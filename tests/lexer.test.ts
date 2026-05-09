import { describe, expect, test } from "bun:test";
import { tokenize } from "../src/lexer/lexer.ts";
import { DiagnosticCollector } from "../src/diagnostics/collector.ts";
import type { Token, TokenKind } from "../src/lexer/token.ts";

function lex(source: string): { tokens: readonly Token[]; diags: DiagnosticCollector } {
  const diags = new DiagnosticCollector();
  const { tokens } = tokenize(source, "<test>", diags);
  return { tokens, diags };
}

function kinds(tokens: readonly Token[]): TokenKind[] {
  return tokens.map((t) => t.kind);
}

describe("lexer — empty", () => {
  test("empty source produces only EOF", () => {
    const { tokens, diags } = lex("");
    expect(kinds(tokens)).toEqual(["eof"]);
    expect(diags.count("error")).toBe(0);
  });

  test("only whitespace produces only EOF", () => {
    const { tokens, diags } = lex("   \t  ");
    expect(kinds(tokens)).toEqual(["eof"]);
    expect(diags.count("error")).toBe(0);
  });
});

describe("lexer — identifiers and keywords", () => {
  test("plain identifier", () => {
    const { tokens } = lex("foo_bar");
    expect(tokens[0]).toMatchObject({ kind: "ident", text: "foo_bar" });
  });

  test("identifier starting with underscore", () => {
    const { tokens } = lex("_x");
    expect(tokens[0]).toMatchObject({ kind: "ident", text: "_x" });
  });

  test("each keyword maps to its kind", () => {
    const cases: Array<[string, TokenKind]> = [
      ["fn", "kw_fn"],
      ["struct", "kw_struct"],
      ["trait", "kw_trait"],
      ["implements", "kw_implements"],
      ["if", "kw_if"],
      ["else", "kw_else"],
      ["match", "kw_match"],
      ["is", "kw_is"],
      ["for", "kw_for"],
      ["in", "kw_in"],
      ["return", "kw_return"],
      ["defer", "kw_defer"],
      ["break", "kw_break"],
      ["continue", "kw_continue"],
      ["import", "kw_import"],
      ["as", "kw_as"],
      ["export", "kw_export"],
      ["true", "kw_true"],
      ["false", "kw_false"],
      ["null", "kw_null"],
      ["self", "kw_self"],
    ];
    for (const [text, kind] of cases) {
      const { tokens } = lex(text);
      expect(tokens[0]?.kind).toBe(kind);
    }
  });

  test("ident that starts with 'r' but is not a raw string", () => {
    const { tokens } = lex("rust");
    expect(tokens[0]).toMatchObject({ kind: "ident", text: "rust" });
  });
});

describe("lexer — integers", () => {
  test("decimal", () => {
    const { tokens } = lex("42");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 42n });
  });

  test("decimal with underscores", () => {
    const { tokens } = lex("1_000_000");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 1_000_000n });
  });

  test("hex", () => {
    const { tokens } = lex("0xFF");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 255n });
  });

  test("hex with underscore separator", () => {
    const { tokens } = lex("0xFF_FF");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 0xFFFFn });
  });

  test("binary", () => {
    const { tokens } = lex("0b1010");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 10n });
  });

  test("octal", () => {
    const { tokens } = lex("0o755");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 0o755n });
  });

  test("integer with suffix accolé", () => {
    const { tokens } = lex("42i64");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 42n, numericSuffix: "i64" });
  });

  test("integer with optional underscore before suffix", () => {
    const { tokens } = lex("42_u32");
    expect(tokens[0]).toMatchObject({ kind: "int_literal", intValue: 42n, numericSuffix: "u32" });
  });

  test("malformed: leading underscore", () => {
    const { tokens, diags } = lex("_42");
    // _42 lexes as identifier (per spec: identifier allowed).
    expect(tokens[0]?.kind).toBe("ident");
    expect(diags.count("error")).toBe(0);
  });

  test("malformed: trailing underscore", () => {
    const { diags } = lex("42_");
    expect(diags.count("error")).toBeGreaterThan(0);
  });

  test("malformed: double underscore", () => {
    const { diags } = lex("1__000");
    expect(diags.count("error")).toBeGreaterThan(0);
  });

  test("malformed: unknown suffix", () => {
    const { diags } = lex("42xx");
    expect(diags.count("error")).toBeGreaterThan(0);
  });
});

describe("lexer — floats", () => {
  test("simple float", () => {
    const { tokens } = lex("3.14");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", floatValue: 3.14 });
  });

  test("float with leading zero", () => {
    const { tokens } = lex("0.5");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", floatValue: 0.5 });
  });

  test("float with multiple leading zeros", () => {
    const { tokens } = lex("00.5");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", floatValue: 0.5 });
  });

  test("float with exponent", () => {
    const { tokens } = lex("1.5e10");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", floatValue: 1.5e10 });
  });

  test("float with negative exponent", () => {
    const { tokens } = lex("1.0e-10");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", floatValue: 1.0e-10 });
  });

  test("float with f32 suffix", () => {
    const { tokens } = lex("3.14f32");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", numericSuffix: "f32" });
  });

  test("float with optional underscore before suffix", () => {
    const { tokens } = lex("3.14_f64");
    expect(tokens[0]).toMatchObject({ kind: "float_literal", numericSuffix: "f64" });
  });

  test("integer literal with f-suffix becomes float", () => {
    const { tokens } = lex("42f32");
    expect(tokens[0]?.kind).toBe("float_literal");
  });
});

describe("lexer — chars", () => {
  test("simple ASCII char", () => {
    const { tokens } = lex("'a'");
    expect(tokens[0]).toMatchObject({ kind: "char_literal", charValue: 0x61 });
  });

  test("escape char", () => {
    const { tokens } = lex("'\\n'");
    expect(tokens[0]).toMatchObject({ kind: "char_literal", charValue: 0x0A });
  });

  test("unicode escape", () => {
    const { tokens } = lex("'\\u{1F600}'");
    expect(tokens[0]).toMatchObject({ kind: "char_literal", charValue: 0x1F600 });
  });

  test("empty char is an error", () => {
    const { diags } = lex("''");
    expect(diags.count("error")).toBeGreaterThan(0);
  });

  test("multi-char is an error", () => {
    const { diags } = lex("'ab'");
    expect(diags.count("error")).toBeGreaterThan(0);
  });
});

describe("lexer — strings", () => {
  test("empty string", () => {
    const { tokens } = lex('""');
    expect(kinds(tokens)).toEqual(["string_begin", "string_end", "eof"]);
  });

  test("plain string", () => {
    const { tokens } = lex('"hello"');
    expect(kinds(tokens)).toEqual(["string_begin", "string_part", "string_end", "eof"]);
    expect(tokens[1]?.stringValue).toBe("hello");
  });

  test("string with escape", () => {
    const { tokens } = lex('"a\\nb"');
    expect(tokens[1]?.stringValue).toBe("a\nb");
  });

  test("raw string", () => {
    const { tokens } = lex('r"a\\nb"');
    expect(kinds(tokens)).toEqual(["string_begin", "string_part", "string_end", "eof"]);
    expect(tokens[1]?.stringValue).toBe("a\\nb");
  });

  test("triple-quoted multiline string", () => {
    const src = '"""\nhello\nworld\n"""';
    const { tokens } = lex(src);
    expect(kinds(tokens)).toEqual(["string_begin", "string_part", "string_end", "eof"]);
    expect(tokens[1]?.stringValue).toBe("hello\nworld\n");
  });

  test("string with simple interpolation $x", () => {
    const { tokens } = lex('"a $x b"');
    expect(kinds(tokens)).toEqual([
      "string_begin",
      "string_part",       // "a "
      "interp_open",       // $
      "ident",             // x
      "interp_close",      // (synthetic)
      "string_part",       // " b"
      "string_end",
      "eof",
    ]);
  });

  test("string with brace interpolation ${expr}", () => {
    const { tokens } = lex('"a ${x + 1} b"');
    const ks = kinds(tokens);
    expect(ks).toEqual([
      "string_begin",
      "string_part",
      "interp_open",
      "ident",
      "plus",
      "int_literal",
      "interp_close",
      "string_part",
      "string_end",
      "eof",
    ]);
  });

  test("nested interpolation", () => {
    const { tokens } = lex('"a ${"b ${c} d"} e"');
    const ks = kinds(tokens);
    // outer: begin, part("a "), open
    expect(ks.slice(0, 3)).toEqual(["string_begin", "string_part", "interp_open"]);
    // last: end, eof
    expect(ks.slice(-2)).toEqual(["string_end", "eof"]);
    // somewhere inside: string_begin (inner string), interp_open (inner), ident, interp_close, string_end (inner), interp_close (outer)
    expect(ks).toContain("interp_open");
    expect(ks).toContain("interp_close");
  });

  test("unterminated string is an error", () => {
    const { diags } = lex('"unterminated');
    expect(diags.count("error")).toBeGreaterThan(0);
  });
});

describe("lexer — comments", () => {
  test("line comment is skipped", () => {
    const { tokens, diags } = lex("// a line comment\nx");
    expect(diags.count("error")).toBe(0);
    expect(tokens.find((t) => t.kind === "ident")?.text).toBe("x");
  });

  test("block comment is skipped", () => {
    const { tokens, diags } = lex("/* a block comment */ x");
    expect(diags.count("error")).toBe(0);
    expect(tokens.find((t) => t.kind === "ident")?.text).toBe("x");
  });

  test("nested block comment", () => {
    const { tokens, diags } = lex("/* outer /* inner */ still outer */ x");
    expect(diags.count("error")).toBe(0);
    expect(tokens.find((t) => t.kind === "ident")?.text).toBe("x");
  });

  test("unterminated block comment is an error", () => {
    const { diags } = lex("/* unterminated");
    expect(diags.count("error")).toBeGreaterThan(0);
  });
});

describe("lexer — operators", () => {
  test("multi-char operators", () => {
    const cases: Array<[string, TokenKind]> = [
      ["==", "eq"],
      ["!=", "neq"],
      ["<=", "lte"],
      [">=", "gte"],
      ["&&", "and_and"],
      ["||", "or_or"],
      ["<<", "shl"],
      [">>", "shr"],
      ["->", "arrow"],
      ["=>", "fat_arrow"],
      ["::", "decl_const"],
      [":=", "decl_var"],
      ["..<", "range_excl"],
      ["..=", "range_incl"],
    ];
    for (const [text, kind] of cases) {
      const { tokens } = lex(text);
      expect(tokens[0]?.kind).toBe(kind);
    }
  });

  test("single-char operators", () => {
    const cases: Array<[string, TokenKind]> = [
      ["+", "plus"], ["-", "minus"], ["*", "star"], ["/", "slash"],
      ["<", "lt"], [">", "gt"], ["?", "question"], ["@", "at"],
      ["$", "dollar"], ["!", "bang"], ["=", "assign"],
    ];
    for (const [text, kind] of cases) {
      const { tokens } = lex(text);
      expect(tokens[0]?.kind).toBe(kind);
    }
  });
});

describe("lexer — newlines", () => {
  test("standalone newline emits NEWLINE", () => {
    const { tokens } = lex("a\nb");
    expect(kinds(tokens)).toEqual(["ident", "newline", "ident", "eof"]);
  });

  test("newline absorbed inside parens", () => {
    const { tokens } = lex("(a\nb)");
    expect(kinds(tokens)).toEqual(["lparen", "ident", "ident", "rparen", "eof"]);
  });

  test("newline absorbed after comma", () => {
    const { tokens } = lex("a,\nb");
    expect(kinds(tokens)).toEqual(["ident", "comma", "ident", "eof"]);
  });

  test("newline absorbed after binary operator", () => {
    const { tokens } = lex("a +\nb");
    expect(kinds(tokens)).toEqual(["ident", "plus", "ident", "eof"]);
  });

  test("newline absorbed after =", () => {
    const { tokens } = lex("x =\n42");
    expect(kinds(tokens)).toEqual(["ident", "assign", "int_literal", "eof"]);
  });

  test("newline absorbed after :", () => {
    const { tokens } = lex("x :\ni32");
    expect(kinds(tokens)).toEqual(["ident", "colon", "ident", "eof"]);
  });

  test("newline absorbed after ->", () => {
    const { tokens } = lex("fn() ->\ni32");
    expect(kinds(tokens)).toEqual(["kw_fn", "lparen", "rparen", "arrow", "ident", "eof"]);
  });

  test("multiple consecutive newlines collapse", () => {
    const { tokens } = lex("a\n\n\nb");
    expect(kinds(tokens)).toEqual(["ident", "newline", "ident", "eof"]);
  });

  test("backslash is a stray (no continuation)", () => {
    const { diags } = lex("a + \\\nb");
    expect(diags.count("error")).toBeGreaterThan(0);
  });
});

describe("lexer — shebang", () => {
  test("shebang on line 1 is ignored", () => {
    const { tokens, diags } = lex("#!/usr/bin/env vader\nfoo");
    expect(diags.count("error")).toBe(0);
    expect(tokens[0]?.kind).toBe("ident");
    expect(tokens[0]?.text).toBe("foo");
  });

  test("shebang not on line 1 is an error", () => {
    const { diags } = lex("foo\n#!/bad");
    expect(diags.count("error")).toBeGreaterThan(0);
  });
});

describe("lexer — declarations smoke test", () => {
  test("simple function declaration tokens", () => {
    const { tokens, diags } = lex("main :: fn() -> i32 { return 0 }");
    expect(diags.count("error")).toBe(0);
    expect(kinds(tokens)).toEqual([
      "ident",        // main
      "decl_const",   // ::
      "kw_fn",        // fn
      "lparen", "rparen",
      "arrow",
      "ident",        // i32
      "lbrace",
      "kw_return",
      "int_literal",
      "rbrace",
      "eof",
    ]);
  });

  test("trait declaration tokens", () => {
    const { tokens, diags } = lex("Display :: trait { fn show(self) -> string }");
    expect(diags.count("error")).toBe(0);
    expect(kinds(tokens)).toContain("kw_trait");
    expect(kinds(tokens)).toContain("kw_self");
  });

  test("hello world", () => {
    const src = `
      import "std/io" { println }

      main :: fn() -> i32 {
          println("Hello, World!")
          return 0
      }
    `;
    const { diags } = lex(src);
    expect(diags.count("error")).toBe(0);
  });
});
