# 0025 — A VM scalar rides in its box

## Status

Accepted (2026-09-29). Amends the heap consequence of 0024.

## Context

A VM `Value` is a union; the native backend stores a union as a 16-byte
`vader_box_t` — a tag and an 8-byte payload. The scalar variants were structs
(`I32Val :: struct { value: i32 }`), so every integer, float, bool, char or
string that left a register — into a struct field, an array element, a host
call's argument or result — was a heap object of its own, and the box only held
a pointer to it. At the end of the compiler's self-compilation on the VM, 34.9 M
`I32Val` objects were live: 837 MB of a 1 471 MB live set.

## Decision

`I32Val`, `I64Val`, `F64Val`, `StringVal`, `BoolVal` and `CharVal` are distinct
types over their primitive (`I32Val :: i32`). A distinct is nominal at typecheck
and stripped to its backing by the backend, so the scalar is the box's payload
and allocates nothing. Construction is `I32Val(x)`, the unwrap `i32(v)`.

`TypeVal` (over `i32`) and `ErrorVal` (over `string`) stay structs. Distincts in
one union are told apart by their backing's tag, so two over the same primitive
would be one variant at runtime.

`NullVal` stays an empty struct; reads hand back the module singleton.

## What was measured

Standalone runners built from each tree, minimum of seven runs, before → after:
`vm_field` 252 → 197 ms, `vm_arr` 184 → 155, `vm_fib` 199 → 187, `vm_loop` 418 →
400, `vm_str` 530 → 508; `vm_map` and `vm_shapes` unchanged.

The compiler compiling itself on the VM: 163 to 166 s against 167 to 168, output
byte-identical. Its live set at the end of the run fell from 1 471 to 973 MB;
array buffers grew from 421 to 786 MB.

## Consequences

- `Value` is no longer a union of references only, so a `Value[]` is stored
  `Boxed` — 16-byte slots — instead of `Ref`, 8-byte raw pointers. An element
  that is a struct pays 8 bytes more, and its box is built from the object's
  header when stored.
- The peak RSS did not move: 2.5 to 3.0 GB across runs of one binary, before and
  after alike. It follows the collector's arena sizing, not the live data.
- The compiler had not met a union with a primitive member stored in an array
  before, nor a distinct constructed from a wide literal. Four gaps it exposed are
  closed: a union alias over distincts declared after it, a primitive written into
  a union-element array boxed with the union's tag, `array.push` typed on the
  pushed value instead of the array's element, and a free literal in `Wide(…)`
  typed `i32` instead of the distinct's backing.
