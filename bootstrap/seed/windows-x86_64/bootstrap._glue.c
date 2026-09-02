#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(162u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL };
vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(162u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_diagnostics_diag_less = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_expr(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_expr = { { 157u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_expr, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_in = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_bitwise(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_bitwise = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_bitwise, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_compare = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_arith = { { 147u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL };
vader_box_t vader_fn_tramp_vader_comptime_evaluate_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_comptime_evaluate_expr = { { 156u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_evaluate_expr, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(162u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_vader_comptime_op_or = { { 136u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(162u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_vader_comptime_op_and = { { 136u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_bit_or = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_bit_and = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_shr = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_shl = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_mod = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_div(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_div = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_div, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_mul = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_sub = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(168u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_add = { { 144u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL };
vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(162u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL };
vader_box_t vader_fn_tramp_vader_lower_lower_block(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_vader_lower_lower_block = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_block, NULL };
vader_box_t vader_fn_tramp_vader_lower_lower_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_vader_lower_lower_expr = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_expr, NULL };
vader_box_t vader_fn_tramp_vader_types_mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_vader_types_mk_trait = { { 153u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_trait, NULL };
vader_box_t vader_fn_lift___lambda_174(void* env, vader_box_t a0) {
    return vader_box_bool(162u, __lambda_174(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift___lambda_2069(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_2069(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift___lambda_3082(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_3082(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_2119(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_2119(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift___lambda_3960(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_3960(env, a0, a1));
}
vader_box_t vader_fn_lift___lambda_2320(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_2320(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift___lambda_5498(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_5498(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_209(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_209(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_212(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_212(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_1717(void* env, vader_box_t a0) {
    __lambda_1717(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_4443(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_4443(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_1842(void* env, vader_box_t a0) {
    __lambda_1842(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_1845(void* env, vader_box_t a0) {
    __lambda_1845(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_1941(void* env) {
    return vader_ref_box(__lambda_1941(env));
}
vader_box_t vader_fn_lift___lambda_1959(void* env) {
    return vader_ref_box(__lambda_1959(env));
}
vader_box_t vader_fn_lift___lambda_2963(void* env, vader_box_t a0) {
    __lambda_2963(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_2972(void* env, vader_box_t a0) {
    __lambda_2972(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_2979(void* env, vader_box_t a0) {
    __lambda_2979(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_2982(void* env, vader_box_t a0) {
    __lambda_2982(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_2988(void* env) {
    return vader_ref_box(__lambda_2988(env));
}
vader_box_t vader_fn_lift___lambda_2991(void* env) {
    return vader_ref_box(__lambda_2991(env));
}
vader_box_t vader_fn_lift___lambda_3012(void* env, vader_box_t a0) {
    __lambda_3012(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_3020(void* env, vader_box_t a0) {
    __lambda_3020(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_3023(void* env, vader_box_t a0) {
    __lambda_3023(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_1372(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_1372(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_1382(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_1382(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_2814(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_2814(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_6072(void* env, vader_box_t a0) {
    return vader_box_bool(162u, __lambda_6072(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift___lambda_3456(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_3456(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_3459(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_3459(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_3462(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_3462(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_3465(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(162u, __lambda_3465(env, a0.payload.s, a1.payload.s));
}

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 164u);
    return (int) vader_bootstrap_main(__args);
}
