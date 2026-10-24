# 0055 — A property over the call graph is one fixed point

## Status

Accepted (2026-10-12). The engine of the property layer the type-system work calls
for; its first client runs in observation and changes no emitted code.

## Context

Four analyses already followed calls, each with a fixed point of its own and its
own idea of a cycle: `compute_may_alloc` in the C emitter (least fixed point), the
propagation of type-parameter observation in the typecheck (least fixed point),
the closure of parameter inference (a worklist) and `bce_fn_pure` in the lowering
(a pessimistic sentinel, so every recursive function is impure, a pure `gcd`
included).

The range analysis of midir followed none: every call forgot every array length
it knew, in case the callee shortened the array. On the self-compile it proved
312 of 6026 array accesses. Letting direct calls keep the lengths, which is not
sound, proved about 1890.

## Decision

- **`vader/support/fixpoint`**, a module of its own that depends on `std` only, so the
  typecheck can import it as well as midir. A `Graph` over dense node indices,
  its strongly connected components callees first (Tarjan with an explicit stack,
  so a long call chain does not depend on the host's recursion depth), and
  `solve_bottom_up`, which steps every node of a component until none changes.
- **The client owns the facts and the lattice.** Facts live in the client's
  arrays and the step is a closure: no generic parameter, since the compiler's
  generics still have open gaps and dense arrays are faster than maps. A
  component that does not settle within the client's cap is handed back, and the
  client puts its nodes on a value that is always sound.
- **The first client is midir's**: whether running a function may shorten an
  array. Only `remove_last` and `clear` shorten one; growth keeps `i < len(xs)`
  true. The call graph has a node per function and per bodyless function, plus
  three: one for indirect calls, one for the functions handed to C as callbacks,
  which every bodyless function may call back, and one for a callee the project
  does not define. It resolves a callee through the same resolution as the CFG
  verifier, the chain the bytecode emitter follows.
  - An indirect call or a deferred block reaches every function some Vader value
    is taken of (`InstrFnRef`, `InstrMakeClosure`), and a bodyless function every
    function handed to C (`InstrFnAddr`): those are the only sources of a value of
    function type, and the CFG is the whole program. A virtual call whose key no
    vtable row carries counts as a call to an unknown function.
  - A bodyless function is judged by what the host does for it. Foreign code
    (`@extern`) is lent an array's buffer, never the header that holds its length.
    A host function an op serves, like an intrinsic, shortens an array if that op
    does (`op_shortens_array`: `ArrayRemoveLast` and `ArrayClear`). Any other host
    function answers through `intrinsic_may_shorten_array`, an exhaustive match on
    `IntrinsicId` beside `intrinsic_may_collect`: a new host function has to say.
- **Observation only.** The range analysis reads the summary; `array_load_forward`,
  `cfg_dce` and `bce_fn_pure` do not. `$VADER_OPT_REPORT` runs the analysis with
  and without the summary, so one build shows what the summary adds.

## Consequences

- On the self-compile, 1458 of 6026 accesses are proven instead of 312. 1460 of
  5498 functions may still shorten an array, 35 of them by their own body: the
  rest inherit it through calls.
- A first version judged a bodyless function by what it is handed (anything that
  can lead to an array or to code) and proved 1115: system calls taking a byte
  buffer and the `Buffer` operations made every caller cautious.
- Indirect calls account for most of what is left. Assumed harmless, which is not
  sound, they bring the count to about 1870. Splitting them by arity proved 8 more
  accesses and was not kept: the functions that shorten an array share their
  arity with the common callbacks. Telling the closures that reach a call site
  apart needs a flow analysis of closures.
- The report's range analysis takes about 510 ms instead of 250 ms, since it runs
  twice. Without `$VADER_OPT_REPORT` nothing runs.
- Eliding the checks this proves was a separate decision: ADR 0058.
- The typecheck's propagation of type-parameter observation runs on the engine
  too (`type_param_observation.vader`): a node per function that observes or
  relays, an edge per call that hands its callee the caller's own type
  parameters. Each client solves a reachability, through `solve_reachability`,
  which owns the cap and the sound side of an unsettled node. The loop the
  typecheck's client replaces swept every call once per link of the longest
  chain of such calls: `vader check` on a chain of 3000 generic relays takes about
  595 ms instead of 660. No function of the compiler observes a type parameter,
  so its own build does not move.
- The C emitter's `compute_may_alloc` follows: a node per bytecode function, an
  edge per direct `call`. Its set was an `i32[]` searched with `in`, swept once per
  link of the longest chain; it is now a `bool[]` read by index, and the
  self-compile's C emission takes about 3350 ms instead of 3390, its output
  unchanged. Its graph is the bytecode's, not midir's: the C emitter also reads
  a `.virt` dump, which has no CFG, and the bytecode emitter adds `_vt` wrappers
  and renumbers the functions after midir. An indirect or virtual call stays an
  allocator by itself; resolving them as midir does would spare no frame on the
  self-compile, by an estimate over its bytecode.
