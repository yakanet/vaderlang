# 0059 — What a function does with its parameters is summarised after the typecheck

## Status

Accepted (2026-10-13). The effect summary that ADR 0053 calls for, and its frozen
checks. Their faults are observed only, in `vader dump --stage=effects`, beside the
rights the typecheck still enforces; their copies are made (2026-10-14). Moving
the rights out of the types onto them is a later decision.

**Extended by [0066](0066-an-access-keeps-the-constraint-that-put-it-in-its-set.md)
(2026-10-15)**: each access keeps the constraint that put it in its set, and a fault
names the calls and the write that modify the value.

**Its faults are errors since [0067](0067-the-frozen-values-decide-what-may-be-written.md)
(2026-10-16)**, which moved the rights out of the types onto them.

## Context

ADR 0053 freezes the value of a module constant and a view of a string's bytes.
It rests its two errors on a summary of whether a function modifies what a caller
lends a parameter, and its copies on whether the function keeps it. Until now the
closest thing was the deduction of `!` (0051, 0052), which is the typecheck
replayed in rounds and sees a write only when a rights check refuses it. The
holes of those checks were therefore its own: a field written through a union, an
`is` that keeps only the top-level rights, a tuple element, the arguments of a
type, `+`, an array turned into an iterator.
Eight probes of 2026-10-09 compile and write into a constant, which the native
build punishes with a `SIGBUS`; two more, of the same time, modify one through a
callback.

## Decision

- **A pass after the typecheck** (`vader/effects`), over every module's typed
  bodies and call record (0056), on the fixed-point engine (0055). Every check
  runs it (`vader/pipeline/check`): the CLI, the LSP and the seed's driver.
- **The fact is a set of accesses per parameter**: an effect (assigned, resized,
  shrunk, stored, returned, unknown) at a path below the parameter. A path is at
  most three steps, each a field by its name or an element, and is cut past
  that. A narrowing takes no step, so a write is recorded by its form, whatever
  the type it writes through.
- **Each body is read once into constraints over slots**, which the fixed point
  evaluates against the callees' summaries. A local is an alias, its slot holding
  everything bound or assigned to it. What a callee returns is not an effect on
  the argument: the caller holds it through the call's result.
- **Calls**: a member reached through a trait or a bound runs the member of every
  impl of the project, and an impl that relies on the trait's default may do
  anything, defaults not being indexed; an intrinsic does what a table of the
  compiler says, and one the table omits may do anything unless it takes no
  references; an `@extern` writes its `@c_out` parameters. A function value, or a
  site the record could not settle, keeps every argument and brings `unknown`
  below it, which a client needing a sound answer reads as any change. This
  departs from ADR 0053, where a function value is assumed to modify: an unknown
  change is told apart from a proven one.
- **The sets stay small in two ways**, the cut at three steps already keeping them
  finite: through a call back into the caller's own component, a part of a
  parameter handed down takes everything below it, and a cut path drops the
  accesses it covers. Without them a recursive walk of a tree named every
  combination of fields down to three steps, 35 000 accesses for one parameter.
- **The frozen checks** are computed beside the rights, not instead of them. Each
  use of a frozen value is a root of its function's skeleton, followed like a
  parameter: through fields, elements, branches, aliases, and what a callee
  returns. A name bound to it holds a copy (E1), a root of its own. A use written
  through, or lent to a callee that modifies it, is a fault; one only unknown code
  may modify is reported apart; a use stored or returned is a copy. A binding
  written, stored, returned or handed to unseen code is a copy; one only read
  shares the frozen value. A copy is left out when no write of the program reaches
  a value of the type of what is kept, returned or handed on, or of a type it
  holds: an element kept out of a table is judged by the element's type.
- **The copy is made at the use.** A use the checks copy, or hand to unseen code
  with a type some write reaches, reads a fresh value of its constant. The summary
  lists those uses (`EffectSummary.fresh`), and the typed project the lowering
  reads carries them with no default, so a driver that skips the summary does not
  compile. A constant laid out in the data pool, one value every read shares, gets
  an accessor that builds its literal again, which those uses call; a constant
  wrapped in a function or inlined at each read is fresh already. A view of a
  string's bytes is not copied yet: without telling one field of a struct from
  another, the copy would land on every `for c in s`.

## Consequences

- On the compiler, the summary names 6 600 functions and settles every component;
  it costs about 150 ms in the process, most of it the walk and the fixed point.
  Every check runs it, since the lowering reads which uses take a fresh value.
- A copy builds the whole constant, even where one element escapes:
  `intrinsic_spec`, which hands out an entry of `INTRINSICS`, builds the table at
  each call, since an entry carries an array and some array of every program is
  written. Copying only what escapes needs a copy per type, which the lowering
  does not have.
- The frozen checks find no proven fault on the compiler. They catch the ten
  probes, as a fault, an unknown call or a copy, and the 36 rights fixtures of the
  diagnostic corpus whose error concerns the use of a constant, at the site or
  through a copy upstream.
- The compiler has 19 sites where only a function value could modify a constant,
  through higher-order helpers such as `any_match`; none is proven, and all go
  when function values are taken as readers. Turning the checks into errors
  needs a decision on those first.
- Type-based elision leaves out 569 copies, 416 of the 438 stores of a type
  singleton among them. A binding only read shares the frozen value: of the 201
  copies the first version kept, 148 being views of a string's bytes bound to a
  name, 17 remain (2026-10-14, roots of the skeleton, and a copy judged by the
  type of what escapes rather than by the whole constant's).
- `CheckResult.impls` holds the entry module's impls only; the summary builds its
  own registry over every module, as the lowering does.
