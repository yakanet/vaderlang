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
static vader_box_t vader_vm$after_entry(vader_box_t l0, vader_string_t l1);
static void vader_vm$announce_cancelled(int64_t l0, vader_box_t l1);
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
static uint8_t vader_vm$byte_at(void* l0, int64_t l1);
static void* vader_vm$bytes_to_value(vader_string_t l0, int32_t l1);
static vader_string_t vader_vm$call_foreign(int64_t l0, bool l1, void* l2, void* l3, int64_t l4);
static vader_box_t vader_vm$call_import(void* l0, void* l1, int32_t l2, int64_t l3, int32_t l4, bool l5);
static vader_box_t vader_vm$call_results(void* l0, vader_box_t l1);
static void* vader_vm$call_stack(void* l0, void* l1, int64_t l2, int64_t l3);
static vader_box_t vader_vm$callee_of(void* l0, void* l1, int64_t l2, int32_t l3);
static void vader_vm$cancel(int64_t l0);
static vader_box_t vader_vm$cancel_guest_thread(vader_box_t l0, int32_t l1);
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
static vader_box_t vader_vm$copy_all(void* l0, vader_box_t l1);
static vader_box_t vader_vm$copy_array(void* l0, void* l1);
static vader_box_t vader_vm$copy_each(void* l0, void* l1);
static vader_box_t vader_vm$copy_inside(void* l0, vader_box_t l1);
static vader_box_t vader_vm$copy_object(void* l0, void* l1);
static vader_box_t vader_vm$copy_of(void* l0, vader_box_t l1);
static vader_box_t vader_vm$copy_struct(void* l0, void* l1);
static vader_box_t vader_vm$debug_controller(void* l0);
static vader_box_t vader_vm$debug_session(vader_box_t l0, int32_t l1);
static int64_t vader_vm$debug_std_descriptor(int64_t l0);
static vader_box_t vader_vm$debug_write(void* l0, void* l1, int64_t l2, int32_t l3, void* l4);
static int32_t vader_vm$debugged_thread_id(int64_t l0);
static void* vader_vm$debugged_threads(void* l0);
static vader_box_t vader_vm$deep_copy_value(void* l0, vader_box_t l1, int32_t l2);
static void* vader_vm$defect(void* l0, int64_t l1, vader_string_t l2);
static vader_box_t vader_vm$defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3);
static vader_string_t vader_vm$describe_obj(void* l0);
static vader_string_t vader_vm$describe_value_tag(vader_box_t l0);
static vader_box_t vader_vm$dispatch_extern(void* l0, int32_t l1, void* l2, int64_t l3, int32_t l4, vader_box_t l5);
static vader_box_t vader_vm$dispatch_import(void* l0, void* l1, int64_t l2, void* l3, int32_t l4, int32_t l5, int32_t l6, bool l7, uint8_t l8);
static vader_string_t vader_vm$display_tags(uint8_t l0);
static vader_string_t vader_vm$display_value(vader_box_t l0);
static vader_box_t vader_vm$do_memory_copy(void* l0);
static void vader_vm$drop_last_op(void* l0);
static void* vader_vm$effect(int64_t l0, int64_t l1);
static vader_box_t vader_vm$effect_of(void* l0, void* l1, vader_box_t l2);
static vader_string_t vader_vm$element_label(int32_t l0);
static uint8_t vader_vm$element_tags(void* l0, int32_t l1);
static void* vader_vm$element_trap(void* l0, int64_t l1, int32_t l2, int32_t l3, void* l4, int64_t l5, int32_t l6);
static void vader_vm$emit(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static void* vader_vm$empty_machine(vader_box_t l0);
static void vader_vm$enter_frame(void* l0, void* l1, int64_t l2);
static vader_box_t vader_vm$entry_named(void* l0, vader_string_t l1);
static int64_t vader_vm$environment_params(void* l0);
static void* vader_vm$exception_stop(vader_string_t l0, int32_t l1, void* l2);
static vader_box_t vader_vm$exec_array_copy(void* l0);
static vader_box_t vader_vm$exec_array_push_all(void* l0);
static vader_box_t vader_vm$exec_array_repeat(void* l0);
static vader_box_t vader_vm$exec_array_reserve(void* l0, void* l1);
static vader_box_t vader_vm$exec_array_slice(void* l0, void* l1);
static vader_box_t vader_vm$exec_buffer_write_string(void* l0);
static vader_box_t vader_vm$exec_string_compare(void* l0);
static vader_box_t vader_vm$extern_result(uint8_t l0, int64_t l1);
static vader_box_t vader_vm$extern_word(vader_box_t l0, int32_t l1, vader_string_t l2, int64_t l3);
static double vader_vm$f64_of(void* l0, int64_t l1, int32_t l2);
static int32_t vader_vm$ffi_result_class(uint8_t l0, bool l1);
static bool vader_vm$ffi_result_is_opt(void* l0, int32_t l1, uint8_t l2);
static uint8_t vader_vm$field_tags(void* l0, int32_t l1, int32_t l2);
static uint8_t vader_vm$field_val_type(void* l0, void* l1);
static int32_t vader_vm$find_string_array_type_id(void* l0);
static int32_t vader_vm$find_u8_array_type_id(void* l0);
static void* vader_vm$finish_guest_threads(bool l0, vader_box_t l1);
static vader_box_t vader_vm$finish_run(void* l0, bool l1, vader_box_t l2);
static void* vader_vm$first_bytes(void* l0, int64_t l1);
static bool vader_vm$fits_signed(int32_t l0, int64_t l1);
static uint64_t vader_vm$float_bits(double l0, int64_t l1);
static vader_box_t vader_vm$flow_to(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5, int64_t l6);
static void vader_vm$flush(void* l0, int64_t l1);
static void* vader_vm$fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_vm$fn_type_of(void* l0, int32_t l1);
static vader_box_t vader_vm$foreign_call_of(void* l0, int32_t l1, int32_t l2);
static void* vader_vm$frame_names(void* l0);
static vader_box_t vader_vm$fused_branch(int32_t l0, bool l1);
static void* vader_vm$global_at_comptime_trap(void* l0, int32_t l1);
static uint8_t vader_vm$global_tags(void* l0, int32_t l1);
static void vader_vm$grow_frame_records(void* l0, void* l1, int64_t l2, int64_t l3);
static void* vader_vm$guest_threads(void);
static void* vader_vm$guest_threads$singleton(void);
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
static bool vader_vm$is_boxed(vader_box_t l0);
static bool vader_vm$is_covered_variadic(int64_t l0, int64_t l1, int64_t l2);
static bool vader_vm$is_fn_index_out_of_range(int32_t l0, void* l1);
static bool vader_vm$is_i32_tag(uint8_t l0);
static bool vader_vm$is_inline_leaf(void* l0);
static bool vader_vm$is_integer_alias(uint8_t l0);
static bool vader_vm$is_leaving(void* l0, void* l1);
static bool vader_vm$is_overflow_trap_message(vader_string_t l0);
static bool vader_vm$is_source_local(vader_string_t l0);
static bool vader_vm$is_std_handle_symbol(vader_string_t l0);
static bool vader_vm$is_unsigned_source(vader_string_t l0);
static bool vader_vm$is_write_symbol(vader_string_t l0);
static void vader_vm$jump(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static vader_box_t vader_vm$lent_element_val_type(void* l0, int32_t l1);
static bool vader_vm$line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_vm$load_bytes_op(void* l0, int64_t l1, vader_string_t l2);
static int32_t vader_vm$lookup_vtable_row(void* l0, int32_t l1, int32_t l2);
static void* vader_vm$main_thread(void* l0);
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
static int32_t vader_vm$note(void* l0, vader_box_t l1, int32_t l2, vader_box_t l3);
static void vader_vm$note_checked_kind(void* l0, vader_box_t l1);
static void vader_vm$note_entry_thread(void* l0);
static void vader_vm$note_host_call(void* l0, int64_t l1, int64_t l2);
static vader_box_t vader_vm$on_i64(vader_box_t l0, int32_t l1, vader_string_t l2, void* l3);
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
static vader_box_t vader_vm$parked(void);
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
static void vader_vm$restore(void* l0);
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
static vader_box_t vader_vm$serve_import(void* l0, void* l1, int32_t l2, void* l3, void* l4, int32_t l5, bool l6);
static vader_box_t vader_vm$serve_thread_primitive(void* l0, void* l1, uint8_t l2, void* l3, int32_t l4, bool l5);
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
static vader_box_t vader_vm$start_guest_thread(void* l0, vader_box_t l1, bool l2, vader_box_t l3);
static bool vader_vm$step_should_stop(uint8_t l0, int32_t l1, int32_t l2);
static void vader_vm$stop_at_line(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5);
static vader_box_t vader_vm$store_bytes_op(void* l0, int64_t l1, uint64_t l2, vader_string_t l3);
static void vader_vm$store_slot(void* l0, void* l1, int64_t l2, int32_t l3, bool l4, int64_t l5);
static void* vader_vm$string_array_to_value(void* l0, int32_t l1);
static vader_box_t vader_vm$string_at(void* l0, int64_t l1);
static bool vader_vm$string_byte_op(void* l0, int64_t l1, uint8_t l2);
static void vader_vm$string_constant(void* l0, void* l1, int64_t l2, void* l3);
static vader_box_t vader_vm$struct_at(void* l0, int64_t l1);
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
static int32_t vader_vm$type_operand(vader_box_t l0);
static uint8_t vader_vm$type_tags(void* l0, int32_t l1, int32_t l2);
static uint32_t vader_vm$u32_of(void* l0, int64_t l1, int32_t l2);
static uint64_t vader_vm$u64_of(void* l0, int64_t l1, int32_t l2);
static vader_box_t vader_vm$unary_op(void* l0, vader_box_t l1, void* l2, int64_t l3);
static bool vader_vm$union_matches(void* l0, vader_box_t l1, void* l2);
static vader_string_t vader_vm$unopened_reason(void* l0);
static vader_box_t vader_vm$validate_fn_index(int32_t l0, void* l1, int32_t l2, vader_string_t l3);
static vader_box_t vader_vm$value_from_bits(uint8_t l0, uint64_t l1);
static bool vader_vm$value_ref_eq(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_vm$verify_function(void* l0, void* l1);
static vader_box_t vader_vm$verify_module(void* l0);
static void* vader_vm$view_of(void* l0, int32_t l1, int64_t l2, int64_t l3);
static vader_box_t vader_vm$void_result(void);
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
    int64_t l2, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 494u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 857u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 1019u);
    l2 = INT64_C(0);
    l3 = vader_vm$element_count(l0);
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string__builder$append(l1, 383u);
        }
        t1 = vader_vm$element_at(l0, l2);
        l4 = vader_vm$display_value(t1);
        std_string__builder$append(l1, l4);
        l2 = (l2 + INT64_C(1));
    }
    std_string__builder$append(l1, 1024u);
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$BoolVal$std_core$Display$to_string(bool l0) {
    if (l0) {
        return 2914u;
    }
    return 2071u;
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
        l2 = std_core$write_string_at(l1, l2, 549u);
        t0 = ((vader_struct_vader_vm$FnVal_t*) l0)->f_function_index;
        l3 = ((int64_t) (int32_t) t0);
        l2 = std_core$write_int(l1, l2, l3);
        l2 = std_core$write_string_at(l1, l2, 563u);
        t1 = std_core$finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 549u);
    t0 = ((vader_struct_vader_vm$FnVal_t*) l0)->f_function_index;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 380u);
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
    return 2532u;
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
    if (l1.tag == 1709u) {
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 494u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 857u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l3 = INT64_C(0);
    t1 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
    l4 = ((int64_t) (int32_t) t1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3252u);
    l5 = std_core$finish_buffer(l2, l3);
    std_string__builder$append(l1, l5);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l1, 383u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
        l5 = vader_vm$display_value(t2);
        std_string__builder$append(l1, l5);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append(l1, 259u);
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
    l2 = std_core$write_string_at(l1, l2, 555u);
    t0 = ((vader_struct_vader_vm$TypeVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 563u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$accepted_tags(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    void* t0;
    uint8_t t1;
    if ((l0.tag == 1032u || l0.tag == 1033u || l0.tag == 1035u || l0.tag == 1036u || l0.tag == 1038u || l0.tag == 1040u || l0.tag == 1041u || l0.tag == 1042u || l0.tag == 1043u || l0.tag == 1044u || l0.tag == 1045u || l0.tag == 1048u || l0.tag == 1049u || l0.tag == 1050u || l0.tag == 1051u || l0.tag == 1112u || l0.tag == 1113u || l0.tag == 1114u || l0.tag == 1115u || l0.tag == 1116u || l0.tag == 1117u)) {
        l2 = vader_box_i32(499u, INT32_C(19));
        return l2;
    }
    if ((l0.tag == 1034u || l0.tag == 1047u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(499u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 1039u || l0.tag == 1046u)) {
        l2 = vader_box_i32(499u, (INT32_C(19) | INT32_C(32)));
    } else if ((l0.tag == 1052u || l0.tag == 1053u || l0.tag == 1055u || l0.tag == 1056u || l0.tag == 1058u || l0.tag == 1059u || l0.tag == 1060u || l0.tag == 1061u || l0.tag == 1062u || l0.tag == 1063u || l0.tag == 1064u || l0.tag == 1065u || l0.tag == 1066u || l0.tag == 1068u || l0.tag == 1069u || l0.tag == 1070u || l0.tag == 1071u || l0.tag == 1118u || l0.tag == 1119u || l0.tag == 1120u || l0.tag == 1121u || l0.tag == 1122u || l0.tag == 1123u)) {
        l2 = vader_box_i32(499u, INT32_C(3));
    } else if ((l0.tag == 1054u || l0.tag == 1067u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(499u, INT32_C(3));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 1015u || l0.tag == 1017u || l0.tag == 1018u || l0.tag == 1019u || l0.tag == 1020u || l0.tag == 1021u || l0.tag == 1022u || l0.tag == 1023u || l0.tag == 1024u || l0.tag == 1026u)) {
        l2 = vader_box_i32(499u, INT32_C(4));
    } else if (l0.tag == 1025u) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(499u, INT32_C(4));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1004u) {
        t0 = l0.payload.obj;
        t1 = vader_vm$integer_operand_tags(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        l2 = vader_box_i32(499u, (int32_t)(uint32_t) t1);
    } else if (l0.tag == 1005u) {
        if (l1 == INT64_C(1)) {
            t0 = l0.payload.obj;
            t1 = vader_vm$integer_operand_tags(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
            l2 = vader_box_i32(499u, (int32_t)(uint32_t) t1);
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 954u || l0.tag == 1077u || l0.tag == 1078u || l0.tag == 1079u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(499u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 962u || l0.tag == 1099u || l0.tag == 1100u || l0.tag == 1101u)) {
        if (l1 == INT64_C(2)) {
            l2 = vader_box_i32(499u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else {
        if (!((l0.tag == 952u || l0.tag == 953u || l0.tag == 955u || l0.tag == 956u || l0.tag == 957u || l0.tag == 958u || l0.tag == 959u || l0.tag == 960u || l0.tag == 961u || l0.tag == 963u || l0.tag == 984u || l0.tag == 985u || l0.tag == 986u || l0.tag == 987u || l0.tag == 988u || l0.tag == 989u || l0.tag == 990u || l0.tag == 991u || l0.tag == 992u || l0.tag == 993u || l0.tag == 994u || l0.tag == 995u || l0.tag == 996u || l0.tag == 997u || l0.tag == 1000u || l0.tag == 1001u || l0.tag == 1002u || l0.tag == 1003u || l0.tag == 1006u || l0.tag == 1007u || l0.tag == 1009u || l0.tag == 1010u || l0.tag == 1011u || l0.tag == 1012u || l0.tag == 1013u || l0.tag == 1014u || l0.tag == 1016u || l0.tag == 1027u || l0.tag == 1028u || l0.tag == 1029u || l0.tag == 1030u || l0.tag == 1031u || l0.tag == 1037u || l0.tag == 1057u || l0.tag == 1072u || l0.tag == 1074u || l0.tag == 1075u || l0.tag == 1076u || l0.tag == 1080u || l0.tag == 1081u || l0.tag == 1082u || l0.tag == 1083u || l0.tag == 1084u || l0.tag == 1085u || l0.tag == 1086u || l0.tag == 1087u || l0.tag == 1088u || l0.tag == 1089u || l0.tag == 1090u || l0.tag == 1091u || l0.tag == 1092u || l0.tag == 1093u || l0.tag == 1094u || l0.tag == 1095u || l0.tag == 1096u || l0.tag == 1097u || l0.tag == 1098u || l0.tag == 1102u || l0.tag == 1103u || l0.tag == 1104u || l0.tag == 1105u || l0.tag == 1106u || l0.tag == 1107u || l0.tag == 1108u || l0.tag == 1109u || l0.tag == 1110u || l0.tag == 1111u || l0.tag == 1124u || l0.tag == 1125u || l0.tag == 1126u || l0.tag == 1127u))) {
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
            t2 = concat_3(2330u, l3, 1305u);
            { vader_box_t __vret = vader_box_string(494u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params)->length;
    if ((t1 > INT64_C(8))) {
        { vader_box_t __vret = vader_box_string(494u, 2324u); vader_gc_top = gc_frame.prev; return __vret; }
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
                l12 = std_core$write_string_at(l11, l12, 1641u);
                l12 = std_core$write_int(l11, l12, l7);
                l12 = std_core$write_string_at(l11, l12, 212u);
                t2 = std_core$finish_buffer(l11, l12);
                { vader_box_t __vret = vader_box_string(494u, t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l7, 499u);
        if (((int32_t) t3.payload.i) == INT32_C(8)) {
            l13 = (void*) vader_buffer_new((size_t) INT64_C(41));
            l14 = INT64_C(0);
            l14 = std_core$write_string_at(l13, l14, 1641u);
            l14 = std_core$write_int(l13, l14, l7);
            l14 = std_core$write_string_at(l13, l14, 158u);
            t2 = std_core$finish_buffer(l13, l14);
            { vader_box_t __vret = vader_box_string(494u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t3 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l7, 499u);
        if (((int32_t) t3.payload.i) == INT32_C(11)) {
            l15 = (void*) vader_buffer_new((size_t) INT64_C(41));
            l16 = INT64_C(0);
            l16 = std_core$write_string_at(l15, l16, 1641u);
            l16 = std_core$write_int(l15, l16, l7);
            l16 = std_core$write_string_at(l15, l16, 153u);
            t2 = std_core$finish_buffer(l15, l16);
            { vader_box_t __vret = vader_box_string(494u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t3 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 499u);
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
        { vader_box_t __vret = vader_box_string(494u, 2321u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l18 == INT32_C(8)) {
        { vader_box_t __vret = vader_box_string(494u, 2322u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l6 > INT64_C(0))) {
        if ((l5 > INT64_C(0))) {
            { vader_box_t __vret = vader_box_string(494u, 2320u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if ((l6 > INT64_C(2))) {
        { vader_box_t __vret = vader_box_string(494u, 2325u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT64_C(0)) {
        if (l18 == INT32_C(9)) {
            { vader_box_t __vret = vader_box_string(494u, 2323u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if ((l6 > INT64_C(0))) {
        if (l18 != INT32_C(9)) {
            { vader_box_t __vret = vader_box_string(494u, 2331u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
    if ((t4 >= INT32_C(0))) {
        t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
        l5 = ((int64_t) (int32_t) t4);
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params)->length;
        t5 = vader_vm$is_covered_variadic(l5, l7, l6);
        if (!(t5)) {
            { vader_box_t __vret = vader_box_string(494u, 2336u); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_vm$scalar_of(l0);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l5.payload.obj;
    l6 = ((vader_array_t*) l1)->length;
    t0 = std_collections$put_absent__vader_vm_Scalar__i64(l3, l4, l6);
    if (t0.tag == 0u) {
        l6 = ((vader_struct_vader_vm$Scalar_t*) l4)->f_bits;
        vader_array_push_i64((vader_array_t*) l1, l6);
        l7 = ((vader_struct_vader_vm$Scalar_t*) l4)->f_tag;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$after_entry(vader_box_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l2, &l3, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l6, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$finish_guest_threads(false, vader_box_obj(0u, NULL));
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1698u) {
        t0 = ((vader_array_t*) l2)->length;
        vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) t0, 0u, 494u);
        l3 = (void*) _a0_arr;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
            l6 = __lambda_vader_vm_5(t0);
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(494u, l6));
            l5 = (l5 + INT64_C(1));
        }
        t1 = std_string$join(l3, 383u);
        t2 = concat_4(t1, 228u, l1, 222u);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 1716u);
        _a2_obj->f_message = t2;
        t3 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$announce_cancelled(int64_t l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) vader_buffer_new((size_t) INT64_C(73));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 3029u);
    l4 = std_core$write_int(l3, l4, l0);
    l4 = std_core$write_string_at(l3, l4, 229u);
    l2 = std_core$finish_buffer(l3, l4);
    if (l1.tag == 0u) {
        std_io$eprintln__string(l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_vm$DebugController_t*) t0)->f_output_sink;
    l2 = concat_2(l2, 1u);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
    ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(497u, INT32_C(1)), vader_box_string(494u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4, bool l5) {
    int64_t l6, l15;
    void* l7 = NULL;
    int32_t l8, l10;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null();
    uint8_t l11;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    bool l16, l17;
    uint64_t l18;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2, t7;
    bool t3;
    vader_string_t t4 = 0;
    vader_box_t t5 = vader_box_null();
    uint64_t t6;
    double t8;
    vader_box_t* gc_roots[4] = { &l2, &l9, &l13, &t5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l12, &l14, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1029u) {
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        vader_struct_vader_vm$FnVal_t* _a0_obj = (vader_struct_vader_vm$FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FnVal_t));
        vader_obj_header_init(_a0_obj, 1686u);
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
    if (l2.tag == 1086u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_owned(l3, l6);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        vader_struct_vader_vm$FnVal_t* _a1_obj = (vader_struct_vader_vm$FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FnVal_t));
        vader_obj_header_init(_a1_obj, 1686u);
        _a1_obj->f_function_index = t1;
        _a1_obj->f_env = l9;
        l7 = (void*) _a1_obj;
        vader_vm$push_val(l3, l6, vader_ref_box(l7));
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1108u) {
        l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l9 = vader_vm$build_struct(l7, l8, l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 956u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l9 = vader_vm$build_array(l8, l10, l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 963u) {
        l7 = l2.payload.obj;
        l9 = vader_vm$exec_array_slice(l3, l7);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 961u) {
        l7 = l2.payload.obj;
        l9 = vader_vm$exec_array_reserve(l3, l7);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 960u) {
        l9 = vader_vm$exec_array_repeat(l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 958u) {
        l9 = vader_vm$exec_array_push_all(l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 953u) {
        l9 = vader_vm$exec_array_copy(l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 959u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$peek_array_mut(l3, l6, l8, 1670u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        if (!(((vader_struct_vader_vm$ArrayVal_t*) t0)->f_raw.tag == 0u)) {
            t0 = l9.payload.obj;
            vader_vm$own_bytes(t0);
        }
        t0 = l9.payload.obj;
        l9 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
        if (l9.tag == 0u) {
            l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(5);
        } else {
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_vm$push_val(l3, l6, l9);
        }
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 952u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$peek_array_mut(l3, l6, l8, 1652u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_raw = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) t0);
        t0 = l9.payload.obj;
        vader_array_clear((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1030u) {
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
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        l9 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l8];
        vader_vm$push_val(l3, l6, l9);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1031u) {
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
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8] = l9;
        VADER_WRITE_BARRIER(_a4_slotarr->buf);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1007u) {
        l7 = ((vader_struct_vader_vm$VmState_t*) l0)->f_data_pool;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l7 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
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
            l7 = ((vader_struct_vader_vm$ArrayVal_t*) l7)->f_elements;
            vader_struct_vader_vm$ArrayVal_t* _a6_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
            vader_obj_header_init(_a6_obj, 1681u);
            _a6_obj->f_type_id = l8;
            _a6_obj->f_elements = l7;
            _a6_obj->f_raw = vader_box_obj(0u, NULL);
            l7 = (void*) _a6_obj;
            vader_vm$push_val(l3, l6, vader_ref_box(l7));
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1006u) {
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
        t0 = l2.payload.obj;
        l12 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t3 = vader_vm$convert_int_fast(l3, l11, l12);
        if (!(t3)) {
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            l9 = vader_vm$peek_val(l3, l6);
            t0 = l2.payload.obj;
            l11 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
            t0 = l2.payload.obj;
            l12 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
            l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l13 = vader_vm$convert_value(l9, l11, l12, l8);
            if (l13.tag == 1716u) {
                t0 = l13.payload.obj;
                l12 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
                l14 = vader_vm$describe_value_tag(l9);
                t4 = concat_6(l12, 53u, l14, 353u, l4, 307u);
                vader_struct_vader_vm$Trap_t* _a7_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a7_obj, 1716u);
                _a7_obj->f_message = t4;
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l6 = vader_chk_sub(i64, t2, INT64_C(1));
            l9 = l13;
            vader_vm$push_val(l3, l6, l9);
        }
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1095u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        if (!(l9.tag == 1717u)) {
            l12 = vader_vm$describe_value_tag(l9);
            l6 = vader_host_std_core$byte_len(l12);
            l7 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l6));
            l6 = INT64_C(0);
            l6 = std_core$write_string_at(l7, l6, 2295u);
            l6 = std_core$write_string_at(l7, l6, l12);
            l6 = std_core$write_string_at(l7, l6, 99u);
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l15 = ((int64_t) (int32_t) t1);
            l6 = std_core$write_int(l7, l6, l15);
            t4 = std_core$finish_buffer(l7, l6);
            vader_struct_vader_vm$Trap_t* _a8_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a8_obj, 1716u);
            _a8_obj->f_message = t4;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        l8 = ((vader_struct_vader_vm$TypeVal_t*) t0)->f_type_id;
        if ((l8 < INT32_C(0))) {
            l16 = true;
        } else {
            l6 = ((int64_t) (int32_t) l8);
            l15 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types)->length;
            l16 = (l6 >= l15);
        }
        if (l16) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(89));
            l6 = INT64_C(0);
            l6 = std_core$write_string_at(l7, l6, 2296u);
            l15 = ((int64_t) (int32_t) l8);
            l6 = std_core$write_int(l7, l6, l15);
            l6 = std_core$write_string_at(l7, l6, 204u);
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l15 = ((int64_t) (int32_t) t1);
            l6 = std_core$write_int(l7, l6, l15);
            t4 = std_core$finish_buffer(l7, l6);
            vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a9_obj, 1716u);
            _a9_obj->f_message = t4;
            t0 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
        t5 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l8);
        l8 = vader_core_bytecode$size_of_bc_type(t5);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l15 = ((int64_t) (int32_t) l8);
        vader_array_t* _a11_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
        ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1039u) {
        l9 = vader_vm$apply_eq_binop(l3, 2190u, false);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1046u) {
        l9 = vader_vm$apply_eq_binop(l3, 2197u, true);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 989u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1715u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_bool(l13, l8, 1715u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l16 = l9.payload.b;
        l17 = l13.payload.b;
        if (l16 == l17) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
        ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 990u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1716u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_bool(l13, l8, 1716u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l16 = l9.payload.b;
        l17 = l13.payload.b;
        if (l16 != l17) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
        ((int64_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 987u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1713u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_bool(l13, l8, 1713u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t3 = l9.payload.b;
        if (t3) {
            l16 = l13.payload.b;
        } else {
            l16 = false;
        }
        if (l16) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
        ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 992u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1718u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_bool(l13, l8, 1718u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t3 = l9.payload.b;
        if (t3) {
            l16 = true;
        } else {
            l16 = l13.payload.b;
        }
        if (l16) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a19_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
        ((int64_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 991u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_bool(l9, l8, 1717u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t3 = l9.payload.b;
        if (t3) {
            l15 = INT64_C(0);
        } else {
            l15 = INT64_C(1);
        }
        vader_array_t* _a21_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
        ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a22_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l6)
        ((uint8_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1105u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_string(l9, l8, 2808u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_string(l13, l8, 2808u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l12 = l9.payload.s;
        l14 = l13.payload.s;
        if (l12 == l14) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
        ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a24_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
        ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1106u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_string(l9, l8, 2810u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_string(l13, l8, 2810u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l12 = l9.payload.s;
        l14 = l13.payload.s;
        if (l12 != l14) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l6)
        ((int64_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 1103u) {
        l9 = vader_vm$exec_string_compare(l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1090u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l16 = vader_vm$value_ref_eq(l9, l13);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        if (l16) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a27_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l6)
        ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 1091u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l9 = vader_vm$peek_val(l3, l6);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l13 = vader_vm$peek_val(l3, l6);
        l16 = vader_vm$value_ref_eq(l9, l13);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        if (l16) {
            l15 = INT64_C(0);
        } else {
            l15 = INT64_C(1);
        }
        vader_array_t* _a29_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l6)
        ((int64_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 1110u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        l16 = vader_vm$type_matches(l0, l9, l8);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        if (l16) {
            l15 = INT64_C(1);
        } else {
            l15 = INT64_C(0);
        }
        vader_array_t* _a31_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l6)
        ((int64_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a32_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l6)
        ((uint8_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1111u) {
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        vader_struct_vader_vm$TypeVal_t* _a33_obj = (vader_struct_vader_vm$TypeVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$TypeVal_t));
        vader_obj_header_init(_a33_obj, 1717u);
        _a33_obj->f_type_id = t1;
        l7 = (void*) _a33_obj;
        vader_vm$push_val(l3, l6, vader_ref_box(l7));
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 995u) {
        l7 = ((vader_struct_vader_vm$RunHost_t*) l1)->f_obj_handles;
        l9 = vader_vm$build_buffer(l3, l7);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1080u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(1), 2388u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l15 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t6));
        vader_array_t* _a34_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l6)
        ((int64_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a35_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l6)
        ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1075u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(4), 2382u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l15 = ((int64_t) (int32_t) ((int32_t) (uint64_t) t6));
        vader_array_t* _a36_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
        ((int64_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l6] = (int64_t) l15;
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
    } else if (l2.tag == 1076u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(8), 2383u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l15 = ((int64_t) (uint64_t) t6);
        vader_array_t* _a38_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l6)
        ((int64_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a39_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l6)
        ((uint8_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1074u) {
        l9 = vader_vm$load_bytes_op(l3, INT64_C(8), 2381u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t6 = ((uint64_t) l9.payload.i);
        l15 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t6) }).__vd) }).__vu);
        vader_array_t* _a40_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l6)
        ((int64_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        vader_array_t* _a41_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l6)
        ((uint8_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1102u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$stack_i32(l3, l6, 2801u, 3167u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l9.payload.i);
        t2 = ((int64_t) (uint32_t) (t1 & INT32_C(255)));
        l18 = (uint64_t) (int64_t) t2;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(1), l18, 2801u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1097u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$stack_i32(l3, l6, 2794u, 3167u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int32_t) l9.payload.i);
        t2 = ((int64_t) (uint32_t) t1);
        l18 = (uint64_t) (int64_t) t2;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(4), l18, 2794u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1098u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i64(l9, l8, 2796u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int64_t) l9.payload.i);
        t7 = t2;
        l18 = (uint64_t) (int64_t) t7;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(8), l18, 2795u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1096u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_f64(l9, l8, 2793u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t8 = ((double) l9.payload.f);
        t2 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
        l18 = (uint64_t) (int64_t) t2;
        l9 = vader_vm$store_bytes_op(l3, INT64_C(8), l18, 2792u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1087u) {
        l9 = vader_vm$do_memory_copy(l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 996u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i32(l9, l8, 1738u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        l13 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l13 = vader_vm$read_obj(l13, l8, 1739u);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((int32_t) l9.payload.i);
        t0 = l13.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t0)->f_bytes)->length;
        l10 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$check_byte_range(l8, INT64_C(0), l6, 1737u, l10);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(2));
        t0 = l13.payload.obj;
        l7 = ((vader_struct_vader_vm$ObjVal_t*) t0)->f_bytes;
        l15 = ((int64_t) l9.payload.i);
        vader_array_t* _a42_arr = vader_array_slice((vader_array_t*) l7, (int64_t) INT64_C(0), (int64_t) l15);
        t0 = (void*) _a42_arr;
        l12 = vader_host_std_core$bytes_to_string(t0);
        vader_vm$push_val(l3, l6, vader_box_string(494u, l12));
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l6;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 997u) {
        l9 = vader_vm$exec_buffer_write_string(l3);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1027u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_f64(l9, l8, 2068u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t8 = ((double) l9.payload.f);
        l15 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
        vader_array_t* _a43_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l6)
        ((int64_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a44_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l6)
        ((uint8_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 985u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i64(l9, l8, 1709u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t2 = ((int64_t) l9.payload.i);
        l15 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t2) }).__vd) }).__vu);
        vader_array_t* _a45_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l6)
        ((int64_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a46_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l6)
        ((uint8_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 1014u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_f64(l9, l8, 2054u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t8 = ((double) l9.payload.f);
        l15 = ((int64_t) (int32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = t8 }).__vb));
        vader_array_t* _a47_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l6)
        ((int64_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a48_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l6)
        ((uint8_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(0);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l8;
    } else if (l2.tag == 984u) {
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        l9 = vader_vm$peek_val(l3, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l9 = vader_vm$read_i32(l9, l8, 1708u);
        if (l9.tag == 1716u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        t1 = ((int32_t) l9.payload.i);
        l15 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(t1) }).__vf)) }).__vu);
        vader_array_t* _a49_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l6)
        ((int64_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l6] = (int64_t) l15;
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l6 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a50_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l6)
        ((uint8_t*) _a50_slotarr->buf->slots)[_a50_slotarr->offset + (size_t) l6] = (uint8_t) INT32_C(2);
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
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 499u);
    l5 = ((uint8_t) t1.payload.i);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 499u);
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
            if (l11.tag == 1716u) {
                t3 = l11.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l12.tag == 1716u) {
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 1681u) {
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
    int64_t l6;
    uint8_t l7;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l4, &t2 };
    void** gc_raw_roots[4] = { &l0, &l5, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        t1 = vader_vm$first_bytes(t0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 499u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        l4 = vader_vm$read_i64(t2, l2, l3);
        if (l4.tag == 1716u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((int64_t) l4.payload.i);
        t4 = (((int32_t) (int64_t) t3) & INT32_C(255));
        l7 = (uint8_t) (int32_t) t4;
        vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l7);
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
    if (l0.tag == 982u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        { vader_box_t __vret = vader_box_string(494u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 981u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t2 = vader_vm$value_from_bits(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 983u) {
        vader_array_t* _a0_arr = vader_array_new(414u, 0u, 0u, 2456u);
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
        vader_obj_header_init(_a2_obj, 1713u);
        _a2_obj->f_type_id = t3;
        _a2_obj->f_fields = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 980u)) {
        { vader_box_t __vret = vader_box_i32(497u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(414u, 0u, 0u, 2456u);
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
    t0 = l0.payload.obj;
    t3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a5_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a5_obj, 1681u);
    _a5_obj->f_type_id = t3;
    _a5_obj->f_elements = l4;
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
    if (l0.tag == 1032u) {
        l3 = vader_box_i32(497u, INT32_C(2));
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1051u) {
        l3 = vader_box_i32(497u, INT32_C(3));
    } else if (l0.tag == 1045u) {
        l3 = vader_box_i32(497u, INT32_C(4));
    } else if (l0.tag == 1038u) {
        l3 = vader_box_i32(497u, INT32_C(5));
    } else if (l0.tag == 1044u) {
        l3 = vader_box_i32(497u, INT32_C(6));
    } else if (l0.tag == 1033u) {
        l3 = vader_box_i32(497u, INT32_C(7));
    } else if (l0.tag == 1035u) {
        l3 = vader_box_i32(497u, INT32_C(8));
    } else if (l0.tag == 1036u) {
        l3 = vader_box_i32(497u, INT32_C(9));
    } else if (l0.tag == 1048u) {
        l3 = vader_box_i32(497u, INT32_C(10));
    } else if (l0.tag == 1049u) {
        l3 = vader_box_i32(497u, INT32_C(11));
    } else if (l0.tag == 1050u) {
        l3 = vader_box_i32(497u, INT32_C(12));
    } else if (l0.tag == 1112u) {
        l3 = vader_box_i32(497u, INT32_C(15));
    } else if (l0.tag == 1117u) {
        l3 = vader_box_i32(497u, INT32_C(16));
    } else if (l0.tag == 1039u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(497u, INT32_C(17));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1046u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(497u, INT32_C(18));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1043u) {
        l3 = vader_box_i32(497u, INT32_C(19));
    } else if (l0.tag == 1042u) {
        l3 = vader_box_i32(497u, INT32_C(20));
    } else if (l0.tag == 1041u) {
        l3 = vader_box_i32(497u, INT32_C(21));
    } else if (l0.tag == 1040u) {
        l3 = vader_box_i32(497u, INT32_C(22));
    } else if (l0.tag == 1116u) {
        l3 = vader_box_i32(497u, INT32_C(23));
    } else if (l0.tag == 1115u) {
        l3 = vader_box_i32(497u, INT32_C(24));
    } else if (l0.tag == 1114u) {
        l3 = vader_box_i32(497u, INT32_C(25));
    } else if (l0.tag == 1113u) {
        l3 = vader_box_i32(497u, INT32_C(26));
    } else if (l0.tag == 1052u) {
        l3 = vader_box_i32(497u, INT32_C(27));
    } else if (l0.tag == 1071u) {
        l3 = vader_box_i32(497u, INT32_C(28));
    } else if (l0.tag == 1065u) {
        l3 = vader_box_i32(497u, INT32_C(29));
    } else if (l0.tag == 1058u) {
        l3 = vader_box_i32(497u, INT32_C(30));
    } else if (l0.tag == 1064u) {
        l3 = vader_box_i32(497u, INT32_C(31));
    } else if (l0.tag == 1053u) {
        l3 = vader_box_i32(497u, INT32_C(32));
    } else if (l0.tag == 1055u) {
        l3 = vader_box_i32(497u, INT32_C(33));
    } else if (l0.tag == 1056u) {
        l3 = vader_box_i32(497u, INT32_C(34));
    } else if (l0.tag == 1068u) {
        l3 = vader_box_i32(497u, INT32_C(35));
    } else if (l0.tag == 1069u) {
        l3 = vader_box_i32(497u, INT32_C(36));
    } else if (l0.tag == 1070u) {
        l3 = vader_box_i32(497u, INT32_C(37));
    } else if (l0.tag == 1118u) {
        l3 = vader_box_i32(497u, INT32_C(40));
    } else if (l0.tag == 1123u) {
        l3 = vader_box_i32(497u, INT32_C(41));
    } else if (l0.tag == 1059u) {
        l3 = vader_box_i32(497u, INT32_C(42));
    } else if (l0.tag == 1066u) {
        l3 = vader_box_i32(497u, INT32_C(43));
    } else if (l0.tag == 1063u) {
        l3 = vader_box_i32(497u, INT32_C(44));
    } else if (l0.tag == 1062u) {
        l3 = vader_box_i32(497u, INT32_C(45));
    } else if (l0.tag == 1061u) {
        l3 = vader_box_i32(497u, INT32_C(46));
    } else if (l0.tag == 1060u) {
        l3 = vader_box_i32(497u, INT32_C(47));
    } else if (l0.tag == 1122u) {
        l3 = vader_box_i32(497u, INT32_C(48));
    } else if (l0.tag == 1121u) {
        l3 = vader_box_i32(497u, INT32_C(49));
    } else if (l0.tag == 1120u) {
        l3 = vader_box_i32(497u, INT32_C(50));
    } else if (l0.tag == 1119u) {
        l3 = vader_box_i32(497u, INT32_C(51));
    } else if (l0.tag == 1015u) {
        l3 = vader_box_i32(497u, INT32_C(52));
    } else if (l0.tag == 1026u) {
        l3 = vader_box_i32(497u, INT32_C(53));
    } else if (l0.tag == 1023u) {
        l3 = vader_box_i32(497u, INT32_C(54));
    } else if (l0.tag == 1017u) {
        l3 = vader_box_i32(497u, INT32_C(55));
    } else if (l0.tag == 1018u) {
        l3 = vader_box_i32(497u, INT32_C(57));
    } else if (l0.tag == 1024u) {
        l3 = vader_box_i32(497u, INT32_C(58));
    } else if (l0.tag == 1022u) {
        l3 = vader_box_i32(497u, INT32_C(59));
    } else if (l0.tag == 1021u) {
        l3 = vader_box_i32(497u, INT32_C(60));
    } else if (l0.tag == 1020u) {
        l3 = vader_box_i32(497u, INT32_C(61));
    } else if (l0.tag == 1019u) {
        l3 = vader_box_i32(497u, INT32_C(62));
    } else if (l0.tag == 989u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(497u, INT32_C(63));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 990u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(497u, INT32_C(64));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 987u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(497u, INT32_C(65));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 992u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(497u, INT32_C(66));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1004u) {
        t1 = l0.payload.obj;
        t2 = vader_vm$checked_register_op(t1);
        l3 = vader_box_i32(497u, t2);
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
    vader_vm$emit(l0, l1, INT32_C(120), l6, l5, l7);
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
        vader_obj_header_init(_a0_obj, 1690u);
        _a0_obj->f_op = l1;
        _a0_obj->f_swap = l2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$FusedBranch_t* _a1_obj = (vader_struct_vader_vm$FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FusedBranch_t));
    vader_obj_header_init(_a1_obj, 1690u);
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
    l2 = std_core$write_string_at(l1, l2, 1871u);
    l2 = std_core$write_int(l1, l2, l0);
    l2 = std_core$write_string_at(l1, l2, 227u);
    t0 = std_core$finish_buffer(l1, l2);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1716u);
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
        l4 = std_core$write_string_at(l3, l4, 1664u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 165u);
        t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core$write_int(l3, l4, l5);
        t1 = std_core$finish_buffer(l3, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) (int32_t) l1);
    t3 = ((vader_struct_vader_vm$Frame_t*) l2)->f_sp;
    l5 = vader_chk_sub(i64, t3, l4);
    vader_array_t* _a1_arr = vader_array_reserve(414u, (int64_t) l4, 0u, 2456u);
    l3 = (void*) _a1_arr;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        l7 = vader_chk_add(i64, l5, l6);
        l8 = vader_vm$peek_owned(l2, l7);
        vader_array_push((vader_array_t*) l3, l8);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1681u);
    _a2_obj->f_type_id = l0;
    _a2_obj->f_elements = l3;
    _a2_obj->f_raw = vader_box_obj(0u, NULL);
    l3 = (void*) _a2_obj;
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
    l3 = vader_vm$read_i32(l3, l4, 1735u);
    if (l3.tag == 1716u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l3.payload.i);
    if ((t2 < INT32_C(0))) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(75));
        l2 = INT64_C(0);
        l2 = std_core$write_string_at(l5, l2, 1736u);
        t2 = ((int32_t) l3.payload.i);
        l6 = ((int64_t) (int32_t) t2);
        l2 = std_core$write_int(l5, l2, l6);
        l2 = std_core$write_string_at(l5, l2, 165u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l6 = ((int64_t) (int32_t) t2);
        l2 = std_core$write_int(l5, l2, l6);
        t3 = std_core$finish_buffer(l5, l2);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l3.payload.i);
    vader_array_t* _a1_arr = vader_array_reserve(29u, (int64_t) ((int64_t) (int32_t) t2), 1u, 499u);
    l5 = (void*) _a1_arr;
    l2 = INT64_C(0);
    t2 = ((int32_t) l3.payload.i);
    l6 = ((int64_t) (int32_t) t2);
    vader_array_t* _pc78_hdr = (vader_array_t*) l5;
    size_t _pc78_len = _pc78_hdr->length;
    size_t _pc78_cap = vader_array_is_borrowed(_pc78_hdr) ? (size_t) 0 : _pc78_hdr->capacity;
    void* _pc78_slots = _pc78_hdr->buf->slots;
    for (;;) {
        if ((l2 < l6)) {
            if (VADER_LIKELY(_pc78_len < _pc78_cap)) {
                ((uint8_t*) _pc78_slots)[_pc78_len] = (uint8_t) (INT32_C(0));
                _pc78_len += 1;
            } else {
                _pc78_hdr->length = _pc78_len;
                if (_pc78_hdr->buf->length < _pc78_len) {
                    _pc78_hdr->buf->length = _pc78_len;
                }
                vader_array_push_u8((vader_array_t*) l5, INT32_C(0));
                _pc78_hdr = (vader_array_t*) l5;
                _pc78_len = _pc78_hdr->length;
                _pc78_cap = vader_array_is_borrowed(_pc78_hdr) ? (size_t) 0 : _pc78_hdr->capacity;
                _pc78_slots = _pc78_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc78_hdr->length = _pc78_len;
        if (_pc78_hdr->buf->length < _pc78_len) {
            _pc78_hdr->buf->length = _pc78_len;
        }
        break;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (int32_t) l4;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
    vader_array_t* _a3_arr = vader_array_new(414u, 0u, 0u, 2456u);
    l7 = (void*) _a3_arr;
    vader_struct_vader_vm$ObjVal_t* _a4_obj = (vader_struct_vader_vm$ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ObjVal_t));
    vader_obj_header_init(_a4_obj, 1697u);
    _a4_obj->f_handle = l4;
    _a4_obj->f_type_id = INT32_C(0);
    _a4_obj->f_bytes = l5;
    _a4_obj->f_slots = l7;
    l5 = (void*) _a4_obj;
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
    vader_array_t* _a0_arr = vader_array_new(414u, 0u, 0u, 2456u);
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
        l7 = std_core$write_string_at(l8, l7, 1981u);
        l7 = std_core$write_string_at(l8, l7, l6);
        l7 = std_core$write_string_at(l8, l7, 317u);
        l7 = std_core$write_int(l8, l7, l5);
        l7 = std_core$write_string_at(l8, l7, 211u);
        t1 = std_core$finish_buffer(l8, l7);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1716u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(0), 499u);
    l9 = vader_vm$tags_of_val(((uint8_t) t3.payload.i));
    t4 = vader_vm$tags_within((uint8_t) 64, l9);
    if (!(t4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t3 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) INT32_C(0), 499u);
        l6 = vader_core_bytecode$val_type_name(((uint8_t) t3.payload.i));
        l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
        t1 = concat_5(1981u, l10, 318u, l6, 395u);
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 1716u);
        _a4_obj->f_message = t1;
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a5_arr = vader_array_new(26u, 1u, 0u, 494u);
        vader_array_box_slots(_a5_arr->buf)[_a5_arr->offset + 0u] = vader_box_string(494u, 557u);
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
    if (!(l3.tag == 978u)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(79));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 2828u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l4, l5, l6);
        l5 = std_core$write_string_at(l4, l5, 168u);
        t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
        l6 = ((int64_t) (int32_t) t0);
        l5 = std_core$write_int(l4, l5, l6);
        t1 = std_core$finish_buffer(l4, l5);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1716u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l3.payload.obj;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields)->length;
    t3 = ((vader_struct_vader_vm$Frame_t*) l2)->f_sp;
    l6 = vader_chk_sub(i64, t3, l5);
    if ((INT64_C(0) < l5)) {
        l7 = l5;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a2_arr = vader_array_reserve(414u, (int64_t) l7, 0u, 2456u);
    l4 = (void*) _a2_arr;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        t2 = l3.payload.obj;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcField_t*) t2)->f_type_index;
        l9 = vader_vm$field_valtype(l0, l8);
        l10 = vader_chk_add(i64, l6, l7);
        t4 = vader_vm$peek_owned(l2, l10);
        l11 = vader_vm$narrow_mask(t4, l9);
        vader_array_push((vader_array_t*) l4, l11);
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_vm$StructVal_t* _a4_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
    vader_obj_header_init(_a4_obj, 1713u);
    _a4_obj->f_type_id = l1;
    _a4_obj->f_fields = l4;
    l4 = (void*) _a4_obj;
    vader_vm$push_val(l2, l6, vader_ref_box(l4));
    l5 = vader_chk_add(i64, l6, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_sp = l5;
    t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
    l8 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_pc = l8;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static uint8_t vader_vm$byte_at(void* l0, int64_t l1) {
    vader_string_t l2;
    int64_t l3;
    int64_t t0;
    uint8_t t1;
    l2 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_text;
    t0 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_offset;
    l3 = vader_chk_add(i64, t0, l1);
    t1 = vader_host_std_core$byte_at(l2, l3);
    return t1;
}

static void* vader_vm$bytes_to_value(vader_string_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(414u, 0u, 0u, 2456u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core$byte_len(l0);
    vader_struct_vader_vm$StringWindow_t* _a1_obj = (vader_struct_vader_vm$StringWindow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StringWindow_t));
    vader_obj_header_init(_a1_obj, 1712u);
    _a1_obj->f_text = l0;
    _a1_obj->f_offset = INT64_C(0);
    _a1_obj->f_length = l3;
    l4 = (void*) _a1_obj;
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1681u);
    _a2_obj->f_type_id = l1;
    _a2_obj->f_elements = l2;
    _a2_obj->f_raw = vader_ref_box(l4);
    t0 = (void*) _a2_obj;
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
    int64_t l8, l9, l10;
    vader_box_t l11 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    uint8_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_reserve(414u, (int64_t) t0, 0u, 2456u);
    l7 = (void*) _a1_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params)->length;
    while ((l8 < l9)) {
        l10 = vader_chk_add(i64, l3, l8);
        l11 = vader_vm$register_value(l1, l10);
        vader_array_push((vader_array_t*) l7, l11);
        l8 = (l8 + INT64_C(1));
    }
    l11 = vader_vm$serve_import(l0, l1, l2, l6, l7, l4, l5);
    if (l11.tag == 1716u) {
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
    if (l1.tag == 1000u) {
        l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l2)->f_functions;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        return vader_ref_box(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature)->f_results);
    }
    if (l1.tag == 1001u) {
        l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l2)->f_imports;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        return vader_ref_box(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature)->f_results);
    }
    if (!(l1.tag == 1127u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results);
}

static void* vader_vm$call_stack(void* l0, void* l1, int64_t l2, int64_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    int64_t l5, l7, l8, l10, l11, l12, l14, l15, l16;
    vader_box_t l17 = vader_box_null();
    int32_t l20, l22;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l17 };
    void** gc_raw_roots[10] = { &l0, &l1, &l4, &l6, &l9, &l13, &l18, &l19, &l21, &l23 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(368u, 0u, 13u, 1700u);
    l4 = (void*) _a0_arr;
    l5 = l3;
    while ((l5 > INT64_C(0))) {
        l5 = vader_chk_sub(i64, l5, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = vader_chk_sub(i64, l3, INT64_C(1));
        if (l5 == l8) {
            l7 = l2;
        } else {
            l9 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_return;
            l10 = vader_chk_add(i64, l5, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
            l7 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l10];
        }
        l12 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_slots;
        if ((INT64_C(0) < l12)) {
            l11 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_slots;
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a3_arr = vader_array_reserve(414u, (int64_t) l11, 0u, 2456u);
        l13 = (void*) _a3_arr;
        l14 = INT64_C(0);
        l15 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_slots;
        while ((l14 < l15)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_base);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
            l16 = vader_chk_add(i64, t0, l14);
            l17 = vader_vm$register_value(l1, l16);
            vader_array_push((vader_array_t*) l13, l17);
            l14 = (l14 + INT64_C(1));
        }
        l18 = ((vader_struct_vader_vm$VmState_t*) l0)->f_bc;
        l19 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
        l20 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_index;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l20)
        l21 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l20);
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l6)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l22 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
        l23 = vader_vm$pause_frame(l18, l21, l13, l22);
        vader_array_push_ref((vader_array_t*) l4, l23);
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$callee_of(void* l0, void* l1, int64_t l2, int32_t l3) {
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    int64_t l9, l10, l11;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2 != INT64_C(0)) {
        { vader_box_t __vret = vader_box_i64(498u, l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l5 = vader_vm$adapter_reason(l1, l4);
    if (!(l5.tag == 0u)) {
        l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
        l7 = l5.payload.s;
        l8 = 1747u;
        l9 = vader_host_std_core$byte_len(l6);
        l10 = vader_host_std_core$byte_len(l7);
        l9 = (l9 + l10);
        l10 = vader_host_std_core$byte_len(l8);
        l9 = (l9 + l10);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(40) + l9));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l4, l9, 2050u);
        l9 = std_core$write_string_at(l4, l9, l6);
        l9 = std_core$write_string_at(l4, l9, 1120u);
        l10 = ((int64_t) (int32_t) l3);
        l9 = std_core$write_int(l4, l9, l10);
        l9 = std_core$write_string_at(l4, l9, 498u);
        l9 = std_core$write_string_at(l4, l9, l7);
        l9 = std_core$write_string_at(l4, l9, 539u);
        l9 = std_core$write_string_at(l4, l9, l8);
        t0 = std_core$finish_buffer(l4, l9);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$library_name(l1);
    l9 = vader_host_vader_vm$ffi_open(t0);
    if (l9 == INT64_C(0)) {
        l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
        l7 = vader_vm$unopened_reason(l1);
        l10 = vader_host_std_core$byte_len(l6);
        l11 = vader_host_std_core$byte_len(l7);
        l10 = (l10 + l11);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l10));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l4, l10, 2050u);
        l10 = std_core$write_string_at(l4, l10, l6);
        l10 = std_core$write_string_at(l4, l10, 1120u);
        l11 = ((int64_t) (int32_t) l3);
        l10 = std_core$write_int(l4, l10, l11);
        l10 = std_core$write_string_at(l4, l10, 498u);
        l10 = std_core$write_string_at(l4, l10, l7);
        t0 = std_core$finish_buffer(l4, l10);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1716u);
        _a1_obj->f_message = t0;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
    l9 = vader_host_vader_vm$ffi_symbol(l9, l6);
    if (!(l9 == INT64_C(0))) {
        { vader_box_t __vret = vader_box_i64(498u, l9); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
    l9 = vader_host_std_core$byte_len(l6);
    l4 = (void*) vader_buffer_new((size_t) (INT64_C(54) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l4, l9, 2050u);
    l9 = std_core$write_string_at(l4, l9, l6);
    l9 = std_core$write_string_at(l4, l9, 1120u);
    l10 = ((int64_t) (int32_t) l3);
    l9 = std_core$write_int(l4, l9, l10);
    l9 = std_core$write_string_at(l4, l9, 531u);
    t0 = std_core$finish_buffer(l4, l9);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 1716u);
    _a2_obj->f_message = t0;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$cancel(int64_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_vm$guest_threads();
    l3 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l1)->f_live, l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    ((vader_struct_vader_vm$GuestThread_t*) l2)->f_cancelled = true;
    t0 = ((vader_struct_vader_vm$GuestThread_t*) l2)->f_started;
    if (t0) {
        vader_host_std_runtime_scheduler$cancel_thread(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_vm$forget(l1, l0);
    vader_host_std_runtime_scheduler$cancel_thread(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$cancel_guest_thread(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3, l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l2, &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$read_i64(l0, l1, 1805u);
    if (l2.tag == 1716u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) l2.payload.i);
    t0 = vader_vm$guest_threads();
    l4 = ((vader_struct_vader_vm$GuestThreads_t*) t0)->f_entry_thread;
    if (!(l3 == l4)) {
        vader_vm$cancel(l3);
        t1 = vader_vm$void_result();
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1716u);
    _a0_obj->f_message = 3195u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
        l6 = std_core$write_string_at(l7, l6, 198u);
        l8 = ((int64_t) (int32_t) l0);
        l6 = std_core$write_int(l7, l6, l8);
        l6 = std_core$write_string_at(l7, l6, 165u);
        l8 = ((int64_t) (int32_t) l4);
        l6 = std_core$write_int(l7, l6, l8);
        t0 = std_core$finish_buffer(l7, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int64_t) (int32_t) l0);
    t2 = vader_chk_add(i64, l6, l1);
    if (!((t2 > l2))) {
        { vader_box_t __vret = vader_box_i64(498u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l8 = vader_host_std_core$byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l7, l8, l5);
    l8 = std_core$write_string_at(l7, l8, 198u);
    l8 = std_core$write_int(l7, l8, l6);
    l8 = std_core$write_string_at(l7, l8, 47u);
    l8 = std_core$write_int(l7, l8, l1);
    l8 = std_core$write_string_at(l7, l8, 352u);
    l8 = std_core$write_int(l7, l8, l2);
    l8 = std_core$write_string_at(l7, l8, 99u);
    l6 = ((int64_t) (int32_t) l4);
    l8 = std_core$write_int(l7, l8, l6);
    t0 = std_core$finish_buffer(l7, l8);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
                    l16 = concat_6(1087u, l15, 1258u, l13, 248u, l14);
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
    l4 = std_core$write_string_at(l5, l4, 99u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    l6 = ((int64_t) (int32_t) t0);
    l4 = std_core$write_int(l5, l4, l6);
    t1 = std_core$finish_buffer(l5, l4);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
    l5 = std_core$write_string_at(l6, l5, 99u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core$write_int(l6, l5, l7);
    t1 = std_core$finish_buffer(l6, l5);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
        if (l0.tag == 497u) {
            return true;
        }
        return l0.tag == 498u;
    }
    if (l1 == INT32_C(8)) {
        return (l0.tag == 503u || l0.tag == 504u);
    }
    if (!(l1 == INT32_C(15))) {
        return false;
    }
    if (l0.tag == 498u) {
        return true;
    }
    return l0.tag == 497u;
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
        if (l7.tag == 1094u) {
            t0 = l7.payload.obj;
            vader_vm$add_constant(((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value, l1, l2, l3);
        } else if ((l7.tag == 988u || l7.tag == 1003u || l7.tag == 1016u || l7.tag == 1037u || l7.tag == 1057u || l7.tag == 1088u)) {
            vader_vm$add_constant(l7, l1, l2, l3);
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$comptime_refusal(uint8_t l0) {
    vader_box_t l1;
    bool l2;
    if (l0 == INT32_C(32)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(33);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(34);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(35);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(36);
    }
    if (l2) {
        l1 = vader_box_string(494u, 2315u);
        return l1;
    }
    if (l0 == INT32_C(30)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(31);
    }
    if (l2) {
        l1 = vader_box_string(494u, 2315u);
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
                l2 = true;
            } else {
                l2 = l0 == INT32_C(9);
            }
            if (l2) {
                l1 = vader_box_obj(0u, NULL);
            } else {
                if (l0 == INT32_C(10)) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(11);
                }
                if (l2) {
                    l1 = vader_box_obj(0u, NULL);
                } else {
                    if (l0 == INT32_C(12)) {
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
                        l1 = vader_box_obj(0u, NULL);
                    } else {
                        if (l0 == INT32_C(16)) {
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
                            l1 = vader_box_obj(0u, NULL);
                        } else {
                            if (l0 == INT32_C(19)) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(20);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(21);
                            }
                            if (l2) {
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
                                l1 = vader_box_obj(0u, NULL);
                            } else {
                                if (l0 == INT32_C(25)) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(26);
                                }
                                if (l2) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(27);
                                }
                                if (l2) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(28);
                                }
                                if (l2) {
                                    l1 = vader_box_obj(0u, NULL);
                                } else if (l0 == INT32_C(29)) {
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
    t0 = concat_4(2178u, l0, 1249u, l1);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1716u);
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
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 499u);
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
    if (l0.tag == 497u) {
        t0 = vader_vm$is_unsigned_source(l2);
        if (t0) {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i64(498u, ((int64_t) (uint32_t) t1));
        } else {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i32(497u, t1);
        }
    } else {
        l4 = l0;
    }
    if (l1 == INT32_C(0)) {
        if (l4.tag == 497u) {
            t1 = ((int32_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i32(497u, t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1716u)) {
            t2 = ((int64_t) l5.payload.i);
            { vader_box_t __vret = vader_box_i32(497u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        if (l4.tag == 498u) {
            t2 = ((int64_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i64(498u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_i64(l4, l3);
        if (!(l5.tag == 1716u)) {
            t2 = ((int64_t) l5.payload.i);
            { vader_box_t __vret = vader_box_i64(498u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        if ((l4.tag == 503u || l4.tag == 504u)) {
            t4 = ((double) l4.payload.f);
            { vader_box_t __vret = vader_box_f64(504u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_f64(l4, l3);
        if (!(l5.tag == 1716u)) {
            t4 = ((double) l5.payload.f);
            { vader_box_t __vret = vader_box_f64(504u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 493u) {
        t5 = ((uint32_t) l4.payload.i);
        { vader_box_t __vret = vader_box_i32(493u, (int32_t) t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$read_numeric_as_i64(l4, l3);
    if (l4.tag == 1716u) {
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
            { vader_box_t __vret = vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l6)); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        { vader_box_t __vret = vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l6)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm$copy_all(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    int64_t l3, l4, l6, l9;
    void* l5 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l7, &l8 };
    void** gc_raw_roots[3] = { &l0, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$copy_of(l0, l1);
    if (l2.tag == 1716u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        l3 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next;
        l4 = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies)->length;
        if ((l3 < l4)) {
            l5 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies;
            l6 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            l7 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
            l8 = vader_vm$copy_inside(l0, l7);
            if (l8.tag == 1716u) {
                t0 = l8.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next;
            l9 = vader_chk_add(i64, t1, INT64_C(1));
            ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next = l9;
            continue;
        }
        break;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$copy_array(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    int32_t t0, t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_type_id;
    if ((t0 < INT32_C(0))) {
        l2 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies;
        t0 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_type_id;
        t1 = vader_chk_neg(i32, t0);
        l3 = vader_chk_sub(i32, t1, INT32_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$element_count(l1);
    vader_array_t* _a1_arr = vader_array_reserve(414u, (int64_t) l4, 0u, 2456u);
    l2 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l6 = vader_vm$element_at(l1, l5);
        vader_array_push((vader_array_t*) l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1681u);
    _a2_obj->f_type_id = t0;
    _a2_obj->f_elements = l2;
    _a2_obj->f_raw = vader_box_obj(0u, NULL);
    l2 = (void*) _a2_obj;
    l3 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_type_id;
    l3 = vader_vm$note(l0, vader_ref_box(l1), l3, vader_ref_box(l2));
    ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_type_id = l3;
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$copy_each(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l1)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
        l5 = vader_vm$copy_of(l0, l4);
        if (l5.tag == 1716u) {
            t0 = l5.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = l5;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2] = l6;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$copy_inside(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1713u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields;
        l2 = vader_vm$copy_each(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1681u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
        l2 = vader_vm$copy_each(l0, l3);
    } else if (l1.tag == 1697u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_vm$ObjVal_t*) t0)->f_slots;
        l2 = vader_vm$copy_each(l0, l3);
    } else {
        if (!((l1.tag == 492u || l1.tag == 493u || (l1.tag == 503u || l1.tag == 504u) || l1.tag == 1686u || l1.tag == 497u || l1.tag == 498u || l1.tag == 1696u || l1.tag == 494u || l1.tag == 1717u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$copy_object(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int32_t l3, l4;
    int32_t t0, t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l1)->f_type_id;
    if (!((t0 < INT32_C(0)))) {
        l3 = ((vader_struct_vader_vm$ObjVal_t*) l1)->f_handle;
        l4 = ((vader_struct_vader_vm$ObjVal_t*) l1)->f_type_id;
        l2 = std_iter$clone__u8(((vader_struct_vader_vm$ObjVal_t*) l1)->f_bytes);
        l5 = std_iter$clone__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal(((vader_struct_vader_vm$ObjVal_t*) l1)->f_slots);
        vader_struct_vader_vm$ObjVal_t* _a0_obj = (vader_struct_vader_vm$ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ObjVal_t));
        vader_obj_header_init(_a0_obj, 1697u);
        _a0_obj->f_handle = l3;
        _a0_obj->f_type_id = l4;
        _a0_obj->f_bytes = l2;
        _a0_obj->f_slots = l5;
        l5 = (void*) _a0_obj;
        l4 = ((vader_struct_vader_vm$ObjVal_t*) l1)->f_type_id;
        l4 = vader_vm$note(l0, vader_ref_box(l1), l4, vader_ref_box(l5));
        ((vader_struct_vader_vm$ObjVal_t*) l1)->f_type_id = l4;
        { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies;
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l1)->f_type_id;
    t1 = vader_chk_neg(i32, t0);
    l3 = vader_chk_sub(i32, t1, INT32_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$copy_of(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1713u) {
        l3 = l1.payload.obj;
        l2 = vader_vm$copy_struct(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1681u) {
        l3 = l1.payload.obj;
        l2 = vader_vm$copy_array(l0, l3);
    } else if (l1.tag == 1697u) {
        l3 = l1.payload.obj;
        l2 = vader_vm$copy_object(l0, l3);
    } else if (l1.tag == 1686u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(71));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1916u);
        t0 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_at_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core$write_int(l3, l4, l5);
        t1 = std_core$finish_buffer(l3, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        l2 = vader_ref_box(t2);
    } else {
        if (!((l1.tag == 492u || l1.tag == 493u || (l1.tag == 503u || l1.tag == 504u) || l1.tag == 497u || l1.tag == 498u || l1.tag == 1696u || l1.tag == 494u || l1.tag == 1717u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$copy_struct(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t t0, t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[2] = { &l4, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    if ((t0 < INT32_C(0))) {
        l2 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies;
        t0 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
        t1 = vader_chk_neg(i32, t0);
        l3 = vader_chk_sub(i32, t1, INT32_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_types;
    l3 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (l4.tag == 978u) {
        t3 = l4.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t3)->f_shared;
        if (t4) {
            { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    l2 = std_iter$clone__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal(((vader_struct_vader_vm$StructVal_t*) l1)->f_fields);
    vader_struct_vader_vm$StructVal_t* _a2_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
    vader_obj_header_init(_a2_obj, 1713u);
    _a2_obj->f_type_id = l3;
    _a2_obj->f_fields = l2;
    l2 = (void*) _a2_obj;
    l3 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    l3 = vader_vm$note(l0, vader_ref_box(l1), l3, vader_ref_box(l2));
    ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id = l3;
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
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

static vader_box_t vader_vm$debug_session(vader_box_t l0, int32_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = l0.payload.obj;
        vader_struct_vader_vm$DebugSession_t* _a0_obj = (vader_struct_vader_vm$DebugSession_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$DebugSession_t));
        vader_obj_header_init(_a0_obj, 1685u);
        _a0_obj->f_controller = t0;
        _a0_obj->f_thread_id = l1;
        _a0_obj->f_last_line = INT32_C(-1);
        _a0_obj->f_step_mode = (uint8_t) 0;
        _a0_obj->f_step_depth = INT32_C(0);
        _a0_obj->f_host_pc = INT64_C(0);
        _a0_obj->f_host_depth = INT64_C(0);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
    l5 = vader_vm$read_i64(t0, l3, 2847u);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_chk_add(i64, l2, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
    l7 = vader_vm$read_array(t0, l3, 2844u);
    if (l7.tag == 1716u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_chk_add(i64, l2, INT64_C(2));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
    l8 = vader_vm$read_i64(t0, l3, 2846u);
    if (l8.tag == 1716u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int64_t) l8.payload.i);
    if ((t2 < INT64_C(0))) {
        l9 = true;
    } else {
        l6 = ((int64_t) l8.payload.i);
        t1 = l7.payload.obj;
        l10 = vader_vm$element_count(t1);
        l9 = (l6 > l10);
    }
    if (l9) {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(83));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l11, l6, 2843u);
        l10 = ((int64_t) (int32_t) l3);
        l6 = std_core$write_int(l11, l6, l10);
        l6 = std_core$write_string_at(l11, l6, 511u);
        l10 = ((int64_t) l8.payload.i);
        l6 = std_core$write_int(l11, l6, l10);
        l6 = std_core$write_string_at(l11, l6, 124u);
        t3 = std_core$finish_buffer(l11, l6);
        vader_struct_vader_vm$Trap_t* _a3_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a3_obj, 1716u);
        _a3_obj->f_message = t3;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l7.payload.obj;
    l6 = ((int64_t) l8.payload.i);
    l7 = vader_vm$array_bytes(l11, l6, l3, 2845u);
    if (l7.tag == 1716u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = ((vader_struct_vader_vm$DebugController_t*) l4)->f_output_sink;
    t2 = ((int64_t) l5.payload.i);
    l12 = vader_chk_sub(i32, ((int32_t) (int64_t) t2), INT32_C(1));
    t1 = l7.payload.obj;
    l13 = vader_host_std_core$bytes_to_string(t1);
    vader_fn_t* _a4_fnobj = (vader_fn_t*) l11;
    ((vader_fn_erased_sig_2_t) _a4_fnobj->code)(_a4_fnobj->env, vader_box_i32(497u, l12), vader_box_string(494u, l13));
    t4 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
    if (!(t4 == INT32_C(10))) {
        t2 = ((int64_t) l8.payload.i);
        vader_struct_vader_vm$HostOk_t* _a5_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a5_obj, 1693u);
        _a5_obj->f_value = vader_box_i64(498u, t2);
        t1 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a6_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a6_obj, 1693u);
    _a6_obj->f_value = vader_box_bool(492u, true);
    t1 = (void*) _a6_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$debugged_thread_id(int64_t l0) {
    int32_t t0;
    t0 = vader_chk_add(i32, ((int32_t) (int64_t) l0), INT32_C(1));
    return t0;
}

static void* vader_vm$debugged_threads(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    vader_box_t l2 = vader_box_null();
    int64_t l4, l7, l9, l10;
    int32_t l8;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l6, &l12, &l13, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_vm$guest_threads();
    l2 = ((vader_struct_vader_vm$GuestThreads_t*) l1)->f_entry_machine;
    vader_struct___lambda_env_vader_vm_10_t* _a0_obj = (vader_struct___lambda_env_vader_vm_10_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_10_t));
    vader_obj_header_init(_a0_obj, 667u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l2;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 433u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_9;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    t1 = vader_vm$main_thread(t0);
    vader_array_t* _a2_arr = vader_array_new(369u, 1u, 13u, 1701u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t1;
    l3 = (void*) _a2_arr;
    l1 = ((vader_struct_vader_vm$GuestThreads_t*) l1)->f_live;
    l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_size;
    if ((INT64_C(0) < l4)) {
        l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_size;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_reserve(364u, (int64_t) l4, 13u, 1691u);
    l5 = (void*) _a3_arr;
    l6 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_size;
    while ((l4 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        l1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        vader_array_push_ref((vader_array_t*) l5, l1);
        l4 = (l4 + INT64_C(1));
    }
    l1 = (void*) &vader_fn_static___lambda_vader_vm_11;
    l1 = std_sort$sort__vader_vm_GuestThread(l5, l1);
    l4 = ((vader_array_t*) l1)->length;
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l2 = ((vader_struct_vader_vm$GuestThread_t*) l5)->f_machine;
        t2 = ((vader_struct_vader_vm$GuestThread_t*) l5)->f_number;
        l8 = vader_vm$debugged_thread_id(t2);
        l6 = (void*) vader_buffer_new((size_t) INT64_C(26));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l6, l9, 2857u);
        l10 = ((vader_struct_vader_vm$GuestThread_t*) l5)->f_number;
        l9 = std_core$write_int(l6, l9, l10);
        l11 = std_core$finish_buffer(l6, l9);
        vader_struct___lambda_env_vader_vm_13_t* _a6_obj = (vader_struct___lambda_env_vader_vm_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_13_t));
        vader_obj_header_init(_a6_obj, 668u);
        _a6_obj->f_cap_0 = l0;
        _a6_obj->f_cap_1 = l2;
        t0 = (void*) _a6_obj;
        vader_fn_t* _a7_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a7_closure, 433u);
        _a7_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_12;
        _a7_closure->env = t0;
        l12 = (void*) _a7_closure;
        vader_struct_vader_vm$PauseThread_t* _a8_obj = (vader_struct_vader_vm$PauseThread_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseThread_t));
        vader_obj_header_init(_a8_obj, 1701u);
        _a8_obj->f_id = l8;
        _a8_obj->f_name = l11;
        _a8_obj->f_stack = l12;
        l13 = (void*) _a8_obj;
        vader_array_push_ref((vader_array_t*) l3, l13);
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$deep_copy_value(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(415u, 0u, 13u, 2470u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 7u, 497u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(414u, 0u, 0u, 2456u);
    l5 = (void*) _a2_arr;
    vader_struct_vader_vm$CopyWalk_t* _a3_obj = (vader_struct_vader_vm$CopyWalk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$CopyWalk_t));
    vader_obj_header_init(_a3_obj, 1683u);
    _a3_obj->f_types = l0;
    _a3_obj->f_at_pc = l2;
    _a3_obj->f_sources = l3;
    _a3_obj->f_kept_ids = l4;
    _a3_obj->f_copies = l5;
    _a3_obj->f_next = INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = vader_vm$copy_all(l3, l1);
    vader_vm$restore(l3);
    if (!(l6.tag == 1716u)) {
        vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a4_obj, 1693u);
        _a4_obj->f_value = l6;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l6.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 1719u);
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
    if (!(l1.tag == 1686u)) {
        l4 = l1;
        l5 = concat_2(l3, 122u);
        t0 = vader_vm$read_fn(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    l4 = vader_vm$validate_fn_index(l6, l7, l2, l3);
    if (l4.tag == 1716u) {
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
    l8 = std_core$write_string_at(l7, l8, 1920u);
    l8 = std_core$write_string_at(l7, l8, l5);
    l8 = std_core$write_string_at(l7, l8, 316u);
    l9 = ((int64_t) (int32_t) l2);
    l8 = std_core$write_int(l7, l8, l9);
    t3 = std_core$finish_buffer(l7, l8);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
    l2 = std_core$write_string_at(l1, l2, 553u);
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l0)->f_handle;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 239u);
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 108u);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l0)->f_bytes)->length;
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 226u);
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l0)->f_slots)->length;
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 563u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$describe_value_tag(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 497u) {
        l1 = 2181u;
        return l1;
    }
    if (l0.tag == 498u) {
        l1 = 2203u;
    } else if ((l0.tag == 503u || l0.tag == 504u)) {
        l1 = 2055u;
    } else if (l0.tag == 494u) {
        l1 = 2803u;
    } else if (l0.tag == 1713u) {
        l1 = 2815u;
    } else if (l0.tag == 1681u) {
        l1 = 1647u;
    } else if (l0.tag == 1686u) {
        l1 = 2106u;
    } else if (l0.tag == 1696u) {
        l1 = 2532u;
    } else if (l0.tag == 492u) {
        l1 = 1712u;
    } else if (l0.tag == 493u) {
        l1 = 1838u;
    } else if (l0.tag == 1717u) {
        l1 = 2920u;
    } else {
        if (!(l0.tag == 1697u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2536u;
    }
    return l1;
}

static vader_box_t vader_vm$dispatch_extern(void* l0, int32_t l1, void* l2, int64_t l3, int32_t l4, vader_box_t l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    void* l38 = NULL;
    void* l45 = NULL;
    void* l46 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    void* l64 = NULL;
    void* l75 = NULL;
    void* l83 = NULL;
    void* l85 = NULL;
    void* l86 = NULL;
    void* l89 = NULL;
    void* l90 = NULL;
    void* l102 = NULL;
    vader_box_t l9 = vader_box_null(), l19 = vader_box_null(), l26 = vader_box_null(), l48 = vader_box_null(), l54 = vader_box_null(), l56 = vader_box_null(), l72 = vader_box_null(), l82 = vader_box_null(), l93 = vader_box_null(), l95 = vader_box_null(), l98 = vader_box_null(), l110 = vader_box_null(), l112 = vader_box_null();
    int64_t l16, l17, l18, l21, l23, l24, l28, l30, l31, l35, l36, l37, l39, l40, l41, l42, l43, l44, l50, l57, l61, l62, l63, l65, l66, l68, l69, l70, l74, l76, l77, l78, l80, l81, l84, l87, l91, l92, l94, l100, l101, l104, l106, l109, l114;
    vader_string_t l20 = 0;
    vader_string_t l27 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l47 = 0;
    vader_string_t l55 = 0;
    vader_string_t l59 = 0;
    vader_string_t l60 = 0;
    vader_string_t l73 = 0;
    vader_string_t l96 = 0;
    vader_string_t l97 = 0;
    vader_string_t l111 = 0;
    uint8_t l49, l67, l79, l88, l99, l103, l105, l107, l108, l113;
    bool l58;
    int32_t l71;
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3, t4;
    void* t5 = NULL;
    uint8_t t6;
    int32_t t7;
    double t8;
    uint32_t t9;
    vader_box_t* gc_roots[15] = {
        &l5, &l9, &l19, &l26, &l48, &l54, &l56, &l72, &l82, &l93, &l95, &l98, &l110, &l112, &t2,
    };
    void** gc_raw_roots[30] = {
        &l0, &l2, &l6, &l7, &l8, &l10, &l11, &l12, &l13, &l14, &l15, &l22, &l25, &l29, &l32, &l38,
        &l45, &l46, &l51, &l52, &l53, &l64, &l75, &l83, &l85, &l86, &l89, &l90, &l102, &t5,
    };
    vader_string_t* gc_atom_roots[13] = {
        &l20, &l27, &l33, &l34, &l47, &l55, &l59, &l60, &l73, &l96, &l97, &l111, &t0,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 15u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params;
    if (!(l5.tag == 0u)) {
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
        t1 = vader_vm$is_std_handle_symbol(t0);
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
            l9 = vader_vm$read_i64(t2, l4, 695u);
            if (!(l9.tag == 1716u)) {
                t3 = ((int64_t) l9.payload.i);
                t4 = vader_vm$debug_std_descriptor(t3);
                vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a2_obj, 1693u);
                _a2_obj->f_value = vader_box_i64(498u, t4);
                t5 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t5 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(l5.tag == 0u)) {
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
        t1 = vader_vm$is_write_symbol(t0);
        if (t1) {
            l10 = l5.payload.obj;
            t2 = vader_vm$debug_write(l6, l2, l3, l4, l10);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l9 = vader_vm$foreign_call_of(l0, l1, l4);
    if (l9.tag == 1716u) {
        t5 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t5 = l9.payload.obj;
    t6 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result_class;
    vader_array_t* _a3_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) (int32_t) (uint8_t) t6;
    l10 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(28u, 0u, 8u, 498u);
    l11 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 8u, 498u);
    l12 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 1u, 499u);
    l13 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(365u, 0u, 13u, 1694u);
    l14 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(366u, 0u, 13u, 1695u);
    l15 = (void*) _a8_arr;
    l16 = INT64_C(0);
    l17 = ((vader_array_t*) l8)->length;
    while ((l16 < l17)) {
        l18 = vader_chk_add(i64, l3, l16);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l18)
        l19 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l18];
        if (l19.tag == 1686u) {
            l20 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
            l21 = vader_host_std_core$byte_len(l20);
            l22 = (void*) vader_buffer_new((size_t) (INT64_C(138) + l21));
            l23 = INT64_C(0);
            l23 = std_core$write_string_at(l22, l23, 2050u);
            l23 = std_core$write_string_at(l22, l23, l20);
            l23 = std_core$write_string_at(l22, l23, 1120u);
            l24 = ((int64_t) (int32_t) l4);
            l23 = std_core$write_int(l22, l23, l24);
            l23 = std_core$write_string_at(l22, l23, 504u);
            l23 = std_core$write_int(l22, l23, l16);
            l23 = std_core$write_string_at(l22, l23, 154u);
            t0 = std_core$finish_buffer(l22, l23);
            vader_struct_vader_vm$Trap_t* _a10_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a10_obj, 1716u);
            _a10_obj->f_message = t0;
            t5 = (void*) _a10_obj;
            { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l19.tag == 1713u) {
            l25 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_param_types;
            l26 = vader_vm$mirrored_struct_fields(l7, l25, l16);
            if (l26.tag == 0u) {
                l27 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
                l28 = vader_host_std_core$byte_len(l27);
                l29 = (void*) vader_buffer_new((size_t) (INT64_C(112) + l28));
                l30 = INT64_C(0);
                l30 = std_core$write_string_at(l29, l30, 2050u);
                l30 = std_core$write_string_at(l29, l30, l27);
                l30 = std_core$write_string_at(l29, l30, 1120u);
                l31 = ((int64_t) (int32_t) l4);
                l30 = std_core$write_int(l29, l30, l31);
                l30 = std_core$write_string_at(l29, l30, 504u);
                l30 = std_core$write_int(l29, l30, l16);
                l30 = std_core$write_string_at(l29, l30, 156u);
                t0 = std_core$finish_buffer(l29, l30);
                vader_struct_vader_vm$Trap_t* _a11_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a11_obj, 1716u);
                _a11_obj->f_message = t0;
                t5 = (void*) _a11_obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t5 = l26.payload.obj;
            l32 = vader_core_bytecode$c_struct_layout(t5, l7);
            if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_unknown_field.tag == 0u)) {
                l33 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
                l34 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_unknown_field.payload.s;
                l35 = vader_host_std_core$byte_len(l33);
                l36 = vader_host_std_core$byte_len(l34);
                l37 = (l35 + l36);
                l38 = (void*) vader_buffer_new((size_t) (INT64_C(142) + l37));
                l39 = INT64_C(0);
                l39 = std_core$write_string_at(l38, l39, 2050u);
                l39 = std_core$write_string_at(l38, l39, l33);
                l39 = std_core$write_string_at(l38, l39, 1120u);
                l40 = ((int64_t) (int32_t) l4);
                l39 = std_core$write_int(l38, l39, l40);
                l39 = std_core$write_string_at(l38, l39, 504u);
                l39 = std_core$write_int(l38, l39, l16);
                l39 = std_core$write_string_at(l38, l39, 184u);
                l39 = std_core$write_string_at(l38, l39, l34);
                l39 = std_core$write_string_at(l38, l39, 1226u);
                t0 = std_core$finish_buffer(l38, l39);
                vader_struct_vader_vm$Trap_t* _a12_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a12_obj, 1716u);
                _a12_obj->f_message = t0;
                t5 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l41 = ((vader_array_t*) l13)->length;
            l42 = INT64_C(4096);
            t3 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_size;
            if ((t3 > l42)) {
                l43 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_size;
            } else {
                l43 = l42;
            }
            l44 = INT64_C(0);
            while ((l44 < l43)) {
                vader_array_push_u8((vader_array_t*) l13, INT32_C(0));
                l44 = (l44 + INT64_C(1));
            }
            l45 = l19.payload.obj;
            l46 = l26.payload.obj;
            l47 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
            l48 = vader_vm$serialise_mirror(l13, l41, l45, l46, l7, l4, l47, INT32_C(0));
            if (l48.tag == 1716u) {
                t5 = l48.payload.obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = (INT32_C(3) & INT32_C(255));
            l49 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l49);
            l50 = ((vader_array_t*) l11)->length;
            vader_array_push_i64((vader_array_t*) l12, l50);
            vader_array_push_i64((vader_array_t*) l11, l41);
            t1 = vader_core_bytecode$param_is_c_out(((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature, l16);
            if (t1) {
                l51 = l19.payload.obj;
                l52 = l26.payload.obj;
                vader_struct_vader_vm$LentStruct_t* _a13_obj = (vader_struct_vader_vm$LentStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$LentStruct_t));
                vader_obj_header_init(_a13_obj, 1695u);
                _a13_obj->f_target = l51;
                _a13_obj->f_at = l41;
                _a13_obj->f_fields = l52;
                l53 = (void*) _a13_obj;
                vader_array_push_ref((vader_array_t*) l15, l53);
            }
            l16 = (l16 + INT64_C(1));
            continue;
        }
        t1 = vader_core_bytecode$param_is_by_address(((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature, l16);
        if (t1) {
            l54 = l19;
            l55 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
            l56 = vader_vm$extern_word(l54, l4, l55, l16);
            if (l56.tag == 1716u) {
                t5 = l56.payload.obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a14_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            t2 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l16, 499u);
            t7 = vader_core_bytecode$size_of_val_type(((uint8_t) t2.payload.i));
            l57 = ((int64_t) (int32_t) t7);
            if (l57 == INT64_C(0)) {
                l58 = true;
            } else {
                l58 = (l57 > INT64_C(8));
            }
            if (l58) {
                l59 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                t2 = vader_array_read_u8(_a15_slotarr, _a15_slotarr->offset + (size_t) l16, 499u);
                l60 = vader_core_bytecode$val_type_name(((uint8_t) t2.payload.i));
                l61 = vader_host_std_core$byte_len(l59);
                l62 = vader_host_std_core$byte_len(l60);
                l63 = (l61 + l62);
                l64 = (void*) vader_buffer_new((size_t) (INT64_C(81) + l63));
                l65 = INT64_C(0);
                l65 = std_core$write_string_at(l64, l65, 2050u);
                l65 = std_core$write_string_at(l64, l65, l59);
                l65 = std_core$write_string_at(l64, l65, 1120u);
                l66 = ((int64_t) (int32_t) l4);
                l65 = std_core$write_int(l64, l65, l66);
                l65 = std_core$write_string_at(l64, l65, 501u);
                l65 = std_core$write_string_at(l64, l65, l60);
                l65 = std_core$write_string_at(l64, l65, 208u);
                t0 = std_core$finish_buffer(l64, l65);
                vader_struct_vader_vm$Trap_t* _a16_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a16_obj, 1716u);
                _a16_obj->f_message = t0;
                t5 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = (INT32_C(3) & INT32_C(255));
            l67 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l67);
            l68 = ((vader_array_t*) l11)->length;
            vader_array_push_i64((vader_array_t*) l12, l68);
            l69 = ((vader_array_t*) l13)->length;
            vader_array_push_i64((vader_array_t*) l11, l69);
            l70 = ((int64_t) l56.payload.i);
            vader_vm$push_little_endian(l13, l70, l57);
        } else if (l19.tag == 1681u) {
            t5 = l19.payload.obj;
            l71 = ((vader_struct_vader_vm$ArrayVal_t*) t5)->f_type_id;
            l72 = vader_vm$lent_element_val_type(l7, l71);
            if (l72.tag == 0u) {
                l73 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
                l74 = vader_host_std_core$byte_len(l73);
                l75 = (void*) vader_buffer_new((size_t) (INT64_C(153) + l74));
                l76 = INT64_C(0);
                l76 = std_core$write_string_at(l75, l76, 2050u);
                l76 = std_core$write_string_at(l75, l76, l73);
                l76 = std_core$write_string_at(l75, l76, 1120u);
                l77 = ((int64_t) (int32_t) l4);
                l76 = std_core$write_int(l75, l76, l77);
                l76 = std_core$write_string_at(l75, l76, 504u);
                l76 = std_core$write_int(l75, l76, l16);
                l76 = std_core$write_string_at(l75, l76, 159u);
                t0 = std_core$finish_buffer(l75, l76);
                vader_struct_vader_vm$Trap_t* _a17_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a17_obj, 1716u);
                _a17_obj->f_message = t0;
                t5 = (void*) _a17_obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t6 = ((uint8_t) l72.payload.i);
            t7 = vader_core_bytecode$size_of_val_type(t6);
            l78 = ((int64_t) (int32_t) t7);
            t7 = (INT32_C(3) & INT32_C(255));
            l79 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l79);
            l80 = ((vader_array_t*) l11)->length;
            vader_array_push_i64((vader_array_t*) l12, l80);
            l81 = ((vader_array_t*) l13)->length;
            vader_array_push_i64((vader_array_t*) l11, l81);
            t5 = l19.payload.obj;
            l82 = ((vader_struct_vader_vm$ArrayVal_t*) t5)->f_raw;
            if (l82.tag == 0u) {
                l86 = l19.payload.obj;
                l87 = ((vader_array_t*) l13)->length;
                l88 = ((uint8_t) l72.payload.i);
                vader_struct_vader_vm$LentArray_t* _a18_obj = (vader_struct_vader_vm$LentArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$LentArray_t));
                vader_obj_header_init(_a18_obj, 1694u);
                _a18_obj->f_target = l86;
                _a18_obj->f_at = l87;
                _a18_obj->f_element = l88;
                l89 = (void*) _a18_obj;
                vader_array_push_ref((vader_array_t*) l14, l89);
                t5 = l19.payload.obj;
                l90 = ((vader_struct_vader_vm$ArrayVal_t*) t5)->f_elements;
                l91 = ((vader_array_t*) l90)->length;
                l92 = INT64_C(0);
                while ((l92 < l91)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l90);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    l93 = vader_array_box_slots(_a19_slotarr->buf)[_a19_slotarr->offset + (size_t) l92];
                    if (l93.tag == 498u) {
                        l94 = ((int64_t) l93.payload.i);
                    } else if (l93.tag == 497u) {
                        t7 = ((int32_t) l93.payload.i);
                        l94 = ((int64_t) (int32_t) t7);
                    } else {
                        l95 = l93;
                        l96 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
                        l97 = concat_3(2050u, l96, 1144u);
                        l98 = vader_vm$read_i64(l95, l4, l97);
                        if (l98.tag == 1716u) {
                            t5 = l98.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l94 = ((int64_t) l98.payload.i);
                    }
                    vader_vm$push_little_endian(l13, l94, l78);
                    l92 = (l92 + INT64_C(1));
                }
            } else {
                l83 = l82.payload.obj;
                t5 = l82.payload.obj;
                l84 = ((vader_struct_vader_vm$StringWindow_t*) t5)->f_length;
                l85 = vader_vm$first_bytes(l83, l84);
                vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l85);
            }
        } else if (l19.tag == 494u) {
            t7 = (INT32_C(3) & INT32_C(255));
            l99 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l99);
            l100 = ((vader_array_t*) l11)->length;
            vader_array_push_i64((vader_array_t*) l12, l100);
            l101 = ((vader_array_t*) l13)->length;
            vader_array_push_i64((vader_array_t*) l11, l101);
            t0 = l19.payload.s;
            l102 = vader_host_std_core$bytes(t0);
            vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l102);
            vader_array_push_u8((vader_array_t*) l13, INT32_C(0));
        } else if ((l19.tag == 503u || l19.tag == 504u)) {
            t7 = (INT32_C(2) & INT32_C(255));
            l103 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l103);
            t8 = ((double) l19.payload.f);
            l104 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t8 }).__vu);
            vader_array_push_i64((vader_array_t*) l11, l104);
        } else if (l19.tag == 492u) {
            t7 = (INT32_C(1) & INT32_C(255));
            l105 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l105);
            t1 = l19.payload.b;
            if (t1) {
                l106 = INT64_C(1);
            } else {
                l106 = INT64_C(0);
            }
            vader_array_push_i64((vader_array_t*) l11, l106);
        } else if (l19.tag == 1696u) {
            t7 = (INT32_C(1) & INT32_C(255));
            l107 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l107);
            vader_array_push_i64((vader_array_t*) l11, INT64_C(0));
        } else if (l19.tag == 493u) {
            t7 = (INT32_C(1) & INT32_C(255));
            l108 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l108);
            t9 = ((uint32_t) l19.payload.i);
            l109 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t9));
            vader_array_push_i64((vader_array_t*) l11, l109);
        } else {
            l110 = l19;
            l111 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_extern_name;
            l112 = vader_vm$extern_word(l110, l4, l111, l16);
            if (l112.tag == 1716u) {
                t5 = l112.payload.obj;
                { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t7 = (INT32_C(1) & INT32_C(255));
            l113 = (uint8_t) (int32_t) t7;
            vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l113);
            l114 = ((int64_t) l112.payload.i);
            vader_array_push_i64((vader_array_t*) l11, l114);
        }
        l16 = (l16 + INT64_C(1));
    }
    t5 = l9.payload.obj;
    l19 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result_mirror;
    l16 = ((vader_array_t*) l13)->length;
    if (!(l19.tag == 0u)) {
        l17 = INT64_C(0);
        t5 = l19.payload.obj;
        l18 = ((vader_struct_vader_vm$ResultMirror_t*) t5)->f_size;
        while ((l17 < l18)) {
            vader_array_push_u8((vader_array_t*) l13, INT32_C(0));
            l17 = (l17 + INT64_C(1));
        }
        t7 = (INT32_C(3) & INT32_C(255));
        l49 = (uint8_t) (int32_t) t7;
        vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l49);
        l17 = ((vader_array_t*) l11)->length;
        vader_array_push_i64((vader_array_t*) l12, l17);
        vader_array_push_i64((vader_array_t*) l11, l16);
    }
    t3 = ((vader_array_t*) l11)->length;
    l17 = vader_chk_mul(i64, t3, INT64_C(8));
    l8 = l12;
    l18 = ((vader_array_t*) l8)->length;
    l21 = INT64_C(0);
    while ((l21 < l18)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l23 = ((int64_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l21];
        vader_array_t* _a21_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l23)
        t3 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l23];
        l24 = vader_chk_add(i64, t3, l17);
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l23)
        ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l23] = (int64_t) l24;
        l21 = (l21 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(29u, 0u, 1u, 499u);
    l8 = (void*) _a22_arr;
    l18 = ((vader_array_t*) l11)->length;
    l21 = INT64_C(0);
    while ((l21 < l18)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l23 = ((int64_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l21];
        vader_vm$push_little_endian(l8, l23, INT64_C(8));
        l21 = (l21 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l13);
    t3 = ((vader_array_t*) l8)->length;
    if (t3 == INT64_C(0)) {
        t5 = l9.payload.obj;
        if (((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result != INT32_C(14)) {
            vader_vm$push_little_endian(l8, INT64_C(0), INT64_C(8));
        }
    }
    t5 = l9.payload.obj;
    l18 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_callee;
    t5 = l9.payload.obj;
    l58 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_through_adapter;
    t7 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_c_variadic_fixed;
    l21 = ((int64_t) (int32_t) t7);
    l20 = vader_vm$call_foreign(l18, l58, l10, l8, l21);
    l6 = l14;
    l18 = ((vader_array_t*) l6)->length;
    l21 = INT64_C(0);
    while ((l21 < l18)) {
        vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        l10 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l21);
        t7 = vader_core_bytecode$size_of_val_type(((vader_struct_vader_vm$LentArray_t*) l10)->f_element);
        l23 = ((int64_t) (int32_t) t7);
        t1 = vader_core_bytecode$is_unsigned_val(((vader_struct_vader_vm$LentArray_t*) l10)->f_element);
        l58 = !(t1);
        l24 = INT64_C(0);
        l28 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l10)->f_target)->f_elements)->length;
        while ((l24 < l28)) {
            l30 = ((vader_struct_vader_vm$LentArray_t*) l10)->f_at;
            l31 = vader_chk_add(i64, l17, l30);
            l35 = vader_chk_mul(i64, l24, l23);
            l36 = vader_chk_add(i64, l31, l35);
            l37 = vader_vm$read_little_endian(l8, l36, l23, l58);
            l11 = ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l10)->f_target)->f_elements;
            vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l10)->f_target)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l24)
            t2 = vader_array_box_slots(_a25_slotarr->buf)[_a25_slotarr->offset + (size_t) l24];
            l26 = vader_vm$retyped_int(t2, l37);
            vader_array_t* _a26_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l24)
            vader_array_box_slots(_a26_slotarr->buf)[_a26_slotarr->offset + (size_t) l24] = l26;
            VADER_WRITE_BARRIER(_a26_slotarr->buf);
            l24 = (l24 + INT64_C(1));
        }
        l21 = (l21 + INT64_C(1));
    }
    l6 = l15;
    l18 = ((vader_array_t*) l6)->length;
    l21 = INT64_C(0);
    while ((l21 < l18)) {
        vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        l10 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l21);
        l23 = ((vader_struct_vader_vm$LentStruct_t*) l10)->f_at;
        l24 = vader_chk_add(i64, l17, l23);
        l11 = ((vader_struct_vader_vm$LentStruct_t*) l10)->f_target;
        l12 = ((vader_struct_vader_vm$LentStruct_t*) l10)->f_fields;
        vader_vm$read_back_mirror(l8, l24, l11, l12, l7, INT32_C(0));
        l21 = (l21 + INT64_C(1));
    }
    if (!(l19.tag == 0u)) {
        l16 = vader_chk_add(i64, l17, l16);
        t5 = l19.payload.obj;
        l71 = ((vader_struct_vader_vm$ResultMirror_t*) t5)->f_type_index;
        t5 = l19.payload.obj;
        l6 = ((vader_struct_vader_vm$ResultMirror_t*) t5)->f_mirror;
        t5 = vader_vm$mirror_value(l8, l16, l71, l6, l7);
        vader_struct_vader_vm$HostOk_t* _a28_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a28_obj, 1693u);
        _a28_obj->f_value = vader_ref_box(t5);
        t5 = (void*) _a28_obj;
        { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t5 = l9.payload.obj;
    if (((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result == INT32_C(14)) {
        t2 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a29_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a29_obj, 1693u);
        _a29_obj->f_value = t2;
        t5 = (void*) _a29_obj;
        { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t5 = l9.payload.obj;
    if (((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result == INT32_C(9)) {
        l58 = true;
    } else {
        t5 = l9.payload.obj;
        l58 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result == INT32_C(8);
    }
    if (l58) {
        t3 = vader_vm$read_little_endian(l8, INT64_C(0), INT64_C(8), false);
        vader_struct_vader_vm$HostOk_t* _a30_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a30_obj, 1693u);
        _a30_obj->f_value = vader_box_f64(504u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t3) }).__vd));
        t5 = (void*) _a30_obj;
        { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t5 = l9.payload.obj;
    t1 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_null_on_zero;
    if (t1) {
        t3 = vader_vm$read_little_endian(l8, INT64_C(0), INT64_C(8), false);
        if (t3 == INT64_C(0)) {
            t5 = (void*) &vader_data_169;
            vader_array_t* _a31_slotarr = ((vader_array_t*) t5);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            t5 = vader_array_ref_load_obj(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) INT64_C(0));
            vader_struct_vader_vm$HostOk_t* _a32_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a32_obj, 1693u);
            _a32_obj->f_value = vader_ref_box(t5);
            t5 = (void*) _a32_obj;
            { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t5 = l9.payload.obj;
    l49 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result_class;
    t7 = (INT32_C(4) & INT32_C(255));
    l67 = (uint8_t) (int32_t) t7;
    if (l49 == l67) {
        l58 = true;
    } else {
        t5 = l9.payload.obj;
        l49 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result_class;
        t7 = (INT32_C(5) & INT32_C(255));
        l67 = (uint8_t) (int32_t) t7;
        l58 = l49 == l67;
    }
    if (!(l58)) {
        t5 = l9.payload.obj;
        l49 = ((vader_struct_vader_vm$ForeignCall_t*) t5)->f_result;
        l16 = vader_vm$read_little_endian(l8, INT64_C(0), INT64_C(8), true);
        t2 = vader_vm$extern_result(l49, l16);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a33_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a33_obj, 1693u);
    _a33_obj->f_value = vader_box_string(494u, l20);
    t5 = (void*) _a33_obj;
    { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$dispatch_import(void* l0, void* l1, int64_t l2, void* l3, int32_t l4, int32_t l5, int32_t l6, bool l7, uint8_t l8) {
    vader_box_t l9 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    bool l12;
    void* l13 = NULL;
    int64_t l14, l16;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_string_t t7 = 0;
    uint64_t t3;
    bool t4;
    int64_t t5;
    int32_t t6;
    uint8_t t8;
    vader_box_t* gc_roots[3] = { &l9, &l15, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l13, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l11, &t2, &t7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l7) {
        l9 = vader_vm$comptime_refusal(l8);
        if (!(l9.tag == 0u)) {
            l10 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
            l11 = l9.payload.s;
            t0 = vader_vm$comptime_refusal_trap(l10, l11);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l8 == INT32_C(1)) {
        l12 = true;
    } else {
        l12 = l8 == INT32_C(2);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l8 == INT32_C(3);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l8 == INT32_C(4);
    }
    if (!(l12)) {
        if (!(l8 == INT32_C(9))) {
            if (l8 == INT32_C(6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_array(t0, l4, 1770u);
                if (l9.tag == 1716u) {
                    t1 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l13 = l9.payload.obj;
                t1 = l9.payload.obj;
                l14 = vader_vm$element_count(t1);
                l9 = vader_vm$array_bytes(l13, l14, l4, 1769u);
                if (!(l9.tag == 1716u)) {
                    t1 = l9.payload.obj;
                    t2 = vader_host_std_core$bytes_to_string(t1);
                    vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a1_obj, 1693u);
                    _a1_obj->f_value = vader_box_string(494u, t2);
                    t1 = (void*) _a1_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(5)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 1766u);
                if (!(l9.tag == 1716u)) {
                    t2 = l9.payload.s;
                    t1 = vader_vm$bytes_to_value(t2, l6);
                    vader_struct_vader_vm$HostOk_t* _a3_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a3_obj, 1693u);
                    _a3_obj->f_value = vader_ref_box(t1);
                    t1 = (void*) _a3_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2174u);
                if (!(l9.tag == 1716u)) {
                    t2 = l9.payload.s;
                    t3 = std_core$string$Hash$hash_vt(t2);
                    vader_struct_vader_vm$HostOk_t* _a5_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a5_obj, 1693u);
                    _a5_obj->f_value = vader_box_i64(498u, ((int64_t) (uint64_t) t3));
                    t1 = (void*) _a5_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(8)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l2)
                t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2001u);
                if (l9.tag == 1716u) {
                    t1 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l14 = vader_chk_add(i64, l2, INT64_C(1));
                vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l14)
                t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l14];
                l15 = vader_vm$read_string(t0, l4, 2000u);
                if (!(l15.tag == 1716u)) {
                    l10 = l9.payload.s;
                    l11 = l15.payload.s;
                    vader_struct_vader_vm$HostOk_t* _a8_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a8_obj, 1693u);
                    _a8_obj->f_value = vader_box_bool(492u, l10 == l11);
                    t1 = (void*) _a8_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l15.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(10)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l2)
                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_i64(t0, l4, 2001u);
                if (l9.tag == 1716u) {
                    t1 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l14 = vader_chk_add(i64, l2, INT64_C(1));
                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l14)
                t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l14];
                l15 = vader_vm$read_i64(t0, l4, 2000u);
                if (!(l15.tag == 1716u)) {
                    l14 = ((int64_t) l9.payload.i);
                    l16 = ((int64_t) l15.payload.i);
                    vader_struct_vader_vm$HostOk_t* _a11_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a11_obj, 1693u);
                    _a11_obj->f_value = vader_box_bool(492u, l14 == l16);
                    t1 = (void*) _a11_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l15.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(11)) {
                t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
                t4 = vader_core_bytecode$is_unsigned_display(t2);
                if (!(t4)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l2)
                    t0 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l2];
                    t2 = vader_vm$display_value(t0);
                    vader_struct_vader_vm$HostOk_t* _a13_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a13_obj, 1693u);
                    _a13_obj->f_value = vader_box_string(494u, t2);
                    t1 = (void*) _a13_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l2)
                l9 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l2];
                if (l9.tag == 498u) {
                    t5 = ((int64_t) l9.payload.i);
                    t2 = std_core$u64$Display$to_string((uint64_t) (int64_t) t5);
                    vader_struct_vader_vm$HostOk_t* _a15_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a15_obj, 1693u);
                    _a15_obj->f_value = vader_box_string(494u, t2);
                    t1 = (void*) _a15_obj;
                    l15 = vader_ref_box(t1);
                    { vader_box_t __vret = l15; vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l9.tag == 497u) {
                    t6 = ((int32_t) l9.payload.i);
                    t2 = std_core$u64$Display$to_string((uint64_t) (int64_t) ((int64_t) (uint32_t) t6));
                    vader_struct_vader_vm$HostOk_t* _a16_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a16_obj, 1693u);
                    _a16_obj->f_value = vader_box_string(494u, t2);
                    t1 = (void*) _a16_obj;
                    l15 = vader_ref_box(t1);
                } else {
                    l10 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
                    l11 = vader_vm$describe_value_tag(l9);
                    l14 = vader_host_std_core$byte_len(l10);
                    l16 = vader_host_std_core$byte_len(l11);
                    l14 = (l14 + l16);
                    l13 = (void*) vader_buffer_new((size_t) (INT64_C(57) + l14));
                    l14 = INT64_C(0);
                    l14 = std_core$write_string_at(l13, l14, l10);
                    l14 = std_core$write_string_at(l13, l14, 99u);
                    l16 = ((int64_t) (int32_t) l4);
                    l14 = std_core$write_int(l13, l14, l16);
                    l14 = std_core$write_string_at(l13, l14, 520u);
                    l14 = std_core$write_string_at(l13, l14, l11);
                    t2 = std_core$finish_buffer(l13, l14);
                    vader_struct_vader_vm$Trap_t* _a17_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a17_obj, 1716u);
                    _a17_obj->f_message = t2;
                    t1 = (void*) _a17_obj;
                    l15 = vader_ref_box(t1);
                }
                { vader_box_t __vret = l15; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(12)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, INT32_C(0))
                t5 = ((int64_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) INT32_C(0)];
                l14 = vader_chk_add(i64, t5, INT64_C(1));
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, INT32_C(0))
                ((int64_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) l14;
                t1 = (void*) &vader_data_169;
                vader_array_t* _a19_slotarr = ((vader_array_t*) t1);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                t1 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
                vader_struct_vader_vm$HostOk_t* _a20_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a20_obj, 1693u);
                _a20_obj->f_value = vader_ref_box(t1);
                t1 = (void*) _a20_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(13)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, INT32_C(0))
                t5 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) INT32_C(0)];
                vader_struct_vader_vm$HostOk_t* _a22_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a22_obj, 1693u);
                _a22_obj->f_value = vader_box_i64(498u, t5);
                t1 = (void*) _a22_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(14)) {
                vader_struct_vader_vm$HostOk_t* _a23_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a23_obj, 1693u);
                _a23_obj->f_value = vader_box_i64(498u, INT64_C(0));
                t1 = (void*) _a23_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(15)) {
                vader_struct_vader_vm$HostOk_t* _a24_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a24_obj, 1693u);
                _a24_obj->f_value = vader_box_i64(498u, INT64_C(0));
                t1 = (void*) _a24_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(16)) {
                vader_struct_vader_vm$HostOk_t* _a25_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a25_obj, 1693u);
                _a25_obj->f_value = vader_box_i64(498u, INT64_C(0));
                t1 = (void*) _a25_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(17)) {
                vader_struct_vader_vm$HostOk_t* _a26_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a26_obj, 1693u);
                _a26_obj->f_value = vader_box_i64(498u, INT64_C(0));
                t1 = (void*) _a26_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(18)) {
                t1 = (void*) &vader_data_169;
                vader_array_t* _a27_slotarr = ((vader_array_t*) t1);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                t1 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) INT64_C(0));
                vader_struct_vader_vm$HostOk_t* _a28_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a28_obj, 1693u);
                _a28_obj->f_value = vader_ref_box(t1);
                t1 = (void*) _a28_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(19)) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(20);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(21);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(22);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(23);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(24);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(25);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(26);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(27);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(28);
            }
            if (l12) {
                t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
                t7 = concat_2(t2, 502u);
                vader_struct_vader_vm$Trap_t* _a29_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a29_obj, 1716u);
                _a29_obj->f_message = t7;
                t1 = (void*) _a29_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(32)) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l2)
                t0 = vader_array_box_slots(_a30_slotarr->buf)[_a30_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2075u);
                if (!(l9.tag == 1716u)) {
                    t2 = l9.payload.s;
                    t5 = vader_host_vader_vm$ffi_open(t2);
                    vader_struct_vader_vm$HostOk_t* _a31_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a31_obj, 1693u);
                    _a31_obj->f_value = vader_box_i64(498u, t5);
                    t1 = (void*) _a31_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(34)) {
                vader_array_t* _a32_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l2)
                t0 = vader_array_box_slots(_a32_slotarr->buf)[_a32_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_i64(t0, l4, 2077u);
                if (l9.tag == 1716u) {
                    t1 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l14 = vader_chk_add(i64, l2, INT64_C(1));
                vader_array_t* _a33_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l14)
                t0 = vader_array_box_slots(_a33_slotarr->buf)[_a33_slotarr->offset + (size_t) l14];
                l15 = vader_vm$read_string(t0, l4, 2078u);
                if (!(l15.tag == 1716u)) {
                    l14 = ((int64_t) l9.payload.i);
                    l10 = l15.payload.s;
                    t5 = vader_host_vader_vm$ffi_symbol(l14, l10);
                    vader_struct_vader_vm$HostOk_t* _a34_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a34_obj, 1693u);
                    _a34_obj->f_value = vader_box_i64(498u, t5);
                    t1 = (void*) _a34_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l15.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(33)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l2)
                t0 = vader_array_box_slots(_a35_slotarr->buf)[_a35_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2076u);
                if (!(l9.tag == 1716u)) {
                    t2 = l9.payload.s;
                    t5 = vader_host_vader_vm$ffi_open_path(t2);
                    vader_struct_vader_vm$HostOk_t* _a36_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a36_obj, 1693u);
                    _a36_obj->f_value = vader_box_i64(498u, t5);
                    t1 = (void*) _a36_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(35)) {
                l9 = vader_vm$hosted_frame_call(l1, l2, l4, 2073u, false);
                if (!(l9.tag == 1716u)) {
                    t0 = vader_vm$zero_value();
                    vader_struct_vader_vm$HostOk_t* _a37_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a37_obj, 1693u);
                    _a37_obj->f_value = t0;
                    t1 = (void*) _a37_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(36)) {
                l9 = vader_vm$hosted_frame_call(l1, l2, l4, 2074u, true);
                if (!(l9.tag == 1716u)) {
                    t2 = l9.payload.s;
                    vader_struct_vader_vm$HostOk_t* _a38_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a38_obj, 1693u);
                    _a38_obj->f_value = vader_box_string(494u, t2);
                    t1 = (void*) _a38_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(30)) {
                t8 = vader_host_std_target$current_os();
                vader_struct_vader_vm$HostOk_t* _a39_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a39_obj, 1693u);
                _a39_obj->f_value = vader_box_i32(497u, ((int32_t) (uint8_t) t8));
                t1 = (void*) _a39_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(31)) {
                t8 = vader_host_std_target$current_arch();
                vader_struct_vader_vm$HostOk_t* _a40_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a40_obj, 1693u);
                _a40_obj->f_value = vader_box_i32(497u, ((int32_t) (uint8_t) t8));
                t1 = (void*) _a40_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(29)) {
                vader_array_t* _a41_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l2)
                t0 = vader_array_box_slots(_a41_slotarr->buf)[_a41_slotarr->offset + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2570u);
                if (!(l9.tag == 1716u)) {
                    l10 = l9.payload.s;
                    t2 = concat_2(2572u, l10);
                    vader_struct_vader_vm$Trap_t* _a42_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a42_obj, 1716u);
                    _a42_obj->f_message = t2;
                    t1 = (void*) _a42_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (!(l8 == INT32_C(0))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    l10 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l14 = vader_host_std_core$byte_len(l10);
    l13 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l14));
    l14 = INT64_C(0);
    l14 = std_core$write_string_at(l13, l14, 2978u);
    l14 = std_core$write_string_at(l13, l14, l10);
    l14 = std_core$write_string_at(l13, l14, 313u);
    l16 = ((int64_t) (int32_t) l4);
    l14 = std_core$write_int(l13, l14, l16);
    t2 = std_core$finish_buffer(l13, l14);
    vader_struct_vader_vm$Trap_t* _a43_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a43_obj, 1716u);
    _a43_obj->f_message = t2;
    t1 = (void*) _a43_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
        { vader_gc_top = gc_frame.prev; return 2530u; }
    }
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 494u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 857u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = INT64_C(0);
    t0 = (void*) &vader_data_56;
    l4 = ((vader_array_t*) t0)->length;
    while ((l3 < l4)) {
        t1 = (((int32_t) (int64_t) l3) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        t1 = ((INT32_C(1) << (l5 & 31)) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t1;
        if ((l0 & l6) != INT32_C(0)) {
            if (!(l2)) {
                std_string__builder$append(l1, 3258u);
            }
            t0 = (void*) &vader_data_56;
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
    if (l0.tag == 497u) {
        t0 = ((int32_t) l0.payload.i);
        l1 = vader_vm$I32Val$std_core$Display$to_string(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 498u) {
        t1 = ((int64_t) l0.payload.i);
        l1 = vader_vm$I64Val$std_core$Display$to_string(t1);
    } else if ((l0.tag == 503u || l0.tag == 504u)) {
        t2 = ((double) l0.payload.f);
        l1 = vader_vm$F64Val$std_core$Display$to_string(t2);
    } else if (l0.tag == 494u) {
        t3 = l0.payload.s;
        l1 = vader_vm$StringVal$std_core$Display$to_string(t3);
    } else if (l0.tag == 1713u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$StructVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 1681u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$ArrayVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 1686u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$FnVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 1696u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$NullVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 492u) {
        t5 = l0.payload.b;
        l1 = vader_vm$BoolVal$std_core$Display$to_string(t5);
    } else if (l0.tag == 493u) {
        t6 = ((uint32_t) l0.payload.i);
        l1 = vader_vm$CharVal$std_core$Display$to_string(t6);
    } else if (l0.tag == 1717u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$TypeVal$std_core$Display$to_string(t4);
    } else {
        if (!(l0.tag == 1697u)) {
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
    l4 = std_core$write_string_at(l6, l4, 99u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l6, l4, l5);
    l4 = std_core$write_string_at(l6, l4, 149u);
    l4 = std_core$write_string_at(l6, l4, l3);
    l4 = std_core$write_string_at(l6, l4, 307u);
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
    l2 = vader_vm$read_i32(l2, l3, 2448u);
    if (l2.tag == 1716u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l3, 2452u);
    if (l4.tag == 1716u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l5 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$read_obj(l5, l3, 2451u);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(4));
    l6 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$read_i32(l6, l3, 2447u);
    if (l6.tag == 1716u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    l7 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l7 = vader_vm$read_obj(l7, l3, 2446u);
    if (l7.tag == 1716u) {
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
        l1 = std_core$write_string_at(l9, l1, 2449u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l10 = ((int64_t) (int32_t) t2);
        l1 = std_core$write_int(l9, l1, l10);
        t3 = std_core$finish_buffer(l9, l1);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
        l12 = std_core$write_string_at(l9, l12, 2450u);
        l12 = std_core$write_int(l9, l12, l10);
        l12 = std_core$write_string_at(l9, l12, 383u);
        l13 = vader_chk_add(i64, l10, l1);
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 351u);
        t1 = l5.payload.obj;
        l13 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 99u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core$write_int(l9, l12, l13);
        t3 = std_core$finish_buffer(l9, l12);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1716u);
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
        l12 = std_core$write_string_at(l9, l12, 2445u);
        l12 = std_core$write_int(l9, l12, l11);
        l12 = std_core$write_string_at(l9, l12, 383u);
        l13 = vader_chk_add(i64, l11, l1);
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 351u);
        t1 = l7.payload.obj;
        l13 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
        l12 = std_core$write_int(l9, l12, l13);
        l12 = std_core$write_string_at(l9, l12, 99u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core$write_int(l9, l12, l13);
        t3 = std_core$finish_buffer(l9, l12);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 1716u);
        _a2_obj->f_message = t3;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_reserve(29u, (int64_t) l1, 1u, 499u);
    l9 = (void*) _a3_arr;
    l12 = INT64_C(0);
    vader_array_t* _pc338_hdr = (vader_array_t*) l9;
    size_t _pc338_len = _pc338_hdr->length;
    size_t _pc338_cap = vader_array_is_borrowed(_pc338_hdr) ? (size_t) 0 : _pc338_hdr->capacity;
    void* _pc338_slots = _pc338_hdr->buf->slots;
    for (;;) {
        if ((l12 < l1)) {
            t1 = l5.payload.obj;
            l14 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
            l13 = vader_chk_add(i64, l10, l12);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
            t4 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l13, 499u);
            l15 = ((uint8_t) t4.payload.i);
            if (VADER_LIKELY(_pc338_len < _pc338_cap)) {
                ((uint8_t*) _pc338_slots)[_pc338_len] = (uint8_t) ((int32_t) (uint8_t) l15);
                _pc338_len += 1;
            } else {
                _pc338_hdr->length = _pc338_len;
                if (_pc338_hdr->buf->length < _pc338_len) {
                    _pc338_hdr->buf->length = _pc338_len;
                }
                vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l15);
                _pc338_hdr = (vader_array_t*) l9;
                _pc338_len = _pc338_hdr->length;
                _pc338_cap = vader_array_is_borrowed(_pc338_hdr) ? (size_t) 0 : _pc338_hdr->capacity;
                _pc338_slots = _pc338_hdr->buf->slots;
            }
            l12 = (l12 + INT64_C(1));
            continue;
        }
        _pc338_hdr->length = _pc338_len;
        if (_pc338_hdr->buf->length < _pc338_len) {
            _pc338_hdr->buf->length = _pc338_len;
        }
        break;
    }
    l10 = INT64_C(0);
    while ((l10 < l1)) {
        t1 = l7.payload.obj;
        l14 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
        l12 = vader_chk_add(i64, l11, l10);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        t4 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l10, 499u);
        l15 = ((uint8_t) t4.payload.i);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
        ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l12] = (uint8_t) (int32_t) (uint8_t) l15;
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
    vader_obj_header_init(_a0_obj, 1710u);
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
    if (l2.tag == 1082u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1083u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 1084u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1081u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
        l5 = vader_vm$indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1104u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1007u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1030u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1031u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 1000u) {
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
    } else if (l2.tag == 1001u) {
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
    } else if (l2.tag == 1002u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        l5 = vader_vm$indirect_effect(l0, l6);
    } else if (l2.tag == 1127u) {
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
    } else if (l2.tag == 1029u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1028u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1086u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1108u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l5 = vader_vm$struct_new_effect(l0, l6);
    } else if (l2.tag == 956u) {
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
    } else if (l2.tag == 1111u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 961u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1110u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
        l5 = vader_vm$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1004u) {
        t0 = l2.payload.obj;
        t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_vm$effect(INT64_C(2), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 1005u) {
        t0 = l2.payload.obj;
        t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_vm$effect(INT64_C(1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if ((l2.tag == 988u || l2.tag == 1003u || l2.tag == 1016u || l2.tag == 1037u || l2.tag == 1057u || l2.tag == 1088u)) {
        t0 = vader_vm$effect(INT64_C(0), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 955u || l2.tag == 959u || l2.tag == 984u || l2.tag == 985u || l2.tag == 991u || l2.tag == 995u || l2.tag == 1006u || l2.tag == 1014u || l2.tag == 1025u || l2.tag == 1027u || l2.tag == 1034u || l2.tag == 1047u || l2.tag == 1054u || l2.tag == 1067u || l2.tag == 1089u || l2.tag == 1092u || l2.tag == 1095u || l2.tag == 1107u || l2.tag == 1124u)) {
        t0 = vader_vm$effect(INT64_C(1), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 954u || l2.tag == 960u || l2.tag == 987u || l2.tag == 989u || l2.tag == 990u || l2.tag == 992u || l2.tag == 996u || l2.tag == 1015u || l2.tag == 1017u || l2.tag == 1018u || l2.tag == 1019u || l2.tag == 1020u || l2.tag == 1021u || l2.tag == 1022u || l2.tag == 1023u || l2.tag == 1024u || l2.tag == 1026u || l2.tag == 1032u || l2.tag == 1033u || l2.tag == 1035u || l2.tag == 1036u || l2.tag == 1038u || l2.tag == 1039u || l2.tag == 1040u || l2.tag == 1041u || l2.tag == 1042u || l2.tag == 1043u || l2.tag == 1044u || l2.tag == 1045u || l2.tag == 1046u || l2.tag == 1048u || l2.tag == 1049u || l2.tag == 1050u || l2.tag == 1051u || l2.tag == 1052u || l2.tag == 1053u || l2.tag == 1055u || l2.tag == 1056u || l2.tag == 1058u || l2.tag == 1059u || l2.tag == 1060u || l2.tag == 1061u || l2.tag == 1062u || l2.tag == 1063u || l2.tag == 1064u || l2.tag == 1065u || l2.tag == 1066u || l2.tag == 1068u || l2.tag == 1069u || l2.tag == 1070u || l2.tag == 1071u || l2.tag == 1074u || l2.tag == 1075u || l2.tag == 1076u || l2.tag == 1077u || l2.tag == 1078u || l2.tag == 1079u || l2.tag == 1080u || l2.tag == 1090u || l2.tag == 1091u || l2.tag == 1103u || l2.tag == 1105u || l2.tag == 1106u || l2.tag == 1112u || l2.tag == 1113u || l2.tag == 1114u || l2.tag == 1115u || l2.tag == 1116u || l2.tag == 1117u || l2.tag == 1118u || l2.tag == 1119u || l2.tag == 1120u || l2.tag == 1121u || l2.tag == 1122u || l2.tag == 1123u)) {
        t0 = vader_vm$effect(INT64_C(2), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 957u || l2.tag == 958u || l2.tag == 1109u || l2.tag == 1125u)) {
        t0 = vader_vm$effect(INT64_C(2), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 962u || l2.tag == 997u || l2.tag == 1096u || l2.tag == 1097u || l2.tag == 1098u || l2.tag == 1099u || l2.tag == 1100u || l2.tag == 1101u || l2.tag == 1102u)) {
        t0 = vader_vm$effect(INT64_C(3), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if (l2.tag == 963u) {
        t0 = vader_vm$effect(INT64_C(3), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 953u || l2.tag == 1087u)) {
        t0 = vader_vm$effect(INT64_C(5), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 952u || l2.tag == 1010u || l2.tag == 1011u)) {
        t0 = vader_vm$effect(INT64_C(1), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 986u || l2.tag == 1009u || l2.tag == 1013u || l2.tag == 1085u)) {
        t0 = vader_vm$effect(INT64_C(0), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 994u || l2.tag == 1072u)) {
        vader_struct_vader_vm$StackEffect_t* _a2_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
        vader_obj_header_init(_a2_obj, 1710u);
        _a2_obj->f_pops = INT64_C(1);
        _a2_obj->f_pushes = INT64_C(0);
        _a2_obj->f_flow = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 993u || l2.tag == 1012u)) {
        vader_struct_vader_vm$StackEffect_t* _a3_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
        vader_obj_header_init(_a3_obj, 1710u);
        _a3_obj->f_pops = INT64_C(0);
        _a3_obj->f_pushes = INT64_C(0);
        _a3_obj->f_flow = (uint8_t) 1;
        t0 = (void*) _a3_obj;
        l5 = vader_ref_box(t0);
    } else {
        if (!((l2.tag == 1093u || l2.tag == 1094u || l2.tag == 1126u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_vm$StackEffect_t* _a4_obj = (vader_struct_vader_vm$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackEffect_t));
        vader_obj_header_init(_a4_obj, 1710u);
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
    void* t0;
    uint8_t t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        t1 = vader_vm$byte_at(t0, l1);
        return vader_box_i32(497u, ((int32_t) (uint8_t) t1));
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    return t2;
}

int64_t vader_vm$element_count(void* l0) {
    vader_box_t l1;
    void* t0;
    int64_t t1;
    l1 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_vm$StringWindow_t*) t0)->f_length;
        return t1;
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements)->length;
    return t1;
}

static vader_string_t vader_vm$element_label(int32_t l0) {
    if (l0 == INT32_C(116)) {
        return 2384u;
    }
    if (l0 == INT32_C(117)) {
        return 2797u;
    }
    if (!(l0 == INT32_C(115))) {
        return 1661u;
    }
    return 1676u;
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
        if (l4.tag == 965u) {
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
        t0 = vader_vm$receiver_trap(l0, l8, l4, l5, l7, 1647u);
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
    l8 = std_core$write_string_at(l11, l8, 151u);
    l14 = ((int64_t) (int32_t) l12);
    l8 = std_core$write_int(l11, l8, l14);
    l8 = std_core$write_string_at(l11, l8, 202u);
    l14 = vader_vm$element_count(l9);
    l8 = std_core$write_int(l11, l8, l14);
    l8 = std_core$write_string_at(l11, l8, 350u);
    l14 = ((int64_t) (int32_t) l13);
    l8 = std_core$write_int(l11, l8, l14);
    t2 = std_core$finish_buffer(l11, l8);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 1716u);
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

static void* vader_vm$empty_machine(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[11] = { &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 8u, 498u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 499u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(414u, 0u, 0u, 2456u);
    l3 = (void*) _a2_arr;
    l4 = vader_vm$new_run_host();
    l5 = vader_vm$scratch_frame();
    vader_array_t* _a3_arr = vader_array_new(372u, 0u, 13u, 1704u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(28u, 0u, 8u, 498u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 8u, 498u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(414u, 0u, 0u, 2456u);
    l9 = (void*) _a6_arr;
    t0 = (void*) &vader_data_169;
    vader_array_t* _a7_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    l10 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_vm$RegMachine_t* _a8_obj = (vader_struct_vader_vm$RegMachine_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegMachine_t));
    vader_obj_header_init(_a8_obj, 1705u);
    _a8_obj->f_bits = l1;
    _a8_obj->f_tags = l2;
    _a8_obj->f_refs = l3;
    _a8_obj->f_run = l4;
    _a8_obj->f_scratch = l5;
    _a8_obj->f_frame_code = l6;
    _a8_obj->f_frame_base = l7;
    _a8_obj->f_frame_return = l8;
    _a8_obj->f_defers = l9;
    _a8_obj->f_defer_count = INT64_C(0);
    _a8_obj->f_debug = l0;
    _a8_obj->f_null_value = vader_ref_box(l10);
    t0 = (void*) _a8_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l4, 499u);
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
    l2 = std_collections$Map$std_core$Index$at__string__i32(((vader_struct_vader_vm$VmState_t*) l0)->f_fn_index_by_name, l1);
    if (!(l2.tag == 0u)) {
        t0 = ((int32_t) l2.payload.i);
        { vader_box_t __vret = vader_box_i32(497u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_3(2508u, l1, 307u);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1716u);
    _a0_obj->f_message = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$environment_params(void* l0) {
    if (!(((vader_struct_vader_vm$FnVal_t*) l0)->f_env.tag == 0u)) {
        return INT64_C(1);
    }
    return INT64_C(0);
}

static void* vader_vm$exception_stop(vader_string_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(368u, 0u, 13u, 1700u);
    l3 = (void*) _a0_arr;
    vader_struct_vader_vm$PauseCtx_t* _a1_obj = (vader_struct_vader_vm$PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseCtx_t));
    vader_obj_header_init(_a1_obj, 1699u);
    _a1_obj->f_reason = 2010u;
    _a1_obj->f_text = l0;
    _a1_obj->f_thread_id = l1;
    _a1_obj->f_frames = l3;
    _a1_obj->f_threads = l2;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_copy(void* l0) {
    int64_t l1, l8, l9, l10, l11;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l3;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t t0;
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
    l2 = vader_vm$read_i32(l2, l3, 1657u);
    if (l2.tag == 1716u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l3, 1656u);
    if (l4.tag == 1716u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$peek_array_mut(l0, l1, l3, 1655u);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(4));
    l6 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$read_i32(l6, l3, 1660u);
    if (l6.tag == 1716u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(5));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l7 = vader_vm$peek_array_mut(l0, l1, l3, 1659u);
    if (l7.tag == 1716u) {
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
    l11 = vader_vm$element_count(t1);
    if ((l10 > l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(64));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, 1658u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l11 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l12, l10, l11);
        t3 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_chk_add(i64, l9, l1);
    t1 = l5.payload.obj;
    l11 = vader_vm$element_count(t1);
    if ((l10 > l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(103));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, 1654u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l11 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l12, l10, l11);
        t3 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1716u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_reserve(414u, (int64_t) l1, 0u, 2456u);
    l12 = (void*) _a2_arr;
    l10 = INT64_C(0);
    while ((l10 < l1)) {
        l13 = l7.payload.obj;
        l11 = vader_chk_add(i64, l8, l10);
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
        l10 = vader_chk_add(i64, l9, l8);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        l2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l8];
        vader_array_t* _a4_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l10] = l2;
        VADER_WRITE_BARRIER(_a4_slotarr->buf);
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
    int64_t l1, l7;
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l8 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l8 };
    void** gc_raw_roots[4] = { &l0, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$peek_array_mut(l0, l1, l2, 1668u);
    if (l3.tag == 1716u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l1, l2, 1667u);
    if (l4.tag == 1716u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    vader_vm$own_bytes(t1);
    t1 = l3.payload.obj;
    if (((vader_struct_vader_vm$ArrayVal_t*) t1)->f_raw.tag == 0u) {
        t1 = l4.payload.obj;
        l5 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
        vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
    } else {
        l1 = INT64_C(0);
        t1 = l3.payload.obj;
        l7 = vader_vm$element_count(t1);
        while ((l1 < l7)) {
            t1 = l4.payload.obj;
            l5 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_elements;
            t1 = l3.payload.obj;
            l8 = vader_vm$element_at(t1, l1);
            vader_array_push((vader_array_t*) l5, l8);
            l1 = (l1 + INT64_C(1));
        }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l2;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$exec_array_repeat(void* l0) {
    int64_t l1, l5, l7, l8;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3;
    void* l6 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[3] = { &l0, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l2 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$read_i32(l2, l3, 1672u);
    if (l2.tag == 1716u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l1, l3, 1673u);
    if (l4.tag == 1716u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    l1 = vader_vm$clamp_nonneg(t2);
    t1 = l4.payload.obj;
    l5 = vader_vm$element_count(t1);
    t0 = vader_chk_mul(i64, l1, l5);
    vader_array_t* _a0_arr = vader_array_reserve(414u, (int64_t) t0, 0u, 2456u);
    l6 = (void*) _a0_arr;
    l7 = INT64_C(0);
    while ((l7 < l1)) {
        l8 = INT64_C(0);
        while ((l8 < l5)) {
            t1 = l4.payload.obj;
            l2 = vader_vm$element_at(t1, l8);
            vader_array_push((vader_array_t*) l6, l2);
            l8 = (l8 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    t1 = l4.payload.obj;
    t2 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a1_obj, 1681u);
    _a1_obj->f_type_id = t2;
    _a1_obj->f_elements = l6;
    _a1_obj->f_raw = vader_box_obj(0u, NULL);
    l6 = (void*) _a1_obj;
    vader_vm$push_val(l0, l1, vader_ref_box(l6));
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l1;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$exec_array_reserve(void* l0, void* l1) {
    int64_t l2;
    vader_box_t l3 = vader_box_null();
    int32_t l4;
    void* l5 = NULL;
    int64_t t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l4, 1675u);
    if (!(l3.tag == 1716u)) {
        t1 = ((int32_t) l3.payload.i);
        t0 = vader_vm$clamp_nonneg(t1);
        vader_array_t* _a0_arr = vader_array_reserve(414u, (int64_t) t0, 0u, 2456u);
        l5 = (void*) _a0_arr;
        t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        t1 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) l1)->f_type_id;
        vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
        vader_obj_header_init(_a1_obj, 1681u);
        _a1_obj->f_type_id = t1;
        _a1_obj->f_elements = l5;
        _a1_obj->f_raw = vader_box_obj(0u, NULL);
        l5 = (void*) _a1_obj;
        vader_vm$push_val(l0, l2, vader_ref_box(l5));
        t1 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l4 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_slice(void* l0, void* l1) {
    int64_t l2, l7, l8;
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
    l3 = vader_vm$read_i32(l3, l4, 1678u);
    if (l3.tag == 1716u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$read_i32(l5, l4, 1679u);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$peek_array_mut(l0, l2, l4, 1680u);
    if (l6.tag == 1716u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l6.payload.obj;
    l2 = vader_vm$element_count(t1);
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
    l9 = l6.payload.obj;
    l4 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) l1)->f_type_id;
    l9 = vader_vm$view_of(l9, l4, l7, l8);
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
    l2 = vader_vm$read_string(l2, l3, 1743u);
    if (l2.tag == 1716u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l3, 1741u);
    if (l4.tag == 1716u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(3));
    l5 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$read_obj(l5, l3, 1742u);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l2.payload.s;
    l3 = ((int32_t) l4.payload.i);
    l1 = vader_host_std_core$byte_len(l6);
    t1 = l5.payload.obj;
    l7 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_vm$check_byte_range(l3, l1, l7, 1740u, l8);
    if (l2.tag == 1716u) {
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
    l2 = vader_vm$read_string(l2, l3, 2806u);
    if (l2.tag == 1716u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm$peek_val(l0, l1);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_string(l4, l3, 2806u);
    if (!(l4.tag == 1716u)) {
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
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = 2051u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        t1 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a1_obj, 1693u);
        _a1_obj->f_value = t1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a2_obj, 1693u);
        _a2_obj->f_value = vader_box_bool(492u, ((int32_t) (int64_t) (l1 & INT64_C(4294967295))) != INT32_C(0));
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
        vader_obj_header_init(_a3_obj, 1693u);
        _a3_obj->f_value = vader_box_i64(498u, l1);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a4_obj, 1693u);
    _a4_obj->f_value = vader_box_i32(497u, ((int32_t) (int64_t) l1));
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
    if (!(l0.tag == 498u)) {
        l4 = l0;
        l5 = l2;
        l6 = vader_host_std_core$byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(34) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l7, l6, 2050u);
        l6 = std_core$write_string_at(l7, l6, l5);
        l6 = std_core$write_string_at(l7, l6, 1118u);
        l6 = std_core$write_int(l7, l6, l3);
        l5 = std_core$finish_buffer(l7, l6);
        t0 = vader_vm$read_i64(l4, l1, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int64_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(498u, t1); vader_gc_top = gc_frame.prev; return __vret; }
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

static int32_t vader_vm$ffi_result_class(uint8_t l0, bool l1) {
    if (l1) {
        return INT32_C(5);
    }
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
    if (!(l5.tag == 979u)) {
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
                if (l5.tag == 975u) {
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
        if (l5.tag == 978u) {
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
        if (l5.tag == 979u) {
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
    if (!(l4.tag == 975u)) {
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
        if (l4.tag == 975u) {
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
        if (l4.tag == 965u) {
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
        if (l4.tag == 975u) {
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
        if (l4.tag == 965u) {
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

static void* vader_vm$finish_guest_threads(bool l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    int64_t l4, l7, l8, l11;
    vader_box_t l10 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l10 };
    void** gc_raw_roots[6] = { &l2, &l3, &l5, &l6, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$guest_threads();
    ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_entry_machine = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_vm$GuestThreads_t*) l2);
    t0 = std_collections$len__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live);
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(28u, 0u, 8u, 498u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live;
    l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_size;
    if ((INT64_C(0) < l4)) {
        l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_size;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_reserve(28u, (int64_t) l4, 8u, 498u);
    l5 = (void*) _a1_arr;
    l6 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_ekeys;
    l4 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_size;
    while ((l4 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l8 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        vader_array_push_i64((vader_array_t*) l5, l8);
        l4 = (l4 + INT64_C(1));
    }
    vader_struct___lambda_env_vader_vm_7_t* _a3_obj = (vader_struct___lambda_env_vader_vm_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_7_t));
    vader_obj_header_init(_a3_obj, 671u);
    _a3_obj->f_cap_0 = l2;
    t1 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 465u);
    _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_6;
    _a4_closure->env = t1;
    l3 = (void*) _a4_closure;
    l3 = std_sort$sort__i64(l5, l3);
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 8u, 498u);
    l5 = (void*) _a5_arr;
    l6 = l3;
    l4 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l8 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
        l10 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live, l8);
        if (l10.tag == 0u) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l9 = l10.payload.obj;
        t2 = vader_vm$is_leaving(l2, l9);
        if (t2) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l11 = ((vader_struct_vader_vm$GuestThread_t*) l9)->f_number;
        vader_array_push_i64((vader_array_t*) l5, l11);
        if (l0) {
            t0 = ((vader_struct_vader_vm$GuestThread_t*) l9)->f_number;
            vader_vm$announce_cancelled(t0, l1);
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_array_t*) l3)->length;
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
        t0 = ((int64_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
        vader_vm$cancel(t0);
        l7 = (l7 + INT64_C(1));
    }
    l4 = vader_host_std_runtime_scheduler$current_thread();
    ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_waiter = l4;
    t0 = ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_waiter;
    vader_host_std_runtime_scheduler$wake(t0);
    vader_host_std_runtime_scheduler$park();
    for (;;) {
        t0 = std_collections$len__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live);
        if ((t0 > INT64_C(0))) {
            vader_host_std_runtime_scheduler$park();
            continue;
        }
        break;
    }
    ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_waiter = INT64_C(-1);
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
            vader_obj_header_init(_a0_obj, 1698u);
            _a0_obj->f_value = INT32_C(0);
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_vm$register_value(l0, INT64_C(0));
        l4 = vader_vm$read_i32(t1, INT32_C(0), 2652u);
        if (!(l4.tag == 1716u)) {
            t2 = ((int32_t) l4.payload.i);
            vader_struct_vader_vm$Ok_t* _a1_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
            vader_obj_header_init(_a1_obj, 1698u);
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
        vader_obj_header_init(_a3_obj, 1698u);
        _a3_obj->f_value = INT32_C(0);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$Ok_t* _a4_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
    vader_obj_header_init(_a4_obj, 1698u);
    _a4_obj->f_value = INT32_C(0);
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$first_bytes(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_text;
    l2 = vader_host_std_core$bytes(t0);
    l3 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_offset;
    t1 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_offset;
    l4 = vader_chk_add(i64, t1, l1);
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (int64_t) l3, (int64_t) l4);
    t2 = (void*) _a0_arr;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    l7 = std_core$write_string_at(l8, l7, 1894u);
    l7 = std_core$write_int(l8, l7, l4);
    l7 = std_core$write_string_at(l8, l7, 242u);
    l7 = std_core$write_int(l8, l7, l6);
    l7 = std_core$write_string_at(l8, l7, 93u);
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
    l4 = std_core$write_string_at(l5, l4, 136u);
    l6 = ((int64_t) (int32_t) l0);
    l4 = std_core$write_int(l5, l4, l6);
    l4 = std_core$write_string_at(l5, l4, 204u);
    l6 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l5, l4, l6);
    t0 = std_core$finish_buffer(l5, l4);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1716u);
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
    if (l3.tag == 968u) {
        t1 = l3.payload.obj;
        return vader_ref_box(t1);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_vm$foreign_call_of(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    int64_t l6, l13, l14;
    int32_t l7;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    uint8_t l16, l19;
    bool l17, l18;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2, t3;
    vader_box_t* gc_roots[3] = { &l3, &l8, &l9 };
    void** gc_raw_roots[6] = { &l0, &l4, &l5, &l10, &l15, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_foreign_calls);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l6 = vader_vm$adapter_of(l0, l1);
    l3 = vader_vm$callee_of(l0, l4, l6, l2);
    if (l3.tag == 1716u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_core_bytecode$bc_single_result_type(((vader_struct_vader_core_bytecode$BcImport_t*) l4)->f_signature);
    l8 = vader_core_bytecode$mirror_at(l5, l7);
    l9 = vader_box_obj(0u, NULL);
    if (!(l8.tag == 0u)) {
        t0 = l8.payload.obj;
        l10 = vader_core_bytecode$c_struct_layout(((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields, l5);
        if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_unknown_field.tag == 0u)) {
            l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l4)->f_extern_name;
            l12 = ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_unknown_field.payload.s;
            l13 = vader_host_std_core$byte_len(l11);
            l14 = vader_host_std_core$byte_len(l12);
            l13 = (l13 + l14);
            l15 = (void*) vader_buffer_new((size_t) (INT64_C(123) + l13));
            l13 = INT64_C(0);
            l13 = std_core$write_string_at(l15, l13, 2050u);
            l13 = std_core$write_string_at(l15, l13, l11);
            l13 = std_core$write_string_at(l15, l13, 1120u);
            l14 = ((int64_t) (int32_t) l2);
            l13 = std_core$write_int(l15, l13, l14);
            l13 = std_core$write_string_at(l15, l13, 526u);
            l13 = std_core$write_string_at(l15, l13, l12);
            l13 = std_core$write_string_at(l15, l13, 1226u);
            t1 = std_core$finish_buffer(l15, l13);
            vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a2_obj, 1716u);
            _a2_obj->f_message = t1;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l15 = l8.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_size;
        vader_struct_vader_vm$ResultMirror_t* _a3_obj = (vader_struct_vader_vm$ResultMirror_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ResultMirror_t));
        vader_obj_header_init(_a3_obj, 1707u);
        _a3_obj->f_type_index = l7;
        _a3_obj->f_mirror = l15;
        _a3_obj->f_size = l13;
        t0 = (void*) _a3_obj;
        l9 = vader_ref_box(t0);
    }
    l16 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l4)->f_signature);
    l17 = vader_vm$ffi_result_is_opt(l5, l7, (uint8_t) 12);
    l13 = ((int64_t) l3.payload.i);
    l18 = l6 != INT64_C(0);
    t2 = vader_vm$ffi_result_class(l16, l17);
    t3 = (t2 & INT32_C(255));
    l19 = (uint8_t) (int32_t) t3;
    if (l17) {
        l17 = true;
    } else {
        l17 = vader_vm$ffi_result_is_opt(l5, l7, (uint8_t) 15);
    }
    vader_struct_vader_vm$ForeignCall_t* _a4_obj = (vader_struct_vader_vm$ForeignCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ForeignCall_t));
    vader_obj_header_init(_a4_obj, 1687u);
    _a4_obj->f_callee = l13;
    _a4_obj->f_through_adapter = l18;
    _a4_obj->f_result = l16;
    _a4_obj->f_result_mirror = l9;
    _a4_obj->f_result_class = l19;
    _a4_obj->f_null_on_zero = l17;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_foreign_calls);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l1, l4);
    VADER_WRITE_BARRIER(_a5_slotarr->buf);
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$forget(void* l0, int64_t l1) {
    int64_t t0;
    std_collections$remove__i64__vader_vm_GuestThread(((vader_struct_vader_vm$GuestThreads_t*) l0)->f_live, l1);
    t0 = std_collections$len__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l0)->f_live);
    if (t0 == INT64_C(0)) {
        t0 = ((vader_struct_vader_vm$GuestThreads_t*) l0)->f_waiter;
        if ((t0 >= INT64_C(0))) {
            t0 = ((vader_struct_vader_vm$GuestThreads_t*) l0)->f_waiter;
            vader_host_std_runtime_scheduler$wake(t0);
            return;
        }
        return;
    }
    return;
}

static void* vader_vm$frame_names(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code)->length;
    vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) t0, 0u, 494u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(494u, l5));
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
    t1 = concat_3(1087u, l2, 1123u);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
    vader_box_t l1;
    bool l2;
    void* t0;
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
        l1 = vader_box_i32(497u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l1 = vader_box_i64(498u, INT64_C(0));
    } else {
        if (l0 == INT32_C(8)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l1 = vader_box_f64(504u, 0.0);
        } else if (l0 == INT32_C(10)) {
            l1 = vader_box_bool(492u, false);
        } else if (l0 == INT32_C(11)) {
            l1 = vader_box_i32(493u, (int32_t) ((uint32_t) 0));
        } else if (l0 == INT32_C(12)) {
            l1 = vader_box_string(494u, 0u);
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
            t0 = (void*) &vader_data_169;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
            l1 = vader_ref_box(t0);
        }
    }
    return l1;
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

static void* vader_vm$guest_threads(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_27;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_28;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_29;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_29 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_vader_vm$guest_threads$keep;
    t3 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t3)) {
        vader_unreachable("singleton `guest_threads` called while it initialises");
    }
    t1 = vader_global_28;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$guest_threads$keep(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_27;
    if (!(t0 == INT32_C(2))) {
        t1 = vader_vm$guest_threads$singleton();
        vader_global_28 = t1;
        vader_global_27 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_vm$guest_threads$singleton(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 8u, 498u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 505u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 497u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i64__Any_t* _a3_obj = (vader_struct_std_collections$Map__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__Any_t));
    vader_obj_header_init(_a3_obj, 732u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_vm$GuestThreads_t* _a4_obj = (vader_struct_vader_vm$GuestThreads_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$GuestThreads_t));
    vader_obj_header_init(_a4_obj, 1692u);
    _a4_obj->f_live = t0;
    _a4_obj->f_numbered = INT64_C(0);
    _a4_obj->f_entry_thread = INT64_C(-1);
    _a4_obj->f_waiter = INT64_C(-1);
    _a4_obj->f_entry_machine = vader_box_obj(0u, NULL);
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$hosted_frame_call(void* l0, int64_t l1, int32_t l2, vader_string_t l3, bool l4) {
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    vader_string_t l6 = 0;
    int64_t l7, l11, l16;
    void* l10 = NULL;
    void* l15 = NULL;
    uint8_t l14;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    vader_box_t* gc_roots[6] = { &l5, &l8, &l9, &l12, &l13, &t3 };
    void** gc_raw_roots[4] = { &l0, &l10, &l15, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    l6 = concat_2(l3, 130u);
    l5 = vader_vm$read_i64(l5, l2, l6);
    if (l5.tag == 1716u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_chk_add(i64, l1, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    l8 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l7];
    l6 = concat_2(l3, 115u);
    l8 = vader_vm$read_array(l8, l2, l6);
    if (l8.tag == 1716u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_chk_add(i64, l1, INT64_C(2));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
    l6 = concat_2(l3, 133u);
    l9 = vader_vm$read_array(l9, l2, l6);
    if (l9.tag == 1716u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = l8.payload.obj;
    t0 = l8.payload.obj;
    l7 = vader_vm$element_count(t0);
    l6 = concat_2(l3, 116u);
    l8 = vader_vm$array_bytes(l10, l7, l2, l6);
    if (l8.tag == 1716u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l9.payload.obj;
    vader_vm$own_bytes(t0);
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 1u, 499u);
    l10 = (void*) _a3_arr;
    l7 = INT64_C(0);
    t0 = l9.payload.obj;
    l11 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements)->length;
    while ((l7 < l11)) {
        t0 = l9.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        l12 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
        l6 = concat_2(l3, 134u);
        l13 = vader_vm$read_i64(l12, l2, l6);
        if (l13.tag == 1716u) {
            t0 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int64_t) l13.payload.i);
        t2 = (((int32_t) (int64_t) t1) & INT32_C(255));
        l14 = (uint8_t) (int32_t) t2;
        vader_array_push_u8((vader_array_t*) l10, (int32_t) (uint8_t) l14);
        l7 = (l7 + INT64_C(1));
    }
    l7 = ((int64_t) l5.payload.i);
    l15 = l8.payload.obj;
    l6 = vader_vm$call_foreign(l7, l4, l15, l10, INT64_C(-1));
    l7 = INT64_C(0);
    t0 = l9.payload.obj;
    l11 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements)->length;
    while ((l7 < l11)) {
        t0 = l9.payload.obj;
        l15 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
        t0 = l9.payload.obj;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l5 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l7];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t3 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l7, 499u);
        t4 = ((uint8_t) t3.payload.i);
        l16 = ((int64_t) (uint8_t) t4);
        l8 = vader_vm$retyped_int(l5, l16);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
        vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7] = l8;
        VADER_WRITE_BARRIER(_a7_slotarr->buf);
        l7 = (l7 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_string(494u, l6); vader_gc_top = gc_frame.prev; return __vret; }
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
    l6 = vader_vm$read_fn(t0, l4, 1798u);
    if (l6.tag == 1716u) {
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
        t1 = vader_vm$fn_index_trap(l7, l4, 1795u);
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
    l9 = std_core$write_string_at(l14, l9, 1796u);
    l13 = ((int64_t) (int32_t) l4);
    l9 = std_core$write_int(l14, l9, l13);
    l9 = std_core$write_string_at(l14, l9, 509u);
    l9 = std_core$write_int(l14, l9, l5);
    l9 = std_core$write_string_at(l14, l9, l11);
    l9 = std_core$write_string_at(l14, l9, 104u);
    l9 = std_core$write_string_at(l14, l9, l12);
    l9 = std_core$write_string_at(l14, l9, 314u);
    l5 = ((vader_struct_vader_vm$RegFunction_t*) l10)->f_params;
    l9 = std_core$write_int(l14, l9, l5);
    l9 = std_core$write_string_at(l14, l9, 206u);
    t2 = std_core$finish_buffer(l14, l9);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 8u, 498u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a2_arr;
    l6 = vader_chk_mul(i64, l3, INT64_C(2));
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a3_arr;
    vader_struct_vader_vm$FunctionTags_t* _a4_obj = (vader_struct_vader_vm$FunctionTags_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FunctionTags_t));
    vader_obj_header_init(_a4_obj, 1689u);
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
    vader_array_t* _a5_arr = vader_array_new(29u, 1u, 1u, 499u);
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
        t1 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l6, 499u);
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
    vader_array_t* _a10_arr = vader_array_new(29u, 1u, 1u, 499u);
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
    int64_t t0;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$new_tag_context(l0);
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_reserve(363u, (int64_t) t0, 13u, 1689u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l7 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
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
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals;
    vader_struct___lambda_env_vader_vm_1_t* _a0_obj = (vader_struct___lambda_env_vader_vm_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_1_t));
    vader_obj_header_init(_a0_obj, 666u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    t0 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_reserve(414u, (int64_t) t0, 0u, 2456u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l7 = __lambda_vader_vm_0(l2, l6);
        vader_array_push((vader_array_t*) l3, l7);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$inlinable_op(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 1011u || l0.tag == 1082u || l0.tag == 1083u || l0.tag == 1084u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 1004u || l0.tag == 1005u)) {
        l1 = true;
    } else if ((l0.tag == 988u || l0.tag == 1003u || l0.tag == 1016u || l0.tag == 1037u || l0.tag == 1057u || l0.tag == 1088u)) {
        l1 = true;
    } else if ((l0.tag == 1006u || l0.tag == 1092u)) {
        l1 = true;
    } else if ((l0.tag == 1032u || l0.tag == 1033u || l0.tag == 1034u || l0.tag == 1045u || l0.tag == 1047u || l0.tag == 1051u)) {
        l1 = true;
    } else if ((l0.tag == 1035u || l0.tag == 1036u || l0.tag == 1048u || l0.tag == 1049u || l0.tag == 1050u)) {
        l1 = true;
    } else if ((l0.tag == 1039u || l0.tag == 1040u || l0.tag == 1041u || l0.tag == 1042u || l0.tag == 1043u || l0.tag == 1046u)) {
        l1 = true;
    } else if ((l0.tag == 1113u || l0.tag == 1114u || l0.tag == 1115u || l0.tag == 1116u)) {
        l1 = true;
    } else if ((l0.tag == 1052u || l0.tag == 1053u || l0.tag == 1054u || l0.tag == 1065u || l0.tag == 1067u || l0.tag == 1071u)) {
        l1 = true;
    } else if ((l0.tag == 1055u || l0.tag == 1056u || l0.tag == 1068u || l0.tag == 1069u || l0.tag == 1070u)) {
        l1 = true;
    } else if ((l0.tag == 1059u || l0.tag == 1060u || l0.tag == 1061u || l0.tag == 1062u || l0.tag == 1063u || l0.tag == 1066u)) {
        l1 = true;
    } else if ((l0.tag == 1119u || l0.tag == 1120u || l0.tag == 1121u || l0.tag == 1122u)) {
        l1 = true;
    } else if ((l0.tag == 1015u || l0.tag == 1017u || l0.tag == 1023u || l0.tag == 1025u || l0.tag == 1026u)) {
        l1 = true;
    } else if ((l0.tag == 1018u || l0.tag == 1019u || l0.tag == 1020u || l0.tag == 1021u || l0.tag == 1022u || l0.tag == 1024u)) {
        l1 = true;
    } else if ((l0.tag == 987u || l0.tag == 989u || l0.tag == 990u || l0.tag == 991u || l0.tag == 992u)) {
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
    void* l29 = NULL;
    void* l30 = NULL;
    void* l36 = NULL;
    void* l44 = NULL;
    bool l7;
    int64_t l8, l9, l26, l27, l33, l34, l38, l39, l40, l45;
    vader_box_t l10 = vader_box_null(), l19 = vader_box_null(), l25 = vader_box_null(), l32 = vader_box_null(), l41 = vader_box_null(), l42 = vader_box_null(), l46 = vader_box_null(), l47 = vader_box_null();
    int32_t l15, l18, l20, l21, l22, l23, l24, l31, l35, l37, l43, l48, l49;
    uint8_t l28;
    vader_string_t l50 = 0;
    bool t0, t3;
    int64_t t1, t5;
    void* t2 = NULL;
    vader_box_t t4 = vader_box_null();
    int32_t t6;
    vader_box_t* gc_roots[9] = { &l10, &l19, &l25, &l32, &l41, &l42, &l46, &l47, &t4 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l16, &l17, &l29, &l30, &l36, &l44,
        &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l50 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 9u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_body;
    l5 = l4;
    vader_struct___lambda_env_vader_vm_4_t* _a1_obj = (vader_struct___lambda_env_vader_vm_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_4_t));
    vader_obj_header_init(_a1_obj, 670u);
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
    vader_array_t* _a3_arr = vader_array_new(390u, 0u, 13u, 1980u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(394u, 0u, 13u, 2040u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 497u);
    l11 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 497u);
    l12 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(84u, 0u, 13u, 972u);
    l13 = (void*) _a7_arr;
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_locals;
    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l14);
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature)->f_params)->length;
    l15 = ((int32_t) (int64_t) t1);
    vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 497u);
    l14 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(27u, 0u, 7u, 497u);
    l16 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(27u, 0u, 7u, 497u);
    l17 = (void*) _a10_arr;
    vader_struct_std_collections$Map__i32__i32_t* _a11_obj = (vader_struct_std_collections$Map__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__i32_t));
    vader_obj_header_init(_a11_obj, 687u);
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
        if (l10.tag == 1000u) {
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
                t1 = ((vader_array_t*) l13)->length;
                l22 = ((int32_t) (int64_t) t1);
                l23 = vader_chk_add(i32, l15, l22);
                t2 = l10.payload.obj;
                l24 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                l25 = std_collections$put_absent__i32__i32(l14, l24, l23);
                if (l25.tag == 0u) {
                    l17 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params;
                    l26 = ((vader_array_t*) l17)->length;
                    l27 = INT64_C(0);
                    while ((l27 < l26)) {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        t4 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l27, 499u);
                        l28 = ((uint8_t) t4.payload.i);
                        vader_struct_vader_core_bytecode$BcLocal_t* _a17_obj = (vader_struct_vader_core_bytecode$BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcLocal_t));
                        vader_obj_header_init(_a17_obj, 972u);
                        _a17_obj->f_name = 2268u;
                        _a17_obj->f_val = l28;
                        l29 = (void*) _a17_obj;
                        vader_array_push_ref((vader_array_t*) l13, l29);
                        l27 = (l27 + INT64_C(1));
                    }
                    l30 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_locals;
                    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l30);
                }
                l32 = l25;
                if (l32.tag == 0u) {
                    l31 = l23;
                } else {
                    l31 = ((int32_t) l32.payload.i);
                }
                l33 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params)->length;
                l34 = INT64_C(0);
                while ((l34 < l33)) {
                    t1 = vader_chk_sub(i64, l33, INT64_C(1));
                    t5 = vader_chk_sub(i64, t1, l34);
                    l35 = ((int32_t) (int64_t) t5);
                    t6 = vader_chk_add(i32, l31, l35);
                    vader_struct_vader_core_bytecode$LocalSet_t* _a18_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
                    vader_obj_header_init(_a18_obj, 1083u);
                    _a18_obj->f_slot = t6;
                    l36 = (void*) _a18_obj;
                    vader_array_push_ref((vader_array_t*) l5, l36);
                    vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
                    l37 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l37);
                    l34 = (l34 + INT64_C(1));
                }
                l38 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body)->length;
                l39 = INT64_C(0);
                l40 = vader_chk_sub(i64, l38, INT64_C(1));
                while ((l39 < l40)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l39)
                    t4 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l39);
                    l41 = vader_vm$relocated(t4, l31);
                    vader_array_push_ref((vader_array_t*) l5, l41.payload.obj);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l39)
                    l42 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l39);
                    vader_array_push_ref((vader_array_t*) l6, l42.payload.obj);
                    l43 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l43);
                    l39 = (l39 + INT64_C(1));
                }
                l44 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body;
                l45 = vader_chk_sub(i64, l38, INT64_C(1));
                vader_array_t* _a21_slotarr = ((vader_array_t*) l44);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l45)
                l46 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l45);
                if (l46.tag == 1094u) {
                    t2 = l46.payload.obj;
                    l47 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t2)->f_value;
                    vader_array_push_ref((vader_array_t*) l5, l47.payload.obj);
                    vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
                    l48 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l48);
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        vader_array_push_ref((vader_array_t*) l5, l10.payload.obj);
        vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
        l49 = ((int32_t) (int64_t) l8);
        vader_array_push_i32((vader_array_t*) l11, l49);
        l8 = (l8 + INT64_C(1));
    }
    l4 = l3;
    l50 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_jump_table;
    l8 = ((vader_array_t*) l5)->length;
    l3 = vader_core_bytecode$remap_jump_table(l3, l12, l8);
    vader_struct_vader_core_bytecode$BcFunction_t* _a22_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a22_obj, 969u);
    _a22_obj->f_name = l50;
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
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l3, l4;
    bool l5;
    vader_string_t l7 = 0;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l8, &l9, &l10, &l11, &l12, &l13, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_reserve(24u, (int64_t) t0, 12u, 492u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l5 = vader_vm$is_inline_leaf(t1);
        vader_array_push_bool((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    t2 = std_core$$array$Contains$contains__bool(l1, true);
    if (!(t2)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a2_arr = vader_array_reserve(81u, (int64_t) t0, 13u, 969u);
    l2 = (void*) _a2_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l3 < l4)) {
        l6 = vader_vm$inline_into(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions, l1, l3);
        vader_array_push_ref((vader_array_t*) l2, l6);
        l3 = (l3 + INT64_C(1));
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
    vader_struct_vader_core_bytecode$BytecodeModule_t* _a3_obj = (vader_struct_vader_core_bytecode$BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BytecodeModule_t));
    vader_obj_header_init(_a3_obj, 998u);
    _a3_obj->f_name = l7;
    _a3_obj->f_types = l6;
    _a3_obj->f_strings = l8;
    _a3_obj->f_data_pool = l9;
    _a3_obj->f_functions = l2;
    _a3_obj->f_imports = l10;
    _a3_obj->f_exports = l11;
    _a3_obj->f_impl_table = l12;
    _a3_obj->f_vtables = l13;
    _a3_obj->f_globals = l1;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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

static bool vader_vm$is_boxed(vader_box_t l0) {
    return (l0.tag == 952u || l0.tag == 953u || l0.tag == 956u || l0.tag == 958u || l0.tag == 959u || l0.tag == 960u || l0.tag == 961u || l0.tag == 963u || l0.tag == 984u || l0.tag == 985u || l0.tag == 987u || l0.tag == 989u || l0.tag == 990u || l0.tag == 991u || l0.tag == 992u || l0.tag == 995u || l0.tag == 996u || l0.tag == 997u || l0.tag == 1006u || l0.tag == 1007u || l0.tag == 1014u || l0.tag == 1027u || l0.tag == 1029u || l0.tag == 1030u || l0.tag == 1031u || l0.tag == 1039u || l0.tag == 1046u || l0.tag == 1074u || l0.tag == 1075u || l0.tag == 1076u || l0.tag == 1080u || l0.tag == 1086u || l0.tag == 1087u || l0.tag == 1090u || l0.tag == 1091u || l0.tag == 1095u || l0.tag == 1096u || l0.tag == 1097u || l0.tag == 1098u || l0.tag == 1102u || l0.tag == 1103u || l0.tag == 1105u || l0.tag == 1106u || l0.tag == 1108u || l0.tag == 1110u || l0.tag == 1111u);
}

bool vader_vm$is_comptime_refusal_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$string$std_core$Contains$contains(l0, 2312u);
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
    if (!((t2.tag == 1093u || t2.tag == 1094u))) {
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
            if (l6.tag == 1082u) {
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

static bool vader_vm$is_leaving(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    vader_box_t l4;
    bool t0;
    t0 = ((vader_struct_vader_vm$GuestThread_t*) l1)->f_cancelled;
    if (t0) {
        return true;
    }
    l2 = ((vader_struct_vader_vm$GuestThreads_t*) l0)->f_live;
    l3 = ((vader_struct_vader_vm$GuestThread_t*) l1)->f_launcher;
    l4 = std_collections$Map$std_core$Index$at__i64__Any(l2, l3);
    if (l4.tag == 0u) {
        return false;
    }
    l2 = l4.payload.obj;
    t0 = vader_vm$is_leaving(l0, l2);
    return t0;
}

static bool vader_vm$is_overflow_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$starts_with(l0, 1793u);
    return t0;
}

bool vader_vm$is_singleton_comptime_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$string$std_core$Contains$contains(l0, 1699u);
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
    if (!(l0 == 2235u)) {
        return true;
    }
    return false;
}

static bool vader_vm$is_std_handle_symbol(vader_string_t l0) {
    return l0 == 694u;
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
    if (l0 == 3226u) {
        l1 = true;
    } else {
        l1 = l0 == 1085u;
    }
    if (l1) {
        return true;
    }
    return l0 == 1017u;
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
    if (!(l4.tag == 965u)) {
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
    if (!(l4.tag == 975u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
    if (!(t2)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_box_i32(499u, (int32_t)(uint32_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
}

static bool vader_vm$line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_vm$DebugController_t*) l0)->f_breakpoints, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections$Set$std_core$Contains$contains__i32(t0, l2);
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
    l4 = vader_vm$stack_i32(l0, l3, l2, 2539u);
    if (l4.tag == 1716u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm$stack_obj(l0, l3, l2);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int32_t) l4.payload.i);
    t1 = l5.payload.obj;
    l3 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    l7 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$check_byte_range(l6, l1, l3, l2, l7);
    if (!(l4.tag == 1716u)) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes;
        l3 = ((int64_t) l4.payload.i);
        t2 = vader_core_bytecode$read_le(l8, l3, l1);
        { vader_box_t __vret = vader_box_i64(502u, (int64_t)(uint64_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
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

static void* vader_vm$main_thread(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_vm$PauseThread_t* _a0_obj = (vader_struct_vader_vm$PauseThread_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseThread_t));
    vader_obj_header_init(_a0_obj, 1701u);
    _a0_obj->f_id = INT32_C(1);
    _a0_obj->f_name = 2416u;
    _a0_obj->f_stack = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a1_obj, 1703u);
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
    l7 = std_core$write_string_at(l6, l7, 2618u);
    l7 = std_core$write_int(l6, l7, l3);
    l7 = std_core$write_string_at(l6, l7, 250u);
    l7 = std_core$write_int(l6, l7, l4);
    l7 = std_core$write_string_at(l6, l7, 243u);
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
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 499u);
        l10 = ((uint8_t) t1.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 499u);
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
        l2 = vader_box_bool(492u, l1 != INT64_C(0));
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
        l2 = vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l3));
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
            l2 = vader_box_i32(497u, ((int32_t) (int64_t) l1));
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
                l2 = vader_box_i64(498u, l1);
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
                l2 = vader_box_i64(498u, l1);
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
    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 499u);
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
    if (l0.tag == 497u) {
        t1 = ((int32_t) l0.payload.i);
        l4 = ((int64_t) (int32_t) t1);
    } else {
        if (!(l0.tag == 498u)) {
            return l0;
        }
        l4 = ((int64_t) l0.payload.i);
    }
    if (l1 == INT32_C(0)) {
        l3 = true;
        t1 = vader_vm$truncate_to_width(l4, l2, l3);
        return vader_box_i32(497u, t1);
    }
    l3 = l1 == INT32_C(1);
    t1 = vader_vm$truncate_to_width(l4, l2, l3);
    return vader_box_i32(497u, t1);
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    if (((int32_t) t0.payload.i) != INT32_C(0)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
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
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 12u, 492u);
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
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 8u, 498u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(28u, 1u, 8u, 498u);
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
    vader_array_t* _a12_arr = vader_array_new(28u, 1u, 8u, 498u);
    ((int64_t*) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = (int64_t) INT64_C(-1);
    l4 = (void*) _a12_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l3);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l13 = (void*) _a14_arr;
    t2 = ((vader_array_t*) l6)->length;
    l3 = vader_chk_mul(i64, t2, l2);
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l3);
    l13 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(28u, 0u, 8u, 498u);
    l14 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(24u, 1u, 12u, 492u);
    ((uint8_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (uint8_t) false;
    l15 = (void*) _a17_arr;
    l3 = ((vader_array_t*) l6)->length;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l3);
    l15 = (void*) _a18_arr;
    vader_struct_vader_vm$Blocks_t* _a19_obj = (vader_struct_vader_vm$Blocks_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Blocks_t));
    vader_obj_header_init(_a19_obj, 1682u);
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
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 8u, 498u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 1u, 7u, 497u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a1_arr;
    vader_struct_vader_vm$RunHost_t* _a2_obj = (vader_struct_vader_vm$RunHost_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RunHost_t));
    vader_obj_header_init(_a2_obj, 1708u);
    _a2_obj->f_gc_state = l0;
    _a2_obj->f_obj_handles = l1;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$new_tag_context(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    int32_t l5;
    uint8_t l6;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    vader_array_t* _a0_arr = vader_array_reserve(29u, (int64_t) t0, 1u, 499u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        l5 = ((int32_t) (int64_t) l2);
        l6 = vader_vm$type_tags(l4, l5, INT32_C(0));
        vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l6);
        l2 = (l2 + INT64_C(1));
    }
    vader_struct_vader_vm$TagContext_t* _a1_obj = (vader_struct_vader_vm$TagContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$TagContext_t));
    vader_obj_header_init(_a1_obj, 1714u);
    _a1_obj->f_module = l0;
    _a1_obj->f_type_tags = l1;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$note(void* l0, vader_box_t l1, int32_t l2, vader_box_t l3) {
    int32_t l4;
    int64_t t0;
    int32_t t1, t2;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies)->length;
    l4 = ((int32_t) (int64_t) t0);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_sources, l1.payload.obj);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_kept_ids, l2);
    vader_array_push((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies, l3);
    t1 = vader_chk_neg(i32, l4);
    t2 = vader_chk_sub(i32, t1, INT32_C(1));
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$note_checked_kind(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3;
    uint8_t l4;
    int64_t t0;
    if ((l1.tag == 1004u || l1.tag == 1005u)) {
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

static void vader_vm$note_entry_thread(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_vm$guest_threads();
    l2 = vader_host_std_runtime_scheduler$current_thread();
    ((vader_struct_vader_vm$GuestThreads_t*) l1)->f_entry_thread = l2;
    ((vader_struct_vader_vm$GuestThreads_t*) l1)->f_entry_machine = vader_ref_box(l0);
    VADER_WRITE_BARRIER((vader_struct_vader_vm$GuestThreads_t*) l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_vm$note_host_call(void* l0, int64_t l1, int64_t l2) {
    void* l3;
    vader_box_t l4;
    l4 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_debug;
    if (l4.tag == 0u) {
        return;
    }
    l3 = l4.payload.obj;
    ((vader_struct_vader_vm$DebugSession_t*) l3)->f_host_pc = l1;
    ((vader_struct_vader_vm$DebugSession_t*) l3)->f_host_depth = l2;
    return;
}

int64_t vader_vm$number_of(void* l0, int64_t l1) {
    void* l2;
    vader_box_t l3;
    int64_t t0;
    l3 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l0)->f_live, l1);
    if (l3.tag == 0u) {
        return INT64_C(0);
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_vm$GuestThread_t*) l2)->f_number;
    return t0;
}

static vader_box_t vader_vm$on_i64(vader_box_t l0, int32_t l1, vader_string_t l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[2] = { &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_vm$read_i64(l0, l1, l2);
    if (!(l4.tag == 1716u)) {
        t0 = ((int64_t) l4.payload.i);
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(498u, t0));
        t1 = vader_vm$void_result();
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l4.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 494u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 857u);
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
    l1 = 1793u;
    l2 = l0;
    l3 = vader_host_std_core$byte_len(l1);
    l4 = vader_host_std_core$byte_len(l2);
    l3 = (l3 + l4);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l5, l3, l1);
    l3 = std_core$write_string_at(l5, l3, 52u);
    l3 = std_core$write_int(l5, l3, INT64_C(1024));
    l3 = std_core$write_string_at(l5, l3, 349u);
    l3 = std_core$write_string_at(l5, l3, l2);
    l3 = std_core$write_string_at(l5, l3, 307u);
    t0 = std_core$finish_buffer(l5, l3);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 1716u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$own_bytes(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    int64_t l4, l5;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_vm$StringWindow_t*) l1)->f_length;
    vader_array_t* _a0_arr = vader_array_reserve(414u, (int64_t) t0, 0u, 2456u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = ((vader_struct_vader_vm$StringWindow_t*) l1)->f_length;
    while ((l4 < l5)) {
        l2 = vader_vm$element_at(l0, l4);
        vader_array_push((vader_array_t*) l3, l2);
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) l0);
    ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) l0);
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
    return vader_box_i64(498u, (l4 | l5));
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
    l2 = std_core$write_string_at(l3, l2, 1639u);
    l2 = std_core$write_int(l3, l2, l1);
    t1 = std_core$finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$parked(void) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_std_runtime_scheduler$park();
    t0 = vader_vm$void_result();
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_vm$parked_stack(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(368u, 0u, 13u, 1700u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) t0)->f_debug;
    if (l3.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(368u, 0u, 13u, 1700u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l4 = l1.payload.obj;
    l5 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_host_pc;
    l6 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_host_depth;
    t0 = vader_vm$call_stack(l0, l4, l5, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a1_obj, 1700u);
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l4.tag == 1681u) {
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
    l7 = std_core$write_string_at(l9, l7, 99u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 514u);
    l7 = std_core$write_string_at(l9, l7, l6);
    t2 = std_core$finish_buffer(l9, l7);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 1716u);
    _a2_obj->f_message = t2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$peek_owned(void* l0, int64_t l1) {
    uint8_t l2;
    vader_box_t l3;
    uint32_t l4;
    bool l5;
    vader_box_t t0;
    int64_t t1;
    int32_t t2;
    void* t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        return l3;
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1];
        l3 = vader_box_i32(497u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(498u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(504u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(492u, t1 != INT64_C(0));
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
        l3 = vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l4));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t3 = (void*) &vader_data_169;
        vader_array_t* _a7_slotarr = ((vader_array_t*) t3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
        l3 = vader_ref_box(t3);
    }
    return l3;
}

static vader_box_t vader_vm$peek_val(void* l0, int64_t l1) {
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    if (((int32_t) t0.payload.i) == INT32_C(5)) {
        t1 = (void*) &vader_data_57;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_vm$peek_owned(l0, l1);
    return t0;
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
    if (l2.tag == 1720u) {
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
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int64_t l6, l7;
    uint8_t l9;
    vader_string_t l10 = 0;
    int32_t l11, l13, l14;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[9] = { &l0, &l3, &l4, &l5, &l8, &l12, &l15, &l16, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$verify_module(l0);
    if (l2.tag == 1719u) {
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
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports)->length;
    vader_array_t* _a0_arr = vader_array_reserve(29u, (int64_t) t1, 1u, 499u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_is_extern;
        if (t2) {
            vader_array_push_u8((vader_array_t*) l4, INT32_C(0));
        } else {
            t3 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_mangled_name;
            l9 = vader_core_bytecode$intrinsic_id_for(t3);
            vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l9);
        }
        l7 = (l7 + INT64_C(1));
    }
    l2 = vader_vm$translate_module(l0, l4, l3, l1);
    if (l2.tag == 1719u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 494u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 497u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 497u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__i32_t* _a5_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a5_obj, 767u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l5;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a5_obj;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l6 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l11 = ((int32_t) (int64_t) l6);
        std_collections$Map$std_core$IndexSet$set_at__string__i32(l3, l10, l11);
        l6 = (l6 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool;
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
    l12 = vader_core_bytecode$data_pool_type_ids(l0);
    l5 = vader_vm$reduce_data_pool(l5, l8, l12);
    l8 = vader_vm$initial_globals(l0);
    l11 = vader_core_bytecode$main_function_index(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    l13 = vader_vm$find_string_array_type_id(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l14 = vader_vm$find_u8_array_type_id(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 8u, 498u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(416u, 1u, 13u, 2477u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    l15 = (void*) _a8_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports)->length;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l6);
    l15 = (void*) _a9_arr;
    l16 = l2.payload.obj;
    vader_struct_vader_vm$VmState_t* _a10_obj = (vader_struct_vader_vm$VmState_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VmState_t));
    vader_obj_header_init(_a10_obj, 1720u);
    _a10_obj->f_bc = l0;
    _a10_obj->f_data_pool = l5;
    _a10_obj->f_globals = l8;
    _a10_obj->f_main_index = l11;
    _a10_obj->f_string_array_type_id = l13;
    _a10_obj->f_u8_array_type_id = l14;
    _a10_obj->f_fn_index_by_name = l3;
    _a10_obj->f_import_ids = l4;
    _a10_obj->f_adapters = l12;
    _a10_obj->f_foreign_calls = l15;
    _a10_obj->f_reg = l16;
    _a10_obj->f_debuggable = l1;
    t0 = (void*) _a10_obj;
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
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(17);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(17);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 497u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 1u, 7u, 497u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 494u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 12u, 492u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 12u, 492u);
    l8 = (void*) _a7_arr;
    vader_struct_vader_core_bytecode$BcSignature_t* _a8_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a8_obj, 976u);
    _a8_obj->f_params = l2;
    _a8_obj->f_results = l3;
    _a8_obj->f_param_types = l4;
    _a8_obj->f_result_types = l5;
    _a8_obj->f_param_names = l6;
    _a8_obj->f_param_c_out = l7;
    _a8_obj->f_param_by_address = l8;
    l2 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(26u, 0u, 0u, 494u);
    l3 = (void*) _a9_arr;
    vader_struct_vader_core_bytecode$BcImport_t* _a10_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
    vader_obj_header_init(_a10_obj, 971u);
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
    if (!(l5.tag == 975u)) {
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
        if (l5.tag == 975u) {
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
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 497u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 1u, 7u, 497u);
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
    vader_array_t* _a8_arr = vader_array_new(370u, 0u, 13u, 1702u);
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
    vader_array_t* _a0_arr = vader_array_new(370u, 0u, 13u, 1702u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 494u);
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
        if (l8.tag == 978u) {
            t1 = l8.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
            l6 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l6)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                l10 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(494u, l10));
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
            l12 = std_core$write_string_at(l7, l12, 2079u);
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
    void* l12 = NULL;
    int64_t l5, l6, l8;
    vader_string_t l9 = 0;
    vader_box_t l10 = vader_box_null();
    int32_t l11;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l10 };
    void** gc_raw_roots[5] = { &l2, &l4, &l7, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(370u, 0u, 13u, 1702u);
    l4 = (void*) _a0_arr;
    if ((l3 < INT32_C(5))) {
        if (l1.tag == 1681u) {
            t0 = l1.payload.obj;
            t1 = vader_vm$element_count(t0);
            l5 = std_math$min_3(t1, INT64_C(64));
            l6 = INT64_C(0);
            while ((l6 < l5)) {
                l7 = (void*) vader_buffer_new((size_t) INT64_C(22));
                l8 = INT64_C(0);
                l8 = std_core$write_string_at(l7, l8, 1019u);
                l8 = std_core$write_int(l7, l8, l6);
                l8 = std_core$write_string_at(l7, l8, 1024u);
                l9 = std_core$finish_buffer(l7, l8);
                t0 = l1.payload.obj;
                l10 = vader_vm$element_at(t0, l6);
                l11 = vader_chk_add(i32, l3, INT32_C(1));
                l12 = vader_vm$project_var(l9, l10, l2, l11);
                vader_array_push_ref((vader_array_t*) l4, l12);
                l6 = (l6 + INT64_C(1));
            }
        } else if (l1.tag == 1713u) {
            t0 = l1.payload.obj;
            l4 = vader_vm$project_struct_fields(t0, l2, l3);
        }
        l9 = vader_vm$display_value(l1);
        vader_struct_vader_vm$PauseVar_t* _a1_obj = (vader_struct_vader_vm$PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseVar_t));
        vader_obj_header_init(_a1_obj, 1702u);
        _a1_obj->f_name = l0;
        _a1_obj->f_value = l9;
        _a1_obj->f_children = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm$display_value(l1);
    vader_struct_vader_vm$PauseVar_t* _a2_obj = (vader_struct_vader_vm$PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseVar_t));
    vader_obj_header_init(_a2_obj, 1702u);
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
        vader_host_std_abort$panic(2632u);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        l3 = std_collections$Map$std_core$Index$at__Any__i64(((vader_struct_vader_vm$Translation_t*) l0)->f_constants, vader_ref_box(l2));
        if (l3.tag == 0u) {
            vader_host_std_abort$panic(2633u);
            vader_unreachable("a no-return call returned");
        } else {
            l4 = ((int64_t) l3.payload.i);
            l2 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
            t0 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_slots;
            t1 = vader_chk_add(i64, t0, l4);
            l5 = ((int32_t) (int64_t) t1);
            vader_struct_vader_vm$Pending_t* _a0_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
            vader_obj_header_init(_a0_obj, 1703u);
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
    vader_obj_header_init(_a0_obj, 1703u);
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
    if (l2.tag == 497u) {
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
    if (l2.tag == 498u) {
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
    } else if ((l2.tag == 503u || l2.tag == 504u)) {
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
    } else if (l2.tag == 492u) {
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
    } else if (l2.tag == 493u) {
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
    } else if (l2.tag == 1696u) {
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
    if ((l1.tag == 955u || l1.tag == 1014u || l1.tag == 1032u || l1.tag == 1033u || l1.tag == 1034u || l1.tag == 1035u || l1.tag == 1036u || l1.tag == 1037u || l1.tag == 1038u || l1.tag == 1044u || l1.tag == 1045u || l1.tag == 1047u || l1.tag == 1048u || l1.tag == 1049u || l1.tag == 1050u || l1.tag == 1051u || l1.tag == 1075u || l1.tag == 1080u || l1.tag == 1103u || l1.tag == 1112u || l1.tag == 1117u)) {
        l4 = (uint8_t) 1;
        return l4;
    }
    if ((l1.tag == 1027u || l1.tag == 1052u || l1.tag == 1053u || l1.tag == 1054u || l1.tag == 1055u || l1.tag == 1056u || l1.tag == 1057u || l1.tag == 1058u || l1.tag == 1064u || l1.tag == 1065u || l1.tag == 1067u || l1.tag == 1068u || l1.tag == 1069u || l1.tag == 1070u || l1.tag == 1071u || l1.tag == 1076u || l1.tag == 1095u || l1.tag == 1118u || l1.tag == 1123u)) {
        l4 = (uint8_t) 2;
    } else if ((l1.tag == 984u || l1.tag == 985u || l1.tag == 1015u || l1.tag == 1016u || l1.tag == 1017u || l1.tag == 1023u || l1.tag == 1025u || l1.tag == 1026u || l1.tag == 1074u || l1.tag == 1077u)) {
        l4 = (uint8_t) 4;
    } else if ((l1.tag == 987u || l1.tag == 988u || l1.tag == 989u || l1.tag == 990u || l1.tag == 991u || l1.tag == 992u || l1.tag == 1018u || l1.tag == 1019u || l1.tag == 1020u || l1.tag == 1021u || l1.tag == 1022u || l1.tag == 1024u || l1.tag == 1039u || l1.tag == 1040u || l1.tag == 1041u || l1.tag == 1042u || l1.tag == 1043u || l1.tag == 1046u || l1.tag == 1059u || l1.tag == 1060u || l1.tag == 1061u || l1.tag == 1062u || l1.tag == 1063u || l1.tag == 1066u || l1.tag == 1090u || l1.tag == 1091u || l1.tag == 1105u || l1.tag == 1106u || l1.tag == 1110u || l1.tag == 1113u || l1.tag == 1114u || l1.tag == 1115u || l1.tag == 1116u || l1.tag == 1119u || l1.tag == 1120u || l1.tag == 1121u || l1.tag == 1122u)) {
        l4 = (uint8_t) 8;
    } else if (l1.tag == 1003u) {
        l4 = (uint8_t) 16;
    } else if (l1.tag == 1088u) {
        l4 = (uint8_t) 32;
    } else if ((l1.tag == 1004u || l1.tag == 1005u)) {
        l4 = vader_vm$integer_tags(VADER_UNION_FIELD(uint8_t, vader_struct_vader_core_bytecode$CheckedArith_t, f_kind, l1.payload.obj));
    } else if ((l1.tag == 956u || l1.tag == 960u || l1.tag == 961u || l1.tag == 963u || l1.tag == 995u || l1.tag == 996u || l1.tag == 1007u || l1.tag == 1028u || l1.tag == 1029u || l1.tag == 1086u || l1.tag == 1104u || l1.tag == 1108u || l1.tag == 1111u)) {
        l4 = (uint8_t) 64;
    } else if (l1.tag == 1082u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 499u);
        l4 = ((uint8_t) t1.payload.i);
    } else if ((l1.tag == 1084u || l1.tag == 1092u)) {
        l4 = l3;
    } else if (l1.tag == 1089u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        l6 = vader_vm$tags_of_type(l0, l5);
        t2 = (l3 & l6);
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 1006u) {
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
    } else if ((l1.tag == 1107u || l1.tag == 1124u)) {
        l5 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_type_id, l1.payload.obj);
        l7 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_field_index, l1.payload.obj);
        l4 = vader_vm$field_tags(l0, l5, l7);
    } else if (l1.tag == 1081u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
        l4 = vader_vm$field_tags(l0, l5, l7);
    } else if (l1.tag == 954u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        l4 = vader_vm$element_tags(l0, l5);
    } else if (l1.tag == 1030u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        l4 = vader_vm$global_tags(l0, l5);
    } else if (l1.tag == 959u) {
        l4 = (uint8_t) 127;
    } else if (l1.tag == 1078u) {
        t2 = (INT32_C(1) | INT32_C(16));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 1079u) {
        t2 = (INT32_C(2) | INT32_C(1));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 1002u) {
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
        if (!((l1.tag == 952u || l1.tag == 953u || l1.tag == 957u || l1.tag == 958u || l1.tag == 962u || l1.tag == 986u || l1.tag == 993u || l1.tag == 994u || l1.tag == 997u || l1.tag == 1000u || l1.tag == 1001u || l1.tag == 1009u || l1.tag == 1010u || l1.tag == 1011u || l1.tag == 1012u || l1.tag == 1013u || l1.tag == 1031u || l1.tag == 1072u || l1.tag == 1083u || l1.tag == 1085u || l1.tag == 1087u || l1.tag == 1093u || l1.tag == 1094u || l1.tag == 1096u || l1.tag == 1097u || l1.tag == 1098u || l1.tag == 1099u || l1.tag == 1100u || l1.tag == 1101u || l1.tag == 1102u || l1.tag == 1109u || l1.tag == 1125u || l1.tag == 1126u || l1.tag == 1127u))) {
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
    if (!(l0.tag == 1681u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 514u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
            if ((t1.tag == 503u || t1.tag == 504u)) {
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
                vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7] = vader_box_f64(504u, l21);
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
        if (l10.tag == 1713u) {
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
    if (!(l0.tag == 492u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 515u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.b;
    { vader_box_t __vret = vader_box_bool(492u, t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!((l0.tag == 503u || l0.tag == 504u))) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 516u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l0.payload.f);
    { vader_box_t __vret = vader_box_f64(504u, t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l0.tag == 1686u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 517u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
    if (l0.tag == 497u) {
        t0 = ((int32_t) l0.payload.i);
        l3 = vader_box_i32(497u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 493u) {
        t1 = ((uint32_t) l0.payload.i);
        l3 = vader_box_i32(497u, ((int32_t) (uint32_t) t1));
    } else if (l0.tag == 498u) {
        t2 = ((int64_t) l0.payload.i);
        l3 = vader_box_i32(497u, ((int32_t) (int64_t) t2));
    } else {
        l4 = l2;
        l5 = vader_vm$describe_value_tag(l0);
        l6 = vader_host_std_core$byte_len(l4);
        l7 = vader_host_std_core$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 99u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 518u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t3 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
    if (l0.tag == 498u) {
        t0 = ((int64_t) l0.payload.i);
        l3 = vader_box_i64(498u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 497u) {
        t1 = ((int32_t) l0.payload.i);
        l3 = vader_box_i64(498u, ((int64_t) (int32_t) t1));
    } else {
        l4 = l2;
        l5 = vader_vm$describe_value_tag(l0);
        l6 = vader_host_std_core$byte_len(l4);
        l7 = vader_host_std_core$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 99u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 519u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t2 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 499u);
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
    if (l0.tag == 497u) {
        t0 = ((int32_t) l0.payload.i);
        l2 = vader_box_f64(504u, ((double) (int32_t) t0));
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 498u) {
        t1 = ((int64_t) l0.payload.i);
        l2 = vader_box_f64(504u, ((double) (int64_t) t1));
    } else if ((l0.tag == 503u || l0.tag == 504u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_f64(504u, t2);
    } else if (l0.tag == 493u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_f64(504u, ((double) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else {
        l3 = vader_vm$describe_value_tag(l0);
        l4 = vader_host_std_core$byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(55) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l5, l4, 1895u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l5, l4, l6);
        l4 = std_core$write_string_at(l5, l4, 510u);
        l4 = std_core$write_string_at(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 95u);
        t4 = std_core$finish_buffer(l5, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
    if (l0.tag == 498u) {
        t0 = ((int64_t) l0.payload.i);
        l2 = vader_box_i64(498u, t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 497u) {
        t1 = ((int32_t) l0.payload.i);
        l2 = vader_box_i64(498u, ((int64_t) (int32_t) t1));
    } else if ((l0.tag == 503u || l0.tag == 504u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_i64(498u, ((int64_t) (double) t2));
    } else if (l0.tag == 493u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_i64(498u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else if (l0.tag == 492u) {
        t4 = l0.payload.b;
        if (t4) {
            l2 = vader_box_i64(498u, INT64_C(1));
        } else {
            l2 = vader_box_i64(498u, INT64_C(0));
        }
    } else {
        l3 = vader_vm$describe_value_tag(l0);
        l4 = vader_host_std_core$byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(59) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l5, l4, 1895u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l5, l4, l6);
        l4 = std_core$write_string_at(l5, l4, 510u);
        l4 = std_core$write_string_at(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 96u);
        t5 = std_core$finish_buffer(l5, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
    if (!(l0.tag == 1697u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 521u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
    if (l0.tag == 492u) {
        t0 = l0.payload.b;
        if (t0) {
            { vader_box_t __vret = vader_box_i64(498u, INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i64(498u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 493u)) {
        t1 = vader_vm$read_i64(l0, l1, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((uint32_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(498u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t2))); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l0.tag == 494u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 522u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.s;
    { vader_box_t __vret = vader_box_string(494u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l0.tag == 1713u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$byte_len(l3);
        l6 = vader_host_std_core$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 99u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 523u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
    if (!(l0.tag == 1713u)) {
        l4 = l0;
        l5 = concat_2(l3, 216u);
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
    l7 = std_core$write_string_at(l9, l7, 126u);
    l8 = ((int64_t) (int32_t) l1);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 203u);
    t1 = l0.payload.obj;
    l8 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields)->length;
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 127u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core$write_int(l9, l7, l8);
    t2 = std_core$finish_buffer(l9, l7);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
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
    l8 = std_core$write_string_at(l9, l8, 217u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l10 = ((int64_t) (int32_t) t1);
    l8 = std_core$write_int(l9, l8, l10);
    t2 = std_core$finish_buffer(l9, l8);
    t3 = concat_5(t2, 513u, l5, 398u, l6);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 1716u);
    _a1_obj->f_message = t3;
    t4 = (void*) _a1_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$receiver_type_id_of(void* l0, vader_box_t l1) {
    int32_t l2;
    vader_box_t l3;
    void* t0;
    if (l1.tag == 1713u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id;
        return l2;
    }
    if (l1.tag == 1681u) {
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
    void* l21 = NULL;
    int64_t l4, l5, l9, l10, l13, l14, l18, l19;
    vader_box_t l6 = vader_box_null(), l16 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l11 = 0;
    uint64_t l15;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    vader_box_t* gc_roots[4] = { &l6, &l16, &l20, &t2 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l7, &l8, &l12, &l17, &l21, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_arr = vader_array_reserve(361u, (int64_t) t0, 13u, 1681u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_array_t* _a2_arr = vader_array_new(414u, 0u, 0u, 2456u);
        l7 = (void*) _a2_arr;
        if (l6.tag == 977u) {
            t1 = l6.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$BcStrData_t*) t1)->f_values;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l10];
                l11 = t2.payload.s;
                vader_array_push((vader_array_t*) l7, vader_box_string(494u, l11));
                l10 = (l10 + INT64_C(1));
            }
        } else if (l6.tag == 973u) {
            t1 = l6.payload.obj;
            l12 = ((vader_struct_vader_core_bytecode$BcPrimData_t*) t1)->f_items;
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l14];
                l15 = (uint64_t) (int64_t) t0;
                t1 = l6.payload.obj;
                l16 = vader_vm$value_from_bits(((vader_struct_vader_core_bytecode$BcPrimData_t*) t1)->f_kind, l15);
                vader_array_push((vader_array_t*) l7, l16);
                l14 = (l14 + INT64_C(1));
            }
        } else if (l6.tag == 964u) {
            t1 = l6.payload.obj;
            l17 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t1)->f_elements;
            l18 = ((vader_array_t*) l17)->length;
            l19 = INT64_C(0);
            while ((l19 < l18)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l19);
                l20 = vader_vm$bc_value_to_vm(t2, l1);
                vader_array_push((vader_array_t*) l7, l20);
                l19 = (l19 + INT64_C(1));
            }
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
        t3 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l4];
        vader_struct_vader_vm$ArrayVal_t* _a7_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
        vader_obj_header_init(_a7_obj, 1681u);
        _a7_obj->f_type_id = t3;
        _a7_obj->f_elements = l7;
        _a7_obj->f_raw = vader_box_obj(0u, NULL);
        l21 = (void*) _a7_obj;
        vader_array_push_ref((vader_array_t*) l3, l21);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$ref_type_matches(void* l0, vader_box_t l1, vader_string_t l2) {
    bool l3;
    int32_t l4;
    bool t0;
    if (l2 == 0u) {
        if (l1.tag == 1713u) {
            l3 = true;
            return l3;
        }
        if (l1.tag == 1681u) {
            l3 = true;
        } else if (l1.tag == 1686u) {
            l3 = true;
        } else {
            l3 = false;
        }
        return l3;
    }
    if ((l1.tag == 1681u || l1.tag == 1713u)) {
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
    void* l657 = NULL;
    void* l663 = NULL;
    void* l665 = NULL;
    void* l719 = NULL;
    void* l739 = NULL;
    void* l752 = NULL;
    void* l754 = NULL;
    int64_t l9, l10, l11, l12, l13, l20, l21, l22, l23, l24, l25, l28, l29, l30, l31, l32, l55, l56, l63, l64, l114, l115, l124, l125, l193, l195, l196, l199, l201, l202, l205, l207, l208, l210, l212, l213, l216, l218, l220, l221, l224, l227, l229, l230, l233, l235, l236, l239, l241, l242, l245, l247, l248, l251, l253, l254, l260, l263, l264, l267, l269, l271, l272, l277, l279, l281, l282, l287, l290, l292, l296, l298, l302, l304, l308, l310, l314, l316, l320, l322, l434, l438, l442, l446, l448, l452, l455, l458, l461, l463, l466, l469, l472, l476, l480, l484, l488, l490, l498, l500, l505, l525, l527, l529, l531, l533, l535, l537, l539, l556, l559, l560, l563, l564, l569, l570, l576, l577, l579, l581, l582, l587, l588, l592, l594, l599, l600, l602, l603, l605, l606, l607, l608, l612, l613, l617, l618, l623, l624, l625, l626, l634, l635, l655, l656, l661, l662, l666, l667, l669, l670, l674, l675, l677, l678, l680, l684, l686, l687, l689, l690, l691, l692, l693, l695, l700, l701, l702, l708, l709, l711, l712, l713, l714, l716, l720, l721, l722, l723, l724, l725, l726, l727, l728, l729, l730, l731, l732, l733, l734, l735, l736, l738, l740, l741, l745, l746, l747, l748, l749, l750, l751, l753, l755;
    int32_t l19, l34, l35, l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l57, l58, l59, l60, l61, l65, l66, l67, l68, l69, l70, l71, l72, l73, l74, l75, l76, l77, l78, l79, l80, l81, l82, l83, l84, l85, l86, l87, l88, l89, l90, l91, l92, l93, l94, l95, l96, l97, l98, l100, l101, l103, l104, l105, l106, l107, l108, l109, l110, l111, l112, l116, l117, l120, l121, l122, l126, l127, l130, l131, l132, l133, l134, l135, l137, l138, l139, l140, l141, l143, l144, l145, l146, l147, l149, l150, l151, l152, l153, l155, l156, l157, l158, l159, l161, l162, l163, l164, l165, l167, l168, l170, l173, l174, l176, l179, l180, l182, l185, l186, l188, l191, l192, l194, l197, l198, l200, l203, l204, l206, l209, l214, l215, l217, l222, l223, l225, l226, l228, l231, l232, l234, l237, l238, l240, l243, l244, l246, l249, l250, l252, l255, l256, l258, l261, l262, l265, l266, l268, l273, l274, l278, l283, l284, l288, l289, l291, l294, l295, l297, l300, l301, l303, l306, l307, l309, l312, l313, l315, l318, l319, l321, l324, l325, l327, l330, l331, l333, l336, l337, l339, l342, l343, l345, l348, l349, l351, l354, l355, l357, l360, l361, l363, l366, l367, l369, l372, l373, l375, l376, l378, l381, l382, l384, l387, l388, l390, l393, l394, l396, l399, l400, l402, l405, l406, l408, l411, l412, l414, l417, l418, l420, l423, l424, l426, l427, l428, l430, l431, l432, l436, l437, l440, l441, l444, l445, l447, l450, l451, l454, l457, l460, l462, l465, l468, l471, l474, l478, l482, l486, l489, l492, l493, l494, l495, l496, l497, l499, l501, l502, l503, l506, l507, l508, l509, l510, l511, l512, l513, l514, l515, l516, l517, l518, l519, l520, l521, l522, l523, l524, l526, l528, l530, l532, l534, l536, l538, l540, l542, l544, l546, l548, l550, l552, l554, l558, l561, l567, l568, l573, l574, l578, l580, l585, l591, l593, l598, l615, l620, l628, l630, l631, l632, l638, l639, l640, l642, l643, l644, l645, l646, l648, l649, l650, l651, l652, l653, l659, l660, l671, l676, l682, l698, l699, l704, l705, l706, l744;
    uint8_t l26, l33, l475, l479, l483, l487, l694, l715, l737;
    vader_box_t l27 = vader_box_null(), l435 = vader_box_null(), l439 = vader_box_null(), l443 = vader_box_null(), l449 = vader_box_null(), l453 = vader_box_null(), l456 = vader_box_null(), l459 = vader_box_null(), l464 = vader_box_null(), l467 = vader_box_null(), l470 = vader_box_null(), l473 = vader_box_null(), l477 = vader_box_null(), l481 = vader_box_null(), l485 = vader_box_null(), l491 = vader_box_null(), l557 = vader_box_null(), l562 = vader_box_null(), l566 = vader_box_null(), l572 = vader_box_null(), l584 = vader_box_null(), l590 = vader_box_null(), l601 = vader_box_null(), l609 = vader_box_null(), l610 = vader_box_null(), l616 = vader_box_null(), l619 = vader_box_null(), l627 = vader_box_null(), l629 = vader_box_null(), l633 = vader_box_null(), l636 = vader_box_null(), l654 = vader_box_null(), l658 = vader_box_null(), l664 = vader_box_null(), l668 = vader_box_null(), l679 = vader_box_null(), l683 = vader_box_null(), l696 = vader_box_null(), l697 = vader_box_null(), l703 = vader_box_null(), l717 = vader_box_null(), l718 = vader_box_null();
    uint32_t l99, l102, l118, l119, l128, l129, l169, l171, l175, l177, l181, l183, l187, l189, l504, l541, l543, l545, l547;
    bool l136, l142, l148, l154, l160, l166, l172, l178, l184, l190, l293, l299, l305, l311, l317, l323, l329, l335, l341, l347, l380, l386, l392, l398, l404, l410, l413, l415, l416, l419, l421, l422, l425, l429, l433, l575, l586, l621, l622, l637, l641, l647, l672, l673, l681, l685, l688, l707, l710, l742, l743;
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
    vader_box_t* gc_roots[43] = {
        &l27, &l435, &l439, &l443, &l449, &l453, &l456, &l459, &l464, &l467, &l470, &l473, &l477,
        &l481, &l485, &l491, &l557, &l562, &l566, &l572, &l584, &l590, &l601, &l609, &l610, &l616,
        &l619, &l627, &l629, &l633, &l636, &l654, &l658, &l664, &l668, &l679, &l683, &l696, &l697,
        &l703, &l717, &l718, &t3,
    };
    void** gc_raw_roots[30] = {
        &l0, &l1, &l2, &l8, &l14, &l15, &l16, &l17, &l18, &l54, &l62, &l113, &l123, &l211, &l219,
        &l270, &l280, &l595, &l597, &l604, &l611, &l614, &l657, &l663, &l665, &l719, &l739, &l752,
        &l754, &t1,
    };
    vader_string_t* gc_atom_roots[6] = { &l565, &l571, &l583, &l589, &l596, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 43u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
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
            t3 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l24, 499u);
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
            t3 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l31, 499u);
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
                l55 = std_core$write_string_at(l54, l55, 2189u);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
                t2 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l13];
                l56 = ((int64_t) (int32_t) t2);
                l55 = std_core$write_int(l54, l55, l56);
                t0 = std_core$finish_buffer(l54, l55);
                vader_struct_vader_vm$Trap_t* _a12_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a12_obj, 1716u);
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
                l63 = std_core$write_string_at(l62, l63, 2195u);
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
                t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l13];
                l64 = ((int64_t) (int32_t) t2);
                l63 = std_core$write_int(l62, l63, l64);
                t0 = std_core$finish_buffer(l62, l63);
                vader_struct_vader_vm$Trap_t* _a14_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a14_obj, 1716u);
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
                l114 = std_core$write_string_at(l113, l114, 2953u);
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
                t2 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l13];
                l115 = ((int64_t) (int32_t) t2);
                l114 = std_core$write_int(l113, l114, l115);
                t0 = std_core$finish_buffer(l113, l114);
                vader_struct_vader_vm$Trap_t* _a16_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a16_obj, 1716u);
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
                l124 = std_core$write_string_at(l123, l124, 2959u);
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
                t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l13];
                l125 = ((int64_t) (int32_t) t2);
                l124 = std_core$write_int(l123, l124, l125);
                t0 = std_core$finish_buffer(l123, l124);
                vader_struct_vader_vm$Trap_t* _a18_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a18_obj, 1716u);
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
                l212 = std_core$write_string_at(l211, l212, 2211u);
                vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l13)
                t2 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l13];
                l213 = ((int64_t) (int32_t) t2);
                l212 = std_core$write_int(l211, l212, l213);
                t0 = std_core$finish_buffer(l211, l212);
                vader_struct_vader_vm$Trap_t* _a20_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a20_obj, 1716u);
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
                l220 = std_core$write_string_at(l219, l220, 2221u);
                vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l13)
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l13];
                l221 = ((int64_t) (int32_t) t2);
                l220 = std_core$write_int(l219, l220, l221);
                t0 = std_core$finish_buffer(l219, l220);
                vader_struct_vader_vm$Trap_t* _a22_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a22_obj, 1716u);
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
                l271 = std_core$write_string_at(l270, l271, 2963u);
                vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l13)
                t2 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l13];
                l272 = ((int64_t) (int32_t) t2);
                l271 = std_core$write_int(l270, l271, l272);
                t0 = std_core$finish_buffer(l270, l271);
                vader_struct_vader_vm$Trap_t* _a24_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a24_obj, 1716u);
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
                l281 = std_core$write_string_at(l280, l281, 2969u);
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l13)
                t2 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l13];
                l282 = ((int64_t) (int32_t) t2);
                l281 = std_core$write_int(l280, l281, l282);
                t0 = std_core$finish_buffer(l280, l281);
                vader_struct_vader_vm$Trap_t* _a26_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a26_obj, 1716u);
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
                t3 = vader_array_read_u8(_a27_slotarr, _a27_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a28_slotarr, _a28_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a29_slotarr, _a29_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a30_slotarr, _a30_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a31_slotarr, _a31_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a32_slotarr, _a32_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a33_slotarr, _a33_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a34_slotarr, _a34_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a35_slotarr, _a35_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a36_slotarr, _a36_slotarr->offset + (size_t) l13, 499u);
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
                t3 = vader_array_read_u8(_a37_slotarr, _a37_slotarr->offset + (size_t) l13, 499u);
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
            t3 = vader_array_read_u8(_a38_slotarr, _a38_slotarr->offset + (size_t) l13, 499u);
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
            t3 = vader_array_read_u8(_a39_slotarr, _a39_slotarr->offset + (size_t) l13, 499u);
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
            t3 = vader_array_read_u8(_a40_slotarr, _a40_slotarr->offset + (size_t) l13, 499u);
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
            t3 = vader_array_read_u8(_a41_slotarr, _a41_slotarr->offset + (size_t) l13, 499u);
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
            } else if (l19 == INT32_C(120)) {
                l557 = vader_vm$run_boxed(l0, l2, l8, l13, l12, l7);
                if (!(l557.tag == 0u)) {
                    t1 = l557.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(121)) {
                vader_vm$note_host_call(l2, l13, l11);
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
            } else if (l19 == INT32_C(122)) {
                t2 = vader_vm$operand_b(l20);
                l563 = ((int64_t) (int32_t) t2);
                l564 = vader_chk_add(i64, l12, l563);
                l566 = vader_vm$string_at(l2, l564);
                if (l566.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l564, l8, l13, 1758u, 2803u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l565 = l566.payload.s;
                l567 = vader_vm$operand_a(l20);
                t6 = vader_host_std_core$byte_len(l565);
                l568 = ((int32_t) (int64_t) t6);
                vader_vm$set_i32(l16, l17, l12, l567, l568);
            } else if (l19 == INT32_C(123)) {
                t2 = vader_vm$operand_b(l20);
                l569 = ((int64_t) (int32_t) t2);
                l570 = vader_chk_add(i64, l12, l569);
                l572 = vader_vm$string_at(l2, l570);
                if (l572.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l570, l8, l13, 1757u, 2803u);
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
                    vader_obj_header_init(_a43_obj, 1716u);
                    _a43_obj->f_message = 1756u;
                    t1 = (void*) _a43_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l578 = vader_vm$operand_a(l20);
                l579 = ((int64_t) (int32_t) l574);
                t10 = vader_host_std_core$byte_at(l571, l579);
                l580 = ((int32_t) (uint8_t) t10);
                vader_vm$set_i32(l16, l17, l12, l578, l580);
            } else if (l19 == INT32_C(125)) {
                t2 = vader_vm$operand_b(l20);
                l581 = ((int64_t) (int32_t) t2);
                l582 = vader_chk_add(i64, l12, l581);
                l584 = vader_vm$string_at(l2, l582);
                if (l584.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l582, l8, l13, 2313u, 2803u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l583 = l584.payload.s;
                l585 = vader_vm$operand_a(l20);
                l586 = vader_host_std_core$is_ascii(l583);
                vader_vm$set_bool(l16, l17, l12, l585, l586);
            } else if (l19 == INT32_C(124)) {
                t2 = vader_vm$operand_a(l20);
                l587 = ((int64_t) (int32_t) t2);
                l588 = vader_chk_add(i64, l12, l587);
                l590 = vader_vm$string_at(l2, l588);
                if (l590.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l588, l8, l13, 1759u, 2803u);
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
                vader_array_box_slots(_a44_slotarr->buf)[_a44_slotarr->offset + (size_t) l588] = vader_box_string(494u, l596);
                VADER_WRITE_BARRIER(_a44_slotarr->buf);
                vader_array_t* _a45_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l588)
                ((uint8_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l588] = (uint8_t) INT32_C(6);
            } else {
                if (l19 == INT32_C(126)) {
                    l597 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_texts;
                    l598 = vader_vm$operand_a(l20);
                    vader_array_t* _a46_slotarr = ((vader_array_t*) l597);
                    VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l598)
                    t3 = vader_array_box_slots(_a46_slotarr->buf)[_a46_slotarr->offset + (size_t) l598];
                    t0 = t3.payload.s;
                    vader_struct_vader_vm$Trap_t* _a47_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a47_obj, 1716u);
                    _a47_obj->f_message = t0;
                    t1 = (void*) _a47_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l19 == INT32_C(127)) {
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
                } else if (l19 == INT32_C(128)) {
                    l607 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_registers;
                    l608 = vader_chk_add(i64, l12, l607);
                    l609 = vader_vm$run_defers(l0, l1, l2, l8, l13, l608, l11, l7);
                    if (!(l609.tag == 0u)) {
                        t1 = l609.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else if (l19 == INT32_C(129)) {
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
                    if (l619.tag == 1713u) {
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
                        l629 = vader_vm$read_struct_field(l619, l620, l628, 2825u);
                        if (l629.tag == 1716u) {
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
                } else if (l19 == INT32_C(113)) {
                    t2 = vader_vm$operand_b(l20);
                    l634 = ((int64_t) (int32_t) t2);
                    l635 = vader_chk_add(i64, l12, l634);
                    l636 = vader_vm$struct_at(l2, l635);
                    if (!(l636.tag == 0u)) {
                        t1 = l636.payload.obj;
                        l638 = ((vader_struct_vader_vm$StructVal_t*) t1)->f_type_id;
                        l639 = vader_vm$operand_c(l20);
                        l637 = l638 == l639;
                    } else {
                        l637 = false;
                    }
                    l640 = vader_vm$operand_a(l20);
                    vader_vm$set_bool(l16, l17, l12, l640, l637);
                } else {
                    if (l19 == INT32_C(114)) {
                        l641 = true;
                    } else {
                        l641 = l19 == INT32_C(116);
                    }
                    if (l641) {
                        l642 = vader_vm$operand_a(l20);
                        l643 = vader_vm$operand_b(l20);
                        l644 = vader_vm$operand_c(l20);
                        t11 = vader_vm$try_get_element(l2, l12, l642, l643, l644);
                        if (!(t11)) {
                            l645 = vader_vm$operand_b(l20);
                            l646 = vader_vm$operand_c(l20);
                            t1 = vader_vm$element_trap(l2, l12, l645, l646, l8, l13, l19);
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    } else {
                        if (l19 == INT32_C(115)) {
                            l647 = true;
                        } else {
                            l647 = l19 == INT32_C(117);
                        }
                        if (l647) {
                            l648 = vader_vm$operand_a(l20);
                            l649 = vader_vm$operand_b(l20);
                            l650 = vader_vm$operand_c(l20);
                            t11 = vader_vm$try_set_element(l2, l12, l648, l649, l650);
                            if (!(t11)) {
                                l651 = vader_vm$operand_a(l20);
                                l652 = vader_vm$operand_b(l20);
                                l653 = vader_vm$operand_c(l20);
                                l654 = vader_vm$set_element(l2, l12, l651, l652, l653, l8, l13, l19);
                                if (!(l654.tag == 0u)) {
                                    t1 = l654.payload.obj;
                                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                            }
                        } else if (l19 == INT32_C(118)) {
                            t2 = vader_vm$operand_b(l20);
                            l655 = ((int64_t) (int32_t) t2);
                            l656 = vader_chk_add(i64, l12, l655);
                            l658 = vader_vm$array_at(l2, l656);
                            if (l658.tag == 0u) {
                                t1 = vader_vm$receiver_trap(l2, l656, l8, l13, 1662u, 1647u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l657 = l658.payload.obj;
                            l659 = vader_vm$operand_a(l20);
                            t6 = vader_vm$element_count(l657);
                            l660 = ((int32_t) (int64_t) t6);
                            vader_vm$set_i32(l16, l17, l12, l659, l660);
                        } else if (l19 == INT32_C(119)) {
                            t2 = vader_vm$operand_a(l20);
                            l661 = ((int64_t) (int32_t) t2);
                            l662 = vader_chk_add(i64, l12, l661);
                            l664 = vader_vm$array_at(l2, l662);
                            if (l664.tag == 0u) {
                                t1 = vader_vm$receiver_trap(l2, l662, l8, l13, 1665u, 1647u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l663 = l664.payload.obj;
                            if (!(((vader_struct_vader_vm$ArrayVal_t*) l663)->f_raw.tag == 0u)) {
                                vader_vm$own_bytes(l663);
                            }
                            l665 = ((vader_struct_vader_vm$ArrayVal_t*) l663)->f_elements;
                            t2 = vader_vm$operand_b(l20);
                            l666 = ((int64_t) (int32_t) t2);
                            l667 = vader_chk_add(i64, l12, l666);
                            l668 = vader_vm$register_value(l2, l667);
                            vader_array_push((vader_array_t*) l665, l668);
                        } else if (l19 == INT32_C(106)) {
                            t2 = vader_vm$operand_a(l20);
                            l669 = ((int64_t) (int32_t) t2);
                            l670 = vader_chk_add(i64, l12, l669);
                            l671 = vader_vm$operand_b(l20);
                            vader_vm$narrow_register(l2, l670, l671);
                        } else {
                            if (l19 == INT32_C(103)) {
                                l672 = true;
                            } else {
                                l672 = l19 == INT32_C(104);
                            }
                            if (l672) {
                                l673 = true;
                            } else {
                                l673 = l19 == INT32_C(105);
                            }
                            if (l673) {
                                t2 = vader_vm$operand_b(l20);
                                l674 = ((int64_t) (int32_t) t2);
                                l675 = vader_chk_add(i64, l12, l674);
                                l676 = vader_vm$operand_a(l20);
                                if (l19 == INT32_C(104)) {
                                    t2 = vader_vm$operand_c(l20);
                                    l677 = ((int64_t) (int32_t) t2);
                                    l678 = vader_chk_add(i64, l675, l677);
                                    vader_array_t* _a55_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l678)
                                    l679 = vader_array_box_slots(_a55_slotarr->buf)[_a55_slotarr->offset + (size_t) l678];
                                    l680 = vader_chk_add(i64, l675, l677);
                                    vader_array_t* _a56_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l680)
                                    t3 = vader_array_read_u8(_a56_slotarr, _a56_slotarr->offset + (size_t) l680, 499u);
                                    if (((int32_t) t3.payload.i) == INT32_C(6)) {
                                        l681 = l679.tag == 1686u;
                                    } else {
                                        l681 = false;
                                    }
                                    if (!(l681)) {
                                        vader_array_t* _a57_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l13)
                                        l699 = ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l13];
                                        t1 = vader_vm$indirect_call_trap(l1, l2, l675, l677, l699);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    t1 = l679.payload.obj;
                                    l682 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
                                    t1 = l679.payload.obj;
                                    l683 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_env;
                                    if (l683.tag == 0u) {
                                        l684 = l677;
                                    } else {
                                        l684 = vader_chk_add(i64, l677, INT64_C(1));
                                    }
                                    if ((l682 >= INT32_C(0))) {
                                        l686 = ((int64_t) (int32_t) l682);
                                        l687 = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions)->length;
                                        l685 = (l686 < l687);
                                    } else {
                                        l685 = false;
                                    }
                                    if (l685) {
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l682)
                                        t1 = vader_array_ref_load_obj(_a58_slotarr->buf, _a58_slotarr->offset + (size_t) l682);
                                        t6 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_params;
                                        l688 = t6 == l684;
                                    } else {
                                        l688 = false;
                                    }
                                    if (!(l688)) {
                                        vader_array_t* _a59_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l13)
                                        l698 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l13];
                                        t1 = vader_vm$indirect_call_trap(l1, l2, l675, l677, l698);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    if (!(l683.tag == 0u)) {
                                        l689 = l677;
                                        while ((l689 > INT64_C(0))) {
                                            l690 = vader_chk_add(i64, l675, l689);
                                            l691 = vader_chk_sub(i64, l690, INT64_C(1));
                                            vader_array_t* _a60_slotarr = ((vader_array_t*) l16);
                                            VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l691)
                                            l692 = ((int64_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l691];
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l690)
                                            ((int64_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l690] = (int64_t) l692;
                                            l693 = vader_chk_sub(i64, l690, INT64_C(1));
                                            vader_array_t* _a61_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a61_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l693)
                                            t3 = vader_array_read_u8(_a61_slotarr, _a61_slotarr->offset + (size_t) l693, 499u);
                                            l694 = ((uint8_t) t3.payload.i);
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l690)
                                            ((uint8_t*) _a61_slotarr->buf->slots)[_a61_slotarr->offset + (size_t) l690] = (uint8_t) (int32_t) (uint8_t) l694;
                                            l695 = vader_chk_sub(i64, l690, INT64_C(1));
                                            vader_array_t* _a62_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l695)
                                            l696 = vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l695];
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l690)
                                            vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l690] = l696;
                                            VADER_WRITE_BARRIER(_a62_slotarr->buf);
                                            l689 = vader_chk_sub(i64, l689, INT64_C(1));
                                        }
                                        l697 = l683;
                                        vader_vm$set_register(l2, l675, l697);
                                    }
                                    l676 = l682;
                                } else if (l19 == INT32_C(105)) {
                                    l700 = ((int64_t) (int32_t) l676);
                                    t2 = vader_vm$operand_c(l20);
                                    l701 = ((int64_t) (int32_t) t2);
                                    t6 = vader_chk_add(i64, l675, l701);
                                    l702 = vader_chk_sub(i64, t6, INT64_C(1));
                                    vader_array_t* _a63_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a63_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a63_slotarr, l702)
                                    l703 = vader_array_box_slots(_a63_slotarr->buf)[_a63_slotarr->offset + (size_t) l702];
                                    vader_array_t* _a64_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l702)
                                    t3 = vader_array_read_u8(_a64_slotarr, _a64_slotarr->offset + (size_t) l702, 499u);
                                    if (((int32_t) t3.payload.i) != INT32_C(6)) {
                                        l704 = INT32_C(-1);
                                    } else if (l703.tag == 1713u) {
                                        t1 = l703.payload.obj;
                                        l704 = ((vader_struct_vader_vm$StructVal_t*) t1)->f_type_id;
                                    } else if (l703.tag == 1681u) {
                                        t1 = l703.payload.obj;
                                        l704 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_type_id;
                                    } else {
                                        l704 = INT32_C(-1);
                                    }
                                    if ((l704 < INT32_C(0))) {
                                        l705 = INT32_C(-1);
                                    } else {
                                        vader_array_t* _a65_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_virtual_rows);
                                        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l700)
                                        l705 = ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l700];
                                    }
                                    l706 = vader_vm$lookup_vtable_row(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_vtables, l705, l704);
                                    if ((l706 >= INT32_C(0))) {
                                        l708 = ((int64_t) (int32_t) l706);
                                        l709 = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions)->length;
                                        l707 = (l708 < l709);
                                    } else {
                                        l707 = false;
                                    }
                                    if (l707) {
                                        vader_array_t* _a66_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l706)
                                        t1 = vader_array_ref_load_obj(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l706);
                                        t6 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_params;
                                        l710 = t6 == l701;
                                    } else {
                                        l710 = false;
                                    }
                                    if (l710) {
                                        if ((l702 > l675)) {
                                            l711 = l702;
                                            while ((l711 > l675)) {
                                                l712 = vader_chk_sub(i64, l711, INT64_C(1));
                                                vader_array_t* _a67_slotarr = ((vader_array_t*) l16);
                                                VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l712)
                                                l713 = ((int64_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l712];
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l711)
                                                ((int64_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l711] = (int64_t) l713;
                                                l714 = vader_chk_sub(i64, l711, INT64_C(1));
                                                vader_array_t* _a68_slotarr = ((vader_array_t*) l17);
                                                VADER_ARRAY_RESOLVE_BUF(_a68_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l714)
                                                t3 = vader_array_read_u8(_a68_slotarr, _a68_slotarr->offset + (size_t) l714, 499u);
                                                l715 = ((uint8_t) t3.payload.i);
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l711)
                                                ((uint8_t*) _a68_slotarr->buf->slots)[_a68_slotarr->offset + (size_t) l711] = (uint8_t) (int32_t) (uint8_t) l715;
                                                l716 = vader_chk_sub(i64, l711, INT64_C(1));
                                                vader_array_t* _a69_slotarr = ((vader_array_t*) l18);
                                                VADER_ARRAY_RESOLVE_BUF(_a69_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l716)
                                                l717 = vader_array_box_slots(_a69_slotarr->buf)[_a69_slotarr->offset + (size_t) l716];
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l711)
                                                vader_array_box_slots(_a69_slotarr->buf)[_a69_slotarr->offset + (size_t) l711] = l717;
                                                VADER_WRITE_BARRIER(_a69_slotarr->buf);
                                                l711 = vader_chk_sub(i64, l711, INT64_C(1));
                                            }
                                            vader_array_t* _a70_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a70_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a70_slotarr, l675)
                                            vader_array_box_slots(_a70_slotarr->buf)[_a70_slotarr->offset + (size_t) l675] = l703;
                                            VADER_WRITE_BARRIER(_a70_slotarr->buf);
                                            vader_array_t* _a71_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l675)
                                            ((uint8_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l675] = (uint8_t) INT32_C(6);
                                        }
                                        l676 = l706;
                                    } else {
                                        l718 = vader_vm$resolve_virtual(l0, l2, l8, l13, l675, l7);
                                        if (l718.tag == 1716u) {
                                            t1 = l718.payload.obj;
                                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        l676 = ((int32_t) l718.payload.i);
                                    }
                                }
                                if ((l676 >= INT32_C(0))) {
                                    vader_array_t* _a72_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                    VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l676)
                                    l719 = vader_array_ref_load_obj(_a72_slotarr->buf, _a72_slotarr->offset + (size_t) l676);
                                    l10 = vader_chk_add(i64, l10, INT64_C(1));
                                    l720 = ((int64_t) 1024);
                                    if ((l11 >= l720)) {
                                        t0 = ((vader_struct_vader_vm$RegFunction_t*) l719)->f_name;
                                        t1 = vader_vm$overflow_trap(t0);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    l721 = ((vader_array_t*) l16)->length;
                                    l722 = ((vader_struct_vader_vm$RegFunction_t*) l719)->f_registers;
                                    l723 = vader_chk_add(i64, l675, l722);
                                    if ((l721 < l723)) {
                                        l724 = ((vader_struct_vader_vm$RegFunction_t*) l719)->f_registers;
                                        l725 = vader_chk_add(i64, l675, l724);
                                        vader_vm$reserve_registers(l2, l725);
                                    }
                                    l726 = ((vader_struct_vader_vm$RegFunction_t*) l719)->f_params;
                                    l727 = vader_chk_add(i64, l675, l726);
                                    l728 = ((vader_struct_vader_vm$RegFunction_t*) l719)->f_slots;
                                    l729 = vader_chk_add(i64, l675, l728);
                                    while ((l727 < l729)) {
                                        vader_array_t* _a73_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l727)
                                        ((uint8_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l727] = (uint8_t) INT32_C(5);
                                        l727 = (l727 + INT64_C(1));
                                    }
                                    l730 = ((vader_struct_vader_vm$RegFunction_t*) l719)->f_slots;
                                    l731 = vader_chk_add(i64, l675, l730);
                                    l732 = INT64_C(0);
                                    l733 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l719)->f_consts)->length;
                                    while ((l732 < l733)) {
                                        l734 = vader_chk_add(i64, l731, l732);
                                        vader_array_t* _a74_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l719)->f_consts);
                                        VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l732)
                                        l735 = ((int64_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l732];
                                        vader_array_t* _a75_slotarr = ((vader_array_t*) l16);
                                        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a75_slotarr, l734)
                                        ((int64_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l734] = (int64_t) l735;
                                        l736 = vader_chk_add(i64, l731, l732);
                                        vader_array_t* _a76_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l719)->f_const_tags);
                                        VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l732)
                                        t3 = vader_array_read_u8(_a76_slotarr, _a76_slotarr->offset + (size_t) l732, 499u);
                                        l737 = ((uint8_t) t3.payload.i);
                                        vader_array_t* _a77_slotarr = ((vader_array_t*) l17);
                                        VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a77_slotarr, l736)
                                        ((uint8_t*) _a77_slotarr->buf->slots)[_a77_slotarr->offset + (size_t) l736] = (uint8_t) (int32_t) (uint8_t) l737;
                                        l732 = (l732 + INT64_C(1));
                                    }
                                    l738 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code)->length;
                                    if ((l11 < l738)) {
                                        vader_array_t* _a78_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code);
                                        VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a78_slotarr, l11)
                                        vader_array_ref_store(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l11, l719);
                                        VADER_WRITE_BARRIER(_a78_slotarr->buf);
                                        vader_array_t* _a79_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base);
                                        VADER_ARRAY_RESOLVE_BUF(_a79_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a79_slotarr, l11)
                                        ((int64_t*) _a79_slotarr->buf->slots)[_a79_slotarr->offset + (size_t) l11] = (int64_t) l675;
                                        l739 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return;
                                        l740 = vader_chk_add(i64, l13, INT64_C(1));
                                        vader_array_t* _a80_slotarr = ((vader_array_t*) l739);
                                        VADER_ARRAY_RESOLVE_BUF(_a80_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a80_slotarr, l11)
                                        ((int64_t*) _a80_slotarr->buf->slots)[_a80_slotarr->offset + (size_t) l11] = (int64_t) l740;
                                    } else {
                                        l741 = vader_chk_add(i64, l13, INT64_C(1));
                                        vader_vm$grow_frame_records(l2, l719, l675, l741);
                                    }
                                    l11 = vader_chk_add(i64, l11, INT64_C(1));
                                    l12 = l675;
                                    l8 = l719;
                                    l14 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_ops;
                                    l15 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_words;
                                    l13 = INT64_C(0);
                                    continue;
                                }
                            } else {
                                if (l19 == INT32_C(107)) {
                                    l742 = true;
                                } else {
                                    l742 = l19 == INT32_C(108);
                                }
                                if (!(l742)) {
                                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                }
                                l743 = l19 == INT32_C(108);
                                l744 = vader_vm$operand_a(l20);
                                if (l743) {
                                    l745 = INT64_C(0);
                                    t2 = vader_vm$operand_b(l20);
                                    l746 = ((int64_t) (int32_t) t2);
                                    while ((l745 < l746)) {
                                        l747 = vader_chk_add(i64, l12, l745);
                                        l748 = ((int64_t) (int32_t) l744);
                                        t6 = vader_chk_add(i64, l12, l748);
                                        l749 = vader_chk_add(i64, t6, l745);
                                        vader_vm$move_register(l2, l747, l749);
                                        l745 = (l745 + INT64_C(1));
                                    }
                                } else if ((l744 >= INT32_C(0))) {
                                    l750 = ((int64_t) (int32_t) l744);
                                    l751 = vader_chk_add(i64, l12, l750);
                                    vader_vm$move_register(l2, l12, l751);
                                }
                                l11 = vader_chk_sub(i64, l11, INT64_C(1));
                                if (l11 == l5) {
                                    if (l743) {
                                        if (l5 == INT64_C(0)) {
                                            vader_struct_vader_vm$Trap_t* _a81_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                                            vader_obj_header_init(_a81_obj, 1716u);
                                            _a81_obj->f_message = 2654u;
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
                                l752 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base;
                                l753 = vader_chk_sub(i64, l11, INT64_C(1));
                                vader_array_t* _a83_slotarr = ((vader_array_t*) l752);
                                VADER_ARRAY_RESOLVE_BUF(_a83_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a83_slotarr, l753)
                                l12 = ((int64_t*) _a83_slotarr->buf->slots)[_a83_slotarr->offset + (size_t) l753];
                                l754 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code;
                                l755 = vader_chk_sub(i64, l11, INT64_C(1));
                                vader_array_t* _a84_slotarr = ((vader_array_t*) l754);
                                VADER_ARRAY_RESOLVE_BUF(_a84_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a84_slotarr, l755)
                                l8 = vader_array_ref_load_obj(_a84_slotarr->buf, _a84_slotarr->offset + (size_t) l755);
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
    void* l10 = NULL;
    int32_t l8;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null();
    int64_t l11, l12;
    bool l14;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[5] = { &l4, &l6, &l9, &l13, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l7, &l10, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l8 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
    l9 = vader_vm$build_main_args(l7, l3, l8);
    if (l9.tag == 1716u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_vm$debug_session(l6, INT32_C(1));
    l10 = vader_vm$empty_machine(t1);
    vader_vm$note_entry_thread(l10);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    l11 = ((vader_struct_vader_vm$RegFunction_t*) t0)->f_registers;
    vader_vm$reserve_registers(l10, l11);
    l11 = INT64_C(0);
    t0 = l9.payload.obj;
    l12 = ((vader_array_t*) t0)->length;
    while ((l11 < l12)) {
        t0 = l9.payload.obj;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        l13 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l11];
        vader_vm$set_register(l10, l11, l13);
        l11 = (l11 + INT64_C(1));
    }
    l9 = vader_vm$reg_call(l0, l1, l10, l2, INT64_C(0), INT64_C(0), INT64_C(0), l5);
    if (!(l9.tag == 1716u)) {
        t2 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature);
        l14 = t2 == INT64_C(1);
        t1 = vader_vm$finish_run(l10, l14, l4);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l9.payload.obj;
    t3 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
    t4 = vader_vm$is_overflow_trap_message(t3);
    if (!(t4)) {
        vader_vm$unwind(l0, l1, l10, l5);
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_vm$frame_names(l10);
    vader_vm$unwind(l0, l1, l10, l5);
    t0 = l9.payload.obj;
    vader_struct_vader_vm$StackOverflow_t* _a3_obj = (vader_struct_vader_vm$StackOverflow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackOverflow_t));
    vader_obj_header_init(_a3_obj, 1711u);
    _a3_obj->f_trap = t0;
    _a3_obj->f_frames = l7;
    t0 = (void*) _a3_obj;
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
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
        l3 = vader_box_i32(497u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l1];
        l3 = vader_box_i64(498u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1];
        l3 = vader_box_f64(504u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
        l3 = vader_box_bool(492u, t1 != INT64_C(0));
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
        l3 = vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l4));
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
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits)->length;
        if ((t0 < l1)) {
            vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits, INT64_C(0));
            vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags, INT32_C(5));
            l2 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
            t1 = (void*) &vader_data_169;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
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
    int32_t l9, l10, l12;
    vader_box_t l11 = vader_box_null(), l21 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    bool l18;
    uint8_t l20;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[2] = { &l11, &l21 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l8, &l17, &l19, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l13, &l14, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
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
        l15 = std_core$write_string_at(l17, l15, 3197u);
        l15 = std_core$write_string_at(l17, l15, l13);
        l15 = std_core$write_string_at(l17, l15, 312u);
        l15 = std_core$write_string_at(l17, l15, l14);
        l15 = std_core$write_string_at(l17, l15, 141u);
        l16 = ((int64_t) (int32_t) l10);
        l15 = std_core$write_int(l17, l15, l16);
        t2 = std_core$finish_buffer(l17, l15);
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 1716u);
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
            l13 = concat_3(3197u, l13, 307u);
            t3 = vader_vm$fn_index_trap(l9, l10, l13);
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l17 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l17)->f_signature)->f_params)->length;
        if (!(t1 != l6)) {
            { vader_box_t __vret = vader_box_i32(497u, l9); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l17)->f_signature)->f_params)->length;
        l13 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l8)->f_vtable_key;
        l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l17)->f_name;
        l15 = vader_host_std_core$byte_len(l13);
        l16 = vader_host_std_core$byte_len(l14);
        l15 = (l15 + l16);
        l17 = (void*) vader_buffer_new((size_t) (INT64_C(134) + l15));
        l15 = INT64_C(0);
        l15 = std_core$write_string_at(l17, l15, 3197u);
        l15 = std_core$write_string_at(l17, l15, l13);
        l15 = std_core$write_string_at(l17, l15, 310u);
        l15 = std_core$write_string_at(l17, l15, l14);
        l15 = std_core$write_string_at(l17, l15, 315u);
        l15 = std_core$write_int(l17, l15, l7);
        l15 = std_core$write_string_at(l17, l15, 207u);
        l15 = std_core$write_int(l17, l15, l6);
        l15 = std_core$write_string_at(l17, l15, 99u);
        l7 = ((int64_t) (int32_t) l10);
        l15 = std_core$write_int(l17, l15, l7);
        t2 = std_core$finish_buffer(l17, l15);
        vader_struct_vader_vm$Trap_t* _a6_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a6_obj, 1716u);
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
        l7 = std_core$write_string_at(l8, l7, 3197u);
        l7 = std_core$write_string_at(l8, l7, l13);
        l7 = std_core$write_string_at(l8, l7, 311u);
        l15 = ((int64_t) (int32_t) l12);
        l7 = std_core$write_int(l8, l7, l15);
        l7 = std_core$write_string_at(l8, l7, 99u);
        l15 = ((int64_t) (int32_t) l10);
        l7 = std_core$write_int(l8, l7, l15);
        t2 = std_core$finish_buffer(l8, l7);
        vader_struct_vader_vm$Trap_t* _a7_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a7_obj, 1716u);
        _a7_obj->f_message = t2;
        t3 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_vm$primitive_impl_import(l14, l6);
    if ((INT64_C(0) < l6)) {
        l7 = l6;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a8_arr = vader_array_reserve(414u, (int64_t) l7, 0u, 2456u);
    l17 = (void*) _a8_arr;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        l15 = vader_chk_add(i64, l4, l7);
        l11 = vader_vm$register_value(l1, l15);
        vader_array_push((vader_array_t*) l17, l11);
        l7 = (l7 + INT64_C(1));
    }
    l19 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_gc_state;
    l9 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
    l12 = ((vader_struct_vader_vm$VmState_t*) l0)->f_u8_array_type_id;
    l20 = vader_core_bytecode$intrinsic_id_for(l14);
    l11 = vader_vm$dispatch_import(l8, l17, INT64_C(0), l19, l10, l9, l12, l5, l20);
    if (!(l11.tag == 1716u)) {
        t3 = l11.payload.obj;
        l21 = ((vader_struct_vader_vm$HostOk_t*) t3)->f_value;
        vader_vm$set_register(l1, l4, l21);
        { vader_box_t __vret = vader_box_i32(497u, INT32_C(-1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l11.payload.obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$restore(void* l0) {
    int64_t l1, l2;
    vader_box_t l3;
    int32_t l4;
    void* t0;
    l1 = INT64_C(0);
    l2 = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_sources)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_sources);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_kept_ids);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
        if (l3.tag == 1713u) {
            t0 = l3.payload.obj;
            ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id = l4;
        } else if (l3.tag == 1681u) {
            t0 = l3.payload.obj;
            ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id = l4;
        } else if (l3.tag == 1697u) {
            t0 = l3.payload.obj;
            ((vader_struct_vader_vm$ObjVal_t*) t0)->f_type_id = l4;
        } else if (!((l3.tag == 1686u || l3.tag == 1717u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (l1 + INT64_C(1));
    }
    return;
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 499u);
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
    if (l3.tag == 975u) {
        t1 = l3.payload.obj;
        return ((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val == INT32_C(14);
    }
    return false;
}

static vader_box_t vader_vm$retyped_int(vader_box_t l0, int64_t l1) {
    uint32_t l2;
    bool l3;
    int32_t t0;
    if (l0.tag == 498u) {
        return vader_box_i64(498u, l1);
    }
    if (l0.tag == 492u) {
        return vader_box_bool(492u, l1 != INT64_C(0));
    }
    if (!(l0.tag == 493u)) {
        return vader_box_i32(497u, ((int32_t) (int64_t) l1));
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
            return vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l2));
        }
    } else {
        return vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l2));
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
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l19, 499u);
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
    if (l24.tag == 1716u) {
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
        t1 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l6, 499u);
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
        l10 = std_core$write_string_at(l12, l10, 1923u);
        l11 = ((int64_t) (int32_t) l8);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 400u);
        l11 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 350u);
        l11 = ((int64_t) (int32_t) l9);
        l10 = std_core$write_int(l12, l10, l11);
        t1 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 1716u);
        _a2_obj->f_message = t1;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    l11 = ((int64_t) (int32_t) l8);
    l10 = vader_chk_sub(i64, l10, l11);
    vader_array_t* _a3_arr = vader_array_new(362u, 0u, 13u, 1686u);
    l12 = (void*) _a3_arr;
    l11 = l10;
    l13 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    while ((l11 < l13)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l14 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l11];
        l15 = vader_vm$defer_thunk(l0, l14, l9, 1921u);
        if (l15.tag == 1716u) {
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
        l7 = std_core$write_string_at(l9, l7, 2507u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l9, l7, l8);
        l7 = std_core$write_string_at(l9, l7, 342u);
        t0 = std_core$finish_buffer(l9, l7);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
        vader_obj_header_init(_a1_obj, 1716u);
        _a1_obj->f_message = 1513u;
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
    if (l3.tag == 1716u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 494u);
    l4 = (void*) _a0_arr;
    t1 = vader_vm$zero_value();
    vader_array_t* _a1_arr = vader_array_new(414u, 1u, 0u, 2456u);
    vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = t1;
    l5 = (void*) _a1_arr;
    l6 = ((int32_t) l3.payload.i);
    t1 = vader_vm$run_entry(l0, l6, l4, vader_ref_box(l5), l2, vader_box_obj(0u, NULL));
    l3 = vader_vm$after_entry(t1, 2875u);
    if (!((l3.tag == 1711u || l3.tag == 1716u))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        vader_struct_vader_vm$ValueOk_t* _a3_obj = (vader_struct_vader_vm$ValueOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ValueOk_t));
        vader_obj_header_init(_a3_obj, 1718u);
        _a3_obj->f_value = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$run_guest_thread(void* l0, void* l1, bool l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    int64_t l5;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    int32_t l9;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_vm$guest_threads();
    l5 = vader_host_std_runtime_scheduler$current_thread();
    l6 = vader_vm$empty_machine(l3);
    l7 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l4)->f_live, l5);
    if (!(l7.tag == 0u)) {
        t0 = l7.payload.obj;
        ((vader_struct_vader_vm$GuestThread_t*) t0)->f_started = true;
        t0 = l7.payload.obj;
        ((vader_struct_vader_vm$GuestThread_t*) t0)->f_machine = vader_ref_box(l6);
        VADER_WRITE_BARRIER((vader_struct_vader_vm$GuestThread_t*) t0);
    }
    vader_struct___defer_env_vader_vm_22_t* _a0_obj = (vader_struct___defer_env_vader_vm_22_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_vader_vm_22_t));
    vader_obj_header_init(_a0_obj, 520u);
    _a0_obj->f_cap_0 = l4;
    _a0_obj->f_cap_1 = l5;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 436u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_vader_vm_21;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_struct___defer_env_vader_vm_24_t* _a2_obj = (vader_struct___defer_env_vader_vm_24_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_vader_vm_24_t));
    vader_obj_header_init(_a2_obj, 521u);
    _a2_obj->f_cap_0 = l0;
    _a2_obj->f_cap_1 = l6;
    _a2_obj->f_cap_2 = l2;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 436u);
    _a3_closure->code = (void*) &vader_fn_lift___defer_vader_vm_23;
    _a3_closure->env = t0;
    t0 = (void*) _a3_closure;
    vader_defer_push(vader_ref_box(t0));
    l4 = ((vader_struct_vader_vm$VmState_t*) l0)->f_reg;
    l7 = vader_vm$run_thunk(l0, l4, l6, l1, INT64_C(0), INT64_C(0), INT64_C(0), l2);
    if (!(l7.tag == 1716u)) {
        vader_defer_pop_exec(2u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_vader_vm$DebugController_t*) ((vader_struct_vader_vm$DebugSession_t*) t0)->f_controller)->f_on_fatal_trap;
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
        t0 = l3.payload.obj;
        l9 = ((vader_struct_vader_vm$DebugSession_t*) t0)->f_thread_id;
        l6 = vader_vm$debugged_threads(l0);
        t0 = vader_vm$exception_stop(l8, l9, l6);
        vader_fn_t* _a4_fnobj = (vader_fn_t*) l4;
        ((vader_fn_erased_sig_1_t) _a4_fnobj->code)(_a4_fnobj->env, vader_ref_box(t0));
    }
    t0 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
    t1 = concat_2(1537u, l8);
    vader_host_std_abort$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
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
    if (l0.tag == 1037u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a0_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a0_obj, 1709u);
        _a0_obj->f_bits = ((int64_t) (int32_t) t1);
        _a0_obj->f_tag = (uint8_t) 0;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1057u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a1_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a1_obj, 1709u);
        _a1_obj->f_bits = t2;
        _a1_obj->f_tag = (uint8_t) 1;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1016u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a2_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a2_obj, 1709u);
        _a2_obj->f_bits = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t3 }).__vu);
        _a2_obj->f_tag = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 988u) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        if (t4) {
            l2 = INT64_C(1);
        } else {
            l2 = INT64_C(0);
        }
        vader_struct_vader_vm$Scalar_t* _a3_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a3_obj, 1709u);
        _a3_obj->f_bits = l2;
        _a3_obj->f_tag = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1003u) {
        t0 = l0.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a4_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a4_obj, 1709u);
        _a4_obj->f_bits = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        _a4_obj->f_tag = (uint8_t) 4;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1088u) {
        vader_struct_vader_vm$Scalar_t* _a5_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a5_obj, 1709u);
        _a5_obj->f_bits = INT64_C(0);
        _a5_obj->f_tag = (uint8_t) 5;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1104u)) {
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
    l1 = (void*) &vader_fn_static___lambda_vader_vm_8;
    l1 = std_core$filled__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 8u, 498u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(5);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l3 = (void*) _a3_arr;
    vader_struct_vader_vm$Frame_t* _a4_obj = (vader_struct_vader_vm$Frame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Frame_t));
    vader_obj_header_init(_a4_obj, 1688u);
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
        l9 = std_core$write_string_at(l10, l9, 2050u);
        l9 = std_core$write_string_at(l10, l9, l8);
        l9 = std_core$write_string_at(l10, l9, 1120u);
        l11 = ((int64_t) (int32_t) l5);
        l9 = std_core$write_int(l10, l9, l11);
        l9 = std_core$write_string_at(l10, l9, 528u);
        l9 = std_core$write_int(l10, l9, INT64_C(16));
        t0 = std_core$finish_buffer(l10, l9);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
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
            if ((l29.tag == 503u || l29.tag == 504u)) {
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
            if (l29.tag == 498u) {
                l34 = true;
            } else {
                l34 = l29.tag == 497u;
            }
            if (l34) {
                l35 = true;
            } else {
                l35 = l29.tag == 492u;
            }
            if (l35) {
                l36 = true;
            } else {
                l36 = l29.tag == 493u;
            }
            if (l36) {
                l33 = vader_vm$read_scalar_word(l29, l5, 0u);
            } else {
                l37 = l29;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
                l38 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
                l39 = concat_5(2050u, l6, 1148u, l38, 1087u);
                l33 = vader_vm$read_scalar_word(l37, l5, l39);
            }
            if (l33.tag == 1716u) {
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
        if (!(l13.tag == 1713u)) {
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
            l19 = std_core$write_string_at(l18, l19, 2050u);
            l19 = std_core$write_string_at(l18, l19, l8);
            l19 = std_core$write_string_at(l18, l19, 1120u);
            l20 = ((int64_t) (int32_t) l5);
            l19 = std_core$write_int(l18, l19, l20);
            l19 = std_core$write_string_at(l18, l19, 524u);
            l19 = std_core$write_string_at(l18, l19, l14);
            l19 = std_core$write_string_at(l18, l19, 1259u);
            t0 = std_core$finish_buffer(l18, l19);
            vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a9_obj, 1716u);
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
        if (l26.tag == 1716u) {
            t1 = l26.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_vm$serve_import(void* l0, void* l1, int32_t l2, void* l3, void* l4, int32_t l5, bool l6) {
    vader_box_t l7 = vader_box_null();
    uint8_t l8;
    void* l9 = NULL;
    int32_t l10, l11;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_is_extern;
    if (t0) {
        l7 = vader_vm$debug_controller(l1);
        t1 = vader_vm$dispatch_extern(l0, l2, l4, INT64_C(0), l5, l7);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_import_ids);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l2, 499u);
    l8 = ((uint8_t) t1.payload.i);
    if (l8 == INT32_C(9)) {
        l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l7 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_vm$deep_copy_value(l9, l7, l5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_vm$serve_thread_primitive(l0, l1, l8, l4, l5, l6);
    if (l7.tag == 0u) {
        l9 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_gc_state;
        l10 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
        l11 = ((vader_struct_vader_vm$VmState_t*) l0)->f_u8_array_type_id;
        t1 = vader_vm$dispatch_import(l3, l4, INT64_C(0), l9, l5, l10, l11, l6, l8);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_thread_primitive(void* l0, void* l1, uint8_t l2, void* l3, int32_t l4, bool l5) {
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* l8 = NULL;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l6, &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(19)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l6 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        l7 = vader_vm$debug_controller(l1);
        l6 = vader_vm$start_guest_thread(l0, l6, l5, l7);
        { vader_box_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(20)) {
        l6 = vader_vm$parked();
    } else if (l2 == INT32_C(21)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l7 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        l8 = (void*) &vader_fn_static___lambda_vader_vm_18;
        l6 = vader_vm$on_i64(l7, l4, 3206u, l8);
    } else if (l2 == INT32_C(22)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        l7 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        l8 = (void*) &vader_fn_static___lambda_vader_vm_17;
        l6 = vader_vm$on_i64(l7, l4, 2694u, l8);
    } else if (l2 == INT32_C(25)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        l7 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        l8 = (void*) &vader_fn_static___lambda_vader_vm_16;
        l6 = vader_vm$on_i64(l7, l4, 3211u, l8);
    } else if (l2 == INT32_C(26)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        l7 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        l8 = (void*) &vader_fn_static___lambda_vader_vm_15;
        l6 = vader_vm$on_i64(l7, l4, 3210u, l8);
    } else if (l2 == INT32_C(27)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
        l7 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) INT32_C(0)];
        l8 = (void*) &vader_fn_static___lambda_vader_vm_14;
        l6 = vader_vm$on_i64(l7, l4, 3205u, l8);
    } else if (l2 == INT32_C(23)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) INT32_C(0)];
        l6 = vader_vm$cancel_guest_thread(t0, l4);
    } else if (l2 == INT32_C(24)) {
        t1 = vader_host_std_runtime_scheduler$current_thread();
        vader_struct_vader_vm$HostOk_t* _a7_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a7_obj, 1693u);
        _a7_obj->f_value = vader_box_i64(498u, t1);
        t2 = (void*) _a7_obj;
        l6 = vader_ref_box(t2);
    } else {
        l6 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
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
        l14 = vader_vm$element_count(l9);
        l13 = (l8 >= l14);
    }
    if (!(l13)) {
        vader_vm$own_bytes(l9);
        l9 = ((vader_struct_vader_vm$ArrayVal_t*) l9)->f_elements;
        l8 = ((int64_t) (int32_t) l4);
        l8 = vader_chk_add(i64, l1, l8);
        l10 = vader_vm$register_value(l0, l8);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l12] = l10;
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
    if (l9.tag == 1713u) {
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
        l11 = std_core$write_string_at(l7, l11, 2831u);
        l12 = ((int64_t) (int32_t) l4);
        l11 = std_core$write_int(l7, l11, l12);
        l11 = std_core$write_string_at(l7, l11, 203u);
        l11 = std_core$write_int(l7, l11, l8);
        l11 = std_core$write_string_at(l7, l11, 127u);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l5)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l8 = ((int64_t) (int32_t) t1);
        l11 = std_core$write_int(l7, l11, l8);
        t2 = std_core$finish_buffer(l7, l11);
        vader_struct_vader_vm$Trap_t* _a3_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a3_obj, 1716u);
        _a3_obj->f_message = t2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l5)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
    l16 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
    l9 = vader_vm$read_struct(l9, l16, 2833u);
    if (l9.tag == 1716u) {
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
    if (l2.tag == 497u) {
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
    if (l2.tag == 498u) {
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
    } else if ((l2.tag == 503u || l2.tag == 504u)) {
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
    } else if (l2.tag == 492u) {
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
    } else if (l2.tag == 493u) {
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
    } else if (l2.tag == 1696u) {
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
    if (t0.tag == 1072u) {
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
        return t0.tag == 1012u;
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
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 499u);
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
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload, INT64_C(0));
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag, INT32_C(5));
    l1 = ((vader_struct_vader_vm$Frame_t*) l0)->f_stack;
    t0 = (void*) &vader_data_169;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    t1 = vader_vm$is_i32_tag(((uint8_t) t0.payload.i));
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
        { vader_box_t __vret = vader_box_i32(497u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$peek_val(l0, l1);
    l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = concat_3(l2, 14u, l3);
    l4 = vader_vm$read_i32(l4, l5, l6);
    if (l4.tag == 1716u) {
        t3 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((int32_t) l4.payload.i);
    { vader_box_t __vret = vader_box_i32(497u, t4); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l3.tag == 1697u)) {
        l4 = l3;
        l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l6 = concat_2(l2, 216u);
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
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 499u);
        t3 = ((uint8_t) t2.payload.i);
        { uint8_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(79));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 3028u);
    l4 = std_core$write_int(l3, l4, l2);
    l4 = std_core$write_string_at(l3, l4, 100u);
    t4 = std_core$finish_buffer(l3, l4);
    vader_host_std_abort$panic(t4);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm$start_guest_thread(void* l0, vader_box_t l1, bool l2, vader_box_t l3) {
    int32_t l4;
    void* l5 = NULL;
    void* l10 = NULL;
    int64_t l6, l7, l9;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l8 };
    void** gc_raw_roots[4] = { &l0, &l5, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1686u)) {
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 1716u);
        _a0_obj->f_message = 1571u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l4 = ((vader_struct_vader_vm$FnVal_t*) t0)->f_function_index;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    t1 = vader_vm$is_fn_index_out_of_range(l4, l5);
    if (t1) {
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 1716u);
        _a1_obj->f_message = 1572u;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_vm$RegModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_reg)->f_functions;
    t0 = l1.payload.obj;
    l4 = ((vader_struct_vader_vm$FnVal_t*) t0)->f_function_index;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l6 = ((vader_struct_vader_vm$RegFunction_t*) t0)->f_params;
    t0 = l1.payload.obj;
    l7 = vader_vm$environment_params(t0);
    if (!(l6 != l7)) {
        l5 = vader_vm$guest_threads();
        t2 = ((vader_struct_vader_vm$GuestThreads_t*) l5)->f_numbered;
        l6 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_vm$GuestThreads_t*) l5)->f_numbered = l6;
        l6 = ((vader_struct_vader_vm$GuestThreads_t*) l5)->f_numbered;
        l4 = vader_vm$debugged_thread_id(l6);
        l8 = vader_vm$debug_session(l3, l4);
        l7 = vader_host_std_runtime_scheduler$current_thread();
        vader_struct___lambda_env_vader_vm_20_t* _a3_obj = (vader_struct___lambda_env_vader_vm_20_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_20_t));
        vader_obj_header_init(_a3_obj, 669u);
        _a3_obj->f_cap_0 = l0;
        _a3_obj->f_cap_1 = l1;
        _a3_obj->f_cap_2 = l2;
        _a3_obj->f_cap_3 = l8;
        t0 = (void*) _a3_obj;
        vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a4_closure, 436u);
        _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_19;
        _a4_closure->env = t0;
        t0 = (void*) _a4_closure;
        l9 = vader_host_std_runtime_scheduler$spawn_thread(t0);
        l5 = ((vader_struct_vader_vm$GuestThreads_t*) l5)->f_live;
        vader_struct_vader_vm$GuestThread_t* _a5_obj = (vader_struct_vader_vm$GuestThread_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$GuestThread_t));
        vader_obj_header_init(_a5_obj, 1691u);
        _a5_obj->f_number = l6;
        _a5_obj->f_launcher = l7;
        _a5_obj->f_started = false;
        _a5_obj->f_cancelled = false;
        _a5_obj->f_machine = vader_box_obj(0u, NULL);
        l10 = (void*) _a5_obj;
        std_collections$Map$std_core$IndexSet$set_at__i64__Any(l5, l9, vader_ref_box(l10));
        vader_struct_vader_vm$HostOk_t* _a6_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a6_obj, 1693u);
        _a6_obj->f_value = vader_box_i64(498u, l9);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$Trap_t* _a7_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a7_obj, 1716u);
    _a7_obj->f_message = 1573u;
    t0 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    void* l14 = NULL;
    int32_t l7, l10;
    vader_box_t l9 = vader_box_null();
    vader_string_t l11 = 0;
    bool l12;
    uint8_t l13;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l8, &l14, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
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
        l11 = 1728u;
    } else {
        l11 = 2788u;
    }
    l6 = ((vader_struct_vader_vm$DebugController_t*) ((vader_struct_vader_vm$DebugSession_t*) l2)->f_controller)->f_on_pause;
    l10 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_thread_id;
    l8 = vader_vm$call_stack(l0, l1, l4, l5);
    l14 = vader_vm$debugged_threads(l0);
    vader_struct_vader_vm$PauseCtx_t* _a3_obj = (vader_struct_vader_vm$PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseCtx_t));
    vader_obj_header_init(_a3_obj, 1699u);
    _a3_obj->f_reason = l11;
    _a3_obj->f_text = 0u;
    _a3_obj->f_thread_id = l10;
    _a3_obj->f_frames = l8;
    _a3_obj->f_threads = l14;
    t0 = (void*) _a3_obj;
    vader_fn_t* _a4_fnobj = (vader_fn_t*) l6;
    t2 = ((vader_fn_erased_sig_1_t) _a4_fnobj->code)(_a4_fnobj->env, vader_ref_box(t0));
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
    l5 = vader_vm$stack_i32(l0, l4, l3, 2539u);
    if (l5.tag == 1716u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(3));
    l6 = vader_vm$stack_obj(l0, l4, l3);
    if (l6.tag == 1716u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l5.payload.i);
    t1 = l6.payload.obj;
    l4 = ((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) t1)->f_bytes)->length;
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$check_byte_range(l7, l1, l4, l3, l8);
    if (!(l5.tag == 1716u)) {
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
        vader_obj_header_init(_a4_obj, 1703u);
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
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_arr = vader_array_reserve(414u, (int64_t) t0, 0u, 2456u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
        l6 = t1.payload.s;
        vader_array_push((vader_array_t*) l2, vader_box_string(494u, l6));
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 1681u);
    _a2_obj->f_type_id = l1;
    _a2_obj->f_elements = l2;
    _a2_obj->f_raw = vader_box_obj(0u, NULL);
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$string_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    vader_string_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 494u) {
            t1 = l2.payload.s;
            return vader_box_string(494u, t1);
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
        t0 = vader_vm$one_argument_string_op(l0, l1, INT32_C(122));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(4)) {
        t0 = vader_vm$one_argument_string_op(l0, l1, INT32_C(125));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        l3 = vader_vm$operand(l0, INT64_C(1));
        l4 = vader_vm$operand(l0, INT64_C(2));
        l5 = vader_vm$pop_to(l0, INT64_C(2));
        vader_vm$emit(l0, l1, INT32_C(123), l5, l4, l3);
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
    vader_vm$emit(l0, l1, INT32_C(124), l5, l4, l3);
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
    vader_array_push((vader_array_t*) l6, vader_box_string(494u, l9));
    t1 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_code)->f_values)->length;
    t2 = vader_chk_sub(i64, t1, INT64_C(1));
    l8 = ((int32_t) (int64_t) t2);
    vader_vm$emit(l1, l2, INT32_C(110), l5, l8, INT32_C(0));
    vader_vm$push_register(l1, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$struct_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        if (l2.tag == 1713u) {
            t1 = l2.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
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
    if (!(l3.tag == 978u)) {
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 499u);
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 499u);
        l6 = ((uint8_t) t1.payload.i);
    } else {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_vm$StackEffect_t*) l5)->f_pops;
    l7 = vader_chk_sub(i64, l4, l7);
    if (l1.tag == 1083u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t2)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    } else if (l1.tag == 1084u) {
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
            t1 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l13, 499u);
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
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 8u, 498u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 499u);
    l10 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(33u, 0u, 0u, 505u);
    l11 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(28u, 0u, 8u, 498u);
    l12 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 497u);
    l13 = (void*) _a5_arr;
    vader_struct_std_collections$Map__Any__i64_t* _a6_obj = (vader_struct_std_collections$Map__Any__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__Any__i64_t));
    vader_obj_header_init(_a6_obj, 682u);
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
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 497u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(28u, 0u, 8u, 498u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(27u, 0u, 7u, 497u);
    l15 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(29u, 0u, 1u, 499u);
    l16 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(414u, 0u, 0u, 2456u);
    l17 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(390u, 0u, 13u, 1980u);
    l18 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(180u, 0u, 13u, 1127u);
    l19 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(27u, 0u, 7u, 497u);
    l20 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(26u, 0u, 0u, 494u);
    l21 = (void*) _a15_arr;
    l22 = ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_deepest;
    t0 = vader_chk_add(i64, l8, l22);
    l22 = vader_chk_add(i64, t0, INT64_C(1));
    l23 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature)->f_params)->length;
    vader_struct_vader_vm$RegFunction_t* _a16_obj = (vader_struct_vader_vm$RegFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegFunction_t));
    vader_obj_header_init(_a16_obj, 1704u);
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
    vader_array_t* _a17_arr = vader_array_new(27u, 0u, 7u, 497u);
    l10 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(371u, 0u, 13u, 1703u);
    l12 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(28u, 0u, 8u, 498u);
    l13 = (void*) _a19_arr;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_vm$Translation_t* _a20_obj = (vader_struct_vader_vm$Translation_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Translation_t));
    vader_obj_header_init(_a20_obj, 1715u);
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
    vader_array_t* _a21_arr = vader_array_new(28u, 1u, 8u, 498u);
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
                    vader_vm$emit(l9, l7, INT32_C(129), INT32_C(0), INT32_C(0), INT32_C(0));
                }
            }
        }
        t1 = vader_vm$translate_op(l0, l5, l3, l9, l7);
        if (!(t1)) {
            l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
            l24 = ((int32_t) (int64_t) l7);
            vader_struct_vader_vm$VerifyError_t* _a29_obj = (vader_struct_vader_vm$VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VerifyError_t));
            vader_obj_header_init(_a29_obj, 1719u);
            _a29_obj->f_function = l14;
            _a29_obj->f_pc = l24;
            _a29_obj->f_message = 2513u;
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
            vader_obj_header_init(_a36_obj, 1719u);
            _a36_obj->f_function = l14;
            _a36_obj->f_pc = l30;
            _a36_obj->f_message = 1629u;
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
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l8, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_reserve(372u, (int64_t) t0, 13u, 1704u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l5 < l6)) {
        l7 = ((int32_t) (int64_t) l5);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l9 = vader_vm$translate_function(l0, l1, l7, l8, l3);
        if (l9.tag == 1719u) {
            t1 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = l9.payload.obj;
        vader_array_push_ref((vader_array_t*) l4, l10);
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_vm$RegModule_t* _a2_obj = (vader_struct_vader_vm$RegModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegModule_t));
    vader_obj_header_init(_a2_obj, 1706u);
    _a2_obj->f_functions = l4;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
    l7 = vader_vm$unary_op(l0, l5, l2, l4);
    if (!(l7.tag == 0u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        l10 = ((int32_t) l7.payload.i);
        l11 = vader_vm$type_operand(l5);
        vader_vm$emit(l3, l4, l10, l9, l8, l11);
        vader_vm$note_checked_kind(l3, l5);
        vader_vm$push_register(l3, l9);
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops)->length;
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 1082u) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_stack;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
        vader_struct_vader_vm$Pending_t* _a1_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
        vader_obj_header_init(_a1_obj, 1703u);
        _a1_obj->f_kind = (uint8_t) 1;
        _a1_obj->f_register = l8;
        l14 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l13, l14);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 1083u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
        vader_vm$store_slot(l3, l1, l4, l8, false, l6);
    } else if (l5.tag == 1084u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t1)->f_slot;
        vader_vm$store_slot(l3, l1, l4, l8, true, l6);
    } else if ((l5.tag == 988u || l5.tag == 1003u || l5.tag == 1016u || l5.tag == 1037u || l5.tag == 1057u || l5.tag == 1088u)) {
        l7 = l5;
        vader_vm$push_constant(l3, l7);
    } else if (l5.tag == 1011u) {
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
    } else if ((l5.tag == 986u || l5.tag == 1013u || l5.tag == 1085u || l5.tag == 1089u || l5.tag == 1092u)) {
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l6;
    } else if ((l5.tag == 993u || l5.tag == 1012u)) {
        if (l5.tag == 1012u) {
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
    } else if ((l5.tag == 994u || l5.tag == 1072u)) {
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
        if (l5.tag == 994u) {
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
    } else if (l5.tag == 1093u) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 499u);
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
    } else if (l5.tag == 1002u) {
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
    } else if (l5.tag == 1127u) {
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
    } else if (l5.tag == 1000u) {
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
    } else if (l5.tag == 1094u) {
        t1 = l5.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t1)->f_value;
        if (l7.tag == 1104u) {
            l13 = l7.payload.obj;
            vader_vm$string_constant(l0, l3, l4, l13);
        } else {
            vader_vm$push_constant(l3, l7);
        }
        l8 = vader_vm$operand(l3, INT64_C(1));
        vader_vm$emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1001u) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_import_ids;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
        t2 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l8, 499u);
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
        vader_vm$emit(l3, l4, INT32_C(121), l9, l8, INT32_C(0));
        t6 = vader_core_bytecode$bc_single_result(l13);
        if (t6 != INT32_C(14)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 1010u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
        vader_vm$emit(l3, l4, INT32_C(127), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1009u) {
        vader_vm$flush(l3, l4);
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t1)->f_count;
        vader_vm$emit(l3, l4, INT32_C(128), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1028u) {
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts;
        l14 = (void*) vader_buffer_new((size_t) INT64_C(87));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l14, l6, 2112u);
        l6 = std_core$write_int(l14, l6, l4);
        l6 = std_core$write_string_at(l14, l6, 532u);
        l21 = std_core$finish_buffer(l14, l6);
        vader_array_push_scalar((vader_array_t*) l13, vader_box_string(494u, l21));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm$emit(l3, l4, INT32_C(126), l8, INT32_C(0), INT32_C(0));
        l6 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm$canonical(l3, l6);
        vader_vm$push_register(l3, l8);
    } else if (l5.tag == 1126u) {
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts;
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t1)->f_reason;
        l21 = concat_2(2617u, l21);
        vader_array_push_scalar((vader_array_t*) l13, vader_box_string(494u, l21));
        t0 = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts)->length;
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm$emit(l3, l4, INT32_C(126), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1081u) {
        l6 = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack)->length;
        l8 = vader_vm$canonical(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t1)->f_slot;
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$LocalField_t*) t1)->f_field_index;
        vader_vm$emit(l3, l4, INT32_C(111), l8, l9, l10);
        vader_vm$push_register(l3, l8);
    } else if ((l5.tag == 1107u || l5.tag == 1124u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_field_index, l5.payload.obj);
        vader_vm$emit(l3, l4, INT32_C(111), l9, l8, l10);
        vader_vm$push_register(l3, l9);
    } else if ((l5.tag == 1109u || l5.tag == 1125u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        vader_vm$pop_to(l3, INT64_C(2));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructSet_t, f_field_index, l5.payload.obj);
        vader_vm$emit(l3, l4, INT32_C(112), l9, l8, l10);
    } else if ((l5.tag == 954u || l5.tag == 1077u || l5.tag == 1078u || l5.tag == 1079u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$pop_to(l3, INT64_C(2));
        if (l5.tag == 954u) {
            l11 = INT32_C(114);
        } else {
            l11 = INT32_C(116);
        }
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
        vader_vm$push_register(l3, l10);
    } else if ((l5.tag == 962u || l5.tag == 1099u || l5.tag == 1100u || l5.tag == 1101u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$operand(l3, INT64_C(3));
        vader_vm$pop_to(l3, INT64_C(3));
        if (l5.tag == 962u) {
            l11 = INT32_C(115);
        } else {
            l11 = INT32_C(117);
        }
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
    } else if (l5.tag == 955u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        vader_vm$emit(l3, l4, INT32_C(118), l9, l8, INT32_C(0));
        vader_vm$push_register(l3, l9);
    } else if (l5.tag == 957u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        vader_vm$pop_to(l3, INT64_C(2));
        vader_vm$emit(l3, l4, INT32_C(119), l9, l8, INT32_C(0));
    } else if (l5.tag == 1104u) {
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
    int64_t l6, l10, l12;
    vader_box_t l7, l13;
    int32_t l9;
    int64_t t0;
    void* t1;
    uint8_t t2;
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
    l7 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_raw;
    if (l7.tag == 0u) {
        if ((l9 < INT32_C(0))) {
            return false;
        }
        l10 = ((int64_t) (int32_t) l9);
        l12 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements)->length;
        if (!((l10 >= l12))) {
            l12 = ((int64_t) (int32_t) l2);
            l12 = vader_chk_add(i64, l1, l12);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            l13 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l9];
            vader_vm$set_register(l0, l12, l13);
            return true;
        }
        return false;
    }
    if ((l9 < INT32_C(0))) {
        return false;
    }
    l6 = ((int64_t) (int32_t) l9);
    t1 = l7.payload.obj;
    l10 = ((vader_struct_vader_vm$StringWindow_t*) t1)->f_length;
    if (!((l6 >= l10))) {
        l5 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        l8 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags;
        l11 = l7.payload.obj;
        l6 = ((int64_t) (int32_t) l9);
        t2 = vader_vm$byte_at(l11, l6);
        l9 = ((int32_t) (uint8_t) t2);
        vader_vm$set_i32(l5, l8, l1, l2, l9);
        return true;
    }
    return false;
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
    if (((vader_struct_vader_vm$ArrayVal_t*) l5)->f_raw.tag == 0u) {
        if ((l9 < INT32_C(0))) {
            return false;
        }
        l6 = ((int64_t) (int32_t) l9);
        l10 = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements)->length;
        if (!((l6 >= l10))) {
            l5 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements;
            l6 = ((int64_t) (int32_t) l4);
            l6 = vader_chk_add(i64, l1, l6);
            l7 = vader_vm$register_value(l0, l6);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l9] = l7;
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            return true;
        }
        return false;
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
    if (l5.tag == 975u) {
        t0 = l5.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
        l6 = vader_vm$class_matches(l1, l7);
        return l6;
    }
    if (l5.tag == 978u) {
        if (l1.tag == 1713u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 965u) {
        if (l1.tag == 1681u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 979u) {
        t0 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l6 = vader_vm$union_matches(l0, l1, l8);
    } else if (l5.tag == 974u) {
        t0 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
        l6 = vader_vm$ref_type_matches(l0, l1, l9);
    } else {
        if (!(l5.tag == 968u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = false;
    }
    return l6;
}

static int32_t vader_vm$type_operand(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1110u)) {
        return INT32_C(0);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
    return t1;
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
        if (l4.tag == 975u) {
            t1 = l4.payload.obj;
            l5 = vader_vm$tags_of_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val);
            return l5;
        }
        if ((l4.tag == 965u || l4.tag == 968u || l4.tag == 978u)) {
            l5 = (uint8_t) 64;
        } else if (l4.tag == 974u) {
            l5 = (uint8_t) 127;
        } else {
            if (!(l4.tag == 979u)) {
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

static vader_box_t vader_vm$unary_op(void* l0, vader_box_t l1, void* l2, int64_t l3) {
    uint8_t l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    int32_t l7;
    int32_t t0;
    void* t1 = NULL;
    uint8_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l5, &t4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (((INT32_C(1) | INT32_C(2)) | INT32_C(16)) | INT32_C(8));
    l4 = (uint8_t) (int32_t) t0;
    if (l1.tag == 1047u) {
        l5 = vader_box_i32(497u, INT32_C(13));
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1034u) {
        l5 = vader_box_i32(497u, INT32_C(14));
    } else if (l1.tag == 1067u) {
        l5 = vader_box_i32(497u, INT32_C(38));
    } else if (l1.tag == 1054u) {
        l5 = vader_box_i32(497u, INT32_C(39));
    } else if (l1.tag == 1025u) {
        l5 = vader_box_i32(497u, INT32_C(56));
    } else if (l1.tag == 1005u) {
        t1 = l1.payload.obj;
        t0 = vader_vm$checked_neg_register_op(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t1)->f_kind);
        l5 = vader_box_i32(497u, t0);
    } else if (l1.tag == 991u) {
        t2 = vader_vm$stack_tags(l2, l3, INT64_C(1));
        t3 = vader_vm$tags_within(t2, (uint8_t) 8);
        if (t3) {
            l5 = vader_box_i32(497u, INT32_C(67));
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l1.tag == 1110u) {
        l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        t1 = l1.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t1)->f_type_id;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        if (t4.tag == 978u) {
            l5 = vader_box_i32(497u, INT32_C(113));
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l1.tag == 1006u) {
        t2 = vader_vm$stack_tags(l2, l3, INT64_C(1));
        t3 = vader_vm$tags_within(t2, l4);
        if (t3) {
            t1 = l1.payload.obj;
            if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(0)) {
                l5 = vader_box_i32(497u, INT32_C(83));
            } else {
                t1 = l1.payload.obj;
                if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(1)) {
                    t1 = l1.payload.obj;
                    t5 = ((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_from_name;
                    t0 = vader_vm$widening(t5);
                    l5 = vader_box_i32(497u, t0);
                } else {
                    t1 = l1.payload.obj;
                    if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(3)) {
                        l5 = vader_box_i32(497u, INT32_C(86));
                    } else {
                        l5 = vader_box_obj(0u, NULL);
                    }
                }
            }
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else {
        l5 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
        { vader_gc_top = gc_frame.prev; return 1818u; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_std_ffi$CLibrary_t*) l1)->f_name;
    t0 = concat_3(1816u, l3, 1087u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$unwind(void* l0, void* l1, void* l2, bool l3) {
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
            l8 = vader_vm$defer_thunk(l0, l7, INT32_C(0), 2571u);
            if (l8.tag == 1716u) {
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
        return vader_box_i32(497u, ((int32_t) (int64_t) (l1 & INT64_C(255))));
    }
    if (l0 == INT32_C(5)) {
        t0 = (l1 & INT64_C(255));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(128))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(256));
            return vader_box_i32(497u, t1);
        }
        return vader_box_i32(497u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(12)) {
        return vader_box_bool(492u, l1 != INT64_C(0));
    }
    if (l0 == INT32_C(2)) {
        return vader_box_i32(497u, ((int32_t) (int64_t) (l1 & INT64_C(65535))));
    }
    if (l0 == INT32_C(6)) {
        t0 = (l1 & INT64_C(65535));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(32768))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(65536));
            return vader_box_i32(497u, t1);
        }
        return vader_box_i32(497u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(3)) {
        return vader_box_i32(497u, ((int32_t) (uint64_t) l1));
    }
    if (l0 == INT32_C(7)) {
        return vader_box_i32(497u, ((int32_t) (uint64_t) l1));
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
                return vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l3));
            }
        } else {
            return vader_box_i32(493u, (int32_t) ((uint32_t) (uint32_t) l3));
        }
    } else {
        if (l0 == INT32_C(4)) {
            return vader_box_i64(498u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(8)) {
            return vader_box_i64(498u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(9)) {
            return vader_box_f64(504u, ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
        }
        if (!(l0 == INT32_C(10))) {
            return vader_box_i32(497u, INT32_C(0));
        }
        return vader_box_f64(504u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
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
    if (l0.tag == 1696u) {
        l2 = l1.tag == 1696u;
        return l2;
    }
    if (l0.tag == 497u) {
        if (l1.tag == 497u) {
            l3 = ((int32_t) l0.payload.i);
            l4 = ((int32_t) l1.payload.i);
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 492u) {
        if (l1.tag == 492u) {
            l5 = l0.payload.b;
            l6 = l1.payload.b;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 493u) {
        if (l1.tag == 493u) {
            l7 = ((uint32_t) l0.payload.i);
            l8 = ((uint32_t) l1.payload.i);
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 494u) {
        if (l1.tag == 494u) {
            l9 = l0.payload.s;
            l10 = l1.payload.s;
            l2 = l9 == l10;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 498u) {
        if (l1.tag == 498u) {
            l11 = ((int64_t) l0.payload.i);
            l12 = ((int64_t) l1.payload.i);
            l2 = l11 == l12;
        } else {
            l2 = false;
        }
    } else if ((l0.tag == 503u || l0.tag == 504u)) {
        if ((l1.tag == 503u || l1.tag == 504u)) {
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
        if (!((l0.tag == 1681u || l0.tag == 1686u || l0.tag == 1697u || l0.tag == 1713u || l0.tag == 1717u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if ((l1.tag == 1681u || l1.tag == 1686u || l1.tag == 1697u || l1.tag == 1713u || l1.tag == 1717u)) {
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
        { vader_box_t __vret = vader_box_i64(498u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = INT64_C(0);
    l4 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature);
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 8u, 498u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) INT64_C(0);
    vader_array_t* _a3_arr = vader_array_new(28u, 1u, 8u, 498u);
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
                l14 = concat_3(1087u, l13, 1269u);
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
                l19 = std_core$write_string_at(l18, l19, 1087u);
                l19 = std_core$write_string_at(l18, l19, l16);
                l19 = std_core$write_string_at(l18, l19, 1271u);
                l20 = ((vader_struct_vader_vm$StackEffect_t*) l11)->f_pops;
                l19 = std_core$write_int(l18, l19, l20);
                l19 = std_core$write_string_at(l18, l19, 241u);
                l19 = std_core$write_int(l18, l19, l9);
                l21 = std_core$finish_buffer(l18, l19);
                t0 = vader_vm$defect(l1, l7, l21);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l10.tag == 1093u) {
                if (l9 != l4) {
                    l22 = (void*) vader_buffer_new((size_t) INT64_C(87));
                    l23 = INT64_C(0);
                    l23 = std_core$write_string_at(l22, l23, 1464u);
                    l23 = std_core$write_int(l22, l23, l4);
                    l23 = std_core$write_string_at(l22, l23, 241u);
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
                l37 = concat_3(1087u, l36, 1170u);
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
    { vader_box_t __vret = vader_box_i64(498u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$verify_module(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l7;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 8u, 498u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l6 = vader_vm$verify_function(l0, l5);
        if (l6.tag == 1719u) {
            t1 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((int64_t) l6.payload.i);
        vader_array_push_i64((vader_array_t*) l1, l7);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$view_of(void* l0, int32_t l1, int64_t l2, int64_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l9 = NULL;
    vader_string_t l6 = 0;
    int64_t l7, l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l5, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l4.tag == 0u)) {
        l5 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements;
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_vm$StringWindow_t*) t0)->f_text;
        t0 = l4.payload.obj;
        t1 = ((vader_struct_vader_vm$StringWindow_t*) t0)->f_offset;
        l7 = vader_chk_add(i64, t1, l2);
        l8 = vader_chk_sub(i64, l3, l2);
        vader_struct_vader_vm$StringWindow_t* _a0_obj = (vader_struct_vader_vm$StringWindow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StringWindow_t));
        vader_obj_header_init(_a0_obj, 1712u);
        _a0_obj->f_text = l6;
        _a0_obj->f_offset = l7;
        _a0_obj->f_length = l8;
        l9 = (void*) _a0_obj;
        vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
        vader_obj_header_init(_a1_obj, 1681u);
        _a1_obj->f_type_id = l1;
        _a1_obj->f_elements = l5;
        _a1_obj->f_raw = vader_ref_box(l9);
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements, (int64_t) l2, (int64_t) l3);
    l5 = (void*) _a2_arr;
    vader_struct_vader_vm$ArrayVal_t* _a3_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a3_obj, 1681u);
    _a3_obj->f_type_id = l1;
    _a3_obj->f_elements = l5;
    _a3_obj->f_raw = vader_box_obj(0u, NULL);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$void_result(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_169;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a1_obj, 1693u);
    _a1_obj->f_value = vader_ref_box(t0);
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l12, 499u);
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
                    t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l16, 499u);
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
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 499u);
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
    return vader_box_i32(497u, INT32_C(0));
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
    vader_array_t* _a0_arr = vader_array_new(414u, 0u, 0u, 2456u);
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
    vader_obj_header_init(_a2_obj, 1713u);
    _a2_obj->f_type_id = l0;
    _a2_obj->f_fields = l4;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
