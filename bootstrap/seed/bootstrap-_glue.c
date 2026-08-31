#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_235(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_235 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_235, NULL };
vader_box_t vader_fn_tramp_236(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_236 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_236, NULL };
vader_box_t vader_fn_tramp_483(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_483 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_483, NULL };
vader_box_t vader_fn_tramp_704(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_704 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_704, NULL };
vader_box_t vader_fn_tramp_706(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_706 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_706, NULL };
vader_box_t vader_fn_tramp_708(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_708 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_708, NULL };
vader_box_t vader_fn_tramp_709(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_709 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_709, NULL };
vader_box_t vader_fn_tramp_955(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_955 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_955, NULL };
vader_box_t vader_fn_tramp_1037(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1037 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1037, NULL };
vader_box_t vader_fn_tramp_1038(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1038 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1038, NULL };
vader_box_t vader_fn_tramp_1040(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1040 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1040, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1041 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1042 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1043 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1044(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1044 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1044, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1050(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1050 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1050, NULL };
vader_box_t vader_fn_tramp_1051(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1051 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1051, NULL };
vader_box_t vader_fn_tramp_1053(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1053 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1053, NULL };
vader_box_t vader_fn_tramp_1154(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1154 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1154, NULL };
vader_box_t vader_fn_tramp_1188(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1188 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1188, NULL };
vader_box_t vader_fn_tramp_1288(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1288 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1288, NULL };
vader_box_t vader_fn_tramp_2414(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2414 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2414, NULL };
vader_box_t vader_fn_lift_227(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_287(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1993(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_301(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2958(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_454(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2043(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_567(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3859(env, a0, a1));
}
vader_box_t vader_fn_lift_964(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2244(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1073(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_5361(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1091(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1092(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1118(void* env, vader_box_t a0) {
    __lambda_1643(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1290(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_4332(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1756(void* env, vader_box_t a0) {
    __lambda_1768(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1757(void* env, vader_box_t a0) {
    __lambda_1771(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1763(void* env) {
    return vader_ref_box(__lambda_1861(env));
}
vader_box_t vader_fn_lift_1766(void* env) {
    return vader_ref_box(__lambda_1879(env));
}
vader_box_t vader_fn_lift_1778(void* env, vader_box_t a0) {
    __lambda_2839(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1780(void* env, vader_box_t a0) {
    __lambda_2848(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1782(void* env, vader_box_t a0) {
    __lambda_2855(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1783(void* env, vader_box_t a0) {
    __lambda_2858(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1784(void* env) {
    return vader_ref_box(__lambda_2864(env));
}
vader_box_t vader_fn_lift_1785(void* env) {
    return vader_ref_box(__lambda_2867(env));
}
vader_box_t vader_fn_lift_1787(void* env, vader_box_t a0) {
    __lambda_2888(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1788(void* env, vader_box_t a0) {
    __lambda_2896(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1789(void* env, vader_box_t a0) {
    __lambda_2899(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2001(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1357(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2004(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1367(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2156(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2699(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2485(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_5935(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2554(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(159u, __lambda_3329(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2555(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3332(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2556(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3335(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2557(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3338(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2558(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3341(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2559(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3344(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2560(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3347(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2561(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3350(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2562(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3358(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2563(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3361(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2564(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3364(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2565(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3367(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 162u);
    return (int) vader_bootstrap_main(__args);
}
