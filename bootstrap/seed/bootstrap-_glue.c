#include "bootstrap.split.h"

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    { 242u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = {
    { 254u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less = {
    { 254u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_resolver_0(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_0 = {
    { 243u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_resolver_1(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_1 = {
    { 260u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return __lambda_vader_typecheck_0(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_0 = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return __lambda_vader_typecheck_1(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_1 = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_1, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_expr(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_expr = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_expr, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_typecheck_is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_typecheck_is_free_numeric = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_in = {
    { 252u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_integral = {
    { 252u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_compare = {
    { 252u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_arith = {
    { 252u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_13(void* env) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_typecheck_13());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_13 = {
    { 234u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_17(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_typecheck_17(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_17 = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_19(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_typecheck_19(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_19 = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_19, NULL,
};

vader_box_t vader_fn_tramp_vader_types_carries_mutability_bit(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_types_carries_mutability_bit(a0));
}

vader_fn_t vader_fn_static_vader_types_carries_mutability_bit = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_carries_mutability_bit, NULL,
};

vader_box_t vader_fn_tramp_vader_types_type_withholds_mutation(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_types_type_withholds_mutation(a0));
}

vader_fn_t vader_fn_static_vader_types_type_withholds_mutation = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_type_withholds_mutation, NULL,
};

vader_box_t vader_fn_tramp_vader_types_type_may_grant_mutation(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_types_type_may_grant_mutation(a0));
}

vader_fn_t vader_fn_static_vader_types_type_may_grant_mutation = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_type_may_grant_mutation, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_evaluate_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_comptime_evaluate_expr = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_evaluate_expr, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_comptime_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_0 = {
    { 253u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_0, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mul = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_sub = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_add = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_or = {
    { 241u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_and = {
    { 241u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_or = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_and = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shr = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shl = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(276u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mod = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_comptime_1(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_1 = {
    { 243u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_1, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = {
    { 258u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_lower_block(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3));
}

vader_fn_t vader_fn_static_vader_lower_lower_block = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_block, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_lower_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}

vader_fn_t vader_fn_static_vader_lower_lower_expr = {
    { 257u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_expr, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_9(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_lower_9(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_lower_9 = {
    { 243u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_9, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_lower_is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower_is_defer = {
    { 264u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_8());
}

vader_fn_t vader_fn_static___lambda_vader_midir_8 = {
    { 232u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_13());
}

vader_fn_t vader_fn_static___lambda_vader_midir_13 = {
    { 238u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_14());
}

vader_fn_t vader_fn_static___lambda_vader_midir_14 = {
    { 238u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_c_emit_2(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_c_emit_2(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_c_emit_2 = {
    { 243u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_c_emit_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    { 242u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_0(void* env) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_vm_0());
}

vader_fn_t vader_fn_static___lambda_vader_vm_0 = {
    { 234u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_3(void* env) {
    (void) env;
    return __lambda_vader_vm_3();
}

vader_fn_t vader_fn_static___lambda_vader_vm_3 = {
    { 240u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_effects_0 = {
    { 239u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_1(void* env) {
    (void) env;
    return vader_box_i64(276u, __lambda_vader_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_effects_1 = {
    { 237u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_2(void* env) {
    (void) env;
    return vader_box_i64(276u, __lambda_vader_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_effects_2 = {
    { 237u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_5(void* env) {
    (void) env;
    return vader_box_i32(275u, __lambda_vader_effects_5());
}

vader_fn_t vader_fn_static___lambda_vader_effects_5 = {
    { 236u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_8());
}

vader_fn_t vader_fn_static___lambda_vader_effects_8 = {
    { 239u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_11());
}

vader_fn_t vader_fn_static___lambda_vader_effects_11 = {
    { 239u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_12());
}

vader_fn_t vader_fn_static___lambda_vader_effects_12 = {
    { 239u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_12, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_no_roots(void* env) {
    (void) env;
    return vader_ref_box(vader_effects_no_roots());
}

vader_fn_t vader_fn_static_vader_effects_no_roots = {
    { 233u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_no_roots, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_effects_is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_kept = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_30(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, __lambda_vader_effects_30(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_effects_30 = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_30, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_effects_modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_modifies = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_effects_is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_unknown = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_unknown, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(270u, vader_effects_escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_escapes = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_escapes, NULL,
};

vader_box_t vader_fn_lift___defer_std_io_0(void* env) {
    __defer_std_io_0(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_2(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_2(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_5(void* env, vader_box_t a0) {
    return vader_box_bool(270u, __lambda_vader_typecheck_5(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_7(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(270u, __lambda_vader_typecheck_7(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
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
    return vader_box_bool(270u, __lambda_vader_lower_14(env, a0));
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
    return vader_box_bool(270u, __lambda_vader_c_emit_0(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_fixpoint_0(void* env, vader_box_t a0) {
    return vader_box_bool(270u, __lambda_vader_fixpoint_0(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(270u, __lambda_vader_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_24(void* env, vader_box_t a0) {
    return vader_box_bool(270u, __lambda_vader_effects_24(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_28(void* env, vader_box_t a0) {
    return vader_box_bool(270u, __lambda_vader_effects_28(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_33(void* env, vader_box_t a0) {
    return vader_box_bool(270u, __lambda_vader_effects_33(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(270u, __lambda_vader_c_emit_c_ast_0(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_const_frame;
    vader_atom_roots_register(vader_global_const_arrays, 1u);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 14u, 272u);
    return (int) vader_bootstrap_main(__args);
}
