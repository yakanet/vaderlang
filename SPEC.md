# Vader Language Specification

> **Status**: Draft — Edition Vader 1.0 (target for bootstrap)
> **Author**: Mathieu BROUTIN
> **Last revision**: 2026-05-06

This document describes the Vader language, its execution model, type system, MVP standard library, and bootstrap strategy. It serves as the reference for the TypeScript implementation of the compiler, then for its self-rewrite in Vader.

---

## 1. Vision

### Mission

Vader is a **general-purpose application language**, **strongly typed with type inference**, **portable** (Linux, macOS, Windows, WebAssembly), designed to remain **simple to learn** (close to Java/Kotlin/TypeScript in mental model) while allowing performant programs through a transparent compilation pipeline.

### Tagline

> *"Vader: applicative, simple, portable. The discipline of static typing, the ergonomics of a script."*

### Explicit non-goals

- **No OOP** — no inheritance, no classes, no "real" methods. UFCS (`a.f(b)` ≡ `f(a, b)`) covers object-call ergonomics.
- **No visible pointers** in source code. No pointer arithmetic. Memory layout is opaque.
- **No implicit `null`**. Nullability is expressed only as an explicit union (`T | null`).
- **No exceptions** in the Java/Python sense. Errors are values.
- **No text macros** nor runtime reflection. Metaprogramming goes through typed `@comptime`.

### Philosophy

- **Simplicity over exotic features** — no feature for the feature's sake.
- **Reading > writing** — syntax must read top to bottom, with no ambiguous `<`.
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
  ↓ Lowerer          → Desugaring (pattern match → jumps, traits → vtables/inline, try → match)
  ↓ DCE              → Lowered AST with stdlib decls unreachable from user code pruned
  ↓ Bytecode emitter → Bytecode IR (stack-based)
  │
  ├──→ Stack-based VM   → vader run / @comptime
  ├──→ IR text emitter  → .vir file (debug / inspection / replay)
  ├──→ C emitter        → cc → native binary (Linux/macOS/Windows)
  └──→ WASM emitter     → .wasm (~1:1 mapping with bytecode, since WASM is also stack-based)
```

### Canonical IR

The canonical IR is a **stack-based bytecode**. This IR is the pivot of the ecosystem:

- it is directly executable by the **VM** (interp + comptime modes)
- it is translatable to **C** (text) for the native backend
- it maps **1:1** to WASM (both are stack-based)

### Comptime ↔ monomorphization

The compile-time execution (CTE) engine and generic monomorphization are the **same machinery**. When `List(i32)` is instantiated, the engine evaluates at compile time to generate the specialized code. For a `@comptime fn`, the same VM executes the bytecode.

The pipeline is therefore **incremental**: to evaluate a `@comptime`, its dependencies must be compiled-to-bytecode, executed, and the result injected into the AST before continuing.

### Monomorphization

Monomorphization runs **after** the comptime pass and **before** the lowerer. The comptime pass populates a registry of every concrete generic instantiation that appears in the program (e.g. `List(i32)`, `Map(string, User)`); the monomorphizer reads this registry and clones each generic decl once per `(decl, type-args)` pair, substituting type parameters in signatures, field types, and bodies. The output is a flat AST with **no abstract generics**: every `Struct(args)` reference points to a freshly-emitted concrete decl, and every generic-fn call is rewritten to call its specialised instance.

Registry collection is **transitive**: when `outer<i32>` is observed, the comptime pass walks `outer`'s body, substitutes `T = i32`, and observes every nested generic call site (`inner_fn(arr)` becomes `inner_fn<i32>`), every `for x in arr` over `[T]` (registers `ArrayIter(i32)`), and every substituted struct/trait reference inside the body (so e.g. `Yielded(string)` materialises when `step` is monomorphised over a `[string]`). The fixpoint is bounded — recursive generic types are caught by an iteration cap rather than custom heuristics.

Lowering and every downstream phase therefore see only concrete types — they never have to invent dispatch logic for `$T`.

### Lowered AST

The lowerer consumes the monomorphised typed AST and produces a **separate, smaller AST** (the *Lowered AST*) where high-level constructs are desugared into a fixed set of primitive operations the backends understand. The original typed AST is never mutated. Specifically the lowerer:

- **Pattern match → if/else chains.** Naive linear lowering: each arm becomes a guarded `if` whose predicate is the pattern's discriminator (type tag, struct shape, literal equality) ∧ its optional `if`-guard. Bindings introduced by `is T as x` and struct destructuring become local lets at the head of the arm body. No decision-tree compilation in MVP — naive code is fine for the bytecode emitter to optimise later.
- **`expr?` → `match`.** Lowered to `match expr { is Error e -> return e; is T t -> t }` over the typed scrutinee. Every `Error`-implementing variant routes to a `return` of that same value; the happy variant becomes the expression's result.
- **String interpolation → builder intrinsics.** Each `"…${x}…"` lowers to a sequence of `builder.new`, `builder.append_str`, `builder.append_display(x)`, `builder.finish` intrinsic calls. The runtime (which `std/string_builder` wraps) provides the actual implementation; the lowerer only emits the call chain. `builder.append_display` is dispatched statically per the post-mono `Display` impl table.
- **`defer` → exit-point duplication.** The lowerer keeps a per-block stack of pending defers (LIFO) and inlines them physically at every textual exit of the block: implicit fallthrough, `return`, `break`, `continue`. Panics are **not** unwound through defers in MVP (panics abort the program). Defers do not propagate across function boundaries.
- **Trait calls → static dispatch.** Because monomorphization has stripped abstract generics, every trait-method call site has a concrete receiver type. The lowerer rewrites `recv.show()` to a direct call of the specific impl's function. No vtable / dynamic dispatch in MVP.
- **No inserted runtime checks.** The lowerer does not synthesize bounds checks, null checks, division-by-zero guards, or overflow checks. Type narrowing already covers nullability; the remaining safety checks are the runtime's responsibility (when emitted) or are explicitly out of scope for MVP.

The Lowered AST is the input to the dead-code elimination pass. It is dumpable as JSON via `vader dump --stage=lowered-ast` for debugging and snapshot tests.

### Dead-code elimination

Between the lowerer and the bytecode emitter, a DCE pass prunes lowered declarations that are not transitively reachable from a small set of roots. This keeps unused stdlib machinery out of the final artifact: `std/core` is auto-imported in every program, but a `hello world` doesn't need `Range`, `ArrayIter`, `Done`, `Yielded`, `IOError`, or their impls — DCE drops them before emission.

Roots — preserved unconditionally:

- every decl from a non-stdlib module (the user's own code is never DCE'd, so library targets and snapshot fixtures without `main` keep all their decls);
- `main` (the fn whose mangled name ends in `$main` and has a body);
- any decl carrying `@export`, `@test`, or `@extern` (`@extern` covers signature-only imports — the import table must stay aligned with what the host expects).

`@comptime` and `@file` constants are not automatic roots — their value is inlined at each use site by the bytecode emitter, so an unreferenced one is genuinely dead. They are still preserved when defined in a non-stdlib module by the user-code rule.

Reachability is computed via BFS over the Lowered AST: every `LoweredIdent.symbol.id` and every struct/trait `Type.symbol.id` encountered is added to the live set. Trait dispatch is already statically resolved by the lowerer (one impl-member symbol per call site), so there is no need to over-approximate by keeping every impl of a referenced trait. The pass is a pure `LoweredProject → LoweredProject` transform and is shared across backends. It is dumpable via `vader dump --stage=dced-ast`.

### Exposed execution modes

- `vader run script.vader`: parse + typecheck + interp via VM. No binary emission.
- `vader build [file|--manifest]`: full pipeline + emission of either C-based native binary or WASM.
- `vader` (no args): REPL.

### Compile-time sandbox

Code in `@comptime` context can:

- ✅ compute (pure functions)
- ✅ allocate memory and manipulate structures
- ✅ read project files (equivalent to v1 `@file`)
- ⚠️ read `ENV` / `args`: **opt-in** only, via `vader build --allow-env`
- ❌ network syscalls / exec / stdout: **forbidden**, to preserve build reproducibility

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

Nested block comments follow the Rust convention. The lexer tracks nesting depth and only closes the outer comment when depth returns to zero.

### Identifiers

`[a-zA-Z_][a-zA-Z0-9_]*`. Case-sensitive. No Unicode in identifiers in MVP.

### Reserved keywords

```
fn struct trait implements impl enum
if else match is for in return defer break continue
import as
private
true false null
where
self
@<decorator>
```

### Literals

#### Integer literals

- Decimal: `42`, `1_000_000`
- Hexadecimal: `0xFF`, `0xff`, `0xFF_FF` (case-insensitive after `0x`)
- Binary: `0b1010`, `0b1010_1010`
- Octal: `0o755`, `0o7_5_5`
- Suffix: `42i32`, `42u64`, `42_i32` (an optional underscore between magnitude and suffix is allowed for readability)
- Default type: `i32` if no suffix and no inferred context.
- Underscore rules: never two in a row (`1__000` is an error), never leading or trailing on the digits (`_42`, `42_` are errors).

#### Float literals

- Standard: `3.14`, `0.5`, `00.5` (leading zeros allowed), `1.0e-10`, `1.5E+3`
- Suffix: `3.14f32`, `3.14f64`, `3.14_f32` (optional underscore before suffix allowed)
- A trailing point with no fractional digits is forbidden: `5.` is an error — write `5.0`.
- A bare `.5` is forbidden — write `0.5`.
- Default type: `f64` if no suffix.
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
- Raw strings (`r"..."`) emit `STRING_BEGIN`, a single `STRING_PART` (with the literal contents, no escape processing, no interpolation scan), then `STRING_END`.

### Operators

```
Arithmetic   : + - * / %
Bitwise      : & | ^ ~ << >>
Comparison   : == != < <= > >=
Membership   : in   (sugar for `right.contains(left)`)
              !in   (sugar for `!right.contains(left)`, parsed as `bang` + `kw_in`)
Type test    : is Type   (used in match arms)
Logical      : && || !
Assignment   : =
Declaration  : :: (immutable)  := (mutable)
Range        : 0..<10 (exclusive)  0..=10 (inclusive)
Postfix      : ? (try, propagates the error)
Cast         : Type(expr) (Go-style; numeric ↔ numeric, char ↔ integer)
Field access : .name
Index access : [expr]
```

`in` and `!in` desugar to a method call on the `Contains($T)` trait (see §11). Char comparisons (`<`, `<=`, `>`, `>=`) work on codepoint order (`char` is wire-compatible with `u32`).

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
| 10    | `<`, `<=`, `>`, `>=`, `==`, `!=`, `is`, `in`, `!in` | non-assoc      |
| 11    | `&&`                                   | left           |
| 12    | `\|\|`                                 | left           |
| 13    | `=` (statement-level only)             | n/a            |

Type casts (`Type(expr)`) are parsed as primary call expressions and naturally sit at level 1. The `is Type` form used in `match` arms binds at the comparison level.

### Statement separators

Inside a block, statements are separated by `NEWLINE` tokens (emitted per the rules below). Vader does **not** accept `;` as a statement separator.

A leading newline immediately after `{` is silently absorbed: a block may start on a new line without an empty statement.

### Trailing commas

Trailing commas are allowed in every comma-separated list: function arguments, function parameters, struct literal fields, struct definition fields, array literals, match arms, generic argument lists, and import destructuring lists.

### Newline-significant

A newline terminates a statement (Go-style). No `;` is required. The lexer emits a `NEWLINE` token at every line break **except** in the four cases below, where the newline is silently absorbed:

1. **Inside an unclosed bracket** `(`, `[`, or `{` — newlines inside parens / array / block construction are insignificant.
2. **After a binary or unary operator** that is still pending an operand: `+`, `-`, `*`, `/`, `%`, `<`, `<=`, `>`, `>=`, `==`, `!=`, `&&`, `||`, `&`, `|`, `^`, `<<`, `>>`, `..<`, `..=`, `?` (postfix is fine, only prefix-pending matters), and unary `!`.
3. **After a comma** `,`.
4. **After `=`, `:`, `->`, or `=>`** (the right-hand side is expected to follow).

There is **no backslash-continuation** (`\` at end of line is not special). If you need to break a long expression, use one of the four cases above (typically wrap in parentheses, or break after a binary operator).

```vader
// OK: break inside parens
total := (a +
          b +
          c)

// OK: break after operator
total := a +
         b +
         c

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
| Signed integers | `i8`, `i16`, `i32`, `i64` |
| Floats | `f32`, `f64` |
| Text | `char` (32-bit codepoint), `string` (UTF-8 sequence) |
| Null | `null` |

### Built-in type aliases

To ease migration from Java/Kotlin and reduce typing in everyday code, the compiler recognises a set of **canonical aliases** for primitive types. They are fully transparent — the compiler treats an alias and its target as the same type everywhere (error messages, snapshots, inference).

| Alias | Resolves to | Java / C equivalent |
|-------|-------------|---------------------|
| `int` | `i32` | Java `int`, C `int32_t` |
| `long` | `i64` | Java `long`, C `int64_t` |
| `float` | `f32` | Java `float`, C `float` |
| `double` | `f64` | Java `double`, C `double` |
| `byte` | `u8` | Java `byte` (sign differs — Vader byte is unsigned) |

`char` and `string` are already first-class names in the primitive table, so they need no alias.

`usize` is a **target-dependent** unsigned integer used for sizes and indexes (analogous to C's `size_t`, Rust's `usize`). It maps to `size_t` in the C backend (typically 64-bit on modern hosts). The bytecode/VM bootstrap treats it as a 64-bit value. The WASM backend will choose the platform-native width when implemented (likely WASM64 only at first).

These are **built-in** aliases recognised by the resolver and type-checker; they are *not* user-defined type aliases (those use the `name :: type SomeType` form). Aliases are not reserved keywords — they are identifiers that resolve to a builtin-type symbol, so user code may shadow them in local scope (though this is strongly discouraged).

### Default integer

A literal integer with no suffix **infers to `i32`** (`x := 42` ⇒ `x: i32`).

### Default float

A literal float with no suffix **infers to `f64`** (`x := 3.14` ⇒ `x: f64`).

### Implicit numeric coercion

There is **no implicit coercion between sized numeric types**. `i32 → i64` requires an explicit cast (`i64(x)`). The exception is unsuffixed numeric literals: `let x: i64 = 42` works because `42` is left flexible until it lands in a typed context.

### Signed overflow

`a + b` that overflows **panics in debug, wraps in release** (Rust-style). Behavior not configurable in MVP.

### Strings

- Internals: **fat value** `(ptr: rawptr, len: u32)` — 16 bytes copied on assignment, no shared reference.
- Immutable. Concatenation allocates.
- `len()` returns the number of UTF-8 **bytes**.
- `chars()` or `codepoints()` returns an iterator of `char`.
- Literals stored in the binary's data section.

### Arrays

- `[T]` is a dynamic array (runtime length).
- **Implicit reference** semantics: `arr2 := arr` copies the reference; use `clone(arr)` (free function) for a real copy.
- Indexing: `arr[i]`. Bounds-checked in debug (panic), elidable in release.
- Slicing: `arr[0..<3]` (to validate in MVP, otherwise deferred).

### Structs

```vader
Point :: struct {
    x: f64
    y: f64
}

p :: Point { .x = 1.0, .y = 2.0 }
```

- Heap-allocated by default (Java-style).
- `p2 := p` copies the **reference**, not the contents.
- `==` is reference identity by default. For structural comparison: implement the `Eq` trait, or call a free function `equals(a, b)`.
- Field layout is **not guaranteed** (the compiler arranges fields freely).
- The user has no access to the layout (no `@offset_of`, no `unsafe_cast` in MVP).

#### Struct literals in `if` / `for` / `match` / `while` conditions

A `Foo { ... }` literal opens a `{` that would collide with the body brace of a control-flow statement. To keep the grammar unambiguous, struct literals are **not allowed at the top level** of the condition expression of `if`, `for`, `match`, and (future) `while`. Wrap in parentheses if needed:

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

### Unions (TS-style)

```vader
Result :: type string | i32 | null

show :: fn(r: Result) -> string {
    match r {
        is string -> r
        is i32    -> Display.show(r)
        is null   -> "(none)"
    }
}
```

- Ad-hoc union declared via `Name :: type A | B | C`.
- `T | null` is the standard idiom for nullability.
- A union `A | B` satisfies a trait `T` if **and only if** both `A` and `B` implement it.
- Runtime representation: `(tag, payload)` (tagged sum). The compiler chooses the tag size.

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

`==` and `!=` work on enum values and compare by variant identity. No explicit `Eq` impl is required.

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

Allowed backing types: `i8`, `i16`, `i32`, `i64`, `u8`, `u16`, `u32`, `u64`. Omitting the suffix is equivalent to `enum(i32)`.

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
    fn show(self) -> string {
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
    _                    -> "other"
}
```

- `is Type` for narrowing
- Struct patterns with bindings and constraints
- Guards via `if cond`
- Wildcard `_`
- **Exhaustiveness checked** by the compiler. For union scrutinees, every variant must be covered (or matched by a wildcard `_`). For non-union scrutinees a wildcard arm is required, since the compiler cannot enumerate all values of, say, `i32`.

### Type inference

**Bidirectional**, TS/Swift-style:

- Local: `x := 12` infers `x: i32`.
- Top-down: function signatures used to infer lambda arguments.
- No global Hindley-Milner (by simplicity choice).
- **Function signatures must be fully annotated** (no top-level inference).

### Casts

Go-style, "constructor-call" syntax:

```vader
x: i32 = 42
y: i64 = i64(x)            // widening cast, safe
z: u8  = u8(x)             // narrowing cast, panics in debug if overflow
```

**`char` ↔ integer** : `char` is a `u32` codepoint at the wire level, so casts between `char` and any integer type (`i32`, `u32`, `i64`, `u64`, `usize`, …) are allowed and reinterpret the bits with a tag change. Casts between `char` and float types are rejected — go through an integer first.

```vader
c   := 'A'
n   := u32(c)              // 65
back := char(n + u32(1))   // 'B'
```

For risky conversions (parsing), use explicit functions returning unions:

```vader
n: i32 | Error = parse_int("42")
```

### Generics — Pure Odin

**Generic functions**: type parameter introduced inline with `$T`; subsequent uses without `$`.

```vader
map :: fn(items: [$T], f: fn(T) -> $U) -> [U] {
    result: [U] = []
    for x in items {
        result.push(f(x))
    }
    return result
}
```

**Generic structs**: type params declared up front with `$` prefix.

```vader
List :: struct($T) {
    items: [T]
    len: u32
}

list := List(i32) { .items = [1, 2, 3], .len = 3 }
```

**Constraints** via `where`. Multiple traits combined with `&` (intersection) — the same separator as type intersections:

```vader
sort :: fn(items: [$T]) where T: Ord {
    // ...
}

put :: fn(self: MutableMap($K, $V), key: K, value: V) where K: Hash & Eq {
    // ...
}
```

`&` mirrors `|` (union) — `K: A | B` would mean K satisfies either, `K: A & B` means K satisfies both. **Only `&` is in MVP scope** ; `|` on bounds is post-MVP.

**Compile-time values** (post-MVP candidate):

```vader
make_buffer :: fn($N: i32) -> [N]u8 { ... }
```

**Implementation**: monomorphization at compile time, driven by the comptime engine. Single specialization machinery.

**Limitations (MVP)**:
- **No "associated functions"** (Java-style static methods) — `Type.method(args)` syntax is not parsed. Factory functions are written as free functions and called via UFCS or directly: `new_path("foo/bar")`, `MutableMap(K, V) { ... }` for struct-literal construction. Post-MVP candidate.
- **No trait-method dispatch on bounded type parameters** — inside a generic body, `key.hash()` where `key: $K` and `K: Hash` doesn't resolve, since the typechecker doesn't propagate where-clause methods to type-params. Workaround: pass dispatch as `fn`-typed parameters or specialise per concrete key type. Post-MVP work.

### Traits

A trait defines a contract of methods (in practice, UFCS-callable functions on a type).

```vader
Display :: trait {
    fn show(self) -> string
}

u32 implements Display {
    fn show(self) -> string {
        // ... implementation
    }
}

print_it :: fn(x: $T) where T: Display {
    println(x.show())
}
```

- Declaration: `Name :: trait { ... }`.
- Implementation: `T implements Trait { ... }` (three forms — see below).
- A union satisfies a trait iff all its members satisfy it.
- Operator overloading via stdlib traits — see *Operator overloading* below.
- **`self` and `Self`**: inside a trait or impl, the first parameter conventionally named `self` carries an implicit `Self` type — no annotation required. `Self` refers to the type that implements the trait; in an `impl Foo` block, `Self = Foo`. Outside trait/impl context, `Self` is undefined (`T3023`).

#### Method dispatch on trait values

A receiver typed as a trait dispatches **virtually** at runtime:

```vader
report :: fn(e: Error) -> string {
    return e.message()       // dispatches on `e`'s actual struct tag
}
```

The lowerer synthesises an `is StructA -> StructA_method(...)` chain over every impl of the trait that's in scope. Generic-struct impls are skipped (their concrete instance args aren't recoverable from the trait-typed receiver alone), so virtual dispatch covers non-generic impls and primitives that share a Display/Hash trait. Dynamic-dispatch on generic structs is post-MVP.

Inside a generic body, `key.method()` where `key: $T` and `T: Trait` resolves at typecheck and is monomorphised statically — each call site gets a direct call to the concrete impl member after substitution. No runtime dispatch.

#### Single-method trait sugar (SAM)

When a trait has **exactly one method**, the implementation may omit the redundant `fn name(...) -> RetType` line and write the body directly. The compiler synthesises the signature from the trait declaration; parameter names (`self`, `other`, …) come from the trait and are in scope of the body — no redeclaration required.

```vader
// Arrow form — single-expression body.
i32   implements Hash -> u64(self)
i32   implements Eq   -> self == other

// With generic trait args.
Tutu  implements Toto(i32, i64) -> i64(self + other)

// Block form — multi-statement body.
string implements Hash {
    h: u64 = 14695981039346656037
    n: usize = self.length()
    i: usize = 0
    while i < n {
        h = (h ^ u64(self.char_at(i))) * 1099511628211
        i = i + 1
    }
    return h
}

// Classic form — required for traits with two or more methods.
ArrayIter($T) implements Iterator(T) {
    fn step(self) -> Done | Yielded(T) { ... }
}
```

- Detection: the impl body starts with `->` (arrow) or `{` not followed by `fn` (block).
- The classic form (`{ fn name(...) ... }`) remains valid and is **required** for multi-method traits.
- `R2016` is emitted when the short forms are used on a trait with 0 or ≥ 2 methods.

#### Operator overloading

Built-in operators dispatch through stdlib traits when the operand types are not primitive numerics (or when `==` / `<` are applied to user types).

| Operator        | Trait              | Method                                      |
|-----------------|--------------------|---------------------------------------------|
| `a + b`         | `Add`              | `fn add(self, other: Self) -> Self`         |
| `a - b`         | `Sub`              | `fn sub(self, other: Self) -> Self`         |
| `a * b`         | `Mul`              | `fn mul(self, other: Self) -> Self`         |
| `a / b`         | `Div`              | `fn div(self, other: Self) -> Self`         |
| `a % b`         | `Rem`              | `fn rem(self, other: Self) -> Self`         |
| `a == b`        | `Eq`               | `fn equals(self, other: Self) -> bool`      |
| `a < b` / `<=` / `>` / `>=` | `Ord`  | `fn compare(self, other: Self) -> i32`      |
| `a[i]`          | `Index($I, $T)`    | `fn at(self, i: I) -> T`                    |
| `a[i] = v`      | `IndexSet($I, $T)` | `fn set_at(self, i: I, v: T)`               |
| `v in a`        | `Contains($T)`     | `fn contains(self, v: T) -> bool`           |

Compound assignments (`+=`, `-=`, `*=`, `/=`, `%=`) desugar to `lhs = lhs <op> rhs` at parse time, so they reuse the corresponding trait dispatch.

Resolution rule for arithmetic and comparison operators :
1. If both operands are primitive numerics, use the built-in op (current behaviour).
2. Otherwise, look up the trait `impl` for the left operand's type. The right operand must be assignable to the trait's expected `Self` (or its parameter for `Index`/`IndexSet`/`Contains`).
3. If no impl matches, error.

Index access (`a[i]`) and `in` follow the same fallback : built-in array / range first, then trait dispatch.

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
| Struct, array | **Reference identity** (Java-style) |
| Type with `impl Eq` | Delegated to `Eq.equals` |

To compare two structs structurally, implement `Eq` or call `equals(a, b)`.

---

## 5. Variables and Bindings

### Three operators

- **`x :: <expr>`**: **immutable** declaration. The binding cannot be reassigned.
- **`x := <expr>`**: **mutable** declaration. The binding can be reassigned via `=`.
- **`x = <expr>`**: reassignment of an existing mutable variable.

### Mutability = binding only

`::` freezes the binding, not the contents. If `p :: Point { ... }`, you cannot `p = otherPoint`, but `p.x = 5` is allowed.

For deep immutability of collections, use **stdlib convention** :
- raw `[T]` arrays are mutable (Java-style — `arr.push`, `arr[i] = v`)
- read-only `List(T)` / `Map(K, V)` / `Set(T)` will pair with mutable variants when implemented (post-MVP — currently struct stubs in `std/collections`)

### Explicit type annotations

```vader
x: i64 = 42
buffer: [u8] = []
name: string | null = null
```

The annotation `: T` is used when inference cannot decide or to clarify intent.

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
```

`return` is valid anywhere. If the last expression of a block is an expression and its type matches the return type, `return` is optional.

**No-return functions** drop the `-> void` annotation. Internally the compiler still has a unit/void type, but it is not user-facing — `void` is **not** a name available in source code. Function-pointer types that produce no value drop the arrow likewise: `callback: fn()` instead of `callback: fn() -> void`. This mirrors Rust's `()` being implicit.

### `main` entry point

The program entry is a fn called `main` declared at module scope. It accepts exactly one of two shapes (T3033 otherwise) :

```vader
main :: fn() -> i32                 // ignore argv
main :: fn(argv: [string]) -> i32   // receive process args
```

`argv[0]` is implementation-defined : the script path under `vader run`, the binary path under a native build. User-supplied args start at `argv[1]`.

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
sum :: fn(...nums: [i32]) -> i32 {
    total := 0
    for n in nums { total = total + n }
    return total
}

sum(1, 2, 3, 4)
```

### Closures / lambdas

Full form, identical to functions:

```vader
inc :: fn(x: i32) -> i32 { x + 1 }
items.map(fn(x: i32) -> i32 { x * 2 })
```

**Type annotations on lambda parameters and return are optional** when the surrounding context provides them via bidirectional inference:

```vader
items.map(fn(x) { x * 2 })            // x and return inferred from map's signature
items.map(fn(x: i32) -> i32 { x * 2 }) // explicit, also valid
```

Top-level function declarations (`name :: fn(...)`) still require full annotations — see §4 inference rules.

Closures capture their environment **by reference** (consistent with the Java-style model). Captured locals are heap-promoted into single-slot cells at the lowering pass: the cell lives on the GC heap, the binding becomes a pointer to it, and every closure that mentions the variable shares the same cell. This is what makes mutation visible across closures (a counter built via `n := 0; inc :: fn() { n = n + 1 }; get :: fn() -> i32 { n }` works as expected). Lifting itself is transparent: the closure value is a `(code, env)` fat pointer where `code` points to a synthesised top-level fn taking the env as its first parameter, and `env` is a heap-allocated struct holding refs to the captured cells.

### Function values

The function-type form `fn(T1, T2, ...) -> R` (or `fn(T1, T2, ...)` for void return) is a **first-class type**: it can appear anywhere a type is allowed — fn parameters, struct fields, array elements, locals, return types. A function name used outside of an immediate call yields a function value:

```vader
add :: fn(a: i32, b: i32) -> i32 { return a + b }

main :: fn() -> i32 {
    f := add               // f: fn(i32, i32) -> i32
    return f(2, 3)         // indirect call — same syntax as direct
}
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

#### Function overloading

Two free functions with the same name **may coexist in the same module** when they differ in the type of their **first parameter** (the receiver). The resolver dispatches based on the receiver's type at the call site.

```vader
size :: fn(self: Path) -> i32 { ... }
size :: fn(self: MutableMap($K, $V)) -> usize { ... }

p.size()            // resolves to the Path version
m.size()            // resolves to the MutableMap version
```

Rules :
- Overload candidates must differ in their first parameter type. Differing only on later parameters is **not** an overload (post-MVP — see TODO).
- Type-param receivers (`fn(self: $T)`) are wildcards and conflict with every concrete-receiver overload of the same name.
- Resolution is performed at typecheck after the receiver type is known. Errors out with `R2004` if two candidates match.

### Visibility

- **`public` by default** (Java-style).
- **`private`** to hide a symbol outside its **module** (= folder).

```vader
private helper :: fn(x: i32) -> i32 {
    // visible to other files in the same module, not outside
}
```

---

## 7. Control Flow

### `if` / `else` (expression)

```vader
x :: if (b > 2) 2 else 3

if (cond) {
    // ...
} else if (other) {
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
    _                   -> "?"
}
```

Exhaustive match on unions, checked at compile time.

### `for` (universal loop)

```vader
// Exclusive range
for i in 0..<10 {
    println("$i")
}

// Inclusive range
for i in 0..=10 { ... }

// Iterate over a collection (built-in array, Iterator, or Iterable)
for item in items {
    println(item)
}

// While-like
for cond {
    // ...
}

// Infinite
for {
    if exit_condition { break }
}
```

The iteration form `for x in expr` accepts three shapes for `expr`:
1. A built-in array `[T]` — auto-wrapped in `ArrayIter(T)`.
2. A value of type `Iterator(T)` — used directly.
3. A value implementing `Iterable(T)` — `expr.iter()` is auto-called and the result drives the loop.

Raw `[T]` arrays are auto-wrapped in `ArrayIter(T)`, and `Range` (`0..<10`) iterates directly. User collections opt in by implementing `Iterable(T)` so `for x in coll { ... }` works without an explicit `coll.iter()`.

```vader
Iterable :: trait($T) {
    fn iter(self) -> Iterator(T)
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

Block-scoped, executed when leaving the block where it was written (Zig/Swift-style):

```vader
fn process(path: string) -> string! {
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
// if read_file returns string | Error :
//   - if Error : the current function returns that Error
//   - else     : content receives the string

// Chainable
first_line :: read_file("a.txt")?.lines()?.first()?
```

`expr?` is only usable inside a function whose return type is itself a union including an `Error`.

---

## 8. Memory Model

### GC

All non-primitive values (struct, array, string buffer contents, future stdlib types) are allocated on the **GC-managed heap**.

### GC backends

- **Native (C)**: hand-written **Cheney semi-space copying GC** (stop-the-world), in C, linked into the binary. Two arenas of equal size (16 MB each by default); allocation is bump-pointer; collection copies live objects from the from-space to the to-space and swaps. Roots are enumerated **precisely** via a shadow stack: every emitted C function pushes a `vader_gc_frame_t` chained through `prev` containing the addresses of its ref-typed locals, popped on return. Per-type pointer maps emitted by the compiler tell the scanner where the heap pointers live inside each object.
- **WASM**: uses the `(ref struct)`, `(ref array)`, `anyref` types of the WASM GC proposal (the host runtime — wasmtime / V8 — performs GC).

### Storage semantics

**Java-style**:

- Primitives (`i32`, `f64`, `bool`, etc.): value, copied on assignment.
- `string`: fat value `(ptr, len)`, copied on assignment, immutable shared content.
- Structs, arrays: heap-allocated, manipulated via implicit references (the user does not see pointers).

### No visible pointers

No `&`, `*`, or "pointer" type exposed in MVP. Memory management is entirely implicit (except via explicit allocator APIs for perf-critical zones, post-MVP).

### Escape analysis

The spec **allows** the compiler to allocate a struct on the stack if analysis proves it does not escape, but **does not require** it in MVP. This is a transparent optimization the user never observes.

### Explicit allocators (post-MVP)

API for perf-critical zones, Zig-style. Allows allocating into an arena, a buffer, etc., without breaking the GC model. To be specified when needed.

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

`\n`, `\t`, `\\`, `\"`, `\$` (literal dollar), `\0`, `\u{1F600}` (codepoint).

### Compile-time verification

Interpolation expressions `${...}` are parsed and **type-checked at compile time**. Errors caught:

- Variable does not exist
- Type incompatible with `Display`
- Malformed expression

Interpolation is **desugared** into calls to `Display.show` followed by concatenation via `StringBuilder`.

### `Display` trait

All primitives implement `Display`. User types must impl explicitly:

```vader
Point implements Display {
    fn show(self) -> string {
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

### `!T` sugar

`!T` is a syntactic alias for `T | Error`, where `Error` is the stdlib's nominal trait:

```vader
read_file :: fn(path: string) -> string!  {
    // equivalent to : -> string | Error
}
```

### `Error` trait

```vader
Error :: trait {
    fn message(self) -> string
}
```

Any type implementing `Error` may be returned by an `!T` function. The stdlib provides concrete errors: `IOError`, `ParseError`, etc.

### `?` operator

Postfix, propagates the error if present:

```vader
process :: fn(path: string) -> string! {
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

### Granularity

**One folder = one module.** All `.vader` files in a folder share a common namespace. Files see each other (including `private` symbols).

### Imports

```vader
import "std/io"                              // access via prefix : io.read_file()
import "std/io" as fs                        // alias : fs.read_file()
import "std/io" { read_file, write_file }    // destructuring : read_file() direct
```

### Path resolution

| Form | Resolution |
|------|-----------|
| `std/...` | Stdlib embedded in the compiler |
| `./foo/bar` | Relative to current file |
| `foo/bar` (no `./`) | Relative to project root (where `vader.json` lives) |

**No external packages in MVP.** Post-MVP topic.

### Manifest

**`vader.json`** at the root, JSON format:

```json
{
  "name": "myapp",
  "version": "0.1.0",
  "entries": {
    "main": "src/main.vader",
    "cli":  "src/cli.vader"
  }
}
```

Manifest is **optional** — `vader build single_file.vader` also works as long as `single_file.vader` contains a `main` function.

### Visibility

- `public` (default): visible everywhere.
- `private`: visible **within the module** (other files in the same folder OK), invisible outside the module.

### Forbidden import cycles

A → B → A is a compile-time error.

### Entry point

Always a `main` function. No overloaded conventions.

```vader
main :: fn() -> i32 {
    println("Hello")
    return 0
}
```

`main` may also return `void` (equivalent to returning `0` from `i32`). Or return `i32!` to propagate errors via `?`.

### What appears at the top level of a `.vader` file

A source file may contain only:

- `import` statements
- Type declarations: `Result :: type ...`
- Function declarations: `name :: fn(...) -> T { ... }`
- Struct declarations: `Foo :: struct { ... }`
- Enum declarations: `Color :: enum { ... }`
- Trait declarations: `T :: trait { ... }`
- Trait implementations: `T implements Trait { ... }`
- Constant declarations: `PI :: 3.14159`
- Decorators on any of the above

**No executable statements at the top level** — no top-level `print(...)`, no top-level loops. Every side-effecting expression lives inside a function body, typically `main`. This keeps the parser simple, makes module loading order independent of execution order, and means `import`-ing a module never runs code (unlike Python).

### Future: programmable build API

Following Jai/Zig, post-MVP: a `build.vader` file that drives the build via Vader code (instead of a declarative manifest).

---

## 12. Decorators

Decorators are **compiler instructions** prefixed with `@`. They operate at compile time, never at runtime.

| Decorator | Target | Purpose |
|-----------|--------|---------|
| `@comptime` | fn / value | Forces compile-time evaluation |
| `@extern("module", "name")` | fn (no body) | Declares an import (WASM) or external symbol (C) |
| `@export` or `@export("name")` | fn | Exposes the function with no name mangling (JS-side / lib-side) |
| `@file` | string literal | Embeds file contents at compile time |
| `@test` | fn | Marks as a test, executed by `vader test` |

The v1 `@intrinsic` is **replaced by `@extern`** to unify the mechanism.

The v1 `@load` is **replaced by `import`**.

---

## 13. FFI / External Functions

### `@extern` — declaring imports

```vader
@extern("env", "console_log")
console_log :: fn(ptr: i32, len: i32)
```

On the **WASM** target, the compiler generates:
```wat
(import "env" "console_log" (func (param i32 i32)))
```

On the **native (C)** target, the compiler generates:
```c
extern void console_log(int32_t, int32_t);
```
and passes `-lenv` (or equivalent) to `cc`.

### String marshalling — no magic in MVP

To pass a Vader string to an external function:

```vader
@extern("env", "console_log")
console_log :: fn(ptr: i32, len: i32)

print_message :: fn(msg: string) {
    console_log(msg.ptr, msg.len)
}
```

The user writes the host-side glue (JS, C) themselves. The Vader JS stdlib provides helpers `vader_string_decode(memory, ptr, len)`.

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
TABLE :: @comptime build_lookup_table()

build_lookup_table :: fn() -> [u32] {
    result: [u32] = []
    for i in 0..<256 {
        result.push(u32(i * i))
    }
    return result
}
```

`build_lookup_table()` runs during compilation. `TABLE` is a constant whose value is placed in the binary's data section.

### Synergy with generics

A call `List(i32)` is a `@comptime` expression (the engine resolves the type, instantiates the generic struct, generates the specialized code).

### Sandbox

See section 2 (Compilation Model).

### Implementation note (TypeScript bootstrap)

The bootstrap compiler runs an **AST-walking interpreter** for `@comptime`, not the bytecode VM described in §2. The op table and stack machine are built later in the bytecode-emitter phase, where they'll be shared by both the comptime engine and the C/WASM emitters. The semantics described above hold either way — the choice is purely an engineering one to avoid designing the op set twice. Self-hosted Vader switches to the bytecode VM uniformly.

---

## 15. Standard Library — MVP scope

### `std/core` (auto-imported)

Traits : `Display`, `Eq`, `Ord`, `Add`, `Sub`, `Mul`, `Div`, `Hash`, `Clone`, `Iterator(T)`, `Iterable(T)`, `Contains(T)`, `Error`.

Types : `Done`, `Yielded(T)`, `Range`, `ArrayIter(T)`.

The `Contains(T)` trait powers the `in` / `!in` operators :

```vader
Contains :: trait($T) {
    fn contains(self, value: T) -> bool
}

// `Range implements Contains(i32)` is shipped, so `5 in 0..<10` works
// out of the box. User types opt in by implementing the trait.
```

Free helpers for primitive `Hash`/`Eq` dispatch (`hash_i32`, `eq_i32`, …) — workaround for trait-method dispatch on bounded type params (post-MVP). String hashing is FNV-1a over the UTF-8 bytes (intrinsic, exposed via `string implements Hash`).

### `std/io`

```vader
fn print(msg: string) -> void
fn println(msg: string) -> void
fn read_line() -> string!
fn read_file(path: string) -> string!
fn write_file(path: string, content: string) -> void!
fn exists(path: string) -> bool
```

I/O is **synchronous blocking** only in MVP.

### `std/string`

Width-based helpers (`pad_start`, `pad_end`) measure bytes, not codepoints.

```vader
// Core access (intrinsics — no body in Vader).
fn len(s: string) -> i32                       // bytes
fn slice(s: string, start: i32, end: i32) -> string
fn char_at(s: string, i: i32) -> char
fn contains(s: string, sub: string) -> bool
fn starts_with(s: string, prefix: string) -> bool
fn ends_with(s: string, suffix: string) -> bool
fn split(s: string, sep: string) -> [string]
fn trim(s: string) -> string
fn to_upper(s: string) -> string
fn to_lower(s: string) -> string
fn parse_int(s: string) -> i32!
fn parse_float(s: string) -> f64!

// Indexing helpers.
fn last_index_of(s: string, c: char, min_index: i32) -> i32

// Format helpers (pure Vader).
fn pad_start(s: string, width: i32, fill: char) -> string
fn pad_end(s: string, width: i32, fill: char) -> string
fn is_whitechar(c: char) -> bool

// Pattern helpers (ad-hoc — no real regex engine in MVP).
fn replace_chars_where(s: string, pred: fn(char) -> bool, replacement: string) -> string
fn trim_suffix(s: string, suffix: string) -> string
fn trim_prefix(s: string, prefix: string) -> string
fn split_whitespace(s: string) -> [string]
```

### `std/numbers`

UFCS-callable numeric formatting.

```vader
fn to_hex(self: u64) -> string   // lowercase, no `0x`, no leading zeros
fn to_bin(self: u64) -> string   // no prefix, no leading zeros
```

Caller pads via `pad_start` (`n.to_hex().pad_start(8, '0')`).

### `std/collections`

All hash-based mutable collections live in a single module. Sequence
collections use raw `[T]` arrays (which already support `push`, `len`,
indexed access, mutation, and `for x in arr`) — no `MutableList` wrapper
in MVP. Immutable `List<T>` will pair with arrays once read-only views
land (post-MVP).

```vader
// Hash map — chaining HashMap with fixed bucket count.
MutableMap(K, V)   where K: Hash + Eq
Map(K, V)          // read-only (struct stub, post-MVP API)
fn put          (self: MutableMap(K, V), key: K, value: V) -> void
fn get          (self: MutableMap(K, V), key: K) -> V | null
fn contains_key (self: MutableMap(K, V), key: K) -> bool
fn len          (self: MutableMap(K, V)) -> usize
fn is_empty     (self: MutableMap(K, V)) -> bool
fn keys         (self: MutableMap(K, V)) -> [K]
fn values       (self: MutableMap(K, V)) -> [V]

// Hash set — wraps a `MutableMap(T, bool)` (Java HashSet pattern). Lookups
// inherit the chained-bucket O(1) behaviour from the underlying map.
MutableSet(T)      where T: Hash + Eq
Set(T)             // read-only (struct stub, post-MVP API)
fn add      (self: MutableSet(T), value: T) -> bool   // true if newly added
fn contains (self: MutableSet(T), value: T) -> bool
fn len      (self: MutableSet(T)) -> usize
fn is_empty (self: MutableSet(T)) -> bool
```

### `std/math`

```vader
// Comparison + helpers — f64-only in MVP. Generic `Ord`-driven variants land
// once trait-method dispatch on bounded type params can construct a `min`
// returning the receiver type (post-MVP).
fn min(a: f64, b: f64) -> f64
fn max(a: f64, b: f64) -> f64
fn abs(x: f64) -> f64
fn lerp(a: f64, b: f64, t: f64) -> f64    // a + (b - a) * t

// Float intrinsics — wired to libm on native, JS Math on the VM.
fn sqrt(x: f64) -> f64
fn pow(x: f64, n: f64) -> f64
fn floor(x: f64) -> f64
fn ceil(x: f64) -> f64
fn round(x: f64) -> f64
fn sin(x: f64) -> f64
fn cos(x: f64) -> f64
fn tan(x: f64) -> f64

const pi: f64
const e:  f64
```

### `std/string_builder`

Efficient string construction. `to_string` flushes via the `concat_all` runtime intrinsic — single allocation sized from the total length, avoids the O(N²) of repeated `+`.

```vader
StringBuilder :: struct { parts: [string] }

fn new_builder()                                -> StringBuilder
fn append      (self: StringBuilder, s: string) -> void
fn append_char (self: StringBuilder, c: char)   -> void
fn to_string   (self: StringBuilder)            -> string
```

### `std/iter`

The iterator trait lives in `std/core` (auto-imported), using a `Done | Yielded(T)` step result rather than `T | null` so iterators over nullable element types stay unambiguous:

```vader
Done    :: struct {}
Yielded :: struct($T) { value: T }

Iterator(T) :: trait {
    fn step(self) -> Done | Yielded(T)
}
```

`std/iter` provides combinators on top of it. Two flavours coexist :

```vader
// Iterator-driven (require trait dispatch through `for x in it`):
fn count(it: Iterator($T))   -> i32
fn collect(it: Iterator($T)) -> [T]

// Array-driven (closure-friendly; eager — return `[T]` or a single value):
fn map(arr: [$T], f: fn(T) -> $U)        -> [U]
fn filter(arr: [$T], pred: fn(T) -> bool) -> [T]
fn fold(arr: [$T], init: $U, f: fn(U, T) -> U) -> U
fn sum(arr: [i32]) -> i32
fn take(arr: [$T], n: i32) -> [T]
fn skip(arr: [$T], n: i32) -> [T]
fn slice(arr: [$T], start: i32, end: i32) -> [T]    // bounds clamped, end exclusive
```

The closure-driven combinators take a concrete `[T]` rather than `Iterator($T)` because direct trait-method dispatch on a generic `$T : Iterator` parameter is post-MVP (the `for x in it` form has compiler-internal dispatch but user code can't `it.step()` directly). Bridging from an iterator goes through `collect(it)` first; once trait dispatch on bounded type params lands the two flavours converge.

### `std/gc`

Garbage-collector introspection and controls. Mostly a debug/test surface :

```vader
fn collect()       -> void   // force a Cheney cycle
fn collections()   -> i32    // total cycles since start
fn bytes_used()    -> i32    // live bytes in from-space
fn bytes_copied()  -> i32    // cumulative bytes copied
```

### `std/path`

Filesystem path manipulation. POSIX `/` separator only in MVP — Windows support deferred. All operations return fresh `Path` values (no mutation).

```vader
Path :: struct { repr: string }

fn to_path     (s: string)                    -> Path
fn empty_path  ()                             -> Path
fn as_string   (self: Path)                   -> string
fn is_empty    (self: Path)                   -> bool
fn is_absolute (self: Path)                   -> bool
fn parent      (self: Path)                   -> Path
fn filename    (self: Path)                   -> string
fn extension   (self: Path)                   -> string
fn stem        (self: Path)                   -> string
fn join        (self: Path, other: string)    -> Path
fn starts_with (self: Path, prefix: Path)     -> bool   // segment-aware
fn ends_with   (self: Path, suffix: Path)     -> bool   // segment-aware
fn normalize   (self: Path)                   -> Path   // collapse `.` and `..`
```

### `std/process`

Synchronous external-process invocation. Native-only in MVP — the runtime
wires `posix_spawnp` + pipes to capture stdout/stderr ; on the WASM target
the imports are unbound and fail at link time (WASI preview2's process API
is post-MVP). Used by the self-host build pipeline to drive `cc`.

```vader
ProcessError :: struct { msg: string }              // implements Error
ProcessResult :: struct {
    exit:   i32
    stdout: string
    stderr: string
}

fn spawn(argv: [string]) -> ProcessResult!
```

`argv[0]` is the program name (resolved against `PATH`) ; `argv[1..]` are
arguments. Stdin is inherited from the parent — no MVP need to wire a stdin
pipe (most tooling reads its inputs from files). Single-threaded by design :
the runtime captures the most recent run's output into module-level buffers ;
calling `spawn` again replaces them. Returns `ProcessError` when argv is
empty, the program can't be launched, or the child is killed by a signal.

### `std/json`

Recursive-descent JSON parse + stringify, pure Vader. Numbers are stored as `f64` (loses precision past 2^53 — fine for compiler use cases).

```vader
JsonValue :: type JsonString | JsonNumber | JsonBool | JsonNull | JsonArray | JsonObject
JsonString :: struct { value: string }
JsonNumber :: struct { value: f64 }
JsonBool   :: struct { value: bool }
JsonNull   :: struct {}
JsonArray  :: struct { items: [JsonValue] }
JsonObject :: struct { entries: MutableMap(string, JsonValue) }

JsonError  :: struct { msg: string, pos: i32 }   // implements Error

fn parse            (input: string)                -> JsonValue | JsonError
fn stringify        (v: JsonValue)                 -> string
fn stringify_pretty (v: JsonValue, indent: i32)    -> string
```

The trait-widening limitation (struct implementing `Error` → `Error`) prevents `T!` sugar on `parse`'s return today (cf. self-host TODO). Returns `JsonValue | JsonError` explicitly.

### Out of MVP

- networking
- real regex engine (ad-hoc helpers ship in `std/string` ; full NFA/DFA post-MVP)
- compile-time-generated JSON parsers (kotlinx-serialization style ; runtime parser ships today via `std/json`)
- time / date
- random
- threads / async
- crypto
- compression

---

## 16. Concurrency (post-MVP)

### MVP

**No concurrency.** Synchronous blocking I/O. Single-threaded program.

### Post-MVP — async/await

Add `async` and `await` keywords. Single-threaded cooperative semantics, lowered to state machines at compile time. Portable across the four targets.

### Later — coroutines

Kotlin-style envisioned (continuation-passing), to provide better ergonomics than plain `async`/`await`.

### Native threads

Possibly post-MVP, in `std/thread`, **not available on the WASM target** (compile-time assertion if imported on WASM).

---

## 17. Compilation Targets

### Native (Linux, macOS, Windows)

- Backend = **portable C emission**, invokes `cc` (gcc, clang, or tcc depending on availability).
- Minimal C runtime: GC mark-sweep + string helpers + I/O helpers via libc.
- Future possibility: direct ASM backends per target.

### WebAssembly

- Backend = **direct WASM emission** (~1:1 mapping from bytecode IR).
- Uses WASM GC proposal for structs/arrays.
- MVP target: **browser** (priority 1). Imports/exports via `@extern`/`@export`.
- WASI: upcoming.

### IR (Intermediate Representation)

A first-class debug/inspection target. The bytecode IR is serialized into a textual `.vir` file alongside any final artifact, and can be requested as the **only** output of a build via `--target=ir`.

- Stack-based, mirrors the in-memory bytecode 1:1.
- Textual, line-oriented, human-readable.
- Includes source positions (mapping IR ops back to `file:line:col` in the original Vader source).
- Generated for the **whole program** post-monomorphization: every specialized generic instance is materialized.
- Loadable: `vader run program.vir` re-executes the IR via the VM without re-parsing the source.

Use cases:
- Debugging the compiler pipeline ("did monomorphization specialize as expected?").
- Inspecting what `@comptime` produced.
- Reproducing a bug without the full source tree.
- Sharing a minimal repro with a third party.

### Single codegen strategy

A single C native backend + a single WASM backend + IR text emission = **three output targets to maintain** (the IR is a near-trivial textualization of the in-memory bytecode). No QBE/Cranelift/LLVM in MVP.

---

## 18. Tooling

### CLI

| Command | Description |
|---------|-------------|
| `vader run [file]` | Interpret via VM. No arg → REPL |
| `vader build [file\|--manifest]` | Compile to binary (default target = native) |
| `vader build --target=wasm` | Targets WebAssembly |
| `vader build --target=ir` | Emits a textual `.vir` IR file (debug / replay) |
| `vader fmt [path]` | Single opinionated formatter, **no config** |
| `vader test [path]` | Runs all functions marked `@test` |
| `vader dump --stage=<stage> file.vader` | Dumps JSON/text of a stage (`ast`, `typed-ast`, `bytecode`, `c`, `wasm`) |
| `vader init [name]` *(post-MVP)* | Scaffolds a new Vader project: creates the directory, an `examples/hello.vader`, and a default `vader.json` manifest |

### REPL

Interactive mode (`vader` with no arg). Reuses the VM.

### Tests

```vader
@test
test_addition :: fn() {
    assert_eq(1 + 1, 2)
}
```

### Debugging

- **WASM**: DWARF emission, debuggable in Chrome DevTools / wasmtime.
- **Native**: `#line` directives in emitted C, gdb / lldb on the binary.
- No Vader-specific debugger tool in MVP.

### Diagnostics

Diagnostic plumbing is **MVP-mandatory** even though the LSP itself is post-self-host. The intent: when we eventually write the LSP in Vader, the entire compiler is already capable of producing the structured diagnostics the LSP needs.

**Design principles**:

- **Structured, not stringly-typed**. Every diagnostic carries `severity` (`error` / `warning` / `info` / `hint`), `code` (stable identifier like `E0001`), `message`, primary `span`, optional secondary spans (with their own labels), optional `notes`, and optional machine-readable `fixes`.
- **Continuation after error**. No phase aborts on the first diagnostic. The lexer recovers at the next newline; the parser at the next top-level keyword or matching brace; the type-checker continues per-declaration. The user sees a maximal harvest of issues in one run.
- **Two output modes from the same data**:
  - **Terminal**: rich rendering with source snippet, primary-span underline, color, fix hints — Rust/Elm-style.
  - **JSON**: stable schema, suitable for LSP consumption and CI tooling. Toggle via `--diagnostics=json` on every command that compiles.
- **Source positions are byte-accurate**. The LSP needs UTF-16 column counts; we emit UTF-8 byte offsets and rely on a small conversion layer at the LSP boundary, so the compiler stays in one encoding.

**Diagnostic codes** are issued per-phase with prefixes:
- `L0xxx` lexer
- `P1xxx` parser
- `R2xxx` resolver
- `T3xxx` type-checker
- `C4xxx` comptime engine
- `B5xxx` backend

A registry of codes lives in `src/diagnostics/codes.ts` (TypeScript) / `compiler/diagnostics/codes.vader` (after self-host) — every code is documented with a short description and an example.

### LSP

**Deferred to post-self-host.** Ideally written in Vader. The compiler is built so that the LSP, when implemented, only needs to consume the existing JSON diagnostic stream and add navigation features (hover, go-to-definition, completion).

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

1. **Parser** (the simplest, mostly pattern matching on tokens)
2. **C-emit** (text emission, mechanical)
3. **Bytecode-emit** (mechanical)
4. **VM** (simple algorithms, dispatch table)
5. **WASM-emit** (slightly more complex due to binary encoding)
6. **Type-checker** (the most complex, last — Vader must be mature enough to self-represent)

### Double-maintenance period

During the transition:

- **Snapshot tests**: for each sample in the test suite, the **TS** compiler's output is snapshotted as the reference. The **Vader-in-Vader** compiler must produce the same output. Guarantees consistency step by step.
- **After successful bootstrap**: the TS compiler is set to read-only. No more bug-fixes nor features added in TS, except emergencies. All evolution happens in Vader.

### Bootstrap success criterion

Let `compile_ts(src)` be the output of the TS compiler on the Vader compiler source `src`.
Let `compile_vader(src)` be the output of the Vader compiler (compiled by TS) on the same source.

**Bootstrap successful** ⇔ `compile_ts(src) == compile_vader(src)` AND `compile_vader(src) == compile_vader(src)` (idempotence over two generations).

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
fib :: fn(n: u32) -> u64 {
    if (n < 2) return u64(n)
    return fib(n - 1) + fib(n - 2)
}

main :: fn() -> i32 {
    for i in 0..<10 {
        println("fib($i) = ${fib(i)}")
    }
    return 0
}
```

### Array build + iterate

```vader
import "std/io" { println }

main :: fn() -> i32 {
    list: [i32] = []
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
    fn show(self) -> string
}

Point :: struct {
    x: f64
    y: f64
}

Point implements Display {
    fn show(self) -> string {
        return "(${self.x}, ${self.y})"
    }
}

main :: fn() -> i32 {
    p :: Point { .x = 1.5, .y = 2.5 }
    println(p.show())
    return 0
}
```

### Pattern matching + errors

```vader
import "std/io" { read_file }
import "std/string" { parse_int }

read_count :: fn(path: string) -> i32! {
    raw := read_file(path)?
    n   := parse_int(raw.trim())?
    return n
}

main :: fn() -> i32 {
    match read_count("count.txt") {
        is i32   -> println("Count: $value")
        is Error -> println("Error: ${value.message()}")
    }
    return 0
}
```

### `@comptime`

```vader
import "std/io" { println }

squares :: fn() -> [u32] {
    result: [u32] = []
    for i in 0..<10 {
        result.push(u32(i * i))
    }
    return result
}

SQUARES :: @comptime squares()

main :: fn() -> i32 {
    for s in SQUARES {
        println("$s")
    }
    return 0
}
```

### `@extern` — calling JS from WASM

```vader
@extern("env", "alert")
js_alert :: fn(ptr: i32, len: i32)

@export("greet")
greet :: fn() {
    msg :: "Hello from Vader!"
    js_alert(msg.ptr, msg.len)
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
6. **Lowerer**: pattern match → jumps, traits → vtables/inline, `?` → match
7. **Bytecode emitter**: from lowered AST
8. **VM**: bytecode interpretation (mode `vader run` + comptime)
9. **IR text emitter**: serialize the bytecode into a human-readable `.vir` file with source-position annotations
10. **IR text reader**: parse `.vir` back into in-memory bytecode for `vader run program.vir`
11. **C emitter**: from bytecode
12. **WASM emitter**: from bytecode
13. **Stdlib in Vader**: core, io, string, collections, math, builder, iter
14. **C runtime**: mark-sweep stop-the-world GC, string helpers, basic syscalls
15. **CLI**: `run`, `build` (with `--target=ir|native|wasm`), `fmt`, `test`, `dump`, REPL
16. **Snapshot tests**: for each sample, snapshot the output of every stage

### B. Deferred decisions / topics to revisit

- `unsafe` for low-level FFI (native need)
- Explicit allocator API (arena, etc.) for perf-critical zones
- Auto string marshalling WASM ↔ JS
- Async / await
- Kotlin-style coroutines
- Native threads (`std/thread`)
- Networking, regex, json, time, random
- LSP
- Programmable build API (`build.vader`)
- External packages
- Pure WASM compilation without WASI
- Full array slicing
- `vader init [name]`: project scaffolder (creates the dir, an `examples/hello.vader`, and a default `vader.json`)

### C. Glossary

- **UFCS**: Uniform Function Call Syntax. `a.f(b)` ≡ `f(a, b)`.
- **Comptime**: Compile-Time Execution. Vader code executed during compilation.
- **Monomorphization**: generation of specialized versions of a generic function/struct for each concrete combination of type parameters.
- **HIR / MIR / LIR**: High/Mid/Low Intermediate Representation. Vader v1.0 has a single IR (the bytecode); later levels possible.
- **VM**: the stack-based virtual machine that executes bytecode (interp + comptime modes).
- **Bootstrap**: compilation of the Vader compiler with itself.
