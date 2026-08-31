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
vader_box_t vader_fn_tramp_953(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_953 = { { 154u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_953, NULL };
vader_box_t vader_fn_tramp_1035(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1035 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1035, NULL };
vader_box_t vader_fn_tramp_1036(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1036 = { { 134u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1036, NULL };
vader_box_t vader_fn_tramp_1038(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1038 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1038, NULL };
vader_box_t vader_fn_tramp_1039(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1039 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1039, NULL };
vader_box_t vader_fn_tramp_1040(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1040 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1040, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1041 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1042(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1042 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1042, NULL };
vader_box_t vader_fn_tramp_1044(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1044 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1044, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1049(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1049 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1049, NULL };
vader_box_t vader_fn_tramp_1051(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1051 = { { 142u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1051, NULL };
vader_box_t vader_fn_tramp_1152(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(160u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1152 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1152, NULL };
vader_box_t vader_fn_tramp_1186(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1186 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1186, NULL };
vader_box_t vader_fn_tramp_1286(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1286 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1286, NULL };
vader_box_t vader_fn_tramp_2408(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2408 = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2408, NULL };
vader_box_t vader_fn_lift_226(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_286(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1984(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_300(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2950(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_453(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2034(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_566(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3854(env, a0, a1));
}
vader_box_t vader_fn_lift_962(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2235(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1071(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_5318(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1089(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1090(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1116(void* env, vader_box_t a0) {
    __lambda_1640(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1288(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_4292(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1754(void* env, vader_box_t a0) {
    __lambda_1765(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1755(void* env, vader_box_t a0) {
    __lambda_1768(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1760(void* env) {
    return vader_ref_box(__lambda_1852(env));
}
vader_box_t vader_fn_lift_1763(void* env) {
    return vader_ref_box(__lambda_1870(env));
}
vader_box_t vader_fn_lift_1775(void* env, vader_box_t a0) {
    __lambda_2831(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1777(void* env, vader_box_t a0) {
    __lambda_2840(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1779(void* env, vader_box_t a0) {
    __lambda_2847(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1780(void* env, vader_box_t a0) {
    __lambda_2850(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1781(void* env) {
    return vader_ref_box(__lambda_2856(env));
}
vader_box_t vader_fn_lift_1782(void* env) {
    return vader_ref_box(__lambda_2859(env));
}
vader_box_t vader_fn_lift_1784(void* env, vader_box_t a0) {
    __lambda_2880(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1785(void* env, vader_box_t a0) {
    __lambda_2888(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1786(void* env, vader_box_t a0) {
    __lambda_2891(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1997(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1357(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2000(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_1367(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2151(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_2691(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2479(void* env, vader_box_t a0) {
    return vader_box_bool(160u, __lambda_5892(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2548(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(159u, __lambda_3319(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2549(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3322(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2550(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3325(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2551(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3328(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2552(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3331(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2553(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3334(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2554(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3337(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2555(void* env, vader_box_t a0) {
    return vader_box_f64(159u, __lambda_3340(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2556(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3348(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2557(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3351(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2558(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3354(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2559(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(160u, __lambda_3357(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 162u);
    return (int) vader_bootstrap_main(__args);
}
