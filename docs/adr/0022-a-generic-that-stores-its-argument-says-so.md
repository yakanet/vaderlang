# 0022 — A generic that stores its argument says so

## Status

Accepted (2026-09-28). Amends 0017 on two points: the generic-parameter exemption,
and the storageless module const.

## Context

A struct module const was rebuilt at every read — one allocation per reference,
`NULL_VALUE` in the VM's frame reset included. Materialising it once means every
read shares one value, and a shared value is only sound if nothing can write
through any path to it.

One such path already crashed. Arrays of struct literals are baked into `.rodata`
today, and:

```vader
TABLE :: [P { .x = 1 }]
held: P![]!: []
held.push(TABLE[0])
held[0].x = 9          // native: SIGBUS ; VM: TABLE[0].x reads 9 afterwards
```

## What was measured

Three independent holes, each verified against `HEAD` before any change:

1. **The module-const freeze stopped at the top level.** `auto_const_module_array`
   froze the array (`P[]`) and left its elements `P!`. `a[0] = TABLE[0]`,
   `m["k"] = TABLE[0]`, `push_all(TABLE)` and `w: P!: TABLE[0]` all compiled, and so
   did `p :: ORIGIN ; p.x = 5` for a struct const — 0017's "the type lies, only the
   path knows".

2. **A `!` parameter lost its marker through method syntax.** `ufcs_method_type`,
   `try_trait_method` and `try_default_trait_method` rebuilt the member's type with
   `mk_fn(params, ret)`, dropping `params_mutable`. `absorb(c, CFG)` was T3072 and
   `c.absorb(CFG)` compiled.

3. **The generic exemption ignored storage.** 0017 exempts a substituted `T` from the
   element check because "inside the body the element is a `T`, which grants no
   mutation". True of what the callee *does* with it, not of where it *puts* it:
   `push(self!, value: T)` stores the value in an array that hands it back writable.
   The same laundering worked from a read-only parameter — `fn(q: P) { held.push(q);
   held[0].x = 9 }`.

Tree cost, measured on `vader/cli/main.vader` + `vader/bootstrap/bootstrap.vader`:

| change | new errors |
|---|---|
| recursive freeze of unannotated module consts | 1 (`[NULL_VALUE] * n` into `Value![]!`) |
| markers kept through method syntax + `push(value: T!)` | 17 |
| … with a distinct type judged by its backing | 8 |
| … with an unbound `T` asking nothing inside a generic body | 5 → fixed at the sites |

The five were real: four `NULL_VALUE` stores into `Value![]` (now a fresh
`NullVal {}` on those cold grow paths) and one `push_to_module(…, decl: LoweredDecl)`
storing a read-only decl into `LoweredDecl![]!` (now `decl: LoweredDecl!`). No
snapshot moved; the suite passed unchanged.

## Decision

- **A module const is frozen at every level** — `auto_freeze_module_const` applies the
  same `apply_readonly_default` a written type gets. A local bound from it is a
  read-only view; a mutable copy is spelled `P { ...ORIGIN }`.
- **A `!` on a type parameter is the storage contract.** `push :: fn(self!, value: T!)`
  means "I keep what you give me". The argument must be as mutable as `T` is bound to:
  a `P![]` receiver demands a mutable `P`, a `P[]` or an `i32[]` asks nothing
  (`type_may_grant_mutation` on the substituted parameter gates T3072). Inside the
  generic body an unbound `T` asks nothing — the binding call is the one judged.
- **Method types keep their markers**, shifted past the dropped receiver
  (`mk_fn_drop_self`).

A heuristic ("a `self!` method taking a `T` stores it") was the alternative. It needs
no stdlib change but misfires on a `self!` method that only compares its `T`. The
signature is where Vader states mutation; storage is mutation the caller will see.

## Left open

- **Nominal type arguments still carry no bit** (0017, "Left open"), so a generic
  struct container cannot state what `push` now states: `Bag<P>` and `Bag<P!>` bind
  the same `T`, erased to its maximal rights, so a `v: T!` there would demand a
  mutable argument either way. `MutableMap`'s write path is
  `m[k] = v`, which the recursive freeze covers at the index-set slot.
- **`rooted_in_storageless_const` may now be redundant**: the const's type tells the
  truth, which is what its three call sites compensated for. Not removed here.
