#include "bootstrap.split.h"

static vader_string_t vader_vm_ArrayVal_std_core_Display_to_string(void* l0);
static vader_string_t vader_vm_BoolVal_std_core_Display_to_string(bool l0);
static vader_string_t vader_vm_CharVal_std_core_Display_to_string(uint32_t l0);
static vader_string_t vader_vm_ErrorVal_std_core_Display_to_string(void* l0);
static vader_string_t vader_vm_F64Val_std_core_Display_to_string(double l0);
static vader_string_t vader_vm_FnVal_std_core_Display_to_string(void* l0);
static vader_string_t vader_vm_I32Val_std_core_Display_to_string(int32_t l0);
static vader_string_t vader_vm_I64Val_std_core_Display_to_string(int64_t l0);
static vader_string_t vader_vm_NullVal_std_core_Display_to_string(void* l0);
static vader_string_t vader_vm_ObjVal_std_core_Display_to_string(void* l0);
static vader_string_t vader_vm_StringVal_std_core_Display_to_string(vader_string_t l0);
static vader_string_t vader_vm_StructVal_std_core_Display_to_string(void* l0);
static vader_string_t vader_vm_TypeVal_std_core_Display_to_string(void* l0);
static vader_box_t vader_vm_accepted_tags(vader_box_t l0, int64_t l1);
static void vader_vm_add_constant(vader_box_t l0, void* l1, void* l2);
static vader_box_t vader_vm_apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4, bool l5);
static vader_box_t vader_vm_apply_eq_binop(void* l0, vader_string_t l1, bool l2);
static vader_box_t vader_vm_array_at(void* l0, int64_t l1);
static vader_box_t vader_vm_array_bytes(void* l0, int64_t l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm_bc_value_to_vm(vader_box_t l0, void* l1);
static vader_box_t vader_vm_binary_op(vader_box_t l0, void* l1, int64_t l2);
static int64_t vader_vm_bits_of(void* l0, int64_t l1, int32_t l2);
static void vader_vm_boxed(void* l0, int64_t l1, vader_box_t l2, int64_t l3, int64_t l4);
static void* vader_vm_branch(bool l0, int32_t l1, bool l2, int32_t l3, bool l4);
static void* vader_vm_budget_trap(int64_t l0);
static vader_box_t vader_vm_build_array(int32_t l0, int32_t l1, void* l2);
static vader_box_t vader_vm_build_buffer(void* l0, void* l1);
static vader_box_t vader_vm_build_main_args(void* l0, void* l1, int32_t l2);
static vader_box_t vader_vm_build_struct(void* l0, int32_t l1, void* l2);
static void* vader_vm_bytes_to_value(vader_string_t l0, int32_t l1);
static vader_box_t vader_vm_call_import(void* l0, void* l1, int32_t l2, int64_t l3, int32_t l4, bool l5);
static vader_box_t vader_vm_call_results(void* l0, vader_box_t l1);
static int32_t vader_vm_canonical(void* l0, int64_t l1);
static vader_box_t vader_vm_check_byte_range(int32_t l0, int64_t l1, int64_t l2, vader_string_t l3, int32_t l4);
static vader_box_t vader_vm_check_module_tags(void* l0, void* l1);
static int32_t vader_vm_checked_neg_register_op(uint8_t l0);
static void* vader_vm_checked_neg_trap(uint8_t l0, void* l1, int64_t l2);
static int32_t vader_vm_checked_register_op(void* l0);
static vader_box_t vader_vm_checked_registers(uint8_t l0, uint8_t l1, void* l2, int64_t l3, int64_t l4);
static void* vader_vm_checked_trap(uint8_t l0, uint8_t l1, void* l2, int64_t l3);
static int64_t vader_vm_clamp_nonneg(int32_t l0);
static bool vader_vm_class_matches(vader_box_t l0, uint8_t l1);
static void vader_vm_collect_constants(void* l0, void* l1, void* l2);
static int64_t vader_vm_constant_index(void* l0, void* l1, void* l2);
static bool vader_vm_convert_int_fast(void* l0, uint8_t l1, vader_string_t l2);
static vader_box_t vader_vm_convert_value(vader_box_t l0, uint8_t l1, vader_string_t l2, int32_t l3);
static vader_box_t vader_vm_debug_controller(void* l0);
static int64_t vader_vm_debug_std_descriptor(int64_t l0);
static vader_box_t vader_vm_debug_write(void* l0, void* l1, int64_t l2, int32_t l3, void* l4);
static void* vader_vm_defect(void* l0, int64_t l1, vader_string_t l2);
static vader_box_t vader_vm_defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3);
static vader_string_t vader_vm_describe_obj(void* l0);
static vader_string_t vader_vm_describe_value_tag(vader_box_t l0);
static void vader_vm_detach_array_view(void* l0);
static vader_box_t vader_vm_dispatch_extern(void* l0, void* l1, int64_t l2, int32_t l3, void* l4, vader_box_t l5);
static vader_box_t vader_vm_dispatch_import(void* l0, void* l1, int64_t l2, void* l3, void* l4, int32_t l5, int32_t l6, int32_t l7, int32_t l8, void* l9, bool l10, vader_box_t l11, uint8_t l12);
static vader_string_t vader_vm_display_tags(uint8_t l0);
static vader_string_t vader_vm_display_value(vader_box_t l0);
static vader_box_t vader_vm_do_memory_copy(void* l0);
static void vader_vm_drop_due_timers(void* l0);
static void vader_vm_drop_last_op(void* l0);
static void* vader_vm_effect(int64_t l0, int64_t l1);
static vader_box_t vader_vm_effect_of(void* l0, void* l1, vader_box_t l2);
static vader_string_t vader_vm_element_label(int32_t l0);
static uint8_t vader_vm_element_tags(void* l0, int32_t l1);
static void* vader_vm_element_trap(void* l0, int64_t l1, int32_t l2, int32_t l3, void* l4, int64_t l5, int32_t l6);
static void vader_vm_emit(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static void vader_vm_enter_frame(void* l0, void* l1, int64_t l2);
static vader_box_t vader_vm_exec_array_copy(void* l0);
static vader_box_t vader_vm_exec_array_push_all(void* l0);
static vader_box_t vader_vm_exec_array_repeat(void* l0);
static vader_box_t vader_vm_exec_array_slice(void* l0, void* l1);
static vader_box_t vader_vm_exec_buffer_write_string(void* l0);
static vader_box_t vader_vm_exec_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5);
static vader_box_t vader_vm_exec_string_compare(void* l0);
static vader_box_t vader_vm_extern_result(uint8_t l0, int64_t l1);
static vader_box_t vader_vm_extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, int64_t l3);
static double vader_vm_f64_of(void* l0, int64_t l1, int32_t l2);
static int32_t vader_vm_ffi_result_class(uint8_t l0);
static bool vader_vm_ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2);
static uint8_t vader_vm_field_tags(void* l0, int32_t l1, int32_t l2);
static uint8_t vader_vm_field_val_type(void* l0, void* l1);
static int32_t vader_vm_find_io_error_type_id(void* l0);
static int32_t vader_vm_find_string_array_type_id(void* l0);
static int32_t vader_vm_find_u8_array_type_id(void* l0);
static vader_box_t vader_vm_finish_run(void* l0, bool l1, vader_box_t l2);
static bool vader_vm_fits_signed(int32_t l0, int64_t l1);
static vader_box_t vader_vm_flow_to(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5, int64_t l6);
static void vader_vm_flush(void* l0, int64_t l1);
static void* vader_vm_fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_fn_type_of(void* l0, int32_t l1);
static vader_box_t vader_vm_fused_branch(int32_t l0, bool l1);
static void* vader_vm_global_at_comptime_trap(void* l0, int32_t l1);
static uint8_t vader_vm_global_tags(void* l0, int32_t l1);
static void vader_vm_grow_frame_records(void* l0, void* l1, int64_t l2, int64_t l3);
static int32_t vader_vm_i32_of(void* l0, int64_t l1, int32_t l2);
static vader_box_t vader_vm_impure_comptime_trap(vader_string_t l0);
static bool vader_vm_in_range(int32_t l0, int64_t l1);
static vader_box_t vader_vm_indexed_effect(int32_t l0, int64_t l1, int64_t l2, int64_t l3);
static void* vader_vm_indirect_call_trap(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4);
static vader_box_t vader_vm_indirect_effect(void* l0, int32_t l1);
static void* vader_vm_infer_function_tags(void* l0, void* l1, int64_t l2);
static void* vader_vm_infer_module_tags(void* l0, void* l1);
static void* vader_vm_initial_globals(void* l0);
static bool vader_vm_inlinable_op(vader_box_t l0);
static void* vader_vm_inline_into(void* l0, void* l1, int64_t l2);
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
static bool vader_vm_is_unsigned_source(vader_string_t l0);
static bool vader_vm_is_write_symbol(vader_string_t l0);
static void vader_vm_jump(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static vader_box_t vader_vm_lent_element_val_type(void* l0, int32_t l1);
static bool vader_vm_line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_vm_load_bytes_op(void* l0, int64_t l1, vader_string_t l2);
static int32_t vader_vm_lookup_vtable_row(void* l0, int32_t l1, int32_t l2);
static void vader_vm_materialise(void* l0, int64_t l1, int64_t l2);
static vader_box_t vader_vm_merge(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5);
static void vader_vm_merge_block(void* l0, int64_t l1, int64_t l2, void* l3);
static vader_box_t vader_vm_mirrored_struct_fields(void* l0, void* l1, int64_t l2);
static void vader_vm_move_register(void* l0, int64_t l1, int64_t l2);
static int32_t vader_vm_narrow_code(uint8_t l0);
static vader_box_t vader_vm_narrow_mask(vader_box_t l0, uint8_t l1);
static void vader_vm_narrow_register(void* l0, int64_t l1, int32_t l2);
static void* vader_vm_new_blocks(void* l0, void* l1, int64_t l2);
static void* vader_vm_new_run_host(void);
static void* vader_vm_new_tag_context(void* l0);
static void vader_vm_note_checked_kind(void* l0, vader_box_t l1);
static bool vader_vm_one_argument_string_op(void* l0, int64_t l1, int32_t l2);
static vader_string_t vader_vm_op_text(vader_box_t l0);
static int32_t vader_vm_operand(void* l0, int64_t l1);
static int32_t vader_vm_operand_a(int64_t l0);
static int32_t vader_vm_operand_b(int64_t l0);
static int32_t vader_vm_operand_c(int64_t l0);
static int32_t vader_vm_operand_of(void* l0, int64_t l1, int64_t l2);
static bool vader_vm_operands_within(void* l0, int64_t l1, uint8_t l2);
static void* vader_vm_overflow_trap(vader_string_t l0);
static void vader_vm_own_bytes(void* l0);
static vader_box_t vader_vm_pack_operands(int32_t l0, int32_t l1, int32_t l2);
static vader_string_t vader_vm_param_display_name(void* l0, int64_t l1);
static void* vader_vm_pause_context(void* l0, void* l1, vader_string_t l2, int64_t l3, int64_t l4);
static void* vader_vm_pause_frame(void* l0, void* l1, void* l2, int32_t l3);
static vader_box_t vader_vm_peek_array_mut(void* l0, int64_t l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm_peek_owned(void* l0, int64_t l1);
static vader_box_t vader_vm_peek_val(void* l0, int64_t l1);
static int32_t vader_vm_pop_to(void* l0, int64_t l1);
static vader_box_t vader_vm_prepare_for(void* l0, bool l1);
static vader_box_t vader_vm_prepare_module(void* l0, bool l1);
static void* vader_vm_primitive_impl_import(vader_string_t l0, int64_t l1);
static vader_string_t vader_vm_primitive_kind_at(void* l0, int32_t l1);
static int32_t vader_vm_primitive_type_id(void* l0, vader_box_t l1);
static void* vader_vm_project_locals(void* l0, int32_t l1, void* l2, void* l3);
static void* vader_vm_project_struct_fields(void* l0, void* l1, int32_t l2);
static void* vader_vm_project_var(vader_string_t l0, vader_box_t l1, void* l2, int32_t l3);
static void vader_vm_push_constant(void* l0, vader_box_t l1);
static void vader_vm_push_little_endian(void* l0, int64_t l1, int64_t l2);
static void vader_vm_push_register(void* l0, int32_t l1);
static void vader_vm_push_val(void* l0, int64_t l1, vader_box_t l2);
static uint8_t vader_vm_pushed_tags(void* l0, vader_box_t l1, void* l2, uint8_t l3);
static vader_box_t vader_vm_read_array(vader_box_t l0, int32_t l1, vader_string_t l2);
static void vader_vm_read_back_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5);
static vader_box_t vader_vm_read_bool(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_f64(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_fn(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_i32(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_i64(vader_box_t l0, int32_t l1, vader_string_t l2);
static uint64_t vader_vm_read_le(void* l0, int64_t l1, int64_t l2);
static int64_t vader_vm_read_little_endian(void* l0, int64_t l1, int64_t l2, bool l3);
static vader_box_t vader_vm_read_numeric_as_f64(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm_read_numeric_as_i64(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm_read_obj(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_scalar_word(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_string(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_struct(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm_read_struct_field(vader_box_t l0, int32_t l1, int32_t l2, vader_string_t l3);
static void* vader_vm_receiver_trap(void* l0, int64_t l1, void* l2, int64_t l3, vader_string_t l4, vader_string_t l5);
static int32_t vader_vm_receiver_type_id_of(void* l0, vader_box_t l1);
static void* vader_vm_reduce_data_pool(void* l0, void* l1, void* l2);
static int32_t vader_vm_reduce_main_index(void* l0);
static bool vader_vm_ref_type_matches(void* l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_vm_reg_call(void* l0, void* l1, void* l2, int32_t l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm_reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6);
static vader_box_t vader_vm_register_value(void* l0, int64_t l1);
static vader_box_t vader_vm_relocated(vader_box_t l0, int32_t l1);
static void vader_vm_reserve_registers(void* l0, int64_t l1);
static void vader_vm_reserve_stack(void* l0, int64_t l1);
static void vader_vm_reset_stack(void* l0, int64_t l1);
static vader_box_t vader_vm_resolve_virtual(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5);
static void vader_vm_return_many(void* l0, int64_t l1, void* l2);
static bool vader_vm_returns_void(void* l0, int32_t l1);
static vader_box_t vader_vm_retyped_int(vader_box_t l0, int64_t l1);
static vader_box_t vader_vm_run_boxed(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5);
static vader_box_t vader_vm_run_defers(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm_run_thunk(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm_scalar_of(vader_box_t l0);
static void* vader_vm_scratch_frame(void);
static vader_box_t vader_vm_serialise_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7);
static void vader_vm_set_bool(void* l0, void* l1, int64_t l2, int32_t l3, bool l4);
static void vader_vm_set_char_code(void* l0, void* l1, int64_t l2, int32_t l3, uint32_t l4);
static vader_box_t vader_vm_set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6, int32_t l7);
static void vader_vm_set_f64(void* l0, void* l1, int64_t l2, int32_t l3, double l4);
static vader_box_t vader_vm_set_field(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6);
static void vader_vm_set_i32(void* l0, void* l1, int64_t l2, int32_t l3, int32_t l4);
static void vader_vm_set_i64(void* l0, void* l1, int64_t l2, int32_t l3, int64_t l4);
static void vader_vm_set_integer(void* l0, void* l1, int64_t l2, int32_t l3, uint8_t l4, int64_t l5);
static void vader_vm_set_register(void* l0, int64_t l1, vader_box_t l2);
static bool vader_vm_skips_else(void* l0, int64_t l1);
static bool vader_vm_slot_in_scope(void* l0, void* l1, int64_t l2, int32_t l3);
static int32_t vader_vm_slot_touched_by(vader_box_t l0);
static uint8_t vader_vm_slot_valtype(void* l0, int32_t l1);
static void vader_vm_stack_grow(void* l0);
static vader_box_t vader_vm_stack_i32(void* l0, int64_t l1, vader_string_t l2, vader_string_t l3);
static vader_box_t vader_vm_stack_obj(void* l0, int64_t l1, vader_string_t l2);
static uint8_t vader_vm_stack_tags(void* l0, int64_t l1, int64_t l2);
static bool vader_vm_step_should_stop(uint8_t l0, int32_t l1, int32_t l2);
static void vader_vm_stop_at_line(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5);
static vader_box_t vader_vm_store_bytes_op(void* l0, int64_t l1, uint64_t l2, vader_string_t l3);
static void vader_vm_store_slot(void* l0, void* l1, int64_t l2, int32_t l3, bool l4, int64_t l5);
static void* vader_vm_string_array_to_value(void* l0, int32_t l1);
static vader_box_t vader_vm_string_at(void* l0, int64_t l1);
static bool vader_vm_string_byte_op(void* l0, int64_t l1, uint8_t l2);
static void vader_vm_string_constant(void* l0, void* l1, int64_t l2, void* l3);
static vader_box_t vader_vm_struct_new_effect(void* l0, int32_t l1);
static uint8_t vader_vm_tags_of_type(void* l0, int32_t l1);
static uint8_t vader_vm_tags_of_val(uint8_t l0);
static bool vader_vm_tags_within(uint8_t l0, uint8_t l1);
static bool vader_vm_trait_implemented_by(void* l0, vader_string_t l1, int32_t l2);
static int64_t vader_vm_transfer(void* l0, vader_box_t l1, void* l2, int64_t l3, int64_t l4, void* l5);
static vader_box_t vader_vm_translate_function(void* l0, void* l1, int32_t l2, void* l3, bool l4);
static vader_box_t vader_vm_translate_module(void* l0, void* l1, void* l2, bool l3);
static bool vader_vm_translate_op(void* l0, void* l1, void* l2, void* l3, int64_t l4);
static int32_t vader_vm_truncate_to_width(int64_t l0, int64_t l1, bool l2);
static bool vader_vm_try_get_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4);
static bool vader_vm_try_set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4);
static int32_t vader_vm_type_id_for_symbol(void* l0, int32_t l1);
static bool vader_vm_type_matches(void* l0, vader_box_t l1, int32_t l2);
static uint8_t vader_vm_type_tags(void* l0, int32_t l1, int32_t l2);
static uint32_t vader_vm_u32_of(void* l0, int64_t l1, int32_t l2);
static uint64_t vader_vm_u64_of(void* l0, int64_t l1, int32_t l2);
static vader_box_t vader_vm_unary_op(vader_box_t l0, void* l1, int64_t l2);
static bool vader_vm_union_matches(void* l0, vader_box_t l1, void* l2);
static void vader_vm_unwind(void* l0, void* l1, void* l2, bool l3);
static vader_box_t vader_vm_validate_fn_index(int32_t l0, void* l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm_value_from_bits(uint8_t l0, uint64_t l1);
static bool vader_vm_value_ref_eq(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_vm_verify_function(void* l0, void* l1);
static vader_box_t vader_vm_verify_module(void* l0);
static int64_t vader_vm_virtual_result_arity(void* l0, vader_string_t l1);
static vader_box_t vader_vm_virtual_signature(void* l0, vader_string_t l1);
static int32_t vader_vm_vtable_row_of(void* l0, vader_string_t l1);
static void vader_vm_walk_block(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, void* l5, vader_box_t l6);
static int32_t vader_vm_widening(vader_string_t l0);
static void vader_vm_write_le(void* l0, int64_t l1, int64_t l2, uint64_t l3);
static void vader_vm_write_little_endian(void* l0, int64_t l1, int64_t l2, int64_t l3);
static int64_t vader_vm_zero_extended(void* l0, void* l1, int64_t l2, int32_t l3);
static vader_box_t vader_vm_zero_value(void);

static vader_string_t vader_vm_ArrayVal_std_core_Display_to_string(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3, l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 531u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append(l1, 847u);
    l2 = INT64_C(0);
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string_builder_append(l1, 305u);
        }
        t1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        l4 = vader_chk_add(i64, t1, l2);
        t2 = vader_vm_element_at(l0, l4);
        l5 = vader_vm_display_value(t2);
        std_string_builder_append(l1, l5);
        l2 = (l2 + INT64_C(1));
    }
    std_string_builder_append(l1, 850u);
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_BoolVal_std_core_Display_to_string(bool l0) {
    if (l0) {
        return 2536u;
    }
    return 1793u;
}

static vader_string_t vader_vm_CharVal_std_core_Display_to_string(uint32_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_char_Display_to_string(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_ErrorVal_std_core_Display_to_string(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_vm_ErrorVal_t*) l0)->f_message;
    t0 = concat_3(442u, l1, 457u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_F64Val_std_core_Display_to_string(double l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_f64_Display_to_string(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_FnVal_std_core_Display_to_string(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_vm_FnVal_t*) l0)->f_env.tag == 0u) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(25));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l1, l2, 443u);
        t0 = ((vader_struct_vader_vm_FnVal_t*) l0)->f_function_index;
        l3 = ((int64_t) (int32_t) t0);
        l2 = std_core_write_int(l1, l2, l3);
        l2 = std_core_write_string_at(l1, l2, 457u);
        t1 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 443u);
    t0 = ((vader_struct_vader_vm_FnVal_t*) l0)->f_function_index;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 302u);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_I32Val_std_core_Display_to_string(int32_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
    l2 = INT64_C(0);
    l3 = ((int64_t) (int32_t) l0);
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_I64Val_std_core_Display_to_string(int64_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
    l2 = INT64_C(0);
    l3 = l0;
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_NullVal_std_core_Display_to_string(void* l0) {
    return 2227u;
}

static vader_string_t vader_vm_ObjVal_std_core_Display_to_string(void* l0) {
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

static vader_string_t vader_vm_StringVal_std_core_Display_to_string(vader_string_t l0) {
    return l0;
}

static vader_string_t vader_vm_StructVal_std_core_Display_to_string(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 531u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l3 = INT64_C(0);
    t1 = ((vader_struct_vader_vm_StructVal_t*) l0)->f_type_id;
    l4 = ((int64_t) (int32_t) t1);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2838u);
    l5 = std_core_finish_buffer(l2, l3);
    std_string_builder_append(l1, l5);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string_builder_append(l1, 305u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
        l5 = vader_vm_display_value(t2);
        std_string_builder_append(l1, l5);
        l3 = (l3 + INT64_C(1));
    }
    std_string_builder_append(l1, 183u);
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_TypeVal_std_core_Display_to_string(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 449u);
    t0 = ((vader_struct_vader_vm_TypeVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 457u);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_accepted_tags(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    void* t0;
    uint8_t t1;
    if ((l0.tag == 709u || l0.tag == 710u || l0.tag == 712u || l0.tag == 713u || l0.tag == 715u || l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 722u || l0.tag == 725u || l0.tag == 726u || l0.tag == 727u || l0.tag == 728u || l0.tag == 791u || l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u)) {
        l2 = vader_box_i32(292u, INT32_C(19));
        return l2;
    }
    if ((l0.tag == 711u || l0.tag == 724u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(292u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 716u || l0.tag == 723u)) {
        l2 = vader_box_i32(292u, (INT32_C(19) | INT32_C(32)));
    } else if ((l0.tag == 729u || l0.tag == 730u || l0.tag == 732u || l0.tag == 733u || l0.tag == 735u || l0.tag == 736u || l0.tag == 737u || l0.tag == 738u || l0.tag == 739u || l0.tag == 740u || l0.tag == 741u || l0.tag == 742u || l0.tag == 743u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u)) {
        l2 = vader_box_i32(292u, INT32_C(3));
    } else if ((l0.tag == 731u || l0.tag == 744u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(292u, INT32_C(3));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 692u || l0.tag == 694u || l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 698u || l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 703u)) {
        l2 = vader_box_i32(292u, INT32_C(4));
    } else if (l0.tag == 702u) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(292u, INT32_C(4));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 679u) {
        t0 = l0.payload.obj;
        t1 = vader_vm_integer_operand_tags(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind);
        l2 = vader_box_i32(292u, (int32_t)(uint32_t) t1);
    } else if (l0.tag == 680u) {
        if (l1 == INT64_C(1)) {
            t0 = l0.payload.obj;
            t1 = vader_vm_integer_operand_tags(((vader_struct_vader_bytecode_CheckedNeg_t*) t0)->f_kind);
            l2 = vader_box_i32(292u, (int32_t)(uint32_t) t1);
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 629u || l0.tag == 754u || l0.tag == 755u || l0.tag == 756u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(292u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 636u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u)) {
        if (l1 == INT64_C(2)) {
            l2 = vader_box_i32(292u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else {
        if (!((l0.tag == 627u || l0.tag == 628u || l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 637u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 672u || l0.tag == 675u || l0.tag == 676u || l0.tag == 677u || l0.tag == 678u || l0.tag == 681u || l0.tag == 682u || l0.tag == 684u || l0.tag == 685u || l0.tag == 686u || l0.tag == 687u || l0.tag == 690u || l0.tag == 691u || l0.tag == 693u || l0.tag == 704u || l0.tag == 705u || l0.tag == 706u || l0.tag == 707u || l0.tag == 708u || l0.tag == 714u || l0.tag == 734u || l0.tag == 749u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 757u || l0.tag == 758u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u || l0.tag == 762u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 767u || l0.tag == 768u || l0.tag == 769u || l0.tag == 770u || l0.tag == 771u || l0.tag == 772u || l0.tag == 773u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 781u || l0.tag == 782u || l0.tag == 783u || l0.tag == 784u || l0.tag == 785u || l0.tag == 786u || l0.tag == 787u || l0.tag == 788u || l0.tag == 789u || l0.tag == 790u || l0.tag == 803u || l0.tag == 804u || l0.tag == 805u || l0.tag == 806u))) {
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

static vader_box_t vader_vm_apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4, bool l5) {
    int64_t l6, l11;
    void* l7 = NULL;
    void* l14 = NULL;
    int32_t l8, l10;
    vader_box_t l9 = vader_box_null(), l12 = vader_box_null();
    bool l13, l18;
    uint8_t l15;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    uint64_t l19;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2, t7;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_string_t t5 = 0;
    uint64_t t6;
    double t8;
    vader_box_t* gc_roots[4] = { &l2, &l9, &l12, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l7, &l14, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l16, &l17, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 706u) {
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        vader_struct_vader_vm_FnVal_t* _a0_obj = (vader_struct_vader_vm_FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FnVal_t));
        vader_obj_header_init(_a0_obj, 1285u);
        _a0_obj->f_function_index = t1;
        _a0_obj->f_env = vader_box_obj(0u, NULL);
        l7 = (void*) _a0_obj;
        vader_vm_push_val(l3, l6, vader_ref_box(l7));
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l2.tag == 763u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_owned(l3, l6);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        vader_struct_vader_vm_FnVal_t* _a1_obj = (vader_struct_vader_vm_FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FnVal_t));
        vader_obj_header_init(_a1_obj, 1285u);
        _a1_obj->f_function_index = t1;
        _a1_obj->f_env = l9;
        l7 = (void*) _a1_obj;
        vader_vm_push_val(l3, l6, vader_ref_box(l7));
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 787u) {
        l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l9 = vader_vm_build_struct(l7, l8, l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 631u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        l9 = vader_vm_build_array(l8, l10, l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 637u) {
        l7 = l2.payload.obj;
        l9 = vader_vm_exec_array_slice(l3, l7);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 635u) {
        l9 = vader_vm_exec_array_repeat(l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 633u) {
        l9 = vader_vm_exec_array_push_all(l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 628u) {
        l9 = vader_vm_exec_array_copy(l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 634u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_peek_array_mut(l3, l6, l8, 1431u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
        if (t2 == INT64_C(0)) {
            l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(5);
        } else {
            t0 = l9.payload.obj;
            vader_vm_own_bytes(t0);
            t0 = l9.payload.obj;
            l7 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements;
            t0 = l9.payload.obj;
            l6 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
            t0 = l9.payload.obj;
            l11 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            t2 = vader_chk_add(i64, l6, l11);
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l12 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6];
            t0 = l9.payload.obj;
            t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
            if (t2 == INT64_C(0)) {
                t0 = l9.payload.obj;
                l6 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
                t0 = l9.payload.obj;
                l11 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements)->length;
                if (l6 == l11) {
                    t0 = l9.payload.obj;
                    t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements);
                }
            }
            l7 = l9.payload.obj;
            t0 = l9.payload.obj;
            t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            ((vader_struct_vader_vm_ArrayVal_t*) l7)->f_length = l6;
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_vm_push_val(l3, l6, l12);
        }
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 627u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_peek_array_mut(l3, l6, l8, 1413u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_raw = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) t0);
        t0 = l9.payload.obj;
        t2 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
        if (t2 == INT64_C(0)) {
            t0 = l9.payload.obj;
            l6 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            t0 = l9.payload.obj;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements)->length;
            l13 = l6 == l11;
        } else {
            l13 = false;
        }
        if (l13) {
            t0 = l9.payload.obj;
            vader_array_clear((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_elements);
        } else {
            l7 = l9.payload.obj;
            vader_array_t* _a4_arr = vader_array_new(247u, 0u, 0u, 1949u);
            l14 = (void*) _a4_arr;
            ((vader_struct_vader_vm_ArrayVal_t*) l7)->f_elements = l14;
            VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) l7);
        }
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset = INT64_C(0);
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length = INT64_C(0);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 707u) {
        if (l5) {
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
            t0 = vader_vm_global_at_comptime_trap(l0, l8);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l7 = ((vader_struct_vader_vm_VmState_t*) l0)->f_globals;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l9 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l8];
        vader_vm_push_val(l3, l6, l9);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 708u) {
        if (l5) {
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_bytecode_GlobalSet_t*) t0)->f_index;
            t0 = vader_vm_global_at_comptime_trap(l0, l8);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_VmState_t*) l0)->f_globals;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_GlobalSet_t*) t0)->f_index;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_owned(l3, l6);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l8] = l9;
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 682u) {
        l7 = ((vader_struct_vader_vm_VmState_t*) l0)->f_data_pool;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        l7 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l7)->f_type_id;
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        if (l8 == l10) {
            l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            vader_vm_push_val(l3, l6, vader_ref_box(l7));
        } else {
            l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
            l14 = ((vader_struct_vader_vm_ArrayVal_t*) l7)->f_elements;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) l7)->f_elements)->length;
            vader_struct_vader_vm_ArrayVal_t* _a8_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
            vader_obj_header_init(_a8_obj, 1280u);
            _a8_obj->f_type_id = l8;
            _a8_obj->f_elements = l14;
            _a8_obj->f_offset = INT64_C(0);
            _a8_obj->f_length = l11;
            _a8_obj->f_raw = vader_box_obj(0u, NULL);
            l7 = (void*) _a8_obj;
            vader_vm_push_val(l3, l6, vader_ref_box(l7));
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 681u) {
        t0 = l2.payload.obj;
        l15 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_target;
        t0 = l2.payload.obj;
        l16 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        t4 = vader_vm_convert_int_fast(l3, l15, l16);
        if (!(t4)) {
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            l9 = vader_vm_peek_val(l3, l6);
            t0 = l2.payload.obj;
            l15 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_target;
            t0 = l2.payload.obj;
            l16 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
            l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
            l12 = vader_vm_convert_value(l9, l15, l16, l8);
            if (l12.tag == 1308u) {
                t0 = l12.payload.obj;
                l16 = ((vader_struct_vader_vm_Trap_t*) t0)->f_message;
                l17 = vader_vm_describe_value_tag(l9);
                t5 = concat_6(l16, 30u, l17, 279u, l4, 234u);
                vader_struct_vader_vm_Trap_t* _a9_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a9_obj, 1308u);
                _a9_obj->f_message = t5;
                t0 = (void*) _a9_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            l9 = l12;
            vader_vm_push_val(l3, l6, l9);
        }
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 773u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        if (!(l9.tag == 1309u)) {
            l16 = vader_vm_describe_value_tag(l9);
            l6 = vader_host_std_core_byte_len(l16);
            l7 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l6));
            l6 = INT64_C(0);
            l6 = std_core_write_string_at(l7, l6, 2016u);
            l6 = std_core_write_string_at(l7, l6, l16);
            l6 = std_core_write_string_at(l7, l6, 66u);
            t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
            l11 = ((int64_t) (int32_t) t1);
            l6 = std_core_write_int(l7, l6, l11);
            t5 = std_core_finish_buffer(l7, l6);
            vader_struct_vader_vm_Trap_t* _a10_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a10_obj, 1308u);
            _a10_obj->f_message = t5;
            t0 = (void*) _a10_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        l8 = ((vader_struct_vader_vm_TypeVal_t*) t0)->f_type_id;
        if ((l8 < INT32_C(0))) {
            l13 = true;
        } else {
            l6 = ((int64_t) (int32_t) l8);
            l11 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types)->length;
            l13 = (l6 >= l11);
        }
        if (l13) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(89));
            l6 = INT64_C(0);
            l6 = std_core_write_string_at(l7, l6, 2017u);
            l11 = ((int64_t) (int32_t) l8);
            l6 = std_core_write_int(l7, l6, l11);
            l6 = std_core_write_string_at(l7, l6, 141u);
            t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
            l11 = ((int64_t) (int32_t) t1);
            l6 = std_core_write_int(l7, l6, l11);
            t5 = std_core_finish_buffer(l7, l6);
            vader_struct_vader_vm_Trap_t* _a11_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a11_obj, 1308u);
            _a11_obj->f_message = t5;
            t0 = (void*) _a11_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        l8 = vader_bytecode_size_of_bc_type(t3);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l11 = ((int64_t) (int32_t) l8);
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
        ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 716u) {
        l9 = vader_vm_apply_eq_binop(l3, 1911u, false);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 723u) {
        l9 = vader_vm_apply_eq_binop(l3, 1918u, true);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 664u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_bool(l9, l8, 1476u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_bool(l12, l8, 1476u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l13 = l9.payload.b;
        l18 = l12.payload.b;
        if (l13 == l18) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
        ((int64_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a16_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 665u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_bool(l9, l8, 1477u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_bool(l12, l8, 1477u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l13 = l9.payload.b;
        l18 = l12.payload.b;
        if (l13 != l18) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
        ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a18_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
        ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 662u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_bool(l9, l8, 1474u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_bool(l12, l8, 1474u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t4 = l9.payload.b;
        if (t4) {
            l13 = l12.payload.b;
        } else {
            l13 = false;
        }
        if (l13) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a19_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
        ((int64_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
        ((uint8_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 667u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_bool(l9, l8, 1479u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_bool(l12, l8, 1479u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t4 = l9.payload.b;
        if (t4) {
            l13 = true;
        } else {
            l13 = l12.payload.b;
        }
        if (l13) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a21_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
        ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a22_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l6)
        ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 666u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_bool(l9, l8, 1478u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t4 = l9.payload.b;
        if (t4) {
            l11 = INT64_C(0);
        } else {
            l11 = INT64_C(1);
        }
        vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
        ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a24_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
        ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 784u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_string(l9, l8, 2452u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_string(l12, l8, 2452u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l16 = l9.payload.s;
        l17 = l12.payload.s;
        if (l16 == l17) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l6)
        ((int64_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a26_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l6)
        ((uint8_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 785u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_string(l9, l8, 2454u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_string(l12, l8, 2454u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l16 = l9.payload.s;
        l17 = l12.payload.s;
        if (l16 != l17) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a27_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l6)
        ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l6)
        ((uint8_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 782u) {
        l9 = vader_vm_exec_string_compare(l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 768u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l13 = vader_vm_value_ref_eq(l9, l12);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        if (l13) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a29_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l6)
        ((int64_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a30_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
        ((uint8_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 769u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm_peek_val(l3, l6);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm_peek_val(l3, l6);
        l13 = vader_vm_value_ref_eq(l9, l12);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        if (l13) {
            l11 = INT64_C(0);
        } else {
            l11 = INT64_C(1);
        }
        vader_array_t* _a31_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l6)
        ((int64_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a32_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l6)
        ((uint8_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 789u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        l13 = vader_vm_type_matches(l0, l9, l8);
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        if (l13) {
            l11 = INT64_C(1);
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a33_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l6)
        ((int64_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a34_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l6)
        ((uint8_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 790u) {
        l6 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        vader_struct_vader_vm_TypeVal_t* _a35_obj = (vader_struct_vader_vm_TypeVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_TypeVal_t));
        vader_obj_header_init(_a35_obj, 1309u);
        _a35_obj->f_type_id = t1;
        l7 = (void*) _a35_obj;
        vader_vm_push_val(l3, l6, vader_ref_box(l7));
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 670u) {
        l7 = ((vader_struct_vader_vm_RunHost_t*) l1)->f_obj_handles;
        l9 = vader_vm_build_buffer(l3, l7);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 757u) {
        l9 = vader_vm_load_bytes_op(l3, INT64_C(1), 2090u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t6));
        vader_array_t* _a36_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
        ((int64_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a37_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l6)
        ((uint8_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 752u) {
        l9 = vader_vm_load_bytes_op(l3, INT64_C(4), 2084u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t6));
        vader_array_t* _a38_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l6)
        ((int64_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a39_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l6)
        ((uint8_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 753u) {
        l9 = vader_vm_load_bytes_op(l3, INT64_C(8), 2085u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = ((int64_t) (uint64_t) t6);
        vader_array_t* _a40_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l6)
        ((int64_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a41_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l6)
        ((uint8_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 751u) {
        l9 = vader_vm_load_bytes_op(l3, INT64_C(8), 2083u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t6) }).__vd) }).__vu);
        vader_array_t* _a42_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l6)
        ((int64_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a43_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l6)
        ((uint8_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 781u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_stack_i32(l3, l6, 2445u, 2769u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l9.payload.i);
        t2 = ((int64_t) (uint32_t) (t1 & INT32_C(255)));
        l19 = (uint64_t) (int64_t) t2;
        l9 = vader_vm_store_bytes_op(l3, INT64_C(1), l19, 2445u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 776u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_stack_i32(l3, l6, 2438u, 2769u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l9.payload.i);
        t2 = ((int64_t) (uint32_t) t1);
        l19 = (uint64_t) (int64_t) t2;
        l9 = vader_vm_store_bytes_op(l3, INT64_C(4), l19, 2438u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 777u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_i64(l9, l8, 2440u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int64_t) l9.payload.i);
        t7 = t2;
        l19 = (uint64_t) (int64_t) t7;
        l9 = vader_vm_store_bytes_op(l3, INT64_C(8), l19, 2439u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 775u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_f64(l9, l8, 2437u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t8 = ((double) l9.payload.f);
        t2 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
        l19 = (uint64_t) (int64_t) t2;
        l9 = vader_vm_store_bytes_op(l3, INT64_C(8), l19, 2436u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 764u) {
        l9 = vader_vm_do_memory_copy(l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 671u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_i32(l9, l8, 1501u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l12 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l12 = vader_vm_read_obj(l12, l8, 1502u);
        if (l12.tag == 1308u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((int32_t) l9.payload.i);
        t0 = l12.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t0)->f_bytes)->length;
        l10 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_check_byte_range(l8, INT64_C(0), l6, 1500u, l10);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t0 = l12.payload.obj;
        l7 = ((vader_struct_vader_vm_ObjVal_t*) t0)->f_bytes;
        l11 = ((int64_t) l9.payload.i);
        vader_array_t* _a44_arr = vader_array_slice((vader_array_t*) l7, (int64_t) INT64_C(0), (int64_t) l11);
        t0 = (void*) _a44_arr;
        l16 = vader_host_std_core_bytes_to_string(t0);
        vader_vm_push_val(l3, l6, vader_box_string(287u, l16));
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 672u) {
        l9 = vader_vm_exec_buffer_write_string(l3);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 704u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_f64(l9, l8, 1790u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t8 = ((double) l9.payload.f);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
        vader_array_t* _a45_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l6)
        ((int64_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a46_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l6)
        ((uint8_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 660u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_i64(l9, l8, 1470u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t2 = ((int64_t) l9.payload.i);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t2) }).__vd) }).__vu);
        vader_array_t* _a47_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l6)
        ((int64_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a48_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l6)
        ((uint8_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 691u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_f64(l9, l8, 1776u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t8 = ((double) l9.payload.f);
        l11 = ((int64_t) (int32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = t8 }).__vb));
        vader_array_t* _a49_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l6)
        ((int64_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a50_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l6)
        ((uint8_t*) _a50_slotarr->buf->slots)[_a50_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 659u) {
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm_peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l9 = vader_vm_read_i32(l9, l8, 1469u);
        if (l9.tag == 1308u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t1 = ((int32_t) l9.payload.i);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(t1) }).__vf)) }).__vu);
        vader_array_t* _a51_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l6)
        ((int64_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm_Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm_Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a52_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l6)
        ((uint8_t*) _a52_slotarr->buf->slots)[_a52_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm_Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l3)->f_pc = l8;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_apply_eq_binop(void* l0, vader_string_t l1, bool l2) {
    void* l3 = NULL;
    int64_t l4, l13;
    uint8_t l5, l6;
    bool l7, l8;
    int32_t l9, l10;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    void* t3 = NULL;
    int32_t t4;
    vader_box_t* gc_roots[3] = { &l11, &l12, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 292u);
    l5 = ((uint8_t) t1.payload.i);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 292u);
    l6 = ((uint8_t) t1.payload.i);
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
        t2 = vader_vm_is_i32_tag(l5);
        if (t2) {
            l8 = vader_vm_is_i32_tag(l6);
        } else {
            l8 = false;
        }
        if (l8) {
            l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(2));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            l9 = ((int32_t) (int64_t) t0);
            l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
            l10 = ((int32_t) (int64_t) t0);
            l7 = l9 == l10;
        } else {
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(2));
            l11 = vader_vm_peek_val(l0, l4);
            l9 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
            l11 = vader_vm_read_i32(l11, l9, l1);
            t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            l12 = vader_vm_peek_val(l0, l4);
            l9 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
            l12 = vader_vm_read_i32(l12, l9, l1);
            if (l11.tag == 1308u) {
                t3 = l11.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l12.tag == 1308u) {
                t3 = l12.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = ((int32_t) l11.payload.i);
            l10 = ((int32_t) l12.payload.i);
            l7 = l9 == l10;
        }
    }
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
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
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) INT32_C(3);
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l4;
    t4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l9 = vader_chk_add(i32, t4, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l9;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_array_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 1280u) {
            t1 = l2.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_vm_array_bytes(void* l0, int64_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    uint8_t l9;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l4, &t3 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw;
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.s;
        l5 = vader_host_std_core_bytes(t0);
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        t1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        l7 = vader_chk_add(i64, t1, l1);
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l5, (int64_t) l6, (int64_t) l7);
        t2 = (void*) _a0_arr;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(17u, 0u, 1u, 292u);
    l5 = (void*) _a1_arr;
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements;
        t1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        l7 = vader_chk_add(i64, t1, l6);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l4 = vader_vm_read_i64(t3, l2, l3);
        if (l4.tag == 1308u) {
            t2 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int64_t) l4.payload.i);
        t4 = (((int32_t) (int64_t) t1) & INT32_C(255));
        l9 = (uint8_t) (int32_t) t4;
        vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l9);
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_bc_value_to_vm(vader_box_t l0, void* l1) {
    uint8_t l2;
    uint64_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    vader_box_t* gc_roots[3] = { &l0, &l8, &t2 };
    void** gc_raw_roots[4] = { &l1, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 657u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        { vader_box_t __vret = vader_box_string(287u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_bits;
        t2 = vader_vm_value_from_bits(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 658u) {
        vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1949u);
        l4 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l8 = vader_vm_bc_value_to_vm(t2, l1);
            vader_array_push((vader_array_t*) l4, l8);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_symbol_id;
        t3 = vader_vm_type_id_for_symbol(l1, l9);
        vader_struct_vader_vm_StructVal_t* _a2_obj = (vader_struct_vader_vm_StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StructVal_t));
        vader_obj_header_init(_a2_obj, 1305u);
        _a2_obj->f_type_id = t3;
        _a2_obj->f_fields = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 655u)) {
        { vader_box_t __vret = vader_box_i32(290u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l4 = (void*) _a3_arr;
    t0 = l0.payload.obj;
    l5 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l8 = vader_vm_bc_value_to_vm(t2, l1);
        vader_array_push((vader_array_t*) l4, l8);
        l7 = (l7 + INT64_C(1));
    }
    l6 = ((vader_array_t*) l4)->length;
    vader_struct_vader_vm_ArrayVal_t* _a5_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a5_obj, 1280u);
    _a5_obj->f_type_id = INT32_C(0);
    _a5_obj->f_elements = l4;
    _a5_obj->f_offset = INT64_C(0);
    _a5_obj->f_length = l6;
    _a5_obj->f_raw = vader_box_obj(0u, NULL);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_binary_op(vader_box_t l0, void* l1, int64_t l2) {
    vader_box_t l3;
    bool t0;
    void* t1;
    int32_t t2;
    if (l0.tag == 709u) {
        l3 = vader_box_i32(290u, INT32_C(2));
        return l3;
    }
    if (l0.tag == 728u) {
        l3 = vader_box_i32(290u, INT32_C(3));
    } else if (l0.tag == 722u) {
        l3 = vader_box_i32(290u, INT32_C(4));
    } else if (l0.tag == 715u) {
        l3 = vader_box_i32(290u, INT32_C(5));
    } else if (l0.tag == 721u) {
        l3 = vader_box_i32(290u, INT32_C(6));
    } else if (l0.tag == 710u) {
        l3 = vader_box_i32(290u, INT32_C(7));
    } else if (l0.tag == 712u) {
        l3 = vader_box_i32(290u, INT32_C(8));
    } else if (l0.tag == 713u) {
        l3 = vader_box_i32(290u, INT32_C(9));
    } else if (l0.tag == 725u) {
        l3 = vader_box_i32(290u, INT32_C(10));
    } else if (l0.tag == 726u) {
        l3 = vader_box_i32(290u, INT32_C(11));
    } else if (l0.tag == 727u) {
        l3 = vader_box_i32(290u, INT32_C(12));
    } else if (l0.tag == 791u) {
        l3 = vader_box_i32(290u, INT32_C(15));
    } else if (l0.tag == 796u) {
        l3 = vader_box_i32(290u, INT32_C(16));
    } else if (l0.tag == 716u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(290u, INT32_C(17));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 723u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(290u, INT32_C(18));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 720u) {
        l3 = vader_box_i32(290u, INT32_C(19));
    } else if (l0.tag == 719u) {
        l3 = vader_box_i32(290u, INT32_C(20));
    } else if (l0.tag == 718u) {
        l3 = vader_box_i32(290u, INT32_C(21));
    } else if (l0.tag == 717u) {
        l3 = vader_box_i32(290u, INT32_C(22));
    } else if (l0.tag == 795u) {
        l3 = vader_box_i32(290u, INT32_C(23));
    } else if (l0.tag == 794u) {
        l3 = vader_box_i32(290u, INT32_C(24));
    } else if (l0.tag == 793u) {
        l3 = vader_box_i32(290u, INT32_C(25));
    } else if (l0.tag == 792u) {
        l3 = vader_box_i32(290u, INT32_C(26));
    } else if (l0.tag == 729u) {
        l3 = vader_box_i32(290u, INT32_C(27));
    } else if (l0.tag == 748u) {
        l3 = vader_box_i32(290u, INT32_C(28));
    } else if (l0.tag == 742u) {
        l3 = vader_box_i32(290u, INT32_C(29));
    } else if (l0.tag == 735u) {
        l3 = vader_box_i32(290u, INT32_C(30));
    } else if (l0.tag == 741u) {
        l3 = vader_box_i32(290u, INT32_C(31));
    } else if (l0.tag == 730u) {
        l3 = vader_box_i32(290u, INT32_C(32));
    } else if (l0.tag == 732u) {
        l3 = vader_box_i32(290u, INT32_C(33));
    } else if (l0.tag == 733u) {
        l3 = vader_box_i32(290u, INT32_C(34));
    } else if (l0.tag == 745u) {
        l3 = vader_box_i32(290u, INT32_C(35));
    } else if (l0.tag == 746u) {
        l3 = vader_box_i32(290u, INT32_C(36));
    } else if (l0.tag == 747u) {
        l3 = vader_box_i32(290u, INT32_C(37));
    } else if (l0.tag == 797u) {
        l3 = vader_box_i32(290u, INT32_C(40));
    } else if (l0.tag == 802u) {
        l3 = vader_box_i32(290u, INT32_C(41));
    } else if (l0.tag == 736u) {
        l3 = vader_box_i32(290u, INT32_C(42));
    } else if (l0.tag == 743u) {
        l3 = vader_box_i32(290u, INT32_C(43));
    } else if (l0.tag == 740u) {
        l3 = vader_box_i32(290u, INT32_C(44));
    } else if (l0.tag == 739u) {
        l3 = vader_box_i32(290u, INT32_C(45));
    } else if (l0.tag == 738u) {
        l3 = vader_box_i32(290u, INT32_C(46));
    } else if (l0.tag == 737u) {
        l3 = vader_box_i32(290u, INT32_C(47));
    } else if (l0.tag == 801u) {
        l3 = vader_box_i32(290u, INT32_C(48));
    } else if (l0.tag == 800u) {
        l3 = vader_box_i32(290u, INT32_C(49));
    } else if (l0.tag == 799u) {
        l3 = vader_box_i32(290u, INT32_C(50));
    } else if (l0.tag == 798u) {
        l3 = vader_box_i32(290u, INT32_C(51));
    } else if (l0.tag == 692u) {
        l3 = vader_box_i32(290u, INT32_C(52));
    } else if (l0.tag == 703u) {
        l3 = vader_box_i32(290u, INT32_C(53));
    } else if (l0.tag == 700u) {
        l3 = vader_box_i32(290u, INT32_C(54));
    } else if (l0.tag == 694u) {
        l3 = vader_box_i32(290u, INT32_C(55));
    } else if (l0.tag == 695u) {
        l3 = vader_box_i32(290u, INT32_C(57));
    } else if (l0.tag == 701u) {
        l3 = vader_box_i32(290u, INT32_C(58));
    } else if (l0.tag == 699u) {
        l3 = vader_box_i32(290u, INT32_C(59));
    } else if (l0.tag == 698u) {
        l3 = vader_box_i32(290u, INT32_C(60));
    } else if (l0.tag == 697u) {
        l3 = vader_box_i32(290u, INT32_C(61));
    } else if (l0.tag == 696u) {
        l3 = vader_box_i32(290u, INT32_C(62));
    } else if (l0.tag == 664u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(290u, INT32_C(63));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 665u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(290u, INT32_C(64));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 662u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(290u, INT32_C(65));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 667u) {
        t0 = vader_vm_operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(290u, INT32_C(66));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 679u) {
        t1 = l0.payload.obj;
        t2 = vader_vm_checked_register_op(t1);
        l3 = vader_box_i32(290u, t2);
    } else {
        l3 = vader_box_obj(0u, NULL);
    }
    return l3;
}

static int64_t vader_vm_bits_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return t0;
}

static void vader_vm_boxed(void* l0, int64_t l1, vader_box_t l2, int64_t l3, int64_t l4) {
    int32_t l5, l6, l8;
    int64_t l7;
    int64_t t0, t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_vm_flush(l0, l1);
    l5 = vader_vm_pop_to(l0, l3);
    vader_array_push((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_boxed, l2);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_boxed)->length;
    t1 = vader_chk_sub(i64, t0, INT64_C(1));
    l6 = ((int32_t) (int64_t) t1);
    l7 = (l4 << INT64_C(8));
    l8 = ((int32_t) (int64_t) (l3 | l7));
    vader_vm_emit(l0, l1, INT32_C(119), l6, l5, l8);
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        l6 = ((int32_t) (int64_t) l7);
        l8 = vader_chk_add(i32, l5, l6);
        vader_vm_push_register(l0, l8);
        l7 = (l7 + INT64_C(1));
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
        vader_obj_header_init(_a0_obj, 1288u);
        _a0_obj->f_op = l1;
        _a0_obj->f_swap = l2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_FusedBranch_t* _a1_obj = (vader_struct_vader_vm_FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FusedBranch_t));
    vader_obj_header_init(_a1_obj, 1288u);
    _a1_obj->f_op = l3;
    _a1_obj->f_swap = l4;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_budget_trap(int64_t l0) {
    void* l1 = NULL;
    int64_t l2;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(84));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 1611u);
    l2 = std_core_write_int(l1, l2, l0);
    l2 = std_core_write_string_at(l1, l2, 160u);
    t0 = std_core_finish_buffer(l1, l2);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1308u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_build_array(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[3] = { &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(76));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1425u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l3, l4, l5);
        l4 = std_core_write_string_at(l3, l4, 109u);
        t0 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core_write_int(l3, l4, l5);
        t1 = std_core_finish_buffer(l3, l4);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) (int32_t) l1);
    t3 = ((vader_struct_vader_vm_Frame_t*) l2)->f_sp;
    l5 = vader_chk_sub(i64, t3, l4);
    vader_array_t* _a1_arr = vader_array_new(247u, 0u, 0u, 1949u);
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (int64_t) l4);
    l3 = (void*) _a2_arr;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        l7 = vader_chk_add(i64, l5, l6);
        l8 = vader_vm_peek_owned(l2, l7);
        vader_array_push((vader_array_t*) l3, l8);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_array_t*) l3)->length;
    vader_struct_vader_vm_ArrayVal_t* _a3_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1280u);
    _a3_obj->f_type_id = l0;
    _a3_obj->f_elements = l3;
    _a3_obj->f_offset = INT64_C(0);
    _a3_obj->f_length = l4;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    l3 = (void*) _a3_obj;
    vader_vm_push_val(l2, l5, vader_ref_box(l3));
    l4 = vader_chk_add(i64, l5, INT64_C(1));
    ((vader_struct_vader_vm_Frame_t*) l2)->f_sp = l4;
    t0 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
    l9 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l2)->f_pc = l9;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_build_buffer(void* l0, void* l1) {
    int64_t l2, l6;
    vader_box_t l3 = vader_box_null();
    int32_t l4;
    void* l5 = NULL;
    void* l7 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm_peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_vm_read_i32(l3, l4, 1498u);
    if (l3.tag == 1308u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l3.payload.i);
    if ((t2 < INT32_C(0))) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(75));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l5, l2, 1499u);
        t2 = ((int32_t) l3.payload.i);
        l6 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l5, l2, l6);
        l2 = std_core_write_string_at(l5, l2, 109u);
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l6 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l5, l2, l6);
        t3 = std_core_finish_buffer(l5, l2);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(17u, 0u, 1u, 292u);
    l5 = (void*) _a1_arr;
    t2 = ((int32_t) l3.payload.i);
    l2 = ((int64_t) (int32_t) t2);
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l2);
    l5 = (void*) _a2_arr;
    l2 = INT64_C(0);
    t2 = ((int32_t) l3.payload.i);
    l6 = ((int64_t) (int32_t) t2);
    vader_array_t* _pc83_hdr = (vader_array_t*) l5;
    size_t _pc83_len = _pc83_hdr->length;
    size_t _pc83_cap = (_pc83_hdr->offset == 0 && !vader_array_is_borrowed(_pc83_hdr) && _pc83_hdr->length >= _pc83_hdr->buf->length) ? _pc83_hdr->capacity : (size_t) 0;
    void* _pc83_slots = _pc83_hdr->buf->slots;
    for (;;) {
        if ((l2 < l6)) {
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
            l2 = (l2 + INT64_C(1));
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
    t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)] = (int32_t) l4;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
    vader_array_t* _a4_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l7 = (void*) _a4_arr;
    vader_struct_vader_vm_ObjVal_t* _a5_obj = (vader_struct_vader_vm_ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ObjVal_t));
    vader_obj_header_init(_a5_obj, 1293u);
    _a5_obj->f_handle = l4;
    _a5_obj->f_type_id = INT32_C(0);
    _a5_obj->f_bytes = l5;
    _a5_obj->f_slots = l7;
    l5 = (void*) _a5_obj;
    vader_vm_push_val(l0, l2, vader_ref_box(l5));
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l4;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_build_main_args(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    int64_t l5, l7;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    uint8_t l9;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l8, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1949u);
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
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l7));
        l7 = INT64_C(0);
        l7 = std_core_write_string_at(l8, l7, 1704u);
        l7 = std_core_write_string_at(l8, l7, l6);
        l7 = std_core_write_string_at(l8, l7, 244u);
        l7 = std_core_write_int(l8, l7, l5);
        l7 = std_core_write_string_at(l8, l7, 148u);
        t1 = std_core_finish_buffer(l8, l7);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1308u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(0), 292u);
    l9 = vader_vm_tags_of_val(((uint8_t) t3.payload.i));
    t4 = vader_vm_tags_within((uint8_t) 64, l9);
    if (!(t4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t3 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) INT32_C(0), 292u);
        l6 = vader_bytecode_val_type_name(((uint8_t) t3.payload.i));
        l10 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
        t1 = concat_5(1704u, l10, 245u, l6, 310u);
        vader_struct_vader_vm_Trap_t* _a4_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a4_obj, 1308u);
        _a4_obj->f_message = t1;
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a5_arr = vader_array_new(14u, 1u, 0u, 287u);
        vader_array_box_slots(_a5_arr->buf)[_a5_arr->offset + 0u] = vader_box_string(287u, 451u);
        t2 = (void*) _a5_arr;
        l4 = vader_vm_string_array_to_value(t2, l2);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm_string_array_to_value(l1, l2);
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_build_struct(void* l0, int32_t l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l11 = vader_box_null();
    void* l4 = NULL;
    int64_t l5, l6, l7, l10;
    int32_t l8;
    uint8_t l9;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l11, &t4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 653u)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(79));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l4, l5, 2468u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l4, l5, l6);
        l5 = std_core_write_string_at(l4, l5, 112u);
        t0 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
        l6 = ((int64_t) (int32_t) t0);
        l5 = std_core_write_int(l4, l5, l6);
        t1 = std_core_finish_buffer(l4, l5);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1308u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l3.payload.obj;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields)->length;
    t3 = ((vader_struct_vader_vm_Frame_t*) l2)->f_sp;
    l6 = vader_chk_sub(i64, t3, l5);
    vader_array_t* _a2_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l4 = (void*) _a2_arr;
    if ((INT64_C(0) < l5)) {
        l7 = l5;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l7);
    l4 = (void*) _a3_arr;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        t2 = l3.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_type_index;
        l9 = vader_vm_field_valtype(l0, l8);
        l10 = vader_chk_add(i64, l6, l7);
        t4 = vader_vm_peek_owned(l2, l10);
        l11 = vader_vm_narrow_mask(t4, l9);
        vader_array_push((vader_array_t*) l4, l11);
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_vm_StructVal_t* _a5_obj = (vader_struct_vader_vm_StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StructVal_t));
    vader_obj_header_init(_a5_obj, 1305u);
    _a5_obj->f_type_id = l1;
    _a5_obj->f_fields = l4;
    l4 = (void*) _a5_obj;
    vader_vm_push_val(l2, l6, vader_ref_box(l4));
    l5 = vader_chk_add(i64, l6, INT64_C(1));
    ((vader_struct_vader_vm_Frame_t*) l2)->f_sp = l5;
    t0 = ((vader_struct_vader_vm_Frame_t*) l2)->f_pc;
    l8 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l2)->f_pc = l8;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_vm_bytes_to_value(vader_string_t l0, int32_t l1) {
    void* l2 = NULL;
    int64_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core_byte_len(l0);
    vader_struct_vader_vm_ArrayVal_t* _a1_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a1_obj, 1280u);
    _a1_obj->f_type_id = l1;
    _a1_obj->f_elements = l2;
    _a1_obj->f_offset = INT64_C(0);
    _a1_obj->f_length = l3;
    _a1_obj->f_raw = vader_box_string(287u, l0);
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_call_import(void* l0, void* l1, int32_t l2, int64_t l3, int32_t l4, bool l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    int64_t l8, l9, l10;
    vader_box_t l11 = vader_box_null();
    int32_t l14, l15, l16;
    uint8_t l18;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    uint8_t t2;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l6, &l7, &l12, &l13, &l17, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    vader_array_t* _a1_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l7 = (void*) _a1_arr;
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_params)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l8);
    l7 = (void*) _a2_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_params)->length;
    while ((l8 < l9)) {
        l10 = vader_chk_add(i64, l3, l8);
        l11 = vader_vm_register_value(l1, l10);
        vader_array_push((vader_array_t*) l7, l11);
        l8 = (l8 + INT64_C(1));
    }
    l12 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_gc_state;
    l13 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_sched_state;
    l14 = ((vader_struct_vader_vm_VmState_t*) l0)->f_string_array_type_id;
    l15 = ((vader_struct_vader_vm_VmState_t*) l0)->f_u8_array_type_id;
    l16 = ((vader_struct_vader_vm_VmState_t*) l0)->f_io_error_type_id;
    l17 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
    l11 = vader_vm_debug_controller(l1);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_import_ids);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
    t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 292u);
    l18 = ((uint8_t) t0.payload.i);
    l11 = vader_vm_dispatch_import(l6, l7, INT64_C(0), l12, l13, l4, l14, l15, l16, l17, l5, l11, l18);
    if (l11.tag == 1308u) {
        t1 = l11.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature);
    if (t2 != INT32_C(14)) {
        t1 = l11.payload.obj;
        l11 = ((vader_struct_vader_vm_HostOk_t*) t1)->f_value;
        vader_vm_set_register(l1, l3, l11);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_call_results(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_module;
    if (l1.tag == 675u) {
        l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l2)->f_functions;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        { vader_box_t __vret = vader_ref_box(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_signature)->f_results); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 676u) {
        l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l2)->f_imports;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        { vader_box_t __vret = vader_ref_box(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) t0)->f_signature)->f_results); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 806u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_virtual_results;
    t0 = l1.payload.obj;
    l5 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
    l6 = std_collections_MutableMap_std_core_Index_at__string__Any(l2, l5);
    if (l6.tag == 0u) {
        vader_array_t* _a2_arr = vader_array_new(17u, 1u, 1u, 292u);
        ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(17);
        t0 = (void*) _a2_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l6.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_canonical(void* l0, int64_t l1) {
    int64_t t0, t1;
    t0 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack_base;
    t1 = vader_chk_add(i64, t0, l1);
    return ((int32_t) (int64_t) t1);
}

static vader_box_t vader_vm_check_byte_range(int32_t l0, int64_t l1, int64_t l2, vader_string_t l3, int32_t l4) {
    vader_string_t l5 = 0;
    int64_t l6, l8;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        l5 = l3;
        l6 = vader_host_std_core_byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(67) + l6));
        l6 = INT64_C(0);
        l6 = std_core_write_string_at(l7, l6, l5);
        l6 = std_core_write_string_at(l7, l6, 137u);
        l8 = ((int64_t) (int32_t) l0);
        l6 = std_core_write_int(l7, l6, l8);
        l6 = std_core_write_string_at(l7, l6, 109u);
        l8 = ((int64_t) (int32_t) l4);
        l6 = std_core_write_int(l7, l6, l8);
        t0 = std_core_finish_buffer(l7, l6);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int64_t) (int32_t) l0);
    t2 = vader_chk_add(i64, l6, l1);
    if (!((t2 > l2))) {
        { vader_box_t __vret = vader_box_i64(291u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l8 = vader_host_std_core_byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l8));
    l8 = INT64_C(0);
    l8 = std_core_write_string_at(l7, l8, l5);
    l8 = std_core_write_string_at(l7, l8, 137u);
    l8 = std_core_write_int(l7, l8, l6);
    l8 = std_core_write_string_at(l7, l8, 28u);
    l8 = std_core_write_int(l7, l8, l1);
    l8 = std_core_write_string_at(l7, l8, 278u);
    l8 = std_core_write_int(l7, l8, l2);
    l8 = std_core_write_string_at(l7, l8, 66u);
    l6 = ((int64_t) (int32_t) l4);
    l8 = std_core_write_int(l7, l8, l6);
    t0 = std_core_finish_buffer(l7, l8);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t0;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_check_module_tags(void* l0, void* l1) {
    int64_t l2, l3, l4, l7, l8, l10;
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
    l2 = INT64_C(2);
    l3 = INT64_C(0);
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
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
        while ((l7 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l6)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
            if ((t0 < INT64_C(0))) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l9 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            l10 = INT64_C(1);
            l11 = (l10 <= l2);
            while (l11) {
                l13 = vader_vm_accepted_tags(l9, l10);
                if (l13.tag == 0u) {
                    l11 = (l10 < l2);
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                l12 = ((uint8_t) l13.payload.i);
                l14 = vader_vm_stack_tags(l6, l7, l10);
                t1 = vader_vm_tags_within(l14, l12);
                if (!(t1)) {
                    l15 = vader_vm_display_tags(l14);
                    l16 = vader_vm_display_tags(l12);
                    l17 = vader_vm_op_text(l9);
                    l18 = concat_6(916u, l17, 1057u, l15, 177u, l16);
                    t2 = vader_vm_defect(l5, l7, l18);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l11 = (l10 < l2);
                l10 = (l10 + INT64_C(1));
            }
            l7 = (l7 + INT64_C(1));
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static int32_t vader_vm_checked_neg_register_op(uint8_t l0) {
    if (l0 == INT32_C(2)) {
        return INT32_C(71);
    }
    if (!(l0 == INT32_C(3))) {
        return INT32_C(82);
    }
    return INT32_C(75);
}

static void* vader_vm_checked_neg_trap(uint8_t l0, void* l1, int64_t l2) {
    vader_string_t l3 = 0;
    int64_t l4, l6;
    void* l5 = NULL;
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
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l4));
    l4 = INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 66u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    l6 = ((int64_t) (int32_t) t0);
    l4 = std_core_write_int(l5, l4, l6);
    t1 = std_core_finish_buffer(l5, l4);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t1;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_checked_register_op(void* l0) {
    uint8_t l1;
    int32_t l2;
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

static vader_box_t vader_vm_checked_registers(uint8_t l0, uint8_t l1, void* l2, int64_t l3, int64_t l4) {
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

static void* vader_vm_checked_trap(uint8_t l0, uint8_t l1, void* l2, int64_t l3) {
    vader_string_t l4 = 0;
    int64_t l5, l7;
    void* l6 = NULL;
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
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l5));
    l5 = INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 66u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core_write_int(l6, l5, l7);
    t1 = std_core_finish_buffer(l6, l5);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t1;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm_clamp_nonneg(int32_t l0) {
    if ((l0 < INT32_C(0))) {
        return INT64_C(0);
    }
    return ((int64_t) (int32_t) l0);
}

static bool vader_vm_class_matches(vader_box_t l0, uint8_t l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = vader_bytecode_val_type_name(l1);
    l3 = vader_vm_describe_value_tag(l0);
    if (l2 == l3) {
        return true;
    }
    t0 = vader_vm_is_integer_alias(l1);
    if (t0) {
        if (l0.tag == 290u) {
            return true;
        }
        return l0.tag == 291u;
    }
    if (l1 == INT32_C(8)) {
        return (l0.tag == 296u || l0.tag == 297u);
    }
    if (!(l1 == INT32_C(15))) {
        return false;
    }
    if (l0.tag == 291u) {
        return true;
    }
    return l0.tag == 290u;
}

static void vader_vm_collect_constants(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 772u) {
            t0 = l6.payload.obj;
            vader_vm_add_constant(((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value, l1, l2);
        } else if ((l6.tag == 663u || l6.tag == 678u || l6.tag == 693u || l6.tag == 714u || l6.tag == 734u || l6.tag == 765u)) {
            vader_vm_add_constant(l6, l1, l2);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_vm_constant_index(void* l0, void* l1, void* l2) {
    int64_t l3, l4, l5, l6;
    uint8_t l7, l8;
    vader_box_t t0;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        l6 = ((vader_struct_vader_vm_Scalar_t*) l2)->f_bits;
        if (l5 == l6) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 292u);
            l7 = ((uint8_t) t0.payload.i);
            l8 = ((vader_struct_vader_vm_Scalar_t*) l2)->f_tag;
            if (l7 == l8) {
                return l3;
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return INT64_C(-1);
}

static bool vader_vm_convert_int_fast(void* l0, uint8_t l1, vader_string_t l2) {
    int64_t l3, l5, l7;
    uint8_t l4;
    bool l6;
    void* l8;
    int64_t t0;
    vader_box_t t1;
    if (l1 != INT32_C(0)) {
        if (l1 != INT32_C(1)) {
            return false;
        }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 292u);
    l4 = ((uint8_t) t1.payload.i);
    l5 = INT64_C(0);
    if (l4 == INT32_C(0)) {
        if (l1 == INT32_C(1)) {
            l6 = vader_vm_is_unsigned_source(l2);
        } else {
            l6 = false;
        }
        if (l6) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
        } else {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
            l5 = ((int64_t) (int32_t) ((int32_t) (int64_t) t0));
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
        t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l3];
        l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
    } else {
        if (!(l4 == INT32_C(3))) {
            return false;
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
        t0 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l3];
        if (t0 != INT64_C(0)) {
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
    uint32_t l6;
    bool l7;
    bool t0;
    int32_t t1;
    int64_t t2;
    void* t3 = NULL;
    double t4;
    uint32_t t5;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l5 };
    void** gc_raw_roots[1] = { &t3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 290u) {
        t0 = vader_vm_is_unsigned_source(l2);
        if (t0) {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i64(291u, ((int64_t) (uint32_t) t1));
        } else {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i32(290u, t1);
        }
    } else {
        l4 = l0;
    }
    if (l1 == INT32_C(0)) {
        if (l4.tag == 290u) {
            t1 = ((int32_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i32(290u, t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm_read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1308u)) {
            t2 = ((int64_t) l5.payload.i);
            { vader_box_t __vret = vader_box_i32(290u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        if (l4.tag == 291u) {
            t2 = ((int64_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i64(291u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm_read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1308u)) {
            t2 = ((int64_t) l5.payload.i);
            { vader_box_t __vret = vader_box_i64(291u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        if ((l4.tag == 296u || l4.tag == 297u)) {
            t4 = ((double) l4.payload.f);
            { vader_box_t __vret = vader_box_f64(297u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm_read_numeric_as_f64(l4, l3);
        if (!(l5.tag == 1308u)) {
            t4 = ((double) l5.payload.f);
            { vader_box_t __vret = vader_box_f64(297u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 286u) {
        t5 = ((uint32_t) l4.payload.i);
        { vader_box_t __vret = vader_box_i32(286u, (int32_t) t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm_read_numeric_as_i64(l4, l3);
    if (l4.tag == 1308u) {
        t3 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int64_t) l4.payload.i);
    t1 = ((int32_t) (int64_t) t2);
    l6 = (uint32_t) (int32_t) t1;
    if ((l6 > INT32_C(55295))) {
        if ((l6 < INT32_C(57344))) {
            l7 = true;
        } else {
            l7 = (l6 > INT32_C(1114111));
        }
        if (l7) {
            vader_unreachable("value out of range: no Unicode scalar value");
        } else {
            { vader_box_t __vret = vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l6)); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        { vader_box_t __vret = vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l6)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
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

static vader_box_t vader_vm_debug_write(void* l0, void* l1, int64_t l2, int32_t l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    int64_t l6, l10;
    bool l9;
    void* l11 = NULL;
    int32_t l12;
    vader_string_t l13 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t* gc_roots[4] = { &l5, &l7, &l8, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l11, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l13, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l5 = vader_vm_read_i64(t0, l3, 2486u);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_chk_add(i64, l2, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
    l7 = vader_vm_read_array(t0, l3, 2483u);
    if (l7.tag == 1308u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_chk_add(i64, l2, INT64_C(2));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
    l8 = vader_vm_read_i64(t0, l3, 2485u);
    if (l8.tag == 1308u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int64_t) l8.payload.i);
    if ((t2 < INT64_C(0))) {
        l9 = true;
    } else {
        l6 = ((int64_t) l8.payload.i);
        t1 = l7.payload.obj;
        l10 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
        l9 = (l6 > l10);
    }
    if (l9) {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(83));
        l6 = INT64_C(0);
        l6 = std_core_write_string_at(l11, l6, 2482u);
        l10 = ((int64_t) (int32_t) l3);
        l6 = std_core_write_int(l11, l6, l10);
        l6 = std_core_write_string_at(l11, l6, 406u);
        l10 = ((int64_t) l8.payload.i);
        l6 = std_core_write_int(l11, l6, l10);
        l6 = std_core_write_string_at(l11, l6, 80u);
        t3 = std_core_finish_buffer(l11, l6);
        vader_struct_vader_vm_Trap_t* _a3_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a3_obj, 1308u);
        _a3_obj->f_message = t3;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l7.payload.obj;
    l6 = ((int64_t) l8.payload.i);
    l7 = vader_vm_array_bytes(l11, l6, l3, 2484u);
    if (l7.tag == 1308u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = ((vader_struct_vader_vm_DebugController_t*) l4)->f_output_sink;
    t2 = ((int64_t) l5.payload.i);
    l12 = vader_chk_sub(i32, ((int32_t) (int64_t) t2), INT32_C(1));
    t1 = l7.payload.obj;
    l13 = vader_host_std_core_bytes_to_string(t1);
    vader_fn_t* _a4_fnobj = (vader_fn_t*) l11;
    ((vader_fn_erased_sig_2_t) _a4_fnobj->code)(_a4_fnobj->env, vader_box_i32(290u, l12), vader_box_string(287u, l13));
    t4 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    if (!(t4 == INT32_C(10))) {
        t2 = ((int64_t) l8.payload.i);
        vader_struct_vader_vm_HostOk_t* _a5_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a5_obj, 1289u);
        _a5_obj->f_value = vader_box_i64(291u, t2);
        t1 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_HostOk_t* _a6_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
    vader_obj_header_init(_a6_obj, 1289u);
    _a6_obj->f_value = vader_box_bool(285u, true);
    t1 = (void*) _a6_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_defect(void* l0, int64_t l1, vader_string_t l2) {
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
    l4 = ((int32_t) (int64_t) l1);
    vader_struct_vader_vm_VerifyError_t* _a0_obj = (vader_struct_vader_vm_VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VerifyError_t));
    vader_obj_header_init(_a0_obj, 1311u);
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
    int64_t l8, l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1285u)) {
        l4 = l1;
        l5 = concat_2(l3, 79u);
        t0 = vader_vm_read_fn(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_function_index;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    l4 = vader_vm_validate_fn_index(l6, l7, l2, l3);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_function_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_signature)->f_params)->length;
    if (!(t2 != INT64_C(1))) {
        t1 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_name;
    l8 = vader_host_std_core_byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(73) + l8));
    l8 = INT64_C(0);
    l8 = std_core_write_string_at(l7, l8, 1658u);
    l8 = std_core_write_string_at(l7, l8, l5);
    l8 = std_core_write_string_at(l7, l8, 243u);
    l9 = ((int64_t) (int32_t) l2);
    l8 = std_core_write_int(l7, l8, l9);
    t3 = std_core_finish_buffer(l7, l8);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t3;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_describe_obj(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(106));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 447u);
    t0 = ((vader_struct_vader_vm_ObjVal_t*) l0)->f_handle;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 169u);
    t0 = ((vader_struct_vader_vm_ObjVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 70u);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) l0)->f_bytes)->length;
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 158u);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) l0)->f_slots)->length;
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 457u);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_describe_value_tag(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 290u) {
        l1 = 1902u;
        return l1;
    }
    if (l0.tag == 291u) {
        l1 = 1924u;
    } else if ((l0.tag == 296u || l0.tag == 297u)) {
        l1 = 1777u;
    } else if (l0.tag == 287u) {
        l1 = 2447u;
    } else if (l0.tag == 1305u) {
        l1 = 2459u;
    } else if (l0.tag == 1280u) {
        l1 = 1409u;
    } else if (l0.tag == 1285u) {
        l1 = 1832u;
    } else if (l0.tag == 1292u) {
        l1 = 2227u;
    } else if (l0.tag == 285u) {
        l1 = 1473u;
    } else if (l0.tag == 286u) {
        l1 = 1581u;
    } else if (l0.tag == 1284u) {
        l1 = 1720u;
    } else if (l0.tag == 1309u) {
        l1 = 2541u;
    } else {
        if (!(l0.tag == 1293u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2230u;
    }
    return l1;
}

static void vader_vm_detach_array_view(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3, l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    int64_t t1;
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
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    while ((l2 < l3)) {
        t1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        l4 = vader_chk_add(i64, t1, l2);
        l5 = vader_vm_element_at(l0, l4);
        vader_array_push((vader_array_t*) l1, l5);
        l2 = (l2 + INT64_C(1));
    }
    ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) l0);
    ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset = INT64_C(0);
    ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_vm_ArrayVal_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_dispatch_extern(void* l0, void* l1, int64_t l2, int32_t l3, void* l4, vader_box_t l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    void* l30 = NULL;
    void* l36 = NULL;
    void* l43 = NULL;
    void* l44 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l62 = NULL;
    void* l73 = NULL;
    void* l81 = NULL;
    void* l86 = NULL;
    void* l87 = NULL;
    void* l90 = NULL;
    void* l93 = NULL;
    void* l104 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l12 = 0;
    vader_string_t l31 = 0;
    vader_string_t l32 = 0;
    vader_string_t l45 = 0;
    vader_string_t l53 = 0;
    vader_string_t l57 = 0;
    vader_string_t l58 = 0;
    vader_string_t l71 = 0;
    vader_string_t l98 = 0;
    vader_string_t l99 = 0;
    vader_string_t l111 = 0;
    int64_t l8, l10, l13, l19, l20, l22, l23, l26, l28, l29, l33, l34, l35, l37, l38, l39, l40, l41, l42, l48, l55, l59, l60, l61, l63, l64, l66, l67, l68, l72, l74, l75, l76, l78, l79, l82, l83, l84, l85, l88, l91, l92, l94, l96, l102, l103, l106, l108, l114;
    vader_box_t l11 = vader_box_null(), l25 = vader_box_null(), l46 = vader_box_null(), l52 = vader_box_null(), l54 = vader_box_null(), l70 = vader_box_null(), l80 = vader_box_null(), l95 = vader_box_null(), l97 = vader_box_null(), l100 = vader_box_null(), l110 = vader_box_null(), l112 = vader_box_null();
    uint8_t l47, l65, l77, l89, l101, l105, l107, l109, l113;
    bool l56;
    int32_t l69;
    int64_t t0, t5;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    int32_t t6, t9;
    uint8_t t7;
    double t8;
    vader_box_t* gc_roots[14] = {
        &l5, &l11, &l25, &l46, &l52, &l54, &l70, &l80, &l95, &l97, &l100, &l110, &l112, &t4,
    };
    void** gc_raw_roots[29] = {
        &l0, &l1, &l4, &l6, &l9, &l14, &l15, &l16, &l17, &l18, &l21, &l24, &l27, &l30, &l36, &l43,
        &l44, &l49, &l50, &l51, &l62, &l73, &l81, &l86, &l87, &l90, &l93, &l104, &t2,
    };
    vader_string_t* gc_atom_roots[13] = {
        &l7, &l12, &l31, &l32, &l45, &l53, &l57, &l58, &l71, &l98, &l99, &l111, &t1,
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
        l9 = (void*) vader_buffer_new((size_t) (INT64_C(59) + l8));
        l8 = INT64_C(0);
        l8 = std_core_write_string_at(l9, l8, 1772u);
        l8 = std_core_write_string_at(l9, l8, l7);
        l8 = std_core_write_string_at(l9, l8, 939u);
        l10 = ((int64_t) (int32_t) l3);
        l8 = std_core_write_int(l9, l8, l10);
        l8 = std_core_write_string_at(l9, l8, 421u);
        t1 = std_core_finish_buffer(l9, l8);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
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
            l11 = vader_vm_read_i64(t4, l3, 550u);
            if (!(l11.tag == 1308u)) {
                t0 = ((int64_t) l11.payload.i);
                t5 = vader_vm_debug_std_descriptor(t0);
                vader_struct_vader_vm_HostOk_t* _a2_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a2_obj, 1289u);
                _a2_obj->f_value = vader_box_i64(291u, t5);
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
            l7 = 2511u;
        } else {
            l12 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_c_library;
            l7 = concat_3(916u, l12, 916u);
        }
        l12 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l10 = vader_host_std_core_byte_len(l12);
        l13 = vader_host_std_core_byte_len(l7);
        l10 = (l10 + l13);
        l9 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l10));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l9, l10, 1772u);
        l10 = std_core_write_string_at(l9, l10, l12);
        l10 = std_core_write_string_at(l9, l10, 939u);
        l13 = ((int64_t) (int32_t) l3);
        l10 = std_core_write_int(l9, l10, l13);
        l10 = std_core_write_string_at(l9, l10, 404u);
        l10 = std_core_write_string_at(l9, l10, l7);
        t1 = std_core_finish_buffer(l9, l10);
        vader_struct_vader_vm_Trap_t* _a3_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a3_obj, 1308u);
        _a3_obj->f_message = t1;
        t2 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    l8 = vader_host_vader_vm_ffi_symbol(l8, l7);
    if (l8 == INT64_C(0)) {
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l10 = vader_host_std_core_byte_len(l7);
        l9 = (void*) vader_buffer_new((size_t) (INT64_C(54) + l10));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l9, l10, 1772u);
        l10 = std_core_write_string_at(l9, l10, l7);
        l10 = std_core_write_string_at(l9, l10, 939u);
        l13 = ((int64_t) (int32_t) l3);
        l10 = std_core_write_int(l9, l10, l13);
        l10 = std_core_write_string_at(l9, l10, 424u);
        t1 = std_core_finish_buffer(l9, l10);
        vader_struct_vader_vm_Trap_t* _a4_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a4_obj, 1308u);
        _a4_obj->f_message = t1;
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) (INT32_C(0) & INT32_C(255));
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 8u, 291u);
    l14 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 8u, 291u);
    l15 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(17u, 0u, 1u, 292u);
    l16 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(205u, 0u, 13u, 1290u);
    l17 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(206u, 0u, 13u, 1291u);
    l18 = (void*) _a10_arr;
    l10 = INT64_C(0);
    l13 = ((vader_array_t*) l6)->length;
    while ((l10 < l13)) {
        l19 = vader_chk_add(i64, l2, l10);
        vader_array_t* _a11_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l19)
        l11 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l19];
        if (l11.tag == 1285u) {
            l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l20 = vader_host_std_core_byte_len(l7);
            l21 = (void*) vader_buffer_new((size_t) (INT64_C(138) + l20));
            l22 = INT64_C(0);
            l22 = std_core_write_string_at(l21, l22, 1772u);
            l22 = std_core_write_string_at(l21, l22, l7);
            l22 = std_core_write_string_at(l21, l22, 939u);
            l23 = ((int64_t) (int32_t) l3);
            l22 = std_core_write_int(l21, l22, l23);
            l22 = std_core_write_string_at(l21, l22, 401u);
            l22 = std_core_write_int(l21, l22, l10);
            l22 = std_core_write_string_at(l21, l22, 102u);
            t1 = std_core_finish_buffer(l21, l22);
            vader_struct_vader_vm_Trap_t* _a12_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a12_obj, 1308u);
            _a12_obj->f_message = t1;
            t2 = (void*) _a12_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11.tag == 1305u) {
            l24 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_param_types;
            l25 = vader_vm_mirrored_struct_fields(l4, l24, l10);
            if (l25.tag == 0u) {
                l12 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                l26 = vader_host_std_core_byte_len(l12);
                l27 = (void*) vader_buffer_new((size_t) (INT64_C(112) + l26));
                l28 = INT64_C(0);
                l28 = std_core_write_string_at(l27, l28, 1772u);
                l28 = std_core_write_string_at(l27, l28, l12);
                l28 = std_core_write_string_at(l27, l28, 939u);
                l29 = ((int64_t) (int32_t) l3);
                l28 = std_core_write_int(l27, l28, l29);
                l28 = std_core_write_string_at(l27, l28, 401u);
                l28 = std_core_write_int(l27, l28, l10);
                l28 = std_core_write_string_at(l27, l28, 103u);
                t1 = std_core_finish_buffer(l27, l28);
                vader_struct_vader_vm_Trap_t* _a13_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a13_obj, 1308u);
                _a13_obj->f_message = t1;
                t2 = (void*) _a13_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l25.payload.obj;
            l30 = vader_bytecode_c_struct_layout(t2, l4);
            if (!(((vader_struct_vader_bytecode_CLayout_t*) l30)->f_unknown_field.tag == 0u)) {
                l31 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                l32 = ((vader_struct_vader_bytecode_CLayout_t*) l30)->f_unknown_field.payload.s;
                l33 = vader_host_std_core_byte_len(l31);
                l34 = vader_host_std_core_byte_len(l32);
                l35 = (l33 + l34);
                l36 = (void*) vader_buffer_new((size_t) (INT64_C(142) + l35));
                l37 = INT64_C(0);
                l37 = std_core_write_string_at(l36, l37, 1772u);
                l37 = std_core_write_string_at(l36, l37, l31);
                l37 = std_core_write_string_at(l36, l37, 939u);
                l38 = ((int64_t) (int32_t) l3);
                l37 = std_core_write_int(l36, l37, l38);
                l37 = std_core_write_string_at(l36, l37, 401u);
                l37 = std_core_write_int(l36, l37, l10);
                l37 = std_core_write_string_at(l36, l37, 126u);
                l37 = std_core_write_string_at(l36, l37, l32);
                l37 = std_core_write_string_at(l36, l37, 1036u);
                t1 = std_core_finish_buffer(l36, l37);
                vader_struct_vader_vm_Trap_t* _a14_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a14_obj, 1308u);
                _a14_obj->f_message = t1;
                t2 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l39 = ((vader_array_t*) l16)->length;
            l40 = INT64_C(4096);
            t0 = ((vader_struct_vader_bytecode_CLayout_t*) l30)->f_size;
            if ((t0 > l40)) {
                l41 = ((vader_struct_vader_bytecode_CLayout_t*) l30)->f_size;
            } else {
                l41 = l40;
            }
            l42 = INT64_C(0);
            while ((l42 < l41)) {
                vader_array_push_u8((vader_array_t*) l16, INT32_C(0));
                l42 = (l42 + INT64_C(1));
            }
            l43 = l11.payload.obj;
            l44 = l25.payload.obj;
            l45 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l46 = vader_vm_serialise_mirror(l16, l39, l43, l44, l4, l3, l45, INT32_C(0));
            if (l46.tag == 1308u) {
                t2 = l46.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = (INT32_C(3) & INT32_C(255));
            l47 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l47);
            l48 = ((vader_array_t*) l14)->length;
            vader_array_push_i64((vader_array_t*) l15, l48);
            vader_array_push_i64((vader_array_t*) l14, l39);
            t3 = vader_bytecode_param_is_c_out(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l10);
            if (t3) {
                l49 = l11.payload.obj;
                l50 = l25.payload.obj;
                vader_struct_vader_vm_LentStruct_t* _a15_obj = (vader_struct_vader_vm_LentStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_LentStruct_t));
                vader_obj_header_init(_a15_obj, 1291u);
                _a15_obj->f_target = l49;
                _a15_obj->f_at = l39;
                _a15_obj->f_fields = l50;
                l51 = (void*) _a15_obj;
                vader_array_push((vader_array_t*) l18, vader_ref_box(l51));
            }
            l10 = (l10 + INT64_C(1));
            continue;
        }
        t3 = vader_bytecode_param_is_by_address(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l10);
        if (t3) {
            l52 = l11;
            l53 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l54 = vader_vm_extern_word(l52, l3, l53, l10);
            if (l54.tag == 1308u) {
                t2 = l54.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t4 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l10, 292u);
            t6 = vader_bytecode_size_of_val_type(((uint8_t) t4.payload.i));
            l55 = ((int64_t) (int32_t) t6);
            if (l55 == INT64_C(0)) {
                l56 = true;
            } else {
                l56 = (l55 > INT64_C(8));
            }
            if (l56) {
                l57 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                t4 = vader_array_read_u8(_a17_slotarr, _a17_slotarr->offset + (size_t) l10, 292u);
                l58 = vader_bytecode_val_type_name(((uint8_t) t4.payload.i));
                l59 = vader_host_std_core_byte_len(l57);
                l60 = vader_host_std_core_byte_len(l58);
                l61 = (l59 + l60);
                l62 = (void*) vader_buffer_new((size_t) (INT64_C(81) + l61));
                l63 = INT64_C(0);
                l63 = std_core_write_string_at(l62, l63, 1772u);
                l63 = std_core_write_string_at(l62, l63, l57);
                l63 = std_core_write_string_at(l62, l63, 939u);
                l64 = ((int64_t) (int32_t) l3);
                l63 = std_core_write_int(l62, l63, l64);
                l63 = std_core_write_string_at(l62, l63, 399u);
                l63 = std_core_write_string_at(l62, l63, l58);
                l63 = std_core_write_string_at(l62, l63, 145u);
                t1 = std_core_finish_buffer(l62, l63);
                vader_struct_vader_vm_Trap_t* _a18_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a18_obj, 1308u);
                _a18_obj->f_message = t1;
                t2 = (void*) _a18_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = (INT32_C(3) & INT32_C(255));
            l65 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l65);
            l66 = ((vader_array_t*) l14)->length;
            vader_array_push_i64((vader_array_t*) l15, l66);
            l67 = ((vader_array_t*) l16)->length;
            vader_array_push_i64((vader_array_t*) l14, l67);
            l68 = ((int64_t) l54.payload.i);
            vader_vm_push_little_endian(l16, l68, l55);
        } else if (l11.tag == 1280u) {
            t2 = l11.payload.obj;
            l69 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_type_id;
            l70 = vader_vm_lent_element_val_type(l4, l69);
            if (l70.tag == 0u) {
                l71 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                l72 = vader_host_std_core_byte_len(l71);
                l73 = (void*) vader_buffer_new((size_t) (INT64_C(153) + l72));
                l74 = INT64_C(0);
                l74 = std_core_write_string_at(l73, l74, 1772u);
                l74 = std_core_write_string_at(l73, l74, l71);
                l74 = std_core_write_string_at(l73, l74, 939u);
                l75 = ((int64_t) (int32_t) l3);
                l74 = std_core_write_int(l73, l74, l75);
                l74 = std_core_write_string_at(l73, l74, 401u);
                l74 = std_core_write_int(l73, l74, l10);
                l74 = std_core_write_string_at(l73, l74, 105u);
                t1 = std_core_finish_buffer(l73, l74);
                vader_struct_vader_vm_Trap_t* _a19_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a19_obj, 1308u);
                _a19_obj->f_message = t1;
                t2 = (void*) _a19_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = ((uint8_t) l70.payload.i);
            t6 = vader_bytecode_size_of_val_type(t7);
            l76 = ((int64_t) (int32_t) t6);
            t6 = (INT32_C(3) & INT32_C(255));
            l77 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l77);
            l78 = ((vader_array_t*) l14)->length;
            vader_array_push_i64((vader_array_t*) l15, l78);
            l79 = ((vader_array_t*) l16)->length;
            vader_array_push_i64((vader_array_t*) l14, l79);
            t2 = l11.payload.obj;
            l80 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_raw;
            if (l80.tag == 0u) {
                l87 = l11.payload.obj;
                l88 = ((vader_array_t*) l16)->length;
                l89 = ((uint8_t) l70.payload.i);
                vader_struct_vader_vm_LentArray_t* _a20_obj = (vader_struct_vader_vm_LentArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_LentArray_t));
                vader_obj_header_init(_a20_obj, 1290u);
                _a20_obj->f_target = l87;
                _a20_obj->f_at = l88;
                _a20_obj->f_element = l89;
                l90 = (void*) _a20_obj;
                vader_array_push((vader_array_t*) l17, vader_ref_box(l90));
                l91 = INT64_C(0);
                t2 = l11.payload.obj;
                l92 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
                while ((l91 < l92)) {
                    t2 = l11.payload.obj;
                    l93 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
                    t2 = l11.payload.obj;
                    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                    l94 = vader_chk_add(i64, t0, l91);
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l93);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l94)
                    l95 = vader_array_box_slots(_a21_slotarr->buf)[_a21_slotarr->offset + (size_t) l94];
                    if (l95.tag == 291u) {
                        l96 = ((int64_t) l95.payload.i);
                    } else if (l95.tag == 290u) {
                        t6 = ((int32_t) l95.payload.i);
                        l96 = ((int64_t) (int32_t) t6);
                    } else {
                        l97 = l95;
                        l98 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
                        l99 = concat_3(1772u, l98, 962u);
                        l100 = vader_vm_read_i64(l97, l3, l99);
                        if (l100.tag == 1308u) {
                            t2 = l100.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l96 = ((int64_t) l100.payload.i);
                    }
                    vader_vm_push_little_endian(l16, l96, l76);
                    l91 = (l91 + INT64_C(1));
                }
            } else {
                t1 = l80.payload.s;
                l81 = vader_host_std_core_bytes(t1);
                t2 = l11.payload.obj;
                l82 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                t2 = l11.payload.obj;
                l83 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                t2 = l11.payload.obj;
                l84 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
                l85 = vader_chk_add(i64, l83, l84);
                vader_array_t* _a22_arr = vader_array_slice((vader_array_t*) l81, (int64_t) l82, (int64_t) l85);
                l86 = (void*) _a22_arr;
                vader_array_push_all((vader_array_t*) l16, (vader_array_t*) l86);
            }
        } else if (l11.tag == 287u) {
            t6 = (INT32_C(3) & INT32_C(255));
            l101 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l101);
            l102 = ((vader_array_t*) l14)->length;
            vader_array_push_i64((vader_array_t*) l15, l102);
            l103 = ((vader_array_t*) l16)->length;
            vader_array_push_i64((vader_array_t*) l14, l103);
            t1 = l11.payload.s;
            l104 = vader_host_std_core_bytes(t1);
            vader_array_push_all((vader_array_t*) l16, (vader_array_t*) l104);
            vader_array_push_u8((vader_array_t*) l16, INT32_C(0));
        } else if ((l11.tag == 296u || l11.tag == 297u)) {
            t6 = (INT32_C(2) & INT32_C(255));
            l105 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l105);
            t8 = ((double) l11.payload.f);
            l106 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
            vader_array_push_i64((vader_array_t*) l14, l106);
        } else if (l11.tag == 285u) {
            t6 = (INT32_C(1) & INT32_C(255));
            l107 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l107);
            t3 = l11.payload.b;
            if (t3) {
                l108 = INT64_C(1);
            } else {
                l108 = INT64_C(0);
            }
            vader_array_push_i64((vader_array_t*) l14, l108);
        } else if (l11.tag == 1292u) {
            t6 = (INT32_C(1) & INT32_C(255));
            l109 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l109);
            vader_array_push_i64((vader_array_t*) l14, INT64_C(0));
        } else {
            l110 = l11;
            l111 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
            l112 = vader_vm_extern_word(l110, l3, l111, l10);
            if (l112.tag == 1308u) {
                t2 = l112.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = (INT32_C(1) & INT32_C(255));
            l113 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l113);
            l114 = ((int64_t) l112.payload.i);
            vader_array_push_i64((vader_array_t*) l14, l114);
        }
        l10 = (l10 + INT64_C(1));
    }
    l47 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    if (l47 == INT32_C(8)) {
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
        l10 = vader_host_std_core_byte_len(l7);
        l6 = (void*) vader_buffer_new((size_t) (INT64_C(67) + l10));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l6, l10, 1772u);
        l10 = std_core_write_string_at(l6, l10, l7);
        l10 = std_core_write_string_at(l6, l10, 939u);
        l13 = ((int64_t) (int32_t) l3);
        l10 = std_core_write_int(l6, l10, l13);
        l10 = std_core_write_string_at(l6, l10, 400u);
        t1 = std_core_finish_buffer(l6, l10);
        vader_struct_vader_vm_Trap_t* _a23_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a23_obj, 1308u);
        _a23_obj->f_message = t1;
        t2 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l69 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    t3 = vader_vm_ffi_result_is_opt(l4, l69, (uint8_t) 12);
    if (t3) {
        t6 = (INT32_C(5) & INT32_C(255));
        l65 = (uint8_t) (int32_t) t6;
    } else {
        t6 = vader_vm_ffi_result_class(l47);
        t9 = (t6 & INT32_C(255));
        l65 = (uint8_t) (int32_t) t9;
    }
    vader_array_t* _a24_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, INT32_C(0))
    ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) (int32_t) (uint8_t) l65;
    t0 = ((vader_array_t*) l14)->length;
    l10 = vader_chk_mul(i64, t0, INT64_C(8));
    l6 = l15;
    l13 = ((vader_array_t*) l6)->length;
    l19 = INT64_C(0);
    while ((l19 < l13)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        l20 = ((int64_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l19];
        vader_array_t* _a26_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l20)
        t0 = ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l20];
        l22 = vader_chk_add(i64, t0, l10);
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l20)
        ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l20] = (int64_t) l22;
        l19 = (l19 + INT64_C(1));
    }
    vader_array_t* _a27_arr = vader_array_new(17u, 0u, 1u, 292u);
    l6 = (void*) _a27_arr;
    l13 = ((vader_array_t*) l14)->length;
    l19 = INT64_C(0);
    while ((l19 < l13)) {
        vader_array_t* _a28_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        l20 = ((int64_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l19];
        vader_vm_push_little_endian(l6, l20, INT64_C(8));
        l19 = (l19 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l16);
    t0 = ((vader_array_t*) l6)->length;
    if (t0 == INT64_C(0)) {
        t7 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
        if (t7 != INT32_C(14)) {
            vader_vm_push_little_endian(l6, INT64_C(0), INT64_C(8));
        }
    }
    t6 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_c_variadic_fixed;
    l13 = ((int64_t) (int32_t) t6);
    l7 = vader_host_vader_vm_ffi_call(l8, l9, l6, l13);
    l14 = l17;
    l8 = ((vader_array_t*) l14)->length;
    l13 = INT64_C(0);
    while ((l13 < l8)) {
        vader_array_t* _a29_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        l15 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l13);
        t6 = vader_bytecode_size_of_val_type(((vader_struct_vader_vm_LentArray_t*) l15)->f_element);
        l19 = ((int64_t) (int32_t) t6);
        t3 = vader_bytecode_is_unsigned_val(((vader_struct_vader_vm_LentArray_t*) l15)->f_element);
        l56 = !(t3);
        l20 = INT64_C(0);
        l22 = ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l15)->f_target)->f_length;
        while ((l20 < l22)) {
            t0 = ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l15)->f_target)->f_offset;
            l23 = vader_chk_add(i64, t0, l20);
            l26 = ((vader_struct_vader_vm_LentArray_t*) l15)->f_at;
            l28 = vader_chk_add(i64, l10, l26);
            l29 = vader_chk_mul(i64, l20, l19);
            l33 = vader_chk_add(i64, l28, l29);
            l34 = vader_vm_read_little_endian(l6, l33, l19, l56);
            l16 = ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l15)->f_target)->f_elements;
            vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) ((vader_struct_vader_vm_LentArray_t*) l15)->f_target)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l23)
            t4 = vader_array_box_slots(_a30_slotarr->buf)[_a30_slotarr->offset + (size_t) l23];
            l11 = vader_vm_retyped_int(t4, l34);
            vader_array_t* _a31_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l23)
            vader_array_box_slots(_a31_slotarr->buf)[_a31_slotarr->offset + (size_t) l23] = l11;
            VADER_WRITE_BARRIER(_a31_slotarr->buf);
            l20 = (l20 + INT64_C(1));
        }
        l13 = (l13 + INT64_C(1));
    }
    l14 = l18;
    l8 = ((vader_array_t*) l14)->length;
    l13 = INT64_C(0);
    while ((l13 < l8)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        l15 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l13);
        l19 = ((vader_struct_vader_vm_LentStruct_t*) l15)->f_at;
        l20 = vader_chk_add(i64, l10, l19);
        l16 = ((vader_struct_vader_vm_LentStruct_t*) l15)->f_target;
        l17 = ((vader_struct_vader_vm_LentStruct_t*) l15)->f_fields;
        vader_vm_read_back_mirror(l6, l20, l16, l17, l4, INT32_C(0));
        l13 = (l13 + INT64_C(1));
    }
    if (l47 == INT32_C(14)) {
        t4 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a33_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a33_obj, 1289u);
        _a33_obj->f_value = t4;
        t2 = (void*) _a33_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l47 == INT32_C(9)) {
        t0 = vader_vm_read_little_endian(l6, INT64_C(0), INT64_C(8), false);
        vader_struct_vader_vm_HostOk_t* _a34_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a34_obj, 1289u);
        _a34_obj->f_value = vader_box_f64(297u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t0) }).__vd));
        t2 = (void*) _a34_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a35_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a35_slotarr, INT32_C(0))
    t4 = vader_array_read_u8(_a35_slotarr, _a35_slotarr->offset + (size_t) INT32_C(0), 292u);
    l65 = ((uint8_t) t4.payload.i);
    t6 = (INT32_C(5) & INT32_C(255));
    l77 = (uint8_t) (int32_t) t6;
    if (l65 == l77) {
        t0 = vader_vm_read_little_endian(l6, INT64_C(0), INT64_C(8), false);
        if (!(t0 == INT64_C(0))) {
            vader_struct_vader_vm_HostOk_t* _a36_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a36_obj, 1289u);
            _a36_obj->f_value = vader_box_string(287u, l7);
            t2 = (void*) _a36_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_vm_NullVal_t* _a37_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
        vader_obj_header_init(_a37_obj, 1292u);
        t2 = (void*) _a37_obj;
        vader_struct_vader_vm_HostOk_t* _a38_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a38_obj, 1289u);
        _a38_obj->f_value = vader_ref_box(t2);
        t2 = (void*) _a38_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l47 == INT32_C(12)) {
        vader_struct_vader_vm_HostOk_t* _a39_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a39_obj, 1289u);
        _a39_obj->f_value = vader_box_string(287u, l7);
        t2 = (void*) _a39_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l69 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    t3 = vader_vm_ffi_result_is_opt(l4, l69, (uint8_t) 15);
    if (t3) {
        t0 = vader_vm_read_little_endian(l6, INT64_C(0), INT64_C(8), false);
        if (t0 == INT64_C(0)) {
            vader_struct_vader_vm_NullVal_t* _a40_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
            vader_obj_header_init(_a40_obj, 1292u);
            t2 = (void*) _a40_obj;
            vader_struct_vader_vm_HostOk_t* _a41_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a41_obj, 1289u);
            _a41_obj->f_value = vader_ref_box(t2);
            t2 = (void*) _a41_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l8 = vader_vm_read_little_endian(l6, INT64_C(0), INT64_C(8), true);
    t4 = vader_vm_extern_result(l47, l8);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_dispatch_import(void* l0, void* l1, int64_t l2, void* l3, void* l4, int32_t l5, int32_t l6, int32_t l7, int32_t l8, void* l9, bool l10, vader_box_t l11, uint8_t l12) {
    bool l13;
    vader_box_t l14 = vader_box_null(), l17 = vader_box_null(), l22 = vader_box_null(), l24 = vader_box_null();
    void* l15 = NULL;
    void* l23 = NULL;
    int64_t l16, l20, l21, l26;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    uint8_t l25;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    uint64_t t4;
    int64_t t5;
    int32_t t6;
    uint8_t t7;
    vader_box_t* gc_roots[6] = { &l11, &l14, &l17, &l22, &l24, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l9, &l15, &l23, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l18, &l19, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    if (t0 == 2739u) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a0_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a0_obj, 1289u);
        _a0_obj->f_value = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    if (t0 == 2741u) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a1_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a1_obj, 1289u);
        _a1_obj->f_value = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    if (t0 == 2740u) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a2_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a2_obj, 1289u);
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
        l13 = true;
    } else {
        l13 = l12 == INT32_C(2);
    }
    if (l13) {
        l13 = true;
    } else {
        l13 = l12 == INT32_C(3);
    }
    if (l13) {
        l13 = true;
    } else {
        l13 = l12 == INT32_C(4);
    }
    if (!(l13)) {
        if (l12 == INT32_C(6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
            t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_array(t1, l5, 1530u);
            if (l14.tag == 1308u) {
                t2 = l14.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l15 = l14.payload.obj;
            t2 = l14.payload.obj;
            l16 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
            l14 = vader_vm_array_bytes(l15, l16, l5, 1529u);
            if (!(l14.tag == 1308u)) {
                t2 = l14.payload.obj;
                t0 = vader_host_std_core_bytes_to_string(t2);
                vader_struct_vader_vm_HostOk_t* _a4_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a4_obj, 1289u);
                _a4_obj->f_value = vader_box_string(287u, t0);
                t2 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(5)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
            t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_string(t1, l5, 1526u);
            if (!(l14.tag == 1308u)) {
                t0 = l14.payload.s;
                t2 = vader_vm_bytes_to_value(t0, l7);
                vader_struct_vader_vm_HostOk_t* _a6_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a6_obj, 1289u);
                _a6_obj->f_value = vader_ref_box(t2);
                t2 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(7)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l2)
            t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_string(t1, l5, 1894u);
            if (!(l14.tag == 1308u)) {
                t0 = l14.payload.s;
                t4 = std_core_string_Hash_hash_vt(t0);
                vader_struct_vader_vm_HostOk_t* _a8_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a8_obj, 1289u);
                _a8_obj->f_value = vader_box_i64(291u, ((int64_t) (uint64_t) t4));
                t2 = (void*) _a8_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(8)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l2)
            t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_string(t1, l5, 1719u);
            if (l14.tag == 1308u) {
                t2 = l14.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l16)
            t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l16];
            l17 = vader_vm_read_string(t1, l5, 1718u);
            if (!(l17.tag == 1308u)) {
                l18 = l14.payload.s;
                l19 = l17.payload.s;
                vader_struct_vader_vm_HostOk_t* _a11_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a11_obj, 1289u);
                _a11_obj->f_value = vader_box_bool(285u, l18 == l19);
                t2 = (void*) _a11_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l17.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(9)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l2)
            t1 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_i64(t1, l5, 1719u);
            if (l14.tag == 1308u) {
                t2 = l14.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a13_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l16)
            t1 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l16];
            l17 = vader_vm_read_i64(t1, l5, 1718u);
            if (!(l17.tag == 1308u)) {
                l16 = ((int64_t) l14.payload.i);
                l20 = ((int64_t) l17.payload.i);
                vader_struct_vader_vm_HostOk_t* _a14_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a14_obj, 1289u);
                _a14_obj->f_value = vader_box_bool(285u, l16 == l20);
                t2 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l17.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(10)) {
            t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
            t3 = vader_bytecode_is_unsigned_display(t0);
            if (!(t3)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l2)
                t1 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l2];
                t0 = vader_vm_display_value(t1);
                vader_struct_vader_vm_HostOk_t* _a16_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a16_obj, 1289u);
                _a16_obj->f_value = vader_box_string(287u, t0);
                t2 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a17_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l2)
            l14 = vader_array_box_slots(_a17_slotarr->buf)[_a17_slotarr->offset + (size_t) l2];
            if (l14.tag == 291u) {
                t5 = ((int64_t) l14.payload.i);
                t0 = std_core_u64_Display_to_string((uint64_t) (int64_t) t5);
                vader_struct_vader_vm_HostOk_t* _a18_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a18_obj, 1289u);
                _a18_obj->f_value = vader_box_string(287u, t0);
                t2 = (void*) _a18_obj;
                l17 = vader_ref_box(t2);
                { vader_box_t __vret = l17; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l14.tag == 290u) {
                t6 = ((int32_t) l14.payload.i);
                t0 = std_core_u64_Display_to_string((uint64_t) (int64_t) ((int64_t) (uint32_t) t6));
                vader_struct_vader_vm_HostOk_t* _a19_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a19_obj, 1289u);
                _a19_obj->f_value = vader_box_string(287u, t0);
                t2 = (void*) _a19_obj;
                l17 = vader_ref_box(t2);
            } else {
                l18 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
                l19 = vader_vm_describe_value_tag(l14);
                l16 = vader_host_std_core_byte_len(l18);
                l20 = vader_host_std_core_byte_len(l19);
                l16 = (l16 + l20);
                l15 = (void*) vader_buffer_new((size_t) (INT64_C(57) + l16));
                l16 = INT64_C(0);
                l16 = std_core_write_string_at(l15, l16, l18);
                l16 = std_core_write_string_at(l15, l16, 66u);
                l20 = ((int64_t) (int32_t) l5);
                l16 = std_core_write_int(l15, l16, l20);
                l16 = std_core_write_string_at(l15, l16, 414u);
                l16 = std_core_write_string_at(l15, l16, l19);
                t0 = std_core_finish_buffer(l15, l16);
                vader_struct_vader_vm_Trap_t* _a20_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a20_obj, 1308u);
                _a20_obj->f_message = t0;
                t2 = (void*) _a20_obj;
                l17 = vader_ref_box(t2);
            }
            { vader_box_t __vret = l17; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(11)) {
            vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, INT32_C(0))
            t5 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) INT32_C(0)];
            l16 = vader_chk_add(i64, t5, INT64_C(1));
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, INT32_C(0))
            ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) l16;
            vader_struct_vader_vm_NullVal_t* _a22_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
            vader_obj_header_init(_a22_obj, 1292u);
            t2 = (void*) _a22_obj;
            vader_struct_vader_vm_HostOk_t* _a23_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a23_obj, 1289u);
            _a23_obj->f_value = vader_ref_box(t2);
            t2 = (void*) _a23_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(12)) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, INT32_C(0))
            t5 = ((int64_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) INT32_C(0)];
            vader_struct_vader_vm_HostOk_t* _a25_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a25_obj, 1289u);
            _a25_obj->f_value = vader_box_i32(290u, ((int32_t) (int64_t) t5));
            t2 = (void*) _a25_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(13)) {
            vader_struct_vader_vm_HostOk_t* _a26_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a26_obj, 1289u);
            _a26_obj->f_value = vader_box_i32(290u, INT32_C(0));
            t2 = (void*) _a26_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(14)) {
            vader_struct_vader_vm_HostOk_t* _a27_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a27_obj, 1289u);
            _a27_obj->f_value = vader_box_i32(290u, INT32_C(0));
            t2 = (void*) _a27_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(15)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, INT32_C(0))
            t5 = ((int64_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) INT32_C(0)];
            vader_struct_vader_vm_HostOk_t* _a29_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a29_obj, 1289u);
            _a29_obj->f_value = vader_box_i64(291u, t5);
            t2 = (void*) _a29_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(16)) {
            vader_array_t* _a30_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l2)
            t1 = vader_array_box_slots(_a30_slotarr->buf)[_a30_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_i64(t1, l5, 2345u);
            if (!(l14.tag == 1308u)) {
                l16 = ((int64_t) l14.payload.i);
                vader_array_push_i64((vader_array_t*) l4, l16);
                vader_struct_vader_vm_NullVal_t* _a31_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
                vader_obj_header_init(_a31_obj, 1292u);
                t2 = (void*) _a31_obj;
                vader_struct_vader_vm_HostOk_t* _a32_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a32_obj, 1289u);
                _a32_obj->f_value = vader_ref_box(t2);
                t2 = (void*) _a32_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(17)) {
            vader_vm_drop_due_timers(l4);
            t5 = ((vader_array_t*) l4)->length;
            if ((t5 <= INT64_C(1))) {
                vader_struct_vader_vm_HostOk_t* _a33_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a33_obj, 1289u);
                _a33_obj->f_value = vader_box_i32(290u, INT32_C(1));
                t2 = (void*) _a33_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            l16 = ((int64_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) INT32_C(1)];
            l20 = INT64_C(2);
            l21 = ((vader_array_t*) l4)->length;
            while ((l20 < l21)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                t5 = ((int64_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l20];
                if ((t5 < l16)) {
                    vader_array_t* _a36_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                    l16 = ((int64_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l20];
                }
                l20 = (l20 + INT64_C(1));
            }
            vader_array_t* _a37_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            ((int64_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) l16;
            vader_vm_drop_due_timers(l4);
            vader_struct_vader_vm_HostOk_t* _a38_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a38_obj, 1289u);
            _a38_obj->f_value = vader_box_i32(290u, INT32_C(0));
            t2 = (void*) _a38_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(21)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l2)
            t1 = vader_array_box_slots(_a39_slotarr->buf)[_a39_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_string(t1, l5, 1801u);
            if (!(l14.tag == 1308u)) {
                t0 = l14.payload.s;
                t5 = vader_host_vader_vm_ffi_open(t0);
                vader_struct_vader_vm_HostOk_t* _a40_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a40_obj, 1289u);
                _a40_obj->f_value = vader_box_i64(291u, t5);
                t2 = (void*) _a40_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(22)) {
            vader_array_t* _a41_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l2)
            t1 = vader_array_box_slots(_a41_slotarr->buf)[_a41_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_i64(t1, l5, 1802u);
            if (l14.tag == 1308u) {
                t2 = l14.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a42_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l16)
            t1 = vader_array_box_slots(_a42_slotarr->buf)[_a42_slotarr->offset + (size_t) l16];
            l17 = vader_vm_read_string(t1, l5, 1803u);
            if (!(l17.tag == 1308u)) {
                l16 = ((int64_t) l14.payload.i);
                l18 = l17.payload.s;
                t5 = vader_host_vader_vm_ffi_symbol(l16, l18);
                vader_struct_vader_vm_HostOk_t* _a43_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
                vader_obj_header_init(_a43_obj, 1289u);
                _a43_obj->f_value = vader_box_i64(291u, t5);
                t2 = (void*) _a43_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l17.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(23)) {
            vader_array_t* _a44_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l2)
            t1 = vader_array_box_slots(_a44_slotarr->buf)[_a44_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_i64(t1, l5, 1798u);
            if (l14.tag == 1308u) {
                t2 = l14.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a45_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l16)
            t1 = vader_array_box_slots(_a45_slotarr->buf)[_a45_slotarr->offset + (size_t) l16];
            l17 = vader_vm_read_array(t1, l5, 1796u);
            if (l17.tag == 1308u) {
                t2 = l17.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_chk_add(i64, l2, INT64_C(2));
            vader_array_t* _a46_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l16)
            t1 = vader_array_box_slots(_a46_slotarr->buf)[_a46_slotarr->offset + (size_t) l16];
            l22 = vader_vm_read_array(t1, l5, 1799u);
            if (l22.tag == 1308u) {
                t2 = l22.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l15 = l17.payload.obj;
            t2 = l17.payload.obj;
            l16 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
            l17 = vader_vm_array_bytes(l15, l16, l5, 1797u);
            if (l17.tag == 1308u) {
                t2 = l17.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l22.payload.obj;
            vader_vm_own_bytes(t2);
            vader_array_t* _a47_arr = vader_array_new(17u, 0u, 1u, 292u);
            l15 = (void*) _a47_arr;
            l16 = INT64_C(0);
            t2 = l22.payload.obj;
            l20 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
            while ((l16 < l20)) {
                t2 = l22.payload.obj;
                l23 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
                t2 = l22.payload.obj;
                t5 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                l21 = vader_chk_add(i64, t5, l16);
                vader_array_t* _a48_slotarr = ((vader_array_t*) l23);
                VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l21)
                t1 = vader_array_box_slots(_a48_slotarr->buf)[_a48_slotarr->offset + (size_t) l21];
                l24 = vader_vm_read_i64(t1, l5, 1800u);
                if (l24.tag == 1308u) {
                    t2 = l24.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t5 = ((int64_t) l24.payload.i);
                t6 = (((int32_t) (int64_t) t5) & INT32_C(255));
                l25 = (uint8_t) (int32_t) t6;
                vader_array_push_u8((vader_array_t*) l15, (int32_t) (uint8_t) l25);
                l16 = (l16 + INT64_C(1));
            }
            l16 = ((int64_t) l14.payload.i);
            l23 = l17.payload.obj;
            vader_host_vader_vm_ffi_call(l16, l23, l15, INT64_C(-1));
            l16 = INT64_C(0);
            t2 = l22.payload.obj;
            l20 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_length;
            while ((l16 < l20)) {
                t2 = l22.payload.obj;
                t5 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_offset;
                l21 = vader_chk_add(i64, t5, l16);
                t2 = l22.payload.obj;
                l23 = ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements;
                t2 = l22.payload.obj;
                vader_array_t* _a49_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) t2)->f_elements);
                VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l21)
                l14 = vader_array_box_slots(_a49_slotarr->buf)[_a49_slotarr->offset + (size_t) l21];
                vader_array_t* _a50_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l16)
                t1 = vader_array_read_u8(_a50_slotarr, _a50_slotarr->offset + (size_t) l16, 292u);
                t7 = ((uint8_t) t1.payload.i);
                l26 = ((int64_t) (uint8_t) t7);
                l17 = vader_vm_retyped_int(l14, l26);
                vader_array_t* _a51_slotarr = ((vader_array_t*) l23);
                VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l21)
                vader_array_box_slots(_a51_slotarr->buf)[_a51_slotarr->offset + (size_t) l21] = l17;
                VADER_WRITE_BARRIER(_a51_slotarr->buf);
                l16 = (l16 + INT64_C(1));
            }
            t1 = vader_vm_zero_value();
            vader_struct_vader_vm_HostOk_t* _a52_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a52_obj, 1289u);
            _a52_obj->f_value = t1;
            t2 = (void*) _a52_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(19)) {
            t7 = vader_host_std_target_current_os();
            vader_struct_vader_vm_HostOk_t* _a53_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a53_obj, 1289u);
            _a53_obj->f_value = vader_box_i32(290u, ((int32_t) (uint8_t) t7));
            t2 = (void*) _a53_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(20)) {
            t7 = vader_host_std_target_current_arch();
            vader_struct_vader_vm_HostOk_t* _a54_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
            vader_obj_header_init(_a54_obj, 1289u);
            _a54_obj->f_value = vader_box_i32(290u, ((int32_t) (uint8_t) t7));
            t2 = (void*) _a54_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l12 == INT32_C(18)) {
            vader_array_t* _a55_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l2)
            t1 = vader_array_box_slots(_a55_slotarr->buf)[_a55_slotarr->offset + (size_t) l2];
            l14 = vader_vm_read_string(t1, l5, 2262u);
            if (!(l14.tag == 1308u)) {
                l18 = l14.payload.s;
                t0 = concat_2(2264u, l18);
                vader_struct_vader_vm_Trap_t* _a56_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a56_obj, 1308u);
                _a56_obj->f_message = t0;
                t2 = (void*) _a56_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l12 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    l18 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l16 = vader_host_std_core_byte_len(l18);
    l15 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l16));
    l16 = INT64_C(0);
    l16 = std_core_write_string_at(l15, l16, 2603u);
    l16 = std_core_write_string_at(l15, l16, l18);
    l16 = std_core_write_string_at(l15, l16, 240u);
    l20 = ((int64_t) (int32_t) l5);
    l16 = std_core_write_int(l15, l16, l20);
    t0 = std_core_finish_buffer(l15, l16);
    vader_struct_vader_vm_Trap_t* _a57_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a57_obj, 1308u);
    _a57_obj->f_message = t0;
    t2 = (void*) _a57_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_display_tags(uint8_t l0) {
    void* l1 = NULL;
    bool l2;
    int64_t l3, l4;
    uint8_t l5, l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 2226u; }
    }
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 531u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = INT64_C(0);
    t0 = (void*) &vader_data_50;
    l4 = ((vader_array_t*) t0)->length;
    while ((l3 < l4)) {
        t1 = (((int32_t) (int64_t) l3) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        t1 = ((INT32_C(1) << (l5 & 31)) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t1;
        if ((l0 & l6) != INT32_C(0)) {
            if (!(l2)) {
                std_string_builder_append(l1, 2844u);
            }
            t0 = (void*) &vader_data_50;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
            l7 = t2.payload.s;
            std_string_builder_append(l1, l7);
            l2 = false;
        }
        l3 = (l3 + INT64_C(1));
    }
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 290u) {
        t0 = ((int32_t) l0.payload.i);
        l1 = vader_vm_I32Val_std_core_Display_to_string(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 291u) {
        t1 = ((int64_t) l0.payload.i);
        l1 = vader_vm_I64Val_std_core_Display_to_string(t1);
    } else if ((l0.tag == 296u || l0.tag == 297u)) {
        t2 = ((double) l0.payload.f);
        l1 = vader_vm_F64Val_std_core_Display_to_string(t2);
    } else if (l0.tag == 287u) {
        t3 = l0.payload.s;
        l1 = vader_vm_StringVal_std_core_Display_to_string(t3);
    } else if (l0.tag == 1305u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_StructVal_std_core_Display_to_string(t4);
    } else if (l0.tag == 1280u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_ArrayVal_std_core_Display_to_string(t4);
    } else if (l0.tag == 1285u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_FnVal_std_core_Display_to_string(t4);
    } else if (l0.tag == 1292u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_NullVal_std_core_Display_to_string(t4);
    } else if (l0.tag == 285u) {
        t5 = l0.payload.b;
        l1 = vader_vm_BoolVal_std_core_Display_to_string(t5);
    } else if (l0.tag == 286u) {
        t6 = ((uint32_t) l0.payload.i);
        l1 = vader_vm_CharVal_std_core_Display_to_string(t6);
    } else if (l0.tag == 1284u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_ErrorVal_std_core_Display_to_string(t4);
    } else if (l0.tag == 1309u) {
        t4 = l0.payload.obj;
        l1 = vader_vm_TypeVal_std_core_Display_to_string(t4);
    } else {
        if (!(l0.tag == 1293u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t4 = l0.payload.obj;
        l1 = vader_vm_ObjVal_std_core_Display_to_string(t4);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm_display_verify_error(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    int64_t l3, l4;
    void* l5 = NULL;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_vm_VerifyError_t*) l0)->f_message;
    l2 = ((vader_struct_vader_vm_VerifyError_t*) l0)->f_function;
    l3 = vader_host_std_core_byte_len(l1);
    l4 = vader_host_std_core_byte_len(l2);
    l3 = (l3 + l4);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(33) + l3));
    l3 = INT64_C(0);
    l3 = std_core_write_string_at(l5, l3, l1);
    l3 = std_core_write_string_at(l5, l3, 66u);
    t0 = ((vader_struct_vader_vm_VerifyError_t*) l0)->f_pc;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l5, l3, l4);
    l3 = std_core_write_string_at(l5, l3, 99u);
    l3 = std_core_write_string_at(l5, l3, l2);
    l3 = std_core_write_string_at(l5, l3, 234u);
    t1 = std_core_finish_buffer(l5, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_do_memory_copy(void* l0) {
    int64_t l1, l10, l11, l12, l13;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l3;
    bool l8;
    void* l9 = NULL;
    void* l14 = NULL;
    uint8_t l15;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l2, &l4, &l5, &l6, &l7, &t4 };
    void** gc_raw_roots[4] = { &l0, &l9, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_i32(l2, l3, 2135u);
    if (l2.tag == 1308u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 2139u);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l5 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_obj(l5, l3, 2138u);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(4));
    l6 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = vader_vm_read_i32(l6, l3, 2134u);
    if (l6.tag == 1308u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    l7 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l7 = vader_vm_read_obj(l7, l3, 2133u);
    if (l7.tag == 1308u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    if ((t2 < INT32_C(0))) {
        l8 = true;
    } else {
        t2 = ((int32_t) l4.payload.i);
        l8 = (t2 < INT32_C(0));
    }
    if (l8) {
        l8 = true;
    } else {
        t2 = ((int32_t) l6.payload.i);
        l8 = (t2 < INT32_C(0));
    }
    if (l8) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(61));
        l1 = INT64_C(0);
        l1 = std_core_write_string_at(l9, l1, 2136u);
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l10 = ((int64_t) (int32_t) t2);
        l1 = std_core_write_int(l9, l1, l10);
        t3 = std_core_finish_buffer(l9, l1);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    l1 = ((int64_t) (int32_t) t2);
    t2 = ((int32_t) l4.payload.i);
    l10 = ((int64_t) (int32_t) t2);
    t2 = ((int32_t) l6.payload.i);
    l11 = ((int64_t) (int32_t) t2);
    l12 = vader_chk_add(i64, l10, l1);
    t1 = l5.payload.obj;
    l13 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
    if ((l12 > l13)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(125));
        l12 = INT64_C(0);
        l12 = std_core_write_string_at(l9, l12, 2137u);
        l12 = std_core_write_int(l9, l12, l10);
        l12 = std_core_write_string_at(l9, l12, 305u);
        l13 = vader_chk_add(i64, l10, l1);
        l12 = std_core_write_int(l9, l12, l13);
        l12 = std_core_write_string_at(l9, l12, 277u);
        t1 = l5.payload.obj;
        l13 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
        l12 = std_core_write_int(l9, l12, l13);
        l12 = std_core_write_string_at(l9, l12, 66u);
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core_write_int(l9, l12, l13);
        t3 = std_core_finish_buffer(l9, l12);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1308u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = vader_chk_add(i64, l11, l1);
    t1 = l7.payload.obj;
    l13 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
    if ((l12 > l13)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(123));
        l12 = INT64_C(0);
        l12 = std_core_write_string_at(l9, l12, 2132u);
        l12 = std_core_write_int(l9, l12, l11);
        l12 = std_core_write_string_at(l9, l12, 305u);
        l13 = vader_chk_add(i64, l11, l1);
        l12 = std_core_write_int(l9, l12, l13);
        l12 = std_core_write_string_at(l9, l12, 277u);
        t1 = l7.payload.obj;
        l13 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
        l12 = std_core_write_int(l9, l12, l13);
        l12 = std_core_write_string_at(l9, l12, 66u);
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core_write_int(l9, l12, l13);
        t3 = std_core_finish_buffer(l9, l12);
        vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a2_obj, 1308u);
        _a2_obj->f_message = t3;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(17u, 0u, 1u, 292u);
    t1 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l1);
    l9 = (void*) _a4_arr;
    l12 = INT64_C(0);
    vader_array_t* _pc339_hdr = (vader_array_t*) l9;
    size_t _pc339_len = _pc339_hdr->length;
    size_t _pc339_cap = (_pc339_hdr->offset == 0 && !vader_array_is_borrowed(_pc339_hdr) && _pc339_hdr->length >= _pc339_hdr->buf->length) ? _pc339_hdr->capacity : (size_t) 0;
    void* _pc339_slots = _pc339_hdr->buf->slots;
    for (;;) {
        if ((l12 < l1)) {
            t1 = l5.payload.obj;
            l14 = ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes;
            l13 = vader_chk_add(i64, l10, l12);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
            t4 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l13, 292u);
            l15 = ((uint8_t) t4.payload.i);
            if (VADER_LIKELY(_pc339_len < _pc339_cap)) {
                ((uint8_t*) _pc339_slots)[_pc339_len] = (uint8_t) ((int32_t) (uint8_t) l15);
                _pc339_len += 1;
            } else {
                _pc339_hdr->length = _pc339_len;
                if (_pc339_hdr->buf->length < _pc339_len) {
                    _pc339_hdr->buf->length = _pc339_len;
                }
                vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l15);
                _pc339_hdr = (vader_array_t*) l9;
                _pc339_len = _pc339_hdr->length;
                _pc339_cap = (_pc339_hdr->offset == 0 && !vader_array_is_borrowed(_pc339_hdr) && _pc339_hdr->length >= _pc339_hdr->buf->length) ? _pc339_hdr->capacity : (size_t) 0;
                _pc339_slots = _pc339_hdr->buf->slots;
            }
            l12 = (l12 + INT64_C(1));
            continue;
        }
        _pc339_hdr->length = _pc339_len;
        if (_pc339_hdr->buf->length < _pc339_len) {
            _pc339_hdr->buf->length = _pc339_len;
        }
        break;
    }
    l10 = INT64_C(0);
    while ((l10 < l1)) {
        t1 = l7.payload.obj;
        l14 = ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes;
        l12 = vader_chk_add(i64, l11, l10);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        t4 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l10, 292u);
        l15 = ((uint8_t) t4.payload.i);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l12] = (uint8_t) (int32_t) (uint8_t) l15;
        l10 = (l10 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm_drop_due_timers(void* l0) {
    int64_t l1, l2, l3, l4, l5, l6;
    int64_t t0;
    vader_box_t t1;
    l1 = INT64_C(1);
    for (;;) {
        l2 = ((vader_array_t*) l0)->length;
        if ((l1 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l3 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
            l4 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
            if ((l3 <= l4)) {
                t0 = ((vader_array_t*) l0)->length;
                l5 = vader_chk_sub(i64, t0, INT64_C(1));
                l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
                ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l6;
                t1 = vader_array_remove_last((vader_array_t*) l0);
                continue;
            }
            l1 = vader_chk_add(i64, l1, INT64_C(1));
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

static void* vader_vm_effect(int64_t l0, int64_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_vm_StackEffect_t* _a0_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
    vader_obj_header_init(_a0_obj, 1304u);
    _a0_obj->f_pops = l0;
    _a0_obj->f_pushes = l1;
    _a0_obj->f_flow = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_effect_of(void* l0, void* l1, vader_box_t l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_locals)->length;
    l3 = vader_chk_add(i64, l3, l4);
    if (l2.tag == 759u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        l5 = vader_vm_indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 760u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        l5 = vader_vm_indexed_effect(t1, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 761u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        l5 = vader_vm_indexed_effect(t1, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 758u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
        l5 = vader_vm_indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 783u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StringConst_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 682u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 707u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_globals)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 708u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_GlobalSet_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_globals)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 675u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        t2 = vader_vm_in_range(l6, l3);
        if (t2) {
            l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            l7 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_signature;
            l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_params)->length;
            l4 = vader_bytecode_bc_result_arity(l7);
            t0 = vader_vm_effect(l3, l4);
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 676u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports)->length;
        t2 = vader_vm_in_range(l6, l3);
        if (t2) {
            l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            l7 = ((vader_struct_vader_bytecode_BcImport_t*) t0)->f_signature;
            l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_params)->length;
            l4 = vader_bytecode_bc_result_arity(l7);
            t0 = vader_vm_effect(l3, l4);
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 677u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        l5 = vader_vm_indirect_effect(l0, l6);
    } else if (l2.tag == 806u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_parameter_count;
        if ((t1 < INT32_C(0))) {
            l5 = vader_box_obj(0u, NULL);
        } else {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_parameter_count;
            l3 = ((int64_t) (int32_t) t1);
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
            l4 = vader_vm_virtual_result_arity(l0, l8);
            t0 = vader_vm_effect(l3, l4);
            l5 = vader_ref_box(t0);
        }
    } else if (l2.tag == 706u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 705u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 763u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 787u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l5 = vader_vm_struct_new_effect(l0, l6);
    } else if (l2.tag == 631u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
            t0 = vader_vm_effect(((int64_t) (int32_t) t1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 790u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 789u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm_indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 679u) {
        t0 = l2.payload.obj;
        t2 = vader_bytecode_is_integer_val(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_vm_effect(INT64_C(2), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 680u) {
        t0 = l2.payload.obj;
        t2 = vader_bytecode_is_integer_val(((vader_struct_vader_bytecode_CheckedNeg_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_vm_effect(INT64_C(1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if ((l2.tag == 663u || l2.tag == 678u || l2.tag == 693u || l2.tag == 714u || l2.tag == 734u || l2.tag == 765u)) {
        t0 = vader_vm_effect(INT64_C(0), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 630u || l2.tag == 634u || l2.tag == 659u || l2.tag == 660u || l2.tag == 666u || l2.tag == 670u || l2.tag == 681u || l2.tag == 691u || l2.tag == 702u || l2.tag == 704u || l2.tag == 711u || l2.tag == 724u || l2.tag == 731u || l2.tag == 744u || l2.tag == 767u || l2.tag == 770u || l2.tag == 773u || l2.tag == 786u || l2.tag == 803u)) {
        t0 = vader_vm_effect(INT64_C(1), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 629u || l2.tag == 635u || l2.tag == 662u || l2.tag == 664u || l2.tag == 665u || l2.tag == 667u || l2.tag == 671u || l2.tag == 692u || l2.tag == 694u || l2.tag == 695u || l2.tag == 696u || l2.tag == 697u || l2.tag == 698u || l2.tag == 699u || l2.tag == 700u || l2.tag == 701u || l2.tag == 703u || l2.tag == 709u || l2.tag == 710u || l2.tag == 712u || l2.tag == 713u || l2.tag == 715u || l2.tag == 716u || l2.tag == 717u || l2.tag == 718u || l2.tag == 719u || l2.tag == 720u || l2.tag == 721u || l2.tag == 722u || l2.tag == 723u || l2.tag == 725u || l2.tag == 726u || l2.tag == 727u || l2.tag == 728u || l2.tag == 729u || l2.tag == 730u || l2.tag == 732u || l2.tag == 733u || l2.tag == 735u || l2.tag == 736u || l2.tag == 737u || l2.tag == 738u || l2.tag == 739u || l2.tag == 740u || l2.tag == 741u || l2.tag == 742u || l2.tag == 743u || l2.tag == 745u || l2.tag == 746u || l2.tag == 747u || l2.tag == 748u || l2.tag == 751u || l2.tag == 752u || l2.tag == 753u || l2.tag == 754u || l2.tag == 755u || l2.tag == 756u || l2.tag == 757u || l2.tag == 768u || l2.tag == 769u || l2.tag == 782u || l2.tag == 784u || l2.tag == 785u || l2.tag == 791u || l2.tag == 792u || l2.tag == 793u || l2.tag == 794u || l2.tag == 795u || l2.tag == 796u || l2.tag == 797u || l2.tag == 798u || l2.tag == 799u || l2.tag == 800u || l2.tag == 801u || l2.tag == 802u)) {
        t0 = vader_vm_effect(INT64_C(2), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 632u || l2.tag == 633u || l2.tag == 788u || l2.tag == 804u)) {
        t0 = vader_vm_effect(INT64_C(2), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 636u || l2.tag == 672u || l2.tag == 775u || l2.tag == 776u || l2.tag == 777u || l2.tag == 778u || l2.tag == 779u || l2.tag == 780u || l2.tag == 781u)) {
        t0 = vader_vm_effect(INT64_C(3), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if (l2.tag == 637u) {
        t0 = vader_vm_effect(INT64_C(3), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 628u || l2.tag == 764u)) {
        t0 = vader_vm_effect(INT64_C(5), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 627u || l2.tag == 685u || l2.tag == 686u)) {
        t0 = vader_vm_effect(INT64_C(1), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 661u || l2.tag == 684u || l2.tag == 690u || l2.tag == 762u)) {
        t0 = vader_vm_effect(INT64_C(0), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 669u || l2.tag == 749u)) {
        vader_struct_vader_vm_StackEffect_t* _a2_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
        vader_obj_header_init(_a2_obj, 1304u);
        _a2_obj->f_pops = INT64_C(1);
        _a2_obj->f_pushes = INT64_C(0);
        _a2_obj->f_flow = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 668u || l2.tag == 687u)) {
        vader_struct_vader_vm_StackEffect_t* _a3_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
        vader_obj_header_init(_a3_obj, 1304u);
        _a3_obj->f_pops = INT64_C(0);
        _a3_obj->f_pushes = INT64_C(0);
        _a3_obj->f_flow = (uint8_t) 1;
        t0 = (void*) _a3_obj;
        l5 = vader_ref_box(t0);
    } else {
        if (!((l2.tag == 771u || l2.tag == 772u || l2.tag == 805u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm_StackEffect_t* _a4_obj = (vader_struct_vader_vm_StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_StackEffect_t));
        vader_obj_header_init(_a4_obj, 1304u);
        _a4_obj->f_pops = INT64_C(0);
        _a4_obj->f_pushes = INT64_C(0);
        _a4_obj->f_flow = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l5 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_vm_element_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_string_t t0;
    uint8_t t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_raw;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        t1 = vader_host_std_core_byte_at(t0, l1);
        return vader_box_i32(290u, ((int32_t) (uint8_t) t1));
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    return t2;
}

static vader_string_t vader_vm_element_label(int32_t l0) {
    if (l0 == INT32_C(115)) {
        return 2086u;
    }
    if (l0 == INT32_C(116)) {
        return 2441u;
    }
    if (!(l0 == INT32_C(114))) {
        return 1422u;
    }
    return 1435u;
}

static uint8_t vader_vm_element_tags(void* l0, int32_t l1) {
    void* l2;
    int64_t l3;
    vader_box_t l4;
    int32_t l5;
    bool t0;
    void* t1;
    uint8_t t2;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_module)->f_types;
    l3 = ((vader_array_t*) l2)->length;
    t0 = vader_vm_in_range(l1, l3);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l4.tag == 639u) {
            t1 = l4.payload.obj;
            l5 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
            t2 = vader_vm_tags_of_type(l0, l5);
            return t2;
        }
        return (uint8_t) 127;
    }
    return (uint8_t) 127;
}

static void* vader_vm_element_trap(void* l0, int64_t l1, int32_t l2, int32_t l3, void* l4, int64_t l5, int32_t l6) {
    vader_string_t l7 = 0;
    int64_t l8, l14;
    void* l9 = NULL;
    void* l11 = NULL;
    vader_box_t l10 = vader_box_null();
    int32_t l12, l13;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[5] = { &l0, &l4, &l9, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_vm_element_label(l6);
    l8 = ((int64_t) (int32_t) l2);
    l8 = vader_chk_add(i64, l1, l8);
    l10 = vader_vm_array_at(l0, l8);
    if (l10.tag == 0u) {
        t0 = vader_vm_receiver_trap(l0, l8, l4, l5, l7, 1409u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    l8 = ((int64_t) (int32_t) l3);
    l8 = vader_chk_add(i64, l1, l8);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
    l12 = ((int32_t) (int64_t) t1);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l4)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l13 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
    l8 = vader_host_std_core_byte_len(l7);
    l11 = (void*) vader_buffer_new((size_t) (INT64_C(95) + l8));
    l8 = INT64_C(0);
    l8 = std_core_write_string_at(l11, l8, l7);
    l8 = std_core_write_string_at(l11, l8, 101u);
    l14 = ((int64_t) (int32_t) l12);
    l8 = std_core_write_int(l11, l8, l14);
    l8 = std_core_write_string_at(l11, l8, 139u);
    l14 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_length;
    l8 = std_core_write_int(l11, l8, l14);
    l8 = std_core_write_string_at(l11, l8, 276u);
    l14 = ((int64_t) (int32_t) l13);
    l8 = std_core_write_int(l11, l8, l14);
    t2 = std_core_finish_buffer(l11, l8);
    vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a2_obj, 1308u);
    _a2_obj->f_message = t2;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_emit(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5) {
    void* l6 = NULL;
    int32_t l7;
    int64_t l8;
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
        l7 = ((int32_t) (int64_t) l1);
    }
    vader_array_push_i32((vader_array_t*) l6, l7);
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds, INT32_C(14));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_enter_frame(void* l0, void* l1, int64_t l2) {
    int64_t l3, l4, l5, l7, l8, l10;
    void* l6 = NULL;
    void* l9 = NULL;
    uint8_t l11;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_registers;
    l3 = vader_chk_add(i64, l2, l3);
    vader_vm_reserve_registers(l0, l3);
    l3 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_params;
    l3 = vader_chk_add(i64, l2, l3);
    l4 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_slots;
    l4 = vader_chk_add(i64, l2, l4);
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(5);
        l3 = (l3 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_vm_RegFunction_t*) l1)->f_slots;
    l3 = vader_chk_add(i64, l2, l3);
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_consts)->length;
    while ((l4 < l5)) {
        l6 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        l7 = vader_chk_add(i64, l3, l4);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_consts);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l8 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7] = (int64_t) l8;
        l9 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags;
        l10 = vader_chk_add(i64, l3, l4);
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l1)->f_const_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l4, 292u);
        l11 = ((uint8_t) t0.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l11;
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_exec_array_copy(void* l0) {
    int64_t l1, l8, l9, l10, l11;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l3;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t t0, t4;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[5] = { &l2, &l4, &l5, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l12, &l13, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_i32(l2, l3, 1418u);
    if (l2.tag == 1308u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 1417u);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_peek_array_mut(l0, l1, l3, 1416u);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(4));
    l6 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = vader_vm_read_i32(l6, l3, 1421u);
    if (l6.tag == 1308u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l7 = vader_vm_peek_array_mut(l0, l1, l3, 1420u);
    if (l7.tag == 1308u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    l1 = vader_vm_clamp_nonneg(t2);
    t2 = ((int32_t) l6.payload.i);
    l8 = vader_vm_clamp_nonneg(t2);
    t2 = ((int32_t) l4.payload.i);
    l9 = vader_vm_clamp_nonneg(t2);
    l10 = vader_chk_add(i64, l8, l1);
    t1 = l7.payload.obj;
    l11 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
    if ((l10 > l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(64));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l12, l10, 1419u);
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l11 = ((int64_t) (int32_t) t2);
        l10 = std_core_write_int(l12, l10, l11);
        t3 = std_core_finish_buffer(l12, l10);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_chk_add(i64, l9, l1);
    t1 = l5.payload.obj;
    l11 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
    if ((l10 > l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(103));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l12, l10, 1415u);
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l11 = ((int64_t) (int32_t) t2);
        l10 = std_core_write_int(l12, l10, l11);
        t3 = std_core_finish_buffer(l12, l10);
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1308u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(247u, 0u, 0u, 1949u);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l1);
    l12 = (void*) _a3_arr;
    l10 = INT64_C(0);
    while ((l10 < l1)) {
        l13 = l7.payload.obj;
        t1 = l7.payload.obj;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_offset;
        t4 = vader_chk_add(i64, t0, l8);
        l11 = vader_chk_add(i64, t4, l10);
        l2 = vader_vm_element_at(l13, l11);
        vader_array_push((vader_array_t*) l12, l2);
        l10 = (l10 + INT64_C(1));
    }
    t1 = l5.payload.obj;
    vader_vm_own_bytes(t1);
    l8 = INT64_C(0);
    while ((l8 < l1)) {
        t1 = l5.payload.obj;
        l13 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_elements;
        t1 = l5.payload.obj;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_offset;
        t4 = vader_chk_add(i64, t0, l9);
        l10 = vader_chk_add(i64, t4, l8);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        l2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l10] = l2;
        VADER_WRITE_BARRIER(_a5_slotarr->buf);
        l8 = (l8 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_array_push_all(void* l0) {
    int64_t l1, l5, l8;
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l9 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l9 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_vm_peek_array_mut(l0, l1, l2, 1429u);
    if (l3.tag == 1308u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_peek_array_mut(l0, l1, l2, 1428u);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    vader_vm_detach_array_view(t1);
    t1 = l3.payload.obj;
    l1 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        t1 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_elements;
        l7 = l3.payload.obj;
        t1 = l3.payload.obj;
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_offset;
        l8 = vader_chk_add(i64, t0, l5);
        l9 = vader_vm_element_at(l7, l8);
        vader_array_push((vader_array_t*) l6, l9);
        l5 = (l5 + INT64_C(1));
    }
    l6 = l4.payload.obj;
    t1 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
    l1 = vader_chk_add(i64, t0, l1);
    ((vader_struct_vader_vm_ArrayVal_t*) l6)->f_length = l1;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l2;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_array_repeat(void* l0) {
    int64_t l1, l5, l6, l8, l10;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l7, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_i32(l2, l3, 1433u);
    if (l2.tag == 1308u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_peek_array_mut(l0, l1, l3, 1434u);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    l1 = vader_vm_clamp_nonneg(t2);
    t1 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
    if (t0 == INT64_C(0)) {
        l5 = l1;
    } else {
        t1 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
        l5 = vader_chk_mul(i64, l1, l6);
    }
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1949u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l5);
    l7 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        l6 = INT64_C(0);
        t1 = l4.payload.obj;
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
        while ((l6 < l8)) {
            l9 = l4.payload.obj;
            t1 = l4.payload.obj;
            t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_offset;
            l10 = vader_chk_add(i64, t0, l6);
            l2 = vader_vm_element_at(l9, l10);
            vader_array_push((vader_array_t*) l7, l2);
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    t1 = l4.payload.obj;
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_type_id;
    l5 = ((vader_array_t*) l7)->length;
    vader_struct_vader_vm_ArrayVal_t* _a2_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1280u);
    _a2_obj->f_type_id = l3;
    _a2_obj->f_elements = l7;
    _a2_obj->f_offset = INT64_C(0);
    _a2_obj->f_length = l5;
    _a2_obj->f_raw = vader_box_obj(0u, NULL);
    l7 = (void*) _a2_obj;
    vader_vm_push_val(l0, l1, vader_ref_box(l7));
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_array_slice(void* l0, void* l1) {
    int64_t l2, l7, l8, l10;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    int32_t l4;
    void* l9 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm_peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_vm_read_i32(l3, l4, 1437u);
    if (l3.tag == 1308u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm_peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_i32(l5, l4, 1438u);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l4 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = vader_vm_peek_array_mut(l0, l2, l4, 1439u);
    if (l6.tag == 1308u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l6.payload.obj;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_length;
    t2 = ((int32_t) l5.payload.i);
    l7 = vader_vm_clamp_nonneg(t2);
    if ((l7 > l2)) {
        l7 = l2;
    }
    t2 = ((int32_t) l3.payload.i);
    l8 = vader_vm_clamp_nonneg(t2);
    if ((l8 < l7)) {
        l8 = l7;
    }
    if ((l8 > l2)) {
        l8 = l2;
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l4 = ((vader_struct_vader_bytecode_ArraySlice_t*) l1)->f_type_id;
    t1 = l6.payload.obj;
    l9 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_elements;
    t1 = l6.payload.obj;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_offset;
    l10 = vader_chk_add(i64, t0, l7);
    l7 = vader_chk_sub(i64, l8, l7);
    t1 = l6.payload.obj;
    l3 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_raw;
    vader_struct_vader_vm_ArrayVal_t* _a0_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a0_obj, 1280u);
    _a0_obj->f_type_id = l4;
    _a0_obj->f_elements = l9;
    _a0_obj->f_offset = l10;
    _a0_obj->f_length = l7;
    _a0_obj->f_raw = l3;
    l9 = (void*) _a0_obj;
    vader_vm_push_val(l0, l2, vader_ref_box(l9));
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l4;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_buffer_write_string(void* l0) {
    int64_t l1, l7, l9, l11;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l3, l8;
    vader_string_t l6 = 0;
    void* l10 = NULL;
    uint8_t l12;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l2, &l4, &l5 };
    void** gc_raw_roots[3] = { &l0, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_string(l2, l3, 1506u);
    if (l2.tag == 1308u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_i32(l4, l3, 1504u);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l5 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_read_obj(l5, l3, 1505u);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l2.payload.s;
    l3 = ((int32_t) l4.payload.i);
    l1 = vader_host_std_core_byte_len(l6);
    t1 = l5.payload.obj;
    l7 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_check_byte_range(l3, l1, l7, 1503u, l8);
    if (l2.tag == 1308u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((int64_t) l2.payload.i);
    l7 = INT64_C(0);
    l9 = vader_host_std_core_byte_len(l6);
    while ((l7 < l9)) {
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes;
        l11 = vader_chk_add(i64, l1, l7);
        l12 = vader_host_std_core_byte_at(l6, l7);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l11)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l11] = (uint8_t) (int32_t) (uint8_t) l12;
        l7 = (l7 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_exec_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5) {
    bool l6;
    int64_t l7, l8;
    void* l9 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t2 };
    void** gc_raw_roots[4] = { &l0, &l2, &l9, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l6 = true;
    } else {
        l7 = ((int64_t) (int32_t) l1);
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions)->length;
        l6 = (l7 >= l8);
    }
    if (l6) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(46));
        l7 = INT64_C(0);
        l7 = std_core_write_string_at(l9, l7, 2205u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core_write_int(l9, l7, l8);
        l7 = std_core_write_string_at(l9, l7, 269u);
        t0 = std_core_finish_buffer(l9, l7);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 0u) {
        l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_reg;
        t2 = vader_vm_reg_run(l0, l9, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_struct_vader_vm_VmState_t*) l0)->f_debuggable;
    if (!(t3)) {
        vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a1_obj, 1308u);
        _a1_obj->f_message = 1305u;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_reg;
    t2 = vader_vm_reg_run(l0, l9, l1, l2, l3, l4, l5);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    l2 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_vm_VmState_t*) l0)->f_fn_index_by_name, l1);
    if (l2.tag == 0u) {
        t0 = concat_3(1727u, l1, 234u);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 0u, 287u);
    l3 = (void*) _a1_arr;
    t2 = vader_vm_zero_value();
    vader_array_t* _a2_arr = vader_array_new(247u, 1u, 0u, 1949u);
    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = t2;
    l4 = (void*) _a2_arr;
    l5 = ((int32_t) l2.payload.i);
    l2 = vader_vm_exec_entry(l0, l5, l3, vader_ref_box(l4), true, vader_box_obj(0u, NULL));
    if (!(l2.tag == 1308u)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        vader_struct_vader_vm_ValueOk_t* _a4_obj = (vader_struct_vader_vm_ValueOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ValueOk_t));
        vader_obj_header_init(_a4_obj, 1310u);
        _a4_obj->f_value = t2;
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_exec_string_compare(void* l0) {
    int64_t l1, l8;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[3] = { &l0, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l2 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l2 = vader_vm_read_string(l2, l3, 2450u);
    if (l2.tag == 1308u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm_peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_read_string(l4, l3, 2450u);
    if (!(l4.tag == 1308u)) {
        l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_payload;
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        l1 = vader_chk_sub(i64, t0, INT64_C(2));
        l6 = l2.payload.s;
        l7 = l4.payload.s;
        l8 = ((int64_t) (int32_t) vader_string_compare(l6, l7));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l8;
        l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_tag;
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        l1 = vader_chk_sub(i64, t0, INT64_C(2));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        l1 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l1;
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l3 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l3;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_extern_result(uint8_t l0, int64_t l1) {
    bool l2;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = 1773u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        t1 = vader_vm_zero_value();
        vader_struct_vader_vm_HostOk_t* _a1_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a1_obj, 1289u);
        _a1_obj->f_value = t1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_vm_HostOk_t* _a2_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a2_obj, 1289u);
        _a2_obj->f_value = vader_box_bool(285u, ((int32_t) (int64_t) (l1 & INT64_C(4294967295))) != INT32_C(0));
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(5);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(0);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(11);
    }
    if (!(l2)) {
        vader_struct_vader_vm_HostOk_t* _a3_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
        vader_obj_header_init(_a3_obj, 1289u);
        _a3_obj->f_value = vader_box_i64(291u, l1);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_HostOk_t* _a4_obj = (vader_struct_vader_vm_HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_HostOk_t));
    vader_obj_header_init(_a4_obj, 1289u);
    _a4_obj->f_value = vader_box_i32(290u, ((int32_t) (int64_t) l1));
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, int64_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    int64_t l6;
    void* l7 = NULL;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l0, &l4, &t0 };
    void** gc_raw_roots[1] = { &l7 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 291u)) {
        l4 = l0;
        l5 = l2;
        l6 = vader_host_std_core_byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(34) + l6));
        l6 = INT64_C(0);
        l6 = std_core_write_string_at(l7, l6, 1772u);
        l6 = std_core_write_string_at(l7, l6, l5);
        l6 = std_core_write_string_at(l7, l6, 937u);
        l6 = std_core_write_int(l7, l6, l3);
        l5 = std_core_finish_buffer(l7, l6);
        t0 = vader_vm_read_i64(l4, l1, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int64_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(291u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_vm_f64_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t0) }).__vd);
}

static int32_t vader_vm_ffi_result_class(uint8_t l0) {
    if (l0 == INT32_C(14)) {
        return INT32_C(0);
    }
    if (l0 == INT32_C(9)) {
        return INT32_C(2);
    }
    if (!(l0 == INT32_C(12))) {
        return INT32_C(1);
    }
    return INT32_C(4);
}

static bool vader_vm_ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2) {
    int64_t l3, l4, l10, l11;
    vader_box_t l5;
    bool l6, l7;
    void* l8;
    int32_t l9;
    void* t0;
    int64_t t1;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    l3 = ((int64_t) (int32_t) l1);
    l4 = ((vader_array_t*) l0)->length;
    if ((l3 >= l4)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l5.tag == 654u)) {
        return false;
    }
    t0 = l5.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants)->length;
    if (t1 != INT64_C(2)) {
        return false;
    }
    l6 = false;
    l7 = false;
    t0 = l5.payload.obj;
    l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
    l3 = ((vader_array_t*) l8)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        if (!((l9 < INT32_C(0)))) {
            l10 = ((int64_t) (int32_t) l9);
            l11 = ((vader_array_t*) l0)->length;
            if (!((l10 >= l11))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
                l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                if (l5.tag == 650u) {
                    t0 = l5.payload.obj;
                    if (((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val == INT32_C(13)) {
                        l6 = true;
                    }
                    t0 = l5.payload.obj;
                    if (((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val == l2) {
                        l7 = true;
                    }
                }
                l4 = (l4 + INT64_C(1));
                continue;
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    if (l6) {
        return l7;
    }
    return false;
}

static uint8_t vader_vm_field_tags(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t l6;
    bool t0;
    void* t1;
    uint8_t t2;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_module)->f_types;
    l4 = ((vader_array_t*) l3)->length;
    t0 = vader_vm_in_range(l1, l4);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l5.tag == 653u) {
            t1 = l5.payload.obj;
            l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields)->length;
            t0 = vader_vm_in_range(l2, l4);
            if (t0) {
                t1 = l5.payload.obj;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
                t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
                l6 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_type_index;
                t2 = vader_vm_tags_of_type(l0, l6);
                return t2;
            }
        }
        if (l5.tag == 654u) {
            l5 = vader_bytecode_union_layout_struct(l3, l1);
            if (l5.tag == 0u) {
                return (uint8_t) 127;
            }
            l6 = ((int32_t) l5.payload.i);
            t2 = vader_vm_field_tags(l0, l6, l2);
            return t2;
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

uint8_t vader_vm_field_valtype(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    if ((l1 < INT32_C(0))) {
        return (uint8_t) 16;
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return (uint8_t) 16;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l4.tag == 650u)) {
        return (uint8_t) 16;
    }
    t0 = l4.payload.obj;
    return ((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val;
}

static int32_t vader_vm_find_io_error_type_id(void* l0) {
    int32_t t0;
    t0 = vader_bytecode_struct_type_index(l0, 2421u);
    return t0;
}

static int32_t vader_vm_find_string_array_type_id(void* l0) {
    int32_t l1;
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l1 = INT32_C(-1);
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 650u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val == INT32_C(12)) {
                l1 = ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    if ((l1 < INT32_C(0))) {
        return INT32_C(0);
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        if (l4.tag == 639u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(0);
}

static int32_t vader_vm_find_u8_array_type_id(void* l0) {
    int32_t l1;
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l1 = INT32_C(-1);
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 650u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val == INT32_C(4)) {
                l1 = ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    if ((l1 < INT32_C(0))) {
        return INT32_C(0);
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        if (l4.tag == 639u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
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
            vader_obj_header_init(_a0_obj, 1294u);
            _a0_obj->f_value = INT32_C(0);
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_vm_register_value(l0, INT64_C(0));
        l4 = vader_vm_read_i32(t1, INT32_C(0), 2333u);
        if (!(l4.tag == 1308u)) {
            t2 = ((int32_t) l4.payload.i);
            vader_struct_vader_vm_Ok_t* _a1_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
            vader_obj_header_init(_a1_obj, 1294u);
            _a1_obj->f_value = t2;
            t0 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        l3 = l2.payload.obj;
        l4 = vader_vm_register_value(l0, INT64_C(0));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) INT32_C(0)] = l4;
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        vader_struct_vader_vm_Ok_t* _a3_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
        vader_obj_header_init(_a3_obj, 1294u);
        _a3_obj->f_value = INT32_C(0);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm_Ok_t* _a4_obj = (vader_struct_vader_vm_Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Ok_t));
    vader_obj_header_init(_a4_obj, 1294u);
    _a4_obj->f_value = INT32_C(0);
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_fits_signed(int32_t l0, int64_t l1) {
    int64_t l2, l3;
    l2 = ((int64_t) (int32_t) l0);
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    l3 = vader_chk_neg(i64, (INT64_C(1) << (l3 & 63)));
    if ((l2 >= l3)) {
        l2 = ((int64_t) (int32_t) l0);
        l3 = vader_chk_sub(i64, l1, INT64_C(1));
        l3 = (INT64_C(1) << (l3 & 63));
        return (l2 < l3);
    }
    return false;
}

static vader_box_t vader_vm_flow_to(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5, int64_t l6) {
    int64_t l7;
    void* l8 = NULL;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
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
    l8 = (void*) vader_buffer_new((size_t) INT64_C(98));
    l7 = INT64_C(0);
    l7 = std_core_write_string_at(l8, l7, 1633u);
    l7 = std_core_write_int(l8, l7, l4);
    l7 = std_core_write_string_at(l8, l7, 172u);
    l7 = std_core_write_int(l8, l7, l6);
    l7 = std_core_write_string_at(l8, l7, 61u);
    l9 = std_core_finish_buffer(l8, l7);
    t1 = vader_vm_defect(l0, l5, l9);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_flush(void* l0, int64_t l1) {
    int64_t l2, l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    while ((l2 < l3)) {
        vader_vm_materialise(l0, l1, l2);
        l2 = (l2 + INT64_C(1));
    }
    ((vader_struct_vader_vm_Translation_t*) l0)->f_retarget = INT64_C(-1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm_fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    int64_t l4, l6;
    void* l5 = NULL;
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
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(70) + l4));
    l4 = INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 89u);
    l6 = ((int64_t) (int32_t) l0);
    l4 = std_core_write_int(l5, l4, l6);
    l4 = std_core_write_string_at(l5, l4, 141u);
    l6 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l5, l4, l6);
    t0 = std_core_finish_buffer(l5, l4);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1308u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_fn_type_of(void* l0, int32_t l1) {
    int64_t l2;
    vader_box_t l3;
    bool t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (!(t0)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 642u) {
        t1 = l3.payload.obj;
        return vader_ref_box(t1);
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
        t0 = vader_vm_branch(l1, INT32_C(91), false, INT32_C(92), false);
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        t0 = vader_vm_branch(l1, INT32_C(92), false, INT32_C(91), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(19)) {
        t0 = vader_vm_branch(l1, INT32_C(93), false, INT32_C(94), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(20)) {
        t0 = vader_vm_branch(l1, INT32_C(94), false, INT32_C(93), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(21)) {
        t0 = vader_vm_branch(l1, INT32_C(93), true, INT32_C(94), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(22)) {
        t0 = vader_vm_branch(l1, INT32_C(94), true, INT32_C(93), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(23)) {
        t0 = vader_vm_branch(l1, INT32_C(95), false, INT32_C(96), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(24)) {
        t0 = vader_vm_branch(l1, INT32_C(96), false, INT32_C(95), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(25)) {
        t0 = vader_vm_branch(l1, INT32_C(95), true, INT32_C(96), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(26)) {
        t0 = vader_vm_branch(l1, INT32_C(96), true, INT32_C(95), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(42)) {
        t0 = vader_vm_branch(l1, INT32_C(97), false, INT32_C(98), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(43)) {
        t0 = vader_vm_branch(l1, INT32_C(98), false, INT32_C(97), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(44)) {
        t0 = vader_vm_branch(l1, INT32_C(99), false, INT32_C(100), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(45)) {
        t0 = vader_vm_branch(l1, INT32_C(100), false, INT32_C(99), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(46)) {
        t0 = vader_vm_branch(l1, INT32_C(99), true, INT32_C(100), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(47)) {
        t0 = vader_vm_branch(l1, INT32_C(100), true, INT32_C(99), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(48)) {
        t0 = vader_vm_branch(l1, INT32_C(101), false, INT32_C(102), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(49)) {
        t0 = vader_vm_branch(l1, INT32_C(102), false, INT32_C(101), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(50)) {
        t0 = vader_vm_branch(l1, INT32_C(101), true, INT32_C(102), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(51)) {
        t0 = vader_vm_branch(l1, INT32_C(102), true, INT32_C(101), false);
        l2 = vader_ref_box(t0);
    } else {
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_global_at_comptime_trap(void* l0, int32_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_globals);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l2 = ((vader_struct_vader_bytecode_BcGlobal_t*) t0)->f_name;
    t1 = concat_3(916u, l2, 942u);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_global_tags(void* l0, int32_t l1) {
    int32_t l2;
    uint8_t l3;
    void* t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_module)->f_globals);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l2 = ((vader_struct_vader_bytecode_BcGlobal_t*) t0)->f_type_id;
    l3 = vader_vm_tags_of_type(l0, l2);
    if (!((l3 & INT32_C(64)) != INT32_C(0))) {
        return l3;
    }
    return (uint8_t) (int32_t) (l3 | INT32_C(32));
}

vader_box_t vader_vm_global_zero(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
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
        l1 = vader_box_i32(290u, INT32_C(0));
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l1 = vader_box_i64(291u, INT64_C(0));
    } else {
        if (l0 == INT32_C(8)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l1 = vader_box_f64(297u, 0.0);
        } else if (l0 == INT32_C(10)) {
            l1 = vader_box_bool(285u, false);
        } else if (l0 == INT32_C(11)) {
            l1 = vader_box_i32(286u, (int32_t) ((uint32_t) 0));
        } else if (l0 == INT32_C(12)) {
            l1 = vader_box_string(287u, 0u);
        } else {
            if (l0 == INT32_C(13)) {
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
            if (!(l2)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_struct_vader_vm_NullVal_t* _a0_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
            vader_obj_header_init(_a0_obj, 1292u);
            t0 = (void*) _a0_obj;
            l1 = vader_ref_box(t0);
        }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_grow_frame_records(void* l0, void* l1, int64_t l2, int64_t l3) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_frame_code, vader_ref_box(l1));
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_frame_base, l2);
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_frame_return, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_vm_i32_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
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
    t0 = concat_3(1899u, l0, 1028u);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1308u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_in_range(int32_t l0, int64_t l1) {
    int64_t l2;
    l2 = ((int64_t) (int32_t) l0);
    if ((INT64_C(0) <= l2)) {
        return (l2 < l1);
    }
    return false;
}

static vader_box_t vader_vm_indexed_effect(int32_t l0, int64_t l1, int64_t l2, int64_t l3) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_vm_in_range(l0, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_vm_effect(l2, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_indirect_call_trap(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4) {
    int64_t l5, l9, l13;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    bool l8;
    void* l10 = NULL;
    void* l14 = NULL;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l10, &l14, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_chk_add(i64, l2, l3);
    t0 = vader_vm_register_value(l1, l5);
    l6 = vader_vm_read_fn(t0, l4, 1555u);
    if (l6.tag == 1308u) {
        t1 = l6.payload.obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l6.payload.obj;
    l7 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_function_index;
    if ((l7 < INT32_C(0))) {
        l8 = true;
    } else {
        l5 = ((int64_t) (int32_t) l7);
        l9 = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l0)->f_functions)->length;
        l8 = (l5 >= l9);
    }
    if (l8) {
        t1 = vader_vm_fn_index_trap(l7, l4, 1552u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l0)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    t1 = l6.payload.obj;
    if (((vader_struct_vader_vm_FnVal_t*) t1)->f_env.tag == 0u) {
        l5 = l3;
    } else {
        l5 = vader_chk_add(i64, l3, INT64_C(1));
    }
    t1 = l6.payload.obj;
    if (((vader_struct_vader_vm_FnVal_t*) t1)->f_env.tag == 0u) {
        l11 = 0u;
    } else {
        l11 = 31u;
    }
    l12 = ((vader_struct_vader_vm_RegFunction_t*) l10)->f_name;
    l9 = vader_host_std_core_byte_len(l11);
    l13 = vader_host_std_core_byte_len(l12);
    l9 = (l9 + l13);
    l14 = (void*) vader_buffer_new((size_t) (INT64_C(139) + l9));
    l9 = INT64_C(0);
    l9 = std_core_write_string_at(l14, l9, 1553u);
    l13 = ((int64_t) (int32_t) l4);
    l9 = std_core_write_int(l14, l9, l13);
    l9 = std_core_write_string_at(l14, l9, 403u);
    l9 = std_core_write_int(l14, l9, l5);
    l9 = std_core_write_string_at(l14, l9, l11);
    l9 = std_core_write_string_at(l14, l9, 68u);
    l9 = std_core_write_string_at(l14, l9, l12);
    l9 = std_core_write_string_at(l14, l9, 241u);
    l5 = ((vader_struct_vader_vm_RegFunction_t*) l10)->f_params;
    l9 = std_core_write_int(l14, l9, l5);
    l9 = std_core_write_string_at(l14, l9, 143u);
    t2 = std_core_finish_buffer(l14, l9);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t2;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_indirect_effect(void* l0, int32_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4;
    int32_t l5;
    bool t0;
    int64_t t1, t2;
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
        l4 = INT64_C(0);
    } else {
        l4 = INT64_C(1);
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) l2)->f_params)->length;
    t2 = vader_chk_add(i64, t1, INT64_C(1));
    t3 = vader_vm_effect(t2, l4);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_infer_function_tags(void* l0, void* l1, int64_t l2) {
    int64_t l3, l6, l9;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    uint8_t l10;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l11, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a2_arr;
    l6 = vader_chk_mul(i64, l3, l2);
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a3_arr;
    vader_struct_vader_vm_FunctionTags_t* _a4_obj = (vader_struct_vader_vm_FunctionTags_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_FunctionTags_t));
    vader_obj_header_init(_a4_obj, 1287u);
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
    l3 = vader_chk_add(i64, l3, l6);
    l7 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_module;
    l6 = vader_chk_add(i64, l3, l2);
    l7 = vader_vm_new_blocks(l7, l1, l6);
    vader_array_t* _a5_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l8 = (void*) _a5_arr;
    l6 = ((vader_struct_vader_vm_Blocks_t*) l7)->f_width;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l6);
    l8 = (void*) _a6_arr;
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) l5)->length;
    while ((l6 < l9)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l6, 292u);
        l10 = vader_vm_tags_of_val(((uint8_t) t1.payload.i));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l10;
        l6 = (l6 + INT64_C(1));
    }
    l6 = ((vader_array_t*) l5)->length;
    while ((l6 < l3)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(32);
        l6 = (l6 + INT64_C(1));
    }
    vader_vm_merge_block(l7, INT64_C(0), INT64_C(0), l8);
    vader_array_t* _a10_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a10_arr;
    l6 = ((vader_struct_vader_vm_Blocks_t*) l7)->f_width;
    vader_array_t* _a11_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a11_arr;
    for (;;) {
        t2 = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_work)->length;
        if ((t2 > INT64_C(0))) {
            l11 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_work);
            if (l11.tag == 0u) break;
            l6 = ((int64_t) l11.payload.i);
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_queued);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6] = (uint8_t) false;
            vader_vm_walk_block(l0, l1, l7, l6, l3, l5, vader_box_obj(0u, NULL));
            continue;
        }
        break;
    }
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_leaders)->length;
    while ((l6 < l9)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l7)->f_entry_depth);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        t2 = ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6];
        if ((t2 >= INT64_C(0))) {
            vader_vm_walk_block(l0, l1, l7, l6, l3, l5, vader_ref_box(l4));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_infer_module_tags(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int64_t l4, l5, l7;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm_new_tag_context(l0);
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1287u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        l7 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        l8 = vader_vm_infer_function_tags(l2, l6, l7);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_initial_globals(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_globals;
    vader_struct___lambda_env_vader_vm_1_t* _a0_obj = (vader_struct___lambda_env_vader_vm_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_1_t));
    vader_obj_header_init(_a0_obj, 370u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a2_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l7 = __lambda_vader_vm_0(l2, l6);
        vader_array_push((vader_array_t*) l3, l7);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_inlinable_op(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 686u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 679u || l0.tag == 680u)) {
        l1 = true;
    } else if ((l0.tag == 663u || l0.tag == 678u || l0.tag == 693u || l0.tag == 714u || l0.tag == 734u || l0.tag == 765u)) {
        l1 = true;
    } else if ((l0.tag == 681u || l0.tag == 770u)) {
        l1 = true;
    } else if ((l0.tag == 709u || l0.tag == 710u || l0.tag == 711u || l0.tag == 722u || l0.tag == 724u || l0.tag == 728u)) {
        l1 = true;
    } else if ((l0.tag == 712u || l0.tag == 713u || l0.tag == 725u || l0.tag == 726u || l0.tag == 727u)) {
        l1 = true;
    } else if ((l0.tag == 716u || l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 720u || l0.tag == 723u)) {
        l1 = true;
    } else if ((l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u)) {
        l1 = true;
    } else if ((l0.tag == 729u || l0.tag == 730u || l0.tag == 731u || l0.tag == 742u || l0.tag == 744u || l0.tag == 748u)) {
        l1 = true;
    } else if ((l0.tag == 732u || l0.tag == 733u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u)) {
        l1 = true;
    } else if ((l0.tag == 736u || l0.tag == 737u || l0.tag == 738u || l0.tag == 739u || l0.tag == 740u || l0.tag == 743u)) {
        l1 = true;
    } else if ((l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u)) {
        l1 = true;
    } else if ((l0.tag == 692u || l0.tag == 694u || l0.tag == 700u || l0.tag == 702u || l0.tag == 703u)) {
        l1 = true;
    } else if ((l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 698u || l0.tag == 699u || l0.tag == 701u)) {
        l1 = true;
    } else if ((l0.tag == 662u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u)) {
        l1 = true;
    } else {
        l1 = false;
    }
    return l1;
}

static void* vader_vm_inline_into(void* l0, void* l1, int64_t l2) {
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
    int64_t l8, l9, l26, l27, l32, l33, l37, l38, l39, l44;
    vader_box_t l10 = vader_box_null(), l19 = vader_box_null(), l24 = vader_box_null(), l40 = vader_box_null(), l41 = vader_box_null(), l45 = vader_box_null(), l46 = vader_box_null();
    int32_t l15, l18, l20, l21, l22, l23, l25, l31, l34, l36, l42, l47, l48;
    uint8_t l28;
    vader_string_t l49 = 0;
    bool t0;
    int64_t t1, t4;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    int32_t t5;
    vader_box_t* gc_roots[8] = { &l10, &l19, &l24, &l40, &l41, &l45, &l46, &t3 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l16, &l17, &l29, &l30, &l35, &l43,
        &t2,
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
    vader_struct___lambda_env_vader_vm_4_t* _a1_obj = (vader_struct___lambda_env_vader_vm_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_4_t));
    vader_obj_header_init(_a1_obj, 371u);
    _a1_obj->f_cap_0 = l1;
    l6 = (void*) _a1_obj;
    l7 = false;
    l8 = ((vader_array_t*) l5)->length;
    l9 = INT64_C(0);
    {
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            t0 = __lambda_vader_vm_3(l6, l10);
            if (t0) {
                l7 = true;
                goto end_17;
            }
            l9 = (l9 + INT64_C(1));
        }
        l7 = false;
    } end_17: ;
    if (!(l7)) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(230u, 0u, 13u, 1594u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 290u);
    l11 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 290u);
    l12 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(54u, 0u, 13u, 646u);
    l13 = (void*) _a7_arr;
    l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_locals;
    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l14);
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_params)->length;
    l15 = ((int32_t) (int64_t) t1);
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 290u);
    l14 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(15u, 0u, 7u, 290u);
    l16 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(15u, 0u, 7u, 290u);
    l17 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a11_obj, 384u);
    _a11_obj->f_ekeys = l14;
    _a11_obj->f_evals = l16;
    _a11_obj->f_index = l17;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a11_obj;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) l4)->length;
    while ((l8 < l9)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l10 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        t1 = ((vader_array_t*) l5)->length;
        l18 = ((int32_t) (int64_t) t1);
        vader_array_push_i32((vader_array_t*) l12, l18);
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_debug);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        l19 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
        if (l10.tag == 675u) {
            t2 = l10.payload.obj;
            l20 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l20)
            t3 = vader_box_bool(285u, ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l20]);
            t0 = t3.payload.b;
            if (t0) {
                t2 = l10.payload.obj;
                l21 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l21)
                l16 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l21);
                t2 = l10.payload.obj;
                l23 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                l24 = std_collections_MutableMap_std_core_Index_at__i32__i32(l14, l23);
                if (l24.tag == 0u) {
                    l22 = INT32_C(-1);
                } else {
                    l22 = ((int32_t) l24.payload.i);
                }
                if ((l22 < INT32_C(0))) {
                    t1 = ((vader_array_t*) l13)->length;
                    l25 = ((int32_t) (int64_t) t1);
                    l22 = vader_chk_add(i32, l15, l25);
                    l17 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_signature)->f_params;
                    l26 = ((vader_array_t*) l17)->length;
                    l27 = INT64_C(0);
                    while ((l27 < l26)) {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        t3 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l27, 292u);
                        l28 = ((uint8_t) t3.payload.i);
                        vader_struct_vader_bytecode_BcLocal_t* _a17_obj = (vader_struct_vader_bytecode_BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcLocal_t));
                        vader_obj_header_init(_a17_obj, 646u);
                        _a17_obj->f_name = 1988u;
                        _a17_obj->f_val = l28;
                        l29 = (void*) _a17_obj;
                        vader_array_push((vader_array_t*) l13, vader_ref_box(l29));
                        l27 = (l27 + INT64_C(1));
                    }
                    l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_locals;
                    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l30);
                    t2 = l10.payload.obj;
                    l31 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l14, l31, l22);
                }
                l32 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_signature)->f_params)->length;
                l33 = INT64_C(0);
                while ((l33 < l32)) {
                    t1 = vader_chk_sub(i64, l32, INT64_C(1));
                    t4 = vader_chk_sub(i64, t1, l33);
                    l34 = ((int32_t) (int64_t) t4);
                    t5 = vader_chk_add(i32, l22, l34);
                    vader_struct_vader_bytecode_LocalSet_t* _a18_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
                    vader_obj_header_init(_a18_obj, 760u);
                    _a18_obj->f_slot = t5;
                    l35 = (void*) _a18_obj;
                    vader_array_push((vader_array_t*) l5, vader_ref_box(l35));
                    vader_array_push((vader_array_t*) l6, l19);
                    l36 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l36);
                    l33 = (l33 + INT64_C(1));
                }
                l37 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_body)->length;
                l38 = INT64_C(0);
                l39 = vader_chk_sub(i64, l37, INT64_C(1));
                while ((l38 < l39)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_body);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l38)
                    t3 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l38);
                    l40 = vader_vm_relocated(t3, l22);
                    vader_array_push((vader_array_t*) l5, l40);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l38)
                    l41 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l38);
                    vader_array_push((vader_array_t*) l6, l41);
                    l42 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l42);
                    l38 = (l38 + INT64_C(1));
                }
                l43 = ((vader_struct_vader_bytecode_BcFunction_t*) l16)->f_body;
                l44 = vader_chk_sub(i64, l37, INT64_C(1));
                vader_array_t* _a21_slotarr = ((vader_array_t*) l43);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l44)
                l45 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l44);
                if (l45.tag == 772u) {
                    t2 = l45.payload.obj;
                    l46 = ((vader_struct_vader_bytecode_ReturnLit_t*) t2)->f_value;
                    vader_array_push((vader_array_t*) l5, l46);
                    vader_array_push((vader_array_t*) l6, l19);
                    l47 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l47);
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        vader_array_push((vader_array_t*) l5, l10);
        vader_array_push((vader_array_t*) l6, l19);
        l48 = ((int32_t) (int64_t) l8);
        vader_array_push_i32((vader_array_t*) l11, l48);
        l8 = (l8 + INT64_C(1));
    }
    l4 = l3;
    l49 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_is_main;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_jump_table;
    l8 = ((vader_array_t*) l5)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l12, l8);
    vader_struct_vader_bytecode_BcFunction_t* _a22_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a22_obj, 643u);
    _a22_obj->f_name = l49;
    _a22_obj->f_is_main = l7;
    _a22_obj->f_signature = l4;
    _a22_obj->f_locals = l13;
    _a22_obj->f_body = l5;
    _a22_obj->f_debug = l6;
    _a22_obj->f_jump_table = l3;
    _a22_obj->f_source_pc = l11;
    t2 = (void*) _a22_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    void* l13 = NULL;
    int64_t l2, l4;
    bool l5;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[11] = { &l0, &l1, &l3, &l6, &l8, &l9, &l10, &l11, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 12u, 285u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_vm_is_inline_leaf(t0);
        vader_array_push_bool((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    t1 = std_core____Contains_contains__bool(l1, true);
    if (!(t1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(51u, 0u, 13u, 643u);
    l3 = (void*) _a3_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l2);
    l3 = (void*) _a4_arr;
    l2 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l2 < l4)) {
        l6 = vader_vm_inline_into(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions, l1, l2);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
        l2 = (l2 + INT64_C(1));
    }
    l1 = l0;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_name;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_types;
    l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_strings;
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_data_pool;
    l10 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_imports;
    l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_exports;
    l12 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_impl_table;
    l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_vtables;
    l1 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_globals;
    vader_struct_vader_bytecode_BytecodeModule_t* _a5_obj = (vader_struct_vader_bytecode_BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BytecodeModule_t));
    vader_obj_header_init(_a5_obj, 673u);
    _a5_obj->f_name = l7;
    _a5_obj->f_types = l6;
    _a5_obj->f_strings = l8;
    _a5_obj->f_data_pool = l9;
    _a5_obj->f_functions = l3;
    _a5_obj->f_imports = l10;
    _a5_obj->f_exports = l11;
    _a5_obj->f_impl_table = l12;
    _a5_obj->f_vtables = l13;
    _a5_obj->f_globals = l1;
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
    int64_t l2, l4;
    vader_string_t l3 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l2 = std_string_last_index_of(l1, 46u, INT64_C(0));
    if (!((l2 < INT64_C(0)))) {
        l3 = vader_host_std_core_byte_slice(l1, INT64_C(0), l2);
        l2 = vader_chk_add(i64, l2, INT64_C(1));
        l4 = vader_host_std_core_byte_len(l1);
        l5 = vader_host_std_core_byte_slice(l1, l2, l4);
        l3 = vader_types_trait_key_name(l3);
        t0 = vader_bytecode_primitive_member_mangle(l0, l3, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static bool vader_vm_is_array_view(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    t0 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
    if (t0 != INT64_C(0)) {
        return true;
    }
    l1 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
    l2 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    l1 = vader_chk_add(i64, l1, l2);
    l2 = ((vader_array_t*) ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements)->length;
    return (l1 < l2);
}

static bool vader_vm_is_boxed(vader_box_t l0) {
    return (l0.tag == 627u || l0.tag == 628u || l0.tag == 631u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 637u || l0.tag == 659u || l0.tag == 660u || l0.tag == 662u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 670u || l0.tag == 671u || l0.tag == 672u || l0.tag == 681u || l0.tag == 682u || l0.tag == 691u || l0.tag == 704u || l0.tag == 706u || l0.tag == 707u || l0.tag == 708u || l0.tag == 716u || l0.tag == 723u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 757u || l0.tag == 763u || l0.tag == 764u || l0.tag == 768u || l0.tag == 769u || l0.tag == 773u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 781u || l0.tag == 782u || l0.tag == 784u || l0.tag == 785u || l0.tag == 787u || l0.tag == 789u || l0.tag == 790u);
}

static bool vader_vm_is_fn_index_out_of_range(int32_t l0, void* l1) {
    int64_t l2, l3;
    if ((l0 < INT32_C(0))) {
        return true;
    }
    l2 = ((int64_t) (int32_t) l0);
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
    t0 = std_string_string_std_core_Contains_contains(l0, 2033u);
    return t0;
}

static bool vader_vm_is_impure_host(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(21)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(22);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(23);
    }
    if (l2) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(19)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(20);
    }
    if (l2) {
        l1 = true;
    } else {
        if (l0 == INT32_C(15)) {
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
            l1 = true;
        } else {
            if (l0 == INT32_C(1)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(2);
            }
            if (l2) {
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
                l1 = false;
            } else {
                if (l0 == INT32_C(5)) {
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
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(8);
                }
                if (l2) {
                    l1 = false;
                } else {
                    if (l0 == INT32_C(9)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(10);
                    }
                    if (l2) {
                        l1 = false;
                    } else {
                        if (l0 == INT32_C(11)) {
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
                            l1 = false;
                        } else if (l0 == INT32_C(18)) {
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
    int64_t l1, l2, l4;
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7, l8;
    bool t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t2 };
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
    l2 = INT64_C(17);
    if ((l1 > l2)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    if ((t1 > INT64_C(1))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!((t2.tag == 771u || t2.tag == 772u))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    l4 = vader_chk_add(i64, l2, l4);
    l3 = (void*) &vader_fn_static___lambda_vader_vm_2;
    l3 = std_core_filled__bool(l4, l3);
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l1 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l1);
    l5 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l5)->length;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        t0 = vader_vm_inlinable_op(l6);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = vader_vm_slot_touched_by(l6);
        l8 = ((int32_t) (int64_t) l2);
        if ((l7 >= l8)) {
            if (l6.tag == 759u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                t2 = vader_box_bool(285u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7]);
                t0 = t2.payload.b;
                if (!(t0)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
            }
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (uint8_t) true;
        }
        l4 = (l4 + INT64_C(1));
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
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
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
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_vm_is_singleton_comptime_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string_string_std_core_Contains_contains(l0, 1460u);
    return t0;
}

static bool vader_vm_is_source_local(vader_string_t l0) {
    int64_t t0;
    uint8_t t1;
    t0 = vader_host_std_core_byte_len(l0);
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = vader_host_std_core_byte_at(l0, INT64_C(0));
    if (t1 == INT32_C(36)) {
        return false;
    }
    t0 = vader_host_std_core_byte_len(l0);
    if ((t0 >= INT64_C(2))) {
        t1 = vader_host_std_core_byte_at(l0, INT64_C(0));
        if (t1 == INT32_C(95)) {
            t1 = vader_host_std_core_byte_at(l0, INT64_C(1));
            if (t1 == INT32_C(95)) {
                return false;
            }
        }
    }
    if (!(l0 == 1955u)) {
        return true;
    }
    return false;
}

static bool vader_vm_is_std_handle_symbol(vader_string_t l0) {
    return l0 == 549u;
}

static bool vader_vm_is_unsigned_source(vader_string_t l0) {
    int64_t t0;
    uint8_t t1;
    t0 = vader_host_std_core_byte_len(l0);
    if ((t0 > INT64_C(0))) {
        t1 = vader_host_std_core_byte_at(l0, INT64_C(0));
        return t1 == INT32_C(117);
    }
    return false;
}

static bool vader_vm_is_write_symbol(vader_string_t l0) {
    bool l1;
    if (l0 == 2814u) {
        l1 = true;
    } else {
        l1 = l0 == 914u;
    }
    if (l1) {
        return true;
    }
    return l0 == 845u;
}

static void vader_vm_jump(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5) {
    bool l6, l10;
    int32_t l7, l8, l9;
    void* l11 = NULL;
    int64_t l12;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l5 >= INT32_C(0))) {
        l7 = ((int32_t) (int64_t) l1);
        l6 = (l5 < l7);
    } else {
        l6 = false;
    }
    t0 = vader_chk_sub(i32, ((int32_t) (int64_t) l1), l5);
    l7 = vader_chk_add(i32, t0, INT32_C(1));
    l8 = l2;
    l9 = l3;
    if (l6) {
        l10 = l2 == INT32_C(87);
    } else {
        l10 = false;
    }
    if (l10) {
        l8 = INT32_C(88);
        l9 = l7;
    } else if (l6) {
        vader_vm_emit(l0, l1, INT32_C(109), INT32_C(0), l7, INT32_C(0));
    }
    l11 = ((vader_struct_vader_vm_Translation_t*) l0)->f_jumps;
    l12 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_ops)->length;
    vader_array_push_i64((vader_array_t*) l11, l12);
    l11 = ((vader_struct_vader_vm_Translation_t*) l0)->f_jumps;
    l12 = ((int64_t) (int32_t) l5);
    vader_array_push_i64((vader_array_t*) l11, l12);
    vader_vm_emit(l0, l1, l8, INT32_C(0), l9, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_lent_element_val_type(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    int32_t l5;
    void* t0;
    int32_t t1;
    bool t2;
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l4.tag == 639u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
    if ((t1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
    l2 = ((int64_t) (int32_t) t1);
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    if (!(l4.tag == 650u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t2 = vader_bytecode_is_integer_val(((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val);
    if (!(t2)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_box_i32(292u, (int32_t)(uint32_t) ((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val);
}

static bool vader_vm_line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_vm_DebugController_t*) l0)->f_breakpoints, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableSet_std_core_Contains_contains__i32(t0, l2);
    return t1;
}

static vader_box_t vader_vm_load_bytes_op(void* l0, int64_t l1, vader_string_t l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l7;
    void* l8 = NULL;
    int64_t t0;
    void* t1 = NULL;
    uint64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[3] = { &l0, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm_stack_i32(l0, l3, l2, 2232u);
    if (l4.tag == 1308u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm_stack_obj(l0, l3, l2);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int32_t) l4.payload.i);
    t1 = l5.payload.obj;
    l3 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
    l7 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l4 = vader_vm_check_byte_range(l6, l1, l3, l2, l7);
    if (!(l4.tag == 1308u)) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes;
        l3 = ((int64_t) l4.payload.i);
        t2 = vader_vm_read_le(l8, l3, l1);
        { vader_box_t __vret = vader_box_i64(295u, (int64_t)(uint64_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_lookup_vtable_row(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    void* l6;
    int64_t l4, l5;
    void* t0;
    int32_t t1;
    if ((l1 < INT32_C(0))) {
        return INT32_C(-1);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l3 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) l6)->f_receiver_type_index;
        if (t1 == l2) {
            t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) l6)->f_fn_index;
            return t1;
        }
        l5 = (l5 + INT64_C(1));
    }
    return INT32_C(-1);
}

static void vader_vm_materialise(void* l0, int64_t l1, int64_t l2) {
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
    vader_obj_header_init(_a1_obj, 1298u);
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

static vader_box_t vader_vm_merge(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5) {
    void* l6 = NULL;
    int64_t l7, l8;
    vader_string_t l9 = 0;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    if ((t0 < INT64_C(0))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l4;
        vader_array_push_i64((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
    if (!(t0 != l4)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = (void*) vader_buffer_new((size_t) INT64_C(113));
    l7 = INT64_C(0);
    l7 = std_core_write_string_at(l6, l7, 2302u);
    l7 = std_core_write_int(l6, l7, l3);
    l7 = std_core_write_string_at(l6, l7, 178u);
    l7 = std_core_write_int(l6, l7, l4);
    l7 = std_core_write_string_at(l6, l7, 173u);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l8 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    l7 = std_core_write_int(l6, l7, l8);
    l9 = std_core_finish_buffer(l6, l7);
    t1 = vader_vm_defect(l0, l5, l9);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_merge_block(void* l0, int64_t l1, int64_t l2, void* l3) {
    int64_t l4, l6, l7, l9, l14;
    bool l5;
    void* l8 = NULL;
    void* l13 = NULL;
    uint8_t l10, l11, l12;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l3, &l8, &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_width;
    l4 = vader_chk_mul(i64, l1, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l5 = (t0 < INT64_C(0));
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l2;
    l6 = INT64_C(0);
    l7 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_width;
    while ((l6 < l7)) {
        l8 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry;
        l9 = vader_chk_add(i64, l4, l6);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 292u);
        l10 = ((uint8_t) t1.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 292u);
        l11 = ((uint8_t) t1.payload.i);
        t2 = (l10 | l11);
        l12 = (uint8_t) (int32_t) t2;
        if (l12 != l10) {
            l13 = ((vader_struct_vader_vm_Blocks_t*) l0)->f_entry;
            l14 = vader_chk_add(i64, l4, l6);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l14] = (uint8_t) (int32_t) (uint8_t) l12;
            l5 = true;
        }
        l6 = (l6 + INT64_C(1));
    }
    if (l5) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = vader_box_bool(285u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1]);
        t3 = t1.payload.b;
        if (t3) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (uint8_t) true;
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l0)->f_work, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_mirrored_struct_fields(void* l0, void* l1, int64_t l2) {
    int64_t l3, l5;
    int32_t l4;
    vader_box_t l6;
    void* t0;
    vader_string_t t1;
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
    l3 = ((int64_t) (int32_t) l4);
    l5 = ((vader_array_t*) l0)->length;
    if ((l3 >= l5)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    if (!(l6.tag == 653u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l6.payload.obj;
    t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
    if (!(t1 == 0u)) {
        t0 = l6.payload.obj;
        return vader_ref_box(((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields);
    }
    return vader_box_obj(0u, NULL);
}

static void vader_vm_move_register(void* l0, int64_t l1, int64_t l2) {
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
    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 292u);
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
    if (l0 == INT32_C(4)) {
        l1 = INT32_C(0);
        return l1;
    }
    if (l0 == INT32_C(0)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(5)) {
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
            l2 = l0 == INT32_C(6);
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
    t0 = vader_bytecode_is_narrow_valtype(l1);
    if (!(t0)) {
        return l0;
    }
    if (l1 == INT32_C(4)) {
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
    if (l0.tag == 290u) {
        t1 = ((int32_t) l0.payload.i);
        l4 = ((int64_t) (int32_t) t1);
    } else {
        if (!(l0.tag == 291u)) {
            return l0;
        }
        l4 = ((int64_t) l0.payload.i);
    }
    if (l1 == INT32_C(0)) {
        l3 = true;
        t1 = vader_vm_truncate_to_width(l4, l2, l3);
        return vader_box_i32(290u, t1);
    }
    l3 = l1 == INT32_C(1);
    t1 = vader_vm_truncate_to_width(l4, l2, l3);
    return vader_box_i32(290u, t1);
}

static void vader_vm_narrow_register(void* l0, int64_t l1, int32_t l2) {
    int64_t l3, l5;
    void* l4;
    bool l6;
    vader_box_t t0;
    int32_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
    if (((int32_t) t0.payload.i) != INT32_C(0)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
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

static void* vader_vm_new_blocks(void* l0, void* l1, int64_t l2) {
    int64_t l3, l5, l11;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    bool l9;
    int32_t l10;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l8, &t3 };
    void** gc_raw_roots[9] = { &l0, &l1, &l4, &l6, &l12, &l13, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 12u, 285u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) true;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l8 = vader_vm_effect_of(l0, l1, l7);
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
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
            t1 = vader_vm_in_range(l10, l3);
            if (t1) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10] = (uint8_t) true;
            }
        }
        if (((vader_struct_vader_vm_StackEffect_t*) l6)->f_flow != INT32_C(0)) {
            t2 = vader_chk_add(i64, l5, INT64_C(1));
            if ((t2 < l3)) {
                l11 = vader_chk_add(i64, l5, INT64_C(1));
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11] = (uint8_t) true;
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 8u, 291u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l12 = (void*) _a9_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t3 = vader_box_bool(285u, ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5]);
        t1 = t3.payload.b;
        if (t1) {
            l11 = ((vader_array_t*) l6)->length;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
            ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5] = (int64_t) l11;
            vader_array_push_i64((vader_array_t*) l6, l5);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a12_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = (int64_t) INT64_C(-1);
    l4 = (void*) _a12_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l3);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l13 = (void*) _a14_arr;
    t2 = ((vader_array_t*) l6)->length;
    l3 = vader_chk_mul(i64, t2, l2);
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l3);
    l13 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(16u, 0u, 8u, 291u);
    l14 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(12u, 1u, 12u, 285u);
    ((uint8_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (uint8_t) false;
    l15 = (void*) _a17_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l3);
    l15 = (void*) _a18_arr;
    vader_struct_vader_vm_Blocks_t* _a19_obj = (vader_struct_vader_vm_Blocks_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Blocks_t));
    vader_obj_header_init(_a19_obj, 1281u);
    _a19_obj->f_width = l2;
    _a19_obj->f_leaders = l6;
    _a19_obj->f_block_at = l12;
    _a19_obj->f_entry_depth = l4;
    _a19_obj->f_entry = l13;
    _a19_obj->f_work = l14;
    _a19_obj->f_queued = l15;
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
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int64_t) INT64_C(0);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 1u, 7u, 290u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    l2 = (void*) _a2_arr;
    vader_struct_vader_vm_RunHost_t* _a3_obj = (vader_struct_vader_vm_RunHost_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RunHost_t));
    vader_obj_header_init(_a3_obj, 1302u);
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
    int64_t l2, l3;
    int32_t l5;
    uint8_t l6;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_box_t l11 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l7, &l8, &l13, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l10, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 1u, 292u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
        l5 = ((int32_t) (int64_t) l2);
        l6 = vader_vm_type_tags(l4, l5, INT32_C(0));
        vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l6);
        l2 = (l2 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 0u, 287u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 298u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 290u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a5_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a5_obj, 451u);
    _a5_obj->f_ekeys = l4;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a5_obj;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    l2 = ((vader_array_t*) l7)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l3);
        l9 = ((vader_struct_vader_bytecode_VtableRow_t*) l8)->f_key;
        t0 = std_collections_MutableMap_std_core_Contains_contains__string__Any(l4, l9);
        if (!(t0)) {
            l10 = ((vader_struct_vader_bytecode_VtableRow_t*) l8)->f_key;
            l11 = vader_vm_virtual_signature(l0, l10);
            if (!(l11.tag == 0u)) {
                l12 = ((vader_struct_vader_bytecode_VtableRow_t*) l8)->f_key;
                t1 = l11.payload.obj;
                l13 = ((vader_struct_vader_bytecode_BcSignature_t*) t1)->f_results;
                std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l4, l12, vader_ref_box(l13));
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    vader_struct_vader_vm_TagContext_t* _a7_obj = (vader_struct_vader_vm_TagContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_TagContext_t));
    vader_obj_header_init(_a7_obj, 1306u);
    _a7_obj->f_module = l0;
    _a7_obj->f_type_tags = l1;
    _a7_obj->f_virtual_results = l4;
    t1 = (void*) _a7_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_note_checked_kind(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3;
    uint8_t l4;
    int64_t t0;
    if ((l1.tag == 679u || l1.tag == 680u)) {
        l2 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_kinds)->length;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        l4 = VADER_UNION_FIELD(uint8_t, vader_struct_vader_bytecode_CheckedArith_t, f_kind, l1.payload.obj);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l4;
        return;
    }
    return;
}

static bool vader_vm_one_argument_string_op(void* l0, int64_t l1, int32_t l2) {
    int32_t l3, l4;
    int64_t l5;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm_operand(l0, INT64_C(1));
    l4 = vader_vm_pop_to(l0, INT64_C(1));
    vader_vm_emit(l0, l1, l2, l4, l3, INT32_C(0));
    vader_vm_push_register(l0, l4);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_ops)->length;
    l5 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm_Translation_t*) l0)->f_retarget = l5;
    { vader_gc_top = gc_frame.prev; return true; }
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
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 531u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_bytecode_write_op(l1, l0);
    t1 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_operand(void* l0, int64_t l1) {
    void* l2;
    int64_t l3;
    int64_t t0;
    void* t1;
    int32_t t2;
    l2 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    l3 = vader_chk_sub(i64, t0, l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t2 = ((vader_struct_vader_vm_Pending_t*) t1)->f_register_v;
    return t2;
}

static int32_t vader_vm_operand_a(int64_t l0) {
    int64_t l1, l2;
    l1 = INT64_C(42);
    l1 = (l0 << (l1 & 63));
    l2 = INT64_C(42);
    return ((int32_t) (int64_t) (l1 >> (l2 & 63)));
}

static int32_t vader_vm_operand_b(int64_t l0) {
    int64_t l1, l2;
    l1 = (l0 << INT64_C(21));
    l2 = INT64_C(43);
    return ((int32_t) (int64_t) (l1 >> (l2 & 63)));
}

static int32_t vader_vm_operand_c(int64_t l0) {
    int64_t l1;
    l1 = INT64_C(43);
    return ((int32_t) (int64_t) (l0 >> (l1 & 63)));
}

static int32_t vader_vm_operand_of(void* l0, int64_t l1, int64_t l2) {
    void* l3;
    int64_t l4;
    int64_t t0;
    int32_t t1;
    l3 = ((vader_struct_vader_vm_Translation_t*) l0)->f_operands;
    t0 = vader_chk_mul(i64, INT64_C(3), l1);
    l4 = vader_chk_add(i64, t0, l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    return t1;
}

static bool vader_vm_operands_within(void* l0, int64_t l1, uint8_t l2) {
    uint8_t t0;
    bool t1;
    t0 = vader_vm_stack_tags(l0, l1, INT64_C(1));
    t1 = vader_vm_tags_within(t0, l2);
    if (t1) {
        t0 = vader_vm_stack_tags(l0, l1, INT64_C(2));
        t1 = vader_vm_tags_within(t0, l2);
        return t1;
    }
    return false;
}

static void* vader_vm_overflow_trap(vader_string_t l0) {
    vader_string_t l1 = 0;
    int64_t l2;
    void* l3 = NULL;
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
    l3 = (void*) vader_buffer_new((size_t) (INT64_C(65) + l2));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l3, l2, 1550u);
    l2 = std_core_write_int(l3, l2, INT64_C(1024));
    l2 = std_core_write_string_at(l3, l2, 275u);
    l2 = std_core_write_string_at(l3, l2, l1);
    l2 = std_core_write_string_at(l3, l2, 234u);
    t0 = std_core_finish_buffer(l3, l2);
    vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a0_obj, 1308u);
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
    l5 = (l5 << (l6 & 63));
    return vader_box_i64(291u, (l4 | l5));
}

static vader_string_t vader_vm_param_display_name(void* l0, int64_t l1) {
    int64_t l2;
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
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
    l3 = (void*) vader_buffer_new((size_t) INT64_C(23));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l3, l2, 1401u);
    l2 = std_core_write_int(l3, l2, l1);
    t1 = std_core_finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_pause_context(void* l0, void* l1, vader_string_t l2, int64_t l3, int64_t l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    int64_t l6, l8, l9, l11, l13, l14, l16, l17, l18;
    vader_box_t l19 = vader_box_null();
    int32_t l22, l24;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l19 };
    void** gc_raw_roots[12] = { &l0, &l1, &l5, &l7, &l10, &l12, &l15, &l20, &l21, &l23, &l25, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(208u, 0u, 13u, 1296u);
    l5 = (void*) _a0_arr;
    l6 = l4;
    while ((l6 > INT64_C(0))) {
        l6 = vader_chk_sub(i64, l6, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = vader_chk_sub(i64, l4, INT64_C(1));
        if (l6 == l9) {
            l8 = l3;
        } else {
            l10 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_frame_return;
            l11 = vader_chk_add(i64, l6, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
            l8 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l11];
        }
        vader_array_t* _a3_arr = vader_array_new(247u, 0u, 0u, 1949u);
        l12 = (void*) _a3_arr;
        l14 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_slots;
        if ((INT64_C(0) < l14)) {
            l13 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_slots;
        } else {
            l13 = INT64_C(0);
        }
        vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l12, (int64_t) l13);
        l15 = (void*) _a4_arr;
        l16 = INT64_C(0);
        l17 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_slots;
        while ((l16 < l17)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_frame_base);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            t0 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
            l18 = vader_chk_add(i64, t0, l16);
            l19 = vader_vm_register_value(l1, l18);
            vader_array_push((vader_array_t*) l15, l19);
            l16 = (l16 + INT64_C(1));
        }
        l20 = ((vader_struct_vader_vm_VmState_t*) l0)->f_bc;
        l21 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
        l22 = ((vader_struct_vader_vm_RegFunction_t*) l7)->f_index;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l21);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l22)
        l23 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l22);
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l7)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        l24 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l8];
        l25 = vader_vm_pause_frame(l20, l23, l15, l24);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l25));
    }
    vader_struct_vader_vm_PauseCtx_t* _a8_obj = (vader_struct_vader_vm_PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseCtx_t));
    vader_obj_header_init(_a8_obj, 1295u);
    _a8_obj->f_reason = l2;
    _a8_obj->f_frames = l5;
    t1 = (void*) _a8_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_pause_frame(void* l0, void* l1, void* l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    int32_t l5;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null();
    void* l10 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = 0u;
    l5 = INT32_C(0);
    if ((l3 >= INT32_C(0))) {
        l6 = ((int64_t) (int32_t) l3);
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_debug)->length;
        if ((l6 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            if (!(l8.tag == 0u)) {
                t0 = l8.payload.obj;
                l4 = ((vader_struct_vader_bytecode_DebugPos_t*) t0)->f_file;
                t0 = l8.payload.obj;
                l5 = ((vader_struct_vader_bytecode_DebugPos_t*) t0)->f_line;
            }
        }
    }
    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_name;
    l10 = vader_vm_project_locals(l2, l3, l1, l0);
    vader_struct_vader_vm_PauseFrame_t* _a1_obj = (vader_struct_vader_vm_PauseFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseFrame_t));
    vader_obj_header_init(_a1_obj, 1296u);
    _a1_obj->f_function_name = l9;
    _a1_obj->f_file = l4;
    _a1_obj->f_line = l5;
    _a1_obj->f_locals = l10;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_peek_array_mut(void* l0, int64_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    int64_t l7, l8;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l9, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l5, &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l4.tag == 1280u) {
            t1 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = l3;
    t0 = vader_vm_peek_val(l0, l1);
    l6 = vader_vm_describe_value_tag(t0);
    l7 = vader_host_std_core_byte_len(l5);
    l8 = vader_host_std_core_byte_len(l6);
    l7 = (l7 + l8);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l7));
    l7 = INT64_C(0);
    l7 = std_core_write_string_at(l9, l7, l5);
    l7 = std_core_write_string_at(l9, l7, 66u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core_write_int(l9, l7, l8);
    l7 = std_core_write_string_at(l9, l7, 408u);
    l7 = std_core_write_string_at(l9, l7, l6);
    t2 = std_core_finish_buffer(l9, l7);
    vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a2_obj, 1308u);
    _a2_obj->f_message = t2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_peek_owned(void* l0, int64_t l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    uint32_t l4;
    bool l5;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
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
        l3 = vader_box_i32(290u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(291u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(297u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(285u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        t1 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1];
        t2 = ((int32_t) (int64_t) t1);
        l4 = (uint32_t) (int32_t) t2;
        if ((l4 > INT32_C(55295))) {
            if ((l4 < INT32_C(57344))) {
                l5 = true;
            } else {
                l5 = (l4 > INT32_C(1114111));
            }
            if (l5) {
                vader_unreachable("value out of range: no Unicode scalar value");
            }
        }
        l3 = vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l4));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm_NullVal_t* _a7_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
        vader_obj_header_init(_a7_obj, 1292u);
        t3 = (void*) _a7_obj;
        l3 = vader_ref_box(t3);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_peek_val(void* l0, int64_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
    if (((int32_t) t0.payload.i) == INT32_C(5)) {
        t1 = (void*) &vader_data_51;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm_peek_owned(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_pop_to(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    int32_t t1;
    l2 = INT64_C(0);
    while ((l2 < l1)) {
        t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
        l2 = (l2 + INT64_C(1));
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    t1 = vader_vm_canonical(l0, l2);
    return t1;
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
    if (l2.tag == 1312u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm_prepare_module(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_prepare_module(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int64_t l5, l7;
    uint8_t l9;
    vader_string_t l10 = 0;
    int32_t l11, l13, l14, l15;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[7] = { &l0, &l3, &l4, &l6, &l8, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_vm_verify_module(l0);
    if (l2.tag == 1311u) {
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
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 1u, 292u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
    l5 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_is_extern;
        if (t1) {
            vader_array_push_u8((vader_array_t*) l4, INT32_C(0));
        } else {
            t2 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_mangled_name;
            l9 = vader_bytecode_intrinsic_id_for(t2);
            vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l9);
        }
        l7 = (l7 + INT64_C(1));
    }
    l2 = vader_vm_translate_module(l0, l4, l3, l1);
    if (l2.tag == 1311u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 0u, 287u);
    l3 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 290u);
    l8 = (void*) _a5_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a6_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a6_obj, 457u);
    _a6_obj->f_ekeys = l3;
    _a6_obj->f_evals = l6;
    _a6_obj->f_index = l8;
    _a6_obj->f_mask = INT64_C(0);
    _a6_obj->f_size = INT64_C(0);
    _a6_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a6_obj;
    l5 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l5 < l7)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l10 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
        l11 = ((int32_t) (int64_t) l5);
        std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l3, l10, l11);
        l5 = (l5 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool;
    l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types;
    l12 = vader_bytecode_data_pool_type_ids(l0);
    l6 = vader_vm_reduce_data_pool(l6, l8, l12);
    l8 = vader_vm_initial_globals(l0);
    l11 = vader_vm_reduce_main_index(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l13 = vader_vm_find_string_array_type_id(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l14 = vader_vm_find_u8_array_type_id(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l15 = vader_vm_find_io_error_type_id(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l12 = l2.payload.obj;
    vader_struct_vader_vm_VmState_t* _a8_obj = (vader_struct_vader_vm_VmState_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VmState_t));
    vader_obj_header_init(_a8_obj, 1312u);
    _a8_obj->f_bc = l0;
    _a8_obj->f_data_pool = l6;
    _a8_obj->f_globals = l8;
    _a8_obj->f_main_index = l11;
    _a8_obj->f_string_array_type_id = l13;
    _a8_obj->f_u8_array_type_id = l14;
    _a8_obj->f_io_error_type_id = l15;
    _a8_obj->f_fn_index_by_name = l3;
    _a8_obj->f_import_ids = l4;
    _a8_obj->f_reg = l12;
    _a8_obj->f_debuggable = l1;
    t0 = (void*) _a8_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_primitive_impl_import(vader_string_t l0, int64_t l1) {
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
    vader_array_t* _a0_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(17);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(17);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 1u, 7u, 290u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 0u, 287u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(12u, 0u, 12u, 285u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(12u, 0u, 12u, 285u);
    l8 = (void*) _a7_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a8_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a8_obj, 651u);
    _a8_obj->f_params = l2;
    _a8_obj->f_results = l3;
    _a8_obj->f_param_types = l4;
    _a8_obj->f_result_types = l5;
    _a8_obj->f_param_names = l6;
    _a8_obj->f_param_c_out = l7;
    _a8_obj->f_param_by_address = l8;
    l2 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(14u, 0u, 0u, 287u);
    l3 = (void*) _a9_arr;
    vader_struct_vader_bytecode_BcImport_t* _a10_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
    vader_obj_header_init(_a10_obj, 645u);
    _a10_obj->f_extern_name = 0u;
    _a10_obj->f_mangled_name = l0;
    _a10_obj->f_signature = l2;
    _a10_obj->f_is_extern = false;
    _a10_obj->f_c_header = 0u;
    _a10_obj->f_c_library = 0u;
    _a10_obj->f_c_variadic_fixed = INT32_C(-1);
    _a10_obj->f_param_c_types = l3;
    _a10_obj->f_result_c_type = 0u;
    t0 = (void*) _a10_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm_primitive_kind_at(void* l0, int32_t l1) {
    bool l2;
    int64_t l3, l4;
    vader_box_t l5;
    void* t0;
    vader_string_t t1;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        l3 = ((int64_t) (int32_t) l1);
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        return 0u;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l5.tag == 650u)) {
        return 0u;
    }
    t0 = l5.payload.obj;
    t1 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val);
    return t1;
}

static int32_t vader_vm_primitive_type_id(void* l0, vader_box_t l1) {
    vader_string_t l2;
    int64_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_string_t t1;
    l2 = vader_vm_describe_value_tag(l1);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = l5;
        if (l5.tag == 650u) {
            t0 = l6.payload.obj;
            t1 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val);
            if (t1 == l2) {
                return ((int32_t) (int64_t) l3);
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return INT32_C(-1);
}

static void* vader_vm_project_locals(void* l0, int32_t l1, void* l2, void* l3) {
    int64_t l4, l5, l8, l9, l17;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    int32_t l10, l11, l12;
    vader_string_t l14 = 0;
    vader_box_t l15 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l15, &t1 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l6, &l7, &l13, &l16, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals)->length;
    l5 = vader_chk_add(i64, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 290u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 1u, 7u, 290u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l7 = (void*) _a3_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
    while ((l8 < l9)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
        l10 = vader_vm_slot_touched_by(t1);
        if ((l10 >= INT32_C(0))) {
            if ((((int64_t) (int32_t) l10) < l5)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                t2 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10];
                if ((t2 < INT32_C(0))) {
                    l11 = ((int32_t) (int64_t) l8);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
                    ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10] = (int32_t) l11;
                }
                l12 = ((int32_t) (int64_t) l8);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
                ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l10] = (int32_t) l12;
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(209u, 0u, 13u, 1297u);
    l13 = (void*) _a8_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l8 = ((vader_array_t*) l0)->length;
        if ((l5 < l8)) {
            l14 = vader_vm_param_display_name(((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature, l5);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l15 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
            l16 = vader_vm_project_var(l14, l15, l3, INT32_C(0));
            vader_array_push((vader_array_t*) l13, vader_ref_box(l16));
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals)->length;
    while ((l5 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
        l14 = ((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_name;
        l9 = vader_chk_add(i64, l4, l5);
        l17 = ((vader_array_t*) l0)->length;
        if ((l9 < l17)) {
            t3 = vader_vm_is_source_local(l14);
            if (t3) {
                t3 = vader_vm_slot_in_scope(l6, l7, l9, l1);
                if (t3) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                    l15 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l9];
                    l16 = vader_vm_project_var(l14, l15, l3, INT32_C(0));
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l16));
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_project_struct_fields(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    int32_t l5;
    int64_t l6, l9, l11, l12;
    vader_box_t l8 = vader_box_null();
    vader_string_t l10 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l7, &l13, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(209u, 0u, 13u, 1297u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 0u, 287u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_vm_StructVal_t*) l0)->f_type_id;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_types)->length;
    t0 = vader_vm_in_range(l5, l6);
    if (t0) {
        l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l1)->f_types;
        l5 = ((vader_struct_vader_vm_StructVal_t*) l0)->f_type_id;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (l8.tag == 653u) {
            t1 = l8.payload.obj;
            l7 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
            l6 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l6)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                l10 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
                vader_array_push((vader_array_t*) l4, vader_box_string(287u, l10));
                l9 = (l9 + INT64_C(1));
            }
        }
    }
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields)->length;
    while ((l6 < l9)) {
        l11 = ((vader_array_t*) l4)->length;
        if ((l6 < l11)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
            l10 = t2.payload.s;
        } else {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(25));
            l12 = INT64_C(0);
            l12 = std_core_write_string_at(l7, l12, 1804u);
            l12 = std_core_write_int(l7, l12, l6);
            l10 = std_core_finish_buffer(l7, l12);
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l8 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l6];
        l5 = vader_chk_add(i32, l2, INT32_C(1));
        l13 = vader_vm_project_var(l10, l8, l1, l5);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l13));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_project_var(vader_string_t l0, vader_box_t l1, void* l2, int32_t l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    int64_t l5, l6, l8, l11;
    vader_string_t l9 = 0;
    vader_box_t l12 = vader_box_null();
    int32_t l13;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l12 };
    void** gc_raw_roots[6] = { &l2, &l4, &l7, &l10, &l14, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(209u, 0u, 13u, 1297u);
    l4 = (void*) _a0_arr;
    if ((l3 < INT32_C(5))) {
        if (l1.tag == 1280u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            if ((t1 > INT64_C(64))) {
                l5 = INT64_C(64);
            } else {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_length;
            }
            l6 = INT64_C(0);
            while ((l6 < l5)) {
                l7 = (void*) vader_buffer_new((size_t) INT64_C(22));
                l8 = INT64_C(0);
                l8 = std_core_write_string_at(l7, l8, 847u);
                l8 = std_core_write_int(l7, l8, l6);
                l8 = std_core_write_string_at(l7, l8, 850u);
                l9 = std_core_finish_buffer(l7, l8);
                l10 = l1.payload.obj;
                t0 = l1.payload.obj;
                t1 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_offset;
                l11 = vader_chk_add(i64, t1, l6);
                l12 = vader_vm_element_at(l10, l11);
                l13 = vader_chk_add(i32, l3, INT32_C(1));
                l14 = vader_vm_project_var(l9, l12, l2, l13);
                vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
                l6 = (l6 + INT64_C(1));
            }
        } else if (l1.tag == 1305u) {
            t0 = l1.payload.obj;
            l4 = vader_vm_project_struct_fields(t0, l2, l3);
        }
        l9 = vader_vm_display_value(l1);
        vader_struct_vader_vm_PauseVar_t* _a1_obj = (vader_struct_vader_vm_PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseVar_t));
        vader_obj_header_init(_a1_obj, 1297u);
        _a1_obj->f_name = l0;
        _a1_obj->f_value = l9;
        _a1_obj->f_children = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm_display_value(l1);
    vader_struct_vader_vm_PauseVar_t* _a2_obj = (vader_struct_vader_vm_PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_PauseVar_t));
    vader_obj_header_init(_a2_obj, 1297u);
    _a2_obj->f_name = l0;
    _a2_obj->f_value = l9;
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
    int32_t l7;
    int64_t t0, t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm_scalar_of(l1);
    if (l3.tag == 0u) {
        vader_host_std_abort_panic(2314u);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        l4 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_consts;
        l5 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_const_tags;
        l6 = vader_vm_constant_index(l4, l5, l2);
        if (!((l6 < INT64_C(0)))) {
            l2 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
            t0 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_slots;
            t1 = vader_chk_add(i64, t0, l6);
            l7 = ((int32_t) (int64_t) t1);
            vader_struct_vader_vm_Pending_t* _a0_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
            vader_obj_header_init(_a0_obj, 1298u);
            _a0_obj->f_kind = (uint8_t) 2;
            _a0_obj->f_register_v = l7;
            l4 = (void*) _a0_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_host_std_abort_panic(2315u);
        vader_unreachable("a no-return call returned");
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_vm_push_little_endian(void* l0, int64_t l1, int64_t l2) {
    int64_t l3, l4;
    uint8_t l5;
    int32_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        l4 = vader_chk_mul(i64, l3, INT64_C(8));
        t0 = (((int32_t) (int64_t) ((l1 >> (l4 & 63)) & INT64_C(255))) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l0, (int32_t) (uint8_t) l5);
        l3 = (l3 + INT64_C(1));
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
    vader_obj_header_init(_a0_obj, 1298u);
    _a0_obj->f_kind = (uint8_t) 0;
    _a0_obj->f_register_v = l1;
    l3 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_push_val(void* l0, int64_t l1, vader_box_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t t0;
    double t1;
    bool t2;
    uint32_t t3;
    if (l2.tag == 290u) {
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
    if (l2.tag == 291u) {
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
    } else if ((l2.tag == 296u || l2.tag == 297u)) {
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
    } else if (l2.tag == 285u) {
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
    } else if (l2.tag == 286u) {
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
    } else if (l2.tag == 1292u) {
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
    uint8_t l4, l6;
    int32_t l5, l7;
    void* l8;
    vader_box_t l9;
    void* t0;
    vader_box_t t1;
    int32_t t2;
    if ((l1.tag == 630u || l1.tag == 691u || l1.tag == 709u || l1.tag == 710u || l1.tag == 711u || l1.tag == 712u || l1.tag == 713u || l1.tag == 714u || l1.tag == 715u || l1.tag == 721u || l1.tag == 722u || l1.tag == 724u || l1.tag == 725u || l1.tag == 726u || l1.tag == 727u || l1.tag == 728u || l1.tag == 752u || l1.tag == 757u || l1.tag == 782u || l1.tag == 791u || l1.tag == 796u)) {
        l4 = (uint8_t) 1;
        return l4;
    }
    if ((l1.tag == 704u || l1.tag == 729u || l1.tag == 730u || l1.tag == 731u || l1.tag == 732u || l1.tag == 733u || l1.tag == 734u || l1.tag == 735u || l1.tag == 741u || l1.tag == 742u || l1.tag == 744u || l1.tag == 745u || l1.tag == 746u || l1.tag == 747u || l1.tag == 748u || l1.tag == 753u || l1.tag == 773u || l1.tag == 797u || l1.tag == 802u)) {
        l4 = (uint8_t) 2;
    } else if ((l1.tag == 659u || l1.tag == 660u || l1.tag == 692u || l1.tag == 693u || l1.tag == 694u || l1.tag == 700u || l1.tag == 702u || l1.tag == 703u || l1.tag == 751u || l1.tag == 754u)) {
        l4 = (uint8_t) 4;
    } else if ((l1.tag == 662u || l1.tag == 663u || l1.tag == 664u || l1.tag == 665u || l1.tag == 666u || l1.tag == 667u || l1.tag == 695u || l1.tag == 696u || l1.tag == 697u || l1.tag == 698u || l1.tag == 699u || l1.tag == 701u || l1.tag == 716u || l1.tag == 717u || l1.tag == 718u || l1.tag == 719u || l1.tag == 720u || l1.tag == 723u || l1.tag == 736u || l1.tag == 737u || l1.tag == 738u || l1.tag == 739u || l1.tag == 740u || l1.tag == 743u || l1.tag == 768u || l1.tag == 769u || l1.tag == 784u || l1.tag == 785u || l1.tag == 789u || l1.tag == 792u || l1.tag == 793u || l1.tag == 794u || l1.tag == 795u || l1.tag == 798u || l1.tag == 799u || l1.tag == 800u || l1.tag == 801u)) {
        l4 = (uint8_t) 8;
    } else if (l1.tag == 678u) {
        l4 = (uint8_t) 16;
    } else if (l1.tag == 765u) {
        l4 = (uint8_t) 32;
    } else if ((l1.tag == 679u || l1.tag == 680u)) {
        l4 = vader_vm_integer_tags(VADER_UNION_FIELD(uint8_t, vader_struct_vader_bytecode_CheckedArith_t, f_kind, l1.payload.obj));
    } else if ((l1.tag == 631u || l1.tag == 635u || l1.tag == 637u || l1.tag == 670u || l1.tag == 671u || l1.tag == 682u || l1.tag == 705u || l1.tag == 706u || l1.tag == 763u || l1.tag == 783u || l1.tag == 787u || l1.tag == 790u)) {
        l4 = (uint8_t) 64;
    } else if (l1.tag == 759u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 292u);
        l4 = ((uint8_t) t1.payload.i);
    } else if ((l1.tag == 761u || l1.tag == 770u)) {
        l4 = l3;
    } else if (l1.tag == 767u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        l6 = vader_vm_tags_of_type(l0, l5);
        t2 = (l3 & l6);
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 681u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_target;
        if (l6 == INT32_C(0)) {
            l4 = (uint8_t) 1;
        } else if (l6 == INT32_C(1)) {
            l4 = (uint8_t) 2;
        } else if (l6 == INT32_C(2)) {
            l4 = (uint8_t) 4;
        } else {
            if (!(l6 == INT32_C(3))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l4 = (uint8_t) 16;
        }
    } else if ((l1.tag == 786u || l1.tag == 803u)) {
        l5 = VADER_UNION_FIELD(int32_t, vader_struct_vader_bytecode_StructGet_t, f_type_id, l1.payload.obj);
        l7 = VADER_UNION_FIELD(int32_t, vader_struct_vader_bytecode_StructGet_t, f_field_index, l1.payload.obj);
        l4 = vader_vm_field_tags(l0, l5, l7);
    } else if (l1.tag == 758u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
        l4 = vader_vm_field_tags(l0, l5, l7);
    } else if (l1.tag == 629u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        l4 = vader_vm_element_tags(l0, l5);
    } else if (l1.tag == 707u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
        l4 = vader_vm_global_tags(l0, l5);
    } else if (l1.tag == 634u) {
        l4 = (uint8_t) 127;
    } else if (l1.tag == 755u) {
        t2 = (INT32_C(1) | INT32_C(16));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 756u) {
        t2 = (INT32_C(2) | INT32_C(1));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 677u) {
        l8 = ((vader_struct_vader_vm_TagContext_t*) l0)->f_module;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        l9 = vader_vm_fn_type_of(l8, l5);
        if (l9.tag == 0u) {
            l4 = (uint8_t) 127;
        } else {
            t0 = l9.payload.obj;
            l5 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_return_type;
            l4 = vader_vm_tags_of_type(l0, l5);
        }
    } else {
        if (!((l1.tag == 627u || l1.tag == 628u || l1.tag == 632u || l1.tag == 633u || l1.tag == 636u || l1.tag == 661u || l1.tag == 668u || l1.tag == 669u || l1.tag == 672u || l1.tag == 675u || l1.tag == 676u || l1.tag == 684u || l1.tag == 685u || l1.tag == 686u || l1.tag == 687u || l1.tag == 690u || l1.tag == 708u || l1.tag == 749u || l1.tag == 760u || l1.tag == 762u || l1.tag == 764u || l1.tag == 771u || l1.tag == 772u || l1.tag == 775u || l1.tag == 776u || l1.tag == 777u || l1.tag == 778u || l1.tag == 779u || l1.tag == 780u || l1.tag == 781u || l1.tag == 788u || l1.tag == 804u || l1.tag == 805u || l1.tag == 806u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (uint8_t) 0;
    }
    return l4;
}

static vader_box_t vader_vm_read_array(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1280u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 408u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_read_back_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5) {
    void* l6 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l23 = NULL;
    int64_t l7, l8, l11, l12, l16, l20, l21, l22;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l17 = vader_box_null(), l24 = vader_box_null();
    int32_t l15;
    bool l19;
    void* t0 = NULL;
    uint8_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l9, &l10, &l17, &l24, &t3 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l4, &l6, &l13, &l14, &l18, &l23, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l5 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_bytecode_c_struct_layout(l3, l4);
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) l3)->length;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = vader_bytecode_nested_mirror(t0, l4);
        if (l9.tag == 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l17 = vader_bytecode_c_field_width(t0, l4);
            if (l17.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l16 = ((int64_t) l17.payload.i);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l18 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            t1 = vader_vm_field_val_type(l4, l18);
            t2 = vader_bytecode_is_unsigned_val(t1);
            l19 = !(t2);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l20 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            l21 = vader_chk_add(i64, l1, l20);
            l22 = vader_vm_read_little_endian(l0, l21, l16, l19);
            l23 = ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields;
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            t3 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
            l24 = vader_vm_retyped_int(t3, l22);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l23);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l7] = l24;
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l10 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l7];
        if (l10.tag == 1305u) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
            l11 = ((int64_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
            l12 = vader_chk_add(i64, l1, l11);
            l13 = l10.payload.obj;
            t0 = l9.payload.obj;
            l14 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
            l15 = vader_chk_add(i32, l5, INT32_C(1));
            vader_vm_read_back_mirror(l0, l12, l13, l14, l4, l15);
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_read_bool(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 285u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 409u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.b;
    { vader_box_t __vret = vader_box_bool(285u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_f64(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    double t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!((l0.tag == 296u || l0.tag == 297u))) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 410u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l0.payload.f);
    { vader_box_t __vret = vader_box_f64(297u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_fn(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1285u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 411u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_i32(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int64_t l6, l7;
    void* l8 = NULL;
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
    if (l0.tag == 290u) {
        t0 = ((int32_t) l0.payload.i);
        l3 = vader_box_i32(290u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 286u) {
        t1 = ((uint32_t) l0.payload.i);
        l3 = vader_box_i32(290u, ((int32_t) (uint32_t) t1));
    } else if (l0.tag == 291u) {
        t2 = ((int64_t) l0.payload.i);
        l3 = vader_box_i32(290u, ((int32_t) (int64_t) t2));
    } else {
        l4 = l2;
        l5 = vader_vm_describe_value_tag(l0);
        l6 = vader_host_std_core_byte_len(l4);
        l7 = vader_host_std_core_byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core_write_string_at(l8, l6, l4);
        l6 = std_core_write_string_at(l8, l6, 66u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core_write_int(l8, l6, l7);
        l6 = std_core_write_string_at(l8, l6, 412u);
        l6 = std_core_write_string_at(l8, l6, l5);
        t3 = std_core_finish_buffer(l8, l6);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
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
    int64_t l6, l7;
    void* l8 = NULL;
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
    if (l0.tag == 291u) {
        t0 = ((int64_t) l0.payload.i);
        l3 = vader_box_i64(291u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 290u) {
        t1 = ((int32_t) l0.payload.i);
        l3 = vader_box_i64(291u, ((int64_t) (int32_t) t1));
    } else {
        l4 = l2;
        l5 = vader_vm_describe_value_tag(l0);
        l6 = vader_host_std_core_byte_len(l4);
        l7 = vader_host_std_core_byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core_write_string_at(l8, l6, l4);
        l6 = std_core_write_string_at(l8, l6, 66u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core_write_int(l8, l6, l7);
        l6 = std_core_write_string_at(l8, l6, 413u);
        l6 = std_core_write_string_at(l8, l6, l5);
        t2 = std_core_finish_buffer(l8, l6);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t2;
        t3 = (void*) _a0_obj;
        l3 = vader_ref_box(t3);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_vm_read_le(void* l0, int64_t l1, int64_t l2) {
    uint64_t l3, l5, l7;
    int64_t l4, l6;
    int64_t t0, t1;
    vader_box_t t2;
    uint8_t t3;
    l3 = (uint64_t) 0;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        t0 = (l3 << INT64_C(8));
        l5 = (uint64_t) (int64_t) t0;
        t0 = vader_chk_add(i64, l1, l2);
        t1 = vader_chk_sub(i64, t0, INT64_C(1));
        l6 = vader_chk_sub(i64, t1, l4);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 292u);
        t3 = ((uint8_t) t2.payload.i);
        t0 = ((int64_t) (uint8_t) t3);
        l7 = (uint64_t) (int64_t) t0;
        t0 = (l5 | l7);
        l3 = (uint64_t) (int64_t) t0;
        l4 = (l4 + INT64_C(1));
    }
    return l3;
}

static int64_t vader_vm_read_little_endian(void* l0, int64_t l1, int64_t l2, bool l3) {
    int64_t l4, l5, l6, l7, l8, l9;
    vader_box_t t0;
    uint8_t t1;
    int64_t t2;
    l4 = INT64_C(0);
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        l6 = vader_chk_add(i64, l1, l5);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 292u);
        t1 = ((uint8_t) t0.payload.i);
        l7 = ((int64_t) (uint8_t) t1);
        l8 = vader_chk_mul(i64, l5, INT64_C(8));
        l9 = (l7 << (l8 & 63));
        l4 = (l4 | l9);
        l5 = (l5 + INT64_C(1));
    }
    if (l3) {
        if ((l2 < INT64_C(8))) {
            t2 = vader_chk_mul(i64, l2, INT64_C(8));
            l5 = vader_chk_sub(i64, t2, INT64_C(1));
            l5 = (INT64_C(1) << (l5 & 63));
            if ((l4 & l5) != INT64_C(0)) {
                l5 = (l5 << INT64_C(1));
                l4 = vader_chk_sub(i64, l4, l5);
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
    int64_t l4, l6;
    void* l5 = NULL;
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
    if (l0.tag == 290u) {
        t0 = ((int32_t) l0.payload.i);
        l2 = vader_box_f64(297u, ((double) (int32_t) t0));
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 291u) {
        t1 = ((int64_t) l0.payload.i);
        l2 = vader_box_f64(297u, ((double) (int64_t) t1));
    } else if ((l0.tag == 296u || l0.tag == 297u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_f64(297u, t2);
    } else if (l0.tag == 286u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_f64(297u, ((double) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else {
        l3 = vader_vm_describe_value_tag(l0);
        l4 = vader_host_std_core_byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(55) + l4));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 1634u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 405u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 63u);
        t4 = std_core_finish_buffer(l5, l4);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t4;
        t5 = (void*) _a0_obj;
        l2 = vader_ref_box(t5);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_numeric_as_i64(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    int64_t l4, l6;
    void* l5 = NULL;
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
    if (l0.tag == 291u) {
        t0 = ((int64_t) l0.payload.i);
        l2 = vader_box_i64(291u, t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 290u) {
        t1 = ((int32_t) l0.payload.i);
        l2 = vader_box_i64(291u, ((int64_t) (int32_t) t1));
    } else if ((l0.tag == 296u || l0.tag == 297u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_i64(291u, ((int64_t) (double) t2));
    } else if (l0.tag == 286u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_i64(291u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else if (l0.tag == 285u) {
        t4 = l0.payload.b;
        if (t4) {
            l2 = vader_box_i64(291u, INT64_C(1));
        } else {
            l2 = vader_box_i64(291u, INT64_C(0));
        }
    } else {
        l3 = vader_vm_describe_value_tag(l0);
        l4 = vader_host_std_core_byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(59) + l4));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 1634u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 405u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 64u);
        t5 = std_core_finish_buffer(l5, l4);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t5;
        t6 = (void*) _a0_obj;
        l2 = vader_ref_box(t6);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_obj(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1293u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 415u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 285u) {
        t0 = l0.payload.b;
        if (t0) {
            { vader_box_t __vret = vader_box_i64(291u, INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i64(291u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 286u)) {
        t1 = vader_vm_read_i64(l0, l1, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((uint32_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(291u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t2))); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_string(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 287u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 416u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.s;
    { vader_box_t __vret = vader_box_string(287u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_struct(vader_box_t l0, int32_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1305u)) {
        l3 = l2;
        l4 = vader_vm_describe_value_tag(l0);
        l5 = vader_host_std_core_byte_len(l3);
        l6 = vader_host_std_core_byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core_write_string_at(l7, l5, l3);
        l5 = std_core_write_string_at(l7, l5, 66u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core_write_int(l7, l5, l6);
        l5 = std_core_write_string_at(l7, l5, 417u);
        l5 = std_core_write_string_at(l7, l5, l4);
        t0 = std_core_finish_buffer(l7, l5);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_read_struct_field(vader_box_t l0, int32_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    bool l6;
    int64_t l7, l8;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l4, &t0 };
    void** gc_raw_roots[2] = { &l9, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1305u)) {
        l4 = l0;
        l5 = concat_2(l3, 151u);
        t0 = vader_vm_read_struct(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1 < INT32_C(0))) {
        l6 = true;
    } else {
        l7 = ((int64_t) (int32_t) l1);
        t1 = l0.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields)->length;
        l6 = (l7 >= l8);
    }
    if (!(l6)) {
        t1 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l7 = vader_host_std_core_byte_len(l5);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(108) + l7));
    l7 = INT64_C(0);
    l7 = std_core_write_string_at(l9, l7, l5);
    l7 = std_core_write_string_at(l9, l7, 82u);
    l8 = ((int64_t) (int32_t) l1);
    l7 = std_core_write_int(l9, l7, l8);
    l7 = std_core_write_string_at(l9, l7, 140u);
    t1 = l0.payload.obj;
    l8 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields)->length;
    l7 = std_core_write_int(l9, l7, l8);
    l7 = std_core_write_string_at(l9, l7, 83u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core_write_int(l9, l7, l8);
    t2 = std_core_finish_buffer(l9, l7);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t2;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_receiver_trap(void* l0, int64_t l1, void* l2, int64_t l3, vader_string_t l4, vader_string_t l5) {
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t l8, l10;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l9, &t4 };
    vader_string_t* gc_atom_roots[6] = { &l4, &l5, &l6, &l7, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_vm_register_value(l0, l1);
    l6 = vader_vm_describe_value_tag(t0);
    l7 = l4;
    l8 = vader_host_std_core_byte_len(l7);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(36) + l8));
    l8 = INT64_C(0);
    l8 = std_core_write_string_at(l9, l8, l7);
    l8 = std_core_write_string_at(l9, l8, 152u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l10 = ((int64_t) (int32_t) t1);
    l8 = std_core_write_int(l9, l8, l10);
    t2 = std_core_finish_buffer(l9, l8);
    t3 = concat_5(t2, 407u, l5, 312u, l6);
    vader_struct_vader_vm_Trap_t* _a1_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
    vader_obj_header_init(_a1_obj, 1308u);
    _a1_obj->f_message = t3;
    t4 = (void*) _a1_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_receiver_type_id_of(void* l0, vader_box_t l1) {
    int32_t l2;
    vader_box_t l3;
    void* t0;
    if (l1.tag == 1305u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
        return l2;
    }
    if (l1.tag == 1280u) {
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
    int64_t l4, l5, l9, l10, l13, l14, l18, l19, l22;
    vader_box_t l6 = vader_box_null(), l16 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l11 = 0;
    uint64_t l15;
    int32_t l21;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l6, &l16, &l20, &t1 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l7, &l8, &l12, &l17, &l23, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(202u, 0u, 13u, 1280u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_array_t* _a3_arr = vader_array_new(247u, 0u, 0u, 1949u);
        l7 = (void*) _a3_arr;
        if (l6.tag == 652u) {
            t0 = l6.payload.obj;
            l8 = ((vader_struct_vader_bytecode_BcStrData_t*) t0)->f_values;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l10];
                l11 = t1.payload.s;
                vader_array_push((vader_array_t*) l7, vader_box_string(287u, l11));
                l10 = (l10 + INT64_C(1));
            }
        } else if (l6.tag == 648u) {
            t0 = l6.payload.obj;
            l12 = ((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_items;
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                l15 = (uint64_t) (int64_t) t2;
                t0 = l6.payload.obj;
                l16 = vader_vm_value_from_bits(((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_kind, l15);
                vader_array_push((vader_array_t*) l7, l16);
                l14 = (l14 + INT64_C(1));
            }
        } else if (l6.tag == 638u) {
            t0 = l6.payload.obj;
            l17 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_elements;
            l18 = ((vader_array_t*) l17)->length;
            l19 = INT64_C(0);
            while ((l19 < l18)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l19);
                l20 = vader_vm_bc_value_to_vm(t1, l1);
                vader_array_push((vader_array_t*) l7, l20);
                l19 = (l19 + INT64_C(1));
            }
        }
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
        l21 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
        l22 = ((vader_array_t*) l7)->length;
        vader_struct_vader_vm_ArrayVal_t* _a8_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
        vader_obj_header_init(_a8_obj, 1280u);
        _a8_obj->f_type_id = l21;
        _a8_obj->f_elements = l7;
        _a8_obj->f_offset = INT64_C(0);
        _a8_obj->f_length = l22;
        _a8_obj->f_raw = vader_box_obj(0u, NULL);
        l23 = (void*) _a8_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l23));
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm_reduce_main_index(void* l0) {
    int64_t l1, l2;
    void* t0;
    bool t1;
    l1 = INT64_C(0);
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        t1 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_is_main;
        if (t1) {
            return ((int32_t) (int64_t) l1);
        }
        l1 = (l1 + INT64_C(1));
    }
    return INT32_C(-1);
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
    l3 = vader_types_core_trait_key(535u);
    if (l2 == l3) {
        if (l1.tag == 1284u) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        if (l1.tag == 1305u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
            t1 = vader_vm_trait_implemented_by(l0, l2, l4);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l2 == 0u) {
        if (l1.tag == 1305u) {
            l5 = true;
            { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1.tag == 1280u) {
            l5 = true;
        } else if (l1.tag == 1285u) {
            l5 = true;
        } else {
            l5 = false;
        }
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1305u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
        t1 = vader_vm_trait_implemented_by(l0, l2, l4);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_vm_reg_call(void* l0, void* l1, void* l2, int32_t l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
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
    void* l595 = NULL;
    void* l597 = NULL;
    void* l604 = NULL;
    void* l611 = NULL;
    void* l614 = NULL;
    void* l650 = NULL;
    void* l656 = NULL;
    void* l659 = NULL;
    void* l714 = NULL;
    void* l734 = NULL;
    void* l747 = NULL;
    void* l749 = NULL;
    int64_t l9, l10, l11, l12, l13, l20, l21, l22, l23, l24, l25, l28, l29, l30, l31, l32, l55, l56, l63, l64, l114, l115, l124, l125, l193, l195, l196, l199, l201, l202, l205, l207, l208, l210, l212, l213, l216, l218, l220, l221, l224, l227, l229, l230, l233, l235, l236, l239, l241, l242, l245, l247, l248, l251, l253, l254, l260, l263, l264, l267, l269, l271, l272, l277, l279, l281, l282, l287, l290, l292, l296, l298, l302, l304, l308, l310, l314, l316, l320, l322, l434, l438, l442, l446, l448, l452, l455, l458, l461, l463, l466, l469, l472, l476, l480, l484, l488, l490, l498, l500, l505, l525, l527, l529, l531, l533, l535, l537, l539, l556, l559, l560, l563, l564, l569, l570, l576, l577, l579, l581, l582, l587, l588, l592, l594, l599, l600, l602, l603, l605, l606, l607, l608, l612, l613, l617, l618, l623, l624, l625, l626, l648, l649, l654, l655, l660, l661, l663, l664, l665, l669, l670, l672, l673, l675, l679, l681, l682, l684, l685, l686, l687, l688, l690, l695, l696, l697, l703, l704, l706, l707, l708, l709, l711, l715, l716, l717, l718, l719, l720, l721, l722, l723, l724, l725, l726, l727, l728, l729, l730, l731, l733, l735, l736, l740, l741, l742, l743, l744, l745, l746, l748, l750;
    int32_t l19, l34, l35, l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l57, l58, l59, l60, l61, l65, l66, l67, l68, l69, l70, l71, l72, l73, l74, l75, l76, l77, l78, l79, l80, l81, l82, l83, l84, l85, l86, l87, l88, l89, l90, l91, l92, l93, l94, l95, l96, l97, l98, l100, l101, l103, l104, l105, l106, l107, l108, l109, l110, l111, l112, l116, l117, l120, l121, l122, l126, l127, l130, l131, l132, l133, l134, l135, l137, l138, l139, l140, l141, l143, l144, l145, l146, l147, l149, l150, l151, l152, l153, l155, l156, l157, l158, l159, l161, l162, l163, l164, l165, l167, l168, l170, l173, l174, l176, l179, l180, l182, l185, l186, l188, l191, l192, l194, l197, l198, l200, l203, l204, l206, l209, l214, l215, l217, l222, l223, l225, l226, l228, l231, l232, l234, l237, l238, l240, l243, l244, l246, l249, l250, l252, l255, l256, l258, l261, l262, l265, l266, l268, l273, l274, l278, l283, l284, l288, l289, l291, l294, l295, l297, l300, l301, l303, l306, l307, l309, l312, l313, l315, l318, l319, l321, l324, l325, l327, l330, l331, l333, l336, l337, l339, l342, l343, l345, l348, l349, l351, l354, l355, l357, l360, l361, l363, l366, l367, l369, l372, l373, l375, l376, l378, l381, l382, l384, l387, l388, l390, l393, l394, l396, l399, l400, l402, l405, l406, l408, l411, l412, l414, l417, l418, l420, l423, l424, l426, l427, l428, l430, l431, l432, l436, l437, l440, l441, l444, l445, l447, l450, l451, l454, l457, l460, l462, l465, l468, l471, l474, l478, l482, l486, l489, l492, l493, l494, l495, l496, l497, l499, l501, l502, l503, l506, l507, l508, l509, l510, l511, l512, l513, l514, l515, l516, l517, l518, l519, l520, l521, l522, l523, l524, l526, l528, l530, l532, l534, l536, l538, l540, l542, l544, l546, l548, l550, l552, l554, l558, l561, l567, l568, l573, l574, l578, l580, l585, l591, l593, l598, l615, l620, l628, l630, l631, l632, l635, l636, l637, l638, l639, l641, l642, l643, l644, l645, l646, l652, l653, l666, l671, l677, l693, l694, l699, l700, l701, l739;
    uint8_t l26, l33, l475, l479, l483, l487, l689, l710, l732;
    vader_box_t l27 = vader_box_null(), l435 = vader_box_null(), l439 = vader_box_null(), l443 = vader_box_null(), l449 = vader_box_null(), l453 = vader_box_null(), l456 = vader_box_null(), l459 = vader_box_null(), l464 = vader_box_null(), l467 = vader_box_null(), l470 = vader_box_null(), l473 = vader_box_null(), l477 = vader_box_null(), l481 = vader_box_null(), l485 = vader_box_null(), l491 = vader_box_null(), l557 = vader_box_null(), l562 = vader_box_null(), l566 = vader_box_null(), l572 = vader_box_null(), l584 = vader_box_null(), l590 = vader_box_null(), l601 = vader_box_null(), l609 = vader_box_null(), l610 = vader_box_null(), l616 = vader_box_null(), l619 = vader_box_null(), l627 = vader_box_null(), l629 = vader_box_null(), l633 = vader_box_null(), l647 = vader_box_null(), l651 = vader_box_null(), l657 = vader_box_null(), l662 = vader_box_null(), l674 = vader_box_null(), l678 = vader_box_null(), l691 = vader_box_null(), l692 = vader_box_null(), l698 = vader_box_null(), l712 = vader_box_null(), l713 = vader_box_null();
    uint32_t l99, l102, l118, l119, l128, l129, l169, l171, l175, l177, l181, l183, l187, l189, l504, l541, l543, l545, l547;
    bool l136, l142, l148, l154, l160, l166, l172, l178, l184, l190, l293, l299, l305, l311, l317, l323, l329, l335, l341, l347, l380, l386, l392, l398, l404, l410, l413, l415, l416, l419, l421, l422, l425, l429, l433, l575, l586, l621, l622, l634, l640, l658, l667, l668, l676, l680, l683, l702, l705, l737, l738;
    uint64_t l257, l259, l275, l276, l285, l286, l326, l328, l332, l334, l338, l340, l344, l346, l549, l551, l553, l555;
    double l350, l352, l353, l356, l358, l359, l362, l364, l365, l368, l370, l371, l374, l377, l379, l383, l385, l389, l391, l395, l397, l401, l403, l407, l409;
    vader_string_t l565 = 0;
    vader_string_t l571 = 0;
    vader_string_t l583 = 0;
    vader_string_t l589 = 0;
    vader_string_t l596 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int32_t t2, t4;
    vader_box_t t3 = vader_box_null();
    uint32_t t5;
    int64_t t6, t7;
    uint64_t t8;
    double t9;
    uint8_t t10;
    bool t11;
    vader_box_t* gc_roots[42] = {
        &l27, &l435, &l439, &l443, &l449, &l453, &l456, &l459, &l464, &l467, &l470, &l473, &l477,
        &l481, &l485, &l491, &l557, &l562, &l566, &l572, &l584, &l590, &l601, &l609, &l610, &l616,
        &l619, &l627, &l629, &l633, &l647, &l651, &l657, &l662, &l674, &l678, &l691, &l692, &l698,
        &l712, &l713, &t3,
    };
    void** gc_raw_roots[30] = {
        &l0, &l1, &l2, &l8, &l14, &l15, &l16, &l17, &l18, &l54, &l62, &l113, &l123, &l211, &l219,
        &l270, &l280, &l595, &l597, &l604, &l611, &l614, &l650, &l656, &l659, &l714, &l734, &l747,
        &l749, &t1,
    };
    vader_string_t* gc_atom_roots[6] = { &l565, &l571, &l583, &l589, &l596, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 42u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l9 = ((int64_t) 1024);
    if ((l5 >= l9)) {
        t0 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_name;
        t1 = vader_vm_overflow_trap(t0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_return);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (int64_t) l6;
    } else {
        vader_vm_grow_frame_records(l2, l8, l4, l6);
    }
    if (l7) {
        l9 = INT64_C(100000000);
    } else {
        l9 = INT64_C(4611686018427387904);
    }
    l10 = INT64_C(0);
    l11 = vader_chk_add(i64, l5, INT64_C(1));
    l12 = l4;
    l13 = INT64_C(0);
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
            t2 = vader_vm_operand_a(l20);
            l21 = ((int64_t) (int32_t) t2);
            l22 = vader_chk_add(i64, l12, l21);
            t2 = vader_vm_operand_b(l20);
            l23 = ((int64_t) (int32_t) t2);
            l24 = vader_chk_add(i64, l12, l23);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l24)
            l25 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l24];
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l22)
            ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l22] = (int64_t) l25;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l24)
            t3 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l24, 292u);
            l26 = ((uint8_t) t3.payload.i);
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
            t2 = vader_vm_operand_a(l20);
            l28 = ((int64_t) (int32_t) t2);
            l29 = vader_chk_add(i64, l12, l28);
            t2 = vader_vm_operand_b(l20);
            l30 = ((int64_t) (int32_t) t2);
            l31 = vader_chk_add(i64, l12, l30);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l31)
            l32 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l31];
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l29)
            ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l29] = (int64_t) l32;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l31)
            t3 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l31, 292u);
            l33 = ((uint8_t) t3.payload.i);
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
                l54 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l55 = INT64_C(0);
                l55 = std_core_write_string_at(l54, l55, 1910u);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
                t2 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l13];
                l56 = ((int64_t) (int32_t) t2);
                l55 = std_core_write_int(l54, l55, l56);
                t0 = std_core_finish_buffer(l54, l55);
                vader_struct_vader_vm_Trap_t* _a12_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a12_obj, 1308u);
                _a12_obj->f_message = t0;
                t1 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l57 = vader_vm_operand_a(l20);
            l58 = vader_vm_operand_b(l20);
            t2 = vader_vm_i32_of(l16, l12, l58);
            l59 = vader_div_i32(t2, l53);
            vader_vm_set_i32(l16, l17, l12, l57, l59);
        } else if (l19 == INT32_C(6)) {
            l60 = vader_vm_operand_c(l20);
            l61 = vader_vm_i32_of(l16, l12, l60);
            if (l61 == INT32_C(0)) {
                l62 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l63 = INT64_C(0);
                l63 = std_core_write_string_at(l62, l63, 1916u);
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
                t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l13];
                l64 = ((int64_t) (int32_t) t2);
                l63 = std_core_write_int(l62, l63, l64);
                t0 = std_core_finish_buffer(l62, l63);
                vader_struct_vader_vm_Trap_t* _a14_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a14_obj, 1308u);
                _a14_obj->f_message = t0;
                t1 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l65 = vader_vm_operand_a(l20);
            l66 = vader_vm_operand_b(l20);
            t2 = vader_vm_i32_of(l16, l12, l66);
            l67 = vader_mod_i32(t2, l61);
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
            l91 = (l88 << (l90 & 31));
            vader_vm_set_i32(l16, l17, l12, l86, l91);
        } else if (l19 == INT32_C(11)) {
            l92 = vader_vm_operand_a(l20);
            l93 = vader_vm_operand_b(l20);
            l94 = vader_vm_i32_of(l16, l12, l93);
            l95 = vader_vm_operand_c(l20);
            l96 = vader_vm_i32_of(l16, l12, l95);
            l97 = (l94 >> (l96 & 31));
            vader_vm_set_i32(l16, l17, l12, l92, l97);
        } else if (l19 == INT32_C(12)) {
            l98 = vader_vm_operand_b(l20);
            t2 = vader_vm_i32_of(l16, l12, l98);
            t4 = t2;
            l99 = (uint32_t) (int32_t) t4;
            l100 = vader_vm_operand_a(l20);
            l101 = vader_vm_operand_c(l20);
            t2 = vader_vm_i32_of(l16, l12, l101);
            t4 = t2;
            l102 = (uint32_t) (int32_t) t4;
            l103 = ((int32_t) (uint32_t) (l99 >> (l102 & 31)));
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
            t2 = vader_vm_i32_of(l16, l12, l109);
            l110 = ~(t2);
            vader_vm_set_i32(l16, l17, l12, l108, l110);
        } else if (l19 == INT32_C(15)) {
            l111 = vader_vm_operand_c(l20);
            l112 = vader_vm_i32_of(l16, l12, l111);
            if (l112 == INT32_C(0)) {
                l113 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l114 = INT64_C(0);
                l114 = std_core_write_string_at(l113, l114, 2578u);
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
                t2 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l13];
                l115 = ((int64_t) (int32_t) t2);
                l114 = std_core_write_int(l113, l114, l115);
                t0 = std_core_finish_buffer(l113, l114);
                vader_struct_vader_vm_Trap_t* _a16_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a16_obj, 1308u);
                _a16_obj->f_message = t0;
                t1 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l116 = vader_vm_operand_a(l20);
            l117 = vader_vm_operand_b(l20);
            t2 = vader_vm_i32_of(l16, l12, l117);
            t4 = t2;
            l118 = (uint32_t) (int32_t) t4;
            t2 = l112;
            l119 = (uint32_t) (int32_t) t2;
            t5 = vader_div_u32(l118, l119);
            l120 = ((int32_t) (uint32_t) t5);
            vader_vm_set_i32(l16, l17, l12, l116, l120);
        } else if (l19 == INT32_C(16)) {
            l121 = vader_vm_operand_c(l20);
            l122 = vader_vm_i32_of(l16, l12, l121);
            if (l122 == INT32_C(0)) {
                l123 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l124 = INT64_C(0);
                l124 = std_core_write_string_at(l123, l124, 2584u);
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
                t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l13];
                l125 = ((int64_t) (int32_t) t2);
                l124 = std_core_write_int(l123, l124, l125);
                t0 = std_core_finish_buffer(l123, l124);
                vader_struct_vader_vm_Trap_t* _a18_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a18_obj, 1308u);
                _a18_obj->f_message = t0;
                t1 = (void*) _a18_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l126 = vader_vm_operand_a(l20);
            l127 = vader_vm_operand_b(l20);
            t2 = vader_vm_i32_of(l16, l12, l127);
            t4 = t2;
            l128 = (uint32_t) (int32_t) t4;
            t2 = l122;
            l129 = (uint32_t) (int32_t) t2;
            t5 = vader_mod_u32(l128, l129);
            l130 = ((int32_t) (uint32_t) t5);
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
                l211 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l212 = INT64_C(0);
                l212 = std_core_write_string_at(l211, l212, 1932u);
                vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l13)
                t2 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l13];
                l213 = ((int64_t) (int32_t) t2);
                l212 = std_core_write_int(l211, l212, l213);
                t0 = std_core_finish_buffer(l211, l212);
                vader_struct_vader_vm_Trap_t* _a20_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a20_obj, 1308u);
                _a20_obj->f_message = t0;
                t1 = (void*) _a20_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l214 = vader_vm_operand_a(l20);
            l215 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l215);
            l216 = vader_div_i64(t6, l210);
            vader_vm_set_i64(l16, l17, l12, l214, l216);
        } else if (l19 == INT32_C(31)) {
            l217 = vader_vm_operand_c(l20);
            l218 = vader_vm_bits_of(l16, l12, l217);
            if (l218 == INT64_C(0)) {
                l219 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l220 = INT64_C(0);
                l220 = std_core_write_string_at(l219, l220, 1942u);
                vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l13)
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l13];
                l221 = ((int64_t) (int32_t) t2);
                l220 = std_core_write_int(l219, l220, l221);
                t0 = std_core_finish_buffer(l219, l220);
                vader_struct_vader_vm_Trap_t* _a22_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a22_obj, 1308u);
                _a22_obj->f_message = t0;
                t1 = (void*) _a22_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l222 = vader_vm_operand_a(l20);
            l223 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l223);
            l224 = vader_mod_i64(t6, l218);
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
            l248 = (l245 << (l247 & 63));
            vader_vm_set_i64(l16, l17, l12, l243, l248);
        } else if (l19 == INT32_C(36)) {
            l249 = vader_vm_operand_a(l20);
            l250 = vader_vm_operand_b(l20);
            l251 = vader_vm_bits_of(l16, l12, l250);
            l252 = vader_vm_operand_c(l20);
            l253 = vader_vm_bits_of(l16, l12, l252);
            l254 = (l251 >> (l253 & 63));
            vader_vm_set_i64(l16, l17, l12, l249, l254);
        } else if (l19 == INT32_C(37)) {
            l255 = vader_vm_operand_a(l20);
            l256 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l256);
            t7 = t6;
            l257 = (uint64_t) (int64_t) t7;
            l258 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l258);
            t7 = t6;
            l259 = (uint64_t) (int64_t) t7;
            l260 = ((int64_t) (uint64_t) (l257 >> (l259 & 63)));
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
            t6 = vader_vm_bits_of(l16, l12, l266);
            l267 = ~(t6);
            vader_vm_set_i64(l16, l17, l12, l265, l267);
        } else if (l19 == INT32_C(40)) {
            l268 = vader_vm_operand_c(l20);
            l269 = vader_vm_bits_of(l16, l12, l268);
            if (l269 == INT64_C(0)) {
                l270 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l271 = INT64_C(0);
                l271 = std_core_write_string_at(l270, l271, 2588u);
                vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l13)
                t2 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l13];
                l272 = ((int64_t) (int32_t) t2);
                l271 = std_core_write_int(l270, l271, l272);
                t0 = std_core_finish_buffer(l270, l271);
                vader_struct_vader_vm_Trap_t* _a24_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a24_obj, 1308u);
                _a24_obj->f_message = t0;
                t1 = (void*) _a24_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l273 = vader_vm_operand_a(l20);
            l274 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l274);
            t7 = t6;
            l275 = (uint64_t) (int64_t) t7;
            t6 = l269;
            l276 = (uint64_t) (int64_t) t6;
            t8 = vader_div_u64(l275, l276);
            l277 = ((int64_t) (uint64_t) t8);
            vader_vm_set_i64(l16, l17, l12, l273, l277);
        } else if (l19 == INT32_C(41)) {
            l278 = vader_vm_operand_c(l20);
            l279 = vader_vm_bits_of(l16, l12, l278);
            if (l279 == INT64_C(0)) {
                l280 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l281 = INT64_C(0);
                l281 = std_core_write_string_at(l280, l281, 2594u);
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l13)
                t2 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l13];
                l282 = ((int64_t) (int32_t) t2);
                l281 = std_core_write_int(l280, l281, l282);
                t0 = std_core_finish_buffer(l280, l281);
                vader_struct_vader_vm_Trap_t* _a26_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                vader_obj_header_init(_a26_obj, 1308u);
                _a26_obj->f_message = t0;
                t1 = (void*) _a26_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l283 = vader_vm_operand_a(l20);
            l284 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l284);
            t7 = t6;
            l285 = (uint64_t) (int64_t) t7;
            t6 = l279;
            l286 = (uint64_t) (int64_t) t6;
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
            t6 = vader_vm_bits_of(l16, l12, l325);
            t7 = t6;
            l326 = (uint64_t) (int64_t) t7;
            l327 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l327);
            t7 = t6;
            l328 = (uint64_t) (int64_t) t7;
            l329 = (l326 < l328);
            vader_vm_set_bool(l16, l17, l12, l324, l329);
        } else if (l19 == INT32_C(49)) {
            l330 = vader_vm_operand_a(l20);
            l331 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l331);
            t7 = t6;
            l332 = (uint64_t) (int64_t) t7;
            l333 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l333);
            t7 = t6;
            l334 = (uint64_t) (int64_t) t7;
            l335 = (l332 <= l334);
            vader_vm_set_bool(l16, l17, l12, l330, l335);
        } else if (l19 == INT32_C(50)) {
            l336 = vader_vm_operand_a(l20);
            l337 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l337);
            t7 = t6;
            l338 = (uint64_t) (int64_t) t7;
            l339 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l339);
            t7 = t6;
            l340 = (uint64_t) (int64_t) t7;
            l341 = (l338 > l340);
            vader_vm_set_bool(l16, l17, l12, l336, l341);
        } else if (l19 == INT32_C(51)) {
            l342 = vader_vm_operand_a(l20);
            l343 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l343);
            t7 = t6;
            l344 = (uint64_t) (int64_t) t7;
            l345 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l345);
            t7 = t6;
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
            t6 = vader_vm_bits_of(l16, l12, l412);
            l413 = t6 != INT64_C(0);
            l414 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l414);
            l415 = t6 != INT64_C(0);
            l416 = l413 == l415;
            vader_vm_set_bool(l16, l17, l12, l411, l416);
        } else if (l19 == INT32_C(64)) {
            l417 = vader_vm_operand_a(l20);
            l418 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l418);
            l419 = t6 != INT64_C(0);
            l420 = vader_vm_operand_c(l20);
            t6 = vader_vm_bits_of(l16, l12, l420);
            l421 = t6 != INT64_C(0);
            l422 = l419 != l421;
            vader_vm_set_bool(l16, l17, l12, l417, l422);
        } else if (l19 == INT32_C(65)) {
            l423 = vader_vm_operand_a(l20);
            l424 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l424);
            if (t6 != INT64_C(0)) {
                l426 = vader_vm_operand_c(l20);
                t6 = vader_vm_bits_of(l16, l12, l426);
                l425 = t6 != INT64_C(0);
            } else {
                l425 = false;
            }
            vader_vm_set_bool(l16, l17, l12, l423, l425);
        } else if (l19 == INT32_C(66)) {
            l427 = vader_vm_operand_a(l20);
            l428 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l428);
            if (t6 != INT64_C(0)) {
                l429 = true;
            } else {
                l430 = vader_vm_operand_c(l20);
                t6 = vader_vm_bits_of(l16, l12, l430);
                l429 = t6 != INT64_C(0);
            }
            vader_vm_set_bool(l16, l17, l12, l427, l429);
        } else if (l19 == INT32_C(67)) {
            l431 = vader_vm_operand_a(l20);
            l432 = vader_vm_operand_b(l20);
            t6 = vader_vm_bits_of(l16, l12, l432);
            l433 = t6 == INT64_C(0);
            vader_vm_set_bool(l16, l17, l12, l431, l433);
        } else if (l19 == INT32_C(68)) {
            l435 = vader_vm_checked_registers((uint8_t) 0, (uint8_t) 2, l16, l12, l20);
            if (l435.tag == 0u) {
                vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l13)
                t3 = vader_array_read_u8(_a27_slotarr, _a27_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a28_slotarr, _a28_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a29_slotarr, _a29_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a30_slotarr, _a30_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_neg_trap(((uint8_t) t3.payload.i), l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a31_slotarr, _a31_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a32_slotarr, _a32_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a33_slotarr, _a33_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
                t3 = vader_array_read_u8(_a34_slotarr, _a34_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_neg_trap(((uint8_t) t3.payload.i), l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l461 = ((int64_t) l464.payload.i);
            l465 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l465, l461);
        } else if (l19 == INT32_C(76)) {
            l467 = vader_vm_checked_registers((uint8_t) 0, (uint8_t) 7, l16, l12, l20);
            if (l467.tag == 0u) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l13)
                t3 = vader_array_read_u8(_a35_slotarr, _a35_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l466 = ((int64_t) l467.payload.i);
            l468 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l468, l466);
        } else if (l19 == INT32_C(77)) {
            l470 = vader_vm_checked_registers((uint8_t) 1, (uint8_t) 7, l16, l12, l20);
            if (l470.tag == 0u) {
                vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l13)
                t3 = vader_array_read_u8(_a36_slotarr, _a36_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l469 = ((int64_t) l470.payload.i);
            l471 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l471, l469);
        } else if (l19 == INT32_C(78)) {
            l473 = vader_vm_checked_registers((uint8_t) 2, (uint8_t) 7, l16, l12, l20);
            if (l473.tag == 0u) {
                vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l13)
                t3 = vader_array_read_u8(_a37_slotarr, _a37_slotarr->offset + (size_t) l13, 292u);
                t1 = vader_vm_checked_trap(((uint8_t) t3.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l472 = ((int64_t) l473.payload.i);
            l474 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l474, l472);
        } else if (l19 == INT32_C(79)) {
            vader_array_t* _a38_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l13)
            t3 = vader_array_read_u8(_a38_slotarr, _a38_slotarr->offset + (size_t) l13, 292u);
            l475 = ((uint8_t) t3.payload.i);
            l477 = vader_vm_checked_registers((uint8_t) 0, l475, l16, l12, l20);
            if (l477.tag == 0u) {
                t1 = vader_vm_checked_trap(l475, (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l476 = ((int64_t) l477.payload.i);
            l478 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l478, l475, l476);
        } else if (l19 == INT32_C(80)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l13)
            t3 = vader_array_read_u8(_a39_slotarr, _a39_slotarr->offset + (size_t) l13, 292u);
            l479 = ((uint8_t) t3.payload.i);
            l481 = vader_vm_checked_registers((uint8_t) 1, l479, l16, l12, l20);
            if (l481.tag == 0u) {
                t1 = vader_vm_checked_trap(l479, (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l480 = ((int64_t) l481.payload.i);
            l482 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l482, l479, l480);
        } else if (l19 == INT32_C(81)) {
            vader_array_t* _a40_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l13)
            t3 = vader_array_read_u8(_a40_slotarr, _a40_slotarr->offset + (size_t) l13, 292u);
            l483 = ((uint8_t) t3.payload.i);
            l485 = vader_vm_checked_registers((uint8_t) 2, l483, l16, l12, l20);
            if (l485.tag == 0u) {
                t1 = vader_vm_checked_trap(l483, (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l484 = ((int64_t) l485.payload.i);
            l486 = vader_vm_operand_a(l20);
            vader_vm_set_integer(l16, l17, l12, l486, l483, l484);
        } else if (l19 == INT32_C(82)) {
            vader_array_t* _a41_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l13)
            t3 = vader_array_read_u8(_a41_slotarr, _a41_slotarr->offset + (size_t) l13, 292u);
            l487 = ((uint8_t) t3.payload.i);
            l489 = vader_vm_operand_b(l20);
            l490 = vader_vm_bits_of(l16, l12, l489);
            l491 = vader_bytecode_checked_neg(l487, l490);
            if (l491.tag == 0u) {
                t1 = vader_vm_checked_neg_trap(l487, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
            l499 = vader_vm_operand_b(l20);
            l500 = vader_vm_zero_extended(l16, l17, l12, l499);
            l501 = vader_vm_operand_a(l20);
            vader_vm_set_i64(l16, l17, l12, l501, l500);
        } else if (l19 == INT32_C(86)) {
            l502 = vader_vm_operand_a(l20);
            l503 = vader_vm_operand_b(l20);
            l504 = vader_vm_u32_of(l16, l12, l503);
            vader_vm_set_char_code(l16, l17, l12, l502, l504);
        } else {
            if (l19 == INT32_C(87)) {
                t2 = vader_vm_operand_a(l20);
                l13 = ((int64_t) (int32_t) t2);
                continue;
            }
            if (l19 == INT32_C(88)) {
                t2 = vader_vm_operand_b(l20);
                l505 = ((int64_t) (int32_t) t2);
                l10 = vader_chk_add(i64, l10, l505);
                if ((l10 > l9)) {
                    t1 = vader_vm_budget_trap(l9);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = vader_vm_operand_a(l20);
                l13 = ((int64_t) (int32_t) t2);
                continue;
            }
            if (l19 == INT32_C(89)) {
                l506 = vader_vm_operand_b(l20);
                t6 = vader_vm_bits_of(l16, l12, l506);
                if (t6 == INT64_C(0)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(90)) {
                l507 = vader_vm_operand_b(l20);
                t6 = vader_vm_bits_of(l16, l12, l507);
                if (t6 != INT64_C(0)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(91)) {
                l508 = vader_vm_operand_b(l20);
                l509 = vader_vm_i32_of(l16, l12, l508);
                l510 = vader_vm_operand_c(l20);
                l511 = vader_vm_i32_of(l16, l12, l510);
                if (l509 == l511) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(92)) {
                l512 = vader_vm_operand_b(l20);
                l513 = vader_vm_i32_of(l16, l12, l512);
                l514 = vader_vm_operand_c(l20);
                l515 = vader_vm_i32_of(l16, l12, l514);
                if (l513 != l515) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(93)) {
                l516 = vader_vm_operand_b(l20);
                l517 = vader_vm_i32_of(l16, l12, l516);
                l518 = vader_vm_operand_c(l20);
                l519 = vader_vm_i32_of(l16, l12, l518);
                if ((l517 < l519)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(94)) {
                l520 = vader_vm_operand_b(l20);
                l521 = vader_vm_i32_of(l16, l12, l520);
                l522 = vader_vm_operand_c(l20);
                l523 = vader_vm_i32_of(l16, l12, l522);
                if ((l521 <= l523)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(97)) {
                l524 = vader_vm_operand_b(l20);
                l525 = vader_vm_bits_of(l16, l12, l524);
                l526 = vader_vm_operand_c(l20);
                l527 = vader_vm_bits_of(l16, l12, l526);
                if (l525 == l527) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(98)) {
                l528 = vader_vm_operand_b(l20);
                l529 = vader_vm_bits_of(l16, l12, l528);
                l530 = vader_vm_operand_c(l20);
                l531 = vader_vm_bits_of(l16, l12, l530);
                if (l529 != l531) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(99)) {
                l532 = vader_vm_operand_b(l20);
                l533 = vader_vm_bits_of(l16, l12, l532);
                l534 = vader_vm_operand_c(l20);
                l535 = vader_vm_bits_of(l16, l12, l534);
                if ((l533 < l535)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(100)) {
                l536 = vader_vm_operand_b(l20);
                l537 = vader_vm_bits_of(l16, l12, l536);
                l538 = vader_vm_operand_c(l20);
                l539 = vader_vm_bits_of(l16, l12, l538);
                if ((l537 <= l539)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(95)) {
                l540 = vader_vm_operand_b(l20);
                l541 = vader_vm_u32_of(l16, l12, l540);
                l542 = vader_vm_operand_c(l20);
                l543 = vader_vm_u32_of(l16, l12, l542);
                if ((l541 < l543)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(96)) {
                l544 = vader_vm_operand_b(l20);
                l545 = vader_vm_u32_of(l16, l12, l544);
                l546 = vader_vm_operand_c(l20);
                l547 = vader_vm_u32_of(l16, l12, l546);
                if ((l545 <= l547)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(101)) {
                l548 = vader_vm_operand_b(l20);
                l549 = vader_vm_u64_of(l16, l12, l548);
                l550 = vader_vm_operand_c(l20);
                l551 = vader_vm_u64_of(l16, l12, l550);
                if ((l549 < l551)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(102)) {
                l552 = vader_vm_operand_b(l20);
                l553 = vader_vm_u64_of(l16, l12, l552);
                l554 = vader_vm_operand_c(l20);
                l555 = vader_vm_u64_of(l16, l12, l554);
                if ((l553 <= l555)) {
                    t2 = vader_vm_operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(109)) {
                t2 = vader_vm_operand_b(l20);
                l556 = ((int64_t) (int32_t) t2);
                l10 = vader_chk_add(i64, l10, l556);
                if ((l10 > l9)) {
                    t1 = vader_vm_budget_trap(l9);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(119)) {
                l557 = vader_vm_run_boxed(l0, l2, l8, l13, l12, l7);
                if (!(l557.tag == 0u)) {
                    t1 = l557.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(120)) {
                l558 = vader_vm_operand_a(l20);
                t2 = vader_vm_operand_b(l20);
                l559 = ((int64_t) (int32_t) t2);
                l560 = vader_chk_add(i64, l12, l559);
                vader_array_t* _a42_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l13)
                l561 = ((int32_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l13];
                l562 = vader_vm_call_import(l0, l2, l558, l560, l561, l7);
                if (!(l562.tag == 0u)) {
                    t1 = l562.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(121)) {
                t2 = vader_vm_operand_b(l20);
                l563 = ((int64_t) (int32_t) t2);
                l564 = vader_chk_add(i64, l12, l563);
                l566 = vader_vm_string_at(l2, l564);
                if (l566.tag == 0u) {
                    t1 = vader_vm_receiver_trap(l2, l564, l8, l13, 1519u, 2447u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l565 = l566.payload.s;
                l567 = vader_vm_operand_a(l20);
                t6 = vader_host_std_core_byte_len(l565);
                l568 = ((int32_t) (int64_t) t6);
                vader_vm_set_i32(l16, l17, l12, l567, l568);
            } else if (l19 == INT32_C(122)) {
                t2 = vader_vm_operand_b(l20);
                l569 = ((int64_t) (int32_t) t2);
                l570 = vader_chk_add(i64, l12, l569);
                l572 = vader_vm_string_at(l2, l570);
                if (l572.tag == 0u) {
                    t1 = vader_vm_receiver_trap(l2, l570, l8, l13, 1518u, 2447u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l571 = l572.payload.s;
                l573 = vader_vm_operand_c(l20);
                l574 = vader_vm_i32_of(l16, l12, l573);
                if ((l574 < INT32_C(0))) {
                    l575 = true;
                } else {
                    l576 = ((int64_t) (int32_t) l574);
                    l577 = vader_host_std_core_byte_len(l571);
                    l575 = (l576 >= l577);
                }
                if (l575) {
                    vader_struct_vader_vm_Trap_t* _a43_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                    vader_obj_header_init(_a43_obj, 1308u);
                    _a43_obj->f_message = 1517u;
                    t1 = (void*) _a43_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l578 = vader_vm_operand_a(l20);
                l579 = ((int64_t) (int32_t) l574);
                t10 = vader_host_std_core_byte_at(l571, l579);
                l580 = ((int32_t) (uint8_t) t10);
                vader_vm_set_i32(l16, l17, l12, l578, l580);
            } else if (l19 == INT32_C(124)) {
                t2 = vader_vm_operand_b(l20);
                l581 = ((int64_t) (int32_t) t2);
                l582 = vader_chk_add(i64, l12, l581);
                l584 = vader_vm_string_at(l2, l582);
                if (l584.tag == 0u) {
                    t1 = vader_vm_receiver_trap(l2, l582, l8, l13, 2034u, 2447u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l583 = l584.payload.s;
                l585 = vader_vm_operand_a(l20);
                l586 = vader_host_std_core_is_ascii(l583);
                vader_vm_set_bool(l16, l17, l12, l585, l586);
            } else if (l19 == INT32_C(123)) {
                t2 = vader_vm_operand_a(l20);
                l587 = ((int64_t) (int32_t) t2);
                l588 = vader_chk_add(i64, l12, l587);
                l590 = vader_vm_string_at(l2, l588);
                if (l590.tag == 0u) {
                    t1 = vader_vm_receiver_trap(l2, l588, l8, l13, 1520u, 2447u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l589 = l590.payload.s;
                l591 = vader_vm_operand_b(l20);
                l592 = vader_vm_bits_of(l16, l12, l591);
                l593 = vader_vm_operand_c(l20);
                l594 = vader_vm_bits_of(l16, l12, l593);
                l595 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_refs;
                l596 = vader_host_std_core_byte_slice(l589, l592, l594);
                vader_array_t* _a44_slotarr = ((vader_array_t*) l595);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l588)
                vader_array_box_slots(_a44_slotarr->buf)[_a44_slotarr->offset + (size_t) l588] = vader_box_string(287u, l596);
                VADER_WRITE_BARRIER(_a44_slotarr->buf);
                vader_array_t* _a45_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l588)
                ((uint8_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l588] = (uint8_t) INT32_C(6);
            } else {
                if (l19 == INT32_C(125)) {
                    l597 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_texts;
                    l598 = vader_vm_operand_a(l20);
                    vader_array_t* _a46_slotarr = ((vader_array_t*) l597);
                    VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l598)
                    t3 = vader_array_box_slots(_a46_slotarr->buf)[_a46_slotarr->offset + (size_t) l598];
                    t0 = t3.payload.s;
                    vader_struct_vader_vm_Trap_t* _a47_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                    vader_obj_header_init(_a47_obj, 1308u);
                    _a47_obj->f_message = t0;
                    t1 = (void*) _a47_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l19 == INT32_C(126)) {
                    t2 = vader_vm_operand_a(l20);
                    l599 = ((int64_t) (int32_t) t2);
                    l600 = vader_chk_add(i64, l12, l599);
                    l601 = vader_vm_register_value(l2, l600);
                    l602 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
                    l603 = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers)->length;
                    if ((l602 < l603)) {
                        l604 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers;
                        l605 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
                        vader_array_t* _a48_slotarr = ((vader_array_t*) l604);
                        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l605)
                        vader_array_box_slots(_a48_slotarr->buf)[_a48_slotarr->offset + (size_t) l605] = l601;
                        VADER_WRITE_BARRIER(_a48_slotarr->buf);
                    } else {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers, l601);
                    }
                    t6 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
                    l606 = vader_chk_add(i64, t6, INT64_C(1));
                    ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count = l606;
                } else if (l19 == INT32_C(127)) {
                    l607 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_registers;
                    l608 = vader_chk_add(i64, l12, l607);
                    l609 = vader_vm_run_defers(l0, l1, l2, l8, l13, l608, l11, l7);
                    if (!(l609.tag == 0u)) {
                        t1 = l609.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else if (l19 == INT32_C(128)) {
                    l610 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_debug;
                    if (!(l610.tag == 0u)) {
                        l611 = l610.payload.obj;
                        vader_vm_stop_at_line(l0, l2, l611, l8, l13, l11);
                    }
                } else if (l19 == INT32_C(110)) {
                    t2 = vader_vm_operand_a(l20);
                    l612 = ((int64_t) (int32_t) t2);
                    l613 = vader_chk_add(i64, l12, l612);
                    l614 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_values;
                    l615 = vader_vm_operand_b(l20);
                    vader_array_t* _a49_slotarr = ((vader_array_t*) l614);
                    VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l615)
                    l616 = vader_array_box_slots(_a49_slotarr->buf)[_a49_slotarr->offset + (size_t) l615];
                    vader_array_t* _a50_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l613)
                    vader_array_box_slots(_a50_slotarr->buf)[_a50_slotarr->offset + (size_t) l613] = l616;
                    VADER_WRITE_BARRIER(_a50_slotarr->buf);
                    vader_array_t* _a51_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l613)
                    ((uint8_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l613] = (uint8_t) INT32_C(6);
                } else if (l19 == INT32_C(111)) {
                    t2 = vader_vm_operand_b(l20);
                    l617 = ((int64_t) (int32_t) t2);
                    l618 = vader_chk_add(i64, l12, l617);
                    vader_array_t* _a52_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l618)
                    l619 = vader_array_box_slots(_a52_slotarr->buf)[_a52_slotarr->offset + (size_t) l618];
                    l620 = vader_vm_operand_c(l20);
                    if (l619.tag == 1305u) {
                        l621 = (l620 >= INT32_C(0));
                    } else {
                        l621 = false;
                    }
                    if (l621) {
                        l623 = ((int64_t) (int32_t) l620);
                        t1 = l619.payload.obj;
                        l624 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields)->length;
                        l622 = (l623 < l624);
                    } else {
                        l622 = false;
                    }
                    if (l622) {
                        t2 = vader_vm_operand_a(l20);
                        l625 = ((int64_t) (int32_t) t2);
                        l626 = vader_chk_add(i64, l12, l625);
                        t1 = l619.payload.obj;
                        vader_array_t* _a53_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t1)->f_fields);
                        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l620)
                        l627 = vader_array_box_slots(_a53_slotarr->buf)[_a53_slotarr->offset + (size_t) l620];
                        vader_vm_set_register(l2, l626, l627);
                    } else {
                        vader_array_t* _a54_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                        VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a54_slotarr, l13)
                        l628 = ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l13];
                        l629 = vader_vm_read_struct_field(l619, l620, l628, 2465u);
                        if (l629.tag == 1308u) {
                            t1 = l629.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    }
                } else if (l19 == INT32_C(112)) {
                    l630 = vader_vm_operand_a(l20);
                    l631 = vader_vm_operand_b(l20);
                    l632 = vader_vm_operand_c(l20);
                    l633 = vader_vm_set_field(l2, l12, l630, l631, l632, l8, l13);
                    if (!(l633.tag == 0u)) {
                        t1 = l633.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else {
                    if (l19 == INT32_C(113)) {
                        l634 = true;
                    } else {
                        l634 = l19 == INT32_C(115);
                    }
                    if (l634) {
                        l635 = vader_vm_operand_a(l20);
                        l636 = vader_vm_operand_b(l20);
                        l637 = vader_vm_operand_c(l20);
                        t11 = vader_vm_try_get_element(l2, l12, l635, l636, l637);
                        if (!(t11)) {
                            l638 = vader_vm_operand_b(l20);
                            l639 = vader_vm_operand_c(l20);
                            t1 = vader_vm_element_trap(l2, l12, l638, l639, l8, l13, l19);
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    } else {
                        if (l19 == INT32_C(114)) {
                            l640 = true;
                        } else {
                            l640 = l19 == INT32_C(116);
                        }
                        if (l640) {
                            l641 = vader_vm_operand_a(l20);
                            l642 = vader_vm_operand_b(l20);
                            l643 = vader_vm_operand_c(l20);
                            t11 = vader_vm_try_set_element(l2, l12, l641, l642, l643);
                            if (!(t11)) {
                                l644 = vader_vm_operand_a(l20);
                                l645 = vader_vm_operand_b(l20);
                                l646 = vader_vm_operand_c(l20);
                                l647 = vader_vm_set_element(l2, l12, l644, l645, l646, l8, l13, l19);
                                if (!(l647.tag == 0u)) {
                                    t1 = l647.payload.obj;
                                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                            }
                        } else if (l19 == INT32_C(117)) {
                            t2 = vader_vm_operand_b(l20);
                            l648 = ((int64_t) (int32_t) t2);
                            l649 = vader_chk_add(i64, l12, l648);
                            l651 = vader_vm_array_at(l2, l649);
                            if (l651.tag == 0u) {
                                t1 = vader_vm_receiver_trap(l2, l649, l8, l13, 1423u, 1409u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l650 = l651.payload.obj;
                            l652 = vader_vm_operand_a(l20);
                            t6 = ((vader_struct_vader_vm_ArrayVal_t*) l650)->f_length;
                            l653 = ((int32_t) (int64_t) t6);
                            vader_vm_set_i32(l16, l17, l12, l652, l653);
                        } else if (l19 == INT32_C(118)) {
                            t2 = vader_vm_operand_a(l20);
                            l654 = ((int64_t) (int32_t) t2);
                            l655 = vader_chk_add(i64, l12, l654);
                            l657 = vader_vm_array_at(l2, l655);
                            if (l657.tag == 0u) {
                                t1 = vader_vm_receiver_trap(l2, l655, l8, l13, 1426u, 1409u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l656 = l657.payload.obj;
                            if (!(((vader_struct_vader_vm_ArrayVal_t*) l656)->f_raw.tag == 0u)) {
                                l658 = true;
                            } else {
                                l658 = vader_vm_is_array_view(l656);
                            }
                            if (l658) {
                                vader_vm_detach_array_view(l656);
                            }
                            l659 = ((vader_struct_vader_vm_ArrayVal_t*) l656)->f_elements;
                            t2 = vader_vm_operand_b(l20);
                            l660 = ((int64_t) (int32_t) t2);
                            l661 = vader_chk_add(i64, l12, l660);
                            l662 = vader_vm_register_value(l2, l661);
                            vader_array_push((vader_array_t*) l659, l662);
                            t6 = ((vader_struct_vader_vm_ArrayVal_t*) l656)->f_length;
                            l663 = vader_chk_add(i64, t6, INT64_C(1));
                            ((vader_struct_vader_vm_ArrayVal_t*) l656)->f_length = l663;
                        } else if (l19 == INT32_C(106)) {
                            t2 = vader_vm_operand_a(l20);
                            l664 = ((int64_t) (int32_t) t2);
                            l665 = vader_chk_add(i64, l12, l664);
                            l666 = vader_vm_operand_b(l20);
                            vader_vm_narrow_register(l2, l665, l666);
                        } else {
                            if (l19 == INT32_C(103)) {
                                l667 = true;
                            } else {
                                l667 = l19 == INT32_C(104);
                            }
                            if (l667) {
                                l668 = true;
                            } else {
                                l668 = l19 == INT32_C(105);
                            }
                            if (l668) {
                                t2 = vader_vm_operand_b(l20);
                                l669 = ((int64_t) (int32_t) t2);
                                l670 = vader_chk_add(i64, l12, l669);
                                l671 = vader_vm_operand_a(l20);
                                if (l19 == INT32_C(104)) {
                                    t2 = vader_vm_operand_c(l20);
                                    l672 = ((int64_t) (int32_t) t2);
                                    l673 = vader_chk_add(i64, l670, l672);
                                    vader_array_t* _a55_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l673)
                                    l674 = vader_array_box_slots(_a55_slotarr->buf)[_a55_slotarr->offset + (size_t) l673];
                                    l675 = vader_chk_add(i64, l670, l672);
                                    vader_array_t* _a56_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l675)
                                    t3 = vader_array_read_u8(_a56_slotarr, _a56_slotarr->offset + (size_t) l675, 292u);
                                    if (((int32_t) t3.payload.i) == INT32_C(6)) {
                                        l676 = l674.tag == 1285u;
                                    } else {
                                        l676 = false;
                                    }
                                    if (!(l676)) {
                                        vader_array_t* _a57_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l13)
                                        l694 = ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l13];
                                        t1 = vader_vm_indirect_call_trap(l1, l2, l670, l672, l694);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    t1 = l674.payload.obj;
                                    l677 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_function_index;
                                    t1 = l674.payload.obj;
                                    l678 = ((vader_struct_vader_vm_FnVal_t*) t1)->f_env;
                                    if (l678.tag == 0u) {
                                        l679 = l672;
                                    } else {
                                        l679 = vader_chk_add(i64, l672, INT64_C(1));
                                    }
                                    if ((l677 >= INT32_C(0))) {
                                        l681 = ((int64_t) (int32_t) l677);
                                        l682 = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions)->length;
                                        l680 = (l681 < l682);
                                    } else {
                                        l680 = false;
                                    }
                                    if (l680) {
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l677)
                                        t1 = vader_array_ref_load_obj(_a58_slotarr->buf, _a58_slotarr->offset + (size_t) l677);
                                        t6 = ((vader_struct_vader_vm_RegFunction_t*) t1)->f_params;
                                        l683 = t6 == l679;
                                    } else {
                                        l683 = false;
                                    }
                                    if (!(l683)) {
                                        vader_array_t* _a59_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l13)
                                        l693 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l13];
                                        t1 = vader_vm_indirect_call_trap(l1, l2, l670, l672, l693);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    if (!(l678.tag == 0u)) {
                                        l684 = l672;
                                        while ((l684 > INT64_C(0))) {
                                            l685 = vader_chk_add(i64, l670, l684);
                                            l686 = vader_chk_sub(i64, l685, INT64_C(1));
                                            vader_array_t* _a60_slotarr = ((vader_array_t*) l16);
                                            VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l686)
                                            l687 = ((int64_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l686];
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l685)
                                            ((int64_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l685] = (int64_t) l687;
                                            l688 = vader_chk_sub(i64, l685, INT64_C(1));
                                            vader_array_t* _a61_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a61_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l688)
                                            t3 = vader_array_read_u8(_a61_slotarr, _a61_slotarr->offset + (size_t) l688, 292u);
                                            l689 = ((uint8_t) t3.payload.i);
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l685)
                                            ((uint8_t*) _a61_slotarr->buf->slots)[_a61_slotarr->offset + (size_t) l685] = (uint8_t) (int32_t) (uint8_t) l689;
                                            l690 = vader_chk_sub(i64, l685, INT64_C(1));
                                            vader_array_t* _a62_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l690)
                                            l691 = vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l690];
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l685)
                                            vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l685] = l691;
                                            VADER_WRITE_BARRIER(_a62_slotarr->buf);
                                            l684 = vader_chk_sub(i64, l684, INT64_C(1));
                                        }
                                        l692 = l678;
                                        vader_vm_set_register(l2, l670, l692);
                                    }
                                    l671 = l677;
                                } else if (l19 == INT32_C(105)) {
                                    l695 = ((int64_t) (int32_t) l671);
                                    t2 = vader_vm_operand_c(l20);
                                    l696 = ((int64_t) (int32_t) t2);
                                    t6 = vader_chk_add(i64, l670, l696);
                                    l697 = vader_chk_sub(i64, t6, INT64_C(1));
                                    vader_array_t* _a63_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a63_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a63_slotarr, l697)
                                    l698 = vader_array_box_slots(_a63_slotarr->buf)[_a63_slotarr->offset + (size_t) l697];
                                    vader_array_t* _a64_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l697)
                                    t3 = vader_array_read_u8(_a64_slotarr, _a64_slotarr->offset + (size_t) l697, 292u);
                                    if (((int32_t) t3.payload.i) != INT32_C(6)) {
                                        l699 = INT32_C(-1);
                                    } else if (l698.tag == 1305u) {
                                        t1 = l698.payload.obj;
                                        l699 = ((vader_struct_vader_vm_StructVal_t*) t1)->f_type_id;
                                    } else if (l698.tag == 1280u) {
                                        t1 = l698.payload.obj;
                                        l699 = ((vader_struct_vader_vm_ArrayVal_t*) t1)->f_type_id;
                                    } else {
                                        l699 = INT32_C(-1);
                                    }
                                    if ((l699 < INT32_C(0))) {
                                        l700 = INT32_C(-1);
                                    } else {
                                        vader_array_t* _a65_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l8)->f_virtual_rows);
                                        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l695)
                                        l700 = ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l695];
                                    }
                                    l701 = vader_vm_lookup_vtable_row(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables, l700, l699);
                                    if ((l701 >= INT32_C(0))) {
                                        l703 = ((int64_t) (int32_t) l701);
                                        l704 = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions)->length;
                                        l702 = (l703 < l704);
                                    } else {
                                        l702 = false;
                                    }
                                    if (l702) {
                                        vader_array_t* _a66_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l701)
                                        t1 = vader_array_ref_load_obj(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l701);
                                        t6 = ((vader_struct_vader_vm_RegFunction_t*) t1)->f_params;
                                        l705 = t6 == l696;
                                    } else {
                                        l705 = false;
                                    }
                                    if (l705) {
                                        if ((l697 > l670)) {
                                            l706 = l697;
                                            while ((l706 > l670)) {
                                                l707 = vader_chk_sub(i64, l706, INT64_C(1));
                                                vader_array_t* _a67_slotarr = ((vader_array_t*) l16);
                                                VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l707)
                                                l708 = ((int64_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l707];
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l706)
                                                ((int64_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l706] = (int64_t) l708;
                                                l709 = vader_chk_sub(i64, l706, INT64_C(1));
                                                vader_array_t* _a68_slotarr = ((vader_array_t*) l17);
                                                VADER_ARRAY_RESOLVE_BUF(_a68_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l709)
                                                t3 = vader_array_read_u8(_a68_slotarr, _a68_slotarr->offset + (size_t) l709, 292u);
                                                l710 = ((uint8_t) t3.payload.i);
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l706)
                                                ((uint8_t*) _a68_slotarr->buf->slots)[_a68_slotarr->offset + (size_t) l706] = (uint8_t) (int32_t) (uint8_t) l710;
                                                l711 = vader_chk_sub(i64, l706, INT64_C(1));
                                                vader_array_t* _a69_slotarr = ((vader_array_t*) l18);
                                                VADER_ARRAY_RESOLVE_BUF(_a69_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l711)
                                                l712 = vader_array_box_slots(_a69_slotarr->buf)[_a69_slotarr->offset + (size_t) l711];
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l706)
                                                vader_array_box_slots(_a69_slotarr->buf)[_a69_slotarr->offset + (size_t) l706] = l712;
                                                VADER_WRITE_BARRIER(_a69_slotarr->buf);
                                                l706 = vader_chk_sub(i64, l706, INT64_C(1));
                                            }
                                            vader_array_t* _a70_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a70_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a70_slotarr, l670)
                                            vader_array_box_slots(_a70_slotarr->buf)[_a70_slotarr->offset + (size_t) l670] = l698;
                                            VADER_WRITE_BARRIER(_a70_slotarr->buf);
                                            vader_array_t* _a71_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l670)
                                            ((uint8_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l670] = (uint8_t) INT32_C(6);
                                        }
                                        l671 = l701;
                                    } else {
                                        l713 = vader_vm_resolve_virtual(l0, l2, l8, l13, l670, l7);
                                        if (l713.tag == 1308u) {
                                            t1 = l713.payload.obj;
                                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        l671 = ((int32_t) l713.payload.i);
                                    }
                                }
                                if ((l671 >= INT32_C(0))) {
                                    vader_array_t* _a72_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions);
                                    VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l671)
                                    l714 = vader_array_ref_load_obj(_a72_slotarr->buf, _a72_slotarr->offset + (size_t) l671);
                                    l10 = vader_chk_add(i64, l10, INT64_C(1));
                                    l715 = ((int64_t) 1024);
                                    if ((l11 >= l715)) {
                                        t0 = ((vader_struct_vader_vm_RegFunction_t*) l714)->f_name;
                                        t1 = vader_vm_overflow_trap(t0);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    l716 = ((vader_array_t*) l16)->length;
                                    l717 = ((vader_struct_vader_vm_RegFunction_t*) l714)->f_registers;
                                    l718 = vader_chk_add(i64, l670, l717);
                                    if ((l716 < l718)) {
                                        l719 = ((vader_struct_vader_vm_RegFunction_t*) l714)->f_registers;
                                        l720 = vader_chk_add(i64, l670, l719);
                                        vader_vm_reserve_registers(l2, l720);
                                    }
                                    l721 = ((vader_struct_vader_vm_RegFunction_t*) l714)->f_params;
                                    l722 = vader_chk_add(i64, l670, l721);
                                    l723 = ((vader_struct_vader_vm_RegFunction_t*) l714)->f_slots;
                                    l724 = vader_chk_add(i64, l670, l723);
                                    while ((l722 < l724)) {
                                        vader_array_t* _a73_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l722)
                                        ((uint8_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l722] = (uint8_t) INT32_C(5);
                                        l722 = (l722 + INT64_C(1));
                                    }
                                    l725 = ((vader_struct_vader_vm_RegFunction_t*) l714)->f_slots;
                                    l726 = vader_chk_add(i64, l670, l725);
                                    l727 = INT64_C(0);
                                    l728 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l714)->f_consts)->length;
                                    while ((l727 < l728)) {
                                        l729 = vader_chk_add(i64, l726, l727);
                                        vader_array_t* _a74_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l714)->f_consts);
                                        VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l727)
                                        l730 = ((int64_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l727];
                                        vader_array_t* _a75_slotarr = ((vader_array_t*) l16);
                                        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a75_slotarr, l729)
                                        ((int64_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l729] = (int64_t) l730;
                                        l731 = vader_chk_add(i64, l726, l727);
                                        vader_array_t* _a76_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l714)->f_const_tags);
                                        VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l727)
                                        t3 = vader_array_read_u8(_a76_slotarr, _a76_slotarr->offset + (size_t) l727, 292u);
                                        l732 = ((uint8_t) t3.payload.i);
                                        vader_array_t* _a77_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a77_slotarr, l731)
                                        ((uint8_t*) _a77_slotarr->buf->slots)[_a77_slotarr->offset + (size_t) l731] = (uint8_t) (int32_t) (uint8_t) l732;
                                        l727 = (l727 + INT64_C(1));
                                    }
                                    l733 = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code)->length;
                                    if ((l11 < l733)) {
                                        vader_array_t* _a78_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code);
                                        VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a78_slotarr, l11)
                                        vader_array_ref_store(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l11, l714);
                                        VADER_WRITE_BARRIER(_a78_slotarr->buf);
                                        vader_array_t* _a79_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_base);
                                        VADER_ARRAY_RESOLVE_BUF(_a79_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a79_slotarr, l11)
                                        ((int64_t*) _a79_slotarr->buf->slots)[_a79_slotarr->offset + (size_t) l11] = (int64_t) l670;
                                        l734 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_return;
                                        l735 = vader_chk_add(i64, l13, INT64_C(1));
                                        vader_array_t* _a80_slotarr = ((vader_array_t*) l734);
                                        VADER_ARRAY_RESOLVE_BUF(_a80_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a80_slotarr, l11)
                                        ((int64_t*) _a80_slotarr->buf->slots)[_a80_slotarr->offset + (size_t) l11] = (int64_t) l735;
                                    } else {
                                        l736 = vader_chk_add(i64, l13, INT64_C(1));
                                        vader_vm_grow_frame_records(l2, l714, l670, l736);
                                    }
                                    l11 = vader_chk_add(i64, l11, INT64_C(1));
                                    l12 = l670;
                                    l8 = l714;
                                    l14 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_ops;
                                    l15 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_words;
                                    l13 = INT64_C(0);
                                    continue;
                                }
                            } else {
                                if (l19 == INT32_C(107)) {
                                    l737 = true;
                                } else {
                                    l737 = l19 == INT32_C(108);
                                }
                                if (!(l737)) {
                                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                }
                                l738 = l19 == INT32_C(108);
                                l739 = vader_vm_operand_a(l20);
                                if (l738) {
                                    l740 = INT64_C(0);
                                    t2 = vader_vm_operand_b(l20);
                                    l741 = ((int64_t) (int32_t) t2);
                                    while ((l740 < l741)) {
                                        l742 = vader_chk_add(i64, l12, l740);
                                        l743 = ((int64_t) (int32_t) l739);
                                        t6 = vader_chk_add(i64, l12, l743);
                                        l744 = vader_chk_add(i64, t6, l740);
                                        vader_vm_move_register(l2, l742, l744);
                                        l740 = (l740 + INT64_C(1));
                                    }
                                } else if ((l739 >= INT32_C(0))) {
                                    l745 = ((int64_t) (int32_t) l739);
                                    l746 = vader_chk_add(i64, l12, l745);
                                    vader_vm_move_register(l2, l12, l746);
                                }
                                l11 = vader_chk_sub(i64, l11, INT64_C(1));
                                if (l11 == l5) {
                                    if (l738) {
                                        if (l5 == INT64_C(0)) {
                                            vader_struct_vader_vm_Trap_t* _a81_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
                                            vader_obj_header_init(_a81_obj, 1308u);
                                            _a81_obj->f_message = 2335u;
                                            t1 = (void*) _a81_obj;
                                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                                    }
                                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                                }
                                vader_array_t* _a82_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_return);
                                VADER_ARRAY_RESOLVE_BUF(_a82_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a82_slotarr, l11)
                                l13 = ((int64_t*) _a82_slotarr->buf->slots)[_a82_slotarr->offset + (size_t) l11];
                                l747 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_base;
                                l748 = vader_chk_sub(i64, l11, INT64_C(1));
                                vader_array_t* _a83_slotarr = ((vader_array_t*) l747);
                                VADER_ARRAY_RESOLVE_BUF(_a83_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a83_slotarr, l748)
                                l12 = ((int64_t*) _a83_slotarr->buf->slots)[_a83_slotarr->offset + (size_t) l748];
                                l749 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_frame_code;
                                l750 = vader_chk_sub(i64, l11, INT64_C(1));
                                vader_array_t* _a84_slotarr = ((vader_array_t*) l749);
                                VADER_ARRAY_RESOLVE_BUF(_a84_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a84_slotarr, l750)
                                l8 = vader_array_ref_load_obj(_a84_slotarr->buf, _a84_slotarr->offset + (size_t) l750);
                                l14 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_ops;
                                l15 = ((vader_struct_vader_vm_RegFunction_t*) l8)->f_words;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        l13 = vader_chk_add(i64, l13, INT64_C(1));
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm_reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6) {
    void* l7 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    int32_t l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    int64_t l21, l22;
    bool l23;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l4, &l6, &l9, &l10, &t2 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l3, &l7, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 15u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l8 = ((vader_struct_vader_vm_VmState_t*) l0)->f_string_array_type_id;
    l9 = vader_vm_build_main_args(l7, l3, l8);
    if (l9.tag == 1308u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 0u) {
        l10 = vader_box_obj(0u, NULL);
    } else {
        t0 = l6.payload.obj;
        vader_struct_vader_vm_DebugSession_t* _a1_obj = (vader_struct_vader_vm_DebugSession_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_DebugSession_t));
        vader_obj_header_init(_a1_obj, 1283u);
        _a1_obj->f_controller = t0;
        _a1_obj->f_last_line = INT32_C(-1);
        _a1_obj->f_step_mode = (uint8_t) 0;
        _a1_obj->f_step_depth = INT32_C(0);
        t0 = (void*) _a1_obj;
        l10 = vader_ref_box(t0);
    }
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 8u, 291u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(17u, 0u, 1u, 292u);
    l12 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l13 = (void*) _a4_arr;
    l14 = vader_vm_new_run_host();
    l15 = vader_vm_scratch_frame();
    vader_array_t* _a5_arr = vader_array_new(211u, 0u, 13u, 1299u);
    l16 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 8u, 291u);
    l17 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 8u, 291u);
    l18 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l19 = (void*) _a8_arr;
    vader_struct_vader_vm_NullVal_t* _a9_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
    vader_obj_header_init(_a9_obj, 1292u);
    l20 = (void*) _a9_obj;
    vader_struct_vader_vm_RegMachine_t* _a10_obj = (vader_struct_vader_vm_RegMachine_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RegMachine_t));
    vader_obj_header_init(_a10_obj, 1300u);
    _a10_obj->f_bits = l11;
    _a10_obj->f_tags = l12;
    _a10_obj->f_refs = l13;
    _a10_obj->f_run = l14;
    _a10_obj->f_scratch = l15;
    _a10_obj->f_frame_code = l16;
    _a10_obj->f_frame_base = l17;
    _a10_obj->f_frame_return = l18;
    _a10_obj->f_defers = l19;
    _a10_obj->f_defer_count = INT64_C(0);
    _a10_obj->f_debug = l10;
    _a10_obj->f_null_value = vader_ref_box(l20);
    l11 = (void*) _a10_obj;
    vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l2);
    l21 = ((vader_struct_vader_vm_RegFunction_t*) t0)->f_registers;
    vader_vm_reserve_registers(l11, l21);
    l21 = INT64_C(0);
    t0 = l9.payload.obj;
    l22 = ((vader_array_t*) t0)->length;
    while ((l21 < l22)) {
        t0 = l9.payload.obj;
        vader_array_t* _a12_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l21)
        l10 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l21];
        vader_vm_set_register(l11, l21, l10);
        l21 = (l21 + INT64_C(1));
    }
    l9 = vader_vm_reg_call(l0, l1, l11, l2, INT64_C(0), INT64_C(0), INT64_C(0), l5);
    if (!(l9.tag == 1308u)) {
        t1 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_signature);
        l23 = t1 == INT64_C(1);
        t2 = vader_vm_finish_run(l11, l23, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_vm_unwind(l0, l1, l11, l5);
    t0 = l9.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_register_value(void* l0, int64_t l1) {
    uint8_t l2;
    vader_box_t l3;
    uint32_t l4;
    bool l5;
    vader_box_t t0;
    int64_t t1;
    int32_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
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
        l3 = vader_box_i32(290u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(291u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(297u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(285u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        t1 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1];
        t2 = ((int32_t) (int64_t) t1);
        l4 = (uint32_t) (int32_t) t2;
        if ((l4 > INT32_C(55295))) {
            if ((l4 < INT32_C(57344))) {
                l5 = true;
            } else {
                l5 = (l4 > INT32_C(1114111));
            }
            if (l5) {
                vader_unreachable("value out of range: no Unicode scalar value");
            }
        }
        l3 = vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l4));
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

static void vader_vm_reserve_registers(void* l0, int64_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t t0;
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
            vader_obj_header_init(_a0_obj, 1292u);
            l3 = (void*) _a0_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm_reserve_stack(void* l0, int64_t l1) {
    int64_t t0;
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

static void vader_vm_reset_stack(void* l0, int64_t l1) {
    int64_t l2;
    int32_t l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_clear((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
    l2 = INT64_C(0);
    while ((l2 < l1)) {
        l3 = vader_vm_canonical(l0, l2);
        vader_vm_push_register(l0, l3);
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_resolve_virtual(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5) {
    int64_t l6, l7, l15, l16;
    void* l8 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    int32_t l9, l10, l12, l21;
    vader_box_t l11 = vader_box_null(), l24 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    bool l18;
    uint8_t l23;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[2] = { &l11, &l24 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l8, &l17, &l19, &l20, &l22, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l13, &l14, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    t0 = vader_vm_operand_a(l6);
    l7 = ((int64_t) (int32_t) t0);
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
    l6 = ((int64_t) (int32_t) t0);
    t1 = vader_chk_add(i64, l4, l6);
    l7 = vader_chk_sub(i64, t1, INT64_C(1));
    l11 = vader_vm_register_value(l1, l7);
    l12 = vader_vm_receiver_type_id_of(l0, l11);
    if ((l12 < INT32_C(0))) {
        l14 = vader_vm_describe_value_tag(l11);
        l13 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
        l15 = vader_host_std_core_byte_len(l13);
        l16 = vader_host_std_core_byte_len(l14);
        l15 = (l15 + l16);
        l17 = (void*) vader_buffer_new((size_t) (INT64_C(73) + l15));
        l15 = INT64_C(0);
        l15 = std_core_write_string_at(l17, l15, 2791u);
        l15 = std_core_write_string_at(l17, l15, l13);
        l15 = std_core_write_string_at(l17, l15, 239u);
        l15 = std_core_write_string_at(l17, l15, l14);
        l15 = std_core_write_string_at(l17, l15, 93u);
        l16 = ((int64_t) (int32_t) l10);
        l15 = std_core_write_int(l17, l15, l16);
        t2 = std_core_finish_buffer(l17, l15);
        vader_struct_vader_vm_Trap_t* _a4_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a4_obj, 1308u);
        _a4_obj->f_message = t2;
        t3 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm_lookup_vtable_row(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables, l9, l12);
    while ((l7 > l4)) {
        l15 = vader_chk_sub(i64, l7, INT64_C(1));
        vader_vm_move_register(l1, l7, l15);
        l7 = vader_chk_sub(i64, l7, INT64_C(1));
    }
    vader_vm_set_register(l1, l4, l11);
    if ((l9 >= INT32_C(0))) {
        l17 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
        t4 = vader_vm_is_fn_index_out_of_range(l9, l17);
        if (t4) {
            l13 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
            l13 = concat_3(2791u, l13, 234u);
            t3 = vader_vm_fn_index_trap(l9, l10, l13);
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l17 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l17)->f_signature)->f_params)->length;
        if (!(t1 != l6)) {
            { vader_box_t __vret = vader_box_i32(290u, l9); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l17)->f_signature)->f_params)->length;
        l13 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
        l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l17)->f_name;
        l15 = vader_host_std_core_byte_len(l13);
        l16 = vader_host_std_core_byte_len(l14);
        l15 = (l15 + l16);
        l17 = (void*) vader_buffer_new((size_t) (INT64_C(134) + l15));
        l15 = INT64_C(0);
        l15 = std_core_write_string_at(l17, l15, 2791u);
        l15 = std_core_write_string_at(l17, l15, l13);
        l15 = std_core_write_string_at(l17, l15, 237u);
        l15 = std_core_write_string_at(l17, l15, l14);
        l15 = std_core_write_string_at(l17, l15, 242u);
        l15 = std_core_write_int(l17, l15, l7);
        l15 = std_core_write_string_at(l17, l15, 144u);
        l15 = std_core_write_int(l17, l15, l6);
        l15 = std_core_write_string_at(l17, l15, 66u);
        l7 = ((int64_t) (int32_t) l10);
        l15 = std_core_write_int(l17, l15, l7);
        t2 = std_core_finish_buffer(l17, l15);
        vader_struct_vader_vm_Trap_t* _a6_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a6_obj, 1308u);
        _a6_obj->f_message = t2;
        t3 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l13 = vader_vm_primitive_kind_at(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types, l12);
    l14 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
    l14 = vader_vm_intrinsic_host_mangle(l13, l14);
    if (l13 == 0u) {
        l18 = true;
    } else {
        l18 = l14 == 0u;
    }
    if (l18) {
        l13 = ((vader_struct_vader_bytecode_VirtualCall_t*) l8)->f_vtable_key;
        l7 = vader_host_std_core_byte_len(l13);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(82) + l7));
        l7 = INT64_C(0);
        l7 = std_core_write_string_at(l8, l7, 2791u);
        l7 = std_core_write_string_at(l8, l7, l13);
        l7 = std_core_write_string_at(l8, l7, 238u);
        l15 = ((int64_t) (int32_t) l12);
        l7 = std_core_write_int(l8, l7, l15);
        l7 = std_core_write_string_at(l8, l7, 66u);
        l15 = ((int64_t) (int32_t) l10);
        l7 = std_core_write_int(l8, l7, l15);
        t2 = std_core_finish_buffer(l8, l7);
        vader_struct_vader_vm_Trap_t* _a7_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a7_obj, 1308u);
        _a7_obj->f_message = t2;
        t3 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_vm_primitive_impl_import(l14, l6);
    vader_array_t* _a8_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l17 = (void*) _a8_arr;
    if ((INT64_C(0) < l6)) {
        l7 = l6;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l17, (int64_t) l7);
    l17 = (void*) _a9_arr;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        l15 = vader_chk_add(i64, l4, l7);
        l11 = vader_vm_register_value(l1, l15);
        vader_array_push((vader_array_t*) l17, l11);
        l7 = (l7 + INT64_C(1));
    }
    l19 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_gc_state;
    l20 = ((vader_struct_vader_vm_RunHost_t*) ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run)->f_sched_state;
    l9 = ((vader_struct_vader_vm_VmState_t*) l0)->f_string_array_type_id;
    l12 = ((vader_struct_vader_vm_VmState_t*) l0)->f_u8_array_type_id;
    l21 = ((vader_struct_vader_vm_VmState_t*) l0)->f_io_error_type_id;
    l22 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types;
    l11 = vader_vm_debug_controller(l1);
    l23 = vader_bytecode_intrinsic_id_for(l14);
    l11 = vader_vm_dispatch_import(l8, l17, INT64_C(0), l19, l20, l10, l9, l12, l21, l22, l5, l11, l23);
    if (!(l11.tag == 1308u)) {
        t3 = l11.payload.obj;
        l24 = ((vader_struct_vader_vm_HostOk_t*) t3)->f_value;
        vader_vm_set_register(l1, l4, l24);
        { vader_box_t __vret = vader_box_i32(290u, INT32_C(-1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l11.payload.obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_return_many(void* l0, int64_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    int32_t l6, l8;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_vm_flush(l0, l1);
    l3 = ((vader_array_t*) l2)->length;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    l4 = vader_chk_sub(i64, t0, l3);
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 292u);
        l6 = vader_vm_narrow_code(((uint8_t) t1.payload.i));
        if ((l6 >= INT32_C(0))) {
            l7 = vader_chk_add(i64, l4, l5);
            l8 = vader_vm_canonical(l0, l7);
            vader_vm_emit(l0, l1, INT32_C(106), l8, l6, INT32_C(0));
        }
        l5 = (l5 + INT64_C(1));
    }
    l6 = vader_vm_canonical(l0, l4);
    l8 = ((int32_t) (int64_t) l3);
    vader_vm_emit(l0, l1, INT32_C(108), l6, l8, INT32_C(0));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_vm_returns_void(void* l0, int32_t l1) {
    int64_t l2;
    vader_box_t l3;
    bool t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (!(t0)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 650u) {
        t1 = l3.payload.obj;
        return ((vader_struct_vader_bytecode_BcScalar_t*) t1)->f_val == INT32_C(14);
    }
    return false;
}

static vader_box_t vader_vm_retyped_int(vader_box_t l0, int64_t l1) {
    uint32_t l2;
    bool l3;
    int32_t t0;
    if (l0.tag == 291u) {
        return vader_box_i64(291u, l1);
    }
    if (l0.tag == 285u) {
        return vader_box_bool(285u, l1 != INT64_C(0));
    }
    if (!(l0.tag == 286u)) {
        return vader_box_i32(290u, ((int32_t) (int64_t) l1));
    }
    t0 = ((int32_t) (int64_t) (l1 & INT64_C(4294967295)));
    l2 = (uint32_t) (int32_t) t0;
    if ((l2 > INT32_C(55295))) {
        if ((l2 < INT32_C(57344))) {
            l3 = true;
        } else {
            l3 = (l2 > INT32_C(1114111));
        }
        if (l3) {
            vader_unreachable("value out of range: no Unicode scalar value");
        } else {
            return vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l2));
        }
    } else {
        return vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l2));
    }
}

static vader_box_t vader_vm_run_boxed(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5) {
    int64_t l6, l7, l8, l9, l11, l14, l15, l18, l22;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    uint8_t l19;
    vader_box_t l23 = vader_box_null();
    int32_t l24;
    vader_string_t l25 = 0;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l23, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l10, &l12, &l13, &l16, &l17, &l20, &l21, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l25 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    t0 = vader_vm_operand_b(l6);
    l7 = ((int64_t) (int32_t) t0);
    l7 = vader_chk_add(i64, l4, l7);
    t0 = vader_vm_operand_c(l6);
    l8 = ((int64_t) (int32_t) (t0 & INT32_C(255)));
    t0 = vader_vm_operand_c(l6);
    l9 = ((int64_t) (int32_t) (t0 >> INT32_C(8)));
    l10 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_scratch;
    vader_vm_reserve_stack(l10, l8);
    l11 = INT64_C(0);
    while ((l11 < l8)) {
        l12 = ((vader_struct_vader_vm_Frame_t*) l10)->f_payload;
        l13 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_bits;
        l14 = vader_chk_add(i64, l7, l11);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l14)
        l15 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l14];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l11] = (int64_t) l15;
        l16 = ((vader_struct_vader_vm_Frame_t*) l10)->f_tag;
        l17 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_tags;
        l18 = vader_chk_add(i64, l7, l11);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l18)
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l18, 292u);
        l19 = ((uint8_t) t1.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11] = (uint8_t) (int32_t) (uint8_t) l19;
        l20 = ((vader_struct_vader_vm_Frame_t*) l10)->f_stack;
        l21 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_refs;
        l22 = vader_chk_add(i64, l7, l11);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l21);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l22)
        l23 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l22];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l20);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
        vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l11] = l23;
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        l11 = (l11 + INT64_C(1));
    }
    ((vader_struct_vader_vm_Frame_t*) l10)->f_sp = l8;
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
    l24 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3];
    ((vader_struct_vader_vm_Frame_t*) l10)->f_pc = l24;
    l12 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_run;
    l13 = ((vader_struct_vader_vm_RegFunction_t*) l2)->f_boxed;
    l24 = vader_vm_operand_a(l6);
    vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l24)
    l23 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l24);
    l25 = ((vader_struct_vader_vm_RegFunction_t*) l2)->f_name;
    l23 = vader_vm_apply_boxed(l0, l12, l23, l10, l25, l5);
    if (l23.tag == 1308u) {
        t2 = l23.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = INT64_C(0);
    while ((l6 < l9)) {
        l12 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_bits;
        l8 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l10)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        l11 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6];
        vader_array_t* _a10_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
        ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8] = (int64_t) l11;
        l13 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_tags;
        l14 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l10)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
        t1 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l6, 292u);
        l19 = ((uint8_t) t1.payload.i);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l14)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l14] = (uint8_t) (int32_t) (uint8_t) l19;
        l16 = ((vader_struct_vader_vm_RegMachine_t*) l1)->f_refs;
        l15 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l10)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        l23 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l6];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l15)
        vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l15] = l23;
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_run_defers(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
    int32_t l8, l9;
    int64_t l10, l11, l13;
    void* l12 = NULL;
    void* l16 = NULL;
    vader_box_t l14 = vader_box_null(), l15 = vader_box_null();
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l14, &l15 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l12, &l16, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
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
    l11 = ((int64_t) (int32_t) l8);
    if ((l10 < l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(107));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l12, l10, 1661u);
        l11 = ((int64_t) (int32_t) l8);
        l10 = std_core_write_int(l12, l10, l11);
        l10 = std_core_write_string_at(l12, l10, 314u);
        l11 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
        l10 = std_core_write_int(l12, l10, l11);
        l10 = std_core_write_string_at(l12, l10, 276u);
        l11 = ((int64_t) (int32_t) l9);
        l10 = std_core_write_int(l12, l10, l11);
        t1 = std_core_finish_buffer(l12, l10);
        vader_struct_vader_vm_Trap_t* _a2_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a2_obj, 1308u);
        _a2_obj->f_message = t1;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
    l11 = ((int64_t) (int32_t) l8);
    l10 = vader_chk_sub(i64, l10, l11);
    vader_array_t* _a3_arr = vader_array_new(203u, 0u, 13u, 1285u);
    l12 = (void*) _a3_arr;
    l11 = l10;
    l13 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
    while ((l11 < l13)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l14 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l11];
        l15 = vader_vm_defer_thunk(l0, l14, l9, 1659u);
        if (l15.tag == 1308u) {
            t2 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = l15.payload.obj;
        vader_array_push((vader_array_t*) l12, vader_ref_box(l16));
        l11 = (l11 + INT64_C(1));
    }
    ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count = l10;
    l10 = ((vader_array_t*) l12)->length;
    while ((l10 > INT64_C(0))) {
        l10 = vader_chk_sub(i64, l10, INT64_C(1));
        vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        l16 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l10);
        l11 = vader_chk_add(i64, l4, INT64_C(1));
        l14 = vader_vm_run_thunk(l0, l1, l2, l16, l5, l6, l11, l7);
        if (!(l14.tag == 0u)) {
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm_run_thunk(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
    int64_t l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l8 = vader_chk_add(i64, l4, INT64_C(1));
    vader_vm_reserve_registers(l2, l8);
    if (((vader_struct_vader_vm_FnVal_t*) l3)->f_env.tag == 0u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l2)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4] = (uint8_t) INT32_C(5);
        l10 = ((vader_struct_vader_vm_FnVal_t*) l3)->f_function_index;
        t0 = vader_vm_reg_call(l0, l1, l2, l10, l4, l5, l6, l7);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_vm_FnVal_t*) l3)->f_env;
    vader_vm_set_register(l2, l4, l9);
    l10 = ((vader_struct_vader_vm_FnVal_t*) l3)->f_function_index;
    t0 = vader_vm_reg_call(l0, l1, l2, l10, l4, l5, l6, l7);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 714u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a0_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a0_obj, 1303u);
        _a0_obj->f_bits = ((int64_t) (int32_t) t1);
        _a0_obj->f_tag = (uint8_t) 0;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 734u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a1_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a1_obj, 1303u);
        _a1_obj->f_bits = t2;
        _a1_obj->f_tag = (uint8_t) 1;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 693u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a2_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a2_obj, 1303u);
        _a2_obj->f_bits = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t3 }).__vu);
        _a2_obj->f_tag = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 663u) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        if (t4) {
            l2 = INT64_C(1);
        } else {
            l2 = INT64_C(0);
        }
        vader_struct_vader_vm_Scalar_t* _a3_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a3_obj, 1303u);
        _a3_obj->f_bits = l2;
        _a3_obj->f_tag = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 678u) {
        t0 = l0.payload.obj;
        t5 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        vader_struct_vader_vm_Scalar_t* _a4_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a4_obj, 1303u);
        _a4_obj->f_bits = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        _a4_obj->f_tag = (uint8_t) 4;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 765u) {
        vader_struct_vader_vm_Scalar_t* _a5_obj = (vader_struct_vader_vm_Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Scalar_t));
        vader_obj_header_init(_a5_obj, 1303u);
        _a5_obj->f_bits = INT64_C(0);
        _a5_obj->f_tag = (uint8_t) 5;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 783u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm_scratch_frame(void) {
    int64_t l0;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = INT64_C(8);
    l1 = (void*) &vader_fn_static___lambda_vader_vm_5;
    l1 = std_core_filled__vader_vm_ArrayVal___bool___char___vader_vm_ErrorVal___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(17u, 1u, 1u, 292u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(5);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l3 = (void*) _a3_arr;
    vader_struct_vader_vm_Frame_t* _a4_obj = (vader_struct_vader_vm_Frame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Frame_t));
    vader_obj_header_init(_a4_obj, 1286u);
    _a4_obj->f_stack = l1;
    _a4_obj->f_payload = l2;
    _a4_obj->f_tag = l3;
    _a4_obj->f_sp = INT64_C(0);
    _a4_obj->f_pc = INT32_C(0);
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_serialise_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7) {
    vader_string_t l8 = 0;
    vader_string_t l14 = 0;
    vader_string_t l35 = 0;
    vader_string_t l36 = 0;
    int64_t l9, l11, l15, l16, l17, l19, l20, l21, l22, l27, l37, l38, l39;
    void* l10 = NULL;
    void* l18 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l26 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null(), l34 = vader_box_null();
    int32_t l25;
    bool l31, l32, l33;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[7] = { &l12, &l13, &l26, &l28, &l29, &l30, &l34 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l4, &l10, &l18, &l23, &l24, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l6, &l8, &l14, &l35, &l36, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        l8 = l6;
        l9 = vader_host_std_core_byte_len(l8);
        l10 = (void*) vader_buffer_new((size_t) (INT64_C(83) + l9));
        l9 = INT64_C(0);
        l9 = std_core_write_string_at(l10, l9, 1772u);
        l9 = std_core_write_string_at(l10, l9, l8);
        l9 = std_core_write_string_at(l10, l9, 939u);
        l11 = ((int64_t) (int32_t) l5);
        l9 = std_core_write_int(l10, l9, l11);
        l9 = std_core_write_string_at(l10, l9, 420u);
        l9 = std_core_write_int(l10, l9, INT64_C(16));
        t0 = std_core_finish_buffer(l10, l9);
        vader_struct_vader_vm_Trap_t* _a0_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a0_obj, 1308u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_bytecode_c_struct_layout(l3, l4);
    l9 = INT64_C(0);
    l11 = ((vader_array_t*) l3)->length;
    while ((l9 < l11)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l12 = vader_bytecode_nested_mirror(t1, l4);
        if (l12.tag == 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l28 = vader_bytecode_c_field_width(t1, l4);
            if (l28.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l27 = ((int64_t) l28.payload.i);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l29 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l9];
            if (l29.tag == 291u) {
                l31 = true;
            } else {
                l31 = l29.tag == 290u;
            }
            if (l31) {
                l32 = true;
            } else {
                l32 = l29.tag == 285u;
            }
            if (l32) {
                l33 = true;
            } else {
                l33 = l29.tag == 286u;
            }
            if (l33) {
                l30 = vader_vm_read_scalar_word(l29, l5, 0u);
            } else {
                l34 = l29;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                l35 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
                l36 = concat_5(1772u, l6, 965u, l35, 916u);
                l30 = vader_vm_read_scalar_word(l34, l5, l36);
            }
            if (l30.tag == 1308u) {
                t1 = l30.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l10)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            l37 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9];
            l38 = vader_chk_add(i64, l1, l37);
            l39 = ((int64_t) l30.payload.i);
            vader_vm_write_little_endian(l0, l38, l39, l27);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        l13 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l9];
        if (!(l13.tag == 1305u)) {
            l8 = l6;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            l14 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
            l15 = vader_host_std_core_byte_len(l8);
            l16 = vader_host_std_core_byte_len(l14);
            l17 = (l15 + l16);
            l18 = (void*) vader_buffer_new((size_t) (INT64_C(91) + l17));
            l19 = INT64_C(0);
            l19 = std_core_write_string_at(l18, l19, 1772u);
            l19 = std_core_write_string_at(l18, l19, l8);
            l19 = std_core_write_string_at(l18, l19, 939u);
            l20 = ((int64_t) (int32_t) l5);
            l19 = std_core_write_int(l18, l19, l20);
            l19 = std_core_write_string_at(l18, l19, 418u);
            l19 = std_core_write_string_at(l18, l19, l14);
            l19 = std_core_write_string_at(l18, l19, 1058u);
            t0 = std_core_finish_buffer(l18, l19);
            vader_struct_vader_vm_Trap_t* _a8_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
            vader_obj_header_init(_a8_obj, 1308u);
            _a8_obj->f_message = t0;
            t1 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l10)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
        l21 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9];
        l22 = vader_chk_add(i64, l1, l21);
        l23 = l13.payload.obj;
        t1 = l12.payload.obj;
        l24 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
        l25 = vader_chk_add(i32, l7, INT32_C(1));
        l26 = vader_vm_serialise_mirror(l0, l22, l23, l24, l4, l5, l6, l25);
        if (l26.tag == 1308u) {
            t1 = l26.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm_set_bool(void* l0, void* l1, int64_t l2, int32_t l3, bool l4) {
    int64_t l5, l6;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
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

static void vader_vm_set_char_code(void* l0, void* l1, int64_t l2, int32_t l3, uint32_t l4) {
    int64_t l5, l6;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
    l6 = ((int64_t) (uint32_t) l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5] = (uint8_t) INT32_C(4);
    return;
}

static vader_box_t vader_vm_set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6, int32_t l7) {
    int64_t l8, l14;
    void* l9 = NULL;
    void* l11 = NULL;
    vader_box_t l10 = vader_box_null();
    int32_t l12;
    bool l13;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[5] = { &l0, &l5, &l9, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l8 = ((int64_t) (int32_t) l2);
    l8 = vader_chk_add(i64, l1, l8);
    l10 = vader_vm_array_at(l0, l8);
    if (l10.tag == 0u) {
        t0 = vader_vm_element_trap(l0, l1, l2, l3, l5, l6, l7);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    l8 = ((int64_t) (int32_t) l3);
    l8 = vader_chk_add(i64, l1, l8);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
    l12 = ((int32_t) (int64_t) t1);
    if ((l12 < INT32_C(0))) {
        l13 = true;
    } else {
        l8 = ((int64_t) (int32_t) l12);
        l14 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_length;
        l13 = (l8 >= l14);
    }
    if (!(l13)) {
        vader_vm_own_bytes(l9);
        l11 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_elements;
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l9)->f_offset;
        l14 = ((int64_t) (int32_t) l12);
        l8 = vader_chk_add(i64, l8, l14);
        l14 = ((int64_t) (int32_t) l4);
        l14 = vader_chk_add(i64, l1, l14);
        l10 = vader_vm_register_value(l0, l14);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8] = l10;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_vm_element_trap(l0, l1, l2, l3, l5, l6, l7);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_set_f64(void* l0, void* l1, int64_t l2, int32_t l3, double l4) {
    int64_t l5, l6;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
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

static vader_box_t vader_vm_set_field(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6) {
    void* l7 = NULL;
    void* l13 = NULL;
    int64_t l8, l11, l12, l14;
    vader_box_t l9 = vader_box_null(), l15 = vader_box_null();
    bool l10;
    int32_t l16;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l9, &l15 };
    void** gc_raw_roots[5] = { &l0, &l5, &l7, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs;
    l8 = ((int64_t) (int32_t) l2);
    l8 = vader_chk_add(i64, l1, l8);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    l9 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
    if (l9.tag == 1305u) {
        if ((l4 < INT32_C(0))) {
            l10 = true;
        } else {
            l8 = ((int64_t) (int32_t) l4);
            t0 = l9.payload.obj;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t0)->f_fields)->length;
            l10 = (l8 >= l11);
        }
        if (!(l10)) {
            t0 = l9.payload.obj;
            l13 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_fields;
            l12 = ((int64_t) (int32_t) l3);
            l14 = vader_chk_add(i64, l1, l12);
            l15 = vader_vm_register_value(l0, l14);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4] = l15;
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l9.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_vm_StructVal_t*) t0)->f_fields)->length;
        l7 = (void*) vader_buffer_new((size_t) INT64_C(118));
        l11 = INT64_C(0);
        l11 = std_core_write_string_at(l7, l11, 2471u);
        l12 = ((int64_t) (int32_t) l4);
        l11 = std_core_write_int(l7, l11, l12);
        l11 = std_core_write_string_at(l7, l11, 140u);
        l11 = std_core_write_int(l7, l11, l8);
        l11 = std_core_write_string_at(l7, l11, 83u);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l5)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l8 = ((int64_t) (int32_t) t1);
        l11 = std_core_write_int(l7, l11, l8);
        t2 = std_core_finish_buffer(l7, l11);
        vader_struct_vader_vm_Trap_t* _a3_obj = (vader_struct_vader_vm_Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Trap_t));
        vader_obj_header_init(_a3_obj, 1308u);
        _a3_obj->f_message = t2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l5)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
    l16 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
    l9 = vader_vm_read_struct(l9, l16, 2473u);
    if (l9.tag == 1308u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm_set_i32(void* l0, void* l1, int64_t l2, int32_t l3, int32_t l4) {
    int64_t l5, l6;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
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

static void vader_vm_set_i64(void* l0, void* l1, int64_t l2, int32_t l3, int64_t l4) {
    int64_t l5;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
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

static void vader_vm_set_integer(void* l0, void* l1, int64_t l2, int32_t l3, uint8_t l4, int64_t l5) {
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

static void vader_vm_set_register(void* l0, int64_t l1, vader_box_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t t0;
    double t1;
    bool t2;
    uint32_t t3;
    if (l2.tag == 290u) {
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
    if (l2.tag == 291u) {
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
    } else if ((l2.tag == 296u || l2.tag == 297u)) {
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
    } else if (l2.tag == 285u) {
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
    } else if (l2.tag == 286u) {
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
    } else if (l2.tag == 1292u) {
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

static bool vader_vm_skips_else(void* l0, int64_t l1) {
    bool l2;
    int64_t l3, l4;
    void* l5;
    vader_box_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (t0.tag == 749u) {
        l3 = vader_chk_add(i64, l1, INT64_C(1));
        l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
        l2 = (l3 < l4);
    } else {
        l2 = false;
    }
    if (l2) {
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
        l3 = vader_chk_add(i64, l1, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        return t0.tag == 687u;
    }
    return false;
}

static bool vader_vm_slot_in_scope(void* l0, void* l1, int64_t l2, int32_t l3) {
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
    if (l0.tag == 759u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 760u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 761u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 758u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
    return t1;
}

static uint8_t vader_vm_slot_valtype(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l3 = ((int64_t) (int32_t) l1);
    if ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 292u);
        return ((uint8_t) t0.payload.i);
    }
    l2 = vader_chk_sub(i64, l3, l2);
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    if (!((l2 < l3))) {
        return (uint8_t) 2;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    return ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
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
    vader_obj_header_init(_a0_obj, 1292u);
    l2 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_stack_i32(void* l0, int64_t l1, vader_string_t l2, vader_string_t l3) {
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
    t1 = vader_vm_is_i32_tag(((uint8_t) t0.payload.i));
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = vader_box_i32(290u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm_peek_val(l0, l1);
    l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l6 = concat_3(l2, 10u, l3);
    l4 = vader_vm_read_i32(l4, l5, l6);
    if (l4.tag == 1308u) {
        t3 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((int32_t) l4.payload.i);
    { vader_box_t __vret = vader_box_i32(290u, t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_stack_obj(void* l0, int64_t l1, vader_string_t l2) {
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
    if (!(l3.tag == 1293u)) {
        l4 = l3;
        l5 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l6 = concat_2(l2, 151u);
        t0 = vader_vm_read_obj(l4, l5, l6);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_stack_tags(void* l0, int64_t l1, int64_t l2) {
    int64_t l3, l5;
    void* l4;
    int64_t t0;
    vader_box_t t1;
    uint8_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l0)->f_depth);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l3 = vader_chk_sub(i64, t0, l2);
    l4 = ((vader_struct_vader_vm_FunctionTags_t*) l0)->f_stack;
    l5 = ((vader_struct_vader_vm_FunctionTags_t*) l0)->f_deepest;
    t0 = vader_chk_mul(i64, l1, l5);
    l3 = vader_chk_add(i64, t0, l3);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 292u);
    t2 = ((uint8_t) t1.payload.i);
    return t2;
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

static void vader_vm_stop_at_line(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5) {
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l7, l10;
    vader_box_t l9 = vader_box_null();
    vader_string_t l11 = 0;
    bool l12;
    uint8_t l13;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_functions;
    l7 = ((vader_struct_vader_vm_RegFunction_t*) l3)->f_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    l8 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_debug;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) l3)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l7 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
    if (l9.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = l9.payload.obj;
    l7 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_line;
    l10 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_last_line;
    if (l7 == l10) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_line;
    ((vader_struct_vader_vm_DebugSession_t*) l2)->f_last_line = l7;
    l7 = ((int32_t) (int64_t) l5);
    l8 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_controller;
    l11 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_file;
    l10 = ((vader_struct_vader_bytecode_DebugPos_t*) l6)->f_line;
    l12 = vader_vm_line_has_breakpoint(l8, l11, l10);
    if (!(l12)) {
        l13 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_mode;
        l10 = ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_depth;
        t1 = vader_vm_step_should_stop(l13, l10, l7);
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l12) {
        l11 = 1491u;
    } else {
        l11 = 2433u;
    }
    l6 = ((vader_struct_vader_vm_DebugController_t*) ((vader_struct_vader_vm_DebugSession_t*) l2)->f_controller)->f_on_pause;
    t0 = vader_vm_pause_context(l0, l1, l11, l4, l5);
    vader_fn_t* _a3_fnobj = (vader_fn_t*) l6;
    t2 = ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_ref_box(t0));
    l13 = ((uint8_t) t2.payload.i);
    ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_mode = l13;
    ((vader_struct_vader_vm_DebugSession_t*) l2)->f_step_depth = l7;
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_store_bytes_op(void* l0, int64_t l1, uint64_t l2, vader_string_t l3) {
    int64_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    int32_t l7, l8;
    void* l9 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l9, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm_stack_i32(l0, l4, l3, 2232u);
    if (l5.tag == 1308u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(3));
    l6 = vader_vm_stack_obj(l0, l4, l3);
    if (l6.tag == 1308u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l5.payload.i);
    t1 = l6.payload.obj;
    l4 = ((vader_array_t*) ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
    l5 = vader_vm_check_byte_range(l7, l1, l4, l3, l8);
    if (!(l5.tag == 1308u)) {
        t1 = l6.payload.obj;
        l9 = ((vader_struct_vader_vm_ObjVal_t*) t1)->f_bytes;
        l4 = ((int64_t) l5.payload.i);
        vader_vm_write_le(l9, l4, l1, l2);
        t0 = ((vader_struct_vader_vm_Frame_t*) l0)->f_sp;
        l4 = vader_chk_sub(i64, t0, INT64_C(3));
        ((vader_struct_vader_vm_Frame_t*) l0)->f_sp = l4;
        t2 = ((vader_struct_vader_vm_Frame_t*) l0)->f_pc;
        l7 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm_Frame_t*) l0)->f_pc = l7;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l5.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm_store_slot(void* l0, void* l1, int64_t l2, int32_t l3, bool l4, int64_t l5) {
    int64_t l6, l8, l9;
    int32_t l7, l12, l13;
    void* l10 = NULL;
    void* l14 = NULL;
    bool l11;
    int64_t t0;
    uint8_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l10, &l14, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    l6 = vader_chk_sub(i64, t0, INT64_C(1));
    t1 = vader_vm_slot_valtype(l1, l3);
    l7 = vader_vm_narrow_code(t1);
    l8 = l5;
    l9 = INT64_C(0);
    while ((l9 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        if (((vader_struct_vader_vm_Pending_t*) t2)->f_kind == INT32_C(1)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            t3 = ((vader_struct_vader_vm_Pending_t*) t2)->f_register_v;
            if (t3 == l3) {
                vader_vm_materialise(l0, l2, l9);
                l8 = INT64_C(-1);
            }
        }
        l9 = (l9 + INT64_C(1));
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
        l12 = vader_vm_operand_of(l0, l8, INT64_C(0));
        l13 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
        l11 = l12 == l13;
    } else {
        l11 = false;
    }
    if (l11) {
        l14 = ((vader_struct_vader_vm_Translation_t*) l0)->f_operands;
        l6 = vader_chk_mul(i64, INT64_C(3), l8);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l3;
    } else if (((vader_struct_vader_vm_Pending_t*) l10)->f_kind == INT32_C(2)) {
        l12 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
        vader_vm_emit(l0, l2, INT32_C(1), l3, l12, INT32_C(0));
    } else {
        t3 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
        if (t3 != l3) {
            l12 = ((vader_struct_vader_vm_Pending_t*) l10)->f_register_v;
            vader_vm_emit(l0, l2, INT32_C(0), l3, l12, INT32_C(0));
        }
    }
    if ((l7 >= INT32_C(0))) {
        vader_vm_emit(l0, l2, INT32_C(106), l3, l7, INT32_C(0));
    }
    t4 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack);
    if (l4) {
        l10 = ((vader_struct_vader_vm_Translation_t*) l0)->f_stack;
        vader_struct_vader_vm_Pending_t* _a4_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
        vader_obj_header_init(_a4_obj, 1298u);
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
    int64_t l3, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        vader_array_push((vader_array_t*) l2, vader_box_string(287u, l6));
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_array_t*) l2)->length;
    vader_struct_vader_vm_ArrayVal_t* _a3_obj = (vader_struct_vader_vm_ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1280u);
    _a3_obj->f_type_id = l1;
    _a3_obj->f_elements = l2;
    _a3_obj->f_offset = INT64_C(0);
    _a3_obj->f_length = l3;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_string_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    vader_string_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 287u) {
            t1 = l2.payload.s;
            return vader_box_string(287u, t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_vm_string_byte_op(void* l0, int64_t l1, uint8_t l2) {
    int32_t l3, l4, l5;
    int64_t l6;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(1)) {
        t0 = vader_vm_one_argument_string_op(l0, l1, INT32_C(121));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(4)) {
        t0 = vader_vm_one_argument_string_op(l0, l1, INT32_C(124));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        l3 = vader_vm_operand(l0, INT64_C(1));
        l4 = vader_vm_operand(l0, INT64_C(2));
        l5 = vader_vm_pop_to(l0, INT64_C(2));
        vader_vm_emit(l0, l1, INT32_C(122), l5, l4, l3);
        vader_vm_push_register(l0, l5);
        t1 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_code)->f_ops)->length;
        l6 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm_Translation_t*) l0)->f_retarget = l6;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (!(l2 == INT32_C(3))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l0)->f_stack)->length;
    l6 = vader_chk_sub(i64, t1, INT64_C(3));
    vader_vm_materialise(l0, l1, l6);
    l3 = vader_vm_operand(l0, INT64_C(1));
    l4 = vader_vm_operand(l0, INT64_C(2));
    l5 = vader_vm_pop_to(l0, INT64_C(3));
    vader_vm_emit(l0, l1, INT32_C(123), l5, l4, l3);
    vader_vm_push_register(l0, l5);
    { vader_gc_top = gc_frame.prev; return true; }
}

static void vader_vm_string_constant(void* l0, void* l1, int64_t l2, void* l3) {
    int64_t l4;
    int32_t l5, l8;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1, t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l1)->f_stack)->length;
    l5 = vader_vm_canonical(l1, l4);
    l6 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l1)->f_code)->f_values;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings;
    l8 = ((vader_struct_vader_bytecode_StringConst_t*) l3)->f_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
    l9 = t0.payload.s;
    vader_array_push((vader_array_t*) l6, vader_box_string(287u, l9));
    t1 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l1)->f_code)->f_values)->length;
    t2 = vader_chk_sub(i64, t1, INT64_C(1));
    l8 = ((int32_t) (int64_t) t2);
    vader_vm_emit(l1, l2, INT32_C(110), l5, l8, INT32_C(0));
    vader_vm_push_register(l1, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm_struct_new_effect(void* l0, int32_t l1) {
    int64_t l2;
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 653u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l3.payload.obj;
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields)->length;
    t1 = vader_vm_effect(t2, INT64_C(1));
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_tags_of_type(void* l0, int32_t l1) {
    int64_t l2;
    bool t0;
    vader_box_t t1;
    uint8_t t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_type_tags)->length;
    t0 = vader_vm_in_range(l1, l2);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_TagContext_t*) l0)->f_type_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 292u);
        t2 = ((uint8_t) t1.payload.i);
        return t2;
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
        t0 = (INT32_C(1) | INT32_C(16));
        l1 = (uint8_t) (int32_t) t0;
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(15);
    }
    if (l2) {
        t0 = (INT32_C(2) | INT32_C(1));
        l1 = (uint8_t) (int32_t) t0;
    } else {
        if (l0 == INT32_C(8)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l1 = (uint8_t) 4;
        } else if (l0 == INT32_C(10)) {
            l1 = (uint8_t) 8;
        } else if (l0 == INT32_C(11)) {
            l1 = (uint8_t) 16;
        } else if (l0 == INT32_C(13)) {
            l1 = (uint8_t) 32;
        } else {
            if (l0 == INT32_C(12)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(16);
            }
            if (l2) {
                l1 = (uint8_t) 64;
            } else if (l0 == INT32_C(14)) {
                l1 = (uint8_t) 0;
            } else {
                if (!(l0 == INT32_C(17))) {
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
    int64_t l3, l4, l6, l7;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    bool t3;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = INT64_C(0);
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
        l3 = (l3 + INT64_C(1));
    }
    l5 = concat_2(l1, 335u);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_vtables);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        t2 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_key;
        t3 = std_string_starts_with(t2, l5);
        if (t3) {
            l6 = INT64_C(0);
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
                l6 = (l6 + INT64_C(1));
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static int64_t vader_vm_transfer(void* l0, vader_box_t l1, void* l2, int64_t l3, int64_t l4, void* l5) {
    uint8_t l6, l14;
    int64_t l7, l10, l12, l13;
    int32_t l8;
    vader_box_t l9 = vader_box_null();
    void* l11 = NULL;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l5, &l11, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l4 > INT64_C(0))) {
        t0 = vader_chk_add(i64, l3, l4);
        l7 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 292u);
        l6 = ((uint8_t) t1.payload.i);
    } else {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_vm_StackEffect_t*) l5)->f_pops;
    l7 = vader_chk_sub(i64, l4, l7);
    if (l1.tag == 760u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    } else if (l1.tag == 761u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalTee_t*) t2)->f_slot;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    }
    l9 = vader_vm_call_results(l0, l1);
    if (l9.tag == 0u) {
        t0 = ((vader_struct_vader_vm_StackEffect_t*) l5)->f_pushes;
        if (t0 == INT64_C(1)) {
            l10 = vader_chk_add(i64, l3, l7);
            l14 = vader_vm_pushed_tags(l0, l1, l2, l6);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l14;
        }
    } else {
        l10 = vader_chk_add(i64, l3, l7);
        l11 = l9.payload.obj;
        l12 = ((vader_array_t*) l11)->length;
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l13, 292u);
            l6 = ((uint8_t) t1.payload.i);
            if (l6 != INT32_C(14)) {
                l14 = vader_vm_tags_of_val(l6);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l14;
                l10 = vader_chk_add(i64, l10, INT64_C(1));
            }
            l13 = (l13 + INT64_C(1));
        }
    }
    l10 = ((vader_struct_vader_vm_StackEffect_t*) l5)->f_pushes;
    t0 = vader_chk_add(i64, l7, l10);
    { int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_translate_function(void* l0, void* l1, int32_t l2, void* l3, bool l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    int64_t l6, l7, l8, l21, l22, l24, l25;
    vader_string_t l11 = 0;
    int32_t l23, l26, l27, l29;
    vader_box_t l28 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l28, &t1 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l3, &l5, &l9, &l10, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_signature)->f_params)->length;
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals)->length;
    l7 = vader_chk_add(i64, l7, l8);
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 291u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(17u, 0u, 1u, 292u);
    l10 = (void*) _a2_arr;
    vader_vm_collect_constants(l5, l9, l10);
    l8 = ((vader_array_t*) l9)->length;
    l8 = vader_chk_add(i64, l7, l8);
    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 290u);
    l12 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 8u, 291u);
    l13 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 290u);
    l14 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(17u, 0u, 1u, 292u);
    l15 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(247u, 0u, 0u, 1949u);
    l16 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l17 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(59u, 0u, 13u, 806u);
    l18 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(15u, 0u, 7u, 290u);
    l19 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(14u, 0u, 0u, 287u);
    l20 = (void*) _a11_arr;
    l21 = ((vader_struct_vader_vm_FunctionTags_t*) l3)->f_deepest;
    t0 = vader_chk_add(i64, l8, l21);
    l21 = vader_chk_add(i64, t0, INT64_C(1));
    l22 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_signature)->f_params)->length;
    vader_struct_vader_vm_RegFunction_t* _a12_obj = (vader_struct_vader_vm_RegFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RegFunction_t));
    vader_obj_header_init(_a12_obj, 1299u);
    _a12_obj->f_name = l11;
    _a12_obj->f_index = l2;
    _a12_obj->f_ops = l12;
    _a12_obj->f_words = l13;
    _a12_obj->f_origin = l14;
    _a12_obj->f_kinds = l15;
    _a12_obj->f_consts = l9;
    _a12_obj->f_const_tags = l10;
    _a12_obj->f_values = l16;
    _a12_obj->f_boxed = l17;
    _a12_obj->f_virtuals = l18;
    _a12_obj->f_virtual_rows = l19;
    _a12_obj->f_texts = l20;
    _a12_obj->f_registers = l21;
    _a12_obj->f_params = l22;
    _a12_obj->f_slots = l7;
    l9 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(15u, 0u, 7u, 290u);
    l10 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(210u, 0u, 13u, 1298u);
    l12 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(16u, 0u, 8u, 291u);
    l13 = (void*) _a15_arr;
    l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_vm_Translation_t* _a16_obj = (vader_struct_vader_vm_Translation_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Translation_t));
    vader_obj_header_init(_a16_obj, 1307u);
    _a16_obj->f_code = l9;
    _a16_obj->f_operands = l10;
    _a16_obj->f_stack = l12;
    _a16_obj->f_stack_base = l8;
    _a16_obj->f_retarget = INT64_C(-1);
    _a16_obj->f_jumps = l13;
    _a16_obj->f_source_pc = l14;
    _a16_obj->f_import_ids = l1;
    l9 = (void*) _a16_obj;
    l10 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_jump_table, l6);
    vader_array_t* _a17_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (int64_t) INT64_C(0);
    l12 = (void*) _a17_arr;
    l7 = vader_chk_add(i64, l6, INT64_C(1));
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l12, (int64_t) l7);
    l12 = (void*) _a18_arr;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a19_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
        t1 = vader_box_bool(285u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l7]);
        t2 = t1.payload.b;
        if (t2) {
            vader_vm_flush(l9, l7);
        }
        l8 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l9)->f_code)->f_ops)->length;
        vader_array_t* _a20_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
        ((int64_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l7] = (int64_t) l8;
        vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l3)->f_depth);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
        t0 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l7];
        if ((t0 < INT64_C(0))) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_t* _a22_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
        t1 = vader_box_bool(285u, ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l7]);
        t2 = t1.payload.b;
        if (t2) {
            vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) l3)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
            l21 = ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l7];
            vader_vm_reset_stack(l9, l21);
        }
        if (l4) {
            l22 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_debug)->length;
            if ((l7 < l22)) {
                vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_debug);
                VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
                t1 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
                if (!(t1.tag == 0u)) {
                    vader_vm_emit(l9, l7, INT32_C(128), INT32_C(0), INT32_C(0), INT32_C(0));
                }
            }
        }
        t2 = vader_vm_translate_op(l0, l5, l3, l9, l7);
        if (!(t2)) {
            l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
            l23 = ((int32_t) (int64_t) l7);
            vader_struct_vader_vm_VerifyError_t* _a25_obj = (vader_struct_vader_vm_VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VerifyError_t));
            vader_obj_header_init(_a25_obj, 1311u);
            _a25_obj->f_function = l11;
            _a25_obj->f_pc = l23;
            _a25_obj->f_message = 2210u;
            t3 = (void*) _a25_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (l7 + INT64_C(1));
    }
    l7 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l9)->f_code)->f_ops)->length;
    vader_array_t* _a26_slotarr = ((vader_array_t*) l12);
    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l6)
    ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l6] = (int64_t) l7;
    vader_vm_emit(l9, l6, INT32_C(107), INT32_C(-1), INT32_C(0), INT32_C(0));
    l6 = INT64_C(0);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l9)->f_jumps)->length;
    l7 = vader_div_i64(t0, INT64_C(2));
    while ((l6 < l7)) {
        l10 = ((vader_struct_vader_vm_Translation_t*) l9)->f_jumps;
        l8 = vader_chk_mul(i64, INT64_C(2), l6);
        vader_array_t* _a27_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l8)
        l21 = ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l8];
        l13 = ((vader_struct_vader_vm_Translation_t*) l9)->f_operands;
        l22 = vader_chk_mul(i64, INT64_C(3), l21);
        l14 = ((vader_struct_vader_vm_Translation_t*) l9)->f_jumps;
        t0 = vader_chk_mul(i64, INT64_C(2), l6);
        l24 = vader_chk_add(i64, t0, INT64_C(1));
        vader_array_t* _a28_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l24)
        l25 = ((int64_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l24];
        vader_array_t* _a29_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l25)
        t0 = ((int64_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l25];
        l23 = ((int32_t) (int64_t) t0);
        vader_array_t* _a30_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l22)
        ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l22] = (int32_t) l23;
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l9)->f_code)->f_ops)->length;
    while ((l6 < l7)) {
        l23 = vader_vm_operand_of(l9, l6, INT64_C(0));
        l26 = vader_vm_operand_of(l9, l6, INT64_C(1));
        l27 = vader_vm_operand_of(l9, l6, INT64_C(2));
        l28 = vader_vm_pack_operands(l23, l26, l27);
        if (l28.tag == 0u) {
            l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
            vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l9)->f_code)->f_origin);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l6)
            l29 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l6];
            vader_struct_vader_vm_VerifyError_t* _a32_obj = (vader_struct_vader_vm_VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_VerifyError_t));
            vader_obj_header_init(_a32_obj, 1311u);
            _a32_obj->f_function = l11;
            _a32_obj->f_pc = l29;
            _a32_obj->f_message = 1393u;
            t3 = (void*) _a32_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l9)->f_code)->f_words;
        l8 = ((int64_t) l28.payload.i);
        vader_array_push_i64((vader_array_t*) l10, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(((vader_struct_vader_vm_Translation_t*) l9)->f_code); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_translate_module(void* l0, void* l1, void* l2, bool l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    int64_t l5, l6;
    int32_t l7;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l8, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(211u, 0u, 13u, 1299u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l5 < l6)) {
        l7 = ((int32_t) (int64_t) l5);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l9 = vader_vm_translate_function(l0, l1, l7, l8, l3);
        if (l9.tag == 1311u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = l9.payload.obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_vm_RegModule_t* _a3_obj = (vader_struct_vader_vm_RegModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_RegModule_t));
    vader_obj_header_init(_a3_obj, 1301u);
    _a3_obj->f_functions = l4;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm_translate_op(void* l0, void* l1, void* l2, void* l3, int64_t l4) {
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    int64_t l6, l12;
    int32_t l8, l9, l10, l11, l18, l19;
    void* l13 = NULL;
    void* l14 = NULL;
    bool l15, l16, l17;
    uint8_t l20;
    vader_string_t l21 = 0;
    int64_t t0, t5;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    bool t4;
    uint8_t t6;
    vader_box_t* gc_roots[3] = { &l5, &l7, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l13, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l21 };
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
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_operand(l3, INT64_C(2));
        l10 = vader_vm_pop_to(l3, INT64_C(2));
        l11 = ((int32_t) l7.payload.i);
        vader_vm_emit(l3, l4, l11, l10, l9, l8);
        vader_vm_note_checked_kind(l3, l5);
        vader_vm_push_register(l3, l10);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l7 = vader_vm_unary_op(l5, l2, l4);
    if (!(l7.tag == 0u)) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_pop_to(l3, INT64_C(1));
        l10 = ((int32_t) l7.payload.i);
        vader_vm_emit(l3, l4, l10, l9, l8, INT32_C(0));
        vader_vm_note_checked_kind(l3, l5);
        vader_vm_push_register(l3, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 759u) {
        l13 = ((vader_struct_vader_vm_Translation_t*) l3)->f_stack;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
        vader_struct_vader_vm_Pending_t* _a1_obj = (vader_struct_vader_vm_Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_Pending_t));
        vader_obj_header_init(_a1_obj, 1298u);
        _a1_obj->f_kind = (uint8_t) 1;
        _a1_obj->f_register_v = l8;
        l14 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 760u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
        vader_vm_store_slot(l3, l1, l4, l8, false, l6);
    } else if (l5.tag == 761u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
        vader_vm_store_slot(l3, l1, l4, l8, true, l6);
    } else if ((l5.tag == 663u || l5.tag == 678u || l5.tag == 693u || l5.tag == 714u || l5.tag == 734u || l5.tag == 765u)) {
        l7 = l5;
        vader_vm_push_constant(l3, l7);
    } else if (l5.tag == 686u) {
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack);
    } else if ((l5.tag == 661u || l5.tag == 690u || l5.tag == 762u || l5.tag == 767u || l5.tag == 770u)) {
        ((vader_struct_vader_vm_Translation_t*) l3)->f_retarget = l6;
    } else if ((l5.tag == 668u || l5.tag == 687u)) {
        if (l5.tag == 687u) {
            l12 = vader_chk_sub(i64, l4, INT64_C(1));
            l15 = vader_vm_skips_else(l1, l12);
        } else {
            l15 = false;
        }
        if (!(l15)) {
            vader_vm_flush(l3, l4);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            l8 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_vm_jump(l3, l4, INT32_C(87), INT32_C(0), INT32_C(0), l8);
        }
    } else if ((l5.tag == 669u || l5.tag == 749u)) {
        l13 = ((vader_struct_vader_vm_Translation_t*) l3)->f_stack;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
        l13 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l12);
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack);
        vader_vm_flush(l3, l4);
        l15 = vader_vm_skips_else(l1, l4);
        if (l5.tag == 669u) {
            l16 = true;
        } else {
            l16 = l15;
        }
        l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table;
        if (l15) {
            l12 = vader_chk_add(i64, l4, INT64_C(1));
        } else {
            l12 = l4;
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
        l8 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
        if (((vader_struct_vader_vm_Pending_t*) l13)->f_kind == INT32_C(0)) {
            l17 = (l6 >= INT64_C(0));
        } else {
            l17 = false;
        }
        if (l17) {
            t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops)->length;
            l12 = vader_chk_sub(i64, t0, INT64_C(1));
            l17 = l6 == l12;
        } else {
            l17 = false;
        }
        if (l17) {
            l9 = vader_vm_operand_of(l3, l6, INT64_C(0));
            l10 = ((vader_struct_vader_vm_Pending_t*) l13)->f_register_v;
            l15 = l9 == l10;
        } else {
            l15 = false;
        }
        if (l15) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_ops);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
            l7 = vader_vm_fused_branch(t3, l16);
        } else {
            l7 = vader_box_obj(0u, NULL);
        }
        if (l7.tag == 0u) {
            if (l16) {
                l18 = INT32_C(90);
            } else {
                l18 = INT32_C(89);
            }
            l19 = ((vader_struct_vader_vm_Pending_t*) l13)->f_register_v;
            vader_vm_jump(l3, l4, l18, l19, INT32_C(0), l8);
        } else {
            l9 = vader_vm_operand_of(l3, l6, INT64_C(1));
            l10 = vader_vm_operand_of(l3, l6, INT64_C(2));
            vader_vm_drop_last_op(l3);
            t1 = l7.payload.obj;
            t4 = ((vader_struct_vader_vm_FusedBranch_t*) t1)->f_swap;
            if (t4) {
                t1 = l7.payload.obj;
                l11 = ((vader_struct_vader_vm_FusedBranch_t*) t1)->f_op;
                vader_vm_jump(l3, l4, l11, l10, l9, l8);
            } else {
                t1 = l7.payload.obj;
                l11 = ((vader_struct_vader_vm_FusedBranch_t*) t1)->f_op;
                vader_vm_jump(l3, l4, l11, l9, l10, l8);
            }
        }
    } else if (l5.tag == 771u) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 292u);
        l20 = ((uint8_t) t2.payload.i);
        t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature);
        if ((t0 > INT64_C(1))) {
            l13 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature)->f_results;
            vader_vm_return_many(l3, l4, l13);
        } else if (l20 == INT32_C(14)) {
            vader_vm_emit(l3, l4, INT32_C(107), INT32_C(-1), INT32_C(0), INT32_C(0));
        } else {
            t3 = vader_vm_narrow_code(l20);
            if ((t3 >= INT32_C(0))) {
                vader_vm_flush(l3, l4);
                t0 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
                l6 = vader_chk_sub(i64, t0, INT64_C(1));
                l8 = vader_vm_canonical(l3, l6);
                l9 = vader_vm_narrow_code(l20);
                vader_vm_emit(l3, l4, INT32_C(106), l8, l9, INT32_C(0));
                vader_vm_emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
            } else {
                l8 = vader_vm_operand(l3, INT64_C(1));
                vader_vm_emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
            }
        }
    } else if (l5.tag == 677u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_CallIndirect_t*) t1)->f_type_id;
        l7 = vader_vm_fn_type_of(l0, l8);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) l13)->f_params)->length;
        vader_vm_flush(l3, l4);
        l12 = vader_chk_add(i64, l6, INT64_C(1));
        l8 = vader_vm_pop_to(l3, l12);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallIndirect_t*) t1)->f_type_id;
        l10 = ((int32_t) (int64_t) l6);
        vader_vm_emit(l3, l4, INT32_C(104), l9, l8, l10);
        l9 = ((vader_struct_vader_bytecode_BcFn_t*) l13)->f_return_type;
        t4 = vader_vm_returns_void(l0, l9);
        if (!(t4)) {
            vader_vm_push_register(l3, l8);
        }
    } else if (l5.tag == 806u) {
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_vtable_key;
        l6 = vader_vm_virtual_result_arity(l0, l21);
        if ((l6 > INT64_C(1))) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        vader_vm_flush(l3, l4);
        t1 = l5.payload.obj;
        t3 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_parameter_count;
        l12 = ((int64_t) (int32_t) t3);
        l8 = vader_vm_pop_to(l3, l12);
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_virtuals;
        l14 = l5.payload.obj;
        vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_virtual_rows;
        l14 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_vtable_key;
        l9 = vader_vm_vtable_row_of(l14, l21);
        vader_array_push_i32((vader_array_t*) l13, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_virtuals)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l9 = ((int32_t) (int64_t) t5);
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_parameter_count;
        vader_vm_emit(l3, l4, INT32_C(105), l9, l8, l10);
        if (l6 == INT64_C(1)) {
            vader_vm_push_register(l3, l8);
        }
    } else if (l5.tag == 675u) {
        l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        l13 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_signature;
        l6 = vader_bytecode_bc_result_arity(l13);
        vader_vm_flush(l3, l4);
        l12 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l13)->f_params)->length;
        l8 = vader_vm_pop_to(l3, l12);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
        vader_vm_emit(l3, l4, INT32_C(103), l9, l8, INT32_C(0));
        l12 = INT64_C(0);
        while ((l12 < l6)) {
            l9 = ((int32_t) (int64_t) l12);
            l10 = vader_chk_add(i32, l8, l9);
            vader_vm_push_register(l3, l10);
            l12 = (l12 + INT64_C(1));
        }
    } else if (l5.tag == 772u) {
        t1 = l5.payload.obj;
        l7 = ((vader_struct_vader_bytecode_ReturnLit_t*) t1)->f_value;
        if (l7.tag == 783u) {
            l13 = l7.payload.obj;
            vader_vm_string_constant(l0, l3, l4, l13);
        } else {
            vader_vm_push_constant(l3, l7);
        }
        l8 = vader_vm_operand(l3, INT64_C(1));
        vader_vm_emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 676u) {
        l13 = ((vader_struct_vader_vm_Translation_t*) l3)->f_import_ids;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_CallImport_t*) t1)->f_index;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
        t2 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l8, 292u);
        l20 = ((uint8_t) t2.payload.i);
        t4 = vader_vm_string_byte_op(l3, l4, l20);
        if (t4) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_CallImport_t*) t1)->f_index;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l8);
        l13 = ((vader_struct_vader_bytecode_BcImport_t*) t1)->f_signature;
        vader_vm_flush(l3, l4);
        l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l13)->f_params)->length;
        l8 = vader_vm_pop_to(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallImport_t*) t1)->f_index;
        vader_vm_emit(l3, l4, INT32_C(120), l9, l8, INT32_C(0));
        t6 = vader_bytecode_bc_single_result(l13);
        if (t6 != INT32_C(14)) {
            vader_vm_push_register(l3, l8);
        }
    } else if (l5.tag == 685u) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack);
        vader_vm_emit(l3, l4, INT32_C(126), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 684u) {
        vader_vm_flush(l3, l4);
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_DeferPopExec_t*) t1)->f_count;
        vader_vm_emit(l3, l4, INT32_C(127), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 705u) {
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts;
        l14 = (void*) vader_buffer_new((size_t) INT64_C(87));
        l6 = INT64_C(0);
        l6 = std_core_write_string_at(l14, l6, 1836u);
        l6 = std_core_write_int(l14, l6, l4);
        l6 = std_core_write_string_at(l14, l6, 425u);
        l21 = std_core_finish_buffer(l14, l6);
        vader_array_push((vader_array_t*) l13, vader_box_string(287u, l21));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm_emit(l3, l4, INT32_C(125), l8, INT32_C(0), INT32_C(0));
        l6 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm_canonical(l3, l6);
        vader_vm_push_register(l3, l8);
    } else if (l5.tag == 805u) {
        l13 = ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts;
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_bytecode_Unreachable_t*) t1)->f_reason;
        l21 = concat_2(2301u, l21);
        vader_array_push((vader_array_t*) l13, vader_box_string(287u, l21));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm_RegFunction_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_code)->f_texts)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm_emit(l3, l4, INT32_C(125), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 758u) {
        l6 = ((vader_array_t*) ((vader_struct_vader_vm_Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm_canonical(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_field_index;
        vader_vm_emit(l3, l4, INT32_C(111), l8, l9, l10);
        vader_vm_push_register(l3, l8);
    } else if ((l5.tag == 786u || l5.tag == 803u)) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_pop_to(l3, INT64_C(1));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_bytecode_StructGet_t, f_field_index, l5.payload.obj);
        vader_vm_emit(l3, l4, INT32_C(111), l9, l8, l10);
        vader_vm_push_register(l3, l9);
    } else if ((l5.tag == 788u || l5.tag == 804u)) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_operand(l3, INT64_C(2));
        vader_vm_pop_to(l3, INT64_C(2));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_bytecode_StructSet_t, f_field_index, l5.payload.obj);
        vader_vm_emit(l3, l4, INT32_C(112), l9, l8, l10);
    } else if ((l5.tag == 629u || l5.tag == 754u || l5.tag == 755u || l5.tag == 756u)) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_operand(l3, INT64_C(2));
        l10 = vader_vm_pop_to(l3, INT64_C(2));
        if (l5.tag == 629u) {
            l11 = INT32_C(113);
        } else {
            l11 = INT32_C(115);
        }
        vader_vm_emit(l3, l4, l11, l10, l9, l8);
        vader_vm_push_register(l3, l10);
    } else if ((l5.tag == 636u || l5.tag == 778u || l5.tag == 779u || l5.tag == 780u)) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_operand(l3, INT64_C(2));
        l10 = vader_vm_operand(l3, INT64_C(3));
        vader_vm_pop_to(l3, INT64_C(3));
        if (l5.tag == 636u) {
            l11 = INT32_C(114);
        } else {
            l11 = INT32_C(116);
        }
        vader_vm_emit(l3, l4, l11, l10, l9, l8);
    } else if (l5.tag == 630u) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_pop_to(l3, INT64_C(1));
        vader_vm_emit(l3, l4, INT32_C(117), l9, l8, INT32_C(0));
        vader_vm_push_register(l3, l9);
    } else if (l5.tag == 632u) {
        l8 = vader_vm_operand(l3, INT64_C(1));
        l9 = vader_vm_operand(l3, INT64_C(2));
        vader_vm_pop_to(l3, INT64_C(2));
        vader_vm_emit(l3, l4, INT32_C(118), l9, l8, INT32_C(0));
    } else if (l5.tag == 783u) {
        l13 = l5.payload.obj;
        vader_vm_string_constant(l0, l3, l4, l13);
    } else {
        t4 = vader_vm_is_boxed(l5);
        if (!(t4)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = l5;
        l7 = vader_vm_effect_of(l0, l1, l7);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l6 = ((vader_struct_vader_vm_StackEffect_t*) l13)->f_pops;
        l12 = ((vader_struct_vader_vm_StackEffect_t*) l13)->f_pushes;
        vader_vm_boxed(l3, l4, l5, l6, l12);
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static int32_t vader_vm_truncate_to_width(int64_t l0, int64_t l1, bool l2) {
    int64_t l3, l5;
    bool l4;
    int64_t t0;
    l3 = vader_chk_sub(i64, (INT64_C(1) << (l1 & 63)), INT64_C(1));
    l3 = (l0 & l3);
    if (l2) {
        l5 = vader_chk_sub(i64, l1, INT64_C(1));
        l5 = (INT64_C(1) << (l5 & 63));
        l4 = (l3 & l5) != INT64_C(0);
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = (INT64_C(1) << (l1 & 63));
        t0 = vader_chk_sub(i64, l3, l5);
        return ((int32_t) (int64_t) t0);
    }
    return ((int32_t) (int64_t) l3);
}

static bool vader_vm_try_get_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5;
    void* l8;
    void* l11;
    int64_t l6, l10, l14;
    vader_box_t l7;
    int32_t l9, l13;
    vader_string_t l12;
    int64_t t0;
    uint8_t t1;
    l6 = ((int64_t) (int32_t) l3);
    l6 = vader_chk_add(i64, l1, l6);
    l7 = vader_vm_array_at(l0, l6);
    if (l7.tag == 0u) {
        return false;
    }
    l5 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    l6 = ((int64_t) (int32_t) l4);
    l6 = vader_chk_add(i64, l1, l6);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
    l9 = ((int32_t) (int64_t) t0);
    if ((l9 < INT32_C(0))) {
        return false;
    }
    l6 = ((int64_t) (int32_t) l9);
    l10 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_length;
    if ((l6 >= l10)) {
        return false;
    }
    l7 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_raw;
    if (!(l7.tag == 0u)) {
        l8 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
        l11 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_tags;
        l12 = l7.payload.s;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_offset;
        l10 = ((int64_t) (int32_t) l9);
        l6 = vader_chk_add(i64, l6, l10);
        t1 = vader_host_std_core_byte_at(l12, l6);
        l13 = ((int32_t) (uint8_t) t1);
        vader_vm_set_i32(l8, l11, l1, l2, l13);
        return true;
    }
    l6 = ((int64_t) (int32_t) l2);
    l6 = vader_chk_add(i64, l1, l6);
    l8 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_elements;
    l10 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_offset;
    l14 = ((int64_t) (int32_t) l9);
    l10 = vader_chk_add(i64, l10, l14);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
    l7 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l10];
    vader_vm_set_register(l0, l6, l7);
    return true;
}

static bool vader_vm_try_set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5;
    void* l8;
    int64_t l6, l10;
    vader_box_t l7;
    int32_t l9;
    int64_t t0;
    l6 = ((int64_t) (int32_t) l2);
    l6 = vader_chk_add(i64, l1, l6);
    l7 = vader_vm_array_at(l0, l6);
    if (l7.tag == 0u) {
        return false;
    }
    l5 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm_RegMachine_t*) l0)->f_bits;
    l6 = ((int64_t) (int32_t) l3);
    l6 = vader_chk_add(i64, l1, l6);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
    l9 = ((int32_t) (int64_t) t0);
    if ((l9 < INT32_C(0))) {
        return false;
    }
    l6 = ((int64_t) (int32_t) l9);
    l10 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_length;
    if ((l6 >= l10)) {
        return false;
    }
    if (((vader_struct_vader_vm_ArrayVal_t*) l5)->f_raw.tag == 0u) {
        l8 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_elements;
        l6 = ((vader_struct_vader_vm_ArrayVal_t*) l5)->f_offset;
        l10 = ((int64_t) (int32_t) l9);
        l6 = vader_chk_add(i64, l6, l10);
        l10 = ((int64_t) (int32_t) l4);
        l10 = vader_chk_add(i64, l1, l10);
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
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    bool l6;
    uint8_t l7;
    void* l8 = NULL;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[3] = { &l0, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l2 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = ((int64_t) (int32_t) l2);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types)->length;
    if ((l3 >= l4)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_vm_VmState_t*) l0)->f_bc)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l5.tag == 650u) {
        t0 = l5.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val;
        l6 = vader_vm_class_matches(l1, l7);
        { bool __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 653u) {
        if (l1.tag == 1305u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm_StructVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 639u) {
        if (l1.tag == 1280u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm_ArrayVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 654u) {
        t0 = l5.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l6 = vader_vm_union_matches(l0, l1, l8);
    } else if (l5.tag == 649u) {
        t0 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcRef_t*) t0)->f_trait_name;
        l6 = vader_vm_ref_type_matches(l0, l1, l9);
    } else {
        if (!(l5.tag == 642u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = false;
    }
    { bool __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm_type_tags(void* l0, int32_t l1, int32_t l2) {
    int64_t l3, l8;
    vader_box_t l4;
    uint8_t l5, l6, l11;
    void* l7;
    int32_t l9, l10;
    bool t0;
    void* t1;
    int32_t t2;
    l3 = ((vader_array_t*) l0)->length;
    t0 = vader_vm_in_range(l1, l3);
    if (t0) {
        if ((l2 > INT32_C(8))) {
            return (uint8_t) 127;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l4.tag == 650u) {
            t1 = l4.payload.obj;
            l5 = vader_vm_tags_of_val(((vader_struct_vader_bytecode_BcScalar_t*) t1)->f_val);
            return l5;
        }
        if ((l4.tag == 639u || l4.tag == 642u || l4.tag == 653u)) {
            l5 = (uint8_t) 64;
        } else if (l4.tag == 649u) {
            l5 = (uint8_t) 127;
        } else {
            if (!(l4.tag == 654u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l6 = (uint8_t) 0;
            t1 = l4.payload.obj;
            l7 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
            l3 = ((vader_array_t*) l7)->length;
            l8 = INT64_C(0);
            while ((l8 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
                l10 = vader_chk_add(i32, l2, INT32_C(1));
                l11 = vader_vm_type_tags(l0, l9, l10);
                t2 = (l6 | l11);
                l6 = (uint8_t) (int32_t) t2;
                l8 = (l8 + INT64_C(1));
            }
            l5 = l6;
        }
        return l5;
    }
    return (uint8_t) 127;
}

static uint32_t vader_vm_u32_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return (uint32_t) (int32_t) ((int32_t) (int64_t) t0);
}

static uint64_t vader_vm_u64_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return (uint64_t) (int64_t) t0;
}

static vader_box_t vader_vm_unary_op(vader_box_t l0, void* l1, int64_t l2) {
    uint8_t l3;
    vader_box_t l4;
    int32_t t0;
    void* t1;
    uint8_t t2;
    bool t3;
    vader_string_t t4;
    t0 = (((INT32_C(1) | INT32_C(2)) | INT32_C(16)) | INT32_C(8));
    l3 = (uint8_t) (int32_t) t0;
    if (l0.tag == 724u) {
        l4 = vader_box_i32(290u, INT32_C(13));
        return l4;
    }
    if (l0.tag == 711u) {
        l4 = vader_box_i32(290u, INT32_C(14));
    } else if (l0.tag == 744u) {
        l4 = vader_box_i32(290u, INT32_C(38));
    } else if (l0.tag == 731u) {
        l4 = vader_box_i32(290u, INT32_C(39));
    } else if (l0.tag == 702u) {
        l4 = vader_box_i32(290u, INT32_C(56));
    } else if (l0.tag == 680u) {
        t1 = l0.payload.obj;
        t0 = vader_vm_checked_neg_register_op(((vader_struct_vader_bytecode_CheckedNeg_t*) t1)->f_kind);
        l4 = vader_box_i32(290u, t0);
    } else if (l0.tag == 666u) {
        t2 = vader_vm_stack_tags(l1, l2, INT64_C(1));
        t3 = vader_vm_tags_within(t2, (uint8_t) 8);
        if (t3) {
            l4 = vader_box_i32(290u, INT32_C(67));
        } else {
            l4 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 681u) {
        t2 = vader_vm_stack_tags(l1, l2, INT64_C(1));
        t3 = vader_vm_tags_within(t2, l3);
        if (t3) {
            t1 = l0.payload.obj;
            if (((vader_struct_vader_bytecode_Convert_t*) t1)->f_target == INT32_C(0)) {
                l4 = vader_box_i32(290u, INT32_C(83));
            } else {
                t1 = l0.payload.obj;
                if (((vader_struct_vader_bytecode_Convert_t*) t1)->f_target == INT32_C(1)) {
                    t1 = l0.payload.obj;
                    t4 = ((vader_struct_vader_bytecode_Convert_t*) t1)->f_from_name;
                    t0 = vader_vm_widening(t4);
                    l4 = vader_box_i32(290u, t0);
                } else {
                    t1 = l0.payload.obj;
                    if (((vader_struct_vader_bytecode_Convert_t*) t1)->f_target == INT32_C(3)) {
                        l4 = vader_box_i32(290u, INT32_C(86));
                    } else {
                        l4 = vader_box_obj(0u, NULL);
                    }
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
    int64_t l3, l4;
    int32_t l5;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l2)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        t0 = vader_vm_type_matches(l0, l1, l5);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_vm_unwind(void* l0, void* l1, void* l2, bool l3) {
    int64_t l4, l6;
    void* l5 = NULL;
    void* l9 = NULL;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
        if ((t0 > INT64_C(0))) {
            t0 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count = l4;
            l5 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defers;
            l6 = ((vader_struct_vader_vm_RegMachine_t*) l2)->f_defer_count;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            l7 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
            l8 = vader_vm_defer_thunk(l0, l7, INT32_C(0), 2263u);
            if (l8.tag == 1308u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = l8.payload.obj;
            t1 = vader_vm_run_thunk(l0, l1, l2, l9, INT64_C(0), INT64_C(0), INT64_C(0), l3);
            if (!(t1.tag == 0u)) {
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
    uint32_t l3;
    bool l4;
    int64_t t0;
    int32_t t1;
    if (l0 == INT32_C(1)) {
        return vader_box_i32(290u, ((int32_t) (int64_t) (l1 & INT64_C(255))));
    }
    if (l0 == INT32_C(5)) {
        t0 = (l1 & INT64_C(255));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(128))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(256));
            return vader_box_i32(290u, t1);
        }
        return vader_box_i32(290u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(12)) {
        return vader_box_bool(285u, l1 != INT64_C(0));
    }
    if (l0 == INT32_C(2)) {
        return vader_box_i32(290u, ((int32_t) (int64_t) (l1 & INT64_C(65535))));
    }
    if (l0 == INT32_C(6)) {
        t0 = (l1 & INT64_C(65535));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(32768))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(65536));
            return vader_box_i32(290u, t1);
        }
        return vader_box_i32(290u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(3)) {
        return vader_box_i32(290u, ((int32_t) (uint64_t) l1));
    }
    if (l0 == INT32_C(7)) {
        return vader_box_i32(290u, ((int32_t) (uint64_t) l1));
    }
    if (l0 == INT32_C(11)) {
        t1 = ((int32_t) (uint64_t) l1);
        l3 = (uint32_t) (int32_t) t1;
        if ((l3 > INT32_C(55295))) {
            if ((l3 < INT32_C(57344))) {
                l4 = true;
            } else {
                l4 = (l3 > INT32_C(1114111));
            }
            if (l4) {
                vader_unreachable("value out of range: no Unicode scalar value");
            } else {
                return vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l3));
            }
        } else {
            return vader_box_i32(286u, (int32_t) ((uint32_t) (uint32_t) l3));
        }
    } else {
        if (l0 == INT32_C(4)) {
            return vader_box_i64(291u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(8)) {
            return vader_box_i64(291u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(9)) {
            return vader_box_f64(297u, ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
        }
        if (!(l0 == INT32_C(10))) {
            return vader_box_i32(290u, INT32_C(0));
        }
        return vader_box_f64(297u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
    }
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
    if (l0.tag == 1292u) {
        l2 = l1.tag == 1292u;
        return l2;
    }
    if (l0.tag == 290u) {
        if (l1.tag == 290u) {
            l3 = ((int32_t) l0.payload.i);
            l4 = ((int32_t) l1.payload.i);
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 285u) {
        if (l1.tag == 285u) {
            l5 = l0.payload.b;
            l6 = l1.payload.b;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 286u) {
        if (l1.tag == 286u) {
            l7 = ((uint32_t) l0.payload.i);
            l8 = ((uint32_t) l1.payload.i);
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 287u) {
        if (l1.tag == 287u) {
            l9 = l0.payload.s;
            l10 = l1.payload.s;
            l2 = l9 == l10;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 291u) {
        if (l1.tag == 291u) {
            l11 = ((int64_t) l0.payload.i);
            l12 = ((int64_t) l1.payload.i);
            l2 = l11 == l12;
        } else {
            l2 = false;
        }
    } else if ((l0.tag == 296u || l0.tag == 297u)) {
        if ((l1.tag == 296u || l1.tag == 297u)) {
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
        if (!((l0.tag == 1280u || l0.tag == 1284u || l0.tag == 1285u || l0.tag == 1293u || l0.tag == 1305u || l0.tag == 1309u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if ((l1.tag == 1280u || l1.tag == 1284u || l1.tag == 1285u || l1.tag == 1293u || l1.tag == 1305u || l1.tag == 1309u)) {
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
    int64_t l2, l3, l4, l7, l9, l15, l17, l19, l20, l23, l25, l26, l27, l28, l30, l34, l38;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l31 = vader_box_null(), l39 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l21 = 0;
    vader_string_t l24 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    bool l29, l32, l35;
    int32_t l33;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[5] = { &l8, &l10, &l12, &l31, &l39 };
    void** gc_raw_roots[8] = { &l0, &l1, &l5, &l6, &l11, &l18, &l22, &t0 };
    vader_string_t* gc_atom_roots[7] = { &l13, &l14, &l16, &l21, &l24, &l36, &l37 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    if (l2 == INT64_C(0)) {
        { vader_box_t __vret = vader_box_i64(291u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = INT64_C(0);
    l4 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_signature);
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) INT64_C(0);
    vader_array_t* _a3_arr = vader_array_new(16u, 1u, 8u, 291u);
    ((int64_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (int64_t) INT64_C(0);
    l6 = (void*) _a3_arr;
    for (;;) {
        t1 = ((vader_array_t*) l6)->length;
        if ((t1 > INT64_C(0))) {
            l8 = vader_array_remove_last((vader_array_t*) l6);
            if (l8.tag == 0u) break;
            l7 = ((int64_t) l8.payload.i);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            l9 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7];
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l12 = vader_vm_effect_of(l0, l1, l10);
            if (l12.tag == 0u) {
                l13 = vader_vm_op_text(l10);
                l14 = concat_3(916u, l13, 1070u);
                t0 = vader_vm_defect(l1, l7, l14);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = l12.payload.obj;
            l15 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pops;
            if ((l9 < l15)) {
                l16 = vader_vm_op_text(l10);
                l17 = vader_host_std_core_byte_len(l16);
                l18 = (void*) vader_buffer_new((size_t) (INT64_C(79) + l17));
                l19 = INT64_C(0);
                l19 = std_core_write_string_at(l18, l19, 916u);
                l19 = std_core_write_string_at(l18, l19, l16);
                l19 = std_core_write_string_at(l18, l19, 1072u);
                l20 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pops;
                l19 = std_core_write_int(l18, l19, l20);
                l19 = std_core_write_string_at(l18, l19, 171u);
                l19 = std_core_write_int(l18, l19, l9);
                l21 = std_core_finish_buffer(l18, l19);
                t0 = vader_vm_defect(l1, l7, l21);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l10.tag == 771u) {
                if (l9 != l4) {
                    l22 = (void*) vader_buffer_new((size_t) INT64_C(87));
                    l23 = INT64_C(0);
                    l23 = std_core_write_string_at(l22, l23, 1257u);
                    l23 = std_core_write_int(l22, l23, l4);
                    l23 = std_core_write_string_at(l22, l23, 171u);
                    l23 = std_core_write_int(l22, l23, l9);
                    l24 = std_core_finish_buffer(l22, l23);
                    t0 = vader_vm_defect(l1, l7, l24);
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l25 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pops;
            l26 = vader_chk_sub(i64, l9, l25);
            l27 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_pushes;
            l28 = vader_chk_add(i64, l26, l27);
            if ((l28 > l3)) {
                l3 = l28;
            }
            if (((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(0)) {
                l29 = true;
            } else {
                l29 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (l29) {
                l30 = vader_chk_add(i64, l7, INT64_C(1));
                l31 = vader_vm_flow_to(l1, l5, l6, l30, l28, l7, l4);
                if (!(l31.tag == 0u)) {
                    t0 = l31.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            if (((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(1)) {
                l32 = true;
            } else {
                l32 = ((vader_struct_vader_vm_StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (!(l32)) {
                continue;
            }
            l34 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table)->length;
            if ((l7 < l34)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
                l33 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
            } else {
                l33 = INT32_C(-1);
            }
            if ((l33 < INT32_C(0))) {
                l35 = true;
            } else {
                l35 = (((int64_t) (int32_t) l33) > l2);
            }
            if (l35) {
                l36 = vader_vm_op_text(l10);
                l37 = concat_3(916u, l36, 987u);
                t0 = vader_vm_defect(l1, l7, l37);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l38 = ((int64_t) (int32_t) l33);
            l39 = vader_vm_flow_to(l1, l5, l6, l38, l28, l7, l4);
            if (!(l39.tag == 0u)) {
                t0 = l39.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(291u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm_verify_module(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l2, l4, l7;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 291u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = vader_vm_verify_function(l0, l5);
        if (l6.tag == 1311u) {
            t0 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((int64_t) l6.payload.i);
        vader_array_push_i64((vader_array_t*) l1, l7);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm_virtual_result_arity(void* l0, vader_string_t l1) {
    vader_box_t l2;
    void* t0;
    int64_t t1;
    l2 = vader_vm_virtual_signature(l0, l1);
    if (l2.tag == 0u) {
        return INT64_C(1);
    }
    t0 = l2.payload.obj;
    t1 = vader_bytecode_bc_result_arity(t0);
    return t1;
}

static vader_box_t vader_vm_virtual_signature(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    int64_t l3, l4, l7;
    int32_t l6;
    vader_string_t t0;
    int64_t t1;
    void* t2;
    bool t3;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
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
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                    return vader_ref_box(((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature);
                }
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static int32_t vader_vm_vtable_row_of(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    void* t0;
    vader_string_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_key;
        if (t1 == l1) {
            return ((int32_t) (int64_t) l2);
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

static void vader_vm_walk_block(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, void* l5, vader_box_t l6) {
    int64_t l7, l8, l9, l10, l12, l14, l15, l16, l22, l23, l24;
    void* l11 = NULL;
    void* l18 = NULL;
    uint8_t l13;
    vader_box_t l17 = vader_box_null(), l19 = vader_box_null();
    bool l20, l21;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[4] = { &l6, &l17, &l19, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l11, &l18, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body)->length;
    l8 = ((vader_struct_vader_vm_Blocks_t*) l2)->f_width;
    l8 = vader_chk_mul(i64, l3, l8);
    l9 = INT64_C(0);
    l10 = ((vader_struct_vader_vm_Blocks_t*) l2)->f_width;
    while ((l9 < l10)) {
        l11 = ((vader_struct_vader_vm_Blocks_t*) l2)->f_entry;
        l12 = vader_chk_add(i64, l8, l9);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l12)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l12, 292u);
        l13 = ((uint8_t) t0.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9] = (uint8_t) (int32_t) (uint8_t) l13;
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l8 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_leaders);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l9 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    for (;;) {
        if ((l9 < l7)) {
            if (!(l6.tag == 0u)) {
                t1 = l6.payload.obj;
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_FunctionTags_t*) t1)->f_depth);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9] = (int64_t) l8;
                l10 = INT64_C(0);
                l12 = l8;
                while ((l10 < l12)) {
                    t1 = l6.payload.obj;
                    l11 = ((vader_struct_vader_vm_FunctionTags_t*) t1)->f_stack;
                    t1 = l6.payload.obj;
                    l14 = ((vader_struct_vader_vm_FunctionTags_t*) t1)->f_deepest;
                    t2 = vader_chk_mul(i64, l9, l14);
                    l15 = vader_chk_add(i64, t2, l10);
                    l16 = vader_chk_add(i64, l4, l10);
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
                    t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l16, 292u);
                    l13 = ((uint8_t) t0.payload.i);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
                    ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l15] = (uint8_t) (int32_t) (uint8_t) l13;
                    l10 = (l10 + INT64_C(1));
                }
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            l17 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            l19 = vader_vm_effect_of(((vader_struct_vader_vm_TagContext_t*) l0)->f_module, l1, l17);
            if (l19.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l18 = l19.payload.obj;
            l8 = vader_vm_transfer(l0, l17, l5, l4, l8, l18);
            if (l6.tag == 0u) {
                if (((vader_struct_vader_vm_StackEffect_t*) l18)->f_flow == INT32_C(1)) {
                    l21 = true;
                } else {
                    l21 = ((vader_struct_vader_vm_StackEffect_t*) l18)->f_flow == INT32_C(2);
                }
                l20 = l21;
            } else {
                l20 = false;
            }
            if (l20) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
                t3 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l9];
                l22 = ((int64_t) (int32_t) t3);
                if ((l22 < l7)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_block_at);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l22)
                    l23 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l22];
                    vader_vm_merge_block(l2, l23, l8, l5);
                }
            }
            if (((vader_struct_vader_vm_StackEffect_t*) l18)->f_flow != INT32_C(0)) {
                if (((vader_struct_vader_vm_StackEffect_t*) l18)->f_flow != INT32_C(2)) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l9 = vader_chk_add(i64, l9, INT64_C(1));
            if (!((l9 < l7))) {
                continue;
            }
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_block_at);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
            t2 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9];
            if (!((t2 >= INT64_C(0)))) {
                continue;
            }
            if (l6.tag == 0u) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm_Blocks_t*) l2)->f_block_at);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                l24 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                vader_vm_merge_block(l2, l24, l8, l5);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_vm_widening(vader_string_t l0) {
    bool t0;
    t0 = vader_vm_is_unsigned_source(l0);
    if (!(t0)) {
        return INT32_C(84);
    }
    return INT32_C(85);
}

static void vader_vm_write_le(void* l0, int64_t l1, int64_t l2, uint64_t l3) {
    uint64_t l4;
    int64_t l5, l6;
    uint8_t l7;
    int32_t t0;
    l4 = l3;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        l6 = vader_chk_add(i64, l1, l5);
        t0 = (((int32_t) (int64_t) (l4 & INT64_C(255))) & INT32_C(255));
        l7 = (uint8_t) (int32_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l7;
        l4 = (l4 >> INT64_C(8));
        l5 = (l5 + INT64_C(1));
    }
    return;
}

static void vader_vm_write_little_endian(void* l0, int64_t l1, int64_t l2, int64_t l3) {
    uint64_t l4, l7;
    int64_t l5, l6;
    uint8_t l8;
    int64_t t0, t1;
    int32_t t2;
    t0 = l2;
    l4 = (uint64_t) (int64_t) t0;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        l6 = vader_chk_add(i64, l1, l5);
        t0 = vader_chk_mul(i64, l5, INT64_C(8));
        t1 = t0;
        l7 = (uint64_t) (int64_t) t1;
        t2 = (((int32_t) (int64_t) ((l4 >> (l7 & 63)) & INT64_C(255))) & INT32_C(255));
        l8 = (uint8_t) (int32_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l8;
        l5 = (l5 + INT64_C(1));
    }
    return;
}

static int64_t vader_vm_zero_extended(void* l0, void* l1, int64_t l2, int32_t l3) {
    int64_t l4;
    vader_box_t t0;
    int64_t t1;
    l4 = ((int64_t) (int32_t) l3);
    l4 = vader_chk_add(i64, l2, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 292u);
    if (!(((int32_t) t0.payload.i) == INT32_C(0))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        return t1;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
    return ((int64_t) (uint32_t) ((int32_t) (int64_t) t1));
}

static vader_box_t vader_vm_zero_value(void) {
    return vader_box_i32(290u, INT32_C(0));
}
