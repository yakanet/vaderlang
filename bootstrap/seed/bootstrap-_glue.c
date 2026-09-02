#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_246(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_246 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_246, NULL };
vader_box_t vader_fn_tramp_247(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_247 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_247, NULL };
vader_box_t vader_fn_tramp_495(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_495 = { { 156u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_495, NULL };
vader_box_t vader_fn_tramp_720(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_720 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_720, NULL };
vader_box_t vader_fn_tramp_722(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_722 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_722, NULL };
vader_box_t vader_fn_tramp_724(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_724 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_724, NULL };
vader_box_t vader_fn_tramp_725(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_725 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_725, NULL };
vader_box_t vader_fn_tramp_973(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_973 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_973, NULL };
vader_box_t vader_fn_tramp_1055(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1055 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1055, NULL };
vader_box_t vader_fn_tramp_1056(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1056 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1056, NULL };
vader_box_t vader_fn_tramp_1058(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1058 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1058, NULL };
vader_box_t vader_fn_tramp_1059(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1059 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1059, NULL };
vader_box_t vader_fn_tramp_1060(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1060 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1060, NULL };
vader_box_t vader_fn_tramp_1061(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1061 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1061, NULL };
vader_box_t vader_fn_tramp_1062(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1062 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1062, NULL };
vader_box_t vader_fn_tramp_1064(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1064 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1064, NULL };
vader_box_t vader_fn_tramp_1066(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1066 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1066, NULL };
vader_box_t vader_fn_tramp_1068(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1068 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1068, NULL };
vader_box_t vader_fn_tramp_1069(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1069 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1069, NULL };
vader_box_t vader_fn_tramp_1071(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1071 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1071, NULL };
vader_box_t vader_fn_tramp_1172(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1172 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1172, NULL };
vader_box_t vader_fn_tramp_1206(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1206 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1206, NULL };
vader_box_t vader_fn_tramp_1306(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1306 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1306, NULL };
vader_box_t vader_fn_tramp_2449(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2449 = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2449, NULL };
vader_box_t vader_fn_lift_238(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_298(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2081(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_312(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3101(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_466(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2131(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_579(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3979(env, a0, a1));
}
vader_box_t vader_fn_lift_982(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2332(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1091(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_5517(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1109(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1110(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1136(void* env, vader_box_t a0) {
    __lambda_1729(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1308(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_4462(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1774(void* env, vader_box_t a0) {
    __lambda_1854(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1775(void* env, vader_box_t a0) {
    __lambda_1857(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1783(void* env) {
    return vader_ref_box(__lambda_1953(env));
}
vader_box_t vader_fn_lift_1786(void* env) {
    return vader_ref_box(__lambda_1971(env));
}
vader_box_t vader_fn_lift_1800(void* env, vader_box_t a0) {
    __lambda_2982(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1802(void* env, vader_box_t a0) {
    __lambda_2991(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1804(void* env, vader_box_t a0) {
    __lambda_2998(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1805(void* env, vader_box_t a0) {
    __lambda_3001(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1806(void* env) {
    return vader_ref_box(__lambda_3007(env));
}
vader_box_t vader_fn_lift_1807(void* env) {
    return vader_ref_box(__lambda_3010(env));
}
vader_box_t vader_fn_lift_1809(void* env, vader_box_t a0) {
    __lambda_3031(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1810(void* env, vader_box_t a0) {
    __lambda_3039(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1811(void* env, vader_box_t a0) {
    __lambda_3042(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2025(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1380(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2028(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1390(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2185(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2832(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2518(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_6091(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2587(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3475(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2588(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3478(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2589(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3481(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2590(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3484(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 163u);
    return (int) vader_bootstrap_main(__args);
}
