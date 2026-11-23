#include "bootstrap.split.h"

static vader_box_t vader_emit_c$address_as_integer(vader_box_t l0);
static void vader_emit_c$append_statement(void* l0, vader_box_t l1);
static vader_box_t vader_emit_c$argument(int64_t l0);
static int32_t vader_emit_c$array_element_tag(void* l0, int32_t l1);
static vader_box_t vader_emit_c$array_header_pointer(vader_box_t l0);
static vader_box_t vader_emit_c$array_pointer(vader_box_t l0);
static int32_t vader_emit_c$array_tag(void* l0, int32_t l1);
static vader_box_t vader_emit_c$as_buffer_type(vader_string_t l0, vader_box_t l1);
static vader_box_t vader_emit_c$as_count(vader_box_t l0);
static vader_box_t vader_emit_c$as_size(vader_box_t l0);
static void vader_emit_c$assert_stack_empty(void* l0, vader_string_t l1);
static void vader_emit_c$assign(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_emit_c$atom_count_define(void* l0);
static int32_t vader_emit_c$atom_for(void* l0, vader_string_t l1);
static void* vader_emit_c$atom_table_of(void* l0, void* l1);
static vader_string_t vader_emit_c$aux(void* l0, vader_string_t l1);
static int32_t vader_emit_c$baked_object_tag(void* l0, vader_box_t l1);
static void* vader_emit_c$bc_struct_fields(void* l0, int32_t l1);
static vader_string_t vader_emit_c$bc_struct_name(void* l0, int32_t l1);
static vader_box_t vader_emit_c$binary_expression(void* l0, uint8_t l1, uint8_t l2);
static vader_string_t vader_emit_c$bind_array_local(void* l0, vader_box_t l1);
static vader_box_t vader_emit_c$box_call(vader_string_t l0, int32_t l1, vader_box_t l2);
static vader_box_t vader_emit_c$box_expr(vader_box_t l0, uint8_t l1, int32_t l2);
static vader_box_t vader_emit_c$box_expr_unknown(void* l0, vader_box_t l1, uint8_t l2);
static vader_box_t vader_emit_c$box_slot(vader_string_t l0, vader_box_t l1);
static vader_box_t vader_emit_c$box_slot_1(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4);
static vader_box_t vader_emit_c$boxed_object(int32_t l0, vader_box_t l1);
static void* vader_emit_c$boxed_parameters(void* l0, int64_t l1);
static vader_string_t vader_emit_c$boxed_push_helper(vader_box_t l0);
static vader_box_t vader_emit_c$boxed_scalar(int32_t l0, uint8_t l1, uint64_t l2);
static vader_box_t vader_emit_c$boxed_string(int32_t l0, int32_t l1);
static vader_box_t vader_emit_c$branch_target(void* l0, int32_t l1);
static vader_box_t vader_emit_c$buffer_pointer(vader_box_t l0);
static void* vader_emit_c$build_string_atom_map(void* l0);
static vader_string_t vader_emit_c$c_field_name(void* l0);
static vader_string_t vader_emit_c$c_string_lit(vader_string_t l0);
static void* vader_emit_c$c_struct_layout_asserts(void* l0, void* l1);
static void* vader_emit_c$c_type_asserts(void* l0, void* l1);
static vader_string_t vader_emit_c$c_type_for(vader_box_t l0);
static vader_string_t vader_emit_c$c_type_for_array_kind(uint8_t l0);
static vader_string_t vader_emit_c$c_type_for_val_bare(uint8_t l0);
static int32_t vader_emit_c$callee_index_of(vader_box_t l0);
static int64_t vader_emit_c$callee_result_arity(void* l0, vader_box_t l1);
static int32_t vader_emit_c$class_index(void* l0, uint8_t l1);
static bool vader_emit_c$class_matches_type(void* l0, uint8_t l1, int32_t l2);
static int32_t vader_emit_c$class_tag_of(void* l0, uint8_t l1);
static void* vader_emit_c$classify_struct_fields(void* l0, void* l1, int64_t l2);
static void vader_emit_c$close_node(void* l0, vader_string_t l1);
static vader_box_t vader_emit_c$coerce_expr(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static vader_box_t vader_emit_c$coerce_operand(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static vader_box_t vader_emit_c$coerced_as(void* l0, vader_box_t l1, uint8_t l2);
static void* vader_emit_c$compute_atom_ids(void* l0, void* l1);
static void* vader_emit_c$compute_may_alloc(void* l0, void* l1);
static vader_box_t vader_emit_c$const_lit_c(void* l0, vader_box_t l1);
static uint8_t vader_emit_c$const_val(vader_box_t l0);
static uint8_t vader_emit_c$convert_target_val(uint8_t l0);
static void* vader_emit_c$current_block(void* l0);
static vader_box_t vader_emit_c$data_slot(uint8_t l0, uint64_t l1);
static void vader_emit_c$declare(void* l0, vader_string_t l1, vader_string_t l2, vader_box_t l3);
static vader_string_t vader_emit_c$declare_array(void* l0, vader_string_t l1, int32_t l2, vader_box_t l3);
static vader_box_t vader_emit_c$deep_copy_return(uint8_t l0);
static void* vader_emit_c$direct_callees(void* l0);
static void vader_emit_c$directive(void* l0, vader_string_t l1);
static vader_string_t vader_emit_c$dispatcher_name(vader_string_t l0);
static void* vader_emit_c$dispatcher_parameters(void* l0);
static vader_box_t vader_emit_c$dispatcher_result(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static void* vader_emit_c$dispatcher_signature(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_emit_c$div_mod_helper(uint8_t l0, uint8_t l1);
static void vader_emit_c$drop_bound_for_local(void* l0, int32_t l1);
static void vader_emit_c$drop_top(void* l0);
static uint8_t vader_emit_c$element_storage_kind(void* l0);
static void vader_emit_c$emit_agg_data_entry(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_emit_c$emit_array_clear(void* l0);
static void vader_emit_c$emit_array_copy(void* l0);
static void vader_emit_c$emit_array_get(void* l0, void* l1);
static void vader_emit_c$emit_array_len(void* l0);
static void vader_emit_c$emit_array_new(void* l0, void* l1);
static void vader_emit_c$emit_array_push(void* l0, void* l1);
static void vader_emit_c$emit_array_push_all(void* l0);
static void vader_emit_c$emit_array_remove_last(void* l0);
static void vader_emit_c$emit_array_repeat(void* l0);
static void vader_emit_c$emit_array_reserve(void* l0, void* l1);
static void vader_emit_c$emit_array_set(void* l0, void* l1);
static void vader_emit_c$emit_array_slice(void* l0, void* l1);
static void vader_emit_c$emit_atom_comptime_table(void* l0, void* l1);
static void vader_emit_c$emit_bits_to_f32(void* l0);
static void vader_emit_c$emit_bits_to_f64(void* l0);
static void vader_emit_c$emit_boxed_push(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3);
static void vader_emit_c$emit_branch(void* l0, int32_t l1, bool l2);
static void vader_emit_c$emit_buffer_load(void* l0, vader_string_t l1, uint8_t l2);
static void vader_emit_c$emit_buffer_new(void* l0);
static void vader_emit_c$emit_buffer_store(void* l0, vader_string_t l1, vader_string_t l2);
static void vader_emit_c$emit_buffer_to_string(void* l0);
static void vader_emit_c$emit_buffer_write_string(void* l0);
static void vader_emit_c$emit_call(void* l0, void* l1);
static void vader_emit_c$emit_call_import(void* l0, void* l1);
static void vader_emit_c$emit_call_indirect(void* l0, void* l1);
static void vader_emit_c$emit_call_result(void* l0, vader_box_t l1, uint8_t l2);
static void vader_emit_c$emit_call_to(void* l0, vader_string_t l1, void* l2);
static void vader_emit_c$emit_checked_arith(void* l0, void* l1);
static void vader_emit_c$emit_checked_neg(void* l0, void* l1);
static void vader_emit_c$emit_closure_forward_decls(void* l0, void* l1);
static void vader_emit_c$emit_closure_lift(void* l0, void* l1, int32_t l2);
static void vader_emit_c$emit_convert(void* l0, uint8_t l1, vader_string_t l2);
static void vader_emit_c$emit_data_const_op(void* l0, void* l1);
static void vader_emit_c$emit_data_global_externs(void* l0, void* l1);
static void vader_emit_c$emit_data_pool(void* l0, void* l1);
static vader_box_t vader_emit_c$emit_data_value(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4);
static void vader_emit_c$emit_defer_pop_exec(void* l0, void* l1);
static void vader_emit_c$emit_defer_push(void* l0);
static void vader_emit_c$emit_else(void* l0);
static void vader_emit_c$emit_end(void* l0, int32_t l1);
static void vader_emit_c$emit_f32_to_bits(void* l0);
static void vader_emit_c$emit_f64_to_bits(void* l0);
static void vader_emit_c$emit_fn_addr(void* l0, void* l1);
static void vader_emit_c$emit_fn_ref(void* l0, void* l1);
static void vader_emit_c$emit_fn_ref_tramp(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_emit_c$emit_fn_sig_typedefs(void* l0, void* l1);
static void vader_emit_c$emit_fn_trampolines(void* l0, void* l1);
static void vader_emit_c$emit_foreign_declarations(void* l0, void* l1, void* l2, void* l3);
static vader_string_t vader_emit_c$emit_foreign_unit(void* l0, vader_string_t l1);
static void vader_emit_c$emit_forward_decls(void* l0, void* l1);
static void vader_emit_c$emit_global_get(void* l0, void* l1);
static void vader_emit_c$emit_global_roots(void* l0, void* l1);
static void vader_emit_c$emit_global_set(void* l0, void* l1);
static void vader_emit_c$emit_global_slots(void* l0, void* l1);
static void vader_emit_c$emit_if_open(void* l0);
static void vader_emit_c$emit_import_group(void* l0, void* l1, void* l2);
static void vader_emit_c$emit_import_shims(void* l0, void* l1);
static void vader_emit_c$emit_internal_forward_decls(void* l0, void* l1, void* l2);
static void vader_emit_c$emit_local_decls(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5);
static void vader_emit_c$emit_local_field(void* l0, void* l1);
static void vader_emit_c$emit_local_get(void* l0, void* l1);
static void vader_emit_c$emit_local_set(void* l0, int32_t l1, bool l2);
static void vader_emit_c$emit_main(void* l0, void* l1, vader_string_t l2);
static void vader_emit_c$emit_make_closure(void* l0, void* l1);
static void vader_emit_c$emit_memory_copy(void* l0);
static void vader_emit_c$emit_mirrored_struct_typedefs(void* l0, void* l1, void* l2);
static void vader_emit_c$emit_multi_call(void* l0, vader_string_t l1, void* l2, void* l3);
static void vader_emit_c$emit_multi_return(void* l0);
static vader_box_t vader_emit_c$emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4);
static void vader_emit_c$emit_op(void* l0, int32_t l1, vader_box_t l2);
static void vader_emit_c$emit_open_scope(void* l0, int32_t l1, uint8_t l2);
static void vader_emit_c$emit_preamble(void* l0, vader_string_t l1);
static void vader_emit_c$emit_prim_data_entry(void* l0, void* l1, void* l2);
static void vader_emit_c$emit_ref_cast(void* l0, void* l1);
static void vader_emit_c$emit_retag_op(void* l0, void* l1);
static void vader_emit_c$emit_return(void* l0);
static void vader_emit_c$emit_return_lit(void* l0, vader_box_t l1);
static void vader_emit_c$emit_size_of_type(void* l0);
static vader_string_t vader_emit_c$emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3);
static void vader_emit_c$emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6);
static void vader_emit_c$emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_emit_c$emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_emit_c$emit_str_data_entry(void* l0, void* l1, void* l2, void* l3);
static void vader_emit_c$emit_string_compare(void* l0);
static void vader_emit_c$emit_struct_get(void* l0, void* l1);
static void vader_emit_c$emit_struct_new(void* l0, void* l1);
static void vader_emit_c$emit_struct_set(void* l0, void* l1);
static void vader_emit_c$emit_struct_typedefs(void* l0, void* l1);
static void vader_emit_c$emit_temporary_declarations(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5);
static void vader_emit_c$emit_type_check(void* l0, void* l1);
static void vader_emit_c$emit_type_const(void* l0, void* l1);
static void vader_emit_c$emit_type_info_table(void* l0, void* l1);
static void vader_emit_c$emit_typed_slot_write(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3, vader_string_t l4, uint8_t l5);
static void vader_emit_c$emit_union_field_get(void* l0, void* l1);
static void vader_emit_c$emit_union_field_set(void* l0, void* l1);
static void vader_emit_c$emit_virtual_call(void* l0, void* l1);
static void vader_emit_c$emit_vtable_dispatchers(void* l0, void* l1);
static void vader_emit_c$emit_vtable_forward_decls(void* l0, void* l1);
static void* vader_emit_c$empty_struct_offsets(void);
static bool vader_emit_c$entry_needs_materialise(vader_box_t l0, int32_t l1);
static void* vader_emit_c$erased_parameters(int64_t l0);
static vader_box_t vader_emit_c$erased_sibling_field_read(void* l0, int32_t l1, int32_t l2, uint8_t l3, vader_box_t l4);
static void* vader_emit_c$erased_wrapper_signature(void* l0, vader_string_t l1, int64_t l2);
static void vader_emit_c$evaluate(void* l0, vader_box_t l1);
static vader_box_t vader_emit_c$evaluated_void(void* l0, vader_box_t l1);
static vader_box_t vader_emit_c$expression_of(vader_box_t l0);
static vader_string_t vader_emit_c$extern_c_type(uint8_t l0);
static vader_box_t vader_emit_c$extern_decl(void* l0, void* l1);
static vader_string_t vader_emit_c$extern_parameter_type(void* l0, void* l1, int64_t l2);
static vader_string_t vader_emit_c$extern_result_type(void* l0, void* l1);
static vader_box_t vader_emit_c$external(vader_string_t l0, vader_string_t l1, vader_box_t l2, bool l3);
static vader_string_t vader_emit_c$field_c_name(vader_string_t l0);
static vader_box_t vader_emit_c$field_of(vader_string_t l0, vader_box_t l1, vader_string_t l2);
static bool vader_emit_c$fields_are_layout_siblings(void* l0, void* l1, void* l2);
static vader_box_t vader_emit_c$find_vtable_row(void* l0, vader_string_t l1);
static vader_string_t vader_emit_c$float_lit(double l0);
static vader_box_t vader_emit_c$float_tag_check_expr(void* l0, vader_box_t l1);
static bool vader_emit_c$fn_builds_stack_object(void* l0);
static vader_string_t vader_emit_c$fn_symbol_name(void* l0, int32_t l1);
static vader_string_t vader_emit_c$foreign_unit_banner(void* l0);
static void* vader_emit_c$foreign_units(void* l0);
static void* vader_emit_c$forward_boxed(void* l0, vader_string_t l1, void* l2, void* l3);
static void* vader_emit_c$forwarded_result(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_emit_c$fresh_slot(vader_string_t l0, int32_t l1);
static void* vader_emit_c$function_definition(void* l0, int32_t l1, void* l2);
static vader_box_t vader_emit_c$gc_allocation(vader_string_t l0);
static vader_box_t vader_emit_c$gc_statistic(vader_string_t l0);
static void* vader_emit_c$global_slot_addresses(void* l0, uint8_t l1);
static uint8_t vader_emit_c$global_slot_val(void* l0, int32_t l1);
static uint8_t vader_emit_c$global_storage(bool l0);
static bool vader_emit_c$has_str_data(void* l0);
static vader_string_t vader_emit_c$host_shim_name(void* l0);
static void* vader_emit_c$import_shim(void* l0, void* l1);
static vader_string_t vader_emit_c$imports_header_name(vader_string_t l0);
static void* vader_emit_c$imports_may_collect(void* l0);
static void* vader_emit_c$imports_of_unit(void* l0, vader_string_t l1);
static void* vader_emit_c$include_of(vader_string_t l0);
static void* vader_emit_c$including(vader_string_t l0);
static vader_box_t vader_emit_c$info_row(int64_t l0, void* l1);
static void vader_emit_c$init_object_header(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_emit_c$integer_as_address(vader_box_t l0);
static vader_box_t vader_emit_c$integer_payload(void* l0, vader_box_t l1);
static void* vader_emit_c$internal_fn_flags(void* l0, void* l1, vader_string_t l2);
static vader_box_t vader_emit_c$interned(vader_box_t l0);
static void vader_emit_c$invalidate_header_cache(void* l0, vader_box_t l1);
static bool vader_emit_c$is_abi_array(void* l0, int32_t l1);
static bool vader_emit_c$is_abi_nullable_pointer(void* l0, int32_t l1);
static bool vader_emit_c$is_abi_nullable_string(void* l0, int32_t l1);
static bool vader_emit_c$is_c_reserved(vader_string_t l0);
static bool vader_emit_c$is_cache_safe(vader_box_t l0);
static bool vader_emit_c$is_continue_branch(void* l0, int32_t l1);
static bool vader_emit_c$is_pure_read(vader_box_t l0);
static bool vader_emit_c$is_ref_val(uint8_t l0);
static bool vader_emit_c$is_scope_opening(vader_box_t l0);
static bool vader_emit_c$is_tail_forwarder(void* l0, void* l1);
static int64_t vader_emit_c$leading_pure_reads(void* l0);
static vader_box_t vader_emit_c$left_operand(void* l0, uint8_t l1, vader_box_t l2, vader_box_t l3, uint8_t l4);
static void* vader_emit_c$library_open_shim(vader_string_t l0, vader_box_t l1);
static vader_string_t vader_emit_c$library_unit_name(vader_string_t l0);
static void* vader_emit_c$lift_signature(void* l0, vader_string_t l1, void* l2);
static void* vader_emit_c$lift_unbox_tail(void* l0);
static bool vader_emit_c$literal_within(vader_box_t l0, int64_t l1);
static void* vader_emit_c$main_body(void* l0, vader_string_t l1);
static vader_box_t vader_emit_c$materialise_entry(void* l0, vader_box_t l1);
static void vader_emit_c$materialize_stack_for_slot(void* l0, int32_t l1);
static int64_t vader_emit_c$max_fn_arity(void* l0);
static bool vader_emit_c$may_hold_reference(vader_box_t l0);
static void* vader_emit_c$mirror_crossings(void* l0, void* l1);
static void* vader_emit_c$mirror_result(void* l0, int32_t l1, vader_string_t l2, vader_box_t l3);
static vader_string_t vader_emit_c$mirrored_c_struct(void* l0, int32_t l1);
static uint8_t vader_emit_c$module_function_storage(void* l0, int32_t l1);
static vader_box_t vader_emit_c$monitor_give(uint8_t l0);
static vader_box_t vader_emit_c$monitor_take_alone(void);
static bool vader_emit_c$needs_frame(void* l0, int32_t l1, void* l2);
static void* vader_emit_c$new_ctx(void* l0, void* l1, void* l2);
static void* vader_emit_c$new_fn_state(void* l0, int32_t l1, void* l2);
static void* vader_emit_c$new_temporary(void* l0, uint8_t l1);
static vader_box_t vader_emit_c$null_member(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_emit_c$null_or(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_emit_c$object_header(vader_box_t l0);
static vader_box_t vader_emit_c$object_pointer(vader_box_t l0, uint8_t l1);
static vader_box_t vader_emit_c$object_pointer_of(vader_box_t l0);
static vader_box_t vader_emit_c$one_variant_check(void* l0, vader_box_t l1, int32_t l2);
static void vader_emit_c$open_else(void* l0);
static void vader_emit_c$open_if(void* l0, vader_box_t l1);
static void vader_emit_c$open_node(void* l0, vader_box_t l1);
static void vader_emit_c$open_scope(void* l0, vader_string_t l1);
static vader_box_t vader_emit_c$operand_as(void* l0, vader_box_t l1, uint8_t l2);
static vader_string_t vader_emit_c$out_param_name(int64_t l0);
static void* vader_emit_c$partition_functions(void* l0);
static vader_box_t vader_emit_c$payload(vader_box_t l0, vader_string_t l1);
static vader_box_t vader_emit_c$payload_cast(vader_string_t l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_emit_c$pc_active_for(void* l0, int32_t l1);
static vader_box_t vader_emit_c$pc_capacity(int32_t l0);
static void vader_emit_c$pc_close_cache(void* l0, int32_t l1);
static void vader_emit_c$pc_emit_preheader(void* l0, void* l1);
static void vader_emit_c$pc_emit_push(void* l0, void* l1, vader_box_t l2, vader_box_t l3);
static void vader_emit_c$pc_emit_writeback(void* l0, int32_t l1);
static void* vader_emit_c$pc_fill_of(uint8_t l0);
static vader_box_t vader_emit_c$pc_header(int32_t l0, vader_string_t l1);
static vader_string_t vader_emit_c$pc_helper_of(uint8_t l0);
static bool vader_emit_c$pc_liftable_kind(uint8_t l0);
static vader_box_t vader_emit_c$pc_local(int32_t l0, vader_string_t l1);
static bool vader_emit_c$pc_operand_is_slot(vader_box_t l0, int32_t l1);
static void vader_emit_c$pc_plan_for_loop(void* l0, int32_t l1, int32_t* __o0, int32_t* __o1, int32_t* __o2, uint8_t* __o3);
static void vader_emit_c$pc_reload(void* l0, int32_t l1);
static bool vader_emit_c$pc_slot_used_outside_push(void* l0, int32_t l1, int32_t l2, int32_t l3, int32_t l4);
static vader_box_t vader_emit_c$pointee_signedness(vader_string_t l0, uint8_t l1);
static vader_string_t vader_emit_c$pointer_to(vader_string_t l0, bool l1);
static vader_box_t vader_emit_c$pop(void* l0);
static void* vader_emit_c$pop_args_boxed(void* l0, int32_t l1);
static void* vader_emit_c$pop_erased_args(void* l0, void* l1, void* l2);
static void* vader_emit_c$precompute_branch_targets(void* l0, void* l1);
static void* vader_emit_c$precompute_scopes(void* l0);
static int32_t vader_emit_c$present_tag(void* l0, uint8_t l1);
static void* vader_emit_c$publish(uint8_t l0);
static void vader_emit_c$push_binop(void* l0, uint8_t l1, uint8_t l2);
static void vader_emit_c$push_binop_any(void* l0, uint8_t l1, uint8_t l2);
static void vader_emit_c$push_c_type_assert(vader_string_t l0, uint8_t l1, void* l2, void* l3);
static void vader_emit_c$push_cmp(void* l0, uint8_t l1, uint8_t l2);
static void vader_emit_c$push_const(void* l0, vader_box_t l1);
static void vader_emit_c$push_eager(void* l0, uint8_t l1, uint8_t l2);
static void vader_emit_c$push_expr(void* l0, uint8_t l1, vader_box_t l2);
static void vader_emit_c$push_foreign_units(void* l0, void* l1, void* l2);
static vader_box_t vader_emit_c$push_helper_for(uint8_t l0);
static void vader_emit_c$push_i64_neg(void* l0);
static void vader_emit_c$push_into_temporary(void* l0, vader_box_t l1, uint8_t l2);
static void vader_emit_c$push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7);
static void vader_emit_c$push_lit(void* l0, uint8_t l1, vader_box_t l2);
static void vader_emit_c$push_local_ref(void* l0, int32_t l1, uint8_t l2);
static void vader_emit_c$push_member_copies(void* l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4, void* l5, int32_t l6);
static vader_string_t vader_emit_c$push_mirror_allocation(void* l0, int32_t l1, void* l2, void* l3, void* l4, int32_t l5);
static void vader_emit_c$push_object(void* l0, vader_box_t l1);
static void vader_emit_c$push_offset_list(void* l0, vader_string_t l1, void* l2);
static void vader_emit_c$push_pointee_assert(vader_string_t l0, uint8_t l1, void* l2, void* l3);
static void vader_emit_c$push_pool_array(void* l0, void* l1, vader_string_t l2, uint8_t l3, void* l4);
static void vader_emit_c$push_shift(void* l0, uint8_t l1, uint8_t l2);
static void vader_emit_c$push_struct_field(void* l0, int32_t l1, int32_t l2, vader_box_t l3, uint8_t l4);
static void vader_emit_c$push_temporary(void* l0, void* l1, uint8_t l2);
static void vader_emit_c$push_unop(void* l0, vader_string_t l1, uint8_t l2);
static void vader_emit_c$push_width_assert(vader_string_t l0, vader_string_t l1, vader_box_t l2, vader_string_t l3, void* l4, void* l5);
static vader_box_t vader_emit_c$read_back(void* l0, vader_box_t l1);
static bool vader_emit_c$reboxes_to_own_tag(void* l0, int32_t l1, uint8_t l2);
static vader_box_t vader_emit_c$ref_box(vader_box_t l0);
static bool vader_emit_c$ref_carrying_element(vader_box_t l0, void* l1);
static void* vader_emit_c$relay_declarations(void* l0, void* l1);
static vader_string_t vader_emit_c$relay_frame_name(void* l0);
static vader_string_t vader_emit_c$relay_runner_name(void* l0);
static vader_box_t vader_emit_c$renamed_argument(void* l0, int64_t l1, vader_box_t l2);
static void vader_emit_c$return_statement(void* l0, void* l1);
static bool vader_emit_c$returns_at(void* l0, int64_t l1);
static vader_box_t vader_emit_c$root_list(void* l0, vader_string_t l1, vader_string_t l2, void* l3);
static vader_box_t vader_emit_c$safepoint_result_arity(void* l0, vader_box_t l1, int64_t l2);
static vader_string_t vader_emit_c$sanitise(vader_string_t l0);
static vader_box_t vader_emit_c$scalar_cast(vader_box_t l0, uint8_t l1, uint8_t l2);
static int32_t vader_emit_c$scalar_tag(void* l0, uint8_t l1);
static void* vader_emit_c$scan_fn_value_usage(void* l0);
static vader_box_t vader_emit_c$scope_ending_at(void* l0, int32_t l1);
static vader_box_t vader_emit_c$scope_ending_for_opener(void* l0, int32_t l1);
static int64_t vader_emit_c$shift_count_mask(uint8_t l0);
static void* vader_emit_c$shim_body(void* l0, void* l1);
static void* vader_emit_c$shim_signature(void* l0, void* l1);
static void* vader_emit_c$signature_for(void* l0, int32_t l1);
static bool vader_emit_c$signed_under_unsigned(uint8_t l0, uint8_t l1);
static vader_box_t vader_emit_c$signed_view(vader_box_t l0, uint8_t l1, vader_string_t l2);
static vader_box_t vader_emit_c$signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3);
static vader_box_t vader_emit_c$single_offset_list(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_emit_c$single_reference_row(int64_t l0, vader_string_t l1, vader_string_t l2, int32_t l3, vader_string_t l4, void* l5);
static vader_box_t vader_emit_c$slot_index(vader_string_t l0, vader_box_t l1);
static void* vader_emit_c$sorted_fn_indices(void* l0);
static void* vader_emit_c$sorted_module_stems(void* l0);
static uint8_t vader_emit_c$source_class(uint8_t l0, uint8_t l1, vader_string_t l2);
static vader_box_t vader_emit_c$spilled_address(void* l0, int64_t l1);
static vader_string_t vader_emit_c$spilled_c_type(void* l0, int64_t l1);
static uint8_t vader_emit_c$stack_class_of(uint8_t l0);
static void vader_emit_c$statement_macro(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_emit_c$static_assert(vader_box_t l0, vader_string_t l1);
static void vader_emit_c$store_field(void* l0, vader_box_t l1, vader_box_t l2, int32_t l3, vader_box_t l4);
static int32_t vader_emit_c$string_array_tag(void* l0, int32_t l1);
static int32_t vader_emit_c$string_primitive_tag(void* l0);
static vader_string_t vader_emit_c$struct_c_name(vader_string_t l0);
static void* vader_emit_c$struct_c_names_of(void* l0);
static void* vader_emit_c$struct_definition(void* l0, void* l1, void* l2, int64_t l3);
static vader_box_t vader_emit_c$struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static vader_box_t vader_emit_c$struct_info_row(void* l0, void* l1, void* l2, int64_t l3);
static vader_box_t vader_emit_c$struct_set_barrier(void* l0, vader_string_t l1, vader_box_t l2);
static bool vader_emit_c$synthesises_prototype(void* l0);
static vader_box_t vader_emit_c$tag_equals(vader_box_t l0, int32_t l1);
static vader_box_t vader_emit_c$tag_expression(vader_box_t l0, uint8_t l1);
static vader_box_t vader_emit_c$tag_of(vader_box_t l0);
static vader_box_t vader_emit_c$trait_check_expr(void* l0, vader_box_t l1, vader_string_t l2, int32_t l3);
static void* vader_emit_c$tramp_unbox_args(void* l0);
static void* vader_emit_c$trampoline_signature(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_emit_c$trap(vader_string_t l0);
static int32_t vader_emit_c$type_id_for_struct_symbol(void* l0, int32_t l1);
static vader_box_t vader_emit_c$typed_array_fill_for(uint8_t l0);
static vader_box_t vader_emit_c$typed_slot(vader_string_t l0, vader_string_t l1, vader_box_t l2);
static vader_box_t vader_emit_c$unbox_expr(vader_box_t l0, uint8_t l1);
static void* vader_emit_c$union_field_place(void* l0, int32_t l1, int32_t l2, vader_box_t l3);
static void* vader_emit_c$unit_names_of(void* l0, void* l1);
static void vader_emit_c$unreachable(void* l0, vader_string_t l1);
static void* vader_emit_c$user_extern_shim(void* l0, void* l1);
static uint8_t vader_emit_c$val_of(vader_box_t l0);
static uint8_t vader_emit_c$val_type_of_bc_type(vader_box_t l0);
static uint8_t vader_emit_c$val_type_of_field(void* l0, int32_t l1);
static void* vader_emit_c$value_parameters(void* l0, vader_string_t l1);
static vader_box_t vader_emit_c$void_box(void* l0);
static void* vader_emit_c$vtable_sig_for_row(void* l0, void* l1);
static uint8_t vader_emit_c$wrapper_storage(bool l0);
static void vader_emit_c$write_barrier(void* l0, vader_box_t l1);
static void vader_emit_c$write_barrier_for(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_emit_c$zero_of(uint8_t l0);

static vader_box_t vader_emit_c$address_as_integer(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c_ast$cast(2749u, l0);
    t0 = vader_emit_c_ast$cast(2731u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$append_statement(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$current_block(l0);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) t0)->f_body, l1.payload.obj);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$argument(int64_t l0) {
    void* l1 = NULL;
    int64_t l2;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 1793u);
    l2 = std_core$write_int(l1, l2, l0);
    t0 = std_core$finish_buffer(l1, l2);
    t1 = vader_emit_c_ast$verbatim(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$array_element_tag(void* l0, int32_t l1) {
    vader_box_t l2;
    void* t0;
    int32_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l2.tag == 1273u)) {
        return l1;
    }
    t0 = l2.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
    return t1;
}

static vader_box_t vader_emit_c$array_header_pointer(vader_box_t l0) {
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &t0, &t1 };
    void** gc_raw_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$object_pointer_of(l0);
    t1 = vader_emit_c$array_pointer(t0);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1600u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$array_pointer(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_emit_c_ast$cast(3548u, l0);
    return t0;
}

static int32_t vader_emit_c$array_tag(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        if (l4.tag == 1273u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

static vader_box_t vader_emit_c$as_buffer_type(vader_string_t l0, vader_box_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0 == 2287u)) {
        t0 = vader_emit_c_ast$cast(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$as_count(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    t0 = vader_emit_c_ast$cast(2731u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$as_size(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    t0 = vader_emit_c_ast$cast(3185u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$assert_stack_empty(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    int64_t l4, l5;
    void* l6 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    if (!(t0 != INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l1;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
    l4 = vader_host_std_core$Intrinsic$byte_len(l2);
    l5 = vader_host_std_core$Intrinsic$byte_len(l3);
    l4 = (l4 + l5);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(156) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l6, l4, 2174u);
    l4 = std_core$write_string_at(l6, l4, l2);
    l4 = std_core$write_string_at(l6, l4, 188u);
    l4 = std_core$write_string_at(l6, l4, l3);
    l4 = std_core$write_string_at(l6, l4, 1316u);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    l4 = std_core$write_int(l6, l4, l5);
    l4 = std_core$write_string_at(l6, l4, 426u);
    t1 = std_core$finish_buffer(l6, l4);
    vader_host_std_core$Intrinsic$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_c$assign(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CAssign_t* _a0_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
    vader_obj_header_init(_a0_obj, 1566u);
    _a0_obj->f_target = l1;
    _a0_obj->f_value = l2;
    _a0_obj->f_operator = vader_box_obj(0u, NULL);
    l3 = (void*) _a0_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$atom_count_define(void* l0) {
    vader_box_t l1 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    l1 = vader_emit_c_ast$unsigned(t0);
    vader_struct_vader_emit_c_ast$CDefine_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDefine_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDefine_t));
    vader_obj_header_init(_a0_obj, 1579u);
    _a0_obj->f_name = 1172u;
    _a0_obj->f_value = l1;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$atom_for(void* l0, vader_string_t l1) {
    vader_box_t l2;
    int32_t t0;
    l2 = std_collections$Map$std_core$Index$at__string__i32(l0, l1);
    if (!(l2.tag == 626u)) {
        return INT32_C(0);
    }
    t0 = ((int32_t) l2.payload.i);
    return t0;
}

static void* vader_emit_c$atom_table_of(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l1));
    if (t0 != INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l3];
        t2 = t1.payload.s;
        if (t2 != 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l3];
            l5 = t1.payload.s;
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l5));
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$aux(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    int32_t l3;
    int64_t l4, l6;
    void* l5 = NULL;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_aux_counter;
    l2 = l1;
    l4 = vader_host_std_core$Intrinsic$byte_len(l2);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(23) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l5, l4, 1289u);
    l6 = ((int64_t) (int32_t) l3);
    l4 = std_core$write_int(l5, l4, l6);
    l4 = std_core$write_string_at(l5, l4, 1245u);
    l4 = std_core$write_string_at(l5, l4, l2);
    l2 = std_core$finish_buffer(l5, l4);
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_aux_counter;
    l3 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_emit_c$FnState_t*) l0)->f_aux_counter = l3;
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$baked_object_tag(void* l0, vader_box_t l1) {
    int32_t l2;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1288u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        t1 = vader_emit_c$type_id_for_struct_symbol(l0, l2);
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$bc_struct_fields(void* l0, int32_t l1) {
    bool l2;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        l3 = ((int64_t) (int32_t) l1);
        l4 = vader_array_length(((vader_array_t*) l0));
        l2 = (l3 >= l4);
    }
    if (l2) {
        vader_array_t* _a0_arr = vader_array_new(112u, 0u, 13u, 1275u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    if (!(l5.tag == 1286u)) {
        vader_array_t* _a2_arr = vader_array_new(112u, 0u, 13u, 1275u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    { void* __vret = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$bc_struct_name(void* l0, int32_t l1) {
    bool l2;
    int64_t l3, l4;
    vader_box_t l5;
    void* t0;
    vader_string_t t1;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        l3 = ((int64_t) (int32_t) l1);
        l4 = vader_array_length(((vader_array_t*) l0));
        l2 = (l3 >= l4);
    }
    if (l2) {
        return 0u;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l5.tag == 1286u)) {
        return 0u;
    }
    t0 = l5.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
    return t1;
}

static vader_box_t vader_emit_c$binary_expression(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$left_operand(l0, l1, l4, l3, l2);
    l3 = vader_emit_c$operand_as(l0, l3, l2);
    l3 = vader_emit_c_ast$binary(l1, l4, l3);
    if (l1 == INT32_C(11)) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == INT32_C(12))) {
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a0_obj, 1600u);
        _a0_obj->f_inner = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$bind_array_local(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        t0 = vader_emit_c_ast$same_expression(((vader_struct_vader_emit_c$BoundArray_t*) l5)->f_pointer, l1);
        if (t0) {
            t1 = ((vader_struct_vader_emit_c$BoundArray_t*) l5)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = (l4 + INT64_C(1));
    }
    l6 = vader_emit_c$aux(l0, 3192u);
    vader_emit_c$declare(l0, 3548u, l6, l1);
    t2 = vader_emit_c_ast$verbatim(l6);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t2.payload.obj;
    l2 = (void*) _a1_arr;
    vader_emit_c$statement_macro(l0, 1168u, l2);
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays;
    vader_struct_vader_emit_c$BoundArray_t* _a2_obj = (vader_struct_vader_emit_c$BoundArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$BoundArray_t));
    vader_obj_header_init(_a2_obj, 1545u);
    _a2_obj->f_name = l6;
    _a2_obj->f_pointer = l1;
    l5 = (void*) _a2_obj;
    vader_array_push_ref((vader_array_t*) l2, l5);
    { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$box_call(vader_string_t l0, int32_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(3555u, l0);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l5 = INT64_C(0);
    l6 = ((int64_t) (int32_t) l1);
    l5 = std_core$write_int(l4, l5, l6);
    l5 = std_core$write_string_at(l4, l5, 3423u);
    t0 = std_core$finish_buffer(l4, l5);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l4 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$call(l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$box_expr(vader_box_t l0, uint8_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    bool l4;
    void* l5 = NULL;
    int64_t l7, l8;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l3, &l6 };
    void** gc_raw_roots[2] = { &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(0)) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(1);
    }
    if (l4) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(2);
    }
    if (l4) {
        l3 = vader_emit_c$box_call(2635u, l2, l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(4)) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(5);
    }
    if (l4) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(6);
    }
    if (l4) {
        vader_array_t* _a0_arr = vader_array_new(28u, 2u, 0u, 623u);
        vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(623u, 3451u);
        vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(623u, 2730u);
        t0 = (void*) _a0_arr;
        vader_struct_vader_emit_c_ast$CCast_t* _a1_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
        vader_obj_header_init(_a1_obj, 1572u);
        _a1_obj->f_types = t0;
        _a1_obj->f_value = l0;
        l5 = (void*) _a1_obj;
        l3 = vader_emit_c$box_call(2635u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(3)) {
        l3 = vader_emit_c$box_call(2657u, l2, l0);
    } else if (l1 == INT32_C(7)) {
        vader_array_t* _a2_arr = vader_array_new(28u, 2u, 0u, 623u);
        vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 1u] = vader_box_string(623u, 3452u);
        vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_box_string(623u, 2731u);
        t0 = (void*) _a2_arr;
        vader_struct_vader_emit_c_ast$CCast_t* _a3_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
        vader_obj_header_init(_a3_obj, 1572u);
        _a3_obj->f_types = t0;
        _a3_obj->f_value = l0;
        l5 = (void*) _a3_obj;
        l3 = vader_emit_c$box_call(2657u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(8)) {
        l6 = vader_emit_c_ast$cast(2352u, l0);
        l3 = vader_emit_c$box_call(2485u, l2, l6);
    } else if (l1 == INT32_C(9)) {
        l3 = vader_emit_c$box_call(2485u, l2, l0);
    } else if (l1 == INT32_C(10)) {
        l3 = vader_emit_c$box_call(2091u, l2, l0);
    } else if (l1 == INT32_C(11)) {
        l6 = vader_emit_c_ast$cast(2730u, l0);
        l3 = vader_emit_c$box_call(2635u, l2, l6);
    } else if (l1 == INT32_C(12)) {
        l3 = vader_emit_c$box_call(3236u, l2, l0);
    } else {
        if (l1 == INT32_C(13)) {
            l4 = true;
        } else {
            l4 = l1 == INT32_C(17);
        }
        if (l4) {
            l3 = l0;
        } else if (l1 == INT32_C(14)) {
            l5 = (void*) vader_buffer_new((size_t) INT64_C(42));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l5, l7, 3559u);
            l8 = ((int64_t) (int32_t) l2);
            l7 = std_core$write_int(l5, l7, l8);
            l7 = std_core$write_string_at(l5, l7, 3426u);
            t1 = std_core$finish_buffer(l5, l7);
            l3 = vader_emit_c_ast$verbatim(t1);
        } else if (l1 == INT32_C(15)) {
            l6 = vader_emit_c_ast$cast(2749u, l0);
            l6 = vader_emit_c_ast$cast(2731u, l6);
            l3 = vader_emit_c$box_call(2657u, l2, l6);
        } else {
            if (!(l1 == INT32_C(16))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l3 = vader_emit_c$ref_box(l0);
        }
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$box_expr_unknown(void* l0, vader_box_t l1, uint8_t l2) {
    int32_t l3;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$class_tag_of(l0, l2);
    t0 = vader_emit_c$box_expr(l1, l2, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$box_slot(vader_string_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 485u);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$call(3514u, l2);
    vader_struct_vader_emit_c_ast$CIndex_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a1_obj, 1591u);
    _a1_obj->f_base = t1;
    _a1_obj->f_index = l1;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$box_slot_1(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4) {
    void* l5 = NULL;
    int32_t l6, l8;
    vader_string_t l7 = 0;
    uint8_t l9;
    uint64_t l10;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l11, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    if (l2.tag == 1290u) {
        l6 = vader_emit_c$class_tag_of(l5, (uint8_t) 12);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        l8 = vader_emit_c$atom_for(l4, l7);
        t1 = vader_emit_c$boxed_string(l6, l8);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1289u)) {
        l11 = l2;
        l8 = vader_emit_c$baked_object_tag(l5, l11);
        l11 = l2;
        l11 = vader_emit_c$emit_data_value(l0, l1, l11, l3, l4);
        t1 = vader_emit_c$boxed_object(l8, l11);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l9 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
    l6 = vader_emit_c$scalar_tag(l5, l9);
    t0 = l2.payload.obj;
    l9 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
    t0 = l2.payload.obj;
    l10 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
    t1 = vader_emit_c$boxed_scalar(l6, l9, l10);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$boxed_object(int32_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t1 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_69;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_c_ast$cast(3701u, l1);
    t1 = vader_emit_c_ast$designated(521u, l4);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l2.payload.obj;
    t0 = (void*) _a2_arr;
    t1 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$boxed_parameters(void* l0, int64_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l3, l5;
    vader_string_t l6 = 0;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(272u, 1u, 13u, 1599u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0;
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1793u);
        l5 = std_core$write_int(l4, l5, l3);
        l6 = std_core$finish_buffer(l4, l5);
        vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a1_obj, 1599u);
        _a1_obj->f_type = 3560u;
        _a1_obj->f_name = l6;
        l7 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l2, l7);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$boxed_push_helper(vader_box_t l0) {
    bool t0;
    t0 = vader_emit_c$may_hold_reference(l0);
    if (t0) {
        return 3523u;
    }
    return 3533u;
}

static vader_box_t vader_emit_c$boxed_scalar(int32_t l0, uint8_t l1, uint64_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool l5;
    vader_string_t l6 = 0;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t2 };
    void** gc_raw_roots[2] = { &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$data_slot(l1, l2);
    if (l1 == INT32_C(9)) {
        l5 = true;
    } else {
        l5 = l1 == INT32_C(10);
    }
    if (l5) {
        l4 = vader_emit_c_ast$cast(2352u, l3);
        l4 = vader_emit_c_ast$designated(511u, l4);
    } else if (l1 == INT32_C(12)) {
        l4 = vader_emit_c_ast$designated(502u, l3);
    } else {
        if (l1 == INT32_C(1)) {
            l5 = true;
        } else {
            l5 = l1 == INT32_C(2);
        }
        if (l5) {
            l5 = true;
        } else {
            l5 = l1 == INT32_C(3);
        }
        if (l5) {
            vader_array_t* _a0_arr = vader_array_new(28u, 3u, 0u, 623u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 2u] = vader_box_string(623u, 3451u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(623u, 2730u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(623u, 2731u);
            t0 = (void*) _a0_arr;
            l4 = vader_emit_c$integer_payload(t0, l3);
        } else {
            if (l1 == INT32_C(5)) {
                l5 = true;
            } else {
                l5 = l1 == INT32_C(6);
            }
            if (l5) {
                l5 = true;
            } else {
                l5 = l1 == INT32_C(7);
            }
            if (l5) {
                l5 = true;
            } else {
                l5 = l1 == INT32_C(11);
            }
            if (l5) {
                vader_array_t* _a1_arr = vader_array_new(28u, 2u, 0u, 623u);
                vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 1u] = vader_box_string(623u, 2730u);
                vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 0u] = vader_box_string(623u, 2731u);
                t0 = (void*) _a1_arr;
                l4 = vader_emit_c$integer_payload(t0, l3);
            } else {
                if (l1 == INT32_C(8)) {
                    l5 = true;
                } else {
                    l5 = l1 == INT32_C(4);
                }
                if (l5) {
                    vader_array_t* _a2_arr = vader_array_new(28u, 1u, 0u, 623u);
                    vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_box_string(623u, 2731u);
                    t0 = (void*) _a2_arr;
                    l4 = vader_emit_c$integer_payload(t0, l3);
                } else {
                    if (l1 == INT32_C(13)) {
                        l5 = true;
                    } else {
                        l5 = l1 == INT32_C(0);
                    }
                    if (!(l5)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l6 = vader_core_bytecode$array_kind_name(l1);
                    t1 = concat_3(2170u, l6, 1310u);
                    vader_host_std_core$Intrinsic$panic(t1);
                    vader_unreachable("a no-return call returned");
                }
            }
        }
    }
    l3 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_69;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l4.payload.obj;
    t0 = (void*) _a4_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a5_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 2u] = l4.payload.obj;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l7;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = l3.payload.obj;
    t0 = (void*) _a5_arr;
    t2 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$boxed_string(int32_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_69;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l1));
    t1 = vader_emit_c_ast$designated(525u, l4);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l2.payload.obj;
    t0 = (void*) _a2_arr;
    t1 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$branch_target(void* l0, int32_t l1) {
    int64_t l2, l3;
    void* t0;
    bool t1;
    int32_t t2, t3;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        t1 = vader_emit_c$is_continue_branch(t0, l1);
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
            return vader_ref_box(t0);
        }
        l2 = (l2 + INT64_C(1));
    }
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
        t2 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_end_pc;
        t3 = vader_chk_add(i32, t2, INT32_C(1));
        if (t3 == l1) {
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
            return vader_ref_box(t0);
        }
        l2 = (l2 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_c$buffer_pointer(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$object_pointer_of(l0);
    t0 = vader_emit_c_ast$cast(3573u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$build_string_atom_map(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    int32_t l7;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__i32_t* _a3_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a3_obj, 977u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_strings;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l2));
    while ((l4 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l4];
        l6 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_ids);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
        l7 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l4];
        std_collections$Map$std_core$IndexSet$set_at__string__i32(l1, l6, l7);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$c_field_name(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l0)->f_name;
    return t0;
}

static vader_string_t vader_emit_c$c_string_lit(vader_string_t l0) {
    int64_t l1, l3, l8;
    void* l2 = NULL;
    uint8_t l4, l6, l7;
    bool l5;
    uint32_t t0;
    int32_t t1;
    uint8_t t2;
    bool t3;
    vader_string_t t4 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core$Intrinsic$byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(31u, 0u, 1u, 628u);
    l2 = (void*) _a0_arr;
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        l4 = vader_host_std_core$Intrinsic$byte_at(l0, l3);
        if (l4 == INT32_C(92)) {
            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
        } else if (l4 == INT32_C(34)) {
            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
            vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
        } else if (l4 == INT32_C(10)) {
            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
            vader_array_push_u8((vader_array_t*) l2, INT32_C(110));
        } else if (l4 == INT32_C(13)) {
            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
            vader_array_push_u8((vader_array_t*) l2, INT32_C(114));
        } else if (l4 == INT32_C(9)) {
            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
            vader_array_push_u8((vader_array_t*) l2, INT32_C(116));
        } else {
            if ((l4 < INT32_C(32))) {
                l5 = true;
            } else {
                l5 = (l4 >= INT32_C(127));
            }
            if (l5) {
                vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
                vader_array_push_u8((vader_array_t*) l2, INT32_C(120));
                t0 = std_numbers$hex_digit(((uint64_t) (int64_t) ((int64_t) (uint8_t) l4) >> INT64_C(4)));
                t1 = (((int32_t) (uint32_t) t0) & INT32_C(255));
                l6 = (uint8_t) (int32_t) t1;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l6);
                t0 = std_numbers$hex_digit((uint64_t) (int64_t) (((int64_t) (uint8_t) l4) & INT64_C(15)));
                t1 = (((int32_t) (uint32_t) t0) & INT32_C(255));
                l7 = (uint8_t) (int32_t) t1;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l7);
                l8 = vader_chk_add(i64, l3, INT64_C(1));
                if ((l8 < l1)) {
                    t2 = vader_host_std_core$Intrinsic$byte_at(l0, l8);
                    t3 = std_numbers$is_hex_digit(((uint32_t) (int32_t) ((int32_t) (uint8_t) t2)));
                    if (t3) {
                        vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
                        vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
                    }
                }
            } else {
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    t4 = vader_host_std_core$Intrinsic$bytes_to_string(l2);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$c_struct_layout_asserts(void* l0, void* l1) {
    void* l2 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l27 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l26 = vader_box_null();
    bool l6, l8, l22;
    int32_t l7, l9;
    vader_string_t l10 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    vader_string_t l25 = 0;
    vader_string_t l28 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[12] = {
        &l5, &l13, &l14, &l15, &l17, &l18, &l19, &l21, &l23, &l24, &l26, &t3,
    };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l11, &l12, &l27, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l10, &l16, &l20, &l25, &l28, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 12u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        if (l5.tag == 1286u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            if (t1 == 0u) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            t0 = l5.payload.obj;
            t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields));
            if (t2 == INT64_C(0)) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            l7 = ((int32_t) (int64_t) l3);
            l6 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct_vader_emit_c$MirrorCrossings_t*) l1)->f_lent, l7);
            l9 = ((int32_t) (int64_t) l3);
            l8 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct_vader_emit_c$MirrorCrossings_t*) l1)->f_copied, l9);
            if (!(l6)) {
                if (!(l8)) {
                    l3 = (l3 + INT64_C(1));
                    continue;
                }
            }
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
            l10 = vader_emit_c$struct_c_name(t1);
            t0 = l5.payload.obj;
            l11 = vader_core_bytecode$c_struct_layout(((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields, l0);
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            t3 = vader_emit_c_ast$verbatim(t1);
            vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
            ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t3.payload.obj;
            l12 = (void*) _a2_arr;
            l13 = vader_emit_c_ast$call(3186u, l12);
            if (l8) {
                t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l11)->f_size;
                l14 = vader_emit_c_ast$number(t2);
                l15 = vader_emit_c_ast$binary((uint8_t) 11, l14, l13);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l16 = concat_2(t1, 204u);
                l17 = vader_emit_c$static_assert(l15, l16);
                vader_array_push_ref((vader_array_t*) l2, l17.payload.obj);
            } else {
                t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l11)->f_size;
                l18 = vader_emit_c_ast$number(t2);
                l19 = vader_emit_c_ast$binary((uint8_t) 8, l18, l13);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l20 = concat_2(t1, 257u);
                l21 = vader_emit_c$static_assert(l19, l20);
                vader_array_push_ref((vader_array_t*) l2, l21.payload.obj);
            }
            if (l6) {
                l22 = true;
            } else {
                l22 = !(l8);
            }
            if (l22) {
                l23 = vader_emit_c_ast$number(INT64_C(4096));
                l24 = vader_emit_c_ast$binary((uint8_t) 8, l13, l23);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l25 = concat_2(t1, 162u);
                l26 = vader_emit_c$static_assert(l24, l25);
                vader_array_push_ref((vader_array_t*) l2, l26.payload.obj);
            }
            t0 = l5.payload.obj;
            l27 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
            t0 = l5.payload.obj;
            l28 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            vader_emit_c$push_leaf_asserts(l0, l27, l28, 0u, l10, INT64_C(0), l2, INT32_C(0));
            l3 = (l3 + INT64_C(1));
            continue;
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$c_type_asserts(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6, l9, l10;
    vader_string_t l11 = 0;
    vader_string_t l18 = 0;
    vader_box_t l12 = vader_box_null(), l19 = vader_box_null();
    int32_t l13, l14, l15;
    uint8_t l16, l17, l20;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l12, &l19, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    l3 = (void*) _a1_arr;
    l4 = l0;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature;
        l9 = INT64_C(0);
        l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_params));
        while ((l9 < l10)) {
            l12 = vader_core_bytecode$param_c_type(l7, l9);
            if (l12.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l11 = l12.payload.s;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l13 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l9];
            t0 = vader_emit_c$is_abi_array(l1, l13);
            if (t0) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                l14 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l9];
                l15 = vader_emit_c$array_element_tag(l1, l14);
                l16 = vader_emit_c$val_type_of_field(l1, l15);
                vader_emit_c$push_pointee_assert(l11, l16, l3, l2);
            } else {
                vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_params);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
                t1 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l9, 628u);
                l17 = ((uint8_t) t1.payload.i);
                vader_emit_c$push_c_type_assert(l11, l17, l3, l2);
            }
            l9 = (l9 + INT64_C(1));
        }
        l19 = vader_core_bytecode$c_result_type(l7);
        if (l19.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l18 = l19.payload.s;
        l20 = vader_core_bytecode$bc_single_result(l8);
        vader_emit_c$push_c_type_assert(l18, l20, l3, l2);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$c_type_for(vader_box_t l0) {
    uint8_t t0;
    vader_string_t t1;
    t0 = vader_emit_c$val_type_of_bc_type(l0);
    t1 = vader_emit_c$c_type_for_val_bare(t0);
    return t1;
}

static vader_string_t vader_emit_c$c_type_for_array_kind(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(1)) {
        l1 = 3453u;
        return l1;
    }
    if (l0 == INT32_C(2)) {
        l1 = 3450u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3451u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3452u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2732u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2729u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2730u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2731u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2541u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2352u;
    } else if (l0 == INT32_C(11)) {
        l1 = 3451u;
    } else if (l0 == INT32_C(12)) {
        l1 = 3453u;
    } else if (l0 == INT32_C(13)) {
        l1 = 3701u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3560u;
    }
    return l1;
}

static vader_string_t vader_emit_c$c_type_for_val_bare(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2732u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2729u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2730u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2731u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3453u;
    } else if (l0 == INT32_C(5)) {
        l1 = 3450u;
    } else if (l0 == INT32_C(6)) {
        l1 = 3451u;
    } else if (l0 == INT32_C(7)) {
        l1 = 3452u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2541u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2352u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2091u;
    } else if (l0 == INT32_C(11)) {
        l1 = 3451u;
    } else if (l0 == INT32_C(12)) {
        l1 = 3657u;
    } else if (l0 == INT32_C(13)) {
        l1 = 3560u;
    } else if (l0 == INT32_C(14)) {
        l1 = 3699u;
    } else if (l0 == INT32_C(15)) {
        l1 = 3701u;
    } else if (l0 == INT32_C(16)) {
        l1 = 3701u;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3560u;
    }
    return l1;
}

static int32_t vader_emit_c$callee_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 1308u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 1337u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        return t1;
    }
    if (!(l0.tag == 1336u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
    return t1;
}

static int64_t vader_emit_c$callee_result_arity(void* l0, vader_box_t l1) {
    int64_t l2, l4;
    bool l3;
    void* l5;
    int32_t l6;
    void* t0;
    int32_t t1;
    int64_t t2;
    if (l1.tag == 1308u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        l2 = ((int64_t) (int32_t) t1);
        if ((INT64_C(0) <= l2)) {
            l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions));
            l3 = (l2 < l4);
        } else {
            l3 = false;
        }
        if (!(!(l3))) {
            l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
            t2 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature);
            return t2;
        }
        return INT64_C(1);
    }
    if (!(l1.tag == 1309u)) {
        return INT64_C(1);
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
    l2 = ((int64_t) (int32_t) t1);
    if ((INT64_C(0) <= l2)) {
        l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_imports));
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (!(!(l3))) {
        l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_imports;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        t2 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature);
        return t2;
    }
    return INT64_C(1);
}

static int32_t vader_emit_c$class_index(void* l0, uint8_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        if (l4.tag == 1283u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

static bool vader_emit_c$class_matches_type(void* l0, uint8_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    if (!(l3.tag == 1283u)) {
        return false;
    }
    t0 = l3.payload.obj;
    return ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == l1;
}

static int32_t vader_emit_c$class_tag_of(void* l0, uint8_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    bool t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        if (l4.tag == 1283u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    t1 = vader_core_bytecode$is_float_val(l1);
    if (t1) {
        l2 = INT64_C(0);
        l3 = vader_array_length(((vader_array_t*) l0));
        while ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l4 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
            if (l4.tag == 1283u) {
                t0 = l4.payload.obj;
                t1 = vader_core_bytecode$is_float_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
                if (t1) {
                    return ((int32_t) (int64_t) l2);
                }
            }
            l2 = (l2 + INT64_C(1));
        }
    }
    return INT32_C(0);
}

static void* vader_emit_c$classify_struct_fields(void* l0, void* l1, int64_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    int32_t l9;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    uint8_t t4;
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l7, &l8, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l11, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    l3 = t0.payload.s;
    l4 = vader_emit_c$empty_struct_offsets();
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields));
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
        t1 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_name;
        l11 = vader_emit_c$field_c_name(t1);
        l12 = concat_5(3012u, l3, 444u, l11, 398u);
        if (l10.tag == 1283u) {
            t2 = l10.payload.obj;
            t3 = vader_core_bytecode$is_string_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t2)->f_val);
            if (t3) {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_str_offsets, vader_box_string(623u, l12));
            }
        } else {
            t4 = vader_emit_c$val_type_of_bc_type(l10);
            if (t4 == INT32_C(16)) {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_ref_offsets, vader_box_string(623u, l12));
            } else {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_ptr_offsets, vader_box_string(623u, l12));
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$close_node(void* l0, vader_string_t l1) {
    void* l2;
    int64_t l3;
    vader_box_t l4;
    int64_t t0;
    void* t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes));
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    if (l4.tag == 1589u) {
        t1 = l4.payload.obj;
        ((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_end_label = l1;
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes);
        return;
    }
    t1 = l4.payload.obj;
    ((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_end_label = l1;
    t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes);
    return;
}

static vader_box_t vader_emit_c$coerce_expr(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
    bool l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == l3) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(16)) {
        if (l2 == INT32_C(17)) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(13);
        }
        if (!(l4)) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_emit_c$payload(l1, 3007u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(16)) {
        t1 = vader_emit_c$is_ref_val(l3);
        if (!(t1)) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_emit_c$ref_box(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c$is_ref_val(l3);
    if (t1) {
        t1 = vader_emit_c$is_ref_val(l2);
        if (t1) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = vader_emit_c$is_ref_val(l3);
    if (t1) {
        t0 = vader_emit_c$box_expr_unknown(l0, l1, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c$is_ref_val(l2);
    if (!(t1)) {
        t0 = vader_emit_c$scalar_cast(l1, l2, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_emit_c$unbox_expr(l1, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$coerce_operand(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$is_ref_val(l2);
    if (!(t0)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c$coerce_expr(l0, l1, l2, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$coerced_as(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    uint8_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l4 = vader_emit_c$expression_of(l1);
    l5 = vader_emit_c$val_of(l1);
    t0 = vader_emit_c$coerce_expr(l3, l4, l5, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$compute_atom_ids(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l3;
    int64_t l4, l5;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core$is_empty__string(l1);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 626u);
        l2 = (void*) _a0_arr;
        l3 = INT32_C(1);
        l4 = INT64_C(0);
        l5 = vader_array_length(((vader_array_t*) l0));
        vader_array_t* _pc12_hdr = (vader_array_t*) l2;
        size_t _pc12_len = vader_array_length(_pc12_hdr);
        size_t _pc12_cap = vader_array_is_borrowed(_pc12_hdr) ? (size_t) 0 : vader_array_capacity(_pc12_hdr);
        void* _pc12_slots = _pc12_hdr->buf->slots;
        for (;;) {
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l4];
                t2 = t1.payload.s;
                if (t2 == 0u) {
                    if (VADER_LIKELY(_pc12_len < _pc12_cap)) {
                        ((int32_t*) _pc12_slots)[_pc12_len] = (int32_t) (INT32_C(0));
                        _pc12_len += 1;
                    } else {
                        vader_array_set_length(_pc12_hdr, _pc12_len);
                        if (_pc12_hdr->buf->length < _pc12_len) {
                            _pc12_hdr->buf->length = _pc12_len;
                        }
                        vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                        _pc12_hdr = (vader_array_t*) l2;
                        _pc12_len = vader_array_length(_pc12_hdr);
                        _pc12_cap = vader_array_is_borrowed(_pc12_hdr) ? (size_t) 0 : vader_array_capacity(_pc12_hdr);
                        _pc12_slots = _pc12_hdr->buf->slots;
                    }
                } else {
                    if (VADER_LIKELY(_pc12_len < _pc12_cap)) {
                        ((int32_t*) _pc12_slots)[_pc12_len] = (int32_t) (l3);
                        _pc12_len += 1;
                    } else {
                        vader_array_set_length(_pc12_hdr, _pc12_len);
                        if (_pc12_hdr->buf->length < _pc12_len) {
                            _pc12_hdr->buf->length = _pc12_len;
                        }
                        vader_array_push_i32((vader_array_t*) l2, l3);
                        _pc12_hdr = (vader_array_t*) l2;
                        _pc12_len = vader_array_length(_pc12_hdr);
                        _pc12_cap = vader_array_is_borrowed(_pc12_hdr) ? (size_t) 0 : vader_array_capacity(_pc12_hdr);
                        _pc12_slots = _pc12_hdr->buf->slots;
                    }
                    l3 = vader_chk_add(i32, l3, INT32_C(1));
                }
                l4 = (l4 + INT64_C(1));
                continue;
            }
            vader_array_set_length(_pc12_hdr, _pc12_len);
            if (_pc12_hdr->buf->length < _pc12_len) {
                _pc12_hdr->buf->length = _pc12_len;
            }
            break;
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 626u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 626u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__i32_t* _a5_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a5_obj, 977u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a5_obj;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l1));
    while ((l4 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l4];
        l8 = t1.payload.s;
        l3 = vader_chk_add(i32, ((int32_t) (int64_t) l4), INT32_C(1));
        std_collections$get_or_put__string__i32(l2, l8, l3);
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 626u);
    l6 = (void*) _a7_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l0));
    while ((l4 < l5)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l4];
        t2 = t1.payload.s;
        if (t2 == 0u) {
            vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        } else {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t1 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l4];
            l8 = t1.payload.s;
            l9 = std_collections$Map$std_core$Index$at__string__i32(l2, l8);
            if (l9.tag == 0u) {
                l3 = INT32_C(0);
            } else {
                l3 = ((int32_t) l9.payload.i);
            }
            vader_array_push_i32((vader_array_t*) l6, l3);
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$compute_may_alloc(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6;
    bool l8;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_c_8_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_8_t));
    vader_obj_header_init(_a0_obj, 694u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(26u, (int64_t) t0, 12u, 621u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = __lambda_vader_emit_c_7(l3, l7);
        vader_array_push_bool((vader_array_t*) l4, l8);
        l6 = (l6 + INT64_C(1));
    }
    l2 = l4;
    l3 = l0;
    t0 = vader_array_length(((vader_array_t*) l3));
    vader_array_t* _a3_arr = vader_array_reserve(4u, (int64_t) t0, 13u, 29u);
    l4 = (void*) _a3_arr;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6);
        l7 = vader_emit_c$direct_callees(t1);
        vader_array_push_ref((vader_array_t*) l4, l7);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_support_fixpoint$Graph_t* _a5_obj = (vader_struct_vader_support_fixpoint$Graph_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_fixpoint$Graph_t));
    vader_obj_header_init(_a5_obj, 2080u);
    _a5_obj->f_successors = l4;
    t1 = (void*) _a5_obj;
    vader_support_fixpoint$solve_reachability(t1, l2);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$const_lit_c(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3, l7;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void* l8 = NULL;
    uint64_t l6;
    int32_t l9;
    void* t0 = NULL;
    int32_t t1;
    double t2;
    vader_string_t t3 = 0;
    bool t4;
    uint32_t t5;
    int64_t t6;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1345u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l3 = ((int64_t) (int32_t) t1);
        vader_struct_vader_emit_c_ast$CIntegerLiteral_t* _a0_obj = (vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIntegerLiteral_t));
        vader_obj_header_init(_a0_obj, 1593u);
        _a0_obj->f_class = (uint8_t) 2;
        _a0_obj->f_value = l3;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1365u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        vader_struct_vader_emit_c_ast$CIntegerLiteral_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIntegerLiteral_t));
        vader_obj_header_init(_a1_obj, 1593u);
        _a1_obj->f_class = (uint8_t) 3;
        _a1_obj->f_value = l3;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l1.tag == 1324u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        t3 = vader_emit_c$float_lit(t2);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else if (l1.tag == 1296u) {
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        if (t4) {
            l4 = 3379u;
        } else {
            l4 = 2502u;
        }
        l2 = vader_emit_c_ast$verbatim(l4);
    } else if (l1.tag == 1311u) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t6 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        l6 = (uint64_t) (int64_t) t6;
        l3 = std_core$write_unsigned(l5, l3, l6);
        l3 = std_core$write_string_at(l5, l3, 3423u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else if (l1.tag == 1397u) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(42));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l5, l3, 3559u);
        t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_null_tag;
        l7 = ((int64_t) (int32_t) t1);
        l3 = std_core$write_int(l5, l3, l7);
        l3 = std_core$write_string_at(l5, l3, 3426u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else {
        if (!(l1.tag == 1414u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        l8 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_ids;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l9];
        l7 = ((int64_t) (int32_t) t1);
        l3 = std_core$write_int(l5, l3, l7);
        l3 = std_core$write_string_at(l5, l3, 3423u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$const_val(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 1345u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 1365u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 1324u) {
        l1 = (uint8_t) 9;
    } else if (l0.tag == 1296u) {
        l1 = (uint8_t) 10;
    } else if (l0.tag == 1311u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 1397u) {
        l1 = (uint8_t) 17;
    } else {
        if (!(l0.tag == 1414u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 12;
    }
    return l1;
}

static uint8_t vader_emit_c$convert_target_val(uint8_t l0) {
    uint8_t l1;
    if (l0 == INT32_C(0)) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = (uint8_t) 3;
    } else if (l0 == INT32_C(2)) {
        l1 = (uint8_t) 9;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 11;
    }
    return l1;
}

static void* vader_emit_c$current_block(void* l0) {
    void* l1;
    int64_t l2;
    vader_box_t l3, l4;
    int64_t t0;
    void* t1;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes));
    if (t0 == INT64_C(0)) {
        return ((vader_struct_vader_emit_c$FnState_t*) l0)->f_root;
    }
    l1 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes));
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    if (!(l3.tag == 1589u)) {
        t1 = l3.payload.obj;
        return ((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_body;
    }
    t1 = l3.payload.obj;
    l4 = ((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_else_block;
    if (l4.tag == 0u) {
        t1 = l3.payload.obj;
        return ((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_then_block;
    }
    t1 = l4.payload.obj;
    return t1;
}

static vader_box_t vader_emit_c$data_slot(uint8_t l0, uint64_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int64_t l5;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l6, &t1 };
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$c_type_for_array_kind(l0);
    if (l0 == INT32_C(10)) {
        t0 = vader_emit_c$float_lit((((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
        l3 = vader_emit_c_ast$verbatim(t0);
        t1 = vader_emit_c_ast$cast(l2, l3);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(9))) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(20));
        l5 = INT64_C(0);
        l5 = std_core$write_unsigned(l4, l5, l1);
        t0 = std_core$finish_buffer(l4, l5);
        t1 = vader_emit_c_ast$verbatim(t0);
        vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
        l4 = (void*) _a0_arr;
        l6 = vader_emit_c_ast$call(1162u, l4);
        t1 = vader_emit_c_ast$cast(l2, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_emit_c$float_lit(((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
    l3 = vader_emit_c_ast$verbatim(t0);
    t1 = vader_emit_c_ast$cast(l2, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$declare(void* l0, vader_string_t l1, vader_string_t l2, vader_box_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$declaration(l1, l2, l3);
    vader_emit_c$append_statement(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c$declare_array(void* l0, vader_string_t l1, int32_t l2, vader_box_t l3) {
    void* l4 = NULL;
    int32_t l5, l6;
    vader_string_t l7 = 0;
    int64_t l8, l9;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[5] = { &l3, &l10, &l11, &l12, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_emit_c$array_element_tag(l4, l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    t1 = vader_core_bytecode$array_kind_of(t0, l4);
    l6 = vader_core_bytecode$array_kind_index(t1);
    l7 = vader_emit_c$aux(l0, 2013u);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l2);
    l8 = std_core$write_int(l4, l8, l9);
    l8 = std_core$write_string_at(l4, l8, 3423u);
    t2 = std_core$finish_buffer(l4, l8);
    l10 = vader_emit_c_ast$verbatim(t2);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l6);
    l8 = std_core$write_int(l4, l8, l9);
    l8 = std_core$write_string_at(l4, l8, 3423u);
    t2 = std_core$finish_buffer(l4, l8);
    l11 = vader_emit_c_ast$verbatim(t2);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l5);
    l8 = std_core$write_int(l4, l8, l9);
    l8 = std_core$write_string_at(l4, l8, 3423u);
    t2 = std_core$finish_buffer(l4, l8);
    l12 = vader_emit_c_ast$verbatim(t2);
    vader_array_t* _a1_arr = vader_array_new(486u, 4u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 3u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = l11.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l3.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l10.payload.obj;
    l4 = (void*) _a1_arr;
    l10 = vader_emit_c_ast$call(l1, l4);
    vader_emit_c$declare(l0, 3548u, l7, l10);
    { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$deep_copy_return(uint8_t l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null();
    void* l2 = NULL;
    bool l3;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(16)) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a0_arr;
        l1 = vader_emit_c_ast$returning(3582u, l2);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        l3 = true;
    } else {
        l3 = l0 == INT32_C(13);
    }
    if (l3) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a1_arr;
        l1 = vader_emit_c_ast$returning(3581u, l2);
    } else {
        if (l0 == INT32_C(0)) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(1);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(2);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(3);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(4);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(5);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(6);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(7);
        }
        if (l3) {
            vader_array_t* _a2_arr = vader_array_new(266u, 0u, 13u, 1566u);
            l2 = (void*) _a2_arr;
            l4 = vader_emit_c$argument(INT64_C(0));
            vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a3_obj, 1604u);
            _a3_obj->f_stores = l2;
            _a3_obj->f_value = l4;
            _a3_obj->f_snapshot_type = 0u;
            _a3_obj->f_pops_frame = false;
            t1 = (void*) _a3_obj;
            l1 = vader_ref_box(t1);
        } else {
            if (l0 == INT32_C(8)) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(9);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(10);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(11);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(12);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(14);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(15);
            }
            if (!(l3)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a4_arr = vader_array_new(266u, 0u, 13u, 1566u);
            l2 = (void*) _a4_arr;
            l4 = vader_emit_c$argument(INT64_C(0));
            vader_struct_vader_emit_c_ast$CReturn_t* _a5_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a5_obj, 1604u);
            _a5_obj->f_stores = l2;
            _a5_obj->f_value = l4;
            _a5_obj->f_snapshot_type = 0u;
            _a5_obj->f_pops_frame = false;
            t1 = (void*) _a5_obj;
            l1 = vader_ref_box(t1);
        }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$direct_callees(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 626u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    vader_array_t* _pc8_hdr = (vader_array_t*) l1;
    size_t _pc8_len = vader_array_length(_pc8_hdr);
    size_t _pc8_cap = vader_array_is_borrowed(_pc8_hdr) ? (size_t) 0 : vader_array_capacity(_pc8_hdr);
    void* _pc8_slots = _pc8_hdr->buf->slots;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            if (l5.tag == 1308u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
                if (VADER_LIKELY(_pc8_len < _pc8_cap)) {
                    ((int32_t*) _pc8_slots)[_pc8_len] = (int32_t) (l6);
                    _pc8_len += 1;
                } else {
                    vader_array_set_length(_pc8_hdr, _pc8_len);
                    if (_pc8_hdr->buf->length < _pc8_len) {
                        _pc8_hdr->buf->length = _pc8_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, l6);
                    _pc8_hdr = (vader_array_t*) l1;
                    _pc8_len = vader_array_length(_pc8_hdr);
                    _pc8_cap = vader_array_is_borrowed(_pc8_hdr) ? (size_t) 0 : vader_array_capacity(_pc8_hdr);
                    _pc8_slots = _pc8_hdr->buf->slots;
                }
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc8_hdr, _pc8_len);
        if (_pc8_hdr->buf->length < _pc8_len) {
            _pc8_hdr->buf->length = _pc8_len;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$directive(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CDirective_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDirective_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDirective_t));
    vader_obj_header_init(_a0_obj, 1581u);
    _a0_obj->f_text = l1;
    l2 = (void*) _a0_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c$dispatcher_name(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_core_mangle$vtable_dispatcher_mangle(l0);
    t1 = vader_emit_c$sanitise(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$dispatcher_parameters(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CParameter_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a0_obj, 1599u);
    _a0_obj->f_type = 3560u;
    _a0_obj->f_name = 3105u;
    l1 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_params));
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    t1 = vader_emit_c$boxed_parameters(l1, l2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$dispatcher_result(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
    bool l4;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l3 == INT32_C(17)) {
        l4 = l2 != INT32_C(17);
    } else {
        l4 = false;
    }
    if (l4) {
        l4 = l2 != INT32_C(14);
    } else {
        l4 = false;
    }
    if (l4) {
        t0 = vader_emit_c$coerce_expr(l0, l1, l2, (uint8_t) 17);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$dispatcher_signature(void* l0, vader_string_t l1, void* l2) {
    uint8_t l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l6 = NULL;
    bool t0;
    uint8_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l3 = vader_emit_c$wrapper_storage(t0);
    t1 = vader_core_bytecode$bc_single_result(l2);
    l4 = vader_emit_c$c_type_for_val_bare(t1);
    l5 = vader_emit_c$dispatcher_name(l1);
    l6 = vader_emit_c$dispatcher_parameters(l2);
    vader_struct_vader_emit_c_ast$CSignature_t* _a0_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a0_obj, 1608u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline = false;
    _a0_obj->f_result = l4;
    _a0_obj->f_name = l5;
    _a0_obj->f_parameters = l6;
    t2 = (void*) _a0_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$div_mod_helper(uint8_t l0, uint8_t l1) {
    bool l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(2)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(3);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(7);
    }
    if (l2) {
        if (l0 == INT32_C(1)) {
            l3 = 2348u;
        } else {
            l3 = 2920u;
        }
        l4 = vader_core_bytecode$val_type_name(l1);
        t0 = concat_4(3513u, l3, 1245u, l4);
        { vader_box_t __vret = vader_box_string(623u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_emit_c$drop_bound_for_local(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(262u, 0u, 13u, 1545u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        t0 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c$BoundArray_t*) l6)->f_pointer, l1);
        if (!(t0)) {
            vader_array_push_ref((vader_array_t*) l2, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$drop_top(void* l0) {
    int64_t l1;
    void* l2 = NULL;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(0), (int64_t) l1);
        l2 = (void*) _a0_arr;
        ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_emit_c$element_storage_kind(void* l0) {
    vader_box_t l1;
    int64_t t0;
    void* t1;
    t0 = vader_array_length(((vader_array_t*) l0));
    if (t0 == INT64_C(0)) {
        return (uint8_t) 0;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
    if (!(l1.tag == 1289u)) {
        return (uint8_t) 0;
    }
    t1 = l1.payload.obj;
    return ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_kind;
}

static void vader_emit_c$emit_agg_data_entry(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l11 = NULL;
    int64_t l6, l7, l10, l12;
    vader_box_t l8 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l13 = 0;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l8, &l14 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcAggregateData_t*) l3)->f_elements));
    vader_array_t* _a0_arr = vader_array_reserve(486u, (int64_t) t0, 13u, 2777u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcAggregateData_t*) l3)->f_elements));
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcAggregateData_t*) l3)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l8 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        l9 = ((vader_struct_vader_emit_c$PoolArray_t*) l2)->f_name;
        l10 = vader_host_std_core$Intrinsic$byte_len(l9);
        l11 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l10));
        l12 = INT64_C(0);
        l12 = std_core$write_string_at(l11, l12, l9);
        l12 = std_core$write_string_at(l11, l12, 1293u);
        l12 = std_core$write_int(l11, l12, l6);
        l13 = std_core$finish_buffer(l11, l12);
        l14 = vader_emit_c$box_slot_1(l0, l1, l8, l13, l4);
        vader_array_push_ref((vader_array_t*) l5, l14.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    vader_emit_c$push_pool_array(l1, l2, 3560u, (uint8_t) 0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_clear(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$object_pointer_of(t0);
    t0 = vader_emit_c$array_pointer(t1);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3517u, l1);
    vader_emit_c$evaluate(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_copy(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l1, &l2, &l3, &l4, &l5, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$object_pointer_of(t0);
    l5 = vader_emit_c$array_pointer(t1);
    l4 = vader_emit_c$as_count(l4);
    t0 = vader_emit_c$object_pointer_of(l3);
    l3 = vader_emit_c$array_pointer(t0);
    l2 = vader_emit_c$as_count(l2);
    l1 = vader_emit_c$as_count(l1);
    vader_array_t* _a0_arr = vader_array_new(486u, 5u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3518u, l6);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l6 = vader_box_null(), l8 = vader_box_null(), l16 = vader_box_null();
    void* l4 = NULL;
    void* l13 = NULL;
    int32_t l5;
    uint8_t l7, l11;
    bool l9;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    int64_t l14, l15;
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[5] = { &l2, &l3, &l6, &l8, &l16 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l13, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l10, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$pop(l0);
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) l1)->f_type_id;
    l5 = vader_emit_c$array_element_tag(l4, l5);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    l7 = vader_core_bytecode$array_kind_of(l6, l4);
    l8 = vader_emit_c$typed_array_fill_for(l7);
    l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) l1)->f_bounds_safe;
    l10 = vader_emit_c$emit_slot_array_local(l0, l3, l2, l9);
    if (l8.tag == 0u) {
        t0 = vader_emit_c$ref_carrying_element(l6, l4);
        if (t0) {
            l11 = vader_emit_c$val_type_of_bc_type(l6);
            if (l11 == INT32_C(16)) {
                l12 = 3538u;
            } else {
                l12 = 3537u;
            }
            t1 = concat_2(l10, 485u);
            l3 = vader_emit_c_ast$verbatim(t1);
            l6 = vader_emit_c$slot_index(l10, l2);
            vader_array_t* _a1_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l6.payload.obj;
            ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l3.payload.obj;
            l13 = (void*) _a1_arr;
            l3 = vader_emit_c_ast$call(l12, l13);
            vader_emit_c$push_into_temporary(l0, l3, l11);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l8.tag == 0u) {
        l3 = vader_emit_c$slot_index(l10, l2);
        l3 = vader_emit_c$box_slot(l10, l3);
        vader_emit_c$push_into_temporary(l0, l3, (uint8_t) 17);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(1)) {
        l3 = vader_emit_c_ast$verbatim(l10);
        l6 = vader_emit_c$slot_index(l10, l2);
        l13 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l15 = ((int64_t) (int32_t) l5);
        l14 = std_core$write_int(l13, l14, l15);
        l14 = std_core$write_string_at(l13, l14, 3423u);
        t1 = std_core$finish_buffer(l13, l14);
        l16 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a2_arr = vader_array_new(486u, 3u, 13u, 2777u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = l16.payload.obj;
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l6.payload.obj;
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3.payload.obj;
        l13 = (void*) _a2_arr;
        l3 = vader_emit_c_ast$call(3536u, l13);
        vader_emit_c$push_into_temporary(l0, l3, (uint8_t) 17);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = l8.payload.obj;
    l12 = ((vader_struct_vader_emit_c$SlotFill_t*) t2)->f_cty;
    l2 = vader_emit_c$slot_index(l10, l2);
    l2 = vader_emit_c$typed_slot(l12, l10, l2);
    t2 = l8.payload.obj;
    l7 = ((vader_struct_vader_emit_c$SlotFill_t*) t2)->f_val;
    t0 = vader_emit_c$reboxes_to_own_tag(l4, l5, l7);
    if (t0) {
        t2 = l8.payload.obj;
        l7 = ((vader_struct_vader_emit_c$SlotFill_t*) t2)->f_val;
        vader_emit_c$push_into_temporary(l0, l2, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = l8.payload.obj;
    l7 = ((vader_struct_vader_emit_c$SlotFill_t*) t2)->f_val;
    l2 = vader_emit_c$box_expr(l2, l7, l5);
    vader_emit_c$push_into_temporary(l0, l2, (uint8_t) 17);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_len(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$array_header_pointer(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3520u, l1);
    vader_emit_c$push_into_temporary(l0, l2, (uint8_t) 3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_new(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3, l5, l11;
    uint8_t l4, l16;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l12 = 0;
    vader_string_t l15 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[13] = {
        &l8, &l10, &l13, &l14, &l17, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &t0,
    };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l9, &l12, &l15, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 13u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l1)->f_type_id;
    l3 = vader_emit_c$array_element_tag(l2, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l4 = vader_core_bytecode$array_kind_of(t0, l2);
    l3 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l1)->f_length;
    l5 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l1)->f_type_id;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l6 = INT64_C(0);
    l7 = ((int64_t) (int32_t) l3);
    l6 = std_core$write_int(l2, l6, l7);
    l6 = std_core$write_string_at(l2, l6, 3423u);
    t1 = std_core$finish_buffer(l2, l6);
    l8 = vader_emit_c_ast$verbatim(t1);
    l9 = vader_emit_c$declare_array(l0, 3521u, l5, l8);
    l8 = vader_emit_c$typed_array_fill_for(l4);
    l5 = INT32_C(0);
    while ((l5 < l3)) {
        l10 = vader_emit_c$pop(l0);
        t2 = vader_chk_sub(i32, l3, INT32_C(1));
        l11 = vader_chk_sub(i32, t2, l5);
        if (l8.tag == 0u) {
            if (l4 == INT32_C(13)) {
                l19 = vader_emit_c$fresh_slot(l9, l11);
                l20 = vader_emit_c$typed_slot(3701u, l9, l19);
                l21 = vader_emit_c$coerced_as(l0, l10, (uint8_t) 16);
                vader_emit_c$assign(l0, l20, l21);
            } else {
                l22 = vader_emit_c$fresh_slot(l9, l11);
                l23 = vader_emit_c$box_slot(l9, l22);
                l24 = vader_emit_c$coerced_as(l0, l10, (uint8_t) 17);
                vader_emit_c$assign(l0, l23, l24);
            }
        } else {
            t3 = l8.payload.obj;
            l12 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_cty;
            l13 = vader_emit_c$fresh_slot(l9, l11);
            l14 = vader_emit_c$typed_slot(l12, l9, l13);
            t3 = l8.payload.obj;
            l15 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_cty;
            t3 = l8.payload.obj;
            l16 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_val;
            l17 = vader_emit_c$coerced_as(l0, l10, l16);
            l18 = vader_emit_c_ast$cast(l15, l17);
            vader_emit_c$assign(l0, l14, l18);
        }
        l5 = (l5 + INT32_C(1));
    }
    l8 = vader_emit_c_ast$verbatim(l9);
    vader_emit_c$push_object(l0, l8);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null(), l13 = vader_box_null();
    void* l4 = NULL;
    void* l10 = NULL;
    int32_t l6;
    uint8_t l7, l9;
    bool l11;
    vader_string_t l12 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t3 = NULL;
    bool t2;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l5, &l8, &l13, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l10, &t1, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$pop(l0);
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_emit_c$object_pointer_of(l3);
    l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l1)->f_type_id;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    l7 = vader_core_bytecode$array_kind_of(t0, l4);
    l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l1)->f_cache_slot;
    l8 = vader_emit_c$pc_active_for(l0, l6);
    if (!(l8.tag == 0u)) {
        t1 = l8.payload.obj;
        l6 = ((vader_struct_vader_emit_c$PushCache_t*) t1)->f_slot;
        t2 = vader_emit_c$pc_operand_is_slot(l3, l6);
        if (t2) {
            t1 = l8.payload.obj;
            t3 = vader_emit_c$pc_fill_of(((vader_struct_vader_emit_c$PushCache_t*) t1)->f_kind);
            l9 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_val;
            l10 = l8.payload.obj;
            l3 = vader_emit_c$coerced_as(l0, l2, l9);
            vader_emit_c$pc_emit_push(l0, l10, l5, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l3 = vader_emit_c$push_helper_for(l7);
    l8 = vader_emit_c$typed_array_fill_for(l7);
    if (l3.tag == 0u) {
        l11 = true;
    } else {
        l11 = l8.tag == 0u;
    }
    if (!(l11)) {
        l12 = l3.payload.s;
        l13 = vader_emit_c$array_pointer(l5);
        t1 = l8.payload.obj;
        l7 = ((vader_struct_vader_emit_c$SlotFill_t*) t1)->f_val;
        l8 = vader_emit_c$coerced_as(l0, l2, l7);
        vader_array_t* _a1_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l8.payload.obj;
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l13.payload.obj;
        l10 = (void*) _a1_arr;
        l8 = vader_emit_c_ast$call(l12, l10);
        vader_emit_c$evaluate(l0, l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l1)->f_type_id;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l3 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
    l5 = vader_emit_c$array_pointer(l5);
    vader_emit_c$emit_boxed_push(l0, l3, l5, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_push_all(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$object_pointer_of(t0);
    l2 = vader_emit_c$array_pointer(t1);
    t0 = vader_emit_c$object_pointer_of(l1);
    l1 = vader_emit_c$array_pointer(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3524u, l3);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_remove_last(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$object_pointer_of(t0);
    t0 = vader_emit_c$array_pointer(t1);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3542u, l1);
    vader_emit_c$push_into_temporary(l0, l2, (uint8_t) 17);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_repeat(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$aux(l0, 2013u);
    t0 = vader_emit_c$object_pointer_of(l2);
    l2 = vader_emit_c$array_pointer(t0);
    l1 = vader_emit_c$as_count(l1);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3543u, l4);
    vader_emit_c$declare(l0, 3548u, l3, l1);
    l1 = vader_emit_c_ast$verbatim(l3);
    vader_emit_c$push_object(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_reserve(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) l1)->f_type_id;
    l2 = vader_emit_c$as_count(l2);
    t0 = vader_emit_c$declare_array(l0, 3544u, l3, l2);
    l2 = vader_emit_c_ast$verbatim(t0);
    vader_emit_c$push_object(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_set(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l11 = vader_box_null();
    void* l5 = NULL;
    int32_t l6;
    bool l9;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    uint8_t l13;
    uint8_t t0;
    bool t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l4, &l7, &l8, &l11 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l10, &l12, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = ((vader_struct_vader_core_bytecode$ArraySet_t*) l1)->f_type_id;
    l6 = vader_emit_c$array_element_tag(l5, l6);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    t0 = vader_core_bytecode$array_kind_of(l7, l5);
    l8 = vader_emit_c$typed_array_fill_for(t0);
    l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) l1)->f_bounds_safe;
    l10 = vader_emit_c$emit_slot_array_local(l0, l4, l3, l9);
    if (l8.tag == 0u) {
        t1 = vader_emit_c$ref_carrying_element(l7, l5);
        if (t1) {
            if (l7.tag == 1282u) {
                t2 = concat_2(l10, 485u);
                l4 = vader_emit_c_ast$verbatim(t2);
                l7 = vader_emit_c$slot_index(l10, l3);
                l11 = vader_emit_c$coerced_as(l0, l2, (uint8_t) 17);
                vader_array_t* _a1_arr = vader_array_new(486u, 3u, 13u, 2777u);
                ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = l11.payload.obj;
                ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l7.payload.obj;
                ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l4.payload.obj;
                l5 = (void*) _a1_arr;
                l4 = vader_emit_c_ast$call(3541u, l5);
                vader_emit_c$evaluate(l0, l4);
            } else {
                t2 = concat_2(l10, 485u);
                l4 = vader_emit_c_ast$verbatim(t2);
                l7 = vader_emit_c$slot_index(l10, l3);
                l11 = vader_emit_c$object_pointer_of(l2);
                vader_array_t* _a2_arr = vader_array_new(486u, 3u, 13u, 2777u);
                ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = l11.payload.obj;
                ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l7.payload.obj;
                ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l4.payload.obj;
                l5 = (void*) _a2_arr;
                l4 = vader_emit_c_ast$call(3540u, l5);
                vader_emit_c$evaluate(l0, l4);
            }
            t2 = concat_2(l10, 485u);
            l4 = vader_emit_c_ast$verbatim(t2);
            vader_emit_c$write_barrier_for(l0, l4, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l8.tag == 0u) {
        l4 = vader_emit_c$slot_index(l10, l3);
        l4 = vader_emit_c$box_slot(l10, l4);
        l7 = vader_emit_c$coerced_as(l0, l2, (uint8_t) 17);
        vader_emit_c$assign(l0, l4, l7);
        t2 = concat_2(l10, 485u);
        l4 = vader_emit_c_ast$verbatim(t2);
        vader_emit_c$write_barrier_for(l0, l4, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t3 = l8.payload.obj;
    l12 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_cty;
    t3 = l8.payload.obj;
    l13 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_val;
    vader_emit_c$emit_typed_slot_write(l0, l10, l3, l2, l12, l13);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_slice(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    l5 = vader_emit_c$aux(l0, 2013u);
    t0 = vader_emit_c$object_pointer_of(l4);
    l4 = vader_emit_c$array_pointer(t0);
    l3 = vader_emit_c$as_count(l3);
    l2 = vader_emit_c$as_count(l2);
    vader_array_t* _a0_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l4.payload.obj;
    l6 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3546u, l6);
    vader_emit_c$declare(l0, 3548u, l5, l2);
    l2 = vader_emit_c_ast$verbatim(l5);
    vader_emit_c$push_object(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_atom_comptime_table(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    vader_box_t l8 = vader_box_null(), l16 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null();
    uint8_t l9;
    int64_t l10, l11, l12, l14, l23;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[7] = { &l8, &l16, &l18, &l19, &l21, &l22, &t3 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l17, &l20, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l13, &l15, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(623u, 729u);
    l2 = (void*) _a0_arr;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    if (t0 == INT64_C(0)) {
        t1 = (void*) &vader_data_69;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_69;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_69;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l5 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_69;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_69;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
        l8 = vader_emit_c_ast$verbatim(322u);
        vader_array_t* _a6_arr = vader_array_new(486u, 6u, 13u, 2777u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 5u] = l8.payload.obj;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 4u] = l7;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 3u] = l6;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 2u] = l5;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l4;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l3;
        t1 = (void*) _a6_arr;
        l8 = vader_emit_c_ast$initializer_list(t1);
        t2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l9 = vader_emit_c$global_storage(t2);
        vader_array_t* _a7_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l8.payload.obj;
        t1 = (void*) _a7_arr;
        l8 = vader_emit_c_ast$initializer_list(t1);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a8_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a8_obj, 1578u);
        _a8_obj->f_name = 3550u;
        _a8_obj->f_length = vader_box_i32(626u, INT32_C(1));
        _a8_obj->f_value = l8;
        l3 = (void*) _a8_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a9_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a9_obj, 1587u);
        _a9_obj->f_storage = l9;
        _a9_obj->f_constant = true;
        _a9_obj->f_type = 3551u;
        _a9_obj->f_declarator = l3;
        l3 = (void*) _a9_obj;
        l8 = vader_emit_c$atom_count_define(l0);
        vader_array_t* _a10_arr = vader_array_new(488u, 2u, 13u, 2786u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 1u] = l8.payload.obj;
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_struct_vader_emit_c_ast$CSection_t* _a11_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
        vader_obj_header_init(_a11_obj, 1606u);
        _a11_obj->f_comment = l2;
        _a11_obj->f_items = l3;
        l3 = (void*) _a11_obj;
        vader_emit_c_ast$print_section(l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l9 = vader_emit_c$global_storage(t2);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    vader_array_t* _a12_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
    l3 = (void*) _a12_arr;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    vader_array_t* _a13_arr = vader_array_reserve(486u, (int64_t) t0, 13u, 2777u);
    l4 = (void*) _a13_arr;
    l10 = INT64_C(0);
    l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table;
    l11 = vader_array_length(((vader_array_t*) l5));
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        t3 = vader_array_box_slots(_a14_slotarr->buf)[vader_array_offset(_a14_slotarr) + (size_t) l12];
        l13 = t3.payload.s;
        l14 = vader_host_std_core$Intrinsic$byte_len(l13);
        t4 = vader_emit_c$c_string_lit(l13);
        l15 = concat_2(t4, 63u);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l15));
        l8 = vader_emit_c_ast$verbatim(3549u);
        l16 = vader_emit_c_ast$number(l10);
        vader_struct_vader_emit_c_ast$CIndex_t* _a15_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
        vader_obj_header_init(_a15_obj, 1591u);
        _a15_obj->f_base = l8;
        _a15_obj->f_index = l16;
        l6 = (void*) _a15_obj;
        t1 = (void*) &vader_data_69;
        vader_array_t* _a16_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        l7 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_69;
        vader_array_t* _a17_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        l17 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) INT64_C(0));
        l18 = vader_emit_c_ast$unsigned(l14);
        l19 = vader_emit_c_ast$verbatim(1170u);
        t1 = (void*) &vader_data_69;
        vader_array_t* _a18_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l20 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) INT64_C(0));
        l21 = vader_emit_c_ast$address_of(vader_ref_box(l6));
        vader_array_t* _a19_arr = vader_array_new(486u, 6u, 13u, 2777u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 5u] = l21.payload.obj;
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 4u] = l20;
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 3u] = l19.payload.obj;
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 2u] = l18.payload.obj;
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 1u] = l17;
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = l7;
        t1 = (void*) _a19_arr;
        l22 = vader_emit_c_ast$initializer_list(t1);
        vader_array_push_ref((vader_array_t*) l4, l22.payload.obj);
        l23 = vader_chk_add(i64, l14, INT64_C(1));
        l10 = vader_chk_add(i64, l10, l23);
        l12 = (l12 + INT64_C(1));
    }
    t1 = (void*) &vader_data_68;
    vader_array_t* _a20_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
    l5 = vader_array_ref_load_obj(_a20_slotarr->buf, vader_array_offset(_a20_slotarr) + (size_t) INT64_C(0));
    vader_struct_vader_emit_c_ast$CStringLiterals_t* _a21_obj = (vader_struct_vader_emit_c_ast$CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStringLiterals_t));
    vader_obj_header_init(_a21_obj, 1610u);
    _a21_obj->f_literals = l3;
    l3 = (void*) _a21_obj;
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a22_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a22_obj, 1578u);
    _a22_obj->f_name = 3549u;
    _a22_obj->f_length = vader_ref_box(l5);
    _a22_obj->f_value = vader_ref_box(l3);
    l3 = (void*) _a22_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a23_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a23_obj, 1587u);
    _a23_obj->f_storage = l9;
    _a23_obj->f_constant = true;
    _a23_obj->f_type = 2232u;
    _a23_obj->f_declarator = l3;
    l3 = (void*) _a23_obj;
    t1 = (void*) &vader_data_68;
    vader_array_t* _a24_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
    l5 = vader_array_ref_load_obj(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) INT64_C(0));
    l8 = vader_emit_c_ast$initializer_list(l4);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a25_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a25_obj, 1578u);
    _a25_obj->f_name = 3550u;
    _a25_obj->f_length = vader_ref_box(l5);
    _a25_obj->f_value = l8;
    l4 = (void*) _a25_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a26_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a26_obj, 1587u);
    _a26_obj->f_storage = l9;
    _a26_obj->f_constant = true;
    _a26_obj->f_type = 3551u;
    _a26_obj->f_declarator = l4;
    l4 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(488u, 1u, 13u, 2786u);
    ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = l3;
    l3 = (void*) _a27_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a28_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a28_obj, 1606u);
    _a28_obj->f_comment = l2;
    _a28_obj->f_items = l3;
    l2 = (void*) _a28_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a29_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(488u, 1u, 13u, 2786u);
    ((void**) _a30_arr->buf->slots)[vader_array_offset(_a30_arr) + 0u] = l4;
    l3 = (void*) _a30_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a31_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a31_obj, 1606u);
    _a31_obj->f_comment = l2;
    _a31_obj->f_items = l3;
    l2 = (void*) _a31_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a32_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a32_arr;
    t3 = vader_emit_c$atom_count_define(l0);
    vader_array_t* _a33_arr = vader_array_new(488u, 1u, 13u, 2786u);
    ((void**) _a33_arr->buf->slots)[vader_array_offset(_a33_arr) + 0u] = t3.payload.obj;
    l3 = (void*) _a33_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a34_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a34_obj, 1606u);
    _a34_obj->f_comment = l2;
    _a34_obj->f_items = l3;
    l2 = (void*) _a34_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_bits_to_f32(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 2);
    l1 = vader_emit_c_ast$around(382u, l1, 418u);
    vader_emit_c$push_expr(l0, (uint8_t) 8, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_bits_to_f64(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 3);
    l1 = vader_emit_c_ast$around(383u, l1, 417u);
    vader_emit_c$push_expr(l0, (uint8_t) 9, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_boxed_push(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3) {
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    bool t0;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &l5 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = vader_emit_c$ref_carrying_element(l1, l4);
    if (t0) {
        if (!(l1.tag == 1282u)) {
            l5 = vader_emit_c$object_pointer_of(l3);
            vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l5.payload.obj;
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
            l4 = (void*) _a0_arr;
            l5 = vader_emit_c_ast$call(3532u, l4);
            vader_emit_c$evaluate(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l6 = vader_emit_c$boxed_push_helper(l3);
    l5 = vader_emit_c$coerced_as(l0, l3, (uint8_t) 17);
    vader_array_t* _a1_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l5.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l2.payload.obj;
    l4 = (void*) _a1_arr;
    l5 = vader_emit_c_ast$call(l6, l4);
    vader_emit_c$evaluate(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_branch(void* l0, int32_t l1, bool l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l9 = 0;
    void* l6 = NULL;
    int64_t l7, l8, l10;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    bool t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l6, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_jump_table);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    l4 = vader_emit_c$branch_target(((vader_struct_vader_emit_c$FnState_t*) l0)->f_scopes, l3);
    if (!(l4.tag == 1556u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(91));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2383u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 74u);
        l10 = ((int64_t) (int32_t) l3);
        l7 = std_core$write_int(l6, l7, l10);
        l7 = std_core$write_string_at(l6, l7, 398u);
        t0 = std_core$finish_buffer(l6, l7);
        std_abort$todo(t0);
        vader_unreachable("a no-return call returned");
    }
    t1 = l4.payload.obj;
    t2 = vader_emit_c$is_continue_branch(t1, l3);
    if (t2) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(25));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2854u);
        t1 = l4.payload.obj;
        t3 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t1)->f_opener_pc;
        l8 = ((int64_t) (int32_t) t3);
        l7 = std_core$write_int(l6, l7, l8);
        l5 = std_core$finish_buffer(l6, l7);
    } else {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(24));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2392u);
        t1 = l4.payload.obj;
        t3 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t1)->f_opener_pc;
        l8 = ((int64_t) (int32_t) t3);
        l7 = std_core$write_int(l6, l7, l8);
        l5 = std_core$finish_buffer(l6, l7);
    }
    if (l2) {
        l4 = vader_emit_c$pop(l0);
        l6 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2105u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 398u);
        l9 = std_core$finish_buffer(l6, l7);
        vader_emit_c$assert_stack_empty(l0, l9);
        l4 = vader_emit_c$expression_of(l4);
        vader_struct_vader_emit_c_ast$CGoto_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGoto_t));
        vader_obj_header_init(_a1_obj, 1588u);
        _a1_obj->f_label = l5;
        _a1_obj->f_condition = l4;
        l6 = (void*) _a1_obj;
        vader_emit_c$append_statement(l0, vader_ref_box(l6));
    } else {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(28));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2103u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 398u);
        l9 = std_core$finish_buffer(l6, l7);
        vader_emit_c$assert_stack_empty(l0, l9);
        vader_struct_vader_emit_c_ast$CGoto_t* _a2_obj = (vader_struct_vader_emit_c_ast$CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGoto_t));
        vader_obj_header_init(_a2_obj, 1588u);
        _a2_obj->f_label = l5;
        _a2_obj->f_condition = vader_box_obj(0u, NULL);
        l6 = (void*) _a2_obj;
        vader_emit_c$append_statement(l0, vader_ref_box(l6));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_buffer_load(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$buffer_pointer(t0);
    l3 = vader_emit_c$as_size(l3);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l4.payload.obj;
    l5 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(l1, l5);
    vader_emit_c$push_into_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_buffer_new(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$as_size(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3568u, l1);
    l2 = vader_emit_c_ast$cast(3701u, l2);
    vader_emit_c$push_into_temporary(l0, l2, (uint8_t) 16);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_buffer_store(void* l0, vader_string_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l3, &l4, &l5, &t0 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    l5 = vader_emit_c$buffer_pointer(t0);
    l4 = vader_emit_c$as_size(l4);
    l3 = vader_emit_c$expression_of(l3);
    l3 = vader_emit_c_ast$cast(l2, l3);
    vader_array_t* _a0_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(l1, l6);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_buffer_to_string(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$buffer_pointer(t0);
    l1 = vader_emit_c$as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3562u, l3);
    vader_emit_c$push_into_temporary(l0, l1, (uint8_t) 12);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_buffer_write_string(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$buffer_pointer(t0);
    l2 = vader_emit_c$as_size(l2);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 12);
    vader_array_t* _a0_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3574u, l4);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_emit_c$emit_c_split(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    bool l7;
    vader_box_t l11 = vader_box_null();
    int64_t l13, l14, l18, l19;
    int32_t l20;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l3, &l4, &l6, &l8, &l9, &l10, &l12, &l15, &l16, &l17, &l21, &l22, &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l2, &l5, &l23, &l24, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$partition_functions(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    l4 = l1;
    l5 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l4)->f_entry_mangled;
    l6 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l4)->f_atom_universe;
    l7 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l4)->f_verify_bounds;
    vader_struct_vader_emit_c$CEmitOptions_t* _a0_obj = (vader_struct_vader_emit_c$CEmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$CEmitOptions_t));
    vader_obj_header_init(_a0_obj, 1547u);
    _a0_obj->f_entry_mangled = l5;
    _a0_obj->f_split = true;
    _a0_obj->f_atom_universe = l6;
    _a0_obj->f_verify_bounds = l7;
    _a0_obj->f_library_units = true;
    l4 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_entry_mangled;
    l6 = vader_emit_c$internal_fn_flags(l0, l3, l5);
    l4 = vader_emit_c$new_ctx(l0, l4, l6);
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 1096u);
    _a2_obj->f_parts = t0;
    t0 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a3_obj, 1602u);
    _a3_obj->f_out = t0;
    _a3_obj->f_started = false;
    l6 = (void*) _a3_obj;
    vader_emit_c$emit_preamble(l6, 772u);
    vader_emit_c$emit_struct_typedefs(l4, l6);
    vader_emit_c$emit_fn_sig_typedefs(l4, l6);
    vader_emit_c$emit_forward_decls(l4, l6);
    vader_emit_c$emit_closure_forward_decls(l4, l6);
    vader_emit_c$emit_vtable_forward_decls(l4, l6);
    vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a4_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a5_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a5_obj, 1096u);
    _a5_obj->f_parts = t0;
    t0 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a6_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a6_obj, 1602u);
    _a6_obj->f_out = t0;
    _a6_obj->f_started = false;
    l8 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_box_string(623u, 771u);
    l9 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CInclude_t* _a8_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a8_obj, 1590u);
    _a8_obj->f_path = 3507u;
    _a8_obj->f_system = false;
    t0 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(488u, 1u, 13u, 2786u);
    ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0;
    l10 = (void*) _a9_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a10_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a10_obj, 1606u);
    _a10_obj->f_comment = l9;
    _a10_obj->f_items = l10;
    l9 = (void*) _a10_obj;
    vader_emit_c_ast$print_section(l8, l9);
    vader_emit_c$emit_import_shims(l4, l8);
    t1 = vader_emit_c$imports_header_name(l2);
    vader_struct_vader_emit_c_ast$CInclude_t* _a11_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a11_obj, 1590u);
    _a11_obj->f_path = t1;
    _a11_obj->f_system = false;
    l9 = (void*) _a11_obj;
    vader_emit_c_ast$print_item(l6, vader_ref_box(l9));
    l11 = vader_emit_c$atom_count_define(l4);
    vader_emit_c_ast$print_item(l6, l11);
    vader_emit_c$emit_data_global_externs(l4, l6);
    l9 = vader_emit_c$including(l2);
    vader_emit_c$emit_atom_comptime_table(l4, l9);
    vader_emit_c$emit_data_pool(l4, l9);
    vader_emit_c$emit_type_info_table(l4, l9);
    l10 = vader_emit_c$unit_names_of(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions, l3);
    t2 = vader_array_length(((vader_array_t*) l3));
    vader_array_t* _a12_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
    l12 = (void*) _a12_arr;
    l13 = INT64_C(0);
    l14 = vader_array_length(((vader_array_t*) l3));
    while ((l13 < l14)) {
        l15 = vader_emit_c$including(l2);
        vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
        l16 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l13);
        vader_emit_c$emit_internal_forward_decls(l4, l16, l15);
        if (l13 == INT64_C(0)) {
            vader_emit_c$emit_fn_trampolines(l4, l15);
            vader_emit_c$emit_vtable_dispatchers(l4, l15);
        }
        vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l13)
        l17 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l13);
        l18 = vader_array_length(((vader_array_t*) l17));
        l19 = INT64_C(0);
        while ((l19 < l18)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l19)
            l20 = ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l19];
            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l20)
            l21 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l20);
            l22 = vader_emit_c$function_definition(l4, l20, l21);
            vader_emit_c_ast$print_item(l15, vader_ref_box(l22));
            l19 = (l19 + INT64_C(1));
        }
        if (l13 == INT64_C(0)) {
            l5 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_entry_mangled;
            vader_emit_c$emit_main(l4, l15, l5);
        }
        l23 = vader_emit_c_ast$printed_text(l15);
        vader_array_push_scalar((vader_array_t*) l12, vader_box_string(623u, l23));
        l13 = (l13 + INT64_C(1));
    }
    vader_emit_c$push_foreign_units(l4, l10, l12);
    l5 = vader_emit_c_ast$printed_text(l6);
    l23 = vader_emit_c_ast$printed_text(l8);
    l24 = vader_emit_c_ast$printed_text(l9);
    vader_struct_vader_emit_c$CProgram_t* _a17_obj = (vader_struct_vader_emit_c$CProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$CProgram_t));
    vader_obj_header_init(_a17_obj, 1548u);
    _a17_obj->f_header = l5;
    _a17_obj->f_imports = l23;
    _a17_obj->f_globals = l24;
    _a17_obj->f_units = l12;
    _a17_obj->f_unit_names = l10;
    t0 = (void*) _a17_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$emit_call(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l3 = ((vader_struct_vader_core_bytecode$Call_t*) l1)->f_function_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_name;
    l4 = vader_emit_c$sanitise(t0);
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature;
    vader_emit_c$emit_call_to(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_call_import(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_string_t l4 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_imports;
    l3 = ((vader_struct_vader_core_bytecode$CallImport_t*) l1)->f_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l4 = vader_emit_c$host_shim_name(l2);
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
    vader_emit_c$emit_call_to(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_call_indirect(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l7 = 0;
    int64_t l9, l10;
    uint8_t l11;
    int32_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l6, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) l1)->f_type_id;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    if (!(l4.tag == 1276u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(49));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l6, l9, 2188u);
        t0 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) l1)->f_type_id;
        l10 = ((int64_t) (int32_t) t0);
        l9 = std_core$write_int(l6, l9, l10);
        t1 = std_core$finish_buffer(l6, l9);
        std_abort$todo(t1);
        vader_unreachable("a no-return call returned");
    }
    l5 = vader_emit_c$pop(l0);
    t2 = l4.payload.obj;
    t3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) t2)->f_params));
    l3 = ((int32_t) (int64_t) t3);
    t2 = l4.payload.obj;
    l6 = ((vader_struct_vader_core_bytecode$BcFn_t*) t2)->f_params;
    l6 = vader_emit_c$pop_erased_args(l0, l6, l2);
    l7 = vader_emit_c$aux(l0, 2552u);
    l5 = vader_emit_c$object_pointer_of(l5);
    l5 = vader_emit_c_ast$cast(3596u, l5);
    vader_emit_c$declare(l0, 3596u, l7, l5);
    t1 = concat_2(l7, 489u);
    t4 = vader_emit_c_ast$verbatim(t1);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t4.payload.obj;
    l8 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
    l9 = vader_host_std_core$Intrinsic$byte_len(l7);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(53) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l6, l9, 384u);
    l10 = ((int64_t) (int32_t) l3);
    l9 = std_core$write_int(l6, l9, l10);
    l9 = std_core$write_string_at(l6, l9, 1307u);
    l9 = std_core$write_string_at(l6, l9, l7);
    l9 = std_core$write_string_at(l6, l9, 488u);
    t1 = std_core$finish_buffer(l6, l9);
    l5 = vader_emit_c_ast$call(t1, l8);
    t2 = l4.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$BcFn_t*) t2)->f_return_type;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t4 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
    l11 = vader_emit_c$val_type_of_bc_type(t4);
    if (l11 == INT32_C(14)) {
        vader_emit_c$evaluate(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_emit_c$new_temporary(l0, (uint8_t) 17);
    vader_emit_c$assign(l0, vader_ref_box(l6), l5);
    if (l11 == INT32_C(17)) {
        vader_emit_c$push_temporary(l0, l6, (uint8_t) 17);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_emit_c$coerce_expr(l2, vader_ref_box(l6), (uint8_t) 17, l11);
    vader_emit_c$push_into_temporary(l0, l4, l11);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_call_result(void* l0, vader_box_t l1, uint8_t l2) {
    bool l3;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(14)) {
        l3 = true;
    } else {
        l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_drop_call_result;
    }
    if (!(l3)) {
        vader_emit_c$push_into_temporary(l0, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_call_to(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l5, l6;
    void* l4 = NULL;
    void* l10 = NULL;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    uint8_t l8;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l7, &l9, &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    t0 = vader_emit_c_ast$verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        t2 = vader_chk_sub(i64, l3, INT64_C(1));
        l6 = vader_chk_sub(i64, t2, l5);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l6, 628u);
        if (((int32_t) t0.payload.i) != INT32_C(14)) {
            l7 = vader_emit_c$pop(l0);
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            t0 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l6, 628u);
            l8 = ((uint8_t) t0.payload.i);
            l9 = vader_emit_c$coerced_as(l0, l7, l8);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            vader_array_ref_store(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6, l9.payload.obj);
            VADER_WRITE_BARRIER(_a4_slotarr->buf);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l10 = (void*) _a5_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t0 = vader_array_read_u8(_a6_slotarr, vader_array_offset(_a6_slotarr) + (size_t) l5, 628u);
        if (((int32_t) t0.payload.i) != INT32_C(14)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            l7 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l10, l7.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    t2 = vader_core_bytecode$bc_result_arity(l2);
    if (!((t2 > INT64_C(1)))) {
        l7 = vader_emit_c_ast$call(l1, l10);
        l8 = vader_core_bytecode$bc_single_result(l2);
        vader_emit_c$emit_call_result(l0, l7, l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$emit_multi_call(l0, l1, l10, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_checked_arith(void* l0, void* l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_string_t l7 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$stack_class_of(((vader_struct_vader_core_bytecode$CheckedArith_t*) l1)->f_kind);
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    t0 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) l1)->f_kind);
    l5 = vader_emit_c_ast$verbatim(t0);
    l4 = vader_emit_c$operand_as(l0, l4, l2);
    l3 = vader_emit_c$operand_as(l0, l3, l2);
    vader_array_t* _a0_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l7 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) l1)->f_op);
    t0 = concat_2(3575u, l7);
    l3 = vader_emit_c_ast$call(t0, l6);
    vader_emit_c$push_into_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_checked_neg(void* l0, void* l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$stack_class_of(((vader_struct_vader_core_bytecode$CheckedNeg_t*) l1)->f_kind);
    l3 = vader_emit_c$pop(l0);
    t0 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) l1)->f_kind);
    l4 = vader_emit_c_ast$verbatim(t0);
    l3 = vader_emit_c$operand_as(l0, l3, l2);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l4.payload.obj;
    l5 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3576u, l5);
    vader_emit_c$push_into_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_closure_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l5, l6;
    int32_t l7;
    vader_string_t l8 = 0;
    vader_string_t l11 = 0;
    vader_box_t l12 = vader_box_null();
    bool t0, t3;
    int32_t t1;
    void* t2 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l9, &l10, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_emit_c$scan_fn_value_usage(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    t0 = ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_any;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l3));
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l7 = ((int32_t) (int64_t) l5);
            l8 = vader_emit_c$fn_symbol_name(l3, l7);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
            l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_signature;
            t2 = vader_emit_c$trampoline_signature(l0, l8, l9);
            vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a3_obj, 1603u);
            _a3_obj->f_signature = t2;
            l10 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l4, l10);
            l11 = concat_2(3594u, l8);
            l12 = vader_emit_c$external(3595u, l11, vader_box_obj(0u, NULL), false);
            vader_array_push_ref((vader_array_t*) l4, l12.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l3));
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l5];
        t3 = t0;
        if (t3) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t2 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
            t4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_signature)->f_params));
            if ((t4 > INT64_C(0))) {
                l7 = ((int32_t) (int64_t) l5);
                l8 = vader_emit_c$fn_symbol_name(l3, l7);
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t2 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
                l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_signature;
                t2 = vader_emit_c$lift_signature(l0, l8, l9);
                vader_struct_vader_emit_c_ast$CPrototype_t* _a7_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
                vader_obj_header_init(_a7_obj, 1603u);
                _a7_obj->f_signature = t2;
                l10 = (void*) _a7_obj;
                vader_array_push_ref((vader_array_t*) l4, l10);
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 623u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a9_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a9_obj, 1606u);
    _a9_obj->f_comment = t2;
    _a9_obj->f_items = l4;
    l2 = (void*) _a9_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_closure_lift(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l6 = vader_box_null();
    uint8_t l7;
    vader_string_t t0 = 0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l5, &l8, &l9, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_name;
    l4 = vader_emit_c$sanitise(t0);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature;
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params));
    if (!(t1 == INT64_C(0))) {
        l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l6 = vader_emit_c_ast$verbatim(2414u);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0), 628u);
        l7 = ((uint8_t) t2.payload.i);
        t2 = vader_emit_c$coerce_expr(l5, l6, (uint8_t) 16, l7);
        vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t2.payload.obj;
        l5 = (void*) _a2_arr;
        l8 = vader_emit_c$lift_unbox_tail(((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l8);
        vader_array_t* _a3_arr = vader_array_new(487u, 0u, 13u, 2782u);
        t3 = (void*) _a3_arr;
        vader_struct_vader_emit_c_ast$CBlock_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
        vader_obj_header_init(_a4_obj, 1568u);
        _a4_obj->f_body = t3;
        l8 = (void*) _a4_obj;
        l9 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l8)->f_body;
        l5 = vader_emit_c$forward_boxed(l0, l4, l5, l3);
        vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l5);
        l3 = vader_emit_c$lift_signature(l0, l4, l3);
        vader_array_t* _a5_arr = vader_array_new(487u, 0u, 13u, 2782u);
        l5 = (void*) _a5_arr;
        vader_struct_vader_emit_c_ast$CFunction_t* _a6_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
        vader_obj_header_init(_a6_obj, 1585u);
        _a6_obj->f_signature = l3;
        _a6_obj->f_prologue = l5;
        _a6_obj->f_body = l8;
        l3 = (void*) _a6_obj;
        vader_array_push_ref((vader_array_t*) l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_convert(void* l0, uint8_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    uint8_t l4, l5;
    void* l7 = NULL;
    bool t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l3, &l6, &t1, &t2 };
    void** gc_raw_roots[2] = { &l0, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$val_of(l3);
    l5 = vader_emit_c$source_class(l4, l1, l2);
    t0 = vader_emit_c$is_ref_val(l4);
    if (t0) {
        t1 = vader_emit_c$expression_of(l3);
        l6 = vader_emit_c$unbox_expr(t1, l1);
        vader_emit_c$push_expr(l0, l1, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == l1) {
        t1 = vader_emit_c$expression_of(l3);
        l6 = vader_emit_c$signed_view(t1, l1, l2);
        vader_emit_c$push_expr(l0, l1, l6);
    } else {
        t1 = vader_emit_c$expression_of(l3);
        t2 = vader_emit_c$scalar_cast(t1, l5, l1);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a0_obj, 1600u);
        _a0_obj->f_inner = t2;
        l7 = (void*) _a0_obj;
        vader_emit_c$push_expr(l0, l1, vader_ref_box(l7));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_data_const_op(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(31));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 3580u);
    t0 = ((vader_struct_vader_core_bytecode$DataConst_t*) l1)->f_pool_index;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    t1 = std_core$finish_buffer(l2, l3);
    t2 = vader_emit_c_ast$verbatim(t1);
    l5 = vader_emit_c_ast$address_of(t2);
    vader_emit_c$push_object(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_data_global_externs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    int64_t l3, l4, l6;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    int64_t t0;
    uint8_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l10, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool));
    vader_array_t* _a0_arr = vader_array_reserve(488u, (int64_t) t0, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool));
    while ((l3 < l4)) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l5, l6, 3580u);
        l6 = std_core$write_int(l5, l6, l3);
        l7 = std_core$finish_buffer(l5, l6);
        l8 = vader_emit_c$external(3547u, l7, vader_box_obj(0u, NULL), true);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
        l3 = (l3 + INT64_C(1));
    }
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    while ((l3 < l4)) {
        l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module;
        l9 = ((int32_t) (int64_t) l3);
        t1 = vader_emit_c$global_slot_val(l5, l9);
        l7 = vader_emit_c$c_type_for_val_bare(t1);
        l10 = (void*) vader_buffer_new((size_t) INT64_C(33));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l10, l6, 3605u);
        l6 = std_core$write_int(l10, l6, l3);
        l11 = std_core$finish_buffer(l10, l6);
        l8 = vader_emit_c$external(l7, l11, vader_box_obj(0u, NULL), false);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
        l3 = (l3 + INT64_C(1));
    }
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    if ((t0 > INT64_C(0))) {
        l8 = vader_emit_c$external(3601u, 3608u, vader_box_obj(0u, NULL), false);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
    }
    t2 = (void*) &vader_data_68;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    l8 = vader_emit_c$external(3551u, 3550u, vader_ref_box(l5), true);
    vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1606u);
    _a3_obj->f_comment = t2;
    _a3_obj->f_items = l2;
    l2 = (void*) _a3_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_data_pool(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    int64_t l8, l9, l11;
    vader_box_t l10 = vader_box_null();
    vader_string_t l12 = 0;
    uint8_t l13;
    int32_t l14, l15, l16;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l17, &l18, &l19, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool));
    if (t0 == INT64_C(0)) {
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
        if (t0 == INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l3 = vader_core_bytecode$data_pool_type_ids(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module);
    t1 = vader_emit_c$has_str_data(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool);
    if (t1) {
        l4 = vader_emit_c$build_string_atom_map(l0);
    } else {
        vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
        l6 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 626u);
        l7 = (void*) _a3_arr;
        vader_struct_std_collections$Map__string__i32_t* _a4_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
        vader_obj_header_init(_a4_obj, 977u);
        _a4_obj->f_ekeys = l5;
        _a4_obj->f_evals = l6;
        _a4_obj->f_index = l7;
        _a4_obj->f_mask = INT64_C(0);
        _a4_obj->f_grow_at = INT64_C(0);
        _a4_obj->f_size = INT64_C(0);
        _a4_obj->f_tombs = INT64_C(0);
        l4 = (void*) _a4_obj;
    }
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool));
    while ((l8 < l9)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l10 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l8);
        l5 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l11 = INT64_C(0);
        l11 = std_core$write_string_at(l5, l11, 3580u);
        l11 = std_core$write_int(l5, l11, l8);
        l12 = std_core$finish_buffer(l5, l11);
        t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l13 = vader_emit_c$global_storage(t1);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        l14 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l8];
        l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l15 = l14;
        l16 = vader_emit_c$array_element_tag(l6, l15);
        vader_struct_vader_emit_c$PoolArray_t* _a7_obj = (vader_struct_vader_emit_c$PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$PoolArray_t));
        vader_obj_header_init(_a7_obj, 1554u);
        _a7_obj->f_name = l12;
        _a7_obj->f_storage = l13;
        _a7_obj->f_type_id = l14;
        _a7_obj->f_element_tag = l16;
        l7 = (void*) _a7_obj;
        if (l10.tag == 1285u) {
            l17 = l10.payload.obj;
            vader_emit_c$emit_str_data_entry(l2, l7, l17, l4);
        } else if (l10.tag == 1281u) {
            l18 = l10.payload.obj;
            vader_emit_c$emit_prim_data_entry(l2, l7, l18);
        } else {
            if (!(l10.tag == 1272u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l19 = l10.payload.obj;
            vader_emit_c$emit_agg_data_entry(l0, l2, l7, l19, l4);
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_emit_c$emit_global_slots(l0, l2);
    vader_emit_c$emit_global_roots(l0, l2);
    vader_array_t* _a8_arr = vader_array_new(28u, 3u, 0u, 623u);
    vader_array_box_slots(_a8_arr->buf)[vader_array_offset(_a8_arr) + 2u] = vader_box_string(623u, 3116u);
    vader_array_box_slots(_a8_arr->buf)[vader_array_offset(_a8_arr) + 1u] = vader_box_string(623u, 905u);
    vader_array_box_slots(_a8_arr->buf)[vader_array_offset(_a8_arr) + 0u] = vader_box_string(623u, 730u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a9_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a9_obj, 1606u);
    _a9_obj->f_comment = t2;
    _a9_obj->f_items = l2;
    l2 = (void*) _a9_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$emit_data_value(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4) {
    uint8_t l5;
    uint64_t l6;
    vader_string_t l7 = 0;
    vader_string_t l15 = 0;
    vader_string_t l19 = 0;
    void* l8 = NULL;
    void* l17 = NULL;
    int32_t l9;
    vader_box_t l10 = vader_box_null(), l14 = vader_box_null(), l20 = vader_box_null();
    int64_t l11, l12, l13, l16, l18;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null(), t3 = vader_box_null();
    int32_t t2;
    bool t4;
    vader_box_t* gc_roots[6] = { &l2, &l10, &l14, &l20, &t1, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l8, &l17, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l7, &l15, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1289u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t1 = vader_emit_c$data_slot(l5, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1290u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        t2 = vader_emit_c$atom_for(l4, l7);
        t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1291u) {
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        l9 = vader_emit_c$type_id_for_struct_symbol(l8, l9);
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l9];
        l7 = t1.payload.s;
        l7 = concat_2(3249u, l7);
        t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l9));
        t3 = vader_emit_c$object_header(t1);
        vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t3.payload.obj;
        l8 = (void*) _a1_arr;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
        if (l10.tag == 1286u) {
            l11 = INT64_C(0);
            t0 = l2.payload.obj;
            l12 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields));
            while ((l11 < l12)) {
                t0 = l10.payload.obj;
                l13 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields));
                if ((l11 < l13)) {
                    t0 = l10.payload.obj;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
                    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l11);
                    l9 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
                } else {
                    l9 = INT32_C(0);
                }
                t0 = l2.payload.obj;
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
                l14 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l11);
                l15 = l3;
                l16 = vader_host_std_core$Intrinsic$byte_len(l15);
                l17 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l16));
                l18 = INT64_C(0);
                l18 = std_core$write_string_at(l17, l18, l15);
                l18 = std_core$write_string_at(l17, l18, 1294u);
                l18 = std_core$write_int(l17, l18, l11);
                l19 = std_core$finish_buffer(l17, l18);
                l20 = vader_emit_c$struct_field_init(l0, l1, l14, l19, l9, l4);
                vader_array_push_ref((vader_array_t*) l8, l20.payload.obj);
                l11 = (l11 + INT64_C(1));
            }
        }
        t4 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l5 = vader_emit_c$global_storage(t4);
        l10 = vader_emit_c_ast$initializer_list(l8);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a5_obj, 1578u);
        _a5_obj->f_name = l3;
        _a5_obj->f_length = vader_box_obj(0u, NULL);
        _a5_obj->f_value = l10;
        l8 = (void*) _a5_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a6_obj, 1587u);
        _a6_obj->f_storage = l5;
        _a6_obj->f_constant = true;
        _a6_obj->f_type = l7;
        _a6_obj->f_declarator = l8;
        l8 = (void*) _a6_obj;
        vader_array_push_ref((vader_array_t*) l1, l8);
        l7 = concat_2(l7, 432u);
        t1 = vader_emit_c_ast$verbatim(l3);
        l10 = vader_emit_c_ast$address_of(t1);
        t1 = vader_emit_c_ast$cast(l7, l10);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1288u)) {
        t1 = vader_emit_c_ast$number(INT64_C(0));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l2.payload.obj;
    t1 = vader_emit_c$emit_nested_array(l0, l1, l8, l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$emit_defer_pop_exec(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l3 = INT64_C(0);
    t0 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) l1)->f_count;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3423u);
    t1 = std_core$finish_buffer(l2, l3);
    t2 = vader_emit_c_ast$verbatim(t1);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t2.payload.obj;
    l2 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(3583u, l2);
    vader_emit_c$evaluate(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_defer_push(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$coerced_as(l0, l1, (uint8_t) 17);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3584u, l2);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_else(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_emit_c$assert_stack_empty(l0, 2370u);
    vader_emit_c$open_else(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_end(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    int32_t l8;
    vader_string_t t0 = 0;
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l2, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(35));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 3161u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 398u);
    l5 = std_core$finish_buffer(l2, l3);
    vader_emit_c$assert_stack_empty(l0, l5);
    l6 = vader_emit_c$scope_ending_at(((vader_struct_vader_emit_c$FnState_t*) l0)->f_scopes, l1);
    if (l6.tag == 0u) {
        l7 = (void*) vader_buffer_new((size_t) INT64_C(50));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l7, l3, 2384u);
        l4 = ((int64_t) (int32_t) l1);
        l3 = std_core$write_int(l7, l3, l4);
        t0 = std_core$finish_buffer(l7, l3);
        std_abort$todo(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l6.payload.obj;
        l8 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l2)->f_opener_pc;
        vader_emit_c$pc_close_cache(l0, l8);
        l7 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_break_targets;
        l8 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l2)->f_opener_pc;
        t1 = std_core$$array$Contains$contains__i32(l7, l8);
        if (t1) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(24));
            l3 = INT64_C(0);
            l3 = std_core$write_string_at(l7, l3, 2392u);
            t2 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l2)->f_opener_pc;
            l4 = ((int64_t) (int32_t) t2);
            l3 = std_core$write_int(l7, l3, l4);
            l5 = std_core$finish_buffer(l7, l3);
            vader_emit_c$close_node(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l5 = 0u;
        vader_emit_c$close_node(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_c$emit_f32_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 8);
    l1 = vader_emit_c_ast$around(393u, l1, 313u);
    vader_emit_c$push_expr(l0, (uint8_t) 2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_f64_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 9);
    l1 = vader_emit_c_ast$around(394u, l1, 314u);
    vader_emit_c$push_expr(l0, (uint8_t) 3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_fn_addr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$new_temporary(l0, (uint8_t) 15);
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l4 = ((vader_struct_vader_core_bytecode$FnAddr_t*) l1)->f_function_index;
    t0 = vader_emit_c$fn_symbol_name(l3, l4);
    t1 = vader_emit_c_ast$verbatim(t0);
    l5 = vader_emit_c_ast$address_of(t1);
    l5 = vader_emit_c_ast$cast(3701u, l5);
    vader_emit_c$assign(l0, vader_ref_box(l2), l5);
    vader_array_t* _a0_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l3 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(3587u, l3);
    vader_emit_c$evaluate(l0, l5);
    vader_emit_c$push_temporary(l0, l2, (uint8_t) 15);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_fn_ref(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l3 = ((vader_struct_vader_core_bytecode$FnRef_t*) l1)->f_function_index;
    l4 = vader_emit_c$fn_symbol_name(l2, l3);
    t0 = concat_2(3594u, l4);
    t1 = vader_emit_c_ast$verbatim(t0);
    l5 = vader_emit_c_ast$address_of(t1);
    vader_emit_c$push_object(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_fn_ref_tramp(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null(), l10 = vader_box_null();
    uint8_t l11;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[3] = { &l6, &l10, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l7, &l8, &l9, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    l5 = vader_emit_c$sanitise(t0);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature;
    l6 = vader_emit_c_ast$verbatim(2414u);
    t1 = vader_emit_c_ast$cast(3699u, l6);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 1582u);
    _a1_obj->f_expression = t1;
    t2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(487u, 1u, 13u, 2782u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t2;
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a3_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a3_obj, 1568u);
    _a3_obj->f_body = t2;
    l7 = (void*) _a3_obj;
    l8 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l7)->f_body;
    l9 = vader_emit_c$tramp_unbox_args(((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
    l9 = vader_emit_c$forward_boxed(l0, l5, l9, l4);
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l9);
    l4 = vader_emit_c$trampoline_signature(l0, l5, l4);
    vader_array_t* _a4_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l8 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CFunction_t* _a5_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a5_obj, 1585u);
    _a5_obj->f_signature = l4;
    _a5_obj->f_prologue = l8;
    _a5_obj->f_body = l7;
    l4 = (void*) _a5_obj;
    vader_array_push_ref((vader_array_t*) l1, l4);
    t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l3));
    l6 = vader_emit_c$object_header(t1);
    t0 = concat_2(3597u, l5);
    t1 = vader_emit_c_ast$verbatim(t0);
    l10 = vader_emit_c_ast$address_of(t1);
    l10 = vader_emit_c_ast$cast(3701u, l10);
    t2 = (void*) &vader_data_70;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l4 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 2u] = l4;
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = l10.payload.obj;
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l6.payload.obj;
    t2 = (void*) _a7_arr;
    l6 = vader_emit_c_ast$initializer_list(t2);
    t3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l11 = vader_emit_c$global_storage(t3);
    t0 = concat_2(3594u, l5);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a8_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a8_obj, 1578u);
    _a8_obj->f_name = t0;
    _a8_obj->f_length = vader_box_obj(0u, NULL);
    _a8_obj->f_value = l6;
    l4 = (void*) _a8_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a9_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a9_obj, 1587u);
    _a9_obj->f_storage = l11;
    _a9_obj->f_constant = false;
    _a9_obj->f_type = 3595u;
    _a9_obj->f_declarator = l4;
    l4 = (void*) _a9_obj;
    vader_array_push_ref((vader_array_t*) l1, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_fn_sig_typedefs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l3, l4, l7;
    bool l5;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l6, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_emit_c$max_fn_arity(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
    l5 = (l3 <= l4);
    while (l5) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(42));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 3591u);
        l7 = std_core$write_int(l6, l7, l3);
        l7 = std_core$write_string_at(l6, l7, 1306u);
        l8 = std_core$finish_buffer(l6, l7);
        l9 = vader_emit_c$erased_parameters(l3);
        vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t* _a1_obj = (vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t));
        vader_obj_header_init(_a1_obj, 1586u);
        _a1_obj->f_result = 3560u;
        _a1_obj->f_name = l8;
        _a1_obj->f_parameters = l9;
        l10 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l2, l10);
        l5 = (l3 < l4);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1606u);
    _a3_obj->f_comment = t0;
    _a3_obj->f_items = l2;
    l2 = (void*) _a3_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_fn_trampolines(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3, l5;
    int32_t l6, l7;
    bool t0, t2;
    int32_t t1;
    void* t3 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$scan_fn_value_usage(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    t0 = ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_any;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions));
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l6 = ((int32_t) (int64_t) l5);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_fn_ref_type);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            l7 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5];
            vader_emit_c$emit_fn_ref_tramp(l0, l4, l6, l7);
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t0 = ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l5];
        t2 = t0;
        if (t2) {
            l6 = ((int32_t) (int64_t) l5);
            vader_emit_c$emit_closure_lift(l0, l4, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 623u);
    t3 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a5_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a5_obj, 1606u);
    _a5_obj->f_comment = t3;
    _a5_obj->f_items = l4;
    l2 = (void*) _a5_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_foreign_declarations(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    int64_t l8, l9, l15, l16;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l17 = 0;
    vader_box_t l13 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l13, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l14, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l11, &l12, &l17, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    l6 = (void*) _a2_arr;
    l7 = l1;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l10 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_is_extern;
        if (t0) {
            l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_extern_name;
            t0 = std_core$$array$Contains$contains__string(l5, l11);
            if (!(t0)) {
                l12 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_extern_name;
                vader_array_push_scalar((vader_array_t*) l5, vader_box_string(623u, l12));
                t0 = vader_emit_c$synthesises_prototype(l10);
                if (t0) {
                    l13 = vader_emit_c$extern_decl(l10, l2);
                    vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
                } else {
                    l14 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_c_headers;
                    l15 = vader_array_length(((vader_array_t*) l14));
                    l16 = INT64_C(0);
                    while ((l16 < l15)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        t1 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l16];
                        l17 = t1.payload.s;
                        t0 = std_core$$array$Contains$contains__string(l6, l17);
                        if (!(t0)) {
                            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l17));
                        }
                        l16 = (l16 + INT64_C(1));
                    }
                }
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    t2 = vader_array_length(((vader_array_t*) l6));
    vader_array_t* _a5_arr = vader_array_reserve(488u, (int64_t) t2, 13u, 2786u);
    l5 = (void*) _a5_arr;
    l8 = vader_array_length(((vader_array_t*) l6));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l9];
        t3 = t1.payload.s;
        l7 = vader_emit_c$include_of(t3);
        vader_array_push_ref((vader_array_t*) l5, l7);
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_box_string(623u, 796u);
    t4 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 1606u);
    _a8_obj->f_comment = t4;
    _a8_obj->f_items = l5;
    l5 = (void*) _a8_obj;
    vader_emit_c_ast$print_section(l0, l5);
    vader_array_t* _a9_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a9_arr->buf)[vader_array_offset(_a9_arr) + 0u] = vader_box_string(623u, 1165u);
    t4 = (void*) _a9_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a10_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a10_obj, 1606u);
    _a10_obj->f_comment = t4;
    _a10_obj->f_items = l4;
    l4 = (void*) _a10_obj;
    vader_emit_c_ast$print_section(l0, l4);
    vader_array_t* _a11_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a11_arr->buf)[vader_array_offset(_a11_arr) + 0u] = vader_box_string(623u, 1718u);
    l4 = (void*) _a11_arr;
    l5 = vader_emit_c$c_type_asserts(l1, l2);
    vader_struct_vader_emit_c_ast$CSection_t* _a12_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a12_obj, 1606u);
    _a12_obj->f_comment = l4;
    _a12_obj->f_items = l5;
    l4 = (void*) _a12_obj;
    vader_emit_c_ast$print_section(l0, l4);
    vader_array_t* _a13_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a13_arr->buf)[vader_array_offset(_a13_arr) + 0u] = vader_box_string(623u, 1714u);
    l4 = (void*) _a13_arr;
    l5 = vader_emit_c$c_struct_layout_asserts(l2, l3);
    vader_struct_vader_emit_c_ast$CSection_t* _a14_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a14_obj, 1606u);
    _a14_obj->f_comment = l4;
    _a14_obj->f_items = l5;
    l4 = (void*) _a14_obj;
    vader_emit_c_ast$print_section(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c$emit_foreign_unit(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$imports_of_unit(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, l1);
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a2_obj, 1602u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l3 = (void*) _a2_obj;
    l4 = vader_emit_c$foreign_unit_banner(l2);
    l4 = concat_2(770u, l4);
    vader_emit_c$emit_preamble(l3, l4);
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l6 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names;
    vader_emit_c$emit_mirrored_struct_typedefs(l5, l6, l3);
    vader_emit_c$emit_import_group(l0, l3, l2);
    t1 = vader_emit_c_ast$printed_text(l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$emit_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    int64_t l3, l4;
    int32_t l5, l7;
    bool l6;
    uint8_t t0;
    bool t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions));
    while ((l3 < l4)) {
        l5 = ((int32_t) (int64_t) l3);
        t0 = vader_emit_c$module_function_storage(l0, l5);
        if (t0 == INT32_C(1)) {
            l6 = true;
        } else {
            t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
            l6 = !(t1);
        }
        if (l6) {
            l7 = ((int32_t) (int64_t) l3);
            t2 = vader_emit_c$signature_for(l0, l7);
            vader_struct_vader_emit_c_ast$CPrototype_t* _a1_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a1_obj, 1603u);
            _a1_obj->f_signature = t2;
            l8 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l2, l8);
        }
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1606u);
    _a3_obj->f_comment = t2;
    _a3_obj->f_items = l2;
    l2 = (void*) _a3_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_global_get(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    uint8_t l4;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module;
    l3 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) l1)->f_index;
    l4 = vader_emit_c$global_slot_val(l2, l3);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(33));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l2, l5, 3605u);
    t0 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) l1)->f_index;
    l6 = ((int64_t) (int32_t) t0);
    l5 = std_core$write_int(l2, l5, l6);
    t1 = std_core$finish_buffer(l2, l5);
    l7 = vader_emit_c_ast$verbatim(t1);
    vader_emit_c$push_into_temporary(l0, l7, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_global_roots(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    uint8_t l10;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[5] = { &l6, &l7, &l8, &l9, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_emit_c$global_slot_addresses(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, (uint8_t) 17);
    l3 = vader_emit_c$global_slot_addresses(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, (uint8_t) 16);
    l4 = vader_emit_c$global_slot_addresses(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, (uint8_t) 12);
    t1 = (void*) &vader_data_70;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t0 = vader_array_length(((vader_array_t*) l2));
    l6 = vader_emit_c_ast$unsigned(t0);
    t0 = vader_array_length(((vader_array_t*) l3));
    l7 = vader_emit_c_ast$unsigned(t0);
    l8 = vader_emit_c$root_list(l1, 3561u, 3607u, l2);
    l9 = vader_emit_c$root_list(l1, 3702u, 3609u, l3);
    t1 = (void*) &vader_data_69;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    t1 = (void*) &vader_data_70;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a3_arr = vader_array_new(486u, 7u, 13u, 2777u);
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 6u] = l3;
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 5u] = l2;
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 4u] = l9.payload.obj;
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 3u] = l8.payload.obj;
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 2u] = l7.payload.obj;
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 1u] = l6.payload.obj;
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = l5;
    l2 = (void*) _a3_arr;
    t0 = vader_array_length(((vader_array_t*) l4));
    if ((t0 > INT64_C(0))) {
        l6 = vader_emit_c$root_list(l1, 3658u, 3606u, l4);
        t0 = vader_array_length(((vader_array_t*) l4));
        t2 = vader_emit_c_ast$unsigned(t0);
        vader_array_t* _a4_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l6.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = t2.payload.obj;
        l3 = (void*) _a4_arr;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
    }
    t3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l10 = vader_emit_c$global_storage(t3);
    l6 = vader_emit_c_ast$initializer_list(l2);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a5_obj, 1578u);
    _a5_obj->f_name = 3608u;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l6;
    l2 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a6_obj, 1587u);
    _a6_obj->f_storage = l10;
    _a6_obj->f_constant = false;
    _a6_obj->f_type = 3601u;
    _a6_obj->f_declarator = l2;
    l2 = (void*) _a6_obj;
    vader_array_push_ref((vader_array_t*) l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_global_set(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l7;
    uint8_t l8;
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l2, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(33));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 3605u);
    t0 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) l1)->f_index;
    l5 = ((int64_t) (int32_t) t0);
    l4 = std_core$write_int(l3, l4, l5);
    t1 = std_core$finish_buffer(l3, l4);
    l6 = vader_emit_c_ast$verbatim(t1);
    l3 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module;
    l7 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) l1)->f_index;
    l8 = vader_emit_c$global_slot_val(l3, l7);
    l2 = vader_emit_c$coerced_as(l0, l2, l8);
    vader_emit_c$assign(l0, l6, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_global_slots(void* l0, void* l1) {
    int64_t l2, l3, l10;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int32_t l5;
    uint8_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l11 = 0;
    vader_box_t l12 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l9, &l13, &l14 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module;
        l5 = ((int32_t) (int64_t) l2);
        l6 = vader_emit_c$global_slot_val(l4, l5);
        t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l7 = vader_emit_c$global_storage(t0);
        l8 = vader_emit_c$c_type_for_val_bare(l6);
        l9 = (void*) vader_buffer_new((size_t) INT64_C(33));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 3605u);
        l10 = std_core$write_int(l9, l10, l2);
        l11 = std_core$finish_buffer(l9, l10);
        l12 = vader_emit_c$zero_of(l6);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a0_obj, 1578u);
        _a0_obj->f_name = l11;
        _a0_obj->f_length = vader_box_obj(0u, NULL);
        _a0_obj->f_value = l12;
        l13 = (void*) _a0_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a1_obj, 1587u);
        _a1_obj->f_storage = l7;
        _a1_obj->f_constant = false;
        _a1_obj->f_type = l8;
        _a1_obj->f_declarator = l13;
        l14 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l1, l14);
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_if_open(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    vader_emit_c$assert_stack_empty(l0, 2688u);
    l1 = vader_emit_c$expression_of(l1);
    vader_emit_c$open_if(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_import_group(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l5, l6;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l4 = vader_emit_c$mirror_crossings(l2, l3);
    vader_emit_c$emit_foreign_declarations(l1, l2, l3, l4);
    t0 = vader_array_length(((vader_array_t*) l2));
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_struct_vader_emit_c_ast$CPragma_t* _a0_obj = (vader_struct_vader_emit_c_ast$CPragma_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPragma_t));
    vader_obj_header_init(_a0_obj, 1601u);
    _a0_obj->f_text = 769u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CPragma_t* _a1_obj = (vader_struct_vader_emit_c_ast$CPragma_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPragma_t));
    vader_obj_header_init(_a1_obj, 1601u);
    _a1_obj->f_text = 767u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(488u, 2u, 13u, 2786u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3;
    l3 = (void*) _a2_arr;
    l4 = l2;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_is_extern;
        if (t1) {
            t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_blocking;
            if (t1) {
                l8 = vader_emit_c$relay_declarations(l0, l7);
                vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
            }
        }
        l9 = vader_emit_c$import_shim(l0, l7);
        vader_array_push_ref((vader_array_t*) l3, l9);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_emit_c_ast$CPragma_t* _a4_obj = (vader_struct_vader_emit_c_ast$CPragma_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPragma_t));
    vader_obj_header_init(_a4_obj, 1601u);
    _a4_obj->f_text = 768u;
    l4 = (void*) _a4_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 623u);
    t2 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1606u);
    _a6_obj->f_comment = t2;
    _a6_obj->f_items = l3;
    l3 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_import_shims(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    int64_t l4, l5;
    bool l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l7, &l11, &l12, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    if (t0) {
        l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names;
        vader_emit_c$emit_mirrored_struct_typedefs(l2, l3, l1);
    }
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_library_units;
    if (!(t0)) {
        l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_imports;
        vader_emit_c$emit_import_group(l0, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_emit_c$imports_of_unit(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, 0u);
    vader_emit_c$emit_import_group(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_imports;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        t1 = vader_emit_c$foreign_unit_of(l6);
        if (t1 != 0u) {
            l7 = vader_emit_c$shim_signature(l0, l6);
            l8 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_inline;
            l9 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_result;
            l10 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_name;
            l11 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_parameters;
            vader_struct_vader_emit_c_ast$CSignature_t* _a2_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
            vader_obj_header_init(_a2_obj, 1608u);
            _a2_obj->f_storage = (uint8_t) 2;
            _a2_obj->f_inline = l8;
            _a2_obj->f_result = l9;
            _a2_obj->f_name = l10;
            _a2_obj->f_parameters = l11;
            t2 = (void*) _a2_obj;
            vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a3_obj, 1603u);
            _a3_obj->f_signature = t2;
            l12 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l2, l12);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = vader_box_string(623u, 996u);
    t2 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a5_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a5_obj, 1606u);
    _a5_obj->f_comment = t2;
    _a5_obj->f_items = l2;
    l2 = (void*) _a5_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_internal_forward_decls(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    int32_t l7;
    uint8_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l3 = (void*) _a0_arr;
    l4 = l1;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        t0 = vader_emit_c$module_function_storage(l0, l7);
        if (t0 == INT32_C(0)) {
            t1 = vader_emit_c$signature_for(l0, l7);
            vader_struct_vader_emit_c_ast$CPrototype_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a2_obj, 1603u);
            _a2_obj->f_signature = t1;
            l8 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l8);
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 623u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 1606u);
    _a4_obj->f_comment = t1;
    _a4_obj->f_items = l3;
    l3 = (void*) _a4_obj;
    vader_emit_c_ast$print_section(l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_local_decls(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    int64_t l7, l10, l11, l14, l15;
    uint8_t l12;
    vader_string_t l16 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &l9, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params));
    vader_array_t* _a0_arr = vader_array_new(31u, 0u, 1u, 628u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    l9 = (void*) _a1_arr;
    l10 = INT64_C(0);
    l11 = vader_array_length(((vader_array_t*) l6));
    while ((l10 < l11)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l10);
        if (((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val == INT32_C(14)) {
            l10 = (l10 + INT64_C(1));
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l10);
        l12 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val;
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
        l13 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l13, l14, 2812u);
        l15 = vader_chk_add(i64, l7, l10);
        l14 = std_core$write_int(l13, l14, l15);
        l16 = std_core$finish_buffer(l13, l14);
        vader_array_push_scalar((vader_array_t*) l9, vader_box_string(623u, l16));
        l10 = (l10 + INT64_C(1));
    }
    vader_emit_c$emit_slot_decls(l1, l8, l9, l2, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_local_field(void* l0, void* l1) {
    int32_t l2, l3, l6;
    void* l4 = NULL;
    void* l5 = NULL;
    uint8_t l7;
    int32_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$LocalField_t*) l1)->f_type_id;
    l3 = ((vader_struct_vader_core_bytecode$LocalField_t*) l1)->f_field_index;
    t0 = ((vader_struct_vader_core_bytecode$LocalField_t*) l1)->f_slot;
    vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
    vader_obj_header_init(_a0_obj, 1594u);
    _a0_obj->f_slot = t0;
    l4 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function;
    l6 = ((vader_struct_vader_core_bytecode$LocalField_t*) l1)->f_slot;
    l7 = vader_core_bytecode$slot_val_type(l5, l6);
    vader_emit_c$push_struct_field(l0, l2, l3, vader_ref_box(l4), l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_local_get(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    uint8_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function;
    l3 = ((vader_struct_vader_core_bytecode$LocalGet_t*) l1)->f_slot;
    l4 = vader_core_bytecode$slot_val_type(l2, l3);
    if (!(l4 == INT32_C(14))) {
        l3 = ((vader_struct_vader_core_bytecode$LocalGet_t*) l1)->f_slot;
        vader_emit_c$push_local_ref(l0, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_local_set(void* l0, int32_t l1, bool l2) {
    uint8_t l3;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_bytecode$slot_val_type(((vader_struct_vader_emit_c$FnState_t*) l0)->f_function, l1);
    if (l3 == INT32_C(14)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$materialize_stack_for_slot(l0, l1);
    l4 = vader_emit_c$pop(l0);
    vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
    vader_obj_header_init(_a0_obj, 1594u);
    _a0_obj->f_slot = l1;
    l5 = (void*) _a0_obj;
    l4 = vader_emit_c$coerced_as(l0, l4, l3);
    vader_emit_c$assign(l0, vader_ref_box(l5), l4);
    if (l2) {
        vader_emit_c$push_local_ref(l0, l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_main(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CParameter_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a0_obj, 1599u);
    _a0_obj->f_type = 2728u;
    _a0_obj->f_name = 2006u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a1_obj, 1599u);
    _a1_obj->f_type = 2233u;
    _a1_obj->f_name = 2010u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(272u, 2u, 13u, 1599u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3;
    l3 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 1608u);
    _a3_obj->f_storage = (uint8_t) 1;
    _a3_obj->f_inline = false;
    _a3_obj->f_result = 2728u;
    _a3_obj->f_name = 2870u;
    _a3_obj->f_parameters = l3;
    l3 = (void*) _a3_obj;
    t0 = vader_emit_c$main_body(l0, l2);
    vader_struct_vader_emit_c_ast$CBlock_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a4_obj, 1568u);
    _a4_obj->f_body = t0;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l5 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CFunction_t* _a6_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a6_obj, 1585u);
    _a6_obj->f_signature = l3;
    _a6_obj->f_prologue = l5;
    _a6_obj->f_body = l4;
    l3 = (void*) _a6_obj;
    vader_emit_c_ast$print_item(l1, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_make_closure(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l7 = 0;
    int32_t l5;
    void* l6 = NULL;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l4, &l8, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l7, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$aux(l0, 2242u);
    l4 = vader_emit_c$gc_allocation(3595u);
    vader_emit_c$declare(l0, 3596u, l3, l4);
    l5 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l1)->f_env_type_id;
    vader_emit_c$init_object_header(l0, l3, l5);
    t0 = concat_2(l3, 487u);
    l4 = vader_emit_c_ast$verbatim(t0);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l5 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l1)->f_function_index;
    l7 = vader_emit_c$fn_symbol_name(l6, l5);
    t0 = concat_2(3592u, l7);
    t1 = vader_emit_c_ast$verbatim(t0);
    l8 = vader_emit_c_ast$address_of(t1);
    l8 = vader_emit_c_ast$cast(3701u, l8);
    vader_emit_c$assign(l0, l4, l8);
    t0 = concat_2(l3, 489u);
    l4 = vader_emit_c_ast$verbatim(t0);
    l2 = vader_emit_c$object_pointer_of(l2);
    vader_emit_c$assign(l0, l4, l2);
    l2 = vader_emit_c_ast$verbatim(l3);
    vader_emit_c$push_object(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_memory_copy(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    l5 = vader_emit_c$buffer_pointer(t0);
    l4 = vader_emit_c$as_size(l4);
    l3 = vader_emit_c$buffer_pointer(l3);
    l2 = vader_emit_c$as_size(l2);
    l1 = vader_emit_c$as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(486u, 5u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3567u, l6);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_mirrored_struct_typedefs(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l0));
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        if (l7.tag == 1286u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            if (t1 != 0u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l5];
                t1 = t2.payload.s;
                vader_struct_vader_emit_c_ast$CStructForward_t* _a4_obj = (vader_struct_vader_emit_c_ast$CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructForward_t));
                vader_obj_header_init(_a4_obj, 1612u);
                _a4_obj->f_name = t1;
                l8 = (void*) _a4_obj;
                vader_array_push_ref((vader_array_t*) l3, l8);
                l9 = l7.payload.obj;
                l10 = vader_emit_c$struct_definition(l0, l1, l9, l5);
                vader_array_push_ref((vader_array_t*) l4, l10);
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1606u);
    _a6_obj->f_comment = t0;
    _a6_obj->f_items = l3;
    l3 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l2, l3);
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 1606u);
    _a8_obj->f_comment = t0;
    _a8_obj->f_items = l4;
    l3 = (void*) _a8_obj;
    vader_emit_c_ast$print_section(l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_multi_call(void* l0, vader_string_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    int64_t l6, l7;
    uint8_t l8;
    vader_box_t l10 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_results;
    t0 = vader_array_length(((vader_array_t*) l4));
    vader_array_t* _a0_arr = vader_array_reserve(273u, (int64_t) t0, 13u, 1614u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l4));
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l6, 628u);
        l8 = ((uint8_t) t1.payload.i);
        l9 = vader_emit_c$new_temporary(l0, l8);
        vader_array_push_ref((vader_array_t*) l5, l9);
        l10 = vader_emit_c_ast$address_of(vader_ref_box(l9));
        vader_array_push_ref((vader_array_t*) l2, l10.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    l10 = vader_emit_c_ast$call(l1, l2);
    vader_emit_c$evaluate(l0, l10);
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l4));
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l6, 628u);
        l8 = ((uint8_t) t1.payload.i);
        vader_emit_c$push_temporary(l0, l9, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_multi_return(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l11 = NULL;
    int64_t l2, l4, l6;
    vader_string_t l3 = 0;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    uint8_t l9;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l7, &l8, &l10, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_signature)->f_results;
    l2 = vader_array_length(((vader_array_t*) l1));
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    if ((t0 < l2)) {
        l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
        l3 = concat_2(3483u, l3);
        vader_emit_c$unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a0_arr = vader_array_reserve(266u, (int64_t) l4, 13u, 1566u);
    l5 = (void*) _a0_arr;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        t0 = vader_chk_sub(i64, l2, INT64_C(1));
        l6 = vader_chk_sub(i64, t0, l4);
        l7 = vader_emit_c$pop(l0);
        l3 = vader_emit_c$out_param_name(l6);
        t1 = concat_2(432u, l3);
        l8 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l6, 628u);
        l9 = ((uint8_t) t2.payload.i);
        l10 = vader_emit_c$coerced_as(l0, l7, l9);
        vader_struct_vader_emit_c_ast$CAssign_t* _a2_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a2_obj, 1566u);
        _a2_obj->f_target = l8;
        _a2_obj->f_value = l10;
        _a2_obj->f_operator = vader_box_obj(0u, NULL);
        l11 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l5, l11);
        l4 = (l4 + INT64_C(1));
    }
    vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a3_obj, 1604u);
    _a3_obj->f_stores = l5;
    _a3_obj->f_value = vader_box_obj(0u, NULL);
    _a3_obj->f_snapshot_type = 0u;
    _a3_obj->f_pops_frame = false;
    l1 = (void*) _a3_obj;
    vader_emit_c$return_statement(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    uint8_t l5, l6;
    int32_t l7, l9;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    int64_t l11, l12, l15, l17;
    vader_box_t l13 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l18 = 0;
    uint64_t l20;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l13, &l19, &l21, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l8, &l10, &l16, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l14, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_emit_c$element_storage_kind(((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_elements);
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l6 = vader_emit_c$global_storage(t0);
    l7 = ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_type_id;
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l9 = ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_type_id;
    l9 = vader_emit_c$array_element_tag(l8, l9);
    vader_struct_vader_emit_c$PoolArray_t* _a0_obj = (vader_struct_vader_emit_c$PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$PoolArray_t));
    vader_obj_header_init(_a0_obj, 1554u);
    _a0_obj->f_name = l3;
    _a0_obj->f_storage = l6;
    _a0_obj->f_type_id = l7;
    _a0_obj->f_element_tag = l9;
    l8 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l10 = (void*) _a1_arr;
    l11 = INT64_C(0);
    l12 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_elements));
    while ((l11 < l12)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        l13 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l11);
        if (l5 == INT32_C(0)) {
            l14 = l3;
            l15 = vader_host_std_core$Intrinsic$byte_len(l14);
            l16 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l15));
            l17 = INT64_C(0);
            l17 = std_core$write_string_at(l16, l17, l14);
            l17 = std_core$write_string_at(l16, l17, 1309u);
            l17 = std_core$write_int(l16, l17, l11);
            l18 = std_core$finish_buffer(l16, l17);
            l19 = vader_emit_c$box_slot_1(l0, l1, l13, l18, l4);
            vader_array_push_ref((vader_array_t*) l10, l19.payload.obj);
        } else if (l13.tag == 1289u) {
            t1 = l13.payload.obj;
            l20 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_bits;
            l21 = vader_emit_c$data_slot(l5, l20);
            vader_array_push_ref((vader_array_t*) l10, l21.payload.obj);
        }
        l11 = (l11 + INT64_C(1));
    }
    l14 = vader_emit_c$c_type_for_array_kind(l5);
    vader_emit_c$push_pool_array(l1, l8, l14, l5, l10);
    t2 = vader_emit_c_ast$verbatim(l3);
    l13 = vader_emit_c_ast$address_of(t2);
    t2 = vader_emit_c_ast$cast(3548u, l13);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$emit_op(void* l0, int32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_string_t l6 = 0;
    uint8_t l7;
    bool l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_emit_c$invalidate_header_cache(l0, l2);
    if (l2.tag == 1345u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1365u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1324u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1296u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1311u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1397u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1438u) {
        l4 = vader_emit_c$void_box(((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx);
        vader_emit_c$push_lit(l0, (uint8_t) 17, l4);
    } else if (l2.tag == 1414u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1390u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_local_get(l0, l3);
    } else if (l2.tag == 1391u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        vader_emit_c$emit_local_set(l0, l5, false);
    } else if (l2.tag == 1392u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        vader_emit_c$emit_local_set(l0, l5, true);
    } else if (l2.tag == 1389u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_local_field(l0, l3);
    } else if (l2.tag == 1402u) {
        vader_emit_c$emit_return(l0);
    } else if (l2.tag == 1403u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_c$emit_return_lit(l0, l4);
    } else if (l2.tag == 1319u) {
        vader_emit_c$drop_top(l0);
    } else if (l2.tag == 1308u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call(l0, l3);
    } else if (l2.tag == 1309u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call_import(l0, l3);
    } else if (l2.tag == 1310u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call_indirect(l0, l3);
    } else if (l2.tag == 1437u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_virtual_call(l0, l3);
    } else if (l2.tag == 1337u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_fn_ref(l0, l3);
    } else if (l2.tag == 1336u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_fn_addr(l0, l3);
    } else if (l2.tag == 1394u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_make_closure(l0, l3);
    } else if (l2.tag == 1380u) {
        vader_emit_c$emit_if_open(l0);
    } else if (l2.tag == 1320u) {
        vader_emit_c$emit_else(l0);
    } else if (l2.tag == 1321u) {
        vader_emit_c$emit_end(l0, l1);
    } else if (l2.tag == 1294u) {
        vader_emit_c$emit_open_scope(l0, l1, (uint8_t) 0);
    } else if (l2.tag == 1393u) {
        vader_emit_c$emit_open_scope(l0, l1, (uint8_t) 1);
    } else if (l2.tag == 1301u) {
        vader_emit_c$emit_branch(l0, l1, false);
    } else if (l2.tag == 1302u) {
        vader_emit_c$emit_branch(l0, l1, true);
    } else if (l2.tag == 1299u) {
        vader_emit_c$push_unop(l0, 315u, (uint8_t) 10);
    } else if (l2.tag == 1418u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_new(l0, l3);
    } else if (l2.tag == 1417u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_get(l0, l3);
    } else if (l2.tag == 1419u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_set(l0, l3);
    } else if (l2.tag == 1434u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_union_field_get(l0, l3);
    } else if (l2.tag == 1435u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_union_field_set(l0, l3);
    } else if (l2.tag == 1264u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_new(l0, l3);
    } else if (l2.tag == 1263u) {
        vader_emit_c$emit_array_len(l0);
    } else if (l2.tag == 1265u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_push(l0, l3);
    } else if (l2.tag == 1262u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_get(l0, l3);
    } else if (l2.tag == 1270u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_set(l0, l3);
    } else if (l2.tag == 1271u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_slice(l0, l3);
    } else if (l2.tag == 1269u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_reserve(l0, l3);
    } else if (l2.tag == 1268u) {
        vader_emit_c$emit_array_repeat(l0);
    } else if (l2.tag == 1266u) {
        vader_emit_c$emit_array_push_all(l0);
    } else if (l2.tag == 1261u) {
        vader_emit_c$emit_array_copy(l0);
    } else if (l2.tag == 1267u) {
        vader_emit_c$emit_array_remove_last(l0);
    } else if (l2.tag == 1260u) {
        vader_emit_c$emit_array_clear(l0);
    } else if (l2.tag == 1315u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_data_const_op(l0, l3);
    } else if (l2.tag == 1338u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_global_get(l0, l3);
    } else if (l2.tag == 1339u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_global_set(l0, l3);
    } else if (l2.tag == 1421u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_type_const(l0, l3);
    } else if (l2.tag == 1420u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_type_check(l0, l3);
    } else if (l2.tag == 1398u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_ref_cast(l0, l3);
    } else if (l2.tag == 1401u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_retag_op(l0, l3);
    } else if (l2.tag == 1436u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
        vader_emit_c$unreachable(l0, l6);
    } else if (l2.tag == 1314u) {
        t0 = l2.payload.obj;
        l7 = vader_emit_c$convert_target_val(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        vader_emit_c$emit_convert(l0, l7, l6);
    } else if (l2.tag == 1404u) {
        vader_emit_c$emit_size_of_type(l0);
    } else if (l2.tag == 1312u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_checked_arith(l0, l3);
    } else if (l2.tag == 1313u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_checked_neg(l0, l3);
    } else if (l2.tag == 1340u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 2);
    } else if (l2.tag == 1359u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 2);
    } else if (l2.tag == 1353u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 2);
    } else if (l2.tag == 1346u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 2);
    } else if (l2.tag == 1352u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 2);
    } else if (l2.tag == 1355u) {
        vader_emit_c$push_unop(l0, 479u, (uint8_t) 2);
    } else if (l2.tag == 1342u) {
        vader_emit_c$push_unop(l0, 3790u, (uint8_t) 2);
    } else if (l2.tag == 1341u) {
        vader_emit_c$push_binop(l0, (uint8_t) 13, (uint8_t) 2);
    } else if (l2.tag == 1343u) {
        vader_emit_c$push_binop(l0, (uint8_t) 15, (uint8_t) 2);
    } else if (l2.tag == 1344u) {
        vader_emit_c$push_binop(l0, (uint8_t) 14, (uint8_t) 2);
    } else if (l2.tag == 1356u) {
        vader_emit_c$push_shift(l0, (uint8_t) 5, (uint8_t) 2);
    } else if (l2.tag == 1357u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 2);
    } else if (l2.tag == 1358u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 6);
    } else if (l2.tag == 1347u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 2);
    } else if (l2.tag == 1354u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 2);
    } else if (l2.tag == 1351u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 2);
    } else if (l2.tag == 1350u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 2);
    } else if (l2.tag == 1349u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 2);
    } else if (l2.tag == 1348u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 2);
    } else if (l2.tag == 1360u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 3);
    } else if (l2.tag == 1379u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 3);
    } else if (l2.tag == 1373u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 3);
    } else if (l2.tag == 1366u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 3);
    } else if (l2.tag == 1372u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 3);
    } else if (l2.tag == 1375u) {
        vader_emit_c$push_i64_neg(l0);
    } else if (l2.tag == 1361u) {
        vader_emit_c$push_binop(l0, (uint8_t) 13, (uint8_t) 3);
    } else if (l2.tag == 1363u) {
        vader_emit_c$push_binop(l0, (uint8_t) 15, (uint8_t) 3);
    } else if (l2.tag == 1364u) {
        vader_emit_c$push_binop(l0, (uint8_t) 14, (uint8_t) 3);
    } else if (l2.tag == 1362u) {
        vader_emit_c$push_unop(l0, 3790u, (uint8_t) 3);
    } else if (l2.tag == 1376u) {
        vader_emit_c$push_shift(l0, (uint8_t) 5, (uint8_t) 3);
    } else if (l2.tag == 1377u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 3);
    } else if (l2.tag == 1378u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 7);
    } else if (l2.tag == 1367u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 3);
    } else if (l2.tag == 1374u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 3);
    } else if (l2.tag == 1371u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 3);
    } else if (l2.tag == 1370u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 3);
    } else if (l2.tag == 1369u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 3);
    } else if (l2.tag == 1368u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 3);
    } else if (l2.tag == 1422u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 6);
    } else if (l2.tag == 1427u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 6);
    } else if (l2.tag == 1426u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 6);
    } else if (l2.tag == 1425u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 6);
    } else if (l2.tag == 1424u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 6);
    } else if (l2.tag == 1423u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 6);
    } else if (l2.tag == 1428u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 7);
    } else if (l2.tag == 1433u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 7);
    } else if (l2.tag == 1432u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 7);
    } else if (l2.tag == 1431u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 7);
    } else if (l2.tag == 1430u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 7);
    } else if (l2.tag == 1429u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 7);
    } else if (l2.tag == 1323u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 9);
    } else if (l2.tag == 1334u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 9);
    } else if (l2.tag == 1331u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 9);
    } else if (l2.tag == 1325u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 9);
    } else if (l2.tag == 1333u) {
        vader_emit_c$push_unop(l0, 479u, (uint8_t) 9);
    } else if (l2.tag == 1326u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 9);
    } else if (l2.tag == 1332u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 9);
    } else if (l2.tag == 1330u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 9);
    } else if (l2.tag == 1329u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 9);
    } else if (l2.tag == 1328u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 9);
    } else if (l2.tag == 1327u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 9);
    } else if (l2.tag == 1297u) {
        vader_emit_c$push_binop(l0, (uint8_t) 11, (uint8_t) 10);
    } else if (l2.tag == 1298u) {
        vader_emit_c$push_binop(l0, (uint8_t) 12, (uint8_t) 10);
    } else if (l2.tag == 1295u) {
        vader_emit_c$push_binop(l0, (uint8_t) 16, (uint8_t) 10);
    } else if (l2.tag == 1300u) {
        vader_emit_c$push_binop(l0, (uint8_t) 17, (uint8_t) 10);
    } else if (l2.tag == 1415u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 1416u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 1413u) {
        vader_emit_c$emit_string_compare(l0);
    } else if (l2.tag == 1399u) {
        vader_emit_c$push_binop_any(l0, (uint8_t) 11, (uint8_t) 10);
    } else if (l2.tag == 1400u) {
        vader_emit_c$push_binop_any(l0, (uint8_t) 12, (uint8_t) 10);
    } else if (l2.tag == 1318u) {
        vader_emit_c$emit_defer_push(l0);
    } else if (l2.tag == 1317u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_defer_pop_exec(l0, l3);
    } else if (l2.tag == 1303u) {
        vader_emit_c$emit_buffer_new(l0);
    } else if (l2.tag == 1388u) {
        vader_emit_c$emit_buffer_load(l0, 3566u, (uint8_t) 2);
    } else if (l2.tag == 1383u) {
        vader_emit_c$emit_buffer_load(l0, 3564u, (uint8_t) 2);
    } else if (l2.tag == 1384u) {
        vader_emit_c$emit_buffer_load(l0, 3565u, (uint8_t) 3);
    } else if (l2.tag == 1382u) {
        vader_emit_c$emit_buffer_load(l0, 3563u, (uint8_t) 9);
    } else if (l2.tag == 1412u) {
        vader_emit_c$emit_buffer_store(l0, 3572u, 3453u);
    } else if (l2.tag == 1407u) {
        vader_emit_c$emit_buffer_store(l0, 3570u, 2730u);
    } else if (l2.tag == 1408u) {
        vader_emit_c$emit_buffer_store(l0, 3571u, 2731u);
    } else if (l2.tag == 1406u) {
        vader_emit_c$emit_buffer_store(l0, 3569u, 2352u);
    } else if (l2.tag == 1386u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2730u, (uint8_t) 2, l8);
    } else if (l2.tag == 1387u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2731u, (uint8_t) 3, l8);
    } else if (l2.tag == 1385u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2352u, (uint8_t) 9, l8);
    } else if (l2.tag == 1410u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2730u, (uint8_t) 2, l8);
    } else if (l2.tag == 1411u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2731u, (uint8_t) 3, l8);
    } else if (l2.tag == 1409u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2352u, (uint8_t) 9, l8);
    } else if (l2.tag == 1396u) {
        vader_emit_c$emit_memory_copy(l0);
    } else if (l2.tag == 1304u) {
        vader_emit_c$emit_buffer_to_string(l0);
    } else if (l2.tag == 1305u) {
        vader_emit_c$emit_buffer_write_string(l0);
    } else if (l2.tag == 1335u) {
        vader_emit_c$emit_f64_to_bits(l0);
    } else if (l2.tag == 1293u) {
        vader_emit_c$emit_bits_to_f64(l0);
    } else if (l2.tag == 1322u) {
        vader_emit_c$emit_f32_to_bits(l0);
    } else {
        if (!(l2.tag == 1292u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_emit_c$emit_bits_to_f32(l0);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_open_scope(void* l0, int32_t l1, uint8_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    bool l9;
    int32_t l10, l11;
    uint8_t l12;
    int32_t t0, t1, t2;
    uint8_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[4] = { &l0, &l3, &l8, &t4 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) vader_buffer_new((size_t) INT64_C(36));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 3162u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 398u);
    l6 = std_core$finish_buffer(l3, l4);
    vader_emit_c$assert_stack_empty(l0, l6);
    if (l2 == INT32_C(1)) {
        vader_emit_c$pc_plan_for_loop(l0, l1, &t0, &t1, &t2, &t3);
        l12 = t3;
        l11 = t2;
        l10 = t1;
        if (t0 == INT32_C(0)) {
            l7 = vader_box_obj(0u, NULL);
        } else {
            vader_struct_vader_emit_c$PushCache_t* _a0_obj = (vader_struct_vader_emit_c$PushCache_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$PushCache_t));
            vader_obj_header_init(_a0_obj, 1555u);
            _a0_obj->f_opener_pc = l10;
            _a0_obj->f_slot = l11;
            _a0_obj->f_kind = l12;
            t4 = (void*) _a0_obj;
            l7 = vader_ref_box(t4);
        }
        if (!(l7.tag == 0u)) {
            l3 = l7.payload.obj;
            vader_emit_c$pc_emit_preheader(l0, l3);
            l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches;
            l8 = l7.payload.obj;
            vader_array_push_ref((vader_array_t*) l3, l8);
        }
    }
    if (l2 == INT32_C(1)) {
        l9 = std_core$$array$Contains$contains__i32(((vader_struct_vader_emit_c$FnState_t*) l0)->f_continue_targets, l1);
    } else {
        l9 = false;
    }
    if (l9) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(25));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2854u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        vader_emit_c$open_scope(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = 0u;
    vader_emit_c$open_scope(l0, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_preamble(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(623u, l1);
    l2 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CInclude_t* _a1_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a1_obj, 1590u);
    _a1_obj->f_path = 3507u;
    _a1_obj->f_system = false;
    l3 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a2_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a2_obj, 1590u);
    _a2_obj->f_path = 3215u;
    _a2_obj->f_system = true;
    l4 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a3_obj, 1590u);
    _a3_obj->f_path = 3216u;
    _a3_obj->f_system = true;
    l5 = (void*) _a3_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a4_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a4_obj, 1590u);
    _a4_obj->f_path = 3242u;
    _a4_obj->f_system = true;
    l6 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(488u, 4u, 13u, 2786u);
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 3u] = l6;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 2u] = l5;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l4;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = l3;
    l3 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1606u);
    _a6_obj->f_comment = l2;
    _a6_obj->f_items = l3;
    l2 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_prim_data_entry(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    uint64_t l7;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    uint8_t l10;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_items));
    vader_array_t* _a0_arr = vader_array_reserve(486u, (int64_t) t0, 13u, 2777u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_items;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        l7 = (uint64_t) (int64_t) t0;
        l8 = vader_emit_c$data_slot(((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_kind, l7);
        vader_array_push_ref((vader_array_t*) l3, l8.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    l9 = vader_emit_c$c_type_for_array_kind(((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_kind);
    l10 = ((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_kind;
    vader_emit_c$push_pool_array(l0, l1, l9, l10, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_ref_cast(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    uint8_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l4 = ((vader_struct_vader_core_bytecode$RefCast_t*) l1)->f_type_id;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
    l5 = vader_emit_c$val_type_of_bc_type(t0);
    l2 = vader_emit_c$coerced_as(l0, l2, l5);
    vader_emit_c$push_into_temporary(l0, l2, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_retag_op(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    uint8_t l4;
    int32_t l5;
    uint8_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$val_of(l2);
    if (t0 == INT32_C(17)) {
        l3 = vader_emit_c$expression_of(l2);
        vader_emit_c$push_into_temporary(l0, l3, (uint8_t) 17);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_emit_c$val_of(l2);
    if (t0 == INT32_C(16)) {
        t1 = vader_emit_c$expression_of(l2);
        l3 = vader_emit_c$ref_box(t1);
        vader_emit_c$push_into_temporary(l0, l3, (uint8_t) 17);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_emit_c$expression_of(l2);
    l4 = vader_emit_c$val_of(l2);
    l5 = ((vader_struct_vader_core_bytecode$Retag_t*) l1)->f_type_id;
    l3 = vader_emit_c$box_expr(l3, l4, l5);
    if (!(l2.tag == 1559u)) {
        vader_emit_c$push_expr(l0, (uint8_t) 17, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$push_lit(l0, (uint8_t) 17, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_return(void* l0) {
    uint8_t l1;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_signature);
    if ((t0 > INT64_C(1))) {
        vader_emit_c$emit_multi_return(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_signature);
    if (l1 == INT32_C(14)) {
        vader_array_t* _a0_arr = vader_array_new(266u, 0u, 13u, 1566u);
        t1 = (void*) _a0_arr;
        vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a1_obj, 1604u);
        _a1_obj->f_stores = t1;
        _a1_obj->f_value = vader_box_obj(0u, NULL);
        _a1_obj->f_snapshot_type = 0u;
        _a1_obj->f_pops_frame = false;
        l2 = (void*) _a1_obj;
        vader_emit_c$return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    if (!(t0 == INT64_C(0))) {
        l4 = vader_emit_c$pop(l0);
        vader_array_t* _a2_arr = vader_array_new(266u, 0u, 13u, 1566u);
        l2 = (void*) _a2_arr;
        l4 = vader_emit_c$coerced_as(l0, l4, l1);
        l3 = vader_emit_c$c_type_for_val_bare(l1);
        vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a3_obj, 1604u);
        _a3_obj->f_stores = l2;
        _a3_obj->f_value = l4;
        _a3_obj->f_snapshot_type = l3;
        _a3_obj->f_pops_frame = false;
        l2 = (void*) _a3_obj;
        vader_emit_c$return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
    l3 = concat_2(3483u, l3);
    vader_emit_c$unreachable(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_return_lit(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    uint8_t l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_emit_c$const_lit_c(((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx, l1);
    l4 = vader_emit_c$const_val(l1);
    l5 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_signature);
    l3 = vader_emit_c$coerce_expr(l2, l3, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(266u, 0u, 13u, 1566u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a1_obj, 1604u);
    _a1_obj->f_stores = t0;
    _a1_obj->f_value = l3;
    _a1_obj->f_snapshot_type = 0u;
    _a1_obj->f_pops_frame = false;
    l2 = (void*) _a1_obj;
    vader_emit_c$return_statement(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_size_of_type(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &t0, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$expression_of(t0);
    l1 = vader_emit_c$payload(t1, 3007u);
    l1 = vader_emit_c_ast$around(395u, l1, 1243u);
    vader_emit_c$push_into_temporary(l0, l1, (uint8_t) 3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c$emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l5 = 0;
    void* l7 = NULL;
    bool t0;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l6, &l8 };
    void** gc_raw_roots[2] = { &l0, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c$array_header_pointer(l1);
    l5 = vader_emit_c$bind_array_local(l0, l4);
    if (l3) {
        t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_verify_bounds;
        if (t0) {
            l6 = vader_emit_c_ast$verbatim(l5);
            l8 = vader_emit_c$expression_of(l2);
            vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l8.payload.obj;
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l6.payload.obj;
            l7 = (void*) _a0_arr;
            vader_emit_c$statement_macro(l0, 1167u, l7);
        }
        { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_emit_c_ast$verbatim(l5);
    l6 = vader_emit_c$expression_of(l2);
    vader_array_t* _a1_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l4.payload.obj;
    l7 = (void*) _a1_arr;
    vader_emit_c$statement_macro(l0, 1166u, l7);
    { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6) {
    void* l7 = NULL;
    void* l27 = NULL;
    void* l31 = NULL;
    void* l33 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    int64_t l8, l9, l13, l14, l19, l20, l28, l29;
    uint8_t l10;
    bool l11, l12;
    vader_string_t l15 = 0;
    vader_string_t l21 = 0;
    vader_string_t l25 = 0;
    vader_string_t l30 = 0;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l26 = vader_box_null(), l32 = vader_box_null(), l34 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[10] = { &l16, &l17, &l18, &l22, &l23, &l24, &l26, &l32, &l34, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l27, &l31, &l33, &l35, &l36 };
    vader_string_t* gc_atom_roots[5] = { &l15, &l21, &l25, &l30, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 10u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(31u, 0u, 1u, 628u);
    l7 = (void*) _a0_arr;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) l1));
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l8, 628u);
        l10 = ((uint8_t) t0.payload.i);
        t1 = std_core$$array$Contains$contains__vader_core_bytecode_ValType(l7, l10);
        if (t1) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        vader_array_push_u8((vader_array_t*) l7, (int32_t) (uint8_t) l10);
        if (l10 == INT32_C(16)) {
            l11 = true;
        } else {
            l11 = l10 == INT32_C(15);
        }
        t1 = vader_emit_c$is_ref_val(l10);
        if (t1) {
            l12 = l6;
        } else {
            l12 = false;
        }
        if (l10 == INT32_C(12)) {
            if (l6) {
                l13 = INT64_C(0);
                l14 = vader_array_length(((vader_array_t*) l1));
                while ((l13 < l14)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l13, 628u);
                    if (((int32_t) t0.payload.i) == l10) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
                        t0 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l13];
                        l15 = t0.payload.s;
                        l16 = vader_emit_c_ast$verbatim(553u);
                        l17 = vader_emit_c_ast$declaration(3657u, l15, l16);
                        vader_array_push_ref((vader_array_t*) l0, l17.payload.obj);
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
                        t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l13];
                        t2 = t0.payload.s;
                        t0 = vader_emit_c_ast$verbatim(t2);
                        l18 = vader_emit_c_ast$address_of(t0);
                        vader_array_push_ref((vader_array_t*) l5, l18.payload.obj);
                    }
                    l13 = (l13 + INT64_C(1));
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        if (l11) {
            l19 = INT64_C(0);
            l20 = vader_array_length(((vader_array_t*) l1));
            while ((l19 < l20)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t0 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l19, 628u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l19)
                        t0 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l19];
                        l21 = t0.payload.s;
                        l22 = vader_emit_c_ast$verbatim(895u);
                        l23 = vader_emit_c_ast$declaration(3701u, l21, l22);
                        vader_array_push_ref((vader_array_t*) l0, l23.payload.obj);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l19)
                        t0 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l19];
                        t2 = t0.payload.s;
                        t0 = vader_emit_c_ast$verbatim(t2);
                        l24 = vader_emit_c_ast$address_of(t0);
                        vader_array_push_ref((vader_array_t*) l4, l24.payload.obj);
                    } else {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l19)
                        t0 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l19];
                        l25 = t0.payload.s;
                        l26 = vader_emit_c_ast$declaration(3701u, l25, vader_box_obj(0u, NULL));
                        vader_array_push_ref((vader_array_t*) l0, l26.payload.obj);
                    }
                }
                l19 = (l19 + INT64_C(1));
            }
        } else {
            vader_array_t* _a9_arr = vader_array_new(268u, 0u, 13u, 1578u);
            l27 = (void*) _a9_arr;
            l28 = INT64_C(0);
            l29 = vader_array_length(((vader_array_t*) l1));
            while ((l28 < l29)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_read_u8(_a10_slotarr, vader_array_offset(_a10_slotarr) + (size_t) l28, 628u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l28)
                        t0 = vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l28];
                        l30 = t0.payload.s;
                        vader_array_t* _a12_arr = vader_array_new(486u, 0u, 13u, 2777u);
                        l31 = (void*) _a12_arr;
                        l32 = vader_emit_c_ast$call(3557u, l31);
                        vader_struct_vader_emit_c_ast$CDeclarator_t* _a13_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
                        vader_obj_header_init(_a13_obj, 1578u);
                        _a13_obj->f_name = l30;
                        _a13_obj->f_length = vader_box_obj(0u, NULL);
                        _a13_obj->f_value = l32;
                        l33 = (void*) _a13_obj;
                        vader_array_push_ref((vader_array_t*) l27, l33);
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l28)
                        t0 = vader_array_box_slots(_a14_slotarr->buf)[vader_array_offset(_a14_slotarr) + (size_t) l28];
                        t2 = t0.payload.s;
                        t0 = vader_emit_c_ast$verbatim(t2);
                        l34 = vader_emit_c_ast$address_of(t0);
                        vader_array_push_ref((vader_array_t*) l3, l34.payload.obj);
                    } else {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l28)
                        t0 = vader_array_box_slots(_a15_slotarr->buf)[vader_array_offset(_a15_slotarr) + (size_t) l28];
                        t2 = t0.payload.s;
                        vader_struct_vader_emit_c_ast$CDeclarator_t* _a16_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
                        vader_obj_header_init(_a16_obj, 1578u);
                        _a16_obj->f_name = t2;
                        _a16_obj->f_length = vader_box_obj(0u, NULL);
                        _a16_obj->f_value = vader_box_obj(0u, NULL);
                        l35 = (void*) _a16_obj;
                        vader_array_push_ref((vader_array_t*) l27, l35);
                    }
                }
                l28 = (l28 + INT64_C(1));
            }
            t2 = vader_emit_c$c_type_for_val_bare(l10);
            vader_struct_vader_emit_c_ast$CDeclaration_t* _a17_obj = (vader_struct_vader_emit_c_ast$CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclaration_t));
            vader_obj_header_init(_a17_obj, 1577u);
            _a17_obj->f_type = t2;
            _a17_obj->f_declarators = l27;
            l36 = (void*) _a17_obj;
            vader_array_push_ref((vader_array_t*) l0, l36);
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c$pop(l0);
    l5 = vader_emit_c$pop(l0);
    l6 = vader_emit_c$emit_slot_array_local(l0, l5, l4, l3);
    l4 = vader_emit_c$slot_index(l6, l4);
    l4 = vader_emit_c$typed_slot(l1, l6, l4);
    vader_emit_c$push_into_temporary(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c$pop(l0);
    l5 = vader_emit_c$pop(l0);
    l6 = vader_emit_c$pop(l0);
    l7 = vader_emit_c$emit_slot_array_local(l0, l6, l5, l3);
    vader_emit_c$emit_typed_slot_write(l0, l7, l5, l4, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_str_data_entry(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_string_t l8 = 0;
    int32_t l9, l10;
    vader_box_t l11 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l11, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStrData_t*) l2)->f_values));
    vader_array_t* _a0_arr = vader_array_reserve(486u, (int64_t) t0, 13u, 2777u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcStrData_t*) l2)->f_values;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l7];
        l8 = t1.payload.s;
        l9 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_element_tag;
        l10 = vader_emit_c$atom_for(l3, l8);
        l11 = vader_emit_c$boxed_string(l9, l10);
        vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
        l7 = (l7 + INT64_C(1));
    }
    vader_emit_c$push_pool_array(l0, l1, 3560u, (uint8_t) 0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_string_compare(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$pop(l0);
    l2 = vader_emit_c$operand_as(l0, l2, (uint8_t) 12);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 12);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3654u, l3);
    vader_emit_c$push_expr(l0, (uint8_t) 2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_struct_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    int32_t l3, l4;
    uint8_t l6;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = ((vader_struct_vader_core_bytecode$StructGet_t*) l1)->f_type_id;
    l4 = ((vader_struct_vader_core_bytecode$StructGet_t*) l1)->f_field_index;
    l5 = vader_emit_c$expression_of(l2);
    l6 = vader_emit_c$val_of(l2);
    vader_emit_c$push_struct_field(l0, l3, l4, l5, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_struct_new(void* l0, void* l1) {
    void* l2 = NULL;
    void* l9 = NULL;
    void* l16 = NULL;
    int32_t l3, l7, l8, l10;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l17 = 0;
    int64_t l6, l19;
    uint8_t l11;
    bool l18;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    bool t4;
    uint8_t t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[4] = { &l4, &l12, &l13, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l9, &l16, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l14, &l15, &l17, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    if (l4.tag == 1286u) {
        l2 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names;
        l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l3];
        l5 = t0.payload.s;
        t1 = l4.payload.obj;
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields));
        l3 = ((int32_t) (int64_t) t2);
        t0 = vader_emit_c_ast$verbatim(0u);
        vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a2_arr;
        l6 = ((int64_t) (int32_t) l3);
        vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l6);
        l2 = (void*) _a3_arr;
        l7 = INT32_C(0);
        while ((l7 < l3)) {
            t3 = vader_chk_sub(i32, l3, INT32_C(1));
            l8 = vader_chk_sub(i32, t3, l7);
            l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
            t1 = l4.payload.obj;
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
            t1 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l8);
            l10 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_type_index;
            l11 = vader_emit_c$val_type_of_field(l9, l10);
            if (l11 != INT32_C(14)) {
                l12 = vader_emit_c$pop(l0);
                l13 = vader_emit_c$coerced_as(l0, l12, l11);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
                vader_array_ref_store(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l8, l13.payload.obj);
                VADER_WRITE_BARRIER(_a5_slotarr->buf);
            }
            l7 = (l7 + INT32_C(1));
        }
        t4 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_stack;
        if (t4) {
            l14 = vader_emit_c$aux(l0, 3221u);
            l15 = vader_emit_c$aux(l0, 3007u);
            l9 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack_storages;
            vader_struct_vader_emit_c$StackStorage_t* _a6_obj = (vader_struct_vader_emit_c$StackStorage_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackStorage_t));
            vader_obj_header_init(_a6_obj, 1561u);
            _a6_obj->f_cname = l5;
            _a6_obj->f_storage = l14;
            l16 = (void*) _a6_obj;
            vader_array_push_ref((vader_array_t*) l9, l16);
            l17 = concat_2(l5, 432u);
            t0 = vader_emit_c_ast$verbatim(l14);
            l12 = vader_emit_c_ast$address_of(t0);
            vader_emit_c$declare(l0, l17, l15, l12);
            l14 = l15;
        } else {
            l15 = vader_emit_c$aux(l0, 3007u);
            l17 = concat_2(l5, 432u);
            l12 = vader_emit_c$gc_allocation(l5);
            vader_emit_c$declare(l0, l17, l15, l12);
            l14 = l15;
        }
        l7 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        vader_emit_c$init_object_header(l0, l14, l7);
        l7 = INT32_C(0);
        while ((l7 < l3)) {
            t1 = l4.payload.obj;
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
            l9 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l7);
            l16 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l8 = ((vader_struct_vader_core_bytecode$BcField_t*) l9)->f_type_index;
            t5 = vader_emit_c$val_type_of_field(l16, l8);
            if (t5 != INT32_C(14)) {
                t6 = ((vader_struct_vader_core_bytecode$BcField_t*) l9)->f_name;
                l5 = vader_emit_c$field_c_name(t6);
                t6 = concat_3(l14, 484u, l5);
                l12 = vader_emit_c_ast$verbatim(t6);
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
                l13 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l7);
                vader_emit_c$assign(l0, l12, l13);
            }
            l7 = (l7 + INT32_C(1));
        }
        l4 = vader_emit_c_ast$verbatim(l14);
        vader_emit_c$push_object(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
    l6 = ((int64_t) (int32_t) t3);
    if ((INT64_C(0) <= l6)) {
        l19 = vader_array_length(((vader_array_t*) l2));
        l18 = (l6 < l19);
    } else {
        l18 = false;
    }
    if (!(l18)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(56));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l9, l6, 2716u);
        l19 = vader_array_length(((vader_array_t*) l2));
        l6 = std_core$write_int(l9, l6, l19);
        l6 = std_core$write_string_at(l9, l6, 490u);
        l5 = std_core$finish_buffer(l9, l6);
    } else {
        l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        l14 = vader_core_bytecode$bc_type_key(l2, l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l14);
        l9 = (void*) vader_buffer_new((size_t) (INT64_C(53) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l9, l6, 3322u);
        l6 = std_core$write_string_at(l9, l6, l14);
        l6 = std_core$write_string_at(l9, l6, 1434u);
        l19 = vader_array_length(((vader_array_t*) l2));
        l6 = std_core$write_int(l9, l6, l19);
        l6 = std_core$write_string_at(l9, l6, 490u);
        l5 = std_core$finish_buffer(l9, l6);
    }
    l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
    l6 = vader_host_std_core$Intrinsic$byte_len(l5);
    l2 = (void*) vader_buffer_new((size_t) (INT64_C(52) + l6));
    l6 = INT64_C(0);
    l6 = std_core$write_string_at(l2, l6, 3260u);
    l19 = ((int64_t) (int32_t) l3);
    l6 = std_core$write_int(l2, l6, l19);
    l6 = std_core$write_string_at(l2, l6, 566u);
    l6 = std_core$write_string_at(l2, l6, l5);
    t6 = std_core$finish_buffer(l2, l6);
    std_abort$todo(t6);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_c$emit_struct_set(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    int64_t l10, l11;
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    uint8_t t4;
    vader_box_t* gc_roots[4] = { &l4, &l7, &l9, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_type_id;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    if (!(l4.tag == 1286u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(50));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l6, l10, 3265u);
        t0 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_type_id;
        l11 = ((int64_t) (int32_t) t0);
        l10 = std_core$write_int(l6, l10, l11);
        t1 = std_core$finish_buffer(l6, l10);
        std_abort$todo(t1);
        vader_unreachable("a no-return call returned");
    }
    l2 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names;
    l3 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_type_id;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l3];
    l5 = t2.payload.s;
    t3 = l4.payload.obj;
    l2 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t3)->f_fields;
    l3 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_field_index;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$BcField_t*) l2)->f_type_index;
    t4 = vader_emit_c$val_type_of_field(l6, l3);
    if (t4 == INT32_C(14)) {
        vader_emit_c$pop(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_emit_c$pop(l0);
    t2 = vader_emit_c$pop(l0);
    l7 = vader_emit_c$object_pointer_of(t2);
    l8 = ((vader_struct_vader_core_bytecode$BcField_t*) l2)->f_name;
    l9 = vader_emit_c$field_of(l5, l7, l8);
    l3 = ((vader_struct_vader_core_bytecode$BcField_t*) l2)->f_type_index;
    l7 = vader_emit_c$struct_set_barrier(l1, l5, l7);
    vader_emit_c$store_field(l0, l9, l4, l3, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_struct_typedefs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    bool l7;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l8, &l9, &l10, &l11, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types));
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
        if (l6.tag == 1286u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            if (t1 == 0u) {
                l7 = true;
            } else {
                t2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
                l7 = !(t2);
            }
            if (l7) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                t3 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l4];
                t1 = t3.payload.s;
                vader_struct_vader_emit_c_ast$CStructForward_t* _a4_obj = (vader_struct_vader_emit_c_ast$CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructForward_t));
                vader_obj_header_init(_a4_obj, 1612u);
                _a4_obj->f_name = t1;
                l8 = (void*) _a4_obj;
                vader_array_push_ref((vader_array_t*) l2, l8);
                l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
                l10 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names;
                l11 = l6.payload.obj;
                l12 = vader_emit_c$struct_definition(l9, l10, l11, l4);
                vader_array_push_ref((vader_array_t*) l3, l12);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1606u);
    _a6_obj->f_comment = t0;
    _a6_obj->f_items = l2;
    l2 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 1606u);
    _a8_obj->f_comment = t0;
    _a8_obj->f_items = l3;
    l2 = (void*) _a8_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_temporary_declarations(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    int64_t l7, l8, l10;
    vader_string_t l11 = 0;
    int64_t t0;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l6, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
    l6 = (void*) _a0_arr;
    l7 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) l0));
    while ((l7 < l8)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 3278u);
        l10 = std_core$write_int(l9, l10, l7);
        l11 = std_core$finish_buffer(l9, l10);
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l11));
        l7 = (l7 + INT64_C(1));
    }
    vader_emit_c$emit_slot_decls(l1, l0, l6, l2, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_type_check(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l10 = vader_box_null();
    uint8_t l3;
    void* l4 = NULL;
    void* l7 = NULL;
    int32_t l5;
    int64_t l8, l9;
    vader_string_t l11 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l6, &l10, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$val_of(l2);
    t0 = vader_emit_c$is_ref_val(l3);
    if (t0) {
        l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
        l5 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) l1)->f_type_id;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        if (l6.tag == 1287u) {
            vader_array_t* _a1_arr = vader_array_new(486u, 0u, 13u, 2777u);
            l4 = (void*) _a1_arr;
            t1 = l6.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
            l8 = vader_array_length(((vader_array_t*) l7));
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l5 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l9];
                l6 = vader_emit_c$tag_of(l2);
                l10 = vader_emit_c$one_variant_check(l0, l6, l5);
                vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
                l9 = (l9 + INT64_C(1));
            }
            t2 = vader_emit_c_ast$any_of(l4);
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a3_obj, 1600u);
            _a3_obj->f_inner = t2;
            l4 = (void*) _a3_obj;
            vader_emit_c$push_expr(l0, (uint8_t) 10, vader_ref_box(l4));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = vader_emit_c$tag_of(l2);
        l5 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) l1)->f_type_id;
        l2 = vader_emit_c$one_variant_check(l0, l2, l5);
        vader_emit_c$push_expr(l0, (uint8_t) 10, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) l1)->f_type_id;
    t0 = vader_emit_c$class_matches_type(l4, l3, l5);
    if (t0) {
        l11 = 3379u;
    } else {
        l11 = 2502u;
    }
    l2 = vader_emit_c_ast$verbatim(l11);
    vader_emit_c$push_lit(l0, (uint8_t) 10, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_type_const(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(77));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 3559u);
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_null_tag;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3425u);
    t0 = ((vader_struct_vader_core_bytecode$TypeConst_t*) l1)->f_type_id;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3424u);
    t1 = std_core$finish_buffer(l2, l3);
    l5 = vader_emit_c_ast$verbatim(t1);
    vader_emit_c$push_lit(l0, (uint8_t) 17, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_type_info_table(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    int64_t l3, l7, l8, l20;
    bool l4, l5;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l14 = vader_box_null(), l17 = vader_box_null(), l21 = vader_box_null(), l23 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null();
    int32_t l15, l18, l24;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[9] = { &l9, &l10, &l14, &l17, &l21, &l23, &l25, &l27, &t3 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l6, &l11, &l12, &l13, &l16, &l19, &l22, &l26, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 9u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = false;
    l5 = false;
    l6 = l2;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
        if (l9.tag == 1276u) {
            l4 = true;
        }
        if (l9.tag == 1273u) {
            l5 = true;
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l6 = (void*) _a1_arr;
    if (l4) {
        l9 = vader_emit_c$single_offset_list(3593u, 3014u);
        vader_array_push_ref((vader_array_t*) l6, l9.payload.obj);
    }
    if (l5) {
        l9 = vader_emit_c$single_offset_list(3539u, 3013u);
        vader_array_push_ref((vader_array_t*) l6, l9.payload.obj);
    }
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1606u);
    _a3_obj->f_comment = t0;
    _a3_obj->f_items = l6;
    l6 = (void*) _a3_obj;
    vader_emit_c_ast$print_section(l1, l6);
    vader_array_t* _a4_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l6 = (void*) _a4_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l9 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
        l10 = l9;
        if (l9.tag == 1286u) {
            l11 = l10.payload.obj;
            l12 = l10.payload.obj;
            l13 = vader_emit_c$classify_struct_fields(l0, l12, l7);
            l14 = vader_emit_c$struct_info_row(l0, l11, l13, l7);
            vader_array_push_ref((vader_array_t*) l6, l14.payload.obj);
        } else if (l9.tag == 1276u) {
            t0 = l10.payload.obj;
            l15 = vader_core_bytecode$size_of_bc_type(vader_ref_box(t0));
            vader_array_t* _a6_arr = vader_array_new(486u, 0u, 13u, 2777u);
            l16 = (void*) _a6_arr;
            l17 = vader_emit_c$single_reference_row(l7, 755u, 3595u, l15, 3593u, l16);
            vader_array_push_ref((vader_array_t*) l6, l17.payload.obj);
        } else if (l9.tag == 1273u) {
            t0 = l10.payload.obj;
            l18 = vader_core_bytecode$size_of_bc_type(vader_ref_box(t0));
            l19 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l8 = INT64_C(0);
            t0 = l10.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
            l20 = ((int64_t) (int32_t) t1);
            l8 = std_core$write_int(l19, l8, l20);
            l8 = std_core$write_string_at(l19, l8, 3423u);
            t2 = std_core$finish_buffer(l19, l8);
            l21 = vader_emit_c_ast$verbatim(t2);
            t3 = vader_emit_c_ast$designated(510u, l21);
            vader_array_t* _a7_arr = vader_array_new(486u, 1u, 13u, 2777u);
            ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t3.payload.obj;
            l22 = (void*) _a7_arr;
            l23 = vader_emit_c$single_reference_row(l7, 667u, 3547u, l18, 3539u, l22);
            vader_array_push_ref((vader_array_t*) l6, l23.payload.obj);
        } else {
            l24 = vader_core_bytecode$size_of_bc_type(l10);
            if ((l24 > INT32_C(0))) {
                l25 = vader_emit_c_ast$number(((int64_t) (int32_t) l24));
                t3 = vader_emit_c_ast$designated(527u, l25);
                vader_array_t* _a8_arr = vader_array_new(486u, 1u, 13u, 2777u);
                ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = t3.payload.obj;
                l26 = (void*) _a8_arr;
                l27 = vader_emit_c$info_row(l7, l26);
                vader_array_push_ref((vader_array_t*) l6, l27.payload.obj);
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    l15 = ((int32_t) (int64_t) l3);
    l9 = vader_emit_c_ast$initializer_list(l6);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a9_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a9_obj, 1578u);
    _a9_obj->f_name = 3664u;
    _a9_obj->f_length = vader_box_i32(626u, l15);
    _a9_obj->f_value = l9;
    l2 = (void*) _a9_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a10_obj, 1587u);
    _a10_obj->f_storage = (uint8_t) 1;
    _a10_obj->f_constant = true;
    _a10_obj->f_type = 3663u;
    _a10_obj->f_declarator = l2;
    l2 = (void*) _a10_obj;
    l9 = vader_emit_c_ast$number(l3);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a11_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a11_obj, 1578u);
    _a11_obj->f_name = 3662u;
    _a11_obj->f_length = vader_box_obj(0u, NULL);
    _a11_obj->f_value = l9;
    l6 = (void*) _a11_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a12_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a12_obj, 1587u);
    _a12_obj->f_storage = (uint8_t) 1;
    _a12_obj->f_constant = true;
    _a12_obj->f_type = 3185u;
    _a12_obj->f_declarator = l6;
    l6 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(28u, 0u, 0u, 623u);
    l11 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(488u, 2u, 13u, 2786u);
    ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l6;
    ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l2;
    l2 = (void*) _a14_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a15_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a15_obj, 1606u);
    _a15_obj->f_comment = l11;
    _a15_obj->f_items = l2;
    l2 = (void*) _a15_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_typed_slot_write(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3, vader_string_t l4, uint8_t l5) {
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l6, &l7 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_emit_c$slot_index(l1, l2);
    l6 = vader_emit_c$typed_slot(l4, l1, l6);
    l7 = vader_emit_c$coerced_as(l0, l3, l5);
    l7 = vader_emit_c_ast$cast(l4, l7);
    vader_emit_c$assign(l0, l6, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_union_field_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l4;
    void* l5 = NULL;
    void* l6 = NULL;
    uint8_t l7;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    l3 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) l1)->f_type_id;
    l4 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) l1)->f_field_index;
    l2 = vader_emit_c$object_pointer_of(l2);
    l5 = vader_emit_c$union_field_place(l0, l3, l4, l2);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_emit_c$UnionFieldPlace_t*) l5)->f_type_index;
    l7 = vader_emit_c$val_type_of_field(l6, l3);
    l2 = ((vader_struct_vader_emit_c$UnionFieldPlace_t*) l5)->f_place;
    vader_emit_c$push_expr(l0, l7, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_union_field_set(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l7 = vader_box_null();
    int32_t l4, l5;
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l7, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$object_pointer_of(t0);
    l4 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) l1)->f_type_id;
    l5 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) l1)->f_field_index;
    l6 = vader_emit_c$union_field_place(l0, l4, l5, l3);
    l7 = ((vader_struct_vader_emit_c$UnionFieldPlace_t*) l6)->f_place;
    l4 = ((vader_struct_vader_emit_c$UnionFieldPlace_t*) l6)->f_type_index;
    vader_emit_c$store_field(l0, l7, l2, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_virtual_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    int32_t l5, l6;
    uint8_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    uint8_t t5;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l3, &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx;
    l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_vtable_key;
    l4 = vader_emit_c$find_vtable_row(l2, l3);
    if (l4.tag == 0u) {
        l5 = INT32_C(0);
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_parameter_count;
        while ((l5 < l6)) {
            vader_emit_c$drop_top(l0);
            l5 = (l5 + INT32_C(1));
        }
        l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_vtable_key;
        l3 = concat_2(2989u, l3);
        vader_emit_c$unreachable(l0, l3);
        t0 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
        if (t0 == INT64_C(1)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 628u);
            l7 = ((uint8_t) t1.payload.i);
            l8 = vader_emit_c$new_temporary(l0, l7);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
            t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0), 628u);
            l7 = ((uint8_t) t1.payload.i);
            vader_emit_c$push_temporary(l0, l8, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l4.payload.obj;
    l4 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$coerced_as(l0, l4, (uint8_t) 17);
    vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t1.payload.obj;
    l8 = (void*) _a2_arr;
    t2 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_parameter_count;
    l5 = vader_chk_sub(i32, t2, INT32_C(1));
    l9 = vader_emit_c$pop_args_boxed(l0, l5);
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l9);
    l2 = vader_emit_c$vtable_sig_for_row(((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx, l2);
    t3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_vtable_key;
    t4 = vader_emit_c$dispatcher_name(t3);
    l4 = vader_emit_c_ast$call(t4, l8);
    t5 = vader_core_bytecode$bc_single_result(l2);
    if (!(t5 == INT32_C(14))) {
        l7 = vader_core_bytecode$bc_single_result(l2);
        vader_emit_c$push_into_temporary(l0, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$evaluate(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_vtable_dispatchers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l30 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    void* l42 = NULL;
    void* l44 = NULL;
    void* l45 = NULL;
    void* l46 = NULL;
    void* l47 = NULL;
    void* l48 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    int64_t l5, l6, l12, l13, l27, l28;
    int32_t l15, l16, l18, l24, l25, l31;
    vader_box_t l21 = vader_box_null(), l29 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null(), l41 = vader_box_null();
    uint8_t l22, l32, l39, l40;
    vader_string_t l43 = 0;
    vader_string_t l49 = 0;
    int64_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    uint8_t t5;
    void* t6 = NULL;
    int32_t t7;
    vader_box_t* gc_roots[6] = { &l21, &l29, &l33, &l34, &l41, &t2 };
    void** gc_raw_roots[32] = {
        &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l10, &l11, &l14, &l17, &l19, &l20, &l23, &l26,
        &l30, &l35, &l36, &l37, &l38, &l42, &l44, &l45, &l46, &l47, &l48, &l50, &l51, &l52, &l53,
        &t6,
    };
    vader_string_t* gc_atom_roots[4] = { &l43, &l49, &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 32u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_vtables;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l3 = (void*) _a0_arr;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_entries));
        if (t0 == INT64_C(0)) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l8 = vader_emit_c$vtable_sig_for_row(l0, l7);
        vader_array_t* _a2_arr = vader_array_new(267u, 0u, 13u, 1571u);
        l9 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 626u);
        l10 = (void*) _a3_arr;
        l11 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_entries;
        l12 = vader_array_length(((vader_array_t*) l11));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l14 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l13);
            l15 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l14)->f_receiver_type_index;
            t1 = std_core$$array$Contains$contains__i32(l10, l15);
            if (t1) {
                l13 = (l13 + INT64_C(1));
                continue;
            }
            l16 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l14)->f_receiver_type_index;
            vader_array_push_i32((vader_array_t*) l10, l16);
            l17 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
            l18 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l14)->f_fn_index;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l18)
            l19 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l18);
            l20 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l19)->f_signature;
            l21 = vader_emit_c_ast$verbatim(3105u);
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t2 = vader_array_read_u8(_a6_slotarr, vader_array_offset(_a6_slotarr) + (size_t) INT32_C(0), 628u);
            l22 = ((uint8_t) t2.payload.i);
            t2 = vader_emit_c$coerce_expr(l2, l21, (uint8_t) 17, l22);
            vader_array_t* _a7_arr = vader_array_new(486u, 1u, 13u, 2777u);
            ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t2.payload.obj;
            l23 = (void*) _a7_arr;
            t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params));
            l24 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
            l25 = INT32_C(0);
            while ((l25 < l24)) {
                l26 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l27 = INT64_C(0);
                l27 = std_core$write_string_at(l26, l27, 1793u);
                l28 = ((int64_t) (int32_t) l25);
                l27 = std_core$write_int(l26, l27, l28);
                t3 = std_core$finish_buffer(l26, l27);
                l29 = vader_emit_c_ast$verbatim(t3);
                l30 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params;
                l31 = vader_chk_add(i32, l25, INT32_C(1));
                vader_array_t* _a8_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l31)
                t2 = vader_array_read_u8(_a8_slotarr, vader_array_offset(_a8_slotarr) + (size_t) l31, 628u);
                l32 = ((uint8_t) t2.payload.i);
                l33 = vader_emit_c$coerce_expr(l2, l29, (uint8_t) 17, l32);
                vader_array_push_ref((vader_array_t*) l23, l33.payload.obj);
                l25 = (l25 + INT32_C(1));
            }
            t3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l19)->f_name;
            t4 = vader_emit_c$sanitise(t3);
            l34 = vader_emit_c_ast$call(t4, l23);
            t5 = vader_core_bytecode$bc_single_result(l8);
            if (t5 == INT32_C(14)) {
                vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a9_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
                vader_obj_header_init(_a9_obj, 1582u);
                _a9_obj->f_expression = l34;
                l36 = (void*) _a9_obj;
                vader_array_t* _a10_arr = vader_array_new(266u, 0u, 13u, 1566u);
                t6 = (void*) _a10_arr;
                vader_struct_vader_emit_c_ast$CReturn_t* _a11_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
                vader_obj_header_init(_a11_obj, 1604u);
                _a11_obj->f_stores = t6;
                _a11_obj->f_value = vader_box_obj(0u, NULL);
                _a11_obj->f_snapshot_type = 0u;
                _a11_obj->f_pops_frame = false;
                l37 = (void*) _a11_obj;
                vader_array_t* _a12_arr = vader_array_new(489u, 2u, 13u, 2788u);
                ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 1u] = l37;
                ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = l36;
                l35 = (void*) _a12_arr;
            } else {
                vader_array_t* _a13_arr = vader_array_new(266u, 0u, 13u, 1566u);
                l38 = (void*) _a13_arr;
                l39 = vader_core_bytecode$bc_single_result(l20);
                l40 = vader_core_bytecode$bc_single_result(l8);
                l41 = vader_emit_c$dispatcher_result(l2, l34, l39, l40);
                vader_struct_vader_emit_c_ast$CReturn_t* _a14_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
                vader_obj_header_init(_a14_obj, 1604u);
                _a14_obj->f_stores = l38;
                _a14_obj->f_value = l41;
                _a14_obj->f_snapshot_type = 0u;
                _a14_obj->f_pops_frame = false;
                t6 = (void*) _a14_obj;
                vader_array_t* _a15_arr = vader_array_new(489u, 1u, 13u, 2788u);
                ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = t6;
                l35 = (void*) _a15_arr;
            }
            t7 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l14)->f_receiver_type_index;
            t2 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t7));
            vader_struct_vader_emit_c_ast$CCase_t* _a16_obj = (vader_struct_vader_emit_c_ast$CCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCase_t));
            vader_obj_header_init(_a16_obj, 1571u);
            _a16_obj->f_value = t2;
            _a16_obj->f_body = l35;
            l42 = (void*) _a16_obj;
            vader_array_push_ref((vader_array_t*) l9, l42);
            l13 = (l13 + INT64_C(1));
        }
        l43 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_key;
        t3 = concat_2(3707u, l43);
        t4 = vader_emit_c$c_string_lit(t3);
        t2 = vader_emit_c_ast$verbatim(t4);
        vader_array_t* _a17_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = t2.payload.obj;
        l44 = (void*) _a17_arr;
        t2 = vader_emit_c_ast$call(3665u, l44);
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a18_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a18_obj, 1582u);
        _a18_obj->f_expression = t2;
        l45 = (void*) _a18_obj;
        t2 = vader_emit_c_ast$verbatim(3105u);
        vader_struct_vader_emit_c_ast$CMember_t* _a19_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a19_obj, 1596u);
        _a19_obj->f_base = t2;
        _a19_obj->f_member = 3279u;
        _a19_obj->f_arrow = false;
        l46 = (void*) _a19_obj;
        vader_array_t* _a20_arr = vader_array_new(489u, 1u, 13u, 2788u);
        ((void**) _a20_arr->buf->slots)[vader_array_offset(_a20_arr) + 0u] = l45;
        l47 = (void*) _a20_arr;
        vader_struct_vader_emit_c_ast$CSwitch_t* _a21_obj = (vader_struct_vader_emit_c_ast$CSwitch_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSwitch_t));
        vader_obj_header_init(_a21_obj, 1613u);
        _a21_obj->f_subject = vader_ref_box(l46);
        _a21_obj->f_cases = l9;
        _a21_obj->f_default_body = vader_ref_box(l47);
        t6 = (void*) _a21_obj;
        vader_array_t* _a22_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t6;
        l48 = (void*) _a22_arr;
        t5 = vader_core_bytecode$bc_single_result(l8);
        if (t5 != INT32_C(14)) {
            vader_array_push_ref((vader_array_t*) l48, l45);
        }
        l49 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_key;
        l50 = vader_emit_c$dispatcher_signature(l0, l49, l8);
        vader_array_t* _a23_arr = vader_array_new(487u, 0u, 13u, 2782u);
        l51 = (void*) _a23_arr;
        vader_struct_vader_emit_c_ast$CBlock_t* _a24_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
        vader_obj_header_init(_a24_obj, 1568u);
        _a24_obj->f_body = l48;
        l52 = (void*) _a24_obj;
        vader_struct_vader_emit_c_ast$CFunction_t* _a25_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
        vader_obj_header_init(_a25_obj, 1585u);
        _a25_obj->f_signature = l50;
        _a25_obj->f_prologue = l51;
        _a25_obj->f_body = l52;
        l53 = (void*) _a25_obj;
        vader_array_push_ref((vader_array_t*) l3, l53);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a26_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a26_arr->buf)[vader_array_offset(_a26_arr) + 0u] = vader_box_string(623u, 3705u);
    t6 = (void*) _a26_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a27_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a27_obj, 1606u);
    _a27_obj->f_comment = t6;
    _a27_obj->f_items = l3;
    l2 = (void*) _a27_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_vtable_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    vader_string_t l8 = 0;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l9, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_vtables;
    vader_array_t* _a0_arr = vader_array_new(488u, 0u, 13u, 2786u);
    l2 = (void*) _a0_arr;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$VtableRow_t*) l6)->f_entries));
        if (t0 == INT64_C(0)) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = vader_emit_c$vtable_sig_for_row(l0, l6);
        l8 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l6)->f_key;
        t1 = vader_emit_c$dispatcher_signature(l0, l8, l7);
        vader_struct_vader_emit_c_ast$CPrototype_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
        vader_obj_header_init(_a2_obj, 1603u);
        _a2_obj->f_signature = t1;
        l9 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l9);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a3_arr->buf)[vader_array_offset(_a3_arr) + 0u] = vader_box_string(623u, 3706u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 1606u);
    _a4_obj->f_comment = t1;
    _a4_obj->f_items = l2;
    l2 = (void*) _a4_obj;
    vader_emit_c_ast$print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_c$empty_struct_offsets(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_emit_c$StructOffsets_t* _a3_obj = (vader_struct_vader_emit_c$StructOffsets_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StructOffsets_t));
    vader_obj_header_init(_a3_obj, 1563u);
    _a3_obj->f_ptr_offsets = l0;
    _a3_obj->f_str_offsets = l1;
    _a3_obj->f_ref_offsets = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$entry_needs_materialise(vader_box_t l0, int32_t l1) {
    bool l2;
    void* t0;
    int32_t t1;
    if (l0.tag == 1558u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 1560u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
        l2 = t1 == l1;
    } else if (l0.tag == 1562u) {
        l2 = false;
    } else {
        if (!(l0.tag == 1559u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    return l2;
}

static void* vader_emit_c$erased_parameters(int64_t l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CParameter_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a0_obj, 1599u);
    _a0_obj->f_type = 3701u;
    _a0_obj->f_name = 2414u;
    t0 = (void*) _a0_obj;
    t1 = vader_emit_c$boxed_parameters(t0, l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$erased_sibling_field_read(void* l0, int32_t l1, int32_t l2, uint8_t l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    int32_t l9;
    uint8_t l10;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l6, &t0 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l6.tag == 1286u)) {
        t0 = vader_emit_c_ast$verbatim(553u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
    l7 = t0.payload.s;
    t1 = l6.payload.obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
    l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
    l10 = vader_emit_c$val_type_of_field(l5, l9);
    l11 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_name;
    l6 = vader_emit_c$field_of(l7, l4, l11);
    t0 = vader_emit_c$coerce_expr(l5, l6, l10, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$erased_wrapper_signature(void* l0, vader_string_t l1, int64_t l2) {
    uint8_t l3;
    void* l4 = NULL;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l3 = vader_emit_c$wrapper_storage(t0);
    l4 = vader_emit_c$erased_parameters(l2);
    vader_struct_vader_emit_c_ast$CSignature_t* _a0_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a0_obj, 1608u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline = false;
    _a0_obj->f_result = 3560u;
    _a0_obj->f_name = l1;
    _a0_obj->f_parameters = l4;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$evaluate(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 1582u);
    _a0_obj->f_expression = l1;
    l2 = (void*) _a0_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$evaluated_void(void* l0, vader_box_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_emit_c$evaluate(l0, l1);
    t0 = vader_emit_c_ast$verbatim(385u);
    vader_struct_vader_emit_c$StackLit_t* _a0_obj = (vader_struct_vader_emit_c$StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackLit_t));
    vader_obj_header_init(_a0_obj, 1559u);
    _a0_obj->f_expression = t0;
    _a0_obj->f_val = (uint8_t) 14;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$expression_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1562u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c$StackTemporary_t*) t0)->f_temporary;
        l1 = vader_ref_box(t1);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1559u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_expression;
    } else if (l0.tag == 1560u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
        vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
        vader_obj_header_init(_a0_obj, 1594u);
        _a0_obj->f_slot = t2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1558u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackExpr_t*) t0)->f_expression;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$extern_c_type(uint8_t l0) {
    vader_string_t t0;
    if (!(l0 == INT32_C(12))) {
        t0 = vader_emit_c$c_type_for_val_bare(l0);
        return t0;
    }
    return 2285u;
}

static vader_box_t vader_emit_c$extern_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params));
    vader_array_t* _a0_arr = vader_array_reserve(272u, (int64_t) t0, 13u, 1599u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params));
    while ((l3 < l4)) {
        t1 = vader_emit_c$extern_parameter_type(l0, l1, l3);
        vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a1_obj, 1599u);
        _a1_obj->f_type = t1;
        _a1_obj->f_name = 0u;
        l5 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        l3 = (l3 + INT64_C(1));
    }
    l6 = vader_emit_c$extern_result_type(l0, l1);
    l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    vader_struct_vader_emit_c_ast$CSignature_t* _a2_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a2_obj, 1608u);
    _a2_obj->f_storage = (uint8_t) 2;
    _a2_obj->f_inline = false;
    _a2_obj->f_result = l6;
    _a2_obj->f_name = l7;
    _a2_obj->f_parameters = l2;
    t2 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
    vader_obj_header_init(_a3_obj, 1603u);
    _a3_obj->f_signature = t2;
    t2 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$extern_parameter_type(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    bool l4;
    int32_t l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l7, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    l4 = vader_core_bytecode$param_is_c_out(l3, l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    t0 = vader_emit_c$is_abi_array(l1, l5);
    if (t0) {
        l6 = vader_core_bytecode$param_c_type(l0, l2);
        if (l6.tag == 0u) {
            t1 = vader_emit_c$pointer_to(3699u, l4);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l6.payload.s;
        t2 = vader_emit_c$pointer_to(t1, l4);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    l5 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l2];
    l7 = vader_emit_c$mirrored_c_struct(l1, l5);
    if (l7 != 0u) {
        t0 = vader_core_bytecode$param_is_by_address(l3, l2);
        if (!(t0)) {
            { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_emit_c$pointer_to(l7, l4);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$param_is_by_address(l3, l2);
    if (t0) {
        t1 = vader_emit_c$spilled_c_type(l0, l2);
        t2 = vader_emit_c$pointer_to(t1, l4);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    l5 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l2];
    t0 = vader_emit_c$is_abi_nullable_pointer(l1, l5);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return 3701u; }
    }
    l6 = vader_core_bytecode$param_c_type(l0, l2);
    if (l6.tag == 0u) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t3 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l2, 628u);
        t1 = vader_emit_c$extern_c_type(((uint8_t) t3.payload.i));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l6.payload.s;
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$extern_result_type(void* l0, void* l1) {
    int32_t l2;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    bool t0;
    uint8_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_bytecode$bc_single_result_type(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
    t0 = vader_emit_c$is_abi_nullable_pointer(l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return 3701u; }
    }
    t0 = vader_emit_c$is_abi_nullable_string(l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return 2285u; }
    }
    l3 = vader_emit_c$mirrored_c_struct(l1, l2);
    if (l3 != 0u) {
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_core_bytecode$c_result_type(l0);
    if (l4.tag == 0u) {
        t1 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
        t2 = vader_emit_c$extern_c_type(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l4.payload.s;
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$external(vader_string_t l0, vader_string_t l1, vader_box_t l2, bool l3) {
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a0_obj, 1578u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    l4 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a1_obj, 1587u);
    _a1_obj->f_storage = (uint8_t) 2;
    _a1_obj->f_constant = l3;
    _a1_obj->f_type = l0;
    _a1_obj->f_declarator = l4;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$field_c_name(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_2(2500u, l0);
    return t0;
}

static vader_box_t vader_emit_c$field_of(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(l0, 432u);
    l4 = vader_emit_c$field_c_name(l2);
    t0 = vader_emit_c_ast$pointer_member(l3, l1, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$fields_are_layout_siblings(void* l0, void* l1, void* l2) {
    int64_t l3, l4;
    bool l5;
    int32_t l6, l7;
    void* t0;
    vader_box_t t1;
    uint8_t t2;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields));
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields));
    if (l3 != l4) {
        return false;
    }
    l5 = false;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields));
    for (;;) {
        if ((l3 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
            l6 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
            l7 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
            if (l7 == l6) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            l5 = true;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
            if (t1.tag == 1282u) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
            if (t1.tag == 1282u) {
                t2 = vader_emit_c$val_type_of_field(l0, l7);
                if (t2 == INT32_C(16)) {
                    l3 = (l3 + INT64_C(1));
                    continue;
                }
                return false;
            }
            return false;
        }
        break;
    }
    return l5;
}

void* vader_emit_c$find_layout_siblings(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    bool l4, l8, l9, l12;
    int64_t l5, l6;
    int32_t l10, l11, l15;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l0, &l2, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l3 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    if (l3.tag == 1286u) {
        t0 = l3.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
        l4 = vader_core_mangle$is_tuple_struct_name(t1);
        l5 = INT64_C(0);
        l6 = vader_array_length(((vader_array_t*) l0));
        while ((l5 < l6)) {
            if (((int32_t) (int64_t) l5) == l1) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l7 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
            if (l7.tag == 1286u) {
                t0 = l3.payload.obj;
                t2 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_symbol_id;
                if ((t2 >= INT32_C(0))) {
                    t0 = l7.payload.obj;
                    l10 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_symbol_id;
                    t0 = l3.payload.obj;
                    l11 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_symbol_id;
                    l9 = l10 == l11;
                } else {
                    l9 = false;
                }
                if (l9) {
                    l8 = true;
                } else {
                    if (l4) {
                        t0 = l7.payload.obj;
                        t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
                        l12 = vader_core_mangle$is_tuple_struct_name(t1);
                    } else {
                        l12 = false;
                    }
                    l8 = l12;
                }
                if (l8) {
                    l13 = l3.payload.obj;
                    l14 = l7.payload.obj;
                    t3 = vader_emit_c$fields_are_layout_siblings(l0, l13, l14);
                    if (t3) {
                        l15 = ((int32_t) (int64_t) l5);
                        vader_array_push_i32((vader_array_t*) l2, l15);
                    }
                }
            }
            l5 = (l5 + INT64_C(1));
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$find_vtable_row(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    int64_t l3, l4;
    vader_string_t t0;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_vtables;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        t0 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l5)->f_key;
        if (t0 == l1) {
            return vader_ref_box(l5);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static vader_string_t vader_emit_c$float_lit(double l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core$f64$Display$to_string(l0);
    if (l1 == 2719u) {
        { vader_gc_top = gc_frame.prev; return 1262u; }
    }
    if (l1 == 491u) {
        { vader_gc_top = gc_frame.prev; return 388u; }
    }
    if (l1 == 2948u) {
        { vader_gc_top = gc_frame.prev; return 1263u; }
    }
    t0 = std_string$string$std_core$Contains$contains(l1, 492u);
    if (t0) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$string$std_core$Contains$contains(l1, 2360u);
    if (!(t0)) {
        t1 = concat_2(l1, 501u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$float_tag_check_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    int32_t l6;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l5, &l7, &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        if (l5.tag == 1283u) {
            t0 = l5.payload.obj;
            t1 = vader_core_bytecode$is_float_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
            if (t1) {
                l6 = ((int32_t) (int64_t) l3);
                l7 = vader_emit_c$tag_equals(l1, l6);
                vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    t2 = vader_array_length(((vader_array_t*) l2));
    if (!(t2 == INT64_C(0))) {
        t3 = vader_emit_c_ast$any_of(l2);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a2_obj, 1600u);
        _a2_obj->f_inner = t3;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_emit_c_ast$verbatim(553u);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$fn_builds_stack_object(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        t1 = __lambda_vader_emit_c_14(t0);
        if (t1) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

bool vader_emit_c$fn_has_direct_alloc(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    vader_struct___lambda_env_vader_emit_c_12_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_12_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_12_t));
    vader_obj_header_init(_a0_obj, 691u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        t0 = __lambda_vader_emit_c_11(l3, l6);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_string_t vader_emit_c$fn_symbol_name(void* l0, int32_t l1) {
    bool l2;
    int64_t l3, l4;
    void* l5 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    void** gc_raw_roots[3] = { &l0, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        l3 = ((int64_t) (int32_t) l1);
        l4 = vader_array_length(((vader_array_t*) l0));
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        t2 = vader_emit_c$sanitise(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (void*) vader_buffer_new((size_t) INT64_C(84));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l5, l3, 2173u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l5, l3, l4);
    l3 = std_core$write_string_at(l5, l3, 476u);
    t1 = std_core$finish_buffer(l5, l3);
    vader_host_std_core$Intrinsic$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_emit_c$foreign_unit_banner(void* l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
    l1 = vader_core_bytecode$library_name(t0);
    if (!(l1 == 0u)) {
        t1 = concat_3(764u, l1, 1683u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 765u; }
}

vader_string_t vader_emit_c$foreign_unit_of(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_bytecode$library_name(l0);
    if (l1 != 0u) {
        t0 = vader_emit_c$library_unit_name(l1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c$synthesises_prototype(l0);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    { vader_gc_top = gc_frame.prev; return 1295u; }
}

static void* vader_emit_c$foreign_units(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l5 = vader_emit_c$foreign_unit_of(t0);
        if (l5 != 0u) {
            t1 = std_core$$array$Contains$contains__string(l1, l5);
            if (!(t1)) {
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l5));
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    l2 = (void*) &vader_fn_static_std_string$compare_ascending;
    t0 = std_sort$sort__string(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$forward_boxed(void* l0, vader_string_t l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
    uint8_t l5;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l8 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$call(l1, l2);
    l5 = vader_core_bytecode$bc_single_result(l3);
    if (l5 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 1582u);
        _a0_obj->f_expression = l4;
        l6 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(266u, 0u, 13u, 1566u);
        l7 = (void*) _a1_arr;
        l8 = vader_emit_c$void_box(l0);
        vader_struct_vader_emit_c_ast$CReturn_t* _a2_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a2_obj, 1604u);
        _a2_obj->f_stores = l7;
        _a2_obj->f_value = l8;
        _a2_obj->f_snapshot_type = 0u;
        _a2_obj->f_pops_frame = false;
        l7 = (void*) _a2_obj;
        vader_array_t* _a3_arr = vader_array_new(487u, 2u, 13u, 2782u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 1u] = l7;
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = l6;
        t0 = (void*) _a3_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5 == INT32_C(17)) {
        l8 = l4;
    } else if (l5 == INT32_C(16)) {
        l8 = vader_emit_c$ref_box(l4);
    } else {
        l9 = vader_core_bytecode$bc_single_result_type(l3);
        l8 = vader_emit_c$box_expr(l4, l5, l9);
    }
    vader_array_t* _a4_arr = vader_array_new(266u, 0u, 13u, 1566u);
    t0 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a5_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a5_obj, 1604u);
    _a5_obj->f_stores = t0;
    _a5_obj->f_value = l8;
    _a5_obj->f_snapshot_type = 0u;
    _a5_obj->f_pops_frame = false;
    t0 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(487u, 1u, 13u, 2782u);
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t0;
    t0 = (void*) _a6_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$forwarded_result(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    int32_t l5, l8;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l12 = 0;
    uint8_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[7] = { &l2, &l3, &l4, &l9, &l10, &l11, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l12, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c_ast$verbatim(3087u);
    l4 = vader_emit_c_ast$verbatim(3043u);
    l5 = vader_core_bytecode$bc_single_result_type(l0);
    t0 = vader_core_bytecode$bc_single_result(l0);
    if (t0 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 1582u);
        _a0_obj->f_expression = l2;
        l6 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(487u, 0u, 13u, 2782u);
        l7 = (void*) _a1_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a2_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a2_obj, 1552u);
        _a2_obj->f_capture = vader_ref_box(l6);
        _a2_obj->f_settle = l7;
        _a2_obj->f_returned = vader_box_obj(0u, NULL);
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_emit_c$is_abi_nullable_pointer(l1, l5);
    if (t2) {
        l8 = vader_emit_c$present_tag(l1, (uint8_t) 15);
        l9 = vader_emit_c$box_expr(l3, (uint8_t) 15, l8);
        l10 = vader_emit_c_ast$declaration(3701u, 3087u, l2);
        vader_array_t* _a3_arr = vader_array_new(487u, 0u, 13u, 2782u);
        l6 = (void*) _a3_arr;
        l9 = vader_emit_c$null_or(l3, l9);
        vader_struct_vader_emit_c$ForwardedResult_t* _a4_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a4_obj, 1552u);
        _a4_obj->f_capture = l10;
        _a4_obj->f_settle = l6;
        _a4_obj->f_returned = l9;
        t1 = (void*) _a4_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_emit_c$is_abi_nullable_string(l1, l5);
    if (t2) {
        l8 = vader_emit_c$present_tag(l1, (uint8_t) 12);
        l9 = vader_emit_c$interned(l3);
        l9 = vader_emit_c_ast$cast(2731u, l9);
        l9 = vader_emit_c$box_call(2657u, l8, l9);
        l10 = vader_emit_c_ast$declaration(2285u, 3087u, l2);
        l9 = vader_emit_c$null_or(l3, l9);
        t3 = vader_emit_c_ast$declaration(3560u, 3043u, l9);
        vader_array_t* _a5_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t3.payload.obj;
        l6 = (void*) _a5_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a6_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a6_obj, 1552u);
        _a6_obj->f_capture = l10;
        _a6_obj->f_settle = l6;
        _a6_obj->f_returned = l4;
        t1 = (void*) _a6_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$bc_single_result(l0);
    if (t0 == INT32_C(12)) {
        l9 = vader_emit_c_ast$verbatim(322u);
        l10 = vader_emit_c_ast$number(INT64_C(0));
        vader_array_t* _a7_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = l10.payload.obj;
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l9.payload.obj;
        l6 = (void*) _a7_arr;
        l9 = vader_emit_c_ast$call(3553u, l6);
        t1 = (void*) &vader_data_70;
        vader_array_t* _a8_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l6 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) INT64_C(0));
        l10 = vader_emit_c_ast$binary((uint8_t) 11, l3, vader_ref_box(l6));
        l11 = vader_emit_c$interned(l3);
        vader_struct_vader_emit_c_ast$CConditional_t* _a9_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
        vader_obj_header_init(_a9_obj, 1575u);
        _a9_obj->f_condition = l10;
        _a9_obj->f_then_value = l9;
        _a9_obj->f_else_value = l11;
        l6 = (void*) _a9_obj;
        l9 = vader_emit_c_ast$declaration(2285u, 3087u, l2);
        t3 = vader_emit_c_ast$declaration(3657u, 3043u, vader_ref_box(l6));
        vader_array_t* _a10_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t3.payload.obj;
        l6 = (void*) _a10_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a11_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a11_obj, 1552u);
        _a11_obj->f_capture = l9;
        _a11_obj->f_settle = l6;
        _a11_obj->f_returned = l4;
        t1 = (void*) _a11_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = vader_emit_c$mirrored_c_struct(l1, l5);
    if (!(l12 != 0u)) {
        t0 = vader_core_bytecode$bc_single_result(l0);
        t4 = vader_emit_c$c_type_for_val_bare(t0);
        l4 = vader_emit_c_ast$declaration(t4, 3087u, l2);
        vader_array_t* _a12_arr = vader_array_new(487u, 0u, 13u, 2782u);
        l6 = (void*) _a12_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a13_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a13_obj, 1552u);
        _a13_obj->f_capture = l4;
        _a13_obj->f_settle = l6;
        _a13_obj->f_returned = l3;
        t1 = (void*) _a13_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c$mirror_result(l1, l5, l12, l2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$fresh_slot(vader_string_t l0, int32_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l3, &l6, &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c_ast$verbatim(l0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3522u, l2);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l4 = INT64_C(0);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l2, l4, l5);
    l4 = std_core$write_string_at(l2, l4, 3423u);
    t1 = std_core$finish_buffer(l2, l4);
    l6 = vader_emit_c_ast$verbatim(t1);
    t0 = vader_emit_c_ast$binary((uint8_t) 3, l3, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$function_definition(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    int32_t l6, l13, l24;
    vader_string_t l7 = 0;
    vader_string_t l14 = 0;
    vader_string_t l18 = 0;
    vader_string_t l30 = 0;
    vader_string_t l31 = 0;
    int64_t l8, l9, l15, l16, l17, l20, l21, l22;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l23 = vader_box_null(), l32 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null(), l35 = vader_box_null();
    bool l12, l19;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    int64_t t5;
    vader_box_t* gc_roots[8] = { &l10, &l11, &l23, &l32, &l33, &l34, &l35, &t4 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l5, &l25, &l26, &l27, &l28, &l29, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l7, &l14, &l18, &l30, &l31, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$new_fn_state(l0, l1, l2);
    l4 = vader_emit_c$precompute_scopes(l2);
    ((vader_struct_vader_emit_c$FnState_t*) l3)->f_scopes = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l3);
    l4 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_scopes;
    l4 = vader_emit_c$precompute_branch_targets(l2, l4);
    l5 = ((vader_struct_vader_emit_c$BranchTargets_t*) l4)->f_continue_targets;
    ((vader_struct_vader_emit_c$FnState_t*) l3)->f_continue_targets = l5;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l3);
    l4 = ((vader_struct_vader_emit_c$BranchTargets_t*) l4)->f_break_targets;
    ((vader_struct_vader_emit_c$FnState_t*) l3)->f_break_targets = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l3);
    l6 = INT32_C(-1);
    l7 = 0u;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body));
    while ((l8 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l10 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
        t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_drop_call_result;
        if (t0) {
            if (l10.tag == 1319u) {
                ((vader_struct_vader_emit_c$FnState_t*) l3)->f_drop_call_result = false;
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_debug);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l11 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
        if (!(l11.tag == 0u)) {
            t1 = l11.payload.obj;
            t2 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_line;
            if (t2 != l6) {
                l12 = true;
            } else {
                t1 = l11.payload.obj;
                t3 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_file;
                l12 = t3 != l7;
            }
            if (l12) {
                t1 = l11.payload.obj;
                l13 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_line;
                t1 = l11.payload.obj;
                t3 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_file;
                l14 = vader_emit_c$c_string_lit(t3);
                l15 = vader_host_std_core$Intrinsic$byte_len(l14);
                l4 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l15));
                l16 = INT64_C(0);
                l16 = std_core$write_string_at(l4, l16, 333u);
                l17 = ((int64_t) (int32_t) l13);
                l16 = std_core$write_int(l4, l16, l17);
                l16 = std_core$write_string_at(l4, l16, 19u);
                l16 = std_core$write_string_at(l4, l16, l14);
                l18 = std_core$finish_buffer(l4, l16);
                vader_emit_c$directive(l3, l18);
                t1 = l11.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_line;
                t1 = l11.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_file;
            }
        }
        if (l10.tag == 1308u) {
            l19 = true;
        } else {
            l19 = l10.tag == 1309u;
        }
        if (l19) {
            l20 = vader_chk_add(i64, l8, INT64_C(1));
            l21 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body));
            if ((l20 < l21)) {
                l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body;
                l22 = vader_chk_add(i64, l8, INT64_C(1));
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l22)
                t4 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l22);
                if (t4.tag == 1319u) {
                    l23 = l10;
                    t5 = vader_emit_c$callee_result_arity(l0, l23);
                    if ((t5 <= INT64_C(1))) {
                        ((vader_struct_vader_emit_c$FnState_t*) l3)->f_drop_call_result = true;
                    }
                }
            }
        }
        l24 = ((int32_t) (int64_t) l8);
        vader_emit_c$emit_op(l3, l24, l10);
        l8 = (l8 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        t0 = vader_emit_c_ast$ends_with_return(((vader_struct_vader_emit_c$FnState_t*) l3)->f_root);
        if (!(t0)) {
            l4 = ((vader_struct_vader_emit_c_ast$CBlock_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root)->f_body;
            vader_struct_vader_emit_c_ast$CVerbatim_t* _a3_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
            vader_obj_header_init(_a3_obj, 1617u);
            _a3_obj->f_text = 3604u;
            l5 = (void*) _a3_obj;
            vader_struct_vader_emit_c_ast$CVerbatim_t* _a4_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
            vader_obj_header_init(_a4_obj, 1617u);
            _a4_obj->f_text = 2593u;
            l25 = (void*) _a4_obj;
            vader_struct_vader_emit_c_ast$CAssign_t* _a5_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
            vader_obj_header_init(_a5_obj, 1566u);
            _a5_obj->f_target = vader_ref_box(l5);
            _a5_obj->f_value = vader_ref_box(l25);
            _a5_obj->f_operator = vader_box_obj(0u, NULL);
            l5 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l4, l5);
        }
    }
    l4 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root;
    l5 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_temporaries;
    l4 = vader_emit_c_ast$coalesce_temporaries(l4, l5);
    vader_emit_c_ast$structure_loops(((vader_struct_vader_emit_c$FnState_t*) l3)->f_root);
    vader_array_t* _a6_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l25 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l26 = (void*) _a8_arr;
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        l27 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params;
        l8 = INT64_C(0);
        l9 = vader_array_length(((vader_array_t*) l27));
        while ((l8 < l9)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t4 = vader_array_read_u8(_a9_slotarr, vader_array_offset(_a9_slotarr) + (size_t) l8, 628u);
            if (((int32_t) t4.payload.i) == INT32_C(16)) {
                vader_struct_vader_emit_c_ast$CLocal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                vader_obj_header_init(_a10_obj, 1594u);
                _a10_obj->f_slot = ((int32_t) (int64_t) l8);
                t1 = (void*) _a10_obj;
                l10 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                vader_array_push_ref((vader_array_t*) l25, l10.payload.obj);
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l27);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                t4 = vader_array_read_u8(_a11_slotarr, vader_array_offset(_a11_slotarr) + (size_t) l8, 628u);
                if (((int32_t) t4.payload.i) == INT32_C(12)) {
                    vader_struct_vader_emit_c_ast$CLocal_t* _a12_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                    vader_obj_header_init(_a12_obj, 1594u);
                    _a12_obj->f_slot = ((int32_t) (int64_t) l8);
                    t1 = (void*) _a12_obj;
                    l11 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                    vader_array_push_ref((vader_array_t*) l26, l11.payload.obj);
                } else {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l27);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    t4 = vader_array_read_u8(_a13_slotarr, vader_array_offset(_a13_slotarr) + (size_t) l8, 628u);
                    t0 = vader_emit_c$is_ref_val(((uint8_t) t4.payload.i));
                    if (t0) {
                        vader_struct_vader_emit_c_ast$CLocal_t* _a14_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                        vader_obj_header_init(_a14_obj, 1594u);
                        _a14_obj->f_slot = ((int32_t) (int64_t) l8);
                        t1 = (void*) _a14_obj;
                        l23 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                        vader_array_push_ref((vader_array_t*) l5, l23.payload.obj);
                    }
                }
            }
            l8 = (l8 + INT64_C(1));
        }
    }
    vader_array_t* _a15_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l27 = (void*) _a15_arr;
    l12 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    vader_emit_c$emit_local_decls(l2, l27, l5, l25, l26, l12);
    l12 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    vader_emit_c$emit_temporary_declarations(l4, l27, l5, l25, l26, l12);
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        t5 = vader_array_length(((vader_array_t*) l5));
        if ((t5 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3561u, 2595u, l5);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        t5 = vader_array_length(((vader_array_t*) l25));
        if ((t5 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3702u, 2594u, l25);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        t5 = vader_array_length(((vader_array_t*) l5));
        if ((t5 > INT64_C(0))) {
            l7 = 2595u;
        } else {
            l7 = 895u;
        }
        t5 = vader_array_length(((vader_array_t*) l25));
        if ((t5 > INT64_C(0))) {
            l14 = 2594u;
        } else {
            l14 = 895u;
        }
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages));
        if ((l8 > INT64_C(0))) {
            l18 = 2596u;
        } else {
            l18 = 895u;
        }
        t5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages));
        vader_array_t* _a16_arr = vader_array_reserve(486u, (int64_t) t5, 13u, 2777u);
        l4 = (void*) _a16_arr;
        l28 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages;
        l9 = vader_array_length(((vader_array_t*) l28));
        l15 = INT64_C(0);
        while ((l15 < l9)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l28);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            l29 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) l15);
            l30 = ((vader_struct_vader_emit_c$StackStorage_t*) l29)->f_cname;
            l31 = ((vader_struct_vader_emit_c$StackStorage_t*) l29)->f_storage;
            l10 = vader_emit_c_ast$verbatim(3777u);
            l11 = vader_emit_c_ast$declaration(l30, l31, l10);
            vader_array_push_ref((vader_array_t*) l27, l11.payload.obj);
            t3 = ((vader_struct_vader_emit_c$StackStorage_t*) l29)->f_storage;
            t4 = vader_emit_c_ast$verbatim(t3);
            l23 = vader_emit_c_ast$address_of(t4);
            l32 = vader_emit_c_ast$cast(3701u, l23);
            vader_array_push_ref((vader_array_t*) l4, l32.payload.obj);
            l15 = (l15 + INT64_C(1));
        }
        if ((l8 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3701u, 2596u, l4);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        l9 = vader_array_length(((vader_array_t*) l26));
        if ((l9 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3658u, 2591u, l26);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        l10 = vader_emit_c_ast$verbatim(3604u);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l15 = INT64_C(0);
        l16 = vader_array_length(((vader_array_t*) l5));
        l15 = std_core$write_int(l4, l15, l16);
        l15 = std_core$write_string_at(l4, l15, 3423u);
        t3 = std_core$finish_buffer(l4, l15);
        l11 = vader_emit_c_ast$verbatim(t3);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l15 = INT64_C(0);
        l16 = vader_array_length(((vader_array_t*) l25));
        l15 = std_core$write_int(l4, l15, l16);
        l15 = std_core$write_string_at(l4, l15, 3423u);
        t3 = std_core$finish_buffer(l4, l15);
        l23 = vader_emit_c_ast$verbatim(t3);
        l32 = vader_emit_c_ast$verbatim(l7);
        l33 = vader_emit_c_ast$verbatim(l14);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l15 = INT64_C(0);
        l15 = std_core$write_int(l4, l15, l8);
        l15 = std_core$write_string_at(l4, l15, 3423u);
        t3 = std_core$finish_buffer(l4, l15);
        l34 = vader_emit_c_ast$verbatim(t3);
        l35 = vader_emit_c_ast$verbatim(l18);
        vader_array_t* _a18_arr = vader_array_new(486u, 7u, 13u, 2777u);
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 6u] = l35.payload.obj;
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 5u] = l34.payload.obj;
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 4u] = l33.payload.obj;
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 3u] = l32.payload.obj;
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 2u] = l23.payload.obj;
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 1u] = l11.payload.obj;
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = l10.payload.obj;
        l4 = (void*) _a18_arr;
        if ((l9 > INT64_C(0))) {
            l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l8 = INT64_C(0);
            l8 = std_core$write_int(l5, l8, l9);
            l8 = std_core$write_string_at(l5, l8, 3423u);
            t3 = std_core$finish_buffer(l5, l8);
            l10 = vader_emit_c_ast$verbatim(t3);
            l11 = vader_emit_c_ast$verbatim(2591u);
            vader_array_t* _a19_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 1u] = l11.payload.obj;
            ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = l10.payload.obj;
            l5 = (void*) _a19_arr;
            vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l5);
        }
        vader_struct_vader_emit_c_ast$CInitializerList_t* _a20_obj = (vader_struct_vader_emit_c_ast$CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInitializerList_t));
        vader_obj_header_init(_a20_obj, 1592u);
        _a20_obj->f_elements = l4;
        l4 = (void*) _a20_obj;
        l10 = vader_emit_c_ast$declaration(3601u, 2592u, vader_ref_box(l4));
        vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        l10 = vader_emit_c_ast$verbatim(3604u);
        t4 = vader_emit_c_ast$verbatim(2592u);
        l11 = vader_emit_c_ast$address_of(t4);
        vader_struct_vader_emit_c_ast$CAssign_t* _a21_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a21_obj, 1566u);
        _a21_obj->f_target = l10;
        _a21_obj->f_value = l11;
        _a21_obj->f_operator = vader_box_obj(0u, NULL);
        l4 = (void*) _a21_obj;
        vader_array_push_ref((vader_array_t*) l27, l4);
    }
    l4 = vader_emit_c$signature_for(l0, l1);
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root;
    vader_struct_vader_emit_c_ast$CFunction_t* _a22_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a22_obj, 1585u);
    _a22_obj->f_signature = l4;
    _a22_obj->f_prologue = l27;
    _a22_obj->f_body = l3;
    t1 = (void*) _a22_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$gc_allocation(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = concat_2(l0, 432u);
    t0 = concat_3(3187u, l0, 398u);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3598u, l2);
    t1 = vader_emit_c_ast$cast(l1, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$gc_statistic(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(266u, 0u, 13u, 1566u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l2 = (void*) _a1_arr;
    t0 = vader_emit_c_ast$call(3602u, l2);
    vader_struct_vader_emit_c_ast$CMember_t* _a2_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a2_obj, 1596u);
    _a2_obj->f_base = t0;
    _a2_obj->f_member = l0;
    _a2_obj->f_arrow = false;
    l2 = (void*) _a2_obj;
    l3 = vader_emit_c_ast$cast(2731u, vader_ref_box(l2));
    vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a3_obj, 1604u);
    _a3_obj->f_stores = l1;
    _a3_obj->f_value = l3;
    _a3_obj->f_snapshot_type = 0u;
    _a3_obj->f_pops_frame = false;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$global_slot_addresses(void* l0, uint8_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int64_t l3, l4, l7;
    int32_t l5;
    vader_box_t l8 = vader_box_null();
    uint8_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals));
    while ((l3 < l4)) {
        l5 = ((int32_t) (int64_t) l3);
        t0 = vader_emit_c$global_slot_val(l0, l5);
        if (t0 == l1) {
            l6 = (void*) vader_buffer_new((size_t) INT64_C(33));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l6, l7, 3605u);
            l7 = std_core$write_int(l6, l7, l3);
            t1 = std_core$finish_buffer(l6, l7);
            t2 = vader_emit_c_ast$verbatim(t1);
            l8 = vader_emit_c_ast$address_of(t2);
            vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$global_slot_val(void* l0, int32_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    uint8_t t1;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l3 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_type_id;
    t1 = vader_emit_c$val_type_of_field(l2, l3);
    return t1;
}

static uint8_t vader_emit_c$global_storage(bool l0) {
    if (l0) {
        return (uint8_t) 1;
    }
    return (uint8_t) 0;
}

static bool vader_emit_c$has_str_data(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t l4;
    l1 = l0;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        if (l4.tag == 1285u) {
            return true;
        }
        if (l4.tag == 1272u) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static vader_string_t vader_emit_c$host_shim_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l1 = vader_emit_c$sanitise(t0);
    t0 = concat_2(3610u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$import_shim(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$shim_signature(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    t0 = vader_emit_c$shim_body(l1, l4);
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1568u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CFunction_t* _a2_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a2_obj, 1585u);
    _a2_obj->f_signature = l2;
    _a2_obj->f_prologue = l3;
    _a2_obj->f_body = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$imports_header_name(vader_string_t l0) {
    int64_t l1;
    void* l2 = NULL;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    int64_t t2;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$ends_with(l0, 530u);
    if (!(t0)) {
        t1 = concat_2(l0, 515u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = std_core$len_1(l0);
    l1 = vader_chk_sub(i64, t2, INT64_C(8));
    vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
    vader_obj_header_init(_a0_obj, 1081u);
    _a0_obj->f_start = INT64_C(0);
    _a0_obj->f_end = l1;
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = INT64_C(0);
    l2 = (void*) _a0_obj;
    t1 = std_core$string$Index$at$1(l0, l2);
    t3 = concat_2(t1, 515u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$imports_may_collect(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    bool l5;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) t0, 12u, 621u);
    l2 = (void*) _a0_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    vader_array_t* _pc10_hdr = (vader_array_t*) l2;
    size_t _pc10_len = vader_array_length(_pc10_hdr);
    size_t _pc10_cap = vader_array_is_borrowed(_pc10_hdr) ? (size_t) 0 : vader_array_capacity(_pc10_hdr);
    void* _pc10_slots = _pc10_hdr->buf->slots;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            l5 = __lambda_vader_emit_c_6(t1);
            if (VADER_LIKELY(_pc10_len < _pc10_cap)) {
                ((uint8_t*) _pc10_slots)[_pc10_len] = (uint8_t) (l5);
                _pc10_len += 1;
            } else {
                vader_array_set_length(_pc10_hdr, _pc10_len);
                if (_pc10_hdr->buf->length < _pc10_len) {
                    _pc10_hdr->buf->length = _pc10_len;
                }
                vader_array_push_bool((vader_array_t*) l2, l5);
                _pc10_hdr = (vader_array_t*) l2;
                _pc10_len = vader_array_length(_pc10_hdr);
                _pc10_cap = vader_array_is_borrowed(_pc10_hdr) ? (size_t) 0 : vader_array_capacity(_pc10_hdr);
                _pc10_slots = _pc10_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc10_hdr, _pc10_len);
        if (_pc10_hdr->buf->length < _pc10_len) {
            _pc10_hdr->buf->length = _pc10_len;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$imports_of_unit(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    bool t0;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l7, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
    vader_struct___lambda_env_vader_emit_c_10_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_10_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_10_t));
    vader_obj_header_init(_a0_obj, 690u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(115u, 0u, 13u, 1279u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        t0 = __lambda_vader_emit_c_9(l3, l7);
        if (t0) {
            l8 = l7;
            vader_array_push_ref((vader_array_t*) l4, l8);
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$include_of(vader_string_t l0) {
    bool l1;
    vader_string_t l2 = 0;
    int64_t l3;
    void* l4 = NULL;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    void** gc_raw_roots[2] = { &l4, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core$len_1(l0);
    l1 = (t0 >= INT64_C(2));
    if (l1) {
        t0 = std_core$len_1(l0);
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
        vader_obj_header_init(_a0_obj, 1081u);
        _a0_obj->f_start = INT64_C(1);
        _a0_obj->f_end = l3;
        _a0_obj->f_inclusive = false;
        _a0_obj->f_done = false;
        _a0_obj->f_cursor = INT64_C(1);
        l4 = (void*) _a0_obj;
        l2 = std_core$string$Index$at$1(l0, l4);
    } else {
        l2 = l0;
    }
    if (l1) {
        t1 = std_string$starts_with(l0, 610u);
        if (t1) {
            t1 = std_string$ends_with(l0, 632u);
            if (t1) {
                vader_struct_vader_emit_c_ast$CInclude_t* _a1_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
                vader_obj_header_init(_a1_obj, 1590u);
                _a1_obj->f_path = l2;
                _a1_obj->f_system = true;
                t2 = (void*) _a1_obj;
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l1) {
        t1 = std_string$starts_with(l0, 319u);
        if (t1) {
            t1 = std_string$ends_with(l0, 319u);
            if (t1) {
                vader_struct_vader_emit_c_ast$CInclude_t* _a2_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
                vader_obj_header_init(_a2_obj, 1590u);
                _a2_obj->f_path = l2;
                _a2_obj->f_system = false;
                t2 = (void*) _a2_obj;
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l1 = false;
            vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
            vader_obj_header_init(_a3_obj, 1590u);
            _a3_obj->f_path = l0;
            _a3_obj->f_system = l1;
            t2 = (void*) _a3_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l1 = false;
        vader_struct_vader_emit_c_ast$CInclude_t* _a4_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
        vader_obj_header_init(_a4_obj, 1590u);
        _a4_obj->f_path = l0;
        _a4_obj->f_system = l1;
        t2 = (void*) _a4_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = false;
    vader_struct_vader_emit_c_ast$CInclude_t* _a5_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a5_obj, 1590u);
    _a5_obj->f_path = l0;
    _a5_obj->f_system = l1;
    t2 = (void*) _a5_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$including(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a2_obj, 1602u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l1 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a3_obj, 1590u);
    _a3_obj->f_path = l0;
    _a3_obj->f_system = false;
    l2 = (void*) _a3_obj;
    vader_emit_c_ast$print_item(l1, vader_ref_box(l2));
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$info_row(int64_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 1221u);
    l3 = std_core$write_int(l2, l3, l0);
    l3 = std_core$write_string_at(l2, l3, 1237u);
    l4 = std_core$finish_buffer(l2, l3);
    l5 = vader_emit_c_ast$initializer_list(l1);
    t0 = vader_emit_c_ast$designated(l4, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$init_object_header(void* l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c_ast$verbatim(l1);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l5 = INT64_C(0);
    l6 = ((int64_t) (int32_t) l2);
    l5 = std_core$write_int(l4, l5, l6);
    l5 = std_core$write_string_at(l4, l5, 3423u);
    t0 = std_core$finish_buffer(l4, l5);
    l7 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3611u, l4);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$integer_as_address(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c_ast$cast(2749u, l0);
    t0 = vader_emit_c_ast$cast(3701u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$integer_payload(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CCast_t* _a0_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
    vader_obj_header_init(_a0_obj, 1572u);
    _a0_obj->f_types = l0;
    _a0_obj->f_value = l1;
    l2 = (void*) _a0_obj;
    t0 = vader_emit_c_ast$designated(514u, vader_ref_box(l2));
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$internal_fn_flags(void* l0, void* l1, vader_string_t l2) {
    int64_t l3, l6, l7, l9, l10;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    int32_t l11, l12;
    bool l14;
    void* t0 = NULL;
    int32_t t1;
    bool t2, t5;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l8, &l13, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 7u, 626u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(26u, 1u, 12u, 621u);
    ((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l5 = (void*) _a3_arr;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l1));
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l8 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6);
        l9 = vader_array_length(((vader_array_t*) l8));
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l11 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l10];
            l12 = ((int32_t) (int64_t) l6);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
            ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l11] = (int32_t) l12;
            l10 = (l10 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_exports;
    l6 = vader_array_length(((vader_array_t*) l8));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l7);
        l11 = ((vader_struct_vader_core_bytecode$BcExport_t*) t0)->f_fn_index;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
        ((uint8_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l11] = (uint8_t) true;
        l7 = (l7 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_vtables;
    l6 = vader_array_length(((vader_array_t*) l8));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l7);
        l13 = ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_entries;
        l9 = vader_array_length(((vader_array_t*) l13));
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l10);
            l11 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) t0)->f_fn_index;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l11)
            ((uint8_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l11] = (uint8_t) true;
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l8 = vader_emit_c$scan_fn_value_usage(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    l6 = INT64_C(0);
    while ((l6 < l3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l8)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
        t1 = ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l6];
        if ((t1 >= INT32_C(0))) {
            l14 = true;
        } else {
            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l8)->f_is_closure);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
            t2 = ((uint8_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l6];
            l14 = t2;
        }
        if (l14) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
            ((uint8_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l6] = (uint8_t) true;
        }
        if (l2 != 0u) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) l6);
            t3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
            if (t3 == l2) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
                ((uint8_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l6] = (uint8_t) true;
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    while ((l6 < l3)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
        l11 = ((int32_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l6];
        vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l6);
        l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l7 = vader_array_length(((vader_array_t*) l8));
        l9 = INT64_C(0);
        while ((l9 < l7)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t4 = vader_array_ref_load_box(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) l9);
            l12 = vader_emit_c$callee_index_of(t4);
            if ((l12 >= INT32_C(0))) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l12)
                t1 = ((int32_t*) _a20_slotarr->buf->slots)[vader_array_offset(_a20_slotarr) + (size_t) l12];
                if (t1 != l11) {
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l12)
                    ((uint8_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l12] = (uint8_t) true;
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    if ((INT64_C(0) < l3)) {
        l6 = l3;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a22_arr = vader_array_reserve(26u, (int64_t) l6, 12u, 621u);
    l4 = (void*) _a22_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc269_hdr = (vader_array_t*) l4;
    size_t _pc269_len = vader_array_length(_pc269_hdr);
    size_t _pc269_cap = vader_array_is_borrowed(_pc269_hdr) ? (size_t) 0 : vader_array_capacity(_pc269_hdr);
    void* _pc269_slots = _pc269_hdr->buf->slots;
    for (;;) {
        if ((l6 < l3)) {
            vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
            t2 = ((uint8_t*) _a23_slotarr->buf->slots)[vader_array_offset(_a23_slotarr) + (size_t) l6];
            t5 = t2;
            l14 = !(t5);
            if (VADER_LIKELY(_pc269_len < _pc269_cap)) {
                ((uint8_t*) _pc269_slots)[_pc269_len] = (uint8_t) (l14);
                _pc269_len += 1;
            } else {
                vader_array_set_length(_pc269_hdr, _pc269_len);
                if (_pc269_hdr->buf->length < _pc269_len) {
                    _pc269_hdr->buf->length = _pc269_len;
                }
                vader_array_push_bool((vader_array_t*) l4, l14);
                _pc269_hdr = (vader_array_t*) l4;
                _pc269_len = vader_array_length(_pc269_hdr);
                _pc269_cap = vader_array_is_borrowed(_pc269_hdr) ? (size_t) 0 : vader_array_capacity(_pc269_hdr);
                _pc269_slots = _pc269_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc269_hdr, _pc269_len);
        if (_pc269_hdr->buf->length < _pc269_len) {
            _pc269_hdr->buf->length = _pc269_len;
        }
        break;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$interned(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l2, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3247u, l1);
    vader_array_t* _a1_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l2.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a1_arr;
    t0 = vader_emit_c_ast$call(3553u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$invalidate_header_cache(void* l0, vader_box_t l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1391u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        vader_emit_c$drop_bound_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1392u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        vader_emit_c$drop_bound_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_emit_c$is_cache_safe(l1);
    if (t1) {
        l3 = l1;
        l4 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_import_may_collect;
        t1 = vader_emit_c$op_may_collect(l3, l4);
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    t1 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_safepoint_free;
    if (t1) {
        t1 = vader_emit_c$is_scope_opening(l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_clear((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_clear((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_c$is_abi_array(void* l0, int32_t l1) {
    int32_t l2;
    int64_t t0;
    vader_box_t t1;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = vader_array_length(((vader_array_t*) l0));
    l2 = ((int32_t) (int64_t) t0);
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        return t1.tag == 1273u;
    }
    return false;
}

static bool vader_emit_c$is_abi_nullable_pointer(void* l0, int32_t l1) {
    int32_t l2, l9;
    vader_box_t l3;
    bool l4, l5;
    void* l6;
    int64_t l7, l8;
    int64_t t0;
    void* t1;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = vader_array_length(((vader_array_t*) l0));
    l2 = ((int32_t) (int64_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l3.tag == 1287u)) {
        return false;
    }
    t1 = l3.payload.obj;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants));
    if (t0 != INT64_C(2)) {
        return false;
    }
    l4 = false;
    l5 = false;
    t1 = l3.payload.obj;
    l6 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l8];
        if (!((l2 < INT32_C(0)))) {
            t0 = vader_array_length(((vader_array_t*) l0));
            l9 = ((int32_t) (int64_t) t0);
            if (!((l2 >= l9))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                l3 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
                if (l3.tag == 1283u) {
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val == INT32_C(13)) {
                        l4 = true;
                    }
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val == INT32_C(15)) {
                        l5 = true;
                    }
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    if (l4) {
        return l5;
    }
    return false;
}

static bool vader_emit_c$is_abi_nullable_string(void* l0, int32_t l1) {
    int32_t l2, l9;
    vader_box_t l3;
    bool l4, l5;
    void* l6;
    int64_t l7, l8;
    int64_t t0;
    void* t1;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = vader_array_length(((vader_array_t*) l0));
    l2 = ((int32_t) (int64_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l3.tag == 1287u)) {
        return false;
    }
    t1 = l3.payload.obj;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants));
    if (t0 != INT64_C(2)) {
        return false;
    }
    l4 = false;
    l5 = false;
    t1 = l3.payload.obj;
    l6 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l8];
        if (!((l2 < INT32_C(0)))) {
            t0 = vader_array_length(((vader_array_t*) l0));
            l9 = ((int32_t) (int64_t) t0);
            if (!((l2 >= l9))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                l3 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
                if (l3.tag == 1283u) {
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val == INT32_C(13)) {
                        l4 = true;
                    }
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val == INT32_C(12)) {
                        l5 = true;
                    }
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    if (l4) {
        return l5;
    }
    return false;
}

static bool vader_emit_c$is_c_reserved(vader_string_t l0) {
    void* t0;
    bool t1;
    t0 = (void*) &vader_data_30;
    t1 = std_core$$array$Contains$contains__string(t0, l0);
    return t1;
}

static bool vader_emit_c$is_cache_safe(vader_box_t l0) {
    if ((l0.tag == 1389u || l0.tag == 1390u || l0.tag == 1417u || l0.tag == 1434u)) {
        return true;
    }
    if ((l0.tag == 1385u || l0.tag == 1386u || l0.tag == 1387u)) {
        return true;
    }
    if ((l0.tag == 1409u || l0.tag == 1410u || l0.tag == 1411u)) {
        return true;
    }
    if ((l0.tag == 1262u || l0.tag == 1263u || l0.tag == 1270u)) {
        return true;
    }
    if ((l0.tag == 1382u || l0.tag == 1383u || l0.tag == 1384u || l0.tag == 1388u)) {
        return true;
    }
    if ((l0.tag == 1406u || l0.tag == 1407u || l0.tag == 1408u || l0.tag == 1412u)) {
        return true;
    }
    if ((l0.tag == 1296u || l0.tag == 1311u || l0.tag == 1324u || l0.tag == 1345u || l0.tag == 1365u)) {
        return true;
    }
    if ((l0.tag == 1315u || l0.tag == 1337u || l0.tag == 1397u || l0.tag == 1404u || l0.tag == 1414u || l0.tag == 1421u)) {
        return true;
    }
    if ((l0.tag == 1340u || l0.tag == 1346u || l0.tag == 1352u || l0.tag == 1353u || l0.tag == 1355u || l0.tag == 1359u)) {
        return true;
    }
    if ((l0.tag == 1360u || l0.tag == 1366u || l0.tag == 1372u || l0.tag == 1373u || l0.tag == 1375u || l0.tag == 1379u)) {
        return true;
    }
    if ((l0.tag == 1312u || l0.tag == 1313u)) {
        return true;
    }
    if ((l0.tag == 1323u || l0.tag == 1325u || l0.tag == 1331u || l0.tag == 1333u || l0.tag == 1334u)) {
        return true;
    }
    if ((l0.tag == 1422u || l0.tag == 1427u || l0.tag == 1428u || l0.tag == 1433u)) {
        return true;
    }
    if ((l0.tag == 1341u || l0.tag == 1342u || l0.tag == 1343u || l0.tag == 1344u || l0.tag == 1356u || l0.tag == 1357u || l0.tag == 1358u)) {
        return true;
    }
    if ((l0.tag == 1361u || l0.tag == 1362u || l0.tag == 1363u || l0.tag == 1364u || l0.tag == 1376u || l0.tag == 1377u || l0.tag == 1378u)) {
        return true;
    }
    if ((l0.tag == 1347u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1350u || l0.tag == 1351u || l0.tag == 1354u)) {
        return true;
    }
    if ((l0.tag == 1367u || l0.tag == 1368u || l0.tag == 1369u || l0.tag == 1370u || l0.tag == 1371u || l0.tag == 1374u)) {
        return true;
    }
    if ((l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1332u)) {
        return true;
    }
    if ((l0.tag == 1423u || l0.tag == 1424u || l0.tag == 1425u || l0.tag == 1426u || l0.tag == 1429u || l0.tag == 1430u || l0.tag == 1431u || l0.tag == 1432u)) {
        return true;
    }
    if ((l0.tag == 1297u || l0.tag == 1298u)) {
        return true;
    }
    if ((l0.tag == 1399u || l0.tag == 1400u || l0.tag == 1413u || l0.tag == 1415u || l0.tag == 1416u)) {
        return true;
    }
    if ((l0.tag == 1295u || l0.tag == 1299u || l0.tag == 1300u)) {
        return true;
    }
    if ((l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1314u || l0.tag == 1322u || l0.tag == 1335u || l0.tag == 1398u || l0.tag == 1401u)) {
        return true;
    }
    if (!(l0.tag == 1319u)) {
        return false;
    }
    return true;
}

static bool vader_emit_c$is_continue_branch(void* l0, int32_t l1) {
    int32_t t0, t1;
    if (((vader_struct_vader_emit_c$ScopeInfo_t*) l0)->f_kind == INT32_C(1)) {
        t0 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l0)->f_opener_pc;
        t1 = vader_chk_add(i32, t0, INT32_C(1));
        return t1 == l1;
    }
    return false;
}

static bool vader_emit_c$is_pure_read(vader_box_t l0) {
    vader_box_t t0;
    if ((l0.tag == 1389u || l0.tag == 1390u)) {
        return true;
    }
    t0 = vader_core_bytecode$const_op_of(l0);
    return !(t0.tag == 0u);
}

static bool vader_emit_c$is_ref_val(uint8_t l0) {
    if (l0 == INT32_C(16)) {
        return true;
    }
    return l0 == INT32_C(17);
}

static bool vader_emit_c$is_scope_opening(vader_box_t l0) {
    return (l0.tag == 1294u || l0.tag == 1380u || l0.tag == 1393u);
}

static bool vader_emit_c$is_tail_forwarder(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4;
    vader_box_t t0;
    bool t1;
    l2 = vader_emit_c$leading_pure_reads(l1);
    l3 = vader_array_length(((vader_array_t*) l1));
    if (l2 == l3) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    l4 = vader_emit_c$safepoint_result_arity(l0, l4, l2);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int64_t) l4.payload.i);
    l2 = vader_chk_add(i64, l2, INT64_C(1));
    if (l3 == INT64_C(1)) {
        l3 = vader_array_length(((vader_array_t*) l1));
        if ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
            if (t0.tag == 1319u) {
                l3 = vader_chk_add(i64, l2, INT64_C(1));
                t1 = vader_emit_c$returns_at(l1, l3);
                return t1;
            }
            t1 = vader_emit_c$returns_at(l1, l2);
            return t1;
        }
        t1 = vader_emit_c$returns_at(l1, l2);
        return t1;
    }
    t1 = vader_emit_c$returns_at(l1, l2);
    return t1;
}

static int64_t vader_emit_c$leading_pure_reads(void* l0) {
    int64_t l1, l2;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    l1 = INT64_C(0);
    l2 = vader_array_length(((vader_array_t*) l0));
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        t1 = vader_emit_c$is_pure_read(t0);
        if (!(t1)) {
            return l1;
        }
        l1 = (l1 + INT64_C(1));
    }
    t2 = vader_array_length(((vader_array_t*) l0));
    return t2;
}

static vader_box_t vader_emit_c$left_operand(void* l0, uint8_t l1, vader_box_t l2, vader_box_t l3, uint8_t l4) {
    vader_box_t l5 = vader_box_null();
    bool l6;
    uint8_t l7;
    uint8_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l5, &t2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_emit_c$operand_as(l0, l2, l4);
    t0 = vader_emit_c$val_of(l2);
    t1 = vader_emit_c$signed_under_unsigned(t0, l4);
    if (!(t1)) {
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(6)) {
        l6 = true;
    } else {
        t0 = vader_emit_c$val_of(l3);
        l6 = vader_emit_c$signed_under_unsigned(t0, l4);
    }
    if (!(l6)) {
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_emit_c$val_of(l2);
    t2 = vader_emit_c$scalar_cast(l5, l7, l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$library_open_shim(vader_string_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[6] = { &l1, &l3, &l4, &l5, &l6, &t0 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3659u, l2);
    l3 = vader_emit_c_ast$declaration(2285u, 2164u, l3);
    t0 = vader_emit_c_ast$verbatim(2164u);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(l0, l2);
    l4 = vader_emit_c_ast$declaration(3701u, 3087u, l4);
    l5 = vader_emit_c_ast$verbatim(2164u);
    vader_array_t* _a2_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l5.payload.obj;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l1.payload.obj;
    l2 = (void*) _a2_arr;
    l5 = vader_emit_c_ast$perform(3577u, l2);
    vader_array_t* _a3_arr = vader_array_new(266u, 0u, 13u, 1566u);
    l2 = (void*) _a3_arr;
    t0 = vader_emit_c_ast$verbatim(3087u);
    l6 = vader_emit_c$address_as_integer(t0);
    vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a4_obj, 1604u);
    _a4_obj->f_stores = l2;
    _a4_obj->f_value = l6;
    _a4_obj->f_snapshot_type = 0u;
    _a4_obj->f_pops_frame = false;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(487u, 4u, 13u, 2782u);
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 3u] = l2;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 2u] = l5.payload.obj;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l4.payload.obj;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = l3.payload.obj;
    t1 = (void*) _a5_arr;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$library_unit_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_support_text$sanitise_ident(l0);
    t0 = concat_2(1296u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$lift_signature(void* l0, vader_string_t l1, void* l2) {
    vader_string_t l3 = 0;
    int64_t l4;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(3592u, l1);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    t1 = vader_emit_c$erased_wrapper_signature(l0, l3, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$lift_unbox_tail(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3, l5, l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    uint8_t l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l7, &l9, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(1);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l2, 628u);
        if (((int32_t) t0.payload.i) != INT32_C(14)) {
            l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l4, l5, 1793u);
            l6 = vader_chk_sub(i64, l2, INT64_C(1));
            l5 = std_core$write_int(l4, l5, l6);
            t1 = std_core$finish_buffer(l4, l5);
            l7 = vader_emit_c_ast$verbatim(t1);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l2, 628u);
            l8 = ((uint8_t) t0.payload.i);
            l9 = vader_emit_c$unbox_expr(l7, l8);
            vader_array_push_ref((vader_array_t*) l1, l9.payload.obj);
        }
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$literal_within(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    bool l3;
    void* t0;
    int64_t t1;
    if (!(l0.tag == 1559u)) {
        return false;
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_expression;
    if (l2.tag == 1593u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_value;
        l3 = (t1 >= INT64_C(0));
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_value;
        return (t1 <= l1);
    }
    return false;
}

static void* vader_emit_c$main_body(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    int32_t l5, l10;
    bool l7;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t* gc_roots[5] = { &l2, &l6, &l12, &l13, &t0 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l8, &l9, &l11 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$verbatim(2006u);
    t0 = vader_emit_c_ast$cast(3699u, l2);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 1582u);
    _a0_obj->f_expression = t0;
    l3 = (void*) _a0_obj;
    l2 = vader_emit_c_ast$verbatim(2010u);
    t0 = vader_emit_c_ast$cast(3699u, l2);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 1582u);
    _a1_obj->f_expression = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(487u, 2u, 13u, 2782u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3;
    l3 = (void*) _a2_arr;
    l2 = vader_core_bytecode$entry_function_index(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a3_arr = vader_array_new(266u, 0u, 13u, 1566u);
        l4 = (void*) _a3_arr;
        l6 = vader_emit_c_ast$number(INT64_C(0));
        vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a4_obj, 1604u);
        _a4_obj->f_stores = l4;
        _a4_obj->f_value = l6;
        _a4_obj->f_snapshot_type = 0u;
        _a4_obj->f_pops_frame = false;
        l4 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l3, l4);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((int32_t) l2.payload.i);
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature)->f_params));
    l7 = t1 == INT64_C(1);
    l2 = vader_emit_c_ast$verbatim(3550u);
    l6 = vader_emit_c_ast$verbatim(1172u);
    vader_array_t* _a6_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l6.payload.obj;
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l2.payload.obj;
    l8 = (void*) _a6_arr;
    t0 = vader_emit_c_ast$perform(3552u, l8);
    vader_array_t* _a7_arr = vader_array_new(487u, 1u, 13u, 2782u);
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0.payload.obj;
    l8 = (void*) _a7_arr;
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    if ((t1 > INT64_C(0))) {
        l2 = vader_emit_c_ast$verbatim(3604u);
        t0 = vader_emit_c_ast$verbatim(3608u);
        l6 = vader_emit_c_ast$address_of(t0);
        vader_struct_vader_emit_c_ast$CAssign_t* _a8_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a8_obj, 1566u);
        _a8_obj->f_target = l2;
        _a8_obj->f_value = l6;
        _a8_obj->f_operator = vader_box_obj(0u, NULL);
        l9 = (void*) _a8_obj;
        vader_array_push_ref((vader_array_t*) l8, l9);
    }
    t0 = vader_emit_c_ast$verbatim(3554u);
    vader_array_t* _a9_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0.payload.obj;
    l9 = (void*) _a9_arr;
    l2 = vader_emit_c_ast$perform(2067u, l9);
    vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
    t0 = vader_emit_c_ast$verbatim(3603u);
    vader_array_t* _a10_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t0.payload.obj;
    l9 = (void*) _a10_arr;
    l2 = vader_emit_c_ast$perform(2067u, l9);
    vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
    vader_array_t* _a11_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l9 = (void*) _a11_arr;
    if (l7) {
        l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_string_tag;
        l10 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_string_array_tag;
        if ((l5 < INT32_C(0))) {
            l7 = true;
        } else {
            l7 = (l10 < INT32_C(0));
        }
        if (l7) {
            vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l3);
            l2 = vader_emit_c$trap(2873u);
            vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
            vader_array_t* _a12_arr = vader_array_new(266u, 0u, 13u, 1566u);
            l11 = (void*) _a12_arr;
            l2 = vader_emit_c_ast$number(INT64_C(1));
            vader_struct_vader_emit_c_ast$CReturn_t* _a13_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a13_obj, 1604u);
            _a13_obj->f_stores = l11;
            _a13_obj->f_value = l2;
            _a13_obj->f_snapshot_type = 0u;
            _a13_obj->f_pops_frame = false;
            l11 = (void*) _a13_obj;
            vader_array_push_ref((vader_array_t*) l8, l11);
            { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_emit_c_ast$verbatim(2006u);
        l6 = vader_emit_c_ast$verbatim(2010u);
        l12 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l10));
        l13 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l5));
        vader_array_t* _a14_arr = vader_array_new(486u, 4u, 13u, 2777u);
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 3u] = l13.payload.obj;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 2u] = l12.payload.obj;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l6.payload.obj;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l2.payload.obj;
        l11 = (void*) _a14_arr;
        l2 = vader_emit_c_ast$call(3619u, l11);
        vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a15_slotarr, vader_array_offset(_a15_slotarr) + (size_t) INT32_C(0), 628u);
        if (((int32_t) t0.payload.i) == INT32_C(16)) {
            l6 = vader_emit_c_ast$cast(3701u, l2);
            l6 = vader_emit_c_ast$declaration(3701u, 1261u, l6);
            vader_array_push_ref((vader_array_t*) l8, l6.payload.obj);
        } else {
            t0 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l10));
            vader_array_t* _a16_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 1u] = l2.payload.obj;
            ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0.payload.obj;
            l11 = (void*) _a16_arr;
            l2 = vader_emit_c_ast$call(3558u, l11);
            l2 = vader_emit_c_ast$declaration(3560u, 1261u, l2);
            vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
        }
        l2 = vader_emit_c_ast$verbatim(1261u);
        vader_array_push_ref((vader_array_t*) l9, l2.payload.obj);
    } else {
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l3);
    }
    t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    t3 = vader_emit_c$sanitise(t2);
    l2 = vader_emit_c_ast$call(t3, l9);
    t4 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature);
    if (t4 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a17_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a17_obj, 1582u);
        _a17_obj->f_expression = l2;
        l3 = (void*) _a17_obj;
        vader_array_push_ref((vader_array_t*) l8, l3);
        vader_array_t* _a18_arr = vader_array_new(266u, 0u, 13u, 1566u);
        l3 = (void*) _a18_arr;
        t0 = vader_emit_c_ast$number(INT64_C(0));
        vader_array_t* _a19_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0.payload.obj;
        l4 = (void*) _a19_arr;
        l6 = vader_emit_c_ast$call(3622u, l4);
        vader_struct_vader_emit_c_ast$CReturn_t* _a20_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a20_obj, 1604u);
        _a20_obj->f_stores = l3;
        _a20_obj->f_value = l6;
        _a20_obj->f_snapshot_type = 0u;
        _a20_obj->f_pops_frame = false;
        l3 = (void*) _a20_obj;
        vader_array_push_ref((vader_array_t*) l8, l3);
        { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a21_arr = vader_array_new(266u, 0u, 13u, 1566u);
    l3 = (void*) _a21_arr;
    t0 = vader_emit_c_ast$cast(2728u, l2);
    vader_array_t* _a22_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t0.payload.obj;
    l4 = (void*) _a22_arr;
    l2 = vader_emit_c_ast$call(3622u, l4);
    vader_struct_vader_emit_c_ast$CReturn_t* _a23_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a23_obj, 1604u);
    _a23_obj->f_stores = l3;
    _a23_obj->f_value = l2;
    _a23_obj->f_snapshot_type = 0u;
    _a23_obj->f_pops_frame = false;
    l3 = (void*) _a23_obj;
    vader_array_push_ref((vader_array_t*) l8, l3);
    { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$materialise_entry(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t1 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$val_of(l1);
    if (!(l2 == INT32_C(14))) {
        l4 = vader_emit_c$new_temporary(l0, l2);
        l3 = vader_emit_c$expression_of(l1);
        vader_emit_c$assign(l0, vader_ref_box(l4), l3);
        vader_struct_vader_emit_c$StackTemporary_t* _a0_obj = (vader_struct_vader_emit_c$StackTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackTemporary_t));
        vader_obj_header_init(_a0_obj, 1562u);
        _a0_obj->f_temporary = l4;
        _a0_obj->f_val = l2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_emit_c$expression_of(l1);
    t1 = vader_emit_c$evaluated_void(l0, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$materialize_stack_for_slot(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    void* l5 = NULL;
    bool t0;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        t0 = vader_emit_c$entry_needs_materialise(l4, l1);
        if (t0) {
            l5 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
            l6 = vader_emit_c$materialise_entry(l0, l4);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            vader_array_ref_store(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2, l6.payload.obj);
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_emit_c$max_fn_arity(void* l0) {
    int64_t l1, l3, l4;
    void* l2;
    vader_box_t l5;
    void* t0;
    int64_t t1;
    l1 = INT64_C(0);
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        if (l5.tag == 1276u) {
            t0 = l5.payload.obj;
            t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params));
            if ((t1 > l1)) {
                t0 = l5.payload.obj;
                l1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params));
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    return l1;
}

static bool vader_emit_c$may_hold_reference(vader_box_t l0) {
    uint8_t t0;
    bool t1;
    t0 = vader_emit_c$val_of(l0);
    t1 = vader_emit_c$is_ref_val(t0);
    return t1;
}

static void* vader_emit_c$mirror_crossings(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7, l8, l9;
    int32_t l10, l11;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 621u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 888u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__i32_t* _a4_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a4_obj, 1070u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 626u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(26u, 0u, 12u, 621u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 626u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a8_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a8_obj, 888u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$Set__i32_t* _a9_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a9_obj, 1070u);
    _a9_obj->f_inner = t0;
    l3 = (void*) _a9_obj;
    l4 = l0;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l5 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l7);
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_is_extern;
        if (t1) {
            l8 = INT64_C(0);
            l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature)->f_param_types));
            while ((l8 < l9)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
                l10 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l8];
                t2 = vader_core_bytecode$mirror_at(l1, l10);
                if (t2.tag == 0u) {
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
                t1 = vader_core_bytecode$param_is_by_address(((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature, l8);
                if (t1) {
                    std_collections$add__i32(l2, l10);
                } else {
                    std_collections$add__i32(l3, l10);
                }
                l8 = (l8 + INT64_C(1));
            }
            l11 = vader_core_bytecode$bc_single_result_type(((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature);
            t2 = vader_core_bytecode$mirror_at(l1, l11);
            if (!(t2.tag == 0u)) {
                std_collections$add__i32(l3, l11);
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_emit_c$MirrorCrossings_t* _a12_obj = (vader_struct_vader_emit_c$MirrorCrossings_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$MirrorCrossings_t));
    vader_obj_header_init(_a12_obj, 1553u);
    _a12_obj->f_lent = l2;
    _a12_obj->f_copied = l3;
    t0 = (void*) _a12_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$mirror_result(void* l0, int32_t l1, vader_string_t l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_string_t l7 = 0;
    int64_t l9, l10;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[5] = { &l3, &l11, &l12, &l13, &t1 };
    void** gc_raw_roots[6] = { &l0, &l4, &l5, &l6, &l8, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l6 = (void*) _a2_arr;
    l7 = vader_emit_c$push_mirror_allocation(l0, l1, l4, l5, l6, INT32_C(0));
    vader_array_t* _a3_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l8 = (void*) _a3_arr;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l5);
    t0 = vader_array_length(((vader_array_t*) l4));
    if (t0 == INT64_C(1)) {
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
    } else {
        vader_array_t* _a4_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a4_arr;
        l9 = vader_array_length(((vader_array_t*) l4));
        vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l4, (int64_t) INT64_C(1), (int64_t) l9);
        l4 = (void*) _a5_arr;
        l9 = vader_array_length(((vader_array_t*) l4));
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l10];
            t2 = t1.payload.s;
            t1 = vader_emit_c_ast$verbatim(t2);
            l11 = vader_emit_c_ast$address_of(t1);
            l12 = vader_emit_c_ast$cast(3702u, l11);
            vader_array_push_ref((vader_array_t*) l5, l12.payload.obj);
            l10 = (l10 + INT64_C(1));
        }
        l11 = vader_emit_c_ast$verbatim(1284u);
        l12 = vader_emit_c_ast$array_declaration(3702u, 1285u, l5);
        vader_array_push_ref((vader_array_t*) l8, l12.payload.obj);
        t0 = vader_array_length(((vader_array_t*) l5));
        l12 = vader_emit_c_ast$number(t0);
        l13 = vader_emit_c_ast$verbatim(1285u);
        vader_array_t* _a7_arr = vader_array_new(486u, 3u, 13u, 2777u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 2u] = l12.payload.obj;
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = l13.payload.obj;
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l11.payload.obj;
        l4 = (void*) _a7_arr;
        l12 = vader_emit_c_ast$perform(1176u, l4);
        vader_array_push_ref((vader_array_t*) l8, l12.payload.obj);
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
        vader_array_t* _a8_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l11.payload.obj;
        l4 = (void*) _a8_arr;
        l11 = vader_emit_c_ast$perform(1175u, l4);
        vader_array_push_ref((vader_array_t*) l8, l11.payload.obj);
    }
    l4 = vader_emit_c$bc_struct_fields(l0, l1);
    l11 = vader_emit_c_ast$verbatim(3087u);
    l12 = vader_emit_c_ast$verbatim(l7);
    vader_emit_c$push_member_copies(l0, l4, l11, l12, false, l8, INT32_C(0));
    l11 = vader_emit_c_ast$declaration(l2, 3087u, l3);
    l12 = vader_emit_c_ast$verbatim(l7);
    vader_struct_vader_emit_c$ForwardedResult_t* _a9_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
    vader_obj_header_init(_a9_obj, 1552u);
    _a9_obj->f_capture = l11;
    _a9_obj->f_settle = l8;
    _a9_obj->f_returned = l12;
    t3 = (void*) _a9_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$mirrored_c_struct(void* l0, int32_t l1) {
    void* l2;
    vader_box_t l3;
    vader_string_t t0;
    l3 = vader_core_bytecode$mirror_at(l0, l1);
    if (l3.tag == 0u) {
        return 0u;
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_c_name;
    return t0;
}

static uint8_t vader_emit_c$module_function_storage(void* l0, int32_t l1) {
    int64_t l2, l4;
    bool l3;
    bool t0, t1;
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    if (!(t0)) {
        return (uint8_t) 0;
    }
    l2 = ((int64_t) (int32_t) l1);
    if ((INT64_C(0) <= l2)) {
        l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_internal_fns));
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_internal_fns);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
        t1 = t0;
        if (t1) {
            return (uint8_t) 0;
        }
        return (uint8_t) 1;
    }
    return (uint8_t) 1;
}

static vader_box_t vader_emit_c$monitor_give(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    bool l3;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(16)) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a0_arr;
        l1 = vader_emit_c_ast$perform(3628u, l2);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        l3 = true;
    } else {
        l3 = l0 == INT32_C(13);
    }
    if (l3) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a1_arr;
        l1 = vader_emit_c_ast$perform(3627u, l2);
    } else {
        if (l0 == INT32_C(0)) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(1);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(2);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(3);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(4);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(5);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(6);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(7);
        }
        if (l3) {
            l1 = vader_emit_c$monitor_take_alone();
        } else {
            if (l0 == INT32_C(8)) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(9);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(10);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(11);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(12);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(14);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(15);
            }
            if (!(l3)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l1 = vader_emit_c$monitor_take_alone();
        }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$monitor_take_alone(void) {
    void* l0 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c_ast$verbatim(2502u);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l0 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$perform(3625u, l0);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$needs_frame(void* l0, int32_t l1, void* l2) {
    void* l3;
    void* l4;
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_may_alloc);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    t1 = t0;
    if (!(t1)) {
        t0 = vader_emit_c$fn_builds_stack_object(l2);
        return t0;
    }
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body;
    t0 = vader_emit_c$is_tail_forwarder(l3, l4);
    return !(t0);
}

static void* vader_emit_c$new_ctx(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int32_t l4, l11, l12, l13;
    int64_t l6;
    bool l14, l15, l16;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &l9, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$struct_c_names_of(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l4 = vader_emit_c$string_primitive_tag(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l5 = vader_emit_c$imports_may_collect(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports);
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
    vader_struct___lambda_env_vader_emit_c_2_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_2_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_cap_0 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 553u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_emit_c_1;
    _a1_closure->env = t0;
    l7 = (void*) _a1_closure;
    l7 = std_core$filled_indexed__i32__(l6, l7);
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings;
    l9 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_atom_universe;
    l8 = vader_emit_c$compute_atom_ids(l8, l9);
    l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings;
    l10 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_atom_universe;
    l9 = vader_emit_c$atom_table_of(l9, l10);
    l11 = vader_emit_c$class_tag_of(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types, (uint8_t) 13);
    l12 = vader_emit_c$class_tag_of(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types, (uint8_t) 14);
    l13 = vader_emit_c$string_array_tag(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types, l4);
    l10 = vader_emit_c$compute_may_alloc(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions, l5);
    l14 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_split;
    l15 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_verify_bounds;
    l16 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_library_units;
    vader_struct_vader_emit_c$EmitCtx_t* _a2_obj = (vader_struct_vader_emit_c$EmitCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$EmitCtx_t));
    vader_obj_header_init(_a2_obj, 1549u);
    _a2_obj->f_module = l0;
    _a2_obj->f_struct_c_names = l3;
    _a2_obj->f_atom_ids = l8;
    _a2_obj->f_atom_table = l9;
    _a2_obj->f_null_tag = l11;
    _a2_obj->f_void_tag = l12;
    _a2_obj->f_string_tag = l4;
    _a2_obj->f_string_array_tag = l13;
    _a2_obj->f_may_alloc = l10;
    _a2_obj->f_import_may_collect = l5;
    _a2_obj->f_split = l14;
    _a2_obj->f_internal_fns = l2;
    _a2_obj->f_verify_bounds = l15;
    _a2_obj->f_library_units = l16;
    _a2_obj->f_layout_siblings = l7;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$new_fn_state(void* l0, int32_t l1, void* l2) {
    bool l3, l10;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* t0 = NULL;
    bool t1, t2;
    void** gc_raw_roots[13] = {
        &l0, &l2, &l4, &l5, &l6, &l7, &l8, &l9, &l11, &l12, &l13, &l14, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$needs_frame(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(487u, 0u, 13u, 2782u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1568u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(485u, 0u, 13u, 2776u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(273u, 0u, 13u, 1614u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(264u, 0u, 13u, 1556u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 626u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 626u);
    l9 = (void*) _a6_arr;
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_may_alloc);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
    t1 = ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l1];
    t2 = t1;
    if (!(t2)) {
        l10 = !(l3);
    } else {
        l10 = false;
    }
    vader_array_t* _a8_arr = vader_array_new(263u, 0u, 13u, 1555u);
    l11 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(262u, 0u, 13u, 1545u);
    l12 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(265u, 0u, 13u, 1561u);
    l13 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(490u, 0u, 13u, 2792u);
    l14 = (void*) _a11_arr;
    vader_struct_vader_emit_c$FnState_t* _a12_obj = (vader_struct_vader_emit_c$FnState_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$FnState_t));
    vader_obj_header_init(_a12_obj, 1550u);
    _a12_obj->f_ctx = l0;
    _a12_obj->f_function = l2;
    _a12_obj->f_root = l4;
    _a12_obj->f_stack = l5;
    _a12_obj->f_temporaries = l6;
    _a12_obj->f_aux_counter = INT32_C(0);
    _a12_obj->f_scopes = l7;
    _a12_obj->f_continue_targets = l8;
    _a12_obj->f_break_targets = l9;
    _a12_obj->f_safepoint_free = l10;
    _a12_obj->f_needs_frame = l3;
    _a12_obj->f_push_caches = l11;
    _a12_obj->f_bound_arrays = l12;
    _a12_obj->f_drop_call_result = false;
    _a12_obj->f_stack_storages = l13;
    _a12_obj->f_open_nodes = l14;
    t0 = (void*) _a12_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$new_temporary(void* l0, uint8_t l1) {
    void* l2 = NULL;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_temporaries));
    vader_struct_vader_emit_c_ast$CTemporary_t* _a0_obj = (vader_struct_vader_emit_c_ast$CTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CTemporary_t));
    vader_obj_header_init(_a0_obj, 1614u);
    _a0_obj->f_id = ((int32_t) (int64_t) t0);
    _a0_obj->f_val = l1;
    _a0_obj->f_slot = INT32_C(-1);
    l2 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_temporaries, l2);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$null_member(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_2(l0, 432u);
    l3 = vader_emit_c_ast$number(INT64_C(0));
    t0 = vader_emit_c_ast$pointer_member(l2, l3, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$null_or(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l3, &l4 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_70;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l3 = vader_emit_c_ast$binary((uint8_t) 11, l0, vader_ref_box(l2));
    vader_array_t* _a1_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l2 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(3557u, l2);
    vader_struct_vader_emit_c_ast$CConditional_t* _a2_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
    vader_obj_header_init(_a2_obj, 1575u);
    _a2_obj->f_condition = l3;
    _a2_obj->f_then_value = l4;
    _a2_obj->f_else_value = l1;
    t0 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$object_header(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$call(1183u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$object_pointer(vader_box_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(16)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_emit_c$payload(l0, 3007u);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$object_pointer_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    uint8_t l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    l2 = vader_emit_c$val_of(l0);
    t0 = vader_emit_c$object_pointer(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$one_variant_check(void* l0, vader_box_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t2 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    if (l3.tag == 1282u) {
        t0 = l3.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
        if (t1 != 0u) {
            l4 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx;
            t0 = l3.payload.obj;
            l5 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
            t2 = vader_emit_c$trait_check_expr(l4, l1, l5, l2);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l3.tag == 1283u) {
        t0 = l3.payload.obj;
        t3 = vader_core_bytecode$is_float_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
        if (t3) {
            t2 = vader_emit_c$float_tag_check_expr(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types, l1);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_emit_c$tag_equals(l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_emit_c$tag_equals(l1, l2);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_emit_c$op_may_collect(vader_box_t l0, void* l1) {
    bool l2;
    int32_t l3;
    void* t0;
    bool t1;
    if (l0.tag == 1418u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        l2 = !(t1);
        return l2;
    }
    if (l0.tag == 1309u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
        l2 = t1;
    } else if ((l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1271u || l0.tag == 1303u || l0.tag == 1304u || l0.tag == 1310u || l0.tag == 1336u || l0.tag == 1394u || l0.tag == 1437u)) {
        l2 = true;
    } else if ((l0.tag == 1338u || l0.tag == 1339u)) {
        l2 = false;
    } else {
        if (!((l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1262u || l0.tag == 1263u || l0.tag == 1267u || l0.tag == 1270u || l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1294u || l0.tag == 1295u || l0.tag == 1296u || l0.tag == 1297u || l0.tag == 1298u || l0.tag == 1299u || l0.tag == 1300u || l0.tag == 1301u || l0.tag == 1302u || l0.tag == 1305u || l0.tag == 1308u || l0.tag == 1311u || l0.tag == 1312u || l0.tag == 1313u || l0.tag == 1314u || l0.tag == 1315u || l0.tag == 1317u || l0.tag == 1318u || l0.tag == 1319u || l0.tag == 1320u || l0.tag == 1321u || l0.tag == 1322u || l0.tag == 1323u || l0.tag == 1324u || l0.tag == 1325u || l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1333u || l0.tag == 1334u || l0.tag == 1335u || l0.tag == 1337u || l0.tag == 1340u || l0.tag == 1341u || l0.tag == 1342u || l0.tag == 1343u || l0.tag == 1344u || l0.tag == 1345u || l0.tag == 1346u || l0.tag == 1347u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1350u || l0.tag == 1351u || l0.tag == 1352u || l0.tag == 1353u || l0.tag == 1354u || l0.tag == 1355u || l0.tag == 1356u || l0.tag == 1357u || l0.tag == 1358u || l0.tag == 1359u || l0.tag == 1360u || l0.tag == 1361u || l0.tag == 1362u || l0.tag == 1363u || l0.tag == 1364u || l0.tag == 1365u || l0.tag == 1366u || l0.tag == 1367u || l0.tag == 1368u || l0.tag == 1369u || l0.tag == 1370u || l0.tag == 1371u || l0.tag == 1372u || l0.tag == 1373u || l0.tag == 1374u || l0.tag == 1375u || l0.tag == 1376u || l0.tag == 1377u || l0.tag == 1378u || l0.tag == 1379u || l0.tag == 1380u || l0.tag == 1382u || l0.tag == 1383u || l0.tag == 1384u || l0.tag == 1385u || l0.tag == 1386u || l0.tag == 1387u || l0.tag == 1388u || l0.tag == 1389u || l0.tag == 1390u || l0.tag == 1391u || l0.tag == 1392u || l0.tag == 1393u || l0.tag == 1396u || l0.tag == 1397u || l0.tag == 1398u || l0.tag == 1399u || l0.tag == 1400u || l0.tag == 1401u || l0.tag == 1402u || l0.tag == 1403u || l0.tag == 1404u || l0.tag == 1406u || l0.tag == 1407u || l0.tag == 1408u || l0.tag == 1409u || l0.tag == 1410u || l0.tag == 1411u || l0.tag == 1412u || l0.tag == 1413u || l0.tag == 1414u || l0.tag == 1415u || l0.tag == 1416u || l0.tag == 1417u || l0.tag == 1419u || l0.tag == 1420u || l0.tag == 1421u || l0.tag == 1422u || l0.tag == 1423u || l0.tag == 1424u || l0.tag == 1425u || l0.tag == 1426u || l0.tag == 1427u || l0.tag == 1428u || l0.tag == 1429u || l0.tag == 1430u || l0.tag == 1431u || l0.tag == 1432u || l0.tag == 1433u || l0.tag == 1434u || l0.tag == 1435u || l0.tag == 1436u || l0.tag == 1438u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    return l2;
}

static void vader_emit_c$open_else(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2;
    vader_box_t l3 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes));
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    if (!(l3.tag == 1589u)) {
        vader_host_std_core$Intrinsic$panic(2169u);
        vader_unreachable("a no-return call returned");
    }
    l1 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(487u, 0u, 13u, 2782u);
    t1 = (void*) _a1_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a2_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a2_obj, 1568u);
    _a2_obj->f_body = t1;
    l4 = (void*) _a2_obj;
    ((vader_struct_vader_emit_c_ast$CIf_t*) l1)->f_else_block = vader_ref_box(l4);
    VADER_WRITE_BARRIER((vader_struct_vader_emit_c_ast$CIf_t*) l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$open_if(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(487u, 0u, 13u, 2782u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1568u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CIf_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIf_t));
    vader_obj_header_init(_a2_obj, 1589u);
    _a2_obj->f_condition = l1;
    _a2_obj->f_then_block = l2;
    _a2_obj->f_else_block = vader_box_obj(0u, NULL);
    _a2_obj->f_end_label = 0u;
    l2 = (void*) _a2_obj;
    vader_emit_c$open_node(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$open_node(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_emit_c$append_statement(l0, l1);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes, l1.payload.obj);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$open_scope(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(487u, 0u, 13u, 2782u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1568u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CScope_t* _a2_obj = (vader_struct_vader_emit_c_ast$CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CScope_t));
    vader_obj_header_init(_a2_obj, 1605u);
    _a2_obj->f_label = l1;
    _a2_obj->f_body = l2;
    _a2_obj->f_end_label = 0u;
    l2 = (void*) _a2_obj;
    vader_emit_c$open_node(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$operand_as(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    uint8_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l4 = vader_emit_c$expression_of(l1);
    l5 = vader_emit_c$val_of(l1);
    t0 = vader_emit_c$coerce_operand(l3, l4, l5, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$out_param_name(int64_t l0) {
    void* l1 = NULL;
    int64_t l2;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(23));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 1277u);
    l2 = std_core$write_int(l1, l2, l0);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$partition_functions(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    int32_t l6;
    vader_string_t l7 = 0;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 634u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any___t* _a3_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
    vader_obj_header_init(_a3_obj, 971u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = vader_emit_c$sorted_fn_indices(l0);
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l6 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l5];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l7 = vader_core_mangle$mangle_module_part(t1);
        l3 = (void*) &vader_fn_static___lambda_vader_emit_c_0;
        t0 = std_collections$get_or_put_with__string__i32__(l1, l7, l3);
        vader_array_push_i32((vader_array_t*) t0, l6);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 626u);
    t0 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(4u, 1u, 13u, 29u);
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0;
    l2 = (void*) _a7_arr;
    l3 = vader_emit_c$sorted_module_stems(l1);
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t2 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l5];
        l7 = t2.payload.s;
        l8 = std_collections$Map$std_core$Index$at__string__Any(l1, l7);
        if (l8.tag == 0u) {
            vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 626u);
            l9 = (void*) _a9_arr;
        } else {
            l9 = l8.payload.obj;
        }
        vader_array_push_ref((vader_array_t*) l2, l9);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$payload(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_2(3066u, l1);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 1596u);
    _a0_obj->f_base = l0;
    _a0_obj->f_member = l2;
    _a0_obj->f_arrow = false;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$payload_cast(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$payload(l1, l2);
    t0 = vader_emit_c_ast$cast(l0, l3);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1600u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$pc_active_for(void* l0, int32_t l1) {
    int64_t l2;
    void* l3;
    int32_t t0;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches));
    if (l2 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches;
    l2 = vader_chk_sub(i64, l2, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    t0 = ((vader_struct_vader_emit_c$PushCache_t*) l3)->f_slot;
    if (!(t0 != l1)) {
        return vader_ref_box(l3);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_c$pc_capacity(int32_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t0 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pc_local(l0, 2628u);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3519u, l1);
    l3 = vader_emit_c_ast$verbatim(553u);
    l3 = vader_emit_c_ast$cast(3185u, l3);
    t0 = vader_emit_c$pc_local(l0, 2628u);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(3516u, l1);
    vader_struct_vader_emit_c_ast$CConditional_t* _a2_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
    vader_obj_header_init(_a2_obj, 1575u);
    _a2_obj->f_condition = l2;
    _a2_obj->f_then_value = l3;
    _a2_obj->f_else_value = l4;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$pc_close_cache(void* l0, int32_t l1) {
    int64_t l2;
    void* l3 = NULL;
    int32_t l4;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches));
    if (l2 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches;
    l2 = vader_chk_sub(i64, l2, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    t0 = ((vader_struct_vader_emit_c$PushCache_t*) l3)->f_opener_pc;
    if (!(t0 != l1)) {
        l4 = ((vader_struct_vader_emit_c$PushCache_t*) l3)->f_opener_pc;
        vader_emit_c$pc_emit_writeback(l0, l4);
        t1 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$pc_emit_preheader(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$PushCache_t*) l1)->f_opener_pc;
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1301u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1298u);
    l6 = std_core$finish_buffer(l3, l4);
    t0 = ((vader_struct_vader_emit_c$PushCache_t*) l1)->f_slot;
    vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
    vader_obj_header_init(_a0_obj, 1594u);
    _a0_obj->f_slot = t0;
    t1 = (void*) _a0_obj;
    l7 = vader_emit_c$array_pointer(vader_ref_box(t1));
    vader_emit_c$declare(l0, 3548u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1301u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1299u);
    l6 = std_core$finish_buffer(l3, l4);
    t2 = vader_emit_c$pc_local(l2, 2628u);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t2.payload.obj;
    l3 = (void*) _a1_arr;
    l7 = vader_emit_c_ast$call(3520u, l3);
    vader_emit_c$declare(l0, 3185u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1301u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1291u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_capacity(l2);
    vader_emit_c$declare(l0, 3185u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1301u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1305u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_header(l2, 2113u);
    vader_emit_c$declare(l0, 3701u, l6, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$pc_emit_push(void* l0, void* l1, vader_box_t l2, vader_box_t l3) {
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    void* l10 = NULL;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[5] = { &l2, &l3, &l5, &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_emit_c$PushCache_t*) l1)->f_opener_pc;
    l5 = vader_emit_c$pc_local(l4, 2819u);
    l6 = vader_emit_c$pc_local(l4, 2217u);
    t0 = vader_emit_c_ast$binary((uint8_t) 7, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l7 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(1178u, l7);
    vader_emit_c$open_if(l0, l5);
    t1 = vader_emit_c$pc_fill_of(((vader_struct_vader_emit_c$PushCache_t*) l1)->f_kind);
    l8 = ((vader_struct_vader_emit_c$SlotFill_t*) t1)->f_cty;
    l9 = concat_2(l8, 432u);
    l5 = vader_emit_c$pc_local(l4, 3193u);
    t0 = vader_emit_c_ast$cast(l9, l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a1_obj, 1600u);
    _a1_obj->f_inner = t0;
    l7 = (void*) _a1_obj;
    l5 = vader_emit_c$pc_local(l4, 2819u);
    vader_struct_vader_emit_c_ast$CIndex_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a2_obj, 1591u);
    _a2_obj->f_base = vader_ref_box(l7);
    _a2_obj->f_index = l5;
    l7 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a3_obj, 1600u);
    _a3_obj->f_inner = l3;
    l10 = (void*) _a3_obj;
    l5 = vader_emit_c_ast$cast(l8, vader_ref_box(l10));
    vader_emit_c$assign(l0, vader_ref_box(l7), l5);
    l5 = vader_emit_c$pc_local(l4, 2819u);
    l6 = vader_emit_c_ast$verbatim(558u);
    vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
    vader_obj_header_init(_a4_obj, 1566u);
    _a4_obj->f_target = l5;
    _a4_obj->f_value = l6;
    _a4_obj->f_operator = vader_box_i32(628u, INT32_C(3));
    l7 = (void*) _a4_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l7));
    vader_emit_c$open_else(l0);
    vader_emit_c$pc_emit_writeback(l0, l4);
    l8 = vader_emit_c$pc_helper_of(((vader_struct_vader_emit_c$PushCache_t*) l1)->f_kind);
    t0 = vader_emit_c$array_pointer(l2);
    vader_array_t* _a5_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l3.payload.obj;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0.payload.obj;
    l7 = (void*) _a5_arr;
    l5 = vader_emit_c_ast$call(l8, l7);
    vader_emit_c$evaluate(l0, l5);
    l5 = vader_emit_c$pc_local(l4, 2628u);
    l6 = vader_emit_c$array_pointer(l2);
    vader_emit_c$assign(l0, l5, l6);
    vader_emit_c$pc_reload(l0, l4);
    vader_emit_c$close_node(l0, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$pc_emit_writeback(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pc_local(l1, 2628u);
    l3 = vader_emit_c$pc_local(l1, 2819u);
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3545u, l4);
    vader_emit_c$evaluate(l0, l2);
    l2 = vader_emit_c$pc_header(l1, 2112u);
    l3 = vader_emit_c$pc_local(l1, 2819u);
    l2 = vader_emit_c_ast$binary((uint8_t) 7, l2, l3);
    vader_emit_c$open_if(l0, l2);
    l2 = vader_emit_c$pc_header(l1, 2112u);
    l3 = vader_emit_c$pc_local(l1, 2819u);
    vader_emit_c$assign(l0, l2, l3);
    vader_emit_c$close_node(l0, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_c$pc_fill_of(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$typed_array_fill_for(l0);
    if (l1.tag == 0u) {
        vader_struct_vader_emit_c$SlotFill_t* _a0_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a0_obj, 1557u);
        _a0_obj->f_cty = 2730u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$pc_header(int32_t l0, vader_string_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pc_local(l0, 2628u);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 1596u);
    _a0_obj->f_base = t0;
    _a0_obj->f_member = l1;
    _a0_obj->f_arrow = true;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$pc_helper_of(uint8_t l0) {
    vader_box_t l1;
    vader_string_t t0;
    l1 = vader_emit_c$push_helper_for(l0);
    if (l1.tag == 0u) {
        return 3529u;
    }
    t0 = l1.payload.s;
    return t0;
}

static bool vader_emit_c$pc_liftable_kind(uint8_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$push_helper_for(l0);
    if (!(t0.tag == 0u)) {
        t0 = vader_emit_c$typed_array_fill_for(l0);
        { bool __vret = !(t0.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_emit_c$pc_local(int32_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    int64_t l3, l5;
    void* l4 = NULL;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = vader_host_std_core$Intrinsic$byte_len(l2);
    l4 = (void*) vader_buffer_new((size_t) (INT64_C(24) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l4, l3, 1301u);
    l5 = ((int64_t) (int32_t) l0);
    l3 = std_core$write_int(l4, l3, l5);
    l3 = std_core$write_string_at(l4, l3, 1245u);
    l3 = std_core$write_string_at(l4, l3, l2);
    t0 = std_core$finish_buffer(l4, l3);
    t1 = vader_emit_c_ast$verbatim(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$pc_operand_is_slot(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1560u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
    return t1 == l1;
}

static void vader_emit_c$pc_plan_for_loop(void* l0, int32_t l1, int32_t* __o0, int32_t* __o1, int32_t* __o2, uint8_t* __o3) {
    void* l2 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    vader_box_t l3 = vader_box_null(), l11 = vader_box_null(), l17 = vader_box_null();
    int32_t l4, l6, l7, l8, l10, l14, l15, l16, l20;
    uint8_t l5, l13;
    int64_t l21, l22;
    void* t0 = NULL;
    int32_t t1;
    bool t2, t3;
    vader_box_t* gc_roots[3] = { &l3, &l11, &l17 };
    void** gc_raw_roots[7] = { &l0, &l2, &l9, &l12, &l18, &l19, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$scope_ending_for_opener(((vader_struct_vader_emit_c$FnState_t*) l0)->f_scopes, l1);
    if (l3.tag == 0u) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    l4 = INT32_C(-1);
    l5 = (uint8_t) 7;
    l6 = INT32_C(0);
    l7 = vader_chk_add(i32, l1, INT32_C(1));
    for (;;) {
        l8 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l2)->f_end_pc;
        if ((l7 < l8)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
            if (l3.tag == 1393u) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 1265u) {
                t0 = l3.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
                if ((t1 < INT32_C(0))) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
                t0 = l3.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
                l11 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
                l12 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
                l13 = vader_core_bytecode$array_kind_of(l11, l12);
                t2 = vader_emit_c$pc_liftable_kind(l13);
                if (!(t2)) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                if ((l4 >= INT32_C(0))) {
                    t0 = l3.payload.obj;
                    l14 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
                    if (l4 != l14) {
                        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                    }
                }
                t0 = l3.payload.obj;
                l4 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
                l5 = l13;
                l6 = vader_chk_add(i32, l6, INT32_C(1));
                l7 = vader_chk_add(i32, l7, INT32_C(1));
                continue;
            }
            if ((l3.tag == 1402u || l3.tag == 1403u)) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            {
                if ((l3.tag == 1301u || l3.tag == 1302u)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_jump_table);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                    l15 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l7];
                    if (!((l15 < l1))) {
                        l16 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l2)->f_end_pc;
                        if (!((l15 > l16))) {
                            goto end_138;
                        }
                    }
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
            } end_138: ;
            l17 = l3;
            l18 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_import_may_collect;
            t2 = vader_emit_c$op_may_collect(l17, l18);
            if (t2) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 1308u) {
                l19 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_may_alloc;
                t0 = l3.payload.obj;
                l20 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l19);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l20)
                t2 = ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l20];
                t3 = t2;
                if (t3) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
            }
            l7 = vader_chk_add(i32, l7, INT32_C(1));
            continue;
        }
        break;
    }
    if ((l4 < INT32_C(0))) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches;
    l21 = vader_array_length(((vader_array_t*) l9));
    l22 = INT64_C(0);
    while ((l22 < l21)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l22);
        t1 = ((vader_struct_vader_emit_c$PushCache_t*) t0)->f_slot;
        if (t1 == l4) {
            { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
        }
        l22 = (l22 + INT64_C(1));
    }
    l7 = ((vader_struct_vader_emit_c$ScopeInfo_t*) l2)->f_end_pc;
    t2 = vader_emit_c$pc_slot_used_outside_push(l0, l1, l7, l4, l6);
    if (!(t2)) {
        { *__o3 = l5; *__o2 = l4; *__o1 = l1; *__o0 = INT32_C(1); vader_gc_top = gc_frame.prev; return; }
    }
    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$pc_reload(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pc_local(l1, 2819u);
    t0 = vader_emit_c$pc_local(l1, 2628u);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l3 = (void*) _a0_arr;
    l4 = vader_emit_c_ast$call(3520u, l3);
    vader_emit_c$assign(l0, l2, l4);
    l2 = vader_emit_c$pc_local(l1, 2217u);
    l4 = vader_emit_c$pc_capacity(l1);
    vader_emit_c$assign(l0, l2, l4);
    l2 = vader_emit_c$pc_local(l1, 3193u);
    l4 = vader_emit_c$pc_header(l1, 2113u);
    vader_emit_c$assign(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_c$pc_slot_used_outside_push(void* l0, int32_t l1, int32_t l2, int32_t l3, int32_t l4) {
    int32_t l5, l6;
    vader_box_t l7;
    void* t0;
    int32_t t1;
    l5 = INT32_C(0);
    l6 = l1;
    while ((l6 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
        if (l7.tag == 1391u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            if (t1 == l3) {
                return true;
            }
        }
        if (l7.tag == 1392u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            if (t1 == l3) {
                return true;
            }
        }
        if (l7.tag == 1390u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            if (t1 == l3) {
                l5 = vader_chk_add(i32, l5, INT32_C(1));
            }
        }
        if (l7.tag == 1389u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
            if (t1 == l3) {
                l5 = vader_chk_add(i32, l5, INT32_C(1));
            }
        }
        l6 = (l6 + INT32_C(1));
    }
    return l5 != l4;
}

static vader_box_t vader_emit_c$pointee_signedness(vader_string_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    bool l3;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l4, &l5, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_3(1252u, l0, 435u);
    t1 = concat_2(t0, 3489u);
    l2 = vader_emit_c_ast$verbatim(t1);
    t2 = vader_core_bytecode$is_unsigned_val(l1);
    if (t2) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(11);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(10);
    }
    if (l3) {
        l4 = vader_emit_c_ast$number(INT64_C(1));
        t3 = vader_emit_c_ast$binary((uint8_t) 12, l2, l4);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_core_bytecode$is_integer_val(l1);
    if (!(t2)) {
        l5 = vader_emit_c_ast$number(INT64_C(2));
        t3 = vader_emit_c_ast$binary((uint8_t) 11, l2, l5);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_emit_c_ast$number(INT64_C(0));
    t3 = vader_emit_c_ast$binary((uint8_t) 12, l2, l4);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$pointer_to(vader_string_t l0, bool l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1) {
        t0 = concat_2(l0, 432u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_3(2284u, l0, 432u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$pop(void* l0) {
    int64_t l1, l3;
    void* l2 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
        l3 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(0), (int64_t) l1);
        l2 = (void*) _a1_arr;
        ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l0);
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_emit_c_ast$verbatim(553u);
    vader_struct_vader_emit_c$StackLit_t* _a2_obj = (vader_struct_vader_emit_c$StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackLit_t));
    vader_obj_header_init(_a2_obj, 1559u);
    _a2_obj->f_expression = t0;
    _a2_obj->f_val = (uint8_t) 2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$pop_args_boxed(void* l0, int32_t l1) {
    void* l2 = NULL;
    int64_t l3;
    int32_t l4, l6;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    vader_box_t* gc_roots[3] = { &l5, &l7, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c_ast$verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = ((int64_t) (int32_t) l1);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = INT32_C(0);
    while ((l4 < l1)) {
        l5 = vader_emit_c$pop(l0);
        t1 = vader_chk_sub(i32, l1, INT32_C(1));
        l6 = vader_chk_sub(i32, t1, l4);
        l7 = vader_emit_c$coerced_as(l0, l5, (uint8_t) 17);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        vader_array_ref_store(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6, l7.payload.obj);
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        l4 = (l4 + INT32_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$pop_erased_args(void* l0, void* l1, void* l2) {
    int64_t l3, l5, l6;
    void* l4 = NULL;
    int32_t l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    uint8_t t3;
    vader_box_t* gc_roots[4] = { &l8, &l9, &l10, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) l1));
    t0 = vader_emit_c_ast$verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        t2 = vader_chk_sub(i64, l3, INT64_C(1));
        l6 = vader_chk_sub(i64, t2, l5);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t0 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
        t3 = vader_emit_c$val_type_of_bc_type(t0);
        if (t3 == INT32_C(14)) {
            l8 = vader_emit_c$void_box(((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            vader_array_ref_store(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6, l8.payload.obj);
            VADER_WRITE_BARRIER(_a4_slotarr->buf);
        } else {
            l9 = vader_emit_c$pop(l0);
            l10 = vader_emit_c$coerced_as(l0, l9, (uint8_t) 17);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            vader_array_ref_store(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6, l10.payload.obj);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$precompute_branch_targets(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    bool l9;
    int32_t l10, l12, l13, l14, l15;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l8, &l11 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 626u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l4));
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        if (l8.tag == 1301u) {
            l9 = true;
        } else {
            l9 = l8.tag == 1302u;
        }
        if (l9) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l6];
            l11 = vader_emit_c$branch_target(l1, l10);
            if (l11.tag == 1556u) {
                t0 = l11.payload.obj;
                t1 = vader_emit_c$is_continue_branch(t0, l10);
                if (t1) {
                    t0 = l11.payload.obj;
                    l12 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_opener_pc;
                    t1 = std_core$$array$Contains$contains__i32(l2, l12);
                    if (!(t1)) {
                        t0 = l11.payload.obj;
                        l13 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_opener_pc;
                        vader_array_push_i32((vader_array_t*) l2, l13);
                    }
                } else {
                    t0 = l11.payload.obj;
                    l14 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_opener_pc;
                    t1 = std_core$$array$Contains$contains__i32(l3, l14);
                    if (!(t1)) {
                        t0 = l11.payload.obj;
                        l15 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_opener_pc;
                        vader_array_push_i32((vader_array_t*) l3, l15);
                    }
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_emit_c$BranchTargets_t* _a4_obj = (vader_struct_vader_emit_c$BranchTargets_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$BranchTargets_t));
    vader_obj_header_init(_a4_obj, 1546u);
    _a4_obj->f_continue_targets = l2;
    _a4_obj->f_break_targets = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$precompute_scopes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l17 = NULL;
    int64_t l5, l6, l11, l12, l14, l18, l19;
    vader_box_t l7 = vader_box_null();
    int32_t l8, l9, l10, l13, l16;
    uint8_t l15;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l17 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(264u, 0u, 13u, 1556u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(31u, 0u, 1u, 628u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l4));
    while ((l5 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        if (l7.tag == 1294u) {
            l8 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l8);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
        } else if (l7.tag == 1393u) {
            l9 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l9);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(1));
        } else if (l7.tag == 1380u) {
            l10 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(2));
        } else if (l7.tag == 1321u) {
            l11 = vader_array_length(((vader_array_t*) l2));
            if ((l11 > INT64_C(0))) {
                l12 = vader_chk_sub(i64, l11, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l13 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l12];
                l14 = vader_chk_sub(i64, l11, INT64_C(1));
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                t0 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l14, 628u);
                l15 = ((uint8_t) t0.payload.i);
                l16 = ((int32_t) (int64_t) l5);
                vader_struct_vader_emit_c$ScopeInfo_t* _a6_obj = (vader_struct_vader_emit_c$ScopeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ScopeInfo_t));
                vader_obj_header_init(_a6_obj, 1556u);
                _a6_obj->f_opener_pc = l13;
                _a6_obj->f_kind = l15;
                _a6_obj->f_end_pc = l16;
                l17 = (void*) _a6_obj;
                vader_array_push_ref((vader_array_t*) l1, l17);
                l18 = vader_chk_sub(i64, l11, INT64_C(1));
                vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(0), (int64_t) l18);
                l2 = (void*) _a7_arr;
                l19 = vader_chk_sub(i64, l11, INT64_C(1));
                vader_array_t* _a8_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l19);
                l3 = (void*) _a8_arr;
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$present_tag(void* l0, uint8_t l1) {
    int32_t l2;
    l2 = vader_emit_c$class_index(l0, l1);
    if ((l2 < INT32_C(0))) {
        return INT32_C(0);
    }
    return l2;
}

static void* vader_emit_c$publish(uint8_t l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    bool l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(16)) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
        l1 = (void*) _a0_arr;
        t0 = vader_emit_c_ast$perform(3634u, l1);
        vader_array_t* _a1_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        l1 = (void*) _a1_arr;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(13);
    }
    if (l2) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0.payload.obj;
        l3 = (void*) _a2_arr;
        t0 = vader_emit_c_ast$perform(3633u, l3);
        vader_array_t* _a3_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0.payload.obj;
        l1 = (void*) _a3_arr;
    } else {
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
            vader_array_t* _a4_arr = vader_array_new(487u, 0u, 13u, 2782u);
            l1 = (void*) _a4_arr;
        } else {
            if (l0 == INT32_C(8)) {
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
            if (!(l2)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a5_arr = vader_array_new(487u, 0u, 13u, 2782u);
            l1 = (void*) _a5_arr;
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$push_binop(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$binary_expression(l0, l1, l2);
    vader_emit_c$push_expr(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_binop_any(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l3, &l4, &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$val_of(l4);
    if (t0 == INT32_C(17)) {
        t0 = vader_emit_c$val_of(l3);
        if (t0 == INT32_C(17)) {
            l5 = vader_emit_c$expression_of(l4);
            l6 = vader_emit_c$expression_of(l3);
            vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l6.payload.obj;
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
            l7 = (void*) _a0_arr;
            l5 = vader_emit_c_ast$call(3556u, l7);
            if (l1 == INT32_C(11)) {
                l6 = l5;
                vader_emit_c$push_expr(l0, l2, l6);
                { vader_gc_top = gc_frame.prev; return; }
            }
            vader_struct_vader_emit_c_ast$CUnary_t* _a1_obj = (vader_struct_vader_emit_c_ast$CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CUnary_t));
            vader_obj_header_init(_a1_obj, 1615u);
            _a1_obj->f_operator = 315u;
            _a1_obj->f_operand = l5;
            t1 = (void*) _a1_obj;
            l6 = vader_ref_box(t1);
            vader_emit_c$push_expr(l0, l2, l6);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = vader_emit_c$object_pointer_of(l4);
    l3 = vader_emit_c$object_pointer_of(l3);
    l3 = vader_emit_c_ast$binary(l1, l4, l3);
    vader_emit_c$push_expr(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_c_type_assert(vader_string_t l0, uint8_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l7 = 0;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[2] = { &l2, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c$c_type_for_val_bare(l1);
    l5 = vader_emit_c_ast$verbatim(556u);
    l5 = vader_emit_c_ast$cast(l0, l5);
    l6 = vader_emit_c_ast$number(INT64_C(0));
    l5 = vader_emit_c_ast$binary((uint8_t) 11, l5, l6);
    l7 = concat_4(644u, l0, 411u, l4);
    vader_emit_c$push_width_assert(l0, l4, l5, l7, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_cmp(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$binary_expression(l0, l1, l2);
    vader_emit_c$push_expr(l0, (uint8_t) 10, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_const(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$const_val(l1);
    l3 = vader_emit_c$const_lit_c(((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx, l1);
    vader_emit_c$push_lit(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_eager(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    void* l8 = NULL;
    vader_box_t* gc_roots[4] = { &l3, &l4, &l5, &l6 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$operand_as(l0, l4, l2);
    l3 = vader_emit_c$operand_as(l0, l3, l2);
    l5 = vader_emit_c$div_mod_helper(l1, l2);
    if (l5.tag == 0u) {
        l6 = vader_emit_c_ast$binary(l1, l4, l3);
        vader_emit_c$push_into_temporary(l0, l6, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l5.payload.s;
    vader_array_t* _a0_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l4.payload.obj;
    l8 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(l7, l8);
    vader_emit_c$push_into_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_expr(void* l0, uint8_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
    vader_struct_vader_emit_c$StackExpr_t* _a0_obj = (vader_struct_vader_emit_c$StackExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackExpr_t));
    vader_obj_header_init(_a0_obj, 1558u);
    _a0_obj->f_expression = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_foreign_units(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$foreign_units(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module);
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l5];
        l6 = t0.payload.s;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l6));
        l7 = vader_emit_c$emit_foreign_unit(l0, l6);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l7));
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$push_helper_for(uint8_t l0) {
    vader_box_t l1;
    bool l2;
    if (l0 == INT32_C(7)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(3);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(11);
    }
    if (l2) {
        l1 = vader_box_string(623u, 3529u);
        return l1;
    }
    if (l0 == INT32_C(8)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l1 = vader_box_string(623u, 3530u);
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_string(623u, 3527u);
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_string(623u, 3526u);
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_string(623u, 3535u);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_string(623u, 3531u);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_string(623u, 3534u);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_string(623u, 3528u);
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_string(623u, 3525u);
    } else {
        if (l0 == INT32_C(13)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(0);
        }
        if (!(l2)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

static void vader_emit_c$push_i64_neg(void* l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pop(l0);
    l1 = vader_emit_c$operand_as(l0, l1, (uint8_t) 3);
    if (l1.tag == 1593u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_class == INT32_C(3);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.obj;
        l2 = vader_emit_c_ast$is_most_negative(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        l3 = l1.payload.obj;
        vader_emit_c$push_lit(l0, (uint8_t) 3, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_struct_vader_emit_c_ast$CUnary_t* _a0_obj = (vader_struct_vader_emit_c_ast$CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CUnary_t));
    vader_obj_header_init(_a0_obj, 1615u);
    _a0_obj->f_operator = 479u;
    _a0_obj->f_operand = l1;
    l3 = (void*) _a0_obj;
    vader_emit_c$push_expr(l0, (uint8_t) 3, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_into_temporary(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2 == INT32_C(14))) {
        l3 = vader_emit_c$new_temporary(l0, l2);
        vader_emit_c$assign(l0, vader_ref_box(l3), l1);
        vader_emit_c$push_temporary(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
    l4 = vader_emit_c$evaluated_void(l0, l1);
    vader_array_push_ref((vader_array_t*) l3, l4.payload.obj);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7) {
    void* l8 = NULL;
    void* l11 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l32 = NULL;
    int64_t l9, l10, l14, l15;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l28 = 0;
    vader_string_t l36 = 0;
    vader_box_t l16 = vader_box_null(), l22 = vader_box_null(), l26 = vader_box_null(), l27 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null(), l31 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null(), l35 = vader_box_null(), l37 = vader_box_null(), l38 = vader_box_null(), l39 = vader_box_null();
    int32_t l20;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[14] = {
        &l16, &l22, &l26, &l27, &l29, &l30, &l31, &l33, &l34, &l35, &l37, &l38, &l39, &t0,
    };
    void** gc_raw_roots[10] = { &l0, &l1, &l6, &l8, &l11, &l17, &l21, &l25, &l32, &t1 };
    vader_string_t* gc_atom_roots[12] = {
        &l2, &l3, &l4, &l12, &l13, &l18, &l19, &l23, &l24, &l28, &l36, &t2,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 14u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 12u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_core_bytecode$c_struct_layout(l1, l0);
    l9 = INT64_C(0);
    l10 = vader_array_length(((vader_array_t*) l1));
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l11 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l9);
        l12 = vader_emit_c$c_field_name(l11);
        l13 = concat_2(l3, l12);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l8)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l14 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l9];
        l15 = vader_chk_add(i64, l5, l14);
        l16 = vader_core_bytecode$nested_mirror(l11, l0);
        if (l16.tag == 0u) {
            t0 = vader_emit_c$null_member(l2, l13);
            vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
            ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0.payload.obj;
            l21 = (void*) _a2_arr;
            l22 = vader_emit_c_ast$call(3186u, l21);
            l23 = ((vader_struct_vader_core_bytecode$BcField_t*) l11)->f_name;
            l24 = concat_2(2500u, l23);
            t0 = vader_emit_c$null_member(l4, l24);
            vader_array_t* _a3_arr = vader_array_new(486u, 1u, 13u, 2777u);
            ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0.payload.obj;
            l25 = (void*) _a3_arr;
            l26 = vader_emit_c_ast$call(3186u, l25);
            l27 = vader_emit_c_ast$binary((uint8_t) 11, l22, l26);
            l28 = concat_3(l2, 492u, l13);
            l29 = vader_emit_c$static_assert(l27, l28);
            vader_array_push_ref((vader_array_t*) l6, l29.payload.obj);
            l30 = vader_emit_c_ast$verbatim(l2);
            l31 = vader_emit_c_ast$verbatim(l13);
            vader_array_t* _a4_arr = vader_array_new(486u, 2u, 13u, 2777u);
            ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l31.payload.obj;
            ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l30.payload.obj;
            l32 = (void*) _a4_arr;
            l33 = vader_emit_c_ast$call(1264u, l32);
            l34 = vader_emit_c_ast$number(l15);
            l35 = vader_emit_c_ast$binary((uint8_t) 11, l33, l34);
            l36 = concat_4(l2, 492u, l13, 239u);
            l37 = vader_emit_c$static_assert(l35, l36);
            vader_array_push_ref((vader_array_t*) l6, l37.payload.obj);
            l38 = vader_emit_c$signedness_assert(l0, l11, l2, l13);
            if (!(l38.tag == 0u)) {
                l39 = l38;
                vader_array_push_ref((vader_array_t*) l6, l39.payload.obj);
            }
            l9 = (l9 + INT64_C(1));
            continue;
        }
        t1 = l16.payload.obj;
        l17 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
        l18 = concat_2(l13, 492u);
        t1 = l16.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_name;
        l19 = vader_emit_c$struct_c_name(t2);
        l20 = vader_chk_add(i32, l7, INT32_C(1));
        vader_emit_c$push_leaf_asserts(l0, l17, l2, l18, l19, l15, l6, l20);
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_lit(void* l0, uint8_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
    vader_struct_vader_emit_c$StackLit_t* _a0_obj = (vader_struct_vader_emit_c$StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackLit_t));
    vader_obj_header_init(_a0_obj, 1559u);
    _a0_obj->f_expression = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_local_ref(void* l0, int32_t l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
    vader_struct_vader_emit_c$StackLocalRef_t* _a0_obj = (vader_struct_vader_emit_c$StackLocalRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackLocalRef_t));
    vader_obj_header_init(_a0_obj, 1560u);
    _a0_obj->f_slot = l1;
    _a0_obj->f_val = l2;
    l4 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_member_copies(void* l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4, void* l5, int32_t l6) {
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    int64_t l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_box_t l16 = vader_box_null();
    int32_t l19;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l16, &t3 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l5, &l7, &l10, &l12, &l15, &l17, &l18, &l20, &l21, &l22, &l23, &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l11, &l13, &l14, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l6 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l1;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l9);
        l11 = vader_emit_c$c_field_name(l10);
        vader_struct_vader_emit_c_ast$CMember_t* _a1_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a1_obj, 1596u);
        _a1_obj->f_base = l2;
        _a1_obj->f_member = l11;
        _a1_obj->f_arrow = false;
        l12 = (void*) _a1_obj;
        l13 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
        l14 = concat_2(2500u, l13);
        vader_struct_vader_emit_c_ast$CMember_t* _a2_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a2_obj, 1596u);
        _a2_obj->f_base = l3;
        _a2_obj->f_member = l14;
        _a2_obj->f_arrow = true;
        l15 = (void*) _a2_obj;
        l16 = vader_core_bytecode$nested_mirror(l10, l0);
        if (l16.tag == 0u) {
            if (l4) {
                l20 = l12;
            } else {
                l20 = l15;
            }
            if (l4) {
                l21 = l15;
            } else {
                l21 = l12;
            }
            vader_struct_vader_emit_c_ast$CCastToTypeOf_t* _a3_obj = (vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCastToTypeOf_t));
            vader_obj_header_init(_a3_obj, 1573u);
            _a3_obj->f_model = vader_ref_box(l20);
            _a3_obj->f_value = vader_ref_box(l21);
            l22 = (void*) _a3_obj;
            vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
            vader_obj_header_init(_a4_obj, 1566u);
            _a4_obj->f_target = vader_ref_box(l20);
            _a4_obj->f_value = vader_ref_box(l22);
            _a4_obj->f_operator = vader_box_obj(0u, NULL);
            l23 = (void*) _a4_obj;
            vader_array_push_ref((vader_array_t*) l5, l23);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        t0 = l16.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
        t2 = vader_emit_c$struct_c_name(t1);
        t1 = concat_2(t2, 432u);
        t3 = vader_emit_c_ast$cast(t1, vader_ref_box(l15));
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a5_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a5_obj, 1600u);
        _a5_obj->f_inner = t3;
        l17 = (void*) _a5_obj;
        t0 = l16.payload.obj;
        l18 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
        l19 = vader_chk_add(i32, l6, INT32_C(1));
        vader_emit_c$push_member_copies(l0, l18, vader_ref_box(l12), vader_ref_box(l17), l4, l5, l19);
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c$push_mirror_allocation(void* l0, int32_t l1, void* l2, void* l3, void* l4, int32_t l5) {
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l17 = 0;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    int64_t l8, l9;
    vader_box_t l12 = vader_box_null(), l19 = vader_box_null();
    int32_t l15, l16;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    vader_box_t* gc_roots[3] = { &l12, &l19, &t2 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l4, &l7, &l13, &l14, &l18, &l20, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l10, &l11, &l17, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = (void*) vader_buffer_new((size_t) INT64_C(23));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l7, l8, 3007u);
    l9 = vader_array_length(((vader_array_t*) l2));
    l8 = std_core$write_int(l7, l8, l9);
    l6 = std_core$finish_buffer(l7, l8);
    vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l6));
    t0 = vader_emit_c$bc_struct_name(l0, l1);
    l10 = vader_emit_c$struct_c_name(t0);
    l11 = concat_2(l10, 432u);
    t1 = (void*) &vader_data_70;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l12 = vader_emit_c_ast$declaration(l11, l6, vader_ref_box(l7));
    vader_array_push_ref((vader_array_t*) l3, l12.payload.obj);
    vader_array_t* _a1_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l7 = (void*) _a1_arr;
    l13 = vader_emit_c$bc_struct_fields(l0, l1);
    l8 = vader_array_length(((vader_array_t*) l13));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l14 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
        t2 = vader_core_bytecode$nested_mirror(l14, l0);
        if (!(t2.tag == 0u)) {
            t3 = vader_chk_add(i32, l5, INT32_C(1));
            if (!((t3 >= INT32_C(16)))) {
                l15 = ((vader_struct_vader_core_bytecode$BcField_t*) l14)->f_type_index;
                l16 = vader_chk_add(i32, l5, INT32_C(1));
                l11 = vader_emit_c$push_mirror_allocation(l0, l15, l2, l3, l4, l16);
                l12 = vader_emit_c_ast$verbatim(l6);
                t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l14)->f_name;
                l17 = vader_emit_c$field_c_name(t0);
                vader_struct_vader_emit_c_ast$CMember_t* _a3_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                vader_obj_header_init(_a3_obj, 1596u);
                _a3_obj->f_base = l12;
                _a3_obj->f_member = l17;
                _a3_obj->f_arrow = true;
                l18 = (void*) _a3_obj;
                l19 = vader_emit_c_ast$verbatim(l11);
                vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
                vader_obj_header_init(_a4_obj, 1566u);
                _a4_obj->f_target = vader_ref_box(l18);
                _a4_obj->f_value = l19;
                _a4_obj->f_operator = vader_box_obj(0u, NULL);
                l20 = (void*) _a4_obj;
                vader_array_push_ref((vader_array_t*) l7, l20);
                l9 = (l9 + INT64_C(1));
                continue;
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    l12 = vader_emit_c_ast$verbatim(l6);
    l19 = vader_emit_c$gc_allocation(l10);
    vader_struct_vader_emit_c_ast$CAssign_t* _a5_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
    vader_obj_header_init(_a5_obj, 1566u);
    _a5_obj->f_target = l12;
    _a5_obj->f_value = l19;
    _a5_obj->f_operator = vader_box_obj(0u, NULL);
    l13 = (void*) _a5_obj;
    vader_array_push_ref((vader_array_t*) l4, l13);
    l12 = vader_emit_c_ast$verbatim(l6);
    l13 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l1);
    l8 = std_core$write_int(l13, l8, l9);
    l8 = std_core$write_string_at(l13, l8, 3423u);
    t0 = std_core$finish_buffer(l13, l8);
    l19 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a6_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l19.payload.obj;
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l12.payload.obj;
    l13 = (void*) _a6_arr;
    l12 = vader_emit_c_ast$perform(3611u, l13);
    vader_array_push_ref((vader_array_t*) l4, l12.payload.obj);
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l7);
    { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$push_object(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$cast(3701u, l1);
    vader_emit_c$push_into_temporary(l0, l2, (uint8_t) 16);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_offset_list(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l2));
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l2;
    t0 = vader_array_length(((vader_array_t*) l3));
    vader_array_t* _a0_arr = vader_array_reserve(486u, (int64_t) t0, 13u, 2777u);
    l4 = (void*) _a0_arr;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        t2 = t1.payload.s;
        l7 = __lambda_vader_emit_c_13(t2);
        vader_array_push_ref((vader_array_t*) l4, l7.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    l3 = l4;
    l8 = concat_3(492u, l1, 1300u);
    vader_struct_vader_emit_c_ast$CCompoundLiteral_t* _a2_obj = (vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCompoundLiteral_t));
    vader_obj_header_init(_a2_obj, 1574u);
    _a2_obj->f_type = 2286u;
    _a2_obj->f_elements = l3;
    l3 = (void*) _a2_obj;
    l7 = vader_emit_c_ast$designated(l8, vader_ref_box(l3));
    vader_array_push_ref((vader_array_t*) l0, l7.payload.obj);
    l8 = concat_3(492u, l1, 1292u);
    t0 = vader_array_length(((vader_array_t*) l2));
    l7 = vader_emit_c_ast$number(t0);
    l7 = vader_emit_c_ast$designated(l8, l7);
    vader_array_push_ref((vader_array_t*) l0, l7.payload.obj);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_pointee_assert(vader_string_t l0, uint8_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[2] = { &l2, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c$c_type_for_val_bare(l1);
    l5 = concat_5(644u, l0, 414u, l4, 1224u);
    l6 = vader_emit_c$pointee_signedness(l0, l1);
    vader_emit_c$push_width_assert(l0, l4, l6, l5, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_pool_array(void* l0, void* l1, vader_string_t l2, uint8_t l3, void* l4) {
    int64_t l5, l9;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    uint8_t l7;
    void* l10 = NULL;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    vader_string_t t0 = 0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l11, &l12, &l13, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l10, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_array_length(((vader_array_t*) l4));
    t0 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_name;
    l6 = concat_2(t0, 1290u);
    l7 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_storage;
    l8 = l2;
    l9 = vader_host_std_core$Intrinsic$byte_len(l8);
    l10 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l10, l9, 1169u);
    l9 = std_core$write_string_at(l10, l9, l8);
    l9 = std_core$write_string_at(l10, l9, 444u);
    l9 = std_core$write_int(l10, l9, l5);
    l9 = std_core$write_string_at(l10, l9, 398u);
    l8 = std_core$finish_buffer(l10, l9);
    t1 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_element_tag;
    l11 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t1));
    t1 = vader_core_bytecode$array_kind_index(l3);
    l12 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t1));
    l13 = vader_emit_c_ast$unsigned(l5);
    vader_array_t* _a0_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l13.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l12.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l11.payload.obj;
    l10 = (void*) _a0_arr;
    l11 = vader_emit_c_ast$call(1182u, l10);
    l12 = vader_emit_c_ast$initializer_list(l4);
    l12 = vader_emit_c_ast$designated(528u, l12);
    vader_array_t* _a1_arr = vader_array_new(486u, 2u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l11.payload.obj;
    t2 = (void*) _a1_arr;
    l11 = vader_emit_c_ast$initializer_list(t2);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a2_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a2_obj, 1578u);
    _a2_obj->f_name = l6;
    _a2_obj->f_length = vader_box_obj(0u, NULL);
    _a2_obj->f_value = l11;
    l10 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a3_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a3_obj, 1587u);
    _a3_obj->f_storage = l7;
    _a3_obj->f_constant = true;
    _a3_obj->f_type = l8;
    _a3_obj->f_declarator = l10;
    l10 = (void*) _a3_obj;
    vader_array_push_ref((vader_array_t*) l0, l10);
    l7 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_storage;
    l8 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_name;
    t1 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_type_id;
    l11 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t1));
    l12 = vader_emit_c_ast$unsigned(l5);
    t3 = vader_emit_c_ast$verbatim(l6);
    l13 = vader_emit_c_ast$address_of(t3);
    vader_array_t* _a4_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l13.payload.obj;
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l12.payload.obj;
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l11.payload.obj;
    l10 = (void*) _a4_arr;
    l11 = vader_emit_c_ast$call(1181u, l10);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a5_obj, 1578u);
    _a5_obj->f_name = l8;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l11;
    l10 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a6_obj, 1587u);
    _a6_obj->f_storage = l7;
    _a6_obj->f_constant = true;
    _a6_obj->f_type = 3547u;
    _a6_obj->f_declarator = l10;
    l10 = (void*) _a6_obj;
    vader_array_push_ref((vader_array_t*) l0, l10);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_shift(void* l0, uint8_t l1, uint8_t l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t1 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$shift_count_mask(l2);
    l4 = vader_emit_c$pop(l0);
    t0 = vader_emit_c$literal_within(l4, l3);
    if (t0) {
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack, l4.payload.obj);
        vader_emit_c$push_binop(l0, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_emit_c$operand_as(l0, l4, l2);
    l5 = vader_emit_c_ast$number(l3);
    t1 = vader_emit_c_ast$binary((uint8_t) 13, l4, l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1600u);
    _a0_obj->f_inner = t1;
    l6 = (void*) _a0_obj;
    vader_emit_c$push_expr(l0, l2, vader_ref_box(l6));
    vader_emit_c$push_binop(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_struct_field(void* l0, int32_t l1, int32_t l2, vader_box_t l3, uint8_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    vader_box_t l6 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    int32_t l9;
    uint8_t l10;
    int64_t l14, l15, l16;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    int64_t t3, t4;
    vader_box_t* gc_roots[6] = { &l3, &l6, &l12, &l13, &l17, &t1 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l6.tag == 1286u)) {
        l8 = (void*) vader_buffer_new((size_t) INT64_C(59));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l8, l14, 3250u);
        l15 = ((int64_t) (int32_t) l1);
        l14 = std_core$write_int(l8, l14, l15);
        t0 = std_core$finish_buffer(l8, l14);
        std_abort$todo(t0);
        vader_unreachable("a no-return call returned");
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
    l7 = t1.payload.s;
    t2 = l6.payload.obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
    l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
    l10 = vader_emit_c$val_type_of_field(l5, l9);
    if (l10 == INT32_C(14)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_emit_c$object_pointer(l3, l4);
    l11 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_name;
    l12 = vader_emit_c$field_of(l7, l6, l11);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_layout_siblings);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    l5 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l1);
    t3 = vader_array_length(((vader_array_t*) l5));
    if (t3 == INT64_C(0)) {
        vader_emit_c$push_expr(l0, l10, l12);
    } else {
        l13 = vader_emit_c$tag_expression(l3, l4);
        l14 = INT64_C(0);
        l15 = vader_array_length(((vader_array_t*) l5));
        while ((l14 < l15)) {
            t3 = vader_array_length(((vader_array_t*) l5));
            t4 = vader_chk_sub(i64, t3, INT64_C(1));
            l16 = vader_chk_sub(i64, t4, l14);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l16)
            l9 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l16];
            l17 = vader_emit_c$erased_sibling_field_read(l0, l9, l2, l10, l6);
            t1 = vader_emit_c$tag_equals(l13, l9);
            vader_struct_vader_emit_c_ast$CConditional_t* _a5_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
            vader_obj_header_init(_a5_obj, 1575u);
            _a5_obj->f_condition = t1;
            _a5_obj->f_then_value = l17;
            _a5_obj->f_else_value = l12;
            t2 = (void*) _a5_obj;
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a6_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a6_obj, 1600u);
            _a6_obj->f_inner = vader_ref_box(t2);
            t2 = (void*) _a6_obj;
            l12 = vader_ref_box(t2);
            l14 = (l14 + INT64_C(1));
        }
        vader_emit_c$push_expr(l0, l10, l12);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_temporary(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
    vader_struct_vader_emit_c$StackTemporary_t* _a0_obj = (vader_struct_vader_emit_c$StackTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackTemporary_t));
    vader_obj_header_init(_a0_obj, 1562u);
    _a0_obj->f_temporary = l1;
    _a0_obj->f_val = l2;
    l4 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_unop(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l3 = vader_emit_c$operand_as(l0, l3, l2);
    vader_struct_vader_emit_c_ast$CUnary_t* _a0_obj = (vader_struct_vader_emit_c_ast$CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CUnary_t));
    vader_obj_header_init(_a0_obj, 1615u);
    _a0_obj->f_operator = l1;
    _a0_obj->f_operand = l3;
    l4 = (void*) _a0_obj;
    vader_emit_c$push_expr(l0, l2, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_width_assert(vader_string_t l0, vader_string_t l1, vader_box_t l2, vader_string_t l3, void* l4, void* l5) {
    void* l6 = NULL;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l7, &l8, &t1 };
    void** gc_raw_roots[3] = { &l4, &l5, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core$$array$Contains$contains__string(l4, l3);
    if (!(t0)) {
        vader_array_push_scalar((vader_array_t*) l4, vader_box_string(623u, l3));
        t1 = vader_emit_c_ast$verbatim(l0);
        vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
        l6 = (void*) _a0_arr;
        l7 = vader_emit_c_ast$call(3186u, l6);
        t1 = vader_emit_c_ast$verbatim(l1);
        vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
        l6 = (void*) _a1_arr;
        l8 = vader_emit_c_ast$call(3186u, l6);
        l7 = vader_emit_c_ast$binary((uint8_t) 11, l7, l8);
        t1 = vader_emit_c_ast$binary((uint8_t) 16, l7, l2);
        l7 = vader_emit_c$static_assert(t1, l3);
        vader_array_push_ref((vader_array_t*) l5, l7.payload.obj);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$read_back(void* l0, vader_box_t l1) {
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$c_result_type(l0);
    if (!(t0.tag == 0u)) {
        t1 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature);
        t2 = vader_emit_c$c_type_for_val_bare(t1);
        t0 = vader_emit_c_ast$cast(t2, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$reboxes_to_own_tag(void* l0, int32_t l1, uint8_t l2) {
    int32_t t0;
    t0 = vader_emit_c$class_tag_of(l0, l2);
    return t0 == l1;
}

static vader_box_t vader_emit_c$ref_box(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$call(3615u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$ref_carrying_element(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if ((l0.tag == 1273u || l0.tag == 1276u || l0.tag == 1282u || l0.tag == 1286u)) {
        return true;
    }
    if (!(l0.tag == 1287u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_core_bytecode$is_ref_only_element(vader_ref_box(t0), l1);
    return t1;
}

static void* vader_emit_c$relay_declarations(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l6, l7, l10, l14;
    vader_string_t l8 = 0;
    vader_string_t l11 = 0;
    vader_box_t l15 = vader_box_null(), l16 = vader_box_null();
    bool l17;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[3] = { &l15, &l16, &t2 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l12, &l13, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_signature;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params));
    vader_array_t* _a0_arr = vader_array_reserve(269u, (int64_t) t0, 13u, 1583u);
    l4 = (void*) _a0_arr;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params));
    vader_array_t* _a1_arr = vader_array_reserve(486u, (int64_t) t0, 13u, 2777u);
    l5 = (void*) _a1_arr;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params));
    while ((l6 < l7)) {
        l8 = vader_emit_c$extern_parameter_type(l1, l2, l6);
        l9 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 1793u);
        l10 = std_core$write_int(l9, l10, l6);
        l11 = std_core$finish_buffer(l9, l10);
        vader_struct_vader_emit_c_ast$CField_t* _a2_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
        vader_obj_header_init(_a2_obj, 1583u);
        _a2_obj->f_type = l8;
        _a2_obj->f_name = l11;
        l12 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l4, l12);
        l13 = (void*) vader_buffer_new((size_t) INT64_C(24));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l13, l14, 2481u);
        l14 = std_core$write_int(l13, l14, l6);
        t1 = std_core$finish_buffer(l13, l14);
        l15 = vader_emit_c_ast$verbatim(t1);
        vader_array_push_ref((vader_array_t*) l5, l15.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_extern_name;
    l15 = vader_emit_c_ast$call(t1, l5);
    l8 = vader_emit_c$relay_frame_name(l1);
    l8 = concat_3(3249u, l8, 432u);
    l16 = vader_emit_c_ast$verbatim(3093u);
    l16 = vader_emit_c_ast$cast(l8, l16);
    t2 = vader_emit_c_ast$declaration(l8, 2480u, l16);
    vader_array_t* _a3_arr = vader_array_new(487u, 1u, 13u, 2782u);
    ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t2.payload.obj;
    l5 = (void*) _a3_arr;
    t3 = vader_core_bytecode$bc_single_result(l3);
    if (t3 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a4_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a4_obj, 1582u);
        _a4_obj->f_expression = l15;
        l3 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l5, l3);
    } else {
        t1 = vader_emit_c$extern_result_type(l1, l2);
        vader_struct_vader_emit_c_ast$CField_t* _a5_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
        vader_obj_header_init(_a5_obj, 1583u);
        _a5_obj->f_type = t1;
        _a5_obj->f_name = 3087u;
        l2 = (void*) _a5_obj;
        vader_array_push_ref((vader_array_t*) l4, l2);
        t2 = vader_emit_c_ast$verbatim(2482u);
        vader_struct_vader_emit_c_ast$CAssign_t* _a6_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a6_obj, 1566u);
        _a6_obj->f_target = t2;
        _a6_obj->f_value = l15;
        _a6_obj->f_operator = vader_box_obj(0u, NULL);
        l2 = (void*) _a6_obj;
        vader_array_push_ref((vader_array_t*) l5, l2);
    }
    t0 = vader_array_length(((vader_array_t*) l4));
    if (t0 == INT64_C(0)) {
        vader_struct_vader_emit_c_ast$CField_t* _a7_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
        vader_obj_header_init(_a7_obj, 1583u);
        _a7_obj->f_type = 2232u;
        _a7_obj->f_name = 3498u;
        l2 = (void*) _a7_obj;
        vader_array_push_ref((vader_array_t*) l4, l2);
    }
    t1 = vader_emit_c$relay_frame_name(l1);
    vader_struct_vader_emit_c_ast$CStructDefinition_t* _a8_obj = (vader_struct_vader_emit_c_ast$CStructDefinition_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructDefinition_t));
    vader_obj_header_init(_a8_obj, 1611u);
    _a8_obj->f_name = t1;
    _a8_obj->f_fields = l4;
    l2 = (void*) _a8_obj;
    l17 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l8 = vader_emit_c$relay_runner_name(l1);
    vader_struct_vader_emit_c_ast$CParameter_t* _a9_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a9_obj, 1599u);
    _a9_obj->f_type = 3701u;
    _a9_obj->f_name = 3093u;
    t4 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(272u, 1u, 13u, 1599u);
    ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t4;
    l3 = (void*) _a10_arr;
    vader_struct_vader_emit_c_ast$CSignature_t* _a11_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a11_obj, 1608u);
    _a11_obj->f_storage = (uint8_t) 0;
    _a11_obj->f_inline = l17;
    _a11_obj->f_result = 3699u;
    _a11_obj->f_name = l8;
    _a11_obj->f_parameters = l3;
    l3 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l4 = (void*) _a12_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a13_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a13_obj, 1568u);
    _a13_obj->f_body = l5;
    l5 = (void*) _a13_obj;
    vader_struct_vader_emit_c_ast$CFunction_t* _a14_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a14_obj, 1585u);
    _a14_obj->f_signature = l3;
    _a14_obj->f_prologue = l4;
    _a14_obj->f_body = l5;
    l3 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(488u, 2u, 13u, 2786u);
    ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 1u] = l3;
    ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = l2;
    t4 = (void*) _a15_arr;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$relay_frame_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l1 = vader_emit_c$sanitise(t0);
    t0 = concat_2(3616u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$relay_runner_name(void* l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$relay_frame_name(l0);
    t1 = concat_2(t0, 1304u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$renamed_argument(void* l0, int64_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_core_bytecode$param_c_type(l0, l1);
    if (l3.tag == 0u) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.s;
    t1 = vader_emit_c_ast$cast(t0, l2);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$return_statement(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    bool l6;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l2)->f_stores;
    l4 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l2)->f_value;
    l5 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l2)->f_snapshot_type;
    l6 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_needs_frame;
    vader_struct_vader_emit_c_ast$CReturn_t* _a0_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a0_obj, 1604u);
    _a0_obj->f_stores = l3;
    _a0_obj->f_value = l4;
    _a0_obj->f_snapshot_type = l5;
    _a0_obj->f_pops_frame = l6;
    l2 = (void*) _a0_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_c$returns_at(void* l0, int64_t l1) {
    int64_t l2;
    int64_t t0;
    vader_box_t t1;
    l2 = vader_array_length(((vader_array_t*) l0));
    if (l1 == l2) {
        return true;
    }
    t0 = vader_array_length(((vader_array_t*) l0));
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    if (l1 == l2) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        return (t1.tag == 1402u || t1.tag == 1403u);
    }
    return false;
}

static vader_box_t vader_emit_c$root_list(void* l0, vader_string_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l3));
    if (!(t0 == INT64_C(0))) {
        t1 = (void*) &vader_data_68;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        l5 = vader_emit_c_ast$initializer_list(l3);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a1_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a1_obj, 1578u);
        _a1_obj->f_name = l2;
        _a1_obj->f_length = vader_ref_box(l4);
        _a1_obj->f_value = l5;
        l4 = (void*) _a1_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a2_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a2_obj, 1587u);
        _a2_obj->f_storage = (uint8_t) 0;
        _a2_obj->f_constant = false;
        _a2_obj->f_type = l1;
        _a2_obj->f_declarator = l4;
        l4 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l0, l4);
        t2 = vader_emit_c_ast$verbatim(l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_70;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$safepoint_result_arity(void* l0, vader_box_t l1, int64_t l2) {
    int32_t l3;
    void* l4;
    int64_t l5;
    void* t0;
    int64_t t1;
    if (l1.tag == 1265u) {
        if (!(l2 != INT64_C(2))) {
            return vader_box_i64(627u, INT64_C(0));
        }
        return vader_box_obj(0u, NULL);
    }
    if (!(l1.tag == 1308u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature;
    l5 = vader_core_bytecode$bc_result_arity(l4);
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params));
    if (t1 != l2) {
        return vader_box_obj(0u, NULL);
    }
    if (!((l5 > INT64_C(1)))) {
        return vader_box_i64(627u, l5);
    }
    return vader_box_obj(0u, NULL);
}

static vader_string_t vader_emit_c$sanitise(vader_string_t l0) {
    int64_t l1, l2;
    uint8_t l3;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = INT64_C(0);
    l2 = vader_host_std_core$Intrinsic$byte_len(l0);
    while ((l1 < l2)) {
        l3 = vader_host_std_core$Intrinsic$byte_at(l0, l1);
        t0 = vader_support_text$is_ident_byte(l3);
        if (!(t0)) {
            if (l3 != INT32_C(36)) {
                t1 = concat_3(2176u, l0, 1423u);
                std_abort$todo(t1);
                vader_unreachable("a no-return call returned");
            }
        }
        l1 = (l1 + INT64_C(1));
    }
    t0 = vader_emit_c$is_c_reserved(l0);
    if (!(t0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_2(l0, 335u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$scalar_cast(vader_box_t l0, uint8_t l1, uint8_t l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l7, &t3 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1593u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_class == l1) {
            t0 = l0.payload.obj;
            t1 = vader_emit_c_ast$is_most_negative(t0);
            if (!(t1)) {
                l3 = vader_emit_c$c_type_for_val_bare(l2);
                l4 = (void*) vader_buffer_new((size_t) INT64_C(20));
                l5 = INT64_C(0);
                t0 = l0.payload.obj;
                l6 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_value;
                l5 = std_core$write_int(l4, l5, l6);
                t2 = std_core$finish_buffer(l4, l5);
                l7 = vader_emit_c_ast$verbatim(t2);
                t3 = vader_emit_c_ast$cast(l3, l7);
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l3 = vader_emit_c$c_type_for_val_bare(l2);
    t2 = vader_emit_c$c_type_for_val_bare(l1);
    l7 = vader_emit_c_ast$cast(t2, l0);
    t3 = vader_emit_c_ast$cast(l3, l7);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$scalar_tag(void* l0, uint8_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    uint8_t t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        if (l4.tag == 1283u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val != INT32_C(15)) {
                t0 = l4.payload.obj;
                t1 = vader_core_bytecode$array_kind_of_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
                if (t1 == l1) {
                    return ((int32_t) (int64_t) l2);
                }
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(0);
}

static void* vader_emit_c$scan_fn_value_usage(void* l0) {
    int64_t l1, l6, l8, l9;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    bool l4;
    vader_box_t l10 = vader_box_null();
    int32_t l11, l12, l13;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 7u, 626u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(26u, 1u, 12u, 621u);
    ((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a3_arr;
    l4 = false;
    l5 = l0;
    l1 = vader_array_length(((vader_array_t*) l5));
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6);
        l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l8 = vader_array_length(((vader_array_t*) l7));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l9);
            if (l10.tag == 1337u) {
                t0 = l10.payload.obj;
                l11 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
                t0 = l10.payload.obj;
                l12 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l11] = (int32_t) l12;
                l4 = true;
            } else if (l10.tag == 1394u) {
                t0 = l10.payload.obj;
                l13 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l13)
                ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l13] = (uint8_t) true;
                l4 = true;
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_emit_c$FnValueUsage_t* _a8_obj = (vader_struct_vader_emit_c$FnValueUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$FnValueUsage_t));
    vader_obj_header_init(_a8_obj, 1551u);
    _a8_obj->f_fn_ref_type = l2;
    _a8_obj->f_is_closure = l3;
    _a8_obj->f_any = l4;
    t0 = (void*) _a8_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$scope_ending_at(void* l0, int32_t l1) {
    int64_t l2, l3;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        t1 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_end_pc;
        if (t1 == l1) {
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
            return vader_ref_box(t0);
        }
        l2 = (l2 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_c$scope_ending_for_opener(void* l0, int32_t l1) {
    int64_t l2, l3;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        t1 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_opener_pc;
        if (t1 == l1) {
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
            return vader_ref_box(t0);
        }
        l2 = (l2 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static int64_t vader_emit_c$shift_count_mask(uint8_t l0) {
    if (l0 == INT32_C(3)) {
        return INT64_C(63);
    }
    if (!(l0 == INT32_C(7))) {
        return INT64_C(31);
    }
    return INT64_C(63);
}

static void* vader_emit_c$shim_body(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l6 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    uint8_t l4;
    void* l5 = NULL;
    int32_t l7, l8;
    bool l12;
    vader_string_t l13 = 0;
    vader_box_t t0 = vader_box_null(), t2 = vader_box_null();
    void* t1 = NULL;
    bool t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[8] = { &l2, &l3, &l6, &l9, &l10, &l11, &t0, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l13, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$argument(INT64_C(0));
    l3 = vader_emit_c$argument(INT64_C(1));
    l4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_intrinsic;
    if (l4 == INT32_C(58)) {
        vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a0_arr;
        t0 = vader_emit_c_ast$perform(3614u, l5);
        vader_array_t* _a1_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a2_arr;
        t0 = vader_emit_c_ast$returning(3651u, l5);
        vader_array_t* _a3_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a3_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(2)) {
        vader_array_t* _a4_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a4_arr;
        t0 = vader_emit_c_ast$returning(3650u, l5);
        vader_array_t* _a5_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a5_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(3)) {
        l6 = vader_emit_c$argument(INT64_C(2));
        vader_array_t* _a6_arr = vader_array_new(486u, 3u, 13u, 2777u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 2u] = l6.payload.obj;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l3.payload.obj;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a6_arr;
        t0 = vader_emit_c_ast$returning(3652u, l5);
        vader_array_t* _a7_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a7_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(4)) {
        vader_array_t* _a8_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a8_arr;
        t0 = vader_emit_c_ast$returning(3656u, l5);
        vader_array_t* _a9_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a9_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(5)) {
        l7 = vader_emit_c$class_index(l1, (uint8_t) 4);
        if ((l7 < INT32_C(0))) {
            t0 = vader_emit_c$trap(2155u);
            vader_array_t* _a10_arr = vader_array_new(487u, 1u, 13u, 2782u);
            ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t0.payload.obj;
            t1 = (void*) _a10_arr;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = vader_emit_c$array_tag(l1, l7);
        if (!((l8 < INT32_C(0)))) {
            l6 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l8));
            l9 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l7));
            vader_array_t* _a11_arr = vader_array_new(486u, 3u, 13u, 2777u);
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 2u] = l9.payload.obj;
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 1u] = l6.payload.obj;
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = l2.payload.obj;
            l5 = (void*) _a11_arr;
            l6 = vader_emit_c_ast$call(3653u, l5);
            vader_array_t* _a12_arr = vader_array_new(266u, 0u, 13u, 1566u);
            l5 = (void*) _a12_arr;
            l6 = vader_emit_c_ast$cast(3701u, l6);
            vader_struct_vader_emit_c_ast$CReturn_t* _a13_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a13_obj, 1604u);
            _a13_obj->f_stores = l5;
            _a13_obj->f_value = l6;
            _a13_obj->f_snapshot_type = 0u;
            _a13_obj->f_pops_frame = false;
            t1 = (void*) _a13_obj;
            vader_array_t* _a14_arr = vader_array_new(487u, 1u, 13u, 2782u);
            ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = t1;
            t1 = (void*) _a14_arr;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_emit_c$trap(2156u);
        vader_array_t* _a15_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a15_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(6)) {
        t0 = vader_emit_c_ast$cast(3548u, l2);
        vader_array_t* _a16_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0.payload.obj;
        l5 = (void*) _a16_arr;
        t0 = vader_emit_c_ast$returning(3649u, l5);
        vader_array_t* _a17_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a17_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(7)) {
        vader_array_t* _a18_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a18_arr;
        t0 = vader_emit_c_ast$returning(3655u, l5);
        vader_array_t* _a19_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a19_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(13)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a20_slotarr, vader_array_offset(_a20_slotarr) + (size_t) INT32_C(0), 628u);
        t2 = vader_emit_c$deep_copy_return(((uint8_t) t0.payload.i));
        vader_array_t* _a21_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = t2.payload.obj;
        t1 = (void*) _a21_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(26)) {
        vader_array_t* _a22_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a22_arr;
        t0 = vader_emit_c_ast$perform(3599u, l5);
        vader_array_t* _a23_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a23_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(27)) {
        t0 = vader_emit_c$gc_statistic(3369u);
        vader_array_t* _a24_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a24_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(28)) {
        t0 = vader_emit_c$gc_statistic(2161u);
        vader_array_t* _a25_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a25_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(29)) {
        t0 = vader_emit_c$gc_statistic(3370u);
        vader_array_t* _a26_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a26_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(30)) {
        t0 = vader_emit_c$gc_statistic(3367u);
        vader_array_t* _a27_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a27_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(31)) {
        t0 = vader_emit_c$gc_statistic(3368u);
        vader_array_t* _a28_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a28_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(32)) {
        vader_array_t* _a29_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a29_arr;
        t0 = vader_emit_c_ast$perform(3600u, l5);
        vader_array_t* _a30_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a30_arr->buf->slots)[vader_array_offset(_a30_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a30_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(33)) {
        vader_array_t* _a31_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a31_arr->buf->slots)[vader_array_offset(_a31_arr) + 1u] = l3.payload.obj;
        ((void**) _a31_arr->buf->slots)[vader_array_offset(_a31_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a31_arr;
        t0 = vader_emit_c_ast$returning(3636u, l5);
        vader_array_t* _a32_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a32_arr->buf->slots)[vader_array_offset(_a32_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a32_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(34)) {
        vader_array_t* _a33_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a33_arr;
        t0 = vader_emit_c_ast$perform(3632u, l5);
        vader_array_t* _a34_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a34_arr->buf->slots)[vader_array_offset(_a34_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a34_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(35)) {
        vader_array_t* _a35_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a35_arr->buf->slots)[vader_array_offset(_a35_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a35_arr;
        t0 = vader_emit_c_ast$perform(3645u, l5);
        vader_array_t* _a36_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a36_arr->buf->slots)[vader_array_offset(_a36_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a36_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(36)) {
        vader_array_t* _a37_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a37_arr->buf->slots)[vader_array_offset(_a37_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a37_arr;
        t0 = vader_emit_c_ast$perform(3635u, l5);
        vader_array_t* _a38_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a38_arr->buf->slots)[vader_array_offset(_a38_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a38_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(37)) {
        vader_array_t* _a39_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a39_arr->buf->slots)[vader_array_offset(_a39_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a39_arr;
        t0 = vader_emit_c_ast$perform(3620u, l5);
        vader_array_t* _a40_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a40_arr->buf->slots)[vader_array_offset(_a40_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a40_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(38)) {
        vader_array_t* _a41_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a41_arr;
        t0 = vader_emit_c_ast$returning(3621u, l5);
        vader_array_t* _a42_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a42_arr->buf->slots)[vader_array_offset(_a42_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a42_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(39)) {
        vader_array_t* _a43_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a43_arr;
        t0 = vader_emit_c_ast$returning(3623u, l5);
        vader_array_t* _a44_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a44_arr->buf->slots)[vader_array_offset(_a44_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a44_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(40)) {
        vader_array_t* _a45_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a45_arr->buf->slots)[vader_array_offset(_a45_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a45_arr;
        t0 = vader_emit_c_ast$returning(3624u, l5);
        vader_array_t* _a46_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a46_arr->buf->slots)[vader_array_offset(_a46_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a46_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(42)) {
        vader_array_t* _a47_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a47_arr->buf->slots)[vader_array_offset(_a47_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a47_arr;
        t0 = vader_emit_c_ast$perform(3647u, l5);
        vader_array_t* _a48_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a48_arr->buf->slots)[vader_array_offset(_a48_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a48_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(43)) {
        vader_array_t* _a49_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a49_arr->buf->slots)[vader_array_offset(_a49_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a49_arr;
        t0 = vader_emit_c_ast$perform(3646u, l5);
        vader_array_t* _a50_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a50_arr->buf->slots)[vader_array_offset(_a50_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a50_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(44)) {
        vader_array_t* _a51_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a51_arr->buf->slots)[vader_array_offset(_a51_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a51_arr;
        t0 = vader_emit_c_ast$perform(3625u, l5);
        vader_array_t* _a52_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a52_arr->buf->slots)[vader_array_offset(_a52_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a52_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(45)) {
        vader_array_t* _a53_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a53_slotarr, vader_array_offset(_a53_slotarr) + (size_t) INT32_C(0), 628u);
        t2 = vader_emit_c$monitor_give(((uint8_t) t0.payload.i));
        vader_array_t* _a54_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a54_arr->buf->slots)[vader_array_offset(_a54_arr) + 0u] = t2.payload.obj;
        t1 = (void*) _a54_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(46)) {
        vader_array_t* _a55_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a55_arr;
        t0 = vader_emit_c_ast$perform(3626u, l5);
        vader_array_t* _a56_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a56_arr->buf->slots)[vader_array_offset(_a56_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a56_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(41)) {
        vader_array_t* _a57_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a57_arr;
        t0 = vader_emit_c_ast$perform(3638u, l5);
        vader_array_t* _a58_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a58_arr->buf->slots)[vader_array_offset(_a58_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a58_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(47)) {
        vader_array_t* _a59_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a59_slotarr, vader_array_offset(_a59_slotarr) + (size_t) INT32_C(0), 628u);
        t1 = vader_emit_c$publish(((uint8_t) t0.payload.i));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(48)) {
        vader_array_t* _a60_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a60_arr->buf->slots)[vader_array_offset(_a60_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a60_arr;
        t0 = vader_emit_c_ast$perform(3629u, l5);
        vader_array_t* _a61_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a61_arr->buf->slots)[vader_array_offset(_a61_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a61_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(49)) {
        vader_array_t* _a62_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a62_arr->buf->slots)[vader_array_offset(_a62_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a62_arr;
        t0 = vader_emit_c_ast$perform(3630u, l5);
        vader_array_t* _a63_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a63_arr->buf->slots)[vader_array_offset(_a63_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a63_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(50)) {
        vader_array_t* _a64_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a64_arr->buf->slots)[vader_array_offset(_a64_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a64_arr;
        t0 = vader_emit_c_ast$perform(3631u, l5);
        vader_array_t* _a65_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a65_arr->buf->slots)[vader_array_offset(_a65_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a65_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(51)) {
        vader_array_t* _a66_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a66_arr->buf->slots)[vader_array_offset(_a66_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a66_arr;
        t0 = vader_emit_c_ast$perform(3641u, l5);
        vader_array_t* _a67_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a67_arr->buf->slots)[vader_array_offset(_a67_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a67_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(52)) {
        vader_array_t* _a68_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a68_arr->buf->slots)[vader_array_offset(_a68_arr) + 1u] = l3.payload.obj;
        ((void**) _a68_arr->buf->slots)[vader_array_offset(_a68_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a68_arr;
        t0 = vader_emit_c_ast$returning(3642u, l5);
        vader_array_t* _a69_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a69_arr->buf->slots)[vader_array_offset(_a69_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a69_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(53)) {
        vader_array_t* _a70_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a70_arr->buf->slots)[vader_array_offset(_a70_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a70_arr;
        t0 = vader_emit_c_ast$perform(3643u, l5);
        vader_array_t* _a71_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a71_arr->buf->slots)[vader_array_offset(_a71_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a71_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(54)) {
        vader_array_t* _a72_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a72_arr->buf->slots)[vader_array_offset(_a72_arr) + 1u] = l3.payload.obj;
        ((void**) _a72_arr->buf->slots)[vader_array_offset(_a72_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a72_arr;
        t0 = vader_emit_c_ast$returning(3644u, l5);
        vader_array_t* _a73_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a73_arr->buf->slots)[vader_array_offset(_a73_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a73_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(55)) {
        vader_array_t* _a74_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a74_arr->buf->slots)[vader_array_offset(_a74_arr) + 1u] = l3.payload.obj;
        ((void**) _a74_arr->buf->slots)[vader_array_offset(_a74_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a74_arr;
        t0 = vader_emit_c_ast$returning(3639u, l5);
        vader_array_t* _a75_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a75_arr->buf->slots)[vader_array_offset(_a75_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a75_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(56)) {
        vader_array_t* _a76_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a76_arr->buf->slots)[vader_array_offset(_a76_arr) + 1u] = l3.payload.obj;
        ((void**) _a76_arr->buf->slots)[vader_array_offset(_a76_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a76_arr;
        t0 = vader_emit_c_ast$returning(3640u, l5);
        vader_array_t* _a77_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a77_arr->buf->slots)[vader_array_offset(_a77_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a77_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(57)) {
        vader_array_t* _a78_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a78_arr->buf->slots)[vader_array_offset(_a78_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a78_arr;
        t0 = vader_emit_c_ast$perform(3637u, l5);
        vader_array_t* _a79_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a79_arr->buf->slots)[vader_array_offset(_a79_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a79_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(61)) {
        t1 = vader_emit_c$library_open_shim(3588u, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(62)) {
        t1 = vader_emit_c$library_open_shim(3589u, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(63)) {
        l6 = vader_emit_c$integer_as_address(l2);
        l9 = vader_emit_c_ast$verbatim(2165u);
        vader_array_t* _a80_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a80_arr->buf->slots)[vader_array_offset(_a80_arr) + 1u] = l9.payload.obj;
        ((void**) _a80_arr->buf->slots)[vader_array_offset(_a80_arr) + 0u] = l6.payload.obj;
        l5 = (void*) _a80_arr;
        l6 = vader_emit_c_ast$call(3590u, l5);
        vader_array_t* _a81_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a81_arr->buf->slots)[vader_array_offset(_a81_arr) + 0u] = l3.payload.obj;
        l5 = (void*) _a81_arr;
        l9 = vader_emit_c_ast$call(3659u, l5);
        l9 = vader_emit_c_ast$declaration(2285u, 2165u, l9);
        l6 = vader_emit_c_ast$declaration(3701u, 3087u, l6);
        l10 = vader_emit_c_ast$verbatim(2165u);
        vader_array_t* _a82_arr = vader_array_new(486u, 2u, 13u, 2777u);
        ((void**) _a82_arr->buf->slots)[vader_array_offset(_a82_arr) + 1u] = l10.payload.obj;
        ((void**) _a82_arr->buf->slots)[vader_array_offset(_a82_arr) + 0u] = l3.payload.obj;
        l5 = (void*) _a82_arr;
        l10 = vader_emit_c_ast$perform(3577u, l5);
        vader_array_t* _a83_arr = vader_array_new(266u, 0u, 13u, 1566u);
        l5 = (void*) _a83_arr;
        t0 = vader_emit_c_ast$verbatim(3087u);
        l11 = vader_emit_c$address_as_integer(t0);
        vader_struct_vader_emit_c_ast$CReturn_t* _a84_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a84_obj, 1604u);
        _a84_obj->f_stores = l5;
        _a84_obj->f_value = l11;
        _a84_obj->f_snapshot_type = 0u;
        _a84_obj->f_pops_frame = false;
        l5 = (void*) _a84_obj;
        vader_array_t* _a85_arr = vader_array_new(487u, 4u, 13u, 2782u);
        ((void**) _a85_arr->buf->slots)[vader_array_offset(_a85_arr) + 3u] = l5;
        ((void**) _a85_arr->buf->slots)[vader_array_offset(_a85_arr) + 2u] = l10.payload.obj;
        ((void**) _a85_arr->buf->slots)[vader_array_offset(_a85_arr) + 1u] = l6.payload.obj;
        ((void**) _a85_arr->buf->slots)[vader_array_offset(_a85_arr) + 0u] = l9.payload.obj;
        t1 = (void*) _a85_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(64)) {
        l6 = vader_emit_c$integer_as_address(l2);
        l9 = vader_emit_c_ast$cast(3548u, l3);
        l10 = vader_emit_c$argument(INT64_C(2));
        l10 = vader_emit_c_ast$cast(3548u, l10);
        l11 = vader_emit_c$argument(INT64_C(3));
        vader_array_t* _a86_arr = vader_array_new(486u, 4u, 13u, 2777u);
        ((void**) _a86_arr->buf->slots)[vader_array_offset(_a86_arr) + 3u] = l11.payload.obj;
        ((void**) _a86_arr->buf->slots)[vader_array_offset(_a86_arr) + 2u] = l10.payload.obj;
        ((void**) _a86_arr->buf->slots)[vader_array_offset(_a86_arr) + 1u] = l9.payload.obj;
        ((void**) _a86_arr->buf->slots)[vader_array_offset(_a86_arr) + 0u] = l6.payload.obj;
        l5 = (void*) _a86_arr;
        t0 = vader_emit_c_ast$returning(3586u, l5);
        vader_array_t* _a87_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a87_arr->buf->slots)[vader_array_offset(_a87_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a87_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(65)) {
        l2 = vader_emit_c$integer_as_address(l2);
        l3 = vader_emit_c_ast$cast(3548u, l3);
        l6 = vader_emit_c$argument(INT64_C(2));
        l6 = vader_emit_c_ast$cast(3548u, l6);
        vader_array_t* _a88_arr = vader_array_new(486u, 3u, 13u, 2777u);
        ((void**) _a88_arr->buf->slots)[vader_array_offset(_a88_arr) + 2u] = l6.payload.obj;
        ((void**) _a88_arr->buf->slots)[vader_array_offset(_a88_arr) + 1u] = l3.payload.obj;
        ((void**) _a88_arr->buf->slots)[vader_array_offset(_a88_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a88_arr;
        t0 = vader_emit_c_ast$returning(3585u, l5);
        vader_array_t* _a89_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a89_arr->buf->slots)[vader_array_offset(_a89_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a89_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(59)) {
        vader_array_t* _a90_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a90_arr;
        t0 = vader_emit_c_ast$returning(3579u, l5);
        vader_array_t* _a91_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a91_arr->buf->slots)[vader_array_offset(_a91_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a91_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(60)) {
        vader_array_t* _a92_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l5 = (void*) _a92_arr;
        t0 = vader_emit_c_ast$returning(3578u, l5);
        vader_array_t* _a93_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a93_arr->buf->slots)[vader_array_offset(_a93_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a93_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(0)) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(8);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(9);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(10);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(11);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(12);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(14);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(15);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(16);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(17);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(18);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(19);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(20);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(21);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(22);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(23);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(24);
    }
    if (l12) {
        l12 = true;
    } else {
        l12 = l4 == INT32_C(25);
    }
    if (!(l12)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t3 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_is_extern;
    if (!(t3)) {
        l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
        t4 = concat_2(3457u, l13);
        t0 = vader_emit_c$trap(t4);
        vader_array_t* _a94_arr = vader_array_new(487u, 1u, 13u, 2782u);
        ((void**) _a94_arr->buf->slots)[vader_array_offset(_a94_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a94_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c$user_extern_shim(l0, l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$shim_signature(void* l0, void* l1) {
    bool l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void* l6 = NULL;
    uint8_t t0;
    bool t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    t0 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_signature);
    l3 = vader_emit_c$c_type_for_val_bare(t0);
    l4 = vader_emit_c$host_shim_name(l1);
    l5 = vader_emit_c$value_parameters(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_signature)->f_params, 1793u);
    vader_struct_vader_emit_c_ast$CSignature_t* _a0_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a0_obj, 1608u);
    _a0_obj->f_storage = (uint8_t) 0;
    _a0_obj->f_inline = l2;
    _a0_obj->f_result = l3;
    _a0_obj->f_name = l4;
    _a0_obj->f_parameters = l5;
    l5 = (void*) _a0_obj;
    t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_library_units;
    if (t1) {
        t2 = vader_emit_c$foreign_unit_of(l1);
        if (t2 != 0u) {
            l6 = l5;
            l3 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l6)->f_result;
            l4 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l6)->f_name;
            l6 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l6)->f_parameters;
            vader_struct_vader_emit_c_ast$CSignature_t* _a1_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
            vader_obj_header_init(_a1_obj, 1608u);
            _a1_obj->f_storage = (uint8_t) 1;
            _a1_obj->f_inline = false;
            _a1_obj->f_result = l3;
            _a1_obj->f_name = l4;
            _a1_obj->f_parameters = l6;
            t3 = (void*) _a1_obj;
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$signature_for(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    bool l4;
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    uint8_t l11;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    uint8_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l10, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l3 = vader_emit_c$value_parameters(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params, 2812u);
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature);
    l4 = (t0 > INT64_C(1));
    if (l4) {
        l5 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_results;
        l6 = INT64_C(0);
        l7 = vader_array_length(((vader_array_t*) l5));
        while ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l6, 628u);
            t2 = vader_emit_c$c_type_for_val_bare(((uint8_t) t1.payload.i));
            l8 = concat_2(t2, 432u);
            l9 = vader_emit_c$out_param_name(l6);
            vader_struct_vader_emit_c_ast$CParameter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
            vader_obj_header_init(_a2_obj, 1599u);
            _a2_obj->f_type = l8;
            _a2_obj->f_name = l9;
            l10 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l10);
            l6 = (l6 + INT64_C(1));
        }
    }
    l11 = vader_emit_c$module_function_storage(l0, l1);
    if (l4) {
        l8 = 3699u;
    } else {
        t3 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature);
        l8 = vader_emit_c$c_type_for_val_bare(t3);
    }
    t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_name;
    l9 = vader_emit_c$sanitise(t2);
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 1608u);
    _a3_obj->f_storage = l11;
    _a3_obj->f_inline = false;
    _a3_obj->f_result = l8;
    _a3_obj->f_name = l9;
    _a3_obj->f_parameters = l3;
    t4 = (void*) _a3_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$signed_under_unsigned(uint8_t l0, uint8_t l1) {
    bool l2;
    if (l0 == INT32_C(3)) {
        l2 = l1 == INT32_C(7);
    } else {
        l2 = false;
    }
    if (l2) {
        return true;
    }
    if (l0 == INT32_C(2)) {
        l2 = l1 == INT32_C(6);
    } else {
        l2 = false;
    }
    return l2;
}

static vader_box_t vader_emit_c$signed_view(vader_box_t l0, uint8_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2 != 3428u) {
        if (l2 != 3438u) {
            { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l0.tag == 1593u) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 != INT32_C(2)) {
        if (l1 != INT32_C(3)) {
            { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = vader_emit_c$c_type_for_val_bare(l1);
    l4 = l0;
    t0 = vader_emit_c_ast$cast(l3, l4);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1600u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3) {
    uint8_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    int64_t l8;
    vader_string_t l9 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l6, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_core_bytecode$c_field_val_type(l1, l0);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((uint8_t) l5.payload.i);
    t0 = vader_core_bytecode$is_integer_val(l4);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = vader_emit_c$null_member(l2, l3);
    l6 = vader_emit_c_ast$number(INT64_C(-1));
    vader_struct_vader_emit_c_ast$CCastToTypeOf_t* _a0_obj = (vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCastToTypeOf_t));
    vader_obj_header_init(_a0_obj, 1573u);
    _a0_obj->f_model = l5;
    _a0_obj->f_value = l6;
    l7 = (void*) _a0_obj;
    l5 = vader_emit_c_ast$number(INT64_C(0));
    t1 = vader_emit_c_ast$binary((uint8_t) 7, vader_ref_box(l7), l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a1_obj, 1600u);
    _a1_obj->f_inner = t1;
    l7 = (void*) _a1_obj;
    t0 = vader_core_bytecode$is_unsigned_val(l4);
    if (t0) {
        l8 = INT64_C(0);
    } else {
        l8 = INT64_C(1);
    }
    l5 = vader_emit_c_ast$number(l8);
    l5 = vader_emit_c_ast$binary((uint8_t) 11, vader_ref_box(l7), l5);
    l9 = concat_4(l2, 492u, l3, 271u);
    t1 = vader_emit_c$static_assert(l5, l9);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$single_offset_list(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_68;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t1 = vader_emit_c_ast$verbatim(l1);
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l3 = vader_emit_c_ast$initializer_list(t0);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a2_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a2_obj, 1578u);
    _a2_obj->f_name = l0;
    _a2_obj->f_length = vader_ref_box(l2);
    _a2_obj->f_value = l3;
    l2 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a3_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a3_obj, 1587u);
    _a3_obj->f_storage = (uint8_t) 0;
    _a3_obj->f_constant = true;
    _a3_obj->f_type = 3450u;
    _a3_obj->f_declarator = l2;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$single_reference_row(int64_t l0, vader_string_t l1, vader_string_t l2, int32_t l3, vader_string_t l4, void* l5) {
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    void* l11 = NULL;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l6, &l7, &l8, &l9, &l10, &t1 };
    void** gc_raw_roots[2] = { &l5, &l11 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(1185u, l1);
    l6 = vader_emit_c_ast$verbatim(t0);
    l6 = vader_emit_c_ast$designated(518u, l6);
    t0 = concat_3(3187u, l2, 398u);
    l7 = vader_emit_c_ast$verbatim(t0);
    l7 = vader_emit_c_ast$designated(526u, l7);
    l8 = vader_emit_c_ast$number(((int64_t) (int32_t) l3));
    l8 = vader_emit_c_ast$designated(527u, l8);
    l9 = vader_emit_c_ast$verbatim(l4);
    l9 = vader_emit_c_ast$designated(524u, l9);
    l10 = vader_emit_c_ast$number(INT64_C(1));
    l10 = vader_emit_c_ast$designated(523u, l10);
    vader_array_t* _a0_arr = vader_array_new(486u, 5u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 4u] = l10.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 3u] = l9.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l8.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l6.payload.obj;
    l11 = (void*) _a0_arr;
    vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l5);
    t1 = vader_emit_c$info_row(l0, l11);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$slot_index(vader_string_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l3, &l4, &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c_ast$verbatim(l0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3522u, l2);
    l4 = vader_emit_c$expression_of(l1);
    l4 = vader_emit_c_ast$cast(3185u, l4);
    t0 = vader_emit_c_ast$binary((uint8_t) 3, l3, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$sorted_fn_indices(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    int64_t l2, l3;
    int32_t l4;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(29u, (int64_t) t0, 7u, 626u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _pc9_hdr = (vader_array_t*) l1;
    size_t _pc9_len = vader_array_length(_pc9_hdr);
    size_t _pc9_cap = vader_array_is_borrowed(_pc9_hdr) ? (size_t) 0 : vader_array_capacity(_pc9_hdr);
    void* _pc9_slots = _pc9_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            l4 = ((int32_t) (int64_t) l2);
            if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                ((int32_t*) _pc9_slots)[_pc9_len] = (int32_t) (l4);
                _pc9_len += 1;
            } else {
                vader_array_set_length(_pc9_hdr, _pc9_len);
                if (_pc9_hdr->buf->length < _pc9_len) {
                    _pc9_hdr->buf->length = _pc9_len;
                }
                vader_array_push_i32((vader_array_t*) l1, l4);
                _pc9_hdr = (vader_array_t*) l1;
                _pc9_len = vader_array_length(_pc9_hdr);
                _pc9_cap = vader_array_is_borrowed(_pc9_hdr) ? (size_t) 0 : vader_array_capacity(_pc9_hdr);
                _pc9_slots = _pc9_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc9_hdr, _pc9_len);
        if (_pc9_hdr->buf->length < _pc9_len) {
            _pc9_hdr->buf->length = _pc9_len;
        }
        break;
    }
    vader_struct___lambda_env_vader_emit_c_4_t* _a1_obj = (vader_struct___lambda_env_vader_emit_c_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_4_t));
    vader_obj_header_init(_a1_obj, 693u);
    _a1_obj->f_cap_0 = l0;
    t1 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 551u);
    _a2_closure->code = (void*) &vader_fn_lift___lambda_vader_emit_c_3;
    _a2_closure->env = t1;
    l5 = (void*) _a2_closure;
    t1 = std_sort$sort__i32(l1, l5);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$sorted_module_stems(void* l0) {
    int64_t l1, l6;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_std_collections$Map__string__i32___t*) l0)->f_size;
    if ((INT64_C(0) < l1)) {
        l1 = ((vader_struct_std_collections$Map__string__i32___t*) l0)->f_size;
    } else {
        l1 = INT64_C(0);
    }
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) l1, 0u, 623u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_struct_std_collections$Map__string__i32___t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$Map__string__i32___t*) l3)->f_evals;
    l1 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__string__i32___t*) l3)->f_size;
    while ((l1 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        l7 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l1);
        l8 = l7;
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l8));
        l1 = (l1 + INT64_C(1));
    }
    l3 = (void*) &vader_fn_static___lambda_vader_emit_c_5;
    t1 = std_sort$sort__string(l2, l3);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$source_class(uint8_t l0, uint8_t l1, vader_string_t l2) {
    bool t0;
    t0 = std_string$starts_with(l2, 3423u);
    if (!(t0)) {
        return l0;
    }
    if (l0 == INT32_C(2)) {
        if (l1 == INT32_C(3)) {
            return (uint8_t) 6;
        }
        if (l1 == INT32_C(9)) {
            return (uint8_t) 6;
        }
    }
    if (l0 == INT32_C(3)) {
        if (l1 == INT32_C(9)) {
            return (uint8_t) 7;
        }
        return l0;
    }
    return l0;
}

static vader_box_t vader_emit_c$spilled_address(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 3046u);
    l3 = std_core$write_int(l2, l3, l1);
    t0 = std_core$finish_buffer(l2, l3);
    t1 = vader_emit_c_ast$verbatim(t0);
    l4 = vader_emit_c_ast$address_of(t1);
    t1 = vader_core_bytecode$param_c_type(l0, l1);
    if (!(t1.tag == 0u)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c_ast$cast(3701u, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$spilled_c_type(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_box_t t0;
    vader_string_t t1;
    l2 = vader_core_bytecode$param_c_type(l0, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 628u);
        t1 = vader_emit_c$c_type_for_val_bare(((uint8_t) t0.payload.i));
        return t1;
    }
    t1 = l2.payload.s;
    return t1;
}

static uint8_t vader_emit_c$stack_class_of(uint8_t l0) {
    bool t0;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        return (uint8_t) 2;
    }
    return (uint8_t) 3;
}

static void vader_emit_c$statement_macro(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CCall_t* _a0_obj = (vader_struct_vader_emit_c_ast$CCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCall_t));
    vader_obj_header_init(_a0_obj, 1570u);
    _a0_obj->f_callee = l1;
    _a0_obj->f_arguments = l2;
    t0 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CMacroStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CMacroStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMacroStatement_t));
    vader_obj_header_init(_a1_obj, 1595u);
    _a1_obj->f_call = t0;
    l3 = (void*) _a1_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$static_assert(vader_box_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$c_string_lit(l1);
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(623u, t0);
    t1 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CStringLiterals_t* _a1_obj = (vader_struct_vader_emit_c_ast$CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStringLiterals_t));
    vader_obj_header_init(_a1_obj, 1610u);
    _a1_obj->f_literals = t1;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CStaticAssert_t* _a2_obj = (vader_struct_vader_emit_c_ast$CStaticAssert_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStaticAssert_t));
    vader_obj_header_init(_a2_obj, 1609u);
    _a2_obj->f_condition = l0;
    _a2_obj->f_message = l2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$store_field(void* l0, vader_box_t l1, vader_box_t l2, int32_t l3, vader_box_t l4) {
    uint8_t l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l6 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_emit_c$val_type_of_field(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types, l3);
    l6 = vader_emit_c$coerced_as(l0, l2, l5);
    vader_emit_c$assign(l0, l1, l6);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_emit_c$is_ref_val(l5);
    if (t0) {
        l6 = l4;
        vader_emit_c$write_barrier_for(l0, l6, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_emit_c$string_array_tag(void* l0, int32_t l1) {
    int32_t t0;
    if (!((l1 < INT32_C(0)))) {
        t0 = vader_emit_c$array_tag(l0, l1);
        return t0;
    }
    return INT32_C(-1);
}

static int32_t vader_emit_c$string_primitive_tag(void* l0) {
    int64_t l1, l2;
    vader_box_t l3;
    void* t0;
    bool t1;
    l1 = INT64_C(0);
    l2 = vader_array_length(((vader_array_t*) l0));
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        if (l3.tag == 1283u) {
            t0 = l3.payload.obj;
            t1 = vader_core_bytecode$is_string_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
            if (t1) {
                return ((int32_t) (int64_t) l1);
            }
        }
        l1 = (l1 + INT64_C(1));
    }
    return INT32_C(-1);
}

static vader_string_t vader_emit_c$struct_c_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$sanitise(l0);
    t0 = concat_3(3660u, l1, 1306u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$struct_c_names_of(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        if (l5.tag == 1286u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
            l6 = vader_emit_c$struct_c_name(t1);
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l6));
        } else {
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, 0u));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$struct_definition(void* l0, void* l1, void* l2, int64_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    int64_t l6, l7;
    int32_t l9, l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l5, &l8, &l13, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CField_t* _a0_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
    vader_obj_header_init(_a0_obj, 1583u);
    _a0_obj->f_type = 3612u;
    _a0_obj->f_name = 2629u;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(269u, 1u, 13u, 1583u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
        l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
        t1 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
        t2 = vader_emit_c$val_type_of_bc_type(t1);
        if (t2 != INT32_C(14)) {
            l10 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l10);
            l11 = vader_emit_c$c_type_for(t1);
            t3 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_name;
            l12 = vader_emit_c$field_c_name(t3);
            vader_struct_vader_emit_c_ast$CField_t* _a5_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
            vader_obj_header_init(_a5_obj, 1583u);
            _a5_obj->f_type = l11;
            _a5_obj->f_name = l12;
            l13 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l4, l13);
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
    t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l3];
    t3 = t1.payload.s;
    vader_struct_vader_emit_c_ast$CStructDefinition_t* _a7_obj = (vader_struct_vader_emit_c_ast$CStructDefinition_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructDefinition_t));
    vader_obj_header_init(_a7_obj, 1611u);
    _a7_obj->f_name = t3;
    _a7_obj->f_fields = l4;
    t0 = (void*) _a7_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
    uint8_t l6, l7;
    uint64_t l8;
    vader_string_t l9 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[4] = { &l2, &l10, &l11, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
    l6 = vader_emit_c$val_type_of_bc_type(t0);
    if (l6 == INT32_C(17)) {
        t0 = vader_emit_c$box_slot_1(l0, l1, l2, l3, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1289u) {
        t1 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_kind;
        t1 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_bits;
        t0 = vader_emit_c$data_slot(l7, l8);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1290u) {
        t1 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t1)->f_value;
        t2 = vader_emit_c$atom_for(l5, l9);
        t0 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l6 == INT32_C(16))) {
        l10 = l2;
        l11 = vader_emit_c$emit_data_value(l0, l1, l10, l3, l5);
        t0 = vader_emit_c$boxed_object(l4, l11);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = l2;
    l10 = vader_emit_c$emit_data_value(l0, l1, l10, l3, l5);
    t0 = vader_emit_c_ast$cast(3701u, l10);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$struct_info_row(void* l0, void* l1, void* l2, int64_t l3) {
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l5 = 0;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[4] = { &l4, &l6, &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &l9 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$verbatim(1186u);
    l4 = vader_emit_c_ast$designated(518u, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l3];
    l5 = t0.payload.s;
    t1 = concat_3(3187u, l5, 398u);
    l6 = vader_emit_c_ast$verbatim(t1);
    l6 = vader_emit_c_ast$designated(526u, l6);
    t2 = vader_core_bytecode$size_of_bc_type(vader_ref_box(l1));
    l7 = vader_emit_c_ast$number(((int64_t) (int32_t) t2));
    l7 = vader_emit_c_ast$designated(527u, l7);
    vader_array_t* _a1_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = l7.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l4.payload.obj;
    l8 = (void*) _a1_arr;
    t3 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_shared;
    if (t3) {
        l4 = vader_emit_c_ast$verbatim(1184u);
        l4 = vader_emit_c_ast$designated(512u, l4);
        vader_array_push_ref((vader_array_t*) l8, l4.payload.obj);
    }
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_ptr_offsets;
    vader_emit_c$push_offset_list(l8, 3083u, l9);
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_str_offsets;
    vader_emit_c$push_offset_list(l8, 3236u, l9);
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_ref_offsets;
    vader_emit_c$push_offset_list(l8, 3107u, l9);
    t0 = vader_emit_c$info_row(l3, l8);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$struct_set_barrier(void* l0, vader_string_t l1, vader_box_t l2) {
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$StructSet_t*) l0)->f_stack;
    if (!(t0)) {
        t1 = concat_2(l1, 432u);
        t2 = vader_emit_c_ast$cast(t1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_emit_c$synthesises_prototype(void* l0) {
    bool t0;
    int64_t t1;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_is_extern;
    if (t0) {
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_c_headers));
        return t1 == INT64_C(0);
    }
    return false;
}

static vader_box_t vader_emit_c$tag_equals(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t1 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l3 = INT64_C(0);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3423u);
    t0 = std_core$finish_buffer(l2, l3);
    l5 = vader_emit_c_ast$verbatim(t0);
    t1 = vader_emit_c_ast$binary((uint8_t) 11, l0, l5);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$tag_expression(vader_box_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(16)) {
        t0 = vader_emit_c_ast$pointer_member(3613u, l0, 3410u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 1596u);
    _a0_obj->f_base = l0;
    _a0_obj->f_member = 3279u;
    _a0_obj->f_arrow = false;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$tag_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    uint8_t l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    l2 = vader_emit_c$val_of(l0);
    t0 = vader_emit_c$tag_expression(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$trait_check_expr(void* l0, vader_box_t l1, vader_string_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    int64_t l6, l7;
    int32_t l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[6] = { &l0, &l4, &l5, &l8, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$tag_equals(l1, l3);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1600u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1;
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_impl_table;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
        t2 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) l8)->f_trait_name;
        if (t2 == l2) {
            l9 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) l8)->f_type_index;
            t0 = vader_emit_c$tag_equals(l1, l9);
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a3_obj, 1600u);
            _a3_obj->f_inner = t0;
            l10 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l4, l10);
        }
        l7 = (l7 + INT64_C(1));
    }
    t0 = vader_emit_c_ast$any_of(l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$tramp_unbox_args(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3, l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    uint8_t l7;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l6, &l8, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l2, 628u);
        if (((int32_t) t0.payload.i) != INT32_C(14)) {
            l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l4, l5, 1793u);
            l5 = std_core$write_int(l4, l5, l2);
            t1 = std_core$finish_buffer(l4, l5);
            l6 = vader_emit_c_ast$verbatim(t1);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l2, 628u);
            l7 = ((uint8_t) t0.payload.i);
            l8 = vader_emit_c$unbox_expr(l6, l7);
            vader_array_push_ref((vader_array_t*) l1, l8.payload.obj);
        }
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$trampoline_signature(void* l0, vader_string_t l1, void* l2) {
    vader_string_t l3 = 0;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(3597u, l1);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    t0 = vader_emit_c$erased_wrapper_signature(l0, l3, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$trap(vader_string_t l0) {
    void* l1 = NULL;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$c_string_lit(l0);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$perform(3661u, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$type_id_for_struct_symbol(void* l0, int32_t l1) {
    int32_t l2;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_bytecode$struct_symbol_type_index(l0, l1);
    if (!((l2 < INT32_C(0)))) {
        { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(80));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 2172u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 234u);
    t0 = std_core$finish_buffer(l3, l4);
    vader_host_std_core$Intrinsic$panic(t0);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_emit_c$typed_array_fill_for(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(7)) {
        vader_struct_vader_emit_c$SlotFill_t* _a0_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a0_obj, 1557u);
        _a0_obj->f_cty = 2730u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_emit_c$SlotFill_t* _a1_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a1_obj, 1557u);
        _a1_obj->f_cty = 2730u;
        _a1_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_emit_c$SlotFill_t* _a2_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a2_obj, 1557u);
        _a2_obj->f_cty = 2730u;
        _a2_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(8)) {
        vader_struct_vader_emit_c$SlotFill_t* _a3_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a3_obj, 1557u);
        _a3_obj->f_cty = 2731u;
        _a3_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(4)) {
        vader_struct_vader_emit_c$SlotFill_t* _a4_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a4_obj, 1557u);
        _a4_obj->f_cty = 2731u;
        _a4_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_emit_c$SlotFill_t* _a5_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a5_obj, 1557u);
        _a5_obj->f_cty = 2352u;
        _a5_obj->f_val = (uint8_t) 9;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(1)) {
        vader_struct_vader_emit_c$SlotFill_t* _a6_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a6_obj, 1557u);
        _a6_obj->f_cty = 3453u;
        _a6_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a6_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(5)) {
        vader_struct_vader_emit_c$SlotFill_t* _a7_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a7_obj, 1557u);
        _a7_obj->f_cty = 2732u;
        _a7_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a7_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        vader_struct_vader_emit_c$SlotFill_t* _a8_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a8_obj, 1557u);
        _a8_obj->f_cty = 3453u;
        _a8_obj->f_val = (uint8_t) 10;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(2)) {
        vader_struct_vader_emit_c$SlotFill_t* _a9_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a9_obj, 1557u);
        _a9_obj->f_cty = 3450u;
        _a9_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(6)) {
        vader_struct_vader_emit_c$SlotFill_t* _a10_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a10_obj, 1557u);
        _a10_obj->f_cty = 2729u;
        _a10_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a10_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(9)) {
        vader_struct_vader_emit_c$SlotFill_t* _a11_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a11_obj, 1557u);
        _a11_obj->f_cty = 2541u;
        _a11_obj->f_val = (uint8_t) 8;
        t0 = (void*) _a11_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$typed_slot(vader_string_t l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
    void** gc_raw_roots[1] = { &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(l0, 432u);
    t0 = concat_2(l1, 486u);
    l4 = vader_emit_c_ast$verbatim(t0);
    t1 = vader_emit_c_ast$cast(l3, l4);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1600u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CIndex_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a1_obj, 1591u);
    _a1_obj->f_base = vader_ref_box(t2);
    _a1_obj->f_index = l2;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$unbox_expr(vader_box_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l3, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(0)) {
        l2 = vader_emit_c$payload_cast(2732u, l0, 2633u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        l2 = vader_emit_c$payload_cast(2729u, l0, 2633u);
    } else if (l1 == INT32_C(2)) {
        l2 = vader_emit_c$payload_cast(2730u, l0, 2633u);
    } else if (l1 == INT32_C(3)) {
        l2 = vader_emit_c$payload_cast(2731u, l0, 2633u);
    } else if (l1 == INT32_C(4)) {
        l2 = vader_emit_c$payload_cast(3453u, l0, 2633u);
    } else if (l1 == INT32_C(5)) {
        l2 = vader_emit_c$payload_cast(3450u, l0, 2633u);
    } else if (l1 == INT32_C(6)) {
        l2 = vader_emit_c$payload_cast(3451u, l0, 2633u);
    } else if (l1 == INT32_C(7)) {
        l2 = vader_emit_c$payload_cast(3452u, l0, 2633u);
    } else if (l1 == INT32_C(11)) {
        l2 = vader_emit_c$payload_cast(3451u, l0, 2633u);
    } else if (l1 == INT32_C(8)) {
        l2 = vader_emit_c$payload_cast(2541u, l0, 2480u);
    } else if (l1 == INT32_C(9)) {
        l2 = vader_emit_c$payload_cast(2352u, l0, 2480u);
    } else if (l1 == INT32_C(10)) {
        l2 = vader_emit_c$payload(l0, 2070u);
    } else if (l1 == INT32_C(12)) {
        l2 = vader_emit_c$payload(l0, 3152u);
    } else if (l1 == INT32_C(13)) {
        l2 = l0;
    } else if (l1 == INT32_C(14)) {
        l2 = vader_emit_c_ast$verbatim(385u);
    } else if (l1 == INT32_C(15)) {
        l3 = vader_emit_c$payload(l0, 2633u);
        l3 = vader_emit_c_ast$cast(2749u, l3);
        t0 = vader_emit_c_ast$cast(3701u, l3);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a0_obj, 1600u);
        _a0_obj->f_inner = t0;
        t1 = (void*) _a0_obj;
        l2 = vader_ref_box(t1);
    } else if (l1 == INT32_C(16)) {
        l2 = vader_emit_c$payload(l0, 3007u);
    } else {
        if (!(l1 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$union_field_place(void* l0, int32_t l1, int32_t l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    int32_t l5, l10;
    vader_box_t l6 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    int64_t l8, l9;
    vader_string_t t0 = 0;
    vader_string_t t3 = 0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l3, &l6, &l11, &l12, &t2 };
    void** gc_raw_roots[4] = { &l0, &l4, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = vader_core_bytecode$union_layout_struct(l4, l1);
    if (l6.tag == 0u) {
        l7 = (void*) vader_buffer_new((size_t) INT64_C(78));
        l8 = INT64_C(0);
        l8 = std_core$write_string_at(l7, l8, 2171u);
        l9 = ((int64_t) (int32_t) l1);
        l8 = std_core$write_int(l7, l8, l9);
        l8 = std_core$write_string_at(l7, l8, 464u);
        t0 = std_core$finish_buffer(l7, l8);
        vader_host_std_core$Intrinsic$panic(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l5 = ((int32_t) l6.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        if (!(l6.tag == 1286u)) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(61));
            l8 = INT64_C(0);
            l8 = std_core$write_string_at(l7, l8, 2175u);
            l9 = ((int64_t) (int32_t) l1);
            l8 = std_core$write_int(l7, l8, l9);
            l8 = std_core$write_string_at(l7, l8, 207u);
            t0 = std_core$finish_buffer(l7, l8);
            vader_host_std_core$Intrinsic$panic(t0);
            vader_unreachable("a no-return call returned");
        }
        t1 = l6.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
        l10 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t2 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l10);
        t0 = vader_emit_c$c_type_for(t2);
        l6 = vader_emit_c_ast$verbatim(t0);
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l5];
        t0 = t2.payload.s;
        l11 = vader_emit_c_ast$verbatim(t0);
        t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_name;
        t3 = vader_emit_c$field_c_name(t0);
        l12 = vader_emit_c_ast$verbatim(t3);
        vader_array_t* _a4_arr = vader_array_new(486u, 4u, 13u, 2777u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 3u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l12.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l11.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l6.payload.obj;
        l4 = (void*) _a4_arr;
        l6 = vader_emit_c_ast$call(1187u, l4);
        l5 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_struct_vader_emit_c$UnionFieldPlace_t* _a5_obj = (vader_struct_vader_emit_c$UnionFieldPlace_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$UnionFieldPlace_t));
        vader_obj_header_init(_a5_obj, 1564u);
        _a5_obj->f_place = l6;
        _a5_obj->f_type_index = l5;
        t1 = (void*) _a5_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static void* vader_emit_c$unit_names_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l3, l4, l7, l8;
    int32_t l5, l9;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    uint8_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l12, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l10, &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 623u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(623u, 1297u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(1);
    l4 = vader_array_length(((vader_array_t*) l1));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0)];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l6 = vader_core_mangle$mangle_module_part(t1);
        l7 = INT64_C(0);
        l8 = vader_host_std_core$Intrinsic$byte_len(l6);
        while ((l7 < l8)) {
            t2 = vader_host_std_core$Intrinsic$byte_at(l6, l7);
            t3 = vader_support_text$is_ident_byte(t2);
            if (!(t3)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
                l9 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) INT32_C(0)];
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
                t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l9);
                l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
                t1 = concat_3(3199u, l10, 1503u);
                std_abort$todo(t1);
                vader_unreachable("a no-return call returned");
            }
            l7 = (l7 + INT64_C(1));
        }
        if (l6 == 0u) {
            l11 = 1303u;
        } else {
            l11 = l6;
        }
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l11));
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 623u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(26u, 0u, 12u, 621u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 626u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections$Map__string__bool_t* _a10_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a10_obj, 976u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_grow_at = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a10_obj;
    vader_struct_std_collections$Set__string_t* _a11_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a11_obj, 1072u);
    _a11_obj->f_inner = t0;
    l12 = (void*) _a11_obj;
    l13 = l2;
    l3 = vader_array_length(((vader_array_t*) l13));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        t4 = vader_array_box_slots(_a12_slotarr->buf)[vader_array_offset(_a12_slotarr) + (size_t) l4];
        l6 = t4.payload.s;
        t3 = std_collections$add__string(l12, l6);
        if (!(t3)) {
            t1 = concat_3(3198u, l6, 1624u);
            std_abort$todo(t1);
            vader_unreachable("a no-return call returned");
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$unreachable(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$c_string_lit(l1);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3665u, l2);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_c$user_extern_shim(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l43 = NULL;
    void* l49 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    void* l56 = NULL;
    void* l57 = NULL;
    void* l61 = NULL;
    void* l64 = NULL;
    void* l67 = NULL;
    void* l70 = NULL;
    void* l73 = NULL;
    void* l75 = NULL;
    int64_t l6, l7, l19, l22, l32, l36, l44, l58, l62, l65, l71, l76;
    int32_t l8, l10, l25, l27, l29, l48;
    bool l9;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l24 = vader_box_null(), l33 = vader_box_null(), l38 = vader_box_null(), l39 = vader_box_null(), l40 = vader_box_null(), l41 = vader_box_null(), l46 = vader_box_null(), l47 = vader_box_null(), l50 = vader_box_null(), l51 = vader_box_null(), l54 = vader_box_null(), l55 = vader_box_null(), l60 = vader_box_null(), l63 = vader_box_null(), l68 = vader_box_null(), l69 = vader_box_null(), l72 = vader_box_null(), l74 = vader_box_null(), l77 = vader_box_null(), l78 = vader_box_null();
    vader_string_t l20 = 0;
    vader_string_t l26 = 0;
    vader_string_t l28 = 0;
    vader_string_t l37 = 0;
    vader_string_t l42 = 0;
    vader_string_t l45 = 0;
    vader_string_t l59 = 0;
    vader_string_t l66 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    void* t4 = NULL;
    uint8_t t5;
    vader_box_t* gc_roots[24] = {
        &l11, &l12, &l13, &l24, &l33, &l38, &l39, &l40, &l41, &l46, &l47, &l50, &l51, &l54, &l55,
        &l60, &l63, &l68, &l69, &l72, &l74, &l77, &l78, &t2,
    };
    void** gc_raw_roots[30] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l14, &l15, &l16, &l17, &l18, &l21, &l23, &l30, &l31, &l34,
        &l35, &l43, &l49, &l52, &l53, &l56, &l57, &l61, &l64, &l67, &l70, &l73, &l75, &t4,
    };
    vader_string_t* gc_atom_roots[9] = { &l20, &l26, &l28, &l37, &l42, &l45, &l59, &l66, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 24u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    vader_array_t* _a0_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l5 = (void*) _a2_arr;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_blocking;
    if (t0) {
        l6 = INT64_C(0);
        l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
        while ((l6 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l8 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l6];
            t0 = vader_emit_c$is_abi_array(l1, l8);
            if (t0) {
                l9 = true;
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
                l10 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l6];
                t1 = vader_emit_c$mirrored_c_struct(l1, l10);
                l9 = t1 != 0u;
            }
            if (l9) {
                t2 = vader_emit_c$argument(l6);
                l11 = vader_emit_c_ast$address_of(t2);
                vader_array_push_ref((vader_array_t*) l5, l11.payload.obj);
            }
            l6 = (l6 + INT64_C(1));
        }
        t3 = vader_array_length(((vader_array_t*) l5));
        if ((t3 > INT64_C(0))) {
            t3 = vader_array_length(((vader_array_t*) l5));
            l11 = vader_emit_c_ast$number(t3);
            l12 = vader_emit_c_ast$array_declaration(3702u, 1283u, l5);
            vader_array_push_ref((vader_array_t*) l4, l12.payload.obj);
            l12 = vader_emit_c_ast$verbatim(1282u);
            l13 = vader_emit_c_ast$verbatim(1283u);
            vader_array_t* _a5_arr = vader_array_new(486u, 3u, 13u, 2777u);
            ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 2u] = l11.payload.obj;
            ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l13.payload.obj;
            ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = l12.payload.obj;
            l14 = (void*) _a5_arr;
            l11 = vader_emit_c_ast$perform(1176u, l14);
            vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
        }
        t3 = vader_array_length(((vader_array_t*) l5));
        if ((t3 > INT64_C(0))) {
            l6 = INT64_C(1);
        } else {
            l6 = INT64_C(0);
        }
        t2 = vader_emit_c_ast$number(l6);
        vader_array_t* _a6_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t2.payload.obj;
        l14 = (void*) _a6_arr;
        l11 = vader_emit_c_ast$call(3617u, l14);
        l11 = vader_emit_c_ast$declaration(2728u, 1278u, l11);
        vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
    }
    vader_array_t* _a7_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l14 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l15 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(486u, 0u, 13u, 2777u);
    l16 = (void*) _a9_arr;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    while ((l6 < l7)) {
        l11 = vader_emit_c$argument(l6);
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
        l8 = ((int32_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l6];
        t0 = vader_emit_c$is_abi_array(l1, l8);
        if (t0) {
            t2 = vader_emit_c_ast$cast(3548u, l11);
            vader_array_t* _a11_arr = vader_array_new(486u, 1u, 13u, 2777u);
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = t2.payload.obj;
            l17 = (void*) _a11_arr;
            l12 = vader_emit_c_ast$call(3515u, l17);
            l18 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l19 = INT64_C(0);
            l19 = std_core$write_string_at(l18, l19, 3152u);
            l19 = std_core$write_int(l18, l19, l6);
            l20 = std_core$finish_buffer(l18, l19);
            l13 = vader_emit_c_ast$declaration(3648u, l20, l12);
            vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
            l21 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l22 = INT64_C(0);
            l22 = std_core$write_string_at(l21, l22, 3152u);
            l22 = std_core$write_int(l21, l22, l6);
            t1 = std_core$finish_buffer(l21, l22);
            t2 = vader_emit_c_ast$verbatim(t1);
            vader_struct_vader_emit_c_ast$CMember_t* _a12_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
            vader_obj_header_init(_a12_obj, 1596u);
            _a12_obj->f_base = t2;
            _a12_obj->f_member = 3083u;
            _a12_obj->f_arrow = false;
            l23 = (void*) _a12_obj;
            t1 = vader_emit_c$extern_parameter_type(l0, l1, l6);
            l24 = vader_emit_c$as_buffer_type(t1, vader_ref_box(l23));
            vader_array_push_ref((vader_array_t*) l3, l24.payload.obj);
        } else {
            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
            l10 = ((int32_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l6];
            t1 = vader_emit_c$mirrored_c_struct(l1, l10);
            if (t1 != 0u) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
                l25 = ((int32_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l6];
                l26 = vader_emit_c$mirrored_c_struct(l1, l25);
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
                l27 = ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l6];
                t1 = vader_emit_c$bc_struct_name(l1, l27);
                l28 = vader_emit_c$struct_c_name(t1);
                vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
                l29 = ((int32_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l6];
                l30 = vader_emit_c$bc_struct_fields(l1, l29);
                l31 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l32 = INT64_C(0);
                l32 = std_core$write_string_at(l31, l32, 3046u);
                l32 = std_core$write_int(l31, l32, l6);
                t1 = std_core$finish_buffer(l31, l32);
                l33 = vader_emit_c_ast$verbatim(t1);
                t1 = concat_2(l28, 432u);
                t2 = vader_emit_c_ast$cast(t1, l11);
                vader_struct_vader_emit_c_ast$CParenthesized_t* _a17_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
                vader_obj_header_init(_a17_obj, 1600u);
                _a17_obj->f_inner = t2;
                l34 = (void*) _a17_obj;
                l35 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l36 = INT64_C(0);
                l36 = std_core$write_string_at(l35, l36, 3046u);
                l36 = std_core$write_int(l35, l36, l6);
                l37 = std_core$finish_buffer(l35, l36);
                t2 = vader_emit_c_ast$number(INT64_C(0));
                vader_array_t* _a18_arr = vader_array_new(486u, 1u, 13u, 2777u);
                ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = t2.payload.obj;
                t4 = (void*) _a18_arr;
                l38 = vader_emit_c_ast$initializer_list(t4);
                l39 = vader_emit_c_ast$declaration(l26, l37, l38);
                vader_array_push_ref((vader_array_t*) l4, l39.payload.obj);
                vader_emit_c$push_member_copies(l1, l30, l33, vader_ref_box(l34), true, l4, INT32_C(0));
                t0 = vader_core_bytecode$param_is_by_address(l2, l6);
                if (t0) {
                    t0 = vader_core_bytecode$param_is_c_out(l2, l6);
                    if (t0) {
                        l40 = vader_emit_c_ast$address_of(l11);
                        vader_array_push_ref((vader_array_t*) l16, l40.payload.obj);
                        vader_emit_c$push_member_copies(l1, l30, l33, vader_ref_box(l34), false, l15, INT32_C(0));
                    }
                    l41 = vader_emit_c_ast$address_of(l33);
                    vader_array_push_ref((vader_array_t*) l3, l41.payload.obj);
                } else {
                    vader_array_push_ref((vader_array_t*) l3, l33.payload.obj);
                    l6 = (l6 + INT64_C(1));
                    continue;
                }
            } else {
                t0 = vader_core_bytecode$param_is_by_address(l2, l6);
                if (t0) {
                    l42 = vader_emit_c$spilled_c_type(l0, l6);
                    l43 = (void*) vader_buffer_new((size_t) INT64_C(21));
                    l44 = INT64_C(0);
                    l44 = std_core$write_string_at(l43, l44, 3046u);
                    l44 = std_core$write_int(l43, l44, l6);
                    l45 = std_core$finish_buffer(l43, l44);
                    l46 = vader_emit_c_ast$declaration(l42, l45, l11);
                    vader_array_push_ref((vader_array_t*) l4, l46.payload.obj);
                    l47 = vader_emit_c$spilled_address(l0, l6);
                    vader_array_push_ref((vader_array_t*) l3, l47.payload.obj);
                } else {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
                    l48 = ((int32_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l6];
                    t0 = vader_emit_c$is_abi_nullable_pointer(l1, l48);
                    if (t0) {
                        vader_struct_vader_emit_c_ast$CMember_t* _a20_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a20_obj, 1596u);
                        _a20_obj->f_base = l11;
                        _a20_obj->f_member = 3279u;
                        _a20_obj->f_arrow = false;
                        l49 = (void*) _a20_obj;
                        l50 = vader_emit_c_ast$verbatim(1171u);
                        l51 = vader_emit_c_ast$binary((uint8_t) 11, vader_ref_box(l49), l50);
                        vader_struct_vader_emit_c_ast$CMember_t* _a21_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a21_obj, 1596u);
                        _a21_obj->f_base = l11;
                        _a21_obj->f_member = 3065u;
                        _a21_obj->f_arrow = false;
                        t4 = (void*) _a21_obj;
                        vader_struct_vader_emit_c_ast$CMember_t* _a22_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a22_obj, 1596u);
                        _a22_obj->f_base = vader_ref_box(t4);
                        _a22_obj->f_member = 2633u;
                        _a22_obj->f_arrow = false;
                        l52 = (void*) _a22_obj;
                        t4 = (void*) &vader_data_70;
                        vader_array_t* _a23_slotarr = ((vader_array_t*) t4);
                        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                        l53 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) INT64_C(0));
                        l54 = vader_emit_c_ast$cast(2749u, vader_ref_box(l52));
                        l55 = vader_emit_c_ast$cast(3701u, l54);
                        vader_struct_vader_emit_c_ast$CConditional_t* _a24_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
                        vader_obj_header_init(_a24_obj, 1575u);
                        _a24_obj->f_condition = l51;
                        _a24_obj->f_then_value = vader_ref_box(l53);
                        _a24_obj->f_else_value = l55;
                        l56 = (void*) _a24_obj;
                        l57 = (void*) vader_buffer_new((size_t) INT64_C(21));
                        l58 = INT64_C(0);
                        l58 = std_core$write_string_at(l57, l58, 3046u);
                        l58 = std_core$write_int(l57, l58, l6);
                        l59 = std_core$finish_buffer(l57, l58);
                        l60 = vader_emit_c_ast$declaration(3701u, l59, vader_ref_box(l56));
                        vader_array_push_ref((vader_array_t*) l4, l60.payload.obj);
                        l61 = (void*) vader_buffer_new((size_t) INT64_C(21));
                        l62 = INT64_C(0);
                        l62 = std_core$write_string_at(l61, l62, 3046u);
                        l62 = std_core$write_int(l61, l62, l6);
                        t1 = std_core$finish_buffer(l61, l62);
                        l63 = vader_emit_c_ast$verbatim(t1);
                        vader_array_push_ref((vader_array_t*) l3, l63.payload.obj);
                    } else {
                        vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l6)
                        t2 = vader_array_read_u8(_a25_slotarr, vader_array_offset(_a25_slotarr) + (size_t) l6, 628u);
                        if (((int32_t) t2.payload.i) == INT32_C(12)) {
                            l64 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l65 = INT64_C(0);
                            l65 = std_core$write_string_at(l64, l65, 2162u);
                            l65 = std_core$write_int(l64, l65, l6);
                            l66 = std_core$finish_buffer(l64, l65);
                            vader_array_t* _a26_arr = vader_array_new(486u, 1u, 13u, 2777u);
                            ((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = l11.payload.obj;
                            l67 = (void*) _a26_arr;
                            l68 = vader_emit_c_ast$call(3659u, l67);
                            l69 = vader_emit_c_ast$declaration(2285u, l66, l68);
                            vader_array_push_ref((vader_array_t*) l4, l69.payload.obj);
                            l70 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l71 = INT64_C(0);
                            l71 = std_core$write_string_at(l70, l71, 2162u);
                            l71 = std_core$write_int(l70, l71, l6);
                            t1 = std_core$finish_buffer(l70, l71);
                            l72 = vader_emit_c_ast$verbatim(t1);
                            vader_array_t* _a27_arr = vader_array_new(486u, 2u, 13u, 2777u);
                            ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 1u] = l72.payload.obj;
                            ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = l11.payload.obj;
                            l73 = (void*) _a27_arr;
                            l74 = vader_emit_c_ast$perform(3577u, l73);
                            vader_array_push_ref((vader_array_t*) l14, l74.payload.obj);
                            l75 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l76 = INT64_C(0);
                            l76 = std_core$write_string_at(l75, l76, 2162u);
                            l76 = std_core$write_int(l75, l76, l6);
                            t1 = std_core$finish_buffer(l75, l76);
                            l77 = vader_emit_c_ast$verbatim(t1);
                            vader_array_push_ref((vader_array_t*) l3, l77.payload.obj);
                        } else {
                            l78 = vader_emit_c$renamed_argument(l0, l6, l11);
                            vader_array_push_ref((vader_array_t*) l3, l78.payload.obj);
                        }
                    }
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a28_arr = vader_array_new(487u, 0u, 13u, 2782u);
    l17 = (void*) _a28_arr;
    t3 = vader_array_length(((vader_array_t*) l16));
    if ((t3 > INT64_C(0))) {
        t3 = vader_array_length(((vader_array_t*) l16));
        l11 = vader_emit_c_ast$number(t3);
        l12 = vader_emit_c_ast$array_declaration(3702u, 1288u, l16);
        vader_array_push_ref((vader_array_t*) l4, l12.payload.obj);
        l12 = vader_emit_c_ast$verbatim(1287u);
        l13 = vader_emit_c_ast$verbatim(1288u);
        vader_array_t* _a29_arr = vader_array_new(486u, 3u, 13u, 2777u);
        ((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 2u] = l11.payload.obj;
        ((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 1u] = l13.payload.obj;
        ((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 0u] = l12.payload.obj;
        l16 = (void*) _a29_arr;
        l11 = vader_emit_c_ast$perform(1176u, l16);
        vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
        vader_array_t* _a30_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a30_arr->buf->slots)[vader_array_offset(_a30_arr) + 0u] = l12.payload.obj;
        l16 = (void*) _a30_arr;
        l11 = vader_emit_c_ast$perform(1175u, l16);
        vader_array_push_ref((vader_array_t*) l17, l11.payload.obj);
    }
    vader_array_push_all((vader_array_t*) l17, (vader_array_t*) l15);
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_blocking;
    if (!(t0)) {
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
        l13 = vader_emit_c_ast$call(t1, l3);
        l13 = vader_emit_c$read_back(l0, l13);
        l18 = vader_emit_c$forwarded_result(l2, l1, l13);
        l26 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
        t1 = concat_3(319u, l26, 319u);
        t2 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a31_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a31_arr->buf->slots)[vader_array_offset(_a31_arr) + 0u] = t2.payload.obj;
        l21 = (void*) _a31_arr;
        l13 = vader_emit_c_ast$perform(1173u, l21);
        vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
        l13 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l18)->f_capture;
        vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
        vader_array_t* _a32_arr = vader_array_new(486u, 0u, 13u, 2777u);
        l21 = (void*) _a32_arr;
        l13 = vader_emit_c_ast$perform(1174u, l21);
        vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
        vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l17);
        l21 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l18)->f_settle;
        vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l21);
        vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l14);
        vader_array_t* _a33_arr = vader_array_new(266u, 0u, 13u, 1566u);
        l21 = (void*) _a33_arr;
        l13 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l18)->f_returned;
        vader_struct_vader_emit_c_ast$CReturn_t* _a34_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a34_obj, 1604u);
        _a34_obj->f_stores = l21;
        _a34_obj->f_value = l13;
        _a34_obj->f_snapshot_type = 0u;
        _a34_obj->f_pops_frame = false;
        l18 = (void*) _a34_obj;
        vader_array_push_ref((vader_array_t*) l4, l18);
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l20 = vader_emit_c$relay_frame_name(l0);
    t1 = concat_2(3249u, l20);
    l11 = vader_emit_c_ast$declaration(t1, 1279u, vader_box_obj(0u, NULL));
    vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l3));
    while ((l6 < l7)) {
        l15 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l19 = INT64_C(0);
        l19 = std_core$write_string_at(l15, l19, 1280u);
        l19 = std_core$write_int(l15, l19, l6);
        t1 = std_core$finish_buffer(l15, l19);
        l11 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a35_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l12 = vader_array_ref_load_box(_a35_slotarr->buf, vader_array_offset(_a35_slotarr) + (size_t) l6);
        vader_struct_vader_emit_c_ast$CAssign_t* _a36_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a36_obj, 1566u);
        _a36_obj->f_target = l11;
        _a36_obj->f_value = l12;
        _a36_obj->f_operator = vader_box_obj(0u, NULL);
        l16 = (void*) _a36_obj;
        vader_array_push_ref((vader_array_t*) l4, l16);
        l6 = (l6 + INT64_C(1));
    }
    t1 = vader_emit_c$relay_runner_name(l0);
    l11 = vader_emit_c_ast$verbatim(t1);
    t2 = vader_emit_c_ast$verbatim(1279u);
    l12 = vader_emit_c_ast$address_of(t2);
    t2 = vader_emit_c_ast$verbatim(1278u);
    vader_array_t* _a37_arr = vader_array_new(486u, 3u, 13u, 2777u);
    ((void**) _a37_arr->buf->slots)[vader_array_offset(_a37_arr) + 2u] = l12.payload.obj;
    ((void**) _a37_arr->buf->slots)[vader_array_offset(_a37_arr) + 1u] = l11.payload.obj;
    ((void**) _a37_arr->buf->slots)[vader_array_offset(_a37_arr) + 0u] = t2.payload.obj;
    l3 = (void*) _a37_arr;
    l11 = vader_emit_c_ast$perform(3618u, l3);
    vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
    l11 = vader_emit_c_ast$verbatim(1281u);
    l11 = vader_emit_c$read_back(l0, l11);
    l3 = vader_emit_c$forwarded_result(l2, l1, l11);
    t5 = vader_core_bytecode$bc_single_result(l2);
    if (t5 != INT32_C(14)) {
        l11 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l3)->f_capture;
        vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
    }
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l17);
    l2 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l3)->f_settle;
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l2);
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l14);
    t3 = vader_array_length(((vader_array_t*) l5));
    if ((t3 > INT64_C(0))) {
        t2 = vader_emit_c_ast$verbatim(1282u);
        vader_array_t* _a38_arr = vader_array_new(486u, 1u, 13u, 2777u);
        ((void**) _a38_arr->buf->slots)[vader_array_offset(_a38_arr) + 0u] = t2.payload.obj;
        l2 = (void*) _a38_arr;
        l11 = vader_emit_c_ast$perform(1175u, l2);
        vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
    }
    vader_array_t* _a39_arr = vader_array_new(266u, 0u, 13u, 1566u);
    l2 = (void*) _a39_arr;
    l11 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l3)->f_returned;
    vader_struct_vader_emit_c_ast$CReturn_t* _a40_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a40_obj, 1604u);
    _a40_obj->f_stores = l2;
    _a40_obj->f_value = l11;
    _a40_obj->f_snapshot_type = 0u;
    _a40_obj->f_pops_frame = false;
    l2 = (void*) _a40_obj;
    vader_array_push_ref((vader_array_t*) l4, l2);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$val_of(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 1562u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackTemporary_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 1559u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_val;
    } else if (l0.tag == 1560u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_val;
    } else {
        if (!(l0.tag == 1558u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackExpr_t*) t0)->f_val;
    }
    return l1;
}

static uint8_t vader_emit_c$val_type_of_bc_type(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 1283u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 1286u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1273u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1276u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1287u) {
        l1 = (uint8_t) 17;
    } else {
        if (!(l0.tag == 1282u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 17;
    }
    return l1;
}

static uint8_t vader_emit_c$val_type_of_field(void* l0, int32_t l1) {
    vader_box_t t0;
    uint8_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    t1 = vader_emit_c$val_type_of_bc_type(t0);
    return t1;
}

static void* vader_emit_c$value_parameters(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    int64_t l3, l4, l7, l9;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &l11 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(272u, 0u, 13u, 1599u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l3, 628u);
        if (((int32_t) t0.payload.i) == INT32_C(14)) {
            l3 = (l3 + INT64_C(1));
            continue;
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l3, 628u);
        l5 = vader_emit_c$c_type_for_val_bare(((uint8_t) t0.payload.i));
        l6 = l1;
        l7 = vader_host_std_core$Intrinsic$byte_len(l6);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(20) + l7));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l8, l9, l6);
        l9 = std_core$write_int(l8, l9, l3);
        l10 = std_core$finish_buffer(l8, l9);
        vader_struct_vader_emit_c_ast$CParameter_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a3_obj, 1599u);
        _a3_obj->f_type = l5;
        _a3_obj->f_name = l10;
        l11 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l2, l11);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$void_box(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(42));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 3559u);
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_void_tag;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 3426u);
    t1 = std_core$finish_buffer(l1, l2);
    t2 = vader_emit_c_ast$verbatim(t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$vtable_sig_for_row(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int32_t l3, l11;
    uint8_t l4;
    bool l5, l13;
    int64_t l7, l8;
    void* t0 = NULL;
    uint8_t t1;
    int32_t t2;
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l9, &l10, &l12, &l14, &l15, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VtableRow_t*) l1)->f_entries);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
    l3 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) t0)->f_fn_index;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature;
    l4 = vader_core_bytecode$bc_single_result(l2);
    l3 = vader_core_bytecode$bc_single_result_type(l2);
    l5 = true;
    l6 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l1)->f_entries;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l8);
        l10 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
        l11 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l9)->f_fn_index;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l11);
        t1 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_signature);
        if (t1 != l4) {
            l13 = true;
        } else {
            t2 = vader_core_bytecode$bc_single_result_type(((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_signature);
            l13 = t2 != l3;
        }
        if (l13) {
            l5 = false;
        }
        l8 = (l8 + INT64_C(1));
    }
    if (!(l5)) {
        l6 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params;
        vader_array_t* _a4_arr = vader_array_new(31u, 1u, 1u, 628u);
        ((uint8_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (uint8_t) INT32_C(17);
        l9 = (void*) _a4_arr;
        l10 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types;
        vader_array_t* _a5_arr = vader_array_new(29u, 1u, 7u, 626u);
        ((int32_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (int32_t) l3;
        l12 = (void*) _a5_arr;
        l14 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_names;
        vader_array_t* _a6_arr = vader_array_new(26u, 0u, 12u, 621u);
        l15 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(26u, 0u, 12u, 621u);
        l16 = (void*) _a7_arr;
        vader_struct_vader_core_bytecode$BcSignature_t* _a8_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
        vader_obj_header_init(_a8_obj, 1284u);
        _a8_obj->f_params = l6;
        _a8_obj->f_results = l9;
        _a8_obj->f_param_types = l10;
        _a8_obj->f_result_types = l12;
        _a8_obj->f_param_names = l14;
        _a8_obj->f_param_c_out = l15;
        _a8_obj->f_param_by_address = l16;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$wrapper_storage(bool l0) {
    if (l0) {
        return (uint8_t) 1;
    }
    return (uint8_t) 0;
}

static void vader_emit_c$write_barrier(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(1189u, l2);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$write_barrier_for(void* l0, vader_box_t l1, vader_box_t l2) {
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$may_hold_reference(l2);
    if (t0) {
        vader_emit_c$write_barrier(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$zero_of(uint8_t l0) {
    bool l1;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(17)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (!(l1)) {
        t0 = (void*) &vader_data_69;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_69;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(486u, 1u, 13u, 2777u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
    t0 = (void*) _a2_arr;
    t1 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
