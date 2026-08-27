// Formatter end-to-end tests : invokes `vader fmt --stdout` over a curated
// subset of snippets to verify two contracts :
//
// 1. **Idempotency** — `fmt(fmt(src)) === fmt(src)` for every formatted file.
// 2. **Parse round-trip** — `parse(fmt(src))` is AST-equal to `parse(src)`
//    modulo spans. Demonstrates that the format pass doesn't change the
//    program's structural meaning.
//
// Each check spawns the native `build/vader` once (~20 ms). This suite used to be
// gated behind `RUN_FMT_TESTS=1` because `vader fmt` ran through a TS shim over
// the bytecode VM and paid a ~2-3 s bootstrap per call; that shim went with
// `src/`, and the gate outlived its reason — silently, since a gated test
// registers and passes.

import { test, expect } from "bun:test";
import { existsSync, rmSync } from "node:fs";
import { join } from "node:path";

import { MEDIUM_BUILD, fmtStdout, fmtString, runCli } from "./cli-bin.ts";

// A representative cross-section of the snippet corpus. Adding every
// snippet would push the runtime past 5 minutes — pick fixtures that
// exercise distinct AST shapes (decorators, generics, traits, match,
// multi-line strings, …).
const SNIPPETS = [
  "hello",
  "arith",
  "interpolation",
  "loop",
  "match_union",
  "defer_block",
  "enum_basic",
  "enum_match",
  "generic_fn",
  "generic_struct",
  "trait_dispatch_bounded",
  "iter_combinators",
  "generator_surface",
  "tuple_destructure_let",
  "tuple_for_destructure",
  "struct_defaults",
  "struct_spread",
  "closure_simple",
  "expr_bodied_fn",
  "format_helpers",
  "implicit_dot_variant",
  "not_paren",
  "precedence_parens",
];

// Structural AST via the Vader CLI. `dump --stage=ast` elides spans and
// embeds no file path, so two dumps are directly comparable ; the module
// name comes from the source `module "..."` decl, which formatting preserves.
async function astDump(path: string): Promise<string> {
  const { stdout, stderr, exit } = await runCli(["dump", "--stage=ast", path]);
  if (exit !== 0) {
    throw new Error(`vader dump --stage=ast failed on ${path} (exit ${exit}) :\n${stderr}`);
  }
  return stdout;
}

// ---------------------------------------------------------------------------
// Regression fixtures — inline sources for the round-trip bugs fixed 2026-07-06
// (audit F3/F4/F5, plus a typed-const `::` slip surfaced by the tree-wide
// sweep). Each asserts BOTH that the formatted output reparses to the same AST
// (a corrupt re-emit either fails to parse or drifts structurally) AND that
// formatting is idempotent. Kept inline rather than as `tests/snippets/` dirs
// so they carry no snapshot sidecars.
// ---------------------------------------------------------------------------
const REGRESSIONS: { name: string; source: string }[] = [
  {
    // F3 : nested generic in impl position. `Into<Iterator<T>>` used to gain an
    // extra `>` — the split `>>` handed both closers the whole-`>>` span.
    name: "nested_generic_impl",
    source: `module "reg/nested_generic_impl"

Iterator :: trait<T> {
    next :: fn(self) -> T | null
}

Into :: trait<Target> {
    into :: fn(self) -> Target
}

Wrap :: struct<T> {
    inner: T
}

Wrap<T> implements<T> Into<Iterator<T>> {
    into :: fn(self) -> Iterator<T> {
        return self.inner
    }
}
`,
  },
  {
    // F4 : `@comptime` const sugar (typed + untyped). Used to leak the synthetic
    // `__comptime_*` helper fn and rewrite the const to call it.
    name: "comptime_const_sugar",
    source: `module "reg/comptime_const_sugar"

build_table :: fn() -> i32[] = [1, 2, 3]

TABLE_TYPED: i32[]: @comptime { return build_table() }
TABLE_UNTYPED :: @comptime build_table()
`,
  },
  {
    // F5 : struct-pattern literal field. `field: <expr>` was re-emitted with `=`
    // and no longer reparsed.
    name: "struct_pattern_literal",
    source: `module "reg/struct_pattern_literal"

Point :: struct {
    x: i32
    y: i32
}

classify :: fn(pt: Point) -> i32 = match pt {
    is Point { x: 0 } -> 1
    _ -> 2
}
`,
  },
  {
    // Typed const `NAME: T: value` (Odin-style, two single colons). Used to be
    // re-emitted as `NAME: T :: value`, which no longer reparsed.
    name: "typed_const",
    source: `module "reg/typed_const"

MASK: u64: 0xFFFFFFFF
NAMES: string[]: ["a", "b"]
`,
  },
  {
    // Postfix target paren-drop. A range / binary / unary receiver of `.method`,
    // `[index]` or a call binds looser than the postfix, so its parens are
    // required — dropping them re-targets the postfix at a sub-expression
    // (`(0..<3).count()` → `0..<3.count()` binds `.count()` to `3`).
    name: "postfix_target_parens",
    source: `module "reg/postfix_target_parens"

r :: fn() -> i64 = (0..<3).count()
b :: fn(x: i32, y: i32) -> i32 = (x + y).abs()
u :: fn(x: i32) -> i32 = (-x).abs()
i :: fn(x: i32, y: i32) -> i32[] = (x + y)[0..<2]
`,
  },
  {
    // Local typed-const `name: T: value` (two single colons) is immutable ;
    // re-emitting it as `name: T = value` silently widened it to a mutable local.
    name: "local_typed_const",
    source: `module "reg/local_typed_const"

f :: fn() -> u64 {
    a: u64: 14757395258967641293
    b: i32 = 2
    return a + u64(b)
}
`,
  },
  {
    // Fn type as a union operand needs parens : \`-> ReturnType\` greedily
    // absorbs a following \`| T\`, so \`(fn() -> void) | null\` re-emitted bare
    // becomes \`fn() -> void | null\` = \`fn() -> (void | null)\`.
    name: "fn_type_union",
    source: `module "reg/fn_type_union"

S :: struct {
    a: (fn(string, string) -> void) | null
    c: i32 | (fn() -> void) | string
}
`,
  },
  {
    // Mutable-parameter marker `!`. It has TWO surfaces for one notion, and each
    // must survive a round-trip: on the TYPE (`buf: u8[]!`, including inside a fn
    // type, `fn(u8[]!) -> void`, where there are no parameter names at all), and on
    // `self!`, the one place it still rides the name — `self` has no written type to
    // hang it on. Dropping either silently widens a read-only borrow into a mutable
    // slot.
    //
    // `buf!: u8[]` was the original spelling and is now P1031: this fixture kept it
    // for a while after the marker moved onto the type, and nothing said so, because
    // the whole file sat behind an opt-in gate.
    name: "mutable_param_marker",
    source: `module "reg/mutable_param_marker"

Counter :: struct {
    count: i32
}

Bumpable :: trait {
    bump :: fn(self!, by: i32) -> void
}

Counter implements Bumpable {
    bump :: fn(self!, by: i32) -> void {
        self.count += by
    }
}

fill :: fn(buf: u8[]!, byte: u8) -> void {
    buf.push(byte)
}

apply :: fn(f: fn(u8[]!) -> void, xs: u8[]!) -> void {
    f(xs)
}

mixed :: fn(a: u8[], b: u8[]!, c: i32) -> void {
    b.push(c)
}
`,
  },
];

for (const { name, source } of REGRESSIONS) {
  test(`fmt regression round-trip : ${name}`, async () => {
    const orig = join(process.cwd(), `.tmp-fmt-reg-src-${name}.vader`);
    const fmtd = join(process.cwd(), `.tmp-fmt-reg-out-${name}.vader`);
    await Bun.write(orig, source);
    try {
      const formatted = await fmtStdout(orig);
      await Bun.write(fmtd, formatted);
      // Structural round-trip : formatted output reparses to the source AST.
      expect(await astDump(fmtd)).toBe(await astDump(orig));
      // Idempotency.
      expect(await fmtString(formatted, ".tmp-fmt-roundtrip")).toBe(formatted);
    } finally {
      // `rmSync(force)` and not `Bun.file().delete()`: the latter returns a PROMISE,
      // so an ENOENT (the output file is never written when fmt itself fails) escapes
      // the surrounding try/catch as an unhandled rejection and fails the NEXT test
      // instead. One stale fixture reported as three failures that way.
      for (const p of [orig, fmtd]) rmSync(p, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });
}

// ---------------------------------------------------------------------------
// Comment-preservation fixtures. Each source is already canonically formatted,
// so fmt must be a NO-OP : `fmt(src) === src`. A relocated or dropped comment
// changes the output and trips the check — which neither the AST round-trip
// (comments aren't in the AST) nor idempotency (stable on the moved version)
// catches. Guards the enum-variant + block-trailing comment flush fixes.
// ---------------------------------------------------------------------------
const COMMENT_STABILITY: { name: string; source: string }[] = [
  {
    // A variant's leading comment must stay attached to it, not relocate after
    // the enum's `}`.
    name: "enum_variant_comment",
    source: `module "reg/enum_variant_comment"

Kind :: enum(u8) {
    Alpha,
    // Doc for Beta.
    Beta,
}
`,
  },
  {
    // A comment above a block-TRAILING expression (a \`match\` that is a fn's
    // whole body) must stay put, not detach to end-of-block or into an arm.
    name: "block_trailing_comment",
    source: `module "reg/block_trailing_comment"

classify :: fn(x: i32) -> i32 {
    // Leading comment before the match.
    match x {
        0 -> 1
        _ -> 2
    }
}
`,
  },
];

for (const { name, source } of COMMENT_STABILITY) {
  test(`fmt comment stability : ${name}`, async () => {
    const src = join(process.cwd(), `.tmp-fmt-cmt-${name}.vader`);
    await Bun.write(src, source);
    try {
      expect(await fmtStdout(src)).toBe(source);
    } finally {
      rmSync(src, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });
}

// ---------------------------------------------------------------------------
// Match-arm `->` alignment. Canonically-aligned sources so fmt is a NO-OP.
// `aligned` : arm heads pad to the widest so the arrows line up (CLAUDE.md §6).
// `too_wide` : the widest head exceeds the alignment cap, so arrows stay glued
// to their heads (no padding).
// ---------------------------------------------------------------------------
const MATCH_ALIGN: { name: string; source: string }[] = [
  {
    name: "aligned",
    source: `module "reg/match_align"

k :: fn(t: Type) -> string = match t {
    is PrimitiveType as p -> p.name
    is StructType as s    -> "s"
    _                     -> "?"
}
`,
  },
  {
    name: "too_wide",
    source: `module "reg/match_align_wide"

f :: fn(x: T) -> i32 {
    match x {
        is A -> 1
        is SomeVeryLongVariantNameThatExceedsTheAlignmentCapWidth as binding -> 2
        is B -> 3
    }
}
`,
  },
];

for (const { name, source } of MATCH_ALIGN) {
  test(`fmt match-arm alignment : ${name}`, async () => {
    const src = join(process.cwd(), `.tmp-fmt-align-${name}.vader`);
    await Bun.write(src, source);
    try {
      expect(await fmtStdout(src)).toBe(source);
    } finally {
      rmSync(src, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });
}

for (const name of SNIPPETS) {
  test(`fmt idempotency : ${name}`, async () => {
    const path = join("tests", "snippets", name, "_main.vader");
    if (!existsSync(path)) {
      throw new Error(`snippet missing : ${path}`);
    }
    const f1 = await fmtStdout(path);
    const f2 = await fmtString(f1, ".tmp-fmt-roundtrip");
    expect(f2).toBe(f1);
  }, { timeout: MEDIUM_BUILD });

  test(`fmt parse round-trip : ${name}`, async () => {
    const path = join("tests", "snippets", name, "_main.vader");
    if (!existsSync(path)) {
      throw new Error(`snippet missing : ${path}`);
    }
    const formatted = await fmtStdout(path);
    const tmp = join(process.cwd(), `.tmp-fmt-ast-${name}.vader`);
    await Bun.write(tmp, formatted);
    try {
      expect(await astDump(tmp)).toBe(await astDump(path));
    } finally {
      rmSync(tmp, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });
}
