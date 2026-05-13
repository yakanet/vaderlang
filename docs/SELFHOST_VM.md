# Self-host VM — incremental port plan

The `src/vm/` interpreter is the next compiler component scheduled for
self-host port (TODO §2.4). This document tracks the **incremental
strategy** — instead of porting the whole 1300-LoC TS VM (plus the
~2300 LoC `src/bytecode/` reader stack) in one shot, we bootstrap on
the existing TS-produced `.virt` text dump and grow the Vader-side
reader + executor sprint by sprint.

The key insight: the `.virt` text format is already the supported pivot
between the TS toolchain and end-users (`vader build --target=ir-text`
produces it ; `vader run` already accepts `.virt`/`.vir`). The Vader VM
can therefore validate end-to-end against the TS compiler **before**
the typer / lower / bytecode emit are ported. Reading `.vir` (binary)
comes later — it's cosmetic until ship-size matters.

## Sprint 1 — Minimum vital

**Goal**: `vader run trivial.virt` exits with the user code's return
value, on a snippet shaped `main :: fn() -> i32 { return 42 }`.

**Acceptance**:
- `vader build --target=ir-text tests/snippets/return_42/_main.vader` produces a `.virt`.
- `vader run <that-virt>` exits 42.
- Behaviour matches `bun src/index.ts run …`.

**Scope** (only what the trivial snippet exercises):
- `.virt` parser: `module <name>`, `fn N name (params) -> ret`, op
  lines, `end`. Reject unknown directives loudly so missing coverage
  surfaces as a diag not a silent miss.
- Op coverage: `i32.const`, `return`.
- Value repr: `i32` only.
- Host: none (no `println`, no I/O — exit code is enough).
- Bytecode shape: minimal `BytecodeModule` Vader-side — name + a single
  `BcFunction { name, ret, body: Op[] }`.

**Layout** (start consolidated, split when it grows):
- `vader/vm/exec.vader` — value type, parser, exec loop, all in one
  for sprint 1.
- `vader/cli/main.vader cmd_run` — dispatch on `.virt` extension to
  the new module.

**Out of scope for sprint 1**: locals, control flow, binops, strings,
println, structs, arrays, calls, type checks, imports, intrinsics,
traits/vtables, binary `.vir`.

## Subsequent sprints (rough scope, may be revised)

| Sprint | Adds | Snippets unlocked |
|---|---|---|
| 2 | locals, binops (i32 arith + cmp), `if`/`block`/`loop`/`br`/`br_if` | most numeric snippets |
| 3 | strings + `vader_println` host fn → "hello world" | `hello_world`, `interp_string` |
| 4 (a) | direct `call` + Frame stack — multi-fn modules ✅ | `vm_call_simple`, `vm_call_chain`, `vm_call_recursive` |
| 4 (b1) | type table + struct ops (`struct.new(_stack)`, `struct.get`, `struct.set(_stack)`, `local.tee`) ✅ | `vm_struct_point`, `vm_struct_nested`, `vm_struct_mutate` |
| 4 (b2) | array ops (`array.new`, `array.push`, `array.get`, `array.set`, `array.len`) + no-op `ref.cast` / `*.to_*` conversions ✅ | `vm_array_basic`, `vm_array_push_len`, `vm_array_mutate` |
| 4 (b3) | intrinsic builder.* — unblocks `"${}"` interpolation | most println-heavy snippets |
| 4 (b4) | `fn.ref` + `call.indirect` — fn-values stored in fields / arrays | `fn_value_*` |
| 5 | `type_check`, `ref.cast`, virtual.call, intrinsics, traits/vtables | nearly all snippets |
| 6 | binary `.vir` loader (alternative to text) | shipping-perf gains |
| 7 | Split `vader/vm/exec.vader` into `vader/bytecode/{types,ops,module,text}.vader` + `vader/vm/{value,exec,host}.vader` once the single file becomes unwieldy (probably mid-sprint 3 or 4). |

## Validation strategy

Each sprint adds a small **VM snippet test set** under `tests/snippets/`
guarded by a new `tests/vader_vm.test.ts` (parallel to the existing
`tests/vm.test.ts` which runs the TS VM). The test compiles each
snippet via the TS toolchain to `.virt`, then runs it through the
Vader-built `vader run`, then asserts the exit code + stdout match the
TS-VM-recorded `vm.snapshot`.

This piggybacks on the existing `vader build --target=native` build
chain (the Vader CLI ships as a native binary), so the harness can
spawn `./build/vader run <snippet>.virt` and compare against the TS
baseline without rebuilding the world.

## Bootstrap-check connection

This effort is the first half of TODO §2.4 ("Port the VM"). It doesn't
yet touch §2.6 (typer port) — the Vader VM stays parasitic on the TS
typer/lower/bytecode emit through sprint 5. Once those three are also
ported, `compiler_v2 (TS)` vs `compiler_v3 (Vader)` differ only in the
bytecode emit driver, which is the bootstrap-check (§2 phase-end goal).
