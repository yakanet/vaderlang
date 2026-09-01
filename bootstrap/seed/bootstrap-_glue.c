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
vader_box_t vader_fn_tramp_961(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_961 = { { 153u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_961, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1043 = { { 133u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1044(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1044 = { { 133u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1044, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1047(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1047 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1047, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1049(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1049 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1049, NULL };
vader_box_t vader_fn_tramp_1050(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1050 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1050, NULL };
vader_box_t vader_fn_tramp_1052(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1052 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1052, NULL };
vader_box_t vader_fn_tramp_1054(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1054 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1054, NULL };
vader_box_t vader_fn_tramp_1056(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1056 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1056, NULL };
vader_box_t vader_fn_tramp_1057(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1057 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1057, NULL };
vader_box_t vader_fn_tramp_1059(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(165u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1059 = { { 141u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1059, NULL };
vader_box_t vader_fn_tramp_1160(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(159u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1160 = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1160, NULL };
vader_box_t vader_fn_tramp_1194(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1194 = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1194, NULL };
vader_box_t vader_fn_tramp_1294(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1294 = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1294, NULL };
vader_box_t vader_fn_tramp_2430(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2430 = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2430, NULL };
vader_box_t vader_fn_lift_229(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_289(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2054(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_303(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3068(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_456(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2104(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_569(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3946(env, a0, a1));
}
vader_box_t vader_fn_lift_970(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2305(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1079(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_5466(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1097(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1098(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1124(void* env, vader_box_t a0) {
    __lambda_1705(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1296(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_4424(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1762(void* env, vader_box_t a0) {
    __lambda_1830(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1763(void* env, vader_box_t a0) {
    __lambda_1833(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1770(void* env) {
    return vader_ref_box(__lambda_1926(env));
}
vader_box_t vader_fn_lift_1773(void* env) {
    return vader_ref_box(__lambda_1944(env));
}
vader_box_t vader_fn_lift_1787(void* env, vader_box_t a0) {
    __lambda_2949(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1789(void* env, vader_box_t a0) {
    __lambda_2958(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1791(void* env, vader_box_t a0) {
    __lambda_2965(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1792(void* env, vader_box_t a0) {
    __lambda_2968(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1793(void* env) {
    return vader_ref_box(__lambda_2974(env));
}
vader_box_t vader_fn_lift_1794(void* env) {
    return vader_ref_box(__lambda_2977(env));
}
vader_box_t vader_fn_lift_1796(void* env, vader_box_t a0) {
    __lambda_2998(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1797(void* env, vader_box_t a0) {
    __lambda_3006(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1798(void* env, vader_box_t a0) {
    __lambda_3009(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2010(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1376(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2013(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_1386(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2169(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_2802(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2501(void* env, vader_box_t a0) {
    return vader_box_bool(159u, __lambda_6040(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2570(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3442(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2571(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3445(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2572(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3448(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2573(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(159u, __lambda_3451(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_ffi_register_statics(vader_ffi_static_syms);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 161u);
    return (int) vader_bootstrap_main(__args);
}
