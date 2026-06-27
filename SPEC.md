# Vader Language Specification

> **Status**: Draft — Edition Vader 1.0 (target for bootstrap)
> **Author**: Mathieu BROUTIN
> **Last revision**: 2026-05-12

This document describes the Vader language, its execution model, type system, MVP standard library, and bootstrap strategy. It serves as the reference for the TypeScript implementation of the compiler, then for its self-rewrite in Vader.

---

## 1. Vision

### Mission

Vader is a **general-purpose application language**, **strongly typed with type inference**, **portable** (Linux, macOS, Windows, WebAssembly), designed to remain **simple to learn** while allowing performant programs through a transparent compilation pipeline.

### Tagline

> *"Vader: applicative, simple, portable. The discipline of static typing, the ergonomics of a script."*

### Explicit non-goals

- **No OOP** — no inheritance, no classes, no "real" methods. UFCS (`a.f(b)` ≡ `f(a, b)`) covers object-call ergonomics.
- **No visible pointers** in source code. No pointer arithmetic. Memory layout is opaque.
- **No implicit `null`**. Nullability is expressed only as an explicit union (`T | null`).
- **No exceptions**. Errors are values, returned in a union with the success type.
- **No text macros** nor runtime reflection. Metaprogramming goes through typed `@comptime`.

### Philosophy

- **Simplicity over exotic features** — no feature for the feature's sake.
- **Reading > writing** — syntax must read top to bottom. Generics use the
  familiar `<T>` form (Java/C# style); the parser keeps the `<` →
  generic-instantiation decision local with a hard-precedence rule
  (commits to generic only when `<…>` closes with `(` or `{`), so
  comparison `<` stays unambiguous in expression position.
- **Compile-time errors > runtime errors** — string interpolation is type-checked at compile time.
- **Rich diagnostics** — every phase emits structured diagnostics (severity, message, span, notes, hints), continues after errors when possible, and produces messages that read well both in the terminal and through an LSP. The LSP itself is a post-MVP target, but the diagnostic plumbing is built in from day one.
- **Evolvability** — the pipeline must be easy to extend, every intermediate IR dumpable.

---

## 2. Compilation Model

### Overall pipeline

```
Source (.vader)
  ↓ Lexer            → Tokens
  ↓ Parser           → AST
  ↓ Resolver         → AST with resolved names (modules, imports)
  ↓ Type-checker     → Typed AST (with narrowing, traits, bidirectional inference)
  ↓ Comptime engine  → Typed AST (@comptime values evaluated; engine also drives monomorphization)
  ↓ Monomorphizer    → AST with no abstract generics
  ↓ Lowerer          → Desugaring (pattern match → if/else chains, traits → static dispatch, try → match)
  ↓ DCE              → Lowered AST with stdlib decls unreachable from user code pruned
  ↓ Mid-IR (CFG)     → Reducible CFG with basic blocks + terminators; substrate for escape / liveness analyses
  ↓ Bytecode emitter → Bytecode IR (stack-based)
  │
  ├──→ Stack-based VM   → vader run / @comptime
  ├──→ IR text emitter  → .vir file (debug / inspection / replay)
  ├──→ C emitter        → cc → native binary (Linux/macOS/Windows)
  └──→ WASM emitter     → .wasm (~1:1 mapping with bytecode, since WASM is also stack-based)
```

Self-host status (Vader-side under `vader/`): the full native pipeline is self-hosted — Lexer ✅, Parser ✅, Resolver ✅ (9 modules under `vader/resolver/`), Type-checker ✅, Comptime/monomorphizer ✅, Lowerer ✅, Mid-IR (CFG/SSA/DCE/escape/scheduler) ✅, Bytecode emitter ✅, C emitter ✅, LSP ✅, Formatter 🟡 (partial — see §18), VM 🟡 (`.virt` subset). WASM emitter ⏳ (post-MVP — see §19). The legacy TypeScript bootstrap under `src/` has been removed; self-host correctness is verified by the bootstrap fixed-point check (`bootstrap/verify.sh`) and the snapshot suite, not by cross-toolchain parity.

### Canonical IR

The canonical IR is a **stack-based bytecode**. This IR is the pivot of the ecosystem:

- it is directly executable by the **VM** (interp + comptime modes)
- it is translatable to **C** (text) for the native backend
- it maps **1:1** to WASM (both are stack-based)

### Comptime ↔ monomorphization

The compile-time execution (CTE) engine and generic monomorphization are the **same machinery**. When `List<i32>` is instantiated, the engine evaluates at compile time to generate the specialized code. For a `@comptime fn`, the same VM executes the bytecode.

The pipeline is therefore **incremental**: to evaluate a `@comptime`, its dependencies must be compiled-to-bytecode, executed, and the result injected into the AST before continuing.

### Monomorphization

Monomorphization runs **after** the comptime pass and **before** the lowerer. The comptime pass populates a registry of every concrete generic instantiation that appears in the program (e.g. `ArrayIterator<i32>`, `MutableMap<string, User>`); the monomorphizer reads this registry and clones each generic decl once per `(decl, type-args)` pair, substituting type parameters in signatures, field types, and bodies. The output is a flat AST with **no abstract generics**: every `Struct<args>` reference points to a freshly-emitted concrete decl, and every generic-fn call is rewritten to call its specialised instance.

Registry collection is **transitive**: when `outer<i32>` is observed, the comptime pass walks `outer`'s body, substitutes `T = i32`, and observes every nested generic call site (`inner_fn(arr)` becomes `inner_fn<i32>`), every `for x in arr` over `T[]` (registers `ArrayIterator<i32>`), and every substituted struct/trait reference inside the body (so e.g. `Yield<string>` materialises when `next` is monomorphised over a `string[]`). The fixpoint is bounded — recursive generic types are caught by an iteration cap rather than custom heuristics.

Lowering and every downstream phase therefore see only concrete types — they never have to invent dispatch logic for an unbound type parameter.

### Lowered AST

The lowerer consumes the monomorphised typed AST and produces a **separate, smaller AST** (the *Lowered AST*) where high-level constructs are desugared into a fixed set of primitive operations the backends understand. The original typed AST is never mutated. Specifically the lowerer:

- **Pattern match → if/else chains.** Naive linear lowering: each arm becomes a guarded `if` whose predicate is the pattern's discriminator (type tag, struct shape, literal equality) ∧ its optional `if`-guard. Bindings introduced by `is T as x` and struct destructuring become local lets at the head of the arm body. No decision-tree compilation in MVP — naive code is fine for the bytecode emitter to optimise later.
- **`expr?` → `match`.** Lowered to `match expr { is Error as e -> return e is T as t -> t }` over the typed scrutinee. Every `Error`-implementing variant routes to a `return` of that same value; the happy variant becomes the expression's result.
- **String interpolation → builder intrinsics.** Each `"…${x}…"` lowers to a sequence of `builder.new`, `builder.append_str`, `builder.append_display(x)`, `builder.finish` intrinsic calls. The runtime (which `std/string_builder` wraps) provides the actual implementation; the lowerer only emits the call chain. `builder.append_display` is dispatched statically per the post-mono `Display` impl table.
- **`defer` → exit-point duplication.** The lowerer keeps a per-block stack of pending defers (LIFO) and inlines them physically at every textual exit of the block: implicit fallthrough, `return`, `break`, `continue`. Panics are **not** unwound through defers in MVP (panics abort the program). Defers do not propagate across function boundaries.
- **Trait calls → static dispatch.** Because monomorphization has stripped abstract generics, every trait-method call site has a concrete receiver type. The lowerer rewrites `recv.to_string()` to a direct call of the specific impl's function. No vtable / dynamic dispatch in MVP.
- **No inserted runtime checks.** The lowerer does not synthesize bounds checks, null checks, division-by-zero guards, or overflow checks. Type narrowing already covers nullability; the remaining safety checks are the runtime's responsibility (when emitted) or are explicitly out of scope for MVP.

The Lowered AST is the input to the dead-code elimination pass. It is dumpable as JSON via `vader dump --stage=lowered-ast` for debugging and snapshot tests.

### Mid-IR (CFG)

Between the (DCE'd) Lowered AST and the bytecode emitter, a Mid-IR layer lowers every `LoweredFnDecl` to a **reducible CFG** of basic blocks with explicit terminators (`branch`, `cond_branch`, `return`, `unreachable`). Expressions become three-address `Instruction` sequences over named local slots; control flow (`LoweredIf`, `LoweredLoop`, `break`, `continue`, `return`) becomes block terminators. Strings are interned into a project-level pool reused verbatim by the emitter.

The CFG is the substrate for analyses that need def-use chains rather than tree walks:

- **Escape analysis** — stack-allocates structs whose lifetime stays within the function (no SSA).
- **Loop-carried-dependency check** — replaces the over-conservative "in loop ⇒ escapes" filter; +95 stack-promotions on the self-host.
- **Dead-store elimination** — finer-grained than the AST-level DCE pass, prunes individual writes whose result is never read.

The bytecode emitter consumes the CFG (not the Lowered AST), recovers WASM-style structured nesting via a structurer pass that uses immediate dominators + post-dominators, and emits the linear stack ops. CFG dumps are exposed via `vader dump --stage=cfg`. Design: `docs/MID_IR_DESIGN.md`.

### Dead-code elimination

Between the lowerer and the bytecode emitter, a DCE pass prunes lowered declarations that are not transitively reachable from a small set of roots. This keeps unused stdlib machinery out of the final artifact: `std/core` is auto-imported in every program, but a `hello world` doesn't need `Range`, `ArrayIterator`, `Yield`, `IOError`, or their impls — DCE drops them before emission.

Roots — preserved unconditionally:

- every decl from a non-stdlib module (the user's own code is never DCE'd, so library targets and snapshot fixtures without `main` keep all their decls);
- `main` (the fn whose mangled name ends in `$main` and has a body);
- any decl carrying `@export`, `@test`, or `@extern` (`@extern` covers signature-only imports — the import table must stay aligned with what the host expects).

`@comptime` constants are not automatic roots — their value is inlined at each use site by the bytecode emitter, so an unreferenced one is genuinely dead. They are still preserved when defined in a non-stdlib module by the user-code rule.

Reachability is computed via BFS over the Lowered AST: every `LoweredIdent.symbol.id` and every struct/trait `Type.symbol.id` encountered is added to the live set. Trait dispatch is already statically resolved by the lowerer (one impl-member symbol per call site), so there is no need to over-approximate by keeping every impl of a referenced trait. The pass is a pure `LoweredProject → LoweredProject` transform and is shared across backends. It is dumpable via `vader dump --stage=dced-ast`.

### Exposed execution modes

- `vader run script.vader`: parse + typecheck + interp via VM. No binary emission.
- `vader build [file|--manifest]`: full pipeline + emission of either C-based native binary or WASM.
- `vader` (no args): REPL.

### Compile-time sandbox

Code in `@comptime` context can:

- ✅ compute (pure functions)
- ✅ allocate memory and manipulate structures
- ✅ read project files (via `@file(path)` — see §14)
- ❌ read `ENV` / `args`, network syscalls, exec, stdout: **forbidden**, to preserve build reproducibility

---

## 3. Lexical Structure

### Source encoding

UTF-8. A leading BOM is silently ignored.

### Shebang

A `#!` shebang line is allowed on the **first line only** and is silently skipped by the lexer. Anywhere else, `#!` is a lexical error. This makes Vader scripts directly executable on Unix.

```vader
#!/usr/bin/env vader
main :: fn() -> i32 { return 0 }
```

### Comments

```vader
// line comment, terminates at the next newline

/* block comment */

/*
   /* nested block comments are allowed */
   the outer comment continues here
*/
```

Nested block comments are supported: the lexer tracks nesting depth and only closes the outer comment when depth returns to zero.

### VaderDoc

Doc-comments start with `///` (line form). Each successive `///` line is part of the same doc-block attached to the declaration that immediately follows. The lexer drops every comment before the parser sees it; tooling consumes them by re-scanning the source (`vader/fmt/comments.scan_comments` and the future `vader doc` extractor). The `///` form is the only supported VaderDoc shape — `/**` block-style doc-comments are NOT recognised.

Doc-comments may use the following tags. Tags appear one per line, after a blank-line-separated body:

| Tag        | Meaning                                                                          |
|------------|----------------------------------------------------------------------------------|
| `@param`   | Describe one named parameter. Format: `@param <name>  <description>`.           |
| `@return`  | Describe the return value. Omit for `void` returns.                              |
| `@error`   | Describe which `Error` variant(s) can be raised and under what cause.            |
| `@example` | A usage snippet block. Lines after the bare `@example` line are the body — the convention is to indent them with backtick-wrapped code, one example per line. |

```vader
/// Parse `s` as a base-10 `i32`. No prefix, no underscores, no leading
/// `+` sign; a leading `-` is accepted.
///
/// @param s  the digits-only input.
/// @return   the parsed integer.
/// @error    `ParseError` on empty input, malformed digit, or overflow.
/// @example
///   `parse_int("42")     → 42`
///   `parse_int("hello")  → ParseError`
export parse_int :: fn(s: string) -> i32 | ParseError
```

Every public method in the standard library carries a VaderDoc block following this convention.

### Identifiers

`[a-zA-Z_][a-zA-Z0-9_]*`. Case-sensitive. No Unicode in identifiers in MVP.

### Reserved keywords

```
fn struct trait implements enum
if else match is for in return defer break continue
import as
export
true false null
self
const
@<decorator>
```

The identifier `void` is **reserved**: binding it as a fn name, struct name, parameter, local, type-param, pattern binding, or namespace-import name raises `R2019`. The name describes the type of expressions that yield no value and is never user-facing in source code.

`Self` (capitalised) is **not** a lexical keyword — it is a reserved *type name* resolved by the typechecker, usable only inside `trait` / `implements` bodies where it denotes the implementing type. Using it elsewhere raises `T3023`. (Only lowercase `self`, the receiver parameter, is a keyword.)

### Literals

#### Integer literals

- Decimal: `42`, `1_000_000`
- Hexadecimal: `0xFF`, `0xff`, `0xFF_FF` (case-insensitive after `0x`)
- Binary: `0b1010`, `0b1010_1010`
- Octal: `0o755`, `0o7_5_5`
- Default type: `i32` when no surrounding context pins a width. A literal is *free* (untyped) until its context provides a concrete integer type — there is **no typed-suffix form** (`42i32` / `42_i32` are errors); write a typed slot, annotation, or cast instead.
- Underscore rules: never two in a row (`1__000` is an error), never leading or trailing on the digits (`_42`, `42_` are errors).

#### Float literals

- Standard: `3.14`, `0.5`, `00.5` (leading zeros allowed), `1.0e-10`, `1.5E+3`
- A trailing point with no fractional digits is forbidden: `5.` is an error — write `5.0`.
- A bare `.5` is forbidden — write `0.5`.
- Default type: `f64`. Like integers, a float literal is *free* until context pins a width ; there is **no typed-suffix form** (`3.14f32` is an error — annotate the slot for `f32`).
- Same underscore rules as integers.

#### Boolean / null

`true`, `false`, `null` are reserved keywords producing literal tokens.

#### Char literals

```vader
'a'        // ASCII codepoint
'é'        // any Unicode codepoint
'\n'       // escape sequence
'\u{1F600}'  // explicit codepoint
```

- Escape set: `\n`, `\t`, `\r`, `\\`, `\'`, `\0`, `\u{HHHH}` (1–6 hex digits).
- Exactly **one** logical codepoint per literal. `''` and `'ab'` are lexical errors.
- A char **literal** is *free*: in an integer context it coerces to that integer type, carrying its codepoint, bounds-checked at compile time (`b == '/'` with `b: u8` works ; `b == '💩'` is rejected — U+1F4A9 doesn't fit `u8`). With no integer context it defaults to `char`. This replaces the old `b'X'` byte literal — write `'X'`, not `b'X'`. (There is no `b'…'` form anymore.) A char **variable** keeps the concrete `char` type and never auto-coerces: convert it explicitly with `u8(c)` (which truncates codepoints above `0xFF`).

#### String literals

Three forms:

```vader
"plain"                        // simple string, supports interpolation
r"raw"                         // raw string, no interpolation, no escape processing
"""
multi-line
"""                            // triple-quoted, supports interpolation, may span newlines
```

- Escape set inside `"..."` and `"""..."""`: `\n`, `\t`, `\r`, `\\`, `\"`, `\$` (literal dollar), `\0`, `\u{HHHH}`.
- Inside `r"..."`: backslashes are taken literally; `\n` stays as two characters; no `${...}` interpretation.
- Triple-quoted strings consume an optional immediately-following newline after the opening `"""` (so the body starts on a fresh line cleanly).

#### String interpolation tokens

The lexer emits a flat token stream when crossing into and out of `${...}`:

```
STRING_BEGIN  STRING_PART("foo ")  INTERP_OPEN  <expression tokens>  INTERP_CLOSE  STRING_PART(" bar")  STRING_END
```

- `STRING_BEGIN` / `STRING_END` mark the literal's boundaries.
- `STRING_PART` carries decoded text.
- Inside `INTERP_OPEN..INTERP_CLOSE` the lexer is in **expression mode** and emits regular tokens.
- **Nested interpolation** is allowed: `"outer ${"inner ${x}"}"`. The lexer maintains a stack of modes (string vs. interpolation) so it can re-enter string mode after a nested `INTERP_CLOSE`.
- **Braceless shorthand**: a bare `$ident` interpolates a single identifier without braces — `"Hello, $name"` is equivalent to `"Hello, ${name}"`. Only a plain identifier is accepted after `$`; anything more (a field access, a call, an expression) needs the `${...}` form.
- Raw strings (`r"..."`) emit `STRING_BEGIN`, a single `STRING_PART` (with the literal contents, no escape processing, no interpolation scan), then `STRING_END`.

### Operators

```
Arithmetic   : + - * / %
Bitwise      : & | ^ ~ << >>
Comparison   : == != < <= > >=
Membership   : in   (sugar for `right.contains(left)`)
              !in   (sugar for `!right.contains(left)`, parsed as `bang` + `kw_in`)
Type test    : is Type   (in `match` arms and in `if`/`else` conditions ; narrows the scrutinee)
              !is Type   (negated form, parsed as `bang` + `kw_is` ; desugars to `!(x is Type)`)
Logical      : && || !
Assignment   : =  (also compound : += -= *= /= %=, each desugaring `lhs op= rhs` → `lhs = lhs op rhs`)
Declaration  : x :: value           (immutable, type inferred)
               x := value           (mutable,   type inferred)
               x: T : value         (immutable, typed)
               x: T = value         (mutable,   typed)
Range        : 0..<10 (exclusive)  0..=10 (inclusive)
Postfix      : ? (try, propagates the error)
Cast         : Type(expr) (numeric ↔ numeric, char ↔ integer)
Field access : .name
Index access : [expr]
```

`in` and `!in` desugar to a method call on the `Contains<T>` trait (see §11). Char comparisons (`<`, `<=`, `>`, `>=`) work on codepoint order (`char` is wire-compatible with `u32`).

### Operator precedence

From tightest to loosest. Higher levels bind more tightly. Non-assoc operators forbid chaining (`a == b == c` is a parse error — write `(a == b) == c`).

| Level | Operators                              | Associativity |
|-------|----------------------------------------|----------------|
| 1     | postfix `?`, `.`, `[]`, `()`           | left           |
| 2     | prefix `-`, `!`, `~`                   | right          |
| 3     | `*`, `/`, `%`                          | left           |
| 4     | `+`, `-`                               | left           |
| 5     | `<<`, `>>`                             | left           |
| 6     | `&`                                    | left           |
| 7     | `^`                                    | left           |
| 8     | `\|`                                   | left           |
| 9     | `..<`, `..=`                           | non-assoc      |
| 10    | `<`, `<=`, `>`, `>=`, `==`, `!=`, `is`, `!is`, `in`, `!in` | non-assoc      |
| 11    | `&&`                                   | left           |
| 12    | `\|\|`                                 | left           |
| 13    | `=` (statement-level only)             | n/a            |

Type casts (`Type(expr)`) are parsed as primary call expressions and naturally sit at level 1. The `is Type` form used in `match` arms binds at the comparison level. `!is Type` is a parser-level sugar that desugars to `!(x is Type)`; the flow-narrower handles the wrapping `!` to flip then/else, and `as <ident>` is rejected after `!is` since the binding has no meaningful lifetime when the type check is negated.

`is` checks the runtime *struct-tag* of the value, not a "union tag" — `x is <UnionType>` therefore always returns false. The typechecker emits `W0003` whenever the RHS of `is` resolves to a union (literal `A | B` or a `MyUnion :: A | B` alias), suggesting the user destructure into individual variants via `match v { is A -> ... is B -> ... }` instead.

Flow narrowing flows through a `&&` condition: in `if x is T && <rest>` the scrutinee `x` is narrowed to `T` both in the conjunction's right operand (`<rest>`) and in the then-block, so `if x is Circle && x.radius > 0 { … x.radius … }` type-checks. The else branch of a conjunction is **not** narrowed (a false `a && b` doesn't reveal which operand failed). An `as` binding may **not** appear inside a `&&` — `if x is T as a && …` raises `R2029` because the binding's scope across the short-circuit is ambiguous; narrow the variable in place (`if x is T && …`) or nest the checks (`if x is T as a { if … }`).

### Statement separators

Inside a block, statements are separated by `NEWLINE` tokens (emitted per the rules below). Vader does **not** accept `;` as a statement separator.

A leading newline immediately after `{` is silently absorbed: a block may start on a new line without an empty statement.

### Trailing commas

Trailing commas are allowed in every comma-separated list: function arguments, function parameters, struct literal fields, struct definition fields, array literals, match arms, generic argument lists, and import destructuring lists.

### Newline-significant

A newline terminates a statement. No `;` is required. The lexer emits a `NEWLINE` token at every line break **except** in the five cases below, where the newline is silently absorbed:

1. **Inside an unclosed bracket** `(` or `[` — newlines inside parens / array construction are insignificant. (Newlines inside `{ }` blocks stay significant — they separate statements; only a newline *immediately after* an opening `{` is absorbed, per *Statement separators* above.)
2. **After a binary or unary operator** that is still pending an operand: `+`, `-`, `*`, `/`, `%`, `<`, `<=`, `>`, `>=`, `==`, `!=`, `&&`, `||`, `&`, `|`, `^`, `<<`, `>>`, `..<`, `..=`, and the spread `...`. (A newline after `?` or `!` is **not** absorbed.)
3. **After a comma** `,`.
4. **After a token that expects a right-hand side**: `=`, `:`, `->`, `=>`, the binding operators `::` / `:=`, and the compound-assignments `+=` `-=` `*=` `/=` `%=`.
5. **Before a leading operator that has no prefix form** — when the next line *opens* with `&&`, `||`, `&`, or `|`, the newline before it is absorbed so the operator continues the previous expression. These four operators are infix-only (no prefix / unary meaning), so a line starting with one is unambiguously a continuation: a leading `&&` / `||` continues a boolean condition, a leading `&` / `|` continues a type intersection / union. (The compound-assign forms `&=` / `|=` are **not** treated as continuations.) Operators that *do* have a prefix form — `-`, `~`, `!` — are excluded, so they never silently join the previous line.

There is **no backslash-continuation** (`\` at end of line is not special). If you need to break a long expression, use one of the five cases above (typically wrap in parentheses, or break after — or before — a binary operator).

```vader
// OK: break inside parens
total := (a +
          b +
          c)

// OK: break after operator
total := a +
         b +
         c

// OK: break before a leading `&&` / `||` (infix-only operators)
if a == 1
    && b == 2
    && c == 3 {
    // ...
}

// OK: break after comma
list := [
    1,
    2,
    3,
]

// ERROR: backslash is not a continuation
x := a + \
     b           // lexer error: stray '\'
```

---

## 4. Type System

### Primitive types

| Category | Types |
|----------|-------|
| Boolean | `bool` |
| Unsigned integers | `u8`, `u16`, `u32`, `u64`, `usize` |
| Signed integers | `i8`, `i16`, `i32`, `i64`, `isize` |
| Floats | `f32`, `f64` |
| Text | `char` (32-bit codepoint), `string` (UTF-8 sequence) |
| Null | `null` |
| Metatype | `type` (comptime-only — see below) |

`type` is the **metatype**: a value of static type `type` *is* a Vader type. It is **comptime-only** — values never reach runtime, so `: type` is only meaningful in comptime contexts (currently the angle-bracketed `<T: type>` generic-param head, soon `let T: type = i32` and the result type of intrinsics like `@type_of(x)`). The compiler enforces that any expression typed `type` is comptime-evaluable; emitting one in a runtime slot is an internal-bug error in the bytecode emitter.

### Built-in type aliases

To reduce typing in everyday code, the compiler recognises a set of **canonical aliases** for primitive types. They are fully transparent — the compiler treats an alias and its target as the same type everywhere (error messages, snapshots, inference).

| Alias | Resolves to |
|-------|-------------|
| `int` | `i32` |
| `long` | `i64` |
| `float` | `f32` |
| `double` | `f64` |
| `byte` | `u8` (unsigned) |

`char` and `string` are already first-class names in the primitive table, so they need no alias.

`usize` is a **target-dependent** unsigned integer used for sizes and indexes. It maps to `size_t` in the C backend (typically 64-bit on modern hosts). The bytecode/VM bootstrap treats it as a 64-bit value. The WASM backend will choose the platform-native width when implemented (likely WASM64 only at first).

`isize` is its **signed** counterpart — a target-dependent signed integer used for pointer differences and signed indexing. Maps to `ptrdiff_t` in the C backend and is 64-bit in the bytecode/VM bootstrap. Use `isize` when you need a signed offset (e.g. iterating backwards), `usize` when the value is a count or index that can't be negative.

Array `len()` returns `usize`, and array indexing accepts `usize` (the runtime also accepts narrower integer types for ergonomic literals — `arr[2]` compiles, `arr.len() == 12` compiles, no explicit casts needed).

These are **built-in** aliases recognised by the resolver and type-checker; they are *not* user-defined type aliases. Aliases are not reserved keywords — they are identifiers that resolve to a builtin-type symbol, so user code may shadow them in local scope (though this is strongly discouraged).

User-defined type aliases use the same `Foo :: <type-expr>` syntax as a regular const declaration — `type` is not a keyword in Vader. The typechecker recognises a const whose value is structurally a type expression (built from type-name references and the type operators `|` / `&` / `[]` / `fn(...) -> ...`) and promotes it to a type alias: no runtime slot is allocated and the name is usable in any type-demanding slot.

Generic type aliases use the LHS-angle head `Foo<T> :: <body>` — the `<...>` between the ident and `::` is unambiguous (no other decl form puts angles there), so the parser dispatches without a form-selector keyword. Type parameters are always written with angle brackets `<...>`; there is no bracket or paren form.

```vader
// Non-generic implicit alias — just a const whose value is a type
Mixed :: i32 | string

// Generic alias via LHS-angle type-params
Maybe<T> :: T | null
Pair<A, B> :: A | B

// Used like any named type
fits :: fn(x: Mixed) -> bool {
    return match x {
        is i32    -> true
        is string -> false
    }
}

opt: Maybe<i32> = 42
```

#### Distinct types (newtypes over a primitive)

A `Name :: <type-expr>` whose RHS resolves to a **primitive** (`i32`, `u8`,
`f64`, `bool`, `char`, `string`, … — anything but `void` / `null`) is **not** a
transparent alias: it is a **distinct type** (a nominal newtype, à la Nim
`distinct` / Go defined-types). A composite RHS (`union` / `&` / `[]` / `fn`)
stays a transparent alias as above. There is no decorator — the primitive RHS
*is* the trigger.

```vader
Celsius :: f64        // distinct — NOT interchangeable with f64
Handle  :: i32        // distinct
Mixed   :: i32 | string   // transparent alias (composite RHS)
```

A distinct type is **nominal** at typecheck and **zero-cost** at runtime — it
is represented exactly as its backing primitive (a register scalar, no heap
box; the same mechanism `enum` uses for its `repr`). Distinct exists only in the
typechecker; the backend never sees one (it is stripped to the backing at the
lowering boundary).

- **Conversions are explicit and symmetric**, both runtime no-ops:
  `Celsius(x)` wraps an `f64`, `f64(c)` unwraps. An *implicit* coercion either
  way is rejected (`T3001`) — that is the whole point of the newtype.
- **Operators are opaque by default.** A distinct does **not** inherit its
  backing's `Add` / `Comparable` / `Equals` / `Hash` impls (Vader has no
  auto-derive). Arithmetic, comparison, equality, hashing and map-key use each
  require an explicit `Celsius implements Add { … }` / `Comparable` / `Equals` /
  `Hash` on the distinct — typically delegating to the backing
  (`-> i32(self) == i32(other)`). Using an operator with no matching impl is
  the usual `T3043` / `T3017`. This is what enables dimensional types
  (`Instant - Instant -> Duration`).
- **`@comptime Name :: <type>` is the exception** — it stays a transparent
  compile-time type alias (it resolves through the comptime type-alias channel,
  e.g. `@size_of(Name)`), never a newtype.
- **Reflection follows the backing**: `@size_of`, `@align_of` and `@type_kind`
  of a distinct report its backing primitive's size / alignment / `"primitive"`.

### Default integer

A literal integer with no concrete context **infers to `i32`** (`x := 42` ⇒ `x: i32`).

### Default float

A literal float with no concrete context **infers to `f64`** (`x := 3.14` ⇒ `x: f64`).

### Implicit numeric coercion

There is **no implicit coercion between sized numeric types**. `i32 → i64` requires an explicit cast (`i64(x)`). The exception is numeric literals: `x: i64 = 42` works because `42` is left flexible until it lands in a typed context.

### Float ↔ bits reinterpret

A `Type(expr)` cast **converts the value** (`u64(3.7)` truncates to `3`; `f64(5)` widens to `5.0`). To reinterpret a float as its raw **IEEE 754 bit pattern** — a different operation, same bits, no value change — use the dedicated methods (NOT the cast, which would silently change meaning):

```
x: f64 = 3.0
bits :: x.to_bits()        // u64 0x4008000000000000  — the exact IEEE bits
back :: bits.from_bits()   // f64 3.0                 — round-trips bit-for-bit
```

`f64.to_bits() -> u64` (trait `FloatBits`) and `u64.from_bits() -> f64` (trait `BitsFloat`) are `std/core` prelude methods, mirroring Rust's `f64::to_bits` / `f64::from_bits`. They lower to the `F64ToBits` / `BitsToF64` memory opcodes — an inline `union` cast in the C backend, no runtime symbol — and are the foundation for float formatting / bit-fiddling.

### Numeric-literal context-sensitivity

An integer literal stays as a *free* (untyped) numeric until its surrounding context provides a concrete width; at that point it adopts the slot's type *without* a runtime conversion. This is what makes `x: usize = 5`, `Box { .size = 10 }`, `arr.slice(0, n - 1)`, `if usz == 42`, and `g: i64 = -50` all compile without explicit casts even though `5`, `10`, `0`, `42`, `50` would otherwise default to `i32`.

The flow is bidirectional:
- **Top-down (slot expected)** — typed lets, struct-field defaults, fn-arg slots, struct-lit field values, return-type-annotated `return …`, indexed `arr[i]` (slot is the impl's `I` type), comparison/arithmetic where one side has a concrete numeric type. The literal repins to the expected width.
- **Unary `-`, `~`** — the operand inherits the operator's outer expected type, so `g: i64 = -50` lowers the inner `50` as `i64`, not `i32`.
- **Generic call sites** — after type-parameter unification, FreeInt args adopt the substituted concrete width. Works through plain calls, generic UFCS, and namespace imports.
- **Cross-branch in `if`** — when one branch of an if-expression produces a concrete numeric type and the other is a Free literal, the Free side repins to match (so `if c { 0 } else { width: usize }` types to `usize`, not `{integer} | usize`).

When no context applies, the literal falls back to its **default** (`i32` for integers, `f64` for floats). The default is what `x := 42` records.

### Type coercion via `Into`

User-defined cross-type conversions go through the `Into<Target>` trait in `std/core`. The trait is single-method:

```vader
Into :: trait<Target> {
    into :: fn(self) -> Target
}
```

The compiler probes `S implements Into<T>` whenever a value of type `S` is about to reach a slot expecting `T` and `isAssignable(S, T)` already failed. When the impl is found the typer records the site and the lowerer inserts the matching `value.into()` call before the consumer sees the value.

**Sites of implicit coercion**
- A call argument whose corresponding parameter has a typed annotation.
- A `return v` (or block-trailing expression) of a fn with an annotated return type.
- A `x: T = v` typed binding with an annotation.
- A struct-literal field whose declared type differs from the argument's.

**Explicit form**
The `Target(value)` syntax doubles as the explicit coercion surface. Numeric and `char` targets keep their primitive cast semantics (`u32(x)`, `i64(c)`); non-numeric targets and numeric targets fed a non-numeric source route through `tryInto` and emit the matching `value.into()` call. The two paths share the same impl registry, so the implicit and explicit forms always agree on which method runs.

**Rules**
- **Target must be concrete or a trait.** `Struct`, `Enum`, `Primitive`, and `Trait` targets trigger the probe; `Union` and `TypeParam` slots are excluded. A union target leaves the typer unable to pick a variant; a `TypeParam` slot resolves after mono. Direct trait widening (when `S` already implements `T`) runs first via `isAssignable`, so `tryInto` only fires for `Trait` targets when the source needs an actual conversion (the canonical case being `T[] → Iterator<T>` via the blanket `T[] implements<T> Into<Iterator<T>>`).
- **No identity.** `T implements Into<T>` is forbidden (diagnostic **T3039** at the impl site) — it would shadow simple assignment and clutter the registry.
- **No transitive chains.** The lookup is a single registry probe. `S → U → T` never auto-composes; if both impls exist, the user must declare `S implements Into<T>` explicitly to bridge them. Prevents the "where did this allocation come from?" debugging trap.
- **One impl per `(Source, Target)`.** Duplicate impls are caught by the standard resolver duplicate-impl diagnostic.
- **Overload resolution is decided first.** When a call has overloaded candidates, the typer ranks them *without* `Into`; the second-pass with `Into` only fires if no exact-match overload was found.

**Built-in coercions**
- `T[] → Iterator<T>` — raw arrays auto-wrap into `ArrayIterator<T>` on entry to an `Iterator<T>` slot, materialised by the blanket impl `T[] implements<T> Into<Iterator<T>>` in `std/core`. Driven through the `Into` probe, not a special-cased typer rule.
- `T → string` when `T: Display` — anything implementing `Display` flowing into a `string`-typed slot is rewritten as a call to the impl's `to_string` member, via the blanket `T implements<T: Display> Into<string>` in `std/core`. The string-interpolation path (`"${value}"`) bypasses `Into` and routes through the builder intrinsics directly.
- `FreeInt → i32` / `FreeFloat → f64` and friends — free literals defaulting to their canonical width at the typer level. Unrelated to `Into`; happens before any coercion lookup.
- Concrete `S → Trait` when `S` impl `Trait` — virtual dispatch boxing. Distinct from `Into`; the value flows in unchanged and runtime dispatch resolves the method by tag.

**Resolution order at a coercion site**
1. `isAssignable(S, T)` — accepted (subtype, trait widening, numeric defaulting) → no work.
2. `tryInto(S, T)` — registry probe with the rules above.
3. Otherwise, `T3001` / `T3020` mismatch fires.

**Diagnostics**
- `T3039` — `Into<T>` identity impl rejected (emitted at the impl site, not at the call site).
- `T3001` / `T3020` — type mismatch; the message indicates no coercion was found.

### Signed overflow

`a + b` that overflows **panics in debug, wraps in release**. Behavior not configurable in MVP.

### Strings

- Internals: **fat value** `(ptr: rawptr, len: u32)` — 16 bytes copied on assignment, no shared reference.
- Immutable. Concatenation allocates.
- `len()` returns the number of Unicode codepoints (allocation-free walk via leading-byte widths). For the **byte** length, take a view and ask its length: `s.bytes().len()` — written inline like that, the lowerer folds it to an O(1) byte-length primitive (no view materialised). Byte vs. codepoint is thus explicit at the call site: `len()` for codepoint arithmetic, `s.bytes().len()` for byte arithmetic.
- `chars()` returns an iterator of `char` (`StringChars implements Iterator<char>`); pair with `for c in s.chars()` for a true Unicode loop.
- `bytes()` returns the UTF-8 byte sequence as `const u8[]`; for ad-hoc byte processing (binary protocols carried in strings, ASCII fast paths, BOM detection). On the native target it is a **zero-copy view** aliasing the string's interned bytes (it allocates only a small array header, not the byte storage); the `const` is what keeps that view sound — writes are rejected at compile time (T3042) since the shared bytes are immutable. On the VM the bytes are **copied** into a materialised array (VM arrays box every slot and cannot alias a raw byte buffer) — same observable values, just not zero-copy. Iteration works through `for b in s.bytes()` via the built-in array iterator. Strings iterate by **codepoint** by default — `string implements Into<Iterator<char>>`, so `for c in s` is the codepoint loop (equivalent to `for c in s.chars()`); use `for b in s.bytes()` to walk raw bytes.
- `is_empty()` — sugar for `s.bytes().len() == 0` (codepoint count and byte count agree on emptiness).
- **Subscript** `s[i]` returns the Unicode codepoint at *codepoint* index `i` (via `string implements Index<usize, char>` in `std/core`). Walking from the start is O(i); pair `chars()` with `for c in s.chars()` for O(n) iteration. For byte-cursor access, take a view with `s.bytes()` (a `const u8[]`) and index it — `s.bytes()[i] -> u8` for the raw byte, `s.bytes()[lo..<hi].bytes_to_string()` to slice a byte range back into a string (the inverse of `bytes()`, O(1) on the borrowed view). `byte_decode_at(i) -> char` decodes the UTF-8 codepoint starting at byte offset `i` (used by lexers, JSON parsers, LSP transport; byte-view consumers that hold the view call `decode_codepoint_at(bs, i)` instead). There is no `IndexSet` impl; strings are immutable.
- Literals stored in the binary's data section.

### Arrays

- `T[]` (postfix) is a dynamic array (runtime length). `int[]`, `string[]`, `Foo<i32>[]`, ... `int[][]` is an array of int arrays.
- **Implicit reference** semantics: `arr2 := arr` copies the reference; use `arr.clone()` (UFCS from `std/iter`) for a fresh mutable copy.
- Indexing: `arr[i]`. Bounds-checked in debug (panic), elidable in release.
- **Slicing**: `arr[r]` where `r: Range<integer>` returns a **zero-copy view** sharing the parent's buffer. Both literal ranges (`arr[1..<4]`, `arr[0..=2]`) and let-bound range values work — dispatch keys on the index *type*, not the AST shape. Any integer-bounded range is accepted; bounds are coerced to `usize` at the use site. Pushing into the view detaches it into a fresh buffer so the parent is never mutated through the slice. For an independent copy use `arr[r].clone()`.
- Postfix `[]` binds tighter than `|`; use parens to group: `(T | U)[]` is "array of T-or-U", `T | U[]` is "T or array-of-U".

#### `const T[]` — immutable arrays

The `const` prefix qualifies an array type as immutable. Through a value typed `const T[]`, mutation is rejected at typecheck — neither `arr[i] = v` nor `arr.push(v)` compiles.

```vader
read :: fn(a: const i32[]) -> i32 = a[0]            // OK to read
write :: fn(a: const i32[]) { a[0] = 99 }           // T3042 at typecheck
```

**Subtyping**: `T[] <: const T[]`. A mutable array passes anywhere a `const T[]` is expected (covariant), never the reverse. This lets read-only fns accept both kinds without overloads.

```vader
mut_arr := [1, 2, 3]
read(mut_arr)             // OK: T[] passes for const T[]
read([4, 5, 6])           // OK: fresh array passes
```

**Inference**: a module-level array-literal const-decl is automatically pinned as `const T[]`. Locals stay mutable by default.

```vader
KEYWORDS :: ["fn", "if", "else"]      // const string[] (module scope)

main :: fn() {
    local :: [1, 2, 3]                // i32[] (local — mutable)
    local[0] = 99                     // OK
}
```

**Escape hatch**: `arr.clone()` produces a fresh mutable `T[]` from any `T[]` or `const T[]` source. Mutating the copy never affects the original.

**Storage**: module-level `const T[]` literals whose elements are all primitive (fixed-width integers, floats, char, bool) and all literal-valued land in the bytecode module's data pool — the C backend emits them as `static const` `.rodata` arrays, the VM materialises them once at module load, and `data.const` op-codes resolve to those pre-built values. References share one allocation across the whole process. Non-primitive elements (struct, string) continue to fn-wrap until the pool gains the matching representation.

#### Repeat / preallocate — `[lhs] * n`

The repeat operator builds a fresh array by repeating an array literal's elements `n` times. The array is always on the **left**, an integer count on the right:

```vader
zeros := [0] * 3          // [0, 0, 0]
pair  := [7, 9] * 2       // [7, 9, 7, 9]   (length = len(lhs) * n)
```

Result length is `len(lhs) * n`; capacity is reserved for at least `max(len(lhs) * n, n)` elements. The empty-LHS form is the **preallocation** primitive (there is no named `with_capacity`):

```vader
buf: i32[] = [] * 1024    // length 0, capacity 1024 reserved
for x in src { buf.push(x) }   // no reallocation up to 1024 elements
```

- `[] * n` yields an **empty** array (length 0) whose reserved tail is uninitialised. Indexing is bounds-checked against **length**, so `([] * n)[0]` traps — the reserved slots become readable only as `push` / `push_all` grow the length past them. (Identical to Rust `Vec::with_capacity`.) Use `[v] * n` when you want `n` *readable* slots; `[] * n` only to preallocate before pushing.
- For a **reference** element type, the LHS is evaluated **once** and the same reference is repeated (shallow): `[obj] * 3` holds three references to the one `obj`.
- The element type is inferred from the LHS, or from the assignment slot when the LHS is empty / a free literal (`[] * n` / `[0] * n` against an annotated `T[]`).

#### Mutation methods

Beyond `push(v)`, mutable arrays expose:

| Method | Effect |
|---|---|
| `dst.push_all(src)` | Append every element of `src` (a `const T[]`) to `dst`, growing it. |
| `src.copy_to(src_start, dst, dst_start, len)` | Overlap-safe positional copy of `len` elements from `src[src_start..]` into the **existing** `dst[dst_start..]` region (`dst` must already be long enough — traps otherwise). |
| `arr.remove_last()` | Remove and return the last element as `T \| null` (`null` when empty). |
| `arr.clear()` | Drop every element (length 0; keeps capacity). |

All four reject a borrowed `const u8[]` view at runtime (mutation of a `bytes()` view is forbidden, as with `push`). `remove_last` returns the nullable through the usual `T | null` union, narrowed by `if x == null`.

### Tuples

Heterogeneous fixed-arity sequences. The bracketed form `[T1, T2, ...]` (≥ 2 elements; **1-tuples are forbidden**) introduces a tuple type. Tuples lower to anonymous structs at compile time — no extra runtime cost.

```vader
divmod :: fn(a: i32, b: i32) -> [i32, i32] { return [a / b, a % b] }

pair: [i32, string] = [42, "answer"]
println(pair.0)      // 42
println(pair.1)      // "answer"
```

- **Field access**: `t.0`, `t.1`, ... — numeric, in source order.
- **Disambiguation of seq literals** is contextual:
  - `[1, 2, 3]` → array (homogeneous, no annotation).
  - `[1, "x"]` → tuple (heterogeneous, no annotation).
  - With an annotation, the annotation wins: `xs: int[] = [1, 2, 3]` is array; `p: [int, string] = [1, "x"]` is tuple.
- **Tuples are not arrays**: `[i32, i32]` is not assignable to `i32[]` even though every element type unifies.

### Destructuring

Tuples can be destructured in `let` and in `match` arms. Nested patterns and `_` wildcards are supported.

```vader
[k, v] := key_value()                  // mutable bindings
[k, v] :: key_value()                  // immutable bindings
[a, _, c] := triple()                  // ignore middle slot
[[x, y], z] := nested_pair()           // nested destructure

match pair {
    [0, name] -> println("zero, ${name}")
    [n, _]    -> println("n = ${n}")
}
```

A tuple pattern whose every leaf is a binding or `_` is *irrefutable* — the compiler treats it as covering the scrutinee, no wildcard arm needed.

#### Spread destructuring (arrays only)

A `let`-binding may end with `...rest` to collect the tail of an array source into a fresh array. At most one rest, last position only.

```vader
arr :: [10, 20, 30, 40, 50]
[first, ...rest] := arr                // first: i32, rest: i32[] = [20,30,40,50]
[a, b, ...tail] := arr                 // a, b consume the head; tail = [30,40,50]
[_, _, ...short] := arr                // wildcards combine with rest
```

Tuple sources keep the existing exact-arity rule (`[a, b] := pair` requires the tuple to have exactly two elements) — `...rest` is array-specific because the result type only makes sense when the tail length is dynamic. T3001 fires on a non-array source or when `...rest` isn't the last element.

#### Destructuring via `Into<[...]>`

A `[...]` pattern applied to a value that is **neither a tuple nor an array** still destructures when the value's type implements `Into<[...]>` of matching arity. Each leaf binds to the corresponding element type of the target tuple.

```vader
for [k, v] in m { ... }                // m: MutableMap<K, V> yields Entry<K, V>
```

A `MutableMap` yields `Entry<K, V>` (a struct, not a tuple), and `std/collections` ships `Entry<K, V> implements Into<[K, V]>`, so the `for [k, v] in m` form (parser-desugared to `for e in m { let [k, v] := e; ... }`) binds `k: K`, `v: V`. The same rule applies to any user type with an `Into<[...]>` impl.

When the impl's `into` body is a tuple literal of plain field reads (`[self.key, self.value]`), the lowerer binds each leaf directly to the source field — no `into()` call and no transient tuple allocation. T3001 still fires when the source is a non-tuple, non-array type with no matching `Into<[...]>` impl.

### Structs

```vader
Point :: struct {
    x: f64
    y: f64
}

p :: Point { .x = 1.0, .y = 2.0 }
```

- Heap-allocated by default.
- `p2 := p` copies the **reference**, not the contents.
- `==` on two structs requires an `Equals` impl — there is no silent reference-identity default; comparing structs without one is **T3043** (`` `X` does not implement `Equals` ``). For value comparison, implement the `Equals` trait (or call a free function `equals(a, b)`).
- Field layout is **not guaranteed** (the compiler arranges fields freely).
- The user has no access to the layout (no `@offset_of`, no `unsafe_cast` in MVP).

Struct-literal field order does not have to match the declaration order — the compiler always emits in declaration order. Listing the same field twice raises `T3038`.

#### Field defaults

A field declaration may carry an initialiser used when the literal omits it. Defaults are checked once at the decl site against the (unsubstituted) field type; they are re-lowered at every literal site that uses them.

```vader
Settings :: struct {
    name:    string
    timeout: i32  = 30
    debug:   bool = false
}

s1 :: Settings { .name = "minimal" }                    // timeout=30, debug=false
s2 :: Settings { .name = "loud", .debug = true }        // timeout=30
s3 :: Settings { .name = "tight", .timeout = 5 }        // debug=false
```

Omitting a field that has neither a default nor a spread source raises `T3037`.

#### Spread (functional update)

`{ ...other, .field = v }` copies every field of `other` and overrides the listed ones. The spread source is evaluated **once** (bound to a synthetic local) regardless of how many fields inherit from it. Multiple spreads are allowed; the last one wins for any field not explicitly named.

```vader
base :: P { .a = 1, .b = 2, .c = 3 }
upd  :: P { ...base, .b = 99 }                          // a=1, b=99, c=3
mix  :: P { ...base, ...other, .b = 7 }                 // 'other' wins for non-named
```

The spread source's static type must be assignable to the literal's struct type.

#### Struct literals in `if` / `for` / `match` conditions

A `Foo { ... }` literal opens a `{` that would collide with the body brace of a control-flow statement. To keep the grammar unambiguous, struct literals are **not allowed at the top level** of the condition expression of `if`, `for`, and `match`. (Vader has no `while` keyword — `for cond { ... }` covers the same case.) Wrap in parentheses if needed:

```vader
// Error: ambiguous between struct literal and if-body
if Point { .x = 1 } == p {
    do_something()
}

// OK: parens disambiguate
if (Point { .x = 1 }) == p {
    do_something()
}
```

The rule applies to the **immediate** condition expression. Struct literals nested inside calls, ranges, or other parenthesised contexts inside the condition remain valid without an extra pair of parens.

### Unions

```vader
Result :: string | i32 | null

show :: fn(r: Result) -> string {
    match r {
        is string -> r
        is i32    -> r.to_string()
        is null   -> "(none)"
    }
}
```

- Ad-hoc union declared via `Name :: A | B | C`.
- `T | null` is the standard idiom for nullability.
- A union `A | B` satisfies a trait `T` if **and only if** both `A` and `B` implement it.
- Runtime representation: `(tag, payload)` (tagged sum). The compiler chooses the tag size.

#### Common-field access

When every variant of a union carries a field of the same name, the field is accessible directly on the union value — no outer `match` required:

```vader
Cat :: struct { name: string, age: i32 }
Dog :: struct { name: string, age: i32 }
Animal :: Cat | Dog

animal_name :: fn(a: Animal) -> string {
    return a.name        // OK — both Cat and Dog have a `name` field
}
```

The resolution applies to inline unions (`a: Cat | Dog`), to `::` type-aliases (`Animal :: Cat | Dog`), and to discriminated unions of structs/tuples. When the field types match across variants (`Cat.name: string`, `Dog.name: string`), the result is that shared type. When they diverge (`Cat.age: i32`, `Dog.age: i64`), the result is their union (`i32 | i64`) — the caller narrows with `match` to discriminate.

Lowering emits either a single same-offset read (when every variant stores the field at the same struct slot with the same resolved type) or a variant-dispatch cascade (`if a is Cat { (Cat) a.f } else if a is Dog { (Dog) a.f } else …`).

#### Flow-narrowing on `T | null`

The typechecker narrows an identifier's type inside an `if` branch whose condition discriminates against `null`:

```vader
greet :: fn(a: Animal | null) -> string {
    if a != null {
        return "hi ${a.name}"     // `a` narrowed to `Animal` here
    }
    return "no animal"
}

// `if x == null { return }` propagates the narrowing past the guard.
must_greet :: fn(a: Animal | null) -> string {
    if a == null { return "missing" }
    return a.name                  // `a` narrowed to `Animal` for the rest of the block
}
```

Mirrors the per-arm narrowing inside `match`. Today the rule fires on `BinaryExpr(.Eq | .Neq, ident, NullLit)` where `ident` is a `local` / `param` / `binding` whose static type is a union containing `null`; both orderings (`x == null` / `null == x`) and both branches (`if`-true and `else`) are covered. Divergent branches (then-block ends in `return` / `break` / `continue`) propagate the complement narrowing to the subsequent statements of the enclosing block.

### Enums

```vader
Direction :: enum {
    North,
    South,
    East,
    West,
}
```

An enum defines a **closed set of named variants** with no attached data. Each variant is a distinct constant of the enum's type.

#### Access

Full form: `EnumName.VariantName`.

```vader
d :: Direction.North
```

#### Dot-shorthand inference

When the expected type can be determined from context without ambiguity, the enum name may be omitted and replaced by a leading dot:

```vader
is_north :: fn(d: Direction) -> bool {
    return d == .North      // .North inferred as Direction.North
}

// Also in annotated declarations:
d: Direction = .East

// And in function calls:
move_towards(.South)        // parameter type is Direction

// And in return statements:
current_dir :: fn() -> Direction { return .West }
```

The shorthand `.Variant` is accepted in any position where the target enum type is unambiguous:
- Either operand of `==` / `!=` whose other operand has an enum type.
- A function argument whose declared parameter type is an enum.
- A `return` expression inside a function whose return type is an enum.
- The right-hand side of a `: EnumType =` declaration.

If the context is ambiguous (two different enum types in scope share a variant name), the compiler emits an error and requires the full `EnumName.Variant` form.

#### Pattern matching

Enum arms in a `match` use the dot-shorthand form. The `is` keyword is **not** used for enum variants (no type narrowing is needed — the type is already known):

```vader
match d {
    .North -> "north"
    .South -> "south"
    .East  -> "east"
    .West  -> "west"
}
```

Match on an enum scrutinee is **exhaustive**: every variant must appear as an arm, or a wildcard `_` arm must be present.

#### Equality

`==` and `!=` work on enum values and compare by variant identity. No explicit `Equals` impl is required.

#### Representation

##### Backing type

By default, variants are stored as `i32`. An optional `(type)` suffix selects any integer backing type:

```vader
Direction :: enum(u8) {
    North,
    South,
    East,
    West,
}
```

Allowed backing types: `i8`, `i16`, `i32`, `i64`, `u8`, `u16`, `u32`, `u64`, plus the word-width `isize` / `usize` (range-checked as `i64` / `u64`). Omitting the suffix is equivalent to `enum(i32)`.

##### Variant indices

By default, variants are numbered from `0` in declaration order. An explicit `= value` overrides the index; subsequent unspecified variants continue incrementing from that value:

```vader
Priority :: enum(u8) {
    Low    = 10,   // 10
    Medium,        // 11  (auto-increment)
    High   = 20,   // 20
    Critical,      // 21  (auto-increment)
}
```

Rules:
- The first variant defaults to `0` if no explicit value is given.
- Each subsequent unspecified variant is `previous + 1`.
- Duplicate indices are a compile error.
- The compiler verifies that every resolved index fits in the declared backing type (e.g. `u8` range `0..=255`). Exceeding the range is a compile error.

##### Memory model

Enum values are **value-typed** (copied on assignment, like `bool`), not heap-allocated. The exact integer representation is not directly observable from Vader code.

#### `Display`

Enums do not implement `Display` automatically. Implement the trait explicitly to use an enum in string interpolation:

```vader
Direction implements Display {
    to_string :: fn(self) -> string {
        match self {
            .North -> "North"
            .South -> "South"
            .East  -> "East"
            .West  -> "West"
        }
    }
}
```

---

### Pattern matching

```vader
match value {
    is i32 if value > 0 -> "positive"
    is i32              -> "negative or zero"
    is Point { x: 0, y } -> "Y axis at $y"
    is Point { x, y }    -> "($x, $y)"
    is null              -> "nothing"
    42                   -> "the answer"
    1 | 2 | 3            -> "small"
    'A'                  -> "letter A"
    "ok"                 -> "literal ok"
    rest                 -> "anything else, bound as `rest`"
    _                    -> "wildcard catch-all"
}
```

- `is Type` for type narrowing.
- **Literal-value patterns**: `42` / `'A'` / `"ok"` / `true` / `false` / `null` / `-1` directly match a scalar value. The literal's type is checked against the scrutinee (T3001 on mismatch) and the lowerer emits a `scrutinee == literal` predicate. Range-patterns (`'a'..='z' -> …`) are deferred.
- **Or-patterns**: pipe-separated alternatives in one arm — `.North | .South -> …` (enum variants), `1 | 2 | 3 -> …` (literals). The arm matches when *any* alternative does (lowered to `p1 || p2 || …`); each alternative is checked against the scrutinee, and every enum variant listed counts toward exhaustiveness. Alternatives are value-level and bind nothing. **Type tests don't need an or-pattern**: `is A | B -> …` is already a single `is` over the union type `A | B` (no parentheses required) — it narrows to `A | B` and covers both for exhaustiveness.
- Struct patterns with bindings and constraints.
- **Binding patterns**: a bare identifier `name -> …` matches every remaining value and binds it to `name`. Combined with `is`-narrowing of prior arms, the binding sees the *narrowed* type, not the full scrutinee — `match v { is null -> {}; pet -> use(pet) }` narrows `pet` to "scrutinee − null".
- Guards via `if cond`.
- Wildcard `_` — same flow-narrowing as binding arms.
- **Flow narrowing through wildcard / binding arms**: after one or more `is X` arms (without inner struct refinement), the subsequent `_` or `name` arm sees the scrutinee narrowed to `union − matched`. Lets `match p: Pet | null { is null -> "no"; _ -> p.name }` read the common field without a wrapping cast.
- **`is T` reachability** (`T3040`): an `is T` arm whose `T` can never be a value of the scrutinee's static type is rejected at compile time. `match p: Pet { is Bird -> … }` errors when `Bird` is not part of `Pet`'s union; same rule fires for `if x is T` expressions outside `match`. The check uses the symmetric `intersects(T, scrutinee)` predicate; unknowns (`Unresolved`, `TypeParam`) suppress cascading. **`==` / `!=` get the same check** — `if n: i32 == null` triggers T3040 with the same wording, replacing the misleading "no Eq impl" T3017. Use `is null` when you want the flow-narrowing; both forms work but `is` is the canonical idiom.
- **Exhaustiveness checked** by the compiler. For union scrutinees, every variant must be covered (or matched by a wildcard `_` / binding arm). For non-union scrutinees a wildcard or binding arm is required, since the compiler cannot enumerate all values of, say, `i32`.
- **Wildcard on a closed union, value position (`W0005`)**: a `match` that *produces a value* over a union / enum scrutinee whose catch-all is a bare `_` / binding arm earns a warning — the wildcard silences the exhaustiveness check, so a variant added later degrades silently into the catch-all instead of erroring. Enumerate every variant, or opt out explicitly with `@partial` (§ decorators) when "everything else does X" is intended. Statement matches (`_ -> {}`, no value) and non-union scrutinees (`i32` / `string` / …) are exempt. The warning does not fire on `@partial` matches.

### Variable bindings

Local bindings come in four shapes that share a single `LetStmt` AST node; the syntax is symmetric on the mutability axis (`::` ↔ `:`, `:=` ↔ `=`).

| Form                  | Mutability | Type        | Example                       |
|-----------------------|------------|-------------|-------------------------------|
| `name :: value`       | immutable  | inferred    | `pi :: 3.14`                  |
| `name := value`       | mutable    | inferred    | `total := 0`                  |
| `name: T: value`     | immutable  | typed       | `cap: usize: 1024`           |
| `name: T = value`     | mutable    | typed       | `count: u64 = 0`              |

The typed forms run the same bidirectional inference as the inferred forms — `T` is propagated as the expected type, so free numeric literals adopt it (`x: i64 = 42` ⇒ `42: i64`) and trait-typed slots trigger the implicit-coercion machinery (e.g. `T[]` → `Iterator<T>`, see §4 *Type coercion via `Into`*).

Reassignment uses `=` and is only valid on mutable bindings:

```vader
n := 0          // mutable, inferred i32
n = n + 1       // OK
k :: 0          // immutable
k = 1           // ERROR — cannot reassign immutable binding
```

Top-level constants follow the same pattern but are restricted to compile-time expressions (`PI :: 3.14`, `MAX: u64: 1_000_000`).

### Type inference

**Bidirectional** inference:

- Local: `x := 12` infers `x: i32`.
- Top-down: function signatures used to infer lambda arguments.
- No global Hindley-Milner (by simplicity choice).
- **Function signatures must be fully annotated** (no top-level inference).

### Casts

"Constructor-call" syntax:

```vader
x: i32 = 42
y: i64 = i64(x)            // widening cast, safe
z: u8  = u8(x)             // narrowing cast, panics in debug if overflow
```

**`char` ↔ integer**: `char` is a `u32` codepoint at the wire level, so casts between `char` and any integer type (`i32`, `u32`, `i64`, `u64`, `usize`, …) are allowed and reinterpret the bits with a tag change. Casts between `char` and float types are rejected — go through an integer first.

```vader
c   := 'A'
n   := u32(c)              // 65
back := char(n + u32(1))   // 'B'
```

For risky conversions (parsing), use explicit functions returning unions:

```vader
n: i32 | ParseError = parse_int("42")
```

### Generics

Type parameters are introduced with the angle-bracket `<T>` form at the declaration site (Java/C# style). They compile to a `TypeParam[]` slot on the underlying `FnDecl` / `StructDecl`; later references in the same scope are plain `IdentExpr` nodes that the resolver rebinds to the type-param symbol. Angle brackets are the only accepted form — there is no bracket `[T]` or paren `(T)` type-parameter syntax.

A type parameter may declare a **default** with `<T = Default>` (after the optional `: bound`, e.g. `<Rhs: Numeric = Self>`). When a generic is used with fewer arguments than it declares, the trailing parameters fill from their defaults; a `Self` default resolves to the implementing / receiver type. Defaults are currently honored on the **impl→trait-arg path** — `i32 implements Add` and a `where T: Add` bound both resolve `Add<Rhs = Self, Out = Self>` to `Add<Self, Self>` — which is what lets the arithmetic operator traits be generic without forcing every existing impl/bound to spell the params. Defaults on struct / fn / type-alias parameters parse but are not yet filled at their use sites (those instantiations error rather than default).

**Disambiguation rule (expression position).** Because `<` and `>` are also comparison operators, the parser uses a hard-precedence rule: after an `Ident`, a `<` opens a generic argument list **iff** the matching `>` is immediately followed by `(` (call) or `{` (struct literal). Any other follower leaves the `<` to Pratt as comparison. This is unambiguous in practice — `assert(v < 20, "msg")` reads as comparison because the `>` candidate is followed by `)`, not `(` or `{`.

For nested generics like `Box<Box<T>>`, the lexer's fused `>>` token is split on demand at the parser level — the first `>` closes the inner level, the second the outer.

**Generic functions**:

```vader
map :: fn<T, U>(items: T[], f: fn(T) -> U) -> U[] {
    result: U[] = []
    for x in items {
        result.push(f(x))
    }
    return result
}
```

**Generic structs**:

```vader
List :: struct<T> {
    items: T[]
    len: u32
}

list := List<i32> { .items = [1, 2, 3], .len = 3 }
```

**Constraints**. Inline bounds with `&` for trait intersection ("satisfies both"):

```vader
sort :: fn<T: Comparable>(items: T[]) {
    // ...
}

put :: fn<K: Hash & Equals, V>(self: MutableMap<K, V>, key: K, value: V) {
    // ...
}
```

`&` mirrors `|` (union) — `K: A | B` would mean K satisfies either, `K: A & B` means K satisfies both. **Only `&` (intersection) is in MVP scope**; `|` on bounds is post-MVP. A future predicate-bound escape hatch (`<T: @size_of <= 64>`-style; DESIGN_TYPE_FIRST.md §13 Layer 7d) is reserved for non-trait constraints once they land.

**Compile-time values** (post-MVP candidate; the fixed-size array surface itself is not designed yet — the example below uses placeholder syntax):

```vader
make_buffer :: fn<N: i32>() -> FixedArray<u8, N> { ... }
```

**Implementation**: monomorphization at compile time, driven by the comptime engine. Single specialization machinery.

**Bound enforcement and trait-method dispatch on type parameters**: both wired since Layer 7e. The typechecker:
- Resolves `key.hash()` inside a generic body where `key: K` and `K: Hash` to the trait method statically, then mono-substitutes it to the concrete type's impl member.
- At every call site of a generic fn, walks the call-site type-args against each type-param's angle-bracketed bound (`<T: Trait>`). Any concrete type lacking an explicit `T implements Trait` impl yields T3006 ("trait not satisfied").

**Limitations (MVP)**:
- **No "associated functions"** (static methods on a type) — `Type.method(args)` syntax is not parsed. Factory functions are written as free functions and called via UFCS or directly: `new_path("foo/bar")`, `MutableMap<K, V> { ... }` for struct-literal construction. Post-MVP candidate.

Numeric primitives carry `@intrinsic` `Add`/`Sub`/`Mul`/`Div` impls in `std/core` — `<T: Add>` succeeds for every primitive numeric type as well as for `string` (concat). `Equals` and `Hash` are carried by **every** primitive (`@intrinsic <prim> implements Equals` + `<prim> implements Hash` in `std/core`, covering `i8`…`usize`, `f32`/`f64`, `bool`, `char`, `string`), so `x.hash()` / `x.equals(y)` and `MutableMap` / `MutableSet` keying work for any primitive without a per-type opt-in.

### Traits

A trait defines a contract of methods (in practice, UFCS-callable functions on a type). Members are declared with the same `name :: fn(...)` shape as top-level functions — there is no separate `fn name(...)` syntax inside trait/impl bodies.

```vader
Display :: trait {
    to_string :: fn(self) -> string
}

u32 implements Display {
    to_string :: fn(self) -> string {
        // ... implementation
    }
}

print_it :: fn<T: Display>(x: T) {
    println(x.to_string())
}
```

- Declaration: `Name :: trait { ... }`.
- Implementation: `T implements Trait { ... }` (three forms — see below).
- A union satisfies a trait iff all its members satisfy it.
- Operator overloading via stdlib traits — see *Operator overloading* below.
- **`self` and `Self`**: inside a trait or impl, the first parameter conventionally named `self` carries an implicit `Self` type — no annotation required. `Self` refers to the type that implements the trait; in a `Foo implements Trait { … }` block, `Self = Foo`. Outside trait/impl context, `Self` is undefined (`T3023`).

#### Coherence — one impl per (type, trait)

A program may declare **at most one** `impl` of a given trait for a given
concrete receiver type. A second impl of the same `(type, trait, trait-args)`
triple raises **R2030** ("conflicting trait impl for the same type"). This
mirrors Rust's E0119 and is a sibling of the orphan rule (R2018) and the
`Into`-identity ban (T3039).

The check spans the **whole program, prelude included**. The `std/core`
prelude carries `i32 implements Display`, `<prim> implements Hash`, etc., and
those impls are in scope in every module, so a user re-`impl` of one —

```vader
i32 implements Display {           // ✗ R2030 — std/core already implements
    to_string :: fn(self) -> string = "n=${self}"
}
```

— is a **conflict**, not a silent shadow. (Before R2030 this compiled, with
dispatch order deciding which impl won — and `"${self}"` inside the override
could re-enter the override and recurse.) To attach behaviour to a primitive,
declare your own trait and `impl` that instead.

Only **fully-concrete** receivers are checked. Blanket / generic-receiver impls
(`T implements …`, `T[] implements …`, `Range<T> implements …`) have subtler
overlap rules and are not yet diagnosed.

#### Bounded-generic impls

When the impl introduces its own type parameters (with optional bounds), the `<T>` list follows the `implements` keyword — same position as it does after `fn` / `struct` / `trait`. This is the canonical place for any typeParam that's local to the impl (not borrowed from the for-type's struct head).

```vader
// Borrowing T from the struct head — no impl-level typeParams.
ArrayIterator<T> implements Iterator<T> {
    next :: fn(self) -> Yield<T> | null { /* … */ }
}

// Bounded blanket impl — Range<T> coerces into an Iterator when T
// satisfies both Comparable and Step.
Range<T> implements<T: Comparable & Step> Iterator<T> {
    next :: fn(self) -> Yield<T> | null { /* … */ }
}

// Blanket on a structural source (any array, any Display-bound type).
T[] implements<T>          Into<Iterator<T>> { /* … */ }
T   implements<T: Display> Into<string>      { /* … */ }
```

The angle-bracket list after `implements` introduces the typeParams *for the entire impl block* — the for-type, the trait args, and every method body resolve against them. Multi-bound (`<T: A & B>`) is identical to the bound grammar on fn / struct heads.

Compared to the borrowing form (`Foo<T> implements Trait<T>` without an impl-level `<T>`, where `T` aliases the struct's own type-param), the bounded form lets the impl declare *its own* `T` whose bounds are scoped to this block — the struct itself stays unbounded.

#### Trait composition

A trait can compose other traits — i.e. require its implementor to satisfy each of them — through one of two declaration shapes:

```vader
// Pure alias — Numeric IS Add & Sub & Mul; no own methods.
Numeric :: trait<T> = Add & Sub & Mul

// With own methods — Hashable requires Hash and Equals, plus declares its own.
Hashable :: trait<T> : Hash & Equals {
    fingerprint :: fn(self: T) -> u64
}
```

The `=` form has no body; the `:` form has a body for the additional methods. A single trait reference is also valid (`Foo :: trait<T> = Bar` aliases Bar). The composition expression is a type-position `&`-chain, parsed with the same precedence as type intersection; `T: Foo` bound checking transitively applies the composed traits.

#### Method dispatch on trait values

A receiver typed as a trait dispatches **virtually** at runtime:

```vader
report :: fn(e: Error) -> string {
    return e.message()       // dispatches on `e`'s actual struct tag
}
```

The lowerer synthesises an `is StructA -> StructA_method(...)` chain over every impl of the trait that monomorphization has materialised. Non-generic impls contribute one arm each; generic impls (`Foo<T> implements Trait { ... }`) contribute one arm per observed concrete `(struct, args)` pair, since each instance has a distinct runtime tag (`is Foo<i32>`, `is Foo<string>`, …). Trait args on the receiver itself are substituted into the method's signature, so e.g. `it: Iterator<i32>; it.next()` returns `Yield<i32> | null` — not the unsubstituted `Yield<T> | null`. Primitive impls remain skipped (the dispatch chain assumes struct-tagged boxes).

Inside a generic body, `key.method()` where `key: T` and `T: Trait` resolves at typecheck and is monomorphised statically — each call site gets a direct call to the concrete impl member after substitution. No runtime dispatch.

#### Single-method trait sugar (SAM)

When a trait has **exactly one method**, the implementation may omit the redundant `name :: fn(...) -> RetType` line and write the body directly. The compiler synthesises the signature from the trait declaration; parameter names (`self`, `other`, …) come from the trait and are in scope of the body — no redeclaration required.

```vader
// Arrow form — single-expression body.
i32   implements Hash   -> u64(self)
i32   implements Equals -> self == other

// With generic trait args.
Tutu  implements Toto<i32, i64> -> i64(self + other)

// Block form — multi-statement body.
string implements Hash {
    h: u64 = 14695981039346656037
    n: usize = self.bytes().len()
    i: usize = 0
    for i < n {
        h = (h ^ u64(self[i])) * 1099511628211
        i = i + 1
    }
    return h
}

// Classic form — required for traits with two or more methods.
ArrayIterator<T> implements Iterator<T> {
    next :: fn(self) -> Yield<T> | null { ... }
}
```

- Detection: the impl body starts with `->` (arrow), or with `{` whose first significant token is **not** the start of a member declaration (`name :: fn`). Anything else inside the braces is treated as a SAM block body.
- The classic form (`{ name :: fn(...) ... }`) remains valid and is **required** for multi-method traits.
- "Single-method" here means a single *required* (body-less) method; a trait can declare additional methods with default bodies (see *Default methods* below) and still accept the SAM short forms.
- `R2016` is emitted when the short forms are used on a trait with 0 or ≥ 2 required methods.

#### Default methods

A trait method may carry a body:

```vader
Equals :: trait {
    equals     :: fn(self, other: Self) -> bool
    not_equals :: fn(self, other: Self) -> bool { return !self.equals(other) }
}
```

Any impl that doesn't override `not_equals` automatically inherits the body
above — the resolver clones the trait method's body into the impl at
declaration time, with `Self → forType` substituted (and trait type-params
substituted by impl trait-args). References inside the body to other trait
methods (`self.equals(other)`) resolve through UFCS against the impl scope,
so they pick up the impl's own member when the user provides one.

```vader
Money implements Equals -> self.amount == other.amount
// Money.not_equals exists implicitly, derived from the cloned default.
```

Stdlib traits that ship with default methods:
- `Equals.not_equals` (derived from `equals`).
- `Comparable.lt` / `.lte` / `.gt` / `.gte` (derived from `compare`).

#### Operator overloading

Built-in operators dispatch through stdlib traits when the operand types are not primitive numerics (or when `==` / `<` are applied to user types).

| Operator        | Trait              | Method                                      |
|-----------------|--------------------|---------------------------------------------|
| `a + b`         | `Add<Rhs = Self, Out = Self>` | `add :: fn(self, other: Rhs) -> Out`        |
| `a - b`         | `Sub<Rhs = Self, Out = Self>` | `sub :: fn(self, other: Rhs) -> Out`        |
| `a * b`         | `Mul<Rhs = Self, Out = Self>` | `mul :: fn(self, other: Rhs) -> Out`        |
| `a / b`         | `Div<Rhs = Self, Out = Self>` | `div :: fn(self, other: Rhs) -> Out`        |
| `a % b`         | `Rem<Rhs = Self, Out = Self>` | `rem :: fn(self, other: Rhs) -> Out`        |
| `a == b`        | `Equals`           | `equals :: fn(self, other: Self) -> bool`   |
| `a < b` / `<=` / `>` / `>=` | `Comparable` | `compare :: fn(self, other: Self) -> i32` |
| `a[i]`          | `Index<I, T>`      | `at :: fn(self, i: I) -> T`                 |
| `a[i] = v`      | `IndexSet<I, T>`   | `set_at :: fn(self, i: I, v: T)`            |
| `v in a`        | `Contains<T>`      | `contains :: fn(self, v: T) -> bool`        |

Compound assignments (`+=`, `-=`, `*=`, `/=`, `%=`) desugar to `lhs = lhs <op> rhs` at parse time, so they reuse the corresponding trait dispatch. Because the result is rebound to `lhs`, a compound assignment requires the operator's `Out` to be assignable to `lhs`'s type — always true in the homogeneous `Out = Self` case; a heterogeneous `Out` (e.g. `Instant - Instant -> Duration`) simply can't be used with the compound form.

Resolution rule for **arithmetic** operators (`+ - * / %`):
1. If both operands are primitive numerics, use the built-in op (current behaviour).
2. `string + string` is a built-in op (`string.concat`); `string implements Add` exists for SPEC completeness and is also reachable via UFCS — the compiler routes both paths to the same op (see §12 op-level intrinsics).
3. Otherwise, look up the matching `Add`/`Sub`/`Mul`/`Div`/`Rem` impl on the left operand's type; the right operand must be assignable to that impl's `Rhs`, and the result type is the impl's `Out`. `Rhs` and `Out` default to `Self`, so the homogeneous case needs only `implements Add`; a heterogeneous operator (e.g. `Instant implements Add<Duration, Instant>`) spells them. The defaults fill at impl materialization, so existing `i32 implements Add` and `where T: Add` keep meaning `Add<Self, Self>`.
4. If no impl matches, T3017.

Resolution rule for **equality** (`==` / `!=`):
1. Primitive operands (numerics, strings, chars, bools, null) use the built-in equality op.
2. User-struct operands of the same type look up the `Equals` impl and dispatch through `equals` when one exists; **without an impl it is T3043** (`` `X` does not implement `Equals` ``). `==` on a struct that never opted into value equality is almost always a bug, so it is rejected rather than silently comparing references.
3. Mismatched types are T3017.

Resolution rule for **ordering** (`< <= > >=`):
1. Primitive numerics, strings, and chars use the built-in comparison ops.
2. User-struct operands look up the `Comparable` impl; the lowerer rewrites `a < b` to `compare(a, b) < 0` (and analogously for the other three operators) over the i32 result.
3. If no impl matches, **T3043** (`` `X` does not implement `Comparable` ``).

**T3043** is the shared "operator's trait is not implemented" error — it names the missing trait (`Equals` for `==`/`!=`, `Comparable` for `< <= > >=`, `Contains` for `in`) so the fix is obvious. It is distinct from T3017, which stays for plain operand-type mismatches (e.g. `i32 && bool`, mismatched numeric widths). (Arithmetic `+ - * / %` on a type without the matching `Add`/… impl still reports T3017 for now.)

Index access (`a[i]`) and `in` follow the same fallback: built-in array / range first, then trait dispatch through `Index<I, T>::at` / `Contains<T>::contains` — the trait path covers struct receivers AND primitives (`string implements Index<usize, char>` enables `s[i]` without importing anything). Index assignment (`a[i] = v`) dispatches through `IndexSet<I, T>::set_at`.

### Nullability

No implicit `null`. To express absence, use a union:

```vader
find_user :: fn(id: u32) -> User | null {
    // ...
}

u := find_user(42)
match u {
    is User -> println("found ${u.name}")
    is null -> println("not found")
}
```

### Equality

| Type | Default `==` behavior |
|------|----------------------|
| Primitives (numeric, bool, char) | Bit-for-bit |
| `string` | Structural (compares contents) |
| Struct, array | **Reference identity** |
| Type with `impl Equals` | Delegated to `Equals.equals` |

To compare two structs structurally, implement `Equals` or call `equals(a, b)`.

---

## 5. Variables and Bindings

### Binding forms

Mutability is chosen by the declaration operator; an optional `: T` annotation pins the type. The four declaration forms and the reassignment form:

- **`x :: <expr>`**: **immutable**, type inferred. The binding cannot be reassigned.
- **`x := <expr>`**: **mutable**, type inferred. The binding can be reassigned via `=`.
- **`x: T: <expr>`**: **immutable**, typed (`:` separator before the value).
- **`x: T = <expr>`**: **mutable**, typed (`=` separator before the value).
- **`x = <expr>`**: reassignment of an existing mutable variable.

So with a type annotation the separator decides mutability: `:` → immutable, `=` → mutable.

### Mutability = binding only

`::` freezes the binding, not the contents. If `p :: Point { ... }`, you cannot `p = otherPoint`, but `p.x = 5` is allowed.

For deep immutability of collections, use **stdlib convention**:
- raw `T[]` arrays are mutable (`arr.push`, `arr[i] = v`)
- read-only `List<T>` / `Map<K, V>` / `Set<T>` will pair with mutable variants when implemented (post-MVP — currently struct stubs in `std/collections`)

### Explicit type annotations

```vader
x: i64 = 42
buffer: u8[] = []
name: string | null = null
```

The annotation `: T` is used when inference cannot decide or to clarify intent. Note these all use the `=` separator, so they are **mutable** typed bindings; swap `=` for `:` (`x: i64: 42`) for the immutable typed form.

### Scoping

- Lexical, function and block.
- Shadowing **allowed** in a sub-block.
- No hoisting.

---

## 6. Functions

### Declaration

```vader
add :: fn(a: i32, b: i32) -> i32 {
    return a + b   // explicit
}

double :: fn(x: i32) -> i32 {
    x * 2          // implicit (last expression)
}

// Functions returning nothing omit the arrow entirely.
log :: fn(message: string) {
    println(message)
}

// Expression-body form — `= expr` replaces a single-expression brace body.
add_one :: fn(x: i32) -> i32 = x + 1
```

`return` is valid anywhere. If the last expression of a block is an expression and its type matches the return type, `return` is optional. When the whole body is a single expression, prefer the expression-body form `fn(...) -> T = expr` (no braces, no `return`) — it is the idiomatic shape across the stdlib and compiler tree.

**No-return functions** drop the `-> void` annotation. Internally the compiler still has a unit/void type, but it is not user-facing — `void` is **not** a name available in source code. Function-pointer types that produce no value drop the arrow likewise: `callback: fn()` instead of `callback: fn() -> void`.

### `main` entry point

The program entry is a fn called `main` declared at module scope. It accepts exactly one of two shapes (T3033 otherwise):

```vader
main :: fn() -> i32                 // ignore argv
main :: fn(argv: string[]) -> i32   // receive process args
```

`argv[0]` is implementation-defined: the script path under `vader run`, the binary path under a native build. User-supplied args start at `argv[1]`.

### Default parameter values

```vader
greet :: fn(name: string, prefix: string = "Hello") -> string {
    return "${prefix}, ${name}"
}

greet("Alice")                    // "Hello, Alice"
greet("Bob", "Hi")                // "Hi, Bob"
greet("Eve", prefix = "Hello")    // "Hello, Eve" (named parameter)
```

### Named arguments at call site

`f(a = 1, b = 2)` is always allowed.

### Variadics

```vader
sum :: fn(...nums: i32[]) -> i32 {
    total := 0
    for n in nums { total = total + n }
    return total
}

sum(1, 2, 3, 4)
```

### Closures / lambdas

Lambdas use the form `params -> body`. The `->` is the mandatory separator between parameters and body; the `fn` keyword is **not used** on lambdas (it remains for declarations and function types — see *Function values* below). As a leniency the parser also accepts an explicit `fn(params) -> R { body }` expression directly in value position — an anonymous function literal, semantically identical to the `->` form — but `params -> body` is the canonical lambda syntax and the only one used across the stdlib and the compiler. (This is distinct from `name :: fn(...) { ... }`, which is a named function *declaration*, top-level or local — see below.)

```vader
// Single param — parens optional, expression body
items.map(x -> x * 2)
items.map((x) -> x * 2)

// Single param typed (parens required for the `:` annotation)
items.map((x: i32) -> x * 2)

// Multi-param (parens required)
arr.fold(0, (acc, x) -> acc + x)

// No-arg (empty parens required)
btn.on_click(() -> count = count + 1)

// Multi-statement via block-expr
items.map(x -> {
    tmp :: x * x
    tmp + 1
})
```

**No explicit return-type slot on lambdas.** The return type is always inferred — from the call-site signature, an enclosing struct field's fn-type, a typed `let`, or from the body itself. If you need to annotate the return type explicitly, declare a named function instead:

```vader
inc :: fn(x: i32) -> i32 { x + 1 }
items.map(inc)
```

The `name :: fn(...) -> R { ... }` form is a regular function declaration (top-level **or** local to a fn body), not a value-position lambda. Parameter and return-type annotations are required for top-level fns (see §4 inference rules).

Closures capture their environment **by reference** (consistent with Vader's reference-semantics model for non-primitive values). Captured locals are heap-promoted into single-slot cells at the lowering pass: the cell lives on the GC heap, the binding becomes a pointer to it, and every closure that mentions the variable shares the same cell. This is what makes mutation visible across closures (a counter built via `n := 0; inc :: fn() { n = n + 1 }; get :: fn() -> i32 { n }` works as expected). Lifting itself is transparent: the closure value is a `(code, env)` fat pointer where `code` points to a synthesised top-level fn taking the env as its first parameter, and `env` is a heap-allocated struct holding refs to the captured cells.

### Function values

The function-type form `fn(T1, T2, ...) -> R` (or `fn(T1, T2, ...)` for void return) is a **first-class type**: it can appear anywhere a type is allowed — fn parameters, struct fields, array elements, locals, return types. **The `fn` keyword is retained on function types** (it's the visual sentinel that says "this is a callable type"). A function name used outside of an immediate call yields a function value:

```vader
add :: fn(a: i32, b: i32) -> i32 { return a + b }

main :: fn() -> i32 {
    f := add               // f: fn(i32, i32) -> i32 (inferred from `add`)
    return f(2, 3)         // indirect call — same syntax as direct
}
```

A lambda flows into a fn-type slot without any wrapping:

```vader
cb: fn(i32) -> i32 = x -> x + 1
println(cb(41))                                       // 42

Handler :: struct { cb: fn(i32) -> i32 }
h :: Handler { .cb = (x) -> x * 2 }
println(h.cb(21))                                     // 42
```

Runtime representation: a fat pointer `{ code, env }`. Non-capturing globals carry `env = NULL` and route through a small generated trampoline so the same indirect-call path handles both global function refs and closures.

### UFCS (Uniform Function Call Syntax)

```vader
plus :: fn(this: i32, other: i32) -> i32 {
    return this + other
}

// Equivalent calls:
plus(2, 3)
2.plus(3)
```

`a.f(b)` is desugared to `f(a, b)` at compile time. There are **no methods** in Vader, only free functions + UFCS.

UFCS dispatch works against five shapes of receiver–first-param relation, ranked weakest-wins-only-on-tie:
1. **Concrete match**: the receiver's static type is assignable to the first param. `s.starts_with(p)` where `starts_with :: fn(s: string, prefix: string) -> bool`.
2. **Symbolic match**: the receiver and the first param share a struct/trait symbol but differ in their type-args (e.g. `MutableList<i32>` against `fn<T>(self: MutableList<T>)`). The generic-fn-dispatch path closes over the type-args at the call site.
3. **Trait-typed first param**: when the first param has trait type `Trait<T>` and the receiver implements that trait, UFCS dispatches to it. `source.chars().filter(is_bf_char)` resolves through `std/iter.filter :: fn<T>(it: Iterator<T>, pred) -> T[]` because `StringChars` implements `Iterator<char>`. Trait-typeparam unification happens through `unifyTraitParamWithConcrete`.
4. **Union receivers**: `value.method()` on a union-typed `value` falls through to free-fn UFCS when no variant carries a struct field by that name. The first-param type can be the *union itself* (`fn read_i32(v: Value, …)`) — receiver and param match directly.
5. **`Into<Target>` last-resort coercion**: strictly weaker than every other rank; only fires when no direct candidate exists.

Specifically — a partial match where some variants of a union scrutinee carry the field and others don't still raises `T3009`; the fall-through to UFCS only triggers when *no* variant has the field at all.

#### Import requirement

UFCS resolution obeys the **same import rule as a bare call**: `x.foo()` resolves only against free functions whose owning module is reachable in the program (transitively `import`ed), exactly as `foo(x)` would. `std/core` (the implicit prelude, §11) is the sole exemption — its exports are always in scope, so `s.len()`, `bs.bytes_to_string()`, `x.hash()` work with no import. A `x.foo()` whose only candidate lives in a *non-imported* module is a **compile error** (`T3008` / `T3009`), not a silently-dropped call. This keeps the type-checker's UFCS visibility aligned with the lowerer's: both dispatch against the same reachable module set, so a method that type-checks always lowers to a real call. (Historically the typer carried hardcoded per-primitive method tables that bypassed this, letting `s.split()` type-check without `import "std/string"` and then mis-compile; those tables were removed so primitive/array methods resolve uniformly through trait impls + free-fn UFCS.)

#### Function overloading

Two free functions with the same name **may coexist in the same module** when they differ in the type of their **first parameter** (the receiver). The resolver dispatches based on the receiver's type at the call site.

```vader
size :: fn(self: Path) -> i32 { ... }
size :: fn<K, V>(self: MutableMap<K, V>) -> usize { ... }

p.size()            // resolves to the Path version
m.size()            // resolves to the MutableMap version
```

Rules:
- Overload candidates must differ in their first parameter type. Differing only on later parameters is **not** an overload (post-MVP — see TODO).
- Two functions with the same name **and the same full signature** (identical parameter types) in one module are a **redefinition**, not an overload — rejected at declaration with **T3053**, independent of whether they are ever called (so it catches an uncalled entry like `main`). A module spans **every file of its directory**, so this also fires when the same function is declared in two sibling files — e.g. two single-file programs sharing a folder, each with its own `main`.
- Type-param receivers (`fn<T>(self: T)`) are wildcards and conflict with every concrete-receiver overload of the same name.
- Resolution is performed at typecheck after the receiver type is known. Errors out with `R2004` if two candidates match.
- A **local fn coexists with a same-named imported fn** as overloads. The local fn takes the primary slot in the module's symbol table (so unqualified references pick it), and the imported fn stays reachable through UFCS dispatch by receiver type. So `std/path` legally both imports `is_empty` from `std/string` and exports its own `is_empty(self: Path)` — `self.repr.is_empty()` picks the string version inside the module while `p.is_empty()` at a call site picks the Path version.

### Visibility

- **Private by default**. Top-level decls are visible only inside their **module** (every `.vader` file declares its module via `module "..."` — see §11) unless explicitly exported.
- **`export`** prefix to make a symbol visible across module boundaries.
- The top-level `main` function is **always public** — the resolver promotes its visibility to `public` regardless of whether the source carries the `export` keyword.

```vader
helper :: fn(x: i32) -> i32 {
    // visible to other files in the same module, invisible outside
}

export api :: fn(x: i32) -> i32 {
    // visible everywhere a consumer imports this module
}
```

Note: the `export` keyword (visibility) is distinct from the `@export` decorator
(ABI exposure to the host — see §12). A function may be both.

#### Exported declarations cannot expose a non-exported type

An `export`ed declaration must not name a non-exported type in its public
surface — a caller in another module would receive a value of a type it cannot
name. Mirrors Rust's E0446 (`private_interfaces`). The compiler rejects this
with **T3052**:

```vader
Secret :: struct { value: i32 }          // private to this module

export reveal :: fn() -> Secret { ... }   // T3052 — Secret is not exported
```

To fix, export the type or make the declaration private. The check currently
covers fn **return types**; coverage of parameter types, exported struct field
types, and type-alias right-hand sides is planned.

---

## 7. Control Flow

### `if` / `else` (expression)

```vader
x :: if b > 2 { 2 } else { 3 }

if cond {
    // ...
} else if other {
    // ...
} else {
    // ...
}
```

`if` is always an expression. When used as a value, all branches must return a compatible type.

### `match` (expression)

```vader
result :: match value {
    is i32 if value > 0 -> "pos"
    is i32              -> "non-pos"
    is string           -> "str: $value"
    42                  -> "literal int"
    'A'                 -> "literal char"
    _                   -> "?"
}
```

Exhaustive match on unions, checked at compile time. See §4 *Pattern matching* for the full grammar — `is`-narrowing, literal patterns, binding patterns with flow narrowing, struct refinement, guards, and the `T3040` reachability rule.

### `for` (universal loop)

```vader
// Exclusive range
for i in 0..<10 {
    println("$i")
}

// Inclusive range
for i in 0..=10 { ... }

// Iterate over a collection (built-in array, Iterator, or an Into<Iterator> type)
for item in items {
    println(item)
}

// Tuple-destructuring binding — each yielded tuple is unpacked into the names.
for [key, value] in pairs {
    println("${key} = ${value}")
}

// While-like
for cond {
    // ...
}

// Infinite
for {
    if exit_condition { break }
}

// Iter without a binding (sugar for `for _ in <iter>`)
for 0..<GENERATIONS {
    step()
}
```

The single-expression form `for <expr> { body }` is dispatched by the type of `<expr>`:
- `bool` — true while-loop, body runs while the condition holds.
- iterable (built-in array, `Iterator<T>`, `Range`, …) — equivalent to `for _ in <expr>`, body runs once per element with the value discarded.

`T3019` fires when the expression is neither — the diagnostic catches a misplaced struct cond as well as a non-`Iterator` user type.

The iteration form `for x in expr` accepts three shapes for `expr`:
1. A built-in array `T[]` — auto-wrapped in `ArrayIterator<T>`.
2. A value of type `Iterator<T>` — used directly. Two dispatch flavours:
   - **Concrete iter** (`Range<T>`, `ArrayIterator<T>`, a user struct implementing `Iterator<T>`) — the `next()` call resolves statically against the impl-method.
   - **Trait-typed iter** (`Iterator<T>` itself, e.g. a fn param `fn count<T>(it: Iterator<T>)`) — the `next()` call dispatches through the lowerer-synthesised `is StructA -> StructA_next(...)` chain over every materialised impl (see *Method dispatch on trait values* in §4). Lets generic fns drive `for x in it { … }` against any concrete iterator the caller supplies.
3. A value implementing `Into<Iterator<T>>` — the for-in lowerer inserts `.into()` to obtain the iterator, then drives the loop over it.

Raw `T[]` arrays are auto-wrapped in `ArrayIterator<T>` (via the shipped `T[] implements Into<Iterator<T>>` impl in `std/core`), and `Range` (`0..<10`) iterates directly. User collections opt in by implementing `Into<Iterator<T>>` so `for x in coll { ... }` works without an explicit `.into()`. There is no separate `Iterable` trait today (see the planned note below).

The same auto-wrap fires at any *concrete* `Iterator<T>` slot — function arguments, `return` expressions, and typed `let` bindings — so `T[]` flows transparently:

```vader
walk :: fn(it: Iterator<i32>) -> i32 { ... }
walk([10, 20, 30])                            // call-arg coercion
fold :: fn() -> Iterator<i32> { return [1, 2, 3] }   // return coercion
buf: Iterator<i32> : [4, 5, 6]                // typed-let coercion
```

The coercion is gated on **canonical symbol identity** of `std/core::Iterator`; a user-defined trait that happens to be named `Iterator` is left alone. It does **not** fire on a generic `Iterator<T>` parameter — type-arg inference can't bind `T` from a `T[]` argument across the widening, so combinators that take `Iterator<T>` still need an explicit `ArrayIterator<T> { ... }` wrap (or an array-driven overload). Concrete trait-instance receivers (`Iterator<i32>`, `Iterator<string>`, …) are unaffected.

```vader
// Planned — not yet exported from std/core. Today user types iterate
// via a direct `Iterator<T>` impl on the collection itself.
Iterable :: trait<T> {
    iter :: fn(self) -> Iterator<T>
}
```

### Labeled `break` / `continue`

```vader
outer: for i in 0..<10 {
    for j in 0..<10 {
        if (i + j > 12) {
            break outer
        }
    }
}
```

Without a label, `break`/`continue` act on the innermost loop.

### `defer`

Block-scoped, executed when leaving the block where it was written:

```vader
process :: fn(path: string) -> string | Error {
    file := open(path)?
    defer close(file)

    {
        tmp := allocate_temp()
        defer free(tmp)
        // tmp freed at the end of this sub-block
    }

    // file closed at the end of the function
    return read_all(file)?
}
```

### `?` operator (try)

Postfix, propagates the error:

```vader
content :: read_file("a.txt")?
// if read_file returns string | Error:
//   - if Error: the current function returns that Error
//   - else: content receives the string

// Chainable
first_line :: read_file("a.txt")?.lines()?.first()?
```

`expr?` is meant to be used only inside a function whose return type is itself a union including an `Error`. This contract is **not yet enforced** by the typechecker — there is no diagnostic today for a `?` in a non-`Error`-returning function.

---

## 8. Memory Model

### GC

All non-primitive values (struct, array, string buffer contents, future stdlib types) are allocated on the **GC-managed heap**.

### GC backends

- **Native (C)**: hand-written **generational Cheney copying GC** (stop-the-world), in C, linked into the binary. Two generations:
  - **Young** (Eden + Survivor): two 4 MB semi-spaces collected by minor cycles. Every allocation lands here.
  - **Old**: two 16 MB semi-spaces collected by major cycles. Objects that survive `VADER_TENURE_AGE` (=2) minors are promoted in.

  Both generations use the same Cheney semi-space algorithm. A **card table** (one byte per 512 bytes of old) tracks cross-generation pointers: the C emitter inserts a `VADER_WRITE_BARRIER` after every store of a pointer field into a heap object, marking the card if the target lives in old. Minor cycles use the shadow stack plus marked cards as roots — clean cards are skipped wholesale. Major cycles run a preliminary minor to drain young, then Cheney-collect old and reset the card table. Roots are enumerated **precisely** via the shadow stack: every emitted C function pushes a `vader_gc_frame_t` chained through `prev` containing the addresses of its ref-typed locals, popped on return. Per-type pointer maps emitted by the compiler tell the scanner where the heap pointers live inside each object.
- **WASM**: uses the `(ref struct)`, `(ref array)`, `anyref` types of the WASM GC proposal (the host runtime — wasmtime / V8 — performs GC).

### Storage semantics

- Primitives (`i32`, `f64`, `bool`, etc.): value, copied on assignment.
- `string`: fat value `(ptr, len)`, copied on assignment, immutable shared content.
- Structs, arrays: heap-allocated, manipulated via implicit references (the user does not see pointers).

### No visible pointers

No `&`, `*`, or "pointer" type exposed in MVP. Memory management is entirely implicit (except via explicit allocator APIs for perf-critical zones, post-MVP).

### Escape analysis

The spec **allows** the compiler to allocate a struct on the stack if analysis proves it does not escape, but **does not require** it in MVP. This is a transparent optimization the user never observes.

### Explicit allocators (post-MVP)

API for perf-critical zones. Allows allocating into an arena, a buffer, etc., without breaking the GC model. To be specified when needed.

### Finalizers

**None**. Non-memory resources (files, sockets, handles) must be released explicitly via `defer`.

```vader
file := open("a.txt")?
defer close(file)
```

---

## 9. Strings

### Literal syntax

```vader
s1 :: "Hello, World!"                 // simple string
s2 :: "Hello, $name"                  // simple variable interpolation
s3 :: "${prefix}_value_${suffix}"     // expression interpolation
s4 :: r"C:\Windows\System32"          // raw string, no interpolation
s5 :: """
line 1
line 2 with ${var}
"""                                   // multiline with interpolation
```

### Escapes

`\n`, `\t`, `\r`, `\\`, `\"`, `\$` (literal dollar), `\0`, `\u{1F600}` (codepoint).

### Compile-time verification

Interpolation expressions `${...}` are parsed and **type-checked at compile time**. Errors caught:

- Variable does not exist
- Type incompatible with `Display`
- Malformed expression

Interpolation is **desugared** into a string-concatenation chain. Each `${expr}` segment is rendered to a string through its `Display.to_string` (string-typed segments pass straight through), and the literal pieces + rendered segments are joined uniformly: a short interpolation folds to `concat2` / `concat3` / `concat4`, a longer one to a `StringBuilder` chain. There is no primitive vs. non-primitive split — every non-string segment goes through `to_string`, so interpolation honours user `Display` impls on any type.

### `Display` trait

All primitives implement `Display`. User types must impl explicitly:

```vader
Point implements Display {
    to_string :: fn(self) -> string {
        return "(${self.x}, ${self.y})"
    }
}
```

---

## 10. Errors

### "Errors as values" model

Errors are ordinary values, returned in a union with the success type.

```vader
read_file :: fn(path: string) -> string | IOError {
    // ...
}
```

### Error unions

A fallible function returns an explicit union of its success type and one or
more error types — e.g. `fn parse_int(s: string) -> i32 | ParseError` or, when
the error is the generic stdlib `Error`, `fn read_file(p: string) -> string |
Error`. There is no postfix-`!` shorthand: write the union out. The `?`
operator (below) propagates any member implementing the `Error` trait.

### `Error` trait

```vader
Error :: trait {
    message :: fn(self) -> string
}
```

Any type implementing `Error` may be returned in an error union (e.g. `T | Error`). The stdlib provides concrete errors: `IOError`, `ParseError`, etc.

### `?` operator

Postfix, propagates the error if present:

```vader
process :: fn(path: string) -> string | Error {
    raw    := read_file(path)?     // if Error: return the Error
    parsed := parse(raw)?
    return parsed
}
```

### Explicit match

When errors must be handled locally:

```vader
r :: read_file("a.txt")
match r {
    is string -> println("got: ${r}")
    is Error  -> println("error: ${r.message()}")    // virtual dispatch
}
```

---

## 11. Modules

### Module declaration

Every `.vader` file declares its module on its first non-trivial line via the `module` keyword followed by a double-quoted string literal:

```vader
#!/usr/bin/env vader            // optional shebang
// optional leading comments

module "std/string"             // mandatory
```

Rules:

- Exactly one `module` declaration per file. Repeating it is a compile error.
- Must appear before any `import`, `export`, or top-level decl. Only shebang and comments may precede it.
- Missing declaration is a compile error (no implicit module name).
- The REPL injects `module "main"` implicitly so REPL fragments don't need to type it.

### Module name grammar

```
module-name ::= segment ('/' segment)*
segment     ::= [a-z] [a-z0-9_]*
```

Examples accepted: `main`, `std/string`, `std/string/utf8`, `vader/lexer`, `my_app/util_2`.

Examples rejected: `Std/String` (uppercase), `std/1string` (segment starts with digit), `std//string` (empty segment), `std/string/` (trailing slash), `./relative` (special chars).

The `/` inside a name is a regular character; segment-level parsing exists only for the grammar check above.

### Granularity and identity

Module identity is **not** derived from the filesystem. The filesystem is the storage layer; the `module "..."` declaration is the identity. This implies:

- A folder contains **at most one** module: all `.vader` files in the same folder must declare the same module name. Mixed declarations are a scan-time error.
- A folder may contain zero `.vader` files (skipped silently by the scan).
- Across every scoped source root (project whitelist + stdlib + future deps), each module name appears in **exactly one** folder. Two folders declaring the same module name is a compile error.
- Sub-modules are **independent**: `std/string` and `std/string/utf8` are unrelated logical modules. Their shared prefix has no semantics — no parent-child relationship, no implicit re-export, no automatic visibility.

### Imports

```vader
import "std/string"                              // pure namespace import
str :: import "std/string"                       // named namespace import
import "std/string" { trim }                     // destructured import
str :: import "std/string" { trim, chars }       // scoped namespace import
```

A namespace import always names its binding explicitly (`name :: import "..."`) — there is no implicit last-segment binding and no `as` suffix. The destructure form (`import "..." { a, b }`) pulls names into the importing module's top-level scope. The combined form (`name :: import "..." { a, b, c }`) is **scoped**: only the listed names are reachable through `name.X`; the rest of the target module is hidden, and the listed names are NOT also pulled into top-level scope.

#### Resolution rules

- The string passed to `import` is **strictly** a module name, looked up in the discovered index. No filesystem fallback.
- Relative paths (`./foo`, `../foo`) and bareword filesystem walks are not part of the language.
- Self-import (a file inside module `X` writing `import "X"`) is a compile error.
- `import` declarations are **file-scoped**. Names bound in one file of a multi-file module are not visible in sibling files of the same module; each file declares its own imports.
- Two destructured bindings of the same name in the same file — whether from two distinct modules or shadowing a prelude binding — are a compile error.
- Import cycles (`A → … → A`) are forbidden; the resolver emits a diagnostic.
- **No re-exports.** A module cannot republish another module's bindings; a façade must wrap each binding manually.

#### Prelude

`std/core` is an **implicit prelude**: every `export` from `std/core` is automatically in scope in every other module without an `import`. `Range`, `Field`, `Display`, `Iterator`, etc. are usable directly. The prelude does not apply inside `std/core` itself. Writing `import "std/core"` explicitly from any other module is a compile error (duplicate of the prelude).

### Visibility

Two levels:

- **`export`** — the decl is visible to importers via `import "<this-module>"`.
- **default (no keyword)** — the decl is private to the module: visible to every file of the same module without an import, and invisible to any other module.

There is no file-private level. If a decl needs to live in only one file, place it in that file alone — but sibling files of the same module can still see it; this is by design.

The `main` function is **always public** — the resolver promotes its visibility regardless of an explicit `export` keyword (which is then redundant). See §6.

#### Intra-module collisions

Two top-level decls with the same name in the same module raise a compile error:

- Two structs / type aliases / consts / enums / traits with the same name across files of the module → hard error (no canonical "winner").
- Two `fn` decls with the same name across files of the module → join the same overload set, exactly like multiple `fn` decls inside one file today. Ambiguity surfaces at the call site if parameter shapes overlap.

#### Visibility leak

An `export`ed decl whose signature mentions a module-private type, alias, const, enum, or trait is a compile error. A public surface must be reachable through public types only — either `export` the referenced decl or refactor the signature.

### Configuration: `vader.json`

`vader.json` is **optional**. When present, the `modules` field declares the source roots to scan:

```json
{
  "name": "myapp",
  "version": "0.1.0",
  "modules": ["src/", "vader/"]
}
```

Folders not listed (`tests/`, `bench/`, `examples/`, `build/`, `dist/`, `node_modules/`, `.git/`, …) are excluded from the scan, even when they contain `.vader` files. They cannot be imported by name.

The `modules` field accepts **literal folder paths only** — no glob patterns. Each root is a plain relative path resolved from the manifest's directory.

#### Default whitelist

When `vader.json` is absent or omits `modules`, the scan covers only the entry file's containing folder, plus the stdlib (below). Single-file invocations and trivial projects need no manifest; larger projects with multiple source roots do.

#### Stdlib resolution

The stdlib is resolved out-of-band, independently of `vader.json`:

- **Release** — sidecar of the binary at `<dir-of-binary>/stdlib/`.
- **Dev** — hard-coded `<workspace>/stdlib/` when running from source.

The stdlib's modules participate in the global index like any other scope; they're simply discovered through a fixed path.

#### CLI fallback for out-of-scope files

For invocations like `vader dump tests/snippets/arith/_main.vader` or `vader run examples/hello.vader` where the entry file lives outside the active whitelist, the compiler implicitly adds the file's containing folder to the scan **for that invocation only**. This keeps the whitelist strict for indexing while making single-file invocations ergonomic.

**No external packages in MVP.** Post-MVP topic.

### Discovery and scan

At project load, the compiler performs a single pass that scans every scoped root recursively and builds an in-memory index mapping each module name to its folder and file list. Symlinks are not followed, neither for `.vader` files nor for folders containing them. Scan order is not deterministic across platforms; diagnostics that mention "first / second occurrence" are stable within an invocation but may swap roles between machines. The index is rebuilt on each invocation (no on-disk cache in MVP).

The same scan + index applies to every CLI subcommand — `run`, `build`, `dump`, `test`, `fmt`, `lsp` (and the post-MVP `check`). The contract checks (uniqueness, name grammar) and the diagnostic surface are identical across subcommands; only the downstream work differs.

### Compilation modes

| Mode | Triggered by | Behaviour |
|------|---|---|
| **Focus** (default) | `vader run`, `vader build`, `vader dump <file>` | Scan everything in scope to build the index and validate uniqueness. Typecheck **only** the entry's module + its transitive imports. |
| **Whole** (post-MVP) | `vader check --all` (or equivalent) | Scan + typecheck every module reachable from the project's roots, including those not imported by any entry. |

Focus mode tolerates work-in-progress modules that aren't yet linked into the main graph.

### Entry point

Always a `main` function. No overloaded conventions. Write it without the `export` keyword — the resolver promotes it to public (see §6).

```vader
module "main"

main :: fn() -> i32 {
    println("Hello")
    return 0
}
```

`main` must return `i32` (see §6) — the typechecker rejects any other signature with **T3033**. Relaxing this to allow `void` (implicit `0`) or `i32 | Error` (propagating errors via `?`) is a possible future change, not currently accepted.

### What appears at the top level of a `.vader` file

A source file may contain only:

- The `module` declaration (mandatory, first non-trivial line)
- `import` statements
- Type declarations: `Result :: A | B | C` and `Maybe<T> :: T | null`
- Function declarations: `name :: fn(...) -> T { ... }`
- Struct declarations: `Foo :: struct { ... }`
- Enum declarations: `Color :: enum { ... }`
- Trait declarations: `T :: trait { ... }`
- Trait implementations: `T implements Trait { ... }`
- Constant declarations: `PI :: 3.14159`
- Decorators on any of the above

**No executable statements at the top level** — no top-level `print(...)`, no top-level loops. Every side-effecting expression lives inside a function body, typically `main`. This keeps the parser simple, makes module loading order independent of execution order, and means `import`-ing a module never runs code.

### Rationale: why module identity is decoupled from the filesystem

Earlier iterations of Vader used "one folder = one module" as identity: the resolver inferred a module's name from its folder path. That rule broke down on flat stdlib layouts (sibling `.vader` files each conceptually a distinct module) and pinned naming choices to filesystem structure. The explicit `module "..."` declaration:

- Lets module names be globally unique without forcing a specific folder layout.
- Decouples conceptual organisation from on-disk storage: a small module lives as a single file in a single-file folder; a large module splits across siblings without changing its name.
- Makes import resolution a pure name lookup, removing the need for filesystem heuristics.

The folder remains the colocation unit (one folder ≤ one module), but the module's name and identity come from the source file, not the directory.

### Future: programmable build API

Post-MVP: a `build.vader` file that drives the build via Vader code (instead of a declarative manifest).

---

## 12. Decorators

Decorators are **compiler instructions** prefixed with `@`. They operate at compile time, never at runtime.

| Decorator | Target | Purpose |
|-----------|--------|---------|
| `@comptime` | fn / value | Forces compile-time evaluation |
| `@extern`, `@extern("symbol")`, or `@extern("module", "symbol")` | fn (no body) | Declares a user-supplied FFI symbol — see §13 |
| `@intrinsic` | fn (no body) / impl (no body) | Marks a stdlib function or trait impl as host-provided; the runtime (VM / C / WASM) wires each method by mangled name |
| `@export` or `@export("name")` | fn | Exposes the function with no name mangling (JS-side / lib-side) |
| `@test` | fn | Marks as a test, executed by `vader test` |
| `@deprecated("reason")` | any decl | Emits a `W0001` warning at every reference — code still compiles |
| `@assert(condition)` or `@assert(condition, "message")` | top-level | Compile-time assertion; condition must evaluate to `true` at comptime, otherwise build fails with `C4015`. The optional second argument must be a *static* string literal (no `${...}` interpolation) — when present, it is appended to the C4015 detail to surface meaningful context |
| `@partial` | `match` expression | Opts out of exhaustiveness checking; missing variants no longer trigger `T3013`. Use with a deliberate `_`/binding catch-all (which also silences `W0005`) for "everything else does X" |
| `@unreachable` | `match` expression | Opts out of exhaustiveness checking like `@partial`, but asserts the *uncovered* variants can never occur: handle the possible variants explicitly (no `_` arm, no fake value) and any uncovered variant traps at runtime (`reached unreachable`). Use for "handle A/B/C, the rest are impossible". Mutually exclusive with `@partial` |
| `@specialize` | generic struct / fn | Marks the decl as ineligible for type-erasure; the compiler keeps a distinct monomorphisation per `(decl, typeArgs)` pair. Default behaviour for unmarked generics is erasure (one shared body, vtable dispatch on type-param method calls). Today used on stdlib iterator types (`ArrayIterator`, `Yield`, `MapIterator`, `FilterIterator`, `TakeIterator`, `SkipIterator`, `SetIterator`) whose for-in fusion inlining depends on the body being inline at the call site |
| `@no_return` | fn | Marks the fn as **diverging** — control never returns to the caller (it panics, aborts, or loops forever). A call to it types as `never`, so it is assignable into any slot (`_ -> todo("x")` where a value is expected type-checks) and terminates control flow (the call satisfies a non-`void` fn's return obligation; code after it is unreachable, `W0002`). Powers `panic` / `todo` / `unreachable` in `std/abort`. |
| `@internal` | struct field | Restricts a single struct field to its **declaring module**. Struct fields are **public by default** (the opposite polarity to top-level `export`, which is private-by-default); `@internal` opts one field out. Reading, writing, constructing-with, or pattern-binding the field from another module is rejected with `T3054`. An `@internal` field should usually carry a `default` so the type stays constructible across modules via `T {}` (otherwise the type is constructible only from inside its module — a deliberate "factory-only" pattern). |
| `@allow_unused` | any top-level decl | Exempts the declaration from the `W0007` dead-code lint (an unused private fn / const / type / enum / trait / alias). Use for intentional dead code : an API not yet wired, a helper kept for symmetry, or a test fixture's deliberate decoy. The declaration is treated as a reachability root — never flagged, and anything it references stays live. |

`@extern` and `@intrinsic` are siblings — both apply to declarations the source doesn't define a body for, with the host filling in the runtime behavior. `@extern` is for **user code** crossing into FFI; `@intrinsic` is for **stdlib code** whose implementation lives in the host runtime (e.g. `print`, `collect`, the methods of `string implements Add / Hash / Index`). The decorator is informational today — the compiler doesn't yet validate that every `@intrinsic` has a host wiring, but the marker enables that check and distinguishes intentional host-bridging from accidentally-bodyless declarations.

`@intrinsic` accepts two shapes:

```vader
// Standalone fn — used for free-function host imports (I/O, GC, builders…).
@intrinsic
export print :: fn(msg: string) -> void

// Trait impl — used when every method of the impl is host-provided. The
// compiler synthesises one body-less FnDecl per trait method, each marked
// `@intrinsic`, mangled as `<module>$<type>$<trait>$<method>`.
@intrinsic
string implements Add
```

A handful of `@intrinsic` impl methods are also **op-level** intrinsics: the bytecode emitter recognises calls to specific mangled names (`std_core$string$Add$add`) and emits a dedicated op (`string.concat`) instead of a regular `call.import`, so `s1 + s2` and `"a".add("b")` share a single zero-overhead path.

The v1 `@load` is **replaced by `import`**.

---

## 13. FFI / External Functions

### `@extern` — declaring imports

```vader
@extern add_i32 :: fn(a: i32, b: i32) -> i32                    // C symbol: add_i32
@extern("strlen") c_strlen :: fn(s: string) -> usize            // C symbol: strlen
@extern("env", "console_log") log :: fn(p: i32, n: i32) -> void // C symbol: console_log
```

The decorator accepts **0, 1, or 2 string arguments**. The **last** string is the foreign symbol name (the C linker symbol on the native target; the WASM `field` on a future WASM target). The **first** of two arguments is the WASM module hint (`"env"` by convention) — ignored by the C-emit, consumed by future WASM-emit. Omitting all arguments reuses the Vader-side fn name as the C symbol. 3+ arguments or any non-string-literal argument is `T3050`.

`@extern`-decorated fns **must be bodyless** — declaring a body alongside `@extern` is `T3051`.

### Allowed signature types

The MVP C ABI marshals **primitives + `string` only**:

```
i8 i16 i32 i64    u8 u16 u32 u64    isize usize
f32 f64    bool   char    void    string
```

Anything else (struct / array / union / fn-typed param / trait / type-param) is `T3050`. Future iterations may add:
- opaque pointer types alongside a future `unsafe` block facility (deferred — see Appendix B)
- struct passing for `@repr(C)` Vader structs
- callbacks (C → Vader function pointers)

### Native target — code generation

For each user `@extern` the compiler emits one forward declaration at the top of the generated `.c`, then a per-call shim that the bytecode's `call.import` jumps to:

```c
// Forward declaration — resolved by the linker.
extern int32_t add_i32(int32_t, int32_t);
extern size_t strlen(const char*);

// Shim — bridges the Vader-side ABI to the foreign signature.
static int32_t vader_import_0(int32_t a0, int32_t a1) {
    return add_i32(a0, a1);
}
static size_t vader_import_1(vader_string_t a0) {
    // Stack-allocated NUL copy for strings < 4 KiB; heap fallback above.
    char _b0[a0.len < 4096 ? a0.len + 1 : 1];
    const char* c0;
    if (a0.len < 4096) {
        if (a0.len > 0) memcpy(_b0, a0.ptr, a0.len);
        _b0[a0.len] = 0;
        c0 = _b0;
    } else {
        c0 = vader_string_to_cstr(a0);  // malloc'd
    }
    size_t r = strlen(c0);
    if (a0.len >= 4096) vader_cstr_free(c0);
    return r;
}
```

The shim is **emitted by the compiler** — the user never writes the `vader_string_t` ↔ `const char*` glue manually. `string` parameters are marshalled to NUL-terminated UTF-8 `const char*` with a frame-lifetime guarantee: the buffer is valid only during the call and freed (or discarded with the stack frame) on return.

Two distinct `@extern` decls sharing the same C symbol (`@extern("strlen") a` + `@extern("strlen") b`) are `T3050` — the linker would resolve both calls to the same prototype, masking ABI mismatches.

### Linking

```bash
vader build prog.vader --target=native --ldflags="helper.o -lcrypto -L/usr/local/lib"
```

`--ldflags="<raw flags>"` passes a whitespace-split string of linker flags directly to `cc` — append `.o` files, `-l<lib>` libs, `-L<dir>` paths, frameworks, etc. The MVP doesn't ship a manifest format; everything goes through `--ldflags`.

### VM behaviour

The VM resolves `@extern` user imports against a **host registry** keyed by `(mangledName, externName)`. Each `call.import` consults the registry and dispatches to the registered host handler; unbound imports throw `vm: unbound host import …`. The registry is populated by callers of `vader run` (the test runner, the comptime engine, embedders) — there is no auto-discovery.

C-emit and WASM continue to resolve `@extern` against the system linker / module import table respectively; the same `@extern` decl compiles for all three backends, only the binding mechanism differs.

### Future WASM target

When the WASM emitter lands (see §17 *Compilation Targets*), `@extern` will additionally support the WASM `(module, field)` shape:
- 2-arg form `@extern("env", "console_log") log` → `(import "env" "console_log" (func …))`
- 1-arg / 0-arg form defaults the module to `"env"`.

The C-emit will continue to ignore the module hint. The same `@extern` decl compiles for both targets.

### `@export` — exposing a function

```vader
@export("addNumbers")
add_numbers :: fn(a: i32, b: i32) -> i32 {
    return a + b
}
```

JS side:

```javascript
const { instance } = await WebAssembly.instantiateStreaming(fetch("app.wasm"));
console.log(instance.exports.addNumbers(2, 3));
```

---

## 14. Compile-time Execution

### `@comptime`

Forces evaluation at compile time:

```vader
build_lookup_table :: fn() -> u32[] {
    result: u32[] = []
    for i in 0..<256 {
        result.push(u32(i * i))
    }
    return result
}

@comptime
TABLE :: build_lookup_table()
```

`build_lookup_table()` runs during compilation — loops, local mutation and calls are evaluated by the embedded bytecode VM (see the implementation note). `TABLE` is a constant whose value is computed once at compile time. When typed as an immutable `const T[]` of primitive elements it is **materialised into the binary's read-only data section** (`.rodata` natively, a data segment under wasm) and referenced by a zero-copy view — never rebuilt at runtime ; otherwise the value is inlined at each use site.

**Inline form.** `@comptime` also works as an expression prefix on a const's right-hand side, so the builder can be written at the const instead of as a separate fn:

```vader
TABLE :: @comptime {
    result: u32[] = []
    for i in 0..<256 { result.push(u32(i * i)) }
    return result
}

// typed form — materialised into .rodata :
SQUARES: const u32[]: @comptime { … }
```

`NAME :: @comptime <expr>` desugars to a synthetic nullary fn holding `<expr>` plus a `@comptime`-decorated `NAME` that calls it ; a trailing `return` inside a block behaves as the block's value.

### Synergy with generics

A call `List<i32>` is a `@comptime` expression (the engine resolves the type, instantiates the generic struct, generates the specialized code).

### Sandbox

See section 2 (Compilation Model).

### Implementation note (comptime engine)

In the self-hosted compiler the comptime engine is a **tree-walk AST interpreter** (`vader/comptime/`) for the common case — expression evaluation plus calls to functions with a single `return <expr>` / trailing-expression body. A decl the tree-walk can't evaluate (loop, statement-bodied callee, local mutation) is **staged to bytecode and run by the embedded VM** (`vader/comptime_vm`, between `evaluate_project` and `lower_project`) — the model the TypeScript reference compiler always used. The VM result is bridged back to a comptime value and injected. Guards keep this deterministic: a step budget bounds non-terminating loops (`C4004`), a sandbox denies non-deterministic / side-effecting hosts at comptime (clock, process, I/O), and a VM trap surfaces `C4002` ; a genuinely unevaluable shape still surfaces `C4001`. Generic instances are observed during evaluation and fed to the monomorphizer.

### Reflection / comptime intrinsics

Compiler-built `@<name>(args)` calls usable in *expression* position. Distinct from decorators, which annotate declarations. Reflection intrinsics operate on a type expression and **fold to a constant at lower time**; the comptime-host builtin `@file` reads project state and bakes its result before the lower phase. Both shapes compose freely with `@assert(...)` and (eventually) `where` predicates to drive comptime branching on type shape, layout, or external content.

The "Signature" column below uses `T: type` for arguments that name a type. A bare type-ident like `i32` is a value of the metatype `type` (§4), so `@size_of(i32)` reads `i32` *as a value* — the intrinsic itself takes a value-position arg, and the typechecker validates it is `type`-typed. `@size_of` uniquely also accepts a runtime `type` value (e.g. a fn param `fn(t: type)`); the other reflection intrinsics require the arg to fold to a static type at the call site.

| Intrinsic | Signature | Result | Notes |
|-----------|-----------|--------|-------|
| `@size_of(T)` | `(T: type) -> usize` | Byte size of `T` as a runtime value. | Primitives use Vader's ABI sizes (`i8` → 1, `i32` → 4, `i64`/`usize`/`f64` → 8, `string` → 16, `null` → 0); aggregate or reference types are stored as `vader_box_t` (16 bytes); comptime-only / unresolved kinds → 0. The only intrinsic that also accepts a runtime `type` value; the lowerer folds the static case to a literal and routes the runtime case through a `size_of.type` op. |
| `@align_of(T)` | `(T: type) -> usize` | Alignment in bytes. | Mirrors `size_of` for primitives; aggregates align to the pointer boundary (8). |
| `@type_name(T)` | `(T: type) -> string` | Printable name of `T`. | Same shape as the typechecker's `displayType` (`"i32"`, `"MutableMap<i32, string>"`, `"i32 \| string"`). |
| `@type_kind(T)` | `(T: type) -> string` | Discriminator of `T`'s shape. | Stable strings: `"primitive"`, `"struct"`, `"enum"`, `"union"`, `"array"`, `"tuple"`, `"fn"`, `"trait"`, `"type"`, `"any"`, `"unknown"`. User code is expected to compare on exact match (`if @type_kind(T) == "struct" { ... }`). |
| `@field_count(T)` | `(T: type) -> usize` | Number of fields on a Struct, or elements on a Tuple. | Returns 0 for any other shape. |
| `@variant_count(T)` | `(T: type) -> usize` | Number of variants on a Union or Enum. | Returns 0 for any other shape. Unions are canonicalised by `unionOf` before counting (a union of unions flattens). |
| `@field_index(T, "name")` | `(T: type, name: string-literal) -> usize` | 0-based position of `name` in `T`'s field list. | `T` must be a `struct` (not a Tuple, not a primitive); `name` must be a *static* string literal naming an existing field. T3002 if either constraint is violated, T3009 if the field is unknown. |
| `@satisfies(T, Trait)` | `(T: type, Trait: type) -> bool` | True iff `T` has an explicit `T implements Trait` impl in scope. | Walks the project's impl registry. Returns `false` if `Trait` resolves to anything other than a `trait` symbol, or if no impl is found. Numeric primitives carry `@intrinsic` `Add`/`Sub`/`Mul`/`Div` impls in `std/core`, so e.g. `@satisfies(i32, Add)` is `true`. The same impls underpin the Layer 7e automatic enforcement of `<T: Trait>` bounds. |
| `@file(path)` | `(path: string) -> string` | UTF-8 contents of the file at `path`, baked at compile time. | The path is resolved relative to the source file containing the call. `path` must be comptime-evaluable — a string literal, an ident pointing at a string-typed const, or any expression whose result the comptime VM can reduce to a string (e.g. `FILENAME + ".txt"`). The sandbox confines the resolved path to the project root; escapes raise `C4011`. Missing file raises `C4006`. |
| `@type_of(x)` | `(x: value) -> type` | Static type of `x` as a `type` runtime value. | Argument is **not evaluated at runtime** — only its static type is read at the call site. Useful as input to other reflection intrinsics (`@fields(@type_of(point))`). |
| `@fields(T)` | `(T: type) -> Field[]` | Field introspection for a struct. | `Field` carries `name: string`, `offset: usize`, `ty: type`. Materialised at lower time as a `Field[]` literal in the const pool. T3002 if `T` isn't a struct. |
| `@type_args(T)` | `(T: type) -> type[]` | Generic-argument list of a struct or trait instance. | Returns `[]` for non-generic types. |
| `@field(x, "name")` | `(x: value, name: value) -> <field type>` | Dynamic field access by static-string-literal name. | `name` must be a static string literal (or a `f.name` access that folds to one inside `@comptime for f in @fields(T)`). Result type is the field's declared type, resolved per-call. |

Composition example — comptime layout assertions:

```vader
@assert(@size_of(MyHotStruct) <= 64,
        "MyHotStruct must fit in a cache line")
@assert(@type_kind(KeyType) == "primitive" || @type_kind(KeyType) == "struct",
        "KeyType is not hashable")
```

The condition expression is evaluated by the comptime VM; each intrinsic appears as a literal in the bytecode (folded at lower time), so the assertion compiles to a single comparison on constants.

### `@comptime for` over reflected fields

`@comptime for f in @fields(T) { … }` is **loop unrolling** at compile time — the lowerer unrolls one body copy per field and substitutes `f` (and any `f.name` / `f.ty` access) with the concrete field's metadata in each copy. Inside an unrolled body, `@field(x, f.name)` folds to a direct field access on `x` (no string-keyed lookup at runtime). The result is generic introspection code (e.g. a `to_string` derived from a struct's fields, a JSON serialiser, a hash impl) that compiles to per-field straight-line code with no runtime reflection.

---

## 15. Standard Library — MVP scope

### `std/core` (auto-imported)

Traits: `Display`, `Equals`, `Comparable`, `Step`, `Into<Target>`, `Add`, `Sub`, `Mul`, `Div`, `Rem`, `Hash`, `Clone`, `Iterator<T>`, `Contains<T>`, `Index<I, T>`, `IndexSet<I, T>`, `Error`. (There is no `Iterable` trait — iteration sources implement `Into<Iterator<T>>`, see §7.)

Types: `Yield<T>`, `Range`, `ArrayIterator<T>`, `Field` (reflection — see §14).

Primitive trait impls: `string implements Add` (via `string.concat` op), `string implements Hash`, `string implements Index<usize, char>` (powers `s[i]`), and `Equals`/`Hash`/`Comparable`/`Step` on the integer primitives + `char`. `Add`/`Sub`/`Mul`/`Div` on every numeric primitive. (`%` is a built-in op; the `Rem` trait is declared for user overloading but is **not** impl'd on the primitives.) `Comparable` and `Step` impls are written in Vader (arrow form); the rest are `@intrinsic` and bodies are host-provided.

The `Contains<T>` trait powers the `in` / `!in` operators:

```vader
Contains :: trait<T> {
    contains :: fn(self, value: T) -> bool
}

// `Range<i32> implements Contains<i32>` is shipped, so `5 in 0..<10`
// works out of the box. User types opt in by implementing the trait.
```

Trait-method dispatch on a bounded type param (`f :: fn<T: Hash>(x: T) { x.hash() }`) resolves at typecheck and is monomorphised statically — each call site lands on the concrete impl member after substitution. Primitive `Hash` impls dispatch through the same machinery (`(42).hash()`, `"foo".hash()`). String hashing is FNV-1a over the UTF-8 bytes (`@intrinsic string implements Hash` — host-provided method).

### `std/io`

```vader
print      :: fn<T: Display>(msg: T) -> void
println    :: fn<T: Display>(msg: T) -> void
eprint     :: fn<T: Display>(msg: T) -> void
eprintln   :: fn<T: Display>(msg: T) -> void
read_line  :: fn() -> string | Error
read_stdin :: fn(n: usize) -> string | Error  // read up to n bytes from stdin
read_file_string  :: fn(path: string) -> string | Error
write_file_string :: fn(path: string, content: string) -> null | Error
read_file_bytes   :: fn(path: string) -> u8[] | Error
write_file_bytes  :: fn(path: string, content: const u8[]) -> null | Error
exists     :: fn(path: string) -> bool
is_dir     :: fn(path: string) -> bool
read_dir   :: fn(path: string) -> string[] | Error  // names only (no recursion)
current_executable_location :: fn() -> string       // absolute path of the running binary
```

`print` / `println` / `eprint` / `eprintln` are generic over `Display`:
`println(42)` and `println(my_struct)` both monomorphise against the
argument's type and call `msg.to_string()` (the `Display` impl member)
before writing the bytes. No per-type wrapper, no virtual dispatch; the
coercion is in the function source, not a separate lowerer pass.

I/O is **synchronous blocking** only in MVP.

### `std/string`

Width-based helpers (`pad_start`, `pad_end`) measure bytes, not codepoints.

```vader
// Core access (intrinsics — no body in Vader).
is_empty    :: fn(s: string) -> bool                   // sugar for s.bytes().len() == 0
contains    :: fn(s: string, sub: string) -> bool      // the `Contains<string>` impl (powers `sub in s`); pure Vader, not a host intrinsic
starts_with :: fn(s: string, prefix: string) -> bool
ends_with   :: fn(s: string, suffix: string) -> bool
split       :: fn(s: string, sep: string) -> string[]
trim        :: fn(s: string) -> string
to_upper    :: fn(s: string) -> string
to_lower    :: fn(s: string) -> string

// Parsing. `ParseError` is the union arm raised on malformed / empty / overflow.
ParseError  :: struct { msg: string }              // implements Error
parse_int   :: fn(s: string) -> i32 | ParseError
parse_float :: fn(s: string) -> f64 | Error          // host intrinsic: generic Error

// Codepoint walkers. `s[i]` (Index impl in std/core) is the primary access form.
len              :: fn(s: string) -> usize                      // codepoint count, allocation-free
chars            :: fn(s: string) -> StringChars                // StringChars implements Iterator<char>
decode_codepoint :: fn(s: string, i: usize) -> [char, usize]    // (codepoint, byte width)

// Byte access (raw UTF-8 — for ASCII / binary protocols / BOM detection).
bytes          :: fn(s: string) -> const u8[]                   // UTF-8 bytes; zero-copy borrowed view on native, materialised copy on the VM
bytes_to_string :: fn(bs: const u8[]) -> string                 // inverse of bytes(); `s.bytes()[lo..<hi].bytes_to_string()` is the byte-indexed substring (O(1) on the borrowed view)
byte_decode_at :: fn(s: string, i: usize) -> char               // decode UTF-8 codepoint at byte offset (for byte-cursor parsers)
decode_codepoint_at :: fn(bs: const u8[], i: usize) -> [char, usize]  // byte-view codepoint decode; advance a held-view cursor by the returned width

// Indexing helpers. `min_index` / `from` and the result use `isize` so the
// `-1`-on-miss sentinel stays expressible without a `usize | null`.
index_of      :: fn(s: string, c: char, from: usize) -> isize
last_index_of :: fn(s: string, c: char, min_index: isize) -> isize

// Ordering — case-sensitive and case-insensitive lexicographic comparators.
compare_ascending    :: fn(a: string, b: string) -> bool
compare_ascending_ci :: fn(a: string, b: string) -> bool

// Format helpers (pure Vader).
pad_start  :: fn(s: string, width: usize, fill: char) -> string
pad_end    :: fn(s: string, width: usize, fill: char) -> string
join       :: fn(parts: string[], sep: string) -> string
left_trim  :: fn(s: string) -> string
right_trim :: fn(s: string) -> string

// UTF-8 codepoint width (powers `chars()` / `len`).
codepoint_byte_len :: fn(c: char) -> usize                      // 1..4 — UTF-8 width of a codepoint

// Pattern / scanner helpers (ad-hoc — no real regex engine in MVP).
trim_prefix         :: fn(s: string, prefix: string) -> string
trim_suffix         :: fn(s: string, suffix: string) -> string
replace_chars_where :: fn(s: string, pred: fn(char) -> bool, replacement: string) -> string
split_where         :: fn(s: string, pred: fn(char) -> bool) -> string[]   // e.g. `s.split_where(is_white_char)`
decode_escapes      :: fn(body: string) -> string               // decode `\n`, `\t`, `\u{HHHH}`, …
```

`is_hex_digit`, `is_digit_in_base`, and base-specific parsing helpers live in [`std/numbers`](#stdnumbers) — they belong to numeric reading, not string scanning.

### `std/numbers`

UFCS-callable numeric formatting and parsing.

```vader
to_hex          :: fn(self: u64) -> string         // lowercase, no `0x`, no leading zeros
to_bin          :: fn(self: u64) -> string         // no prefix, no leading zeros
to_compact_str  :: fn(self: f64) -> string         // strips trailing `.0`; `(10.0).to_compact_str() = "10"`

parse_int_in_base  :: fn(s: string, base: i32) -> i64 | ParseError
parse_uint_in_base :: fn(s: string, base: i32) -> u64 | ParseError
hex_digit_value    :: fn(c: char) -> i32           // -1 if not a hex digit
is_hex_digit       :: fn(c: char) -> bool
is_digit_in_base   :: fn(c: char, base: i32) -> bool
strip_numeric_text :: fn(text: string, base: i32) -> string  // drop the base prefix + `_` digit separators
```

Caller pads via `pad_start` (`n.to_hex().pad_start(8, '0')`).

### `std/char`

ASCII character predicates (universal — useful for any DSL or text scanner).
They operate on `char` (codepoints), not bytes. To append a decoded codepoint
to a `StringBuilder`, call `sb.append_char(char(cp))` directly — `append_char`
UTF-8-encodes the codepoint canonically, no `append_codepoint` wrapper needed.

```vader
is_white_char :: fn(c: char) -> bool                  // space, tab, newline, CR
is_digit      :: fn(c: char) -> bool                  // 0-9
is_alpha      :: fn(c: char) -> bool                  // a-z, A-Z
is_alnum      :: fn(c: char) -> bool                  // a-z, A-Z, 0-9
```

### `std/string_builder`

Efficient string construction.

```vader
StringBuilder :: struct { parts: string[] }

new_builder     :: fn() -> StringBuilder
append          :: fn(self: StringBuilder, s: string) -> void
append_char     :: fn(self: StringBuilder, c: char) -> void
append_repeated :: fn(self: StringBuilder, c: char, count: i32) -> void  // pretty-printer / padding helper

// Display is host-provided — flushes the buffer in one allocation.
// `${sb}` interpolation and `sb.to_string()` both resolve here.
@intrinsic StringBuilder implements Display
```

### `std/collections`

All hash-based mutable collections live in a single module. Sequence
collections use raw `T[]` arrays (which already support `push`, `len`,
indexed access, mutation, and `for x in arr`) — no `MutableList` wrapper
in MVP. Immutable `List<T>` will pair with arrays once read-only views
land (post-MVP).

```vader
// Hash map — chained buckets with a fixed bucket count. The public surface
// is the trait-operator triad below; `put` / `get` / `contains_key` are
// internal helpers used by the impls.
MutableMap<K: Hash & Equals, V>
len      :: fn(self: MutableMap<K, V>) -> usize
is_empty :: fn(self: MutableMap<K, V>) -> bool
keys     :: fn(self: MutableMap<K, V>) -> K[]
values   :: fn(self: MutableMap<K, V>) -> V[]
remove   :: fn(self: MutableMap<K, V>, key: K) -> bool   // true if the key was present

// Hash set — wraps a `MutableMap<T, bool>`. Lookups inherit the
// chained-bucket O(1) behaviour from the underlying map.
MutableSet<T: Hash & Equals>
add      :: fn(self: MutableSet<T>, value: T) -> bool   // true if newly added
remove   :: fn(self: MutableSet<T>, value: T) -> bool   // true if the value was present
contains :: fn(self: MutableSet<T>, value: T) -> bool
len      :: fn(self: MutableSet<T>) -> usize
is_empty :: fn(self: MutableSet<T>) -> bool
```

`MutableMap` carries `Index<K, V | null>` / `IndexSet<K, V>` / `Contains<K>`
impls, so the trait operators (§4 *Operator overloading*) are the canonical
access surface:

```vader
m["a"] = 10              // IndexSet — store
match m["a"] { … }       // Index    — fetch, returns `V | null`
if "a" in m { … }        // Contains — membership
```

`MutableSet` carries a `Contains<T>` impl; `value in set` / `value !in set`
both work. No `Index` / `IndexSet` impl on Set: sets have no value-at-key
semantics, and `s.add(v)` reads more clearly than `s[v] = true` ever could.

### `std/math`

```vader
// Comparison + helpers — overloaded on `i32`, `usize`, and `f64`. A generic
// `Comparable`-driven variant (one fn body for any `T: Comparable`) is post-MVP: the
// body needs to default-init a slot of type `T` before threading it through
// `compare`, which is gated on `Default<T>` / a `zero<T>()` intrinsic.
min   :: fn(a: i32, b: i32) -> i32
min   :: fn(a: usize, b: usize) -> usize
min   :: fn(a: f64, b: f64) -> f64
max   :: fn(a: i32, b: i32) -> i32
max   :: fn(a: usize, b: usize) -> usize
max   :: fn(a: f64, b: f64) -> f64
abs   :: fn(x: i32) -> i32
abs   :: fn(x: f64) -> f64
clamp :: fn(x: i32, lo: i32, hi: i32) -> i32
clamp :: fn(x: usize, lo: usize, hi: usize) -> usize
clamp :: fn(x: f64, lo: f64, hi: f64) -> f64
lerp  :: fn(a: f64, b: f64, t: f64) -> f64        // a + (b - a) * clamp(t, 0.0, 1.0)

// Float intrinsics — wired to libm on native, JS Math on the VM.
sqrt  :: fn(x: f64) -> f64
pow   :: fn(x: f64, n: f64) -> f64
floor :: fn(x: f64) -> f64
ceil  :: fn(x: f64) -> f64
round :: fn(x: f64) -> f64
sin   :: fn(x: f64) -> f64
cos   :: fn(x: f64) -> f64
tan   :: fn(x: f64) -> f64

pi :: 3.141592653589793
e  :: 2.718281828459045
```

### `std/iter`

The iterator trait lives in `std/core` (auto-imported). `next()` returns `Yield<T> | null` (`null` = exhausted). The `Yield` wrapper keeps iterators over nullable elements unambiguous — a yielded `null` is distinct from end-of-stream:

```vader
Yield :: struct<T> { value: T }

Iterator :: trait<T> {
    next     :: fn(self) -> Yield<T> | null
    is_empty :: fn(self) -> bool                  // default — derives from next
    count    :: fn(self) -> usize                 // default — drains, returns total
    last     :: fn(self) -> T | null              // default — drains, last yielded
}
```

`is_empty` / `count` / `last` are default methods (Layer 8d) — every Iterator impl inherits the bodies derived from `next`, the user only has to provide `next`.

`std/iter` provides combinators on top of `Iterator<T>`. Two flavours coexist:

- **Eager combinators** — take a `T[]` directly (an `Iterator<T>` also drops in via the `Into` coerce), allocate a fresh array for the result, return it. Suitable for the common case of "I want a `T[]` out of this pipeline".

  ```vader
  map       :: fn<T, U>(arr: T[], f: fn(T) -> U) -> U[]
  filter    :: fn<T>(arr: T[], pred: fn(T) -> bool) -> T[]
  fold      :: fn<T, U>(arr: T[], init: U, f: fn(U, T) -> U) -> U
  take      :: fn<T>(arr: T[], n: usize) -> T[]
  skip      :: fn<T>(arr: T[], n: usize) -> T[]
  slice     :: fn<T>(arr: T[], lo: usize, hi: usize) -> T[]
  zip       :: fn<T, U>(a: T[], b: U[]) -> [T, U][]
  chain     :: fn<T>(a: T[], b: T[]) -> T[]
  enumerate :: fn<T>(arr: T[]) -> [usize, T][]
  flat_map  :: fn<T, U>(arr: T[], f: fn(T) -> U[]) -> U[]
  clone     :: fn<T>(arr: T[]) -> T[]
  sum       :: fn(arr: i32[]) -> i32
  count     :: fn<T>(arr: T[]) -> usize
  is_empty  :: fn<T>(arr: T[]) -> bool
  collect   :: fn<T>(it: Iterator<T>) -> T[]            // materialise an iterator (or T[]) into an array
  ```

- **Lazy combinators** — return a struct (`MapIterator<T, U>`, `FilterIterator<T>`, `TakeIterator<T>`, `SkipIterator<T>`) that itself implements `Iterator<T>`. Chains fuse through `Iterator<T>` slots without allocating intermediate arrays. UFCS lets calls chain fluently:

  ```vader
  arr.filter(p).map(f).take(10).collect()
  ```

  The auto-coerce `T[] implements<T> Into<Iterator<T>>` makes raw arrays drop into any `Iterator<T>` slot, so a raw `T[]` flows straight into the first combinator with no explicit wrap. Short-circuiting combinators (`any`, `all`, `find`, `find_map`) live in this family too — they take a single `Iterator<T>` (raw arrays auto-coerce) and stop on the first match.

The eager and lazy families converge on the same `Iterator<T>` trait: an eager `collect(it)` materialises whatever the lazy chain produces; a lazy chain accepts a raw `T[]` via the same `Into<Iterator<T>>` coercion.

### `std/runtime`

Runtime introspection and controls — currently GC-only. The module is named `runtime` since Vader has no compiler-private visibility tier today; the surface is meant for debugging and testing rather than production code.

```vader
collect      :: fn() -> void   // force a Cheney cycle
collections  :: fn() -> i32    // total cycles since start
bytes_used   :: fn() -> i32    // live bytes in from-space
bytes_copied :: fn() -> i32    // cumulative bytes copied
```

### `std/path`

Filesystem path manipulation. POSIX `/` separator only in MVP — Windows support deferred. All operations return fresh `Path` values (no mutation).

```vader
Path :: struct { repr: string }

to_path     :: fn(s: string)                    -> Path
empty_path  :: fn()                             -> Path
as_string   :: fn(self: Path)                   -> string
is_empty    :: fn(self: Path)                   -> bool
is_absolute :: fn(self: Path)                   -> bool
parent      :: fn(self: Path)                   -> Path
filename    :: fn(self: Path)                   -> string
extension   :: fn(self: Path)                   -> string
stem        :: fn(self: Path)                   -> string
join        :: fn(self: Path, other: string)    -> Path
starts_with :: fn(self: Path, prefix: Path)     -> bool   // segment-aware
ends_with   :: fn(self: Path, suffix: Path)     -> bool   // segment-aware
normalize   :: fn(self: Path)                   -> Path   // collapse `.` and `..`
```

### `std/process`

Synchronous external-process invocation. Native-only in MVP — the runtime
wires `posix_spawnp` + pipes to capture stdout/stderr; on the WASM target
the imports are unbound and fail at link time (WASI preview2's process API
is post-MVP). Used by the self-host build pipeline to drive `cc`.

```vader
ProcessError :: struct { msg: string }              // implements Error
ProcessResult :: struct {
    exit:   i32
    stdout: string
    stderr: string
}

spawn :: fn(argv: string[]) -> ProcessResult | ProcessError

// Lower-level primitives `spawn` is built on (capture lives in thread-local state).
spawn_run         :: fn(argv: string[]) -> i32       // run, return exit code
spawn_last_stdout :: fn() -> string                  // captured stdout of the last spawn_run
spawn_last_stderr :: fn() -> string                  // captured stderr of the last spawn_run
```

`argv[0]` is the program name (resolved against `PATH`); `argv[1..]` are
arguments. Stdin is inherited from the parent — no MVP need to wire a stdin
pipe (most tooling reads its inputs from files). Single-threaded by design:
the runtime captures the most recent run's output into module-level buffers;
calling `spawn` again replaces them. Returns `ProcessError` when argv is
empty, the program can't be launched, or the child is killed by a signal.

### `std/json`

Recursive-descent JSON parse + stringify, pure Vader. Numbers are stored as `f64` (loses precision past 2^53 — fine for compiler use cases).

```vader
JsonValue :: JsonString | JsonNumber | JsonBool | JsonNull | JsonArray | JsonObject
JsonString :: struct { value: string }
JsonNumber :: struct { value: f64 }
JsonBool   :: struct { value: bool }
JsonNull   :: struct {}
JsonArray  :: struct { items: JsonValue[] }
JsonObject :: struct { entries: MutableMap<string, JsonValue> }

JsonError  :: struct { msg: string, pos: usize }   // implements Error

parse            :: fn(input: string)                -> JsonValue | JsonError
stringify        :: fn(v: JsonValue)                  -> string
stringify_pretty :: fn(v: JsonValue, indent: i32)     -> string
```

`parse` returns `JsonValue | JsonError` explicitly.

### Out of MVP

- networking (no HTTP / sockets in stdlib)
- compile-time-generated JSON parsers (runtime parser ships today via `std/json`)
- threads / async
- compression

### Landed in stdlib (beyond the core MVP set)

The following modules ship in `stdlib/std/` today, alongside the core MVP set documented above:

- `std/abort` — `panic` / `todo` / `unreachable` (the diverging-fn primitives; prelude-level).
- `std/base64` — encode / decode.
- `std/cli` — declarative flag parsing (`FlagSpec`, `parse_known`).
- `std/crypto` — basic hashing primitives.
- `std/semver` — `Version` / `VersionRange` parsing and comparison.
- `std/json` — runtime parser + emitter.
- `std/path` — POSIX path manipulation (`Path.join`, `Path.parent`, `Path.normalize`).
- `std/process` — process spawning / argv.
- `std/random` — PRNG.
- `std/regex` — minimal regex engine.
- `std/sort` — stable mergesort.
- `std/testing` — `assert` / `assert_eq` consumed by `@test` functions.
- `std/time` — clock / formatting.

Listed here because they're in-tree but not part of the frozen v1.0 surface in §15.

---

## 16. Concurrency (post-MVP)

### MVP

**No concurrency.** Synchronous blocking I/O. Single-threaded program.

### Post-MVP — async/await

Add `async` and `await` keywords. Single-threaded cooperative semantics, lowered to state machines at compile time. Portable across the four targets.

### Later — coroutines

Continuation-passing coroutines envisioned, to provide better ergonomics than plain `async`/`await`.

### Native threads

Possibly post-MVP, in `std/thread`, **not available on the WASM target** (compile-time assertion if imported on WASM).

---

## 17. Compilation Targets

### Native (Linux, macOS, Windows)

- Backend = **portable C emission**, invokes `cc` (gcc, clang, or tcc depending on availability).
- Minimal C runtime: Cheney semi-space copying GC + string helpers + I/O helpers via libc.
- Future possibility: direct ASM backends per target.

### WebAssembly

- Backend = **direct WASM emission** (~1:1 mapping from bytecode IR).
- Uses WASM GC proposal for structs/arrays.
- MVP target: **browser** (priority 1). Imports/exports via `@extern`/`@export`.
- WASI: upcoming.

### IR (Intermediate Representation)

A first-class debug/inspection target. The bytecode IR is emitted as a standalone build artifact in one of two formats:

- `--target=ir` → `.vir` — **binary** module, compact, what `vader run program.vir` consumes.
- `--target=ir-text` → `.virt` — **textual**, line-oriented, human-readable; `vader run program.virt` re-parses it back into the in-memory bytecode without touching the original source.

Both formats:
- mirror the in-memory bytecode 1:1 (stack-based);
- include source positions (mapping IR ops back to `file:line:col` in the original Vader source);
- are generated for the **whole program** post-monomorphization: every specialized generic instance is materialized.

Use cases:
- Debugging the compiler pipeline ("did monomorphization specialize as expected?").
- Inspecting what `@comptime` produced.
- Reproducing a bug without the full source tree.
- Sharing a minimal repro with a third party.

### Single codegen strategy

A single C native backend + a single WASM backend + IR text + IR binary emission = **four output artifacts to maintain** (the IR text form is a near-trivial textualization of the binary form, which is itself the in-memory bytecode written to disk). No QBE/Cranelift/LLVM in MVP.

---

## 18. Tooling

### CLI

| Command | Description |
|---------|-------------|
| `vader run [file]` | Interpret via VM. No arg → REPL *(REPL not yet implemented in the native CLI)* |
| `vader build [file\|--manifest]` | Compile to binary (default target = native) |
| `vader build --target=native` | C-emit → `cc` → native binary (default) |
| `vader build --target=wasm` | Targets WebAssembly *(not yet implemented)* |
| `vader build --target=ir` | Emits a binary `.vir` bytecode module *(not yet implemented)* |
| `vader build --target=c` | Emits the generated C source only |
| `vader fmt [path]` | Single opinionated formatter, **no config**; defaults to recursive walk under `.` |
| `vader test [path]` | Runs all functions marked `@test` *(not yet implemented in the native CLI; the test suite runs through the TS driver today)* |
| `vader lsp` | Runs the Language Server (JSON-RPC over stdin/stdout). Spawned by VS Code / IntelliJ |
| `vader dump --stage=<stage> file.vader` | Dumps an IR stage (text or JSON depending on stage) |
| `vader init [name]` *(post-MVP)* | Scaffolds a new Vader project: directory, `examples/hello.vader`, default `vader.json` |

`vader dump` stages, in pipeline order (`lexer`, `resolved-ast`, `cfg`, `bytecode-cfg`, `c`/`wasm` produce text; the rest produce JSON):

| Stage | Output |
|-------|--------|
| `lexer` | Token stream + diagnostics (text) |
| `ast` | Parser AST, spans elided |
| `resolved-ast` | Per-module symbol table + import wiring (text — byte-aligned with `vader/resolver/dump.vader`) |
| `typed-ast` | Per-decl + per-expression types |
| `evaluated-ast` | `@comptime` / `@file` values + generic instances |
| `lowered-ast` | Desugared tree (match / `?` / interp / defer expanded) |
| `dced-ast` | Lowered tree post-stdlib reachability prune |
| `cfg` | Mid-IR CFG (post-DCE + escape-annotated) |
| `bytecode` | Stack-machine ops + type/string/import tables |
| `bytecode-cfg` | Bytecode with CFG-level const-folding (text) |
| `c` | Generated C source |
| `wasm` *(planned)* | WebAssembly module |

### REPL

Interactive mode (`vader` with no arg). Reuses the VM.

### Tests

```vader
import "std/testing" { assert_eq }

@test
test_addition :: fn() {
    assert_eq(1 + 1, 2)
}
```

`assert_eq` / `assert` / `assert_ne` / `assert_close` and friends live in `std/testing` (see §15) — `std/testing` is not auto-imported, every test module imports the asserts it uses.

### Debugging

Both IDE integrations (VS Code, IntelliJ) target full step-by-step debugging with variable inspection. The strategy has two phases.

#### Protocol: DAP (Debug Adapter Protocol)

DAP is the standard (same role as LSP, but for debuggers). A single Debug Adapter implementation serves both VS Code and IntelliJ (IntelliJ supports DAP natively since 2022 via `com.intellij.xdebugger`). The adapter communicates with the IDE over JSON-RPC (stdin/stdout or TCP) and drives the Vader runtime.

```
IDE (VS Code / IntelliJ)
    ↕  JSON-RPC
Debug Adapter
    ↕
Vader runtime (VM or native binary)
```

#### Short term — native backend via lldb-dap

The C emitter already outputs `#line` directives that map every instruction back to the originating `.vader` file and line. This is sufficient to drive `lldb-dap` (LLVM's official DAP adapter, shipped with clang) or an equivalent GDB wrapper without writing any custom adapter code.

What this requires:

- Verify that `#line` directives carry both file and column (not just line) for precise cursor placement.
- Provide a launch configuration for VS Code (`launch.json`) and IntelliJ that invokes `vader build` then hands the binary to `lldb-dap`.
- Document the workflow in the editor plugins.

Limitations: local variable names may appear mangled (e.g. `fibonacci$n` instead of `n`), and Vader-level types are not visible — the debugger sees the C representation. The experience works but is not polished.

#### Medium term — VM debugger with native DAP server

Once the VM is stable (or self-hosting is underway), a Vader-native Debug Adapter is added to the interpreter. `vader run --debug [--port=N]` starts the VM in debug mode and exposes a DAP server.

What the VM must expose:

- **Source map**: every bytecode instruction carries a `(file, line, col)` span. This information is already available in the compiler (every node has a `Span`); the bytecode emitter must forward it into the emitted instructions.
- **Pause / continue / step_in / step_over / step_out**: the VM event loop checks a debug flag before each instruction dispatch.
- **Breakpoints**: a table of `(file, line) → instruction offset` populated from the source map; the VM pauses when the program counter hits a registered offset.
- **Frame inspection**: on `stopped`, the adapter walks the current call frame and serialises local bindings as `(name: string, value: VaderValue)` pairs. Structured values (structs, arrays) are serialised as DAP `Variable` trees.
- **DAP events**: `stopped` (reason: breakpoint / step / exception), `continued`, `terminated`, `output` (for `println` in debug session).

This approach gives source-level debugging entirely in Vader terms (original variable names, Vader types) and works before the native backend is complete. It also serves as the debug runtime for WASM targets where lldb is not available.

#### WASM

DWARF emission, debuggable in Chrome DevTools / wasmtime. The VM DAP server (medium-term) is the preferred path for WASM debugging once available.

### LSP

The Language Server lives in Vader under `vader/lsp/`. It's spawned by editors via `vader lsp`, speaks JSON-RPC over stdin/stdout, and exposes:

- **Hover** — type / signature for the symbol under the cursor.
- **Go-to-definition** — resolved via the Vader resolver's span-keyed `IdentExpr → Symbol` map (`vader/resolver/body.vader::ResolvedFile.idents`).
- **Completion** — symbol-table lookups + scope-aware filtering.
- **Semantic tokens** — two-phase classifier (`vader/lsp/ast_tokens.vader`). Phase 1 is a positional walker that paints every ident from its AST position (decl name, type position, value position). Phase 2 (`refine_via_resolver`) reads the resolved-ident map and overrides Phase 1 tokens whose ident resolves to a Symbol with a more specific kind — `Param` paints `Parameter`, `Local` paints `Variable`, primitive type names (`i32`, `string`, …) paint `Type`. The same resolver is reused by the compiler.

VS Code and IntelliJ extensions live under `editors/vscode/` and `editors/intellij/` and ship the `vader lsp` binary as their language server.

### Diagnostics

Diagnostic plumbing is **MVP-mandatory** and consumed by both the CLI rendering (text + JSON) and the LSP boundary. The intent: a single structured shape feeds every consumer; no phase produces strings that only one consumer knows how to parse.

**Design principles**:

- **Structured, not stringly-typed**. Every diagnostic carries `severity` (`error` / `warning` / `info` / `hint`), `code` (stable identifier like `T3001`), `message`, primary `span`, optional secondary spans (with their own labels), optional `notes`, and optional machine-readable `fixes`.
- **Continuation after error**. No phase aborts on the first diagnostic. The lexer recovers at the next newline; the parser at the next top-level keyword or matching brace; the type-checker continues per-declaration. The user sees a maximal harvest of issues in one run.
- **Two output modes from the same data**:
  - **Terminal**: rich rendering with source snippet, primary-span underline, color, fix hints.
  - **JSON**: stable schema, suitable for LSP consumption and CI tooling. Toggle via `--diagnostics=json` on every command that compiles.
- **Source positions are byte-accurate**. The LSP needs UTF-16 column counts; we emit UTF-8 byte offsets and rely on a small conversion layer at the LSP boundary, so the compiler stays in one encoding.

**Diagnostic codes** are issued per-phase with prefixes:
- `L0xxx` lexer
- `P1xxx` parser
- `R2xxx` resolver
- `T3xxx` type-checker
- `C4xxx` comptime engine
- `M5xxx` MIR lowering (AST → Lowered IR)
- `B5xxx` backend (per-target codegen)
- `W0xxx` warnings (non-fatal)

A registry of codes lives in `src/diagnostics/codes.ts` (TypeScript) and `vader/diagnostics/codes.vader` (self-host). The two registries are kept in lockstep — same IDs, same wording, same enum order.

Notable cross-pass placement rules:
- **`R2006`** (unresolved identifier) and **`R2009`** (trait name does not refer to a trait) are emitted at the resolver stage by the body-walker / project pre-resolve pass, not by the typechecker.
- **`R2018`** (orphan impl forbidden) runs in a project-level pre-resolve pass after `wireImports` so cross-module ImportBinding redirects resolve correctly.
- **`T3050`** / **`T3051`** validate `@extern` decls (ABI shape + body-absent) — emitted during fn-decl typing.
- **`W0002`** (unreachable code) fires once per block on the first stmt past a divergent guard (`return` / `break` / `continue`).
- **`M5xxx`** lowering codes use the `M` prefix (Middle-IR) rather than `L` to avoid collision with `L0xxx` lexer codes — same reasoning as `B5xxx` for backend.

---

## 19. Self-hosting Strategy

### Vader 1.0 — the bootstrap edition

The **Vader 1.0 edition** corresponds to the set of features needed for the Vader compiler to compile its own source code. At successful bootstrap, this perimeter is frozen.

Subsequent evolutions:
- v1.x: backwards-compatible changes (new features, optimizations)
- v2.0: breaking changes (new edition, re-bootstrap required)

### Goal — self-host as soon as possible

As soon as the TS compiler can compile simple functions (a syntactic subset: fns, ifs, loops, structs, arrays, strings, imports, traits), we begin porting piece by piece. The intent: **validate the language design early** by using it to write itself.

### Porting order

1. **Lexer** ✅ (`vader/lexer/`) — straightforward, table-driven.
2. **Parser** ✅ (`vader/parser/`) — recursive-descent + Pratt expressions.
3. **Resolver** ✅ (`vader/resolver/`) — body-walking + top-level minting + import collection + trait method synthesis (intrinsic / default / SAM). Shared by the LSP and the typechecker.
4. **Formatter** ✅ (`vader/fmt/`) — idempotent + parse round-trip on the stdlib.
5. **LSP** ✅ (`vader/lsp/`) — hover, definition, completion, semantic tokens (consumes the resolver).
6. **VM** ✅ (`vader/vm/`) — runs the bytecode for the whole snippet corpus.
7. **Type-checker** ✅ (`vader/typecheck/`).
8. **Comptime / monomorphizer** ✅ (`vader/comptime/`).
9. **Lowerer** ✅ (`vader/lower/`).
10. **Mid-IR (CFG / SSA / DCE / escape / scheduler)** ✅ (`vader/midir/`).
11. **Bytecode-emit** ✅ (`vader/bytecode/`).
12. **C-emit** ✅ (`vader/c_emit/`).
13. **WASM-emit** ⏳ (post-MVP — binary encoding, Phase 3).

Legend: ✅ ported, ⏳ not yet (post-MVP).

The full native pipeline is self-hosted. The only stage still TS-only is the WASM
emitter, which is post-MVP.

### Bootstrap status — achieved

The fixed point has been reached: the Vader-built compiler reproduces its own
generated C **byte-for-byte** (`stage1.c == stage2.c`), and a committed,
gzip-compressed C seed (`bootstrap/bootstrap.c.gz`) lets any machine with a C
compiler rebuild the entire toolchain from source with no Bun or TypeScript in
the cold-start path — see [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md). CI rebuilds
from the seed on every push.

The TypeScript compiler under `src/` is now only the day-to-day development
driver and the reference the self-host port is checked against; it is slated for
removal (TODO §2.8) once the self-host is fully sealed. Snapshot and parity tests
run the native Vader CLI as the oracle for every stage.

---

## 20. Examples

### Hello World

```vader
import "std/io" { println }

main :: fn() -> i32 {
    println("Hello, World!")
    return 0
}
```

### Fibonacci

```vader
import "std/io" { println }

fib :: fn(n: u32) -> u64 {
    if n < 2 { return u64(n) }
    return fib(n - 1) + fib(n - 2)
}

main :: fn() -> i32 {
    for i in 0..<10 {
        println("fib(${i}) = ${fib(i)}")
    }
    return 0
}
```

### Array build + iterate

```vader
import "std/io" { println }

main :: fn() -> i32 {
    list: i32[] = []
    for i in 0..<5 {
        list.push(i * i)
    }
    for x in list {
        println("$x")
    }
    return 0
}
```

### Trait + impl

```vader
import "std/io" { println }

Display :: trait {
    to_string :: fn(self) -> string
}

Point :: struct {
    x: f64
    y: f64
}

Point implements Display {
    to_string :: fn(self) -> string {
        return "(${self.x}, ${self.y})"
    }
}

main :: fn() -> i32 {
    p :: Point { .x = 1.5, .y = 2.5 }
    println(p.to_string())
    return 0
}
```

### Pattern matching + errors

```vader
import "std/io" { read_file, println }
import "std/string" { parse_int, trim }

read_count :: fn(path: string) -> i32 | Error {
    raw := read_file(path)?            // read_file → string | Error
    n   := parse_int(trim(raw))?       // parse_int → i32 | ParseError; ParseError widens to Error
    return n
}

main :: fn() -> i32 {
    match read_count("count.txt") {
        is i32   as count -> println("Count: ${count}")
        is Error as err   -> println("Error: ${err.message()}")
    }
    return 0
}
```

### `@comptime`

```vader
import "std/io" { println }

squares :: fn() -> u32[] {
    result: u32[] = []
    for i in 0..<10 {
        result.push(u32(i * i))
    }
    return result
}

@comptime
SQUARES :: squares()

main :: fn() -> i32 {
    for s in SQUARES {
        println("${s}")
    }
    return 0
}
```

### `@extern` — calling JS from WASM

Same shape as the C path (§13) — the 2-arg form gives the WASM `(module, field)` pair. The compiler will materialise `(import "env" "alert" (func …))` in the module's import section. String parameters are still allowed and marshalled into a `(ptr: i32, len: i32)` pair pushed onto the WASM stack; the user-side glue (JS) reads the linear memory accordingly.

```vader
@extern("env", "alert")
js_alert :: fn(msg: string) -> void

@export("greet")
greet :: fn() -> void {
    js_alert("Hello from Vader!")
}

main :: fn() -> i32 {
    return 0
}
```

HTML/JS side:
```html
<script>
const memory = new WebAssembly.Memory({ initial: 256 });
const decoder = new TextDecoder("utf-8");
const imports = {
    env: {
        alert: (ptr, len) => {
            const buf = new Uint8Array(memory.buffer, ptr, len);
            window.alert(decoder.decode(buf));
        }
    }
};
WebAssembly.instantiateStreaming(fetch("app.wasm"), imports).then(({ instance }) => {
    instance.exports.greet();
});
</script>
```

---

## Appendices

### A. MVP TypeScript implementation roadmap

1. **Lexer**: tokens, newline-significant handling, strings with interpolation parsed as composed tokens
2. **Parser**: full AST covering expressions / statements / declarations
3. **Resolver**: modules, imports, scoping
4. **Type-checker**: bidirectional inference, narrowing, traits, match exhaustiveness
5. **Comptime engine + monomorphizer**: bytecode VM, `@comptime` execution, generic instantiation
6. **Lowerer**: pattern match → if/else chains, traits → static dispatch chain (`is StructA -> StructA_method(...)`), `?` → match
7. **Mid-IR (CFG)**: LoweredAST → CFG converter; substrate for escape analysis, loop-carried-dependency check, dead-store elimination
8. **Bytecode emitter**: from CFG (not directly from lowered AST)
9. **VM**: bytecode interpretation (mode `vader run` + comptime)
10. **IR text emitter**: serialize the bytecode into a human-readable `.virt` file with source-position annotations
11. **IR text reader**: parse `.virt` back into in-memory bytecode for `vader run program.virt`
12. **C emitter**: from bytecode
13. **WASM emitter**: from bytecode
14. **Stdlib in Vader**: core, io, string, collections, math, builder, iter
15. **C runtime**: Cheney semi-space copying GC (stop-the-world, shadow-stack roots), string helpers, basic syscalls
16. **CLI**: `run`, `build` (with `--target=ir|native|wasm`), `fmt`, `test`, `dump`, REPL
17. **Snapshot tests**: for each sample, snapshot the output of every stage

### B. Deferred decisions / topics to revisit

- `unsafe` for low-level FFI (native need)
- Explicit allocator API (arena, etc.) for perf-critical zones
- Auto string marshalling WASM ↔ JS
- Async / await
- Continuation-passing coroutines
- Native threads (`std/thread`)
- Networking, regex, time, random
- Programmable build API (`build.vader`)
- External packages
- Pure WASM compilation without WASI
- Full array slicing
- `vader init [name]`: project scaffolder (creates the dir, an `examples/hello.vader`, and a default `vader.json`)

Already landed (cross-reference for B's reader):
- `std/json` (in MVP — §15 `std/json`)
- LSP (`vader/lsp/`, partial — server + completion / hover / definition / semantic tokens)
- Resolver self-host (`vader/resolver/` — 9 modules)
- Reflection intrinsics `@type_of`, `@fields`, `@type_args`, `@field`, `@comptime for` loop unrolling
- FFI VM host registry (`@extern` user imports now run on the VM via a host-side handler table)
- Lazy iterator combinators (`MapIterator`, `FilterIterator`, `TakeIterator`, `SkipIterator` in `std/iter`)
- Mid-IR CFG layer + escape analysis + loop-carried-dependency check
- Single-binary distribution (`bun build --compile` + per-OS tarballs)
- Reference benchmark suite (`bench/`)
- Self-host VM (`vader/vm/`, partial — runs `.virt` text bytecode subset)

### C. Glossary

- **UFCS**: Uniform Function Call Syntax. `a.f(b)` ≡ `f(a, b)`.
- **Comptime**: Compile-Time Execution. Vader code executed during compilation.
- **Monomorphization**: generation of specialized versions of a generic function/struct for each concrete combination of type parameters.
- **CFG**: Control Flow Graph. Nodes are basic blocks (linear instruction sequences); edges are control transitions (conditional / unconditional branches). Vader's Mid-IR materialises a CFG between the Lowered AST and the bytecode emitter so analyses (escape, liveness) can use def-use chains.
- **HIR / MIR / LIR**: High/Mid/Low Intermediate Representation. Vader v1.0 has two IRs (the Lowered AST + the Mid-IR CFG) feeding the bytecode emitter.
- **SAM**: Single Abstract Method. A trait with exactly one required method; impls may use a short body-only form (`Foo implements Trait -> expr`) instead of the full `name :: fn(...) { ... }` decl.
- **VM**: the stack-based virtual machine that executes bytecode (interp + comptime modes).
- **Bootstrap**: compilation of the Vader compiler with itself.
