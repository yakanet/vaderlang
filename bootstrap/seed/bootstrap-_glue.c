#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_236(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_236 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_236, NULL };
vader_box_t vader_fn_tramp_237(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_237 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_237, NULL };
vader_box_t vader_fn_tramp_484(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_484 = { { 156u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_484, NULL };
vader_box_t vader_fn_tramp_705(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_705 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_705, NULL };
vader_box_t vader_fn_tramp_707(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_707 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_707, NULL };
vader_box_t vader_fn_tramp_709(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_709 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_709, NULL };
vader_box_t vader_fn_tramp_710(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_710 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_710, NULL };
vader_box_t vader_fn_tramp_956(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_956 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_956, NULL };
vader_box_t vader_fn_tramp_1038(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1038 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1038, NULL };
vader_box_t vader_fn_tramp_1039(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1039 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1039, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1041 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1042 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1043 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1044(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1044 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1044, NULL };
vader_box_t vader_fn_tramp_1045(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1045 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1045, NULL };
vader_box_t vader_fn_tramp_1047(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1047 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1047, NULL };
vader_box_t vader_fn_tramp_1049(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1049 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1049, NULL };
vader_box_t vader_fn_tramp_1051(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1051 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1051, NULL };
vader_box_t vader_fn_tramp_1052(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1052 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1052, NULL };
vader_box_t vader_fn_tramp_1054(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1054 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1054, NULL };
vader_box_t vader_fn_tramp_1155(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1155 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1155, NULL };
vader_box_t vader_fn_tramp_1189(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1189 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1189, NULL };
vader_box_t vader_fn_tramp_1289(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1289 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1289, NULL };
vader_box_t vader_fn_tramp_2417(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2417 = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2417, NULL };
vader_box_t vader_fn_lift_228(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_288(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1996(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_302(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2967(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_455(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2046(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_568(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3870(env, a0, a1));
}
vader_box_t vader_fn_lift_965(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2247(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1074(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_5380(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1092(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1093(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1119(void* env, vader_box_t a0) {
    __lambda_1646(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1291(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_4351(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1757(void* env, vader_box_t a0) {
    __lambda_1771(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1758(void* env, vader_box_t a0) {
    __lambda_1774(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1764(void* env) {
    return vader_ref_box(__lambda_1864(env));
}
vader_box_t vader_fn_lift_1767(void* env) {
    return vader_ref_box(__lambda_1882(env));
}
vader_box_t vader_fn_lift_1781(void* env, vader_box_t a0) {
    __lambda_2848(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1783(void* env, vader_box_t a0) {
    __lambda_2857(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1785(void* env, vader_box_t a0) {
    __lambda_2864(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1786(void* env, vader_box_t a0) {
    __lambda_2867(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1787(void* env) {
    return vader_ref_box(__lambda_2873(env));
}
vader_box_t vader_fn_lift_1788(void* env) {
    return vader_ref_box(__lambda_2876(env));
}
vader_box_t vader_fn_lift_1790(void* env, vader_box_t a0) {
    __lambda_2897(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1791(void* env, vader_box_t a0) {
    __lambda_2905(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1792(void* env, vader_box_t a0) {
    __lambda_2908(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2004(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1360(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2007(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1370(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2159(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2702(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2488(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_5954(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2557(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(160u, __lambda_3340(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2558(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3343(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2559(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3346(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2560(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3349(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2561(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3352(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2562(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3355(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2563(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3358(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2564(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3361(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2565(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3369(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2566(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3372(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2567(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3375(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2568(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3378(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 163u);
    return (int) vader_bootstrap_main(__args);
}
