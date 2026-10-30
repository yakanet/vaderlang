#include "bootstrap.split.h"

static vader_string_t vader_vm$ArrayVal$std_core$Display$to_string(void* l0);
static vader_string_t vader_vm$BoolVal$std_core$Display$to_string(bool l0);
static vader_string_t vader_vm$CharVal$std_core$Display$to_string(uint32_t l0);
static vader_string_t vader_vm$F64Val$std_core$Display$to_string(double l0);
static vader_string_t vader_vm$FnVal$std_core$Display$to_string(void* l0);
static vader_string_t vader_vm$I32Val$std_core$Display$to_string(int32_t l0);
static vader_string_t vader_vm$I64Val$std_core$Display$to_string(int64_t l0);
static vader_string_t vader_vm$NullVal$std_core$Display$to_string(void* l0);
static vader_string_t vader_vm$ObjVal$std_core$Display$to_string(void* l0);
static vader_string_t vader_vm$StringVal$std_core$Display$to_string(vader_string_t l0);
static vader_string_t vader_vm$StructVal$std_core$Display$to_string(void* l0);
static vader_string_t vader_vm$TypeVal$std_core$Display$to_string(void* l0);
static vader_box_t vader_vm$accepted_tags(vader_box_t l0, int64_t l1);
static int64_t vader_vm$adapter_of(void* l0, int32_t l1);
static vader_box_t vader_vm$adapter_reason(void* l0, void* l1);
static void vader_vm$add_constant(vader_box_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_vm$apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4, bool l5);
static vader_box_t vader_vm$apply_eq_binop(void* l0, vader_string_t l1, bool l2);
static vader_box_t vader_vm$array_at(void* l0, int64_t l1);
static vader_box_t vader_vm$array_bytes(void* l0, int64_t l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm$bc_value_to_vm(vader_box_t l0, void* l1);
static vader_box_t vader_vm$binary_op(vader_box_t l0, void* l1, int64_t l2);
static int64_t vader_vm$bits_of(void* l0, int64_t l1, int32_t l2);
static void vader_vm$boxed(void* l0, int64_t l1, vader_box_t l2, int64_t l3, int64_t l4);
static int32_t vader_vm$boxed_counts(int64_t l0, int64_t l1);
static int64_t vader_vm$boxed_pops(int32_t l0);
static int64_t vader_vm$boxed_pushes(int32_t l0);
static void* vader_vm$branch(bool l0, int32_t l1, bool l2, int32_t l3, bool l4);
static void* vader_vm$budget_trap(int64_t l0);
static vader_box_t vader_vm$build_array(int32_t l0, int32_t l1, void* l2);
static vader_box_t vader_vm$build_buffer(void* l0, void* l1);
static vader_box_t vader_vm$build_main_args(void* l0, void* l1, int32_t l2);
static vader_box_t vader_vm$build_struct(void* l0, int32_t l1, void* l2);
static void* vader_vm$bytes_to_value(vader_string_t l0, int32_t l1);
static vader_string_t vader_vm$call_foreign(int64_t l0, bool l1, void* l2, void* l3, int64_t l4);
static vader_box_t vader_vm$call_import(void* l0, void* l1, int32_t l2, int64_t l3, int32_t l4, bool l5);
static vader_box_t vader_vm$call_results(void* l0, vader_box_t l1);
static vader_box_t vader_vm$callee_of(void* l0, int64_t l1, int32_t l2);
static int32_t vader_vm$canonical(void* l0, int64_t l1);
static vader_box_t vader_vm$check_byte_range(int32_t l0, int64_t l1, int64_t l2, vader_string_t l3, int32_t l4);
static vader_box_t vader_vm$check_module_tags(void* l0, void* l1);
static int32_t vader_vm$checked_neg_register_op(uint8_t l0);
static void* vader_vm$checked_neg_trap(uint8_t l0, void* l1, int64_t l2);
static int32_t vader_vm$checked_register_op(void* l0);
static vader_box_t vader_vm$checked_registers(uint8_t l0, uint8_t l1, void* l2, int64_t l3, int64_t l4);
static void* vader_vm$checked_trap(uint8_t l0, uint8_t l1, void* l2, int64_t l3);
static int64_t vader_vm$clamp_nonneg(int32_t l0);
static bool vader_vm$class_matches(vader_box_t l0, uint8_t l1);
static void vader_vm$collect_constants(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_vm$comptime_refusal(uint8_t l0);
static vader_box_t vader_vm$comptime_refusal_trap(vader_string_t l0, vader_string_t l1);
static bool vader_vm$convert_int_fast(void* l0, uint8_t l1, vader_string_t l2);
static vader_box_t vader_vm$convert_value(vader_box_t l0, uint8_t l1, vader_string_t l2, int32_t l3);
static vader_box_t vader_vm$debug_controller(void* l0);
static int64_t vader_vm$debug_std_descriptor(int64_t l0);
static vader_box_t vader_vm$debug_write(void* l0, void* l1, int64_t l2, int32_t l3, void* l4);
static void* vader_vm$defect(void* l0, int64_t l1, vader_string_t l2);
static vader_box_t vader_vm$defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3);
static vader_string_t vader_vm$describe_obj(void* l0);
static vader_string_t vader_vm$describe_value_tag(vader_box_t l0);
static void vader_vm$detach_array_view(void* l0);
static vader_box_t vader_vm$dispatch_extern(void* l0, void* l1, int64_t l2, int32_t l3, void* l4, vader_box_t l5, int64_t l6);
static vader_box_t vader_vm$dispatch_import(void* l0, void* l1, int64_t l2, void* l3, void* l4, int32_t l5, int32_t l6, int32_t l7, void* l8, bool l9, vader_box_t l10, uint8_t l11, int64_t l12);
static vader_string_t vader_vm$display_tags(uint8_t l0);
static vader_string_t vader_vm$display_value(vader_box_t l0);
static vader_box_t vader_vm$do_memory_copy(void* l0);
static void vader_vm$drop_due_timers(void* l0);
static void vader_vm$drop_last_op(void* l0);
static void* vader_vm$effect(int64_t l0, int64_t l1);
static vader_box_t vader_vm$effect_of(void* l0, void* l1, vader_box_t l2);
static vader_string_t vader_vm$element_label(int32_t l0);
static uint8_t vader_vm$element_tags(void* l0, int32_t l1);
static void* vader_vm$element_trap(void* l0, int64_t l1, int32_t l2, int32_t l3, void* l4, int64_t l5, int32_t l6);
static void vader_vm$emit(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static void vader_vm$enter_frame(void* l0, void* l1, int64_t l2);
static vader_box_t vader_vm$entry_named(void* l0, vader_string_t l1);
static vader_box_t vader_vm$exec_array_copy(void* l0);
static vader_box_t vader_vm$exec_array_push_all(void* l0);
static vader_box_t vader_vm$exec_array_repeat(void* l0);
static vader_box_t vader_vm$exec_array_slice(void* l0, void* l1);
static vader_box_t vader_vm$exec_buffer_write_string(void* l0);
static vader_box_t vader_vm$exec_string_compare(void* l0);
static vader_box_t vader_vm$extern_result(uint8_t l0, int64_t l1);
static vader_box_t vader_vm$extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, int64_t l3);
static double vader_vm$f64_of(void* l0, int64_t l1, int32_t l2);
static int32_t vader_vm$ffi_result_class(uint8_t l0);
static bool vader_vm$ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2);
static uint8_t vader_vm$field_tags(void* l0, int32_t l1, int32_t l2);
static uint8_t vader_vm$field_val_type(void* l0, void* l1);
static int32_t vader_vm$find_string_array_type_id(void* l0);
static int32_t vader_vm$find_u8_array_type_id(void* l0);
static vader_box_t vader_vm$finish_run(void* l0, bool l1, vader_box_t l2);
static bool vader_vm$fits_signed(int32_t l0, int64_t l1);
static uint64_t vader_vm$float_bits(double l0, int64_t l1);
static vader_box_t vader_vm$flow_to(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5, int64_t l6);
static void vader_vm$flush(void* l0, int64_t l1);
static void* vader_vm$fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$fn_type_of(void* l0, int32_t l1);
static void* vader_vm$frame_names(void* l0);
static vader_box_t vader_vm$fused_branch(int32_t l0, bool l1);
static void* vader_vm$global_at_comptime_trap(void* l0, int32_t l1);
static uint8_t vader_vm$global_tags(void* l0, int32_t l1);
static void vader_vm$grow_frame_records(void* l0, void* l1, int64_t l2, int64_t l3);
static vader_box_t vader_vm$hosted_frame_call(void* l0, int64_t l1, int32_t l2, vader_string_t l3, bool l4);
static int32_t vader_vm$i32_of(void* l0, int64_t l1, int32_t l2);
static bool vader_vm$in_range(int32_t l0, int64_t l1);
static vader_box_t vader_vm$indexed_effect(int32_t l0, int64_t l1, int64_t l2, int64_t l3);
static void* vader_vm$indirect_call_trap(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4);
static vader_box_t vader_vm$indirect_effect(void* l0, int32_t l1);
static void* vader_vm$infer_function_tags(void* l0, void* l1, int64_t l2);
static void* vader_vm$infer_module_tags(void* l0, void* l1);
static void* vader_vm$initial_globals(void* l0);
static bool vader_vm$inlinable_op(vader_box_t l0);
static void* vader_vm$inline_into(void* l0, void* l1, int64_t l2);
static void* vader_vm$inline_leaf_calls(void* l0);
static uint8_t vader_vm$integer_operand_tags(uint8_t l0);
static uint8_t vader_vm$integer_tags(uint8_t l0);
static vader_string_t vader_vm$intrinsic_host_mangle(vader_string_t l0, vader_string_t l1);
static bool vader_vm$is_array_view(void* l0);
static bool vader_vm$is_boxed(vader_box_t l0);
static bool vader_vm$is_covered_variadic(int64_t l0, int64_t l1, int64_t l2);
static bool vader_vm$is_fn_index_out_of_range(int32_t l0, void* l1);
static bool vader_vm$is_i32_tag(uint8_t l0);
static bool vader_vm$is_inline_leaf(void* l0);
static bool vader_vm$is_integer_alias(uint8_t l0);
static bool vader_vm$is_overflow_trap_message(vader_string_t l0);
static bool vader_vm$is_profiler_bracket(vader_string_t l0);
static bool vader_vm$is_source_local(vader_string_t l0);
static bool vader_vm$is_std_handle_symbol(vader_string_t l0);
static bool vader_vm$is_unsigned_source(vader_string_t l0);
static bool vader_vm$is_write_symbol(vader_string_t l0);
static void vader_vm$jump(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static vader_box_t vader_vm$lent_element_val_type(void* l0, int32_t l1);
static bool vader_vm$line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_vm$load_bytes_op(void* l0, int64_t l1, vader_string_t l2);
static int32_t vader_vm$lookup_vtable_row(void* l0, int32_t l1, int32_t l2);
static void vader_vm$materialise(void* l0, int64_t l1, int64_t l2);
static vader_box_t vader_vm$merge(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5);
static void vader_vm$merge_block(void* l0, int64_t l1, int64_t l2, void* l3);
static vader_box_t vader_vm$mirror_field_value(uint8_t l0, int64_t l1);
static void* vader_vm$mirror_value(void* l0, int64_t l1, int32_t l2, void* l3, void* l4);
static vader_box_t vader_vm$mirrored_struct_fields(void* l0, void* l1, int64_t l2);
static void vader_vm$move_register(void* l0, int64_t l1, int64_t l2);
static int32_t vader_vm$narrow_code(uint8_t l0);
static vader_box_t vader_vm$narrow_mask(vader_box_t l0, uint8_t l1);
static void vader_vm$narrow_register(void* l0, int64_t l1, int32_t l2);
static void* vader_vm$new_blocks(void* l0, void* l1, int64_t l2);
static void* vader_vm$new_run_host(void);
static void* vader_vm$new_tag_context(void* l0);
static void vader_vm$note_checked_kind(void* l0, vader_box_t l1);
static bool vader_vm$one_argument_string_op(void* l0, int64_t l1, int32_t l2);
static vader_string_t vader_vm$op_text(vader_box_t l0);
static int32_t vader_vm$operand(void* l0, int64_t l1);
static int32_t vader_vm$operand_a(int64_t l0);
static int32_t vader_vm$operand_b(int64_t l0);
static int32_t vader_vm$operand_c(int64_t l0);
static int32_t vader_vm$operand_of(void* l0, int64_t l1, int64_t l2);
static bool vader_vm$operands_within(void* l0, int64_t l1, uint8_t l2);
static void* vader_vm$overflow_trap(vader_string_t l0);
static void vader_vm$own_bytes(void* l0);
static vader_box_t vader_vm$pack_operands(int32_t l0, int32_t l1, int32_t l2);
static vader_string_t vader_vm$param_display_name(void* l0, int64_t l1);
static void* vader_vm$pause_context(void* l0, void* l1, vader_string_t l2, int64_t l3, int64_t l4);
static void* vader_vm$pause_frame(void* l0, void* l1, void* l2, int32_t l3);
static vader_box_t vader_vm$peek_array_mut(void* l0, int64_t l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm$peek_owned(void* l0, int64_t l1);
static vader_box_t vader_vm$peek_val(void* l0, int64_t l1);
static int32_t vader_vm$pop_to(void* l0, int64_t l1);
static vader_box_t vader_vm$prepare_for(void* l0, bool l1);
static vader_box_t vader_vm$prepare_module(void* l0, bool l1);
static void* vader_vm$primitive_impl_import(vader_string_t l0, int64_t l1);
static vader_string_t vader_vm$primitive_kind_at(void* l0, int32_t l1);
static int32_t vader_vm$primitive_type_id(void* l0, vader_box_t l1);
static void* vader_vm$project_locals(void* l0, int32_t l1, void* l2, void* l3);
static void* vader_vm$project_struct_fields(void* l0, void* l1, int32_t l2);
static void* vader_vm$project_var(vader_string_t l0, vader_box_t l1, void* l2, int32_t l3);
static void vader_vm$push_constant(void* l0, vader_box_t l1);
static void vader_vm$push_little_endian(void* l0, int64_t l1, int64_t l2);
static void vader_vm$push_register(void* l0, int32_t l1);
static void vader_vm$push_val(void* l0, int64_t l1, vader_box_t l2);
static uint8_t vader_vm$pushed_tags(void* l0, vader_box_t l1, void* l2, uint8_t l3);
static vader_box_t vader_vm$read_array(vader_box_t l0, int32_t l1, vader_string_t l2);
static void vader_vm$read_back_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5);
static vader_box_t vader_vm$read_bool(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_f64(vader_box_t l0, int32_t l1, vader_string_t l2);
static double vader_vm$read_float(void* l0, int64_t l1, int64_t l2);
static vader_box_t vader_vm$read_fn(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_i32(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_i64(vader_box_t l0, int32_t l1, vader_string_t l2);
static int64_t vader_vm$read_little_endian(void* l0, int64_t l1, int64_t l2, bool l3);
static vader_box_t vader_vm$read_numeric_as_f64(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm$read_numeric_as_i64(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm$read_obj(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_scalar_word(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_string(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_struct(vader_box_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$read_struct_field(vader_box_t l0, int32_t l1, int32_t l2, vader_string_t l3);
static void* vader_vm$receiver_trap(void* l0, int64_t l1, void* l2, int64_t l3, vader_string_t l4, vader_string_t l5);
static int32_t vader_vm$receiver_type_id_of(void* l0, vader_box_t l1);
static void* vader_vm$reduce_data_pool(void* l0, void* l1, void* l2);
static bool vader_vm$ref_type_matches(void* l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_vm$reg_call(void* l0, void* l1, void* l2, int32_t l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm$reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6);
static vader_box_t vader_vm$register_value(void* l0, int64_t l1);
static vader_box_t vader_vm$relocated(vader_box_t l0, int32_t l1);
static void vader_vm$reserve_registers(void* l0, int64_t l1);
static void vader_vm$reserve_stack(void* l0, int64_t l1);
static void vader_vm$reset_stack(void* l0, int64_t l1);
static vader_box_t vader_vm$resolve_virtual(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5);
static void vader_vm$return_many(void* l0, int64_t l1, void* l2);
static bool vader_vm$returns_void(void* l0, int32_t l1);
static vader_box_t vader_vm$retyped_int(vader_box_t l0, int64_t l1);
static vader_box_t vader_vm$run_boxed(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5);
static vader_box_t vader_vm$run_defers(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm$run_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5);
static vader_box_t vader_vm$run_for_value(void* l0, vader_string_t l1, bool l2);
static vader_box_t vader_vm$run_thunk(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm$scalar_of(vader_box_t l0);
static void* vader_vm$scratch_frame(void);
static vader_box_t vader_vm$serialise_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7);
static void vader_vm$set_bool(void* l0, void* l1, int64_t l2, int32_t l3, bool l4);
static void vader_vm$set_char_code(void* l0, void* l1, int64_t l2, int32_t l3, uint32_t l4);
static vader_box_t vader_vm$set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6, int32_t l7);
static void vader_vm$set_f64(void* l0, void* l1, int64_t l2, int32_t l3, double l4);
static vader_box_t vader_vm$set_field(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6);
static void vader_vm$set_i32(void* l0, void* l1, int64_t l2, int32_t l3, int32_t l4);
static void vader_vm$set_i64(void* l0, void* l1, int64_t l2, int32_t l3, int64_t l4);
static void vader_vm$set_integer(void* l0, void* l1, int64_t l2, int32_t l3, uint8_t l4, int64_t l5);
static void vader_vm$set_register(void* l0, int64_t l1, vader_box_t l2);
static bool vader_vm$skips_else(void* l0, int64_t l1);
static bool vader_vm$slot_in_scope(void* l0, void* l1, int64_t l2, int32_t l3);
static uint8_t vader_vm$slot_valtype(void* l0, int32_t l1);
static void vader_vm$stack_grow(void* l0);
static vader_box_t vader_vm$stack_i32(void* l0, int64_t l1, vader_string_t l2, vader_string_t l3);
static vader_box_t vader_vm$stack_obj(void* l0, int64_t l1, vader_string_t l2);
static uint8_t vader_vm$stack_tags(void* l0, int64_t l1, int64_t l2);
static bool vader_vm$step_should_stop(uint8_t l0, int32_t l1, int32_t l2);
static void vader_vm$stop_at_line(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5);
static vader_box_t vader_vm$store_bytes_op(void* l0, int64_t l1, uint64_t l2, vader_string_t l3);
static void vader_vm$store_slot(void* l0, void* l1, int64_t l2, int32_t l3, bool l4, int64_t l5);
static void* vader_vm$string_array_to_value(void* l0, int32_t l1);
static vader_box_t vader_vm$string_at(void* l0, int64_t l1);
static bool vader_vm$string_byte_op(void* l0, int64_t l1, uint8_t l2);
static void vader_vm$string_constant(void* l0, void* l1, int64_t l2, void* l3);
static vader_box_t vader_vm$struct_new_effect(void* l0, int32_t l1);
static uint8_t vader_vm$tags_of_type(void* l0, int32_t l1);
static uint8_t vader_vm$tags_of_val(uint8_t l0);
static bool vader_vm$tags_within(uint8_t l0, uint8_t l1);
static bool vader_vm$trait_implemented_by(void* l0, vader_string_t l1, int32_t l2);
static int64_t vader_vm$transfer(void* l0, vader_box_t l1, void* l2, int64_t l3, int64_t l4, void* l5);
static vader_box_t vader_vm$translate_function(void* l0, void* l1, int32_t l2, void* l3, bool l4);
static vader_box_t vader_vm$translate_module(void* l0, void* l1, void* l2, bool l3);
static bool vader_vm$translate_op(void* l0, void* l1, void* l2, void* l3, int64_t l4);
static int32_t vader_vm$truncate_to_width(int64_t l0, int64_t l1, bool l2);
static bool vader_vm$try_get_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4);
static bool vader_vm$try_set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4);
static int32_t vader_vm$type_id_for_symbol(void* l0, int32_t l1);
static bool vader_vm$type_matches(void* l0, vader_box_t l1, int32_t l2);
static uint8_t vader_vm$type_tags(void* l0, int32_t l1, int32_t l2);
static uint32_t vader_vm$u32_of(void* l0, int64_t l1, int32_t l2);
static uint64_t vader_vm$u64_of(void* l0, int64_t l1, int32_t l2);
static vader_box_t vader_vm$unary_op(vader_box_t l0, void* l1, int64_t l2);
static bool vader_vm$union_matches(void* l0, vader_box_t l1, void* l2);
static vader_string_t vader_vm$unopened_reason(void* l0);
static void vader_vm$unwind(void* l0, void* l1, void* l2, bool l3);
static vader_box_t vader_vm$validate_fn_index(int32_t l0, void* l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm$value_from_bits(uint8_t l0, uint64_t l1);
static bool vader_vm$value_ref_eq(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_vm$verify_function(void* l0, void* l1);
static vader_box_t vader_vm$verify_module(void* l0);
static int32_t vader_vm$vtable_row_of(void* l0, vader_string_t l1);
static void vader_vm$walk_block(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, void* l5, vader_box_t l6);
static int32_t vader_vm$widening(vader_string_t l0);
static void vader_vm$write_float(void* l0, int64_t l1, double l2, int64_t l3);
static void vader_vm$write_little_endian(void* l0, int64_t l1, int64_t l2, int64_t l3);
static int64_t vader_vm$zero_extended(void* l0, void* l1, int64_t l2, int32_t l3);
static vader_box_t vader_vm$zero_value(void);
static void* vader_vm$zeroed_mirror(int32_t l0, void* l1, void* l2, int32_t l3);

static vader_string_t vader_vm$ArrayVal$std_core$Display$to_string(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 964u);
    l2 = INT64_C(0);
    l3 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_length;
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string__builder$append(l1, 362u);
        }
        t1 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
        l4 = vader_chk_add(i64, t1, l2);
        t2 = vader_vm$element_at(l0, l4);
        l5 = vader_vm$display_value(t2);
        std_string__builder$append(l1, l5);
        l2 = (l2 + INT64_C(1));
    }
    std_string__builder$append(l1, 967u);
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$BoolVal$std_core$Display$to_string(bool l0) {
    if (l0) {
        return 2738u;
    }
    return 1968u;
}

static vader_string_t vader_vm$CharVal$std_core$Display$to_string(uint32_t l0) {
    vader_string_t t0;
    t0 = std_core$char$Display$to_string(l0);
    return t0;
}

static vader_string_t vader_vm$F64Val$std_core$Display$to_string(double l0) {
    vader_string_t t0;
    t0 = std_core$f64$Display$to_string(l0);
    return t0;
}

static vader_string_t vader_vm$FnVal$std_core$Display$to_string(void* l0) {
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
    if (((vader_struct_vader_vm$FnVal_t*) l0)->f_env.tag == 0u) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(25));
        l2 = INT64_C(0);
        l2 = std_core$write_string_at(l1, l2, 512u);
        t0 = ((vader_struct_vader_vm$FnVal_t*) l0)->f_function_index;
        l3 = ((int64_t) (int32_t) t0);
        l2 = std_core$write_int(l1, l2, l3);
        l2 = std_core$write_string_at(l1, l2, 525u);
        t1 = std_core$finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 512u);
    t0 = ((vader_struct_vader_vm$FnVal_t*) l0)->f_function_index;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 359u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$I32Val$std_core$Display$to_string(int32_t l0) {
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
    l2 = std_core$write_int(l1, l2, l3);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$I64Val$std_core$Display$to_string(int64_t l0) {
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
    l2 = std_core$write_int(l1, l2, l3);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$NullVal$std_core$Display$to_string(void* l0) {
    return 2408u;
}

static vader_string_t vader_vm$ObjVal$std_core$Display$to_string(void* l0) {
    vader_string_t t0;
    t0 = vader_vm$describe_obj(l0);
    return t0;
}

bool vader_vm$Scalar$std_core$Equals$equals(void* l0, void* l1) {
    int64_t l2, l3;
    uint8_t l4, l5;
    l2 = ((vader_struct_vader_vm$Scalar_t*) l0)->f_bits;
    l3 = ((vader_struct_vader_vm$Scalar_t*) l1)->f_bits;
    if (l2 == l3) {
        l4 = ((vader_struct_vader_vm$Scalar_t*) l0)->f_tag;
        l5 = ((vader_struct_vader_vm$Scalar_t*) l1)->f_tag;
        return l4 == l5;
    }
    return false;
}

bool vader_vm$Scalar$std_core$Equals$equals$guard(void* l0, vader_box_t l1) {
    void* l2;
    bool t0;
    if (l1.tag == 1440u) {
        l2 = l1.payload.obj;
        t0 = vader_vm$Scalar$std_core$Equals$equals(l0, l2);
        return t0;
    }
    return false;
}

uint64_t vader_vm$Scalar$std_core$Hash$hash(void* l0) {
    uint64_t l1, l2;
    int64_t t0, t1;
    t0 = ((vader_struct_vader_vm$Scalar_t*) l0)->f_bits;
    t1 = t0;
    l1 = (uint64_t) (int64_t) t1;
    t0 = ((vader_struct_vader_vm$Scalar_t*) l0)->f_bits;
    l2 = ((uint64_t) (int64_t) t0 >> INT64_C(32));
    return (uint64_t) (int64_t) (l1 ^ l2);
}

static vader_string_t vader_vm$StringVal$std_core$Display$to_string(vader_string_t l0) {
    return l0;
}

static vader_string_t vader_vm$StructVal$std_core$Display$to_string(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l3 = INT64_C(0);
    t1 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
    l4 = ((int64_t) (int32_t) t1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3051u);
    l5 = std_core$finish_buffer(l2, l3);
    std_string__builder$append(l1, l5);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l1, 362u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
        l5 = vader_vm$display_value(t2);
        std_string__builder$append(l1, l5);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append(l1, 240u);
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$TypeVal$std_core$Display$to_string(void* l0) {
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
    l2 = std_core$write_string_at(l1, l2, 517u);
    t0 = ((vader_struct_vader_vm$TypeVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 525u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$accepted_tags(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    void* t0;
    uint8_t t1;
    if ((l0.tag == 800u || l0.tag == 801u || l0.tag == 803u || l0.tag == 804u || l0.tag == 806u || l0.tag == 808u || l0.tag == 809u || l0.tag == 810u || l0.tag == 811u || l0.tag == 812u || l0.tag == 813u || l0.tag == 816u || l0.tag == 817u || l0.tag == 818u || l0.tag == 819u || l0.tag == 880u || l0.tag == 881u || l0.tag == 882u || l0.tag == 883u || l0.tag == 884u || l0.tag == 885u)) {
        l2 = vader_box_i32(340u, INT32_C(19));
        return l2;
    }
    if ((l0.tag == 802u || l0.tag == 815u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(340u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 807u || l0.tag == 814u)) {
        l2 = vader_box_i32(340u, (INT32_C(19) | INT32_C(32)));
    } else if ((l0.tag == 820u || l0.tag == 821u || l0.tag == 823u || l0.tag == 824u || l0.tag == 826u || l0.tag == 827u || l0.tag == 828u || l0.tag == 829u || l0.tag == 830u || l0.tag == 831u || l0.tag == 832u || l0.tag == 833u || l0.tag == 834u || l0.tag == 836u || l0.tag == 837u || l0.tag == 838u || l0.tag == 839u || l0.tag == 886u || l0.tag == 887u || l0.tag == 888u || l0.tag == 889u || l0.tag == 890u || l0.tag == 891u)) {
        l2 = vader_box_i32(340u, INT32_C(3));
    } else if ((l0.tag == 822u || l0.tag == 835u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(340u, INT32_C(3));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 783u || l0.tag == 785u || l0.tag == 786u || l0.tag == 787u || l0.tag == 788u || l0.tag == 789u || l0.tag == 790u || l0.tag == 791u || l0.tag == 792u || l0.tag == 794u)) {
        l2 = vader_box_i32(340u, INT32_C(4));
    } else if (l0.tag == 793u) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(340u, INT32_C(4));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 772u) {
        t0 = l0.payload.obj;
        t1 = vader_vm$integer_operand_tags(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        l2 = vader_box_i32(340u, (int32_t)(uint32_t) t1);
    } else if (l0.tag == 773u) {
        if (l1 == INT64_C(1)) {
            t0 = l0.payload.obj;
            t1 = vader_vm$integer_operand_tags(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
            l2 = vader_box_i32(340u, (int32_t)(uint32_t) t1);
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 723u || l0.tag == 845u || l0.tag == 846u || l0.tag == 847u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(340u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 730u || l0.tag == 867u || l0.tag == 868u || l0.tag == 869u)) {
        if (l1 == INT64_C(2)) {
            l2 = vader_box_i32(340u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else {
        if (!((l0.tag == 721u || l0.tag == 722u || l0.tag == 724u || l0.tag == 725u || l0.tag == 726u || l0.tag == 727u || l0.tag == 728u || l0.tag == 729u || l0.tag == 731u || l0.tag == 752u || l0.tag == 753u || l0.tag == 754u || l0.tag == 755u || l0.tag == 756u || l0.tag == 757u || l0.tag == 758u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u || l0.tag == 762u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 768u || l0.tag == 769u || l0.tag == 770u || l0.tag == 771u || l0.tag == 774u || l0.tag == 775u || l0.tag == 777u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 784u || l0.tag == 795u || l0.tag == 796u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 805u || l0.tag == 825u || l0.tag == 840u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 848u || l0.tag == 849u || l0.tag == 850u || l0.tag == 851u || l0.tag == 852u || l0.tag == 853u || l0.tag == 854u || l0.tag == 855u || l0.tag == 856u || l0.tag == 857u || l0.tag == 858u || l0.tag == 859u || l0.tag == 860u || l0.tag == 861u || l0.tag == 862u || l0.tag == 863u || l0.tag == 864u || l0.tag == 865u || l0.tag == 866u || l0.tag == 870u || l0.tag == 871u || l0.tag == 872u || l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 877u || l0.tag == 878u || l0.tag == 879u || l0.tag == 892u || l0.tag == 893u || l0.tag == 894u || l0.tag == 895u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    return l2;
}

static int64_t vader_vm$adapter_of(void* l0, int32_t l1) {
    int64_t l2, l3;
    int64_t t0;
    l2 = ((int64_t) (int32_t) l1);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_adapters)->length;
    if (!((l2 >= l3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_adapters);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
        return t0;
    }
    return INT64_C(0);
}

static vader_box_t vader_vm$adapter_reason(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    int64_t l5, l6, l7, l8, l12, l14, l16;
    bool l9, l17;
    int32_t l10;
    uint8_t l18;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    bool t5;
    vader_box_t* gc_roots[2] = { &l2, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l11, &l13, &l15, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_library;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_std_ffi$CLibrary_t*) t0)->f_archives)->length;
        if ((t1 > INT64_C(0))) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_std_ffi$CLibrary_t*) t0)->f_name;
            t2 = concat_3(2223u, l3, 1237u);
            { vader_box_t __vret = vader_box_string(335u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params)->length;
    if ((t1 > INT64_C(8))) {
        { vader_box_t __vret = vader_box_string(335u, 2217u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = INT64_C(0);
    l6 = INT64_C(0);
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params)->length;
    while ((l7 < l8)) {
        l9 = vader_core_bytecode$param_is_by_address(l4, l7);
        if (!(l9)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l10 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
            t3 = vader_core_bytecode$mirror_at(l1, l10);
            if (!(t3.tag == 0u)) {
                l11 = (void*) vader_buffer_new((size_t) INT64_C(54));
                l12 = INT64_C(0);
                l12 = std_core$write_string_at(l11, l12, 1550u);
                l12 = std_core$write_int(l11, l12, l7);
                l12 = std_core$write_string_at(l11, l12, 202u);
                t2 = std_core$finish_buffer(l11, l12);
                { vader_box_t __vret = vader_box_string(335u, t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l7, 340u);
        if (((int32_t) t3.payload.i) == INT32_C(8)) {
            l13 = (void*) vader_buffer_new((size_t) INT64_C(41));
            l14 = INT64_C(0);
            l14 = std_core$write_string_at(l13, l14, 1550u);
            l14 = std_core$write_int(l13, l14, l7);
            l14 = std_core$write_string_at(l13, l14, 150u);
            t2 = std_core$finish_buffer(l13, l14);
            { vader_box_t __vret = vader_box_string(335u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t3 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l7, 340u);
        if (((int32_t) t3.payload.i) == INT32_C(11)) {
            l15 = (void*) vader_buffer_new((size_t) INT64_C(41));
            l16 = INT64_C(0);
            l16 = std_core$write_string_at(l15, l16, 1550u);
            l16 = std_core$write_int(l15, l16, l7);
            l16 = std_core$write_string_at(l15, l16, 146u);
            t2 = std_core$finish_buffer(l15, l16);
            { vader_box_t __vret = vader_box_string(335u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t3 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 340u);
        if (((int32_t) t3.payload.i) == INT32_C(9)) {
            l17 = !(l9);
        } else {
            l17 = false;
        }
        if (l17) {
            l6 = vader_chk_add(i64, l6, INT64_C(1));
        } else {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l18 = vader_core_bytecode$bc_single_result(l4);
    l10 = vader_core_bytecode$bc_single_result_type(l4);
    t3 = vader_core_bytecode$mirror_at(l1, l10);
    if (!(t3.tag == 0u)) {
        { vader_box_t __vret = vader_box_string(335u, 2214u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l18 == INT32_C(8)) {
        { vader_box_t __vret = vader_box_string(335u, 2215u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l6 > INT64_C(0))) {
        if ((l5 > INT64_C(0))) {
            { vader_box_t __vret = vader_box_string(335u, 2213u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if ((l6 > INT64_C(2))) {
        { vader_box_t __vret = vader_box_string(335u, 2218u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT64_C(0)) {
        if (l18 == INT32_C(9)) {
            { vader_box_t __vret = vader_box_string(335u, 2216u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if ((l6 > INT64_C(0))) {
        if (l18 != INT32_C(9)) {
            { vader_box_t __vret = vader_box_string(335u, 2224u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
    if ((t4 >= INT32_C(0))) {
        t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
        l5 = ((int64_t) (int32_t) t4);
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params)->length;
        t5 = vader_vm$is_covered_variadic(l5, l7, l6);
        if (!(t5)) {
            { vader_box_t __vret = vader_box_string(335u, 2229u); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm$add_constant(vader_box_t l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    int64_t l6;
    uint8_t l7;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l0, &l5 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_vm$scalar_of(l0);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l5.payload.obj;
    l6 = ((vader_array_t*) l1)->length;
    t0 = std_collections$get_or_put__vader_vm_Scalar__i64(l3, l4, l6);
    if (t0 == l6) {
        l6 = ((vader_struct_vader_vm$Scalar_t*) l4)->f_bits;
        vader_array_push_i64((vader_array_t*) l1, l6);
        l7 = ((vader_struct_vader_vm$Scalar_t*) l4)->f_tag;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4, bool l5) {
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
    if (l2.tag == 797u) {
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        vader_struct_vader_vm$FnVal_t* _a0_obj = (vader_struct_vader_vm$FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FnVal_t));
        vader_obj_header_init(_a0_obj, 1422u);
        _a0_obj->f_function_index = t1;
        _a0_obj->f_env = vader_box_obj(0u, NULL);
        l7 = (void*) _a0_obj;
        vader_vm$push_val(l3, l6, vader_ref_box(l7));
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l2.tag == 854u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_owned(l3, l6);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        vader_struct_vader_vm$FnVal_t* _a1_obj = (vader_struct_vader_vm$FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FnVal_t));
        vader_obj_header_init(_a1_obj, 1422u);
        _a1_obj->f_function_index = t1;
        _a1_obj->f_env = l9;
        l7 = (void*) _a1_obj;
        vader_vm$push_val(l3, l6, vader_ref_box(l7));
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 876u) {
        l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l9 = vader_vm$build_struct(l7, l8, l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 725u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l9 = vader_vm$build_array(l8, l10, l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 731u) {
        l7 = l2.payload.obj;
        l9 = vader_vm$exec_array_slice(l3, l7);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 729u) {
        l9 = vader_vm$exec_array_repeat(l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 727u) {
        l9 = vader_vm$exec_array_push_all(l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 722u) {
        l9 = vader_vm$exec_array_copy(l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 728u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$peek_array_mut(l3, l6, l8, 1579u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        t2 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
        if (t2 == INT64_C(0)) {
            l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(5);
        } else {
            t0 = l9.payload.obj;
            vader_vm$own_bytes(t0);
            t0 = l9.payload.obj;
            l7 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
            t0 = l9.payload.obj;
            l6 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset;
            t0 = l9.payload.obj;
            l11 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
            t2 = vader_chk_add(i64, l6, l11);
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l12 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6];
            t0 = l9.payload.obj;
            t2 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset;
            if (t2 == INT64_C(0)) {
                t0 = l9.payload.obj;
                l6 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
                t0 = l9.payload.obj;
                l11 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements)->length;
                if (l6 == l11) {
                    t0 = l9.payload.obj;
                    t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
                }
            }
            l7 = l9.payload.obj;
            t0 = l9.payload.obj;
            t2 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            ((vader_struct_vader_vm$ArrayVal_t*) l7)->f_length = l6;
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_vm$push_val(l3, l6, l12);
        }
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 721u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$peek_array_mut(l3, l6, l8, 1561u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_raw = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) t0);
        t0 = l9.payload.obj;
        t2 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset;
        if (t2 == INT64_C(0)) {
            t0 = l9.payload.obj;
            l6 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
            t0 = l9.payload.obj;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements)->length;
            l13 = l6 == l11;
        } else {
            l13 = false;
        }
        if (l13) {
            t0 = l9.payload.obj;
            vader_array_clear((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
        } else {
            l7 = l9.payload.obj;
            vader_array_t* _a4_arr = vader_array_new(269u, 0u, 0u, 2153u);
            l14 = (void*) _a4_arr;
            ((vader_struct_vader_vm$ArrayVal_t*) l7)->f_elements = l14;
            VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) l7);
        }
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset = INT64_C(0);
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length = INT64_C(0);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 798u) {
        if (l5) {
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
            t0 = vader_vm$global_at_comptime_trap(l0, l8);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l7 = ((vader_struct_vader_vm$VmState_t*) l0)->f_globals;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l9 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l8];
        vader_vm$push_val(l3, l6, l9);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 799u) {
        if (l5) {
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
            t0 = vader_vm$global_at_comptime_trap(l0, l8);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$VmState_t*) l0)->f_globals;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_owned(l3, l6);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l8] = l9;
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 775u) {
        l7 = ((vader_struct_vader_vm$VmState_t*) l0)->f_data_pool;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        l7 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) l7)->f_type_id;
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        if (l8 == l10) {
            l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            vader_vm$push_val(l3, l6, vader_ref_box(l7));
        } else {
            l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
            l14 = ((vader_struct_vader_vm$ArrayVal_t*) l7)->f_elements;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l7)->f_elements)->length;
            vader_struct_vader_vm$ArrayVal_t* _a8_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
            vader_obj_header_init(_a8_obj, 1418u);
            _a8_obj->f_type_id = l8;
            _a8_obj->f_elements = l14;
            _a8_obj->f_offset = INT64_C(0);
            _a8_obj->f_length = l11;
            _a8_obj->f_raw = vader_box_obj(0u, NULL);
            l7 = (void*) _a8_obj;
            vader_vm$push_val(l3, l6, vader_ref_box(l7));
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 774u) {
        t0 = l2.payload.obj;
        l15 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
        t0 = l2.payload.obj;
        l16 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t4 = vader_vm$convert_int_fast(l3, l15, l16);
        if (!(t4)) {
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            l9 = vader_vm$peek_val(l3, l6);
            t0 = l2.payload.obj;
            l15 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
            t0 = l2.payload.obj;
            l16 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
            l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l12 = vader_vm$convert_value(l9, l15, l16, l8);
            if (l12.tag == 1446u) {
                t0 = l12.payload.obj;
                l16 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
                l17 = vader_vm$describe_value_tag(l9);
                t5 = concat_6(l16, 53u, l17, 334u, l4, 288u);
                vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a9_obj, 1446u);
                _a9_obj->f_message = t5;
                t0 = (void*) _a9_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            l9 = l12;
            vader_vm$push_val(l3, l6, l9);
        }
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 863u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        if (!(l9.tag == 1447u)) {
            l16 = vader_vm$describe_value_tag(l9);
            l6 = vader_host_std_core$byte_len(l16);
            l7 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l6));
            l6 = INT64_C(0);
            l6 = std_core$write_string_at(l7, l6, 2188u);
            l6 = std_core$write_string_at(l7, l6, l16);
            l6 = std_core$write_string_at(l7, l6, 96u);
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l11 = ((int64_t) (int32_t) t1);
            l6 = std_core$write_int(l7, l6, l11);
            t5 = std_core$finish_buffer(l7, l6);
            vader_struct_vader_vm$Trap_t* _a10_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a10_obj, 1446u);
            _a10_obj->f_message = t5;
            t0 = (void*) _a10_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        l8 = ((vader_struct_vader_vm$TypeVal_t*) t0)->f_type_id;
        if ((l8 < INT32_C(0))) {
            l13 = true;
        } else {
            l6 = ((int64_t) (int32_t) l8);
            l11 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types)->length;
            l13 = (l6 >= l11);
        }
        if (l13) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(89));
            l6 = INT64_C(0);
            l6 = std_core$write_string_at(l7, l6, 2189u);
            l11 = ((int64_t) (int32_t) l8);
            l6 = std_core$write_int(l7, l6, l11);
            l6 = std_core$write_string_at(l7, l6, 194u);
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l11 = ((int64_t) (int32_t) t1);
            l6 = std_core$write_int(l7, l6, l11);
            t5 = std_core$finish_buffer(l7, l6);
            vader_struct_vader_vm$Trap_t* _a11_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a11_obj, 1446u);
            _a11_obj->f_message = t5;
            t0 = (void*) _a11_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        l8 = vader_core_bytecode$size_of_bc_type(t3);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l11 = ((int64_t) (int32_t) l8);
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
        ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 807u) {
        l9 = vader_vm$apply_eq_binop(l3, 2084u, false);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 814u) {
        l9 = vader_vm$apply_eq_binop(l3, 2091u, true);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 757u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1630u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_bool(l12, l8, 1630u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a16_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 758u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1631u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_bool(l12, l8, 1631u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a18_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
        ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 755u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1628u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_bool(l12, l8, 1628u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
        ((uint8_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 760u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1633u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_bool(l12, l8, 1633u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a22_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l6)
        ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 759u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1632u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a24_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
        ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 873u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_string(l9, l8, 2643u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_string(l12, l8, 2643u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a26_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l6)
        ((uint8_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 874u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_string(l9, l8, 2645u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_string(l12, l8, 2645u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l6)
        ((uint8_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 871u) {
        l9 = vader_vm$exec_string_compare(l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 858u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l13 = vader_vm$value_ref_eq(l9, l12);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a30_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
        ((uint8_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 859u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l12 = vader_vm$peek_val(l3, l6);
        l13 = vader_vm$value_ref_eq(l9, l12);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a32_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l6)
        ((uint8_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 878u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        l13 = vader_vm$type_matches(l0, l9, l8);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
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
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a34_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l6)
        ((uint8_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 879u) {
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        vader_struct_vader_vm$TypeVal_t* _a35_obj = (vader_struct_vader_vm$TypeVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$TypeVal_t));
        vader_obj_header_init(_a35_obj, 1447u);
        _a35_obj->f_type_id = t1;
        l7 = (void*) _a35_obj;
        vader_vm$push_val(l3, l6, vader_ref_box(l7));
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 763u) {
        l7 = ((vader_struct_vader_vm$RunHost_t*) l1)->f_obj_handles;
        l9 = vader_vm$build_buffer(l3, l7);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 848u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(1), 2275u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t6));
        vader_array_t* _a36_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
        ((int64_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a37_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l6)
        ((uint8_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 843u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(4), 2269u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t6));
        vader_array_t* _a38_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l6)
        ((int64_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a39_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l6)
        ((uint8_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 844u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(8), 2270u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = ((int64_t) (uint64_t) t6);
        vader_array_t* _a40_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l6)
        ((int64_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a41_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l6)
        ((uint8_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 842u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(8), 2268u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t6) }).__vd) }).__vu);
        vader_array_t* _a42_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l6)
        ((int64_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a43_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l6)
        ((uint8_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 870u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$stack_i32(l3, l6, 2636u, 2979u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l9.payload.i);
        t2 = ((int64_t) (uint32_t) (t1 & INT32_C(255)));
        l19 = (uint64_t) (int64_t) t2;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(1), l19, 2636u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 865u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$stack_i32(l3, l6, 2629u, 2979u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l9.payload.i);
        t2 = ((int64_t) (uint32_t) t1);
        l19 = (uint64_t) (int64_t) t2;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(4), l19, 2629u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 866u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i64(l9, l8, 2631u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int64_t) l9.payload.i);
        t7 = t2;
        l19 = (uint64_t) (int64_t) t7;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(8), l19, 2630u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 864u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_f64(l9, l8, 2628u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t8 = ((double) l9.payload.f);
        t2 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
        l19 = (uint64_t) (int64_t) t2;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(8), l19, 2627u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 855u) {
        l9 = vader_vm$do_memory_copy(l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 764u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i32(l9, l8, 1653u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l12 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l12 = vader_vm$read_obj(l12, l8, 1654u);
        if (l12.tag == 1446u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((int32_t) l9.payload.i);
        t0 = l12.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t0)->f_bytes)->length;
        l10 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$check_byte_range(l8, INT64_C(0), l6, 1652u, l10);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t0 = l12.payload.obj;
        l7 = ((vader_struct_vader_vm$ObjVal_t*) t0)->f_bytes;
        l11 = ((int64_t) l9.payload.i);
        vader_array_t* _a44_arr = vader_array_slice((vader_array_t*) l7, (int64_t) INT64_C(0), (int64_t) l11);
        t0 = (void*) _a44_arr;
        l16 = vader_host_std_core$bytes_to_string(t0);
        vader_vm$push_val(l3, l6, vader_box_string(335u, l16));
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 765u) {
        l9 = vader_vm$exec_buffer_write_string(l3);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 795u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_f64(l9, l8, 1965u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t8 = ((double) l9.payload.f);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
        vader_array_t* _a45_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l6)
        ((int64_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a46_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l6)
        ((uint8_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 753u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i64(l9, l8, 1624u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t2 = ((int64_t) l9.payload.i);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t2) }).__vd) }).__vu);
        vader_array_t* _a47_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l6)
        ((int64_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a48_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l6)
        ((uint8_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 782u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_f64(l9, l8, 1951u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t8 = ((double) l9.payload.f);
        l11 = ((int64_t) (int32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = t8 }).__vb));
        vader_array_t* _a49_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l6)
        ((int64_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a50_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l6)
        ((uint8_t*) _a50_slotarr->buf->slots)[_a50_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 752u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i32(l9, l8, 1623u);
        if (l9.tag == 1446u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t1 = ((int32_t) l9.payload.i);
        l11 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(t1) }).__vf)) }).__vu);
        vader_array_t* _a51_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l6)
        ((int64_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l6] = (int64_t) l11;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a52_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l6)
        ((uint8_t*) _a52_slotarr->buf->slots)[_a52_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$apply_eq_binop(void* l0, vader_string_t l1, bool l2) {
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
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 340u);
    l5 = ((uint8_t) t1.payload.i);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 340u);
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
        t2 = vader_vm$is_i32_tag(l5);
        if (t2) {
            l8 = vader_vm$is_i32_tag(l6);
        } else {
            l8 = false;
        }
        if (l8) {
            l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(2));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            l9 = ((int32_t) (int64_t) t0);
            l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
            l10 = ((int32_t) (int64_t) t0);
            l7 = l9 == l10;
        } else {
            t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(2));
            l11 = vader_vm$peek_val(l0, l4);
            l9 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
            l11 = vader_vm$read_i32(l11, l9, l1);
            t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            l12 = vader_vm$peek_val(l0, l4);
            l9 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
            l12 = vader_vm$read_i32(l12, l9, l1);
            if (l11.tag == 1446u) {
                t3 = l11.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l12.tag == 1446u) {
                t3 = l12.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = ((int32_t) l11.payload.i);
            l10 = ((int32_t) l12.payload.i);
            l7 = l9 == l10;
        }
    }
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
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
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) INT32_C(3);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l4;
    t4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l9 = vader_chk_add(i32, t4, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l9;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$array_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 1418u) {
            t1 = l2.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_vm$array_bytes(void* l0, int64_t l1, int32_t l2, vader_string_t l3) {
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
    l4 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.s;
        l5 = vader_host_std_core$bytes(t0);
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
        t1 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
        l7 = vader_chk_add(i64, t1, l1);
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l5, (int64_t) l6, (int64_t) l7);
        t2 = (void*) _a0_arr;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(25u, 0u, 1u, 340u);
    l5 = (void*) _a1_arr;
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements;
        t1 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
        l7 = vader_chk_add(i64, t1, l6);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l4 = vader_vm$read_i64(t3, l2, l3);
        if (l4.tag == 1446u) {
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

static vader_box_t vader_vm$bc_value_to_vm(vader_box_t l0, void* l1) {
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
    if (l0.tag == 750u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        { vader_box_t __vret = vader_box_string(335u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 749u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t2 = vader_vm$value_from_bits(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 751u) {
        vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
        l4 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l8 = vader_vm$bc_value_to_vm(t2, l1);
            vader_array_push((vader_array_t*) l4, l8);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        t3 = vader_vm$type_id_for_symbol(l1, l9);
        vader_struct_vader_vm$StructVal_t* _a2_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
        vader_obj_header_init(_a2_obj, 1443u);
        _a2_obj->f_type_id = t3;
        _a2_obj->f_fields = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 748u)) {
        { vader_box_t __vret = vader_box_i32(338u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l4 = (void*) _a3_arr;
    t0 = l0.payload.obj;
    l5 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l8 = vader_vm$bc_value_to_vm(t2, l1);
        vader_array_push((vader_array_t*) l4, l8);
        l7 = (l7 + INT64_C(1));
    }
    l6 = ((vader_array_t*) l4)->length;
    vader_struct_vader_vm$ArrayVal_t* _a5_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a5_obj, 1418u);
    _a5_obj->f_type_id = INT32_C(0);
    _a5_obj->f_elements = l4;
    _a5_obj->f_offset = INT64_C(0);
    _a5_obj->f_length = l6;
    _a5_obj->f_raw = vader_box_obj(0u, NULL);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$binary_op(vader_box_t l0, void* l1, int64_t l2) {
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 800u) {
        l3 = vader_box_i32(338u, INT32_C(2));
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 819u) {
        l3 = vader_box_i32(338u, INT32_C(3));
    } else if (l0.tag == 813u) {
        l3 = vader_box_i32(338u, INT32_C(4));
    } else if (l0.tag == 806u) {
        l3 = vader_box_i32(338u, INT32_C(5));
    } else if (l0.tag == 812u) {
        l3 = vader_box_i32(338u, INT32_C(6));
    } else if (l0.tag == 801u) {
        l3 = vader_box_i32(338u, INT32_C(7));
    } else if (l0.tag == 803u) {
        l3 = vader_box_i32(338u, INT32_C(8));
    } else if (l0.tag == 804u) {
        l3 = vader_box_i32(338u, INT32_C(9));
    } else if (l0.tag == 816u) {
        l3 = vader_box_i32(338u, INT32_C(10));
    } else if (l0.tag == 817u) {
        l3 = vader_box_i32(338u, INT32_C(11));
    } else if (l0.tag == 818u) {
        l3 = vader_box_i32(338u, INT32_C(12));
    } else if (l0.tag == 880u) {
        l3 = vader_box_i32(338u, INT32_C(15));
    } else if (l0.tag == 885u) {
        l3 = vader_box_i32(338u, INT32_C(16));
    } else if (l0.tag == 807u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(338u, INT32_C(17));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 814u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(338u, INT32_C(18));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 811u) {
        l3 = vader_box_i32(338u, INT32_C(19));
    } else if (l0.tag == 810u) {
        l3 = vader_box_i32(338u, INT32_C(20));
    } else if (l0.tag == 809u) {
        l3 = vader_box_i32(338u, INT32_C(21));
    } else if (l0.tag == 808u) {
        l3 = vader_box_i32(338u, INT32_C(22));
    } else if (l0.tag == 884u) {
        l3 = vader_box_i32(338u, INT32_C(23));
    } else if (l0.tag == 883u) {
        l3 = vader_box_i32(338u, INT32_C(24));
    } else if (l0.tag == 882u) {
        l3 = vader_box_i32(338u, INT32_C(25));
    } else if (l0.tag == 881u) {
        l3 = vader_box_i32(338u, INT32_C(26));
    } else if (l0.tag == 820u) {
        l3 = vader_box_i32(338u, INT32_C(27));
    } else if (l0.tag == 839u) {
        l3 = vader_box_i32(338u, INT32_C(28));
    } else if (l0.tag == 833u) {
        l3 = vader_box_i32(338u, INT32_C(29));
    } else if (l0.tag == 826u) {
        l3 = vader_box_i32(338u, INT32_C(30));
    } else if (l0.tag == 832u) {
        l3 = vader_box_i32(338u, INT32_C(31));
    } else if (l0.tag == 821u) {
        l3 = vader_box_i32(338u, INT32_C(32));
    } else if (l0.tag == 823u) {
        l3 = vader_box_i32(338u, INT32_C(33));
    } else if (l0.tag == 824u) {
        l3 = vader_box_i32(338u, INT32_C(34));
    } else if (l0.tag == 836u) {
        l3 = vader_box_i32(338u, INT32_C(35));
    } else if (l0.tag == 837u) {
        l3 = vader_box_i32(338u, INT32_C(36));
    } else if (l0.tag == 838u) {
        l3 = vader_box_i32(338u, INT32_C(37));
    } else if (l0.tag == 886u) {
        l3 = vader_box_i32(338u, INT32_C(40));
    } else if (l0.tag == 891u) {
        l3 = vader_box_i32(338u, INT32_C(41));
    } else if (l0.tag == 827u) {
        l3 = vader_box_i32(338u, INT32_C(42));
    } else if (l0.tag == 834u) {
        l3 = vader_box_i32(338u, INT32_C(43));
    } else if (l0.tag == 831u) {
        l3 = vader_box_i32(338u, INT32_C(44));
    } else if (l0.tag == 830u) {
        l3 = vader_box_i32(338u, INT32_C(45));
    } else if (l0.tag == 829u) {
        l3 = vader_box_i32(338u, INT32_C(46));
    } else if (l0.tag == 828u) {
        l3 = vader_box_i32(338u, INT32_C(47));
    } else if (l0.tag == 890u) {
        l3 = vader_box_i32(338u, INT32_C(48));
    } else if (l0.tag == 889u) {
        l3 = vader_box_i32(338u, INT32_C(49));
    } else if (l0.tag == 888u) {
        l3 = vader_box_i32(338u, INT32_C(50));
    } else if (l0.tag == 887u) {
        l3 = vader_box_i32(338u, INT32_C(51));
    } else if (l0.tag == 783u) {
        l3 = vader_box_i32(338u, INT32_C(52));
    } else if (l0.tag == 794u) {
        l3 = vader_box_i32(338u, INT32_C(53));
    } else if (l0.tag == 791u) {
        l3 = vader_box_i32(338u, INT32_C(54));
    } else if (l0.tag == 785u) {
        l3 = vader_box_i32(338u, INT32_C(55));
    } else if (l0.tag == 786u) {
        l3 = vader_box_i32(338u, INT32_C(57));
    } else if (l0.tag == 792u) {
        l3 = vader_box_i32(338u, INT32_C(58));
    } else if (l0.tag == 790u) {
        l3 = vader_box_i32(338u, INT32_C(59));
    } else if (l0.tag == 789u) {
        l3 = vader_box_i32(338u, INT32_C(60));
    } else if (l0.tag == 788u) {
        l3 = vader_box_i32(338u, INT32_C(61));
    } else if (l0.tag == 787u) {
        l3 = vader_box_i32(338u, INT32_C(62));
    } else if (l0.tag == 757u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(338u, INT32_C(63));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 758u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(338u, INT32_C(64));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 755u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(338u, INT32_C(65));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 760u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(338u, INT32_C(66));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 772u) {
        t1 = l0.payload.obj;
        t2 = vader_vm$checked_register_op(t1);
        l3 = vader_box_i32(338u, t2);
    } else {
        l3 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$bits_of(void* l0, int64_t l1, int32_t l2) {
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

static void vader_vm$boxed(void* l0, int64_t l1, vader_box_t l2, int64_t l3, int64_t l4) {
    int32_t l5, l6, l7;
    int64_t l8;
    int64_t t0, t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_vm$flush(l0, l1);
    l5 = vader_vm$pop_to(l0, l3);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_boxed, l2.payload.obj);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_boxed)->length;
    t1 = vader_chk_sub(i64, t0, INT64_C(1));
    l6 = ((int32_t) (int64_t) t1);
    l7 = vader_vm$boxed_counts(l3, l4);
    vader_vm$emit(l0, l1, INT32_C(119), l6, l5, l7);
    l8 = INT64_C(0);
    while ((l8 < l4)) {
        l6 = ((int32_t) (int64_t) l8);
        l7 = vader_chk_add(i32, l5, l6);
        vader_vm$push_register(l0, l7);
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_vm$boxed_counts(int64_t l0, int64_t l1) {
    return ((int32_t) (int64_t) ((l0 << INT64_C(2)) | l1));
}

static int64_t vader_vm$boxed_pops(int32_t l0) {
    return (((int64_t) (int32_t) l0) >> INT64_C(2));
}

static int64_t vader_vm$boxed_pushes(int32_t l0) {
    int64_t l1, l2;
    l1 = ((int64_t) (int32_t) l0);
    l2 = vader_chk_sub(i64, (INT64_C(1) << INT64_C(2)), INT64_C(1));
    return (l1 & l2);
}

static void* vader_vm$branch(bool l0, int32_t l1, bool l2, int32_t l3, bool l4) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0) {
        vader_struct_vader_vm$FusedBranch_t* _a0_obj = (vader_struct_vader_vm$FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FusedBranch_t));
        vader_obj_header_init(_a0_obj, 1425u);
        _a0_obj->f_op = l1;
        _a0_obj->f_swap = l2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$FusedBranch_t* _a1_obj = (vader_struct_vader_vm$FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FusedBranch_t));
    vader_obj_header_init(_a1_obj, 1425u);
    _a1_obj->f_op = l3;
    _a1_obj->f_swap = l4;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$budget_trap(int64_t l0) {
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
    l2 = std_core$write_string_at(l1, l2, 1777u);
    l2 = std_core$write_int(l1, l2, l0);
    l2 = std_core$write_string_at(l1, l2, 216u);
    t0 = std_core$finish_buffer(l1, l2);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1446u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$build_array(int32_t l0, int32_t l1, void* l2) {
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
        l4 = std_core$write_string_at(l3, l4, 1573u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 156u);
        t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core$write_int(l3, l4, l5);
        t1 = std_core$finish_buffer(l3, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) (int32_t) l1);
    t3 = ((vader_struct_vader_vm$Frame_t*) l2)->f_sp;
    l5 = vader_chk_sub(i64, t3, l4);
    vader_array_t* _a1_arr = vader_array_new(269u, 0u, 0u, 2153u);
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (int64_t) l4);
    l3 = (void*) _a2_arr;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        l7 = vader_chk_add(i64, l5, l6);
        l8 = vader_vm$peek_owned(l2, l7);
        vader_array_push((vader_array_t*) l3, l8);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_array_t*) l3)->length;
    vader_struct_vader_vm$ArrayVal_t* _a3_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1418u);
    _a3_obj->f_type_id = l0;
    _a3_obj->f_elements = l3;
    _a3_obj->f_offset = INT64_C(0);
    _a3_obj->f_length = l4;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    l3 = (void*) _a3_obj;
    vader_vm$push_val(l2, l5, vader_ref_box(l3));
    l4 = vader_chk_add(i64, l5, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_sp = l4;
    t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
    l9 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_pc = l9;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$build_buffer(void* l0, void* l1) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l4, 1650u);
    if (l3.tag == 1446u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l3.payload.i);
    if ((t2 < INT32_C(0))) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(75));
        l2 = INT64_C(0);
        l2 = std_core$write_string_at(l5, l2, 1651u);
        t2 = ((int32_t) l3.payload.i);
        l6 = ((int64_t) (int32_t) t2);
        l2 = std_core$write_int(l5, l2, l6);
        l2 = std_core$write_string_at(l5, l2, 156u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l6 = ((int64_t) (int32_t) t2);
        l2 = std_core$write_int(l5, l2, l6);
        t3 = std_core$finish_buffer(l5, l2);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(25u, 0u, 1u, 340u);
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
    vader_array_t* _a4_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l7 = (void*) _a4_arr;
    vader_struct_vader_vm$ObjVal_t* _a5_obj = (vader_struct_vader_vm$ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ObjVal_t));
    vader_obj_header_init(_a5_obj, 1430u);
    _a5_obj->f_handle = l4;
    _a5_obj->f_type_id = INT32_C(0);
    _a5_obj->f_bytes = l5;
    _a5_obj->f_slots = l7;
    l5 = (void*) _a5_obj;
    vader_vm$push_val(l0, l2, vader_ref_box(l5));
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$build_main_args(void* l0, void* l1, int32_t l2) {
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
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params;
    t0 = ((vader_array_t*) l4)->length;
    if (t0 == INT64_C(0)) {
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l4)->length;
    if ((t0 > INT64_C(1))) {
        l5 = ((vader_array_t*) l4)->length;
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
        l7 = vader_host_std_core$byte_len(l6);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l7));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l8, l7, 1881u);
        l7 = std_core$write_string_at(l8, l7, l6);
        l7 = std_core$write_string_at(l8, l7, 298u);
        l7 = std_core$write_int(l8, l7, l5);
        l7 = std_core$write_string_at(l8, l7, 201u);
        t1 = std_core$finish_buffer(l8, l7);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1446u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(0), 340u);
    l9 = vader_vm$tags_of_val(((uint8_t) t3.payload.i));
    t4 = vader_vm$tags_within((uint8_t) 64, l9);
    if (!(t4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t3 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) INT32_C(0), 340u);
        l6 = vader_core_bytecode$val_type_name(((uint8_t) t3.payload.i));
        l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
        t1 = concat_5(1881u, l10, 299u, l6, 371u);
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 1446u);
        _a4_obj->f_message = t1;
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a5_arr = vader_array_new(22u, 1u, 0u, 335u);
        vader_array_box_slots(_a5_arr->buf)[_a5_arr->offset + 0u] = vader_box_string(335u, 519u);
        t2 = (void*) _a5_arr;
        l4 = vader_vm$string_array_to_value(t2, l2);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$string_array_to_value(l1, l2);
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$build_struct(void* l0, int32_t l1, void* l2) {
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
    if (!(l3.tag == 746u)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(79));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 2664u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l4, l5, l6);
        l5 = std_core$write_string_at(l4, l5, 159u);
        t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
        l6 = ((int64_t) (int32_t) t0);
        l5 = std_core$write_int(l4, l5, l6);
        t1 = std_core$finish_buffer(l4, l5);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1446u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l3.payload.obj;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields)->length;
    t3 = ((vader_struct_vader_vm$Frame_t*) l2)->f_sp;
    l6 = vader_chk_sub(i64, t3, l5);
    vader_array_t* _a2_arr = vader_array_new(269u, 0u, 0u, 2153u);
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
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcField_t*) t2)->f_type_index;
        l9 = vader_vm$field_valtype(l0, l8);
        l10 = vader_chk_add(i64, l6, l7);
        t4 = vader_vm$peek_owned(l2, l10);
        l11 = vader_vm$narrow_mask(t4, l9);
        vader_array_push((vader_array_t*) l4, l11);
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_vm$StructVal_t* _a5_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
    vader_obj_header_init(_a5_obj, 1443u);
    _a5_obj->f_type_id = l1;
    _a5_obj->f_fields = l4;
    l4 = (void*) _a5_obj;
    vader_vm$push_val(l2, l6, vader_ref_box(l4));
    l5 = vader_chk_add(i64, l6, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_sp = l5;
    t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
    l8 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_pc = l8;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_vm$bytes_to_value(vader_string_t l0, int32_t l1) {
    void* l2 = NULL;
    int64_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core$byte_len(l0);
    vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a1_obj, 1418u);
    _a1_obj->f_type_id = l1;
    _a1_obj->f_elements = l2;
    _a1_obj->f_offset = INT64_C(0);
    _a1_obj->f_length = l3;
    _a1_obj->f_raw = vader_box_string(335u, l0);
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$call_foreign(int64_t l0, bool l1, void* l2, void* l3, int64_t l4) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1)) {
        t0 = vader_host_vader_vm$ffi_call(l0, l2, l3, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_vader_vm$ffi_call_frame(l0, l2, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$call_import(void* l0, void* l1, int32_t l2, int64_t l3, int32_t l4, bool l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    int64_t l8, l9, l10;
    vader_box_t l11 = vader_box_null();
    int32_t l14, l15;
    uint8_t l17;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    uint8_t t2;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l6, &l7, &l12, &l13, &l16, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    vader_array_t* _a1_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l7 = (void*) _a1_arr;
    l8 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l8);
    l7 = (void*) _a2_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params)->length;
    while ((l8 < l9)) {
        l10 = vader_chk_add(i64, l3, l8);
        l11 = vader_vm$register_value(l1, l10);
        vader_array_push((vader_array_t*) l7, l11);
        l8 = (l8 + INT64_C(1));
    }
    l12 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_gc_state;
    l13 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_sched_state;
    l14 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
    l15 = ((vader_struct_vader_vm$VmState_t*) l0)->f_u8_array_type_id;
    l16 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l11 = vader_vm$debug_controller(l1);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_import_ids);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
    t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 340u);
    l17 = ((uint8_t) t0.payload.i);
    l8 = vader_vm$adapter_of(l0, l2);
    l11 = vader_vm$dispatch_import(l6, l7, INT64_C(0), l12, l13, l4, l14, l15, l16, l5, l11, l17, l8);
    if (l11.tag == 1446u) {
        t1 = l11.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature);
    if (t2 != INT32_C(14)) {
        t1 = l11.payload.obj;
        l11 = ((vader_struct_vader_vm$HostOk_t*) t1)->f_value;
        vader_vm$set_register(l1, l3, l11);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$call_results(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    int32_t l4;
    void* t0;
    l2 = ((vader_struct_vader_vm$TagContext_t*) l0)->f_module;
    if (l1.tag == 768u) {
        l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l2)->f_functions;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        return vader_ref_box(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature)->f_results);
    }
    if (l1.tag == 769u) {
        l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l2)->f_imports;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        return vader_ref_box(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature)->f_results);
    }
    if (!(l1.tag == 895u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results);
}

static vader_box_t vader_vm$callee_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3, l6, l7;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l8 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l8, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 != INT64_C(0)) {
        { vader_box_t __vret = vader_box_i64(339u, l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$library_name(l0);
    l3 = vader_host_vader_vm$ffi_open(t0);
    if (l3 == INT64_C(0)) {
        l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
        l5 = vader_vm$unopened_reason(l0);
        l6 = vader_host_std_core$byte_len(l4);
        l7 = vader_host_std_core$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, 1947u);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 1064u);
        l7 = ((int64_t) (int32_t) l2);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 462u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t0 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    l3 = vader_host_vader_vm$ffi_symbol(l3, l4);
    if (!(l3 == INT64_C(0))) {
        { vader_box_t __vret = vader_box_i64(339u, l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    l3 = vader_host_std_core$byte_len(l4);
    l8 = (void*) vader_buffer_new((size_t) (INT64_C(54) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l8, l3, 1947u);
    l3 = std_core$write_string_at(l8, l3, l4);
    l3 = std_core$write_string_at(l8, l3, 1064u);
    l6 = ((int64_t) (int32_t) l2);
    l3 = std_core$write_int(l8, l3, l6);
    l3 = std_core$write_string_at(l8, l3, 494u);
    t0 = std_core$finish_buffer(l8, l3);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t0;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$canonical(void* l0, int64_t l1) {
    int64_t t0, t1;
    t0 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack_base;
    t1 = vader_chk_add(i64, t0, l1);
    return ((int32_t) (int64_t) t1);
}

static vader_box_t vader_vm$check_byte_range(int32_t l0, int64_t l1, int64_t l2, vader_string_t l3, int32_t l4) {
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
        l6 = vader_host_std_core$byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(67) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l7, l6, l5);
        l6 = std_core$write_string_at(l7, l6, 189u);
        l8 = ((int64_t) (int32_t) l0);
        l6 = std_core$write_int(l7, l6, l8);
        l6 = std_core$write_string_at(l7, l6, 156u);
        l8 = ((int64_t) (int32_t) l4);
        l6 = std_core$write_int(l7, l6, l8);
        t0 = std_core$finish_buffer(l7, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int64_t) (int32_t) l0);
    t2 = vader_chk_add(i64, l6, l1);
    if (!((t2 > l2))) {
        { vader_box_t __vret = vader_box_i64(339u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l8 = vader_host_std_core$byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l7, l8, l5);
    l8 = std_core$write_string_at(l7, l8, 189u);
    l8 = std_core$write_int(l7, l8, l6);
    l8 = std_core$write_string_at(l7, l8, 47u);
    l8 = std_core$write_int(l7, l8, l1);
    l8 = std_core$write_string_at(l7, l8, 333u);
    l8 = std_core$write_int(l7, l8, l2);
    l8 = std_core$write_string_at(l7, l8, 96u);
    l6 = ((int64_t) (int32_t) l4);
    l8 = std_core$write_int(l7, l8, l6);
    t0 = std_core$finish_buffer(l7, l8);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t0;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$check_module_tags(void* l0, void* l1) {
    int64_t l2, l3, l6, l7, l9;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    uint8_t l10, l12;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l8, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l13, &l14, &l15, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        l6 = INT64_C(0);
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) l5)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
            if ((t0 < INT64_C(0))) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
            l9 = INT64_C(1);
            while ((l9 <= INT64_C(2))) {
                l11 = vader_vm$accepted_tags(l8, l9);
                if (l11.tag == 0u) {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
                l10 = ((uint8_t) l11.payload.i);
                l12 = vader_vm$stack_tags(l5, l6, l9);
                t1 = vader_vm$tags_within(l12, l10);
                if (!(t1)) {
                    l13 = vader_vm$display_tags(l12);
                    l14 = vader_vm$display_tags(l10);
                    l15 = vader_vm$op_text(l8);
                    l16 = concat_6(1035u, l15, 1191u, l13, 234u, l14);
                    t2 = vader_vm$defect(l4, l6, l16);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l9 = (l9 + INT64_C(1));
            }
            l6 = (l6 + INT64_C(1));
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static int32_t vader_vm$checked_neg_register_op(uint8_t l0) {
    if (l0 == INT32_C(2)) {
        return INT32_C(71);
    }
    if (!(l0 == INT32_C(3))) {
        return INT32_C(82);
    }
    return INT32_C(75);
}

static void* vader_vm$checked_neg_trap(uint8_t l0, void* l1, int64_t l2) {
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
    l3 = vader_core_bytecode$checked_neg_message(l0);
    l4 = vader_host_std_core$byte_len(l3);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l5, l4, l3);
    l4 = std_core$write_string_at(l5, l4, 96u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    l6 = ((int64_t) (int32_t) t0);
    l4 = std_core$write_int(l5, l4, l6);
    t1 = std_core$finish_buffer(l5, l4);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t1;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$checked_register_op(void* l0) {
    uint8_t l1;
    int32_t l2;
    bool t0;
    if (((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_kind == INT32_C(2)) {
        l1 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_op;
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
    if (((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_kind == INT32_C(3)) {
        l1 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_op;
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
    t0 = vader_core_bytecode$is_u64_class(((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_kind);
    if (t0) {
        l1 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_op;
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
    l1 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) l0)->f_op;
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

static vader_box_t vader_vm$checked_registers(uint8_t l0, uint8_t l1, void* l2, int64_t l3, int64_t l4) {
    int32_t l5;
    int64_t l6, l7;
    vader_box_t t0;
    l5 = vader_vm$operand_b(l4);
    l6 = vader_vm$bits_of(l2, l3, l5);
    l5 = vader_vm$operand_c(l4);
    l7 = vader_vm$bits_of(l2, l3, l5);
    t0 = vader_core_bytecode$checked_arith(l0, l1, l6, l7);
    return t0;
}

static void* vader_vm$checked_trap(uint8_t l0, uint8_t l1, void* l2, int64_t l3) {
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
    l4 = vader_core_bytecode$checked_overflow_message(l0, l1);
    l5 = vader_host_std_core$byte_len(l4);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l5));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l6, l5, l4);
    l5 = std_core$write_string_at(l6, l5, 96u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core$write_int(l6, l5, l7);
    t1 = std_core$finish_buffer(l6, l5);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t1;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$clamp_nonneg(int32_t l0) {
    if ((l0 < INT32_C(0))) {
        return INT64_C(0);
    }
    return ((int64_t) (int32_t) l0);
}

static bool vader_vm$class_matches(vader_box_t l0, uint8_t l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = vader_core_bytecode$val_type_name(l1);
    l3 = vader_vm$describe_value_tag(l0);
    if (l2 == l3) {
        return true;
    }
    t0 = vader_vm$is_integer_alias(l1);
    if (t0) {
        if (l0.tag == 338u) {
            return true;
        }
        return l0.tag == 339u;
    }
    if (l1 == INT32_C(8)) {
        return (l0.tag == 344u || l0.tag == 345u);
    }
    if (!(l1 == INT32_C(15))) {
        return false;
    }
    if (l0.tag == 339u) {
        return true;
    }
    return l0.tag == 338u;
}

static void vader_vm$collect_constants(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 862u) {
            t0 = l7.payload.obj;
            vader_vm$add_constant(((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value, l1, l2, l3);
        } else if ((l7.tag == 756u || l7.tag == 771u || l7.tag == 784u || l7.tag == 805u || l7.tag == 825u || l7.tag == 856u)) {
            vader_vm$add_constant(l7, l1, l2, l3);
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$comptime_refusal(uint8_t l0) {
    vader_box_t l1;
    bool l2;
    if (l0 == INT32_C(21)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(22);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(23);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(24);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(25);
    }
    if (l2) {
        l1 = vader_box_string(335u, 2208u);
        return l1;
    }
    if (l0 == INT32_C(19)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(20);
    }
    if (l2) {
        l1 = vader_box_string(335u, 2208u);
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
            l1 = vader_box_string(335u, 2700u);
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
                l1 = vader_box_obj(0u, NULL);
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
                    l1 = vader_box_obj(0u, NULL);
                } else {
                    if (l0 == INT32_C(9)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(10);
                    }
                    if (l2) {
                        l1 = vader_box_obj(0u, NULL);
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
                            l1 = vader_box_obj(0u, NULL);
                        } else if (l0 == INT32_C(18)) {
                            l1 = vader_box_obj(0u, NULL);
                        } else {
                            if (!(l0 == INT32_C(0))) {
                                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                            }
                            l1 = vader_box_obj(0u, NULL);
                        }
                    }
                }
            }
        }
    }
    return l1;
}

static vader_box_t vader_vm$comptime_refusal_trap(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_4(2072u, l0, 1184u, l1);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1446u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$convert_int_fast(void* l0, uint8_t l1, vader_string_t l2) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 340u);
    l4 = ((uint8_t) t1.payload.i);
    l5 = INT64_C(0);
    if (l4 == INT32_C(0)) {
        if (l1 == INT32_C(1)) {
            l6 = vader_vm$is_unsigned_source(l2);
        } else {
            l6 = false;
        }
        if (l6) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
            l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
        } else {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
            l5 = ((int64_t) (int32_t) ((int32_t) (int64_t) t0));
        }
    } else if (l4 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
        l5 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    } else if (l4 == INT32_C(4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
        t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l3];
        l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
    } else {
        if (!(l4 == INT32_C(3))) {
            return false;
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
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
        l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        l7 = ((int64_t) (int32_t) ((int32_t) (int64_t) l5));
        vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
        ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l3] = (int64_t) l7;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(0);
        return true;
    }
    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l3)
    ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l3] = (int64_t) l5;
    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l3)
    ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(1);
    return true;
}

static vader_box_t vader_vm$convert_value(vader_box_t l0, uint8_t l1, vader_string_t l2, int32_t l3) {
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
    if (l0.tag == 338u) {
        t0 = vader_vm$is_unsigned_source(l2);
        if (t0) {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i64(339u, ((int64_t) (uint32_t) t1));
        } else {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i32(338u, t1);
        }
    } else {
        l4 = l0;
    }
    if (l1 == INT32_C(0)) {
        if (l4.tag == 338u) {
            t1 = ((int32_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i32(338u, t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1446u)) {
            t2 = ((int64_t) l5.payload.i);
            { vader_box_t __vret = vader_box_i32(338u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        if (l4.tag == 339u) {
            t2 = ((int64_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i64(339u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1446u)) {
            t2 = ((int64_t) l5.payload.i);
            { vader_box_t __vret = vader_box_i64(339u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        if ((l4.tag == 344u || l4.tag == 345u)) {
            t4 = ((double) l4.payload.f);
            { vader_box_t __vret = vader_box_f64(345u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_f64(l4, l3);
        if (!(l5.tag == 1446u)) {
            t4 = ((double) l5.payload.f);
            { vader_box_t __vret = vader_box_f64(345u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 334u) {
        t5 = ((uint32_t) l4.payload.i);
        { vader_box_t __vret = vader_box_i32(334u, (int32_t) t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$read_numeric_as_i64(l4, l3);
    if (l4.tag == 1446u) {
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
            { vader_box_t __vret = vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l6)); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        { vader_box_t __vret = vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l6)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm$debug_controller(void* l0) {
    vader_box_t l1;
    void* t0;
    l1 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_debug;
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(((vader_struct_vader_vm$DebugSession_t*) t0)->f_controller);
}

static int64_t vader_vm$debug_std_descriptor(int64_t l0) {
    if (l0 == INT64_C(4294967284)) {
        return INT64_C(2);
    }
    return INT64_C(1);
}

static vader_box_t vader_vm$debug_write(void* l0, void* l1, int64_t l2, int32_t l3, void* l4) {
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
    l5 = vader_vm$read_i64(t0, l3, 2683u);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_chk_add(i64, l2, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
    l7 = vader_vm$read_array(t0, l3, 2680u);
    if (l7.tag == 1446u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_chk_add(i64, l2, INT64_C(2));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
    l8 = vader_vm$read_i64(t0, l3, 2682u);
    if (l8.tag == 1446u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int64_t) l8.payload.i);
    if ((t2 < INT64_C(0))) {
        l9 = true;
    } else {
        l6 = ((int64_t) l8.payload.i);
        t1 = l7.payload.obj;
        l10 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
        l9 = (l6 > l10);
    }
    if (l9) {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(83));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l11, l6, 2679u);
        l10 = ((int64_t) (int32_t) l3);
        l6 = std_core$write_int(l11, l6, l10);
        l6 = std_core$write_string_at(l11, l6, 474u);
        l10 = ((int64_t) l8.payload.i);
        l6 = std_core$write_int(l11, l6, l10);
        l6 = std_core$write_string_at(l11, l6, 119u);
        t3 = std_core$finish_buffer(l11, l6);
        vader_struct_vader_vm$Trap_t* _a3_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a3_obj, 1446u);
        _a3_obj->f_message = t3;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l7.payload.obj;
    l6 = ((int64_t) l8.payload.i);
    l7 = vader_vm$array_bytes(l11, l6, l3, 2681u);
    if (l7.tag == 1446u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = ((vader_struct_vader_vm$DebugController_t*) l4)->f_output_sink;
    t2 = ((int64_t) l5.payload.i);
    l12 = vader_chk_sub(i32, ((int32_t) (int64_t) t2), INT32_C(1));
    t1 = l7.payload.obj;
    l13 = vader_host_std_core$bytes_to_string(t1);
    vader_fn_t* _a4_fnobj = (vader_fn_t*) l11;
    ((vader_fn_erased_sig_2_t) _a4_fnobj->code)(_a4_fnobj->env, vader_box_i32(338u, l12), vader_box_string(335u, l13));
    t4 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
    if (!(t4 == INT32_C(10))) {
        t2 = ((int64_t) l8.payload.i);
        vader_struct_vader_vm$HostOk_t* _a5_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a5_obj, 1426u);
        _a5_obj->f_value = vader_box_i64(339u, t2);
        t1 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a6_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a6_obj, 1426u);
    _a6_obj->f_value = vader_box_bool(333u, true);
    t1 = (void*) _a6_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$defect(void* l0, int64_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
    l4 = ((int32_t) (int64_t) l1);
    vader_struct_vader_vm$VerifyError_t* _a0_obj = (vader_struct_vader_vm$VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VerifyError_t));
    vader_obj_header_init(_a0_obj, 1449u);
    _a0_obj->f_function = l3;
    _a0_obj->f_pc = l4;
    _a0_obj->f_message = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3) {
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
    if (!(l1.tag == 1422u)) {
        l4 = l1;
        l5 = concat_2(l3, 117u);
        t0 = vader_vm$read_fn(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    l4 = vader_vm$validate_fn_index(l6, l7, l2, l3);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    t2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature)->f_params)->length;
    if (!(t2 != INT64_C(1))) {
        t1 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_name;
    l8 = vader_host_std_core$byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(73) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l7, l8, 1823u);
    l8 = std_core$write_string_at(l7, l8, l5);
    l8 = std_core$write_string_at(l7, l8, 297u);
    l9 = ((int64_t) (int32_t) l2);
    l8 = std_core$write_int(l7, l8, l9);
    t3 = std_core$finish_buffer(l7, l8);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t3;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$describe_obj(void* l0) {
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
    l2 = std_core$write_string_at(l1, l2, 515u);
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l0)->f_handle;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 225u);
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 105u);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l0)->f_bytes)->length;
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 214u);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l0)->f_slots)->length;
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 525u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$describe_value_tag(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 338u) {
        l1 = 2075u;
        return l1;
    }
    if (l0.tag == 339u) {
        l1 = 2097u;
    } else if ((l0.tag == 344u || l0.tag == 345u)) {
        l1 = 1952u;
    } else if (l0.tag == 335u) {
        l1 = 2638u;
    } else if (l0.tag == 1443u) {
        l1 = 2650u;
    } else if (l0.tag == 1418u) {
        l1 = 1556u;
    } else if (l0.tag == 1422u) {
        l1 = 2003u;
    } else if (l0.tag == 1429u) {
        l1 = 2408u;
    } else if (l0.tag == 333u) {
        l1 = 1627u;
    } else if (l0.tag == 334u) {
        l1 = 1745u;
    } else if (l0.tag == 1447u) {
        l1 = 2743u;
    } else {
        if (!(l0.tag == 1430u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2412u;
    }
    return l1;
}

static void vader_vm$detach_array_view(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3, l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw.tag == 0u) {
        t0 = vader_vm$is_array_view(l0);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_length;
    while ((l2 < l3)) {
        t1 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
        l4 = vader_chk_add(i64, t1, l2);
        l5 = vader_vm$element_at(l0, l4);
        vader_array_push((vader_array_t*) l1, l5);
        l2 = (l2 + INT64_C(1));
    }
    ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) l0);
    ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset = INT64_C(0);
    ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$dispatch_extern(void* l0, void* l1, int64_t l2, int32_t l3, void* l4, vader_box_t l5, int64_t l6) {
    void* l7 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    void* l37 = NULL;
    void* l44 = NULL;
    void* l45 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    void* l63 = NULL;
    void* l74 = NULL;
    void* l82 = NULL;
    void* l87 = NULL;
    void* l88 = NULL;
    void* l91 = NULL;
    void* l94 = NULL;
    void* l105 = NULL;
    vader_box_t l8 = vader_box_null(), l21 = vader_box_null(), l27 = vader_box_null(), l47 = vader_box_null(), l53 = vader_box_null(), l55 = vader_box_null(), l71 = vader_box_null(), l81 = vader_box_null(), l96 = vader_box_null(), l98 = vader_box_null(), l101 = vader_box_null(), l113 = vader_box_null(), l115 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l33 = 0;
    vader_string_t l46 = 0;
    vader_string_t l54 = 0;
    vader_string_t l58 = 0;
    vader_string_t l59 = 0;
    vader_string_t l72 = 0;
    vader_string_t l99 = 0;
    vader_string_t l100 = 0;
    vader_string_t l114 = 0;
    int64_t l12, l13, l20, l22, l24, l25, l28, l30, l31, l34, l35, l36, l38, l39, l40, l41, l42, l43, l49, l56, l60, l61, l62, l64, l65, l67, l68, l69, l73, l75, l76, l77, l79, l80, l83, l84, l85, l86, l89, l92, l93, l95, l97, l103, l104, l107, l109, l112, l117;
    uint8_t l48, l66, l78, l90, l102, l106, l108, l110, l111, l116;
    bool l57;
    int32_t l70;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    int64_t t4, t5;
    int32_t t6, t10;
    uint8_t t7;
    double t8;
    uint32_t t9;
    vader_box_t* gc_roots[15] = {
        &l5, &l8, &l21, &l27, &l47, &l53, &l55, &l71, &l81, &l96, &l98, &l101, &l113, &l115, &t3,
    };
    void** gc_raw_roots[29] = {
        &l0, &l1, &l4, &l7, &l14, &l15, &l16, &l17, &l18, &l19, &l23, &l26, &l29, &l32, &l37, &l44,
        &l45, &l50, &l51, &l52, &l63, &l74, &l82, &l87, &l88, &l91, &l94, &l105, &t1,
    };
    vader_string_t* gc_atom_roots[13] = {
        &l9, &l10, &l11, &l33, &l46, &l54, &l58, &l59, &l72, &l99, &l100, &l114, &t0,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 15u, 29u, gc_roots, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params;
    if (l6 == INT64_C(0)) {
        l8 = vader_vm$adapter_reason(l0, l4);
        if (!(l8.tag == 0u)) {
            l9 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
            l10 = l8.payload.s;
            l11 = 1662u;
            l12 = vader_host_std_core$byte_len(l9);
            l13 = vader_host_std_core$byte_len(l10);
            l12 = (l12 + l13);
            l13 = vader_host_std_core$byte_len(l11);
            l12 = (l12 + l13);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(40) + l12));
            l12 = INT64_C(0);
            l12 = std_core$write_string_at(l14, l12, 1947u);
            l12 = std_core$write_string_at(l14, l12, l9);
            l12 = std_core$write_string_at(l14, l12, 1064u);
            l13 = ((int64_t) (int32_t) l3);
            l12 = std_core$write_int(l14, l12, l13);
            l12 = std_core$write_string_at(l14, l12, 462u);
            l12 = std_core$write_string_at(l14, l12, l10);
            l12 = std_core$write_string_at(l14, l12, 502u);
            l12 = std_core$write_string_at(l14, l12, l11);
            t0 = std_core$finish_buffer(l14, l12);
            vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a0_obj, 1446u);
            _a0_obj->f_message = t0;
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(l5.tag == 0u)) {
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
        t2 = vader_vm$is_std_handle_symbol(t0);
        if (t2) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2];
            l8 = vader_vm$read_i64(t3, l3, 657u);
            if (!(l8.tag == 1446u)) {
                t4 = ((int64_t) l8.payload.i);
                t5 = vader_vm$debug_std_descriptor(t4);
                vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a2_obj, 1426u);
                _a2_obj->f_value = vader_box_i64(339u, t5);
                t1 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(l5.tag == 0u)) {
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
        t2 = vader_vm$is_write_symbol(t0);
        if (t2) {
            l14 = l5.payload.obj;
            t3 = vader_vm$debug_write(l0, l1, l2, l3, l14);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l8 = vader_vm$callee_of(l0, l6, l3);
    if (l8.tag == 1446u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) (INT32_C(0) & INT32_C(255));
    l14 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(24u, 0u, 8u, 339u);
    l15 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(24u, 0u, 8u, 339u);
    l16 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(25u, 0u, 1u, 340u);
    l17 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(223u, 0u, 13u, 1427u);
    l18 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(224u, 0u, 13u, 1428u);
    l19 = (void*) _a8_arr;
    l12 = INT64_C(0);
    l13 = ((vader_array_t*) l7)->length;
    while ((l12 < l13)) {
        l20 = vader_chk_add(i64, l2, l12);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l20)
        l21 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l20];
        if (l21.tag == 1422u) {
            l9 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
            l22 = vader_host_std_core$byte_len(l9);
            l23 = (void*) vader_buffer_new((size_t) (INT64_C(138) + l22));
            l24 = INT64_C(0);
            l24 = std_core$write_string_at(l23, l24, 1947u);
            l24 = std_core$write_string_at(l23, l24, l9);
            l24 = std_core$write_string_at(l23, l24, 1064u);
            l25 = ((int64_t) (int32_t) l3);
            l24 = std_core$write_int(l23, l24, l25);
            l24 = std_core$write_string_at(l23, l24, 467u);
            l24 = std_core$write_int(l23, l24, l12);
            l24 = std_core$write_string_at(l23, l24, 147u);
            t0 = std_core$finish_buffer(l23, l24);
            vader_struct_vader_vm$Trap_t* _a10_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a10_obj, 1446u);
            _a10_obj->f_message = t0;
            t1 = (void*) _a10_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l21.tag == 1443u) {
            l26 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_param_types;
            l27 = vader_vm$mirrored_struct_fields(l4, l26, l12);
            if (l27.tag == 0u) {
                l10 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
                l28 = vader_host_std_core$byte_len(l10);
                l29 = (void*) vader_buffer_new((size_t) (INT64_C(112) + l28));
                l30 = INT64_C(0);
                l30 = std_core$write_string_at(l29, l30, 1947u);
                l30 = std_core$write_string_at(l29, l30, l10);
                l30 = std_core$write_string_at(l29, l30, 1064u);
                l31 = ((int64_t) (int32_t) l3);
                l30 = std_core$write_int(l29, l30, l31);
                l30 = std_core$write_string_at(l29, l30, 467u);
                l30 = std_core$write_int(l29, l30, l12);
                l30 = std_core$write_string_at(l29, l30, 148u);
                t0 = std_core$finish_buffer(l29, l30);
                vader_struct_vader_vm$Trap_t* _a11_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a11_obj, 1446u);
                _a11_obj->f_message = t0;
                t1 = (void*) _a11_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = l27.payload.obj;
            l32 = vader_core_bytecode$c_struct_layout(t1, l4);
            if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_unknown_field.tag == 0u)) {
                l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
                l33 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_unknown_field.payload.s;
                l34 = vader_host_std_core$byte_len(l11);
                l35 = vader_host_std_core$byte_len(l33);
                l36 = (l34 + l35);
                l37 = (void*) vader_buffer_new((size_t) (INT64_C(142) + l36));
                l38 = INT64_C(0);
                l38 = std_core$write_string_at(l37, l38, 1947u);
                l38 = std_core$write_string_at(l37, l38, l11);
                l38 = std_core$write_string_at(l37, l38, 1064u);
                l39 = ((int64_t) (int32_t) l3);
                l38 = std_core$write_int(l37, l38, l39);
                l38 = std_core$write_string_at(l37, l38, 467u);
                l38 = std_core$write_int(l37, l38, l12);
                l38 = std_core$write_string_at(l37, l38, 175u);
                l38 = std_core$write_string_at(l37, l38, l33);
                l38 = std_core$write_string_at(l37, l38, 1162u);
                t0 = std_core$finish_buffer(l37, l38);
                vader_struct_vader_vm$Trap_t* _a12_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a12_obj, 1446u);
                _a12_obj->f_message = t0;
                t1 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l40 = ((vader_array_t*) l17)->length;
            l41 = INT64_C(4096);
            t4 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_size;
            if ((t4 > l41)) {
                l42 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_size;
            } else {
                l42 = l41;
            }
            l43 = INT64_C(0);
            while ((l43 < l42)) {
                vader_array_push_u8((vader_array_t*) l17, INT32_C(0));
                l43 = (l43 + INT64_C(1));
            }
            l44 = l21.payload.obj;
            l45 = l27.payload.obj;
            l46 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
            l47 = vader_vm$serialise_mirror(l17, l40, l44, l45, l4, l3, l46, INT32_C(0));
            if (l47.tag == 1446u) {
                t1 = l47.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = (INT32_C(3) & INT32_C(255));
            l48 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l48);
            l49 = ((vader_array_t*) l15)->length;
            vader_array_push_i64((vader_array_t*) l16, l49);
            vader_array_push_i64((vader_array_t*) l15, l40);
            t2 = vader_core_bytecode$param_is_c_out(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature, l12);
            if (t2) {
                l50 = l21.payload.obj;
                l51 = l27.payload.obj;
                vader_struct_vader_vm$LentStruct_t* _a13_obj = (vader_struct_vader_vm$LentStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$LentStruct_t));
                vader_obj_header_init(_a13_obj, 1428u);
                _a13_obj->f_target = l50;
                _a13_obj->f_at = l40;
                _a13_obj->f_fields = l51;
                l52 = (void*) _a13_obj;
                vader_array_push_ref((vader_array_t*) l19, l52);
            }
            l12 = (l12 + INT64_C(1));
            continue;
        }
        t2 = vader_core_bytecode$param_is_by_address(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature, l12);
        if (t2) {
            l53 = l21;
            l54 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
            l55 = vader_vm$extern_word(l53, l3, l54, l12);
            if (l55.tag == 1446u) {
                t1 = l55.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            t3 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l12, 340u);
            t6 = vader_core_bytecode$size_of_val_type(((uint8_t) t3.payload.i));
            l56 = ((int64_t) (int32_t) t6);
            if (l56 == INT64_C(0)) {
                l57 = true;
            } else {
                l57 = (l56 > INT64_C(8));
            }
            if (l57) {
                l58 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                t3 = vader_array_read_u8(_a15_slotarr, _a15_slotarr->offset + (size_t) l12, 340u);
                l59 = vader_core_bytecode$val_type_name(((uint8_t) t3.payload.i));
                l60 = vader_host_std_core$byte_len(l58);
                l61 = vader_host_std_core$byte_len(l59);
                l62 = (l60 + l61);
                l63 = (void*) vader_buffer_new((size_t) (INT64_C(81) + l62));
                l64 = INT64_C(0);
                l64 = std_core$write_string_at(l63, l64, 1947u);
                l64 = std_core$write_string_at(l63, l64, l58);
                l64 = std_core$write_string_at(l63, l64, 1064u);
                l65 = ((int64_t) (int32_t) l3);
                l64 = std_core$write_int(l63, l64, l65);
                l64 = std_core$write_string_at(l63, l64, 465u);
                l64 = std_core$write_string_at(l63, l64, l59);
                l64 = std_core$write_string_at(l63, l64, 198u);
                t0 = std_core$finish_buffer(l63, l64);
                vader_struct_vader_vm$Trap_t* _a16_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a16_obj, 1446u);
                _a16_obj->f_message = t0;
                t1 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = (INT32_C(3) & INT32_C(255));
            l66 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l66);
            l67 = ((vader_array_t*) l15)->length;
            vader_array_push_i64((vader_array_t*) l16, l67);
            l68 = ((vader_array_t*) l17)->length;
            vader_array_push_i64((vader_array_t*) l15, l68);
            l69 = ((int64_t) l55.payload.i);
            vader_vm$push_little_endian(l17, l69, l56);
        } else if (l21.tag == 1418u) {
            t1 = l21.payload.obj;
            l70 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_type_id;
            l71 = vader_vm$lent_element_val_type(l4, l70);
            if (l71.tag == 0u) {
                l72 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
                l73 = vader_host_std_core$byte_len(l72);
                l74 = (void*) vader_buffer_new((size_t) (INT64_C(153) + l73));
                l75 = INT64_C(0);
                l75 = std_core$write_string_at(l74, l75, 1947u);
                l75 = std_core$write_string_at(l74, l75, l72);
                l75 = std_core$write_string_at(l74, l75, 1064u);
                l76 = ((int64_t) (int32_t) l3);
                l75 = std_core$write_int(l74, l75, l76);
                l75 = std_core$write_string_at(l74, l75, 467u);
                l75 = std_core$write_int(l74, l75, l12);
                l75 = std_core$write_string_at(l74, l75, 151u);
                t0 = std_core$finish_buffer(l74, l75);
                vader_struct_vader_vm$Trap_t* _a17_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a17_obj, 1446u);
                _a17_obj->f_message = t0;
                t1 = (void*) _a17_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = ((uint8_t) l71.payload.i);
            t6 = vader_core_bytecode$size_of_val_type(t7);
            l77 = ((int64_t) (int32_t) t6);
            t6 = (INT32_C(3) & INT32_C(255));
            l78 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l78);
            l79 = ((vader_array_t*) l15)->length;
            vader_array_push_i64((vader_array_t*) l16, l79);
            l80 = ((vader_array_t*) l17)->length;
            vader_array_push_i64((vader_array_t*) l15, l80);
            t1 = l21.payload.obj;
            l81 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_raw;
            if (l81.tag == 0u) {
                l88 = l21.payload.obj;
                l89 = ((vader_array_t*) l17)->length;
                l90 = ((uint8_t) l71.payload.i);
                vader_struct_vader_vm$LentArray_t* _a18_obj = (vader_struct_vader_vm$LentArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$LentArray_t));
                vader_obj_header_init(_a18_obj, 1427u);
                _a18_obj->f_target = l88;
                _a18_obj->f_at = l89;
                _a18_obj->f_element = l90;
                l91 = (void*) _a18_obj;
                vader_array_push_ref((vader_array_t*) l18, l91);
                l92 = INT64_C(0);
                t1 = l21.payload.obj;
                l93 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
                while ((l92 < l93)) {
                    t1 = l21.payload.obj;
                    l94 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
                    t1 = l21.payload.obj;
                    t4 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
                    l95 = vader_chk_add(i64, t4, l92);
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l94);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l95)
                    l96 = vader_array_box_slots(_a19_slotarr->buf)[_a19_slotarr->offset + (size_t) l95];
                    if (l96.tag == 339u) {
                        l97 = ((int64_t) l96.payload.i);
                    } else if (l96.tag == 338u) {
                        t6 = ((int32_t) l96.payload.i);
                        l97 = ((int64_t) (int32_t) t6);
                    } else {
                        l98 = l96;
                        l99 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
                        l100 = concat_3(1947u, l99, 1086u);
                        l101 = vader_vm$read_i64(l98, l3, l100);
                        if (l101.tag == 1446u) {
                            t1 = l101.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l97 = ((int64_t) l101.payload.i);
                    }
                    vader_vm$push_little_endian(l17, l97, l77);
                    l92 = (l92 + INT64_C(1));
                }
            } else {
                t0 = l81.payload.s;
                l82 = vader_host_std_core$bytes(t0);
                t1 = l21.payload.obj;
                l83 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
                t1 = l21.payload.obj;
                l84 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
                t1 = l21.payload.obj;
                l85 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
                l86 = vader_chk_add(i64, l84, l85);
                vader_array_t* _a20_arr = vader_array_slice((vader_array_t*) l82, (int64_t) l83, (int64_t) l86);
                l87 = (void*) _a20_arr;
                vader_array_push_all((vader_array_t*) l17, (vader_array_t*) l87);
            }
        } else if (l21.tag == 335u) {
            t6 = (INT32_C(3) & INT32_C(255));
            l102 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l102);
            l103 = ((vader_array_t*) l15)->length;
            vader_array_push_i64((vader_array_t*) l16, l103);
            l104 = ((vader_array_t*) l17)->length;
            vader_array_push_i64((vader_array_t*) l15, l104);
            t0 = l21.payload.s;
            l105 = vader_host_std_core$bytes(t0);
            vader_array_push_all((vader_array_t*) l17, (vader_array_t*) l105);
            vader_array_push_u8((vader_array_t*) l17, INT32_C(0));
        } else if ((l21.tag == 344u || l21.tag == 345u)) {
            t6 = (INT32_C(2) & INT32_C(255));
            l106 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l106);
            t8 = ((double) l21.payload.f);
            l107 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
            vader_array_push_i64((vader_array_t*) l15, l107);
        } else if (l21.tag == 333u) {
            t6 = (INT32_C(1) & INT32_C(255));
            l108 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l108);
            t2 = l21.payload.b;
            if (t2) {
                l109 = INT64_C(1);
            } else {
                l109 = INT64_C(0);
            }
            vader_array_push_i64((vader_array_t*) l15, l109);
        } else if (l21.tag == 1429u) {
            t6 = (INT32_C(1) & INT32_C(255));
            l110 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l110);
            vader_array_push_i64((vader_array_t*) l15, INT64_C(0));
        } else if (l21.tag == 334u) {
            t6 = (INT32_C(1) & INT32_C(255));
            l111 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l111);
            t9 = ((uint32_t) l21.payload.i);
            l112 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t9));
            vader_array_push_i64((vader_array_t*) l15, l112);
        } else {
            l113 = l21;
            l114 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
            l115 = vader_vm$extern_word(l113, l3, l114, l12);
            if (l115.tag == 1446u) {
                t1 = l115.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = (INT32_C(1) & INT32_C(255));
            l116 = (uint8_t) (int32_t) t6;
            vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l116);
            l117 = ((int64_t) l115.payload.i);
            vader_array_push_i64((vader_array_t*) l15, l117);
        }
        l12 = (l12 + INT64_C(1));
    }
    l70 = vader_core_bytecode$bc_single_result_type(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
    l21 = vader_core_bytecode$mirror_at(l4, l70);
    l12 = ((vader_array_t*) l17)->length;
    if (!(l21.tag == 0u)) {
        t1 = l21.payload.obj;
        l7 = vader_core_bytecode$c_struct_layout(((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields, l4);
        if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l7)->f_unknown_field.tag == 0u)) {
            l9 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
            l10 = ((vader_struct_vader_core_bytecode$CLayout_t*) l7)->f_unknown_field.payload.s;
            l13 = vader_host_std_core$byte_len(l9);
            l20 = vader_host_std_core$byte_len(l10);
            l13 = (l13 + l20);
            l23 = (void*) vader_buffer_new((size_t) (INT64_C(123) + l13));
            l13 = INT64_C(0);
            l13 = std_core$write_string_at(l23, l13, 1947u);
            l13 = std_core$write_string_at(l23, l13, l9);
            l13 = std_core$write_string_at(l23, l13, 1064u);
            l20 = ((int64_t) (int32_t) l3);
            l13 = std_core$write_int(l23, l13, l20);
            l13 = std_core$write_string_at(l23, l13, 489u);
            l13 = std_core$write_string_at(l23, l13, l10);
            l13 = std_core$write_string_at(l23, l13, 1162u);
            t0 = std_core$finish_buffer(l23, l13);
            vader_struct_vader_vm$Trap_t* _a21_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a21_obj, 1446u);
            _a21_obj->f_message = t0;
            t1 = (void*) _a21_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l13 = INT64_C(0);
        l20 = ((vader_struct_vader_core_bytecode$CLayout_t*) l7)->f_size;
        while ((l13 < l20)) {
            vader_array_push_u8((vader_array_t*) l17, INT32_C(0));
            l13 = (l13 + INT64_C(1));
        }
        t6 = (INT32_C(3) & INT32_C(255));
        l48 = (uint8_t) (int32_t) t6;
        vader_array_push_u8((vader_array_t*) l14, (int32_t) (uint8_t) l48);
        l13 = ((vader_array_t*) l15)->length;
        vader_array_push_i64((vader_array_t*) l16, l13);
        vader_array_push_i64((vader_array_t*) l15, l12);
    }
    l48 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
    t2 = vader_vm$ffi_result_is_opt(l4, l70, (uint8_t) 12);
    if (t2) {
        t6 = (INT32_C(5) & INT32_C(255));
        l66 = (uint8_t) (int32_t) t6;
    } else {
        t6 = vader_vm$ffi_result_class(l48);
        t10 = (t6 & INT32_C(255));
        l66 = (uint8_t) (int32_t) t10;
    }
    vader_array_t* _a22_slotarr = ((vader_array_t*) l14);
    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a22_slotarr, INT32_C(0))
    ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) (int32_t) (uint8_t) l66;
    t4 = ((vader_array_t*) l15)->length;
    l13 = vader_chk_mul(i64, t4, INT64_C(8));
    l7 = l16;
    l20 = ((vader_array_t*) l7)->length;
    l22 = INT64_C(0);
    while ((l22 < l20)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l24 = ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l22];
        vader_array_t* _a24_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l24)
        t4 = ((int64_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l24];
        l25 = vader_chk_add(i64, t4, l13);
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l24)
        ((int64_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l24] = (int64_t) l25;
        l22 = (l22 + INT64_C(1));
    }
    vader_array_t* _a25_arr = vader_array_new(25u, 0u, 1u, 340u);
    l7 = (void*) _a25_arr;
    l20 = ((vader_array_t*) l15)->length;
    l22 = INT64_C(0);
    while ((l22 < l20)) {
        vader_array_t* _a26_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        l24 = ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l22];
        vader_vm$push_little_endian(l7, l24, INT64_C(8));
        l22 = (l22 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l17);
    t4 = ((vader_array_t*) l7)->length;
    if (t4 == INT64_C(0)) {
        if (l48 != INT32_C(14)) {
            vader_vm$push_little_endian(l7, INT64_C(0), INT64_C(8));
        }
    }
    l20 = ((int64_t) l8.payload.i);
    l57 = l6 != INT64_C(0);
    t6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
    l22 = ((int64_t) (int32_t) t6);
    l9 = vader_vm$call_foreign(l20, l57, l14, l7, l22);
    l15 = l18;
    l20 = ((vader_array_t*) l15)->length;
    l22 = INT64_C(0);
    while ((l22 < l20)) {
        vader_array_t* _a27_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        l16 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l22);
        t6 = vader_core_bytecode$size_of_val_type(((vader_struct_vader_vm$LentArray_t*) l16)->f_element);
        l24 = ((int64_t) (int32_t) t6);
        t2 = vader_core_bytecode$is_unsigned_val(((vader_struct_vader_vm$LentArray_t*) l16)->f_element);
        l57 = !(t2);
        l25 = INT64_C(0);
        l28 = ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l16)->f_target)->f_length;
        while ((l25 < l28)) {
            t4 = ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l16)->f_target)->f_offset;
            l30 = vader_chk_add(i64, t4, l25);
            l31 = ((vader_struct_vader_vm$LentArray_t*) l16)->f_at;
            l34 = vader_chk_add(i64, l13, l31);
            l35 = vader_chk_mul(i64, l25, l24);
            l36 = vader_chk_add(i64, l34, l35);
            l38 = vader_vm$read_little_endian(l7, l36, l24, l57);
            l17 = ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l16)->f_target)->f_elements;
            vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l16)->f_target)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l30)
            t3 = vader_array_box_slots(_a28_slotarr->buf)[_a28_slotarr->offset + (size_t) l30];
            l8 = vader_vm$retyped_int(t3, l38);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l30)
            vader_array_box_slots(_a29_slotarr->buf)[_a29_slotarr->offset + (size_t) l30] = l8;
            VADER_WRITE_BARRIER(_a29_slotarr->buf);
            l25 = (l25 + INT64_C(1));
        }
        l22 = (l22 + INT64_C(1));
    }
    l15 = l19;
    l20 = ((vader_array_t*) l15)->length;
    l22 = INT64_C(0);
    while ((l22 < l20)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        l16 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l22);
        l24 = ((vader_struct_vader_vm$LentStruct_t*) l16)->f_at;
        l25 = vader_chk_add(i64, l13, l24);
        l17 = ((vader_struct_vader_vm$LentStruct_t*) l16)->f_target;
        l18 = ((vader_struct_vader_vm$LentStruct_t*) l16)->f_fields;
        vader_vm$read_back_mirror(l7, l25, l17, l18, l4, INT32_C(0));
        l22 = (l22 + INT64_C(1));
    }
    if (!(l21.tag == 0u)) {
        l12 = vader_chk_add(i64, l13, l12);
        l15 = l21.payload.obj;
        t1 = vader_vm$mirror_value(l7, l12, l70, l15, l4);
        vader_struct_vader_vm$HostOk_t* _a31_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a31_obj, 1426u);
        _a31_obj->f_value = vader_ref_box(t1);
        t1 = (void*) _a31_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l48 == INT32_C(14)) {
        t3 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a32_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a32_obj, 1426u);
        _a32_obj->f_value = t3;
        t1 = (void*) _a32_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l48 == INT32_C(9)) {
        l57 = true;
    } else {
        l57 = l48 == INT32_C(8);
    }
    if (l57) {
        t4 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), false);
        vader_struct_vader_vm$HostOk_t* _a33_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a33_obj, 1426u);
        _a33_obj->f_value = vader_box_f64(345u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t4) }).__vd));
        t1 = (void*) _a33_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a34_slotarr = ((vader_array_t*) l14);
    VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a34_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a34_slotarr, _a34_slotarr->offset + (size_t) INT32_C(0), 340u);
    l66 = ((uint8_t) t3.payload.i);
    t6 = (INT32_C(5) & INT32_C(255));
    l78 = (uint8_t) (int32_t) t6;
    if (l66 == l78) {
        t4 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), false);
        if (!(t4 == INT64_C(0))) {
            vader_struct_vader_vm$HostOk_t* _a35_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a35_obj, 1426u);
            _a35_obj->f_value = vader_box_string(335u, l9);
            t1 = (void*) _a35_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_vm$NullVal_t* _a36_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
        vader_obj_header_init(_a36_obj, 1429u);
        t1 = (void*) _a36_obj;
        vader_struct_vader_vm$HostOk_t* _a37_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a37_obj, 1426u);
        _a37_obj->f_value = vader_ref_box(t1);
        t1 = (void*) _a37_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l48 == INT32_C(12)) {
        vader_struct_vader_vm$HostOk_t* _a38_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a38_obj, 1426u);
        _a38_obj->f_value = vader_box_string(335u, l9);
        t1 = (void*) _a38_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_vm$ffi_result_is_opt(l4, l70, (uint8_t) 15);
    if (t2) {
        t4 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), false);
        if (t4 == INT64_C(0)) {
            vader_struct_vader_vm$NullVal_t* _a39_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
            vader_obj_header_init(_a39_obj, 1429u);
            t1 = (void*) _a39_obj;
            vader_struct_vader_vm$HostOk_t* _a40_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a40_obj, 1426u);
            _a40_obj->f_value = vader_ref_box(t1);
            t1 = (void*) _a40_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l12 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), true);
    t3 = vader_vm$extern_result(l48, l12);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$dispatch_import(void* l0, void* l1, int64_t l2, void* l3, void* l4, int32_t l5, int32_t l6, int32_t l7, void* l8, bool l9, vader_box_t l10, uint8_t l11, int64_t l12) {
    vader_box_t l13 = vader_box_null(), l19 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    bool l16;
    void* l17 = NULL;
    int64_t l18, l20, l21;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    uint64_t t4;
    int64_t t5;
    int32_t t6;
    uint8_t t7;
    vader_box_t* gc_roots[4] = { &l10, &l13, &l19, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l8, &l17, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l14, &l15, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_is_extern;
    if (t0) {
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
        t0 = vader_vm$is_profiler_bracket(t1);
        if (!(t0)) {
            t2 = vader_vm$dispatch_extern(l0, l1, l2, l5, l8, l10, l12);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a0_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a0_obj, 1426u);
        _a0_obj->f_value = t2;
        t3 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l9) {
        l13 = vader_vm$comptime_refusal(l11);
        if (!(l13.tag == 0u)) {
            l14 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
            l15 = l13.payload.s;
            t2 = vader_vm$comptime_refusal_trap(l14, l15);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l11 == INT32_C(1)) {
        l16 = true;
    } else {
        l16 = l11 == INT32_C(2);
    }
    if (l16) {
        l16 = true;
    } else {
        l16 = l11 == INT32_C(3);
    }
    if (l16) {
        l16 = true;
    } else {
        l16 = l11 == INT32_C(4);
    }
    if (!(l16)) {
        if (l11 == INT32_C(6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_array(t2, l5, 1684u);
            if (l13.tag == 1446u) {
                t3 = l13.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l17 = l13.payload.obj;
            t3 = l13.payload.obj;
            l18 = ((vader_struct_vader_vm$ArrayVal_t*) t3)->f_length;
            l13 = vader_vm$array_bytes(l17, l18, l5, 1683u);
            if (!(l13.tag == 1446u)) {
                t3 = l13.payload.obj;
                t1 = vader_host_std_core$bytes_to_string(t3);
                vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a2_obj, 1426u);
                _a2_obj->f_value = vader_box_string(335u, t1);
                t3 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
            t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_string(t2, l5, 1680u);
            if (!(l13.tag == 1446u)) {
                t1 = l13.payload.s;
                t3 = vader_vm$bytes_to_value(t1, l7);
                vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a4_obj, 1426u);
                _a4_obj->f_value = vader_ref_box(t3);
                t3 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
            t2 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_string(t2, l5, 2067u);
            if (!(l13.tag == 1446u)) {
                t1 = l13.payload.s;
                t4 = std_core$string$Hash$hash_vt(t1);
                vader_struct_vader_vm$HostOk_t* _a6_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a6_obj, 1426u);
                _a6_obj->f_value = vader_box_i64(339u, ((int64_t) (uint64_t) t4));
                t3 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l2)
            t2 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_string(t2, l5, 1901u);
            if (l13.tag == 1446u) {
                t3 = l13.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l18 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l18)
            t2 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l18];
            l19 = vader_vm$read_string(t2, l5, 1900u);
            if (!(l19.tag == 1446u)) {
                l14 = l13.payload.s;
                l15 = l19.payload.s;
                vader_struct_vader_vm$HostOk_t* _a9_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a9_obj, 1426u);
                _a9_obj->f_value = vader_box_bool(333u, l14 == l15);
                t3 = (void*) _a9_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l19.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l2)
            t2 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_i64(t2, l5, 1901u);
            if (l13.tag == 1446u) {
                t3 = l13.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l18 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a11_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l18)
            t2 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l18];
            l19 = vader_vm$read_i64(t2, l5, 1900u);
            if (!(l19.tag == 1446u)) {
                l18 = ((int64_t) l13.payload.i);
                l20 = ((int64_t) l19.payload.i);
                vader_struct_vader_vm$HostOk_t* _a12_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a12_obj, 1426u);
                _a12_obj->f_value = vader_box_bool(333u, l18 == l20);
                t3 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l19.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(10)) {
            t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
            t0 = vader_core_bytecode$is_unsigned_display(t1);
            if (!(t0)) {
                vader_array_t* _a13_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l2)
                t2 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l2];
                t1 = vader_vm$display_value(t2);
                vader_struct_vader_vm$HostOk_t* _a14_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a14_obj, 1426u);
                _a14_obj->f_value = vader_box_string(335u, t1);
                t3 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a15_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l2)
            l13 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l2];
            if (l13.tag == 339u) {
                t5 = ((int64_t) l13.payload.i);
                t1 = std_core$u64$Display$to_string((uint64_t) (int64_t) t5);
                vader_struct_vader_vm$HostOk_t* _a16_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a16_obj, 1426u);
                _a16_obj->f_value = vader_box_string(335u, t1);
                t3 = (void*) _a16_obj;
                l19 = vader_ref_box(t3);
                { vader_box_t __vret = l19; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l13.tag == 338u) {
                t6 = ((int32_t) l13.payload.i);
                t1 = std_core$u64$Display$to_string((uint64_t) (int64_t) ((int64_t) (uint32_t) t6));
                vader_struct_vader_vm$HostOk_t* _a17_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a17_obj, 1426u);
                _a17_obj->f_value = vader_box_string(335u, t1);
                t3 = (void*) _a17_obj;
                l19 = vader_ref_box(t3);
            } else {
                l14 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
                l15 = vader_vm$describe_value_tag(l13);
                l18 = vader_host_std_core$byte_len(l14);
                l20 = vader_host_std_core$byte_len(l15);
                l18 = (l18 + l20);
                l17 = (void*) vader_buffer_new((size_t) (INT64_C(57) + l18));
                l18 = INT64_C(0);
                l18 = std_core$write_string_at(l17, l18, l14);
                l18 = std_core$write_string_at(l17, l18, 96u);
                l20 = ((int64_t) (int32_t) l5);
                l18 = std_core$write_int(l17, l18, l20);
                l18 = std_core$write_string_at(l17, l18, 483u);
                l18 = std_core$write_string_at(l17, l18, l15);
                t1 = std_core$finish_buffer(l17, l18);
                vader_struct_vader_vm$Trap_t* _a18_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a18_obj, 1446u);
                _a18_obj->f_message = t1;
                t3 = (void*) _a18_obj;
                l19 = vader_ref_box(t3);
            }
            { vader_box_t __vret = l19; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(11)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, INT32_C(0))
            t5 = ((int64_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) INT32_C(0)];
            l18 = vader_chk_add(i64, t5, INT64_C(1));
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, INT32_C(0))
            ((int64_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) l18;
            vader_struct_vader_vm$NullVal_t* _a20_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
            vader_obj_header_init(_a20_obj, 1429u);
            t3 = (void*) _a20_obj;
            vader_struct_vader_vm$HostOk_t* _a21_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a21_obj, 1426u);
            _a21_obj->f_value = vader_ref_box(t3);
            t3 = (void*) _a21_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(12)) {
            vader_array_t* _a22_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, INT32_C(0))
            t5 = ((int64_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) INT32_C(0)];
            vader_struct_vader_vm$HostOk_t* _a23_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a23_obj, 1426u);
            _a23_obj->f_value = vader_box_i32(338u, ((int32_t) (int64_t) t5));
            t3 = (void*) _a23_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(13)) {
            vader_struct_vader_vm$HostOk_t* _a24_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a24_obj, 1426u);
            _a24_obj->f_value = vader_box_i32(338u, INT32_C(0));
            t3 = (void*) _a24_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(14)) {
            vader_struct_vader_vm$HostOk_t* _a25_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a25_obj, 1426u);
            _a25_obj->f_value = vader_box_i32(338u, INT32_C(0));
            t3 = (void*) _a25_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(15)) {
            vader_array_t* _a26_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, INT32_C(0))
            t5 = ((int64_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) INT32_C(0)];
            vader_struct_vader_vm$HostOk_t* _a27_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a27_obj, 1426u);
            _a27_obj->f_value = vader_box_i64(339u, t5);
            t3 = (void*) _a27_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(16)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l2)
            t2 = vader_array_box_slots(_a28_slotarr->buf)[_a28_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_i64(t2, l5, 2536u);
            if (!(l13.tag == 1446u)) {
                l18 = ((int64_t) l13.payload.i);
                vader_array_push_i64((vader_array_t*) l4, l18);
                vader_struct_vader_vm$NullVal_t* _a29_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
                vader_obj_header_init(_a29_obj, 1429u);
                t3 = (void*) _a29_obj;
                vader_struct_vader_vm$HostOk_t* _a30_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a30_obj, 1426u);
                _a30_obj->f_value = vader_ref_box(t3);
                t3 = (void*) _a30_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(17)) {
            vader_vm$drop_due_timers(l4);
            t5 = ((vader_array_t*) l4)->length;
            if ((t5 <= INT64_C(1))) {
                vader_struct_vader_vm$HostOk_t* _a31_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a31_obj, 1426u);
                _a31_obj->f_value = vader_box_i32(338u, INT32_C(1));
                t3 = (void*) _a31_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a32_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            l18 = ((int64_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) INT32_C(1)];
            l20 = INT64_C(2);
            l21 = ((vader_array_t*) l4)->length;
            while ((l20 < l21)) {
                vader_array_t* _a33_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                t5 = ((int64_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l20];
                if ((t5 < l18)) {
                    vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                    l18 = ((int64_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l20];
                }
                l20 = (l20 + INT64_C(1));
            }
            vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            ((int64_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) l18;
            vader_vm$drop_due_timers(l4);
            vader_struct_vader_vm$HostOk_t* _a36_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a36_obj, 1426u);
            _a36_obj->f_value = vader_box_i32(338u, INT32_C(0));
            t3 = (void*) _a36_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(21)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l2)
            t2 = vader_array_box_slots(_a37_slotarr->buf)[_a37_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_string(t2, l5, 1972u);
            if (!(l13.tag == 1446u)) {
                t1 = l13.payload.s;
                t5 = vader_host_vader_vm$ffi_open(t1);
                vader_struct_vader_vm$HostOk_t* _a38_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a38_obj, 1426u);
                _a38_obj->f_value = vader_box_i64(339u, t5);
                t3 = (void*) _a38_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(23)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l2)
            t2 = vader_array_box_slots(_a39_slotarr->buf)[_a39_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_i64(t2, l5, 1974u);
            if (l13.tag == 1446u) {
                t3 = l13.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l18 = vader_chk_add(i64, l2, INT64_C(1));
            vader_array_t* _a40_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l18)
            t2 = vader_array_box_slots(_a40_slotarr->buf)[_a40_slotarr->offset + (size_t) l18];
            l19 = vader_vm$read_string(t2, l5, 1975u);
            if (!(l19.tag == 1446u)) {
                l18 = ((int64_t) l13.payload.i);
                l14 = l19.payload.s;
                t5 = vader_host_vader_vm$ffi_symbol(l18, l14);
                vader_struct_vader_vm$HostOk_t* _a41_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a41_obj, 1426u);
                _a41_obj->f_value = vader_box_i64(339u, t5);
                t3 = (void*) _a41_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l19.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(22)) {
            vader_array_t* _a42_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l2)
            t2 = vader_array_box_slots(_a42_slotarr->buf)[_a42_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_string(t2, l5, 1973u);
            if (!(l13.tag == 1446u)) {
                t1 = l13.payload.s;
                t5 = vader_host_vader_vm$ffi_open_path(t1);
                vader_struct_vader_vm$HostOk_t* _a43_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a43_obj, 1426u);
                _a43_obj->f_value = vader_box_i64(339u, t5);
                t3 = (void*) _a43_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(24)) {
            l13 = vader_vm$hosted_frame_call(l1, l2, l5, 1970u, false);
            if (!(l13.tag == 1446u)) {
                t2 = vader_vm$zero_value();
                vader_struct_vader_vm$HostOk_t* _a44_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a44_obj, 1426u);
                _a44_obj->f_value = t2;
                t3 = (void*) _a44_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(25)) {
            l13 = vader_vm$hosted_frame_call(l1, l2, l5, 1971u, true);
            if (!(l13.tag == 1446u)) {
                t1 = l13.payload.s;
                vader_struct_vader_vm$HostOk_t* _a45_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a45_obj, 1426u);
                _a45_obj->f_value = vader_box_string(335u, t1);
                t3 = (void*) _a45_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(19)) {
            t7 = vader_host_std_target$current_os();
            vader_struct_vader_vm$HostOk_t* _a46_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a46_obj, 1426u);
            _a46_obj->f_value = vader_box_i32(338u, ((int32_t) (uint8_t) t7));
            t3 = (void*) _a46_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(20)) {
            t7 = vader_host_std_target$current_arch();
            vader_struct_vader_vm$HostOk_t* _a47_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a47_obj, 1426u);
            _a47_obj->f_value = vader_box_i32(338u, ((int32_t) (uint8_t) t7));
            t3 = (void*) _a47_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l11 == INT32_C(18)) {
            vader_array_t* _a48_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l2)
            t2 = vader_array_box_slots(_a48_slotarr->buf)[_a48_slotarr->offset + (size_t) l2];
            l13 = vader_vm$read_string(t2, l5, 2444u);
            if (!(l13.tag == 1446u)) {
                l14 = l13.payload.s;
                t1 = concat_2(2446u, l14);
                vader_struct_vader_vm$Trap_t* _a49_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a49_obj, 1446u);
                _a49_obj->f_message = t1;
                t3 = (void*) _a49_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t3 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l11 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    l14 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l18 = vader_host_std_core$byte_len(l14);
    l17 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l18));
    l18 = INT64_C(0);
    l18 = std_core$write_string_at(l17, l18, 2801u);
    l18 = std_core$write_string_at(l17, l18, l14);
    l18 = std_core$write_string_at(l17, l18, 294u);
    l20 = ((int64_t) (int32_t) l5);
    l18 = std_core$write_int(l17, l18, l20);
    t1 = std_core$finish_buffer(l17, l18);
    vader_struct_vader_vm$Trap_t* _a50_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a50_obj, 1446u);
    _a50_obj->f_message = t1;
    t3 = (void*) _a50_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$display_tags(uint8_t l0) {
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
        { vader_gc_top = gc_frame.prev; return 2406u; }
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = INT64_C(0);
    t0 = (void*) &vader_data_55;
    l4 = ((vader_array_t*) t0)->length;
    while ((l3 < l4)) {
        t1 = (((int32_t) (int64_t) l3) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        t1 = ((INT32_C(1) << (l5 & 31)) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t1;
        if ((l0 & l6) != INT32_C(0)) {
            if (!(l2)) {
                std_string__builder$append(l1, 3057u);
            }
            t0 = (void*) &vader_data_55;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
            l7 = t2.payload.s;
            std_string__builder$append(l1, l7);
            l2 = false;
        }
        l3 = (l3 + INT64_C(1));
    }
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$display_value(vader_box_t l0) {
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
    if (l0.tag == 338u) {
        t0 = ((int32_t) l0.payload.i);
        l1 = vader_vm$I32Val$std_core$Display$to_string(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 339u) {
        t1 = ((int64_t) l0.payload.i);
        l1 = vader_vm$I64Val$std_core$Display$to_string(t1);
    } else if ((l0.tag == 344u || l0.tag == 345u)) {
        t2 = ((double) l0.payload.f);
        l1 = vader_vm$F64Val$std_core$Display$to_string(t2);
    } else if (l0.tag == 335u) {
        t3 = l0.payload.s;
        l1 = vader_vm$StringVal$std_core$Display$to_string(t3);
    } else if (l0.tag == 1443u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$StructVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 1418u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$ArrayVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 1422u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$FnVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 1429u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$NullVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 333u) {
        t5 = l0.payload.b;
        l1 = vader_vm$BoolVal$std_core$Display$to_string(t5);
    } else if (l0.tag == 334u) {
        t6 = ((uint32_t) l0.payload.i);
        l1 = vader_vm$CharVal$std_core$Display$to_string(t6);
    } else if (l0.tag == 1447u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$TypeVal$std_core$Display$to_string(t4);
    } else {
        if (!(l0.tag == 1430u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t4 = l0.payload.obj;
        l1 = vader_vm$ObjVal$std_core$Display$to_string(t4);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_vm$display_verify_error(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l3 = 0;
    int32_t l2;
    int64_t l4, l5;
    void* l6 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_vm$VerifyError_t*) l0)->f_message;
    l2 = ((vader_struct_vader_vm$VerifyError_t*) l0)->f_pc;
    l3 = ((vader_struct_vader_vm$VerifyError_t*) l0)->f_function;
    l4 = vader_host_std_core$byte_len(l1);
    l5 = vader_host_std_core$byte_len(l3);
    l4 = (l4 + l5);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(33) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l6, l4, l1);
    l4 = std_core$write_string_at(l6, l4, 96u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l6, l4, l5);
    l4 = std_core$write_string_at(l6, l4, 143u);
    l4 = std_core$write_string_at(l6, l4, l3);
    l4 = std_core$write_string_at(l6, l4, 288u);
    t0 = std_core$finish_buffer(l6, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$do_memory_copy(void* l0) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$read_i32(l2, l3, 2327u);
    if (l2.tag == 1446u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l3, 2331u);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l5 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$read_obj(l5, l3, 2330u);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(4));
    l6 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$read_i32(l6, l3, 2326u);
    if (l6.tag == 1446u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    l7 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l7 = vader_vm$read_obj(l7, l3, 2325u);
    if (l7.tag == 1446u) {
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
        l1 = std_core$write_string_at(l9, l1, 2328u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l10 = ((int64_t) (int32_t) t2);
        l1 = std_core$write_int(l9, l1, l10);
        t3 = std_core$finish_buffer(l9, l1);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
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
    l13 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    if ((l12 > l13)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(125));
        l12 = INT64_C(0);
        l12 = std_core$write_string_at(l9, l12, 2329u);
        l12 = std_core$write_int(l9, l12, l10);
        l12 = std_core$write_string_at(l9, l12, 362u);
        l13 = vader_chk_add(i64, l10, l1);
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 332u);
        t1 = l5.payload.obj;
        l13 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 96u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core$write_int(l9, l12, l13);
        t3 = std_core$finish_buffer(l9, l12);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1446u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = vader_chk_add(i64, l11, l1);
    t1 = l7.payload.obj;
    l13 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    if ((l12 > l13)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(123));
        l12 = INT64_C(0);
        l12 = std_core$write_string_at(l9, l12, 2324u);
        l12 = std_core$write_int(l9, l12, l11);
        l12 = std_core$write_string_at(l9, l12, 362u);
        l13 = vader_chk_add(i64, l11, l1);
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 332u);
        t1 = l7.payload.obj;
        l13 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 96u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core$write_int(l9, l12, l13);
        t3 = std_core$finish_buffer(l9, l12);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 1446u);
        _a2_obj->f_message = t3;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(25u, 0u, 1u, 340u);
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
            l14 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
            l13 = vader_chk_add(i64, l10, l12);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
            t4 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l13, 340u);
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
        l14 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
        l12 = vader_chk_add(i64, l11, l10);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        t4 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l10, 340u);
        l15 = ((uint8_t) t4.payload.i);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l12] = (uint8_t) (int32_t) (uint8_t) l15;
        l10 = (l10 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm$drop_due_timers(void* l0) {
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

static void vader_vm$drop_last_op(void* l0) {
    int32_t l1;
    vader_box_t t0;
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops);
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_origin);
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_kinds);
    l1 = INT32_C(0);
    while ((l1 < INT32_C(3))) {
        t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_operands);
        l1 = (l1 + INT32_C(1));
    }
    return;
}

static void* vader_vm$effect(int64_t l0, int64_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_vm$StackEffect_t* _a0_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
    vader_obj_header_init(_a0_obj, 1441u);
    _a0_obj->f_pops = l0;
    _a0_obj->f_pushes = l1;
    _a0_obj->f_flow = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$effect_of(void* l0, void* l1, vader_box_t l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* l7 = NULL;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals)->length;
    l3 = vader_chk_add(i64, l3, l4);
    if (l2.tag == 850u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 851u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 852u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 849u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 872u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 775u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 798u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 799u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 768u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        t2 = vader_vm$in_range(l6, l3);
        if (t2) {
            l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature;
            l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l7)->f_params)->length;
            l4 = vader_core_bytecode$bc_result_arity(l7);
            t0 = vader_vm$effect(l3, l4);
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 769u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports)->length;
        t2 = vader_vm$in_range(l6, l3);
        if (t2) {
            l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature;
            l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l7)->f_params)->length;
            l4 = vader_core_bytecode$bc_result_arity(l7);
            t0 = vader_vm$effect(l3, l4);
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 770u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        l5 = vader_vm$indirect_effect(l0, l6);
    } else if (l2.tag == 895u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        if ((t1 < INT32_C(0))) {
            l5 = vader_box_obj(0u, NULL);
        } else {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
            l3 = ((int64_t) (int32_t) t1);
            t0 = l2.payload.obj;
            l4 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results);
            t0 = vader_vm$effect(l3, l4);
            l5 = vader_ref_box(t0);
        }
    } else if (l2.tag == 797u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 796u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 854u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 876u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l5 = vader_vm$struct_new_effect(l0, l6);
    } else if (l2.tag == 725u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
            t0 = vader_vm$effect(((int64_t) (int32_t) t1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 879u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 878u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 772u) {
        t0 = l2.payload.obj;
        t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_vm$effect(INT64_C(2), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 773u) {
        t0 = l2.payload.obj;
        t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_vm$effect(INT64_C(1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if ((l2.tag == 756u || l2.tag == 771u || l2.tag == 784u || l2.tag == 805u || l2.tag == 825u || l2.tag == 856u)) {
        t0 = vader_vm$effect(INT64_C(0), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 724u || l2.tag == 728u || l2.tag == 752u || l2.tag == 753u || l2.tag == 759u || l2.tag == 763u || l2.tag == 774u || l2.tag == 782u || l2.tag == 793u || l2.tag == 795u || l2.tag == 802u || l2.tag == 815u || l2.tag == 822u || l2.tag == 835u || l2.tag == 857u || l2.tag == 860u || l2.tag == 863u || l2.tag == 875u || l2.tag == 892u)) {
        t0 = vader_vm$effect(INT64_C(1), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 723u || l2.tag == 729u || l2.tag == 755u || l2.tag == 757u || l2.tag == 758u || l2.tag == 760u || l2.tag == 764u || l2.tag == 783u || l2.tag == 785u || l2.tag == 786u || l2.tag == 787u || l2.tag == 788u || l2.tag == 789u || l2.tag == 790u || l2.tag == 791u || l2.tag == 792u || l2.tag == 794u || l2.tag == 800u || l2.tag == 801u || l2.tag == 803u || l2.tag == 804u || l2.tag == 806u || l2.tag == 807u || l2.tag == 808u || l2.tag == 809u || l2.tag == 810u || l2.tag == 811u || l2.tag == 812u || l2.tag == 813u || l2.tag == 814u || l2.tag == 816u || l2.tag == 817u || l2.tag == 818u || l2.tag == 819u || l2.tag == 820u || l2.tag == 821u || l2.tag == 823u || l2.tag == 824u || l2.tag == 826u || l2.tag == 827u || l2.tag == 828u || l2.tag == 829u || l2.tag == 830u || l2.tag == 831u || l2.tag == 832u || l2.tag == 833u || l2.tag == 834u || l2.tag == 836u || l2.tag == 837u || l2.tag == 838u || l2.tag == 839u || l2.tag == 842u || l2.tag == 843u || l2.tag == 844u || l2.tag == 845u || l2.tag == 846u || l2.tag == 847u || l2.tag == 848u || l2.tag == 858u || l2.tag == 859u || l2.tag == 871u || l2.tag == 873u || l2.tag == 874u || l2.tag == 880u || l2.tag == 881u || l2.tag == 882u || l2.tag == 883u || l2.tag == 884u || l2.tag == 885u || l2.tag == 886u || l2.tag == 887u || l2.tag == 888u || l2.tag == 889u || l2.tag == 890u || l2.tag == 891u)) {
        t0 = vader_vm$effect(INT64_C(2), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 726u || l2.tag == 727u || l2.tag == 877u || l2.tag == 893u)) {
        t0 = vader_vm$effect(INT64_C(2), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 730u || l2.tag == 765u || l2.tag == 864u || l2.tag == 865u || l2.tag == 866u || l2.tag == 867u || l2.tag == 868u || l2.tag == 869u || l2.tag == 870u)) {
        t0 = vader_vm$effect(INT64_C(3), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if (l2.tag == 731u) {
        t0 = vader_vm$effect(INT64_C(3), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 722u || l2.tag == 855u)) {
        t0 = vader_vm$effect(INT64_C(5), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 721u || l2.tag == 778u || l2.tag == 779u)) {
        t0 = vader_vm$effect(INT64_C(1), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 754u || l2.tag == 777u || l2.tag == 781u || l2.tag == 853u)) {
        t0 = vader_vm$effect(INT64_C(0), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 762u || l2.tag == 840u)) {
        vader_struct_vader_vm$StackEffect_t* _a2_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
        vader_obj_header_init(_a2_obj, 1441u);
        _a2_obj->f_pops = INT64_C(1);
        _a2_obj->f_pushes = INT64_C(0);
        _a2_obj->f_flow = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 761u || l2.tag == 780u)) {
        vader_struct_vader_vm$StackEffect_t* _a3_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
        vader_obj_header_init(_a3_obj, 1441u);
        _a3_obj->f_pops = INT64_C(0);
        _a3_obj->f_pushes = INT64_C(0);
        _a3_obj->f_flow = (uint8_t) 1;
        t0 = (void*) _a3_obj;
        l5 = vader_ref_box(t0);
    } else {
        if (!((l2.tag == 861u || l2.tag == 862u || l2.tag == 894u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm$StackEffect_t* _a4_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
        vader_obj_header_init(_a4_obj, 1441u);
        _a4_obj->f_pops = INT64_C(0);
        _a4_obj->f_pushes = INT64_C(0);
        _a4_obj->f_flow = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l5 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_vm$element_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_string_t t0;
    uint8_t t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        t1 = vader_host_std_core$byte_at(t0, l1);
        return vader_box_i32(338u, ((int32_t) (uint8_t) t1));
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    return t2;
}

static vader_string_t vader_vm$element_label(int32_t l0) {
    if (l0 == INT32_C(115)) {
        return 2271u;
    }
    if (l0 == INT32_C(116)) {
        return 2632u;
    }
    if (!(l0 == INT32_C(114))) {
        return 1570u;
    }
    return 1583u;
}

static uint8_t vader_vm$element_tags(void* l0, int32_t l1) {
    void* l2;
    int64_t l3;
    vader_box_t l4;
    int32_t l5;
    bool t0;
    void* t1;
    uint8_t t2;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_module)->f_types;
    l3 = ((vader_array_t*) l2)->length;
    t0 = vader_vm$in_range(l1, l3);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l4.tag == 733u) {
            t1 = l4.payload.obj;
            l5 = ((vader_struct_vader_core_bytecode$BcArray_t*) t1)->f_element;
            t2 = vader_vm$tags_of_type(l0, l5);
            return t2;
        }
        return (uint8_t) 127;
    }
    return (uint8_t) 127;
}

static void* vader_vm$element_trap(void* l0, int64_t l1, int32_t l2, int32_t l3, void* l4, int64_t l5, int32_t l6) {
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
    l7 = vader_vm$element_label(l6);
    l8 = ((int64_t) (int32_t) l2);
    l8 = vader_chk_add(i64, l1, l8);
    l10 = vader_vm$array_at(l0, l8);
    if (l10.tag == 0u) {
        t0 = vader_vm$receiver_trap(l0, l8, l4, l5, l7, 1556u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
    l8 = ((int64_t) (int32_t) l3);
    l8 = vader_chk_add(i64, l1, l8);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
    l12 = ((int32_t) (int64_t) t1);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l4)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l13 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
    l8 = vader_host_std_core$byte_len(l7);
    l11 = (void*) vader_buffer_new((size_t) (INT64_C(95) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l11, l8, l7);
    l8 = std_core$write_string_at(l11, l8, 145u);
    l14 = ((int64_t) (int32_t) l12);
    l8 = std_core$write_int(l11, l8, l14);
    l8 = std_core$write_string_at(l11, l8, 192u);
    l14 = ((vader_struct_vader_vm$ArrayVal_t*) l9)->f_length;
    l8 = std_core$write_int(l11, l8, l14);
    l8 = std_core$write_string_at(l11, l8, 331u);
    l14 = ((int64_t) (int32_t) l13);
    l8 = std_core$write_int(l11, l8, l14);
    t2 = std_core$finish_buffer(l11, l8);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 1446u);
    _a2_obj->f_message = t2;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$emit(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5) {
    void* l6 = NULL;
    int32_t l7;
    int64_t l8;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops, l2);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_operands, l3);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_operands, l4);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_operands, l5);
    l6 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_origin;
    l8 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_source_pc)->length;
    if ((l1 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_source_pc);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    } else {
        l7 = ((int32_t) (int64_t) l1);
    }
    vader_array_push_i32((vader_array_t*) l6, l7);
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_kinds, INT32_C(14));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm$enter_frame(void* l0, void* l1, int64_t l2) {
    int64_t l3, l4, l5, l7, l8, l10;
    void* l6 = NULL;
    void* l9 = NULL;
    uint8_t l11;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_vm$RegFunction_t*) l1)->f_registers;
    l3 = vader_chk_add(i64, l2, l3);
    vader_vm$reserve_registers(l0, l3);
    l3 = ((vader_struct_vader_vm$RegFunction_t*) l1)->f_params;
    l3 = vader_chk_add(i64, l2, l3);
    l4 = ((vader_struct_vader_vm$RegFunction_t*) l1)->f_slots;
    l4 = vader_chk_add(i64, l2, l4);
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (uint8_t) INT32_C(5);
        l3 = (l3 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_vm$RegFunction_t*) l1)->f_slots;
    l3 = vader_chk_add(i64, l2, l3);
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_consts)->length;
    while ((l4 < l5)) {
        l6 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        l7 = vader_chk_add(i64, l3, l4);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_consts);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l8 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7] = (int64_t) l8;
        l9 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags;
        l10 = vader_chk_add(i64, l3, l4);
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_const_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l4, 340u);
        l11 = ((uint8_t) t0.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l11;
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$entry_named(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections$MutableMap$std_core$Index$at__string__i32(((vader_struct_vader_vm$VmState_t*) l0)->f_fn_index_by_name, l1);
    if (!(l2.tag == 0u)) {
        t0 = ((int32_t) l2.payload.i);
        { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_3(2385u, l1, 288u);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1446u);
    _a0_obj->f_message = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_copy(void* l0) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$read_i32(l2, l3, 1566u);
    if (l2.tag == 1446u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l3, 1565u);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$peek_array_mut(l0, l1, l3, 1564u);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(4));
    l6 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$read_i32(l6, l3, 1569u);
    if (l6.tag == 1446u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l7 = vader_vm$peek_array_mut(l0, l1, l3, 1568u);
    if (l7.tag == 1446u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    l1 = vader_vm$clamp_nonneg(t2);
    t2 = ((int32_t) l6.payload.i);
    l8 = vader_vm$clamp_nonneg(t2);
    t2 = ((int32_t) l4.payload.i);
    l9 = vader_vm$clamp_nonneg(t2);
    l10 = vader_chk_add(i64, l8, l1);
    t1 = l7.payload.obj;
    l11 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
    if ((l10 > l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(64));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, 1567u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l11 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l12, l10, l11);
        t3 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_chk_add(i64, l9, l1);
    t1 = l5.payload.obj;
    l11 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
    if ((l10 > l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(103));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, 1563u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l11 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l12, l10, l11);
        t3 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1446u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(269u, 0u, 0u, 2153u);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l1);
    l12 = (void*) _a3_arr;
    l10 = INT64_C(0);
    while ((l10 < l1)) {
        l13 = l7.payload.obj;
        t1 = l7.payload.obj;
        t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
        t4 = vader_chk_add(i64, t0, l8);
        l11 = vader_chk_add(i64, t4, l10);
        l2 = vader_vm$element_at(l13, l11);
        vader_array_push((vader_array_t*) l12, l2);
        l10 = (l10 + INT64_C(1));
    }
    t1 = l5.payload.obj;
    vader_vm$own_bytes(t1);
    l8 = INT64_C(0);
    while ((l8 < l1)) {
        t1 = l5.payload.obj;
        l13 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
        t1 = l5.payload.obj;
        t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$exec_array_push_all(void* l0) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$peek_array_mut(l0, l1, l2, 1577u);
    if (l3.tag == 1446u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l1, l2, 1576u);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    vader_vm$detach_array_view(t1);
    t1 = l3.payload.obj;
    l1 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        t1 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
        l7 = l3.payload.obj;
        t1 = l3.payload.obj;
        t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
        l8 = vader_chk_add(i64, t0, l5);
        l9 = vader_vm$element_at(l7, l8);
        vader_array_push((vader_array_t*) l6, l9);
        l5 = (l5 + INT64_C(1));
    }
    l6 = l4.payload.obj;
    t1 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
    l1 = vader_chk_add(i64, t0, l1);
    ((vader_struct_vader_vm$ArrayVal_t*) l6)->f_length = l1;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l2;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$exec_array_repeat(void* l0) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$read_i32(l2, l3, 1581u);
    if (l2.tag == 1446u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l1, l3, 1582u);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    l1 = vader_vm$clamp_nonneg(t2);
    t1 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
    if (t0 == INT64_C(0)) {
        l5 = l1;
    } else {
        t1 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
        l5 = vader_chk_mul(i64, l1, l6);
    }
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l5);
    l7 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        l6 = INT64_C(0);
        t1 = l4.payload.obj;
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
        while ((l6 < l8)) {
            l9 = l4.payload.obj;
            t1 = l4.payload.obj;
            t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
            l10 = vader_chk_add(i64, t0, l6);
            l2 = vader_vm$element_at(l9, l10);
            vader_array_push((vader_array_t*) l7, l2);
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    t1 = l4.payload.obj;
    l3 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_type_id;
    l5 = ((vader_array_t*) l7)->length;
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1418u);
    _a2_obj->f_type_id = l3;
    _a2_obj->f_elements = l7;
    _a2_obj->f_offset = INT64_C(0);
    _a2_obj->f_length = l5;
    _a2_obj->f_raw = vader_box_obj(0u, NULL);
    l7 = (void*) _a2_obj;
    vader_vm$push_val(l0, l1, vader_ref_box(l7));
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$exec_array_slice(void* l0, void* l1) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l4, 1585u);
    if (l3.tag == 1446u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$read_i32(l5, l4, 1586u);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$peek_array_mut(l0, l2, l4, 1587u);
    if (l6.tag == 1446u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l6.payload.obj;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_length;
    t2 = ((int32_t) l5.payload.i);
    l7 = vader_vm$clamp_nonneg(t2);
    if ((l7 > l2)) {
        l7 = l2;
    }
    t2 = ((int32_t) l3.payload.i);
    l8 = vader_vm$clamp_nonneg(t2);
    if ((l8 < l7)) {
        l8 = l7;
    }
    if ((l8 > l2)) {
        l8 = l2;
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l4 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) l1)->f_type_id;
    t1 = l6.payload.obj;
    l9 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
    t1 = l6.payload.obj;
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_offset;
    l10 = vader_chk_add(i64, t0, l7);
    l7 = vader_chk_sub(i64, l8, l7);
    t1 = l6.payload.obj;
    l3 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_raw;
    vader_struct_vader_vm$ArrayVal_t* _a0_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a0_obj, 1418u);
    _a0_obj->f_type_id = l4;
    _a0_obj->f_elements = l9;
    _a0_obj->f_offset = l10;
    _a0_obj->f_length = l7;
    _a0_obj->f_raw = l3;
    l9 = (void*) _a0_obj;
    vader_vm$push_val(l0, l2, vader_ref_box(l9));
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$exec_buffer_write_string(void* l0) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$read_string(l2, l3, 1658u);
    if (l2.tag == 1446u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l3, 1656u);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l5 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$read_obj(l5, l3, 1657u);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l2.payload.s;
    l3 = ((int32_t) l4.payload.i);
    l1 = vader_host_std_core$byte_len(l6);
    t1 = l5.payload.obj;
    l7 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$check_byte_range(l3, l1, l7, 1655u, l8);
    if (l2.tag == 1446u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((int64_t) l2.payload.i);
    l7 = INT64_C(0);
    l9 = vader_host_std_core$byte_len(l6);
    while ((l7 < l9)) {
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
        l11 = vader_chk_add(i64, l1, l7);
        l12 = vader_host_std_core$byte_at(l6, l7);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l11)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l11] = (uint8_t) (int32_t) (uint8_t) l12;
        l7 = (l7 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t vader_vm$exec_comptime_value(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = vader_vm$run_for_value(l0, l1, true);
    return t0;
}

static vader_box_t vader_vm$exec_string_compare(void* l0) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l2 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$read_string(l2, l3, 2641u);
    if (l2.tag == 1446u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_string(l4, l3, 2641u);
    if (!(l4.tag == 1446u)) {
        l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
        l1 = vader_chk_sub(i64, t0, INT64_C(2));
        l6 = l2.payload.s;
        l7 = l4.payload.s;
        l8 = ((int64_t) (int32_t) vader_string_compare(l6, l7));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l8;
        l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
        t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
        l1 = vader_chk_sub(i64, t0, INT64_C(2));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
        l1 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l3 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$extern_result(uint8_t l0, int64_t l1) {
    bool l2;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = 1948u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        t1 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a1_obj, 1426u);
        _a1_obj->f_value = t1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a2_obj, 1426u);
        _a2_obj->f_value = vader_box_bool(333u, ((int32_t) (int64_t) (l1 & INT64_C(4294967295))) != INT32_C(0));
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
        vader_struct_vader_vm$HostOk_t* _a3_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a3_obj, 1426u);
        _a3_obj->f_value = vader_box_i64(339u, l1);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a4_obj, 1426u);
    _a4_obj->f_value = vader_box_i32(338u, ((int32_t) (int64_t) l1));
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, int64_t l3) {
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
    if (!(l0.tag == 339u)) {
        l4 = l0;
        l5 = l2;
        l6 = vader_host_std_core$byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(34) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l7, l6, 1947u);
        l6 = std_core$write_string_at(l7, l6, l5);
        l6 = std_core$write_string_at(l7, l6, 1062u);
        l6 = std_core$write_int(l7, l6, l3);
        l5 = std_core$finish_buffer(l7, l6);
        t0 = vader_vm$read_i64(l4, l1, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int64_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(339u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_vm$f64_of(void* l0, int64_t l1, int32_t l2) {
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

static int32_t vader_vm$ffi_result_class(uint8_t l0) {
    if (l0 == INT32_C(14)) {
        return INT32_C(0);
    }
    if (l0 == INT32_C(9)) {
        return INT32_C(2);
    }
    if (l0 == INT32_C(8)) {
        return INT32_C(2);
    }
    if (!(l0 == INT32_C(12))) {
        return INT32_C(1);
    }
    return INT32_C(4);
}

static bool vader_vm$ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2) {
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
    if (!(l5.tag == 747u)) {
        return false;
    }
    t0 = l5.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants)->length;
    if (t1 != INT64_C(2)) {
        return false;
    }
    l6 = false;
    l7 = false;
    t0 = l5.payload.obj;
    l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
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
                if (l5.tag == 743u) {
                    t0 = l5.payload.obj;
                    if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == INT32_C(13)) {
                        l6 = true;
                    }
                    t0 = l5.payload.obj;
                    if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == l2) {
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

static uint8_t vader_vm$field_tags(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t l6;
    bool t0;
    void* t1;
    uint8_t t2;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_module)->f_types;
    l4 = ((vader_array_t*) l3)->length;
    t0 = vader_vm$in_range(l1, l4);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l5.tag == 746u) {
            t1 = l5.payload.obj;
            l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields)->length;
            t0 = vader_vm$in_range(l2, l4);
            if (t0) {
                t1 = l5.payload.obj;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
                t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
                l6 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_type_index;
                t2 = vader_vm$tags_of_type(l0, l6);
                return t2;
            }
        }
        if (l5.tag == 747u) {
            l5 = vader_core_bytecode$union_layout_struct(l3, l1);
            if (l5.tag == 0u) {
                return (uint8_t) 127;
            }
            l6 = ((int32_t) l5.payload.i);
            t2 = vader_vm$field_tags(l0, l6, l2);
            return t2;
        }
        return (uint8_t) 127;
    }
    return (uint8_t) 127;
}

static uint8_t vader_vm$field_val_type(void* l0, void* l1) {
    vader_box_t l2;
    uint8_t t0;
    l2 = vader_core_bytecode$c_field_val_type(l1, l0);
    if (l2.tag == 0u) {
        return (uint8_t) 3;
    }
    t0 = ((uint8_t) l2.payload.i);
    return t0;
}

uint8_t vader_vm$field_valtype(void* l0, int32_t l1) {
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
    if (!(l4.tag == 743u)) {
        return (uint8_t) 16;
    }
    t0 = l4.payload.obj;
    return ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
}

static int32_t vader_vm$find_string_array_type_id(void* l0) {
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
        if (l4.tag == 743u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == INT32_C(12)) {
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
        if (l4.tag == 733u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(0);
}

static int32_t vader_vm$find_u8_array_type_id(void* l0) {
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
        if (l4.tag == 743u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == INT32_C(4)) {
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
        if (l4.tag == 733u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(0);
}

static vader_box_t vader_vm$finish_run(void* l0, bool l1, vader_box_t l2) {
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
            vader_struct_vader_vm$Ok_t* _a0_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
            vader_obj_header_init(_a0_obj, 1431u);
            _a0_obj->f_value = INT32_C(0);
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_vm$register_value(l0, INT64_C(0));
        l4 = vader_vm$read_i32(t1, INT32_C(0), 2522u);
        if (!(l4.tag == 1446u)) {
            t2 = ((int32_t) l4.payload.i);
            vader_struct_vader_vm$Ok_t* _a1_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
            vader_obj_header_init(_a1_obj, 1431u);
            _a1_obj->f_value = t2;
            t0 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        l3 = l2.payload.obj;
        l4 = vader_vm$register_value(l0, INT64_C(0));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) INT32_C(0)] = l4;
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        vader_struct_vader_vm$Ok_t* _a3_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
        vader_obj_header_init(_a3_obj, 1431u);
        _a3_obj->f_value = INT32_C(0);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$Ok_t* _a4_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
    vader_obj_header_init(_a4_obj, 1431u);
    _a4_obj->f_value = INT32_C(0);
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$fits_signed(int32_t l0, int64_t l1) {
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

static uint64_t vader_vm$float_bits(double l0, int64_t l1) {
    if (!(l1 == INT64_C(4))) {
        return (uint64_t) (int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
    }
    return (uint64_t) (int64_t) ((int64_t) (uint32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = l0 }).__vb));
}

static vader_box_t vader_vm$flow_to(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5, int64_t l6) {
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
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body)->length;
    if ((l3 < l7)) {
        t0 = vader_vm$merge(l0, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l4 != l6)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l8 = (void*) vader_buffer_new((size_t) INT64_C(98));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l8, l7, 1800u);
    l7 = std_core$write_int(l8, l7, l4);
    l7 = std_core$write_string_at(l8, l7, 228u);
    l7 = std_core$write_int(l8, l7, l6);
    l7 = std_core$write_string_at(l8, l7, 90u);
    l9 = std_core$finish_buffer(l8, l7);
    t1 = vader_vm$defect(l0, l5, l9);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$flush(void* l0, int64_t l1) {
    int64_t l2, l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack)->length;
    while ((l2 < l3)) {
        vader_vm$materialise(l0, l1, l2);
        l2 = (l2 + INT64_C(1));
    }
    ((vader_struct_vader_vm$Translation_t*) l0)->f_retarget = INT64_C(-1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm$fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2) {
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
    l4 = vader_host_std_core$byte_len(l3);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(70) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l5, l4, l3);
    l4 = std_core$write_string_at(l5, l4, 131u);
    l6 = ((int64_t) (int32_t) l0);
    l4 = std_core$write_int(l5, l4, l6);
    l4 = std_core$write_string_at(l5, l4, 194u);
    l6 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l5, l4, l6);
    t0 = std_core$finish_buffer(l5, l4);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1446u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$fn_type_of(void* l0, int32_t l1) {
    int64_t l2;
    vader_box_t l3;
    bool t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm$in_range(l1, l2);
    if (!(t0)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 736u) {
        t1 = l3.payload.obj;
        return vader_ref_box(t1);
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_vm$frame_names(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_vm$RegFunction_t*) t0)->f_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(335u, l5));
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$fused_branch(int32_t l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(17)) {
        t0 = vader_vm$branch(l1, INT32_C(91), false, INT32_C(92), false);
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        t0 = vader_vm$branch(l1, INT32_C(92), false, INT32_C(91), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(19)) {
        t0 = vader_vm$branch(l1, INT32_C(93), false, INT32_C(94), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(20)) {
        t0 = vader_vm$branch(l1, INT32_C(94), false, INT32_C(93), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(21)) {
        t0 = vader_vm$branch(l1, INT32_C(93), true, INT32_C(94), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(22)) {
        t0 = vader_vm$branch(l1, INT32_C(94), true, INT32_C(93), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(23)) {
        t0 = vader_vm$branch(l1, INT32_C(95), false, INT32_C(96), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(24)) {
        t0 = vader_vm$branch(l1, INT32_C(96), false, INT32_C(95), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(25)) {
        t0 = vader_vm$branch(l1, INT32_C(95), true, INT32_C(96), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(26)) {
        t0 = vader_vm$branch(l1, INT32_C(96), true, INT32_C(95), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(42)) {
        t0 = vader_vm$branch(l1, INT32_C(97), false, INT32_C(98), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(43)) {
        t0 = vader_vm$branch(l1, INT32_C(98), false, INT32_C(97), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(44)) {
        t0 = vader_vm$branch(l1, INT32_C(99), false, INT32_C(100), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(45)) {
        t0 = vader_vm$branch(l1, INT32_C(100), false, INT32_C(99), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(46)) {
        t0 = vader_vm$branch(l1, INT32_C(99), true, INT32_C(100), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(47)) {
        t0 = vader_vm$branch(l1, INT32_C(100), true, INT32_C(99), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(48)) {
        t0 = vader_vm$branch(l1, INT32_C(101), false, INT32_C(102), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(49)) {
        t0 = vader_vm$branch(l1, INT32_C(102), false, INT32_C(101), true);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(50)) {
        t0 = vader_vm$branch(l1, INT32_C(101), true, INT32_C(102), false);
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(51)) {
        t0 = vader_vm$branch(l1, INT32_C(102), true, INT32_C(101), false);
        l2 = vader_ref_box(t0);
    } else {
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$global_at_comptime_trap(void* l0, int32_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_globals);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l2 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_name;
    t1 = concat_3(1035u, l2, 1067u);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm$global_tags(void* l0, int32_t l1) {
    int32_t l2;
    uint8_t l3;
    void* t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_module)->f_globals);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l2 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_type_id;
    l3 = vader_vm$tags_of_type(l0, l2);
    if (!((l3 & INT32_C(64)) != INT32_C(0))) {
        return l3;
    }
    return (uint8_t) (int32_t) (l3 | INT32_C(32));
}

vader_box_t vader_vm$global_zero(uint8_t l0) {
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
        l1 = vader_box_i32(338u, INT32_C(0));
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l1 = vader_box_i64(339u, INT64_C(0));
    } else {
        if (l0 == INT32_C(8)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l1 = vader_box_f64(345u, 0.0);
        } else if (l0 == INT32_C(10)) {
            l1 = vader_box_bool(333u, false);
        } else if (l0 == INT32_C(11)) {
            l1 = vader_box_i32(334u, (int32_t) ((uint32_t) 0));
        } else if (l0 == INT32_C(12)) {
            l1 = vader_box_string(335u, 0u);
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
            vader_struct_vader_vm$NullVal_t* _a0_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
            vader_obj_header_init(_a0_obj, 1429u);
            t0 = (void*) _a0_obj;
            l1 = vader_ref_box(t0);
        }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$grow_frame_records(void* l0, void* l1, int64_t l2, int64_t l3) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code, l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_base, l2);
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_return, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$hosted_frame_call(void* l0, int64_t l1, int32_t l2, vader_string_t l3, bool l4) {
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l6 = 0;
    int64_t l7, l11, l13, l17;
    void* l10 = NULL;
    void* l12 = NULL;
    uint8_t l16;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    vader_box_t* gc_roots[6] = { &l5, &l8, &l9, &l14, &l15, &t3 };
    void** gc_raw_roots[4] = { &l0, &l10, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    l6 = concat_2(l3, 125u);
    l5 = vader_vm$read_i64(l5, l2, l6);
    if (l5.tag == 1446u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_chk_add(i64, l1, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    l8 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l7];
    l6 = concat_2(l3, 110u);
    l8 = vader_vm$read_array(l8, l2, l6);
    if (l8.tag == 1446u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_chk_add(i64, l1, INT64_C(2));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
    l6 = concat_2(l3, 128u);
    l9 = vader_vm$read_array(l9, l2, l6);
    if (l9.tag == 1446u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = l8.payload.obj;
    t0 = l8.payload.obj;
    l7 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
    l6 = concat_2(l3, 111u);
    l8 = vader_vm$array_bytes(l10, l7, l2, l6);
    if (l8.tag == 1446u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l9.payload.obj;
    vader_vm$own_bytes(t0);
    vader_array_t* _a3_arr = vader_array_new(25u, 0u, 1u, 340u);
    l10 = (void*) _a3_arr;
    l7 = INT64_C(0);
    t0 = l9.payload.obj;
    l11 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
    while ((l7 < l11)) {
        t0 = l9.payload.obj;
        l12 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
        t0 = l9.payload.obj;
        t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset;
        l13 = vader_chk_add(i64, t1, l7);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
        l14 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l13];
        l6 = concat_2(l3, 129u);
        l15 = vader_vm$read_i64(l14, l2, l6);
        if (l15.tag == 1446u) {
            t0 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int64_t) l15.payload.i);
        t2 = (((int32_t) (int64_t) t1) & INT32_C(255));
        l16 = (uint8_t) (int32_t) t2;
        vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l16);
        l7 = (l7 + INT64_C(1));
    }
    l7 = ((int64_t) l5.payload.i);
    l12 = l8.payload.obj;
    l6 = vader_vm$call_foreign(l7, l4, l12, l10, INT64_C(-1));
    l7 = INT64_C(0);
    t0 = l9.payload.obj;
    l11 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
    while ((l7 < l11)) {
        t0 = l9.payload.obj;
        t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset;
        l13 = vader_chk_add(i64, t1, l7);
        t0 = l9.payload.obj;
        l12 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
        t0 = l9.payload.obj;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
        l5 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l13];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t3 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l7, 340u);
        t4 = ((uint8_t) t3.payload.i);
        l17 = ((int64_t) (uint8_t) t4);
        l8 = vader_vm$retyped_int(l5, l17);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l13)
        vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l13] = l8;
        VADER_WRITE_BARRIER(_a7_slotarr->buf);
        l7 = (l7 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_string(335u, l6); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$i32_of(void* l0, int64_t l1, int32_t l2) {
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

static bool vader_vm$in_range(int32_t l0, int64_t l1) {
    int64_t l2;
    l2 = ((int64_t) (int32_t) l0);
    if ((INT64_C(0) <= l2)) {
        return (l2 < l1);
    }
    return false;
}

static vader_box_t vader_vm$indexed_effect(int32_t l0, int64_t l1, int64_t l2, int64_t l3) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_vm$in_range(l0, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_vm$effect(l2, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$indirect_call_trap(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4) {
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
    t0 = vader_vm$register_value(l1, l5);
    l6 = vader_vm$read_fn(t0, l4, 1710u);
    if (l6.tag == 1446u) {
        t1 = l6.payload.obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l6.payload.obj;
    l7 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
    if ((l7 < INT32_C(0))) {
        l8 = true;
    } else {
        l5 = ((int64_t) (int32_t) l7);
        l9 = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l0)->f_functions)->length;
        l8 = (l5 >= l9);
    }
    if (l8) {
        t1 = vader_vm$fn_index_trap(l7, l4, 1707u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l0)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    t1 = l6.payload.obj;
    if (((vader_struct_vader_vm$FnVal_t*) t1)->f_env.tag == 0u) {
        l5 = l3;
    } else {
        l5 = vader_chk_add(i64, l3, INT64_C(1));
    }
    t1 = l6.payload.obj;
    if (((vader_struct_vader_vm$FnVal_t*) t1)->f_env.tag == 0u) {
        l11 = 0u;
    } else {
        l11 = 54u;
    }
    l12 = ((vader_struct_vader_vm$RegFunction_t*) l10)->f_name;
    l9 = vader_host_std_core$byte_len(l11);
    l13 = vader_host_std_core$byte_len(l12);
    l9 = (l9 + l13);
    l14 = (void*) vader_buffer_new((size_t) (INT64_C(139) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l14, l9, 1708u);
    l13 = ((int64_t) (int32_t) l4);
    l9 = std_core$write_int(l14, l9, l13);
    l9 = std_core$write_string_at(l14, l9, 472u);
    l9 = std_core$write_int(l14, l9, l5);
    l9 = std_core$write_string_at(l14, l9, l11);
    l9 = std_core$write_string_at(l14, l9, 101u);
    l9 = std_core$write_string_at(l14, l9, l12);
    l9 = std_core$write_string_at(l14, l9, 295u);
    l5 = ((vader_struct_vader_vm$RegFunction_t*) l10)->f_params;
    l9 = std_core$write_int(l14, l9, l5);
    l9 = std_core$write_string_at(l14, l9, 196u);
    t2 = std_core$finish_buffer(l14, l9);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t2;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$indirect_effect(void* l0, int32_t l1) {
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
    l3 = vader_vm$fn_type_of(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l5 = ((vader_struct_vader_core_bytecode$BcFn_t*) l2)->f_return_type;
    t0 = vader_vm$returns_void(l0, l5);
    if (t0) {
        l4 = INT64_C(0);
    } else {
        l4 = INT64_C(1);
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) l2)->f_params)->length;
    t2 = vader_chk_add(i64, t1, INT64_C(1));
    t3 = vader_vm$effect(t2, l4);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$infer_function_tags(void* l0, void* l1, int64_t l2) {
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
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body)->length;
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a2_arr;
    l6 = vader_chk_mul(i64, l3, INT64_C(2));
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a3_arr;
    vader_struct_vader_vm$FunctionTags_t* _a4_obj = (vader_struct_vader_vm$FunctionTags_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FunctionTags_t));
    vader_obj_header_init(_a4_obj, 1424u);
    _a4_obj->f_deepest = l2;
    _a4_obj->f_depth = l4;
    _a4_obj->f_stack = l5;
    l4 = (void*) _a4_obj;
    if (l3 == INT64_C(0)) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params;
    l3 = ((vader_array_t*) l5)->length;
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals)->length;
    l3 = vader_chk_add(i64, l3, l6);
    l7 = ((vader_struct_vader_vm$TagContext_t*) l0)->f_module;
    l6 = vader_chk_add(i64, l3, l2);
    l7 = vader_vm$new_blocks(l7, l1, l6);
    vader_array_t* _a5_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l8 = (void*) _a5_arr;
    l6 = ((vader_struct_vader_vm$Blocks_t*) l7)->f_width;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l6);
    l8 = (void*) _a6_arr;
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) l5)->length;
    while ((l6 < l9)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l6, 340u);
        l10 = vader_vm$tags_of_val(((uint8_t) t1.payload.i));
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
    vader_vm$merge_block(l7, INT64_C(0), INT64_C(0), l8);
    vader_array_t* _a10_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a10_arr;
    l6 = ((vader_struct_vader_vm$Blocks_t*) l7)->f_width;
    vader_array_t* _a11_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a11_arr;
    for (;;) {
        t2 = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_work)->length;
        if ((t2 > INT64_C(0))) {
            l11 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_work);
            if (l11.tag == 0u) break;
            l6 = ((int64_t) l11.payload.i);
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_queued);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6] = (uint8_t) false;
            vader_vm$walk_block(l0, l1, l7, l6, l3, l5, vader_box_obj(0u, NULL));
            continue;
        }
        break;
    }
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_leaders)->length;
    while ((l6 < l9)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_entry_depth);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        t2 = ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6];
        if ((t2 >= INT64_C(0))) {
            vader_vm$walk_block(l0, l1, l7, l6, l3, l5, vader_ref_box(l4));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$infer_module_tags(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int64_t l4, l5, l7;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$new_tag_context(l0);
    vader_array_t* _a0_arr = vader_array_new(222u, 0u, 13u, 1424u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        l7 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        l8 = vader_vm$infer_function_tags(l2, l6, l7);
        vader_array_push_ref((vader_array_t*) l3, l8);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$initial_globals(void* l0) {
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
    l1 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals;
    vader_struct___lambda_env_vader_vm_1_t* _a0_obj = (vader_struct___lambda_env_vader_vm_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_1_t));
    vader_obj_header_init(_a0_obj, 455u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(269u, 0u, 0u, 2153u);
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

static bool vader_vm$inlinable_op(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 779u || l0.tag == 850u || l0.tag == 851u || l0.tag == 852u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 772u || l0.tag == 773u)) {
        l1 = true;
    } else if ((l0.tag == 756u || l0.tag == 771u || l0.tag == 784u || l0.tag == 805u || l0.tag == 825u || l0.tag == 856u)) {
        l1 = true;
    } else if ((l0.tag == 774u || l0.tag == 860u)) {
        l1 = true;
    } else if ((l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 813u || l0.tag == 815u || l0.tag == 819u)) {
        l1 = true;
    } else if ((l0.tag == 803u || l0.tag == 804u || l0.tag == 816u || l0.tag == 817u || l0.tag == 818u)) {
        l1 = true;
    } else if ((l0.tag == 807u || l0.tag == 808u || l0.tag == 809u || l0.tag == 810u || l0.tag == 811u || l0.tag == 814u)) {
        l1 = true;
    } else if ((l0.tag == 881u || l0.tag == 882u || l0.tag == 883u || l0.tag == 884u)) {
        l1 = true;
    } else if ((l0.tag == 820u || l0.tag == 821u || l0.tag == 822u || l0.tag == 833u || l0.tag == 835u || l0.tag == 839u)) {
        l1 = true;
    } else if ((l0.tag == 823u || l0.tag == 824u || l0.tag == 836u || l0.tag == 837u || l0.tag == 838u)) {
        l1 = true;
    } else if ((l0.tag == 827u || l0.tag == 828u || l0.tag == 829u || l0.tag == 830u || l0.tag == 831u || l0.tag == 834u)) {
        l1 = true;
    } else if ((l0.tag == 887u || l0.tag == 888u || l0.tag == 889u || l0.tag == 890u)) {
        l1 = true;
    } else if ((l0.tag == 783u || l0.tag == 785u || l0.tag == 791u || l0.tag == 793u || l0.tag == 794u)) {
        l1 = true;
    } else if ((l0.tag == 786u || l0.tag == 787u || l0.tag == 788u || l0.tag == 789u || l0.tag == 790u || l0.tag == 792u)) {
        l1 = true;
    } else if ((l0.tag == 755u || l0.tag == 757u || l0.tag == 758u || l0.tag == 759u || l0.tag == 760u)) {
        l1 = true;
    } else {
        l1 = false;
    }
    return l1;
}

static void* vader_vm$inline_into(void* l0, void* l1, int64_t l2) {
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
    void* l30 = NULL;
    void* l31 = NULL;
    void* l35 = NULL;
    void* l43 = NULL;
    bool l7;
    int64_t l8, l9, l22, l27, l28, l32, l33, l37, l38, l39, l44;
    vader_box_t l10 = vader_box_null(), l19 = vader_box_null(), l40 = vader_box_null(), l41 = vader_box_null(), l45 = vader_box_null(), l46 = vader_box_null();
    int32_t l15, l18, l20, l21, l23, l24, l25, l26, l34, l36, l42, l47, l48;
    uint8_t l29;
    vader_string_t l49 = 0;
    bool t0, t3;
    int64_t t1, t5;
    void* t2 = NULL;
    vader_box_t t4 = vader_box_null();
    int32_t t6;
    vader_box_t* gc_roots[7] = { &l10, &l19, &l40, &l41, &l45, &l46, &t4 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l16, &l17, &l30, &l31, &l35, &l43,
        &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l49 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_body;
    l5 = l4;
    vader_struct___lambda_env_vader_vm_4_t* _a1_obj = (vader_struct___lambda_env_vader_vm_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_4_t));
    vader_obj_header_init(_a1_obj, 456u);
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
    vader_array_t* _a3_arr = vader_array_new(246u, 0u, 13u, 1689u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(250u, 0u, 13u, 1748u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l11 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l12 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(63u, 0u, 13u, 740u);
    l13 = (void*) _a7_arr;
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_locals;
    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l14);
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature)->f_params)->length;
    l15 = ((int32_t) (int64_t) t1);
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 338u);
    l14 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(23u, 0u, 7u, 338u);
    l16 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(23u, 0u, 7u, 338u);
    l17 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a11_obj, 471u);
    _a11_obj->f_ekeys = l14;
    _a11_obj->f_evals = l16;
    _a11_obj->f_index = l17;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
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
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_debug);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        l19 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
        if (l10.tag == 768u) {
            t2 = l10.payload.obj;
            l20 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l20)
            t0 = ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l20];
            t3 = t0;
            if (t3) {
                t2 = l10.payload.obj;
                l21 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l21)
                l16 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l21);
                l22 = std_collections$len__i32__i32(l14);
                t2 = l10.payload.obj;
                l23 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                t1 = ((vader_array_t*) l13)->length;
                l24 = ((int32_t) (int64_t) t1);
                l25 = vader_chk_add(i32, l15, l24);
                l26 = std_collections$get_or_put__i32__i32(l14, l23, l25);
                t1 = std_collections$len__i32__i32(l14);
                if ((t1 > l22)) {
                    l17 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params;
                    l27 = ((vader_array_t*) l17)->length;
                    l28 = INT64_C(0);
                    while ((l28 < l27)) {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        t4 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l28, 340u);
                        l29 = ((uint8_t) t4.payload.i);
                        vader_struct_vader_core_bytecode$BcLocal_t* _a17_obj = (vader_struct_vader_core_bytecode$BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcLocal_t));
                        vader_obj_header_init(_a17_obj, 740u);
                        _a17_obj->f_name = 2161u;
                        _a17_obj->f_val = l29;
                        l30 = (void*) _a17_obj;
                        vader_array_push_ref((vader_array_t*) l13, l30);
                        l28 = (l28 + INT64_C(1));
                    }
                    l31 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_locals;
                    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l31);
                }
                l32 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params)->length;
                l33 = INT64_C(0);
                while ((l33 < l32)) {
                    t1 = vader_chk_sub(i64, l32, INT64_C(1));
                    t5 = vader_chk_sub(i64, t1, l33);
                    l34 = ((int32_t) (int64_t) t5);
                    t6 = vader_chk_add(i32, l26, l34);
                    vader_struct_vader_core_bytecode$LocalSet_t* _a18_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
                    vader_obj_header_init(_a18_obj, 851u);
                    _a18_obj->f_slot = t6;
                    l35 = (void*) _a18_obj;
                    vader_array_push_ref((vader_array_t*) l5, l35);
                    vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
                    l36 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l36);
                    l33 = (l33 + INT64_C(1));
                }
                l37 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body)->length;
                l38 = INT64_C(0);
                l39 = vader_chk_sub(i64, l37, INT64_C(1));
                while ((l38 < l39)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l38)
                    t4 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l38);
                    l40 = vader_vm$relocated(t4, l26);
                    vader_array_push_ref((vader_array_t*) l5, l40.payload.obj);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l38)
                    l41 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l38);
                    vader_array_push_ref((vader_array_t*) l6, l41.payload.obj);
                    l42 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l42);
                    l38 = (l38 + INT64_C(1));
                }
                l43 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body;
                l44 = vader_chk_sub(i64, l37, INT64_C(1));
                vader_array_t* _a21_slotarr = ((vader_array_t*) l43);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l44)
                l45 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l44);
                if (l45.tag == 862u) {
                    t2 = l45.payload.obj;
                    l46 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t2)->f_value;
                    vader_array_push_ref((vader_array_t*) l5, l46.payload.obj);
                    vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
                    l47 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l47);
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        vader_array_push_ref((vader_array_t*) l5, l10.payload.obj);
        vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
        l48 = ((int32_t) (int64_t) l8);
        vader_array_push_i32((vader_array_t*) l11, l48);
        l8 = (l8 + INT64_C(1));
    }
    l4 = l3;
    l49 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_jump_table;
    l8 = ((vader_array_t*) l5)->length;
    l3 = vader_core_bytecode$remap_jump_table(l3, l12, l8);
    vader_struct_vader_core_bytecode$BcFunction_t* _a22_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a22_obj, 737u);
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

static void* vader_vm$inline_leaf_calls(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(20u, 0u, 12u, 333u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_vm$is_inline_leaf(t0);
        vader_array_push_bool((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    t1 = std_core$$array$Contains$contains__bool(l1, true);
    if (!(t1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(60u, 0u, 13u, 737u);
    l3 = (void*) _a3_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l2);
    l3 = (void*) _a4_arr;
    l2 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l2 < l4)) {
        l6 = vader_vm$inline_into(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions, l1, l2);
        vader_array_push_ref((vader_array_t*) l3, l6);
        l2 = (l2 + INT64_C(1));
    }
    l1 = l0;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_name;
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_types;
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_strings;
    l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_data_pool;
    l10 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_imports;
    l11 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_exports;
    l12 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_impl_table;
    l13 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_vtables;
    l1 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_globals;
    vader_struct_vader_core_bytecode$BytecodeModule_t* _a5_obj = (vader_struct_vader_core_bytecode$BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BytecodeModule_t));
    vader_obj_header_init(_a5_obj, 766u);
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

static uint8_t vader_vm$integer_operand_tags(uint8_t l0) {
    bool t0;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        return (uint8_t) 19;
    }
    return (uint8_t) 3;
}

static uint8_t vader_vm$integer_tags(uint8_t l0) {
    bool t0;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        return (uint8_t) 1;
    }
    return (uint8_t) 2;
}

static vader_string_t vader_vm$intrinsic_host_mangle(vader_string_t l0, vader_string_t l1) {
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
    l2 = std_string$last_index_of(l1, 46u, INT64_C(0));
    if (!((l2 < INT64_C(0)))) {
        l3 = vader_host_std_core$byte_slice(l1, INT64_C(0), l2);
        l2 = vader_chk_add(i64, l2, INT64_C(1));
        l4 = vader_host_std_core$byte_len(l1);
        l5 = vader_host_std_core$byte_slice(l1, l2, l4);
        l3 = vader_core_types$trait_key_name(l3);
        t0 = vader_core_bytecode$primitive_member_mangle(l0, l3, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static bool vader_vm$is_array_view(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
    if (t0 != INT64_C(0)) {
        return true;
    }
    l1 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_offset;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_length;
    l1 = vader_chk_add(i64, l1, l2);
    l2 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements)->length;
    return (l1 < l2);
}

static bool vader_vm$is_boxed(vader_box_t l0) {
    return (l0.tag == 721u || l0.tag == 722u || l0.tag == 725u || l0.tag == 727u || l0.tag == 728u || l0.tag == 729u || l0.tag == 731u || l0.tag == 752u || l0.tag == 753u || l0.tag == 755u || l0.tag == 757u || l0.tag == 758u || l0.tag == 759u || l0.tag == 760u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 774u || l0.tag == 775u || l0.tag == 782u || l0.tag == 795u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 807u || l0.tag == 814u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 848u || l0.tag == 854u || l0.tag == 855u || l0.tag == 858u || l0.tag == 859u || l0.tag == 863u || l0.tag == 864u || l0.tag == 865u || l0.tag == 866u || l0.tag == 870u || l0.tag == 871u || l0.tag == 873u || l0.tag == 874u || l0.tag == 876u || l0.tag == 878u || l0.tag == 879u);
}

bool vader_vm$is_comptime_refusal_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$string$std_core$Contains$contains(l0, 2205u);
    return t0;
}

static bool vader_vm$is_covered_variadic(int64_t l0, int64_t l1, int64_t l2) {
    bool l3;
    int64_t t0;
    if (l2 == INT64_C(0)) {
        l3 = (l0 >= INT64_C(1));
    } else {
        l3 = false;
    }
    if (l3) {
        l3 = (l0 <= INT64_C(3));
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_chk_sub(i64, l1, l0);
        return (t0 <= INT64_C(3));
    }
    return false;
}

static bool vader_vm$is_fn_index_out_of_range(int32_t l0, void* l1) {
    int64_t l2, l3;
    if ((l0 < INT32_C(0))) {
        return true;
    }
    l2 = ((int64_t) (int32_t) l0);
    l3 = ((vader_array_t*) l1)->length;
    return (l2 >= l3);
}

static bool vader_vm$is_i32_tag(uint8_t l0) {
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

static bool vader_vm$is_inline_leaf(void* l0) {
    int64_t l1, l2, l4;
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7, l8;
    bool t0, t3;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body)->length;
    t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_is_main;
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
    t1 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature);
    if ((t1 > INT64_C(1))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!((t2.tag == 861u || t2.tag == 862u))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    l4 = vader_chk_add(i64, l2, l4);
    l3 = (void*) &vader_fn_static___lambda_vader_vm_2;
    l3 = std_core$filled__bool(l4, l3);
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l1 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l1);
    l5 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l5)->length;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        t0 = vader_vm$inlinable_op(l6);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = vader_core_bytecode$slot_touched(l6);
        l8 = ((int32_t) (int64_t) l2);
        if ((l7 >= l8)) {
            if (l6.tag == 850u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                t0 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
                t3 = t0;
                if (!(t3)) {
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

static bool vader_vm$is_integer_alias(uint8_t l0) {
    bool t0;
    t0 = vader_core_bytecode$is_integer_val(l0);
    if (t0) {
        return l0 != INT32_C(2);
    }
    return false;
}

static bool vader_vm$is_overflow_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$starts_with(l0, 1705u);
    return t0;
}

static bool vader_vm$is_profiler_bracket(vader_string_t l0) {
    bool l1;
    if (l0 == 2947u) {
        l1 = true;
    } else {
        l1 = l0 == 2949u;
    }
    if (l1) {
        return true;
    }
    return l0 == 2948u;
}

bool vader_vm$is_singleton_comptime_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$string$std_core$Contains$contains(l0, 1614u);
    return t0;
}

static bool vader_vm$is_source_local(vader_string_t l0) {
    int64_t t0;
    uint8_t t1;
    t0 = vader_host_std_core$byte_len(l0);
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = vader_host_std_core$byte_at(l0, INT64_C(0));
    if (t1 == INT32_C(36)) {
        return false;
    }
    t0 = vader_host_std_core$byte_len(l0);
    if ((t0 >= INT64_C(2))) {
        t1 = vader_host_std_core$byte_at(l0, INT64_C(0));
        if (t1 == INT32_C(95)) {
            t1 = vader_host_std_core$byte_at(l0, INT64_C(1));
            if (t1 == INT32_C(95)) {
                return false;
            }
        }
    }
    if (!(l0 == 2128u)) {
        return true;
    }
    return false;
}

static bool vader_vm$is_std_handle_symbol(vader_string_t l0) {
    return l0 == 656u;
}

static bool vader_vm$is_unsigned_source(vader_string_t l0) {
    int64_t t0;
    uint8_t t1;
    t0 = vader_host_std_core$byte_len(l0);
    if ((t0 > INT64_C(0))) {
        t1 = vader_host_std_core$byte_at(l0, INT64_C(0));
        return t1 == INT32_C(117);
    }
    return false;
}

static bool vader_vm$is_write_symbol(vader_string_t l0) {
    bool l1;
    if (l0 == 3026u) {
        l1 = true;
    } else {
        l1 = l0 == 1033u;
    }
    if (l1) {
        return true;
    }
    return l0 == 962u;
}

static void vader_vm$jump(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5) {
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
        vader_vm$emit(l0, l1, INT32_C(109), INT32_C(0), l7, INT32_C(0));
    }
    l11 = ((vader_struct_vader_vm$Translation_t*) l0)->f_jumps;
    l12 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops)->length;
    vader_array_push_i64((vader_array_t*) l11, l12);
    l11 = ((vader_struct_vader_vm$Translation_t*) l0)->f_jumps;
    l12 = ((int64_t) (int32_t) l5);
    vader_array_push_i64((vader_array_t*) l11, l12);
    vader_vm$emit(l0, l1, l8, INT32_C(0), l9, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$lent_element_val_type(void* l0, int32_t l1) {
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
    if (!(l4.tag == 733u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
    if ((t1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
    l2 = ((int64_t) (int32_t) t1);
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    if (!(l4.tag == 743u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
    if (!(t2)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_box_i32(340u, (int32_t)(uint32_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
}

static bool vader_vm$line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_vm$DebugController_t*) l0)->f_breakpoints, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(t0, l2);
    return t1;
}

static vader_box_t vader_vm$load_bytes_op(void* l0, int64_t l1, vader_string_t l2) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm$stack_i32(l0, l3, l2, 2414u);
    if (l4.tag == 1446u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm$stack_obj(l0, l3, l2);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int32_t) l4.payload.i);
    t1 = l5.payload.obj;
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    l7 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$check_byte_range(l6, l1, l3, l2, l7);
    if (!(l4.tag == 1446u)) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
        l3 = ((int64_t) l4.payload.i);
        t2 = vader_core_bytecode$read_le(l8, l3, l1);
        { vader_box_t __vret = vader_box_i64(343u, (int64_t)(uint64_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$lookup_vtable_row(void* l0, int32_t l1, int32_t l2) {
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
    l3 = ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_entries;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l6)->f_receiver_type_index;
        if (t1 == l2) {
            t1 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l6)->f_fn_index;
            return t1;
        }
        l5 = (l5 + INT64_C(1));
    }
    return INT32_C(-1);
}

static void vader_vm$materialise(void* l0, int64_t l1, int64_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    int32_t l4, l5;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = vader_vm$canonical(l0, l2);
    if (((vader_struct_vader_vm$Pending_t*) l3)->f_kind == INT32_C(2)) {
        l5 = ((vader_struct_vader_vm$Pending_t*) l3)->f_register;
        vader_vm$emit(l0, l1, INT32_C(1), l4, l5, INT32_C(0));
    } else {
        t0 = ((vader_struct_vader_vm$Pending_t*) l3)->f_register;
        if (t0 != l4) {
            l5 = ((vader_struct_vader_vm$Pending_t*) l3)->f_register;
            vader_vm$emit(l0, l1, INT32_C(0), l4, l5, INT32_C(0));
        }
    }
    l3 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
    vader_struct_vader_vm$Pending_t* _a1_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
    vader_obj_header_init(_a1_obj, 1435u);
    _a1_obj->f_kind = (uint8_t) 0;
    _a1_obj->f_register = l4;
    l6 = (void*) _a1_obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2, l6);
    VADER_WRITE_BARRIER(_a2_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$merge(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5) {
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
    l7 = std_core$write_string_at(l6, l7, 2490u);
    l7 = std_core$write_int(l6, l7, l3);
    l7 = std_core$write_string_at(l6, l7, 235u);
    l7 = std_core$write_int(l6, l7, l4);
    l7 = std_core$write_string_at(l6, l7, 229u);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l8 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    l7 = std_core$write_int(l6, l7, l8);
    l9 = std_core$finish_buffer(l6, l7);
    t1 = vader_vm$defect(l0, l5, l9);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$merge_block(void* l0, int64_t l1, int64_t l2, void* l3) {
    int64_t l4, l6, l7, l9, l14;
    bool l5;
    void* l8 = NULL;
    void* l13 = NULL;
    uint8_t l10, l11, l12;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3, t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l3, &l8, &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_width;
    l4 = vader_chk_mul(i64, l1, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l5 = (t0 < INT64_C(0));
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l2;
    l6 = INT64_C(0);
    l7 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_width;
    while ((l6 < l7)) {
        l8 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_entry;
        l9 = vader_chk_add(i64, l4, l6);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 340u);
        l10 = ((uint8_t) t1.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 340u);
        l11 = ((uint8_t) t1.payload.i);
        t2 = (l10 | l11);
        l12 = (uint8_t) (int32_t) t2;
        if (l12 != l10) {
            l13 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_entry;
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
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t3 = ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        t4 = t3;
        if (t4) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (uint8_t) true;
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_work, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$mirror_field_value(uint8_t l0, int64_t l1) {
    vader_box_t l2;
    uint32_t l3;
    bool l4;
    int32_t t0;
    if (l0 == INT32_C(10)) {
        l2 = vader_box_bool(333u, l1 != INT64_C(0));
        return l2;
    }
    if (l0 == INT32_C(11)) {
        t0 = ((int32_t) (int64_t) (l1 & INT64_C(4294967295)));
        l3 = (uint32_t) (int32_t) t0;
        if ((l3 > INT32_C(55295))) {
            if ((l3 < INT32_C(57344))) {
                l4 = true;
            } else {
                l4 = (l3 > INT32_C(1114111));
            }
            if (l4) {
                vader_unreachable("value out of range: no Unicode scalar value");
            }
        }
        l2 = vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l3));
    } else {
        if (l0 == INT32_C(0)) {
            l4 = true;
        } else {
            l4 = l0 == INT32_C(1);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l0 == INT32_C(2);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l0 == INT32_C(4);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l0 == INT32_C(5);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l0 == INT32_C(6);
        }
        if (l4) {
            l2 = vader_box_i32(338u, ((int32_t) (int64_t) l1));
        } else {
            if (l0 == INT32_C(3)) {
                l4 = true;
            } else {
                l4 = l0 == INT32_C(7);
            }
            if (l4) {
                l4 = true;
            } else {
                l4 = l0 == INT32_C(15);
            }
            if (l4) {
                l2 = vader_box_i64(339u, l1);
            } else {
                if (l0 == INT32_C(8)) {
                    l4 = true;
                } else {
                    l4 = l0 == INT32_C(9);
                }
                if (l4) {
                    l4 = true;
                } else {
                    l4 = l0 == INT32_C(12);
                }
                if (l4) {
                    l4 = true;
                } else {
                    l4 = l0 == INT32_C(13);
                }
                if (l4) {
                    l4 = true;
                } else {
                    l4 = l0 == INT32_C(14);
                }
                if (l4) {
                    l4 = true;
                } else {
                    l4 = l0 == INT32_C(16);
                }
                if (l4) {
                    l4 = true;
                } else {
                    l4 = l0 == INT32_C(17);
                }
                if (!(l4)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l2 = vader_box_i64(339u, l1);
            }
        }
    }
    return l2;
}

static void* vader_vm$mirror_value(void* l0, int64_t l1, int32_t l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_vm$zeroed_mirror(l2, l3, l4, INT32_C(0));
    l6 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l3)->f_fields;
    vader_vm$read_back_mirror(l0, l1, l5, l6, l4, INT32_C(0));
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$mirrored_struct_fields(void* l0, void* l1, int64_t l2) {
    int64_t l3;
    void* l4;
    int32_t l5;
    vader_box_t l6;
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    l6 = vader_core_bytecode$mirror_at(l0, l5);
    if (l6.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l6.payload.obj;
    return vader_ref_box(((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_fields);
}

static void vader_vm$move_register(void* l0, int64_t l1, int64_t l2) {
    void* l3;
    int64_t l4;
    uint8_t l5;
    vader_box_t l6;
    vader_box_t t0;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (int64_t) l4;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 340u);
    l5 = ((uint8_t) t0.payload.i);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) (int32_t) (uint8_t) l5;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
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

static int32_t vader_vm$narrow_code(uint8_t l0) {
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

static vader_box_t vader_vm$narrow_mask(vader_box_t l0, uint8_t l1) {
    int64_t l2, l4;
    bool l3;
    bool t0;
    int32_t t1;
    t0 = vader_core_bytecode$is_narrow_valtype(l1);
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
    if (l0.tag == 338u) {
        t1 = ((int32_t) l0.payload.i);
        l4 = ((int64_t) (int32_t) t1);
    } else {
        if (!(l0.tag == 339u)) {
            return l0;
        }
        l4 = ((int64_t) l0.payload.i);
    }
    if (l1 == INT32_C(0)) {
        l3 = true;
        t1 = vader_vm$truncate_to_width(l4, l2, l3);
        return vader_box_i32(338u, t1);
    }
    l3 = l1 == INT32_C(1);
    t1 = vader_vm$truncate_to_width(l4, l2, l3);
    return vader_box_i32(338u, t1);
}

static void vader_vm$narrow_register(void* l0, int64_t l1, int32_t l2) {
    int64_t l3, l5;
    void* l4;
    bool l6;
    vader_box_t t0;
    int32_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    if (((int32_t) t0.payload.i) != INT32_C(0)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
        if (((int32_t) t0.payload.i) != INT32_C(1)) {
            return;
        }
    }
    if ((l2 < INT32_C(2))) {
        l3 = INT64_C(8);
    } else {
        l3 = INT64_C(16);
    }
    l4 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
    if (l2 == INT32_C(1)) {
        l6 = true;
    } else {
        l6 = l2 == INT32_C(3);
    }
    t1 = vader_vm$truncate_to_width(l5, l3, l6);
    l3 = ((int64_t) (int32_t) t1);
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
    ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int64_t) l3;
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
    return;
}

static void* vader_vm$new_blocks(void* l0, void* l1, int64_t l2) {
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
    bool t1, t3;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[9] = { &l0, &l1, &l4, &l6, &l12, &l13, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body)->length;
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 12u, 333u);
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
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l8 = vader_vm$effect_of(l0, l1, l7);
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l6 = l8.payload.obj;
        if (((vader_struct_vader_vm$StackEffect_t*) l6)->f_flow == INT32_C(1)) {
            l9 = true;
        } else {
            l9 = ((vader_struct_vader_vm$StackEffect_t*) l6)->f_flow == INT32_C(2);
        }
        if (l9) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            l10 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
            t1 = vader_vm$in_range(l10, l3);
            if (t1) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10] = (uint8_t) true;
            }
        }
        if (((vader_struct_vader_vm$StackEffect_t*) l6)->f_flow != INT32_C(0)) {
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
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 8u, 339u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l12 = (void*) _a9_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t1 = ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5];
        t3 = t1;
        if (t3) {
            l11 = ((vader_array_t*) l6)->length;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
            ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5] = (int64_t) l11;
            vader_array_push_i64((vader_array_t*) l6, l5);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a12_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = (int64_t) INT64_C(-1);
    l4 = (void*) _a12_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l3);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l13 = (void*) _a14_arr;
    t2 = ((vader_array_t*) l6)->length;
    l3 = vader_chk_mul(i64, t2, l2);
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l3);
    l13 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(24u, 0u, 8u, 339u);
    l14 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(20u, 1u, 12u, 333u);
    ((uint8_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (uint8_t) false;
    l15 = (void*) _a17_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l3);
    l15 = (void*) _a18_arr;
    vader_struct_vader_vm$Blocks_t* _a19_obj = (vader_struct_vader_vm$Blocks_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Blocks_t));
    vader_obj_header_init(_a19_obj, 1419u);
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

static void* vader_vm$new_run_host(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int64_t) INT64_C(0);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    l2 = (void*) _a2_arr;
    vader_struct_vader_vm$RunHost_t* _a3_obj = (vader_struct_vader_vm$RunHost_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RunHost_t));
    vader_obj_header_init(_a3_obj, 1439u);
    _a3_obj->f_gc_state = l0;
    _a3_obj->f_sched_state = l1;
    _a3_obj->f_obj_handles = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$new_tag_context(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    int32_t l5;
    uint8_t l6;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 1u, 340u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        l5 = ((int32_t) (int64_t) l2);
        l6 = vader_vm$type_tags(l4, l5, INT32_C(0));
        vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l6);
        l2 = (l2 + INT64_C(1));
    }
    vader_struct_vader_vm$TagContext_t* _a2_obj = (vader_struct_vader_vm$TagContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$TagContext_t));
    vader_obj_header_init(_a2_obj, 1444u);
    _a2_obj->f_module = l0;
    _a2_obj->f_type_tags = l1;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$note_checked_kind(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3;
    uint8_t l4;
    int64_t t0;
    if ((l1.tag == 772u || l1.tag == 773u)) {
        l2 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_kinds;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_kinds)->length;
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        l4 = VADER_UNION_FIELD(uint8_t, vader_struct_vader_core_bytecode$CheckedArith_t, f_kind, l1.payload.obj);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l4;
        return;
    }
    return;
}

static bool vader_vm$one_argument_string_op(void* l0, int64_t l1, int32_t l2) {
    int32_t l3, l4;
    int64_t l5;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm$operand(l0, INT64_C(1));
    l4 = vader_vm$pop_to(l0, INT64_C(1));
    vader_vm$emit(l0, l1, l2, l4, l3, INT32_C(0));
    vader_vm$push_register(l0, l4);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops)->length;
    l5 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Translation_t*) l0)->f_retarget = l5;
    { vader_gc_top = gc_frame.prev; return true; }
}

static vader_string_t vader_vm$op_text(vader_box_t l0) {
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_emit_virt$write_op(l1, l0);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$operand(void* l0, int64_t l1) {
    void* l2;
    int64_t l3;
    int64_t t0;
    void* t1;
    int32_t t2;
    l2 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack)->length;
    l3 = vader_chk_sub(i64, t0, l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t2 = ((vader_struct_vader_vm$Pending_t*) t1)->f_register;
    return t2;
}

static int32_t vader_vm$operand_a(int64_t l0) {
    int64_t l1, l2;
    l1 = INT64_C(42);
    l1 = (l0 << (l1 & 63));
    l2 = INT64_C(42);
    return ((int32_t) (int64_t) (l1 >> (l2 & 63)));
}

static int32_t vader_vm$operand_b(int64_t l0) {
    int64_t l1, l2;
    l1 = (l0 << INT64_C(21));
    l2 = INT64_C(43);
    return ((int32_t) (int64_t) (l1 >> (l2 & 63)));
}

static int32_t vader_vm$operand_c(int64_t l0) {
    int64_t l1;
    l1 = INT64_C(43);
    return ((int32_t) (int64_t) (l0 >> (l1 & 63)));
}

static int32_t vader_vm$operand_of(void* l0, int64_t l1, int64_t l2) {
    void* l3;
    int64_t l4;
    int64_t t0;
    int32_t t1;
    l3 = ((vader_struct_vader_vm$Translation_t*) l0)->f_operands;
    t0 = vader_chk_mul(i64, INT64_C(3), l1);
    l4 = vader_chk_add(i64, t0, l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    return t1;
}

static bool vader_vm$operands_within(void* l0, int64_t l1, uint8_t l2) {
    uint8_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_vm$stack_tags(l0, l1, INT64_C(1));
    t1 = vader_vm$tags_within(t0, l2);
    if (t1) {
        t0 = vader_vm$stack_tags(l0, l1, INT64_C(2));
        t1 = vader_vm$tags_within(t0, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_vm$overflow_trap(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    int64_t l3, l4;
    void* l5 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l5, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = 1705u;
    l2 = l0;
    l3 = vader_host_std_core$byte_len(l1);
    l4 = vader_host_std_core$byte_len(l2);
    l3 = (l3 + l4);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l5, l3, l1);
    l3 = std_core$write_string_at(l5, l3, 52u);
    l3 = std_core$write_int(l5, l3, INT64_C(1024));
    l3 = std_core$write_string_at(l5, l3, 330u);
    l3 = std_core$write_string_at(l5, l3, l2);
    l3 = std_core$write_string_at(l5, l3, 288u);
    t0 = std_core$finish_buffer(l5, l3);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1446u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$own_bytes(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_vm$detach_array_view(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$pack_operands(int32_t l0, int32_t l1, int32_t l2) {
    bool l3;
    int64_t l4, l5, l6;
    bool t0;
    t0 = vader_vm$fits_signed(l0, INT64_C(22));
    if (t0) {
        l3 = vader_vm$fits_signed(l1, INT64_C(21));
    } else {
        l3 = false;
    }
    if (l3) {
        l3 = vader_vm$fits_signed(l2, INT64_C(21));
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
    return vader_box_i64(339u, (l4 | l5));
}

static vader_string_t vader_vm$param_display_name(void* l0, int64_t l1) {
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
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_names)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
        t1 = t0.payload.s;
        if (t1 != 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_names);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
            t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
            t1 = t0.payload.s;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(23));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l3, l2, 1548u);
    l2 = std_core$write_int(l3, l2, l1);
    t1 = std_core$finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$pause_context(void* l0, void* l1, vader_string_t l2, int64_t l3, int64_t l4) {
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
    vader_array_t* _a0_arr = vader_array_new(226u, 0u, 13u, 1433u);
    l5 = (void*) _a0_arr;
    l6 = l4;
    while ((l6 > INT64_C(0))) {
        l6 = vader_chk_sub(i64, l6, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = vader_chk_sub(i64, l4, INT64_C(1));
        if (l6 == l9) {
            l8 = l3;
        } else {
            l10 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_return;
            l11 = vader_chk_add(i64, l6, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
            l8 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l11];
        }
        vader_array_t* _a3_arr = vader_array_new(269u, 0u, 0u, 2153u);
        l12 = (void*) _a3_arr;
        l14 = ((vader_struct_vader_vm$RegFunction_t*) l7)->f_slots;
        if ((INT64_C(0) < l14)) {
            l13 = ((vader_struct_vader_vm$RegFunction_t*) l7)->f_slots;
        } else {
            l13 = INT64_C(0);
        }
        vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l12, (int64_t) l13);
        l15 = (void*) _a4_arr;
        l16 = INT64_C(0);
        l17 = ((vader_struct_vader_vm$RegFunction_t*) l7)->f_slots;
        while ((l16 < l17)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_base);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            t0 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
            l18 = vader_chk_add(i64, t0, l16);
            l19 = vader_vm$register_value(l1, l18);
            vader_array_push((vader_array_t*) l15, l19);
            l16 = (l16 + INT64_C(1));
        }
        l20 = ((vader_struct_vader_vm$VmState_t*) l0)->f_bc;
        l21 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
        l22 = ((vader_struct_vader_vm$RegFunction_t*) l7)->f_index;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l21);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l22)
        l23 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l22);
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l7)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        l24 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l8];
        l25 = vader_vm$pause_frame(l20, l23, l15, l24);
        vader_array_push_ref((vader_array_t*) l5, l25);
    }
    vader_struct_vader_vm$PauseCtx_t* _a8_obj = (vader_struct_vader_vm$PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseCtx_t));
    vader_obj_header_init(_a8_obj, 1432u);
    _a8_obj->f_reason = l2;
    _a8_obj->f_frames = l5;
    t1 = (void*) _a8_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$pause_frame(void* l0, void* l1, void* l2, int32_t l3) {
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
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug)->length;
        if ((l6 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            if (!(l8.tag == 0u)) {
                t0 = l8.payload.obj;
                l4 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t0)->f_file;
                t0 = l8.payload.obj;
                l5 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t0)->f_line;
            }
        }
    }
    l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_name;
    l10 = vader_vm$project_locals(l2, l3, l1, l0);
    vader_struct_vader_vm$PauseFrame_t* _a1_obj = (vader_struct_vader_vm$PauseFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseFrame_t));
    vader_obj_header_init(_a1_obj, 1433u);
    _a1_obj->f_function_name = l9;
    _a1_obj->f_file = l4;
    _a1_obj->f_line = l5;
    _a1_obj->f_locals = l10;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$peek_array_mut(void* l0, int64_t l1, int32_t l2, vader_string_t l3) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l4.tag == 1418u) {
            t1 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = l3;
    t0 = vader_vm$peek_val(l0, l1);
    l6 = vader_vm$describe_value_tag(t0);
    l7 = vader_host_std_core$byte_len(l5);
    l8 = vader_host_std_core$byte_len(l6);
    l7 = (l7 + l8);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l7));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l9, l7, l5);
    l7 = std_core$write_string_at(l9, l7, 96u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 477u);
    l7 = std_core$write_string_at(l9, l7, l6);
    t2 = std_core$finish_buffer(l9, l7);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 1446u);
    _a2_obj->f_message = t2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$peek_owned(void* l0, int64_t l1) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(338u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(339u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(345u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(333u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
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
        l3 = vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l4));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm$NullVal_t* _a7_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
        vader_obj_header_init(_a7_obj, 1429u);
        t3 = (void*) _a7_obj;
        l3 = vader_ref_box(t3);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$peek_val(void* l0, int64_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    if (((int32_t) t0.payload.i) == INT32_C(5)) {
        t1 = (void*) &vader_data_56;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm$peek_owned(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$pop_to(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    int32_t t1;
    l2 = INT64_C(0);
    while ((l2 < l1)) {
        t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
        l2 = (l2 + INT64_C(1));
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack)->length;
    t1 = vader_vm$canonical(l0, l2);
    return t1;
}

vader_box_t vader_vm$prepare(void* l0) {
    vader_box_t t0;
    t0 = vader_vm$prepare_for(l0, false);
    return t0;
}

static vader_box_t vader_vm$prepare_for(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1) {
        t0 = vader_vm$prepare_module(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_vm$inline_leaf_calls(l0);
    l2 = vader_vm$prepare_module(t1, false);
    if (l2.tag == 1450u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm$prepare_module(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$prepare_module(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    int64_t l5, l7;
    uint8_t l9;
    vader_string_t l10 = 0;
    int32_t l11, l13, l14;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l6, &l8, &l12, &l15, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$verify_module(l0);
    if (l2.tag == 1449u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    l3 = vader_vm$infer_module_tags(l0, l3);
    l2 = vader_vm$check_module_tags(l0, l3);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 1u, 340u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
    l5 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_is_extern;
        if (t1) {
            vader_array_push_u8((vader_array_t*) l4, INT32_C(0));
        } else {
            t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_mangled_name;
            l9 = vader_core_bytecode$intrinsic_id_for(t2);
            vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l9);
        }
        l7 = (l7 + INT64_C(1));
    }
    l2 = vader_vm$translate_module(l0, l4, l3, l1);
    if (l2.tag == 1449u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a5_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a6_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a6_obj, 548u);
    _a6_obj->f_ekeys = l3;
    _a6_obj->f_evals = l6;
    _a6_obj->f_index = l8;
    _a6_obj->f_mask = INT64_C(0);
    _a6_obj->f_grow_at = INT64_C(0);
    _a6_obj->f_size = INT64_C(0);
    _a6_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a6_obj;
    l5 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l5 < l7)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l11 = ((int32_t) (int64_t) l5);
        std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l3, l10, l11);
        l5 = (l5 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool;
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
    l12 = vader_core_bytecode$data_pool_type_ids(l0);
    l6 = vader_vm$reduce_data_pool(l6, l8, l12);
    l8 = vader_vm$initial_globals(l0);
    l11 = vader_core_bytecode$main_function_index(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    l13 = vader_vm$find_string_array_type_id(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l14 = vader_vm$find_u8_array_type_id(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    vader_array_t* _a8_arr = vader_array_new(24u, 0u, 8u, 339u);
    l12 = (void*) _a8_arr;
    l15 = l2.payload.obj;
    vader_struct_vader_vm$VmState_t* _a9_obj = (vader_struct_vader_vm$VmState_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VmState_t));
    vader_obj_header_init(_a9_obj, 1450u);
    _a9_obj->f_bc = l0;
    _a9_obj->f_data_pool = l6;
    _a9_obj->f_globals = l8;
    _a9_obj->f_main_index = l11;
    _a9_obj->f_string_array_type_id = l13;
    _a9_obj->f_u8_array_type_id = l14;
    _a9_obj->f_fn_index_by_name = l3;
    _a9_obj->f_import_ids = l4;
    _a9_obj->f_adapters = l12;
    _a9_obj->f_reg = l15;
    _a9_obj->f_debuggable = l1;
    t0 = (void*) _a9_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$primitive_impl_import(vader_string_t l0, int64_t l1) {
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
    vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(17);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(17);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 0u, 335u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(20u, 0u, 12u, 333u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(20u, 0u, 12u, 333u);
    l8 = (void*) _a7_arr;
    vader_struct_vader_core_bytecode$BcSignature_t* _a8_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a8_obj, 744u);
    _a8_obj->f_params = l2;
    _a8_obj->f_results = l3;
    _a8_obj->f_param_types = l4;
    _a8_obj->f_result_types = l5;
    _a8_obj->f_param_names = l6;
    _a8_obj->f_param_c_out = l7;
    _a8_obj->f_param_by_address = l8;
    l2 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a9_arr;
    vader_struct_vader_core_bytecode$BcImport_t* _a10_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
    vader_obj_header_init(_a10_obj, 739u);
    _a10_obj->f_extern_name = 0u;
    _a10_obj->f_mangled_name = l0;
    _a10_obj->f_signature = l2;
    _a10_obj->f_is_extern = false;
    _a10_obj->f_c_header = 0u;
    _a10_obj->f_library = vader_box_obj(0u, NULL);
    _a10_obj->f_c_variadic_fixed = INT32_C(-1);
    _a10_obj->f_param_c_types = l3;
    _a10_obj->f_result_c_type = 0u;
    t0 = (void*) _a10_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$primitive_kind_at(void* l0, int32_t l1) {
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
    if (!(l5.tag == 743u)) {
        return 0u;
    }
    t0 = l5.payload.obj;
    t1 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
    return t1;
}

static int32_t vader_vm$primitive_type_id(void* l0, vader_box_t l1) {
    vader_string_t l2;
    int64_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_string_t t1;
    l2 = vader_vm$describe_value_tag(l1);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = l5;
        if (l5.tag == 743u) {
            t0 = l6.payload.obj;
            t1 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
            if (t1 == l2) {
                return ((int32_t) (int64_t) l3);
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return INT32_C(-1);
}

static void* vader_vm$project_locals(void* l0, int32_t l1, void* l2, void* l3) {
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
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals)->length;
    l5 = vader_chk_add(i64, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l7 = (void*) _a3_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body)->length;
    while ((l8 < l9)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
        l10 = vader_core_bytecode$slot_touched(t1);
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
    vader_array_t* _a8_arr = vader_array_new(227u, 0u, 13u, 1434u);
    l13 = (void*) _a8_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l8 = ((vader_array_t*) l0)->length;
        if ((l5 < l8)) {
            l14 = vader_vm$param_display_name(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature, l5);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l15 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
            l16 = vader_vm$project_var(l14, l15, l3, INT32_C(0));
            vader_array_push_ref((vader_array_t*) l13, l16);
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    l8 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals)->length;
    while ((l5 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
        l14 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_name;
        l9 = vader_chk_add(i64, l4, l5);
        l17 = ((vader_array_t*) l0)->length;
        if ((l9 < l17)) {
            t3 = vader_vm$is_source_local(l14);
            if (t3) {
                t3 = vader_vm$slot_in_scope(l6, l7, l9, l1);
                if (t3) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                    l15 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l9];
                    l16 = vader_vm$project_var(l14, l15, l3, INT32_C(0));
                    vader_array_push_ref((vader_array_t*) l13, l16);
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$project_struct_fields(void* l0, void* l1, int32_t l2) {
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
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1434u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 335u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_types)->length;
    t0 = vader_vm$in_range(l5, l6);
    if (t0) {
        l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_types;
        l5 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (l8.tag == 746u) {
            t1 = l8.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
            l6 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l6)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                l10 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(335u, l10));
                l9 = (l9 + INT64_C(1));
            }
        }
    }
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields)->length;
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
            l12 = std_core$write_string_at(l7, l12, 1976u);
            l12 = std_core$write_int(l7, l12, l6);
            l10 = std_core$finish_buffer(l7, l12);
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l8 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l6];
        l5 = vader_chk_add(i32, l2, INT32_C(1));
        l13 = vader_vm$project_var(l10, l8, l1, l5);
        vader_array_push_ref((vader_array_t*) l3, l13);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$project_var(vader_string_t l0, vader_box_t l1, void* l2, int32_t l3) {
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
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1434u);
    l4 = (void*) _a0_arr;
    if ((l3 < INT32_C(5))) {
        if (l1.tag == 1418u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
            if ((t1 > INT64_C(64))) {
                l5 = INT64_C(64);
            } else {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_length;
            }
            l6 = INT64_C(0);
            while ((l6 < l5)) {
                l7 = (void*) vader_buffer_new((size_t) INT64_C(22));
                l8 = INT64_C(0);
                l8 = std_core$write_string_at(l7, l8, 964u);
                l8 = std_core$write_int(l7, l8, l6);
                l8 = std_core$write_string_at(l7, l8, 967u);
                l9 = std_core$finish_buffer(l7, l8);
                l10 = l1.payload.obj;
                t0 = l1.payload.obj;
                t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_offset;
                l11 = vader_chk_add(i64, t1, l6);
                l12 = vader_vm$element_at(l10, l11);
                l13 = vader_chk_add(i32, l3, INT32_C(1));
                l14 = vader_vm$project_var(l9, l12, l2, l13);
                vader_array_push_ref((vader_array_t*) l4, l14);
                l6 = (l6 + INT64_C(1));
            }
        } else if (l1.tag == 1443u) {
            t0 = l1.payload.obj;
            l4 = vader_vm$project_struct_fields(t0, l2, l3);
        }
        l9 = vader_vm$display_value(l1);
        vader_struct_vader_vm$PauseVar_t* _a1_obj = (vader_struct_vader_vm$PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseVar_t));
        vader_obj_header_init(_a1_obj, 1434u);
        _a1_obj->f_name = l0;
        _a1_obj->f_value = l9;
        _a1_obj->f_children = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm$display_value(l1);
    vader_struct_vader_vm$PauseVar_t* _a2_obj = (vader_struct_vader_vm$PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseVar_t));
    vader_obj_header_init(_a2_obj, 1434u);
    _a2_obj->f_name = l0;
    _a2_obj->f_value = l9;
    _a2_obj->f_children = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$push_constant(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4;
    int32_t l5;
    int64_t t0, t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_vm$scalar_of(l1);
    if (l3.tag == 0u) {
        vader_host_std_abort$panic(2502u);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        l3 = std_collections$MutableMap$std_core$Index$at__Any__i64(((vader_struct_vader_vm$Translation_t*) l0)->f_constants, vader_ref_box(l2));
        if (l3.tag == 0u) {
            vader_host_std_abort$panic(2503u);
            vader_unreachable("a no-return call returned");
        } else {
            l4 = ((int64_t) l3.payload.i);
            l2 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
            t0 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_slots;
            t1 = vader_chk_add(i64, t0, l4);
            l5 = ((int32_t) (int64_t) t1);
            vader_struct_vader_vm$Pending_t* _a0_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
            vader_obj_header_init(_a0_obj, 1435u);
            _a0_obj->f_kind = (uint8_t) 2;
            _a0_obj->f_register = l5;
            l6 = (void*) _a0_obj;
            vader_array_push_ref((vader_array_t*) l2, l6);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_vm$push_little_endian(void* l0, int64_t l1, int64_t l2) {
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

static void vader_vm$push_register(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
    vader_struct_vader_vm$Pending_t* _a0_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
    vader_obj_header_init(_a0_obj, 1435u);
    _a0_obj->f_kind = (uint8_t) 0;
    _a0_obj->f_register = l1;
    l3 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm$push_val(void* l0, int64_t l1, vader_box_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t t0;
    double t1;
    bool t2;
    uint32_t t3;
    if (l2.tag == 338u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t0 = ((int32_t) l2.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        return;
    }
    if (l2.tag == 339u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        l4 = ((int64_t) l2.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(1);
    } else if ((l2.tag == 344u || l2.tag == 345u)) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t1 = ((double) l2.payload.f);
        l4 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(2);
    } else if (l2.tag == 333u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
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
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(3);
    } else if (l2.tag == 334u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t3 = ((uint32_t) l2.payload.i);
        l4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
        ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
        ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(4);
    } else if (l2.tag == 1429u) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l1)
        ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(5);
    } else {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_stack;
        l5 = l2;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l1)
        vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l1] = l5;
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l1)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(6);
    }
    return;
}

static uint8_t vader_vm$pushed_tags(void* l0, vader_box_t l1, void* l2, uint8_t l3) {
    uint8_t l4, l6;
    int32_t l5, l7;
    void* l8;
    vader_box_t l9;
    void* t0;
    vader_box_t t1;
    int32_t t2;
    if ((l1.tag == 724u || l1.tag == 782u || l1.tag == 800u || l1.tag == 801u || l1.tag == 802u || l1.tag == 803u || l1.tag == 804u || l1.tag == 805u || l1.tag == 806u || l1.tag == 812u || l1.tag == 813u || l1.tag == 815u || l1.tag == 816u || l1.tag == 817u || l1.tag == 818u || l1.tag == 819u || l1.tag == 843u || l1.tag == 848u || l1.tag == 871u || l1.tag == 880u || l1.tag == 885u)) {
        l4 = (uint8_t) 1;
        return l4;
    }
    if ((l1.tag == 795u || l1.tag == 820u || l1.tag == 821u || l1.tag == 822u || l1.tag == 823u || l1.tag == 824u || l1.tag == 825u || l1.tag == 826u || l1.tag == 832u || l1.tag == 833u || l1.tag == 835u || l1.tag == 836u || l1.tag == 837u || l1.tag == 838u || l1.tag == 839u || l1.tag == 844u || l1.tag == 863u || l1.tag == 886u || l1.tag == 891u)) {
        l4 = (uint8_t) 2;
    } else if ((l1.tag == 752u || l1.tag == 753u || l1.tag == 783u || l1.tag == 784u || l1.tag == 785u || l1.tag == 791u || l1.tag == 793u || l1.tag == 794u || l1.tag == 842u || l1.tag == 845u)) {
        l4 = (uint8_t) 4;
    } else if ((l1.tag == 755u || l1.tag == 756u || l1.tag == 757u || l1.tag == 758u || l1.tag == 759u || l1.tag == 760u || l1.tag == 786u || l1.tag == 787u || l1.tag == 788u || l1.tag == 789u || l1.tag == 790u || l1.tag == 792u || l1.tag == 807u || l1.tag == 808u || l1.tag == 809u || l1.tag == 810u || l1.tag == 811u || l1.tag == 814u || l1.tag == 827u || l1.tag == 828u || l1.tag == 829u || l1.tag == 830u || l1.tag == 831u || l1.tag == 834u || l1.tag == 858u || l1.tag == 859u || l1.tag == 873u || l1.tag == 874u || l1.tag == 878u || l1.tag == 881u || l1.tag == 882u || l1.tag == 883u || l1.tag == 884u || l1.tag == 887u || l1.tag == 888u || l1.tag == 889u || l1.tag == 890u)) {
        l4 = (uint8_t) 8;
    } else if (l1.tag == 771u) {
        l4 = (uint8_t) 16;
    } else if (l1.tag == 856u) {
        l4 = (uint8_t) 32;
    } else if ((l1.tag == 772u || l1.tag == 773u)) {
        l4 = vader_vm$integer_tags(VADER_UNION_FIELD(uint8_t, vader_struct_vader_core_bytecode$CheckedArith_t, f_kind, l1.payload.obj));
    } else if ((l1.tag == 725u || l1.tag == 729u || l1.tag == 731u || l1.tag == 763u || l1.tag == 764u || l1.tag == 775u || l1.tag == 796u || l1.tag == 797u || l1.tag == 854u || l1.tag == 872u || l1.tag == 876u || l1.tag == 879u)) {
        l4 = (uint8_t) 64;
    } else if (l1.tag == 850u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 340u);
        l4 = ((uint8_t) t1.payload.i);
    } else if ((l1.tag == 852u || l1.tag == 860u)) {
        l4 = l3;
    } else if (l1.tag == 857u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        l6 = vader_vm$tags_of_type(l0, l5);
        t2 = (l3 & l6);
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 774u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
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
    } else if ((l1.tag == 875u || l1.tag == 892u)) {
        l5 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_type_id, l1.payload.obj);
        l7 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_field_index, l1.payload.obj);
        l4 = vader_vm$field_tags(l0, l5, l7);
    } else if (l1.tag == 849u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
        l4 = vader_vm$field_tags(l0, l5, l7);
    } else if (l1.tag == 723u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        l4 = vader_vm$element_tags(l0, l5);
    } else if (l1.tag == 798u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        l4 = vader_vm$global_tags(l0, l5);
    } else if (l1.tag == 728u) {
        l4 = (uint8_t) 127;
    } else if (l1.tag == 846u) {
        t2 = (INT32_C(1) | INT32_C(16));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 847u) {
        t2 = (INT32_C(2) | INT32_C(1));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 770u) {
        l8 = ((vader_struct_vader_vm$TagContext_t*) l0)->f_module;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        l9 = vader_vm$fn_type_of(l8, l5);
        if (l9.tag == 0u) {
            l4 = (uint8_t) 127;
        } else {
            t0 = l9.payload.obj;
            l5 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_return_type;
            l4 = vader_vm$tags_of_type(l0, l5);
        }
    } else {
        if (!((l1.tag == 721u || l1.tag == 722u || l1.tag == 726u || l1.tag == 727u || l1.tag == 730u || l1.tag == 754u || l1.tag == 761u || l1.tag == 762u || l1.tag == 765u || l1.tag == 768u || l1.tag == 769u || l1.tag == 777u || l1.tag == 778u || l1.tag == 779u || l1.tag == 780u || l1.tag == 781u || l1.tag == 799u || l1.tag == 840u || l1.tag == 851u || l1.tag == 853u || l1.tag == 855u || l1.tag == 861u || l1.tag == 862u || l1.tag == 864u || l1.tag == 865u || l1.tag == 866u || l1.tag == 867u || l1.tag == 868u || l1.tag == 869u || l1.tag == 870u || l1.tag == 877u || l1.tag == 893u || l1.tag == 894u || l1.tag == 895u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (uint8_t) 0;
    }
    return l4;
}

static vader_box_t vader_vm$read_array(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!(l0.tag == 1418u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 477u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$read_back_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5) {
    void* l6 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l28 = NULL;
    int64_t l7, l8, l11, l12, l16, l19, l20, l24, l25, l27;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l17 = vader_box_null(), l29 = vader_box_null();
    int32_t l15;
    double l21;
    uint8_t l23;
    bool l26;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[5] = { &l9, &l10, &l17, &l29, &t1 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l6, &l13, &l14, &l18, &l22, &l28, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l5 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_core_bytecode$c_struct_layout(l3, l4);
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) l3)->length;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = vader_core_bytecode$nested_mirror(t0, l4);
        if (l9.tag == 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l17 = vader_core_bytecode$c_field_width(t0, l4);
            if (l17.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l16 = ((int64_t) l17.payload.i);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
            if ((t1.tag == 344u || t1.tag == 345u)) {
                l18 = ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l6)->f_offsets);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                l19 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
                l20 = vader_chk_add(i64, l1, l19);
                l21 = vader_vm$read_float(l0, l20, l16);
                vader_array_t* _a4_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
                vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7] = vader_box_f64(345u, l21);
                VADER_WRITE_BARRIER(_a4_slotarr->buf);
                l7 = (l7 + INT64_C(1));
                continue;
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l22 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l23 = vader_vm$field_val_type(l4, l22);
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
            l24 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
            l25 = vader_chk_add(i64, l1, l24);
            t2 = vader_core_bytecode$is_unsigned_val(l23);
            l26 = !(t2);
            l27 = vader_vm$read_little_endian(l0, l25, l16, l26);
            l28 = ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields;
            l29 = vader_vm$mirror_field_value(l23, l27);
            vader_array_t* _a7_slotarr = ((vader_array_t*) l28);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
            vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7] = l29;
            VADER_WRITE_BARRIER(_a7_slotarr->buf);
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        l10 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l7];
        if (l10.tag == 1443u) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
            l11 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l7];
            l12 = vader_chk_add(i64, l1, l11);
            l13 = l10.payload.obj;
            t0 = l9.payload.obj;
            l14 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
            l15 = vader_chk_add(i32, l5, INT32_C(1));
            vader_vm$read_back_mirror(l0, l12, l13, l14, l4, l15);
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$read_bool(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!(l0.tag == 333u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 478u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.b;
    { vader_box_t __vret = vader_box_bool(333u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_f64(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!((l0.tag == 344u || l0.tag == 345u))) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 479u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l0.payload.f);
    { vader_box_t __vret = vader_box_f64(345u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_vm$read_float(void* l0, int64_t l1, int64_t l2) {
    uint64_t l3;
    l3 = vader_core_bytecode$read_le(l0, l1, l2);
    if (!(l2 == INT64_C(4))) {
        return (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l3) }).__vd);
    }
    return ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l3)) }).__vf));
}

static vader_box_t vader_vm$read_fn(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!(l0.tag == 1422u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 480u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_i32(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (l0.tag == 338u) {
        t0 = ((int32_t) l0.payload.i);
        l3 = vader_box_i32(338u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 334u) {
        t1 = ((uint32_t) l0.payload.i);
        l3 = vader_box_i32(338u, ((int32_t) (uint32_t) t1));
    } else if (l0.tag == 339u) {
        t2 = ((int64_t) l0.payload.i);
        l3 = vader_box_i32(338u, ((int32_t) (int64_t) t2));
    } else {
        l4 = l2;
        l5 = vader_vm$describe_value_tag(l0);
        l6 = vader_host_std_core$byte_len(l4);
        l7 = vader_host_std_core$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 96u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 481u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t3 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t3;
        t4 = (void*) _a0_obj;
        l3 = vader_ref_box(t4);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_i64(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (l0.tag == 339u) {
        t0 = ((int64_t) l0.payload.i);
        l3 = vader_box_i64(339u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 338u) {
        t1 = ((int32_t) l0.payload.i);
        l3 = vader_box_i64(339u, ((int64_t) (int32_t) t1));
    } else {
        l4 = l2;
        l5 = vader_vm$describe_value_tag(l0);
        l6 = vader_host_std_core$byte_len(l4);
        l7 = vader_host_std_core$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 96u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 482u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t2 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t2;
        t3 = (void*) _a0_obj;
        l3 = vader_ref_box(t3);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$read_little_endian(void* l0, int64_t l1, int64_t l2, bool l3) {
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
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 340u);
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

static vader_box_t vader_vm$read_numeric_as_f64(vader_box_t l0, int32_t l1) {
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
    if (l0.tag == 338u) {
        t0 = ((int32_t) l0.payload.i);
        l2 = vader_box_f64(345u, ((double) (int32_t) t0));
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 339u) {
        t1 = ((int64_t) l0.payload.i);
        l2 = vader_box_f64(345u, ((double) (int64_t) t1));
    } else if ((l0.tag == 344u || l0.tag == 345u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_f64(345u, t2);
    } else if (l0.tag == 334u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_f64(345u, ((double) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else {
        l3 = vader_vm$describe_value_tag(l0);
        l4 = vader_host_std_core$byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(55) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l5, l4, 1801u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l5, l4, l6);
        l4 = std_core$write_string_at(l5, l4, 473u);
        l4 = std_core$write_string_at(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 92u);
        t4 = std_core$finish_buffer(l5, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t4;
        t5 = (void*) _a0_obj;
        l2 = vader_ref_box(t5);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_numeric_as_i64(vader_box_t l0, int32_t l1) {
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
    if (l0.tag == 339u) {
        t0 = ((int64_t) l0.payload.i);
        l2 = vader_box_i64(339u, t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 338u) {
        t1 = ((int32_t) l0.payload.i);
        l2 = vader_box_i64(339u, ((int64_t) (int32_t) t1));
    } else if ((l0.tag == 344u || l0.tag == 345u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_i64(339u, ((int64_t) (double) t2));
    } else if (l0.tag == 334u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_i64(339u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else if (l0.tag == 333u) {
        t4 = l0.payload.b;
        if (t4) {
            l2 = vader_box_i64(339u, INT64_C(1));
        } else {
            l2 = vader_box_i64(339u, INT64_C(0));
        }
    } else {
        l3 = vader_vm$describe_value_tag(l0);
        l4 = vader_host_std_core$byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(59) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l5, l4, 1801u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l5, l4, l6);
        l4 = std_core$write_string_at(l5, l4, 473u);
        l4 = std_core$write_string_at(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 93u);
        t5 = std_core$finish_buffer(l5, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t5;
        t6 = (void*) _a0_obj;
        l2 = vader_ref_box(t6);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_obj(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!(l0.tag == 1430u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 484u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_scalar_word(vader_box_t l0, int32_t l1, vader_string_t l2) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    uint32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 333u) {
        t0 = l0.payload.b;
        if (t0) {
            { vader_box_t __vret = vader_box_i64(339u, INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i64(339u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 334u)) {
        t1 = vader_vm$read_i64(l0, l1, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((uint32_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(339u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t2))); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_string(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!(l0.tag == 335u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 485u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.s;
    { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_struct(vader_box_t l0, int32_t l1, vader_string_t l2) {
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
    if (!(l0.tag == 1443u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 96u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 486u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$read_struct_field(vader_box_t l0, int32_t l1, int32_t l2, vader_string_t l3) {
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
    if (!(l0.tag == 1443u)) {
        l4 = l0;
        l5 = concat_2(l3, 205u);
        t0 = vader_vm$read_struct(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1 < INT32_C(0))) {
        l6 = true;
    } else {
        l7 = ((int64_t) (int32_t) l1);
        t1 = l0.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields)->length;
        l6 = (l7 >= l8);
    }
    if (!(l6)) {
        t1 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l7 = vader_host_std_core$byte_len(l5);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(108) + l7));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l9, l7, l5);
    l7 = std_core$write_string_at(l9, l7, 121u);
    l8 = ((int64_t) (int32_t) l1);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 193u);
    t1 = l0.payload.obj;
    l8 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields)->length;
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 122u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core$write_int(l9, l7, l8);
    t2 = std_core$finish_buffer(l9, l7);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t2;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$receiver_trap(void* l0, int64_t l1, void* l2, int64_t l3, vader_string_t l4, vader_string_t l5) {
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
    t0 = vader_vm$register_value(l0, l1);
    l6 = vader_vm$describe_value_tag(t0);
    l7 = l4;
    l8 = vader_host_std_core$byte_len(l7);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(36) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l9, l8, l7);
    l8 = std_core$write_string_at(l9, l8, 206u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l10 = ((int64_t) (int32_t) t1);
    l8 = std_core$write_int(l9, l8, l10);
    t2 = std_core$finish_buffer(l9, l8);
    t3 = concat_5(t2, 476u, l5, 374u, l6);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_message = t3;
    t4 = (void*) _a1_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$receiver_type_id_of(void* l0, vader_box_t l1) {
    int32_t l2;
    vader_box_t l3;
    void* t0;
    if (l1.tag == 1443u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id;
        return l2;
    }
    if (l1.tag == 1418u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id;
    } else {
        l3 = l1;
        l2 = vader_vm$primitive_type_id(l0, l3);
    }
    return l2;
}

static void* vader_vm$reduce_data_pool(void* l0, void* l1, void* l2) {
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
    vader_array_t* _a0_arr = vader_array_new(220u, 0u, 13u, 1418u);
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
        vader_array_t* _a3_arr = vader_array_new(269u, 0u, 0u, 2153u);
        l7 = (void*) _a3_arr;
        if (l6.tag == 745u) {
            t0 = l6.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$BcStrData_t*) t0)->f_values;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l10];
                l11 = t1.payload.s;
                vader_array_push((vader_array_t*) l7, vader_box_string(335u, l11));
                l10 = (l10 + INT64_C(1));
            }
        } else if (l6.tag == 741u) {
            t0 = l6.payload.obj;
            l12 = ((vader_struct_vader_core_bytecode$BcPrimData_t*) t0)->f_items;
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                l15 = (uint64_t) (int64_t) t2;
                t0 = l6.payload.obj;
                l16 = vader_vm$value_from_bits(((vader_struct_vader_core_bytecode$BcPrimData_t*) t0)->f_kind, l15);
                vader_array_push((vader_array_t*) l7, l16);
                l14 = (l14 + INT64_C(1));
            }
        } else if (l6.tag == 732u) {
            t0 = l6.payload.obj;
            l17 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t0)->f_elements;
            l18 = ((vader_array_t*) l17)->length;
            l19 = INT64_C(0);
            while ((l19 < l18)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l19);
                l20 = vader_vm$bc_value_to_vm(t1, l1);
                vader_array_push((vader_array_t*) l7, l20);
                l19 = (l19 + INT64_C(1));
            }
        }
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
        l21 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
        l22 = ((vader_array_t*) l7)->length;
        vader_struct_vader_vm$ArrayVal_t* _a8_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
        vader_obj_header_init(_a8_obj, 1418u);
        _a8_obj->f_type_id = l21;
        _a8_obj->f_elements = l7;
        _a8_obj->f_offset = INT64_C(0);
        _a8_obj->f_length = l22;
        _a8_obj->f_raw = vader_box_obj(0u, NULL);
        l23 = (void*) _a8_obj;
        vader_array_push_ref((vader_array_t*) l3, l23);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$ref_type_matches(void* l0, vader_box_t l1, vader_string_t l2) {
    bool l3;
    int32_t l4;
    bool t0;
    if (l2 == 0u) {
        if (l1.tag == 1443u) {
            l3 = true;
            return l3;
        }
        if (l1.tag == 1418u) {
            l3 = true;
        } else if (l1.tag == 1422u) {
            l3 = true;
        } else {
            l3 = false;
        }
        return l3;
    }
    if ((l1.tag == 1418u || l1.tag == 1443u)) {
        l4 = VADER_UNION_FIELD(int32_t, vader_struct_vader_vm$ArrayVal_t, f_type_id, l1.payload.obj);
        t0 = vader_vm$trait_implemented_by(l0, l2, l4);
        return t0;
    }
    return false;
}

static vader_box_t vader_vm$reg_call(void* l0, void* l1, void* l2, int32_t l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l9 = ((int64_t) 1024);
    if ((l5 >= l9)) {
        t0 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_name;
        t1 = vader_vm$overflow_trap(t0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_vm$enter_frame(l2, l8, l4);
    l9 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code)->length;
    if ((l5 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5, l8);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (int64_t) l6;
    } else {
        vader_vm$grow_frame_records(l2, l8, l4, l6);
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
    l14 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_ops;
    l15 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_words;
    l16 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_bits;
    l17 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_tags;
    l18 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_refs;
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
            t2 = vader_vm$operand_a(l20);
            l21 = ((int64_t) (int32_t) t2);
            l22 = vader_chk_add(i64, l12, l21);
            t2 = vader_vm$operand_b(l20);
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
            t3 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l24, 340u);
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
            t2 = vader_vm$operand_a(l20);
            l28 = ((int64_t) (int32_t) t2);
            l29 = vader_chk_add(i64, l12, l28);
            t2 = vader_vm$operand_b(l20);
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
            t3 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l31, 340u);
            l33 = ((uint8_t) t3.payload.i);
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l29)
            ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l29] = (uint8_t) (int32_t) (uint8_t) l33;
        } else if (l19 == INT32_C(2)) {
            l34 = vader_vm$operand_a(l20);
            l35 = vader_vm$operand_b(l20);
            l36 = vader_vm$i32_of(l16, l12, l35);
            l37 = vader_vm$operand_c(l20);
            l38 = vader_vm$i32_of(l16, l12, l37);
            l39 = (l36 + l38);
            vader_vm$set_i32(l16, l17, l12, l34, l39);
        } else if (l19 == INT32_C(3)) {
            l40 = vader_vm$operand_a(l20);
            l41 = vader_vm$operand_b(l20);
            l42 = vader_vm$i32_of(l16, l12, l41);
            l43 = vader_vm$operand_c(l20);
            l44 = vader_vm$i32_of(l16, l12, l43);
            l45 = (l42 - l44);
            vader_vm$set_i32(l16, l17, l12, l40, l45);
        } else if (l19 == INT32_C(4)) {
            l46 = vader_vm$operand_a(l20);
            l47 = vader_vm$operand_b(l20);
            l48 = vader_vm$i32_of(l16, l12, l47);
            l49 = vader_vm$operand_c(l20);
            l50 = vader_vm$i32_of(l16, l12, l49);
            l51 = (l48 * l50);
            vader_vm$set_i32(l16, l17, l12, l46, l51);
        } else if (l19 == INT32_C(5)) {
            l52 = vader_vm$operand_c(l20);
            l53 = vader_vm$i32_of(l16, l12, l52);
            if (l53 == INT32_C(0)) {
                l54 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l55 = INT64_C(0);
                l55 = std_core$write_string_at(l54, l55, 2083u);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
                t2 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l13];
                l56 = ((int64_t) (int32_t) t2);
                l55 = std_core$write_int(l54, l55, l56);
                t0 = std_core$finish_buffer(l54, l55);
                vader_struct_vader_vm$Trap_t* _a12_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a12_obj, 1446u);
                _a12_obj->f_message = t0;
                t1 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l57 = vader_vm$operand_a(l20);
            l58 = vader_vm$operand_b(l20);
            t2 = vader_vm$i32_of(l16, l12, l58);
            l59 = vader_div_i32(t2, l53);
            vader_vm$set_i32(l16, l17, l12, l57, l59);
        } else if (l19 == INT32_C(6)) {
            l60 = vader_vm$operand_c(l20);
            l61 = vader_vm$i32_of(l16, l12, l60);
            if (l61 == INT32_C(0)) {
                l62 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l63 = INT64_C(0);
                l63 = std_core$write_string_at(l62, l63, 2089u);
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
                t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l13];
                l64 = ((int64_t) (int32_t) t2);
                l63 = std_core$write_int(l62, l63, l64);
                t0 = std_core$finish_buffer(l62, l63);
                vader_struct_vader_vm$Trap_t* _a14_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a14_obj, 1446u);
                _a14_obj->f_message = t0;
                t1 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l65 = vader_vm$operand_a(l20);
            l66 = vader_vm$operand_b(l20);
            t2 = vader_vm$i32_of(l16, l12, l66);
            l67 = vader_mod_i32(t2, l61);
            vader_vm$set_i32(l16, l17, l12, l65, l67);
        } else if (l19 == INT32_C(7)) {
            l68 = vader_vm$operand_a(l20);
            l69 = vader_vm$operand_b(l20);
            l70 = vader_vm$i32_of(l16, l12, l69);
            l71 = vader_vm$operand_c(l20);
            l72 = vader_vm$i32_of(l16, l12, l71);
            l73 = (l70 & l72);
            vader_vm$set_i32(l16, l17, l12, l68, l73);
        } else if (l19 == INT32_C(8)) {
            l74 = vader_vm$operand_a(l20);
            l75 = vader_vm$operand_b(l20);
            l76 = vader_vm$i32_of(l16, l12, l75);
            l77 = vader_vm$operand_c(l20);
            l78 = vader_vm$i32_of(l16, l12, l77);
            l79 = (l76 | l78);
            vader_vm$set_i32(l16, l17, l12, l74, l79);
        } else if (l19 == INT32_C(9)) {
            l80 = vader_vm$operand_a(l20);
            l81 = vader_vm$operand_b(l20);
            l82 = vader_vm$i32_of(l16, l12, l81);
            l83 = vader_vm$operand_c(l20);
            l84 = vader_vm$i32_of(l16, l12, l83);
            l85 = (l82 ^ l84);
            vader_vm$set_i32(l16, l17, l12, l80, l85);
        } else if (l19 == INT32_C(10)) {
            l86 = vader_vm$operand_a(l20);
            l87 = vader_vm$operand_b(l20);
            l88 = vader_vm$i32_of(l16, l12, l87);
            l89 = vader_vm$operand_c(l20);
            l90 = vader_vm$i32_of(l16, l12, l89);
            l91 = (l88 << (l90 & 31));
            vader_vm$set_i32(l16, l17, l12, l86, l91);
        } else if (l19 == INT32_C(11)) {
            l92 = vader_vm$operand_a(l20);
            l93 = vader_vm$operand_b(l20);
            l94 = vader_vm$i32_of(l16, l12, l93);
            l95 = vader_vm$operand_c(l20);
            l96 = vader_vm$i32_of(l16, l12, l95);
            l97 = (l94 >> (l96 & 31));
            vader_vm$set_i32(l16, l17, l12, l92, l97);
        } else if (l19 == INT32_C(12)) {
            l98 = vader_vm$operand_b(l20);
            t2 = vader_vm$i32_of(l16, l12, l98);
            t4 = t2;
            l99 = (uint32_t) (int32_t) t4;
            l100 = vader_vm$operand_a(l20);
            l101 = vader_vm$operand_c(l20);
            t2 = vader_vm$i32_of(l16, l12, l101);
            t4 = t2;
            l102 = (uint32_t) (int32_t) t4;
            l103 = ((int32_t) (uint32_t) (l99 >> (l102 & 31)));
            vader_vm$set_i32(l16, l17, l12, l100, l103);
        } else if (l19 == INT32_C(13)) {
            l104 = vader_vm$operand_a(l20);
            l105 = vader_vm$operand_b(l20);
            l106 = vader_vm$i32_of(l16, l12, l105);
            l107 = (INT32_C(0) - l106);
            vader_vm$set_i32(l16, l17, l12, l104, l107);
        } else if (l19 == INT32_C(14)) {
            l108 = vader_vm$operand_a(l20);
            l109 = vader_vm$operand_b(l20);
            t2 = vader_vm$i32_of(l16, l12, l109);
            l110 = ~(t2);
            vader_vm$set_i32(l16, l17, l12, l108, l110);
        } else if (l19 == INT32_C(15)) {
            l111 = vader_vm$operand_c(l20);
            l112 = vader_vm$i32_of(l16, l12, l111);
            if (l112 == INT32_C(0)) {
                l113 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l114 = INT64_C(0);
                l114 = std_core$write_string_at(l113, l114, 2776u);
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
                t2 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l13];
                l115 = ((int64_t) (int32_t) t2);
                l114 = std_core$write_int(l113, l114, l115);
                t0 = std_core$finish_buffer(l113, l114);
                vader_struct_vader_vm$Trap_t* _a16_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a16_obj, 1446u);
                _a16_obj->f_message = t0;
                t1 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l116 = vader_vm$operand_a(l20);
            l117 = vader_vm$operand_b(l20);
            t2 = vader_vm$i32_of(l16, l12, l117);
            t4 = t2;
            l118 = (uint32_t) (int32_t) t4;
            t2 = l112;
            l119 = (uint32_t) (int32_t) t2;
            t5 = vader_div_u32(l118, l119);
            l120 = ((int32_t) (uint32_t) t5);
            vader_vm$set_i32(l16, l17, l12, l116, l120);
        } else if (l19 == INT32_C(16)) {
            l121 = vader_vm$operand_c(l20);
            l122 = vader_vm$i32_of(l16, l12, l121);
            if (l122 == INT32_C(0)) {
                l123 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l124 = INT64_C(0);
                l124 = std_core$write_string_at(l123, l124, 2782u);
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
                t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l13];
                l125 = ((int64_t) (int32_t) t2);
                l124 = std_core$write_int(l123, l124, l125);
                t0 = std_core$finish_buffer(l123, l124);
                vader_struct_vader_vm$Trap_t* _a18_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a18_obj, 1446u);
                _a18_obj->f_message = t0;
                t1 = (void*) _a18_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l126 = vader_vm$operand_a(l20);
            l127 = vader_vm$operand_b(l20);
            t2 = vader_vm$i32_of(l16, l12, l127);
            t4 = t2;
            l128 = (uint32_t) (int32_t) t4;
            t2 = l122;
            l129 = (uint32_t) (int32_t) t2;
            t5 = vader_mod_u32(l128, l129);
            l130 = ((int32_t) (uint32_t) t5);
            vader_vm$set_i32(l16, l17, l12, l126, l130);
        } else if (l19 == INT32_C(17)) {
            l131 = vader_vm$operand_a(l20);
            l132 = vader_vm$operand_b(l20);
            l133 = vader_vm$i32_of(l16, l12, l132);
            l134 = vader_vm$operand_c(l20);
            l135 = vader_vm$i32_of(l16, l12, l134);
            l136 = l133 == l135;
            vader_vm$set_bool(l16, l17, l12, l131, l136);
        } else if (l19 == INT32_C(18)) {
            l137 = vader_vm$operand_a(l20);
            l138 = vader_vm$operand_b(l20);
            l139 = vader_vm$i32_of(l16, l12, l138);
            l140 = vader_vm$operand_c(l20);
            l141 = vader_vm$i32_of(l16, l12, l140);
            l142 = l139 != l141;
            vader_vm$set_bool(l16, l17, l12, l137, l142);
        } else if (l19 == INT32_C(19)) {
            l143 = vader_vm$operand_a(l20);
            l144 = vader_vm$operand_b(l20);
            l145 = vader_vm$i32_of(l16, l12, l144);
            l146 = vader_vm$operand_c(l20);
            l147 = vader_vm$i32_of(l16, l12, l146);
            l148 = (l145 < l147);
            vader_vm$set_bool(l16, l17, l12, l143, l148);
        } else if (l19 == INT32_C(20)) {
            l149 = vader_vm$operand_a(l20);
            l150 = vader_vm$operand_b(l20);
            l151 = vader_vm$i32_of(l16, l12, l150);
            l152 = vader_vm$operand_c(l20);
            l153 = vader_vm$i32_of(l16, l12, l152);
            l154 = (l151 <= l153);
            vader_vm$set_bool(l16, l17, l12, l149, l154);
        } else if (l19 == INT32_C(21)) {
            l155 = vader_vm$operand_a(l20);
            l156 = vader_vm$operand_b(l20);
            l157 = vader_vm$i32_of(l16, l12, l156);
            l158 = vader_vm$operand_c(l20);
            l159 = vader_vm$i32_of(l16, l12, l158);
            l160 = (l157 > l159);
            vader_vm$set_bool(l16, l17, l12, l155, l160);
        } else if (l19 == INT32_C(22)) {
            l161 = vader_vm$operand_a(l20);
            l162 = vader_vm$operand_b(l20);
            l163 = vader_vm$i32_of(l16, l12, l162);
            l164 = vader_vm$operand_c(l20);
            l165 = vader_vm$i32_of(l16, l12, l164);
            l166 = (l163 >= l165);
            vader_vm$set_bool(l16, l17, l12, l161, l166);
        } else if (l19 == INT32_C(23)) {
            l167 = vader_vm$operand_a(l20);
            l168 = vader_vm$operand_b(l20);
            l169 = vader_vm$u32_of(l16, l12, l168);
            l170 = vader_vm$operand_c(l20);
            l171 = vader_vm$u32_of(l16, l12, l170);
            l172 = (l169 < l171);
            vader_vm$set_bool(l16, l17, l12, l167, l172);
        } else if (l19 == INT32_C(24)) {
            l173 = vader_vm$operand_a(l20);
            l174 = vader_vm$operand_b(l20);
            l175 = vader_vm$u32_of(l16, l12, l174);
            l176 = vader_vm$operand_c(l20);
            l177 = vader_vm$u32_of(l16, l12, l176);
            l178 = (l175 <= l177);
            vader_vm$set_bool(l16, l17, l12, l173, l178);
        } else if (l19 == INT32_C(25)) {
            l179 = vader_vm$operand_a(l20);
            l180 = vader_vm$operand_b(l20);
            l181 = vader_vm$u32_of(l16, l12, l180);
            l182 = vader_vm$operand_c(l20);
            l183 = vader_vm$u32_of(l16, l12, l182);
            l184 = (l181 > l183);
            vader_vm$set_bool(l16, l17, l12, l179, l184);
        } else if (l19 == INT32_C(26)) {
            l185 = vader_vm$operand_a(l20);
            l186 = vader_vm$operand_b(l20);
            l187 = vader_vm$u32_of(l16, l12, l186);
            l188 = vader_vm$operand_c(l20);
            l189 = vader_vm$u32_of(l16, l12, l188);
            l190 = (l187 >= l189);
            vader_vm$set_bool(l16, l17, l12, l185, l190);
        } else if (l19 == INT32_C(27)) {
            l191 = vader_vm$operand_a(l20);
            l192 = vader_vm$operand_b(l20);
            l193 = vader_vm$bits_of(l16, l12, l192);
            l194 = vader_vm$operand_c(l20);
            l195 = vader_vm$bits_of(l16, l12, l194);
            l196 = (l193 + l195);
            vader_vm$set_i64(l16, l17, l12, l191, l196);
        } else if (l19 == INT32_C(28)) {
            l197 = vader_vm$operand_a(l20);
            l198 = vader_vm$operand_b(l20);
            l199 = vader_vm$bits_of(l16, l12, l198);
            l200 = vader_vm$operand_c(l20);
            l201 = vader_vm$bits_of(l16, l12, l200);
            l202 = (l199 - l201);
            vader_vm$set_i64(l16, l17, l12, l197, l202);
        } else if (l19 == INT32_C(29)) {
            l203 = vader_vm$operand_a(l20);
            l204 = vader_vm$operand_b(l20);
            l205 = vader_vm$bits_of(l16, l12, l204);
            l206 = vader_vm$operand_c(l20);
            l207 = vader_vm$bits_of(l16, l12, l206);
            l208 = (l205 * l207);
            vader_vm$set_i64(l16, l17, l12, l203, l208);
        } else if (l19 == INT32_C(30)) {
            l209 = vader_vm$operand_c(l20);
            l210 = vader_vm$bits_of(l16, l12, l209);
            if (l210 == INT64_C(0)) {
                l211 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l212 = INT64_C(0);
                l212 = std_core$write_string_at(l211, l212, 2105u);
                vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l13)
                t2 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l13];
                l213 = ((int64_t) (int32_t) t2);
                l212 = std_core$write_int(l211, l212, l213);
                t0 = std_core$finish_buffer(l211, l212);
                vader_struct_vader_vm$Trap_t* _a20_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a20_obj, 1446u);
                _a20_obj->f_message = t0;
                t1 = (void*) _a20_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l214 = vader_vm$operand_a(l20);
            l215 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l215);
            l216 = vader_div_i64(t6, l210);
            vader_vm$set_i64(l16, l17, l12, l214, l216);
        } else if (l19 == INT32_C(31)) {
            l217 = vader_vm$operand_c(l20);
            l218 = vader_vm$bits_of(l16, l12, l217);
            if (l218 == INT64_C(0)) {
                l219 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l220 = INT64_C(0);
                l220 = std_core$write_string_at(l219, l220, 2115u);
                vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l13)
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l13];
                l221 = ((int64_t) (int32_t) t2);
                l220 = std_core$write_int(l219, l220, l221);
                t0 = std_core$finish_buffer(l219, l220);
                vader_struct_vader_vm$Trap_t* _a22_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a22_obj, 1446u);
                _a22_obj->f_message = t0;
                t1 = (void*) _a22_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l222 = vader_vm$operand_a(l20);
            l223 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l223);
            l224 = vader_mod_i64(t6, l218);
            vader_vm$set_i64(l16, l17, l12, l222, l224);
        } else if (l19 == INT32_C(32)) {
            l225 = vader_vm$operand_a(l20);
            l226 = vader_vm$operand_b(l20);
            l227 = vader_vm$bits_of(l16, l12, l226);
            l228 = vader_vm$operand_c(l20);
            l229 = vader_vm$bits_of(l16, l12, l228);
            l230 = (l227 & l229);
            vader_vm$set_i64(l16, l17, l12, l225, l230);
        } else if (l19 == INT32_C(33)) {
            l231 = vader_vm$operand_a(l20);
            l232 = vader_vm$operand_b(l20);
            l233 = vader_vm$bits_of(l16, l12, l232);
            l234 = vader_vm$operand_c(l20);
            l235 = vader_vm$bits_of(l16, l12, l234);
            l236 = (l233 | l235);
            vader_vm$set_i64(l16, l17, l12, l231, l236);
        } else if (l19 == INT32_C(34)) {
            l237 = vader_vm$operand_a(l20);
            l238 = vader_vm$operand_b(l20);
            l239 = vader_vm$bits_of(l16, l12, l238);
            l240 = vader_vm$operand_c(l20);
            l241 = vader_vm$bits_of(l16, l12, l240);
            l242 = (l239 ^ l241);
            vader_vm$set_i64(l16, l17, l12, l237, l242);
        } else if (l19 == INT32_C(35)) {
            l243 = vader_vm$operand_a(l20);
            l244 = vader_vm$operand_b(l20);
            l245 = vader_vm$bits_of(l16, l12, l244);
            l246 = vader_vm$operand_c(l20);
            l247 = vader_vm$bits_of(l16, l12, l246);
            l248 = (l245 << (l247 & 63));
            vader_vm$set_i64(l16, l17, l12, l243, l248);
        } else if (l19 == INT32_C(36)) {
            l249 = vader_vm$operand_a(l20);
            l250 = vader_vm$operand_b(l20);
            l251 = vader_vm$bits_of(l16, l12, l250);
            l252 = vader_vm$operand_c(l20);
            l253 = vader_vm$bits_of(l16, l12, l252);
            l254 = (l251 >> (l253 & 63));
            vader_vm$set_i64(l16, l17, l12, l249, l254);
        } else if (l19 == INT32_C(37)) {
            l255 = vader_vm$operand_a(l20);
            l256 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l256);
            t7 = t6;
            l257 = (uint64_t) (int64_t) t7;
            l258 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l258);
            t7 = t6;
            l259 = (uint64_t) (int64_t) t7;
            l260 = ((int64_t) (uint64_t) (l257 >> (l259 & 63)));
            vader_vm$set_i64(l16, l17, l12, l255, l260);
        } else if (l19 == INT32_C(38)) {
            l261 = vader_vm$operand_a(l20);
            l262 = vader_vm$operand_b(l20);
            l263 = vader_vm$bits_of(l16, l12, l262);
            l264 = (INT64_C(0) - l263);
            vader_vm$set_i64(l16, l17, l12, l261, l264);
        } else if (l19 == INT32_C(39)) {
            l265 = vader_vm$operand_a(l20);
            l266 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l266);
            l267 = ~(t6);
            vader_vm$set_i64(l16, l17, l12, l265, l267);
        } else if (l19 == INT32_C(40)) {
            l268 = vader_vm$operand_c(l20);
            l269 = vader_vm$bits_of(l16, l12, l268);
            if (l269 == INT64_C(0)) {
                l270 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l271 = INT64_C(0);
                l271 = std_core$write_string_at(l270, l271, 2786u);
                vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l13)
                t2 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l13];
                l272 = ((int64_t) (int32_t) t2);
                l271 = std_core$write_int(l270, l271, l272);
                t0 = std_core$finish_buffer(l270, l271);
                vader_struct_vader_vm$Trap_t* _a24_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a24_obj, 1446u);
                _a24_obj->f_message = t0;
                t1 = (void*) _a24_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l273 = vader_vm$operand_a(l20);
            l274 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l274);
            t7 = t6;
            l275 = (uint64_t) (int64_t) t7;
            t6 = l269;
            l276 = (uint64_t) (int64_t) t6;
            t8 = vader_div_u64(l275, l276);
            l277 = ((int64_t) (uint64_t) t8);
            vader_vm$set_i64(l16, l17, l12, l273, l277);
        } else if (l19 == INT32_C(41)) {
            l278 = vader_vm$operand_c(l20);
            l279 = vader_vm$bits_of(l16, l12, l278);
            if (l279 == INT64_C(0)) {
                l280 = (void*) vader_buffer_new((size_t) INT64_C(42));
                l281 = INT64_C(0);
                l281 = std_core$write_string_at(l280, l281, 2792u);
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l13)
                t2 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l13];
                l282 = ((int64_t) (int32_t) t2);
                l281 = std_core$write_int(l280, l281, l282);
                t0 = std_core$finish_buffer(l280, l281);
                vader_struct_vader_vm$Trap_t* _a26_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a26_obj, 1446u);
                _a26_obj->f_message = t0;
                t1 = (void*) _a26_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l283 = vader_vm$operand_a(l20);
            l284 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l284);
            t7 = t6;
            l285 = (uint64_t) (int64_t) t7;
            t6 = l279;
            l286 = (uint64_t) (int64_t) t6;
            t8 = vader_mod_u64(l285, l286);
            l287 = ((int64_t) (uint64_t) t8);
            vader_vm$set_i64(l16, l17, l12, l283, l287);
        } else if (l19 == INT32_C(42)) {
            l288 = vader_vm$operand_a(l20);
            l289 = vader_vm$operand_b(l20);
            l290 = vader_vm$bits_of(l16, l12, l289);
            l291 = vader_vm$operand_c(l20);
            l292 = vader_vm$bits_of(l16, l12, l291);
            l293 = l290 == l292;
            vader_vm$set_bool(l16, l17, l12, l288, l293);
        } else if (l19 == INT32_C(43)) {
            l294 = vader_vm$operand_a(l20);
            l295 = vader_vm$operand_b(l20);
            l296 = vader_vm$bits_of(l16, l12, l295);
            l297 = vader_vm$operand_c(l20);
            l298 = vader_vm$bits_of(l16, l12, l297);
            l299 = l296 != l298;
            vader_vm$set_bool(l16, l17, l12, l294, l299);
        } else if (l19 == INT32_C(44)) {
            l300 = vader_vm$operand_a(l20);
            l301 = vader_vm$operand_b(l20);
            l302 = vader_vm$bits_of(l16, l12, l301);
            l303 = vader_vm$operand_c(l20);
            l304 = vader_vm$bits_of(l16, l12, l303);
            l305 = (l302 < l304);
            vader_vm$set_bool(l16, l17, l12, l300, l305);
        } else if (l19 == INT32_C(45)) {
            l306 = vader_vm$operand_a(l20);
            l307 = vader_vm$operand_b(l20);
            l308 = vader_vm$bits_of(l16, l12, l307);
            l309 = vader_vm$operand_c(l20);
            l310 = vader_vm$bits_of(l16, l12, l309);
            l311 = (l308 <= l310);
            vader_vm$set_bool(l16, l17, l12, l306, l311);
        } else if (l19 == INT32_C(46)) {
            l312 = vader_vm$operand_a(l20);
            l313 = vader_vm$operand_b(l20);
            l314 = vader_vm$bits_of(l16, l12, l313);
            l315 = vader_vm$operand_c(l20);
            l316 = vader_vm$bits_of(l16, l12, l315);
            l317 = (l314 > l316);
            vader_vm$set_bool(l16, l17, l12, l312, l317);
        } else if (l19 == INT32_C(47)) {
            l318 = vader_vm$operand_a(l20);
            l319 = vader_vm$operand_b(l20);
            l320 = vader_vm$bits_of(l16, l12, l319);
            l321 = vader_vm$operand_c(l20);
            l322 = vader_vm$bits_of(l16, l12, l321);
            l323 = (l320 >= l322);
            vader_vm$set_bool(l16, l17, l12, l318, l323);
        } else if (l19 == INT32_C(48)) {
            l324 = vader_vm$operand_a(l20);
            l325 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l325);
            t7 = t6;
            l326 = (uint64_t) (int64_t) t7;
            l327 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l327);
            t7 = t6;
            l328 = (uint64_t) (int64_t) t7;
            l329 = (l326 < l328);
            vader_vm$set_bool(l16, l17, l12, l324, l329);
        } else if (l19 == INT32_C(49)) {
            l330 = vader_vm$operand_a(l20);
            l331 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l331);
            t7 = t6;
            l332 = (uint64_t) (int64_t) t7;
            l333 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l333);
            t7 = t6;
            l334 = (uint64_t) (int64_t) t7;
            l335 = (l332 <= l334);
            vader_vm$set_bool(l16, l17, l12, l330, l335);
        } else if (l19 == INT32_C(50)) {
            l336 = vader_vm$operand_a(l20);
            l337 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l337);
            t7 = t6;
            l338 = (uint64_t) (int64_t) t7;
            l339 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l339);
            t7 = t6;
            l340 = (uint64_t) (int64_t) t7;
            l341 = (l338 > l340);
            vader_vm$set_bool(l16, l17, l12, l336, l341);
        } else if (l19 == INT32_C(51)) {
            l342 = vader_vm$operand_a(l20);
            l343 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l343);
            t7 = t6;
            l344 = (uint64_t) (int64_t) t7;
            l345 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l345);
            t7 = t6;
            l346 = (uint64_t) (int64_t) t7;
            l347 = (l344 >= l346);
            vader_vm$set_bool(l16, l17, l12, l342, l347);
        } else if (l19 == INT32_C(52)) {
            l348 = vader_vm$operand_a(l20);
            l349 = vader_vm$operand_b(l20);
            l350 = vader_vm$f64_of(l16, l12, l349);
            l351 = vader_vm$operand_c(l20);
            l352 = vader_vm$f64_of(l16, l12, l351);
            l353 = (l350 + l352);
            vader_vm$set_f64(l16, l17, l12, l348, l353);
        } else if (l19 == INT32_C(53)) {
            l354 = vader_vm$operand_a(l20);
            l355 = vader_vm$operand_b(l20);
            l356 = vader_vm$f64_of(l16, l12, l355);
            l357 = vader_vm$operand_c(l20);
            l358 = vader_vm$f64_of(l16, l12, l357);
            l359 = (l356 - l358);
            vader_vm$set_f64(l16, l17, l12, l354, l359);
        } else if (l19 == INT32_C(54)) {
            l360 = vader_vm$operand_a(l20);
            l361 = vader_vm$operand_b(l20);
            l362 = vader_vm$f64_of(l16, l12, l361);
            l363 = vader_vm$operand_c(l20);
            l364 = vader_vm$f64_of(l16, l12, l363);
            l365 = (l362 * l364);
            vader_vm$set_f64(l16, l17, l12, l360, l365);
        } else if (l19 == INT32_C(55)) {
            l366 = vader_vm$operand_a(l20);
            l367 = vader_vm$operand_b(l20);
            l368 = vader_vm$f64_of(l16, l12, l367);
            l369 = vader_vm$operand_c(l20);
            l370 = vader_vm$f64_of(l16, l12, l369);
            l371 = l368 / l370;
            vader_vm$set_f64(l16, l17, l12, l366, l371);
        } else if (l19 == INT32_C(56)) {
            l372 = vader_vm$operand_a(l20);
            l373 = vader_vm$operand_b(l20);
            t9 = vader_vm$f64_of(l16, l12, l373);
            l374 = -(t9);
            vader_vm$set_f64(l16, l17, l12, l372, l374);
        } else if (l19 == INT32_C(57)) {
            l375 = vader_vm$operand_a(l20);
            l376 = vader_vm$operand_b(l20);
            l377 = vader_vm$f64_of(l16, l12, l376);
            l378 = vader_vm$operand_c(l20);
            l379 = vader_vm$f64_of(l16, l12, l378);
            l380 = l377 == l379;
            vader_vm$set_bool(l16, l17, l12, l375, l380);
        } else if (l19 == INT32_C(58)) {
            l381 = vader_vm$operand_a(l20);
            l382 = vader_vm$operand_b(l20);
            l383 = vader_vm$f64_of(l16, l12, l382);
            l384 = vader_vm$operand_c(l20);
            l385 = vader_vm$f64_of(l16, l12, l384);
            l386 = l383 != l385;
            vader_vm$set_bool(l16, l17, l12, l381, l386);
        } else if (l19 == INT32_C(59)) {
            l387 = vader_vm$operand_a(l20);
            l388 = vader_vm$operand_b(l20);
            l389 = vader_vm$f64_of(l16, l12, l388);
            l390 = vader_vm$operand_c(l20);
            l391 = vader_vm$f64_of(l16, l12, l390);
            l392 = (l389 < l391);
            vader_vm$set_bool(l16, l17, l12, l387, l392);
        } else if (l19 == INT32_C(60)) {
            l393 = vader_vm$operand_a(l20);
            l394 = vader_vm$operand_b(l20);
            l395 = vader_vm$f64_of(l16, l12, l394);
            l396 = vader_vm$operand_c(l20);
            l397 = vader_vm$f64_of(l16, l12, l396);
            l398 = (l395 <= l397);
            vader_vm$set_bool(l16, l17, l12, l393, l398);
        } else if (l19 == INT32_C(61)) {
            l399 = vader_vm$operand_a(l20);
            l400 = vader_vm$operand_b(l20);
            l401 = vader_vm$f64_of(l16, l12, l400);
            l402 = vader_vm$operand_c(l20);
            l403 = vader_vm$f64_of(l16, l12, l402);
            l404 = (l401 > l403);
            vader_vm$set_bool(l16, l17, l12, l399, l404);
        } else if (l19 == INT32_C(62)) {
            l405 = vader_vm$operand_a(l20);
            l406 = vader_vm$operand_b(l20);
            l407 = vader_vm$f64_of(l16, l12, l406);
            l408 = vader_vm$operand_c(l20);
            l409 = vader_vm$f64_of(l16, l12, l408);
            l410 = (l407 >= l409);
            vader_vm$set_bool(l16, l17, l12, l405, l410);
        } else if (l19 == INT32_C(63)) {
            l411 = vader_vm$operand_a(l20);
            l412 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l412);
            l413 = t6 != INT64_C(0);
            l414 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l414);
            l415 = t6 != INT64_C(0);
            l416 = l413 == l415;
            vader_vm$set_bool(l16, l17, l12, l411, l416);
        } else if (l19 == INT32_C(64)) {
            l417 = vader_vm$operand_a(l20);
            l418 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l418);
            l419 = t6 != INT64_C(0);
            l420 = vader_vm$operand_c(l20);
            t6 = vader_vm$bits_of(l16, l12, l420);
            l421 = t6 != INT64_C(0);
            l422 = l419 != l421;
            vader_vm$set_bool(l16, l17, l12, l417, l422);
        } else if (l19 == INT32_C(65)) {
            l423 = vader_vm$operand_a(l20);
            l424 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l424);
            if (t6 != INT64_C(0)) {
                l426 = vader_vm$operand_c(l20);
                t6 = vader_vm$bits_of(l16, l12, l426);
                l425 = t6 != INT64_C(0);
            } else {
                l425 = false;
            }
            vader_vm$set_bool(l16, l17, l12, l423, l425);
        } else if (l19 == INT32_C(66)) {
            l427 = vader_vm$operand_a(l20);
            l428 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l428);
            if (t6 != INT64_C(0)) {
                l429 = true;
            } else {
                l430 = vader_vm$operand_c(l20);
                t6 = vader_vm$bits_of(l16, l12, l430);
                l429 = t6 != INT64_C(0);
            }
            vader_vm$set_bool(l16, l17, l12, l427, l429);
        } else if (l19 == INT32_C(67)) {
            l431 = vader_vm$operand_a(l20);
            l432 = vader_vm$operand_b(l20);
            t6 = vader_vm$bits_of(l16, l12, l432);
            l433 = t6 == INT64_C(0);
            vader_vm$set_bool(l16, l17, l12, l431, l433);
        } else if (l19 == INT32_C(68)) {
            l435 = vader_vm$checked_registers((uint8_t) 0, (uint8_t) 2, l16, l12, l20);
            if (l435.tag == 0u) {
                vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l13)
                t3 = vader_array_read_u8(_a27_slotarr, _a27_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l434 = ((int64_t) l435.payload.i);
            l436 = vader_vm$operand_a(l20);
            l437 = ((int32_t) (int64_t) l434);
            vader_vm$set_i32(l16, l17, l12, l436, l437);
        } else if (l19 == INT32_C(69)) {
            l439 = vader_vm$checked_registers((uint8_t) 1, (uint8_t) 2, l16, l12, l20);
            if (l439.tag == 0u) {
                vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l13)
                t3 = vader_array_read_u8(_a28_slotarr, _a28_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l438 = ((int64_t) l439.payload.i);
            l440 = vader_vm$operand_a(l20);
            l441 = ((int32_t) (int64_t) l438);
            vader_vm$set_i32(l16, l17, l12, l440, l441);
        } else if (l19 == INT32_C(70)) {
            l443 = vader_vm$checked_registers((uint8_t) 2, (uint8_t) 2, l16, l12, l20);
            if (l443.tag == 0u) {
                vader_array_t* _a29_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l13)
                t3 = vader_array_read_u8(_a29_slotarr, _a29_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l442 = ((int64_t) l443.payload.i);
            l444 = vader_vm$operand_a(l20);
            l445 = ((int32_t) (int64_t) l442);
            vader_vm$set_i32(l16, l17, l12, l444, l445);
        } else if (l19 == INT32_C(71)) {
            l447 = vader_vm$operand_b(l20);
            l448 = vader_vm$bits_of(l16, l12, l447);
            l449 = vader_core_bytecode$checked_neg((uint8_t) 2, l448);
            if (l449.tag == 0u) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l13)
                t3 = vader_array_read_u8(_a30_slotarr, _a30_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_neg_trap(((uint8_t) t3.payload.i), l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l446 = ((int64_t) l449.payload.i);
            l450 = vader_vm$operand_a(l20);
            l451 = ((int32_t) (int64_t) l446);
            vader_vm$set_i32(l16, l17, l12, l450, l451);
        } else if (l19 == INT32_C(72)) {
            l453 = vader_vm$checked_registers((uint8_t) 0, (uint8_t) 3, l16, l12, l20);
            if (l453.tag == 0u) {
                vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l13)
                t3 = vader_array_read_u8(_a31_slotarr, _a31_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l452 = ((int64_t) l453.payload.i);
            l454 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l454, l452);
        } else if (l19 == INT32_C(73)) {
            l456 = vader_vm$checked_registers((uint8_t) 1, (uint8_t) 3, l16, l12, l20);
            if (l456.tag == 0u) {
                vader_array_t* _a32_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l13)
                t3 = vader_array_read_u8(_a32_slotarr, _a32_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l455 = ((int64_t) l456.payload.i);
            l457 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l457, l455);
        } else if (l19 == INT32_C(74)) {
            l459 = vader_vm$checked_registers((uint8_t) 2, (uint8_t) 3, l16, l12, l20);
            if (l459.tag == 0u) {
                vader_array_t* _a33_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l13)
                t3 = vader_array_read_u8(_a33_slotarr, _a33_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l458 = ((int64_t) l459.payload.i);
            l460 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l460, l458);
        } else if (l19 == INT32_C(75)) {
            l462 = vader_vm$operand_b(l20);
            l463 = vader_vm$bits_of(l16, l12, l462);
            l464 = vader_core_bytecode$checked_neg((uint8_t) 3, l463);
            if (l464.tag == 0u) {
                vader_array_t* _a34_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l13)
                t3 = vader_array_read_u8(_a34_slotarr, _a34_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_neg_trap(((uint8_t) t3.payload.i), l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l461 = ((int64_t) l464.payload.i);
            l465 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l465, l461);
        } else if (l19 == INT32_C(76)) {
            l467 = vader_vm$checked_registers((uint8_t) 0, (uint8_t) 7, l16, l12, l20);
            if (l467.tag == 0u) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l13)
                t3 = vader_array_read_u8(_a35_slotarr, _a35_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l466 = ((int64_t) l467.payload.i);
            l468 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l468, l466);
        } else if (l19 == INT32_C(77)) {
            l470 = vader_vm$checked_registers((uint8_t) 1, (uint8_t) 7, l16, l12, l20);
            if (l470.tag == 0u) {
                vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l13)
                t3 = vader_array_read_u8(_a36_slotarr, _a36_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l469 = ((int64_t) l470.payload.i);
            l471 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l471, l469);
        } else if (l19 == INT32_C(78)) {
            l473 = vader_vm$checked_registers((uint8_t) 2, (uint8_t) 7, l16, l12, l20);
            if (l473.tag == 0u) {
                vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l13)
                t3 = vader_array_read_u8(_a37_slotarr, _a37_slotarr->offset + (size_t) l13, 340u);
                t1 = vader_vm$checked_trap(((uint8_t) t3.payload.i), (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l472 = ((int64_t) l473.payload.i);
            l474 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l474, l472);
        } else if (l19 == INT32_C(79)) {
            vader_array_t* _a38_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l13)
            t3 = vader_array_read_u8(_a38_slotarr, _a38_slotarr->offset + (size_t) l13, 340u);
            l475 = ((uint8_t) t3.payload.i);
            l477 = vader_vm$checked_registers((uint8_t) 0, l475, l16, l12, l20);
            if (l477.tag == 0u) {
                t1 = vader_vm$checked_trap(l475, (uint8_t) 0, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l476 = ((int64_t) l477.payload.i);
            l478 = vader_vm$operand_a(l20);
            vader_vm$set_integer(l16, l17, l12, l478, l475, l476);
        } else if (l19 == INT32_C(80)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l13)
            t3 = vader_array_read_u8(_a39_slotarr, _a39_slotarr->offset + (size_t) l13, 340u);
            l479 = ((uint8_t) t3.payload.i);
            l481 = vader_vm$checked_registers((uint8_t) 1, l479, l16, l12, l20);
            if (l481.tag == 0u) {
                t1 = vader_vm$checked_trap(l479, (uint8_t) 1, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l480 = ((int64_t) l481.payload.i);
            l482 = vader_vm$operand_a(l20);
            vader_vm$set_integer(l16, l17, l12, l482, l479, l480);
        } else if (l19 == INT32_C(81)) {
            vader_array_t* _a40_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l13)
            t3 = vader_array_read_u8(_a40_slotarr, _a40_slotarr->offset + (size_t) l13, 340u);
            l483 = ((uint8_t) t3.payload.i);
            l485 = vader_vm$checked_registers((uint8_t) 2, l483, l16, l12, l20);
            if (l485.tag == 0u) {
                t1 = vader_vm$checked_trap(l483, (uint8_t) 2, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l484 = ((int64_t) l485.payload.i);
            l486 = vader_vm$operand_a(l20);
            vader_vm$set_integer(l16, l17, l12, l486, l483, l484);
        } else if (l19 == INT32_C(82)) {
            vader_array_t* _a41_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_kinds);
            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l13)
            t3 = vader_array_read_u8(_a41_slotarr, _a41_slotarr->offset + (size_t) l13, 340u);
            l487 = ((uint8_t) t3.payload.i);
            l489 = vader_vm$operand_b(l20);
            l490 = vader_vm$bits_of(l16, l12, l489);
            l491 = vader_core_bytecode$checked_neg(l487, l490);
            if (l491.tag == 0u) {
                t1 = vader_vm$checked_neg_trap(l487, l8, l13);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l488 = ((int64_t) l491.payload.i);
            l492 = vader_vm$operand_a(l20);
            vader_vm$set_integer(l16, l17, l12, l492, l487, l488);
        } else if (l19 == INT32_C(83)) {
            l493 = vader_vm$operand_a(l20);
            l494 = vader_vm$operand_b(l20);
            l495 = vader_vm$i32_of(l16, l12, l494);
            vader_vm$set_i32(l16, l17, l12, l493, l495);
        } else if (l19 == INT32_C(84)) {
            l496 = vader_vm$operand_a(l20);
            l497 = vader_vm$operand_b(l20);
            l498 = vader_vm$bits_of(l16, l12, l497);
            vader_vm$set_i64(l16, l17, l12, l496, l498);
        } else if (l19 == INT32_C(85)) {
            l499 = vader_vm$operand_b(l20);
            l500 = vader_vm$zero_extended(l16, l17, l12, l499);
            l501 = vader_vm$operand_a(l20);
            vader_vm$set_i64(l16, l17, l12, l501, l500);
        } else if (l19 == INT32_C(86)) {
            l502 = vader_vm$operand_a(l20);
            l503 = vader_vm$operand_b(l20);
            l504 = vader_vm$u32_of(l16, l12, l503);
            vader_vm$set_char_code(l16, l17, l12, l502, l504);
        } else {
            if (l19 == INT32_C(87)) {
                t2 = vader_vm$operand_a(l20);
                l13 = ((int64_t) (int32_t) t2);
                continue;
            }
            if (l19 == INT32_C(88)) {
                t2 = vader_vm$operand_b(l20);
                l505 = ((int64_t) (int32_t) t2);
                l10 = vader_chk_add(i64, l10, l505);
                if ((l10 > l9)) {
                    t1 = vader_vm$budget_trap(l9);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = vader_vm$operand_a(l20);
                l13 = ((int64_t) (int32_t) t2);
                continue;
            }
            if (l19 == INT32_C(89)) {
                l506 = vader_vm$operand_b(l20);
                t6 = vader_vm$bits_of(l16, l12, l506);
                if (t6 == INT64_C(0)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(90)) {
                l507 = vader_vm$operand_b(l20);
                t6 = vader_vm$bits_of(l16, l12, l507);
                if (t6 != INT64_C(0)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(91)) {
                l508 = vader_vm$operand_b(l20);
                l509 = vader_vm$i32_of(l16, l12, l508);
                l510 = vader_vm$operand_c(l20);
                l511 = vader_vm$i32_of(l16, l12, l510);
                if (l509 == l511) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(92)) {
                l512 = vader_vm$operand_b(l20);
                l513 = vader_vm$i32_of(l16, l12, l512);
                l514 = vader_vm$operand_c(l20);
                l515 = vader_vm$i32_of(l16, l12, l514);
                if (l513 != l515) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(93)) {
                l516 = vader_vm$operand_b(l20);
                l517 = vader_vm$i32_of(l16, l12, l516);
                l518 = vader_vm$operand_c(l20);
                l519 = vader_vm$i32_of(l16, l12, l518);
                if ((l517 < l519)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(94)) {
                l520 = vader_vm$operand_b(l20);
                l521 = vader_vm$i32_of(l16, l12, l520);
                l522 = vader_vm$operand_c(l20);
                l523 = vader_vm$i32_of(l16, l12, l522);
                if ((l521 <= l523)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(97)) {
                l524 = vader_vm$operand_b(l20);
                l525 = vader_vm$bits_of(l16, l12, l524);
                l526 = vader_vm$operand_c(l20);
                l527 = vader_vm$bits_of(l16, l12, l526);
                if (l525 == l527) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(98)) {
                l528 = vader_vm$operand_b(l20);
                l529 = vader_vm$bits_of(l16, l12, l528);
                l530 = vader_vm$operand_c(l20);
                l531 = vader_vm$bits_of(l16, l12, l530);
                if (l529 != l531) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(99)) {
                l532 = vader_vm$operand_b(l20);
                l533 = vader_vm$bits_of(l16, l12, l532);
                l534 = vader_vm$operand_c(l20);
                l535 = vader_vm$bits_of(l16, l12, l534);
                if ((l533 < l535)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(100)) {
                l536 = vader_vm$operand_b(l20);
                l537 = vader_vm$bits_of(l16, l12, l536);
                l538 = vader_vm$operand_c(l20);
                l539 = vader_vm$bits_of(l16, l12, l538);
                if ((l537 <= l539)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(95)) {
                l540 = vader_vm$operand_b(l20);
                l541 = vader_vm$u32_of(l16, l12, l540);
                l542 = vader_vm$operand_c(l20);
                l543 = vader_vm$u32_of(l16, l12, l542);
                if ((l541 < l543)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(96)) {
                l544 = vader_vm$operand_b(l20);
                l545 = vader_vm$u32_of(l16, l12, l544);
                l546 = vader_vm$operand_c(l20);
                l547 = vader_vm$u32_of(l16, l12, l546);
                if ((l545 <= l547)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(101)) {
                l548 = vader_vm$operand_b(l20);
                l549 = vader_vm$u64_of(l16, l12, l548);
                l550 = vader_vm$operand_c(l20);
                l551 = vader_vm$u64_of(l16, l12, l550);
                if ((l549 < l551)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(102)) {
                l552 = vader_vm$operand_b(l20);
                l553 = vader_vm$u64_of(l16, l12, l552);
                l554 = vader_vm$operand_c(l20);
                l555 = vader_vm$u64_of(l16, l12, l554);
                if ((l553 <= l555)) {
                    t2 = vader_vm$operand_a(l20);
                    l13 = ((int64_t) (int32_t) t2);
                    continue;
                }
            } else if (l19 == INT32_C(109)) {
                t2 = vader_vm$operand_b(l20);
                l556 = ((int64_t) (int32_t) t2);
                l10 = vader_chk_add(i64, l10, l556);
                if ((l10 > l9)) {
                    t1 = vader_vm$budget_trap(l9);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(119)) {
                l557 = vader_vm$run_boxed(l0, l2, l8, l13, l12, l7);
                if (!(l557.tag == 0u)) {
                    t1 = l557.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(120)) {
                l558 = vader_vm$operand_a(l20);
                t2 = vader_vm$operand_b(l20);
                l559 = ((int64_t) (int32_t) t2);
                l560 = vader_chk_add(i64, l12, l559);
                vader_array_t* _a42_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l13)
                l561 = ((int32_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l13];
                l562 = vader_vm$call_import(l0, l2, l558, l560, l561, l7);
                if (!(l562.tag == 0u)) {
                    t1 = l562.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(121)) {
                t2 = vader_vm$operand_b(l20);
                l563 = ((int64_t) (int32_t) t2);
                l564 = vader_chk_add(i64, l12, l563);
                l566 = vader_vm$string_at(l2, l564);
                if (l566.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l564, l8, l13, 1673u, 2638u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l565 = l566.payload.s;
                l567 = vader_vm$operand_a(l20);
                t6 = vader_host_std_core$byte_len(l565);
                l568 = ((int32_t) (int64_t) t6);
                vader_vm$set_i32(l16, l17, l12, l567, l568);
            } else if (l19 == INT32_C(122)) {
                t2 = vader_vm$operand_b(l20);
                l569 = ((int64_t) (int32_t) t2);
                l570 = vader_chk_add(i64, l12, l569);
                l572 = vader_vm$string_at(l2, l570);
                if (l572.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l570, l8, l13, 1672u, 2638u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l571 = l572.payload.s;
                l573 = vader_vm$operand_c(l20);
                l574 = vader_vm$i32_of(l16, l12, l573);
                if ((l574 < INT32_C(0))) {
                    l575 = true;
                } else {
                    l576 = ((int64_t) (int32_t) l574);
                    l577 = vader_host_std_core$byte_len(l571);
                    l575 = (l576 >= l577);
                }
                if (l575) {
                    vader_struct_vader_vm$Trap_t* _a43_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a43_obj, 1446u);
                    _a43_obj->f_message = 1671u;
                    t1 = (void*) _a43_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l578 = vader_vm$operand_a(l20);
                l579 = ((int64_t) (int32_t) l574);
                t10 = vader_host_std_core$byte_at(l571, l579);
                l580 = ((int32_t) (uint8_t) t10);
                vader_vm$set_i32(l16, l17, l12, l578, l580);
            } else if (l19 == INT32_C(124)) {
                t2 = vader_vm$operand_b(l20);
                l581 = ((int64_t) (int32_t) t2);
                l582 = vader_chk_add(i64, l12, l581);
                l584 = vader_vm$string_at(l2, l582);
                if (l584.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l582, l8, l13, 2206u, 2638u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l583 = l584.payload.s;
                l585 = vader_vm$operand_a(l20);
                l586 = vader_host_std_core$is_ascii(l583);
                vader_vm$set_bool(l16, l17, l12, l585, l586);
            } else if (l19 == INT32_C(123)) {
                t2 = vader_vm$operand_a(l20);
                l587 = ((int64_t) (int32_t) t2);
                l588 = vader_chk_add(i64, l12, l587);
                l590 = vader_vm$string_at(l2, l588);
                if (l590.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l588, l8, l13, 1674u, 2638u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l589 = l590.payload.s;
                l591 = vader_vm$operand_b(l20);
                l592 = vader_vm$bits_of(l16, l12, l591);
                l593 = vader_vm$operand_c(l20);
                l594 = vader_vm$bits_of(l16, l12, l593);
                l595 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_refs;
                l596 = vader_host_std_core$byte_slice(l589, l592, l594);
                vader_array_t* _a44_slotarr = ((vader_array_t*) l595);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l588)
                vader_array_box_slots(_a44_slotarr->buf)[_a44_slotarr->offset + (size_t) l588] = vader_box_string(335u, l596);
                VADER_WRITE_BARRIER(_a44_slotarr->buf);
                vader_array_t* _a45_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l588)
                ((uint8_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l588] = (uint8_t) INT32_C(6);
            } else {
                if (l19 == INT32_C(125)) {
                    l597 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_texts;
                    l598 = vader_vm$operand_a(l20);
                    vader_array_t* _a46_slotarr = ((vader_array_t*) l597);
                    VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l598)
                    t3 = vader_array_box_slots(_a46_slotarr->buf)[_a46_slotarr->offset + (size_t) l598];
                    t0 = t3.payload.s;
                    vader_struct_vader_vm$Trap_t* _a47_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a47_obj, 1446u);
                    _a47_obj->f_message = t0;
                    t1 = (void*) _a47_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l19 == INT32_C(126)) {
                    t2 = vader_vm$operand_a(l20);
                    l599 = ((int64_t) (int32_t) t2);
                    l600 = vader_chk_add(i64, l12, l599);
                    l601 = vader_vm$register_value(l2, l600);
                    l602 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
                    l603 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers)->length;
                    if ((l602 < l603)) {
                        l604 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers;
                        l605 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
                        vader_array_t* _a48_slotarr = ((vader_array_t*) l604);
                        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l605)
                        vader_array_box_slots(_a48_slotarr->buf)[_a48_slotarr->offset + (size_t) l605] = l601;
                        VADER_WRITE_BARRIER(_a48_slotarr->buf);
                    } else {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers, l601);
                    }
                    t6 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
                    l606 = vader_chk_add(i64, t6, INT64_C(1));
                    ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count = l606;
                } else if (l19 == INT32_C(127)) {
                    l607 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_registers;
                    l608 = vader_chk_add(i64, l12, l607);
                    l609 = vader_vm$run_defers(l0, l1, l2, l8, l13, l608, l11, l7);
                    if (!(l609.tag == 0u)) {
                        t1 = l609.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else if (l19 == INT32_C(128)) {
                    l610 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_debug;
                    if (!(l610.tag == 0u)) {
                        l611 = l610.payload.obj;
                        vader_vm$stop_at_line(l0, l2, l611, l8, l13, l11);
                    }
                } else if (l19 == INT32_C(110)) {
                    t2 = vader_vm$operand_a(l20);
                    l612 = ((int64_t) (int32_t) t2);
                    l613 = vader_chk_add(i64, l12, l612);
                    l614 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_values;
                    l615 = vader_vm$operand_b(l20);
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
                    t2 = vader_vm$operand_b(l20);
                    l617 = ((int64_t) (int32_t) t2);
                    l618 = vader_chk_add(i64, l12, l617);
                    vader_array_t* _a52_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l618)
                    l619 = vader_array_box_slots(_a52_slotarr->buf)[_a52_slotarr->offset + (size_t) l618];
                    l620 = vader_vm$operand_c(l20);
                    if (l619.tag == 1443u) {
                        l621 = (l620 >= INT32_C(0));
                    } else {
                        l621 = false;
                    }
                    if (l621) {
                        l623 = ((int64_t) (int32_t) l620);
                        t1 = l619.payload.obj;
                        l624 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields)->length;
                        l622 = (l623 < l624);
                    } else {
                        l622 = false;
                    }
                    if (l622) {
                        t2 = vader_vm$operand_a(l20);
                        l625 = ((int64_t) (int32_t) t2);
                        l626 = vader_chk_add(i64, l12, l625);
                        t1 = l619.payload.obj;
                        vader_array_t* _a53_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields);
                        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l620)
                        l627 = vader_array_box_slots(_a53_slotarr->buf)[_a53_slotarr->offset + (size_t) l620];
                        vader_vm$set_register(l2, l626, l627);
                    } else {
                        vader_array_t* _a54_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                        VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a54_slotarr, l13)
                        l628 = ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l13];
                        l629 = vader_vm$read_struct_field(l619, l620, l628, 2661u);
                        if (l629.tag == 1446u) {
                            t1 = l629.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    }
                } else if (l19 == INT32_C(112)) {
                    l630 = vader_vm$operand_a(l20);
                    l631 = vader_vm$operand_b(l20);
                    l632 = vader_vm$operand_c(l20);
                    l633 = vader_vm$set_field(l2, l12, l630, l631, l632, l8, l13);
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
                        l635 = vader_vm$operand_a(l20);
                        l636 = vader_vm$operand_b(l20);
                        l637 = vader_vm$operand_c(l20);
                        t11 = vader_vm$try_get_element(l2, l12, l635, l636, l637);
                        if (!(t11)) {
                            l638 = vader_vm$operand_b(l20);
                            l639 = vader_vm$operand_c(l20);
                            t1 = vader_vm$element_trap(l2, l12, l638, l639, l8, l13, l19);
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    } else {
                        if (l19 == INT32_C(114)) {
                            l640 = true;
                        } else {
                            l640 = l19 == INT32_C(116);
                        }
                        if (l640) {
                            l641 = vader_vm$operand_a(l20);
                            l642 = vader_vm$operand_b(l20);
                            l643 = vader_vm$operand_c(l20);
                            t11 = vader_vm$try_set_element(l2, l12, l641, l642, l643);
                            if (!(t11)) {
                                l644 = vader_vm$operand_a(l20);
                                l645 = vader_vm$operand_b(l20);
                                l646 = vader_vm$operand_c(l20);
                                l647 = vader_vm$set_element(l2, l12, l644, l645, l646, l8, l13, l19);
                                if (!(l647.tag == 0u)) {
                                    t1 = l647.payload.obj;
                                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                            }
                        } else if (l19 == INT32_C(117)) {
                            t2 = vader_vm$operand_b(l20);
                            l648 = ((int64_t) (int32_t) t2);
                            l649 = vader_chk_add(i64, l12, l648);
                            l651 = vader_vm$array_at(l2, l649);
                            if (l651.tag == 0u) {
                                t1 = vader_vm$receiver_trap(l2, l649, l8, l13, 1571u, 1556u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l650 = l651.payload.obj;
                            l652 = vader_vm$operand_a(l20);
                            t6 = ((vader_struct_vader_vm$ArrayVal_t*) l650)->f_length;
                            l653 = ((int32_t) (int64_t) t6);
                            vader_vm$set_i32(l16, l17, l12, l652, l653);
                        } else if (l19 == INT32_C(118)) {
                            t2 = vader_vm$operand_a(l20);
                            l654 = ((int64_t) (int32_t) t2);
                            l655 = vader_chk_add(i64, l12, l654);
                            l657 = vader_vm$array_at(l2, l655);
                            if (l657.tag == 0u) {
                                t1 = vader_vm$receiver_trap(l2, l655, l8, l13, 1574u, 1556u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l656 = l657.payload.obj;
                            if (!(((vader_struct_vader_vm$ArrayVal_t*) l656)->f_raw.tag == 0u)) {
                                l658 = true;
                            } else {
                                l658 = vader_vm$is_array_view(l656);
                            }
                            if (l658) {
                                vader_vm$detach_array_view(l656);
                            }
                            l659 = ((vader_struct_vader_vm$ArrayVal_t*) l656)->f_elements;
                            t2 = vader_vm$operand_b(l20);
                            l660 = ((int64_t) (int32_t) t2);
                            l661 = vader_chk_add(i64, l12, l660);
                            l662 = vader_vm$register_value(l2, l661);
                            vader_array_push((vader_array_t*) l659, l662);
                            t6 = ((vader_struct_vader_vm$ArrayVal_t*) l656)->f_length;
                            l663 = vader_chk_add(i64, t6, INT64_C(1));
                            ((vader_struct_vader_vm$ArrayVal_t*) l656)->f_length = l663;
                        } else if (l19 == INT32_C(106)) {
                            t2 = vader_vm$operand_a(l20);
                            l664 = ((int64_t) (int32_t) t2);
                            l665 = vader_chk_add(i64, l12, l664);
                            l666 = vader_vm$operand_b(l20);
                            vader_vm$narrow_register(l2, l665, l666);
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
                                t2 = vader_vm$operand_b(l20);
                                l669 = ((int64_t) (int32_t) t2);
                                l670 = vader_chk_add(i64, l12, l669);
                                l671 = vader_vm$operand_a(l20);
                                if (l19 == INT32_C(104)) {
                                    t2 = vader_vm$operand_c(l20);
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
                                    t3 = vader_array_read_u8(_a56_slotarr, _a56_slotarr->offset + (size_t) l675, 340u);
                                    if (((int32_t) t3.payload.i) == INT32_C(6)) {
                                        l676 = l674.tag == 1422u;
                                    } else {
                                        l676 = false;
                                    }
                                    if (!(l676)) {
                                        vader_array_t* _a57_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l13)
                                        l694 = ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l13];
                                        t1 = vader_vm$indirect_call_trap(l1, l2, l670, l672, l694);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    t1 = l674.payload.obj;
                                    l677 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
                                    t1 = l674.payload.obj;
                                    l678 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_env;
                                    if (l678.tag == 0u) {
                                        l679 = l672;
                                    } else {
                                        l679 = vader_chk_add(i64, l672, INT64_C(1));
                                    }
                                    if ((l677 >= INT32_C(0))) {
                                        l681 = ((int64_t) (int32_t) l677);
                                        l682 = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions)->length;
                                        l680 = (l681 < l682);
                                    } else {
                                        l680 = false;
                                    }
                                    if (l680) {
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l677)
                                        t1 = vader_array_ref_load_obj(_a58_slotarr->buf, _a58_slotarr->offset + (size_t) l677);
                                        t6 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_params;
                                        l683 = t6 == l679;
                                    } else {
                                        l683 = false;
                                    }
                                    if (!(l683)) {
                                        vader_array_t* _a59_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l13)
                                        l693 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l13];
                                        t1 = vader_vm$indirect_call_trap(l1, l2, l670, l672, l693);
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
                                            t3 = vader_array_read_u8(_a61_slotarr, _a61_slotarr->offset + (size_t) l688, 340u);
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
                                        vader_vm$set_register(l2, l670, l692);
                                    }
                                    l671 = l677;
                                } else if (l19 == INT32_C(105)) {
                                    l695 = ((int64_t) (int32_t) l671);
                                    t2 = vader_vm$operand_c(l20);
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
                                    t3 = vader_array_read_u8(_a64_slotarr, _a64_slotarr->offset + (size_t) l697, 340u);
                                    if (((int32_t) t3.payload.i) != INT32_C(6)) {
                                        l699 = INT32_C(-1);
                                    } else if (l698.tag == 1443u) {
                                        t1 = l698.payload.obj;
                                        l699 = ((vader_struct_vader_vm$StructVal_t*) t1)->f_type_id;
                                    } else if (l698.tag == 1418u) {
                                        t1 = l698.payload.obj;
                                        l699 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_type_id;
                                    } else {
                                        l699 = INT32_C(-1);
                                    }
                                    if ((l699 < INT32_C(0))) {
                                        l700 = INT32_C(-1);
                                    } else {
                                        vader_array_t* _a65_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_virtual_rows);
                                        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l695)
                                        l700 = ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l695];
                                    }
                                    l701 = vader_vm$lookup_vtable_row(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_vtables, l700, l699);
                                    if ((l701 >= INT32_C(0))) {
                                        l703 = ((int64_t) (int32_t) l701);
                                        l704 = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions)->length;
                                        l702 = (l703 < l704);
                                    } else {
                                        l702 = false;
                                    }
                                    if (l702) {
                                        vader_array_t* _a66_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l701)
                                        t1 = vader_array_ref_load_obj(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l701);
                                        t6 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_params;
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
                                                t3 = vader_array_read_u8(_a68_slotarr, _a68_slotarr->offset + (size_t) l709, 340u);
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
                                        l713 = vader_vm$resolve_virtual(l0, l2, l8, l13, l670, l7);
                                        if (l713.tag == 1446u) {
                                            t1 = l713.payload.obj;
                                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        l671 = ((int32_t) l713.payload.i);
                                    }
                                }
                                if ((l671 >= INT32_C(0))) {
                                    vader_array_t* _a72_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                    VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l671)
                                    l714 = vader_array_ref_load_obj(_a72_slotarr->buf, _a72_slotarr->offset + (size_t) l671);
                                    l10 = vader_chk_add(i64, l10, INT64_C(1));
                                    l715 = ((int64_t) 1024);
                                    if ((l11 >= l715)) {
                                        t0 = ((vader_struct_vader_vm$RegFunction_t*) l714)->f_name;
                                        t1 = vader_vm$overflow_trap(t0);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    l716 = ((vader_array_t*) l16)->length;
                                    l717 = ((vader_struct_vader_vm$RegFunction_t*) l714)->f_registers;
                                    l718 = vader_chk_add(i64, l670, l717);
                                    if ((l716 < l718)) {
                                        l719 = ((vader_struct_vader_vm$RegFunction_t*) l714)->f_registers;
                                        l720 = vader_chk_add(i64, l670, l719);
                                        vader_vm$reserve_registers(l2, l720);
                                    }
                                    l721 = ((vader_struct_vader_vm$RegFunction_t*) l714)->f_params;
                                    l722 = vader_chk_add(i64, l670, l721);
                                    l723 = ((vader_struct_vader_vm$RegFunction_t*) l714)->f_slots;
                                    l724 = vader_chk_add(i64, l670, l723);
                                    while ((l722 < l724)) {
                                        vader_array_t* _a73_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l722)
                                        ((uint8_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l722] = (uint8_t) INT32_C(5);
                                        l722 = (l722 + INT64_C(1));
                                    }
                                    l725 = ((vader_struct_vader_vm$RegFunction_t*) l714)->f_slots;
                                    l726 = vader_chk_add(i64, l670, l725);
                                    l727 = INT64_C(0);
                                    l728 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l714)->f_consts)->length;
                                    while ((l727 < l728)) {
                                        l729 = vader_chk_add(i64, l726, l727);
                                        vader_array_t* _a74_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l714)->f_consts);
                                        VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l727)
                                        l730 = ((int64_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l727];
                                        vader_array_t* _a75_slotarr = ((vader_array_t*) l16);
                                        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a75_slotarr, l729)
                                        ((int64_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l729] = (int64_t) l730;
                                        l731 = vader_chk_add(i64, l726, l727);
                                        vader_array_t* _a76_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l714)->f_const_tags);
                                        VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l727)
                                        t3 = vader_array_read_u8(_a76_slotarr, _a76_slotarr->offset + (size_t) l727, 340u);
                                        l732 = ((uint8_t) t3.payload.i);
                                        vader_array_t* _a77_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a77_slotarr, l731)
                                        ((uint8_t*) _a77_slotarr->buf->slots)[_a77_slotarr->offset + (size_t) l731] = (uint8_t) (int32_t) (uint8_t) l732;
                                        l727 = (l727 + INT64_C(1));
                                    }
                                    l733 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code)->length;
                                    if ((l11 < l733)) {
                                        vader_array_t* _a78_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code);
                                        VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a78_slotarr, l11)
                                        vader_array_ref_store(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l11, l714);
                                        VADER_WRITE_BARRIER(_a78_slotarr->buf);
                                        vader_array_t* _a79_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base);
                                        VADER_ARRAY_RESOLVE_BUF(_a79_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a79_slotarr, l11)
                                        ((int64_t*) _a79_slotarr->buf->slots)[_a79_slotarr->offset + (size_t) l11] = (int64_t) l670;
                                        l734 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return;
                                        l735 = vader_chk_add(i64, l13, INT64_C(1));
                                        vader_array_t* _a80_slotarr = ((vader_array_t*) l734);
                                        VADER_ARRAY_RESOLVE_BUF(_a80_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a80_slotarr, l11)
                                        ((int64_t*) _a80_slotarr->buf->slots)[_a80_slotarr->offset + (size_t) l11] = (int64_t) l735;
                                    } else {
                                        l736 = vader_chk_add(i64, l13, INT64_C(1));
                                        vader_vm$grow_frame_records(l2, l714, l670, l736);
                                    }
                                    l11 = vader_chk_add(i64, l11, INT64_C(1));
                                    l12 = l670;
                                    l8 = l714;
                                    l14 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_ops;
                                    l15 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_words;
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
                                l739 = vader_vm$operand_a(l20);
                                if (l738) {
                                    l740 = INT64_C(0);
                                    t2 = vader_vm$operand_b(l20);
                                    l741 = ((int64_t) (int32_t) t2);
                                    while ((l740 < l741)) {
                                        l742 = vader_chk_add(i64, l12, l740);
                                        l743 = ((int64_t) (int32_t) l739);
                                        t6 = vader_chk_add(i64, l12, l743);
                                        l744 = vader_chk_add(i64, t6, l740);
                                        vader_vm$move_register(l2, l742, l744);
                                        l740 = (l740 + INT64_C(1));
                                    }
                                } else if ((l739 >= INT32_C(0))) {
                                    l745 = ((int64_t) (int32_t) l739);
                                    l746 = vader_chk_add(i64, l12, l745);
                                    vader_vm$move_register(l2, l12, l746);
                                }
                                l11 = vader_chk_sub(i64, l11, INT64_C(1));
                                if (l11 == l5) {
                                    if (l738) {
                                        if (l5 == INT64_C(0)) {
                                            vader_struct_vader_vm$Trap_t* _a81_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                                            vader_obj_header_init(_a81_obj, 1446u);
                                            _a81_obj->f_message = 2524u;
                                            t1 = (void*) _a81_obj;
                                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                                    }
                                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                                }
                                vader_array_t* _a82_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return);
                                VADER_ARRAY_RESOLVE_BUF(_a82_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a82_slotarr, l11)
                                l13 = ((int64_t*) _a82_slotarr->buf->slots)[_a82_slotarr->offset + (size_t) l11];
                                l747 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base;
                                l748 = vader_chk_sub(i64, l11, INT64_C(1));
                                vader_array_t* _a83_slotarr = ((vader_array_t*) l747);
                                VADER_ARRAY_RESOLVE_BUF(_a83_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a83_slotarr, l748)
                                l12 = ((int64_t*) _a83_slotarr->buf->slots)[_a83_slotarr->offset + (size_t) l748];
                                l749 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code;
                                l750 = vader_chk_sub(i64, l11, INT64_C(1));
                                vader_array_t* _a84_slotarr = ((vader_array_t*) l749);
                                VADER_ARRAY_RESOLVE_BUF(_a84_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a84_slotarr, l750)
                                l8 = vader_array_ref_load_obj(_a84_slotarr->buf, _a84_slotarr->offset + (size_t) l750);
                                l14 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_ops;
                                l15 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_words;
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

static vader_box_t vader_vm$reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6) {
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
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[5] = { &l4, &l6, &l9, &l10, &t2 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l3, &l7, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l8 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
    l9 = vader_vm$build_main_args(l7, l3, l8);
    if (l9.tag == 1446u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 0u) {
        l10 = vader_box_obj(0u, NULL);
    } else {
        t0 = l6.payload.obj;
        vader_struct_vader_vm$DebugSession_t* _a1_obj = (vader_struct_vader_vm$DebugSession_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$DebugSession_t));
        vader_obj_header_init(_a1_obj, 1421u);
        _a1_obj->f_controller = t0;
        _a1_obj->f_last_line = INT32_C(-1);
        _a1_obj->f_step_mode = (uint8_t) 0;
        _a1_obj->f_step_depth = INT32_C(0);
        t0 = (void*) _a1_obj;
        l10 = vader_ref_box(t0);
    }
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 8u, 339u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(25u, 0u, 1u, 340u);
    l12 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l13 = (void*) _a4_arr;
    l14 = vader_vm$new_run_host();
    l15 = vader_vm$scratch_frame();
    vader_array_t* _a5_arr = vader_array_new(229u, 0u, 13u, 1436u);
    l16 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 8u, 339u);
    l17 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 8u, 339u);
    l18 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l19 = (void*) _a8_arr;
    vader_struct_vader_vm$NullVal_t* _a9_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
    vader_obj_header_init(_a9_obj, 1429u);
    l20 = (void*) _a9_obj;
    vader_struct_vader_vm$RegMachine_t* _a10_obj = (vader_struct_vader_vm$RegMachine_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegMachine_t));
    vader_obj_header_init(_a10_obj, 1437u);
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
    vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l2);
    l21 = ((vader_struct_vader_vm$RegFunction_t*) t0)->f_registers;
    vader_vm$reserve_registers(l11, l21);
    l21 = INT64_C(0);
    t0 = l9.payload.obj;
    l22 = ((vader_array_t*) t0)->length;
    while ((l21 < l22)) {
        t0 = l9.payload.obj;
        vader_array_t* _a12_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l21)
        l10 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l21];
        vader_vm$set_register(l11, l21, l10);
        l21 = (l21 + INT64_C(1));
    }
    l9 = vader_vm$reg_call(l0, l1, l11, l2, INT64_C(0), INT64_C(0), INT64_C(0), l5);
    if (!(l9.tag == 1446u)) {
        t1 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature);
        l23 = t1 == INT64_C(1);
        t2 = vader_vm$finish_run(l11, l23, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l9.payload.obj;
    t3 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
    t4 = vader_vm$is_overflow_trap_message(t3);
    if (!(t4)) {
        vader_vm$unwind(l0, l1, l11, l5);
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_vm$frame_names(l11);
    vader_vm$unwind(l0, l1, l11, l5);
    t0 = l9.payload.obj;
    vader_struct_vader_vm$StackOverflow_t* _a13_obj = (vader_struct_vader_vm$StackOverflow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackOverflow_t));
    vader_obj_header_init(_a13_obj, 1442u);
    _a13_obj->f_trap = t0;
    _a13_obj->f_frames = l7;
    t0 = (void*) _a13_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$register_value(void* l0, int64_t l1) {
    uint8_t l2;
    vader_box_t l3;
    uint32_t l4;
    bool l5;
    vader_box_t t0;
    int64_t t1;
    int32_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        return l3;
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(338u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(339u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(345u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(333u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
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
        l3 = vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l4));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_null_value;
    }
    return l3;
}

static vader_box_t vader_vm$relocated(vader_box_t l0, int32_t l1) {
    int32_t l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_bytecode$slot_touched(l0);
    if ((l2 < INT32_C(0))) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_chk_add(i32, l2, l1);
    t0 = vader_core_bytecode$with_remapped_slot(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$reserve_registers(void* l0, int64_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits)->length;
        if ((t0 < l1)) {
            vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits, INT64_C(0));
            vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags, INT32_C(5));
            l2 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
            vader_struct_vader_vm$NullVal_t* _a0_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
            vader_obj_header_init(_a0_obj, 1429u);
            l3 = (void*) _a0_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm$reserve_stack(void* l0, int64_t l1) {
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload)->length;
        if ((t0 < l1)) {
            vader_vm$stack_grow(l0);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm$reset_stack(void* l0, int64_t l1) {
    int64_t l2;
    int32_t l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_clear((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
    l2 = INT64_C(0);
    while ((l2 < l1)) {
        l3 = vader_vm$canonical(l0, l2);
        vader_vm$push_register(l0, l3);
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$resolve_virtual(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5) {
    int64_t l6, l7, l15, l16;
    void* l8 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    int32_t l9, l10, l12;
    vader_box_t l11 = vader_box_null(), l23 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    bool l18;
    uint8_t l22;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[2] = { &l11, &l23 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l8, &l17, &l19, &l20, &l21, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l13, &l14, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    t0 = vader_vm$operand_a(l6);
    l7 = ((int64_t) (int32_t) t0);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_virtuals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_virtual_rows);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    t0 = vader_vm$operand_c(l6);
    l6 = ((int64_t) (int32_t) t0);
    t1 = vader_chk_add(i64, l4, l6);
    l7 = vader_chk_sub(i64, t1, INT64_C(1));
    l11 = vader_vm$register_value(l1, l7);
    l12 = vader_vm$receiver_type_id_of(l0, l11);
    if ((l12 < INT32_C(0))) {
        l14 = vader_vm$describe_value_tag(l11);
        l13 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l8)->f_vtable_key;
        l15 = vader_host_std_core$byte_len(l13);
        l16 = vader_host_std_core$byte_len(l14);
        l15 = (l15 + l16);
        l17 = (void*) vader_buffer_new((size_t) (INT64_C(73) + l15));
        l15 = INT64_C(0);
        l15 = std_core$write_string_at(l17, l15, 3004u);
        l15 = std_core$write_string_at(l17, l15, l13);
        l15 = std_core$write_string_at(l17, l15, 293u);
        l15 = std_core$write_string_at(l17, l15, l14);
        l15 = std_core$write_string_at(l17, l15, 136u);
        l16 = ((int64_t) (int32_t) l10);
        l15 = std_core$write_int(l17, l15, l16);
        t2 = std_core$finish_buffer(l17, l15);
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 1446u);
        _a4_obj->f_message = t2;
        t3 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm$lookup_vtable_row(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_vtables, l9, l12);
    while ((l7 > l4)) {
        l15 = vader_chk_sub(i64, l7, INT64_C(1));
        vader_vm$move_register(l1, l7, l15);
        l7 = vader_chk_sub(i64, l7, INT64_C(1));
    }
    vader_vm$set_register(l1, l4, l11);
    if ((l9 >= INT32_C(0))) {
        l17 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
        t4 = vader_vm$is_fn_index_out_of_range(l9, l17);
        if (t4) {
            l13 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l8)->f_vtable_key;
            l13 = concat_3(3004u, l13, 288u);
            t3 = vader_vm$fn_index_trap(l9, l10, l13);
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l17 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l17)->f_signature)->f_params)->length;
        if (!(t1 != l6)) {
            { vader_box_t __vret = vader_box_i32(338u, l9); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l17)->f_signature)->f_params)->length;
        l13 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l8)->f_vtable_key;
        l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l17)->f_name;
        l15 = vader_host_std_core$byte_len(l13);
        l16 = vader_host_std_core$byte_len(l14);
        l15 = (l15 + l16);
        l17 = (void*) vader_buffer_new((size_t) (INT64_C(134) + l15));
        l15 = INT64_C(0);
        l15 = std_core$write_string_at(l17, l15, 3004u);
        l15 = std_core$write_string_at(l17, l15, l13);
        l15 = std_core$write_string_at(l17, l15, 291u);
        l15 = std_core$write_string_at(l17, l15, l14);
        l15 = std_core$write_string_at(l17, l15, 296u);
        l15 = std_core$write_int(l17, l15, l7);
        l15 = std_core$write_string_at(l17, l15, 197u);
        l15 = std_core$write_int(l17, l15, l6);
        l15 = std_core$write_string_at(l17, l15, 96u);
        l7 = ((int64_t) (int32_t) l10);
        l15 = std_core$write_int(l17, l15, l7);
        t2 = std_core$finish_buffer(l17, l15);
        vader_struct_vader_vm$Trap_t* _a6_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a6_obj, 1446u);
        _a6_obj->f_message = t2;
        t3 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l13 = vader_vm$primitive_kind_at(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types, l12);
    l14 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l8)->f_vtable_key;
    l14 = vader_vm$intrinsic_host_mangle(l13, l14);
    if (l13 == 0u) {
        l18 = true;
    } else {
        l18 = l14 == 0u;
    }
    if (l18) {
        l13 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l8)->f_vtable_key;
        l7 = vader_host_std_core$byte_len(l13);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(82) + l7));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l8, l7, 3004u);
        l7 = std_core$write_string_at(l8, l7, l13);
        l7 = std_core$write_string_at(l8, l7, 292u);
        l15 = ((int64_t) (int32_t) l12);
        l7 = std_core$write_int(l8, l7, l15);
        l7 = std_core$write_string_at(l8, l7, 96u);
        l15 = ((int64_t) (int32_t) l10);
        l7 = std_core$write_int(l8, l7, l15);
        t2 = std_core$finish_buffer(l8, l7);
        vader_struct_vader_vm$Trap_t* _a7_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a7_obj, 1446u);
        _a7_obj->f_message = t2;
        t3 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_vm$primitive_impl_import(l14, l6);
    vader_array_t* _a8_arr = vader_array_new(269u, 0u, 0u, 2153u);
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
        l11 = vader_vm$register_value(l1, l15);
        vader_array_push((vader_array_t*) l17, l11);
        l7 = (l7 + INT64_C(1));
    }
    l19 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_gc_state;
    l20 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_sched_state;
    l9 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
    l12 = ((vader_struct_vader_vm$VmState_t*) l0)->f_u8_array_type_id;
    l21 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l11 = vader_vm$debug_controller(l1);
    l22 = vader_core_bytecode$intrinsic_id_for(l14);
    l11 = vader_vm$dispatch_import(l8, l17, INT64_C(0), l19, l20, l10, l9, l12, l21, l5, l11, l22, INT64_C(0));
    if (!(l11.tag == 1446u)) {
        t3 = l11.payload.obj;
        l23 = ((vader_struct_vader_vm$HostOk_t*) t3)->f_value;
        vader_vm$set_register(l1, l4, l23);
        { vader_box_t __vret = vader_box_i32(338u, INT32_C(-1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l11.payload.obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$return_many(void* l0, int64_t l1, void* l2) {
    int64_t l3, l4, l5, l7;
    int32_t l6, l8;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_vm$flush(l0, l1);
    l3 = ((vader_array_t*) l2)->length;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack)->length;
    l4 = vader_chk_sub(i64, t0, l3);
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 340u);
        l6 = vader_vm$narrow_code(((uint8_t) t1.payload.i));
        if ((l6 >= INT32_C(0))) {
            l7 = vader_chk_add(i64, l4, l5);
            l8 = vader_vm$canonical(l0, l7);
            vader_vm$emit(l0, l1, INT32_C(106), l8, l6, INT32_C(0));
        }
        l5 = (l5 + INT64_C(1));
    }
    l6 = vader_vm$canonical(l0, l4);
    l8 = ((int32_t) (int64_t) l3);
    vader_vm$emit(l0, l1, INT32_C(108), l6, l8, INT32_C(0));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_vm$returns_void(void* l0, int32_t l1) {
    int64_t l2;
    vader_box_t l3;
    bool t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm$in_range(l1, l2);
    if (!(t0)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 743u) {
        t1 = l3.payload.obj;
        return ((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val == INT32_C(14);
    }
    return false;
}

static vader_box_t vader_vm$retyped_int(vader_box_t l0, int64_t l1) {
    uint32_t l2;
    bool l3;
    int32_t t0;
    if (l0.tag == 339u) {
        return vader_box_i64(339u, l1);
    }
    if (l0.tag == 333u) {
        return vader_box_bool(333u, l1 != INT64_C(0));
    }
    if (!(l0.tag == 334u)) {
        return vader_box_i32(338u, ((int32_t) (int64_t) l1));
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
            return vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l2));
        }
    } else {
        return vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l2));
    }
}

static vader_box_t vader_vm$run_boxed(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5) {
    int64_t l6, l7, l9, l10, l12, l15, l16, l19, l23;
    int32_t l8;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    uint8_t l20;
    vader_box_t l24 = vader_box_null();
    vader_string_t l25 = 0;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l24, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l11, &l13, &l14, &l17, &l18, &l21, &l22, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l25 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    t0 = vader_vm$operand_b(l6);
    l7 = ((int64_t) (int32_t) t0);
    l7 = vader_chk_add(i64, l4, l7);
    l8 = vader_vm$operand_c(l6);
    l9 = vader_vm$boxed_pops(l8);
    l10 = vader_vm$boxed_pushes(l8);
    l11 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_scratch;
    vader_vm$reserve_stack(l11, l9);
    l12 = INT64_C(0);
    while ((l12 < l9)) {
        l13 = ((vader_struct_vader_vm$Frame_t*) l11)->f_payload;
        l14 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_bits;
        l15 = vader_chk_add(i64, l7, l12);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l15)
        l16 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l15];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l12] = (int64_t) l16;
        l17 = ((vader_struct_vader_vm$Frame_t*) l11)->f_tag;
        l18 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_tags;
        l19 = vader_chk_add(i64, l7, l12);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l19)
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l19, 340u);
        l20 = ((uint8_t) t1.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12] = (uint8_t) (int32_t) (uint8_t) l20;
        l21 = ((vader_struct_vader_vm$Frame_t*) l11)->f_stack;
        l22 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_refs;
        l23 = vader_chk_add(i64, l7, l12);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l22);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l23)
        l24 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l23];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l21);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
        vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l12] = l24;
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        l12 = (l12 + INT64_C(1));
    }
    ((vader_struct_vader_vm$Frame_t*) l11)->f_sp = l9;
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
    l8 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3];
    ((vader_struct_vader_vm$Frame_t*) l11)->f_pc = l8;
    l13 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run;
    l14 = ((vader_struct_vader_vm$RegFunction_t*) l2)->f_boxed;
    l8 = vader_vm$operand_a(l6);
    vader_array_t* _a8_slotarr = ((vader_array_t*) l14);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
    l24 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
    l25 = ((vader_struct_vader_vm$RegFunction_t*) l2)->f_name;
    l24 = vader_vm$apply_boxed(l0, l13, l24, l11, l25, l5);
    if (l24.tag == 1446u) {
        t2 = l24.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = INT64_C(0);
    while ((l6 < l10)) {
        l13 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_bits;
        l9 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l11)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        l12 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6];
        vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
        ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9] = (int64_t) l12;
        l14 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_tags;
        l15 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l11)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
        t1 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l6, 340u);
        l20 = ((uint8_t) t1.payload.i);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l15)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l15] = (uint8_t) (int32_t) (uint8_t) l20;
        l17 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_refs;
        l16 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l11)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        l24 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l6];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l16)
        vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l16] = l24;
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$run_defers(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l3)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    l8 = vader_vm$operand_a(t0);
    if ((l8 <= INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l3)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
    l10 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    l11 = ((int64_t) (int32_t) l8);
    if ((l10 < l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(107));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, 1826u);
        l11 = ((int64_t) (int32_t) l8);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 376u);
        l11 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 331u);
        l11 = ((int64_t) (int32_t) l9);
        l10 = std_core$write_int(l12, l10, l11);
        t1 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 1446u);
        _a2_obj->f_message = t1;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    l11 = ((int64_t) (int32_t) l8);
    l10 = vader_chk_sub(i64, l10, l11);
    vader_array_t* _a3_arr = vader_array_new(221u, 0u, 13u, 1422u);
    l12 = (void*) _a3_arr;
    l11 = l10;
    l13 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    while ((l11 < l13)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l14 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l11];
        l15 = vader_vm$defer_thunk(l0, l14, l9, 1824u);
        if (l15.tag == 1446u) {
            t2 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = l15.payload.obj;
        vader_array_push_ref((vader_array_t*) l12, l16);
        l11 = (l11 + INT64_C(1));
    }
    ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count = l10;
    l10 = ((vader_array_t*) l12)->length;
    while ((l10 > INT64_C(0))) {
        l10 = vader_chk_sub(i64, l10, INT64_C(1));
        vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        l16 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l10);
        l11 = vader_chk_add(i64, l4, INT64_C(1));
        l14 = vader_vm$run_thunk(l0, l1, l2, l16, l5, l6, l11, l7);
        if (!(l14.tag == 0u)) {
            t2 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$run_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5) {
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
        l8 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions)->length;
        l6 = (l7 >= l8);
    }
    if (l6) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(46));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l9, l7, 2384u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l9, l7, l8);
        l7 = std_core$write_string_at(l9, l7, 323u);
        t0 = std_core$finish_buffer(l9, l7);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 0u) {
        l9 = ((vader_struct_vader_vm$VmState_t*) l0)->f_reg;
        t2 = vader_vm$reg_run(l0, l9, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_struct_vader_vm$VmState_t*) l0)->f_debuggable;
    if (!(t3)) {
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1446u);
        _a1_obj->f_message = 1441u;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_vm$VmState_t*) l0)->f_reg;
    t2 = vader_vm$reg_run(l0, l9, l1, l2, l3, l4, l5);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$run_for_value(void* l0, vader_string_t l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[4] = { &l0, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_vm$entry_named(l0, l1);
    if (l3.tag == 1446u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l4 = (void*) _a0_arr;
    t1 = vader_vm$zero_value();
    vader_array_t* _a1_arr = vader_array_new(269u, 1u, 0u, 2153u);
    vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = t1;
    l5 = (void*) _a1_arr;
    l6 = ((int32_t) l3.payload.i);
    l3 = vader_vm$run_entry(l0, l6, l4, vader_ref_box(l5), l2, vader_box_obj(0u, NULL));
    if (!((l3.tag == 1442u || l3.tag == 1446u))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        vader_struct_vader_vm$ValueOk_t* _a3_obj = (vader_struct_vader_vm$ValueOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ValueOk_t));
        vader_obj_header_init(_a3_obj, 1448u);
        _a3_obj->f_value = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$run_thunk(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
    int64_t l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l8 = vader_chk_add(i64, l4, INT64_C(1));
    vader_vm$reserve_registers(l2, l8);
    if (((vader_struct_vader_vm$FnVal_t*) l3)->f_env.tag == 0u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4] = (uint8_t) INT32_C(5);
        l10 = ((vader_struct_vader_vm$FnVal_t*) l3)->f_function_index;
        t0 = vader_vm$reg_call(l0, l1, l2, l10, l4, l5, l6, l7);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_vm$FnVal_t*) l3)->f_env;
    vader_vm$set_register(l2, l4, l9);
    l10 = ((vader_struct_vader_vm$FnVal_t*) l3)->f_function_index;
    t0 = vader_vm$reg_call(l0, l1, l2, l10, l4, l5, l6, l7);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$scalar_of(vader_box_t l0) {
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
    if (l0.tag == 805u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a0_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a0_obj, 1440u);
        _a0_obj->f_bits = ((int64_t) (int32_t) t1);
        _a0_obj->f_tag = (uint8_t) 0;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a1_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a1_obj, 1440u);
        _a1_obj->f_bits = t2;
        _a1_obj->f_tag = (uint8_t) 1;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 784u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a2_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a2_obj, 1440u);
        _a2_obj->f_bits = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t3 }).__vu);
        _a2_obj->f_tag = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 756u) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        if (t4) {
            l2 = INT64_C(1);
        } else {
            l2 = INT64_C(0);
        }
        vader_struct_vader_vm$Scalar_t* _a3_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a3_obj, 1440u);
        _a3_obj->f_bits = l2;
        _a3_obj->f_tag = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 771u) {
        t0 = l0.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a4_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a4_obj, 1440u);
        _a4_obj->f_bits = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        _a4_obj->f_tag = (uint8_t) 4;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 856u) {
        vader_struct_vader_vm$Scalar_t* _a5_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a5_obj, 1440u);
        _a5_obj->f_bits = INT64_C(0);
        _a5_obj->f_tag = (uint8_t) 5;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 872u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$scratch_frame(void) {
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
    l1 = std_core$filled__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(5);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l3 = (void*) _a3_arr;
    vader_struct_vader_vm$Frame_t* _a4_obj = (vader_struct_vader_vm$Frame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Frame_t));
    vader_obj_header_init(_a4_obj, 1423u);
    _a4_obj->f_stack = l1;
    _a4_obj->f_payload = l2;
    _a4_obj->f_tag = l3;
    _a4_obj->f_sp = INT64_C(0);
    _a4_obj->f_pc = INT32_C(0);
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serialise_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7) {
    vader_string_t l8 = 0;
    vader_string_t l14 = 0;
    vader_string_t l38 = 0;
    vader_string_t l39 = 0;
    int64_t l9, l11, l15, l16, l17, l19, l20, l21, l22, l27, l30, l31, l40, l41, l42;
    void* l10 = NULL;
    void* l18 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l26 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null(), l33 = vader_box_null(), l37 = vader_box_null();
    int32_t l25;
    double l32;
    bool l34, l35, l36;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[7] = { &l12, &l13, &l26, &l28, &l29, &l33, &l37 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l4, &l10, &l18, &l23, &l24, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l6, &l8, &l14, &l38, &l39, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        l8 = l6;
        l9 = vader_host_std_core$byte_len(l8);
        l10 = (void*) vader_buffer_new((size_t) (INT64_C(83) + l9));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l10, l9, 1947u);
        l9 = std_core$write_string_at(l10, l9, l8);
        l9 = std_core$write_string_at(l10, l9, 1064u);
        l11 = ((int64_t) (int32_t) l5);
        l9 = std_core$write_int(l10, l9, l11);
        l9 = std_core$write_string_at(l10, l9, 491u);
        l9 = std_core$write_int(l10, l9, INT64_C(16));
        t0 = std_core$finish_buffer(l10, l9);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1446u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_core_bytecode$c_struct_layout(l3, l4);
    l9 = INT64_C(0);
    l11 = ((vader_array_t*) l3)->length;
    while ((l9 < l11)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l12 = vader_core_bytecode$nested_mirror(t1, l4);
        if (l12.tag == 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l28 = vader_core_bytecode$c_field_width(t1, l4);
            if (l28.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l27 = ((int64_t) l28.payload.i);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l29 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l9];
            if ((l29.tag == 344u || l29.tag == 345u)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_offsets);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                l30 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9];
                l31 = vader_chk_add(i64, l1, l30);
                l32 = ((double) l29.payload.f);
                vader_vm$write_float(l0, l31, l32, l27);
                l9 = (l9 + INT64_C(1));
                continue;
            }
            if (l29.tag == 339u) {
                l34 = true;
            } else {
                l34 = l29.tag == 338u;
            }
            if (l34) {
                l35 = true;
            } else {
                l35 = l29.tag == 333u;
            }
            if (l35) {
                l36 = true;
            } else {
                l36 = l29.tag == 334u;
            }
            if (l36) {
                l33 = vader_vm$read_scalar_word(l29, l5, 0u);
            } else {
                l37 = l29;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
                l38 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
                l39 = concat_5(1947u, l6, 1090u, l38, 1035u);
                l33 = vader_vm$read_scalar_word(l37, l5, l39);
            }
            if (l33.tag == 1446u) {
                t1 = l33.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
            l40 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l9];
            l41 = vader_chk_add(i64, l1, l40);
            l42 = ((int64_t) l33.payload.i);
            vader_vm$write_little_endian(l0, l41, l42, l27);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
        l13 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l9];
        if (!(l13.tag == 1443u)) {
            l8 = l6;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
            l14 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
            l15 = vader_host_std_core$byte_len(l8);
            l16 = vader_host_std_core$byte_len(l14);
            l17 = (l15 + l16);
            l18 = (void*) vader_buffer_new((size_t) (INT64_C(91) + l17));
            l19 = INT64_C(0);
            l19 = std_core$write_string_at(l18, l19, 1947u);
            l19 = std_core$write_string_at(l18, l19, l8);
            l19 = std_core$write_string_at(l18, l19, 1064u);
            l20 = ((int64_t) (int32_t) l5);
            l19 = std_core$write_int(l18, l19, l20);
            l19 = std_core$write_string_at(l18, l19, 487u);
            l19 = std_core$write_string_at(l18, l19, l14);
            l19 = std_core$write_string_at(l18, l19, 1192u);
            t0 = std_core$finish_buffer(l18, l19);
            vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a9_obj, 1446u);
            _a9_obj->f_message = t0;
            t1 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
        l21 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9];
        l22 = vader_chk_add(i64, l1, l21);
        l23 = l13.payload.obj;
        t1 = l12.payload.obj;
        l24 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
        l25 = vader_chk_add(i32, l7, INT32_C(1));
        l26 = vader_vm$serialise_mirror(l0, l22, l23, l24, l4, l5, l6, l25);
        if (l26.tag == 1446u) {
            t1 = l26.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm$set_bool(void* l0, void* l1, int64_t l2, int32_t l3, bool l4) {
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

static void vader_vm$set_char_code(void* l0, void* l1, int64_t l2, int32_t l3, uint32_t l4) {
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

static vader_box_t vader_vm$set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6, int32_t l7) {
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
    l10 = vader_vm$array_at(l0, l8);
    if (l10.tag == 0u) {
        t0 = vader_vm$element_trap(l0, l1, l2, l3, l5, l6, l7);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
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
        l14 = ((vader_struct_vader_vm$ArrayVal_t*) l9)->f_length;
        l13 = (l8 >= l14);
    }
    if (!(l13)) {
        vader_vm$own_bytes(l9);
        l11 = ((vader_struct_vader_vm$ArrayVal_t*) l9)->f_elements;
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) l9)->f_offset;
        l14 = ((int64_t) (int32_t) l12);
        l8 = vader_chk_add(i64, l8, l14);
        l14 = ((int64_t) (int32_t) l4);
        l14 = vader_chk_add(i64, l1, l14);
        l10 = vader_vm$register_value(l0, l14);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8] = l10;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_vm$element_trap(l0, l1, l2, l3, l5, l6, l7);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$set_f64(void* l0, void* l1, int64_t l2, int32_t l3, double l4) {
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

static vader_box_t vader_vm$set_field(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, void* l5, int64_t l6) {
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
    l7 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
    l8 = ((int64_t) (int32_t) l2);
    l8 = vader_chk_add(i64, l1, l8);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    l9 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
    if (l9.tag == 1443u) {
        if ((l4 < INT32_C(0))) {
            l10 = true;
        } else {
            l8 = ((int64_t) (int32_t) l4);
            t0 = l9.payload.obj;
            l11 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields)->length;
            l10 = (l8 >= l11);
        }
        if (!(l10)) {
            t0 = l9.payload.obj;
            l13 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields;
            l12 = ((int64_t) (int32_t) l3);
            l14 = vader_chk_add(i64, l1, l12);
            l15 = vader_vm$register_value(l0, l14);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4] = l15;
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l9.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields)->length;
        l7 = (void*) vader_buffer_new((size_t) INT64_C(118));
        l11 = INT64_C(0);
        l11 = std_core$write_string_at(l7, l11, 2667u);
        l12 = ((int64_t) (int32_t) l4);
        l11 = std_core$write_int(l7, l11, l12);
        l11 = std_core$write_string_at(l7, l11, 193u);
        l11 = std_core$write_int(l7, l11, l8);
        l11 = std_core$write_string_at(l7, l11, 122u);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l5)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l8 = ((int64_t) (int32_t) t1);
        l11 = std_core$write_int(l7, l11, l8);
        t2 = std_core$finish_buffer(l7, l11);
        vader_struct_vader_vm$Trap_t* _a3_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a3_obj, 1446u);
        _a3_obj->f_message = t2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l5)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
    l16 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
    l9 = vader_vm$read_struct(l9, l16, 2669u);
    if (l9.tag == 1446u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_vm$set_i32(void* l0, void* l1, int64_t l2, int32_t l3, int32_t l4) {
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

static void vader_vm$set_i64(void* l0, void* l1, int64_t l2, int32_t l3, int64_t l4) {
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

static void vader_vm$set_integer(void* l0, void* l1, int64_t l2, int32_t l3, uint8_t l4, int64_t l5) {
    int32_t l6;
    bool t0;
    t0 = vader_core_bytecode$is_64_bit_int_val(l4);
    if (t0) {
        vader_vm$set_i64(l0, l1, l2, l3, l5);
        return;
    }
    l6 = ((int32_t) (int64_t) l5);
    vader_vm$set_i32(l0, l1, l2, l3, l6);
    return;
}

static void vader_vm$set_register(void* l0, int64_t l1, vader_box_t l2) {
    void* l3;
    int64_t l4;
    vader_box_t l5;
    int32_t t0;
    double t1;
    bool t2;
    uint32_t t3;
    if (l2.tag == 338u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        t0 = ((int32_t) l2.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(0);
        return;
    }
    if (l2.tag == 339u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        l4 = ((int64_t) l2.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(1);
    } else if ((l2.tag == 344u || l2.tag == 345u)) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        t1 = ((double) l2.payload.f);
        l4 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(2);
    } else if (l2.tag == 333u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
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
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(3);
    } else if (l2.tag == 334u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        t3 = ((uint32_t) l2.payload.i);
        l4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
        ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
        ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(4);
    } else if (l2.tag == 1429u) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l1)
        ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(5);
    } else {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
        l5 = l2;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l1)
        vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l1] = l5;
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l1)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l1] = (uint8_t) INT32_C(6);
    }
    return;
}

static bool vader_vm$skips_else(void* l0, int64_t l1) {
    bool l2;
    int64_t l3, l4;
    void* l5;
    vader_box_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (t0.tag == 840u) {
        l3 = vader_chk_add(i64, l1, INT64_C(1));
        l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body)->length;
        l2 = (l3 < l4);
    } else {
        l2 = false;
    }
    if (l2) {
        l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
        l3 = vader_chk_add(i64, l1, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        return t0.tag == 780u;
    }
    return false;
}

static bool vader_vm$slot_in_scope(void* l0, void* l1, int64_t l2, int32_t l3) {
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

static uint8_t vader_vm$slot_valtype(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l3 = ((int64_t) (int32_t) l1);
    if ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 340u);
        return ((uint8_t) t0.payload.i);
    }
    l2 = vader_chk_sub(i64, l3, l2);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    if (!((l2 < l3))) {
        return (uint8_t) 2;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    return ((vader_struct_vader_core_bytecode$BcLocal_t*) t1)->f_val;
}

static void vader_vm$stack_grow(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload, INT64_C(0));
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag, INT32_C(5));
    l1 = ((vader_struct_vader_vm$Frame_t*) l0)->f_stack;
    vader_struct_vader_vm$NullVal_t* _a0_obj = (vader_struct_vader_vm$NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$NullVal_t));
    vader_obj_header_init(_a0_obj, 1429u);
    l2 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$stack_i32(void* l0, int64_t l1, vader_string_t l2, vader_string_t l3) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    t1 = vader_vm$is_i32_tag(((uint8_t) t0.payload.i));
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = vader_box_i32(338u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$peek_val(l0, l1);
    l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = concat_3(l2, 14u, l3);
    l4 = vader_vm$read_i32(l4, l5, l6);
    if (l4.tag == 1446u) {
        t3 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((int32_t) l4.payload.i);
    { vader_box_t __vret = vader_box_i32(338u, t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$stack_obj(void* l0, int64_t l1, vader_string_t l2) {
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
    l3 = vader_vm$peek_val(l0, l1);
    if (!(l3.tag == 1430u)) {
        l4 = l3;
        l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l6 = concat_2(l2, 205u);
        t0 = vader_vm$read_obj(l4, l5, l6);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm$stack_tags(void* l0, int64_t l1, int64_t l2) {
    void* l3 = NULL;
    int64_t l4;
    int64_t t0, t1;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!((l2 > INT64_C(2)))) {
        l3 = ((vader_struct_vader_vm$FunctionTags_t*) l0)->f_stack;
        t0 = vader_chk_mul(i64, l1, INT64_C(2));
        t1 = vader_chk_add(i64, t0, l2);
        l4 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 340u);
        t3 = ((uint8_t) t2.payload.i);
        { uint8_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(79));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 2850u);
    l4 = std_core$write_int(l3, l4, l2);
    l4 = std_core$write_string_at(l3, l4, 97u);
    t4 = std_core$finish_buffer(l3, l4);
    vader_host_std_abort$panic(t4);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static bool vader_vm$step_should_stop(uint8_t l0, int32_t l1, int32_t l2) {
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

static void vader_vm$stop_at_line(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5) {
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
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    l7 = ((vader_struct_vader_vm$RegFunction_t*) l3)->f_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_debug;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l3)->f_origin);
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
    l7 = ((vader_struct_vader_core_bytecode$DebugPos_t*) l6)->f_line;
    l10 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_last_line;
    if (l7 == l10) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_core_bytecode$DebugPos_t*) l6)->f_line;
    ((vader_struct_vader_vm$DebugSession_t*) l2)->f_last_line = l7;
    l7 = ((int32_t) (int64_t) l5);
    l8 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_controller;
    l11 = ((vader_struct_vader_core_bytecode$DebugPos_t*) l6)->f_file;
    l10 = ((vader_struct_vader_core_bytecode$DebugPos_t*) l6)->f_line;
    l12 = vader_vm$line_has_breakpoint(l8, l11, l10);
    if (!(l12)) {
        l13 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_step_mode;
        l10 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_step_depth;
        t1 = vader_vm$step_should_stop(l13, l10, l7);
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l12) {
        l11 = 1643u;
    } else {
        l11 = 2624u;
    }
    l6 = ((vader_struct_vader_vm$DebugController_t*) ((vader_struct_vader_vm$DebugSession_t*) l2)->f_controller)->f_on_pause;
    t0 = vader_vm$pause_context(l0, l1, l11, l4, l5);
    vader_fn_t* _a3_fnobj = (vader_fn_t*) l6;
    t2 = ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_ref_box(t0));
    l13 = ((uint8_t) t2.payload.i);
    ((vader_struct_vader_vm$DebugSession_t*) l2)->f_step_mode = l13;
    ((vader_struct_vader_vm$DebugSession_t*) l2)->f_step_depth = l7;
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$store_bytes_op(void* l0, int64_t l1, uint64_t l2, vader_string_t l3) {
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
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm$stack_i32(l0, l4, l3, 2414u);
    if (l5.tag == 1446u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(3));
    l6 = vader_vm$stack_obj(l0, l4, l3);
    if (l6.tag == 1446u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l5.payload.i);
    t1 = l6.payload.obj;
    l4 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$check_byte_range(l7, l1, l4, l3, l8);
    if (!(l5.tag == 1446u)) {
        t1 = l6.payload.obj;
        l9 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
        l4 = ((int64_t) l5.payload.i);
        vader_core_bytecode$write_le(l9, l4, l1, l2);
        t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
        l4 = vader_chk_sub(i64, t0, INT64_C(3));
        ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l4;
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l7 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l7;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l5.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$store_slot(void* l0, void* l1, int64_t l2, int32_t l3, bool l4, int64_t l5) {
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
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack)->length;
    l6 = vader_chk_sub(i64, t0, INT64_C(1));
    t1 = vader_vm$slot_valtype(l1, l3);
    l7 = vader_vm$narrow_code(t1);
    l8 = l5;
    l9 = INT64_C(0);
    while ((l9 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        if (((vader_struct_vader_vm$Pending_t*) t2)->f_kind == INT32_C(1)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            t3 = ((vader_struct_vader_vm$Pending_t*) t2)->f_register;
            if (t3 == l3) {
                vader_vm$materialise(l0, l2, l9);
                l8 = INT64_C(-1);
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
    if (((vader_struct_vader_vm$Pending_t*) l10)->f_kind == INT32_C(0)) {
        l11 = (l8 >= INT64_C(0));
    } else {
        l11 = false;
    }
    if (l11) {
        l12 = vader_vm$operand_of(l0, l8, INT64_C(0));
        l13 = ((vader_struct_vader_vm$Pending_t*) l10)->f_register;
        l11 = l12 == l13;
    } else {
        l11 = false;
    }
    if (l11) {
        l14 = ((vader_struct_vader_vm$Translation_t*) l0)->f_operands;
        l6 = vader_chk_mul(i64, INT64_C(3), l8);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l3;
    } else if (((vader_struct_vader_vm$Pending_t*) l10)->f_kind == INT32_C(2)) {
        l12 = ((vader_struct_vader_vm$Pending_t*) l10)->f_register;
        vader_vm$emit(l0, l2, INT32_C(1), l3, l12, INT32_C(0));
    } else {
        t3 = ((vader_struct_vader_vm$Pending_t*) l10)->f_register;
        if (t3 != l3) {
            l12 = ((vader_struct_vader_vm$Pending_t*) l10)->f_register;
            vader_vm$emit(l0, l2, INT32_C(0), l3, l12, INT32_C(0));
        }
    }
    if ((l7 >= INT32_C(0))) {
        vader_vm$emit(l0, l2, INT32_C(106), l3, l7, INT32_C(0));
    }
    t4 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
    if (l4) {
        l10 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
        vader_struct_vader_vm$Pending_t* _a4_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
        vader_obj_header_init(_a4_obj, 1435u);
        _a4_obj->f_kind = (uint8_t) 1;
        _a4_obj->f_register = l3;
        l14 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l10, l14);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm$string_array_to_value(void* l0, int32_t l1) {
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
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
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
        vader_array_push((vader_array_t*) l2, vader_box_string(335u, l6));
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_array_t*) l2)->length;
    vader_struct_vader_vm$ArrayVal_t* _a3_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1418u);
    _a3_obj->f_type_id = l1;
    _a3_obj->f_elements = l2;
    _a3_obj->f_offset = INT64_C(0);
    _a3_obj->f_length = l3;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$string_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    vader_string_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 335u) {
            t1 = l2.payload.s;
            return vader_box_string(335u, t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_vm$string_byte_op(void* l0, int64_t l1, uint8_t l2) {
    int32_t l3, l4, l5;
    int64_t l6;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(1)) {
        t0 = vader_vm$one_argument_string_op(l0, l1, INT32_C(121));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(4)) {
        t0 = vader_vm$one_argument_string_op(l0, l1, INT32_C(124));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        l3 = vader_vm$operand(l0, INT64_C(1));
        l4 = vader_vm$operand(l0, INT64_C(2));
        l5 = vader_vm$pop_to(l0, INT64_C(2));
        vader_vm$emit(l0, l1, INT32_C(122), l5, l4, l3);
        vader_vm$push_register(l0, l5);
        t1 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops)->length;
        l6 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Translation_t*) l0)->f_retarget = l6;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (!(l2 == INT32_C(3))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack)->length;
    l6 = vader_chk_sub(i64, t1, INT64_C(3));
    vader_vm$materialise(l0, l1, l6);
    l3 = vader_vm$operand(l0, INT64_C(1));
    l4 = vader_vm$operand(l0, INT64_C(2));
    l5 = vader_vm$pop_to(l0, INT64_C(3));
    vader_vm$emit(l0, l1, INT32_C(123), l5, l4, l3);
    vader_vm$push_register(l0, l5);
    { vader_gc_top = gc_frame.prev; return true; }
}

static void vader_vm$string_constant(void* l0, void* l1, int64_t l2, void* l3) {
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
    l4 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_stack)->length;
    l5 = vader_vm$canonical(l1, l4);
    l6 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_code)->f_values;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings;
    l8 = ((vader_struct_vader_core_bytecode$StringConst_t*) l3)->f_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
    l9 = t0.payload.s;
    vader_array_push((vader_array_t*) l6, vader_box_string(335u, l9));
    t1 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_code)->f_values)->length;
    t2 = vader_chk_sub(i64, t1, INT64_C(1));
    l8 = ((int32_t) (int64_t) t2);
    vader_vm$emit(l1, l2, INT32_C(110), l5, l8, INT32_C(0));
    vader_vm$push_register(l1, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$struct_new_effect(void* l0, int32_t l1) {
    int64_t l2;
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    t0 = vader_vm$in_range(l1, l2);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 746u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l3.payload.obj;
    t2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields)->length;
    t1 = vader_vm$effect(t2, INT64_C(1));
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm$tags_of_type(void* l0, int32_t l1) {
    int64_t l2;
    bool t0;
    vader_box_t t1;
    uint8_t t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_type_tags)->length;
    t0 = vader_vm$in_range(l1, l2);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_type_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
        t2 = ((uint8_t) t1.payload.i);
        return t2;
    }
    return (uint8_t) 127;
}

static uint8_t vader_vm$tags_of_val(uint8_t l0) {
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

static bool vader_vm$tags_within(uint8_t l0, uint8_t l1) {
    return (l0 | l1) == l1;
}

static bool vader_vm$trait_implemented_by(void* l0, vader_string_t l1, int32_t l2) {
    int64_t l3, l4;
    void* t0;
    int32_t t1;
    vader_string_t t2;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_impl_table)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_impl_table);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) t0)->f_type_index;
        if (t1 == l2) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t2 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) t0)->f_trait_name;
            if (t2 == l1) {
                return true;
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static int64_t vader_vm$transfer(void* l0, vader_box_t l1, void* l2, int64_t l3, int64_t l4, void* l5) {
    uint8_t l6, l14;
    int64_t l7, l10, l12, l13;
    int32_t l8;
    vader_box_t l9;
    void* l11;
    int64_t t0;
    vader_box_t t1;
    void* t2;
    if ((l4 > INT64_C(0))) {
        t0 = vader_chk_add(i64, l3, l4);
        l7 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 340u);
        l6 = ((uint8_t) t1.payload.i);
    } else {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_vm$StackEffect_t*) l5)->f_pops;
    l7 = vader_chk_sub(i64, l4, l7);
    if (l1.tag == 851u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t2)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    } else if (l1.tag == 852u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t2)->f_slot;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    }
    l9 = vader_vm$call_results(l0, l1);
    if (l9.tag == 0u) {
        t0 = ((vader_struct_vader_vm$StackEffect_t*) l5)->f_pushes;
        if (t0 == INT64_C(1)) {
            l10 = vader_chk_add(i64, l3, l7);
            l14 = vader_vm$pushed_tags(l0, l1, l2, l6);
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
            t1 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l13, 340u);
            l6 = ((uint8_t) t1.payload.i);
            if (l6 != INT32_C(14)) {
                l14 = vader_vm$tags_of_val(l6);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l14;
                l10 = vader_chk_add(i64, l10, INT64_C(1));
            }
            l13 = (l13 + INT64_C(1));
        }
    }
    l10 = ((vader_struct_vader_vm$StackEffect_t*) l5)->f_pushes;
    t0 = vader_chk_add(i64, l7, l10);
    return t0;
}

static vader_box_t vader_vm$translate_function(void* l0, void* l1, int32_t l2, void* l3, bool l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    int64_t l6, l7, l8, l22, l23, l25, l26;
    vader_string_t l14 = 0;
    int32_t l24, l27, l28, l30;
    vader_box_t l29 = vader_box_null();
    int64_t t0;
    bool t1, t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l29, &t3 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l3, &l5, &l9, &l10, &l11, &l12, &l13, &l15, &l16, &l17, &l18, &l19, &l20, &l21,
        &t4,
    };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body)->length;
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature)->f_params)->length;
    l8 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_locals)->length;
    l7 = vader_chk_add(i64, l7, l8);
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 8u, 339u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(25u, 0u, 1u, 340u);
    l10 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 0u, 346u);
    l11 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(24u, 0u, 8u, 339u);
    l12 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l13 = (void*) _a5_arr;
    vader_struct_std_collections$MutableMap__Any__i64_t* _a6_obj = (vader_struct_std_collections$MutableMap__Any__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__Any__i64_t));
    vader_obj_header_init(_a6_obj, 466u);
    _a6_obj->f_ekeys = l11;
    _a6_obj->f_evals = l12;
    _a6_obj->f_index = l13;
    _a6_obj->f_mask = INT64_C(0);
    _a6_obj->f_grow_at = INT64_C(0);
    _a6_obj->f_size = INT64_C(0);
    _a6_obj->f_tombs = INT64_C(0);
    l11 = (void*) _a6_obj;
    vader_vm$collect_constants(l5, l9, l10, l11);
    l8 = ((vader_array_t*) l9)->length;
    l8 = vader_chk_add(i64, l7, l8);
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(24u, 0u, 8u, 339u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(23u, 0u, 7u, 338u);
    l15 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(25u, 0u, 1u, 340u);
    l16 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l17 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(246u, 0u, 13u, 1689u);
    l18 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(66u, 0u, 13u, 895u);
    l19 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(23u, 0u, 7u, 338u);
    l20 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(22u, 0u, 0u, 335u);
    l21 = (void*) _a15_arr;
    l22 = ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_deepest;
    t0 = vader_chk_add(i64, l8, l22);
    l22 = vader_chk_add(i64, t0, INT64_C(1));
    l23 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature)->f_params)->length;
    vader_struct_vader_vm$RegFunction_t* _a16_obj = (vader_struct_vader_vm$RegFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegFunction_t));
    vader_obj_header_init(_a16_obj, 1436u);
    _a16_obj->f_name = l14;
    _a16_obj->f_index = l2;
    _a16_obj->f_ops = l12;
    _a16_obj->f_words = l13;
    _a16_obj->f_origin = l15;
    _a16_obj->f_kinds = l16;
    _a16_obj->f_consts = l9;
    _a16_obj->f_const_tags = l10;
    _a16_obj->f_values = l17;
    _a16_obj->f_boxed = l18;
    _a16_obj->f_virtuals = l19;
    _a16_obj->f_virtual_rows = l20;
    _a16_obj->f_texts = l21;
    _a16_obj->f_registers = l22;
    _a16_obj->f_params = l23;
    _a16_obj->f_slots = l7;
    l9 = (void*) _a16_obj;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 7u, 338u);
    l10 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(228u, 0u, 13u, 1435u);
    l12 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(24u, 0u, 8u, 339u);
    l13 = (void*) _a19_arr;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_vm$Translation_t* _a20_obj = (vader_struct_vader_vm$Translation_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Translation_t));
    vader_obj_header_init(_a20_obj, 1445u);
    _a20_obj->f_code = l9;
    _a20_obj->f_operands = l10;
    _a20_obj->f_stack = l12;
    _a20_obj->f_stack_base = l8;
    _a20_obj->f_retarget = INT64_C(-1);
    _a20_obj->f_jumps = l13;
    _a20_obj->f_source_pc = l15;
    _a20_obj->f_import_ids = l1;
    _a20_obj->f_constants = l11;
    l9 = (void*) _a20_obj;
    l10 = vader_core_bytecode$mark_jump_targets(((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_jump_table, l6);
    vader_array_t* _a21_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = (int64_t) INT64_C(0);
    l11 = (void*) _a21_arr;
    l7 = vader_chk_add(i64, l6, INT64_C(1));
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) l11, (int64_t) l7);
    l11 = (void*) _a22_arr;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
        t1 = ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l7];
        t2 = t1;
        if (t2) {
            vader_vm$flush(l9, l7);
        }
        l8 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_ops)->length;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
        ((int64_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l7] = (int64_t) l8;
        vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_depth);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
        t0 = ((int64_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l7];
        if ((t0 < INT64_C(0))) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
        t1 = ((uint8_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l7];
        t2 = t1;
        if (t2) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            l22 = ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l7];
            vader_vm$reset_stack(l9, l22);
        }
        if (l4) {
            l23 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_debug)->length;
            if ((l7 < l23)) {
                vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_debug);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
                t3 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
                if (!(t3.tag == 0u)) {
                    vader_vm$emit(l9, l7, INT32_C(128), INT32_C(0), INT32_C(0), INT32_C(0));
                }
            }
        }
        t1 = vader_vm$translate_op(l0, l5, l3, l9, l7);
        if (!(t1)) {
            l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
            l24 = ((int32_t) (int64_t) l7);
            vader_struct_vader_vm$VerifyError_t* _a29_obj = (vader_struct_vader_vm$VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VerifyError_t));
            vader_obj_header_init(_a29_obj, 1449u);
            _a29_obj->f_function = l14;
            _a29_obj->f_pc = l24;
            _a29_obj->f_message = 2390u;
            t4 = (void*) _a29_obj;
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (l7 + INT64_C(1));
    }
    l7 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_ops)->length;
    vader_array_t* _a30_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
    ((int64_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l6] = (int64_t) l7;
    vader_vm$emit(l9, l6, INT32_C(107), INT32_C(-1), INT32_C(0), INT32_C(0));
    l6 = INT64_C(0);
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_jumps)->length;
    l7 = vader_div_i64(t0, INT64_C(2));
    while ((l6 < l7)) {
        l10 = ((vader_struct_vader_vm$Translation_t*) l9)->f_jumps;
        l8 = vader_chk_mul(i64, INT64_C(2), l6);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l8)
        l22 = ((int64_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l8];
        l12 = ((vader_struct_vader_vm$Translation_t*) l9)->f_operands;
        l23 = vader_chk_mul(i64, INT64_C(3), l22);
        l13 = ((vader_struct_vader_vm$Translation_t*) l9)->f_jumps;
        t0 = vader_chk_mul(i64, INT64_C(2), l6);
        l25 = vader_chk_add(i64, t0, INT64_C(1));
        vader_array_t* _a32_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l25)
        l26 = ((int64_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l25];
        vader_array_t* _a33_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l26)
        t0 = ((int64_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l26];
        l24 = ((int32_t) (int64_t) t0);
        vader_array_t* _a34_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l23)
        ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l23] = (int32_t) l24;
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_ops)->length;
    while ((l6 < l7)) {
        l24 = vader_vm$operand_of(l9, l6, INT64_C(0));
        l27 = vader_vm$operand_of(l9, l6, INT64_C(1));
        l28 = vader_vm$operand_of(l9, l6, INT64_C(2));
        l29 = vader_vm$pack_operands(l24, l27, l28);
        if (l29.tag == 0u) {
            l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
            vader_array_t* _a35_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_origin);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l6)
            l30 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l6];
            vader_struct_vader_vm$VerifyError_t* _a36_obj = (vader_struct_vader_vm$VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VerifyError_t));
            vader_obj_header_init(_a36_obj, 1449u);
            _a36_obj->f_function = l14;
            _a36_obj->f_pc = l30;
            _a36_obj->f_message = 1538u;
            t4 = (void*) _a36_obj;
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_words;
        l8 = ((int64_t) l29.payload.i);
        vader_array_push_i64((vader_array_t*) l10, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(((vader_struct_vader_vm$Translation_t*) l9)->f_code); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$translate_module(void* l0, void* l1, void* l2, bool l3) {
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
    vader_array_t* _a0_arr = vader_array_new(229u, 0u, 13u, 1436u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l5 < l6)) {
        l7 = ((int32_t) (int64_t) l5);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l9 = vader_vm$translate_function(l0, l1, l7, l8, l3);
        if (l9.tag == 1449u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = l9.payload.obj;
        vader_array_push_ref((vader_array_t*) l4, l10);
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_vm$RegModule_t* _a3_obj = (vader_struct_vader_vm$RegModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegModule_t));
    vader_obj_header_init(_a3_obj, 1438u);
    _a3_obj->f_functions = l4;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$translate_op(void* l0, void* l1, void* l2, void* l3, int64_t l4) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l6 = ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget;
    ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = INT64_C(-1);
    l7 = vader_vm$binary_op(l5, l2, l4);
    if (!(l7.tag == 0u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$pop_to(l3, INT64_C(2));
        l11 = ((int32_t) l7.payload.i);
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
        vader_vm$note_checked_kind(l3, l5);
        vader_vm$push_register(l3, l10);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l7 = vader_vm$unary_op(l5, l2, l4);
    if (!(l7.tag == 0u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        l10 = ((int32_t) l7.payload.i);
        vader_vm$emit(l3, l4, l10, l9, l8, INT32_C(0));
        vader_vm$note_checked_kind(l3, l5);
        vader_vm$push_register(l3, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 850u) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_stack;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
        vader_struct_vader_vm$Pending_t* _a1_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
        vader_obj_header_init(_a1_obj, 1435u);
        _a1_obj->f_kind = (uint8_t) 1;
        _a1_obj->f_register = l8;
        l14 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l13, l14);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 851u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
        vader_vm$store_slot(l3, l1, l4, l8, false, l6);
    } else if (l5.tag == 852u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t1)->f_slot;
        vader_vm$store_slot(l3, l1, l4, l8, true, l6);
    } else if ((l5.tag == 756u || l5.tag == 771u || l5.tag == 784u || l5.tag == 805u || l5.tag == 825u || l5.tag == 856u)) {
        l7 = l5;
        vader_vm$push_constant(l3, l7);
    } else if (l5.tag == 779u) {
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
    } else if ((l5.tag == 754u || l5.tag == 781u || l5.tag == 853u || l5.tag == 857u || l5.tag == 860u)) {
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l6;
    } else if ((l5.tag == 761u || l5.tag == 780u)) {
        if (l5.tag == 780u) {
            l12 = vader_chk_sub(i64, l4, INT64_C(1));
            l15 = vader_vm$skips_else(l1, l12);
        } else {
            l15 = false;
        }
        if (!(l15)) {
            vader_vm$flush(l3, l4);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            l8 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_vm$jump(l3, l4, INT32_C(87), INT32_C(0), INT32_C(0), l8);
        }
    } else if ((l5.tag == 762u || l5.tag == 840u)) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_stack;
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
        l13 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l12);
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
        vader_vm$flush(l3, l4);
        l15 = vader_vm$skips_else(l1, l4);
        if (l5.tag == 762u) {
            l16 = true;
        } else {
            l16 = l15;
        }
        l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table;
        if (l15) {
            l12 = vader_chk_add(i64, l4, INT64_C(1));
        } else {
            l12 = l4;
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
        l8 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
        if (((vader_struct_vader_vm$Pending_t*) l13)->f_kind == INT32_C(0)) {
            l17 = (l6 >= INT64_C(0));
        } else {
            l17 = false;
        }
        if (l17) {
            t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops)->length;
            l12 = vader_chk_sub(i64, t0, INT64_C(1));
            l17 = l6 == l12;
        } else {
            l17 = false;
        }
        if (l17) {
            l9 = vader_vm$operand_of(l3, l6, INT64_C(0));
            l10 = ((vader_struct_vader_vm$Pending_t*) l13)->f_register;
            l15 = l9 == l10;
        } else {
            l15 = false;
        }
        if (l15) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
            l7 = vader_vm$fused_branch(t3, l16);
        } else {
            l7 = vader_box_obj(0u, NULL);
        }
        if (l7.tag == 0u) {
            if (l16) {
                l18 = INT32_C(90);
            } else {
                l18 = INT32_C(89);
            }
            l19 = ((vader_struct_vader_vm$Pending_t*) l13)->f_register;
            vader_vm$jump(l3, l4, l18, l19, INT32_C(0), l8);
        } else {
            l9 = vader_vm$operand_of(l3, l6, INT64_C(1));
            l10 = vader_vm$operand_of(l3, l6, INT64_C(2));
            vader_vm$drop_last_op(l3);
            t1 = l7.payload.obj;
            t4 = ((vader_struct_vader_vm$FusedBranch_t*) t1)->f_swap;
            if (t4) {
                t1 = l7.payload.obj;
                l11 = ((vader_struct_vader_vm$FusedBranch_t*) t1)->f_op;
                vader_vm$jump(l3, l4, l11, l10, l9, l8);
            } else {
                t1 = l7.payload.obj;
                l11 = ((vader_struct_vader_vm$FusedBranch_t*) t1)->f_op;
                vader_vm$jump(l3, l4, l11, l9, l10, l8);
            }
        }
    } else if (l5.tag == 861u) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 340u);
        l20 = ((uint8_t) t2.payload.i);
        t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature);
        if ((t0 > INT64_C(1))) {
            l13 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_results;
            vader_vm$return_many(l3, l4, l13);
        } else if (l20 == INT32_C(14)) {
            vader_vm$emit(l3, l4, INT32_C(107), INT32_C(-1), INT32_C(0), INT32_C(0));
        } else {
            t3 = vader_vm$narrow_code(l20);
            if ((t3 >= INT32_C(0))) {
                vader_vm$flush(l3, l4);
                t0 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack)->length;
                l6 = vader_chk_sub(i64, t0, INT64_C(1));
                l8 = vader_vm$canonical(l3, l6);
                l9 = vader_vm$narrow_code(l20);
                vader_vm$emit(l3, l4, INT32_C(106), l8, l9, INT32_C(0));
                vader_vm$emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
            } else {
                l8 = vader_vm$operand(l3, INT64_C(1));
                vader_vm$emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
            }
        }
    } else if (l5.tag == 770u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t1)->f_type_id;
        l7 = vader_vm$fn_type_of(l0, l8);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) l13)->f_params)->length;
        vader_vm$flush(l3, l4);
        l12 = vader_chk_add(i64, l6, INT64_C(1));
        l8 = vader_vm$pop_to(l3, l12);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t1)->f_type_id;
        l10 = ((int32_t) (int64_t) l6);
        vader_vm$emit(l3, l4, INT32_C(104), l9, l8, l10);
        l9 = ((vader_struct_vader_core_bytecode$BcFn_t*) l13)->f_return_type;
        t4 = vader_vm$returns_void(l0, l9);
        if (!(t4)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 895u) {
        t1 = l5.payload.obj;
        l6 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$VirtualCall_t*) t1)->f_results);
        if ((l6 > INT64_C(1))) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        vader_vm$flush(l3, l4);
        t1 = l5.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t1)->f_parameter_count;
        l12 = ((int64_t) (int32_t) t3);
        l8 = vader_vm$pop_to(l3, l12);
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_virtuals;
        l14 = l5.payload.obj;
        vader_array_push_ref((vader_array_t*) l13, l14);
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_virtual_rows;
        l14 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_vtables;
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t1)->f_vtable_key;
        l9 = vader_vm$vtable_row_of(l14, l21);
        vader_array_push_i32((vader_array_t*) l13, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_virtuals)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l9 = ((int32_t) (int64_t) t5);
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t1)->f_parameter_count;
        vader_vm$emit(l3, l4, INT32_C(105), l9, l8, l10);
        if (l6 == INT64_C(1)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 768u) {
        l13 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$Call_t*) t1)->f_function_index;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_signature;
        l6 = vader_core_bytecode$bc_result_arity(l13);
        vader_vm$flush(l3, l4);
        l12 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l13)->f_params)->length;
        l8 = vader_vm$pop_to(l3, l12);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t1)->f_function_index;
        vader_vm$emit(l3, l4, INT32_C(103), l9, l8, INT32_C(0));
        l12 = INT64_C(0);
        while ((l12 < l6)) {
            l9 = ((int32_t) (int64_t) l12);
            l10 = vader_chk_add(i32, l8, l9);
            vader_vm$push_register(l3, l10);
            l12 = (l12 + INT64_C(1));
        }
    } else if (l5.tag == 862u) {
        t1 = l5.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t1)->f_value;
        if (l7.tag == 872u) {
            l13 = l7.payload.obj;
            vader_vm$string_constant(l0, l3, l4, l13);
        } else {
            vader_vm$push_constant(l3, l7);
        }
        l8 = vader_vm$operand(l3, INT64_C(1));
        vader_vm$emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 769u) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_import_ids;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
        t2 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l8, 340u);
        l20 = ((uint8_t) t2.payload.i);
        t4 = vader_vm$string_byte_op(l3, l4, l20);
        if (t4) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l13 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l8);
        l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) t1)->f_signature;
        vader_vm$flush(l3, l4);
        l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l13)->f_params)->length;
        l8 = vader_vm$pop_to(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_vm$emit(l3, l4, INT32_C(120), l9, l8, INT32_C(0));
        t6 = vader_core_bytecode$bc_single_result(l13);
        if (t6 != INT32_C(14)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 778u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
        vader_vm$emit(l3, l4, INT32_C(126), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 777u) {
        vader_vm$flush(l3, l4);
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t1)->f_count;
        vader_vm$emit(l3, l4, INT32_C(127), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 796u) {
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts;
        l14 = (void*) vader_buffer_new((size_t) INT64_C(87));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l14, l6, 2009u);
        l6 = std_core$write_int(l14, l6, l4);
        l6 = std_core$write_string_at(l14, l6, 495u);
        l21 = std_core$finish_buffer(l14, l6);
        vader_array_push_scalar((vader_array_t*) l13, vader_box_string(335u, l21));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm$emit(l3, l4, INT32_C(125), l8, INT32_C(0), INT32_C(0));
        l6 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm$canonical(l3, l6);
        vader_vm$push_register(l3, l8);
    } else if (l5.tag == 894u) {
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts;
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t1)->f_reason;
        l21 = concat_2(2489u, l21);
        vader_array_push_scalar((vader_array_t*) l13, vader_box_string(335u, l21));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm$emit(l3, l4, INT32_C(125), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 849u) {
        l6 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm$canonical(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t1)->f_slot;
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$LocalField_t*) t1)->f_field_index;
        vader_vm$emit(l3, l4, INT32_C(111), l8, l9, l10);
        vader_vm$push_register(l3, l8);
    } else if ((l5.tag == 875u || l5.tag == 892u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_field_index, l5.payload.obj);
        vader_vm$emit(l3, l4, INT32_C(111), l9, l8, l10);
        vader_vm$push_register(l3, l9);
    } else if ((l5.tag == 877u || l5.tag == 893u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        vader_vm$pop_to(l3, INT64_C(2));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructSet_t, f_field_index, l5.payload.obj);
        vader_vm$emit(l3, l4, INT32_C(112), l9, l8, l10);
    } else if ((l5.tag == 723u || l5.tag == 845u || l5.tag == 846u || l5.tag == 847u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$pop_to(l3, INT64_C(2));
        if (l5.tag == 723u) {
            l11 = INT32_C(113);
        } else {
            l11 = INT32_C(115);
        }
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
        vader_vm$push_register(l3, l10);
    } else if ((l5.tag == 730u || l5.tag == 867u || l5.tag == 868u || l5.tag == 869u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$operand(l3, INT64_C(3));
        vader_vm$pop_to(l3, INT64_C(3));
        if (l5.tag == 730u) {
            l11 = INT32_C(114);
        } else {
            l11 = INT32_C(116);
        }
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
    } else if (l5.tag == 724u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        vader_vm$emit(l3, l4, INT32_C(117), l9, l8, INT32_C(0));
        vader_vm$push_register(l3, l9);
    } else if (l5.tag == 726u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        vader_vm$pop_to(l3, INT64_C(2));
        vader_vm$emit(l3, l4, INT32_C(118), l9, l8, INT32_C(0));
    } else if (l5.tag == 872u) {
        l13 = l5.payload.obj;
        vader_vm$string_constant(l0, l3, l4, l13);
    } else {
        t4 = vader_vm$is_boxed(l5);
        if (!(t4)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = l5;
        l7 = vader_vm$effect_of(l0, l1, l7);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l6 = ((vader_struct_vader_vm$StackEffect_t*) l13)->f_pops;
        l12 = ((vader_struct_vader_vm$StackEffect_t*) l13)->f_pushes;
        vader_vm$boxed(l3, l4, l5, l6, l12);
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static int32_t vader_vm$truncate_to_width(int64_t l0, int64_t l1, bool l2) {
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

static bool vader_vm$try_get_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4) {
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
    l7 = vader_vm$array_at(l0, l6);
    if (l7.tag == 0u) {
        return false;
    }
    l5 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
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
    l10 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_length;
    if ((l6 >= l10)) {
        return false;
    }
    l7 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_raw;
    if (!(l7.tag == 0u)) {
        l8 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        l11 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags;
        l12 = l7.payload.s;
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_offset;
        l10 = ((int64_t) (int32_t) l9);
        l6 = vader_chk_add(i64, l6, l10);
        t1 = vader_host_std_core$byte_at(l12, l6);
        l13 = ((int32_t) (uint8_t) t1);
        vader_vm$set_i32(l8, l11, l1, l2, l13);
        return true;
    }
    l6 = ((int64_t) (int32_t) l2);
    l6 = vader_chk_add(i64, l1, l6);
    l8 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements;
    l10 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_offset;
    l14 = ((int64_t) (int32_t) l9);
    l10 = vader_chk_add(i64, l10, l14);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
    l7 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l10];
    vader_vm$set_register(l0, l6, l7);
    return true;
}

static bool vader_vm$try_set_element(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5;
    void* l8;
    int64_t l6, l10;
    vader_box_t l7;
    int32_t l9;
    int64_t t0;
    l6 = ((int64_t) (int32_t) l2);
    l6 = vader_chk_add(i64, l1, l6);
    l7 = vader_vm$array_at(l0, l6);
    if (l7.tag == 0u) {
        return false;
    }
    l5 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
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
    l10 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_length;
    if ((l6 >= l10)) {
        return false;
    }
    if (((vader_struct_vader_vm$ArrayVal_t*) l5)->f_raw.tag == 0u) {
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements;
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_offset;
        l10 = ((int64_t) (int32_t) l9);
        l6 = vader_chk_add(i64, l6, l10);
        l10 = ((int64_t) (int32_t) l4);
        l10 = vader_chk_add(i64, l1, l10);
        l7 = vader_vm$register_value(l0, l10);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6] = l7;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        return true;
    }
    return false;
}

static int32_t vader_vm$type_id_for_symbol(void* l0, int32_t l1) {
    int32_t l2;
    l2 = vader_core_bytecode$struct_symbol_type_index(l0, l1);
    if ((l2 < INT32_C(0))) {
        return INT32_C(0);
    }
    return l2;
}

static bool vader_vm$type_matches(void* l0, vader_box_t l1, int32_t l2) {
    int64_t l3, l4;
    vader_box_t l5;
    bool l6;
    uint8_t l7;
    void* l8;
    vader_string_t l9;
    void* t0;
    int32_t t1;
    if ((l2 < INT32_C(0))) {
        return false;
    }
    l3 = ((int64_t) (int32_t) l2);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types)->length;
    if ((l3 >= l4)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l5.tag == 743u) {
        t0 = l5.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
        l6 = vader_vm$class_matches(l1, l7);
        return l6;
    }
    if (l5.tag == 746u) {
        if (l1.tag == 1443u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 733u) {
        if (l1.tag == 1418u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 747u) {
        t0 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l6 = vader_vm$union_matches(l0, l1, l8);
    } else if (l5.tag == 742u) {
        t0 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
        l6 = vader_vm$ref_type_matches(l0, l1, l9);
    } else {
        if (!(l5.tag == 736u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = false;
    }
    return l6;
}

static uint8_t vader_vm$type_tags(void* l0, int32_t l1, int32_t l2) {
    int64_t l3, l8;
    vader_box_t l4;
    uint8_t l5, l6, l11;
    void* l7;
    int32_t l9, l10;
    bool t0;
    void* t1;
    int32_t t2;
    l3 = ((vader_array_t*) l0)->length;
    t0 = vader_vm$in_range(l1, l3);
    if (t0) {
        if ((l2 > INT32_C(8))) {
            return (uint8_t) 127;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l4.tag == 743u) {
            t1 = l4.payload.obj;
            l5 = vader_vm$tags_of_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val);
            return l5;
        }
        if ((l4.tag == 733u || l4.tag == 736u || l4.tag == 746u)) {
            l5 = (uint8_t) 64;
        } else if (l4.tag == 742u) {
            l5 = (uint8_t) 127;
        } else {
            if (!(l4.tag == 747u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l6 = (uint8_t) 0;
            t1 = l4.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
            l3 = ((vader_array_t*) l7)->length;
            l8 = INT64_C(0);
            while ((l8 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
                l10 = vader_chk_add(i32, l2, INT32_C(1));
                l11 = vader_vm$type_tags(l0, l9, l10);
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

static uint32_t vader_vm$u32_of(void* l0, int64_t l1, int32_t l2) {
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

static uint64_t vader_vm$u64_of(void* l0, int64_t l1, int32_t l2) {
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

static vader_box_t vader_vm$unary_op(vader_box_t l0, void* l1, int64_t l2) {
    uint8_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    uint8_t t2;
    bool t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (((INT32_C(1) | INT32_C(2)) | INT32_C(16)) | INT32_C(8));
    l3 = (uint8_t) (int32_t) t0;
    if (l0.tag == 815u) {
        l4 = vader_box_i32(338u, INT32_C(13));
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 802u) {
        l4 = vader_box_i32(338u, INT32_C(14));
    } else if (l0.tag == 835u) {
        l4 = vader_box_i32(338u, INT32_C(38));
    } else if (l0.tag == 822u) {
        l4 = vader_box_i32(338u, INT32_C(39));
    } else if (l0.tag == 793u) {
        l4 = vader_box_i32(338u, INT32_C(56));
    } else if (l0.tag == 773u) {
        t1 = l0.payload.obj;
        t0 = vader_vm$checked_neg_register_op(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t1)->f_kind);
        l4 = vader_box_i32(338u, t0);
    } else if (l0.tag == 759u) {
        t2 = vader_vm$stack_tags(l1, l2, INT64_C(1));
        t3 = vader_vm$tags_within(t2, (uint8_t) 8);
        if (t3) {
            l4 = vader_box_i32(338u, INT32_C(67));
        } else {
            l4 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 774u) {
        t2 = vader_vm$stack_tags(l1, l2, INT64_C(1));
        t3 = vader_vm$tags_within(t2, l3);
        if (t3) {
            t1 = l0.payload.obj;
            if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(0)) {
                l4 = vader_box_i32(338u, INT32_C(83));
            } else {
                t1 = l0.payload.obj;
                if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(1)) {
                    t1 = l0.payload.obj;
                    t4 = ((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_from_name;
                    t0 = vader_vm$widening(t4);
                    l4 = vader_box_i32(338u, t0);
                } else {
                    t1 = l0.payload.obj;
                    if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(3)) {
                        l4 = vader_box_i32(338u, INT32_C(86));
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
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$union_matches(void* l0, vader_box_t l1, void* l2) {
    int64_t l3, l4;
    int32_t l5;
    bool t0;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l2)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        t0 = vader_vm$type_matches(l0, l1, l5);
        if (t0) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static vader_string_t vader_vm$unopened_reason(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_library;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 1729u; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_std_ffi$CLibrary_t*) l1)->f_name;
    t0 = concat_3(1727u, l3, 1035u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$unwind(void* l0, void* l1, void* l2, bool l3) {
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
        t0 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
        if ((t0 > INT64_C(0))) {
            t0 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count = l4;
            l5 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers;
            l6 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            l7 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
            l8 = vader_vm$defer_thunk(l0, l7, INT32_C(0), 2445u);
            if (l8.tag == 1446u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = l8.payload.obj;
            t1 = vader_vm$run_thunk(l0, l1, l2, l9, INT64_C(0), INT64_C(0), INT64_C(0), l3);
            if (!(t1.tag == 0u)) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$validate_fn_index(int32_t l0, void* l1, int32_t l2, vader_string_t l3) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_vm$is_fn_index_out_of_range(l0, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_vm$fn_index_trap(l0, l2, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$value_from_bits(uint8_t l0, uint64_t l1) {
    uint64_t l2;
    uint32_t l3;
    bool l4;
    int64_t t0;
    int32_t t1;
    if (l0 == INT32_C(1)) {
        return vader_box_i32(338u, ((int32_t) (int64_t) (l1 & INT64_C(255))));
    }
    if (l0 == INT32_C(5)) {
        t0 = (l1 & INT64_C(255));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(128))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(256));
            return vader_box_i32(338u, t1);
        }
        return vader_box_i32(338u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(12)) {
        return vader_box_bool(333u, l1 != INT64_C(0));
    }
    if (l0 == INT32_C(2)) {
        return vader_box_i32(338u, ((int32_t) (int64_t) (l1 & INT64_C(65535))));
    }
    if (l0 == INT32_C(6)) {
        t0 = (l1 & INT64_C(65535));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(32768))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(65536));
            return vader_box_i32(338u, t1);
        }
        return vader_box_i32(338u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(3)) {
        return vader_box_i32(338u, ((int32_t) (uint64_t) l1));
    }
    if (l0 == INT32_C(7)) {
        return vader_box_i32(338u, ((int32_t) (uint64_t) l1));
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
                return vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l3));
            }
        } else {
            return vader_box_i32(334u, (int32_t) ((uint32_t) (uint32_t) l3));
        }
    } else {
        if (l0 == INT32_C(4)) {
            return vader_box_i64(339u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(8)) {
            return vader_box_i64(339u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(9)) {
            return vader_box_f64(345u, ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
        }
        if (!(l0 == INT32_C(10))) {
            return vader_box_i32(338u, INT32_C(0));
        }
        return vader_box_f64(345u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
    }
}

static bool vader_vm$value_ref_eq(vader_box_t l0, vader_box_t l1) {
    bool l2, l5, l6;
    int32_t l3, l4;
    uint32_t l7, l8;
    vader_string_t l9, l10;
    int64_t l11, l12;
    uint64_t l13, l14;
    vader_box_t l15, l16;
    double t0;
    int64_t t1;
    if (l0.tag == 1429u) {
        l2 = l1.tag == 1429u;
        return l2;
    }
    if (l0.tag == 338u) {
        if (l1.tag == 338u) {
            l3 = ((int32_t) l0.payload.i);
            l4 = ((int32_t) l1.payload.i);
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 333u) {
        if (l1.tag == 333u) {
            l5 = l0.payload.b;
            l6 = l1.payload.b;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 334u) {
        if (l1.tag == 334u) {
            l7 = ((uint32_t) l0.payload.i);
            l8 = ((uint32_t) l1.payload.i);
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 335u) {
        if (l1.tag == 335u) {
            l9 = l0.payload.s;
            l10 = l1.payload.s;
            l2 = l9 == l10;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 339u) {
        if (l1.tag == 339u) {
            l11 = ((int64_t) l0.payload.i);
            l12 = ((int64_t) l1.payload.i);
            l2 = l11 == l12;
        } else {
            l2 = false;
        }
    } else if ((l0.tag == 344u || l0.tag == 345u)) {
        if ((l1.tag == 344u || l1.tag == 345u)) {
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
        if (!((l0.tag == 1418u || l0.tag == 1422u || l0.tag == 1430u || l0.tag == 1443u || l0.tag == 1447u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if ((l1.tag == 1418u || l1.tag == 1422u || l1.tag == 1430u || l1.tag == 1443u || l1.tag == 1447u)) {
            l15 = l0;
            l16 = l1;
            l2 = vader_box_eq(l15, l16);
        } else {
            l2 = false;
        }
    }
    return l2;
}

static vader_box_t vader_vm$verify_function(void* l0, void* l1) {
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
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body)->length;
    if (l2 == INT64_C(0)) {
        { vader_box_t __vret = vader_box_i64(339u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = INT64_C(0);
    l4 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature);
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 8u, 339u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) INT64_C(0);
    vader_array_t* _a3_arr = vader_array_new(24u, 1u, 8u, 339u);
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
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l12 = vader_vm$effect_of(l0, l1, l10);
            if (l12.tag == 0u) {
                l13 = vader_vm$op_text(l10);
                l14 = concat_3(1035u, l13, 1202u);
                t0 = vader_vm$defect(l1, l7, l14);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = l12.payload.obj;
            l15 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_pops;
            if ((l9 < l15)) {
                l16 = vader_vm$op_text(l10);
                l17 = vader_host_std_core$byte_len(l16);
                l18 = (void*) vader_buffer_new((size_t) (INT64_C(79) + l17));
                l19 = INT64_C(0);
                l19 = std_core$write_string_at(l18, l19, 1035u);
                l19 = std_core$write_string_at(l18, l19, l16);
                l19 = std_core$write_string_at(l18, l19, 1204u);
                l20 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_pops;
                l19 = std_core$write_int(l18, l19, l20);
                l19 = std_core$write_string_at(l18, l19, 227u);
                l19 = std_core$write_int(l18, l19, l9);
                l21 = std_core$finish_buffer(l18, l19);
                t0 = vader_vm$defect(l1, l7, l21);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l10.tag == 861u) {
                if (l9 != l4) {
                    l22 = (void*) vader_buffer_new((size_t) INT64_C(87));
                    l23 = INT64_C(0);
                    l23 = std_core$write_string_at(l22, l23, 1393u);
                    l23 = std_core$write_int(l22, l23, l4);
                    l23 = std_core$write_string_at(l22, l23, 227u);
                    l23 = std_core$write_int(l22, l23, l9);
                    l24 = std_core$finish_buffer(l22, l23);
                    t0 = vader_vm$defect(l1, l7, l24);
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l25 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_pops;
            l26 = vader_chk_sub(i64, l9, l25);
            l27 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_pushes;
            l28 = vader_chk_add(i64, l26, l27);
            if ((l28 > l3)) {
                l3 = l28;
            }
            if (((vader_struct_vader_vm$StackEffect_t*) l11)->f_flow == INT32_C(0)) {
                l29 = true;
            } else {
                l29 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (l29) {
                l30 = vader_chk_add(i64, l7, INT64_C(1));
                l31 = vader_vm$flow_to(l1, l5, l6, l30, l28, l7, l4);
                if (!(l31.tag == 0u)) {
                    t0 = l31.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            if (((vader_struct_vader_vm$StackEffect_t*) l11)->f_flow == INT32_C(1)) {
                l32 = true;
            } else {
                l32 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (!(l32)) {
                continue;
            }
            l34 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table)->length;
            if ((l7 < l34)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
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
                l36 = vader_vm$op_text(l10);
                l37 = concat_3(1035u, l36, 1111u);
                t0 = vader_vm$defect(l1, l7, l37);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l38 = ((int64_t) (int32_t) l33);
            l39 = vader_vm$flow_to(l1, l5, l6, l38, l28, l7, l4);
            if (!(l39.tag == 0u)) {
                t0 = l39.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(339u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$verify_module(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 8u, 339u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = vader_vm$verify_function(l0, l5);
        if (l6.tag == 1449u) {
            t0 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((int64_t) l6.payload.i);
        vader_array_push_i64((vader_array_t*) l1, l7);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$vtable_row_of(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    void* t0;
    vader_string_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_key;
        if (t1 == l1) {
            return ((int32_t) (int64_t) l2);
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

static void vader_vm$walk_block(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, void* l5, vader_box_t l6) {
    int64_t l7, l8, l9, l10, l12, l15, l16, l22, l23, l24;
    void* l11 = NULL;
    void* l18 = NULL;
    uint8_t l13;
    bool l14, l20, l21;
    vader_box_t l17 = vader_box_null(), l19 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2, t3;
    int32_t t4;
    vader_box_t* gc_roots[4] = { &l6, &l17, &l19, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l11, &l18, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body)->length;
    l8 = ((vader_struct_vader_vm$Blocks_t*) l2)->f_width;
    l8 = vader_chk_mul(i64, l3, l8);
    l9 = INT64_C(0);
    l10 = ((vader_struct_vader_vm$Blocks_t*) l2)->f_width;
    while ((l9 < l10)) {
        l11 = ((vader_struct_vader_vm$Blocks_t*) l2)->f_entry;
        l12 = vader_chk_add(i64, l8, l9);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l12)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l12, 340u);
        l13 = ((uint8_t) t0.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9] = (uint8_t) (int32_t) (uint8_t) l13;
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l8 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_leaders);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l9 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l3];
    for (;;) {
        if ((l9 < l7)) {
            if (!(l6.tag == 0u)) {
                t1 = l6.payload.obj;
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) t1)->f_depth);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9] = (int64_t) l8;
                l10 = INT64_C(1);
                l12 = std_math$min_3(l8, INT64_C(2));
                l14 = (l10 <= l12);
                while (l14) {
                    t1 = l6.payload.obj;
                    l11 = ((vader_struct_vader_vm$FunctionTags_t*) t1)->f_stack;
                    t2 = vader_chk_mul(i64, l9, INT64_C(2));
                    t3 = vader_chk_add(i64, t2, l10);
                    l15 = vader_chk_sub(i64, t3, INT64_C(1));
                    t2 = vader_chk_add(i64, l4, l8);
                    l16 = vader_chk_sub(i64, t2, l10);
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
                    t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l16, 340u);
                    l13 = ((uint8_t) t0.payload.i);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
                    ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l15] = (uint8_t) (int32_t) (uint8_t) l13;
                    l14 = (l10 < l12);
                    l10 = (l10 + INT64_C(1));
                }
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            l17 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            l19 = vader_vm$effect_of(((vader_struct_vader_vm$TagContext_t*) l0)->f_module, l1, l17);
            if (l19.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l18 = l19.payload.obj;
            l8 = vader_vm$transfer(l0, l17, l5, l4, l8, l18);
            if (l6.tag == 0u) {
                if (((vader_struct_vader_vm$StackEffect_t*) l18)->f_flow == INT32_C(1)) {
                    l21 = true;
                } else {
                    l21 = ((vader_struct_vader_vm$StackEffect_t*) l18)->f_flow == INT32_C(2);
                }
                l20 = l21;
            } else {
                l20 = false;
            }
            if (l20) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
                t4 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l9];
                l22 = ((int64_t) (int32_t) t4);
                if ((l22 < l7)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_block_at);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l22)
                    l23 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l22];
                    vader_vm$merge_block(l2, l23, l8, l5);
                }
            }
            if (((vader_struct_vader_vm$StackEffect_t*) l18)->f_flow != INT32_C(0)) {
                if (((vader_struct_vader_vm$StackEffect_t*) l18)->f_flow != INT32_C(2)) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            l9 = vader_chk_add(i64, l9, INT64_C(1));
            if (!((l9 < l7))) {
                continue;
            }
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_block_at);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
            t2 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9];
            if (!((t2 >= INT64_C(0)))) {
                continue;
            }
            if (l6.tag == 0u) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_block_at);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                l24 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                vader_vm$merge_block(l2, l24, l8, l5);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_vm$widening(vader_string_t l0) {
    bool t0;
    t0 = vader_vm$is_unsigned_source(l0);
    if (!(t0)) {
        return INT32_C(84);
    }
    return INT32_C(85);
}

static void vader_vm$write_float(void* l0, int64_t l1, double l2, int64_t l3) {
    uint64_t l4;
    l4 = vader_vm$float_bits(l2, l3);
    vader_core_bytecode$write_le(l0, l1, l3, l4);
    return;
}

static void vader_vm$write_little_endian(void* l0, int64_t l1, int64_t l2, int64_t l3) {
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

static int64_t vader_vm$zero_extended(void* l0, void* l1, int64_t l2, int32_t l3) {
    int64_t l4;
    vader_box_t t0;
    int64_t t1;
    l4 = ((int64_t) (int32_t) l3);
    l4 = vader_chk_add(i64, l2, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 340u);
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

static vader_box_t vader_vm$zero_value(void) {
    return vader_box_i32(338u, INT32_C(0));
}

static void* vader_vm$zeroed_mirror(int32_t l0, void* l1, void* l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    int64_t l6, l7;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null();
    bool l10;
    int32_t l11, l13, l15;
    uint8_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l9, &l16 };
    void** gc_raw_roots[8] = { &l1, &l2, &l4, &l5, &l8, &l12, &l14, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 0u, 2153u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = vader_core_bytecode$nested_mirror(l8, l2);
        if (!(l9.tag == 0u)) {
            l10 = (l3 < INT32_C(16));
        } else {
            l10 = false;
        }
        if (l10) {
            l11 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
            l12 = l9.payload.obj;
            l13 = vader_chk_add(i32, l3, INT32_C(1));
            l14 = vader_vm$zeroed_mirror(l11, l12, l2, l13);
            vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
        } else {
            l15 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
            t0 = vader_vm$field_valtype(l2, l15);
            l16 = vader_vm$global_zero(t0);
            vader_array_push((vader_array_t*) l4, l16);
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_vm$StructVal_t* _a2_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
    vader_obj_header_init(_a2_obj, 1443u);
    _a2_obj->f_type_id = l0;
    _a2_obj->f_fields = l4;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
