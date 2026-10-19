#include "bootstrap.split.h"

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = {
    { 267u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less = {
    { 267u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_resolver_0(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_0 = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_resolver_1(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_1 = {
    { 271u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_1, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, vader_typecheck_is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_typecheck_is_free_numeric = {
    { 277u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_17(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_typecheck_17(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_17 = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_17, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_in = {
    { 265u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_integral = {
    { 265u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_compare = {
    { 265u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_arith = {
    { 265u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_22(void* env) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_typecheck_22());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_22 = {
    { 246u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_22, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_48(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_typecheck_48(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_48 = {
    { 277u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_48, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_50(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_typecheck_50(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_50 = {
    { 277u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_50, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_struct(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_struct(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_struct = {
    { 270u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_struct, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_trait = {
    { 270u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_trait, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_comptime_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_0 = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_0, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mul = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_sub = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_add = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_or = {
    { 254u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_and = {
    { 254u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_or = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_and = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shr = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shl = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(289u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mod = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_comptime_1(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_1 = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_1, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = {
    { 269u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_9(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_lower_9(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_lower_9 = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_9, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, vader_lower_is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower_is_defer = {
    { 275u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_6(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_6());
}

vader_fn_t vader_fn_static___lambda_vader_midir_6 = {
    { 245u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_11());
}

vader_fn_t vader_fn_static___lambda_vader_midir_11 = {
    { 250u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_12());
}

vader_fn_t vader_fn_static___lambda_vader_midir_12 = {
    { 250u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_c_emit_2(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_c_emit_2(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_c_emit_2 = {
    { 256u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_c_emit_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_fixpoint_0(void* env) {
    (void) env;
    return vader_box_i32(288u, __lambda_vader_fixpoint_0());
}

vader_fn_t vader_fn_static___lambda_vader_fixpoint_0 = {
    { 248u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_fixpoint_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    { 255u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_2(void* env) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_vm_2());
}

vader_fn_t vader_fn_static___lambda_vader_vm_2 = {
    { 246u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_5(void* env) {
    (void) env;
    return __lambda_vader_vm_5();
}

vader_fn_t vader_fn_static___lambda_vader_vm_5 = {
    { 253u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_effects_0 = {
    { 251u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_1(void* env) {
    (void) env;
    return vader_box_i64(289u, __lambda_vader_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_effects_1 = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_2(void* env) {
    (void) env;
    return vader_box_i64(289u, __lambda_vader_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_effects_2 = {
    { 249u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_9(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_9());
}

vader_fn_t vader_fn_static___lambda_vader_effects_9 = {
    { 251u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_9, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_10());
}

vader_fn_t vader_fn_static___lambda_vader_effects_10 = {
    { 251u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_10, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, vader_effects_is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_kept = {
    { 268u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_27(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, __lambda_vader_effects_27(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_effects_27 = {
    { 268u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_27, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, vader_effects_modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_modifies = {
    { 268u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, vader_effects_is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_unknown = {
    { 268u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_unknown, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(283u, vader_effects_escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_escapes = {
    { 268u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_escapes, NULL,
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
    return vader_box_i32(291u, (int32_t)(uint32_t) __lambda_vader_typecheck_2(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_6(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_6(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_8(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(283u, __lambda_vader_typecheck_8(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_10(void* env, vader_box_t a0) {
    return vader_box_i32(291u, (int32_t)(uint32_t) __lambda_vader_typecheck_10(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_12(void* env) {
    return __lambda_vader_typecheck_12(env);
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_14(void* env) {
    return __lambda_vader_typecheck_14(env);
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_18(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_typecheck_18(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_20(void* env, vader_box_t a0) {
    return vader_box_i32(291u, (int32_t)(uint32_t) __lambda_vader_typecheck_20(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_26(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_26(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_28(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_28(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_37(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_typecheck_37(env, a0));
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

vader_box_t vader_fn_lift___lambda_vader_lower_17(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_lower_17(env, a0));
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

vader_box_t vader_fn_lift___lambda_vader_midir_7(void* env, vader_box_t a0) {
    __lambda_vader_midir_7(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_midir_9(void* env, vader_box_t a0) {
    __lambda_vader_midir_9(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(283u, __lambda_vader_c_emit_0(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_fixpoint_1(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_fixpoint_1(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_21(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_effects_21(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_25(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_effects_25(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_30(void* env, vader_box_t a0) {
    return vader_box_bool(283u, __lambda_vader_effects_30(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(283u, __lambda_vader_c_emit_c_ast_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

/* vtable dispatchers */
uint64_t vader_vt_std_core_Hash__hash(vader_box_t recv) {
    switch (recv.tag) {
        case 288u: return std_core_i32_Hash_hash(((int32_t) recv.payload.i));
        case 289u: return std_core_i64_Hash_hash(((int64_t) recv.payload.i));
        case 285u: return std_core_string_Hash_hash_vt(recv.payload.s);
        case 294u: return std_core_u64_Hash_hash(((uint64_t) recv.payload.i));
        case 279u: return std_core_i8_Hash_hash(((int8_t) recv.payload.i));
        case 280u: return std_core_i16_Hash_hash(((int16_t) recv.payload.i));
        case 290u: return std_core_isize_Hash_hash(((ptrdiff_t) recv.payload.i));
        case 291u: return std_core_u8_Hash_hash(((uint8_t) recv.payload.i));
        case 292u: return std_core_u16_Hash_hash(((uint16_t) recv.payload.i));
        case 293u: return std_core_u32_Hash_hash(((uint32_t) recv.payload.i));
        case 295u: return std_core_usize_Hash_hash(((size_t) recv.payload.i));
        case 284u: return std_core_char_Hash_hash(((uint32_t) recv.payload.i));
        case 615u: return toolchain_span_Span_std_core_Hash_hash(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Hash.hash");
    }
    vader_unreachable("vtable miss in std_core$Hash.hash");
}

bool vader_vt_std_core_Equals__equals(vader_box_t recv, vader_box_t a0) {
    switch (recv.tag) {
        case 288u: return std_core_i32_Equals_equals_guard(((int32_t) recv.payload.i), a0);
        case 289u: return std_core_i64_Equals_equals_guard(((int64_t) recv.payload.i), a0);
        case 285u: return std_core_string_Equals_equals_guard(recv.payload.s, a0);
        case 294u: return std_core_u64_Equals_equals_guard(((uint64_t) recv.payload.i), a0);
        case 279u: return std_core_i8_Equals_equals_guard(((int8_t) recv.payload.i), a0);
        case 280u: return std_core_i16_Equals_equals_guard(((int16_t) recv.payload.i), a0);
        case 290u: return std_core_isize_Equals_equals_guard(((ptrdiff_t) recv.payload.i), a0);
        case 291u: return std_core_u8_Equals_equals_guard(((uint8_t) recv.payload.i), a0);
        case 292u: return std_core_u16_Equals_equals_guard(((uint16_t) recv.payload.i), a0);
        case 293u: return std_core_u32_Equals_equals_guard(((uint32_t) recv.payload.i), a0);
        case 295u: return std_core_usize_Equals_equals_guard(((size_t) recv.payload.i), a0);
        case 281u: return std_core_f32_Equals_equals_guard(((float) recv.payload.f), a0);
        case 282u: return std_core_f64_Equals_equals_guard(((double) recv.payload.f), a0);
        case 283u: return std_core_bool_Equals_equals_guard(recv.payload.b, a0);
        case 284u: return std_core_char_Equals_equals_guard(((uint32_t) recv.payload.i), a0);
        case 615u: return toolchain_span_Span_std_core_Equals_equals_guard(recv.payload.obj, a0);
        default: vader_unreachable("vtable miss in std_core$Equals.equals");
    }
    vader_unreachable("vtable miss in std_core$Equals.equals");
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_frame;
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 14u, 285u);
    return (int) vader_bootstrap_main(__args);
}
