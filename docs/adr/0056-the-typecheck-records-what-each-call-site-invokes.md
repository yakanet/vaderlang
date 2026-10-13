# 0056 — The typecheck records what each call site invokes

## Status

Accepted (2026-10-13). The record the property layer of the type-system work walks
for its call edges. Its first readers are the language server's references and
rename, the call edges of the mutability deduction, and the propagation of
type-parameter observation. The lowering reads it form by form, once a verifier
in the lowering finds the two agree: free fns, impl members, and what dispatches
through a trait at run time so far.

## Context

A call's callee was decided in several places: `field.vader` for a member,
`call.vader` for an overload, the resolver for a plain name. Many sites that call
through a trait left no trace at all: an operator, an index, a `for`, an
interpolation, an implicit `into`. The lowering decided those again, by name or by
type, in about ten places, and disagreed with the typecheck in some of them.

A property over the call graph (ADR 0055) needs one answer per site, given once at
the typed level, where a generic body is checked once.

## Decision

- **One record per module**, `TypedProgram.call_sites`: a table per role (a call,
  an operator, an index read, an index write, an `into`, the `into` and the `next`
  of a `for`, an interpolated value), each keyed by the node's id. Node ids are
  project-wide, the members materialised from a trait default included, so a
  function is named by the id of its declaration.
- **A callee is a closed union**: a known declaration (marked when the lowering
  chooses again at each instance), a member reached through a type parameter's
  bound and settled per instance, a member of a trait value or a union dispatched at
  run time, a value of function type, no call, an erroneous callee, a valid form the
  record does not cover, and several calls at one site (a structural `==`). A
  `match` over it is exhaustive, so a reader has to handle a new form.
- **Each decision is filed where it is taken.** A check files "not settled" on entry
  and each route files what it decided, "no call" included. A route that decides
  nothing then shows as unsettled instead of passing for a built-in operation.
- **The record says what the language runs**, not what the lowering emits today:
  - walking an array, counting through an integer range written in place, and
    interpolating an integer, a `bool` or a `string` are built in;
  - a generator's state steps through the generator's own declaration;
  - a structural `==` lists the `equals` of each part it compares;
  - a conversion runs the `into` the lowering's rule picks, none for the same type
    or for a distinct handing out its own backing, and a cast files that `into` at
    its value.
- An overloaded member behind a namespace alias is recorded as its first
  declaration: the typecheck itself checks the call against that one alone. The
  lowering reads the record, so resolving the overload there is enough.
- **The call graph's edges.** A call to a generic fn keeps the type each of the
  fn's type parameters takes there (`DirectFn.bindings`), and the calls written in
  each function are listed under its declaration (`CallSites.calls_in_fn`). A
  lambda's calls are listed under the function around it, whose instances it
  shares.
- `vader dump --stage=callees` prints each site with its role and callee, and the
  count of unsettled sites.

## Consequences

- On the self-compile, 49 709 sites, none unsettled. Typecheck time moves within
  noise (about +3 %), allocations by 0.1 %.
- The record and the lowering already disagree in known places:
  - fast paths that inline a known call (array repeat, `in` over a literal range,
    map and set walks, chain fusion, a string stepped through `chars`);
  - a struct that only converts into an iterator, whose `into` the lowering never
    calls;
  - a distinct with no `Display` of its own, and an expression of free literals,
    which the lowering renders through a virtual call;
  - an `into` the typecheck accepts at an assignment and the lowering never emits.

  The verifier lists them. Where the lowering is wrong, the lowering is fixed, not
  the record.
- The lowering switches to the record form by form, once the verifier reports no
  unexplained disagreement for that form.
