# 0031 — The VM inlines calls to small straight-line leaves

## Status

Accepted (2026-10-04).

## Context

A direct call on the register VM records a frame, resets the callee's locals,
copies its constants into the frame and moves the result back out. Measured on
2026-10-04, that is about 19 ns where an arithmetic op costs about 1.7 ns, so a
leaf doing two or three ops of arithmetic pays several times more for its call
than for its body. `arr_map` (`for x in a.map(square)`) ran 586 times slower on
the VM than natively; written with `square`'s body inline it ran 33 % faster.

The compiler had a lowering inliner until 2026-09-13; it was removed because it
cost emission time and no native workload moved — `cc` inlines on its own. The VM
was not measured then.

Options weighed:

- **A.** A bytecode → bytecode pass in the VM's `prepare`, before verification.
- **B.** The same at the register level, after translation: constants live per
  frame and operands are register windows, so splicing a body means renumbering
  both.
- **C.** Back in the lowering: both backends pay the emission cost, only the VM
  gains.

A prototype of A, measured against the same binary with inlining off, settled
the criteria: field reads added to the inlinable ops gained nothing measurable,
and `vader test` and the comptime evaluation of a self-compile were neutral —
both are dominated by compilation, not by calls.

## Decision

A, in `vader/vm/inline_leaf.vader`, run by `prepare` and skipped by
`prepare_debug`. A direct `call` is replaced by the callee's body when the callee:

- is straight-line — no block, loop, branch — of at most 16 ops besides its
  only `return`, which is its last op, and has at most one result;
- holds only ops that can neither call nor trap: locals, constants, numeric
  conversions, integer and float arithmetic without integer division, comparisons
  and boolean ops;
- writes each of its own locals before reading it.

The arguments are stored into locals appended to the caller — one block per
leaf, shared by every site of it, since an inlined body calls nothing and two of
its sites never overlap. Those locals are reset once per call of the caller, not
once per site, hence the last criterion: a local read first would see the value
an earlier site left.

The verifier and the tag inference then run on the rewritten module, so a wrong
splice fails `prepare` instead of running. Inlining moves where an operand's tag
is proven: an inlined body's operands carry the caller's argument tags, no longer
the leaf's signature. A module whose rewritten form fails that check is prepared
again without inlining, so every module that prepared before still prepares.

Every op of a rewritten body keeps the pc it had as emitted
(`BcFunction.source_pc`); the translator maps it into the register code's origin,
so a trap or a frame trace names the pc `vader dump` shows. No trap can happen
inside an inlined body. Under the debugger nothing is inlined, so every call
stays a frame to step into.

## Consequences

Measured 2026-10-04 against `f33db8d0b`, alternating, VM:

- `arr_map` (run with a tenth of its passes) −29 %, `vm_map` −9 %,
  `iter_chain` −8 %; `sort_by` −2 %; `vm_fib`, `vm_loop`, `vm_arr`, `vm_field`,
  `vm_str`, `vm_shapes`, `map_iter`, `closures` within noise.
- `vader test lib/std`, `vader test vader` and the self-compile: within noise; the
  C a self-compile emits is identical byte for byte.
- The comptime step budget counts fewer calls.

Native code is unchanged. A leaf with a branch (`min`, `abs`), a field read or a
call keeps its call; widening the criteria is a separate measurement. So are
passing arguments on the stack instead of through `local.set`, and sharing one
block of locals between leaves.
