#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_std_string_compare_ascending(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, std_string_compare_ascending(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static_std_string_compare_ascending = {
    { 289u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_std_string_compare_ascending, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_path_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, __lambda_std_path_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_path_0 = {
    { 287u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_path_0, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = {
    { 301u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL,
};

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_diagnostics_diag_less = {
    { 301u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_resolver_0(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_0 = {
    { 289u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_1(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_resolver_1());
}

vader_fn_t vader_fn_static___lambda_vader_resolver_1 = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_2(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_resolver_2(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_resolver_2 = {
    { 305u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_resolver_4(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_resolver_4());
}

vader_fn_t vader_fn_static___lambda_vader_resolver_4 = {
    { 264u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_resolver_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_10());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_10 = {
    { 261u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_11());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_11 = {
    { 275u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_12());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_12 = {
    { 258u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_13(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_13());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_13 = {
    { 267u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_13, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_16(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_16());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_16 = {
    { 266u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_16, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_17(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_17());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_17 = {
    { 269u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_17, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_28(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_28());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_28 = {
    { 265u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_28, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_29(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_29());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_29 = {
    { 268u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_29, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_is_free_numeric(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, vader_typecheck_is_free_numeric(a0));
}

vader_fn_t vader_fn_static_vader_typecheck_is_free_numeric = {
    { 311u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_is_free_numeric, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_35(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_typecheck_35(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_35 = {
    { 296u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_35, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_in = {
    { 299u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_integral(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_integral(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_integral = {
    { 299u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_integral, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_compare = {
    { 299u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL,
};

vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}

vader_fn_t vader_fn_static_vader_typecheck_check_arith = {
    { 299u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_38(void* env) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_typecheck_38());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_38 = {
    { 270u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_38, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_67(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_typecheck_67(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_67 = {
    { 311u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_67, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_69(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_typecheck_69(a0));
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_69 = {
    { 311u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_69, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_70(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_70());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_70 = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_70, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_typecheck_71(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_typecheck_71());
}

vader_fn_t vader_fn_static___lambda_vader_typecheck_71 = {
    { 259u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_typecheck_71, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_struct(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_struct(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_struct = {
    { 304u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_struct, NULL,
};

vader_box_t vader_fn_tramp_vader_types_mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}

vader_fn_t vader_fn_static_vader_types_mk_trait = {
    { 304u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_trait, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_display_key_before(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, vader_comptime_display_key_before(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_comptime_display_key_before = {
    { 300u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_display_key_before, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mul = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_sub = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_add = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_or = {
    { 286u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_comptime_op_and = {
    { 286u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_or = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_bit_and = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shr = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_shl = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(321u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_comptime_op_mod = {
    { 297u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_comptime_0(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_comptime_0(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_comptime_0 = {
    { 289u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_comptime_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_0());
}

vader_fn_t vader_fn_static___lambda_vader_lower_0 = {
    { 264u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_7(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_lower_7());
}

vader_fn_t vader_fn_static___lambda_vader_lower_7 = {
    { 278u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_7, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = {
    { 303u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_lower_11(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_lower_11(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_lower_11 = {
    { 289u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_lower_11, NULL,
};

vader_box_t vader_fn_tramp_vader_lower_is_defer(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, vader_lower_is_defer(a0));
}

vader_fn_t vader_fn_static_vader_lower_is_defer = {
    { 309u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_is_defer, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_6(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_6());
}

vader_fn_t vader_fn_static___lambda_vader_midir_6 = {
    { 260u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_6, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_11());
}

vader_fn_t vader_fn_static___lambda_vader_midir_11 = {
    { 281u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_midir_12(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_midir_12());
}

vader_fn_t vader_fn_static___lambda_vader_midir_12 = {
    { 281u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_midir_12, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_c_emit_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_c_emit_0());
}

vader_fn_t vader_fn_static___lambda_vader_c_emit_0 = {
    { 260u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_c_emit_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_c_emit_5(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_c_emit_5(a0.payload.s, a1.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_c_emit_5 = {
    { 289u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_c_emit_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_parser_4(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(317u, __lambda_vader_parser_4(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_parser_4 = {
    { 288u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_parser_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_parser_5(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_string(317u, __lambda_vader_parser_5(a0.payload.s));
}

vader_fn_t vader_fn_static___lambda_vader_parser_5 = {
    { 288u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_parser_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_fixpoint_0(void* env) {
    (void) env;
    return vader_box_i32(320u, __lambda_vader_fixpoint_0());
}

vader_fn_t vader_fn_static___lambda_vader_fixpoint_0 = {
    { 273u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_fixpoint_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_std_numbers_0(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, __lambda_std_numbers_0(((uint32_t) a0.payload.i)));
}

vader_fn_t vader_fn_static___lambda_std_numbers_0 = {
    { 287u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_std_numbers_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_2(void* env) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_vm_2());
}

vader_fn_t vader_fn_static___lambda_vader_vm_2 = {
    { 270u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_vm_5(void* env) {
    (void) env;
    return __lambda_vader_vm_5();
}

vader_fn_t vader_fn_static___lambda_vader_vm_5 = {
    { 285u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_vm_5, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_0(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_0());
}

vader_fn_t vader_fn_static___lambda_vader_effects_0 = {
    { 282u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_0, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_1(void* env) {
    (void) env;
    return vader_box_i64(321u, __lambda_vader_effects_1());
}

vader_fn_t vader_fn_static___lambda_vader_effects_1 = {
    { 274u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_1, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_2(void* env) {
    (void) env;
    return vader_box_i64(321u, __lambda_vader_effects_2());
}

vader_fn_t vader_fn_static___lambda_vader_effects_2 = {
    { 274u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_2, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_9(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_9());
}

vader_fn_t vader_fn_static___lambda_vader_effects_9 = {
    { 282u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_9, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_10(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_10());
}

vader_fn_t vader_fn_static___lambda_vader_effects_10 = {
    { 282u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_10, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_11(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_11());
}

vader_fn_t vader_fn_static___lambda_vader_effects_11 = {
    { 263u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_11, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_21(void* env) {
    (void) env;
    return vader_ref_box(__lambda_vader_effects_21());
}

vader_fn_t vader_fn_static___lambda_vader_effects_21 = {
    { 262u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_21, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_kept(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, vader_effects_is_kept(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_kept = {
    { 302u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_kept, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_effects_29(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, __lambda_vader_effects_29(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_effects_29 = {
    { 302u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp___lambda_vader_effects_29, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_modifies(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, vader_effects_modifies(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_modifies = {
    { 302u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_modifies, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_is_unknown(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, vader_effects_is_unknown(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_is_unknown = {
    { 302u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_is_unknown, NULL,
};

vader_box_t vader_fn_tramp_vader_effects_escapes(void* env, vader_box_t a0) {
    (void) env;
    return vader_box_bool(315u, vader_effects_escapes(a0.payload.obj));
}

vader_fn_t vader_fn_static_vader_effects_escapes = {
    { 302u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_effects_escapes, NULL,
};

vader_box_t vader_fn_lift___defer_std_io_0(void* env) {
    __defer_std_io_0(env);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_0(void* env) {
    return vader_ref_box(__lambda_vader_typecheck_0(env));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_2(void* env) {
    return vader_ref_box(__lambda_vader_typecheck_2(env));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_4(void* env) {
    return vader_ref_box(__lambda_vader_typecheck_4(env));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_6(void* env) {
    return vader_ref_box(__lambda_vader_typecheck_6(env));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_8(void* env) {
    return vader_ref_box(__lambda_vader_typecheck_8(env));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_14(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_14(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_20(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_20(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_22(void* env, vader_box_t a0) {
    return vader_box_i32(322u, (int32_t)(uint32_t) __lambda_vader_typecheck_22(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_24(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(315u, __lambda_vader_typecheck_24(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_26(void* env, vader_box_t a0) {
    return vader_box_i32(322u, (int32_t)(uint32_t) __lambda_vader_typecheck_26(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_30(void* env) {
    return __lambda_vader_typecheck_30(env);
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_32(void* env) {
    return __lambda_vader_typecheck_32(env);
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_36(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_typecheck_36(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_42(void* env, vader_box_t a0) {
    return vader_box_i32(322u, (int32_t)(uint32_t) __lambda_vader_typecheck_42(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_44(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_44(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_46(void* env, vader_box_t a0) {
    __lambda_vader_typecheck_46(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_typecheck_56(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_typecheck_56(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_1(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_1(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_3(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_3(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_5(void* env, vader_box_t a0) {
    __lambda_vader_lower_5(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_8(void* env, vader_box_t a0) {
    __lambda_vader_lower_8(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_12(void* env) {
    return vader_box_string(317u, __lambda_vader_lower_12(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_14(void* env, vader_box_t a0) {
    __lambda_vader_lower_14(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_16(void* env, vader_box_t a0) {
    __lambda_vader_lower_16(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_18(void* env, vader_box_t a0) {
    __lambda_vader_lower_18(env, a0);
    return vader_box_null();
}

vader_box_t vader_fn_lift___lambda_vader_lower_21(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_lower_21(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_lower_23(void* env) {
    return vader_ref_box(__lambda_vader_lower_23(env));
}

vader_box_t vader_fn_lift___lambda_vader_lower_25(void* env) {
    return vader_ref_box(__lambda_vader_lower_25(env));
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

vader_box_t vader_fn_lift___lambda_vader_c_emit_1(void* env, vader_box_t a0) {
    return vader_ref_box(__lambda_vader_c_emit_1(env, ((int64_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_3(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(315u, __lambda_vader_c_emit_3(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_parser_0(void* env, vader_box_t a0) {
    return vader_box_string(317u, __lambda_vader_parser_0(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_parser_2(void* env, vader_box_t a0) {
    return vader_box_string(317u, __lambda_vader_parser_2(env, a0.payload.s));
}

vader_box_t vader_fn_lift___lambda_vader_fixpoint_1(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_fixpoint_1(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_3(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_effects_3(env, ((int32_t) a0.payload.i)));
}

vader_box_t vader_fn_lift___lambda_vader_effects_23(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_effects_23(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_27(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_effects_27(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_effects_34(void* env, vader_box_t a0) {
    return vader_box_bool(315u, __lambda_vader_effects_34(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_c_emit_c_ast_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(315u, __lambda_vader_c_emit_c_ast_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_frame;
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 21u, 317u);
    return (int) vader_bootstrap_main(__args);
}
