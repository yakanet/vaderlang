# 0024 — The VM runs register code translated at load

## Status

Accepted (2026-09-29). Replaces the stack interpreter (`exec_entry`'s loop in
`vader/vm/exec.vader`) and its superinstruction pass (`vader/vm/fuse.vader`);
both are deleted.

## Context

The VM dispatched the shared bytecode directly: an operand stack per `Frame`
object, a push and a pop for every value, a tag test in every arm, a `Frame`
allocated per call. After the heap-side work of ADR 0023 the profile of the seven
VM benches was the dispatch itself — the stack traffic and the tag tests, not the
work the ops do.

The shared bytecode (`Op`, `.virt`, the C backend, the snapshots) is the contract
of the whole toolchain; the interpreter's representation is private to
`vader/vm`. So the choice was which private code to run, not whether to change
the bytecode.

## Decision

`prepare` translates every verified function once into private register code
(`reg_code.vader`, `reg_translate.vader`); `reg_exec.vader` runs it. Four decisions
framed it:

- **`Value` stays the exchange format** at the edges — the host dispatcher, the
  FFI, comptime, the heap. The engine boxes only where a value crosses one.
- **Operand tags are proven at load** (`tags.vader`, a forward dataflow over basic
  blocks). `prepare` refuses a module where an arm could meet a tag it does not
  accept, so no arm tests one at run time.
- **Every trap runs the pending `defer`s**, the last pushed first, as the native
  runtime does; a `defer` that traps in turn ends the unwind. The old loop drained
  them for four kinds of trap only.
- **Trap messages quote the original pc**, so they read the same as before.

The shape of the code:

- **Registers.** A function's window is its parameters, its locals, its constants,
  then one register per operand-stack depth. A callee's window starts at the
  register holding its first argument, so arguments are never copied and a result
  lands where the caller expects it. One register file serves the whole run, in
  three columns: raw bits, a tag, the boxed `Value` of a reference.
- **Lazy translation.** A `local.get` or a constant emits nothing; the op that
  consumes it reads the slot or the constant's register. A `local.set` right after
  the op that computed its value retargets that op onto the slot. Pending cells are
  written to their canonical registers wherever control can arrive from
  elsewhere.
- **Encoding.** An op is an `i32`-wide enum in one column and its three operands
  packed in one `i64` in another, so a fetch follows no pointer. A byte-wide enum
  was slower: an array of a `u8` enum is read through `vader_array_read_u8`, which
  tests whether the array views a string's bytes.
- **Fusion.** An integer comparison (signed or unsigned) feeding an `if` or
  `br_if` becomes one conditional jump; `>` and `>=` swap their operands onto `<`
  and `<=`. `ref.cast` and `box` translate to nothing.
- **Cold ops** — the bulk array, string and buffer ops, closures, conversions the
  tags do not prove — run through `apply_boxed` on a scratch operand stack holding
  their operands.
- **`defer`** is one stack for the whole run, as in the native runtime. A thunk runs
  as a nested call above the running frame.
- **The debugger** gets a separate translation with a `Line` op at every source
  position; a normal run has none and pays nothing for it.

## What was measured

Minimum of five runs of `vader run` on pre-compiled bytecode, the stack interpreter
against the register engine at the end of this work, same machine:

| bench | stack | registers | |
|---|---|---|---|
| `vm_loop` | 2 015 ms | 378 ms | ×5.3 |
| `vm_fib` | 656 ms | 188 ms | ×3.5 |
| `vm_arr` | 644 ms | 180 ms | ×3.6 |
| `vm_field` | 809 ms | 242 ms | ×3.3 |
| `vm_str` | 1 170 ms | 513 ms | ×2.3 |
| `vm_map` | 391 ms | 138 ms | ×2.8 |
| `vm_shapes` | 203 ms | 81 ms | ×2.5 |

The compiler running on its own bytecode (`vader run compiler.virt dump --stage=c
vader/cli/main.vader`) went from 593 s to 164 s, its output byte-identical to the
native compiler's.

`vm_map` measured 203 ms instead of 139 in one build of `build/vader` and 138 ms in
a standalone runner built from the same sources: a code-layout effect of the large
binary, not of the engine. Comparing two engines needs the same binary shape.

Steps along the way, each measured on the seven benches: the translation alone
(×1.1 to ×3.9), constants in registers, packed operands (fetch was a quarter of
`vm_loop`), compare-and-branch fusion (`vm_loop` −25 %), `load_slot` / `ref.cast`
out of the boxed path (`vm_arr` and `vm_field` roughly halved), the call's fast
path written into the loop (`vm_fib` −16 %: the frame helpers may grow an array,
so they do not inline). Moving the old loop's arms into `apply_boxed` behind a
call, rather than copying them, made the old loop 17 to 44 % slower while both
engines coexisted.

A trap label interpolated as an argument — `read_i32(v, pc, "${label} offset")` —
is built and interned on every execution, not only when the read fails. It cost
`vm_str` a fifth of its time in the byte ops, and `vm_arr` a quarter once
reintroduced by accident. The label is built in the trap branch only.

## Consequences

- The heap is still boxed: a `Value` is allocated for every scalar stored into a
  struct field or an array element. That is now what bounds `vm_arr`, `vm_field`
  and `vm_str`.
- The comptime step budget counts the original ops a back edge spans, and one per
  call, instead of every op dispatched. A non-terminating `@comptime` loop still
  trips it; the count at which it does is not the same.
- A register or jump operand past the packed widths (22 bits for `a`, 21 for `b`
  and `c`) is refused at `prepare` with a `VerifyError`.
- Every byte-wide enum array in the tree is read through the string-view test,
  `StackTag[]` included. Only a real `u8[]` can be such a view; letting the C
  emitter read other byte-wide element types directly is open.
