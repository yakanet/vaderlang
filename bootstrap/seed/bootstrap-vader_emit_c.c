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
static vader_box_t vader_emit_c$expression_of(vader_box_t l0);
static vader_string_t vader_emit_c$extern_c_type(uint8_t l0);
static vader_box_t vader_emit_c$extern_decl(void* l0, void* l1);
static vader_string_t vader_emit_c$extern_parameter_type(void* l0, void* l1, int64_t l2);
static vader_string_t vader_emit_c$extern_result_type(void* l0, void* l1);
static vader_box_t vader_emit_c$external(vader_string_t l0, vader_string_t l1, vader_box_t l2, bool l3);
static vader_string_t vader_emit_c$field_c_name(vader_string_t l0);
static vader_box_t vader_emit_c$field_of(vader_string_t l0, vader_box_t l1, vader_string_t l2);
static bool vader_emit_c$fields_are_layout_siblings(void* l0, void* l1, void* l2);
static int32_t vader_emit_c$find_main(void* l0, vader_string_t l1);
static vader_box_t vader_emit_c$find_vtable_row(void* l0, vader_string_t l1);
static vader_string_t vader_emit_c$float_lit(double l0);
static vader_box_t vader_emit_c$float_tag_check_expr(void* l0, vader_box_t l1);
static bool vader_emit_c$fn_builds_stack_object(void* l0);
static vader_string_t vader_emit_c$fn_symbol_name(void* l0, int32_t l1);
static vader_box_t vader_emit_c$foreign_depth(uint8_t l0);
static vader_string_t vader_emit_c$foreign_unit_banner(void* l0);
static void* vader_emit_c$foreign_units(void* l0);
static void* vader_emit_c$forward_boxed(vader_string_t l0, void* l1, void* l2);
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
static void* vader_emit_c$precompute_branch_targets(void* l0, void* l1);
static void* vader_emit_c$precompute_scopes(void* l0);
static int32_t vader_emit_c$present_tag(void* l0, uint8_t l1);
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
static uint8_t vader_emit_c$slot_val_type(void* l0, int32_t l1);
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
    l1 = vader_emit_c_ast$cast(2633u, l0);
    t0 = vader_emit_c_ast$cast(2617u, l1);
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
    l2 = std_core$write_string_at(l1, l2, 1722u);
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
    if (!(l2.tag == 1176u)) {
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
    vader_obj_header_init(_a0_obj, 1445u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$array_pointer(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_emit_c_ast$cast(3383u, l0);
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
        if (l4.tag == 1176u) {
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
    if (!(l0 == 2193u)) {
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
    t0 = vader_emit_c_ast$cast(2617u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$as_size(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    t0 = vader_emit_c_ast$cast(3038u, l1);
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
    l4 = std_core$write_string_at(l6, l4, 2083u);
    l4 = std_core$write_string_at(l6, l4, l2);
    l4 = std_core$write_string_at(l6, l4, 174u);
    l4 = std_core$write_string_at(l6, l4, l3);
    l4 = std_core$write_string_at(l6, l4, 1264u);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack));
    l4 = std_core$write_int(l6, l4, l5);
    l4 = std_core$write_string_at(l6, l4, 405u);
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
    vader_obj_header_init(_a0_obj, 1411u);
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
    vader_obj_header_init(_a0_obj, 1424u);
    _a0_obj->f_name = 1138u;
    _a0_obj->f_value = l1;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$atom_for(void* l0, vader_string_t l1) {
    vader_box_t l2;
    int32_t t0;
    l2 = std_collections$Map$std_core$Index$at__string__i32(l0, l1);
    if (!(l2.tag == 579u)) {
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
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
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(576u, l5));
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
    l4 = std_core$write_string_at(l5, l4, 1238u);
    l6 = ((int64_t) (int32_t) l3);
    l4 = std_core$write_int(l5, l4, l6);
    l4 = std_core$write_string_at(l5, l4, 1200u);
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
    if (!(l1.tag == 1191u)) {
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
        vader_array_t* _a0_arr = vader_array_new(101u, 0u, 13u, 1178u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    if (!(l5.tag == 1189u)) {
        vader_array_t* _a2_arr = vader_array_new(101u, 0u, 13u, 1178u);
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
    if (!(l5.tag == 1189u)) {
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
        vader_obj_header_init(_a0_obj, 1445u);
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
    l6 = vader_emit_c$aux(l0, 3045u);
    vader_emit_c$declare(l0, 3383u, l6, l1);
    t2 = vader_emit_c_ast$verbatim(l6);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t2.payload.obj;
    l2 = (void*) _a1_arr;
    vader_emit_c$statement_macro(l0, 1134u, l2);
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays;
    vader_struct_vader_emit_c$BoundArray_t* _a2_obj = (vader_struct_vader_emit_c$BoundArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$BoundArray_t));
    vader_obj_header_init(_a2_obj, 1390u);
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
    l3 = concat_2(3390u, l0);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l5 = INT64_C(0);
    l6 = ((int64_t) (int32_t) l1);
    l5 = std_core$write_int(l4, l5, l6);
    l5 = std_core$write_string_at(l4, l5, 3263u);
    t0 = std_core$finish_buffer(l4, l5);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
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
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l3, &l6 };
    void** gc_raw_roots[2] = { &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
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
        l3 = vader_emit_c$box_call(2521u, l2, l0);
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
        vader_array_t* _a0_arr = vader_array_new(26u, 2u, 0u, 576u);
        vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(576u, 3291u);
        vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, 2616u);
        t0 = (void*) _a0_arr;
        vader_struct_vader_emit_c_ast$CCast_t* _a1_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
        vader_obj_header_init(_a1_obj, 1417u);
        _a1_obj->f_types = t0;
        _a1_obj->f_value = l0;
        l5 = (void*) _a1_obj;
        l3 = vader_emit_c$box_call(2521u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(3)) {
        l3 = vader_emit_c$box_call(2543u, l2, l0);
    } else if (l1 == INT32_C(7)) {
        vader_array_t* _a2_arr = vader_array_new(26u, 2u, 0u, 576u);
        vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 1u] = vader_box_string(576u, 3292u);
        vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_box_string(576u, 2617u);
        t0 = (void*) _a2_arr;
        vader_struct_vader_emit_c_ast$CCast_t* _a3_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
        vader_obj_header_init(_a3_obj, 1417u);
        _a3_obj->f_types = t0;
        _a3_obj->f_value = l0;
        l5 = (void*) _a3_obj;
        l3 = vader_emit_c$box_call(2543u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(8)) {
        l6 = vader_emit_c_ast$cast(2257u, l0);
        l3 = vader_emit_c$box_call(2379u, l2, l6);
    } else if (l1 == INT32_C(9)) {
        l3 = vader_emit_c$box_call(2379u, l2, l0);
    } else if (l1 == INT32_C(10)) {
        l3 = vader_emit_c$box_call(2002u, l2, l0);
    } else if (l1 == INT32_C(11)) {
        l6 = vader_emit_c_ast$cast(2616u, l0);
        l3 = vader_emit_c$box_call(2521u, l2, l6);
    } else if (l1 == INT32_C(12)) {
        l3 = vader_emit_c$box_call(3087u, l2, l0);
    } else {
        if (l1 == INT32_C(13)) {
            l4 = true;
        } else {
            l4 = l1 == INT32_C(17);
        }
        if (l4) {
            l3 = l0;
        } else if (l1 == INT32_C(14)) {
            vader_array_t* _a4_arr = vader_array_new(451u, 0u, 13u, 2544u);
            l5 = (void*) _a4_arr;
            l3 = vader_emit_c_ast$call(3392u, l5);
        } else if (l1 == INT32_C(15)) {
            l6 = vader_emit_c_ast$cast(2633u, l0);
            l6 = vader_emit_c_ast$cast(2617u, l6);
            l3 = vader_emit_c$box_call(2543u, l2, l6);
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
    t0 = concat_2(l0, 464u);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$call(3349u, l2);
    vader_struct_vader_emit_c_ast$CIndex_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a1_obj, 1436u);
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
    if (l2.tag == 1193u) {
        l6 = vader_emit_c$class_tag_of(l5, (uint8_t) 12);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        l8 = vader_emit_c$atom_for(l4, l7);
        t1 = vader_emit_c$boxed_string(l6, l8);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1192u)) {
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
    t0 = (void*) &vader_data_67;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_c_ast$cast(3524u, l1);
    t1 = vader_emit_c_ast$designated(499u, l4);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(451u, 3u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(245u, 1u, 13u, 1444u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0;
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1722u);
        l5 = std_core$write_int(l4, l5, l3);
        l6 = std_core$finish_buffer(l4, l5);
        vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a1_obj, 1444u);
        _a1_obj->f_type = 3395u;
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
        return 3358u;
    }
    return 3368u;
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
        l4 = vader_emit_c_ast$cast(2257u, l3);
        l4 = vader_emit_c_ast$designated(489u, l4);
    } else if (l1 == INT32_C(12)) {
        l4 = vader_emit_c_ast$designated(480u, l3);
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
            vader_array_t* _a0_arr = vader_array_new(26u, 3u, 0u, 576u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 2u] = vader_box_string(576u, 3291u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(576u, 2616u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, 2617u);
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
                vader_array_t* _a1_arr = vader_array_new(26u, 2u, 0u, 576u);
                vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 1u] = vader_box_string(576u, 2616u);
                vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 0u] = vader_box_string(576u, 2617u);
                t0 = (void*) _a1_arr;
                l4 = vader_emit_c$integer_payload(t0, l3);
            } else {
                if (l1 == INT32_C(8)) {
                    l5 = true;
                } else {
                    l5 = l1 == INT32_C(4);
                }
                if (l5) {
                    vader_array_t* _a2_arr = vader_array_new(26u, 1u, 0u, 576u);
                    vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_box_string(576u, 2617u);
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
                    t1 = concat_3(2079u, l6, 1258u);
                    vader_host_std_core$Intrinsic$panic(t1);
                    vader_unreachable("a no-return call returned");
                }
            }
        }
    }
    l3 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_67;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l4.payload.obj;
    t0 = (void*) _a4_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a5_arr = vader_array_new(451u, 3u, 13u, 2544u);
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
    t0 = (void*) &vader_data_67;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l1));
    t1 = vader_emit_c_ast$designated(503u, l4);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(451u, 3u, 13u, 2544u);
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
    t0 = vader_emit_c_ast$cast(3408u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 7u, 579u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__i32_t* _a3_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a3_obj, 901u);
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
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 581u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        if (l5.tag == 1189u) {
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
            vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
            ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t3.payload.obj;
            l12 = (void*) _a2_arr;
            l13 = vader_emit_c_ast$call(3039u, l12);
            if (l8) {
                t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l11)->f_size;
                l14 = vader_emit_c_ast$number(t2);
                l15 = vader_emit_c_ast$binary((uint8_t) 11, l14, l13);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l16 = concat_2(t1, 190u);
                l17 = vader_emit_c$static_assert(l15, l16);
                vader_array_push_ref((vader_array_t*) l2, l17.payload.obj);
            } else {
                t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l11)->f_size;
                l18 = vader_emit_c_ast$number(t2);
                l19 = vader_emit_c_ast$binary((uint8_t) 8, l18, l13);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l20 = concat_2(t1, 243u);
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
                l25 = concat_2(t1, 152u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
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
                t1 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l9, 581u);
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
        l1 = 3293u;
        return l1;
    }
    if (l0 == INT32_C(2)) {
        l1 = 3290u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3291u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3292u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2618u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2615u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2616u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2617u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2432u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2257u;
    } else if (l0 == INT32_C(11)) {
        l1 = 3291u;
    } else if (l0 == INT32_C(12)) {
        l1 = 3293u;
    } else if (l0 == INT32_C(13)) {
        l1 = 3524u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3395u;
    }
    return l1;
}

static vader_string_t vader_emit_c$c_type_for_val_bare(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2618u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2615u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2616u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2617u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3293u;
    } else if (l0 == INT32_C(5)) {
        l1 = 3290u;
    } else if (l0 == INT32_C(6)) {
        l1 = 3291u;
    } else if (l0 == INT32_C(7)) {
        l1 = 3292u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2432u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2257u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2002u;
    } else if (l0 == INT32_C(11)) {
        l1 = 3291u;
    } else if (l0 == INT32_C(12)) {
        l1 = 3482u;
    } else if (l0 == INT32_C(13)) {
        l1 = 3395u;
    } else if (l0 == INT32_C(14)) {
        l1 = 3523u;
    } else if (l0 == INT32_C(15)) {
        l1 = 3524u;
    } else if (l0 == INT32_C(16)) {
        l1 = 3524u;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3395u;
    }
    return l1;
}

static int32_t vader_emit_c$callee_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 1211u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 1240u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        return t1;
    }
    if (!(l0.tag == 1239u)) {
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
    if (l1.tag == 1211u) {
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
    if (!(l1.tag == 1212u)) {
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
        if (l4.tag == 1186u) {
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
    if (!(l3.tag == 1186u)) {
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
        if (l4.tag == 1186u) {
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
            if (l4.tag == 1186u) {
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
        l12 = concat_5(2885u, l3, 423u, l11, 377u);
        if (l10.tag == 1186u) {
            t2 = l10.payload.obj;
            t3 = vader_core_bytecode$is_string_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t2)->f_val);
            if (t3) {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_str_offsets, vader_box_string(576u, l12));
            }
        } else {
            t4 = vader_emit_c$val_type_of_bc_type(l10);
            if (t4 == INT32_C(16)) {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_ref_offsets, vader_box_string(576u, l12));
            } else {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_ptr_offsets, vader_box_string(576u, l12));
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
    if (l4.tag == 1434u) {
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
        t0 = vader_emit_c$payload(l1, 2880u);
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
        vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 579u);
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
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 579u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 579u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__i32_t* _a5_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a5_obj, 901u);
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
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 579u);
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
    vader_obj_header_init(_a0_obj, 633u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(24u, (int64_t) t0, 12u, 574u);
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
    vader_array_t* _a3_arr = vader_array_reserve(3u, (int64_t) t0, 13u, 27u);
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
    vader_obj_header_init(_a5_obj, 1916u);
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
    if (l1.tag == 1248u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l3 = ((int64_t) (int32_t) t1);
        vader_struct_vader_emit_c_ast$CIntegerLiteral_t* _a0_obj = (vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIntegerLiteral_t));
        vader_obj_header_init(_a0_obj, 1438u);
        _a0_obj->f_class = (uint8_t) 2;
        _a0_obj->f_value = l3;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1268u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        vader_struct_vader_emit_c_ast$CIntegerLiteral_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIntegerLiteral_t));
        vader_obj_header_init(_a1_obj, 1438u);
        _a1_obj->f_class = (uint8_t) 3;
        _a1_obj->f_value = l3;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l1.tag == 1227u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        t3 = vader_emit_c$float_lit(t2);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else if (l1.tag == 1199u) {
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        if (t4) {
            l4 = 3223u;
        } else {
            l4 = 2396u;
        }
        l2 = vader_emit_c_ast$verbatim(l4);
    } else if (l1.tag == 1214u) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t6 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        l6 = (uint64_t) (int64_t) t6;
        l3 = std_core$write_unsigned(l5, l3, l6);
        l3 = std_core$write_string_at(l5, l3, 3263u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else if (l1.tag == 1300u) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(42));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l5, l3, 3394u);
        t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_null_tag;
        l7 = ((int64_t) (int32_t) t1);
        l3 = std_core$write_int(l5, l3, l7);
        l3 = std_core$write_string_at(l5, l3, 3266u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else {
        if (!(l1.tag == 1316u)) {
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
        l3 = std_core$write_string_at(l5, l3, 3263u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$const_val(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 1248u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 1268u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 1227u) {
        l1 = (uint8_t) 9;
    } else if (l0.tag == 1199u) {
        l1 = (uint8_t) 10;
    } else if (l0.tag == 1214u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 1300u) {
        l1 = (uint8_t) 17;
    } else {
        if (!(l0.tag == 1316u)) {
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
    if (!(l3.tag == 1434u)) {
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
        vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
        l4 = (void*) _a0_arr;
        l6 = vader_emit_c_ast$call(1128u, l4);
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
    l7 = vader_emit_c$aux(l0, 1926u);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l2);
    l8 = std_core$write_int(l4, l8, l9);
    l8 = std_core$write_string_at(l4, l8, 3263u);
    t2 = std_core$finish_buffer(l4, l8);
    l10 = vader_emit_c_ast$verbatim(t2);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l6);
    l8 = std_core$write_int(l4, l8, l9);
    l8 = std_core$write_string_at(l4, l8, 3263u);
    t2 = std_core$finish_buffer(l4, l8);
    l11 = vader_emit_c_ast$verbatim(t2);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l5);
    l8 = std_core$write_int(l4, l8, l9);
    l8 = std_core$write_string_at(l4, l8, 3263u);
    t2 = std_core$finish_buffer(l4, l8);
    l12 = vader_emit_c_ast$verbatim(t2);
    vader_array_t* _a1_arr = vader_array_new(451u, 4u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 3u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = l11.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l3.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l10.payload.obj;
    l4 = (void*) _a1_arr;
    l10 = vader_emit_c_ast$call(l1, l4);
    vader_emit_c$declare(l0, 3383u, l7, l10);
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
        vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a0_arr;
        l1 = vader_emit_c_ast$returning(3417u, l2);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        l3 = true;
    } else {
        l3 = l0 == INT32_C(13);
    }
    if (l3) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a1_arr;
        l1 = vader_emit_c_ast$returning(3416u, l2);
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
            vader_array_t* _a2_arr = vader_array_new(239u, 0u, 13u, 1411u);
            l2 = (void*) _a2_arr;
            l4 = vader_emit_c$argument(INT64_C(0));
            vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a3_obj, 1449u);
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
            vader_array_t* _a4_arr = vader_array_new(239u, 0u, 13u, 1411u);
            l2 = (void*) _a4_arr;
            l4 = vader_emit_c$argument(INT64_C(0));
            vader_struct_vader_emit_c_ast$CReturn_t* _a5_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a5_obj, 1449u);
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
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 579u);
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
            if (l5.tag == 1211u) {
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
    vader_obj_header_init(_a0_obj, 1426u);
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
    vader_obj_header_init(_a0_obj, 1444u);
    _a0_obj->f_type = 3395u;
    _a0_obj->f_name = 2968u;
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
    vader_obj_header_init(_a0_obj, 1453u);
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
            l3 = 2253u;
        } else {
            l3 = 2801u;
        }
        l4 = vader_core_bytecode$val_type_name(l1);
        t0 = concat_4(3348u, l3, 1200u, l4);
        { vader_box_t __vret = vader_box_string(576u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(235u, 0u, 13u, 1390u);
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
    if (!(l1.tag == 1192u)) {
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
    vader_array_t* _a0_arr = vader_array_reserve(451u, (int64_t) t0, 13u, 2544u);
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
        l12 = std_core$write_string_at(l11, l12, 1242u);
        l12 = std_core$write_int(l11, l12, l6);
        l13 = std_core$finish_buffer(l11, l12);
        l14 = vader_emit_c$box_slot_1(l0, l1, l8, l13, l4);
        vader_array_push_ref((vader_array_t*) l5, l14.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    vader_emit_c$push_pool_array(l1, l2, 3395u, (uint8_t) 0, l5);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3352u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 5u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3353u, l6);
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
                l12 = 3373u;
            } else {
                l12 = 3372u;
            }
            t1 = concat_2(l10, 464u);
            l3 = vader_emit_c_ast$verbatim(t1);
            l6 = vader_emit_c$slot_index(l10, l2);
            vader_array_t* _a1_arr = vader_array_new(451u, 2u, 13u, 2544u);
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
        l14 = std_core$write_string_at(l13, l14, 3263u);
        t1 = std_core$finish_buffer(l13, l14);
        l16 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a2_arr = vader_array_new(451u, 3u, 13u, 2544u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = l16.payload.obj;
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l6.payload.obj;
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3.payload.obj;
        l13 = (void*) _a2_arr;
        l3 = vader_emit_c_ast$call(3371u, l13);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3355u, l1);
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
    l6 = std_core$write_string_at(l2, l6, 3263u);
    t1 = std_core$finish_buffer(l2, l6);
    l8 = vader_emit_c_ast$verbatim(t1);
    l9 = vader_emit_c$declare_array(l0, 3356u, l5, l8);
    l8 = vader_emit_c$typed_array_fill_for(l4);
    l5 = INT32_C(0);
    while ((l5 < l3)) {
        l10 = vader_emit_c$pop(l0);
        t2 = vader_chk_sub(i32, l3, INT32_C(1));
        l11 = vader_chk_sub(i32, t2, l5);
        if (l8.tag == 0u) {
            if (l4 == INT32_C(13)) {
                l19 = vader_emit_c$fresh_slot(l9, l11);
                l20 = vader_emit_c$typed_slot(3524u, l9, l19);
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
        vader_array_t* _a1_arr = vader_array_new(451u, 2u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3359u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3377u, l1);
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
    l3 = vader_emit_c$aux(l0, 1926u);
    t0 = vader_emit_c$object_pointer_of(l2);
    l2 = vader_emit_c$array_pointer(t0);
    l1 = vader_emit_c$as_count(l1);
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3378u, l4);
    vader_emit_c$declare(l0, 3383u, l3, l1);
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
    t0 = vader_emit_c$declare_array(l0, 3379u, l3, l2);
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
            if (l7.tag == 1185u) {
                t2 = concat_2(l10, 464u);
                l4 = vader_emit_c_ast$verbatim(t2);
                l7 = vader_emit_c$slot_index(l10, l3);
                l11 = vader_emit_c$coerced_as(l0, l2, (uint8_t) 17);
                vader_array_t* _a1_arr = vader_array_new(451u, 3u, 13u, 2544u);
                ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = l11.payload.obj;
                ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l7.payload.obj;
                ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l4.payload.obj;
                l5 = (void*) _a1_arr;
                l4 = vader_emit_c_ast$call(3376u, l5);
                vader_emit_c$evaluate(l0, l4);
            } else {
                t2 = concat_2(l10, 464u);
                l4 = vader_emit_c_ast$verbatim(t2);
                l7 = vader_emit_c$slot_index(l10, l3);
                l11 = vader_emit_c$object_pointer_of(l2);
                vader_array_t* _a2_arr = vader_array_new(451u, 3u, 13u, 2544u);
                ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = l11.payload.obj;
                ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l7.payload.obj;
                ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l4.payload.obj;
                l5 = (void*) _a2_arr;
                l4 = vader_emit_c_ast$call(3375u, l5);
                vader_emit_c$evaluate(l0, l4);
            }
            t2 = concat_2(l10, 464u);
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
        t2 = concat_2(l10, 464u);
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
    l5 = vader_emit_c$aux(l0, 1926u);
    t0 = vader_emit_c$object_pointer_of(l4);
    l4 = vader_emit_c$array_pointer(t0);
    l3 = vader_emit_c$as_count(l3);
    l2 = vader_emit_c$as_count(l2);
    vader_array_t* _a0_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l4.payload.obj;
    l6 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3381u, l6);
    vader_emit_c$declare(l0, 3383u, l5, l2);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, 700u);
    l2 = (void*) _a0_arr;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    if (t0 == INT64_C(0)) {
        t1 = (void*) &vader_data_67;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_67;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_67;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l5 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_67;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_67;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
        l8 = vader_emit_c_ast$verbatim(305u);
        vader_array_t* _a6_arr = vader_array_new(451u, 6u, 13u, 2544u);
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
        vader_array_t* _a7_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l8.payload.obj;
        t1 = (void*) _a7_arr;
        l8 = vader_emit_c_ast$initializer_list(t1);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a8_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a8_obj, 1423u);
        _a8_obj->f_name = 3385u;
        _a8_obj->f_length = vader_box_i32(579u, INT32_C(1));
        _a8_obj->f_value = l8;
        l3 = (void*) _a8_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a9_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a9_obj, 1432u);
        _a9_obj->f_storage = l9;
        _a9_obj->f_constant = true;
        _a9_obj->f_type = 3386u;
        _a9_obj->f_declarator = l3;
        l3 = (void*) _a9_obj;
        l8 = vader_emit_c$atom_count_define(l0);
        vader_array_t* _a10_arr = vader_array_new(453u, 2u, 13u, 2553u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 1u] = l8.payload.obj;
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_struct_vader_emit_c_ast$CSection_t* _a11_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
        vader_obj_header_init(_a11_obj, 1451u);
        _a11_obj->f_comment = l2;
        _a11_obj->f_items = l3;
        l3 = (void*) _a11_obj;
        vader_emit_c_ast$print_section(l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l9 = vader_emit_c$global_storage(t2);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    vader_array_t* _a12_arr = vader_array_reserve(26u, (int64_t) t0, 0u, 576u);
    l3 = (void*) _a12_arr;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table));
    vader_array_t* _a13_arr = vader_array_reserve(451u, (int64_t) t0, 13u, 2544u);
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
        l15 = concat_2(t4, 59u);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(576u, l15));
        l8 = vader_emit_c_ast$verbatim(3384u);
        l16 = vader_emit_c_ast$number(l10);
        vader_struct_vader_emit_c_ast$CIndex_t* _a15_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
        vader_obj_header_init(_a15_obj, 1436u);
        _a15_obj->f_base = l8;
        _a15_obj->f_index = l16;
        l6 = (void*) _a15_obj;
        t1 = (void*) &vader_data_67;
        vader_array_t* _a16_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        l7 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_67;
        vader_array_t* _a17_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        l17 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) INT64_C(0));
        l18 = vader_emit_c_ast$unsigned(l14);
        l19 = vader_emit_c_ast$verbatim(1136u);
        t1 = (void*) &vader_data_67;
        vader_array_t* _a18_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l20 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) INT64_C(0));
        l21 = vader_emit_c_ast$address_of(vader_ref_box(l6));
        vader_array_t* _a19_arr = vader_array_new(451u, 6u, 13u, 2544u);
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
    t1 = (void*) &vader_data_66;
    vader_array_t* _a20_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
    l5 = vader_array_ref_load_obj(_a20_slotarr->buf, vader_array_offset(_a20_slotarr) + (size_t) INT64_C(0));
    vader_struct_vader_emit_c_ast$CStringLiterals_t* _a21_obj = (vader_struct_vader_emit_c_ast$CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStringLiterals_t));
    vader_obj_header_init(_a21_obj, 1455u);
    _a21_obj->f_literals = l3;
    l3 = (void*) _a21_obj;
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a22_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a22_obj, 1423u);
    _a22_obj->f_name = 3384u;
    _a22_obj->f_length = vader_ref_box(l5);
    _a22_obj->f_value = vader_ref_box(l3);
    l3 = (void*) _a22_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a23_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a23_obj, 1432u);
    _a23_obj->f_storage = l9;
    _a23_obj->f_constant = true;
    _a23_obj->f_type = 2139u;
    _a23_obj->f_declarator = l3;
    l3 = (void*) _a23_obj;
    t1 = (void*) &vader_data_66;
    vader_array_t* _a24_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
    l5 = vader_array_ref_load_obj(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) INT64_C(0));
    l8 = vader_emit_c_ast$initializer_list(l4);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a25_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a25_obj, 1423u);
    _a25_obj->f_name = 3385u;
    _a25_obj->f_length = vader_ref_box(l5);
    _a25_obj->f_value = l8;
    l4 = (void*) _a25_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a26_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a26_obj, 1432u);
    _a26_obj->f_storage = l9;
    _a26_obj->f_constant = true;
    _a26_obj->f_type = 3386u;
    _a26_obj->f_declarator = l4;
    l4 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(453u, 1u, 13u, 2553u);
    ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = l3;
    l3 = (void*) _a27_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a28_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a28_obj, 1451u);
    _a28_obj->f_comment = l2;
    _a28_obj->f_items = l3;
    l2 = (void*) _a28_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a29_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(453u, 1u, 13u, 2553u);
    ((void**) _a30_arr->buf->slots)[vader_array_offset(_a30_arr) + 0u] = l4;
    l3 = (void*) _a30_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a31_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a31_obj, 1451u);
    _a31_obj->f_comment = l2;
    _a31_obj->f_items = l3;
    l2 = (void*) _a31_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a32_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a32_arr;
    t3 = vader_emit_c$atom_count_define(l0);
    vader_array_t* _a33_arr = vader_array_new(453u, 1u, 13u, 2553u);
    ((void**) _a33_arr->buf->slots)[vader_array_offset(_a33_arr) + 0u] = t3.payload.obj;
    l3 = (void*) _a33_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a34_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a34_obj, 1451u);
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
    l1 = vader_emit_c_ast$around(361u, l1, 397u);
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
    l1 = vader_emit_c_ast$around(362u, l1, 396u);
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
        if (!(l1.tag == 1185u)) {
            l5 = vader_emit_c$object_pointer_of(l3);
            vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l5.payload.obj;
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
            l4 = (void*) _a0_arr;
            l5 = vader_emit_c_ast$call(3367u, l4);
            vader_emit_c$evaluate(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l6 = vader_emit_c$boxed_push_helper(l3);
    l5 = vader_emit_c$coerced_as(l0, l3, (uint8_t) 17);
    vader_array_t* _a1_arr = vader_array_new(451u, 2u, 13u, 2544u);
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
    if (!(l4.tag == 1401u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(91));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2287u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 70u);
        l10 = ((int64_t) (int32_t) l3);
        l7 = std_core$write_int(l6, l7, l10);
        l7 = std_core$write_string_at(l6, l7, 377u);
        t0 = std_core$finish_buffer(l6, l7);
        std_abort$todo(t0);
        vader_unreachable("a no-return call returned");
    }
    t1 = l4.payload.obj;
    t2 = vader_emit_c$is_continue_branch(t1, l3);
    if (t2) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(25));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2736u);
        t1 = l4.payload.obj;
        t3 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t1)->f_opener_pc;
        l8 = ((int64_t) (int32_t) t3);
        l7 = std_core$write_int(l6, l7, l8);
        l5 = std_core$finish_buffer(l6, l7);
    } else {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(24));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2296u);
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
        l7 = std_core$write_string_at(l6, l7, 2015u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 377u);
        l9 = std_core$finish_buffer(l6, l7);
        vader_emit_c$assert_stack_empty(l0, l9);
        l4 = vader_emit_c$expression_of(l4);
        vader_struct_vader_emit_c_ast$CGoto_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGoto_t));
        vader_obj_header_init(_a1_obj, 1433u);
        _a1_obj->f_label = l5;
        _a1_obj->f_condition = l4;
        l6 = (void*) _a1_obj;
        vader_emit_c$append_statement(l0, vader_ref_box(l6));
    } else {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(28));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2013u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 377u);
        l9 = std_core$finish_buffer(l6, l7);
        vader_emit_c$assert_stack_empty(l0, l9);
        vader_struct_vader_emit_c_ast$CGoto_t* _a2_obj = (vader_struct_vader_emit_c_ast$CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGoto_t));
        vader_obj_header_init(_a2_obj, 1433u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3403u, l1);
    l2 = vader_emit_c_ast$cast(3524u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 3u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3397u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3409u, l4);
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
    vader_obj_header_init(_a0_obj, 1392u);
    _a0_obj->f_entry_mangled = l5;
    _a0_obj->f_split = true;
    _a0_obj->f_atom_universe = l6;
    _a0_obj->f_verify_bounds = l7;
    _a0_obj->f_library_units = true;
    l4 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_entry_mangled;
    l6 = vader_emit_c$internal_fn_flags(l0, l3, l5);
    l4 = vader_emit_c$new_ctx(l0, l4, l6);
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 1010u);
    _a2_obj->f_parts = t0;
    t0 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a3_obj, 1447u);
    _a3_obj->f_out = t0;
    _a3_obj->f_started = false;
    l6 = (void*) _a3_obj;
    vader_emit_c$emit_preamble(l6, 743u);
    vader_emit_c$emit_struct_typedefs(l4, l6);
    vader_emit_c$emit_fn_sig_typedefs(l4, l6);
    vader_emit_c$emit_forward_decls(l4, l6);
    vader_emit_c$emit_closure_forward_decls(l4, l6);
    vader_emit_c$emit_vtable_forward_decls(l4, l6);
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a4_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a5_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a5_obj, 1010u);
    _a5_obj->f_parts = t0;
    t0 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a6_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a6_obj, 1447u);
    _a6_obj->f_out = t0;
    _a6_obj->f_started = false;
    l8 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_box_string(576u, 742u);
    l9 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CInclude_t* _a8_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a8_obj, 1435u);
    _a8_obj->f_path = 3342u;
    _a8_obj->f_system = false;
    t0 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(453u, 1u, 13u, 2553u);
    ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0;
    l10 = (void*) _a9_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a10_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a10_obj, 1451u);
    _a10_obj->f_comment = l9;
    _a10_obj->f_items = l10;
    l9 = (void*) _a10_obj;
    vader_emit_c_ast$print_section(l8, l9);
    vader_emit_c$emit_import_shims(l4, l8);
    t1 = vader_emit_c$imports_header_name(l2);
    vader_struct_vader_emit_c_ast$CInclude_t* _a11_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a11_obj, 1435u);
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
    vader_array_t* _a12_arr = vader_array_reserve(26u, (int64_t) t2, 0u, 576u);
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
        vader_array_push_scalar((vader_array_t*) l12, vader_box_string(576u, l23));
        l13 = (l13 + INT64_C(1));
    }
    vader_emit_c$push_foreign_units(l4, l10, l12);
    l5 = vader_emit_c_ast$printed_text(l6);
    l23 = vader_emit_c_ast$printed_text(l8);
    l24 = vader_emit_c_ast$printed_text(l9);
    vader_struct_vader_emit_c$CProgram_t* _a17_obj = (vader_struct_vader_emit_c$CProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$CProgram_t));
    vader_obj_header_init(_a17_obj, 1393u);
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
    if (!(l4.tag == 1179u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(49));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l6, l9, 2097u);
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
    l6 = vader_emit_c$pop_args_boxed(l0, l3);
    l7 = vader_emit_c$aux(l0, 2443u);
    l5 = vader_emit_c$object_pointer_of(l5);
    l5 = vader_emit_c_ast$cast(3431u, l5);
    vader_emit_c$declare(l0, 3431u, l7, l5);
    t1 = concat_2(l7, 468u);
    t4 = vader_emit_c_ast$verbatim(t1);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t4.payload.obj;
    l8 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
    l9 = vader_host_std_core$Intrinsic$byte_len(l7);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(53) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l6, l9, 363u);
    l10 = ((int64_t) (int32_t) l3);
    l9 = std_core$write_int(l6, l9, l10);
    l9 = std_core$write_string_at(l6, l9, 1255u);
    l9 = std_core$write_string_at(l6, l9, l7);
    l9 = std_core$write_string_at(l6, l9, 467u);
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
    int32_t l3, l6, l8;
    void* l4 = NULL;
    int64_t l5;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null();
    uint8_t l9;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l7, &l10, &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    l3 = ((int32_t) (int64_t) t0);
    t1 = vader_emit_c_ast$verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l4 = (void*) _a0_arr;
    l5 = ((int64_t) (int32_t) l3);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l6 = INT32_C(0);
    while ((l6 < l3)) {
        l7 = vader_emit_c$pop(l0);
        t2 = vader_chk_sub(i32, l3, INT32_C(1));
        l8 = vader_chk_sub(i32, t2, l6);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        t1 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l8, 581u);
        l9 = ((uint8_t) t1.payload.i);
        l10 = vader_emit_c$coerced_as(l0, l7, l9);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        vader_array_ref_store(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l8, l10.payload.obj);
        VADER_WRITE_BARRIER(_a3_slotarr->buf);
        l6 = (l6 + INT32_C(1));
    }
    t0 = vader_core_bytecode$bc_result_arity(l2);
    if (!((t0 > INT64_C(1)))) {
        l7 = vader_emit_c_ast$call(l1, l4);
        l9 = vader_core_bytecode$bc_single_result(l2);
        vader_emit_c$emit_call_result(l0, l7, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$emit_multi_call(l0, l1, l4, l2);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l7 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) l1)->f_op);
    t0 = concat_2(3410u, l7);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l4.payload.obj;
    l5 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3411u, l5);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
            vader_obj_header_init(_a3_obj, 1448u);
            _a3_obj->f_signature = t2;
            l10 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l4, l10);
            l11 = concat_2(3429u, l8);
            l12 = vader_emit_c$external(3430u, l11, vader_box_obj(0u, NULL), false);
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
                vader_obj_header_init(_a7_obj, 1448u);
                _a7_obj->f_signature = t2;
                l10 = (void*) _a7_obj;
                vader_array_push_ref((vader_array_t*) l4, l10);
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(26u, 0u, 0u, 576u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a9_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a9_obj, 1451u);
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
        l6 = vader_emit_c_ast$verbatim(2317u);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0), 581u);
        l7 = ((uint8_t) t2.payload.i);
        t2 = vader_emit_c$coerce_expr(l5, l6, (uint8_t) 16, l7);
        vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t2.payload.obj;
        l5 = (void*) _a2_arr;
        l8 = vader_emit_c$lift_unbox_tail(((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l8);
        vader_array_t* _a3_arr = vader_array_new(452u, 0u, 13u, 2549u);
        t3 = (void*) _a3_arr;
        vader_struct_vader_emit_c_ast$CBlock_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
        vader_obj_header_init(_a4_obj, 1413u);
        _a4_obj->f_body = t3;
        l8 = (void*) _a4_obj;
        l9 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l8)->f_body;
        l5 = vader_emit_c$forward_boxed(l4, l5, l3);
        vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l5);
        l3 = vader_emit_c$lift_signature(l0, l4, l3);
        vader_array_t* _a5_arr = vader_array_new(452u, 0u, 13u, 2549u);
        l5 = (void*) _a5_arr;
        vader_struct_vader_emit_c_ast$CFunction_t* _a6_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
        vader_obj_header_init(_a6_obj, 1430u);
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
        vader_obj_header_init(_a0_obj, 1445u);
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
    l3 = std_core$write_string_at(l2, l3, 3415u);
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
    vader_array_t* _a0_arr = vader_array_reserve(453u, (int64_t) t0, 13u, 2553u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool));
    while ((l3 < l4)) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l5, l6, 3415u);
        l6 = std_core$write_int(l5, l6, l3);
        l7 = std_core$finish_buffer(l5, l6);
        l8 = vader_emit_c$external(3382u, l7, vader_box_obj(0u, NULL), true);
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
        l6 = std_core$write_string_at(l10, l6, 3441u);
        l6 = std_core$write_int(l10, l6, l3);
        l11 = std_core$finish_buffer(l10, l6);
        l8 = vader_emit_c$external(l7, l11, vader_box_obj(0u, NULL), false);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
        l3 = (l3 + INT64_C(1));
    }
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    if ((t0 > INT64_C(0))) {
        l8 = vader_emit_c$external(3437u, 3444u, vader_box_obj(0u, NULL), false);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
    }
    t2 = (void*) &vader_data_66;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    l8 = vader_emit_c$external(3386u, 3385u, vader_ref_box(l5), true);
    vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l2 = (void*) _a0_arr;
    l3 = vader_core_bytecode$data_pool_type_ids(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module);
    t1 = vader_emit_c$has_str_data(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool);
    if (t1) {
        l4 = vader_emit_c$build_string_atom_map(l0);
    } else {
        vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
        l6 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 579u);
        l7 = (void*) _a3_arr;
        vader_struct_std_collections$Map__string__i32_t* _a4_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
        vader_obj_header_init(_a4_obj, 901u);
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
        l11 = std_core$write_string_at(l5, l11, 3415u);
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
        vader_obj_header_init(_a7_obj, 1399u);
        _a7_obj->f_name = l12;
        _a7_obj->f_storage = l13;
        _a7_obj->f_type_id = l14;
        _a7_obj->f_element_tag = l16;
        l7 = (void*) _a7_obj;
        if (l10.tag == 1188u) {
            l17 = l10.payload.obj;
            vader_emit_c$emit_str_data_entry(l2, l7, l17, l4);
        } else if (l10.tag == 1184u) {
            l18 = l10.payload.obj;
            vader_emit_c$emit_prim_data_entry(l2, l7, l18);
        } else {
            if (!(l10.tag == 1175u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l19 = l10.payload.obj;
            vader_emit_c$emit_agg_data_entry(l0, l2, l7, l19, l4);
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_emit_c$emit_global_slots(l0, l2);
    vader_emit_c$emit_global_roots(l0, l2);
    vader_array_t* _a8_arr = vader_array_new(26u, 3u, 0u, 576u);
    vader_array_box_slots(_a8_arr->buf)[vader_array_offset(_a8_arr) + 2u] = vader_box_string(576u, 2979u);
    vader_array_box_slots(_a8_arr->buf)[vader_array_offset(_a8_arr) + 1u] = vader_box_string(576u, 875u);
    vader_array_box_slots(_a8_arr->buf)[vader_array_offset(_a8_arr) + 0u] = vader_box_string(576u, 701u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a9_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a9_obj, 1451u);
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
    if (l2.tag == 1192u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t1 = vader_emit_c$data_slot(l5, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1193u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        t2 = vader_emit_c$atom_for(l4, l7);
        t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1194u) {
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        l9 = vader_emit_c$type_id_for_struct_symbol(l8, l9);
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l9];
        l7 = t1.payload.s;
        l7 = concat_2(3100u, l7);
        t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l9));
        t3 = vader_emit_c$object_header(t1);
        vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t3.payload.obj;
        l8 = (void*) _a1_arr;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
        if (l10.tag == 1189u) {
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
                l18 = std_core$write_string_at(l17, l18, 1243u);
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
        vader_obj_header_init(_a5_obj, 1423u);
        _a5_obj->f_name = l3;
        _a5_obj->f_length = vader_box_obj(0u, NULL);
        _a5_obj->f_value = l10;
        l8 = (void*) _a5_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a6_obj, 1432u);
        _a6_obj->f_storage = l5;
        _a6_obj->f_constant = true;
        _a6_obj->f_type = l7;
        _a6_obj->f_declarator = l8;
        l8 = (void*) _a6_obj;
        vader_array_push_ref((vader_array_t*) l1, l8);
        l7 = concat_2(l7, 411u);
        t1 = vader_emit_c_ast$verbatim(l3);
        l10 = vader_emit_c_ast$address_of(t1);
        t1 = vader_emit_c_ast$cast(l7, l10);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1191u)) {
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
    l3 = std_core$write_string_at(l2, l3, 3263u);
    t1 = std_core$finish_buffer(l2, l3);
    t2 = vader_emit_c_ast$verbatim(t1);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t2.payload.obj;
    l2 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(3418u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3419u, l2);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_else(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_emit_c$assert_stack_empty(l0, 2274u);
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
    l3 = std_core$write_string_at(l2, l3, 3015u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 377u);
    l5 = std_core$finish_buffer(l2, l3);
    vader_emit_c$assert_stack_empty(l0, l5);
    l6 = vader_emit_c$scope_ending_at(((vader_struct_vader_emit_c$FnState_t*) l0)->f_scopes, l1);
    if (l6.tag == 0u) {
        l7 = (void*) vader_buffer_new((size_t) INT64_C(50));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l7, l3, 2288u);
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
            l3 = std_core$write_string_at(l7, l3, 2296u);
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
    l1 = vader_emit_c_ast$around(372u, l1, 297u);
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
    l1 = vader_emit_c_ast$around(373u, l1, 298u);
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
    l5 = vader_emit_c_ast$cast(3524u, l5);
    vader_emit_c$assign(l0, vader_ref_box(l2), l5);
    vader_array_t* _a0_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l3 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(3422u, l3);
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
    t0 = concat_2(3429u, l4);
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
    l6 = vader_emit_c_ast$verbatim(2317u);
    t1 = vader_emit_c_ast$cast(3523u, l6);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 1427u);
    _a1_obj->f_expression = t1;
    t2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(452u, 1u, 13u, 2549u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t2;
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a3_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a3_obj, 1413u);
    _a3_obj->f_body = t2;
    l7 = (void*) _a3_obj;
    l8 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l7)->f_body;
    l9 = vader_emit_c$tramp_unbox_args(((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
    l9 = vader_emit_c$forward_boxed(l5, l9, l4);
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l9);
    l4 = vader_emit_c$trampoline_signature(l0, l5, l4);
    vader_array_t* _a4_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l8 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CFunction_t* _a5_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a5_obj, 1430u);
    _a5_obj->f_signature = l4;
    _a5_obj->f_prologue = l8;
    _a5_obj->f_body = l7;
    l4 = (void*) _a5_obj;
    vader_array_push_ref((vader_array_t*) l1, l4);
    t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l3));
    l6 = vader_emit_c$object_header(t1);
    t0 = concat_2(3432u, l5);
    t1 = vader_emit_c_ast$verbatim(t0);
    l10 = vader_emit_c_ast$address_of(t1);
    l10 = vader_emit_c_ast$cast(3524u, l10);
    t2 = (void*) &vader_data_68;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l4 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 2u] = l4;
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = l10.payload.obj;
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l6.payload.obj;
    t2 = (void*) _a7_arr;
    l6 = vader_emit_c_ast$initializer_list(t2);
    t3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l11 = vader_emit_c$global_storage(t3);
    t0 = concat_2(3429u, l5);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a8_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a8_obj, 1423u);
    _a8_obj->f_name = t0;
    _a8_obj->f_length = vader_box_obj(0u, NULL);
    _a8_obj->f_value = l6;
    l4 = (void*) _a8_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a9_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a9_obj, 1432u);
    _a9_obj->f_storage = l11;
    _a9_obj->f_constant = false;
    _a9_obj->f_type = 3430u;
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_emit_c$max_fn_arity(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
    l5 = (l3 <= l4);
    while (l5) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(42));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 3426u);
        l7 = std_core$write_int(l6, l7, l3);
        l7 = std_core$write_string_at(l6, l7, 1254u);
        l8 = std_core$finish_buffer(l6, l7);
        l9 = vader_emit_c$erased_parameters(l3);
        vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t* _a1_obj = (vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t));
        vader_obj_header_init(_a1_obj, 1431u);
        _a1_obj->f_result = 3395u;
        _a1_obj->f_name = l8;
        _a1_obj->f_parameters = l9;
        l10 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l2, l10);
        l5 = (l3 < l4);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 0u, 576u);
    t3 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a5_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a5_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
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
                vader_array_push_scalar((vader_array_t*) l5, vader_box_string(576u, l12));
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
                            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(576u, l17));
                        }
                        l16 = (l16 + INT64_C(1));
                    }
                }
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    t2 = vader_array_length(((vader_array_t*) l6));
    vader_array_t* _a5_arr = vader_array_reserve(453u, (int64_t) t2, 13u, 2553u);
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
    vader_array_t* _a7_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_box_string(576u, 767u);
    t4 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 1451u);
    _a8_obj->f_comment = t4;
    _a8_obj->f_items = l5;
    l5 = (void*) _a8_obj;
    vader_emit_c_ast$print_section(l0, l5);
    vader_array_t* _a9_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a9_arr->buf)[vader_array_offset(_a9_arr) + 0u] = vader_box_string(576u, 1131u);
    t4 = (void*) _a9_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a10_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a10_obj, 1451u);
    _a10_obj->f_comment = t4;
    _a10_obj->f_items = l4;
    l4 = (void*) _a10_obj;
    vader_emit_c_ast$print_section(l0, l4);
    vader_array_t* _a11_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a11_arr->buf)[vader_array_offset(_a11_arr) + 0u] = vader_box_string(576u, 1647u);
    l4 = (void*) _a11_arr;
    l5 = vader_emit_c$c_type_asserts(l1, l2);
    vader_struct_vader_emit_c_ast$CSection_t* _a12_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a12_obj, 1451u);
    _a12_obj->f_comment = l4;
    _a12_obj->f_items = l5;
    l4 = (void*) _a12_obj;
    vader_emit_c_ast$print_section(l0, l4);
    vader_array_t* _a13_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a13_arr->buf)[vader_array_offset(_a13_arr) + 0u] = vader_box_string(576u, 1643u);
    l4 = (void*) _a13_arr;
    l5 = vader_emit_c$c_struct_layout_asserts(l2, l3);
    vader_struct_vader_emit_c_ast$CSection_t* _a14_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a14_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1010u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a2_obj, 1447u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l3 = (void*) _a2_obj;
    l4 = vader_emit_c$foreign_unit_banner(l2);
    l4 = concat_2(741u, l4);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
            vader_obj_header_init(_a1_obj, 1448u);
            _a1_obj->f_signature = t2;
            l8 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l2, l8);
        }
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1451u);
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
    l5 = std_core$write_string_at(l2, l5, 3441u);
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
    t1 = (void*) &vader_data_68;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t0 = vader_array_length(((vader_array_t*) l2));
    l6 = vader_emit_c_ast$unsigned(t0);
    t0 = vader_array_length(((vader_array_t*) l3));
    l7 = vader_emit_c_ast$unsigned(t0);
    l8 = vader_emit_c$root_list(l1, 3396u, 3443u, l2);
    l9 = vader_emit_c$root_list(l1, 3525u, 3445u, l3);
    t1 = (void*) &vader_data_67;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    t1 = (void*) &vader_data_68;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a3_arr = vader_array_new(451u, 7u, 13u, 2544u);
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
        l6 = vader_emit_c$root_list(l1, 3483u, 3442u, l4);
        t0 = vader_array_length(((vader_array_t*) l4));
        t2 = vader_emit_c_ast$unsigned(t0);
        vader_array_t* _a4_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l6.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = t2.payload.obj;
        l3 = (void*) _a4_arr;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
    }
    t3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l10 = vader_emit_c$global_storage(t3);
    l6 = vader_emit_c_ast$initializer_list(l2);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a5_obj, 1423u);
    _a5_obj->f_name = 3444u;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l6;
    l2 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a6_obj, 1432u);
    _a6_obj->f_storage = l10;
    _a6_obj->f_constant = false;
    _a6_obj->f_type = 3437u;
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
    l4 = std_core$write_string_at(l3, l4, 3441u);
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
        l10 = std_core$write_string_at(l9, l10, 3441u);
        l10 = std_core$write_int(l9, l10, l2);
        l11 = std_core$finish_buffer(l9, l10);
        l12 = vader_emit_c$zero_of(l6);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a0_obj, 1423u);
        _a0_obj->f_name = l11;
        _a0_obj->f_length = vader_box_obj(0u, NULL);
        _a0_obj->f_value = l12;
        l13 = (void*) _a0_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a1_obj, 1432u);
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
    vader_emit_c$assert_stack_empty(l0, 2574u);
    l1 = vader_emit_c$expression_of(l1);
    vader_emit_c$open_if(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_import_group(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l4 = vader_emit_c$mirror_crossings(l2, l3);
    vader_emit_c$emit_foreign_declarations(l1, l2, l3, l4);
    t0 = vader_array_length(((vader_array_t*) l2));
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_struct_vader_emit_c_ast$CPragma_t* _a0_obj = (vader_struct_vader_emit_c_ast$CPragma_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPragma_t));
    vader_obj_header_init(_a0_obj, 1446u);
    _a0_obj->f_text = 740u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CPragma_t* _a1_obj = (vader_struct_vader_emit_c_ast$CPragma_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPragma_t));
    vader_obj_header_init(_a1_obj, 1446u);
    _a1_obj->f_text = 738u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(453u, 2u, 13u, 2553u);
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
        l8 = vader_emit_c$import_shim(l0, l7);
        vader_array_push_ref((vader_array_t*) l3, l8);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_emit_c_ast$CPragma_t* _a4_obj = (vader_struct_vader_emit_c_ast$CPragma_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPragma_t));
    vader_obj_header_init(_a4_obj, 1446u);
    _a4_obj->f_text = 739u;
    l4 = (void*) _a4_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 576u);
    t1 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1451u);
    _a6_obj->f_comment = t1;
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
            vader_obj_header_init(_a2_obj, 1453u);
            _a2_obj->f_storage = (uint8_t) 2;
            _a2_obj->f_inline = l8;
            _a2_obj->f_result = l9;
            _a2_obj->f_name = l10;
            _a2_obj->f_parameters = l11;
            t2 = (void*) _a2_obj;
            vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a3_obj, 1448u);
            _a3_obj->f_signature = t2;
            l12 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l2, l12);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = vader_box_string(576u, 964u);
    t2 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a5_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a5_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
            vader_obj_header_init(_a2_obj, 1448u);
            _a2_obj->f_signature = t1;
            l8 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l8);
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(26u, 0u, 0u, 576u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 581u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
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
        l14 = std_core$write_string_at(l13, l14, 2696u);
        l15 = vader_chk_add(i64, l7, l10);
        l14 = std_core$write_int(l13, l14, l15);
        l16 = std_core$finish_buffer(l13, l14);
        vader_array_push_scalar((vader_array_t*) l9, vader_box_string(576u, l16));
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
    vader_obj_header_init(_a0_obj, 1439u);
    _a0_obj->f_slot = t0;
    l4 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function;
    l6 = ((vader_struct_vader_core_bytecode$LocalField_t*) l1)->f_slot;
    l7 = vader_emit_c$slot_val_type(l5, l6);
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
    l4 = vader_emit_c$slot_val_type(l2, l3);
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
    l3 = vader_emit_c$slot_val_type(((vader_struct_vader_emit_c$FnState_t*) l0)->f_function, l1);
    if (l3 == INT32_C(14)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c$materialize_stack_for_slot(l0, l1);
    l4 = vader_emit_c$pop(l0);
    vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
    vader_obj_header_init(_a0_obj, 1439u);
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
    vader_obj_header_init(_a0_obj, 1444u);
    _a0_obj->f_type = 2614u;
    _a0_obj->f_name = 1919u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a1_obj, 1444u);
    _a1_obj->f_type = 2140u;
    _a1_obj->f_name = 1923u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(245u, 2u, 13u, 1444u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3;
    l3 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 1453u);
    _a3_obj->f_storage = (uint8_t) 1;
    _a3_obj->f_inline = false;
    _a3_obj->f_result = 2614u;
    _a3_obj->f_name = 2752u;
    _a3_obj->f_parameters = l3;
    l3 = (void*) _a3_obj;
    t0 = vader_emit_c$main_body(l0, l2);
    vader_struct_vader_emit_c_ast$CBlock_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a4_obj, 1413u);
    _a4_obj->f_body = t0;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l5 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CFunction_t* _a6_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a6_obj, 1430u);
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
    l3 = vader_emit_c$aux(l0, 2149u);
    l4 = vader_emit_c$gc_allocation(3430u);
    vader_emit_c$declare(l0, 3431u, l3, l4);
    l5 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l1)->f_env_type_id;
    vader_emit_c$init_object_header(l0, l3, l5);
    t0 = concat_2(l3, 466u);
    l4 = vader_emit_c_ast$verbatim(t0);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l5 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l1)->f_function_index;
    l7 = vader_emit_c$fn_symbol_name(l6, l5);
    t0 = concat_2(3427u, l7);
    t1 = vader_emit_c_ast$verbatim(t0);
    l8 = vader_emit_c_ast$address_of(t1);
    l8 = vader_emit_c_ast$cast(3524u, l8);
    vader_emit_c$assign(l0, l4, l8);
    t0 = concat_2(l3, 468u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 5u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3402u, l6);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l0));
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        if (l7.tag == 1189u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            if (t1 != 0u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l5];
                t1 = t2.payload.s;
                vader_struct_vader_emit_c_ast$CStructForward_t* _a4_obj = (vader_struct_vader_emit_c_ast$CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructForward_t));
                vader_obj_header_init(_a4_obj, 1457u);
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
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1451u);
    _a6_obj->f_comment = t0;
    _a6_obj->f_items = l3;
    l3 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l2, l3);
    vader_array_t* _a7_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_reserve(246u, (int64_t) t0, 13u, 1459u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l4));
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l6, 581u);
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
        t1 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l6, 581u);
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
        l3 = concat_2(3321u, l3);
        vader_emit_c$unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a0_arr = vader_array_reserve(239u, (int64_t) l4, 13u, 1411u);
    l5 = (void*) _a0_arr;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        t0 = vader_chk_sub(i64, l2, INT64_C(1));
        l6 = vader_chk_sub(i64, t0, l4);
        l7 = vader_emit_c$pop(l0);
        l3 = vader_emit_c$out_param_name(l6);
        t1 = concat_2(411u, l3);
        l8 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l6, 581u);
        l9 = ((uint8_t) t2.payload.i);
        l10 = vader_emit_c$coerced_as(l0, l7, l9);
        vader_struct_vader_emit_c_ast$CAssign_t* _a2_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a2_obj, 1411u);
        _a2_obj->f_target = l8;
        _a2_obj->f_value = l10;
        _a2_obj->f_operator = vader_box_obj(0u, NULL);
        l11 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l5, l11);
        l4 = (l4 + INT64_C(1));
    }
    vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a3_obj, 1449u);
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
    vader_obj_header_init(_a0_obj, 1399u);
    _a0_obj->f_name = l3;
    _a0_obj->f_storage = l6;
    _a0_obj->f_type_id = l7;
    _a0_obj->f_element_tag = l9;
    l8 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(451u, 0u, 13u, 2544u);
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
            l17 = std_core$write_string_at(l16, l17, 1257u);
            l17 = std_core$write_int(l16, l17, l11);
            l18 = std_core$finish_buffer(l16, l17);
            l19 = vader_emit_c$box_slot_1(l0, l1, l13, l18, l4);
            vader_array_push_ref((vader_array_t*) l10, l19.payload.obj);
        } else if (l13.tag == 1192u) {
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
    t2 = vader_emit_c_ast$cast(3383u, l13);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c$emit_op(void* l0, int32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    uint8_t l7;
    bool l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_emit_c$invalidate_header_cache(l0, l2);
    if (l2.tag == 1248u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1268u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1227u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1199u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1214u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1300u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1316u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 1293u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_local_get(l0, l3);
    } else if (l2.tag == 1294u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        vader_emit_c$emit_local_set(l0, l4, false);
    } else if (l2.tag == 1295u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        vader_emit_c$emit_local_set(l0, l4, true);
    } else if (l2.tag == 1292u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_local_field(l0, l3);
    } else if (l2.tag == 1305u) {
        vader_emit_c$emit_return(l0);
    } else if (l2.tag == 1306u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_c$emit_return_lit(l0, l5);
    } else if (l2.tag == 1222u) {
        vader_emit_c$drop_top(l0);
    } else if (l2.tag == 1211u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call(l0, l3);
    } else if (l2.tag == 1212u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call_import(l0, l3);
    } else if (l2.tag == 1213u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call_indirect(l0, l3);
    } else if (l2.tag == 1339u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_virtual_call(l0, l3);
    } else if (l2.tag == 1240u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_fn_ref(l0, l3);
    } else if (l2.tag == 1239u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_fn_addr(l0, l3);
    } else if (l2.tag == 1297u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_make_closure(l0, l3);
    } else if (l2.tag == 1283u) {
        vader_emit_c$emit_if_open(l0);
    } else if (l2.tag == 1223u) {
        vader_emit_c$emit_else(l0);
    } else if (l2.tag == 1224u) {
        vader_emit_c$emit_end(l0, l1);
    } else if (l2.tag == 1197u) {
        vader_emit_c$emit_open_scope(l0, l1, (uint8_t) 0);
    } else if (l2.tag == 1296u) {
        vader_emit_c$emit_open_scope(l0, l1, (uint8_t) 1);
    } else if (l2.tag == 1204u) {
        vader_emit_c$emit_branch(l0, l1, false);
    } else if (l2.tag == 1205u) {
        vader_emit_c$emit_branch(l0, l1, true);
    } else if (l2.tag == 1202u) {
        vader_emit_c$push_unop(l0, 299u, (uint8_t) 10);
    } else if (l2.tag == 1320u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_new(l0, l3);
    } else if (l2.tag == 1319u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_get(l0, l3);
    } else if (l2.tag == 1321u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_set(l0, l3);
    } else if (l2.tag == 1336u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_union_field_get(l0, l3);
    } else if (l2.tag == 1337u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_union_field_set(l0, l3);
    } else if (l2.tag == 1167u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_new(l0, l3);
    } else if (l2.tag == 1166u) {
        vader_emit_c$emit_array_len(l0);
    } else if (l2.tag == 1168u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_push(l0, l3);
    } else if (l2.tag == 1165u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_get(l0, l3);
    } else if (l2.tag == 1173u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_set(l0, l3);
    } else if (l2.tag == 1174u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_slice(l0, l3);
    } else if (l2.tag == 1172u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_reserve(l0, l3);
    } else if (l2.tag == 1171u) {
        vader_emit_c$emit_array_repeat(l0);
    } else if (l2.tag == 1169u) {
        vader_emit_c$emit_array_push_all(l0);
    } else if (l2.tag == 1164u) {
        vader_emit_c$emit_array_copy(l0);
    } else if (l2.tag == 1170u) {
        vader_emit_c$emit_array_remove_last(l0);
    } else if (l2.tag == 1163u) {
        vader_emit_c$emit_array_clear(l0);
    } else if (l2.tag == 1218u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_data_const_op(l0, l3);
    } else if (l2.tag == 1241u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_global_get(l0, l3);
    } else if (l2.tag == 1242u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_global_set(l0, l3);
    } else if (l2.tag == 1323u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_type_const(l0, l3);
    } else if (l2.tag == 1322u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_type_check(l0, l3);
    } else if (l2.tag == 1301u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_ref_cast(l0, l3);
    } else if (l2.tag == 1304u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_retag_op(l0, l3);
    } else if (l2.tag == 1338u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
        vader_emit_c$unreachable(l0, l6);
    } else if (l2.tag == 1217u) {
        t0 = l2.payload.obj;
        l7 = vader_emit_c$convert_target_val(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        vader_emit_c$emit_convert(l0, l7, l6);
    } else if (l2.tag == 1307u) {
        vader_emit_c$emit_size_of_type(l0);
    } else if (l2.tag == 1215u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_checked_arith(l0, l3);
    } else if (l2.tag == 1216u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_checked_neg(l0, l3);
    } else if (l2.tag == 1243u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 2);
    } else if (l2.tag == 1262u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 2);
    } else if (l2.tag == 1256u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 2);
    } else if (l2.tag == 1249u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 2);
    } else if (l2.tag == 1255u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 2);
    } else if (l2.tag == 1258u) {
        vader_emit_c$push_unop(l0, 458u, (uint8_t) 2);
    } else if (l2.tag == 1245u) {
        vader_emit_c$push_unop(l0, 3607u, (uint8_t) 2);
    } else if (l2.tag == 1244u) {
        vader_emit_c$push_binop(l0, (uint8_t) 13, (uint8_t) 2);
    } else if (l2.tag == 1246u) {
        vader_emit_c$push_binop(l0, (uint8_t) 15, (uint8_t) 2);
    } else if (l2.tag == 1247u) {
        vader_emit_c$push_binop(l0, (uint8_t) 14, (uint8_t) 2);
    } else if (l2.tag == 1259u) {
        vader_emit_c$push_shift(l0, (uint8_t) 5, (uint8_t) 2);
    } else if (l2.tag == 1260u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 2);
    } else if (l2.tag == 1261u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 6);
    } else if (l2.tag == 1250u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 2);
    } else if (l2.tag == 1257u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 2);
    } else if (l2.tag == 1254u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 2);
    } else if (l2.tag == 1253u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 2);
    } else if (l2.tag == 1252u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 2);
    } else if (l2.tag == 1251u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 2);
    } else if (l2.tag == 1263u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 3);
    } else if (l2.tag == 1282u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 3);
    } else if (l2.tag == 1276u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 3);
    } else if (l2.tag == 1269u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 3);
    } else if (l2.tag == 1275u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 3);
    } else if (l2.tag == 1278u) {
        vader_emit_c$push_i64_neg(l0);
    } else if (l2.tag == 1264u) {
        vader_emit_c$push_binop(l0, (uint8_t) 13, (uint8_t) 3);
    } else if (l2.tag == 1266u) {
        vader_emit_c$push_binop(l0, (uint8_t) 15, (uint8_t) 3);
    } else if (l2.tag == 1267u) {
        vader_emit_c$push_binop(l0, (uint8_t) 14, (uint8_t) 3);
    } else if (l2.tag == 1265u) {
        vader_emit_c$push_unop(l0, 3607u, (uint8_t) 3);
    } else if (l2.tag == 1279u) {
        vader_emit_c$push_shift(l0, (uint8_t) 5, (uint8_t) 3);
    } else if (l2.tag == 1280u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 3);
    } else if (l2.tag == 1281u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 7);
    } else if (l2.tag == 1270u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 3);
    } else if (l2.tag == 1277u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 3);
    } else if (l2.tag == 1274u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 3);
    } else if (l2.tag == 1273u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 3);
    } else if (l2.tag == 1272u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 3);
    } else if (l2.tag == 1271u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 3);
    } else if (l2.tag == 1324u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 6);
    } else if (l2.tag == 1329u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 6);
    } else if (l2.tag == 1328u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 6);
    } else if (l2.tag == 1327u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 6);
    } else if (l2.tag == 1326u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 6);
    } else if (l2.tag == 1325u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 6);
    } else if (l2.tag == 1330u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 7);
    } else if (l2.tag == 1335u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 7);
    } else if (l2.tag == 1334u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 7);
    } else if (l2.tag == 1333u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 7);
    } else if (l2.tag == 1332u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 7);
    } else if (l2.tag == 1331u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 7);
    } else if (l2.tag == 1226u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 9);
    } else if (l2.tag == 1237u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 9);
    } else if (l2.tag == 1234u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 9);
    } else if (l2.tag == 1228u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 9);
    } else if (l2.tag == 1236u) {
        vader_emit_c$push_unop(l0, 458u, (uint8_t) 9);
    } else if (l2.tag == 1229u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 9);
    } else if (l2.tag == 1235u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 9);
    } else if (l2.tag == 1233u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 9);
    } else if (l2.tag == 1232u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 9);
    } else if (l2.tag == 1231u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 9);
    } else if (l2.tag == 1230u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 9);
    } else if (l2.tag == 1200u) {
        vader_emit_c$push_binop(l0, (uint8_t) 11, (uint8_t) 10);
    } else if (l2.tag == 1201u) {
        vader_emit_c$push_binop(l0, (uint8_t) 12, (uint8_t) 10);
    } else if (l2.tag == 1198u) {
        vader_emit_c$push_binop(l0, (uint8_t) 16, (uint8_t) 10);
    } else if (l2.tag == 1203u) {
        vader_emit_c$push_binop(l0, (uint8_t) 17, (uint8_t) 10);
    } else if (l2.tag == 1317u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 1318u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 1315u) {
        vader_emit_c$emit_string_compare(l0);
    } else if (l2.tag == 1302u) {
        vader_emit_c$push_binop_any(l0, (uint8_t) 11, (uint8_t) 10);
    } else if (l2.tag == 1303u) {
        vader_emit_c$push_binop_any(l0, (uint8_t) 12, (uint8_t) 10);
    } else if (l2.tag == 1221u) {
        vader_emit_c$emit_defer_push(l0);
    } else if (l2.tag == 1220u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_defer_pop_exec(l0, l3);
    } else if (l2.tag == 1206u) {
        vader_emit_c$emit_buffer_new(l0);
    } else if (l2.tag == 1291u) {
        vader_emit_c$emit_buffer_load(l0, 3401u, (uint8_t) 2);
    } else if (l2.tag == 1286u) {
        vader_emit_c$emit_buffer_load(l0, 3399u, (uint8_t) 2);
    } else if (l2.tag == 1287u) {
        vader_emit_c$emit_buffer_load(l0, 3400u, (uint8_t) 3);
    } else if (l2.tag == 1285u) {
        vader_emit_c$emit_buffer_load(l0, 3398u, (uint8_t) 9);
    } else if (l2.tag == 1314u) {
        vader_emit_c$emit_buffer_store(l0, 3407u, 3293u);
    } else if (l2.tag == 1309u) {
        vader_emit_c$emit_buffer_store(l0, 3405u, 2616u);
    } else if (l2.tag == 1310u) {
        vader_emit_c$emit_buffer_store(l0, 3406u, 2617u);
    } else if (l2.tag == 1308u) {
        vader_emit_c$emit_buffer_store(l0, 3404u, 2257u);
    } else if (l2.tag == 1289u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2616u, (uint8_t) 2, l8);
    } else if (l2.tag == 1290u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2617u, (uint8_t) 3, l8);
    } else if (l2.tag == 1288u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2257u, (uint8_t) 9, l8);
    } else if (l2.tag == 1312u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2616u, (uint8_t) 2, l8);
    } else if (l2.tag == 1313u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2617u, (uint8_t) 3, l8);
    } else if (l2.tag == 1311u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2257u, (uint8_t) 9, l8);
    } else if (l2.tag == 1299u) {
        vader_emit_c$emit_memory_copy(l0);
    } else if (l2.tag == 1207u) {
        vader_emit_c$emit_buffer_to_string(l0);
    } else if (l2.tag == 1208u) {
        vader_emit_c$emit_buffer_write_string(l0);
    } else if (l2.tag == 1238u) {
        vader_emit_c$emit_f64_to_bits(l0);
    } else if (l2.tag == 1196u) {
        vader_emit_c$emit_bits_to_f64(l0);
    } else if (l2.tag == 1225u) {
        vader_emit_c$emit_f32_to_bits(l0);
    } else {
        if (!(l2.tag == 1195u)) {
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
    l4 = std_core$write_string_at(l3, l4, 3016u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 377u);
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
            vader_obj_header_init(_a0_obj, 1400u);
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
        l4 = std_core$write_string_at(l3, l4, 2736u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, l1);
    l2 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CInclude_t* _a1_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a1_obj, 1435u);
    _a1_obj->f_path = 3342u;
    _a1_obj->f_system = false;
    l3 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a2_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a2_obj, 1435u);
    _a2_obj->f_path = 3068u;
    _a2_obj->f_system = true;
    l4 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a3_obj, 1435u);
    _a3_obj->f_path = 3069u;
    _a3_obj->f_system = true;
    l5 = (void*) _a3_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a4_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a4_obj, 1435u);
    _a4_obj->f_path = 3093u;
    _a4_obj->f_system = true;
    l6 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(453u, 4u, 13u, 2553u);
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 3u] = l6;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 2u] = l5;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l4;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = l3;
    l3 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_reserve(451u, (int64_t) t0, 13u, 2544u);
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
    if (!(l2.tag == 1404u)) {
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
        vader_array_t* _a0_arr = vader_array_new(239u, 0u, 13u, 1411u);
        t1 = (void*) _a0_arr;
        vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a1_obj, 1449u);
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
        vader_array_t* _a2_arr = vader_array_new(239u, 0u, 13u, 1411u);
        l2 = (void*) _a2_arr;
        l4 = vader_emit_c$coerced_as(l0, l4, l1);
        l3 = vader_emit_c$c_type_for_val_bare(l1);
        vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a3_obj, 1449u);
        _a3_obj->f_stores = l2;
        _a3_obj->f_value = l4;
        _a3_obj->f_snapshot_type = l3;
        _a3_obj->f_pops_frame = false;
        l2 = (void*) _a3_obj;
        vader_emit_c$return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
    l3 = concat_2(3321u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(239u, 0u, 13u, 1411u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a1_obj, 1449u);
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
    l1 = vader_emit_c$payload(t1, 2880u);
    l1 = vader_emit_c_ast$around(374u, l1, 1198u);
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
            vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l8.payload.obj;
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l6.payload.obj;
            l7 = (void*) _a0_arr;
            vader_emit_c$statement_macro(l0, 1133u, l7);
        }
        { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_emit_c_ast$verbatim(l5);
    l6 = vader_emit_c$expression_of(l2);
    vader_array_t* _a1_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l4.payload.obj;
    l7 = (void*) _a1_arr;
    vader_emit_c$statement_macro(l0, 1132u, l7);
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
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 581u);
    l7 = (void*) _a0_arr;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) l1));
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l8, 581u);
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
                    t0 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l13, 581u);
                    if (((int32_t) t0.payload.i) == l10) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
                        t0 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l13];
                        l15 = t0.payload.s;
                        l16 = vader_emit_c_ast$verbatim(528u);
                        l17 = vader_emit_c_ast$declaration(3482u, l15, l16);
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
                t0 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l19, 581u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l19)
                        t0 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l19];
                        l21 = t0.payload.s;
                        l22 = vader_emit_c_ast$verbatim(866u);
                        l23 = vader_emit_c_ast$declaration(3524u, l21, l22);
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
                        l26 = vader_emit_c_ast$declaration(3524u, l25, vader_box_obj(0u, NULL));
                        vader_array_push_ref((vader_array_t*) l0, l26.payload.obj);
                    }
                }
                l19 = (l19 + INT64_C(1));
            }
        } else {
            vader_array_t* _a9_arr = vader_array_new(241u, 0u, 13u, 1423u);
            l27 = (void*) _a9_arr;
            l28 = INT64_C(0);
            l29 = vader_array_length(((vader_array_t*) l1));
            while ((l28 < l29)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_read_u8(_a10_slotarr, vader_array_offset(_a10_slotarr) + (size_t) l28, 581u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l28)
                        t0 = vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l28];
                        l30 = t0.payload.s;
                        vader_array_t* _a12_arr = vader_array_new(451u, 0u, 13u, 2544u);
                        l31 = (void*) _a12_arr;
                        l32 = vader_emit_c_ast$call(3392u, l31);
                        vader_struct_vader_emit_c_ast$CDeclarator_t* _a13_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
                        vader_obj_header_init(_a13_obj, 1423u);
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
                        vader_obj_header_init(_a16_obj, 1423u);
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
            vader_obj_header_init(_a17_obj, 1422u);
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
    vader_array_t* _a0_arr = vader_array_reserve(451u, (int64_t) t0, 13u, 2544u);
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
    vader_emit_c$push_pool_array(l0, l1, 3395u, (uint8_t) 0, l4);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(3479u, l3);
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
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l3, l7, l9, l12;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    int64_t l6, l19;
    uint8_t l13;
    bool l18;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    bool t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[4] = { &l4, &l8, &l14, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l10, &l11, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l15, &l16, &l17, &t5 };
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
    if (l4.tag == 1189u) {
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
        vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a2_arr;
        l6 = ((int64_t) (int32_t) l3);
        vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l6);
        l2 = (void*) _a3_arr;
        l7 = INT32_C(0);
        while ((l7 < l3)) {
            l8 = vader_emit_c$pop(l0);
            t3 = vader_chk_sub(i32, l3, INT32_C(1));
            l9 = vader_chk_sub(i32, t3, l7);
            t1 = l4.payload.obj;
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            l10 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l9);
            l11 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l12 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_type_index;
            l13 = vader_emit_c$val_type_of_field(l11, l12);
            l14 = vader_emit_c$coerced_as(l0, l8, l13);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            vader_array_ref_store(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l9, l14.payload.obj);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
            l7 = (l7 + INT32_C(1));
        }
        t4 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_stack;
        if (t4) {
            l15 = vader_emit_c$aux(l0, 3074u);
            l16 = vader_emit_c$aux(l0, 2880u);
            l10 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack_storages;
            vader_struct_vader_emit_c$StackStorage_t* _a6_obj = (vader_struct_vader_emit_c$StackStorage_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackStorage_t));
            vader_obj_header_init(_a6_obj, 1406u);
            _a6_obj->f_cname = l5;
            _a6_obj->f_storage = l15;
            l11 = (void*) _a6_obj;
            vader_array_push_ref((vader_array_t*) l10, l11);
            l17 = concat_2(l5, 411u);
            t0 = vader_emit_c_ast$verbatim(l15);
            l8 = vader_emit_c_ast$address_of(t0);
            vader_emit_c$declare(l0, l17, l16, l8);
            l15 = l16;
        } else {
            l16 = vader_emit_c$aux(l0, 2880u);
            l17 = concat_2(l5, 411u);
            l8 = vader_emit_c$gc_allocation(l5);
            vader_emit_c$declare(l0, l17, l16, l8);
            l15 = l16;
        }
        l7 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        vader_emit_c$init_object_header(l0, l15, l7);
        l7 = INT32_C(0);
        while ((l7 < l3)) {
            t1 = l4.payload.obj;
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
            l10 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l7);
            t5 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
            l5 = vader_emit_c$field_c_name(t5);
            t5 = concat_3(l15, 463u, l5);
            l8 = vader_emit_c_ast$verbatim(t5);
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
            l14 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l7);
            vader_emit_c$assign(l0, l8, l14);
            l7 = (l7 + INT32_C(1));
        }
        l4 = vader_emit_c_ast$verbatim(l15);
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
        l10 = (void*) vader_buffer_new((size_t) INT64_C(56));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l10, l6, 2602u);
        l19 = vader_array_length(((vader_array_t*) l2));
        l6 = std_core$write_int(l10, l6, l19);
        l6 = std_core$write_string_at(l10, l6, 469u);
        l5 = std_core$finish_buffer(l10, l6);
    } else {
        l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        l15 = vader_core_bytecode$bc_type_key(l2, l3);
        l6 = vader_host_std_core$Intrinsic$byte_len(l15);
        l10 = (void*) vader_buffer_new((size_t) (INT64_C(53) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l10, l6, 3168u);
        l6 = std_core$write_string_at(l10, l6, l15);
        l6 = std_core$write_string_at(l10, l6, 1378u);
        l19 = vader_array_length(((vader_array_t*) l2));
        l6 = std_core$write_int(l10, l6, l19);
        l6 = std_core$write_string_at(l10, l6, 469u);
        l5 = std_core$finish_buffer(l10, l6);
    }
    l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
    l6 = vader_host_std_core$Intrinsic$byte_len(l5);
    l2 = (void*) vader_buffer_new((size_t) (INT64_C(52) + l6));
    l6 = INT64_C(0);
    l6 = std_core$write_string_at(l2, l6, 3111u);
    l19 = ((int64_t) (int32_t) l3);
    l6 = std_core$write_int(l2, l6, l19);
    l6 = std_core$write_string_at(l2, l6, 541u);
    l6 = std_core$write_string_at(l2, l6, l5);
    t5 = std_core$finish_buffer(l2, l6);
    std_abort$todo(t5);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_c$emit_struct_set(void* l0, void* l1) {
    void* l2 = NULL;
    void* l9 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    int64_t l10, l11;
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l6, &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l9, &t3 };
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
    if (!(l4.tag == 1189u)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(50));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 3116u);
        t0 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_type_id;
        l11 = ((int64_t) (int32_t) t0);
        l10 = std_core$write_int(l9, l10, l11);
        t1 = std_core$finish_buffer(l9, l10);
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
    l6 = vader_emit_c$pop(l0);
    l7 = vader_emit_c$pop(l0);
    t3 = l4.payload.obj;
    l2 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t3)->f_fields;
    l3 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_field_index;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
    l4 = vader_emit_c$object_pointer_of(l7);
    l8 = ((vader_struct_vader_core_bytecode$BcField_t*) l2)->f_name;
    l7 = vader_emit_c$field_of(l5, l4, l8);
    l3 = ((vader_struct_vader_core_bytecode$BcField_t*) l2)->f_type_index;
    l4 = vader_emit_c$struct_set_barrier(l1, l5, l4);
    vader_emit_c$store_field(l0, l7, l6, l3, l4);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types));
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
        if (l6.tag == 1189u) {
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
                vader_obj_header_init(_a4_obj, 1457u);
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
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 1451u);
    _a6_obj->f_comment = t0;
    _a6_obj->f_items = l2;
    l2 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a7_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) t0, 0u, 576u);
    l6 = (void*) _a0_arr;
    l7 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) l0));
    while ((l7 < l8)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 3129u);
        l10 = std_core$write_int(l9, l10, l7);
        l11 = std_core$finish_buffer(l9, l10);
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(576u, l11));
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
        if (l6.tag == 1190u) {
            vader_array_t* _a1_arr = vader_array_new(451u, 0u, 13u, 2544u);
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
            vader_obj_header_init(_a3_obj, 1445u);
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
        l11 = 3223u;
    } else {
        l11 = 2396u;
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
    l3 = std_core$write_string_at(l2, l3, 3394u);
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_null_tag;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3265u);
    t0 = ((vader_struct_vader_core_bytecode$TypeConst_t*) l1)->f_type_id;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 3264u);
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
        if (l9.tag == 1179u) {
            l4 = true;
        }
        if (l9.tag == 1176u) {
            l5 = true;
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_new(453u, 0u, 13u, 2553u);
    l6 = (void*) _a1_arr;
    if (l4) {
        l9 = vader_emit_c$single_offset_list(3428u, 2887u);
        vader_array_push_ref((vader_array_t*) l6, l9.payload.obj);
    }
    if (l5) {
        l9 = vader_emit_c$single_offset_list(3374u, 2886u);
        vader_array_push_ref((vader_array_t*) l6, l9.payload.obj);
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 1451u);
    _a3_obj->f_comment = t0;
    _a3_obj->f_items = l6;
    l6 = (void*) _a3_obj;
    vader_emit_c_ast$print_section(l1, l6);
    vader_array_t* _a4_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l6 = (void*) _a4_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l9 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
        l10 = l9;
        if (l9.tag == 1189u) {
            l11 = l10.payload.obj;
            l12 = l10.payload.obj;
            l13 = vader_emit_c$classify_struct_fields(l0, l12, l7);
            l14 = vader_emit_c$struct_info_row(l0, l11, l13, l7);
            vader_array_push_ref((vader_array_t*) l6, l14.payload.obj);
        } else if (l9.tag == 1179u) {
            t0 = l10.payload.obj;
            l15 = vader_core_bytecode$size_of_bc_type(vader_ref_box(t0));
            vader_array_t* _a6_arr = vader_array_new(451u, 0u, 13u, 2544u);
            l16 = (void*) _a6_arr;
            l17 = vader_emit_c$single_reference_row(l7, 726u, 3430u, l15, 3428u, l16);
            vader_array_push_ref((vader_array_t*) l6, l17.payload.obj);
        } else if (l9.tag == 1176u) {
            t0 = l10.payload.obj;
            l18 = vader_core_bytecode$size_of_bc_type(vader_ref_box(t0));
            l19 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l8 = INT64_C(0);
            t0 = l10.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
            l20 = ((int64_t) (int32_t) t1);
            l8 = std_core$write_int(l19, l8, l20);
            l8 = std_core$write_string_at(l19, l8, 3263u);
            t2 = std_core$finish_buffer(l19, l8);
            l21 = vader_emit_c_ast$verbatim(t2);
            t3 = vader_emit_c_ast$designated(488u, l21);
            vader_array_t* _a7_arr = vader_array_new(451u, 1u, 13u, 2544u);
            ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t3.payload.obj;
            l22 = (void*) _a7_arr;
            l23 = vader_emit_c$single_reference_row(l7, 639u, 3382u, l18, 3374u, l22);
            vader_array_push_ref((vader_array_t*) l6, l23.payload.obj);
        } else {
            l24 = vader_core_bytecode$size_of_bc_type(l10);
            if ((l24 > INT32_C(0))) {
                l25 = vader_emit_c_ast$number(((int64_t) (int32_t) l24));
                t3 = vader_emit_c_ast$designated(505u, l25);
                vader_array_t* _a8_arr = vader_array_new(451u, 1u, 13u, 2544u);
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
    vader_obj_header_init(_a9_obj, 1423u);
    _a9_obj->f_name = 3489u;
    _a9_obj->f_length = vader_box_i32(579u, l15);
    _a9_obj->f_value = l9;
    l2 = (void*) _a9_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a10_obj, 1432u);
    _a10_obj->f_storage = (uint8_t) 1;
    _a10_obj->f_constant = true;
    _a10_obj->f_type = 3488u;
    _a10_obj->f_declarator = l2;
    l2 = (void*) _a10_obj;
    l9 = vader_emit_c_ast$number(l3);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a11_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a11_obj, 1423u);
    _a11_obj->f_name = 3487u;
    _a11_obj->f_length = vader_box_obj(0u, NULL);
    _a11_obj->f_value = l9;
    l6 = (void*) _a11_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a12_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a12_obj, 1432u);
    _a12_obj->f_storage = (uint8_t) 1;
    _a12_obj->f_constant = true;
    _a12_obj->f_type = 3038u;
    _a12_obj->f_declarator = l6;
    l6 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(26u, 0u, 0u, 576u);
    l11 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(453u, 2u, 13u, 2553u);
    ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l6;
    ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l2;
    l2 = (void*) _a14_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a15_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a15_obj, 1451u);
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
        l3 = concat_2(2862u, l3);
        vader_emit_c$unreachable(l0, l3);
        t0 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
        if (t0 == INT64_C(1)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 581u);
            l7 = ((uint8_t) t1.payload.i);
            l8 = vader_emit_c$new_temporary(l0, l7);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
            t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0), 581u);
            l7 = ((uint8_t) t1.payload.i);
            vader_emit_c$push_temporary(l0, l8, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l4.payload.obj;
    l4 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$coerced_as(l0, l4, (uint8_t) 17);
    vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
        vader_array_t* _a2_arr = vader_array_new(240u, 0u, 13u, 1416u);
        l9 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 579u);
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
            l21 = vader_emit_c_ast$verbatim(2968u);
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t2 = vader_array_read_u8(_a6_slotarr, vader_array_offset(_a6_slotarr) + (size_t) INT32_C(0), 581u);
            l22 = ((uint8_t) t2.payload.i);
            t2 = vader_emit_c$coerce_expr(l2, l21, (uint8_t) 17, l22);
            vader_array_t* _a7_arr = vader_array_new(451u, 1u, 13u, 2544u);
            ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t2.payload.obj;
            l23 = (void*) _a7_arr;
            t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params));
            l24 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
            l25 = INT32_C(0);
            while ((l25 < l24)) {
                l26 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l27 = INT64_C(0);
                l27 = std_core$write_string_at(l26, l27, 1722u);
                l28 = ((int64_t) (int32_t) l25);
                l27 = std_core$write_int(l26, l27, l28);
                t3 = std_core$finish_buffer(l26, l27);
                l29 = vader_emit_c_ast$verbatim(t3);
                l30 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params;
                l31 = vader_chk_add(i32, l25, INT32_C(1));
                vader_array_t* _a8_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l31)
                t2 = vader_array_read_u8(_a8_slotarr, vader_array_offset(_a8_slotarr) + (size_t) l31, 581u);
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
                vader_obj_header_init(_a9_obj, 1427u);
                _a9_obj->f_expression = l34;
                l36 = (void*) _a9_obj;
                vader_array_t* _a10_arr = vader_array_new(239u, 0u, 13u, 1411u);
                t6 = (void*) _a10_arr;
                vader_struct_vader_emit_c_ast$CReturn_t* _a11_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
                vader_obj_header_init(_a11_obj, 1449u);
                _a11_obj->f_stores = t6;
                _a11_obj->f_value = vader_box_obj(0u, NULL);
                _a11_obj->f_snapshot_type = 0u;
                _a11_obj->f_pops_frame = false;
                l37 = (void*) _a11_obj;
                vader_array_t* _a12_arr = vader_array_new(454u, 2u, 13u, 2555u);
                ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 1u] = l37;
                ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = l36;
                l35 = (void*) _a12_arr;
            } else {
                vader_array_t* _a13_arr = vader_array_new(239u, 0u, 13u, 1411u);
                l38 = (void*) _a13_arr;
                l39 = vader_core_bytecode$bc_single_result(l20);
                l40 = vader_core_bytecode$bc_single_result(l8);
                l41 = vader_emit_c$dispatcher_result(l2, l34, l39, l40);
                vader_struct_vader_emit_c_ast$CReturn_t* _a14_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
                vader_obj_header_init(_a14_obj, 1449u);
                _a14_obj->f_stores = l38;
                _a14_obj->f_value = l41;
                _a14_obj->f_snapshot_type = 0u;
                _a14_obj->f_pops_frame = false;
                t6 = (void*) _a14_obj;
                vader_array_t* _a15_arr = vader_array_new(454u, 1u, 13u, 2555u);
                ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = t6;
                l35 = (void*) _a15_arr;
            }
            t7 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l14)->f_receiver_type_index;
            t2 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t7));
            vader_struct_vader_emit_c_ast$CCase_t* _a16_obj = (vader_struct_vader_emit_c_ast$CCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCase_t));
            vader_obj_header_init(_a16_obj, 1416u);
            _a16_obj->f_value = t2;
            _a16_obj->f_body = l35;
            l42 = (void*) _a16_obj;
            vader_array_push_ref((vader_array_t*) l9, l42);
            l13 = (l13 + INT64_C(1));
        }
        l43 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_key;
        t3 = concat_2(3529u, l43);
        t4 = vader_emit_c$c_string_lit(t3);
        t2 = vader_emit_c_ast$verbatim(t4);
        vader_array_t* _a17_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = t2.payload.obj;
        l44 = (void*) _a17_arr;
        t2 = vader_emit_c_ast$call(3490u, l44);
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a18_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a18_obj, 1427u);
        _a18_obj->f_expression = t2;
        l45 = (void*) _a18_obj;
        t2 = vader_emit_c_ast$verbatim(2968u);
        vader_struct_vader_emit_c_ast$CMember_t* _a19_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a19_obj, 1441u);
        _a19_obj->f_base = t2;
        _a19_obj->f_member = 3130u;
        _a19_obj->f_arrow = false;
        l46 = (void*) _a19_obj;
        vader_array_t* _a20_arr = vader_array_new(454u, 1u, 13u, 2555u);
        ((void**) _a20_arr->buf->slots)[vader_array_offset(_a20_arr) + 0u] = l45;
        l47 = (void*) _a20_arr;
        vader_struct_vader_emit_c_ast$CSwitch_t* _a21_obj = (vader_struct_vader_emit_c_ast$CSwitch_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSwitch_t));
        vader_obj_header_init(_a21_obj, 1458u);
        _a21_obj->f_subject = vader_ref_box(l46);
        _a21_obj->f_cases = l9;
        _a21_obj->f_default_body = vader_ref_box(l47);
        t6 = (void*) _a21_obj;
        vader_array_t* _a22_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t6;
        l48 = (void*) _a22_arr;
        t5 = vader_core_bytecode$bc_single_result(l8);
        if (t5 != INT32_C(14)) {
            vader_array_push_ref((vader_array_t*) l48, l45);
        }
        l49 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_key;
        l50 = vader_emit_c$dispatcher_signature(l0, l49, l8);
        vader_array_t* _a23_arr = vader_array_new(452u, 0u, 13u, 2549u);
        l51 = (void*) _a23_arr;
        vader_struct_vader_emit_c_ast$CBlock_t* _a24_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
        vader_obj_header_init(_a24_obj, 1413u);
        _a24_obj->f_body = l48;
        l52 = (void*) _a24_obj;
        vader_struct_vader_emit_c_ast$CFunction_t* _a25_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
        vader_obj_header_init(_a25_obj, 1430u);
        _a25_obj->f_signature = l50;
        _a25_obj->f_prologue = l51;
        _a25_obj->f_body = l52;
        l53 = (void*) _a25_obj;
        vader_array_push_ref((vader_array_t*) l3, l53);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a26_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a26_arr->buf)[vader_array_offset(_a26_arr) + 0u] = vader_box_string(576u, 3527u);
    t6 = (void*) _a26_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a27_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a27_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(453u, 0u, 13u, 2553u);
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
        vader_obj_header_init(_a2_obj, 1448u);
        _a2_obj->f_signature = t1;
        l9 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l9);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a3_arr->buf)[vader_array_offset(_a3_arr) + 0u] = vader_box_string(576u, 3528u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 1451u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_emit_c$StructOffsets_t* _a3_obj = (vader_struct_vader_emit_c$StructOffsets_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StructOffsets_t));
    vader_obj_header_init(_a3_obj, 1408u);
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
    if (l0.tag == 1403u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 1405u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
        l2 = t1 == l1;
    } else if (l0.tag == 1407u) {
        l2 = false;
    } else {
        if (!(l0.tag == 1404u)) {
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
    vader_obj_header_init(_a0_obj, 1444u);
    _a0_obj->f_type = 3524u;
    _a0_obj->f_name = 2317u;
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
    if (!(l6.tag == 1189u)) {
        t0 = vader_emit_c_ast$verbatim(528u);
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
    vader_obj_header_init(_a0_obj, 1453u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline = false;
    _a0_obj->f_result = 3395u;
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
    vader_obj_header_init(_a0_obj, 1427u);
    _a0_obj->f_expression = l1;
    l2 = (void*) _a0_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
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
    if (l0.tag == 1407u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c$StackTemporary_t*) t0)->f_temporary;
        l1 = vader_ref_box(t1);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1404u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_expression;
    } else if (l0.tag == 1405u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
        vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
        vader_obj_header_init(_a0_obj, 1439u);
        _a0_obj->f_slot = t2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1403u)) {
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
    return 2191u;
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
    vader_array_t* _a0_arr = vader_array_reserve(245u, (int64_t) t0, 13u, 1444u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params));
    while ((l3 < l4)) {
        t1 = vader_emit_c$extern_parameter_type(l0, l1, l3);
        vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a1_obj, 1444u);
        _a1_obj->f_type = t1;
        _a1_obj->f_name = 0u;
        l5 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        l3 = (l3 + INT64_C(1));
    }
    l6 = vader_emit_c$extern_result_type(l0, l1);
    l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    vader_struct_vader_emit_c_ast$CSignature_t* _a2_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a2_obj, 1453u);
    _a2_obj->f_storage = (uint8_t) 2;
    _a2_obj->f_inline = false;
    _a2_obj->f_result = l6;
    _a2_obj->f_name = l7;
    _a2_obj->f_parameters = l2;
    t2 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
    vader_obj_header_init(_a3_obj, 1448u);
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
            t1 = vader_emit_c$pointer_to(3523u, l4);
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
        { vader_gc_top = gc_frame.prev; return 3524u; }
    }
    l6 = vader_core_bytecode$param_c_type(l0, l2);
    if (l6.tag == 0u) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t3 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l2, 581u);
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
        { vader_gc_top = gc_frame.prev; return 3524u; }
    }
    t0 = vader_emit_c$is_abi_nullable_string(l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return 2191u; }
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
    vader_obj_header_init(_a0_obj, 1423u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    l4 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a1_obj, 1432u);
    _a1_obj->f_storage = (uint8_t) 2;
    _a1_obj->f_constant = l3;
    _a1_obj->f_type = l0;
    _a1_obj->f_declarator = l4;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$field_c_name(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_2(2394u, l0);
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
    l3 = concat_2(l0, 411u);
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
            if (t1.tag == 1185u) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
            if (t1.tag == 1185u) {
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
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 579u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l3 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    if (l3.tag == 1189u) {
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
            if (l7.tag == 1189u) {
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

static int32_t vader_emit_c$find_main(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    void* l4;
    vader_string_t t0;
    int64_t t1;
    bool t2;
    if (l1 != 0u) {
        l2 = INT64_C(0);
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
        while ((l2 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
            t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
            if (t0 == l1) {
                t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body));
                if ((t1 > INT64_C(0))) {
                    return ((int32_t) (int64_t) l2);
                }
            }
            l2 = (l2 + INT64_C(1));
        }
    }
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
        t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
        if (t2) {
            t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body));
            if ((t1 > INT64_C(0))) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
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
    if (l1 == 2605u) {
        { vader_gc_top = gc_frame.prev; return 1217u; }
    }
    if (l1 == 470u) {
        { vader_gc_top = gc_frame.prev; return 367u; }
    }
    if (l1 == 2826u) {
        { vader_gc_top = gc_frame.prev; return 1218u; }
    }
    t0 = std_string$string$std_core$Contains$contains(l1, 471u);
    if (t0) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$string$std_core$Contains$contains(l1, 2265u);
    if (!(t0)) {
        t1 = concat_2(l1, 479u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        if (l5.tag == 1186u) {
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
        vader_obj_header_init(_a2_obj, 1445u);
        _a2_obj->f_inner = t3;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_emit_c_ast$verbatim(528u);
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
    vader_obj_header_init(_a0_obj, 630u);
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
    l3 = std_core$write_string_at(l5, l3, 2082u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l5, l3, l4);
    l3 = std_core$write_string_at(l5, l3, 455u);
    t1 = std_core$finish_buffer(l5, l3);
    vader_host_std_core$Intrinsic$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_emit_c$foreign_depth(uint8_t l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c_ast$verbatim(3433u);
    l2 = vader_emit_c_ast$number(INT64_C(1));
    vader_struct_vader_emit_c_ast$CAssign_t* _a0_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
    vader_obj_header_init(_a0_obj, 1411u);
    _a0_obj->f_target = l1;
    _a0_obj->f_value = l2;
    _a0_obj->f_operator = vader_box_i32(581u, (int32_t)(uint32_t) l0);
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
        t1 = concat_3(735u, l1, 1613u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 736u; }
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
    { vader_gc_top = gc_frame.prev; return 1244u; }
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
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
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(576u, l5));
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    l2 = (void*) &vader_fn_static_std_string$compare_ascending;
    t0 = std_sort$sort__string(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$forward_boxed(vader_string_t l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l8 = vader_box_null();
    uint8_t l4;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l8 };
    void** gc_raw_roots[6] = { &l1, &l2, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c_ast$call(l0, l1);
    l4 = vader_core_bytecode$bc_single_result(l2);
    if (l4 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 1427u);
        _a0_obj->f_expression = l3;
        l5 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(239u, 0u, 13u, 1411u);
        l6 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l7 = (void*) _a2_arr;
        l8 = vader_emit_c_ast$call(3392u, l7);
        vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a3_obj, 1449u);
        _a3_obj->f_stores = l6;
        _a3_obj->f_value = l8;
        _a3_obj->f_snapshot_type = 0u;
        _a3_obj->f_pops_frame = false;
        l6 = (void*) _a3_obj;
        vader_array_t* _a4_arr = vader_array_new(452u, 2u, 13u, 2549u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l6;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l5;
        t0 = (void*) _a4_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(17)) {
        l8 = l3;
    } else if (l4 == INT32_C(16)) {
        l8 = vader_emit_c$ref_box(l3);
    } else {
        l9 = vader_core_bytecode$bc_single_result_type(l2);
        l8 = vader_emit_c$box_expr(l3, l4, l9);
    }
    vader_array_t* _a5_arr = vader_array_new(239u, 0u, 13u, 1411u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a6_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a6_obj, 1449u);
    _a6_obj->f_stores = t0;
    _a6_obj->f_value = l8;
    _a6_obj->f_snapshot_type = 0u;
    _a6_obj->f_pops_frame = false;
    t0 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(452u, 1u, 13u, 2549u);
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0;
    t0 = (void*) _a7_arr;
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
    l3 = vader_emit_c_ast$verbatim(2953u);
    l4 = vader_emit_c_ast$verbatim(2913u);
    l5 = vader_core_bytecode$bc_single_result_type(l0);
    t0 = vader_core_bytecode$bc_single_result(l0);
    if (t0 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 1427u);
        _a0_obj->f_expression = l2;
        l6 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(452u, 0u, 13u, 2549u);
        l7 = (void*) _a1_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a2_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a2_obj, 1397u);
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
        l10 = vader_emit_c_ast$declaration(3524u, 2953u, l2);
        vader_array_t* _a3_arr = vader_array_new(452u, 0u, 13u, 2549u);
        l6 = (void*) _a3_arr;
        l9 = vader_emit_c$null_or(l3, l9);
        vader_struct_vader_emit_c$ForwardedResult_t* _a4_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a4_obj, 1397u);
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
        l9 = vader_emit_c_ast$cast(2617u, l9);
        l9 = vader_emit_c$box_call(2543u, l8, l9);
        l10 = vader_emit_c_ast$declaration(2191u, 2953u, l2);
        l9 = vader_emit_c$null_or(l3, l9);
        t3 = vader_emit_c_ast$declaration(3395u, 2913u, l9);
        vader_array_t* _a5_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t3.payload.obj;
        l6 = (void*) _a5_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a6_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a6_obj, 1397u);
        _a6_obj->f_capture = l10;
        _a6_obj->f_settle = l6;
        _a6_obj->f_returned = l4;
        t1 = (void*) _a6_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$bc_single_result(l0);
    if (t0 == INT32_C(12)) {
        l9 = vader_emit_c_ast$verbatim(305u);
        l10 = vader_emit_c_ast$number(INT64_C(0));
        vader_array_t* _a7_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = l10.payload.obj;
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l9.payload.obj;
        l6 = (void*) _a7_arr;
        l9 = vader_emit_c_ast$call(3388u, l6);
        t1 = (void*) &vader_data_68;
        vader_array_t* _a8_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l6 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) INT64_C(0));
        l10 = vader_emit_c_ast$binary((uint8_t) 11, l3, vader_ref_box(l6));
        l11 = vader_emit_c$interned(l3);
        vader_struct_vader_emit_c_ast$CConditional_t* _a9_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
        vader_obj_header_init(_a9_obj, 1420u);
        _a9_obj->f_condition = l10;
        _a9_obj->f_then_value = l9;
        _a9_obj->f_else_value = l11;
        l6 = (void*) _a9_obj;
        l9 = vader_emit_c_ast$declaration(2191u, 2953u, l2);
        t3 = vader_emit_c_ast$declaration(3482u, 2913u, vader_ref_box(l6));
        vader_array_t* _a10_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t3.payload.obj;
        l6 = (void*) _a10_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a11_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a11_obj, 1397u);
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
        l4 = vader_emit_c_ast$declaration(t4, 2953u, l2);
        vader_array_t* _a12_arr = vader_array_new(452u, 0u, 13u, 2549u);
        l6 = (void*) _a12_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a13_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a13_obj, 1397u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3357u, l2);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l4 = INT64_C(0);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l2, l4, l5);
    l4 = std_core$write_string_at(l2, l4, 3263u);
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
            if (l10.tag == 1222u) {
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
                l16 = std_core$write_string_at(l4, l16, 312u);
                l17 = ((int64_t) (int32_t) l13);
                l16 = std_core$write_int(l4, l16, l17);
                l16 = std_core$write_string_at(l4, l16, 16u);
                l16 = std_core$write_string_at(l4, l16, l14);
                l18 = std_core$finish_buffer(l4, l16);
                vader_emit_c$directive(l3, l18);
                t1 = l11.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_line;
                t1 = l11.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_file;
            }
        }
        if (l10.tag == 1211u) {
            l19 = true;
        } else {
            l19 = l10.tag == 1212u;
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
                if (t4.tag == 1222u) {
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
            vader_obj_header_init(_a3_obj, 1462u);
            _a3_obj->f_text = 3440u;
            l5 = (void*) _a3_obj;
            vader_struct_vader_emit_c_ast$CVerbatim_t* _a4_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
            vader_obj_header_init(_a4_obj, 1462u);
            _a4_obj->f_text = 2480u;
            l25 = (void*) _a4_obj;
            vader_struct_vader_emit_c_ast$CAssign_t* _a5_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
            vader_obj_header_init(_a5_obj, 1411u);
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
    vader_array_t* _a6_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l25 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l26 = (void*) _a8_arr;
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        l27 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params;
        l8 = INT64_C(0);
        l9 = vader_array_length(((vader_array_t*) l27));
        while ((l8 < l9)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t4 = vader_array_read_u8(_a9_slotarr, vader_array_offset(_a9_slotarr) + (size_t) l8, 581u);
            if (((int32_t) t4.payload.i) == INT32_C(16)) {
                vader_struct_vader_emit_c_ast$CLocal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                vader_obj_header_init(_a10_obj, 1439u);
                _a10_obj->f_slot = ((int32_t) (int64_t) l8);
                t1 = (void*) _a10_obj;
                l10 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                vader_array_push_ref((vader_array_t*) l25, l10.payload.obj);
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l27);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                t4 = vader_array_read_u8(_a11_slotarr, vader_array_offset(_a11_slotarr) + (size_t) l8, 581u);
                if (((int32_t) t4.payload.i) == INT32_C(12)) {
                    vader_struct_vader_emit_c_ast$CLocal_t* _a12_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                    vader_obj_header_init(_a12_obj, 1439u);
                    _a12_obj->f_slot = ((int32_t) (int64_t) l8);
                    t1 = (void*) _a12_obj;
                    l11 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                    vader_array_push_ref((vader_array_t*) l26, l11.payload.obj);
                } else {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l27);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    t4 = vader_array_read_u8(_a13_slotarr, vader_array_offset(_a13_slotarr) + (size_t) l8, 581u);
                    t0 = vader_emit_c$is_ref_val(((uint8_t) t4.payload.i));
                    if (t0) {
                        vader_struct_vader_emit_c_ast$CLocal_t* _a14_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                        vader_obj_header_init(_a14_obj, 1439u);
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
    vader_array_t* _a15_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l27 = (void*) _a15_arr;
    l12 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    vader_emit_c$emit_local_decls(l2, l27, l5, l25, l26, l12);
    l12 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    vader_emit_c$emit_temporary_declarations(l4, l27, l5, l25, l26, l12);
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        t5 = vader_array_length(((vader_array_t*) l5));
        if ((t5 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3396u, 2482u, l5);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        t5 = vader_array_length(((vader_array_t*) l25));
        if ((t5 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3525u, 2481u, l25);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        t5 = vader_array_length(((vader_array_t*) l5));
        if ((t5 > INT64_C(0))) {
            l7 = 2482u;
        } else {
            l7 = 866u;
        }
        t5 = vader_array_length(((vader_array_t*) l25));
        if ((t5 > INT64_C(0))) {
            l14 = 2481u;
        } else {
            l14 = 866u;
        }
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages));
        if ((l8 > INT64_C(0))) {
            l18 = 2483u;
        } else {
            l18 = 866u;
        }
        t5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages));
        vader_array_t* _a16_arr = vader_array_reserve(451u, (int64_t) t5, 13u, 2544u);
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
            l10 = vader_emit_c_ast$verbatim(3594u);
            l11 = vader_emit_c_ast$declaration(l30, l31, l10);
            vader_array_push_ref((vader_array_t*) l27, l11.payload.obj);
            t3 = ((vader_struct_vader_emit_c$StackStorage_t*) l29)->f_storage;
            t4 = vader_emit_c_ast$verbatim(t3);
            l23 = vader_emit_c_ast$address_of(t4);
            l32 = vader_emit_c_ast$cast(3524u, l23);
            vader_array_push_ref((vader_array_t*) l4, l32.payload.obj);
            l15 = (l15 + INT64_C(1));
        }
        if ((l8 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3524u, 2483u, l4);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        l9 = vader_array_length(((vader_array_t*) l26));
        if ((l9 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3483u, 2478u, l26);
            vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        }
        l10 = vader_emit_c_ast$verbatim(3440u);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l15 = INT64_C(0);
        l16 = vader_array_length(((vader_array_t*) l5));
        l15 = std_core$write_int(l4, l15, l16);
        l15 = std_core$write_string_at(l4, l15, 3263u);
        t3 = std_core$finish_buffer(l4, l15);
        l11 = vader_emit_c_ast$verbatim(t3);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l15 = INT64_C(0);
        l16 = vader_array_length(((vader_array_t*) l25));
        l15 = std_core$write_int(l4, l15, l16);
        l15 = std_core$write_string_at(l4, l15, 3263u);
        t3 = std_core$finish_buffer(l4, l15);
        l23 = vader_emit_c_ast$verbatim(t3);
        l32 = vader_emit_c_ast$verbatim(l7);
        l33 = vader_emit_c_ast$verbatim(l14);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l15 = INT64_C(0);
        l15 = std_core$write_int(l4, l15, l8);
        l15 = std_core$write_string_at(l4, l15, 3263u);
        t3 = std_core$finish_buffer(l4, l15);
        l34 = vader_emit_c_ast$verbatim(t3);
        l35 = vader_emit_c_ast$verbatim(l18);
        vader_array_t* _a18_arr = vader_array_new(451u, 7u, 13u, 2544u);
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
            l8 = std_core$write_string_at(l5, l8, 3263u);
            t3 = std_core$finish_buffer(l5, l8);
            l10 = vader_emit_c_ast$verbatim(t3);
            l11 = vader_emit_c_ast$verbatim(2478u);
            vader_array_t* _a19_arr = vader_array_new(451u, 2u, 13u, 2544u);
            ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 1u] = l11.payload.obj;
            ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = l10.payload.obj;
            l5 = (void*) _a19_arr;
            vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l5);
        }
        vader_struct_vader_emit_c_ast$CInitializerList_t* _a20_obj = (vader_struct_vader_emit_c_ast$CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInitializerList_t));
        vader_obj_header_init(_a20_obj, 1437u);
        _a20_obj->f_elements = l4;
        l4 = (void*) _a20_obj;
        l10 = vader_emit_c_ast$declaration(3437u, 2479u, vader_ref_box(l4));
        vader_array_push_ref((vader_array_t*) l27, l10.payload.obj);
        l10 = vader_emit_c_ast$verbatim(3440u);
        t4 = vader_emit_c_ast$verbatim(2479u);
        l11 = vader_emit_c_ast$address_of(t4);
        vader_struct_vader_emit_c_ast$CAssign_t* _a21_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a21_obj, 1411u);
        _a21_obj->f_target = l10;
        _a21_obj->f_value = l11;
        _a21_obj->f_operator = vader_box_obj(0u, NULL);
        l4 = (void*) _a21_obj;
        vader_array_push_ref((vader_array_t*) l27, l4);
    }
    l4 = vader_emit_c$signature_for(l0, l1);
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root;
    vader_struct_vader_emit_c_ast$CFunction_t* _a22_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a22_obj, 1430u);
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
    l1 = concat_2(l0, 411u);
    t0 = concat_3(3040u, l0, 377u);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3434u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(239u, 0u, 13u, 1411u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l2 = (void*) _a1_arr;
    t0 = vader_emit_c_ast$call(3438u, l2);
    vader_struct_vader_emit_c_ast$CMember_t* _a2_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a2_obj, 1441u);
    _a2_obj->f_base = t0;
    _a2_obj->f_member = l0;
    _a2_obj->f_arrow = false;
    l2 = (void*) _a2_obj;
    l3 = vader_emit_c_ast$cast(2617u, vader_ref_box(l2));
    vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a3_obj, 1449u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals));
    while ((l3 < l4)) {
        l5 = ((int32_t) (int64_t) l3);
        t0 = vader_emit_c$global_slot_val(l0, l5);
        if (t0 == l1) {
            l6 = (void*) vader_buffer_new((size_t) INT64_C(33));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l6, l7, 3441u);
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
        if (l4.tag == 1188u) {
            return true;
        }
        if (l4.tag == 1175u) {
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
    t0 = concat_2(3446u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    t0 = vader_emit_c$shim_body(l1, l4);
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1413u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CFunction_t* _a2_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a2_obj, 1430u);
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
    t0 = std_string$ends_with(l0, 508u);
    if (!(t0)) {
        t1 = concat_2(l0, 493u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = std_core$len_1(l0);
    l1 = vader_chk_sub(i64, t2, INT64_C(8));
    vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
    vader_obj_header_init(_a0_obj, 998u);
    _a0_obj->f_start = INT64_C(0);
    _a0_obj->f_end = l1;
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = INT64_C(0);
    l2 = (void*) _a0_obj;
    t1 = std_core$string$Index$at$1(l0, l2);
    t3 = concat_2(t1, 493u);
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
    vader_array_t* _a0_arr = vader_array_reserve(24u, (int64_t) t0, 12u, 574u);
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
    vader_obj_header_init(_a0_obj, 629u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(104u, 0u, 13u, 1182u);
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
        vader_obj_header_init(_a0_obj, 998u);
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
        t1 = std_string$starts_with(l0, 584u);
        if (t1) {
            t1 = std_string$ends_with(l0, 606u);
            if (t1) {
                vader_struct_vader_emit_c_ast$CInclude_t* _a1_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
                vader_obj_header_init(_a1_obj, 1435u);
                _a1_obj->f_path = l2;
                _a1_obj->f_system = true;
                t2 = (void*) _a1_obj;
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l1) {
        t1 = std_string$starts_with(l0, 303u);
        if (t1) {
            t1 = std_string$ends_with(l0, 303u);
            if (t1) {
                vader_struct_vader_emit_c_ast$CInclude_t* _a2_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
                vader_obj_header_init(_a2_obj, 1435u);
                _a2_obj->f_path = l2;
                _a2_obj->f_system = false;
                t2 = (void*) _a2_obj;
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l1 = false;
            vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
            vader_obj_header_init(_a3_obj, 1435u);
            _a3_obj->f_path = l0;
            _a3_obj->f_system = l1;
            t2 = (void*) _a3_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l1 = false;
        vader_struct_vader_emit_c_ast$CInclude_t* _a4_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
        vader_obj_header_init(_a4_obj, 1435u);
        _a4_obj->f_path = l0;
        _a4_obj->f_system = l1;
        t2 = (void*) _a4_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = false;
    vader_struct_vader_emit_c_ast$CInclude_t* _a5_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a5_obj, 1435u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1010u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a2_obj, 1447u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l1 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a3_obj, 1435u);
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
    l3 = std_core$write_string_at(l2, l3, 1179u);
    l3 = std_core$write_int(l2, l3, l0);
    l3 = std_core$write_string_at(l2, l3, 1192u);
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
    l5 = std_core$write_string_at(l4, l5, 3263u);
    t0 = std_core$finish_buffer(l4, l5);
    l7 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3447u, l4);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$integer_as_address(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c_ast$cast(2633u, l0);
    t0 = vader_emit_c_ast$cast(3524u, l1);
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
    vader_obj_header_init(_a0_obj, 1417u);
    _a0_obj->f_types = l0;
    _a0_obj->f_value = l1;
    l2 = (void*) _a0_obj;
    t0 = vader_emit_c_ast$designated(492u, vader_ref_box(l2));
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
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 579u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 1u, 12u, 574u);
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
    vader_array_t* _a22_arr = vader_array_reserve(24u, (int64_t) l6, 12u, 574u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3098u, l1);
    vader_array_t* _a1_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l2.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a1_arr;
    t0 = vader_emit_c_ast$call(3388u, l1);
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
    if (l1.tag == 1294u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        vader_emit_c$drop_bound_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1295u) {
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
        return t1.tag == 1176u;
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
    if (!(l3.tag == 1190u)) {
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
                if (l3.tag == 1186u) {
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
    if (!(l3.tag == 1190u)) {
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
                if (l3.tag == 1186u) {
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
    if ((l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1319u || l0.tag == 1336u)) {
        return true;
    }
    if ((l0.tag == 1288u || l0.tag == 1289u || l0.tag == 1290u)) {
        return true;
    }
    if ((l0.tag == 1311u || l0.tag == 1312u || l0.tag == 1313u)) {
        return true;
    }
    if ((l0.tag == 1165u || l0.tag == 1166u || l0.tag == 1173u)) {
        return true;
    }
    if ((l0.tag == 1285u || l0.tag == 1286u || l0.tag == 1287u || l0.tag == 1291u)) {
        return true;
    }
    if ((l0.tag == 1308u || l0.tag == 1309u || l0.tag == 1310u || l0.tag == 1314u)) {
        return true;
    }
    if ((l0.tag == 1199u || l0.tag == 1214u || l0.tag == 1227u || l0.tag == 1248u || l0.tag == 1268u)) {
        return true;
    }
    if ((l0.tag == 1218u || l0.tag == 1240u || l0.tag == 1300u || l0.tag == 1307u || l0.tag == 1316u || l0.tag == 1323u)) {
        return true;
    }
    if ((l0.tag == 1243u || l0.tag == 1249u || l0.tag == 1255u || l0.tag == 1256u || l0.tag == 1258u || l0.tag == 1262u)) {
        return true;
    }
    if ((l0.tag == 1263u || l0.tag == 1269u || l0.tag == 1275u || l0.tag == 1276u || l0.tag == 1278u || l0.tag == 1282u)) {
        return true;
    }
    if ((l0.tag == 1215u || l0.tag == 1216u)) {
        return true;
    }
    if ((l0.tag == 1226u || l0.tag == 1228u || l0.tag == 1234u || l0.tag == 1236u || l0.tag == 1237u)) {
        return true;
    }
    if ((l0.tag == 1324u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1335u)) {
        return true;
    }
    if ((l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1246u || l0.tag == 1247u || l0.tag == 1259u || l0.tag == 1260u || l0.tag == 1261u)) {
        return true;
    }
    if ((l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1279u || l0.tag == 1280u || l0.tag == 1281u)) {
        return true;
    }
    if ((l0.tag == 1250u || l0.tag == 1251u || l0.tag == 1252u || l0.tag == 1253u || l0.tag == 1254u || l0.tag == 1257u)) {
        return true;
    }
    if ((l0.tag == 1270u || l0.tag == 1271u || l0.tag == 1272u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1277u)) {
        return true;
    }
    if ((l0.tag == 1229u || l0.tag == 1230u || l0.tag == 1231u || l0.tag == 1232u || l0.tag == 1233u || l0.tag == 1235u)) {
        return true;
    }
    if ((l0.tag == 1325u || l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1333u || l0.tag == 1334u)) {
        return true;
    }
    if ((l0.tag == 1200u || l0.tag == 1201u)) {
        return true;
    }
    if ((l0.tag == 1302u || l0.tag == 1303u || l0.tag == 1315u || l0.tag == 1317u || l0.tag == 1318u)) {
        return true;
    }
    if ((l0.tag == 1198u || l0.tag == 1202u || l0.tag == 1203u)) {
        return true;
    }
    if ((l0.tag == 1195u || l0.tag == 1196u || l0.tag == 1217u || l0.tag == 1225u || l0.tag == 1238u || l0.tag == 1301u || l0.tag == 1304u)) {
        return true;
    }
    if (!(l0.tag == 1222u)) {
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
    if ((l0.tag == 1292u || l0.tag == 1293u)) {
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
    return (l0.tag == 1197u || l0.tag == 1283u || l0.tag == 1296u);
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
            if (t0.tag == 1222u) {
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3484u, l2);
    l3 = vader_emit_c_ast$declaration(2191u, 2074u, l3);
    t0 = vader_emit_c_ast$verbatim(2074u);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(l0, l2);
    l4 = vader_emit_c_ast$declaration(3524u, 2953u, l4);
    l5 = vader_emit_c_ast$verbatim(2074u);
    vader_array_t* _a2_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l5.payload.obj;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l1.payload.obj;
    l2 = (void*) _a2_arr;
    l5 = vader_emit_c_ast$perform(3412u, l2);
    vader_array_t* _a3_arr = vader_array_new(239u, 0u, 13u, 1411u);
    l2 = (void*) _a3_arr;
    t0 = vader_emit_c_ast$verbatim(2953u);
    l6 = vader_emit_c$address_as_integer(t0);
    vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a4_obj, 1449u);
    _a4_obj->f_stores = l2;
    _a4_obj->f_value = l6;
    _a4_obj->f_snapshot_type = 0u;
    _a4_obj->f_pops_frame = false;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(452u, 4u, 13u, 2549u);
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
    t0 = concat_2(1245u, l1);
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
    l3 = concat_2(3427u, l1);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    t1 = vader_emit_c$erased_wrapper_signature(l0, l3, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$lift_unbox_tail(void* l0) {
    int64_t l1, l3, l5, l6;
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    uint8_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l9, &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    if ((INT64_C(1) < l1)) {
        t0 = vader_array_length(((vader_array_t*) l0));
        l1 = (t0 - INT64_C(1));
    } else {
        l1 = INT64_C(0);
    }
    vader_array_t* _a0_arr = vader_array_reserve(451u, (int64_t) l1, 13u, 2544u);
    l2 = (void*) _a0_arr;
    l1 = INT64_C(1);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l1 < l3)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1722u);
        l6 = vader_chk_sub(i64, l1, INT64_C(1));
        l5 = std_core$write_int(l4, l5, l6);
        t1 = std_core$finish_buffer(l4, l5);
        l7 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l1, 581u);
        l8 = ((uint8_t) t2.payload.i);
        l9 = vader_emit_c$unbox_expr(l7, l8);
        vader_array_push_ref((vader_array_t*) l2, l9.payload.obj);
        l1 = (l1 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$literal_within(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    bool l3;
    void* t0;
    int64_t t1;
    if (!(l0.tag == 1404u)) {
        return false;
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_expression;
    if (l2.tag == 1438u) {
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
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    int32_t l5, l10;
    bool l6;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t* gc_roots[5] = { &l2, &l7, &l12, &l13, &t0 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l8, &l9, &l11 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$verbatim(1919u);
    t0 = vader_emit_c_ast$cast(3523u, l2);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 1427u);
    _a0_obj->f_expression = t0;
    l3 = (void*) _a0_obj;
    l2 = vader_emit_c_ast$verbatim(1923u);
    t0 = vader_emit_c_ast$cast(3523u, l2);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 1427u);
    _a1_obj->f_expression = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(452u, 2u, 13u, 2549u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l3;
    l3 = (void*) _a2_arr;
    l5 = vader_emit_c$find_main(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, l1);
    if ((l5 < INT32_C(0))) {
        vader_array_t* _a3_arr = vader_array_new(239u, 0u, 13u, 1411u);
        l4 = (void*) _a3_arr;
        l2 = vader_emit_c_ast$number(INT64_C(0));
        vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a4_obj, 1449u);
        _a4_obj->f_stores = l4;
        _a4_obj->f_value = l2;
        _a4_obj->f_snapshot_type = 0u;
        _a4_obj->f_pops_frame = false;
        l4 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l3, l4);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature)->f_params));
    l6 = t1 == INT64_C(1);
    l2 = vader_emit_c_ast$verbatim(3385u);
    l7 = vader_emit_c_ast$verbatim(1138u);
    vader_array_t* _a6_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l7.payload.obj;
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l2.payload.obj;
    l8 = (void*) _a6_arr;
    t0 = vader_emit_c_ast$perform(3387u, l8);
    vader_array_t* _a7_arr = vader_array_new(452u, 1u, 13u, 2549u);
    ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0.payload.obj;
    l8 = (void*) _a7_arr;
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals));
    if ((t1 > INT64_C(0))) {
        l2 = vader_emit_c_ast$verbatim(3440u);
        t0 = vader_emit_c_ast$verbatim(3444u);
        l7 = vader_emit_c_ast$address_of(t0);
        vader_struct_vader_emit_c_ast$CAssign_t* _a8_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a8_obj, 1411u);
        _a8_obj->f_target = l2;
        _a8_obj->f_value = l7;
        _a8_obj->f_operator = vader_box_obj(0u, NULL);
        l9 = (void*) _a8_obj;
        vader_array_push_ref((vader_array_t*) l8, l9);
    }
    t0 = vader_emit_c_ast$verbatim(3389u);
    vader_array_t* _a9_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0.payload.obj;
    l9 = (void*) _a9_arr;
    l2 = vader_emit_c_ast$perform(1979u, l9);
    vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
    t0 = vader_emit_c_ast$verbatim(3439u);
    vader_array_t* _a10_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t0.payload.obj;
    l9 = (void*) _a10_arr;
    l2 = vader_emit_c_ast$perform(1979u, l9);
    vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
    vader_array_t* _a11_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l9 = (void*) _a11_arr;
    if (l6) {
        l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_string_tag;
        l10 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_string_array_tag;
        if ((l5 < INT32_C(0))) {
            l6 = true;
        } else {
            l6 = (l10 < INT32_C(0));
        }
        if (l6) {
            vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l3);
            l2 = vader_emit_c$trap(2755u);
            vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
            vader_array_t* _a12_arr = vader_array_new(239u, 0u, 13u, 1411u);
            l11 = (void*) _a12_arr;
            l2 = vader_emit_c_ast$number(INT64_C(1));
            vader_struct_vader_emit_c_ast$CReturn_t* _a13_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a13_obj, 1449u);
            _a13_obj->f_stores = l11;
            _a13_obj->f_value = l2;
            _a13_obj->f_snapshot_type = 0u;
            _a13_obj->f_pops_frame = false;
            l11 = (void*) _a13_obj;
            vader_array_push_ref((vader_array_t*) l8, l11);
            { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_emit_c_ast$verbatim(1919u);
        l7 = vader_emit_c_ast$verbatim(1923u);
        l12 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l10));
        l13 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l5));
        vader_array_t* _a14_arr = vader_array_new(451u, 4u, 13u, 2544u);
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 3u] = l13.payload.obj;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 2u] = l12.payload.obj;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l7.payload.obj;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l2.payload.obj;
        l11 = (void*) _a14_arr;
        l2 = vader_emit_c_ast$call(3452u, l11);
        vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a15_slotarr, vader_array_offset(_a15_slotarr) + (size_t) INT32_C(0), 581u);
        if (((int32_t) t0.payload.i) == INT32_C(16)) {
            l7 = vader_emit_c_ast$cast(3524u, l2);
            l7 = vader_emit_c_ast$declaration(3524u, 1216u, l7);
            vader_array_push_ref((vader_array_t*) l8, l7.payload.obj);
        } else {
            t0 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l10));
            vader_array_t* _a16_arr = vader_array_new(451u, 2u, 13u, 2544u);
            ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 1u] = l2.payload.obj;
            ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0.payload.obj;
            l11 = (void*) _a16_arr;
            l2 = vader_emit_c_ast$call(3393u, l11);
            l2 = vader_emit_c_ast$declaration(3395u, 1216u, l2);
            vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
        }
        l2 = vader_emit_c_ast$verbatim(1216u);
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
        vader_obj_header_init(_a17_obj, 1427u);
        _a17_obj->f_expression = l2;
        l3 = (void*) _a17_obj;
        vader_array_push_ref((vader_array_t*) l8, l3);
        vader_array_t* _a18_arr = vader_array_new(239u, 0u, 13u, 1411u);
        l3 = (void*) _a18_arr;
        t0 = vader_emit_c_ast$number(INT64_C(0));
        vader_array_t* _a19_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0.payload.obj;
        l4 = (void*) _a19_arr;
        l7 = vader_emit_c_ast$call(3455u, l4);
        vader_struct_vader_emit_c_ast$CReturn_t* _a20_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a20_obj, 1449u);
        _a20_obj->f_stores = l3;
        _a20_obj->f_value = l7;
        _a20_obj->f_snapshot_type = 0u;
        _a20_obj->f_pops_frame = false;
        l3 = (void*) _a20_obj;
        vader_array_push_ref((vader_array_t*) l8, l3);
        { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a21_arr = vader_array_new(239u, 0u, 13u, 1411u);
    l3 = (void*) _a21_arr;
    t0 = vader_emit_c_ast$cast(2614u, l2);
    vader_array_t* _a22_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t0.payload.obj;
    l4 = (void*) _a22_arr;
    l2 = vader_emit_c_ast$call(3455u, l4);
    vader_struct_vader_emit_c_ast$CReturn_t* _a23_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a23_obj, 1449u);
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
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$val_of(l1);
    l3 = vader_emit_c$new_temporary(l0, l2);
    l4 = vader_emit_c$expression_of(l1);
    vader_emit_c$assign(l0, vader_ref_box(l3), l4);
    vader_struct_vader_emit_c$StackTemporary_t* _a0_obj = (vader_struct_vader_emit_c$StackTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackTemporary_t));
    vader_obj_header_init(_a0_obj, 1407u);
    _a0_obj->f_temporary = l3;
    _a0_obj->f_val = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
        if (l5.tag == 1179u) {
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
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 579u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 574u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 814u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__i32_t* _a4_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a4_obj, 988u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 579u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 12u, 574u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 579u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a8_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a8_obj, 814u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$Set__i32_t* _a9_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a9_obj, 988u);
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
    vader_obj_header_init(_a12_obj, 1398u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l6 = (void*) _a2_arr;
    l7 = vader_emit_c$push_mirror_allocation(l0, l1, l4, l5, l6, INT32_C(0));
    vader_array_t* _a3_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l8 = (void*) _a3_arr;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l5);
    t0 = vader_array_length(((vader_array_t*) l4));
    if (t0 == INT64_C(1)) {
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
    } else {
        vader_array_t* _a4_arr = vader_array_new(451u, 0u, 13u, 2544u);
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
            l12 = vader_emit_c_ast$cast(3525u, l11);
            vader_array_push_ref((vader_array_t*) l5, l12.payload.obj);
            l10 = (l10 + INT64_C(1));
        }
        l11 = vader_emit_c_ast$verbatim(1233u);
        l12 = vader_emit_c_ast$array_declaration(3525u, 1234u, l5);
        vader_array_push_ref((vader_array_t*) l8, l12.payload.obj);
        t0 = vader_array_length(((vader_array_t*) l5));
        l12 = vader_emit_c_ast$number(t0);
        l13 = vader_emit_c_ast$verbatim(1234u);
        vader_array_t* _a7_arr = vader_array_new(451u, 3u, 13u, 2544u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 2u] = l12.payload.obj;
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = l13.payload.obj;
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = l11.payload.obj;
        l4 = (void*) _a7_arr;
        l12 = vader_emit_c_ast$perform(1140u, l4);
        vader_array_push_ref((vader_array_t*) l8, l12.payload.obj);
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
        vader_array_t* _a8_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l11.payload.obj;
        l4 = (void*) _a8_arr;
        l11 = vader_emit_c_ast$perform(1139u, l4);
        vader_array_push_ref((vader_array_t*) l8, l11.payload.obj);
    }
    l4 = vader_emit_c$bc_struct_fields(l0, l1);
    l11 = vader_emit_c_ast$verbatim(2953u);
    l12 = vader_emit_c_ast$verbatim(l7);
    vader_emit_c$push_member_copies(l0, l4, l11, l12, false, l8, INT32_C(0));
    l11 = vader_emit_c_ast$declaration(l2, 2953u, l3);
    l12 = vader_emit_c_ast$verbatim(l7);
    vader_struct_vader_emit_c$ForwardedResult_t* _a9_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
    vader_obj_header_init(_a9_obj, 1397u);
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
        vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a0_arr;
        l1 = vader_emit_c_ast$perform(3461u, l2);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        l3 = true;
    } else {
        l3 = l0 == INT32_C(13);
    }
    if (l3) {
        t0 = vader_emit_c$argument(INT64_C(0));
        vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        l2 = (void*) _a1_arr;
        l1 = vader_emit_c_ast$perform(3460u, l2);
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
    t0 = vader_emit_c_ast$verbatim(2396u);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l0 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$perform(3458u, l0);
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
    int32_t l4, l11, l12;
    int64_t l6;
    bool l13, l14, l15;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &l9, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$struct_c_names_of(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l4 = vader_emit_c$string_primitive_tag(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types);
    l5 = vader_emit_c$imports_may_collect(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports);
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
    vader_struct___lambda_env_vader_emit_c_2_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_2_t));
    vader_obj_header_init(_a0_obj, 631u);
    _a0_obj->f_cap_0 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 516u);
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
    l12 = vader_emit_c$string_array_tag(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types, l4);
    l10 = vader_emit_c$compute_may_alloc(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions, l5);
    l13 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_split;
    l14 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_verify_bounds;
    l15 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_library_units;
    vader_struct_vader_emit_c$EmitCtx_t* _a2_obj = (vader_struct_vader_emit_c$EmitCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$EmitCtx_t));
    vader_obj_header_init(_a2_obj, 1394u);
    _a2_obj->f_module = l0;
    _a2_obj->f_struct_c_names = l3;
    _a2_obj->f_atom_ids = l8;
    _a2_obj->f_atom_table = l9;
    _a2_obj->f_null_tag = l11;
    _a2_obj->f_string_tag = l4;
    _a2_obj->f_string_array_tag = l12;
    _a2_obj->f_may_alloc = l10;
    _a2_obj->f_import_may_collect = l5;
    _a2_obj->f_split = l13;
    _a2_obj->f_internal_fns = l2;
    _a2_obj->f_verify_bounds = l14;
    _a2_obj->f_library_units = l15;
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
    vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2549u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1413u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(450u, 0u, 13u, 2543u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(246u, 0u, 13u, 1459u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(237u, 0u, 13u, 1401u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 579u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 579u);
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
    vader_array_t* _a8_arr = vader_array_new(236u, 0u, 13u, 1400u);
    l11 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(235u, 0u, 13u, 1390u);
    l12 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(238u, 0u, 13u, 1406u);
    l13 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(455u, 0u, 13u, 2559u);
    l14 = (void*) _a11_arr;
    vader_struct_vader_emit_c$FnState_t* _a12_obj = (vader_struct_vader_emit_c$FnState_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$FnState_t));
    vader_obj_header_init(_a12_obj, 1395u);
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
    vader_obj_header_init(_a0_obj, 1459u);
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
    l2 = concat_2(l0, 411u);
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
    t0 = (void*) &vader_data_68;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l3 = vader_emit_c_ast$binary((uint8_t) 11, l0, vader_ref_box(l2));
    vader_array_t* _a1_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l2 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(3392u, l2);
    vader_struct_vader_emit_c_ast$CConditional_t* _a2_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
    vader_obj_header_init(_a2_obj, 1420u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$call(1147u, l1);
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
    t0 = vader_emit_c$payload(l0, 2880u);
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
    if (l3.tag == 1185u) {
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
    if (l3.tag == 1186u) {
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
    if (l0.tag == 1320u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        l2 = !(t1);
        return l2;
    }
    if (l0.tag == 1212u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
        l2 = t1;
    } else if ((l0.tag == 1167u || l0.tag == 1168u || l0.tag == 1169u || l0.tag == 1171u || l0.tag == 1172u || l0.tag == 1174u || l0.tag == 1206u || l0.tag == 1207u || l0.tag == 1213u || l0.tag == 1239u || l0.tag == 1297u || l0.tag == 1339u)) {
        l2 = true;
    } else if ((l0.tag == 1241u || l0.tag == 1242u)) {
        l2 = false;
    } else {
        if (!((l0.tag == 1163u || l0.tag == 1164u || l0.tag == 1165u || l0.tag == 1166u || l0.tag == 1170u || l0.tag == 1173u || l0.tag == 1195u || l0.tag == 1196u || l0.tag == 1197u || l0.tag == 1198u || l0.tag == 1199u || l0.tag == 1200u || l0.tag == 1201u || l0.tag == 1202u || l0.tag == 1203u || l0.tag == 1204u || l0.tag == 1205u || l0.tag == 1208u || l0.tag == 1211u || l0.tag == 1214u || l0.tag == 1215u || l0.tag == 1216u || l0.tag == 1217u || l0.tag == 1218u || l0.tag == 1220u || l0.tag == 1221u || l0.tag == 1222u || l0.tag == 1223u || l0.tag == 1224u || l0.tag == 1225u || l0.tag == 1226u || l0.tag == 1227u || l0.tag == 1228u || l0.tag == 1229u || l0.tag == 1230u || l0.tag == 1231u || l0.tag == 1232u || l0.tag == 1233u || l0.tag == 1234u || l0.tag == 1235u || l0.tag == 1236u || l0.tag == 1237u || l0.tag == 1238u || l0.tag == 1240u || l0.tag == 1243u || l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1246u || l0.tag == 1247u || l0.tag == 1248u || l0.tag == 1249u || l0.tag == 1250u || l0.tag == 1251u || l0.tag == 1252u || l0.tag == 1253u || l0.tag == 1254u || l0.tag == 1255u || l0.tag == 1256u || l0.tag == 1257u || l0.tag == 1258u || l0.tag == 1259u || l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1262u || l0.tag == 1263u || l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1270u || l0.tag == 1271u || l0.tag == 1272u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1275u || l0.tag == 1276u || l0.tag == 1277u || l0.tag == 1278u || l0.tag == 1279u || l0.tag == 1280u || l0.tag == 1281u || l0.tag == 1282u || l0.tag == 1283u || l0.tag == 1285u || l0.tag == 1286u || l0.tag == 1287u || l0.tag == 1288u || l0.tag == 1289u || l0.tag == 1290u || l0.tag == 1291u || l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1294u || l0.tag == 1295u || l0.tag == 1296u || l0.tag == 1299u || l0.tag == 1300u || l0.tag == 1301u || l0.tag == 1302u || l0.tag == 1303u || l0.tag == 1304u || l0.tag == 1305u || l0.tag == 1306u || l0.tag == 1307u || l0.tag == 1308u || l0.tag == 1309u || l0.tag == 1310u || l0.tag == 1311u || l0.tag == 1312u || l0.tag == 1313u || l0.tag == 1314u || l0.tag == 1315u || l0.tag == 1316u || l0.tag == 1317u || l0.tag == 1318u || l0.tag == 1319u || l0.tag == 1321u || l0.tag == 1322u || l0.tag == 1323u || l0.tag == 1324u || l0.tag == 1325u || l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1333u || l0.tag == 1334u || l0.tag == 1335u || l0.tag == 1336u || l0.tag == 1337u || l0.tag == 1338u))) {
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
    if (!(l3.tag == 1434u)) {
        vader_host_std_core$Intrinsic$panic(2078u);
        vader_unreachable("a no-return call returned");
    }
    l1 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(452u, 0u, 13u, 2549u);
    t1 = (void*) _a1_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a2_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a2_obj, 1413u);
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
    vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2549u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1413u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CIf_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIf_t));
    vader_obj_header_init(_a2_obj, 1434u);
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
    vader_array_t* _a0_arr = vader_array_new(452u, 0u, 13u, 2549u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1413u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CScope_t* _a2_obj = (vader_struct_vader_emit_c_ast$CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CScope_t));
    vader_obj_header_init(_a2_obj, 1450u);
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
    l2 = std_core$write_string_at(l1, l2, 1232u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 587u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any___t* _a3_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
    vader_obj_header_init(_a3_obj, 895u);
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
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 579u);
    t0 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(3u, 1u, 13u, 27u);
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
            vader_array_t* _a9_arr = vader_array_new(27u, 0u, 7u, 579u);
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
    l2 = concat_2(2933u, l1);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 1441u);
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
    vader_obj_header_init(_a0_obj, 1445u);
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
    t0 = vader_emit_c$pc_local(l0, 2514u);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3354u, l1);
    l3 = vader_emit_c_ast$verbatim(528u);
    l3 = vader_emit_c_ast$cast(3038u, l3);
    t0 = vader_emit_c$pc_local(l0, 2514u);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
    l1 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(3351u, l1);
    vader_struct_vader_emit_c_ast$CConditional_t* _a2_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
    vader_obj_header_init(_a2_obj, 1420u);
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
    l4 = std_core$write_string_at(l3, l4, 1250u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1247u);
    l6 = std_core$finish_buffer(l3, l4);
    t0 = ((vader_struct_vader_emit_c$PushCache_t*) l1)->f_slot;
    vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
    vader_obj_header_init(_a0_obj, 1439u);
    _a0_obj->f_slot = t0;
    t1 = (void*) _a0_obj;
    l7 = vader_emit_c$array_pointer(vader_ref_box(t1));
    vader_emit_c$declare(l0, 3383u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1250u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1248u);
    l6 = std_core$finish_buffer(l3, l4);
    t2 = vader_emit_c$pc_local(l2, 2514u);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t2.payload.obj;
    l3 = (void*) _a1_arr;
    l7 = vader_emit_c_ast$call(3355u, l3);
    vader_emit_c$declare(l0, 3038u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1250u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1240u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_capacity(l2);
    vader_emit_c$declare(l0, 3038u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1250u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1253u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_header(l2, 2023u);
    vader_emit_c$declare(l0, 3524u, l6, l7);
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
    l5 = vader_emit_c$pc_local(l4, 2703u);
    l6 = vader_emit_c$pc_local(l4, 2124u);
    t0 = vader_emit_c_ast$binary((uint8_t) 7, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l7 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(1142u, l7);
    vader_emit_c$open_if(l0, l5);
    t1 = vader_emit_c$pc_fill_of(((vader_struct_vader_emit_c$PushCache_t*) l1)->f_kind);
    l8 = ((vader_struct_vader_emit_c$SlotFill_t*) t1)->f_cty;
    l9 = concat_2(l8, 411u);
    l5 = vader_emit_c$pc_local(l4, 3046u);
    t0 = vader_emit_c_ast$cast(l9, l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a1_obj, 1445u);
    _a1_obj->f_inner = t0;
    l7 = (void*) _a1_obj;
    l5 = vader_emit_c$pc_local(l4, 2703u);
    vader_struct_vader_emit_c_ast$CIndex_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a2_obj, 1436u);
    _a2_obj->f_base = vader_ref_box(l7);
    _a2_obj->f_index = l5;
    l7 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a3_obj, 1445u);
    _a3_obj->f_inner = l3;
    l10 = (void*) _a3_obj;
    l5 = vader_emit_c_ast$cast(l8, vader_ref_box(l10));
    vader_emit_c$assign(l0, vader_ref_box(l7), l5);
    l5 = vader_emit_c$pc_local(l4, 2703u);
    l6 = vader_emit_c_ast$verbatim(533u);
    vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
    vader_obj_header_init(_a4_obj, 1411u);
    _a4_obj->f_target = l5;
    _a4_obj->f_value = l6;
    _a4_obj->f_operator = vader_box_i32(581u, INT32_C(3));
    l7 = (void*) _a4_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l7));
    vader_emit_c$open_else(l0);
    vader_emit_c$pc_emit_writeback(l0, l4);
    l8 = vader_emit_c$pc_helper_of(((vader_struct_vader_emit_c$PushCache_t*) l1)->f_kind);
    t0 = vader_emit_c$array_pointer(l2);
    vader_array_t* _a5_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 1u] = l3.payload.obj;
    ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0.payload.obj;
    l7 = (void*) _a5_arr;
    l5 = vader_emit_c_ast$call(l8, l7);
    vader_emit_c$evaluate(l0, l5);
    l5 = vader_emit_c$pc_local(l4, 2514u);
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
    l2 = vader_emit_c$pc_local(l1, 2514u);
    l3 = vader_emit_c$pc_local(l1, 2703u);
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(3380u, l4);
    vader_emit_c$evaluate(l0, l2);
    l2 = vader_emit_c$pc_header(l1, 2022u);
    l3 = vader_emit_c$pc_local(l1, 2703u);
    l2 = vader_emit_c_ast$binary((uint8_t) 7, l2, l3);
    vader_emit_c$open_if(l0, l2);
    l2 = vader_emit_c$pc_header(l1, 2022u);
    l3 = vader_emit_c$pc_local(l1, 2703u);
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
        vader_obj_header_init(_a0_obj, 1402u);
        _a0_obj->f_cty = 2616u;
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
    t0 = vader_emit_c$pc_local(l0, 2514u);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 1441u);
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
        return 3364u;
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
    l3 = std_core$write_string_at(l4, l3, 1250u);
    l5 = ((int64_t) (int32_t) l0);
    l3 = std_core$write_int(l4, l3, l5);
    l3 = std_core$write_string_at(l4, l3, 1200u);
    l3 = std_core$write_string_at(l4, l3, l2);
    t0 = std_core$finish_buffer(l4, l3);
    t1 = vader_emit_c_ast$verbatim(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$pc_operand_is_slot(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1405u)) {
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
            if (l3.tag == 1296u) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 1168u) {
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
            if ((l3.tag == 1305u || l3.tag == 1306u)) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            {
                if ((l3.tag == 1204u || l3.tag == 1205u)) {
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
            if (l3.tag == 1211u) {
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
    l2 = vader_emit_c$pc_local(l1, 2703u);
    t0 = vader_emit_c$pc_local(l1, 2514u);
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l3 = (void*) _a0_arr;
    l4 = vader_emit_c_ast$call(3355u, l3);
    vader_emit_c$assign(l0, l2, l4);
    l2 = vader_emit_c$pc_local(l1, 2124u);
    l4 = vader_emit_c$pc_capacity(l1);
    vader_emit_c$assign(l0, l2, l4);
    l2 = vader_emit_c$pc_local(l1, 3046u);
    l4 = vader_emit_c$pc_header(l1, 2023u);
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
        if (l7.tag == 1294u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            if (t1 == l3) {
                return true;
            }
        }
        if (l7.tag == 1295u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            if (t1 == l3) {
                return true;
            }
        }
        if (l7.tag == 1293u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            if (t1 == l3) {
                l5 = vader_chk_add(i32, l5, INT32_C(1));
            }
        }
        if (l7.tag == 1292u) {
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
    t0 = concat_3(1207u, l0, 414u);
    t1 = concat_2(t0, 3327u);
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
        t0 = concat_2(l0, 411u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_3(2190u, l0, 411u);
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
    t0 = vader_emit_c_ast$verbatim(528u);
    vader_struct_vader_emit_c$StackLit_t* _a2_obj = (vader_struct_vader_emit_c$StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackLit_t));
    vader_obj_header_init(_a2_obj, 1404u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 579u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 7u, 579u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l4));
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        if (l8.tag == 1204u) {
            l9 = true;
        } else {
            l9 = l8.tag == 1205u;
        }
        if (l9) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l6];
            l11 = vader_emit_c$branch_target(l1, l10);
            if (l11.tag == 1401u) {
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
    vader_obj_header_init(_a4_obj, 1391u);
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
    vader_array_t* _a0_arr = vader_array_new(237u, 0u, 13u, 1401u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 7u, 579u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 581u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l4));
    while ((l5 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        if (l7.tag == 1197u) {
            l8 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l8);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
        } else if (l7.tag == 1296u) {
            l9 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l9);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(1));
        } else if (l7.tag == 1283u) {
            l10 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(2));
        } else if (l7.tag == 1224u) {
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
                t0 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l14, 581u);
                l15 = ((uint8_t) t0.payload.i);
                l16 = ((int32_t) (int64_t) l5);
                vader_struct_vader_emit_c$ScopeInfo_t* _a6_obj = (vader_struct_vader_emit_c$ScopeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ScopeInfo_t));
                vader_obj_header_init(_a6_obj, 1401u);
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
            vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l6.payload.obj;
            ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l5.payload.obj;
            l7 = (void*) _a0_arr;
            l5 = vader_emit_c_ast$call(3391u, l7);
            if (l1 == INT32_C(11)) {
                l6 = l5;
                vader_emit_c$push_expr(l0, l2, l6);
                { vader_gc_top = gc_frame.prev; return; }
            }
            vader_struct_vader_emit_c_ast$CUnary_t* _a1_obj = (vader_struct_vader_emit_c_ast$CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CUnary_t));
            vader_obj_header_init(_a1_obj, 1460u);
            _a1_obj->f_operator = 299u;
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
    l5 = vader_emit_c_ast$verbatim(531u);
    l5 = vader_emit_c_ast$cast(l0, l5);
    l6 = vader_emit_c_ast$number(INT64_C(0));
    l5 = vader_emit_c_ast$binary((uint8_t) 11, l5, l6);
    l7 = concat_4(617u, l0, 390u, l4);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 2u, 13u, 2544u);
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
    vader_obj_header_init(_a0_obj, 1403u);
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
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(576u, l6));
        l7 = vader_emit_c$emit_foreign_unit(l0, l6);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(576u, l7));
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
        l1 = vader_box_string(576u, 3364u);
        return l1;
    }
    if (l0 == INT32_C(8)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l1 = vader_box_string(576u, 3365u);
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_string(576u, 3362u);
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_string(576u, 3361u);
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_string(576u, 3370u);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_string(576u, 3366u);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_string(576u, 3369u);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_string(576u, 3363u);
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_string(576u, 3360u);
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
    if (l1.tag == 1438u) {
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
    vader_obj_header_init(_a0_obj, 1460u);
    _a0_obj->f_operator = 458u;
    _a0_obj->f_operand = l1;
    l3 = (void*) _a0_obj;
    vader_emit_c$push_expr(l0, (uint8_t) 3, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_into_temporary(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$new_temporary(l0, l2);
    vader_emit_c$assign(l0, vader_ref_box(l3), l1);
    vader_emit_c$push_temporary(l0, l3, l2);
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
            vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
            ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0.payload.obj;
            l21 = (void*) _a2_arr;
            l22 = vader_emit_c_ast$call(3039u, l21);
            l23 = ((vader_struct_vader_core_bytecode$BcField_t*) l11)->f_name;
            l24 = concat_2(2394u, l23);
            t0 = vader_emit_c$null_member(l4, l24);
            vader_array_t* _a3_arr = vader_array_new(451u, 1u, 13u, 2544u);
            ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0.payload.obj;
            l25 = (void*) _a3_arr;
            l26 = vader_emit_c_ast$call(3039u, l25);
            l27 = vader_emit_c_ast$binary((uint8_t) 11, l22, l26);
            l28 = concat_3(l2, 471u, l13);
            l29 = vader_emit_c$static_assert(l27, l28);
            vader_array_push_ref((vader_array_t*) l6, l29.payload.obj);
            l30 = vader_emit_c_ast$verbatim(l2);
            l31 = vader_emit_c_ast$verbatim(l13);
            vader_array_t* _a4_arr = vader_array_new(451u, 2u, 13u, 2544u);
            ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l31.payload.obj;
            ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l30.payload.obj;
            l32 = (void*) _a4_arr;
            l33 = vader_emit_c_ast$call(1219u, l32);
            l34 = vader_emit_c_ast$number(l15);
            l35 = vader_emit_c_ast$binary((uint8_t) 11, l33, l34);
            l36 = concat_4(l2, 471u, l13, 225u);
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
        l18 = concat_2(l13, 471u);
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
    vader_obj_header_init(_a0_obj, 1404u);
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
    vader_obj_header_init(_a0_obj, 1405u);
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
        vader_obj_header_init(_a1_obj, 1441u);
        _a1_obj->f_base = l2;
        _a1_obj->f_member = l11;
        _a1_obj->f_arrow = false;
        l12 = (void*) _a1_obj;
        l13 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
        l14 = concat_2(2394u, l13);
        vader_struct_vader_emit_c_ast$CMember_t* _a2_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a2_obj, 1441u);
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
            vader_obj_header_init(_a3_obj, 1418u);
            _a3_obj->f_model = vader_ref_box(l20);
            _a3_obj->f_value = vader_ref_box(l21);
            l22 = (void*) _a3_obj;
            vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
            vader_obj_header_init(_a4_obj, 1411u);
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
        t1 = concat_2(t2, 411u);
        t3 = vader_emit_c_ast$cast(t1, vader_ref_box(l15));
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a5_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a5_obj, 1445u);
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
    l8 = std_core$write_string_at(l7, l8, 2880u);
    l9 = vader_array_length(((vader_array_t*) l2));
    l8 = std_core$write_int(l7, l8, l9);
    l6 = std_core$finish_buffer(l7, l8);
    vader_array_push_scalar((vader_array_t*) l2, vader_box_string(576u, l6));
    t0 = vader_emit_c$bc_struct_name(l0, l1);
    l10 = vader_emit_c$struct_c_name(t0);
    l11 = concat_2(l10, 411u);
    t1 = (void*) &vader_data_68;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l12 = vader_emit_c_ast$declaration(l11, l6, vader_ref_box(l7));
    vader_array_push_ref((vader_array_t*) l3, l12.payload.obj);
    vader_array_t* _a1_arr = vader_array_new(452u, 0u, 13u, 2549u);
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
                vader_obj_header_init(_a3_obj, 1441u);
                _a3_obj->f_base = l12;
                _a3_obj->f_member = l17;
                _a3_obj->f_arrow = true;
                l18 = (void*) _a3_obj;
                l19 = vader_emit_c_ast$verbatim(l11);
                vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
                vader_obj_header_init(_a4_obj, 1411u);
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
    vader_obj_header_init(_a5_obj, 1411u);
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
    l8 = std_core$write_string_at(l13, l8, 3263u);
    t0 = std_core$finish_buffer(l13, l8);
    l19 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a6_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l19.payload.obj;
    ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l12.payload.obj;
    l13 = (void*) _a6_arr;
    l12 = vader_emit_c_ast$perform(3447u, l13);
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
    l2 = vader_emit_c_ast$cast(3524u, l1);
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
    vader_array_t* _a0_arr = vader_array_reserve(451u, (int64_t) t0, 13u, 2544u);
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
    l8 = concat_3(471u, l1, 1249u);
    vader_struct_vader_emit_c_ast$CCompoundLiteral_t* _a2_obj = (vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCompoundLiteral_t));
    vader_obj_header_init(_a2_obj, 1419u);
    _a2_obj->f_type = 2192u;
    _a2_obj->f_elements = l3;
    l3 = (void*) _a2_obj;
    l7 = vader_emit_c_ast$designated(l8, vader_ref_box(l3));
    vader_array_push_ref((vader_array_t*) l0, l7.payload.obj);
    l8 = concat_3(471u, l1, 1241u);
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
    l5 = concat_5(617u, l0, 393u, l4, 1182u);
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
    l6 = concat_2(t0, 1239u);
    l7 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_storage;
    l8 = l2;
    l9 = vader_host_std_core$Intrinsic$byte_len(l8);
    l10 = (void*) vader_buffer_new((size_t) (INT64_C(46) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l10, l9, 1135u);
    l9 = std_core$write_string_at(l10, l9, l8);
    l9 = std_core$write_string_at(l10, l9, 423u);
    l9 = std_core$write_int(l10, l9, l5);
    l9 = std_core$write_string_at(l10, l9, 377u);
    l8 = std_core$finish_buffer(l10, l9);
    t1 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_element_tag;
    l11 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t1));
    t1 = vader_core_bytecode$array_kind_index(l3);
    l12 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t1));
    l13 = vader_emit_c_ast$unsigned(l5);
    vader_array_t* _a0_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = l13.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = l12.payload.obj;
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l11.payload.obj;
    l10 = (void*) _a0_arr;
    l11 = vader_emit_c_ast$call(1146u, l10);
    l12 = vader_emit_c_ast$initializer_list(l4);
    l12 = vader_emit_c_ast$designated(506u, l12);
    vader_array_t* _a1_arr = vader_array_new(451u, 2u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l11.payload.obj;
    t2 = (void*) _a1_arr;
    l11 = vader_emit_c_ast$initializer_list(t2);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a2_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a2_obj, 1423u);
    _a2_obj->f_name = l6;
    _a2_obj->f_length = vader_box_obj(0u, NULL);
    _a2_obj->f_value = l11;
    l10 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a3_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a3_obj, 1432u);
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
    vader_array_t* _a4_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l13.payload.obj;
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l12.payload.obj;
    ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l11.payload.obj;
    l10 = (void*) _a4_arr;
    l11 = vader_emit_c_ast$call(1145u, l10);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a5_obj, 1423u);
    _a5_obj->f_name = l8;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l11;
    l10 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a6_obj, 1432u);
    _a6_obj->f_storage = l7;
    _a6_obj->f_constant = true;
    _a6_obj->f_type = 3382u;
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
    vader_obj_header_init(_a0_obj, 1445u);
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
    if (!(l6.tag == 1189u)) {
        l8 = (void*) vader_buffer_new((size_t) INT64_C(59));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l8, l14, 3101u);
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
            vader_obj_header_init(_a5_obj, 1420u);
            _a5_obj->f_condition = t1;
            _a5_obj->f_then_value = l17;
            _a5_obj->f_else_value = l12;
            t2 = (void*) _a5_obj;
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a6_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a6_obj, 1445u);
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
    vader_obj_header_init(_a0_obj, 1407u);
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
    vader_obj_header_init(_a0_obj, 1460u);
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
        vader_array_push_scalar((vader_array_t*) l4, vader_box_string(576u, l3));
        t1 = vader_emit_c_ast$verbatim(l0);
        vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
        l6 = (void*) _a0_arr;
        l7 = vader_emit_c_ast$call(3039u, l6);
        t1 = vader_emit_c_ast$verbatim(l1);
        vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
        l6 = (void*) _a1_arr;
        l8 = vader_emit_c_ast$call(3039u, l6);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$call(3451u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$ref_carrying_element(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if ((l0.tag == 1176u || l0.tag == 1179u || l0.tag == 1185u || l0.tag == 1189u)) {
        return true;
    }
    if (!(l0.tag == 1190u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_core_bytecode$is_ref_only_element(vader_ref_box(t0), l1);
    return t1;
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
    vader_obj_header_init(_a0_obj, 1449u);
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
        return (t1.tag == 1305u || t1.tag == 1306u);
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
        t1 = (void*) &vader_data_66;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        l5 = vader_emit_c_ast$initializer_list(l3);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a1_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a1_obj, 1423u);
        _a1_obj->f_name = l2;
        _a1_obj->f_length = vader_ref_box(l4);
        _a1_obj->f_value = l5;
        l4 = (void*) _a1_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a2_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a2_obj, 1432u);
        _a2_obj->f_storage = (uint8_t) 0;
        _a2_obj->f_constant = false;
        _a2_obj->f_type = l1;
        _a2_obj->f_declarator = l4;
        l4 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l0, l4);
        t2 = vader_emit_c_ast$verbatim(l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_68;
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
    if (l1.tag == 1168u) {
        if (!(l2 != INT64_C(2))) {
            return vader_box_i64(580u, INT64_C(0));
        }
        return vader_box_obj(0u, NULL);
    }
    if (!(l1.tag == 1211u)) {
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
        return vader_box_i64(580u, l5);
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
                t1 = concat_3(2085u, l0, 1368u);
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
    t1 = concat_2(l0, 314u);
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
    if (l0.tag == 1438u) {
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
        if (l4.tag == 1186u) {
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
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 579u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 1u, 12u, 574u);
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
            if (l10.tag == 1240u) {
                t0 = l10.payload.obj;
                l11 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
                t0 = l10.payload.obj;
                l12 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l11] = (int32_t) l12;
                l4 = true;
            } else if (l10.tag == 1297u) {
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
    vader_obj_header_init(_a8_obj, 1396u);
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
    if (l4 == INT32_C(51)) {
        vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a0_arr;
        t0 = vader_emit_c_ast$perform(3450u, l5);
        vader_array_t* _a1_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a2_arr;
        t0 = vader_emit_c_ast$returning(3476u, l5);
        vader_array_t* _a3_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a3_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(2)) {
        vader_array_t* _a4_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a4_arr;
        t0 = vader_emit_c_ast$returning(3475u, l5);
        vader_array_t* _a5_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a5_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(3)) {
        l6 = vader_emit_c$argument(INT64_C(2));
        vader_array_t* _a6_arr = vader_array_new(451u, 3u, 13u, 2544u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 2u] = l6.payload.obj;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = l3.payload.obj;
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a6_arr;
        t0 = vader_emit_c_ast$returning(3477u, l5);
        vader_array_t* _a7_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a7_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(4)) {
        vader_array_t* _a8_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a8_arr;
        t0 = vader_emit_c_ast$returning(3481u, l5);
        vader_array_t* _a9_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a9_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(5)) {
        l7 = vader_emit_c$class_index(l1, (uint8_t) 4);
        if ((l7 < INT32_C(0))) {
            t0 = vader_emit_c$trap(2065u);
            vader_array_t* _a10_arr = vader_array_new(452u, 1u, 13u, 2549u);
            ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = t0.payload.obj;
            t1 = (void*) _a10_arr;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = vader_emit_c$array_tag(l1, l7);
        if (!((l8 < INT32_C(0)))) {
            l6 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l8));
            l9 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l7));
            vader_array_t* _a11_arr = vader_array_new(451u, 3u, 13u, 2544u);
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 2u] = l9.payload.obj;
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 1u] = l6.payload.obj;
            ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = l2.payload.obj;
            l5 = (void*) _a11_arr;
            l6 = vader_emit_c_ast$call(3478u, l5);
            vader_array_t* _a12_arr = vader_array_new(239u, 0u, 13u, 1411u);
            l5 = (void*) _a12_arr;
            l6 = vader_emit_c_ast$cast(3524u, l6);
            vader_struct_vader_emit_c_ast$CReturn_t* _a13_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a13_obj, 1449u);
            _a13_obj->f_stores = l5;
            _a13_obj->f_value = l6;
            _a13_obj->f_snapshot_type = 0u;
            _a13_obj->f_pops_frame = false;
            t1 = (void*) _a13_obj;
            vader_array_t* _a14_arr = vader_array_new(452u, 1u, 13u, 2549u);
            ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = t1;
            t1 = (void*) _a14_arr;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_emit_c$trap(2066u);
        vader_array_t* _a15_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a15_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(6)) {
        t0 = vader_emit_c_ast$cast(3383u, l2);
        vader_array_t* _a16_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0.payload.obj;
        l5 = (void*) _a16_arr;
        t0 = vader_emit_c_ast$returning(3474u, l5);
        vader_array_t* _a17_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a17_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(7)) {
        vader_array_t* _a18_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a18_arr;
        t0 = vader_emit_c_ast$returning(3480u, l5);
        vader_array_t* _a19_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a19_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(13)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a20_slotarr, vader_array_offset(_a20_slotarr) + (size_t) INT32_C(0), 581u);
        t2 = vader_emit_c$deep_copy_return(((uint8_t) t0.payload.i));
        vader_array_t* _a21_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = t2.payload.obj;
        t1 = (void*) _a21_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(26)) {
        vader_array_t* _a22_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a22_arr;
        t0 = vader_emit_c_ast$perform(3435u, l5);
        vader_array_t* _a23_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a23_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(27)) {
        t0 = vader_emit_c$gc_statistic(3213u);
        vader_array_t* _a24_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a24_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(28)) {
        t0 = vader_emit_c$gc_statistic(2071u);
        vader_array_t* _a25_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a25_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(29)) {
        t0 = vader_emit_c$gc_statistic(3214u);
        vader_array_t* _a26_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a26_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(30)) {
        t0 = vader_emit_c$gc_statistic(3211u);
        vader_array_t* _a27_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a27_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(31)) {
        t0 = vader_emit_c$gc_statistic(3212u);
        vader_array_t* _a28_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a28_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(32)) {
        vader_array_t* _a29_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a29_arr;
        t0 = vader_emit_c_ast$perform(3436u, l5);
        vader_array_t* _a30_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a30_arr->buf->slots)[vader_array_offset(_a30_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a30_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(33)) {
        vader_array_t* _a31_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a31_arr->buf->slots)[vader_array_offset(_a31_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a31_arr;
        t0 = vader_emit_c_ast$returning(3464u, l5);
        vader_array_t* _a32_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a32_arr->buf->slots)[vader_array_offset(_a32_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a32_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(34)) {
        vader_array_t* _a33_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a33_arr;
        t0 = vader_emit_c_ast$perform(3462u, l5);
        vader_array_t* _a34_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a34_arr->buf->slots)[vader_array_offset(_a34_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a34_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(35)) {
        vader_array_t* _a35_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a35_arr->buf->slots)[vader_array_offset(_a35_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a35_arr;
        t0 = vader_emit_c_ast$perform(3470u, l5);
        vader_array_t* _a36_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a36_arr->buf->slots)[vader_array_offset(_a36_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a36_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(36)) {
        vader_array_t* _a37_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a37_arr->buf->slots)[vader_array_offset(_a37_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a37_arr;
        t0 = vader_emit_c_ast$perform(3463u, l5);
        vader_array_t* _a38_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a38_arr->buf->slots)[vader_array_offset(_a38_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a38_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(37)) {
        vader_array_t* _a39_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a39_arr->buf->slots)[vader_array_offset(_a39_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a39_arr;
        t0 = vader_emit_c_ast$perform(3453u, l5);
        vader_array_t* _a40_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a40_arr->buf->slots)[vader_array_offset(_a40_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a40_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(38)) {
        vader_array_t* _a41_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a41_arr;
        t0 = vader_emit_c_ast$returning(3454u, l5);
        vader_array_t* _a42_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a42_arr->buf->slots)[vader_array_offset(_a42_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a42_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(39)) {
        vader_array_t* _a43_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a43_arr;
        t0 = vader_emit_c_ast$returning(3456u, l5);
        vader_array_t* _a44_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a44_arr->buf->slots)[vader_array_offset(_a44_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a44_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(40)) {
        vader_array_t* _a45_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a45_arr->buf->slots)[vader_array_offset(_a45_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a45_arr;
        t0 = vader_emit_c_ast$returning(3457u, l5);
        vader_array_t* _a46_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a46_arr->buf->slots)[vader_array_offset(_a46_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a46_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(41)) {
        vader_array_t* _a47_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a47_arr->buf->slots)[vader_array_offset(_a47_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a47_arr;
        t0 = vader_emit_c_ast$perform(3472u, l5);
        vader_array_t* _a48_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a48_arr->buf->slots)[vader_array_offset(_a48_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a48_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(42)) {
        vader_array_t* _a49_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a49_arr->buf->slots)[vader_array_offset(_a49_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a49_arr;
        t0 = vader_emit_c_ast$perform(3471u, l5);
        vader_array_t* _a50_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a50_arr->buf->slots)[vader_array_offset(_a50_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a50_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(43)) {
        vader_array_t* _a51_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a51_arr->buf->slots)[vader_array_offset(_a51_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a51_arr;
        t0 = vader_emit_c_ast$perform(3458u, l5);
        vader_array_t* _a52_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a52_arr->buf->slots)[vader_array_offset(_a52_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a52_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(44)) {
        vader_array_t* _a53_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a53_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a53_slotarr, vader_array_offset(_a53_slotarr) + (size_t) INT32_C(0), 581u);
        t2 = vader_emit_c$monitor_give(((uint8_t) t0.payload.i));
        vader_array_t* _a54_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a54_arr->buf->slots)[vader_array_offset(_a54_arr) + 0u] = t2.payload.obj;
        t1 = (void*) _a54_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(45)) {
        vader_array_t* _a55_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a55_arr;
        t0 = vader_emit_c_ast$perform(3459u, l5);
        vader_array_t* _a56_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a56_arr->buf->slots)[vader_array_offset(_a56_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a56_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(46)) {
        vader_array_t* _a57_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a57_arr->buf->slots)[vader_array_offset(_a57_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a57_arr;
        t0 = vader_emit_c_ast$perform(3466u, l5);
        vader_array_t* _a58_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a58_arr->buf->slots)[vader_array_offset(_a58_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a58_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(47)) {
        vader_array_t* _a59_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a59_arr->buf->slots)[vader_array_offset(_a59_arr) + 1u] = l3.payload.obj;
        ((void**) _a59_arr->buf->slots)[vader_array_offset(_a59_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a59_arr;
        t0 = vader_emit_c_ast$returning(3467u, l5);
        vader_array_t* _a60_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a60_arr->buf->slots)[vader_array_offset(_a60_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a60_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(48)) {
        vader_array_t* _a61_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a61_arr->buf->slots)[vader_array_offset(_a61_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a61_arr;
        t0 = vader_emit_c_ast$perform(3468u, l5);
        vader_array_t* _a62_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a62_arr->buf->slots)[vader_array_offset(_a62_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a62_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(49)) {
        vader_array_t* _a63_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a63_arr->buf->slots)[vader_array_offset(_a63_arr) + 1u] = l3.payload.obj;
        ((void**) _a63_arr->buf->slots)[vader_array_offset(_a63_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a63_arr;
        t0 = vader_emit_c_ast$returning(3469u, l5);
        vader_array_t* _a64_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a64_arr->buf->slots)[vader_array_offset(_a64_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a64_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(50)) {
        vader_array_t* _a65_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a65_arr->buf->slots)[vader_array_offset(_a65_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a65_arr;
        t0 = vader_emit_c_ast$perform(3465u, l5);
        vader_array_t* _a66_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a66_arr->buf->slots)[vader_array_offset(_a66_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a66_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(54)) {
        t1 = vader_emit_c$library_open_shim(3423u, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(55)) {
        t1 = vader_emit_c$library_open_shim(3424u, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(56)) {
        l6 = vader_emit_c$integer_as_address(l2);
        l9 = vader_emit_c_ast$verbatim(2075u);
        vader_array_t* _a67_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a67_arr->buf->slots)[vader_array_offset(_a67_arr) + 1u] = l9.payload.obj;
        ((void**) _a67_arr->buf->slots)[vader_array_offset(_a67_arr) + 0u] = l6.payload.obj;
        l5 = (void*) _a67_arr;
        l6 = vader_emit_c_ast$call(3425u, l5);
        vader_array_t* _a68_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a68_arr->buf->slots)[vader_array_offset(_a68_arr) + 0u] = l3.payload.obj;
        l5 = (void*) _a68_arr;
        l9 = vader_emit_c_ast$call(3484u, l5);
        l9 = vader_emit_c_ast$declaration(2191u, 2075u, l9);
        l6 = vader_emit_c_ast$declaration(3524u, 2953u, l6);
        l10 = vader_emit_c_ast$verbatim(2075u);
        vader_array_t* _a69_arr = vader_array_new(451u, 2u, 13u, 2544u);
        ((void**) _a69_arr->buf->slots)[vader_array_offset(_a69_arr) + 1u] = l10.payload.obj;
        ((void**) _a69_arr->buf->slots)[vader_array_offset(_a69_arr) + 0u] = l3.payload.obj;
        l5 = (void*) _a69_arr;
        l10 = vader_emit_c_ast$perform(3412u, l5);
        vader_array_t* _a70_arr = vader_array_new(239u, 0u, 13u, 1411u);
        l5 = (void*) _a70_arr;
        t0 = vader_emit_c_ast$verbatim(2953u);
        l11 = vader_emit_c$address_as_integer(t0);
        vader_struct_vader_emit_c_ast$CReturn_t* _a71_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a71_obj, 1449u);
        _a71_obj->f_stores = l5;
        _a71_obj->f_value = l11;
        _a71_obj->f_snapshot_type = 0u;
        _a71_obj->f_pops_frame = false;
        l5 = (void*) _a71_obj;
        vader_array_t* _a72_arr = vader_array_new(452u, 4u, 13u, 2549u);
        ((void**) _a72_arr->buf->slots)[vader_array_offset(_a72_arr) + 3u] = l5;
        ((void**) _a72_arr->buf->slots)[vader_array_offset(_a72_arr) + 2u] = l10.payload.obj;
        ((void**) _a72_arr->buf->slots)[vader_array_offset(_a72_arr) + 1u] = l6.payload.obj;
        ((void**) _a72_arr->buf->slots)[vader_array_offset(_a72_arr) + 0u] = l9.payload.obj;
        t1 = (void*) _a72_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(57)) {
        l6 = vader_emit_c$integer_as_address(l2);
        l9 = vader_emit_c_ast$cast(3383u, l3);
        l10 = vader_emit_c$argument(INT64_C(2));
        l10 = vader_emit_c_ast$cast(3383u, l10);
        l11 = vader_emit_c$argument(INT64_C(3));
        vader_array_t* _a73_arr = vader_array_new(451u, 4u, 13u, 2544u);
        ((void**) _a73_arr->buf->slots)[vader_array_offset(_a73_arr) + 3u] = l11.payload.obj;
        ((void**) _a73_arr->buf->slots)[vader_array_offset(_a73_arr) + 2u] = l10.payload.obj;
        ((void**) _a73_arr->buf->slots)[vader_array_offset(_a73_arr) + 1u] = l9.payload.obj;
        ((void**) _a73_arr->buf->slots)[vader_array_offset(_a73_arr) + 0u] = l6.payload.obj;
        l5 = (void*) _a73_arr;
        t0 = vader_emit_c_ast$returning(3421u, l5);
        vader_array_t* _a74_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a74_arr->buf->slots)[vader_array_offset(_a74_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a74_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(58)) {
        l2 = vader_emit_c$integer_as_address(l2);
        l3 = vader_emit_c_ast$cast(3383u, l3);
        l6 = vader_emit_c$argument(INT64_C(2));
        l6 = vader_emit_c_ast$cast(3383u, l6);
        vader_array_t* _a75_arr = vader_array_new(451u, 3u, 13u, 2544u);
        ((void**) _a75_arr->buf->slots)[vader_array_offset(_a75_arr) + 2u] = l6.payload.obj;
        ((void**) _a75_arr->buf->slots)[vader_array_offset(_a75_arr) + 1u] = l3.payload.obj;
        ((void**) _a75_arr->buf->slots)[vader_array_offset(_a75_arr) + 0u] = l2.payload.obj;
        l5 = (void*) _a75_arr;
        t0 = vader_emit_c_ast$returning(3420u, l5);
        vader_array_t* _a76_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a76_arr->buf->slots)[vader_array_offset(_a76_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a76_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(52)) {
        vader_array_t* _a77_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a77_arr;
        t0 = vader_emit_c_ast$returning(3414u, l5);
        vader_array_t* _a78_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a78_arr->buf->slots)[vader_array_offset(_a78_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a78_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(53)) {
        vader_array_t* _a79_arr = vader_array_new(451u, 0u, 13u, 2544u);
        l5 = (void*) _a79_arr;
        t0 = vader_emit_c_ast$returning(3413u, l5);
        vader_array_t* _a80_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a80_arr->buf->slots)[vader_array_offset(_a80_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a80_arr;
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
        t4 = concat_2(3297u, l13);
        t0 = vader_emit_c$trap(t4);
        vader_array_t* _a81_arr = vader_array_new(452u, 1u, 13u, 2549u);
        ((void**) _a81_arr->buf->slots)[vader_array_offset(_a81_arr) + 0u] = t0.payload.obj;
        t1 = (void*) _a81_arr;
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
    l5 = vader_emit_c$value_parameters(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_signature)->f_params, 1722u);
    vader_struct_vader_emit_c_ast$CSignature_t* _a0_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a0_obj, 1453u);
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
            vader_obj_header_init(_a1_obj, 1453u);
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
    l3 = vader_emit_c$value_parameters(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params, 2696u);
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature);
    l4 = (t0 > INT64_C(1));
    if (l4) {
        l5 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_results;
        l6 = INT64_C(0);
        l7 = vader_array_length(((vader_array_t*) l5));
        while ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l6, 581u);
            t2 = vader_emit_c$c_type_for_val_bare(((uint8_t) t1.payload.i));
            l8 = concat_2(t2, 411u);
            l9 = vader_emit_c$out_param_name(l6);
            vader_struct_vader_emit_c_ast$CParameter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
            vader_obj_header_init(_a2_obj, 1444u);
            _a2_obj->f_type = l8;
            _a2_obj->f_name = l9;
            l10 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l10);
            l6 = (l6 + INT64_C(1));
        }
    }
    l11 = vader_emit_c$module_function_storage(l0, l1);
    if (l4) {
        l8 = 3523u;
    } else {
        t3 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature);
        l8 = vader_emit_c$c_type_for_val_bare(t3);
    }
    t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_name;
    l9 = vader_emit_c$sanitise(t2);
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 1453u);
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
    if (l2 != 3268u) {
        if (l2 != 3278u) {
            { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l0.tag == 1438u) {
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
    vader_obj_header_init(_a0_obj, 1445u);
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
    vader_obj_header_init(_a0_obj, 1418u);
    _a0_obj->f_model = l5;
    _a0_obj->f_value = l6;
    l7 = (void*) _a0_obj;
    l5 = vader_emit_c_ast$number(INT64_C(0));
    t1 = vader_emit_c_ast$binary((uint8_t) 7, vader_ref_box(l7), l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a1_obj, 1445u);
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
    l9 = concat_4(l2, 471u, l3, 257u);
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
    t0 = (void*) &vader_data_66;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t1 = vader_emit_c_ast$verbatim(l1);
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l3 = vader_emit_c_ast$initializer_list(t0);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a2_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a2_obj, 1423u);
    _a2_obj->f_name = l0;
    _a2_obj->f_length = vader_ref_box(l2);
    _a2_obj->f_value = l3;
    l2 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a3_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a3_obj, 1432u);
    _a3_obj->f_storage = (uint8_t) 0;
    _a3_obj->f_constant = true;
    _a3_obj->f_type = 3290u;
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
    t0 = concat_2(1149u, l1);
    l6 = vader_emit_c_ast$verbatim(t0);
    l6 = vader_emit_c_ast$designated(496u, l6);
    t0 = concat_3(3040u, l2, 377u);
    l7 = vader_emit_c_ast$verbatim(t0);
    l7 = vader_emit_c_ast$designated(504u, l7);
    l8 = vader_emit_c_ast$number(((int64_t) (int32_t) l3));
    l8 = vader_emit_c_ast$designated(505u, l8);
    l9 = vader_emit_c_ast$verbatim(l4);
    l9 = vader_emit_c_ast$designated(502u, l9);
    l10 = vader_emit_c_ast$number(INT64_C(1));
    l10 = vader_emit_c_ast$designated(501u, l10);
    vader_array_t* _a0_arr = vader_array_new(451u, 5u, 13u, 2544u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3357u, l2);
    l4 = vader_emit_c$expression_of(l1);
    l4 = vader_emit_c_ast$cast(3038u, l4);
    t0 = vader_emit_c_ast$binary((uint8_t) 3, l3, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$slot_val_type(void* l0, int32_t l1) {
    void* l2;
    void* l4;
    int32_t l3;
    int64_t l5, l6;
    int64_t t0;
    void* t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params;
    t0 = vader_array_length(((vader_array_t*) l2));
    l3 = ((int32_t) (int64_t) t0);
    if (!((l1 < l3))) {
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
        l5 = ((int64_t) (int32_t) l1);
        l6 = vader_array_length(((vader_array_t*) l2));
        l5 = vader_chk_sub(i64, l5, l6);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        return ((vader_struct_vader_core_bytecode$BcLocal_t*) t1)->f_val;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l1, 581u);
    return ((uint8_t) t2.payload.i);
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
    vader_array_t* _a0_arr = vader_array_reserve(27u, (int64_t) t0, 7u, 579u);
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
    vader_obj_header_init(_a1_obj, 632u);
    _a1_obj->f_cap_0 = l0;
    t1 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 514u);
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
    vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) l1, 0u, 576u);
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
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(576u, l8));
        l1 = (l1 + INT64_C(1));
    }
    l3 = (void*) &vader_fn_static___lambda_vader_emit_c_5;
    t1 = std_sort$sort__string(l2, l3);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$source_class(uint8_t l0, uint8_t l1, vader_string_t l2) {
    bool t0;
    t0 = std_string$starts_with(l2, 3263u);
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
    l3 = std_core$write_string_at(l2, l3, 2915u);
    l3 = std_core$write_int(l2, l3, l1);
    t0 = std_core$finish_buffer(l2, l3);
    t1 = vader_emit_c_ast$verbatim(t0);
    l4 = vader_emit_c_ast$address_of(t1);
    t1 = vader_core_bytecode$param_c_type(l0, l1);
    if (!(t1.tag == 0u)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_emit_c_ast$cast(3524u, l4);
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
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 581u);
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
    vader_obj_header_init(_a0_obj, 1415u);
    _a0_obj->f_callee = l1;
    _a0_obj->f_arguments = l2;
    t0 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CMacroStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CMacroStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMacroStatement_t));
    vader_obj_header_init(_a1_obj, 1440u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, t0);
    t1 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CStringLiterals_t* _a1_obj = (vader_struct_vader_emit_c_ast$CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStringLiterals_t));
    vader_obj_header_init(_a1_obj, 1455u);
    _a1_obj->f_literals = t1;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CStaticAssert_t* _a2_obj = (vader_struct_vader_emit_c_ast$CStaticAssert_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStaticAssert_t));
    vader_obj_header_init(_a2_obj, 1454u);
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
        if (l3.tag == 1186u) {
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
    t0 = concat_3(3485u, l1, 1254u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        if (l5.tag == 1189u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
            l6 = vader_emit_c$struct_c_name(t1);
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(576u, l6));
        } else {
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(576u, 0u));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$struct_definition(void* l0, void* l1, void* l2, int64_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int64_t l6, l7;
    int32_t l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l5, &l8, &l12, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l10, &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CField_t* _a0_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
    vader_obj_header_init(_a0_obj, 1428u);
    _a0_obj->f_type = 3448u;
    _a0_obj->f_name = 2515u;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(242u, 1u, 13u, 1428u);
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
        l10 = vader_emit_c$c_type_for(t1);
        t2 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_name;
        l11 = vader_emit_c$field_c_name(t2);
        vader_struct_vader_emit_c_ast$CField_t* _a4_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
        vader_obj_header_init(_a4_obj, 1428u);
        _a4_obj->f_type = l10;
        _a4_obj->f_name = l11;
        l12 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l4, l12);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
    t1 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l3];
    t2 = t1.payload.s;
    vader_struct_vader_emit_c_ast$CStructDefinition_t* _a6_obj = (vader_struct_vader_emit_c_ast$CStructDefinition_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructDefinition_t));
    vader_obj_header_init(_a6_obj, 1456u);
    _a6_obj->f_name = t2;
    _a6_obj->f_fields = l4;
    t0 = (void*) _a6_obj;
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
    if (l2.tag == 1192u) {
        t1 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_kind;
        t1 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_bits;
        t0 = vader_emit_c$data_slot(l7, l8);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1193u) {
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
    t0 = vader_emit_c_ast$cast(3524u, l10);
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
    l4 = vader_emit_c_ast$verbatim(1150u);
    l4 = vader_emit_c_ast$designated(496u, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l3];
    l5 = t0.payload.s;
    t1 = concat_3(3040u, l5, 377u);
    l6 = vader_emit_c_ast$verbatim(t1);
    l6 = vader_emit_c_ast$designated(504u, l6);
    t2 = vader_core_bytecode$size_of_bc_type(vader_ref_box(l1));
    l7 = vader_emit_c_ast$number(((int64_t) (int32_t) t2));
    l7 = vader_emit_c_ast$designated(505u, l7);
    vader_array_t* _a1_arr = vader_array_new(451u, 3u, 13u, 2544u);
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = l7.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l4.payload.obj;
    l8 = (void*) _a1_arr;
    t3 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_shared;
    if (t3) {
        l4 = vader_emit_c_ast$verbatim(1148u);
        l4 = vader_emit_c_ast$designated(490u, l4);
        vader_array_push_ref((vader_array_t*) l8, l4.payload.obj);
    }
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_ptr_offsets;
    vader_emit_c$push_offset_list(l8, 2950u, l9);
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_str_offsets;
    vader_emit_c$push_offset_list(l8, 3087u, l9);
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_ref_offsets;
    vader_emit_c$push_offset_list(l8, 2970u, l9);
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
        t1 = concat_2(l1, 411u);
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
    l3 = std_core$write_string_at(l2, l3, 3263u);
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
        t0 = vader_emit_c_ast$pointer_member(3449u, l0, 3250u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 1441u);
    _a0_obj->f_base = l0;
    _a0_obj->f_member = 3130u;
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
    vader_obj_header_init(_a0_obj, 1445u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(451u, 1u, 13u, 2544u);
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
            vader_obj_header_init(_a3_obj, 1445u);
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
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l8, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(451u, (int64_t) t0, 13u, 2544u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1722u);
        l5 = std_core$write_int(l4, l5, l2);
        t1 = std_core$finish_buffer(l4, l5);
        l6 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l2, 581u);
        l7 = ((uint8_t) t2.payload.i);
        l8 = vader_emit_c$unbox_expr(l6, l7);
        vader_array_push_ref((vader_array_t*) l1, l8.payload.obj);
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
    l3 = concat_2(3432u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$perform(3486u, l1);
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
    l4 = std_core$write_string_at(l3, l4, 2081u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 220u);
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
        vader_obj_header_init(_a0_obj, 1402u);
        _a0_obj->f_cty = 2616u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_emit_c$SlotFill_t* _a1_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a1_obj, 1402u);
        _a1_obj->f_cty = 2616u;
        _a1_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_emit_c$SlotFill_t* _a2_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a2_obj, 1402u);
        _a2_obj->f_cty = 2616u;
        _a2_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(8)) {
        vader_struct_vader_emit_c$SlotFill_t* _a3_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a3_obj, 1402u);
        _a3_obj->f_cty = 2617u;
        _a3_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(4)) {
        vader_struct_vader_emit_c$SlotFill_t* _a4_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a4_obj, 1402u);
        _a4_obj->f_cty = 2617u;
        _a4_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_emit_c$SlotFill_t* _a5_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a5_obj, 1402u);
        _a5_obj->f_cty = 2257u;
        _a5_obj->f_val = (uint8_t) 9;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(1)) {
        vader_struct_vader_emit_c$SlotFill_t* _a6_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a6_obj, 1402u);
        _a6_obj->f_cty = 3293u;
        _a6_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a6_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(5)) {
        vader_struct_vader_emit_c$SlotFill_t* _a7_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a7_obj, 1402u);
        _a7_obj->f_cty = 2618u;
        _a7_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a7_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        vader_struct_vader_emit_c$SlotFill_t* _a8_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a8_obj, 1402u);
        _a8_obj->f_cty = 3293u;
        _a8_obj->f_val = (uint8_t) 10;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(2)) {
        vader_struct_vader_emit_c$SlotFill_t* _a9_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a9_obj, 1402u);
        _a9_obj->f_cty = 3290u;
        _a9_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(6)) {
        vader_struct_vader_emit_c$SlotFill_t* _a10_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a10_obj, 1402u);
        _a10_obj->f_cty = 2615u;
        _a10_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a10_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(9)) {
        vader_struct_vader_emit_c$SlotFill_t* _a11_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a11_obj, 1402u);
        _a11_obj->f_cty = 2432u;
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
    l3 = concat_2(l0, 411u);
    t0 = concat_2(l1, 465u);
    l4 = vader_emit_c_ast$verbatim(t0);
    t1 = vader_emit_c_ast$cast(l3, l4);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1445u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CIndex_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a1_obj, 1436u);
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
        l2 = vader_emit_c$payload_cast(2618u, l0, 2519u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        l2 = vader_emit_c$payload_cast(2615u, l0, 2519u);
    } else if (l1 == INT32_C(2)) {
        l2 = vader_emit_c$payload_cast(2616u, l0, 2519u);
    } else if (l1 == INT32_C(3)) {
        l2 = vader_emit_c$payload_cast(2617u, l0, 2519u);
    } else if (l1 == INT32_C(4)) {
        l2 = vader_emit_c$payload_cast(3293u, l0, 2519u);
    } else if (l1 == INT32_C(5)) {
        l2 = vader_emit_c$payload_cast(3290u, l0, 2519u);
    } else if (l1 == INT32_C(6)) {
        l2 = vader_emit_c$payload_cast(3291u, l0, 2519u);
    } else if (l1 == INT32_C(7)) {
        l2 = vader_emit_c$payload_cast(3292u, l0, 2519u);
    } else if (l1 == INT32_C(11)) {
        l2 = vader_emit_c$payload_cast(3291u, l0, 2519u);
    } else if (l1 == INT32_C(8)) {
        l2 = vader_emit_c$payload_cast(2432u, l0, 2376u);
    } else if (l1 == INT32_C(9)) {
        l2 = vader_emit_c$payload_cast(2257u, l0, 2376u);
    } else if (l1 == INT32_C(10)) {
        l2 = vader_emit_c$payload(l0, 1982u);
    } else if (l1 == INT32_C(12)) {
        l2 = vader_emit_c$payload(l0, 3010u);
    } else if (l1 == INT32_C(13)) {
        l2 = l0;
    } else if (l1 == INT32_C(14)) {
        l2 = vader_emit_c_ast$verbatim(364u);
    } else if (l1 == INT32_C(15)) {
        l3 = vader_emit_c$payload(l0, 2519u);
        l3 = vader_emit_c_ast$cast(2633u, l3);
        t0 = vader_emit_c_ast$cast(3524u, l3);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a0_obj, 1445u);
        _a0_obj->f_inner = t0;
        t1 = (void*) _a0_obj;
        l2 = vader_ref_box(t1);
    } else if (l1 == INT32_C(16)) {
        l2 = vader_emit_c$payload(l0, 2880u);
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
        l8 = std_core$write_string_at(l7, l8, 2080u);
        l9 = ((int64_t) (int32_t) l1);
        l8 = std_core$write_int(l7, l8, l9);
        l8 = std_core$write_string_at(l7, l8, 443u);
        t0 = std_core$finish_buffer(l7, l8);
        vader_host_std_core$Intrinsic$panic(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l5 = ((int32_t) l6.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        if (!(l6.tag == 1189u)) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(61));
            l8 = INT64_C(0);
            l8 = std_core$write_string_at(l7, l8, 2084u);
            l9 = ((int64_t) (int32_t) l1);
            l8 = std_core$write_int(l7, l8, l9);
            l8 = std_core$write_string_at(l7, l8, 193u);
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
        vader_array_t* _a4_arr = vader_array_new(451u, 4u, 13u, 2544u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 3u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l12.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l11.payload.obj;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l6.payload.obj;
        l4 = (void*) _a4_arr;
        l6 = vader_emit_c_ast$call(1151u, l4);
        l5 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_struct_vader_emit_c$UnionFieldPlace_t* _a5_obj = (vader_struct_vader_emit_c$UnionFieldPlace_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$UnionFieldPlace_t));
        vader_obj_header_init(_a5_obj, 1409u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, 1246u);
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
                t1 = concat_3(3052u, l10, 1440u);
                std_abort$todo(t1);
                vader_unreachable("a no-return call returned");
            }
            l7 = (l7 + INT64_C(1));
        }
        if (l6 == 0u) {
            l11 = 1252u;
        } else {
            l11 = l6;
        }
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(576u, l11));
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(26u, 0u, 0u, 576u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(24u, 0u, 12u, 574u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(27u, 0u, 7u, 579u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections$Map__string__bool_t* _a10_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a10_obj, 900u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_grow_at = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a10_obj;
    vader_struct_std_collections$Set__string_t* _a11_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a11_obj, 990u);
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
            t1 = concat_3(3051u, l6, 1557u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(3490u, l2);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_c$user_extern_shim(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l41 = NULL;
    void* l47 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l54 = NULL;
    void* l55 = NULL;
    void* l59 = NULL;
    void* l62 = NULL;
    void* l65 = NULL;
    void* l68 = NULL;
    void* l71 = NULL;
    void* l73 = NULL;
    int64_t l8, l9, l15, l19, l30, l34, l42, l56, l60, l63, l69, l74;
    vader_box_t l10 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null(), l21 = vader_box_null(), l31 = vader_box_null(), l36 = vader_box_null(), l37 = vader_box_null(), l38 = vader_box_null(), l39 = vader_box_null(), l44 = vader_box_null(), l45 = vader_box_null(), l48 = vader_box_null(), l49 = vader_box_null(), l52 = vader_box_null(), l53 = vader_box_null(), l58 = vader_box_null(), l61 = vader_box_null(), l66 = vader_box_null(), l67 = vader_box_null(), l70 = vader_box_null(), l72 = vader_box_null(), l75 = vader_box_null(), l76 = vader_box_null();
    int32_t l11, l22, l23, l25, l27, l46;
    vader_string_t l16 = 0;
    vader_string_t l24 = 0;
    vader_string_t l26 = 0;
    vader_string_t l35 = 0;
    vader_string_t l40 = 0;
    vader_string_t l43 = 0;
    vader_string_t l57 = 0;
    vader_string_t l64 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[24] = {
        &l10, &l13, &l17, &l21, &l31, &l36, &l37, &l38, &l39, &l44, &l45, &l48, &l49, &l52, &l53,
        &l58, &l61, &l66, &l67, &l70, &l72, &l75, &l76, &t1,
    };
    void** gc_raw_roots[29] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l12, &l14, &l18, &l20, &l28, &l29, &l32, &l33,
        &l41, &l47, &l50, &l51, &l54, &l55, &l59, &l62, &l65, &l68, &l71, &l73, &t3,
    };
    vader_string_t* gc_atom_roots[9] = { &l16, &l24, &l26, &l35, &l40, &l43, &l57, &l64, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 24u, 29u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    vader_array_t* _a0_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(451u, 0u, 13u, 2544u);
    l7 = (void*) _a4_arr;
    l8 = INT64_C(0);
    l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params));
    while ((l8 < l9)) {
        l10 = vader_emit_c$argument(l8);
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l11 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l8];
        t0 = vader_emit_c$is_abi_array(l1, l11);
        if (t0) {
            t1 = vader_emit_c_ast$cast(3383u, l10);
            vader_array_t* _a6_arr = vader_array_new(451u, 1u, 13u, 2544u);
            ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t1.payload.obj;
            l12 = (void*) _a6_arr;
            l13 = vader_emit_c_ast$call(3350u, l12);
            l14 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l15 = INT64_C(0);
            l15 = std_core$write_string_at(l14, l15, 3010u);
            l15 = std_core$write_int(l14, l15, l8);
            l16 = std_core$finish_buffer(l14, l15);
            l17 = vader_emit_c_ast$declaration(3473u, l16, l13);
            vader_array_push_ref((vader_array_t*) l4, l17.payload.obj);
            l18 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l19 = INT64_C(0);
            l19 = std_core$write_string_at(l18, l19, 3010u);
            l19 = std_core$write_int(l18, l19, l8);
            t2 = std_core$finish_buffer(l18, l19);
            t1 = vader_emit_c_ast$verbatim(t2);
            vader_struct_vader_emit_c_ast$CMember_t* _a7_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
            vader_obj_header_init(_a7_obj, 1441u);
            _a7_obj->f_base = t1;
            _a7_obj->f_member = 2950u;
            _a7_obj->f_arrow = false;
            l20 = (void*) _a7_obj;
            t2 = vader_emit_c$extern_parameter_type(l0, l1, l8);
            l21 = vader_emit_c$as_buffer_type(t2, vader_ref_box(l20));
            vader_array_push_ref((vader_array_t*) l3, l21.payload.obj);
        } else {
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
            l22 = ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l8];
            t2 = vader_emit_c$mirrored_c_struct(l1, l22);
            if (t2 != 0u) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
                l23 = ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l8];
                l24 = vader_emit_c$mirrored_c_struct(l1, l23);
                vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
                l25 = ((int32_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l8];
                t2 = vader_emit_c$bc_struct_name(l1, l25);
                l26 = vader_emit_c$struct_c_name(t2);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
                l27 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l8];
                l28 = vader_emit_c$bc_struct_fields(l1, l27);
                l29 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l30 = INT64_C(0);
                l30 = std_core$write_string_at(l29, l30, 2915u);
                l30 = std_core$write_int(l29, l30, l8);
                t2 = std_core$finish_buffer(l29, l30);
                l31 = vader_emit_c_ast$verbatim(t2);
                t2 = concat_2(l26, 411u);
                t1 = vader_emit_c_ast$cast(t2, l10);
                vader_struct_vader_emit_c_ast$CParenthesized_t* _a12_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
                vader_obj_header_init(_a12_obj, 1445u);
                _a12_obj->f_inner = t1;
                l32 = (void*) _a12_obj;
                l33 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l34 = INT64_C(0);
                l34 = std_core$write_string_at(l33, l34, 2915u);
                l34 = std_core$write_int(l33, l34, l8);
                l35 = std_core$finish_buffer(l33, l34);
                t1 = vader_emit_c_ast$number(INT64_C(0));
                vader_array_t* _a13_arr = vader_array_new(451u, 1u, 13u, 2544u);
                ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = t1.payload.obj;
                t3 = (void*) _a13_arr;
                l36 = vader_emit_c_ast$initializer_list(t3);
                l37 = vader_emit_c_ast$declaration(l24, l35, l36);
                vader_array_push_ref((vader_array_t*) l4, l37.payload.obj);
                vader_emit_c$push_member_copies(l1, l28, l31, vader_ref_box(l32), true, l4, INT32_C(0));
                t0 = vader_core_bytecode$param_is_by_address(l2, l8);
                if (t0) {
                    t0 = vader_core_bytecode$param_is_c_out(l2, l8);
                    if (t0) {
                        l38 = vader_emit_c_ast$address_of(l10);
                        vader_array_push_ref((vader_array_t*) l7, l38.payload.obj);
                        vader_emit_c$push_member_copies(l1, l28, l31, vader_ref_box(l32), false, l6, INT32_C(0));
                    }
                    l39 = vader_emit_c_ast$address_of(l31);
                    vader_array_push_ref((vader_array_t*) l3, l39.payload.obj);
                } else {
                    vader_array_push_ref((vader_array_t*) l3, l31.payload.obj);
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            } else {
                t0 = vader_core_bytecode$param_is_by_address(l2, l8);
                if (t0) {
                    l40 = vader_emit_c$spilled_c_type(l0, l8);
                    l41 = (void*) vader_buffer_new((size_t) INT64_C(21));
                    l42 = INT64_C(0);
                    l42 = std_core$write_string_at(l41, l42, 2915u);
                    l42 = std_core$write_int(l41, l42, l8);
                    l43 = std_core$finish_buffer(l41, l42);
                    l44 = vader_emit_c_ast$declaration(l40, l43, l10);
                    vader_array_push_ref((vader_array_t*) l4, l44.payload.obj);
                    l45 = vader_emit_c$spilled_address(l0, l8);
                    vader_array_push_ref((vader_array_t*) l3, l45.payload.obj);
                } else {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
                    l46 = ((int32_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l8];
                    t0 = vader_emit_c$is_abi_nullable_pointer(l1, l46);
                    if (t0) {
                        vader_struct_vader_emit_c_ast$CMember_t* _a15_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a15_obj, 1441u);
                        _a15_obj->f_base = l10;
                        _a15_obj->f_member = 3130u;
                        _a15_obj->f_arrow = false;
                        l47 = (void*) _a15_obj;
                        l48 = vader_emit_c_ast$verbatim(1137u);
                        l49 = vader_emit_c_ast$binary((uint8_t) 11, vader_ref_box(l47), l48);
                        vader_struct_vader_emit_c_ast$CMember_t* _a16_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a16_obj, 1441u);
                        _a16_obj->f_base = l10;
                        _a16_obj->f_member = 2932u;
                        _a16_obj->f_arrow = false;
                        t3 = (void*) _a16_obj;
                        vader_struct_vader_emit_c_ast$CMember_t* _a17_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a17_obj, 1441u);
                        _a17_obj->f_base = vader_ref_box(t3);
                        _a17_obj->f_member = 2519u;
                        _a17_obj->f_arrow = false;
                        l50 = (void*) _a17_obj;
                        t3 = (void*) &vader_data_68;
                        vader_array_t* _a18_slotarr = ((vader_array_t*) t3);
                        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                        l51 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) INT64_C(0));
                        l52 = vader_emit_c_ast$cast(2633u, vader_ref_box(l50));
                        l53 = vader_emit_c_ast$cast(3524u, l52);
                        vader_struct_vader_emit_c_ast$CConditional_t* _a19_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
                        vader_obj_header_init(_a19_obj, 1420u);
                        _a19_obj->f_condition = l49;
                        _a19_obj->f_then_value = vader_ref_box(l51);
                        _a19_obj->f_else_value = l53;
                        l54 = (void*) _a19_obj;
                        l55 = (void*) vader_buffer_new((size_t) INT64_C(21));
                        l56 = INT64_C(0);
                        l56 = std_core$write_string_at(l55, l56, 2915u);
                        l56 = std_core$write_int(l55, l56, l8);
                        l57 = std_core$finish_buffer(l55, l56);
                        l58 = vader_emit_c_ast$declaration(3524u, l57, vader_ref_box(l54));
                        vader_array_push_ref((vader_array_t*) l4, l58.payload.obj);
                        l59 = (void*) vader_buffer_new((size_t) INT64_C(21));
                        l60 = INT64_C(0);
                        l60 = std_core$write_string_at(l59, l60, 2915u);
                        l60 = std_core$write_int(l59, l60, l8);
                        t2 = std_core$finish_buffer(l59, l60);
                        l61 = vader_emit_c_ast$verbatim(t2);
                        vader_array_push_ref((vader_array_t*) l3, l61.payload.obj);
                    } else {
                        vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
                        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l8)
                        t1 = vader_array_read_u8(_a20_slotarr, vader_array_offset(_a20_slotarr) + (size_t) l8, 581u);
                        if (((int32_t) t1.payload.i) == INT32_C(12)) {
                            l62 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l63 = INT64_C(0);
                            l63 = std_core$write_string_at(l62, l63, 2072u);
                            l63 = std_core$write_int(l62, l63, l8);
                            l64 = std_core$finish_buffer(l62, l63);
                            vader_array_t* _a21_arr = vader_array_new(451u, 1u, 13u, 2544u);
                            ((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = l10.payload.obj;
                            l65 = (void*) _a21_arr;
                            l66 = vader_emit_c_ast$call(3484u, l65);
                            l67 = vader_emit_c_ast$declaration(2191u, l64, l66);
                            vader_array_push_ref((vader_array_t*) l4, l67.payload.obj);
                            l68 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l69 = INT64_C(0);
                            l69 = std_core$write_string_at(l68, l69, 2072u);
                            l69 = std_core$write_int(l68, l69, l8);
                            t2 = std_core$finish_buffer(l68, l69);
                            l70 = vader_emit_c_ast$verbatim(t2);
                            vader_array_t* _a22_arr = vader_array_new(451u, 2u, 13u, 2544u);
                            ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 1u] = l70.payload.obj;
                            ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = l10.payload.obj;
                            l71 = (void*) _a22_arr;
                            l72 = vader_emit_c_ast$perform(3412u, l71);
                            vader_array_push_ref((vader_array_t*) l5, l72.payload.obj);
                            l73 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l74 = INT64_C(0);
                            l74 = std_core$write_string_at(l73, l74, 2072u);
                            l74 = std_core$write_int(l73, l74, l8);
                            t2 = std_core$finish_buffer(l73, l74);
                            l75 = vader_emit_c_ast$verbatim(t2);
                            vader_array_push_ref((vader_array_t*) l3, l75.payload.obj);
                        } else {
                            l76 = vader_emit_c$renamed_argument(l0, l8, l10);
                            vader_array_push_ref((vader_array_t*) l3, l76.payload.obj);
                        }
                    }
                }
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a23_arr = vader_array_new(452u, 0u, 13u, 2549u);
    l12 = (void*) _a23_arr;
    t4 = vader_array_length(((vader_array_t*) l7));
    if ((t4 > INT64_C(0))) {
        t4 = vader_array_length(((vader_array_t*) l7));
        l10 = vader_emit_c_ast$number(t4);
        l13 = vader_emit_c_ast$array_declaration(3525u, 1237u, l7);
        vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
        l13 = vader_emit_c_ast$verbatim(1236u);
        l17 = vader_emit_c_ast$verbatim(1237u);
        vader_array_t* _a24_arr = vader_array_new(451u, 3u, 13u, 2544u);
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 2u] = l10.payload.obj;
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 1u] = l17.payload.obj;
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = l13.payload.obj;
        l7 = (void*) _a24_arr;
        l10 = vader_emit_c_ast$perform(1140u, l7);
        vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
        vader_array_t* _a25_arr = vader_array_new(451u, 1u, 13u, 2544u);
        ((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = l13.payload.obj;
        l7 = (void*) _a25_arr;
        l10 = vader_emit_c_ast$perform(1139u, l7);
        vader_array_push_ref((vader_array_t*) l12, l10.payload.obj);
    }
    vader_array_push_all((vader_array_t*) l12, (vader_array_t*) l6);
    t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    l10 = vader_emit_c_ast$call(t2, l3);
    l10 = vader_emit_c$read_back(l0, l10);
    l2 = vader_emit_c$forwarded_result(l2, l1, l10);
    l10 = vader_emit_c$foreign_depth((uint8_t) 3);
    vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
    l10 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_capture;
    vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
    l10 = vader_emit_c$foreign_depth((uint8_t) 4);
    vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l12);
    l3 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_settle;
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l3);
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l5);
    vader_array_t* _a26_arr = vader_array_new(239u, 0u, 13u, 1411u);
    l3 = (void*) _a26_arr;
    l10 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_returned;
    vader_struct_vader_emit_c_ast$CReturn_t* _a27_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a27_obj, 1449u);
    _a27_obj->f_stores = l3;
    _a27_obj->f_value = l10;
    _a27_obj->f_snapshot_type = 0u;
    _a27_obj->f_pops_frame = false;
    l2 = (void*) _a27_obj;
    vader_array_push_ref((vader_array_t*) l4, l2);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$val_of(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 1407u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackTemporary_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 1404u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_val;
    } else if (l0.tag == 1405u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_val;
    } else {
        if (!(l0.tag == 1403u)) {
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
    if (l0.tag == 1186u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 1189u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1176u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1179u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1190u) {
        l1 = (uint8_t) 17;
    } else {
        if (!(l0.tag == 1185u)) {
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
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &l11 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(245u, (int64_t) t0, 13u, 1444u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l3, 581u);
        l5 = vader_emit_c$c_type_for_val_bare(((uint8_t) t1.payload.i));
        l6 = l1;
        l7 = vader_host_std_core$Intrinsic$byte_len(l6);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(20) + l7));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l8, l9, l6);
        l9 = std_core$write_int(l8, l9, l3);
        l10 = std_core$finish_buffer(l8, l9);
        vader_struct_vader_emit_c_ast$CParameter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a2_obj, 1444u);
        _a2_obj->f_type = l5;
        _a2_obj->f_name = l10;
        l11 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l11);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
        vader_array_t* _a4_arr = vader_array_new(29u, 1u, 1u, 581u);
        ((uint8_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (uint8_t) INT32_C(17);
        l9 = (void*) _a4_arr;
        l10 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types;
        vader_array_t* _a5_arr = vader_array_new(27u, 1u, 7u, 579u);
        ((int32_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (int32_t) l3;
        l12 = (void*) _a5_arr;
        l14 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_names;
        vader_array_t* _a6_arr = vader_array_new(24u, 0u, 12u, 574u);
        l15 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(24u, 0u, 12u, 574u);
        l16 = (void*) _a7_arr;
        vader_struct_vader_core_bytecode$BcSignature_t* _a8_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
        vader_obj_header_init(_a8_obj, 1187u);
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
    vader_array_t* _a0_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(1153u, l2);
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
        t0 = (void*) &vader_data_67;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_67;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(451u, 1u, 13u, 2544u);
    ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
    t0 = (void*) _a2_arr;
    t1 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
