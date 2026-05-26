# Vader self-host compiler — gap-closing plan

> **Scope** : combler les manques du compilateur Vader self-host
> (`vader/`) pour atteindre la parité fonctionnelle avec le bootstrap
> TS (`src/`), hors backend C (`c_emit/`).
>
> **Date** : 2026-05-26.
>
> **In** : resolver, typecheck, comptime, lower, midir, bytecode emit,
> VM, intrinsics.
>
> **Out** : `c_emit/`, formatter (`vader fmt`), LSP code actions,
> bootstrap.c seed, perf chantiers (déjà couverts par
> `CC_COMPILE_TIME_REDUCTION.md`), WASM target.

---

## Sprint progress

### S1 — Resolver hygiene + typecheck cleanups (closed 2026-05-26, commit `fc8e5c49`)

- **C.5 Test process leak** ✅ — kill-timer 60-90 s sur `runCli`,
  `runVaderDump`, `runProc`. Plus de zombies pinning a CPU sur
  bun:test bailout.
- **C.4 settle_external scope-down** ✅ — pass 1 du re-walk skipé
  pour modules sans expr-bodied fn. -14 % warm typecheck dump.
- **C.2 `!is` operator** ✅ already shipped (commit `03525c1f`).
  TODO entry mis à jour.
- **B.1 R2026 activation + 3 collisions consolidées** ✅ — 
  `vader/vm/{ScopeEntry, PendingBranch}` kept in builder.vader ;
  `vader/lower/CellInit` + helpers kept in helpers.vader.
- **B.2 Resolver lazy index** ⚠️ reverted — perf win mesurée (660 ms
  → ~30 ms sur `arith`) mais `diagnose_import_path` fires R2001
  depuis l'intérieur de `collect_module` avant que le BFS puisse
  lazy-expand. Documenté pour fix futur (1 jour vs ~2-3 h prévu).
- **C.1 `is_assignable` split** ✅ already shipped via Phase B de
  `CC_COMPILE_TIME_REDUCTION` (80 lignes C vs 51 k pré-split).

### S2 — Default-method materialize + Cell(T) (closed before this session)

- **D Default-method materialize** ✅ — landed via `5e4c1b84` +
  `2b8ddab4` + `cded9837` + `d9303880`. Walker `substitute_expr_full`
  (291 LoC) dans `vader/resolver/substitute_body.vader`. Tous les
  5 snippets bloqués passent : `custom_iter`, `custom_iter_generic`,
  `iter_defaults`, `trait_dispatch_generic_iter`, `for_in_iter_trait`.
- **E `Cell(T)` heap promotion** ✅ — déjà wiré end-to-end.
  `lower_let`, `lower_match` bindings, `lower_ident` captured-read,
  `try_lower_cell_set_assign` toutes émittent `LoweredCellNew` /
  `LoweredCellGet` / `LoweredCellSet`. `vm_closure_mutating` run
  cleanly.

**S2 était stale dans le plan — les TODO entries n'avaient pas été
mises à jour à la livraison. Verification 2026-05-26 surfaceé les
deux comme done. Save : ~2-3 semaines de travail évitées.**

---

## 1. Inventaire par pass

### 1.1 Resolver

| Gap | État | Impact |
|---|---|---|
| **Cross-file duplicate-decl silent first-wins** | 7 collisions masquées dans `vader/{vm,typecheck,lower}/` | Décision #28 du module redesign mandate R2026 hard error ; choix à faire : (a) renommer + activer R2026 ; (b) formaliser le silent-first-wins dans la SPEC. Détails `MODULE_SYSTEM.md` §8 |
| **`bindImport` duplicate import-bindings cross-file** | Même pattern que ci-dessus, file-scoped vs module-scoped | Décision liée à (a) ou (b) ci-dessus |
| **Resolver lazy index** | `discoverModules` scanne tous les `.vader` up-front (~660 ms vs 100 ms en BFS depth-1 pour `arith`) | Affecte chaque `bun test` (~250× spawn par stage). 2-3 h de refactor de `vader/resolver/loader.vader` + `discover.vader` |

### 1.2 Typecheck

| Gap | État | Impact |
|---|---|---|
| **Default-method materialize into impls** | Pas porté — TS materialise `Iterator.is_empty`/`Iterator.count`/etc. dans chaque impl avec line:col d'origine + substitution `Self→struct_ty` | Bloque `custom_iter`, `custom_iter_generic`, `iter_defaults`, `trait_dispatch_generic_iter`, `for_in_iter_trait`. **Heavy** : besoin d'un `substitute_expr` walker dans `vader/resolver/substitute.vader` (seul `substitute_type_expr` existe) — le walker d'expression est le gros lift |
| **`a == b` → `a.equals(b)` synthesis** | Vader retourne `bool` plain, TS enregistre `CallExpr`/`FieldExpr` synthétisés dans `expr_types` au span du BinaryExpr | Bloque `op_overload_eq_ord` parity ; cascade vers lower |
| **`is Type` antipattern** | Anti-pattern présent dans la base, à linter ou éliminer | Sécurité : `expected is Type` contre une union fermée renvoie toujours false (le runtime tag est le variant tag, pas l'union tag) |
| **`settle_external_expr_bodied_returns`** | Walk tous les bodies non-entry au lieu des seules expr-bodied fns | Perf : multiplie typecheck time sur les modules ayant 1 expr-bodied fn |
| **`is_assignable` code-size explosion** | Ajouter une branche → `vader/cli/main.c` saute 27 → 90 MB (3.3×), clang 1 min → 10 min | Tax de 10 min sur chaque changement typecheck. Mitigations : (a) hoister en helpers, (b) split `is_assignable` par type-pair class, (c) auditer le c-emit (full-clone-inlining ?) |
| **Test process leak** | `parity.test.ts` timeout 30s mais les `build/vader run` spawns n'héritent pas — process dans la nature 33+ h | Trivial : ajouter `kill` au cleanup ou `timeout 30s` wrapper |
| **Closure capturing 2 free vars segfaults** | `vader/typecheck/orchestrate.vader:758` : forme `for_each_type(t, (sub) -> register_named_external(sub, entry, per_module))` SIGSEGV — repli vers explicit recursion | Lié à `Cell(T)` heap promotion (lower) — racine probable côté `LoweredMakeClosure` emit qui mishandle le 2ᵉ slot capturé |
| **`!is` operator** | Pas porté — `!(x is Y)` partout dans le self-host | Sugar lexer+parser+formatter ; pas de changement type-system |
| **`if a is X { for v in a.variants {} }` narrowing across statements** | Single-expression guards OK, multi-stmt requiert rewrite vers `match` | Soit tighten flow analysis, soit documenter + lint formatter |

### 1.3 Comptime

| Gap | État | Impact |
|---|---|---|
| **Generic fn-instance harvest** | `typed.genericFnCalls` pas maintenu côté Vader → `## generic instances` dump omet les fn instances | Surface : `generic_fn_calls: MutableMap(usize, Type[])` dans `TypedProgram`, populated dans `call.vader` |
| **for-in ArrayIterator detection** | Walker des bodies pour enregistrer les wraps `for x in <Array>` | Même shape de walker que ci-dessus |
| **Into-coercion materialisation** | Blanket `T[] implements Into(Iterator(T))` impl members → registry | Walker `walkImplBodyForCalls` TS à porter |
| **Transitive closure** | `closeOverGenericImpls` worklist re-observe les substituted return types | Boucle sur les 3 items ci-dessus |
| **Bytecode-driven `@comptime fn`** | Tree-walk evaluator seulement ; fns avec loops/calls/mutation pas évaluables | Sprint majeur (~2-3 semaines selon `STDLIB_JSON_V2.md` §2.1) ; gated sur lowerer + bytecode emit ports (deux complets) |
| **`@is_*` predicate family** | Pas portés (`@is_struct`, `@is_integer`, `@is_array`, `@is_union`, `@is_boolean`, `@is_union_with_null`) | Trivial (~1 j) ; bloque `STDLIB_JSON_V2` Phase 2 |
| **`@field(value, name)` dynamic** | Pas porté | Bloque le pattern derive-style |
| **`@field_type(T, name)`** | Pas porté | Idem |
| **`@construct(T, slots)`** | Pas porté | Idem |
| **`@compile_error(msg)`** | Pas porté | Trivial ; améliore les diags comptime |
| **`${...}` identifier interpolation** | Pas porté | Exotique ; fallback : `array[N]` indexée par comptime position |

### 1.4 Lower

| Gap | État | Impact |
|---|---|---|
| **`Cell(T)` heap promotion** | Closure analysis identifie `captured_symbols`, mais `lower_let`/`lower_ident` n'émettent pas `LoweredCellNew`/`LoweredCellGet`. Stub `helpers.vader::lower_cell_init` en place | Closures sur mutables observent des copies périmées ; cascade vers le bug "2 free vars segfault" en typecheck |
| **Inline-consts pass** | `src/lower/passes/inline-consts.ts` (471 LoC) pas porté | Bloque le data-pool ; gated sur bytecode-emit chantier |
| **`let t :: i32` in-fn type aliases** | Pas de table `let_type_aliases` portée | Divergences snapshot |
| **M5004 `IntoCoercionFailed` emit** | Pas wiré dans `vader/lower/lower_for_in.vader` | TS émet B5001 backend ; cascade `for_in_into_iter` diag-parity |
| **Snapshot flip** | Byte-match 148/226 (peak 181/226 avant refactors) ; cible 200+ | Une fois ≥ 200, `tests/snapshot.test.ts:22` flippe `dumpLower`→`dumpLowerViaVader` et les ~226 `lower.snapshot` regen |

### 1.5 Midir

| Gap | État | Impact |
|---|---|---|
| **DCE primitive trait-impl entries** | `drainPending` punte sur les receivers primitifs (`src/midir/dce.ts:156`) — tout le vtable `Display`/`Equals`/etc. survit dès qu'un `virtual.call` survit | Coût concret : 15 `to_string` imports + 15 `_vt` trampolines + 15 vtable rows pour *un* `println(some_i32)`. Stop-gap `@specialize` landed 2026-05-25 ; proper fix = tracker `usedPrimitives` dans `pruneUnreachable` |

### 1.6 Bytecode emit

| Gap | État | Impact |
|---|---|---|
| **Lower-side stdlib surface** | `is_stdlib_path` skip dans `lower.vader:87` garde stdlib `@intrinsic`/`@extern` hors `LoweredProject.modules` | Chaque dump Vader rate import table + stdlib vtable rows + intrinsic wrappers. Décision : drop le skip vs pass séparé "enumerate-stdlib-externs" |
| **`emit_body.vader` file split** | Bloqué par mutual-import limitation (cycle `emit_block ↔ emit_stmt ↔ emit_expr ↔ emit_if/emit_loop`) | Cosmétique tant que le fichier ne devient pas ingérable ; déclenche soit forward-decls Vader, soit bump per-file cap |
| **Perf 4-map cascade `emit_call_to_symbol`** | slot → intrinsic → fn-table → import | Refactor candidat : single `MutableMap(symbol_id, CallTarget)` ; deferred jusqu'à profiler hit |
| **Snapshot parity bytecode** | Drift `format_op` vs `write_op_line` (`i32.mod` vs `i32.rem`, etc.) | Réconcilier avant byte-diff `.virt` Vader vs TS |

### 1.7 VM

`SELFHOST_VM.md` essentiellement done (98 % acceptance). Reste optionnel :

- Binary `.vir` loader (Sprint 6) — cosmetic, gated sur ship-size
- File split de `vader/vm/exec.vader` si la taille devient un problème

---

## 2. Carte de dépendances

```
                   ┌────────────────────────────────────┐
                   │ A. Pre-impl decisions (cf §3)      │
                   └────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ B. Resolver hygiene (R2026 + lazy index)                    │
│    - 2-3 j ; débloque la fiabilité du dump cross-file       │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ C. Typecheck core gaps                                      │
│    1. is_assignable split (anti-cascade C tax)              │
│    2. !is operator (cleanup massif self-host)               │
│    3. a == b → equals lowering at typecheck                 │
│    4. settle_external scope-down                            │
│    5. test process leak fix                                 │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ D. Default-method materialize (BLOCK MAJEUR)                │
│    - substitute_expr walker dans vader/resolver/            │
│    - body-walk pass typing sous contexte substituant        │
│    - 1-2 semaines ; débloque 5 snippets bloqués             │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ E. Lower : Cell(T) heap promotion                           │
│    - tied to typecheck gap "2 free vars segfault"           │
│    - LoweredCellNew/CellGet emit                            │
│    - 3-5 j                                                  │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ F. Lower : finition + snapshot flip                         │
│    - let_type_aliases, M5004 wiring                         │
│    - viser ≥ 200/226 byte-match                             │
│    - flip dumpLower → dumpLowerViaVader                     │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ G. Comptime walkers : generic-fn harvest + for-in detect    │
│    + Into-coercion + transitive closure                     │
│    - dépend de C (typecheck side-tables propres)            │
│    - 1 semaine                                              │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ H. Midir : DCE primitive-aware                              │
│    - usedPrimitives tracking + pendingVirtual gate          │
│    - 3-5 j ; win sur chaque generic [T: Display]            │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ I. Bytecode emit : stdlib surface + snapshot parity         │
│    - décision drop-skip vs on-demand                        │
│    - réconcilier format_op spellings                        │
│    - 3-5 j                                                  │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│ J. Comptime : @is_* family + petits intrinsics              │
│    - @is_struct, @is_integer, @field, @field_type,          │
│      @construct, @compile_error                             │
│    - 3-5 j ; débloque STDLIB_JSON_V2 Phase 2                │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼ (gros sprint, optionnel)
┌─────────────────────────────────────────────────────────────┐
│ K. @comptime fn subsystem                                   │
│    - ~2-3 semaines (cf STDLIB_JSON_V2 §2.1)                 │
│    - décision finir-Path-3 vs freezer (cf                   │
│      DESIGN_TYPE_FIRST §10bis)                              │
└─────────────────────────────────────────────────────────────┘
```

---

## 3. Décisions à prendre avant lancement

À arbitrer au début de la session ; chacune cadre un ou plusieurs items.

1. **R2026 cross-file duplicate-decl** : (a) renommer les 7 collisions
   + activer hard error, (b) formaliser le silent first-wins. Cadre B.

2. **`is_assignable` split** : (a) hoister chaque arm en helper free
   fn, (b) split par type-pair class, (c) ne pas toucher tant que la
   tax 10-min clang ne gène pas. Cadre C.1.

3. **`a == b` synthesis** : ré-implémenter exactement la forme TS
   (`CallExpr` synthétisé + `FieldExpr` enregistrés dans `expr_types`),
   ou définir une nouvelle représentation Vader-native qui passe
   par un `BinaryOp.Eq + impl_dispatch_hint` ? La 1ʳᵉ donne parité
   snapshot ; la 2ᵈᵉ est plus propre mais demande un changement de
   contrat dump. Cadre C.3.

4. **Default-method materialize** : nouveau `substitute_expr` walker
   dans `vader/resolver/substitute.vader` (le gros lift) — feu vert
   sur la sémantique attendue : reproduire exactement le shape TS
   (matérialisation INTO chaque impl avec line:col d'origine), ou
   adopter un dispatch vtable-driven sans matérialisation explicite ?
   Cadre D.

5. **Bytecode emit stdlib surface** : drop le `is_stdlib_path` skip
   (pollue le synthetic-id counter — voir rationale existant) vs ajout
   d'une pass `enumerate-stdlib-externs` qui surface les imports
   on-demand à emit time. Cadre I.

6. **`@comptime fn` go/no-go** : engagement ~2-3 semaines pour
   débloquer `STDLIB_JSON_V2` + finir Path 3 du type-first (cf
   `DESIGN_TYPE_FIRST.md` §10bis). Décision peut être deferred après K.

---

## 4. Sprint ordering proposé

Trois sessions logiques. Chaque sprint expose un livrable validable
isolément.

### Sprint S1 — Hygiène resolver + typecheck cleanups (DONE 2026-05-26)

Closed in commit `fc8e5c49`. See §"Sprint progress" above.

### Sprint S2 — Default-method + Cell(T) (DONE pre-2026-05-26)

Already shipped. See §"Sprint progress" above.

### Sprint S3 — Finitions lower + comptime walkers + midir DCE (1-2 semaines, **next up**)

Open work :

- **Lower byte-match flip** : currently 183/234 (78 %), need ≥ 200/226
  pour `tests/snapshot.test.ts:22` flip de `dumpLower` → `dumpLowerViaVader`.
  51 divergent snippets clustering around :
  - **let-bound type aliases** (`let_type_alias`, `type_valued_local_rejected`)
    — `@size_of(t)` where `t` is a let-typed alias doesn't fold to
    `int(N)` ; Vader emits the runtime intrinsic call.
  - **defer in nested blocks** (`defer_block`, `defer_in_lambda`,
    `defer_on_panic`) — block-scope wrapping differs vs TS.
  - **generic dispatch / trait routing** (`generic_*`, `trait_dispatch_*`,
    `iter_*`, `custom_iter*`, `transitive_mono`) — assorted small
    drifts.
  - **operator overload** (`op_overload_*`, `contains_op`, `range_widths`).
  - **specifics** (`enum_trait_self_return`, `numeric_add_trait`,
    `string_codepoint_slice`, `interpolation_tokens`, `tuple_comptime`,
    `file_decorator`, `spread_destructure`, `struct_spread`,
    `ufcs_union_receiver`, `vm_trait_dispatch`).
- **G — Comptime walkers** : `generic_fn_calls` side-table population,
  `for-in ArrayIterator` detection, `Into`-coercion materialisation,
  transitive closure (`closeOverGenericImpls`-equivalent).
  See TODO §2.5b "Deferred until lowerer + bytecode emit port".
- **H — Midir DCE primitive-aware** : `usedPrimitives` tracking in
  `pruneUnreachable` + primitive-aware gate in `pendingVirtual`. Stop-gap
  `@specialize` on `std/io` wrappers landed 2026-05-25 ; proper fix
  earns the win on every generic `[T: Display]`. TODO line 844.
- **I — Bytecode emit stdlib surface** : drop `is_stdlib_path` skip vs
  add `enumerate-stdlib-externs` pass ; reconcile `format_op`/`write_op_line`
  spellings before byte-diff `.virt`. TODO line 542-567.
- **M5004 `IntoCoercionFailed` emit** : wire in
  `vader/lower/lower_for_in.vader` after porting TS for-in emit sites.
  Currently missing — Vader has no equivalent of TS's B5001 backend diag.

**Exit** : ≥ 200/234 byte-match → flip snapshot.test.ts ;
`generic_fn_calls` populated ; DCE primitive-aware reduces
`vader.c` by another N% ; bytecode `.virt` byte-diffs Vader vs TS.

### Sprint S4 (optionnel) — `@comptime fn` subsystem (~2-3 semaines)

À décider après S3, en fonction de la décision finir-Path-3 (cf §3
item 6).

---

## 5. Risques + open questions

- **Risque cascade typecheck → lower → snapshot** : chaque fix
  `expr_types` côté typecheck peut faire bouger le dump lower et
  invalider des snapshots. Garder un sprint de regen à la fin de
  chaque session.

- **Risque code-size explosion sur les helpers `is_assignable` split** :
  si la décision §3 item 2 est (a) ou (b), la tax 10-min clang reste
  tant que le c-emit ne change pas. Décision liée à
  `CC_COMPILE_TIME_REDUCTION.md` §7 (piste 6 Phase B/C).

- **Risque divergence dump comptime → bytecode emit** : G et I
  touchent tous les deux les side-tables `generic_fn_calls` ; bien
  séquencer pour éviter de regenerer les snapshots deux fois.

- **Question ouverte sur `${...}` interpolation** (item J.7) : la
  pousser dans `@comptime fn` (sprint K) ou ajouter le fallback
  `array[N]` indexed dans J ? Le fallback rend STDLIB_JSON_V2 viable
  sans K.

---

## 6. Out of scope

- `c_emit/` (exclusion explicite — couvert par
  `CC_COMPILE_TIME_REDUCTION.md`).
- WASM emitter (gated sur §3.10).
- `vader fmt` (séparé, déjà tracké dans `IMPROVEMENT.md`).
- LSP code actions (cf `LSP_CODE_ACTIONS.md`).
- `bootstrap.c` seed (gated sur compilateur complet).
- Surface refactor (struct lit paren grammar — décision pending dans
  `STRUCT_LIT_PAREN_GRAMMAR.md`).

---

## 7. Tracking

Status sera mis à jour au début de chaque session sous §"Sprint
progress" (à ajouter ici quand S1 démarre). Issues encontrées de
chaque sprint dans une section dédiée par sprint, format conforme à
[[feedback-record-issues-in-plan]] (symptom / cause / fix / port note).
