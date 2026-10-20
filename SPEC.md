# Vader Language Specification

> **Status**: Draft — Edition Vader 1.0 (target for bootstrap)
> **Author**: Mathieu BROUTIN
> **Last revision**: 2026-05-12

This document describes the Vader language, its execution model, type system, MVP standard library, and bootstrap strategy. It served as the reference for the original TypeScript implementation of the compiler, then for its self-rewrite in Vader — now the sole, self-hosted compiler.

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
  ↓ Lowerer          → Desugaring (pattern match → if/else chains, traits → static dispatch)
  ↓ DCE              → Lowered AST with stdlib decls unreachable from user code pruned
  ↓ Mid-IR (CFG)     → Reducible CFG with basic blocks + terminators; substrate for escape / liveness analyses
  ↓ Bytecode emitter → Bytecode IR (stack-based)
  │
  ├──→ Stack-based VM   → vader run / @comptime
  ├──→ IR text emitter  → .vir file (debug / inspection / replay)
  ├──→ C emitter        → cc → native binary (Linux/macOS/Windows)
  └──→ WASM emitter     → .wasm (~1:1 mapping with bytecode, since WASM is also stack-based)
```

Self-host status (Vader-side under `vader/`): the full native pipeline is self-hosted — Lexer ✅, Parser ✅, Resolver ✅ (9 modules under `vader/resolver/`), Type-checker ✅, Comptime/monomorphizer ✅, Lowerer ✅, Mid-IR (CFG/DCE/escape/scheduler) ✅, Bytecode emitter ✅, C emitter ✅, LSP ✅, Formatter 🟡 (partial — see §18), VM 🟡 (`.virt` subset). WASM emitter ⏳ (post-MVP — see §19). The legacy TypeScript bootstrap under `src/` has been removed; self-host correctness is verified by the bootstrap fixed-point check (`bootstrap/verify.sh`) and the snapshot suite, not by cross-toolchain parity.

### Canonical IR

The canonical IR is a **stack-based bytecode**. This IR is the pivot of the ecosystem:

- it is directly executable by the **VM** (interp + comptime modes)
- it is translatable to **C** (text) for the native backend
- it maps **1:1** to WASM (both are stack-based)

### Comptime ↔ monomorphization

The compile-time execution (CTE) engine and generic monomorphization are the **same machinery**. When `List<i32>` is instantiated, the engine evaluates at compile time to generate the specialized code. For a `@comptime fn`, the same VM executes the bytecode.

The pipeline is therefore **incremental**: to evaluate a `@comptime`, its dependencies must be compiled-to-bytecode, executed, and the result injected into the AST before continuing.

### Monomorphization

Monomorphization runs **after** the comptime pass and **before** the lowerer. The comptime pass populates a registry of every concrete generic instantiation that appears in the program (e.g. `Range<i32>`, `MutableMap<string, User>`); the monomorphizer reads this registry and clones each generic decl once per `(decl, type-args)` pair, substituting type parameters in signatures, field types, and bodies. The output is a flat AST with **no abstract generics**: every `Struct<args>` reference points to an emitted decl, and every generic-fn call is rewritten to call the instance that serves it — a per-type clone, or a shared erased body for reference type arguments (see *Instance flavor* below).

Registry collection is **transitive**: when `outer<i32>` is observed, the comptime pass walks `outer`'s body, substitutes `T = i32`, and observes every nested generic call site (`inner_fn(arr)` becomes `inner_fn<i32>`), every `for x in arr` over `T[]`, and every substituted struct/trait reference inside the body (so e.g. `[string, Continuation]` materialises when `next` is monomorphised over a `string[]`). The fixpoint is bounded — recursive generic types are caught by an iteration cap rather than custom heuristics.

Lowering and every downstream phase therefore never see an *unbound* type parameter: each instance's type arguments are either substituted to concrete types or erased to the uniform-pointer representation, per its **instance flavor** (below).

### Instance flavor (monomorphise vs erase)

Cloning *every* instance in full would blow up code size — a `List<T>` used at ten different reference types would emit ten identical pointer-shuffling bodies. So each observed `(decl, type-args)` instance is classified into one of three **flavors**, which decide how its type arguments are represented in the emitted body. The split keys on whether a type argument is a **primitive value-type** — the fixed-width numerics (`i8`…`i64`, `u8`…`u64`), `f32`/`f64`, `bool`, `char`, `string`, distinct newtypes over any of these, an integer range, and an enum, kept as itself — or a **reference type** (structs, arrays, tuples, closures — everything represented at runtime as a uniform pointer):

- **Mono** — full concrete substitution, one body per instance (`second__i32`). A free fn is `Mono` when it dispatches a trait method on a type parameter (the call must bind to a concrete impl) or returns a `T[]`.
- **Mixed** — at least one type argument is a primitive. Primitive parameters stay **concrete and raw** — a `Box<i64>` field is laid out as a raw `i64` (not a boxed slot), and `msg.to_string()` on a primitive resolves to the one impl statically — while reference parameters are erased to the uniform pointer. Mangling keeps one body per distinct primitive shape (`Box__i64`, `Box__f32`, …).
- **Erased** — every type argument is a reference type. All type parameters erase to a single uniform-pointer representation (spelled `Any`), so identical erased instances **deduplicate to one emitted body**, and a trait-method call on an erased receiver dispatches at runtime on the boxed tag. A reference is a reference regardless of what it points to, so one body serves them all.

The classifier is `fn_instance_flavor` in `vader/lower/lower_mono_fn.vader` for free functions, with the matching struct-layout and impl-materialisation logic in `vader/lower/lower_mono_struct.vader` and `vader/lower/lower_subst.vader`. The payoff is the **box-vs-raw partition**: a primitive instance is fully concrete (its representation is known statically, primitive ops inline, no vtable), while a reference instance stays erased and uniform (small code, one shared body). Because the split is derived structurally from the type arguments, generics need no per-declaration "always specialise" annotation — the compiler already keeps every primitive instance concrete on its own.

### Lowered AST

The lowerer consumes the monomorphised typed AST and produces a **separate, smaller AST** (the *Lowered AST*) where high-level constructs are desugared into a fixed set of primitive operations the backends understand. The original typed AST is never mutated. Specifically the lowerer:

- **Pattern match → if/else chains.** Naive linear lowering: each arm becomes a guarded `if` whose predicate is the pattern's discriminator (type tag, struct shape, literal equality) ∧ its optional `if`-guard. The `match x :: e` binder becomes a local binding ahead of the arms; struct destructuring binds locals at the head of the arm body. No decision-tree compilation in MVP — naive code is fine for the bytecode emitter to optimise later.
- **`expr?` → `match`.** Lowered to `match v :: expr { is Error -> return v  is T -> v }` over the typed scrutinee. Every `Error`-implementing variant routes to a `return` of that same value; the happy variant becomes the expression's result.
- **String interpolation → one string build.** Each `"…${x}…"` lowers to plain Vader calls on the `std/core` byte-buffer API, or to the shared `concat_N` when no segment is an integer or a bool (§9 *Compile-time verification*). A segment of any other type renders through its `Display.to_string`, called directly when the impl is known at that point.
- **`defer` → a per-frame stack of thunks.** Each `defer` body is lifted into a closure over the locals it captures (a captured local is promoted to a heap cell), and the `defer` statement pushes it onto the frame's defer stack (`defer.push`). Every exit of a block pops and runs the thunks registered since the block was entered, LIFO (`defer.pop_exec N`): implicit fallthrough, `return` (every block up to the fn root), `break` / `continue` (every block up to the target loop's body). A value leaving the block — a `return` value, a trailing expression — is computed before the thunks run. In an async coroutine the stack lives in the coroutine's frame, so it survives a suspension. A `panic` (or trap) **runs the pending defers** of every frame it unwinds through — LIFO, innermost frame first — before the process aborts; the panic stays fatal (no recovery). Each frame runs its own defers as the stack tears down; defers do not otherwise propagate across function boundaries.
- **Trait calls → a direct call where the receiver is concrete.** A call whose receiver has a concrete type becomes a direct call of that type's impl member: `recv.to_string()` calls the receiver's own `to_string`. A call on a trait-typed value (a parameter typed `Display`, an `Iterator<T>` held in a field, the receiver inside an erased generic instance) dispatches through a vtable instead (`virtual.call`), filled by the impl members that take `self`; a static member has no slot (§Traits).
- **No inserted runtime checks.** The lowerer does not synthesize bounds checks, null checks, division-by-zero guards, or overflow checks. Type narrowing already covers nullability; the remaining safety checks are the runtime's responsibility (when emitted) or are explicitly out of scope for MVP. Two exceptions are runtime checks the **backends** run. An integer `div` / `mod` by zero traps identically on both — the VM raises a labelled trap and the C backend routes the op through a `vader_{div,mod}_<width>` runtime helper that does the same (it also folds `INT_MIN / -1`). Float divide keeps IEEE `inf` / `nan`. And the lowerer marks an integer `+`, `-`, `*` or unary `-` as checked: the backends stop the run on its overflow, natively through a `vader_chk_<op>` helper, which wraps in a release build (§Integer overflow).

The Lowered AST is the input to the dead-code elimination pass. It is dumpable, printed as Vader, via `vader dump --stage=lowered-ast` for debugging and snapshot tests.

### Mid-IR (CFG)

Between the (DCE'd) Lowered AST and the bytecode emitter, a Mid-IR layer lowers every `LoweredFnDecl` to a **reducible CFG** of basic blocks with explicit terminators (`branch`, `cond_branch`, `return`, `unreachable`). Expressions become three-address `Instruction` sequences over named local slots; control flow (`LoweredIf`, `LoweredLoop`, `break`, `continue`, `return`) becomes block terminators. Strings are interned into a project-level pool reused verbatim by the emitter.

The CFG is the substrate for analyses that need def-use chains rather than tree walks:

- **Escape analysis** — stack-allocates structs whose lifetime stays within the function (no SSA).
- **Loop-carried-dependency check** — replaces the over-conservative "in loop ⇒ escapes" filter; +95 stack-promotions on the self-host.
- **Dead-store elimination** — finer-grained than the AST-level DCE pass, prunes individual writes whose result is never read.

The bytecode emitter consumes the CFG (not the Lowered AST), recovers WASM-style structured nesting via a structurer pass that places each block once by dominator tree (`docs/adr/0027`), and emits the linear stack ops. CFG dumps are exposed via `vader dump --stage=cfg`. Design: `docs/MID_IR_DESIGN.md`.

### Dead-code elimination

Between the lowerer and the bytecode emitter, a DCE pass prunes lowered declarations that are not transitively reachable from a small set of roots. This keeps unused stdlib machinery out of the final artifact: `std/core` is auto-imported in every program, but a `hello world` doesn't need `Range`, `array_iter`, `Continuation`, `IOError`, or their impls — DCE drops them before emission.

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
- ✅ write debug output to `stdout` (`println`) — a side effect that never enters
  the baked value, so it cannot affect reproducibility
- ✅ read the clock, the environment, the filesystem or a subprocess. Baking
  `now()` into a build stamp is an ordinary thing for a program to want. What it
  costs is reproducibility, and that is the program author's call to make — the
  language does not take it away.
- ❌ ask what machine the COMPILER is running on: `current_os` / `current_arch`,
  the scheduler's clock, and the dynamic FFI (`ffi_open` / `ffi_symbol` /
  `ffi_call`, which resolves a symbol out of a library chosen at build time).
  Refused with `C4016`. These are a different thing from an impure value: baking
  one makes the same SOURCE emit differently depending on who built it, which no
  author asked for and none can see.
- The compiler holds ITSELF to a stricter rule than the language, and checks it
  directly rather than by forbidding: `bootstrap/verify.sh` compares stage1 to
  stage2 byte for byte on every PR, so a non-reproducible `@comptime` inside the
  compiler's own tree fails CI. That is where this tree's guarantee lives — not
  in a restriction on everyone else's programs.

---

## 3. Lexical Structure

### Source encoding

UTF-8. A leading BOM is silently ignored and takes no column. A file holding a byte sequence that does not decode as UTF-8 is L0012, reported once, at its first malformed run, with the count; the lexer reads each run as a U+FFFD one column wide and goes on (§Strings, *Malformed UTF-8*).

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
if else match is for in return yield await defer break continue
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

- Escape set: `\n`, `\t`, `\r`, `\\`, `\'`, `\0`, `\u{HHHH}` (1–6 hex digits, a Unicode scalar value: a surrogate `D800..DFFF` or a value past `10FFFF` is L0009, in a char or a string literal).
- Exactly **one** logical codepoint per literal. `''` and `'ab'` are lexical errors.
- A char **literal** is *free*: in an integer context it coerces to that integer type, a range included, carrying its codepoint, bounds-checked at compile time (`b == '/'` with `b: u8` works, and so does `d: 48..=57: '5'` ; `b == '💩'` is rejected — U+1F4A9 is not in `u8`). With no integer context it defaults to `char`. Arithmetic on char literals computes on their code points and gives an integer: `'a' - 'A'` is `32`, and `char('\u{D7FF}' + 1)` is checked as any `char(x)`. This replaces the old `b'X'` byte literal — write `'X'`, not `b'X'`. (There is no `b'…'` form anymore.) A char **variable** keeps the concrete `char` type and never auto-coerces: convert it explicitly with `u8(c)` (which truncates codepoints above `0xFF`).

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
Wrapping     : +% -% *%  (integers only : the result wraps around the operand's width)
Bitwise      : & | ^ ~ << >>
Comparison   : == != < <= > >=
Identity     : === !==   (same object; references only — §Equality, *Identity*)
Membership   : in   (sugar for `right.contains(left)`)
              !in   (sugar for `!right.contains(left)`, parsed as `bang` + `kw_in`)
Type test    : is Type   (in `match` arms and in `if`/`else` conditions ; narrows the scrutinee)
              !is Type   (negated form, parsed as `bang` + `kw_is` ; desugars to `!(x is Type)`)
Logical      : && || !
Assignment   : =  (also compound : += -= *= /= %= +%= -%= *%=, each `lhs op= rhs` meaning `lhs = lhs op rhs`, `lhs` evaluated once)
Declaration  : x :: value           (immutable, type inferred)
               x := value           (mutable,   type inferred)
               x: T : value         (immutable, typed)
               x: T = value         (mutable,   typed)
Range        : 0..<10 (exclusive)  0..=10 (inclusive)
Cast         : Type(expr) (numeric ↔ numeric, char ↔ integer)
Field access : .name
Index access : [expr]
```

`in` and `!in` desugar to a method call on the `Contains<T>` trait (see §11), except with a type on the right: `x in Hour` tests an integer against the bounds of an integer type (§Range types, *Bounds*), `x in Weekday` against the values of an enum (§Enums, *Values*), `x in char` against the Unicode scalar values (§Casts, *`char` ↔ integer*). The element is `contains`'s `value`: `n in r` with `n: i64` on a `Range<i32>` is T3017, as `r.contains(n)` is, and so is an `i32 | null` on an `i32[]`; a free element takes the container's type (`4_000_000_000 in r` on a `Range<i64>`). A literal range or array on the right takes the element's type, a distinct's backing for a distinct element, as `<` gives a literal: `n in 5_000_000_000..=6_000_000_000` over an `i64` is a `Range<i64>`, `b in [' ', '\t']` over a `u8` a `u8[]`, `m in 0..=9` holds for a distinct over `i64`, and `b in -1..=3` over a `u8` is T3066. `s in "a"..="m"` is then a `Range<string>`, which implements no `Contains` (T3043). A union element gives the literal nothing to take, whose variant it cannot pick. Char comparisons (`<`, `<=`, `>`, `>=`) work on codepoint order (`char` is wire-compatible with `u32`); string comparisons on byte order, which in UTF-8 is codepoint order too.

A variable's type is fixed at its declaration. A reassignment (`x = v`, `arr[i] = v`, `m[k] = v`, `obj.f = v`, and every compound form) must supply a value assignable to that declared slot type — the same rule the initializer applies, `Into` coercions included — otherwise it raises **T3063**. The check targets the *declared* type, not any active flow-narrowing: inside `if x is A { … }` a write `x = b` of another union member is allowed (it retires the narrowing) as long as `b` fits `x`'s declaration.

### Operator precedence

From tightest to loosest. Higher levels bind more tightly. Non-assoc operators forbid chaining (`a == b == c` is a parse error — write `(a == b) == c`).

| Level | Operators                              | Associativity |
|-------|----------------------------------------|----------------|
| 1     | postfix `.`, `[]`, `()`                | left           |
| 2     | prefix `-`, `!`, `~`                   | right          |
| 3     | `*`, `/`, `%`, `*%`                    | left           |
| 4     | `+`, `-`, `+%`, `-%`                   | left           |
| 5     | `<<`, `>>`                             | left           |
| 6     | `&`                                    | left           |
| 7     | `^`                                    | left           |
| 8     | `\|`                                   | left           |
| 9     | `..<`, `..=`                           | non-assoc      |
| 10    | `<`, `<=`, `>`, `>=`, `==`, `!=`, `===`, `!==`, `is`, `!is`, `in`, `!in` | non-assoc      |
| 11    | `&&`                                   | left           |
| 12    | `\|\|`                                 | left           |
| 13    | `??` (null-coalescing)                 | left (non-chaining) |
| 14    | `=` (statement-level only)             | n/a            |

Type casts (`Type(expr)`) are parsed as primary call expressions and naturally sit at level 1. A `-` written against a number literal, with nothing in between, where an operand is expected, is not the level-2 prefix operator but part of the literal, so a postfix applies to the negative value: `-5.to_string()` is `"-5"` and `-5.abs()` is `5`, while `-x.abs()`, `-(5).abs()` and `- 5.abs()` negate the call (§Default integer). After an operand, `-` is the subtraction: `a -5` is `a - 5`. The `is Type` form used in `match` arms binds at the comparison level. `!is Type` is a parser-level sugar that desugars to `!(x is Type)`; the flow-narrower handles the wrapping `!` to flip then/else.

`is` checks the runtime *struct-tag* of the value. A **union on the right-hand side is a membership test**: `x is A | B` — and equally `x is MyUnion` for a `MyUnion :: A | B` alias — is true when `x`'s tag is one of that union's members, and narrows `x` to it in the then-branch. So given `U :: A | B | C` and `AB :: A | B`, a value of type `U` holding a `B` satisfies `v is AB`, and inside that branch `v` may be passed where an `AB` is expected. A test that *cannot* match — the right-hand side shares no values with the scrutinee's type, e.g. `v is D` on a `v: A | B` — is the error `T3040`, not a warning.

An `is` test binds no name: it narrows the name or field chain it tests, in place. A value with no name of its own gets one first, `r :: f()`, then the test narrows that name: `if r is T { … r … }`. `x is T as y` (and `x !is T as y`) is **P1036**.

Flow narrowing flows through a `&&` condition: in `if x is T && <rest>` the scrutinee `x` is narrowed to `T` both in the conjunction's right operand (`<rest>`) and in the then-block, so `if x is Circle && x.radius > 0 { … x.radius … }` type-checks. The else branch of a conjunction is **not** narrowed (a false `a && b` doesn't reveal which operand failed).

Narrowing flows through a `||` condition in the mirror direction. The **false** branch of a disjunction narrows every binding its operands tested — reaching it means *each* operand was false — so `if x is A || x is B { … } else { … }` sees `x` as its declared type minus `A | B` in the else, and the same complement applies to the rest of the block after a divergent guard (`if x is A || x is B { return }`). The **true** branch narrows only when *every* operand tests the same binding, and then to the **union** of what they matched: `if x is A || x is B { … }` sees `x` as `A | B`. A disjunction with one non-narrowing operand (`if x is A || flag`) narrows nothing on the true side — a true condition doesn't reveal which operand fired — while the false side still narrows `x`; likewise `if x is A || y is B` narrows neither on the true side and both on the false one.

The two operators are duals: a conjunction's **true** side applies each operand's positive narrowing and its false side applies none; a disjunction's **false** side applies each operand's negative narrowing and its true side applies one only in the single-binding case. The right operand of each sees the outcome its evaluation implies — `&&` the left's true side, `||` the left's false side — so `y == null || y.a > 0` type-checks with `y` non-null on the right.

These rules compose at any depth, through `!` as well: `!c` narrows what `c` narrows on the opposite side, and each operand of `&&` / `||` is itself a condition. So `if (y is A || y is B) && p { … }` sees `y` as `A | B`, and `if !(y is A || y is B) { … }` sees it as what neither matched.

**A predicate narrows as its condition does.** A function of the module whose body is one condition over its parameters (`= cond`, returning `bool`, not generic) is a *guard*: a call to it in a condition narrows each argument that is a binding or a field chain as `cond` narrows the matching parameter, on both sides, and composes through `!`, `&&`, `||` and a divergent guard like any test. With `is_weekend :: fn(d: Weekday) -> bool = d >= 5`, `if is_weekend(d)` sees `d` as a `5..=6` and its `else` as a `0..=4`; `is_walk :: fn(a: Activity) -> bool = a is Walk` narrows a union, and `has_name :: fn(n: string | null) -> bool = n != null` a nullable. A guard may be written after its call, called as `d.is_weekend()`, and built on another guard. It holds in its own module: another module calls it as a plain predicate. A predicate with a block body is no guard, and what a condition proves of a parameter's field (`b.label != null`) is not carried to the argument.

**A declared guard.** `@returns(cond)` on a free function returning `bool` states its contract, that it returns the value of `cond`: a call narrows its arguments as `cond` narrows the parameters, in every module, and the body is held to it, both ways, at each value it returns. Where it returns true, each parameter must lie within what `cond` proves on its true side; where it returns false, within its false side: `@returns(d in Weekend) is_weekend :: fn(d: Weekday) -> bool = d >= 4` is **T3111**, true for `d = 4`. A block body is held at each `return` and at its trailing value, with the narrowings in force there; `return true` and `return false` on their own side only, an `if` value branch by branch. The body may not write a parameter, from a lambda either (**T3113**). A generic function, a result other than `bool`, a function with no body, or a condition proving nothing of the parameters (one that only reaches its own guard included) is **T3112**; more than one condition is **P1032**; `@returns` on anything but a free function is **P1014**.

**A declared postcondition.** `@ensures(cond)` on a free function states what holds once it has returned normally: a call written as a statement, or as the value of a `let`, narrows its arguments as `cond` narrows the parameters where it is true, for the rest of the block, in every module. Only an argument that is a binding no lambda rebinds is narrowed: a field may be written through another name during the call, and a local by a lambda it runs. Nothing is checked at run time; the body is held to it instead, at each `return` and at its end, with the narrowings in force there: each parameter must lie within what `cond` proves on its true side, else **T3114**. A body that stops the program where `cond` fails (`if h !in Hour { panic(…) }`) holds it, as does one returning a call to a function ensuring it (`= require_hour(h)`); an `if` value is held branch by branch, a branch that never ends not at all. The function may return any type, but its body must have run once a call returns: a generator, a function that awaits and one with no body (`@extern`) are **T3112**. The rules of `@returns` apply: no write to a parameter (**T3113**); a generic function or a condition proving nothing of the parameters is **T3112**; more than one condition is **P1032**, and declares no contract; anything but a free function is **P1014**.

```vader
@ensures(h in Hour)
require_hour :: fn(h: i64) -> void {
    if h !in Hour {
        panic("not an hour: ${h}")
    }
}

require_hour(n)
label(n)                   // `n` is an `Hour` here
```

**A narrowing lasts while nothing can have changed what it tested.** A write to the narrowed name or field retires it unless the value still fits (§ reassignment above). Beyond that:

- A **call** may write any object it reaches, through its arguments, an alias or a closure, so it retires every narrowing of a field (`a.s`, `self.items`) and the narrowing of a local that some lambda rebinds. A write through a user `IndexSet` (`m[k] = v`) runs its `set_at` and is one; a conversion `T(x)` is not. An `await` and a `yield` let other code run before the body resumes, and count as calls. A narrowing of a local that nothing else rebinds survives them.
- A narrowing made **before a loop** does not hold inside it for what an earlier iteration may have changed: every field narrowing, and every local the body rebinds. The iterable of a `for x in e` is read once, before the first iteration, and still sees it.
- A **field write** through any path (`b.s = v`, `xs[i].s = v`) retires every narrowing that goes through a field of that name, since `b` may be `a`.
- In `a && b` (and the false side of `a || b`), a call in `b` retires what `a` narrowed, for the narrowed block as for the rest of `b`.

The usual remedy is to bind the field to a local before testing it, `s :: a.s` then `if s is Circle { reset(a); s.r }`: the local keeps the value that was tested.

### Statement separators

Inside a block, statements are separated by `NEWLINE` tokens (emitted per the rules below). Vader does **not** accept `;` as a statement separator.

A leading newline immediately after `{` is silently absorbed: a block may start on a new line without an empty statement.

### Trailing commas

Trailing commas are allowed in every comma-separated list: function arguments, function parameters, struct literal fields, struct definition fields, array literals, match arms, generic argument lists, and import destructuring lists.

### Newline-significant

A newline terminates a statement. No `;` is required. The lexer emits a `NEWLINE` token at every line break **except** in the five cases below, where the newline is silently absorbed:

1. **Inside an unclosed bracket** `(` or `[`, and inside a `${…}` interpolation: newlines there are insignificant. Newlines inside a `{ }` block stay significant, since they separate statements, and that holds for a block opened inside a bracket or an interpolation too, such as the body of a lambda passed as an argument. Only a newline *immediately after* an opening `{` is absorbed, per *Statement separators* above.
2. **After a binary or unary operator** that is still pending an operand: `+`, `-`, `*`, `/`, `%`, `<`, `<=`, `>`, `>=`, `==`, `!=`, `===`, `!==`, `&&`, `||`, `&`, `|`, `^`, `<<`, `>>`, `??`, `..<`, `..=`, and the spread `...`. (A newline after `!` is **not** absorbed.)
3. **After a comma** `,`.
4. **After a token that expects a right-hand side**: `=`, `:`, `->`, `=>`, the binding operators `::` / `:=`, and the compound-assignments `+=` `-=` `*=` `/=` `%=`.
5. **Before a leading operator that has no prefix form**: when the next line *opens* with `+`, `*`, `/`, `%`, `+%`, `-%`, `*%`, `^`, `??`, `==`, `!=`, `===`, `!==`, `<`, `<=`, `<<`, `>`, `>=`, `>>`, `&&`, `||`, `&` or `|`, the newline before it is absorbed so the operator continues the previous expression. None of these has a prefix / unary meaning, so a line starting with one is unambiguously a continuation — in a `{ }` block too, where nothing else holds the expression open: a leading `+` continues a sum or a concatenation, `??` a fallback, `&&` / `||` a condition, `&` / `|` a type intersection / union. `//` comment lines between the two are looked past. A compound assignment (`+=`, `*=`, `/=`, `%=`, `+%=`, …) is **not** a continuation. Operators that *do* have a prefix form — `-`, `~`, `!`, `.` — are excluded, so they never silently join the previous line.

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

// OK: break before a leading infix-only operator
if a == 1
    && b == 2
    && c == 3 {
    // ...
}
label :: if verbose {
    "value "
        + "${n}"
} else {
    "${n}"
}
name :: first_name(user)
    ?? return "anonymous"

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
| Text | `char` (a Unicode scalar value, held in 32 bits), `string` (UTF-8 sequence) |
| Foreign pointer | `CPointer` (§13) |
| Null | `null` |
| Metatype | `type` (comptime-only — see below) |

The eight integer types are ranges of `Int` (§Range types, *Machine integers*), declared in `std/core` (`lib/std/core/integers.vader`) and reached as any name of the prelude: `u8` is `export u8 :: Int in 0..=0xFF`, and a program built without the standard library has none of them. None has the target's width: a foreign `size_t` is a `u64` that `@c_type` spells for C (§13), and a `CPointer` is read as an `i64` or a `u64`. A numeric type has one name, which gives its kind and its width: there is no `int`, `long`, `float`, `double` or `byte`.

`type` is the **metatype**: a value of static type `type` *is* a Vader type. It is **comptime-only** — values never reach runtime, so `: type` is only meaningful in comptime contexts (currently the angle-bracketed `<T: type>` generic-param head, soon `T: type : i32` and the result type of intrinsics like `@type_of(x)`). The compiler enforces that any expression typed `type` is comptime-evaluable; emitting one in a runtime slot is an internal-bug error in the bytecode emitter.

A length, an index and a size are an `i64`, on every target: array and string `len()`, `byte_len()`, `@size_of(T)`. Array indexing accepts any integer type, a range included (`arr[2]`, `arr[i]` with `i: i32`, `arr[h]` with `h: Hour`, `arr.len() == 12` all compile with no conversion written); an index outside the array stops the run.

### Type aliases

A type alias uses the same `Foo :: <type-expr>` syntax as a regular const declaration — `type` is not a keyword in Vader. The typechecker recognises a const whose value is structurally a type expression (built from type-name references and the type operators `|` / `&` / `[]` / `fn(...) -> ...`) and promotes it to a type alias: no runtime slot is allocated and the name is usable in any type-demanding slot.

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

#### Distinct types (newtypes over a primitive, array, struct or tuple)

A `Name :: <type-expr>` whose RHS resolves to a **primitive** (`i32`, `u8`,
`f64`, `bool`, `char`, `string`, … — anything but `void` / `null`), an **array**
(`u32[]`), a **struct** (`Rgb`), or a **tuple** (`[i32, i32]`) is **not** a
transparent alias: it is a **distinct type** (a nominal newtype, à la Nim
`distinct` / Go defined-types). A `union` / `&` / `fn` RHS stays a transparent
alias as above. There is no decorator — the RHS shape *is* the trigger.

The bracketed tuple form `Name :: [T1, T2, …]` (≥ 2 all-type elements) is the
**tuple type alias** syntax : a `::` const whose value is a bracketed list of
types is promoted to a `TupleType` newtype. A bracket list with any *value*
element (`["a", "b"]`) stays an ordinary array const.

```vader
Celsius :: f64        // distinct — NOT interchangeable with f64
Handle  :: i32        // distinct
BigInt  :: u32[]      // distinct — array-backed newtype
Color   :: Rgb        // distinct — struct-backed newtype
Coord   :: [i32, i32] // distinct — tuple-backed newtype
Mixed   :: i32 | string   // transparent alias (union RHS)
```

A distinct type is **nominal** at typecheck and **zero-cost** at runtime — it
is represented exactly as its backing primitive (a register scalar, no heap
box; the same mechanism `enum` uses for its `repr`). Distinct exists only in the
typechecker; the backend never sees one (it is stripped to the backing at the
lowering boundary).

- **Conversions are explicit and symmetric**, both runtime no-ops:
  `Celsius(x)` wraps an `f64`, `f64(c)` unwraps. An *implicit* coercion either
  way is rejected (`T3001`) — that is the whole point of the newtype.
- **Composite-backed distincts forward structural ops.** The structural
  operations of the backing forward through the newtype, while trait impls stay
  **nominal** :
  - **array** (`Name :: T[]`) — index `n[i]`, the `.len()` / `.push()` / …
    builtins, `for x in n`, and `[…]` literal coercion. This lets an array
    newtype declare its own operators (`BigInt implements Mul<u32>`) without
    colliding with the array blanket impls (`T[] implements Mul<i64>` repeat).
  - **struct** (`Name :: Rgb`) — field access `c.r` and `Name { … }`
    construction forward to the backing struct's fields, while the newtype owns
    its own trait impls (`Color implements Add<Color, Color>`).
  - **tuple** (`Name :: [A, B]`) — positional access `p.0` / `p.1`, `[a, b]`
    literal construction, and `[a, b] :: p` destructure forward to the backing
    tuple.
  Nominal distinctness is a typechecker-only concept — the backend strips a
  distinct to its backing at the lowering boundary, so there is no runtime cost.
- **Arithmetic operators : concrete-first, then aliased-fallback.** A distinct's
  OWN arithmetic impl wins (`Instant implements Add<Duration>` drives `i + d`).
  With no own impl, `+` / `-` / `*` / `/` / `%` fall back to the backing type's —
  so `Meters :: i64` gets `i64`'s arithmetic for free, and an array-backed
  distinct without a `Mul` falls to the array blanket. A literal beside such a
  distinct is then a value of the backing: `m + -1` with `m: Meters` is an `i64`
  sum, and `c + -1` with `c: Code` and `Code :: u32` is **T3066**, as on a `u32`.
  A distinct that DOES
  define the operator but for a different Rhs errors on the Rhs mismatch rather
  than silently computing on the backing (so `instant + 5` is still rejected).
  This is what enables dimensional types (`Instant - Instant -> Duration`).
- **A distinct combines only with itself and its backing.** Every operator —
  `==` / `!=`, ordering, arithmetic, bitwise — refuses two distinct types that
  are not one another's backing: `Meters == Seconds`, `Meters + Seconds`,
  `Meters < Seconds` are `T3001`, although both are `i64`. A distinct over a
  distinct (`Km :: Meters`) combines with the one it wraps. Against its own
  backing a distinct compares and computes as that backing (`path == ""`,
  `d < i64(3)`), through the distinct's own impl (`Equals`, `Comparable`,
  operators) when it defines one.
- **`@comptime Name :: <type>` is the exception** — it stays a transparent
  compile-time type alias (it resolves through the comptime type-alias channel,
  e.g. `@size_of(Name)`), never a newtype.
- **Reflection follows the backing**: `@size_of`, `@align_of` and `@type_kind`
  of a distinct report its backing's size / alignment / kind (a primitive's
  scalar, or an array's `ref`).

### Default integer

A literal integer with no concrete context **infers to `i32`** (`x := 42` ⇒ `x: i32`), and must fit it wherever it sits: `big :: 9000000000`, `[9000000000]` and `9000000000 + 1` are **T3066**; write the type (`big: i64: 9000000000`) or give the literal a context (`n + 9000000000` with `n: i64`).

A `-` written against a number literal where an operand is expected makes one negative literal, integer or float: `-128` is a value, not the negation of `128`, and a postfix applies to it (`-5.to_string()` is `"-5"`). `-(128)`, `- 128` and `-x` stay negations.

When a literal **does** land in a concrete integer context, it is **bounds-checked against that type** at compile time, exactly like a char literal (§Char). An out-of-range value (`x: i32 = 9000000000`, `x: u8 = 300`, `x: i8 = 128`, `x: i8 = -129`) and a negative literal in an unsigned slot (`z: u32 = -1`) are rejected with **T3066**; there is no silent truncation or wraparound, and `x: i8 = -128` holds the least `i8`. Widen the target or the literal explicitly (`x: i64 = 9000000000`).

A literal landing in a **union** takes one of its members: the family's default (`i32` for an integer, `f64` for a float, `char` for a char literal) when the union has it, else the union's **only** member of that family — `5` passed to `u8 | string` is a `u8`, `2.5` into `f32 | string` an `f32`. With several candidates and no default among them (`5` into `u8 | i16 | string`) the literal is ambiguous and rejected with **T3089**; convert it explicitly (`u8(5)`). A literal UFCS receiver whose function takes a union first (`5.show()`) follows the same rule. The chosen member is then bounds-checked as above.

### Default float

A literal float with no concrete context **infers to `f64`** (`x := 3.14` ⇒ `x: f64`).

### Implicit numeric coercion

**An integer type goes into any integer type holding every value it has**, with no conversion written: a `u8` into a `u16`, an `i32` or a `u64`, an `i32` into an `i64`, a `u32` into an `i64` or a `u64`. It does so as an argument, a return value, a field, an initialiser or an assignment, an array or tuple element, and into a union through such a member. Nothing goes the other way implicitly: an `i32` into a `u8` is **T3001** (write `u8(x)`, §Casts).

An operation between two integer types is computed in the one holding the other: `b + i` with `b: u8` and `i: i32` is an `i32`, and so is a comparison's operand. Two of which neither holds the other (`u32` and `i32`, `u64` and `i64`) are **T3017**. Where paths join, the branches of a value `if` or `match`, an integer type goes into another of them holding it. Among overloads, the parameter holding the argument most tightly wins, the one whose values take the fewest bits to count: `min(b, b)` on a `u8` calls the `i32` overload rather than the `i64` one, and an `Hour` argument a parameter on `0..=23` rather than one on `u8`; two whose values take as many bits tie.

The widening does not reach through a container, a function type or a union: a `u8[]` is no `i32[]`, a `fn() -> u8` no `fn() -> i32`, which would call the function as it is, and a `u8 | null` no `i32 | null`, whose value keeps the tag it was built with. A bare `u8` goes into an `i32 | null` through its `i32`. A float never widens: `f32 → f64` and an integer into a float require a cast (`f64(x)`). Numeric literals stay flexible until they land in a typed context (`x: i64 = 42`), and range types widen as integer types do (§Range types).

### Float ↔ bits reinterpret

A `Type(expr)` cast **converts the value** (`u64(3.7)` truncates to `3`; `f64(5)` widens to `5.0`). To reinterpret a float as its raw **IEEE 754 bit pattern** — a different operation, same bits, no value change — use the dedicated methods (NOT the cast, which would silently change meaning):

```
x: f64 = 3.0
bits :: x.to_bits()        // u64 0x4008000000000000  — the exact IEEE bits
back :: bits.from_bits()   // f64 3.0                 — round-trips bit-for-bit
```

`f64.to_bits() -> u64` (trait `FloatBits`) and `u64.from_bits() -> f64` (trait `BitsFloat`) are `std/core` prelude methods, mirroring Rust's `f64::to_bits` / `f64::from_bits`. They lower to the `F64ToBits` / `BitsToF64` memory opcodes — an inline `union` cast in the C backend, no runtime symbol — and are the foundation for float formatting / bit-fiddling.

### Numeric-literal context-sensitivity

An integer literal stays as a *free* (untyped) numeric until its surrounding context provides a concrete width; at that point it adopts the slot's type *without* a runtime conversion. This is what makes `x: u64 = 5`, `Box { .size = 10 }`, `arr.slice(0, n - 1)`, `if count == 42`, and `g: i64 = -50` all compile without explicit casts even though `5`, `10`, `0`, `42`, `50` would otherwise default to `i32`.

The flow is bidirectional:
- **Top-down (slot expected)** — typed lets, struct-field defaults, fn-arg slots, struct-lit field values, return-type-annotated `return …`, indexed `arr[i]` (slot is the impl's `I` type), comparison/arithmetic where one side has a concrete numeric type. The literal repins to the expected width.
- **Unary `-`, `~`** — the operand inherits the operator's outer expected type, so `g: i64 = -50` lowers the inner `50` as `i64`, not `i32`.
- **Generic call sites** — after type-parameter unification, FreeInt args adopt the substituted concrete width. Works through plain calls, generic UFCS, and namespace imports.
- **Cross-branch in `if`** — when one branch of an if-expression produces a concrete numeric type and the other is a Free literal, the Free side repins to match (so `if c { 0 } else { width: u64 }` types to `u64`, not `{integer} | u64`).

When no context applies, the literal falls back to its **default** (`i32` for integers, `f64` for floats). The default is what `x := 42` records.

A type parameter is **not** a numeric context: inside a generic body, a free literal never fits a slot typed `T` (§Generics, *Type parameters are opaque in their body*).

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
- `T[] → Iterator<T>` — raw arrays auto-wrap on entry to an `Iterator<T>` slot, materialised by the blanket impl `T[] implements<T> Into<Iterator<T>>` in `std/core`, which hands back the `array_iter` generator. Driven through the `Into` probe, not a special-cased typer rule.
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

### Integer overflow

An integer `+`, `-`, `*` or unary `-` whose result leaves its type **stops the run**, under `vader run`, under `vader test` and from a debug build: `a: i32: 2147483647` then `a + 1` traps with `i32.add overflow`. Each type is checked at its own bounds, so a `u8` stops past 255 and a `u64` below 0. A **release** build (`--release`) wraps instead (two's complement, at the type's width) and pays nothing for the check. The method forms (`a.add(b)`, `Add` on a primitive) behave as the operators.

A constant the compiler folds follows the same rule: an overflow while evaluating a `@comptime` value is `C4017`. A plain constant that does not fold is computed at run time, where it traps outside a release build.

The **wrapping operators** `+%`, `-%` and `*%` (and `+%=`, `-%=`, `*%=`) wrap in every mode: integer operands only (`T3017` otherwise, and no trait overloads them), the result wrapping around the operands' width, an 8- or 16-bit one included: so `250 +% 10` is `4` on a `u8`, at run time as when a constant folds. They are the form for arithmetic meant to wrap (a hash, a PRNG, a checksum): `h *%= 16_777_619`. There is no wrapping negation: write `0 -% x`.

A negative integer literal is one value (§Default integer), so `x: i64: -9_223_372_036_854_775_808` holds the least `i64` rather than negating a magnitude past its range. Division by zero traps in every mode (§Lowered AST); a narrowing cast truncates and a shift never traps (§Casts).

### Range types

A **range type** holds the integers of an interval. It is declared over the abstract integer `Int`, or written in place where a type is expected:

```vader
Hour :: Int in 0..=23
Offset :: Int in -12..=14

Clock :: struct {
    hour: Hour
    minute: 0..<60
}
```

`Int` only names the base of a range: a value, a parameter or a field typed `Int` is **T3108**. The bounds are integer literals, the least first, within `i64` but for the greatest, which reaches up to `u64.max` exactly: `Int in 0..=18_446_744_073_709_551_615` holds the values of a `u64`, and `@max` of it is that value (`Int in 5..=1`, `Int in 0..=LIMIT`, a least bound past `i64` or another base are **T3109**). A range alone in value position (`r :: 0..=23`) stays a `Range<i32>` value. A range written over values of integer types has the element its bounds join into, as two branches do (*Narrowing*): `lo..=hi` with `lo` and `hi` of type `Hour` is a `Range<Hour>`, `h..=30` on an `Hour` a `Range<0..=30>`, and `n..=10` past `n in 0..=2` a `Range<0..=10>`. `Name :: Int in …` is a transparent refinement of the integer, shown under its name; a range alias written alone (`Heure :: Hour`) is a distinct type, as any type named alone.

**Machine integers.** `i8`, `i16`, `i32`, `i64`, `u8`, `u16`, `u32` and `u64` are the ranges of their values: `i32` is `Int in -2_147_483_648..=2_147_483_647`, `u64` is `Int in 0..=18_446_744_073_709_551_615`. A range of those bounds is that integer, named or not: `Octet :: Int in 0..=255` is a `u8`, shown under its name, and goes where a `u8` goes and back. Its arithmetic is the integer's, closed and checked (§Integer overflow) rather than computed over the integers: `o + 55` with `o: Octet` is an `Octet`, where `l + 1` with `l: Int in 0..=254` is a `1..=255`. A comparison does not narrow it (*Narrowing*), `x in Octet` narrows as `x in u8` does (*Bounds*), and `Octet(x)` converts as `u8(x)` does (§Casts), with no check that stops the program. An integer type written alone (`Meters :: i64`) is a distinct type (§Distinct types), a transparent alias under `@comptime`.

**Representation.** A value of a range is held in the narrowest of `u8`, `u16`, `u32`, `u64` that holds it when it has no negative value, of `i8`, `i16`, `i32`, `i64` otherwise: `Hour` is one byte, `Offset` an `i8`. `@size_of`, the layout of a field and an array's element all follow. A value narrowed to a range is held as one (*Bounds*): past `n in Hour`, the elements of `[n, n]` are bytes, and `first([n, n])` calls the instance every `Hour` shares.

**Widening.** A range goes into any range or integer type holding every value it has, with no conversion written: an `Hour` into a `u8`, an `i8`, an `i32` or a `0..=99`, into a union through such a member, and as an argument to a function taking an `i32`. Nothing goes in the other direction implicitly: an `i32` into an `Hour` is **T3001**. The widening does not reach through a container, a function type or a union: an `Hour[]` is no `i32[]`, a `fn() -> Hour` is a `fn() -> u8`, the integer it is held in, but no `fn() -> i32`, and an `Hour | null` is a `u8 | null` but no `i32 | null`.

**Literals.** A literal stored in a range must be one of its values (**T3066**): `h: Hour = 30` is refused, in a field, an array, a union member (`Hour | null`), a `match` pattern (`30 ->` or `20..=40 ->` on an `Hour`) and a conversion alike.

**Operations.** An operation between ranges and literals is computed over the integers, and its type is the range of every value it can take, a literal standing for its own value (a `char` literal for its code point: `b - '0'` past `b in '0'..='9'` is `0..=9`): `h + 1` on an `Hour` is `1..=24`, `h - 30` is `-30..=-7`, `-h` is `-23..=0`, `h / 2` is `0..=11`, and `(h + 1) % 24` is `0..=23`. Storing a result in a narrower range is refused (`next: Hour = h + 1` is **T3001**; write `(h + 1) % 24`), and so is `h += 1`. `/` truncates toward zero and `%` takes the dividend's sign, as at run time. A result past 64 bits is an `i64`, checked as any (§Integer overflow). A primitive operand absorbs a range that fits it: `h * x` with `x: i32` is an `i32` product, and `h < x` with `x: i64` compares. Beside a range holding it, a primitive is read as the range of its values (`b + r` with `b: u8` and `r: 0..=300` is `0..=555`), and a range that neither fits nor holds the primitive beside it is **T3017**. A comparison and an equality give a `bool`. A bitwise operation (`&`, `|`, `^`, shifts, `~`, the wrapping operators) computes at a width, which a range of no machine integer's bounds does not have: on such a range it is **T3115**, a narrowed value included; converting the operand names the width (`~i64(n)`, `u8(h) & 1`). A shift's count, whose width changes no result, may be a range (`x << k` past `k in 0..<32`).

A local takes the type of its first value, a range included, whether it is mutable or not: `next := h + 1` is a `1..=24`, and `next = next % 24` is **T3063**, `0..=23` not lying in it. A local that must hold other values writes its type (`next: i32 = h + 1`), and the detail of the T3063 says so; a local copied from a narrowed value takes its range too (*Bounds*).

**Narrowing.** A comparison narrows a range where it holds, for a binding or a field chain, as `is` narrows a union (the flow narrowing under §Operator precedence), for as long and through `!`, `&&`, `||` and a guard that leaves the block alike. After `if h < 12` on an `Hour`, `h` is a `0..=11` in the branch and a `12..=23` in the `else` and past `if h < 12 { return … }`; `if h >= 6 && h <= 9` sees a `6..=9`. The value compared with is a literal or a value of a range, read by its bounds: `h < k` with `k: 1..=5` holds `h` within `0..=4`. `==` narrows to the compared values; `!=` removes a value at an end of the range only, a range having no hole: `h != 23` makes an `Hour` a `0..=22`, `h != 12` leaves it whole. For the same reason, where ranges meet again they join into the one holding them all: a true `||` (`if h < 6 || h > 20` sees a whole `Hour`, its `else` a `6..=20`), the branches of an `if` or a `match` (`if h < 12 { h } else { h }` is an `Hour`, a free literal among them standing for its own value, through a nested `if` or `match` as well: `if c { h } else if d { 30 } else { 40 }` is a `0..=40`) and the `return`s of a function whose result is inferred. A union written in the source keeps its ranges apart. A side no value reaches is `never`. A machine integer, or an integer of a primitive type, is not narrowed by a comparison; `in` narrows it (*Bounds*). A write to a narrowed binding, a destructuring one included, is checked against its declared range, as any write (§Operators), and retires the narrowing: `x = 0` is legal where `x == 23` holds.

**Bounds.** `@min(T)` and `@max(T)` are the least and the greatest value of an integer type, a range or a primitive, as values of `T`: `@max(Hour)` is `23`, `@min(i8)` `-128`, `@max(u64)` `18446744073709551615`. A comparison with one narrows as the literal it stands for does (`if h == @max(Hour) { … }`). `x in T`, `T` an integer type, tests the integer `x` against the bounds of `T`, a constant where the type of `x` already decides it (`x` still runs); `x !in T` is its negation. It narrows `x` within `T` where it holds, an integer of a primitive type included: `if n in Hour { return n }` returns an `Hour` from an `i64`, with no conversion that could stop the program. Where it fails, a range `x` is narrowed past an end `T` covers, a primitive one is not: past most `T`, its values are two intervals. A narrowed integer is a value of the range for what follows, its arithmetic included, as a value declared of it would be: after `if n !in Hour { return }`, `n * 1000` computes `0..=23000`, the type `acc := n * 1000` takes (§*Operations*); `a := n` is an `Hour`, `i64(n)` the `i64` `n` was declared as, and `n << 8` is **T3115** where `i64(n) << 8` is not. Past `b in 0..=10` with `b: u8`, `c := b` is a `0..=10` and `u8(b)` the `u8`. A value narrowed to the bounds of a machine integer is that integer, its arithmetic closed and checked: past `n in u8`, `acc := n` is a `u8`, and `acc = acc * 2` stops the program once `acc` passes `127`, as on any `u8`. A range with integer literal bounds on the right narrows the same way (`if h in 0..<12`), its test still the `Range`'s `contains`. An enum without variant data has its values as bounds (§Enums, *Values*), and `char` the Unicode scalar values (§Casts, *`char` ↔ integer*): `@min(char)` is U+0000, `@max(char)` U+10FFFF, and `x in char` narrows nothing, its values being two intervals around the surrogates. Any other type with no integer bounds is **T3110**, for `in` and for `@min` / `@max`. The values of `T` are not counted: `@max(T) - @min(T) + 1` is the number of them.

**Conversion.** `Hour(x)` converts an integer into a range: the value is checked against the bounds its own type does not already keep, and the program **stops** outside them, in every build, a release one included. A distinct type over a range converts as the range does: `Slot(x)` with `Slot :: Hour` stops outside `0..=23` too, `Slot(f)` with `f: f64` is **T3010**, and `Hour(s)` with `s: Slot` converts back with nothing to check. A literal is checked at compile time (**T3066**), a value its type keeps within the range is converted as it is, and a source no value of which is in the range (`Below(b)` with `b: u8` and `Below :: Int in -9..=-1`), or a float, is **T3010**.

A range is its integer to every impl: `"${h}"` prints the number, and its `Display`, `Equals` or `Hash` are those of the integer it is held in. A member returning `Self` returns the integer: `h.add(k)` is a `u8`. A literal into a union of several integers and ranges (`u8 | Hour`) is ambiguous (**T3089**).

**In a generic function.** A generic function used at a range (`T` bound to `Hour`, written or handed on by an enclosing instance) has an instance of its own, apart from the one at the integer. There, what a call or an operator gives back as a `T` is checked against the range as `Hour(x)` checks it, and the program **stops** outside: `bump :: fn<T: Add>(a: T, b: T) -> T = a + b` at two `Hour` 20 and 10 stops rather than return a 30, and so do `T.zero()` at a `1..=12` and `sum` over `Hour` values past 23. A range inside an argument (`Hour[]` for `T[]` is `T` at `Hour`, but `Box<Hour>` for `T` is `Box<u8>`) is read as its integer; a member returning `Self` inside another type (`Self | null`) is not checked.

**Generic over integers.** `fn<T: Int>` takes any integer type within `i64`, a range or a primitive; `u64` and a non-integer are **T3006**. `Int` may stand beside traits (`T: Int & Display`). In the body, `T` is an integer type whose bounds only its instances know: `@min(T)` and `@max(T)` are values of `T` folded per instance, `x in T` tests an integer against them and narrows it to `T` where it holds, and `T(x)` converts an integer, the program **stopping** outside as for `Hour(x)` (a non-integer, a value of a type parameter that is no `Int` included, is **T3010**). A value of `T` is computed on as an `i64`: `a + b`, `-a` and `a < 5` take the values as `i64`, and a `T` goes where an `i64` goes (`i64`, `i64 | null`), as it is, and into no narrower slot. Getting a `T` back from a computation takes `x in T` or `T(x)`:

```
clamp_to :: fn<T: Int>(n: i64) -> T {
    if n in T {
        return n
    }
    if n < @min(T) {
        return @min(T)
    }
    return @max(T)
}

wrap_next :: fn<T: Int>(x: T) -> T =
    T((x - @min(T) + 1) % (@max(T) - @min(T) + 1) + @min(T))
```

### Strings

- Internals: an **interned atom id** — `vader_string_t` is a `u32`, 4 bytes, copied on assignment. `==` is an integer compare and hashing is the identity; the bytes live once in a global atom table (`docs/ATOM_INTERNING.md`). The `(ptr, len)` fat value this used to be went out with atom interning.
- Immutable. Concatenation allocates.
- `len()` returns the number of Unicode codepoints (an allocation-free walk, decoding malformed bytes as described below, which an ASCII string skips: see `is_ascii`). For the **byte** length, `s.byte_len()` (O(1), no view). Byte vs. codepoint is thus explicit at the call site: `len()` for codepoint arithmetic, `byte_len()` for byte arithmetic.
- `chars()` returns an iterator of `char` (`StringChars implements Iterator<char>`), for a codepoint iterator held as a value. The codepoint loop itself is `for c in s` (below), which walks the string in place.
- `bytes()` returns the UTF-8 byte sequence as a `u8[]` **view**, for ad-hoc byte processing (binary protocols carried in strings, ASCII fast paths, BOM detection). On the native target it is **zero-copy**, aliasing the string's interned bytes (it allocates only a small array header, not the byte storage). A view is frozen (§5, *Frozen values*): writing it, lending it to a function that modifies it, or keeping it in a field is rejected at compile time, which keeps it sound since the shared bytes are immutable; `.clone()` makes a copy to modify or keep. On the VM the array reads the interned bytes in place until a write copies them. `bytes()` is for handing the bytes to code that takes a `u8[]`; to read them, the string itself answers (`byte_len`, `byte_at`, `byte_slice`, below), with no view to allocate. Strings iterate by **codepoint** by default: `string implements Into<Iterator<char>>`, so `for c in s` is the codepoint loop (equivalent to `for c in s.chars()`); the byte loop is `for i in 0..<s.byte_len() { b :: s.byte_at(i) }`.
- `is_empty()` — sugar for `s.byte_len() == 0` (codepoint count and byte count agree on emptiness).
- **Subscript** `s[i]` returns the Unicode codepoint at *codepoint* index `i` (via `string implements Index<i64, char>` in `std/core`); the key is an `i64` or a free literal, as for any `Index` impl, and an index past the last codepoint stops the run. **Slicing** `s[lo..<hi]` (or `s[lo..=hi]`) returns the codepoints of the range as a string (via `string implements Index<Range<i64>, string>`): bounds past the end clamp to it, and a range that ends before it starts gives `""`. Both walk from the start: `s[i]` is O(i) and `s[lo..<hi]` O(hi). In an ASCII string, where a codepoint index is a byte offset, both find their bytes without a walk. `for c in s` walks every codepoint in O(n). For byte-cursor access, read the string in place: `s.byte_at(i) -> u8` for the raw byte, `s.byte_slice(lo, hi)` for the substring between two byte offsets, `s.codepoint_at_byte(i) -> [char, i64]` to decode the UTF-8 codepoint starting at byte offset `i` into the codepoint and the bytes it spans (lexers and regex parsers; `.0` keeps the codepoint alone). There is no `IndexSet` impl; strings are immutable.
- **Malformed UTF-8.** Nothing validates the bytes a string is made from (`bytes_to_string`, `read_file_string`, a `byte_slice` that cuts a codepoint). Every codepoint walk decodes them one way, the substitution Unicode recommends and WHATWG decoders apply: a malformed run is one `U+FFFD` spanning the longest prefix of a well-formed sequence, and at least one byte. Overlong forms, surrogates and codepoints past U+10FFFF are malformed, and no `char` holds one, so what `utf8_encode` (behind `append_char` and a `char`'s `Display`) writes decodes back. So `s.len()` is the number of codepoints `for c in s` yields and the number of valid `s[i]`, on any bytes. The compiler reads source the same way (§Source encoding).
- Literals stored in the binary's data section.

### Arrays

- `T[]` (postfix) is a dynamic array (runtime length). `i32[]`, `string[]`, `Foo<i32>[]`, ... `i32[][]` is an array of `i32` arrays.
- **Implicit reference** semantics: `arr2 := arr` copies the reference; use `arr.clone()` (UFCS from `std/iter`) for a fresh mutable copy.
- Indexing: `arr[i]`. Bounds-checked: an index outside `0..<arr.len()` stops the run. The compiler may drop a check it proves can never fail.
- **Slicing**: `arr[r]` where `r: Range<integer>` returns a **zero-copy view** sharing the parent's buffer. Both literal ranges (`arr[1..<4]`, `arr[0..=2]`) and range values bound to a local work — dispatch keys on the index *type*, not the AST shape. Any integer-bounded range is accepted; its bounds are read as `i64`, a bound below 0 counting as 0 and one past the end as the end. Pushing into the view detaches it into a fresh buffer so the parent is never mutated through the slice. For an independent copy use `arr[r].clone()`.
- Postfix `[]` binds tighter than `|`; use parens to group: `(T | U)[]` is "array of T-or-U", `T | U[]` is "T or array-of-U".

#### Variance

**Element variance**: an array is shared, not copied (`b := a` shares the buffer), so its element type is **invariant** wherever the array is bound, stored or returned: a `(i32 | string)[]` local does not accept an `i32[]`, since a write `b[0] = "x"` through the wider alias would store a string into the shared i32 buffer (T3001 on the binding, T3063 on a reassignment).

An **argument** may widen its element: `Circle[]` passes for a `(Circle | null)[]` parameter, and for a `Shape[]` one when `Circle implements Shape`, at any depth (`Circle[][]` for `(Circle | null)[][]`). The compiler deduces from the callee's body whether that is sound, with no annotation: the callee must put no wider element into the array, so it may not replace an element, grow the array, keep it past the call, return it, or hand it to a function value; through a method, a trait or a bound, every function the call may run is checked. Reading the array, removing elements, and keeping or returning an element (which escapes as what it is) are all fine. An argument the callee may break is T3102, whose detail says what the callee does:

```vader
total :: fn(shapes: Shape[]) -> f64 { … }        // reads only
add_square :: fn(shapes: Shape[]) -> void {      // grows the array
    shapes.push(Square { .side = 1.0 })
}

total(circles)        // OK — a `Circle[]` is read as a `Shape[]`
add_square(circles)   // T3102: `add_square` may grow `shapes`
```

The widened element must also read the slots the source wrote. An array of primitives stores raw values, an array of structs (or of a union of structs and `null`) raw references, and an array whose element is `string` or a union holding a non-reference stores boxes; a trait element is read through the struct's own reference. A wider element over references or boxes reads either; one over boxes reads only boxes; one over a primitive reads only its own type. A tuple is a heap object here, like a struct. So `string[]` passes for `(string | null)[]`, but `i32[]` does not pass for `(i32 | string)[]`, nor `Circle[]` for `(Circle | string)[]` (T3001).

A fresh **literal** is no widening: it is materialised directly at the target element type, so `xs: (i32 | string)[] = [1, 2, 3]` builds a union array and compiles, and so does `shapes: Shape[] = [Circle { .r = 1.0 }]`.

**In a union**: an array variant is a valid member anywhere in a type union, not only as the first: `string | u8[]` and `A | T[] | B` both parse.

#### Array constants

A module constant is frozen (§5, *Frozen values*): it has no storage a write could land in. An array constant the compiler can bake lands in the data pool, a `static const` blob in `.rodata`, shared process-wide, read through a zero-copy view. A module keeps its state in a `@singleton` function (§12).

```vader
DIGITS: string[]: ["0", "1", "2"]   // .rodata
LIMITS :: [10, 20, 30]              // same storage, inferred

@singleton
counts :: fn() -> i32[] = [0, 0, 0] // state: one instance, built on first call

bump :: fn(i: i64) -> void { counts()[i] += 1 }   // persists across calls
```

**Escape hatch**: `arr.clone()` produces a fresh array from any array. Modifying the copy never affects the original.

**Storage**: module-level array constants whose elements are all primitive (fixed-width integers, floats, char, bool) and all literal-valued land in the bytecode module's data pool: the C backend emits them as `static const` `.rodata` arrays, the VM materialises them once at module load, and `data.const` op-codes resolve to those pre-built values. References share one allocation across the whole process. Non-primitive elements (struct, string) continue to fn-wrap until the pool gains the matching representation.

**How a type is printed.** As written: `i32[]`, `Box<Cfg>`. Side-table keys (impl dispatch, monomorphisation mangles, `@type_name`) use the same rendering.

#### Repeat / preallocate — `[lhs] * n`

The repeat operator builds a fresh array by repeating an array literal's elements `n` times. The array is always on the **left**, an integer count on the right:

```vader
zeros := [0] * 3          // [0, 0, 0]
pair  := [7, 9] * 2       // [7, 9, 7, 9]   (length = len(lhs) * n)
```

Result length is `len(lhs) * n`, a count below 0 counting as 0; capacity is reserved for at least `max(len(lhs) * n, n)` elements. The empty-LHS form is the **preallocation** primitive (there is no named `with_capacity`):

```vader
buf: i32[] = [] * 1024    // length 0, capacity 1024 reserved
for x in src { buf.push(x) }   // no reallocation up to 1024 elements
```

- `[] * n` yields an **empty** array (length 0) whose reserved tail is uninitialised. Indexing is bounds-checked against **length**, so `([] * n)[0]` traps — the reserved slots become readable only as `push` / `push_all` grow the length past them. (Identical to Rust `Vec::with_capacity`.) Use `[v] * n` when you want `n` *readable* slots; `[] * n` only to preallocate before pushing.
- For a **reference** element type, the LHS is evaluated **once** and the same reference is repeated (shallow): `[obj] * 3` holds three references to the one `obj`. Sharing an *existing* binding that way is deliberate, but repeating a **freshly allocated** element — an array or struct literal, a constructor call — is almost always a mistake, since nobody else holds that object: `rows :: [[]] * 3` then `rows[0].push(x)` grows all three slots. That shape warns (`W0013`); reach for `filled` (`std/core`, the prelude — no import) when each slot needs its own:

```vader
rows: i32[][] = filled(3, () -> [])            // 3 DISTINCT arrays
seen :: filled(n, new_visited_set)             // `make` may be any `fn() -> T`
squares :: filled_indexed(n, (i) -> i32(i * i))   // per-slot index
grid :: 3.filled(() -> [])                     // UFCS on the count reads fine too
```

`filled(n, make)` calls `make` once per slot, in order, and reserves the capacity up front; `filled_indexed(n, make)` passes each slot's index to `make`. They are the constructor counterpart of `[v] * n`, which can only ever repeat one value.

- The element type is inferred from the LHS, or from the assignment slot when the LHS is empty / a free literal (`[] * n` / `[0] * n` against an annotated `T[]`).

#### Mutation methods

Beyond `push(v)`, mutable arrays expose:

| Method | Effect |
|---|---|
| `dst.push_all(src)` | Append every element of `src` (read-only) to `dst`, growing it. |
| `src.copy_to(src_start, dst, dst_start, len)` | Overlap-safe positional copy of `len` elements from `src[src_start..]` into the **existing** `dst[dst_start..]` region (`dst` must already be long enough — traps otherwise). |
| `arr.remove_last()` | Remove and return the last element as `T \| null` (`null` when empty). |
| `arr.clear()` | Drop every element (length 0; keeps capacity). |

None of them may be handed a view of a string's bytes, which nothing modifies (T3072, §5). `remove_last` returns the nullable through the usual `T | null` union, narrowed by `if x == null`.

### Tuples

Heterogeneous fixed-arity sequences. The bracketed form `[T1, T2, ...]` (≥ 2 elements; **1-tuples are forbidden**) introduces a tuple type. Tuples lower to anonymous structs at compile time — no extra runtime cost.

```vader
divmod :: fn(a: i32, b: i32) -> [i32, i32] { return [a / b, a % b] }

pair: [i32, string] = [42, "answer"]
println(pair.0)      // 42
println(pair.1)      // "answer"
```

- **Field access**: `t.0`, `t.1`, ... — numeric, in source order.
- **Elements are read-only.** `t.0 = x`, `t.0 += 1` and a destructuring target `[t.0, n] = …` are `T3101`, through a distinct over a tuple too: build a new tuple instead. A struct held in an element is still a struct, so `t.0.x = 5` writes it.
- **Disambiguation of seq literals** is contextual:
  - `[1, 2, 3]` → array (homogeneous, no annotation).
  - `[1, "x"]` → tuple (heterogeneous, no annotation).
  - With an annotation, the annotation wins: `xs: i32[] = [1, 2, 3]` is array; `p: [i32, string] = [1, "x"]` is tuple.
- **Tuples are not arrays**: `[i32, i32]` is not assignable to `i32[]` even though every element type unifies.
- **Element types are invariant.** A tuple's fields are laid out by their types and read with no test, so `[i32, i32]` does not pass as `[i32 | string, i32]` (T3001): the raw `i32` would be read as a union. A fresh literal is built straight into the slot's element types instead, so `p: [i32 | string, i32]: [1, 2]` compiles.
- **`==` compares the elements, not the references.** A tuple carries no identity to observe — its elements cannot be written (`T3101`, above) and a fresh one is built at each construction — so `a == b` is rewritten field by field. Two tuples with equal contents are equal whether or not they are the same object, and `a != b` negates the whole comparison. Each element compares as it would on its own: a nested tuple recurses, a struct goes through its `Equals` impl, a union by variant, a bounded type parameter through `Equals`. A **distinct newtype over a tuple** (`Pair :: [i32, i32]`) compares through its backing unless it implements `Equals` itself.
- **A tuple is only as comparable as its elements.** An element with no working `==` — an array, a struct without an `Equals` impl, a function value, a trait value, or a type parameter whose bound does not name `Equals` — is `T3043`, reported against the **element's** type, which is what needs the impl. The two operands must have the *same* type, not merely the same arity: `[i32, string] == [string, i32]` and a nested arity mismatch are both `T3001`.

### Destructuring

Tuples are destructured by a local declaration (`::` / `:=`). Nested patterns and `_` wildcards are supported.

```vader
[k, v] := key_value()                  // mutable bindings
[k, v] :: key_value()                  // immutable bindings
[a, _, c] := triple()                  // ignore middle slot
[[x, y], z] := nested_pair()           // nested destructure
```

A `match` arm does not destructure (`[a, b] ->` is `P1022`). It tests the tuple TYPE, like any other type, and the arm destructures what it narrowed:

```vader
match found :: lookup(key) {
    is null          -> println("no result")
    is [i32, string] -> {
        [n, s] :: found
        println("n=${n} s=${s}")
    }
}
```

#### Array sources

A `[...]` pattern also destructures an **array**. Arity is *not* checked: an array's
length is dynamic, so the compiler cannot verify it against the pattern. Surplus
elements are **silently dropped**, and missing ones **trap at runtime**
(`array.get index N out of bounds`) rather than producing a diagnostic.

```vader
parts :: "a-b-c".split("-")
[x, y] :: parts                        // x = "a", y = "b" — "c" is dropped, silently
solo  :: "a".split("-")
[p, q] :: solo                         // traps: array.get index 1 out of bounds (len=1)
```

Guard the length first, or use `...rest` below, whose result type is defined for
every length. This is the one place where a tuple pattern and an array pattern
differ in kind rather than in degree: `[a, b] := pair` is checked at compile time,
`[a, b] := arr` is not checked at all.

#### Spread destructuring (arrays only)

A destructuring declaration (`::` / `:=`) may end with `...rest` to collect the tail of an array source into a fresh array. At most one rest, last position only.

```vader
arr :: [10, 20, 30, 40, 50]
[first, ...rest] := arr                // first: i32, rest: i32[] = [20,30,40,50]
[a, b, ...tail] := arr                 // a, b consume the head; tail = [30,40,50]
[_, _, ...short] := arr                // wildcards combine with rest
```

Tuple sources keep the existing exact-arity rule (`[a, b] := pair` requires the tuple to have exactly two elements) — `...rest` is array-specific because the result type only makes sense when the tail length is dynamic. T3001 fires on a non-array source, and P1038 when `...rest` isn't the last element.

#### Destructuring via `Into<[...]>`

A `[...]` pattern applied to a value that is **neither a tuple nor an array** still destructures when the value's type implements `Into<[...]>` of matching arity. Each leaf binds to the corresponding element type of the target tuple.

```vader
[n, s] := p                            // p: a struct that `implements Into<[i32, string]>`
```

Any type that ships an `Into<[...]>` impl of matching arity destructures through a `[...]` pattern: the parser desugars `[n, s] := p` to bind each leaf from the `into` body's field reads, giving `n: i32`, `s: string`. (`MutableMap` no longer uses this path — it yields plain `[K, V]` tuples directly, like `zip` / `indexed`, so `for [k, v] in m` is an ordinary tuple destructure.)

When the impl's `into` body is a tuple literal of plain field reads (`[self.a, self.b]`), the lowerer binds each leaf directly to the source field — no `into()` call and no transient tuple allocation. T3001 still fires when the source is a non-tuple, non-array type with no matching `Into<[...]>` impl.

#### Destructuring assignment

The same `[...]` shape also works on the left of an `=`, writing to targets that
already exist rather than introducing names. Each element must be an assignment
target in its own right — a name, a field, or an index — and is held to every
rule a bare assignment faces. An element that is not an assignment target is
`T3082`; a tuple source whose arity differs from the pattern is `T3081`, and so
is a literal source of the wrong length — a literal's length is known even when
it would otherwise read as an array.

```vader
a := 1
b := 2
[a, b] = [10, 20]                      // a = 10, b = 20
[a, b] = [b, a]                        // swap — a = 20, b = 10
[cfg.width, sizes[0]] = dimensions()   // fields and indices are targets too
```

**Every element is read before any is written.** That is what makes the swap
above mean what it reads as: the source is evaluated once, each element lands in
a temporary, and only then are the targets written. A left-to-right
read-then-write would assign `a = b` and read the *new* `a` back into `b`.

`_` skips an element: it counts toward a tuple's arity, and nothing is read or
written for it. A trailing `...place` writes a **fresh array** of every element
the other targets left, exactly as a destructuring declaration's `...rest` binds
one — so it asks for an array source (`T3001` otherwise), comes last (`P1038`
otherwise), and is built in the read phase like any other element.

```vader
[_, name] = lookup(id)                 // lookup runs once, its first element is dropped
[head, ...queue] = queue               // head = queue[0], queue = a copy of the rest
[x, _, ...tail] = coords               // tail = coords[2..], empty when there is none
```

The target is otherwise a flat list of places, not a pattern: **nesting
(`[[a, b], c] = …`) is not accepted**, and a source that destructures only
through `Into<[...]>` is refused. Those belong to a destructuring declaration and
to match arms, where a pattern introduces names.

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
- `==` on two structs requires an `Equals` impl — there is no silent reference-identity default; comparing structs without one is **T3043** (`` `X` does not implement `Equals` ``). For value comparison, implement the `Equals` trait (or call a free function `equals(a, b)`); to ask whether two references are the same object, use `===` (§Identity).
- Field layout is **not guaranteed** (the compiler arranges fields freely).
- The user has no access to the layout (no `@offset_of`, no `unsafe_cast` in MVP).

Struct-literal field order does not have to match the declaration order — the compiler always emits in declaration order. Listing the same field twice raises `T3038`.

#### Field defaults

A field declaration may carry an initialiser used when the literal omits it. Defaults are checked once at the decl site against the (unsubstituted) field type. A module constant in a default is copied where a write could reach it, as anywhere it is kept (§5, *Frozen values*). They are re-lowered at every literal site that uses them.

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

Since a default is evaluated at each literal that omits its field, the struct literals it holds fill in their own omitted fields in turn. Defaults whose literals fill one another in would never stop — `A :: struct { b: B = B {} }` with `B :: struct { a: A = A {} }` — and are `T3100`. A const built from a literal reads what the defaults it fills in read, so `D :: Q {}.n` with `Q :: struct { n: i32 = D }` is `T3099`.

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

The rule holds at the condition's own level only. A bracket opened inside the condition (a call's arguments, an index, a sequence literal, an interpolation, parentheses, a block) ends what it encloses, so a struct literal there needs no parens of its own:

```vader
if is_origin(Point { .x = 0, .y = 0 }) { … }
for p in [Point { .x = 1, .y = 2 }] { … }
```

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

When every variant of a union of structs reads a field the same way, the field is accessible directly on the union value, with no outer `match`:

```vader
Cat :: struct { name: string, age: i32 }
Dog :: struct { name: string, age: i32 }
Animal :: Cat | Dog

animal_name :: fn(a: Animal) -> string {
    return a.name        // OK: both Cat and Dog have a `name: string` field first
}
```

The variants read the field the same way when they share a common initial sequence up to it: the field sits at the same position in each of them with the same type, and so does every field before it. Those types are what place the field in memory, so the access lowers to a single read at that offset, whichever variant the value holds. The names of the earlier fields may differ:

```vader
Point :: struct { id: i32, label: string }
Tag   :: struct { rank: i32, label: string }

label_of :: fn(x: Point | Tag) -> string = x.label   // OK: `i32`, then `label: string`, in both
```

Any disagreement is `T3008`, which names the first one, and the caller narrows with `if` / `match` instead:

```vader
Kitten :: struct { name: string, age: i32 }
Puppy  :: struct { name: string, age: i64 }
Narrow :: struct { tag: u8, name: string }
Wide   :: struct { tag: i64, name: string }

age_of  :: fn(a: Kitten | Puppy) = a.age     // T3008: `age` is `i32` in one, `i64` in the other
name_of :: fn(n: Narrow | Wide) = n.name     // T3008: field 0 differs, so the offset of `name` does
```

A field declared at different positions (`Cat { name, age }` against `Dog { age, name }`) is `T3008` for the same reason. The resolution applies to inline unions (`a: Cat | Dog`) and to `::` type aliases (`Animal :: Cat | Dog`).

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

#### Null-coalescing `??`

`left ?? fallback` yields `left` with `null` removed when `left` is non-null,
otherwise it evaluates `fallback`. The left operand must be a `T | null`
(a union containing `null`) — otherwise the fallback is dead code and the
compiler raises **T3068**. The result type is `left` with `null` subtracted
(`A | B | null ?? …` → `A | B`).

```vader
port :: settings["port"] ?? 8080        // value fallback → i32
name :: lookup(id)       ?? "anonymous" // value fallback → string
```

The fallback is one of:

- a **value** expression assignable to the non-null result type, or
- a **divergent** statement — `return` / `return <expr>` / `break` / `continue`
  (typed `never`, so it constrains nothing). Unlike a classic value-only
  coalescing operator, Vader's `??` accepts a divergent right operand, which
  unifies "default" and "bail out" under one form:

```vader
node  :: resolve(sym) ?? return null    // propagate absence
value :: entry[k]     ?? continue       // skip this iteration
first :: rows.next()  ?? break          // stop the loop
```

- a **block** `{ … }`, whose trailing expression / divergence supplies the value:

```vader
v :: cache[k] ?? {
    log("miss ${k}")
    continue
}
```

`??` is an expression operator (usable anywhere a value is), and the **loosest**
binary operator (level 13, below `||`), so `(a ?? b) + c` needs the parentheses —
bare `a ?? b + c` parses as `a ?? (b + c)`. It lowers to a temp-bound guard —
`{ _t :: left ; if _t is null { fallback } else { _t } }` — so the same flow
narrowing described above produces the non-null result. The `std/option`
`or_else` combinator remains for the higher-order case (a fallback passed as a
first-class function). Scope note: `??` requires `T | null` today; a `T | Error`
form (with error-value access in the fallback) is a future extension.

### Enums

```vader
Direction :: enum {
    North,
    South,
    East,
    West,
}
```

An enum defines a **closed set of named variants**. Each variant is a distinct constant of the enum's type; it may also carry a constant value of a struct the header names (§ Variant data).

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

`==` and `!=` work on enum values and compare by variant identity. Every enum also implements `Equals`, comparing the same way, with no impl: an enum fits a `T: Equals` bound and a slot typed `Equals` alike, `c.equals(d)` is `c == d`, and an impl written for one is `R2030`. It implements `Hash` the same way, so an enum keys a `MutableMap` or a `MutableSet`.

#### Values

An enum without variant data is a named set of integers, the values of its variants, and stays nominal: no arithmetic, no widening into an integer (`i32(d)` converts).

- `@min(E)` and `@max(E)` are its variants of the least and the greatest value: `@max(Weekday)` is `.Sun`.
- `x in E` tests an integer against its values (`x !in E` negated), a constant where the type of `x` decides it. Where the values follow one another, it narrows `x` to them as `x in 0..=6` would; an enum with a gap (`enum { Low = 1, Mid = 5 }`) narrows nothing, a value outside it may lie between its values.
- `E(x)` converts an integer, the program **stopping** on any other value, as `Hour(x)` does; a literal is checked where it is written, `Weekday(9)` being **T3066**. A value of another type is **T3010**.
- `for d in E` walks its variants in declaration order.

An enum of no variant has no value: `@min` and `@max` of it are **T3110**, `x in E` is `false`, `for` takes no turn, and `E(x)` is **T3010**. An enum with variant data stores its variant's rank, not its value: none of these apply to it (**T3110**, **T3007** for `E(x)`, **T3088**). The forms reach an enum through a namespace (`M.Weekday(n)`) and a renamed import alike.

#### Representation

##### Backing type

Without a written width, an enum takes the **narrowest integer its variant values fit**: unsigned when none is negative (`u8`, then `u16`, `u32`, `u64`), signed otherwise (`i8` … `i64`). `Direction :: enum { North, South, East, West }` is therefore a `u8`. An enum with variant data stores ranks instead, so its width follows the number of variants (§ Variant data). An optional `(type)` suffix pins the width instead:

```vader
Direction :: enum(i32) {
    North,
    South,
    East,
    West,
}
```

Allowed backing types: `i8`, `i16`, `i32`, `i64`, `u8`, `u16`, `u32`, `u64`. An inferred width is not an ABI promise — adding a 257th variant widens a `u8` enum to `u16` — so an enum whose layout matters outside the program (a wire protocol, a file format) pins its width.

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

#### Variant data

An enum header may name a **struct** instead of, or before, the width. Each variant then carries a constant value of that struct, written as its fields after the variant name:

```vader
StatusInfo :: struct {
    code:   i32
    reason: string
    retry:  bool = false
}

HttpStatus :: enum(StatusInfo) {
    Ok          { .code = 200, .reason = "OK" },
    NotFound    { .code = 404, .reason = "Not Found" },
    Unavailable { .code = 503, .reason = "Service Unavailable", .retry = true },
}

line :: "HTTP/1.1 ${s.code} ${s.reason}"   // s : HttpStatus
info :: StatusInfo(s)                       // a copy of the whole value
```

The header takes three forms: `enum(u8)` (a width, no data), `enum(Info)` (data, width inferred), `enum(Info, i32)` (data, the width of its values pinned). A lone argument is the width when it resolves to an integer — directly or through a distinct over one (`Byte :: u8`, `enum(Byte)`) — and the data when it is a struct; anything else is `T3084` when it sits in the data position.

- **Each block is checked as a literal of the data struct**: unknown field (`T3009`), wrong type (`T3001`), a required field left unset (`T3037`, on the variant). A variant without a block is valid when every field has a default. A block on an enum whose header names no data is `T3085`.
- **The data holds only values**: scalars, strings, enums. A field that holds a reference, an array or a struct, is `T3096`: every read of the variant would share it.
- **Every value must be a constant** the compiler can bake (`C4001`): the data lives in one read-only table, built once.
- **Values are free**, as for any enum: `Ok { … } = 200`, `NotFound { … } = 404`. A variant without `=` takes the previous value plus one, and two variants sharing a value is `T3031`. A written width bounds them: `= 404` under `enum(Info, u8)` is `T3030`.
- **Reading.** `v.field` is the field of `v`'s data; `Info(v)` is the whole value, frozen as a module constant is (§5, *Frozen values*): `Info(v).code = 5` and `v.code = 5` are `T3070`, lending it to a function that writes it `T3072`, and a name bound to it holds a copy. On the enum's name, `HttpStatus.code` is still a variant lookup (`T3027`).
- **Representation.** An enum with data stores its variant's **rank** — 0, 1, 2… in declaration order — not the written value: the data is a read-only table indexed by the rank, so a read allocates nothing, and `==`, `match` and `.Variant` compare ranks. The rank is stored at the narrowest width holding the ranks, whatever the header writes, so `@size_of` follows the number of variants, not the values: `HttpStatus` above is 1 byte.
- **Converting to an integer** (`i32(s)`) gives the written value — folded for a constant, `rank + first` when the values are consecutive, else a read of a second table of the values.
- **Interpolating** renders through `Display`, like any enum (below) — never the written value.
- **Crossing to C.** An `@extern` parameter crosses as the written value, at the width the header writes: `enum(Info, i32)` passes 404 as an `int32_t`. The declaration lowers to a Vader function that converts the rank before calling C, so a call through a fn value converts too. Without a written width it is `T3050`, as is an `@extern` that also takes a callback (C calls only a named function, and the converting function would hold the callback as a value). A `@c_struct` field copies the stored integer as it is, so such an enum cannot be one (`T3050`): C would read the rank where the source says 404.

#### `Display`

An enum implements `Display` only on request; interpolating one that does not is `T3018`. **`@displayable`** asks the compiler for it: each variant renders as its own name.

```vader
@displayable
Direction :: enum { North, South, East, West }

"${Direction.East}"   // "East"
```

The generated impl is an ordinary `Direction implements Display`, so writing one as well is `R2030`. For any other text, implement the trait yourself:

```vader
Direction implements Display -> match self {
    .North -> "N"
    .South -> "S"
    .East  -> "E"
    .West  -> "W"
}
```

- **A generic instantiated with an enum** gets an instance of its own, a generic impl included (`Box<Direction>` renders through `Direction`'s `Display`), so a dispatch on `T` reaches the enum's impl rather than its integer's. A distinct gets one when the fn interpolates `T`.
- **Interpolating a union that holds an enum is refused** (`T3086`), an array of such unions included: `"${v}"` with `v : Direction | null` — narrow first (`if v != null { "${v}" }`). A value boxed in a union carries its integer's runtime type, not the enum's, so it would render through the integer's `Display`. So does a distinct with a `Display` of its own, boxed as its backing; one without renders through its backing's anyway.

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
    _                    -> "wildcard catch-all"
}
```

- **Header binding — `match x :: e { … }`**: names the scrutinee for the whole match. `x` is visible in every arm (and in every guard), holds the value `e` evaluated to — once — and is narrowed by each arm to what that arm's pattern matched. Its scope is the match: past it, `x` is whatever it named before. It is one constant name (assigning it is **T3041**), typed as the scrutinee: `match x := e`, `match x: T: e`, `match [a, b] :: e` and `match e as x` are **P1039**.

  The binding exists for an *expression* scrutinee. A scrutinee that is already a name needs none, since each arm narrows it in place. It is the only binder a `match` has: an arm cannot bind with `as` (`is T as x ->` is `P1037`), so every arm reads the one name the header gives:

  ```vader
  match s :: shape_at(n) {        match shape {
      is Circle -> s.radius           is Circle -> shape.radius
      is Square -> s.side             is Square -> shape.side
  }                               }
  ```

- `is Type` for type narrowing. On an instance of a generic struct the test tells the instances apart when every type argument is a primitive or an enum (`is Spec<bool>` never matches a `Spec<string>`, nor `is Box<Color>` a `Box<Direction>` or a `Box<u8>`). **A type argument that erases is `T3087`** — a reference type, or a type parameter, which a reference may bind: `Box<Foo>` and `Box<Bar>` share one body (*Instance flavor* above), whose values carry the shared tag, so no test can tell them apart. Test the field that holds the type argument instead (`x.value is Foo`). A generic fn may test one of its own type parameters (`x is U`, `match x { is U -> … }`): the test reads what the call binds `U` to, through generic callers too. Inside an impl member it is `T3087`.
- **Literal-value patterns**: `42` / `'A'` / `"ok"` / `true` / `false` / `null` / `-1` directly match a scalar value. The arm matches when `scrutinee == literal` holds, with the literal typed as that right operand: a free literal takes the type of the variant it fills (`5` against `i64 | string` is an `i64`), a union compares by variant and a float by IEEE (`0.0` matches `-0.0`). The literal is typed against what the arms above leave of the scrutinee: after `is Point ->`, `"a"` against `Point | string | null` compares with `string | null`, so `Point` needs no `Equals` — placed before that arm, the same literal is T3043, as `==` on the whole union would be. A literal whose variant an arm above consumed (`"a"` after `is string ->`) can no longer match: `W0014`. A literal no value of the scrutinee can equal is T3001. A literal in a struct pattern (`is Holder { v: 5 }`) follows the same rule against its field.
- **Range patterns**: `'a'..='z' -> …` / `0..<10 -> …` match a scalar scrutinee (char / integer) that falls in the range. `..=` includes the upper bound, `..<` excludes it (matching the range-expression operators). The bounds are scalar literals of the scrutinee's type, a free literal taking it: `5_000_000_000..=6_000_000_000` over an `i64` is two `i64`, and `-1..=3` over a `u8` is T3066. Over a distinct they take its backing, as `<` does. Over a union they take its integer or `char` variant, and the arm tests that variant first: after `is null ->`, `0..=9` matches an `i32 | null` holding 0 to 9; once the arms above took that variant, the range is W0014, as a literal is. A scrutinee with no integer or `char` to order is T3001. The lowerer emits `scrutinee >= lower && scrutinee <(=) upper`. Range patterns bind nothing; over an integer type they and literal patterns cover its values (next item).
- **Exhaustive over an integer type**: a `match` over a range, an integer primitive or `char` (a distinct over one included) needs no `_` once its unguarded literal and range arms cover every value: `match h { 0..=11 -> …; 12..=23 -> … }` on an `Hour`, `0..<128` and `128..=255` on a `u8`, every Unicode scalar value on a `char` (the surrogates are none). A value no arm takes is `T3013`, which names the first one missing (`value `12` of Hour is not covered`). `u64` reaches past `i64`, which no literal does: it keeps needing `_`. An arm whose values earlier arms all took, and a `_` after arms covering the type, are `W0014`.
- **A literal or range arm narrows** an integer scrutinee (a name, a field chain or the header binding) to its values in the arm, as `if h in 1..=11` would: past `1..=11 ->` an `Hour` is a `1..=11`, and an `i64` matched against `0..=11` is a `0..=11` there. An or-pattern narrows to the range holding its alternatives, and the wildcard to the values left when they are one interval (`_` after `0..=11` on an `Hour` sees `12..=23`). A `char` and a distinct are not narrowed to a range.
- **Or-patterns**: pipe-separated alternatives in one arm — `.North | .South -> …` (enum variants), `1 | 2 | 3 -> …` (literals). The arm matches when *any* alternative does (lowered to `p1 || p2 || …`); each alternative is checked against the scrutinee, and every enum variant listed counts toward exhaustiveness. Alternatives are value-level and bind nothing: a struct pattern in one may constrain a field (`is A { x: 1 } | is B { x: 2 }`) but not bind it (`P1037`), since the arm could not say which alternative bound it. **Type tests don't need an or-pattern**: `is A | B -> …` is already a single `is` over the union type `A | B` (no parentheses required) — it narrows to `A | B` and covers both for exhaustiveness.
- **Struct patterns**: `is Point { x, y }` binds fields by name, `is Point { x: 0, y }` also constrains one to a literal. Each name must be a field of the struct (`T3009`), a literal takes that field's type (`T3001`), and braces after a type that is not a struct are `T3001`. The field tests run after the type test, on the narrowed value — on a union, a field is only read once the variant carrying it is confirmed. **A constrained arm contributes nothing to exhaustiveness**, exactly as a guarded one: `is Point { x: 0 }` matches only some points, so an unconstrained arm (or `_`) must still cover `Point`.
- **A pattern binds no name.** A bare identifier arm (`name -> …`) and a struct-pattern binding inside an or-pattern alternative are `P1037`, a tuple destructure (`[a, b] -> …`) is `P1022`: the catch-all is `_`, the name comes from the header (`match pet :: v { is null -> {}; _ -> use(pet) }` narrows `pet` to "scrutinee − null"), and a tuple is tested with `is [T, U]` and destructured by a local declaration in the arm (`[a, b] :: x`). Struct patterns still bind their fields (`is Point { x, y }`).
- Guards via `if cond`. The guard may read the pattern's bindings and the header's (`match n :: f() { is i32 if n > 0 -> … }`). **A guarded arm contributes nothing to exhaustiveness** — it only matches when its guard holds, so the variant it tests stays uncovered until an unguarded arm (or wildcard) handles it; with `x: i32 | string`, `match x { is i32 if x > 0 -> …, is string -> … }` is rejected with `T3013`. Bare lambda sugar (`x -> …`, `(x) -> …`) is not parsed at the guard's own level, where the arrow belongs to the arm; inside a bracket it is (`_ if xs.any_match(x -> x > 0) -> …`), and a parenthesised lambda (`(x -> …)`) works anywhere. A guard has no body brace, so a struct literal parses there.
- **Flow narrowing through the wildcard arm**: after one or more `is X` arms (without a literal field constraint), the subsequent `_` arm sees the scrutinee — and the header name — narrowed to `union − matched`. With `p: Pet | null`, `match p { is null -> "no"; _ -> p.name }` reads the common field without a wrapping cast.
- **`is T` reachability** (`T3040`): an `is T` arm whose `T` can never be a value of the scrutinee's static type is rejected at compile time. With `p: Pet`, `match p { is Bird -> … }` errors when `Bird` is not part of `Pet`'s union; same rule fires for `if x is T` expressions outside `match`. The check uses the symmetric `intersects(T, scrutinee)` predicate; unknowns (`Unresolved`, `TypeParam`) suppress cascading. **`==` / `!=` get the same check** — `if n: i32 == null` triggers T3040 with the same wording, replacing the misleading "no Eq impl" T3017. Use `is null` when you want the flow-narrowing; both forms work but `is` is the canonical idiom.
- **Exhaustiveness checked** by the compiler. For union scrutinees, every variant must be covered (or matched by a wildcard `_`). An integer type is covered by its values, a union's one integer variant included (`Hour | null` by `0..=23` and `null`). Any other scrutinee (`string`, `f64`) needs a wildcard.
- **Unreachable match arm (`W0014`)**: an arm no value can reach, because the arms before it already cover it — a wildcard came first, the earlier arms consumed the whole scrutinee, an enum variant is named twice, an `is T` restates a test an earlier arm made, or the literal and range arms above already took the values of an integer one. Distinct from both neighbours: `T3013` asks whether a variant is *missing*, and `T3040` compares an `is` against the scrutinee's *static* type, so neither sees a variant covered twice. Fires on `@partial` matches too — an arm that cannot be taken is a mistake whatever the match opted out of.

- **Wildcard on a closed union, value position (`W0005`)**: a `match` that *produces a value* over a union / enum scrutinee whose catch-all is a bare `_` earns a warning — the wildcard silences the exhaustiveness check, so a variant added later degrades silently into the catch-all instead of erroring. Enumerate every variant, or opt out explicitly with `@partial` (§ decorators) when "everything else does X" is intended. Statement matches (`_ -> {}`, no value) and non-union scrutinees (`i32` / `string` / …) are exempt. The warning does not fire on `@partial` matches.

### Variable bindings

Local bindings come in four shapes that share a single `LetStmt` AST node; the syntax is symmetric on the mutability axis (`::` ↔ `:`, `:=` ↔ `=`).

| Form                  | Mutability | Type        | Example                       |
|-----------------------|------------|-------------|-------------------------------|
| `name :: value`       | immutable  | inferred    | `pi :: 3.14`                  |
| `name := value`       | mutable    | inferred    | `total := 0`                  |
| `name: T: value`     | immutable  | typed       | `cap: i64: 1024`             |
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

- **Mutable local never reassigned (`W0015`)**: a `:=` / `name: T =` local that no assignment ever rebinds earns a warning — the mutable form advertises a rebinding that does not happen. The fix is the immutable form on the same row of the table above (`n := 0` → `n :: 0`, `n: i32 = 0` → `n: i32: 0`). What counts as a rebinding is a **bare name as the whole assignment target**, compound assignments included: `x.f = 1` and `x[0] = 1` mutate what the name designates, which the immutable form already permits, so they do not justify a `:=`. A destructuring declaration carries one `:=` for every name it binds, so rebinding any one of them justifies it.

- **A write into a copy nothing reads (`W0019`)**: a name bound to a module constant, or to the data of a variant, holds a copy of it (§5, *Frozen values*). Written, and never read nor kept anywhere in the body, the copy takes the write and nothing sees it: `for c in TABLE { c.n = 0 }` changes no element of `TABLE`. A write below the name (`c.n = 0`, `c.n += 1`) is no read of it. A name that may hold another value than copies of frozen ones (a parameter, a branch that may be a fresh value, a rebinding to one) is not warned about: the write may land there. The warning sits on the write.
- **Needless enum type prefix (`W0016`)**: writing `Enum.Variant` where the slot already pins that enum earns a warning — the name before the dot repeats what the context says, and the bare `.Variant` reads the same. The slots that pin are the ones the shorthand already resolves against: a typed return, a parameter, an annotated local or field, a match arm's BODY, an element of an array literal in a typed slot, and the other operand of an `==` / `!=`. A nullable slot (`Color | null`) pins just as well. A match PATTERN never triggers it — the qualified form does not parse there, the bare `.Variant` being the only spelling a pattern accepts. It stays silent wherever the prefix is load-bearing: an unannotated local (`c :: Color.Red` has nothing to infer from); a slot whose union carries two enums sharing the variant name, where the bare form resolves to the first that carries it; and **any argument of an overloaded call**, where the prefix is what selects the candidate — given `pick(c: Color)` and `pick(f: Fruit)`, `pick(Fruit.Red)` and `pick(.Red)` reach different functions, so advising the bare form there would change the call in silence. The qualified form remains legal everywhere; the warning only says it earns nothing here.

### Type inference

**Bidirectional** inference:

- Local: `x := 12` infers `x: i32`.
- Top-down: function signatures used to infer lambda arguments.
- No global Hindley-Milner (by simplicity choice).
- **Function signatures must be fully annotated** (no top-level inference).
- A generic call binds its type arguments from the arguments first, then from the **result slot** — `rows: i32[] = empty_of()` binds `T = i32` for `empty_of :: fn<T>() -> T[]`, which no argument could reach. Each call instantiates the callee's type parameters afresh: inside a generic body, the body's own `T` met in an argument or in the result slot is fixed, and binds the callee's parameter to `T` itself (`rows: T[] = empty_of()`). An explicit `<…>` fixes the callee's parameters in the order it declares them, wherever it is declared (`println<i64>(9000000000)`). A type parameter nothing binds is `T3069` at the call site, not an erased value that fails downstream, including one only the callee's body names (`tag :: fn<T>() -> string`); the check stays silent only on an arity mismatch, which T3003 / T3005 already name.
- A generic function **named as a value** is instantiated against the function type of the slot it fills: `apply(name_of, 5)` with `apply :: fn(f: fn(i32) -> string, x: i32)` takes `name_of` at `T = i32`, and so do `xs.map(name_of)` and `h: fn(i32) -> string: name_of`. Written type arguments fix it outright (`apply(name_of<i32>, 5)`, `f :: id<i32>`); writing fewer fixes the first and the slot binds the rest. A local `::` binding with no annotation **aliases** the function (`g :: id`): each use of `g` names `id`, instantiated where it is used, so `g(3)` and `g("s")` are two instances. A module constant is no alias: it takes an annotation (`h: fn(i32) -> i32: id`). A generic function used as a value with neither a function-typed slot nor its type arguments is `T3069` (`m := id`, `keep(id)` for `keep :: fn<T>(x: T) -> T`).
- A **member with type parameters of its own** (`conv :: fn<U>(self, x: U) -> string` in a trait or an impl) runs as one instance per call, at the types the call gives them, like a generic function: on a concrete receiver (`b.conv(5)`, `b.conv<i64>(5)`), as a static member (`Box.make(true)`), through a bound in a generic body, and on a generic impl, whose own parameters the receiver binds. A vtable holds one body per member, so such a member is not called on a trait value, nor through a bound of a generic impl's parameter in that impl's members, which its instances share: `T3107`. Called through a bound elsewhere, it keeps the caller's instances concrete. In the same way, an impl member that tests one of its own type parameters (`x is U`) is fine, while one that hands its impl's parameters to a function testing them is `T3087`.
- Against a **union** parameter, the variants the argument shares with the pattern pair off first, so `T | null` never binds `T = null`; a pattern variant the argument lacks binds nothing (`T | null` given a narrowed `i32` binds `T = i32`). A type parameter left **alone** then stands for every variant left: `T | null` against `i32 | string | null` binds `T = i32 | string`, which is what lets `filter_not_null` keep both payload kinds. Several leftovers on both sides pair by position.

### Casts

"Constructor-call" syntax:

```vader
x: i32 = 42
y: i64 = x                 // widening, no cast needed
z: u8  = u8(x)             // narrowing cast, keeps the low bits (300 -> 44)
```

**`char` ↔ integer**: a `char` is a Unicode scalar value, every code point from U+0000 to U+10FFFF but the surrogates `D800..DFFF`, held as a `u32`. An integer cast reads its code point (`u32(c)`). `char(x)` converts an integer, **checked** in every build: the program stops on a surrogate, a negative value or one past U+10FFFF. A literal off them is **T3066** (`char(0xD800)`), a type none of whose values is one **T3010**, and a value whose type decides it is not tested (`char(b)` and `char(u32(b))` with `b: u8`). A distinct over an integer converts as its backing, and a distinct over `char` (`Glyph :: char`) is checked as `char` (`Glyph(n)`). A float or an enum is **T3010**: go through an integer first; a type implementing `Into<char>` converts through it. A UTF-16 surrogate is a code unit, an integer (`is_surrogate(unit: u32)` in `std/string`).

```vader
c    :: 'A'
n    :: u32(c)            // 65
back :: char(n + 1)       // 'B', checked
```

For risky conversions (parsing), use explicit functions returning unions:

```vader
n: i32 | ParseError = parse_int("42")
```

### Generics

Type parameters are introduced with the angle-bracket `<T>` form at the declaration site (Java/C# style). They compile to a `TypeParam[]` slot on the underlying `FnDecl` / `StructDecl`; later references in the same scope are plain `IdentExpr` nodes that the resolver rebinds to the type-param symbol. Angle brackets are the only accepted form — there is no bracket `[T]` or paren `(T)` type-parameter syntax.

A type parameter may declare a **default** with `<T = Default>` (after the optional `: bound`, e.g. `<Rhs: Numeric = Self>`). When a generic is used with fewer arguments than it declares, the trailing parameters fill from their defaults; a `Self` default resolves to the implementing / receiver type. Defaults are currently honored on the **impl→trait-arg path** — `i32 implements Add` and a `where T: Add` bound both resolve `Add<Rhs = Self, Out = Self>` to `Add<Self, Self>` — which is what lets the arithmetic operator traits be generic without forcing every existing impl/bound to spell the params. Defaults on struct / fn / type-alias parameters parse but are not yet filled at their use sites (those instantiations error rather than default).

**Disambiguation rule (expression position).** Because `<` and `>` are also comparison operators, the parser uses a hard-precedence rule: after a name (`f`, or the member of `x.f`, `M.f`), a `<` opens a generic argument list **iff** the matching `>` is immediately followed by `(` (call), `{` (struct literal) or `.name` (a member of the instance, `Bag<f64>.make(1)`). Any other follower leaves the `<` to Pratt as comparison. This is unambiguous in practice: `assert(v < 20, "msg")` reads as comparison because the `>` candidate is followed by `)`.

**Explicit type arguments.** A call writes its callee's type arguments after the callee's name, whatever its form: `f<i64>(x)`, `x.f<i64>(y)` (UFCS), `M.f<i64>(y)` (aliased module); a static member takes the arguments of the type it is called on, written on the type: `Bag<f64>.make(1)`. They fix the callee's parameters in the order it declares them; a call may write **fewer** (`pair<i64>(5, "x")` fixes `A = i64` and infers `B`), but not more (`T3105`, as is any on a function that takes none). On a static member they fix the member's own parameters, the type's coming from the type: `Bag<f64>.make<i64>(1)`, or `Bag.make<i64>(1)` with `Bag`'s inferred. A generic type written with its arguments writes them all, where nothing could infer the rest: a struct literal (`Pair<i32> { … }` for `Pair :: struct<A, B>` is `T3105`), a static member's owner (`Pair<f64>.make(1)`), a conversion's target (`Box<i64>(x)`).

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

A bound names traits, joined by `&` (`K: A & B`: K satisfies both). A union is not a bound: `K: A | B` grants nothing a body could use, so it is **R2042**, as it is in a trait's `requires`; an optional value carries `null` where the parameter is used, not on its bound: `fn<T: Bump>(x: T | null)`, never `fn<T: Bump | null>(x: T)`. A future predicate-bound escape hatch (`<T: @size_of <= 64>`-style) is reserved for non-trait constraints once they land.

**Compile-time values** (post-MVP candidate; the fixed-size array surface itself is not designed yet — the example below uses placeholder syntax):

```vader
make_buffer :: fn<N: i32>() -> FixedArray<u8, N> { ... }
```

**Implementation**: monomorphization at compile time, driven by the comptime engine. Single specialization machinery.

**Bound enforcement and trait-method dispatch on type parameters**: both wired since Layer 7e. The typechecker:
- Resolves `key.hash()` inside a generic body where `key: K` and `K: Hash` to the trait method statically, then mono-substitutes it to the concrete type's impl member. An operator on such a parameter goes the same way (`a + b` with `T: Add`, `a < b` with `T: Comparable`, `a == b` with `T: Equals`, `x in c` with `C: Contains<E>` — see *Operator overloading*).
- At every call site of a generic fn, checks each type argument the call binds against every trait of its parameter's bound (`<T: Trait>`, each of `<T: A & B>`), arguments included: `C: Contains<i32>` is not met by a `string[]`, whose impl is `Contains<string>`. A type lacking a matching impl yields T3006 ("trait not satisfied"). The check is the same wherever the callee is declared (in the module, imported, behind a namespace alias) and however it is called — directly, or through UFCS, where the receiver alone may bind the parameter (`m.println()`). A type argument that is itself a type parameter meets a bound its own bound names.

**Type parameters are opaque in their body.** A generic body must hold for every instance, so it knows nothing of `T` beyond its bound: only a `T` fits a slot typed `T`, and a `T` fits only a slot that names it (`T`, or a union such as `T | null`). Each of these is rejected (T3001; T3020 on a `return`; T3017 on an operator's operand), because a `T = string` instance would receive an integer or hand one out:

```vader
widen :: fn<T>(x: T) -> i64 {
    n: i64: x            // a T is no i64
    return n
}

narrow :: fn<T>(x: T) -> T {
    y: i64: 5
    return y             // nor is an i64 a T
}

zero :: fn<T: Add>(x: T) -> T {
    s: T: 0              // nor is a free literal
    return s.add(x)
}
```

The same holds for `pick(x, 0)` where `pick` takes two `T`, for `f(2.5)` through a parameter `f: fn(T) -> T`, for `x > 0` with `T: Comparable`, and for `x == 0` with `T: Equals`. Inside a generic fn or impl, its own type parameters are fixed: a call in the body binds none of them, and its arguments check against them as written. So `keep("s")` on a local `keep :: (y: T) -> …` is T3001, and so is `t.visit((y: Inner) -> …)` with `T: Visit`. A callee's own type parameters are still bound at each call (`g :: identity`), and a receiver or a type name still binds an impl's at the instance it names (`other.put(4)` on a `Box<i32>`, `Bag.make(5)`, inside that type's impl).

**A generic recursion may not grow its type argument.** Monomorphization builds one instance per set of type arguments, so a call that passes a type parameter on inside a larger type, on a cycle of calls that leads back to it, would ask for a larger instance at each step: `wrap<T>` calling `wrap([x, x], n - 1)` is `T3104`, and so is `ping<A>` calling `pong([a], n)` when `pong` calls `ping` back. A recursion that passes its parameters on unchanged (`count_down(x, n - 1)`), or calls itself on a fixed type (`fixed(n, n - 1)` inside `fixed<T>`), is not. The check follows the calls of generic functions and the members of an array impl, which run one instance per element type: `[self].depth(n - 1)` inside `T[]`'s impl is `T3104` too. A member of a generic struct's impl runs once for each instance the program writes and once for all the others, so a `Box<T[]>` built and called inside `Box<T>`'s impl asks for no new instance and is accepted.

Matching an argument against a signature that nothing has instantiated yet is a different question, where a type parameter is still free: choosing an overload, choosing the UFCS function for a receiver (`Iterator<i32>` fits `self: Iterator<T>`), and checking the fields of a generic struct literal written without type arguments (`Box { .value = [4, 5] }`). A free literal still needs a type to land on, and such a literal binds none: `Box { .value = 0 }` is T3001 — write `Box<i32> { .value = 0 }`.

**Limitations (MVP)**:
- **No inherent "associated functions"** — a static function belongs to a trait (*Static members* under §Traits), never to a type on its own. Factory functions outside a trait are written as free functions and called via UFCS or directly: `new_path("foo/bar")`, `MutableMap<K, V> { ... }` for struct-literal construction. Post-MVP candidate.

Numeric primitives carry `@intrinsic` `Add`/`Sub`/`Mul`/`Div` impls in `std/core` — `<T: Add>` succeeds for every primitive numeric type as well as for `string` (concat). `Equals` and `Hash` are carried by **every** primitive (`@intrinsic <prim> implements Equals` + `<prim> implements Hash` in `std/core`, covering `i8`…`u64`, `f32`/`f64`, `bool`, `char`, `string`), so `x.hash()` / `x.equals(y)` and `MutableMap` / `MutableSet` keying work for any primitive without a per-type opt-in.

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
- Implementation: `T implements Trait { ... }` (three forms — see below). `T` and `Trait` name declarations, resolved like any other name — a trait imported from another module included. The impl belongs to those declarations, not to their names: when two modules each declare a `Foo`, or an `Animal` trait, an impl of one says nothing about the other.
- An impl defines its trait's members and nothing else (`T3094`; see *No inherent "associated functions"*), each with its trait method's signature: the same parameters and return type, `Self` read as the impl's type and the trait's parameters as the impl's arguments (`T3095`). The default of an argument the impl leaves out (`Out = Self`) is the impl's type.
- A union satisfies a trait iff all its members satisfy it.
- **A union calls the members of a trait all its variants implement** — `u.area()` on `u: Sq | Circle`, `k in u`, `u + 5`, `u[k]` and `u[k] = v` — through that trait, by the value's tag, as a value of the trait does. The variants must agree on the trait's arguments, each argument being one type for all of them or each variant itself (`Out = Self`, which the union reads as itself: `a + 5` on `a: i32 | Money` is an `i32 | Money`). A member two traits offer every variant is `T3032`. A dispatch by the tag alone refuses a variant implementing the trait more than once (`T3097`); a variant boxed as its representation — an enum, or a distinct implementing the trait itself, or an array of either (`T3086`); a member taking another `Self` (`compare`, `Add<Self>`), which the other operand may fill with another variant — `Equals` excepted, its slot checks the other operand's type — and a member returning `Self` inside another type (`Self[]`) unless every variant is a struct (`T3098`). Narrow first. A generic member, an `@intrinsic` array member (`push`) and a member taken as a value (`f :: u.area`) are not dispatched.
- Operator overloading via stdlib traits — see *Operator overloading* below.
- **`self` and `Self`**: inside a trait or impl, the first parameter conventionally named `self` carries an implicit `Self` type — no annotation required. `Self` refers to the type that implements the trait; in a `Foo implements Trait { … }` block, `Self = Foo`, a written `-> Self` included. Outside trait/impl context, `Self` is undefined (`T3023`).

#### Static members

A trait member whose first parameter is not named `self` is **static** — the name decides, not the type, so `combine :: fn(a: Self, b: Self) -> Self` is static too. It is called on a **type**, never on a value. The type is a concrete one, a type parameter whose bound names the trait, or a member reached through a namespace alias (`M.Point.origin()`):

```vader
Zero :: trait {
    zero :: fn() -> Self
}

i64 implements Zero -> 0

sum :: fn<T: Add & Zero>(xs: T[]) -> T {
    s := T.zero()
    for x in xs {
        s += x
    }
    return s
}

start :: i64.zero()
```

- `Type.member(args)` resolves `member` in `Type`'s impls, or through the bound for a type parameter. A static member may take parameters (`unit :: fn(scale: i32) -> Self`).
- A static member called on a value is **T3091**, and so is one called on the trait itself (`Zero.zero()`: the trait has no impl to pick). An instance member (one taking `self`) called on a type is **T3092**. A static member named without being called (`f :: i64.zero`) is **T3093**: it has no value form.
- Dispatch is static: the call goes straight to the owner's impl member. A generic function calling one on its type parameter is instantiated per concrete type. A static member has no vtable slot, so a trait mixing static and `self` members still dispatches the latter on a trait-typed value; the static ones are reached through a type only.
- `std/core` declares `Zero` and `One` (`zero` / `one :: fn() -> Self`, the additive and multiplicative identities), implemented by every numeric primitive — `Zero` by `BigInt` too. `std/iter`'s `sum` is `fn<T: Add & Zero>(self: Iterator<T>) -> T`, and `product` is `fn<T: Mul & One>(self: Iterator<T>) -> T`.

#### Coherence — one impl per (type, trait, arguments)

A program may declare **at most one** `impl` of a given trait instance for a
given concrete receiver type. A second impl of the same `(type, trait, trait-args)`
triple raises **R2030** ("conflicting trait impl for the same type"); impls of one
trait at other arguments are *Several impls of one trait*, below. This
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

Two **generic** impls of one trait on one base (`Wrapper<T>`, `T[]`) may not
both cover an instance: `Wrapper<T> implements<T: A> Poke` beside
`Wrapper<T> implements<T: B> Poke` is **R2030**, whatever the bounds say — a
type implementing both `A` and `B` can always be declared. A bare type-parameter
receiver (`T implements<T: A> …`) is not checked yet.

#### Specialization — the instance wins

An impl on **one instance** of a generic base — `Wrapper<MonType> implements
Poke`, `MonType[] implements Poke` — is not a second generic impl: it covers that
instance alone, and wins over the base's generic impl for it, whatever the order
of declaration.

```vader
Wrapper<T> implements<T> Poke {
    poke :: fn(self) -> string = "generic"
}

Wrapper<MonType> implements Poke {      // wins for `Wrapper<MonType>` alone
    poke :: fn(self) -> string = "mon"
}
```

- Every route to the impl agrees: a method call, a bounded type parameter, a
  trait-typed value, and an instance built inside a generic body
  (`fn<T>(x: T) -> Wrapper<T>` called with a `MonType`).
- The base's other traits still reach the instance through their generic impls.
- The rule is per trait instance: an impl on one instance replaces the generic
  impls of that trait at arguments that can coincide with its own, and leaves the
  others — `MonType[] implements Into<Label>` leaves
  `T[] implements<T> Into<Iterator<T>>` to an array of `MonType`.
- A type an instance impl is built from (`MonType` above) keeps its generic
  instances apart at run time, as a primitive argument does: a generic function
  or struct instantiated with it gets its own body instead of the erased one
  the reference arguments share.

An array type takes impls on `T[]` (`T[] implements<T> …`) and on a **concrete
array** (`i32[] implements Tag`, `MonType[] implements Tag`), which wins for its
element type. A partly generic array — `T[][]`, `[T, i32][]` — would be a second
generic impl on arrays and is **T3090**. For the orphan rule (R2018), an array
belongs to its element's owner: `MonType[]` to `MonType`'s module, `i32[]` to
`std/core`, as `i32` does.

#### Several impls of one trait

A receiver may implement one trait several times at different arguments —
`Vec2 implements Mul<f64>` beside `Mul<Vec2>`, `Mon implements Into<Label>` beside
`Into<Tag>`. Each use site runs the impl its own types pick:

- an operator, by its right operand (`v * 2.0`, `v * v`);
- a method call, by its first argument (`v.mul(2.0)`), or, for a member without
  one, by the type its result must have (`t: Tag: m.into()`);
- `x in c`, by the element; `c[k]` and `c[k] = v`, by the key;
- `[a, b] :: r`, by the arity of the tuple an `Into<[…]>` builds;
- a static member, by its argument (`Vec2.make(1.5)`);
- a call, a static member or an operator on a bounded `T`, by the bound's
  arguments (`fn<T: Mul<f64>>(v: T) -> T = v * 2.0`, `T.make("s")` under
  `T: Make<string>`), in a generic fn and in a generic impl's members alike;
- inside one of the impls, a member of the trait reached on its own type is its
  own: a default method's `self.tag()` runs the `tag` of the impl it belongs to.

Two impls that fit a use site equally, a member without an argument whose result
the site leaves untyped (`println("${m.into()}")`), and the member taken as a value
(`f :: m.into`) are **T3032**. A use that reaches the trait without naming its
arguments cannot pick: a `for` over a type implementing `Iterator` twice, or
converting into two `Iterator`s (`Into<Iterator<i32>>` beside
`Into<Iterator<string>>`) without being one itself, and a trait value of a trait
its type implements twice (`v: Into<Tag>: m`), are **T3097** — a trait value
dispatches by the trait alone. A type that is an `Iterator` and also converts into
one is walked through its own `next`.

#### Bounded-generic impls

When the impl introduces its own type parameters (with optional bounds), the `<T>` list follows the `implements` keyword — same position as it does after `fn` / `struct` / `trait`. This is the canonical place for any typeParam that's local to the impl (not borrowed from the for-type's struct head).

```vader
// Borrowing T from the struct head — no impl-level typeParams.
Countdown<T> implements Iterator<T> {
    next :: fn(self) -> [T, Continuation] { /* … */ }
}

// Bounded blanket impl — Range<T> coerces into an Iterator when T
// satisfies both Comparable and Step.
Range<T> implements<T: Comparable & Step> Iterator<T> {
    next :: fn(self) -> [T, Continuation] { /* … */ }
}

// Blanket on a structural source (any array, any Display-bound type).
T[] implements<T>          Into<Iterator<T>> { /* … */ }
T   implements<T: Display> Into<string>      { /* … */ }
```

The angle-bracket list after `implements` introduces the typeParams *for the entire impl block* — the for-type, the trait args, and every method body resolve against them. Multi-bound (`<T: A & B>`) is identical to the bound grammar on fn / struct heads.

Compared to the borrowing form (`Foo<T> implements Trait<T>` without an impl-level `<T>`, where `T` aliases the struct's own type-param), the bounded form lets the impl declare *its own* `T` whose bounds are scoped to this block — the struct itself stays unbounded.

**A bounded impl holds only for the arguments its bounds admit.** With `Box<T> implements<T: Display> Display`, `Box<i32>` implements `Display` and `Box<Point>` does not while `Point` has no `Display`: interpolating it is `T3018`, passing it to a `T: Display` parameter is `T3006`, and the detail names the unmet bound. A type argument that is itself a type parameter meets a bound its own bound names; a union meets it when every variant does; a distinct, through its own impl or its backing's. An array does not meet a `Display` bound there: the impl's instance reaches its argument through an erased slot, and no vtable carries an array's `Display`. An `is Trait` test still matches by the type's base, as the run-time test does. A member of a bounded impl is reached only through an instance its bounds admit, whatever the form: with `Wrapper<T> implements<T: Bump> Poke`, `w.poke()` on a `Wrapper<Plain>` is `T3006`, and so are `for`, `w[i]` and `w[i] = v` through such an impl; an operator (`+`, `<`, `in`) is `T3043`. An argument meets a bound when it implements the trait at the bound's own arguments (`S: Source<i32>` admits no `Source<i64>`).

**A struct's bounds hold at its literal.** `Wrapper :: struct<T: Bump>` puts its bound on every `Wrapper<X> { … }`: an `X` that does not meet it is `T3006` there, where a value of the type comes to exist. A type written elsewhere (`w: Wrapper<Plain>`) is not checked, since no value can inhabit it. An impl that borrows the struct's parameters (`Wrapper<T> implements Poke`) holds only for what the struct admits, so its `T` carries the struct's bound. A generic fn states the bounds it relies on: `fn<K>(m: MutableMap<K, V>)` indexing `m` is `T3006`, and says `fn<K: Hash & Equals>`.

Both checks need the arguments: a generic struct literal written without them (`Box { .value = p }`) is typed `Box`, and its bounds are not checked.

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

The lowerer synthesises an `is StructA -> StructA_method(...)` chain over every impl of the trait that monomorphization has materialised. Non-generic impls contribute one arm each; generic impls (`Foo<T> implements Trait { ... }`) contribute one arm per observed concrete `(struct, args)` pair, since each instance has a distinct runtime tag (`is Foo<i32>`, `is Foo<string>`, …). Trait args on the receiver itself are substituted into the method's signature, so e.g. `it: Iterator<i32>; it.next()` returns `[i32, Continuation]` — not the unsubstituted `[T, Continuation]`. Primitive impls remain skipped (the dispatch chain assumes struct-tagged boxes).

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
    for i in 0..<self.byte_len() {
        h = (h ^ u64(self.byte_at(i))) * 1099511628211
    }
    return h
}

// Classic form — required for traits with two or more methods.
Countdown<T> implements Iterator<T> {
    next :: fn(self) -> [T, Continuation] { ... }
}
```

- Detection: the impl body starts with `->` (arrow), or with `{` whose first significant token is **not** the start of a member declaration (`name :: fn`). Anything else inside the braces is treated as a SAM block body.
- The classic form (`{ name :: fn(...) ... }`) remains valid and is **required** for multi-method traits.
- "Single-method" here means a single *required* (body-less) method; a trait can declare additional methods with default bodies (see *Default methods* below) and still accept the SAM short forms.
- `R2016` is emitted when the short forms are used on a trait with 0 or ≥ 2 required methods.

#### Default methods

A trait method may carry a body:

```vader
Shape :: trait {
    area     :: fn(self) -> f64
    describe :: fn(self) -> string { return "a shape of area ${self.area()}" }
}
```

Any impl that doesn't override `describe` automatically inherits the body
above — the resolver clones the trait method's body into the impl at
declaration time, with `Self → forType` substituted (and trait type-params
substituted by impl trait-args). References inside the body to other trait
methods (`self.area()`) resolve through UFCS against the impl scope,
so they pick up the impl's own member when the user provides one.

```vader
Square implements Shape -> self.side * self.side
// Square.describe exists implicitly, derived from the cloned default.
```

Stdlib traits that ship with default methods:
- `Async.cancel` (does nothing).

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

Each operator trait declares exactly the member its operator dispatches to, with no
default method: `a != b` is `!a.equals(b)` and `a <= b` is `a.compare(b) <= 0`. An impl
declares only its trait's members (T3094), so an operator cannot disagree with a method
of its trait.

Compound assignments (`+=`, `-=`, `*=`, `/=`, `%=`) desugar to `lhs = lhs <op> rhs` at parse time, so they reuse the corresponding trait dispatch. The place `lhs` is still evaluated once: in `a[i()] += v()`, `a` and `i()` run first, then the element is read, then `v()` runs, and the result is written back to that same element — `i()` runs once, where the spelled-out `a[i()] = a[i()] + v()` would run it twice. Because the result is rebound to `lhs`, a compound assignment requires the operator's `Out` to be assignable to `lhs`'s type — always true in the homogeneous `Out = Self` case; a heterogeneous `Out` (e.g. `Instant - Instant -> Duration`) simply can't be used with the compound form.

Resolution rule for **arithmetic** operators (`+ - * / %`):
1. If both operands are primitive numerics, use the built-in op (current behaviour).
2. `string + string` is a built-in op (`string.concat`); `string implements Add` exists for SPEC completeness and is also reachable via UFCS — the compiler routes both paths to the same op (see §12 op-level intrinsics).
3. Otherwise, look up the matching `Add`/`Sub`/`Mul`/`Div`/`Rem` impl on the left operand's type — among several impls of the trait, the one the right operand picks (*Several impls of one trait*); the right operand must be assignable to that impl's `Rhs`, and the result type is the impl's `Out`. `Rhs` and `Out` default to `Self`, so the homogeneous case needs only `implements Add`; a heterogeneous operator (e.g. `Instant implements Add<Duration, Instant>`) spells them. The defaults fill at impl materialization, so existing `i32 implements Add` and `where T: Add` keep meaning `Add<Self, Self>`.
4. A left operand typed by a type parameter whose bound names the operator's trait (`T: Add` for `+`) dispatches through that bound, exactly as `a.add(b)` would: the right operand must be a `T`, the result is a `T`, and each instance of the enclosing function is monomorphised, so a primitive `T` gets the built-in op and a struct `T` its impl. A value of the operator's trait (`a: Add<i32>`) and a union of its implementors dispatch through it by their tag, as their method form does; so does `in` on a value of `Contains` or a union of its implementors. The operator takes the union's refusals: `a < b` on two `Comparable` values is `T3098`, since `b` may hold another implementor.
5. If no impl matches, T3017.

Resolution rule for **equality** (`==` / `!=`):
1. Primitive operands (numerics, strings, chars, bools, null) use the built-in equality op.
2. User-struct operands of the same type look up the `Equals` impl and dispatch through `equals` when one exists; **without an impl it is T3043** (`` `X` does not implement `Equals` ``). An array has none (*Equality* below), and the detail points at `content_equals`, `is_permutation_of` and `===`. When a generic impl would apply but for a bound (`Box<T> implements<T: Equals> Equals` on a `Box<Raw>`), the detail names the type argument that lacks it. `==` on a struct that never opted into value equality is almost always a bug, so it is rejected rather than silently comparing references.
3. `==` on a type-parameter operand needs a bound naming `Equals`, as `a + b` needs `Add` — `fn<T: Equals>(a: T, b: T) = a == b`. Without it, **T3043**, also when the parameter is a variant of a union (`T | null == T`). Only `x == null` needs no bound. `x in xs` follows: `T[]` implements `Contains<T>` only for `T: Equals`.
4. A union operand compares by variant: both sides hold the same variant, and those two values are equal by that variant's own `==`. Every variant but `null` must compare, else **T3043** naming it. A union compares with another union or with one of its members; two sides that share no variant are **T3001**. A variant with no tag of its own to test — a type parameter, or an instance of a generic struct whose body other instances share — may sit only beside `null` (**T3087**). An enum boxes as its integer and a distinct as its backing, so `Color | u8` or `Meters | i64` cannot tell those two variants apart.
5. Mismatched types are an error. Two numerics of different family, or two integer types neither of which holds the other (§Implicit numeric coercion), are T3017. Any other pair of scalars compares through its **backings** — a distinct type stands for its backing, through any number of layers — two integers when one holds the other, whatever the integers they are stored in (`s == w` with `s` of a distinct over `Hour` and `w: i64` compares, in `i64`), any other two when they are the same primitive, and else **T3001**: `h == INVALID_HANDLE` with `h: Handle` (`Handle :: CPointer`) against an `i64`, `b == c` with `b: u8` and a `char` variable, `name == 3`. A distinct type against its own backing compares (`path == ""` or `"" == path` with `Path :: string`), through the type's `Equals` impl when it has one, whichever side it is on; two distinct types that are not one another's backing do not (`Meters == Seconds`, both `i64`: T3001). Free literals adopt the other operand's type first, so `b == '/'` and `x == 0` compare.

Resolution rule for **ordering** (`< <= > >=`):
1. Primitive numerics and `char` use the built-in comparison ops — a float by IEEE 754 (every comparison with `nan` is false). A distinct type orders as its backing (§Distinct types). `string` orders through its `Comparable` impl, by bytes — codepoint order in UTF-8, a proper prefix first.
2. User-struct operands look up the `Comparable` impl; the lowerer rewrites `a < b` to `compare(a, b) < 0` (and analogously for the other three operators) over the i32 result. A type parameter bounded by `Comparable` dispatches the same way, through its bound; the right operand must be a `T` (T3017 otherwise).
3. If no impl matches, **T3043** (`` `X` does not implement `Comparable` ``). `bool`, enums, arrays, tuples and unions have none.

**T3043** is the shared "operator's trait is not implemented" error — it names the missing trait (`Equals` for `==`/`!=`, `Comparable` for `< <= > >=`, `Contains` for `in`) so the fix is obvious. It is distinct from T3017, which stays for plain operand-type mismatches (e.g. `i32 && bool`, two integer types neither of which holds the other). (Arithmetic `+ - * / %` on a type without the matching `Add`/… impl still reports T3017 for now.)

Index access (`a[i]`) and `in` follow the same fallback: built-in array / range first, then trait dispatch through `Index<I, T>::at` / `Contains<T>::contains` — the trait path covers struct receivers AND primitives (`string implements Index<i64, char>` enables `s[i]` without importing anything). Index assignment (`a[i] = v`) dispatches through `IndexSet<I, T>::set_at`. A type's **own** impl wins over the array it is backed by, trait by trait: a distinct `Offset :: i32[]` that implements `Index` reads through its `at`, one that also implements `IndexSet` writes through its `set_at`, and one with `Index` alone writes into its backing array, at the backing's element type. A distinct over a struct indexes only through its own impls; it does not inherit its struct's. A `Range` index on an array-backed distinct always slices the backing, and a write with neither an `IndexSet` nor an array to store into is `T3008`. A receiver that dispatches through the trait itself — a type parameter bounded by it, a value of the trait (`store: IndexSet<string, i32>`), a union of its implementors (`MutableMap<string, i32> | Log`) — reads and writes through `at` / `set_at` as its method form does. Outside an array, the key is of the trait's key type `K`, read or write, whatever the receiver (`m["nope"]` on a `MutableMap<i64, i32>` is `T3001`), and a free literal key takes it. A destructuring place (`[m["a"], m["b"]] = …`) is a write like `m["a"] = v`: it takes the `IndexSet` value type, never what the `Index` read hands back (`V | null` on a `MutableMap`).

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
| Integers, `bool`, `char` | By value |
| Floats | IEEE 754: `nan != nan`, `0.0 == -0.0` — the same in a union or a generic body |
| `string` | Structural (compares contents) |
| `enum` | Discriminant equality; every enum implements `Equals` and `Hash` |
| Distinct type | Its own `Equals` impl, else the backing type's `==` |
| Tuple | Element by element (see *Tuples*) |
| Union (`A \| B`, `T \| null`) | Same variant, then that variant's `==`; `null == null` |
| Type parameter | Through `Equals`: the bound must name it (T3043) |
| **Struct** | **Compile error (T3043) — no built-in `==`; implement `Equals`** |
| **Array** | **Compile error (T3043)** — comparing two walks them: `content_equals` (in order), `is_permutation_of` (any order, quadratic); `===` for identity |
| Type with `impl Equals` | Delegated to `Equals.equals` |
| **Trait value, fn value** | **Compile error (T3043)** — a trait value may hold an implementor without `Equals`; narrow it first (`if d is Point`) |

`===` asks another question — whether two references are the same object (*Identity* below).

A generic body compares a `T: Equals` through its `Equals`, picked from the receiver's runtime type. When the other operand holds another type — `T` is a union, or the values are typed `Equals` — `equals` answers `false` without reaching the impl. An enum or a distinct type is the exception: it boxes as its representation, so it compares as that representation does. A union whose variant has no tag of its own (an instance of a generic struct whose body other instances share) beside another non-null variant does not satisfy `Equals` (T3006).

To compare two structs, implement `Equals` (`a.equals(b)` calls it directly). A
struct has no implicit identity `==`: a bare `a == b` on one without `Equals` is
rejected at compile time, never a silent reference compare. Identity has its own
operator, `===`.

An array has no `==` at all: comparing two costs a walk of both, so the call says
so. `std/core` provides, for any `T: Equals` element:

- `a.content_equals(b)` — the same length, and equal elements in the same order;
- `a.is_permutation_of(b)` — the same elements in some order, each as many times
  (quadratic);
- `a.contains_all(b)` — every element of `b` is in `a`, each counting once;
- `a.is_disjoint(b)` — no element in common.

Nor does an array meet an `Equals` bound: `[1] in rows` (`rows: i32[][]`) and
`same(a, b)` with `fn<T: Equals>` are T3043 / T3006, and an array of arrays has no
`content_equals`. A distinct type over an array opts in by implementing `Equals`
itself (`Row :: i32[]`, `Row implements Equals`), and then compares through that
impl; `i32[](row)` gives back the array, for the methods above. A distinct over a
struct with no `Equals` of its own compares through its backing's.

#### Identity: `===` and `!==`

`==` asks whether two values are equal; `===` asks whether two references are the
**same object**, and `!==` is its negation. Two equal points built apart are `==`
(through their `Equals`) but not `===`.

- Only a reference has an identity: a struct, an array, a union of references
  (`Node | null` included), a distinct type over one of these. A union compares
  the object it holds.
- A value has none — a number, `bool`, `char`, `string`, an enum, a tuple, a fn,
  `null` on its own. Neither does a type that may hold one: a value typed by a
  trait (`i32` implements `Display`), `any`, a type parameter, `Self`. `===` on any
  of them is **T3017**: compare with `==`, or narrow first (`if d is Point`).
- The two operands must be able to hold the same object — they share a variant
  other than `null`. `Point === Label` and `Point | null === Label | null` are
  **T3017**.
- `===` goes through no trait and cannot be overloaded.

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

**A module const may be read before its declaration**, by another const or by a fn: the top level is not ordered. `INNERS :: [ONE]` above `ONE :: Inner { .n = 7 }` is an `Inner[]`. A const whose value reads itself, directly or through other consts (`A :: B + 1`, `B :: A + 1`), is `T3099`; a cycle through a `@comptime` const is reported by its evaluation (`C4009`). A read inside a lambda of the value waits for the lambda to run, so an annotated const may name itself there — `fact: fn(i32) -> i32 : (n: i32) -> if n <= 1 { 1 } else { n * fact(n - 1) }` — but an unannotated one may not: its type would depend on itself.

### Mutability: two independent axes

Vader separates **who may rebind a name** from **who may mutate what it points at**.

**The binding.** `::` freezes it, `:=` allows rebinding. If `p :: Point { ... }`, `p = otherPoint` is rejected (T3041), and so is rebinding any declaration (a module const, a fn, a type), written bare, renamed by its import or through a namespace (`P.SEP = 'x'`). Only a parameter, a name a pattern binds, and a `:=` local may be rebound; the variable of a `for … in` and the name a `match` header binds may not (§`for`, §`match`). An assignment writes to a name, a field or an element; any other target (`get() = 3`, `xs.len() = 5`, `Color.Red = .Green`) is T3082.

**The referent.** A value may be modified through any name that reaches it: a parameter, a local, a field, an element. A signature does not say what a function does with what it is lent; the compiler reads it from the body (see *What a function does with what it is lent*). Two values are **frozen**, never modified in place: the value of a **module constant**, at every level, and a **view of a string's bytes** (`s.bytes()`).

```vader
CONFIG :: Config { .retries = 3 }

main :: fn() -> i32 {
    p :: Point { .x = 1, .y = 2 }
    p.x = 5                 // OK: `::` froze the name, not the contents
    // p = other_point      // T3041: that IS the binding
    // CONFIG.retries = 5   // T3070: a module constant is frozen
    c :: CONFIG
    c.retries = 5           // OK: `c` holds a copy of the constant
    return c.retries
}
```

### Frozen values

**A module constant** has no storage a write could land in: its value is rebuilt at each read, or shared from read-only data. So:

- a write through it, directly or down a path (`CONFIG.retries = 5`, `TABLE[0].n = 1`, `[PAIR[1], y] = …`), is **T3070**;
- lending it to a function that modifies what it is lent, directly or down the calls it hands it on to, is **T3072**; a call through a trait, a bound or method syntax is judged by every function it may run;
- binding it to a name, storing it in a field or an element, returning it, or handing it to a function value makes a **copy**, which the program owns. A copy is left out where nothing in the program modifies a value of its type. A name whose copy is written, and never read nor kept in its body, is **W0019**: the write is lost.

The detail of T3070 and T3072 names the value, what modifies it, down the calls it goes through, and the way out: a name bound to the constant holds a copy to modify.

```vader
TABLE :: [1, 2, 3]

fill :: fn(buf: i32[], value: i32, n: i32) -> void {
    for _ in 0..<n {
        buf.push(value)
    }
}

refill :: fn(buf: i32[]) -> void = fill(buf, 0, 4)

fill(TABLE, 1, 2)           // T3072: `fill` modifies it (`buf` grows)
refill(TABLE)               // T3072: `refill` modifies it through `fill`
fill(TABLE.clone(), 1, 2)   // OK: a copy
```

**A view of a string's bytes** (§Strings) is the string's own bytes, which nothing modifies, and it is never copied behind the program's back: avoiding that copy is what `bytes()` is for. What holds a view, the call that makes it or a name bound to it, may read it, lend it to a function that only reads it, and return it. Written, or lent to a function that modifies it, it is T3070 or T3072. Kept, in a field, an element or a module constant's value, or handed to code the compiler cannot follow (a function value), it is **T3071**. Only the view itself counts: a byte read out of it is a value, and so is a name narrowed to a type no byte array is (`if r is Failure { failures.push(r) }`, `r` of type `u8[] | Failure`). `.clone()` makes a copy the program owns.

A function that returns a view hands views out, as `bytes()` does, and what its callers do with the result is judged the same way.

```vader
bytes_of :: fn(s: string) -> u8[] = s.bytes()   // OK: it returns the view

v :: "abc".bytes()
v[0] = 'x'                                      // T3070
bytes_of("abc").push(0)                         // T3072: `push` modifies it
p :: Packet { .payload = "abc".bytes() }        // T3071: kept
q :: Packet { .payload = bytes_of("abc").clone() }   // OK: a copy
```

**What this does and does not guarantee.** The frozen values are protected, statically. Any other value may be modified by a function it is lent to, as in Go, Java or Python, and no signature says so.

### What a function does with what it is lent

Once the program is typed, the compiler summarises what each function does with each parameter: which parts it assigns, grows or shrinks, which it keeps past the call, which it returns. The summary follows the calls over the whole program, so a write at the end of a chain of calls is found at the call that lends a frozen value. A function known without a body says what it does: an intrinsic by the compiler's own table, an `@extern` by its `@c_out` parameters. A function value may do anything. The same summary decides whether an array argument may widen its element (§Arrays, T3102).

### No mutability marker

A type says nothing about what may be written: there is no `!` after a type and no read-only form. Every value but a frozen one may be modified, and a `!` after a type is a syntax error. A module's state belongs in a `@singleton` (§12). Writing the removed `const` qualifier is P1027.

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

**Every path must produce the declared value (`T3083`).** A body that reaches its
closing brace with no trailing expression, and without diverging, is an error when
the fn declares a return type — `f :: fn() -> i32 { n :: 1 }` does not compile.
This is the other half of `T3020`, which already covered a body whose trailing
expression has the wrong type (so `fn(c: bool) -> i32 { if c { return 7 } }` was
an error before). A body **diverges**, and is accepted, when its last statement is
a `return` / `break` / `continue`, a call to a `@no_return` fn (`panic`, `todo`),
or a loop no `break` can leave — `fn() -> i32 { for { … } }` is fine, since control
never reaches the brace. Functions with no return type promise nothing and are
unaffected. A **lambda** carries the same obligation whenever a type is promised
— by an annotation, or by the slot it is handed to — and is exempt when nothing
promises one, since its return type is then inferred from the body.

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

**No explicit return-type slot on lambdas.** The return type is always inferred — from the call-site signature, an enclosing struct field's fn-type, a typed declaration, or from the body itself. If you need to annotate the return type explicitly, declare a named function instead:

```vader
inc :: fn(x: i32) -> i32 { x + 1 }
items.map(inc)
```

The `name :: fn(...) -> R { ... }` form is a regular function declaration (top-level **or** local to a fn body), not a value-position lambda. Parameter and return-type annotations are required for top-level fns (see §4 inference rules).

Closures capture their environment **by reference** (consistent with Vader's reference-semantics model for non-primitive values): an assignment to a captured variable, inside the closure or around it, is visible on both sides (a counter built via `n := 0; inc :: fn() { n = n + 1 }; get :: fn() -> i32 { n }` works as expected). The lowering implements this with single-slot cells on the GC heap for the captured variables some assignment rebinds — the binding becomes a pointer to its cell, shared by every closure that mentions it. A captured variable nothing rebinds holds the same value for its whole life, so the closure copies it instead; no program can tell the two apart. Lifting itself is transparent: the closure value is a `(code, env)` fat pointer where `code` points to a synthesised top-level fn taking the env as its first parameter, and `env` is a heap-allocated struct holding each capture's value or cell.

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
3. **Trait-typed first param**: when the first param has trait type `Trait<T>` and the receiver implements that trait, UFCS dispatches to it. `source.chars().filter(is_bf_char)` resolves through `std/iter.filter :: fn<T>(self: Iterator<T>, pred: fn(T) -> bool) -> Iterator<T>` because `StringChars` implements `Iterator<char>`. Trait-typeparam unification happens through `unifyTraitParamWithConcrete`.
4. **Union receivers**: `value.method()` on a union-typed `value` falls through to free-fn UFCS when no variant carries a struct field by that name. The first-param type can be the *union itself* (`fn read_i32(v: Value, …)`) — receiver and param match directly.
5. **`Into<Target>` last-resort coercion**: strictly weaker than every other rank; only fires when no direct candidate exists.

Specifically — a partial match where some variants of a union scrutinee carry the field and others don't still raises `T3009`; the fall-through to UFCS only triggers when *no* variant has the field at all.

#### Import requirement

UFCS resolution obeys the **same import rule as a bare call**: `x.foo()` resolves only against free functions whose owning module is reachable in the program (transitively `import`ed), exactly as `foo(x)` would. `std/core` (the implicit prelude, §11) is the sole exemption — its exports are always in scope, so `s.len()`, `bs.bytes_to_string()`, `x.hash()` work with no import. A `x.foo()` whose only candidate lives in a *non-imported* module is a **compile error** (`T3008` / `T3009`), not a silently-dropped call.

"Same rule" includes the **scope**: imports are file-scoped (§11), so `x.foo()` resolves against the imports of **the file it is written in**, never a sibling file's. A `import "p" { foo as _ }` therefore drops `foo` from both call forms in that file, while a sibling that imports `p` bare keeps both.

"Same rule" also includes the **import form**. A namespace alias (`P :: import "p"`, §11) binds one name and qualifies the rest — it puts nothing in unqualified scope — so `x.foo()` fails there exactly as `foo(x)` does, and the fix is `P.foo(x)`. That case reports **T3078**, which names the alias and spells the qualified call, rather than the shape-based `T3008` / `T3009` — when the aliased export actually fits the receiver; otherwise the shape-based code still stands. This keeps the type-checker's UFCS visibility aligned with the lowerer's: both dispatch against the same reachable module set, so a method that type-checks always lowers to a real call. (Historically the typer carried hardcoded per-primitive method tables that bypassed this, letting `s.split()` type-check without `import "std/string"` and then mis-compile; those tables were removed so primitive/array methods resolve uniformly through trait impls + free-fn UFCS.)

#### Function overloading

Two free functions with the same name **may coexist in the same module** when they differ in the type of their **first parameter** (the receiver). The resolver dispatches based on the receiver's type at the call site.

```vader
size :: fn(self: Path) -> i32 { ... }
size :: fn<K, V>(self: MutableMap<K, V>) -> i64 { ... }

p.size()            // resolves to the Path version
m.size()            // resolves to the MutableMap version
```

Rules:
- Overload candidates must differ in their first parameter type. Differing only on later parameters is **not** an overload (post-MVP — see TODO).
- Two functions with the same name **and the same full signature** (identical parameter types) in one module are a **redefinition**, not an overload — rejected at declaration with **T3053**, independent of whether they are ever called (so it catches an uncalled entry like `main`). A module spans **every file of its directory**, so this also fires when the same function is declared in two sibling files — e.g. two single-file programs sharing a folder, each with its own `main`.
- Type-param receivers (`fn<T>(self: T)`) are wildcards and conflict with every concrete-receiver overload of the same name.
- Resolution is performed at typecheck once the first argument's type is known. Among the candidates whose first parameter accepts it, the **most specific** wins — a concrete union member beats a bare `T` wildcard (`T | Boom` over `T | null` for an `i32 | Boom` argument); then, on a direct call, the candidate whose arity matches the call; then, for a free literal, the candidate whose parameter is the literal's default type — the rule a literal follows into a union (§Default integer), so `abs(-5)` reaches the `i32` overload whatever the declaration order. Through UFCS the call's arity is not known at the receiver, so that rank is skipped there and candidates of different arity are never compared on it.
- **In a generic body, a call is resolved against the type parameters, once.** A receiver or first argument typed by `T` (or by a type that mentions it, `T[]`) reaches only the candidates whose first parameter accepts `T` itself, and every instance of the body runs the candidate chosen: an overload on a concrete type is not one of them, whatever `T` turns out to be. Given `describe :: fn<T: Display>(self: T)` and `describe :: fn(self: i32)`, `show :: fn<T: Display>(v: T) -> string = v.describe()` runs the generic `describe` for `show(1)`, while `1.describe()` written on an `i32` runs the `i32` one. Behaviour that differs by type goes through a trait bound, whose impl each instance reaches (§ Specialization).
- Two candidates **of one module** still level after these ranks are **T3032** (ambiguous overload resolution) rather than a pick by declaration order: `x.or(-1)` on an `x: i32 | Error | null` fits `or(x: T | null, d: T)` with `T = i32 | Error` and `or(x: T | Error, d: T)` with `T = i32 | null` alike, and either choice would let the other unhappy variant through. Narrow `x` first. A local overload still wins a tie over an imported one.
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

Exhaustive match on unions, checked at compile time. See §4 *Pattern matching* for the full grammar — `is`-narrowing, literal patterns, the header binder with flow narrowing, struct refinement, guards, and the `T3040` reachability rule.

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

**The variable of a `for x in …` is a constant binding**, bound anew each turn, and so is each name of `for [k, v] in …`: assigning it is **T3041** (copy it into a `:=` local to change it), while changing what it designates (`x.f = 1`, `x.push(y)`) is allowed, as for any `::` binding. The condition form binds nothing: in `for i > 0 { i -= 1 }`, `i` is an ordinary local.

**What a loop iterates is evaluated once, before the first element.** A range `lo..<hi` evaluates `lo`, then `hi`, once each, when it is built — at loop entry for `for i in lo..<hi` — so `for i in 0..<n { n = 5 }` runs as many times as `n` held on entry. A lazy chain does the same, source first, then each combinator's argument, then a terminal's: `xs.map(f()).filter(p()).any_match(q())` evaluates `xs`, `f()`, `p()` and `q()` once each, in that order, before the first element — and on an empty `xs` too. The compiler fusing the chain into one loop does not change this.

The iteration form `for x in expr` accepts four shapes for `expr`:
1. A built-in array `T[]` — auto-wrapped through `array_iter`.
2. A value of type `Iterator<T>` — used directly. Two dispatch flavours:
   - **Concrete iter** (`Range<T>`, a user struct implementing `Iterator<T>`) — the `next()` call resolves statically against the impl-method.
   - **Trait-typed iter** (`Iterator<T>` itself, e.g. a fn param `fn count<T>(it: Iterator<T>)`) — the `next()` call dispatches through the lowerer-synthesised `is StructA -> StructA_next(...)` chain over every materialised impl (see *Method dispatch on trait values* in §4). Lets generic fns drive `for x in it { … }` against any concrete iterator the caller supplies.
3. A value implementing `Into<Iterator<T>>` — the for-in lowerer inserts `.into()` to obtain the iterator, then drives the loop over it.
4. A type: a range, an integer type within `i64` or a type parameter bounded by `Int` binds `x` to each of its values, the least first (`for h in Hour`, `for b in u8`, 256 turns, `255` included); an enum without variant data, to each variant in declaration order (`for d in Weekday`). `u64`, `char`, an enum with variant data and any other type are **T3088**. A range of `char` (`for c in 'a'..='z'`) steps over the surrogates, which no `char` holds.

Raw `T[]` arrays are auto-wrapped through `array_iter` (via the shipped `T[] implements Into<Iterator<T>>` impl in `std/core`), and `Range` (`0..<10`) iterates directly. User collections opt in by implementing `Into<Iterator<T>>` — the loop advances the iterator it is handed — so `for x in coll { ... }` works without an explicit `.into()`. There is no separate `Iterable` trait today (see the planned note below).

The same auto-wrap fires at any *concrete* `Iterator<T>` slot — function arguments, `return` expressions, and typed declarations — so `T[]` flows transparently:

```vader
walk :: fn(it: Iterator<i32>) -> i32 { ... }
walk([10, 20, 30])                            // call-arg coercion
fold :: fn() -> Iterator<i32> { return [1, 2, 3] }   // return coercion
buf: Iterator<i32> : [4, 5, 6]                // typed-declaration coercion
```

The coercion is gated on **canonical symbol identity** of `std/core::Iterator`; a user-defined trait that happens to be named `Iterator` is left alone. The lazy `std/iter` combinators (`map` / `filter` / …, all generators — they `yield` — over `self: Iterator<T>`) resolve **directly on a bare array** through the generator receiver-dispatch path — `arr.map(f)` needs no explicit wrap and there is no array-driven overload (§ `std/iter`). Concrete trait-instance receivers (`Iterator<i32>`, `Iterator<string>`, …) are unaffected.

```vader
// Planned — not yet exported from std/core. Today user types iterate
// via a direct `Iterator<T>` impl on the collection itself.
Iterable :: trait<T> {
    iter :: fn(self) -> Iterator<T>
}
```

### Targeting an outer loop — `break <var>` / `continue <var>`

A bare `break` / `continue` acts on the **innermost** loop. To target an enclosing
loop, name it — **by its iteration variable** (the preferred form, no declaration
needed) :

```vader
for row in grid {
    for cell in row {
        if cell == 0    { continue }      // innermost — bare
        if cell == goal { break row }     // the row-loop, by its variable
    }
}
```

`break <name>` / `continue <name>` resolves to the nearest enclosing loop whose
iteration variable (or label, below) is `<name>`. The target must be a loop —
naming a local or an unknown name is a compile error (`T3067`).

**Labels — only for a loop with no variable.** A `while`-style (`for <cond>`) or
infinite (`for {}`) loop has no iteration variable, so it is targeted by a label
declared with a `name:` prefix :

```vader
scan: for !done {
    for cell in row {
        if cell == goal { break scan }
    }
}
```

A label on a `for`-in loop (which already has a variable) is redundant and warns
(`W0010`) — use the variable instead. There is no reader-ambiguity concern: an
editor / LSP resolves a `break` / `continue` to its target loop on demand
(go-to-definition), so no annotation is forced on the common innermost case.

### `defer`

Block-scoped, executed when leaving the block where it was written:

```vader
process :: fn(path: string) -> string | Error {
    file := open(path)
    if file is Error { return file }
    defer close(file)

    {
        tmp := allocate_temp()
        defer free(tmp)
        // tmp freed at the end of this sub-block
    }

    // file closed at the end of the function
    result := read_all(file)
    if result is Error { return result }
    return result
}
```

A `return` computes its value **before** the defers it leaves run: `return read_all(file)` reads the file, then `close(file)` runs. A defer that writes a local the value reads does not change what is returned. The same holds for a block's trailing value.

A `defer` body cannot `return` (`T3106`): it runs while its block is being left, once what the block returns is decided. Nor can it `break` or `continue` a loop it is not inside of. A lambda written in a `defer` body returns from the lambda, as anywhere.

A `panic` runs the pending defers too: as the panic unwinds the call stack, each frame's own defers execute (LIFO, innermost frame first) before the process aborts. Cleanup — releasing a lock, closing a handle — therefore still happens on the abnormal path. The panic remains fatal; there is no `recover`.

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
- `string`: an interned atom id (`u32`), copied on assignment, immutable shared content.
- Structs, arrays: heap-allocated, manipulated via implicit references (the user does not see pointers).
  Passing one to a function therefore lets the callee reach the caller's value, and modify it unless it is
  frozen (see "Frozen values").

### No visible pointers

No `&`, `*`, or "pointer" type exposed in MVP. Memory management is entirely implicit (except via explicit allocator APIs for perf-critical zones, post-MVP).

### Escape analysis

The spec **allows** the compiler to allocate a struct on the stack if analysis proves it does not escape, but **does not require** it in MVP. This is a transparent optimization the user never observes.

### Explicit allocators (post-MVP)

API for perf-critical zones. Allows allocating into an arena, a buffer, etc., without breaking the GC model. To be specified when needed.

### Finalizers

**None**. Non-memory resources (files, sockets, handles) must be released explicitly via `defer`.

```vader
file := open("a.txt")
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
- Type without a `Display` (`T3018`) — an enum without `@displayable` or an impl, a struct without an impl, a type parameter without a `Display` bound (`T` alone is refused, `T: Display` is not)
- Malformed expression

Interpolation is **desugared** into one string build. An integer or a `bool` segment writes its digits straight into a buffer sized up front; a string segment is copied as is; every other segment renders through its `Display.to_string`, so interpolation honours user `Display` impls on any type. An interpolation with no integer or `bool` segment is a call to the shared `concat_N`, the same as a `+` chain.

### `Display` trait

All primitives implement `Display`, and so does `null` (`"null"`). An array renders as `[`, each element's own `Display` separated by `, `, then `]` — `"${[1, 2]}"` is `"[1, 2]"`, `"${[[1], [2, 3]]}"` is `"[[1], [2, 3]]"`; an array of a type without `Display` is `T3018`. An array does not satisfy a `T: Display` bound (`T3006`): an erased instance dispatches `Display` on its value's runtime type, and no vtable carries an array's, so `show(xs)` is refused where `"${xs}"` renders. Enums opt in through `@displayable` (§Enums). User types must impl explicitly:

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
Error`. There is no postfix-`!` shorthand: write the union out. Propagate an
error by narrowing on it and returning explicitly (below).

### `Error` trait

```vader
Error :: trait {
    message :: fn(self) -> string
}
```

Any type implementing `Error` may be returned in an error union (e.g. `T | Error`). The stdlib provides concrete errors: `IOError`, `ParseError`, etc.

### Error propagation

Propagate an error by narrowing on it and returning explicitly. After the guard,
the compiler narrows the value to its success type:

```vader
process :: fn(path: string) -> string | Error {
    raw := read_file(path)
    if raw is Error { return raw }    // raw is `string` below
    parsed := parse(raw)
    if parsed is Error { return parsed }
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
import "std/string"                                 // wildcard   — every export, unqualified
str :: import "std/string"                          // namespace  — reached as `str.trim(…)`
import "std/string" { trim as strip, split as _ }   // wildcard + modifiers — rename / exclude
```

A bare **`import "path"`** is a **wildcard**: every `export` of the module — functions, types, structs, enums, traits, and consts alike — becomes visible **unqualified** in the importing file, as if declared there. This is the default form; reach for it unless a name would clash.

A **namespace** import names its binding explicitly (`name :: import "path"`) and pulls nothing into scope on its own — every member is reached through the alias (`str.trim`, `str.Builder`, and `is` / `match` against `str.Type`). Use it to keep a module behind a short prefix, or to disambiguate a name two wildcards would otherwise both provide.

A **wildcard-with-modifiers** import (`import "path" { x as y, z as _ }`) is a wildcard that adjusts a few names: it exposes every export of `path` (exactly like the bare form) **minus** the ones listed — `x as y` drops `x` and rebinds it as `y` (a rename), `z as _` is a pure exclusion. A plain name (no `as`) inside `{ … }` is a compile error (`R2033`): the wildcard already brings it, so listing it is meaningless. Reach for this only to rename a clashing export or drop one you don't want; the bare wildcard is the default.

There is no implicit last-segment binding, and no `as` suffix on the module path itself.

#### Resolution rules

- The string passed to `import` is **strictly** a module name, looked up in the discovered index. No filesystem fallback.
- Relative paths (`./foo`, `../foo`) and bareword filesystem walks are not part of the language.
- Self-import (a file inside module `X` writing `import "X"`) is a compile error.
- `import` declarations are **file-scoped**. Names bound in one file of a multi-file module are not visible in sibling files of the same module; each file declares its own imports.
- **Wildcard ambiguity (`R2031`).** When a name is `export`ed by two or more wildcard-imported modules and used **unqualified**, the reference is a compile error naming every providing module. Qualify it through a namespace import, or rename/exclude one export. The check fires only on an actually-ambiguous *use* — two wildcards that merely happen to share an export are fine until the shared name is referenced unqualified — and a same-module declaration or a rename binding of that name shadows the wildcards and suppresses it. A name a wildcard shares with the prelude or a builtin is never ambiguous (the prelude/builtin symbol always wins).
- **Conflicting import forms (`R2032`).** Importing the same path twice in one file — bare `import "p"` plus `import "p" { … }`, or two `{ … }` — is a compile error: both are wildcards of `p`, so a second is redundant. Keep one import per path (put every modifier in its `{ … }`).
- **Plain name in a modifier list (`R2033`).** A name with no `as` inside `import "p" { … }` (e.g. `import "p" { foo }`) is a compile error — the wildcard already brings `foo`. Use `foo as bar` to rename it or `foo as _` to exclude it, or drop the entry entirely.
- **Empty modifier list (`W0011`, warning).** `import "p" {}` is just the bare wildcard with no modifiers — a warning nudges toward `import "p"`, and the formatter drops the empty `{}` on re-format.
- **Duplicate rename bindings (`R2011`).** Two rename modifiers that bind the same local name in one file — `import "a" { x as p }` and `import "b" { y as p }`, or one shadowing a prelude name — are a compile error.
- **A binding against a declaration.** A rename or namespace binding cannot take the name of a type or const the module declares, in whichever of its files (`R2011`). A module fn of that name coexists with it instead: the fn keeps the unqualified name and the import stays reachable by UFCS (§ Function overloading) — unless both have the same signature, a redefinition (`T3053`). Either error is reported on the import, in the file that writes it: the import belongs to that file, the declaration to the module. The same rule holds across files as within one, since a module's declarations are visible in every file and its imports in one. Two files importing the same name never clash.
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

`std/` lives under the toolchain's **library root**, `lib/` — a module root that hosts every namespace the toolchain ships, not the stdlib's own directory. It is resolved out-of-band, independently of `vader.json`:

- **`$VADER_HOME`** — `<$VADER_HOME>/lib/`, probed with the same marker. Optional, and it outranks the other two: an explicit setting beats an implicit guess, which is the only reason the variable exists — pointing a binary at a toolchain that is not the one beside it. A value that does **not** hold the marker is *ignored*, not fatal, so a stale setting left over from a moved install degrades to the ordinary probe rather than bricking every invocation; `vader doctor` reports it as set-and-unusable. `$VADER_HOME` also supplies the C runtime (`runtime/c/`) and, for a driven build, the compiler's own sources (`vader/` in a checkout, `src/vader/` in a bundle).
- **Sidecar of the binary** — `<dir-of-binary>/lib/`, probed with the marker `std/io/io.vader`. This is what a `dist/` bundle uses.
- **Relative fallback** — the bare `lib/`, i.e. `<cwd>/lib`, which is what a source checkout uses.

The fallback is deliberately *relative*: the resolved root becomes a module-id prefix, and an absolute root reshuffles map-keyed insertion order, drifting snapshots. `$VADER_HOME` is absolute, so it carries that hazard exactly as a bundle does — do not set it when running the snapshot corpus (the test harness clears it for that reason).

A `vader.json` may also name it through `includePaths` (`["lib"]`), which is searched **before** the out-of-band probe. That ordering is load-bearing during a layout migration: a binary whose probe is baked to the previous layout still resolves against the renamed tree, which is what makes the bootstrap seed survive the rename.

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

`main` must return `i32` (see §6) — the typechecker rejects any other signature with **T3033**. Relaxing this to allow `void` (implicit `0`) or `i32 | Error` (propagating errors from `main`) is a possible future change, not currently accepted.

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

A module's files normally all live in **one** folder: include paths are searched in order and the
first folder declaring the module wins, so a second folder declaring the same module is ignored.
The **one exception** is `build/generated/` under the project root — where a driven build
(`build.vader` — below) puts generated modules. It does not shadow a module an earlier root
provided; its files are **appended** to it. That is what lets a driver's `ctx.emit_module("app", …)`
extend the project's own `app` — the generated file becomes a module sibling, so it sees the
module's declarations (and is seen by them) with no `import` in either direction, which no separate
module could do without a cycle. The module's identity stays its primary folder; generated files
come after the hand-written ones, so file order — and therefore symbol-id assignment — remains a
function of the content alone.

The directory is found by the **loader**, not supplied by whoever asked for the compilation: it is
probed under the project root (the folder holding `vader.json`, or the invocation directory when the
project has no manifest) and contributes nothing when absent or empty. So `vader run`, `test`,
`lint`, `dump` and the LSP see generated code exactly as `vader build` does — a project that
generates is not buildable by one command only.

### Programmable build API — `build.vader`

A project drives its own build by putting a `build.vader` at its root. `vader build` with **no file
argument** finds it, compiles it, and runs it; the driver then decides what to compile, because the
compiler is part of its own import closure. A named file (`vader build src/main.vader`) bypasses the
driver and says so; `--no-hooks` skips it silently.

`build.vader` declares `module "build"` and a `build` fn — a **reserved name**, the way `main` is in
a program, with no decorator involved:

```vader
module "build"

import "toolchain/build"

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_build_file("src/main.vader")
    return ctx.emit_native()
}
```

`toolchain/build` is the one module a driver imports (plus `toolchain/ast`, to name AST types). Draining
`ctx.messages()` **is** the build: it yields each module's typed declarations, then the phase
boundaries, and the back end reuses the front end rather than re-running it. `Phase.BeforeEmit` is
the last point at which leaving the loop writes nothing, which is how a lint-only driver declines to
build without an opt-out flag.

A driver can also **generate code**: `ctx.emit_module(name, source)` hands the compiler module text,
which is materialised as an ordinary `.vader` file under `build/generated/` and compiled like any
hand-written module — real spans, readable, formattable, and found by every command, not just this
one (see the folder-rule exception above). `name`
may be a **new** module the project imports, or an **existing** one, in which case the generated
file joins it as a sibling (see the folder-rule exception above). The front end then runs again, and
the generated declarations come back through the stream, so transitive generation needs no mechanism
of its own — and every declaration is still delivered exactly once per build, so a rule applied to
the stream fires once however many rounds run. Generation stops at a fixed point (a round that
writes nothing new); `H6006` reports a driver whose output never stabilises.

Driver-contract failures are the `H6xxx` family (§12 / `vader/diagnostics/codes.vader`); a driver's
own rules are reported through `ctx.report`, which carries `H6004`.

---

## 12. Decorators

Decorators are **compiler instructions** prefixed with `@`. They operate at compile time, never at runtime.

| Decorator | Target | Purpose |
|-----------|--------|---------|
| `@comptime` | fn / value | Forces compile-time evaluation |
| `@c_pointer` | a parameter of an `@extern` fn | The callee receives the parameter's ADDRESS, not its value. No argument — `@c_out` says whether C writes through it. `T3079` anywhere else. See §13 |
| `@c_out` | a parameter of an `@extern` fn | C writes through the parameter — an array, or a `@c_struct` crossing with `@c_pointer`. No argument. `T3079` anywhere else, or on a type C cannot write into. See §13 |
| `@c_type("size_t")` | a parameter of an `@extern` fn, or the fn itself for its result | The C type the callee declares for an integer, where it is not the Vader type's own spelling. One plain string. Must be an integer type as wide as the Vader one. `T3079` on a parameter, `T3050` on a declaration otherwise. See §13 |
| `@c_header("<header.h>")` | an `@extern` fn | Includes the header and does NOT synthesise a prototype, so `cc` checks the call against the real declaration. Exclusive with the synthesised prototype for that symbol. See §13 |
| `@c_struct("struct name")` | struct decl | Declares which C type the struct mirrors, so it may cross as an address. See §13 |
| `@extern`, `@extern("symbol")`, or `@extern("module", "symbol")` | fn (no body) | Declares a user-supplied FFI symbol — see §13 |
| `@intrinsic` | fn (no body) / impl (no body) | Marks a stdlib function or trait impl as host-provided; the runtime (VM / C / WASM) wires each method by mangled name. **Required** on any bodyless free fn (`T3062`); the compiler also verifies each host import is actually wired at emit — see §12 |
| `@export` or `@export("name")` | fn | Exposes the function with no name mangling (JS-side / lib-side) |
| `@test` | fn | Marks as a test, executed by `vader test` |
| `@deprecated("reason")` | any decl | Emits a `W0001` warning at every reference — code still compiles |
| `@assert(condition)` or `@assert(condition, "message")` | top-level | Compile-time assertion; condition must evaluate to `true` at comptime, otherwise build fails with `C4015`. The optional second argument must be a *static* string literal (no `${...}` interpolation) — when present, it is appended to the C4015 detail to surface meaningful context |
| `@partial` | `match` expression | Opts out of exhaustiveness checking; missing variants no longer trigger `T3013`. Use with a deliberate `_`/binding catch-all (which also silences `W0005`) for "everything else does X" |
| `@unreachable` | `match` expression | Opts out of exhaustiveness checking like `@partial`, but asserts the *uncovered* variants can never occur: handle the possible variants explicitly (no `_` arm, no fake value) and any uncovered variant traps at runtime (`reached unreachable`). Use for "handle A/B/C, the rest are impossible". Mutually exclusive with `@partial` |
| `@no_return` | fn | Marks the fn as **diverging** — control never returns to the caller (it panics, aborts, or loops forever). A call to it types as `never`, so it is assignable into any slot (`_ -> todo("x")` where a value is expected type-checks) and terminates control flow (the call satisfies a non-`void` fn's return obligation; code after it is unreachable, `W0002`). Powers `panic` / `todo` / `unreachable` in `std/abort`. |
| `@internal` | struct field | Restricts a single struct field to its **declaring module**. Struct fields are **public by default** (the opposite polarity to top-level `export`, which is private-by-default); `@internal` opts one field out. Reading, writing, constructing-with, or pattern-binding the field from another module is rejected with `T3054`. An `@internal` field should usually carry a `default` so the type stays constructible across modules via `T {}` (otherwise the type is constructible only from inside its module — a deliberate "factory-only" pattern). |
| `@target` or `@target(.Os, …)` | top-level fn | Selects which BODY of a function this build uses — see §17 *Target selection*. **Bare** names the declaration: it carries the signature, the `export` and the vaderdoc, and optionally the general body. **With a list** it names a body for those operating systems, and is *always* a body, never a declaration. Only the OS axis selects code: there is no `@architecture`, because an architecture parameterises values and never includes or excludes a declaration. Rejected anywhere but a top-level fn (`P1014`) — on a struct, a trait or an impl member it would parse and then do nothing, and a silent no-op is worse than either answer. |
| `@displayable` | enum decl | Generates the enum's `Display`: each variant renders as its own name (`"${Direction.East}"` is `"East"`). The impl is an ordinary one, so an explicit `implements Display` beside it is `R2030`. Rejected anywhere else (`P1014`). |
| `@singleton` | top-level fn with no parameter | Runs the body **once per program** and hands every call the instance it built: `@singleton log :: fn() -> string[] = []`, then `log().push("x")` from anywhere, and every later `log()` sees it. The instance is ordinary heap state, not a frozen value: writes through it stay, and one built from a module constant is a copy of it. This is how a module keeps state: a module holds constants and functions, no variable. A singleton takes no parameter, has no type parameter, and neither `await`s nor `yield`s (`T3103`): an argument would ask for one instance per value, and a body that suspends would let another call see it half built. A call that comes back into the singleton while its body runs traps. It cannot run at comptime (`C4018`): only the program's run builds the instance. Anywhere but a free function it is `P1014`. |
| `@returns(cond)` | top-level fn returning `bool` | Declares that the predicate returns the value of `cond`, over its parameters: a call narrows its arguments as `cond` would, in every module, and the body is checked against it at each value it returns (`T3111` to `T3113`). See *A declared guard* under §Operator precedence. |
| `@ensures(cond)` | top-level fn | Declares that `cond`, over its parameters, holds once the fn has returned: a call written as a statement or a `let` value narrows its arguments for the rest of the block, in every module, and the body is checked against it at each return and at its end (`T3112` to `T3114`). See *A declared postcondition* under §Operator precedence. |
| `@allow_unused` | any top-level decl | Exempts the declaration from the `W0007` dead-code lint (an unused private fn / const / type / enum / trait / alias). Use for intentional dead code : an API not yet wired, a helper kept for symmetry, or a test fixture's deliberate decoy. The declaration is treated as a reachability root — never flagged, and anything it references stays live. |

`@extern` and `@intrinsic` are siblings — both apply to declarations the source doesn't define a body for, with the host filling in the runtime behavior. `@extern` is for **user code** crossing into FFI; `@intrinsic` is for **stdlib code** whose implementation lives in the host runtime (e.g. `print`, `collect`, the methods of `string implements Add / Hash / Index`). The decorator is **load-bearing**, not merely informational: a bodyless free fn *must* carry `@intrinsic` or `@extern` (`T3062`), so host-ness is always *declared* rather than implied by the missing body — a bodyless `Name :: fn(...)` is unambiguously a host, and a named function-*type* is spelled inline at its use sites (not as a bodyless declaration). The compiler then verifies, at bytecode emit, that every non-`@extern` host import is actually wired: its mangled name must be recognised by the intrinsic manifest (`intrinsic_id_for` — itself exhaustively dispatched by the VM and C backends, so `T3013` forces both to handle it) or map to a dedicated bytecode op; an unwired host fails the build rather than reaching runtime as an unbound `call.import`. This closes the chain bodyless ⟹ `@intrinsic` ⟹ recognised ⟹ served.

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
@extern("puts") c_puts :: fn(s: string) -> i32                  // C symbol: puts
@extern("env", "console_log") log :: fn(p: i32, n: i32) -> void // C symbol: console_log
```

The decorator accepts **0, 1, or 2 string arguments**. The **last** string is the foreign symbol name (the C linker symbol on the native target; the WASM `field` on a future WASM target). The **first** of two arguments names WHERE the symbol comes from. The VM `dlopen`s it, so `@extern("z", "compress2")` reaches `libz` under `vader run`; the C-emit DROPS it and the symbol resolves through the ordinary link line, so it never becomes a `-l`. A library that shadows a libc symbol therefore gives the two backends different functions from one source — name the library only when the VM needs it, and link it with `--ldflags`. A future WASM-emit consumes it as the import module (`"env"` by convention). Omitting all arguments reuses the Vader-side fn name as the C symbol. 3+ arguments or any non-string-literal argument is `T3050`.

`@extern`-decorated fns **must be bodyless** — declaring a body alongside `@extern` is `T3051`.

### `@c_pointer` — a parameter crossing as an address

A C function often takes a pointer where the value would do: `localtime(const
time_t *)` reads through it, `WriteFile(…, LPDWORD, …)` writes through it.
Nothing in a Vader signature can say which — `write(fd: i32)` passes by value
and `localtime(t: TimeT)` does not — so the fact is annotated, on the parameter:

```vader
TimeT :: i64

@extern("localtime")
localtime :: fn(@c_pointer t: TimeT) -> CPointer
```

The shim spills the argument to a stack temporary and hands over its address;
**no pointer type ever enters Vader**. The temporary lives for the call and no
longer.

`@c_pointer` takes **no argument**. A scalar crosses read-only (`const T*`); to
read one back, see `@c_out`.

It is accepted **only on an `@extern` declaration** — on a fn Vader compiles a
body for, an address has no meaning. Any decorator on a parameter other than
`@c_pointer` and `@c_out`, an argument to either, or either outside an `@extern`,
is `T3079`.

### `@c_out` — C writes through the parameter

```vader
@extern("read")
sys_read :: fn(fd: i32, @c_out buf: u8[], count: i64) -> i64
```

Without `@c_out`, C only reads what it is lent: an array crosses as `const void*`,
a `@c_struct` mirror is filled before the call and not read back. With it, an array
crosses as `void*` and C writes into its buffer in place; a mirror is filled, then
copied back after the call. A frozen value is refused there (T3072), as it is by any
parameter its callee modifies.

`@c_out` needs something C can write into — an array, or a mirror crossing with
`@c_pointer`. On a scalar or a `string` it is `T3079`: what C writes into the
shim's temporary dies with it at the return. To read a scalar back, lend a
**one-element array**: `@c_out written: u32[]` reads back on both backends, the
shape `WriteFile`'s `lpNumberOfBytesWritten` takes. Every `T*` out-param —
`getsockname`'s `socklen_t*`, `sqlite3_open`'s `sqlite3**` — takes that shape.

### `@c_header` — letting the header own the prototype

By default an `@extern` synthesises its own C prototype. When the symbol already
has one in a system header, that synthesis is a *conflicting declaration* the C
compiler refuses — `clock_gettime` against `<time.h>`, `WriteFile` against
`<windows.h>`. `@c_header` includes the header instead:

```vader
@c_header("<time.h>")
@extern("clock_gettime")
sys_clock_gettime :: fn(clock_id: i32, @c_out ts: i64[]) -> i32
```

The two are exclusive **per symbol**: with `@c_header`, no prototype is emitted,
and `cc` checks every argument against the real declaration. That is what caught
a `uint32_t*` passed where Win32 wants `LPDWORD`.

**It is the only check that the declaration matches the real function.** A bare
`@extern` synthesises its prototype FROM the Vader signature, so the two agree by
construction and nothing compares them to the header: declaring `isatty` as
`fn(fd: i64) -> i64` compiles, links against the real `int isatty(int)`, and
misreads the ABI at run time. Reach for `@c_header` by default, not only to
settle a conflict: it is the ONLY check that the declaration matches the real
function, since a bare `@extern` synthesises its prototype FROM the Vader
signature and nothing ever compares the two.

A quoted header resolves against the entry file's directory, wherever `--out`
writes the generated C: the build hands that directory to `cc` as `-iquote`. So
`@c_header("\"my_header.h\"")` finds a header sitting next to the entry, and
`"\"include/my.h\""` one below it; a header installed in a system location takes
angle brackets.

### `@c_type` — the C spelling of an integer

A synthesised prototype spells each number by its Vader type: `u64` is
`uint64_t`. Where the C function declares another name for the same width
(`size_t`, `ssize_t`, `off_t`, `DWORD`), that prototype conflicts with the
header the C compiler sees, and `@c_type` names the C type instead:

```vader
@c_type("size_t")
@extern("strnlen")
c_strnlen :: fn(s: string, @c_type("size_t") max: u64) -> u64
```

On a parameter it spells that parameter; on the declaration, the result. Its
argument is one plain string, and it applies to an integer only, a distinct type
over one included (`T3079` on a parameter, `T3050` on the declaration, as
anywhere outside an `@extern`). The shim casts at the call, `(size_t) max` going
in and the result back to the Vader type coming out, but the value keeps its
width: the C type must be an **integer as wide** as the Vader one, since the
interpreter hands the callee the Vader width in an integer register. A native
build asserts it once per spelling and Vader type
(`_Static_assert(sizeof(size_t) == sizeof(uint64_t) && (size_t) 0.5 == 0)`).
With `@c_header`, the header owns the prototype and `@c_type` only adds the
casts.

### `@c_struct` — mirroring a C struct

A Vader struct may mirror a C one, and then cross as an ADDRESS:

```vader
@c_struct("div_t")
Div :: struct { quot: i32, rem: i32 }

@extern fill_div :: fn(@c_pointer @c_out d: Div, quot: i32, rem: i32) -> void
```

The parameter must carry `@c_pointer`; a `@c_struct` type without it is
`T3050` ("crosses as an address — mark the parameter `@c_pointer`"). The shim
declares a REAL C struct and marshals **field by field, by name**, so `cc`
computes every offset from the actual header and checks every field's type —
nothing here assumes a layout. `@c_out` picks the direction: without it C reads
what Vader holds, with it the shim copies back what C wrote.

The emitted C also carries `_Static_assert` lines: each mirrored field's width
against the C field of that name, each field's signedness, each field's OFFSET
against `__builtin_offsetof`, and two bounds on the struct — the interpreter's
computed block fits inside `sizeof(C)`, and `sizeof(C)` fits the 4 KiB block the
interpreter reserves. A drifting header then fails the build.

The offset assert is what makes a mirror **a contiguous LEADING prefix** rather
than any subset. The shim itself would not need it — it copies by NAME and `cc`
resolves both offsets. The interpreter would: it lays its block out from the
declared fields at natural alignment from zero and hands that address to the real
callee, so skipping a member shifts every field after it under `vader run` alone,
where nothing on the Vader side could see it. A mirror may therefore stop early;
it may not have holes.

**The VM runs a `@c_struct` argument.** It builds the block itself from the
declared field widths, passes its address, and reads it back when the parameter
carries `@c_out`. What differs from native is WHERE the offsets come from: `cc` reads
the header, the interpreter computes them from the Vader field types. So a field
declared WIDER than its C member would place every following field at a
different offset under `vader run` than in a built binary — which is exactly why
the width check below is exact rather than merely fitting.

### A mirrored field's width

A mirrored field is checked against the C one **by width**, and the check is
**exact**: `sizeof(C field) == sizeof(Vader field)`, whichever way the copy runs.

Exactness is what the interpreter needs. The native shim could tolerate a wider
Vader field where C writes — the copy would extend rather than truncate — but the
VM lays its block out from these very widths and hands its address to the real
callee, so one field wider than its C member shifts every field after it. The
interpreter then reads its own block back consistently and nothing on the Vader
side can see the difference; only the C callee does.

The width comes from the **Vader field's own type**. Nothing is declared: `cc`
reads both sides and the check is a `_Static_assert` in the emitted C, so a
header that changes a width fails the build instead of passing unnoticed. The
signedness is pinned the same way — only the width may differ between the two,
because the shim copies with C's own conversion while the interpreter reads the
block back using the Vader field's signedness.

A type whose width differs between systems therefore takes **one mirror per
system**, selected the way `stat` is: a mirror and an `@extern` for each, chosen
by `@target` at the call. `suseconds_t` — 4 bytes on Darwin, 8 on Linux — cannot
be covered by declaring the wider one.

A mirror stays **partial**: declaring two fields of a 144-byte `struct stat`
copies those two and ignores the rest.

A member that is itself a struct takes a **nested mirror** — a field whose type
is another `@c_struct`. C holds it inline; Vader holds it BY POINTER, and the
shim descends the C path (`.srWindow.Right`) while dereferencing the Vader one,
so the two layouts still never meet. Nesting is capped at 16 deep.

```vader
@c_struct("SMALL_RECT")
SmallRect :: struct { Left: i16, Top: i16, Right: i16, Bottom: i16 }

// Whole, not `{ srWindow: SmallRect }`: `srWindow` is the fourth member, and a
// mirror that skipped the three before it would fail the offset assert.
@c_struct("CONSOLE_SCREEN_BUFFER_INFO")
ScreenBufferInfo :: struct {
    dwSize:              Coord
    dwCursorPosition:    Coord
    wAttributes:         u16
    srWindow:            SmallRect
    dwMaximumWindowSize: Coord
}
```

> A field decorator `@c_size(N, .System)` used to state the C width per system.
> It was removed: it carried an OS axis and no ARCHITECTURE axis, while a C
> struct's layout differs between arches of one system — `st_mode` sits at
> offset 24 on linux-x86_64 and 16 on linux-arm64 — so no single annotated
> mirror could be correct for both. An arch axis would not have saved it either:
> the arches also disagree on field ORDER, which no per-field annotation can
> express. `struct stat` is not mirrorable at all — see
> `docs/adr/0013-what-the-ffi-boundary-cannot-express.md` for what to reach for
> instead. `P1034` retired with it, and `T3080` was
> reused for the callback shape rule below.

### The opaque buffer — when there is no mirror to write

A C struct whose members Vader never reads can cross as a **lent `u8[]` nobody
interprets**: reserve its size, hand it over, hand the same array back. `termios`
in `lib/system/posix` does exactly that — `tcgetattr` fills it, `cfmakeraw`
rewrites it, `tcsetattr` applies it, and no Vader code ever looks inside.

It is the LAST resort, because **nothing about it is checked**. A mirror pins
every field's width and signedness against the real header at build time; a
buffer pins nothing. Its size is a constant a human transcribed, and the callee
writes `sizeof(struct …)` bytes into it whatever that constant says — so a size
taken too LOW is an out-of-bounds write that no diagnostic, no assert and no
backend will report. Take it from the LARGEST system in scope and say so at the
declaration: over-reserving wastes bytes, under-reserving corrupts.

Reach for it only when a mirror cannot exist — the struct has no member Vader
needs to name, or its layout has no stable public shape. Whenever a field has a
name, mirror it.

### Allowed signature types

The C ABI marshals these scalars (`void` as a return only, `null` never):

```
i8 i16 i32 i64    u8 u16 u32 u64
f32 f64    bool   char    void    string
```

`string` crosses in both directions, with one asymmetry worth stating:

- as an **argument** it becomes a `const char*`. An atom that owns its bytes is
  passed straight through; a SLICE atom is copied to a NUL-terminated heap dup,
  freed after the call.
- as a **RETURN** it is interned into the atom table and **borrowed** — never
  freed. That is right for the library-owned pointers this serves (`getenv`,
  `strerror`); its worst case is a leak on the C side, never a corruption. The
  interning happens BEFORE the argument buffers are released, because a returned
  pointer may aim into one of them (`strstr` gives back a suffix of its
  haystack).

`string | null` is admitted as a result and is the only way a callee can say
"absent" rather than "empty" — `getenv` rests on that distinction.

Plus, on top of the scalars:

| shape | direction | notes |
|---|---|---|
| a **distinct type** | both | zero-cost, so its ABI is its backing's — `Handle :: CPointer` is the idiom for a foreign handle |
| a **nullable foreign pointer** (`CPointer \| null`) | both | one of the two union shapes with an ABI; C has no other nullable scalar |
| a **nullable string** (`string \| null`) | RESULT only | how a callee says "absent" rather than "empty"; the atom is borrowed, as above |
| **`i64(p)` / `u64(p)` on a `CPointer`** | reading only | a foreign sentinel that is not NULL — `INVALID_HANDLE_VALUE`, `MAP_FAILED`, both `-1` — is invisible to `CPointer \| null`, which narrows on zero alone. Reading the pointer as a 64-bit integer, which holds an address on every target, is the only way to test one. Narrower targets (`u8(p)`, `i32(p)`) are `T3010`: they would drop address bits, as is `f64(p)`. The reverse — `CPointer(42)`, fabricating a pointer — stays `T3010`, and nothing needs it: a sentinel is RETURNED and compared, never passed |
| an **array of scalars** | ARGUMENT only | crosses as ONE bare pointer; a length, when the callee wants one, is a parameter of its own. C cannot fabricate a Vader array, so an array RETURN is rejected. `@c_out` decides `void*` vs `const void*`, and what C writes reads back |
| a **`@c_struct`** | ARGUMENT only, with `@c_pointer` | see above; both backends, with the offset caveat noted there |
| an **enum with a written width** | ARGUMENT only | crosses as the integer its variant stores, at that width (`enum(i32)` → `int32_t`), and one with variant data as its written value (§ Variant data). An inferred width moves when a variant is added, so it is `T3050`. A RESULT would let C hand back an integer no variant holds, so it is rejected too. A `@c_struct` field of enum type needs a written width as well, and cannot be an enum with variant data |
| a **function type** | ARGUMENT only | a callback — see below; native backend only |

Anything else (a plain struct, a trait, a type-param) is `T3050`. Future
iterations may add:
- opaque pointer types alongside a future `unsafe` block facility (deferred — see Appendix B)
- struct passing BY VALUE

### Callbacks

A parameter may be a **function type** — a C callback. What crosses is the
function's ADDRESS, so every part of its signature has to cross too: C calls it
with those very types.

```vader
double_it :: fn(x: i32) -> i32 = x * 2

@extern call_twice :: fn(f: fn(i32) -> i32) -> i32

call_twice(double_it)                 // ok
call_twice((x: i32) -> x * 2)         // T3080
```

**The argument must NAME a function.** A lambda or a closure is a value whose
code takes a leading environment and boxed arguments, so a foreign callee calling
it would jump into the wrong ABI; only a named function's own emitted symbol
carries the native signature. The type is right in both cases — this is a shape
rule, which is why it has a diagnostic of its own (`T3080`).

**A callback is NATIVE-ONLY.** Under the interpreter a function is a bytecode
index with no machine code to address, so a program that passes one traps rather
than running. Build it instead.

**A callback's own signature is narrower than an `@extern`'s.** An `@extern`
parameter reaches C through a shim that marshals — `string` becomes a
`const char*`, an array becomes its data pointer — but C calls a callback
DIRECTLY, with no shim anywhere. So a callback signature admits only the types
that need no marshalling: the numeric scalars, `bool`, `char`, **`CPointer`**,
distinct types over any of those, and `void` as a return. `string` and arrays are
`T3050` inside one. `CPointer` is what makes the C comparator shape reachable —
`qsort`'s `int (*)(const void *, const void *)` is written
`fn(CPointer, CPointer) -> i32`.

A function type is rejected as a RETURN: a C function handing back code Vader
would call has no representation here.

The name must be reachable WITHOUT a namespace alias: `H.double_it` is `T3080`
today, because the check resolves an identifier and an alias-qualified name is
not one.


### Native target — code generation

For each user `@extern` the compiler emits one forward declaration at the top of the generated `.c`, then a per-call shim that the bytecode's `call.import` jumps to:

```c
// Forward declaration — emitted only WITHOUT `@c_header`; the header owns the
// prototype when there is one.
extern int32_t add_i32(int32_t, int32_t);

// Shim — bridges the Vader-side ABI to the foreign signature. One per `@extern`,
// named after the declaration's mangled name.
static int32_t vader_host_snippet_add_i32(int32_t a0, int32_t a1) {
    return add_i32(a0, a1);
}
static size_t vader_host_snippet_c_strlen(vader_string_t a0) {
    const char* c0 = vader_string_to_cstr(a0);
    size_t r = strlen(c0);
    vader_cstr_free_for(a0, c0);
    return r;
}
```

The shim is **emitted by the compiler** — the user never writes the `vader_string_t` ↔ `const char*` glue manually. `string` parameters are marshalled to NUL-terminated UTF-8 `const char*` with a frame-lifetime guarantee: the buffer is valid only during the call and released on return. A callee that RETAINS the pointer reads freed memory afterwards, and nothing diagnoses it.

Two distinct `@extern` decls sharing the same C symbol (`@extern("strlen") a` + `@extern("strlen") b`) are `T3050` — the synthesised prototypes would disagree while the linker resolved both calls to one function. **`@c_header` on BOTH lifts it**, because neither synthesises a prototype and `cc` checks each call against the real one. That is what makes a varargs symbol bindable: one `@extern` per argument shape, each checked against the header.

### Linking

```bash
vader build --emit=executable --ldflags="helper.o -lcrypto -L/usr/local/lib" prog.vader
```

`--ldflags="<raw flags>"` passes a whitespace-split string of linker flags directly to `cc` — append `.o` files, `-l<lib>` libs, `-L<dir>` paths, frameworks, etc. The MVP doesn't ship a manifest format; everything goes through `--ldflags`.

### VM behaviour

The VM resolves an `@extern` user import at the call: it `dlopen`s the library named by a 2-argument `@extern` (the running process's own scope when there is none), `dlsym`s the symbol, and calls it through a data-described trampoline — one class per argument slot, then a flat frame of 8-byte slots. Nothing has to be registered; whatever the process already links is reachable. A symbol the loader cannot find traps naming the symbol — `extern 'X' at pc=N: symbol not found`.

The trampoline covers less than the native shim: integer, `bool` and pointer-width arguments, `f64`, `string`, lent arrays and `@c_struct` mirrors, up to 8 arguments. Outside that it TRAPS naming the reason rather than guessing — a `char` or `f32` parameter, a lent array whose elements are not integers, a call mixing floating and integer arguments, more than two floating ones, more than eight arguments, an `f32` result. A `string` result is covered, not trapped: `getenv` returning `string | null` works under `vader run`. A **callback** is the one shape that cannot work here at all: the interpreter has no address for a Vader function.

C-emit and WASM continue to resolve `@extern` against the system linker / module import table respectively; the same `@extern` decl compiles for all three backends, only the binding mechanism differs.

### Future WASM target

When the WASM emitter lands (see §17 *Compilation Targets*), `@extern` will additionally support the WASM `(module, field)` shape:
- 2-arg form `@extern("env", "console_log") log` → `(import "env" "console_log" (func …))`
- 1-arg / 0-arg form defaults the module to `"env"`.

The C-emit will continue to drop that first string; the VM will continue to `dlopen` it. The same `@extern` decl compiles for every target — only the binding mechanism differs.

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

`build_lookup_table()` runs during compilation — loops, local mutation and calls are evaluated by the embedded bytecode VM (see the implementation note). `TABLE` is a constant whose value is computed once at compile time. When it is an array of primitive elements it is **materialised into the binary's read-only data section** (`.rodata` natively, a data segment under wasm) and referenced by a zero-copy view — never rebuilt at runtime ; otherwise the value is inlined at each use site.

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

In the self-hosted compiler the comptime engine is a **tree-walk AST interpreter** (`vader/comptime/`) for the common case — expression evaluation plus calls to functions with a single `return <expr>` / trailing-expression body. A decl the tree-walk can't evaluate (loop, statement-bodied callee, local mutation) is **staged to bytecode and run by the embedded VM** (`vader/comptime_vm`, between `evaluate_project` and `lower_project`) — the model the TypeScript reference compiler always used. The VM result is bridged back to a comptime value and injected. Guards bound this: a step budget bounds non-terminating loops (`C4004`), and a VM trap surfaces `C4002` ; a genuinely unevaluable shape still surfaces `C4001`. There is no host-purity sandbox — a `@comptime` decl may call any host, so reading the clock / filesystem / process state at comptime yields non-reproducible output; keeping comptime deterministic is the author's responsibility. Generic instances are observed during evaluation and fed to the monomorphizer.

### Reflection / comptime intrinsics

Compiler-built `@<name>(args)` calls usable in *expression* position. Distinct from decorators, which annotate declarations. Reflection intrinsics operate on a type expression and **fold to a constant at lower time**; the comptime-host builtin `@file` reads project state and bakes its result before the lower phase. Both shapes compose freely with `@assert(...)` and (eventually) `where` predicates to drive comptime branching on type shape, layout, or external content.

The "Signature" column below uses `T: type` for arguments that name a type. A bare type-ident like `i32` is a value of the metatype `type` (§4), so `@size_of(i32)` reads `i32` *as a value* — the intrinsic itself takes a value-position arg, and the typechecker validates it is `type`-typed. `@size_of` uniquely also accepts a runtime `type` value (e.g. a fn param `fn(t: type)`); the other reflection intrinsics require the arg to fold to a static type at the call site.

| Intrinsic | Signature | Result | Notes |
|-----------|-----------|--------|-------|
| `@size_of(T)` | `(T: type) -> i64` | Width in bytes of the SLOT that carries a `T` — a field, a local, a parameter — not the size of the object a reference points at. | Primitives use Vader's ABI sizes (`i8` → 1, `i32` → 4, `i64`/`u64`/`f64` → 8, `string` → 4 — an interned atom id, `null` → 0). An enum rides its `repr`, so `enum(u8)` → 1, `enum(i32)` → 4, and an unwritten width is the narrowest its values fit (`enum { A, B }` → 1). A concrete reference — struct, array, tuple, fn value — is a bare pointer, 8. Only an ERASED slot (trait object, union, `any`) carries a `vader_box_t`, 16, because no single object header answers for every variant it may hold. Comptime-only / unresolved kinds → 0. The only intrinsic that also accepts a runtime `type` value; the lowerer folds the static case to a literal and routes the runtime case through a `size_of.type` op. |
| `@align_of(T)` | `(T: type) -> i64` | Alignment in bytes of that slot. | Each scalar aligns to its own width; a `vader_box_t` is 16 wide but its widest member is a word, so it aligns to 8. |
| `@type_name(T)` | `(T: type) -> string` | Printable name of `T`. | Same shape as the typechecker's `displayType` (`"i32"`, `"MutableMap<i32, string>"`, `"i32 \| string"`). |
| `@type_kind(T)` | `(T: type) -> string` | Discriminator of `T`'s shape. | Stable strings: `"primitive"`, `"struct"`, `"enum"`, `"union"`, `"array"`, `"tuple"`, `"fn"`, `"trait"`, `"type"`, `"any"`, `"unknown"`. User code is expected to compare on exact match (`if @type_kind(T) == "struct" { ... }`). |
| `@min(T)`, `@max(T)` | `(T: type) -> T` | The least, the greatest value of the integer type `T`, a range, a primitive, or a type parameter bounded by `Int`; of an enum without variant data, its variant of the least, the greatest value; of `char`, U+0000 and U+10FFFF. | A literal of `T`, per instance for a type parameter. **T3110** for any other type (§Range types, *Bounds*). |
| `@field_count(T)` | `(T: type) -> i64` | Number of fields on a Struct, or elements on a Tuple. | Returns 0 for any other shape. |
| `@variant_count(T)` | `(T: type) -> i64` | Number of variants on a Union or Enum. | Returns 0 for any other shape. Unions are canonicalised by `unionOf` before counting (a union of unions flattens). |
| `@field_index(T, "name")` | `(T: type, name: string-literal) -> i64` | 0-based position of `name` in `T`'s field list. | `T` must be a `struct` (not a Tuple, not a primitive); `name` must be a *static* string literal naming an existing field. T3002 if either constraint is violated, T3009 if the field is unknown. |
| `@satisfies(T, Trait)` | `(T: type, Trait: type) -> bool` | True iff `T` has an explicit `T implements Trait` impl in scope, or has it built in (an enum's `Equals`). | Walks the project's impl registry. Returns `false` if `Trait` resolves to anything other than a `trait` symbol, or if no impl is found. Numeric primitives carry `@intrinsic` `Add`/`Sub`/`Mul`/`Div` impls in `std/core`, so e.g. `@satisfies(i32, Add)` is `true`. The same impls underpin the Layer 7e automatic enforcement of `<T: Trait>` bounds. |
| `@file(path)` | `(path: string) -> string` | UTF-8 contents of the file at `path`, baked at compile time. | The path is resolved relative to the source file containing the call. `path` must be comptime-evaluable — a string literal, an ident pointing at a string-typed const, or any expression whose result the comptime VM can reduce to a string (e.g. `FILENAME + ".txt"`). The sandbox confines the resolved path to the project root; escapes raise `C4011`. Missing file raises `C4006`. |
| `@type_of(x)` | `(x: value) -> type` | Static type of `x` as a `type` runtime value. | Argument is **not evaluated at runtime** — only its static type is read at the call site. Useful as input to other reflection intrinsics (`@fields(@type_of(point))`). |
| `@fields(T)` | `(T: type) -> Field[]` | Field introspection for a struct. | `Field` carries `name: string`, `offset: i64`, `ty: type`. Materialised at lower time as a `Field[]` literal in the const pool. T3002 if `T` isn't a struct. |
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

Types: `Continuation`, `Range`, `Field` (reflection — see §14).

Primitive trait impls: `string implements Add` (via `string.concat` op), `string implements Hash`, `string implements Comparable` (via the `string.compare` op), `string implements Index<i64, char>` and `Index<Range<i64>, string>` (power `s[i]` and `s[lo..<hi]`), `Equals` on every primitive (floats, `bool` and `string` included), and `Hash`/`Comparable`/`Step` on the integer primitives + `char`. `T[] implements<T> Add<T[]>` concatenates — `a + b` is a fresh array holding `a`'s elements then `b`'s, neither operand touched — mirroring `string + string`; it is written in Vader over `push_all`, not an intrinsic, so it allocates once per application (a chain `a + b + c` allocates twice). `Add`/`Sub`/`Mul`/`Div` on every numeric primitive. (`%` is a built-in op; the `Rem` trait is declared for user overloading but is **not** impl'd on the primitives.) The integer `Hash`, `Comparable` and `Step` impls and the two `Index` impls on `string` are written in Vader; the rest are `@intrinsic` and bodies are host-provided.

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
read_stdin :: fn(n: i64) -> string | Error  // read up to n bytes from stdin
read_file_string  :: fn(path: string) -> string | Error
write_file_string :: fn(path: string, content: string) -> null | Error
read_file_bytes   :: fn(path: string) -> u8[] | Error
write_file_bytes  :: fn(path: string, content: u8[]) -> null | Error
exists     :: fn(path: string) -> bool
is_dir     :: fn(path: string) -> bool
read_dir   :: fn(path: string) -> string[] | Error  // names only (no recursion)
current_executable_location :: fn() -> string       // absolute path of the running binary
temp_dir   :: fn() -> string                        // OS temp dir, `/`-separated, no trailing slash
```

`print` / `println` / `eprint` / `eprintln` are generic over `Display`:
`println(42)` and `println(my_struct)` both monomorphise against the
argument's type and call `msg.to_string()` (the `Display` impl member)
before writing the bytes. No per-type wrapper, no virtual dispatch; the
coercion is in the function source, not a separate lowerer pass.

I/O is **synchronous blocking** only in MVP.

### `std/string`

Width-based helpers (`pad_start`, `pad_end`) count codepoints, as `len` does; a codepoint is not a terminal column (a wide CJK glyph or a combining mark still counts one).

```vader
// Core access (intrinsics — no body in Vader).
is_empty    :: fn(s: string) -> bool                   // sugar for s.byte_len() == 0
contains    :: fn(s: string, sub: string) -> bool      // the `Contains<string>` impl (powers `sub in s`); pure Vader, not a host intrinsic
starts_with :: fn(s: string, prefix: string) -> bool
ends_with   :: fn(s: string, suffix: string) -> bool
matches_at  :: fn(s: string, offset: i64, sub: string) -> bool  // `sub` at byte `offset`
split       :: fn(s: string, sep: string) -> string[]       // an empty `sep` gives one segment per codepoint
trim        :: fn(s: string) -> string
to_upper    :: fn(s: string) -> string
to_lower    :: fn(s: string) -> string

// Parsing. `ParseError` is the union arm raised on malformed / empty / overflow.
ParseError  :: struct { msg: string }              // implements Error
parse_int   :: fn(s: string) -> i32 | ParseError
parse_float :: fn(s: string) -> f64 | ParseError     // pure-Vader, correctly rounded (std/core Eisel-Lemire)

// Codepoint walkers. `s[i]` (Index impl in std/core) is the primary access form.
len              :: fn(s: string) -> i64                        // codepoint count, allocation-free
chars            :: fn(s: string) -> StringChars                // StringChars implements Iterator<char>

// Byte access (raw UTF-8), read in place. `byte_len`, `byte_at`, `byte_slice`, `is_ascii`,
// `codepoint_at_byte`, `bytes` and `bytes_to_string` live in the prelude (`std/core`).
byte_len          :: fn(s: string) -> i64                           // byte length, O(1)
byte_at           :: fn(s: string, i: i64) -> u8                    // the byte at `i`; traps past the end
byte_slice        :: fn(s: string, start: i64, end: i64) -> string  // bytes `start..<end` as a string
is_ascii          :: fn(s: string) -> bool                          // every byte below 0x80, no walk
codepoint_at_byte :: fn(s: string, i: i64) -> [char, i64]           // the codepoint at byte `i`, the bytes it spans
bytes             :: fn(s: string) -> u8[]                          // UTF-8 bytes as an array
bytes_to_string   :: fn(bs: u8[]) -> string                         // inverse of bytes()

// Indexing helpers. The result is `-1` on a miss.
index_of      :: fn(s: string, c: char, from: i64) -> i64
last_index_of :: fn(s: string, c: char, min_index: i64) -> i64

// Ordering — case-sensitive and case-insensitive lexicographic comparators.
compare_ascending    :: fn(a: string, b: string) -> bool
compare_ascending_ci :: fn(a: string, b: string) -> bool

// Format helpers (pure Vader).
pad_start  :: fn(s: string, width: i64, fill: char) -> string
pad_end    :: fn(s: string, width: i64, fill: char) -> string
join       :: fn(parts: string[], sep: string) -> string
left_trim  :: fn(s: string) -> string
right_trim :: fn(s: string) -> string

// The bytes a `char` takes once encoded.
codepoint_byte_len :: fn(c: char) -> i64                        // 1..4, as `utf8_encode` writes it

// UTF-16 surrogates, as code units: no `char` holds one (JSON `\uXXXX`).
is_surrogate       :: fn(unit: u32) -> bool
is_high_surrogate  :: fn(unit: u32) -> bool
is_low_surrogate   :: fn(unit: u32) -> bool
combine_surrogates :: fn(hi: u32, lo: u32) -> char             // `hi` and `lo` checked by the caller

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
len      :: fn(self: MutableMap<K, V>) -> i64
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
len      :: fn(self: MutableSet<T>) -> i64
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
// Comparison + helpers — overloaded on `i32`, `i64`, and `f64`. A generic
// `Comparable`-driven variant (one fn body for any `T: Comparable`) is post-MVP: the
// body needs to default-init a slot of type `T` before threading it through
// `compare`, which is gated on `Default<T>` / a `zero<T>()` intrinsic.
min   :: fn(a: i32, b: i32) -> i32
min   :: fn(a: i64, b: i64) -> i64
min   :: fn(a: f64, b: f64) -> f64
max   :: fn(a: i32, b: i32) -> i32
max   :: fn(a: i64, b: i64) -> i64
max   :: fn(a: f64, b: f64) -> f64
abs   :: fn(x: i32) -> i32
abs   :: fn(x: f64) -> f64
clamp :: fn(x: i32, lo: i32, hi: i32) -> i32
clamp :: fn(x: i64, lo: i64, hi: i64) -> i64
clamp :: fn(x: f64, lo: f64, hi: f64) -> f64
lerp  :: fn(a: f64, b: f64, t: f64) -> f64        // a + (b - a) * clamp(t, 0.0, 1.0)

// libm, declared `@extern` with `@c_header("<math.h>")` — the emitted C calls
// it directly, and the VM resolves them through `ffi_symbol` like any other import.
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

The iterator trait lives in `std/core` (auto-imported). `next()` hands back a PAIR: the element, and whether the iteration goes on. The pair crosses the call in registers, and it keeps iterators over nullable elements unambiguous — `Continuation` says whether there is an element, so a yielded `null` is just an element:

```vader
Continuation :: enum(u8) { Continue, Stop }

Iterator :: trait<T> {
    next :: fn(self) -> [T, Continuation]
}
```

The element beside `Stop` is **meaningless** and no consumer may read it (`for x in it` never does). An implementation returns whatever `T` it has at hand — its cursor, a spare literal — rather than manufacturing one. An implementation with no `T` to offer at all (an empty `T[]`, an unconstrained `T`) is written as a generator instead, where the lowerer supplies the type's zero: that is what `std/core::array_iter` is.

An implementation provides `next` and nothing else: everything that consumes an iterator — `count`, `last`, `is_empty`, `collect`, … — is a free function of `std/iter` over `Iterator<T>`, called with the method syntax (`it.count()`).

**Advancing an iterator modifies it**: `next` changes its state, so a frozen iterator, a module constant's, cannot be advanced (T3072). An array reaching an `Iterator<T>` slot implicitly goes through the `into` toward that iterator (an impl on its own instance converting to that very type, else `T[] implements<T> Into<Iterator<T>>`), whose result is a fresh iterator.

`std/iter` provides **lazy combinators** on top of `Iterator<T>`. Each is a generator (it `yield`s) returning `Iterator<U>`: nothing is materialised until a terminal drains the stream, and chains **fuse** through their `Iterator<T>` slots down to a single loop with no intermediate arrays. There is one family — no eager `T[]`-returning overloads and no `.iter()` cursor.

```vader
map             :: fn<T, U>(self: Iterator<T>, f: fn(T) -> U)    -> Iterator<U>
filter          :: fn<T>(self: Iterator<T>, pred: fn(T) -> bool) -> Iterator<T>
take            :: fn<T>(self: Iterator<T>, n: i64)              -> Iterator<T>
skip            :: fn<T>(self: Iterator<T>, n: i64)              -> Iterator<T>
indexed         :: fn<T>(self: Iterator<T>)                      -> Iterator<[T, i64]>
flat_map        :: fn<T, U>(self: Iterator<T>, f: fn(T) -> U[])  -> Iterator<U>
chain           :: fn<T>(self: Iterator<T>, other: Iterator<T>) -> Iterator<T>
zip             :: fn<T, U>(self: T[], other: U[])                -> Iterator<[T, U]>
window          :: fn<T>(self: T[], size: i64)                   -> Iterator<T[]>
chunked         :: fn<T>(self: Iterator<T>, size: i64)           -> Iterator<T[]>
distinct        :: fn<T: Hash & Equals>(self: Iterator<T>)       -> Iterator<T>
filter_not_null :: fn<T>(self: Iterator<T | null>)               -> Iterator<T>
```

**Terminals** drain the stream to a concrete value — `collect` materialises an array, the rest fold or short-circuit:

```vader
collect  :: fn<T>(it: Iterator<T>) -> T[]                    // the way to get a T[] back
fold     :: fn<T, U>(it: Iterator<T>, init: U, f: fn(U, T) -> U) -> U
sum / count / last                                           // whole-stream reductions
is_empty / any_match / all_match / find / find_map           // stop on the first match
```

A terminal is an ordinary function: it consumes its `Iterator<T>` parameter with one `for`. Any function of that shape — a user's as much as std's — fuses with the chain it is handed, down to the same single loop.

The blanket `T[] implements<T> Into<Iterator<T>>` makes a raw array drop into any `Iterator<T>` slot, so the combinators resolve **directly on a bare array** — no cursor, no explicit wrap:

```vader
arr.map(f).filter(p).take(10).collect()     // arr : T[] ; `arr.map(f)` is lazy, `.collect()` yields the T[]
for x in arr.filter(p) { ... }              // a lazy chain also drives for-in directly
```

`arr.map(f)` returns a lazy `Iterator<U>`, never an array; call `.collect()` when you want the `T[]`. (`array_iter` is the generator the `into` coercion materialises at a *non-fused* `Iterator<T>` boundary — e.g. passing `arr` to a `fn(it: Iterator<T>)` parameter; you rarely name it directly.)

### Generators (`yield`)

> **Shipped.** The `yield` statement parses, formats, type-checks
> (`T3056`, `T3058`–`T3061`), and lowers to a resumable state machine. The entire
> `std/iter` combinator family (`map` / `filter` / `take` / `skip` / `indexed` /
> `flat_map` / `chain` / `zip` / …) is authored as generators on top of it. A fused
> chain inlines the generator body directly (no allocation, no boxed iterator); an
> escaping generator falls back to the state-machine struct.

A **generator function** is a function that `yield`s — there is **no decorator**.
Generator-ness is **inferred** from the presence of a `yield` in the body (mirror
of how an `await` makes a function an async coroutine), and expressed in the
signature by returning `Iterator<T>`. It produces its elements lazily, one at a
time, instead of building a whole collection up front — authoring sugar for an
`Iterator<T>` impl that everything downstream (`for`-in, the lazy combinators,
`.collect()`) consumes unchanged.

```vader
concat_file_decls :: fn(files: SourceFile[]) -> Iterator<Decl> {
    for f in files {
        for d in f.program.decls { yield d }     // flatten = a nested `for`
    }
}

// consumed lazily — no intermediate array is built
for d in concat_file_decls(files) { process(d) }
```

Rules:

- A `yield` in the body **makes the function a generator** (inferred, no
  annotation). The declared return type **must** then be `Iterator<T>` for some
  `T` — `T` is the yielded element type (`T3056` otherwise).
- A function with **no** `yield` is not a generator, even if it returns
  `Iterator<T>` — it is an ordinary factory returning an iterator value
  (a bare array, `arr.into()`, a wrapping combinator). The empty-iterator case is an empty
  array `[]`, which coerces to `Iterator<T>`.
- `yield e` is a **statement**, legal only directly inside a generator's own body,
  never in a nested lambda or a `defer` body (`T3059`). `e` must coerce to `T`
  (same path as `return`, `T3061` on mismatch).
- `return <value>` inside a generator is an **error** (`T3058`) — a generator
  produces via `yield`. A bare `return`, or falling off the end, means
  **exhausted**: every subsequent `next()` hands back `Continuation.Stop`,
  paired with an element that is INDETERMINATE and must not be read.
- `break` / `continue` keep their normal loop meaning across `yield` suspension
  points.
- The generator's result is a **first-class `Iterator<T>` value**: it can be
  stored, passed, returned, and fed to any combinator.

There is no `yield from` / `yield*`: the flatten case is a nested `for`, already
the language's flatten idiom.

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

processor_count :: fn() -> i32                      // logical processors online, at least 1

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

### `json`

Recursive-descent JSON parse + stringify, pure Vader. Numbers are stored as `f64` (loses precision past 2^53 — fine for compiler use cases).

```vader
JsonValue :: JsonString | JsonNumber | JsonBool | JsonNull | JsonArray | JsonObject
JsonString :: struct { value: string }
JsonNumber :: struct { value: f64 }
JsonBool   :: struct { value: bool }
JsonNull   :: struct {}
JsonArray  :: struct { items: JsonValue[] }
JsonObject :: struct { entries: MutableMap<string, JsonValue> }

JsonError  :: struct { msg: string, pos: i64 }   // implements Error

parse            :: fn(input: string)                -> JsonValue | JsonError
stringify        :: fn(v: JsonValue)                  -> string
stringify_pretty :: fn(v: JsonValue, indent: i32)     -> string
```

`parse` returns `JsonValue | JsonError` explicitly.

### Out of MVP

- networking (no HTTP / sockets in stdlib)
- compile-time-generated JSON parsers (runtime parser ships today via `json`)
- threads / async
- compression

### Landed in stdlib (beyond the core MVP set)

These ship today alongside the core MVP set. `std/` holds the language's own
vocabulary; the rest are libraries with namespaces of their own, all under the
same `lib/` root and all shipped in a bundle — the prefix says which is which, it
does not say which is present.

Under `std/`:

- `std/abort` — `panic` / `todo` / `unreachable` (the diverging-fn primitives; prelude-level).
- `std/path` — POSIX path manipulation (`Path.join`, `Path.parent`, `Path.normalize`).
- `std/process` — process spawning / argv.
- `std/sort` — stable mergesort.
- `std/testing` — `assert` / `assert_eq` consumed by `@test` functions.
- `std/time` — clock / formatting.

Namespaces of their own — `import "json"`, not `import "std/json"`:

- `base64` — encode / decode.
- `cli` — declarative flag parsing (`FlagSpec`, `parse_known`).
- `crypto` — basic hashing primitives.
- `images/ppm` — PPM (P6) encode / decode.
- `json` — runtime parser + emitter.
- `random` — PRNG.
- `regex` — minimal regex engine.
- `semver` — `Version` / `VersionRange` parsing and comparison.

Listed here because they're in-tree but not part of the frozen v1.0 surface in §15.

---

## 16. Concurrency (post-MVP)

### MVP

**No concurrency.** Synchronous blocking I/O. Single-threaded program.

### Post-MVP — async/await (in progress)

Single-threaded cooperative async, lowered to a coroutine state machine at compile time (Model A self-drive, sharing the generator block-split engine). Portable across the four targets.

- A function is an **async coroutine** when it uses `await`; it declares its return type as `Async<T>`. `await e` unwraps an `Async<T>` to `T`, and a call to a coroutine is typed as `Async<T>`.
- The coroutine's body returns the inner `T` (the frame wraps it), mirroring how a generator's `-> Iterator<E>` body yields `E`. A coroutine that completes with no value returns `Async<void>`.
- A function may also *return* an `Async<T>` value it constructs — a factory such as a future `sleep(ms) -> Async<void>` — without awaiting; that is an ordinary function.
- `await` must appear directly in a coroutine body, not inside a nested lambda or a `defer` body (T3064): a deferred block runs at scope exit and cannot suspend.
- **Evaluation order.** Operands evaluate left to right, as in synchronous code, even when a later one awaits: in `f(a(), await b())`, `a()` runs before `b()`. An assignment evaluates its target's operands (receiver, index) before its value. A compound assignment `place op= e` then evaluates `e`, and reads `place` only at the write, so nothing suspends between the read and the write.
- `defer` is allowed inside an async coroutine: pending defers live in the frame and run LIFO when the coroutine completes **or when it is cancelled** (see below), including defers registered before an `await` — the thunk, and any local it captures, survive the suspension. `defer` inside a generator is still rejected (T3060), pending the teardown hook for abandoned generators.
- Errors are values: `await` on a fallible `fn -> Async<T | E>` yields `T | E`, narrowed at `if`/`match`.
- **Entry & scheduler.** An async `main` runs on a cooperative single-threaded scheduler (strict-FIFO ready queue + timer min-heap), entered implicitly once the program imports `std/async`. `sleep(ms)` suspends the current coroutine until a virtual-clock deadline.
- **Wake times.** A hand-written awaitable's `resume` returns `Suspended { .wake_at = t }` when it cannot progress before the scheduler clock reaches `t` (ms, as `sched_now` reads it); `Suspended {}` (`wake_at = 0`) means unknown. A coroutine reports the `wake_at` of the child it is parked on, and the combinators (`join_all`, `race`, `join_any`) resume a child only once its `wake_at` has passed — so a parked child costs nothing while the others wake. An awaitable that reports a `wake_at` later than it can actually progress is not resumed in time.
- **Concurrency combinators** (`std/async`): `join_all(xs)` joins every awaitable (results in input order); `try_join_all<U, E>(xs)` is the fallible join, surfacing the first error by input order; `race(xs)` completes with the first to settle (value or error); `join_any<U, E>(xs)` completes with the first success — a settled error is not a win — or the last error if all fail; `timeout(ms, x)` bounds `x`, yielding a `TimeoutError` value if the deadline elapses first. The `<U, E>` combinators need explicit type args (the `U | E` split can't be inferred).
- **Cancellation.** `race` / `join_any` / `timeout` cancel their losing awaitables so no orphaned work is left behind: a cancelled coroutine runs its pending defers (LIFO) and recursively tears down the child it is parked on, without finishing its body. Cancellation is cooperative (only a suspended coroutine can be cancelled) and internal — there is no user-facing `cancel` in v1. Open structured concurrency (`scope` / `spawn`) remains deferred.

### Later — coroutines

Continuation-passing coroutines envisioned, to provide better ergonomics than plain `async`/`await`.

### Native threads

Possibly post-MVP, in `std/thread`, **not available on the WASM target** (compile-time assertion if imported on WASM).

---

## 17. Compilation Targets

### Target selection — `@target`

A build is parameterised by a target: an operating system and an architecture,
written `<os>-<arch>` (`--target=darwin-arm64`), defaulting to the machine the
compiler runs on. The two axes do **not** play the same role, and the asymmetry is
the design rather than an accident:

- **`os` selects code.** It is the only axis `@target` filters on.
- **`arch` selects nothing.** It parameterises values — pointer width —
  and never includes or excludes a declaration. Hence no `@architecture`: its
  absence is a consequence, not a gap.

`Os` is `Windows | Linux | Darwin | Wasi | Browser`; `Arch` is `X86_64 | Arm64 |
Wasm32`. `wasm` is not an OS — it is an architecture, and the two systems running
on it are far enough apart (`Wasi` has a POSIX-shaped filesystem, `Browser` has
none) that one value would hide the difference that matters.

#### One declaration, several bodies

```vader
// path.vader — the declaration. Carries the signature, the export, the doc.
import "std/string"

/// True iff the path is absolute.
@target
export is_absolute :: fn(p: string) -> bool = p.starts_with("/")

// path-windows.vader — a body. Same module; the file name means nothing.
@target(.Windows)
is_absolute :: fn(p: string) -> bool { /* drive letter, UNC */ }
```

A build keeps **one** body per declaration: the one whose list contains the
target's OS, or else the general body the declaration itself carries. A body may
come from the linker instead of Vader — `@target(.Windows) @extern("CreateFileW")`
is a body too, which is why the presence of a `{ … }` is not what distinguishes a
declaration from a body. **Bare versus list is.**

Selection happens between parsing and name resolution. A body whose target does
not match is therefore **never resolved and never type-checked** — not merely
dropped from the output. This is what keeps a library's Windows bug from breaking
a Linux build, and it is why `vader check --target=` exists: on any one machine,
every other platform's code is unchecked until something asks for it.

#### Rules

| | |
|---|---|
| `R2035` | an argument that names no OS (`.Drawin`) — compared syntactically, since selection precedes name resolution |
| `R2036` | a body whose name matches no bare declaration. The typo case |
| `R2037` | a body carrying `export`, or a decorator other than `@extern` and `@intrinsic` (which say who provides the body). The declaration owns the visibility and the rest of the envelope |
| `R2038` | two bodies covering the same platform — the winner would depend on declaration order |
| `R2039` | a second bare declaration for a name that already has one — including two OVERLOADS, since a group is keyed by name alone |
| `R2040` | a body whose signature differs from the declaration's. The body binds by POSITION, so reordered parameter names silently compute something else |
| `R2041` | no body covers the target being built, and the declaration carries no general body |
| `P1014` | `@target` anywhere but a top-level fn, a struct, a trait, an enum or a constant |

R2035 to R2040 are checked **before** selection, so they fire for every target
rather than only the one being built: a malformed group is an error on the
machine that wrote it, not a surprise on whichever platform compiles it next.
R2041 is the exception, and necessarily so — "nothing covers this" is a question
only a target can answer.

Only the declaration's signature is kept: `graft_body` takes the params, the
return type and the type params from it, because the declaration is what carries
the contract. R2040 exists because that makes a divergent body *silently* wrong.
It compares arity and parameter names, not types — a body written against
different types fails to type-check against the declaration's anyway, with a
better message than this pass could give.

#### `VADER_OS` — the target as a value

`VADER_OS` and `VADER_ARCH` are constants of the compilation target, seeded into
the prelude and foldable at comptime. Their *types* are not: naming a variant
means importing `std/target`, since `.Windows` alone does not infer from a
comparison (`T3028` — an operand is not an inference site).

```vader
import "std/target"

SEP :: if VADER_OS == Os.Windows { '\\' } else { '/' }
```

They answer *what this build is for*. `std/target::current_os()` answers the other
question — *what the program is running on* — and the two differ whenever a build
is cross-compiled, whenever code runs in the VM, and in the C seed, which is
emitted on one machine and compiled on another. Code that manipulates its own
environment wants the second.

The rule of thumb: **`VADER_OS` chooses a value, `@target` chooses code.** A
separator or a limit is a value; twenty lines of platform API is code.

#### Tests are never targeted

`@test` sits on the *declaration*, which is the bare `@target` one, so a test is
never itself selected away — and `@target(.Windows) @test` is `R2036`, since a
body has no declaration of its own to carry the decorator. That is the model
being consistent, not a gap: a test names a behaviour, and the behaviour is the
same everywhere even when the code implementing it is not. What varies is the
*expectation*, and an expectation is a value:

```vader
import "std/target"

@test
test_separator_matches_the_platform :: fn() -> void {
    want :: if VADER_OS == Os.Windows { '\\' } else { '/' }
    assert_eq(SEP, want)
}
```

The same test then runs on every target and checks the body that target selected,
which is more coverage than a per-platform test would give, not less.

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

- `--emit=bytecode` → `.vir` — **binary** module, compact, what `vader run program.vir` consumes.
- `--emit=bytecode-text` → `.virt` — **textual**, line-oriented, human-readable; `vader run program.virt` re-parses it back into the in-memory bytecode without touching the original source.

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

Every invocation is `vader <action> [options] [args]`. **An action's options come
before its first positional argument**; everything after that argument belongs to
whatever the action passes it to — for `run`, the executed program's argv,
verbatim and with no `--` needed. A bare `--` closes the option zone explicitly,
which is how a path beginning with a dash is named. Anything an action doesn't
recognise is an error, in both `--long` and `-s` forms.

Short aliases: `-o` (`--out`), `-t` (`--target`), `-r` (`--release`), `-s`
(`--stage`), `-h` (`--help`), `-v` (`--version`). A flag taking a value accepts
it after `=` or after a space, in either spelling.

Actions, their flags and the accepted values of each enumerated flag are declared
once in `vader/cli/spec.vader`; `vader <action> --help` (equivalently `-h`, or
`vader help <action>`) renders from that same table, so the help cannot drift
from what the parser accepts. A `--help` written past a `run` path is forwarded
to the program like any other argument.

| Command | Description |
|---------|-------------|
| `vader run <file> [args…]` | Interpret via VM; everything after `<file>` is the program's argv. A bare `vader` (no action) is where the REPL will live *(not yet implemented)* |
| `vader build [file\|--manifest]` | Compile to binary (default target = native) |
| `vader build --emit=executable` | C-emit → `cc` → native binary (default) |
| `vader build --target=wasm32-browser` | Targets WebAssembly *(not yet implemented)* — the artefact stays `--emit=executable`; wasm is a platform, not an artefact kind |
| `vader build --emit=bytecode` | Emits a binary `.vir` bytecode module *(not yet implemented)* |
| `vader build --emit=c` | Emits the generated C source only |
| `vader fmt [path]` | Single opinionated formatter, **no config**; defaults to recursive walk under `.` |
| `vader test [path]` | Runs all functions marked `@test`, each in an isolated process. |
| `vader lsp` | Runs the Language Server (JSON-RPC over stdin/stdout). Spawned by VS Code / IntelliJ |
| `vader dump --stage=<stage> <file>` | Dumps an IR stage (text, JSON or Markdown depending on stage) |
| `vader help [action]` | Usage overview, or one action's options in full |
| `vader init [name]` *(post-MVP)* | Scaffolds a new Vader project: directory, `examples/hello.vader`, default `vader.json` |

`vader dump` stages, in pipeline order (`ast` produces JSON, `evaluated-ast` Markdown, the others text):

| Stage | Output |
|-------|--------|
| `lexer` | Token stream + diagnostics (text) |
| `ast` | Parser AST, spans elided |
| `resolved-ast` | Per-module symbol table + import wiring (text — byte-aligned with `vader/resolver/dump.vader`) |
| `typed-ast` | Per-decl + per-expression types |
| `evaluated-ast` | `@comptime` values, `@file` reads and `@assert` verdicts, in Markdown |
| `lowered-ast` | Desugared program printed as Vader under qualified names, with where each constant and global slot lives, the vtable rows, and what the lowering materialised in the dependencies |
| `dced-ast` | Lowered tree post-stdlib reachability prune |
| `cfg` | Mid-IR CFG (post-DCE + escape-annotated) |
| `ranges` | Range analysis over the CFG the bytecode emitter receives: a verdict per array access and checked operation |
| `bytecode` | Stack-machine ops + type/string/import tables |
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

A registry of codes lives in `vader/diagnostics/codes.vader` — the single source of truth for IDs, wording, and enum order.

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

Once the original TypeScript compiler could compile a syntactic subset (fns, ifs, loops, structs, arrays, strings, imports, traits), the port proceeded piece by piece. The intent: **validate the language design early** by using it to write itself.

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
10. **Mid-IR (CFG / DCE / escape / scheduler)** ✅ (`vader/midir/`).
11. **Bytecode-emit** ✅ (`vader/bytecode/`).
12. **C-emit** ✅ (`vader/c_emit/`).
13. **WASM-emit** ⏳ (post-MVP — binary encoding, Phase 3).

Legend: ✅ ported, ⏳ not yet (post-MVP).

The full native pipeline is self-hosted. The only stage not yet ported is the WASM
emitter, which is post-MVP.

### Bootstrap status — achieved

The fixed point has been reached: the Vader-built compiler reproduces its own
generated C **byte-for-byte** (`stage1.c == stage2.c`), and a committed C seed
(`bootstrap/seed/`) lets any machine with a C
compiler rebuild the entire toolchain from source with no Bun or TypeScript in
the cold-start path — see [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md). CI rebuilds
from the seed on every push.

The TypeScript compiler under `src/` has been removed (TODO §2.8); the native
Vader CLI is the only compiler. Snapshot tests run that CLI as the oracle for
every stage, and the bootstrap fixed-point check (`bootstrap/verify.sh`) guards
self-host correctness against the committed seed.

---

## 20. Examples

### Hello World

```vader
import "std/io"

main :: fn() -> i32 {
    println("Hello, World!")
    return 0
}
```

### Fibonacci

```vader
import "std/io"

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
import "std/io"

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
import "std/io"

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
    raw := read_file(path)             // read_file → string | Error
    if raw is Error { return raw }
    n := parse_int(trim(raw))          // parse_int → i32 | ParseError; ParseError widens to Error
    if n is Error { return n }
    return n
}

main :: fn() -> i32 {
    match result :: read_count("count.txt") {
        is i32   -> println("Count: ${result}")
        is Error -> println("Error: ${result.message()}")
    }
    return 0
}
```

### `@comptime`

```vader
import "std/io"

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
6. **Lowerer**: pattern match → if/else chains, traits → static dispatch chain (`is StructA -> StructA_method(...)`)
7. **Mid-IR (CFG)**: LoweredAST → CFG converter; substrate for escape analysis, loop-carried-dependency check, dead-store elimination
8. **Bytecode emitter**: from CFG (not directly from lowered AST)
9. **VM**: bytecode interpretation (mode `vader run` + comptime)
10. **IR text emitter**: serialize the bytecode into a human-readable `.virt` file with source-position annotations
11. **IR text reader**: parse `.virt` back into in-memory bytecode for `vader run program.virt`
12. **C emitter**: from bytecode
13. **WASM emitter**: from bytecode
14. **Stdlib in Vader**: core, io, string, collections, math, builder, iter
15. **C runtime**: Cheney semi-space copying GC (stop-the-world, shadow-stack roots), string helpers, basic syscalls
16. **CLI**: `run`, `build` (with `--emit=bytecode|native|wasm`), `fmt`, `test`, `dump`, REPL
17. **Snapshot tests**: for each sample, snapshot the output of every stage

### B. Deferred decisions / topics to revisit

- `unsafe` for low-level FFI (native need)
- Explicit allocator API (arena, etc.) for perf-critical zones
- Auto string marshalling WASM ↔ JS
- Async / await
- Continuation-passing coroutines
- Native threads (`std/thread`)
- Networking, regex, time, random
- External packages
- Pure WASM compilation without WASI
- Full array slicing
- `vader init [name]`: project scaffolder (creates the dir, an `examples/hello.vader`, and a default `vader.json`)

Already landed (cross-reference for B's reader):
- Programmable build API (`build.vader` — §11 *Programmable build API*, `toolchain/build`)
- `json` (in MVP — §15 `json`)
- LSP (`vader/lsp/`, partial — server + completion / hover / definition / semantic tokens)
- Resolver self-host (`vader/resolver/` — 9 modules)
- Reflection intrinsics `@type_of`, `@fields`, `@type_args`, `@field`, `@comptime for` loop unrolling
- FFI VM host registry (`@extern` user imports now run on the VM via a host-side handler table)
- Lazy iterator combinators (`map` / `filter` / `take` / `skip` / `indexed` / `flat_map` / `chain` / `zip` — all generators in `std/iter`)
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
