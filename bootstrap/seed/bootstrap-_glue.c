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
vader_box_t vader_fn_tramp_703(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_703 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_703, NULL };
vader_box_t vader_fn_tramp_705(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_705 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_705, NULL };
vader_box_t vader_fn_tramp_707(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_707 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_707, NULL };
vader_box_t vader_fn_tramp_708(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_708 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_708, NULL };
vader_box_t vader_fn_tramp_954(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_954 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_954, NULL };
vader_box_t vader_fn_tramp_1036(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1036 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1036, NULL };
vader_box_t vader_fn_tramp_1037(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1037 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1037, NULL };
vader_box_t vader_fn_tramp_1039(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1039 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1039, NULL };
vader_box_t vader_fn_tramp_1040(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1040 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1040, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1041 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1042 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1043 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1045(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1045 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1045, NULL };
vader_box_t vader_fn_tramp_1047(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1047 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1047, NULL };
vader_box_t vader_fn_tramp_1049(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1049 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1049, NULL };
vader_box_t vader_fn_tramp_1050(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1050 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1050, NULL };
vader_box_t vader_fn_tramp_1052(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1052 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1052, NULL };
vader_box_t vader_fn_tramp_1153(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1153 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1153, NULL };
vader_box_t vader_fn_tramp_1187(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1187 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1187, NULL };
vader_box_t vader_fn_tramp_1287(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1287 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1287, NULL };
vader_box_t vader_fn_tramp_2409(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2409 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2409, NULL };
vader_box_t vader_fn_lift_227(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_287(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1984(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_301(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2950(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_454(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2034(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_567(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3854(env, a0, a1));
}
vader_box_t vader_fn_lift_963(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2235(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1072(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_5340(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1090(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1091(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1117(void* env, vader_box_t a0) {
    __lambda_1640(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1289(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_4311(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1755(void* env, vader_box_t a0) {
    __lambda_1765(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1756(void* env, vader_box_t a0) {
    __lambda_1768(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1761(void* env) {
    return vader_ref_box(__lambda_1852(env));
}
vader_box_t vader_fn_lift_1764(void* env) {
    return vader_ref_box(__lambda_1870(env));
}
vader_box_t vader_fn_lift_1776(void* env, vader_box_t a0) {
    __lambda_2831(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1778(void* env, vader_box_t a0) {
    __lambda_2840(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1780(void* env, vader_box_t a0) {
    __lambda_2847(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1781(void* env, vader_box_t a0) {
    __lambda_2850(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1782(void* env) {
    return vader_ref_box(__lambda_2856(env));
}
vader_box_t vader_fn_lift_1783(void* env) {
    return vader_ref_box(__lambda_2859(env));
}
vader_box_t vader_fn_lift_1785(void* env, vader_box_t a0) {
    __lambda_2880(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1786(void* env, vader_box_t a0) {
    __lambda_2888(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1787(void* env, vader_box_t a0) {
    __lambda_2891(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1998(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1357(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2001(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1367(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2152(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2691(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2480(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_5914(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2549(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(159u, __lambda_3321(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2550(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3324(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2551(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3327(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2552(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3330(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2553(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3333(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2554(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3336(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2555(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3339(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2556(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3342(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2557(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3350(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2558(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3353(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2559(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3356(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2560(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3359(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 162u);
    return (int) vader_bootstrap_main(__args);
}
