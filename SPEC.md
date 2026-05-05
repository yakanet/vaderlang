# Vader Language Specification

> **Status**: Draft — Edition Vader 1.0 (target for bootstrap)
> **Author**: Mathieu BROUTIN
> **Last revision**: 2026-05-04

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

Lowering and every downstream phase therefore see only concrete types — they never have to invent dispatch logic for `$T`.

### Lowered AST

The lowerer consumes the monomorphised typed AST and produces a **separate, smaller AST** (the *Lowered AST*) where high-level constructs are desugared into a fixed set of primitive operations the backends understand. The original typed AST is never mutated. Specifically the lowerer:

- **Pattern match → if/else chains.** Naive linear lowering: each arm becomes a guarded `if` whose predicate is the pattern's discriminator (type tag, struct shape, literal equality) ∧ its optional `if`-guard. Bindings introduced by `is T as x` and struct destructuring become local lets at the head of the arm body. No decision-tree compilation in MVP — naive code is fine for the bytecode emitter to optimise later.
- **`expr?` → `match`.** Lowered to `match expr { is Error e -> return e; is T t -> t }` over the typed scrutinee. Every `Error`-implementing variant routes to a `return` of that same value; the happy variant becomes the expression's result.
- **String interpolation → builder intrinsics.** Each `"…${x}…"` lowers to a sequence of `__builder_new`, `__builder_append_str`, `__builder_append_display(x)`, `__builder_finish` intrinsic calls. The runtime / std/builder provides the actual implementation; the lowerer only emits the call chain. `__builder_append_display` is dispatched statically per the post-mono `Display` impl table.
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
type      // used in (T: type) for generics
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
Logical      : && || !
Assignment   : =
Declaration  : :: (immutable)  := (mutable)
Range        : 0..<10 (exclusive)  0..=10 (inclusive)
Postfix      : ? (try, propagates the error)
Cast         : Type(expr) (Go-style)
Field access : .name
Index access : [expr]
```

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
| 10    | `<`, `<=`, `>`, `>=`, `==`, `!=`, `is` | non-assoc      |
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
| Unsigned integers | `u8`, `u16`, `u32`, `u64` |
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

For risky conversions (parsing), use explicit functions returning unions:

```vader
n: i32 | Error = parse_int("42")
```

### Generics — Pure Odin

**Generic functions**: type parameter introduced inline with `$T`; subsequent uses without `$`.

```vader
map :: fn(items: [$T], f: fn(T) -> $U) -> [U] {
    result := MutableList(U){}
    for x in items {
        result.add(f(x))
    }
    return result.to_list()
}
```

**Generic structs**: type params declared up front.

```vader
List :: struct(T: type) {
    items: [T]
    len: u32
}

list := List(i32) { .items = [1, 2, 3], .len = 3 }
```

**Constraints** via `where`:

```vader
sort :: fn(items: [$T]) where T: Ord {
    // ...
}
```

**Compile-time values** (post-MVP candidate):

```vader
make_buffer :: fn($N: i32) -> [N]u8 { ... }
```

**Implementation**: monomorphization at compile time, driven by the comptime engine. Single specialization machinery.

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
- Implementation: `T implements Trait { ... }`.
- A union satisfies a trait iff all its members satisfy it.
- Operator overloading via stdlib traits: `Add`, `Sub`, `Mul`, `Div`, `Eq`, `Ord`, `Hash`, `Clone`.
- **`self` and `Self`**: inside a trait or impl, the first parameter conventionally named `self` carries an implicit `Self` type — no annotation required. `Self` refers to the type that implements the trait; in an `impl Foo` block, `Self = Foo`. Outside trait/impl context, `Self` is undefined (`T3023`).

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

For deep immutability, use **stdlib convention**:
- `List<T>`: read-only
- `MutableList<T>`: mutable
(Kotlin-style)

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
```

`return` is valid anywhere. If the last expression of a block is an expression and its type matches the return type, `return` is optional.

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

Closures capture their environment **by reference** (consistent with the Java-style model).

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

// Iterate over a collection
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

- **Native (C)**: hand-written mark-sweep stop-the-world GC, in C, linked into the binary.
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
match read_file("a.txt") {
    is string -> println("got: ${value}")
    is Error  -> println("error: ${value.message()}")
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
    result := MutableList(u32){}
    for i in 0..<256 {
        result.add(i * i)
    }
    return result.to_list()
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

Traits: `Display`, `Eq`, `Ord`, `Add`, `Sub`, `Mul`, `Div`, `Hash`, `Clone`, `Iterator<T>`, `Iterable<T>`, `Error`.
Type: `Error` (base).

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

```vader
fn len(s: string) -> u32                       // bytes
fn chars(s: string) -> Iterator(char)
fn slice(s: string, range: Range) -> string
fn contains(s: string, sub: string) -> bool
fn starts_with(s: string, prefix: string) -> bool
fn ends_with(s: string, suffix: string) -> bool
fn split(s: string, sep: string) -> [string]
fn trim(s: string) -> string
fn to_upper(s: string) -> string
fn to_lower(s: string) -> string
fn parse_int(s: string) -> i32!
fn parse_float(s: string) -> f64!
```

### `std/collections`

```vader
List(T)              // read-only
MutableList(T)       // mutable
Map(K, V)            // read-only
MutableMap(K, V)     // mutable
Set(T)               // read-only
MutableSet(T)        // mutable
```

Kotlin convention: `Mutable*` is a subtype of the read-only version.

### `std/math`

```vader
fn min(a, b)        // generic via Ord
fn max(a, b)
fn abs(x)
fn sqrt(x: f64) -> f64
fn pow(x: f64, n: f64) -> f64
fn floor(x: f64) -> f64
fn ceil(x: f64) -> f64
fn round(x: f64) -> f64
fn sin / cos / tan
const pi: f64
const e:  f64
```

### `std/builder`

```vader
StringBuilder :: struct {
    fn append(self, s: string) -> void
    fn append_char(self, c: char) -> void
    fn to_string(self) -> string
}
```

### `std/iter`

```vader
Iterator(T) :: trait {
    fn next(self) -> T | null
}

// Methods/UFCS on Iterator
fn map<T, U>(it: Iterator(T), f: fn(T) -> U) -> Iterator(U)
fn filter<T>(it: Iterator(T), pred: fn(T) -> bool) -> Iterator(T)
fn fold<T, A>(it: Iterator(T), init: A, f: fn(A, T) -> A) -> A
fn sum / count / take / skip / collect
```

### Out of MVP

- networking
- regex
- json
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

### Generic List

```vader
import "std/collections" { MutableList }

main :: fn() -> i32 {
    list := MutableList(i32){}
    for i in 0..<5 {
        list.add(i * i)
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
    result := MutableList(u32){}
    for i in 0..<10 {
        result.add(u32(i * i))
    }
    return result.to_list()
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
