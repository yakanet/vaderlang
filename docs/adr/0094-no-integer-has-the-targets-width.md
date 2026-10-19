# 0094 — No integer has the target's width

## Status

Accepted (2026-10-19). Second of the two steps 0093 announced: `usize` and `isize`
leave the language. The user chose to spell a foreign `size_t` with a decorator
(`@c_type`) over keeping a pointer-width integer for the foreign boundary alone.

## Context

After 0093, `usize` and `isize` served only the foreign boundary: the integer a
`CPointer` is read as, the words lent where C wants a `char**` or a `HANDLE*`, the
reserved members of a mirrored Win32 struct, and the `size_t` of a function
declared without its header, whose prototype Vader synthesises from the signature.
Keeping two integer types for that kept their cost everywhere else: a width that
depends on the target in the type checker, a `ValType` pair in the bytecode, a C
spelling (`size_t`, `ptrdiff_t`), checked-arithmetic helpers and `std/core` impls
for each, and `u64` and `usize` holding neither the other although they hold the
same values on every target the compiler builds for.

## Decision

- **No integer has the target's width.** The eight machine integers remain.
- **A `CPointer` reads as an integer at least as wide as a pointer**: `i64(p)` or
  `u64(p)`. A narrower one is still `T3010`.
- **A word lent to C is a `u64`**, a sentinel compared against a handle an `i64`
  (`INVALID_HANDLE: i64: -1`).
- **`@c_type("…")` names the C type a foreign function declares for an integer**
  where it is not the Vader type's own spelling: on a parameter for that
  parameter, on the declaration for the result. The value keeps its width, so the
  C type must be an integer as wide as the Vader one; a native build asserts it
  with a `_Static_assert` beside the prototypes. A float is refused: the
  interpreter would pass it in a float register where the native call passes an
  integer.
- **The buffer allocation is a free `@intrinsic`**, `new_byte_buffer(n: i64)`, in
  place of the `BufferAlloc` trait `usize` implemented.

## Consequences

- A foreign function without its header that takes or returns `size_t` needs
  `@c_type("size_t")`; with `@c_header` the header owns the prototype and the
  decorator only adds the conversions at the call.
- The interpreter passes the Vader width to the callee and has nothing to compare
  a `@c_type` against: the width rule is checked by a native build only.
- On a 32-bit C target, reading a pointer as an `i64` is a conversion the C
  standard leaves to the implementation (sign or zero extension), so `i64(p) == -1`
  could miss `INVALID_HANDLE_VALUE` there. No such target exists; the emitter would
  convert through `intptr_t` when one does.
- `@size_of` and `array.len` are `i64` in the bytecode and in the generated C,
  which no longer declares a `size_t` temporary. The buffer operations still take
  a `size_t` from the runtime, a negative count included, which the interpreter
  refuses.
- The step needed a seed that already knew the free allocation and the 64-bit
  pointer readings, so it landed in two commits around a reseed.
