#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_234(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_234 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_234, NULL };
vader_box_t vader_fn_tramp_235(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_235 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_235, NULL };
vader_box_t vader_fn_tramp_482(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_482 = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_482, NULL };
vader_box_t vader_fn_tramp_702(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_702 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_702, NULL };
vader_box_t vader_fn_tramp_704(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_704 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_704, NULL };
vader_box_t vader_fn_tramp_706(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_706 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_706, NULL };
vader_box_t vader_fn_tramp_707(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_707 = { { 145u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_707, NULL };
vader_box_t vader_fn_tramp_951(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_951 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_951, NULL };
vader_box_t vader_fn_tramp_1033(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1033 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1033, NULL };
vader_box_t vader_fn_tramp_1034(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1034 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1034, NULL };
vader_box_t vader_fn_tramp_1036(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1036 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1036, NULL };
vader_box_t vader_fn_tramp_1037(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1037 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1037, NULL };
vader_box_t vader_fn_tramp_1038(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1038 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1038, NULL };
vader_box_t vader_fn_tramp_1039(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1039 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1039, NULL };
vader_box_t vader_fn_tramp_1040(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1040 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1040, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1042 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1044(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1044 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1044, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1047(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1047 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1047, NULL };
vader_box_t vader_fn_tramp_1049(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1049 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1049, NULL };
vader_box_t vader_fn_tramp_1150(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1150 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1150, NULL };
vader_box_t vader_fn_tramp_1184(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1184 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1184, NULL };
vader_box_t vader_fn_tramp_1283(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1283 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1283, NULL };
vader_box_t vader_fn_tramp_2400(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2400 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2400, NULL };
vader_box_t vader_fn_lift_228(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_320(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_286(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1983(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_300(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2933(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_453(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2033(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_566(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3832(env, a0, a1));
}
vader_box_t vader_fn_lift_960(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2234(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1069(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_5288(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1087(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_206(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1088(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1114(void* env, vader_box_t a0) {
    __lambda_1639(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1285(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_4265(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1751(void* env, vader_box_t a0) {
    __lambda_1764(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1752(void* env, vader_box_t a0) {
    __lambda_1767(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1757(void* env) {
    return vader_ref_box(__lambda_1851(env));
}
vader_box_t vader_fn_lift_1760(void* env) {
    return vader_ref_box(__lambda_1869(env));
}
vader_box_t vader_fn_lift_1772(void* env, vader_box_t a0) {
    __lambda_2814(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1774(void* env, vader_box_t a0) {
    __lambda_2823(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1776(void* env, vader_box_t a0) {
    __lambda_2830(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1777(void* env, vader_box_t a0) {
    __lambda_2833(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1778(void* env) {
    return vader_ref_box(__lambda_2839(env));
}
vader_box_t vader_fn_lift_1779(void* env) {
    return vader_ref_box(__lambda_2842(env));
}
vader_box_t vader_fn_lift_1781(void* env, vader_box_t a0) {
    __lambda_2863(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1782(void* env, vader_box_t a0) {
    __lambda_2871(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1783(void* env, vader_box_t a0) {
    __lambda_2874(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1993(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1357(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_1996(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1367(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2143(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2674(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2471(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_5862(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2540(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(159u, __lambda_3302(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2541(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3305(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2542(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3308(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2543(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3311(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2544(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3314(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2545(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3317(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2546(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3320(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2547(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3323(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2548(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3331(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2549(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3334(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2550(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3337(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2551(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3340(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 162u);
    return (int) vader_bootstrap_main(__args);
}
