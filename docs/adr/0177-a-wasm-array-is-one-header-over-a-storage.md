# 0177: A WASM array is one header over a storage

## Status

Accepted (2026-11-23). Amends 0175 on two points: `is` on an array type reads a
field, and the slot loads and stores are translated.

## Context

0175 says `is` is `ref.test` on the type itself, and sets aside a `type_index`
field in every object. It lists `LoadSlot*` / `StoreSlot*` among the ops of the C
boundary, refused on a WASM target. Three facts of the arrays go against it:

- Several array ops name no array type: `array.len`, `array.clear`,
  `array.remove_last`, `array.push_all`, `array.copy`, `array.repeat`. They run on
  any array.
- An access in a shared generic instance reads a `T[]` whose elements the
  bytecode erased, while the array may have been made by concrete code storing
  raw `u8`s. The native runtime reads the element kind off the buffer for it.
- A slice is a view (SPEC, *Arrays*): a write through it reaches the array it
  slices, until a push gives one of them elements of its own.

And the bytecode emitter uses the slot ops for every access to a concrete `i32`,
`i64` or `f64` array, not only at the C boundary.

## Decision

- **One struct type for every array**, the header:
  `{ type_id: i32, element: i32, length: i64, capacity: i64, offset: i32,
  storage: eqref, shared: i32 }`. The ops that name no array type read it
  directly.
- **One WASM array type per way of storing an element**: `i8` and `i16` packed,
  `i32` (a string atom included), `i64`, `f32`, `f64`, `eqref`. `element` records
  which: the boxed class of the elements, or the references.
- **`is X[]` compares `type_id`**, the bytecode type the array was made as, as
  the native header's type index does.
- **An erased access dispatches on `element`**, through the classes the module
  makes arrays of.
- **A slice shares the storage**, under the native rule (0108, 0122): a header
  writes in place only `[length, capacity)`; a view is born with
  `capacity == length`, and a header marked `shared` that shrinks sets
  `capacity = length`.
- **A pool entry builds its storage once**, and each array type that reads it a
  header over that storage, as the VM shares the elements.
- **The slot ops are translated**, as the accesses of their storage.
- **Each access is a function** the emitter writes once per way of storing. It
  checks the index against `length` whatever `bounds_safe` says.

## Consequences

- An array carries one `i32` more than 0175 meant: `type_id`.
- An erased access costs a dispatch on `element`, and every access a call and
  two casts of the header while locals are all `eqref`. Inlining the accesses and
  typing the locals precisely are left for later.
- `array.copy` between two arrays that store alike is one WASM `array.copy`;
  `array.push_all` and `array.repeat` still move one boxed element at a time.
- A pool entry is built by one `array.new_fixed`, which engines cap at 10 000
  elements: a larger entry has no WASM form until data segments.

## Set aside

- **A header type per array type, subtypes of a base holding the length.** `is`
  would be `ref.test`, as 0175 wants. The ops with no type and the erased
  accesses still need the element's storage at run time, so the gain is one field;
  the cost is `sub` types in the encoder and one more type per array type.
- **A header per way of storing.** `is u8[]` could not tell a `u8[]` from an
  `i8[]` or a `bool[]`.
- **A slice as a copy.** It breaks the view the SPEC defines.
