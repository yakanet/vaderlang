#include "bootstrap.split.h"

static vader_string_t vader_vm_BoolVal_Display_to_string(bool l0);
static vader_string_t vader_vm_CharVal_Display_to_string(uint32_t l0);
static vader_string_t vader_vm_F64Val_Display_to_string(double l0);
static vader_string_t vader_vm_I32Val_Display_to_string(int32_t l0);
static vader_string_t vader_vm_I64Val_Display_to_string(int64_t l0);
static vader_string_t vader_vm_StringVal_Display_to_string(vader_string_t l0);
static vader_box_t vader_vm_accepted_tags(vader_box_t l0, size_t l1);
static void vader_vm_add_constant(vader_box_t l0, void* l1, void* l2);
static vader_box_t vader_vm_apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4);
static vader_box_t vader_vm_apply_eq_binop(void* l0, vader_string_t l1, bool l2);
static vader_box_t vader_vm_array_at(void* l0, size_t l1);
static vader_box_t vader_vm_array_bytes(void* l0, size_t l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm_bc_value_to_vm(vader_box_t l0, void* l1);
static vader_box_t vader_vm_binary_op(vader_box_t l0, void* l1, size_t l2);
static int64_t vader_vm_bits_of(void* l0, size_t l1, int32_t l2);
static void vader_vm_boxed(void* l0, size_t l1, vader_box_t l2, size_t l3, size_t l4);
static void* vader_vm_branch(bool l0, int32_t l1, bool l2, int32_t l3, bool l4);
static void* vader_vm_budget_trap(int64_t l0);
static vader_box_t vader_vm_build_array(int32_t l0, int32_t l1, void* l2);
static vader_box_t vader_vm_build_buffer(void* l0, void* l1);
static vader_box_t vader_vm_build_main_args(void* l0, void* l1, int32_t l2);
static vader_box_t vader_vm_build_struct(void* l0, int32_t l1, void* l2);
static void* vader_vm_bytes_to_value(vader_string_t l0, int32_t l1);
static vader_box_t vader_vm_call_import(void* l0, void* l1, int32_t l2, size_t l3, int32_t l4, bool l5);
static vader_box_t vader_vm_call_results(void* l0, vader_box_t l1);
static int32_t vader_vm_canonical(void* l0, size_t l1);
static vader_box_t vader_vm_check_byte_range(int32_t l0, size_t l1, size_t l2, vader_string_t l3, int32_t l4);
static vader_box_t vader_vm_check_module_tags(void* l0, void* l1);
static int32_t vader_vm_checked_neg_register_op(uint8_t l0);
static void* vader_vm_checked_neg_trap(uint8_t l0, void* l1, size_t l2);
static int32_t vader_vm_checked_register_op(void* l0);
static vader_box_t vader_vm_checked_registers(uint8_t l0, uint8_t l1, void* l2, size_t l3, int64_t l4);
static void* vader_vm_checked_trap(uint8_t l0, uint8_t l1, void* l2, size_t l3);
static size_t vader_vm_clamp_nonneg(int32_t l0);
static void vader_vm_collect_constants(void* l0, void* l1, void* l2);
static int64_t vader_vm_constant_index(void* l0, void* l1, void* l2);
static bool vader_vm_convert_int_fast(void* l0, uint8_t l1, vader_string_t l2);
static vader_box_t vader_vm_convert_value(vader_box_t l0, uint8_t l1, vader_string_t l2, int32_t l3);
static vader_box_t vader_vm_debug_controller(void* l0);
static int64_t vader_vm_debug_std_descriptor(int64_t l0);
static vader_box_t vader_vm_debug_write(void* l0, void* l1, size_t l2, int32_t l3, void* l4);
static void* vader_vm_defect(void* l0, size_t l1, vader_string_t l2);
static vader_box_t vader_vm_defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3);
static vader_string_t vader_vm_describe_obj(void* l0);
static vader_string_t vader_vm_describe_value_tag(vader_box_t l0);
static void vader_vm_detach_array_view(void* l0);
static vader_box_t vader_vm_dispatch_extern(void* l0, void* l1, size_t l2, int32_t l3, void* l4, vader_box_t l5);
static vader_box_t vader_vm_dispatch_import(void* l0, void* l1, size_t l2, void* l3, void* l4, int32_t l5, int32_t l6, int32_t l7, int32_t l8, void* l9, bool l10, vader_box_t l11, uint8_t l12);
static vader_string_t vader_vm_display_tags(uint8_t l0);
static vader_string_t vader_vm_display_value(vader_box_t l0);
static vader_box_t vader_vm_do_memory_copy(void* l0);
static void vader_vm_drop_due_timers(void* l0);
static void vader_vm_drop_last_op(void* l0);
static void* vader_vm_effect(size_t l0, size_t l1);
static vader_box_t vader_vm_effect_of(void* l0, void* l1, vader_box_t l2);
static vader_string_t vader_vm_element_label(int32_t l0);
static uint8_t vader_vm_element_tags(void* l0, int32_t l1);
static void* vader_vm_element_trap(void* l0, size_t l1, int32_t l2, int32_t l3, void* l4, size_t l5, int32_t l6);
static void vader_vm_emit(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static void vader_vm_enter_frame(void* l0, void* l1, size_t l2);
static vader_box_t vader_vm_exec_array_copy(void* l0);
static vader_box_t vader_vm_exec_array_push_all(void* l0);
static vader_box_t vader_vm_exec_array_repeat(void* l0);
static vader_box_t vader_vm_exec_array_slice(void* l0, void* l1);
static vader_box_t vader_vm_exec_buffer_write_string(void* l0);
static vader_box_t vader_vm_exec_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5);
static vader_box_t vader_vm_exec_string_compare(void* l0);
static vader_box_t vader_vm_exec_string_slice_codepoints(void* l0);
static bool vader_vm_extern_by_address(void* l0, size_t l1);
static vader_box_t vader_vm_extern_result(uint8_t l0, int64_t l1);
static vader_box_t vader_vm_extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, size_t l3);
static double vader_vm_f64_of(void* l0, size_t l1, int32_t l2);
static int32_t vader_vm_ffi_result_class(uint8_t l0);
static bool vader_vm_ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2);
static uint8_t vader_vm_field_tags(void* l0, int32_t l1, int32_t l2);
static uint8_t vader_vm_field_val_type(void* l0, void* l1);
static uint8_t vader_vm_field_valtype(void* l0, int32_t l1);
static int32_t vader_vm_find_io_error_type_id(void* l0);
static int32_t vader_vm_find_string_array_type_id(void* l0);
static int32_t vader_vm_find_u8_array_type_id(void* l0);
static vader_box_t vader_vm_finish_run(void* l0, bool l1, vader_box_t l2);
static bool vader_vm_fits_signed(int32_t l0, int64_t l1);
static vader_box_t vader_vm_flow_to(void* l0, void* l1, void* l2, size_t l3, size_t l4, size_t l5, size_t l6);
static void vader_vm_flush(void* l0, size_t l1);
static void* vader_vm_fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_fn_type_of(void* l0, int32_t l1);
static vader_box_t vader_vm_fused_branch(int32_t l0, bool l1);
static void vader_vm_grow_frame_records(void* l0, void* l1, size_t l2, size_t l3);
static int32_t vader_vm_i32_of(void* l0, size_t l1, int32_t l2);
static vader_box_t vader_vm_impure_comptime_trap(vader_string_t l0);
static bool vader_vm_in_range(int32_t l0, size_t l1);
static void* vader_vm_indirect_call_trap(void* l0, void* l1, size_t l2, size_t l3, int32_t l4);
static vader_box_t vader_vm_indirect_effect(void* l0, int32_t l1);
static void* vader_vm_infer_function_tags(void* l0, void* l1, size_t l2);
static void* vader_vm_infer_module_tags(void* l0, void* l1);
static bool vader_vm_inlinable_op(vader_box_t l0);
static void* vader_vm_inline_into(void* l0, void* l1, size_t l2);
static void* vader_vm_inline_leaf_calls(void* l0);
static uint8_t vader_vm_integer_operand_tags(uint8_t l0);
static uint8_t vader_vm_integer_tags(uint8_t l0);
static vader_string_t vader_vm_intrinsic_host_mangle(vader_string_t l0, vader_string_t l1);
static bool vader_vm_is_array_view(void* l0);
static bool vader_vm_is_boxed(vader_box_t l0);
static bool vader_vm_is_fn_index_out_of_range(int32_t l0, void* l1);
static bool vader_vm_is_i32_tag(uint8_t l0);
static bool vader_vm_is_impure_host(uint8_t l0);
static bool vader_vm_is_inline_leaf(void* l0);
static bool vader_vm_is_integer_alias(uint8_t l0);
static bool vader_vm_is_source_local(vader_string_t l0);
static bool vader_vm_is_std_handle_symbol(vader_string_t l0);
static bool vader_vm_is_write_symbol(vader_string_t l0);
static void vader_vm_jump(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static vader_box_t vader_vm_lent_element_val_type(void* l0, int32_t l1);
static bool vader_vm_line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_vm_load_bytes_op(void* l0, size_t l1, vader_string_t l2);
static int32_t vader_vm_lookup_vtable_row(void* l0, int32_t l1, int32_t l2);
static void vader_vm_materialise(void* l0, size_t l1, size_t l2);
static vader_box_t vader_vm_merge(void* l0, void* l1, void* l2, size_t l3, size_t l4, size_t l5);
static void vader_vm_merge_block(void* l0, size_t l1, size_t l2, void* l3);
static vader_box_t vader_vm_mirrored_struct_fields(void* l0, void* l1, size_t l2);
static void vader_vm_move_register(void* l0, size_t l1, size_t l2);
static int32_t vader_vm_narrow_code(uint8_t l0);
static vader_box_t vader_vm_narrow_mask(vader_box_t l0, uint8_t l1);
static void vader_vm_narrow_register(void* l0, size_t l1, int32_t l2);
static void* vader_vm_new_blocks(void* l0, void* l1, size_t l2);
static void* vader_vm_new_run_host(void);
static void* vader_vm_new_tag_context(void* l0);
static void vader_vm_note_checked_kind(void* l0, vader_box_t l1);
static vader_string_t vader_vm_op_text(vader_box_t l0);
static int32_t vader_vm_operand(void* l0, size_t l1);
static int32_t vader_vm_operand_a(int64_t l0);
static int32_t vader_vm_operand_b(int64_t l0);
static int32_t vader_vm_operand_c(int64_t l0);
static int32_t vader_vm_operand_of(void* l0, size_t l1, size_t l2);
static bool vader_vm_operands_within(void* l0, size_t l1, uint8_t l2);
static void* vader_vm_overflow_trap(vader_string_t l0);
static void vader_vm_own_bytes(void* l0);
static vader_box_t vader_vm_pack_operands(int32_t l0, int32_t l1, int32_t l2);
static vader_string_t vader_vm_param_display_name(void* l0, size_t l1);
static bool vader_vm_param_mirror_is_mutable(void* l0, size_t l1);
static void* vader_vm_pause_context(void* l0, void* l1, vader_string_t l2, size_t l3, size_t l4);
static void* vader_vm_pause_frame(void* l0, void* l1, void* l2, int32_t l3);
static vader_box_t vader_vm_peek_array_mut(void* l0, size_t l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm_peek_owned(void* l0, size_t l1);
static vader_box_t vader_vm_peek_val(void* l0, size_t l1);
static int32_t vader_vm_pop_to(void* l0, size_t l1);
static vader_box_t vader_vm_prepare_for(void* l0, bool l1);
static vader_box_t vader_vm_prepare_module(void* l0, bool l1);
static void* vader_vm_primitive_impl_import(vader_string_t l0, size_t l1);
static vader_string_t vader_vm_primitive_kind_at(void* l0, int32_t l1);
static bool vader_vm_primitive_matches(vader_box_t l0, uint8_t l1);
static int32_t vader_vm_primitive_type_id(void* l0, vader_box_t l1);
static void* vader_vm_project_locals(void* l0, int32_t l1, void* l2, void* l3);
static void* vader_vm_project_struct_fields(void* l0, void* l1, int32_t l2);
static void* vader_vm_project_var(vader_string_t l0, vader_box_t l1, void* l2, int32_t l3);
static void vader_vm_push_constant(void* l0, vader_box_t l1);
static void vader_vm_push_little_endian(void* l0, int64_t l1, size_t l2);
static void vader_vm_push_register(void* l0, int32_t l1);
static void vader_vm_push_val(void* l0, size_t l1, vader_box_t l2);
static uint8_t vader_vm_pushed_tags(void* l0, vader_box_t l1, void* l2, uint8_t l3);
static vader_box_t vader_vm_read_array(vader_box_t l0, int32_t l1, vader_string_t l2);
static void vader_vm_read_back_mirror(void* l0, size_t l1, void* l2, void* l3, void* l4, int32_t l5);
static vader_box_t vader_vm_read_bool(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_f64(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_fn(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_i32(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_i64(vader_box_t l0, int32_t l1, vader_string_t l2);
static uint64_t vader_vm_read_le(void* l0, size_t l1, size_t l2);
static int64_t vader_vm_read_little_endian(void* l0, size_t l1, size_t l2, bool l3);
static vader_box_t vader_vm_read_numeric_as_f64(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm_read_numeric_as_i64(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm_read_obj(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_scalar_word(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_string(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_struct(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_struct_field(vader_box_t l0, int32_t l1, int32_t l2, vader_string_t l3);
static void* vader_vm_receiver_trap(void* l0, size_t l1, void* l2, size_t l3, vader_string_t l4);
static int32_t vader_vm_receiver_type_id_of(void* l0, vader_box_t l1);
static void* vader_vm_reduce_data_pool(void* l0, void* l1, void* l2);
static int32_t vader_vm_reduce_main_index(void* l0);
static bool vader_vm_ref_type_matches(void* l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_vm_reg_call(void* l0, void* l1, void* l2, int32_t l3, size_t l4, size_t l5, size_t l6, bool l7);
static vader_box_t vader_vm_reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6);
static vader_box_t vader_vm_register_value(void* l0, size_t l1);
static vader_box_t vader_vm_relocated(vader_box_t l0, int32_t l1);
static void vader_vm_reserve_registers(void* l0, size_t l1);
static void vader_vm_reserve_stack(void* l0, size_t l1);
static void vader_vm_reset_stack(void* l0, size_t l1);
static vader_box_t vader_vm_resolve_virtual(void* l0, void* l1, void* l2, size_t l3, size_t l4, bool l5);
static void vader_vm_return_many(void* l0, size_t l1, void* l2);
static bool vader_vm_returns_void(void* l0, int32_t l1);
static vader_box_t vader_vm_retyped_int(vader_box_t l0, int64_t l1);
static vader_box_t vader_vm_run_boxed(void* l0, void* l1, void* l2, size_t l3, size_t l4);
static vader_box_t vader_vm_run_defers(void* l0, void* l1, void* l2, void* l3, size_t l4, size_t l5, size_t l6, bool l7);
static vader_box_t vader_vm_run_thunk(void* l0, void* l1, void* l2, void* l3, size_t l4, size_t l5, size_t l6, bool l7);
static vader_box_t vader_vm_scalar_of(vader_box_t l0);
static void* vader_vm_scratch_frame(void);
static vader_box_t vader_vm_serialise_mirror(void* l0, size_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7);
static void vader_vm_set_bool(void* l0, void* l1, size_t l2, int32_t l3, bool l4);
static vader_box_t vader_vm_set_element(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, size_t l6, int32_t l7);
static void vader_vm_set_f64(void* l0, void* l1, size_t l2, int32_t l3, double l4);
static vader_box_t vader_vm_set_field(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, size_t l6);
static void vader_vm_set_i32(void* l0, void* l1, size_t l2, int32_t l3, int32_t l4);
static void vader_vm_set_i64(void* l0, void* l1, size_t l2, int32_t l3, int64_t l4);
static void vader_vm_set_integer(void* l0, void* l1, size_t l2, int32_t l3, uint8_t l4, int64_t l5);
static void vader_vm_set_register(void* l0, size_t l1, vader_box_t l2);
static bool vader_vm_skips_else(void* l0, size_t l1);
static bool vader_vm_slot_in_scope(void* l0, void* l1, size_t l2, int32_t l3);
static int32_t vader_vm_slot_touched_by(vader_box_t l0);
static uint8_t vader_vm_slot_valtype(void* l0, int32_t l1);
static void vader_vm_stack_grow(void* l0);
static vader_box_t vader_vm_stack_i32(void* l0, size_t l1, vader_string_t l2, vader_string_t l3);
static vader_box_t vader_vm_stack_obj(void* l0, size_t l1, vader_string_t l2);
static uint8_t vader_vm_stack_tags(void* l0, size_t l1, size_t l2);
static bool vader_vm_step_should_stop(uint8_t l0, int32_t l1, int32_t l2);
static void vader_vm_stop_at_line(void* l0, void* l1, void* l2, void* l3, size_t l4, size_t l5);
static vader_box_t vader_vm_store_bytes_op(void* l0, size_t l1, uint64_t l2, vader_string_t l3);
static void vader_vm_store_slot(void* l0, void* l1, size_t l2, int32_t l3, bool l4, int64_t l5);
static void* vader_vm_string_array_to_value(void* l0, int32_t l1);
static void vader_vm_string_constant(void* l0, void* l1, size_t l2, void* l3);
static vader_box_t vader_vm_struct_new_effect(void* l0, int32_t l1);
static uint8_t vader_vm_tags_of_type(void* l0, int32_t l1);
static uint8_t vader_vm_tags_of_val(uint8_t l0);
static bool vader_vm_tags_within(uint8_t l0, uint8_t l1);
static bool vader_vm_trait_implemented_by(void* l0, vader_string_t l1, int32_t l2);
static size_t vader_vm_transfer(void* l0, vader_box_t l1, void* l2, size_t l3, size_t l4, void* l5);
static vader_box_t vader_vm_translate_function(void* l0, int32_t l1, void* l2, bool l3);
static vader_box_t vader_vm_translate_module(void* l0, void* l1, bool l2);
static bool vader_vm_translate_op(void* l0, void* l1, void* l2, void* l3, size_t l4);
static int32_t vader_vm_truncate_to_width(int64_t l0, int64_t l1, bool l2);
static bool vader_vm_try_get_element(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4);
static bool vader_vm_try_set_element(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4);
static int32_t vader_vm_type_id_for_symbol(void* l0, int32_t l1);
static bool vader_vm_type_matches(void* l0, vader_box_t l1, int32_t l2);
static uint8_t vader_vm_type_tags(void* l0, int32_t l1, int32_t l2);
static uint32_t vader_vm_u32_of(void* l0, size_t l1, int32_t l2);
static uint64_t vader_vm_u64_of(void* l0, size_t l1, int32_t l2);
static vader_box_t vader_vm_unary_op(vader_box_t l0, void* l1, size_t l2);
static bool vader_vm_union_matches(void* l0, vader_box_t l1, void* l2);
static void vader_vm_unwind(void* l0, void* l1, void* l2, bool l3);
static vader_box_t vader_vm_validate_fn_index(int32_t l0, void* l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm_value_from_bits(uint8_t l0, uint64_t l1);
static bool vader_vm_value_ref_eq(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_vm_verify_function(void* l0, void* l1);
static vader_box_t vader_vm_verify_module(void* l0);
static size_t vader_vm_virtual_result_arity(void* l0, vader_string_t l1);
static vader_box_t vader_vm_virtual_signature(void* l0, vader_string_t l1);
static int32_t vader_vm_vtable_row_of(void* l0, vader_string_t l1);
static void vader_vm_walk_block(void* l0, void* l1, void* l2, size_t l3, size_t l4, void* l5, vader_box_t l6);
static void vader_vm_write_le(void* l0, size_t l1, size_t l2, uint64_t l3);
static void vader_vm_write_little_endian(void* l0, size_t l1, int64_t l2, size_t l3);
static vader_box_t vader_vm_zero_value(void);

vader_string_t vader_vm_ArrayVal_Display_to_string(void* l0) {
    void* l1 = NULL;
    size_t l2, l3, l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 438u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append(l1, 799u);
    l2 = (size_t) 0;
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string_builder_append(l1, 279u);
        }
        t1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        t2 = vader_chk_add(usize, t1, l2);
        l4 = (size_t) (int64_t) t2;
        t3 = vader_vm_element_at(l0, l4);
        l5 = vader_vm_display_value(t3);
        std_string_builder_append(l1, l5);
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    std_string_builder_append(l1, 802u);
    t4 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_BoolVal_Display_to_string(bool l0) {
    if (l0) {
        return 2376u;
    }
    return 1657u;
}

static vader_string_t vader_vm_CharVal_Display_to_string(uint32_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_char_Display_to_string(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm_ErrorVal_Display_to_string(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_vm_ErrorVal_t*) l0)->f_message;
    t0 = concat_3(395u, l1, 408u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_F64Val_Display_to_string(double l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_f64_Display_to_string(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm_FnVal_Display_to_string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_vm_FnVal_t*) l0)->f_env.tag == 0u) {
        l1 = std_core_new_byte_buffer((size_t) 25);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l1, l2, 396u);
        t0 = ((vader_struct_vader_vm_FnVal_t*) l0)->f_function_index;
        l3 = ((int64_t) (int32_t) t0);
        l2 = std_core_write_int(l1, l2, l3);
        l2 = std_core_write_string_at(l1, l2, 408u);
        t1 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer((size_t) 29);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 396u);
    t0 = ((vader_struct_vader_vm_FnVal_t*) l0)->f_function_index;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 276u);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_I32Val_Display_to_string(int32_t l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 20);
    l2 = (size_t) 0;
    l3 = ((int64_t) (int32_t) l0);
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_I64Val_Display_to_string(int64_t l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 20);
    l2 = (size_t) 0;
    l3 = l0;
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm_NullVal_Display_to_string(void* l0) {
    return 2062u;
}

vader_string_t vader_vm_ObjVal_Display_to_string(void* l0) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_vm_describe_obj(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_StringVal_Display_to_string(vader_string_t l0) {
    return l0;
}

vader_string_t vader_vm_StructVal_Display_to_string(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l6;
    int64_t l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 438u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = std_core_new_byte_buffer((size_t) 22);
    l3 = (size_t) 0;
    t1 = ((vader_struct_vader_vm_StructVal_t*) l0)->f_type_id;
    l4 = ((int64_t) (int32_t) t1);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2659u);
    l5 = std_core_finish_buffer(l2, l3);
    std_string_builder_append(l1, l5);
    l3 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields)->length;
    while ((l3 < l6)) {
        if ((l3 > INT64_C(0))) {
            std_string_builder_append(l1, 279u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
        l5 = vader_vm_display_value(t2);
        std_string_builder_append(l1, l5);
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    std_string_builder_append(l1, 153u);
    t4 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm_TypeVal_Display_to_string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 27);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 400u);
    t0 = ((vader_struct_vader_vm_TypeVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 408u);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_accepted_tags(vader_box_t l0, size_t l1) {
    vader_box_t l2;
    void* t0;
    uint8_t t1;
    if ((l0.tag == 615u || l0.tag == 616u || l0.tag == 618u || l0.tag == 619u || l0.tag == 621u || l0.tag == 623u || l0.tag == 624u || l0.tag == 625u || l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 698u || l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 702u || l0.tag == 703u)) {
        l2 = vader_box_i32(249u, INT32_C(19));
        return l2;
    }
    if ((l0.tag == 617u || l0.tag == 630u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(249u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 622u || l0.tag == 629u)) {
        l2 = vader_box_i32(249u, (INT32_C(19) | INT32_C(32)));
    } else if ((l0.tag == 635u || l0.tag == 636u || l0.tag == 638u || l0.tag == 639u || l0.tag == 641u || l0.tag == 642u || l0.tag == 643u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 647u || l0.tag == 648u || l0.tag == 649u || l0.tag == 651u || l0.tag == 652u || l0.tag == 653u || l0.tag == 654u || l0.tag == 704u || l0.tag == 705u || l0.tag == 706u || l0.tag == 707u || l0.tag == 708u || l0.tag == 709u)) {
        l2 = vader_box_i32(249u, INT32_C(3));
    } else if ((l0.tag == 637u || l0.tag == 650u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(249u, INT32_C(3));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 600u || l0.tag == 602u || l0.tag == 603u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 608u || l0.tag == 609u || l0.tag == 611u)) {
        l2 = vader_box_i32(249u, INT32_C(4));
    } else if (l0.tag == 610u) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(249u, INT32_C(4));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 587u) {
        t0 = l0.payload.obj;
        t1 = vader_vm_integer_operand_tags(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind);
        l2 = vader_box_i32(249u, (int32_t)(uint32_t) t1);
    } else if (l0.tag == 588u) {
        if (l1 == INT64_C(1)) {
            t0 = l0.payload.obj;
            t1 = vader_vm_integer_operand_tags(((vader_struct_vader_bytecode_CheckedNeg_t*) t0)->f_kind);
            l2 = vader_box_i32(249u, (int32_t)(uint32_t) t1);
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 538u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(249u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 545u || l0.tag == 684u || l0.tag == 685u || l0.tag == 686u)) {
        if (l1 == INT64_C(2)) {
            l2 = vader_box_i32(249u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else {
        if (!((l0.tag == 536u || l0.tag == 537u || l0.tag == 539u || l0.tag == 540u || l0.tag == 541u || l0.tag == 542u || l0.tag == 543u || l0.tag == 544u || l0.tag == 546u || l0.tag == 567u || l0.tag == 568u || l0.tag == 569u || l0.tag == 570u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 586u || l0.tag == 589u || l0.tag == 590u || l0.tag == 592u || l0.tag == 593u || l0.tag == 594u || l0.tag == 595u || l0.tag == 598u || l0.tag == 599u || l0.tag == 601u || l0.tag == 612u || l0.tag == 613u || l0.tag == 614u || l0.tag == 620u || l0.tag == 640u || l0.tag == 655u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 673u || l0.tag == 674u || l0.tag == 675u || l0.tag == 676u || l0.tag == 677u || l0.tag == 678u || l0.tag == 679u || l0.tag == 681u || l0.tag == 682u || l0.tag == 683u || l0.tag == 687u || l0.tag == 688u || l0.tag == 689u || l0.tag == 690u || l0.tag == 691u || l0.tag == 692u || l0.tag == 693u || l0.tag == 694u || l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 710u || l0.tag == 711u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    return l2;
}

static void vader_vm_add_constant(vader_box_t l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int64_t l5;
    uint8_t l6;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm_scalar_of(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l3.payload.obj;
    t0 = vader_vm_constant_index(l1, l2, l4);
    if ((t0 < INT64_C(0))) {
        t1 = l3.payload.obj;
        l5 = ((vader_struct_vader_vm_Scalar_t*) t1)->f_bits;
        vader_array_push_i64((vader_array_t*) l1, l5);
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_vm_Scalar_t*) t1)->f_tag;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4) {
    size_t l5, l10;
    void* l6 = NULL;
    void* l13 = NULL;
    int32_t l7, l9;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    bool l12, l18;
    uint8_t l14;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    int64_t l17;
    uint64_t l19;
    void* t0 = NULL;
    int32_t t1;
    size_t t2;
    int64_t t3, t4;
    vader_box_t t5 = vader_box_null();
    bool t6;
    vader_string_t t7 = 0;
    uint64_t t8;
    double t9;
    vader_box_t* gc_roots[4] = { &l2, &l8, &l11, &t5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l13, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l15, &l16, &t7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 614u) {
        l5 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        vader_struct_vader_vm_FnVal_t* _a0_obj = (vader_struct_vader_vm_FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FnVal_t));
        vader_obj_header_init(_a0_obj, 1103u);
        _a0_obj->f_function_index = t1;
        _a0_obj->f_env = vader_box_obj(0u, NULL);
        l6 = (void*) _a0_obj;
        vader_vm_push_val(l3, l5, vader_ref_box(l6));
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_add(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l2.tag == 669u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_owned(l3, l5);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        vader_struct_vader_vm_FnVal_t* _a1_obj = (vader_struct_vader_vm_FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FnVal_t));
        vader_obj_header_init(_a1_obj, 1103u);
        _a1_obj->f_function_index = t1;
        _a1_obj->f_env = l8;
        l6 = (void*) _a1_obj;
        vader_vm_push_val(l3, l5, vader_ref_box(l6));
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 694u) {
        l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l8 = vader_vm_build_struct(l6, l7, l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 540u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        l8 = vader_vm_build_array(l7, l9, l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 546u) {
        l6 = l2.payload.obj;
        l8 = vader_vm_exec_array_slice(l3, l6);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 544u) {
        l8 = vader_vm_exec_array_repeat(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 542u) {
        l8 = vader_vm_exec_array_push_all(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 537u) {
        l8 = vader_vm_exec_array_copy(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 543u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_peek_array_mut(l3, l5, l7, 1307u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l8.payload.obj;
        t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
        if (t2 == INT64_C(0)) {
            l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            t3 = vader_chk_sub(usize, t2, INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(5);
        } else {
            t0 = l8.payload.obj;
            vader_vm_own_bytes(t0);
            t0 = l8.payload.obj;
            l6 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements;
            t0 = l8.payload.obj;
            l5 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
            t0 = l8.payload.obj;
            l10 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            t3 = vader_chk_add(usize, l5, l10);
            t4 = vader_chk_sub(usize, t3, INT64_C(1));
            l5 = (size_t) (int64_t) t4;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            l11 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
            t0 = l8.payload.obj;
            t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
            if (t2 == INT64_C(0)) {
                t0 = l8.payload.obj;
                l5 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
                t0 = l8.payload.obj;
                l10 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements)->length;
                if (l5 == l10) {
                    t0 = l8.payload.obj;
                    t5 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements);
                }
            }
            l6 = l8.payload.obj;
            t0 = l8.payload.obj;
            t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            t3 = vader_chk_sub(usize, t2, INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_length = l5;
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            t3 = vader_chk_sub(usize, t2, INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            vader_vm_push_val(l3, l5, l11);
        }
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 536u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_peek_array_mut(l3, l5, l7, 1289u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l8.payload.obj;
        ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_raw = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) t0);
        t0 = l8.payload.obj;
        t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
        if (t2 == INT64_C(0)) {
            t0 = l8.payload.obj;
            l5 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            t0 = l8.payload.obj;
            l10 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements)->length;
            l12 = l5 == l10;
        } else {
            l12 = false;
        }
        if (l12) {
            t0 = l8.payload.obj;
            vader_array_clear((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements);
        } else {
            l6 = l8.payload.obj;
            vader_array_t* _a4_arr = vader_array_new(205u, 0u, 0u, 1642u);
            l13 = (void*) _a4_arr;
            ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_elements = l13;
            VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) l6);
        }
        t0 = l8.payload.obj;
        ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset = (size_t) 0;
        t0 = l8.payload.obj;
        ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length = (size_t) 0;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 590u) {
        l6 = ((vader_struct_vader_vm_VmState_t*) l0)->f_data_pool;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        t3 = ((int64_t) (int32_t) t1);
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_type_id;
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        if (l7 == l9) {
            l5 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            vader_vm_push_val(l3, l5, vader_ref_box(l6));
        } else {
            l5 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
            l13 = ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_elements;
            l10 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_elements)->length;
            vader_struct_vader_vm_ArrayVal_t* _a6_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
            vader_obj_header_init(_a6_obj, 1098u);
            _a6_obj->f_type_id = l7;
            _a6_obj->f_elements = l13;
            _a6_obj->f_offset = (size_t) 0;
            _a6_obj->f_length = l10;
            _a6_obj->f_raw = vader_box_obj(0u, NULL);
            l6 = (void*) _a6_obj;
            vader_vm_push_val(l3, l5, vader_ref_box(l6));
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_add(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 589u) {
        t0 = l2.payload.obj;
        l14 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_target;
        t0 = l2.payload.obj;
        l15 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        t6 = vader_vm_convert_int_fast(l3, l14, l15);
        if (!(t6)) {
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            t3 = vader_chk_sub(usize, t2, INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            l8 = vader_vm_peek_val(l3, l5);
            t0 = l2.payload.obj;
            l14 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_target;
            t0 = l2.payload.obj;
            l15 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
            l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
            l11 = vader_vm_convert_value(l8, l14, l15, l7);
            if (l11.tag == 1126u) {
                t0 = l11.payload.obj;
                l15 = ((vader_struct_vader_vm_Trap_t*) t0)->f_message;
                l16 = vader_vm_describe_value_tag(l8);
                t7 = concat_6(l15, 26u, l16, 253u, l4, 213u);
                vader_struct_vader_vm_Trap_t* _a7_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a7_obj, 1126u);
                _a7_obj->f_message = t7;
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            t3 = vader_chk_sub(usize, t2, INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            l8 = l11;
            vader_vm_push_val(l3, l5, l8);
        }
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 679u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        if (!(l8.tag == 1127u)) {
            l15 = vader_vm_describe_value_tag(l8);
            l5 = vader_host_std_core_byte_len(l15);
            l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(76) + l5));
            l5 = (size_t) 0;
            l5 = std_core_write_string_at(l6, l5, 1869u);
            l5 = std_core_write_string_at(l6, l5, l15);
            l5 = std_core_write_string_at(l6, l5, 56u);
            t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
            l17 = ((int64_t) (int32_t) t1);
            l5 = std_core_write_int(l6, l5, l17);
            t7 = std_core_finish_buffer(l6, l5);
            vader_struct_vader_vm_Trap_t* _a8_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a8_obj, 1126u);
            _a8_obj->f_message = t7;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l8.payload.obj;
        l7 = ((vader_struct_vader_vm_TypeVal_t*) t0)->f_type_id;
        if ((l7 < INT32_C(0))) {
            l12 = true;
        } else {
            t3 = ((int64_t) (int32_t) l7);
            l5 = (size_t) (int64_t) t3;
            l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types)->length;
            l12 = (l5 >= l10);
        }
        if (l12) {
            l6 = std_core_new_byte_buffer((size_t) 89);
            l5 = (size_t) 0;
            l5 = std_core_write_string_at(l6, l5, 1870u);
            l17 = ((int64_t) (int32_t) l7);
            l5 = std_core_write_int(l6, l5, l17);
            l5 = std_core_write_string_at(l6, l5, 114u);
            t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
            l17 = ((int64_t) (int32_t) t1);
            l5 = std_core_write_int(l6, l5, l17);
            t7 = std_core_finish_buffer(l6, l5);
            vader_struct_vader_vm_Trap_t* _a9_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a9_obj, 1126u);
            _a9_obj->f_message = t7;
            t0 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
        t3 = ((int64_t) (int32_t) l7);
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t5 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
        l7 = vader_bytecode_size_of_bc_type(t5);
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l17 = ((int64_t) (int32_t) l7);
        vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
        ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 622u) {
        l8 = vader_vm_apply_eq_binop(l3, 1769u, false);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 629u) {
        l8 = vader_vm_apply_eq_binop(l3, 1776u, true);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 572u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_bool(l8, l7, 1348u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_bool(l11, l7, 1348u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l12 = l8.payload.b;
        l18 = l11.payload.b;
        if (l12 == l18) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
        ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 573u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_bool(l8, l7, 1349u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_bool(l11, l7, 1349u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l12 = l8.payload.b;
        l18 = l11.payload.b;
        if (l12 != l18) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l5)
        ((int64_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l5)
        ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 570u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_bool(l8, l7, 1346u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_bool(l11, l7, 1346u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t6 = l8.payload.b;
        if (t6) {
            l12 = l11.payload.b;
        } else {
            l12 = false;
        }
        if (l12) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
        ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a18_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l5)
        ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 575u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_bool(l8, l7, 1351u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_bool(l11, l7, 1351u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t6 = l8.payload.b;
        if (t6) {
            l12 = true;
        } else {
            l12 = l11.payload.b;
        }
        if (l12) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l5)
        ((int64_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a20_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l5)
        ((uint8_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 574u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_bool(l8, l7, 1350u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        t6 = l8.payload.b;
        if (t6) {
            l17 = INT64_C(0);
        } else {
            l17 = INT64_C(1);
        }
        vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
        ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a22_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l5)
        ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 690u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_string(l8, l7, 2280u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_string(l11, l7, 2280u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l15 = l8.payload.s;
        l16 = l11.payload.s;
        if (l15 == l16) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l5)
        ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l5)
        ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 691u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_string(l8, l7, 2282u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_string(l11, l7, 2282u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l15 = l8.payload.s;
        l16 = l11.payload.s;
        if (l15 != l16) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
        ((int64_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a26_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l5)
        ((uint8_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 688u) {
        l8 = vader_vm_exec_string_compare(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 692u) {
        l8 = vader_vm_exec_string_slice_codepoints(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 674u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l12 = vader_vm_value_ref_eq(l8, l11);
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        if (l12) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
        ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
        ((uint8_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 675u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l12 = vader_vm_value_ref_eq(l8, l11);
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        if (l12) {
            l17 = INT64_C(0);
        } else {
            l17 = INT64_C(1);
        }
        vader_array_t* _a29_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
        ((int64_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a30_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
        ((uint8_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 696u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        l12 = vader_vm_type_matches(l0, l8, l7);
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        if (l12) {
            l17 = INT64_C(1);
        } else {
            l17 = INT64_C(0);
        }
        vader_array_t* _a31_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
        ((int64_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a32_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l5)
        ((uint8_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 697u) {
        l5 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        vader_struct_vader_vm_TypeVal_t* _a33_obj = (vader_struct_vader_vm_TypeVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_TypeVal_t));
        vader_obj_header_init(_a33_obj, 1127u);
        _a33_obj->f_type_id = t1;
        l6 = (void*) _a33_obj;
        vader_vm_push_val(l3, l5, vader_ref_box(l6));
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_add(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 578u) {
        l6 = ((vader_struct_vader_vm_RunHost_t*) l1)->f_obj_handles;
        l8 = vader_vm_build_buffer(l3, l6);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 663u) {
        l8 = vader_vm_load_bytes_op(l3, (size_t) 1, 1949u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t8 = ((uint64_t) l8.payload.i);
        l17 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t8));
        vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l5)
        ((int64_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a35_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l5)
        ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 658u) {
        l8 = vader_vm_load_bytes_op(l3, (size_t) 4, 1943u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t8 = ((uint64_t) l8.payload.i);
        l17 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t8));
        vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l5)
        ((int64_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a37_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l5)
        ((uint8_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 659u) {
        l8 = vader_vm_load_bytes_op(l3, (size_t) 8, 1944u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t8 = ((uint64_t) l8.payload.i);
        l17 = ((int64_t) (uint64_t) t8);
        vader_array_t* _a38_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l5)
        ((int64_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a39_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l5)
        ((uint8_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(1);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 657u) {
        l8 = vader_vm_load_bytes_op(l3, (size_t) 8, 1942u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t8 = ((uint64_t) l8.payload.i);
        l17 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t8) }).__vd) }).__vu);
        vader_array_t* _a40_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l5)
        ((int64_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a41_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l5)
        ((uint8_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(2);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 687u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_stack_i32(l3, l5, 2271u, 2604u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l8.payload.i);
        t3 = ((int64_t) (uint32_t) (t1 & INT32_C(255)));
        l19 = (uint64_t) (int64_t) t3;
        l8 = vader_vm_store_bytes_op(l3, (size_t) 1, l19, 2271u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 682u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_stack_i32(l3, l5, 2264u, 2604u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l8.payload.i);
        t3 = ((int64_t) (uint32_t) t1);
        l19 = (uint64_t) (int64_t) t3;
        l8 = vader_vm_store_bytes_op(l3, (size_t) 4, l19, 2264u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 683u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_i64(l8, l7, 2266u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((int64_t) l8.payload.i);
        t4 = t3;
        l19 = (uint64_t) (int64_t) t4;
        l8 = vader_vm_store_bytes_op(l3, (size_t) 8, l19, 2265u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 681u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_f64(l8, l7, 2263u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t9 = ((double) l8.payload.f);
        t3 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t9 }).__vu);
        l19 = (uint64_t) (int64_t) t3;
        l8 = vader_vm_store_bytes_op(l3, (size_t) 8, l19, 2262u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 670u) {
        l8 = vader_vm_do_memory_copy(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 579u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_i32(l8, l7, 1371u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        l11 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l11 = vader_vm_read_obj(l11, l7, 1372u);
        if (l11.tag == 1126u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((int32_t) l8.payload.i);
        t0 = l11.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t0)->f_bytes)->length;
        l9 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_check_byte_range(l7, (size_t) 0, l5, 1370u, l9);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(2));
        l5 = (size_t) (int64_t) t3;
        t0 = l11.payload.obj;
        l6 = ((vader_struct_vader_vm_ObjVal_t*) t0)->f_bytes;
        l10 = ((size_t) l8.payload.i);
        vader_array_t* _a42_arr = vader_array_slice((vader_array_t*) l6, (size_t) INT64_C(0), (size_t) l10);
        t0 = (void*) _a42_arr;
        l15 = vader_host_std_core_bytes_to_string(t0);
        t5 = vader_box_string(243u, l15);
        vader_vm_push_val(l3, l5, t5);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l5;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 580u) {
        l8 = vader_vm_exec_buffer_write_string(l3);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 612u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_f64(l8, l7, 1654u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        t9 = ((double) l8.payload.f);
        l17 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t9 }).__vu);
        vader_array_t* _a43_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l5)
        ((int64_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a44_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l5)
        ((uint8_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 568u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_i64(l8, l7, 1342u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        t3 = ((int64_t) l8.payload.i);
        l17 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t3) }).__vd) }).__vu);
        vader_array_t* _a45_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l5)
        ((int64_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a46_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l5)
        ((uint8_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 599u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_f64(l8, l7, 1640u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        t9 = ((double) l8.payload.f);
        l17 = ((int64_t) (int32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = t9 }).__vb));
        vader_array_t* _a47_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l5)
        ((int64_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a48_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l5)
        ((uint8_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(0);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    } else if (l2.tag == 567u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        l8 = vader_vm_peek_val(l3, l5);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_vm_read_i32(l8, l7, 1341u);
        if (l8.tag == 1126u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        t1 = ((int32_t) l8.payload.i);
        l17 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(t1) }).__vf)) }).__vu);
        vader_array_t* _a49_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l5)
        ((int64_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l5] = (int64_t) l17;
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t3 = vader_chk_sub(usize, t2, INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a50_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l5)
        ((uint8_t*) _a50_slotarr->buf->slots)[_a50_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l7 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l7;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_apply_eq_binop(void* l0, vader_string_t l1, bool l2) {
    void* l3 = NULL;
    size_t l4;
    uint8_t l5, l6;
    bool l7, l8;
    int32_t l9, l10;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    int64_t l13;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    void* t4 = NULL;
    int32_t t5;
    vader_box_t* gc_roots[3] = { &l11, &l12, &t2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t4 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 249u);
    l5 = ((uint8_t) t2.payload.i);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 249u);
    l6 = ((uint8_t) t2.payload.i);
    l7 = false;
    if (l5 == INT32_C(5)) {
        l8 = true;
    } else {
        l8 = l6 == INT32_C(5);
    }
    if (l8) {
        if (l5 == INT32_C(5)) {
            l8 = l6 == INT32_C(5);
        } else {
            l8 = false;
        }
        l7 = l8;
    } else {
        t3 = vader_vm_is_i32_tag(l5);
        if (t3) {
            l8 = vader_vm_is_i32_tag(l6);
        } else {
            l8 = false;
        }
        if (l8) {
            l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            t1 = vader_chk_sub(usize, t0, INT64_C(2));
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            l9 = ((int32_t) (int64_t) t1);
            l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            t1 = vader_chk_sub(usize, t0, INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
            l10 = ((int32_t) (int64_t) t1);
            l7 = l9 == l10;
        } else {
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            t1 = vader_chk_sub(usize, t0, INT64_C(2));
            l4 = (size_t) (int64_t) t1;
            l11 = vader_vm_peek_val(l0, l4);
            l9 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
            l11 = vader_vm_read_i32(l11, l9, l1);
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            t1 = vader_chk_sub(usize, t0, INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            l12 = vader_vm_peek_val(l0, l4);
            l9 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
            l12 = vader_vm_read_i32(l12, l9, l1);
            if (l11.tag == 1126u) {
                t4 = l11.payload.obj;
                { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l12.tag == 1126u) {
                t4 = l12.payload.obj;
                { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = ((int32_t) l11.payload.i);
            l10 = ((int32_t) l12.payload.i);
            l7 = l9 == l10;
        }
    }
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l4 = (size_t) (int64_t) t1;
    if (l2) {
        l8 = !(l7);
    } else {
        l8 = l7;
    }
    if (l8) {
        l13 = INT64_C(1);
    } else {
        l13 = INT64_C(0);
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) l13;
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) INT32_C(3);
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l4;
    t5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l9 = vader_chk_add(i32, t5, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l9;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_array_at(void* l0, size_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 1098u) {
            t1 = l2.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_vm_array_bytes(void* l0, size_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6, l7;
    uint8_t l9;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l4, &t3 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw;
    if (!(l4.tag == 0u)) {
        l5 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        t1 = vader_chk_add(usize, t0, l1);
        l7 = (size_t) (int64_t) t1;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l5, (size_t) l6, (size_t) l7);
        t2 = (void*) _a0_arr;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 1u, 249u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) 0;
    while ((l6 < l1)) {
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        t1 = vader_chk_add(usize, t0, l6);
        l7 = (size_t) (int64_t) t1;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l4 = vader_vm_read_i64(t3, l2, l3);
        if (l4.tag == 1126u) {
            t2 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int64_t) l4.payload.i);
        t4 = (((int32_t) (int64_t) t1) & INT32_C(255));
        l9 = (uint8_t) (int32_t) t4;
        vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l9);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_bc_value_to_vm(vader_box_t l0, void* l1) {
    uint8_t l2;
    uint64_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[3] = { &l0, &l8, &t2 };
    void** gc_raw_roots[4] = { &l1, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 565u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        t2 = vader_box_string(243u, t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 564u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_bits;
        t2 = vader_vm_value_from_bits(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 566u) {
        vader_array_t* _a0_arr = vader_array_new(205u, 0u, 0u, 1642u);
        l4 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l8 = vader_vm_bc_value_to_vm(t2, l1);
            vader_array_push((vader_array_t*) l4, l8);
            t3 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t3;
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_symbol_id;
        t4 = vader_vm_type_id_for_symbol(l1, l9);
        vader_struct_vader_vm_StructVal_t* _a2_obj = (vader_struct_vader_vm_StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StructVal_t));
        vader_obj_header_init(_a2_obj, 1123u);
        _a2_obj->f_type_id = t4;
        _a2_obj->f_fields = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 563u)) {
        { vader_box_t __vret = vader_box_i32(246u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l4 = (void*) _a3_arr;
    t0 = l0.payload.obj;
    l5 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l8 = vader_vm_bc_value_to_vm(t2, l1);
        vader_array_push((vader_array_t*) l4, l8);
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    l6 = ((vader_array_t*) l4)->length;
    vader_struct_vader_vm_ArrayVal_t* _a5_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a5_obj, 1098u);
    _a5_obj->f_type_id = INT32_C(0);
    _a5_obj->f_elements = l4;
    _a5_obj->f_offset = (size_t) 0;
    _a5_obj->f_length = l6;
    _a5_obj->f_raw = vader_box_obj(0u, NULL);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_binary_op(vader_box_t l0, void* l1, size_t l2) {
    vader_box_t l3;
    bool t0;
    void* t1;
    int32_t t2;
    if (l0.tag == 615u) {
        l3 = vader_box_i32(246u, INT32_C(2));
        return l3;
    }
    if (l0.tag == 634u) {
        l3 = vader_box_i32(246u, INT32_C(3));
    } else if (l0.tag == 628u) {
        l3 = vader_box_i32(246u, INT32_C(4));
    } else if (l0.tag == 621u) {
        l3 = vader_box_i32(246u, INT32_C(5));
    } else if (l0.tag == 627u) {
        l3 = vader_box_i32(246u, INT32_C(6));
    } else if (l0.tag == 616u) {
        l3 = vader_box_i32(246u, INT32_C(7));
    } else if (l0.tag == 618u) {
        l3 = vader_box_i32(246u, INT32_C(8));
    } else if (l0.tag == 619u) {
        l3 = vader_box_i32(246u, INT32_C(9));
    } else if (l0.tag == 631u) {
        l3 = vader_box_i32(246u, INT32_C(10));
    } else if (l0.tag == 632u) {
        l3 = vader_box_i32(246u, INT32_C(11));
    } else if (l0.tag == 633u) {
        l3 = vader_box_i32(246u, INT32_C(12));
    } else if (l0.tag == 698u) {
        l3 = vader_box_i32(246u, INT32_C(15));
    } else if (l0.tag == 703u) {
        l3 = vader_box_i32(246u, INT32_C(16));
    } else if (l0.tag == 622u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(246u, INT32_C(17));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 629u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(246u, INT32_C(18));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 626u) {
        l3 = vader_box_i32(246u, INT32_C(19));
    } else if (l0.tag == 625u) {
        l3 = vader_box_i32(246u, INT32_C(20));
    } else if (l0.tag == 624u) {
        l3 = vader_box_i32(246u, INT32_C(21));
    } else if (l0.tag == 623u) {
        l3 = vader_box_i32(246u, INT32_C(22));
    } else if (l0.tag == 702u) {
        l3 = vader_box_i32(246u, INT32_C(23));
    } else if (l0.tag == 701u) {
        l3 = vader_box_i32(246u, INT32_C(24));
    } else if (l0.tag == 700u) {
        l3 = vader_box_i32(246u, INT32_C(25));
    } else if (l0.tag == 699u) {
        l3 = vader_box_i32(246u, INT32_C(26));
    } else if (l0.tag == 635u) {
        l3 = vader_box_i32(246u, INT32_C(27));
    } else if (l0.tag == 654u) {
        l3 = vader_box_i32(246u, INT32_C(28));
    } else if (l0.tag == 648u) {
        l3 = vader_box_i32(246u, INT32_C(29));
    } else if (l0.tag == 641u) {
        l3 = vader_box_i32(246u, INT32_C(30));
    } else if (l0.tag == 647u) {
        l3 = vader_box_i32(246u, INT32_C(31));
    } else if (l0.tag == 636u) {
        l3 = vader_box_i32(246u, INT32_C(32));
    } else if (l0.tag == 638u) {
        l3 = vader_box_i32(246u, INT32_C(33));
    } else if (l0.tag == 639u) {
        l3 = vader_box_i32(246u, INT32_C(34));
    } else if (l0.tag == 651u) {
        l3 = vader_box_i32(246u, INT32_C(35));
    } else if (l0.tag == 652u) {
        l3 = vader_box_i32(246u, INT32_C(36));
    } else if (l0.tag == 653u) {
        l3 = vader_box_i32(246u, INT32_C(37));
    } else if (l0.tag == 704u) {
        l3 = vader_box_i32(246u, INT32_C(40));
    } else if (l0.tag == 709u) {
        l3 = vader_box_i32(246u, INT32_C(41));
    } else if (l0.tag == 642u) {
        l3 = vader_box_i32(246u, INT32_C(42));
    } else if (l0.tag == 649u) {
        l3 = vader_box_i32(246u, INT32_C(43));
    } else if (l0.tag == 646u) {
        l3 = vader_box_i32(246u, INT32_C(44));
    } else if (l0.tag == 645u) {
        l3 = vader_box_i32(246u, INT32_C(45));
    } else if (l0.tag == 644u) {
        l3 = vader_box_i32(246u, INT32_C(46));
    } else if (l0.tag == 643u) {
        l3 = vader_box_i32(246u, INT32_C(47));
    } else if (l0.tag == 708u) {
        l3 = vader_box_i32(246u, INT32_C(48));
    } else if (l0.tag == 707u) {
        l3 = vader_box_i32(246u, INT32_C(49));
    } else if (l0.tag == 706u) {
        l3 = vader_box_i32(246u, INT32_C(50));
    } else if (l0.tag == 705u) {
        l3 = vader_box_i32(246u, INT32_C(51));
    } else if (l0.tag == 600u) {
        l3 = vader_box_i32(246u, INT32_C(52));
    } else if (l0.tag == 611u) {
        l3 = vader_box_i32(246u, INT32_C(53));
    } else if (l0.tag == 608u) {
        l3 = vader_box_i32(246u, INT32_C(54));
    } else if (l0.tag == 602u) {
        l3 = vader_box_i32(246u, INT32_C(55));
    } else if (l0.tag == 603u) {
        l3 = vader_box_i32(246u, INT32_C(57));
    } else if (l0.tag == 609u) {
        l3 = vader_box_i32(246u, INT32_C(58));
    } else if (l0.tag == 607u) {
        l3 = vader_box_i32(246u, INT32_C(59));
    } else if (l0.tag == 606u) {
        l3 = vader_box_i32(246u, INT32_C(60));
    } else if (l0.tag == 605u) {
        l3 = vader_box_i32(246u, INT32_C(61));
    } else if (l0.tag == 604u) {
        l3 = vader_box_i32(246u, INT32_C(62));
    } else if (l0.tag == 572u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(246u, INT32_C(63));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 573u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(246u, INT32_C(64));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 570u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(246u, INT32_C(65));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 575u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(246u, INT32_C(66));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 587u) {
        t1 = l0.payload.obj;
        t2 = vader_vm_checked_register_op(t1);
        l3 = vader_box_i32(246u, t2);
    } else {
        l3 = vader_box_obj(0u, NULL);
    }
    return l3;
}

static int64_t vader_vm_bits_of(void* l0, size_t l1, int32_t l2) {
    size_t l3;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l3);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return t0;
}

static void vader_vm_boxed(void* l0, size_t l1, vader_box_t l2, size_t l3, size_t l4) {
    int32_t l5, l6, l8;
    size_t l7;
    size_t t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_vm_flush(l0, l1);
    l5 = vader_vm_pop_to(l0, l3);
    vader_array_push((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_boxed, l2);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_boxed)->length;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l6 = ((int32_t) (int64_t) t1);
    t1 = (l4 << INT64_C(8));
    l7 = (size_t) (int64_t) t1;
    l8 = ((int32_t) (int64_t) (l3 | l7));
    vader_vm_emit(l0, l1, INT32_C(118), l6, l5, l8);
    l7 = (size_t) 0;
    while ((l7 < l4)) {
        l6 = ((int32_t) (size_t) l7);
        l8 = vader_chk_add(i32, l5, l6);
        vader_vm_push_register(l0, l8);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm_branch(bool l0, int32_t l1, bool l2, int32_t l3, bool l4) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0) {
        vader_struct_vader_vm_FusedBranch_t* _a0_obj = (vader_struct_vader_vm_FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FusedBranch_t));
        vader_obj_header_init(_a0_obj, 1106u);
        _a0_obj->f_op = l1;
        _a0_obj->f_swap = l2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_FusedBranch_t* _a1_obj = (vader_struct_vader_vm_FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FusedBranch_t));
    vader_obj_header_init(_a1_obj, 1106u);
    _a1_obj->f_op = l3;
    _a1_obj->f_swap = l4;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_budget_trap(int64_t l0) {
    void* l1 = NULL;
    size_t l2;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 84);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1483u);
    l2 = std_core_write_int(l1, l2, l0);
    l2 = std_core_write_string_at(l1, l2, 132u);
    t0 = std_core_finish_buffer(l1, l2);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1126u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_build_array(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    size_t l4, l6, l7, l8;
    int64_t l5;
    vader_box_t l9 = vader_box_null();
    int32_t l10;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    size_t t4;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[3] = { &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l3 = std_core_new_byte_buffer((size_t) 76);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1301u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l3, l4, l5);
        l4 = std_core_write_string_at(l3, l4, 91u);
        t0 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core_write_int(l3, l4, l5);
        t1 = std_core_finish_buffer(l3, l4);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t3;
    t4 = ((vader_struct_vader_vm_Frame_t*) l2)->f_sp;
    t3 = vader_chk_sub(usize, t4, l4);
    l6 = (size_t) (int64_t) t3;
    vader_array_t* _a1_arr = vader_array_new(205u, 0u, 0u, 1642u);
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l4);
    l3 = (void*) _a2_arr;
    l7 = (size_t) 0;
    while ((l7 < l4)) {
        t3 = vader_chk_add(usize, l6, l7);
        l8 = (size_t) (int64_t) t3;
        l9 = vader_vm_peek_owned(l2, l8);
        vader_array_push((vader_array_t*) l3, l9);
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    l4 = ((vader_array_t*) l3)->length;
    vader_struct_vader_vm_ArrayVal_t* _a3_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1098u);
    _a3_obj->f_type_id = l0;
    _a3_obj->f_elements = l3;
    _a3_obj->f_offset = (size_t) 0;
    _a3_obj->f_length = l4;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    l3 = (void*) _a3_obj;
    vader_vm_push_val(l2, l6, vader_ref_box(l3));
    t3 = vader_chk_add(usize, l6, INT64_C(1));
    l4 = (size_t) (int64_t) t3;
    ((vader_struct_vader_vm_Frame_t*) l2)->f_sp = l4;
    t0 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
    l10 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l2)->f_pc = l10;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_build_buffer(void* l0, void* l1) {
    size_t l2, l7;
    vader_box_t l3 = vader_box_null();
    int32_t l4;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    l3 = vader_vm_peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_vm_read_i32(l3, l4, 1368u);
    if (l3.tag == 1126u) {
        t2 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int32_t) l3.payload.i);
    if ((t3 < INT32_C(0))) {
        l5 = std_core_new_byte_buffer((size_t) 75);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l5, l2, 1369u);
        t3 = ((int32_t) l3.payload.i);
        l6 = ((int64_t) (int32_t) t3);
        l2 = std_core_write_int(l5, l2, l6);
        l2 = std_core_write_string_at(l5, l2, 91u);
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l6 = ((int64_t) (int32_t) t3);
        l2 = std_core_write_int(l5, l2, l6);
        t4 = std_core_finish_buffer(l5, l2);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t4;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 1u, 249u);
    l5 = (void*) _a1_arr;
    t3 = ((int32_t) l3.payload.i);
    t1 = ((int64_t) (int32_t) t3);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l2);
    l5 = (void*) _a2_arr;
    l2 = (size_t) 0;
    t3 = ((int32_t) l3.payload.i);
    t1 = ((int64_t) (int32_t) t3);
    l7 = (size_t) (int64_t) t1;
    vader_array_t* _pc83_hdr = (vader_array_t*) l5;
    size_t _pc83_len = _pc83_hdr->length;
    size_t _pc83_cap = (_pc83_hdr->offset == 0 && !vader_array_is_borrowed(_pc83_hdr) && _pc83_hdr->length >= _pc83_hdr->buf->length) ? _pc83_hdr->capacity : (size_t) 0;
    void* _pc83_slots = _pc83_hdr->buf->slots;
    for (;;) {
        if ((l2 < l7)) {
            if (VADER_LIKELY(_pc83_len < _pc83_cap)) {
                ((uint8_t*) _pc83_slots)[_pc83_len] = (uint8_t) (INT32_C(0));
                _pc83_len += 1;
            } else {
                _pc83_hdr->length = _pc83_len;
                if (_pc83_hdr->buf->length < _pc83_len) {
                    _pc83_hdr->buf->length = _pc83_len;
                }
                vader_array_push_u8((vader_array_t*) l5, INT32_C(0));
                _pc83_hdr = (vader_array_t*) l5;
                _pc83_len = _pc83_hdr->length;
                _pc83_cap = (_pc83_hdr->offset == 0 && !vader_array_is_borrowed(_pc83_hdr) && _pc83_hdr->length >= _pc83_hdr->buf->length) ? _pc83_hdr->capacity : (size_t) 0;
                _pc83_slots = _pc83_hdr->buf->slots;
            }
            t1 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t1;
            continue;
        }
        _pc83_hdr->length = _pc83_len;
        if (_pc83_hdr->buf->length < _pc83_len) {
            _pc83_hdr->buf->length = _pc83_len;
        }
        break;
    }
    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
    l4 = vader_chk_add(i32, t3, INT32_C(1));
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)] = (int32_t) l4;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
    vader_array_t* _a4_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l8 = (void*) _a4_arr;
    vader_struct_vader_vm_ObjVal_t* _a5_obj = (vader_struct_vader_vm_ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ObjVal_t));
    vader_obj_header_init(_a5_obj, 1111u);
    _a5_obj->f_handle = l4;
    _a5_obj->f_type_id = INT32_C(0);
    _a5_obj->f_bytes = l5;
    _a5_obj->f_slots = l8;
    l5 = (void*) _a5_obj;
    vader_vm_push_val(l0, l2, vader_ref_box(l5));
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l4;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_build_main_args(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l7;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    uint64_t l9;
    uint8_t l10;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t t4 = vader_box_null();
    bool t5;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l8, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params;
    t0 = ((vader_array_t*) l4)->length;
    if (t0 == INT64_C(0)) {
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l4)->length;
    if ((t0 > INT64_C(1))) {
        l5 = ((vader_array_t*) l4)->length;
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
        l7 = vader_host_std_core_byte_len(l6);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(76) + l7));
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l8, l7, 1569u);
        l7 = std_core_write_string_at(l8, l7, l6);
        l7 = std_core_write_string_at(l8, l7, 222u);
        t1 = ((int64_t) (size_t) l5);
        l9 = (uint64_t) (int64_t) t1;
        l7 = std_core_write_unsigned(l8, l7, l9);
        l7 = std_core_write_string_at(l8, l7, 121u);
        t2 = std_core_finish_buffer(l8, l7);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1126u);
        _a1_obj->f_message = t2;
        t3 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t4 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(0), 249u);
    l10 = vader_vm_tags_of_val(((uint8_t) t4.payload.i));
    t5 = vader_vm_tags_within((uint8_t) 64, l10);
    if (!(t5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t4 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) INT32_C(0), 249u);
        l6 = vader_bytecode_val_type_name(((uint8_t) t4.payload.i));
        l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
        t2 = concat_5(1569u, l11, 223u, l6, 282u);
        vader_struct_vader_vm_Trap_t* _a4_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a4_obj, 1126u);
        _a4_obj->f_message = t2;
        t3 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a5_arr = vader_array_new(13u, 1u, 0u, 243u);
        vader_array_box_slots(_a5_arr->buf)[_a5_arr->offset + 0u] = vader_box_string(243u, 402u);
        t3 = (void*) _a5_arr;
        l4 = vader_vm_string_array_to_value(t3, l2);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm_string_array_to_value(l1, l2);
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_build_struct(void* l0, int32_t l1, void* l2) {
    size_t l3, l7, l8, l11;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null();
    void* l5 = NULL;
    int64_t l6;
    int32_t l9;
    uint8_t l10;
    int64_t t0;
    int32_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    size_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l12, &t5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 561u)) {
        l5 = std_core_new_byte_buffer((size_t) 79);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l5, l3, 2302u);
        l6 = ((int64_t) (int32_t) l1);
        l3 = std_core_write_int(l5, l3, l6);
        l3 = std_core_write_string_at(l5, l3, 93u);
        t1 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
        l6 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l5, l3, l6);
        t2 = std_core_finish_buffer(l5, l3);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1126u);
        _a1_obj->f_message = t2;
        t3 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l4.payload.obj;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields)->length;
    t4 = ((vader_struct_vader_vm_Frame_t*) l2)->f_sp;
    t0 = vader_chk_sub(usize, t4, l3);
    l7 = (size_t) (int64_t) t0;
    vader_array_t* _a2_arr = vader_array_new(205u, 0u, 0u, 1642u);
    t3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t3, (size_t) l3);
    l5 = (void*) _a3_arr;
    l8 = (size_t) 0;
    while ((l8 < l3)) {
        t3 = l4.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t3 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_bytecode_BcField_t*) t3)->f_type_index;
        l10 = vader_vm_field_valtype(l0, l9);
        t0 = vader_chk_add(usize, l7, l8);
        l11 = (size_t) (int64_t) t0;
        t5 = vader_vm_peek_owned(l2, l11);
        l12 = vader_vm_narrow_mask(t5, l10);
        vader_array_push((vader_array_t*) l5, l12);
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    vader_struct_vader_vm_StructVal_t* _a5_obj = (vader_struct_vader_vm_StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StructVal_t));
    vader_obj_header_init(_a5_obj, 1123u);
    _a5_obj->f_type_id = l1;
    _a5_obj->f_fields = l5;
    l5 = (void*) _a5_obj;
    vader_vm_push_val(l2, l7, vader_ref_box(l5));
    t0 = vader_chk_add(usize, l7, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_vader_vm_Frame_t*) l2)->f_sp = l3;
    t1 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
    l9 = vader_chk_add(i32, t1, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l2)->f_pc = l9;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_vm_bytes_to_value(vader_string_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l0);
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l2)->length;
    vader_struct_vader_vm_ArrayVal_t* _a1_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a1_obj, 1098u);
    _a1_obj->f_type_id = l1;
    _a1_obj->f_elements = l3;
    _a1_obj->f_offset = (size_t) 0;
    _a1_obj->f_length = l4;
    _a1_obj->f_raw = vader_ref_box(l2);
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_call_import(void* l0, void* l1, int32_t l2, size_t l3, int32_t l4, bool l5) {
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    size_t l7, l9, l10;
    vader_box_t l11 = vader_box_null();
    int32_t l14, l15, l16;
    uint8_t l19;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    uint8_t t3;
    vader_box_t* gc_roots[2] = { &l11, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l6, &l8, &l12, &l13, &l17, &l18, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_imports;
    t0 = ((int64_t) (int32_t) l2);
    l7 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    vader_array_t* _a1_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l8 = (void*) _a1_arr;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_params)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l8, (size_t) l7);
    l8 = (void*) _a2_arr;
    l7 = (size_t) 0;
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_params)->length;
    while ((l7 < l9)) {
        t0 = vader_chk_add(usize, l3, l7);
        l10 = (size_t) (int64_t) t0;
        l11 = vader_vm_register_value(l1, l10);
        vader_array_push((vader_array_t*) l8, l11);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l12 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_gc_state;
    l13 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_sched_state;
    l14 = ((vader_struct_vader_vm_VmState_t*) l0)->f_string_array_type_id;
    l15 = ((vader_struct_vader_vm_VmState_t*) l0)->f_u8_array_type_id;
    l16 = ((vader_struct_vader_vm_VmState_t*) l0)->f_io_error_type_id;
    l17 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
    l11 = vader_vm_debug_controller(l1);
    l18 = ((vader_struct_vader_vm_VmState_t*) l0)->f_import_ids;
    t0 = ((int64_t) (int32_t) l2);
    l7 = (size_t) (int64_t) t0;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l18);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
    t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 249u);
    l19 = ((uint8_t) t1.payload.i);
    l11 = vader_vm_dispatch_import(l6, l8, (size_t) 0, l12, l13, l4, l14, l15, l16, l17, l5, l11, l19);
    if (l11.tag == 1126u) {
        t2 = l11.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature);
    if (t3 != INT32_C(16)) {
        t2 = l11.payload.obj;
        l11 = ((vader_struct_vader_vm_HostOk_t*) t2)->f_value;
        vader_vm_set_register(l1, l3, l11);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_call_results(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_module;
    if (l1.tag == 583u) {
        l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l2)->f_functions;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        t2 = ((int64_t) (int32_t) t1);
        l4 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        { vader_box_t __vret = vader_ref_box(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_signature)->f_results); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 584u) {
        l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l2)->f_imports;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t2 = ((int64_t) (int32_t) t1);
        l4 = (size_t) (int64_t) t2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        { vader_box_t __vret = vader_ref_box(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) t0)->f_signature)->f_results); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 711u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_virtual_results;
    t0 = l1.payload.obj;
    l5 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
    l6 = std_collections_MutableMap_Index_at__string__Any(l2, l5);
    if (l6.tag == 0u) {
        vader_array_t* _a2_arr = vader_array_new(16u, 1u, 1u, 249u);
        ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(19);
        t0 = (void*) _a2_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l6.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_canonical(void* l0, size_t l1) {
    size_t t0;
    int64_t t1;
    t0 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack_base;
    t1 = vader_chk_add(usize, t0, l1);
    return ((int32_t) (int64_t) t1);
}

static vader_box_t vader_vm_check_byte_range(int32_t l0, size_t l1, size_t l2, vader_string_t l3, int32_t l4) {
    vader_string_t l5 = 0;
    size_t l6, l9;
    void* l7 = NULL;
    int64_t l8;
    uint64_t l10;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        l5 = l3;
        l6 = vader_host_std_core_byte_len(l5);
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(67) + l6));
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l7, l6, l5);
        l6 = std_core_write_string_at(l7, l6, 110u);
        l8 = ((int64_t) (int32_t) l0);
        l6 = std_core_write_int(l7, l6, l8);
        l6 = std_core_write_string_at(l7, l6, 91u);
        l8 = ((int64_t) (int32_t) l4);
        l6 = std_core_write_int(l7, l6, l8);
        t0 = std_core_finish_buffer(l7, l6);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int64_t) (int32_t) l0);
    l6 = (size_t) (int64_t) t2;
    t2 = vader_chk_add(usize, l6, l1);
    if (!((t2 > l2))) {
        t3 = vader_box_i64(253u, (int64_t)(uint64_t) l6);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l9 = vader_host_std_core_byte_len(l5);
    l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(127) + l9));
    l9 = (size_t) 0;
    l9 = std_core_write_string_at(l7, l9, l5);
    l9 = std_core_write_string_at(l7, l9, 110u);
    t2 = ((int64_t) (size_t) l6);
    l10 = (uint64_t) (int64_t) t2;
    l9 = std_core_write_unsigned(l7, l9, l10);
    l9 = std_core_write_string_at(l7, l9, 25u);
    t2 = ((int64_t) (size_t) l1);
    l10 = (uint64_t) (int64_t) t2;
    l9 = std_core_write_unsigned(l7, l9, l10);
    l9 = std_core_write_string_at(l7, l9, 252u);
    t2 = ((int64_t) (size_t) l2);
    l10 = (uint64_t) (int64_t) t2;
    l9 = std_core_write_unsigned(l7, l9, l10);
    l9 = std_core_write_string_at(l7, l9, 56u);
    l8 = ((int64_t) (int32_t) l4);
    l9 = std_core_write_int(l7, l9, l8);
    t0 = std_core_finish_buffer(l7, l9);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t0;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_check_module_tags(void* l0, void* l1) {
    size_t l2, l3, l4, l7, l8, l10;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null();
    bool l11;
    uint8_t l12, l14;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l9, &l13 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l15, &l16, &l17, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (size_t) 2;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l7 = (size_t) 0;
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
        while ((l7 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l6)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
            if ((t0 < INT64_C(0))) {
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l9 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            l10 = (size_t) 1;
            l11 = (l10 <= l2);
            while (l11) {
                l13 = vader_vm_accepted_tags(l9, l10);
                if (l13.tag == 0u) {
                    l11 = (l10 < l2);
                    t0 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t0;
                    continue;
                }
                l12 = ((uint8_t) l13.payload.i);
                l14 = vader_vm_stack_tags(l6, l7, l10);
                t1 = vader_vm_tags_within(l14, l12);
                if (!(t1)) {
                    l15 = vader_vm_display_tags(l14);
                    l16 = vader_vm_display_tags(l12);
                    l17 = vader_vm_op_text(l9);
                    l18 = concat_6(865u, l17, 979u, l15, 147u, l16);
                    t2 = vader_vm_defect(l5, l7, l18);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l11 = (l10 < l2);
                t0 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t0;
            }
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
        }
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static int32_t vader_vm_checked_neg_register_op(uint8_t l0) {
    if (l0 == INT32_C(2)) {
        return INT32_C(71);
    }
    if (l0 == INT32_C(3)) {
        return INT32_C(75);
    }
    if (!(l0 == INT32_C(4))) {
        return INT32_C(82);
    }
    return INT32_C(75);
}

static void* vader_vm_checked_neg_trap(uint8_t l0, void* l1, size_t l2) {
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    int64_t l6;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l1, &l5, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_checked_neg_message(l0);
    l4 = vader_host_std_core_byte_len(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l4));
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 56u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    l6 = ((int64_t) (int32_t) t0);
    l4 = std_core_write_int(l5, l4, l6);
    t1 = std_core_finish_buffer(l5, l4);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t1;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_checked_register_op(void* l0) {
    uint8_t l1;
    int32_t l2;
    bool l3;
    bool t0;
    if (((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_kind == INT32_C(2)) {
        l1 = ((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_op;
        if (l1 == INT32_C(0)) {
            l2 = INT32_C(68);
            return l2;
        }
        if (l1 == INT32_C(1)) {
            l2 = INT32_C(69);
        } else {
            if (!(l1 == INT32_C(2))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = INT32_C(70);
        }
        return l2;
    }
    if (((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_kind == INT32_C(3)) {
        l3 = true;
    } else {
        l3 = ((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_kind == INT32_C(4);
    }
    if (l3) {
        l1 = ((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_op;
        if (l1 == INT32_C(0)) {
            l2 = INT32_C(72);
            return l2;
        }
        if (l1 == INT32_C(1)) {
            l2 = INT32_C(73);
        } else {
            if (!(l1 == INT32_C(2))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = INT32_C(74);
        }
        return l2;
    }
    t0 = vader_bytecode_is_u64_class(((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_kind);
    if (t0) {
        l1 = ((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_op;
        if (l1 == INT32_C(0)) {
            l2 = INT32_C(76);
            return l2;
        }
        if (l1 == INT32_C(1)) {
            l2 = INT32_C(77);
        } else {
            if (!(l1 == INT32_C(2))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = INT32_C(78);
        }
        return l2;
    }
    l1 = ((vader_struct_vader_bytecode_CheckedArith_t*) l0)->f_op;
    if (l1 == INT32_C(0)) {
        l2 = INT32_C(79);
        return l2;
    }
    if (l1 == INT32_C(1)) {
        l2 = INT32_C(80);
    } else {
        if (!(l1 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = INT32_C(81);
    }
    return l2;
}

static vader_box_t vader_vm_checked_registers(uint8_t l0, uint8_t l1, void* l2, size_t l3, int64_t l4) {
    int32_t l5;
    int64_t l6, l7;
    vader_box_t t0;
    l5 = vader_vm_operand_b(l4);
    l6 = vader_vm_bits_of(l2, l3, l5);
    l5 = vader_vm_operand_c(l4);
    l7 = vader_vm_bits_of(l2, l3, l5);
    t0 = vader_bytecode_checked_arith(l0, l1, l6, l7);
    return t0;
}

static void* vader_vm_checked_trap(uint8_t l0, uint8_t l1, void* l2, size_t l3) {
    vader_string_t l4 = 0;
    size_t l5;
    void* l6 = NULL;
    int64_t l7;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l2, &l6, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_bytecode_checked_overflow_message(l0, l1);
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l5));
    l5 = (size_t) 0;
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 56u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core_write_int(l6, l5, l7);
    t1 = std_core_finish_buffer(l6, l5);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t1;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_vm_clamp_nonneg(int32_t l0) {
    if ((l0 < INT32_C(0))) {
        return (size_t) 0;
    }
    return (size_t) (int64_t) ((int64_t) (int32_t) l0);
}

static void vader_vm_collect_constants(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 678u) {
            t0 = l6.payload.obj;
            vader_vm_add_constant(((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value, l1, l2);
        } else if ((l6.tag == 571u || l6.tag == 586u || l6.tag == 601u || l6.tag == 620u || l6.tag == 640u || l6.tag == 671u)) {
            vader_vm_add_constant(l6, l1, l2);
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_vm_constant_index(void* l0, void* l1, void* l2) {
    size_t l3, l4;
    int64_t l5, l6;
    uint8_t l7, l8;
    vader_box_t t0;
    int64_t t1;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        l6 = ((vader_struct_vader_vm_Scalar_t*) l2)->f_bits;
        if (l5 == l6) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 249u);
            l7 = ((uint8_t) t0.payload.i);
            l8 = ((vader_struct_vader_vm_Scalar_t*) l2)->f_tag;
            if (l7 == l8) {
                return ((int64_t) (size_t) l3);
            }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return INT64_C(-1);
}

static bool vader_vm_convert_int_fast(void* l0, uint8_t l1, vader_string_t l2) {
    size_t l3;
    uint8_t l4;
    int64_t l5, l7;
    bool l6;
    void* l8;
    size_t t0;
    int64_t t1;
    vader_box_t t2;
    uint8_t t3;
    if (l1 != INT32_C(0)) {
        if (l1 != INT32_C(1)) {
            return false;
        }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 249u);
    l4 = ((uint8_t) t2.payload.i);
    l5 = INT64_C(0);
    if (l4 == INT32_C(0)) {
        if (l1 == INT32_C(1)) {
            t0 = vader_host_std_core_byte_len(l2);
            l6 = (t0 > INT64_C(0));
        } else {
            l6 = false;
        }
        if (l6) {
            t3 = vader_host_std_core_byte_at(l2, (size_t) 0);
            l6 = t3 == INT32_C(117);
        } else {
            l6 = false;
        }
        if (l6) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t1));
        } else {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
            l5 = ((int64_t) (int32_t) ((int32_t) (int64_t) t1));
        }
    } else if (l4 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
        l5 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    } else if (l4 == INT32_C(4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l3];
        l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t1));
    } else {
        if (!(l4 == INT32_C(3))) {
            return false;
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l3];
        if (t1 != INT64_C(0)) {
            l7 = INT64_C(1);
        } else {
            l7 = INT64_C(0);
        }
        l5 = l7;
    }
    if (l1 == INT32_C(0)) {
        l8 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        l7 = ((int64_t) (int32_t) ((int32_t) (int64_t) l5));
        vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
        ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l3] = (int64_t) l7;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(0);
        return true;
    }
    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l3)
    ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l3] = (int64_t) l5;
    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l3)
    ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(1);
    return true;
}

static vader_box_t vader_vm_convert_value(vader_box_t l0, uint8_t l1, vader_string_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    bool t0;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    void* t4 = NULL;
    double t5;
    uint32_t t6;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &t2 };
    void** gc_raw_roots[1] = { &t4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 246u) {
        t0 = std_string_starts_with(l2, 2409u);
        if (t0) {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i64(247u, ((int64_t) (uint32_t) t1));
        } else {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i32(246u, t1);
        }
    } else {
        l4 = l0;
    }
    if (l1 == INT32_C(0)) {
        if (l4.tag == 246u) {
            t1 = ((int32_t) l4.payload.i);
            t2 = vader_box_i32(246u, t1);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm_read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1126u)) {
            t3 = ((int64_t) l5.payload.i);
            t2 = vader_box_i32(246u, ((int32_t) (int64_t) t3));
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        if (l4.tag == 247u) {
            t3 = ((int64_t) l4.payload.i);
            t2 = vader_box_i64(247u, t3);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm_read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1126u)) {
            t3 = ((int64_t) l5.payload.i);
            t2 = vader_box_i64(247u, t3);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        if ((l4.tag == 239u || l4.tag == 240u)) {
            t5 = ((double) l4.payload.f);
            t2 = vader_box_f64(240u, t5);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm_read_numeric_as_f64(l4, l3);
        if (!(l5.tag == 1126u)) {
            t5 = ((double) l5.payload.f);
            t2 = vader_box_f64(240u, t5);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 242u) {
        t6 = ((uint32_t) l4.payload.i);
        t2 = vader_box_i32(242u, (int32_t) t6);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm_read_numeric_as_i64(l4, l3);
    if (!(l4.tag == 1126u)) {
        t3 = ((int64_t) l4.payload.i);
        t2 = vader_box_i32(242u, (int32_t) ((uint32_t) (int32_t) ((int32_t) (int64_t) t3)));
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_debug_controller(void* l0) {
    vader_box_t l1;
    void* t0;
    l1 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_debug;
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(((vader_struct_vader_vm_DebugSession_t*) t0)->f_controller);
}

static int64_t vader_vm_debug_std_descriptor(int64_t l0) {
    if (l0 == INT64_C(4294967284)) {
        return INT64_C(2);
    }
    return INT64_C(1);
}

static vader_box_t vader_vm_debug_write(void* l0, void* l1, size_t l2, int32_t l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    size_t l6, l10;
    bool l9;
    void* l11 = NULL;
    int64_t l12;
    int32_t l13;
    vader_string_t l14 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2, t3;
    vader_string_t t4 = 0;
    uint8_t t5;
    vader_box_t* gc_roots[4] = { &l5, &l7, &l8, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l11, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l14, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l5 = vader_vm_read_i64(t0, l3, 2319u);
    if (l5.tag == 1126u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_chk_add(usize, l2, INT64_C(1));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
    l7 = vader_vm_read_array(t0, l3, 2316u);
    if (l7.tag == 1126u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_chk_add(usize, l2, INT64_C(2));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
    l8 = vader_vm_read_i64(t0, l3, 2318u);
    if (l8.tag == 1126u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int64_t) l8.payload.i);
    if ((t2 < INT32_C(0))) {
        l9 = true;
    } else {
        t2 = ((int64_t) l8.payload.i);
        t3 = t2;
        l6 = (size_t) (int64_t) t3;
        t1 = l7.payload.obj;
        l10 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
        l9 = (l6 > l10);
    }
    if (l9) {
        l11 = std_core_new_byte_buffer((size_t) 83);
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l11, l6, 2315u);
        l12 = ((int64_t) (int32_t) l3);
        l6 = std_core_write_int(l11, l6, l12);
        l6 = std_core_write_string_at(l11, l6, 364u);
        l12 = ((int64_t) l8.payload.i);
        l6 = std_core_write_int(l11, l6, l12);
        l6 = std_core_write_string_at(l11, l6, 67u);
        t4 = std_core_finish_buffer(l11, l6);
        vader_struct_vader_vm_Trap_t* _a3_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a3_obj, 1126u);
        _a3_obj->f_message = t4;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l7.payload.obj;
    t2 = ((int64_t) l8.payload.i);
    t3 = t2;
    l6 = (size_t) (int64_t) t3;
    l7 = vader_vm_array_bytes(l11, l6, l3, 2317u);
    if (l7.tag == 1126u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = ((vader_struct_vader_vm_DebugController_t*) l4)->f_output_sink;
    t2 = ((int64_t) l5.payload.i);
    l13 = vader_chk_sub(i32, ((int32_t) (int64_t) t2), INT32_C(1));
    t1 = l7.payload.obj;
    l14 = vader_host_std_core_bytes_to_string(t1);
    vader_fn_t* _a4_fnobj = (vader_fn_t*) l11;
    ((vader_fn_erased_sig_2_t) _a4_fnobj->code)(_a4_fnobj->env, vader_box_i32(246u, l13), vader_box_string(243u, l14));
    t5 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    if (!(t5 == INT32_C(12))) {
        t2 = ((int64_t) l8.payload.i);
        t0 = vader_box_i64(247u, t2);
        vader_struct_vader_vm_HostOk_t* _a5_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a5_obj, 1107u);
        _a5_obj->f_value = t0;
        t1 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_HostOk_t* _a6_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
    vader_obj_header_init(_a6_obj, 1107u);
    _a6_obj->f_value = vader_box_bool(241u, true);
    t1 = (void*) _a6_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_defect(void* l0, size_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l4 = ((int32_t) (size_t) l1);
    vader_struct_vader_vm_VerifyError_t* _a0_obj = (vader_struct_vader_vm_VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VerifyError_t));
    vader_obj_header_init(_a0_obj, 1129u);
    _a0_obj->f_function = l3;
    _a0_obj->f_pc = l4;
    _a0_obj->f_message = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    int32_t l6;
    void* l7 = NULL;
    size_t l8;
    int64_t l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    int64_t t3;
    size_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1103u)) {
        l4 = l1;
        l5 = concat_2(l3, 66u);
        t0 = vader_vm_read_fn(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_function_index;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    l4 = vader_vm_validate_fn_index(l6, l7, l2, l3);
    if (l4.tag == 1126u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    t1 = l1.payload.obj;
    t2 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_function_index;
    t3 = ((int64_t) (int32_t) t2);
    l8 = (size_t) (int64_t) t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_signature)->f_params)->length;
    if (!(t4 != INT64_C(1))) {
        t1 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_name;
    l8 = vader_host_std_core_byte_len(l5);
    l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(73) + l8));
    l8 = (size_t) 0;
    l8 = std_core_write_string_at(l7, l8, 1528u);
    l8 = std_core_write_string_at(l7, l8, l5);
    l8 = std_core_write_string_at(l7, l8, 221u);
    l9 = ((int64_t) (int32_t) l2);
    l8 = std_core_write_int(l7, l8, l9);
    t5 = std_core_finish_buffer(l7, l8);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t5;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_describe_obj(void* l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    uint64_t l4;
    int32_t t0;
    size_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 106);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 398u);
    t0 = ((vader_struct_vader_vm_ObjVal_t*) l0)->f_handle;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 139u);
    t0 = ((vader_struct_vader_vm_ObjVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 60u);
    t1 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) l0)->f_bytes)->length;
    t2 = ((int64_t) (size_t) t1);
    l4 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l1, l2, l4);
    l2 = std_core_write_string_at(l1, l2, 130u);
    t1 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) l0)->f_slots)->length;
    t2 = ((int64_t) (size_t) t1);
    l4 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l1, l2, l4);
    l2 = std_core_write_string_at(l1, l2, 408u);
    t3 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_describe_value_tag(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 246u) {
        l1 = 1760u;
        return l1;
    }
    if (l0.tag == 247u) {
        l1 = 1782u;
    } else if ((l0.tag == 239u || l0.tag == 240u)) {
        l1 = 1641u;
    } else if (l0.tag == 243u) {
        l1 = 2273u;
    } else if (l0.tag == 1123u) {
        l1 = 2293u;
    } else if (l0.tag == 1098u) {
        l1 = 1285u;
    } else if (l0.tag == 1103u) {
        l1 = 1695u;
    } else if (l0.tag == 1110u) {
        l1 = 2062u;
    } else if (l0.tag == 241u) {
        l1 = 1345u;
    } else if (l0.tag == 242u) {
        l1 = 1454u;
    } else if (l0.tag == 1102u) {
        l1 = 1583u;
    } else if (l0.tag == 1127u) {
        l1 = 2381u;
    } else {
        if (!(l0.tag == 1111u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2065u;
    }
    return l1;
}

static void vader_vm_detach_array_view(void* l0) {
    void* l1 = NULL;
    size_t l2, l3, l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    size_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw.tag == 0u) {
        t0 = vader_vm_is_array_view(l0);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    while ((l2 < l3)) {
        t1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        t2 = vader_chk_add(usize, t1, l2);
        l4 = (size_t) (int64_t) t2;
        l5 = vader_vm_element_at(l0, l4);
        vader_array_push((vader_array_t*) l1, l5);
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) l0);
    ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset = (size_t) 0;
    ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_dispatch_extern(void* l0, void* l1, size_t l2, int32_t l3, void* l4, vader_box_t l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l32 = NULL;
    void* l38 = NULL;
    void* l46 = NULL;
    void* l47 = NULL;
    void* l53 = NULL;
    void* l54 = NULL;
    void* l55 = NULL;
    void* l66 = NULL;
    void* l77 = NULL;
    void* l86 = NULL;
    void* l91 = NULL;
    void* l92 = NULL;
    void* l95 = NULL;
    void* l98 = NULL;
    void* l109 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l12 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l48 = 0;
    vader_string_t l57 = 0;
    vader_string_t l61 = 0;
    vader_string_t l62 = 0;
    vader_string_t l75 = 0;
    vader_string_t l103 = 0;
    vader_string_t l104 = 0;
    vader_string_t l116 = 0;
    size_t l8, l13, l14, l20, l21, l23, l27, l29, l35, l36, l37, l39, l42, l43, l44, l45, l59, l63, l64, l65, l67, l76, l78, l81, l87, l88, l89, l90, l93, l96, l97, l99;
    int64_t l10, l30, l40, l51, l52, l68, l70, l71, l72, l79, l83, l84, l101, l107, l108, l111, l113, l119;
    vader_box_t l11 = vader_box_null(), l26 = vader_box_null(), l49 = vader_box_null(), l56 = vader_box_null(), l58 = vader_box_null(), l74 = vader_box_null(), l85 = vader_box_null(), l100 = vader_box_null(), l102 = vader_box_null(), l105 = vader_box_null(), l115 = vader_box_null(), l117 = vader_box_null();
    uint64_t l24, l31, l41, l80;
    uint8_t l50, l69, l82, l94, l106, l110, l112, l114, l118;
    bool l60;
    int32_t l73;
    size_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    int64_t t5, t6;
    int32_t t7, t10;
    uint8_t t8;
    double t9;
    vader_box_t* gc_roots[14] = {
        &l5, &l11, &l26, &l49, &l56, &l58, &l74, &l85, &l100, &l102, &l105, &l115, &l117, &t4,
    };
    void** gc_raw_roots[29] = {
        &l0, &l1, &l4, &l6, &l9, &l15, &l16, &l17, &l18, &l19, &l22, &l25, &l28, &l32, &l38, &l46,
        &l47, &l53, &l54, &l55, &l66, &l77, &l86, &l91, &l92, &l95, &l98, &l109, &t2,
    };
    vader_string_t* gc_atom_roots[13] = {
        &l7, &l12, &l33, &l34, &l48, &l57, &l61, &l62, &l75, &l103, &l104, &l116, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 14u, 29u, gc_roots, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params;
    t0 = ((vader_array_t*) l6)->length;
    if ((t0 > INT64_C(8))) {
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l8 = vader_host_std_core_byte_len(l7);
        l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(59) + l8));
        l8 = (size_t) 0;
        l8 = std_core_write_string_at(l9, l8, 1636u);
        l8 = std_core_write_string_at(l9, l8, l7);
        l8 = std_core_write_string_at(l9, l8, 888u);
        l10 = ((int64_t) (int32_t) l3);
        l8 = std_core_write_int(l9, l8, l10);
        l8 = std_core_write_string_at(l9, l8, 377u);
        t1 = std_core_finish_buffer(l9, l8);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 0u)) {
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        t3 = vader_vm_is_std_handle_symbol(t1);
        if (t3) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t4 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2];
            l11 = vader_vm_read_i64(t4, l3, 504u);
            if (!(l11.tag == 1126u)) {
                t5 = ((int64_t) l11.payload.i);
                t6 = vader_vm_debug_std_descriptor(t5);
                t4 = vader_box_i64(247u, t6);
                vader_struct_vader_vm_HostOk_t* _a2_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a2_obj, 1107u);
                _a2_obj->f_value = t4;
                t2 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(l5.tag == 0u)) {
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        t3 = vader_vm_is_write_symbol(t1);
        if (t3) {
            l9 = l5.payload.obj;
            t4 = vader_vm_debug_write(l0, l1, l2, l3, l9);
            { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_c_library;
    l8 = vader_host_vader_vm_ffi_open(t1);
    if (l8 == INT64_C(0)) {
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_c_library;
        if (t1 == 0u) {
            l7 = 2343u;
        } else {
            l12 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_c_library;
            l7 = concat_3(865u, l12, 865u);
        }
        l12 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l13 = vader_host_std_core_byte_len(l12);
        l14 = vader_host_std_core_byte_len(l7);
        t5 = (l13 + l14);
        l13 = (size_t) (int64_t) t5;
        l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l13));
        l13 = (size_t) 0;
        l13 = std_core_write_string_at(l9, l13, 1636u);
        l13 = std_core_write_string_at(l9, l13, l12);
        l13 = std_core_write_string_at(l9, l13, 888u);
        l10 = ((int64_t) (int32_t) l3);
        l13 = std_core_write_int(l9, l13, l10);
        l13 = std_core_write_string_at(l9, l13, 362u);
        l13 = std_core_write_string_at(l9, l13, l7);
        t1 = std_core_finish_buffer(l9, l13);
        vader_struct_vader_vm_Trap_t* _a3_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a3_obj, 1126u);
        _a3_obj->f_message = t1;
        t2 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    l8 = vader_host_vader_vm_ffi_symbol(l8, l7);
    if (l8 == INT64_C(0)) {
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l13 = vader_host_std_core_byte_len(l7);
        l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(54) + l13));
        l13 = (size_t) 0;
        l13 = std_core_write_string_at(l9, l13, 1636u);
        l13 = std_core_write_string_at(l9, l13, l7);
        l13 = std_core_write_string_at(l9, l13, 888u);
        l10 = ((int64_t) (int32_t) l3);
        l13 = std_core_write_int(l9, l13, l10);
        l13 = std_core_write_string_at(l9, l13, 378u);
        t1 = std_core_finish_buffer(l9, l13);
        vader_struct_vader_vm_Trap_t* _a4_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a4_obj, 1126u);
        _a4_obj->f_message = t1;
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) (INT32_C(0) & INT32_C(255));
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 8u, 247u);
    l15 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 8u, 247u);
    l16 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(16u, 0u, 1u, 249u);
    l17 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(169u, 0u, 13u, 1108u);
    l18 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(170u, 0u, 13u, 1109u);
    l19 = (void*) _a10_arr;
    l13 = (size_t) 0;
    l14 = ((vader_array_t*) l6)->length;
    while ((l13 < l14)) {
        t5 = vader_chk_add(usize, l2, l13);
        l20 = (size_t) (int64_t) t5;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l20)
        l11 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l20];
        if (l11.tag == 1103u) {
            l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l21 = vader_host_std_core_byte_len(l7);
            l22 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(138) + l21));
            l23 = (size_t) 0;
            l23 = std_core_write_string_at(l22, l23, 1636u);
            l23 = std_core_write_string_at(l22, l23, l7);
            l23 = std_core_write_string_at(l22, l23, 888u);
            l10 = ((int64_t) (int32_t) l3);
            l23 = std_core_write_int(l22, l23, l10);
            l23 = std_core_write_string_at(l22, l23, 360u);
            t5 = ((int64_t) (size_t) l13);
            l24 = (uint64_t) (int64_t) t5;
            l23 = std_core_write_unsigned(l22, l23, l24);
            l23 = std_core_write_string_at(l22, l23, 87u);
            t1 = std_core_finish_buffer(l22, l23);
            vader_struct_vader_vm_Trap_t* _a12_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a12_obj, 1126u);
            _a12_obj->f_message = t1;
            t2 = (void*) _a12_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11.tag == 1123u) {
            l25 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_param_types;
            l26 = vader_vm_mirrored_struct_fields(l4, l25, l13);
            if (l26.tag == 0u) {
                l12 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                l27 = vader_host_std_core_byte_len(l12);
                l28 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(112) + l27));
                l29 = (size_t) 0;
                l29 = std_core_write_string_at(l28, l29, 1636u);
                l29 = std_core_write_string_at(l28, l29, l12);
                l29 = std_core_write_string_at(l28, l29, 888u);
                l30 = ((int64_t) (int32_t) l3);
                l29 = std_core_write_int(l28, l29, l30);
                l29 = std_core_write_string_at(l28, l29, 360u);
                t5 = ((int64_t) (size_t) l13);
                l31 = (uint64_t) (int64_t) t5;
                l29 = std_core_write_unsigned(l28, l29, l31);
                l29 = std_core_write_string_at(l28, l29, 88u);
                t1 = std_core_finish_buffer(l28, l29);
                vader_struct_vader_vm_Trap_t* _a13_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a13_obj, 1126u);
                _a13_obj->f_message = t1;
                t2 = (void*) _a13_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l26.payload.obj;
            l32 = vader_bytecode_c_struct_layout(t2, l4);
            if (!(((vader_struct_vader_bytecode_CLayout_t*) l32)->f_unknown_field.tag == 0u)) {
                l33 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                l34 = ((vader_struct_vader_bytecode_CLayout_t*) l32)->f_unknown_field.payload.s;
                l35 = vader_host_std_core_byte_len(l33);
                l36 = vader_host_std_core_byte_len(l34);
                t5 = (l35 + l36);
                l37 = (size_t) (int64_t) t5;
                l38 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(142) + l37));
                l39 = (size_t) 0;
                l39 = std_core_write_string_at(l38, l39, 1636u);
                l39 = std_core_write_string_at(l38, l39, l33);
                l39 = std_core_write_string_at(l38, l39, 888u);
                l40 = ((int64_t) (int32_t) l3);
                l39 = std_core_write_int(l38, l39, l40);
                l39 = std_core_write_string_at(l38, l39, 360u);
                t5 = ((int64_t) (size_t) l13);
                l41 = (uint64_t) (int64_t) t5;
                l39 = std_core_write_unsigned(l38, l39, l41);
                l39 = std_core_write_string_at(l38, l39, 101u);
                l39 = std_core_write_string_at(l38, l39, l34);
                l39 = std_core_write_string_at(l38, l39, 962u);
                t1 = std_core_finish_buffer(l38, l39);
                vader_struct_vader_vm_Trap_t* _a14_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a14_obj, 1126u);
                _a14_obj->f_message = t1;
                t2 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l42 = ((vader_array_t*) l17)->length;
            t5 = INT64_C(4096);
            l43 = (size_t) (int64_t) t5;
            t5 = ((vader_struct_vader_bytecode_CLayout_t*) l32)->f_size;
            if ((t5 > l43)) {
                t5 = ((vader_struct_vader_bytecode_CLayout_t*) l32)->f_size;
                t6 = t5;
                l44 = (size_t) (int64_t) t6;
            } else {
                l44 = l43;
            }
            l45 = (size_t) 0;
            while ((l45 < l44)) {
                vader_array_push_u8((vader_array_t*) l17, INT32_C(0));
                t5 = (l45 + INT64_C(1));
                l45 = (size_t) (int64_t) t5;
            }
            l46 = l11.payload.obj;
            l47 = l26.payload.obj;
            l48 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l49 = vader_vm_serialise_mirror(l17, l42, l46, l47, l4, l3, l48, INT32_C(0));
            if (l49.tag == 1126u) {
                t2 = l49.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = (INT32_C(3) & INT32_C(255));
            l50 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l50);
            t0 = ((vader_array_t*) l15)->length;
            l51 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l16, l51);
            l52 = ((int64_t) (size_t) l42);
            vader_array_push_i64((vader_array_t*) l15, l52);
            t3 = vader_vm_param_mirror_is_mutable(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l13);
            if (t3) {
                l53 = l11.payload.obj;
                l54 = l26.payload.obj;
                vader_struct_vader_vm_LentStruct_t* _a15_obj = (vader_struct_vader_vm_LentStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_LentStruct_t));
                vader_obj_header_init(_a15_obj, 1109u);
                _a15_obj->f_target = l53;
                _a15_obj->f_at = l42;
                _a15_obj->f_fields = l54;
                l55 = (void*) _a15_obj;
                vader_array_push((vader_array_t*) l19, vader_ref_box(l55));
            }
            t5 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t5;
            continue;
        }
        t3 = vader_vm_extern_by_address(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l13);
        if (t3) {
            l56 = l11;
            l57 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l58 = vader_vm_extern_word(l56, l3, l57, l13);
            if (l58.tag == 1126u) {
                t2 = l58.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l13)
            t4 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l13, 249u);
            t7 = vader_bytecode_size_of_val_type(((uint8_t) t4.payload.i));
            t5 = ((int64_t) (int32_t) t7);
            l59 = (size_t) (int64_t) t5;
            if (l59 == INT64_C(0)) {
                l60 = true;
            } else {
                l60 = (l59 > INT64_C(8));
            }
            if (l60) {
                l61 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
                t4 = vader_array_read_u8(_a17_slotarr, _a17_slotarr->offset + (size_t) l13, 249u);
                l62 = vader_bytecode_val_type_name(((uint8_t) t4.payload.i));
                l63 = vader_host_std_core_byte_len(l61);
                l64 = vader_host_std_core_byte_len(l62);
                t5 = (l63 + l64);
                l65 = (size_t) (int64_t) t5;
                l66 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(81) + l65));
                l67 = (size_t) 0;
                l67 = std_core_write_string_at(l66, l67, 1636u);
                l67 = std_core_write_string_at(l66, l67, l61);
                l67 = std_core_write_string_at(l66, l67, 888u);
                l68 = ((int64_t) (int32_t) l3);
                l67 = std_core_write_int(l66, l67, l68);
                l67 = std_core_write_string_at(l66, l67, 358u);
                l67 = std_core_write_string_at(l66, l67, l62);
                l67 = std_core_write_string_at(l66, l67, 118u);
                t1 = std_core_finish_buffer(l66, l67);
                vader_struct_vader_vm_Trap_t* _a18_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a18_obj, 1126u);
                _a18_obj->f_message = t1;
                t2 = (void*) _a18_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = (INT32_C(3) & INT32_C(255));
            l69 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l69);
            t0 = ((vader_array_t*) l15)->length;
            l70 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l16, l70);
            t0 = ((vader_array_t*) l17)->length;
            l71 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l15, l71);
            l72 = ((int64_t) l58.payload.i);
            vader_vm_push_little_endian(l17, l72, l59);
        } else if (l11.tag == 1098u) {
            t2 = l11.payload.obj;
            l73 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_type_id;
            l74 = vader_vm_lent_element_val_type(l4, l73);
            if (l74.tag == 0u) {
                l75 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                l76 = vader_host_std_core_byte_len(l75);
                l77 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(153) + l76));
                l78 = (size_t) 0;
                l78 = std_core_write_string_at(l77, l78, 1636u);
                l78 = std_core_write_string_at(l77, l78, l75);
                l78 = std_core_write_string_at(l77, l78, 888u);
                l79 = ((int64_t) (int32_t) l3);
                l78 = std_core_write_int(l77, l78, l79);
                l78 = std_core_write_string_at(l77, l78, 360u);
                t5 = ((int64_t) (size_t) l13);
                l80 = (uint64_t) (int64_t) t5;
                l78 = std_core_write_unsigned(l77, l78, l80);
                l78 = std_core_write_string_at(l77, l78, 90u);
                t1 = std_core_finish_buffer(l77, l78);
                vader_struct_vader_vm_Trap_t* _a19_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a19_obj, 1126u);
                _a19_obj->f_message = t1;
                t2 = (void*) _a19_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t8 = ((uint8_t) l74.payload.i);
            t7 = vader_bytecode_size_of_val_type(t8);
            t5 = ((int64_t) (int32_t) t7);
            l81 = (size_t) (int64_t) t5;
            t7 = (INT32_C(3) & INT32_C(255));
            l82 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l82);
            t0 = ((vader_array_t*) l15)->length;
            l83 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l16, l83);
            t0 = ((vader_array_t*) l17)->length;
            l84 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l15, l84);
            t2 = l11.payload.obj;
            l85 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_raw;
            if (l85.tag == 0u) {
                l92 = l11.payload.obj;
                l93 = ((vader_array_t*) l17)->length;
                l94 = ((uint8_t) l74.payload.i);
                vader_struct_vader_vm_LentArray_t* _a20_obj = (vader_struct_vader_vm_LentArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_LentArray_t));
                vader_obj_header_init(_a20_obj, 1108u);
                _a20_obj->f_target = l92;
                _a20_obj->f_at = l93;
                _a20_obj->f_element = l94;
                l95 = (void*) _a20_obj;
                vader_array_push((vader_array_t*) l18, vader_ref_box(l95));
                l96 = (size_t) 0;
                t2 = l11.payload.obj;
                l97 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
                while ((l96 < l97)) {
                    t2 = l11.payload.obj;
                    l98 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
                    t2 = l11.payload.obj;
                    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                    t5 = vader_chk_add(usize, t0, l96);
                    l99 = (size_t) (int64_t) t5;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l98);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l99)
                    l100 = vader_array_box_slots(_a21_slotarr->buf)[_a21_slotarr->offset + (size_t) l99];
                    if (l100.tag == 247u) {
                        l101 = ((int64_t) l100.payload.i);
                    } else if (l100.tag == 246u) {
                        t7 = ((int32_t) l100.payload.i);
                        l101 = ((int64_t) (int32_t) t7);
                    } else {
                        l102 = l100;
                        l103 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                        l104 = concat_3(1636u, l103, 903u);
                        l105 = vader_vm_read_i64(l102, l3, l104);
                        if (l105.tag == 1126u) {
                            t2 = l105.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l101 = ((int64_t) l105.payload.i);
                    }
                    vader_vm_push_little_endian(l17, l101, l81);
                    t5 = (l96 + INT64_C(1));
                    l96 = (size_t) (int64_t) t5;
                }
            } else {
                l86 = l85.payload.obj;
                t2 = l11.payload.obj;
                l87 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                t2 = l11.payload.obj;
                l88 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                t2 = l11.payload.obj;
                l89 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
                t5 = vader_chk_add(usize, l88, l89);
                l90 = (size_t) (int64_t) t5;
                vader_array_t* _a22_arr = vader_array_slice((vader_array_t*) l86, (size_t) l87, (size_t) l90);
                l91 = (void*) _a22_arr;
                vader_array_push_all((vader_array_t*) l17, (vader_array_t*) l91);
            }
        } else if (l11.tag == 243u) {
            t7 = (INT32_C(3) & INT32_C(255));
            l106 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l106);
            t0 = ((vader_array_t*) l15)->length;
            l107 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l16, l107);
            t0 = ((vader_array_t*) l17)->length;
            l108 = ((int64_t) (size_t) t0);
            vader_array_push_i64((vader_array_t*) l15, l108);
            t1 = l11.payload.s;
            l109 = vader_host_std_core_bytes(t1);
            vader_array_push_all((vader_array_t*) l17, (vader_array_t*) l109);
            vader_array_push_u8((vader_array_t*) l17, INT32_C(0));
        } else if ((l11.tag == 239u || l11.tag == 240u)) {
            t7 = (INT32_C(2) & INT32_C(255));
            l110 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l110);
            t9 = ((double) l11.payload.f);
            l111 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t9 }).__vu);
            vader_array_push_i64((vader_array_t*) l15, l111);
        } else if (l11.tag == 241u) {
            t7 = (INT32_C(1) & INT32_C(255));
            l112 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l112);
            t3 = l11.payload.b;
            if (t3) {
                l113 = INT64_C(1);
            } else {
                l113 = INT64_C(0);
            }
            vader_array_push_i64((vader_array_t*) l15, l113);
        } else if (l11.tag == 1110u) {
            t7 = (INT32_C(1) & INT32_C(255));
            l114 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l114);
            vader_array_push_i64((vader_array_t*) l15, INT64_C(0));
        } else {
            l115 = l11;
            l116 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l117 = vader_vm_extern_word(l115, l3, l116, l13);
            if (l117.tag == 1126u) {
                t2 = l117.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = (INT32_C(1) & INT32_C(255));
            l118 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l118);
            l119 = ((int64_t) l117.payload.i);
            vader_array_push_i64((vader_array_t*) l15, l119);
        }
        t5 = (l13 + INT64_C(1));
        l13 = (size_t) (int64_t) t5;
    }
    l50 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    if (l50 == INT32_C(10)) {
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l13 = vader_host_std_core_byte_len(l7);
        l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(67) + l13));
        l13 = (size_t) 0;
        l13 = std_core_write_string_at(l6, l13, 1636u);
        l13 = std_core_write_string_at(l6, l13, l7);
        l13 = std_core_write_string_at(l6, l13, 888u);
        l10 = ((int64_t) (int32_t) l3);
        l13 = std_core_write_int(l6, l13, l10);
        l13 = std_core_write_string_at(l6, l13, 359u);
        t1 = std_core_finish_buffer(l6, l13);
        vader_struct_vader_vm_Trap_t* _a23_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a23_obj, 1126u);
        _a23_obj->f_message = t1;
        t2 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l73 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    t3 = vader_vm_ffi_result_is_opt(l4, l73, (uint8_t) 14);
    if (t3) {
        t7 = (INT32_C(5) & INT32_C(255));
        l69 = (uint8_t) (int32_t) t7;
    } else {
        t7 = vader_vm_ffi_result_class(l50);
        t10 = (t7 & INT32_C(255));
        l69 = (uint8_t) (int32_t) t10;
    }
    vader_array_t* _a24_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, INT32_C(0))
    ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) (int32_t) (uint8_t) l69;
    t0 = ((vader_array_t*) l15)->length;
    t5 = vader_chk_mul(usize, t0, INT64_C(8));
    l13 = (size_t) (int64_t) t5;
    l6 = l16;
    l14 = ((vader_array_t*) l6)->length;
    l20 = (size_t) 0;
    while ((l20 < l14)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        l10 = ((int64_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l20];
        t5 = l10;
        l21 = (size_t) (int64_t) t5;
        t5 = l10;
        l23 = (size_t) (int64_t) t5;
        vader_array_t* _a26_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l23)
        l30 = ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l23];
        l40 = ((int64_t) (size_t) l13);
        l51 = vader_chk_add(i64, l30, l40);
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l21)
        ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l21] = (int64_t) l51;
        t5 = (l20 + INT64_C(1));
        l20 = (size_t) (int64_t) t5;
    }
    vader_array_t* _a27_arr = vader_array_new(16u, 0u, 1u, 249u);
    l6 = (void*) _a27_arr;
    l14 = ((vader_array_t*) l15)->length;
    l20 = (size_t) 0;
    while ((l20 < l14)) {
        vader_array_t* _a28_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l20)
        l10 = ((int64_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l20];
        vader_vm_push_little_endian(l6, l10, (size_t) 8);
        t5 = (l20 + INT64_C(1));
        l20 = (size_t) (int64_t) t5;
    }
    vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l17);
    t0 = ((vader_array_t*) l6)->length;
    if (t0 == INT64_C(0)) {
        t8 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
        if (t8 != INT32_C(16)) {
            vader_vm_push_little_endian(l6, INT64_C(0), (size_t) 8);
        }
    }
    t7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_c_variadic_fixed;
    l10 = ((int64_t) (int32_t) t7);
    l7 = vader_host_vader_vm_ffi_call(l8, l9, l6, l10);
    l15 = l18;
    l8 = ((vader_array_t*) l15)->length;
    l14 = (size_t) 0;
    while ((l14 < l8)) {
        vader_array_t* _a29_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        l16 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l14);
        t7 = vader_bytecode_size_of_val_type(((vader_struct_vader_vm_LentArray_t*) l16)->f_element);
        t5 = ((int64_t) (int32_t) t7);
        l20 = (size_t) (int64_t) t5;
        t3 = vader_bytecode_is_unsigned_val(((vader_struct_vader_vm_LentArray_t*) l16)->f_element);
        l60 = !(t3);
        l21 = (size_t) 0;
        l23 = ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l16)->f_target)->f_length;
        while ((l21 < l23)) {
            t0 = ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l16)->f_target)->f_offset;
            t5 = vader_chk_add(usize, t0, l21);
            l27 = (size_t) (int64_t) t5;
            l29 = ((vader_struct_vader_vm_LentArray_t*) l16)->f_at;
            t5 = vader_chk_add(usize, l13, l29);
            l35 = (size_t) (int64_t) t5;
            t5 = vader_chk_mul(usize, l21, l20);
            l36 = (size_t) (int64_t) t5;
            t5 = vader_chk_add(usize, l35, l36);
            l37 = (size_t) (int64_t) t5;
            l10 = vader_vm_read_little_endian(l6, l37, l20, l60);
            l17 = ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l16)->f_target)->f_elements;
            vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l16)->f_target)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l27)
            t4 = vader_array_box_slots(_a30_slotarr->buf)[_a30_slotarr->offset + (size_t) l27];
            l11 = vader_vm_retyped_int(t4, l10);
            vader_array_t* _a31_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l27)
            vader_array_box_slots(_a31_slotarr->buf)[_a31_slotarr->offset + (size_t) l27] = l11;
            VADER_WRITE_BARRIER(_a31_slotarr->buf);
            t5 = (l21 + INT64_C(1));
            l21 = (size_t) (int64_t) t5;
        }
        t5 = (l14 + INT64_C(1));
        l14 = (size_t) (int64_t) t5;
    }
    l15 = l19;
    l8 = ((vader_array_t*) l15)->length;
    l14 = (size_t) 0;
    while ((l14 < l8)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l14)
        l16 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l14);
        l20 = ((vader_struct_vader_vm_LentStruct_t*) l16)->f_at;
        t5 = vader_chk_add(usize, l13, l20);
        l21 = (size_t) (int64_t) t5;
        l17 = ((vader_struct_vader_vm_LentStruct_t*) l16)->f_target;
        l18 = ((vader_struct_vader_vm_LentStruct_t*) l16)->f_fields;
        vader_vm_read_back_mirror(l6, l21, l17, l18, l4, INT32_C(0));
        t5 = (l14 + INT64_C(1));
        l14 = (size_t) (int64_t) t5;
    }
    if (l50 == INT32_C(16)) {
        t4 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a33_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a33_obj, 1107u);
        _a33_obj->f_value = t4;
        t2 = (void*) _a33_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l50 == INT32_C(11)) {
        t5 = vader_vm_read_little_endian(l6, (size_t) 0, (size_t) 8, false);
        t4 = vader_box_f64(240u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t5) }).__vd));
        vader_struct_vader_vm_HostOk_t* _a34_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a34_obj, 1107u);
        _a34_obj->f_value = t4;
        t2 = (void*) _a34_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a35_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a35_slotarr, INT32_C(0))
    t4 = vader_array_read_u8(_a35_slotarr, _a35_slotarr->offset + (size_t) INT32_C(0), 249u);
    l69 = ((uint8_t) t4.payload.i);
    t7 = (INT32_C(5) & INT32_C(255));
    l82 = (uint8_t) (int32_t) t7;
    if (l69 == l82) {
        t5 = vader_vm_read_little_endian(l6, (size_t) 0, (size_t) 8, false);
        if (!(t5 == INT64_C(0))) {
            t4 = vader_box_string(243u, l7);
            vader_struct_vader_vm_HostOk_t* _a36_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a36_obj, 1107u);
            _a36_obj->f_value = t4;
            t2 = (void*) _a36_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_vm_NullVal_t* _a37_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
        vader_obj_header_init(_a37_obj, 1110u);
        t2 = (void*) _a37_obj;
        vader_struct_vader_vm_HostOk_t* _a38_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a38_obj, 1107u);
        _a38_obj->f_value = vader_ref_box(t2);
        t2 = (void*) _a38_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l50 == INT32_C(14)) {
        t4 = vader_box_string(243u, l7);
        vader_struct_vader_vm_HostOk_t* _a39_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a39_obj, 1107u);
        _a39_obj->f_value = t4;
        t2 = (void*) _a39_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l73 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    t3 = vader_vm_ffi_result_is_opt(l4, l73, (uint8_t) 17);
    if (t3) {
        t5 = vader_vm_read_little_endian(l6, (size_t) 0, (size_t) 8, false);
        if (t5 == INT64_C(0)) {
            vader_struct_vader_vm_NullVal_t* _a40_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
            vader_obj_header_init(_a40_obj, 1110u);
            t2 = (void*) _a40_obj;
            vader_struct_vader_vm_HostOk_t* _a41_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a41_obj, 1107u);
            _a41_obj->f_value = vader_ref_box(t2);
            t2 = (void*) _a41_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l10 = vader_vm_read_little_endian(l6, (size_t) 0, (size_t) 8, true);
    t4 = vader_vm_extern_result(l50, l10);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_dispatch_import(void* l0, void* l1, size_t l2, void* l3, void* l4, int32_t l5, int32_t l6, int32_t l7, int32_t l8, void* l9, bool l10, vader_box_t l11, uint8_t l12) {
    vader_box_t l13 = vader_box_null(), l15 = vader_box_null(), l26 = vader_box_null(), l28 = vader_box_null();
    size_t l14, l17, l18, l19, l21, l30;
    void* l16 = NULL;
    void* l27 = NULL;
    uint32_t l20;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    int64_t l24, l25;
    uint8_t l29;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    size_t t4;
    int64_t t5, t10;
    int32_t t6;
    uint8_t t7;
    uint64_t t8;
    uint32_t t9;
    vader_box_t* gc_roots[6] = { &l11, &l13, &l15, &l26, &l28, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l9, &l16, &l27, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l22, &l23, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    if (t0 == 2574u) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a0_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a0_obj, 1107u);
        _a0_obj->f_value = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    if (t0 == 2576u) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a1_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a1_obj, 1107u);
        _a1_obj->f_value = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    if (t0 == 2575u) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a2_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a2_obj, 1107u);
        _a2_obj->f_value = t1;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_is_extern;
    if (t3) {
        t1 = vader_vm_dispatch_extern(l0, l1, l2, l5, l9, l11);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l10) {
        t3 = vader_vm_is_impure_host(l12);
        if (t3) {
            t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
            t1 = vader_vm_impure_comptime_trap(t0);
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l12 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 1391u);
        if (!(l13.tag == 1126u)) {
            t0 = l13.payload.s;
            t4 = vader_host_std_core_byte_len(t0);
            t1 = vader_box_i32(246u, ((int32_t) (size_t) t4));
            vader_struct_vader_vm_HostOk_t* _a4_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a4_obj, 1107u);
            _a4_obj->f_value = t1;
            t2 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(2)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
        t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 1390u);
        t5 = vader_chk_add(usize, l2, INT64_C(1));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l14)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l14];
        l15 = vader_vm_read_i32(t1, l5, 1389u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l15.tag == 1126u) {
            t2 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l13.payload.s;
        l16 = vader_host_std_core_bytes(t0);
        t6 = ((int32_t) l15.payload.i);
        t5 = ((int64_t) (int32_t) t6);
        l14 = (size_t) (int64_t) t5;
        l17 = ((vader_array_t*) l16)->length;
        if (!((l14 >= l17))) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l14)
            t1 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l14, 249u);
            t7 = ((uint8_t) t1.payload.i);
            t1 = vader_box_i32(246u, ((int32_t) (uint8_t) t7));
            vader_struct_vader_vm_HostOk_t* _a8_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a8_obj, 1107u);
            _a8_obj->f_value = t1;
            t2 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_vm_Trap_t* _a9_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a9_obj, 1126u);
        _a9_obj->f_message = 1387u;
        t2 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(4)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l2)
        t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_array(t1, l5, 1403u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = l13.payload.obj;
        t2 = l13.payload.obj;
        l14 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
        l13 = vader_vm_array_bytes(l16, l14, l5, 1402u);
        if (!(l13.tag == 1126u)) {
            t2 = l13.payload.obj;
            t0 = vader_host_std_core_bytes_to_string(t2);
            t1 = vader_box_string(243u, t0);
            vader_struct_vader_vm_HostOk_t* _a11_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a11_obj, 1107u);
            _a11_obj->f_value = t1;
            t2 = (void*) _a11_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l2)
        t1 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 1398u);
        if (!(l13.tag == 1126u)) {
            t0 = l13.payload.s;
            t2 = vader_vm_bytes_to_value(t0, l7);
            vader_struct_vader_vm_HostOk_t* _a13_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a13_obj, 1107u);
            _a13_obj->f_value = vader_ref_box(t2);
            t2 = (void*) _a13_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(6)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l2)
        t1 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 1752u);
        if (!(l13.tag == 1126u)) {
            t0 = l13.payload.s;
            t8 = std_core_string_Hash_hash_vt(t0);
            t1 = vader_box_i64(247u, ((int64_t) (uint64_t) t8));
            vader_struct_vader_vm_HostOk_t* _a15_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a15_obj, 1107u);
            _a15_obj->f_value = t1;
            t2 = (void*) _a15_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(5)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l2)
        t1 = vader_array_box_slots(_a16_slotarr->buf)[_a16_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 2288u);
        t5 = vader_chk_add(usize, l2, INT64_C(1));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a17_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l14)
        t1 = vader_array_box_slots(_a17_slotarr->buf)[_a17_slotarr->offset + (size_t) l14];
        l15 = vader_vm_read_i32(t1, l5, 2287u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l15.tag == 1126u) {
            t2 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l13.payload.s;
        l16 = vader_host_std_core_bytes(t0);
        t6 = ((int32_t) l15.payload.i);
        t5 = ((int64_t) (int32_t) t6);
        l14 = (size_t) (int64_t) t5;
        l17 = (size_t) 0;
        l18 = (size_t) 0;
        l19 = ((vader_array_t*) l16)->length;
        while ((l17 < l19)) {
            std_string_utf8_decode_len(l16, l17, &t9, &t4);
            l30 = t4;
            l20 = t9;
            l21 = l30;
            if (l18 == l14) {
                t1 = vader_box_i32(242u, (int32_t) l20);
                vader_struct_vader_vm_HostOk_t* _a18_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a18_obj, 1107u);
                _a18_obj->f_value = t1;
                t2 = (void*) _a18_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t5 = vader_chk_add(usize, l17, l21);
            l17 = (size_t) (int64_t) t5;
            t5 = vader_chk_add(usize, l18, INT64_C(1));
            l18 = (size_t) (int64_t) t5;
        }
        vader_struct_vader_vm_Trap_t* _a19_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a19_obj, 1126u);
        _a19_obj->f_message = 2275u;
        t2 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(7)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l2)
        t1 = vader_array_box_slots(_a20_slotarr->buf)[_a20_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 1582u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_chk_add(usize, l2, INT64_C(1));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a21_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l14)
        t1 = vader_array_box_slots(_a21_slotarr->buf)[_a21_slotarr->offset + (size_t) l14];
        l15 = vader_vm_read_string(t1, l5, 1581u);
        if (!(l15.tag == 1126u)) {
            l22 = l13.payload.s;
            l23 = l15.payload.s;
            t1 = vader_box_bool(241u, l22 == l23);
            vader_struct_vader_vm_HostOk_t* _a22_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a22_obj, 1107u);
            _a22_obj->f_value = t1;
            t2 = (void*) _a22_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l15.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(8)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l2)
        t1 = vader_array_box_slots(_a23_slotarr->buf)[_a23_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_i64(t1, l5, 1582u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_chk_add(usize, l2, INT64_C(1));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l14)
        t1 = vader_array_box_slots(_a24_slotarr->buf)[_a24_slotarr->offset + (size_t) l14];
        l15 = vader_vm_read_i64(t1, l5, 1581u);
        if (!(l15.tag == 1126u)) {
            l24 = ((int64_t) l13.payload.i);
            l25 = ((int64_t) l15.payload.i);
            t1 = vader_box_bool(241u, l24 == l25);
            vader_struct_vader_vm_HostOk_t* _a25_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a25_obj, 1107u);
            _a25_obj->f_value = t1;
            t2 = (void*) _a25_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l15.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(9)) {
        t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
        t3 = vader_bytecode_is_unsigned_display(t0);
        if (!(t3)) {
            vader_array_t* _a26_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l2)
            t1 = vader_array_box_slots(_a26_slotarr->buf)[_a26_slotarr->offset + (size_t) l2];
            t0 = vader_vm_display_value(t1);
            t1 = vader_box_string(243u, t0);
            vader_struct_vader_vm_HostOk_t* _a27_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a27_obj, 1107u);
            _a27_obj->f_value = t1;
            t2 = (void*) _a27_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a28_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l2)
        l13 = vader_array_box_slots(_a28_slotarr->buf)[_a28_slotarr->offset + (size_t) l2];
        if (l13.tag == 247u) {
            t5 = ((int64_t) l13.payload.i);
            t0 = std_core_u64_Display_to_string((uint64_t) (int64_t) t5);
            t1 = vader_box_string(243u, t0);
            vader_struct_vader_vm_HostOk_t* _a29_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a29_obj, 1107u);
            _a29_obj->f_value = t1;
            t2 = (void*) _a29_obj;
            l15 = vader_ref_box(t2);
            { vader_box_t __vret = l15; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l13.tag == 246u) {
            t6 = ((int32_t) l13.payload.i);
            t0 = std_core_u64_Display_to_string((uint64_t) (int64_t) ((int64_t) (uint32_t) t6));
            t1 = vader_box_string(243u, t0);
            vader_struct_vader_vm_HostOk_t* _a30_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a30_obj, 1107u);
            _a30_obj->f_value = t1;
            t2 = (void*) _a30_obj;
            l15 = vader_ref_box(t2);
        } else {
            l22 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
            l23 = vader_vm_describe_value_tag(l13);
            l14 = vader_host_std_core_byte_len(l22);
            l17 = vader_host_std_core_byte_len(l23);
            t5 = (l14 + l17);
            l14 = (size_t) (int64_t) t5;
            l16 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(57) + l14));
            l14 = (size_t) 0;
            l14 = std_core_write_string_at(l16, l14, l22);
            l14 = std_core_write_string_at(l16, l14, 56u);
            l24 = ((int64_t) (int32_t) l5);
            l14 = std_core_write_int(l16, l14, l24);
            l14 = std_core_write_string_at(l16, l14, 371u);
            l14 = std_core_write_string_at(l16, l14, l23);
            t0 = std_core_finish_buffer(l16, l14);
            vader_struct_vader_vm_Trap_t* _a31_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a31_obj, 1126u);
            _a31_obj->f_message = t0;
            t2 = (void*) _a31_obj;
            l15 = vader_ref_box(t2);
        }
        { vader_box_t __vret = l15; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(10)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, INT32_C(0))
        t5 = ((int64_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) INT32_C(0)];
        t10 = vader_chk_add(usize, t5, INT64_C(1));
        l14 = (size_t) (int64_t) t10;
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, INT32_C(0))
        ((int64_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) (int64_t) (size_t) l14;
        vader_struct_vader_vm_NullVal_t* _a33_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
        vader_obj_header_init(_a33_obj, 1110u);
        t2 = (void*) _a33_obj;
        vader_struct_vader_vm_HostOk_t* _a34_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a34_obj, 1107u);
        _a34_obj->f_value = vader_ref_box(t2);
        t2 = (void*) _a34_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(11)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, INT32_C(0))
        t5 = ((int64_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, ((int32_t) (int64_t) t5));
        vader_struct_vader_vm_HostOk_t* _a36_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a36_obj, 1107u);
        _a36_obj->f_value = t1;
        t2 = (void*) _a36_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(12)) {
        vader_struct_vader_vm_HostOk_t* _a37_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a37_obj, 1107u);
        _a37_obj->f_value = vader_box_i32(246u, INT32_C(0));
        t2 = (void*) _a37_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(13)) {
        vader_struct_vader_vm_HostOk_t* _a38_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a38_obj, 1107u);
        _a38_obj->f_value = vader_box_i32(246u, INT32_C(0));
        t2 = (void*) _a38_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(14)) {
        vader_array_t* _a39_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, INT32_C(0))
        t5 = ((int64_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i64(247u, t5);
        vader_struct_vader_vm_HostOk_t* _a40_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a40_obj, 1107u);
        _a40_obj->f_value = t1;
        t2 = (void*) _a40_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(15)) {
        vader_array_t* _a41_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l2)
        t1 = vader_array_box_slots(_a41_slotarr->buf)[_a41_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_i64(t1, l5, 2176u);
        if (!(l13.tag == 1126u)) {
            t5 = ((int64_t) l13.payload.i);
            t10 = t5;
            l14 = (size_t) (int64_t) t10;
            vader_array_push_i64((vader_array_t*) l4, (int64_t) (size_t) l14);
            vader_struct_vader_vm_NullVal_t* _a42_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
            vader_obj_header_init(_a42_obj, 1110u);
            t2 = (void*) _a42_obj;
            vader_struct_vader_vm_HostOk_t* _a43_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a43_obj, 1107u);
            _a43_obj->f_value = vader_ref_box(t2);
            t2 = (void*) _a43_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(16)) {
        vader_vm_drop_due_timers(l4);
        t4 = ((vader_array_t*) l4)->length;
        if ((t4 <= INT64_C(1))) {
            vader_struct_vader_vm_HostOk_t* _a44_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a44_obj, 1107u);
            _a44_obj->f_value = vader_box_i32(246u, INT32_C(1));
            t2 = (void*) _a44_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a45_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, INT32_C(1))
        t5 = ((int64_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) INT32_C(1)];
        l14 = (size_t) (int64_t) t5;
        l17 = (size_t) 2;
        l18 = ((vader_array_t*) l4)->length;
        while ((l17 < l18)) {
            vader_array_t* _a46_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l17)
            t5 = ((int64_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l17];
            if ((t5 < l14)) {
                vader_array_t* _a47_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l17)
                t5 = ((int64_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l17];
                l14 = (size_t) (int64_t) t5;
            }
            t5 = (l17 + INT64_C(1));
            l17 = (size_t) (int64_t) t5;
        }
        vader_array_t* _a48_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, INT32_C(0))
        ((int64_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) (int64_t) (size_t) l14;
        vader_vm_drop_due_timers(l4);
        vader_struct_vader_vm_HostOk_t* _a49_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a49_obj, 1107u);
        _a49_obj->f_value = vader_box_i32(246u, INT32_C(0));
        t2 = (void*) _a49_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(20)) {
        vader_array_t* _a50_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l2)
        t1 = vader_array_box_slots(_a50_slotarr->buf)[_a50_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 1665u);
        if (!(l13.tag == 1126u)) {
            t0 = l13.payload.s;
            t4 = vader_host_vader_vm_ffi_open(t0);
            t1 = vader_box_i64(247u, ((int64_t) (size_t) t4));
            vader_struct_vader_vm_HostOk_t* _a51_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a51_obj, 1107u);
            _a51_obj->f_value = t1;
            t2 = (void*) _a51_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(21)) {
        vader_array_t* _a52_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l2)
        t1 = vader_array_box_slots(_a52_slotarr->buf)[_a52_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_i64(t1, l5, 1666u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_chk_add(usize, l2, INT64_C(1));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a53_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l14)
        t1 = vader_array_box_slots(_a53_slotarr->buf)[_a53_slotarr->offset + (size_t) l14];
        l15 = vader_vm_read_string(t1, l5, 1667u);
        if (!(l15.tag == 1126u)) {
            t5 = ((int64_t) l13.payload.i);
            t10 = t5;
            l14 = (size_t) (int64_t) t10;
            l22 = l15.payload.s;
            t4 = vader_host_vader_vm_ffi_symbol(l14, l22);
            t1 = vader_box_i64(247u, ((int64_t) (size_t) t4));
            vader_struct_vader_vm_HostOk_t* _a54_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a54_obj, 1107u);
            _a54_obj->f_value = t1;
            t2 = (void*) _a54_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l15.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(22)) {
        vader_array_t* _a55_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l2)
        t1 = vader_array_box_slots(_a55_slotarr->buf)[_a55_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_i64(t1, l5, 1662u);
        if (l13.tag == 1126u) {
            t2 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_chk_add(usize, l2, INT64_C(1));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a56_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l14)
        t1 = vader_array_box_slots(_a56_slotarr->buf)[_a56_slotarr->offset + (size_t) l14];
        l15 = vader_vm_read_array(t1, l5, 1660u);
        if (l15.tag == 1126u) {
            t2 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_chk_add(usize, l2, INT64_C(2));
        l14 = (size_t) (int64_t) t5;
        vader_array_t* _a57_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l14)
        t1 = vader_array_box_slots(_a57_slotarr->buf)[_a57_slotarr->offset + (size_t) l14];
        l26 = vader_vm_read_array(t1, l5, 1663u);
        if (l26.tag == 1126u) {
            t2 = l26.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = l15.payload.obj;
        t2 = l15.payload.obj;
        l14 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
        l15 = vader_vm_array_bytes(l16, l14, l5, 1661u);
        if (l15.tag == 1126u) {
            t2 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l26.payload.obj;
        vader_vm_own_bytes(t2);
        vader_array_t* _a58_arr = vader_array_new(16u, 0u, 1u, 249u);
        l16 = (void*) _a58_arr;
        l14 = (size_t) 0;
        t2 = l26.payload.obj;
        l17 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
        while ((l14 < l17)) {
            t2 = l26.payload.obj;
            l27 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
            t2 = l26.payload.obj;
            t4 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
            t5 = vader_chk_add(usize, t4, l14);
            l18 = (size_t) (int64_t) t5;
            vader_array_t* _a59_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l18)
            t1 = vader_array_box_slots(_a59_slotarr->buf)[_a59_slotarr->offset + (size_t) l18];
            l28 = vader_vm_read_i64(t1, l5, 1664u);
            if (l28.tag == 1126u) {
                t2 = l28.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t5 = ((int64_t) l28.payload.i);
            t6 = (((int32_t) (int64_t) t5) & INT32_C(255));
            l29 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l16, (int32_t) (uint8_t) l29);
            t5 = (l14 + INT64_C(1));
            l14 = (size_t) (int64_t) t5;
        }
        t5 = ((int64_t) l13.payload.i);
        t10 = t5;
        l14 = (size_t) (int64_t) t10;
        l27 = l15.payload.obj;
        vader_host_vader_vm_ffi_call(l14, l27, l16, INT64_C(-1));
        l14 = (size_t) 0;
        t2 = l26.payload.obj;
        l17 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
        while ((l14 < l17)) {
            t2 = l26.payload.obj;
            t4 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
            t5 = vader_chk_add(usize, t4, l14);
            l18 = (size_t) (int64_t) t5;
            t2 = l26.payload.obj;
            l27 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
            t2 = l26.payload.obj;
            vader_array_t* _a60_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l18)
            l13 = vader_array_box_slots(_a60_slotarr->buf)[_a60_slotarr->offset + (size_t) l18];
            vader_array_t* _a61_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a61_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l14)
            t1 = vader_array_read_u8(_a61_slotarr, _a61_slotarr->offset + (size_t) l14, 249u);
            t7 = ((uint8_t) t1.payload.i);
            l24 = ((int64_t) (uint8_t) t7);
            l15 = vader_vm_retyped_int(l13, l24);
            vader_array_t* _a62_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l18)
            vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l18] = l15;
            VADER_WRITE_BARRIER(_a62_slotarr->buf);
            t5 = (l14 + INT64_C(1));
            l14 = (size_t) (int64_t) t5;
        }
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a63_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a63_obj, 1107u);
        _a63_obj->f_value = t1;
        t2 = (void*) _a63_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(18)) {
        t7 = vader_host_std_target_current_os();
        t1 = vader_box_i32(246u, ((int32_t) (uint8_t) t7));
        vader_struct_vader_vm_HostOk_t* _a64_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a64_obj, 1107u);
        _a64_obj->f_value = t1;
        t2 = (void*) _a64_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(19)) {
        t7 = vader_host_std_target_current_arch();
        t1 = vader_box_i32(246u, ((int32_t) (uint8_t) t7));
        vader_struct_vader_vm_HostOk_t* _a65_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a65_obj, 1107u);
        _a65_obj->f_value = t1;
        t2 = (void*) _a65_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l12 == INT32_C(17)) {
        vader_array_t* _a66_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l2)
        t1 = vader_array_box_slots(_a66_slotarr->buf)[_a66_slotarr->offset + (size_t) l2];
        l13 = vader_vm_read_string(t1, l5, 2093u);
        if (!(l13.tag == 1126u)) {
            l22 = l13.payload.s;
            t0 = concat_2(2482u, l22);
            vader_struct_vader_vm_Trap_t* _a67_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a67_obj, 1126u);
            _a67_obj->f_message = t0;
            t2 = (void*) _a67_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l13.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l12 == INT32_C(0))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l22 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l14 = vader_host_std_core_byte_len(l22);
    l16 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(49) + l14));
    l14 = (size_t) 0;
    l14 = std_core_write_string_at(l16, l14, 2442u);
    l14 = std_core_write_string_at(l16, l14, l22);
    l14 = std_core_write_string_at(l16, l14, 218u);
    l24 = ((int64_t) (int32_t) l5);
    l14 = std_core_write_int(l16, l14, l24);
    t0 = std_core_finish_buffer(l16, l14);
    vader_struct_vader_vm_Trap_t* _a68_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a68_obj, 1126u);
    _a68_obj->f_message = t0;
    t2 = (void*) _a68_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_display_tags(uint8_t l0) {
    void* l1 = NULL;
    bool l2;
    size_t l3, l4;
    uint8_t l5, l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 2060u; }
    }
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 438u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = (size_t) 0;
    t0 = (void*) &vader_data_46;
    l4 = ((vader_array_t*) t0)->length;
    while ((l3 < l4)) {
        t1 = (((int32_t) (size_t) l3) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        t1 = ((INT32_C(1) << l5) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t1;
        if ((l0 & l6) != INT32_C(0)) {
            if (!(l2)) {
                std_string_builder_append(l1, 2665u);
            }
            t0 = (void*) &vader_data_46;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
            l7 = t2.payload.s;
            std_string_builder_append(l1, l7);
            l2 = false;
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    t4 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_display_value(vader_box_t l0) {
    vader_string_t l1 = 0;
    int32_t t0;
    int64_t t1;
    double t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    bool t5;
    uint32_t t6;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 246u) {
        t0 = ((int32_t) l0.payload.i);
        l1 = vader_vm_I32Val_Display_to_string(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 247u) {
        t1 = ((int64_t) l0.payload.i);
        l1 = vader_vm_I64Val_Display_to_string(t1);
    } else if ((l0.tag == 239u || l0.tag == 240u)) {
        t2 = ((double) l0.payload.f);
        l1 = vader_vm_F64Val_Display_to_string(t2);
    } else if (l0.tag == 243u) {
        t3 = l0.payload.s;
        l1 = vader_vm_StringVal_Display_to_string(t3);
    } else if (l0.tag == 1123u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_StructVal_Display_to_string(t4);
    } else if (l0.tag == 1098u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_ArrayVal_Display_to_string(t4);
    } else if (l0.tag == 1103u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_FnVal_Display_to_string(t4);
    } else if (l0.tag == 1110u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_NullVal_Display_to_string(t4);
    } else if (l0.tag == 241u) {
        t5 = l0.payload.b;
        l1 = vader_vm_BoolVal_Display_to_string(t5);
    } else if (l0.tag == 242u) {
        t6 = ((uint32_t) l0.payload.i);
        l1 = vader_vm_CharVal_Display_to_string(t6);
    } else if (l0.tag == 1102u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_ErrorVal_Display_to_string(t4);
    } else if (l0.tag == 1127u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_TypeVal_Display_to_string(t4);
    } else {
        if (!(l0.tag == 1111u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t4 = l0.payload.obj;
        l1 = vader_vm_ObjVal_Display_to_string(t4);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm_display_verify_error(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    size_t l3, l4;
    void* l5 = NULL;
    int64_t l6;
    int64_t t0;
    int32_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_vm_VerifyError_t*) l0)->f_message;
    l2 = ((vader_struct_vader_vm_VerifyError_t*) l0)->f_function;
    l3 = vader_host_std_core_byte_len(l1);
    l4 = vader_host_std_core_byte_len(l2);
    t0 = (l3 + l4);
    l3 = (size_t) (int64_t) t0;
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(33) + l3));
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l5, l3, l1);
    l3 = std_core_write_string_at(l5, l3, 56u);
    t1 = ((vader_struct_vader_vm_VerifyError_t*) l0)->f_pc;
    l6 = ((int64_t) (int32_t) t1);
    l3 = std_core_write_int(l5, l3, l6);
    l3 = std_core_write_string_at(l5, l3, 83u);
    l3 = std_core_write_string_at(l5, l3, l2);
    l3 = std_core_write_string_at(l5, l3, 213u);
    t2 = std_core_finish_buffer(l5, l3);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_do_memory_copy(void* l0) {
    size_t l1, l11, l12, l13, l14;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l3;
    bool l8;
    void* l9 = NULL;
    void* l16 = NULL;
    int64_t l10;
    uint64_t l15;
    uint8_t l17;
    size_t t0;
    int64_t t1, t5;
    void* t2 = NULL;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t t6 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l2, &l4, &l5, &l6, &l7, &t6 };
    void** gc_raw_roots[4] = { &l0, &l9, &l16, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_i32(l2, l3, 1984u);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 1988u);
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l1 = (size_t) (int64_t) t1;
    l5 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_obj(l5, l3, 1987u);
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(4));
    l1 = (size_t) (int64_t) t1;
    l6 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = vader_vm_read_i32(l6, l3, 1983u);
    if (l6.tag == 1126u) {
        t2 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(5));
    l1 = (size_t) (int64_t) t1;
    l7 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l7 = vader_vm_read_obj(l7, l3, 1982u);
    if (l7.tag == 1126u) {
        t2 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int32_t) l2.payload.i);
    if ((t3 < INT32_C(0))) {
        l8 = true;
    } else {
        t3 = ((int32_t) l4.payload.i);
        l8 = (t3 < INT32_C(0));
    }
    if (l8) {
        l8 = true;
    } else {
        t3 = ((int32_t) l6.payload.i);
        l8 = (t3 < INT32_C(0));
    }
    if (l8) {
        l9 = std_core_new_byte_buffer((size_t) 61);
        l1 = (size_t) 0;
        l1 = std_core_write_string_at(l9, l1, 1985u);
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l10 = ((int64_t) (int32_t) t3);
        l1 = std_core_write_int(l9, l1, l10);
        t4 = std_core_finish_buffer(l9, l1);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t4;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int32_t) l2.payload.i);
    t1 = ((int64_t) (int32_t) t3);
    l1 = (size_t) (int64_t) t1;
    t3 = ((int32_t) l4.payload.i);
    t1 = ((int64_t) (int32_t) t3);
    l11 = (size_t) (int64_t) t1;
    t3 = ((int32_t) l6.payload.i);
    t1 = ((int64_t) (int32_t) t3);
    l12 = (size_t) (int64_t) t1;
    t1 = vader_chk_add(usize, l11, l1);
    l13 = (size_t) (int64_t) t1;
    t2 = l5.payload.obj;
    l14 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
    if ((l13 > l14)) {
        l9 = std_core_new_byte_buffer((size_t) 125);
        l13 = (size_t) 0;
        l13 = std_core_write_string_at(l9, l13, 1986u);
        t1 = ((int64_t) (size_t) l11);
        l15 = (uint64_t) (int64_t) t1;
        l13 = std_core_write_unsigned(l9, l13, l15);
        l13 = std_core_write_string_at(l9, l13, 279u);
        t1 = vader_chk_add(usize, l11, l1);
        t5 = t1;
        l15 = (uint64_t) (int64_t) t5;
        l13 = std_core_write_unsigned(l9, l13, l15);
        l13 = std_core_write_string_at(l9, l13, 251u);
        t2 = l5.payload.obj;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
        t1 = ((int64_t) (size_t) t0);
        l15 = (uint64_t) (int64_t) t1;
        l13 = std_core_write_unsigned(l9, l13, l15);
        l13 = std_core_write_string_at(l9, l13, 56u);
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l10 = ((int64_t) (int32_t) t3);
        l13 = std_core_write_int(l9, l13, l10);
        t4 = std_core_finish_buffer(l9, l13);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1126u);
        _a1_obj->f_message = t4;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_chk_add(usize, l12, l1);
    l13 = (size_t) (int64_t) t1;
    t2 = l7.payload.obj;
    l14 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
    if ((l13 > l14)) {
        l9 = std_core_new_byte_buffer((size_t) 123);
        l13 = (size_t) 0;
        l13 = std_core_write_string_at(l9, l13, 1981u);
        t1 = ((int64_t) (size_t) l12);
        l15 = (uint64_t) (int64_t) t1;
        l13 = std_core_write_unsigned(l9, l13, l15);
        l13 = std_core_write_string_at(l9, l13, 279u);
        t1 = vader_chk_add(usize, l12, l1);
        t5 = t1;
        l15 = (uint64_t) (int64_t) t5;
        l13 = std_core_write_unsigned(l9, l13, l15);
        l13 = std_core_write_string_at(l9, l13, 251u);
        t2 = l7.payload.obj;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
        t1 = ((int64_t) (size_t) t0);
        l15 = (uint64_t) (int64_t) t1;
        l13 = std_core_write_unsigned(l9, l13, l15);
        l13 = std_core_write_string_at(l9, l13, 56u);
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l10 = ((int64_t) (int32_t) t3);
        l13 = std_core_write_int(l9, l13, l10);
        t4 = std_core_finish_buffer(l9, l13);
        vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a2_obj, 1126u);
        _a2_obj->f_message = t4;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 1u, 249u);
    t2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l1);
    l9 = (void*) _a4_arr;
    l13 = (size_t) 0;
    vader_array_t* _pc349_hdr = (vader_array_t*) l9;
    size_t _pc349_len = _pc349_hdr->length;
    size_t _pc349_cap = (_pc349_hdr->offset == 0 && !vader_array_is_borrowed(_pc349_hdr) && _pc349_hdr->length >= _pc349_hdr->buf->length) ? _pc349_hdr->capacity : (size_t) 0;
    void* _pc349_slots = _pc349_hdr->buf->slots;
    for (;;) {
        if ((l13 < l1)) {
            t2 = l5.payload.obj;
            l16 = ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes;
            t1 = vader_chk_add(usize, l11, l13);
            l14 = (size_t) (int64_t) t1;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
            t6 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l14, 249u);
            l17 = ((uint8_t) t6.payload.i);
            if (VADER_LIKELY(_pc349_len < _pc349_cap)) {
                ((uint8_t*) _pc349_slots)[_pc349_len] = (uint8_t) ((int32_t) (uint8_t) l17);
                _pc349_len += 1;
            } else {
                _pc349_hdr->length = _pc349_len;
                if (_pc349_hdr->buf->length < _pc349_len) {
                    _pc349_hdr->buf->length = _pc349_len;
                }
                vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l17);
                _pc349_hdr = (vader_array_t*) l9;
                _pc349_len = _pc349_hdr->length;
                _pc349_cap = (_pc349_hdr->offset == 0 && !vader_array_is_borrowed(_pc349_hdr) && _pc349_hdr->length >= _pc349_hdr->buf->length) ? _pc349_hdr->capacity : (size_t) 0;
                _pc349_slots = _pc349_hdr->buf->slots;
            }
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
            continue;
        }
        _pc349_hdr->length = _pc349_len;
        if (_pc349_hdr->buf->length < _pc349_len) {
            _pc349_hdr->buf->length = _pc349_len;
        }
        break;
    }
    l11 = (size_t) 0;
    while ((l11 < l1)) {
        t2 = l7.payload.obj;
        l16 = ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes;
        t1 = vader_chk_add(usize, l12, l11);
        l13 = (size_t) (int64_t) t1;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
        t6 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l11, 249u);
        l17 = ((uint8_t) t6.payload.i);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l13)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l13] = (uint8_t) (int32_t) (uint8_t) l17;
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(5));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm_drop_due_timers(void* l0) {
    size_t l1, l2, l3, l4, l5, l6;
    int64_t t0;
    size_t t1;
    vader_box_t t2;
    l1 = (size_t) 1;
    for (;;) {
        l2 = ((vader_array_t*) l0)->length;
        if ((l1 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
            t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
            l3 = (size_t) (int64_t) t0;
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
            l4 = (size_t) (int64_t) t0;
            if ((l3 <= l4)) {
                t1 = ((vader_array_t*) l0)->length;
                t0 = vader_chk_sub(usize, t1, INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
                t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
                l6 = (size_t) (int64_t) t0;
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
                ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) (int64_t) (size_t) l6;
                t2 = vader_array_remove_last((vader_array_t*) l0);
                continue;
            }
            t0 = vader_chk_add(usize, l1, INT64_C(1));
            l1 = (size_t) (int64_t) t0;
            continue;
        }
        break;
    }
    return;
}

static void vader_vm_drop_last_op(void* l0) {
    int32_t l1;
    vader_box_t t0;
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_ops);
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_origin);
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds);
    l1 = INT32_C(0);
    while ((l1 < INT32_C(3))) {
        t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_operands);
        l1 = (l1 + INT32_C(1));
    }
    return;
}

static void* vader_vm_effect(size_t l0, size_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_vm_StackEffect_t* _a0_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
    vader_obj_header_init(_a0_obj, 1122u);
    _a0_obj->f_pops = l0;
    _a0_obj->f_pushes = l1;
    _a0_obj->f_flow = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_effect_of(void* l0, void* l1, vader_box_t l2) {
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_locals)->length;
    t0 = vader_chk_add(usize, l3, l4);
    l3 = (size_t) (int64_t) t0;
    if (l2.tag == 665u) {
        t1 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
        t3 = vader_vm_in_range(t2, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 666u) {
        t1 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
        t3 = vader_vm_in_range(t2, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 1, (size_t) 0);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 667u) {
        t1 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
        t3 = vader_vm_in_range(t2, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 1, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 664u) {
        t1 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
        t3 = vader_vm_in_range(t2, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 689u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StringConst_t*) t1)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 590u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 583u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
            t1 = l2.payload.obj;
            t2 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
            t0 = ((int64_t) (int32_t) t2);
            l3 = (size_t) (int64_t) t0;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            l7 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_signature;
            l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_params)->length;
            l4 = vader_bytecode_bc_result_arity(l7);
            t1 = vader_vm_effect(l3, l4);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 584u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_CallImport_t*) t1)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
            t1 = l2.payload.obj;
            t2 = ((vader_struct_vader_bytecode_CallImport_t*) t1)->f_index;
            t0 = ((int64_t) (int32_t) t2);
            l3 = (size_t) (int64_t) t0;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            l7 = ((vader_struct_vader_bytecode_BcImport_t*) t1)->f_signature;
            l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_params)->length;
            l4 = vader_bytecode_bc_result_arity(l7);
            t1 = vader_vm_effect(l3, l4);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 585u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_CallIndirect_t*) t1)->f_type_id;
        l5 = vader_vm_indirect_effect(l0, l6);
    } else if (l2.tag == 711u) {
        t1 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_parameter_count;
        if ((t2 < INT32_C(0))) {
            l5 = vader_box_obj(0u, NULL);
        } else {
            t1 = l2.payload.obj;
            t2 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_parameter_count;
            t0 = ((int64_t) (int32_t) t2);
            l3 = (size_t) (int64_t) t0;
            t1 = l2.payload.obj;
            l8 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_vtable_key;
            l4 = vader_vm_virtual_result_arity(l0, l8);
            t1 = vader_vm_effect(l3, l4);
            l5 = vader_ref_box(t1);
        }
    } else if (l2.tag == 614u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnRef_t*) t1)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 613u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnAddr_t*) t1)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 669u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_MakeClosure_t*) t1)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 1, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 694u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StructNew_t*) t1)->f_type_id;
        l5 = vader_vm_struct_new_effect(l0, l6);
    } else if (l2.tag == 540u) {
        t1 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_ArrayNew_t*) t1)->f_length;
        if ((t2 >= INT32_C(0))) {
            t1 = l2.payload.obj;
            t2 = ((vader_struct_vader_bytecode_ArrayNew_t*) t1)->f_length;
            t1 = vader_vm_effect((size_t) (int64_t) ((int64_t) (int32_t) t2), (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 697u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_TypeConst_t*) t1)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 0, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 696u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_TypeCheck_t*) t1)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
        t3 = vader_vm_in_range(l6, l3);
        if (t3) {
            t1 = vader_vm_effect((size_t) 1, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 587u) {
        t1 = l2.payload.obj;
        t3 = vader_bytecode_is_integer_val(((vader_struct_vader_bytecode_CheckedArith_t*) t1)->f_kind);
        if (t3) {
            t1 = vader_vm_effect((size_t) 2, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 588u) {
        t1 = l2.payload.obj;
        t3 = vader_bytecode_is_integer_val(((vader_struct_vader_bytecode_CheckedNeg_t*) t1)->f_kind);
        if (t3) {
            t1 = vader_vm_effect((size_t) 1, (size_t) 1);
            l5 = vader_ref_box(t1);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if ((l2.tag == 571u || l2.tag == 586u || l2.tag == 601u || l2.tag == 620u || l2.tag == 640u || l2.tag == 671u)) {
        t1 = vader_vm_effect((size_t) 0, (size_t) 1);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 539u || l2.tag == 543u || l2.tag == 567u || l2.tag == 568u || l2.tag == 574u || l2.tag == 578u || l2.tag == 589u || l2.tag == 599u || l2.tag == 610u || l2.tag == 612u || l2.tag == 617u || l2.tag == 630u || l2.tag == 637u || l2.tag == 650u || l2.tag == 673u || l2.tag == 676u || l2.tag == 679u || l2.tag == 693u)) {
        t1 = vader_vm_effect((size_t) 1, (size_t) 1);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 538u || l2.tag == 544u || l2.tag == 570u || l2.tag == 572u || l2.tag == 573u || l2.tag == 575u || l2.tag == 579u || l2.tag == 600u || l2.tag == 602u || l2.tag == 603u || l2.tag == 604u || l2.tag == 605u || l2.tag == 606u || l2.tag == 607u || l2.tag == 608u || l2.tag == 609u || l2.tag == 611u || l2.tag == 615u || l2.tag == 616u || l2.tag == 618u || l2.tag == 619u || l2.tag == 621u || l2.tag == 622u || l2.tag == 623u || l2.tag == 624u || l2.tag == 625u || l2.tag == 626u || l2.tag == 627u || l2.tag == 628u || l2.tag == 629u || l2.tag == 631u || l2.tag == 632u || l2.tag == 633u || l2.tag == 634u || l2.tag == 635u || l2.tag == 636u || l2.tag == 638u || l2.tag == 639u || l2.tag == 641u || l2.tag == 642u || l2.tag == 643u || l2.tag == 644u || l2.tag == 645u || l2.tag == 646u || l2.tag == 647u || l2.tag == 648u || l2.tag == 649u || l2.tag == 651u || l2.tag == 652u || l2.tag == 653u || l2.tag == 654u || l2.tag == 657u || l2.tag == 658u || l2.tag == 659u || l2.tag == 660u || l2.tag == 661u || l2.tag == 662u || l2.tag == 663u || l2.tag == 674u || l2.tag == 675u || l2.tag == 688u || l2.tag == 690u || l2.tag == 691u || l2.tag == 698u || l2.tag == 699u || l2.tag == 700u || l2.tag == 701u || l2.tag == 702u || l2.tag == 703u || l2.tag == 704u || l2.tag == 705u || l2.tag == 706u || l2.tag == 707u || l2.tag == 708u || l2.tag == 709u)) {
        t1 = vader_vm_effect((size_t) 2, (size_t) 1);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 541u || l2.tag == 542u || l2.tag == 695u)) {
        t1 = vader_vm_effect((size_t) 2, (size_t) 0);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 545u || l2.tag == 580u || l2.tag == 681u || l2.tag == 682u || l2.tag == 683u || l2.tag == 684u || l2.tag == 685u || l2.tag == 686u || l2.tag == 687u)) {
        t1 = vader_vm_effect((size_t) 3, (size_t) 0);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 546u || l2.tag == 692u)) {
        t1 = vader_vm_effect((size_t) 3, (size_t) 1);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 537u || l2.tag == 670u)) {
        t1 = vader_vm_effect((size_t) 5, (size_t) 0);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 536u || l2.tag == 593u || l2.tag == 594u)) {
        t1 = vader_vm_effect((size_t) 1, (size_t) 0);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 569u || l2.tag == 592u || l2.tag == 598u || l2.tag == 668u)) {
        t1 = vader_vm_effect((size_t) 0, (size_t) 0);
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 577u || l2.tag == 655u)) {
        vader_struct_vader_vm_StackEffect_t* _a2_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
        vader_obj_header_init(_a2_obj, 1122u);
        _a2_obj->f_pops = (size_t) 1;
        _a2_obj->f_pushes = (size_t) 0;
        _a2_obj->f_flow = (uint8_t) 2;
        t1 = (void*) _a2_obj;
        l5 = vader_ref_box(t1);
    } else if ((l2.tag == 576u || l2.tag == 595u)) {
        vader_struct_vader_vm_StackEffect_t* _a3_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
        vader_obj_header_init(_a3_obj, 1122u);
        _a3_obj->f_pops = (size_t) 0;
        _a3_obj->f_pushes = (size_t) 0;
        _a3_obj->f_flow = (uint8_t) 1;
        t1 = (void*) _a3_obj;
        l5 = vader_ref_box(t1);
    } else {
        if (!((l2.tag == 677u || l2.tag == 678u || l2.tag == 710u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm_StackEffect_t* _a4_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
        vader_obj_header_init(_a4_obj, 1122u);
        _a4_obj->f_pops = (size_t) 0;
        _a4_obj->f_pushes = (size_t) 0;
        _a4_obj->f_flow = (uint8_t) 3;
        t1 = (void*) _a4_obj;
        l5 = vader_ref_box(t1);
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_vm_element_at(void* l0, size_t l1) {
    vader_box_t l2;
    void* t0;
    vader_box_t t1;
    uint8_t t2;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
        t2 = ((uint8_t) t1.payload.i);
        t1 = vader_box_i32(246u, ((int32_t) (uint8_t) t2));
        return t1;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
    return t1;
}

static vader_string_t vader_vm_element_label(int32_t l0) {
    if (l0 == INT32_C(114)) {
        return 1945u;
    }
    if (l0 == INT32_C(115)) {
        return 2267u;
    }
    if (!(l0 == INT32_C(113))) {
        return 1298u;
    }
    return 1311u;
}

static uint8_t vader_vm_element_tags(void* l0, int32_t l1) {
    void* l2;
    size_t l3;
    vader_box_t l4;
    int32_t l5;
    bool t0;
    int64_t t1;
    void* t2;
    uint8_t t3;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_module)->f_types;
    l3 = ((vader_array_t*) l2)->length;
    t0 = vader_vm_in_range(l1, l3);
    if (t0) {
        t1 = ((int64_t) (int32_t) l1);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 548u) {
            t2 = l4.payload.obj;
            l5 = ((vader_struct_vader_bytecode_BcArray_t*) t2)->f_element;
            t3 = vader_vm_tags_of_type(l0, l5);
            return t3;
        }
        return (uint8_t) 127;
    }
    return (uint8_t) 127;
}

static void* vader_vm_element_trap(void* l0, size_t l1, int32_t l2, int32_t l3, void* l4, size_t l5, int32_t l6) {
    vader_string_t l7 = 0;
    size_t l8;
    void* l9 = NULL;
    void* l11 = NULL;
    vader_box_t l10 = vader_box_null();
    int32_t l12, l13;
    int64_t l14;
    uint64_t l15;
    int64_t t0;
    void* t1 = NULL;
    size_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[5] = { &l0, &l4, &l9, &l11, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_vm_element_label(l6);
    t0 = ((int64_t) (int32_t) l2);
    l8 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l8);
    l8 = (size_t) (int64_t) t0;
    l10 = vader_vm_array_at(l0, l8);
    if (l10.tag == 0u) {
        t1 = vader_vm_receiver_trap(l0, l8, l4, l5, l7);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    t0 = ((int64_t) (int32_t) l3);
    l8 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l8);
    l8 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
    l12 = ((int32_t) (int64_t) t0);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l4)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l13 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
    l8 = vader_host_std_core_byte_len(l7);
    l11 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(95) + l8));
    l8 = (size_t) 0;
    l8 = std_core_write_string_at(l11, l8, l7);
    l8 = std_core_write_string_at(l11, l8, 85u);
    l14 = ((int64_t) (int32_t) l12);
    l8 = std_core_write_int(l11, l8, l14);
    l8 = std_core_write_string_at(l11, l8, 112u);
    t2 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_length;
    t0 = ((int64_t) (size_t) t2);
    l15 = (uint64_t) (int64_t) t0;
    l8 = std_core_write_unsigned(l11, l8, l15);
    l8 = std_core_write_string_at(l11, l8, 249u);
    l14 = ((int64_t) (int32_t) l13);
    l8 = std_core_write_int(l11, l8, l14);
    t3 = std_core_finish_buffer(l11, l8);
    vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a2_obj, 1126u);
    _a2_obj->f_message = t3;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_emit(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5) {
    void* l6 = NULL;
    int32_t l7;
    size_t l8;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_ops, l2);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_operands, l3);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_operands, l4);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_operands, l5);
    l6 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_origin;
    l8 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_source_pc)->length;
    if ((l1 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_source_pc);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    } else {
        l7 = ((int32_t) (size_t) l1);
    }
    vader_array_push_i32((vader_array_t*) l6, l7);
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds, INT32_C(16));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_enter_frame(void* l0, void* l1, size_t l2) {
    size_t l3, l4, l5, l7, l10;
    void* l6 = NULL;
    void* l9 = NULL;
    int64_t l8;
    uint8_t l11;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_registers;
    t0 = vader_chk_add(usize, l2, l3);
    l3 = (size_t) (int64_t) t0;
    vader_vm_reserve_registers(l0, l3);
    l3 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_params;
    t0 = vader_chk_add(usize, l2, l3);
    l3 = (size_t) (int64_t) t0;
    l4 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_slots;
    t0 = vader_chk_add(usize, l2, l4);
    l4 = (size_t) (int64_t) t0;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(5);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    l3 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_slots;
    t0 = vader_chk_add(usize, l2, l3);
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_consts)->length;
    while ((l4 < l5)) {
        l6 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        t0 = vader_chk_add(usize, l3, l4);
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_consts);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l8 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7] = (int64_t) l8;
        l9 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags;
        t0 = vader_chk_add(usize, l3, l4);
        l10 = (size_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_const_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l4, 249u);
        l11 = ((uint8_t) t1.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l11;
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_exec_array_copy(void* l0) {
    size_t l1, l8, l9, l10, l11;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l3;
    void* l12 = NULL;
    void* l14 = NULL;
    int64_t l13;
    size_t t0;
    int64_t t1, t5;
    void* t2 = NULL;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[5] = { &l2, &l4, &l5, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l12, &l14, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_i32(l2, l3, 1294u);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 1293u);
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l1 = (size_t) (int64_t) t1;
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_peek_array_mut(l0, l1, l3, 1292u);
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(4));
    l1 = (size_t) (int64_t) t1;
    l6 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = vader_vm_read_i32(l6, l3, 1297u);
    if (l6.tag == 1126u) {
        t2 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(5));
    l1 = (size_t) (int64_t) t1;
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l7 = vader_vm_peek_array_mut(l0, l1, l3, 1296u);
    if (l7.tag == 1126u) {
        t2 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int32_t) l2.payload.i);
    l1 = vader_vm_clamp_nonneg(t3);
    t3 = ((int32_t) l6.payload.i);
    l8 = vader_vm_clamp_nonneg(t3);
    t3 = ((int32_t) l4.payload.i);
    l9 = vader_vm_clamp_nonneg(t3);
    t1 = vader_chk_add(usize, l8, l1);
    l10 = (size_t) (int64_t) t1;
    t2 = l7.payload.obj;
    l11 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
    if ((l10 > l11)) {
        l12 = std_core_new_byte_buffer((size_t) 64);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l12, l10, 1295u);
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t3);
        l10 = std_core_write_int(l12, l10, l13);
        t4 = std_core_finish_buffer(l12, l10);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t4;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_chk_add(usize, l9, l1);
    l10 = (size_t) (int64_t) t1;
    t2 = l5.payload.obj;
    l11 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
    if ((l10 > l11)) {
        l12 = std_core_new_byte_buffer((size_t) 103);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l12, l10, 1291u);
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t3);
        l10 = std_core_write_int(l12, l10, l13);
        t4 = std_core_finish_buffer(l12, l10);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1126u);
        _a1_obj->f_message = t4;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(205u, 0u, 0u, 1642u);
    t2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l1);
    l12 = (void*) _a3_arr;
    l10 = (size_t) 0;
    while ((l10 < l1)) {
        l14 = l7.payload.obj;
        t2 = l7.payload.obj;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
        t1 = vader_chk_add(usize, t0, l8);
        t5 = vader_chk_add(usize, t1, l10);
        l11 = (size_t) (int64_t) t5;
        l2 = vader_vm_element_at(l14, l11);
        vader_array_push((vader_array_t*) l12, l2);
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
    }
    t2 = l5.payload.obj;
    vader_vm_own_bytes(t2);
    l8 = (size_t) 0;
    while ((l8 < l1)) {
        t2 = l5.payload.obj;
        l14 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
        t2 = l5.payload.obj;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
        t1 = vader_chk_add(usize, t0, l9);
        t5 = vader_chk_add(usize, t1, l8);
        l10 = (size_t) (int64_t) t5;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        l2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l10] = l2;
        VADER_WRITE_BARRIER(_a5_slotarr->buf);
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(5));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_array_push_all(void* l0) {
    size_t l1, l5, l8;
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l9 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l9 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_vm_peek_array_mut(l0, l1, l2, 1305u);
    if (l3.tag == 1126u) {
        t2 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_peek_array_mut(l0, l1, l2, 1304u);
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l4.payload.obj;
    vader_vm_detach_array_view(t2);
    t2 = l3.payload.obj;
    l1 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
    l5 = (size_t) 0;
    while ((l5 < l1)) {
        t2 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
        l7 = l3.payload.obj;
        t2 = l3.payload.obj;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
        t1 = vader_chk_add(usize, t0, l5);
        l8 = (size_t) (int64_t) t1;
        l9 = vader_vm_element_at(l7, l8);
        vader_array_push((vader_array_t*) l6, l9);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l6 = l4.payload.obj;
    t2 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
    t1 = vader_chk_add(usize, t0, l1);
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_length = l1;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l2;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_array_repeat(void* l0) {
    size_t l1, l5, l6, l8, l10;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_i32(l2, l3, 1309u);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_peek_array_mut(l0, l1, l3, 1310u);
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int32_t) l2.payload.i);
    l1 = vader_vm_clamp_nonneg(t3);
    t2 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
    if (t0 == INT64_C(0)) {
        l5 = l1;
    } else {
        t2 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
        t1 = vader_chk_mul(usize, l1, l6);
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 0u, 1642u);
    t2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l5);
    l7 = (void*) _a1_arr;
    l5 = (size_t) 0;
    while ((l5 < l1)) {
        l6 = (size_t) 0;
        t2 = l4.payload.obj;
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
        while ((l6 < l8)) {
            l9 = l4.payload.obj;
            t2 = l4.payload.obj;
            t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
            t1 = vader_chk_add(usize, t0, l6);
            l10 = (size_t) (int64_t) t1;
            l2 = vader_vm_element_at(l9, l10);
            vader_array_push((vader_array_t*) l7, l2);
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    t2 = l4.payload.obj;
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_type_id;
    l5 = ((vader_array_t*) l7)->length;
    vader_struct_vader_vm_ArrayVal_t* _a2_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1098u);
    _a2_obj->f_type_id = l3;
    _a2_obj->f_elements = l7;
    _a2_obj->f_offset = (size_t) 0;
    _a2_obj->f_length = l5;
    _a2_obj->f_raw = vader_box_obj(0u, NULL);
    l7 = (void*) _a2_obj;
    vader_vm_push_val(l0, l1, vader_ref_box(l7));
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_array_slice(void* l0, void* l1) {
    size_t l2, l7, l8, l10;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    int32_t l4;
    void* l9 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[3] = { &l3, &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    l3 = vader_vm_peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_vm_read_i32(l3, l4, 1313u);
    if (l3.tag == 1126u) {
        t2 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l2 = (size_t) (int64_t) t1;
    l5 = vader_vm_peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_i32(l5, l4, 1314u);
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l2 = (size_t) (int64_t) t1;
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = vader_vm_peek_array_mut(l0, l2, l4, 1315u);
    if (l6.tag == 1126u) {
        t2 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l6.payload.obj;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
    t3 = ((int32_t) l5.payload.i);
    l7 = vader_vm_clamp_nonneg(t3);
    if ((l7 > l2)) {
        l7 = l2;
    }
    t3 = ((int32_t) l3.payload.i);
    l8 = vader_vm_clamp_nonneg(t3);
    if ((l8 < l7)) {
        l8 = l7;
    }
    if ((l8 > l2)) {
        l8 = l2;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l2 = (size_t) (int64_t) t1;
    l4 = ((vader_struct_vader_bytecode_ArraySlice_t*) l1)->f_type_id;
    t2 = l6.payload.obj;
    l9 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
    t2 = l6.payload.obj;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
    t1 = vader_chk_add(usize, t0, l7);
    l10 = (size_t) (int64_t) t1;
    t1 = vader_chk_sub(usize, l8, l7);
    l7 = (size_t) (int64_t) t1;
    t2 = l6.payload.obj;
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_raw;
    vader_struct_vader_vm_ArrayVal_t* _a0_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a0_obj, 1098u);
    _a0_obj->f_type_id = l4;
    _a0_obj->f_elements = l9;
    _a0_obj->f_offset = l10;
    _a0_obj->f_length = l7;
    _a0_obj->f_raw = l3;
    l9 = (void*) _a0_obj;
    vader_vm_push_val(l0, l2, vader_ref_box(l9));
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l2 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l2;
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l4;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_buffer_write_string(void* l0) {
    size_t l1, l7, l9, l11;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l3, l8;
    void* l6 = NULL;
    void* l10 = NULL;
    uint8_t l12;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    int32_t t5;
    vader_box_t* gc_roots[4] = { &l2, &l4, &l5, &t4 };
    void** gc_raw_roots[4] = { &l0, &l6, &l10, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_string(l2, l3, 1376u);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 1374u);
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l1 = (size_t) (int64_t) t1;
    l5 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_obj(l5, l3, 1375u);
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l2.payload.s;
    l6 = vader_host_std_core_bytes(t3);
    l3 = ((int32_t) l4.payload.i);
    l1 = ((vader_array_t*) l6)->length;
    t2 = l5.payload.obj;
    l7 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_check_byte_range(l3, l1, l7, 1373u, l8);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((size_t) l2.payload.i);
    l7 = (size_t) 0;
    l9 = ((vader_array_t*) l6)->length;
    while ((l7 < l9)) {
        t2 = l5.payload.obj;
        l10 = ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes;
        t1 = vader_chk_add(usize, l1, l7);
        l11 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t4 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 249u);
        l12 = ((uint8_t) t4.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l11] = (uint8_t) (int32_t) (uint8_t) l12;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t5, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5) {
    bool l6;
    size_t l7, l8;
    void* l9 = NULL;
    int64_t l10;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l9, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l6 = true;
    } else {
        t0 = ((int64_t) (int32_t) l1);
        l7 = (size_t) (int64_t) t0;
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions)->length;
        l6 = (l7 >= l8);
    }
    if (l6) {
        l9 = std_core_new_byte_buffer((size_t) 46);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l9, l7, 2044u);
        l10 = ((int64_t) (int32_t) l1);
        l7 = std_core_write_int(l9, l7, l10);
        l7 = std_core_write_string_at(l9, l7, 245u);
        t1 = std_core_finish_buffer(l9, l7);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 0u) {
        l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_reg;
        t3 = vader_vm_reg_run(l0, l9, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((vader_struct_vader_vm_VmState_t*) l0)->f_debuggable;
    if (!(t4)) {
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1126u);
        _a1_obj->f_message = 1200u;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_reg;
    t3 = vader_vm_reg_run(l0, l9, l1, l2, l3, l4, l5);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_vm_exec_fn_value(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    int32_t l5;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_vm_VmState_t*) l0)->f_fn_index_by_name, l1);
    if (l2.tag == 0u) {
        t0 = concat_3(1591u, l1, 213u);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 243u);
    l3 = (void*) _a1_arr;
    t2 = vader_vm_zero_value();
    vader_array_t* _a2_arr = vader_array_new(205u, 1u, 0u, 1642u);
    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = t2;
    l4 = (void*) _a2_arr;
    l5 = ((int32_t) l2.payload.i);
    l2 = vader_vm_exec_entry(l0, l5, l3, vader_ref_box(l4), true, vader_box_obj(0u, NULL));
    if (!(l2.tag == 1126u)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        vader_struct_vader_vm_ValueOk_t* _a4_obj = (vader_struct_vader_vm_ValueOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ValueOk_t));
        vader_obj_header_init(_a4_obj, 1128u);
        _a4_obj->f_value = t2;
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_exec_string_compare(void* l0) {
    size_t l1;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t l8;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[3] = { &l0, &l5, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_string(l2, l3, 2278u);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_string(l4, l3, 2278u);
    if (!(l4.tag == 1126u)) {
        l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        t1 = vader_chk_sub(usize, t0, INT64_C(2));
        l1 = (size_t) (int64_t) t1;
        l6 = l2.payload.s;
        l7 = l4.payload.s;
        l8 = ((int64_t) (int32_t) vader_string_compare(l6, l7));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l8;
        l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        t1 = vader_chk_sub(usize, t0, INT64_C(2));
        l1 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l1 = (size_t) (int64_t) t1;
        ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l3 = vader_chk_add(i32, t3, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_exec_string_slice_codepoints(void* l0) {
    size_t l1, l7, l9, l10, l11, l12, l13, l14, l15;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l3;
    vader_string_t l6 = 0;
    void* l8 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    uint32_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l4, &l5, &t5 };
    void** gc_raw_roots[3] = { &l0, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l1 = (size_t) (int64_t) t1;
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_string(l2, l3, 2286u);
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 2285u);
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    l5 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_i32(l5, l3, 2284u);
    if (l2.tag == 1126u) {
        t2 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l2.payload.s;
    t3 = ((int32_t) l4.payload.i);
    l1 = vader_vm_clamp_nonneg(t3);
    t3 = ((int32_t) l5.payload.i);
    l7 = vader_vm_clamp_nonneg(t3);
    l8 = vader_host_std_core_bytes(l6);
    l9 = ((vader_array_t*) l8)->length;
    l10 = (size_t) 0;
    l11 = (size_t) 0;
    l12 = l9;
    l13 = l9;
    while ((l10 < l9)) {
        if (l11 == l1) {
            l12 = l10;
        }
        if (l11 == l7) {
            l13 = l10;
        }
        std_string_utf8_decode_len(l8, l10, &t4, &t0);
        l15 = t0;
        l14 = l15;
        t1 = vader_chk_add(usize, l10, l14);
        l10 = (size_t) (int64_t) t1;
        t1 = vader_chk_add(usize, l11, INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    if ((l11 <= l1)) {
        l12 = l9;
    }
    if ((l11 <= l7)) {
        l13 = l9;
    }
    if ((l13 < l12)) {
        l13 = l12;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l1 = (size_t) (int64_t) t1;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l8, (size_t) l12, (size_t) l13);
    t2 = (void*) _a0_arr;
    l6 = vader_host_std_core_bytes_to_string(t2);
    t5 = vader_box_string(243u, l6);
    vader_vm_push_val(l0, l1, t5);
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t3, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_vm_extern_by_address(void* l0, size_t l1) {
    size_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address)->length;
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_bool(241u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = t0.payload.b;
        return t1;
    }
    return false;
}

static vader_box_t vader_vm_extern_result(uint8_t l0, int64_t l1) {
    bool l2;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(14)) {
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = 1637u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(16)) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a1_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a1_obj, 1107u);
        _a1_obj->f_value = t1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        t1 = vader_box_bool(241u, ((int32_t) (int64_t) (l1 & INT64_C(4294967295))) != INT32_C(0));
        vader_struct_vader_vm_HostOk_t* _a2_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a2_obj, 1107u);
        _a2_obj->f_value = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(0);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(5);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(13);
    }
    if (!(l2)) {
        t1 = vader_box_i64(247u, l1);
        vader_struct_vader_vm_HostOk_t* _a3_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a3_obj, 1107u);
        _a3_obj->f_value = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_i32(246u, ((int32_t) (int64_t) l1));
    vader_struct_vader_vm_HostOk_t* _a4_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
    vader_obj_header_init(_a4_obj, 1107u);
    _a4_obj->f_value = t1;
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, size_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    size_t l6;
    void* l7 = NULL;
    uint64_t l8;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[1] = { &l7 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 247u)) {
        l4 = l0;
        l5 = l2;
        l6 = vader_host_std_core_byte_len(l5);
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(34) + l6));
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l7, l6, 1636u);
        l6 = std_core_write_string_at(l7, l6, l5);
        l6 = std_core_write_string_at(l7, l6, 886u);
        t0 = ((int64_t) (size_t) l3);
        l8 = (uint64_t) (int64_t) t0;
        l6 = std_core_write_unsigned(l7, l6, l8);
        l5 = std_core_finish_buffer(l7, l6);
        t1 = vader_vm_read_i64(l4, l1, l5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((int64_t) l0.payload.i);
    t1 = vader_box_i64(247u, t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_vm_f64_of(void* l0, size_t l1, int32_t l2) {
    size_t l3;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l3);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t0) }).__vd);
}

static int32_t vader_vm_ffi_result_class(uint8_t l0) {
    if (l0 == INT32_C(16)) {
        return INT32_C(0);
    }
    if (l0 == INT32_C(11)) {
        return INT32_C(2);
    }
    if (!(l0 == INT32_C(14))) {
        return INT32_C(1);
    }
    return INT32_C(4);
}

static bool vader_vm_ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2) {
    size_t l3, l4, l10, l11, l12;
    vader_box_t l5;
    bool l6, l7;
    void* l8;
    int32_t l9;
    int64_t t0;
    void* t1;
    size_t t2;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    l4 = ((vader_array_t*) l0)->length;
    if ((l3 >= l4)) {
        return false;
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l5.tag == 562u)) {
        return false;
    }
    t1 = l5.payload.obj;
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants)->length;
    if (t2 != INT64_C(2)) {
        return false;
    }
    l6 = false;
    l7 = false;
    t1 = l5.payload.obj;
    l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
    l3 = ((vader_array_t*) l8)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        if (!((l9 < INT32_C(0)))) {
            t0 = ((int64_t) (int32_t) l9);
            l10 = (size_t) (int64_t) t0;
            l11 = ((vader_array_t*) l0)->length;
            if (!((l10 >= l11))) {
                t0 = ((int64_t) (int32_t) l9);
                l12 = (size_t) (int64_t) t0;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
                l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                if (l5.tag == 557u) {
                    t1 = l5.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(15)) {
                        l6 = true;
                    }
                    t1 = l5.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == l2) {
                        l7 = true;
                    }
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                continue;
            }
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    if (l6) {
        return l7;
    }
    return false;
}

static uint8_t vader_vm_field_tags(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    size_t l4;
    vader_box_t l5;
    int32_t l6;
    bool t0;
    int64_t t1;
    void* t2;
    uint8_t t3;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_module)->f_types;
    l4 = ((vader_array_t*) l3)->length;
    t0 = vader_vm_in_range(l1, l4);
    if (t0) {
        t1 = ((int64_t) (int32_t) l1);
        l4 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 561u) {
            t2 = l5.payload.obj;
            l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields)->length;
            t0 = vader_vm_in_range(l2, l4);
            if (t0) {
                t2 = l5.payload.obj;
                l3 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
                t1 = ((int64_t) (int32_t) l2);
                l4 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_type_index;
                t3 = vader_vm_tags_of_type(l0, l6);
                return t3;
            }
        }
        return (uint8_t) 127;
    }
    return (uint8_t) 127;
}

static uint8_t vader_vm_field_val_type(void* l0, void* l1) {
    vader_box_t l2;
    uint8_t t0;
    l2 = vader_bytecode_c_field_val_type(l1, l0);
    if (l2.tag == 0u) {
        return (uint8_t) 3;
    }
    t0 = ((uint8_t) l2.payload.i);
    return t0;
}

static uint8_t vader_vm_field_valtype(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    int64_t t0;
    void* t1;
    if ((l1 < INT32_C(0))) {
        return (uint8_t) 18;
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return (uint8_t) 18;
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l4.tag == 557u)) {
        return (uint8_t) 18;
    }
    t1 = l4.payload.obj;
    return ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val;
}

static int32_t vader_vm_find_io_error_type_id(void* l0) {
    int32_t t0;
    t0 = vader_bytecode_struct_type_index(l0, 2247u);
    return t0;
}

static int32_t vader_vm_find_string_array_type_id(void* l0) {
    int32_t l1;
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    int32_t t2;
    l1 = INT32_C(-1);
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 557u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(14)) {
                l1 = ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    if ((l1 < INT32_C(0))) {
        return INT32_C(0);
    }
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        if (l4.tag == 548u) {
            t0 = l4.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
            if (t2 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    return INT32_C(0);
}

static int32_t vader_vm_find_u8_array_type_id(void* l0) {
    int32_t l1;
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    int32_t t2;
    l1 = INT32_C(-1);
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 557u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(5)) {
                l1 = ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    if ((l1 < INT32_C(0))) {
        return INT32_C(0);
    }
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        if (l4.tag == 548u) {
            t0 = l4.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
            if (t2 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    return INT32_C(0);
}

static vader_box_t vader_vm_finish_run(void* l0, bool l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        if (!(l1)) {
            vader_struct_vader_vm_Ok_t* _a0_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
            vader_obj_header_init(_a0_obj, 1112u);
            _a0_obj->f_value = INT32_C(0);
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_vm_register_value(l0, (size_t) 0);
        l4 = vader_vm_read_i32(t1, INT32_C(0), 2163u);
        if (!(l4.tag == 1126u)) {
            t2 = ((int32_t) l4.payload.i);
            vader_struct_vader_vm_Ok_t* _a1_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
            vader_obj_header_init(_a1_obj, 1112u);
            _a1_obj->f_value = t2;
            t0 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        l3 = l2.payload.obj;
        l4 = vader_vm_register_value(l0, (size_t) 0);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) INT32_C(0)] = l4;
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        vader_struct_vader_vm_Ok_t* _a3_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
        vader_obj_header_init(_a3_obj, 1112u);
        _a3_obj->f_value = INT32_C(0);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_Ok_t* _a4_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
    vader_obj_header_init(_a4_obj, 1112u);
    _a4_obj->f_value = INT32_C(0);
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_fits_signed(int32_t l0, int64_t l1) {
    int64_t l2, l3;
    l2 = ((int64_t) (int32_t) l0);
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l3 = vader_chk_neg(i64, (INT64_C(1) << l3));
    if ((l2 >= l3)) {
        l2 = ((int64_t) (int32_t) l0);
        l3 = vader_chk_sub(i64, l1, INT64_C(1));
        l3 = (INT64_C(1) << l3);
        return (l2 < l3);
    }
    return false;
}

static vader_box_t vader_vm_flow_to(void* l0, void* l1, void* l2, size_t l3, size_t l4, size_t l5, size_t l6) {
    size_t l7;
    void* l8 = NULL;
    uint64_t l9;
    vader_string_t l10 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    if ((l3 < l7)) {
        t0 = vader_vm_merge(l0, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l4 != l6)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l8 = std_core_new_byte_buffer((size_t) 98);
    l7 = (size_t) 0;
    l7 = std_core_write_string_at(l8, l7, 1505u);
    t1 = ((int64_t) (size_t) l4);
    l9 = (uint64_t) (int64_t) t1;
    l7 = std_core_write_unsigned(l8, l7, l9);
    l7 = std_core_write_string_at(l8, l7, 142u);
    t1 = ((int64_t) (size_t) l6);
    l9 = (uint64_t) (int64_t) t1;
    l7 = std_core_write_unsigned(l8, l7, l9);
    l7 = std_core_write_string_at(l8, l7, 51u);
    l10 = std_core_finish_buffer(l8, l7);
    t2 = vader_vm_defect(l0, l5, l10);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_flush(void* l0, size_t l1) {
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    while ((l2 < l3)) {
        vader_vm_materialise(l0, l1, l2);
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    ((vader_struct_vader_vm_Translation_t*) l0)->f_retarget = INT64_C(-1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm_fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    int64_t l6;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l5, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l2;
    l4 = vader_host_std_core_byte_len(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(70) + l4));
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 76u);
    l6 = ((int64_t) (int32_t) l0);
    l4 = std_core_write_int(l5, l4, l6);
    l4 = std_core_write_string_at(l5, l4, 114u);
    l6 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l5, l4, l6);
    t0 = std_core_finish_buffer(l5, l4);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1126u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_fn_type_of(void* l0, int32_t l1) {
    size_t l2;
    void* l3;
    vader_box_t l4;
    bool t0;
    int64_t t1;
    void* t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (!(t0)) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
    t1 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l4.tag == 551u) {
        t2 = l4.payload.obj;
        return vader_ref_box(t2);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_vm_fused_branch(int32_t l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(17)) {
        t0 = vader_vm_branch(l1, INT32_C(90), false, INT32_C(91), false);
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        t0 = vader_vm_branch(l1, INT32_C(91), false, INT32_C(90), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(19)) {
        t0 = vader_vm_branch(l1, INT32_C(92), false, INT32_C(93), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(20)) {
        t0 = vader_vm_branch(l1, INT32_C(93), false, INT32_C(92), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(21)) {
        t0 = vader_vm_branch(l1, INT32_C(92), true, INT32_C(93), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(22)) {
        t0 = vader_vm_branch(l1, INT32_C(93), true, INT32_C(92), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(23)) {
        t0 = vader_vm_branch(l1, INT32_C(94), false, INT32_C(95), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(24)) {
        t0 = vader_vm_branch(l1, INT32_C(95), false, INT32_C(94), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(25)) {
        t0 = vader_vm_branch(l1, INT32_C(94), true, INT32_C(95), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(26)) {
        t0 = vader_vm_branch(l1, INT32_C(95), true, INT32_C(94), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(42)) {
        t0 = vader_vm_branch(l1, INT32_C(96), false, INT32_C(97), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(43)) {
        t0 = vader_vm_branch(l1, INT32_C(97), false, INT32_C(96), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(44)) {
        t0 = vader_vm_branch(l1, INT32_C(98), false, INT32_C(99), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(45)) {
        t0 = vader_vm_branch(l1, INT32_C(99), false, INT32_C(98), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(46)) {
        t0 = vader_vm_branch(l1, INT32_C(98), true, INT32_C(99), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(47)) {
        t0 = vader_vm_branch(l1, INT32_C(99), true, INT32_C(98), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(48)) {
        t0 = vader_vm_branch(l1, INT32_C(100), false, INT32_C(101), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(49)) {
        t0 = vader_vm_branch(l1, INT32_C(101), false, INT32_C(100), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(50)) {
        t0 = vader_vm_branch(l1, INT32_C(100), true, INT32_C(101), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(51)) {
        t0 = vader_vm_branch(l1, INT32_C(101), true, INT32_C(100), false);
        l2 = vader_ref_box(t0);
    } else {
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_grow_frame_records(void* l0, void* l1, size_t l2, size_t l3) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_frame_code, vader_ref_box(l1));
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_frame_base, (int64_t) (size_t) l2);
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_frame_return, (int64_t) (size_t) l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_vm_i32_of(void* l0, size_t l1, int32_t l2) {
    size_t l3;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l3);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return ((int32_t) (int64_t) t0);
}

static vader_box_t vader_vm_impure_comptime_trap(vader_string_t l0) {
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_3(1757u, l0, 956u);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1126u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_in_range(int32_t l0, size_t l1) {
    if ((l0 >= INT32_C(0))) {
        return (((int64_t) (int32_t) l0) < l1);
    }
    return false;
}

static void* vader_vm_indirect_call_trap(void* l0, void* l1, size_t l2, size_t l3, int32_t l4) {
    size_t l5, l9, l13;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    bool l8;
    void* l10 = NULL;
    void* l14 = NULL;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int64_t l15;
    uint64_t l16;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    size_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &l6, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l10, &l14, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_chk_add(usize, l2, l3);
    l5 = (size_t) (int64_t) t0;
    t1 = vader_vm_register_value(l1, l5);
    l6 = vader_vm_read_fn(t1, l4, 1425u);
    if (l6.tag == 1126u) {
        t2 = l6.payload.obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l6.payload.obj;
    l7 = ((vader_struct_vader_vm_FnVal_t*) t2)->f_function_index;
    if ((l7 < INT32_C(0))) {
        l8 = true;
    } else {
        t0 = ((int64_t) (int32_t) l7);
        l5 = (size_t) (int64_t) t0;
        l9 = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l0)->f_functions)->length;
        l8 = (l5 >= l9);
    }
    if (l8) {
        t2 = vader_vm_fn_index_trap(l7, l4, 1422u);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm_RegModule_t*) l0)->f_functions;
    t0 = ((int64_t) (int32_t) l7);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l10);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    t2 = l6.payload.obj;
    if (((vader_struct_vader_vm_FnVal_t*) t2)->f_env.tag == 0u) {
        l5 = l3;
    } else {
        t0 = vader_chk_add(usize, l3, INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    t2 = l6.payload.obj;
    if (((vader_struct_vader_vm_FnVal_t*) t2)->f_env.tag == 0u) {
        l11 = 0u;
    } else {
        l11 = 27u;
    }
    l12 = ((vader_struct_vader_vm_RegFunction_t*) l10)->f_name;
    l9 = vader_host_std_core_byte_len(l11);
    l13 = vader_host_std_core_byte_len(l12);
    t0 = (l9 + l13);
    l9 = (size_t) (int64_t) t0;
    l14 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(139) + l9));
    l9 = (size_t) 0;
    l9 = std_core_write_string_at(l14, l9, 1423u);
    l15 = ((int64_t) (int32_t) l4);
    l9 = std_core_write_int(l14, l9, l15);
    l9 = std_core_write_string_at(l14, l9, 361u);
    t0 = ((int64_t) (size_t) l5);
    l16 = (uint64_t) (int64_t) t0;
    l9 = std_core_write_unsigned(l14, l9, l16);
    l9 = std_core_write_string_at(l14, l9, l11);
    l9 = std_core_write_string_at(l14, l9, 58u);
    l9 = std_core_write_string_at(l14, l9, l12);
    l9 = std_core_write_string_at(l14, l9, 219u);
    t3 = ((vader_struct_vader_vm_RegFunction_t*) l10)->f_params;
    t0 = ((int64_t) (size_t) t3);
    l16 = (uint64_t) (int64_t) t0;
    l9 = std_core_write_unsigned(l14, l9, l16);
    l9 = std_core_write_string_at(l14, l9, 116u);
    t4 = std_core_finish_buffer(l14, l9);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t4;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_indirect_effect(void* l0, int32_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    size_t l4;
    int32_t l5;
    bool t0;
    size_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm_fn_type_of(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l5 = ((vader_struct_vader_bytecode_BcFn_t*) l2)->f_return_type;
    t0 = vader_vm_returns_void(l0, l5);
    if (t0) {
        l4 = (size_t) 0;
    } else {
        l4 = (size_t) 1;
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) l2)->f_params)->length;
    t2 = vader_chk_add(usize, t1, INT64_C(1));
    t3 = vader_vm_effect((size_t) (int64_t) t2, l4);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_infer_function_tags(void* l0, void* l1, size_t l2) {
    size_t l3, l6, l9;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    uint8_t l10;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[2] = { &l11, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 8u, 247u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a2_arr;
    t1 = vader_chk_mul(usize, l3, l2);
    l6 = (size_t) (int64_t) t1;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l6);
    l5 = (void*) _a3_arr;
    vader_struct_vader_vm_FunctionTags_t* _a4_obj = (vader_struct_vader_vm_FunctionTags_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FunctionTags_t));
    vader_obj_header_init(_a4_obj, 1105u);
    _a4_obj->f_deepest = l2;
    _a4_obj->f_depth = l4;
    _a4_obj->f_stack = l5;
    l4 = (void*) _a4_obj;
    if (l3 == INT64_C(0)) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_params;
    l3 = ((vader_array_t*) l5)->length;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_locals)->length;
    t1 = vader_chk_add(usize, l3, l6);
    l3 = (size_t) (int64_t) t1;
    l7 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_module;
    t1 = vader_chk_add(usize, l3, l2);
    l6 = (size_t) (int64_t) t1;
    l7 = vader_vm_new_blocks(l7, l1, l6);
    vader_array_t* _a5_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l8 = (void*) _a5_arr;
    l6 = ((vader_struct_vader_vm_Blocks_t*) l7)->f_width;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l8, (size_t) l6);
    l8 = (void*) _a6_arr;
    l6 = (size_t) 0;
    l9 = ((vader_array_t*) l5)->length;
    while ((l6 < l9)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
        t2 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l6, 249u);
        l10 = vader_vm_tags_of_val(((uint8_t) t2.payload.i));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l10;
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l6 = ((vader_array_t*) l5)->length;
    while ((l6 < l3)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(32);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_vm_merge_block(l7, (size_t) 0, (size_t) 0, l8);
    vader_array_t* _a10_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a10_arr;
    l6 = ((vader_struct_vader_vm_Blocks_t*) l7)->f_width;
    vader_array_t* _a11_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l6);
    l5 = (void*) _a11_arr;
    for (;;) {
        t3 = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_work)->length;
        if ((t3 > INT64_C(0))) {
            l11 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_work);
            if (l11.tag == 0u) break;
            l6 = ((size_t) l11.payload.i);
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_queued);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6] = (uint8_t) false;
            vader_vm_walk_block(l0, l1, l7, l6, l3, l5, vader_box_obj(0u, NULL));
            continue;
        }
        break;
    }
    l6 = (size_t) 0;
    l9 = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_leaders)->length;
    while ((l6 < l9)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_entry_depth);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        t1 = ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6];
        if ((t1 >= INT64_C(0))) {
            vader_vm_walk_block(l0, l1, l7, l6, l3, l5, vader_ref_box(l4));
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_infer_module_tags(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l4, l5, l7;
    int64_t t0;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm_new_tag_context(l0);
    vader_array_t* _a0_arr = vader_array_new(168u, 0u, 13u, 1105u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        l7 = (size_t) (int64_t) t0;
        l8 = vader_vm_infer_function_tags(l2, l6, l7);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_inlinable_op(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 594u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 587u || l0.tag == 588u)) {
        l1 = true;
    } else if ((l0.tag == 571u || l0.tag == 586u || l0.tag == 601u || l0.tag == 620u || l0.tag == 640u || l0.tag == 671u)) {
        l1 = true;
    } else if (l0.tag == 589u) {
        l1 = true;
    } else if ((l0.tag == 615u || l0.tag == 616u || l0.tag == 617u || l0.tag == 628u || l0.tag == 630u || l0.tag == 634u)) {
        l1 = true;
    } else if ((l0.tag == 618u || l0.tag == 619u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u)) {
        l1 = true;
    } else if ((l0.tag == 622u || l0.tag == 623u || l0.tag == 624u || l0.tag == 625u || l0.tag == 626u || l0.tag == 629u)) {
        l1 = true;
    } else if ((l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 702u)) {
        l1 = true;
    } else if ((l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 648u || l0.tag == 650u || l0.tag == 654u)) {
        l1 = true;
    } else if ((l0.tag == 638u || l0.tag == 639u || l0.tag == 651u || l0.tag == 652u || l0.tag == 653u)) {
        l1 = true;
    } else if ((l0.tag == 642u || l0.tag == 643u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 649u)) {
        l1 = true;
    } else if ((l0.tag == 705u || l0.tag == 706u || l0.tag == 707u || l0.tag == 708u)) {
        l1 = true;
    } else if ((l0.tag == 600u || l0.tag == 602u || l0.tag == 608u || l0.tag == 610u || l0.tag == 611u)) {
        l1 = true;
    } else if ((l0.tag == 603u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 609u)) {
        l1 = true;
    } else if ((l0.tag == 570u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u)) {
        l1 = true;
    } else {
        l1 = false;
    }
    return l1;
}

static void* vader_vm_inline_into(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l35 = NULL;
    void* l43 = NULL;
    bool l7;
    size_t l8, l9, l20, l21, l26, l27, l32, l33, l37, l38, l39, l44;
    vader_box_t l10 = vader_box_null(), l19 = vader_box_null(), l24 = vader_box_null(), l40 = vader_box_null(), l41 = vader_box_null(), l45 = vader_box_null(), l46 = vader_box_null();
    int32_t l15, l18, l22, l23, l25, l31, l34, l36, l42, l47, l48;
    uint8_t l28;
    vader_string_t l49 = 0;
    bool t0;
    int64_t t1, t6;
    size_t t2;
    void* t3 = NULL;
    int32_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[8] = { &l10, &l19, &l24, &l40, &l41, &l45, &l46, &t5 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l16, &l17, &l29, &l30, &l35, &l43,
        &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l49 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body;
    l5 = l4;
    vader_struct___lambda_env_vader_vm_2_t* _a1_obj = (vader_struct___lambda_env_vader_vm_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_2_t));
    vader_obj_header_init(_a1_obj, 286u);
    _a1_obj->f_cap_0 = l1;
    l6 = (void*) _a1_obj;
    l7 = false;
    l8 = ((vader_array_t*) l5)->length;
    l9 = (size_t) 0;
    {
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            t0 = __lambda_vader_vm_1(l6, l10);
            if (t0) {
                l7 = true;
                goto end_17;
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        l7 = false;
    } end_17: ;
    if (!(l7)) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(187u, 0u, 13u, 1320u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(191u, 0u, 13u, 1375u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l11 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 246u);
    l12 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(46u, 0u, 13u, 554u);
    l13 = (void*) _a7_arr;
    l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_locals;
    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l14);
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_params)->length;
    l15 = ((int32_t) (size_t) t2);
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 246u);
    l14 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(14u, 0u, 7u, 246u);
    l16 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 246u);
    l17 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a11_obj, 329u);
    _a11_obj->f_ekeys = l14;
    _a11_obj->f_evals = l16;
    _a11_obj->f_index = l17;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    l14 = (void*) _a11_obj;
    l8 = (size_t) 0;
    l9 = ((vader_array_t*) l4)->length;
    while ((l8 < l9)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        l10 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        t2 = ((vader_array_t*) l5)->length;
        l18 = ((int32_t) (size_t) t2);
        vader_array_push_i32((vader_array_t*) l12, l18);
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_debug);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        l19 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
        if (l10.tag == 583u) {
            t3 = l10.payload.obj;
            t4 = ((vader_struct_vader_bytecode_Call_t*) t3)->f_function_index;
            t1 = ((int64_t) (int32_t) t4);
            l20 = (size_t) (int64_t) t1;
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l20)
            t5 = vader_box_bool(241u, ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l20]);
            t0 = t5.payload.b;
            if (t0) {
                t3 = l10.payload.obj;
                t4 = ((vader_struct_vader_bytecode_Call_t*) t3)->f_function_index;
                t1 = ((int64_t) (int32_t) t4);
                l21 = (size_t) (int64_t) t1;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l21)
                l16 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l21);
                t3 = l10.payload.obj;
                l23 = ((vader_struct_vader_bytecode_Call_t*) t3)->f_function_index;
                l24 = std_collections_MutableMap_Index_at__i32__i32(l14, l23);
                if (l24.tag == 0u) {
                    l22 = INT32_C(-1);
                } else {
                    l22 = ((int32_t) l24.payload.i);
                }
                if ((l22 < INT32_C(0))) {
                    t2 = ((vader_array_t*) l13)->length;
                    l25 = ((int32_t) (size_t) t2);
                    l22 = vader_chk_add(i32, l15, l25);
                    l17 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_signature)->f_params;
                    l26 = ((vader_array_t*) l17)->length;
                    l27 = (size_t) 0;
                    while ((l27 < l26)) {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l27)
                        t5 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l27, 249u);
                        l28 = ((uint8_t) t5.payload.i);
                        vader_struct_vader_bytecode_BcLocal_t* _a17_obj = (vader_struct_vader_bytecode_BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcLocal_t));
                        vader_obj_header_init(_a17_obj, 554u);
                        _a17_obj->f_name = 1841u;
                        _a17_obj->f_val = l28;
                        l29 = (void*) _a17_obj;
                        vader_array_push((vader_array_t*) l13, vader_ref_box(l29));
                        t1 = (l27 + INT64_C(1));
                        l27 = (size_t) (int64_t) t1;
                    }
                    l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_locals;
                    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l30);
                    t3 = l10.payload.obj;
                    l31 = ((vader_struct_vader_bytecode_Call_t*) t3)->f_function_index;
                    std_collections_MutableMap_IndexSet_set_at__i32__i32(l14, l31, l22);
                }
                l32 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_signature)->f_params)->length;
                l33 = (size_t) 0;
                while ((l33 < l32)) {
                    t1 = vader_chk_sub(usize, l32, INT64_C(1));
                    t6 = vader_chk_sub(usize, t1, l33);
                    l34 = ((int32_t) (int64_t) t6);
                    t4 = vader_chk_add(i32, l22, l34);
                    vader_struct_vader_bytecode_LocalSet_t* _a18_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
                    vader_obj_header_init(_a18_obj, 666u);
                    _a18_obj->f_slot = t4;
                    l35 = (void*) _a18_obj;
                    vader_array_push((vader_array_t*) l5, vader_ref_box(l35));
                    vader_array_push((vader_array_t*) l6, l19);
                    l36 = ((int32_t) (size_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l36);
                    t1 = (l33 + INT64_C(1));
                    l33 = (size_t) (int64_t) t1;
                }
                l37 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_body)->length;
                l38 = (size_t) 0;
                t1 = vader_chk_sub(usize, l37, INT64_C(1));
                l39 = (size_t) (int64_t) t1;
                while ((l38 < l39)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_body);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l38)
                    t5 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l38);
                    l40 = vader_vm_relocated(t5, l22);
                    vader_array_push((vader_array_t*) l5, l40);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l38)
                    l41 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l38);
                    vader_array_push((vader_array_t*) l6, l41);
                    l42 = ((int32_t) (size_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l42);
                    t1 = (l38 + INT64_C(1));
                    l38 = (size_t) (int64_t) t1;
                }
                l43 = ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_body;
                t1 = vader_chk_sub(usize, l37, INT64_C(1));
                l44 = (size_t) (int64_t) t1;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l43);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l44)
                l45 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l44);
                if (l45.tag == 678u) {
                    t3 = l45.payload.obj;
                    l46 = ((vader_struct_vader_bytecode_ReturnLit_t*) t3)->f_value;
                    vader_array_push((vader_array_t*) l5, l46);
                    vader_array_push((vader_array_t*) l6, l19);
                    l47 = ((int32_t) (size_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l47);
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                continue;
            }
        }
        vader_array_push((vader_array_t*) l5, l10);
        vader_array_push((vader_array_t*) l6, l19);
        l48 = ((int32_t) (size_t) l8);
        vader_array_push_i32((vader_array_t*) l11, l48);
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    l4 = l3;
    l49 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_is_main;
    t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature;
    l10 = vader_ref_box(t3);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_jump_table;
    l8 = ((vader_array_t*) l5)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l12, l8);
    vader_struct_vader_bytecode_BcFunction_t* _a22_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a22_obj, 552u);
    _a22_obj->f_name = l49;
    _a22_obj->f_is_main = l7;
    _a22_obj->f_signature = l10.payload.obj;
    _a22_obj->f_locals = l13;
    _a22_obj->f_body = l5;
    _a22_obj->f_debug = l6;
    _a22_obj->f_jump_table = l3;
    _a22_obj->f_source_pc = l11;
    t3 = (void*) _a22_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_inline_leaf_calls(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    size_t l2, l4;
    bool l5;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l6, &l8, &l9, &l10, &l11, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 12u, 241u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_vm_is_inline_leaf(t0);
        vader_array_push_bool((vader_array_t*) l1, l5);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    t2 = std_core____Contains_contains__bool(l1, true);
    if (!(t2)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(44u, 0u, 13u, 552u);
    l3 = (void*) _a3_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l2);
    l3 = (void*) _a4_arr;
    l2 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l2 < l4)) {
        l6 = vader_vm_inline_into(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions, l1, l2);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    l1 = l0;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_name;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_types;
    l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_strings;
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_data_pool;
    l10 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_imports;
    l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_exports;
    l12 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_impl_table;
    l1 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_vtables;
    vader_struct_vader_bytecode_BytecodeModule_t* _a5_obj = (vader_struct_vader_bytecode_BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BytecodeModule_t));
    vader_obj_header_init(_a5_obj, 581u);
    _a5_obj->f_name = l7;
    _a5_obj->f_types = l6;
    _a5_obj->f_strings = l8;
    _a5_obj->f_data_pool = l9;
    _a5_obj->f_functions = l3;
    _a5_obj->f_imports = l10;
    _a5_obj->f_exports = l11;
    _a5_obj->f_impl_table = l12;
    _a5_obj->f_vtables = l1;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_integer_operand_tags(uint8_t l0) {
    bool t0;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        return (uint8_t) 19;
    }
    return (uint8_t) 3;
}

static uint8_t vader_vm_integer_tags(uint8_t l0) {
    bool t0;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        return (uint8_t) 1;
    }
    return (uint8_t) 2;
}

static vader_string_t vader_vm_intrinsic_host_mangle(vader_string_t l0, vader_string_t l1) {
    ptrdiff_t l2;
    void* l3 = NULL;
    size_t l4, l6;
    vader_string_t l5 = 0;
    vader_string_t l7 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l5, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l2 = std_string_last_index_of(l1, 46u, (ptrdiff_t) 0);
    if (!((l2 < INT64_C(0)))) {
        l3 = vader_host_std_core_bytes(l1);
        t0 = ((int64_t) (ptrdiff_t) l2);
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
        t1 = (void*) _a0_arr;
        l5 = vader_host_std_core_bytes_to_string(t1);
        t0 = vader_chk_add(usize, ((int64_t) (ptrdiff_t) l2), INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        l6 = ((vader_array_t*) l3)->length;
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l6);
        t1 = (void*) _a1_arr;
        l7 = vader_host_std_core_bytes_to_string(t1);
        l5 = vader_types_trait_key_name(l5);
        t2 = vader_bytecode_primitive_member_mangle(l0, l5, l7);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static bool vader_vm_is_array_view(void* l0) {
    size_t l1, l2;
    size_t t0;
    int64_t t1;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
    if (t0 != INT64_C(0)) {
        return true;
    }
    l1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    t1 = vader_chk_add(usize, l1, l2);
    l1 = (size_t) (int64_t) t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements)->length;
    return (l1 < l2);
}

static bool vader_vm_is_boxed(vader_box_t l0) {
    return (l0.tag == 536u || l0.tag == 537u || l0.tag == 540u || l0.tag == 542u || l0.tag == 543u || l0.tag == 544u || l0.tag == 546u || l0.tag == 567u || l0.tag == 568u || l0.tag == 570u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 589u || l0.tag == 590u || l0.tag == 599u || l0.tag == 612u || l0.tag == 614u || l0.tag == 622u || l0.tag == 629u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 663u || l0.tag == 669u || l0.tag == 670u || l0.tag == 674u || l0.tag == 675u || l0.tag == 679u || l0.tag == 681u || l0.tag == 682u || l0.tag == 683u || l0.tag == 687u || l0.tag == 688u || l0.tag == 690u || l0.tag == 691u || l0.tag == 692u || l0.tag == 694u || l0.tag == 696u || l0.tag == 697u);
}

static bool vader_vm_is_fn_index_out_of_range(int32_t l0, void* l1) {
    size_t l2, l3;
    int64_t t0;
    if ((l0 < INT32_C(0))) {
        return true;
    }
    t0 = ((int64_t) (int32_t) l0);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l1)->length;
    return (l2 >= l3);
}

static bool vader_vm_is_i32_tag(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(4);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(1);
}

bool vader_vm_is_impure_comptime_trap_message(vader_string_t l0) {
    bool t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_string_Contains_contains(l0, 1885u);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_is_impure_host(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(20)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(21);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(22);
    }
    if (l2) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(18)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(19);
    }
    if (l2) {
        l1 = true;
    } else {
        if (l0 == INT32_C(14)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(15);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(16);
        }
        if (l2) {
            l1 = true;
        } else {
            if (l0 == INT32_C(1)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(2);
            }
            if (l2) {
                l1 = false;
            } else {
                if (l0 == INT32_C(3)) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(4);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(5);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(6);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(7);
                }
                if (l2) {
                    l1 = false;
                } else {
                    if (l0 == INT32_C(8)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(9);
                    }
                    if (l2) {
                        l1 = false;
                    } else {
                        if (l0 == INT32_C(10)) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(11);
                        }
                        if (l2) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(12);
                        }
                        if (l2) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(13);
                        }
                        if (l2) {
                            l1 = false;
                        } else if (l0 == INT32_C(17)) {
                            l1 = false;
                        } else {
                            if (!(l0 == INT32_C(0))) {
                                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                            }
                            l1 = false;
                        }
                    }
                }
            }
        }
    }
    return l1;
}

static bool vader_vm_is_inline_leaf(void* l0) {
    size_t l1, l2, l4, l9, l10;
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7, l8;
    bool t0;
    size_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t3 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = (size_t) 17;
    if ((l1 > l2)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    if ((t1 > INT64_C(1))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    t2 = vader_chk_sub(usize, l1, INT64_C(1));
    l2 = (size_t) (int64_t) t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!((t3.tag == 677u || t3.tag == 678u))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t2 = vader_chk_add(usize, l2, l4);
    l4 = (size_t) (int64_t) t2;
    l3 = (void*) &vader_fn_static___lambda_vader_vm_0;
    l3 = std_core_filled__bool(l4, l3);
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    t2 = vader_chk_sub(usize, l1, INT64_C(1));
    l1 = (size_t) (int64_t) t2;
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l5, (size_t) INT64_C(0), (size_t) l1);
    l5 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l5)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        t0 = vader_vm_inlinable_op(l6);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = vader_vm_slot_touched_by(l6);
        l8 = ((int32_t) (size_t) l2);
        if ((l7 >= l8)) {
            if (l6.tag == 665u) {
                t2 = ((int64_t) (int32_t) l7);
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
                t3 = vader_box_bool(241u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9]);
                t0 = t3.payload.b;
                if (!(t0)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
            }
            t2 = ((int64_t) (int32_t) l7);
            l10 = (size_t) (int64_t) t2;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (uint8_t) true;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_vm_is_integer_alias(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else if (l0 == INT32_C(3)) {
        l1 = true;
    } else if (l0 == INT32_C(4)) {
        l1 = true;
    } else if (l0 == INT32_C(5)) {
        l1 = true;
    } else if (l0 == INT32_C(6)) {
        l1 = true;
    } else if (l0 == INT32_C(7)) {
        l1 = true;
    } else if (l0 == INT32_C(8)) {
        l1 = true;
    } else if (l0 == INT32_C(9)) {
        l1 = true;
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_vm_is_source_local(vader_string_t l0) {
    size_t t0;
    uint8_t t1;
    t0 = vader_host_std_core_byte_len(l0);
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = vader_host_std_core_byte_at(l0, (size_t) 0);
    if (t1 == INT32_C(36)) {
        return false;
    }
    t0 = vader_host_std_core_byte_len(l0);
    if ((t0 >= INT64_C(2))) {
        t1 = vader_host_std_core_byte_at(l0, (size_t) 0);
        if (t1 == INT32_C(95)) {
            t1 = vader_host_std_core_byte_at(l0, (size_t) 1);
            if (t1 == INT32_C(95)) {
                return false;
            }
        }
    }
    if (!(l0 == 1813u)) {
        return true;
    }
    return false;
}

static bool vader_vm_is_std_handle_symbol(vader_string_t l0) {
    return l0 == 503u;
}

static bool vader_vm_is_write_symbol(vader_string_t l0) {
    bool l1;
    if (l0 == 2641u) {
        l1 = true;
    } else {
        l1 = l0 == 863u;
    }
    if (l1) {
        return true;
    }
    return l0 == 795u;
}

static void vader_vm_jump(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5) {
    bool l6, l10;
    int32_t l7, l8, l9;
    void* l11 = NULL;
    int64_t l12;
    int32_t t0;
    size_t t1;
    void** gc_raw_roots[2] = { &l0, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l5 >= INT32_C(0))) {
        l7 = ((int32_t) (size_t) l1);
        l6 = (l5 < l7);
    } else {
        l6 = false;
    }
    t0 = vader_chk_sub(i32, ((int32_t) (size_t) l1), l5);
    l7 = vader_chk_add(i32, t0, INT32_C(1));
    l8 = l2;
    l9 = l3;
    if (l6) {
        l10 = l2 == INT32_C(86);
    } else {
        l10 = false;
    }
    if (l10) {
        l8 = INT32_C(87);
        l9 = l7;
    } else if (l6) {
        vader_vm_emit(l0, l1, INT32_C(108), INT32_C(0), l7, INT32_C(0));
    }
    l11 = ((vader_struct_vader_vm_Translation_t*) l0)->f_jumps;
    t1 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_ops)->length;
    l12 = ((int64_t) (size_t) t1);
    vader_array_push_i64((vader_array_t*) l11, l12);
    l11 = ((vader_struct_vader_vm_Translation_t*) l0)->f_jumps;
    l12 = ((int64_t) (int32_t) l5);
    vader_array_push_i64((vader_array_t*) l11, l12);
    vader_vm_emit(l0, l1, l8, INT32_C(0), l9, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_lent_element_val_type(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    int64_t t0;
    void* t1;
    int32_t t2;
    bool t3;
    vader_box_t t4;
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l4.tag == 548u)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l4.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
    if ((t2 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l4.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
    t0 = ((int64_t) (int32_t) t2);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l4.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
    t0 = ((int64_t) (int32_t) t2);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    if (!(l4.tag == 557u)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l4.payload.obj;
    t3 = vader_bytecode_is_integer_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
    if (!(t3)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l4.payload.obj;
    t4 = vader_box_i32(249u, (int32_t)(uint32_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
    return t4;
}

static bool vader_vm_line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_vm_DebugController_t*) l0)->f_breakpoints, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableSet_Contains_contains__i32(t0, l2);
    return t1;
}

static vader_box_t vader_vm_load_bytes_op(void* l0, size_t l1, vader_string_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l7;
    void* l8 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    uint64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t4 };
    void** gc_raw_roots[3] = { &l0, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    l4 = vader_vm_stack_i32(l0, l3, l2, 2067u);
    if (l4.tag == 1126u) {
        t2 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l3 = (size_t) (int64_t) t1;
    l5 = vader_vm_stack_obj(l0, l3, l2);
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int32_t) l4.payload.i);
    t2 = l5.payload.obj;
    l3 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
    l7 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_check_byte_range(l6, l1, l3, l2, l7);
    if (!(l4.tag == 1126u)) {
        t2 = l5.payload.obj;
        l8 = ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes;
        l3 = ((size_t) l4.payload.i);
        t3 = vader_vm_read_le(l8, l3, l1);
        t4 = vader_box_i64(252u, (int64_t)(uint64_t) t3);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_lookup_vtable_row(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l5;
    void* l4;
    void* l6;
    int64_t t0;
    void* t1;
    int32_t t2;
    if ((l1 < INT32_C(0))) {
        return INT32_C(-1);
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = ((vader_struct_vader_bytecode_VtableRow_t*) t1)->f_entries;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t2 = ((vader_struct_vader_bytecode_VtableEntry_t*) l6)->f_receiver_type_index;
        if (t2 == l2) {
            t2 = ((vader_struct_vader_bytecode_VtableEntry_t*) l6)->f_fn_index;
            return t2;
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    return INT32_C(-1);
}

static void vader_vm_materialise(void* l0, size_t l1, size_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    int32_t l4, l5;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = vader_vm_canonical(l0, l2);
    if (((vader_struct_vader_vm_Pending_t*) l3)->f_kind == INT32_C(2)) {
        l5 = ((vader_struct_vader_vm_Pending_t*) l3)->f_register_v;
        vader_vm_emit(l0, l1, INT32_C(1), l4, l5, INT32_C(0));
    } else {
        t0 = ((vader_struct_vader_vm_Pending_t*) l3)->f_register_v;
        if (t0 != l4) {
            l5 = ((vader_struct_vader_vm_Pending_t*) l3)->f_register_v;
            vader_vm_emit(l0, l1, INT32_C(0), l4, l5, INT32_C(0));
        }
    }
    l3 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
    vader_struct_vader_vm_Pending_t* _a1_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
    vader_obj_header_init(_a1_obj, 1116u);
    _a1_obj->f_kind = (uint8_t) 0;
    _a1_obj->f_register_v = l4;
    l6 = (void*) _a1_obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2, l6);
    VADER_WRITE_BARRIER(_a2_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_merge(void* l0, void* l1, void* l2, size_t l3, size_t l4, size_t l5) {
    int64_t l6, l7;
    void* l8 = NULL;
    size_t l9;
    uint64_t l10;
    vader_string_t l11 = 0;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    if ((t0 < INT64_C(0))) {
        l6 = ((int64_t) (size_t) l4);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l6;
        vader_array_push_i64((vader_array_t*) l2, (int64_t) (size_t) l3);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l6 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
    l7 = ((int64_t) (size_t) l4);
    if (!(l6 != l7)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l8 = std_core_new_byte_buffer((size_t) 113);
    l9 = (size_t) 0;
    l9 = std_core_write_string_at(l8, l9, 2132u);
    t0 = ((int64_t) (size_t) l3);
    l10 = (uint64_t) (int64_t) t0;
    l9 = std_core_write_unsigned(l8, l9, l10);
    l9 = std_core_write_string_at(l8, l9, 148u);
    t0 = ((int64_t) (size_t) l4);
    l10 = (uint64_t) (int64_t) t0;
    l9 = std_core_write_unsigned(l8, l9, l10);
    l9 = std_core_write_string_at(l8, l9, 143u);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l6 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    l9 = std_core_write_int(l8, l9, l6);
    l11 = std_core_finish_buffer(l8, l9);
    t1 = vader_vm_defect(l0, l5, l11);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_merge_block(void* l0, size_t l1, size_t l2, void* l3) {
    size_t l4, l8, l9, l10, l15;
    bool l5;
    void* l6 = NULL;
    void* l14 = NULL;
    int64_t l7;
    uint8_t l11, l12, l13;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_width;
    t0 = vader_chk_mul(usize, l1, l4);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l5 = (t0 < INT64_C(0));
    l6 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry_depth;
    l7 = ((int64_t) (size_t) l2);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (int64_t) l7;
    l8 = (size_t) 0;
    l9 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_width;
    while ((l8 < l9)) {
        l6 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry;
        t0 = vader_chk_add(usize, l4, l8);
        l10 = (size_t) (int64_t) t0;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l10, 249u);
        l11 = ((uint8_t) t1.payload.i);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l8, 249u);
        l12 = ((uint8_t) t1.payload.i);
        t2 = (l11 | l12);
        l13 = (uint8_t) (int32_t) t2;
        if (l13 != l11) {
            l14 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry;
            t0 = vader_chk_add(usize, l4, l8);
            l15 = (size_t) (int64_t) t0;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
            ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l15] = (uint8_t) (int32_t) (uint8_t) l13;
            l5 = true;
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    if (l5) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = vader_box_bool(241u, ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1]);
        t3 = t1.payload.b;
        if (t3) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1] = (uint8_t) true;
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_work, (int64_t) (size_t) l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_mirrored_struct_fields(void* l0, void* l1, size_t l2) {
    size_t l3, l5;
    int32_t l4;
    vader_box_t l6;
    int64_t t0;
    void* t1;
    vader_string_t t2;
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    if ((l4 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((int64_t) (int32_t) l4);
    l3 = (size_t) (int64_t) t0;
    l5 = ((vader_array_t*) l0)->length;
    if ((l3 >= l5)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((int64_t) (int32_t) l4);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (!(l6.tag == 561u)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l6.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
    if (!(t2 == 0u)) {
        t1 = l6.payload.obj;
        return vader_ref_box(((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields);
    }
    return vader_box_obj(0u, NULL);
}

static void vader_vm_move_register(void* l0, size_t l1, size_t l2) {
    void* l3;
    int64_t l4;
    uint8_t l5;
    vader_box_t l6;
    vader_box_t t0;
    l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (int64_t) l4;
    l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 249u);
    l5 = ((uint8_t) t0.payload.i);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) (int32_t) (uint8_t) l5;
    l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs;
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
    l6 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l2];
    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l1] = l6;
    VADER_WRITE_BARRIER(_a5_slotarr->buf);
    return;
}

static int32_t vader_vm_narrow_code(uint8_t l0) {
    int32_t l1;
    bool l2;
    if (l0 == INT32_C(5)) {
        l1 = INT32_C(0);
        return l1;
    }
    if (l0 == INT32_C(0)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(6)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(1)) {
        l1 = INT32_C(3);
    } else {
        if (l0 == INT32_C(2)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(3);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(4);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(7);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(8);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(10);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(11);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(12);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(13);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(14);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(15);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(16);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(17);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(18);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(19);
        }
        if (!(l2)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(-1);
    }
    return l1;
}

static vader_box_t vader_vm_narrow_mask(vader_box_t l0, uint8_t l1) {
    int64_t l2, l4;
    bool l3;
    bool t0;
    int32_t t1;
    vader_box_t t2;
    t0 = vader_bytecode_is_narrow_valtype(l1);
    if (!(t0)) {
        return l0;
    }
    if (l1 == INT32_C(5)) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(0);
    }
    if (l3) {
        l2 = INT64_C(8);
    } else {
        l2 = INT64_C(16);
    }
    l4 = INT64_C(0);
    if (l0.tag == 246u) {
        t1 = ((int32_t) l0.payload.i);
        l4 = ((int64_t) (int32_t) t1);
    } else {
        if (!(l0.tag == 247u)) {
            return l0;
        }
        l4 = ((int64_t) l0.payload.i);
    }
    if (l1 == INT32_C(0)) {
        l3 = true;
        t1 = vader_vm_truncate_to_width(l4, l2, l3);
        t2 = vader_box_i32(246u, t1);
        return t2;
    }
    l3 = l1 == INT32_C(1);
    t1 = vader_vm_truncate_to_width(l4, l2, l3);
    t2 = vader_box_i32(246u, t1);
    return t2;
}

static void vader_vm_narrow_register(void* l0, size_t l1, int32_t l2) {
    int64_t l3, l5;
    void* l4;
    bool l6;
    vader_box_t t0;
    int32_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    if (((int32_t) t0.payload.i) != INT32_C(0)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
        if (((int32_t) t0.payload.i) != INT32_C(1)) {
            return;
        }
    }
    if ((l2 < INT32_C(2))) {
        l3 = INT64_C(8);
    } else {
        l3 = INT64_C(16);
    }
    l4 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
    if (l2 == INT32_C(1)) {
        l6 = true;
    } else {
        l6 = l2 == INT32_C(3);
    }
    t1 = vader_vm_truncate_to_width(l5, l3, l6);
    l3 = ((int64_t) (int32_t) t1);
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
    ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int64_t) l3;
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
    return;
}

static void* vader_vm_new_blocks(void* l0, void* l1, size_t l2) {
    size_t l3, l5, l11, l12;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    bool l9;
    int32_t l10;
    int64_t l14;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    size_t t4;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l4, &l6, &l13, &l15, &l16, &l17, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) true;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l8 = vader_vm_effect_of(l0, l1, l7);
        if (l8.tag == 0u) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        l6 = l8.payload.obj;
        if (((vader_struct_vader_vm_StackEffect_t*) l6)->f_flow == INT32_C(1)) {
            l9 = true;
        } else {
            l9 = ((vader_struct_vader_vm_StackEffect_t*) l6)->f_flow == INT32_C(2);
        }
        if (l9) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            l10 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
            if ((((int64_t) (int32_t) l10) < l3)) {
                t1 = ((int64_t) (int32_t) l10);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l11] = (uint8_t) true;
            }
        }
        if (((vader_struct_vader_vm_StackEffect_t*) l6)->f_flow != INT32_C(0)) {
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            if ((t1 < l3)) {
                t1 = vader_chk_add(usize, l5, INT64_C(1));
                l12 = (size_t) (int64_t) t1;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
                ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l12] = (uint8_t) true;
            }
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a7_arr = vader_array_new(20u, 0u, 4u, 253u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(15u, 1u, 8u, 247u);
    ((int64_t*) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l13 = (void*) _a9_arr;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t2 = vader_box_bool(241u, ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5]);
        t3 = t2.payload.b;
        if (t3) {
            t4 = ((vader_array_t*) l6)->length;
            l14 = ((int64_t) (size_t) t4);
            vader_array_t* _a11_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
            ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5] = (int64_t) l14;
            vader_array_push_i64((vader_array_t*) l6, (int64_t) (size_t) l5);
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a12_arr = vader_array_new(15u, 1u, 8u, 247u);
    ((int64_t*) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = (int64_t) INT64_C(-1);
    l4 = (void*) _a12_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l3);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l15 = (void*) _a14_arr;
    t4 = ((vader_array_t*) l6)->length;
    t1 = vader_chk_mul(usize, t4, l2);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l15, (size_t) l3);
    l15 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(20u, 0u, 4u, 253u);
    l16 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (uint8_t) false;
    l17 = (void*) _a17_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l17, (size_t) l3);
    l17 = (void*) _a18_arr;
    vader_struct_vader_vm_Blocks_t* _a19_obj = (vader_struct_vader_vm_Blocks_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Blocks_t));
    vader_obj_header_init(_a19_obj, 1099u);
    _a19_obj->f_width = l2;
    _a19_obj->f_leaders = l6;
    _a19_obj->f_block_at = l13;
    _a19_obj->f_entry_depth = l4;
    _a19_obj->f_entry = l15;
    _a19_obj->f_work = l16;
    _a19_obj->f_queued = l17;
    t0 = (void*) _a19_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_new_run_host(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 4u, 253u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 1u, 4u, 253u);
    ((int64_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int64_t) INT64_C(0);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    l2 = (void*) _a2_arr;
    vader_struct_vader_vm_RunHost_t* _a3_obj = (vader_struct_vader_vm_RunHost_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RunHost_t));
    vader_obj_header_init(_a3_obj, 1120u);
    _a3_obj->f_gc_state = l0;
    _a3_obj->f_sched_state = l1;
    _a3_obj->f_obj_handles = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_new_tag_context(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    size_t l2, l3;
    int32_t l5;
    uint8_t l6;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_box_t l11 = vader_box_null();
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l7, &l8, &l13, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l10, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 1u, 249u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
        l5 = ((int32_t) (size_t) l2);
        l6 = vader_vm_type_tags(l4, l5, INT32_C(0));
        vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l6);
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 0u, 243u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 254u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 246u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a5_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a5_obj, 337u);
    _a5_obj->f_ekeys = l4;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a5_obj;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    l2 = ((vader_array_t*) l7)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
        l8 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l3);
        l9 = ((vader_struct_vader_bytecode_VtableRow_t*) l8)->f_key;
        t1 = std_collections_MutableMap_Contains_contains__string__Any(l4, l9);
        if (!(t1)) {
            l10 = ((vader_struct_vader_bytecode_VtableRow_t*) l8)->f_key;
            l11 = vader_vm_virtual_signature(l0, l10);
            if (!(l11.tag == 0u)) {
                l12 = ((vader_struct_vader_bytecode_VtableRow_t*) l8)->f_key;
                t2 = l11.payload.obj;
                l13 = ((vader_struct_vader_bytecode_BcSignature_t*) t2)->f_results;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l4, l12, vader_ref_box(l13));
            }
        }
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    vader_struct_vader_vm_TagContext_t* _a7_obj = (vader_struct_vader_vm_TagContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_TagContext_t));
    vader_obj_header_init(_a7_obj, 1124u);
    _a7_obj->f_module = l0;
    _a7_obj->f_type_tags = l1;
    _a7_obj->f_virtual_results = l4;
    t2 = (void*) _a7_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_note_checked_kind(void* l0, vader_box_t l1) {
    void* l2;
    size_t l3;
    uint8_t l4;
    size_t t0;
    int64_t t1;
    void* t2;
    if ((l1.tag == 587u || l1.tag == 588u)) {
        l2 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_bytecode_CheckedArith_t*) t2)->f_kind;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l4;
        return;
    }
    return;
}

static vader_string_t vader_vm_op_text(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 438u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_bytecode_write_op(l1, l0);
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_operand(void* l0, size_t l1) {
    void* l2;
    size_t l3;
    size_t t0;
    int64_t t1;
    void* t2;
    int32_t t3;
    l2 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    t1 = vader_chk_sub(usize, t0, l1);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t3 = ((vader_struct_vader_vm_Pending_t*) t2)->f_register_v;
    return t3;
}

static int32_t vader_vm_operand_a(int64_t l0) {
    int64_t l1, l2;
    l1 = INT64_C(42);
    l1 = (l0 << l1);
    l2 = INT64_C(42);
    return ((int32_t) (int64_t) (l1 >> l2));
}

static int32_t vader_vm_operand_b(int64_t l0) {
    int64_t l1, l2;
    l1 = (l0 << INT64_C(21));
    l2 = INT64_C(43);
    return ((int32_t) (int64_t) (l1 >> l2));
}

static int32_t vader_vm_operand_c(int64_t l0) {
    int64_t l1;
    l1 = INT64_C(43);
    return ((int32_t) (int64_t) (l0 >> l1));
}

static int32_t vader_vm_operand_of(void* l0, size_t l1, size_t l2) {
    void* l3;
    size_t l4;
    int64_t t0, t1;
    int32_t t2;
    l3 = ((vader_struct_vader_vm_Translation_t*) l0)->f_operands;
    t0 = vader_chk_mul(usize, INT64_C(3), l1);
    t1 = vader_chk_add(usize, t0, l2);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    return t2;
}

static bool vader_vm_operands_within(void* l0, size_t l1, uint8_t l2) {
    uint8_t t0;
    bool t1;
    t0 = vader_vm_stack_tags(l0, l1, (size_t) 1);
    t1 = vader_vm_tags_within(t0, l2);
    if (t1) {
        t0 = vader_vm_stack_tags(l0, l1, (size_t) 2);
        t1 = vader_vm_tags_within(t0, l2);
        return t1;
    }
    return false;
}

static void* vader_vm_overflow_trap(vader_string_t l0) {
    vader_string_t l1 = 0;
    size_t l2;
    void* l3 = NULL;
    int64_t l4;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(65) + l2));
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l3, l2, 1420u);
    l4 = ((int64_t) 1024);
    l2 = std_core_write_int(l3, l2, l4);
    l2 = std_core_write_string_at(l3, l2, 248u);
    l2 = std_core_write_string_at(l3, l2, l1);
    l2 = std_core_write_string_at(l3, l2, 213u);
    t0 = std_core_finish_buffer(l3, l2);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1126u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_own_bytes(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_vm_detach_array_view(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_pack_operands(int32_t l0, int32_t l1, int32_t l2) {
    bool l3;
    int64_t l4, l5, l6;
    bool t0;
    vader_box_t t1;
    t0 = vader_vm_fits_signed(l0, INT64_C(22));
    if (t0) {
        l3 = vader_vm_fits_signed(l1, INT64_C(21));
    } else {
        l3 = false;
    }
    if (l3) {
        l3 = vader_vm_fits_signed(l2, INT64_C(21));
    } else {
        l3 = false;
    }
    if (!(l3)) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((int64_t) (int32_t) l0);
    l5 = vader_chk_sub(i64, (INT64_C(1) << INT64_C(22)), INT64_C(1));
    l4 = (l4 & l5);
    l5 = ((int64_t) (int32_t) l1);
    l6 = vader_chk_sub(i64, (INT64_C(1) << INT64_C(21)), INT64_C(1));
    l5 = ((l5 & l6) << INT64_C(22));
    l4 = (l4 | l5);
    l5 = ((int64_t) (int32_t) l2);
    l6 = INT64_C(43);
    l5 = (l5 << l6);
    t1 = vader_box_i64(247u, (l4 | l5));
    return t1;
}

static vader_string_t vader_vm_param_display_name(void* l0, size_t l1) {
    size_t l2;
    void* l3 = NULL;
    uint64_t l4;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_names)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
        t1 = t0.payload.s;
        if (t1 != 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_names);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
            t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
            t1 = t0.payload.s;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = std_core_new_byte_buffer((size_t) 23);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l3, l2, 1277u);
    t2 = ((int64_t) (size_t) l1);
    l4 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l3, l2, l4);
    t1 = std_core_finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_param_mirror_is_mutable(void* l0, size_t l1) {
    size_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_mutable)->length;
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_mutable);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_bool(241u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = t0.payload.b;
        return t1;
    }
    return false;
}

static void* vader_vm_pause_context(void* l0, void* l1, vader_string_t l2, size_t l3, size_t l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    size_t l6, l8, l9, l11, l13, l15, l16, l17, l21;
    vader_box_t l18 = vader_box_null();
    int32_t l23;
    int64_t t0, t1;
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l18 };
    void** gc_raw_roots[12] = { &l0, &l1, &l5, &l7, &l10, &l12, &l14, &l19, &l20, &l22, &l24, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(172u, 0u, 13u, 1114u);
    l5 = (void*) _a0_arr;
    l6 = l4;
    while ((l6 > INT64_C(0))) {
        t0 = vader_chk_sub(usize, l6, INT64_C(1));
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        t0 = vader_chk_sub(usize, l4, INT64_C(1));
        l9 = (size_t) (int64_t) t0;
        if (l6 == l9) {
            l8 = l3;
        } else {
            l10 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_frame_return;
            t0 = vader_chk_add(usize, l6, INT64_C(1));
            l11 = (size_t) (int64_t) t0;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l11];
            l8 = (size_t) (int64_t) t0;
        }
        vader_array_t* _a3_arr = vader_array_new(205u, 0u, 0u, 1642u);
        l12 = (void*) _a3_arr;
        l13 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_slots;
        vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l12, (size_t) l13);
        l14 = (void*) _a4_arr;
        l15 = (size_t) 0;
        l16 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_slots;
        while ((l15 < l16)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_frame_base);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            t0 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
            t1 = vader_chk_add(usize, t0, l15);
            l17 = (size_t) (int64_t) t1;
            l18 = vader_vm_register_value(l1, l17);
            vader_array_push((vader_array_t*) l14, l18);
            t0 = (l15 + INT64_C(1));
            l15 = (size_t) (int64_t) t0;
        }
        l19 = ((vader_struct_vader_vm_VmState_t*) l0)->f_bc;
        l20 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
        t2 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_index;
        t0 = ((int64_t) (int32_t) t2);
        l21 = (size_t) (int64_t) t0;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l20);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l21)
        l22 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l21);
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l7)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        l23 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l8];
        l24 = vader_vm_pause_frame(l19, l22, l14, l23);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l24));
    }
    vader_struct_vader_vm_PauseCtx_t* _a8_obj = (vader_struct_vader_vm_PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseCtx_t));
    vader_obj_header_init(_a8_obj, 1113u);
    _a8_obj->f_reason = l2;
    _a8_obj->f_frames = l5;
    t3 = (void*) _a8_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_pause_frame(void* l0, void* l1, void* l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l10 = 0;
    int32_t l5;
    size_t l6, l7;
    void* l8 = NULL;
    vader_box_t l9 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = 0u;
    l5 = INT32_C(0);
    if ((l3 >= INT32_C(0))) {
        t0 = ((int64_t) (int32_t) l3);
        l6 = (size_t) (int64_t) t0;
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_debug)->length;
        if ((l6 < l7)) {
            l8 = ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_debug;
            t0 = ((int64_t) (int32_t) l3);
            l6 = (size_t) (int64_t) t0;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            if (!(l9.tag == 0u)) {
                t1 = l9.payload.obj;
                l4 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_file;
                t1 = l9.payload.obj;
                l5 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_line;
            }
        }
    }
    l10 = ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_name;
    l8 = vader_vm_project_locals(l2, l3, l1, l0);
    vader_struct_vader_vm_PauseFrame_t* _a1_obj = (vader_struct_vader_vm_PauseFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseFrame_t));
    vader_obj_header_init(_a1_obj, 1114u);
    _a1_obj->f_function_name = l10;
    _a1_obj->f_file = l4;
    _a1_obj->f_line = l5;
    _a1_obj->f_locals = l8;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_peek_array_mut(void* l0, size_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    size_t l7, l8;
    void* l9 = NULL;
    int64_t l10;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l9, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l5, &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l4.tag == 1098u) {
            t1 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = l3;
    t0 = vader_vm_peek_val(l0, l1);
    l6 = vader_vm_describe_value_tag(t0);
    l7 = vader_host_std_core_byte_len(l5);
    l8 = vader_host_std_core_byte_len(l6);
    t2 = (l7 + l8);
    l7 = (size_t) (int64_t) t2;
    l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(49) + l7));
    l7 = (size_t) 0;
    l7 = std_core_write_string_at(l9, l7, l5);
    l7 = std_core_write_string_at(l9, l7, 56u);
    l10 = ((int64_t) (int32_t) l2);
    l7 = std_core_write_int(l9, l7, l10);
    l7 = std_core_write_string_at(l9, l7, 365u);
    l7 = std_core_write_string_at(l9, l7, l6);
    t3 = std_core_finish_buffer(l9, l7);
    vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a2_obj, 1126u);
    _a2_obj->f_message = t3;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_peek_owned(void* l0, size_t l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(246u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(247u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(240u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(241u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        t1 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(242u, (int32_t) ((uint32_t) (int32_t) ((int32_t) (int64_t) t1)));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm_NullVal_t* _a7_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
        vader_obj_header_init(_a7_obj, 1110u);
        t2 = (void*) _a7_obj;
        l3 = vader_ref_box(t2);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_peek_val(void* l0, size_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    if (((int32_t) t0.payload.i) == INT32_C(5)) {
        t1 = (void*) &vader_data_47;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm_peek_owned(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_pop_to(void* l0, size_t l1) {
    size_t l2;
    vader_box_t t0;
    int64_t t1;
    int32_t t2;
    l2 = (size_t) 0;
    while ((l2 < l1)) {
        t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    t2 = vader_vm_canonical(l0, l2);
    return t2;
}

vader_box_t vader_vm_prepare(void* l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_vm_prepare_for(l0, false);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_prepare_for(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1) {
        t0 = vader_vm_prepare_module(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_vm_inline_leaf_calls(l0);
    l2 = vader_vm_prepare_module(t1, false);
    if (l2.tag == 1130u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm_prepare_module(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_prepare_module(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    size_t l4, l6;
    uint8_t l8;
    vader_string_t l10 = 0;
    int32_t l11, l13, l14, l15;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[7] = { &l0, &l3, &l5, &l7, &l9, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_vm_verify_module(l0);
    if (l2.tag == 1129u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    l3 = vader_vm_infer_module_tags(l0, l3);
    l2 = vader_vm_check_module_tags(l0, l3);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_vm_translate_module(l0, l3, l1);
    if (l2.tag == 1129u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 1u, 249u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_is_extern;
        if (t1) {
            vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
        } else {
            t2 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_mangled_name;
            l8 = vader_bytecode_intrinsic_id_for(t2);
            vader_array_push_u8((vader_array_t*) l3, (int32_t) (uint8_t) l8);
        }
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a3_arr = vader_array_new(13u, 0u, 0u, 243u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 246u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l9 = (void*) _a5_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a6_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a6_obj, 384u);
    _a6_obj->f_ekeys = l5;
    _a6_obj->f_evals = l7;
    _a6_obj->f_index = l9;
    _a6_obj->f_mask = (size_t) 0;
    _a6_obj->f_size = (size_t) 0;
    _a6_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a6_obj;
    l4 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l4 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
        l10 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
        l11 = ((int32_t) (size_t) l4);
        std_collections_MutableMap_IndexSet_set_at__string__i32(l5, l10, l11);
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool;
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
    l12 = vader_bytecode_data_pool_type_ids(l0);
    l7 = vader_vm_reduce_data_pool(l7, l9, l12);
    l11 = vader_vm_reduce_main_index(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l13 = vader_vm_find_string_array_type_id(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l14 = vader_vm_find_u8_array_type_id(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l15 = vader_vm_find_io_error_type_id(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l9 = l2.payload.obj;
    vader_struct_vader_vm_VmState_t* _a8_obj = (vader_struct_vader_vm_VmState_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VmState_t));
    vader_obj_header_init(_a8_obj, 1130u);
    _a8_obj->f_bc = l0;
    _a8_obj->f_data_pool = l7;
    _a8_obj->f_main_index = l11;
    _a8_obj->f_string_array_type_id = l13;
    _a8_obj->f_u8_array_type_id = l14;
    _a8_obj->f_io_error_type_id = l15;
    _a8_obj->f_fn_index_by_name = l5;
    _a8_obj->f_import_ids = l3;
    _a8_obj->f_reg = l9;
    _a8_obj->f_debuggable = l1;
    t0 = (void*) _a8_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_primitive_impl_import(vader_string_t l0, size_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(19);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(19);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(13u, 0u, 0u, 243u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(11u, 0u, 12u, 241u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(11u, 0u, 12u, 241u);
    l8 = (void*) _a7_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a8_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a8_obj, 559u);
    _a8_obj->f_params = l2;
    _a8_obj->f_results = l3;
    _a8_obj->f_param_types = l4;
    _a8_obj->f_result_types = l5;
    _a8_obj->f_param_names = l6;
    _a8_obj->f_param_mutable = l7;
    _a8_obj->f_param_by_address = l8;
    l2 = (void*) _a8_obj;
    vader_struct_vader_bytecode_BcImport_t* _a9_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
    vader_obj_header_init(_a9_obj, 553u);
    _a9_obj->f_extern_name = 0u;
    _a9_obj->f_mangled_name = l0;
    _a9_obj->f_signature = l2;
    _a9_obj->f_is_extern = false;
    _a9_obj->f_c_header = 0u;
    _a9_obj->f_c_library = 0u;
    _a9_obj->f_c_variadic_fixed = INT32_C(-1);
    t0 = (void*) _a9_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_primitive_kind_at(void* l0, int32_t l1) {
    bool l2;
    size_t l3, l4;
    vader_box_t l5;
    int64_t t0;
    void* t1;
    vader_string_t t2;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((int64_t) (int32_t) l1);
        l3 = (size_t) (int64_t) t0;
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        return 0u;
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l5.tag == 557u)) {
        return 0u;
    }
    t1 = l5.payload.obj;
    t2 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
    return t2;
}

static bool vader_vm_primitive_matches(vader_box_t l0, uint8_t l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = vader_bytecode_val_type_name(l1);
    l3 = vader_vm_describe_value_tag(l0);
    if (l2 == l3) {
        return true;
    }
    t0 = vader_vm_is_integer_alias(l1);
    if (t0) {
        if (l0.tag == 246u) {
            return true;
        }
        return l0.tag == 247u;
    }
    if (l1 == INT32_C(10)) {
        return (l0.tag == 239u || l0.tag == 240u);
    }
    if (!(l1 == INT32_C(17))) {
        return false;
    }
    if (l0.tag == 247u) {
        return true;
    }
    return l0.tag == 246u;
}

static int32_t vader_vm_primitive_type_id(void* l0, vader_box_t l1) {
    vader_string_t l2;
    size_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l2 = vader_vm_describe_value_tag(l1);
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = l5;
        if (l5.tag == 557u) {
            t0 = l6.payload.obj;
            t1 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
            if (t1 == l2) {
                return ((int32_t) (size_t) l3);
            }
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return INT32_C(-1);
}

static void* vader_vm_project_locals(void* l0, int32_t l1, void* l2, void* l3) {
    size_t l4, l5, l8, l9, l11, l12, l14;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    int32_t l10, l13, l15;
    vader_string_t l17 = 0;
    vader_box_t l18 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    bool t4;
    vader_box_t* gc_roots[2] = { &l18, &t2 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l6, &l7, &l16, &l19, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals)->length;
    t0 = vader_chk_add(usize, l4, l5);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l5);
    l7 = (void*) _a3_arr;
    l8 = (size_t) 0;
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
    while ((l8 < l9)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
        l10 = vader_vm_slot_touched_by(t2);
        if ((l10 >= INT32_C(0))) {
            if ((((int64_t) (int32_t) l10) < l5)) {
                t0 = ((int64_t) (int32_t) l10);
                l11 = (size_t) (int64_t) t0;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
                t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l11];
                if ((t3 < INT32_C(0))) {
                    t0 = ((int64_t) (int32_t) l10);
                    l12 = (size_t) (int64_t) t0;
                    l13 = ((int32_t) (size_t) l8);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
                    ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l12] = (int32_t) l13;
                }
                t0 = ((int64_t) (int32_t) l10);
                l14 = (size_t) (int64_t) t0;
                l15 = ((int32_t) (size_t) l8);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l14)
                ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l14] = (int32_t) l15;
            }
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a8_arr = vader_array_new(173u, 0u, 13u, 1115u);
    l16 = (void*) _a8_arr;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        l8 = ((vader_array_t*) l0)->length;
        if ((l5 < l8)) {
            l17 = vader_vm_param_display_name(((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature, l5);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
            l18 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
            l19 = vader_vm_project_var(l17, l18, l3, INT32_C(0));
            vader_array_push((vader_array_t*) l16, vader_ref_box(l19));
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    l5 = (size_t) 0;
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals)->length;
    while ((l5 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t1 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
        l17 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_name;
        t0 = vader_chk_add(usize, l4, l5);
        l9 = (size_t) (int64_t) t0;
        l11 = ((vader_array_t*) l0)->length;
        if ((l9 < l11)) {
            t4 = vader_vm_is_source_local(l17);
            if (t4) {
                t4 = vader_vm_slot_in_scope(l6, l7, l9, l1);
                if (t4) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                    l18 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l9];
                    l19 = vader_vm_project_var(l17, l18, l3, INT32_C(0));
                    vader_array_push((vader_array_t*) l16, vader_ref_box(l19));
                }
            }
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    { void* __vret = l16; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_project_struct_fields(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l14 = NULL;
    size_t l5, l6, l10, l11;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    uint64_t l12;
    int32_t l13;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l7, &l14, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(173u, 0u, 13u, 1115u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 243u);
    l4 = (void*) _a1_arr;
    t0 = ((vader_struct_vader_vm_StructVal_t*) l0)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l5 = (size_t) (int64_t) t1;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_types)->length;
    if ((l5 < l6)) {
        l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_types;
        t0 = ((vader_struct_vader_vm_StructVal_t*) l0)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (l8.tag == 561u) {
            t2 = l8.payload.obj;
            l7 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
            l5 = ((vader_array_t*) l7)->length;
            l6 = (size_t) 0;
            while ((l6 < l5)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
                t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                l9 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_name;
                vader_array_push((vader_array_t*) l4, vader_box_string(243u, l9));
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
            }
        }
    }
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields)->length;
    while ((l5 < l6)) {
        l10 = ((vader_array_t*) l4)->length;
        if ((l5 < l10)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            t3 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
            l9 = t3.payload.s;
        } else {
            l7 = std_core_new_byte_buffer((size_t) 25);
            l11 = (size_t) 0;
            l11 = std_core_write_string_at(l7, l11, 1668u);
            t1 = ((int64_t) (size_t) l5);
            l12 = (uint64_t) (int64_t) t1;
            l11 = std_core_write_unsigned(l7, l11, l12);
            l9 = std_core_finish_buffer(l7, l11);
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l8 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l5];
        l13 = vader_chk_add(i32, l2, INT32_C(1));
        l14 = vader_vm_project_var(l9, l8, l1, l13);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_project_var(vader_string_t l0, vader_box_t l1, void* l2, int32_t l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    size_t l5, l6, l8, l12;
    uint64_t l9;
    vader_string_t l10 = 0;
    vader_box_t l13 = vader_box_null();
    int32_t l14;
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l13 };
    void** gc_raw_roots[6] = { &l2, &l4, &l7, &l11, &l15, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(173u, 0u, 13u, 1115u);
    l4 = (void*) _a0_arr;
    if ((l3 < INT32_C(5))) {
        if (l1.tag == 1098u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            if ((t1 > INT64_C(64))) {
                l5 = (size_t) 64;
            } else {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            }
            l6 = (size_t) 0;
            while ((l6 < l5)) {
                l7 = std_core_new_byte_buffer((size_t) 22);
                l8 = (size_t) 0;
                l8 = std_core_write_string_at(l7, l8, 799u);
                t2 = ((int64_t) (size_t) l6);
                l9 = (uint64_t) (int64_t) t2;
                l8 = std_core_write_unsigned(l7, l8, l9);
                l8 = std_core_write_string_at(l7, l8, 802u);
                l10 = std_core_finish_buffer(l7, l8);
                l11 = l1.payload.obj;
                t0 = l1.payload.obj;
                t1 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
                t2 = vader_chk_add(usize, t1, l6);
                l12 = (size_t) (int64_t) t2;
                l13 = vader_vm_element_at(l11, l12);
                l14 = vader_chk_add(i32, l3, INT32_C(1));
                l15 = vader_vm_project_var(l10, l13, l2, l14);
                vader_array_push((vader_array_t*) l4, vader_ref_box(l15));
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
            }
        } else if (l1.tag == 1123u) {
            t0 = l1.payload.obj;
            l4 = vader_vm_project_struct_fields(t0, l2, l3);
        }
        l10 = vader_vm_display_value(l1);
        vader_struct_vader_vm_PauseVar_t* _a1_obj = (vader_struct_vader_vm_PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseVar_t));
        vader_obj_header_init(_a1_obj, 1115u);
        _a1_obj->f_name = l0;
        _a1_obj->f_value = l10;
        _a1_obj->f_children = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_vm_display_value(l1);
    vader_struct_vader_vm_PauseVar_t* _a2_obj = (vader_struct_vader_vm_PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseVar_t));
    vader_obj_header_init(_a2_obj, 1115u);
    _a2_obj->f_name = l0;
    _a2_obj->f_value = l10;
    _a2_obj->f_children = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_push_constant(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l6;
    size_t l7, l8;
    int32_t l9;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm_scalar_of(l1);
    if (l3.tag == 0u) {
        vader_host_std_abort_panic(2143u);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        l4 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_consts;
        l5 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_const_tags;
        l6 = vader_vm_constant_index(l4, l5, l2);
        if (!((l6 < INT64_C(0)))) {
            l2 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
            l7 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_slots;
            t0 = l6;
            l8 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l7, l8);
            l9 = ((int32_t) (int64_t) t0);
            vader_struct_vader_vm_Pending_t* _a0_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
            vader_obj_header_init(_a0_obj, 1116u);
            _a0_obj->f_kind = (uint8_t) 2;
            _a0_obj->f_register_v = l9;
            l4 = (void*) _a0_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_host_std_abort_panic(2144u);
        vader_unreachable("a no-return call returned");
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_vm_push_little_endian(void* l0, int64_t l1, size_t l2) {
    size_t l3;
    int64_t l4;
    uint8_t l5;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        t0 = vader_chk_mul(usize, l3, INT64_C(8));
        l4 = t0;
        t1 = (((int32_t) (int64_t) ((l1 >> l4) & INT64_C(255))) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        vader_array_push_u8((vader_array_t*) l0, (int32_t) (uint8_t) l5);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_push_register(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
    vader_struct_vader_vm_Pending_t* _a0_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
    vader_obj_header_init(_a0_obj, 1116u);
    _a0_obj->f_kind = (uint8_t) 0;
    _a0_obj->f_register_v = l1;
    l3 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_push_val(void* l0, size_t l1, vader_box_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t t0;
    double t1;
    bool t2;
    uint32_t t3;
    if (l2.tag == 246u) {
        l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        t0 = ((int32_t) l2.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        return;
    }
    if (l2.tag == 247u) {
        l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        l4 = ((int64_t) l2.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(1);
    } else if ((l2.tag == 239u || l2.tag == 240u)) {
        l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        t1 = ((double) l2.payload.f);
        l4 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(2);
    } else if (l2.tag == 241u) {
        l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        t2 = l2.payload.b;
        if (t2) {
            l4 = INT64_C(1);
        } else {
            l4 = INT64_C(0);
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(3);
    } else if (l2.tag == 242u) {
        l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        t3 = ((uint32_t) l2.payload.i);
        l4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
        ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
        ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(4);
    } else if (l2.tag == 1110u) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l1)
        ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(5);
    } else {
        l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_stack;
        l5 = l2;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l1)
        vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l1] = l5;
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l1)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(6);
    }
    return;
}

static uint8_t vader_vm_pushed_tags(void* l0, vader_box_t l1, void* l2, uint8_t l3) {
    uint8_t l4, l7;
    size_t l5;
    int32_t l6, l8;
    void* l9;
    vader_box_t l10;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    if ((l1.tag == 539u || l1.tag == 599u || l1.tag == 615u || l1.tag == 616u || l1.tag == 617u || l1.tag == 618u || l1.tag == 619u || l1.tag == 620u || l1.tag == 621u || l1.tag == 627u || l1.tag == 628u || l1.tag == 630u || l1.tag == 631u || l1.tag == 632u || l1.tag == 633u || l1.tag == 634u || l1.tag == 658u || l1.tag == 663u || l1.tag == 688u || l1.tag == 698u || l1.tag == 703u)) {
        l4 = (uint8_t) 1;
        return l4;
    }
    if ((l1.tag == 612u || l1.tag == 635u || l1.tag == 636u || l1.tag == 637u || l1.tag == 638u || l1.tag == 639u || l1.tag == 640u || l1.tag == 641u || l1.tag == 647u || l1.tag == 648u || l1.tag == 650u || l1.tag == 651u || l1.tag == 652u || l1.tag == 653u || l1.tag == 654u || l1.tag == 659u || l1.tag == 679u || l1.tag == 704u || l1.tag == 709u)) {
        l4 = (uint8_t) 2;
    } else if ((l1.tag == 567u || l1.tag == 568u || l1.tag == 600u || l1.tag == 601u || l1.tag == 602u || l1.tag == 608u || l1.tag == 610u || l1.tag == 611u || l1.tag == 657u || l1.tag == 660u)) {
        l4 = (uint8_t) 4;
    } else if ((l1.tag == 570u || l1.tag == 571u || l1.tag == 572u || l1.tag == 573u || l1.tag == 574u || l1.tag == 575u || l1.tag == 603u || l1.tag == 604u || l1.tag == 605u || l1.tag == 606u || l1.tag == 607u || l1.tag == 609u || l1.tag == 622u || l1.tag == 623u || l1.tag == 624u || l1.tag == 625u || l1.tag == 626u || l1.tag == 629u || l1.tag == 642u || l1.tag == 643u || l1.tag == 644u || l1.tag == 645u || l1.tag == 646u || l1.tag == 649u || l1.tag == 674u || l1.tag == 675u || l1.tag == 690u || l1.tag == 691u || l1.tag == 696u || l1.tag == 699u || l1.tag == 700u || l1.tag == 701u || l1.tag == 702u || l1.tag == 705u || l1.tag == 706u || l1.tag == 707u || l1.tag == 708u)) {
        l4 = (uint8_t) 8;
    } else if (l1.tag == 586u) {
        l4 = (uint8_t) 16;
    } else if (l1.tag == 671u) {
        l4 = (uint8_t) 32;
    } else if ((l1.tag == 587u || l1.tag == 588u)) {
        t0 = l1.payload.obj;
        l4 = vader_vm_integer_tags(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind);
    } else if ((l1.tag == 540u || l1.tag == 544u || l1.tag == 546u || l1.tag == 578u || l1.tag == 579u || l1.tag == 590u || l1.tag == 613u || l1.tag == 614u || l1.tag == 669u || l1.tag == 689u || l1.tag == 692u || l1.tag == 694u || l1.tag == 697u)) {
        l4 = (uint8_t) 64;
    } else if (l1.tag == 665u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        t2 = ((int64_t) (int32_t) t1);
        l5 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t3 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 249u);
        l4 = ((uint8_t) t3.payload.i);
    } else if ((l1.tag == 667u || l1.tag == 676u)) {
        l4 = l3;
    } else if (l1.tag == 673u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        l7 = vader_vm_tags_of_type(l0, l6);
        t1 = (l3 & l7);
        l4 = (uint8_t) (int32_t) t1;
    } else if (l1.tag == 589u) {
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_target;
        if (l7 == INT32_C(0)) {
            l4 = (uint8_t) 1;
        } else if (l7 == INT32_C(1)) {
            l4 = (uint8_t) 2;
        } else if (l7 == INT32_C(2)) {
            l4 = (uint8_t) 4;
        } else {
            if (!(l7 == INT32_C(3))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l4 = (uint8_t) 16;
        }
    } else if (l1.tag == 693u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_field_index;
        l4 = vader_vm_field_tags(l0, l6, l8);
    } else if (l1.tag == 664u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
        l4 = vader_vm_field_tags(l0, l6, l8);
    } else if (l1.tag == 538u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        l4 = vader_vm_element_tags(l0, l6);
    } else if (l1.tag == 543u) {
        l4 = (uint8_t) 127;
    } else if (l1.tag == 661u) {
        t1 = (INT32_C(1) | INT32_C(16));
        l4 = (uint8_t) (int32_t) t1;
    } else if (l1.tag == 662u) {
        t1 = (INT32_C(2) | INT32_C(1));
        l4 = (uint8_t) (int32_t) t1;
    } else if (l1.tag == 585u) {
        l9 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_module;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        l10 = vader_vm_fn_type_of(l9, l6);
        if (l10.tag == 0u) {
            l4 = (uint8_t) 127;
        } else {
            t0 = l10.payload.obj;
            l6 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_return_type;
            l4 = vader_vm_tags_of_type(l0, l6);
        }
    } else {
        if (!((l1.tag == 536u || l1.tag == 537u || l1.tag == 541u || l1.tag == 542u || l1.tag == 545u || l1.tag == 569u || l1.tag == 576u || l1.tag == 577u || l1.tag == 580u || l1.tag == 583u || l1.tag == 584u || l1.tag == 592u || l1.tag == 593u || l1.tag == 594u || l1.tag == 595u || l1.tag == 598u || l1.tag == 655u || l1.tag == 666u || l1.tag == 668u || l1.tag == 670u || l1.tag == 677u || l1.tag == 678u || l1.tag == 681u || l1.tag == 682u || l1.tag == 683u || l1.tag == 684u || l1.tag == 685u || l1.tag == 686u || l1.tag == 687u || l1.tag == 695u || l1.tag == 710u || l1.tag == 711u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (uint8_t) 0;
    }
    return l4;
}

static vader_box_t vader_vm_read_array(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1098u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(49) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 365u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_read_back_mirror(void* l0, size_t l1, void* l2, void* l3, void* l4, int32_t l5) {
    void* l6 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l24 = NULL;
    size_t l7, l8, l11, l12, l20, l21, l22;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l17 = vader_box_null(), l25 = vader_box_null();
    int32_t l15;
    int64_t l16, l23;
    bool l19;
    void* t0 = NULL;
    int64_t t1, t4;
    uint8_t t2;
    bool t3;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l9, &l10, &l17, &l25, &t5 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l4, &l6, &l13, &l14, &l18, &l24, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l5 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_bytecode_c_struct_layout(l3, l4);
    l7 = (size_t) 0;
    l8 = ((vader_array_t*) l3)->length;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = vader_bytecode_nested_mirror(t0, l4);
        if (l9.tag == 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l17 = vader_bytecode_c_field_width(t0, l4);
            if (l17.tag == 0u) {
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                continue;
            }
            l16 = ((int64_t) l17.payload.i);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            l18 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            t2 = vader_vm_field_val_type(l4, l18);
            t3 = vader_bytecode_is_unsigned_val(t2);
            l19 = !(t3);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            t4 = t1;
            l20 = (size_t) (int64_t) t4;
            t1 = vader_chk_add(usize, l1, l20);
            l21 = (size_t) (int64_t) t1;
            t1 = l16;
            l22 = (size_t) (int64_t) t1;
            l23 = vader_vm_read_little_endian(l0, l21, l22, l19);
            l24 = ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields;
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            t5 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
            l25 = vader_vm_retyped_int(t5, l23);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l24);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l7] = l25;
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l10 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l7];
        if (l10.tag == 1123u) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
            t1 = ((int64_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
            t4 = t1;
            l11 = (size_t) (int64_t) t4;
            t1 = vader_chk_add(usize, l1, l11);
            l12 = (size_t) (int64_t) t1;
            l13 = l10.payload.obj;
            t0 = l9.payload.obj;
            l14 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
            l15 = vader_chk_add(i32, l5, INT32_C(1));
            vader_vm_read_back_mirror(l0, l12, l13, l14, l4, l15);
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_read_bool(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t4 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 241u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(48) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 366u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l0.payload.b;
    t4 = vader_box_bool(241u, t3);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_f64(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    double t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t4 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!((l0.tag == 239u || l0.tag == 240u))) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 367u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((double) l0.payload.f);
    t4 = vader_box_f64(240u, t3);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_fn(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1103u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(46) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 368u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_i32(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    size_t l6, l7;
    void* l8 = NULL;
    int64_t l9;
    int32_t t0;
    uint32_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[2] = { &l8, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l4, &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 246u) {
        t0 = ((int32_t) l0.payload.i);
        l3 = vader_box_i32(246u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 242u) {
        t1 = ((uint32_t) l0.payload.i);
        l3 = vader_box_i32(246u, ((int32_t) (uint32_t) t1));
    } else if (l0.tag == 247u) {
        t2 = ((int64_t) l0.payload.i);
        l3 = vader_box_i32(246u, ((int32_t) (int64_t) t2));
    } else {
        l4 = l2;
        l5 = vader_vm_describe_value_tag(l0);
        l6 = vader_host_std_core_byte_len(l4);
        l7 = vader_host_std_core_byte_len(l5);
        t2 = (l6 + l7);
        l6 = (size_t) (int64_t) t2;
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l6));
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l8, l6, l4);
        l6 = std_core_write_string_at(l8, l6, 56u);
        l9 = ((int64_t) (int32_t) l1);
        l6 = std_core_write_int(l8, l6, l9);
        l6 = std_core_write_string_at(l8, l6, 369u);
        l6 = std_core_write_string_at(l8, l6, l5);
        t3 = std_core_finish_buffer(l8, l6);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t3;
        t4 = (void*) _a0_obj;
        l3 = vader_ref_box(t4);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_i64(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    size_t l6, l7;
    void* l8 = NULL;
    int64_t l9;
    int64_t t0;
    int32_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[2] = { &l8, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 247u) {
        t0 = ((int64_t) l0.payload.i);
        l3 = vader_box_i64(247u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 246u) {
        t1 = ((int32_t) l0.payload.i);
        l3 = vader_box_i64(247u, ((int64_t) (int32_t) t1));
    } else {
        l4 = l2;
        l5 = vader_vm_describe_value_tag(l0);
        l6 = vader_host_std_core_byte_len(l4);
        l7 = vader_host_std_core_byte_len(l5);
        t0 = (l6 + l7);
        l6 = (size_t) (int64_t) t0;
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l6));
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l8, l6, l4);
        l6 = std_core_write_string_at(l8, l6, 56u);
        l9 = ((int64_t) (int32_t) l1);
        l6 = std_core_write_int(l8, l6, l9);
        l6 = std_core_write_string_at(l8, l6, 370u);
        l6 = std_core_write_string_at(l8, l6, l5);
        t2 = std_core_finish_buffer(l8, l6);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t2;
        t3 = (void*) _a0_obj;
        l3 = vader_ref_box(t3);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_vm_read_le(void* l0, size_t l1, size_t l2) {
    uint64_t l3, l5, l7;
    size_t l4, l6;
    int64_t t0, t1;
    vader_box_t t2;
    uint8_t t3;
    l3 = (uint64_t) 0;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        t0 = (l3 << INT64_C(8));
        l5 = (uint64_t) (int64_t) t0;
        t0 = vader_chk_add(usize, l1, l2);
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        t0 = vader_chk_sub(usize, t1, l4);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 249u);
        t3 = ((uint8_t) t2.payload.i);
        t0 = ((int64_t) (uint8_t) t3);
        l7 = (uint64_t) (int64_t) t0;
        t0 = (l5 | l7);
        l3 = (uint64_t) (int64_t) t0;
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    return l3;
}

static int64_t vader_vm_read_little_endian(void* l0, size_t l1, size_t l2, bool l3) {
    int64_t l4, l7, l8, l9;
    size_t l5, l6;
    int64_t t0, t3;
    vader_box_t t1;
    uint8_t t2;
    l4 = INT64_C(0);
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        t0 = vader_chk_add(usize, l1, l5);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 249u);
        t2 = ((uint8_t) t1.payload.i);
        l7 = ((int64_t) (uint8_t) t2);
        t0 = vader_chk_mul(usize, l5, INT64_C(8));
        l8 = t0;
        l9 = (l7 << l8);
        l4 = (l4 | l9);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    if (l3) {
        if ((l2 < INT64_C(8))) {
            t0 = vader_chk_mul(usize, l2, INT64_C(8));
            t3 = vader_chk_sub(usize, t0, INT64_C(1));
            l7 = t3;
            l7 = (INT64_C(1) << l7);
            if ((l4 & l7) != INT64_C(0)) {
                l7 = (l7 << INT64_C(1));
                l4 = vader_chk_sub(i64, l4, l7);
            }
            return l4;
        }
        return l4;
    }
    return l4;
}

static vader_box_t vader_vm_read_numeric_as_f64(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    int64_t l6;
    int32_t t0;
    int64_t t1;
    double t2;
    uint32_t t3;
    vader_string_t t4 = 0;
    void* t5 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l5, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 246u) {
        t0 = ((int32_t) l0.payload.i);
        l2 = vader_box_f64(240u, ((double) (int32_t) t0));
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 247u) {
        t1 = ((int64_t) l0.payload.i);
        l2 = vader_box_f64(240u, ((double) (int64_t) t1));
    } else if ((l0.tag == 239u || l0.tag == 240u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_f64(240u, t2);
    } else if (l0.tag == 242u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_f64(240u, ((double) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else {
        l3 = vader_vm_describe_value_tag(l0);
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(55) + l4));
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l5, l4, 1506u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 363u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 53u);
        t4 = std_core_finish_buffer(l5, l4);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t4;
        t5 = (void*) _a0_obj;
        l2 = vader_ref_box(t5);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_numeric_as_i64(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    int64_t l6;
    int64_t t0;
    int32_t t1;
    double t2;
    uint32_t t3;
    bool t4;
    vader_string_t t5 = 0;
    void* t6 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l5, &t6 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 247u) {
        t0 = ((int64_t) l0.payload.i);
        l2 = vader_box_i64(247u, t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 246u) {
        t1 = ((int32_t) l0.payload.i);
        l2 = vader_box_i64(247u, ((int64_t) (int32_t) t1));
    } else if ((l0.tag == 239u || l0.tag == 240u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_i64(247u, ((int64_t) (double) t2));
    } else if (l0.tag == 242u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_i64(247u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else if (l0.tag == 241u) {
        t4 = l0.payload.b;
        if (t4) {
            l2 = vader_box_i64(247u, INT64_C(1));
        } else {
            l2 = vader_box_i64(247u, INT64_C(0));
        }
    } else {
        l3 = vader_vm_describe_value_tag(l0);
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(59) + l4));
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l5, l4, 1506u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 363u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 54u);
        t5 = std_core_finish_buffer(l5, l4);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t5;
        t6 = (void*) _a0_obj;
        l2 = vader_ref_box(t6);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_obj(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1111u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 372u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_scalar_word(vader_box_t l0, int32_t l1, vader_string_t l2) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    uint32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 241u) {
        t0 = l0.payload.b;
        if (t0) {
            { vader_box_t __vret = vader_box_i64(247u, INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i64(247u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 242u)) {
        t1 = vader_vm_read_i64(l0, l1, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((uint32_t) l0.payload.i);
    t1 = vader_box_i64(247u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t2)));
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_string(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 243u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 373u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.s;
    t3 = vader_box_string(243u, t1);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_struct(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l6;
    void* l7 = NULL;
    int64_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1123u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        t0 = (l5 + l6);
        l5 = (size_t) (int64_t) t0;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l5));
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 56u);
        l8 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l8);
        l5 = std_core_write_string_at(l7, l5, 374u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t1 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_struct_field(vader_box_t l0, int32_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    bool l6;
    size_t l7, l8;
    void* l9 = NULL;
    int64_t l10;
    uint64_t l11;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    size_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l4, &t0 };
    void** gc_raw_roots[2] = { &l9, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1123u)) {
        l4 = l0;
        l5 = concat_2(l3, 124u);
        t0 = vader_vm_read_struct(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1 < INT32_C(0))) {
        l6 = true;
    } else {
        t1 = ((int64_t) (int32_t) l1);
        l7 = (size_t) (int64_t) t1;
        t2 = l0.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t2)->f_fields)->length;
        l6 = (l7 >= l8);
    }
    if (!(l6)) {
        t2 = l0.payload.obj;
        l9 = ((vader_struct_vader_vm_StructVal_t*) t2)->f_fields;
        t1 = ((int64_t) (int32_t) l1);
        l8 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l7 = vader_host_std_core_byte_len(l5);
    l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(108) + l7));
    l7 = (size_t) 0;
    l7 = std_core_write_string_at(l9, l7, l5);
    l7 = std_core_write_string_at(l9, l7, 69u);
    l10 = ((int64_t) (int32_t) l1);
    l7 = std_core_write_int(l9, l7, l10);
    l7 = std_core_write_string_at(l9, l7, 113u);
    t2 = l0.payload.obj;
    t3 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t2)->f_fields)->length;
    t1 = ((int64_t) (size_t) t3);
    l11 = (uint64_t) (int64_t) t1;
    l7 = std_core_write_unsigned(l9, l7, l11);
    l7 = std_core_write_string_at(l9, l7, 70u);
    l10 = ((int64_t) (int32_t) l2);
    l7 = std_core_write_int(l9, l7, l10);
    t4 = std_core_finish_buffer(l9, l7);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t4;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_receiver_trap(void* l0, size_t l1, void* l2, size_t l3, vader_string_t l4) {
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    size_t l7, l8;
    void* l9 = NULL;
    int64_t l10;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    int32_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l9, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l5, &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_vm_register_value(l0, l1);
    l6 = vader_vm_describe_value_tag(t0);
    l5 = l4;
    l7 = vader_host_std_core_byte_len(l5);
    l8 = vader_host_std_core_byte_len(l6);
    t1 = (l7 + l8);
    l7 = (size_t) (int64_t) t1;
    l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(58) + l7));
    l7 = (size_t) 0;
    l7 = std_core_write_string_at(l9, l7, l5);
    l7 = std_core_write_string_at(l9, l7, 125u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l10 = ((int64_t) (int32_t) t2);
    l7 = std_core_write_int(l9, l7, l10);
    l7 = std_core_write_string_at(l9, l7, 365u);
    l7 = std_core_write_string_at(l9, l7, l6);
    t3 = std_core_finish_buffer(l9, l7);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1126u);
    _a1_obj->f_message = t3;
    t4 = (void*) _a1_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_receiver_type_id_of(void* l0, vader_box_t l1) {
    int32_t l2;
    vader_box_t l3;
    void* t0;
    if (l1.tag == 1123u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
        return l2;
    }
    if (l1.tag == 1098u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_type_id;
    } else {
        l3 = l1;
        l2 = vader_vm_primitive_type_id(l0, l3);
    }
    return l2;
}

static void* vader_vm_reduce_data_pool(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    void* l23 = NULL;
    size_t l4, l5, l9, l10, l13, l14, l18, l19, l22;
    vader_box_t l6 = vader_box_null(), l16 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l11 = 0;
    uint64_t l15;
    int32_t l21;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[4] = { &l6, &l16, &l20, &t1 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l7, &l8, &l12, &l17, &l23, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(166u, 0u, 13u, 1098u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_array_t* _a3_arr = vader_array_new(205u, 0u, 0u, 1642u);
        l7 = (void*) _a3_arr;
        if (l6.tag == 560u) {
            t0 = l6.payload.obj;
            l8 = ((vader_struct_vader_bytecode_BcStrData_t*) t0)->f_values;
            l9 = ((vader_array_t*) l8)->length;
            l10 = (size_t) 0;
            while ((l10 < l9)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l10];
                l11 = t1.payload.s;
                t1 = vader_box_string(243u, l11);
                vader_array_push((vader_array_t*) l7, t1);
                t2 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t2;
            }
        } else if (l6.tag == 556u) {
            t0 = l6.payload.obj;
            l12 = ((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_items;
            l13 = ((vader_array_t*) l12)->length;
            l14 = (size_t) 0;
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                t2 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                l15 = (uint64_t) (int64_t) t2;
                t0 = l6.payload.obj;
                l16 = vader_vm_value_from_bits(((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_kind, l15);
                vader_array_push((vader_array_t*) l7, l16);
                t2 = (l14 + INT64_C(1));
                l14 = (size_t) (int64_t) t2;
            }
        } else if (l6.tag == 547u) {
            t0 = l6.payload.obj;
            l17 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_elements;
            l18 = ((vader_array_t*) l17)->length;
            l19 = (size_t) 0;
            while ((l19 < l18)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l19)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l19);
                l20 = vader_vm_bc_value_to_vm(t1, l1);
                vader_array_push((vader_array_t*) l7, l20);
                t2 = (l19 + INT64_C(1));
                l19 = (size_t) (int64_t) t2;
            }
        }
        t3 = vader_bytecode_data_entry_mutable(l6);
        if (t3) {
            l21 = INT32_C(-1);
        } else {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            l21 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
        }
        l22 = ((vader_array_t*) l7)->length;
        vader_struct_vader_vm_ArrayVal_t* _a8_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
        vader_obj_header_init(_a8_obj, 1098u);
        _a8_obj->f_type_id = l21;
        _a8_obj->f_elements = l7;
        _a8_obj->f_offset = (size_t) 0;
        _a8_obj->f_length = l22;
        _a8_obj->f_raw = vader_box_obj(0u, NULL);
        l23 = (void*) _a8_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l23));
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_reduce_main_index(void* l0) {
    size_t l1, l2;
    void* t0;
    bool t1;
    int64_t t2;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        t1 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_is_main;
        if (t1) {
            return ((int32_t) (size_t) l1);
        }
        t2 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t2;
    }
    return INT32_C(0);
}

static bool vader_vm_ref_type_matches(void* l0, vader_box_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    int32_t l4;
    bool l5;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_types_core_trait_key(485u);
    if (l2 == l3) {
        if (l1.tag == 1102u) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        if (l1.tag == 1123u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
            t1 = vader_vm_trait_implemented_by(l0, l2, l4);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l2 == 0u) {
        if (l1.tag == 1123u) {
            l5 = true;
            { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1.tag == 1098u) {
            l5 = true;
        } else if (l1.tag == 1103u) {
            l5 = true;
        } else {
            l5 = false;
        }
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1123u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
        t1 = vader_vm_trait_implemented_by(l0, l2, l4);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_vm_reg_call(void* l0, void* l1, void* l2, int32_t l3, size_t l4, size_t l5, size_t l6, bool l7) {
    void* l8 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l54 = NULL;
    void* l62 = NULL;
    void* l113 = NULL;
    void* l123 = NULL;
    void* l211 = NULL;
    void* l219 = NULL;
    void* l270 = NULL;
    void* l280 = NULL;
    void* l561 = NULL;
    void* l568 = NULL;
    void* l575 = NULL;
    void* l578 = NULL;
    void* l591 = NULL;
    void* l616 = NULL;
    void* l622 = NULL;
    void* l625 = NULL;
    void* l650 = NULL;
    void* l674 = NULL;
    void* l684 = NULL;
    void* l686 = NULL;
    void* l706 = NULL;
    void* l719 = NULL;
    void* l721 = NULL;
    size_t l9, l12, l13, l21, l22, l23, l24, l28, l29, l30, l31, l55, l63, l114, l124, l212, l220, l271, l281, l499, l500, l557, l558, l562, l563, l564, l566, l567, l569, l570, l571, l572, l576, l577, l579, l581, l582, l587, l588, l589, l590, l592, l614, l615, l620, l621, l626, l627, l629, l630, l631, l635, l636, l638, l639, l641, l645, l647, l648, l651, l652, l653, l654, l656, l658, l663, l664, l665, l671, l672, l675, l676, l677, l679, l681, l685, l687, l688, l689, l690, l691, l692, l693, l694, l695, l696, l697, l698, l699, l700, l701, l703, l705, l707, l708, l712, l713, l714, l715, l716, l717, l718, l720, l722;
    int64_t l10, l11, l20, l25, l32, l56, l64, l115, l125, l193, l195, l196, l199, l201, l202, l205, l207, l208, l210, l213, l216, l218, l221, l224, l227, l229, l230, l233, l235, l236, l239, l241, l242, l245, l247, l248, l251, l253, l254, l260, l263, l264, l267, l269, l272, l277, l279, l282, l287, l290, l292, l296, l298, l302, l304, l308, l310, l314, l316, l320, l322, l434, l438, l442, l446, l448, l452, l455, l458, l461, l463, l466, l469, l472, l476, l480, l484, l488, l490, l498, l501, l503, l523, l525, l527, l529, l531, l533, l535, l537, l554, l655, l678, l702;
    int32_t l19, l34, l35, l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l57, l58, l59, l60, l61, l65, l66, l67, l68, l69, l70, l71, l72, l73, l74, l75, l76, l77, l78, l79, l80, l81, l82, l83, l84, l85, l86, l87, l88, l89, l90, l91, l92, l93, l94, l95, l96, l97, l98, l100, l101, l103, l104, l105, l106, l107, l108, l109, l110, l111, l112, l116, l117, l120, l121, l122, l126, l127, l130, l131, l132, l133, l134, l135, l137, l138, l139, l140, l141, l143, l144, l145, l146, l147, l149, l150, l151, l152, l153, l155, l156, l157, l158, l159, l161, l162, l163, l164, l165, l167, l168, l170, l173, l174, l176, l179, l180, l182, l185, l186, l188, l191, l192, l194, l197, l198, l200, l203, l204, l206, l209, l214, l215, l217, l222, l223, l225, l226, l228, l231, l232, l234, l237, l238, l240, l243, l244, l246, l249, l250, l252, l255, l256, l258, l261, l262, l265, l266, l268, l273, l274, l278, l283, l284, l288, l289, l291, l294, l295, l297, l300, l301, l303, l306, l307, l309, l312, l313, l315, l318, l319, l321, l324, l325, l327, l330, l331, l333, l336, l337, l339, l342, l343, l345, l348, l349, l351, l354, l355, l357, l360, l361, l363, l366, l367, l369, l372, l373, l375, l376, l378, l381, l382, l384, l387, l388, l390, l393, l394, l396, l399, l400, l402, l405, l406, l408, l411, l412, l414, l417, l418, l420, l423, l424, l426, l427, l428, l430, l431, l432, l436, l437, l440, l441, l444, l445, l447, l450, l451, l454, l457, l460, l462, l465, l468, l471, l474, l478, l482, l486, l489, l492, l493, l494, l495, l496, l497, l502, l504, l505, l506, l507, l508, l509, l510, l511, l512, l513, l514, l515, l516, l517, l518, l519, l520, l521, l522, l524, l526, l528, l530, l532, l534, l536, l538, l540, l542, l544, l546, l548, l550, l552, l556, l559, l584, l594, l596, l597, l598, l601, l602, l603, l604, l605, l607, l608, l609, l610, l611, l612, l618, l619, l632, l637, l643, l661, l662, l667, l668, l669, l711;
    uint8_t l26, l33, l475, l479, l483, l487, l657, l680, l704;
    vader_box_t l27 = vader_box_null(), l435 = vader_box_null(), l439 = vader_box_null(), l443 = vader_box_null(), l449 = vader_box_null(), l453 = vader_box_null(), l456 = vader_box_null(), l459 = vader_box_null(), l464 = vader_box_null(), l467 = vader_box_null(), l470 = vader_box_null(), l473 = vader_box_null(), l477 = vader_box_null(), l481 = vader_box_null(), l485 = vader_box_null(), l491 = vader_box_null(), l555 = vader_box_null(), l560 = vader_box_null(), l565 = vader_box_null(), l573 = vader_box_null(), l574 = vader_box_null(), l580 = vader_box_null(), l583 = vader_box_null(), l593 = vader_box_null(), l595 = vader_box_null(), l599 = vader_box_null(), l613 = vader_box_null(), l617 = vader_box_null(), l623 = vader_box_null(), l628 = vader_box_null(), l640 = vader_box_null(), l644 = vader_box_null(), l659 = vader_box_null(), l660 = vader_box_null(), l666 = vader_box_null(), l682 = vader_box_null(), l683 = vader_box_null();
    uint32_t l99, l102, l118, l119, l128, l129, l169, l171, l175, l177, l181, l183, l187, l189, l539, l541, l543, l545;
    bool l136, l142, l148, l154, l160, l166, l172, l178, l184, l190, l293, l299, l305, l311, l317, l323, l329, l335, l341, l347, l380, l386, l392, l398, l404, l410, l413, l415, l416, l419, l421, l422, l425, l429, l433, l585, l586, l600, l606, l624, l633, l634, l642, l646, l649, l670, l673, l709, l710;
    uint64_t l257, l259, l275, l276, l285, l286, l326, l328, l332, l334, l338, l340, l344, l346, l547, l549, l551, l553;
    double l350, l352, l353, l356, l358, l359, l362, l364, l365, l368, l370, l371, l374, l377, l379, l383, l385, l389, l391, l395, l397, l401, l403, l407, l409;
    int64_t t0, t7;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int32_t t3, t5;
    vader_box_t t4 = vader_box_null();
    uint32_t t6;
    uint64_t t8;
    double t9;
    size_t t10;
    bool t11;
    vader_box_t* gc_roots[38] = {
        &l27, &l435, &l439, &l443, &l449, &l453, &l456, &l459, &l464, &l467, &l470, &l473, &l477,
        &l481, &l485, &l491, &l555, &l560, &l565, &l573, &l574, &l580, &l583, &l593, &l595, &l599,
        &l613, &l617, &l623, &l628, &l640, &l644, &l659, &l660, &l666, &l682, &l683, &t4,
    };
    void** gc_raw_roots[33] = {
        &l0, &l1, &l2, &l8, &l14, &l15, &l16, &l17, &l18, &l54, &l62, &l113, &l123, &l211, &l219,
        &l270, &l280, &l561, &l568, &l575, &l578, &l591, &l616, &l622, &l625, &l650, &l674, &l684,
        &l686, &l706, &l719, &l721, &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 38u, 33u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l8 = ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions;
    t0 = ((int64_t) (int32_t) l3);
    l9 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
    l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
    t0 = ((int64_t) 1024);
    l9 = (size_t) (int64_t) t0;
    if ((l5 >= l9)) {
        t1 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_name;
        t2 = vader_vm_overflow_trap(t1);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_vm_enter_frame(l2, l8, l4);
    l9 = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code)->length;
    if ((l5 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5, l8);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_base);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5] = (int64_t) (int64_t) (size_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_return);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (int64_t) (int64_t) (size_t) l6;
    } else {
        vader_vm_grow_frame_records(l2, l8, l4, l6);
    }
    if (l7) {
        l10 = INT64_C(100000000);
    } else {
        l10 = INT64_C(4611686018427387904);
    }
    l11 = INT64_C(0);
    t0 = vader_chk_add(usize, l5, INT64_C(1));
    l9 = (size_t) (int64_t) t0;
    l12 = l4;
    l13 = (size_t) 0;
    l14 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_ops;
    l15 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_words;
    l16 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_bits;
    l17 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_tags;
    l18 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_refs;
    for (;;) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
        l19 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l13];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
        l20 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l13];
        if (l19 == INT32_C(0)) {
            t3 = vader_vm_operand_a(l20);
            t0 = ((int64_t) (int32_t) t3);
            l21 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l12, l21);
            l22 = (size_t) (int64_t) t0;
            t3 = vader_vm_operand_b(l20);
            t0 = ((int64_t) (int32_t) t3);
            l23 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l12, l23);
            l24 = (size_t) (int64_t) t0;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l24)
            l25 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l24];
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l22)
            ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l22] = (int64_t) l25;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l24)
            t4 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l24, 249u);
            l26 = ((uint8_t) t4.payload.i);
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l22)
            ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l22] = (uint8_t) (int32_t) (uint8_t) l26;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l24)
            l27 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l24];
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l22)
            vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l22] = l27;
            VADER_WRITE_BARRIER(_a8_slotarr->buf);
        } else if (l19 == INT32_C(1)) {
            t3 = vader_vm_operand_a(l20);
            t0 = ((int64_t) (int32_t) t3);
            l28 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l12, l28);
            l29 = (size_t) (int64_t) t0;
            t3 = vader_vm_operand_b(l20);
            t0 = ((int64_t) (int32_t) t3);
            l30 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l12, l30);
            l31 = (size_t) (int64_t) t0;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l31)
            l32 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l31];
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l29)
            ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l29] = (int64_t) l32;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l31)
            t4 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l31, 249u);
            l33 = ((uint8_t) t4.payload.i);
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l29)
            ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l29] = (uint8_t) (int32_t) (uint8_t) l33;
        } else if (l19 == INT32_C(2)) {
            l34 = vader_vm_operand_a(l20);
            l35 = vader_vm_operand_b(l20);
            l36 = vader_vm_i32_of(l16, l12, l35);
            l37 = vader_vm_operand_c(l20);
            l38 = vader_vm_i32_of(l16, l12, l37);
            l39 = (l36 + l38);
            vader_vm_set_i32(l16, l17, l12, l34, l39);
        } else if (l19 == INT32_C(3)) {
            l40 = vader_vm_operand_a(l20);
            l41 = vader_vm_operand_b(l20);
            l42 = vader_vm_i32_of(l16, l12, l41);
            l43 = vader_vm_operand_c(l20);
            l44 = vader_vm_i32_of(l16, l12, l43);
            l45 = (l42 - l44);
            vader_vm_set_i32(l16, l17, l12, l40, l45);
        } else if (l19 == INT32_C(4)) {
            l46 = vader_vm_operand_a(l20);
            l47 = vader_vm_operand_b(l20);
            l48 = vader_vm_i32_of(l16, l12, l47);
            l49 = vader_vm_operand_c(l20);
            l50 = vader_vm_i32_of(l16, l12, l49);
            l51 = (l48 * l50);
            vader_vm_set_i32(l16, l17, l12, l46, l51);
        } else if (l19 == INT32_C(5)) {
            l52 = vader_vm_operand_c(l20);
            l53 = vader_vm_i32_of(l16, l12, l52);
            if (l53 == INT32_C(0)) {
                l54 = std_core_new_byte_buffer((size_t) 42);
                l55 = (size_t) 0;
                l55 = std_core_write_string_at(l54, l55, 1768u);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
                t3 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l13];
                l56 = ((int64_t) (int32_t) t3);
                l55 = std_core_write_int(l54, l55, l56);
                t1 = std_core_finish_buffer(l54, l55);
                vader_struct_vader_vm_Trap_t* _a12_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a12_obj, 1126u);
                _a12_obj->f_message = t1;
                t2 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l57 = vader_vm_operand_a(l20);
            l58 = vader_vm_operand_b(l20);
            t3 = vader_vm_i32_of(l16, l12, l58);
            l59 = vader_div_i32(t3, l53);
            vader_vm_set_i32(l16, l17, l12, l57, l59);
        } else if (l19 == INT32_C(6)) {
            l60 = vader_vm_operand_c(l20);
            l61 = vader_vm_i32_of(l16, l12, l60);
            if (l61 == INT32_C(0)) {
                l62 = std_core_new_byte_buffer((size_t) 42);
                l63 = (size_t) 0;
                l63 = std_core_write_string_at(l62, l63, 1774u);
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
                t3 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l13];
                l64 = ((int64_t) (int32_t) t3);
                l63 = std_core_write_int(l62, l63, l64);
                t1 = std_core_finish_buffer(l62, l63);
                vader_struct_vader_vm_Trap_t* _a14_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a14_obj, 1126u);
                _a14_obj->f_message = t1;
                t2 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l65 = vader_vm_operand_a(l20);
            l66 = vader_vm_operand_b(l20);
            t3 = vader_vm_i32_of(l16, l12, l66);
            l67 = vader_mod_i32(t3, l61);
            vader_vm_set_i32(l16, l17, l12, l65, l67);
        } else if (l19 == INT32_C(7)) {
            l68 = vader_vm_operand_a(l20);
            l69 = vader_vm_operand_b(l20);
            l70 = vader_vm_i32_of(l16, l12, l69);
            l71 = vader_vm_operand_c(l20);
            l72 = vader_vm_i32_of(l16, l12, l71);
            l73 = (l70 & l72);
            vader_vm_set_i32(l16, l17, l12, l68, l73);
        } else if (l19 == INT32_C(8)) {
            l74 = vader_vm_operand_a(l20);
            l75 = vader_vm_operand_b(l20);
            l76 = vader_vm_i32_of(l16, l12, l75);
            l77 = vader_vm_operand_c(l20);
            l78 = vader_vm_i32_of(l16, l12, l77);
            l79 = (l76 | l78);
            vader_vm_set_i32(l16, l17, l12, l74, l79);
        } else if (l19 == INT32_C(9)) {
            l80 = vader_vm_operand_a(l20);
            l81 = vader_vm_operand_b(l20);
            l82 = vader_vm_i32_of(l16, l12, l81);
            l83 = vader_vm_operand_c(l20);
            l84 = vader_vm_i32_of(l16, l12, l83);
            l85 = (l82 ^ l84);
            vader_vm_set_i32(l16, l17, l12, l80, l85);
        } else if (l19 == INT32_C(10)) {
            l86 = vader_vm_operand_a(l20);
            l87 = vader_vm_operand_b(l20);
            l88 = vader_vm_i32_of(l16, l12, l87);
            l89 = vader_vm_operand_c(l20);
            l90 = vader_vm_i32_of(l16, l12, l89);
            l91 = (l88 << l90);
            vader_vm_set_i32(l16, l17, l12, l86, l91);
        } else if (l19 == INT32_C(11)) {
            l92 = vader_vm_operand_a(l20);
            l93 = vader_vm_operand_b(l20);
            l94 = vader_vm_i32_of(l16, l12, l93);
            l95 = vader_vm_operand_c(l20);
            l96 = vader_vm_i32_of(l16, l12, l95);
            l97 = (l94 >> l96);
            vader_vm_set_i32(l16, l17, l12, l92, l97);
        } else if (l19 == INT32_C(12)) {
            l98 = vader_vm_operand_b(l20);
            t3 = vader_vm_i32_of(l16, l12, l98);
            t5 = t3;
            l99 = (uint32_t) (int32_t) t5;
            l100 = vader_vm_operand_a(l20);
            l101 = vader_vm_operand_c(l20);
            t3 = vader_vm_i32_of(l16, l12, l101);
            t5 = t3;
            l102 = (uint32_t) (int32_t) t5;
            l103 = ((int32_t) (uint32_t) (l99 >> l102));
            vader_vm_set_i32(l16, l17, l12, l100, l103);
        } else if (l19 == INT32_C(13)) {
            l104 = vader_vm_operand_a(l20);
            l105 = vader_vm_operand_b(l20);
            l106 = vader_vm_i32_of(l16, l12, l105);
            l107 = (INT32_C(0) - l106);
            vader_vm_set_i32(l16, l17, l12, l104, l107);
        } else if (l19 == INT32_C(14)) {
            l108 = vader_vm_operand_a(l20);
            l109 = vader_vm_operand_b(l20);
            t3 = vader_vm_i32_of(l16, l12, l109);
            l110 = ~(t3);
            vader_vm_set_i32(l16, l17, l12, l108, l110);
        } else if (l19 == INT32_C(15)) {
            l111 = vader_vm_operand_c(l20);
            l112 = vader_vm_i32_of(l16, l12, l111);
            if (l112 == INT32_C(0)) {
                l113 = std_core_new_byte_buffer((size_t) 42);
                l114 = (size_t) 0;
                l114 = std_core_write_string_at(l113, l114, 2416u);
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
                t3 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l13];
                l115 = ((int64_t) (int32_t) t3);
                l114 = std_core_write_int(l113, l114, l115);
                t1 = std_core_finish_buffer(l113, l114);
                vader_struct_vader_vm_Trap_t* _a16_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a16_obj, 1126u);
                _a16_obj->f_message = t1;
                t2 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l116 = vader_vm_operand_a(l20);
            l117 = vader_vm_operand_b(l20);
            t3 = vader_vm_i32_of(l16, l12, l117);
            t5 = t3;
            l118 = (uint32_t) (int32_t) t5;
            t3 = l112;
            l119 = (uint32_t) (int32_t) t3;
            t6 = vader_div_u32(l118, l119);
            l120 = ((int32_t) (uint32_t) t6);
            vader_vm_set_i32(l16, l17, l12, l116, l120);
        } else if (l19 == INT32_C(16)) {
            l121 = vader_vm_operand_c(l20);
            l122 = vader_vm_i32_of(l16, l12, l121);
            if (l122 == INT32_C(0)) {
                l123 = std_core_new_byte_buffer((size_t) 42);
                l124 = (size_t) 0;
                l124 = std_core_write_string_at(l123, l124, 2422u);
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
                t3 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l13];
                l125 = ((int64_t) (int32_t) t3);
                l124 = std_core_write_int(l123, l124, l125);
                t1 = std_core_finish_buffer(l123, l124);
                vader_struct_vader_vm_Trap_t* _a18_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a18_obj, 1126u);
                _a18_obj->f_message = t1;
                t2 = (void*) _a18_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l126 = vader_vm_operand_a(l20);
            l127 = vader_vm_operand_b(l20);
            t3 = vader_vm_i32_of(l16, l12, l127);
            t5 = t3;
            l128 = (uint32_t) (int32_t) t5;
            t3 = l122;
            l129 = (uint32_t) (int32_t) t3;
            t6 = vader_mod_u32(l128, l129);
            l130 = ((int32_t) (uint32_t) t6);
            vader_vm_set_i32(l16, l17, l12, l126, l130);
        } else if (l19 == INT32_C(17)) {
            l131 = vader_vm_operand_a(l20);
            l132 = vader_vm_operand_b(l20);
            l133 = vader_vm_i32_of(l16, l12, l132);
            l134 = vader_vm_operand_c(l20);
            l135 = vader_vm_i32_of(l16, l12, l134);
            l136 = l133 == l135;
            vader_vm_set_bool(l16, l17, l12, l131, l136);
        } else if (l19 == INT32_C(18)) {
            l137 = vader_vm_operand_a(l20);
            l138 = vader_vm_operand_b(l20);
            l139 = vader_vm_i32_of(l16, l12, l138);
            l140 = vader_vm_operand_c(l20);
            l141 = vader_vm_i32_of(l16, l12, l140);
            l142 = l139 != l141;
            vader_vm_set_bool(l16, l17, l12, l137, l142);
        } else if (l19 == INT32_C(19)) {
            l143 = vader_vm_operand_a(l20);
            l144 = vader_vm_operand_b(l20);
            l145 = vader_vm_i32_of(l16, l12, l144);
            l146 = vader_vm_operand_c(l20);
            l147 = vader_vm_i32_of(l16, l12, l146);
            l148 = (l145 < l147);
            vader_vm_set_bool(l16, l17, l12, l143, l148);
        } else if (l19 == INT32_C(20)) {
            l149 = vader_vm_operand_a(l20);
            l150 = vader_vm_operand_b(l20);
            l151 = vader_vm_i32_of(l16, l12, l150);
            l152 = vader_vm_operand_c(l20);
            l153 = vader_vm_i32_of(l16, l12, l152);
            l154 = (l151 <= l153);
            vader_vm_set_bool(l16, l17, l12, l149, l154);
        } else if (l19 == INT32_C(21)) {
            l155 = vader_vm_operand_a(l20);
            l156 = vader_vm_operand_b(l20);
            l157 = vader_vm_i32_of(l16, l12, l156);
            l158 = vader_vm_operand_c(l20);
            l159 = vader_vm_i32_of(l16, l12, l158);
            l160 = (l157 > l159);
            vader_vm_set_bool(l16, l17, l12, l155, l160);
        } else if (l19 == INT32_C(22)) {
            l161 = vader_vm_operand_a(l20);
            l162 = vader_vm_operand_b(l20);
            l163 = vader_vm_i32_of(l16, l12, l162);
            l164 = vader_vm_operand_c(l20);
            l165 = vader_vm_i32_of(l16, l12, l164);
            l166 = (l163 >= l165);
            vader_vm_set_bool(l16, l17, l12, l161, l166);
        } else if (l19 == INT32_C(23)) {
            l167 = vader_vm_operand_a(l20);
            l168 = vader_vm_operand_b(l20);
            l169 = vader_vm_u32_of(l16, l12, l168);
            l170 = vader_vm_operand_c(l20);
            l171 = vader_vm_u32_of(l16, l12, l170);
            l172 = (l169 < l171);
            vader_vm_set_bool(l16, l17, l12, l167, l172);
        } else if (l19 == INT32_C(24)) {
            l173 = vader_vm_operand_a(l20);
            l174 = vader_vm_operand_b(l20);
            l175 = vader_vm_u32_of(l16, l12, l174);
            l176 = vader_vm_operand_c(l20);
            l177 = vader_vm_u32_of(l16, l12, l176);
            l178 = (l175 <= l177);
            vader_vm_set_bool(l16, l17, l12, l173, l178);
        } else if (l19 == INT32_C(25)) {
            l179 = vader_vm_operand_a(l20);
            l180 = vader_vm_operand_b(l20);
            l181 = vader_vm_u32_of(l16, l12, l180);
            l182 = vader_vm_operand_c(l20);
            l183 = vader_vm_u32_of(l16, l12, l182);
            l184 = (l181 > l183);
            vader_vm_set_bool(l16, l17, l12, l179, l184);
        } else if (l19 == INT32_C(26)) {
            l185 = vader_vm_operand_a(l20);
            l186 = vader_vm_operand_b(l20);
            l187 = vader_vm_u32_of(l16, l12, l186);
            l188 = vader_vm_operand_c(l20);
            l189 = vader_vm_u32_of(l16, l12, l188);
            l190 = (l187 >= l189);
            vader_vm_set_bool(l16, l17, l12, l185, l190);
        } else if (l19 == INT32_C(27)) {
            l191 = vader_vm_operand_a(l20);
            l192 = vader_vm_operand_b(l20);
            l193 = vader_vm_bits_of(l16, l12, l192);
            l194 = vader_vm_operand_c(l20);
            l195 = vader_vm_bits_of(l16, l12, l194);
            l196 = (l193 + l195);
            vader_vm_set_i64(l16, l17, l12, l191, l196);
        } else if (l19 == INT32_C(28)) {
            l197 = vader_vm_operand_a(l20);
            l198 = vader_vm_operand_b(l20);
            l199 = vader_vm_bits_of(l16, l12, l198);
            l200 = vader_vm_operand_c(l20);
            l201 = vader_vm_bits_of(l16, l12, l200);
            l202 = (l199 - l201);
            vader_vm_set_i64(l16, l17, l12, l197, l202);
        } else if (l19 == INT32_C(29)) {
            l203 = vader_vm_operand_a(l20);
            l204 = vader_vm_operand_b(l20);
            l205 = vader_vm_bits_of(l16, l12, l204);
            l206 = vader_vm_operand_c(l20);
            l207 = vader_vm_bits_of(l16, l12, l206);
            l208 = (l205 * l207);
            vader_vm_set_i64(l16, l17, l12, l203, l208);
        } else if (l19 == INT32_C(30)) {
            l209 = vader_vm_operand_c(l20);
            l210 = vader_vm_bits_of(l16, l12, l209);
            if (l210 == INT64_C(0)) {
                l211 = std_core_new_byte_buffer((size_t) 42);
                l212 = (size_t) 0;
                l212 = std_core_write_string_at(l211, l212, 1790u);
                vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l13)
                t3 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l13];
                l213 = ((int64_t) (int32_t) t3);
                l212 = std_core_write_int(l211, l212, l213);
                t1 = std_core_finish_buffer(l211, l212);
                vader_struct_vader_vm_Trap_t* _a20_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a20_obj, 1126u);
                _a20_obj->f_message = t1;
                t2 = (void*) _a20_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l214 = vader_vm_operand_a(l20);
            l215 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l215);
            l216 = vader_div_i64(t0, l210);
            vader_vm_set_i64(l16, l17, l12, l214, l216);
        } else if (l19 == INT32_C(31)) {
            l217 = vader_vm_operand_c(l20);
            l218 = vader_vm_bits_of(l16, l12, l217);
            if (l218 == INT64_C(0)) {
                l219 = std_core_new_byte_buffer((size_t) 42);
                l220 = (size_t) 0;
                l220 = std_core_write_string_at(l219, l220, 1800u);
                vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l13)
                t3 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l13];
                l221 = ((int64_t) (int32_t) t3);
                l220 = std_core_write_int(l219, l220, l221);
                t1 = std_core_finish_buffer(l219, l220);
                vader_struct_vader_vm_Trap_t* _a22_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a22_obj, 1126u);
                _a22_obj->f_message = t1;
                t2 = (void*) _a22_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l222 = vader_vm_operand_a(l20);
            l223 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l223);
            l224 = vader_mod_i64(t0, l218);
            vader_vm_set_i64(l16, l17, l12, l222, l224);
        } else if (l19 == INT32_C(32)) {
            l225 = vader_vm_operand_a(l20);
            l226 = vader_vm_operand_b(l20);
            l227 = vader_vm_bits_of(l16, l12, l226);
            l228 = vader_vm_operand_c(l20);
            l229 = vader_vm_bits_of(l16, l12, l228);
            l230 = (l227 & l229);
            vader_vm_set_i64(l16, l17, l12, l225, l230);
        } else if (l19 == INT32_C(33)) {
            l231 = vader_vm_operand_a(l20);
            l232 = vader_vm_operand_b(l20);
            l233 = vader_vm_bits_of(l16, l12, l232);
            l234 = vader_vm_operand_c(l20);
            l235 = vader_vm_bits_of(l16, l12, l234);
            l236 = (l233 | l235);
            vader_vm_set_i64(l16, l17, l12, l231, l236);
        } else if (l19 == INT32_C(34)) {
            l237 = vader_vm_operand_a(l20);
            l238 = vader_vm_operand_b(l20);
            l239 = vader_vm_bits_of(l16, l12, l238);
            l240 = vader_vm_operand_c(l20);
            l241 = vader_vm_bits_of(l16, l12, l240);
            l242 = (l239 ^ l241);
            vader_vm_set_i64(l16, l17, l12, l237, l242);
        } else if (l19 == INT32_C(35)) {
            l243 = vader_vm_operand_a(l20);
            l244 = vader_vm_operand_b(l20);
            l245 = vader_vm_bits_of(l16, l12, l244);
            l246 = vader_vm_operand_c(l20);
            l247 = vader_vm_bits_of(l16, l12, l246);
            l248 = (l245 << l247);
            vader_vm_set_i64(l16, l17, l12, l243, l248);
        } else if (l19 == INT32_C(36)) {
            l249 = vader_vm_operand_a(l20);
            l250 = vader_vm_operand_b(l20);
            l251 = vader_vm_bits_of(l16, l12, l250);
            l252 = vader_vm_operand_c(l20);
            l253 = vader_vm_bits_of(l16, l12, l252);
            l254 = (l251 >> l253);
            vader_vm_set_i64(l16, l17, l12, l249, l254);
        } else if (l19 == INT32_C(37)) {
            l255 = vader_vm_operand_a(l20);
            l256 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l256);
            t7 = t0;
            l257 = (uint64_t) (int64_t) t7;
            l258 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l258);
            t7 = t0;
            l259 = (uint64_t) (int64_t) t7;
            l260 = ((int64_t) (uint64_t) (l257 >> l259));
            vader_vm_set_i64(l16, l17, l12, l255, l260);
        } else if (l19 == INT32_C(38)) {
            l261 = vader_vm_operand_a(l20);
            l262 = vader_vm_operand_b(l20);
            l263 = vader_vm_bits_of(l16, l12, l262);
            l264 = (INT64_C(0) - l263);
            vader_vm_set_i64(l16, l17, l12, l261, l264);
        } else if (l19 == INT32_C(39)) {
            l265 = vader_vm_operand_a(l20);
            l266 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l266);
            l267 = ~(t0);
            vader_vm_set_i64(l16, l17, l12, l265, l267);
        } else if (l19 == INT32_C(40)) {
            l268 = vader_vm_operand_c(l20);
            l269 = vader_vm_bits_of(l16, l12, l268);
            if (l269 == INT64_C(0)) {
                l270 = std_core_new_byte_buffer((size_t) 42);
                l271 = (size_t) 0;
                l271 = std_core_write_string_at(l270, l271, 2426u);
                vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l13)
                t3 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l13];
                l272 = ((int64_t) (int32_t) t3);
                l271 = std_core_write_int(l270, l271, l272);
                t1 = std_core_finish_buffer(l270, l271);
                vader_struct_vader_vm_Trap_t* _a24_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a24_obj, 1126u);
                _a24_obj->f_message = t1;
                t2 = (void*) _a24_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l273 = vader_vm_operand_a(l20);
            l274 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l274);
            t7 = t0;
            l275 = (uint64_t) (int64_t) t7;
            t0 = l269;
            l276 = (uint64_t) (int64_t) t0;
            t8 = vader_div_u64(l275, l276);
            l277 = ((int64_t) (uint64_t) t8);
            vader_vm_set_i64(l16, l17, l12, l273, l277);
        } else if (l19 == INT32_C(41)) {
            l278 = vader_vm_operand_c(l20);
            l279 = vader_vm_bits_of(l16, l12, l278);
            if (l279 == INT64_C(0)) {
                l280 = std_core_new_byte_buffer((size_t) 42);
                l281 = (size_t) 0;
                l281 = std_core_write_string_at(l280, l281, 2432u);
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l13)
                t3 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l13];
                l282 = ((int64_t) (int32_t) t3);
                l281 = std_core_write_int(l280, l281, l282);
                t1 = std_core_finish_buffer(l280, l281);
                vader_struct_vader_vm_Trap_t* _a26_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a26_obj, 1126u);
                _a26_obj->f_message = t1;
                t2 = (void*) _a26_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l283 = vader_vm_operand_a(l20);
            l284 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l284);
            t7 = t0;
            l285 = (uint64_t) (int64_t) t7;
            t0 = l279;
            l286 = (uint64_t) (int64_t) t0;
            t8 = vader_mod_u64(l285, l286);
            l287 = ((int64_t) (uint64_t) t8);
            vader_vm_set_i64(l16, l17, l12, l283, l287);
        } else if (l19 == INT32_C(42)) {
            l288 = vader_vm_operand_a(l20);
            l289 = vader_vm_operand_b(l20);
            l290 = vader_vm_bits_of(l16, l12, l289);
            l291 = vader_vm_operand_c(l20);
            l292 = vader_vm_bits_of(l16, l12, l291);
            l293 = l290 == l292;
            vader_vm_set_bool(l16, l17, l12, l288, l293);
        } else if (l19 == INT32_C(43)) {
            l294 = vader_vm_operand_a(l20);
            l295 = vader_vm_operand_b(l20);
            l296 = vader_vm_bits_of(l16, l12, l295);
            l297 = vader_vm_operand_c(l20);
            l298 = vader_vm_bits_of(l16, l12, l297);
            l299 = l296 != l298;
            vader_vm_set_bool(l16, l17, l12, l294, l299);
        } else if (l19 == INT32_C(44)) {
            l300 = vader_vm_operand_a(l20);
            l301 = vader_vm_operand_b(l20);
            l302 = vader_vm_bits_of(l16, l12, l301);
            l303 = vader_vm_operand_c(l20);
            l304 = vader_vm_bits_of(l16, l12, l303);
            l305 = (l302 < l304);
            vader_vm_set_bool(l16, l17, l12, l300, l305);
        } else if (l19 == INT32_C(45)) {
            l306 = vader_vm_operand_a(l20);
            l307 = vader_vm_operand_b(l20);
            l308 = vader_vm_bits_of(l16, l12, l307);
            l309 = vader_vm_operand_c(l20);
            l310 = vader_vm_bits_of(l16, l12, l309);
            l311 = (l308 <= l310);
            vader_vm_set_bool(l16, l17, l12, l306, l311);
        } else if (l19 == INT32_C(46)) {
            l312 = vader_vm_operand_a(l20);
            l313 = vader_vm_operand_b(l20);
            l314 = vader_vm_bits_of(l16, l12, l313);
            l315 = vader_vm_operand_c(l20);
            l316 = vader_vm_bits_of(l16, l12, l315);
            l317 = (l314 > l316);
            vader_vm_set_bool(l16, l17, l12, l312, l317);
        } else if (l19 == INT32_C(47)) {
            l318 = vader_vm_operand_a(l20);
            l319 = vader_vm_operand_b(l20);
            l320 = vader_vm_bits_of(l16, l12, l319);
            l321 = vader_vm_operand_c(l20);
            l322 = vader_vm_bits_of(l16, l12, l321);
            l323 = (l320 >= l322);
            vader_vm_set_bool(l16, l17, l12, l318, l323);
        } else if (l19 == INT32_C(48)) {
            l324 = vader_vm_operand_a(l20);
            l325 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l325);
            t7 = t0;
            l326 = (uint64_t) (int64_t) t7;
            l327 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l327);
            t7 = t0;
            l328 = (uint64_t) (int64_t) t7;
            l329 = (l326 < l328);
            vader_vm_set_bool(l16, l17, l12, l324, l329);
        } else if (l19 == INT32_C(49)) {
            l330 = vader_vm_operand_a(l20);
            l331 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l331);
            t7 = t0;
            l332 = (uint64_t) (int64_t) t7;
            l333 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l333);
            t7 = t0;
            l334 = (uint64_t) (int64_t) t7;
            l335 = (l332 <= l334);
            vader_vm_set_bool(l16, l17, l12, l330, l335);
        } else if (l19 == INT32_C(50)) {
            l336 = vader_vm_operand_a(l20);
            l337 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l337);
            t7 = t0;
            l338 = (uint64_t) (int64_t) t7;
            l339 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l339);
            t7 = t0;
            l340 = (uint64_t) (int64_t) t7;
            l341 = (l338 > l340);
            vader_vm_set_bool(l16, l17, l12, l336, l341);
        } else if (l19 == INT32_C(51)) {
            l342 = vader_vm_operand_a(l20);
            l343 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l343);
            t7 = t0;
            l344 = (uint64_t) (int64_t) t7;
            l345 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l345);
            t7 = t0;
            l346 = (uint64_t) (int64_t) t7;
            l347 = (l344 >= l346);
            vader_vm_set_bool(l16, l17, l12, l342, l347);
        } else if (l19 == INT32_C(52)) {
            l348 = vader_vm_operand_a(l20);
            l349 = vader_vm_operand_b(l20);
            l350 = vader_vm_f64_of(l16, l12, l349);
            l351 = vader_vm_operand_c(l20);
            l352 = vader_vm_f64_of(l16, l12, l351);
            l353 = (l350 + l352);
            vader_vm_set_f64(l16, l17, l12, l348, l353);
        } else if (l19 == INT32_C(53)) {
            l354 = vader_vm_operand_a(l20);
            l355 = vader_vm_operand_b(l20);
            l356 = vader_vm_f64_of(l16, l12, l355);
            l357 = vader_vm_operand_c(l20);
            l358 = vader_vm_f64_of(l16, l12, l357);
            l359 = (l356 - l358);
            vader_vm_set_f64(l16, l17, l12, l354, l359);
        } else if (l19 == INT32_C(54)) {
            l360 = vader_vm_operand_a(l20);
            l361 = vader_vm_operand_b(l20);
            l362 = vader_vm_f64_of(l16, l12, l361);
            l363 = vader_vm_operand_c(l20);
            l364 = vader_vm_f64_of(l16, l12, l363);
            l365 = (l362 * l364);
            vader_vm_set_f64(l16, l17, l12, l360, l365);
        } else if (l19 == INT32_C(55)) {
            l366 = vader_vm_operand_a(l20);
            l367 = vader_vm_operand_b(l20);
            l368 = vader_vm_f64_of(l16, l12, l367);
            l369 = vader_vm_operand_c(l20);
            l370 = vader_vm_f64_of(l16, l12, l369);
            l371 = l368 / l370;
            vader_vm_set_f64(l16, l17, l12, l366, l371);
        } else if (l19 == INT32_C(56)) {
            l372 = vader_vm_operand_a(l20);
            l373 = vader_vm_operand_b(l20);
            t9 = vader_vm_f64_of(l16, l12, l373);
            l374 = -(t9);
            vader_vm_set_f64(l16, l17, l12, l372, l374);
        } else if (l19 == INT32_C(57)) {
            l375 = vader_vm_operand_a(l20);
            l376 = vader_vm_operand_b(l20);
            l377 = vader_vm_f64_of(l16, l12, l376);
            l378 = vader_vm_operand_c(l20);
            l379 = vader_vm_f64_of(l16, l12, l378);
            l380 = l377 == l379;
            vader_vm_set_bool(l16, l17, l12, l375, l380);
        } else if (l19 == INT32_C(58)) {
            l381 = vader_vm_operand_a(l20);
            l382 = vader_vm_operand_b(l20);
            l383 = vader_vm_f64_of(l16, l12, l382);
            l384 = vader_vm_operand_c(l20);
            l385 = vader_vm_f64_of(l16, l12, l384);
            l386 = l383 != l385;
            vader_vm_set_bool(l16, l17, l12, l381, l386);
        } else if (l19 == INT32_C(59)) {
            l387 = vader_vm_operand_a(l20);
            l388 = vader_vm_operand_b(l20);
            l389 = vader_vm_f64_of(l16, l12, l388);
            l390 = vader_vm_operand_c(l20);
            l391 = vader_vm_f64_of(l16, l12, l390);
            l392 = (l389 < l391);
            vader_vm_set_bool(l16, l17, l12, l387, l392);
        } else if (l19 == INT32_C(60)) {
            l393 = vader_vm_operand_a(l20);
            l394 = vader_vm_operand_b(l20);
            l395 = vader_vm_f64_of(l16, l12, l394);
            l396 = vader_vm_operand_c(l20);
            l397 = vader_vm_f64_of(l16, l12, l396);
            l398 = (l395 <= l397);
            vader_vm_set_bool(l16, l17, l12, l393, l398);
        } else if (l19 == INT32_C(61)) {
            l399 = vader_vm_operand_a(l20);
            l400 = vader_vm_operand_b(l20);
            l401 = vader_vm_f64_of(l16, l12, l400);
            l402 = vader_vm_operand_c(l20);
            l403 = vader_vm_f64_of(l16, l12, l402);
            l404 = (l401 > l403);
            vader_vm_set_bool(l16, l17, l12, l399, l404);
        } else if (l19 == INT32_C(62)) {
            l405 = vader_vm_operand_a(l20);
            l406 = vader_vm_operand_b(l20);
            l407 = vader_vm_f64_of(l16, l12, l406);
            l408 = vader_vm_operand_c(l20);
            l409 = vader_vm_f64_of(l16, l12, l408);
            l410 = (l407 >= l409);
            vader_vm_set_bool(l16, l17, l12, l405, l410);
        } else if (l19 == INT32_C(63)) {
            l411 = vader_vm_operand_a(l20);
            l412 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l412);
            l413 = t0 != INT64_C(0);
            l414 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l414);
            l415 = t0 != INT64_C(0);
            l416 = l413 == l415;
            vader_vm_set_bool(l16, l17, l12, l411, l416);
        } else if (l19 == INT32_C(64)) {
            l417 = vader_vm_operand_a(l20);
            l418 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l418);
            l419 = t0 != INT64_C(0);
            l420 = vader_vm_operand_c(l20);
            t0 = vader_vm_bits_of(l16, l12, l420);
            l421 = t0 != INT64_C(0);
            l422 = l419 != l421;
            vader_vm_set_bool(l16, l17, l12, l417, l422);
        } else if (l19 == INT32_C(65)) {
            l423 = vader_vm_operand_a(l20);
            l424 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l424);
            if (t0 != INT64_C(0)) {
                l426 = vader_vm_operand_c(l20);
                t0 = vader_vm_bits_of(l16, l12, l426);
                l425 = t0 != INT64_C(0);
            } else {
                l425 = false;
            }
            vader_vm_set_bool(l16, l17, l12, l423, l425);
        } else if (l19 == INT32_C(66)) {
            l427 = vader_vm_operand_a(l20);
            l428 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l428);
            if (t0 != INT64_C(0)) {
                l429 = true;
            } else {
                l430 = vader_vm_operand_c(l20);
                t0 = vader_vm_bits_of(l16, l12, l430);
                l429 = t0 != INT64_C(0);
            }
            vader_vm_set_bool(l16, l17, l12, l427, l429);
        } else if (l19 == INT32_C(67)) {
            l431 = vader_vm_operand_a(l20);
            l432 = vader_vm_operand_b(l20);
            t0 = vader_vm_bits_of(l16, l12, l432);
            l433 = t0 == INT64_C(0);
            vader_vm_set_bool(l16, l17, l12, l431, l433);
        } else if (l19 == INT32_C(68)) {
            l435 = vader_vm_checked_registers((uint8_t) 0, (uint8_t) 2, l16, l12, l20);
            if (l435.tag == 0u) {
                vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l13)
                t4 = vader_array_read_u8(_a27_slotarr, _a27_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l434 = ((int64_t) l435.payload.i);
            l436 = vader_vm_operand_a(l20);
            l437 = ((int32_t) (int64_t) l434);
            vader_vm_set_i32(l16, l17, l12, l436, l437);
        } else if (l19 == INT32_C(69)) {
            l439 = vader_vm_checked_registers((uint8_t) 1, (uint8_t) 2, l16, l12, l20);
            if (l439.tag == 0u) {
                vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l13)
                t4 = vader_array_read_u8(_a28_slotarr, _a28_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l438 = ((int64_t) l439.payload.i);
            l440 = vader_vm_operand_a(l20);
            l441 = ((int32_t) (int64_t) l438);
            vader_vm_set_i32(l16, l17, l12, l440, l441);
        } else if (l19 == INT32_C(70)) {
            l443 = vader_vm_checked_registers((uint8_t) 2, (uint8_t) 2, l16, l12, l20);
            if (l443.tag == 0u) {
                vader_array_t* _a29_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l13)
                t4 = vader_array_read_u8(_a29_slotarr, _a29_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l442 = ((int64_t) l443.payload.i);
            l444 = vader_vm_operand_a(l20);
            l445 = ((int32_t) (int64_t) l442);
            vader_vm_set_i32(l16, l17, l12, l444, l445);
        } else if (l19 == INT32_C(71)) {
            l447 = vader_vm_operand_b(l20);
            l448 = vader_vm_bits_of(l16, l12, l447);
            l449 = vader_bytecode_checked_neg((uint8_t) 2, l448);
            if (l449.tag == 0u) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l13)
                t4 = vader_array_read_u8(_a30_slotarr, _a30_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_neg_trap(((uint8_t) t4.payload.i), l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l446 = ((int64_t) l449.payload.i);
            l450 = vader_vm_operand_a(l20);
            l451 = ((int32_t) (int64_t) l446);
            vader_vm_set_i32(l16, l17, l12, l450, l451);
        } else if (l19 == INT32_C(72)) {
            l453 = vader_vm_checked_registers((uint8_t) 0, (uint8_t) 3, l16, l12, l20);
            if (l453.tag == 0u) {
                vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l13)
                t4 = vader_array_read_u8(_a31_slotarr, _a31_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l452 = ((int64_t) l453.payload.i);
            l454 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l454, l452);
        } else if (l19 == INT32_C(73)) {
            l456 = vader_vm_checked_registers((uint8_t) 1, (uint8_t) 3, l16, l12, l20);
            if (l456.tag == 0u) {
                vader_array_t* _a32_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l13)
                t4 = vader_array_read_u8(_a32_slotarr, _a32_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l455 = ((int64_t) l456.payload.i);
            l457 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l457, l455);
        } else if (l19 == INT32_C(74)) {
            l459 = vader_vm_checked_registers((uint8_t) 2, (uint8_t) 3, l16, l12, l20);
            if (l459.tag == 0u) {
                vader_array_t* _a33_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l13)
                t4 = vader_array_read_u8(_a33_slotarr, _a33_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l458 = ((int64_t) l459.payload.i);
            l460 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l460, l458);
        } else if (l19 == INT32_C(75)) {
            l462 = vader_vm_operand_b(l20);
            l463 = vader_vm_bits_of(l16, l12, l462);
            l464 = vader_bytecode_checked_neg((uint8_t) 3, l463);
            if (l464.tag == 0u) {
                vader_array_t* _a34_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l13)
                t4 = vader_array_read_u8(_a34_slotarr, _a34_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_neg_trap(((uint8_t) t4.payload.i), l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l461 = ((int64_t) l464.payload.i);
            l465 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l465, l461);
        } else if (l19 == INT32_C(76)) {
            l467 = vader_vm_checked_registers((uint8_t) 0, (uint8_t) 8, l16, l12, l20);
            if (l467.tag == 0u) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l13)
                t4 = vader_array_read_u8(_a35_slotarr, _a35_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l466 = ((int64_t) l467.payload.i);
            l468 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l468, l466);
        } else if (l19 == INT32_C(77)) {
            l470 = vader_vm_checked_registers((uint8_t) 1, (uint8_t) 8, l16, l12, l20);
            if (l470.tag == 0u) {
                vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l13)
                t4 = vader_array_read_u8(_a36_slotarr, _a36_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l469 = ((int64_t) l470.payload.i);
            l471 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l471, l469);
        } else if (l19 == INT32_C(78)) {
            l473 = vader_vm_checked_registers((uint8_t) 2, (uint8_t) 8, l16, l12, l20);
            if (l473.tag == 0u) {
                vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l13)
                t4 = vader_array_read_u8(_a37_slotarr, _a37_slotarr->offset + (size_t) l13, 249u);
                t2 = vader_vm_checked_trap(((uint8_t) t4.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l472 = ((int64_t) l473.payload.i);
            l474 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l474, l472);
        } else if (l19 == INT32_C(79)) {
            vader_array_t* _a38_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l13)
            t4 = vader_array_read_u8(_a38_slotarr, _a38_slotarr->offset + (size_t) l13, 249u);
            l475 = ((uint8_t) t4.payload.i);
            l477 = vader_vm_checked_registers((uint8_t) 0, l475, l16, l12, l20);
            if (l477.tag == 0u) {
                t2 = vader_vm_checked_trap(l475, (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l476 = ((int64_t) l477.payload.i);
            l478 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l478, l475, l476);
        } else if (l19 == INT32_C(80)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l13)
            t4 = vader_array_read_u8(_a39_slotarr, _a39_slotarr->offset + (size_t) l13, 249u);
            l479 = ((uint8_t) t4.payload.i);
            l481 = vader_vm_checked_registers((uint8_t) 1, l479, l16, l12, l20);
            if (l481.tag == 0u) {
                t2 = vader_vm_checked_trap(l479, (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l480 = ((int64_t) l481.payload.i);
            l482 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l482, l479, l480);
        } else if (l19 == INT32_C(81)) {
            vader_array_t* _a40_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l13)
            t4 = vader_array_read_u8(_a40_slotarr, _a40_slotarr->offset + (size_t) l13, 249u);
            l483 = ((uint8_t) t4.payload.i);
            l485 = vader_vm_checked_registers((uint8_t) 2, l483, l16, l12, l20);
            if (l485.tag == 0u) {
                t2 = vader_vm_checked_trap(l483, (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l484 = ((int64_t) l485.payload.i);
            l486 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l486, l483, l484);
        } else if (l19 == INT32_C(82)) {
            vader_array_t* _a41_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l13)
            t4 = vader_array_read_u8(_a41_slotarr, _a41_slotarr->offset + (size_t) l13, 249u);
            l487 = ((uint8_t) t4.payload.i);
            l489 = vader_vm_operand_b(l20);
            l490 = vader_vm_bits_of(l16, l12, l489);
            l491 = vader_bytecode_checked_neg(l487, l490);
            if (l491.tag == 0u) {
                t2 = vader_vm_checked_neg_trap(l487, l8, l13);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l488 = ((int64_t) l491.payload.i);
            l492 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l492, l487, l488);
        } else if (l19 == INT32_C(83)) {
            l493 = vader_vm_operand_a(l20);
            l494 = vader_vm_operand_b(l20);
            l495 = vader_vm_i32_of(l16, l12, l494);
            vader_vm_set_i32(l16, l17, l12, l493, l495);
        } else if (l19 == INT32_C(84)) {
            l496 = vader_vm_operand_a(l20);
            l497 = vader_vm_operand_b(l20);
            l498 = vader_vm_bits_of(l16, l12, l497);
            vader_vm_set_i64(l16, l17, l12, l496, l498);
        } else if (l19 == INT32_C(85)) {
            t3 = vader_vm_operand_b(l20);
            t0 = ((int64_t) (int32_t) t3);
            l499 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l12, l499);
            l500 = (size_t) (int64_t) t0;
            vader_array_t* _a42_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l500)
            t4 = vader_array_read_u8(_a42_slotarr, _a42_slotarr->offset + (size_t) l500, 249u);
            if (((int32_t) t4.payload.i) == INT32_C(0)) {
                vader_array_t* _a43_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l500)
                t0 = ((int64_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l500];
                l501 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
            } else {
                vader_array_t* _a44_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l500)
                l501 = ((int64_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l500];
            }
            l502 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l502, l501);
        } else {
            if (l19 == INT32_C(86)) {
                t3 = vader_vm_operand_a(l20);
                t0 = ((int64_t) (int32_t) t3);
                l13 = (size_t) (int64_t) t0;
                continue;
            }
            if (l19 == INT32_C(87)) {
                t3 = vader_vm_operand_b(l20);
                l503 = ((int64_t) (int32_t) t3);
                l11 = vader_chk_add(i64, l11, l503);
                if ((l11 > l10)) {
                    t2 = vader_vm_budget_trap(l10);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t3 = vader_vm_operand_a(l20);
                t0 = ((int64_t) (int32_t) t3);
                l13 = (size_t) (int64_t) t0;
                continue;
            }
            if (l19 == INT32_C(88)) {
                l504 = vader_vm_operand_b(l20);
                t0 = vader_vm_bits_of(l16, l12, l504);
                if (t0 == INT64_C(0)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(89)) {
                l505 = vader_vm_operand_b(l20);
                t0 = vader_vm_bits_of(l16, l12, l505);
                if (t0 != INT64_C(0)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(90)) {
                l506 = vader_vm_operand_b(l20);
                l507 = vader_vm_i32_of(l16, l12, l506);
                l508 = vader_vm_operand_c(l20);
                l509 = vader_vm_i32_of(l16, l12, l508);
                if (l507 == l509) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(91)) {
                l510 = vader_vm_operand_b(l20);
                l511 = vader_vm_i32_of(l16, l12, l510);
                l512 = vader_vm_operand_c(l20);
                l513 = vader_vm_i32_of(l16, l12, l512);
                if (l511 != l513) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(92)) {
                l514 = vader_vm_operand_b(l20);
                l515 = vader_vm_i32_of(l16, l12, l514);
                l516 = vader_vm_operand_c(l20);
                l517 = vader_vm_i32_of(l16, l12, l516);
                if ((l515 < l517)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(93)) {
                l518 = vader_vm_operand_b(l20);
                l519 = vader_vm_i32_of(l16, l12, l518);
                l520 = vader_vm_operand_c(l20);
                l521 = vader_vm_i32_of(l16, l12, l520);
                if ((l519 <= l521)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(96)) {
                l522 = vader_vm_operand_b(l20);
                l523 = vader_vm_bits_of(l16, l12, l522);
                l524 = vader_vm_operand_c(l20);
                l525 = vader_vm_bits_of(l16, l12, l524);
                if (l523 == l525) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(97)) {
                l526 = vader_vm_operand_b(l20);
                l527 = vader_vm_bits_of(l16, l12, l526);
                l528 = vader_vm_operand_c(l20);
                l529 = vader_vm_bits_of(l16, l12, l528);
                if (l527 != l529) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(98)) {
                l530 = vader_vm_operand_b(l20);
                l531 = vader_vm_bits_of(l16, l12, l530);
                l532 = vader_vm_operand_c(l20);
                l533 = vader_vm_bits_of(l16, l12, l532);
                if ((l531 < l533)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(99)) {
                l534 = vader_vm_operand_b(l20);
                l535 = vader_vm_bits_of(l16, l12, l534);
                l536 = vader_vm_operand_c(l20);
                l537 = vader_vm_bits_of(l16, l12, l536);
                if ((l535 <= l537)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(94)) {
                l538 = vader_vm_operand_b(l20);
                l539 = vader_vm_u32_of(l16, l12, l538);
                l540 = vader_vm_operand_c(l20);
                l541 = vader_vm_u32_of(l16, l12, l540);
                if ((l539 < l541)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(95)) {
                l542 = vader_vm_operand_b(l20);
                l543 = vader_vm_u32_of(l16, l12, l542);
                l544 = vader_vm_operand_c(l20);
                l545 = vader_vm_u32_of(l16, l12, l544);
                if ((l543 <= l545)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(100)) {
                l546 = vader_vm_operand_b(l20);
                l547 = vader_vm_u64_of(l16, l12, l546);
                l548 = vader_vm_operand_c(l20);
                l549 = vader_vm_u64_of(l16, l12, l548);
                if ((l547 < l549)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(101)) {
                l550 = vader_vm_operand_b(l20);
                l551 = vader_vm_u64_of(l16, l12, l550);
                l552 = vader_vm_operand_c(l20);
                l553 = vader_vm_u64_of(l16, l12, l552);
                if ((l551 <= l553)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
            } else if (l19 == INT32_C(108)) {
                t3 = vader_vm_operand_b(l20);
                l554 = ((int64_t) (int32_t) t3);
                l11 = vader_chk_add(i64, l11, l554);
                if ((l11 > l10)) {
                    t2 = vader_vm_budget_trap(l10);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(118)) {
                l555 = vader_vm_run_boxed(l0, l2, l8, l13, l12);
                if (!(l555.tag == 0u)) {
                    t2 = l555.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(119)) {
                l556 = vader_vm_operand_a(l20);
                t3 = vader_vm_operand_b(l20);
                t0 = ((int64_t) (int32_t) t3);
                l557 = (size_t) (int64_t) t0;
                t0 = vader_chk_add(usize, l12, l557);
                l558 = (size_t) (int64_t) t0;
                vader_array_t* _a45_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l13)
                l559 = ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l13];
                l560 = vader_vm_call_import(l0, l2, l556, l558, l559, l7);
                if (!(l560.tag == 0u)) {
                    t2 = l560.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else {
                if (l19 == INT32_C(120)) {
                    l561 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_texts;
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l562 = (size_t) (int64_t) t0;
                    vader_array_t* _a46_slotarr = ((vader_array_t*) l561);
                    VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l562)
                    t4 = vader_array_box_slots(_a46_slotarr->buf)[_a46_slotarr->offset + (size_t) l562];
                    t1 = t4.payload.s;
                    vader_struct_vader_vm_Trap_t* _a47_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                    vader_obj_header_init(_a47_obj, 1126u);
                    _a47_obj->f_message = t1;
                    t2 = (void*) _a47_obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l19 == INT32_C(121)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l563 = (size_t) (int64_t) t0;
                    t0 = vader_chk_add(usize, l12, l563);
                    l564 = (size_t) (int64_t) t0;
                    l565 = vader_vm_register_value(l2, l564);
                    l566 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
                    l567 = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers)->length;
                    if ((l566 < l567)) {
                        l568 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers;
                        l569 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
                        vader_array_t* _a48_slotarr = ((vader_array_t*) l568);
                        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l569)
                        vader_array_box_slots(_a48_slotarr->buf)[_a48_slotarr->offset + (size_t) l569] = l565;
                        VADER_WRITE_BARRIER(_a48_slotarr->buf);
                    } else {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers, l565);
                    }
                    t10 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
                    t0 = vader_chk_add(usize, t10, INT64_C(1));
                    l570 = (size_t) (int64_t) t0;
                    ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count = l570;
                } else if (l19 == INT32_C(122)) {
                    l571 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_registers;
                    t0 = vader_chk_add(usize, l12, l571);
                    l572 = (size_t) (int64_t) t0;
                    l573 = vader_vm_run_defers(l0, l1, l2, l8, l13, l572, l9, l7);
                    if (!(l573.tag == 0u)) {
                        t2 = l573.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else if (l19 == INT32_C(123)) {
                    l574 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_debug;
                    if (!(l574.tag == 0u)) {
                        l575 = l574.payload.obj;
                        vader_vm_stop_at_line(l0, l2, l575, l8, l13, l9);
                    }
                } else if (l19 == INT32_C(109)) {
                    t3 = vader_vm_operand_a(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l576 = (size_t) (int64_t) t0;
                    t0 = vader_chk_add(usize, l12, l576);
                    l577 = (size_t) (int64_t) t0;
                    l578 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_values;
                    t3 = vader_vm_operand_b(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l579 = (size_t) (int64_t) t0;
                    vader_array_t* _a49_slotarr = ((vader_array_t*) l578);
                    VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l579)
                    l580 = vader_array_box_slots(_a49_slotarr->buf)[_a49_slotarr->offset + (size_t) l579];
                    vader_array_t* _a50_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l577)
                    vader_array_box_slots(_a50_slotarr->buf)[_a50_slotarr->offset + (size_t) l577] = l580;
                    VADER_WRITE_BARRIER(_a50_slotarr->buf);
                    vader_array_t* _a51_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l577)
                    ((uint8_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l577] = (uint8_t) INT32_C(6);
                } else if (l19 == INT32_C(110)) {
                    t3 = vader_vm_operand_b(l20);
                    t0 = ((int64_t) (int32_t) t3);
                    l581 = (size_t) (int64_t) t0;
                    t0 = vader_chk_add(usize, l12, l581);
                    l582 = (size_t) (int64_t) t0;
                    vader_array_t* _a52_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l582)
                    l583 = vader_array_box_slots(_a52_slotarr->buf)[_a52_slotarr->offset + (size_t) l582];
                    l584 = vader_vm_operand_c(l20);
                    if (l583.tag == 1123u) {
                        l585 = (l584 >= INT32_C(0));
                    } else {
                        l585 = false;
                    }
                    if (l585) {
                        t0 = ((int64_t) (int32_t) l584);
                        l587 = (size_t) (int64_t) t0;
                        t2 = l583.payload.obj;
                        l588 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t2)->f_fields)->length;
                        l586 = (l587 < l588);
                    } else {
                        l586 = false;
                    }
                    if (l586) {
                        t3 = vader_vm_operand_a(l20);
                        t0 = ((int64_t) (int32_t) t3);
                        l589 = (size_t) (int64_t) t0;
                        t0 = vader_chk_add(usize, l12, l589);
                        l590 = (size_t) (int64_t) t0;
                        t2 = l583.payload.obj;
                        l591 = ((vader_struct_vader_vm_StructVal_t*) t2)->f_fields;
                        t0 = ((int64_t) (int32_t) l584);
                        l592 = (size_t) (int64_t) t0;
                        vader_array_t* _a53_slotarr = ((vader_array_t*) l591);
                        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l592)
                        l593 = vader_array_box_slots(_a53_slotarr->buf)[_a53_slotarr->offset + (size_t) l592];
                        vader_vm_set_register(l2, l590, l593);
                    } else {
                        vader_array_t* _a54_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                        VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a54_slotarr, l13)
                        l594 = ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l13];
                        l595 = vader_vm_read_struct_field(l583, l584, l594, 2299u);
                        if (l595.tag == 1126u) {
                            t2 = l595.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    }
                } else if (l19 == INT32_C(111)) {
                    l596 = vader_vm_operand_a(l20);
                    l597 = vader_vm_operand_b(l20);
                    l598 = vader_vm_operand_c(l20);
                    l599 = vader_vm_set_field(l2, l12, l596, l597, l598, l8, l13);
                    if (!(l599.tag == 0u)) {
                        t2 = l599.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else {
                    if (l19 == INT32_C(112)) {
                        l600 = true;
                    } else {
                        l600 = l19 == INT32_C(114);
                    }
                    if (l600) {
                        l601 = vader_vm_operand_a(l20);
                        l602 = vader_vm_operand_b(l20);
                        l603 = vader_vm_operand_c(l20);
                        t11 = vader_vm_try_get_element(l2, l12, l601, l602, l603);
                        if (!(t11)) {
                            l604 = vader_vm_operand_b(l20);
                            l605 = vader_vm_operand_c(l20);
                            t2 = vader_vm_element_trap(l2, l12, l604, l605, l8, l13, l19);
                            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    } else {
                        if (l19 == INT32_C(113)) {
                            l606 = true;
                        } else {
                            l606 = l19 == INT32_C(115);
                        }
                        if (l606) {
                            l607 = vader_vm_operand_a(l20);
                            l608 = vader_vm_operand_b(l20);
                            l609 = vader_vm_operand_c(l20);
                            t11 = vader_vm_try_set_element(l2, l12, l607, l608, l609);
                            if (!(t11)) {
                                l610 = vader_vm_operand_a(l20);
                                l611 = vader_vm_operand_b(l20);
                                l612 = vader_vm_operand_c(l20);
                                l613 = vader_vm_set_element(l2, l12, l610, l611, l612, l8, l13, l19);
                                if (!(l613.tag == 0u)) {
                                    t2 = l613.payload.obj;
                                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                            }
                        } else if (l19 == INT32_C(116)) {
                            t3 = vader_vm_operand_b(l20);
                            t0 = ((int64_t) (int32_t) t3);
                            l614 = (size_t) (int64_t) t0;
                            t0 = vader_chk_add(usize, l12, l614);
                            l615 = (size_t) (int64_t) t0;
                            l617 = vader_vm_array_at(l2, l615);
                            if (l617.tag == 0u) {
                                t2 = vader_vm_receiver_trap(l2, l615, l8, l13, 1299u);
                                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l616 = l617.payload.obj;
                            l618 = vader_vm_operand_a(l20);
                            t10 = ((vader_struct_vader_vm_ArrayVal_t*) l616)->f_length;
                            l619 = ((int32_t) (size_t) t10);
                            vader_vm_set_i32(l16, l17, l12, l618, l619);
                        } else if (l19 == INT32_C(117)) {
                            t3 = vader_vm_operand_a(l20);
                            t0 = ((int64_t) (int32_t) t3);
                            l620 = (size_t) (int64_t) t0;
                            t0 = vader_chk_add(usize, l12, l620);
                            l621 = (size_t) (int64_t) t0;
                            l623 = vader_vm_array_at(l2, l621);
                            if (l623.tag == 0u) {
                                t2 = vader_vm_receiver_trap(l2, l621, l8, l13, 1302u);
                                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l622 = l623.payload.obj;
                            if (!(((vader_struct_vader_vm_ArrayVal_t*) l622)->f_raw.tag == 0u)) {
                                l624 = true;
                            } else {
                                l624 = vader_vm_is_array_view(l622);
                            }
                            if (l624) {
                                vader_vm_detach_array_view(l622);
                            }
                            l625 = ((vader_struct_vader_vm_ArrayVal_t*) l622)->f_elements;
                            t3 = vader_vm_operand_b(l20);
                            t0 = ((int64_t) (int32_t) t3);
                            l626 = (size_t) (int64_t) t0;
                            t0 = vader_chk_add(usize, l12, l626);
                            l627 = (size_t) (int64_t) t0;
                            l628 = vader_vm_register_value(l2, l627);
                            vader_array_push((vader_array_t*) l625, l628);
                            t10 = ((vader_struct_vader_vm_ArrayVal_t*) l622)->f_length;
                            t0 = vader_chk_add(usize, t10, INT64_C(1));
                            l629 = (size_t) (int64_t) t0;
                            ((vader_struct_vader_vm_ArrayVal_t*) l622)->f_length = l629;
                        } else if (l19 == INT32_C(105)) {
                            t3 = vader_vm_operand_a(l20);
                            t0 = ((int64_t) (int32_t) t3);
                            l630 = (size_t) (int64_t) t0;
                            t0 = vader_chk_add(usize, l12, l630);
                            l631 = (size_t) (int64_t) t0;
                            l632 = vader_vm_operand_b(l20);
                            vader_vm_narrow_register(l2, l631, l632);
                        } else {
                            if (l19 == INT32_C(102)) {
                                l633 = true;
                            } else {
                                l633 = l19 == INT32_C(103);
                            }
                            if (l633) {
                                l634 = true;
                            } else {
                                l634 = l19 == INT32_C(104);
                            }
                            if (l634) {
                                t3 = vader_vm_operand_b(l20);
                                t0 = ((int64_t) (int32_t) t3);
                                l635 = (size_t) (int64_t) t0;
                                t0 = vader_chk_add(usize, l12, l635);
                                l636 = (size_t) (int64_t) t0;
                                l637 = vader_vm_operand_a(l20);
                                if (l19 == INT32_C(103)) {
                                    t3 = vader_vm_operand_c(l20);
                                    t0 = ((int64_t) (int32_t) t3);
                                    l638 = (size_t) (int64_t) t0;
                                    t0 = vader_chk_add(usize, l636, l638);
                                    l639 = (size_t) (int64_t) t0;
                                    vader_array_t* _a55_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l639)
                                    l640 = vader_array_box_slots(_a55_slotarr->buf)[_a55_slotarr->offset + (size_t) l639];
                                    t0 = vader_chk_add(usize, l636, l638);
                                    l641 = (size_t) (int64_t) t0;
                                    vader_array_t* _a56_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l641)
                                    t4 = vader_array_read_u8(_a56_slotarr, _a56_slotarr->offset + (size_t) l641, 249u);
                                    if (((int32_t) t4.payload.i) == INT32_C(6)) {
                                        l642 = l640.tag == 1103u;
                                    } else {
                                        l642 = false;
                                    }
                                    if (!(l642)) {
                                        vader_array_t* _a57_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l13)
                                        l662 = ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l13];
                                        t2 = vader_vm_indirect_call_trap(l1, l2, l636, l638, l662);
                                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    t2 = l640.payload.obj;
                                    l643 = ((vader_struct_vader_vm_FnVal_t*) t2)->f_function_index;
                                    t2 = l640.payload.obj;
                                    l644 = ((vader_struct_vader_vm_FnVal_t*) t2)->f_env;
                                    if (l644.tag == 0u) {
                                        l645 = l638;
                                    } else {
                                        t0 = vader_chk_add(usize, l638, INT64_C(1));
                                        l645 = (size_t) (int64_t) t0;
                                    }
                                    if ((l643 >= INT32_C(0))) {
                                        t0 = ((int64_t) (int32_t) l643);
                                        l647 = (size_t) (int64_t) t0;
                                        l648 = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions)->length;
                                        l646 = (l647 < l648);
                                    } else {
                                        l646 = false;
                                    }
                                    if (l646) {
                                        l650 = ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions;
                                        t0 = ((int64_t) (int32_t) l643);
                                        l651 = (size_t) (int64_t) t0;
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) l650);
                                        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l651)
                                        t2 = vader_array_ref_load_obj(_a58_slotarr->buf, _a58_slotarr->offset + (size_t) l651);
                                        t10 = ((vader_struct_vader_vm_RegFunction_t*) t2)->f_params;
                                        l649 = t10 == l645;
                                    } else {
                                        l649 = false;
                                    }
                                    if (!(l649)) {
                                        vader_array_t* _a59_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l13)
                                        l661 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l13];
                                        t2 = vader_vm_indirect_call_trap(l1, l2, l636, l638, l661);
                                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    if (!(l644.tag == 0u)) {
                                        l652 = l638;
                                        while ((l652 > INT64_C(0))) {
                                            t0 = vader_chk_add(usize, l636, l652);
                                            l653 = (size_t) (int64_t) t0;
                                            t0 = vader_chk_sub(usize, l653, INT64_C(1));
                                            l654 = (size_t) (int64_t) t0;
                                            vader_array_t* _a60_slotarr = ((vader_array_t*) l16);
                                            VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l654)
                                            l655 = ((int64_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l654];
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l653)
                                            ((int64_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l653] = (int64_t) l655;
                                            t0 = vader_chk_sub(usize, l653, INT64_C(1));
                                            l656 = (size_t) (int64_t) t0;
                                            vader_array_t* _a61_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a61_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l656)
                                            t4 = vader_array_read_u8(_a61_slotarr, _a61_slotarr->offset + (size_t) l656, 249u);
                                            l657 = ((uint8_t) t4.payload.i);
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l653)
                                            ((uint8_t*) _a61_slotarr->buf->slots)[_a61_slotarr->offset + (size_t) l653] = (uint8_t) (int32_t) (uint8_t) l657;
                                            t0 = vader_chk_sub(usize, l653, INT64_C(1));
                                            l658 = (size_t) (int64_t) t0;
                                            vader_array_t* _a62_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l658)
                                            l659 = vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l658];
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l653)
                                            vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l653] = l659;
                                            VADER_WRITE_BARRIER(_a62_slotarr->buf);
                                            t0 = vader_chk_sub(usize, l652, INT64_C(1));
                                            l652 = (size_t) (int64_t) t0;
                                        }
                                        l660 = l644;
                                        vader_vm_set_register(l2, l636, l660);
                                    }
                                    l637 = l643;
                                } else if (l19 == INT32_C(104)) {
                                    t0 = ((int64_t) (int32_t) l637);
                                    l663 = (size_t) (int64_t) t0;
                                    t3 = vader_vm_operand_c(l20);
                                    t0 = ((int64_t) (int32_t) t3);
                                    l664 = (size_t) (int64_t) t0;
                                    t0 = vader_chk_add(usize, l636, l664);
                                    t7 = vader_chk_sub(usize, t0, INT64_C(1));
                                    l665 = (size_t) (int64_t) t7;
                                    vader_array_t* _a63_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a63_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a63_slotarr, l665)
                                    l666 = vader_array_box_slots(_a63_slotarr->buf)[_a63_slotarr->offset + (size_t) l665];
                                    vader_array_t* _a64_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l665)
                                    t4 = vader_array_read_u8(_a64_slotarr, _a64_slotarr->offset + (size_t) l665, 249u);
                                    if (((int32_t) t4.payload.i) != INT32_C(6)) {
                                        l667 = INT32_C(-1);
                                    } else if (l666.tag == 1123u) {
                                        t2 = l666.payload.obj;
                                        l667 = ((vader_struct_vader_vm_StructVal_t*) t2)->f_type_id;
                                    } else if (l666.tag == 1098u) {
                                        t2 = l666.payload.obj;
                                        l667 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_type_id;
                                    } else {
                                        l667 = INT32_C(-1);
                                    }
                                    if ((l667 < INT32_C(0))) {
                                        l668 = INT32_C(-1);
                                    } else {
                                        vader_array_t* _a65_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_virtual_rows);
                                        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l663)
                                        l668 = ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l663];
                                    }
                                    l669 = vader_vm_lookup_vtable_row(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables, l668, l667);
                                    if ((l669 >= INT32_C(0))) {
                                        t0 = ((int64_t) (int32_t) l669);
                                        l671 = (size_t) (int64_t) t0;
                                        l672 = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions)->length;
                                        l670 = (l671 < l672);
                                    } else {
                                        l670 = false;
                                    }
                                    if (l670) {
                                        l674 = ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions;
                                        t0 = ((int64_t) (int32_t) l669);
                                        l675 = (size_t) (int64_t) t0;
                                        vader_array_t* _a66_slotarr = ((vader_array_t*) l674);
                                        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l675)
                                        t2 = vader_array_ref_load_obj(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l675);
                                        t10 = ((vader_struct_vader_vm_RegFunction_t*) t2)->f_params;
                                        l673 = t10 == l664;
                                    } else {
                                        l673 = false;
                                    }
                                    if (l673) {
                                        if ((l665 > l636)) {
                                            l676 = l665;
                                            while ((l676 > l636)) {
                                                t0 = vader_chk_sub(usize, l676, INT64_C(1));
                                                l677 = (size_t) (int64_t) t0;
                                                vader_array_t* _a67_slotarr = ((vader_array_t*) l16);
                                                VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l677)
                                                l678 = ((int64_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l677];
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l676)
                                                ((int64_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l676] = (int64_t) l678;
                                                t0 = vader_chk_sub(usize, l676, INT64_C(1));
                                                l679 = (size_t) (int64_t) t0;
                                                vader_array_t* _a68_slotarr = ((vader_array_t*) l17);
                                                VADER_ARRAY_RESOLVE_BUF(_a68_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l679)
                                                t4 = vader_array_read_u8(_a68_slotarr, _a68_slotarr->offset + (size_t) l679, 249u);
                                                l680 = ((uint8_t) t4.payload.i);
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l676)
                                                ((uint8_t*) _a68_slotarr->buf->slots)[_a68_slotarr->offset + (size_t) l676] = (uint8_t) (int32_t) (uint8_t) l680;
                                                t0 = vader_chk_sub(usize, l676, INT64_C(1));
                                                l681 = (size_t) (int64_t) t0;
                                                vader_array_t* _a69_slotarr = ((vader_array_t*) l18);
                                                VADER_ARRAY_RESOLVE_BUF(_a69_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l681)
                                                l682 = vader_array_box_slots(_a69_slotarr->buf)[_a69_slotarr->offset + (size_t) l681];
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l676)
                                                vader_array_box_slots(_a69_slotarr->buf)[_a69_slotarr->offset + (size_t) l676] = l682;
                                                VADER_WRITE_BARRIER(_a69_slotarr->buf);
                                                t0 = vader_chk_sub(usize, l676, INT64_C(1));
                                                l676 = (size_t) (int64_t) t0;
                                            }
                                            vader_array_t* _a70_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a70_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a70_slotarr, l636)
                                            vader_array_box_slots(_a70_slotarr->buf)[_a70_slotarr->offset + (size_t) l636] = l666;
                                            VADER_WRITE_BARRIER(_a70_slotarr->buf);
                                            vader_array_t* _a71_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l636)
                                            ((uint8_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l636] = (uint8_t) INT32_C(6);
                                        }
                                        l637 = l669;
                                    } else {
                                        l683 = vader_vm_resolve_virtual(l0, l2, l8, l13, l636, l7);
                                        if (l683.tag == 1126u) {
                                            t2 = l683.payload.obj;
                                            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        l637 = ((int32_t) l683.payload.i);
                                    }
                                }
                                if ((l637 >= INT32_C(0))) {
                                    l684 = ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions;
                                    t0 = ((int64_t) (int32_t) l637);
                                    l685 = (size_t) (int64_t) t0;
                                    vader_array_t* _a72_slotarr = ((vader_array_t*) l684);
                                    VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l685)
                                    l686 = vader_array_ref_load_obj(_a72_slotarr->buf, _a72_slotarr->offset + (size_t) l685);
                                    l11 = vader_chk_add(i64, l11, INT64_C(1));
                                    t0 = ((int64_t) 1024);
                                    l687 = (size_t) (int64_t) t0;
                                    if ((l9 >= l687)) {
                                        t1 = ((vader_struct_vader_vm_RegFunction_t*) l686)->f_name;
                                        t2 = vader_vm_overflow_trap(t1);
                                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    l688 = ((vader_array_t*) l16)->length;
                                    l689 = ((vader_struct_vader_vm_RegFunction_t*) l686)->f_registers;
                                    t0 = vader_chk_add(usize, l636, l689);
                                    l690 = (size_t) (int64_t) t0;
                                    if ((l688 < l690)) {
                                        l691 = ((vader_struct_vader_vm_RegFunction_t*) l686)->f_registers;
                                        t0 = vader_chk_add(usize, l636, l691);
                                        l692 = (size_t) (int64_t) t0;
                                        vader_vm_reserve_registers(l2, l692);
                                    }
                                    l693 = ((vader_struct_vader_vm_RegFunction_t*) l686)->f_params;
                                    t0 = vader_chk_add(usize, l636, l693);
                                    l694 = (size_t) (int64_t) t0;
                                    l695 = ((vader_struct_vader_vm_RegFunction_t*) l686)->f_slots;
                                    t0 = vader_chk_add(usize, l636, l695);
                                    l696 = (size_t) (int64_t) t0;
                                    while ((l694 < l696)) {
                                        vader_array_t* _a73_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l694)
                                        ((uint8_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l694] = (uint8_t) INT32_C(5);
                                        t0 = (l694 + INT64_C(1));
                                        l694 = (size_t) (int64_t) t0;
                                    }
                                    l697 = ((vader_struct_vader_vm_RegFunction_t*) l686)->f_slots;
                                    t0 = vader_chk_add(usize, l636, l697);
                                    l698 = (size_t) (int64_t) t0;
                                    l699 = (size_t) 0;
                                    l700 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l686)->f_consts)->length;
                                    while ((l699 < l700)) {
                                        t0 = vader_chk_add(usize, l698, l699);
                                        l701 = (size_t) (int64_t) t0;
                                        vader_array_t* _a74_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l686)->f_consts);
                                        VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l699)
                                        l702 = ((int64_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l699];
                                        vader_array_t* _a75_slotarr = ((vader_array_t*) l16);
                                        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a75_slotarr, l701)
                                        ((int64_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l701] = (int64_t) l702;
                                        t0 = vader_chk_add(usize, l698, l699);
                                        l703 = (size_t) (int64_t) t0;
                                        vader_array_t* _a76_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l686)->f_const_tags);
                                        VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l699)
                                        t4 = vader_array_read_u8(_a76_slotarr, _a76_slotarr->offset + (size_t) l699, 249u);
                                        l704 = ((uint8_t) t4.payload.i);
                                        vader_array_t* _a77_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a77_slotarr, l703)
                                        ((uint8_t*) _a77_slotarr->buf->slots)[_a77_slotarr->offset + (size_t) l703] = (uint8_t) (int32_t) (uint8_t) l704;
                                        t0 = (l699 + INT64_C(1));
                                        l699 = (size_t) (int64_t) t0;
                                    }
                                    l705 = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code)->length;
                                    if ((l9 < l705)) {
                                        vader_array_t* _a78_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code);
                                        VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a78_slotarr, l9)
                                        vader_array_ref_store(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l9, l686);
                                        VADER_WRITE_BARRIER(_a78_slotarr->buf);
                                        vader_array_t* _a79_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_base);
                                        VADER_ARRAY_RESOLVE_BUF(_a79_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a79_slotarr, l9)
                                        ((int64_t*) _a79_slotarr->buf->slots)[_a79_slotarr->offset + (size_t) l9] = (int64_t) (int64_t) (size_t) l636;
                                        l706 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_return;
                                        t0 = vader_chk_add(usize, l13, INT64_C(1));
                                        l707 = (size_t) (int64_t) t0;
                                        vader_array_t* _a80_slotarr = ((vader_array_t*) l706);
                                        VADER_ARRAY_RESOLVE_BUF(_a80_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a80_slotarr, l9)
                                        ((int64_t*) _a80_slotarr->buf->slots)[_a80_slotarr->offset + (size_t) l9] = (int64_t) (int64_t) (size_t) l707;
                                    } else {
                                        t0 = vader_chk_add(usize, l13, INT64_C(1));
                                        l708 = (size_t) (int64_t) t0;
                                        vader_vm_grow_frame_records(l2, l686, l636, l708);
                                    }
                                    t0 = vader_chk_add(usize, l9, INT64_C(1));
                                    l9 = (size_t) (int64_t) t0;
                                    l12 = l636;
                                    l8 = l686;
                                    l14 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_ops;
                                    l15 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_words;
                                    l13 = (size_t) 0;
                                    continue;
                                }
                            } else {
                                if (l19 == INT32_C(106)) {
                                    l709 = true;
                                } else {
                                    l709 = l19 == INT32_C(107);
                                }
                                if (!(l709)) {
                                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                }
                                l710 = l19 == INT32_C(107);
                                l711 = vader_vm_operand_a(l20);
                                if (l710) {
                                    l712 = (size_t) 0;
                                    t3 = vader_vm_operand_b(l20);
                                    t0 = ((int64_t) (int32_t) t3);
                                    l713 = (size_t) (int64_t) t0;
                                    while ((l712 < l713)) {
                                        t0 = vader_chk_add(usize, l12, l712);
                                        l714 = (size_t) (int64_t) t0;
                                        t0 = ((int64_t) (int32_t) l711);
                                        l715 = (size_t) (int64_t) t0;
                                        t0 = vader_chk_add(usize, l12, l715);
                                        t7 = vader_chk_add(usize, t0, l712);
                                        l716 = (size_t) (int64_t) t7;
                                        vader_vm_move_register(l2, l714, l716);
                                        t0 = (l712 + INT64_C(1));
                                        l712 = (size_t) (int64_t) t0;
                                    }
                                } else if ((l711 >= INT32_C(0))) {
                                    t0 = ((int64_t) (int32_t) l711);
                                    l717 = (size_t) (int64_t) t0;
                                    t0 = vader_chk_add(usize, l12, l717);
                                    l718 = (size_t) (int64_t) t0;
                                    vader_vm_move_register(l2, l12, l718);
                                }
                                t0 = vader_chk_sub(usize, l9, INT64_C(1));
                                l9 = (size_t) (int64_t) t0;
                                if (l9 == l5) {
                                    if (l710) {
                                        if (l5 == INT64_C(0)) {
                                            vader_struct_vader_vm_Trap_t* _a81_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                                            vader_obj_header_init(_a81_obj, 1126u);
                                            _a81_obj->f_message = 2165u;
                                            t2 = (void*) _a81_obj;
                                            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                                    }
                                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                                }
                                vader_array_t* _a82_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_return);
                                VADER_ARRAY_RESOLVE_BUF(_a82_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a82_slotarr, l9)
                                t0 = ((int64_t*) _a82_slotarr->buf->slots)[_a82_slotarr->offset + (size_t) l9];
                                l13 = (size_t) (int64_t) t0;
                                l719 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_base;
                                t0 = vader_chk_sub(usize, l9, INT64_C(1));
                                l720 = (size_t) (int64_t) t0;
                                vader_array_t* _a83_slotarr = ((vader_array_t*) l719);
                                VADER_ARRAY_RESOLVE_BUF(_a83_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a83_slotarr, l720)
                                t0 = ((int64_t*) _a83_slotarr->buf->slots)[_a83_slotarr->offset + (size_t) l720];
                                l12 = (size_t) (int64_t) t0;
                                l721 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code;
                                t0 = vader_chk_sub(usize, l9, INT64_C(1));
                                l722 = (size_t) (int64_t) t0;
                                vader_array_t* _a84_slotarr = ((vader_array_t*) l721);
                                VADER_ARRAY_RESOLVE_BUF(_a84_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a84_slotarr, l722)
                                l8 = vader_array_ref_load_obj(_a84_slotarr->buf, _a84_slotarr->offset + (size_t) l722);
                                l14 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_ops;
                                l15 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_words;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        t0 = vader_chk_add(usize, l13, INT64_C(1));
        l13 = (size_t) (int64_t) t0;
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm_reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6) {
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    size_t l8, l22;
    int32_t l9;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
    bool l23;
    int64_t t0;
    void* t1 = NULL;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l4, &l6, &l10, &l11, &t3 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l3, &l7, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &l21, &t1,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 15u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    t0 = ((int64_t) (int32_t) l2);
    l8 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_string_array_type_id;
    l10 = vader_vm_build_main_args(l7, l3, l9);
    if (l10.tag == 1126u) {
        t1 = l10.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 0u) {
        l11 = vader_box_obj(0u, NULL);
    } else {
        t1 = l6.payload.obj;
        vader_struct_vader_vm_DebugSession_t* _a1_obj = (vader_struct_vader_vm_DebugSession_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_DebugSession_t));
        vader_obj_header_init(_a1_obj, 1101u);
        _a1_obj->f_controller = t1;
        _a1_obj->f_last_line = INT32_C(-1);
        _a1_obj->f_step_mode = (uint8_t) 0;
        _a1_obj->f_step_depth = INT32_C(0);
        t1 = (void*) _a1_obj;
        l11 = vader_ref_box(t1);
    }
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 8u, 247u);
    l12 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 1u, 249u);
    l13 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l14 = (void*) _a4_arr;
    l15 = vader_vm_new_run_host();
    l16 = vader_vm_scratch_frame();
    vader_array_t* _a5_arr = vader_array_new(175u, 0u, 13u, 1117u);
    l17 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(20u, 0u, 4u, 253u);
    l18 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(20u, 0u, 4u, 253u);
    l19 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l20 = (void*) _a8_arr;
    vader_struct_vader_vm_NullVal_t* _a9_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
    vader_obj_header_init(_a9_obj, 1110u);
    l21 = (void*) _a9_obj;
    vader_struct_vader_vm_RegMachine_t* _a10_obj = (vader_struct_vader_vm_RegMachine_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RegMachine_t));
    vader_obj_header_init(_a10_obj, 1118u);
    _a10_obj->f_bits = l12;
    _a10_obj->f_tags = l13;
    _a10_obj->f_refs = l14;
    _a10_obj->f_run = l15;
    _a10_obj->f_scratch = l16;
    _a10_obj->f_frame_code = l17;
    _a10_obj->f_frame_base = l18;
    _a10_obj->f_frame_return = l19;
    _a10_obj->f_defers = l20;
    _a10_obj->f_defer_count = (size_t) 0;
    _a10_obj->f_debug = l11;
    _a10_obj->f_null_value = vader_ref_box(l21);
    l12 = (void*) _a10_obj;
    l13 = ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions;
    t0 = ((int64_t) (int32_t) l2);
    l8 = (size_t) (int64_t) t0;
    vader_array_t* _a11_slotarr = ((vader_array_t*) l13);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
    t1 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l8);
    l8 = ((vader_struct_vader_vm_RegFunction_t*) t1)->f_registers;
    vader_vm_reserve_registers(l12, l8);
    l8 = (size_t) 0;
    t1 = l10.payload.obj;
    l22 = ((vader_array_t*) t1)->length;
    while ((l8 < l22)) {
        t1 = l10.payload.obj;
        vader_array_t* _a12_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        l11 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l8];
        vader_vm_set_register(l12, l8, l11);
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l10 = vader_vm_reg_call(l0, l1, l12, l2, (size_t) 0, (size_t) 0, (size_t) 0, l5);
    if (!(l10.tag == 1126u)) {
        t2 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_signature);
        l23 = t2 == INT64_C(1);
        t3 = vader_vm_finish_run(l12, l23, l4);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_vm_unwind(l0, l1, l12, l5);
    t1 = l10.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_register_value(void* l0, size_t l1) {
    uint8_t l2;
    vader_box_t l3;
    vader_box_t t0;
    int64_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        return l3;
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(246u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(247u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(240u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(241u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        t1 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(242u, (int32_t) ((uint32_t) (int32_t) ((int32_t) (int64_t) t1)));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_null_value;
    }
    return l3;
}

static vader_box_t vader_vm_relocated(vader_box_t l0, int32_t l1) {
    int32_t l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm_slot_touched_by(l0);
    if ((l2 < INT32_C(0))) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_chk_add(i32, l2, l1);
    t0 = vader_bytecode_with_remapped_slot(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_reserve_registers(void* l0, size_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits)->length;
        if ((t0 < l1)) {
            vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits, INT64_C(0));
            vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags, INT32_C(5));
            l2 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs;
            vader_struct_vader_vm_NullVal_t* _a0_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
            vader_obj_header_init(_a0_obj, 1110u);
            l3 = (void*) _a0_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_reserve_stack(void* l0, size_t l1) {
    size_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload)->length;
        if ((t0 < l1)) {
            vader_vm_stack_grow(l0);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_reset_stack(void* l0, size_t l1) {
    size_t l2;
    int32_t l3;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_clear((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
    l2 = (size_t) 0;
    while ((l2 < l1)) {
        l3 = vader_vm_canonical(l0, l2);
        vader_vm_push_register(l0, l3);
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_resolve_virtual(void* l0, void* l1, void* l2, size_t l3, size_t l4, bool l5) {
    int64_t l6;
    size_t l7, l11, l16, l17;
    void* l8 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    int32_t l9, l10, l13, l23;
    vader_box_t l12 = vader_box_null(), l26 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    uint64_t l19;
    bool l20;
    uint8_t l25;
    int32_t t0;
    int64_t t1, t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    bool t5;
    size_t t6;
    vader_box_t t7 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l12, &l26, &t7 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l8, &l18, &l21, &l22, &l24, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l14, &l15, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    t0 = vader_vm_operand_a(l6);
    t1 = ((int64_t) (int32_t) t0);
    l7 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_virtuals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_virtual_rows);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    t0 = vader_vm_operand_c(l6);
    t1 = ((int64_t) (int32_t) t0);
    l7 = (size_t) (int64_t) t1;
    t1 = vader_chk_add(usize, l4, l7);
    t2 = vader_chk_sub(usize, t1, INT64_C(1));
    l11 = (size_t) (int64_t) t2;
    l12 = vader_vm_register_value(l1, l11);
    l13 = vader_vm_receiver_type_id_of(l0, l12);
    if ((l13 < INT32_C(0))) {
        l15 = vader_vm_describe_value_tag(l12);
        l14 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
        l16 = vader_host_std_core_byte_len(l14);
        l17 = vader_host_std_core_byte_len(l15);
        t1 = (l16 + l17);
        l16 = (size_t) (int64_t) t1;
        l18 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(73) + l16));
        l16 = (size_t) 0;
        l16 = std_core_write_string_at(l18, l16, 2619u);
        l16 = std_core_write_string_at(l18, l16, l14);
        l16 = std_core_write_string_at(l18, l16, 217u);
        l16 = std_core_write_string_at(l18, l16, l15);
        l16 = std_core_write_string_at(l18, l16, 78u);
        l6 = ((int64_t) (int32_t) l10);
        l16 = std_core_write_int(l18, l16, l6);
        t3 = std_core_finish_buffer(l18, l16);
        vader_struct_vader_vm_Trap_t* _a4_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a4_obj, 1126u);
        _a4_obj->f_message = t3;
        t4 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm_lookup_vtable_row(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables, l9, l13);
    while ((l11 > l4)) {
        t1 = vader_chk_sub(usize, l11, INT64_C(1));
        l16 = (size_t) (int64_t) t1;
        vader_vm_move_register(l1, l11, l16);
        t1 = vader_chk_sub(usize, l11, INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    vader_vm_set_register(l1, l4, l12);
    if ((l9 >= INT32_C(0))) {
        l18 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
        t5 = vader_vm_is_fn_index_out_of_range(l9, l18);
        if (t5) {
            l14 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
            l14 = concat_3(2619u, l14, 213u);
            t4 = vader_vm_fn_index_trap(l9, l10, l14);
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
        t1 = ((int64_t) (int32_t) l9);
        l11 = (size_t) (int64_t) t1;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
        l18 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
        t6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l18)->f_signature)->f_params)->length;
        if (!(t6 != l7)) {
            t7 = vader_box_i32(246u, l9);
            { vader_box_t __vret = t7; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l11 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l18)->f_signature)->f_params)->length;
        l14 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
        l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l18)->f_name;
        l16 = vader_host_std_core_byte_len(l14);
        l17 = vader_host_std_core_byte_len(l15);
        t1 = (l16 + l17);
        l16 = (size_t) (int64_t) t1;
        l18 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(134) + l16));
        l16 = (size_t) 0;
        l16 = std_core_write_string_at(l18, l16, 2619u);
        l16 = std_core_write_string_at(l18, l16, l14);
        l16 = std_core_write_string_at(l18, l16, 215u);
        l16 = std_core_write_string_at(l18, l16, l15);
        l16 = std_core_write_string_at(l18, l16, 220u);
        t1 = ((int64_t) (size_t) l11);
        l19 = (uint64_t) (int64_t) t1;
        l16 = std_core_write_unsigned(l18, l16, l19);
        l16 = std_core_write_string_at(l18, l16, 117u);
        t1 = ((int64_t) (size_t) l7);
        l19 = (uint64_t) (int64_t) t1;
        l16 = std_core_write_unsigned(l18, l16, l19);
        l16 = std_core_write_string_at(l18, l16, 56u);
        l6 = ((int64_t) (int32_t) l10);
        l16 = std_core_write_int(l18, l16, l6);
        t3 = std_core_finish_buffer(l18, l16);
        vader_struct_vader_vm_Trap_t* _a6_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a6_obj, 1126u);
        _a6_obj->f_message = t3;
        t4 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l14 = vader_vm_primitive_kind_at(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types, l13);
    l15 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
    l15 = vader_vm_intrinsic_host_mangle(l14, l15);
    if (l14 == 0u) {
        l20 = true;
    } else {
        l20 = l15 == 0u;
    }
    if (l20) {
        l14 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
        l11 = vader_host_std_core_byte_len(l14);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(82) + l11));
        l11 = (size_t) 0;
        l11 = std_core_write_string_at(l8, l11, 2619u);
        l11 = std_core_write_string_at(l8, l11, l14);
        l11 = std_core_write_string_at(l8, l11, 216u);
        l6 = ((int64_t) (int32_t) l13);
        l11 = std_core_write_int(l8, l11, l6);
        l11 = std_core_write_string_at(l8, l11, 56u);
        l6 = ((int64_t) (int32_t) l10);
        l11 = std_core_write_int(l8, l11, l6);
        t3 = std_core_finish_buffer(l8, l11);
        vader_struct_vader_vm_Trap_t* _a7_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a7_obj, 1126u);
        _a7_obj->f_message = t3;
        t4 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_vm_primitive_impl_import(l15, l7);
    vader_array_t* _a8_arr = vader_array_new(205u, 0u, 0u, 1642u);
    t4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t4, (size_t) l7);
    l18 = (void*) _a9_arr;
    l11 = (size_t) 0;
    while ((l11 < l7)) {
        t1 = vader_chk_add(usize, l4, l11);
        l16 = (size_t) (int64_t) t1;
        l12 = vader_vm_register_value(l1, l16);
        vader_array_push((vader_array_t*) l18, l12);
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    l21 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_gc_state;
    l22 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_sched_state;
    l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_string_array_type_id;
    l13 = ((vader_struct_vader_vm_VmState_t*) l0)->f_u8_array_type_id;
    l23 = ((vader_struct_vader_vm_VmState_t*) l0)->f_io_error_type_id;
    l24 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
    l12 = vader_vm_debug_controller(l1);
    l25 = vader_bytecode_intrinsic_id_for(l15);
    l12 = vader_vm_dispatch_import(l8, l18, (size_t) 0, l21, l22, l10, l9, l13, l23, l24, l5, l12, l25);
    if (!(l12.tag == 1126u)) {
        t4 = l12.payload.obj;
        l26 = ((vader_struct_vader_vm_HostOk_t*) t4)->f_value;
        vader_vm_set_register(l1, l4, l26);
        { vader_box_t __vret = vader_box_i32(246u, INT32_C(-1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = l12.payload.obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_return_many(void* l0, size_t l1, void* l2) {
    size_t l3, l4, l5, l7;
    int32_t l6, l8;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_vm_flush(l0, l1);
    l3 = ((vader_array_t*) l2)->length;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    t1 = vader_chk_sub(usize, t0, l3);
    l4 = (size_t) (int64_t) t1;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 249u);
        l6 = vader_vm_narrow_code(((uint8_t) t2.payload.i));
        if ((l6 >= INT32_C(0))) {
            t1 = vader_chk_add(usize, l4, l5);
            l7 = (size_t) (int64_t) t1;
            l8 = vader_vm_canonical(l0, l7);
            vader_vm_emit(l0, l1, INT32_C(105), l8, l6, INT32_C(0));
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l6 = vader_vm_canonical(l0, l4);
    l8 = ((int32_t) (size_t) l3);
    vader_vm_emit(l0, l1, INT32_C(107), l6, l8, INT32_C(0));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_vm_returns_void(void* l0, int32_t l1) {
    size_t l2;
    void* l3;
    vader_box_t l4;
    bool t0;
    int64_t t1;
    void* t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (!(t0)) {
        return false;
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
    t1 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l4.tag == 557u) {
        t2 = l4.payload.obj;
        return ((vader_struct_vader_bytecode_BcPrimitive_t*) t2)->f_val == INT32_C(16);
    }
    return false;
}

static vader_box_t vader_vm_retyped_int(vader_box_t l0, int64_t l1) {
    vader_box_t t0;
    if (l0.tag == 247u) {
        t0 = vader_box_i64(247u, l1);
        return t0;
    }
    if (l0.tag == 241u) {
        t0 = vader_box_bool(241u, l1 != INT64_C(0));
        return t0;
    }
    if (!(l0.tag == 242u)) {
        t0 = vader_box_i32(246u, ((int32_t) (int64_t) l1));
        return t0;
    }
    t0 = vader_box_i32(242u, (int32_t) ((uint32_t) (int32_t) ((int32_t) (int64_t) (l1 & INT64_C(4294967295)))));
    return t0;
}

static vader_box_t vader_vm_run_boxed(void* l0, void* l1, void* l2, size_t l3, size_t l4) {
    int64_t l5, l14;
    size_t l6, l7, l8, l10, l13, l17, l21;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    uint8_t l18;
    vader_box_t l22 = vader_box_null();
    int32_t l23;
    vader_string_t l24 = 0;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l22, &t2 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l9, &l11, &l12, &l15, &l16, &l19, &l20, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    t0 = vader_vm_operand_b(l5);
    t1 = ((int64_t) (int32_t) t0);
    l6 = (size_t) (int64_t) t1;
    t1 = vader_chk_add(usize, l4, l6);
    l6 = (size_t) (int64_t) t1;
    t0 = vader_vm_operand_c(l5);
    t1 = ((int64_t) (int32_t) (t0 & INT32_C(255)));
    l7 = (size_t) (int64_t) t1;
    t0 = vader_vm_operand_c(l5);
    t1 = ((int64_t) (int32_t) (t0 >> INT32_C(8)));
    l8 = (size_t) (int64_t) t1;
    l9 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_scratch;
    vader_vm_reserve_stack(l9, l7);
    l10 = (size_t) 0;
    while ((l10 < l7)) {
        l11 = ((vader_struct_vader_vm_Frame_t*) l9)->f_payload;
        l12 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_bits;
        t1 = vader_chk_add(usize, l6, l10);
        l13 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l13)
        l14 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l13];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l10] = (int64_t) l14;
        l15 = ((vader_struct_vader_vm_Frame_t*) l9)->f_tag;
        l16 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_tags;
        t1 = vader_chk_add(usize, l6, l10);
        l17 = (size_t) (int64_t) t1;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l17)
        t2 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l17, 249u);
        l18 = ((uint8_t) t2.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l18;
        l19 = ((vader_struct_vader_vm_Frame_t*) l9)->f_stack;
        l20 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_refs;
        t1 = vader_chk_add(usize, l6, l10);
        l21 = (size_t) (int64_t) t1;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l20);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l21)
        l22 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l21];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l10] = l22;
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_vm_Frame_t*) l9)->f_sp = l7;
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
    l23 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3];
    ((vader_struct_vader_vm_Frame_t*) l9)->f_pc = l23;
    l11 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run;
    l12 = ((vader_struct_vader_vm_RegFunction_t*) l2)->f_boxed;
    t0 = vader_vm_operand_a(l5);
    t1 = ((int64_t) (int32_t) t0);
    l7 = (size_t) (int64_t) t1;
    vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
    l22 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
    l24 = ((vader_struct_vader_vm_RegFunction_t*) l2)->f_name;
    l22 = vader_vm_apply_boxed(l0, l11, l22, l9, l24);
    if (l22.tag == 1126u) {
        t3 = l22.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = (size_t) 0;
    while ((l7 < l8)) {
        l11 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_bits;
        t1 = vader_chk_add(usize, l6, l7);
        l10 = (size_t) (int64_t) t1;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l9)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
        l5 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l7];
        vader_array_t* _a10_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
        ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10] = (int64_t) l5;
        l12 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_tags;
        t1 = vader_chk_add(usize, l6, l7);
        l13 = (size_t) (int64_t) t1;
        vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l9)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
        t2 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l7, 249u);
        l18 = ((uint8_t) t2.payload.i);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l13)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l13] = (uint8_t) (int32_t) (uint8_t) l18;
        l15 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_refs;
        t1 = vader_chk_add(usize, l6, l7);
        l17 = (size_t) (int64_t) t1;
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l9)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
        l22 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l7];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
        vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l17] = l22;
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_run_defers(void* l0, void* l1, void* l2, void* l3, size_t l4, size_t l5, size_t l6, bool l7) {
    int32_t l8, l9;
    size_t l10, l11, l15;
    void* l12 = NULL;
    void* l18 = NULL;
    int64_t l13;
    uint64_t l14;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null();
    int64_t t0;
    size_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l16, &l17 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l12, &l18, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l3)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    l8 = vader_vm_operand_a(t0);
    if ((l8 <= INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l3)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
    l10 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
    t0 = ((int64_t) (int32_t) l8);
    l11 = (size_t) (int64_t) t0;
    if ((l10 < l11)) {
        l12 = std_core_new_byte_buffer((size_t) 107);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l12, l10, 1531u);
        l13 = ((int64_t) (int32_t) l8);
        l10 = std_core_write_int(l12, l10, l13);
        l10 = std_core_write_string_at(l12, l10, 290u);
        t1 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
        t0 = ((int64_t) (size_t) t1);
        l14 = (uint64_t) (int64_t) t0;
        l10 = std_core_write_unsigned(l12, l10, l14);
        l10 = std_core_write_string_at(l12, l10, 249u);
        l13 = ((int64_t) (int32_t) l9);
        l10 = std_core_write_int(l12, l10, l13);
        t2 = std_core_finish_buffer(l12, l10);
        vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a2_obj, 1126u);
        _a2_obj->f_message = t2;
        t3 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
    t0 = ((int64_t) (int32_t) l8);
    l11 = (size_t) (int64_t) t0;
    t0 = vader_chk_sub(usize, l10, l11);
    l10 = (size_t) (int64_t) t0;
    vader_array_t* _a3_arr = vader_array_new(167u, 0u, 13u, 1103u);
    l12 = (void*) _a3_arr;
    l11 = l10;
    l15 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
    while ((l11 < l15)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l16 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l11];
        l17 = vader_vm_defer_thunk(l0, l16, l9, 1529u);
        if (l17.tag == 1126u) {
            t3 = l17.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = l17.payload.obj;
        vader_array_push((vader_array_t*) l12, vader_ref_box(l18));
        t0 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t0;
    }
    ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count = l10;
    l10 = ((vader_array_t*) l12)->length;
    while ((l10 > INT64_C(0))) {
        t0 = vader_chk_sub(usize, l10, INT64_C(1));
        l10 = (size_t) (int64_t) t0;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        l18 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l10);
        t0 = vader_chk_add(usize, l4, INT64_C(1));
        l11 = (size_t) (int64_t) t0;
        l16 = vader_vm_run_thunk(l0, l1, l2, l18, l5, l6, l11, l7);
        if (!(l16.tag == 0u)) {
            t3 = l16.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_run_thunk(void* l0, void* l1, void* l2, void* l3, size_t l4, size_t l5, size_t l6, bool l7) {
    size_t l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_chk_add(usize, l4, INT64_C(1));
    l8 = (size_t) (int64_t) t0;
    vader_vm_reserve_registers(l2, l8);
    if (((vader_struct_vader_vm_FnVal_t*) l3)->f_env.tag == 0u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4] = (uint8_t) INT32_C(5);
        l10 = ((vader_struct_vader_vm_FnVal_t*) l3)->f_function_index;
        t1 = vader_vm_reg_call(l0, l1, l2, l10, l4, l5, l6, l7);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_vm_FnVal_t*) l3)->f_env;
    vader_vm_set_register(l2, l4, l9);
    l10 = ((vader_struct_vader_vm_FnVal_t*) l3)->f_function_index;
    t1 = vader_vm_reg_call(l0, l1, l2, l10, l4, l5, l6, l7);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_scalar_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    int64_t l2;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    double t3;
    bool t4;
    uint32_t t5;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 620u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a0_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a0_obj, 1121u);
        _a0_obj->f_bits = ((int64_t) (int32_t) t1);
        _a0_obj->f_tag = (uint8_t) 0;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 640u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a1_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a1_obj, 1121u);
        _a1_obj->f_bits = t2;
        _a1_obj->f_tag = (uint8_t) 1;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 601u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a2_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a2_obj, 1121u);
        _a2_obj->f_bits = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t3 }).__vu);
        _a2_obj->f_tag = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 571u) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        if (t4) {
            l2 = INT64_C(1);
        } else {
            l2 = INT64_C(0);
        }
        vader_struct_vader_vm_Scalar_t* _a3_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a3_obj, 1121u);
        _a3_obj->f_bits = l2;
        _a3_obj->f_tag = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 586u) {
        t0 = l0.payload.obj;
        t5 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a4_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a4_obj, 1121u);
        _a4_obj->f_bits = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        _a4_obj->f_tag = (uint8_t) 4;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 671u) {
        vader_struct_vader_vm_Scalar_t* _a5_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a5_obj, 1121u);
        _a5_obj->f_bits = INT64_C(0);
        _a5_obj->f_tag = (uint8_t) 5;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 689u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_scratch_frame(void) {
    size_t l0;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = (size_t) 8;
    l1 = (void*) &vader_fn_static___lambda_vader_vm_3;
    l1 = std_core_filled__ArrayVal___bool___char___ErrorVal___f64___FnVal___i32___i64___NullVal___ObjVal___string___StructVal___TypeVal(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 8u, 247u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l0);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 1u, 1u, 249u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(5);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l0);
    l3 = (void*) _a3_arr;
    vader_struct_vader_vm_Frame_t* _a4_obj = (vader_struct_vader_vm_Frame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Frame_t));
    vader_obj_header_init(_a4_obj, 1104u);
    _a4_obj->f_stack = l1;
    _a4_obj->f_payload = l2;
    _a4_obj->f_tag = l3;
    _a4_obj->f_sp = (size_t) 0;
    _a4_obj->f_pc = INT32_C(0);
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_serialise_mirror(void* l0, size_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7) {
    vader_string_t l8 = 0;
    vader_string_t l15 = 0;
    vader_string_t l35 = 0;
    vader_string_t l36 = 0;
    size_t l9, l12, l16, l17, l18, l20, l21, l22, l37, l38, l40;
    void* l10 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    int64_t l11, l27, l39;
    vader_box_t l13 = vader_box_null(), l14 = vader_box_null(), l26 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null(), l34 = vader_box_null();
    int32_t l25;
    bool l31, l32, l33;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2, t3;
    vader_box_t* gc_roots[7] = { &l13, &l14, &l26, &l28, &l29, &l30, &l34 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l4, &l10, &l19, &l23, &l24, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l6, &l8, &l15, &l35, &l36, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        l8 = l6;
        l9 = vader_host_std_core_byte_len(l8);
        l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(83) + l9));
        l9 = (size_t) 0;
        l9 = std_core_write_string_at(l10, l9, 1636u);
        l9 = std_core_write_string_at(l10, l9, l8);
        l9 = std_core_write_string_at(l10, l9, 888u);
        l11 = ((int64_t) (int32_t) l5);
        l9 = std_core_write_int(l10, l9, l11);
        l9 = std_core_write_string_at(l10, l9, 376u);
        l11 = ((int64_t) 16);
        l9 = std_core_write_int(l10, l9, l11);
        t0 = std_core_finish_buffer(l10, l9);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1126u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_bytecode_c_struct_layout(l3, l4);
    l9 = (size_t) 0;
    l12 = ((vader_array_t*) l3)->length;
    while ((l9 < l12)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l13 = vader_bytecode_nested_mirror(t1, l4);
        if (l13.tag == 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l28 = vader_bytecode_c_field_width(t1, l4);
            if (l28.tag == 0u) {
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                continue;
            }
            l27 = ((int64_t) l28.payload.i);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l29 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l9];
            if (l29.tag == 247u) {
                l31 = true;
            } else {
                l31 = l29.tag == 246u;
            }
            if (l31) {
                l32 = true;
            } else {
                l32 = l29.tag == 241u;
            }
            if (l32) {
                l33 = true;
            } else {
                l33 = l29.tag == 242u;
            }
            if (l33) {
                l30 = vader_vm_read_scalar_word(l29, l5, 0u);
            } else {
                l34 = l29;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                l35 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
                l36 = concat_5(1636u, l6, 905u, l35, 865u);
                l30 = vader_vm_read_scalar_word(l34, l5, l36);
            }
            if (l30.tag == 1126u) {
                t1 = l30.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l10)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            t2 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9];
            t3 = t2;
            l37 = (size_t) (int64_t) t3;
            t2 = vader_chk_add(usize, l1, l37);
            l38 = (size_t) (int64_t) t2;
            l39 = ((int64_t) l30.payload.i);
            t2 = l27;
            l40 = (size_t) (int64_t) t2;
            vader_vm_write_little_endian(l0, l38, l39, l40);
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
            continue;
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        l14 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l9];
        if (!(l14.tag == 1123u)) {
            l8 = l6;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            l15 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
            l16 = vader_host_std_core_byte_len(l8);
            l17 = vader_host_std_core_byte_len(l15);
            t2 = (l16 + l17);
            l18 = (size_t) (int64_t) t2;
            l19 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(91) + l18));
            l20 = (size_t) 0;
            l20 = std_core_write_string_at(l19, l20, 1636u);
            l20 = std_core_write_string_at(l19, l20, l8);
            l20 = std_core_write_string_at(l19, l20, 888u);
            l11 = ((int64_t) (int32_t) l5);
            l20 = std_core_write_int(l19, l20, l11);
            l20 = std_core_write_string_at(l19, l20, 375u);
            l20 = std_core_write_string_at(l19, l20, l15);
            l20 = std_core_write_string_at(l19, l20, 980u);
            t0 = std_core_finish_buffer(l19, l20);
            vader_struct_vader_vm_Trap_t* _a8_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a8_obj, 1126u);
            _a8_obj->f_message = t0;
            t1 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l10)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
        t2 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9];
        t3 = t2;
        l21 = (size_t) (int64_t) t3;
        t2 = vader_chk_add(usize, l1, l21);
        l22 = (size_t) (int64_t) t2;
        l23 = l14.payload.obj;
        t1 = l13.payload.obj;
        l24 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
        l25 = vader_chk_add(i32, l7, INT32_C(1));
        l26 = vader_vm_serialise_mirror(l0, l22, l23, l24, l4, l5, l6, l25);
        if (l26.tag == 1126u) {
            t1 = l26.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm_set_bool(void* l0, void* l1, size_t l2, int32_t l3, bool l4) {
    size_t l5;
    int64_t l6;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l2, l5);
    l5 = (size_t) (int64_t) t0;
    if (l4) {
        l6 = INT64_C(1);
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(3);
    return;
}

static vader_box_t vader_vm_set_element(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, size_t l6, int32_t l7) {
    size_t l8, l14;
    void* l9 = NULL;
    void* l11 = NULL;
    vader_box_t l10 = vader_box_null();
    int32_t l12;
    bool l13;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[5] = { &l0, &l5, &l9, &l11, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((int64_t) (int32_t) l2);
    l8 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l8);
    l8 = (size_t) (int64_t) t0;
    l10 = vader_vm_array_at(l0, l8);
    if (l10.tag == 0u) {
        t1 = vader_vm_element_trap(l0, l1, l2, l3, l5, l6, l7);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    t0 = ((int64_t) (int32_t) l3);
    l8 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l8);
    l8 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
    l12 = ((int32_t) (int64_t) t0);
    if ((l12 < INT32_C(0))) {
        l13 = true;
    } else {
        t0 = ((int64_t) (int32_t) l12);
        l8 = (size_t) (int64_t) t0;
        l14 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_length;
        l13 = (l8 >= l14);
    }
    if (!(l13)) {
        vader_vm_own_bytes(l9);
        l11 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_elements;
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_offset;
        t0 = ((int64_t) (int32_t) l12);
        l14 = (size_t) (int64_t) t0;
        t0 = vader_chk_add(usize, l8, l14);
        l8 = (size_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) l4);
        l14 = (size_t) (int64_t) t0;
        t0 = vader_chk_add(usize, l1, l14);
        l14 = (size_t) (int64_t) t0;
        l10 = vader_vm_register_value(l0, l14);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8] = l10;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_vm_element_trap(l0, l1, l2, l3, l5, l6, l7);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_set_f64(void* l0, void* l1, size_t l2, int32_t l3, double l4) {
    size_t l5;
    int64_t l6;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l2, l5);
    l5 = (size_t) (int64_t) t0;
    l6 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l4 }).__vu);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(2);
    return;
}

static vader_box_t vader_vm_set_field(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, size_t l6) {
    void* l7 = NULL;
    void* l14 = NULL;
    size_t l8, l11, l15, l16;
    vader_box_t l9 = vader_box_null(), l17 = vader_box_null();
    bool l10;
    int64_t l12;
    uint64_t l13;
    int32_t l18;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l9, &l17 };
    void** gc_raw_roots[5] = { &l0, &l5, &l7, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs;
    t0 = ((int64_t) (int32_t) l2);
    l8 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l8);
    l8 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    l9 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
    if (l9.tag == 1123u) {
        if ((l4 < INT32_C(0))) {
            l10 = true;
        } else {
            t0 = ((int64_t) (int32_t) l4);
            l8 = (size_t) (int64_t) t0;
            t1 = l9.payload.obj;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields)->length;
            l10 = (l8 >= l11);
        }
        if (!(l10)) {
            t1 = l9.payload.obj;
            l14 = ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields;
            t0 = ((int64_t) (int32_t) l4);
            l15 = (size_t) (int64_t) t0;
            t0 = ((int64_t) (int32_t) l3);
            l16 = (size_t) (int64_t) t0;
            t0 = vader_chk_add(usize, l1, l16);
            l16 = (size_t) (int64_t) t0;
            l17 = vader_vm_register_value(l0, l16);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l15)
            vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l15] = l17;
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t1 = l9.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields)->length;
        l7 = std_core_new_byte_buffer((size_t) 118);
        l11 = (size_t) 0;
        l11 = std_core_write_string_at(l7, l11, 2305u);
        l12 = ((int64_t) (int32_t) l4);
        l11 = std_core_write_int(l7, l11, l12);
        l11 = std_core_write_string_at(l7, l11, 113u);
        t0 = ((int64_t) (size_t) l8);
        l13 = (uint64_t) (int64_t) t0;
        l11 = std_core_write_unsigned(l7, l11, l13);
        l11 = std_core_write_string_at(l7, l11, 70u);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l5)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l12 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l7, l11, l12);
        t3 = std_core_finish_buffer(l7, l11);
        vader_struct_vader_vm_Trap_t* _a3_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a3_obj, 1126u);
        _a3_obj->f_message = t3;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l5)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
    l18 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
    l9 = vader_vm_read_struct(l9, l18, 2307u);
    if (l9.tag == 1126u) {
        t1 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm_set_i32(void* l0, void* l1, size_t l2, int32_t l3, int32_t l4) {
    size_t l5;
    int64_t l6;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l2, l5);
    l5 = (size_t) (int64_t) t0;
    l6 = ((int64_t) (int32_t) l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(0);
    return;
}

static void vader_vm_set_i64(void* l0, void* l1, size_t l2, int32_t l3, int64_t l4) {
    size_t l5;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l2, l5);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) l4;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(1);
    return;
}

static void vader_vm_set_integer(void* l0, void* l1, size_t l2, int32_t l3, uint8_t l4, int64_t l5) {
    int32_t l6;
    bool t0;
    t0 = vader_bytecode_is_64_bit_int_val(l4);
    if (t0) {
        vader_vm_set_i64(l0, l1, l2, l3, l5);
        return;
    }
    l6 = ((int32_t) (int64_t) l5);
    vader_vm_set_i32(l0, l1, l2, l3, l6);
    return;
}

static void vader_vm_set_register(void* l0, size_t l1, vader_box_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t t0;
    double t1;
    bool t2;
    uint32_t t3;
    if (l2.tag == 246u) {
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        t0 = ((int32_t) l2.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        return;
    }
    if (l2.tag == 247u) {
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        l4 = ((int64_t) l2.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(1);
    } else if ((l2.tag == 239u || l2.tag == 240u)) {
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        t1 = ((double) l2.payload.f);
        l4 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(2);
    } else if (l2.tag == 241u) {
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        t2 = l2.payload.b;
        if (t2) {
            l4 = INT64_C(1);
        } else {
            l4 = INT64_C(0);
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(3);
    } else if (l2.tag == 242u) {
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        t3 = ((uint32_t) l2.payload.i);
        l4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
        ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
        ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(4);
    } else if (l2.tag == 1110u) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l1)
        ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(5);
    } else {
        l3 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs;
        l5 = l2;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l1)
        vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l1] = l5;
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l1)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(6);
    }
    return;
}

static bool vader_vm_skips_else(void* l0, size_t l1) {
    bool l2;
    size_t l3, l4;
    void* l5;
    vader_box_t t0;
    int64_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (t0.tag == 655u) {
        t1 = vader_chk_add(usize, l1, INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
        l2 = (l3 < l4);
    } else {
        l2 = false;
    }
    if (l2) {
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
        t1 = vader_chk_add(usize, l1, INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        return t0.tag == 595u;
    }
    return false;
}

static bool vader_vm_slot_in_scope(void* l0, void* l1, size_t l2, int32_t l3) {
    int32_t l4;
    int32_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    if ((t0 < INT32_C(0))) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2];
    if ((t0 <= l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
        return (l3 <= l4);
    }
    return false;
}

static int32_t vader_vm_slot_touched_by(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 665u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 666u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 667u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 664u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
    return t1;
}

static uint8_t vader_vm_slot_valtype(void* l0, int32_t l1) {
    size_t l2, l3;
    int64_t t0;
    vader_box_t t1;
    void* t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    if ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 249u);
        return ((uint8_t) t1.payload.i);
    }
    t0 = vader_chk_sub(usize, l3, l2);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    if (!((l2 < l3))) {
        return (uint8_t) 2;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    return ((vader_struct_vader_bytecode_BcLocal_t*) t2)->f_val;
}

static void vader_vm_stack_grow(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload, INT64_C(0));
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag, INT32_C(5));
    l1 = ((vader_struct_vader_vm_Frame_t*) l0)->f_stack;
    vader_struct_vader_vm_NullVal_t* _a0_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
    vader_obj_header_init(_a0_obj, 1110u);
    l2 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_stack_i32(void* l0, size_t l1, vader_string_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    void* t3 = NULL;
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 249u);
    t1 = vader_vm_is_i32_tag(((uint8_t) t0.payload.i));
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
        t0 = vader_box_i32(246u, ((int32_t) (int64_t) t2));
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm_peek_val(l0, l1);
    l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = concat_3(l2, 8u, l3);
    l4 = vader_vm_read_i32(l4, l5, l6);
    if (l4.tag == 1126u) {
        t3 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((int32_t) l4.payload.i);
    t0 = vader_box_i32(246u, t4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_stack_obj(void* l0, size_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    int32_t l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_vm_peek_val(l0, l1);
    if (!(l3.tag == 1111u)) {
        l4 = l3;
        l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l6 = concat_2(l2, 124u);
        t0 = vader_vm_read_obj(l4, l5, l6);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_stack_tags(void* l0, size_t l1, size_t l2) {
    size_t l3, l5;
    void* l4;
    int64_t t0, t1;
    vader_box_t t2;
    uint8_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l0)->f_depth);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    t1 = vader_chk_sub(usize, t0, l2);
    l3 = (size_t) (int64_t) t1;
    l4 = ((vader_struct_vader_vm_FunctionTags_t*) l0)->f_stack;
    l5 = ((vader_struct_vader_vm_FunctionTags_t*) l0)->f_deepest;
    t0 = vader_chk_mul(usize, l1, l5);
    t1 = vader_chk_add(usize, t0, l3);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 249u);
    t3 = ((uint8_t) t2.payload.i);
    return t3;
}

static bool vader_vm_step_should_stop(uint8_t l0, int32_t l1, int32_t l2) {
    bool l3;
    if (l0 == INT32_C(0)) {
        l3 = false;
        return l3;
    }
    if (l0 == INT32_C(2)) {
        l3 = true;
    } else if (l0 == INT32_C(1)) {
        l3 = (l2 <= l1);
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = (l2 < l1);
    }
    return l3;
}

static void vader_vm_stop_at_line(void* l0, void* l1, void* l2, void* l3, size_t l4, size_t l5) {
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l7;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11;
    vader_string_t l12 = 0;
    bool l13;
    uint8_t l14;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    t0 = ((vader_struct_vader_vm_RegFunction_t*) l3)->f_index;
    t1 = ((int64_t) (int32_t) t0);
    l7 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    l8 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_debug;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l3)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t0 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
    t1 = ((int64_t) (int32_t) t0);
    l7 = (size_t) (int64_t) t1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
    if (l9.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = l9.payload.obj;
    l10 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_line;
    l11 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_last_line;
    if (l10 == l11) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l10 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_line;
    ((vader_struct_vader_vm_DebugSession_t*) l2)->f_last_line = l10;
    l10 = ((int32_t) (size_t) l5);
    l8 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_controller;
    l12 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_file;
    l11 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_line;
    l13 = vader_vm_line_has_breakpoint(l8, l12, l11);
    if (!(l13)) {
        l14 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_mode;
        l11 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_depth;
        t3 = vader_vm_step_should_stop(l14, l11, l10);
        if (!(t3)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l13) {
        l12 = 1361u;
    } else {
        l12 = 2259u;
    }
    l6 = ((vader_struct_vader_vm_DebugController_t*) ((vader_struct_vader_vm_DebugSession_t*) l2)->f_controller)->f_on_pause;
    t2 = vader_vm_pause_context(l0, l1, l12, l4, l5);
    vader_fn_t* _a3_fnobj = (vader_fn_t*) l6;
    t4 = ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_ref_box(t2));
    l14 = ((uint8_t) t4.payload.i);
    ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_mode = l14;
    ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_depth = l10;
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_store_bytes_op(void* l0, size_t l1, uint64_t l2, vader_string_t l3) {
    size_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    int32_t l7, l8;
    void* l9 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l9, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(2));
    l4 = (size_t) (int64_t) t1;
    l5 = vader_vm_stack_i32(l0, l4, l3, 2067u);
    if (l5.tag == 1126u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    t1 = vader_chk_sub(usize, t0, INT64_C(3));
    l4 = (size_t) (int64_t) t1;
    l6 = vader_vm_stack_obj(l0, l4, l3);
    if (l6.tag == 1126u) {
        t2 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l5.payload.i);
    t2 = l6.payload.obj;
    l4 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_check_byte_range(l7, l1, l4, l3, l8);
    if (!(l5.tag == 1126u)) {
        t2 = l6.payload.obj;
        l9 = ((vader_struct_vader_vm_ObjVal_t*) t2)->f_bytes;
        l4 = ((size_t) l5.payload.i);
        vader_vm_write_le(l9, l4, l1, l2);
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        t1 = vader_chk_sub(usize, t0, INT64_C(3));
        l4 = (size_t) (int64_t) t1;
        ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l4;
        t3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l7 = vader_chk_add(i32, t3, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l7;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = l5.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_store_slot(void* l0, void* l1, size_t l2, int32_t l3, bool l4, int64_t l5) {
    size_t l6, l9;
    int32_t l7, l12, l13;
    int64_t l8;
    void* l10 = NULL;
    void* l14 = NULL;
    bool l11;
    size_t t0;
    int64_t t1;
    uint8_t t2;
    void* t3 = NULL;
    int32_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l10, &l14, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l6 = (size_t) (int64_t) t1;
    t2 = vader_vm_slot_valtype(l1, l3);
    l7 = vader_vm_narrow_code(t2);
    l8 = l5;
    l9 = (size_t) 0;
    while ((l9 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        if (((vader_struct_vader_vm_Pending_t*) t3)->f_kind == INT32_C(1)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            t4 = ((vader_struct_vader_vm_Pending_t*) t3)->f_register_v;
            if (t4 == l3) {
                vader_vm_materialise(l0, l2, l9);
                l8 = INT64_C(-1);
            }
        }
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
    if (((vader_struct_vader_vm_Pending_t*) l10)->f_kind == INT32_C(0)) {
        l11 = (l8 >= INT64_C(0));
    } else {
        l11 = false;
    }
    if (l11) {
        t1 = l8;
        l6 = (size_t) (int64_t) t1;
        l12 = vader_vm_operand_of(l0, l6, (size_t) 0);
        l13 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
        l11 = l12 == l13;
    } else {
        l11 = false;
    }
    if (l11) {
        l14 = ((vader_struct_vader_vm_Translation_t*) l0)->f_operands;
        t1 = l8;
        l6 = (size_t) (int64_t) t1;
        t1 = vader_chk_mul(usize, INT64_C(3), l6);
        l6 = (size_t) (int64_t) t1;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l3;
    } else if (((vader_struct_vader_vm_Pending_t*) l10)->f_kind == INT32_C(2)) {
        l12 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
        vader_vm_emit(l0, l2, INT32_C(1), l3, l12, INT32_C(0));
    } else {
        t4 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
        if (t4 != l3) {
            l12 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
            vader_vm_emit(l0, l2, INT32_C(0), l3, l12, INT32_C(0));
        }
    }
    if ((l7 >= INT32_C(0))) {
        vader_vm_emit(l0, l2, INT32_C(105), l3, l7, INT32_C(0));
    }
    t5 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
    if (l4) {
        l10 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
        vader_struct_vader_vm_Pending_t* _a4_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
        vader_obj_header_init(_a4_obj, 1116u);
        _a4_obj->f_kind = (uint8_t) 1;
        _a4_obj->f_register_v = l3;
        l14 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l10, vader_ref_box(l14));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm_string_array_to_value(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        t0 = vader_box_string(243u, l6);
        vader_array_push((vader_array_t*) l2, t0);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_array_t*) l2)->length;
    vader_struct_vader_vm_ArrayVal_t* _a3_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1098u);
    _a3_obj->f_type_id = l1;
    _a3_obj->f_elements = l2;
    _a3_obj->f_offset = (size_t) 0;
    _a3_obj->f_length = l3;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_string_constant(void* l0, void* l1, size_t l2, void* l3) {
    size_t l4;
    int32_t l5, l9;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l1)->f_stack)->length;
    l5 = vader_vm_canonical(l1, l4);
    l6 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l1)->f_code)->f_values;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings;
    t0 = ((vader_struct_vader_bytecode_StringConst_t*) l3)->f_index;
    t1 = ((int64_t) (int32_t) t0);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
    l8 = t2.payload.s;
    t2 = vader_box_string(243u, l8);
    vader_array_push((vader_array_t*) l6, t2);
    t3 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l1)->f_code)->f_values)->length;
    t1 = vader_chk_sub(usize, t3, INT64_C(1));
    l9 = ((int32_t) (int64_t) t1);
    vader_vm_emit(l1, l2, INT32_C(109), l5, l9, INT32_C(0));
    vader_vm_push_register(l1, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_struct_new_effect(void* l0, int32_t l1) {
    size_t l2;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    size_t t3;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
    t1 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l4.tag == 561u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = l4.payload.obj;
    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields)->length;
    t2 = vader_vm_effect(t3, (size_t) 1);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_tags_of_type(void* l0, int32_t l1) {
    size_t l2;
    void* l3;
    bool t0;
    int64_t t1;
    vader_box_t t2;
    uint8_t t3;
    l2 = ((vader_array_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_type_tags)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (t0) {
        l3 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_type_tags;
        t1 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l2, 249u);
        t3 = ((uint8_t) t2.payload.i);
        return t3;
    }
    return (uint8_t) 127;
}

static uint8_t vader_vm_tags_of_val(uint8_t l0) {
    uint8_t l1;
    bool l2;
    int32_t t0;
    if (l0 == INT32_C(0)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(2);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(5);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        t0 = (INT32_C(1) | INT32_C(16));
        l1 = (uint8_t) (int32_t) t0;
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(8);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(9);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(17);
    }
    if (l2) {
        t0 = (INT32_C(2) | INT32_C(1));
        l1 = (uint8_t) (int32_t) t0;
    } else {
        if (l0 == INT32_C(10)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(11);
        }
        if (l2) {
            l1 = (uint8_t) 4;
        } else if (l0 == INT32_C(12)) {
            l1 = (uint8_t) 8;
        } else if (l0 == INT32_C(13)) {
            l1 = (uint8_t) 16;
        } else if (l0 == INT32_C(15)) {
            l1 = (uint8_t) 32;
        } else {
            if (l0 == INT32_C(14)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(18);
            }
            if (l2) {
                l1 = (uint8_t) 64;
            } else if (l0 == INT32_C(16)) {
                l1 = (uint8_t) 0;
            } else {
                if (!(l0 == INT32_C(19))) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l1 = (uint8_t) 127;
            }
        }
    }
    return l1;
}

static bool vader_vm_tags_within(uint8_t l0, uint8_t l1) {
    return (l0 | l1) == l1;
}

static bool vader_vm_trait_implemented_by(void* l0, vader_string_t l1, int32_t l2) {
    size_t l3, l4, l6, l7;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    int64_t t3;
    bool t4;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_impl_table)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_impl_table);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_bytecode_ImplEntry_t*) t0)->f_struct_type_index;
        if (t1 == l2) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_impl_table);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t2 = ((vader_struct_vader_bytecode_ImplEntry_t*) t0)->f_trait_name;
            if (t2 == l1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    l5 = concat_2(l1, 309u);
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        t2 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_key;
        t4 = std_string_starts_with(t2, l5);
        if (t4) {
            l6 = (size_t) 0;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
            l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries)->length;
            while ((l6 < l7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
                t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
                t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t0)->f_receiver_type_index;
                if (t1 == l2) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                t3 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t3;
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static size_t vader_vm_transfer(void* l0, vader_box_t l1, void* l2, size_t l3, size_t l4, void* l5) {
    uint8_t l6, l13;
    size_t l7, l8, l11, l12;
    vader_box_t l9 = vader_box_null();
    void* l10 = NULL;
    int64_t t0, t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    int32_t t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l1, &l9, &t2 };
    void** gc_raw_roots[5] = { &l0, &l2, &l5, &l10, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l4 > INT64_C(0))) {
        t0 = vader_chk_add(usize, l3, l4);
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 249u);
        l6 = ((uint8_t) t2.payload.i);
    } else {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_vm_StackEffect_t*) l5)->f_pops;
    t0 = vader_chk_sub(usize, l4, l7);
    l7 = (size_t) (int64_t) t0;
    if (l1.tag == 666u) {
        t3 = l1.payload.obj;
        t4 = ((vader_struct_vader_bytecode_LocalSet_t*) t3)->f_slot;
        t0 = ((int64_t) (int32_t) t4);
        l8 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    } else if (l1.tag == 667u) {
        t3 = l1.payload.obj;
        t4 = ((vader_struct_vader_bytecode_LocalTee_t*) t3)->f_slot;
        t0 = ((int64_t) (int32_t) t4);
        l8 = (size_t) (int64_t) t0;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    }
    l9 = vader_vm_call_results(l0, l1);
    if (l9.tag == 0u) {
        t5 = ((vader_struct_vader_vm_StackEffect_t*) l5)->f_pushes;
        if (t5 == INT64_C(1)) {
            t0 = vader_chk_add(usize, l3, l7);
            l11 = (size_t) (int64_t) t0;
            l13 = vader_vm_pushed_tags(l0, l1, l2, l6);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
            ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l11] = (uint8_t) (int32_t) (uint8_t) l13;
        }
    } else {
        t0 = vader_chk_add(usize, l3, l7);
        l8 = (size_t) (int64_t) t0;
        l10 = l9.payload.obj;
        l11 = ((vader_array_t*) l10)->length;
        l12 = (size_t) 0;
        while ((l12 < l11)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l12, 249u);
            l6 = ((uint8_t) t2.payload.i);
            if (l6 != INT32_C(16)) {
                l13 = vader_vm_tags_of_val(l6);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l13;
                t0 = vader_chk_add(usize, l8, INT64_C(1));
                l8 = (size_t) (int64_t) t0;
            }
            t0 = (l12 + INT64_C(1));
            l12 = (size_t) (int64_t) t0;
        }
    }
    l8 = ((vader_struct_vader_vm_StackEffect_t*) l5)->f_pushes;
    t0 = vader_chk_add(usize, l7, l8);
    { size_t __vret = (size_t) (int64_t) t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_translate_function(void* l0, int32_t l1, void* l2, bool l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    size_t l5, l6, l7, l20, l21, l24, l25;
    vader_string_t l10 = 0;
    int64_t l22;
    int32_t l23, l26, l27, l29;
    vader_box_t l28 = vader_box_null();
    int64_t t0, t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    size_t t4;
    void* t5 = NULL;
    uint64_t t6;
    vader_box_t* gc_roots[2] = { &l28, &t2 };
    void** gc_raw_roots[15] = {
        &l0, &l2, &l4, &l8, &l9, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &t5,
    };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params)->length;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_locals)->length;
    t0 = vader_chk_add(usize, l6, l7);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 8u, 247u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 1u, 249u);
    l9 = (void*) _a2_arr;
    vader_vm_collect_constants(l4, l8, l9);
    l7 = ((vader_array_t*) l8)->length;
    t0 = vader_chk_add(usize, l6, l7);
    l7 = (size_t) (int64_t) t0;
    l10 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 246u);
    l11 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 8u, 247u);
    l12 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l13 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 1u, 249u);
    l14 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(205u, 0u, 0u, 1642u);
    l15 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(187u, 0u, 13u, 1320u);
    l16 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(51u, 0u, 13u, 711u);
    l17 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 246u);
    l18 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(13u, 0u, 0u, 243u);
    l19 = (void*) _a11_arr;
    l20 = ((vader_struct_vader_vm_FunctionTags_t*) l2)->f_deepest;
    t0 = vader_chk_add(usize, l7, l20);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    l20 = (size_t) (int64_t) t1;
    l21 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params)->length;
    vader_struct_vader_vm_RegFunction_t* _a12_obj = (vader_struct_vader_vm_RegFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RegFunction_t));
    vader_obj_header_init(_a12_obj, 1117u);
    _a12_obj->f_name = l10;
    _a12_obj->f_index = l1;
    _a12_obj->f_ops = l11;
    _a12_obj->f_words = l12;
    _a12_obj->f_origin = l13;
    _a12_obj->f_kinds = l14;
    _a12_obj->f_consts = l8;
    _a12_obj->f_const_tags = l9;
    _a12_obj->f_values = l15;
    _a12_obj->f_boxed = l16;
    _a12_obj->f_virtuals = l17;
    _a12_obj->f_virtual_rows = l18;
    _a12_obj->f_texts = l19;
    _a12_obj->f_registers = l20;
    _a12_obj->f_params = l21;
    _a12_obj->f_slots = l6;
    l8 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(14u, 0u, 7u, 246u);
    l9 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(174u, 0u, 13u, 1116u);
    l11 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(15u, 0u, 8u, 247u);
    l12 = (void*) _a15_arr;
    l13 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_source_pc;
    vader_struct_vader_vm_Translation_t* _a16_obj = (vader_struct_vader_vm_Translation_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Translation_t));
    vader_obj_header_init(_a16_obj, 1125u);
    _a16_obj->f_code = l8;
    _a16_obj->f_operands = l9;
    _a16_obj->f_stack = l11;
    _a16_obj->f_stack_base = l7;
    _a16_obj->f_retarget = INT64_C(-1);
    _a16_obj->f_jumps = l12;
    _a16_obj->f_source_pc = l13;
    l8 = (void*) _a16_obj;
    l9 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_jump_table, l5);
    vader_array_t* _a17_arr = vader_array_new(15u, 1u, 8u, 247u);
    ((int64_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (int64_t) INT64_C(0);
    l11 = (void*) _a17_arr;
    t0 = vader_chk_add(usize, l5, INT64_C(1));
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l11, (size_t) l6);
    l11 = (void*) _a18_arr;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
        t2 = vader_box_bool(241u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l6]);
        t3 = t2.payload.b;
        if (t3) {
            vader_vm_flush(l8, l6);
        }
        t4 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l8)->f_code)->f_ops)->length;
        l22 = ((int64_t) (size_t) t4);
        vader_array_t* _a20_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
        ((int64_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (int64_t) l22;
        vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l2)->f_depth);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
        t0 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6];
        if ((t0 < INT64_C(0))) {
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        vader_array_t* _a22_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l6)
        t2 = vader_box_bool(241u, ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l6]);
        t3 = t2.payload.b;
        if (t3) {
            vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l2)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
            t0 = ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6];
            t1 = t0;
            l7 = (size_t) (int64_t) t1;
            vader_vm_reset_stack(l8, l7);
        }
        if (l3) {
            l20 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_debug)->length;
            if ((l6 < l20)) {
                vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_debug);
                VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
                t2 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l6);
                if (!(t2.tag == 0u)) {
                    vader_vm_emit(l8, l6, INT32_C(123), INT32_C(0), INT32_C(0), INT32_C(0));
                }
            }
        }
        t3 = vader_vm_translate_op(l0, l4, l2, l8, l6);
        if (!(t3)) {
            l10 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
            l23 = ((int32_t) (size_t) l6);
            vader_struct_vader_vm_VerifyError_t* _a25_obj = (vader_struct_vader_vm_VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VerifyError_t));
            vader_obj_header_init(_a25_obj, 1129u);
            _a25_obj->f_function = l10;
            _a25_obj->f_pc = l23;
            _a25_obj->f_message = 2048u;
            t5 = (void*) _a25_obj;
            { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    t4 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l8)->f_code)->f_ops)->length;
    l22 = ((int64_t) (size_t) t4);
    vader_array_t* _a26_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l5)
    ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l5] = (int64_t) l22;
    vader_vm_emit(l8, l5, INT32_C(106), INT32_C(-1), INT32_C(0), INT32_C(0));
    l5 = (size_t) 0;
    t4 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l8)->f_jumps)->length;
    t6 = vader_div_u64(t4, INT64_C(2));
    l6 = (size_t) (uint64_t) t6;
    while ((l5 < l6)) {
        l9 = ((vader_struct_vader_vm_Translation_t*) l8)->f_jumps;
        t0 = vader_chk_mul(usize, INT64_C(2), l5);
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a27_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
        t0 = ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l7];
        t1 = t0;
        l20 = (size_t) (int64_t) t1;
        l12 = ((vader_struct_vader_vm_Translation_t*) l8)->f_operands;
        t0 = vader_chk_mul(usize, INT64_C(3), l20);
        l21 = (size_t) (int64_t) t0;
        l13 = ((vader_struct_vader_vm_Translation_t*) l8)->f_jumps;
        t0 = vader_chk_mul(usize, INT64_C(2), l5);
        t1 = vader_chk_add(usize, t0, INT64_C(1));
        l24 = (size_t) (int64_t) t1;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l24)
        t0 = ((int64_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l24];
        t1 = t0;
        l25 = (size_t) (int64_t) t1;
        vader_array_t* _a29_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l25)
        t0 = ((int64_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l25];
        l23 = ((int32_t) (int64_t) t0);
        vader_array_t* _a30_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l21)
        ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l21] = (int32_t) l23;
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l8)->f_code)->f_ops)->length;
    while ((l5 < l6)) {
        l23 = vader_vm_operand_of(l8, l5, (size_t) 0);
        l26 = vader_vm_operand_of(l8, l5, (size_t) 1);
        l27 = vader_vm_operand_of(l8, l5, (size_t) 2);
        l28 = vader_vm_pack_operands(l23, l26, l27);
        if (l28.tag == 0u) {
            l10 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
            vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l8)->f_code)->f_origin);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
            l29 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5];
            vader_struct_vader_vm_VerifyError_t* _a32_obj = (vader_struct_vader_vm_VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VerifyError_t));
            vader_obj_header_init(_a32_obj, 1129u);
            _a32_obj->f_function = l10;
            _a32_obj->f_pc = l29;
            _a32_obj->f_message = 1271u;
            t5 = (void*) _a32_obj;
            { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l8)->f_code)->f_words;
        l22 = ((int64_t) l28.payload.i);
        vader_array_push_i64((vader_array_t*) l9, l22);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    { vader_box_t __vret = vader_ref_box(((vader_struct_vader_vm_Translation_t*) l8)->f_code); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_translate_module(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t l4, l5;
    int32_t l6;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l7, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(175u, 0u, 13u, 1117u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l4 < l5)) {
        l6 = ((int32_t) (size_t) l4);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l8 = vader_vm_translate_function(l0, l6, l7, l2);
        if (l8.tag == 1129u) {
            t0 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l8.payload.obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    vader_struct_vader_vm_RegModule_t* _a3_obj = (vader_struct_vader_vm_RegModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RegModule_t));
    vader_obj_header_init(_a3_obj, 1119u);
    _a3_obj->f_functions = l3;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_translate_op(void* l0, void* l1, void* l2, void* l3, size_t l4) {
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    int64_t l6, l12;
    int32_t l8, l9, l10, l11, l19, l20;
    void* l13 = NULL;
    void* l14 = NULL;
    bool l15, l17, l18;
    size_t l16, l22;
    uint8_t l21;
    vader_string_t l23 = 0;
    uint64_t l24;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    bool t5;
    uint8_t t6;
    vader_box_t* gc_roots[3] = { &l5, &l7, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l13, &l14, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l6 = ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget;
    ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = INT64_C(-1);
    l7 = vader_vm_binary_op(l5, l2, l4);
    if (!(l7.tag == 0u)) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_operand(l3, (size_t) 2);
        l10 = vader_vm_pop_to(l3, (size_t) 2);
        l11 = ((int32_t) l7.payload.i);
        vader_vm_emit(l3, l4, l11, l10, l9, l8);
        vader_vm_note_checked_kind(l3, l5);
        vader_vm_push_register(l3, l10);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l12 = t1;
        ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l7 = vader_vm_unary_op(l5, l2, l4);
    if (!(l7.tag == 0u)) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_pop_to(l3, (size_t) 1);
        l10 = ((int32_t) l7.payload.i);
        vader_vm_emit(l3, l4, l10, l9, l8, INT32_C(0));
        vader_vm_note_checked_kind(l3, l5);
        vader_vm_push_register(l3, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l12 = t1;
        ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 665u) {
        l13 = ((vader_struct_vader_vm_Translation_t*) l3)->f_stack;
        t2 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
        vader_struct_vader_vm_Pending_t* _a1_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
        vader_obj_header_init(_a1_obj, 1116u);
        _a1_obj->f_kind = (uint8_t) 1;
        _a1_obj->f_register_v = l8;
        l14 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 666u) {
        t2 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
        vader_vm_store_slot(l3, l1, l4, l8, false, l6);
    } else if (l5.tag == 667u) {
        t2 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalTee_t*) t2)->f_slot;
        vader_vm_store_slot(l3, l1, l4, l8, true, l6);
    } else if ((l5.tag == 571u || l5.tag == 586u || l5.tag == 601u || l5.tag == 620u || l5.tag == 640u || l5.tag == 671u)) {
        l7 = l5;
        vader_vm_push_constant(l3, l7);
    } else if (l5.tag == 594u) {
        t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack);
    } else if ((l5.tag == 569u || l5.tag == 598u || l5.tag == 668u || l5.tag == 673u || l5.tag == 676u)) {
        ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = l6;
    } else if ((l5.tag == 576u || l5.tag == 595u)) {
        if (l5.tag == 595u) {
            t1 = vader_chk_sub(usize, l4, INT64_C(1));
            l16 = (size_t) (int64_t) t1;
            l15 = vader_vm_skips_else(l1, l16);
        } else {
            l15 = false;
        }
        if (!(l15)) {
            vader_vm_flush(l3, l4);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            l8 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_vm_jump(l3, l4, INT32_C(86), INT32_C(0), INT32_C(0), l8);
        }
    } else if ((l5.tag == 577u || l5.tag == 655u)) {
        l13 = ((vader_struct_vader_vm_Translation_t*) l3)->f_stack;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l16 = (size_t) (int64_t) t1;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l16)
        l13 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l16);
        t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack);
        vader_vm_flush(l3, l4);
        l15 = vader_vm_skips_else(l1, l4);
        if (l5.tag == 577u) {
            l17 = true;
        } else {
            l17 = l15;
        }
        l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table;
        if (l15) {
            t1 = vader_chk_add(usize, l4, INT64_C(1));
            l16 = (size_t) (int64_t) t1;
        } else {
            l16 = l4;
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l16)
        l8 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l16];
        if (((vader_struct_vader_vm_Pending_t*) l13)->f_kind == INT32_C(0)) {
            l18 = (l6 >= INT64_C(0));
        } else {
            l18 = false;
        }
        if (l18) {
            t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops)->length;
            l12 = vader_chk_sub(i64, ((int64_t) (size_t) t0), INT64_C(1));
            l18 = l6 == l12;
        } else {
            l18 = false;
        }
        if (l18) {
            t1 = l6;
            l16 = (size_t) (int64_t) t1;
            l9 = vader_vm_operand_of(l3, l16, (size_t) 0);
            l10 = ((vader_struct_vader_vm_Pending_t*) l13)->f_register_v;
            l15 = l9 == l10;
        } else {
            l15 = false;
        }
        if (l15) {
            l14 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops;
            t1 = l6;
            l16 = (size_t) (int64_t) t1;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
            t4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l16];
            l7 = vader_vm_fused_branch(t4, l17);
        } else {
            l7 = vader_box_obj(0u, NULL);
        }
        if (l7.tag == 0u) {
            if (l17) {
                l19 = INT32_C(89);
            } else {
                l19 = INT32_C(88);
            }
            l20 = ((vader_struct_vader_vm_Pending_t*) l13)->f_register_v;
            vader_vm_jump(l3, l4, l19, l20, INT32_C(0), l8);
        } else {
            t1 = l6;
            l16 = (size_t) (int64_t) t1;
            l9 = vader_vm_operand_of(l3, l16, (size_t) 1);
            t1 = l6;
            l16 = (size_t) (int64_t) t1;
            l10 = vader_vm_operand_of(l3, l16, (size_t) 2);
            vader_vm_drop_last_op(l3);
            t2 = l7.payload.obj;
            t5 = ((vader_struct_vader_vm_FusedBranch_t*) t2)->f_swap;
            if (t5) {
                t2 = l7.payload.obj;
                l11 = ((vader_struct_vader_vm_FusedBranch_t*) t2)->f_op;
                vader_vm_jump(l3, l4, l11, l10, l9, l8);
            } else {
                t2 = l7.payload.obj;
                l11 = ((vader_struct_vader_vm_FusedBranch_t*) t2)->f_op;
                vader_vm_jump(l3, l4, l11, l9, l10, l8);
            }
        }
    } else if (l5.tag == 677u) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        t3 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 249u);
        l21 = ((uint8_t) t3.payload.i);
        t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature);
        if ((t0 > INT64_C(1))) {
            l13 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_results;
            vader_vm_return_many(l3, l4, l13);
        } else if (l21 == INT32_C(16)) {
            vader_vm_emit(l3, l4, INT32_C(106), INT32_C(-1), INT32_C(0), INT32_C(0));
        } else {
            t4 = vader_vm_narrow_code(l21);
            if ((t4 >= INT32_C(0))) {
                vader_vm_flush(l3, l4);
                t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
                t1 = vader_chk_sub(usize, t0, INT64_C(1));
                l16 = (size_t) (int64_t) t1;
                l8 = vader_vm_canonical(l3, l16);
                l9 = vader_vm_narrow_code(l21);
                vader_vm_emit(l3, l4, INT32_C(105), l8, l9, INT32_C(0));
                vader_vm_emit(l3, l4, INT32_C(106), l8, INT32_C(0), INT32_C(0));
            } else {
                l8 = vader_vm_operand(l3, (size_t) 1);
                vader_vm_emit(l3, l4, INT32_C(106), l8, INT32_C(0), INT32_C(0));
            }
        }
    } else if (l5.tag == 585u) {
        t2 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_CallIndirect_t*) t2)->f_type_id;
        l7 = vader_vm_fn_type_of(l0, l8);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l16 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) l13)->f_params)->length;
        vader_vm_flush(l3, l4);
        t1 = vader_chk_add(usize, l16, INT64_C(1));
        l22 = (size_t) (int64_t) t1;
        l8 = vader_vm_pop_to(l3, l22);
        t2 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallIndirect_t*) t2)->f_type_id;
        l10 = ((int32_t) (size_t) l16);
        vader_vm_emit(l3, l4, INT32_C(103), l9, l8, l10);
        l9 = ((vader_struct_vader_bytecode_BcFn_t*) l13)->f_return_type;
        t5 = vader_vm_returns_void(l0, l9);
        if (!(t5)) {
            vader_vm_push_register(l3, l8);
        }
    } else if (l5.tag == 711u) {
        t2 = l5.payload.obj;
        l23 = ((vader_struct_vader_bytecode_VirtualCall_t*) t2)->f_vtable_key;
        l16 = vader_vm_virtual_result_arity(l0, l23);
        if ((l16 > INT64_C(1))) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        vader_vm_flush(l3, l4);
        t2 = l5.payload.obj;
        t4 = ((vader_struct_vader_bytecode_VirtualCall_t*) t2)->f_parameter_count;
        t1 = ((int64_t) (int32_t) t4);
        l22 = (size_t) (int64_t) t1;
        l8 = vader_vm_pop_to(l3, l22);
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_virtuals;
        l14 = l5.payload.obj;
        vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_virtual_rows;
        l14 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
        t2 = l5.payload.obj;
        l23 = ((vader_struct_vader_bytecode_VirtualCall_t*) t2)->f_vtable_key;
        l9 = vader_vm_vtable_row_of(l14, l23);
        vader_array_push_i32((vader_array_t*) l13, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_virtuals)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l9 = ((int32_t) (int64_t) t1);
        t2 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_VirtualCall_t*) t2)->f_parameter_count;
        vader_vm_emit(l3, l4, INT32_C(104), l9, l8, l10);
        if (l16 == INT64_C(1)) {
            vader_vm_push_register(l3, l8);
        }
    } else if (l5.tag == 583u) {
        l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
        t2 = l5.payload.obj;
        t4 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
        t1 = ((int64_t) (int32_t) t4);
        l16 = (size_t) (int64_t) t1;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l16)
        t2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l16);
        l13 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature;
        l16 = vader_bytecode_bc_result_arity(l13);
        vader_vm_flush(l3, l4);
        l22 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l13)->f_params)->length;
        l8 = vader_vm_pop_to(l3, l22);
        t2 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
        vader_vm_emit(l3, l4, INT32_C(102), l9, l8, INT32_C(0));
        l22 = (size_t) 0;
        while ((l22 < l16)) {
            l9 = ((int32_t) (size_t) l22);
            l10 = vader_chk_add(i32, l8, l9);
            vader_vm_push_register(l3, l10);
            t1 = (l22 + INT64_C(1));
            l22 = (size_t) (int64_t) t1;
        }
    } else if (l5.tag == 678u) {
        t2 = l5.payload.obj;
        l7 = ((vader_struct_vader_bytecode_ReturnLit_t*) t2)->f_value;
        if (l7.tag == 689u) {
            l13 = l7.payload.obj;
            vader_vm_string_constant(l0, l3, l4, l13);
        } else {
            vader_vm_push_constant(l3, l7);
        }
        l8 = vader_vm_operand(l3, (size_t) 1);
        vader_vm_emit(l3, l4, INT32_C(106), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 584u) {
        l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
        t2 = l5.payload.obj;
        t4 = ((vader_struct_vader_bytecode_CallImport_t*) t2)->f_index;
        t1 = ((int64_t) (int32_t) t4);
        l16 = (size_t) (int64_t) t1;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l16)
        t2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l16);
        l13 = ((vader_struct_vader_bytecode_BcImport_t*) t2)->f_signature;
        vader_vm_flush(l3, l4);
        l16 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l13)->f_params)->length;
        l8 = vader_vm_pop_to(l3, l16);
        t2 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallImport_t*) t2)->f_index;
        vader_vm_emit(l3, l4, INT32_C(119), l9, l8, INT32_C(0));
        t6 = vader_bytecode_bc_single_result(l13);
        if (t6 != INT32_C(16)) {
            vader_vm_push_register(l3, l8);
        }
    } else if (l5.tag == 593u) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack);
        vader_vm_emit(l3, l4, INT32_C(121), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 592u) {
        vader_vm_flush(l3, l4);
        t2 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_DeferPopExec_t*) t2)->f_count;
        vader_vm_emit(l3, l4, INT32_C(122), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 613u) {
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts;
        l14 = std_core_new_byte_buffer((size_t) 87);
        l16 = (size_t) 0;
        l16 = std_core_write_string_at(l14, l16, 1698u);
        t1 = ((int64_t) (size_t) l4);
        l24 = (uint64_t) (int64_t) t1;
        l16 = std_core_write_unsigned(l14, l16, l24);
        l16 = std_core_write_string_at(l14, l16, 379u);
        l23 = std_core_finish_buffer(l14, l16);
        vader_array_push((vader_array_t*) l13, vader_box_string(243u, l23));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_vm_emit(l3, l4, INT32_C(120), l8, INT32_C(0), INT32_C(0));
        l16 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm_canonical(l3, l16);
        vader_vm_push_register(l3, l8);
    } else if (l5.tag == 710u) {
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts;
        t2 = l5.payload.obj;
        l23 = ((vader_struct_vader_bytecode_Unreachable_t*) t2)->f_reason;
        l23 = concat_2(2131u, l23);
        vader_array_push((vader_array_t*) l13, vader_box_string(243u, l23));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts)->length;
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t1);
        vader_vm_emit(l3, l4, INT32_C(120), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 664u) {
        l16 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm_canonical(l3, l16);
        t2 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalField_t*) t2)->f_slot;
        t2 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_LocalField_t*) t2)->f_field_index;
        vader_vm_emit(l3, l4, INT32_C(110), l8, l9, l10);
        vader_vm_push_register(l3, l8);
    } else if (l5.tag == 693u) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_pop_to(l3, (size_t) 1);
        t2 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_StructGet_t*) t2)->f_field_index;
        vader_vm_emit(l3, l4, INT32_C(110), l9, l8, l10);
        vader_vm_push_register(l3, l9);
    } else if (l5.tag == 695u) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_operand(l3, (size_t) 2);
        vader_vm_pop_to(l3, (size_t) 2);
        t2 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_StructSet_t*) t2)->f_field_index;
        vader_vm_emit(l3, l4, INT32_C(111), l9, l8, l10);
    } else if ((l5.tag == 538u || l5.tag == 660u || l5.tag == 661u || l5.tag == 662u)) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_operand(l3, (size_t) 2);
        l10 = vader_vm_pop_to(l3, (size_t) 2);
        if (l5.tag == 538u) {
            l11 = INT32_C(112);
        } else {
            l11 = INT32_C(114);
        }
        vader_vm_emit(l3, l4, l11, l10, l9, l8);
        vader_vm_push_register(l3, l10);
    } else if ((l5.tag == 545u || l5.tag == 684u || l5.tag == 685u || l5.tag == 686u)) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_operand(l3, (size_t) 2);
        l10 = vader_vm_operand(l3, (size_t) 3);
        vader_vm_pop_to(l3, (size_t) 3);
        if (l5.tag == 545u) {
            l11 = INT32_C(113);
        } else {
            l11 = INT32_C(115);
        }
        vader_vm_emit(l3, l4, l11, l10, l9, l8);
    } else if (l5.tag == 539u) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_pop_to(l3, (size_t) 1);
        vader_vm_emit(l3, l4, INT32_C(116), l9, l8, INT32_C(0));
        vader_vm_push_register(l3, l9);
    } else if (l5.tag == 541u) {
        l8 = vader_vm_operand(l3, (size_t) 1);
        l9 = vader_vm_operand(l3, (size_t) 2);
        vader_vm_pop_to(l3, (size_t) 2);
        vader_vm_emit(l3, l4, INT32_C(117), l9, l8, INT32_C(0));
    } else if (l5.tag == 689u) {
        l13 = l5.payload.obj;
        vader_vm_string_constant(l0, l3, l4, l13);
    } else {
        t5 = vader_vm_is_boxed(l5);
        if (!(t5)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = l5;
        l7 = vader_vm_effect_of(l0, l1, l7);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l16 = ((vader_struct_vader_vm_StackEffect_t*) l13)->f_pops;
        l22 = ((vader_struct_vader_vm_StackEffect_t*) l13)->f_pushes;
        vader_vm_boxed(l3, l4, l5, l16, l22);
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static int32_t vader_vm_truncate_to_width(int64_t l0, int64_t l1, bool l2) {
    int64_t l3, l5;
    bool l4;
    int64_t t0;
    l3 = vader_chk_sub(i64, (INT64_C(1) << l1), INT64_C(1));
    l3 = (l0 & l3);
    if (l2) {
        l5 = vader_chk_sub(i64, l1, INT64_C(1));
        l5 = (INT64_C(1) << l5);
        l4 = (l3 & l5) != INT64_C(0);
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = (INT64_C(1) << l1);
        t0 = vader_chk_sub(i64, l3, l5);
        return ((int32_t) (int64_t) t0);
    }
    return ((int32_t) (int64_t) l3);
}

static bool vader_vm_try_get_element(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5;
    void* l8;
    void* l11;
    void* l12;
    size_t l6, l10, l14;
    vader_box_t l7;
    int32_t l9, l13;
    int64_t t0;
    vader_box_t t1;
    uint8_t t2;
    t0 = ((int64_t) (int32_t) l3);
    l6 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l6);
    l6 = (size_t) (int64_t) t0;
    l7 = vader_vm_array_at(l0, l6);
    if (l7.tag == 0u) {
        return false;
    }
    l5 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    t0 = ((int64_t) (int32_t) l4);
    l6 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l6);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
    l9 = ((int32_t) (int64_t) t0);
    if ((l9 < INT32_C(0))) {
        return false;
    }
    t0 = ((int64_t) (int32_t) l9);
    l6 = (size_t) (int64_t) t0;
    l10 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_length;
    if ((l6 >= l10)) {
        return false;
    }
    l7 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_raw;
    if (!(l7.tag == 0u)) {
        l8 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        l11 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags;
        l12 = l7.payload.obj;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_offset;
        t0 = ((int64_t) (int32_t) l9);
        l10 = (size_t) (int64_t) t0;
        t0 = vader_chk_add(usize, l6, l10);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l6, 249u);
        t2 = ((uint8_t) t1.payload.i);
        l13 = ((int32_t) (uint8_t) t2);
        vader_vm_set_i32(l8, l11, l1, l2, l13);
        return true;
    }
    t0 = ((int64_t) (int32_t) l2);
    l6 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l6);
    l6 = (size_t) (int64_t) t0;
    l8 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_elements;
    l10 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_offset;
    t0 = ((int64_t) (int32_t) l9);
    l14 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l10, l14);
    l10 = (size_t) (int64_t) t0;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
    l7 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l10];
    vader_vm_set_register(l0, l6, l7);
    return true;
}

static bool vader_vm_try_set_element(void* l0, size_t l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5;
    void* l8;
    size_t l6, l10;
    vader_box_t l7;
    int32_t l9;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l2);
    l6 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l6);
    l6 = (size_t) (int64_t) t0;
    l7 = vader_vm_array_at(l0, l6);
    if (l7.tag == 0u) {
        return false;
    }
    l5 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    t0 = ((int64_t) (int32_t) l3);
    l6 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l6);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
    l9 = ((int32_t) (int64_t) t0);
    if ((l9 < INT32_C(0))) {
        return false;
    }
    t0 = ((int64_t) (int32_t) l9);
    l6 = (size_t) (int64_t) t0;
    l10 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_length;
    if ((l6 >= l10)) {
        return false;
    }
    if (((vader_struct_vader_vm_ArrayVal_t*) l5)->f_raw.tag == 0u) {
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_elements;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_offset;
        t0 = ((int64_t) (int32_t) l9);
        l10 = (size_t) (int64_t) t0;
        t0 = vader_chk_add(usize, l6, l10);
        l6 = (size_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) l4);
        l10 = (size_t) (int64_t) t0;
        t0 = vader_chk_add(usize, l1, l10);
        l10 = (size_t) (int64_t) t0;
        l7 = vader_vm_register_value(l0, l10);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6] = l7;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        return true;
    }
    return false;
}

static int32_t vader_vm_type_id_for_symbol(void* l0, int32_t l1) {
    int32_t l2;
    l2 = vader_bytecode_struct_symbol_type_index(l0, l1);
    if ((l2 < INT32_C(0))) {
        return INT32_C(0);
    }
    return l2;
}

static bool vader_vm_type_matches(void* l0, vader_box_t l1, int32_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    bool l7;
    uint8_t l8;
    vader_string_t l9 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[3] = { &l0, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l2 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types)->length;
    if ((l3 >= l4)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l6.tag == 557u) {
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val;
        l7 = vader_vm_primitive_matches(l1, l8);
        { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 561u) {
        if (l1.tag == 1123u) {
            t1 = l1.payload.obj;
            t2 = ((vader_struct_vader_vm_StructVal_t*) t1)->f_type_id;
            l7 = t2 == l2;
        } else {
            l7 = false;
        }
    } else if (l6.tag == 548u) {
        if (l1.tag == 1098u) {
            t1 = l1.payload.obj;
            t2 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_type_id;
            l7 = t2 == l2;
        } else {
            l7 = false;
        }
    } else if (l6.tag == 562u) {
        t1 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
        l7 = vader_vm_union_matches(l0, l1, l5);
    } else if (l6.tag == 558u) {
        t1 = l6.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcRef_t*) t1)->f_trait_name;
        l7 = vader_vm_ref_type_matches(l0, l1, l9);
    } else {
        if (!(l6.tag == 551u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l7 = false;
    }
    { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_type_tags(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l8;
    vader_box_t l4;
    uint8_t l5, l6, l11;
    void* l7;
    int32_t l9, l10;
    bool t0;
    int64_t t1;
    void* t2;
    int32_t t3;
    l3 = ((vader_array_t*) l0)->length;
    t0 = vader_vm_in_range(l1, l3);
    if (t0) {
        if ((l2 > INT32_C(8))) {
            return (uint8_t) 127;
        }
        t1 = ((int64_t) (int32_t) l1);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 557u) {
            t2 = l4.payload.obj;
            l5 = vader_vm_tags_of_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t2)->f_val);
            return l5;
        }
        if ((l4.tag == 548u || l4.tag == 551u || l4.tag == 561u)) {
            l5 = (uint8_t) 64;
        } else if (l4.tag == 558u) {
            l5 = (uint8_t) 127;
        } else {
            if (!(l4.tag == 562u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l6 = (uint8_t) 0;
            t2 = l4.payload.obj;
            l7 = ((vader_struct_vader_bytecode_BcUnion_t*) t2)->f_variants;
            l3 = ((vader_array_t*) l7)->length;
            l8 = (size_t) 0;
            while ((l8 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
                l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
                l10 = vader_chk_add(i32, l2, INT32_C(1));
                l11 = vader_vm_type_tags(l0, l9, l10);
                t3 = (l6 | l11);
                l6 = (uint8_t) (int32_t) t3;
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
            }
            l5 = l6;
        }
        return l5;
    }
    return (uint8_t) 127;
}

static uint32_t vader_vm_u32_of(void* l0, size_t l1, int32_t l2) {
    size_t l3;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l3);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return (uint32_t) (int32_t) ((int32_t) (int64_t) t0);
}

static uint64_t vader_vm_u64_of(void* l0, size_t l1, int32_t l2) {
    size_t l3;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    t0 = vader_chk_add(usize, l1, l3);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return (uint64_t) (int64_t) t0;
}

static vader_box_t vader_vm_unary_op(vader_box_t l0, void* l1, size_t l2) {
    uint8_t l3;
    vader_box_t l4;
    bool l5;
    int32_t t0;
    void* t1;
    uint8_t t2;
    bool t3;
    vader_string_t t4;
    size_t t5;
    t0 = (((INT32_C(1) | INT32_C(2)) | INT32_C(16)) | INT32_C(8));
    l3 = (uint8_t) (int32_t) t0;
    if (l0.tag == 630u) {
        l4 = vader_box_i32(246u, INT32_C(13));
        return l4;
    }
    if (l0.tag == 617u) {
        l4 = vader_box_i32(246u, INT32_C(14));
    } else if (l0.tag == 650u) {
        l4 = vader_box_i32(246u, INT32_C(38));
    } else if (l0.tag == 637u) {
        l4 = vader_box_i32(246u, INT32_C(39));
    } else if (l0.tag == 610u) {
        l4 = vader_box_i32(246u, INT32_C(56));
    } else if (l0.tag == 588u) {
        t1 = l0.payload.obj;
        t0 = vader_vm_checked_neg_register_op(((vader_struct_vader_bytecode_CheckedNeg_t*) t1)->f_kind);
        l4 = vader_box_i32(246u, t0);
    } else if (l0.tag == 574u) {
        t2 = vader_vm_stack_tags(l1, l2, (size_t) 1);
        t3 = vader_vm_tags_within(t2, (uint8_t) 8);
        if (t3) {
            l4 = vader_box_i32(246u, INT32_C(67));
        } else {
            l4 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 589u) {
        t2 = vader_vm_stack_tags(l1, l2, (size_t) 1);
        t3 = vader_vm_tags_within(t2, l3);
        if (t3) {
            t1 = l0.payload.obj;
            if (((vader_struct_vader_bytecode_Convert_t*) t1)->f_target == INT32_C(0)) {
                l4 = vader_box_i32(246u, INT32_C(83));
            } else {
                t1 = l0.payload.obj;
                if (((vader_struct_vader_bytecode_Convert_t*) t1)->f_target == INT32_C(1)) {
                    t1 = l0.payload.obj;
                    t4 = ((vader_struct_vader_bytecode_Convert_t*) t1)->f_from_name;
                    t5 = vader_host_std_core_byte_len(t4);
                    if ((t5 > INT64_C(0))) {
                        t1 = l0.payload.obj;
                        t4 = ((vader_struct_vader_bytecode_Convert_t*) t1)->f_from_name;
                        t2 = vader_host_std_core_byte_at(t4, (size_t) 0);
                        l5 = t2 == INT32_C(117);
                    } else {
                        l5 = false;
                    }
                    if (l5) {
                        l4 = vader_box_i32(246u, INT32_C(85));
                    } else {
                        l4 = vader_box_i32(246u, INT32_C(84));
                    }
                } else {
                    l4 = vader_box_obj(0u, NULL);
                }
            }
        } else {
            l4 = vader_box_obj(0u, NULL);
        }
    } else {
        l4 = vader_box_obj(0u, NULL);
    }
    return l4;
}

static bool vader_vm_union_matches(void* l0, vader_box_t l1, void* l2) {
    size_t l3, l4;
    int32_t l5;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l2)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        t0 = vader_vm_type_matches(l0, l1, l5);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_vm_unwind(void* l0, void* l1, void* l2, bool l3) {
    size_t l4, l6;
    void* l5 = NULL;
    void* l9 = NULL;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l8, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
        if ((t0 > INT64_C(0))) {
            t0 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
            t1 = vader_chk_sub(usize, t0, INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count = l4;
            l5 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers;
            l6 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            l7 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
            l8 = vader_vm_defer_thunk(l0, l7, INT32_C(0), 2094u);
            if (l8.tag == 1126u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = l8.payload.obj;
            t2 = vader_vm_run_thunk(l0, l1, l2, l9, (size_t) 0, (size_t) 0, (size_t) 0, l3);
            if (!(t2.tag == 0u)) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_validate_fn_index(int32_t l0, void* l1, int32_t l2, vader_string_t l3) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_vm_is_fn_index_out_of_range(l0, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_vm_fn_index_trap(l0, l2, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_value_from_bits(uint8_t l0, uint64_t l1) {
    uint64_t l2;
    vader_box_t t0;
    int64_t t1;
    int32_t t2;
    if (l0 == INT32_C(1)) {
        t0 = vader_box_i32(246u, ((int32_t) (int64_t) (l1 & INT64_C(255))));
        return t0;
    }
    if (l0 == INT32_C(5)) {
        t1 = (l1 & INT64_C(255));
        l2 = (uint64_t) (int64_t) t1;
        if ((l2 >= INT64_C(128))) {
            t2 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(256));
            t0 = vader_box_i32(246u, t2);
            return t0;
        }
        t0 = vader_box_i32(246u, ((int32_t) (uint64_t) l2));
        return t0;
    }
    if (l0 == INT32_C(12)) {
        t0 = vader_box_bool(241u, l1 != INT64_C(0));
        return t0;
    }
    if (l0 == INT32_C(2)) {
        t0 = vader_box_i32(246u, ((int32_t) (int64_t) (l1 & INT64_C(65535))));
        return t0;
    }
    if (l0 == INT32_C(6)) {
        t1 = (l1 & INT64_C(65535));
        l2 = (uint64_t) (int64_t) t1;
        if ((l2 >= INT64_C(32768))) {
            t2 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(65536));
            t0 = vader_box_i32(246u, t2);
            return t0;
        }
        t0 = vader_box_i32(246u, ((int32_t) (uint64_t) l2));
        return t0;
    }
    if (l0 == INT32_C(3)) {
        t0 = vader_box_i32(246u, ((int32_t) (uint64_t) l1));
        return t0;
    }
    if (l0 == INT32_C(7)) {
        t0 = vader_box_i32(246u, ((int32_t) (uint64_t) l1));
        return t0;
    }
    if (l0 == INT32_C(11)) {
        t0 = vader_box_i32(242u, (int32_t) ((uint32_t) (int32_t) ((int32_t) (uint64_t) l1)));
        return t0;
    }
    if (l0 == INT32_C(4)) {
        t0 = vader_box_i64(247u, ((int64_t) (uint64_t) l1));
        return t0;
    }
    if (l0 == INT32_C(8)) {
        t0 = vader_box_i64(247u, ((int64_t) (uint64_t) l1));
        return t0;
    }
    if (l0 == INT32_C(9)) {
        t0 = vader_box_f64(240u, ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
        return t0;
    }
    if (!(l0 == INT32_C(10))) {
        return vader_box_i32(246u, INT32_C(0));
    }
    t0 = vader_box_f64(240u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
    return t0;
}

static bool vader_vm_value_ref_eq(vader_box_t l0, vader_box_t l1) {
    bool l2, l5, l6;
    int32_t l3, l4;
    uint32_t l7, l8;
    vader_string_t l9, l10;
    int64_t l11, l12;
    uint64_t l13, l14;
    vader_box_t l15, l16;
    double t0;
    int64_t t1;
    if (l0.tag == 1110u) {
        l2 = l1.tag == 1110u;
        return l2;
    }
    if (l0.tag == 246u) {
        if (l1.tag == 246u) {
            l3 = ((int32_t) l0.payload.i);
            l4 = ((int32_t) l1.payload.i);
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 241u) {
        if (l1.tag == 241u) {
            l5 = l0.payload.b;
            l6 = l1.payload.b;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 242u) {
        if (l1.tag == 242u) {
            l7 = ((uint32_t) l0.payload.i);
            l8 = ((uint32_t) l1.payload.i);
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 243u) {
        if (l1.tag == 243u) {
            l9 = l0.payload.s;
            l10 = l1.payload.s;
            l2 = l9 == l10;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 247u) {
        if (l1.tag == 247u) {
            l11 = ((int64_t) l0.payload.i);
            l12 = ((int64_t) l1.payload.i);
            l2 = l11 == l12;
        } else {
            l2 = false;
        }
    } else if ((l0.tag == 239u || l0.tag == 240u)) {
        if ((l1.tag == 239u || l1.tag == 240u)) {
            t0 = ((double) l0.payload.f);
            t1 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t0 }).__vu);
            l13 = (uint64_t) (int64_t) t1;
            t0 = ((double) l1.payload.f);
            t1 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t0 }).__vu);
            l14 = (uint64_t) (int64_t) t1;
            l2 = l13 == l14;
        } else {
            l2 = false;
        }
    } else {
        if (!((l0.tag == 1098u || l0.tag == 1102u || l0.tag == 1103u || l0.tag == 1111u || l0.tag == 1123u || l0.tag == 1127u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if ((l1.tag == 1098u || l1.tag == 1102u || l1.tag == 1103u || l1.tag == 1111u || l1.tag == 1123u || l1.tag == 1127u)) {
            l15 = l0;
            l16 = l1;
            l2 = vader_box_eq(l15, l16);
        } else {
            l2 = false;
        }
    }
    return l2;
}

static vader_box_t vader_vm_verify_function(void* l0, void* l1) {
    size_t l2, l3, l4, l7, l9, l15, l17, l19, l24, l28, l29, l30, l31, l33, l37, l41;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l18 = NULL;
    void* l23 = NULL;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l34 = vader_box_null(), l42 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l22 = 0;
    vader_string_t l27 = 0;
    vader_string_t l39 = 0;
    vader_string_t l40 = 0;
    uint64_t l20, l21, l25, l26;
    bool l32, l35, l38;
    int32_t l36;
    void* t0 = NULL;
    size_t t1;
    int64_t t2, t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l8, &l10, &l12, &l34, &l42, &t4 };
    void** gc_raw_roots[8] = { &l0, &l1, &l5, &l6, &l11, &l18, &l23, &t0 };
    vader_string_t* gc_atom_roots[7] = { &l13, &l14, &l16, &l22, &l27, &l39, &l40 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    if (l2 == INT64_C(0)) {
        { vader_box_t __vret = vader_box_i64(253u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (size_t) 0;
    l4 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature);
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 8u, 247u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) INT64_C(0);
    vader_array_t* _a3_arr = vader_array_new(20u, 1u, 4u, 253u);
    ((int64_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (int64_t) INT64_C(0);
    l6 = (void*) _a3_arr;
    for (;;) {
        t1 = ((vader_array_t*) l6)->length;
        if ((t1 > INT64_C(0))) {
            l8 = vader_array_remove_last((vader_array_t*) l6);
            if (l8.tag == 0u) break;
            l7 = ((size_t) l8.payload.i);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            t2 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7];
            t3 = t2;
            l9 = (size_t) (int64_t) t3;
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l12 = vader_vm_effect_of(l0, l1, l10);
            if (l12.tag == 0u) {
                l13 = vader_vm_op_text(l10);
                l14 = concat_3(865u, l13, 992u);
                t0 = vader_vm_defect(l1, l7, l14);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = l12.payload.obj;
            l15 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pops;
            if ((l9 < l15)) {
                l16 = vader_vm_op_text(l10);
                l17 = vader_host_std_core_byte_len(l16);
                l18 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(79) + l17));
                l19 = (size_t) 0;
                l19 = std_core_write_string_at(l18, l19, 865u);
                l19 = std_core_write_string_at(l18, l19, l16);
                l19 = std_core_write_string_at(l18, l19, 993u);
                t1 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pops;
                t2 = ((int64_t) (size_t) t1);
                l20 = (uint64_t) (int64_t) t2;
                l19 = std_core_write_unsigned(l18, l19, l20);
                l19 = std_core_write_string_at(l18, l19, 141u);
                t2 = ((int64_t) (size_t) l9);
                l21 = (uint64_t) (int64_t) t2;
                l19 = std_core_write_unsigned(l18, l19, l21);
                l22 = std_core_finish_buffer(l18, l19);
                t0 = vader_vm_defect(l1, l7, l22);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l10.tag == 677u) {
                if (l9 != l4) {
                    l23 = std_core_new_byte_buffer((size_t) 87);
                    l24 = (size_t) 0;
                    l24 = std_core_write_string_at(l23, l24, 1159u);
                    t2 = ((int64_t) (size_t) l4);
                    l25 = (uint64_t) (int64_t) t2;
                    l24 = std_core_write_unsigned(l23, l24, l25);
                    l24 = std_core_write_string_at(l23, l24, 141u);
                    t2 = ((int64_t) (size_t) l9);
                    l26 = (uint64_t) (int64_t) t2;
                    l24 = std_core_write_unsigned(l23, l24, l26);
                    l27 = std_core_finish_buffer(l23, l24);
                    t0 = vader_vm_defect(l1, l7, l27);
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l28 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pops;
            t2 = vader_chk_sub(usize, l9, l28);
            l29 = (size_t) (int64_t) t2;
            l30 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pushes;
            t2 = vader_chk_add(usize, l29, l30);
            l31 = (size_t) (int64_t) t2;
            if ((l31 > l3)) {
                l3 = l31;
            }
            if (((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(0)) {
                l32 = true;
            } else {
                l32 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (l32) {
                t2 = vader_chk_add(usize, l7, INT64_C(1));
                l33 = (size_t) (int64_t) t2;
                l34 = vader_vm_flow_to(l1, l5, l6, l33, l31, l7, l4);
                if (!(l34.tag == 0u)) {
                    t0 = l34.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            if (((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(1)) {
                l35 = true;
            } else {
                l35 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (!(l35)) {
                continue;
            }
            l37 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table)->length;
            if ((l7 < l37)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
                l36 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
            } else {
                l36 = INT32_C(-1);
            }
            if ((l36 < INT32_C(0))) {
                l38 = true;
            } else {
                l38 = (((int64_t) (int32_t) l36) > l2);
            }
            if (l38) {
                l39 = vader_vm_op_text(l10);
                l40 = concat_3(865u, l39, 922u);
                t0 = vader_vm_defect(l1, l7, l40);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((int64_t) (int32_t) l36);
            l41 = (size_t) (int64_t) t2;
            l42 = vader_vm_flow_to(l1, l5, l6, l41, l31, l7, l4);
            if (!(l42.tag == 0u)) {
                t0 = l42.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            continue;
        }
        break;
    }
    t4 = vader_box_i64(253u, (int64_t)(uint64_t) l3);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_verify_module(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l2, l4, l7;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(20u, 0u, 4u, 253u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = vader_vm_verify_function(l0, l5);
        if (l6.tag == 1129u) {
            t0 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((size_t) l6.payload.i);
        vader_array_push_i64((vader_array_t*) l1, (int64_t) (size_t) l7);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_vm_virtual_result_arity(void* l0, vader_string_t l1) {
    vader_box_t l2;
    void* t0;
    size_t t1;
    l2 = vader_vm_virtual_signature(l0, l1);
    if (l2.tag == 0u) {
        return (size_t) 1;
    }
    t0 = l2.payload.obj;
    t1 = vader_bytecode_bc_result_arity(t0);
    return t1;
}

static vader_box_t vader_vm_virtual_signature(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    void* l8;
    size_t l3, l4, l7, l9;
    int32_t l6;
    vader_string_t t0;
    size_t t1;
    void* t2;
    bool t3;
    int64_t t4;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_key;
        if (t0 == l1) {
            t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_entries)->length;
            if ((t1 > INT64_C(0))) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_entries);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                l6 = ((vader_struct_vader_bytecode_VtableEntry_t*) t2)->f_fn_index;
                l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
                t3 = vader_vm_in_range(l6, l7);
                if (t3) {
                    l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
                    t4 = ((int64_t) (int32_t) l6);
                    l9 = (size_t) (int64_t) t4;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                    return vader_ref_box(((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature);
                }
            }
        }
        t4 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t4;
    }
    return vader_box_obj(0u, NULL);
}

static int32_t vader_vm_vtable_row_of(void* l0, vader_string_t l1) {
    size_t l2, l3;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_key;
        if (t1 == l1) {
            return ((int32_t) (size_t) l2);
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return INT32_C(-1);
}

static void vader_vm_walk_block(void* l0, void* l1, void* l2, size_t l3, size_t l4, void* l5, vader_box_t l6) {
    size_t l7, l8, l9, l10, l12, l16, l17, l18, l24, l25, l26;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l20 = NULL;
    uint8_t l13;
    int64_t l14;
    vader_box_t l19 = vader_box_null(), l21 = vader_box_null();
    bool l22, l23;
    int64_t t0, t2;
    vader_box_t t1 = vader_box_null();
    void* t3 = NULL;
    int32_t t4;
    vader_box_t* gc_roots[4] = { &l6, &l19, &l21, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l11, &l15, &l20, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    l8 = ((vader_struct_vader_vm_Blocks_t*) l2)->f_width;
    t0 = vader_chk_mul(usize, l3, l8);
    l8 = (size_t) (int64_t) t0;
    l9 = (size_t) 0;
    l10 = ((vader_struct_vader_vm_Blocks_t*) l2)->f_width;
    while ((l9 < l10)) {
        l11 = ((vader_struct_vader_vm_Blocks_t*) l2)->f_entry;
        t0 = vader_chk_add(usize, l8, l9);
        l12 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l12)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l12, 249u);
        l13 = ((uint8_t) t1.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9] = (uint8_t) (int32_t) (uint8_t) l13;
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
    t2 = t0;
    l8 = (size_t) (int64_t) t2;
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_leaders);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    l9 = (size_t) (int64_t) t0;
    for (;;) {
        if ((l9 < l7)) {
            if (!(l6.tag == 0u)) {
                t3 = l6.payload.obj;
                l11 = ((vader_struct_vader_vm_FunctionTags_t*) t3)->f_depth;
                l14 = ((int64_t) (size_t) l8);
                vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9] = (int64_t) l14;
                l10 = (size_t) 0;
                l12 = l8;
                while ((l10 < l12)) {
                    t3 = l6.payload.obj;
                    l15 = ((vader_struct_vader_vm_FunctionTags_t*) t3)->f_stack;
                    t3 = l6.payload.obj;
                    l16 = ((vader_struct_vader_vm_FunctionTags_t*) t3)->f_deepest;
                    t0 = vader_chk_mul(usize, l9, l16);
                    t2 = vader_chk_add(usize, t0, l10);
                    l17 = (size_t) (int64_t) t2;
                    t0 = vader_chk_add(usize, l4, l10);
                    l18 = (size_t) (int64_t) t0;
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l18)
                    t1 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l18, 249u);
                    l13 = ((uint8_t) t1.payload.i);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l15);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l17)
                    ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l17] = (uint8_t) (int32_t) (uint8_t) l13;
                    t0 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t0;
                }
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            l19 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            l21 = vader_vm_effect_of(((vader_struct_vader_vm_TagContext_t*) l0)->f_module, l1, l19);
            if (l21.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l20 = l21.payload.obj;
            l8 = vader_vm_transfer(l0, l19, l5, l4, l8, l20);
            if (l6.tag == 0u) {
                if (((vader_struct_vader_vm_StackEffect_t*) l20)->f_flow == INT32_C(1)) {
                    l23 = true;
                } else {
                    l23 = ((vader_struct_vader_vm_StackEffect_t*) l20)->f_flow == INT32_C(2);
                }
                l22 = l23;
            } else {
                l22 = false;
            }
            if (l22) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
                t4 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l9];
                t0 = ((int64_t) (int32_t) t4);
                l24 = (size_t) (int64_t) t0;
                if ((l24 < l7)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_block_at);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l24)
                    t0 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l24];
                    t2 = t0;
                    l25 = (size_t) (int64_t) t2;
                    vader_vm_merge_block(l2, l25, l8, l5);
                }
            }
            if (((vader_struct_vader_vm_StackEffect_t*) l20)->f_flow != INT32_C(0)) {
                if (((vader_struct_vader_vm_StackEffect_t*) l20)->f_flow != INT32_C(2)) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            t0 = vader_chk_add(usize, l9, INT64_C(1));
            l9 = (size_t) (int64_t) t0;
            if (!((l9 < l7))) {
                continue;
            }
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_block_at);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
            t0 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9];
            if (!((t0 >= INT64_C(0)))) {
                continue;
            }
            if (l6.tag == 0u) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_block_at);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                t0 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                t2 = t0;
                l26 = (size_t) (int64_t) t2;
                vader_vm_merge_block(l2, l26, l8, l5);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_write_le(void* l0, size_t l1, size_t l2, uint64_t l3) {
    uint64_t l4;
    size_t l5, l6;
    uint8_t l7;
    int64_t t0;
    int32_t t1;
    l4 = l3;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        t0 = vader_chk_add(usize, l1, l5);
        l6 = (size_t) (int64_t) t0;
        t1 = (((int32_t) (int64_t) (l4 & INT64_C(255))) & INT32_C(255));
        l7 = (uint8_t) (int32_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l7;
        l4 = (l4 >> INT64_C(8));
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    return;
}

static void vader_vm_write_little_endian(void* l0, size_t l1, int64_t l2, size_t l3) {
    uint64_t l4, l7;
    size_t l5, l6;
    uint8_t l8;
    int64_t t0, t1;
    int32_t t2;
    t0 = l2;
    l4 = (uint64_t) (int64_t) t0;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        t0 = vader_chk_add(usize, l1, l5);
        l6 = (size_t) (int64_t) t0;
        t0 = vader_chk_mul(usize, l5, INT64_C(8));
        t1 = t0;
        l7 = (uint64_t) (int64_t) t1;
        t2 = (((int32_t) (int64_t) ((l4 >> l7) & INT64_C(255))) & INT32_C(255));
        l8 = (uint8_t) (int32_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l8;
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    return;
}

static vader_box_t vader_vm_zero_value(void) {
    return vader_box_i32(246u, INT32_C(0));
}
