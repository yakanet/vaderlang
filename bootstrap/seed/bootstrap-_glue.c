#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_245(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_245 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_245, NULL };
vader_box_t vader_fn_tramp_246(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_246 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_246, NULL };
vader_box_t vader_fn_tramp_493(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_493 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_493, NULL };
vader_box_t vader_fn_tramp_716(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_716 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_716, NULL };
vader_box_t vader_fn_tramp_718(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_718 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_718, NULL };
vader_box_t vader_fn_tramp_720(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_720 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_720, NULL };
vader_box_t vader_fn_tramp_721(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_721 = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_721, NULL };
vader_box_t vader_fn_tramp_969(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_969 = { { 153u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_969, NULL };
vader_box_t vader_fn_tramp_1051(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1051 = { { 133u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1051, NULL };
vader_box_t vader_fn_tramp_1052(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1052 = { { 133u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1052, NULL };
vader_box_t vader_fn_tramp_1054(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1054 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1054, NULL };
vader_box_t vader_fn_tramp_1055(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1055 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1055, NULL };
vader_box_t vader_fn_tramp_1056(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1056 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1056, NULL };
vader_box_t vader_fn_tramp_1057(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1057 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1057, NULL };
vader_box_t vader_fn_tramp_1058(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1058 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1058, NULL };
vader_box_t vader_fn_tramp_1060(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1060 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1060, NULL };
vader_box_t vader_fn_tramp_1062(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1062 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1062, NULL };
vader_box_t vader_fn_tramp_1064(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1064 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1064, NULL };
vader_box_t vader_fn_tramp_1065(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1065 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1065, NULL };
vader_box_t vader_fn_tramp_1067(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1067 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1067, NULL };
vader_box_t vader_fn_tramp_1168(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1168 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1168, NULL };
vader_box_t vader_fn_tramp_1202(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1202 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1202, NULL };
vader_box_t vader_fn_tramp_1302(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1302 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1302, NULL };
vader_box_t vader_fn_tramp_2439(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2439 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2439, NULL };
vader_box_t vader_fn_lift_237(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_297(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2051(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_311(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3068(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_464(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2101(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_577(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3946(env, a0, a1));
}
vader_box_t vader_fn_lift_978(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2302(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1087(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_5463(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1105(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1106(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1132(void* env, vader_box_t a0) {
    __lambda_1702(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1304(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_4421(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1770(void* env, vader_box_t a0) {
    __lambda_1827(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1771(void* env, vader_box_t a0) {
    __lambda_1830(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1778(void* env) {
    return vader_ref_box(__lambda_1923(env));
}
vader_box_t vader_fn_lift_1781(void* env) {
    return vader_ref_box(__lambda_1941(env));
}
vader_box_t vader_fn_lift_1795(void* env, vader_box_t a0) {
    __lambda_2949(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1797(void* env, vader_box_t a0) {
    __lambda_2958(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1799(void* env, vader_box_t a0) {
    __lambda_2965(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1800(void* env, vader_box_t a0) {
    __lambda_2968(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1801(void* env) {
    return vader_ref_box(__lambda_2974(env));
}
vader_box_t vader_fn_lift_1802(void* env) {
    return vader_ref_box(__lambda_2977(env));
}
vader_box_t vader_fn_lift_1804(void* env, vader_box_t a0) {
    __lambda_2998(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1805(void* env, vader_box_t a0) {
    __lambda_3006(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1806(void* env, vader_box_t a0) {
    __lambda_3009(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2018(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1378(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2021(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1388(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2176(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2799(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2508(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_6037(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2577(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3442(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2578(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3445(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2579(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3448(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2580(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3451(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 161u);
    return (int) vader_bootstrap_main(__args);
}
