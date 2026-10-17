// CLI C-emit parity (TODO §2.2) — Vader's `dump --stage=c` output.
//
// Two oracles per allowlisted snippet :
//   1. regression  — `dump --stage=c` matches the Vader-generated
//                    `emit-c.snapshot.c` golden (catches unintended drift).
//   2. behavioural — the emitted C compiles with `cc` and runs, matching
//                    the VM-recorded `vm.snapshot` (the correctness oracle
//                    that survives the TS compiler's deletion).
//
// TS is a diagnostic reference only, never a gate here — the TS compiler
// is disposable, and on any divergence we keep the cleaner Vader output.
// The allowlist grows tranche by tranche (see the plan's §9). T0 covers
// the constant-return path only.

import { test, expect } from "bun:test";
import { join, resolve } from "node:path";
import { tmpdir } from "node:os";
import { existsSync, readFileSync, writeFileSync } from "node:fs";

import { EXE_SUFFIX, LONG_BUILD, runCli } from "./cli-bin.ts";
import { C_SNAPSHOT, SNAPSHOT_TARGET, expectsCompileErrors, formatRun, listSnippets, snapshotEquals } from "./snapshot.ts";
import { snapshotDiff } from "./diff.ts";

const RUNTIME_ROOT = resolve(import.meta.dir, "../runtime/c");

// `$CC` first, as `vader build` reads it (`vader/pipeline/emit.vader::default_cc`).
const CC = process.env.CC || "cc";

const CC_AVAILABLE = await (async () => {
  try {
    const proc = Bun.spawn([CC, "--version"], { stdout: "ignore", stderr: "ignore" });
    return (await proc.exited) === 0;
  } catch {
    return false;
  }
})();

// Snippets whose Vader-emitted C is at parity. Grows tranche by tranche
// (see the plan's §9). T0 : the constant-return path.
const C_PARITY = new Set<string>([
  "return_42",
  // T1 scalar core : params, an i32 binop, a default argument.
  "fn_decl",
  // T1b : locals read twice or folded into a later expression, i32
  // add/sub/mul.
  "scalar_locals",
  // T1c : the rest of the i32 expr family — cmp (eq/ne/lt/le/gt/ge),
  // bitwise (and/or/xor), shifts (shl/shr), unary (neg/bitnot).
  "scalar_arith",
  // T1d : i64 / u32 / u64 / f64 families, eager integer + f64 div/rem,
  // bool.not, i32<->i64 / i32<->char conversions.
  "scalar_wide",
  // T2 : structured control — block / loop / if / else / end / br
  // (jump_table-resolved goto labels, dynamic indent). Counted loop +
  // if/else body ; result via main's exit code (142).
  "scalar_control",
  // A condition that branches on each operand of `&&` / `||` / `!`: shared
  // targets reached by `br_if`, an empty then-arm negated.
  "short_circuit_conditions",
  // T3a : direct `call` — own fns by index, scalar args + result
  // threaded through a fresh temp. Result via exit code (49).
  "scalar_call",
  // T3b : `call.import` + import shims — println reaches the runtime via
  // vader_import_N (write + Display.to_string). stdout-observed.
  "io_println",
  // T4a : stack structs — struct.new_stack / local.field / ref.cast /
  // struct.set_stack (body rep, no GC frame). Exit code 17.
  "struct_point",
  // T4b : heap structs (struct.new) + the GC-frame prologue (gc_roots /
  // gc_frame / gc_top, ref-slot zero-init, framed return). Exit code 7.
  "struct_heap",
  // T5 : arrays — array.new / set / push / get / len (boxed elements via
  // box_expr; heap → reuses the GC frame). Exit code 153.
  "array_ops",
  // T6 : strings + builder — string.concat / string.eq (atom ==) + the
  // builder family (interpolation). stdout "hello, world!".
  "string_ops",
  // T3c : closures + dispatch.
  //   fn_value_local       — fn.ref → vader_fn_tramp/static + call.indirect.
  //   closure_callback     — make_closure → vader_fn_lift + fn-value param.
  //   trait_virtual_dispatch — virtual.call → per-key dispatcher + the slot
  //                          tables (existential `Error` receiver).
  "fn_value_local",
  "closure_callback",
  "trait_virtual_dispatch",
  // A lambda that ignores a param must still be lifted WITH that param, or its
  // arity mismatches the closure calling convention at call.indirect. Guards the
  // resolver def-site recording fix (unused lambda params).
  "unused_lambda_param",
  // `and_then` infers `U` from a `U | Error` union in a fn-param's return, fed a
  // block-body lambda. Guards the lambda-return inference fix (never → real type)
  // that keeps the union-position type param bindable.
  "and_then_infer",
  // Two same-name free fns distinguished only by a concrete union member
  // (`T | null` vs `T | Boom`) dispatch by receiver specificity, not first-match.
  // Guards the overload-by-receiver ranking across typer + lowerer UFCS.
  "overload_by_receiver",
  // T7 : misc ops. type_check (`x is T` → tag-compare / trait disjunction) is
  // the validatable one — a chain of divergent `is`-guards. type.const /
  // size_of.type / defer.push / defer.pop_exec handlers are also ported but
  // unreachable via a clean snippet today (the former blocked by the pending
  // arg / local.set coercion `todo`s, defer by the upstream Vader bytecode
  // dropping defer ops — a self-host gap, not a C-emit one).
  "chained_divergent_narrow",
  // T12a : boundary ValType coercion (call-arg / return / local.set /
  // struct-field) via `coerce_expr` — boxes a primitive into an erased
  // `ref`/`any` slot (and the inverse), the common monomorphised-generic
  // shape (`fn<T>` params lowered to `ref`). The heavy erasure-boundary
  // reshape (array-kind / heap-struct) + B1 stay deferred — no reachable
  // snippet needs them yet.
  "trait_dispatch_param",
  "intrinsic_fields",
  "intrinsic_type_args",
  "comptime_type_value",
  // Dead trailing return : an exhaustive-returning match leaves the lowerer's
  // implicit fn-terminator return unreachable with an empty operand stack —
  // `emit_return` traps it (`vader_unreachable`) instead of underflowing. All
  // three exercise a union match where every arm returns.
  "array_of_union",
  "alias_union_in_array",
  // A primitive written into a union-element array (literal, `a[i] =`, push)
  // boxes with its OWN tag — the VM always did, the emitted C stamped the union.
  "union_primitive_in_array",
  "union_of_distincts_sibling_file",
  "distinct_wide_literal",
  // A small integer or an enum entering a union is tagged with its own type
  // natively (a constant reaches the C emitter as an `i32`).
  "union_small_int_and_enum",
  "narrow_imported_map",
  // §9 C-emit audit (the walker now emits C for the whole compiler) :
  //   for_loop      — `break` out of an infinite `for {}` (a Loop) + `continue`
  //                   → generalized branch resolution (break past a Loop/If end,
  //                   not just a Block). Would hit the unresolved-target todo
  //                   before the fix.
  //   if_null_narrow — break / continue in divergent null-narrow branches.
  "for_loop",
  "if_null_narrow",
  // Erasure-boundary tuple field read : `for [k, v] in zip(...)` / `indexed()`
  // yield erased-sibling tuples (all-`Any` from zip, `[Any, usize]` from
  // indexed) that the carrying array erases to `ref` ; the concrete field
  // read must tag-dispatch + box/unbox (`c_emit/walker.vader::push_struct_field`).
  // The native-run oracle here is the regression guard — the snapshot/VM
  // dimensions stay green even when the native field read is wrong.
  "iter_zip_chain",
  // A raw `T[]` reaching an `Iterator<T>` param of a METHOD call, on both UFCS
  // shapes (free fn, impl member). The argument used to stay unwrapped where the
  // receiver was coerced, so it trapped at the first `next()` — in the native
  // backend as `unreachable at vtable miss in Iterator.next`, not silently. The
  // native run is the guard that the `into` wrap the lowerer inserts is the same
  // one the VM sees.
  "iter_coerce_method_arg",
  // The same raw `T[]` reaching an `Iterator<T>` param of a generator INLINED
  // into a fused loop — as a chain source, or as a combinator's data param — and
  // a scalar reaching a union data param. Inlined, so the native run checks the
  // fused body, not the state machine.
  "generator_inline_arg_slots",
  // A 0-arg combinator over `Iterator<T | null>` whose yielded value must unbox.
  "iter_chunks_distinct_nulls",
  // A type parameter left alone in a union pattern binds the union of the
  // argument's other variants (`T | null` over `i32 | string | null`).
  "generic_param_over_wide_union",
  // Captured parameters : a `defer` / lambda body that reads one of its
  // enclosing fn's PARAMS copies the raw ABI value into a non-empty env, which
  // the lifted body reads back with a typed `struct.get` in the C emitter. The
  // run oracle (matches vm.snapshot) is the guard.
  "defer_capture_param",
  // Captured loop bindings : a for-in element/range loop var and a lambda's own
  // param captured by a nested lambda are copied into each closure's env when it
  // is made. Closures stashed in the loop and run after it must each see their
  // own iteration's value — the run oracle is the guard.
  "capture_loop_var",
  // Rebound captures : a param reassigned after a closure captured it (at fn
  // entry, `promote_cell_params`, and in a lambda), a range counter the body
  // reassigns (per-iteration cell on a synthetic counter) and a local the closure
  // increments all live in a cell both sides share.
  "closure_sees_rebound_capture",
  // Generators (`@generator` + `yield`) — the state-machine lowering emits a
  // synthesized `g$State` struct + an `Iterator::next` state machine consumed by
  // for-in; the native run validates the whole desugar end-to-end.
  "generator_basic",       // single loop, one yield
  "generator_nested",      // nested loops (resume mid-inner-loop)
  "generator_filter",      // yield inside an `if`
  "generator_break",       // break + continue across a yield
  "generator_struct_elem", // struct element type, flattened
  "generator_escapes",     // stored-then-consumed → boxed state machine (not inlined)
  // A generator local captured by a closure, read at each yield : nothing
  // reassigns it, so the closure's env holds its value and the frame carries the
  // closure. A reassigned one (`closure_sees_rebound_capture`) spills to a
  // `g$State` field that must carry the cell, not the value type.
  "generator_closure_capture",
  // Stream fusion (Couche 1): `arr.iter().map(f).filter(p)` under a `for`
  // fuses to a flat index loop — no iterator structs. Native run validates the
  // fused loop produces the same output as the boxed tower would.
  "fuse_array_map_filter",
  // Couche 2: take/skip fuse via a pre-loop counter + break/continue guard.
  "fuse_take_skip",
  // Couche 4: a directly-consumed generator inlines its yield-loop as the
  // fused body — native run validates it matches the boxed state machine.
  "fuse_generator_direct",
  // Couche 4: a GENERIC generator inlines too — instance subst reconstructed
  // at the fusion site (gen_map / gen_filter, T -> U).
  "fuse_generator_generic",
  // Couche 4: a generator COMBINATOR (first param = source iterator) fuses as a
  // chain layer — single UFCS combinator + nested direct-call chain.
  "fuse_generator_chain",
  // A fused chain evaluates each operand once, in source order, before the first
  // element — the predicate of a terminal, a range bound, a layer argument. Every
  // operand logs its evaluation, so the native run pins the order and the count.
  "iter_chain_operands",
  // `place op= rhs` evaluates the operands of its place once — index, call
  // receiver, nested place, `IndexSet` impl and bound, a default method's clone.
  // Every operand logs, so the native run pins the count.
  "compound_assign_operands",
  // A `continue` in a counted loop still runs the loop's step — from a `match`
  // arm, a `??` fallback in a call argument, a loop a `break <var>` also
  // targets, an inner loop's `continue <var>`. A guard ends a loop that stopped
  // advancing, so a regression prints rather than hangs.
  "counted_loop_continue",
  // A jump inside an expression of a generator or async fn (`v :: x ?? continue`,
  // a yielded `x ?? continue`, `?? break`, `?? return`) takes its transition in
  // the state machine instead of re-running its state or leaving `next()`.
  "coroutine_nested_jumps",
  // A `break` / `continue` in a `for` over a generator call reaches that `for`:
  // the generator's body is not fused into it, so no loop of the generator can
  // catch the jump instead.
  "generator_consumer_jumps",
  // A name a closure captures lives in a cell however it was bound: a
  // destructuring leaf or its `...rest`, an `if … as` alias, a fused
  // generator's or combinator's parameter.
  "closure_captures_bindings",
  // `@extern` forwarding shim — string args marshalled atom → `const char*`
  // (`c_emit/host.vader::user_extern_shim`). The shim exists only in native C
  // output — the VM reaches a foreign symbol through `dlsym` instead, so it
  // never marshals through the shim — which makes this run the only guard on
  // the marshalling ABI. Links the snippet's `helper.c`.
  "extern_native_basic",
  // Comptime-folded non-finite f64 constants (`inf` / `-inf` / `nan`). The
  // native run is the guard: the literal emitter must render them as compiler
  // builtins, not the bare words `inf` / `nan` (invalid C). Regression B3.
  "f64_non_finite",
  // `async` + `await` — the coroutine state-machine lowering (`lower_async`,
  // Model A self-drive) synthesizes an `__asyncstate` frame + an `Async::resume`
  // machine. The native run is the seed-critical guard on the erased→concrete
  // cast at each drive site (`cast(child.resume(), T')`) — it must round-trip a
  // boxed value back to its concrete type in emitted C, not just on the VM.
  "async_basic",       // one await, value return
  "async_sequential",  // two awaits of different types + resume-after-done
  "async_conditional", // await hoisted into a conditional branch
  "async_countdown",   // genuine suspension: re-entrant drive of a parking child
  "async_fallible",    // fallible result `T | Error`, narrowed at match
  "async_trailing",    // trailing (implicit-return) await + two awaits per expr
  "async_void",        // void async: `null` done-marker, nested void await
  "async_main",        // implicit async main: inlined run-driver, exit code
  "async_sleep",       // real suspension via sleep: park scheduler + timer heap
  "async_sleep_main",  // implicit async main routed through run_async_main
  "async_all",         // join_all(xs): concurrent join, input-order results
  "async_try_all",     // try_join_all(xs): fallible join, first-error by input order
  "async_interleave",  // visible cooperative interleaving via println order
  "async_shared_deadline", // timers sharing a deadline are spent by one park
  // Captured param + local surviving `await`: the local the closure reassigns
  // lives in a heap cell the frame must carry across suspension (the retired
  // M5008 case) ; the param is copied into the env. Native run is the
  // seed-critical guard — the C-emit bug was a value-typed spilled field.
  "async_closure_capture",
  // The same, but two coroutines under `join_all` with interleaved drives: their
  // cells must stay distinct (the concurrent-capture VM corruption M5008 masked).
  "async_capture_concurrent",
  // `defer` inside a coroutine (4a): pending defers live in a per-frame stack and
  // drain LIFO at completion. A defer registered before the await — and the local
  // it captures — must survive the suspension. Native run is the guard.
  "async_defer",
  // Cancelling a suspended coroutine (4c-1): `frame.cancel()` runs pending defers
  // LIFO and recursively tears down the awaited child, without finishing the body.
  // Native run guards the synthesised `$Async$cancel` method + drain loop.
  "async_cancel_defer",
  // `join_all` resumes a child only once its reported `wake_at` has passed.
  "async_join_all_due_children",
  // An impl reached across modules: an `Into` declared elsewhere, an impl of an
  // imported trait — both registered by identity, not by name.
  "into_across_modules",
  "impl_of_imported_trait",
  "impl_short_form_of_shadowed_trait",
  "into_between_same_named_types",
  "into_distinct_instantiations",
  "impl_on_concrete_instantiations",
  // An impl on one instance wins over its base's generic impl, through a trait
  // value, a bounded parameter, and an instance built in a generic body.
  "impl_specialization",
  // `x[i]` / `x[i] = v` through a trait value or a bounded `T`, and a
  // destructuring place written through `set_at`.
  "index_through_trait_value",
  // A free literal takes the type its call binds, in method and free syntax alike.
  "literal_argument_takes_its_binding",
  // An array converted by the `into` toward its slot's type: impls on its own
  // instance toward `Label` and `Iterator<Label>`, core's toward `Iterator<Mon>`.
  "array_into_by_target",
  // Two `Into` impls on one struct instance or one concrete array, each run.
  "into_impls_on_one_instance",
  // An array iterated through its own `into` by an inlined consumer and a chain.
  "array_own_into_not_fused",
  // An implicit `into` at an assignment, a destructured place, a `push`, a `??`
  // fallback, a `yield`, the argument of a namespace, explicitly instantiated or
  // dispatched call, and an expression body's return.
  "into_at_every_slot",
  // Several impls of one trait on one receiver : each use site runs the one its
  // own types pick.
  "several_impls_of_one_trait",
  // A union of a trait's implementors, and a value of the trait, dispatch its
  // members by their tag : method, index, `in`, operator.
  "union_trait_dispatch",
  // Consts read before their declaration, by a const and by a fn ; a `fn(Self)`
  // callback an impl writes with its own type.
  "const_read_before_its_declaration",
  // Consts nothing reads : their data-pool entries are pruned with their types.
  "const_never_read",
  // A const read under a trait type : its baked structs keep their types.
  "const_trait_array",
  // A field default whose lambda builds its own struct : the inner literal calls a thunk.
  "field_default_builds_its_struct",
  // race (4c-2): first awaitable to settle wins, losers cancelled — the loser's
  // defer runs on teardown, the winner's at its own completion.
  "async_race",
  // timeout (4c-2): the awaited value is cancelled when the deadline elapses
  // first; a TimeoutError (an `Error` value) surfaces, the work's defer runs.
  "async_timeout",
  // join_any (4c-2): first SUCCESS wins (a settled error is not a win); explicit
  // `<U, E>` type args, same as try_join_all.
  "async_any",
  // Not async-specific : a generic struct's trait impl materialised when the
  // struct is built only inside a generic fn's body (the harvest never saw the
  // concrete instance). Regression guard for lower_struct_lit's queue gate.
  "generic_impl_via_generic_fn",
  // `break <var>` / `continue <var>` targeting an outer loop by its iteration
  // variable, over both the int-range and raw-array fast paths. The counter/index
  // increment must run on a var-targeted `continue` (else it spins) — native run
  // is the guard on that reconciliation.
  "loop_break_by_var",
  // Narrow-integer casts and arithmetic cut to their width wherever they are
  // read, stored or not; native output == vm.snapshot keeps the backends from
  // drifting on it.
  "narrow_int_wrap",
  // `i32` / `i64` arithmetic wraps past the maximum (release: `signed_overflow_release.test.ts`).
  "signed_overflow_wraps",
  // A union alias naming a member through a namespace import, declared before and
  // after the signatures that use it.
  "namespace_union_alias",
  // Guards narrowing one binding in a nested block stay in that block.
  "guard_narrowing_stays_in_block",
  // Generic call whose type-param is bound only by the call's expected type,
  // with a lambda factory argument. Native is the oracle that matters here: the
  // erased-vs-packed element mismatch this guards against was invisible in the
  // VM (it boxes uniformly) and only corrupted the native buffers.
  "generic_lambda_factory",
  // `x := []` widened by its first push. Native is the oracle: the widened local
  // reads/writes packed elements, so a literal left erased allocates a boxed
  // buffer and the array silently reads back garbage past its first growth. The
  // VM boxes uniformly and never saw it.
  "empty_array_widening",
  // A type-param bound only by the call's result slot, on both sides of the
  // pipeline (typecheck's unify + the lowerer's instance key).
  "generic_return_binds_typaram",
  // Two lambda arguments, the second one the binder — guards the fixpoint in
  // the deferred-lambda pass and the two no-information unification refusals.
  "generic_lambda_binder_order",
  // Every module-const shape, and singletons holding a module's state. Native is
  // the oracle that matters: the storage each shape lands in is a C-emit decision
  // (a pooled array becomes a `static const` .rodata blob read through a
  // zero-copy view), and a mismatch between the pooled representation and the
  // read site is a silent wrong-value read, not a trap. The singletons' instances
  // must survive collections through the permanent GC frame.
  "module_storage",
  // A `@singleton`'s instance lives in a global slot, which the C emit declares
  // and roots in the permanent GC frame by what it holds (a box, a raw reference,
  // an atom): native is the oracle that the instance survives and keeps its writes.
  "singleton_instance",
  // An `is` test on a union of arrays selects the variant on SHAPE alone, so
  // native is the oracle: each branch must still land on the right concrete
  // element width. A variant matched modulo mutability that read back at the
  // wrong representation would be a silent wrong value, not a trap.
  "union_variant_narrow_mutation",
  // The emitted C IS the subject: `@c_struct` marshalling exists only there,
  // and its `_Static_assert` layout lines have no other corpus. Oracle 2 links
  // the snippet's `helper.c`, so it also pins that the synthesised prototype
  // agrees with the address the shim actually passes.
  "array_clear_refill",
  "c_pointer_as_word",
  "c_struct_char_field",
  "extern_cpointer_match",
  "c_struct_layout",
  "c_struct_prefix_mirror",
  // A C CALLBACK: what must cross is `&snippet_double_it`, the function's own
  // symbol, and not the `vader_fn_t` a fn value would be. Oracle 1 pins that
  // line in `emit-c.snapshot.c`; the `vm.snapshot` holds what the NATIVE binary
  // prints, which is what makes Oracle 2 discriminate — `helper.c` calls the
  // callback, so a wrong address crashes instead of passing quietly.
  "extern_callback",
  "extern_callback_slot",
  "extern_lend_across_callback",
  // A slice and its parent share one buffer, and emitted accesses do not
  // re-check where it lives: a lend that moved it behind the view's back would
  // leave the view reading the abandoned copy. Native only — the VM never moves.
  "extern_lend_sliced_array",
  // Element-REPRESENTATION divergence between a module const (BOXED slots) and a
  // freshly allocated array (KIND_REF): the VM never runs the copy, so only the
  // native oracle can judge these. `array_push_all_const` existed as a snippet
  // when its own bug was fixed but was never allowlisted here — and the sibling
  // defect in `vader_array_copy`, forty lines below the fix, survived until an
  // audit found it. Both are on the list now so one oracle covers the family.
  "array_push_all_const",
  "array_copy_to_const",
  // The push cache lifts an array's length / capacity / slots into C locals and
  // writes them back at the loop's end. The VM has no such form, so a missed
  // write-back — a `break` compiled past it — only shows when the C runs.
  "array_push_cache",
  // A fn whose only host calls never collect (`byte_at`, the cached string
  // hash) is emitted without a GC frame. Only the native build drops frames,
  // so only its run under forced collections says the classification holds.
  "string_key_lookup_gc",
  // A generic instance keeps an enum with variant data concrete : its key
  // hashing and comparison in a map, and the module-qualified mangle that keeps
  // two same-named enums apart, only show what they emit when the C runs.
  // `enum_key_equality` also pins that an enum's `==` never becomes a call to
  // a host `<int>$Equals$equals`, which the VM binds and the native build does not.
  "enum_key_equality",
  // A direct `a.equals(b)` on a primitive reaches its `@intrinsic` import, which
  // only the VM binds a host for : the native build has to emit its op instead.
  "primitive_hash_eq",
  // A union `==` and an erased `Equals` call test each operand's tag before the
  // variant's own comparison ; a wrong read only shows natively as a wrong answer.
  "union_value_equality",
  "equals_across_variants",
  "literal_pattern_on_union",
  "array_content_comparison",
  "distinct_reference_equality",
  "float_ieee_equality",
  // `string.compare` is an op of its own : the VM's arm and the runtime's
  // `vader_string_compare` must order the same.
  "string_ordering",
  // `s[i]` and `s[lo..<hi]` walk malformed UTF-8 the same way on the VM, which
  // calls its own native string code, as in the runtime.
  "string_index_invalid_utf8",
  // The ASCII flag a string carries is set by the runtime natively and read
  // through the host on the VM: `len`, `s[i]` and slices must agree.
  "string_ascii_index",
  // A distinct's own `Equals` answers whichever side of `==` it sits on.
  "distinct_equality_either_side",
  // Without an impl of its own, a distinct orders through its backing's.
  "distinct_orders_as_backing",
  // A distinct's own `Index` / `IndexSet` wins over its backing, trait by trait.
  "distinct_own_index",
  // A constant and a local bind one type parameter ; the instance the lowerer
  // picks keeps the first, and the code must not depend on it.
  "type_param_bound_by_constant_and_local",
  "generic_enum_same_name",
  // An enum with variant data stores its variant's rank : its value tables and
  // the conversion back to the written value, inside a generic instance too.
  "enum_variant_data_written_values",
  "generic_enum_argument",
  // Inlined generator instances keep their own variables: a mistyped slot read
  // only shows natively as a wrong number, where the VM traps.
  "fusion_same_generator_twice",
  "fusion_stages_change_type",
  "fusion_generic_generator_nested",
  // A generator's `return` leaves the block around its inlined body.
  "fusion_generator_return",
  // A consumer's `break` leaves the inlined instances, its `continue` resumes them.
  "fusion_consumer_break",
  "fusion_consumer_continue",
  // A combinator's own `break x` / `continue x`, from a loop nested in its loop.
  "fusion_stage_named_jumps",
  // `take(n)` pulls exactly `n` items, through `map`, `flat_map` and a generator.
  "fusion_take_exact",
  // A jump out of nested or unrolled loops runs the defers of each body it leaves.
  "defer_named_jump_nested_loop",
  // A `return` computes its value before the defers it leaves run.
  "defer_after_return_value",
  "comptime_for_jumps",
  // The lazy form of a chain: `Iterator` defaults on a generator's state, an
  // erased stage over a concrete tuple source, a local after a `yield`.
  "iterator_lazy_forms",
  "fusion_recursive_generator",
  // A free literal branch beside a concrete one: natively, a union of the two
  // compiled to a box read of a constant.
  "branch_literal_width",
  // A union-element const baked in `.rodata`: natively, every box carried the
  // union's tag and a number sat in the pointer slot.
  "union_array_const",
  // `x in coll` and `target[range]` evaluate their operands as written.
  "operand_order_in_slice",
  // A `defer` / lambda reading a `@comptime for` variable: natively, a SIGSEGV.
  "comptime_for_closures",
  // An alias declared below its use, across modules, or generic in a sibling file.
  "alias_declaration_order",
  // A push in a `for [x, y] in zip(a, b)` loop takes the push cache.
  "zip_loop_push",
  // `zip(a, b)` as a chain source, fused against the same chain bound lazily.
  "zip_source_fusion",
  // Any generator heading a chain — user generators, `window` — fused against the
  // same chain bound lazily.
  "generator_source_fusion",
  // A function consuming its `Iterator` parameter with one loop, inlined over a
  // chain — std's terminals and user functions — against the same chain bound
  // lazily.
  "iterator_consumers",
  // A destructured element of a layered chain, fused against lazy.
  "fusion_destructure_filtered",
  // An empty array filled by a counted loop, created at its trip count.
  "array_reserved_by_loop",
  // Three generators of one name, one of them imported, each with its own state
  // machine — fused, escaping, heading a chain, reached by UFCS.
  "generator_overloads",
  // `@displayable` enums rendered by name — a literal, a narrowed union, array
  // elements, generic instances — and a distinct that leaves its integer's slot.
  "enum_display",
  // Arrays and `null` rendered through `Display`, directly and from generics.
  "array_display",
  // A scalar compared with a union holding its type, `null` against a zero.
  "union_scalar_equality",
  // An overloaded call and a UFCS call run the fn typecheck chose, never one of a
  // module imported behind a namespace alias.
  "overload_import_scope",
  // A UFCS call in a generic body runs the fn typecheck chose against the type
  // parameter, in every instance.
  "ufcs_generic_receiver",
  // A free fn named like a field's fn value, or like std's `chars`, never runs
  // in their place.
  "free_fn_namesakes",
  // An `into` written as a generator on a non-generic impl, its iterator held as a
  // value: the body is the state machine, not a plain body that returns nothing.
  "into_generator_held_as_value",
  // `x is U` on a generic fn's own type parameter: natively the shared body compared
  // the `ref _` tag (false where the VM said true).
  "generic_is_type_param",
  // A widened array argument: natively an `i32[]` read as `(i32 | string)[]` took
  // its raw words for boxes; the widening kept here reads boxes as boxes.
  "array_union_literal_ok",
  // A `Circle[]` read as a `Shape[]` (trait) and as a `(Circle | null)[]`, one
  // array deeper too, and a struct literal taking a trait array's element.
  "array_argument_widened",
  // A pooled constant kept where a write may reach it is built again at the use,
  // natively too, where the shared one lies in `.rodata`.
  "const_copied_where_kept",
  // A variant's data bound to a name or kept in a field is copied, natively too,
  // where the shared table lies in `.rodata`.
  "enum_variant_data_copy",
  // A free literal stored into an `i64 | …` union is an `i64`, so `is i64` holds
  // natively as on the VM.
  "literal_into_wide_union",
  // A bound naming its trait's arguments is met by a defaulted or a written impl,
  // whatever rights the argument carries.
  "bound_with_arguments",
  // `+%` / `-%` / `*%` at every width, run time and folded constants alike.
  "wrapping_operators",
  // A `-` written against a number literal belongs to it, postfixes included.
  "negative_literals",
  // A range pattern's bounds at the scrutinee's type, a union's variant tested
  // first.
  "match_range_pattern_bounds",
  // `x in lo..=hi` with bounds at the type of `x`, and a free element at the
  // container's.
  "in_range_element",
  // An inclusive counted loop up to its type's maximum stops instead of wrapping.
  "range_to_type_max",
  // A `Range` value iterated up to its type's maximum stops instead of trapping.
  "range_value_to_type_max",
  // A deferred block's write between two reads of an element reaches the second.
  "defer_write_between_array_reads",
  // A struct with fields spelled `_0`, `_1` is read by name and written like any
  // other.
  "struct_fields_named_like_tuple",
  // An enum with a written width crosses `@extern` as the integer its variant
  // stores.
  "extern_enum_param",
  // An enum with variant data crosses `@extern` as its written value, through a
  // function that converts the rank, a call through a fn value included.
  "extern_enum_data_param",
  // A free function named like an impl member keeps its own slot.
  "free_fn_named_like_impl_member",
  // ... and its own return type.
  "free_fn_namesake_keeps_its_return_type",
  // Two traits of one name, from two modules, implemented for one type.
  "two_traits_of_one_name",
  // An impl whose type parameters differ from its struct's in name or order.
  "impl_names_its_own_parameters",
  // An explicit type argument on a generic fn of another module.
  "explicit_type_argument_on_imported_fn",
  // Generic calls inside a generic body, bound by the result slot.
  "generic_call_inside_generic_body",
  // Written type arguments on every form of callee.
  "explicit_type_arguments_on_members",
  // A lambda that reads a local only through a struct spread captures it.
  "lambda_spread_capture",
  // An `await` on the left of a `??` or in an interpolation makes a coroutine.
  "async_await_in_value_positions",
  // An `await` in an `else if` condition, a match arm or a value block.
  "async_await_in_branches",
  // A `yield` in a binding's value or in an argument block makes a generator.
  "generator_yield_in_value",
  // Two modules' same-named types name apart every instance and impl member.
  "same_name_types_from_two_modules",
  // An inlined generator of another module keeps its captured counter in a cell.
  "inlined_generator_captured_counter",
  // Declaration-shape snippets whose `main` runs what they declare.
  "decorators_ok",
  "expressions",
  "if_branches",
  "interp_display",
  "interp_string",
  "match_expr",
  "numerics",
  "strings",
  "struct_decl",
  "trait_impl",
]);

/// Snippets whose C cannot COMPILE on Windows, so the run cannot judge parity.
///
/// `c_struct_prefix_mirror` mirrors `struct timeval.tv_sec` as 8 bytes, which is
/// `time_t` on POSIX and `long` — 32 bits — under mingw on Win64. Its own
/// `_Static_assert` catches that, correctly: a type whose width differs between
/// systems takes one mirror per system, and this one is the POSIX mirror.
/// `tests/vader_vm.test.ts` excludes it from the VM half for its own reason.
const C_PARITY_UNAVAILABLE_WIN32 = new Set(["c_struct_prefix_mirror"]);

const allowed = listSnippets("tests/snippets").filter((s) => C_PARITY.has(s.name));

// What actually runs here. The allowlist check below deliberately reads
// `allowed`, not this: its job is to catch a name in `C_PARITY` that matches no
// snippet — a typo, or a renamed directory — and a platform skip must not look
// like one.
const scenarios = allowed.filter(
  (s) => !(process.platform === "win32" && C_PARITY_UNAVAILABLE_WIN32.has(s.name)),
);

test("c-emit: allowlist resolves to real snippets", () => {
  expect(allowed.length).toBe(C_PARITY.size);
});

for (const s of scenarios) {
  // Oracle 1 — regression vs the Vader-generated golden.
  //
  // Pinned to ONE target. A `@target` group in the closure (`std/io::write_bytes`
  // since println went through the FFI) makes the emitted C differ per platform,
  // so a snapshot taken on the contributor's machine could never match another's
  // — CI saw a 12-entry type table where macOS wrote 11. The target is the
  // snapshot's identity, not the machine's. Oracle 2 below deliberately does NOT
  // pin: it compiles and runs the C, which only works for the host.
  test.concurrent(`c-emit-snapshot: ${s.name}`, async () => {
    const dump = await runCli(["dump", "--stage=c", `--target=${SNAPSHOT_TARGET}`, s.mainPath]);
    const cmp = snapshotEquals(s.dir, C_SNAPSHOT, dump.stdout);
    if (!cmp.ok) {
      throw new Error(
        `${C_SNAPSHOT} mismatch: ${s.name}\n  snap: ${cmp.snapPath}\n` +
        `  Run with UPDATE_SNAPSHOTS=1 to refresh.\n\n` +
        snapshotDiff(cmp.snapPath, cmp.expected ?? "", dump.stdout),
      );
    }
  }, { timeout: LONG_BUILD });

  // Oracle 2 — the emitted C compiles + runs, matching vm.snapshot. Under
  // `VADER_VERIFY_BOUNDS` the build runs the range analysis and an access it
  // proves in bounds keeps its check under a message of its own, so a wrong
  // proof fails here instead of reading out of bounds in a release build.
  test.concurrent(`c-emit-run: ${s.name}`, async () => {
    if (!CC_AVAILABLE) return;
    const dump = await runCli(["dump", "--stage=c", s.mainPath], { VADER_VERIFY_BOUNDS: "1" });
    const cFile = join(tmpdir(), `vader-cemit-${s.name}.c`);
    const binFile = join(tmpdir(), `vader-cemit-${s.name}${EXE_SUFFIX}`);
    writeFileSync(cFile, dump.stdout);

    const build = Bun.spawn([
      // The include flags `vader build` passes (`push_include_flags`): a quoted
      // `@c_header` resolves beside the snippet's `_main.vader`.
      CC, "-std=c11", "-O0", "-fwrapv", "-I", RUNTIME_ROOT, "-iquote", RUNTIME_ROOT, "-iquote", s.dir,
      cFile, join(RUNTIME_ROOT, "vader_runtime.c"),
      // `@extern` snippets carry their foreign symbols in helper `.c`
      // files next to `_main.vader` — compile them into the binary.
      ...s.helperCFiles,
      "-o", binFile, "-lm",
    ], { stderr: "pipe", stdout: "pipe" });
    const buildErr = await new Response(build.stderr).text();
    if ((await build.exited) !== 0) {
      throw new Error(`c-emit-run: cc failed for ${s.name}\n${buildErr}`);
    }

    const runProc = Bun.spawn([binFile], { cwd: process.cwd(), stdout: "pipe", stderr: "pipe" });
    const killTimer = setTimeout(() => runProc.kill("SIGKILL"), 60_000);
    let stdout: string, stderr: string, runExit: number;
    try {
      stdout = await new Response(runProc.stdout).text();
      stderr = await new Response(runProc.stderr).text();
      runExit = await runProc.exited;
    } finally {
      clearTimeout(killTimer);
    }

    // A `C_PARITY` entry is listed to be run: a `vm.snapshot` that records no run
    // fails here instead of turning the comparison into a skip.
    const snapPath = join(s.dir, "vm.snapshot");
    if (!existsSync(snapPath) || expectsCompileErrors(s.dir)) {
      throw new Error(`c-emit-run: ${s.name} is in C_PARITY but its vm.snapshot records no run`);
    }
    const expected = readFileSync(snapPath, "utf8");

    const actual = formatRun(stdout, stderr, runExit);
    if (actual !== expected) {
      throw new Error(
        `c-emit run mismatch: ${s.name}\n  bin: ${binFile}\n\n` +
        snapshotDiff("vm.snapshot", expected, actual),
      );
    }
  }, { timeout: LONG_BUILD });
}
