#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_247(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_247 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_247, NULL };
vader_box_t vader_fn_tramp_248(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_248 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_248, NULL };
vader_box_t vader_fn_tramp_496(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_496 = { { 156u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_496, NULL };
vader_box_t vader_fn_tramp_721(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_721 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_721, NULL };
vader_box_t vader_fn_tramp_723(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_723 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_723, NULL };
vader_box_t vader_fn_tramp_725(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_725 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_725, NULL };
vader_box_t vader_fn_tramp_726(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_726 = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_726, NULL };
vader_box_t vader_fn_tramp_976(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_976 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_976, NULL };
vader_box_t vader_fn_tramp_1058(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1058 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1058, NULL };
vader_box_t vader_fn_tramp_1059(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1059 = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1059, NULL };
vader_box_t vader_fn_tramp_1061(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1061 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1061, NULL };
vader_box_t vader_fn_tramp_1062(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1062 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1062, NULL };
vader_box_t vader_fn_tramp_1063(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1063 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1063, NULL };
vader_box_t vader_fn_tramp_1064(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1064 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1064, NULL };
vader_box_t vader_fn_tramp_1065(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1065 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1065, NULL };
vader_box_t vader_fn_tramp_1067(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1067 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1067, NULL };
vader_box_t vader_fn_tramp_1069(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1069 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1069, NULL };
vader_box_t vader_fn_tramp_1071(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1071 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1071, NULL };
vader_box_t vader_fn_tramp_1072(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1072 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1072, NULL };
vader_box_t vader_fn_tramp_1074(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(167u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1074 = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1074, NULL };
vader_box_t vader_fn_tramp_1175(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(161u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1175 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1175, NULL };
vader_box_t vader_fn_tramp_1209(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1209 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1209, NULL };
vader_box_t vader_fn_tramp_1309(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1309 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1309, NULL };
vader_box_t vader_fn_tramp_2452(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2452 = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2452, NULL };
vader_box_t vader_fn_lift_239(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_299(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2081(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_313(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3100(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_467(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2131(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_580(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3978(env, a0, a1));
}
vader_box_t vader_fn_lift_985(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2332(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1094(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_5516(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1112(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1113(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1139(void* env, vader_box_t a0) {
    __lambda_1729(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1311(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_4461(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1777(void* env, vader_box_t a0) {
    __lambda_1854(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1778(void* env, vader_box_t a0) {
    __lambda_1857(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1786(void* env) {
    return vader_ref_box(__lambda_1953(env));
}
vader_box_t vader_fn_lift_1789(void* env) {
    return vader_ref_box(__lambda_1971(env));
}
vader_box_t vader_fn_lift_1803(void* env, vader_box_t a0) {
    __lambda_2981(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1805(void* env, vader_box_t a0) {
    __lambda_2990(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1807(void* env, vader_box_t a0) {
    __lambda_2997(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1808(void* env, vader_box_t a0) {
    __lambda_3000(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1809(void* env) {
    return vader_ref_box(__lambda_3006(env));
}
vader_box_t vader_fn_lift_1810(void* env) {
    return vader_ref_box(__lambda_3009(env));
}
vader_box_t vader_fn_lift_1812(void* env, vader_box_t a0) {
    __lambda_3030(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1813(void* env, vader_box_t a0) {
    __lambda_3038(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1814(void* env, vader_box_t a0) {
    __lambda_3041(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2028(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1380(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2031(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_1390(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2188(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_2832(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2521(void* env, vader_box_t a0) {
    return vader_box_bool(161u, __lambda_6090(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2590(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3474(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2591(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3477(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2592(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3480(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2593(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(161u, __lambda_3483(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 163u);
    return (int) vader_bootstrap_main(__args);
}
