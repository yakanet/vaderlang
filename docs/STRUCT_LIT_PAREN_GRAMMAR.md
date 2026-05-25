# Struct literals : `{}` → `()` — évaluation et plan de migration

> *État 2026-05-26* — document récent (commit `fe0d5b69`,
> 2026-05-25). Évaluation terminée, **décision pending**. Le plan
> reste valide en l'état ; aucune des trois portes du §9 (GO
> évaluation seule / GO Phase A / GO A+B+C) n'a été franchie. Voir
> aussi :
>
> - Recommandation de la revue (§10.6) : avant tout GO Phase A,
>   exiger évaluation explicite des alternatives C et D, stratégie
>   de recovery diagnostics, politique nommé-only pour le migration
>   script Phase B.
> - Bloquant potentiel sur `LSP_CODE_ACTIONS.md` (le code-action
>   `match`-pattern destructuring devra suivre la syntaxe retenue
>   ici) — cf. refresh de ce doc.
> - Sites dépendants : `vader/lsp/` (16+ références `StructLitExpr`,
>   §10.3), `vader/fmt/printer.vader::emit_struct_lit`, 70 snapshots
>   parser.

## Contexte

L'idée est née d'une discussion sur les **field defaults de struct**, déjà supportés
end-to-end mais sous-utilisés dans la stdlib. L'objectif final avec defaults
serait d'écrire :

```vader
m :: MutableMap<string, FnDecl>{}            // état actuel envisageable
m :: MutableMap<string, FnDecl>()            // proposition retenue
```

Au-delà de l'économie de 2 caractères, l'idée pose une question architecturale
plus large : **unifier la grammaire d'instanciation** (`Foo(...)`) avec celle
des **calls** (`foo(...)`) et des **casts** (`i32(x)`), qui partagent déjà
la même forme `Ident(args)` aujourd'hui — la résolution se faisant au typecheck.

**Décision de surface** : on retient la forme **sans `.`** pour les fields. La
syntaxe devient symétrique avec les named call args, et — nouveauté par rapport
au modèle actuel — la **construction positionnelle est autorisée**, comme
pour les calls :

| Aujourd'hui | Proposition |
|-------------|-------------|
| `Foo { .x = 1, .y = 2 }` | `Foo(x = 1, y = 2)` (nommé) |
| *(non supporté)* | `Foo(1, 2)` (positionnel) |
| *(non supporté)* | `Foo(1, y = 2)` (mix : positionnels avant nommés) |
| `foo(x = 1, y = 2)` (named call) | `foo(x = 1, y = 2)` (inchangé) |

La distinction struct lit / named call / cast se fait **uniquement** par le
type du callee, résolu au typecheck. Vader fait déjà cette résolution pour
casts `i32(x)` vs calls `foo(x)`. Le seul ajout : si le callee résout vers
un type struct, le `CallExpr` est ré-interprété comme `StructLitExpr`, les
args positionnels mappant vers les fields dans l'ordre de déclaration.

**Règles de mix positionnel + nommé** (alignées sur Python / Kotlin) :

1. Les args positionnels précèdent les args nommés. Inverser → erreur de
   parse-style (`T3039` à créer).
2. Les positionnels couvrent les fields dans **l'ordre de déclaration de la
   struct**. Mapping fixe.
3. Un field omis (positionnel ou nommé) **doit** avoir un default. Sinon
   `T3037` (déjà existant).
4. Un field ne peut pas être assigné deux fois (positionnel + nommé pour le
   même slot). Conflit → `T3038` (déjà existant, à étendre).

> *Variante écartée* — garder le `.` sur les fields (`Foo(.x = 1)`).
> Cette voie offrait un discriminant grammatical local fort, mais elle
> brisait la symétrie avec les named call args et conservait une marque
> visuelle redondante avec la convention PascalCase déjà en place. Voir
> §8.7 pour le détail des ambigüités que cette discipline laissait
> persister.

---

## 1. Cartographie des conflits

### Zones inspectées, par ordre de risque

| # | Zone | Conflit | Verdict |
|---|------|---------|---------|
| 1 | Appels fn `foo(a, b)` | Aucun au parser (déjà unifié en `CallExpr`). Désambiguation par type du callee au typecheck. | **Propre** |
| 2 | Casts `i32(x)`, `usize(0)` | Vader parse déjà tous les `Type(args)` comme `CallExpr` et résout au typecheck (`SPEC §3 l.308`). Même piste. | **Propre — précédent existant** |
| 3 | Variants d'enum | Vader n'a pas de payload enum. Patterns `.Variant` non paramétrés. | **Aucun conflit** |
| 4 | Tuple literals | Vader utilise `[a, b]` pour les tuples, pas `(a, b)`. Les `()` parenthésées ne créent jamais de tuple. | **Aucun conflit** |
| 5 | Generics `Foo<K, V>(...)` | Le scanner d'angle-generic (`src/parser/passes/expr.ts:584-631`, l.608) accepte déjà `>` suivi de `(` ou `{`. Aucun changement. | **Propre** |
| 6 | Spread `...other` | Aujourd'hui le call-site rejette `...expr` (`src/parser/passes/expr.ts:482`, "reserved syntactically"). Donc `(...other, x = 1)` peut être ajouté sans collision. | **Propre — réservation alignée** |
| 7 | Condition `if/for/match` | **Gain net.** SPEC §6 l.667-683 interdit aujourd'hui les struct literals au top-level d'une condition (collision `{` body brace). Avec `()`, la restriction tombe ; toute la machinerie `allowStructLit` (`src/parser/passes/control.ts:19-31, 53-54, 81-82`) disparaît. | **Gain net** |
| 8 | Patterns `is Foo { … }` | `parseStructPattern` attend `lbrace`. Doit migrer vers `lparen`. ~10 lignes. | **Migration locale** |
| 9 | Decorators `@x(args)` | Déjà sur `()`, espace syntaxique séparé. | **Aucun conflit** |
| 10 | Trait impl blocks | Vivent au niveau decl, pas expr. Aucune interaction. | **Aucun conflit** |

### Conflits réels (creusés au-delà du rapport d'exploration)

**Named args vs struct lit — même syntaxe interne** — Vader supporte déjà
`foo(x = 1, y = 2)` (named args) et `foo(1, 2)` (positionnel)
(`src/parser/passes/expr.ts:484-501`). Avec la proposition, `Foo(...)` réutilise
**exactement la même syntaxe d'arguments**, positionnel comme nommé. L'AST
produit par le parser est identique (un `CallExpr` avec des `CallArg`,
chacun avec `name` nullable + `value`). Le typecheck distingue par le callee :

- callee = fn → l'AST reste `CallExpr`, les args mappent vers les
  paramètres de la fn (positionnels par index, nommés par nom) ;
- callee = type struct → le typecheck convertit en `StructLitExpr`, les
  args mappent vers les fields (positionnels par ordre de déclaration,
  nommés par nom) ;
- callee = type primitif → cast (un seul arg positionnel, named args
  invalides).

**`Foo()` vide** — résolu **au typecheck** :
- callee est un type struct → struct literal vide (defaults appliqués) ;
- callee est une fn → call à zéro arg ;
- callee est un primitif → cast invalide.

Précédent : Vader fait déjà cette résolution pour `i32(x)` vs `foo(x)`.

**Spread futur dans les calls** — si Vader active un jour le spread call-site
(`foo(a, ...rest)`), il faudra distinguer dans `Foo(...other, x = 1)` le rôle
de `...other` (override de tous les champs vs étalement positionnel). La règle
existante de struct-lit spread (`{ ...other, .field = v }`, SPEC §6 l.655-666)
se transpose : si le callee est un type struct, `...other` = spread struct
lit ; sinon, spread call args.

---

## 2. Bénéfices

- **Suppression de la machinerie `allowStructLit`** (push/pop sur les nœuds
  control-flow dans `src/parser/passes/control.ts`).
- **Suppression de la restriction SPEC §6** "Struct literals in `if/for/match`
  conditions" — les parenthèses disambig deviennent inutiles.
- **Uniformité conceptuelle** : `Type(args)` (cast, conversion, instanciation)
  vit dans la même grammaire que les calls. Vader assume déjà partiellement
  cette philosophie (casts == call syntaxe).
- **Symétrie struct lit ↔ named call** : `Foo(x = 1)` et `foo(x = 1)`
  partagent la même grammaire d'arguments. Un seul mode mental.
- **Économie graphique** : `Foo<T, U>()` plus court que `Foo<T, U> {}` pour
  les structs entièrement default-initialisées (le cas qui motive la
  discussion).

---

## 3. Coûts

### Code compilateur (TS, `src/`)

- **Parser** : `src/parser/passes/expr.ts` — la branche struct lit de
  `parseIdentOrStructLit` (l.509-551) disparaît : on n'a plus qu'à parser un
  `CallExpr` standard via `parseCallArgs`. La fonction
  `parseStructLitFields` (l.682-713) est supprimée (plus de mode `.field =`).
- **Parser patterns** : `src/parser/passes/pattern.ts` — `parseStructPattern`
  passe à `lparen`/`rparen` (~5-10 lignes).
- **Parser conditions** : `src/parser/passes/control.ts` — suppression de
  `allowStructLit` push/pop (gain net, ~10 lignes supprimées).
- **AST** : `StructLitExpr` reste comme nœud IR-ready. Le parser ne le
  produit plus directement — il produit `CallExpr` qui sera converti au
  typecheck. Alternative : faire la conversion plus tard (au lower) si
  c'est plus simple côté typecheck.
- **Typecheck** : `src/typecheck/passes/call.ts` reçoit un nouveau mode :
  si le callee résout vers un type struct, ré-interpréter le `CallExpr`
  comme `StructLitExpr` (mapping `CallArg.name` → field name pour les
  nommés, mapping `CallArg[i]` → `decl.fields[i]` pour les positionnels)
  puis passer la main à `src/typecheck/passes/struct-lit.ts`. La
  machinerie existante pour les casts (qui détecte callee = type
  primitive) sert de patron. Coût additionnel pour le positionnel :
  ~30 lignes (validation ordre positionnels-avant-nommés, mapping
  index→field, détection doublons).
- **Lower / midir / c_emit / vm** : aucun changement (l'IR
  `LoweredStructLit` est en aval).

### Code Vader (`vader/`, `stdlib/`, `tests/`, `examples/`)

Comptage mécanique des sites à migrer (motif `Ident{...}` avec au moins
un `.field`) :

- `vader/` + `stdlib/` : **~1517 sites**
- `tests/` : **~161 sites** (snippets + fixtures)
- `examples/` : à compter (probablement < 100)

Migration scriptable : pour chaque struct lit `Foo { .x = 1, .y = 2 }`,
deux transformations en parallèle :
1. `{` → `(` et `}` → `)` autour des fields ;
2. retrait du `.` devant chaque field name.

Risque : les `{}` de struct lit imbriquées dans d'autres `{...}` (corps
de fn, match arms, blocs). À gérer via un transformateur AST (parser TS
existant qui re-émet le source), pas par regex.

### Documentation

- **SPEC.md** — réécriture obligatoire de la grammaire d'instanciation,
  pas juste un rafraîchissement d'exemples. Détail : voir §5 Phase C
  ci-dessous, qui liste les sections SPEC à toucher avec ce qu'il faut
  ajouter / réécrire / supprimer.
- **CLAUDE.md** (project) : tous les exemples de struct lit.
- **docs/** : tout ce qui montre des struct literals.

---

## 4. Points subjectifs à arbitrer

### 4.1 Lisibilité humaine

Sur du code imbriqué, la distinction struct lit vs call repose **uniquement
sur la casse du callee** :

```vader
// Aujourd'hui
result :: process(MyConfig { .verbose = true, .timeout = 30 })

// Après — la convention PascalCase est le seul indice visuel
result :: process(MyConfig(verbose = true, timeout = 30))
```

C'est un trade-off assumé : on accepte que la lecture demande de savoir si
`MyConfig` est un type ou une fn (ce qui est déjà nécessaire pour
comprendre la sémantique). En contrepartie, la grammaire devient plus
légère et la base de code plus uniforme.

### 4.2 Précédent dans la famille

- **Rust** : `Foo { x: 1 }` — `{}` réservé struct lit. Distinction nette
  call/struct/cast.
- **Swift** : `Foo(x: 1)` — `()` partout. Casts == initializers ==
  calls, distingués par labels.
- **Zig** : `.{ .x = 1 }` — `{}` réservé. Distinct des calls.
- **Kotlin/Scala** : `Foo(x = 1)` — `()` partout. Plus proche du modèle Swift.

Vader penche déjà côté Swift sur les casts. La proposition aligne
struct lit avec le même modèle (et Kotlin/Scala).

### 4.3 Positionnel : robustesse aux changements de struct

Le mode positionnel introduit un couplage **silencieux** entre les call-sites
et l'ordre de déclaration de la struct :

```vader
// Décl initiale
Point :: struct { x: i32, y: i32 }

// Call-sites positionnels
p :: Point(10, 20)             // x=10, y=20

// Évolution : on ajoute un field au milieu
Point :: struct { x: i32, z: i32, y: i32 }   // z inséré

// Le call-site continue à compiler MAIS la sémantique a changé
p :: Point(10, 20)             // maintenant x=10, z=20, y=??? (default ou erreur)
```

Vader force déjà un default sur tout field omis (T3037), donc le call-site
**fail** au typecheck si le nouveau field n'a pas de default. Mais le pire
cas est subtil : si tous les fields ont des defaults et que le nouveau type
matche (par exemple deux `i32` consécutifs), le code compile en silence
avec un `z = 20` non voulu.

**Atténuations possibles** :
- Inciter au nommé pour les structs publiques (par convention, comme
  Python pour les API stables).
- `vader fmt` peut réécrire le positionnel en nommé (lint optionnel).
- Réserver le positionnel aux structs marquées (`@positional` decorator)
  — voie Rust-like (`struct Pair(i32, i32);`). Plus restrictif mais plus
  sûr.

À arbitrer : on accepte le risque (style libéral) ou on contraint via
décorateur ?

### 4.4 Impact sur le `match` exhaustivité narrative

Avant :
```vader
match v {
    is Pair as p -> Result { .ok = true, .value = p.first }
}
```
Après :
```vader
match v {
    is Pair as p -> Result(ok = true, value = p.first)
}
```
Sur une ligne, équivalent visuel. Sur du multi-ligne, perte d'ancrage
visuel léger (les `{}` étaient des balises plus marquées), compensé par
la cohérence avec le reste des call-sites.

---

## 5. Plan d'exécution conditionnel

**À déclencher seulement après validation explicite.**

### Phase A — Spike grammaire (1 commit)

1. Ajouter en parallèle la **double syntaxe** : le parser accepte
   `Foo(x = 1)` ET `Foo { .x = 1 }`. Permet de valider le typecheck et
   d'écrire des tests sans casser le codebase existant.
2. Tests dédiés `tests/snippets/struct_lit_paren.vader` (heureux chemin,
   conditions if/for/match avec literals, generics, spread, vide,
   patterns, ambigüité call vs struct lit selon callee).
3. Vérification : `bun run test --filter=struct_lit` doit passer sur les
   deux syntaxes.

**Critère sortie Phase A** : le typecheck distingue correctement
`Foo(x=1)` (struct lit), `foo(x=1)` (named call), `i32(0)` (cast) sur
tous les sites de test.

### Phase B — Migration mécanique (1 commit, scripté)

1. Écrire un script de transformation (`scripts/migrate_struct_lit.ts`)
   qui parse chaque `.vader` via le parser TS existant et ré-émet le
   source en :
   - remplaçant `{` / `}` par `(` / `)` autour des struct lits ;
   - retirant le `.` devant chaque field name.

   Pas de regex sed-style — passe par l'AST.
2. Appliquer à `vader/`, `stdlib/`, `tests/`, `examples/`, `bench/`,
   `docs/` (extraction snippets si nécessaire).
3. Vérification : `bun run test` doit passer (le compilateur TS accepte
   encore les deux syntaxes via Phase A).

**Critère sortie Phase B** : aucun `Foo { .x = … }` ne subsiste dans le
codebase.

### Phase C — Suppression de l'ancienne syntaxe (1 commit)

1. Retirer du parser le support `Foo { .x = … }`. L'unique forme
   accepte `Foo(x = …)`.
2. Retirer la machinerie `allowStructLit` push/pop dans
   `src/parser/passes/control.ts`.
3. **Mise à jour SPEC.md** — réécriture de la grammaire d'instanciation.
   Détail des sections :

   - **§6 *Struct* (l.620+)** : remplacer la grammaire `Foo { .x = 1, .y = 2 }`
     par `Foo(x = 1, y = 2)`. Ajouter explicitement la **forme positionnelle**
     (`Foo(1, 2)`) et le **mix** (`Foo(1, y = 2)`), avec les 4 règles de
     mapping (positionnels avant nommés, ordre = ordre de déclaration,
     defaults pour omis, pas de double-assignment). Référencer les codes
     d'erreur T3037 / T3038 / T3039.
   - **§6 *Field defaults* (l.637)** : actualiser les exemples
     (`Settings(name = "loud", debug = true)` au lieu de
     `Settings { .name = "loud", .debug = true }`). La sémantique
     (default re-lowered à chaque site) reste inchangée.
   - **§6 *Spread* (l.655-666)** : actualiser
     (`Config(...defaults, verbose = true)`). Documenter explicitement
     comment le typecheck distingue `Foo(...other, x = 1)` (spread struct lit)
     d'un futur `foo(...rest)` (spread call args) par le type du callee.
   - **§6 *Struct literals in if/for/match conditions* (l.667-683)** :
     **supprimer la section entière**. La collision `{` qui motivait la
     restriction n'existe plus avec `()`. Ajouter une note historique d'une
     ligne dans le changelog SPEC, rien dans le corps.
   - **§3 *Casts* (autour de l.308)** : ajouter une phrase liant les trois
     formes (`Type(arg)` = cast, `Type(field = …)` ou `Type(positionnels)`
     = struct lit, `fn(args)` = call), toutes parsées comme `CallExpr` et
     désambiguïsées au typecheck par le **type du callee**.
   - **§3 *Default integer*, §6 *FreeInt → context type*** : vérifier que
     les exemples de `Box { .size = 10 }` (typage contextuel des int
     literals dans un struct lit) sont rebasés sur la nouvelle syntaxe.
   - **§10 (références grammaticales)** : passe sur tous les snippets pour
     bascule mécanique. Faisable au script.
   - **Ajout d'un §6 nouvelle sous-section *Instantiation grammar*** (titre
     à arbitrer) qui regroupe en un seul endroit : `Foo()` vide,
     `Foo(positionnels)`, `Foo(nommés)`, `Foo(mix)`, `Foo(...spread)`, et
     l'arbre de décision du typecheck (callee primitif → cast / callee
     struct → struct lit / callee fn → call). Sert de point d'entrée
     unique pour le lecteur.

   La SPEC est le **source of truth** pour la grammaire — sans cette
   réécriture, la migration n'est pas terminée. À traiter avant Phase D
   et avant le merge de la Phase C.
4. Mise à jour `.claude/CLAUDE.md` (toutes les sections § Idiomatic
   patterns avec exemples).
5. Vérification : `bun run test` + `bun run vader run examples/...` sur
   les exemples.

**Critère sortie Phase C** : la SPEC ne mentionne plus `{` comme
ouvreur de struct lit (sauf historique). Le parser refuse
`Foo { .x = … }`.

### Phase D (optionnelle) — Migration stdlib defaults

Ajouter les field defaults sur `MutableMap`, `MutableSet`, et autres
structs de la stdlib pour permettre `MutableMap<K, V>()` au lieu de
`MutableMap<K, V>(buckets = [], size = usize(0))`. Indépendant de A/B/C,
gain ergonomique séparé.

---

## 6. Fichiers critiques

- `src/parser/passes/expr.ts` : `parseIdentOrStructLit` (l.509-551),
  `parseStructLitFields` (l.682-713) — à supprimer, `parseCallArgs`
  (l.473-507) — devient unique chemin.
- `src/parser/passes/pattern.ts` : `parseStructPattern`.
- `src/parser/passes/control.ts` : suppression `allowStructLit`.
- `src/typecheck/passes/call.ts` : nouvelle bascule CallExpr → StructLit
  quand callee = type struct.
- `src/typecheck/passes/struct-lit.ts` + `src/typecheck/check.ts:124` :
  côté receveur de la bascule (aucun changement de logique attendu).
- `SPEC.md` : §3 Casts, §6 Struct + Field defaults + Spread +
  restriction conditions, §10 références exemples.
- `.claude/CLAUDE.md` (project) : exemples idiomatic patterns.
- `stdlib/std/collections/collections.vader` : sites les plus visibles
  pour la demo Phase D.

---

## 7. Vérification end-to-end

- `bun run test` après chaque phase (~6 min, doit rester vert).
- `bun run vader run examples/<each>/main.vader` (chaque exemple
  compile et tourne).
- `bun run vader build vader/cli/main.vader --target=native --out=build/vader`
  (le CLI Vader self-host build sans erreur).
- Inspection visuelle de quelques `.vader` post-migration pour vérifier
  la lisibilité (pas de massacre de l'indentation, alignement des
  `field = value` préservé).

---

## 8. Comparaison code réel — avant / après

### 8.1 Construction simple

```vader
// Avant
flags := MutableMap<string, string> { .buckets = [], .size = 0 }
err :: Diagnostic { .code = "T3001", .span = sp, .msg = "type mismatch" }

// Après — nommé
flags := MutableMap<string, string>(buckets = [], size = 0)
err :: Diagnostic(code = "T3001", span = sp, msg = "type mismatch")

// Après — positionnel (nouveauté)
flags := MutableMap<string, string>([], 0)
err :: Diagnostic("T3001", sp, "type mismatch")

// Après — mix : positionnels d'abord, nommés ensuite
err :: Diagnostic("T3001", sp, msg = "type mismatch")
```

Recommandation de style : positionnel pour les constructions simples ou
les tuples-named (2-3 fields évidents), nommé pour les constructions
denses ou les fields ambigus. Aligné sur la convention Python.

### 8.2 Avec defaults (le motif qui a déclenché la discussion)

```vader
// Avant — pénible si tu veux juste les defaults
map :: MutableMap<string, FnDecl> { .buckets = [], .size = 0 }

// Après — defaults appliqués, écriture minimale
map :: MutableMap<string, FnDecl>()
```

### 8.3 Imbriqué dans un call

```vader
// Avant
process(MyConfig { .verbose = true, .timeout = 30, .out = stdout })

// Après — la convention PascalCase informe le lecteur que MyConfig est un type
process(MyConfig(verbose = true, timeout = 30, out = stdout))
```

### 8.4 Condition `if` (gain net)

```vader
// Avant — la struct lit doit être entre parens, sinon le `{` collide
if (Point { .x = 1, .y = 2 }) == p {
    do_something()
}

// Après — plus de collision, les parens sont natives
if Point(x = 1, y = 2) == p { do_something() }
```

### 8.5 Spread / functional update

```vader
// Avant
updated :: Config { ...defaults, .verbose = true }

// Après
updated :: Config(...defaults, verbose = true)
```

### 8.6 Pattern destructuring (`match`)

```vader
// Avant
match v {
    is Point as p -> p.x + p.y
    is Pair { first, second } -> first + second
}

// Après
match v {
    is Point as p -> p.x + p.y
    is Pair(first, second) -> first + second
}
```

### 8.7 Lecture imbriquée — exigence sur la convention de casse

```vader
result :: process(handler = Pipeline(stages = pipeline_stages, debug = false))
```

L'œil cherche **trois rôles** à la même profondeur :
- `process` (snake) → fn
- `handler` (snake) → param name de `process` (named arg)
- `Pipeline` (Pascal) → type struct (donc struct lit)
- `stages`, `debug` (snake) → field names de `Pipeline`

L'unique discriminant local est la **casse**. Tant que la convention
PascalCase pour les types est respectée (`CLAUDE.md §5 Naming` la
rappelle), la ligne se lit sans ambigüité. Le `lsp` highlight (types vs
fns) renforce le signal côté éditeur.

**Coût implicite** : la convention de casse devient un contrat de
lisibilité, plus seulement un guide de style. Un type nommé `myConfig`
ou une fn nommée `Configure` deviendrait franchement illisible — c'est
le seul prix à payer.

### 8.8 Verdict côte-à-côte

| Critère | Aujourd'hui `{}` + `.x` | Après `()` sans `.x` |
|---------|--------------------------|----------------------|
| Conflit parser | aucun | aucun (parser uniforme, type au typecheck) |
| Lisibilité humaine | ★★★ (forte distinction visuelle) | ★★☆ (casse comme indice principal) |
| Suppression `allowStructLit` | non | oui |
| Suppression SPEC §6 restriction conditions | non | oui |
| Compatibilité avec defaults `Foo()` | n/a | oui |
| Construction positionnelle | non supportée | oui (avec coût en robustesse §4.3) |
| Distinction call vs struct lit | grammaticale (`{}` vs `()`) | sémantique (par callee) |
| Risque erreur diagnostique | faible | acceptable (LSP + erreurs précises au typecheck) |
| Charge cognitive | faible | faible si convention casse tenue, sinon élevée |

---

## 9. Décision à prendre avant lancement

Trois portes :

1. **GO sur l'évaluation seule** (état actuel du plan) — pas d'exécution,
   on relit, on en discute. Le sous-chantier *field defaults stdlib*
   (Phase D isolée) peut démarrer indépendamment.
2. **GO sur Phase A uniquement** — spike grammaire pour valider que la
   double syntaxe marche techniquement, sans engagement sur la
   migration.
3. **GO sur A+B+C** (+ D plus tard) — migration complète. Décision
   irréversible côté SPEC. Estimation initiale : 4-6h ; **estimation
   révisée post-audit : 16-30h** (voir §10).

Le verrou subjectif est §4.1 / §8.7 : accepter que la convention de
casse devienne un contrat de lisibilité, plus seulement un guide de
style.

---

## 10. Findings de la revue indépendante (post-évaluation)

Évaluation conduite via trois agents indépendants : vérification
factuelle des claims du plan, audit critique du design, recherche
d'angles morts. Voici la consolidation, classée par criticité.

### 10.1 Corrections factuelles

| Claim du plan | Réalité | Action |
|---------------|---------|--------|
| ~1517 sites `vader/+stdlib/` | **1256** (1365 dans `vader/` + 158 dans `stdlib/` = 1523 selon un autre comptage agrégé ; le plus précis donne 1256 sites distincts struct lit) | Mettre à jour §3 et estimation Phase B |
| ~161 sites `tests/` | **125** | Mettre à jour §3 |
| `examples/+bench/` "< 100" | **20** | Confirmé |
| T3039 "erreur de parse-style à créer" | Le parser n'enforce **aucun** ordre positionnel/nommé aujourd'hui. La validation doit aller dans le **typecheck**, pas le parser. | Corriger §1 et §5 Phase A |
| "Typecheck convertit CallExpr → StructLitExpr quand callee = type struct" | La machinerie cast existe (`src/typecheck/passes/call.ts:42-47`, route vers `inferTypeConstructorCall` quand `sym.kind === "struct"`) mais elle est **mono-argument**. Étendre à N args nommés/positionnels + spread + defaults + mix n'est **pas** une généralisation gratuite. | Corriger §3 (estimation "30 lignes" → 100-150 lignes) |

### 10.2 Risques opérationnels sous-estimés

**Qualité des diagnostics quand le callee n'est pas résolu** — Sur
`Foo(verbose = ture)` avec `Foo` non résolu (typo, import manquant,
cycle de modules), le typecheck ne peut plus router vers
`inferTypeConstructorCall` ; le diagnostic devient un T3007 générique
"not callable" au lieu d'un "unknown field `ture` on struct `Foo`"
actionnable. Le précédent "casts == call" est trompeur : les casts ont
1 argument anonyme, perdre la résolution ne coûte rien ; les struct
lits ont N args nommés, perdre la cible perd N diagnostics. **Stratégie
de recovery à concevoir** pour Phase A.

**Positionnel + insertion de field au milieu (risque amplifié sur self-host)** —
Le §4.3 traite le risque avec "convention Python". Sur un compilateur
self-host de 1256 sites (`vader/`), beaucoup de structs ont des fields
adjacents de même type (`i32`/`i32`, `string`/`string`, `usize`/`usize`).
Insertion silencieuse = bombes à retardement. **Recommandation forte** :
le migration script Phase B doit émettre **toujours du nommé**, jamais
du positionnel. Le positionnel reste opt-in humain au cas par cas.

**Tension avec `feedback_mvp_no_back_compat`** — Phase A propose une
double syntaxe transitoire (Phases A+B). CLAUDE.md interdit
explicitement les "dual-syntax support". À résoudre : soit déclarer
l'exception (fenêtre courte, jamais releasée), soit faire la transition
en **un seul commit atomique** (parser + script + suppression).

### 10.3 Angles morts (zones oubliées du plan)

| Zone | Trouvé | Coût caché |
|------|--------|-----------|
| **LSP** (`vader/lsp/`) | 16+ références `StructLitExpr` dans 6 fichiers (ast_tokens, hover, semantic_tokens, signature_help, indexer, definition). Pas mentionné dans le plan. | +4-6h |
| **Formatter** (`vader/fmt/printer.vader:1570-1597`) | `emit_struct_lit` hardcoded `{` / `}`. Règles single-line vs multi-line à redéfinir pour `()`. | +2-3h |
| **Snapshots parser** | **70 fichiers** `.snapshot` contiennent `StructLitExpr` (151 occurrences). Régénération mass à scripter prudemment. | +2h |
| **Hot zones self-host** | `vader/typecheck/orchestrate.vader` : 26 struct lits ; `vader/typecheck/struct_lit.vader` : 6 (le module struct lit !) ; `vader/lower/` : ~50+. Migration mécanique = risque sémantique. | +3-4h (audit + tests) |
| **AST flag `delim`** | `StructLitExpr` n'a pas de flag `brace` vs `paren`. Phase A doit l'ajouter et propager dans visiteurs. | +1-2h |
| **Diagnostics affichant snippets** | `tests/parity-diagnostics.test.ts` (modifié en cours) inclut probablement des extraits de code surface. Tous cascade. | +1-2h |

**Total coût caché : +13-19h** au-delà des 4-6h initialement estimées.
**Estimation honnête : 16-30h** réparties sur 2-3 sessions, avec
fenêtre de debug post-Phase B sur le self-host (qui doit recompiler
sa propre nouvelle syntaxe — ordering de bootstrap à gérer).

### 10.4 Alternatives non-explorées par le plan

Le plan binarise `{}` vs `()`. Trois alternatives crédibles méritent
évaluation **avant** tout GO migration :

- **Alternative C — `{}` optionnel en position non-ambiguë** : garder
  `Foo { .x = 1 }` partout, autoriser `Foo()` pour all-default,
  autoriser l'omission `{}` complète dans les positions sans collision
  (RHS d'un `::`, return, argument de call). Résout le pain point
  `MutableMap<K,V>()` sans casser 1256 sites.
- **Alternative D — `Foo {}` reste pour struct lit, `Foo()` réservé
  aux calls/casts/all-default** : grammaire qui distingue les deux à
  l'œil et au parser, avec une seule règle de coercition
  "callee = type + zéro arg → struct lit vide". Coût migration ≈ 0.
- **Alternative E — bare `Foo` pour all-default (Go-style)** :
  `m :: MutableMap<K, V>` (sans parens) créerait une instance default
  si le type a tous ses fields default.

  **Disqualifiée** — conflit direct avec le mécanisme d'**alias de
  type implicite** de Vader. Le parser route `name :: <expr>` vers
  `parseConstDecl` (`src/parser/passes/decl.ts:459`) ; le typecheck
  décide après si la RHS est un type (→ alias) ou une valeur (→
  binding). Aujourd'hui :

  ```vader
  NewType :: MutableMap<X, Y>   // type alias
  ```

  E voudrait que la même forme signifie une instanciation. **Aucun
  discriminant grammatical** ne sépare les deux ; la convention de
  casse du LHS (`NewType` vs `m`) retombe sur la dépendance
  PascalCase non-enforcée déjà problématique (§10.5). E n'est
  récupérable qu'en abandonnant l'alias implicite — décision majeure
  hors scope.

Alternative C ou D restent les pistes intermédiaires crédibles si l'on
souhaite éviter la migration mécanique de 1256 sites.

### 10.5 PascalCase : un confort de lecture, pas un verrou compilateur

**Clarification après revue** : l'agent critique a présenté la
dépendance PascalCase comme un verrou à résoudre avant GO. C'est
inexact. Il faut séparer deux niveaux :

- **Côté compilateur** : la différenciation struct lit / named call /
  cast se fait au **typecheck**, en regardant le **type du callee**
  (résolu par le resolver). Cf. `src/typecheck/passes/call.ts:42-47`,
  qui route vers `inferTypeConstructorCall` quand
  `sym.kind === "struct"`. **PascalCase n'a aucun rôle** ici — un
  type nommé `myConfig` se résout en symbole struct et est traité
  comme tel.
- **Côté lecteur humain** : sans accès au resolver, le lecteur infère
  la nature de `MyConfig(verbose = true)` via la convention de casse.
  C'est exactement le tradeoff déjà documenté en §4.1 et §8.7, et
  **assumé** par le choix de l'Option B.

Pas de verrou à débloquer. Pas besoin d'enforcer PascalCase. La revue
critique a glissé vers une recommandation excessive ; la garder
comme prérequis serait du gold-plating.

Reste vrai (point inchangé de §4.1) : la lecture *agréable* dépend
du respect de la convention de casse. Le LSP highlight des types vs
fns renforce ce signal côté éditeur, ce qui clôt le sujet pour
l'usage réel.

### 10.6 Verdict global de la revue

Le plan est **intellectuellement séduisant** (uniformité conceptuelle,
suppression d'`allowStructLit`, défense honnête des choix) **mais
traite à la légère** :

1. la dégradation des diagnostics quand le callee n'est pas résolu ;
2. la fragilité du positionnel sur structs en évolution ;
3. le chiffrage de migration (optimiste d'un facteur 3-5).

L'alternative E (bare `Foo` Go-style) **est disqualifiée** par le
conflit avec l'alias de type implicite (§10.4). PascalCase **n'est
pas un verrou compilateur** (§10.5).

**Recommandation de la revue** : avant tout GO Phase A, exiger :

- évaluation explicite des **alternatives C et D** ;
- stratégie de **recovery diagnostics** quand callee non résolu ;
- politique du **migration script Phase B** : nommé-only, pas de
  positionnel automatique.

L'évaluation est terminée. La décision (porte 1 / 2 / 3 du §9) revient
à l'utilisateur.
