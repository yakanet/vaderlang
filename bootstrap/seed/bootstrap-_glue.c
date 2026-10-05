#include "bootstrap.split.h"

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(222u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    { 194u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = {
    { 206u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less = {
    { 206u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_resolver_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_0 = {
    { 211u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_resolver_1(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_1 = {
    { 195u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return __lambda_vader_typecheck_0(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_0 = {
    { 210u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_0, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_expr(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_expr = {
    { 214u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_expr, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_in = {
    { 204u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_bitwise(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_bitwise = {
    { 204u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_bitwise, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_compare = {
    { 204u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_arith = {
    { 204u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_7(void* env) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_typecheck_7());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_7 = {
    { 189u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_7, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_trait = {
    { 210u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_trait, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_evaluate_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_comptime_evaluate_expr = {
    { 213u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_evaluate_expr, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_comptime_0(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_0 = {
    { 205u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_0, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_or = {
    { 193u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_and = {
    { 193u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_or = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_and = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shr = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shl = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mod = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_div(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_div = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_div, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mul = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_sub = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(228u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_add = {
    { 201u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_1(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_comptime_1(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_1 = {
    { 195u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_1, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = {
    { 209u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_lower_block(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3));
}

vader_fn_t vader_fn_static_vader_lower_lower_block = {
    { 207u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_block, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_lower_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}

vader_fn_t vader_fn_static_vader_lower_lower_expr = {
    { 208u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_expr, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_9(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_lower_9(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_lower_9 = {
    { 195u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_9, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(222u, vader_lower_is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower_is_defer = {
    { 215u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_8(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_8());
}

vader_fn_t vader_fn_static___lambda_vader_midir_8 = {
    { 188u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_8, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_13());
}

vader_fn_t vader_fn_static___lambda_vader_midir_13 = {
    { 191u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_14(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_14());
}

vader_fn_t vader_fn_static___lambda_vader_midir_14 = {
    { 191u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_14, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_c_emit_2(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_c_emit_2(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_c_emit_2 = {
    { 195u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_c_emit_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(222u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    { 194u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_0(void* env) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_vm_0());
}

vader_fn_t vader_fn_static___lambda_vader_vm_0 = {
    { 189u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_3(void* env) {
    (void) env;
    return __lambda_vader_vm_3();
}

vader_fn_t vader_fn_static___lambda_vader_vm_3 = {
    { 192u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_3, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_4(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_vm_4(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_vm_4 = {
    { 200u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_5(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_vm_5(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_vm_5 = {
    { 200u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_6(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_vm_6(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_vm_6 = {
    { 195u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_7(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(222u, __lambda_vader_vm_7(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_vm_7 = {
    { 195u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_7, NULL,
};

vader_box_t vader_fn_lift___defer_std_io_0(void* env) {
    __defer_std_io_0(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_2(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(222u, __lambda_vader_typecheck_2(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
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
    return vader_box_bool(222u, __lambda_vader_lower_14(env, a0));
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
    return vader_box_bool(222u, __lambda_vader_c_emit_0(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(222u, __lambda_vader_c_emit_c_ast_0(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}

/* vtable dispatchers */
vader_string_t vader_vt_std_core_Display__to_string(vader_box_t recv) {
    switch (recv.tag) {
        case 218u: return std_core_i8_Display_to_string(((int8_t) recv.payload.i));
        case 219u: return std_core_i16_Display_to_string(((int16_t) recv.payload.i));
        case 227u: return std_core_i32_Display_to_string(((int32_t) recv.payload.i));
        case 228u: return std_core_i64_Display_to_string(((int64_t) recv.payload.i));
        case 229u: return std_core_isize_Display_to_string(((ptrdiff_t) recv.payload.i));
        case 230u: return std_core_u8_Display_to_string(((uint8_t) recv.payload.i));
        case 231u: return std_core_u16_Display_to_string(((uint16_t) recv.payload.i));
        case 232u: return std_core_u32_Display_to_string(((uint32_t) recv.payload.i));
        case 233u: return std_core_u64_Display_to_string(((uint64_t) recv.payload.i));
        case 234u: return std_core_usize_Display_to_string(((size_t) recv.payload.i));
        case 222u: return std_core_bool_Display_to_string(recv.payload.b);
        case 223u: return std_core_char_Display_to_string(((uint32_t) recv.payload.i));
        case 224u: return std_core_string_Display_to_string(recv.payload.s);
        case 0u: return std_core_null_Display_to_string(recv);
        case 220u: return std_core_f32_Display_to_string(((float) recv.payload.f));
        case 221u: return std_core_f64_Display_to_string(((double) recv.payload.f));
        case 395u: return std_string_builder_StringBuilder_Display_to_string(recv.payload.obj);
        case 489u: return toolchain_span_Span_Display_to_string(recv.payload.obj);
        case 1034u: return vader_vm_FnVal_Display_to_string(recv.payload.obj);
        case 1041u: return vader_vm_NullVal_Display_to_string(recv.payload.obj);
        case 1033u: return vader_vm_ErrorVal_Display_to_string(recv.payload.obj);
        case 1058u: return vader_vm_TypeVal_Display_to_string(recv.payload.obj);
        case 1042u: return vader_vm_ObjVal_Display_to_string(recv.payload.obj);
        case 1054u: return vader_vm_StructVal_Display_to_string(recv.payload.obj);
        case 1029u: return vader_vm_ArrayVal_Display_to_string(recv.payload.obj);
        default: vader_unreachable("vtable miss in std_core$Display.to_string");
    }
    vader_unreachable("vtable miss in std_core$Display.to_string");
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_const_frame;
    vader_atom_roots_register(vader_global_const_arrays, 1u);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 224u);
    return (int) vader_bootstrap_main(__args);
}
