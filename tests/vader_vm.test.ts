// VM parity — Vader CLI's bytecode interpreter vs the TS VM's `vm.snapshot`.
//
// Each snippet that produces a `bytecode.snapshot.virt` (the `.virt` text-IR
// dump emitted by the bytecode phase in `tests/snapshot.test.ts`) is fed
// directly to the Vader CLI (`./build/vader run`). The captured stdout +
// stderr + exit are formatted via `formatRun` and compared to the same
// `vm.snapshot` the TS VM is checked against — both VMs share one oracle.
//
// Vader-VM coverage grows sprint by sprint (docs/SELFHOST_VM.md). The VM
// implements `bool.*`, `null.const`, `virtual.call`, `type_check` (verified
// in `vader/vm/exec.vader`) ; snippets still trap or diverge for narrower
// reasons — host imports beyond `std_io$write` (no host-fn registry),
// panic-unwind defers, and `virtual.call` whose receiver is an *erased*
// type (`ref _`) for which the vtable lookup finds no impl (the mode-a
// erasure gap — fixed by monomorphising/devirtualising in the Vader emit,
// tracked in the §9 audit). Those are listed in `KNOWN_DIVERGENT` and
// skipped — entries should be removed as the gaps close.

import { test } from "bun:test";
import { existsSync, readFileSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

// Snippets where Vader's self-emitted bytecode INTENTIONALLY diverges from
// the TS snapshot (mode-a GATE A : concrete devirt instead of erased
// `virtual.call`) AND is more correct — TS's erased form returns the wrong
// result on the VM. For these we don't run the committed (TS) `.virt` ;
// instead we dump Vader's OWN bytecode and run that against `vm.snapshot`.
// This is the real self-host oracle (Vader compiles → Vader VM runs →
// correct output) and the validation that will let TS be removed.
const VADER_SELF_EMIT = new Set<string>([
  "trait_dispatch_struct",
  // GATE B : `println<string>` keeps `msg` concrete (GATE A), `msg.to_string()`
  // resolves to the intrinsic `string` Display impl surfaced as an import, and
  // the Vader VM dispatches it via `host.vader`. Vader self-emit prints
  // "Hello, World!" where the erased TS path can't.
  "hello",
  // Same GATE A+B path (concrete Display dispatch on primitives / interp) —
  // Vader self-emit runs these to their vm.snapshot oracle where the erased
  // TS bytecode diverges. Each verified: dump-with-Vader → run → matches.
  "squares",
  "vm_hello",
  "interpolation",
  "vm_interp_basic",
  "vm_arith",
  "for_range",
  "loop",
  "vm_interp_mixed",
  "vm_interp_loop",
  "enum_typed",
  "enum_match",
  "match_union",
  "if_field_narrow",
  "vm_struct_nested",
  "vm_array_mutate",
  "vm_for",
  "vm_if",
  "if_is_narrow",
  "match_literal_patterns",
  "match_partial",
  "if_null_narrow",
  "nested_field_narrow",
  "match_wildcard_narrow",
  "match_field_narrow",
  "byte_literal",
  "struct_defaults",
  "op_not_is",
  "match_is_as_binding",
  "match_struct_pattern_binding",
  "op_overload_arith",
  "op_overload_compound",
  "primitive_impl",
  "self_ref_struct",
  "struct_spread",
  "intrinsic_field_access",
  "comptime_const",
  // mode-b : `for x in it` over a concrete (generic) struct iterator now
  // resolves `it.next()` to the impl-member instance mangle.
  "custom_iter_generic",
  "custom_iter",
  "array_iter",
  // Iterator default methods (`count` / `last` / `is_empty`) now self-host :
  // the generic-impl default bodies + the bound primitive `Comparable` / `Step`
  // impls are materialised, the vtable carries the primitive rows, and the
  // cloned bodies get deterministic spans so resolve↔lower agree.
  "iter_defaults",
  // Promoted 2026-05-30 : Vader self-emitted bytecode runs to the same
  // vm.snapshot oracle as the TS path (verified by full-suite run). Bytecode
  // may still diverge from TS at the .virt level (tracked separately in
  // parity's BYTECODE_DIVERGENT_SNIPPETS) — this only asserts the self-host
  // VM produces correct OUTPUT.
  // `x in arr` / `b in s.bytes()` membership (std/core `T[] implements Contains`
  // blanket). Self-emit ONLY : the TS in-process bytecode emit for this snippet
  // is non-deterministic under the concurrent multi-file runner (the disposable
  // erasure-dedupe/DCE layer — a harvested `Yield<char>` from std/string's
  // char-range helpers survives-concrete-vs-erases depending on test-file
  // interleaving ; ruled out type-intern caches + synth counters via verified
  // per-compile resets, 2026-06-02). build/vader emits it deterministically, so
  // the bytecode stage is excluded in its `_config.json` and the feature is
  // validated here against the vm.snapshot oracle.
  "array_contains",
  // `MutableSet<i32>` end-to-end self-host : exercises the erased generic-struct
  // impl-member materialisation (`MutableMap<Any, bool>.Contains.contains`,
  // reached from the deduped erased `add` body) AND the integer-primitive
  // `Equals` host dispatch the erased map-key lookup needs. Guards the three
  // fixes that landed it (DCE walks verbatim survivors / erased impl-member
  // materialisation / VM integer `Equals`) — the suite's only coverage of the
  // Vader emitter on a map/set program.
  "mutable_set",
  // A lambda lifted inside a GENERIC fn body : the instance `run_id__i32` is
  // monomorphised AFTER the per-module lowering walk, so its `__lambda_*` decl
  // is drained into the module by the post-module synth drain. Guards the
  // make-closure GATE-B1 fix (`drain_synth_window`) — without it the lifted
  // closure has no reserved fn index and Vader emit panics.
  "closure_in_generic_fn",
  // JSON parse + stringify : `std/json::write_object` (a harvested non-generic
  // stdlib fn) calls the generic `MutableMap.len`, registering that instance
  // DURING the stdlib harvest — after the old single generic pass. Guards the
  // generic↔stdlib joint-fixpoint fix (drain_generic_fn_instances inside the
  // fixpoint + deferred flush) ; without it `len__string__JsonValue` is
  // stranded and Vader emit panics with an unresolved callee.
  "json_basics",
  // `str.trim(...)` : a namespaced call to a NON-generic stdlib fn. Guards
  // resolve_namespace_member — the namespace form must resolve the member to
  // its real symbol (+ harvest it), not a bare id=0 placeholder, else emit
  // can't reserve the callee. (Generic namespaced calls like `io.println` are
  // a separate follow-up — they need the generic-instance harvest the direct
  // path does.)
  "namespace_call_nongeneric",
  // `if x is T as a { … a … }` narrowing-BINDING resolution on the Vader
  // self-emit path. The lowerer must reuse the resolver's binding symbol (not
  // mint a fresh one) so `a` references resolve — without it every `a` use is
  // an unresolved ident → the then-block body drops. `if_is_as_bind` covers a
  // bare-ident scrutinee ; `is_as_field_narrow` covers a FIELD-CHAIN scrutinee
  // (`w.payload is Inner as p`), which also needs the typechecker to record the
  // binding's type for a non-ident scrutinee. (The suite otherwise runs
  // TS-emitted bytecode for these, never exercising the Vader emitter.)
  "if_is_as_bind",
  "is_as_field_narrow",
  // 64-bit integer literals whose magnitude exceeds 2^31 (e.g. `i64 =
  // -2_147_483_648`). The CFG `emit_const_instr` always emitted `i32.const`,
  // truncating any value >= 2^31 ; the following `i64.neg` then flipped the
  // sign wrong. This is the compiler's own `repr_range("i32").min`, mis-emitted
  // as `+2147483648`, which broke the enum backing-range (T3030) check.
  "i64_const_width",
  // `if !(x.field is null) { … x.field.<sub> … }` — narrowing a FIELD through a
  // NEGATED `is null` then-block guard. The Not case of the then-block detector
  // swapped then/else but dropped `field_key`, so `x.field` kept `T | null` and
  // `x.field.<sub>` dropped. This is the compiler's own `build_if`'s
  // `if e.else_block !is null { … e.else_block.span … }` — every if-with-else
  // (for-loops, matches → if-chains) lost its else handling.
  "field_not_null_narrow",
  // Building a foreign struct while OMITTING a field whose default references a
  // const in the struct's OWNING module (`id: usize = DEFAULT_ID`). The default's
  // AST lives in that module, so lowering it with the construction site's context
  // left the const unresolved → the struct literal dropped. This is the compiler's
  // own `simple_placeholder` building `SimpleBinding` (default `UNASSIGNED_NODE_ID`
  // from vader/parser), which broke nested tuple destructuring.
  "struct_default_cross_module",
  // A CHAIN of divergent `is`-guards ending in `!(x is T) { return }`, then a
  // field access on the narrowed `x`. The `!(x is T)` complement must compose
  // from the already-narrowed type, not re-widen to the declared union — else a
  // chain leaves `x` as `T | A | B` and `x.<T-field>` drops. This is the
  // compiler's own `infer_call` (`callee_ty.params` after its TypeMetaType /
  // UnresolvedType / !FnType guards), which dropped every typed method call.
  "chained_divergent_narrow",
  // `if x.field is null { return }` / `x.field is T` — narrowing a FIELD chain
  // via the `is` operator (the detectors used to narrow fields only for
  // `== null`). A field read after a divergent `is null` guard kept its
  // `T | null` type and dropped (the compiler's own `convert_function`).
  "field_is_narrow",
  // A COMPUTED `u64` (stored `I64Val`, not a small `I32Val` literal) returned
  // through a union and matched `is u64`. The VM's `primitive_matches` only
  // accepted `I32Val` for integer aliases, so the match fell through its
  // no-match arm and dropped the value — exactly how the self-hosted lexer's
  // `parse_uint_in_base` result vanished, dropping every computed int literal.
  "union_computed_u64",
  // `alias.Enum.Variant` — namespace-qualified enum-variant access in value
  // position (`P.Color.Green`). The lowerer's `try_lower_enum_field` must fold
  // it to the variant index even though the target (`P.Color`) is a namespace
  // FieldExpr, not a bare enum ident — else `P` is an unresolved ident and the
  // expression drops. (Mirrors the compiler's own `AST.BinaryOp.Is`.)
  "namespace_enum_variant",
  // `alias.CONST` — a const reached through a namespace import (`C.MAX_RETRIES`),
  // in value position and inside a struct literal. The lowerer must fold it to
  // the const's value, not leave the `C` ImportBinding ident unresolved — else
  // the enclosing struct literal drops. (Mirrors the compiler's own
  // `AST.UNASSIGNED_NODE_ID` in every substitute_* struct literal.)
  "namespace_const",
  // A module-level `const T[]` of ≥4 struct literals (mirror of the compiler's
  // own `INTRINSICS`) referenced in a for-loop. Guards the `inline_consts`
  // fn-wrap path : the const lowers to a synthetic `__const_SPECS` accessor fn
  // (reusing the const's symbol id) that `build_ident` resolves to a `call`.
  // Without it a non-scalar const ref hits `build_ident`'s unreachable stub.
  // (Bytecode diverges from TS only in interning order — see parity's
  // BYTECODE_DIVERGENT_SNIPPETS ; this asserts the self-host VM output.)
  "const_fn_wrap",
  // `Target(value)` / implicit `Into` coercion (call arg, typed let, return,
  // struct field). The coercion call's callee was a bare `into` (id=0) that
  // resolved to neither symbol id nor mangle → emit panicked. The lowerer now
  // resolves it to the impl member's materialised mangle (`<mod>$<Src>$Into$
  // into<_N>`), reusing `impl_member_overload_suffix` so the overload `_N`
  // disambiguates `Into<i32>` vs `Into<string>` exactly as the materialiser
  // numbered them. `coerce_into_overload` adds free-fn overload resolution on
  // top. (Vader self-emit diverges from the TS `.virt` in interning order +
  // devirt `$vt` naming, so we assert the run-output oracle, not byte-parity ;
  // TS-vs-snapshot parity is deterministic and stays in the normal path.)
  "coerce_into_basic", "coerce_into_explicit", "coerce_into_overload",
  "_diag_const_string", "alias_union_in_array", "array_view_aliasing",
  "for_range_sugar", "b1_fn_boundary", "closure_pattern_binding", "comptime_type_value",
  "const_array_basic", "contains_op", "decorator_deprecated",
  "enum_trait_self_return", "expr_bodied_fn", "expr_bodied_recursive_typed",
  "file_decorator", "gc_array_survive", "gc_chain_survive", "gc_multi_collect",
  "generic_helper_chain", "generic_struct", "generic_type_alias",
  "if_is_field_after_narrow", "if_without_else_stmt", "impl_bounded_typeparam",
  "implicit_dot_variant", "io_roundtrip", "is_union_alias_warn", "lambda_no_fn",
  "match_struct_pattern_in_union", "multiline_string", "op_overload_eq_ord",
  "parse_int_match", "std_math", "std_string_builder", "struct_lit_field_order",
  "struct_name_collision", "trait_virtual_dispatch", "transitive_mono",
  "try_op", "ufcs_overload", "ufcs_union_receiver", "union_common_field",
]);

// Snippets that the self-host VM can't yet run end-to-end. New entries
// should carry a one-line explanation + a link to the issue / commit
// blocking them.
//
// To regenerate the list : run this test with all entries removed,
// `bun test tests/vader_vm.test.ts`, and copy the failing names back.
const KNOWN_DIVERGENT = new Set<string>([
  // A8 single-track defer — panic-unwind not yet wired in the Vader self-
  // host VM ; `defer.push` / `defer.pop_exec` (normal exits) work but a
  // trapped op exits via the regular `Trap` path without draining the
  // frame's defer-stack. Tracked alongside the C-emit setjmp/longjmp
  // chantier in TODO §3.8. `defer_in_lambda` exercises a panic inside
  // a lambda ; same root cause.
  "defer_on_panic",
  "defer_in_lambda",
  // `for x in <string>` → codepoint iter requires the `Iterator(char)`
  // impl on `string` to lower without B5001. The arr/map/set legs of
  // this snippet run, but the `chars=…` line is never emitted because
  // the chars leg traps. Tracked alongside TODO §1.5b iterators.
  "for_in_into_iter",
]);

const scenarios = listSnippets("tests/snippets");

for (const s of scenarios) {
  if (KNOWN_DIVERGENT.has(s.name)) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  // Self-emit snippets : compile with Vader, run Vader's OWN bytecode (not
  // the committed TS `.virt`), and compare to the same `vm.snapshot` oracle.
  if (VADER_SELF_EMIT.has(s.name)) {
    test.concurrent(`vader-vm-self: ${s.name}`, async () => {
      const dump = await runCli(["dump", "--stage=bytecode", s.mainPath]);
      const tmp = join(tmpdir(), `vader-self-${s.name}.virt`);
      writeFileSync(tmp, dump.stdout);
      const { stdout, stderr, exit } = await runCli(["run", tmp]);
      const actual = formatRun(stdout, stderr, exit);
      const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
      if (!cmp.ok) {
        throw new Error(
          `vader-vm-self mismatch: ${s.name}\n` +
          `  snap: ${cmp.snapPath}\n\n` +
          snapshotDiff(cmp.snapPath, cmp.expected, actual),
        );
      }
    }, { timeout: MEDIUM_BUILD });
    continue;
  }
  // Native-only snippets — `@extern` user imports trap in the Vader VM
  // for the same reason they trap in the TS VM (no host-fn registry).
  if (s.helperCFiles.length > 0) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  const virtPath = `${s.dir}/bytecode.snapshot.virt`;
  if (!existsSync(virtPath)) {
    // No bytecode emitted — typically compile-error tests. Skip.
    continue;
  }
  const vmSnapPath = `${s.dir}/vm.snapshot`;
  if (existsSync(vmSnapPath)) {
    const vmSnap = readFileSync(vmSnapPath, "utf8");
    // Compile-error tests : bytecode phase still emits a `.virt`
    // (typecheck failures don't halt the pipeline before bytecode),
    // but the snippet is a diagnostic test — the TS VM never runs it.
    // Skip cleanly rather than report a spurious parity failure.
    if (vmSnap.startsWith("# compile errors")
        || vmSnap.startsWith("# pipeline error")
        || vmSnap.startsWith("# internal error")
        || vmSnap.startsWith("# no main function")) {
      continue;
    }
  }
  test.concurrent(`vader-vm: ${s.name}`, async () => {
    const { stdout, stderr, exit } = await runCli(["run", virtPath]);
    const actual = formatRun(stdout, stderr, exit);
    const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `vader-vm parity mismatch: ${s.name}\n` +
        `  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: MEDIUM_BUILD });
}
