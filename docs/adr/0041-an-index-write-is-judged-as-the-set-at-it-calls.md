# 0041 — An index write is judged as the `set_at` it calls

## Status

Accepted (2026-10-07). Closes the index item that 0036 left open.

**Superseded in part by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: its rights half, a type carrying no rights any more.

## Context

`m[k] = v` on a receiver with an `IndexSet` impl lowers to `m.set_at(k, v)`, and
`set_at` takes `self!`. The call written out was judged (T3071 on a read-only
receiver), the index write was not. Only the path to the receiver was checked
(T3070), so a field written without `!` took the write:

```vader
Counts :: struct {
    by_name: MutableMap<string, i32>
}
c.by_name["x"] = 7           // accepted
c.by_name.set_at("x", 7)     // T3071
```

A bounded `T: IndexSet` was already judged (0036), and so was an array (T3042).
The concrete case was the one write form left out.

The compiler relied on the gap. Its pass tables (`TypedProgram.expr_types`,
`ResolvedModule.idents`, `FnLowerCtx` caches and the like) are `MutableMap`
fields written without `!`, filled through `[]=`. A first attempt, in 0036's
step, stopped at more than a hundred errors.

## Decision

**An index write through `IndexSet` is judged as the `set_at` call it is.** One
check, `reject_index_write_receiver`, judges the receiver of every write form
(an assignment, a destructuring target). An array keeps T3042 and T3070. Any
other receiver asks `reject_driving_immutable`, as `for` and `await` already do:
a read-only receiver is T3071, whether its type is concrete or a bounded `T`, and
whether the path or the field withholds the right.

**The tree marks what it writes.** Each field rewritten through `[]=` takes `!` on
its type, which is what the style guide asks of any field a pass rewrites.

- A local that only needed its annotation to be read-only loses it: an inferred
  local is owned.
- A factory whose map is filled after return (`new_import_table`, `new_scope`)
  hands it back marked.
- An array or map holding written maps marks its element (`Scope.frames`,
  `struct_trait_args`).

T3071's hint no longer repeats itself: `mutation_fix_hint` already holds the
read-only field's hint.

## Consequences

Measured on 2026-10-07, at `c2a9f9b74`:

- **The cascade reached its fixed point.** 261 errors at first. 118 field and
  parameter types took `!` from the hint each error carries. About 20 sites were
  edited by hand over a few more rounds: the locals, the factories, the element
  types, then the `Scope` root and the functions that produce it. In all, 30
  compiler files changed (145 lines, the rule included), plus
  `lib/std/async` (`JoinAll.results`) and one snippet.
- **On 848 programs**, one program's diagnostics change: the snippet that wrote
  into an unmarked map field. One T3071 message loses its repeated hint.
- **A map reached through a read-only root** (a parameter, an alias, a loop
  variable) now reports T3071, as `set_at` would, where it reported T3070.
  Which programs are accepted is unchanged.
- **A destructuring target** (`[c.by_name["a"], …] = …`) is held to the same
  check, where it skipped the `set_at` rule.
- **Typecheck time** is unchanged (release builds, minima 522.4 against
  517.8 ms).

Still open, as before this change: an index write is T3008, though the
equivalent call is accepted or the receiver has an `IndexSet`, on

- a trait value (`store: IndexSet<string, i32>!`, where `store.set_at(…)` is
  accepted);
- a union of two `IndexSet` receivers;
- a destructuring target through a bounded `T`.

