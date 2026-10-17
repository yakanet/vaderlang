#include "bootstrap.split.h"

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = {
    { 261u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less = {
    { 261u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_resolver_0(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_0 = {
    { 250u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_resolver_1(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_1 = {
    { 267u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_1, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_expr(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_expr = {
    { 271u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_expr, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, vader_typecheck_is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_typecheck_is_free_numeric = {
    { 274u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_15(void* env) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_typecheck_15());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_15 = {
    { 241u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_15, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_in = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_integral = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_compare = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_arith = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_37(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_typecheck_37(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_37 = {
    { 274u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_37, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_39(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_typecheck_39(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_39 = {
    { 274u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_39, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_struct(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_struct(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_struct = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_struct, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_trait = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_trait, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_evaluate_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_comptime_evaluate_expr = {
    { 270u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_evaluate_expr, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_comptime_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_0 = {
    { 260u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_0, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mul = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_sub = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_add = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_or = {
    { 248u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_and = {
    { 248u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_or = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_and = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shr = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shl = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(286u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mod = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_comptime_1(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_1 = {
    { 250u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_1, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = {
    { 265u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_lower_block(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3));
}

vader_fn_t vader_fn_static_vader_lower_lower_block = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_block, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_lower_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}

vader_fn_t vader_fn_static_vader_lower_lower_expr = {
    { 264u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_expr, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_9(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_lower_9(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_lower_9 = {
    { 250u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_9, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, vader_lower_is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower_is_defer = {
    { 272u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_8());
}

vader_fn_t vader_fn_static___lambda_vader_midir_8 = {
    { 239u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_13());
}

vader_fn_t vader_fn_static___lambda_vader_midir_13 = {
    { 245u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_14());
}

vader_fn_t vader_fn_static___lambda_vader_midir_14 = {
    { 245u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_c_emit_2(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_c_emit_2(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_c_emit_2 = {
    { 250u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_c_emit_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_fixpoint_0(void* env) {
    (void) env;
    return vader_box_i32(285u, __lambda_vader_fixpoint_0());
}

vader_fn_t vader_fn_static___lambda_vader_fixpoint_0 = {
    { 243u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_fixpoint_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_2(void* env) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_vm_2());
}

vader_fn_t vader_fn_static___lambda_vader_vm_2 = {
    { 241u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_5(void* env) {
    (void) env;
    return __lambda_vader_vm_5();
}

vader_fn_t vader_fn_static___lambda_vader_vm_5 = {
    { 247u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_effects_0 = {
    { 246u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_1(void* env) {
    (void) env;
    return vader_box_i64(286u, __lambda_vader_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_effects_1 = {
    { 244u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_2(void* env) {
    (void) env;
    return vader_box_i64(286u, __lambda_vader_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_effects_2 = {
    { 244u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_7(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_7());
}

vader_fn_t vader_fn_static___lambda_vader_effects_7 = {
    { 246u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_7, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_10());
}

vader_fn_t vader_fn_static___lambda_vader_effects_10 = {
    { 246u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_11());
}

vader_fn_t vader_fn_static___lambda_vader_effects_11 = {
    { 246u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_11, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_no_roots(void* env) {
    (void) env;
    return vader_ref_box(vader_effects_no_roots());
}

vader_fn_t vader_fn_static_vader_effects_no_roots = {
    { 240u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_no_roots, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, vader_effects_is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_kept = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_30(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, __lambda_vader_effects_30(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_effects_30 = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_30, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, vader_effects_modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_modifies = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, vader_effects_is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_unknown = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_unknown, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(280u, vader_effects_escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_escapes = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_escapes, NULL,
};

vader_box_t vader_fn_lift___defer_std_io_0(void* env) {
    __defer_std_io_0(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_0(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_0(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_2(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_2(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_4(void* env, vader_box_t a0) {
    return vader_box_i32(288u, (int32_t)(uint32_t) __lambda_vader_typecheck_4(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_7(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(280u, __lambda_vader_typecheck_7(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_11(void* env, vader_box_t a0) {
    return vader_box_i32(288u, (int32_t)(uint32_t) __lambda_vader_typecheck_11(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_13(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_typecheck_13(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_18(void* env, vader_box_t a0) {
    return vader_box_i32(288u, (int32_t)(uint32_t) __lambda_vader_typecheck_18(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_28(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_typecheck_28(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_0(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_0(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_2(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_2(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_4(void* env, vader_box_t a0) {
    __lambda_vader_lower_4(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_6(void* env, vader_box_t a0) {
    __lambda_vader_lower_6(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_10(void* env, vader_box_t a0) {
    __lambda_vader_lower_10(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_12(void* env, vader_box_t a0) {
    __lambda_vader_lower_12(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_14(void* env, vader_box_t a0) {
    __lambda_vader_lower_14(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_16(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_lower_16(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_midir_0(void* env, vader_box_t a0) {
    __lambda_vader_midir_0(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_2(void* env, vader_box_t a0) {
    __lambda_vader_midir_2(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_4(void* env, vader_box_t a0) {
    __lambda_vader_midir_4(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_6(void* env, vader_box_t a0) {
    __lambda_vader_midir_6(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_9(void* env, vader_box_t a0) {
    __lambda_vader_midir_9(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_11(void* env, vader_box_t a0) {
    __lambda_vader_midir_11(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(280u, __lambda_vader_c_emit_0(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_fixpoint_1(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_fixpoint_1(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_24(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_effects_24(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_28(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_effects_28(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_35(void* env, vader_box_t a0) {
    return vader_box_bool(280u, __lambda_vader_effects_35(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(280u, __lambda_vader_c_emit_c_ast_0(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}

/* vtable dispatchers */
uint64_t vader_vt_std_core_Hash__hash(vader_box_t recv) {
    switch (recv.tag) {
        case 285u: return std_core_i32_Hash_hash(((int32_t) recv.payload.i));
        case 286u: return std_core_i64_Hash_hash(((int64_t) recv.payload.i));
        case 282u: return std_core_string_Hash_hash_vt(recv.payload.s);
        case 291u: return std_core_u64_Hash_hash(((uint64_t) recv.payload.i));
        case 292u: return std_core_usize_Hash_hash(((size_t) recv.payload.i));
        case 276u: return std_core_i8_Hash_hash(((int8_t) recv.payload.i));
        case 277u: return std_core_i16_Hash_hash(((int16_t) recv.payload.i));
        case 287u: return std_core_isize_Hash_hash(((ptrdiff_t) recv.payload.i));
        case 288u: return std_core_u8_Hash_hash(((uint8_t) recv.payload.i));
        case 289u: return std_core_u16_Hash_hash(((uint16_t) recv.payload.i));
        case 290u: return std_core_u32_Hash_hash(((uint32_t) recv.payload.i));
        case 281u: return std_core_char_Hash_hash(((uint32_t) recv.payload.i));
        case 610u: return toolchain_span_Span_std_core_Hash_hash(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Hash.hash");
    }
    vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool vader_vt_std_core_Equals__equals(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 285u: return std_core_i32_Equals_equals_guard(((int32_t) recv.payload.i), a0);
        case 286u: return std_core_i64_Equals_equals_guard(((int64_t) recv.payload.i), a0);
        case 282u: return std_core_string_Equals_equals_guard(recv.payload.s, a0);
        case 291u: return std_core_u64_Equals_equals_guard(((uint64_t) recv.payload.i), a0);
        case 292u: return std_core_usize_Equals_equals_guard(((size_t) recv.payload.i), a0);
        case 276u: return std_core_i8_Equals_equals_guard(((int8_t) recv.payload.i), a0);
        case 277u: return std_core_i16_Equals_equals_guard(((int16_t) recv.payload.i), a0);
        case 287u: return std_core_isize_Equals_equals_guard(((ptrdiff_t) recv.payload.i), a0);
        case 288u: return std_core_u8_Equals_equals_guard(((uint8_t) recv.payload.i), a0);
        case 289u: return std_core_u16_Equals_equals_guard(((uint16_t) recv.payload.i), a0);
        case 290u: return std_core_u32_Equals_equals_guard(((uint32_t) recv.payload.i), a0);
        case 278u: return std_core_f32_Equals_equals_guard(((float) recv.payload.f), a0);
        case 279u: return std_core_f64_Equals_equals_guard(((double) recv.payload.f), a0);
        case 280u: return std_core_bool_Equals_equals_guard(recv.payload.b, a0);
        case 281u: return std_core_char_Equals_equals_guard(((uint32_t) recv.payload.i), a0);
        case 610u: return toolchain_span_Span_std_core_Equals_equals_guard(recv.payload.obj, a0);
        default: vader_unreachable("vtable miss in std_core$Equals.equals");
    }
    vader_unreachable("vtable miss in std_core$Equals.equals");
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_frame;
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 15u, 282u);
    return (int) vader_bootstrap_main(__args);
}
