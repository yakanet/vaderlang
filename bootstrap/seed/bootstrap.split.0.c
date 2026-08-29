#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_233(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(7u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_233 = { { 917u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_233, NULL };
vader_box_t vader_fn_tramp_234(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(7u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_234 = { { 917u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_234, NULL };
vader_box_t vader_fn_tramp_481(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_481 = { { 334u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_481, NULL };
vader_box_t vader_fn_tramp_701(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_701 = { { 370u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_701, NULL };
vader_box_t vader_fn_tramp_703(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_703 = { { 370u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_703, NULL };
vader_box_t vader_fn_tramp_705(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_705 = { { 370u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_705, NULL };
vader_box_t vader_fn_tramp_706(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_706 = { { 370u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_706, NULL };
vader_box_t vader_fn_tramp_950(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_950 = { { 414u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_950, NULL };
vader_box_t vader_fn_tramp_1032(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(7u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1032 = { { 417u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1032, NULL };
vader_box_t vader_fn_tramp_1033(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(7u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_1033 = { { 417u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1033, NULL };
vader_box_t vader_fn_tramp_1035(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1035 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1035, NULL };
vader_box_t vader_fn_tramp_1036(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1036 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1036, NULL };
vader_box_t vader_fn_tramp_1037(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1037 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1037, NULL };
vader_box_t vader_fn_tramp_1038(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1038 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1038, NULL };
vader_box_t vader_fn_tramp_1039(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1039 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1039, NULL };
vader_box_t vader_fn_tramp_1041(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1041 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1041, NULL };
vader_box_t vader_fn_tramp_1043(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1043 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1043, NULL };
vader_box_t vader_fn_tramp_1045(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1045 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1045, NULL };
vader_box_t vader_fn_tramp_1046(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1046 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1046, NULL };
vader_box_t vader_fn_tramp_1048(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(22u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_1048 = { { 418u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1048, NULL };
vader_box_t vader_fn_tramp_1149(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(7u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_1149 = { { 919u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1149, NULL };
vader_box_t vader_fn_tramp_1183(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_1183 = { { 542u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1183, NULL };
vader_box_t vader_fn_tramp_1282(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_1282 = { { 544u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_1282, NULL };
vader_box_t vader_fn_tramp_2380(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_2380 = { { 333u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_2380, NULL };
vader_box_t vader_fn_lift_225(void* env, vader_box_t a0) {
    return vader_box_bool(7u, __lambda_315(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_285(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_1873(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_299(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_2692(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_452(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_1923(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift_565(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_3716(env, a0, a1));
}
vader_box_t vader_fn_lift_959(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_2124(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift_1068(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_5217(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1086(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_201(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1087(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_204(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1113(void* env, vader_box_t a0) {
    __lambda_1529(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift_1284(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_4139(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_1750(void* env, vader_box_t a0) {
    __lambda_1654(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1751(void* env, vader_box_t a0) {
    __lambda_1657(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1756(void* env) {
    return vader_ref_box(__lambda_1741(env));
}
vader_box_t vader_fn_lift_1759(void* env) {
    return vader_ref_box(__lambda_1759(env));
}
vader_box_t vader_fn_lift_1771(void* env, vader_box_t a0) {
    __lambda_2573(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1773(void* env, vader_box_t a0) {
    __lambda_2582(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1775(void* env, vader_box_t a0) {
    __lambda_2589(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1776(void* env, vader_box_t a0) {
    __lambda_2592(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1777(void* env) {
    return vader_ref_box(__lambda_2598(env));
}
vader_box_t vader_fn_lift_1778(void* env) {
    return vader_ref_box(__lambda_2601(env));
}
vader_box_t vader_fn_lift_1780(void* env, vader_box_t a0) {
    __lambda_2622(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1781(void* env, vader_box_t a0) {
    __lambda_2630(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_1782(void* env, vader_box_t a0) {
    __lambda_2633(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift_2128(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_3325(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2451(void* env, vader_box_t a0) {
    return vader_box_bool(7u, __lambda_5796(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift_2520(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_f64(30u, __lambda_3085(env, ((double) a0.payload.f), ((double) a1.payload.f)));
}
vader_box_t vader_fn_lift_2521(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3088(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2522(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3091(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2523(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3094(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2524(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3097(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2525(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3100(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2526(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3103(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2527(void* env, vader_box_t a0) {
    return vader_box_f64(30u, __lambda_3106(env, ((double) a0.payload.f)));
}
vader_box_t vader_fn_lift_2528(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_3114(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2529(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_3117(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift_2530(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_3120(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift_2531(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(7u, __lambda_3123(env, a0.payload.s, a1.payload.s));
}

size_t vader_import_0(vader_string_t a0) { return vader_string_byte_len(a0); }
uint8_t vader_import_1(vader_string_t a0, size_t a1) { return vader_string_byte_at(a0, a1); }
vader_string_t vader_import_2(void* a0) { return vader_string_as_string((vader_array_t*) a0); }
void* vader_import_3(vader_string_t a0) { return (void*) vader_string_bytes_view(a0, 27u, 28u); }
uint64_t vader_import_4(vader_string_t a0) { return vader_string_hash(a0); }
void vader_import_5(int32_t a0, vader_string_t a1) { vader_write(a0, a1); }
vader_box_t vader_import_6(vader_string_t a0) { vader_box_t r = vader_read_file_bytes(a0, 27u, 28u, 50u); if (r.tag == 50u) { vader_struct_std_io_IOError_t* e = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t)); vader_obj_header_init(e, 50u); e->f_msg = r.payload.s; return vader_box_obj(50u, e); } return r; }
vader_box_t vader_import_7(vader_string_t a0, void* a1) { vader_box_t r = vader_write_file_bytes(a0, (vader_array_t*) a1, 50u); if (r.tag == 50u) { vader_struct_std_io_IOError_t* e = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t)); vader_obj_header_init(e, 50u); e->f_msg = r.payload.s; return vader_box_obj(50u, e); } return r; }
vader_box_t vader_import_8(vader_string_t a0) { vader_box_t r = vader_create_dir(a0, 50u); if (r.tag == 50u) { vader_struct_std_io_IOError_t* e = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t)); vader_obj_header_init(e, 50u); e->f_msg = r.payload.s; return vader_box_obj(50u, e); } return r; }
vader_box_t vader_import_9(vader_string_t a0) { vader_box_t r = vader_remove_file(a0, 50u); if (r.tag == 50u) { vader_struct_std_io_IOError_t* e = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t)); vader_obj_header_init(e, 50u); e->f_msg = r.payload.s; return vader_box_obj(50u, e); } return r; }
bool vader_import_10(vader_string_t a0) { return vader_exists(a0); }
bool vader_import_11(vader_string_t a0) { return vader_is_dir(a0); }
vader_box_t vader_import_12(vader_string_t a0) { vader_box_t r = vader_read_dir(a0, 1u, 2u, 50u); if (r.tag == 50u) { vader_struct_std_io_IOError_t* e = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t)); vader_obj_header_init(e, 50u); e->f_msg = r.payload.s; return vader_box_obj(50u, e); } return r; }
vader_string_t vader_import_13(void) { return vader_current_executable_location(); }
vader_string_t vader_import_14(void) { return vader_current_working_directory(); }
vader_string_t vader_import_15(void) { return vader_temp_dir(); }
double vader_import_16(double a0) { return vader_math_sqrt(a0); }
double vader_import_17(double a0, double a1) { return vader_math_pow(a0, a1); }
double vader_import_18(double a0) { return vader_math_floor(a0); }
double vader_import_19(double a0) { return vader_math_ceil(a0); }
double vader_import_20(double a0) { return vader_math_round(a0); }
double vader_import_21(double a0) { return vader_math_sin(a0); }
double vader_import_22(double a0) { return vader_math_cos(a0); }
double vader_import_23(double a0) { return vader_math_tan(a0); }
bool vader_import_24(void) { return vader_terminal_raw_begin(); }
void vader_import_25(void) { vader_terminal_raw_end(); }
int32_t vader_import_26(void) { return vader_terminal_columns(); }
vader_string_t vader_import_27(int32_t a0) { return vader_terminal_read_keys(a0); }
bool vader_import_28(int32_t a0) { return vader_is_tty(a0); }
vader_box_t vader_import_29(vader_string_t a0) { return vader_get_env(a0, 2u); }
uint8_t vader_import_30(void) { return vader_current_os(); }
uint8_t vader_import_31(void) { return vader_current_arch(); }
void vader_import_32(vader_string_t a0) { vader_panic(a0); }
int64_t vader_import_33(void* a0) { return vader_spawn_start((vader_array_t*) a0); }
int32_t vader_import_34(int64_t a0) { return vader_spawn_poll(a0); }
void vader_import_35(int64_t a0) { vader_spawn_kill(a0); }
vader_string_t vader_import_36(int64_t a0) { return vader_spawn_take_stdout(a0); }
vader_string_t vader_import_37(int64_t a0) { return vader_spawn_take_stderr(a0); }
int64_t vader_import_38(void) { return vader_clock_realtime_ms(); }
int64_t vader_import_39(void) { return vader_clock_monotonic_ns(); }

int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 1u, 2u);
    return (int) vader_bootstrap_main(__args);
}
