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
vader_box_t vader_fn_tramp_707(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_707 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_707, NULL };
vader_box_t vader_fn_tramp_709(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_709 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_709, NULL };
vader_box_t vader_fn_tramp_711(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_711 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_711, NULL };
vader_box_t vader_fn_tramp_712(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_712 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_712, NULL };
vader_box_t vader_fn_tramp_959(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_959 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_959, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1041 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1042 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1044(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1044 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1044, NULL };
vader_box_t vader_fn_tramp_1045(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1045 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1045, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1047(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1047 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1047, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1050(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1050 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1050, NULL };
vader_box_t vader_fn_tramp_1052(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1052 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1052, NULL };
vader_box_t vader_fn_tramp_1054(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1054 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1054, NULL };
vader_box_t vader_fn_tramp_1055(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1055 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1055, NULL };
vader_box_t vader_fn_tramp_1057(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1057 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1057, NULL };
vader_box_t vader_fn_tramp_1158(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1158 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1158, NULL };
vader_box_t vader_fn_tramp_1192(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1192 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1192, NULL };
vader_box_t vader_fn_tramp_1292(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1292 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1292, NULL };
vader_box_t vader_fn_tramp_2425(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2425 = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2425, NULL };
vader_box_t vader_fn_lift_228(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_288(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2007(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_302(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3009(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_455(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2057(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_568(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3910(env, a0, a1));
}
vader_box_t vader_fn_lift_968(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2258(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1077(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_5430(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1095(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1096(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1122(void* env, vader_box_t a0) {
    __lambda_1658(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1294(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_4394(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1760(void* env, vader_box_t a0) {
    __lambda_1783(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1761(void* env, vader_box_t a0) {
    __lambda_1786(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1768(void* env) {
    return vader_ref_box(__lambda_1879(env));
}
vader_box_t vader_fn_lift_1771(void* env) {
    return vader_ref_box(__lambda_1897(env));
}
vader_box_t vader_fn_lift_1785(void* env, vader_box_t a0) {
    __lambda_2890(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1787(void* env, vader_box_t a0) {
    __lambda_2899(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1789(void* env, vader_box_t a0) {
    __lambda_2906(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1790(void* env, vader_box_t a0) {
    __lambda_2909(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1791(void* env) {
    return vader_ref_box(__lambda_2915(env));
}
vader_box_t vader_fn_lift_1792(void* env) {
    return vader_ref_box(__lambda_2918(env));
}
vader_box_t vader_fn_lift_1794(void* env, vader_box_t a0) {
    __lambda_2939(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1795(void* env, vader_box_t a0) {
    __lambda_2947(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1796(void* env, vader_box_t a0) {
    __lambda_2950(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2008(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1372(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2011(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1382(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2163(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2743(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2496(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_6004(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2565(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(160u, __lambda_3380(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2566(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3383(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2567(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3386(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2568(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3389(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2569(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3392(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2570(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3395(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2571(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3398(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2572(void* env, vader_box_t a0) {
    return vader_box_f64(160u, __lambda_3401(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2573(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3409(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2574(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3412(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2575(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3415(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2576(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3418(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 163u);
    return (int) vader_bootstrap_main(__args);
}
