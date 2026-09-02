#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_245(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_245 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_245, NULL };
vader_box_t vader_fn_tramp_246(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_246 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_246, NULL };
vader_box_t vader_fn_tramp_494(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_494 = { { 156u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_494, NULL };
vader_box_t vader_fn_tramp_719(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_719 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_719, NULL };
vader_box_t vader_fn_tramp_721(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_721 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_721, NULL };
vader_box_t vader_fn_tramp_723(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_723 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_723, NULL };
vader_box_t vader_fn_tramp_724(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_724 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_724, NULL };
vader_box_t vader_fn_tramp_972(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_972 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_972, NULL };
vader_box_t vader_fn_tramp_1054(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1054 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1054, NULL };
vader_box_t vader_fn_tramp_1055(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1055 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1055, NULL };
vader_box_t vader_fn_tramp_1057(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1057 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1057, NULL };
vader_box_t vader_fn_tramp_1058(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1058 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1058, NULL };
vader_box_t vader_fn_tramp_1059(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1059 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1059, NULL };
vader_box_t vader_fn_tramp_1060(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1060 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1060, NULL };
vader_box_t vader_fn_tramp_1061(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1061 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1061, NULL };
vader_box_t vader_fn_tramp_1063(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1063 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1063, NULL };
vader_box_t vader_fn_tramp_1065(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1065 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1065, NULL };
vader_box_t vader_fn_tramp_1067(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1067 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1067, NULL };
vader_box_t vader_fn_tramp_1068(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1068 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1068, NULL };
vader_box_t vader_fn_tramp_1070(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1070 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1070, NULL };
vader_box_t vader_fn_tramp_1171(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1171 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1171, NULL };
vader_box_t vader_fn_tramp_1205(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1205 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1205, NULL };
vader_box_t vader_fn_tramp_1305(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1305 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1305, NULL };
vader_box_t vader_fn_tramp_2447(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2447 = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2447, NULL };
vader_box_t vader_fn_lift_237(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_297(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2079(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_311(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3099(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_465(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2129(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_578(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3977(env, a0, a1));
}
vader_box_t vader_fn_lift_981(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2330(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1090(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_5515(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1108(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1109(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1135(void* env, vader_box_t a0) {
    __lambda_1727(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1307(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_4460(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1773(void* env, vader_box_t a0) {
    __lambda_1852(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1774(void* env, vader_box_t a0) {
    __lambda_1855(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1782(void* env) {
    return vader_ref_box(__lambda_1951(env));
}
vader_box_t vader_fn_lift_1785(void* env) {
    return vader_ref_box(__lambda_1969(env));
}
vader_box_t vader_fn_lift_1799(void* env, vader_box_t a0) {
    __lambda_2980(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1801(void* env, vader_box_t a0) {
    __lambda_2989(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1803(void* env, vader_box_t a0) {
    __lambda_2996(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1804(void* env, vader_box_t a0) {
    __lambda_2999(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1805(void* env) {
    return vader_ref_box(__lambda_3005(env));
}
vader_box_t vader_fn_lift_1806(void* env) {
    return vader_ref_box(__lambda_3008(env));
}
vader_box_t vader_fn_lift_1808(void* env, vader_box_t a0) {
    __lambda_3029(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1809(void* env, vader_box_t a0) {
    __lambda_3037(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1810(void* env, vader_box_t a0) {
    __lambda_3040(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2024(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1380(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2027(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1390(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2183(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2830(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2516(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_6089(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2585(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3473(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2586(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3476(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2587(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3479(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2588(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3482(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 163u);
    return (int) vader_bootstrap_main(__args);
}
