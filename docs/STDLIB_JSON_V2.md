# `std/json` v2 — `jason`, a `@derive(Json)` client

> **Status**: prospective. **Reworked 2026-07-20** — the approach changed
> fundamentally. `jason` is no longer a generic function specialized inline at
> each call site; it is a **`@derive(Json)` handler** that fabricates a concrete
> per-type **trait impl** (`T implements JsonEncode`) at compile time, which the
> runtime calls via trait dispatch. Encode first; **decode is gated on associated
> functions** (SPEC:1228) — see §3.
>
> **This doc is thin and depends on
> [`.claude/plans/2026-07-20-quasiquote-derive.md`](../.claude/plans/2026-07-20-quasiquote-derive.md)** — the `@quote` + `@derive`
> capability. `jason` is milestone **M4** there; it cannot land until M1–M3
> (injection, hygiene, user-registrable derive) do.
>
> The name `jason` is a play on JSON + the `a` of vAder.
>
> **Supersedes** the pre-2026-07 plan (inline `@comptime` specialization of a
> generic `jason.encode<T>`), preserved only in git history. That model — its
> `@is_*` intrinsic wishlist, the `@construct` intrinsic, the erasure-ordering
> discussion — is **obsolete**; the `@quote` + `@derive` capability it now rests
> on is [.claude/plans/2026-07-20-quasiquote-derive.md](../.claude/plans/2026-07-20-quasiquote-derive.md).

---

## 1. User-facing surface

```vader
import "std/json"          // v1 — JsonValue, parse, write_string, JsonError
import "std/json"/jason

@derive(Json)
User :: struct {
    name: string
    age:  i32
    bio:  string | null
}

alice :: User { .name = "Alice", .age = 30, .bio = null }
text  :: jason.encode(alice)            // {"name":"Alice","age":30,"bio":null}
back  :: jason.decode<User>(text)       // User | JsonError  — (v2.1, gated — see §3)
```

`@derive(Json)` on the struct triggers the `Json` handler at compile time. No
decorator soup on fields, no `@derive`-vs-hand-roll choice — one decorator.

---

## 2. What the handler generates

For the `User` above, the `Json` handler (a `@derive_handler(Json)` comptime fn, main plan §1)
emits a **trait impl** — the method is fixed (`encode_into`, builder-based), the per-type identity
is the impl target (no forged `encode_<T>` name):

```vader
// generated + materialized at compile time
User implements JsonEncode {
    encode_into :: fn(self, b: StringBuilder) -> void {
        b.append("{")
        b.append("\"name\":") ; encode_value(self.name, b)
        b.append(",\"age\":") ; encode_value(self.age, b)
        b.append(",\"bio\":") ; encode_value(self.bio, b)   // bio: string | null — union impl OPEN (main §6)
        b.append("}")
    }
}
```

The handler walks `@fields(User)` at expansion and emits one field fragment each. `encode_value`
is the generic stdlib helper `fn<F: JsonEncode>(x, b) = x.encode_into(b)`, monomorphized per field
type — concrete, **builder-based** (no per-field string allocation), no runtime reflection. Entry
point: `jason.encode :: fn<T: JsonEncode>(x) { b :: StringBuilder {} ; encode_value(x, b) ; return
b.to_string() }`. Each field type needs a `JsonEncode` impl (primitives + a `T[]` blanket in stdlib;
nested structs via the derive work-list; `string | null` unions still open — main §6).

**Decode is NOT emitted in v2.0 — gated on ONE dispatch feature** (see §3): decode is a trait
`JsonDecode { decode :: fn(text) -> Self | JsonError }`. `T` is in RETURN position and
`jason.decode<T>` is monomorphized, so `T` is **concrete at compile time** — dispatch is
compile-time, no runtime registry. What's missing is **no-receiver dispatch on a bounded
type-param** — the same path the `Default` trait / `T()` needs (TODO §1.5), smaller than runtime
associated functions. So v2.0 ships **encode-only**.

---

## 3. Dispatch & the encode/decode split

**Encode — trait impl.** The handler emits `T implements JsonEncode { encode_into :: fn(self,
b: StringBuilder) { … } }`; the entry point wraps it: `jason.encode :: fn<T: JsonEncode>(x) { b ::
StringBuilder {} ; x.encode_into(b) ; return b.to_string() }`. Trait-dispatching generics are
already mono-specialized (concrete), zero-overhead. No forged per-type name: the method is the
fixed `encode_into`, the type is the impl target. (The `@derive` decorator is the *trigger*; the
`JsonEncode` trait is only the *dispatch channel* — two distinct concerns.)

**Decode — a trait, gated on one dispatch feature.** Decode is `JsonDecode { decode :: fn(text:
string) -> Self | JsonError }`. `T` sits in RETURN position, and `jason.decode<T>` is
monomorphized → `T` is **concrete at compile time**, so dispatch is compile-time (no runtime
registry). The missing piece is narrow: **dispatching a trait method on a bounded type-param
WITHOUT a value receiver** — Vader has the receiver form (`dispatch_bounded_method`) but not
this. It is exactly the gap `Default` / `T()` waits on (TODO §1.5: *"Default trait can wait until
a dispatch path exists"*), smaller than full associated functions (`Type.method()`, SPEC:1228).
Second prerequisite: **construct `T` with computed field names** (a `.@field(name) = …`
struct-literal form, unspecified). So decode is a later milestone (M4b), not part of the first
`@derive(Json)`.

---

## 4. Reuse of v1

`std/json/json.vader` (~788 LoC) stays the dynamic/tree layer; `jason` is the
typed layer on top.

| v1 component | v2 reuse |
|---|---|
| `json.parse(text) -> JsonValue` | decoder front end |
| `JsonValue`, `JsonObject`, … | decoder walks these |
| `json.write_string(s, b)` | encoder string escaping |
| `json.stringify(v)` | unchanged — still the entry point for *dynamic* values |
| `StringBuilder` | encoder accumulator |
| `JsonError` | shared error type |

v2 pays **one** extra allocation on decode (the intermediate `JsonValue` tree)
vs a hypothetical streaming decoder. Acceptable for v2.0; a streaming
`decode_streaming<T>` can come later if profiling asks.

---

## 5. Scope of v2.0

**In** (eventual target): struct encode/decode with field names verbatim; nested structs
(recursive derive); arrays; `string` / integer / bool / `float`; `T | null` optionals. Each
needs its `JsonEncode` impl (primitives + `T[]` blanket in stdlib; nested via the work-list);
**union (`T | null`) encoding is still open** — see main §6. Encode ships first (M4a), decode M4b.

**Deferred to v2.1**: field renaming / aliasing / skip-if-null. These need
field-level decorator metadata that `@fields(T)` does not expose today and that a
`@json(name = …, skip = …)` decorator would carry — a separate chunk once v2.0
lands and demand exists. v2.0 uses field names as written.

**Error reporting** (when decode lands, M4b): the decoder returns `JsonError` with a synthesised message
("missing field: name") and no source position from the input text — same
fidelity as v1.

---

## 6. Phases (all gated on .claude/plans/2026-07-20-quasiquote-derive.md M1–M3)

1. **`Json` encode handler (M4a)** — emit `T implements JsonEncode { encode_into … }` for
   struct / array / scalar / optional fields, plus the generic `encode_value` helper + per-type
   `JsonEncode` impls (primitives, `T[]` blanket); test against v1 conformance fixtures.
2. **Dispatch + bench** — `jason.encode :: fn<T: JsonEncode>(x) { … x.encode_into(b) … }`; bench vs
   a v1 hand-rolled encoder (target within ~10%, both build a string).
3. **`Json` decode handler (M4b) — GATED.** Decode is a trait `JsonDecode`, dispatched on the
   concrete type-arg at mono. Blocked on (a) **no-receiver dispatch on a bounded type-param** —
   the `Default` / `T()` path (TODO §1.5), not full associated functions — and (b) computed-field-
   name construction (`.@field(name) = …`). When those land: emit a decoder over the v1 `parse`
   tree; validate missing-field / type-mismatch / malformed input.
4. **Docs** — usage examples in `stdlib/std/json/jason.vader` header; mark `json.parse` /
   `json.stringify` as the dynamic entry points, `jason` as the typed path.
