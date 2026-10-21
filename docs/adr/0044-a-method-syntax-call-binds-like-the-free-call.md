# 0044 — A method-syntax call binds like the free call

## Status

Accepted (2026-10-07). Closes the order item 0040 left open. Superseded in part by
0070: the receiver binds the callee's inference variables like any argument, and
`seed_ufcs_bindings` and `check_receiver_alone` are gone.

**Superseded in part by [0053](0053-mutable-by-default-only-constants-are-frozen.md)
(2026-10-09)**: its rights half, a type carrying no rights any more.

## Context

0039 binds a type parameter to the rights all its arguments hold, and 0040 judges
each argument against the instance signature. Both held for `pick(local, CFG)`
and `pick(CFG, local)`, not for `local.pick(CFG)`:

- The method access curried the receiver away and substituted what the receiver
  alone bound: `T = Cfg!`.
- The call was then checked as a non-generic `fn(b: Cfg!) -> Cfg!`, so the
  read-only `CFG` was T3072.

The two spellings of one call disagreed. The method form refused what the free
form accepted, and only in one argument order.

## Decision

**A UFCS call of a generic fn is checked against the callee's own signature,
minus the receiver** (`ufcs_generic_signature`). Its type parameters stay
unbound until the call binds them, from the receiver (`seed_ufcs_bindings`) and
the arguments together, as the free call does.

**The receiver is held to its parameter as the instance has it**, like any
argument (`reject_ufcs_receiver_at_instance`):

- `rows.put(LIST)` binds `T` to the read-only `i32[]` that `LIST` lends.
- `rows`, an `i32[]![]!`, is then refused (T3001), as in `put(rows, LIST)`.
- Before, the receiver bound `T` alone, and the refusal fell on `LIST` instead.

The method access no longer judges, below its top level, a first parameter that
names the callee's type parameters. The call does it, once they are bound. That
holds on the generic path, and also when the signature minus the receiver names
no type parameter (`p.poke()` on `poke<T>(p: Pair<T, Cfg!>)`), where the receiver
alone binds them (`check_receiver_alone`, which also checks their bounds).

**A free literal takes what the call bound its parameter to**, receiver
included. The literal is re-checked against that type, so the lowering, which
instantiates a generic fn from the types recorded on its arguments, picks the
same instance:

- Before, `pick(1, x)` with `x: i64` was typed `i64` but lowered to `pick__i32`.
  The native build printed `410065408`.
- `1.pick(x)` was T3001.

**Deferred lambdas get a binding round only when one of their slots can still
bind**: a type parameter nothing has bound, or one only a free literal has
(`fold(0, (acc: i32, x: i32) -> …)`). Otherwise every lambda is checked once.
More method calls now take the generic path, and checking each nested lambda
twice cost 2^depth: nested `xs.any_match(…)` went from 0.04 s to 2.97 s at
depth 18.

## Consequences

Measured on 2026-10-07, at `f943fa68e`:

- **On 848 programs**, neither diagnostics nor typed ASTs change.
- **On the 148 `.rodata` write probes** of 0039-0041, the verdicts are unchanged.
- **Typecheck time** is unchanged (release builds, minima 505.8 against
  502.0 ms).
- **The fixture that pinned the old refusal** (`local.pick(CFG)` as T3072) now
  pins the result's rights instead: `t3070_method_syntax_binds_least_rights`.
- **A first pass of this change leaked.** It skipped the method access's check
  without judging a receiver-only call, so `p.poke()` wrote into a read-only
  `Cfg` (SIGBUS natively when it held a const). The review caught it, and the
  fixture `t3077_method_syntax_receiver_below_its_level` pins it.

Still open: the method access records the receiver-only signature in
`expr_types`, so a hover on `local.pick` shows `fn(Cfg!) -> Cfg!` while the call
is typed `Cfg`.
