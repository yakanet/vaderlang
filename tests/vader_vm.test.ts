// VM parity: every snippet's `vm.snapshot` is checked against the Vader VM.
//
// - A run snapshot is compared with `./build/vader run` on the snippet's
//   `bytecode.snapshot.virt`, or on bytecode built from source when the snippet
//   has none or is listed in `VADER_SELF_EMIT`. The output goes through
//   `formatRun`, as the native run in `parity-cemit.test.ts` does.
// - A `# compile errors` snapshot is compared with the errors `vader check`
//   reports, and the check must fail.
//
// A snippet whose VM run is known to be wrong is listed in `KNOWN_DIVERGENT`
// with its reason; one with a `helper.c` is skipped, its foreign symbols living
// only in a native binary.

import { expect, test } from "bun:test";
import { existsSync, readFileSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { COMPILE_ERRORS, type Scenario, expectsCompileErrors, formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";
import { MEDIUM_BUILD, runCli } from "./cli-bin.ts";

/// `bytecode.snapshot.virt` is pinned to `SNAPSHOT_TARGET`, but this test
/// EXECUTES it. On a host that is not that target the pinned bytecode carries
/// another platform's `@target` bodies: Windows ran the LINUX `temp_dir()`,
/// looked up `TMPDIR` -- a variable Windows does not set, it uses `TMP`/`TEMP`
/// -- and fell back to `"/tmp"`, which does not exist there, so
/// `ppm_roundtrip` reported `open failed`. macOS never noticed because
/// `@target(.Linux, .Darwin)` share one body.
///
/// A snapshot's identity is its target; an execution's identity is its host.
/// The two cannot be the same artefact, so off-target hosts re-emit for
/// themselves and only the pinned host reuses the committed file.
const HOST_IS_SNAPSHOT_TARGET = process.platform === "linux" && process.arch === "x64";

/// The `.virt` to run: the committed one when the host IS the pinned target,
/// a host-targeted re-emission otherwise.
async function virtForHost(name: string, mainPath: string, pinned: string): Promise<string> {
  if (HOST_IS_SNAPSHOT_TARGET) {
    return pinned;
  }
  const dumped = await runCli(["dump", "--stage=bytecode", mainPath]);
  if (dumped.exit !== 0) {
    throw new Error(`vader-vm: could not emit host bytecode for ${name}\n${dumped.stderr}`);
  }
  const out = join(tmpdir(), `vader-vm-host-${name}.virt`);
  writeFileSync(out, dumped.stdout);
  return out;
}

/// Snippets whose `@extern` targets a symbol no Windows DLL exports, so the VM
/// cannot resolve it even though the native build links it statically.
const VM_PARITY_UNAVAILABLE_WIN32 = new Set(["c_struct_prefix_mirror"]);

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
  "interpolation",
  "for_range",
  "loop",
  "enum_typed",
  "enum_match",
  "if_field_narrow",
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
  "op_overload_arith",
  "op_overload_compound",
  "self_ref_struct",
  "struct_spread",
  "intrinsic_field_access",
  "comptime_const",
  // mode-b : `for x in it` over a concrete (generic) struct iterator now
  // resolves `it.next()` to the impl-member instance mangle.
  "custom_iter_generic",
  "custom_iter",
  "array_iter",
  // `count` / `last` / `is_empty` over a range and a user iterator struct.
  "iterator_terminals",
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
  // const in the struct's OWNING module (`id: i64 = DEFAULT_ID`). The default's
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
  // `[T]` → `Iterator<T>` value-slot coercion (call arg, typed let, return).
  // The blanket `T[] implements Into<Iterator<T>>` member now materialises via
  // `surface_array_blanket_members` (the generalised array-`Contains` pass), and
  // the `ArrayIterator<element>` instance is registered so its `Iterator` impl
  // materialises into the vtable. This is the FIRST self-emit exercise of a
  // generic-impl trait object dispatched VIRTUALLY (for-in always inlines `next`)
  // — it surfaced two latent vtable bugs, both fixed: the impl-member mangle's
  // `__<args>` suffix leaked into the vtable method name (so `Iterator.next__i32`
  // never matched the `vcall Iterator.next`), and the materialised member's synth
  // id-0 symbol needed a mangle fallback to resolve its fn index.
  "iter_coerce_array", "trait_box_range_iter",
  "_diag_const_cross_module", "alias_union_in_array", "array_view_aliasing",
  "for_range_sugar", "b1_fn_boundary", "comptime_type_value",
  "const_array_basic", "contains_op", "decorator_deprecated",
  "enum_trait_self_return", "expr_bodied_fn", "expr_bodied_recursive_typed",
  "file_decorator", "gc_array_survive", "gc_chain_survive", "gc_multi_collect",
  "generic_helper_chain", "generic_struct", "generic_type_alias",
  "if_is_field_after_narrow", "if_without_else_stmt", "implicit_dot_variant",
  "io_roundtrip", "is_union_runtime", "lambda_no_fn",
  "match_struct_pattern_in_union", "multiline_string", "op_overload_eq_ord",
  "parse_int_match", "std_math", "std_string_builder", "trait_virtual_dispatch",
  "transitive_mono", "ufcs_union_receiver", "union_common_field",
  // narrow_imported_map : imported-body divergent-guard narrowing (the
  // B0-in-VM bootstrap frontier that made B0 == B1). Self-emit ONLY — only the
  // Vader emitter, not the committed TS `.virt`, exercises the stmt.vader fix.
  "narrow_imported_map",
]);

// Snippets that the self-host VM can't yet run end-to-end. New entries
// should carry a one-line explanation + a link to the issue / commit
// blocking them.
//
// To regenerate the list : run this test with all entries removed,
// `bun test tests/vader_vm.test.ts`, and copy the failing names back.
const KNOWN_DIVERGENT = new Set<string>([
]);

// The error lines `vader check` reports, as a `vm.snapshot` lists them:
// `[CODE] message: detail`, in the order the compiler emits them.
function compileErrorLines(output: string): string[] {
  return output.split("\n").flatMap((line) => {
    const m = line.match(/^\[[^\]]*\] error\[([A-Z][0-9]+)\] (.*)$/);
    return m ? [`[${m[1]}] ${m[2]}`] : [];
  });
}

// Build `s` from source and run Vader's own bytecode, against `vm.snapshot`.
// `build --emit=bytecode-text`, NOT `dump --stage=bytecode`: this oracle needs
// the whole linked image, every function it calls included. The dump is a VIEW
// of one module and is free to narrow; the build is what runs.
function testFromSource(s: Scenario): void {
  test.concurrent(`vader-vm-self: ${s.name}`, async () => {
    const tmp = join(tmpdir(), `vader-self-${s.name}.virt`);
    const built = await runCli(["build", "--emit=bytecode-text", "-o", tmp, s.mainPath]);
    if (built.exit !== 0) throw new Error(`bytecode-text emit failed: ${built.stderr}`);
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
}

const scenarios = listSnippets("tests/snippets");

// Every list here selects snippets by name and skips a name that matches none,
// so a deleted or renamed snippet would leave a dangling entry behind in silence.
test("vader-vm: name lists resolve to real snippets", () => {
  const known = new Set(scenarios.map((s) => s.name));
  const listed = [
    ...VM_PARITY_UNAVAILABLE_WIN32,
    ...VADER_SELF_EMIT,
    ...KNOWN_DIVERGENT,
    ...ANNOTATED_ROUNDTRIP,
  ];
  expect(listed.filter((name) => !known.has(name))).toEqual([]);
});

for (const s of scenarios) {
  if (KNOWN_DIVERGENT.has(s.name)) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  // Self-emit snippets : compile with Vader, run Vader's OWN bytecode (not
  // the committed TS `.virt`), and compare to the same `vm.snapshot` oracle.
  if (VADER_SELF_EMIT.has(s.name)) {
    testFromSource(s);
    continue;
  }
  // A snippet that must not compile: its `vm.snapshot` lists the errors, and the
  // compiler has to report exactly those and fail. A snippet that compiles, or
  // whose errors change, fails here.
  if (expectsCompileErrors(s.dir)) {
    test.concurrent(`vader-vm-compile-errors: ${s.name}`, async () => {
      const { stdout, stderr, exit } = await runCli(["check", s.mainPath]);
      const lines = compileErrorLines(`${stdout}\n${stderr}`);
      // Checked before the comparison, so `test:update` cannot record an empty
      // list and keep a snippet that now compiles out of every run.
      if (lines.length === 0 || exit !== 1) {
        throw new Error(
          `${s.name}: \`vader check\` reported ${lines.length} error(s) and exited ${exit}; ` +
          `a snippet that compiles records its run in vm.snapshot instead\n${stdout}${stderr}`,
        );
      }
      const actual = `${COMPILE_ERRORS}\n${lines.join("\n")}\n`;
      const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
      if (!cmp.ok) {
        throw new Error(
          `vader-vm compile errors mismatch: ${s.name}\n` +
          `  snap: ${cmp.snapPath}\n\n` +
          snapshotDiff(cmp.snapPath, cmp.expected, actual),
        );
      }
    }, { timeout: MEDIUM_BUILD });
    continue;
  }
  // A snippet with a `helper.c` defines its OWN foreign symbols, which live in
  // the compiled binary and nowhere the interpreter can reach: it resolves an
  // `@extern` by `dlsym` against the RUNNING PROCESS, so it finds libc and the
  // Vader runtime and not a symbol linked into some other executable.
  //
  // The reason used to be that `@extern` traps on the VM outright, for want of a
  // host registry. This branch gave it one — `dispatch_extern` — so a snippet
  // whose externs are libc (`c_pointer_as_word`, `c_struct_prefix_mirror`) runs
  // on both backends. Only the ones that supply their own C are skipped, and
  // that is now the whole of the reason.
  if (s.helperCFiles.length > 0) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  // The VM resolves an `@extern` through `dlsym` on the C library, so it can
  // only reach what that library EXPORTS. MinGW keeps the POSIX shims in
  // libmingwex.a, a static archive: the native build links `gettimeofday` in
  // and runs, while the VM gets "symbol not found". That is a property of the
  // platform's libc, not of the snippet — so the parity check does not apply.
  if (process.platform === "win32" && VM_PARITY_UNAVAILABLE_WIN32.has(s.name)) {
    test.skip(`vader-vm: ${s.name}`, () => {});
    continue;
  }
  const virtPath = `${s.dir}/bytecode.snapshot.virt`;
  if (!existsSync(virtPath)) {
    // Its stage snapshots stop before bytecode (`_config.json`). A run oracle
    // is still checked, from source; without one, the stage snapshots are the
    // whole test.
    if (existsSync(`${s.dir}/vm.snapshot`)) {
      testFromSource(s);
    }
    continue;
  }
  test.concurrent(`vader-vm: ${s.name}`, async () => {
    const runVirt = await virtForHost(s.name, s.mainPath, virtPath);
    const { stdout, stderr, exit } = await runCli(["run", runVirt]);
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

// Annotated-dump round-trip. `dump --stage=bytecode --annotate` glues a
// trailing `; comment` onto every index-bearing op (resolving the string /
// callee / local / field / type behind each operand). That view must stay
// PARSEABLE : `parser.parse_virt`'s `strip_comment` drops the comments on
// read, so an annotated dump must run to the exact same `vm.snapshot` as the
// clean dump. This locks in two things against silent breakage — the Tier-A
// annotation format (`vader/bytecode/dump.vader`) and the parser's
// comment-skipping (`vader/vm/parser.vader::strip_comment`, incl. `;` inside
// quoted strings). The guarantee is format-level, not per-snippet, so a small
// curated set covering strings / structs / fields / calls / interpolation
// suffices — no need to double the whole self-emit VM cost.
const ANNOTATED_ROUNDTRIP = ["hello", "struct_defaults", "fn_decl", "interpolation"];
for (const name of ANNOTATED_ROUNDTRIP) {
  const s = scenarios.find((x) => x.name === name);
  if (!s) continue;
  test.concurrent(`vader-vm-annotated: ${name}`, async () => {
    const dump = await runCli(["dump", "--stage=bytecode", "--annotate", s.mainPath]);
    const tmp = join(tmpdir(), `vader-annot-${name}.virt`);
    writeFileSync(tmp, dump.stdout);
    const { stdout, stderr, exit } = await runCli(["run", tmp]);
    const actual = formatRun(stdout, stderr, exit);
    const cmp = snapshotEquals(s.dir, "vm.snapshot", actual);
    if (!cmp.ok) {
      throw new Error(
        `vader-vm-annotated mismatch: ${name}\n` +
        `  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: MEDIUM_BUILD });
}
