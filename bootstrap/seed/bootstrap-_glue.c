#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_237(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_237 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_237, NULL };
vader_box_t vader_fn_tramp_238(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_238 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_238, NULL };
vader_box_t vader_fn_tramp_485(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_485 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_485, NULL };
vader_box_t vader_fn_tramp_708(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_708 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_708, NULL };
vader_box_t vader_fn_tramp_710(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_710 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_710, NULL };
vader_box_t vader_fn_tramp_712(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_712 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_712, NULL };
vader_box_t vader_fn_tramp_713(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_713 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_713, NULL };
vader_box_t vader_fn_tramp_960(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_960 = { { 153u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_960, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1042 = { { 133u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1043 = { { 133u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1045(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1045 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1045, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1047(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1047 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1047, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1049(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1049 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1049, NULL };
vader_box_t vader_fn_tramp_1051(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1051 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1051, NULL };
vader_box_t vader_fn_tramp_1053(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1053 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1053, NULL };
vader_box_t vader_fn_tramp_1055(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1055 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1055, NULL };
vader_box_t vader_fn_tramp_1056(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1056 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1056, NULL };
vader_box_t vader_fn_tramp_1058(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1058 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1058, NULL };
vader_box_t vader_fn_tramp_1159(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1159 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1159, NULL };
vader_box_t vader_fn_tramp_1193(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1193 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1193, NULL };
vader_box_t vader_fn_tramp_1293(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1293 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1293, NULL };
vader_box_t vader_fn_tramp_2427(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2427 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2427, NULL };
vader_box_t vader_fn_lift_229(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_289(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2050(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_303(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3052(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_456(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2100(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_569(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3927(env, a0, a1));
}
vader_box_t vader_fn_lift_969(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2301(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1078(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_5441(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1096(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1097(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1123(void* env, vader_box_t a0) {
    __lambda_1701(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1295(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_4405(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1761(void* env, vader_box_t a0) {
    __lambda_1826(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1762(void* env, vader_box_t a0) {
    __lambda_1829(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1769(void* env) {
    return vader_ref_box(__lambda_1922(env));
}
vader_box_t vader_fn_lift_1772(void* env) {
    return vader_ref_box(__lambda_1940(env));
}
vader_box_t vader_fn_lift_1786(void* env, vader_box_t a0) {
    __lambda_2933(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1788(void* env, vader_box_t a0) {
    __lambda_2942(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1790(void* env, vader_box_t a0) {
    __lambda_2949(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1791(void* env, vader_box_t a0) {
    __lambda_2952(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1792(void* env) {
    return vader_ref_box(__lambda_2958(env));
}
vader_box_t vader_fn_lift_1793(void* env) {
    return vader_ref_box(__lambda_2961(env));
}
vader_box_t vader_fn_lift_1795(void* env, vader_box_t a0) {
    __lambda_2982(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1796(void* env, vader_box_t a0) {
    __lambda_2990(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1797(void* env, vader_box_t a0) {
    __lambda_2993(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2009(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1375(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2012(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1385(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2167(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2786(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2498(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_6015(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2567(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3426(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2568(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3429(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2569(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3432(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2570(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3435(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 161u);
    return (int) vader_bootstrap_main(__args);
}
