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
static vader_string_t vader_vm$VoidVal$std_core$Display$to_string(void* l0);
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
static int64_t vader_vm$at_width(int64_t l0, int64_t l1, bool l2);
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
static int32_t vader_vm$debugged_thread_id(int64_t l0);
static void* vader_vm$debugged_threads(void* l0);
static vader_box_t vader_vm$deep_copy_value(void* l0, vader_box_t l1, int32_t l2);
static void* vader_vm$defect(void* l0, int64_t l1, vader_string_t l2);
static vader_box_t vader_vm$defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3);
static vader_string_t vader_vm$describe_obj(void* l0);
static vader_string_t vader_vm$describe_value_tag(vader_box_t l0);
static vader_box_t vader_vm$dispatch_extern(void* l0, int32_t l1, void* l2, int64_t l3, int32_t l4);
static vader_box_t vader_vm$dispatch_import(void* l0, void* l1, int64_t l2, void* l3, int32_t l4, int32_t l5, int32_t l6, bool l7, uint8_t l8);
static vader_string_t vader_vm$display_tags(uint8_t l0);
static vader_string_t vader_vm$display_value(vader_box_t l0);
static vader_box_t vader_vm$do_memory_copy(void* l0);
static void vader_vm$drop_last_op(void* l0);
static vader_string_t vader_vm$element_label(int32_t l0);
static uint8_t vader_vm$element_tags(void* l0, int32_t l1);
static void* vader_vm$element_trap(void* l0, int64_t l1, int32_t l2, int32_t l3, void* l4, int64_t l5, int32_t l6);
static void vader_vm$emit(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static void* vader_vm$empty_machine(vader_box_t l0);
static void vader_vm$enter_frame(void* l0, void* l1, int64_t l2);
static vader_box_t vader_vm$entry_args(void* l0, void* l1, vader_box_t l2, int32_t l3);
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
static int32_t vader_vm$find_u8_array_type_id(void* l0);
static void* vader_vm$finish_guest_threads(bool l0, vader_box_t l1);
static vader_box_t vader_vm$finish_run(void* l0, bool l1, vader_box_t l2);
static void* vader_vm$first_bytes(void* l0, int64_t l1);
static bool vader_vm$fits_signed(int32_t l0, int64_t l1);
static uint64_t vader_vm$float_bits(double l0, int64_t l1);
static vader_box_t vader_vm$flow_to(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5, int64_t l6);
static void vader_vm$flush(void* l0, int64_t l1);
static void* vader_vm$fn_index_trap(int32_t l0, int32_t l1, vader_string_t l2);
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
static void* vader_vm$indirect_call_trap(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4);
static void* vader_vm$infer_function_tags(void* l0, void* l1, int64_t l2);
static void* vader_vm$infer_module_tags(void* l0, void* l1);
static void* vader_vm$initial_globals(void* l0);
static bool vader_vm$inlinable_op(vader_box_t l0);
static void* vader_vm$inline_into(void* l0, void* l1, int64_t l2);
static void* vader_vm$inline_leaf_calls(void* l0);
static uint8_t vader_vm$integer_operand_tags(uint8_t l0);
static uint8_t vader_vm$integer_tags(uint8_t l0);
static bool vader_vm$is_boxed(vader_box_t l0);
static bool vader_vm$is_covered_variadic(int64_t l0, int64_t l1, int64_t l2);
static bool vader_vm$is_fn_index_out_of_range(int32_t l0, void* l1);
static bool vader_vm$is_i32_tag(uint8_t l0);
static bool vader_vm$is_inline_leaf(void* l0);
static bool vader_vm$is_integer_alias(uint8_t l0);
static bool vader_vm$is_lendable_element(uint8_t l0);
static bool vader_vm$is_overflow_trap_message(vader_string_t l0);
static bool vader_vm$is_source_local(vader_string_t l0);
static bool vader_vm$is_unsigned_source(vader_string_t l0);
static void vader_vm$jump(void* l0, int64_t l1, int32_t l2, int32_t l3, int32_t l4, int32_t l5);
static vader_box_t vader_vm$lent_element_val_type(void* l0, int32_t l1);
static vader_box_t vader_vm$lent_word(vader_box_t l0, int64_t l1, int32_t l2, vader_string_t l3, vader_string_t l4);
static bool vader_vm$line_has_breakpoint(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_vm$load_bytes_op(void* l0, int64_t l1, vader_string_t l2);
static int32_t vader_vm$lookup_vtable_row(void* l0, int32_t l1, int32_t l2);
static void* vader_vm$main_thread(void* l0);
static void vader_vm$materialise(void* l0, int64_t l1, int64_t l2);
static vader_box_t vader_vm$merge(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, int64_t l5);
static void vader_vm$merge_block(void* l0, int64_t l1, int64_t l2, void* l3);
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
static vader_box_t vader_vm$reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6, vader_box_t l7);
static vader_box_t vader_vm$register_value(void* l0, int64_t l1);
static vader_box_t vader_vm$relocated(vader_box_t l0, int32_t l1);
static void vader_vm$reserve_registers(void* l0, int64_t l1);
static void vader_vm$reserve_stack(void* l0, int64_t l1);
static void vader_vm$reset_stack(void* l0, int64_t l1);
static vader_box_t vader_vm$resolve_virtual(void* l0, void* l1, void* l2, int64_t l3, int64_t l4);
static void vader_vm$restore(void* l0);
static void vader_vm$return_many(void* l0, int64_t l1, void* l2);
static vader_box_t vader_vm$retyped_int(vader_box_t l0, int64_t l1);
static vader_box_t vader_vm$run_boxed(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, bool l5);
static vader_box_t vader_vm$run_defers(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm$run_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5, vader_box_t l6);
static vader_box_t vader_vm$run_for_value(void* l0, vader_string_t l1, bool l2);
static vader_box_t vader_vm$run_thunk(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7);
static vader_box_t vader_vm$scalar_of(vader_box_t l0);
static vader_box_t vader_vm$scalar_value(uint8_t l0, int64_t l1);
static void* vader_vm$scratch_frame(void);
static vader_box_t vader_vm$serialise_mirror(void* l0, int64_t l1, void* l2, void* l3, void* l4, int32_t l5, vader_string_t l6, int32_t l7);
static vader_box_t vader_vm$serve_import(void* l0, void* l1, int32_t l2, void* l3, void* l4, int32_t l5, bool l6);
static vader_box_t vader_vm$serve_is_leaving(vader_box_t l0, int32_t l1);
static vader_box_t vader_vm$serve_program_stream(void* l0, void* l1, void* l2, int64_t l3, int32_t l4);
static vader_box_t vader_vm$serve_read(void* l0, void* l1, int64_t l2, int32_t l3);
static vader_box_t vader_vm$serve_thread_primitive(void* l0, void* l1, uint8_t l2, void* l3, int32_t l4, bool l5);
static vader_box_t vader_vm$serve_wait_readable(void* l0, vader_box_t l1, int32_t l2);
static vader_box_t vader_vm$serve_wait_readable_for(void* l0, void* l1, int32_t l2, bool l3);
static vader_box_t vader_vm$serve_wait_writable_for(void* l0, int32_t l1, bool l2);
static vader_box_t vader_vm$serve_write(void* l0, uint8_t l1, void* l2, void* l3, int64_t l4, int32_t l5);
static bool vader_vm$serves_stdin(void* l0, int64_t l1);
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
static vader_box_t vader_vm$start_guest_thread(void* l0, void* l1, int32_t l2, bool l3, vader_box_t l4);
static int64_t vader_vm$std_descriptor(int64_t l0);
static bool vader_vm$step_should_stop(uint8_t l0, int32_t l1, int32_t l2);
static void vader_vm$stop_at_line(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5);
static vader_box_t vader_vm$store_bytes_op(void* l0, int64_t l1, uint64_t l2, vader_string_t l3);
static void vader_vm$store_slot(void* l0, void* l1, int64_t l2, int32_t l3, bool l4, int64_t l5);
static vader_box_t vader_vm$stream_of(int64_t l0);
static void* vader_vm$string_array_to_value(void* l0, int32_t l1);
static vader_box_t vader_vm$string_at(void* l0, int64_t l1);
static bool vader_vm$string_byte_at(void* l0, int64_t l1);
static bool vader_vm$string_byte_slice(void* l0, int64_t l1);
static void vader_vm$string_constant(void* l0, void* l1, int64_t l2, void* l3);
static bool vader_vm$string_import_op(void* l0, int64_t l1, uint8_t l2);
static vader_box_t vader_vm$struct_at(void* l0, int64_t l1);
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
static void vader_vm$void_constant(void* l0, int64_t l1);
static vader_box_t vader_vm$void_result(void);
static int32_t vader_vm$vtable_row_of(void* l0, vader_string_t l1);
static void vader_vm$walk_block(void* l0, void* l1, void* l2, int64_t l3, int64_t l4, void* l5, vader_box_t l6);
static int32_t vader_vm$widening(vader_string_t l0);
static int64_t vader_vm$word_of_class(int64_t l0, uint8_t l1);
static void vader_vm$write_float(void* l0, int64_t l1, double l2, int64_t l3);
static void vader_vm$write_little_endian(void* l0, int64_t l1, int64_t l2, int64_t l3);
static vader_box_t vader_vm$written_scalar(void* l0, int64_t l1, int64_t l2, uint8_t l3);
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
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 1221u);
    l2 = INT64_C(0);
    l3 = vader_vm$element_count(l0);
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string__builder$append(l1, 444u);
        }
        t1 = vader_vm$element_at(l0, l2);
        l4 = vader_vm$display_value(t1);
        std_string__builder$append(l1, l4);
        l2 = (l2 + INT64_C(1));
    }
    std_string__builder$append(l1, 1237u);
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$BoolVal$std_core$Display$to_string(bool l0) {
    if (l0) {
        return 3379u;
    }
    return 2502u;
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
        l2 = std_core$write_string_at(l1, l2, 617u);
        t0 = ((vader_struct_vader_vm$FnVal_t*) l0)->f_function_index;
        l3 = ((int64_t) (int32_t) t0);
        l2 = std_core$write_int(l1, l2, l3);
        l2 = std_core$write_string_at(l1, l2, 632u);
        t1 = std_core$finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 617u);
    t0 = ((vader_struct_vader_vm$FnVal_t*) l0)->f_function_index;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 441u);
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
    return 3004u;
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
    if (l1.tag == 2122u) {
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
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l3 = INT64_C(0);
    t1 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
    l4 = ((int64_t) (int32_t) t1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3775u);
    l5 = std_core$finish_buffer(l2, l3);
    std_string__builder$append(l1, l5);
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields));
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l1, 444u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l3];
        l5 = vader_vm$display_value(t2);
        std_string__builder$append(l1, l5);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append(l1, 312u);
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
    l2 = std_core$write_string_at(l1, l2, 624u);
    t0 = ((vader_struct_vader_vm$TypeVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 632u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$VoidVal$std_core$Display$to_string(void* l0) {
    return 3699u;
}

static vader_box_t vader_vm$accepted_tags(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    void* t0;
    uint8_t t1;
    if ((l0.tag == 1340u || l0.tag == 1341u || l0.tag == 1343u || l0.tag == 1344u || l0.tag == 1346u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1350u || l0.tag == 1351u || l0.tag == 1352u || l0.tag == 1353u || l0.tag == 1356u || l0.tag == 1357u || l0.tag == 1358u || l0.tag == 1359u || l0.tag == 1422u || l0.tag == 1423u || l0.tag == 1424u || l0.tag == 1425u || l0.tag == 1426u || l0.tag == 1427u)) {
        l2 = vader_box_i32(628u, INT32_C(19));
        return l2;
    }
    if ((l0.tag == 1342u || l0.tag == 1355u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(628u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 1347u || l0.tag == 1354u)) {
        l2 = vader_box_i32(628u, (INT32_C(19) | INT32_C(32)));
    } else if ((l0.tag == 1360u || l0.tag == 1361u || l0.tag == 1363u || l0.tag == 1364u || l0.tag == 1366u || l0.tag == 1367u || l0.tag == 1368u || l0.tag == 1369u || l0.tag == 1370u || l0.tag == 1371u || l0.tag == 1372u || l0.tag == 1373u || l0.tag == 1374u || l0.tag == 1376u || l0.tag == 1377u || l0.tag == 1378u || l0.tag == 1379u || l0.tag == 1428u || l0.tag == 1429u || l0.tag == 1430u || l0.tag == 1431u || l0.tag == 1432u || l0.tag == 1433u)) {
        l2 = vader_box_i32(628u, INT32_C(3));
    } else if ((l0.tag == 1362u || l0.tag == 1375u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(628u, INT32_C(3));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 1323u || l0.tag == 1325u || l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1334u)) {
        l2 = vader_box_i32(628u, INT32_C(4));
    } else if (l0.tag == 1333u) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(628u, INT32_C(4));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1312u) {
        t0 = l0.payload.obj;
        t1 = vader_vm$integer_operand_tags(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        l2 = vader_box_i32(628u, (int32_t)(uint32_t) t1);
    } else if (l0.tag == 1313u) {
        if (l1 == INT64_C(1)) {
            t0 = l0.payload.obj;
            t1 = vader_vm$integer_operand_tags(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
            l2 = vader_box_i32(628u, (int32_t)(uint32_t) t1);
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 1262u || l0.tag == 1385u || l0.tag == 1386u || l0.tag == 1387u)) {
        if (l1 == INT64_C(1)) {
            l2 = vader_box_i32(628u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else if ((l0.tag == 1270u || l0.tag == 1409u || l0.tag == 1410u || l0.tag == 1411u)) {
        if (l1 == INT64_C(2)) {
            l2 = vader_box_i32(628u, INT32_C(19));
        } else {
            l2 = vader_box_obj(0u, NULL);
        }
    } else {
        if (!((l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1263u || l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1271u || l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1294u || l0.tag == 1295u || l0.tag == 1296u || l0.tag == 1297u || l0.tag == 1298u || l0.tag == 1299u || l0.tag == 1300u || l0.tag == 1301u || l0.tag == 1302u || l0.tag == 1303u || l0.tag == 1304u || l0.tag == 1305u || l0.tag == 1308u || l0.tag == 1309u || l0.tag == 1310u || l0.tag == 1311u || l0.tag == 1314u || l0.tag == 1315u || l0.tag == 1317u || l0.tag == 1318u || l0.tag == 1319u || l0.tag == 1320u || l0.tag == 1321u || l0.tag == 1322u || l0.tag == 1324u || l0.tag == 1335u || l0.tag == 1336u || l0.tag == 1337u || l0.tag == 1338u || l0.tag == 1339u || l0.tag == 1345u || l0.tag == 1365u || l0.tag == 1380u || l0.tag == 1382u || l0.tag == 1383u || l0.tag == 1384u || l0.tag == 1388u || l0.tag == 1389u || l0.tag == 1390u || l0.tag == 1391u || l0.tag == 1392u || l0.tag == 1393u || l0.tag == 1394u || l0.tag == 1396u || l0.tag == 1397u || l0.tag == 1398u || l0.tag == 1399u || l0.tag == 1400u || l0.tag == 1401u || l0.tag == 1402u || l0.tag == 1403u || l0.tag == 1404u || l0.tag == 1406u || l0.tag == 1407u || l0.tag == 1408u || l0.tag == 1412u || l0.tag == 1413u || l0.tag == 1414u || l0.tag == 1415u || l0.tag == 1416u || l0.tag == 1417u || l0.tag == 1418u || l0.tag == 1419u || l0.tag == 1420u || l0.tag == 1421u || l0.tag == 1434u || l0.tag == 1435u || l0.tag == 1436u || l0.tag == 1437u || l0.tag == 1438u))) {
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
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_adapters));
    if (!((l2 >= l3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_adapters);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
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
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_std_core$CLibrary_t*) t0)->f_archives));
        if ((t1 > INT64_C(0))) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_std_core$CLibrary_t*) t0)->f_name;
            t2 = concat_3(2799u, l3, 1590u);
            { vader_box_t __vret = vader_box_string(623u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params));
    if ((t1 > INT64_C(8))) {
        { vader_box_t __vret = vader_box_string(623u, 2793u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = INT64_C(0);
    l6 = INT64_C(0);
    l7 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params));
    while ((l7 < l8)) {
        l9 = vader_core_bytecode$param_is_by_address(l4, l7);
        if (!(l9)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l10 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l7];
            t3 = vader_core_bytecode$mirror_at(l1, l10);
            if (!(t3.tag == 0u)) {
                l11 = (void*) vader_buffer_new((size_t) INT64_C(54));
                l12 = INT64_C(0);
                l12 = std_core$write_string_at(l11, l12, 2009u);
                l12 = std_core$write_int(l11, l12, l7);
                l12 = std_core$write_string_at(l11, l12, 256u);
                t2 = std_core$finish_buffer(l11, l12);
                { vader_box_t __vret = vader_box_string(623u, t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t3 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l7, 628u);
        if (((int32_t) t3.payload.i) == INT32_C(8)) {
            l13 = (void*) vader_buffer_new((size_t) INT64_C(41));
            l14 = INT64_C(0);
            l14 = std_core$write_string_at(l13, l14, 2009u);
            l14 = std_core$write_int(l13, l14, l7);
            l14 = std_core$write_string_at(l13, l14, 198u);
            t2 = std_core$finish_buffer(l13, l14);
            { vader_box_t __vret = vader_box_string(623u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t3 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l7, 628u);
        if (((int32_t) t3.payload.i) == INT32_C(11)) {
            l15 = (void*) vader_buffer_new((size_t) INT64_C(41));
            l16 = INT64_C(0);
            l16 = std_core$write_string_at(l15, l16, 2009u);
            l16 = std_core$write_int(l15, l16, l7);
            l16 = std_core$write_string_at(l15, l16, 193u);
            t2 = std_core$finish_buffer(l15, l16);
            { vader_box_t __vret = vader_box_string(623u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t3 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l7, 628u);
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
        { vader_box_t __vret = vader_box_string(623u, 2790u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l18 == INT32_C(8)) {
        { vader_box_t __vret = vader_box_string(623u, 2791u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l6 > INT64_C(0))) {
        if ((l5 > INT64_C(0))) {
            { vader_box_t __vret = vader_box_string(623u, 2788u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if ((l6 > INT64_C(2))) {
        { vader_box_t __vret = vader_box_string(623u, 2794u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT64_C(0)) {
        if (l18 == INT32_C(9)) {
            { vader_box_t __vret = vader_box_string(623u, 2792u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if ((l6 > INT64_C(0))) {
        if (l18 != INT32_C(9)) {
            { vader_box_t __vret = vader_box_string(623u, 2800u); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
    if ((t4 >= INT32_C(0))) {
        t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_variadic_fixed;
        l5 = ((int64_t) (int32_t) t4);
        l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params));
        t5 = vader_vm$is_covered_variadic(l5, l7, l6);
        if (!(t5)) {
            { vader_box_t __vret = vader_box_string(623u, 2806u); vader_gc_top = gc_frame.prev; return __vret; }
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
    l6 = vader_array_length(((vader_array_t*) l1));
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
    t0 = vader_array_length(((vader_array_t*) l2));
    if (t0 == INT64_C(0)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 2110u) {
        t0 = vader_array_length(((vader_array_t*) l2));
        vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
        l3 = (void*) _a0_arr;
        l4 = vader_array_length(((vader_array_t*) l2));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
            l6 = __lambda_vader_vm_5(t0);
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l6));
            l5 = (l5 + INT64_C(1));
        }
        t1 = std_string$join(l3, 444u);
        t2 = concat_4(t1, 276u, l1, 266u);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 2128u);
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
    l4 = std_core$write_string_at(l3, l4, 3512u);
    l4 = std_core$write_int(l3, l4, l0);
    l4 = std_core$write_string_at(l3, l4, 277u);
    l2 = std_core$finish_buffer(l3, l4);
    if (l1.tag == 0u) {
        std_console$eprintln__string(l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_vm$ProgramIo_t*) t0)->f_write;
    l2 = concat_2(l2, 1u);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
    ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(628u, INT32_C(1)), vader_box_string(623u, l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$apply_boxed(void* l0, void* l1, vader_box_t l2, void* l3, vader_string_t l4, bool l5) {
    int32_t l6, l7;
    void* l8 = NULL;
    int64_t l9, l16;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l14 = vader_box_null();
    uint8_t l12;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    bool l17, l18;
    uint64_t l19;
    double l20;
    void* t0 = NULL;
    int64_t t1, t6;
    int32_t t2;
    bool t3;
    vader_string_t t4 = 0;
    vader_box_t t5 = vader_box_null();
    double t7;
    vader_box_t* gc_roots[5] = { &l2, &l10, &l11, &l14, &t5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l13, &l15, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1337u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        vader_struct_vader_vm$FnVal_t* _a0_obj = (vader_struct_vader_vm$FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FnVal_t));
        vader_obj_header_init(_a0_obj, 2098u);
        _a0_obj->f_type_id = l6;
        _a0_obj->f_function_index = l7;
        _a0_obj->f_env = vader_box_obj(0u, NULL);
        l8 = (void*) _a0_obj;
        l9 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        vader_vm$push_val(l3, l9, vader_ref_box(l8));
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_add(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1394u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_owned(l3, l9);
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        vader_struct_vader_vm$FnVal_t* _a1_obj = (vader_struct_vader_vm$FnVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FnVal_t));
        vader_obj_header_init(_a1_obj, 2098u);
        _a1_obj->f_type_id = l6;
        _a1_obj->f_function_index = l7;
        _a1_obj->f_env = l10;
        l8 = (void*) _a1_obj;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_vm$push_val(l3, l9, vader_ref_box(l8));
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1418u) {
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l10 = vader_vm$build_struct(l8, l6, l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1264u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l10 = vader_vm$build_array(l6, l7, l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1271u) {
        l8 = l2.payload.obj;
        l10 = vader_vm$exec_array_slice(l3, l8);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1269u) {
        l8 = l2.payload.obj;
        l10 = vader_vm$exec_array_reserve(l3, l8);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1268u) {
        l10 = vader_vm$exec_array_repeat(l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1266u) {
        l10 = vader_vm$exec_array_push_all(l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1261u) {
        l10 = vader_vm$exec_array_copy(l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1267u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$peek_array_mut(l3, l9, l6, 2038u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l10.payload.obj;
        if (!(((vader_struct_vader_vm$ArrayVal_t*) l8)->f_raw.tag == 0u)) {
            vader_vm$own_bytes(l8);
        }
        l10 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l8)->f_elements);
        if (l10.tag == 0u) {
            l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l9 = vader_chk_sub(i64, t1, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            ((uint8_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l9] = (uint8_t) INT32_C(5);
        } else {
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l9 = vader_chk_sub(i64, t1, INT64_C(1));
            vader_vm$push_val(l3, l9, l10);
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1260u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$peek_array_mut(l3, l9, l6, 2020u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l10.payload.obj;
        ((vader_struct_vader_vm$ArrayVal_t*) l8)->f_raw = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_vm$ArrayVal_t*) l8);
        vader_array_clear((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l8)->f_elements);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1338u) {
        if (l5) {
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
            t0 = vader_vm$global_at_comptime_trap(l0, l6);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l8 = ((vader_struct_vader_vm$VmState_t*) l0)->f_globals;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l10 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l6];
        vader_vm$push_val(l3, l9, l10);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_add(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1339u) {
        if (l5) {
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
            t0 = vader_vm$global_at_comptime_trap(l0, l6);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((vader_struct_vader_vm$VmState_t*) l0)->f_globals;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_owned(l3, l9);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l6] = l10;
        VADER_WRITE_BARRIER(_a4_slotarr->buf);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1315u) {
        l8 = ((vader_struct_vader_vm$VmState_t*) l0)->f_data_pool;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        l6 = ((vader_struct_vader_vm$ArrayVal_t*) l8)->f_type_id;
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        if (l6 == l7) {
            l9 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            vader_vm$push_val(l3, l9, vader_ref_box(l8));
        } else {
            l9 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
            l8 = ((vader_struct_vader_vm$ArrayVal_t*) l8)->f_elements;
            vader_struct_vader_vm$ArrayVal_t* _a6_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
            vader_obj_header_init(_a6_obj, 2093u);
            _a6_obj->f_type_id = l6;
            _a6_obj->f_elements = l8;
            _a6_obj->f_raw = vader_box_obj(0u, NULL);
            l8 = (void*) _a6_obj;
            vader_vm$push_val(l3, l9, vader_ref_box(l8));
        }
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_add(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1314u) {
        t0 = l2.payload.obj;
        l12 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t3 = vader_vm$convert_int_fast(l3, l12, l13);
        if (!(t3)) {
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l9 = vader_chk_sub(i64, t1, INT64_C(1));
            l10 = vader_vm$peek_val(l3, l9);
            t0 = l2.payload.obj;
            l12 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target;
            t0 = l2.payload.obj;
            l13 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
            l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l11 = vader_vm$convert_value(l10, l12, l13, l6);
            l14 = l11;
            if (l11.tag == 2128u) {
                t0 = l14.payload.obj;
                l13 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
                l15 = vader_vm$describe_value_tag(l10);
                t4 = concat_6(l13, 72u, l15, 410u, l4, 362u);
                vader_struct_vader_vm$Trap_t* _a7_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a7_obj, 2128u);
                _a7_obj->f_message = t4;
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = l11;
            t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
            l9 = vader_chk_sub(i64, t1, INT64_C(1));
            vader_vm$push_val(l3, l9, l10);
        }
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1404u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        if (!(l10.tag == 2129u)) {
            l13 = vader_vm$describe_value_tag(l10);
            l9 = vader_host_std_core$Intrinsic$byte_len(l13);
            l8 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l9));
            l9 = INT64_C(0);
            l9 = std_core$write_string_at(l8, l9, 2753u);
            l9 = std_core$write_string_at(l8, l9, l13);
            l9 = std_core$write_string_at(l8, l9, 130u);
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l16 = ((int64_t) (int32_t) t2);
            l9 = std_core$write_int(l8, l9, l16);
            t4 = std_core$finish_buffer(l8, l9);
            vader_struct_vader_vm$Trap_t* _a8_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a8_obj, 2128u);
            _a8_obj->f_message = t4;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l10.payload.obj;
        l6 = ((vader_struct_vader_vm$TypeVal_t*) t0)->f_type_id;
        if ((l6 < INT32_C(0))) {
            l17 = true;
        } else {
            l9 = ((int64_t) (int32_t) l6);
            l16 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types));
            l17 = (l9 >= l16);
        }
        if (l17) {
            l8 = (void*) vader_buffer_new((size_t) INT64_C(89));
            l9 = INT64_C(0);
            l9 = std_core$write_string_at(l8, l9, 2754u);
            l16 = ((int64_t) (int32_t) l6);
            l9 = std_core$write_int(l8, l9, l16);
            l9 = std_core$write_string_at(l8, l9, 247u);
            t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
            l16 = ((int64_t) (int32_t) t2);
            l9 = std_core$write_int(l8, l9, l16);
            t4 = std_core$finish_buffer(l8, l9);
            vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a9_obj, 2128u);
            _a9_obj->f_message = t4;
            t0 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
        t5 = vader_array_ref_load_box(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l6);
        l6 = vader_core_bytecode$size_of_bc_type(t5);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l16 = ((int64_t) (int32_t) l6);
        vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
        ((int64_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a12_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l9)
        ((uint8_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l9] = (uint8_t) INT32_C(1);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1347u) {
        l10 = vader_vm$apply_eq_binop(l3, 2644u, false);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1354u) {
        l10 = vader_vm$apply_eq_binop(l3, 2651u, true);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1297u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2094u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l17 = l10.payload.b;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2094u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = l10.payload.b;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l17 == l18) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a13_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l9)
        ((int64_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a14_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l9)
        ((uint8_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1298u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2095u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l17 = l10.payload.b;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2095u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = l10.payload.b;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l17 != l18) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a15_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l9)
        ((int64_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a16_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l9)
        ((uint8_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1295u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2092u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l17 = l10.payload.b;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2092u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = l10.payload.b;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l17) {
            l17 = l18;
        } else {
            l17 = false;
        }
        if (l17) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a17_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l9)
        ((int64_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a18_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l9)
        ((uint8_t*) _a18_slotarr->buf->slots)[vader_array_offset(_a18_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1300u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2097u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l17 = l10.payload.b;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2097u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = l10.payload.b;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l17) {
            l17 = true;
        } else {
            l17 = l18;
        }
        if (l17) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a19_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l9)
        ((int64_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a20_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l9)
        ((uint8_t*) _a20_slotarr->buf->slots)[vader_array_offset(_a20_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1299u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_bool(l10, l6, 2096u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l17 = l10.payload.b;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        if (l17) {
            l16 = INT64_C(0);
        } else {
            l16 = INT64_C(1);
        }
        vader_array_t* _a21_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l9)
        ((int64_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a22_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l9)
        ((uint8_t*) _a22_slotarr->buf->slots)[vader_array_offset(_a22_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1415u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_string(l10, l6, 3241u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l13 = l10.payload.s;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_string(l10, l6, 3241u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l15 = l10.payload.s;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l13 == l15) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a23_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l9)
        ((int64_t*) _a23_slotarr->buf->slots)[vader_array_offset(_a23_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a24_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l9)
        ((uint8_t*) _a24_slotarr->buf->slots)[vader_array_offset(_a24_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1416u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_string(l10, l6, 3243u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l13 = l10.payload.s;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_string(l10, l6, 3243u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l15 = l10.payload.s;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l13 != l15) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l9)
        ((int64_t*) _a25_slotarr->buf->slots)[vader_array_offset(_a25_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a26_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l9)
        ((uint8_t*) _a26_slotarr->buf->slots)[vader_array_offset(_a26_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1413u) {
        l10 = vader_vm$exec_string_compare(l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1399u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l11 = vader_vm$peek_val(l3, l9);
        l17 = vader_vm$value_ref_eq(l10, l11);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l17) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a27_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l9)
        ((int64_t*) _a27_slotarr->buf->slots)[vader_array_offset(_a27_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a28_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l9)
        ((uint8_t*) _a28_slotarr->buf->slots)[vader_array_offset(_a28_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1400u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l11 = vader_vm$peek_val(l3, l9);
        l17 = vader_vm$value_ref_eq(l10, l11);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        if (l17) {
            l16 = INT64_C(0);
        } else {
            l16 = INT64_C(1);
        }
        vader_array_t* _a29_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l9)
        ((int64_t*) _a29_slotarr->buf->slots)[vader_array_offset(_a29_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a30_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l9)
        ((uint8_t*) _a30_slotarr->buf->slots)[vader_array_offset(_a30_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1420u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        l17 = vader_vm$type_matches(l0, l10, l6);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        if (l17) {
            l16 = INT64_C(1);
        } else {
            l16 = INT64_C(0);
        }
        vader_array_t* _a31_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l9)
        ((int64_t*) _a31_slotarr->buf->slots)[vader_array_offset(_a31_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a32_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l9)
        ((uint8_t*) _a32_slotarr->buf->slots)[vader_array_offset(_a32_slotarr) + (size_t) l9] = (uint8_t) INT32_C(3);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1421u) {
        l9 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        vader_struct_vader_vm$TypeVal_t* _a33_obj = (vader_struct_vader_vm$TypeVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$TypeVal_t));
        vader_obj_header_init(_a33_obj, 2129u);
        _a33_obj->f_type_id = t2;
        l8 = (void*) _a33_obj;
        vader_vm$push_val(l3, l9, vader_ref_box(l8));
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_add(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1303u) {
        l8 = ((vader_struct_vader_vm$RunHost_t*) l1)->f_obj_handles;
        l10 = vader_vm$build_buffer(l3, l8);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1388u) {
        l10 = vader_vm$load_bytes_op(l3, INT64_C(1), 2841u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l19 = ((uint64_t) l10.payload.i);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l16 = ((int64_t) (int32_t) ((int32_t) (uint64_t) l19));
        vader_array_t* _a34_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l9)
        ((int64_t*) _a34_slotarr->buf->slots)[vader_array_offset(_a34_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a35_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l9)
        ((uint8_t*) _a35_slotarr->buf->slots)[vader_array_offset(_a35_slotarr) + (size_t) l9] = (uint8_t) INT32_C(0);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1383u) {
        l10 = vader_vm$load_bytes_op(l3, INT64_C(4), 2835u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l19 = ((uint64_t) l10.payload.i);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l16 = ((int64_t) (int32_t) ((int32_t) (uint64_t) l19));
        vader_array_t* _a36_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l9)
        ((int64_t*) _a36_slotarr->buf->slots)[vader_array_offset(_a36_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a37_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l9)
        ((uint8_t*) _a37_slotarr->buf->slots)[vader_array_offset(_a37_slotarr) + (size_t) l9] = (uint8_t) INT32_C(0);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1384u) {
        l10 = vader_vm$load_bytes_op(l3, INT64_C(8), 2836u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l19 = ((uint64_t) l10.payload.i);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l16 = ((int64_t) (uint64_t) l19);
        vader_array_t* _a38_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l9)
        ((int64_t*) _a38_slotarr->buf->slots)[vader_array_offset(_a38_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a39_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l9)
        ((uint8_t*) _a39_slotarr->buf->slots)[vader_array_offset(_a39_slotarr) + (size_t) l9] = (uint8_t) INT32_C(1);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1382u) {
        l10 = vader_vm$load_bytes_op(l3, INT64_C(8), 2834u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l19 = ((uint64_t) l10.payload.i);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l16 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l19) }).__vd) }).__vu));
        vader_array_t* _a40_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l9)
        ((int64_t*) _a40_slotarr->buf->slots)[vader_array_offset(_a40_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a41_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l9)
        ((uint8_t*) _a41_slotarr->buf->slots)[vader_array_offset(_a41_slotarr) + (size_t) l9] = (uint8_t) INT32_C(2);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1412u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$stack_i32(l3, l9, 3232u, 3666u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int32_t) l10.payload.i);
        t1 = ((int64_t) (uint32_t) (t2 & INT32_C(255)));
        l19 = (uint64_t) (int64_t) t1;
        l10 = vader_vm$store_bytes_op(l3, INT64_C(1), l19, 3232u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1407u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$stack_i32(l3, l9, 3225u, 3666u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int32_t) l10.payload.i);
        t1 = ((int64_t) (uint32_t) t2);
        l19 = (uint64_t) (int64_t) t1;
        l10 = vader_vm$store_bytes_op(l3, INT64_C(4), l19, 3225u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1408u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_i64(l10, l6, 3227u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int64_t) l10.payload.i);
        t6 = t1;
        l19 = (uint64_t) (int64_t) t6;
        l10 = vader_vm$store_bytes_op(l3, INT64_C(8), l19, 3226u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1406u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_f64(l10, l6, 3224u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t7 = ((double) l10.payload.f);
        t1 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t7 }).__vu);
        l19 = (uint64_t) (int64_t) t1;
        l10 = vader_vm$store_bytes_op(l3, INT64_C(8), l19, 3223u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1396u) {
        l10 = vader_vm$do_memory_copy(l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1304u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_i32(l10, l7, 2122u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((int32_t) l10.payload.i);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(2));
        l10 = vader_vm$peek_val(l3, l9);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_obj(l10, l7, 2123u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l10.payload.obj;
        l16 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l8)->f_bytes));
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$check_byte_range(l6, INT64_C(0), l16, 2121u, l7);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((int64_t) l10.payload.i);
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l16 = vader_chk_sub(i64, t1, INT64_C(2));
        vader_array_t* _a42_arr = vader_array_slice((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l8)->f_bytes, (int64_t) INT64_C(0), (int64_t) l9);
        t0 = (void*) _a42_arr;
        l13 = vader_host_std_core$Intrinsic$bytes_to_string(t0);
        vader_vm$push_val(l3, l16, vader_box_string(623u, l13));
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_sp = l9;
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1305u) {
        l10 = vader_vm$exec_buffer_write_string(l3);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l2.tag == 1335u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_f64(l10, l6, 2498u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l20 = ((double) l10.payload.f);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l16 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l20 }).__vu));
        vader_array_t* _a43_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l9)
        ((int64_t*) _a43_slotarr->buf->slots)[vader_array_offset(_a43_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a44_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l9)
        ((uint8_t*) _a44_slotarr->buf->slots)[vader_array_offset(_a44_slotarr) + (size_t) l9] = (uint8_t) INT32_C(1);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1293u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l16 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l16);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_i64(l10, l6, 2085u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((int64_t) l10.payload.i);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l16 = vader_chk_sub(i64, t1, INT64_C(1));
        l9 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l9) }).__vd) }).__vu));
        vader_array_t* _a45_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l16)
        ((int64_t*) _a45_slotarr->buf->slots)[vader_array_offset(_a45_slotarr) + (size_t) l16] = (int64_t) l9;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a46_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l9)
        ((uint8_t*) _a46_slotarr->buf->slots)[vader_array_offset(_a46_slotarr) + (size_t) l9] = (uint8_t) INT32_C(2);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1322u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l6 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_f64(l10, l6, 2484u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l20 = ((double) l10.payload.f);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l16 = ((int64_t) (int32_t) ((int32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = l20 }).__vb)));
        vader_array_t* _a47_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l9)
        ((int64_t*) _a47_slotarr->buf->slots)[vader_array_offset(_a47_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a48_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l9)
        ((uint8_t*) _a48_slotarr->buf->slots)[vader_array_offset(_a48_slotarr) + (size_t) l9] = (uint8_t) INT32_C(0);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    } else if (l2.tag == 1292u) {
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l10 = vader_vm$peek_val(l3, l9);
        l7 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l10 = vader_vm$read_i32(l10, l7, 2084u);
        l11 = l10;
        if (l10.tag == 2128u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((int32_t) l10.payload.i);
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_payload;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        l16 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(l6) }).__vf)) }).__vu));
        vader_array_t* _a49_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l9)
        ((int64_t*) _a49_slotarr->buf->slots)[vader_array_offset(_a49_slotarr) + (size_t) l9] = (int64_t) l16;
        l8 = ((vader_struct_vader_vm$Frame_t*) l3)->f_tag;
        t1 = ((vader_struct_vader_vm$Frame_t*) l3)->f_sp;
        l9 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a50_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l9)
        ((uint8_t*) _a50_slotarr->buf->slots)[vader_array_offset(_a50_slotarr) + (size_t) l9] = (uint8_t) INT32_C(2);
        t2 = ((vader_struct_vader_vm$Frame_t*) l3)->f_pc;
        l6 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_vm$Frame_t*) l3)->f_pc = l6;
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
    t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l4, 628u);
    l5 = ((uint8_t) t1.payload.i);
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l4, 628u);
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
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
            l9 = ((int32_t) (int64_t) t0);
            l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
            t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l4];
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
            if (l11.tag == 2128u) {
                t3 = l11.payload.obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l12.tag == 2128u) {
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
    ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l4] = (int64_t) l13;
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
    ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l4] = (uint8_t) INT32_C(3);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l4;
    t4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l9 = vader_chk_add(i32, t4, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l9;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$array_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        if (l2.tag == 2093u) {
            t1 = l2.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_vm$array_bytes(void* l0, int64_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    int64_t l6;
    uint8_t l8;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[3] = { &l4, &l7, &t2 };
    void** gc_raw_roots[4] = { &l0, &l5, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        t1 = vader_vm$first_bytes(t0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(31u, 0u, 1u, 628u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        l4 = vader_vm$read_i64(t2, l2, l3);
        l7 = l4;
        if (l4.tag == 2128u) {
            t0 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((int64_t) l4.payload.i);
        t4 = (((int32_t) (int64_t) t3) & INT32_C(255));
        l8 = (uint8_t) (int32_t) t4;
        vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$at_width(int64_t l0, int64_t l1, bool l2) {
    int64_t l3, l4;
    int64_t t0;
    if ((l1 >= INT64_C(8))) {
        return l0;
    }
    t0 = vader_chk_mul(i64, l1, INT64_C(8));
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = (INT64_C(1) << (l3 & 63));
    l4 = vader_chk_sub(i64, (l3 << INT64_C(1)), INT64_C(1));
    l4 = (l0 & l4);
    if (l2) {
        if ((l4 & l3) != INT64_C(0)) {
            l3 = (l3 << INT64_C(1));
            t0 = vader_chk_sub(i64, l4, l3);
            return t0;
        }
        return l4;
    }
    return l4;
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
    if (l0.tag == 1290u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        { vader_box_t __vret = vader_box_string(623u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1289u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t2 = vader_vm$value_from_bits(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1291u) {
        vader_array_t* _a0_arr = vader_array_new(503u, 0u, 0u, 3020u);
        l4 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields;
        l6 = vader_array_length(((vader_array_t*) l5));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
            l8 = vader_vm$bc_value_to_vm(t2, l1);
            vader_array_push((vader_array_t*) l4, l8);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        t3 = vader_vm$type_id_for_symbol(l1, l9);
        vader_struct_vader_vm$StructVal_t* _a2_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
        vader_obj_header_init(_a2_obj, 2125u);
        _a2_obj->f_type_id = t3;
        _a2_obj->f_fields = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1288u)) {
        { vader_box_t __vret = vader_box_i32(626u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l4 = (void*) _a3_arr;
    t0 = l0.payload.obj;
    l5 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t2 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l7);
        l8 = vader_vm$bc_value_to_vm(t2, l1);
        vader_array_push((vader_array_t*) l4, l8);
        l7 = (l7 + INT64_C(1));
    }
    t0 = l0.payload.obj;
    t3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a5_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a5_obj, 2093u);
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
    if (l0.tag == 1340u) {
        l3 = vader_box_i32(626u, INT32_C(2));
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1359u) {
        l3 = vader_box_i32(626u, INT32_C(3));
    } else if (l0.tag == 1353u) {
        l3 = vader_box_i32(626u, INT32_C(4));
    } else if (l0.tag == 1346u) {
        l3 = vader_box_i32(626u, INT32_C(5));
    } else if (l0.tag == 1352u) {
        l3 = vader_box_i32(626u, INT32_C(6));
    } else if (l0.tag == 1341u) {
        l3 = vader_box_i32(626u, INT32_C(7));
    } else if (l0.tag == 1343u) {
        l3 = vader_box_i32(626u, INT32_C(8));
    } else if (l0.tag == 1344u) {
        l3 = vader_box_i32(626u, INT32_C(9));
    } else if (l0.tag == 1356u) {
        l3 = vader_box_i32(626u, INT32_C(10));
    } else if (l0.tag == 1357u) {
        l3 = vader_box_i32(626u, INT32_C(11));
    } else if (l0.tag == 1358u) {
        l3 = vader_box_i32(626u, INT32_C(12));
    } else if (l0.tag == 1422u) {
        l3 = vader_box_i32(626u, INT32_C(15));
    } else if (l0.tag == 1427u) {
        l3 = vader_box_i32(626u, INT32_C(16));
    } else if (l0.tag == 1347u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(626u, INT32_C(17));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1354u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 19);
        if (t0) {
            l3 = vader_box_i32(626u, INT32_C(18));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1351u) {
        l3 = vader_box_i32(626u, INT32_C(19));
    } else if (l0.tag == 1350u) {
        l3 = vader_box_i32(626u, INT32_C(20));
    } else if (l0.tag == 1349u) {
        l3 = vader_box_i32(626u, INT32_C(21));
    } else if (l0.tag == 1348u) {
        l3 = vader_box_i32(626u, INT32_C(22));
    } else if (l0.tag == 1426u) {
        l3 = vader_box_i32(626u, INT32_C(23));
    } else if (l0.tag == 1425u) {
        l3 = vader_box_i32(626u, INT32_C(24));
    } else if (l0.tag == 1424u) {
        l3 = vader_box_i32(626u, INT32_C(25));
    } else if (l0.tag == 1423u) {
        l3 = vader_box_i32(626u, INT32_C(26));
    } else if (l0.tag == 1360u) {
        l3 = vader_box_i32(626u, INT32_C(27));
    } else if (l0.tag == 1379u) {
        l3 = vader_box_i32(626u, INT32_C(28));
    } else if (l0.tag == 1373u) {
        l3 = vader_box_i32(626u, INT32_C(29));
    } else if (l0.tag == 1366u) {
        l3 = vader_box_i32(626u, INT32_C(30));
    } else if (l0.tag == 1372u) {
        l3 = vader_box_i32(626u, INT32_C(31));
    } else if (l0.tag == 1361u) {
        l3 = vader_box_i32(626u, INT32_C(32));
    } else if (l0.tag == 1363u) {
        l3 = vader_box_i32(626u, INT32_C(33));
    } else if (l0.tag == 1364u) {
        l3 = vader_box_i32(626u, INT32_C(34));
    } else if (l0.tag == 1376u) {
        l3 = vader_box_i32(626u, INT32_C(35));
    } else if (l0.tag == 1377u) {
        l3 = vader_box_i32(626u, INT32_C(36));
    } else if (l0.tag == 1378u) {
        l3 = vader_box_i32(626u, INT32_C(37));
    } else if (l0.tag == 1428u) {
        l3 = vader_box_i32(626u, INT32_C(40));
    } else if (l0.tag == 1433u) {
        l3 = vader_box_i32(626u, INT32_C(41));
    } else if (l0.tag == 1367u) {
        l3 = vader_box_i32(626u, INT32_C(42));
    } else if (l0.tag == 1374u) {
        l3 = vader_box_i32(626u, INT32_C(43));
    } else if (l0.tag == 1371u) {
        l3 = vader_box_i32(626u, INT32_C(44));
    } else if (l0.tag == 1370u) {
        l3 = vader_box_i32(626u, INT32_C(45));
    } else if (l0.tag == 1369u) {
        l3 = vader_box_i32(626u, INT32_C(46));
    } else if (l0.tag == 1368u) {
        l3 = vader_box_i32(626u, INT32_C(47));
    } else if (l0.tag == 1432u) {
        l3 = vader_box_i32(626u, INT32_C(48));
    } else if (l0.tag == 1431u) {
        l3 = vader_box_i32(626u, INT32_C(49));
    } else if (l0.tag == 1430u) {
        l3 = vader_box_i32(626u, INT32_C(50));
    } else if (l0.tag == 1429u) {
        l3 = vader_box_i32(626u, INT32_C(51));
    } else if (l0.tag == 1323u) {
        l3 = vader_box_i32(626u, INT32_C(52));
    } else if (l0.tag == 1334u) {
        l3 = vader_box_i32(626u, INT32_C(53));
    } else if (l0.tag == 1331u) {
        l3 = vader_box_i32(626u, INT32_C(54));
    } else if (l0.tag == 1325u) {
        l3 = vader_box_i32(626u, INT32_C(55));
    } else if (l0.tag == 1326u) {
        l3 = vader_box_i32(626u, INT32_C(57));
    } else if (l0.tag == 1332u) {
        l3 = vader_box_i32(626u, INT32_C(58));
    } else if (l0.tag == 1330u) {
        l3 = vader_box_i32(626u, INT32_C(59));
    } else if (l0.tag == 1329u) {
        l3 = vader_box_i32(626u, INT32_C(60));
    } else if (l0.tag == 1328u) {
        l3 = vader_box_i32(626u, INT32_C(61));
    } else if (l0.tag == 1327u) {
        l3 = vader_box_i32(626u, INT32_C(62));
    } else if (l0.tag == 1297u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(626u, INT32_C(63));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1298u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(626u, INT32_C(64));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1295u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(626u, INT32_C(65));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1300u) {
        t0 = vader_vm$operands_within(l1, l2, (uint8_t) 8);
        if (t0) {
            l3 = vader_box_i32(626u, INT32_C(66));
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
    } else if (l0.tag == 1312u) {
        t1 = l0.payload.obj;
        t2 = vader_vm$checked_register_op(t1);
        l3 = vader_box_i32(626u, t2);
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_boxed));
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
        vader_obj_header_init(_a0_obj, 2102u);
        _a0_obj->f_op = l1;
        _a0_obj->f_swap = l2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$FusedBranch_t* _a1_obj = (vader_struct_vader_vm$FusedBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FusedBranch_t));
    vader_obj_header_init(_a1_obj, 2102u);
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
    l2 = std_core$write_string_at(l1, l2, 2267u);
    l2 = std_core$write_int(l1, l2, l0);
    l2 = std_core$write_string_at(l1, l2, 275u);
    t0 = std_core$finish_buffer(l1, l2);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 2128u);
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
        l4 = std_core$write_string_at(l3, l4, 2032u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 205u);
        t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core$write_int(l3, l4, l5);
        t1 = std_core$finish_buffer(l3, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) (int32_t) l1);
    t3 = ((vader_struct_vader_vm$Frame_t*) l2)->f_sp;
    l5 = vader_chk_sub(i64, t3, l4);
    vader_array_t* _a1_arr = vader_array_reserve(503u, (int64_t) l4, 0u, 3020u);
    l3 = (void*) _a1_arr;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        l7 = vader_chk_add(i64, l5, l6);
        l8 = vader_vm$peek_owned(l2, l7);
        vader_array_push((vader_array_t*) l3, l8);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 2093u);
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
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$build_buffer(void* l0, void* l1) {
    int32_t l2;
    int64_t l3, l7;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l8 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm$peek_val(l0, l3);
    l2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l2, 2115u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l4.payload.i);
    if ((l2 < INT32_C(0))) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(75));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l6, l3, 2116u);
        l7 = ((int64_t) (int32_t) l2);
        l3 = std_core$write_int(l6, l3, l7);
        l3 = std_core$write_string_at(l6, l3, 205u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l7 = ((int64_t) (int32_t) t2);
        l3 = std_core$write_int(l6, l3, l7);
        t3 = std_core$finish_buffer(l6, l3);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_reserve(31u, (int64_t) ((int64_t) (int32_t) l2), 1u, 628u);
    l6 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l7 = ((int64_t) (int32_t) l2);
    vader_array_t* _pc78_hdr = (vader_array_t*) l6;
    size_t _pc78_len = vader_array_length(_pc78_hdr);
    size_t _pc78_cap = vader_array_is_borrowed(_pc78_hdr) ? (size_t) 0 : vader_array_capacity(_pc78_hdr);
    void* _pc78_slots = _pc78_hdr->buf->slots;
    for (;;) {
        if ((l3 < l7)) {
            if (VADER_LIKELY(_pc78_len < _pc78_cap)) {
                ((uint8_t*) _pc78_slots)[_pc78_len] = (uint8_t) (INT32_C(0));
                _pc78_len += 1;
            } else {
                vader_array_set_length(_pc78_hdr, _pc78_len);
                if (_pc78_hdr->buf->length < _pc78_len) {
                    _pc78_hdr->buf->length = _pc78_len;
                }
                vader_array_push_u8((vader_array_t*) l6, INT32_C(0));
                _pc78_hdr = (vader_array_t*) l6;
                _pc78_len = vader_array_length(_pc78_hdr);
                _pc78_cap = vader_array_is_borrowed(_pc78_hdr) ? (size_t) 0 : vader_array_capacity(_pc78_hdr);
                _pc78_slots = _pc78_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc78_hdr, _pc78_len);
        if (_pc78_hdr->buf->length < _pc78_len) {
            _pc78_hdr->buf->length = _pc78_len;
        }
        break;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t2 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)];
    l2 = vader_chk_add(i32, t2, INT32_C(1));
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)] = (int32_t) l2;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    l2 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)];
    vader_array_t* _a3_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l8 = (void*) _a3_arr;
    vader_struct_vader_vm$ObjVal_t* _a4_obj = (vader_struct_vader_vm$ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ObjVal_t));
    vader_obj_header_init(_a4_obj, 2109u);
    _a4_obj->f_handle = l2;
    _a4_obj->f_type_id = INT32_C(0);
    _a4_obj->f_bytes = l6;
    _a4_obj->f_slots = l8;
    l6 = (void*) _a4_obj;
    vader_vm$push_val(l0, l3, vader_ref_box(l6));
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l2;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params;
    t0 = vader_array_length(((vader_array_t*) l4));
    if (t0 == INT64_C(0)) {
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_array_length(((vader_array_t*) l4));
    if ((t0 > INT64_C(1))) {
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
        l7 = vader_host_std_core$Intrinsic$byte_len(l6);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(76) + l7));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l8, l7, 2400u);
        l7 = std_core$write_string_at(l8, l7, l6);
        l7 = std_core$write_string_at(l8, l7, 373u);
        l7 = std_core$write_int(l8, l7, l5);
        l7 = std_core$write_string_at(l8, l7, 255u);
        t1 = std_core$finish_buffer(l8, l7);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0), 628u);
    l9 = vader_vm$tags_of_val(((uint8_t) t3.payload.i));
    t4 = vader_vm$tags_within((uint8_t) 64, l9);
    if (!(t4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t3 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) INT32_C(0), 628u);
        l6 = vader_core_bytecode$val_type_name(((uint8_t) t3.payload.i));
        l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
        t1 = concat_5(2400u, l10, 374u, l6, 457u);
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 2128u);
        _a4_obj->f_message = t1;
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_array_length(((vader_array_t*) l1));
    if (t0 == INT64_C(0)) {
        vader_array_t* _a5_arr = vader_array_new(28u, 1u, 0u, 623u);
        vader_array_box_slots(_a5_arr->buf)[vader_array_offset(_a5_arr) + 0u] = vader_box_string(623u, 626u);
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
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l3.tag == 1286u)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(79));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 3261u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l4, l5, l6);
        l5 = std_core$write_string_at(l4, l5, 209u);
        t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
        l6 = ((int64_t) (int32_t) t0);
        l5 = std_core$write_int(l4, l5, l6);
        t1 = std_core$finish_buffer(l4, l5);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = t1;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l3.payload.obj;
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields));
    t3 = ((vader_struct_vader_vm$Frame_t*) l2)->f_sp;
    l6 = vader_chk_sub(i64, t3, l5);
    if ((INT64_C(0) < l5)) {
        l7 = l5;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a2_arr = vader_array_reserve(503u, (int64_t) l7, 0u, 3020u);
    l4 = (void*) _a2_arr;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        t2 = l3.payload.obj;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcField_t*) t2)->f_type_index;
        l9 = vader_vm$field_valtype(l0, l8);
        l10 = vader_chk_add(i64, l6, l7);
        t4 = vader_vm$peek_owned(l2, l10);
        l11 = vader_vm$narrow_mask(t4, l9);
        vader_array_push((vader_array_t*) l4, l11);
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_vm$StructVal_t* _a4_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
    vader_obj_header_init(_a4_obj, 2125u);
    _a4_obj->f_type_id = l1;
    _a4_obj->f_fields = l4;
    l4 = (void*) _a4_obj;
    vader_vm$push_val(l2, l6, vader_ref_box(l4));
    l5 = vader_chk_add(i64, l6, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_sp = l5;
    t0 = ((vader_struct_vader_vm$Frame_t*) l2)->f_pc;
    l8 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l2)->f_pc = l8;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_vm$byte_at(void* l0, int64_t l1) {
    vader_string_t l2;
    int64_t l3;
    int64_t t0;
    uint8_t t1;
    l2 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_text;
    t0 = ((vader_struct_vader_vm$StringWindow_t*) l0)->f_offset;
    l3 = vader_chk_add(i64, t0, l1);
    t1 = vader_host_std_core$Intrinsic$byte_at(l2, l3);
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
    vader_array_t* _a0_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core$Intrinsic$byte_len(l0);
    vader_struct_vader_vm$StringWindow_t* _a1_obj = (vader_struct_vader_vm$StringWindow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StringWindow_t));
    vader_obj_header_init(_a1_obj, 2124u);
    _a1_obj->f_text = l0;
    _a1_obj->f_offset = INT64_C(0);
    _a1_obj->f_length = l3;
    l4 = (void*) _a1_obj;
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 2093u);
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
        t0 = vader_host_std_core$Intrinsic$ffi_call(l0, l2, l3, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_std_core$Intrinsic$ffi_call_frame(l0, l2, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$call_import(void* l0, void* l1, int32_t l2, int64_t l3, int32_t l4, bool l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l8, l9, l10;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    uint8_t t2;
    vader_box_t* gc_roots[2] = { &l11, &l12 };
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params));
    vader_array_t* _a1_arr = vader_array_reserve(503u, (int64_t) t0, 0u, 3020u);
    l7 = (void*) _a1_arr;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_params));
    while ((l8 < l9)) {
        l10 = vader_chk_add(i64, l3, l8);
        l11 = vader_vm$register_value(l1, l10);
        vader_array_push((vader_array_t*) l7, l11);
        l8 = (l8 + INT64_C(1));
    }
    l11 = vader_vm$serve_import(l0, l1, l2, l6, l7, l4, l5);
    l12 = l11;
    if (l11.tag == 2128u) {
        t1 = l12.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l11.payload.obj;
    t2 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature);
    if (t2 != INT32_C(14)) {
        l11 = ((vader_struct_vader_vm$HostOk_t*) l7)->f_value;
        vader_vm$set_register(l1, l3, l11);
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$call_results(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    int32_t l4;
    void* t0;
    l2 = ((vader_struct_vader_vm$TagContext_t*) l0)->f_module;
    if (l1.tag == 1308u) {
        l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l2)->f_functions;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        return vader_ref_box(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature)->f_results);
    }
    if (l1.tag == 1309u) {
        l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l2)->f_imports;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        return vader_ref_box(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature)->f_results);
    }
    if (!(l1.tag == 1437u)) {
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
    vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2112u);
    l4 = (void*) _a0_arr;
    l5 = l3;
    while ((l5 > INT64_C(0))) {
        l5 = vader_chk_sub(i64, l5, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l8 = vader_chk_sub(i64, l3, INT64_C(1));
        if (l5 == l8) {
            l7 = l2;
        } else {
            l9 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_return;
            l10 = vader_chk_add(i64, l5, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
            l7 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l10];
        }
        l12 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_slots;
        if ((INT64_C(0) < l12)) {
            l11 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_slots;
        } else {
            l11 = INT64_C(0);
        }
        vader_array_t* _a3_arr = vader_array_reserve(503u, (int64_t) l11, 0u, 3020u);
        l13 = (void*) _a3_arr;
        l14 = INT64_C(0);
        l15 = ((vader_struct_vader_vm$RegFunction_t*) l6)->f_slots;
        while ((l14 < l15)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_frame_base);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            t0 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l5];
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
        l21 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l20);
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l6)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l22 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l7];
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
        { vader_box_t __vret = vader_box_i64(627u, l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l5 = vader_vm$adapter_reason(l1, l4);
    if (!(l5.tag == 0u)) {
        l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
        l7 = l5.payload.s;
        l8 = 2132u;
        l9 = vader_host_std_core$Intrinsic$byte_len(l6);
        l10 = vader_host_std_core$Intrinsic$byte_len(l7);
        l9 = (l9 + l10);
        l10 = vader_host_std_core$Intrinsic$byte_len(l8);
        l9 = (l9 + l10);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(40) + l9));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l4, l9, 2478u);
        l9 = std_core$write_string_at(l4, l9, l6);
        l9 = std_core$write_string_at(l4, l9, 1349u);
        l10 = ((int64_t) (int32_t) l3);
        l9 = std_core$write_int(l4, l9, l10);
        l9 = std_core$write_string_at(l4, l9, 566u);
        l9 = std_core$write_string_at(l4, l9, l7);
        l9 = std_core$write_string_at(l4, l9, 608u);
        l9 = std_core$write_string_at(l4, l9, l8);
        t0 = std_core$finish_buffer(l4, l9);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$library_name(l1);
    l9 = vader_host_std_core$Intrinsic$ffi_open(t0);
    if (l9 == INT64_C(0)) {
        l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
        l7 = vader_vm$unopened_reason(l1);
        l10 = vader_host_std_core$Intrinsic$byte_len(l6);
        l11 = vader_host_std_core$Intrinsic$byte_len(l7);
        l10 = (l10 + l11);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l10));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l4, l10, 2478u);
        l10 = std_core$write_string_at(l4, l10, l6);
        l10 = std_core$write_string_at(l4, l10, 1349u);
        l11 = ((int64_t) (int32_t) l3);
        l10 = std_core$write_int(l4, l10, l11);
        l10 = std_core$write_string_at(l4, l10, 566u);
        l10 = std_core$write_string_at(l4, l10, l7);
        t0 = std_core$finish_buffer(l4, l10);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = t0;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
    l9 = vader_host_std_core$Intrinsic$ffi_symbol(l9, l6);
    if (!(l9 == INT64_C(0))) {
        { vader_box_t __vret = vader_box_i64(627u, l9); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
    l9 = vader_host_std_core$Intrinsic$byte_len(l6);
    l4 = (void*) vader_buffer_new((size_t) (INT64_C(54) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l4, l9, 2478u);
    l9 = std_core$write_string_at(l4, l9, l6);
    l9 = std_core$write_string_at(l4, l9, 1349u);
    l10 = ((int64_t) (int32_t) l3);
    l9 = std_core$write_int(l4, l9, l10);
    l9 = std_core$write_string_at(l4, l9, 600u);
    t0 = std_core$finish_buffer(l4, l9);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 2128u);
    _a2_obj->f_message = t0;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$cancel(int64_t l0) {
    void* l1 = NULL;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_33;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_34;
    } else {
        l1 = vader_vm$guest_threads();
    }
    t1 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l1)->f_live, l0);
    if (!(t1.tag == 0u)) {
        vader_host_std_core$Intrinsic$cancel_thread(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$cancel_guest_thread(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    int64_t l4, l6;
    void* l5 = NULL;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l2, &l3, &t2 };
    void** gc_raw_roots[2] = { &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$read_i64(l0, l1, 2196u);
    l3 = l2;
    if (l2.tag == 2128u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) l2.payload.i);
    t1 = vader_global_33;
    if (t1 == INT32_C(2)) {
        l5 = vader_global_34;
    } else {
        l5 = vader_vm$guest_threads();
    }
    l6 = ((vader_struct_vader_vm$GuestThreads_t*) l5)->f_entry_thread;
    if (!(l4 == l6)) {
        vader_vm$cancel(l4);
        t2 = vader_vm$void_result();
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 2128u);
    _a0_obj->f_message = 3696u;
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
        l6 = vader_host_std_core$Intrinsic$byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(67) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l7, l6, l5);
        l6 = std_core$write_string_at(l7, l6, 240u);
        l8 = ((int64_t) (int32_t) l0);
        l6 = std_core$write_int(l7, l6, l8);
        l6 = std_core$write_string_at(l7, l6, 205u);
        l8 = ((int64_t) (int32_t) l4);
        l6 = std_core$write_int(l7, l6, l8);
        t0 = std_core$finish_buffer(l7, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int64_t) (int32_t) l0);
    t2 = vader_chk_add(i64, l6, l1);
    if (!((t2 > l2))) {
        { vader_box_t __vret = vader_box_i64(627u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l8 = vader_host_std_core$Intrinsic$byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l7, l8, l5);
    l8 = std_core$write_string_at(l7, l8, 240u);
    l8 = std_core$write_int(l7, l8, l6);
    l8 = std_core$write_string_at(l7, l8, 66u);
    l8 = std_core$write_int(l7, l8, l1);
    l8 = std_core$write_string_at(l7, l8, 408u);
    l8 = std_core$write_int(l7, l8, l2);
    l8 = std_core$write_string_at(l7, l8, 130u);
    l6 = ((int64_t) (int32_t) l4);
    l8 = std_core$write_int(l7, l8, l6);
    t0 = std_core$finish_buffer(l7, l8);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
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
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
        l6 = INT64_C(0);
        l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body));
        while ((l6 < l7)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) l5)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
            if ((t0 < INT64_C(0))) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
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
                    l16 = concat_6(1310u, l15, 1528u, l13, 296u, l14);
                    t2 = vader_vm$defect(l4, l6, l16);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l9 = (l9 + INT64_C(1));
            }
            l6 = (l6 + INT64_C(1));
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
    l4 = vader_host_std_core$Intrinsic$byte_len(l3);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l5, l4, l3);
    l4 = std_core$write_string_at(l5, l4, 130u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    l6 = ((int64_t) (int32_t) t0);
    l4 = std_core$write_int(l5, l4, l6);
    t1 = std_core$finish_buffer(l5, l4);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
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
    l5 = vader_host_std_core$Intrinsic$byte_len(l4);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l5));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l6, l5, l4);
    l5 = std_core$write_string_at(l6, l5, 130u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core$write_int(l6, l5, l7);
    t1 = std_core$finish_buffer(l6, l5);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
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
        if (l0.tag == 626u) {
            return true;
        }
        return l0.tag == 627u;
    }
    if (l1 == INT32_C(8)) {
        return (l0.tag == 632u || l0.tag == 633u);
    }
    if (!(l1 == INT32_C(15))) {
        return false;
    }
    if (l0.tag == 627u) {
        return true;
    }
    return l0.tag == 626u;
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
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
        if (l7.tag == 1403u) {
            t0 = l7.payload.obj;
            vader_vm$add_constant(((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value, l1, l2, l3);
        } else if ((l7.tag == 1296u || l7.tag == 1311u || l7.tag == 1324u || l7.tag == 1345u || l7.tag == 1365u || l7.tag == 1397u)) {
            vader_vm$add_constant(l7, l1, l2, l3);
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$comptime_refusal(uint8_t l0) {
    vader_box_t l1;
    bool l2;
    if (l0 == INT32_C(61)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(62);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(63);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(64);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(65);
    }
    if (l2) {
        l1 = vader_box_string(623u, 2783u);
        return l1;
    }
    if (l0 == INT32_C(59)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(60);
    }
    if (l2) {
        l1 = vader_box_string(623u, 2783u);
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
            l2 = true;
        } else {
            l2 = l0 == INT32_C(7);
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
                l2 = l0 == INT32_C(13);
            }
            if (l2) {
                l1 = vader_box_obj(0u, NULL);
            } else {
                if (l0 == INT32_C(26)) {
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
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(29);
                }
                if (l2) {
                    l1 = vader_box_obj(0u, NULL);
                } else {
                    if (l0 == INT32_C(30)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(31);
                    }
                    if (l2) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(32);
                    }
                    if (l2) {
                        l1 = vader_box_obj(0u, NULL);
                    } else {
                        if (l0 == INT32_C(33)) {
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
                            l1 = vader_box_obj(0u, NULL);
                        } else {
                            if (l0 == INT32_C(37)) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(38);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(39);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(40);
                            }
                            if (l2) {
                                l1 = vader_box_obj(0u, NULL);
                            } else {
                                if (l0 == INT32_C(42)) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(43);
                                }
                                if (l2) {
                                    l1 = vader_box_obj(0u, NULL);
                                } else {
                                    if (l0 == INT32_C(44)) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(45);
                                    }
                                    if (l2) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(46);
                                    }
                                    if (l2) {
                                        l1 = vader_box_obj(0u, NULL);
                                    } else if (l0 == INT32_C(41)) {
                                        l1 = vader_box_obj(0u, NULL);
                                    } else {
                                        if (l0 == INT32_C(47)) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(48);
                                        }
                                        if (l2) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(49);
                                        }
                                        if (l2) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(50);
                                        }
                                        if (l2) {
                                            l1 = vader_box_obj(0u, NULL);
                                        } else {
                                            if (l0 == INT32_C(51)) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(52);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(53);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(54);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(57);
                                            }
                                            if (l2) {
                                                l1 = vader_box_obj(0u, NULL);
                                            } else {
                                                if (l0 == INT32_C(55)) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(56);
                                                }
                                                if (l2) {
                                                    l1 = vader_box_obj(0u, NULL);
                                                } else if (l0 == INT32_C(58)) {
                                                    l1 = vader_box_obj(0u, NULL);
                                                } else {
                                                    if (l0 == INT32_C(0)) {
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
                                                    if (l2) {
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
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(25);
                                                    }
                                                    if (!(l2)) {
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
    t0 = concat_4(2632u, l0, 1516u, l1);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 2128u);
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
    t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l3, 628u);
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
            t0 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l3];
            l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
        } else {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l3];
            l5 = ((int64_t) (int32_t) ((int32_t) (int64_t) t0));
        }
    } else if (l4 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
        l5 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l3];
    } else if (l4 == INT32_C(4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
        t0 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l3];
        l5 = ((int64_t) (uint32_t) ((int32_t) (int64_t) t0));
    } else {
        if (!(l4 == INT32_C(3))) {
            return false;
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
        t0 = ((int64_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l3];
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
        ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l3] = (int64_t) l7;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
        ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l3] = (uint8_t) INT32_C(0);
        return true;
    }
    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l3)
    ((int64_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l3] = (int64_t) l5;
    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l3)
    ((uint8_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l3] = (uint8_t) INT32_C(1);
    return true;
}

static vader_box_t vader_vm$convert_value(vader_box_t l0, uint8_t l1, vader_string_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    uint32_t l7;
    bool l8;
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    int64_t t3;
    double t4;
    uint32_t t5;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &l6 };
    void** gc_raw_roots[1] = { &t2 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 626u) {
        t0 = vader_vm$is_unsigned_source(l2);
        if (t0) {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i64(627u, ((int64_t) (uint32_t) t1));
        } else {
            t1 = ((int32_t) l0.payload.i);
            l4 = vader_box_i32(626u, t1);
        }
    } else {
        l4 = l0;
    }
    if (l1 == INT32_C(0)) {
        if (l4.tag == 626u) {
            t1 = ((int32_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i32(626u, t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_i64(l4, l3);
        l6 = l5;
        if (l5.tag == 2128u) {
            t2 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((int64_t) l5.payload.i);
        { vader_box_t __vret = vader_box_i32(626u, ((int32_t) (int64_t) t3)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        if (l4.tag == 627u) {
            t3 = ((int64_t) l4.payload.i);
            { vader_box_t __vret = vader_box_i64(627u, t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_vm$read_numeric_as_i64(l4, l3);
        l6 = l5;
        if (l5.tag == 2128u) {
            t2 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((int64_t) l5.payload.i);
        { vader_box_t __vret = vader_box_i64(627u, t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        if ((l4.tag == 632u || l4.tag == 633u)) {
            t4 = ((double) l4.payload.f);
            { vader_box_t __vret = vader_box_f64(633u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l4.tag == 627u) {
            t0 = vader_vm$is_unsigned_source(l2);
            if (t0) {
                t3 = ((int64_t) l4.payload.i);
                { vader_box_t __vret = vader_box_f64(633u, ((double) (uint64_t) t3)); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l5 = vader_vm$read_numeric_as_f64(l4, l3);
        l6 = l5;
        if (l5.tag == 2128u) {
            t2 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = ((double) l5.payload.f);
        { vader_box_t __vret = vader_box_f64(633u, t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 622u) {
        t5 = ((uint32_t) l4.payload.i);
        { vader_box_t __vret = vader_box_i32(622u, (int32_t) t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$read_numeric_as_i64(l4, l3);
    l5 = l4;
    if (l4.tag == 2128u) {
        t2 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int64_t) l4.payload.i);
    t1 = ((int32_t) (int64_t) t3);
    l7 = (uint32_t) (int32_t) t1;
    if ((l7 > INT32_C(55295))) {
        if ((l7 < INT32_C(57344))) {
            l8 = true;
        } else {
            l8 = (l7 > INT32_C(1114111));
        }
        if (l8) {
            vader_unreachable("value out of range: no Unicode scalar value");
        } else {
            { vader_box_t __vret = vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l7)); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        { vader_box_t __vret = vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l7)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm$copy_all(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    int64_t l4, l5, l7, l10;
    void* l6 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l3, &l8, &l9 };
    void** gc_raw_roots[3] = { &l0, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$copy_of(l0, l1);
    l3 = l2;
    if (l2.tag == 2128u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        l4 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next;
        l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies));
        if ((l4 < l5)) {
            l6 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies;
            l7 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l3 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l7];
            l8 = vader_vm$copy_inside(l0, l3);
            l9 = l8;
            if (l8.tag == 2128u) {
                t0 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next;
            l10 = vader_chk_add(i64, t1, INT64_C(1));
            ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_next = l10;
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
        t2 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l3];
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$element_count(l1);
    vader_array_t* _a1_arr = vader_array_reserve(503u, (int64_t) l4, 0u, 3020u);
    l2 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l6 = vader_vm$element_at(l1, l5);
        vader_array_push((vader_array_t*) l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 2093u);
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
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l5, &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l1));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l2];
        l6 = vader_vm$copy_of(l0, l5);
        l7 = l6;
        if (l6.tag == 2128u) {
            t0 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l6;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l2] = l4;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        l2 = (l2 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$copy_inside(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 2125u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields;
        l2 = vader_vm$copy_each(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 2093u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
        l2 = vader_vm$copy_each(l0, l3);
    } else if (l1.tag == 2109u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_vm$ObjVal_t*) t0)->f_slots;
        l2 = vader_vm$copy_each(l0, l3);
    } else if (!((l1.tag == 621u || l1.tag == 622u || (l1.tag == 632u || l1.tag == 633u) || l1.tag == 2098u || l1.tag == 626u || l1.tag == 627u || l1.tag == 2108u || l1.tag == 623u || l1.tag == 2129u || l1.tag == 2133u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
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
        l2 = std_core$clone__u8(((vader_struct_vader_vm$ObjVal_t*) l1)->f_bytes);
        l5 = std_core$clone__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal___vader_vm_VoidVal(((vader_struct_vader_vm$ObjVal_t*) l1)->f_slots);
        vader_struct_vader_vm$ObjVal_t* _a0_obj = (vader_struct_vader_vm$ObjVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ObjVal_t));
        vader_obj_header_init(_a0_obj, 2109u);
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
    t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l3];
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
    if (l1.tag == 2125u) {
        l3 = l1.payload.obj;
        l2 = vader_vm$copy_struct(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 2093u) {
        l3 = l1.payload.obj;
        l2 = vader_vm$copy_array(l0, l3);
    } else if (l1.tag == 2109u) {
        l3 = l1.payload.obj;
        l2 = vader_vm$copy_object(l0, l3);
    } else if (l1.tag == 2098u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(71));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2327u);
        t0 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_at_pc;
        l5 = ((int64_t) (int32_t) t0);
        l4 = std_core$write_int(l3, l4, l5);
        t1 = std_core$finish_buffer(l3, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t1;
        t2 = (void*) _a0_obj;
        l2 = vader_ref_box(t2);
    } else {
        if (!((l1.tag == 621u || l1.tag == 622u || (l1.tag == 632u || l1.tag == 633u) || l1.tag == 626u || l1.tag == 627u || l1.tag == 2108u || l1.tag == 623u || l1.tag == 2129u || l1.tag == 2133u))) {
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
        t2 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l3];
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_types;
    l3 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
    if (l4.tag == 1286u) {
        t3 = l4.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t3)->f_shared;
        if (t4) {
            { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    l2 = std_core$clone__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal___vader_vm_VoidVal(((vader_struct_vader_vm$StructVal_t*) l1)->f_fields);
    vader_struct_vader_vm$StructVal_t* _a2_obj = (vader_struct_vader_vm$StructVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StructVal_t));
    vader_obj_header_init(_a2_obj, 2125u);
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
        vader_obj_header_init(_a0_obj, 2097u);
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
    int32_t t0;
    void* t1 = NULL;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l6, &l12, &l13, &t1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_global_33;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_34;
    } else {
        l1 = vader_vm$guest_threads();
    }
    l2 = ((vader_struct_vader_vm$GuestThreads_t*) l1)->f_entry_machine;
    vader_struct___lambda_env_vader_vm_10_t* _a0_obj = (vader_struct___lambda_env_vader_vm_10_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_10_t));
    vader_obj_header_init(_a0_obj, 869u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l2;
    t1 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 523u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_9;
    _a1_closure->env = t1;
    t1 = (void*) _a1_closure;
    t2 = vader_vm$main_thread(t1);
    vader_array_t* _a2_arr = vader_array_new(453u, 1u, 13u, 2113u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t2;
    l3 = (void*) _a2_arr;
    l1 = ((vader_struct_vader_vm$GuestThreads_t*) l1)->f_live;
    l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_size;
    if ((INT64_C(0) < l4)) {
        l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_size;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_reserve(448u, (int64_t) l4, 13u, 2103u);
    l5 = (void*) _a3_arr;
    l6 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l1)->f_size;
    while ((l4 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        l1 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l4);
        vader_array_push_ref((vader_array_t*) l5, l1);
        l4 = (l4 + INT64_C(1));
    }
    l1 = (void*) &vader_fn_static___lambda_vader_vm_11;
    l1 = std_sort$sort__vader_vm_GuestThread(l5, l1);
    l4 = vader_array_length(((vader_array_t*) l1));
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
        l2 = ((vader_struct_vader_vm$GuestThread_t*) l5)->f_machine;
        t3 = ((vader_struct_vader_vm$GuestThread_t*) l5)->f_number;
        l8 = vader_vm$debugged_thread_id(t3);
        l6 = (void*) vader_buffer_new((size_t) INT64_C(26));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l6, l9, 3288u);
        l10 = ((vader_struct_vader_vm$GuestThread_t*) l5)->f_number;
        l9 = std_core$write_int(l6, l9, l10);
        l11 = std_core$finish_buffer(l6, l9);
        vader_struct___lambda_env_vader_vm_13_t* _a6_obj = (vader_struct___lambda_env_vader_vm_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_13_t));
        vader_obj_header_init(_a6_obj, 870u);
        _a6_obj->f_cap_0 = l0;
        _a6_obj->f_cap_1 = l2;
        t1 = (void*) _a6_obj;
        vader_fn_t* _a7_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a7_closure, 523u);
        _a7_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_12;
        _a7_closure->env = t1;
        l12 = (void*) _a7_closure;
        vader_struct_vader_vm$PauseThread_t* _a8_obj = (vader_struct_vader_vm$PauseThread_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseThread_t));
        vader_obj_header_init(_a8_obj, 2113u);
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
    vader_array_t* _a0_arr = vader_array_new(504u, 0u, 13u, 3036u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 626u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l5 = (void*) _a2_arr;
    vader_struct_vader_vm$CopyWalk_t* _a3_obj = (vader_struct_vader_vm$CopyWalk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$CopyWalk_t));
    vader_obj_header_init(_a3_obj, 2095u);
    _a3_obj->f_types = l0;
    _a3_obj->f_at_pc = l2;
    _a3_obj->f_sources = l3;
    _a3_obj->f_kept_ids = l4;
    _a3_obj->f_copies = l5;
    _a3_obj->f_next = INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = vader_vm$copy_all(l3, l1);
    vader_vm$restore(l3);
    if (!(l6.tag == 2128u)) {
        vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a4_obj, 2105u);
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
    vader_obj_header_init(_a0_obj, 2131u);
    _a0_obj->f_function = l3;
    _a0_obj->f_pc = l4;
    _a0_obj->f_message = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$defer_thunk(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l5 = 0;
    int32_t l6;
    void* l7 = NULL;
    int64_t l9, l10;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[4] = { &l1, &l4, &l8, &t0 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 2098u)) {
        l4 = l1;
        l5 = concat_2(l3, 154u);
        t0 = vader_vm$read_fn(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    l4 = vader_vm$validate_fn_index(l6, l7, l2, l3);
    l8 = l4;
    if (l4.tag == 2128u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    t1 = l1.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature)->f_params));
    if (!(t2 != INT64_C(1))) {
        t1 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_name;
    l9 = vader_host_std_core$Intrinsic$byte_len(l5);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(73) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l7, l9, 2331u);
    l9 = std_core$write_string_at(l7, l9, l5);
    l9 = std_core$write_string_at(l7, l9, 372u);
    l10 = ((int64_t) (int32_t) l2);
    l9 = std_core$write_int(l7, l9, l10);
    t3 = std_core$finish_buffer(l7, l9);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
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
    l2 = std_core$write_string_at(l1, l2, 622u);
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l0)->f_handle;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 287u);
    t0 = ((vader_struct_vader_vm$ObjVal_t*) l0)->f_type_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 139u);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l0)->f_bytes));
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 274u);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l0)->f_slots));
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 632u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_vm$describe_value_tag(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 626u) {
        l1 = 2635u;
        return l1;
    }
    if (l0.tag == 627u) {
        l1 = 2657u;
    } else if ((l0.tag == 632u || l0.tag == 633u)) {
        l1 = 2485u;
    } else if (l0.tag == 623u) {
        l1 = 3236u;
    } else if (l0.tag == 2125u) {
        l1 = 3248u;
    } else if (l0.tag == 2093u) {
        l1 = 2015u;
    } else if (l0.tag == 2098u) {
        l1 = 2542u;
    } else if (l0.tag == 2108u) {
        l1 = 3004u;
    } else if (l0.tag == 2133u) {
        l1 = 3699u;
    } else if (l0.tag == 621u) {
        l1 = 2091u;
    } else if (l0.tag == 622u) {
        l1 = 2232u;
    } else if (l0.tag == 2129u) {
        l1 = 3393u;
    } else {
        if (!(l0.tag == 2109u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3008u;
    }
    return l1;
}

static vader_box_t vader_vm$dispatch_extern(void* l0, int32_t l1, void* l2, int64_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    void* l38 = NULL;
    void* l45 = NULL;
    void* l51 = NULL;
    void* l59 = NULL;
    void* l65 = NULL;
    void* l79 = NULL;
    void* l88 = NULL;
    void* l90 = NULL;
    void* l91 = NULL;
    void* l93 = NULL;
    void* l94 = NULL;
    void* l105 = NULL;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l47 = vader_box_null(), l48 = vader_box_null(), l63 = vader_box_null(), l68 = vader_box_null(), l69 = vader_box_null(), l76 = vader_box_null(), l87 = vader_box_null(), l97 = vader_box_null(), l99 = vader_box_null(), l100 = vader_box_null(), l114 = vader_box_null(), l116 = vader_box_null(), l117 = vader_box_null();
    int64_t l17, l18, l19, l21, l23, l24, l28, l30, l31, l35, l36, l37, l39, l40, l41, l42, l43, l44, l50, l52, l56, l57, l58, l60, l61, l62, l66, l71, l72, l73, l78, l80, l81, l83, l85, l86, l89, l92, l95, l96, l101, l103, l104, l107, l109, l112, l113, l119, l121;
    vader_string_t l20 = 0;
    vader_string_t l27 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l46 = 0;
    vader_string_t l54 = 0;
    vader_string_t l55 = 0;
    vader_string_t l64 = 0;
    vader_string_t l67 = 0;
    vader_string_t l77 = 0;
    vader_string_t l98 = 0;
    vader_string_t l115 = 0;
    uint8_t l49, l70, l74, l82, l84, l102, l106, l108, l110, l111, l118, l120;
    bool l53;
    int32_t l75;
    void* t0 = NULL;
    uint8_t t1;
    vader_string_t t2 = 0;
    int64_t t3;
    int32_t t4;
    bool t5;
    vader_box_t t6 = vader_box_null();
    double t7;
    uint32_t t8;
    vader_box_t* gc_roots[16] = {
        &l8, &l10, &l47, &l48, &l63, &l68, &l69, &l76, &l87, &l97, &l99, &l100, &l114, &l116, &l117,
        &t6,
    };
    void** gc_raw_roots[30] = {
        &l0, &l2, &l5, &l6, &l7, &l9, &l11, &l12, &l13, &l14, &l15, &l16, &l22, &l25, &l26, &l29,
        &l32, &l38, &l45, &l51, &l59, &l65, &l79, &l88, &l90, &l91, &l93, &l94, &l105, &t0,
    };
    vader_string_t* gc_atom_roots[13] = {
        &l20, &l27, &l33, &l34, &l46, &l54, &l55, &l64, &l67, &l77, &l98, &l115, &t2,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 16u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l7 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature)->f_params;
    l8 = ((vader_struct_vader_vm$VmState_t*) l0)->f_io;
    if (!(l8.tag == 0u)) {
        t0 = l8.payload.obj;
        l8 = vader_vm$serve_program_stream(t0, l5, l2, l3, l4);
        if (!(l8.tag == 0u)) {
            { vader_box_t __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l8 = vader_vm$foreign_call_of(l0, l1, l4);
    l10 = l8;
    if (l8.tag == 2128u) {
        t0 = l10.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l8.payload.obj;
    t1 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result_class;
    vader_array_t* _a1_arr = vader_array_new(31u, 1u, 1u, 628u);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (uint8_t) (int32_t) (uint8_t) t1;
    l11 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(30u, 0u, 8u, 627u);
    l12 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(30u, 0u, 8u, 627u);
    l13 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(31u, 0u, 1u, 628u);
    l14 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(449u, 0u, 13u, 2106u);
    l15 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(450u, 0u, 13u, 2107u);
    l16 = (void*) _a6_arr;
    l17 = INT64_C(0);
    l18 = vader_array_length(((vader_array_t*) l7));
    while ((l17 < l18)) {
        l19 = vader_chk_add(i64, l3, l17);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l19)
        l8 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l19];
        if (l8.tag == 2098u) {
            l20 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
            l21 = vader_host_std_core$Intrinsic$byte_len(l20);
            l22 = (void*) vader_buffer_new((size_t) (INT64_C(138) + l21));
            l23 = INT64_C(0);
            l23 = std_core$write_string_at(l22, l23, 2478u);
            l23 = std_core$write_string_at(l22, l23, l20);
            l23 = std_core$write_string_at(l22, l23, 1349u);
            l24 = ((int64_t) (int32_t) l4);
            l23 = std_core$write_int(l22, l23, l24);
            l23 = std_core$write_string_at(l22, l23, 573u);
            l23 = std_core$write_int(l22, l23, l17);
            l23 = std_core$write_string_at(l22, l23, 194u);
            t2 = std_core$finish_buffer(l22, l23);
            vader_struct_vader_vm$Trap_t* _a8_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a8_obj, 2128u);
            _a8_obj->f_message = t2;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l8.tag == 2125u) {
            l26 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature)->f_param_types;
            l10 = vader_vm$mirrored_struct_fields(l6, l26, l17);
            if (l10.tag == 0u) {
                l27 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
                l28 = vader_host_std_core$Intrinsic$byte_len(l27);
                l29 = (void*) vader_buffer_new((size_t) (INT64_C(112) + l28));
                l30 = INT64_C(0);
                l30 = std_core$write_string_at(l29, l30, 2478u);
                l30 = std_core$write_string_at(l29, l30, l27);
                l30 = std_core$write_string_at(l29, l30, 1349u);
                l31 = ((int64_t) (int32_t) l4);
                l30 = std_core$write_int(l29, l30, l31);
                l30 = std_core$write_string_at(l29, l30, 573u);
                l30 = std_core$write_int(l29, l30, l17);
                l30 = std_core$write_string_at(l29, l30, 196u);
                t2 = std_core$finish_buffer(l29, l30);
                vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a9_obj, 2128u);
                _a9_obj->f_message = t2;
                t0 = (void*) _a9_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l25 = l10.payload.obj;
            l32 = vader_core_bytecode$c_struct_layout(l25, l6);
            if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_unknown_field.tag == 0u)) {
                l33 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
                l34 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_unknown_field.payload.s;
                l35 = vader_host_std_core$Intrinsic$byte_len(l33);
                l36 = vader_host_std_core$Intrinsic$byte_len(l34);
                l37 = (l35 + l36);
                l38 = (void*) vader_buffer_new((size_t) (INT64_C(142) + l37));
                l39 = INT64_C(0);
                l39 = std_core$write_string_at(l38, l39, 2478u);
                l39 = std_core$write_string_at(l38, l39, l33);
                l39 = std_core$write_string_at(l38, l39, 1349u);
                l40 = ((int64_t) (int32_t) l4);
                l39 = std_core$write_int(l38, l39, l40);
                l39 = std_core$write_string_at(l38, l39, 573u);
                l39 = std_core$write_int(l38, l39, l17);
                l39 = std_core$write_string_at(l38, l39, 225u);
                l39 = std_core$write_string_at(l38, l39, l34);
                l39 = std_core$write_string_at(l38, l39, 1494u);
                t2 = std_core$finish_buffer(l38, l39);
                vader_struct_vader_vm$Trap_t* _a10_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a10_obj, 2128u);
                _a10_obj->f_message = t2;
                t0 = (void*) _a10_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l41 = vader_array_length(((vader_array_t*) l14));
            l42 = INT64_C(4096);
            t3 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_size;
            if ((t3 > l42)) {
                l43 = ((vader_struct_vader_core_bytecode$CLayout_t*) l32)->f_size;
            } else {
                l43 = l42;
            }
            l44 = INT64_C(0);
            while ((l44 < l43)) {
                vader_array_push_u8((vader_array_t*) l14, INT32_C(0));
                l44 = (l44 + INT64_C(1));
            }
            l45 = l8.payload.obj;
            l46 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
            l47 = vader_vm$serialise_mirror(l14, l41, l45, l25, l6, l4, l46, INT32_C(0));
            l48 = l47;
            if (l47.tag == 2128u) {
                t0 = l48.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t4 = (INT32_C(3) & INT32_C(255));
            l49 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l49);
            l50 = vader_array_length(((vader_array_t*) l12));
            vader_array_push_i64((vader_array_t*) l13, l50);
            vader_array_push_i64((vader_array_t*) l12, l41);
            t5 = vader_core_bytecode$param_is_c_out(((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature, l17);
            if (t5) {
                t0 = l8.payload.obj;
                vader_struct_vader_vm$LentStruct_t* _a11_obj = (vader_struct_vader_vm$LentStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$LentStruct_t));
                vader_obj_header_init(_a11_obj, 2107u);
                _a11_obj->f_target = t0;
                _a11_obj->f_at = l41;
                _a11_obj->f_fields = l25;
                l51 = (void*) _a11_obj;
                vader_array_push_ref((vader_array_t*) l16, l51);
            }
            l17 = (l17 + INT64_C(1));
            continue;
        }
        t5 = vader_core_bytecode$param_is_by_address(((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature, l17);
        if (t5) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            t6 = vader_array_read_u8(_a12_slotarr, vader_array_offset(_a12_slotarr) + (size_t) l17, 628u);
            t4 = vader_core_bytecode$size_of_val_type(((uint8_t) t6.payload.i));
            l52 = ((int64_t) (int32_t) t4);
            if (l52 == INT64_C(0)) {
                l53 = true;
            } else {
                l53 = (l52 > INT64_C(8));
            }
            if (l53) {
                l54 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                t6 = vader_array_read_u8(_a13_slotarr, vader_array_offset(_a13_slotarr) + (size_t) l17, 628u);
                l55 = vader_core_bytecode$val_type_name(((uint8_t) t6.payload.i));
                l56 = vader_host_std_core$Intrinsic$byte_len(l54);
                l57 = vader_host_std_core$Intrinsic$byte_len(l55);
                l58 = (l56 + l57);
                l59 = (void*) vader_buffer_new((size_t) (INT64_C(81) + l58));
                l60 = INT64_C(0);
                l60 = std_core$write_string_at(l59, l60, 2478u);
                l60 = std_core$write_string_at(l59, l60, l54);
                l60 = std_core$write_string_at(l59, l60, 1349u);
                l61 = ((int64_t) (int32_t) l4);
                l60 = std_core$write_int(l59, l60, l61);
                l60 = std_core$write_string_at(l59, l60, 570u);
                l60 = std_core$write_string_at(l59, l60, l55);
                l60 = std_core$write_string_at(l59, l60, 251u);
                t2 = std_core$finish_buffer(l59, l60);
                vader_struct_vader_vm$Trap_t* _a14_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a14_obj, 2128u);
                _a14_obj->f_message = t2;
                t0 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l63 = l8;
            l64 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
            l65 = (void*) vader_buffer_new((size_t) INT64_C(24));
            l66 = INT64_C(0);
            l66 = std_core$write_string_at(l65, l66, 2005u);
            l66 = std_core$write_int(l65, l66, l17);
            l67 = std_core$finish_buffer(l65, l66);
            l68 = vader_vm$lent_word(l63, l52, l4, l64, l67);
            l69 = l68;
            if (l68.tag == 2128u) {
                t0 = l69.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l62 = ((int64_t) l68.payload.i);
            t4 = (INT32_C(3) & INT32_C(255));
            l70 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l70);
            l71 = vader_array_length(((vader_array_t*) l12));
            vader_array_push_i64((vader_array_t*) l13, l71);
            l72 = vader_array_length(((vader_array_t*) l14));
            vader_array_push_i64((vader_array_t*) l12, l72);
            l73 = l62;
            vader_vm$push_little_endian(l14, l73, l52);
        } else if (l8.tag == 2093u) {
            t0 = l8.payload.obj;
            l75 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id;
            l76 = vader_vm$lent_element_val_type(l6, l75);
            if (l76.tag == 0u) {
                l77 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
                l78 = vader_host_std_core$Intrinsic$byte_len(l77);
                l79 = (void*) vader_buffer_new((size_t) (INT64_C(154) + l78));
                l80 = INT64_C(0);
                l80 = std_core$write_string_at(l79, l80, 2478u);
                l80 = std_core$write_string_at(l79, l80, l77);
                l80 = std_core$write_string_at(l79, l80, 1349u);
                l81 = ((int64_t) (int32_t) l4);
                l80 = std_core$write_int(l79, l80, l81);
                l80 = std_core$write_string_at(l79, l80, 573u);
                l80 = std_core$write_int(l79, l80, l17);
                l80 = std_core$write_string_at(l79, l80, 199u);
                t2 = std_core$finish_buffer(l79, l80);
                vader_struct_vader_vm$Trap_t* _a15_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a15_obj, 2128u);
                _a15_obj->f_message = t2;
                t0 = (void*) _a15_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l74 = ((uint8_t) l76.payload.i);
            t0 = l8.payload.obj;
            t3 = vader_vm$element_count(t0);
            if (t3 == INT64_C(0)) {
                t4 = (INT32_C(1) & INT32_C(255));
                l82 = (uint8_t) (int32_t) t4;
                vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l82);
                vader_array_push_i64((vader_array_t*) l12, INT64_C(0));
                l17 = (l17 + INT64_C(1));
                continue;
            }
            t4 = vader_core_bytecode$size_of_val_type(l74);
            l83 = ((int64_t) (int32_t) t4);
            t4 = (INT32_C(3) & INT32_C(255));
            l84 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l84);
            l85 = vader_array_length(((vader_array_t*) l12));
            vader_array_push_i64((vader_array_t*) l13, l85);
            l86 = vader_array_length(((vader_array_t*) l14));
            vader_array_push_i64((vader_array_t*) l12, l86);
            t0 = l8.payload.obj;
            l87 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_raw;
            if (l87.tag == 0u) {
                l91 = l8.payload.obj;
                l92 = vader_array_length(((vader_array_t*) l14));
                vader_struct_vader_vm$LentArray_t* _a16_obj = (vader_struct_vader_vm$LentArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$LentArray_t));
                vader_obj_header_init(_a16_obj, 2106u);
                _a16_obj->f_target = l91;
                _a16_obj->f_at = l92;
                _a16_obj->f_element = l74;
                l93 = (void*) _a16_obj;
                vader_array_push_ref((vader_array_t*) l15, l93);
                t0 = l8.payload.obj;
                l94 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_elements;
                l95 = vader_array_length(((vader_array_t*) l94));
                l96 = INT64_C(0);
                while ((l96 < l95)) {
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l94);
                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                    l97 = vader_array_box_slots(_a17_slotarr->buf)[vader_array_offset(_a17_slotarr) + (size_t) l96];
                    l98 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
                    l99 = vader_vm$lent_word(l97, l83, l4, l98, 2368u);
                    l100 = l99;
                    if (l99.tag == 2128u) {
                        t0 = l100.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l101 = ((int64_t) l99.payload.i);
                    vader_vm$push_little_endian(l14, l101, l83);
                    l96 = (l96 + INT64_C(1));
                }
            } else {
                l88 = l87.payload.obj;
                t0 = l87.payload.obj;
                l89 = ((vader_struct_vader_vm$StringWindow_t*) t0)->f_length;
                l90 = vader_vm$first_bytes(l88, l89);
                vader_array_push_all((vader_array_t*) l14, (vader_array_t*) l90);
            }
        } else if (l8.tag == 623u) {
            t4 = (INT32_C(3) & INT32_C(255));
            l102 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l102);
            l103 = vader_array_length(((vader_array_t*) l12));
            vader_array_push_i64((vader_array_t*) l13, l103);
            l104 = vader_array_length(((vader_array_t*) l14));
            vader_array_push_i64((vader_array_t*) l12, l104);
            t2 = l8.payload.s;
            l105 = vader_host_std_core$Intrinsic$bytes(t2);
            vader_array_push_all((vader_array_t*) l14, (vader_array_t*) l105);
            vader_array_push_u8((vader_array_t*) l14, INT32_C(0));
        } else if ((l8.tag == 632u || l8.tag == 633u)) {
            t4 = (INT32_C(2) & INT32_C(255));
            l106 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l106);
            t7 = ((double) l8.payload.f);
            l107 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t7 }).__vu));
            vader_array_push_i64((vader_array_t*) l12, l107);
        } else if (l8.tag == 621u) {
            t4 = (INT32_C(1) & INT32_C(255));
            l108 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l108);
            t5 = l8.payload.b;
            if (t5) {
                l109 = INT64_C(1);
            } else {
                l109 = INT64_C(0);
            }
            vader_array_push_i64((vader_array_t*) l12, l109);
        } else if (l8.tag == 2108u) {
            t4 = (INT32_C(1) & INT32_C(255));
            l110 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l110);
            vader_array_push_i64((vader_array_t*) l12, INT64_C(0));
        } else if (l8.tag == 622u) {
            t4 = (INT32_C(1) & INT32_C(255));
            l111 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l111);
            t8 = ((uint32_t) l8.payload.i);
            l112 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t8));
            vader_array_push_i64((vader_array_t*) l12, l112);
        } else {
            l114 = l8;
            l115 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_extern_name;
            l116 = vader_vm$extern_word(l114, l4, l115, l17);
            l117 = l116;
            if (l116.tag == 2128u) {
                t0 = l117.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l113 = ((int64_t) l116.payload.i);
            t4 = (INT32_C(1) & INT32_C(255));
            l118 = (uint8_t) (int32_t) t4;
            vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l118);
            l119 = l113;
            vader_array_t* _a18_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            t6 = vader_array_read_u8(_a18_slotarr, vader_array_offset(_a18_slotarr) + (size_t) l17, 628u);
            l120 = ((uint8_t) t6.payload.i);
            l121 = vader_vm$word_of_class(l119, l120);
            vader_array_push_i64((vader_array_t*) l12, l121);
        }
        l17 = (l17 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result_mirror;
    l17 = vader_array_length(((vader_array_t*) l14));
    if (!(l8.tag == 0u)) {
        l18 = INT64_C(0);
        t0 = l8.payload.obj;
        l19 = ((vader_struct_vader_vm$ResultMirror_t*) t0)->f_size;
        while ((l18 < l19)) {
            vader_array_push_u8((vader_array_t*) l14, INT32_C(0));
            l18 = (l18 + INT64_C(1));
        }
        t4 = (INT32_C(3) & INT32_C(255));
        l49 = (uint8_t) (int32_t) t4;
        vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l49);
        l18 = vader_array_length(((vader_array_t*) l12));
        vader_array_push_i64((vader_array_t*) l13, l18);
        vader_array_push_i64((vader_array_t*) l12, l17);
    }
    t3 = vader_array_length(((vader_array_t*) l12));
    l18 = vader_chk_mul(i64, t3, INT64_C(8));
    l7 = l13;
    l19 = vader_array_length(((vader_array_t*) l7));
    l21 = INT64_C(0);
    while ((l21 < l19)) {
        vader_array_t* _a19_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        l23 = ((int64_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l21];
        vader_array_t* _a20_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l23)
        t3 = ((int64_t*) _a20_slotarr->buf->slots)[vader_array_offset(_a20_slotarr) + (size_t) l23];
        l24 = vader_chk_add(i64, t3, l18);
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l23)
        ((int64_t*) _a20_slotarr->buf->slots)[vader_array_offset(_a20_slotarr) + (size_t) l23] = (int64_t) l24;
        l21 = (l21 + INT64_C(1));
    }
    vader_array_t* _a21_arr = vader_array_new(31u, 0u, 1u, 628u);
    l7 = (void*) _a21_arr;
    l19 = vader_array_length(((vader_array_t*) l12));
    l21 = INT64_C(0);
    while ((l21 < l19)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        l23 = ((int64_t*) _a22_slotarr->buf->slots)[vader_array_offset(_a22_slotarr) + (size_t) l21];
        vader_vm$push_little_endian(l7, l23, INT64_C(8));
        l21 = (l21 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l14);
    t3 = vader_array_length(((vader_array_t*) l7));
    if (t3 == INT64_C(0)) {
        if (((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result != INT32_C(14)) {
            vader_vm$push_little_endian(l7, INT64_C(0), INT64_C(8));
        }
    }
    l19 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_callee;
    l53 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_through_adapter;
    t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_c_variadic_fixed;
    l21 = ((int64_t) (int32_t) t4);
    l20 = vader_vm$call_foreign(l19, l53, l11, l7, l21);
    l5 = l15;
    l19 = vader_array_length(((vader_array_t*) l5));
    l21 = INT64_C(0);
    while ((l21 < l19)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l11 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) l21);
        t4 = vader_core_bytecode$size_of_val_type(((vader_struct_vader_vm$LentArray_t*) l11)->f_element);
        l23 = ((int64_t) (int32_t) t4);
        l24 = INT64_C(0);
        l28 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l11)->f_target)->f_elements));
        while ((l24 < l28)) {
            l12 = ((vader_struct_vader_vm$ArrayVal_t*) ((vader_struct_vader_vm$LentArray_t*) l11)->f_target)->f_elements;
            l30 = ((vader_struct_vader_vm$LentArray_t*) l11)->f_at;
            l31 = vader_chk_add(i64, l18, l30);
            l35 = vader_chk_mul(i64, l24, l23);
            l36 = vader_chk_add(i64, l31, l35);
            l49 = ((vader_struct_vader_vm$LentArray_t*) l11)->f_element;
            l10 = vader_vm$written_scalar(l7, l36, l23, l49);
            vader_array_t* _a24_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l24)
            vader_array_box_slots(_a24_slotarr->buf)[vader_array_offset(_a24_slotarr) + (size_t) l24] = l10;
            VADER_WRITE_BARRIER(_a24_slotarr->buf);
            l24 = (l24 + INT64_C(1));
        }
        l21 = (l21 + INT64_C(1));
    }
    l5 = l16;
    l19 = vader_array_length(((vader_array_t*) l5));
    l21 = INT64_C(0);
    while ((l21 < l19)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        l11 = vader_array_ref_load_obj(_a25_slotarr->buf, vader_array_offset(_a25_slotarr) + (size_t) l21);
        l23 = ((vader_struct_vader_vm$LentStruct_t*) l11)->f_at;
        l24 = vader_chk_add(i64, l18, l23);
        l12 = ((vader_struct_vader_vm$LentStruct_t*) l11)->f_target;
        l13 = ((vader_struct_vader_vm$LentStruct_t*) l11)->f_fields;
        vader_vm$read_back_mirror(l7, l24, l12, l13, l6, INT32_C(0));
        l21 = (l21 + INT64_C(1));
    }
    if (!(l8.tag == 0u)) {
        l17 = vader_chk_add(i64, l18, l17);
        t0 = l8.payload.obj;
        l75 = ((vader_struct_vader_vm$ResultMirror_t*) t0)->f_type_index;
        t0 = l8.payload.obj;
        l5 = ((vader_struct_vader_vm$ResultMirror_t*) t0)->f_mirror;
        t0 = vader_vm$mirror_value(l7, l17, l75, l5, l6);
        vader_struct_vader_vm$HostOk_t* _a26_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a26_obj, 2105u);
        _a26_obj->f_value = vader_ref_box(t0);
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result == INT32_C(14)) {
        t6 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a27_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a27_obj, 2105u);
        _a27_obj->f_value = t6;
        t0 = (void*) _a27_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result == INT32_C(9)) {
        l53 = true;
    } else {
        l53 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result == INT32_C(8);
    }
    if (l53) {
        t3 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), false);
        vader_struct_vader_vm$HostOk_t* _a28_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a28_obj, 2105u);
        _a28_obj->f_value = vader_box_f64(633u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t3) }).__vd));
        t0 = (void*) _a28_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t5 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_null_on_zero;
    if (t5) {
        t3 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), false);
        if (t3 == INT64_C(0)) {
            t0 = (void*) &vader_data_103;
            vader_array_t* _a29_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            t0 = vader_array_ref_load_obj(_a29_slotarr->buf, vader_array_offset(_a29_slotarr) + (size_t) INT64_C(0));
            vader_struct_vader_vm$HostOk_t* _a30_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
            vader_obj_header_init(_a30_obj, 2105u);
            _a30_obj->f_value = vader_ref_box(t0);
            t0 = (void*) _a30_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l49 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result_class;
    t4 = (INT32_C(4) & INT32_C(255));
    l70 = (uint8_t) (int32_t) t4;
    if (l49 == l70) {
        l53 = true;
    } else {
        l49 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result_class;
        t4 = (INT32_C(5) & INT32_C(255));
        l70 = (uint8_t) (int32_t) t4;
        l53 = l49 == l70;
    }
    if (!(l53)) {
        l49 = ((vader_struct_vader_vm$ForeignCall_t*) l9)->f_result;
        l17 = vader_vm$read_little_endian(l7, INT64_C(0), INT64_C(8), true);
        t6 = vader_vm$extern_result(l49, l17);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a31_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a31_obj, 2105u);
    _a31_obj->f_value = vader_box_string(623u, l20);
    t0 = (void*) _a31_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$dispatch_import(void* l0, void* l1, int64_t l2, void* l3, int32_t l4, int32_t l5, int32_t l6, bool l7, uint8_t l8) {
    vader_box_t l9 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    bool l12;
    void* l13 = NULL;
    int64_t l15, l16;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_string_t t4 = 0;
    int64_t t3;
    uint8_t t5;
    vader_box_t* gc_roots[3] = { &l9, &l14, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l13, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l11, &t2, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l7) {
        l9 = vader_vm$comptime_refusal(l8);
        if (!(l9.tag == 0u)) {
            l10 = vader_core_bytecode$display_intrinsic(l8);
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
    if (l12) {
        l12 = true;
    } else {
        l12 = l8 == INT32_C(7);
    }
    if (!(l12)) {
        if (!(l8 == INT32_C(13))) {
            if (l8 == INT32_C(6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
                t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l2];
                l9 = vader_vm$read_array(t0, l4, 2160u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l13 = l9.payload.obj;
                l15 = vader_vm$element_count(l13);
                l9 = vader_vm$array_bytes(l13, l15, l4, 2159u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l9.payload.obj;
                t2 = vader_host_std_core$Intrinsic$bytes_to_string(t1);
                vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a1_obj, 2105u);
                _a1_obj->f_value = vader_box_string(623u, t2);
                t1 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(5)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                t0 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2154u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = l9.payload.s;
                t1 = vader_vm$bytes_to_value(t2, l6);
                vader_struct_vader_vm$HostOk_t* _a3_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a3_obj, 2105u);
                _a3_obj->f_value = vader_ref_box(t1);
                t1 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(26)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
                t3 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) INT32_C(0)];
                l15 = vader_chk_add(i64, t3, INT64_C(1));
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
                ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) INT32_C(0)] = (int64_t) l15;
                t1 = (void*) &vader_data_103;
                vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t1 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
                vader_struct_vader_vm$HostOk_t* _a6_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a6_obj, 2105u);
                _a6_obj->f_value = vader_ref_box(t1);
                t1 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(27)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(0))
                t3 = ((int64_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) INT32_C(0)];
                vader_struct_vader_vm$HostOk_t* _a8_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a8_obj, 2105u);
                _a8_obj->f_value = vader_box_i64(627u, t3);
                t1 = (void*) _a8_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(28)) {
                vader_struct_vader_vm$HostOk_t* _a9_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a9_obj, 2105u);
                _a9_obj->f_value = vader_box_i64(627u, INT64_C(0));
                t1 = (void*) _a9_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(29)) {
                vader_struct_vader_vm$HostOk_t* _a10_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a10_obj, 2105u);
                _a10_obj->f_value = vader_box_i64(627u, INT64_C(0));
                t1 = (void*) _a10_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(30)) {
                vader_struct_vader_vm$HostOk_t* _a11_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a11_obj, 2105u);
                _a11_obj->f_value = vader_box_i64(627u, INT64_C(0));
                t1 = (void*) _a11_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(31)) {
                vader_struct_vader_vm$HostOk_t* _a12_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a12_obj, 2105u);
                _a12_obj->f_value = vader_box_i64(627u, INT64_C(0));
                t1 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(32)) {
                t1 = (void*) &vader_data_103;
                vader_array_t* _a13_slotarr = ((vader_array_t*) t1);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                t1 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) INT64_C(0));
                vader_struct_vader_vm$HostOk_t* _a14_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a14_obj, 2105u);
                _a14_obj->f_value = vader_ref_box(t1);
                t1 = (void*) _a14_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(44)) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(45);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(46);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(47);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(48);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(49);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(41);
            }
            if (l12) {
                t1 = (void*) &vader_data_103;
                vader_array_t* _a15_slotarr = ((vader_array_t*) t1);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                t1 = vader_array_ref_load_obj(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) INT64_C(0));
                vader_struct_vader_vm$HostOk_t* _a16_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a16_obj, 2105u);
                _a16_obj->f_value = vader_ref_box(t1);
                t1 = (void*) _a16_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(33)) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(34);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(35);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(36);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(37);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(50);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(38);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(39);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(40);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(42);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(43);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(51);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(52);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(53);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(54);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(55);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(56);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(57);
            }
            if (l12) {
                t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
                t4 = concat_2(t2, 571u);
                vader_struct_vader_vm$Trap_t* _a17_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a17_obj, 2128u);
                _a17_obj->f_message = t4;
                t1 = (void*) _a17_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(61)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l2)
                t0 = vader_array_box_slots(_a18_slotarr->buf)[vader_array_offset(_a18_slotarr) + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2507u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = l9.payload.s;
                t3 = vader_host_std_core$Intrinsic$ffi_open(t2);
                vader_struct_vader_vm$HostOk_t* _a19_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a19_obj, 2105u);
                _a19_obj->f_value = vader_box_i64(627u, t3);
                t1 = (void*) _a19_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(63)) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l2)
                t0 = vader_array_box_slots(_a20_slotarr->buf)[vader_array_offset(_a20_slotarr) + (size_t) l2];
                l9 = vader_vm$read_i64(t0, l4, 2511u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l15 = ((int64_t) l9.payload.i);
                l16 = vader_chk_add(i64, l2, INT64_C(1));
                vader_array_t* _a21_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l16)
                t0 = vader_array_box_slots(_a21_slotarr->buf)[vader_array_offset(_a21_slotarr) + (size_t) l16];
                l9 = vader_vm$read_string(t0, l4, 2512u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l9.payload.s;
                t3 = vader_host_std_core$Intrinsic$ffi_symbol(l15, l10);
                vader_struct_vader_vm$HostOk_t* _a22_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a22_obj, 2105u);
                _a22_obj->f_value = vader_box_i64(627u, t3);
                t1 = (void*) _a22_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(62)) {
                vader_array_t* _a23_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l2)
                t0 = vader_array_box_slots(_a23_slotarr->buf)[vader_array_offset(_a23_slotarr) + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 2509u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = l9.payload.s;
                t3 = vader_host_std_core$Intrinsic$ffi_open_path(t2);
                vader_struct_vader_vm$HostOk_t* _a24_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a24_obj, 2105u);
                _a24_obj->f_value = vader_box_i64(627u, t3);
                t1 = (void*) _a24_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(64)) {
                l9 = vader_vm$hosted_frame_call(l1, l2, l4, 2504u, false);
                l14 = l9;
                if (!(l9.tag == 2128u)) {
                    t0 = vader_vm$zero_value();
                    vader_struct_vader_vm$HostOk_t* _a25_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                    vader_obj_header_init(_a25_obj, 2105u);
                    _a25_obj->f_value = t0;
                    t1 = (void*) _a25_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = l14.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(65)) {
                l9 = vader_vm$hosted_frame_call(l1, l2, l4, 2505u, true);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = l9.payload.s;
                vader_struct_vader_vm$HostOk_t* _a26_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a26_obj, 2105u);
                _a26_obj->f_value = vader_box_string(623u, t2);
                t1 = (void*) _a26_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(59)) {
                t5 = vader_host_std_core$Intrinsic$current_os();
                vader_struct_vader_vm$HostOk_t* _a27_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a27_obj, 2105u);
                _a27_obj->f_value = vader_box_i32(626u, ((int32_t) (uint8_t) t5));
                t1 = (void*) _a27_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(60)) {
                t5 = vader_host_std_core$Intrinsic$current_arch();
                vader_struct_vader_vm$HostOk_t* _a28_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
                vader_obj_header_init(_a28_obj, 2105u);
                _a28_obj->f_value = vader_box_i32(626u, ((int32_t) (uint8_t) t5));
                t1 = (void*) _a28_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(58)) {
                vader_array_t* _a29_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l2)
                t0 = vader_array_box_slots(_a29_slotarr->buf)[vader_array_offset(_a29_slotarr) + (size_t) l2];
                l9 = vader_vm$read_string(t0, l4, 3050u);
                l14 = l9;
                if (l9.tag == 2128u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l9.payload.s;
                t2 = concat_2(3052u, l10);
                vader_struct_vader_vm$Trap_t* _a30_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a30_obj, 2128u);
                _a30_obj->f_message = t2;
                t1 = (void*) _a30_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l8 == INT32_C(0)) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(8);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(9);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(10);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(11);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(12);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(14);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(15);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(16);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(17);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(18);
            }
            if (l12) {
                l12 = true;
            } else {
                l12 = l8 == INT32_C(19);
            }
            if (l12) {
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
            if (!(l12)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    l10 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l15 = vader_host_std_core$Intrinsic$byte_len(l10);
    l13 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l15));
    l15 = INT64_C(0);
    l15 = std_core$write_string_at(l13, l15, 3456u);
    l15 = std_core$write_string_at(l13, l15, l10);
    l15 = std_core$write_string_at(l13, l15, 369u);
    l16 = ((int64_t) (int32_t) l4);
    l15 = std_core$write_int(l13, l15, l16);
    t2 = std_core$finish_buffer(l13, l15);
    vader_struct_vader_vm$Trap_t* _a31_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a31_obj, 2128u);
    _a31_obj->f_message = t2;
    t1 = (void*) _a31_obj;
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
        { vader_gc_top = gc_frame.prev; return 3002u; }
    }
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = INT64_C(0);
    t0 = (void*) &vader_data_31;
    l4 = vader_array_length(((vader_array_t*) t0));
    while ((l3 < l4)) {
        t1 = (((int32_t) (int64_t) l3) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        t1 = ((INT32_C(1) << (l5 & 31)) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t1;
        if ((l0 & l6) != INT32_C(0)) {
            if (!(l2)) {
                std_string__builder$append(l1, 3782u);
            }
            t0 = (void*) &vader_data_31;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t2 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l3];
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
    if (l0.tag == 626u) {
        t0 = ((int32_t) l0.payload.i);
        l1 = vader_vm$I32Val$std_core$Display$to_string(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 627u) {
        t1 = ((int64_t) l0.payload.i);
        l1 = vader_vm$I64Val$std_core$Display$to_string(t1);
    } else if ((l0.tag == 632u || l0.tag == 633u)) {
        t2 = ((double) l0.payload.f);
        l1 = vader_vm$F64Val$std_core$Display$to_string(t2);
    } else if (l0.tag == 623u) {
        t3 = l0.payload.s;
        l1 = vader_vm$StringVal$std_core$Display$to_string(t3);
    } else if (l0.tag == 2125u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$StructVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 2093u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$ArrayVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 2098u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$FnVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 2108u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$NullVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 2133u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$VoidVal$std_core$Display$to_string(t4);
    } else if (l0.tag == 621u) {
        t5 = l0.payload.b;
        l1 = vader_vm$BoolVal$std_core$Display$to_string(t5);
    } else if (l0.tag == 622u) {
        t6 = ((uint32_t) l0.payload.i);
        l1 = vader_vm$CharVal$std_core$Display$to_string(t6);
    } else if (l0.tag == 2129u) {
        t4 = l0.payload.obj;
        l1 = vader_vm$TypeVal$std_core$Display$to_string(t4);
    } else {
        if (!(l0.tag == 2109u)) {
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
    l4 = vader_host_std_core$Intrinsic$byte_len(l1);
    l5 = vader_host_std_core$Intrinsic$byte_len(l3);
    l4 = (l4 + l5);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(33) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l6, l4, l1);
    l4 = std_core$write_string_at(l6, l4, 130u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l6, l4, l5);
    l4 = std_core$write_string_at(l6, l4, 187u);
    l4 = std_core$write_string_at(l6, l4, l3);
    l4 = std_core$write_string_at(l6, l4, 362u);
    t0 = std_core$finish_buffer(l6, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$do_memory_copy(void* l0) {
    int32_t l1, l5, l7, l8;
    int64_t l2, l12, l13, l14, l15;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    bool l10;
    uint8_t l17;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t4 };
    void** gc_raw_roots[6] = { &l0, &l6, &l9, &l11, &l16, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l1 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l1, 2903u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = vader_vm$peek_val(l0, l2);
    l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l5, 2907u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l3 = vader_vm$peek_val(l0, l2);
    l7 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_obj(l3, l7, 2906u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l3.payload.obj;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(4));
    l3 = vader_vm$peek_val(l0, l2);
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l8, 2902u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(5));
    l3 = vader_vm$peek_val(l0, l2);
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_obj(l3, l8, 2901u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l3.payload.obj;
    if ((l1 < INT32_C(0))) {
        l10 = true;
    } else {
        l10 = (l5 < INT32_C(0));
    }
    if (l10) {
        l10 = true;
    } else {
        l10 = (l7 < INT32_C(0));
    }
    if (l10) {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(61));
        l2 = INT64_C(0);
        l2 = std_core$write_string_at(l11, l2, 2904u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l12 = ((int64_t) (int32_t) t2);
        l2 = std_core$write_int(l11, l2, l12);
        t3 = std_core$finish_buffer(l11, l2);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int64_t) (int32_t) l1);
    l12 = ((int64_t) (int32_t) l5);
    l13 = ((int64_t) (int32_t) l7);
    l14 = vader_chk_add(i64, l12, l2);
    l15 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l6)->f_bytes));
    if ((l14 > l15)) {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(125));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l11, l14, 2905u);
        l14 = std_core$write_int(l11, l14, l12);
        l14 = std_core$write_string_at(l11, l14, 444u);
        l15 = vader_chk_add(i64, l12, l2);
        l14 = std_core$write_int(l11, l14, l15);
        l14 = std_core$write_string_at(l11, l14, 407u);
        l15 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l6)->f_bytes));
        l14 = std_core$write_int(l11, l14, l15);
        l14 = std_core$write_string_at(l11, l14, 130u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l15 = ((int64_t) (int32_t) t2);
        l14 = std_core$write_int(l11, l14, l15);
        t3 = std_core$finish_buffer(l11, l14);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l14 = vader_chk_add(i64, l13, l2);
    l15 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l9)->f_bytes));
    if ((l14 > l15)) {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(123));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l11, l14, 2900u);
        l14 = std_core$write_int(l11, l14, l13);
        l14 = std_core$write_string_at(l11, l14, 444u);
        l15 = vader_chk_add(i64, l13, l2);
        l14 = std_core$write_int(l11, l14, l15);
        l14 = std_core$write_string_at(l11, l14, 407u);
        l15 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l9)->f_bytes));
        l14 = std_core$write_int(l11, l14, l15);
        l14 = std_core$write_string_at(l11, l14, 130u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l15 = ((int64_t) (int32_t) t2);
        l14 = std_core$write_int(l11, l14, l15);
        t3 = std_core$finish_buffer(l11, l14);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 2128u);
        _a2_obj->f_message = t3;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_reserve(31u, (int64_t) l2, 1u, 628u);
    l11 = (void*) _a3_arr;
    l14 = INT64_C(0);
    vader_array_t* _pc349_hdr = (vader_array_t*) l11;
    size_t _pc349_len = vader_array_length(_pc349_hdr);
    size_t _pc349_cap = vader_array_is_borrowed(_pc349_hdr) ? (size_t) 0 : vader_array_capacity(_pc349_hdr);
    void* _pc349_slots = _pc349_hdr->buf->slots;
    for (;;) {
        if ((l14 < l2)) {
            l16 = ((vader_struct_vader_vm$ObjVal_t*) l6)->f_bytes;
            l15 = vader_chk_add(i64, l12, l14);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
            t4 = vader_array_read_u8(_a4_slotarr, vader_array_offset(_a4_slotarr) + (size_t) l15, 628u);
            l17 = ((uint8_t) t4.payload.i);
            if (VADER_LIKELY(_pc349_len < _pc349_cap)) {
                ((uint8_t*) _pc349_slots)[_pc349_len] = (uint8_t) ((int32_t) (uint8_t) l17);
                _pc349_len += 1;
            } else {
                vader_array_set_length(_pc349_hdr, _pc349_len);
                if (_pc349_hdr->buf->length < _pc349_len) {
                    _pc349_hdr->buf->length = _pc349_len;
                }
                vader_array_push_u8((vader_array_t*) l11, (int32_t) (uint8_t) l17);
                _pc349_hdr = (vader_array_t*) l11;
                _pc349_len = vader_array_length(_pc349_hdr);
                _pc349_cap = vader_array_is_borrowed(_pc349_hdr) ? (size_t) 0 : vader_array_capacity(_pc349_hdr);
                _pc349_slots = _pc349_hdr->buf->slots;
            }
            l14 = (l14 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc349_hdr, _pc349_len);
        if (_pc349_hdr->buf->length < _pc349_len) {
            _pc349_hdr->buf->length = _pc349_len;
        }
        break;
    }
    l12 = INT64_C(0);
    while ((l12 < l2)) {
        l6 = ((vader_struct_vader_vm$ObjVal_t*) l9)->f_bytes;
        l14 = vader_chk_add(i64, l13, l12);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l12)
        t4 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l12, 628u);
        l17 = ((uint8_t) t4.payload.i);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l14)
        ((uint8_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l14] = (uint8_t) (int32_t) (uint8_t) l17;
        l12 = (l12 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(5));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l1 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l1;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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

vader_box_t vader_vm$element_at(void* l0, int64_t l1) {
    vader_box_t l2;
    void* t0;
    uint8_t t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        t1 = vader_vm$byte_at(t0, l1);
        return vader_box_i32(626u, ((int32_t) (uint8_t) t1));
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t2 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l1];
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
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements));
    return t1;
}

static vader_string_t vader_vm$element_label(int32_t l0) {
    if (l0 == INT32_C(116)) {
        return 2837u;
    }
    if (l0 == INT32_C(117)) {
        return 3228u;
    }
    if (!(l0 == INT32_C(115))) {
        return 2029u;
    }
    return 2044u;
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
    l3 = vader_array_length(((vader_array_t*) l2));
    t0 = vader_vm$in_range(l1, l3);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        if (l4.tag == 1273u) {
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
        t0 = vader_vm$receiver_trap(l0, l8, l4, l5, l7, 2015u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l10.payload.obj;
    l11 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
    l8 = ((int64_t) (int32_t) l3);
    l8 = vader_chk_add(i64, l1, l8);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t1 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l8];
    l12 = ((int32_t) (int64_t) t1);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l4)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l13 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
    l8 = vader_host_std_core$Intrinsic$byte_len(l7);
    l11 = (void*) vader_buffer_new((size_t) (INT64_C(95) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l11, l8, l7);
    l8 = std_core$write_string_at(l11, l8, 189u);
    l14 = ((int64_t) (int32_t) l12);
    l8 = std_core$write_int(l11, l8, l14);
    l8 = std_core$write_string_at(l11, l8, 245u);
    l14 = vader_vm$element_count(l9);
    l8 = std_core$write_int(l11, l8, l14);
    l8 = std_core$write_string_at(l11, l8, 406u);
    l14 = ((int64_t) (int32_t) l13);
    l8 = std_core$write_int(l11, l8, l14);
    t2 = std_core$finish_buffer(l11, l8);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 2128u);
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
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_source_pc));
    if ((l1 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_source_pc);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l7 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
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
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 627u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(31u, 0u, 1u, 628u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l3 = (void*) _a2_arr;
    l4 = vader_vm$new_run_host();
    l5 = vader_vm$scratch_frame();
    vader_array_t* _a3_arr = vader_array_new(456u, 0u, 13u, 2117u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(30u, 0u, 8u, 627u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(30u, 0u, 8u, 627u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l9 = (void*) _a6_arr;
    t0 = (void*) &vader_data_103;
    vader_array_t* _a7_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    l10 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) INT64_C(0));
    vader_struct_vader_vm$RegMachine_t* _a8_obj = (vader_struct_vader_vm$RegMachine_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegMachine_t));
    vader_obj_header_init(_a8_obj, 2118u);
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
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3] = (uint8_t) INT32_C(5);
        l3 = (l3 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_vm$RegFunction_t*) l1)->f_slots;
    l3 = vader_chk_add(i64, l2, l3);
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_consts));
    while ((l4 < l5)) {
        l6 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        l7 = vader_chk_add(i64, l3, l4);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_consts);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l8 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l7] = (int64_t) l8;
        l9 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags;
        l10 = vader_chk_add(i64, l3, l4);
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l1)->f_const_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l4, 628u);
        l11 = ((uint8_t) t0.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l11;
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$entry_args(void* l0, void* l1, vader_box_t l2, int32_t l3) {
    int64_t l4, l7;
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l8, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        t0 = vader_vm$build_main_args(l0, l1, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params));
    t1 = l2.payload.obj;
    t2 = vader_array_length(((vader_array_t*) t1));
    if (!(t2 != l4)) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = (void*) vader_buffer_new((size_t) INT64_C(75));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l6, l7, 3282u);
    l7 = std_core$write_int(l6, l7, l4);
    l7 = std_core$write_string_at(l6, l7, 254u);
    t1 = l2.payload.obj;
    l4 = vader_array_length(((vader_array_t*) t1));
    l7 = std_core$write_int(l6, l7, l4);
    l5 = std_core$finish_buffer(l6, l7);
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_name;
    t3 = concat_4(2400u, l8, 363u, l5);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 2128u);
    _a0_obj->f_message = t3;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$entry_named(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections$Map$std_core$Index$at__string__i32(((vader_struct_vader_vm$VmState_t*) l0)->f_fn_index_by_name, l1);
    if (l2.tag == 0u) {
        t0 = concat_3(2977u, l1, 362u);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l2.payload.i);
    { vader_box_t __vret = vader_box_i32(626u, t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2112u);
    l3 = (void*) _a0_arr;
    vader_struct_vader_vm$PauseCtx_t* _a1_obj = (vader_struct_vader_vm$PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseCtx_t));
    vader_obj_header_init(_a1_obj, 2111u);
    _a1_obj->f_reason = 2429u;
    _a1_obj->f_text = l0;
    _a1_obj->f_thread_id = l1;
    _a1_obj->f_frames = l3;
    _a1_obj->f_threads = l2;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_copy(void* l0) {
    int32_t l1, l5, l7, l8;
    int64_t l2, l10, l11, l12, l13;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    void* l9 = NULL;
    void* l14 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[5] = { &l0, &l6, &l9, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l1 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l1, 2025u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = vader_vm$peek_val(l0, l2);
    l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l5, 2024u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l7 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$peek_array_mut(l0, l2, l7, 2023u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l3.payload.obj;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(4));
    l3 = vader_vm$peek_val(l0, l2);
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l8, 2028u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(5));
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$peek_array_mut(l0, l2, l8, 2027u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l3.payload.obj;
    l2 = vader_vm$clamp_nonneg(l1);
    l10 = vader_vm$clamp_nonneg(l7);
    l11 = vader_vm$clamp_nonneg(l5);
    l12 = vader_chk_add(i64, l10, l2);
    l13 = vader_vm$element_count(l9);
    if ((l12 > l13)) {
        l14 = (void*) vader_buffer_new((size_t) INT64_C(64));
        l12 = INT64_C(0);
        l12 = std_core$write_string_at(l14, l12, 2026u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core$write_int(l14, l12, l13);
        t3 = std_core$finish_buffer(l14, l12);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = vader_chk_add(i64, l11, l2);
    l13 = vader_vm$element_count(l6);
    if ((l12 > l13)) {
        l14 = (void*) vader_buffer_new((size_t) INT64_C(103));
        l12 = INT64_C(0);
        l12 = std_core$write_string_at(l14, l12, 2022u);
        t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l13 = ((int64_t) (int32_t) t2);
        l12 = std_core$write_int(l14, l12, l13);
        t3 = std_core$finish_buffer(l14, l12);
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = t3;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_reserve(503u, (int64_t) l2, 0u, 3020u);
    l14 = (void*) _a2_arr;
    l12 = INT64_C(0);
    while ((l12 < l2)) {
        l13 = vader_chk_add(i64, l10, l12);
        l3 = vader_vm$element_at(l9, l13);
        vader_array_push((vader_array_t*) l14, l3);
        l12 = (l12 + INT64_C(1));
    }
    vader_vm$own_bytes(l6);
    l10 = INT64_C(0);
    while ((l10 < l2)) {
        l9 = ((vader_struct_vader_vm$ArrayVal_t*) l6)->f_elements;
        l12 = vader_chk_add(i64, l11, l10);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
        l3 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l10];
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
        vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l12] = l3;
        VADER_WRITE_BARRIER(_a4_slotarr->buf);
        l10 = (l10 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(5));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l1 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l1;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_push_all(void* l0) {
    void* l1 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l2, l9;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l6, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l2, l3, 2036u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l4.payload.obj;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l2, l3, 2035u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l4.payload.obj;
    vader_vm$own_bytes(l6);
    if (((vader_struct_vader_vm$ArrayVal_t*) l1)->f_raw.tag == 0u) {
        l7 = ((vader_struct_vader_vm$ArrayVal_t*) l6)->f_elements;
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_elements;
        vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l8);
    } else {
        l2 = INT64_C(0);
        l9 = vader_vm$element_count(l1);
        while ((l2 < l9)) {
            l7 = ((vader_struct_vader_vm$ArrayVal_t*) l6)->f_elements;
            l4 = vader_vm$element_at(l1, l2);
            vader_array_push((vader_array_t*) l7, l4);
            l2 = (l2 + INT64_C(1));
        }
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l3;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_repeat(void* l0) {
    int32_t l1, l6;
    int64_t l2, l7, l9, l10;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l1 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l1, 2040u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l6 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$peek_array_mut(l0, l2, l6, 2041u);
    l4 = l3;
    if (l3.tag == 2128u) {
        t1 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3.payload.obj;
    l2 = vader_vm$clamp_nonneg(l1);
    l7 = vader_vm$element_count(l5);
    t0 = vader_chk_mul(i64, l2, l7);
    vader_array_t* _a0_arr = vader_array_reserve(503u, (int64_t) t0, 0u, 3020u);
    l8 = (void*) _a0_arr;
    l9 = INT64_C(0);
    while ((l9 < l2)) {
        l10 = INT64_C(0);
        while ((l10 < l7)) {
            l3 = vader_vm$element_at(l5, l10);
            vader_array_push((vader_array_t*) l8, l3);
            l10 = (l10 + INT64_C(1));
        }
        l9 = (l9 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    t2 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a1_obj, 2093u);
    _a1_obj->f_type_id = t2;
    _a1_obj->f_elements = l8;
    _a1_obj->f_raw = vader_box_obj(0u, NULL);
    l5 = (void*) _a1_obj;
    vader_vm$push_val(l0, l2, vader_ref_box(l5));
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l1 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l1;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_reserve(void* l0, void* l1) {
    int64_t l2;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    int32_t l4;
    void* l6 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l3, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l4, 2043u);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l3.payload.i);
    t0 = vader_vm$clamp_nonneg(t2);
    vader_array_t* _a0_arr = vader_array_reserve(503u, (int64_t) t0, 0u, 3020u);
    l6 = (void*) _a0_arr;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    t2 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) l1)->f_type_id;
    vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a1_obj, 2093u);
    _a1_obj->f_type_id = t2;
    _a1_obj->f_elements = l6;
    _a1_obj->f_raw = vader_box_obj(0u, NULL);
    l6 = (void*) _a1_obj;
    vader_vm$push_val(l0, l2, vader_ref_box(l6));
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_array_slice(void* l0, void* l1) {
    int32_t l2, l6, l8;
    int64_t l3, l9, l10;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l7 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    l4 = vader_vm$peek_val(l0, l3);
    l2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l2, 2046u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l4.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(2));
    l4 = vader_vm$peek_val(l0, l3);
    l6 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$read_i32(l4, l6, 2047u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int32_t) l4.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(3));
    l8 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_vm$peek_array_mut(l0, l3, l8, 2048u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l4.payload.obj;
    l3 = vader_vm$element_count(l7);
    l9 = vader_vm$clamp_nonneg(l6);
    if ((l9 > l3)) {
        l9 = l3;
    }
    l10 = vader_vm$clamp_nonneg(l2);
    if ((l10 < l9)) {
        l10 = l9;
    }
    if ((l10 > l3)) {
        l10 = l3;
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(3));
    l2 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) l1)->f_type_id;
    l7 = vader_vm$view_of(l7, l2, l9, l10);
    vader_vm$push_val(l0, l3, vader_ref_box(l7));
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l3 = vader_chk_sub(i64, t0, INT64_C(2));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l3;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l2 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l2;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$exec_buffer_write_string(void* l0) {
    vader_string_t l1 = 0;
    int64_t l2, l8, l9, l11;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    int32_t l4, l6;
    void* l7 = NULL;
    void* l10 = NULL;
    uint8_t l12;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l3, &l5 };
    void** gc_raw_roots[4] = { &l0, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_string(l3, l4, 2127u);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l3.payload.s;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = vader_vm$peek_val(l0, l2);
    l6 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_i32(l3, l6, 2125u);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l3.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    l3 = vader_vm$peek_val(l0, l2);
    l6 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_obj(l3, l6, 2126u);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l3.payload.obj;
    l2 = vader_host_std_core$Intrinsic$byte_len(l1);
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l7)->f_bytes));
    l6 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$check_byte_range(l4, l2, l8, 2124u, l6);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int64_t) l3.payload.i);
    l8 = INT64_C(0);
    l9 = vader_host_std_core$Intrinsic$byte_len(l1);
    while ((l8 < l9)) {
        l10 = ((vader_struct_vader_vm$ObjVal_t*) l7)->f_bytes;
        l11 = vader_chk_add(i64, l2, l8);
        l12 = vader_host_std_core$Intrinsic$byte_at(l1, l8);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l11)
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l11] = (uint8_t) (int32_t) (uint8_t) l12;
        l8 = (l8 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_vm$exec_comptime_value(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = vader_vm$run_for_value(l0, l1, true);
    return t0;
}

static vader_box_t vader_vm$exec_string_compare(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l6 = 0;
    int64_t l2, l8;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    int32_t l4;
    void* l7 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l3, &l5 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_string(l3, l4, 3239u);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l3.payload.s;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    l3 = vader_vm$peek_val(l0, l2);
    l4 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l3 = vader_vm$read_string(l3, l4, 3239u);
    l5 = l3;
    if (l3.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l3.payload.s;
    l7 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    l8 = ((int64_t) (int32_t) vader_string_compare(l1, l6));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2] = (int64_t) l8;
    l7 = ((vader_struct_vader_vm$Frame_t*) l0)->f_tag;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(2));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l2] = (uint8_t) INT32_C(0);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l2;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$extern_result(uint8_t l0, int64_t l1) {
    bool l2;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = 2479u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        t1 = vader_vm$zero_value();
        vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a1_obj, 2105u);
        _a1_obj->f_value = t1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a2_obj, 2105u);
        _a2_obj->f_value = vader_box_bool(621u, ((int32_t) (int64_t) (l1 & INT64_C(4294967295))) != INT32_C(0));
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
        vader_obj_header_init(_a3_obj, 2105u);
        _a3_obj->f_value = vader_box_i64(627u, l1);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_vm$word_of_class(l1, l0);
    vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a4_obj, 2105u);
    _a4_obj->f_value = vader_box_i32(626u, ((int32_t) (int64_t) t2));
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
    if (!(l0.tag == 627u)) {
        l4 = l0;
        l5 = l2;
        l6 = vader_host_std_core$Intrinsic$byte_len(l5);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(34) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l7, l6, 2478u);
        l6 = std_core$write_string_at(l7, l6, l5);
        l6 = std_core$write_string_at(l7, l6, 1347u);
        l6 = std_core$write_int(l7, l6, l3);
        l5 = std_core$finish_buffer(l7, l6);
        t0 = vader_vm$read_i64(l4, l1, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int64_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(627u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_vm$f64_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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
    l4 = vader_array_length(((vader_array_t*) l0));
    if ((l3 >= l4)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l5.tag == 1287u)) {
        return false;
    }
    t0 = l5.payload.obj;
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants));
    if (t1 != INT64_C(2)) {
        return false;
    }
    l6 = false;
    l7 = false;
    t0 = l5.payload.obj;
    l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
    l3 = vader_array_length(((vader_array_t*) l8));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
        if (!((l9 < INT32_C(0)))) {
            l10 = ((int64_t) (int32_t) l9);
            l11 = vader_array_length(((vader_array_t*) l0));
            if (!((l10 >= l11))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
                l5 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
                if (l5.tag == 1283u) {
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
    l4 = vader_array_length(((vader_array_t*) l3));
    t0 = vader_vm$in_range(l1, l4);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        if (l5.tag == 1286u) {
            t1 = l5.payload.obj;
            l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields));
            t0 = vader_vm$in_range(l2, l4);
            if (t0) {
                t1 = l5.payload.obj;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
                t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
                l6 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_type_index;
                t2 = vader_vm$tags_of_type(l0, l6);
                return t2;
            }
        }
        if (l5.tag == 1287u) {
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
    l3 = vader_array_length(((vader_array_t*) l0));
    if ((l2 >= l3)) {
        return (uint8_t) 16;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l4.tag == 1283u)) {
        return (uint8_t) 16;
    }
    t0 = l4.payload.obj;
    return ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
}

static int32_t vader_vm$find_u8_array_type_id(void* l0) {
    int32_t l1;
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l1 = INT32_C(-1);
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        if (l4.tag == 1283u) {
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
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
        if (l4.tag == 1273u) {
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
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[2] = { &l1, &l10 };
    void** gc_raw_roots[6] = { &l2, &l3, &l5, &l6, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_33;
    if (t0 == INT32_C(2)) {
        l2 = vader_global_34;
    } else {
        l2 = vader_vm$guest_threads();
    }
    ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_entry_machine = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_vm$GuestThreads_t*) l2);
    t1 = std_collections$len__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live);
    if (t1 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 627u);
        t2 = (void*) _a0_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live;
    l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_size;
    if ((INT64_C(0) < l4)) {
        l4 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_size;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_reserve(30u, (int64_t) l4, 8u, 627u);
    l5 = (void*) _a1_arr;
    l6 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_ekeys;
    l4 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i64__vader_vm_GuestThread_t*) l3)->f_size;
    while ((l4 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l8 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
        vader_array_push_i64((vader_array_t*) l5, l8);
        l4 = (l4 + INT64_C(1));
    }
    vader_struct___lambda_env_vader_vm_7_t* _a3_obj = (vader_struct___lambda_env_vader_vm_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_7_t));
    vader_obj_header_init(_a3_obj, 873u);
    _a3_obj->f_cap_0 = l2;
    t2 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 556u);
    _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_6;
    _a4_closure->env = t2;
    l3 = (void*) _a4_closure;
    l3 = std_sort$sort__i64(l5, l3);
    vader_array_t* _a5_arr = vader_array_new(30u, 0u, 8u, 627u);
    l5 = (void*) _a5_arr;
    l6 = l3;
    l4 = vader_array_length(((vader_array_t*) l6));
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l8 = ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l7];
        l10 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live, l8);
        if (l10.tag == 0u) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l9 = l10.payload.obj;
        t3 = vader_host_std_core$Intrinsic$is_leaving(l8);
        if (t3) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l11 = ((vader_struct_vader_vm$GuestThread_t*) l9)->f_number;
        vader_array_push_i64((vader_array_t*) l5, l11);
        if (l0) {
            t1 = ((vader_struct_vader_vm$GuestThread_t*) l9)->f_number;
            vader_vm$announce_cancelled(t1, l1);
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = vader_array_length(((vader_array_t*) l3));
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
        t1 = ((int64_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l7];
        vader_vm$cancel(t1);
        l7 = (l7 + INT64_C(1));
    }
    l4 = vader_host_std_core$Intrinsic$current_thread();
    ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_waiter = l4;
    for (;;) {
        t1 = std_collections$len__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l2)->f_live);
        if ((t1 > INT64_C(0))) {
            vader_host_std_core$Intrinsic$park();
            continue;
        }
        break;
    }
    ((vader_struct_vader_vm$GuestThreads_t*) l2)->f_waiter = INT64_C(-1);
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$finish_run(void* l0, bool l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_box_t* gc_roots[4] = { &l2, &l4, &l5, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        if (!(l1)) {
            vader_struct_vader_vm$Ok_t* _a0_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
            vader_obj_header_init(_a0_obj, 2110u);
            _a0_obj->f_value = INT32_C(0);
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_vm$register_value(l0, INT64_C(0));
        l4 = vader_vm$read_i32(t1, INT32_C(0), 3140u);
        l5 = l4;
        if (l4.tag == 2128u) {
            t0 = l5.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int32_t) l4.payload.i);
        vader_struct_vader_vm$Ok_t* _a1_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
        vader_obj_header_init(_a1_obj, 2110u);
        _a1_obj->f_value = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        l3 = l2.payload.obj;
        l4 = vader_vm$register_value(l0, INT64_C(0));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)] = l4;
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        vader_struct_vader_vm$Ok_t* _a3_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
        vader_obj_header_init(_a3_obj, 2110u);
        _a3_obj->f_value = INT32_C(0);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$Ok_t* _a4_obj = (vader_struct_vader_vm$Ok_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Ok_t));
    vader_obj_header_init(_a4_obj, 2110u);
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
    l2 = vader_host_std_core$Intrinsic$bytes(t0);
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
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body));
    if ((l3 < l7)) {
        t0 = vader_vm$merge(l0, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l4 != l6)) {
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = (void*) vader_buffer_new((size_t) INT64_C(98));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l8, l7, 2297u);
    l7 = std_core$write_int(l8, l7, l4);
    l7 = std_core$write_string_at(l8, l7, 290u);
    l7 = std_core$write_int(l8, l7, l6);
    l7 = std_core$write_string_at(l8, l7, 124u);
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
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
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
    l4 = vader_host_std_core$Intrinsic$byte_len(l3);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(70) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l5, l4, l3);
    l4 = std_core$write_string_at(l5, l4, 170u);
    l6 = ((int64_t) (int32_t) l0);
    l4 = std_core$write_int(l5, l4, l6);
    l4 = std_core$write_string_at(l5, l4, 247u);
    l6 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l5, l4, l6);
    t0 = std_core$finish_buffer(l5, l4);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 2128u);
    _a0_obj->f_message = t0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$foreign_call_of(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l8 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    int64_t l6, l7, l13, l14;
    int32_t l9;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    uint8_t l16, l19;
    bool l17, l18;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2, t3;
    vader_box_t* gc_roots[2] = { &l3, &l8 };
    void** gc_raw_roots[6] = { &l0, &l4, &l5, &l10, &l15, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_foreign_calls);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    l6 = vader_vm$adapter_of(l0, l1);
    l3 = vader_vm$callee_of(l0, l4, l6, l2);
    l8 = l3;
    if (l3.tag == 2128u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int64_t) l3.payload.i);
    l9 = vader_core_bytecode$bc_single_result_type(((vader_struct_vader_core_bytecode$BcImport_t*) l4)->f_signature);
    l3 = vader_core_bytecode$mirror_at(l5, l9);
    l8 = vader_box_obj(0u, NULL);
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        l10 = vader_core_bytecode$c_struct_layout(((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields, l5);
        if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_unknown_field.tag == 0u)) {
            l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l4)->f_extern_name;
            l12 = ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_unknown_field.payload.s;
            l13 = vader_host_std_core$Intrinsic$byte_len(l11);
            l14 = vader_host_std_core$Intrinsic$byte_len(l12);
            l13 = (l13 + l14);
            l15 = (void*) vader_buffer_new((size_t) (INT64_C(123) + l13));
            l13 = INT64_C(0);
            l13 = std_core$write_string_at(l15, l13, 2478u);
            l13 = std_core$write_string_at(l15, l13, l11);
            l13 = std_core$write_string_at(l15, l13, 1349u);
            l14 = ((int64_t) (int32_t) l2);
            l13 = std_core$write_int(l15, l13, l14);
            l13 = std_core$write_string_at(l15, l13, 595u);
            l13 = std_core$write_string_at(l15, l13, l12);
            l13 = std_core$write_string_at(l15, l13, 1494u);
            t1 = std_core$finish_buffer(l15, l13);
            vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a2_obj, 2128u);
            _a2_obj->f_message = t1;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l15 = l3.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_size;
        vader_struct_vader_vm$ResultMirror_t* _a3_obj = (vader_struct_vader_vm$ResultMirror_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ResultMirror_t));
        vader_obj_header_init(_a3_obj, 2120u);
        _a3_obj->f_type_index = l9;
        _a3_obj->f_mirror = l15;
        _a3_obj->f_size = l13;
        t0 = (void*) _a3_obj;
        l8 = vader_ref_box(t0);
    }
    l16 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l4)->f_signature);
    l17 = vader_vm$ffi_result_is_opt(l5, l9, (uint8_t) 12);
    l18 = l6 != INT64_C(0);
    t2 = vader_vm$ffi_result_class(l16, l17);
    t3 = (t2 & INT32_C(255));
    l19 = (uint8_t) (int32_t) t3;
    if (l17) {
        l17 = true;
    } else {
        l17 = vader_vm$ffi_result_is_opt(l5, l9, (uint8_t) 15);
    }
    vader_struct_vader_vm$ForeignCall_t* _a4_obj = (vader_struct_vader_vm$ForeignCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ForeignCall_t));
    vader_obj_header_init(_a4_obj, 2099u);
    _a4_obj->f_callee = l7;
    _a4_obj->f_through_adapter = l18;
    _a4_obj->f_result = l16;
    _a4_obj->f_result_mirror = l8;
    _a4_obj->f_result_class = l19;
    _a4_obj->f_null_on_zero = l17;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_foreign_calls);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    vader_array_ref_store(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l1, l4);
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
            vader_host_std_core$Intrinsic$wake(t0);
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_frame_code;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l5 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l5));
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l2 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_name;
    t1 = concat_3(1310u, l2, 1352u);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
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
        l1 = vader_box_i32(626u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l1 = vader_box_i64(627u, INT64_C(0));
    } else {
        if (l0 == INT32_C(8)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l1 = vader_box_f64(633u, 0.0);
        } else if (l0 == INT32_C(10)) {
            l1 = vader_box_bool(621u, false);
        } else if (l0 == INT32_C(11)) {
            l1 = vader_box_i32(622u, (int32_t) ((uint32_t) 0));
        } else if (l0 == INT32_C(12)) {
            l1 = vader_box_string(623u, 0u);
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
            t0 = (void*) &vader_data_103;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
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
    t0 = vader_global_33;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_34;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_runtime_scheduler$monitor_enter_to_publish();
    t2 = vader_global_35;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_35 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_vader_vm$guest_threads$keep;
    t3 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t3)) {
        vader_unreachable("singleton `guest_threads` called while it initialises");
    }
    t1 = vader_global_34;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$guest_threads$keep(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_33;
    if (!(t0 == INT32_C(2))) {
        t1 = vader_vm$guest_threads$singleton();
        vader_global_34 = t1;
        vader_global_33 = INT32_C(2);
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
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 627u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 634u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i64__Any_t* _a3_obj = (vader_struct_std_collections$Map__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__Any_t));
    vader_obj_header_init(_a3_obj, 934u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_vm$GuestThreads_t* _a4_obj = (vader_struct_vader_vm$GuestThreads_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$GuestThreads_t));
    vader_obj_header_init(_a4_obj, 2104u);
    _a4_obj->f_live = t0;
    _a4_obj->f_entry_thread = INT64_C(-1);
    _a4_obj->f_waiter = INT64_C(-1);
    _a4_obj->f_entry_machine = vader_box_obj(0u, NULL);
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$hosted_frame_call(void* l0, int64_t l1, int32_t l2, vader_string_t l3, bool l4) {
    int64_t l5, l10, l13;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l7 = 0;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    uint8_t l15;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    vader_box_t* gc_roots[4] = { &l6, &l8, &l14, &t3 };
    void** gc_raw_roots[5] = { &l0, &l9, &l11, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l6 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    l7 = concat_2(l3, 163u);
    l6 = vader_vm$read_i64(l6, l2, l7);
    l8 = l6;
    if (l6.tag == 2128u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((int64_t) l6.payload.i);
    l10 = vader_chk_add(i64, l1, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
    l6 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l10];
    l7 = concat_2(l3, 146u);
    l6 = vader_vm$read_array(l6, l2, l7);
    l8 = l6;
    if (l6.tag == 2128u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l6.payload.obj;
    l10 = vader_chk_add(i64, l1, INT64_C(2));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
    l6 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l10];
    l7 = concat_2(l3, 167u);
    l6 = vader_vm$read_array(l6, l2, l7);
    l8 = l6;
    if (l6.tag == 2128u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l6.payload.obj;
    l10 = vader_vm$element_count(l9);
    l7 = concat_2(l3, 147u);
    l6 = vader_vm$array_bytes(l9, l10, l2, l7);
    l8 = l6;
    if (l6.tag == 2128u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l6.payload.obj;
    vader_vm$own_bytes(l11);
    vader_array_t* _a3_arr = vader_array_new(31u, 0u, 1u, 628u);
    l12 = (void*) _a3_arr;
    l10 = INT64_C(0);
    l13 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l11)->f_elements));
    while ((l10 < l13)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l11)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        l6 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l10];
        l7 = concat_2(l3, 168u);
        l8 = vader_vm$read_i64(l6, l2, l7);
        l14 = l8;
        if (l8.tag == 2128u) {
            t0 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((int64_t) l8.payload.i);
        t2 = (((int32_t) (int64_t) t1) & INT32_C(255));
        l15 = (uint8_t) (int32_t) t2;
        vader_array_push_u8((vader_array_t*) l12, (int32_t) (uint8_t) l15);
        l10 = (l10 + INT64_C(1));
    }
    l7 = vader_vm$call_foreign(l5, l4, l9, l12, INT64_C(-1));
    l5 = INT64_C(0);
    l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l11)->f_elements));
    while ((l5 < l10)) {
        l9 = ((vader_struct_vader_vm$ArrayVal_t*) l11)->f_elements;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l11)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l6 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l5];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t3 = vader_array_read_u8(_a6_slotarr, vader_array_offset(_a6_slotarr) + (size_t) l5, 628u);
        t4 = ((uint8_t) t3.payload.i);
        l13 = ((int64_t) (uint8_t) t4);
        l8 = vader_vm$retyped_int(l6, l13);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l5] = l8;
        VADER_WRITE_BARRIER(_a7_slotarr->buf);
        l5 = (l5 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_string(623u, l7); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$i32_of(void* l0, int64_t l1, int32_t l2) {
    int64_t l3;
    int64_t t0;
    l3 = ((int64_t) (int32_t) l2);
    l3 = vader_chk_add(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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

static void* vader_vm$indirect_call_trap(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l12 = NULL;
    int64_t l6, l11, l15;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int32_t l9;
    bool l10;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l12, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l13, &l14, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_chk_add(i64, l2, l3);
    t0 = vader_vm$register_value(l1, l6);
    l7 = vader_vm$read_fn(t0, l4, 2189u);
    l8 = l7;
    if (l7.tag == 2128u) {
        t1 = l8.payload.obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l7.payload.obj;
    l9 = ((vader_struct_vader_vm$FnVal_t*) l5)->f_function_index;
    if ((l9 < INT32_C(0))) {
        l10 = true;
    } else {
        l6 = ((int64_t) (int32_t) l9);
        l11 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l0)->f_functions));
        l10 = (l6 >= l11);
    }
    if (l10) {
        t1 = vader_vm$fn_index_trap(l9, l4, 2186u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l0)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
    l12 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l9);
    if (((vader_struct_vader_vm$FnVal_t*) l5)->f_env.tag == 0u) {
        l6 = l3;
    } else {
        l6 = vader_chk_add(i64, l3, INT64_C(1));
    }
    if (((vader_struct_vader_vm$FnVal_t*) l5)->f_env.tag == 0u) {
        l13 = 0u;
    } else {
        l13 = 73u;
    }
    l14 = ((vader_struct_vader_vm$RegFunction_t*) l12)->f_name;
    l11 = vader_host_std_core$Intrinsic$byte_len(l13);
    l15 = vader_host_std_core$Intrinsic$byte_len(l14);
    l11 = (l11 + l15);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(139) + l11));
    l11 = INT64_C(0);
    l11 = std_core$write_string_at(l5, l11, 2187u);
    l15 = ((int64_t) (int32_t) l4);
    l11 = std_core$write_int(l5, l11, l15);
    l11 = std_core$write_string_at(l5, l11, 579u);
    l11 = std_core$write_int(l5, l11, l6);
    l11 = std_core$write_string_at(l5, l11, l13);
    l11 = std_core$write_string_at(l5, l11, 135u);
    l11 = std_core$write_string_at(l5, l11, l14);
    l11 = std_core$write_string_at(l5, l11, 370u);
    l6 = ((vader_struct_vader_vm$RegFunction_t*) l12)->f_params;
    l11 = std_core$write_int(l5, l11, l6);
    l11 = std_core$write_string_at(l5, l11, 249u);
    t2 = std_core$finish_buffer(l5, l11);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
    _a1_obj->f_message = t2;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body));
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(31u, 1u, 1u, 628u);
    ((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a2_arr;
    l6 = vader_chk_mul(i64, l3, INT64_C(2));
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a3_arr;
    vader_struct_vader_vm$FunctionTags_t* _a4_obj = (vader_struct_vader_vm$FunctionTags_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$FunctionTags_t));
    vader_obj_header_init(_a4_obj, 2101u);
    _a4_obj->f_deepest = l2;
    _a4_obj->f_depth = l4;
    _a4_obj->f_stack = l5;
    l4 = (void*) _a4_obj;
    if (l3 == INT64_C(0)) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params;
    l3 = vader_array_length(((vader_array_t*) l5));
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals));
    l3 = vader_chk_add(i64, l3, l6);
    l7 = ((vader_struct_vader_vm$TagContext_t*) l0)->f_module;
    l6 = vader_chk_add(i64, l3, l2);
    l7 = vader_vm$new_blocks(l7, l1, l6);
    vader_array_t* _a5_arr = vader_array_new(31u, 1u, 1u, 628u);
    ((uint8_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (uint8_t) INT32_C(0);
    l8 = (void*) _a5_arr;
    l6 = ((vader_struct_vader_vm$Blocks_t*) l7)->f_width;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l6);
    l8 = (void*) _a6_arr;
    l6 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) l5));
    while ((l6 < l9)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_read_u8(_a7_slotarr, vader_array_offset(_a7_slotarr) + (size_t) l6, 628u);
        l10 = vader_vm$tags_of_val(((uint8_t) t1.payload.i));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((uint8_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l10;
        l6 = (l6 + INT64_C(1));
    }
    l6 = vader_array_length(((vader_array_t*) l5));
    while ((l6 < l3)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        ((uint8_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l6] = (uint8_t) INT32_C(32);
        l6 = (l6 + INT64_C(1));
    }
    vader_vm$merge_block(l7, INT64_C(0), INT64_C(0), l8);
    vader_array_t* _a10_arr = vader_array_new(31u, 1u, 1u, 628u);
    ((uint8_t*) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = (uint8_t) INT32_C(0);
    l5 = (void*) _a10_arr;
    l6 = ((vader_struct_vader_vm$Blocks_t*) l7)->f_width;
    vader_array_t* _a11_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a11_arr;
    for (;;) {
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_work));
        if ((t2 > INT64_C(0))) {
            l11 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_work);
            if (l11.tag == 0u) break;
            l6 = ((int64_t) l11.payload.i);
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_queued);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            ((uint8_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l6] = (uint8_t) false;
            vader_vm$walk_block(l0, l1, l7, l6, l3, l5, vader_box_obj(0u, NULL));
            continue;
        }
        break;
    }
    l6 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_leaders));
    while ((l6 < l9)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l7)->f_entry_depth);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        t2 = ((int64_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l6];
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    vader_array_t* _a0_arr = vader_array_reserve(447u, (int64_t) t0, 13u, 2101u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l7 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
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
    vader_obj_header_init(_a0_obj, 868u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a1_arr = vader_array_reserve(503u, (int64_t) t0, 0u, 3020u);
    l3 = (void*) _a1_arr;
    l4 = vader_array_length(((vader_array_t*) l1));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l7 = __lambda_vader_vm_0(l2, l6);
        vader_array_push((vader_array_t*) l3, l7);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$inlinable_op(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 1319u || l0.tag == 1390u || l0.tag == 1391u || l0.tag == 1392u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 1312u || l0.tag == 1313u)) {
        l1 = true;
    } else if ((l0.tag == 1296u || l0.tag == 1311u || l0.tag == 1324u || l0.tag == 1345u || l0.tag == 1365u || l0.tag == 1397u)) {
        l1 = true;
    } else if ((l0.tag == 1314u || l0.tag == 1401u)) {
        l1 = true;
    } else if ((l0.tag == 1340u || l0.tag == 1341u || l0.tag == 1342u || l0.tag == 1353u || l0.tag == 1355u || l0.tag == 1359u)) {
        l1 = true;
    } else if ((l0.tag == 1343u || l0.tag == 1344u || l0.tag == 1356u || l0.tag == 1357u || l0.tag == 1358u)) {
        l1 = true;
    } else if ((l0.tag == 1347u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1350u || l0.tag == 1351u || l0.tag == 1354u)) {
        l1 = true;
    } else if ((l0.tag == 1423u || l0.tag == 1424u || l0.tag == 1425u || l0.tag == 1426u)) {
        l1 = true;
    } else if ((l0.tag == 1360u || l0.tag == 1361u || l0.tag == 1362u || l0.tag == 1373u || l0.tag == 1375u || l0.tag == 1379u)) {
        l1 = true;
    } else if ((l0.tag == 1363u || l0.tag == 1364u || l0.tag == 1376u || l0.tag == 1377u || l0.tag == 1378u)) {
        l1 = true;
    } else if ((l0.tag == 1367u || l0.tag == 1368u || l0.tag == 1369u || l0.tag == 1370u || l0.tag == 1371u || l0.tag == 1374u)) {
        l1 = true;
    } else if ((l0.tag == 1429u || l0.tag == 1430u || l0.tag == 1431u || l0.tag == 1432u)) {
        l1 = true;
    } else if ((l0.tag == 1323u || l0.tag == 1325u || l0.tag == 1331u || l0.tag == 1333u || l0.tag == 1334u)) {
        l1 = true;
    } else if ((l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1332u)) {
        l1 = true;
    } else if ((l0.tag == 1295u || l0.tag == 1297u || l0.tag == 1298u || l0.tag == 1299u || l0.tag == 1300u)) {
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_body;
    l5 = l4;
    vader_struct___lambda_env_vader_vm_4_t* _a1_obj = (vader_struct___lambda_env_vader_vm_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_4_t));
    vader_obj_header_init(_a1_obj, 872u);
    _a1_obj->f_cap_0 = l1;
    l6 = (void*) _a1_obj;
    l7 = false;
    l8 = vader_array_length(((vader_array_t*) l5));
    l9 = INT64_C(0);
    {
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l10 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
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
    vader_array_t* _a3_arr = vader_array_new(476u, 0u, 13u, 2483u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(480u, 0u, 13u, 2544u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 626u);
    l11 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 626u);
    l12 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(116u, 0u, 13u, 1280u);
    l13 = (void*) _a7_arr;
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_locals;
    vader_array_push_all((vader_array_t*) l13, (vader_array_t*) l14);
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature)->f_params));
    l15 = ((int32_t) (int64_t) t1);
    vader_array_t* _a8_arr = vader_array_new(29u, 0u, 7u, 626u);
    l14 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 626u);
    l16 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 626u);
    l17 = (void*) _a10_arr;
    vader_struct_std_collections$Map__i32__i32_t* _a11_obj = (vader_struct_std_collections$Map__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__i32_t));
    vader_obj_header_init(_a11_obj, 889u);
    _a11_obj->f_ekeys = l14;
    _a11_obj->f_evals = l16;
    _a11_obj->f_index = l17;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a11_obj;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) l4));
    while ((l8 < l9)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l10 = vader_array_ref_load_box(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l8);
        t1 = vader_array_length(((vader_array_t*) l5));
        l18 = ((int32_t) (int64_t) t1);
        vader_array_push_i32((vader_array_t*) l12, l18);
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_debug);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        l19 = vader_array_ref_load_box(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l8);
        if (l10.tag == 1308u) {
            t2 = l10.payload.obj;
            l20 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l20)
            t0 = ((uint8_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l20];
            t3 = t0;
            if (t3) {
                t2 = l10.payload.obj;
                l21 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l21)
                l16 = vader_array_ref_load_obj(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) l21);
                t1 = vader_array_length(((vader_array_t*) l13));
                l22 = ((int32_t) (int64_t) t1);
                l23 = vader_chk_add(i32, l15, l22);
                t2 = l10.payload.obj;
                l24 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                l25 = std_collections$put_absent__i32__i32(l14, l24, l23);
                if (l25.tag == 0u) {
                    l17 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params;
                    l26 = vader_array_length(((vader_array_t*) l17));
                    l27 = INT64_C(0);
                    while ((l27 < l26)) {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        t4 = vader_array_read_u8(_a16_slotarr, vader_array_offset(_a16_slotarr) + (size_t) l27, 628u);
                        l28 = ((uint8_t) t4.payload.i);
                        vader_struct_vader_core_bytecode$BcLocal_t* _a17_obj = (vader_struct_vader_core_bytecode$BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcLocal_t));
                        vader_obj_header_init(_a17_obj, 1280u);
                        _a17_obj->f_name = 2723u;
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
                l33 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params));
                l34 = INT64_C(0);
                while ((l34 < l33)) {
                    t1 = vader_chk_sub(i64, l33, INT64_C(1));
                    t5 = vader_chk_sub(i64, t1, l34);
                    l35 = ((int32_t) (int64_t) t5);
                    t6 = vader_chk_add(i32, l31, l35);
                    vader_struct_vader_core_bytecode$LocalSet_t* _a18_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
                    vader_obj_header_init(_a18_obj, 1391u);
                    _a18_obj->f_slot = t6;
                    l36 = (void*) _a18_obj;
                    vader_array_push_ref((vader_array_t*) l5, l36);
                    vader_array_push_ref((vader_array_t*) l6, l19.payload.obj);
                    l37 = ((int32_t) (int64_t) l8);
                    vader_array_push_i32((vader_array_t*) l11, l37);
                    l34 = (l34 + INT64_C(1));
                }
                l38 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body));
                l39 = INT64_C(0);
                l40 = vader_chk_sub(i64, l38, INT64_C(1));
                while ((l39 < l40)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l39)
                    t4 = vader_array_ref_load_box(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) l39);
                    l41 = vader_vm$relocated(t4, l31);
                    vader_array_push_ref((vader_array_t*) l5, l41.payload.obj);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l39)
                    l42 = vader_array_ref_load_box(_a20_slotarr->buf, vader_array_offset(_a20_slotarr) + (size_t) l39);
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
                l46 = vader_array_ref_load_box(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l45);
                if (l46.tag == 1403u) {
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
    l8 = vader_array_length(((vader_array_t*) l5));
    l3 = vader_core_bytecode$remap_jump_table(l3, l12, l8);
    vader_struct_vader_core_bytecode$BcFunction_t* _a22_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a22_obj, 1277u);
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) t0, 12u, 621u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l5 = vader_vm$is_inline_leaf(t1);
        vader_array_push_bool((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    t2 = std_core$$array$Contains$contains__bool(l1, true);
    if (!(t2)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    vader_array_t* _a2_arr = vader_array_reserve(113u, (int64_t) t0, 13u, 1277u);
    l2 = (void*) _a2_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
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
    vader_obj_header_init(_a3_obj, 1306u);
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

static bool vader_vm$is_boxed(vader_box_t l0) {
    return (l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1264u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1271u || l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1295u || l0.tag == 1297u || l0.tag == 1298u || l0.tag == 1299u || l0.tag == 1300u || l0.tag == 1303u || l0.tag == 1304u || l0.tag == 1305u || l0.tag == 1314u || l0.tag == 1315u || l0.tag == 1322u || l0.tag == 1335u || l0.tag == 1337u || l0.tag == 1338u || l0.tag == 1339u || l0.tag == 1347u || l0.tag == 1354u || l0.tag == 1382u || l0.tag == 1383u || l0.tag == 1384u || l0.tag == 1388u || l0.tag == 1394u || l0.tag == 1396u || l0.tag == 1399u || l0.tag == 1400u || l0.tag == 1404u || l0.tag == 1406u || l0.tag == 1407u || l0.tag == 1408u || l0.tag == 1412u || l0.tag == 1413u || l0.tag == 1415u || l0.tag == 1416u || l0.tag == 1418u || l0.tag == 1420u || l0.tag == 1421u);
}

bool vader_vm$is_comptime_refusal_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$string$std_core$Contains$contains(l0, 2778u);
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
    l3 = vader_array_length(((vader_array_t*) l1));
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
    l1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body));
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
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    if (!((t2.tag == 1402u || t2.tag == 1403u))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params));
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals));
    l4 = vader_chk_add(i64, l2, l4);
    l3 = (void*) &vader_fn_static___lambda_vader_vm_2;
    l3 = std_core$filled__bool(l4, l3);
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l1 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l1);
    l5 = (void*) _a1_arr;
    l1 = vader_array_length(((vader_array_t*) l5));
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
        t0 = vader_vm$inlinable_op(l6);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = vader_core_bytecode$slot_touched(l6);
        l8 = ((int32_t) (int64_t) l2);
        if ((l7 >= l8)) {
            if (l6.tag == 1390u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                t0 = ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l7];
                t3 = t0;
                if (!(t3)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
            }
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l7] = (uint8_t) true;
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

static bool vader_vm$is_lendable_element(uint8_t l0) {
    bool l1;
    bool t0;
    t0 = vader_core_bytecode$is_integer_val(l0);
    if (t0) {
        l1 = true;
    } else {
        l1 = vader_core_bytecode$is_float_val(l0);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(11);
}

static bool vader_vm$is_overflow_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$starts_with(l0, 2184u);
    return t0;
}

bool vader_vm$is_singleton_comptime_trap_message(vader_string_t l0) {
    bool t0;
    t0 = std_string$string$std_core$Contains$contains(l0, 2073u);
    return t0;
}

static bool vader_vm$is_source_local(vader_string_t l0) {
    int64_t t0;
    uint8_t t1;
    t0 = vader_host_std_core$Intrinsic$byte_len(l0);
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = vader_host_std_core$Intrinsic$byte_at(l0, INT64_C(0));
    if (t1 == INT32_C(36)) {
        return false;
    }
    t0 = vader_host_std_core$Intrinsic$byte_len(l0);
    if ((t0 >= INT64_C(2))) {
        t1 = vader_host_std_core$Intrinsic$byte_at(l0, INT64_C(0));
        if (t1 == INT32_C(95)) {
            t1 = vader_host_std_core$Intrinsic$byte_at(l0, INT64_C(1));
            if (t1 == INT32_C(95)) {
                return false;
            }
        }
    }
    if (!(l0 == 2689u)) {
        return true;
    }
    return false;
}

static bool vader_vm$is_unsigned_source(vader_string_t l0) {
    int64_t t0;
    uint8_t t1;
    t0 = vader_host_std_core$Intrinsic$byte_len(l0);
    if ((t0 > INT64_C(0))) {
        t1 = vader_host_std_core$Intrinsic$byte_at(l0, INT64_C(0));
        return t1 == INT32_C(117);
    }
    return false;
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
    l12 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops));
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
    l3 = vader_array_length(((vader_array_t*) l0));
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l4.tag == 1273u)) {
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
    l3 = vader_array_length(((vader_array_t*) l0));
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
    if (!(l4.tag == 1283u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    t2 = vader_vm$is_lendable_element(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
    if (!(t2)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_box_i32(628u, (int32_t)(uint32_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
}

static vader_box_t vader_vm$lent_word(vader_box_t l0, int64_t l1, int32_t l2, vader_string_t l3, vader_string_t l4) {
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    int64_t t0;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    double t3;
    uint64_t t4;
    vader_box_t* gc_roots[3] = { &l0, &l5, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 627u) {
        t0 = ((int64_t) l0.payload.i);
        { vader_box_t __vret = vader_box_i64(627u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 626u) {
        t1 = ((int32_t) l0.payload.i);
        { vader_box_t __vret = vader_box_i64(627u, ((int64_t) (int32_t) t1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!((l0.tag == 632u || l0.tag == 633u))) {
        l5 = l0;
        l6 = concat_4(2478u, l3, 1311u, l4);
        t2 = vader_vm$read_scalar_word(l5, l2, l6);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((double) l0.payload.f);
    t4 = vader_vm$float_bits(t3, l1);
    { vader_box_t __vret = vader_box_i64(627u, ((int64_t) (uint64_t) t4)); vader_gc_top = gc_frame.prev; return __vret; }
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
    int32_t l3, l9;
    int64_t l4, l8;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    int64_t t0;
    void* t1 = NULL;
    uint64_t t2;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    l5 = vader_vm$stack_i32(l0, l4, l2, 3011u);
    l6 = l5;
    if (l5.tag == 2128u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int32_t) l5.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l4 = vader_chk_sub(i64, t0, INT64_C(2));
    l5 = vader_vm$stack_obj(l0, l4, l2);
    l6 = l5;
    if (l5.tag == 2128u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l5.payload.obj;
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l7)->f_bytes));
    l9 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l5 = vader_vm$check_byte_range(l3, l1, l8, l2, l9);
    l6 = l5;
    if (l5.tag == 2128u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) l5.payload.i);
    t2 = vader_core_bytecode$read_le(((vader_struct_vader_vm$ObjVal_t*) l7)->f_bytes, l4, l1);
    { vader_box_t __vret = vader_box_i64(631u, (int64_t)(uint64_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l3 = ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_entries;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
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
    vader_obj_header_init(_a0_obj, 2113u);
    _a0_obj->f_id = INT32_C(1);
    _a0_obj->f_name = 2870u;
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
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
    vader_obj_header_init(_a1_obj, 2115u);
    _a1_obj->f_kind = (uint8_t) 0;
    _a1_obj->f_register = l4;
    l6 = (void*) _a1_obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    vader_array_ref_store(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2, l6);
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
    if ((t0 < INT64_C(0))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l3] = (int64_t) l4;
        vader_array_push_i64((vader_array_t*) l2, l3);
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t0 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l3];
    if (!(t0 != l4)) {
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = (void*) vader_buffer_new((size_t) INT64_C(113));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l6, l7, 3095u);
    l7 = std_core$write_int(l6, l7, l3);
    l7 = std_core$write_string_at(l6, l7, 298u);
    l7 = std_core$write_int(l6, l7, l4);
    l7 = std_core$write_string_at(l6, l7, 291u);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l8 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l3];
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    l5 = (t0 < INT64_C(0));
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1] = (int64_t) l2;
    l6 = INT64_C(0);
    l7 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_width;
    while ((l6 < l7)) {
        l8 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_entry;
        l9 = vader_chk_add(i64, l4, l6);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l9, 628u);
        l10 = ((uint8_t) t1.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l6, 628u);
        l11 = ((uint8_t) t1.payload.i);
        t2 = (l10 | l11);
        l12 = (uint8_t) (int32_t) t2;
        if (l12 != l10) {
            l13 = ((vader_struct_vader_vm$Blocks_t*) l0)->f_entry;
            l14 = vader_chk_add(i64, l4, l6);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l14] = (uint8_t) (int32_t) (uint8_t) l12;
            l5 = true;
        }
        l6 = (l6 + INT64_C(1));
    }
    if (l5) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t3 = ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l1];
        t4 = t3;
        if (t4) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_queued);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l1] = (uint8_t) true;
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l0)->f_work, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    l3 = vader_array_length(((vader_array_t*) l1));
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
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
    l4 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1] = (int64_t) l4;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l2, 628u);
    l5 = ((uint8_t) t0.payload.i);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l1] = (uint8_t) (int32_t) (uint8_t) l5;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
    l6 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l2];
    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l1] = l6;
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
    if (l0.tag == 626u) {
        t1 = ((int32_t) l0.payload.i);
        l4 = ((int64_t) (int32_t) t1);
    } else {
        if (!(l0.tag == 627u)) {
            return l0;
        }
        l4 = ((int64_t) l0.payload.i);
    }
    if (l1 == INT32_C(0)) {
        l3 = true;
        t1 = vader_vm$truncate_to_width(l4, l2, l3);
        return vader_box_i32(626u, t1);
    }
    l3 = l1 == INT32_C(1);
    t1 = vader_vm$truncate_to_width(l4, l2, l3);
    return vader_box_i32(626u, t1);
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    if (((int32_t) t0.payload.i) != INT32_C(0)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
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
    l5 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1];
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
    ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l1] = (int64_t) l3;
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l1] = (uint8_t) INT32_C(0);
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
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body));
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 12u, 621u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((uint8_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)] = (uint8_t) true;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        l8 = vader_core_bytecode$stack_effect(l0, l1, l7);
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l6 = l8.payload.obj;
        if (((vader_struct_vader_core_bytecode$StackEffect_t*) l6)->f_flow == INT32_C(1)) {
            l9 = true;
        } else {
            l9 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l6)->f_flow == INT32_C(2);
        }
        if (l9) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            l10 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l5];
            t1 = vader_vm$in_range(l10, l3);
            if (t1) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l10] = (uint8_t) true;
            }
        }
        if (((vader_struct_vader_core_bytecode$StackEffect_t*) l6)->f_flow != INT32_C(0)) {
            t2 = vader_chk_add(i64, l5, INT64_C(1));
            if ((t2 < l3)) {
                l11 = vader_chk_add(i64, l5, INT64_C(1));
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                ((uint8_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l11] = (uint8_t) true;
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(30u, 0u, 8u, 627u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l12 = (void*) _a9_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t1 = ((uint8_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l5];
        t3 = t1;
        if (t3) {
            l11 = vader_array_length(((vader_array_t*) l6));
            vader_array_t* _a11_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
            ((int64_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l5] = (int64_t) l11;
            vader_array_push_i64((vader_array_t*) l6, l5);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a12_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = (int64_t) INT64_C(-1);
    l4 = (void*) _a12_arr;
    l3 = vader_array_length(((vader_array_t*) l6));
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l3);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(31u, 1u, 1u, 628u);
    ((uint8_t*) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = (uint8_t) INT32_C(0);
    l13 = (void*) _a14_arr;
    t2 = vader_array_length(((vader_array_t*) l6));
    l3 = vader_chk_mul(i64, t2, l2);
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l3);
    l13 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(30u, 0u, 8u, 627u);
    l14 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(26u, 1u, 12u, 621u);
    ((uint8_t*) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = (uint8_t) false;
    l15 = (void*) _a17_arr;
    l3 = vader_array_length(((vader_array_t*) l6));
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l3);
    l15 = (void*) _a18_arr;
    vader_struct_vader_vm$Blocks_t* _a19_obj = (vader_struct_vader_vm$Blocks_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Blocks_t));
    vader_obj_header_init(_a19_obj, 2094u);
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
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 1u, 7u, 626u);
    ((int32_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a1_arr;
    vader_struct_vader_vm$RunHost_t* _a2_obj = (vader_struct_vader_vm$RunHost_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RunHost_t));
    vader_obj_header_init(_a2_obj, 2121u);
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
    vader_array_t* _a0_arr = vader_array_reserve(31u, (int64_t) t0, 1u, 628u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        l5 = ((int32_t) (int64_t) l2);
        l6 = vader_vm$type_tags(l4, l5, INT32_C(0));
        vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l6);
        l2 = (l2 + INT64_C(1));
    }
    vader_struct_vader_vm$TagContext_t* _a1_obj = (vader_struct_vader_vm$TagContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$TagContext_t));
    vader_obj_header_init(_a1_obj, 2126u);
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_copies));
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
    if ((l1.tag == 1312u || l1.tag == 1313u)) {
        l2 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_kinds;
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_kinds));
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        l4 = VADER_UNION_FIELD(uint8_t, vader_struct_vader_core_bytecode$CheckedArith_t, f_kind, l1.payload.obj);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l4;
        return;
    }
    return;
}

static void vader_vm$note_entry_thread(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_33;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_34;
    } else {
        l1 = vader_vm$guest_threads();
    }
    l2 = vader_host_std_core$Intrinsic$current_thread();
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
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &t2 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_vm$read_i64(l0, l1, l2);
    l5 = l4;
    if (l4.tag == 2128u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int64_t) l4.payload.i);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(627u, t1));
    t2 = vader_vm$void_result();
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops));
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
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
    l3 = vader_chk_sub(i64, t0, l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
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
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
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
    l1 = 2184u;
    l2 = l0;
    l3 = vader_host_std_core$Intrinsic$byte_len(l1);
    l4 = vader_host_std_core$Intrinsic$byte_len(l2);
    l3 = (l3 + l4);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l5, l3, l1);
    l3 = std_core$write_string_at(l5, l3, 71u);
    l3 = std_core$write_int(l5, l3, INT64_C(1024));
    l3 = std_core$write_string_at(l5, l3, 405u);
    l3 = std_core$write_string_at(l5, l3, l2);
    l3 = std_core$write_string_at(l5, l3, 362u);
    t0 = std_core$finish_buffer(l5, l3);
    vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a0_obj, 2128u);
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
    vader_array_t* _a0_arr = vader_array_reserve(503u, (int64_t) t0, 0u, 3020u);
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
    return vader_box_i64(627u, (l4 | l5));
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
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_names));
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l1];
        t1 = t0.payload.s;
        if (t1 != 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_names);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
            t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
            t1 = t0.payload.s;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(23));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l3, l2, 2004u);
    l2 = std_core$write_int(l3, l2, l1);
    t1 = std_core$finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$parked(void) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_std_core$Intrinsic$park();
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
        vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2112u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_vm$RegMachine_t*) t0)->f_debug;
    if (l3.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(452u, 0u, 13u, 2112u);
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
        l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug));
        if ((l6 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l8 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
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
    vader_obj_header_init(_a1_obj, 2112u);
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        if (l4.tag == 2093u) {
            t1 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = l3;
    t0 = vader_vm$peek_val(l0, l1);
    l6 = vader_vm$describe_value_tag(t0);
    l7 = vader_host_std_core$Intrinsic$byte_len(l5);
    l8 = vader_host_std_core$Intrinsic$byte_len(l6);
    l7 = (l7 + l8);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l7));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l9, l7, l5);
    l7 = std_core$write_string_at(l9, l7, 130u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 584u);
    l7 = std_core$write_string_at(l9, l7, l6);
    t2 = std_core$finish_buffer(l9, l7);
    vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a2_obj, 2128u);
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        return l3;
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l1];
        l3 = vader_box_i32(626u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l1];
        l3 = vader_box_i64(627u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l1];
        l3 = vader_box_f64(633u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l1];
        l3 = vader_box_bool(621u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        t1 = ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l1];
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
        l3 = vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l4));
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t3 = (void*) &vader_data_103;
        vader_array_t* _a7_slotarr = ((vader_array_t*) t3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t3 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) INT64_C(0));
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    if (((int32_t) t0.payload.i) == INT32_C(5)) {
        t1 = (void*) &vader_data_32;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
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
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
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
    if (l2.tag == 2132u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm$prepare_module(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$prepare_module(void* l0, bool l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    int64_t l7, l8;
    uint8_t l9;
    vader_string_t l12 = 0;
    int32_t l13, l15, l16;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[9] = { &l0, &l2, &l5, &l6, &l10, &l11, &l14, &l17, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_vm$verify_module(l0);
    l4 = l3;
    if (l3.tag == 2131u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l2 = vader_vm$infer_module_tags(l0, l2);
    l3 = vader_vm$check_module_tags(l0, l2);
    l4 = l3;
    if (l3.tag == 2131u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports));
    vader_array_t* _a0_arr = vader_array_reserve(31u, (int64_t) t1, 1u, 628u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    vader_array_t* _pc40_hdr = (vader_array_t*) l5;
    size_t _pc40_len = vader_array_length(_pc40_hdr);
    size_t _pc40_cap = vader_array_is_borrowed(_pc40_hdr) ? (size_t) 0 : vader_array_capacity(_pc40_hdr);
    void* _pc40_slots = _pc40_hdr->buf->slots;
    for (;;) {
        if ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
            l9 = ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_intrinsic;
            if (VADER_LIKELY(_pc40_len < _pc40_cap)) {
                ((uint8_t*) _pc40_slots)[_pc40_len] = (uint8_t) ((int32_t) (uint8_t) l9);
                _pc40_len += 1;
            } else {
                vader_array_set_length(_pc40_hdr, _pc40_len);
                if (_pc40_hdr->buf->length < _pc40_len) {
                    _pc40_hdr->buf->length = _pc40_len;
                }
                vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l9);
                _pc40_hdr = (vader_array_t*) l5;
                _pc40_len = vader_array_length(_pc40_hdr);
                _pc40_cap = vader_array_is_borrowed(_pc40_hdr) ? (size_t) 0 : vader_array_capacity(_pc40_hdr);
                _pc40_slots = _pc40_hdr->buf->slots;
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc40_hdr, _pc40_len);
        if (_pc40_hdr->buf->length < _pc40_len) {
            _pc40_hdr->buf->length = _pc40_len;
        }
        break;
    }
    l3 = vader_vm$translate_module(l0, l5, l2, l1);
    l4 = l3;
    if (l3.tag == 2131u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 626u);
    l10 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 626u);
    l11 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__i32_t* _a5_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a5_obj, 977u);
    _a5_obj->f_ekeys = l6;
    _a5_obj->f_evals = l10;
    _a5_obj->f_index = l11;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a5_obj;
    l7 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    while ((l7 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l7);
        l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l13 = ((int32_t) (int64_t) l7);
        std_collections$Map$std_core$IndexSet$set_at__string__i32(l6, l12, l13);
        l7 = (l7 + INT64_C(1));
    }
    l10 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool;
    l11 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
    l14 = vader_core_bytecode$data_pool_type_ids(l0);
    l10 = vader_vm$reduce_data_pool(l10, l11, l14);
    l11 = vader_vm$initial_globals(l0);
    l13 = vader_core_bytecode$main_function_index(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    l15 = vader_core_bytecode$find_string_array_type_id(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l16 = vader_vm$find_u8_array_type_id(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    vader_array_t* _a7_arr = vader_array_new(30u, 0u, 8u, 627u);
    l14 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(505u, 1u, 13u, 3042u);
    ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = vader_box_obj(0u, NULL).payload.obj;
    l17 = (void*) _a8_arr;
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports));
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l17, (int64_t) l7);
    l17 = (void*) _a9_arr;
    vader_struct_vader_vm$VmState_t* _a10_obj = (vader_struct_vader_vm$VmState_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VmState_t));
    vader_obj_header_init(_a10_obj, 2132u);
    _a10_obj->f_bc = l0;
    _a10_obj->f_data_pool = l10;
    _a10_obj->f_globals = l11;
    _a10_obj->f_main_index = l13;
    _a10_obj->f_string_array_type_id = l15;
    _a10_obj->f_u8_array_type_id = l16;
    _a10_obj->f_fn_index_by_name = l6;
    _a10_obj->f_import_ids = l5;
    _a10_obj->f_adapters = l14;
    _a10_obj->f_foreign_calls = l17;
    _a10_obj->f_reg = l2;
    _a10_obj->f_debuggable = l1;
    _a10_obj->f_io = vader_box_obj(0u, NULL);
    t0 = (void*) _a10_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$primitive_type_id(void* l0, vader_box_t l1) {
    vader_string_t l2;
    int64_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_string_t t1;
    l2 = vader_vm$describe_value_tag(l1);
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types));
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        l6 = l5;
        if (l5.tag == 1283u) {
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
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params));
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals));
    l5 = vader_chk_add(i64, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 7u, 626u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 7u, 626u);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l7 = (void*) _a3_arr;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body));
    while ((l8 < l9)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l8);
        l10 = vader_core_bytecode$slot_touched(t1);
        if ((l10 >= INT32_C(0))) {
            if ((((int64_t) (int32_t) l10) < l5)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                t2 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l10];
                if ((t2 < INT32_C(0))) {
                    l11 = ((int32_t) (int64_t) l8);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
                    ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l10] = (int32_t) l11;
                }
                l12 = ((int32_t) (int64_t) l8);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
                ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l10] = (int32_t) l12;
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(454u, 0u, 13u, 2114u);
    l13 = (void*) _a8_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l8 = vader_array_length(((vader_array_t*) l0));
        if ((l5 < l8)) {
            l14 = vader_vm$param_display_name(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature, l5);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l15 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l5];
            l16 = vader_vm$project_var(l14, l15, l3, INT32_C(0));
            vader_array_push_ref((vader_array_t*) l13, l16);
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals));
    while ((l5 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l5);
        l14 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_name;
        l9 = vader_chk_add(i64, l4, l5);
        l17 = vader_array_length(((vader_array_t*) l0));
        if ((l9 < l17)) {
            t3 = vader_vm$is_source_local(l14);
            if (t3) {
                t3 = vader_vm$slot_in_scope(l6, l7, l9, l1);
                if (t3) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                    l15 = vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l9];
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
    vader_array_t* _a0_arr = vader_array_new(454u, 0u, 13u, 2114u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_types));
    t0 = vader_vm$in_range(l5, l6);
    if (t0) {
        l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_types;
        l5 = ((vader_struct_vader_vm$StructVal_t*) l0)->f_type_id;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        if (l8.tag == 1286u) {
            t1 = l8.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
            l6 = vader_array_length(((vader_array_t*) l7));
            l9 = INT64_C(0);
            while ((l9 < l6)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
                l10 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(623u, l10));
                l9 = (l9 + INT64_C(1));
            }
        }
    }
    l6 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields));
    while ((l6 < l9)) {
        l11 = vader_array_length(((vader_array_t*) l4));
        if ((l6 < l11)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l6];
            l10 = t2.payload.s;
        } else {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(25));
            l12 = INT64_C(0);
            l12 = std_core$write_string_at(l7, l12, 2513u);
            l12 = std_core$write_int(l7, l12, l6);
            l10 = std_core$finish_buffer(l7, l12);
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l8 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l6];
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
    vader_array_t* _a0_arr = vader_array_new(454u, 0u, 13u, 2114u);
    l4 = (void*) _a0_arr;
    if ((l3 < INT32_C(5))) {
        if (l1.tag == 2093u) {
            t0 = l1.payload.obj;
            t1 = vader_vm$element_count(t0);
            l5 = std_math$min__i64(t1, INT64_C(64));
            l6 = INT64_C(0);
            while ((l6 < l5)) {
                l7 = (void*) vader_buffer_new((size_t) INT64_C(22));
                l8 = INT64_C(0);
                l8 = std_core$write_string_at(l7, l8, 1221u);
                l8 = std_core$write_int(l7, l8, l6);
                l8 = std_core$write_string_at(l7, l8, 1237u);
                l9 = std_core$finish_buffer(l7, l8);
                t0 = l1.payload.obj;
                l10 = vader_vm$element_at(t0, l6);
                l11 = vader_chk_add(i32, l3, INT32_C(1));
                l12 = vader_vm$project_var(l9, l10, l2, l11);
                vader_array_push_ref((vader_array_t*) l4, l12);
                l6 = (l6 + INT64_C(1));
            }
        } else if (l1.tag == 2125u) {
            t0 = l1.payload.obj;
            l4 = vader_vm$project_struct_fields(t0, l2, l3);
        }
        l9 = vader_vm$display_value(l1);
        vader_struct_vader_vm$PauseVar_t* _a1_obj = (vader_struct_vader_vm$PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseVar_t));
        vader_obj_header_init(_a1_obj, 2114u);
        _a1_obj->f_name = l0;
        _a1_obj->f_value = l9;
        _a1_obj->f_children = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm$display_value(l1);
    vader_struct_vader_vm$PauseVar_t* _a2_obj = (vader_struct_vader_vm$PauseVar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseVar_t));
    vader_obj_header_init(_a2_obj, 2114u);
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
        vader_host_std_core$Intrinsic$panic(3112u);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        l3 = std_collections$Map$std_core$Index$at__Any__i64(((vader_struct_vader_vm$Translation_t*) l0)->f_constants, vader_ref_box(l2));
        if (l3.tag == 0u) {
            vader_host_std_core$Intrinsic$panic(3113u);
            vader_unreachable("a no-return call returned");
        } else {
            l4 = ((int64_t) l3.payload.i);
            l2 = ((vader_struct_vader_vm$Translation_t*) l0)->f_stack;
            t0 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_slots;
            t1 = vader_chk_add(i64, t0, l4);
            l5 = ((int32_t) (int64_t) t1);
            vader_struct_vader_vm$Pending_t* _a0_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
            vader_obj_header_init(_a0_obj, 2115u);
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
    vader_obj_header_init(_a0_obj, 2115u);
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
    if (l2.tag == 626u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t0 = ((int32_t) l2.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1] = (uint8_t) INT32_C(0);
        return;
    }
    if (l2.tag == 627u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        l4 = ((int64_t) l2.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l1] = (uint8_t) INT32_C(1);
    } else if ((l2.tag == 632u || l2.tag == 633u)) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t1 = ((double) l2.payload.f);
        l4 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu));
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l1] = (uint8_t) INT32_C(2);
    } else if (l2.tag == 621u) {
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
        ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
        ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l1] = (uint8_t) INT32_C(3);
    } else if (l2.tag == 622u) {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_payload;
        t3 = ((uint32_t) l2.payload.i);
        l4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
        ((int64_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
        ((uint8_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l1] = (uint8_t) INT32_C(4);
    } else if (l2.tag == 2108u) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l1)
        ((uint8_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l1] = (uint8_t) INT32_C(5);
    } else {
        l3 = ((vader_struct_vader_vm$Frame_t*) l0)->f_stack;
        l5 = l2;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l1)
        vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l1] = l5;
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l1)
        ((uint8_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l1] = (uint8_t) INT32_C(6);
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
    if ((l1.tag == 1263u || l1.tag == 1322u || l1.tag == 1340u || l1.tag == 1341u || l1.tag == 1342u || l1.tag == 1343u || l1.tag == 1344u || l1.tag == 1345u || l1.tag == 1346u || l1.tag == 1352u || l1.tag == 1353u || l1.tag == 1355u || l1.tag == 1356u || l1.tag == 1357u || l1.tag == 1358u || l1.tag == 1359u || l1.tag == 1383u || l1.tag == 1388u || l1.tag == 1413u || l1.tag == 1422u || l1.tag == 1427u)) {
        l4 = (uint8_t) 1;
        return l4;
    }
    if ((l1.tag == 1335u || l1.tag == 1360u || l1.tag == 1361u || l1.tag == 1362u || l1.tag == 1363u || l1.tag == 1364u || l1.tag == 1365u || l1.tag == 1366u || l1.tag == 1372u || l1.tag == 1373u || l1.tag == 1375u || l1.tag == 1376u || l1.tag == 1377u || l1.tag == 1378u || l1.tag == 1379u || l1.tag == 1384u || l1.tag == 1404u || l1.tag == 1428u || l1.tag == 1433u)) {
        l4 = (uint8_t) 2;
    } else if ((l1.tag == 1292u || l1.tag == 1293u || l1.tag == 1323u || l1.tag == 1324u || l1.tag == 1325u || l1.tag == 1331u || l1.tag == 1333u || l1.tag == 1334u || l1.tag == 1382u || l1.tag == 1385u)) {
        l4 = (uint8_t) 4;
    } else if ((l1.tag == 1295u || l1.tag == 1296u || l1.tag == 1297u || l1.tag == 1298u || l1.tag == 1299u || l1.tag == 1300u || l1.tag == 1326u || l1.tag == 1327u || l1.tag == 1328u || l1.tag == 1329u || l1.tag == 1330u || l1.tag == 1332u || l1.tag == 1347u || l1.tag == 1348u || l1.tag == 1349u || l1.tag == 1350u || l1.tag == 1351u || l1.tag == 1354u || l1.tag == 1367u || l1.tag == 1368u || l1.tag == 1369u || l1.tag == 1370u || l1.tag == 1371u || l1.tag == 1374u || l1.tag == 1399u || l1.tag == 1400u || l1.tag == 1415u || l1.tag == 1416u || l1.tag == 1420u || l1.tag == 1423u || l1.tag == 1424u || l1.tag == 1425u || l1.tag == 1426u || l1.tag == 1429u || l1.tag == 1430u || l1.tag == 1431u || l1.tag == 1432u)) {
        l4 = (uint8_t) 8;
    } else if (l1.tag == 1311u) {
        l4 = (uint8_t) 16;
    } else if (l1.tag == 1397u) {
        l4 = (uint8_t) 32;
    } else if ((l1.tag == 1312u || l1.tag == 1313u)) {
        l4 = vader_vm$integer_tags(VADER_UNION_FIELD(uint8_t, vader_struct_vader_core_bytecode$CheckedArith_t, f_kind, l1.payload.obj));
    } else if ((l1.tag == 1264u || l1.tag == 1268u || l1.tag == 1269u || l1.tag == 1271u || l1.tag == 1303u || l1.tag == 1304u || l1.tag == 1315u || l1.tag == 1336u || l1.tag == 1337u || l1.tag == 1394u || l1.tag == 1414u || l1.tag == 1418u || l1.tag == 1421u || l1.tag == 1438u)) {
        l4 = (uint8_t) 64;
    } else if (l1.tag == 1390u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l5, 628u);
        l4 = ((uint8_t) t1.payload.i);
    } else if ((l1.tag == 1392u || l1.tag == 1401u)) {
        l4 = l3;
    } else if (l1.tag == 1398u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        l6 = vader_vm$tags_of_type(l0, l5);
        t2 = (l3 & l6);
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 1314u) {
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
    } else if ((l1.tag == 1417u || l1.tag == 1434u)) {
        l5 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_type_id, l1.payload.obj);
        l7 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_field_index, l1.payload.obj);
        l4 = vader_vm$field_tags(l0, l5, l7);
    } else if (l1.tag == 1389u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
        l4 = vader_vm$field_tags(l0, l5, l7);
    } else if (l1.tag == 1262u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        l4 = vader_vm$element_tags(l0, l5);
    } else if (l1.tag == 1338u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        l4 = vader_vm$global_tags(l0, l5);
    } else if (l1.tag == 1267u) {
        l4 = (uint8_t) 127;
    } else if (l1.tag == 1386u) {
        t2 = (INT32_C(1) | INT32_C(16));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 1387u) {
        t2 = (INT32_C(2) | INT32_C(1));
        l4 = (uint8_t) (int32_t) t2;
    } else if (l1.tag == 1310u) {
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_module)->f_types;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        l9 = vader_core_bytecode$fn_at(l8, l5);
        if (l9.tag == 0u) {
            l4 = (uint8_t) 127;
        } else {
            t0 = l9.payload.obj;
            l5 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_return_type;
            l4 = vader_vm$tags_of_type(l0, l5);
        }
    } else {
        if (!((l1.tag == 1260u || l1.tag == 1261u || l1.tag == 1265u || l1.tag == 1266u || l1.tag == 1270u || l1.tag == 1294u || l1.tag == 1301u || l1.tag == 1302u || l1.tag == 1305u || l1.tag == 1308u || l1.tag == 1309u || l1.tag == 1317u || l1.tag == 1318u || l1.tag == 1319u || l1.tag == 1320u || l1.tag == 1321u || l1.tag == 1339u || l1.tag == 1380u || l1.tag == 1391u || l1.tag == 1393u || l1.tag == 1396u || l1.tag == 1402u || l1.tag == 1403u || l1.tag == 1406u || l1.tag == 1407u || l1.tag == 1408u || l1.tag == 1409u || l1.tag == 1410u || l1.tag == 1411u || l1.tag == 1412u || l1.tag == 1419u || l1.tag == 1435u || l1.tag == 1436u || l1.tag == 1437u))) {
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
    if (!(l0.tag == 2093u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(49) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 584u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    void* l20 = NULL;
    int64_t l7, l8, l11, l12, l16, l21, l22;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l17 = vader_box_null(), l23 = vader_box_null();
    int32_t l15;
    uint8_t l19;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l9, &l10, &l17, &l23 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l4, &l6, &l13, &l14, &l18, &l20, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l5 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_core_bytecode$c_struct_layout(l3, l4);
    l7 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) l3));
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
        l9 = vader_core_bytecode$nested_mirror(t0, l4);
        if (l9.tag == 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
            l17 = vader_core_bytecode$c_field_width(t0, l4);
            if (l17.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l16 = ((int64_t) l17.payload.i);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l18 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
            l19 = vader_vm$field_val_type(l4, l18);
            l20 = ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l21 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l7];
            l22 = vader_chk_add(i64, l1, l21);
            l23 = vader_vm$written_scalar(l0, l22, l16, l19);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l20);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l7] = l23;
            VADER_WRITE_BARRIER(_a4_slotarr->buf);
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l10 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l7];
        if (l10.tag == 2125u) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l6)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
            l11 = ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l7];
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
    if (!(l0.tag == 621u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 585u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l0.payload.b;
    { vader_box_t __vret = vader_box_bool(621u, t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!((l0.tag == 632u || l0.tag == 633u))) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 586u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l0.payload.f);
    { vader_box_t __vret = vader_box_f64(633u, t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l0.tag == 2098u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 587u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    if (l0.tag == 626u) {
        t0 = ((int32_t) l0.payload.i);
        l3 = vader_box_i32(626u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 622u) {
        t1 = ((uint32_t) l0.payload.i);
        l3 = vader_box_i32(626u, ((int32_t) ((int32_t) (uint32_t) t1)));
    } else if (l0.tag == 627u) {
        t2 = ((int64_t) l0.payload.i);
        l3 = vader_box_i32(626u, ((int32_t) (int64_t) t2));
    } else {
        l4 = l2;
        l5 = vader_vm$describe_value_tag(l0);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l7 = vader_host_std_core$Intrinsic$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 130u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 588u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t3 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    if (l0.tag == 627u) {
        t0 = ((int64_t) l0.payload.i);
        l3 = vader_box_i64(627u, t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 626u) {
        t1 = ((int32_t) l0.payload.i);
        l3 = vader_box_i64(627u, ((int64_t) (int32_t) t1));
    } else {
        l4 = l2;
        l5 = vader_vm$describe_value_tag(l0);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l7 = vader_host_std_core$Intrinsic$byte_len(l5);
        l6 = (l6 + l7);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(47) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l8, l6, l4);
        l6 = std_core$write_string_at(l8, l6, 130u);
        l7 = ((int64_t) (int32_t) l1);
        l6 = std_core$write_int(l8, l6, l7);
        l6 = std_core$write_string_at(l8, l6, 589u);
        l6 = std_core$write_string_at(l8, l6, l5);
        t2 = std_core$finish_buffer(l8, l6);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t2;
        t3 = (void*) _a0_obj;
        l3 = vader_ref_box(t3);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$read_little_endian(void* l0, int64_t l1, int64_t l2, bool l3) {
    uint64_t t0;
    int64_t t1;
    t0 = vader_core_bytecode$read_le(l0, l1, l2);
    t1 = vader_vm$at_width(((int64_t) (uint64_t) t0), l2, l3);
    return t1;
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
    if (l0.tag == 626u) {
        t0 = ((int32_t) l0.payload.i);
        l2 = vader_box_f64(633u, ((double) (int32_t) t0));
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 627u) {
        t1 = ((int64_t) l0.payload.i);
        l2 = vader_box_f64(633u, ((double) (int64_t) t1));
    } else if ((l0.tag == 632u || l0.tag == 633u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_f64(633u, t2);
    } else if (l0.tag == 622u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_f64(633u, ((double) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else {
        l3 = vader_vm$describe_value_tag(l0);
        l4 = vader_host_std_core$Intrinsic$byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(55) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l5, l4, 2298u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l5, l4, l6);
        l4 = std_core$write_string_at(l5, l4, 580u);
        l4 = std_core$write_string_at(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 126u);
        t4 = std_core$finish_buffer(l5, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    if (l0.tag == 627u) {
        t0 = ((int64_t) l0.payload.i);
        l2 = vader_box_i64(627u, t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 626u) {
        t1 = ((int32_t) l0.payload.i);
        l2 = vader_box_i64(627u, ((int64_t) (int32_t) t1));
    } else if ((l0.tag == 632u || l0.tag == 633u)) {
        t2 = ((double) l0.payload.f);
        l2 = vader_box_i64(627u, ((int64_t) (double) t2));
    } else if (l0.tag == 622u) {
        t3 = ((uint32_t) l0.payload.i);
        l2 = vader_box_i64(627u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3)));
    } else if (l0.tag == 621u) {
        t4 = l0.payload.b;
        if (t4) {
            l2 = vader_box_i64(627u, INT64_C(1));
        } else {
            l2 = vader_box_i64(627u, INT64_C(0));
        }
    } else {
        l3 = vader_vm$describe_value_tag(l0);
        l4 = vader_host_std_core$Intrinsic$byte_len(l3);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(59) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l5, l4, 2298u);
        l6 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l5, l4, l6);
        l4 = std_core$write_string_at(l5, l4, 580u);
        l4 = std_core$write_string_at(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 127u);
        t5 = std_core$finish_buffer(l5, l4);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    if (!(l0.tag == 2109u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 590u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    if (l0.tag == 621u) {
        t0 = l0.payload.b;
        if (t0) {
            { vader_box_t __vret = vader_box_i64(627u, INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i64(627u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 622u)) {
        t1 = vader_vm$read_i64(l0, l1, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((uint32_t) l0.payload.i);
    { vader_box_t __vret = vader_box_i64(627u, ((int64_t) (uint32_t) ((int32_t) (uint32_t) t2))); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l0.tag == 623u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 591u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.s;
    { vader_box_t __vret = vader_box_string(623u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l0.tag == 2125u)) {
        l3 = l2;
        l4 = vader_vm$describe_value_tag(l0);
        l5 = vader_host_std_core$Intrinsic$byte_len(l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l4);
        l5 = (l5 + l6);
        l7 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l7, l5, l3);
        l5 = std_core$write_string_at(l7, l5, 130u);
        l6 = ((int64_t) (int32_t) l1);
        l5 = std_core$write_int(l7, l5, l6);
        l5 = std_core$write_string_at(l7, l5, 592u);
        l5 = std_core$write_string_at(l7, l5, l4);
        t0 = std_core$finish_buffer(l7, l5);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
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
    if (!(l0.tag == 2125u)) {
        l4 = l0;
        l5 = concat_2(l3, 260u);
        t0 = vader_vm$read_struct(l4, l2, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1 < INT32_C(0))) {
        l6 = true;
    } else {
        l7 = ((int64_t) (int32_t) l1);
        t1 = l0.payload.obj;
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields));
        l6 = (l7 >= l8);
    }
    if (!(l6)) {
        t1 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l1];
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3;
    l7 = vader_host_std_core$Intrinsic$byte_len(l5);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(108) + l7));
    l7 = INT64_C(0);
    l7 = std_core$write_string_at(l9, l7, l5);
    l7 = std_core$write_string_at(l9, l7, 158u);
    l8 = ((int64_t) (int32_t) l1);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 246u);
    t1 = l0.payload.obj;
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields));
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 160u);
    l8 = ((int64_t) (int32_t) l2);
    l7 = std_core$write_int(l9, l7, l8);
    t2 = std_core$finish_buffer(l9, l7);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
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
    l8 = vader_host_std_core$Intrinsic$byte_len(l7);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(36) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l9, l8, l7);
    l8 = std_core$write_string_at(l9, l8, 261u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
    l10 = ((int64_t) (int32_t) t1);
    l8 = std_core$write_int(l9, l8, l10);
    t2 = std_core$finish_buffer(l9, l8);
    t3 = concat_5(t2, 583u, l5, 460u, l6);
    vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a1_obj, 2128u);
    _a1_obj->f_message = t3;
    t4 = (void*) _a1_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$receiver_type_id_of(void* l0, vader_box_t l1) {
    vader_box_t l2;
    int32_t t0;
    if ((l1.tag == 2093u || l1.tag == 2098u || l1.tag == 2125u)) {
        t0 = VADER_UNION_FIELD(int32_t, vader_struct_vader_vm$ArrayVal_t, f_type_id, l1.payload.obj);
        return t0;
    }
    l2 = l1;
    t0 = vader_vm$primitive_type_id(l0, l2);
    return t0;
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
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(445u, (int64_t) t0, 13u, 2093u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l0));
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        vader_array_t* _a2_arr = vader_array_new(503u, 0u, 0u, 3020u);
        l7 = (void*) _a2_arr;
        if (l6.tag == 1285u) {
            t1 = l6.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$BcStrData_t*) t1)->f_values;
            l9 = vader_array_length(((vader_array_t*) l8));
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l10];
                l11 = t2.payload.s;
                vader_array_push((vader_array_t*) l7, vader_box_string(623u, l11));
                l10 = (l10 + INT64_C(1));
            }
        } else if (l6.tag == 1281u) {
            t1 = l6.payload.obj;
            l12 = ((vader_struct_vader_core_bytecode$BcPrimData_t*) t1)->f_items;
            l13 = vader_array_length(((vader_array_t*) l12));
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t0 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l14];
                l15 = (uint64_t) (int64_t) t0;
                t1 = l6.payload.obj;
                l16 = vader_vm$value_from_bits(((vader_struct_vader_core_bytecode$BcPrimData_t*) t1)->f_kind, l15);
                vader_array_push((vader_array_t*) l7, l16);
                l14 = (l14 + INT64_C(1));
            }
        } else if (l6.tag == 1272u) {
            t1 = l6.payload.obj;
            l17 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t1)->f_elements;
            l18 = vader_array_length(((vader_array_t*) l17));
            l19 = INT64_C(0);
            while ((l19 < l18)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l19);
                l20 = vader_vm$bc_value_to_vm(t2, l1);
                vader_array_push((vader_array_t*) l7, l20);
                l19 = (l19 + INT64_C(1));
            }
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
        t3 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l4];
        vader_struct_vader_vm$ArrayVal_t* _a7_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
        vader_obj_header_init(_a7_obj, 2093u);
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
        if (l1.tag == 2125u) {
            l3 = true;
            return l3;
        }
        if (l1.tag == 2093u) {
            l3 = true;
        } else if (l1.tag == 2098u) {
            l3 = true;
        } else {
            l3 = false;
        }
        return l3;
    }
    if ((l1.tag == 2093u || l1.tag == 2098u || l1.tag == 2125u)) {
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
    void* l603 = NULL;
    void* l605 = NULL;
    void* l612 = NULL;
    void* l620 = NULL;
    void* l623 = NULL;
    void* l668 = NULL;
    void* l674 = NULL;
    void* l676 = NULL;
    void* l731 = NULL;
    void* l751 = NULL;
    void* l764 = NULL;
    void* l766 = NULL;
    int64_t l9, l10, l11, l12, l13, l20, l21, l22, l23, l24, l25, l28, l29, l30, l31, l32, l55, l56, l63, l64, l114, l115, l124, l125, l193, l195, l196, l199, l201, l202, l205, l207, l208, l210, l212, l213, l216, l218, l220, l221, l224, l227, l229, l230, l233, l235, l236, l239, l241, l242, l245, l247, l248, l251, l253, l254, l260, l263, l264, l267, l269, l271, l272, l277, l279, l281, l282, l287, l290, l292, l296, l298, l302, l304, l308, l310, l314, l316, l320, l322, l434, l438, l442, l446, l448, l452, l455, l458, l461, l463, l466, l469, l472, l476, l480, l484, l488, l490, l498, l500, l505, l525, l527, l529, l531, l533, l535, l537, l539, l556, l560, l561, l565, l566, l571, l572, l578, l579, l581, l583, l584, l589, l590, l594, l595, l596, l600, l602, l607, l608, l610, l611, l613, l614, l615, l616, l621, l622, l626, l627, l632, l633, l634, l635, l644, l645, l666, l667, l672, l673, l677, l678, l680, l681, l685, l686, l688, l689, l691, l695, l697, l698, l700, l701, l702, l703, l704, l706, l711, l712, l713, l719, l720, l722, l723, l724, l725, l727, l732, l733, l734, l735, l736, l737, l738, l739, l740, l741, l742, l743, l744, l745, l746, l747, l748, l750, l752, l753, l757, l758, l759, l760, l761, l762, l763, l765, l767;
    int32_t l19, l34, l35, l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l57, l58, l59, l60, l61, l65, l66, l67, l68, l69, l70, l71, l72, l73, l74, l75, l76, l77, l78, l79, l80, l81, l82, l83, l84, l85, l86, l87, l88, l89, l90, l91, l92, l93, l94, l95, l96, l97, l98, l100, l101, l103, l104, l105, l106, l107, l108, l109, l110, l111, l112, l116, l117, l120, l121, l122, l126, l127, l130, l131, l132, l133, l134, l135, l137, l138, l139, l140, l141, l143, l144, l145, l146, l147, l149, l150, l151, l152, l153, l155, l156, l157, l158, l159, l161, l162, l163, l164, l165, l167, l168, l170, l173, l174, l176, l179, l180, l182, l185, l186, l188, l191, l192, l194, l197, l198, l200, l203, l204, l206, l209, l214, l215, l217, l222, l223, l225, l226, l228, l231, l232, l234, l237, l238, l240, l243, l244, l246, l249, l250, l252, l255, l256, l258, l261, l262, l265, l266, l268, l273, l274, l278, l283, l284, l288, l289, l291, l294, l295, l297, l300, l301, l303, l306, l307, l309, l312, l313, l315, l318, l319, l321, l324, l325, l327, l330, l331, l333, l336, l337, l339, l342, l343, l345, l348, l349, l351, l354, l355, l357, l360, l361, l363, l366, l367, l369, l372, l373, l375, l376, l378, l381, l382, l384, l387, l388, l390, l393, l394, l396, l399, l400, l402, l405, l406, l408, l411, l412, l414, l417, l418, l420, l423, l424, l426, l427, l428, l430, l431, l432, l436, l437, l440, l441, l444, l445, l447, l450, l451, l454, l457, l460, l462, l465, l468, l471, l474, l478, l482, l486, l489, l492, l493, l494, l495, l496, l497, l499, l501, l502, l503, l506, l507, l508, l509, l510, l511, l512, l513, l514, l515, l516, l517, l518, l519, l520, l521, l522, l523, l524, l526, l528, l530, l532, l534, l536, l538, l540, l542, l544, l546, l548, l550, l552, l554, l559, l562, l569, l570, l575, l576, l580, l582, l587, l593, l599, l601, l606, l624, l629, l637, l639, l640, l641, l648, l649, l650, l652, l653, l654, l655, l656, l658, l659, l660, l661, l662, l663, l670, l671, l682, l687, l693, l709, l710, l715, l716, l717, l756;
    uint8_t l26, l33, l475, l479, l483, l487, l705, l726, l749;
    vader_box_t l27 = vader_box_null(), l435 = vader_box_null(), l439 = vader_box_null(), l443 = vader_box_null(), l449 = vader_box_null(), l453 = vader_box_null(), l456 = vader_box_null(), l459 = vader_box_null(), l464 = vader_box_null(), l467 = vader_box_null(), l470 = vader_box_null(), l473 = vader_box_null(), l477 = vader_box_null(), l481 = vader_box_null(), l485 = vader_box_null(), l491 = vader_box_null(), l557 = vader_box_null(), l558 = vader_box_null(), l563 = vader_box_null(), l564 = vader_box_null(), l568 = vader_box_null(), l574 = vader_box_null(), l586 = vader_box_null(), l592 = vader_box_null(), l598 = vader_box_null(), l609 = vader_box_null(), l617 = vader_box_null(), l618 = vader_box_null(), l619 = vader_box_null(), l625 = vader_box_null(), l628 = vader_box_null(), l636 = vader_box_null(), l638 = vader_box_null(), l642 = vader_box_null(), l643 = vader_box_null(), l646 = vader_box_null(), l664 = vader_box_null(), l665 = vader_box_null(), l669 = vader_box_null(), l675 = vader_box_null(), l679 = vader_box_null(), l690 = vader_box_null(), l694 = vader_box_null(), l707 = vader_box_null(), l708 = vader_box_null(), l714 = vader_box_null(), l728 = vader_box_null(), l729 = vader_box_null(), l730 = vader_box_null();
    uint32_t l99, l102, l118, l119, l128, l129, l169, l171, l175, l177, l181, l183, l187, l189, l504, l541, l543, l545, l547;
    bool l136, l142, l148, l154, l160, l166, l172, l178, l184, l190, l293, l299, l305, l311, l317, l323, l329, l335, l341, l347, l380, l386, l392, l398, l404, l410, l413, l415, l416, l419, l421, l422, l425, l429, l433, l577, l588, l630, l631, l647, l651, l657, l683, l684, l692, l696, l699, l718, l721, l754, l755;
    uint64_t l257, l259, l275, l276, l285, l286, l326, l328, l332, l334, l338, l340, l344, l346, l549, l551, l553, l555;
    double l350, l352, l353, l356, l358, l359, l362, l364, l365, l368, l370, l371, l374, l377, l379, l383, l385, l389, l391, l395, l397, l401, l403, l407, l409;
    vader_string_t l567 = 0;
    vader_string_t l573 = 0;
    vader_string_t l585 = 0;
    vader_string_t l591 = 0;
    vader_string_t l597 = 0;
    vader_string_t l604 = 0;
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
    vader_box_t* gc_roots[50] = {
        &l27, &l435, &l439, &l443, &l449, &l453, &l456, &l459, &l464, &l467, &l470, &l473, &l477,
        &l481, &l485, &l491, &l557, &l558, &l563, &l564, &l568, &l574, &l586, &l592, &l598, &l609,
        &l617, &l618, &l619, &l625, &l628, &l636, &l638, &l642, &l643, &l646, &l664, &l665, &l669,
        &l675, &l679, &l690, &l694, &l707, &l708, &l714, &l728, &l729, &l730, &t3,
    };
    void** gc_raw_roots[30] = {
        &l0, &l1, &l2, &l8, &l14, &l15, &l16, &l17, &l18, &l54, &l62, &l113, &l123, &l211, &l219,
        &l270, &l280, &l603, &l605, &l612, &l620, &l623, &l668, &l674, &l676, &l731, &l751, &l764,
        &l766, &t1,
    };
    vader_string_t* gc_atom_roots[7] = { &l567, &l573, &l585, &l591, &l597, &l604, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 50u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l8 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l9 = ((int64_t) 1024);
    if ((l5 >= l9)) {
        t0 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_name;
        t1 = vader_vm$overflow_trap(t0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_vm$enter_frame(l2, l8, l4);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code));
    if ((l5 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        vader_array_ref_store(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5, l8);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l5] = (int64_t) l6;
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
        l19 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l13];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
        l20 = ((int64_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l13];
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
            l25 = ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l24];
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l22)
            ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l22] = (int64_t) l25;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l24)
            t3 = vader_array_read_u8(_a7_slotarr, vader_array_offset(_a7_slotarr) + (size_t) l24, 628u);
            l26 = ((uint8_t) t3.payload.i);
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l22)
            ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l22] = (uint8_t) (int32_t) (uint8_t) l26;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l24)
            l27 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l24];
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l22)
            vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l22] = l27;
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
            l32 = ((int64_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l31];
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l29)
            ((int64_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l29] = (int64_t) l32;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l31)
            t3 = vader_array_read_u8(_a10_slotarr, vader_array_offset(_a10_slotarr) + (size_t) l31, 628u);
            l33 = ((uint8_t) t3.payload.i);
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l29)
            ((uint8_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l29] = (uint8_t) (int32_t) (uint8_t) l33;
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
                l55 = std_core$write_string_at(l54, l55, 2643u);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
                t2 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l13];
                l56 = ((int64_t) (int32_t) t2);
                l55 = std_core$write_int(l54, l55, l56);
                t0 = std_core$finish_buffer(l54, l55);
                vader_struct_vader_vm$Trap_t* _a12_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a12_obj, 2128u);
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
                l63 = std_core$write_string_at(l62, l63, 2649u);
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
                t2 = ((int32_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l13];
                l64 = ((int64_t) (int32_t) t2);
                l63 = std_core$write_int(l62, l63, l64);
                t0 = std_core$finish_buffer(l62, l63);
                vader_struct_vader_vm$Trap_t* _a14_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a14_obj, 2128u);
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
                l114 = std_core$write_string_at(l113, l114, 3430u);
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
                t2 = ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l13];
                l115 = ((int64_t) (int32_t) t2);
                l114 = std_core$write_int(l113, l114, l115);
                t0 = std_core$finish_buffer(l113, l114);
                vader_struct_vader_vm$Trap_t* _a16_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a16_obj, 2128u);
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
                l124 = std_core$write_string_at(l123, l124, 3436u);
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
                t2 = ((int32_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l13];
                l125 = ((int64_t) (int32_t) t2);
                l124 = std_core$write_int(l123, l124, l125);
                t0 = std_core$finish_buffer(l123, l124);
                vader_struct_vader_vm$Trap_t* _a18_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a18_obj, 2128u);
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
                l212 = std_core$write_string_at(l211, l212, 2665u);
                vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l13)
                t2 = ((int32_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l13];
                l213 = ((int64_t) (int32_t) t2);
                l212 = std_core$write_int(l211, l212, l213);
                t0 = std_core$finish_buffer(l211, l212);
                vader_struct_vader_vm$Trap_t* _a20_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a20_obj, 2128u);
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
                l220 = std_core$write_string_at(l219, l220, 2675u);
                vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l13)
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l13];
                l221 = ((int64_t) (int32_t) t2);
                l220 = std_core$write_int(l219, l220, l221);
                t0 = std_core$finish_buffer(l219, l220);
                vader_struct_vader_vm$Trap_t* _a22_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a22_obj, 2128u);
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
                l271 = std_core$write_string_at(l270, l271, 3440u);
                vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l13)
                t2 = ((int32_t*) _a23_slotarr->buf->slots)[vader_array_offset(_a23_slotarr) + (size_t) l13];
                l272 = ((int64_t) (int32_t) t2);
                l271 = std_core$write_int(l270, l271, l272);
                t0 = std_core$finish_buffer(l270, l271);
                vader_struct_vader_vm$Trap_t* _a24_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a24_obj, 2128u);
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
                l281 = std_core$write_string_at(l280, l281, 3446u);
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l13)
                t2 = ((int32_t*) _a25_slotarr->buf->slots)[vader_array_offset(_a25_slotarr) + (size_t) l13];
                l282 = ((int64_t) (int32_t) t2);
                l281 = std_core$write_int(l280, l281, l282);
                t0 = std_core$finish_buffer(l280, l281);
                vader_struct_vader_vm$Trap_t* _a26_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                vader_obj_header_init(_a26_obj, 2128u);
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
                t3 = vader_array_read_u8(_a27_slotarr, vader_array_offset(_a27_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a28_slotarr, vader_array_offset(_a28_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a29_slotarr, vader_array_offset(_a29_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a30_slotarr, vader_array_offset(_a30_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a31_slotarr, vader_array_offset(_a31_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a32_slotarr, vader_array_offset(_a32_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a33_slotarr, vader_array_offset(_a33_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a34_slotarr, vader_array_offset(_a34_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a35_slotarr, vader_array_offset(_a35_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a36_slotarr, vader_array_offset(_a36_slotarr) + (size_t) l13, 628u);
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
                t3 = vader_array_read_u8(_a37_slotarr, vader_array_offset(_a37_slotarr) + (size_t) l13, 628u);
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
            t3 = vader_array_read_u8(_a38_slotarr, vader_array_offset(_a38_slotarr) + (size_t) l13, 628u);
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
            t3 = vader_array_read_u8(_a39_slotarr, vader_array_offset(_a39_slotarr) + (size_t) l13, 628u);
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
            t3 = vader_array_read_u8(_a40_slotarr, vader_array_offset(_a40_slotarr) + (size_t) l13, 628u);
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
            t3 = vader_array_read_u8(_a41_slotarr, vader_array_offset(_a41_slotarr) + (size_t) l13, 628u);
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
                l558 = l557;
                if (l557.tag == 2128u) {
                    t1 = l558.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(121)) {
                vader_vm$note_host_call(l2, l13, l11);
                l559 = vader_vm$operand_a(l20);
                t2 = vader_vm$operand_b(l20);
                l560 = ((int64_t) (int32_t) t2);
                l561 = vader_chk_add(i64, l12, l560);
                vader_array_t* _a42_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l13)
                l562 = ((int32_t*) _a42_slotarr->buf->slots)[vader_array_offset(_a42_slotarr) + (size_t) l13];
                l563 = vader_vm$call_import(l0, l2, l559, l561, l562, l7);
                l564 = l563;
                if (l563.tag == 2128u) {
                    t1 = l564.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else if (l19 == INT32_C(122)) {
                t2 = vader_vm$operand_b(l20);
                l565 = ((int64_t) (int32_t) t2);
                l566 = vader_chk_add(i64, l12, l565);
                l568 = vader_vm$string_at(l2, l566);
                if (l568.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l566, l8, l13, 2144u, 3236u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l567 = l568.payload.s;
                l569 = vader_vm$operand_a(l20);
                t6 = vader_host_std_core$Intrinsic$byte_len(l567);
                l570 = ((int32_t) (int64_t) t6);
                vader_vm$set_i32(l16, l17, l12, l569, l570);
            } else if (l19 == INT32_C(123)) {
                t2 = vader_vm$operand_b(l20);
                l571 = ((int64_t) (int32_t) t2);
                l572 = vader_chk_add(i64, l12, l571);
                l574 = vader_vm$string_at(l2, l572);
                if (l574.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l572, l8, l13, 2143u, 3236u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l573 = l574.payload.s;
                l575 = vader_vm$operand_c(l20);
                l576 = vader_vm$i32_of(l16, l12, l575);
                if ((l576 < INT32_C(0))) {
                    l577 = true;
                } else {
                    l578 = ((int64_t) (int32_t) l576);
                    l579 = vader_host_std_core$Intrinsic$byte_len(l573);
                    l577 = (l578 >= l579);
                }
                if (l577) {
                    vader_struct_vader_vm$Trap_t* _a43_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a43_obj, 2128u);
                    _a43_obj->f_message = 2142u;
                    t1 = (void*) _a43_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l580 = vader_vm$operand_a(l20);
                l581 = ((int64_t) (int32_t) l576);
                t10 = vader_host_std_core$Intrinsic$byte_at(l573, l581);
                l582 = ((int32_t) (uint8_t) t10);
                vader_vm$set_i32(l16, l17, l12, l580, l582);
            } else if (l19 == INT32_C(125)) {
                t2 = vader_vm$operand_b(l20);
                l583 = ((int64_t) (int32_t) t2);
                l584 = vader_chk_add(i64, l12, l583);
                l586 = vader_vm$string_at(l2, l584);
                if (l586.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l584, l8, l13, 2779u, 3236u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l585 = l586.payload.s;
                l587 = vader_vm$operand_a(l20);
                l588 = vader_host_std_core$Intrinsic$is_ascii(l585);
                vader_vm$set_bool(l16, l17, l12, l587, l588);
            } else if (l19 == INT32_C(126)) {
                t2 = vader_vm$operand_b(l20);
                l589 = ((int64_t) (int32_t) t2);
                l590 = vader_chk_add(i64, l12, l589);
                l592 = vader_vm$string_at(l2, l590);
                if (l592.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l590, l8, l13, 2627u, 3236u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l591 = l592.payload.s;
                l593 = vader_vm$operand_a(l20);
                t8 = vader_host_std_core$Intrinsic$string_hash(l591);
                l594 = ((int64_t) (uint64_t) t8);
                vader_vm$set_i64(l16, l17, l12, l593, l594);
            } else if (l19 == INT32_C(124)) {
                t2 = vader_vm$operand_a(l20);
                l595 = ((int64_t) (int32_t) t2);
                l596 = vader_chk_add(i64, l12, l595);
                l598 = vader_vm$string_at(l2, l596);
                if (l598.tag == 0u) {
                    t1 = vader_vm$receiver_trap(l2, l596, l8, l13, 2145u, 3236u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l597 = l598.payload.s;
                l599 = vader_vm$operand_b(l20);
                l600 = vader_vm$bits_of(l16, l12, l599);
                l601 = vader_vm$operand_c(l20);
                l602 = vader_vm$bits_of(l16, l12, l601);
                l603 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_refs;
                l604 = vader_host_std_core$Intrinsic$byte_slice(l597, l600, l602);
                vader_array_t* _a44_slotarr = ((vader_array_t*) l603);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l596)
                vader_array_box_slots(_a44_slotarr->buf)[vader_array_offset(_a44_slotarr) + (size_t) l596] = vader_box_string(623u, l604);
                VADER_WRITE_BARRIER(_a44_slotarr->buf);
                vader_array_t* _a45_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l596)
                ((uint8_t*) _a45_slotarr->buf->slots)[vader_array_offset(_a45_slotarr) + (size_t) l596] = (uint8_t) INT32_C(6);
            } else {
                if (l19 == INT32_C(127)) {
                    l605 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_texts;
                    l606 = vader_vm$operand_a(l20);
                    vader_array_t* _a46_slotarr = ((vader_array_t*) l605);
                    VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l606)
                    t3 = vader_array_box_slots(_a46_slotarr->buf)[vader_array_offset(_a46_slotarr) + (size_t) l606];
                    t0 = t3.payload.s;
                    vader_struct_vader_vm$Trap_t* _a47_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                    vader_obj_header_init(_a47_obj, 2128u);
                    _a47_obj->f_message = t0;
                    t1 = (void*) _a47_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l19 == INT32_C(128)) {
                    t2 = vader_vm$operand_a(l20);
                    l607 = ((int64_t) (int32_t) t2);
                    l608 = vader_chk_add(i64, l12, l607);
                    l609 = vader_vm$register_value(l2, l608);
                    l610 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
                    l611 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers));
                    if ((l610 < l611)) {
                        l612 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers;
                        l613 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
                        vader_array_t* _a48_slotarr = ((vader_array_t*) l612);
                        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l613)
                        vader_array_box_slots(_a48_slotarr->buf)[vader_array_offset(_a48_slotarr) + (size_t) l613] = l609;
                        VADER_WRITE_BARRIER(_a48_slotarr->buf);
                    } else {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers, l609);
                    }
                    t6 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
                    l614 = vader_chk_add(i64, t6, INT64_C(1));
                    ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count = l614;
                } else if (l19 == INT32_C(129)) {
                    l615 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_registers;
                    l616 = vader_chk_add(i64, l12, l615);
                    l617 = vader_vm$run_defers(l0, l1, l2, l8, l13, l616, l11, l7);
                    l618 = l617;
                    if (l617.tag == 2128u) {
                        t1 = l618.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else if (l19 == INT32_C(130)) {
                    l619 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_debug;
                    if (!(l619.tag == 0u)) {
                        l620 = l619.payload.obj;
                        vader_vm$stop_at_line(l0, l2, l620, l8, l13, l11);
                    }
                } else if (l19 == INT32_C(110)) {
                    t2 = vader_vm$operand_a(l20);
                    l621 = ((int64_t) (int32_t) t2);
                    l622 = vader_chk_add(i64, l12, l621);
                    l623 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_values;
                    l624 = vader_vm$operand_b(l20);
                    vader_array_t* _a49_slotarr = ((vader_array_t*) l623);
                    VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l624)
                    l625 = vader_array_box_slots(_a49_slotarr->buf)[vader_array_offset(_a49_slotarr) + (size_t) l624];
                    vader_array_t* _a50_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l622)
                    vader_array_box_slots(_a50_slotarr->buf)[vader_array_offset(_a50_slotarr) + (size_t) l622] = l625;
                    VADER_WRITE_BARRIER(_a50_slotarr->buf);
                    vader_array_t* _a51_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l622)
                    ((uint8_t*) _a51_slotarr->buf->slots)[vader_array_offset(_a51_slotarr) + (size_t) l622] = (uint8_t) INT32_C(6);
                } else if (l19 == INT32_C(111)) {
                    t2 = vader_vm$operand_b(l20);
                    l626 = ((int64_t) (int32_t) t2);
                    l627 = vader_chk_add(i64, l12, l626);
                    vader_array_t* _a52_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l627)
                    l628 = vader_array_box_slots(_a52_slotarr->buf)[vader_array_offset(_a52_slotarr) + (size_t) l627];
                    l629 = vader_vm$operand_c(l20);
                    if (l628.tag == 2125u) {
                        l630 = (l629 >= INT32_C(0));
                    } else {
                        l630 = false;
                    }
                    if (l630) {
                        l632 = ((int64_t) (int32_t) l629);
                        t1 = l628.payload.obj;
                        l633 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields));
                        l631 = (l632 < l633);
                    } else {
                        l631 = false;
                    }
                    if (l631) {
                        t2 = vader_vm$operand_a(l20);
                        l634 = ((int64_t) (int32_t) t2);
                        l635 = vader_chk_add(i64, l12, l634);
                        t1 = l628.payload.obj;
                        vader_array_t* _a53_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t1)->f_fields);
                        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l629)
                        l636 = vader_array_box_slots(_a53_slotarr->buf)[vader_array_offset(_a53_slotarr) + (size_t) l629];
                        vader_vm$set_register(l2, l635, l636);
                    } else {
                        vader_array_t* _a54_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                        VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a54_slotarr, l13)
                        l637 = ((int32_t*) _a54_slotarr->buf->slots)[vader_array_offset(_a54_slotarr) + (size_t) l13];
                        l638 = vader_vm$read_struct_field(l628, l629, l637, 3258u);
                        if (l638.tag == 2128u) {
                            t1 = l638.payload.obj;
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    }
                } else if (l19 == INT32_C(112)) {
                    l639 = vader_vm$operand_a(l20);
                    l640 = vader_vm$operand_b(l20);
                    l641 = vader_vm$operand_c(l20);
                    l642 = vader_vm$set_field(l2, l12, l639, l640, l641, l8, l13);
                    l643 = l642;
                    if (l642.tag == 2128u) {
                        t1 = l643.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else if (l19 == INT32_C(113)) {
                    t2 = vader_vm$operand_b(l20);
                    l644 = ((int64_t) (int32_t) t2);
                    l645 = vader_chk_add(i64, l12, l644);
                    l646 = vader_vm$struct_at(l2, l645);
                    if (!(l646.tag == 0u)) {
                        t1 = l646.payload.obj;
                        l648 = ((vader_struct_vader_vm$StructVal_t*) t1)->f_type_id;
                        l649 = vader_vm$operand_c(l20);
                        l647 = l648 == l649;
                    } else {
                        l647 = false;
                    }
                    l650 = vader_vm$operand_a(l20);
                    vader_vm$set_bool(l16, l17, l12, l650, l647);
                } else {
                    if (l19 == INT32_C(114)) {
                        l651 = true;
                    } else {
                        l651 = l19 == INT32_C(116);
                    }
                    if (l651) {
                        l652 = vader_vm$operand_a(l20);
                        l653 = vader_vm$operand_b(l20);
                        l654 = vader_vm$operand_c(l20);
                        t11 = vader_vm$try_get_element(l2, l12, l652, l653, l654);
                        if (!(t11)) {
                            l655 = vader_vm$operand_b(l20);
                            l656 = vader_vm$operand_c(l20);
                            t1 = vader_vm$element_trap(l2, l12, l655, l656, l8, l13, l19);
                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                    } else {
                        if (l19 == INT32_C(115)) {
                            l657 = true;
                        } else {
                            l657 = l19 == INT32_C(117);
                        }
                        if (l657) {
                            l658 = vader_vm$operand_a(l20);
                            l659 = vader_vm$operand_b(l20);
                            l660 = vader_vm$operand_c(l20);
                            t11 = vader_vm$try_set_element(l2, l12, l658, l659, l660);
                            if (!(t11)) {
                                l661 = vader_vm$operand_a(l20);
                                l662 = vader_vm$operand_b(l20);
                                l663 = vader_vm$operand_c(l20);
                                l664 = vader_vm$set_element(l2, l12, l661, l662, l663, l8, l13, l19);
                                l665 = l664;
                                if (l664.tag == 2128u) {
                                    t1 = l665.payload.obj;
                                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                            }
                        } else if (l19 == INT32_C(118)) {
                            t2 = vader_vm$operand_b(l20);
                            l666 = ((int64_t) (int32_t) t2);
                            l667 = vader_chk_add(i64, l12, l666);
                            l669 = vader_vm$array_at(l2, l667);
                            if (l669.tag == 0u) {
                                t1 = vader_vm$receiver_trap(l2, l667, l8, l13, 2030u, 2015u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l668 = l669.payload.obj;
                            l670 = vader_vm$operand_a(l20);
                            t6 = vader_vm$element_count(l668);
                            l671 = ((int32_t) (int64_t) t6);
                            vader_vm$set_i32(l16, l17, l12, l670, l671);
                        } else if (l19 == INT32_C(119)) {
                            t2 = vader_vm$operand_a(l20);
                            l672 = ((int64_t) (int32_t) t2);
                            l673 = vader_chk_add(i64, l12, l672);
                            l675 = vader_vm$array_at(l2, l673);
                            if (l675.tag == 0u) {
                                t1 = vader_vm$receiver_trap(l2, l673, l8, l13, 2033u, 2015u);
                                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            l674 = l675.payload.obj;
                            if (!(((vader_struct_vader_vm$ArrayVal_t*) l674)->f_raw.tag == 0u)) {
                                vader_vm$own_bytes(l674);
                            }
                            l676 = ((vader_struct_vader_vm$ArrayVal_t*) l674)->f_elements;
                            t2 = vader_vm$operand_b(l20);
                            l677 = ((int64_t) (int32_t) t2);
                            l678 = vader_chk_add(i64, l12, l677);
                            l679 = vader_vm$register_value(l2, l678);
                            vader_array_push((vader_array_t*) l676, l679);
                        } else if (l19 == INT32_C(106)) {
                            t2 = vader_vm$operand_a(l20);
                            l680 = ((int64_t) (int32_t) t2);
                            l681 = vader_chk_add(i64, l12, l680);
                            l682 = vader_vm$operand_b(l20);
                            vader_vm$narrow_register(l2, l681, l682);
                        } else {
                            if (l19 == INT32_C(103)) {
                                l683 = true;
                            } else {
                                l683 = l19 == INT32_C(104);
                            }
                            if (l683) {
                                l684 = true;
                            } else {
                                l684 = l19 == INT32_C(105);
                            }
                            if (l684) {
                                t2 = vader_vm$operand_b(l20);
                                l685 = ((int64_t) (int32_t) t2);
                                l686 = vader_chk_add(i64, l12, l685);
                                l687 = vader_vm$operand_a(l20);
                                if (l19 == INT32_C(104)) {
                                    t2 = vader_vm$operand_c(l20);
                                    l688 = ((int64_t) (int32_t) t2);
                                    l689 = vader_chk_add(i64, l686, l688);
                                    vader_array_t* _a55_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l689)
                                    l690 = vader_array_box_slots(_a55_slotarr->buf)[vader_array_offset(_a55_slotarr) + (size_t) l689];
                                    l691 = vader_chk_add(i64, l686, l688);
                                    vader_array_t* _a56_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l691)
                                    t3 = vader_array_read_u8(_a56_slotarr, vader_array_offset(_a56_slotarr) + (size_t) l691, 628u);
                                    if (((int32_t) t3.payload.i) == INT32_C(6)) {
                                        l692 = l690.tag == 2098u;
                                    } else {
                                        l692 = false;
                                    }
                                    if (!(l692)) {
                                        vader_array_t* _a57_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l13)
                                        l710 = ((int32_t*) _a57_slotarr->buf->slots)[vader_array_offset(_a57_slotarr) + (size_t) l13];
                                        t1 = vader_vm$indirect_call_trap(l1, l2, l686, l688, l710);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    t1 = l690.payload.obj;
                                    l693 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_function_index;
                                    t1 = l690.payload.obj;
                                    l694 = ((vader_struct_vader_vm$FnVal_t*) t1)->f_env;
                                    if (l694.tag == 0u) {
                                        l695 = l688;
                                    } else {
                                        l695 = vader_chk_add(i64, l688, INT64_C(1));
                                    }
                                    if ((l693 >= INT32_C(0))) {
                                        l697 = ((int64_t) (int32_t) l693);
                                        l698 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions));
                                        l696 = (l697 < l698);
                                    } else {
                                        l696 = false;
                                    }
                                    if (l696) {
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l693)
                                        t1 = vader_array_ref_load_obj(_a58_slotarr->buf, vader_array_offset(_a58_slotarr) + (size_t) l693);
                                        t6 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_params;
                                        l699 = t6 == l695;
                                    } else {
                                        l699 = false;
                                    }
                                    if (!(l699)) {
                                        vader_array_t* _a59_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_origin);
                                        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l13)
                                        l709 = ((int32_t*) _a59_slotarr->buf->slots)[vader_array_offset(_a59_slotarr) + (size_t) l13];
                                        t1 = vader_vm$indirect_call_trap(l1, l2, l686, l688, l709);
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    if (!(l694.tag == 0u)) {
                                        l700 = l688;
                                        while ((l700 > INT64_C(0))) {
                                            l701 = vader_chk_add(i64, l686, l700);
                                            l702 = vader_chk_sub(i64, l701, INT64_C(1));
                                            vader_array_t* _a60_slotarr = ((vader_array_t*) l16);
                                            VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l702)
                                            l703 = ((int64_t*) _a60_slotarr->buf->slots)[vader_array_offset(_a60_slotarr) + (size_t) l702];
                                            VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l701)
                                            ((int64_t*) _a60_slotarr->buf->slots)[vader_array_offset(_a60_slotarr) + (size_t) l701] = (int64_t) l703;
                                            l704 = vader_chk_sub(i64, l701, INT64_C(1));
                                            vader_array_t* _a61_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a61_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l704)
                                            t3 = vader_array_read_u8(_a61_slotarr, vader_array_offset(_a61_slotarr) + (size_t) l704, 628u);
                                            l705 = ((uint8_t) t3.payload.i);
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l701)
                                            ((uint8_t*) _a61_slotarr->buf->slots)[vader_array_offset(_a61_slotarr) + (size_t) l701] = (uint8_t) (int32_t) (uint8_t) l705;
                                            l706 = vader_chk_sub(i64, l701, INT64_C(1));
                                            vader_array_t* _a62_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l706)
                                            l707 = vader_array_box_slots(_a62_slotarr->buf)[vader_array_offset(_a62_slotarr) + (size_t) l706];
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l701)
                                            vader_array_box_slots(_a62_slotarr->buf)[vader_array_offset(_a62_slotarr) + (size_t) l701] = l707;
                                            VADER_WRITE_BARRIER(_a62_slotarr->buf);
                                            l700 = vader_chk_sub(i64, l700, INT64_C(1));
                                        }
                                        l708 = l694;
                                        vader_vm$set_register(l2, l686, l708);
                                    }
                                    l687 = l693;
                                } else if (l19 == INT32_C(105)) {
                                    l711 = ((int64_t) (int32_t) l687);
                                    t2 = vader_vm$operand_c(l20);
                                    l712 = ((int64_t) (int32_t) t2);
                                    t6 = vader_chk_add(i64, l686, l712);
                                    l713 = vader_chk_sub(i64, t6, INT64_C(1));
                                    vader_array_t* _a63_slotarr = ((vader_array_t*) l18);
                                    VADER_ARRAY_RESOLVE_BUF(_a63_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a63_slotarr, l713)
                                    l714 = vader_array_box_slots(_a63_slotarr->buf)[vader_array_offset(_a63_slotarr) + (size_t) l713];
                                    vader_array_t* _a64_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l713)
                                    t3 = vader_array_read_u8(_a64_slotarr, vader_array_offset(_a64_slotarr) + (size_t) l713, 628u);
                                    if (((int32_t) t3.payload.i) != INT32_C(6)) {
                                        l715 = INT32_C(-1);
                                    } else if (l714.tag == 2125u) {
                                        t1 = l714.payload.obj;
                                        l715 = ((vader_struct_vader_vm$StructVal_t*) t1)->f_type_id;
                                    } else if (l714.tag == 2093u) {
                                        t1 = l714.payload.obj;
                                        l715 = ((vader_struct_vader_vm$ArrayVal_t*) t1)->f_type_id;
                                    } else {
                                        l715 = INT32_C(-1);
                                    }
                                    if ((l715 < INT32_C(0))) {
                                        l716 = INT32_C(-1);
                                    } else {
                                        vader_array_t* _a65_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l8)->f_virtual_rows);
                                        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l711)
                                        l716 = ((int32_t*) _a65_slotarr->buf->slots)[vader_array_offset(_a65_slotarr) + (size_t) l711];
                                    }
                                    l717 = vader_vm$lookup_vtable_row(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_vtables, l716, l715);
                                    if ((l717 >= INT32_C(0))) {
                                        l719 = ((int64_t) (int32_t) l717);
                                        l720 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions));
                                        l718 = (l719 < l720);
                                    } else {
                                        l718 = false;
                                    }
                                    if (l718) {
                                        vader_array_t* _a66_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l717)
                                        t1 = vader_array_ref_load_obj(_a66_slotarr->buf, vader_array_offset(_a66_slotarr) + (size_t) l717);
                                        t6 = ((vader_struct_vader_vm$RegFunction_t*) t1)->f_params;
                                        l721 = t6 == l712;
                                    } else {
                                        l721 = false;
                                    }
                                    if (l721) {
                                        if ((l713 > l686)) {
                                            l722 = l713;
                                            while ((l722 > l686)) {
                                                l723 = vader_chk_sub(i64, l722, INT64_C(1));
                                                vader_array_t* _a67_slotarr = ((vader_array_t*) l16);
                                                VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l723)
                                                l724 = ((int64_t*) _a67_slotarr->buf->slots)[vader_array_offset(_a67_slotarr) + (size_t) l723];
                                                VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l722)
                                                ((int64_t*) _a67_slotarr->buf->slots)[vader_array_offset(_a67_slotarr) + (size_t) l722] = (int64_t) l724;
                                                l725 = vader_chk_sub(i64, l722, INT64_C(1));
                                                vader_array_t* _a68_slotarr = ((vader_array_t*) l17);
                                                VADER_ARRAY_RESOLVE_BUF(_a68_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l725)
                                                t3 = vader_array_read_u8(_a68_slotarr, vader_array_offset(_a68_slotarr) + (size_t) l725, 628u);
                                                l726 = ((uint8_t) t3.payload.i);
                                                VADER_ARRAY_CHECK_INDEX(_a68_slotarr, l722)
                                                ((uint8_t*) _a68_slotarr->buf->slots)[vader_array_offset(_a68_slotarr) + (size_t) l722] = (uint8_t) (int32_t) (uint8_t) l726;
                                                l727 = vader_chk_sub(i64, l722, INT64_C(1));
                                                vader_array_t* _a69_slotarr = ((vader_array_t*) l18);
                                                VADER_ARRAY_RESOLVE_BUF(_a69_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l727)
                                                l728 = vader_array_box_slots(_a69_slotarr->buf)[vader_array_offset(_a69_slotarr) + (size_t) l727];
                                                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l722)
                                                vader_array_box_slots(_a69_slotarr->buf)[vader_array_offset(_a69_slotarr) + (size_t) l722] = l728;
                                                VADER_WRITE_BARRIER(_a69_slotarr->buf);
                                                l722 = vader_chk_sub(i64, l722, INT64_C(1));
                                            }
                                            vader_array_t* _a70_slotarr = ((vader_array_t*) l18);
                                            VADER_ARRAY_RESOLVE_BUF(_a70_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a70_slotarr, l686)
                                            vader_array_box_slots(_a70_slotarr->buf)[vader_array_offset(_a70_slotarr) + (size_t) l686] = l714;
                                            VADER_WRITE_BARRIER(_a70_slotarr->buf);
                                            vader_array_t* _a71_slotarr = ((vader_array_t*) l17);
                                            VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l686)
                                            ((uint8_t*) _a71_slotarr->buf->slots)[vader_array_offset(_a71_slotarr) + (size_t) l686] = (uint8_t) INT32_C(6);
                                        }
                                        l687 = l717;
                                    } else {
                                        l729 = vader_vm$resolve_virtual(l0, l2, l8, l13, l686);
                                        l730 = l729;
                                        if (l729.tag == 2128u) {
                                            t1 = l730.payload.obj;
                                            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                        }
                                        l687 = ((int32_t) l729.payload.i);
                                    }
                                }
                                vader_array_t* _a72_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
                                VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l687)
                                l731 = vader_array_ref_load_obj(_a72_slotarr->buf, vader_array_offset(_a72_slotarr) + (size_t) l687);
                                l10 = vader_chk_add(i64, l10, INT64_C(1));
                                l732 = ((int64_t) 1024);
                                if ((l11 >= l732)) {
                                    t0 = ((vader_struct_vader_vm$RegFunction_t*) l731)->f_name;
                                    t1 = vader_vm$overflow_trap(t0);
                                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                                l733 = vader_array_length(((vader_array_t*) l16));
                                l734 = ((vader_struct_vader_vm$RegFunction_t*) l731)->f_registers;
                                l735 = vader_chk_add(i64, l686, l734);
                                if ((l733 < l735)) {
                                    l736 = ((vader_struct_vader_vm$RegFunction_t*) l731)->f_registers;
                                    l737 = vader_chk_add(i64, l686, l736);
                                    vader_vm$reserve_registers(l2, l737);
                                }
                                l738 = ((vader_struct_vader_vm$RegFunction_t*) l731)->f_params;
                                l739 = vader_chk_add(i64, l686, l738);
                                l740 = ((vader_struct_vader_vm$RegFunction_t*) l731)->f_slots;
                                l741 = vader_chk_add(i64, l686, l740);
                                while ((l739 < l741)) {
                                    vader_array_t* _a73_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l739)
                                    ((uint8_t*) _a73_slotarr->buf->slots)[vader_array_offset(_a73_slotarr) + (size_t) l739] = (uint8_t) INT32_C(5);
                                    l739 = (l739 + INT64_C(1));
                                }
                                l742 = ((vader_struct_vader_vm$RegFunction_t*) l731)->f_slots;
                                l743 = vader_chk_add(i64, l686, l742);
                                l744 = INT64_C(0);
                                l745 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l731)->f_consts));
                                while ((l744 < l745)) {
                                    l746 = vader_chk_add(i64, l743, l744);
                                    vader_array_t* _a74_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l731)->f_consts);
                                    VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l744)
                                    l747 = ((int64_t*) _a74_slotarr->buf->slots)[vader_array_offset(_a74_slotarr) + (size_t) l744];
                                    vader_array_t* _a75_slotarr = ((vader_array_t*) l16);
                                    VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a75_slotarr, l746)
                                    ((int64_t*) _a75_slotarr->buf->slots)[vader_array_offset(_a75_slotarr) + (size_t) l746] = (int64_t) l747;
                                    l748 = vader_chk_add(i64, l743, l744);
                                    vader_array_t* _a76_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l731)->f_const_tags);
                                    VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l744)
                                    t3 = vader_array_read_u8(_a76_slotarr, vader_array_offset(_a76_slotarr) + (size_t) l744, 628u);
                                    l749 = ((uint8_t) t3.payload.i);
                                    vader_array_t* _a77_slotarr = ((vader_array_t*) l17);
                                    VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a77_slotarr, l748)
                                    ((uint8_t*) _a77_slotarr->buf->slots)[vader_array_offset(_a77_slotarr) + (size_t) l748] = (uint8_t) (int32_t) (uint8_t) l749;
                                    l744 = (l744 + INT64_C(1));
                                }
                                l750 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code));
                                if ((l11 < l750)) {
                                    vader_array_t* _a78_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code);
                                    VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a78_slotarr, l11)
                                    vader_array_ref_store(_a78_slotarr->buf, vader_array_offset(_a78_slotarr) + (size_t) l11, l731);
                                    VADER_WRITE_BARRIER(_a78_slotarr->buf);
                                    vader_array_t* _a79_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base);
                                    VADER_ARRAY_RESOLVE_BUF(_a79_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a79_slotarr, l11)
                                    ((int64_t*) _a79_slotarr->buf->slots)[vader_array_offset(_a79_slotarr) + (size_t) l11] = (int64_t) l686;
                                    l751 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return;
                                    l752 = vader_chk_add(i64, l13, INT64_C(1));
                                    vader_array_t* _a80_slotarr = ((vader_array_t*) l751);
                                    VADER_ARRAY_RESOLVE_BUF(_a80_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a80_slotarr, l11)
                                    ((int64_t*) _a80_slotarr->buf->slots)[vader_array_offset(_a80_slotarr) + (size_t) l11] = (int64_t) l752;
                                } else {
                                    l753 = vader_chk_add(i64, l13, INT64_C(1));
                                    vader_vm$grow_frame_records(l2, l731, l686, l753);
                                }
                                l11 = vader_chk_add(i64, l11, INT64_C(1));
                                l12 = l686;
                                l8 = l731;
                                l14 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_ops;
                                l15 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_words;
                                l13 = INT64_C(0);
                                continue;
                            }
                            if (l19 == INT32_C(107)) {
                                l754 = true;
                            } else {
                                l754 = l19 == INT32_C(108);
                            }
                            if (!(l754)) {
                                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                            }
                            l755 = l19 == INT32_C(108);
                            l756 = vader_vm$operand_a(l20);
                            if (l755) {
                                l757 = INT64_C(0);
                                t2 = vader_vm$operand_b(l20);
                                l758 = ((int64_t) (int32_t) t2);
                                while ((l757 < l758)) {
                                    l759 = vader_chk_add(i64, l12, l757);
                                    l760 = ((int64_t) (int32_t) l756);
                                    t6 = vader_chk_add(i64, l12, l760);
                                    l761 = vader_chk_add(i64, t6, l757);
                                    vader_vm$move_register(l2, l759, l761);
                                    l757 = (l757 + INT64_C(1));
                                }
                            } else if ((l756 >= INT32_C(0))) {
                                l762 = ((int64_t) (int32_t) l756);
                                l763 = vader_chk_add(i64, l12, l762);
                                vader_vm$move_register(l2, l12, l763);
                            }
                            l11 = vader_chk_sub(i64, l11, INT64_C(1));
                            if (l11 == l5) {
                                if (l755) {
                                    if (l5 == INT64_C(0)) {
                                        vader_struct_vader_vm$Trap_t* _a81_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
                                        vader_obj_header_init(_a81_obj, 2128u);
                                        _a81_obj->f_message = 3142u;
                                        t1 = (void*) _a81_obj;
                                        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                                    }
                                    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                                { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
                            }
                            vader_array_t* _a82_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_return);
                            VADER_ARRAY_RESOLVE_BUF(_a82_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a82_slotarr, l11)
                            l13 = ((int64_t*) _a82_slotarr->buf->slots)[vader_array_offset(_a82_slotarr) + (size_t) l11];
                            l764 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_base;
                            l765 = vader_chk_sub(i64, l11, INT64_C(1));
                            vader_array_t* _a83_slotarr = ((vader_array_t*) l764);
                            VADER_ARRAY_RESOLVE_BUF(_a83_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a83_slotarr, l765)
                            l12 = ((int64_t*) _a83_slotarr->buf->slots)[vader_array_offset(_a83_slotarr) + (size_t) l765];
                            l766 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_frame_code;
                            l767 = vader_chk_sub(i64, l11, INT64_C(1));
                            vader_array_t* _a84_slotarr = ((vader_array_t*) l766);
                            VADER_ARRAY_RESOLVE_BUF(_a84_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a84_slotarr, l767)
                            l8 = vader_array_ref_load_obj(_a84_slotarr->buf, vader_array_offset(_a84_slotarr) + (size_t) l767);
                            l14 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_ops;
                            l15 = ((vader_struct_vader_vm$RegFunction_t*) l8)->f_words;
                            continue;
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

static vader_box_t vader_vm$reg_run(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, bool l5, vader_box_t l6, vader_box_t l7) {
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    int32_t l10;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    int64_t l14, l15;
    bool l16;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[6] = { &l4, &l6, &l7, &l11, &l12, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l8, &l9, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l8 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    l10 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
    l11 = vader_vm$entry_args(l8, l3, l7, l10);
    l12 = l11;
    if (l11.tag == 2128u) {
        t0 = l12.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l11.payload.obj;
    t1 = vader_vm$debug_session(l6, INT32_C(1));
    l13 = vader_vm$empty_machine(t1);
    vader_vm$note_entry_thread(l13);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegModule_t*) l1)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
    l14 = ((vader_struct_vader_vm$RegFunction_t*) t0)->f_registers;
    vader_vm$reserve_registers(l13, l14);
    l14 = INT64_C(0);
    l15 = vader_array_length(((vader_array_t*) l9));
    while ((l14 < l15)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l11 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l14];
        vader_vm$set_register(l13, l14, l11);
        l14 = (l14 + INT64_C(1));
    }
    l11 = vader_vm$reg_call(l0, l1, l13, l2, INT64_C(0), INT64_C(0), INT64_C(0), l5);
    l12 = l11;
    if (!(l11.tag == 2128u)) {
        t2 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l8)->f_signature);
        l16 = t2 == INT64_C(1);
        t1 = vader_vm$finish_run(l13, l16, l4);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l12.payload.obj;
    t3 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
    t4 = vader_vm$is_overflow_trap_message(t3);
    if (!(t4)) {
        vader_vm$unwind(l0, l1, l13, l5);
        t0 = l12.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_vm$frame_names(l13);
    vader_vm$unwind(l0, l1, l13, l5);
    t0 = l12.payload.obj;
    vader_struct_vader_vm$StackOverflow_t* _a3_obj = (vader_struct_vader_vm$StackOverflow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StackOverflow_t));
    vader_obj_header_init(_a3_obj, 2123u);
    _a3_obj->f_trap = t0;
    _a3_obj->f_frames = l8;
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l3 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        return l3;
    }
    if (l2 == INT32_C(0)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l1];
        l3 = vader_box_i32(626u, ((int32_t) (int64_t) t1));
    } else if (l2 == INT32_C(1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l1];
        l3 = vader_box_i64(627u, t1);
    } else if (l2 == INT32_C(2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        t1 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l1];
        l3 = vader_box_f64(633u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(t1) }).__vd));
    } else if (l2 == INT32_C(3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        t1 = ((int64_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l1];
        l3 = vader_box_bool(621u, t1 != INT64_C(0));
    } else if (l2 == INT32_C(4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
        t1 = ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l1];
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
        l3 = vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l4));
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
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits));
        if ((t0 < l1)) {
            vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits, INT64_C(0));
            vader_array_push_u8((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags, INT32_C(5));
            l2 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
            t1 = (void*) &vader_data_103;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
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
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload));
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

static vader_box_t vader_vm$resolve_virtual(void* l0, void* l1, void* l2, int64_t l3, int64_t l4) {
    int64_t l5, l6, l14, l15, l18, l20;
    void* l7 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    int32_t l8, l9, l11;
    vader_box_t l10 = vader_box_null();
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l7, &l16, &l19, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l12, &l13, &l17, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
    t0 = vader_vm$operand_a(l5);
    l6 = ((int64_t) (int32_t) t0);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_virtuals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_virtual_rows);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l8 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l9 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l3];
    t0 = vader_vm$operand_c(l5);
    l5 = ((int64_t) (int32_t) t0);
    t1 = vader_chk_add(i64, l4, l5);
    l6 = vader_chk_sub(i64, t1, INT64_C(1));
    l10 = vader_vm$register_value(l1, l6);
    l11 = vader_vm$receiver_type_id_of(l0, l10);
    if ((l11 < INT32_C(0))) {
        l13 = vader_vm$describe_value_tag(l10);
        l12 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l7)->f_vtable_key;
        l14 = vader_host_std_core$Intrinsic$byte_len(l12);
        l15 = vader_host_std_core$Intrinsic$byte_len(l13);
        l14 = (l14 + l15);
        l16 = (void*) vader_buffer_new((size_t) (INT64_C(73) + l14));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l16, l14, 3698u);
        l14 = std_core$write_string_at(l16, l14, l12);
        l14 = std_core$write_string_at(l16, l14, 368u);
        l14 = std_core$write_string_at(l16, l14, l13);
        l14 = std_core$write_string_at(l16, l14, 177u);
        l15 = ((int64_t) (int32_t) l9);
        l14 = std_core$write_int(l16, l14, l15);
        t2 = std_core$finish_buffer(l16, l14);
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 2128u);
        _a4_obj->f_message = t2;
        t3 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_vm$lookup_vtable_row(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_vtables, l8, l11);
    while ((l6 > l4)) {
        l14 = vader_chk_sub(i64, l6, INT64_C(1));
        vader_vm$move_register(l1, l6, l14);
        l6 = vader_chk_sub(i64, l6, INT64_C(1));
    }
    vader_vm$set_register(l1, l4, l10);
    if (!((l8 >= INT32_C(0)))) {
        l17 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l7)->f_vtable_key;
        l18 = vader_host_std_core$Intrinsic$byte_len(l17);
        l19 = (void*) vader_buffer_new((size_t) (INT64_C(82) + l18));
        l18 = INT64_C(0);
        l18 = std_core$write_string_at(l19, l18, 3698u);
        l18 = std_core$write_string_at(l19, l18, l17);
        l18 = std_core$write_string_at(l19, l18, 367u);
        l20 = ((int64_t) (int32_t) l11);
        l18 = std_core$write_int(l19, l18, l20);
        l18 = std_core$write_string_at(l19, l18, 130u);
        l20 = ((int64_t) (int32_t) l9);
        l18 = std_core$write_int(l19, l18, l20);
        t2 = std_core$finish_buffer(l19, l18);
        vader_struct_vader_vm$Trap_t* _a5_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a5_obj, 2128u);
        _a5_obj->f_message = t2;
        t3 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l16 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    t4 = vader_vm$is_fn_index_out_of_range(l8, l16);
    if (t4) {
        l12 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l7)->f_vtable_key;
        l12 = concat_3(3698u, l12, 362u);
        t3 = vader_vm$fn_index_trap(l8, l9, l12);
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
    l16 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l8);
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params));
    if (!(t1 != l5)) {
        { vader_box_t __vret = vader_box_i32(626u, l8); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_signature)->f_params));
    l12 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l7)->f_vtable_key;
    l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_name;
    l14 = vader_host_std_core$Intrinsic$byte_len(l12);
    l15 = vader_host_std_core$Intrinsic$byte_len(l13);
    l14 = (l14 + l15);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(134) + l14));
    l14 = INT64_C(0);
    l14 = std_core$write_string_at(l7, l14, 3698u);
    l14 = std_core$write_string_at(l7, l14, l12);
    l14 = std_core$write_string_at(l7, l14, 366u);
    l14 = std_core$write_string_at(l7, l14, l13);
    l14 = std_core$write_string_at(l7, l14, 371u);
    l14 = std_core$write_int(l7, l14, l6);
    l14 = std_core$write_string_at(l7, l14, 250u);
    l14 = std_core$write_int(l7, l14, l5);
    l14 = std_core$write_string_at(l7, l14, 130u);
    l5 = ((int64_t) (int32_t) l9);
    l14 = std_core$write_int(l7, l14, l5);
    t2 = std_core$finish_buffer(l7, l14);
    vader_struct_vader_vm$Trap_t* _a7_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
    vader_obj_header_init(_a7_obj, 2128u);
    _a7_obj->f_message = t2;
    t3 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$restore(void* l0) {
    int64_t l1, l2;
    vader_box_t l3;
    int32_t l4;
    void* t0;
    l1 = INT64_C(0);
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_sources));
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_sources);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$CopyWalk_t*) l0)->f_kept_ids);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l4 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        if (l3.tag == 2125u) {
            t0 = l3.payload.obj;
            ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id = l4;
        } else if (l3.tag == 2093u) {
            t0 = l3.payload.obj;
            ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id = l4;
        } else if (l3.tag == 2109u) {
            t0 = l3.payload.obj;
            ((vader_struct_vader_vm$ObjVal_t*) t0)->f_type_id = l4;
        } else if (!(l3.tag == 2098u)) {
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
    l3 = vader_array_length(((vader_array_t*) l2));
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
    l4 = vader_chk_sub(i64, t0, l3);
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l5, 628u);
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

static vader_box_t vader_vm$retyped_int(vader_box_t l0, int64_t l1) {
    uint32_t l2;
    bool l3;
    int32_t t0;
    if (l0.tag == 627u) {
        return vader_box_i64(627u, l1);
    }
    if (l0.tag == 621u) {
        return vader_box_bool(621u, l1 != INT64_C(0));
    }
    if (!(l0.tag == 622u)) {
        return vader_box_i32(626u, ((int32_t) (int64_t) l1));
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
            return vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l2));
        }
    } else {
        return vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l2));
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
    vader_box_t l24 = vader_box_null(), l26 = vader_box_null();
    vader_string_t l25 = 0;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l24, &l26, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l11, &l13, &l14, &l17, &l18, &l21, &l22, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l25 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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
        l16 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l15];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
        ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l12] = (int64_t) l16;
        l17 = ((vader_struct_vader_vm$Frame_t*) l11)->f_tag;
        l18 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_tags;
        l19 = vader_chk_add(i64, l7, l12);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l19)
        t1 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l19, 628u);
        l20 = ((uint8_t) t1.payload.i);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
        ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l12] = (uint8_t) (int32_t) (uint8_t) l20;
        l21 = ((vader_struct_vader_vm$Frame_t*) l11)->f_stack;
        l22 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_refs;
        l23 = vader_chk_add(i64, l7, l12);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l22);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l23)
        l24 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l23];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l21);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
        vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l12] = l24;
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        l12 = (l12 + INT64_C(1));
    }
    ((vader_struct_vader_vm$Frame_t*) l11)->f_sp = l9;
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l2)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
    l8 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l3];
    ((vader_struct_vader_vm$Frame_t*) l11)->f_pc = l8;
    l13 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run;
    l14 = ((vader_struct_vader_vm$RegFunction_t*) l2)->f_boxed;
    l8 = vader_vm$operand_a(l6);
    vader_array_t* _a8_slotarr = ((vader_array_t*) l14);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
    l24 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l8);
    l25 = ((vader_struct_vader_vm$RegFunction_t*) l2)->f_name;
    l24 = vader_vm$apply_boxed(l0, l13, l24, l11, l25, l5);
    l26 = l24;
    if (l24.tag == 2128u) {
        t2 = l26.payload.obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = INT64_C(0);
    while ((l6 < l10)) {
        l13 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_bits;
        l9 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l11)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        l12 = ((int64_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l6];
        vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
        ((int64_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l9] = (int64_t) l12;
        l14 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_tags;
        l15 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l11)->f_tag);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
        t1 = vader_array_read_u8(_a11_slotarr, vader_array_offset(_a11_slotarr) + (size_t) l6, 628u);
        l20 = ((uint8_t) t1.payload.i);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l15)
        ((uint8_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l15] = (uint8_t) (int32_t) (uint8_t) l20;
        l17 = ((vader_struct_vader_vm$RegMachine_t*) l1)->f_refs;
        l16 = vader_chk_add(i64, l7, l6);
        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l11)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        l24 = vader_array_box_slots(_a13_slotarr->buf)[vader_array_offset(_a13_slotarr) + (size_t) l6];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l16)
        vader_array_box_slots(_a14_slotarr->buf)[vader_array_offset(_a14_slotarr) + (size_t) l16] = l24;
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$run_defers(void* l0, void* l1, void* l2, void* l3, int64_t l4, int64_t l5, int64_t l6, bool l7) {
    int32_t l8, l9;
    int64_t l10, l11, l13;
    void* l12 = NULL;
    void* l14 = NULL;
    vader_box_t l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null();
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l15, &l16, &l17 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l12, &l14, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l3)->f_words);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
    l8 = vader_vm$operand_a(t0);
    if ((l8 <= INT32_C(0))) {
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l3)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l9 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
    l10 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    l11 = ((int64_t) (int32_t) l8);
    if ((l10 < l11)) {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(107));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, 2334u);
        l11 = ((int64_t) (int32_t) l8);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 462u);
        l11 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 406u);
        l11 = ((int64_t) (int32_t) l9);
        l10 = std_core$write_int(l12, l10, l11);
        t1 = std_core$finish_buffer(l12, l10);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 2128u);
        _a2_obj->f_message = t1;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    l11 = ((int64_t) (int32_t) l8);
    l10 = vader_chk_sub(i64, l10, l11);
    vader_array_t* _a3_arr = vader_array_new(446u, 0u, 13u, 2098u);
    l12 = (void*) _a3_arr;
    l11 = l10;
    l13 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
    while ((l11 < l13)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l15 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l11];
        l16 = vader_vm$defer_thunk(l0, l15, l9, 2332u);
        l17 = l16;
        if (l16.tag == 2128u) {
            t2 = l17.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l14 = l16.payload.obj;
        vader_array_push_ref((vader_array_t*) l12, l14);
        l11 = (l11 + INT64_C(1));
    }
    ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count = l10;
    l10 = vader_array_length(((vader_array_t*) l12));
    for (;;) {
        if ((l10 > INT64_C(0))) {
            l10 = vader_chk_sub(i64, l10, INT64_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
            l14 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l10);
            l11 = vader_chk_add(i64, l4, INT64_C(1));
            l15 = vader_vm$run_thunk(l0, l1, l2, l14, l5, l6, l11, l7);
            l16 = l15;
            if (!(l15.tag == 2128u)) {
                continue;
            }
            t2 = l16.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$run_entry(void* l0, int32_t l1, void* l2, vader_box_t l3, bool l4, vader_box_t l5, vader_box_t l6) {
    bool l7;
    int64_t l8, l9;
    void* l10 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[4] = { &l3, &l5, &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l2, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l7 = true;
    } else {
        l8 = ((int64_t) (int32_t) l1);
        l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions));
        l7 = (l8 >= l9);
    }
    if (l7) {
        l10 = (void*) vader_buffer_new((size_t) INT64_C(46));
        l8 = INT64_C(0);
        l8 = std_core$write_string_at(l10, l8, 2975u);
        l9 = ((int64_t) (int32_t) l1);
        l8 = std_core$write_int(l10, l8, l9);
        l8 = std_core$write_string_at(l10, l8, 398u);
        t0 = std_core$finish_buffer(l10, l8);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 0u) {
        l10 = ((vader_struct_vader_vm$VmState_t*) l0)->f_reg;
        t2 = vader_vm$reg_run(l0, l10, l1, l2, l3, l4, l5, l6);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_struct_vader_vm$VmState_t*) l0)->f_debuggable;
    if (!(t3)) {
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = 1828u;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_vm$VmState_t*) l0)->f_reg;
    t2 = vader_vm$reg_run(l0, l10, l1, l2, l3, l4, l5, l6);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$run_for_value(void* l0, vader_string_t l1, bool l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t1 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_vm$entry_named(l0, l1);
    l5 = l4;
    if (l4.tag == 2128u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int32_t) l4.payload.i);
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l6 = (void*) _a0_arr;
    t1 = vader_vm$zero_value();
    vader_array_t* _a1_arr = vader_array_new(503u, 1u, 0u, 3020u);
    vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 0u] = t1;
    l7 = (void*) _a1_arr;
    t1 = vader_vm$run_entry(l0, l3, l6, vader_ref_box(l7), l2, vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    l4 = vader_vm$after_entry(t1, 3324u);
    if (!((l4.tag == 2123u || l4.tag == 2128u))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)];
        vader_struct_vader_vm$ValueOk_t* _a3_obj = (vader_struct_vader_vm$ValueOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ValueOk_t));
        vader_obj_header_init(_a3_obj, 2130u);
        _a3_obj->f_value = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$run_guest_thread(void* l0, void* l1, bool l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    int64_t l5;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    int32_t l9;
    int32_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_global_33;
    if (t0 == INT32_C(2)) {
        l4 = vader_global_34;
    } else {
        l4 = vader_vm$guest_threads();
    }
    l5 = vader_host_std_core$Intrinsic$current_thread();
    l6 = vader_vm$empty_machine(l3);
    l7 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_vm$GuestThreads_t*) l4)->f_live, l5);
    if (!(l7.tag == 0u)) {
        t1 = l7.payload.obj;
        ((vader_struct_vader_vm$GuestThread_t*) t1)->f_machine = vader_ref_box(l6);
        VADER_WRITE_BARRIER((vader_struct_vader_vm$GuestThread_t*) t1);
    }
    vader_struct___defer_env_vader_vm_23_t* _a0_obj = (vader_struct___defer_env_vader_vm_23_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_vader_vm_23_t));
    vader_obj_header_init(_a0_obj, 665u);
    _a0_obj->f_cap_0 = l4;
    _a0_obj->f_cap_1 = l5;
    t1 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 526u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_vader_vm_22;
    _a1_closure->env = t1;
    t1 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t1));
    vader_struct___defer_env_vader_vm_25_t* _a2_obj = (vader_struct___defer_env_vader_vm_25_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_vader_vm_25_t));
    vader_obj_header_init(_a2_obj, 666u);
    _a2_obj->f_cap_0 = l0;
    _a2_obj->f_cap_1 = l6;
    _a2_obj->f_cap_2 = l2;
    t1 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 526u);
    _a3_closure->code = (void*) &vader_fn_lift___defer_vader_vm_24;
    _a3_closure->env = t1;
    t1 = (void*) _a3_closure;
    vader_defer_push(vader_ref_box(t1));
    l4 = ((vader_struct_vader_vm$VmState_t*) l0)->f_reg;
    l7 = vader_vm$run_thunk(l0, l4, l6, l1, INT64_C(0), INT64_C(0), INT64_C(0), l2);
    if (!(l7.tag == 2128u)) {
        vader_defer_pop_exec(2u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l3.tag == 0u)) {
        t1 = l3.payload.obj;
        l4 = ((vader_struct_vader_vm$DebugController_t*) ((vader_struct_vader_vm$DebugSession_t*) t1)->f_controller)->f_on_fatal_trap;
        t1 = l7.payload.obj;
        l8 = ((vader_struct_vader_vm$Trap_t*) t1)->f_message;
        t1 = l3.payload.obj;
        l9 = ((vader_struct_vader_vm$DebugSession_t*) t1)->f_thread_id;
        l6 = vader_vm$debugged_threads(l0);
        t1 = vader_vm$exception_stop(l8, l9, l6);
        vader_fn_t* _a4_fnobj = (vader_fn_t*) l4;
        ((vader_fn_erased_sig_1_t) _a4_fnobj->code)(_a4_fnobj->env, vader_ref_box(t1));
    }
    t1 = l7.payload.obj;
    l8 = ((vader_struct_vader_vm$Trap_t*) t1)->f_message;
    t2 = concat_2(1867u, l8);
    vader_host_std_core$Intrinsic$panic(t2);
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
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4] = (uint8_t) INT32_C(5);
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
    if (l0.tag == 1345u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a0_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a0_obj, 2122u);
        _a0_obj->f_bits = ((int64_t) (int32_t) t1);
        _a0_obj->f_tag = (uint8_t) 0;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1365u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a1_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a1_obj, 2122u);
        _a1_obj->f_bits = t2;
        _a1_obj->f_tag = (uint8_t) 1;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1324u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a2_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a2_obj, 2122u);
        _a2_obj->f_bits = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t3 }).__vu));
        _a2_obj->f_tag = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1296u) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        if (t4) {
            l2 = INT64_C(1);
        } else {
            l2 = INT64_C(0);
        }
        vader_struct_vader_vm$Scalar_t* _a3_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a3_obj, 2122u);
        _a3_obj->f_bits = l2;
        _a3_obj->f_tag = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1311u) {
        t0 = l0.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        vader_struct_vader_vm$Scalar_t* _a4_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a4_obj, 2122u);
        _a4_obj->f_bits = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        _a4_obj->f_tag = (uint8_t) 4;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1397u) {
        vader_struct_vader_vm$Scalar_t* _a5_obj = (vader_struct_vader_vm$Scalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Scalar_t));
        vader_obj_header_init(_a5_obj, 2122u);
        _a5_obj->f_bits = INT64_C(0);
        _a5_obj->f_tag = (uint8_t) 5;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1414u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$scalar_value(uint8_t l0, int64_t l1) {
    vader_box_t l2;
    uint32_t l3;
    bool l4;
    int32_t t0;
    if (l0 == INT32_C(10)) {
        l2 = vader_box_bool(621u, l1 != INT64_C(0));
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
        l2 = vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l3));
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
            l2 = vader_box_i32(626u, ((int32_t) (int64_t) l1));
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
                l2 = vader_box_i64(627u, l1);
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
                l2 = vader_box_i64(627u, l1);
            }
        }
    }
    return l2;
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
    l1 = std_core$filled__vader_vm_ArrayVal___bool___char___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal___vader_vm_VoidVal(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int64_t) INT64_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(31u, 1u, 1u, 628u);
    ((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) INT32_C(5);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l3 = (void*) _a3_arr;
    vader_struct_vader_vm$Frame_t* _a4_obj = (vader_struct_vader_vm$Frame_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Frame_t));
    vader_obj_header_init(_a4_obj, 2100u);
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
    vader_string_t l39 = 0;
    vader_string_t l40 = 0;
    int64_t l9, l11, l15, l16, l17, l19, l20, l21, l22, l28, l31, l32, l41, l42, l43;
    void* l10 = NULL;
    void* l18 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l26 = vader_box_null(), l27 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null(), l34 = vader_box_null(), l38 = vader_box_null();
    int32_t l25;
    double l33;
    bool l35, l36, l37;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[8] = { &l12, &l13, &l26, &l27, &l29, &l30, &l34, &l38 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l4, &l10, &l18, &l23, &l24, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l6, &l8, &l14, &l39, &l40, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        l8 = l6;
        l9 = vader_host_std_core$Intrinsic$byte_len(l8);
        l10 = (void*) vader_buffer_new((size_t) (INT64_C(83) + l9));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l10, l9, 2478u);
        l9 = std_core$write_string_at(l10, l9, l8);
        l9 = std_core$write_string_at(l10, l9, 1349u);
        l11 = ((int64_t) (int32_t) l5);
        l9 = std_core$write_int(l10, l9, l11);
        l9 = std_core$write_string_at(l10, l9, 597u);
        l9 = std_core$write_int(l10, l9, INT64_C(16));
        t0 = std_core$finish_buffer(l10, l9);
        vader_struct_vader_vm$Trap_t* _a0_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a0_obj, 2128u);
        _a0_obj->f_message = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_core_bytecode$c_struct_layout(l3, l4);
    l9 = INT64_C(0);
    l11 = vader_array_length(((vader_array_t*) l3));
    while ((l9 < l11)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
        l12 = vader_core_bytecode$nested_mirror(t1, l4);
        if (l12.tag == 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
            l29 = vader_core_bytecode$c_field_width(t1, l4);
            if (l29.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l28 = ((int64_t) l29.payload.i);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l30 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l9];
            if ((l30.tag == 632u || l30.tag == 633u)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_offsets);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                l31 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l9];
                l32 = vader_chk_add(i64, l1, l31);
                l33 = ((double) l30.payload.f);
                vader_vm$write_float(l0, l32, l33, l28);
                l9 = (l9 + INT64_C(1));
                continue;
            }
            if (l30.tag == 627u) {
                l35 = true;
            } else {
                l35 = l30.tag == 626u;
            }
            if (l35) {
                l36 = true;
            } else {
                l36 = l30.tag == 621u;
            }
            if (l36) {
                l37 = true;
            } else {
                l37 = l30.tag == 622u;
            }
            if (l37) {
                l34 = vader_vm$read_scalar_word(l30, l5, 0u);
            } else {
                l38 = l30;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t1 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l9);
                l39 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
                l40 = concat_5(2478u, l6, 1378u, l39, 1310u);
                l34 = vader_vm$read_scalar_word(l38, l5, l40);
            }
            if (l34.tag == 2128u) {
                t1 = l34.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_offsets);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
            l41 = ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l9];
            l42 = vader_chk_add(i64, l1, l41);
            l43 = ((int64_t) l34.payload.i);
            vader_vm$write_little_endian(l0, l42, l43, l28);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l2)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
        l13 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l9];
        if (!(l13.tag == 2125u)) {
            l8 = l6;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l9);
            l14 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_name;
            l15 = vader_host_std_core$Intrinsic$byte_len(l8);
            l16 = vader_host_std_core$Intrinsic$byte_len(l14);
            l17 = (l15 + l16);
            l18 = (void*) vader_buffer_new((size_t) (INT64_C(91) + l17));
            l19 = INT64_C(0);
            l19 = std_core$write_string_at(l18, l19, 2478u);
            l19 = std_core$write_string_at(l18, l19, l8);
            l19 = std_core$write_string_at(l18, l19, 1349u);
            l20 = ((int64_t) (int32_t) l5);
            l19 = std_core$write_int(l18, l19, l20);
            l19 = std_core$write_string_at(l18, l19, 593u);
            l19 = std_core$write_string_at(l18, l19, l14);
            l19 = std_core$write_string_at(l18, l19, 1529u);
            t0 = std_core$finish_buffer(l18, l19);
            vader_struct_vader_vm$Trap_t* _a9_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
            vader_obj_header_init(_a9_obj, 2128u);
            _a9_obj->f_message = t0;
            t1 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l10)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
        l21 = ((int64_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l9];
        l22 = vader_chk_add(i64, l1, l21);
        l23 = l13.payload.obj;
        t1 = l12.payload.obj;
        l24 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
        l25 = vader_chk_add(i32, l7, INT32_C(1));
        l26 = vader_vm$serialise_mirror(l0, l22, l23, l24, l4, l5, l6, l25);
        l27 = l26;
        if (l26.tag == 2128u) {
            t1 = l27.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_import(void* l0, void* l1, int32_t l2, void* l3, void* l4, int32_t l5, bool l6) {
    uint8_t l7;
    void* l8 = NULL;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_is_extern;
    if (t0) {
        t1 = vader_vm$dispatch_extern(l0, l2, l4, INT64_C(0), l5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_import_ids);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l2, 628u);
    l7 = ((uint8_t) t1.payload.i);
    if (l7 == INT32_C(13)) {
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l9 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0)];
        t1 = vader_vm$deep_copy_value(l8, l9, l5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_vm$serve_thread_primitive(l0, l1, l7, l4, l5, l6);
    if (l9.tag == 0u) {
        l8 = ((vader_struct_vader_vm$RunHost_t*) ((vader_struct_vader_vm$RegMachine_t*) l1)->f_run)->f_gc_state;
        l10 = ((vader_struct_vader_vm$VmState_t*) l0)->f_string_array_type_id;
        l11 = ((vader_struct_vader_vm$VmState_t*) l0)->f_u8_array_type_id;
        t1 = vader_vm$dispatch_import(l3, l4, INT64_C(0), l8, l5, l10, l11, l6, l7);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_is_leaving(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[3] = { &l0, &l2, &l3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$read_i64(l0, l1, 2781u);
    l3 = l2;
    if (l2.tag == 2128u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int64_t) l2.payload.i);
    t2 = vader_host_std_core$Intrinsic$is_leaving(t1);
    vader_struct_vader_vm$HostOk_t* _a0_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a0_obj, 2105u);
    _a0_obj->f_value = vader_box_bool(621u, t2);
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_program_stream(void* l0, void* l1, void* l2, int64_t l3, int32_t l4) {
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    bool l8, l9;
    int64_t l10;
    uint8_t l11;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2, t3;
    vader_box_t* gc_roots[3] = { &l6, &l7, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
    if (l5 == 774u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l3];
        l6 = vader_vm$read_i64(t0, l4, 775u);
        l7 = l6;
        if (l6.tag == 2128u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int64_t) l6.payload.i);
        t3 = vader_vm$std_descriptor(t2);
        vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a1_obj, 2105u);
        _a1_obj->f_value = vader_box_i64(627u, t3);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5 == 3740u) {
        l8 = true;
    } else {
        l8 = l5 == 1308u;
    }
    if (l8) {
        l8 = true;
    } else {
        l8 = l5 == 1219u;
    }
    if (l5 == 3096u) {
        l9 = true;
    } else {
        l9 = l5 == 1302u;
    }
    if (l9) {
        l9 = true;
    } else {
        l9 = l5 == 989u;
    }
    if (!(l8)) {
        if (!(l9)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t0 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l3];
    l6 = vader_vm$read_i64(t0, l4, 2337u);
    l7 = l6;
    if (l6.tag == 2128u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((int64_t) l6.payload.i);
    if (l9) {
        if (!(l10 != INT64_C(0))) {
            t0 = vader_vm$serve_read(l1, l2, l3, l4);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = vader_vm$stream_of(l10);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l11 = ((uint8_t) l6.payload.i);
    t0 = vader_vm$serve_write(l0, l11, l1, l2, l3, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_read(void* l0, void* l1, int64_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    int64_t l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    uint8_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l6, &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
    if (t0 != INT32_C(10)) {
        vader_struct_vader_vm$HostOk_t* _a0_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a0_obj, 2105u);
        _a0_obj->f_value = vader_box_i64(627u, INT64_C(0));
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_chk_add(i64, l2, INT64_C(3));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
    l6 = vader_vm$read_array(t2, l3, 990u);
    l7 = l6;
    if (l6.tag == 2128u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l6.payload.obj;
    t3 = vader_vm$element_count(l4);
    if ((t3 > INT64_C(0))) {
        l8 = ((vader_struct_vader_vm$ArrayVal_t*) l4)->f_elements;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l4)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t2 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)];
        l6 = vader_vm$retyped_int(t2, INT64_C(0));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) INT32_C(0)] = l6;
        VADER_WRITE_BARRIER(_a3_slotarr->buf);
    }
    vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a4_obj, 2105u);
    _a4_obj->f_value = vader_box_bool(621u, true);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_thread_primitive(void* l0, void* l1, uint8_t l2, void* l3, int32_t l4, bool l5) {
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    bool l7;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[3] = { &l6, &l8, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(33)) {
        l6 = vader_vm$debug_controller(l1);
        l6 = vader_vm$start_guest_thread(l0, l3, l4, l5, l6);
        { vader_box_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(34)) {
        l7 = true;
    } else {
        l7 = l2 == INT32_C(50);
    }
    if (l7) {
        l6 = vader_vm$parked();
    } else if (l2 == INT32_C(35)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
        l9 = (void*) &vader_fn_static___lambda_vader_vm_19;
        l6 = vader_vm$on_i64(l8, l4, 3714u, l9);
    } else if (l2 == INT32_C(36)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0)];
        l9 = (void*) &vader_fn_static___lambda_vader_vm_18;
        l6 = vader_vm$on_i64(l8, l4, 3188u, l9);
    } else if (l2 == INT32_C(42)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)];
        l9 = (void*) &vader_fn_static___lambda_vader_vm_17;
        l6 = vader_vm$on_i64(l8, l4, 3720u, l9);
    } else if (l2 == INT32_C(43)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) INT32_C(0)];
        l9 = (void*) &vader_fn_static___lambda_vader_vm_16;
        l6 = vader_vm$on_i64(l8, l4, 3719u, l9);
    } else if (l2 == INT32_C(51)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) INT32_C(0)];
        l6 = vader_vm$serve_wait_readable(l0, l8, l4);
    } else if (l2 == INT32_C(52)) {
        l6 = vader_vm$serve_wait_readable_for(l0, l3, l4, false);
    } else if (l2 == INT32_C(53)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) INT32_C(0)];
        l9 = (void*) &vader_fn_static___lambda_vader_vm_15;
        l6 = vader_vm$on_i64(l8, l4, 3712u, l9);
    } else if (l2 == INT32_C(54)) {
        l6 = vader_vm$serve_wait_writable_for(l3, l4, false);
    } else if (l2 == INT32_C(55)) {
        l6 = vader_vm$serve_wait_readable_for(l0, l3, l4, true);
    } else if (l2 == INT32_C(56)) {
        l6 = vader_vm$serve_wait_writable_for(l3, l4, true);
    } else if (l2 == INT32_C(57)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        l8 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) INT32_C(0)];
        l9 = (void*) &vader_fn_static___lambda_vader_vm_14;
        l6 = vader_vm$on_i64(l8, l4, 3220u, l9);
    } else if (l2 == INT32_C(37)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(0))
        t0 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) INT32_C(0)];
        l6 = vader_vm$cancel_guest_thread(t0, l4);
    } else if (l2 == INT32_C(38)) {
        t1 = vader_host_std_core$Intrinsic$current_thread();
        vader_struct_vader_vm$HostOk_t* _a8_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a8_obj, 2105u);
        _a8_obj->f_value = vader_box_i64(627u, t1);
        t2 = (void*) _a8_obj;
        l6 = vader_ref_box(t2);
    } else if (l2 == INT32_C(39)) {
        t3 = vader_host_std_core$Intrinsic$is_cancelled();
        vader_struct_vader_vm$HostOk_t* _a9_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a9_obj, 2105u);
        _a9_obj->f_value = vader_box_bool(621u, t3);
        t2 = (void*) _a9_obj;
        l6 = vader_ref_box(t2);
    } else if (l2 == INT32_C(40)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, INT32_C(0))
        t0 = vader_array_box_slots(_a10_slotarr->buf)[vader_array_offset(_a10_slotarr) + (size_t) INT32_C(0)];
        l6 = vader_vm$serve_is_leaving(t0, l4);
    } else {
        l6 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_wait_readable(void* l0, vader_box_t l1, int32_t l2) {
    int64_t l3, l6;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l4, &l5, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_vm$read_i64(l1, l2, 3710u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) l4.payload.i);
    l6 = l3;
    t1 = vader_vm$serves_stdin(l0, l6);
    if (t1) {
        t2 = vader_vm$void_result();
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_host_std_core$Intrinsic$wait_readable(l3);
    t2 = vader_vm$void_result();
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_wait_readable_for(void* l0, void* l1, int32_t l2, bool l3) {
    int64_t l4, l7, l8, l9;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l5, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
    l5 = vader_vm$read_i64(t0, l2, 3711u);
    l6 = l5;
    if (l5.tag == 2128u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int64_t) l5.payload.i);
    l7 = l4;
    t2 = vader_vm$serves_stdin(l0, l7);
    if (t2) {
        vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a1_obj, 2105u);
        _a1_obj->f_value = vader_box_bool(621u, true);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
    t0 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(1)];
    l5 = vader_vm$read_i64(t0, l2, 3711u);
    l6 = l5;
    if (l5.tag == 2128u) {
        t1 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int64_t) l5.payload.i);
    if (!(l3)) {
        l8 = l4;
        l9 = l7;
        t2 = vader_host_std_core$Intrinsic$wait_readable_for(l8, l9);
        vader_struct_vader_vm$HostOk_t* _a3_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a3_obj, 2105u);
        _a3_obj->f_value = vader_box_bool(621u, t2);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_host_std_core$Intrinsic$wait_blocked_read_for(l4, l7);
    vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a4_obj, 2105u);
    _a4_obj->f_value = vader_box_bool(621u, t2);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_wait_writable_for(void* l0, int32_t l1, bool l2) {
    int64_t l3, l6, l7, l8;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l4, &l5, &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
    l4 = vader_vm$read_i64(t0, l1, 3713u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) l4.payload.i);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
    t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) INT32_C(1)];
    l4 = vader_vm$read_i64(t0, l1, 3713u);
    l5 = l4;
    if (l4.tag == 2128u) {
        t1 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int64_t) l4.payload.i);
    if (!(l2)) {
        l7 = l3;
        l8 = l6;
        t2 = vader_host_std_core$Intrinsic$wait_writable_for(l7, l8);
        vader_struct_vader_vm$HostOk_t* _a2_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a2_obj, 2105u);
        _a2_obj->f_value = vader_box_bool(621u, t2);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_host_std_core$Intrinsic$wait_blocked_write_for(l3, l6);
    vader_struct_vader_vm$HostOk_t* _a3_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a3_obj, 2105u);
    _a3_obj->f_value = vader_box_bool(621u, t2);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$serve_write(void* l0, uint8_t l1, void* l2, void* l3, int64_t l4, int32_t l5) {
    void* l6 = NULL;
    void* l13 = NULL;
    int64_t l7, l10, l12;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    bool l11;
    vader_string_t l14 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    uint8_t t3;
    vader_box_t* gc_roots[3] = { &l8, &l9, &t0 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l6, &l13, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l14, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_chk_add(i64, l4, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l7];
    l8 = vader_vm$read_array(t0, l5, 3749u);
    l9 = l8;
    if (l8.tag == 2128u) {
        t1 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l8.payload.obj;
    l10 = vader_chk_add(i64, l4, INT64_C(2));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l10];
    l8 = vader_vm$read_i64(t0, l5, 3751u);
    l9 = l8;
    if (l8.tag == 2128u) {
        t1 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int64_t) l8.payload.i);
    if ((l7 < INT64_C(0))) {
        l11 = true;
    } else {
        l10 = l7;
        l12 = vader_vm$element_count(l6);
        l11 = (l10 > l12);
    }
    if (l11) {
        l13 = (void*) vader_buffer_new((size_t) INT64_C(79));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l13, l10, 3748u);
        l12 = ((int64_t) (int32_t) l5);
        l10 = std_core$write_int(l13, l10, l12);
        l10 = std_core$write_string_at(l13, l10, 581u);
        l12 = l7;
        l10 = std_core$write_int(l13, l10, l12);
        l10 = std_core$write_string_at(l13, l10, 156u);
        t2 = std_core$finish_buffer(l13, l10);
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 2128u);
        _a2_obj->f_message = t2;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = l7;
    l8 = vader_vm$array_bytes(l6, l10, l5, 3750u);
    l9 = l8;
    if (l8.tag == 2128u) {
        t1 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l8.payload.obj;
    l13 = ((vader_struct_vader_vm$ProgramIo_t*) l0)->f_write;
    l14 = vader_host_std_core$Intrinsic$bytes_to_string(l6);
    vader_fn_t* _a3_fnobj = (vader_fn_t*) l13;
    ((vader_fn_erased_sig_2_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(628u, (int32_t)(uint32_t) l1), vader_box_string(623u, l14));
    t3 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature);
    if (!(t3 == INT32_C(10))) {
        vader_struct_vader_vm$HostOk_t* _a4_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
        vader_obj_header_init(_a4_obj, 2105u);
        _a4_obj->f_value = vader_box_i64(627u, l7);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_vm$HostOk_t* _a5_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a5_obj, 2105u);
    _a5_obj->f_value = vader_box_bool(621u, true);
    t1 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_vm$serves_stdin(void* l0, int64_t l1) {
    if (!(((vader_struct_vader_vm$VmState_t*) l0)->f_io.tag == 0u)) {
        return l1 == INT64_C(0);
    }
    return false;
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
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5] = (uint8_t) INT32_C(3);
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
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5] = (uint8_t) INT32_C(4);
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
    t1 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l8];
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
        vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l12] = l10;
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_vm$element_trap(l0, l1, l2, l3, l5, l6, l7);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$set_f64(void* l0, void* l1, int64_t l2, int32_t l3, double l4) {
    int64_t l5, l6;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
    l6 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l4 }).__vu));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5] = (uint8_t) INT32_C(2);
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
    l9 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l8];
    if (l9.tag == 2125u) {
        if ((l4 < INT32_C(0))) {
            l10 = true;
        } else {
            l8 = ((int64_t) (int32_t) l4);
            t0 = l9.payload.obj;
            l11 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields));
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
            vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l4] = l15;
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) t0)->f_fields));
        l7 = (void*) vader_buffer_new((size_t) INT64_C(118));
        l11 = INT64_C(0);
        l11 = std_core$write_string_at(l7, l11, 3264u);
        l12 = ((int64_t) (int32_t) l4);
        l11 = std_core$write_int(l7, l11, l12);
        l11 = std_core$write_string_at(l7, l11, 246u);
        l11 = std_core$write_int(l7, l11, l8);
        l11 = std_core$write_string_at(l7, l11, 160u);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l5)->f_origin);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
        l8 = ((int64_t) (int32_t) t1);
        l11 = std_core$write_int(l7, l11, l8);
        t2 = std_core$finish_buffer(l7, l11);
        vader_struct_vader_vm$Trap_t* _a3_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a3_obj, 2128u);
        _a3_obj->f_message = t2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l5)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
    l16 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l6];
    l9 = vader_vm$read_struct(l9, l16, 3266u);
    l15 = l9;
    if (!(l9.tag == 2128u)) {
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l15.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$set_i32(void* l0, void* l1, int64_t l2, int32_t l3, int32_t l4) {
    int64_t l5, l6;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
    l6 = ((int64_t) (int32_t) l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5] = (int64_t) l6;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5] = (uint8_t) INT32_C(0);
    return;
}

static void vader_vm$set_i64(void* l0, void* l1, int64_t l2, int32_t l3, int64_t l4) {
    int64_t l5;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l2, l5);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5] = (int64_t) l4;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5] = (uint8_t) INT32_C(1);
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
    if (l2.tag == 626u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        t0 = ((int32_t) l2.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1] = (uint8_t) INT32_C(0);
        return;
    }
    if (l2.tag == 627u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        l4 = ((int64_t) l2.payload.i);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
        ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l1] = (uint8_t) INT32_C(1);
    } else if ((l2.tag == 632u || l2.tag == 633u)) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        t1 = ((double) l2.payload.f);
        l4 = ((int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu));
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
        ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l1] = (uint8_t) INT32_C(2);
    } else if (l2.tag == 621u) {
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
        ((int64_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
        ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l1] = (uint8_t) INT32_C(3);
    } else if (l2.tag == 622u) {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_bits;
        t3 = ((uint32_t) l2.payload.i);
        l4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
        ((int64_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l1] = (int64_t) l4;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
        ((uint8_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l1] = (uint8_t) INT32_C(4);
    } else if (l2.tag == 2108u) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l1)
        ((uint8_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l1] = (uint8_t) INT32_C(5);
    } else {
        l3 = ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs;
        l5 = l2;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l1)
        vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l1] = l5;
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l1)
        ((uint8_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l1] = (uint8_t) INT32_C(6);
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (t0.tag == 1380u) {
        l3 = vader_chk_add(i64, l1, INT64_C(1));
        l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body));
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
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        return t0.tag == 1320u;
    }
    return false;
}

static bool vader_vm$slot_in_scope(void* l0, void* l1, int64_t l2, int32_t l3) {
    int32_t l4;
    int32_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    if ((t0 < INT32_C(0))) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l2];
    if ((t0 <= l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l4 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l2];
        return (l3 <= l4);
    }
    return false;
}

static uint8_t vader_vm$slot_valtype(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t t0;
    void* t1;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params));
    l3 = ((int64_t) (int32_t) l1);
    if ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l3, 628u);
        return ((uint8_t) t0.payload.i);
    }
    l2 = vader_chk_sub(i64, l3, l2);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals));
    if (!((l2 < l3))) {
        return (uint8_t) 2;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
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
    t0 = (void*) &vader_data_103;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    t1 = vader_vm$is_i32_tag(((uint8_t) t0.payload.i));
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Frame_t*) l0)->f_payload);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        { vader_box_t __vret = vader_box_i32(626u, ((int32_t) (int64_t) t2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_vm$peek_val(l0, l1);
    l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = concat_3(l2, 19u, l3);
    l4 = vader_vm$read_i32(l4, l5, l6);
    if (l4.tag == 2128u) {
        t3 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((int32_t) l4.payload.i);
    { vader_box_t __vret = vader_box_i32(626u, t4); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l3.tag == 2109u)) {
        l4 = l3;
        l5 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
        l6 = concat_2(l2, 260u);
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
        t2 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l4, 628u);
        t3 = ((uint8_t) t2.payload.i);
        { uint8_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(79));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 3511u);
    l4 = std_core$write_int(l3, l4, l2);
    l4 = std_core$write_string_at(l3, l4, 131u);
    t4 = std_core$finish_buffer(l3, l4);
    vader_host_std_core$Intrinsic$panic(t4);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_vm$start_guest_thread(void* l0, void* l1, int32_t l2, bool l3, vader_box_t l4) {
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    int32_t l6;
    void* l7 = NULL;
    void* l12 = NULL;
    int64_t l8, l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    vader_box_t* gc_roots[5] = { &l4, &l5, &l10, &l11, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l5 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
    if (!(l5.tag == 2098u)) {
        vader_struct_vader_vm$Trap_t* _a1_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a1_obj, 2128u);
        _a1_obj->f_message = 1914u;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t0)->f_function_index;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_functions;
    t1 = vader_vm$is_fn_index_out_of_range(l6, l7);
    if (t1) {
        vader_struct_vader_vm$Trap_t* _a2_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a2_obj, 2128u);
        _a2_obj->f_message = 1915u;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_vm$RegModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_reg)->f_functions;
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_vm$FnVal_t*) t0)->f_function_index;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
    l8 = ((vader_struct_vader_vm$RegFunction_t*) t0)->f_params;
    t0 = l5.payload.obj;
    l9 = vader_vm$environment_params(t0);
    if (l8 != l9) {
        vader_struct_vader_vm$Trap_t* _a4_obj = (vader_struct_vader_vm$Trap_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Trap_t));
        vader_obj_header_init(_a4_obj, 2128u);
        _a4_obj->f_message = 1916u;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(1))
    t2 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) INT32_C(1)];
    l10 = vader_vm$read_i64(t2, l2, 3197u);
    l11 = l10;
    if (l10.tag == 2128u) {
        t0 = l11.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = ((int64_t) l10.payload.i);
    l6 = vader_vm$debugged_thread_id(l8);
    l10 = vader_vm$debug_session(l4, l6);
    vader_struct___lambda_env_vader_vm_21_t* _a6_obj = (vader_struct___lambda_env_vader_vm_21_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_vm_21_t));
    vader_obj_header_init(_a6_obj, 871u);
    _a6_obj->f_cap_0 = l0;
    _a6_obj->f_cap_1 = l5;
    _a6_obj->f_cap_2 = l3;
    _a6_obj->f_cap_3 = l10;
    t0 = (void*) _a6_obj;
    vader_fn_t* _a7_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a7_closure, 526u);
    _a7_closure->code = (void*) &vader_fn_lift___lambda_vader_vm_20;
    _a7_closure->env = t0;
    t0 = (void*) _a7_closure;
    l9 = vader_host_std_core$Intrinsic$spawn_thread(t0, l8);
    t3 = vader_global_33;
    if (t3 == INT32_C(2)) {
        l7 = vader_global_34;
    } else {
        l7 = vader_vm$guest_threads();
    }
    l7 = ((vader_struct_vader_vm$GuestThreads_t*) l7)->f_live;
    vader_struct_vader_vm$GuestThread_t* _a8_obj = (vader_struct_vader_vm$GuestThread_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$GuestThread_t));
    vader_obj_header_init(_a8_obj, 2103u);
    _a8_obj->f_number = l8;
    _a8_obj->f_machine = vader_box_obj(0u, NULL);
    l12 = (void*) _a8_obj;
    std_collections$Map$std_core$IndexSet$set_at__i64__Any(l7, l9, vader_ref_box(l12));
    vader_struct_vader_vm$HostOk_t* _a9_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a9_obj, 2105u);
    _a9_obj->f_value = vader_box_i64(627u, l9);
    t0 = (void*) _a9_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_vm$std_descriptor(int64_t l0) {
    uint32_t l1;
    int32_t t0;
    t0 = ((int32_t) (int64_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if (l1 == INT32_C(-10)) {
        return INT64_C(0);
    }
    if (!(l1 == INT32_C(-12))) {
        return INT64_C(1);
    }
    return INT64_C(2);
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_debug;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) l3)->f_origin);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l7 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
    l9 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
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
        l11 = 2108u;
    } else {
        l11 = 3217u;
    }
    l6 = ((vader_struct_vader_vm$DebugController_t*) ((vader_struct_vader_vm$DebugSession_t*) l2)->f_controller)->f_on_pause;
    l10 = ((vader_struct_vader_vm$DebugSession_t*) l2)->f_thread_id;
    l8 = vader_vm$call_stack(l0, l1, l4, l5);
    l14 = vader_vm$debugged_threads(l0);
    vader_struct_vader_vm$PauseCtx_t* _a3_obj = (vader_struct_vader_vm$PauseCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$PauseCtx_t));
    vader_obj_header_init(_a3_obj, 2111u);
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
    int32_t l4, l10;
    int64_t l5, l9;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* l8 = NULL;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l5 = vader_chk_sub(i64, t0, INT64_C(2));
    l6 = vader_vm$stack_i32(l0, l5, l3, 3011u);
    l7 = l6;
    if (l6.tag == 2128u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l6.payload.i);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l5 = vader_chk_sub(i64, t0, INT64_C(3));
    l6 = vader_vm$stack_obj(l0, l5, l3);
    l7 = l6;
    if (l6.tag == 2128u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l6.payload.obj;
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ObjVal_t*) l8)->f_bytes));
    l10 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l6 = vader_vm$check_byte_range(l4, l1, l9, l3, l10);
    l7 = l6;
    if (l6.tag == 2128u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((int64_t) l6.payload.i);
    vader_core_bytecode$write_le(((vader_struct_vader_vm$ObjVal_t*) l8)->f_bytes, l5, l1, l2);
    t0 = ((vader_struct_vader_vm$Frame_t*) l0)->f_sp;
    l5 = vader_chk_sub(i64, t0, INT64_C(3));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_sp = l5;
    t2 = ((vader_struct_vader_vm$Frame_t*) l0)->f_pc;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    ((vader_struct_vader_vm$Frame_t*) l0)->f_pc = l4;
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
    l6 = vader_chk_sub(i64, t0, INT64_C(1));
    t1 = vader_vm$slot_valtype(l1, l3);
    l7 = vader_vm$narrow_code(t1);
    l8 = l5;
    l9 = INT64_C(0);
    while ((l9 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l9);
        if (((vader_struct_vader_vm$Pending_t*) t2)->f_kind == INT32_C(1)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
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
    l10 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
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
        ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l6] = (int32_t) l3;
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
        vader_obj_header_init(_a4_obj, 2115u);
        _a4_obj->f_kind = (uint8_t) 1;
        _a4_obj->f_register = l3;
        l14 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l10, l14);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$stream_of(int64_t l0) {
    if (l0 == INT64_C(1)) {
        return vader_box_i32(628u, INT32_C(0));
    }
    if (!(l0 == INT64_C(2))) {
        return vader_box_obj(0u, NULL);
    }
    return vader_box_i32(628u, INT32_C(1));
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
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(503u, (int64_t) t0, 0u, 3020u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        l6 = t1.payload.s;
        vader_array_push((vader_array_t*) l2, vader_box_string(623u, l6));
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_vm$ArrayVal_t* _a2_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a2_obj, 2093u);
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        if (l2.tag == 623u) {
            t1 = l2.payload.s;
            return vader_box_string(623u, t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_vm$string_byte_at(void* l0, int64_t l1) {
    int32_t l2, l3, l4;
    int64_t l5;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_vm$operand(l0, INT64_C(1));
    l3 = vader_vm$operand(l0, INT64_C(2));
    l4 = vader_vm$pop_to(l0, INT64_C(2));
    vader_vm$emit(l0, l1, INT32_C(123), l4, l3, l2);
    vader_vm$push_register(l0, l4);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_ops));
    l5 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_vm$Translation_t*) l0)->f_retarget = l5;
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_vm$string_byte_slice(void* l0, int64_t l1) {
    int64_t l2;
    int32_t l3, l4, l5;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
    l2 = vader_chk_sub(i64, t0, INT64_C(3));
    vader_vm$materialise(l0, l1, l2);
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
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_stack));
    l5 = vader_vm$canonical(l1, l4);
    l6 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_code)->f_values;
    l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings;
    l8 = ((vader_struct_vader_core_bytecode$StringConst_t*) l3)->f_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l8];
    l9 = t0.payload.s;
    vader_array_push((vader_array_t*) l6, vader_box_string(623u, l9));
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l1)->f_code)->f_values));
    t2 = vader_chk_sub(i64, t1, INT64_C(1));
    l8 = ((int32_t) (int64_t) t2);
    vader_vm$emit(l1, l2, INT32_C(110), l5, l8, INT32_C(0));
    vader_vm$push_register(l1, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_vm$string_import_op(void* l0, int64_t l1, uint8_t l2) {
    bool l3, l4;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(1)) {
        l3 = vader_vm$one_argument_string_op(l0, l1, INT32_C(122));
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(4)) {
        l3 = vader_vm$one_argument_string_op(l0, l1, INT32_C(125));
    } else if (l2 == INT32_C(7)) {
        l3 = vader_vm$one_argument_string_op(l0, l1, INT32_C(126));
    } else if (l2 == INT32_C(2)) {
        l3 = vader_vm$string_byte_at(l0, l1);
    } else if (l2 == INT32_C(3)) {
        l3 = vader_vm$string_byte_slice(l0, l1);
    } else {
        if (l2 == INT32_C(0)) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(5);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(6);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(13);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(8);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(9);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(10);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(11);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(12);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(20);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(21);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(22);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(23);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(24);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(25);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(14);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(15);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(16);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(17);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(18);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(19);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(26);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(27);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(28);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(29);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(30);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(31);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(32);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(33);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(34);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(35);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(36);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(37);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(38);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(39);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(40);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(42);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(43);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(44);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(45);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(46);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(41);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(47);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(48);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(49);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(50);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(51);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(52);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(53);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(54);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(57);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(55);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(56);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(58);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(59);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(60);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(61);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(62);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(63);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(64);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(65);
        }
        if (!(l4)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = false;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$struct_at(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    void* t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_tags);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
    if (((int32_t) t0.payload.i) == INT32_C(6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$RegMachine_t*) l0)->f_refs);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        if (l2.tag == 2125u) {
            t1 = l2.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static uint8_t vader_vm$tags_of_type(void* l0, int32_t l1) {
    int64_t l2;
    bool t0;
    vader_box_t t1;
    uint8_t t2;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_type_tags));
    t0 = vader_vm$in_range(l1, l2);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$TagContext_t*) l0)->f_type_tags);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
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
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_impl_table));
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_impl_table);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        t1 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) t0)->f_type_index;
        if (t1 == l2) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
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
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l7, 628u);
        l6 = ((uint8_t) t1.payload.i);
    } else {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l5)->f_pops;
    l7 = vader_chk_sub(i64, l4, l7);
    if (l1.tag == 1391u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t2)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    } else if (l1.tag == 1392u) {
        t2 = l1.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t2)->f_slot;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        ((uint8_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l8] = (uint8_t) (int32_t) (uint8_t) l6;
    }
    l9 = vader_vm$call_results(l0, l1);
    if (l9.tag == 0u) {
        t0 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l5)->f_pushes;
        if (t0 == INT64_C(1)) {
            l10 = vader_chk_add(i64, l3, l7);
            l14 = vader_vm$pushed_tags(l0, l1, l2, l6);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l14;
        }
    } else {
        l10 = vader_chk_add(i64, l3, l7);
        l11 = l9.payload.obj;
        l12 = vader_array_length(((vader_array_t*) l11));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_read_u8(_a4_slotarr, vader_array_offset(_a4_slotarr) + (size_t) l13, 628u);
            l6 = ((uint8_t) t1.payload.i);
            if (l6 != INT32_C(14)) {
                l14 = vader_vm$tags_of_val(l6);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l10] = (uint8_t) (int32_t) (uint8_t) l14;
                l10 = vader_chk_add(i64, l10, INT64_C(1));
            }
            l13 = (l13 + INT64_C(1));
        }
    }
    l10 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l5)->f_pushes;
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
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body));
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature)->f_params));
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_locals));
    l7 = vader_chk_add(i64, l7, l8);
    vader_array_t* _a1_arr = vader_array_new(30u, 0u, 8u, 627u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(31u, 0u, 1u, 628u);
    l10 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(35u, 0u, 0u, 634u);
    l11 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(30u, 0u, 8u, 627u);
    l12 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 626u);
    l13 = (void*) _a5_arr;
    vader_struct_std_collections$Map__Any__i64_t* _a6_obj = (vader_struct_std_collections$Map__Any__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__Any__i64_t));
    vader_obj_header_init(_a6_obj, 884u);
    _a6_obj->f_ekeys = l11;
    _a6_obj->f_evals = l12;
    _a6_obj->f_index = l13;
    _a6_obj->f_mask = INT64_C(0);
    _a6_obj->f_grow_at = INT64_C(0);
    _a6_obj->f_size = INT64_C(0);
    _a6_obj->f_tombs = INT64_C(0);
    l11 = (void*) _a6_obj;
    vader_vm$collect_constants(l5, l9, l10, l11);
    l8 = vader_array_length(((vader_array_t*) l9));
    l8 = vader_chk_add(i64, l7, l8);
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
    vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 626u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(30u, 0u, 8u, 627u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 626u);
    l15 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(31u, 0u, 1u, 628u);
    l16 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l17 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(476u, 0u, 13u, 2483u);
    l18 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(213u, 0u, 13u, 1437u);
    l19 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(29u, 0u, 7u, 626u);
    l20 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(28u, 0u, 0u, 623u);
    l21 = (void*) _a15_arr;
    l22 = ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_deepest;
    t0 = vader_chk_add(i64, l8, l22);
    l22 = vader_chk_add(i64, t0, INT64_C(1));
    l23 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature)->f_params));
    vader_struct_vader_vm$RegFunction_t* _a16_obj = (vader_struct_vader_vm$RegFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegFunction_t));
    vader_obj_header_init(_a16_obj, 2117u);
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
    vader_array_t* _a17_arr = vader_array_new(29u, 0u, 7u, 626u);
    l10 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(455u, 0u, 13u, 2115u);
    l12 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(30u, 0u, 8u, 627u);
    l13 = (void*) _a19_arr;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_vm$Translation_t* _a20_obj = (vader_struct_vader_vm$Translation_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Translation_t));
    vader_obj_header_init(_a20_obj, 2127u);
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
    vader_array_t* _a21_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = (int64_t) INT64_C(0);
    l11 = (void*) _a21_arr;
    l7 = vader_chk_add(i64, l6, INT64_C(1));
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) l11, (int64_t) l7);
    l11 = (void*) _a22_arr;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
        t1 = ((uint8_t*) _a23_slotarr->buf->slots)[vader_array_offset(_a23_slotarr) + (size_t) l7];
        t2 = t1;
        if (t2) {
            vader_vm$flush(l9, l7);
        }
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_ops));
        vader_array_t* _a24_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
        ((int64_t*) _a24_slotarr->buf->slots)[vader_array_offset(_a24_slotarr) + (size_t) l7] = (int64_t) l8;
        vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_depth);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
        t0 = ((int64_t*) _a25_slotarr->buf->slots)[vader_array_offset(_a25_slotarr) + (size_t) l7];
        if ((t0 < INT64_C(0))) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
        t1 = ((uint8_t*) _a26_slotarr->buf->slots)[vader_array_offset(_a26_slotarr) + (size_t) l7];
        t2 = t1;
        if (t2) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) l3)->f_depth);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            l22 = ((int64_t*) _a27_slotarr->buf->slots)[vader_array_offset(_a27_slotarr) + (size_t) l7];
            vader_vm$reset_stack(l9, l22);
        }
        if (l4) {
            l23 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_debug));
            if ((l7 < l23)) {
                vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_debug);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
                t3 = vader_array_ref_load_box(_a28_slotarr->buf, vader_array_offset(_a28_slotarr) + (size_t) l7);
                if (!(t3.tag == 0u)) {
                    vader_vm$emit(l9, l7, INT32_C(130), INT32_C(0), INT32_C(0), INT32_C(0));
                }
            }
        }
        t1 = vader_vm$translate_op(l0, l5, l3, l9, l7);
        if (!(t1)) {
            l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
            l24 = ((int32_t) (int64_t) l7);
            vader_struct_vader_vm$VerifyError_t* _a29_obj = (vader_struct_vader_vm$VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VerifyError_t));
            vader_obj_header_init(_a29_obj, 2131u);
            _a29_obj->f_function = l14;
            _a29_obj->f_pc = l24;
            _a29_obj->f_message = 2984u;
            t4 = (void*) _a29_obj;
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (l7 + INT64_C(1));
    }
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_ops));
    vader_array_t* _a30_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
    ((int64_t*) _a30_slotarr->buf->slots)[vader_array_offset(_a30_slotarr) + (size_t) l6] = (int64_t) l7;
    vader_vm$emit(l9, l6, INT32_C(107), INT32_C(-1), INT32_C(0), INT32_C(0));
    l6 = INT64_C(0);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_jumps));
    l7 = vader_div_i64(t0, INT64_C(2));
    while ((l6 < l7)) {
        l10 = ((vader_struct_vader_vm$Translation_t*) l9)->f_jumps;
        l8 = vader_chk_mul(i64, INT64_C(2), l6);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l8)
        l22 = ((int64_t*) _a31_slotarr->buf->slots)[vader_array_offset(_a31_slotarr) + (size_t) l8];
        l12 = ((vader_struct_vader_vm$Translation_t*) l9)->f_operands;
        l23 = vader_chk_mul(i64, INT64_C(3), l22);
        l13 = ((vader_struct_vader_vm$Translation_t*) l9)->f_jumps;
        t0 = vader_chk_mul(i64, INT64_C(2), l6);
        l25 = vader_chk_add(i64, t0, INT64_C(1));
        vader_array_t* _a32_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l25)
        l26 = ((int64_t*) _a32_slotarr->buf->slots)[vader_array_offset(_a32_slotarr) + (size_t) l25];
        vader_array_t* _a33_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l26)
        t0 = ((int64_t*) _a33_slotarr->buf->slots)[vader_array_offset(_a33_slotarr) + (size_t) l26];
        l24 = ((int32_t) (int64_t) t0);
        vader_array_t* _a34_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l23)
        ((int32_t*) _a34_slotarr->buf->slots)[vader_array_offset(_a34_slotarr) + (size_t) l23] = (int32_t) l24;
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_ops));
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
            l30 = ((int32_t*) _a35_slotarr->buf->slots)[vader_array_offset(_a35_slotarr) + (size_t) l6];
            vader_struct_vader_vm$VerifyError_t* _a36_obj = (vader_struct_vader_vm$VerifyError_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$VerifyError_t));
            vader_obj_header_init(_a36_obj, 2131u);
            _a36_obj->f_function = l14;
            _a36_obj->f_pc = l30;
            _a36_obj->f_message = 1996u;
            t4 = (void*) _a36_obj;
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((int64_t) l29.payload.i);
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l9)->f_code)->f_words, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(((vader_struct_vader_vm$Translation_t*) l9)->f_code); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$translate_module(void* l0, void* l1, void* l2, bool l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t l5, l6;
    int32_t l8;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l10, &l11 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l7, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    vader_array_t* _a0_arr = vader_array_reserve(456u, (int64_t) t0, 13u, 2117u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    while ((l5 < l6)) {
        l8 = ((int32_t) (int64_t) l5);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l10 = vader_vm$translate_function(l0, l1, l8, l9, l3);
        l11 = l10;
        if (l10.tag == 2131u) {
            t1 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l10.payload.obj;
        vader_array_push_ref((vader_array_t*) l4, l7);
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_vm$RegModule_t* _a2_obj = (vader_struct_vader_vm$RegModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$RegModule_t));
    vader_obj_header_init(_a2_obj, 2119u);
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
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops));
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
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops));
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l12;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 1390u) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_stack;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
        vader_struct_vader_vm$Pending_t* _a1_obj = (vader_struct_vader_vm$Pending_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$Pending_t));
        vader_obj_header_init(_a1_obj, 2115u);
        _a1_obj->f_kind = (uint8_t) 1;
        _a1_obj->f_register = l8;
        l14 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l13, l14);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l5.tag == 1391u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
        vader_vm$store_slot(l3, l1, l4, l8, false, l6);
    } else if (l5.tag == 1392u) {
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t1)->f_slot;
        vader_vm$store_slot(l3, l1, l4, l8, true, l6);
    } else if ((l5.tag == 1296u || l5.tag == 1311u || l5.tag == 1324u || l5.tag == 1345u || l5.tag == 1365u || l5.tag == 1397u)) {
        l7 = l5;
        vader_vm$push_constant(l3, l7);
    } else if (l5.tag == 1319u) {
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
    } else if ((l5.tag == 1294u || l5.tag == 1321u || l5.tag == 1393u || l5.tag == 1398u || l5.tag == 1401u)) {
        ((vader_struct_vader_vm$Translation_t*) l3)->f_retarget = l6;
    } else if ((l5.tag == 1301u || l5.tag == 1320u)) {
        if (l5.tag == 1320u) {
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
            l8 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
            vader_vm$jump(l3, l4, INT32_C(87), INT32_C(0), INT32_C(0), l8);
        }
    } else if ((l5.tag == 1302u || l5.tag == 1380u)) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_stack;
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack));
        l12 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
        l13 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l12);
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
        vader_vm$flush(l3, l4);
        l15 = vader_vm$skips_else(l1, l4);
        if (l5.tag == 1302u) {
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
        l8 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l12];
        if (((vader_struct_vader_vm$Pending_t*) l13)->f_kind == INT32_C(0)) {
            l17 = (l6 >= INT64_C(0));
        } else {
            l17 = false;
        }
        if (l17) {
            t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_ops));
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
            t3 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l6];
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
    } else if (l5.tag == 1402u) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a6_slotarr, vader_array_offset(_a6_slotarr) + (size_t) INT32_C(0), 628u);
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
                t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack));
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
    } else if (l5.tag == 1310u) {
        l14 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t1)->f_type_id;
        l7 = vader_core_bytecode$fn_at(l14, l8);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) l13)->f_params));
        vader_vm$flush(l3, l4);
        l12 = vader_chk_add(i64, l6, INT64_C(1));
        l8 = vader_vm$pop_to(l3, l12);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t1)->f_type_id;
        l10 = ((int32_t) (int64_t) l6);
        vader_vm$emit(l3, l4, INT32_C(104), l9, l8, l10);
        l14 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        l9 = ((vader_struct_vader_core_bytecode$BcFn_t*) l13)->f_return_type;
        t4 = vader_core_bytecode$is_void_at(l14, l9);
        if (!(t4)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 1437u) {
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
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_virtuals));
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l9 = ((int32_t) (int64_t) t5);
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t1)->f_parameter_count;
        vader_vm$emit(l3, l4, INT32_C(105), l9, l8, l10);
        if (l6 == INT64_C(1)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 1308u) {
        l13 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$Call_t*) t1)->f_function_index;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l8);
        l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_signature;
        l6 = vader_core_bytecode$bc_result_arity(l13);
        vader_vm$flush(l3, l4);
        l12 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l13)->f_params));
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
    } else if (l5.tag == 1403u) {
        t1 = l5.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t1)->f_value;
        if (l7.tag == 1414u) {
            l13 = l7.payload.obj;
            vader_vm$string_constant(l0, l3, l4, l13);
        } else {
            vader_vm$push_constant(l3, l7);
        }
        l8 = vader_vm$operand(l3, INT64_C(1));
        vader_vm$emit(l3, l4, INT32_C(107), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1309u) {
        l13 = ((vader_struct_vader_vm$Translation_t*) l3)->f_import_ids;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
        t2 = vader_array_read_u8(_a8_slotarr, vader_array_offset(_a8_slotarr) + (size_t) l8, 628u);
        l20 = ((uint8_t) t2.payload.i);
        t4 = vader_vm$string_import_op(l3, l4, l20);
        if (t4) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l13 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l8);
        l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) t1)->f_signature;
        vader_vm$flush(l3, l4);
        l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l13)->f_params));
        l8 = vader_vm$pop_to(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t1)->f_index;
        vader_vm$emit(l3, l4, INT32_C(121), l9, l8, INT32_C(0));
        t6 = vader_core_bytecode$bc_single_result(l13);
        if (t6 != INT32_C(14)) {
            vader_vm$push_register(l3, l8);
        }
    } else if (l5.tag == 1318u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack);
        vader_vm$emit(l3, l4, INT32_C(128), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1317u) {
        vader_vm$flush(l3, l4);
        t1 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t1)->f_count;
        vader_vm$emit(l3, l4, INT32_C(129), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1336u) {
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts;
        l14 = (void*) vader_buffer_new((size_t) INT64_C(87));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l14, l6, 2548u);
        l6 = std_core$write_int(l14, l6, l4);
        l6 = std_core$write_string_at(l14, l6, 601u);
        l21 = std_core$finish_buffer(l14, l6);
        vader_array_push_scalar((vader_array_t*) l13, vader_box_string(623u, l21));
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts));
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm$emit(l3, l4, INT32_C(127), l8, INT32_C(0), INT32_C(0));
        l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack));
        l8 = vader_vm$canonical(l3, l6);
        vader_vm$push_register(l3, l8);
    } else if (l5.tag == 1436u) {
        l13 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts;
        t1 = l5.payload.obj;
        l21 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t1)->f_reason;
        l21 = concat_2(3094u, l21);
        vader_array_push_scalar((vader_array_t*) l13, vader_box_string(623u, l21));
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_code)->f_texts));
        t5 = vader_chk_sub(i64, t0, INT64_C(1));
        l8 = ((int32_t) (int64_t) t5);
        vader_vm$emit(l3, l4, INT32_C(127), l8, INT32_C(0), INT32_C(0));
    } else if (l5.tag == 1389u) {
        l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l3)->f_stack));
        l8 = vader_vm$canonical(l3, l6);
        t1 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t1)->f_slot;
        t1 = l5.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$LocalField_t*) t1)->f_field_index;
        vader_vm$emit(l3, l4, INT32_C(111), l8, l9, l10);
        vader_vm$push_register(l3, l8);
    } else if ((l5.tag == 1417u || l5.tag == 1434u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructGet_t, f_field_index, l5.payload.obj);
        vader_vm$emit(l3, l4, INT32_C(111), l9, l8, l10);
        vader_vm$push_register(l3, l9);
    } else if ((l5.tag == 1419u || l5.tag == 1435u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        vader_vm$pop_to(l3, INT64_C(2));
        l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$StructSet_t, f_field_index, l5.payload.obj);
        vader_vm$emit(l3, l4, INT32_C(112), l9, l8, l10);
    } else if ((l5.tag == 1262u || l5.tag == 1385u || l5.tag == 1386u || l5.tag == 1387u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$pop_to(l3, INT64_C(2));
        if (l5.tag == 1262u) {
            l11 = INT32_C(114);
        } else {
            l11 = INT32_C(116);
        }
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
        vader_vm$push_register(l3, l10);
    } else if ((l5.tag == 1270u || l5.tag == 1409u || l5.tag == 1410u || l5.tag == 1411u)) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        l10 = vader_vm$operand(l3, INT64_C(3));
        vader_vm$pop_to(l3, INT64_C(3));
        if (l5.tag == 1270u) {
            l11 = INT32_C(115);
        } else {
            l11 = INT32_C(117);
        }
        vader_vm$emit(l3, l4, l11, l10, l9, l8);
    } else if (l5.tag == 1263u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$pop_to(l3, INT64_C(1));
        vader_vm$emit(l3, l4, INT32_C(118), l9, l8, INT32_C(0));
        vader_vm$push_register(l3, l9);
    } else if (l5.tag == 1265u) {
        l8 = vader_vm$operand(l3, INT64_C(1));
        l9 = vader_vm$operand(l3, INT64_C(2));
        vader_vm$pop_to(l3, INT64_C(2));
        vader_vm$emit(l3, l4, INT32_C(119), l9, l8, INT32_C(0));
    } else if (l5.tag == 1414u) {
        l13 = l5.payload.obj;
        vader_vm$string_constant(l0, l3, l4, l13);
    } else if (l5.tag == 1438u) {
        vader_vm$void_constant(l3, l4);
    } else {
        t4 = vader_vm$is_boxed(l5);
        if (!(t4)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l7 = l5;
        l7 = vader_core_bytecode$stack_effect(l0, l1, l7);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l13 = l7.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l13)->f_pops;
        l12 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l13)->f_pushes;
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l6];
    l9 = ((int32_t) (int64_t) t0);
    l7 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_raw;
    if (l7.tag == 0u) {
        if ((l9 < INT32_C(0))) {
            return false;
        }
        l10 = ((int64_t) (int32_t) l9);
        l12 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements));
        if (!((l10 >= l12))) {
            l12 = ((int64_t) (int32_t) l2);
            l12 = vader_chk_add(i64, l1, l12);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            l13 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l9];
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l6];
    l9 = ((int32_t) (int64_t) t0);
    if (((vader_struct_vader_vm$ArrayVal_t*) l5)->f_raw.tag == 0u) {
        if ((l9 < INT32_C(0))) {
            return false;
        }
        l6 = ((int64_t) (int32_t) l9);
        l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements));
        if (!((l6 >= l10))) {
            l5 = ((vader_struct_vader_vm$ArrayVal_t*) l5)->f_elements;
            l6 = ((int64_t) (int32_t) l4);
            l6 = vader_chk_add(i64, l1, l6);
            l7 = vader_vm$register_value(l0, l6);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l9] = l7;
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
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types));
    if ((l3 >= l4)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    if (l5.tag == 1283u) {
        t0 = l5.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
        l6 = vader_vm$class_matches(l1, l7);
        return l6;
    }
    if (l5.tag == 1286u) {
        if (l1.tag == 2125u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$StructVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 1273u) {
        if (l1.tag == 2093u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_vm$ArrayVal_t*) t0)->f_type_id;
            l6 = t1 == l2;
        } else {
            l6 = false;
        }
    } else if (l5.tag == 1287u) {
        t0 = l5.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l6 = vader_vm$union_matches(l0, l1, l8);
    } else if (l5.tag == 1282u) {
        t0 = l5.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
        l6 = vader_vm$ref_type_matches(l0, l1, l9);
    } else {
        if (!(l5.tag == 1276u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = false;
    }
    return l6;
}

static int32_t vader_vm$type_operand(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1420u)) {
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
    l3 = vader_array_length(((vader_array_t*) l0));
    t0 = vader_vm$in_range(l1, l3);
    if (t0) {
        if ((l2 > INT32_C(8))) {
            return (uint8_t) 127;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        if (l4.tag == 1283u) {
            t1 = l4.payload.obj;
            l5 = vader_vm$tags_of_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val);
            return l5;
        }
        if ((l4.tag == 1273u || l4.tag == 1276u || l4.tag == 1286u)) {
            l5 = (uint8_t) 64;
        } else if (l4.tag == 1282u) {
            l5 = (uint8_t) 127;
        } else {
            if (!(l4.tag == 1287u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l6 = (uint8_t) 0;
            t1 = l4.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
            l3 = vader_array_length(((vader_array_t*) l7));
            l8 = INT64_C(0);
            while ((l8 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l9 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l8];
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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
    if (l1.tag == 1355u) {
        l5 = vader_box_i32(626u, INT32_C(13));
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1342u) {
        l5 = vader_box_i32(626u, INT32_C(14));
    } else if (l1.tag == 1375u) {
        l5 = vader_box_i32(626u, INT32_C(38));
    } else if (l1.tag == 1362u) {
        l5 = vader_box_i32(626u, INT32_C(39));
    } else if (l1.tag == 1333u) {
        l5 = vader_box_i32(626u, INT32_C(56));
    } else if (l1.tag == 1313u) {
        t1 = l1.payload.obj;
        t0 = vader_vm$checked_neg_register_op(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t1)->f_kind);
        l5 = vader_box_i32(626u, t0);
    } else if (l1.tag == 1299u) {
        t2 = vader_vm$stack_tags(l2, l3, INT64_C(1));
        t3 = vader_vm$tags_within(t2, (uint8_t) 8);
        if (t3) {
            l5 = vader_box_i32(626u, INT32_C(67));
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l1.tag == 1420u) {
        l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
        t1 = l1.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t1)->f_type_id;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
        if (t4.tag == 1286u) {
            l5 = vader_box_i32(626u, INT32_C(113));
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l1.tag == 1314u) {
        t2 = vader_vm$stack_tags(l2, l3, INT64_C(1));
        t3 = vader_vm$tags_within(t2, l4);
        if (t3) {
            t1 = l1.payload.obj;
            if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(0)) {
                l5 = vader_box_i32(626u, INT32_C(83));
            } else {
                t1 = l1.payload.obj;
                if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(1)) {
                    t1 = l1.payload.obj;
                    t5 = ((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_from_name;
                    t0 = vader_vm$widening(t5);
                    l5 = vader_box_i32(626u, t0);
                } else {
                    t1 = l1.payload.obj;
                    if (((vader_struct_vader_core_bytecode$Convert_t*) t1)->f_target == INT32_C(3)) {
                        l5 = vader_box_i32(626u, INT32_C(86));
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
    l4 = vader_array_length(((vader_array_t*) l2));
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
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
        { vader_gc_top = gc_frame.prev; return 2210u; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_std_core$CLibrary_t*) l1)->f_name;
    t0 = concat_3(2208u, l3, 1310u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_vm$unwind(void* l0, void* l1, void* l2, bool l3) {
    int64_t l4, l7;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
        if ((t0 > INT64_C(0))) {
            t0 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count = l4;
            l6 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defers;
            l7 = ((vader_struct_vader_vm$RegMachine_t*) l2)->f_defer_count;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l8 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l7];
            l9 = vader_vm$defer_thunk(l0, l8, INT32_C(0), 3051u);
            if (l9.tag == 2128u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l5 = l9.payload.obj;
            t1 = vader_vm$run_thunk(l0, l1, l2, l5, INT64_C(0), INT64_C(0), INT64_C(0), l3);
            if (!(t1.tag == 2128u)) {
                continue;
            }
            { vader_gc_top = gc_frame.prev; return; }
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
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
        return vader_box_i32(626u, ((int32_t) (int64_t) (l1 & INT64_C(255))));
    }
    if (l0 == INT32_C(5)) {
        t0 = (l1 & INT64_C(255));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(128))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(256));
            return vader_box_i32(626u, t1);
        }
        return vader_box_i32(626u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(12)) {
        return vader_box_bool(621u, l1 != INT64_C(0));
    }
    if (l0 == INT32_C(2)) {
        return vader_box_i32(626u, ((int32_t) (int64_t) (l1 & INT64_C(65535))));
    }
    if (l0 == INT32_C(6)) {
        t0 = (l1 & INT64_C(65535));
        l2 = (uint64_t) (int64_t) t0;
        if ((l2 >= INT64_C(32768))) {
            t1 = vader_chk_sub(i32, ((int32_t) (uint64_t) l2), INT32_C(65536));
            return vader_box_i32(626u, t1);
        }
        return vader_box_i32(626u, ((int32_t) (uint64_t) l2));
    }
    if (l0 == INT32_C(3)) {
        return vader_box_i32(626u, ((int32_t) ((int32_t) (uint64_t) l1)));
    }
    if (l0 == INT32_C(7)) {
        return vader_box_i32(626u, ((int32_t) ((int32_t) (uint64_t) l1)));
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
                return vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l3));
            }
        } else {
            return vader_box_i32(622u, (int32_t) ((uint32_t) (uint32_t) l3));
        }
    } else {
        if (l0 == INT32_C(4)) {
            return vader_box_i64(627u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(8)) {
            return vader_box_i64(627u, ((int64_t) (uint64_t) l1));
        }
        if (l0 == INT32_C(9)) {
            return vader_box_f64(633u, ((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
        }
        if (!(l0 == INT32_C(10))) {
            return vader_box_i32(626u, INT32_C(0));
        }
        return vader_box_f64(633u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
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
    void* t2;
    if (l0.tag == 2108u) {
        l2 = l1.tag == 2108u;
        return l2;
    }
    if (l0.tag == 2133u) {
        l2 = l1.tag == 2133u;
    } else if (l0.tag == 626u) {
        if (l1.tag == 626u) {
            l3 = ((int32_t) l0.payload.i);
            l4 = ((int32_t) l1.payload.i);
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 621u) {
        if (l1.tag == 621u) {
            l5 = l0.payload.b;
            l6 = l1.payload.b;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 622u) {
        if (l1.tag == 622u) {
            l7 = ((uint32_t) l0.payload.i);
            l8 = ((uint32_t) l1.payload.i);
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 623u) {
        if (l1.tag == 623u) {
            l9 = l0.payload.s;
            l10 = l1.payload.s;
            l2 = l9 == l10;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 627u) {
        if (l1.tag == 627u) {
            l11 = ((int64_t) l0.payload.i);
            l12 = ((int64_t) l1.payload.i);
            l2 = l11 == l12;
        } else {
            l2 = false;
        }
    } else if ((l0.tag == 632u || l0.tag == 633u)) {
        if ((l1.tag == 632u || l1.tag == 633u)) {
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
    } else if ((l0.tag == 2093u || l0.tag == 2098u || l0.tag == 2109u || l0.tag == 2125u)) {
        if ((l1.tag == 2093u || l1.tag == 2098u || l1.tag == 2109u || l1.tag == 2125u)) {
            l15 = l0;
            l16 = l1;
            l2 = vader_box_eq(l15, l16);
        } else {
            l2 = false;
        }
    } else {
        if (!(l0.tag == 2129u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if (l1.tag == 2129u) {
            t2 = l0.payload.obj;
            l3 = ((vader_struct_vader_vm$TypeVal_t*) t2)->f_type_id;
            t2 = l1.payload.obj;
            l4 = ((vader_struct_vader_vm$TypeVal_t*) t2)->f_type_id;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    }
    return l2;
}

static vader_box_t vader_vm$verify_function(void* l0, void* l1) {
    int64_t l2, l3, l4, l7, l9, l15, l17, l19, l20, l23, l25, l26, l27, l28, l30, l35, l39;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l31 = vader_box_null(), l32 = vader_box_null(), l40 = vader_box_null(), l41 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l21 = 0;
    vader_string_t l24 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    bool l29, l33, l36;
    int32_t l34;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[7] = { &l8, &l10, &l12, &l31, &l32, &l40, &l41 };
    void** gc_raw_roots[8] = { &l0, &l1, &l5, &l6, &l11, &l18, &l22, &t0 };
    vader_string_t* gc_atom_roots[7] = { &l13, &l14, &l16, &l21, &l24, &l37, &l38 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body));
    if (l2 == INT64_C(0)) {
        { vader_box_t __vret = vader_box_i64(627u, INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = INT64_C(0);
    l4 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature);
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int64_t) INT64_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)] = (int64_t) INT64_C(0);
    vader_array_t* _a3_arr = vader_array_new(30u, 1u, 8u, 627u);
    ((int64_t*) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = (int64_t) INT64_C(0);
    l6 = (void*) _a3_arr;
    for (;;) {
        t1 = vader_array_length(((vader_array_t*) l6));
        if ((t1 > INT64_C(0))) {
            l8 = vader_array_remove_last((vader_array_t*) l6);
            if (l8.tag == 0u) break;
            l7 = ((int64_t) l8.payload.i);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            l9 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l7];
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
            l12 = vader_core_bytecode$stack_effect(l0, l1, l10);
            if (l12.tag == 0u) {
                l13 = vader_vm$op_text(l10);
                l14 = concat_3(1310u, l13, 1540u);
                t0 = vader_vm$defect(l1, l7, l14);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = l12.payload.obj;
            l15 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_pops;
            if ((l9 < l15)) {
                l16 = vader_vm$op_text(l10);
                l17 = vader_host_std_core$Intrinsic$byte_len(l16);
                l18 = (void*) vader_buffer_new((size_t) (INT64_C(79) + l17));
                l19 = INT64_C(0);
                l19 = std_core$write_string_at(l18, l19, 1310u);
                l19 = std_core$write_string_at(l18, l19, l16);
                l19 = std_core$write_string_at(l18, l19, 1543u);
                l20 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_pops;
                l19 = std_core$write_int(l18, l19, l20);
                l19 = std_core$write_string_at(l18, l19, 289u);
                l19 = std_core$write_int(l18, l19, l9);
                l21 = std_core$finish_buffer(l18, l19);
                t0 = vader_vm$defect(l1, l7, l21);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l10.tag == 1402u) {
                if (l9 != l4) {
                    l22 = (void*) vader_buffer_new((size_t) INT64_C(87));
                    l23 = INT64_C(0);
                    l23 = std_core$write_string_at(l22, l23, 1769u);
                    l23 = std_core$write_int(l22, l23, l4);
                    l23 = std_core$write_string_at(l22, l23, 289u);
                    l23 = std_core$write_int(l22, l23, l9);
                    l24 = std_core$finish_buffer(l22, l23);
                    t0 = vader_vm$defect(l1, l7, l24);
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l25 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_pops;
            l26 = vader_chk_sub(i64, l9, l25);
            l27 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_pushes;
            l28 = vader_chk_add(i64, l26, l27);
            if ((l28 > l3)) {
                l3 = l28;
            }
            if (((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_flow == INT32_C(0)) {
                l29 = true;
            } else {
                l29 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (l29) {
                l30 = vader_chk_add(i64, l7, INT64_C(1));
                l31 = vader_vm$flow_to(l1, l5, l6, l30, l28, l7, l4);
                l32 = l31;
                if (l31.tag == 2131u) {
                    t0 = l32.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            if (((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_flow == INT32_C(1)) {
                l33 = true;
            } else {
                l33 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l11)->f_flow == INT32_C(2);
            }
            if (!(l33)) {
                continue;
            }
            l35 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table));
            if ((l7 < l35)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
                l34 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l7];
            } else {
                l34 = INT32_C(-1);
            }
            if ((l34 < INT32_C(0))) {
                l36 = true;
            } else {
                l36 = (((int64_t) (int32_t) l34) > l2);
            }
            if (l36) {
                l37 = vader_vm$op_text(l10);
                l38 = concat_3(1310u, l37, 1407u);
                t0 = vader_vm$defect(l1, l7, l38);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l39 = ((int64_t) (int32_t) l34);
            l40 = vader_vm$flow_to(l1, l5, l6, l39, l28, l7, l4);
            l41 = l40;
            if (!(l40.tag == 2131u)) {
                continue;
            }
            t0 = l41.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(627u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_vm$verify_module(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    vader_array_t* _a0_arr = vader_array_reserve(30u, (int64_t) t0, 8u, 627u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l7 = vader_vm$verify_function(l0, l5);
        l8 = l7;
        if (l7.tag == 2131u) {
            t1 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((int64_t) l7.payload.i);
        vader_array_push_i64((vader_array_t*) l1, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_vm$view_of(void* l0, int32_t l1, int64_t l2, int64_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    int64_t l8, l9;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_raw;
    if (l5.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements, (int64_t) l2, (int64_t) l3);
        l4 = (void*) _a0_arr;
        vader_struct_vader_vm$ArrayVal_t* _a1_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
        vader_obj_header_init(_a1_obj, 2093u);
        _a1_obj->f_type_id = l1;
        _a1_obj->f_elements = l4;
        _a1_obj->f_raw = vader_box_obj(0u, NULL);
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    l6 = ((vader_struct_vader_vm$ArrayVal_t*) l0)->f_elements;
    l7 = ((vader_struct_vader_vm$StringWindow_t*) l4)->f_text;
    t1 = ((vader_struct_vader_vm$StringWindow_t*) l4)->f_offset;
    l8 = vader_chk_add(i64, t1, l2);
    l9 = vader_chk_sub(i64, l3, l2);
    vader_struct_vader_vm$StringWindow_t* _a2_obj = (vader_struct_vader_vm$StringWindow_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$StringWindow_t));
    vader_obj_header_init(_a2_obj, 2124u);
    _a2_obj->f_text = l7;
    _a2_obj->f_offset = l8;
    _a2_obj->f_length = l9;
    l4 = (void*) _a2_obj;
    vader_struct_vader_vm$ArrayVal_t* _a3_obj = (vader_struct_vader_vm$ArrayVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$ArrayVal_t));
    vader_obj_header_init(_a3_obj, 2093u);
    _a3_obj->f_type_id = l1;
    _a3_obj->f_elements = l6;
    _a3_obj->f_raw = vader_ref_box(l4);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_vm$void_constant(void* l0, int64_t l1) {
    int64_t l2;
    int32_t l3, l6;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    int64_t t1, t2;
    void** gc_raw_roots[4] = { &l0, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_stack));
    l3 = vader_vm$canonical(l0, l2);
    l4 = ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_values;
    t0 = (void*) &vader_data_104;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$RegFunction_t*) ((vader_struct_vader_vm$Translation_t*) l0)->f_code)->f_values));
    t2 = vader_chk_sub(i64, t1, INT64_C(1));
    l6 = ((int32_t) (int64_t) t2);
    vader_vm$emit(l0, l1, INT32_C(110), l3, l6, INT32_C(0));
    vader_vm$push_register(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_vm$void_result(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_103;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    vader_struct_vader_vm$HostOk_t* _a1_obj = (vader_struct_vader_vm$HostOk_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm$HostOk_t));
    vader_obj_header_init(_a1_obj, 2105u);
    _a1_obj->f_value = vader_ref_box(t0);
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_vm$vtable_row_of(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    void* t0;
    vader_string_t t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
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
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body));
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
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l12, 628u);
        l13 = ((uint8_t) t0.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l9] = (uint8_t) (int32_t) (uint8_t) l13;
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_entry_depth);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l8 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l3];
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_leaders);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    l9 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l3];
    for (;;) {
        if ((l9 < l7)) {
            if (!(l6.tag == 0u)) {
                t1 = l6.payload.obj;
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$FunctionTags_t*) t1)->f_depth);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l9] = (int64_t) l8;
                l10 = INT64_C(1);
                l12 = std_math$min__i64(l8, INT64_C(2));
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
                    t0 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l16, 628u);
                    l13 = ((uint8_t) t0.payload.i);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
                    ((uint8_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l15] = (uint8_t) (int32_t) (uint8_t) l13;
                    l14 = (l10 < l12);
                    l10 = (l10 + INT64_C(1));
                }
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            l17 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
            l19 = vader_core_bytecode$stack_effect(((vader_struct_vader_vm$TagContext_t*) l0)->f_module, l1, l17);
            if (l19.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l18 = l19.payload.obj;
            l8 = vader_vm$transfer(l0, l17, l5, l4, l8, l18);
            if (l6.tag == 0u) {
                if (((vader_struct_vader_core_bytecode$StackEffect_t*) l18)->f_flow == INT32_C(1)) {
                    l21 = true;
                } else {
                    l21 = ((vader_struct_vader_core_bytecode$StackEffect_t*) l18)->f_flow == INT32_C(2);
                }
                l20 = l21;
            } else {
                l20 = false;
            }
            if (l20) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
                t4 = ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l9];
                l22 = ((int64_t) (int32_t) t4);
                if ((l22 < l7)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_block_at);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l22)
                    l23 = ((int64_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l22];
                    vader_vm$merge_block(l2, l23, l8, l5);
                }
            }
            if (((vader_struct_vader_core_bytecode$StackEffect_t*) l18)->f_flow != INT32_C(0)) {
                if (((vader_struct_vader_core_bytecode$StackEffect_t*) l18)->f_flow != INT32_C(2)) {
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
            t2 = ((int64_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l9];
            if (!((t2 >= INT64_C(0)))) {
                continue;
            }
            if (l6.tag == 0u) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$Blocks_t*) l2)->f_block_at);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                l24 = ((int64_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l9];
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

static int64_t vader_vm$word_of_class(int64_t l0, uint8_t l1) {
    int64_t l2;
    bool l3;
    bool t0;
    int32_t t1;
    int64_t t2;
    t0 = vader_core_bytecode$is_integer_val(l1);
    if (!(t0)) {
        return l0;
    }
    t1 = vader_core_bytecode$size_of_val_type(l1);
    l2 = ((int64_t) (int32_t) t1);
    t0 = vader_core_bytecode$is_unsigned_val(l1);
    l3 = !(t0);
    t2 = vader_vm$at_width(l0, l2, l3);
    return t2;
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
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l8;
        l5 = (l5 + INT64_C(1));
    }
    return;
}

static vader_box_t vader_vm$written_scalar(void* l0, int64_t l1, int64_t l2, uint8_t l3) {
    bool l4;
    int64_t l5;
    bool t0;
    vader_box_t t1;
    double t2;
    t0 = vader_core_bytecode$is_float_val(l3);
    if (!(t0)) {
        t0 = vader_core_bytecode$is_unsigned_val(l3);
        l4 = !(t0);
        l5 = vader_vm$read_little_endian(l0, l1, l2, l4);
        t1 = vader_vm$scalar_value(l3, l5);
        return t1;
    }
    t2 = vader_vm$read_float(l0, l1, l2);
    return vader_box_f64(633u, t2);
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
    t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l4, 628u);
    if (!(((int32_t) t0.payload.i) == INT32_C(0))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
        return t1;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t1 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
    return ((int64_t) (uint32_t) ((int32_t) (int64_t) t1));
}

static vader_box_t vader_vm$zero_value(void) {
    return vader_box_i32(626u, INT32_C(0));
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
    vader_array_t* _a0_arr = vader_array_new(503u, 0u, 0u, 3020u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
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
    vader_obj_header_init(_a2_obj, 2125u);
    _a2_obj->f_type_id = l0;
    _a2_obj->f_fields = l4;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
