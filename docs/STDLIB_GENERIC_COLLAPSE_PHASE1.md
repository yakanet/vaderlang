# Phase 1 — Inline-box generalisation

> **Status**: closed 2026-05-19. 6/6 tasks done.
>
> Multi-field POD structs ≤ 16 bytes (all-primitive fields) now pack
> into the existing 16-byte `vader_box_t.payload.packed[]` view instead
> of heap-allocating. No box size change, no GC arena change, no
> per-allocation cost — `vader_string_t` already made the payload
> union 16 bytes wide ; we just added a new view onto it.
>
> Exit criterion met via
> `bench/poc_erasure/Makefile :: verify_packed` — `Pair { x: i32, y: i32 }`
> compiles, struct.new + struct.get use the packed fast path, no heap
> alloc, binary runs correctly.
>
> **Cross-refs**: `docs/STDLIB_GENERIC_COLLAPSE.md` §2.1 (the original
> framing of this phase, slightly off — see §1 below).

---

## 0. Why this phase exists

POC criterion #1 passed only for primitives that fit a single payload
slot (`i64` inlines into `payload.i`). It would fail for any multi-field
POD like `Pair { x: i32, y: i32 }` (8 bytes) or `Vec3 { f32, f32, f32 }`
(12 bytes) — the current shape gate at `src/bytecode/types.ts:300-333`
returns `null` for any struct with more than one field, forcing a heap
allocation per box.

For the erasure pass (Phase 2) to be perf-acceptable on user types stored
as generic values, multi-field POD structs must inline. Phase 1 unlocks
that.

---

## 1. Key insight — `vader_box_t` already has 16-byte payload capacity

The original framing (`docs/STDLIB_GENERIC_COLLAPSE.md` §2.1) presented
two options:
- (a) bit-pack multi-field payloads into `payload.i` (8 bytes)
- (b) grow `vader_box_t` from 24 to 32 bytes for 16-byte payload

User picked (b). On closer inspection of `runtime/c/vader.h`:

```c
typedef struct {
    uint32_t tag;
    uint32_t _pad;
    union {
        vader_i64_t    i;       /* 8 bytes */
        vader_f64_t    f;       /* 8 bytes */
        vader_bool_t   b;       /* 1 byte */
        vader_string_t s;       /* 16 bytes (ptr + len) */
        void*          obj;     /* 8 bytes */
    } payload;
} vader_box_t;
```

The `vader_string_t` member already makes the union 16 bytes wide. The
struct's total size is `sizeof(vader_box_t) = 24` (verified at runtime).
**The 16-byte payload capacity is already there** — we just don't use
it for multi-field structs today. Option (b) collapses to "use the
existing capacity"; no box growth needed.

This shrinks the effort estimate from 1-2 weeks to ~1 week and removes
the GC arena risk that growing the box would entail.

---

## 2. Scope

**In scope** — extend inline-box to cover multi-field structs:
- Any struct whose fields total ≤ 16 bytes (after alignment).
- All-primitive fields only (no boxed / ref fields inside the packed
  payload — see §6 for the reason).
- Layout uses the existing `payload` union directly (extend the
  union with a `packed[16]` byte-array view so the C emit can address
  arbitrary offsets).
- Pack at `box`, unpack at `unbox`, scan as opaque bytes from the GC.

**Not in scope** (deferred):
- Structs with `ref`-typed fields inside a packed payload (would need
  GC scan support for fine-grained offsets inside the payload).
- Structs > 16 bytes — stay heap-allocated as today.
- Bit-packing arbitrary primitives below 8-byte alignment (e.g.,
  three `u8` fields packed into a single i32) — pure padding-tolerant
  layout for now.

---

## 3. Design

### 3.1 `inlineVariantPayload` extension

Add a new return marker `"packed"` alongside the existing `"void"` /
`<ValType>` / `"ref"` markers:

```ts
export function inlineVariantPayload(
    t: BcStruct, types: readonly BcType[]
): ValType | "void" | "ref" | "packed" | null {
    if (t.fields.length === 0) return "void";
    if (t.name.startsWith("$Cell_")) return null;

    if (t.fields.length === 1) {
        // unchanged — single primitive or single ref
    }

    // NEW — multi-field struct fits the 16-byte payload union.
    const totalSize = sizeOfStructFields(t, types);
    if (totalSize > 16) return null;
    const allPrimitive = t.fields.every(f => {
        const ft = types[f.typeIndex]!;
        return ft.kind === "primitive" && ft.val !== "void" && ft.val !== "null";
    });
    if (!allPrimitive) return null;
    return "packed";
}
```

### 3.2 Runtime — extend `vader_box_t.payload` union

Add a raw-byte view to the union so the C emit can pack arbitrary field
offsets:

```c
typedef struct {
    uint32_t tag;
    uint32_t _pad;
    union {
        vader_i64_t    i;
        vader_f64_t    f;
        vader_bool_t   b;
        vader_string_t s;
        void*          obj;
        uint8_t        packed[16];   // NEW — raw byte view for multi-field
    } payload;
} vader_box_t;
```

`sizeof(vader_box_t)` stays at 24 — the new member doesn't change the
union's width.

### 3.3 C emit — pack/unpack helpers

For a packed struct, the emitter generates inline pack/unpack:

```c
// box: pack struct fields into payload.packed
static inline vader_box_t vader_box_packed_Pair(uint32_t tag, vader_i32_t x, vader_i32_t y) {
    vader_box_t bx; bx.tag = tag; bx._pad = 0;
    memcpy(bx.payload.packed + 0, &x, sizeof x);
    memcpy(bx.payload.packed + 4, &y, sizeof y);
    return bx;
}

// unbox: read field at offset
static inline vader_i32_t vader_unbox_packed_Pair_x(vader_box_t b) {
    vader_i32_t out; memcpy(&out, b.payload.packed + 0, sizeof out); return out;
}
```

The `memcpy` calls are inlined by `cc -O3` into direct loads/stores at
the right offset. No runtime cost.

### 3.4 GC scan info

Packed payloads with all-primitive fields contain **no references**.
The GC scanner skips the payload entirely for these tags — same as
`VADER_TYPE_KIND_NONE`. The per-type info table sets `ptr_count = 0`
and `string_count = 0` for packed types, so the existing scan loop is a
no-op.

If a future extension allows packed payloads with ref fields, the
per-type info would need byte-offsets into the packed payload (parallel
to today's heap-allocated `ptr_offsets`). Out of scope here.

---

## 4. Tasks

| # | Task | Files | Effort |
|---|------|-------|-------:|
| P1-1 | Extend `inlineVariantPayload` with `"packed"` marker | `src/bytecode/types.ts` | 0.5 d |
| P1-2 | Runtime: add `packed[16]` to the payload union | `runtime/c/vader.h` | 0.25 d |
| P1-3 | C emit: pack/unpack helpers + box construction at struct.new sites | `src/c_emit/body.ts`, `src/c_emit/ops.ts` | 1.5 d |
| P1-4 | GC scan info: zero-out for packed types | `src/c_emit/emit.ts` (type info table) | 0.25 d |
| P1-5 | Bench validation: `bench/poc_erasure/pair_inline_test.{vader,Makefile target}` | `bench/poc_erasure/` | 0.5 d |
| P1-6 | Snippet smoke: confirm no regression on existing inline-variant snippets | `tests/snippets/` audit | 0.5 d |

**Total: ~3.5 days.** Down from the original 1-2 weeks because no
box-grow work is needed.

---

## 5. Exit criteria

1. **Functional**: a Vader file with `MutableMap(Pair, i64)` where
   `Pair :: struct { x: i32, y: i32 }` compiles and runs correctly.
   Verified via a new bench snippet.
2. **Allocations**: under `VADER_GC_STRESS=1`, the 100k-insert workload
   allocates exactly 100k entry nodes — zero extra allocations for
   the boxed key payloads. Verified via the existing `poc_alloc_count`
   pattern from `bench/poc_erasure/`.
3. **No regression**: existing snippet tests stay green.

---

## 6. Why all-primitive only

Packed payloads with reference fields would require:
- Per-type info tables with byte-offsets into the packed payload (vs
  today's `offsetof(struct, field)` for heap-allocated objects).
- GC scanner extension to read those offsets and trace the refs.
- Forwarding pointers — if the payload is mutated, every reader sees a
  copy, not the original. (Same issue that excludes `$Cell_*` from
  inline today.)

These are not hard problems, but they're additional surface for a Phase
1 that's already bounded. The 90 % case — `Pair { x: i32, y: i32 }`,
`Vec3 { f32, f32, f32 }`, `Point { x: i64, y: i64 }`, color tuples,
small ID pairs — covers all-primitive payloads. Mixed payloads are a
later optimisation if data shows demand.

---

## 7. Open questions

1. **Alignment**: structs with mixed primitive sizes need padding for
   ABI. E.g. `Mixed { a: i8, b: i64 }` is 16 bytes with 7 bytes of
   padding after `a`. Pack should respect that padding so reads via
   `memcpy` at `offsetof(Mixed, b)` work. The compiler already computes
   field offsets respecting alignment; reuse those.
2. **Endianness**: `memcpy` of a multi-byte field on a little-endian
   host preserves byte order. Cross-host compatibility of serialized
   boxes isn't a concern at MVP — boxes are runtime-only, never
   persisted.
3. **String fields**: `vader_string_t` is a 16-byte fat pointer that
   already uses the full payload. A single-field `struct { s: string }`
   already inlines via the existing single-field-primitive path.
   Packed variant is unnecessary for that case. Confirm the existing
   path is preferred when applicable.

---

## 8. After Phase 1

- Re-run the POC bench with the new packed-payload support; confirm
  `MutableMap(Pair, i64)` allocates only entry nodes.
- Update `bench/poc_erasure/results.md` with the Phase 1 measurement.
- **Then Phase 2 (automatic erasure pass) starts.** Phase 0 + Phase 1
  combined give Phase 2 a clean foundation: dispatch infrastructure
  (Phase 0) + boxing efficiency (Phase 1).
