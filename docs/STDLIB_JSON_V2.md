# `std/json` v2 — comptime-specialised encoder/decoder (`jason`)

> **Status**: prospective. Plans a v2 of the JSON layer that reuses the v1
> tree parser + StringBuilder, and adds a thin generic wrapper —
> `jason.encode[T]` / `jason.decode[T]` — implemented as `@comptime` functions
> whose bodies are auto-specialised per type via `@fields(T)`. No
> `@derive(Json)` decorator, no compiler-side synthesis, no quasi-quotation.
> The implementation is ~300 LoC of pure Vader living in
> `stdlib/std/json/jason.vader`.
>
> The name `jason` is a play on JSON + the `a` of vAder.
>
> **Cross-refs**: TODO §3.4 (`std/json v2`), TODO §3.8 (`@derive`
> machinery — explicitly *not* needed for v2.0), TODO line 418
> (`@comptime fn` deferred); `docs/DESIGN_TYPE_FIRST.md` §12 Layer 6
> sketches the same `@comptime for f in @fields(T)` pattern as the
> canonical motivating example for type-first comptime — read
> alongside ; `docs/STDLIB_GENERIC_COLLAPSE.md` proposes a generic
> erasure pass whose interaction with this plan matters (see §9).

---

## 0. Why this document exists

`std/json` v1 (`stdlib/std/json.vader`, ~625 LoC) is a tree parser : text
→ `JsonValue` union, then the user pulls fields out by hand:

```vader
parsed :: json.parse(text)
match parsed {
    is JsonObject -> {
        name_field :: parsed.get("name")
        match name_field {
            is JsonString -> { name := name_field.value }
            is _          -> { return JsonError { .msg = "type mismatch", .pos = 0_usize } }
        }
        // ... repeat per field ...
    }
}
```

It works, but every consumer reimplements the same per-field plumbing.
v2 collapses this into one line :

```vader
user :: jason.decode[User](text)    // User | JsonError
```

and the per-field walk is generated **once per (T)** by the comptime
unroller, not handwritten.

The TODO §3.4 entry mentions "kotlinx-serialization style via `@derive(Json)`".
After investigating the current compiler state, that exact shape is not
feasible today — see §5. The plan below delivers the same user-facing
ergonomics with a much smaller set of language requirements.

---

## 1. The chosen approach

Two generic functions per side, both pure Vader. Each carries the existing
`@comptime` decorator at the declaration level — meaning the function's
body is auto-specialised per type parameter. Inside the body, ordinary
`if` / `for` / `match` statements whose conditions or iterables depend
solely on comptime-known values are resolved at lower time; the rest stays
runtime. No body-level `@comptime` decorators are needed.

### 1.1 Encoder

```vader
// stdlib/std/json/jason.vader

import "std/json"                  // v1 — reuse JsonError, JsonValue
import "std/string_builder"

export encode :: fn[T](value: T) -> string {
    builder := string_builder.new()
    encode_into(value, builder)
    return builder.to_string()
}

@comptime
encode_into :: fn[T](value: T, builder: StringBuilder) -> void {
    if @is_struct(T) {
        builder.append("{")
        for [field, position] in @fields(T).enumerate() {        // unrolled — @fields(T) is comptime
            if position > 0 {
                builder.append(",")
            }
            builder.append("\"" + field.name + "\":")
            encode_into(value.@field(field.name), builder)
        }
        builder.append("}")
    } else if @is_array(T) {
        builder.append("[")
        for [item, position] in value.enumerate() {              // runtime loop — value is runtime
            if position > 0 { builder.append(",") }
            encode_into(item, builder)
        }
        builder.append("]")
    } else if T == string {
        builder.append("\"")
        json.write_string(value, builder)
        builder.append("\"")
    } else if @is_integer(T) {
        builder.append(value.to_string())
    } else if @is_boolean(T) {
        builder.append(if value { "true" } else { "false" })
    } else if @is_union_with_null(T) {
        match value {
            is null -> { builder.append("null") }
            is _    -> { encode_into(value, builder) }
        }
    } else {
        @compile_error("jason.encode: type " + @type_name(T) + " is not encodable")
    }
}
```

Note the two `for` loops in the body: the one over `@fields(T)` is
unrolled because its iterable is comptime-known; the one over `value`
stays runtime because `value` is a runtime array. The compiler decides
per statement, based on dependencies — no body-level annotation is
necessary.

For a concrete call `jason.encode(some_user)` where
`User :: struct { name: string, age: i32 }`, the specialisation produces
exactly :

```vader
// post-comptime expansion, conceptually
encode_into__User :: fn(value: User, builder: StringBuilder) -> void {
    builder.append("{")
    builder.append("\"")
    builder.append("name")
    builder.append("\":")
    builder.append("\"")
    json.write_string(value.name, builder)
    builder.append("\"")
    builder.append(",")
    builder.append("\"")
    builder.append("age")
    builder.append("\":")
    builder.append(value.age.to_string())
    builder.append("}")
}
```

Direct, inlinable code. No introspection at runtime.

### 1.2 Decoder

The decoder reuses v1's tree parser, then walks the parsed `JsonValue`
with the same `@comptime` declaration + `for field in @fields(T)` pattern :

```vader
export decode :: fn[T](text: string) -> T | JsonError {
    parsed := json.parse(text)
    match parsed {
        is JsonError -> { return parsed }
        is _         -> { return decode_from(parsed) }
    }
}

@comptime
decode_from :: fn[T](value: JsonValue) -> T | JsonError {
    if @is_struct(T) {
        match value {
            is JsonObject -> { /* fall through */ }
            is _          -> { return JsonError { .msg = "type mismatch", .pos = 0_usize } }
        }
        for field in @fields(T) {                               // unrolled per field
            // declare a slot per field, accumulate values
            ${field.name}_slot : @field_type(T, field.name) | null = null
        }
        for entry in value.entries {                            // runtime loop over parsed entries
            match entry.key {
                for field in @fields(T) {                       // unrolled into match arms
                    is field.name -> {
                        ${field.name}_slot = decode_from(entry.value)
                    }
                }
                is _ -> { /* unknown field — ignore in v2.0 */ }
            }
        }
        for field in @fields(T) {                               // unrolled validation
            if ${field.name}_slot == null {
                return JsonError { .msg = "missing field: " + field.name, .pos = 0_usize }
            }
        }
        // Struct construction from per-field accumulators. The natural form
        // (`T { for field in @fields(T) { .${field.name} = ... } }`) is not
        // a Vader syntactic form; v2 needs a new intrinsic — see §2.7.
        return @construct(T, @each(@fields(T), ${field.name}_slot))
    } else if T == string {
        match value {
            is JsonString -> { return value.value }
            is _          -> { return JsonError { .msg = "type mismatch", .pos = 0_usize } }
        }
    } else if @is_integer(T) {
        match value {
            is JsonNumber -> { return T(value.value) }
            is _          -> { return JsonError { .msg = "type mismatch", .pos = 0_usize } }
        }
    }
    // ... arrays, booleans, optionals, similar shape
}
```

Same model : per-T specialisation produced by the compiler from the
call site. Each user struct generates its own decoder body, fully
inlinable. The body reads as plain Vader — the only thing signalling
meta-level behaviour is `@comptime` on the declaration.

### 1.3 User-facing API

```vader
import "std/json"/jason

User :: struct {
    name : string
    age  : i32
    bio  : string | null
}

alice :: User { .name = "Alice", .age = 30, .bio = null }
text  :: jason.encode(alice)                  // → {"name":"Alice","age":30,"bio":null}
back  :: jason.decode[User](text)             // back : User | JsonError
```

No decorator. No `@derive`. Just two generic calls.

---

## 2. Required language primitives

Most of the work is **exposing what comptime can already do internally**.
Nothing here is a deep language change.

### 2.1 Extend `@comptime` to function declarations — new subsystem

Today `@comptime` is **const-only by construction**, not just by
convention: `src/comptime/deps.ts` keys its dep graph on `Map<ConstDecl, …>`,
`src/comptime/evaluate.ts` stores results in `Map<ConstDecl, ComptimeValue>`,
and `src/comptime/lower-decl.ts:CompileInput.decl` is typed `A.ConstDecl`.
A `@comptime` on a `FnDecl` parses fine but is silently ignored.
TODO.md line 418 explicitly defers "Turing-complete `@comptime fn` bodies".

Extending `@comptime` to function declarations is therefore **a new
subsystem**, not an extension of an existing decorator. The work :

- A "comptime fn template" record (distinct from a baked comptime value)
  threaded through `EvaluatedProject`, `EvaluateOptions`, `CompileInput`,
  `runComptimeDecl`, `deps.ts`.
- Per-call-site specialisation cache keyed on `(template, typeArgs)`.
- Dependency-tracked statement elimination — every `if` / `for` / `match`
  in the body needs comptime-known analysis on its scrutinee, with
  conservative defaults that keep the rest runtime.
- Diagnostics when a branch the user expected to be eliminated turns out
  to depend on a runtime value ("this `if` lives in a `@comptime`
  function but its condition references runtime value `x`; either move
  it outside, or make `x` comptime-known").
- Cycle detection on recursive specialisation across types.

Specialisation rules (target semantics) :

- A generic param `T` is comptime-known inside a `@comptime` function.
- A local binding is comptime-known iff its initialiser is comptime-known
  (transitive).
- An `if` branch is eliminated at lower time iff its condition is
  comptime-known and constant-resolvable.
- A `for x in iter` is unrolled iff `iter` is comptime-known
  (e.g. `@fields(T)`); otherwise it stays a runtime loop.
- A `match` arm is selected at lower time iff the scrutinee and pattern
  are comptime-known.
- A `@comptime` function calling another `@comptime` function with a
  comptime-known argument triggers specialisation of the callee.
- A `@comptime` function called from a non-`@comptime` site with a
  runtime-only T is a typecheck error.

**Estimated cost**: ~2–3 weeks. The dep-tracking analysis through every
statement form is the largest piece. Aligning the new template path with
existing `@comptime` const evaluation (so they share validators,
diagnostics, and the bytecode-comptime path TODO.md line 461 plans) is
the second largest.

### 2.2 Comptime type predicates — new but trivial

A handful of `@is_*` intrinsics returning `bool` at comptime :

- `@is_struct(T)`, `@is_enum(T)`, `@is_union(T)`, `@is_array(T)`
- `@is_integer(T)`, `@is_float(T)`, `@is_boolean(T)`
- `@is_union_with_null(T)` (or compose `@union_members(T).contains(null)`)
- `@type_name(T) -> string` for diagnostics

These read from the existing `Type` IR at comptime. Each is ~5 LoC of
compiler plumbing.

**Estimated cost**: ~1 day total.

### 2.3 `@field(value, name)` — field access by comptime name

Inside a `@comptime for field in @fields(T)` loop, the body needs to read
`value.<field.name>`. Today, dotted access requires a literal field name
at parse time. The primitive `value.@field(name)` accepts a comptime
string and lowers to a normal field access after unrolling.

**Estimated cost**: ~1–2 days. The hardest part is teaching the resolver
that `value.@field("name")` after unrolling is equivalent to `value.name`.

### 2.4 `@field_type(T, name)` — field type lookup

Symmetric primitive used in the decoder to declare slot types :
`${field.name}_slot : @field_type(T, field.name) | null = null`. Returns
the type of the named field as a comptime `type` value.

**Estimated cost**: ~0.5 day. Already implied by `@fields(T)` returning
typed entries.

### 2.5 Comptime string interpolation in identifier position

`${field.name}_slot` builds a local binding name from a comptime string.
This is the most exotic primitive — and the most replaceable. Two
alternatives if it's hard :

- Use an `array[N]` indexed by `@comptime field_position` instead of
  per-field bindings. Slightly uglier but pure plain-Vader.
- Use a `MutableMap` keyed by `field.name`. Heavier at runtime.

**Decision**: try with `${...}` interpolation first ; fall back to the
indexed-array trick if the interpolation primitive proves expensive.

**Estimated cost**: ~2 days for the interpolation primitive, OR 0 if we
use the fallback.

### 2.6 `@compile_error(message)` — comptime assertion

Used in the `else` branch of the encoder/decoder to fail at typecheck
when T is unsupported. Probably already exists or trivially related to
`@assert` (TODO §3.8 line 750).

**Estimated cost**: ~0.5 day if not present.

### 2.7 `@construct(T, slots)` — struct construction from accumulators

The decoder builds `T` from per-field slots. The natural form
`T { for field in @fields(T) { .${field.name} = ${field.name}_slot } }`
is not a Vader syntactic form — a `for` inside a struct literal does
not parse today.

Two paths :

- **(a) New intrinsic** `@construct(T, slots)` that accepts a
  comptime-known list of `(name, value)` pairs and produces a `T`
  literal at lower time.
- **(b) Pre-built accumulator struct** generated alongside the decoder,
  with a `finish()` method that constructs the target.

(a) keeps the call site readable ; (b) avoids one new primitive at the
cost of a generated wrapper type per derived T. v2.0 plans (a) ; fall
back to (b) if it proves expensive.

**Estimated cost**: ~2–3 days for (a).

---

## 3. Where the `@json(...)` decorator went

In an earlier sketch I introduced `@json(name = "user_id", skip_if_null)`
for per-field customisation. **v2.0 deliberately drops this** because :

- Decorators today are a bag-of-attributes with no schema (the parser
  hardcodes 7 known names).
- `@fields(T)` does not expose decorators on fields.
- Adding both is significant language work that does not block v2.0.

v2.0 uses field names verbatim. Renaming, aliases, optional-skip
behaviour are deferred to v2.1.

**v2.1 prerequisite**: extend `@fields(T)` to expose `decorators: Decorator[]`
per field, and allow `@json(...)` as a known decorator with a typed
schema. Plan separately when v2.0 has landed and the demand exists.

---

## 4. Reuse vs. rewrite of v1

| v1 component | v2 reuse |
|---|---|
| `json.parse(text) -> JsonValue` | reused as-is for the decoder front end |
| `JsonValue`, `JsonObject`, etc. | reused — `decode_from` walks these |
| `json.write_string(s, builder)` | reused for the encoder |
| `json.stringify(v)` | unchanged ; encoders for `JsonValue` still useful for dynamic cases |
| `StringBuilder` (std/string_builder) | reused by encoder |
| Streaming parser | **not added** — v2.0 parses to tree then walks it |

v2 does **one extra allocation** vs. a hypothetical streaming derive
(the intermediate `JsonValue` tree). Acceptable for v2.0 ; a streaming
variant can land later as `jason.decode_streaming[T]` if profiling
demands it.

---

## 5. Why not `@derive(Json)` like kotlinx ?

I considered the kotlinx-serialization shape — a `@derive(Json)`
decorator that triggers comptime synthesis of `to_json` / `from_json`
methods on the type. It is not feasible today because :

- Comptime in Vader can **compute values** and **unroll loops** but
  cannot **emit declarations**. There is no quasi-quotation
  (`quote { fn ... { ... } }`) and no AST-builder API.
- The decorator system has no user-defined decorators ; `@derive` would
  need either compiler hardcoding (per format) or a `@derive_handler`
  intrinsic mechanism.
- Field-level metadata (`@SerialName`, etc.) requires decorator-on-field
  exposure that does not exist.

The plan above sidesteps all three constraints by generating the per-T
code **at the call site**, inline, via `@comptime for`. The user still
writes `jason.decode[T]` — they just call a generic function instead of
calling a derived method. Same ergonomics, far smaller compiler surface.

If `@derive` machinery lands later for other reasons (e.g. `@derive(Eq)`,
`@derive(Display)`), `jason` can opt to provide a `@derive(Json)` shim
that calls into `jason.encode` / `jason.decode`. Strictly additive.

---

## 6. Migration plan

### Phase 1 — `@comptime` fn subsystem (~2–3 weeks)

Build the comptime-fn template path described in §2.1. Touches
`src/comptime/deps.ts`, `evaluate.ts`, `lower-decl.ts` and every
consumer that today assumes `Map<ConstDecl, …>`. Add per-call-site
specialisation cache, dependency-tracked statement elimination,
recursive-specialisation cycle detection.

**Exit criterion**: a hand-written `@comptime fn f[T](x: T) { if @is_struct(T) {...} }`
specialises correctly per concrete T, with the runtime branch
preserved when the condition is runtime.

### Phase 2 — Intrinsics (~3–4 days)

Add the comptime predicates `@is_struct`, `@is_integer`, `@is_array`,
`@is_boolean`, `@is_float`, `@is_union_with_null`, `@type_name`,
`@compile_error`. Add field-access intrinsics `@field(value, name)` and
`@field_type(T, name)`. Add `@construct(T, slots)` (§2.7) if path (a)
is chosen.

**Exit criterion**: each intrinsic has a snippet test under `tests/snippets/`.

### Phase 3 — Identifier interpolation `${...}` or fallback (~2 days)

Pick path : implement `${...}` in identifier position OR commit to the
indexed-array fallback. If the array fallback is chosen, all subsequent
phases use it.

**Exit criterion**: per-field local accumulator pattern works in a
snippet test.

### Phase 4 — `jason.encode` end-to-end (~2 days)

Write `stdlib/std/json/jason.vader` with the encoder. Test against
existing JSON conformance fixtures.

### Phase 5 — `jason.decode` end-to-end (~3 days)

Add the decoder using the chosen Phase 3 path + `@construct`. Validate
error paths : missing fields, type mismatches, malformed input from v1's
parser.

### Phase 6 — Bench vs. hand-rolled v1 usage (~1 day)

Pick a representative struct, write the v1-style hand parser side by
side, benchmark encode + decode. Target : within 10 % of hand-rolled on
encode (both build a string), within 20 % on decode (v2 pays the
v1-tree-walk cost on top of the per-field walk).

### Phase 7 — Doc and stdlib polish (~0.5 day)

Add usage examples to `stdlib/std/json/jason.vader` header. Mark v1's
`json.parse` + `json.stringify` as still primary entry points for
dynamic cases ; `jason` is the typed path.

---

## 7. Pros and cons

### Pros

- **Bounded new language surface.** One existing decorator (`@comptime`)
  extended to function declarations as a new subsystem (§2.1), plus six
  small comptime intrinsics (§2.2–2.7). No quasi-quotation, no macro
  system, no `@derive` infrastructure, no user-defined decorators.
- **Body reads as plain Vader.** The only meta-level marker is `@comptime`
  on the declaration. Inside, `if` / `for` / `match` are normal
  control-flow — the compiler decides what to specialise based on
  dependency analysis. No decorator soup on every statement.
- **Pure stdlib.** The entire derive logic lives in
  `stdlib/std/json/jason.vader` (~300 LoC). Readable, modifiable,
  copyable by users who want a custom variant.
- **Reuses v1.** No duplicate parser. The v1 tree parser already has
  snippet coverage ; v2 inherits whatever correctness v1 has.
- **Per-call specialisation.** Each `jason.encode[T]` site emits inlined
  per-field code. No runtime introspection, no dispatch, no allocation
  beyond the StringBuilder.
- **Sets a pattern.** The `@fields(T) + @comptime for + @field()` trio,
  once shipped, unlocks user-defined helpers for any per-field operation
  (printing, hashing, equality, validation, ORM mapping, …). `jason` is
  the worked example.
- **No commitment to `@derive`.** If the language later adds a `@derive`
  decorator system, `jason` can plug in via a shim ; today it does not
  need it.

### Cons

- **No field renaming in v2.0.** `User { name: string }` always encodes
  as `"name"`. Snake-case / camelCase / aliasing requires v2.1 work on
  field-decorator exposure.
- **Extra parse allocation on decode.** v2.0 walks the v1 tree
  (`JsonValue`) instead of streaming the source. One transient
  allocation per top-level decode call.
- **`${field.name}_slot` interpolation may be exotic.** §2.5 flags the
  fallback (`array[N]` indexed by comptime position) ; needs validation
  during Phase 2.
- **Diagnostic clarity depends on `@compile_error`.** Without good
  comptime error messages, "type X is not encodable" lands with limited
  context. Mitigation : include `@type_name(T)` in the error.
- **Decoder error reporting is coarse.** v2.0 returns a `JsonError`
  with a synthesised message ("missing field: name") and `pos = 0`,
  without source position from the input text — same as v1.

### When to revisit

- If the `${...}` interpolation proves intractable, fall back to the
  indexed-array variant — slightly less readable but functionally
  identical.
- If `@derive(Eq)` / `@derive(Display)` ship for other reasons, add a
  `@derive(Json)` shim that calls into `jason.encode` / `jason.decode`.
  Backward-compatible by construction.
- v2.1 : add field-decorator exposure + `@json(name = ..., skip = ...)`
  for renaming and conditional encoding.

---

## 8. Effort summary

| Phase | Effort |
|---|---|
| 1 — `@comptime` fn subsystem (per-call spec, dep-tracked elimination) | ~2–3 weeks |
| 2 — Comptime intrinsics (`@is_*`, `@field`, `@field_type`, `@construct`, `@compile_error`) | ~3–4 days |
| 3 — Identifier interpolation `${...}` or array-fallback decision | ~2 days |
| 4 — `jason.encode` end-to-end | ~2 days |
| 5 — `jason.decode` end-to-end | ~3 days |
| 6 — Bench vs. v1 hand-rolled | ~1 day |
| 7 — Doc and stdlib polish | ~0.5 day |

**Total**: ~4–5 weeks. The dominant cost is the `@comptime` fn subsystem
(Phase 1) — today `@comptime` is const-only by construction, the extension
is a new subsystem rather than a tweak. The stdlib code itself is
~300 LoC and ~3 days of writing.

---

## 9. Interaction with `STDLIB_GENERIC_COLLAPSE.md`

`STDLIB_GENERIC_COLLAPSE.md` (prospective) proposes a post-typecheck
erasure pass that rewrites every generic type parameter position to
`ErasedReference` before lower. **This pass and `jason` are mutually
incompatible unless the ordering is settled.**

Concretely : `jason.encode[User]` relies on `@fields(User)` being
resolvable at lower time. If erasure runs first, the call has been
rewritten to `jason.encode[ErasedReference]` and `@fields(ErasedReference)`
returns nothing useful — the encoder collapses to the `else
@compile_error` branch.

Two settlements work :

- **(a) Specialise-then-erase.** Comptime fn specialisation runs before
  erasure. `jason.encode[User]` materialises into `encode__User` with
  field-by-field code baked in. Erasure then sees a concrete function
  with no remaining type parameters and leaves it alone. The specialised
  encoder body stays in the binary as-is.
- **(b) Exempt `@comptime fn` from erasure.** Functions marked
  `@comptime` are flagged in the side-table as "specialise, never erase".
  The erasure pass skips them. Less general but simpler.

Both reconcile cleanly. **Path (a) is the principled choice** because
it places erasure strictly after every other generic-resolving pass,
matching the conceptual model "erasure is the last step that cares
about types". Path (b) is a fallback if (a) proves expensive.

Either way, the erasure plan must be updated to acknowledge `@comptime`
functions as a specific class with deterministic ordering. This
document and `STDLIB_GENERIC_COLLAPSE.md` should land that section
together, whichever ships first.
