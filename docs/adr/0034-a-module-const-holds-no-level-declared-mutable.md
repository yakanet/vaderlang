# 0034 — A module const holds no level declared mutable

## Status

Accepted (2026-10-07). Closes the `.rodata` writes that 0017's permissive rule left
open. The transitive read-only rule it was weighed against is deferred until
parameters are inferred.

## Context

A module const is frozen at every level its type spells out: the unannotated
default (`auto_freeze_module_const`) and an annotation's default reach arrays,
tuples and union variants. They cannot reach a level the const's type does not
spell, such as a struct field declared `items: i32[]!` or a type argument
`Box<Cfg!>`. Those levels keep the rights their declaration grants, and 0017's
permissive rule honours them whatever path reaches them.

Through the const's own path the write is still refused: `CFG.items[0] = 9` is
T3070, because the path starts at a storageless const. That path is lost as soon as
the const leaves its name:

- a fn hands it out (`view :: fn() -> Cfg = CFG`, then `view().items[0] = 9`);
- a copy is made (`h :: Cfg { ...CFG }`, which is shallow, so `h.items` is
  `CFG.items`);
- it is lent to a parameter (`grow(Wrap(ORIGIN))`, which writes `w.items`).

Each compiled, and each died of SIGBUS writing into `.rodata`.

Two remedies were measured on 2026-10-07, at `4f2dd6265`.

- **Transitive read-only.** A field read through a read-only struct is read-only
  at every level.
  - The compiler's own closure gave 375 errors on the first round.
  - Six rounds of automatic annotation placed about 150 `!` across 62 files, and
    then stalled at about 185 errors without a fixed point.
  - Most of what it could not resolve is how the compiler builds its IR: a fresh
    node takes a subtree read through another node (`.target = prev.target`), and
    under the rule the source node then has to be owned mutably.
- **Refusing the const.** A const whose value reaches a level its declarations
  mark `!` is rejected. Two consts in the tree were affected, both harmless:
  - a primitive declared through the `Type` union;
  - an empty array.

## Decision

A module const whose type reaches, below its own level, a level that grants
mutation is **T3096**, and so is an enum whose variant data does — that data is a
constant table every read shares.

- **What counts as such a level:** a level marked `!`, or a trait value (it has no
  bit of its own, and a `self!` member mutates through it).
- **What the walk visits:** array elements, tuple elements, union variants and
  distinct backings. A struct is walked through its type arguments, then its
  declared fields, once per struct. Walking the declared rather than the
  substituted fields is what makes the walk end on a type like
  `Nest<T> { deeper: Nest<T[]> }`.
- **The writable array is not exempt.** Its spine is storage the program owns, but
  its elements are emitted as read-only statics. So `SPECS: Cfg[]!` is refused when
  `Cfg` has a field `items: i32[]!`.
- **Under a union annotation**, the value's own type is walked. A const holds the
  variant its value built, so `DEFAULT: Cfg | null: null` passes.
- **What is left alone:**
  - an empty sequence literal, which holds nothing to write;
  - a marker T3076 already refuses, which is not reported twice. T3076 reads the
    annotation's array and tuple levels, so a marker inside a type argument
    (`E: Box<Inner!>`) is T3096's.

A fn that returns a fresh value (`fn() -> Cfg!`) is the form to use instead.

Transitive read-only as a *contract* (`grow(w: Wrap)` that writes `w.items` while
promising to only read `w`) is a separate question. It costs mostly parameter
annotations, which the planned parameter inference makes free, so it is left until
that lands. With no const able to reach a mutable level, what remains open there is
a signature that does not say everything; it is no longer a memory fault.

## Consequences

- **The tree** changed in one place: `TY_TAG` is a `PrimitiveType` singleton
  instead of a `Type`-typed `mk_primitive`, whose union type reached a variant with
  a field marked `!`.
- **On 832 programs** (every snippet, every diagnostic fixture, the examples, the
  benchmarks and the tools), one adds a diagnostic: the fixture that pins T3070 for
  a const whose field is `!` now also reports T3096 at the declaration. Six fixture
  details change wording, because a const's fix hint now says to hand out a fresh
  value from a fn rather than suggest a marked type a struct const cannot take.
- **The reproductions are refused:** a const handed out by `view()`, a copy
  `{ ...CFG }`, a lent const, a writable array whose elements have a `!` field, a
  map or a `StringBuilder` const, a const holding a trait value, and enum variant
  data with a `!` field. Each died of SIGBUS before.

Still open:

- **A read-only struct widened into a trait value keeps no read-only bit**, so
  `as_bag(BAGS[0]).poke()` (`as_bag :: fn(c: Cfg) -> Bag = c`) still writes into
  `.rodata`. A `TraitType` with a read-only bit is the fix; T3096 cannot see it.
- **`rooted_in_storageless_const` stays.** Through a trait level it is still the
  only guard on a const's own path, until that bit lands.
- **A type argument is judged whether or not a field uses it.** So
  `H :: Holder<Cfg> { .n = 1 }` is refused when `Cfg` has a `!` field, even if
  `Holder`'s `T` is a phantom parameter. Walking only the arguments that its fields
  use would fix it.
- **A field written `item: T!` keeps no `!`,** because a type parameter has no bit.
  That makes the walk blind to it. It is not a hole today, since the marker grants
  nothing, but it should be refused (T3075) or carried.
