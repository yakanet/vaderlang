# 0036 — A type parameter grants mutation through a marked bound

## Status

Accepted (2026-10-07). Closes the two `.rodata` writes that 0035 left open, and a
third that 0035 opened: a read-only value filling the trait variant of a union.
Amends 0022: inside the body, mutating through a `T` also takes a marked bound.

## Context

0032 binds `T` with the argument's rights, and 0022 reads `x: T!` at the call as
"as mutable as `T` is bound to". So `poke(CFG)` binds `T` to a read-only `Cfg` and
asks nothing. The body of `poke :: fn<T: Bump>(x: T!)` read the same `x: T!` as
mutable, and called `x.bump()`. The two readings disagreed, and the module const
was written: SIGBUS in a native build, a silent write under the VM.

`await` had the same gap without generics. It drives its operand through `resume`,
a `self!` member, but it checked nothing: `await view()`, with
`view :: fn() -> Async<i32> = ONCE`, wrote into the const. `for` already refuses a
read-only iterator, for the same reason.

The third write came from `mutability_widens`. It pairs two unions' variants by
index, which matches variants of one shape. A value of another shape that fills a
trait variant was never compared with it: neither a plain value
(`c: Cfg` into a `Bump! | null`) nor a union whose sort order differs
(`null | T` against `Bump! | null`).

## Decision

**A value of type `T` grants mutation only when a trait of `T`'s bound is marked
`!`** (`T: Bump!`). The body also needs a mutable slot (`x: T!`). One predicate,
`withholds_mutation(t, bounds)`, states it; a missing bound table means "no `T` is
judged", which is what `is_assignable` needs, since it never widens a `T` into a
trait. Every reader goes through it:

- `value_is_read_only`, which serves T3071 (a `self!` member), T3072 (an argument),
  and `reject_driving_immutable`. That last one is shared by `for`, `await` and
  an index write through a `T: IndexSet` bound, which checked no rights before;
- `mutability_widens`, which takes the bound table. It serves the trait widening
  in `try_into`, the reassignment and the T3077 wording;
- `narrowing_immutability`, so `x is Cfg` on a `T` is read-only unless the bound
  grants.

Around that predicate:

- **The call honours the bound.** A call binding `T: Bump!` to a type that grants
  no mutation is T3006: a module const, a read-only return, or a `T` whose own
  bound is unmarked. An explicit type argument is a written type, so it takes the
  read-only default and says `poke<Cfg!>(c)`.
- **A value fills one variant of a union slot.** After the index pairing, each
  variant is judged against the trait variants it may fill
  (`widens_into_trait_variant`), unless the union has a variant of its own shape.
- **One report per argument.** A `T` at an argument's top level, bare or as a
  variant, has no bit for `arg_mutability_cleared` to clear, so the parameter's
  top level is set aside instead (`param_shape_slot`), on the plain, generic and
  UFCS paths. T3072 alone reports the rights.
- **The hint names the bound**: "mark the bound of `T` `!`".

## Consequences

Measured on 2026-10-07, at `23f230fc0`:

- **The compiler, `lib/` and `tools/`** needed nothing.
- **On 846 programs**, `check` changes only on the fixtures this decision adds or
  rewrites, once the corpus says `!` where it mutates:
  - non-coroutine factories say `-> Async<T>!`;
  - awaited slots say `Async<i32>!`;
  - five generics mark their bound (`write_nth<Cell!>` at one call);
  - three fixtures mark a bound, so they keep testing what they test.
- **Snapshots:** only `lexer`, `parser`, `typecheck` and `lower` moved, by the new
  markers and the columns they shift. No `vm`, `bytecode` or C snapshot moved.
- **Typecheck time** is unchanged within noise (about 515 ms on the compiler, with
  release builds).

Still open:

- **An index write through a concrete `IndexSet` receiver** checks the access path
  (T3070) but not the receiver's own bit: `view(c)[0] = 9` passes where
  `view(c).set_at(0, 9)` is T3071. Checking it costs over 100 errors in the tree,
  because `MutableMap` fields declared without `!` are written through `m[k] = v`.
  That is a field-rights question rather than a `.rodata` one, since T3096 keeps
  maps out of consts.
- **A `-> Self!` member hands back a fresh value**, but its type is `T`, which
  carries no bit. Mutating it asks for the marked bound too (`relay :: fn<M: Make!>`
  in the T3095 fixture). That is over-strict, not a hole.
- **A struct's own type parameters** are not checked at instantiation
  (`first_unmet_bound` keeps trait keys, not their bits). So `Wrapper<T: Bump!>`
  instantiated with a read-only `Cfg` is not refused. No struct in the tree takes
  a bound marked `!`.
- **Two older bugs** sit next to this change. Both are already wrong at
  `135fe2160`:
  - `await` on a bounded `T` does not unwrap it (T3020, "got A");
  - an `Iterator<i32>!` value bound to `I: Iterator<i32>` is T3006 ("does not
    implement").
