# 0106: A tail forwarder pushes no frame

## Status

Accepted (2026-10-22). Amends
[0003](0003-stack-allocated-gc-structs-are-rooted.md): the frame formula.

## Context

The C emitter decided the shadow-stack frame with one bit,
`no_frame :: !may_alloc && !fn_builds_stack_object`, and that bit had two readers
asking two different questions. Frame emission asked "must this function's own
slots survive a safepoint?". The header cache (`invalidate_header_cache`) asked
"does this body reach no safepoint at all?", which is what lets a cached array
header stay valid across the entry of a nested scope. The two answers coincided
only because the frame was pushed by every function that may reach a safepoint.
The field's own comment asked for the split before anyone changed the rule.

A frame protects the slots of ITS function that are read after a safepoint: a
minor collection rewrites the rooted slot, and the read that follows sees the
forwarded pointer. It never protected the callee's copy of an argument; the
callee roots what it reads itself. A forwarder (`MutableMap.set_at`,
`StringBuilder.append`, `write_null`, a lambda reading one field of its
environment) hands its operands to one call and returns what comes back. Nothing
it reads after that call is a slot of its own, so its frame roots values no one
reads again.

Measured on 2026-10-22 at `ba1555023`, with counters added to the compiler's C,
compiling itself: 120.4 M frames pushed, 15.2 M (12.6 %) of them by 130
forwarders. A prototype that removed those frames from the emitted C by script
produced byte-identical output, also with `VADER_GC_YOUNG_BYTES=262144`, and ran
1.0 % fewer instructions (30.75 G against 30.44 G, `-O2` without LTO).

## Decision

The bit is split in two, and neither is the negation of the other: a tail
forwarder reaches a safepoint and pushes no frame, so both are false.

- `FnState.safepoint_free` keeps the old meaning, `!may_alloc &&
  !fn_builds_stack_object`. Its one reader is the header cache. A function that
  cannot allocate is framed exactly when it builds a stack struct, so the emitter
  computes it as `!may_alloc && !needs_frame`, scanning the body once.
- `FnState.needs_frame`, read by every frame site (prologue, rooting, slot
  initialisation, `return`):

  ```
  needs_frame = fn_builds_stack_object || (may_alloc && !is_tail_forwarder)
  ```

`is_tail_forwarder` (`vader/c_emit/frame.vader`) recognises one closed shape on
the bytecode body, after the bytecode passes, and refuses everything else:

1. pure reads (`local.get`, `local.field`, a `ConstOp` constant), exactly as many
   as the safepoint takes, so the operand stack holds nothing else;
2. one safepoint: a `call` of a module function leaving at most one value, or an
   `array.push`;
3. at most one `drop`, of that value;
4. then the end of the body, or a last `return` / `return.lit`.

The count in point 1 is the subtle part: `local.get 0 ; local.get 1 ; local.get 2
; call f/2 ; drop ; return` returns `l0`, read after the call, and a young `l0`
would be stale without a frame.

Why nothing is lost:

- Before the safepoint nothing collects; after it, only the callee's result or a
  literal is returned, and the return coercion (`vader_ref_box`, a scalar box)
  does not allocate.
- The callee roots what it reads: a module function with a frame roots every
  `Ref` / `Any` / `String` parameter, and `vader_array_push_slow` roots the array
  and the value itself. A chain of forwarders ends on one of those, or on a
  callee that cannot collect.
- The other safepoints stay out. A host (`call.import`) may read an atom's bytes
  after it allocates, and only the caller's frame keeps that atom alive.
  `call.indirect` and `virtual.call` go through trampolines and dispatchers that
  were not audited for this. `struct.new`, `array.new` and `make_closure` read
  their operands after they allocate: the frame is exactly what protects them.
- `defer` (`defer.push` is outside the shape), coroutines (a state machine has
  control flow), variadic calls (the caller builds an `array.new`) and stack
  structs (`fn_builds_stack_object` forces the frame) cannot take the shape.

`EmitCtx.may_alloc` is unchanged: a forwarder can still collect, and its callers
(the push cache, the header cache) must keep seeing a call to it as a safepoint.

## Consequences

- 130 of the 6510 functions in the compiler's own C lose their frame (4632 framed
  against 4502), and each change only removes the frame, its root arrays and the
  root initialisations, turning `{ restore; return x; }` into `return x;`.
- A forwarder without a frame is a trivial body, which the C compiler can inline:
  the compiler's binary grows by 65 KB under link-time optimisation.
- The header cache behaves exactly as before: a forwarder opens no scope.
- A forwarder whose operands are not exactly the safepoint's, or whose safepoint
  is followed by control flow, keeps its frame. Allowing control flow around
  tail safepoints would cover more functions, at the price of reasoning across
  `if` / `else` / `end` and of resting on the empty-stack invariant at scope
  boundaries.

Measured on 2026-10-22 against the build before this change (Mac M-series,
release builds, alternated runs): self-compile 1.25 % fewer instructions and
1.3 % less wall time; `string_builder` 7.0 % fewer instructions, `hashmap` 3.8 %,
`wordfreq` and `split_join` 2.9 %; no benchmark regresses. The snippet corpus
under forced minor and major collections with `VADER_GC_POISON=1`, and the
compiler compiling itself with a fixed 256 KB young generation under poison,
produce the same output as unstressed runs.
