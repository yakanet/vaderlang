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
  "defer_block",
  "enum_match",
  "generic_angle_decl",
  "generic_struct",
  "trait_dispatch_bounded",
  "iter_combinators",
  "tuple_basics",
  "struct_defaults",
  "struct_spread",
  "closure_env_shapes",
  "expr_bodied_fn",
  "format_helpers",
  "implicit_dot_variant",
  "not_paren",
  "precedence_parens",
  // Holds `(fn() -> void)[]`, a fn type under a TYPE postfix, which the
  // printer corrupted for as long as this file was not in the list. A
  // committed snippet pins the shape better than an invented source does.
  "capture_loop_var",
  // A PARAMETER decorator: `@c_pointer` was silently dropped by the formatter,
  // and without it a `@c_struct` crosses by value, where its `@c_out` is refused,
  // so formatting this file used to stop it compiling. The AST round-trip is
  // what catches it.
  "c_struct_layout",
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
    // Operands the TYPE postfix `[]` must keep parenthesised: a fn type most
    // visibly, since its result extends right and `(fn(i64) -> i64)[]` would
    // come back as a fn RETURNING an array.
    name: "parenthesised_postfix_element",
    source: `module "reg/parenthesised_postfix_element"

apply_all :: fn(fns: (fn(i64) -> i64)[], seed: i64) -> i64 = seed

boxed :: fn() -> (fn(i64) -> i64)[] = []

ranged :: fn() -> i32 {
    a :: (0..<3)[]
    b :: (1 + 1)[]
    return i32(a.len() + b.len())
}
`,
  },
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
    // A decorated \`@comptime\` const whose value the parser hands to a helper (a
    // call with arguments, a struct literal) keeps its decorator where it was.
    name: "comptime_decorator_with_helper",
    source: `module "reg/comptime_decorator_with_helper"

Point :: struct {
    x: i32
    y: i32
}

scaled :: fn(n: i32) -> i32 = n * 2

@comptime
ORIGIN :: Point { .x = 0, .y = 0 }

@comptime
TWICE: i64: scaled(21)
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
// `aligned` : arm heads pad to the widest so the arrows line up.
// `too_wide` : the widest head exceeds the alignment cap, so arrows stay glued
// to their heads (no padding).
// ---------------------------------------------------------------------------
const MATCH_ALIGN: { name: string; source: string }[] = [
  {
    name: "aligned",
    source: `module "reg/match_align"

k :: fn(t: Type) -> string = match t {
    is PrimitiveType -> t.name
    is StructType    -> "s"
    _                -> "?"
}
`,
  },
  {
    name: "too_wide",
    source: `module "reg/match_align_wide"

f :: fn(x: T) -> i32 {
    match x {
        is A -> 1
        is SomeVeryLongVariantNameThatExceedsTheAlignmentCapWidthOnItsOwnHere -> 2
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

// ---------------------------------------------------------------------------
// Enum variant alignment. Canonical sources, so fmt is a NO-OP. Across a run of
// variants on adjacent lines the `{ … }` blocks start in one column and the `=`
// in another ; a blank line or a comment line starts a new run, and survives.
// A written value keeps its spelling — `0x8892` used to come back as `34962`.
// ---------------------------------------------------------------------------
const ENUM_ALIGN: { name: string; source: string }[] = [
  {
    name: "variant_data",
    source: `module "reg/enum_align_data"

Info :: struct {
    label: string
    retry: bool = false
}

Level :: enum(Info) {
    Error   { .label = "error" }                  = 1,
    Warning { .label = "warning", .retry = true },
    Notice  { .label = "notice" },
}
`,
  },
  {
    name: "written_values",
    source: `module "reg/enum_align_values"

Target :: enum(i32) {
    Array        = 0x8892,
    ElementArray = 0x8893,
    Invalid      = -1,
}
`,
  },
  {
    name: "runs",
    source: `module "reg/enum_align_runs"

Priority :: enum {
    Low    = 10,
    Medium,
    High   = 20,

    // A new run after the blank line.
    Critical     = 30,
    VeryCritical,
}

Adjacent :: enum {
    A = 1,
    // A comment line ends the run without adding a blank line.
    Bee = 2,
}
`,
  },
];

for (const { name, source } of ENUM_ALIGN) {
  test(`fmt enum variant alignment : ${name}`, async () => {
    const src = join(process.cwd(), `.tmp-fmt-enum-${name}.vader`);
    await Bun.write(src, source);
    try {
      expect(await fmtStdout(src)).toBe(source);
    } finally {
      rmSync(src, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });
}

// ---------------------------------------------------------------------------
// Trailing comments : a `//` after code stays at the end of its line, and a run
// of consecutive such lines at one indentation shares one column — one space
// past the longest code line of the run. Each source is already in that form,
// so formatting must leave it unchanged.
// ---------------------------------------------------------------------------
const TRAILING_COMMENTS: { name: string; source: string }[] = [
  {
    name: "enum",
    source: `module "reg/trailing_enum"

Code :: enum(u8) {
    First,  // X0001
    Second, // X0002
    Third,  // X0003
}
`,
  },
  {
    name: "block",
    source: `module "reg/trailing_block"

f :: fn() -> i32 {
    x :: 1   // one
    return x // done
}
`,
  },
  {
    name: "run_breaks_at_indent",
    source: `module "reg/trailing_indent"

f :: fn(n: i32) -> i32 {
    if n > 0 { // positive
        return n // as is
    }
    return 0 // otherwise
}
`,
  },
  {
    name: "match_arms",
    source: `module "reg/trailing_match"

f :: fn(cp: u32) -> u32 = match cp {
    0x61..=0x7A -> cp - 0x20 // a-z
    0xFF        -> 0x178     // y
    _           -> cp
}
`,
  },
  {
    name: "struct_then_leading",
    source: `module "reg/trailing_struct"

Pair :: struct {
    a: i32 // the a
    b: i32 // the b
    // a leading comment stays on its own line
    c: i32
}
`,
  },
];

for (const { name, source } of TRAILING_COMMENTS) {
  test(`fmt trailing comments : ${name}`, async () => {
    const src = join(process.cwd(), `.tmp-fmt-trailing-${name}.vader`);
    await Bun.write(src, source);
    try {
      expect(await fmtStdout(src)).toBe(source);
    } finally {
      rmSync(src, { force: true });
    }
  }, { timeout: MEDIUM_BUILD });
}

// ---------------------------------------------------------------------------
// Line fit across `??`. A call before `?? return …` decides whether it fits
// counting what follows it on the line, so a binding too wide for one line
// explodes the call's arguments instead of running past 100 columns. Unlike
// the groups above, `source` is NOT canonical : `expected` is what fmt makes
// of it, and must itself be a fixed point.
// ---------------------------------------------------------------------------
type FitCase = { name: string; source: string; expected?: string };

const COALESCE_FIT: FitCase[] = [
  {
    // 110 columns as one line : the arguments go one per line.
    name: "too_wide_explodes_the_call",
    source: `module "reg/coalesce_fit_wide"

f :: fn(a: i32, b: i32, c: i32) -> i32 | null = null

g :: fn(first_parameter: i32, second_parameter: i32, third_parameter: i32) -> i32 | null {
    long_result_name :: f(first_parameter, second_parameter + third_parameter, third_parameter) ?? return null
    return long_result_name
}
`,
    expected: `module "reg/coalesce_fit_wide"

f :: fn(a: i32, b: i32, c: i32) -> i32 | null = null

g :: fn(first_parameter: i32, second_parameter: i32, third_parameter: i32) -> i32 | null {
    long_result_name :: f(
        first_parameter,
        second_parameter + third_parameter,
        third_parameter,
    ) ?? return null
    return long_result_name
}
`,
  },
  {
    // Exactly 100 columns, and a fallback that explodes on its own : only its
    // head \`return Foo {\` shares the call's line, so the call stays inline.
    // Already canonical — no \`expected\`.
    name: "fitting_lines_stay",
    source: `module "reg/coalesce_fit_stays"

Foo :: struct {
    a: i32
    b: i32
}

f :: fn(a: i32, b: i32, c: i32) -> i32 | null = null

g :: fn(first_parameter: i32, second_parameter: i32, third_parameter: i32) -> Foo | null {
    at_exactly_one_hundred_columns_wide :: f(first_parameter, second_parameter, 1000) ?? return null
    with_struct :: f(at_exactly_one_hundred_columns_wide, second_parameter, 1) ?? return Foo {
        .a = 1,
        .b = 2,
    }
    return Foo { .a = with_struct, .b = 0 }
}
`,
  },
];

// `expected` (or `source` when it is canonical) is what fmt makes of `source`,
// and a fixed point of fmt.
function fitTests(label: string, tmp: string, cases: FitCase[]): void {
  for (const { name, source, expected } of cases) {
    test(`${label} : ${name}`, async () => {
      const want = expected ?? source;
      expect(await fmtString(source, `.tmp-fmt-${tmp}-${name}`)).toBe(want);
      expect(await fmtString(want, ".tmp-fmt-roundtrip")).toBe(want);
    }, { timeout: MEDIUM_BUILD });
  }
}

fitTests("fmt line fit across ??", "coalesce", COALESCE_FIT);

// ---------------------------------------------------------------------------
// Line fit around a text block. A multi-line string literal is written
// verbatim, so only the line it opens on and the line it closes on count
// toward the fit : `parts.push("""` keeps its `"""` and the `)` that follows
// the closing one. As above, `expected` is what fmt makes of `source`.
// ---------------------------------------------------------------------------
const TEXT_BLOCK_FIT: FitCase[] = [
  {
    // Already canonical : the calls hug their text blocks.
    name: "hugged_call_stays",
    source: `module "reg/text_block_hug"

emit :: fn(parts: string[], n: i32) -> void {
    parts.push("""
        block \${n}
          local.get 0
          local.get 1
          array.get 1
          i32.const 0
          i32.eq
          br_if 0
        end
        """)
    match n {
        0 -> parts.push("""
                zero
            """)
        _ -> parts.push("one")
    }
}
`,
  },
  {
    // Without a trailing comma, an exploded call collapses onto its text block.
    name: "exploded_call_collapses",
    source: `module "reg/text_block_collapse"

emit :: fn(parts: string[]) -> void {
    parts.push(
        """
        local.get 0
        local.get 1
        array.get 1
        i32.const 0
        i32.eq
        """
    )
}
`,
    expected: `module "reg/text_block_collapse"

emit :: fn(parts: string[]) -> void {
    parts.push("""
        local.get 0
        local.get 1
        array.get 1
        i32.const 0
        i32.eq
        """)
}
`,
  },
  {
    // What follows the closing delimiter counts : past 100 columns, the call
    // explodes.
    name: "closing_line_too_long",
    source: `module "reg/text_block_closing_line"

pair :: fn(a: string, b: string) -> string = a + b

a_long_argument_whose_name_pushes_the_closing_line_of_the_call_past_the_one_hundred_columns :: "b"

f :: fn() -> string {
    return pair("""
        a
        """, a_long_argument_whose_name_pushes_the_closing_line_of_the_call_past_the_one_hundred_columns)
}
`,
    expected: `module "reg/text_block_closing_line"

pair :: fn(a: string, b: string) -> string = a + b

a_long_argument_whose_name_pushes_the_closing_line_of_the_call_past_the_one_hundred_columns :: "b"

f :: fn() -> string {
    return pair(
        """
        a
        """,
        a_long_argument_whose_name_pushes_the_closing_line_of_the_call_past_the_one_hundred_columns,
    )
}
`,
  },
  {
    // A block lambda's lines move with the layout, unlike a text block's : the
    // whole lambda counts, and past 100 columns the call explodes.
    name: "block_lambda_counts_whole",
    source: `module "reg/block_lambda_argument"

apply :: fn(n: i32, f: fn(i32) -> i32) -> i32 = f(n)

g :: fn() -> i32 {
    return apply(1, fn(x: i32) -> i32 {
        first :: x + 1
        second :: first * 2
        third :: second - 3
        return third * first
    })
}
`,
    expected: `module "reg/block_lambda_argument"

apply :: fn(n: i32, f: fn(i32) -> i32) -> i32 = f(n)

g :: fn() -> i32 {
    return apply(
        1,
        fn(x: i32) -> i32 {
            first :: x + 1
            second :: first * 2
            third :: second - 3
            return third * first
        },
    )
}
`,
  },
];

fitTests("fmt line fit around a text block", "text-block", TEXT_BLOCK_FIT);

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
