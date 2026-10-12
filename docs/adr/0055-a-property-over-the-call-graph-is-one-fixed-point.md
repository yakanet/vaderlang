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
312 of 6030 array accesses. Letting direct calls keep the lengths, which is not
sound, proved about 1890.

## Decision

- **`vader/fixpoint`**, a module of its own that depends on `std` only, so the
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
  true. The call graph has a node per function, per bodyless function, one for
  indirect calls, one for the functions handed to C as callbacks, which every
  bodyless function may call back, and one for a callee the project does not
  define. It resolves a
  callee through the same resolution as the CFG verifier, the chain the bytecode
  emitter follows.
  - An indirect call or a deferred block reaches every function some Vader value
    is taken of (`InstrFnRef`, `InstrMakeClosure`), and a bodyless function every
    function handed to C (`InstrFnAddr`): those are the only sources of a value of
    function type, and the CFG is the whole program.
  - A bodyless function may shorten an array when one of its parameters can lead
    to one or to code: anything but a scalar, a string, a C pointer or an enum
    without variant data.
- **Observation only.** The range analysis reads the summary; `array_load_forward`,
  `cfg_dce` and `bce_fn_pure` do not. `$VADER_OPT_REPORT` runs the analysis with
  and without the summary, so one build shows what the summary adds.

## Consequences

- On the self-compile, 1115 of 6030 accesses are proven instead of 312. 2638 of
  5499 functions may still shorten an array, 35 of them by their own body: the
  rest inherit it through calls.
- Most of the gap to the unsound bound comes from two cautious rules. With every
  bodyless function assumed harmless, 1466 accesses are proven; with indirect
  calls assumed harmless, 1224; with both, 1874. The native runtime shortens an
  array only in `remove_last` and `clear`, and calls back into Vader only through
  deferred blocks and FFI callbacks, which a tighter rule for bodyless functions
  could rely on. Indirect calls could be narrowed to the functions whose
  signature matches.
- The report's range analysis takes about 510 ms instead of 250 ms, since it runs
  twice. Without `$VADER_OPT_REPORT` nothing runs.
- Eliding the checks this proves remains a separate decision.
