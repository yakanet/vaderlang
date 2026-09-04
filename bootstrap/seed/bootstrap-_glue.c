#include "bootstrap.split.h"

vader_box_t vader_fn_tramp_vader_diagnostics_diag_less_with_file(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(163u, vader_diagnostics_diag_less_with_file(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_diagnostics_diag_less_with_file = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less_with_file, NULL };
vader_box_t vader_fn_tramp_vader_diagnostics_diag_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(163u, vader_diagnostics_diag_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_diagnostics_diag_less = { { 148u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_diagnostics_diag_less, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_expr(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_typecheck_check_expr(a0, a1, a2.payload.obj, a3.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_expr = { { 156u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_expr, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_in(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_in(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_in = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_in, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_bitwise(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_bitwise(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_bitwise = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_bitwise, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_compare(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_compare(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_compare = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_compare, NULL };
vader_box_t vader_fn_tramp_vader_typecheck_check_arith(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3, vader_box_t a4) {
    (void) env;
    return vader_typecheck_check_arith(a0.payload.obj, a1, a2, a3.payload.obj, a4.payload.obj);
}
vader_fn_t vader_fn_static_vader_typecheck_check_arith = { { 146u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_typecheck_check_arith, NULL };
vader_box_t vader_fn_tramp_vader_comptime_evaluate_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_ref_box(vader_comptime_evaluate_expr(a0, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_comptime_evaluate_expr = { { 155u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_evaluate_expr, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(163u, vader_comptime_op_or(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_vader_comptime_op_or = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_or, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(163u, vader_comptime_op_and(a0.payload.b, a1.payload.b));
}
vader_fn_t vader_fn_static_vader_comptime_op_and = { { 135u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_and, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_bit_xor = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_xor, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_bit_or = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_or, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_bit_and = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_bit_and, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_shr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_shr = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shr, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_shl(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_shl = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_shl, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_mod(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_mod = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mod, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_div(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_div(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_div = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_div, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_mul(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_mul = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_mul, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_sub(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_sub = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_sub, NULL };
vader_box_t vader_fn_tramp_vader_comptime_op_add(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_i64(169u, vader_comptime_op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_fn_t vader_fn_static_vader_comptime_op_add = { { 143u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_comptime_op_add, NULL };
vader_box_t vader_fn_tramp_vader_lower_pending_fn_instance_less(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_box_bool(163u, vader_lower_pending_fn_instance_less(a0.payload.obj, a1.payload.obj));
}
vader_fn_t vader_fn_static_vader_lower_pending_fn_instance_less = { { 151u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_pending_fn_instance_less, NULL };
vader_box_t vader_fn_tramp_vader_lower_lower_block(void* env, vader_box_t a0, vader_box_t a1, vader_box_t a2, vader_box_t a3) {
    (void) env;
    return vader_ref_box(vader_lower_lower_block(a0.payload.obj, a1.payload.obj, a2.payload.b, a3.payload.b));
}
vader_fn_t vader_fn_static_vader_lower_lower_block = { { 149u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_block, NULL };
vader_box_t vader_fn_tramp_vader_lower_lower_expr(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_lower_lower_expr(a0.payload.obj, a1);
}
vader_fn_t vader_fn_static_vader_lower_lower_expr = { { 150u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_lower_lower_expr, NULL };
vader_box_t vader_fn_tramp_vader_types_mk_trait(void* env, vader_box_t a0, vader_box_t a1) {
    (void) env;
    return vader_types_mk_trait(a0.payload.obj, a1.payload.obj);
}
vader_fn_t vader_fn_static_vader_types_mk_trait = { { 152u, 0u, 0u, 0u, NULL }, (void*) &vader_fn_tramp_vader_types_mk_trait, NULL };
vader_box_t vader_fn_lift___lambda_std_path_0(void* env, vader_box_t a0) {
    return vader_box_bool(163u, __lambda_std_path_0(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift___lambda_vader_resolver_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_resolver_0(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift___lambda_vader_resolver_2(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_resolver_2(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_vader_typecheck_0(void* env, vader_box_t a0, vader_box_t a1) {
    return __lambda_vader_typecheck_0(env, a0.payload.obj, a1.payload.obj);
}
vader_box_t vader_fn_lift___lambda_vader_typecheck_2(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_typecheck_2(env, a0, a1));
}
vader_box_t vader_fn_lift___lambda_vader_comptime_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_comptime_0(env, a0.payload.obj, a1.payload.obj));
}
vader_box_t vader_fn_lift___lambda_vader_comptime_2(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_comptime_2(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_vader_lower_0(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_0(env, ((int32_t) a0.payload.i), a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_lower_2(void* env, vader_box_t a0, vader_box_t a1) {
    __lambda_vader_lower_2(env, a0.payload.s, a1.payload.s);
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_lower_4(void* env, vader_box_t a0) {
    __lambda_vader_lower_4(env, a0);
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_lower_6(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_lower_6(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_vader_midir_0(void* env, vader_box_t a0) {
    __lambda_vader_midir_0(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_2(void* env, vader_box_t a0) {
    __lambda_vader_midir_2(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_4(void* env) {
    return vader_ref_box(__lambda_vader_midir_4(env));
}
vader_box_t vader_fn_lift___lambda_vader_midir_6(void* env) {
    return vader_ref_box(__lambda_vader_midir_6(env));
}
vader_box_t vader_fn_lift___lambda_vader_midir_8(void* env, vader_box_t a0) {
    __lambda_vader_midir_8(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_10(void* env, vader_box_t a0) {
    __lambda_vader_midir_10(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_12(void* env, vader_box_t a0) {
    __lambda_vader_midir_12(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_14(void* env, vader_box_t a0) {
    __lambda_vader_midir_14(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_16(void* env) {
    return vader_ref_box(__lambda_vader_midir_16(env));
}
vader_box_t vader_fn_lift___lambda_vader_midir_18(void* env) {
    return vader_ref_box(__lambda_vader_midir_18(env));
}
vader_box_t vader_fn_lift___lambda_vader_midir_20(void* env, vader_box_t a0) {
    __lambda_vader_midir_20(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_22(void* env, vader_box_t a0) {
    __lambda_vader_midir_22(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_midir_24(void* env, vader_box_t a0) {
    __lambda_vader_midir_24(env, ((int32_t) a0.payload.i));
    return vader_box_null();
}
vader_box_t vader_fn_lift___lambda_vader_c_emit_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_c_emit_0(env, ((int32_t) a0.payload.i), ((int32_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_vader_c_emit_2(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_c_emit_2(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_vader_c_emit_4(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_c_emit_4(env, ((size_t) a0.payload.i), ((size_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_std_numbers_0(void* env, vader_box_t a0) {
    return vader_box_bool(163u, __lambda_std_numbers_0(env, ((uint32_t) a0.payload.i)));
}
vader_box_t vader_fn_lift___lambda_vader_vm_0(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_vm_0(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_vader_vm_2(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_vm_2(env, ((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}
vader_box_t vader_fn_lift___lambda_vader_vm_4(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_vm_4(env, a0.payload.s, a1.payload.s));
}
vader_box_t vader_fn_lift___lambda_vader_vm_6(void* env, vader_box_t a0, vader_box_t a1) {
    return vader_box_bool(163u, __lambda_vader_vm_6(env, a0.payload.s, a1.payload.s));
}


/* ----------------------------------------------- vtable dispatchers */
vader_string_t vader_vt_Display__to_string(vader_box_t recv) {
    switch (recv.tag) {
        case 159u: return std_core_i8_Display_to_string(((int8_t) recv.payload.i));
        case 160u: return std_core_i16_Display_to_string(((int16_t) recv.payload.i));
        case 168u: return std_core_i32_Display_to_string(((int32_t) recv.payload.i));
        case 169u: return std_core_i64_Display_to_string(((int64_t) recv.payload.i));
        case 170u: return std_core_isize_Display_to_string(((ptrdiff_t) recv.payload.i));
        case 171u: return std_core_u8_Display_to_string(((uint8_t) recv.payload.i));
        case 172u: return std_core_u16_Display_to_string(((uint16_t) recv.payload.i));
        case 173u: return std_core_u32_Display_to_string(((uint32_t) recv.payload.i));
        case 174u: return std_core_u64_Display_to_string(((uint64_t) recv.payload.i));
        case 175u: return std_core_usize_Display_to_string(((size_t) recv.payload.i));
        case 163u: return std_core_bool_Display_to_string(recv.payload.b);
        case 164u: return std_core_char_Display_to_string(((uint32_t) recv.payload.i));
        case 165u: return std_core_string_Display_to_string(recv.payload.s);
        case 161u: return std_core_f32_Display_to_string(((float) recv.payload.f));
        case 162u: return std_core_f64_Display_to_string(((double) recv.payload.f));
        case 385u: return std_string_builder_StringBuilder_Display_to_string(recv.payload.obj);
        case 476u: return toolchain_span_Span_Display_to_string(recv.payload.obj);
        case 936u: return vader_vm_I32Val_Display_to_string(recv.payload.obj);
        case 932u: return vader_vm_F64Val_Display_to_string(recv.payload.obj);
        case 937u: return vader_vm_I64Val_Display_to_string(recv.payload.obj);
        case 946u: return vader_vm_StringVal_Display_to_string(recv.payload.obj);
        case 933u: return vader_vm_FnVal_Display_to_string(recv.payload.obj);
        case 940u: return vader_vm_NullVal_Display_to_string(recv.payload.obj);
        case 928u: return vader_vm_BoolVal_Display_to_string(recv.payload.obj);
        case 929u: return vader_vm_CharVal_Display_to_string(recv.payload.obj);
        case 931u: return vader_vm_ErrorVal_Display_to_string(recv.payload.obj);
        case 949u: return vader_vm_TypeVal_Display_to_string(recv.payload.obj);
        case 941u: return vader_vm_ObjVal_Display_to_string(recv.payload.obj);
        case 947u: return vader_vm_StructVal_Display_to_string(recv.payload.obj);
        case 927u: return vader_vm_ArrayVal_Display_to_string(recv.payload.obj);
        default: vader_unreachable("vtable miss in Display.to_string");
    }
    vader_unreachable("vtable miss in Display.to_string");
}
int main(int argc, char** argv) {
    vader_atom_init_with_comptime(vader_atom_comptime_table, VADER_COMPTIME_ATOM_COUNT);
    vader_gc_top = &vader_global_const_frame;
    vader_atom_roots_register(vader_global_const_arrays, 1u);
    atexit(vader_atom_shutdown);
    atexit(vader_gc_shutdown);
    void* __args = (void*) vader_runtime_argv(argc, argv, 8u, 165u);
    return (int) vader_bootstrap_main(__args);
}
