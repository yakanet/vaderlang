// VM parity: every snippet's `vm.snapshot` is checked against the Vader VM.
//
// It is compared with `./build/vader run` on the snippet's
// `bytecode.snapshot.virt`, or on bytecode built from source when the snippet
// has none or is listed in `VADER_SELF_EMIT`. The output goes through
// `formatRun`, as the native run in `parity-cemit.test.ts` does.
//
// A snippet whose VM run is not checked says so in its `_config.json`, with its
// reason (`"vm": { "skip" | "skip_on" }`); one with a `helper.c` is skipped, its
// foreign symbols living only in a native binary.

import { expect, test } from "bun:test";
import { existsSync, readFileSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";

import { type Scenario, VM_SNAPSHOT, exclusionReason, formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
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

// Snippets whose `vm.snapshot` is checked against the bytecode image that
// `vader build --emit=bytecode-text` links from source, rather than against the
// committed `bytecode.snapshot.virt` (or, off the pinned host, `vader dump
// --stage=bytecode`). The build driver's path to bytecode is the one a program
// takes outside this suite, and nothing else here runs it; the list keeps a
// spread of programs on it: trait dispatch, narrowing, closures, generics, std
// collections, comptime constants.
const VADER_SELF_EMIT = new Set<string>([
  "alias_union_in_array", "array_iter", "array_view_aliasing",
  "chained_divergent_narrow", "char_literal_escapes", "closure_in_generic_fn",
  "coerce_into", "comptime_const", "comptime_reads_a_file", "comptime_type_value",
  "const_array_basic",
  "const_fn_wrap", "const_imported_from_std", "custom_iter",
  "custom_iter_generic", "enum_match", "enum_trait_self_return", "enum_typed",
  "expr_bodied_fn", "expr_bodied_recursive_typed", "field_narrowing",
  "for_range", "gc_survival", "generic_helper_chain",
  "generic_struct", "generic_type_alias", "hello", "i64_const_width",
  "if_is_field_after_narrow", "if_is_narrow", "if_null_narrow",
  "if_without_else_stmt", "implicit_dot_variant", "in_range_element",
  "interpolation", "intrinsic_field_access", "io_roundtrip", "is_union_runtime",
  "iter_coerce_method_arg", "iterator_terminals", "json_basics", "lambda_no_fn",
  "loop", "map_set_basics", "match_arm_narrows_scrutinee",
  "match_literal_patterns", "match_partial", "match_struct_pattern_in_union",
  "match_wildcard_narrow", "multiline_string", "namespace_member_forms",
  "narrow_imported_map", "nullable_node_across_calls", "op_overload",
  "parse_int_match", "self_ref_struct",
  "struct_default_cross_module", "struct_defaults", "struct_spread",
  "trait_box_range_iter", "trait_dispatch_bounded", "trait_virtual_dispatch",
  "transitive_mono", "ufcs_union_receiver", "union_common_field",
  "union_computed_u64",
]);

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
    const cmp = snapshotEquals(s.dir, VM_SNAPSHOT, actual);
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
    ...VADER_SELF_EMIT,
    ...ANNOTATED_ROUNDTRIP,
  ];
  expect(listed.filter((name) => !known.has(name))).toEqual([]);
});

for (const s of scenarios) {
  const excluded = exclusionReason(s.config.vm);
  if (excluded !== null) {
    test.skip(`vader-vm: ${s.name} (${excluded})`, () => {});
    continue;
  }
  // Run from the image `build --emit=bytecode-text` links (see `VADER_SELF_EMIT`).
  if (VADER_SELF_EMIT.has(s.name)) {
    testFromSource(s);
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
  const virtPath = `${s.dir}/bytecode.snapshot.virt`;
  if (!existsSync(virtPath)) {
    // Its stage snapshots stop before bytecode (`_config.json`). A run oracle
    // is still checked, from source; without one, the stage snapshots are the
    // whole test.
    if (existsSync(join(s.dir, VM_SNAPSHOT))) {
      testFromSource(s);
    }
    continue;
  }
  test.concurrent(`vader-vm: ${s.name}`, async () => {
    const runVirt = await virtForHost(s.name, s.mainPath, virtPath);
    const { stdout, stderr, exit } = await runCli(["run", runVirt]);
    const actual = formatRun(stdout, stderr, exit);
    const cmp = snapshotEquals(s.dir, VM_SNAPSHOT, actual);
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
// annotation format (`vader/emit/virt/dump.vader`) and the parser's
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
    const cmp = snapshotEquals(s.dir, VM_SNAPSHOT, actual);
    if (!cmp.ok) {
      throw new Error(
        `vader-vm-annotated mismatch: ${name}\n` +
        `  snap: ${cmp.snapPath}\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected, actual),
      );
    }
  }, { timeout: MEDIUM_BUILD });
}
