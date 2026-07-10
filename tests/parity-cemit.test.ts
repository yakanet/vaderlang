// CLI C-emit parity (TODO §2.2) — Vader's `dump --stage=c` output.
//
// Two oracles per allowlisted snippet (see
// `.claude/plans/cemit-body-walker.md` §1) :
//   1. regression  — `dump --stage=c` matches the Vader-generated
//                    `c.snapshot` golden (catches unintended drift).
//   2. behavioural — the emitted C compiles with `cc` and runs, matching
//                    the VM-recorded `vm.snapshot` (the correctness oracle
//                    that survives the TS compiler's deletion).
//
// TS is a diagnostic reference only, never a gate here — the TS compiler
// is disposable, and on any divergence we keep the cleaner Vader output.
// The allowlist grows tranche by tranche (see the plan's §9). T0 covers
// the constant-return path only.

import { test, expect } from "bun:test";
import { join, resolve } from "node:path";
import { tmpdir } from "node:os";
import { writeFileSync } from "node:fs";

import { LONG_BUILD, runCli } from "./cli-bin.ts";
import { VM_ERROR_PREFIXES, formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

const RUNTIME_ROOT = resolve(import.meta.dir, "../runtime/c");
const EXE_EXT = process.platform === "win32" ? ".exe" : "";

const CC_AVAILABLE = await (async () => {
  try {
    const proc = Bun.spawn(["cc", "--version"], { stdout: "ignore", stderr: "ignore" });
    return (await proc.exited) === 0;
  } catch {
    return false;
  }
})();

// Snippets whose Vader-emitted C is at parity. Grows tranche by tranche
// (see the plan's §9). T0 : the constant-return path.
const C_PARITY = new Set<string>([
  "return_42",
  // T1 scalar core : params + local.get + i32 binop + non-lit return.
  // No main (library) → the compile/run oracle skips the run, the
  // snapshot + cc-compile oracles still apply.
  "fn_decl",
  // T1b : local.set / local.tee, the prelude (local + temp decls),
  // operand materialisation, i32 add/sub/mul.
  "scalar_locals",
  // T1c : the rest of the i32 expr family — cmp (eq/ne/lt/le/gt/ge),
  // bitwise (and/or/xor), shifts (shl/shr), unary (neg/bitnot). Temp-free
  // (expression-bodied single-op fns) so byte-parity holds vs TS.
  "scalar_arith",
  // T1d : i64 / u32 / u64 / f64 families, eager integer + f64 div/rem,
  // bool.not, i32<->i64 / i32<->char conversions.
  "scalar_wide",
  // T2 : structured control — block / loop / if / else / end / br
  // (jump_table-resolved goto labels, dynamic indent). Counted loop +
  // if/else body ; result via main's exit code (142).
  "scalar_control",
  // T3a : direct `call` — own fns by index, scalar args + result
  // threaded through a fresh temp. Result via exit code (49).
  "scalar_call",
  // T3b : `call.import` + import shims — println reaches the runtime via
  // vader_import_N (write + Display.to_string). stdout-observed.
  "io_println",
  // T4a : stack structs — struct.new_stack / local.field / ref.cast /
  // struct.set_stack (body rep, no GC frame). Exit code 17.
  "struct_point",
  // T4b : heap structs (struct.new) + the GC-frame prologue (gc_roots /
  // gc_frame / gc_top, ref-slot zero-init, framed return). Exit code 7.
  "struct_heap",
  // T5 : arrays — array.new / set / push / get / len (boxed elements via
  // box_expr; heap → reuses the GC frame). Exit code 153.
  "array_ops",
  // T6 : strings + builder — string.concat / string.eq (atom ==) + the
  // builder family (interpolation). stdout "hello, world!".
  "string_ops",
  // T3c : closures + dispatch.
  //   fn_value_local       — fn.ref → vader_fn_tramp/static + call.indirect.
  //   closure_callback     — make_closure → vader_fn_lift + fn-value param.
  //   trait_virtual_dispatch — virtual.call → per-key dispatcher + the slot
  //                          tables (existential `Error` receiver).
  "fn_value_local",
  "closure_callback",
  "trait_virtual_dispatch",
  // T7 : misc ops. type_check (`x is T` → tag-compare / trait disjunction) is
  // the validatable one — a chain of divergent `is`-guards. type.const /
  // size_of.type / defer.push / defer.pop_exec handlers are also ported but
  // unreachable via a clean snippet today (the former blocked by the pending
  // arg / local.set coercion `todo`s, defer by the upstream Vader bytecode
  // dropping defer ops — a self-host gap, not a C-emit one).
  "chained_divergent_narrow",
  // T12a : boundary ValType coercion (call-arg / return / local.set /
  // struct-field) via `coerce_expr` — boxes a primitive into an erased
  // `ref`/`any` slot (and the inverse), the common monomorphised-generic
  // shape (`fn<T>` params lowered to `ref`). The heavy erasure-boundary
  // reshape (array-kind / heap-struct) + B1 stay deferred — no reachable
  // snippet needs them yet.
  "trait_dispatch_param",
  "intrinsic_fields",
  "intrinsic_type_args",
  "comptime_type_value",
  // Dead trailing return : an exhaustive-returning match leaves the lowerer's
  // implicit fn-terminator return unreachable with an empty operand stack —
  // `emit_return` traps it (`vader_unreachable`) instead of underflowing. All
  // three exercise a union match where every arm returns.
  "array_of_union",
  "alias_union_in_array",
  "narrow_imported_map",
  // §9 C-emit audit (the walker now emits C for the whole compiler) :
  //   for_loop      — `break` out of an infinite `for {}` (a Loop) + `continue`
  //                   → generalized branch resolution (break past a Loop/If end,
  //                   not just a Block). Would hit the unresolved-target todo
  //                   before the fix. (Library snippet : compile oracle only.)
  //   if_null_narrow — break / continue in divergent null-narrow branches.
  "for_loop",
  "if_null_narrow",
  // Erasure-boundary tuple field read : `for [k, v] in zip(...)` / `enumerate()`
  // yield erased-sibling tuples (all-`Any` from zip, `[usize, Any]` from
  // enumerate) that the carrying array erases to `ref` ; the concrete field
  // read must tag-dispatch + box/unbox (`c_emit/walker.vader::push_struct_field`).
  // The native-run oracle here is the regression guard — the snapshot/VM
  // dimensions stay green even when the native field read is wrong.
  "iter_zip_chain",
  // Captured parameters : a `defer` / lambda body that reads or mutates one of
  // its enclosing fn's PARAMS promotes that param to a heap cell at fn entry
  // (`promote_captured_params`). Exercises cell-new over an ABI param +
  // make_closure with a non-empty env + the lifted body's `struct.get` cell
  // read in the C emitter. The run oracle (matches vm.snapshot) is the guard.
  "defer_capture_param",
  // Captured loop bindings : a for-in element/range loop var and a lambda's own
  // param captured by a nested lambda promote to per-iteration / per-call cells
  // (`lower_cell_init` at the for-in binding sites + `promote_captured_params`
  // in the lifted lambda body). Closures stashed in the loop and run after it
  // must each see their own iteration's value — the run oracle is the guard.
  "capture_loop_var",
  // Generators (`@generator` + `yield`) — the state-machine lowering emits a
  // synthesized `g$State` struct + an `Iterator::next` state machine consumed by
  // for-in; the native run validates the whole desugar end-to-end.
  "generator_basic",       // single loop, one yield
  "generator_nested",      // nested loops (resume mid-inner-loop)
  "generator_filter",      // yield inside an `if`
  "generator_break",       // break + continue across a yield
  "generator_struct_elem", // struct element type, flattened
  "generator_escapes",     // stored-then-consumed → boxed state machine (not inlined)
  // Stream fusion (Couche 1): `arr.iter().map(f).filter(p)` under a `for`
  // fuses to a flat index loop — no iterator structs. Native run validates the
  // fused loop produces the same output as the boxed tower would.
  "fuse_array_map_filter",
  // Couche 2: take/skip fuse via a pre-loop counter + break/continue guard.
  "fuse_take_skip",
  // Couche 4: a directly-consumed @generator inlines its yield-loop as the
  // fused body — native run validates it matches the boxed state machine.
  "fuse_generator_direct",
  // Couche 4: a GENERIC @generator inlines too — instance subst reconstructed
  // at the fusion site (gen_map / gen_filter, T -> U).
  "fuse_generator_generic",
  // Couche 4: a generator COMBINATOR (first param = source iterator) fuses as a
  // chain layer — single UFCS combinator + nested direct-call chain.
  "fuse_generator_chain",
  // `@extern` forwarding shim — string args marshalled atom → `const char*`
  // (`c_emit/host.vader::user_extern_shim`). The shim only exists in native
  // C output (the VM has no user-extern registry), so this run is the ONLY
  // guard on the marshalling ABI: the 2026-05 atom migration broke it for
  // ~6 weeks without a test noticing. Links the snippet's `helper.c`.
  "extern_native_basic",
  // Comptime-folded non-finite f64 constants (`inf` / `-inf` / `nan`). The
  // native run is the guard: the literal emitter must render them as compiler
  // builtins, not the bare words `inf` / `nan` (invalid C). Regression B3.
  "f64_non_finite",
  // `@async` + `await` — the coroutine state-machine lowering (`lower_async`,
  // Model A self-drive) synthesizes an `__asyncstate` frame + an `Async::resume`
  // machine. The native run is the seed-critical guard on the erased→concrete
  // cast at each drive site (`cast(child.resume(), T')`) — it must round-trip a
  // boxed value back to its concrete type in emitted C, not just on the VM.
  "async_basic",       // one await, value return
  "async_sequential",  // two awaits of different types + resume-after-done
  "async_conditional", // await hoisted into a conditional branch
  "async_countdown",   // genuine suspension: re-entrant drive of a parking child
  "async_fallible",    // fallible result `T | Error`, narrowed at match
  "async_trailing",    // trailing (implicit-return) await + two awaits per expr
  "async_void",        // void async: `null` done-marker, nested void await
  "async_main",        // implicit @async main: inlined run-driver, exit code
  "async_sleep",       // real suspension via sleep: park scheduler + timer heap
]);

const scenarios = listSnippets("tests/snippets").filter((s) => C_PARITY.has(s.name));

test("c-emit: allowlist resolves to real snippets", () => {
  expect(scenarios.length).toBe(C_PARITY.size);
});

for (const s of scenarios) {
  // Oracle 1 — regression vs the Vader-generated golden.
  test.concurrent(`c-emit-snapshot: ${s.name}`, async () => {
    const dump = await runCli(["dump", "--stage=c", s.mainPath]);
    const cmp = snapshotEquals(s.dir, "c.snapshot", dump.stdout);
    if (!cmp.ok) {
      throw new Error(
        `c.snapshot mismatch: ${s.name}\n  snap: ${cmp.snapPath}\n` +
        `  Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected ?? "", dump.stdout),
      );
    }
  }, { timeout: LONG_BUILD });

  // Oracle 2 — the emitted C compiles + runs, matching vm.snapshot.
  test.concurrent(`c-emit-run: ${s.name}`, async () => {
    if (!CC_AVAILABLE) return;
    const dump = await runCli(["dump", "--stage=c", s.mainPath]);
    const cFile = join(tmpdir(), `vader-cemit-${s.name}.c`);
    const binFile = join(tmpdir(), `vader-cemit-${s.name}${EXE_EXT}`);
    writeFileSync(cFile, dump.stdout);

    const build = Bun.spawn([
      "cc", "-std=c11", "-O0", "-I", RUNTIME_ROOT,
      cFile, join(RUNTIME_ROOT, "vader_runtime.c"),
      // `@extern` snippets carry their foreign symbols in helper `.c`
      // files next to `_main.vader` — compile them into the binary.
      ...s.helperCFiles,
      "-o", binFile, "-lm",
    ], { stderr: "pipe", stdout: "pipe" });
    const buildErr = await new Response(build.stderr).text();
    if ((await build.exited) !== 0) {
      throw new Error(`c-emit-run: cc failed for ${s.name}\n${buildErr}`);
    }

    const runProc = Bun.spawn([binFile], { cwd: process.cwd(), stdout: "pipe", stderr: "pipe" });
    const killTimer = setTimeout(() => runProc.kill("SIGKILL"), 60_000);
    let stdout: string, stderr: string, runExit: number;
    try {
      stdout = await new Response(runProc.stdout).text();
      stderr = await new Response(runProc.stderr).text();
      runExit = await runProc.exited;
    } finally {
      clearTimeout(killTimer);
    }

    let expected: string;
    try {
      expected = await Bun.file(join(s.dir, "vm.snapshot")).text();
    } catch {
      return;
    }
    if (VM_ERROR_PREFIXES.some((p) => expected.startsWith(p))) return;
    if (expected.includes("# runtime error\n")) return;

    const actual = formatRun(stdout, stderr, runExit);
    if (actual !== expected) {
      throw new Error(
        `c-emit run mismatch: ${s.name}\n  bin: ${binFile}\n\n` +
        snapshotDiff("vm.snapshot", expected, actual),
      );
    }
  }, { timeout: LONG_BUILD });
}
