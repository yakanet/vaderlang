# 0175: WASM has its own emitter, on Wasm GC

## Status

Accepted (2026-11-22). Amends 0009 for the `wasi-wasm32` and `browser-wasm32`
targets: they do not go through C. How a WASM program reaches its host is 0176.
**Amended by [0177](0177-a-wasm-array-is-one-header-over-a-storage.md)
(2026-11-23)**: `is` on an array type reads a field of its header, and the slot
loads and stores are translated.

## Context

Two routes lead to WASM. The first keeps C (0009) and hands the emitted code to
clang for `wasm32-wasi`. It carries the runtime as it is, with two things WASM
does not have: the conservative scan of the C stack (0008) cannot read WASM
locals, which live on the engine's value stack, and the virtual threads switch
stacks in assembly. Rooting would have to become fully precise first, and the
program would still carry a collector of its own in linear memory.

The second emits WASM from the bytecode, as the VM and the C emitter consume it.
The bytecode's control flow (`docs/RUNTIME.md`, *What a backend provides*) is
already WASM's: it maps one to one, with no stackifier. Wasm GC gives it a
collector.

Probed on 2026-11-22 with hand-written WAT, wasmtime 51.0.0, Node 22.19.0,
wasm-tools 1.263.0 and wasm-opt 133:

- **Type identity.** Wasm GC canonicalises types by structure, rec group by rec
  group. 1 000 structs of the same shape, each in its own group: `ref.test`
  answers wrong 1 000 times out of 1 000, on both engines. In one rec group: no
  wrong answer up to 100 000 types, fields referencing other types included, and
  wasmtime compiles the module in 0.34 to 0.38 s. Types that reference each other
  do not validate at all outside a rec group.
- **Collector.** 4 million iterations, each building two nodes that point at each
  other and two arrays of 1 KiB. wasmtime's `drc` collector leaks the cycles and
  fails at 3.7 GB; `copying`, and the default of wasmtime 51, stay at 8 MB. Node
  stays at 47 MB.
- **wasm-opt.** `-O3 --closed-world` keeps distinct the types a cast tells apart,
  and drops unused fields. With `-all` it emits `exact` types, which neither engine
  reads.

## Decision

- **A WASM emitter of its own**, fed by the bytecode as the VM and the C emitter
  are. The bytecode keeps its structured control flow: moving it to flat jumps or
  to a CFG would now cost a stackifier.
- **Wasm GC.** The engine allocates and collects; no collector is written for
  WASM.
- **One rec group holds every type of a module.** `is` is `ref.test` and
  `br_on_cast` on the type itself.
- **A scalar in a union or beside `null` is boxed in a struct of its own type**
  (one box type per scalar type). `null` is `ref.null`.
- **Strings stay atoms**: an `i32` indexing a module-wide table of byte arrays, so
  `StringEq` is `i32.eq`, as natively.
- **The encoder is written in Vader.** No external tool is needed to produce a
  module that runs. `wasm-tools validate` is an oracle for the tests; `wasm-opt`
  is optional, run on the core module with the target's features listed
  explicitly, never `-all`. wabt is set aside: its support of Wasm GC is
  incomplete.
- **Out of the first cut**: tasks, WASM exceptions (a panic hands its message to
  the host, then `unreachable`; `defer` is already explicit in the bytecode), and
  the ops of the C boundary (`FnAddr`, `LoadSlot*`, `StoreSlot*`, the `@c_struct`
  mirrors), rejected on a WASM target.

Set aside:

- **C through clang**, and **linear memory with a collector written for WASM**:
  both need a collector of ours and a root set that misses nothing.
- **A `type_index` field in every object.** One field more per object, and the
  engine's casts unused. It stays the fallback if an engine caps the size of a rec
  group.
- **`i31ref` for small integers first.** Two rules where one does; to measure
  later.
- **A string as a reference to its bytes and hash**, compared by content. It would
  not leak, but `StringEq` would compare bytes. To revisit if a long-lived browser
  program meets the leak below.

## Consequences

- 0009 still holds for native targets. Under Wasm GC, 0008's rooting and the
  object header do not apply. A length or an index is an `i64`, which the emitter
  wraps to `i32` after the bounds check.
- Wasm GC has no weak reference: the atom table never shrinks, and native atom
  collection has no counterpart.
- How good collection is depends on the engine: wasmtime's `drc` would leak every
  cycle a program drops.
