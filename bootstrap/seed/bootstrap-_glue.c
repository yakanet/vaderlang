#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_233(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_233 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_233, NULL };
vader_box_t vader_fn_tramp_234(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_234 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_234, NULL };
vader_box_t vader_fn_tramp_481(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_481 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_481, NULL };
vader_box_t vader_fn_tramp_701(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_701 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_701, NULL };
vader_box_t vader_fn_tramp_703(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_703 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_703, NULL };
vader_box_t vader_fn_tramp_705(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_705 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_705, NULL };
vader_box_t vader_fn_tramp_706(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_706 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_706, NULL };
vader_box_t vader_fn_tramp_950(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_950 = { { 153u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_950, NULL };
vader_box_t vader_fn_tramp_1032(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1032 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1032, NULL };
vader_box_t vader_fn_tramp_1033(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1033 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1033, NULL };
vader_box_t vader_fn_tramp_1035(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1035 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1035, NULL };
vader_box_t vader_fn_tramp_1036(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1036 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1036, NULL };
vader_box_t vader_fn_tramp_1037(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1037 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1037, NULL };
vader_box_t vader_fn_tramp_1038(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1038 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1038, NULL };
vader_box_t vader_fn_tramp_1039(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1039 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1039, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1041 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1043 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1045(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1045 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1045, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(164u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1149(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1149 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1149, NULL };
vader_box_t vader_fn_tramp_1183(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1183 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1183, NULL };
vader_box_t vader_fn_tramp_1282(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1282 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1282, NULL };
vader_box_t vader_fn_tramp_2385(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2385 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2385, NULL };
vader_box_t vader_fn_lift_225(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_315(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_285(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1873(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_299(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2692(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_452(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_1923(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_565(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3722(env, a0, a1));
}
vader_box_t vader_fn_lift_959(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2124(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1068(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_5229(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1086(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_201(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1087(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_204(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1113(void* env, vader_box_t a0) {
    __lambda_1529(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1284(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_4148(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1750(void* env, vader_box_t a0) {
    __lambda_1654(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1751(void* env, vader_box_t a0) {
    __lambda_1657(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1756(void* env) {
    return vader_ref_box(__lambda_1741(env));
}
vader_box_t vader_fn_lift_1759(void* env) {
    return vader_ref_box(__lambda_1759(env));
}
vader_box_t vader_fn_lift_1771(void* env, vader_box_t a0) {
    __lambda_2573(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1773(void* env, vader_box_t a0) {
    __lambda_2582(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1775(void* env, vader_box_t a0) {
    __lambda_2589(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1776(void* env, vader_box_t a0) {
    __lambda_2592(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1777(void* env) {
    return vader_ref_box(__lambda_2598(env));
}
vader_box_t vader_fn_lift_1778(void* env) {
    return vader_ref_box(__lambda_2601(env));
}
vader_box_t vader_fn_lift_1780(void* env, vader_box_t a0) {
    __lambda_2622(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1781(void* env, vader_box_t a0) {
    __lambda_2630(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1782(void* env, vader_box_t a0) {
    __lambda_2633(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2133(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3331(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2456(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_5808(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2525(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(158u, __lambda_3085(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2526(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3088(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2527(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3091(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2528(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3094(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2529(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3097(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2530(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3100(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2531(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3103(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2532(void* env, vader_box_t a0) {
    return vader_box_f64(158u, __lambda_3106(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2533(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3114(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2534(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3117(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2535(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3120(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2536(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3123(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 161u);
    return (int) vader_bootstrap_main(__args);
}
