#include "bootstrap.split.h"

static vader_box_t vader_emit_c$address_as_integer(vader_box_t l0);
static void vader_emit_c$append_statement(void* l0, vader_box_t l1);
static vader_box_t vader_emit_c$argument(int64_t l0);
static int32_t vader_emit_c$array_element_tag(void* l0, int32_t l1);
static vader_box_t vader_emit_c$array_header_pointer(vader_box_t l0);
static vader_box_t vader_emit_c$array_pointer(vader_box_t l0);
static int32_t vader_emit_c$array_tag(void* l0, int32_t l1);
static int32_t vader_emit_c$array_type_index_for_element(void* l0, int32_t l1);
static vader_box_t vader_emit_c$as_count(vader_box_t l0);
static vader_box_t vader_emit_c$as_size(vader_box_t l0);
static void vader_emit_c$assert_stack_empty(void* l0, vader_string_t l1);
static void vader_emit_c$assign(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_emit_c$atom_count_define(void* l0);
static int32_t vader_emit_c$atom_for(void* l0, vader_string_t l1);
static void* vader_emit_c$atom_table_of(void* l0, void* l1);
static vader_string_t vader_emit_c$aux(void* l0, vader_string_t l1);
static void* vader_emit_c$bc_struct_fields(void* l0, int32_t l1);
static vader_string_t vader_emit_c$bc_struct_name(void* l0, int32_t l1);
static vader_box_t vader_emit_c$binary_expression(void* l0, uint8_t l1, uint8_t l2);
static vader_string_t vader_emit_c$bind_array_local(void* l0, vader_box_t l1);
static vader_box_t vader_emit_c$box_call(vader_string_t l0, int32_t l1, vader_box_t l2);
static vader_box_t vader_emit_c$box_expr(vader_box_t l0, uint8_t l1, int32_t l2);
static vader_box_t vader_emit_c$box_expr_unknown(void* l0, vader_box_t l1, uint8_t l2);
static vader_box_t vader_emit_c$box_slot(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static vader_box_t vader_emit_c$box_slot_1(vader_string_t l0, vader_box_t l1);
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
static void* vader_emit_c$c_type_asserts(void* l0);
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
static void* vader_emit_c$direct_callees(void* l0);
static void vader_emit_c$directive(void* l0, vader_string_t l1);
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
static void vader_emit_c$emit_forward_decls(void* l0, void* l1);
static void vader_emit_c$emit_global_get(void* l0, void* l1);
static void vader_emit_c$emit_global_roots(void* l0, void* l1);
static void vader_emit_c$emit_global_set(void* l0, void* l1);
static void vader_emit_c$emit_global_slots(void* l0, void* l1);
static void vader_emit_c$emit_if_open(void* l0);
static void vader_emit_c$emit_import_group(void* l0, void* l1, void* l2);
static void vader_emit_c$emit_import_shims(void* l0, void* l1);
static void vader_emit_c$emit_internal_forward_decls(void* l0, void* l1, void* l2);
static vader_string_t vader_emit_c$emit_library_unit(void* l0, vader_string_t l1);
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
static void* vader_emit_c$foreign_libraries(void* l0);
static void* vader_emit_c$forward_boxed(vader_string_t l0, void* l1, void* l2);
static void* vader_emit_c$forwarded_result(void* l0, void* l1, vader_box_t l2, bool l3);
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
static void* vader_emit_c$imports_of_library(void* l0, vader_string_t l1);
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
static vader_string_t vader_emit_c$module_stem_of(vader_string_t l0);
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
static vader_box_t vader_emit_c$push_helper_for(uint8_t l0);
static void vader_emit_c$push_i64_neg(void* l0);
static void vader_emit_c$push_into_temporary(void* l0, vader_box_t l1, uint8_t l2);
static void vader_emit_c$push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7);
static void vader_emit_c$push_library_units(void* l0, void* l1, void* l2);
static void vader_emit_c$push_lit(void* l0, uint8_t l1, vader_box_t l2);
static void vader_emit_c$push_local_ref(void* l0, int32_t l1, uint8_t l2);
static void vader_emit_c$push_member_copies(void* l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4, void* l5, int32_t l6);
static vader_string_t vader_emit_c$push_mirror_allocation(void* l0, int32_t l1, void* l2, void* l3, void* l4, int32_t l5);
static void vader_emit_c$push_object(void* l0, vader_box_t l1);
static void vader_emit_c$push_offset_list(void* l0, vader_string_t l1, void* l2);
static void vader_emit_c$push_pool_array(void* l0, void* l1, vader_string_t l2, uint8_t l3, void* l4);
static void vader_emit_c$push_shift(void* l0, uint8_t l1, uint8_t l2);
static void vader_emit_c$push_struct_field(void* l0, int32_t l1, int32_t l2, vader_box_t l3, uint8_t l4);
static void vader_emit_c$push_temporary(void* l0, void* l1, uint8_t l2);
static void vader_emit_c$push_unop(void* l0, vader_string_t l1, uint8_t l2);
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
static vader_box_t vader_emit_c$signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3);
static vader_box_t vader_emit_c$single_offset_list(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_emit_c$single_reference_row(int64_t l0, vader_string_t l1, vader_string_t l2, int32_t l3, vader_string_t l4);
static vader_box_t vader_emit_c$slot_index(vader_string_t l0, vader_box_t l1);
static uint8_t vader_emit_c$slot_val_type(void* l0, int32_t l1);
static void* vader_emit_c$sorted_fn_indices(void* l0);
static void* vader_emit_c$sorted_module_stems(void* l0);
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
static vader_box_t vader_emit_c$tag_equals(vader_box_t l0, int32_t l1);
static vader_box_t vader_emit_c$tag_expression(vader_box_t l0, uint8_t l1);
static vader_box_t vader_emit_c$tag_of(vader_box_t l0);
static vader_box_t vader_emit_c$trait_check_expr(void* l0, vader_box_t l1, vader_string_t l2, int32_t l3);
static void* vader_emit_c$tramp_unbox_args(void* l0);
static void* vader_emit_c$trampoline_signature(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_emit_c$trap(vader_string_t l0);
static int32_t vader_emit_c$type_id_for_struct_symbol(void* l0, int32_t l1);
static int32_t vader_emit_c$type_index_for_name(void* l0, vader_string_t l1);
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
static vader_string_t vader_emit_c$vtable_helper_name(vader_string_t l0);
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
    l1 = vader_emit_c_ast$cast(2194u, l0);
    t0 = vader_emit_c_ast$cast(2179u, l1);
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
    l2 = std_core$write_string_at(l1, l2, 1424u);
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
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l2.tag == 725u)) {
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
    vader_obj_header_init(_a0_obj, 985u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$array_pointer(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_emit_c_ast$cast(2893u, l0);
    return t0;
}

static int32_t vader_emit_c$array_tag(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 725u) {
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

static int32_t vader_emit_c$array_type_index_for_element(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 725u) {
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

static vader_box_t vader_emit_c$as_count(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    t0 = vader_emit_c_ast$cast(2179u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$as_size(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$expression_of(l0);
    t0 = vader_emit_c_ast$cast(2567u, l1);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
    if (!(t0 != INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l1;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
    l4 = vader_host_std_core$byte_len(l2);
    l5 = vader_host_std_core$byte_len(l3);
    l4 = (l4 + l5);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(156) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l6, l4, 1703u);
    l4 = std_core$write_string_at(l6, l4, l2);
    l4 = std_core$write_string_at(l6, l4, 143u);
    l4 = std_core$write_string_at(l6, l4, l3);
    l4 = std_core$write_string_at(l6, l4, 1044u);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
    l4 = std_core$write_int(l6, l4, l5);
    l4 = std_core$write_string_at(l6, l4, 343u);
    t1 = std_core$finish_buffer(l6, l4);
    vader_host_std_abort$panic(t1);
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
    vader_obj_header_init(_a0_obj, 951u);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table)->length;
    l1 = vader_emit_c_ast$unsigned(t0);
    vader_struct_vader_emit_c_ast$CDefine_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDefine_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDefine_t));
    vader_obj_header_init(_a0_obj, 964u);
    _a0_obj->f_name = 932u;
    _a0_obj->f_value = l1;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_c$atom_for(void* l0, vader_string_t l1) {
    vader_box_t l2;
    int32_t t0;
    l2 = std_collections$MutableMap$std_core$Index$at__string__i32(l0, l1);
    if (!(l2.tag == 338u)) {
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
    t0 = ((vader_array_t*) l1)->length;
    if (t0 != INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        t2 = t1.payload.s;
        if (t2 != 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
            l5 = t1.payload.s;
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l5));
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$aux(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    int64_t l3, l5;
    void* l4 = NULL;
    int32_t l6;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = vader_host_std_core$byte_len(l2);
    l4 = (void*) vader_buffer_new((size_t) (INT64_C(23) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l4, l3, 1018u);
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_aux_counter;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l4, l3, l5);
    l3 = std_core$write_string_at(l4, l3, 977u);
    l3 = std_core$write_string_at(l4, l3, l2);
    l2 = std_core$finish_buffer(l4, l3);
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_aux_counter;
    l6 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_emit_c$FnState_t*) l0)->f_aux_counter = l6;
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        vader_array_t* _a0_arr = vader_array_new(59u, 0u, 13u, 727u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (!(l5.tag == 738u)) {
        vader_array_t* _a2_arr = vader_array_new(59u, 0u, 13u, 727u);
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
    if (!(l5.tag == 738u)) {
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
        vader_obj_header_init(_a0_obj, 985u);
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
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = vader_emit_c_ast$same_expression(((vader_struct_vader_emit_c$BoundArray_t*) l5)->f_pointer, l1);
        if (t0) {
            t1 = ((vader_struct_vader_emit_c$BoundArray_t*) l5)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = (l4 + INT64_C(1));
    }
    l6 = vader_emit_c$aux(l0, 2575u);
    vader_emit_c$declare(l0, 2893u, l6, l1);
    t2 = vader_emit_c_ast$verbatim(l6);
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t2.payload.obj;
    l2 = (void*) _a1_arr;
    vader_emit_c$statement_macro(l0, 929u, l2);
    l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays;
    vader_struct_vader_emit_c$BoundArray_t* _a2_obj = (vader_struct_vader_emit_c$BoundArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$BoundArray_t));
    vader_obj_header_init(_a2_obj, 930u);
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
    l3 = concat_2(2900u, l0);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l5 = INT64_C(0);
    l6 = ((int64_t) (int32_t) l1);
    l5 = std_core$write_int(l4, l5, l6);
    l5 = std_core$write_string_at(l4, l5, 2780u);
    t0 = std_core$finish_buffer(l4, l5);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
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
        l3 = vader_emit_c$box_call(2085u, l2, l0);
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
        vader_array_t* _a0_arr = vader_array_new(21u, 2u, 0u, 335u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(335u, 2808u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, 2178u);
        t0 = (void*) _a0_arr;
        vader_struct_vader_emit_c_ast$CCast_t* _a1_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
        vader_obj_header_init(_a1_obj, 957u);
        _a1_obj->f_types = t0;
        _a1_obj->f_value = l0;
        l5 = (void*) _a1_obj;
        l3 = vader_emit_c$box_call(2085u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(3)) {
        l3 = vader_emit_c$box_call(2107u, l2, l0);
    } else if (l1 == INT32_C(7)) {
        vader_array_t* _a2_arr = vader_array_new(21u, 2u, 0u, 335u);
        vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 1u] = vader_box_string(335u, 2809u);
        vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(335u, 2179u);
        t0 = (void*) _a2_arr;
        vader_struct_vader_emit_c_ast$CCast_t* _a3_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
        vader_obj_header_init(_a3_obj, 957u);
        _a3_obj->f_types = t0;
        _a3_obj->f_value = l0;
        l5 = (void*) _a3_obj;
        l3 = vader_emit_c$box_call(2107u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(8)) {
        l6 = vader_emit_c_ast$cast(1850u, l0);
        l3 = vader_emit_c$box_call(1961u, l2, l6);
    } else if (l1 == INT32_C(9)) {
        l3 = vader_emit_c$box_call(1961u, l2, l0);
    } else if (l1 == INT32_C(10)) {
        l3 = vader_emit_c$box_call(1634u, l2, l0);
    } else if (l1 == INT32_C(11)) {
        l6 = vader_emit_c_ast$cast(2178u, l0);
        l3 = vader_emit_c$box_call(2085u, l2, l6);
    } else if (l1 == INT32_C(12)) {
        l3 = vader_emit_c$box_call(2646u, l2, l0);
    } else {
        if (l1 == INT32_C(13)) {
            l4 = true;
        } else {
            l4 = l1 == INT32_C(17);
        }
        if (l4) {
            l3 = l0;
        } else if (l1 == INT32_C(14)) {
            vader_array_t* _a4_arr = vader_array_new(254u, 0u, 13u, 1914u);
            l5 = (void*) _a4_arr;
            l3 = vader_emit_c_ast$call(2902u, l5);
        } else if (l1 == INT32_C(15)) {
            l6 = vader_emit_c_ast$cast(2194u, l0);
            l6 = vader_emit_c_ast$cast(2179u, l6);
            l3 = vader_emit_c$box_call(2107u, l2, l6);
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

static vader_box_t vader_emit_c$box_slot(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
    void* l6 = NULL;
    int32_t l7, l9;
    vader_string_t l8 = 0;
    uint8_t l10;
    uint64_t l11;
    vader_box_t l12 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l12, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    if (l2.tag == 742u) {
        l7 = vader_emit_c$class_tag_of(l6, (uint8_t) 12);
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        l9 = vader_emit_c$atom_for(l5, l8);
        t1 = vader_emit_c$boxed_string(l7, l9);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 741u) {
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        l7 = vader_emit_c$scalar_tag(l6, l10);
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t1 = vader_emit_c$boxed_scalar(l7, l10, l11);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 743u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        l7 = vader_emit_c$type_id_for_struct_symbol(l6, l9);
    } else {
        l7 = l4;
    }
    l12 = l2;
    l12 = vader_emit_c$emit_data_value(l0, l1, l12, l3, l5);
    t1 = vader_emit_c$boxed_object(l7, l12);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$box_slot_1(vader_string_t l0, vader_box_t l1) {
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
    t0 = concat_2(l0, 389u);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$call(2863u, l2);
    vader_struct_vader_emit_c_ast$CIndex_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a1_obj, 976u);
    _a1_obj->f_base = t1;
    _a1_obj->f_index = l1;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = (void*) &vader_data_52;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l4 = vader_emit_c_ast$cast(3017u, l1);
    t1 = vader_emit_c_ast$designated(422u, l4);
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
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
    vader_array_t* _a0_arr = vader_array_new(101u, 1u, 13u, 984u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1424u);
        l5 = std_core$write_int(l4, l5, l3);
        l6 = std_core$finish_buffer(l4, l5);
        vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a1_obj, 984u);
        _a1_obj->f_type = 2905u;
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
        return 2871u;
    }
    return 2881u;
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
        l4 = vader_emit_c_ast$cast(1850u, l3);
        l4 = vader_emit_c_ast$designated(411u, l4);
    } else if (l1 == INT32_C(12)) {
        l4 = vader_emit_c_ast$designated(405u, l3);
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
            vader_array_t* _a0_arr = vader_array_new(21u, 3u, 0u, 335u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(335u, 2808u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(335u, 2178u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, 2179u);
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
                vader_array_t* _a1_arr = vader_array_new(21u, 2u, 0u, 335u);
                vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 1u] = vader_box_string(335u, 2178u);
                vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = vader_box_string(335u, 2179u);
                t0 = (void*) _a1_arr;
                l4 = vader_emit_c$integer_payload(t0, l3);
            } else {
                if (l1 == INT32_C(8)) {
                    l5 = true;
                } else {
                    l5 = l1 == INT32_C(4);
                }
                if (l5) {
                    vader_array_t* _a2_arr = vader_array_new(21u, 1u, 0u, 335u);
                    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(335u, 2179u);
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
                    t1 = concat_3(1699u, l6, 1038u);
                    vader_host_std_abort$panic(t1);
                    vader_unreachable("a no-return call returned");
                }
            }
        }
    }
    l3 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_52;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l4.payload.obj;
    t0 = (void*) _a4_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a5_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l7;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l3.payload.obj;
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
    t0 = (void*) &vader_data_52;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l4 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l1));
    t1 = vader_emit_c_ast$designated(428u, l4);
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
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
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = vader_emit_c$is_continue_branch(t0, l1);
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            return vader_ref_box(t0);
        }
        l2 = (l2 + INT64_C(1));
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        t2 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_end_pc;
        t3 = vader_chk_add(i32, t2, INT32_C(1));
        if (t3 == l1) {
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
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
    t0 = vader_emit_c_ast$cast(2918u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 540u);
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
    l5 = ((vader_array_t*) l2)->length;
    while ((l4 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
        l6 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_ids);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
        l7 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
        std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l1, l6, l7);
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
    l1 = vader_host_std_core$byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 1u, 340u);
    l2 = (void*) _a0_arr;
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        l4 = vader_host_std_core$byte_at(l0, l3);
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
                    t2 = vader_host_std_core$byte_at(l0, l8);
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
    t4 = vader_host_std_core$bytes_to_string(l2);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        if (l5.tag == 738u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            if (t1 == 0u) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            t0 = l5.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields)->length;
            if (t2 == INT64_C(0)) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            l7 = ((int32_t) (int64_t) l3);
            l6 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct_vader_emit_c$MirrorCrossings_t*) l1)->f_lent, l7);
            l9 = ((int32_t) (int64_t) l3);
            l8 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct_vader_emit_c$MirrorCrossings_t*) l1)->f_copied, l9);
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
            vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t3.payload.obj;
            l12 = (void*) _a2_arr;
            l13 = vader_emit_c_ast$call(2568u, l12);
            if (l8) {
                t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l11)->f_size;
                l14 = vader_emit_c_ast$number(t2);
                l15 = vader_emit_c_ast$binary((uint8_t) 11, l14, l13);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l16 = concat_2(t1, 154u);
                l17 = vader_emit_c$static_assert(l15, l16);
                vader_array_push_ref((vader_array_t*) l2, l17.payload.obj);
            } else {
                t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l11)->f_size;
                l18 = vader_emit_c_ast$number(t2);
                l19 = vader_emit_c_ast$binary((uint8_t) 8, l18, l13);
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
                l20 = concat_2(t1, 201u);
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
                l25 = concat_2(t1, 123u);
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

static void* vader_emit_c$c_type_asserts(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l4, l5, l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l13 = 0;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null();
    uint8_t l12, l15;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l11, &l14, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a1_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature;
        l8 = INT64_C(0);
        l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l7)->f_params)->length;
        while ((l8 < l9)) {
            l11 = vader_core_bytecode$param_c_type(l6, l8);
            if (l11.tag == 0u) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l10 = l11.payload.s;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l7)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l8, 340u);
            l12 = ((uint8_t) t0.payload.i);
            vader_emit_c$push_c_type_assert(l10, l12, l2, l1);
            l8 = (l8 + INT64_C(1));
        }
        l14 = vader_core_bytecode$c_result_type(l6);
        if (l14.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l13 = l14.payload.s;
        l15 = vader_core_bytecode$bc_single_result(l7);
        vader_emit_c$push_c_type_assert(l13, l15, l2, l1);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
        l1 = 2810u;
        return l1;
    }
    if (l0 == INT32_C(2)) {
        l1 = 2807u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2808u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2809u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2180u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2177u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2178u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2179u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2011u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1850u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2808u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2810u;
    } else if (l0 == INT32_C(13)) {
        l1 = 3017u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2905u;
    }
    return l1;
}

static vader_string_t vader_emit_c$c_type_for_val_bare(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2180u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2177u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2178u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2179u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2810u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2807u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2808u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2809u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2011u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1850u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1634u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2808u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2975u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2905u;
    } else if (l0 == INT32_C(14)) {
        l1 = 3016u;
    } else if (l0 == INT32_C(15)) {
        l1 = 3017u;
    } else if (l0 == INT32_C(16)) {
        l1 = 3017u;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2905u;
    }
    return l1;
}

static int32_t vader_emit_c$callee_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 760u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 789u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        return t1;
    }
    if (!(l0.tag == 788u)) {
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
    if (l1.tag == 760u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        l2 = ((int64_t) (int32_t) t1);
        if ((INT64_C(0) <= l2)) {
            l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions)->length;
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
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            t2 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature);
            return t2;
        }
        return INT64_C(1);
    }
    if (!(l1.tag == 761u)) {
        return INT64_C(1);
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
    l2 = ((int64_t) (int32_t) t1);
    if ((INT64_C(0) <= l2)) {
        l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_imports)->length;
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
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
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
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 735u) {
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
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l3.tag == 735u)) {
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
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 735u) {
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
        l3 = ((vader_array_t*) l0)->length;
        while ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            if (l4.tag == 735u) {
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
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l3 = t0.payload.s;
    l4 = vader_emit_c$empty_struct_offsets();
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        t1 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_name;
        l11 = vader_emit_c$field_c_name(t1);
        l12 = concat_5(2422u, l3, 360u, l11, 321u);
        if (l10.tag == 735u) {
            t2 = l10.payload.obj;
            t3 = vader_core_bytecode$is_string_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t2)->f_val);
            if (t3) {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_str_offsets, vader_box_string(335u, l12));
            }
        } else {
            t4 = vader_emit_c$val_type_of_bc_type(l10);
            if (t4 == INT32_C(16)) {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_ref_offsets, vader_box_string(335u, l12));
            } else {
                vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_c$StructOffsets_t*) l4)->f_ptr_offsets, vader_box_string(335u, l12));
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes)->length;
    l3 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 974u) {
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
        t0 = vader_emit_c$payload(l1, 2418u);
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
    t0 = std_iter$is_empty__string(l1);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
        l2 = (void*) _a0_arr;
        l3 = INT32_C(1);
        l4 = INT64_C(0);
        l5 = ((vader_array_t*) l0)->length;
        vader_array_t* _pc12_hdr = (vader_array_t*) l2;
        size_t _pc12_len = _pc12_hdr->length;
        size_t _pc12_cap = (_pc12_hdr->offset == 0 && !vader_array_is_borrowed(_pc12_hdr) && _pc12_hdr->length >= _pc12_hdr->buf->length) ? _pc12_hdr->capacity : (size_t) 0;
        void* _pc12_slots = _pc12_hdr->buf->slots;
        for (;;) {
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                if (t2 == 0u) {
                    if (VADER_LIKELY(_pc12_len < _pc12_cap)) {
                        ((int32_t*) _pc12_slots)[_pc12_len] = (int32_t) (INT32_C(0));
                        _pc12_len += 1;
                    } else {
                        _pc12_hdr->length = _pc12_len;
                        if (_pc12_hdr->buf->length < _pc12_len) {
                            _pc12_hdr->buf->length = _pc12_len;
                        }
                        vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                        _pc12_hdr = (vader_array_t*) l2;
                        _pc12_len = _pc12_hdr->length;
                        _pc12_cap = (_pc12_hdr->offset == 0 && !vader_array_is_borrowed(_pc12_hdr) && _pc12_hdr->length >= _pc12_hdr->buf->length) ? _pc12_hdr->capacity : (size_t) 0;
                        _pc12_slots = _pc12_hdr->buf->slots;
                    }
                } else {
                    if (VADER_LIKELY(_pc12_len < _pc12_cap)) {
                        ((int32_t*) _pc12_slots)[_pc12_len] = (int32_t) (l3);
                        _pc12_len += 1;
                    } else {
                        _pc12_hdr->length = _pc12_len;
                        if (_pc12_hdr->buf->length < _pc12_len) {
                            _pc12_hdr->buf->length = _pc12_len;
                        }
                        vader_array_push_i32((vader_array_t*) l2, l3);
                        _pc12_hdr = (vader_array_t*) l2;
                        _pc12_len = _pc12_hdr->length;
                        _pc12_cap = (_pc12_hdr->offset == 0 && !vader_array_is_borrowed(_pc12_hdr) && _pc12_hdr->length >= _pc12_hdr->buf->length) ? _pc12_hdr->capacity : (size_t) 0;
                        _pc12_slots = _pc12_hdr->buf->slots;
                    }
                    l3 = vader_chk_add(i32, l3, INT32_C(1));
                }
                l4 = (l4 + INT64_C(1));
                continue;
            }
            _pc12_hdr->length = _pc12_len;
            if (_pc12_hdr->buf->length < _pc12_len) {
                _pc12_hdr->buf->length = _pc12_len;
            }
            break;
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 540u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a5_obj;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l1)->length;
    while ((l4 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l4];
        l8 = t1.payload.s;
        l3 = vader_chk_add(i32, ((int32_t) (int64_t) l4), INT32_C(1));
        std_collections$get_or_put__string__i32(l2, l8, l3);
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a7_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t1 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l4];
        t2 = t1.payload.s;
        if (t2 == 0u) {
            vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        } else {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l4];
            l8 = t1.payload.s;
            l9 = std_collections$MutableMap$std_core$Index$at__string__i32(l2, l8);
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
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_c_8_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_8_t));
    vader_obj_header_init(_a0_obj, 370u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = __lambda_vader_emit_c_7(l3, l7);
        vader_array_push_bool((vader_array_t*) l4, l8);
        l6 = (l6 + INT64_C(1));
    }
    l2 = l4;
    l3 = l0;
    vader_array_t* _a4_arr = vader_array_new(3u, 0u, 13u, 22u);
    l4 = (void*) _a4_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a5_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l7 = vader_emit_c$direct_callees(t0);
        vader_array_push_ref((vader_array_t*) l4, l7);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_support_fixpoint$Graph_t* _a7_obj = (vader_struct_vader_support_fixpoint$Graph_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_fixpoint$Graph_t));
    vader_obj_header_init(_a7_obj, 1401u);
    _a7_obj->f_successors = l4;
    t0 = (void*) _a7_obj;
    vader_support_fixpoint$solve_reachability(t0, l2);
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
    if (l1.tag == 797u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l3 = ((int64_t) (int32_t) t1);
        vader_struct_vader_emit_c_ast$CIntegerLiteral_t* _a0_obj = (vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIntegerLiteral_t));
        vader_obj_header_init(_a0_obj, 978u);
        _a0_obj->f_class = (uint8_t) 2;
        _a0_obj->f_value = l3;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 817u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        vader_struct_vader_emit_c_ast$CIntegerLiteral_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIntegerLiteral_t));
        vader_obj_header_init(_a1_obj, 978u);
        _a1_obj->f_class = (uint8_t) 3;
        _a1_obj->f_value = l3;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l1.tag == 776u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        t3 = vader_emit_c$float_lit(t2);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else if (l1.tag == 748u) {
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        if (t4) {
            l4 = 2746u;
        } else {
            l4 = 1977u;
        }
        l2 = vader_emit_c_ast$verbatim(l4);
    } else if (l1.tag == 763u) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t6 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        l6 = (uint64_t) (int64_t) t6;
        l3 = std_core$write_unsigned(l5, l3, l6);
        l3 = std_core$write_string_at(l5, l3, 2780u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else if (l1.tag == 848u) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(42));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l5, l3, 2904u);
        t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_null_tag;
        l7 = ((int64_t) (int32_t) t1);
        l3 = std_core$write_int(l5, l3, l7);
        l3 = std_core$write_string_at(l5, l3, 2783u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    } else {
        if (!(l1.tag == 864u)) {
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
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9];
        l7 = ((int64_t) (int32_t) t1);
        l3 = std_core$write_int(l5, l3, l7);
        l3 = std_core$write_string_at(l5, l3, 2780u);
        t3 = std_core$finish_buffer(l5, l3);
        l2 = vader_emit_c_ast$verbatim(t3);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$const_val(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 797u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 817u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 776u) {
        l1 = (uint8_t) 9;
    } else if (l0.tag == 748u) {
        l1 = (uint8_t) 10;
    } else if (l0.tag == 763u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 848u) {
        l1 = (uint8_t) 17;
    } else {
        if (!(l0.tag == 864u)) {
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes)->length;
    if (t0 == INT64_C(0)) {
        return ((vader_struct_vader_emit_c$FnState_t*) l0)->f_root;
    }
    l1 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes;
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes)->length;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l3.tag == 974u)) {
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
        vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
        l4 = (void*) _a0_arr;
        l6 = vader_emit_c_ast$call(923u, l4);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    vader_array_t* _pc8_hdr = (vader_array_t*) l1;
    size_t _pc8_len = _pc8_hdr->length;
    size_t _pc8_cap = (_pc8_hdr->offset == 0 && !vader_array_is_borrowed(_pc8_hdr) && _pc8_hdr->length >= _pc8_hdr->buf->length) ? _pc8_hdr->capacity : (size_t) 0;
    void* _pc8_slots = _pc8_hdr->buf->slots;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            if (l5.tag == 760u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
                if (VADER_LIKELY(_pc8_len < _pc8_cap)) {
                    ((int32_t*) _pc8_slots)[_pc8_len] = (int32_t) (l6);
                    _pc8_len += 1;
                } else {
                    _pc8_hdr->length = _pc8_len;
                    if (_pc8_hdr->buf->length < _pc8_len) {
                        _pc8_hdr->buf->length = _pc8_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, l6);
                    _pc8_hdr = (vader_array_t*) l1;
                    _pc8_len = _pc8_hdr->length;
                    _pc8_cap = (_pc8_hdr->offset == 0 && !vader_array_is_borrowed(_pc8_hdr) && _pc8_hdr->length >= _pc8_hdr->buf->length) ? _pc8_hdr->capacity : (size_t) 0;
                    _pc8_slots = _pc8_hdr->buf->slots;
                }
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc8_hdr->length = _pc8_len;
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
    vader_obj_header_init(_a0_obj, 966u);
    _a0_obj->f_text = l1;
    l2 = (void*) _a0_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_obj_header_init(_a0_obj, 984u);
    _a0_obj->f_type = 2905u;
    _a0_obj->f_name = 2502u;
    l1 = (void*) _a0_obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_params)->length;
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
    l5 = vader_emit_c$vtable_helper_name(l1);
    l6 = vader_emit_c$dispatcher_parameters(l2);
    vader_struct_vader_emit_c_ast$CSignature_t* _a0_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a0_obj, 992u);
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
            l3 = 1845u;
        } else {
            l3 = 2356u;
        }
        l4 = vader_core_bytecode$val_type_name(l1);
        t0 = concat_4(2862u, l3, 977u, l4);
        { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(91u, 0u, 13u, 930u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_bound_arrays;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
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
    l1 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
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
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        return (uint8_t) 0;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    if (!(l1.tag == 741u)) {
        return (uint8_t) 0;
    }
    t1 = l1.payload.obj;
    return ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_kind;
}

static void vader_emit_c$emit_agg_data_entry(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l11 = NULL;
    int64_t l6, l7, l10, l12;
    vader_box_t l8 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l13 = 0;
    int32_t l14;
    vader_box_t* gc_roots[2] = { &l8, &l15 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcAggregateData_t*) l3)->f_elements)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a1_arr;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcAggregateData_t*) l3)->f_elements)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcAggregateData_t*) l3)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_vader_emit_c$PoolArray_t*) l2)->f_name;
        l10 = vader_host_std_core$byte_len(l9);
        l11 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l10));
        l12 = INT64_C(0);
        l12 = std_core$write_string_at(l11, l12, l9);
        l12 = std_core$write_string_at(l11, l12, 1023u);
        l12 = std_core$write_int(l11, l12, l6);
        l13 = std_core$finish_buffer(l11, l12);
        l14 = ((vader_struct_vader_emit_c$PoolArray_t*) l2)->f_element_tag;
        l15 = vader_emit_c$box_slot(l0, l1, l8, l13, l14, l4);
        vader_array_push_ref((vader_array_t*) l5, l15.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    vader_emit_c$push_pool_array(l1, l2, 2905u, (uint8_t) 0, l5);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(2866u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 5u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2867u, l6);
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
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l7 = vader_core_bytecode$array_kind_of(l6, l4);
    l8 = vader_emit_c$typed_array_fill_for(l7);
    l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) l1)->f_bounds_safe;
    l10 = vader_emit_c$emit_slot_array_local(l0, l3, l2, l9);
    if (l8.tag == 0u) {
        t0 = vader_emit_c$ref_carrying_element(l6, l4);
        if (t0) {
            l11 = vader_emit_c$val_type_of_bc_type(l6);
            if (l11 == INT32_C(16)) {
                l12 = 2886u;
            } else {
                l12 = 2885u;
            }
            t1 = concat_2(l10, 389u);
            l3 = vader_emit_c_ast$verbatim(t1);
            l6 = vader_emit_c$slot_index(l10, l2);
            vader_array_t* _a1_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l6.payload.obj;
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
            l13 = (void*) _a1_arr;
            l3 = vader_emit_c_ast$call(l12, l13);
            vader_emit_c$push_into_temporary(l0, l3, l11);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l8.tag == 0u) {
        l3 = vader_emit_c$slot_index(l10, l2);
        l3 = vader_emit_c$box_slot_1(l10, l3);
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
        l14 = std_core$write_string_at(l13, l14, 2780u);
        t1 = std_core$finish_buffer(l13, l14);
        l16 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a2_arr = vader_array_new(254u, 3u, 13u, 1914u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l16.payload.obj;
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l6.payload.obj;
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3.payload.obj;
        l13 = (void*) _a2_arr;
        l3 = vader_emit_c_ast$call(2884u, l13);
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
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$array_header_pointer(t0);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 981u);
    _a0_obj->f_base = t1;
    _a0_obj->f_member = 2273u;
    _a0_obj->f_arrow = true;
    l1 = (void*) _a0_obj;
    vader_emit_c$push_into_temporary(l0, vader_ref_box(l1), (uint8_t) 3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_array_new(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3, l5, l6;
    uint8_t l4, l16;
    vader_string_t l7 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    int64_t l8, l9;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[13] = {
        &l10, &l11, &l12, &l13, &l17, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &t0,
    };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l14, &l15, &t2 };
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = vader_core_bytecode$array_kind_of(t0, l2);
    l5 = vader_core_bytecode$array_kind_index(l4);
    l6 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l1)->f_length;
    l7 = vader_emit_c$aux(l0, 1562u);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l1)->f_type_id;
    l9 = ((int64_t) (int32_t) t1);
    l8 = std_core$write_int(l2, l8, l9);
    l8 = std_core$write_string_at(l2, l8, 2780u);
    t2 = std_core$finish_buffer(l2, l8);
    l10 = vader_emit_c_ast$verbatim(t2);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l6);
    l8 = std_core$write_int(l2, l8, l9);
    l8 = std_core$write_string_at(l2, l8, 2780u);
    t2 = std_core$finish_buffer(l2, l8);
    l11 = vader_emit_c_ast$verbatim(t2);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l5);
    l8 = std_core$write_int(l2, l8, l9);
    l8 = std_core$write_string_at(l2, l8, 2780u);
    t2 = std_core$finish_buffer(l2, l8);
    l12 = vader_emit_c_ast$verbatim(t2);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l8 = INT64_C(0);
    l9 = ((int64_t) (int32_t) l3);
    l8 = std_core$write_int(l2, l8, l9);
    l8 = std_core$write_string_at(l2, l8, 2780u);
    t2 = std_core$finish_buffer(l2, l8);
    l13 = vader_emit_c_ast$verbatim(t2);
    vader_array_t* _a1_arr = vader_array_new(254u, 4u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 3u] = l13.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l11.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l10.payload.obj;
    l2 = (void*) _a1_arr;
    l10 = vader_emit_c_ast$call(2869u, l2);
    vader_emit_c$declare(l0, 2893u, l7, l10);
    l10 = vader_emit_c$typed_array_fill_for(l4);
    l3 = INT32_C(0);
    while ((l3 < l6)) {
        l11 = vader_emit_c$pop(l0);
        t1 = vader_chk_sub(i32, l6, INT32_C(1));
        l5 = vader_chk_sub(i32, t1, l3);
        if (l10.tag == 0u) {
            if (l4 == INT32_C(13)) {
                l19 = vader_emit_c$fresh_slot(l7, l5);
                l20 = vader_emit_c$typed_slot(3017u, l7, l19);
                l21 = vader_emit_c$coerced_as(l0, l11, (uint8_t) 16);
                vader_emit_c$assign(l0, l20, l21);
            } else {
                l22 = vader_emit_c$fresh_slot(l7, l5);
                l23 = vader_emit_c$box_slot_1(l7, l22);
                l24 = vader_emit_c$coerced_as(l0, l11, (uint8_t) 17);
                vader_emit_c$assign(l0, l23, l24);
            }
        } else {
            t3 = l10.payload.obj;
            l14 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_cty;
            l12 = vader_emit_c$fresh_slot(l7, l5);
            l13 = vader_emit_c$typed_slot(l14, l7, l12);
            t3 = l10.payload.obj;
            l15 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_cty;
            t3 = l10.payload.obj;
            l16 = ((vader_struct_vader_emit_c$SlotFill_t*) t3)->f_val;
            l17 = vader_emit_c$coerced_as(l0, l11, l16);
            l18 = vader_emit_c_ast$cast(l15, l17);
            vader_emit_c$assign(l0, l13, l18);
        }
        l3 = (l3 + INT32_C(1));
    }
    l10 = vader_emit_c_ast$verbatim(l7);
    vader_emit_c$push_object(l0, l10);
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
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
        vader_array_t* _a1_arr = vader_array_new(254u, 2u, 13u, 1914u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l13.payload.obj;
        l10 = (void*) _a1_arr;
        l8 = vader_emit_c_ast$call(l12, l10);
        vader_emit_c$evaluate(l0, l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l1)->f_type_id;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2872u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(2889u, l1);
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
    l3 = vader_emit_c$aux(l0, 1562u);
    t0 = vader_emit_c$object_pointer_of(l2);
    l2 = vader_emit_c$array_pointer(t0);
    l1 = vader_emit_c$as_count(l1);
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2890u, l4);
    vader_emit_c$declare(l0, 2893u, l3, l1);
    l1 = vader_emit_c_ast$verbatim(l3);
    vader_emit_c$push_object(l0, l1);
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
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    t0 = vader_core_bytecode$array_kind_of(l7, l5);
    l8 = vader_emit_c$typed_array_fill_for(t0);
    l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) l1)->f_bounds_safe;
    l10 = vader_emit_c$emit_slot_array_local(l0, l4, l3, l9);
    if (l8.tag == 0u) {
        t1 = vader_emit_c$ref_carrying_element(l7, l5);
        if (t1) {
            if (l7.tag == 734u) {
                t2 = concat_2(l10, 389u);
                l4 = vader_emit_c_ast$verbatim(t2);
                l7 = vader_emit_c$slot_index(l10, l3);
                l11 = vader_emit_c$coerced_as(l0, l2, (uint8_t) 17);
                vader_array_t* _a1_arr = vader_array_new(254u, 3u, 13u, 1914u);
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l11.payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l7.payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
                l5 = (void*) _a1_arr;
                l4 = vader_emit_c_ast$call(2888u, l5);
                vader_emit_c$evaluate(l0, l4);
            } else {
                t2 = concat_2(l10, 389u);
                l4 = vader_emit_c_ast$verbatim(t2);
                l7 = vader_emit_c$slot_index(l10, l3);
                l11 = vader_emit_c$object_pointer_of(l2);
                vader_array_t* _a2_arr = vader_array_new(254u, 3u, 13u, 1914u);
                ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l11.payload.obj;
                ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l7.payload.obj;
                ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l4.payload.obj;
                l5 = (void*) _a2_arr;
                l4 = vader_emit_c_ast$call(2887u, l5);
                vader_emit_c$evaluate(l0, l4);
            }
            t2 = concat_2(l10, 389u);
            l4 = vader_emit_c_ast$verbatim(t2);
            vader_emit_c$write_barrier_for(l0, l4, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l8.tag == 0u) {
        l4 = vader_emit_c$slot_index(l10, l3);
        l4 = vader_emit_c$box_slot_1(l10, l4);
        l7 = vader_emit_c$coerced_as(l0, l2, (uint8_t) 17);
        vader_emit_c$assign(l0, l4, l7);
        t2 = concat_2(l10, 389u);
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
    l5 = vader_emit_c$aux(l0, 1562u);
    t0 = vader_emit_c$object_pointer_of(l4);
    l4 = vader_emit_c$array_pointer(t0);
    l3 = vader_emit_c$as_count(l3);
    l2 = vader_emit_c$as_count(l2);
    vader_array_t* _a0_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l6 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(2891u, l6);
    vader_emit_c$declare(l0, 2893u, l5, l2);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, 623u);
    l2 = (void*) _a0_arr;
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table)->length;
    if (t0 == INT64_C(0)) {
        t1 = (void*) &vader_data_52;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_52;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_52;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l5 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_52;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_52;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
        l8 = vader_emit_c_ast$verbatim(250u);
        vader_array_t* _a6_arr = vader_array_new(254u, 6u, 13u, 1914u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 5u] = l8.payload.obj;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 4u] = l7;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 3u] = l6;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 2u] = l5;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l4;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l3;
        t1 = (void*) _a6_arr;
        l8 = vader_emit_c_ast$initializer_list(t1);
        t2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l9 = vader_emit_c$global_storage(t2);
        vader_array_t* _a7_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l8.payload.obj;
        t1 = (void*) _a7_arr;
        l8 = vader_emit_c_ast$initializer_list(t1);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a8_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a8_obj, 963u);
        _a8_obj->f_name = 2895u;
        _a8_obj->f_length = vader_box_i32(338u, INT32_C(1));
        _a8_obj->f_value = l8;
        l3 = (void*) _a8_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a9_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a9_obj, 972u);
        _a9_obj->f_storage = l9;
        _a9_obj->f_constant = true;
        _a9_obj->f_type = 2896u;
        _a9_obj->f_declarator = l3;
        l3 = (void*) _a9_obj;
        l8 = vader_emit_c$atom_count_define(l0);
        vader_array_t* _a10_arr = vader_array_new(256u, 2u, 13u, 1922u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_struct_vader_emit_c_ast$CSection_t* _a11_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
        vader_obj_header_init(_a11_obj, 990u);
        _a11_obj->f_comment = l2;
        _a11_obj->f_items = l3;
        l3 = (void*) _a11_obj;
        vader_emit_c_ast$print_section(l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l9 = vader_emit_c$global_storage(t2);
    vader_array_t* _a12_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a12_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l10);
    l3 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l4 = (void*) _a14_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table)->length;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l10);
    l4 = (void*) _a15_arr;
    l10 = INT64_C(0);
    l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_atom_table;
    l11 = ((vader_array_t*) l5)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t3 = vader_array_box_slots(_a16_slotarr->buf)[_a16_slotarr->offset + (size_t) l12];
        l13 = t3.payload.s;
        l14 = vader_host_std_core$byte_len(l13);
        t4 = vader_emit_c$c_string_lit(l13);
        l15 = concat_2(t4, 44u);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(335u, l15));
        l8 = vader_emit_c_ast$verbatim(2894u);
        l16 = vader_emit_c_ast$number(l10);
        vader_struct_vader_emit_c_ast$CIndex_t* _a17_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
        vader_obj_header_init(_a17_obj, 976u);
        _a17_obj->f_base = l8;
        _a17_obj->f_index = l16;
        l6 = (void*) _a17_obj;
        t1 = (void*) &vader_data_52;
        vader_array_t* _a18_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l7 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_52;
        vader_array_t* _a19_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        l17 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
        l18 = vader_emit_c_ast$unsigned(l14);
        l19 = vader_emit_c_ast$verbatim(930u);
        t1 = (void*) &vader_data_52;
        vader_array_t* _a20_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l20 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
        l21 = vader_emit_c_ast$address_of(vader_ref_box(l6));
        vader_array_t* _a21_arr = vader_array_new(254u, 6u, 13u, 1914u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 5u] = l21.payload.obj;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 4u] = l20;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 3u] = l19.payload.obj;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 2u] = l18.payload.obj;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 1u] = l17;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = l7;
        t1 = (void*) _a21_arr;
        l22 = vader_emit_c_ast$initializer_list(t1);
        vader_array_push_ref((vader_array_t*) l4, l22.payload.obj);
        l23 = vader_chk_add(i64, l14, INT64_C(1));
        l10 = vader_chk_add(i64, l10, l23);
        l12 = (l12 + INT64_C(1));
    }
    t1 = (void*) &vader_data_51;
    vader_array_t* _a22_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
    l5 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_emit_c_ast$CStringLiterals_t* _a23_obj = (vader_struct_vader_emit_c_ast$CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStringLiterals_t));
    vader_obj_header_init(_a23_obj, 994u);
    _a23_obj->f_literals = l3;
    l3 = (void*) _a23_obj;
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a24_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a24_obj, 963u);
    _a24_obj->f_name = 2894u;
    _a24_obj->f_length = vader_ref_box(l5);
    _a24_obj->f_value = vader_ref_box(l3);
    l3 = (void*) _a24_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a25_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a25_obj, 972u);
    _a25_obj->f_storage = l9;
    _a25_obj->f_constant = true;
    _a25_obj->f_type = 1753u;
    _a25_obj->f_declarator = l3;
    l3 = (void*) _a25_obj;
    t1 = (void*) &vader_data_51;
    vader_array_t* _a26_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
    l5 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) INT64_C(0));
    l8 = vader_emit_c_ast$initializer_list(l4);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a27_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a27_obj, 963u);
    _a27_obj->f_name = 2895u;
    _a27_obj->f_length = vader_ref_box(l5);
    _a27_obj->f_value = l8;
    l4 = (void*) _a27_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a28_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a28_obj, 972u);
    _a28_obj->f_storage = l9;
    _a28_obj->f_constant = true;
    _a28_obj->f_type = 2896u;
    _a28_obj->f_declarator = l4;
    l4 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(256u, 1u, 13u, 1922u);
    ((void**) _a29_arr->buf->slots)[_a29_arr->offset + 0u] = l3;
    l3 = (void*) _a29_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a30_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a30_obj, 990u);
    _a30_obj->f_comment = l2;
    _a30_obj->f_items = l3;
    l2 = (void*) _a30_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a31_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(256u, 1u, 13u, 1922u);
    ((void**) _a32_arr->buf->slots)[_a32_arr->offset + 0u] = l4;
    l3 = (void*) _a32_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a33_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a33_obj, 990u);
    _a33_obj->f_comment = l2;
    _a33_obj->f_items = l3;
    l2 = (void*) _a33_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a34_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a34_arr;
    t3 = vader_emit_c$atom_count_define(l0);
    vader_array_t* _a35_arr = vader_array_new(256u, 1u, 13u, 1922u);
    ((void**) _a35_arr->buf->slots)[_a35_arr->offset + 0u] = t3.payload.obj;
    l3 = (void*) _a35_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a36_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a36_obj, 990u);
    _a36_obj->f_comment = l2;
    _a36_obj->f_items = l3;
    l2 = (void*) _a36_obj;
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
    l1 = vader_emit_c_ast$around(305u, l1, 339u);
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
    l1 = vader_emit_c_ast$around(306u, l1, 338u);
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
        if (!(l1.tag == 734u)) {
            l5 = vader_emit_c$object_pointer_of(l3);
            vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l5.payload.obj;
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
            l4 = (void*) _a0_arr;
            l5 = vader_emit_c_ast$call(2880u, l4);
            vader_emit_c$evaluate(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l6 = vader_emit_c$boxed_push_helper(l3);
    l5 = vader_emit_c$coerced_as(l0, l3, (uint8_t) 17);
    vader_array_t* _a1_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l5.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l2.payload.obj;
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
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l4 = vader_emit_c$branch_target(((vader_struct_vader_emit_c$FnState_t*) l0)->f_scopes, l3);
    if (!(l4.tag == 941u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(91));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 1874u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 54u);
        l10 = ((int64_t) (int32_t) l3);
        l7 = std_core$write_int(l6, l7, l10);
        l7 = std_core$write_string_at(l6, l7, 321u);
        t0 = std_core$finish_buffer(l6, l7);
        std_abort$todo(t0);
        vader_unreachable("a no-return call returned");
    }
    t1 = l4.payload.obj;
    t2 = vader_emit_c$is_continue_branch(t1, l3);
    if (t2) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(25));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2296u);
        t1 = l4.payload.obj;
        t3 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t1)->f_opener_pc;
        l8 = ((int64_t) (int32_t) t3);
        l7 = std_core$write_int(l6, l7, l8);
        l5 = std_core$finish_buffer(l6, l7);
    } else {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(24));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 1881u);
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
        l7 = std_core$write_string_at(l6, l7, 1648u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 321u);
        l9 = std_core$finish_buffer(l6, l7);
        vader_emit_c$assert_stack_empty(l0, l9);
        l4 = vader_emit_c$expression_of(l4);
        vader_struct_vader_emit_c_ast$CGoto_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGoto_t));
        vader_obj_header_init(_a1_obj, 973u);
        _a1_obj->f_label = l5;
        _a1_obj->f_condition = l4;
        l6 = (void*) _a1_obj;
        vader_emit_c$append_statement(l0, vader_ref_box(l6));
    } else {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(28));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 1646u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 321u);
        l9 = std_core$finish_buffer(l6, l7);
        vader_emit_c$assert_stack_empty(l0, l9);
        vader_struct_vader_emit_c_ast$CGoto_t* _a2_obj = (vader_struct_vader_emit_c_ast$CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGoto_t));
        vader_obj_header_init(_a2_obj, 973u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(2913u, l1);
    l2 = vader_emit_c_ast$cast(3017u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
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
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2907u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2919u, l4);
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
    vader_obj_header_init(_a0_obj, 932u);
    _a0_obj->f_entry_mangled = l5;
    _a0_obj->f_split = true;
    _a0_obj->f_atom_universe = l6;
    _a0_obj->f_verify_bounds = l7;
    _a0_obj->f_library_units = true;
    l4 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_entry_mangled;
    l6 = vader_emit_c$internal_fn_flags(l0, l3, l5);
    l4 = vader_emit_c$new_ctx(l0, l4, l6);
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 618u);
    _a2_obj->f_parts = t0;
    t0 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a3_obj, 986u);
    _a3_obj->f_out = t0;
    _a3_obj->f_started = false;
    l6 = (void*) _a3_obj;
    vader_emit_c$emit_preamble(l6, 654u);
    vader_emit_c$emit_struct_typedefs(l4, l6);
    vader_emit_c$emit_fn_sig_typedefs(l4, l6);
    vader_emit_c$emit_forward_decls(l4, l6);
    vader_emit_c$emit_closure_forward_decls(l4, l6);
    vader_emit_c$emit_vtable_forward_decls(l4, l6);
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a4_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a5_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a5_obj, 618u);
    _a5_obj->f_parts = t0;
    t0 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a6_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a6_obj, 986u);
    _a6_obj->f_out = t0;
    _a6_obj->f_started = false;
    l8 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a7_arr->buf)[_a7_arr->offset + 0u] = vader_box_string(335u, 652u);
    l9 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CInclude_t* _a8_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a8_obj, 975u);
    _a8_obj->f_path = 2855u;
    _a8_obj->f_system = false;
    t0 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(256u, 1u, 13u, 1922u);
    ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
    l10 = (void*) _a9_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a10_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a10_obj, 990u);
    _a10_obj->f_comment = l9;
    _a10_obj->f_items = l10;
    l9 = (void*) _a10_obj;
    vader_emit_c_ast$print_section(l8, l9);
    vader_emit_c$emit_import_shims(l4, l8);
    t1 = vader_emit_c$imports_header_name(l2);
    vader_struct_vader_emit_c_ast$CInclude_t* _a11_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a11_obj, 975u);
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
    vader_array_t* _a12_arr = vader_array_new(21u, 0u, 0u, 335u);
    l12 = (void*) _a12_arr;
    l13 = ((vader_array_t*) l3)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l12, (int64_t) l13);
    l12 = (void*) _a13_arr;
    l13 = INT64_C(0);
    l14 = ((vader_array_t*) l3)->length;
    while ((l13 < l14)) {
        l15 = vader_emit_c$including(l2);
        vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l13)
        l16 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l13);
        vader_emit_c$emit_internal_forward_decls(l4, l16, l15);
        if (l13 == INT64_C(0)) {
            vader_emit_c$emit_fn_trampolines(l4, l15);
            vader_emit_c$emit_vtable_dispatchers(l4, l15);
        }
        vader_array_t* _a15_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
        l17 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l13);
        l18 = ((vader_array_t*) l17)->length;
        l19 = INT64_C(0);
        while ((l19 < l18)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l19)
            l20 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l19];
            vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l20)
            l21 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l20);
            l22 = vader_emit_c$function_definition(l4, l20, l21);
            vader_emit_c_ast$print_item(l15, vader_ref_box(l22));
            l19 = (l19 + INT64_C(1));
        }
        if (l13 == INT64_C(0)) {
            l5 = ((vader_struct_vader_emit_c$CEmitOptions_t*) l1)->f_entry_mangled;
            vader_emit_c$emit_main(l4, l15, l5);
        }
        l23 = vader_emit_c_ast$printed_text(l15);
        vader_array_push_scalar((vader_array_t*) l12, vader_box_string(335u, l23));
        l13 = (l13 + INT64_C(1));
    }
    vader_emit_c$push_library_units(l4, l10, l12);
    l5 = vader_emit_c_ast$printed_text(l6);
    l23 = vader_emit_c_ast$printed_text(l8);
    l24 = vader_emit_c_ast$printed_text(l9);
    vader_struct_vader_emit_c$CProgram_t* _a18_obj = (vader_struct_vader_emit_c$CProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$CProgram_t));
    vader_obj_header_init(_a18_obj, 933u);
    _a18_obj->f_header = l5;
    _a18_obj->f_imports = l23;
    _a18_obj->f_globals = l24;
    _a18_obj->f_units = l12;
    _a18_obj->f_unit_names = l10;
    t0 = (void*) _a18_obj;
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
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
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
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
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
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 728u)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(49));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l6, l9, 1717u);
        t0 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) l1)->f_type_id;
        l10 = ((int64_t) (int32_t) t0);
        l9 = std_core$write_int(l6, l9, l10);
        t1 = std_core$finish_buffer(l6, l9);
        std_abort$todo(t1);
        vader_unreachable("a no-return call returned");
    }
    l5 = vader_emit_c$pop(l0);
    t2 = l4.payload.obj;
    t3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) t2)->f_params)->length;
    l3 = ((int32_t) (int64_t) t3);
    l6 = vader_emit_c$pop_args_boxed(l0, l3);
    l7 = vader_emit_c$aux(l0, 2023u);
    l5 = vader_emit_c$object_pointer_of(l5);
    l5 = vader_emit_c_ast$cast(2939u, l5);
    vader_emit_c$declare(l0, 2939u, l7, l5);
    t1 = concat_2(l7, 393u);
    t4 = vader_emit_c_ast$verbatim(t1);
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t4.payload.obj;
    l8 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
    l9 = vader_host_std_core$byte_len(l7);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(53) + l9));
    l9 = INT64_C(0);
    l9 = std_core$write_string_at(l6, l9, 307u);
    l10 = ((int64_t) (int32_t) l3);
    l9 = std_core$write_int(l6, l9, l10);
    l9 = std_core$write_string_at(l6, l9, 1034u);
    l9 = std_core$write_string_at(l6, l9, l7);
    l9 = std_core$write_string_at(l6, l9, 392u);
    t1 = std_core$finish_buffer(l6, l9);
    l5 = vader_emit_c_ast$call(t1, l8);
    t2 = l4.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$BcFn_t*) t2)->f_return_type;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params)->length;
    l3 = ((int32_t) (int64_t) t0);
    t1 = vader_emit_c_ast$verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
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
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l8, 340u);
        l9 = ((uint8_t) t1.payload.i);
        l10 = vader_emit_c$coerced_as(l0, l7, l9);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8, l10.payload.obj);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l7 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) l1)->f_op);
    t0 = concat_2(2920u, l7);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l5 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(2921u, l5);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l7 = ((int32_t) (int64_t) l5);
            l8 = vader_emit_c$fn_symbol_name(l3, l7);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_signature;
            t2 = vader_emit_c$trampoline_signature(l0, l8, l9);
            vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a3_obj, 987u);
            _a3_obj->f_signature = t2;
            l10 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l4, l10);
            l11 = concat_2(2937u, l8);
            l12 = vader_emit_c$external(2938u, l11, vader_box_obj(0u, NULL), false);
            vader_array_push_ref((vader_array_t*) l4, l12.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
        t3 = t0;
        if (t3) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
            t4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_signature)->f_params)->length;
            if ((t4 > INT64_C(0))) {
                l7 = ((int32_t) (int64_t) l5);
                l8 = vader_emit_c$fn_symbol_name(l3, l7);
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t2 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_signature;
                t2 = vader_emit_c$lift_signature(l0, l8, l9);
                vader_struct_vader_emit_c_ast$CPrototype_t* _a7_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
                vader_obj_header_init(_a7_obj, 987u);
                _a7_obj->f_signature = t2;
                l10 = (void*) _a7_obj;
                vader_array_push_ref((vader_array_t*) l4, l10);
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(21u, 0u, 0u, 335u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a9_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a9_obj, 990u);
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_name;
    l4 = vader_emit_c$sanitise(t0);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature;
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params)->length;
    if (!(t1 == INT64_C(0))) {
        l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l6 = vader_emit_c_ast$verbatim(1902u);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(0), 340u);
        l7 = ((uint8_t) t2.payload.i);
        t2 = vader_emit_c$coerce_expr(l5, l6, (uint8_t) 16, l7);
        vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t2.payload.obj;
        l5 = (void*) _a2_arr;
        l8 = vader_emit_c$lift_unbox_tail(((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l8);
        vader_array_t* _a3_arr = vader_array_new(255u, 0u, 13u, 1918u);
        t3 = (void*) _a3_arr;
        vader_struct_vader_emit_c_ast$CBlock_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
        vader_obj_header_init(_a4_obj, 953u);
        _a4_obj->f_body = t3;
        l8 = (void*) _a4_obj;
        l9 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l8)->f_body;
        l5 = vader_emit_c$forward_boxed(l4, l5, l3);
        vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l5);
        l3 = vader_emit_c$lift_signature(l0, l4, l3);
        vader_array_t* _a5_arr = vader_array_new(255u, 0u, 13u, 1918u);
        l5 = (void*) _a5_arr;
        vader_struct_vader_emit_c_ast$CFunction_t* _a6_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
        vader_obj_header_init(_a6_obj, 970u);
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
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    uint8_t l4, l5;
    bool l6;
    void* l8 = NULL;
    bool t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l3, &l7, &t1, &t2 };
    void** gc_raw_roots[2] = { &l0, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$pop(l0);
    l4 = vader_emit_c$val_of(l3);
    if (l1 == INT32_C(3)) {
        l6 = true;
    } else {
        l6 = l1 == INT32_C(9);
    }
    if (l6) {
        l6 = l4 == INT32_C(2);
    } else {
        l6 = false;
    }
    if (l6) {
        l6 = std_string$starts_with(l2, 2780u);
    } else {
        l6 = false;
    }
    if (l6) {
        l5 = (uint8_t) 6;
    } else {
        l5 = l4;
    }
    t0 = vader_emit_c$is_ref_val(l4);
    if (t0) {
        t1 = vader_emit_c$expression_of(l3);
        l7 = vader_emit_c$unbox_expr(t1, l1);
        vader_emit_c$push_expr(l0, l1, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == l1) {
        l7 = vader_emit_c$expression_of(l3);
        vader_emit_c$push_expr(l0, l1, l7);
    } else {
        t1 = vader_emit_c$expression_of(l3);
        t2 = vader_emit_c$scalar_cast(t1, l5, l1);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a0_obj, 985u);
        _a0_obj->f_inner = t2;
        l8 = (void*) _a0_obj;
        vader_emit_c$push_expr(l0, l1, vader_ref_box(l8));
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
    l3 = std_core$write_string_at(l2, l3, 2925u);
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
    uint8_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l10, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    while ((l3 < l4)) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l5, l6, 2925u);
        l6 = std_core$write_int(l5, l6, l3);
        l7 = std_core$finish_buffer(l5, l6);
        l8 = vader_emit_c$external(2892u, l7, vader_box_obj(0u, NULL), true);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
        l3 = (l3 + INT64_C(1));
    }
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals)->length;
    while ((l3 < l4)) {
        l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module;
        l9 = ((int32_t) (int64_t) l3);
        t0 = vader_emit_c$global_slot_val(l5, l9);
        l7 = vader_emit_c$c_type_for_val_bare(t0);
        l10 = (void*) vader_buffer_new((size_t) INT64_C(33));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l10, l6, 2947u);
        l6 = std_core$write_int(l10, l6, l3);
        l11 = std_core$finish_buffer(l10, l6);
        l8 = vader_emit_c$external(l7, l11, vader_box_obj(0u, NULL), false);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
        l3 = (l3 + INT64_C(1));
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals)->length;
    if ((t1 > INT64_C(0))) {
        l8 = vader_emit_c$external(2943u, 2950u, vader_box_obj(0u, NULL), false);
        vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
    }
    t2 = (void*) &vader_data_51;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    l8 = vader_emit_c$external(2896u, 2895u, vader_ref_box(l5), true);
    vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
    t2 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_comment = t2;
    _a4_obj->f_items = l2;
    l2 = (void*) _a4_obj;
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
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    if (t0 == INT64_C(0)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals)->length;
        if (t0 == INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l3 = vader_core_bytecode$data_pool_type_ids(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module);
    t1 = vader_emit_c$has_str_data(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool);
    if (t1) {
        l4 = vader_emit_c$build_string_atom_map(l0);
    } else {
        vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
        l6 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
        l7 = (void*) _a3_arr;
        vader_struct_std_collections$MutableMap__string__i32_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
        vader_obj_header_init(_a4_obj, 540u);
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
    l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    while ((l8 < l9)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        l5 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l11 = INT64_C(0);
        l11 = std_core$write_string_at(l5, l11, 2925u);
        l11 = std_core$write_int(l5, l11, l8);
        l12 = std_core$finish_buffer(l5, l11);
        t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l13 = vader_emit_c$global_storage(t1);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        l14 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
        l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        l15 = l14;
        l16 = vader_emit_c$array_element_tag(l6, l15);
        vader_struct_vader_emit_c$PoolArray_t* _a7_obj = (vader_struct_vader_emit_c$PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$PoolArray_t));
        vader_obj_header_init(_a7_obj, 939u);
        _a7_obj->f_name = l12;
        _a7_obj->f_storage = l13;
        _a7_obj->f_type_id = l14;
        _a7_obj->f_element_tag = l16;
        l7 = (void*) _a7_obj;
        if (l10.tag == 737u) {
            l17 = l10.payload.obj;
            vader_emit_c$emit_str_data_entry(l2, l7, l17, l4);
        } else if (l10.tag == 733u) {
            l18 = l10.payload.obj;
            vader_emit_c$emit_prim_data_entry(l2, l7, l18);
        } else {
            if (!(l10.tag == 724u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l19 = l10.payload.obj;
            vader_emit_c$emit_agg_data_entry(l0, l2, l7, l19, l4);
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_emit_c$emit_global_slots(l0, l2);
    vader_emit_c$emit_global_roots(l0, l2);
    vader_array_t* _a8_arr = vader_array_new(21u, 3u, 0u, 335u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 2u] = vader_box_string(335u, 2513u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 1u] = vader_box_string(335u, 729u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 0u] = vader_box_string(335u, 624u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a9_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a9_obj, 990u);
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
    if (l2.tag == 741u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t0)->f_bits;
        t1 = vader_emit_c$data_slot(l5, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 742u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        t2 = vader_emit_c$atom_for(l4, l7);
        t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 743u) {
        l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        l9 = vader_emit_c$type_id_for_struct_symbol(l8, l9);
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l9];
        l7 = t1.payload.s;
        l7 = concat_2(2659u, l7);
        t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l9));
        t3 = vader_emit_c$object_header(t1);
        vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t3.payload.obj;
        l8 = (void*) _a1_arr;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        if (l10.tag == 738u) {
            l11 = INT64_C(0);
            t0 = l2.payload.obj;
            l12 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields)->length;
            while ((l11 < l12)) {
                t0 = l10.payload.obj;
                l13 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields)->length;
                if ((l11 < l13)) {
                    t0 = l10.payload.obj;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
                    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                    l9 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
                } else {
                    l9 = INT32_C(0);
                }
                t0 = l2.payload.obj;
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
                l14 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
                l15 = l3;
                l16 = vader_host_std_core$byte_len(l15);
                l17 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l16));
                l18 = INT64_C(0);
                l18 = std_core$write_string_at(l17, l18, l15);
                l18 = std_core$write_string_at(l17, l18, 1024u);
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
        vader_obj_header_init(_a5_obj, 963u);
        _a5_obj->f_name = l3;
        _a5_obj->f_length = vader_box_obj(0u, NULL);
        _a5_obj->f_value = l10;
        l8 = (void*) _a5_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a6_obj, 972u);
        _a6_obj->f_storage = l5;
        _a6_obj->f_constant = true;
        _a6_obj->f_type = l7;
        _a6_obj->f_declarator = l8;
        l8 = (void*) _a6_obj;
        vader_array_push_ref((vader_array_t*) l1, l8);
        l7 = concat_2(l7, 349u);
        t1 = vader_emit_c_ast$verbatim(l3);
        l10 = vader_emit_c_ast$address_of(t1);
        t1 = vader_emit_c_ast$cast(l7, l10);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 740u)) {
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
    l3 = std_core$write_string_at(l2, l3, 2780u);
    t1 = std_core$finish_buffer(l2, l3);
    t2 = vader_emit_c_ast$verbatim(t1);
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t2.payload.obj;
    l2 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(2926u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2927u, l2);
    vader_emit_c$evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_else(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_emit_c$assert_stack_empty(l0, 1863u);
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
    l3 = std_core$write_string_at(l2, l3, 2544u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 321u);
    l5 = std_core$finish_buffer(l2, l3);
    vader_emit_c$assert_stack_empty(l0, l5);
    l6 = vader_emit_c$scope_ending_at(((vader_struct_vader_emit_c$FnState_t*) l0)->f_scopes, l1);
    if (l6.tag == 0u) {
        l7 = (void*) vader_buffer_new((size_t) INT64_C(50));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l7, l3, 1875u);
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
            l3 = std_core$write_string_at(l7, l3, 1881u);
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
    l1 = vader_emit_c_ast$around(314u, l1, 239u);
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
    l1 = vader_emit_c_ast$around(315u, l1, 240u);
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
    l5 = vader_emit_c_ast$cast(3017u, l5);
    vader_emit_c$assign(l0, vader_ref_box(l2), l5);
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l3 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(2930u, l3);
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
    t0 = concat_2(2937u, l4);
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
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    l5 = vader_emit_c$sanitise(t0);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature;
    l6 = vader_emit_c_ast$verbatim(1902u);
    t1 = vader_emit_c_ast$cast(3016u, l6);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 967u);
    _a1_obj->f_expression = t1;
    t2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(255u, 1u, 13u, 1918u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t2;
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a3_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a3_obj, 953u);
    _a3_obj->f_body = t2;
    l7 = (void*) _a3_obj;
    l8 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l7)->f_body;
    l9 = vader_emit_c$tramp_unbox_args(((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params);
    l9 = vader_emit_c$forward_boxed(l5, l9, l4);
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l9);
    l4 = vader_emit_c$trampoline_signature(l0, l5, l4);
    vader_array_t* _a4_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l8 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CFunction_t* _a5_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a5_obj, 970u);
    _a5_obj->f_signature = l4;
    _a5_obj->f_prologue = l8;
    _a5_obj->f_body = l7;
    l4 = (void*) _a5_obj;
    vader_array_push_ref((vader_array_t*) l1, l4);
    t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l3));
    l6 = vader_emit_c$object_header(t1);
    t0 = concat_2(2940u, l5);
    t1 = vader_emit_c_ast$verbatim(t0);
    l10 = vader_emit_c_ast$address_of(t1);
    l10 = vader_emit_c_ast$cast(3017u, l10);
    t2 = (void*) &vader_data_53;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l4 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 2u] = l4;
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 1u] = l10.payload.obj;
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l6.payload.obj;
    t2 = (void*) _a7_arr;
    l6 = vader_emit_c_ast$initializer_list(t2);
    t3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l11 = vader_emit_c$global_storage(t3);
    t0 = concat_2(2937u, l5);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a8_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a8_obj, 963u);
    _a8_obj->f_name = t0;
    _a8_obj->f_length = vader_box_obj(0u, NULL);
    _a8_obj->f_value = l6;
    l4 = (void*) _a8_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a9_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a9_obj, 972u);
    _a9_obj->f_storage = l11;
    _a9_obj->f_constant = false;
    _a9_obj->f_type = 2938u;
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = vader_emit_c$max_fn_arity(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
    l5 = (l3 <= l4);
    while (l5) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(42));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 2934u);
        l7 = std_core$write_int(l6, l7, l3);
        l7 = std_core$write_string_at(l6, l7, 1033u);
        l8 = std_core$finish_buffer(l6, l7);
        l9 = vader_emit_c$erased_parameters(l3);
        vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t* _a1_obj = (vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t));
        vader_obj_header_init(_a1_obj, 971u);
        _a1_obj->f_result = 2905u;
        _a1_obj->f_name = l8;
        _a1_obj->f_parameters = l9;
        l10 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l2, l10);
        l5 = (l3 < l4);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 990u);
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
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l6 = ((int32_t) (int64_t) l5);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_fn_ref_type);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
            vader_emit_c$emit_fn_ref_tramp(l0, l4, l6, l7);
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t0 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
        t2 = t0;
        if (t2) {
            l6 = ((int32_t) (int64_t) l5);
            vader_emit_c$emit_closure_lift(l0, l4, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    t3 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a5_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a5_obj, 990u);
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
    int64_t l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_box_t l15 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l15, &t2 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &t3 };
    vader_string_t* gc_atom_roots[5] = { &l11, &l12, &l13, &l14, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a2_arr;
    l7 = l1;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l10 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_is_extern;
        if (t0) {
            l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_extern_name;
            t0 = std_core$$array$Contains$contains__string(l5, l11);
            if (!(t0)) {
                l12 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_extern_name;
                vader_array_push_scalar((vader_array_t*) l5, vader_box_string(335u, l12));
                t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_c_header;
                if (t1 != 0u) {
                    l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_c_header;
                    t0 = std_core$$array$Contains$contains__string(l6, l13);
                    if (!(t0)) {
                        l14 = ((vader_struct_vader_core_bytecode$BcImport_t*) l10)->f_c_header;
                        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(335u, l14));
                    }
                } else {
                    l15 = vader_emit_c$extern_decl(l10, l2);
                    vader_array_push_ref((vader_array_t*) l4, l15.payload.obj);
                }
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l5 = (void*) _a4_arr;
    l8 = ((vader_array_t*) l6)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l8);
    l5 = (void*) _a5_arr;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t2 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l9];
        t1 = t2.payload.s;
        l7 = vader_emit_c$include_of(t1);
        vader_array_push_ref((vader_array_t*) l5, l7);
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a7_arr->buf)[_a7_arr->offset + 0u] = vader_box_string(335u, 660u);
    t3 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 990u);
    _a8_obj->f_comment = t3;
    _a8_obj->f_items = l5;
    l5 = (void*) _a8_obj;
    vader_emit_c_ast$print_section(l0, l5);
    vader_array_t* _a9_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(335u, 926u);
    t3 = (void*) _a9_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a10_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a10_obj, 990u);
    _a10_obj->f_comment = t3;
    _a10_obj->f_items = l4;
    l4 = (void*) _a10_obj;
    vader_emit_c_ast$print_section(l0, l4);
    vader_array_t* _a11_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a11_arr->buf)[_a11_arr->offset + 0u] = vader_box_string(335u, 1352u);
    l4 = (void*) _a11_arr;
    l5 = vader_emit_c$c_type_asserts(l1);
    vader_struct_vader_emit_c_ast$CSection_t* _a12_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a12_obj, 990u);
    _a12_obj->f_comment = l4;
    _a12_obj->f_items = l5;
    l4 = (void*) _a12_obj;
    vader_emit_c_ast$print_section(l0, l4);
    vader_array_t* _a13_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a13_arr->buf)[_a13_arr->offset + 0u] = vader_box_string(335u, 1344u);
    l4 = (void*) _a13_arr;
    l5 = vader_emit_c$c_struct_layout_asserts(l2, l3);
    vader_struct_vader_emit_c_ast$CSection_t* _a14_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a14_obj, 990u);
    _a14_obj->f_comment = l4;
    _a14_obj->f_items = l5;
    l4 = (void*) _a14_obj;
    vader_emit_c_ast$print_section(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions)->length;
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
            vader_obj_header_init(_a1_obj, 987u);
            _a1_obj->f_signature = t2;
            l8 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l2, l8);
        }
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 990u);
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
    l5 = std_core$write_string_at(l2, l5, 2947u);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_emit_c$global_slot_addresses(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, (uint8_t) 17);
    l3 = vader_emit_c$global_slot_addresses(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, (uint8_t) 16);
    l4 = vader_emit_c$global_slot_addresses(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, (uint8_t) 12);
    t1 = (void*) &vader_data_53;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t0 = ((vader_array_t*) l2)->length;
    l6 = vader_emit_c_ast$unsigned(t0);
    t0 = ((vader_array_t*) l3)->length;
    l7 = vader_emit_c_ast$unsigned(t0);
    l8 = vader_emit_c$root_list(l1, 2906u, 2949u, l2);
    l9 = vader_emit_c$root_list(l1, 3018u, 2951u, l3);
    t1 = (void*) &vader_data_52;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t1 = (void*) &vader_data_53;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a3_arr = vader_array_new(254u, 7u, 13u, 1914u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 6u] = l3;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 5u] = l2;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 4u] = l9.payload.obj;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 3u] = l8.payload.obj;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 2u] = l7.payload.obj;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l5;
    l2 = (void*) _a3_arr;
    t0 = ((vader_array_t*) l4)->length;
    if ((t0 > INT64_C(0))) {
        l6 = vader_emit_c$root_list(l1, 2976u, 2948u, l4);
        t0 = ((vader_array_t*) l4)->length;
        t2 = vader_emit_c_ast$unsigned(t0);
        vader_array_t* _a4_arr = vader_array_new(254u, 2u, 13u, 1914u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l6.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = t2.payload.obj;
        l3 = (void*) _a4_arr;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
    }
    t3 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l10 = vader_emit_c$global_storage(t3);
    l6 = vader_emit_c_ast$initializer_list(l2);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a5_obj, 963u);
    _a5_obj->f_name = 2950u;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l6;
    l2 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a6_obj, 972u);
    _a6_obj->f_storage = l10;
    _a6_obj->f_constant = false;
    _a6_obj->f_type = 2943u;
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
    l4 = std_core$write_string_at(l3, l4, 2947u);
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
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals)->length;
    while ((l2 < l3)) {
        l4 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module;
        l5 = ((int32_t) (int64_t) l2);
        l6 = vader_emit_c$global_slot_val(l4, l5);
        t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
        l7 = vader_emit_c$global_storage(t0);
        l8 = vader_emit_c$c_type_for_val_bare(l6);
        l9 = (void*) vader_buffer_new((size_t) INT64_C(33));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 2947u);
        l10 = std_core$write_int(l9, l10, l2);
        l11 = std_core$finish_buffer(l9, l10);
        l12 = vader_emit_c$zero_of(l6);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a0_obj, 963u);
        _a0_obj->f_name = l11;
        _a0_obj->f_length = vader_box_obj(0u, NULL);
        _a0_obj->f_value = l12;
        l13 = (void*) _a0_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a1_obj, 972u);
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
    vader_emit_c$assert_stack_empty(l0, 2137u);
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
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l4 = vader_emit_c$mirror_crossings(l2, l3);
    vader_emit_c$emit_foreign_declarations(l1, l2, l3, l4);
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l3 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l5);
    l3 = (void*) _a1_arr;
    l4 = l2;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = vader_emit_c$import_shim(l0, l7);
        vader_array_push_ref((vader_array_t*) l3, l8);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_comment = t0;
    _a4_obj->f_items = l3;
    l3 = (void*) _a4_obj;
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
    l2 = vader_emit_c$imports_of_library(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, 0u);
    vader_emit_c$emit_import_group(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = vader_core_bytecode$library_name(l6);
        if (t1 != 0u) {
            l7 = vader_emit_c$shim_signature(l0, l6);
            l8 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_inline;
            l9 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_result;
            l10 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_name;
            l11 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l7)->f_parameters;
            vader_struct_vader_emit_c_ast$CSignature_t* _a2_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
            vader_obj_header_init(_a2_obj, 992u);
            _a2_obj->f_storage = (uint8_t) 2;
            _a2_obj->f_inline = l8;
            _a2_obj->f_result = l9;
            _a2_obj->f_name = l10;
            _a2_obj->f_parameters = l11;
            t2 = (void*) _a2_obj;
            vader_struct_vader_emit_c_ast$CPrototype_t* _a3_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a3_obj, 987u);
            _a3_obj->f_signature = t2;
            l12 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l2, l12);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a4_arr->buf)[_a4_arr->offset + 0u] = vader_box_string(335u, 801u);
    t2 = (void*) _a4_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a5_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a5_obj, 990u);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l3 = (void*) _a0_arr;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        t0 = vader_emit_c$module_function_storage(l0, l7);
        if (t0 == INT32_C(0)) {
            t1 = vader_emit_c$signature_for(l0, l7);
            vader_struct_vader_emit_c_ast$CPrototype_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
            vader_obj_header_init(_a2_obj, 987u);
            _a2_obj->f_signature = t1;
            l8 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l8);
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_comment = t1;
    _a4_obj->f_items = l3;
    l3 = (void*) _a4_obj;
    vader_emit_c_ast$print_section(l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c$emit_library_unit(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 618u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a2_obj, 986u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l2 = (void*) _a2_obj;
    l3 = concat_3(653u, l1, 1315u);
    vader_emit_c$emit_preamble(l2, l3);
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l5 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names;
    vader_emit_c$emit_mirrored_struct_typedefs(l4, l5, l2);
    l4 = vader_emit_c$imports_of_library(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, l1);
    vader_emit_c$emit_import_group(l0, l2, l4);
    t1 = vader_emit_c_ast$printed_text(l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 1u, 340u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l9 = (void*) _a1_arr;
    l10 = INT64_C(0);
    l11 = ((vader_array_t*) l6)->length;
    while ((l10 < l11)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        if (((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val == INT32_C(14)) {
            l10 = (l10 + INT64_C(1));
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
        l12 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val;
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
        l13 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l13, l14, 2267u);
        l15 = vader_chk_add(i64, l7, l10);
        l14 = std_core$write_int(l13, l14, l15);
        l16 = std_core$finish_buffer(l13, l14);
        vader_array_push_scalar((vader_array_t*) l9, vader_box_string(335u, l16));
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
    vader_obj_header_init(_a0_obj, 979u);
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
    vader_obj_header_init(_a0_obj, 979u);
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
    vader_obj_header_init(_a0_obj, 984u);
    _a0_obj->f_type = 2176u;
    _a0_obj->f_name = 1557u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CParameter_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
    vader_obj_header_init(_a1_obj, 984u);
    _a1_obj->f_type = 1754u;
    _a1_obj->f_name = 1560u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(101u, 2u, 13u, 984u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3;
    l3 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 992u);
    _a3_obj->f_storage = (uint8_t) 1;
    _a3_obj->f_inline = false;
    _a3_obj->f_result = 2176u;
    _a3_obj->f_name = 2307u;
    _a3_obj->f_parameters = l3;
    l3 = (void*) _a3_obj;
    t0 = vader_emit_c$main_body(l0, l2);
    vader_struct_vader_emit_c_ast$CBlock_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a4_obj, 953u);
    _a4_obj->f_body = t0;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l5 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CFunction_t* _a6_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a6_obj, 970u);
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
    l3 = vader_emit_c$aux(l0, 1764u);
    l4 = vader_emit_c$gc_allocation(2938u);
    vader_emit_c$declare(l0, 2939u, l3, l4);
    l5 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l1)->f_env_type_id;
    vader_emit_c$init_object_header(l0, l3, l5);
    t0 = concat_2(l3, 391u);
    l4 = vader_emit_c_ast$verbatim(t0);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l5 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l1)->f_function_index;
    l7 = vader_emit_c$fn_symbol_name(l6, l5);
    t0 = concat_2(2935u, l7);
    t1 = vader_emit_c_ast$verbatim(t0);
    l8 = vader_emit_c_ast$address_of(t1);
    l8 = vader_emit_c_ast$cast(3017u, l8);
    vader_emit_c$assign(l0, l4, l8);
    t0 = concat_2(l3, 393u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 5u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2912u, l6);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l0)->length;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (l7.tag == 738u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_c_name;
            if (t1 != 0u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
                t1 = t2.payload.s;
                vader_struct_vader_emit_c_ast$CStructForward_t* _a4_obj = (vader_struct_vader_emit_c_ast$CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructForward_t));
                vader_obj_header_init(_a4_obj, 996u);
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
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 990u);
    _a6_obj->f_comment = t0;
    _a6_obj->f_items = l3;
    l3 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l2, l3);
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 990u);
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
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_results;
    vader_array_t* _a0_arr = vader_array_new(102u, 0u, 13u, 998u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) l4)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a1_arr;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l4)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 340u);
        l8 = ((uint8_t) t0.payload.i);
        l9 = vader_emit_c$new_temporary(l0, l8);
        vader_array_push_ref((vader_array_t*) l5, l9);
        l10 = vader_emit_c_ast$address_of(vader_ref_box(l9));
        vader_array_push_ref((vader_array_t*) l2, l10.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    l10 = vader_emit_c_ast$call(l1, l2);
    vader_emit_c$evaluate(l0, l10);
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l4)->length;
    while ((l6 < l7)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l9 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l6, 340u);
        l8 = ((uint8_t) t0.payload.i);
        vader_emit_c$push_temporary(l0, l9, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_multi_return(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    int64_t l2, l5, l6;
    vader_string_t l3 = 0;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    uint8_t l9;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l7, &l8, &l10, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_signature)->f_results;
    l2 = ((vader_array_t*) l1)->length;
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
    if ((t0 < l2)) {
        l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
        l3 = concat_2(2837u, l3);
        vader_emit_c$unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 951u);
    l4 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l5 = l2;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        t0 = vader_chk_sub(i64, l2, INT64_C(1));
        l6 = vader_chk_sub(i64, t0, l5);
        l7 = vader_emit_c$pop(l0);
        l3 = vader_emit_c$out_param_name(l6);
        t1 = concat_2(349u, l3);
        l8 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 340u);
        l9 = ((uint8_t) t2.payload.i);
        l10 = vader_emit_c$coerced_as(l0, l7, l9);
        vader_struct_vader_emit_c_ast$CAssign_t* _a3_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a3_obj, 951u);
        _a3_obj->f_target = l8;
        _a3_obj->f_value = l10;
        _a3_obj->f_operator = vader_box_obj(0u, NULL);
        l11 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l4, l11);
        l5 = (l5 + INT64_C(1));
    }
    vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a4_obj, 988u);
    _a4_obj->f_stores = l4;
    _a4_obj->f_value = vader_box_obj(0u, NULL);
    _a4_obj->f_snapshot_type = 0u;
    _a4_obj->f_pops_frame = false;
    l1 = (void*) _a4_obj;
    vader_emit_c$return_statement(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    uint8_t l5, l9;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l18 = 0;
    int32_t l8, l10;
    int64_t l12, l13, l15, l17;
    vader_box_t l14 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null();
    uint64_t l20;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l14, &l19, &l21, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l6, &l11, &l16, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l7, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_emit_c$element_storage_kind(((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_elements);
    l6 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l7 = ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_element_type_name;
    l8 = vader_emit_c$type_index_for_name(l6, l7);
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_split;
    l9 = vader_emit_c$global_storage(t0);
    l10 = vader_emit_c$array_type_index_for_element(((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types, l8);
    vader_struct_vader_emit_c$PoolArray_t* _a0_obj = (vader_struct_vader_emit_c$PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$PoolArray_t));
    vader_obj_header_init(_a0_obj, 939u);
    _a0_obj->f_name = l3;
    _a0_obj->f_storage = l9;
    _a0_obj->f_type_id = l10;
    _a0_obj->f_element_tag = l8;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l11 = (void*) _a1_arr;
    l12 = INT64_C(0);
    l13 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_elements)->length;
    while ((l12 < l13)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcValArray_t*) l2)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
        l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
        if (l5 == INT32_C(0)) {
            l7 = l3;
            l15 = vader_host_std_core$byte_len(l7);
            l16 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l15));
            l17 = INT64_C(0);
            l17 = std_core$write_string_at(l16, l17, l7);
            l17 = std_core$write_string_at(l16, l17, 1037u);
            l17 = std_core$write_int(l16, l17, l12);
            l18 = std_core$finish_buffer(l16, l17);
            l19 = vader_emit_c$box_slot(l0, l1, l14, l18, l8, l4);
            vader_array_push_ref((vader_array_t*) l11, l19.payload.obj);
        } else if (l14.tag == 741u) {
            t1 = l14.payload.obj;
            l20 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_bits;
            l21 = vader_emit_c$data_slot(l5, l20);
            vader_array_push_ref((vader_array_t*) l11, l21.payload.obj);
        }
        l12 = (l12 + INT64_C(1));
    }
    l7 = vader_emit_c$c_type_for_array_kind(l5);
    vader_emit_c$push_pool_array(l1, l6, l7, l5, l11);
    t2 = vader_emit_c_ast$verbatim(l3);
    l14 = vader_emit_c_ast$address_of(t2);
    t2 = vader_emit_c_ast$cast(2893u, l14);
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
    if (l2.tag == 797u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 817u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 776u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 748u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 763u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 848u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 864u) {
        l3 = l2.payload.obj;
        vader_emit_c$push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 842u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_local_get(l0, l3);
    } else if (l2.tag == 843u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        vader_emit_c$emit_local_set(l0, l4, false);
    } else if (l2.tag == 844u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        vader_emit_c$emit_local_set(l0, l4, true);
    } else if (l2.tag == 841u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_local_field(l0, l3);
    } else if (l2.tag == 853u) {
        vader_emit_c$emit_return(l0);
    } else if (l2.tag == 854u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_c$emit_return_lit(l0, l5);
    } else if (l2.tag == 771u) {
        vader_emit_c$drop_top(l0);
    } else if (l2.tag == 760u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call(l0, l3);
    } else if (l2.tag == 761u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call_import(l0, l3);
    } else if (l2.tag == 762u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_call_indirect(l0, l3);
    } else if (l2.tag == 887u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_virtual_call(l0, l3);
    } else if (l2.tag == 789u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_fn_ref(l0, l3);
    } else if (l2.tag == 788u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_fn_addr(l0, l3);
    } else if (l2.tag == 846u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_make_closure(l0, l3);
    } else if (l2.tag == 832u) {
        vader_emit_c$emit_if_open(l0);
    } else if (l2.tag == 772u) {
        vader_emit_c$emit_else(l0);
    } else if (l2.tag == 773u) {
        vader_emit_c$emit_end(l0, l1);
    } else if (l2.tag == 746u) {
        vader_emit_c$emit_open_scope(l0, l1, (uint8_t) 0);
    } else if (l2.tag == 845u) {
        vader_emit_c$emit_open_scope(l0, l1, (uint8_t) 1);
    } else if (l2.tag == 753u) {
        vader_emit_c$emit_branch(l0, l1, false);
    } else if (l2.tag == 754u) {
        vader_emit_c$emit_branch(l0, l1, true);
    } else if (l2.tag == 751u) {
        vader_emit_c$push_unop(l0, 244u, (uint8_t) 10);
    } else if (l2.tag == 868u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_new(l0, l3);
    } else if (l2.tag == 867u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_get(l0, l3);
    } else if (l2.tag == 869u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_struct_set(l0, l3);
    } else if (l2.tag == 884u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_union_field_get(l0, l3);
    } else if (l2.tag == 885u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_union_field_set(l0, l3);
    } else if (l2.tag == 717u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_new(l0, l3);
    } else if (l2.tag == 716u) {
        vader_emit_c$emit_array_len(l0);
    } else if (l2.tag == 718u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_push(l0, l3);
    } else if (l2.tag == 715u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_get(l0, l3);
    } else if (l2.tag == 722u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_set(l0, l3);
    } else if (l2.tag == 723u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_array_slice(l0, l3);
    } else if (l2.tag == 721u) {
        vader_emit_c$emit_array_repeat(l0);
    } else if (l2.tag == 719u) {
        vader_emit_c$emit_array_push_all(l0);
    } else if (l2.tag == 714u) {
        vader_emit_c$emit_array_copy(l0);
    } else if (l2.tag == 720u) {
        vader_emit_c$emit_array_remove_last(l0);
    } else if (l2.tag == 713u) {
        vader_emit_c$emit_array_clear(l0);
    } else if (l2.tag == 767u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_data_const_op(l0, l3);
    } else if (l2.tag == 790u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_global_get(l0, l3);
    } else if (l2.tag == 791u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_global_set(l0, l3);
    } else if (l2.tag == 871u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_type_const(l0, l3);
    } else if (l2.tag == 870u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_type_check(l0, l3);
    } else if (l2.tag == 849u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_ref_cast(l0, l3);
    } else if (l2.tag == 852u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_retag_op(l0, l3);
    } else if (l2.tag == 886u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
        vader_emit_c$unreachable(l0, l6);
    } else if (l2.tag == 766u) {
        t0 = l2.payload.obj;
        l7 = vader_emit_c$convert_target_val(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        vader_emit_c$emit_convert(l0, l7, l6);
    } else if (l2.tag == 855u) {
        vader_emit_c$emit_size_of_type(l0);
    } else if (l2.tag == 764u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_checked_arith(l0, l3);
    } else if (l2.tag == 765u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_checked_neg(l0, l3);
    } else if (l2.tag == 792u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 2);
    } else if (l2.tag == 811u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 2);
    } else if (l2.tag == 805u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 2);
    } else if (l2.tag == 798u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 2);
    } else if (l2.tag == 804u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 2);
    } else if (l2.tag == 807u) {
        vader_emit_c$push_unop(l0, 383u, (uint8_t) 2);
    } else if (l2.tag == 794u) {
        vader_emit_c$push_unop(l0, 3075u, (uint8_t) 2);
    } else if (l2.tag == 793u) {
        vader_emit_c$push_binop(l0, (uint8_t) 13, (uint8_t) 2);
    } else if (l2.tag == 795u) {
        vader_emit_c$push_binop(l0, (uint8_t) 15, (uint8_t) 2);
    } else if (l2.tag == 796u) {
        vader_emit_c$push_binop(l0, (uint8_t) 14, (uint8_t) 2);
    } else if (l2.tag == 808u) {
        vader_emit_c$push_shift(l0, (uint8_t) 5, (uint8_t) 2);
    } else if (l2.tag == 809u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 2);
    } else if (l2.tag == 810u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 6);
    } else if (l2.tag == 799u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 2);
    } else if (l2.tag == 806u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 2);
    } else if (l2.tag == 803u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 2);
    } else if (l2.tag == 802u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 2);
    } else if (l2.tag == 801u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 2);
    } else if (l2.tag == 800u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 2);
    } else if (l2.tag == 812u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 3);
    } else if (l2.tag == 831u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 3);
    } else if (l2.tag == 825u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 3);
    } else if (l2.tag == 818u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 3);
    } else if (l2.tag == 824u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 3);
    } else if (l2.tag == 827u) {
        vader_emit_c$push_i64_neg(l0);
    } else if (l2.tag == 813u) {
        vader_emit_c$push_binop(l0, (uint8_t) 13, (uint8_t) 3);
    } else if (l2.tag == 815u) {
        vader_emit_c$push_binop(l0, (uint8_t) 15, (uint8_t) 3);
    } else if (l2.tag == 816u) {
        vader_emit_c$push_binop(l0, (uint8_t) 14, (uint8_t) 3);
    } else if (l2.tag == 814u) {
        vader_emit_c$push_unop(l0, 3075u, (uint8_t) 3);
    } else if (l2.tag == 828u) {
        vader_emit_c$push_shift(l0, (uint8_t) 5, (uint8_t) 3);
    } else if (l2.tag == 829u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 3);
    } else if (l2.tag == 830u) {
        vader_emit_c$push_shift(l0, (uint8_t) 6, (uint8_t) 7);
    } else if (l2.tag == 819u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 3);
    } else if (l2.tag == 826u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 3);
    } else if (l2.tag == 823u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 3);
    } else if (l2.tag == 822u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 3);
    } else if (l2.tag == 821u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 3);
    } else if (l2.tag == 820u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 3);
    } else if (l2.tag == 872u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 6);
    } else if (l2.tag == 877u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 6);
    } else if (l2.tag == 876u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 6);
    } else if (l2.tag == 875u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 6);
    } else if (l2.tag == 874u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 6);
    } else if (l2.tag == 873u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 6);
    } else if (l2.tag == 878u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 7);
    } else if (l2.tag == 883u) {
        vader_emit_c$push_eager(l0, (uint8_t) 2, (uint8_t) 7);
    } else if (l2.tag == 882u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 7);
    } else if (l2.tag == 881u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 7);
    } else if (l2.tag == 880u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 7);
    } else if (l2.tag == 879u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 7);
    } else if (l2.tag == 775u) {
        vader_emit_c$push_binop(l0, (uint8_t) 3, (uint8_t) 9);
    } else if (l2.tag == 786u) {
        vader_emit_c$push_binop(l0, (uint8_t) 4, (uint8_t) 9);
    } else if (l2.tag == 783u) {
        vader_emit_c$push_binop(l0, (uint8_t) 0, (uint8_t) 9);
    } else if (l2.tag == 777u) {
        vader_emit_c$push_eager(l0, (uint8_t) 1, (uint8_t) 9);
    } else if (l2.tag == 785u) {
        vader_emit_c$push_unop(l0, 383u, (uint8_t) 9);
    } else if (l2.tag == 778u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 9);
    } else if (l2.tag == 784u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 9);
    } else if (l2.tag == 782u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 7, (uint8_t) 9);
    } else if (l2.tag == 781u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 8, (uint8_t) 9);
    } else if (l2.tag == 780u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 9, (uint8_t) 9);
    } else if (l2.tag == 779u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 10, (uint8_t) 9);
    } else if (l2.tag == 749u) {
        vader_emit_c$push_binop(l0, (uint8_t) 11, (uint8_t) 10);
    } else if (l2.tag == 750u) {
        vader_emit_c$push_binop(l0, (uint8_t) 12, (uint8_t) 10);
    } else if (l2.tag == 747u) {
        vader_emit_c$push_binop(l0, (uint8_t) 16, (uint8_t) 10);
    } else if (l2.tag == 752u) {
        vader_emit_c$push_binop(l0, (uint8_t) 17, (uint8_t) 10);
    } else if (l2.tag == 865u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 866u) {
        vader_emit_c$push_cmp(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 863u) {
        vader_emit_c$emit_string_compare(l0);
    } else if (l2.tag == 850u) {
        vader_emit_c$push_binop_any(l0, (uint8_t) 11, (uint8_t) 10);
    } else if (l2.tag == 851u) {
        vader_emit_c$push_binop_any(l0, (uint8_t) 12, (uint8_t) 10);
    } else if (l2.tag == 770u) {
        vader_emit_c$emit_defer_push(l0);
    } else if (l2.tag == 769u) {
        l3 = l2.payload.obj;
        vader_emit_c$emit_defer_pop_exec(l0, l3);
    } else if (l2.tag == 755u) {
        vader_emit_c$emit_buffer_new(l0);
    } else if (l2.tag == 840u) {
        vader_emit_c$emit_buffer_load(l0, 2911u, (uint8_t) 2);
    } else if (l2.tag == 835u) {
        vader_emit_c$emit_buffer_load(l0, 2909u, (uint8_t) 2);
    } else if (l2.tag == 836u) {
        vader_emit_c$emit_buffer_load(l0, 2910u, (uint8_t) 3);
    } else if (l2.tag == 834u) {
        vader_emit_c$emit_buffer_load(l0, 2908u, (uint8_t) 9);
    } else if (l2.tag == 862u) {
        vader_emit_c$emit_buffer_store(l0, 2917u, 2810u);
    } else if (l2.tag == 857u) {
        vader_emit_c$emit_buffer_store(l0, 2915u, 2178u);
    } else if (l2.tag == 858u) {
        vader_emit_c$emit_buffer_store(l0, 2916u, 2179u);
    } else if (l2.tag == 856u) {
        vader_emit_c$emit_buffer_store(l0, 2914u, 1850u);
    } else if (l2.tag == 838u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2178u, (uint8_t) 2, l8);
    } else if (l2.tag == 839u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 2179u, (uint8_t) 3, l8);
    } else if (l2.tag == 837u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_load_prim(l0, 1850u, (uint8_t) 9, l8);
    } else if (l2.tag == 860u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2178u, (uint8_t) 2, l8);
    } else if (l2.tag == 861u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 2179u, (uint8_t) 3, l8);
    } else if (l2.tag == 859u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
        vader_emit_c$emit_slot_store_prim(l0, 1850u, (uint8_t) 9, l8);
    } else if (l2.tag == 847u) {
        vader_emit_c$emit_memory_copy(l0);
    } else if (l2.tag == 756u) {
        vader_emit_c$emit_buffer_to_string(l0);
    } else if (l2.tag == 757u) {
        vader_emit_c$emit_buffer_write_string(l0);
    } else if (l2.tag == 787u) {
        vader_emit_c$emit_f64_to_bits(l0);
    } else if (l2.tag == 745u) {
        vader_emit_c$emit_bits_to_f64(l0);
    } else if (l2.tag == 774u) {
        vader_emit_c$emit_f32_to_bits(l0);
    } else {
        if (!(l2.tag == 744u)) {
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
    l4 = std_core$write_string_at(l3, l4, 2545u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 321u);
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
            vader_obj_header_init(_a0_obj, 940u);
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
        l4 = std_core$write_string_at(l3, l4, 2296u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, l1);
    l2 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CInclude_t* _a1_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a1_obj, 975u);
    _a1_obj->f_path = 2855u;
    _a1_obj->f_system = false;
    l3 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a2_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a2_obj, 975u);
    _a2_obj->f_path = 2630u;
    _a2_obj->f_system = true;
    l4 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a3_obj, 975u);
    _a3_obj->f_path = 2631u;
    _a3_obj->f_system = true;
    l5 = (void*) _a3_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a4_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a4_obj, 975u);
    _a4_obj->f_path = 2652u;
    _a4_obj->f_system = true;
    l6 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(256u, 4u, 13u, 1922u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 3u] = l6;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l5;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l4;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l3;
    l3 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 990u);
    _a6_obj->f_comment = l2;
    _a6_obj->f_items = l3;
    l2 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$emit_prim_data_entry(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l4, l6;
    uint64_t l7;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    uint8_t l10;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_items)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcPrimData_t*) l2)->f_items;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
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
    if (!(l2.tag == 944u)) {
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
        vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 951u);
        t1 = (void*) _a0_arr;
        vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a1_obj, 988u);
        _a1_obj->f_stores = t1;
        _a1_obj->f_value = vader_box_obj(0u, NULL);
        _a1_obj->f_snapshot_type = 0u;
        _a1_obj->f_pops_frame = false;
        l2 = (void*) _a1_obj;
        vader_emit_c$return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
    if (!(t0 == INT64_C(0))) {
        l4 = vader_emit_c$pop(l0);
        vader_array_t* _a2_arr = vader_array_new(95u, 0u, 13u, 951u);
        l2 = (void*) _a2_arr;
        l4 = vader_emit_c$coerced_as(l0, l4, l1);
        l3 = vader_emit_c$c_type_for_val_bare(l1);
        vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a3_obj, 988u);
        _a3_obj->f_stores = l2;
        _a3_obj->f_value = l4;
        _a3_obj->f_snapshot_type = l3;
        _a3_obj->f_pops_frame = false;
        l2 = (void*) _a3_obj;
        vader_emit_c$return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_name;
    l3 = concat_2(2837u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 951u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a1_obj, 988u);
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
    l1 = vader_emit_c$payload(t1, 2418u);
    l1 = vader_emit_c_ast$around(316u, l1, 974u);
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
            vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l8.payload.obj;
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l6.payload.obj;
            l7 = (void*) _a0_arr;
            vader_emit_c$statement_macro(l0, 928u, l7);
        }
        { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_emit_c_ast$verbatim(l5);
    l6 = vader_emit_c$expression_of(l2);
    vader_array_t* _a1_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
    l7 = (void*) _a1_arr;
    vader_emit_c$statement_macro(l0, 927u, l7);
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 1u, 340u);
    l7 = (void*) _a0_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) l1)->length;
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l8, 340u);
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
                l14 = ((vader_array_t*) l1)->length;
                while ((l13 < l14)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l13, 340u);
                    if (((int32_t) t0.payload.i) == l10) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
                        t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l13];
                        l15 = t0.payload.s;
                        l16 = vader_emit_c_ast$verbatim(450u);
                        l17 = vader_emit_c_ast$declaration(2975u, l15, l16);
                        vader_array_push_ref((vader_array_t*) l0, l17.payload.obj);
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
                        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l13];
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
            l20 = ((vader_array_t*) l1)->length;
            while ((l19 < l20)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l19, 340u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l19)
                        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l19];
                        l21 = t0.payload.s;
                        l22 = vader_emit_c_ast$verbatim(720u);
                        l23 = vader_emit_c_ast$declaration(3017u, l21, l22);
                        vader_array_push_ref((vader_array_t*) l0, l23.payload.obj);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l19)
                        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l19];
                        t2 = t0.payload.s;
                        t0 = vader_emit_c_ast$verbatim(t2);
                        l24 = vader_emit_c_ast$address_of(t0);
                        vader_array_push_ref((vader_array_t*) l4, l24.payload.obj);
                    } else {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l19)
                        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l19];
                        l25 = t0.payload.s;
                        l26 = vader_emit_c_ast$declaration(3017u, l25, vader_box_obj(0u, NULL));
                        vader_array_push_ref((vader_array_t*) l0, l26.payload.obj);
                    }
                }
                l19 = (l19 + INT64_C(1));
            }
        } else {
            vader_array_t* _a9_arr = vader_array_new(97u, 0u, 13u, 963u);
            l27 = (void*) _a9_arr;
            l28 = INT64_C(0);
            l29 = ((vader_array_t*) l1)->length;
            while ((l28 < l29)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l28, 340u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l28)
                        t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l28];
                        l30 = t0.payload.s;
                        vader_array_t* _a12_arr = vader_array_new(254u, 0u, 13u, 1914u);
                        l31 = (void*) _a12_arr;
                        l32 = vader_emit_c_ast$call(2902u, l31);
                        vader_struct_vader_emit_c_ast$CDeclarator_t* _a13_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
                        vader_obj_header_init(_a13_obj, 963u);
                        _a13_obj->f_name = l30;
                        _a13_obj->f_length = vader_box_obj(0u, NULL);
                        _a13_obj->f_value = l32;
                        l33 = (void*) _a13_obj;
                        vader_array_push_ref((vader_array_t*) l27, l33);
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l28)
                        t0 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l28];
                        t2 = t0.payload.s;
                        t0 = vader_emit_c_ast$verbatim(t2);
                        l34 = vader_emit_c_ast$address_of(t0);
                        vader_array_push_ref((vader_array_t*) l3, l34.payload.obj);
                    } else {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l28)
                        t0 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l28];
                        t2 = t0.payload.s;
                        vader_struct_vader_emit_c_ast$CDeclarator_t* _a16_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
                        vader_obj_header_init(_a16_obj, 963u);
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
            vader_obj_header_init(_a17_obj, 962u);
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
    void* l6 = NULL;
    int64_t l5, l7;
    vader_string_t l8 = 0;
    int32_t l9, l10;
    vader_box_t l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStrData_t*) l2)->f_values)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l6 = ((vader_struct_vader_core_bytecode$BcStrData_t*) l2)->f_values;
    l5 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        l9 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_element_tag;
        l10 = vader_emit_c$atom_for(l3, l8);
        l11 = vader_emit_c$boxed_string(l9, l10);
        vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
        l7 = (l7 + INT64_C(1));
    }
    vader_emit_c$push_pool_array(l0, l1, 2905u, (uint8_t) 0, l4);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_emit_c_ast$call(2972u, l3);
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
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 738u) {
        l2 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names;
        l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        l5 = t0.payload.s;
        t1 = l4.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields)->length;
        l3 = ((int32_t) (int64_t) t2);
        t0 = vader_emit_c_ast$verbatim(0u);
        vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0.payload.obj;
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
            l10 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
            l11 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l12 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_type_index;
            l13 = vader_emit_c$val_type_of_field(l11, l12);
            l14 = vader_emit_c$coerced_as(l0, l8, l13);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9, l14.payload.obj);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
            l7 = (l7 + INT32_C(1));
        }
        t4 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_stack;
        if (t4) {
            l15 = vader_emit_c$aux(l0, 2634u);
            l16 = vader_emit_c$aux(l0, 2418u);
            l10 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack_storages;
            vader_struct_vader_emit_c$StackStorage_t* _a6_obj = (vader_struct_vader_emit_c$StackStorage_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackStorage_t));
            vader_obj_header_init(_a6_obj, 946u);
            _a6_obj->f_cname = l5;
            _a6_obj->f_storage = l15;
            l11 = (void*) _a6_obj;
            vader_array_push_ref((vader_array_t*) l10, l11);
            l17 = concat_2(l5, 349u);
            t0 = vader_emit_c_ast$verbatim(l15);
            l8 = vader_emit_c_ast$address_of(t0);
            vader_emit_c$declare(l0, l17, l16, l8);
            l15 = l16;
        } else {
            l16 = vader_emit_c$aux(l0, 2418u);
            l17 = concat_2(l5, 349u);
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
            l10 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
            t5 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
            l5 = vader_emit_c$field_c_name(t5);
            t5 = concat_3(l15, 388u, l5);
            l8 = vader_emit_c_ast$verbatim(t5);
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
            l14 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
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
        l19 = ((vader_array_t*) l2)->length;
        l18 = (l6 < l19);
    } else {
        l18 = false;
    }
    if (!(l18)) {
        l10 = (void*) vader_buffer_new((size_t) INT64_C(56));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l10, l6, 2164u);
        l19 = ((vader_array_t*) l2)->length;
        l6 = std_core$write_int(l10, l6, l19);
        l6 = std_core$write_string_at(l10, l6, 395u);
        l5 = std_core$finish_buffer(l10, l6);
    } else {
        l3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
        l15 = vader_core_bytecode$bc_type_key(l2, l3);
        l6 = vader_host_std_core$byte_len(l15);
        l10 = (void*) vader_buffer_new((size_t) (INT64_C(53) + l6));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l10, l6, 2714u);
        l6 = std_core$write_string_at(l10, l6, l15);
        l6 = std_core$write_string_at(l10, l6, 1131u);
        l19 = ((vader_array_t*) l2)->length;
        l6 = std_core$write_int(l10, l6, l19);
        l6 = std_core$write_string_at(l10, l6, 395u);
        l5 = std_core$finish_buffer(l10, l6);
    }
    l6 = vader_host_std_core$byte_len(l5);
    l2 = (void*) vader_buffer_new((size_t) (INT64_C(52) + l6));
    l6 = INT64_C(0);
    l6 = std_core$write_string_at(l2, l6, 2671u);
    t3 = ((vader_struct_vader_core_bytecode$StructNew_t*) l1)->f_type_id;
    l19 = ((int64_t) (int32_t) t3);
    l6 = std_core$write_int(l2, l6, l19);
    l6 = std_core$write_string_at(l2, l6, 460u);
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
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 738u)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(50));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 2676u);
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
    t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
    l5 = t2.payload.s;
    l6 = vader_emit_c$pop(l0);
    l7 = vader_emit_c$pop(l0);
    t3 = l4.payload.obj;
    l2 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t3)->f_fields;
    l3 = ((vader_struct_vader_core_bytecode$StructSet_t*) l1)->f_field_index;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 738u) {
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
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t1 = t3.payload.s;
                vader_struct_vader_emit_c_ast$CStructForward_t* _a4_obj = (vader_struct_vader_emit_c_ast$CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructForward_t));
                vader_obj_header_init(_a4_obj, 996u);
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
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a6_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a6_obj, 990u);
    _a6_obj->f_comment = t0;
    _a6_obj->f_items = l2;
    l2 = (void*) _a6_obj;
    vader_emit_c_ast$print_section(l1, l2);
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a7_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a8_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a8_obj, 990u);
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
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l6, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l7);
    l6 = (void*) _a1_arr;
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) l0)->length;
    while ((l7 < l8)) {
        l9 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l9, l10, 2693u);
        l10 = std_core$write_int(l9, l10, l7);
        l11 = std_core$finish_buffer(l9, l10);
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(335u, l11));
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
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 739u) {
            vader_array_t* _a1_arr = vader_array_new(254u, 0u, 13u, 1914u);
            l4 = (void*) _a1_arr;
            t1 = l6.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
            l8 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9];
                l6 = vader_emit_c$tag_of(l2);
                l10 = vader_emit_c$one_variant_check(l0, l6, l5);
                vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
                l9 = (l9 + INT64_C(1));
            }
            t2 = vader_emit_c_ast$any_of(l4);
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a3_obj, 985u);
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
        l11 = 2746u;
    } else {
        l11 = 1977u;
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
    l3 = std_core$write_string_at(l2, l3, 2904u);
    t0 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_null_tag;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 2782u);
    t0 = ((vader_struct_vader_core_bytecode$TypeConst_t*) l1)->f_type_id;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 2781u);
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
    void* l21 = NULL;
    int64_t l3, l7, l8;
    bool l4, l5;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l14 = vader_box_null(), l16 = vader_box_null(), l18 = vader_box_null(), l20 = vader_box_null(), l22 = vader_box_null();
    int32_t l15, l17, l19;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[8] = { &l9, &l10, &l14, &l16, &l18, &l20, &l22, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l6, &l11, &l12, &l13, &l21, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 8u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    l3 = ((vader_array_t*) l2)->length;
    l4 = false;
    l5 = false;
    l6 = l2;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        if (l9.tag == 728u) {
            l4 = true;
        }
        if (l9.tag == 725u) {
            l5 = true;
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l6 = (void*) _a1_arr;
    if (l4) {
        l9 = vader_emit_c$single_offset_list(2936u, 2424u);
        vader_array_push_ref((vader_array_t*) l6, l9.payload.obj);
    }
    if (l5) {
        l9 = vader_emit_c$single_offset_list(2870u, 2423u);
        vader_array_push_ref((vader_array_t*) l6, l9.payload.obj);
    }
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a3_obj, 990u);
    _a3_obj->f_comment = t0;
    _a3_obj->f_items = l6;
    l6 = (void*) _a3_obj;
    vader_emit_c_ast$print_section(l1, l6);
    vader_array_t* _a4_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l6 = (void*) _a4_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l10 = l9;
        if (l9.tag == 738u) {
            l11 = l10.payload.obj;
            l12 = l10.payload.obj;
            l13 = vader_emit_c$classify_struct_fields(l0, l12, l7);
            l14 = vader_emit_c$struct_info_row(l0, l11, l13, l7);
            vader_array_push_ref((vader_array_t*) l6, l14.payload.obj);
        } else if (l9.tag == 728u) {
            t0 = l10.payload.obj;
            l15 = vader_core_bytecode$size_of_bc_type(vader_ref_box(t0));
            l16 = vader_emit_c$single_reference_row(l7, 645u, 2938u, l15, 2936u);
            vader_array_push_ref((vader_array_t*) l6, l16.payload.obj);
        } else if (l9.tag == 725u) {
            t0 = l10.payload.obj;
            l17 = vader_core_bytecode$size_of_bc_type(vader_ref_box(t0));
            l18 = vader_emit_c$single_reference_row(l7, 577u, 2892u, l17, 2870u);
            vader_array_push_ref((vader_array_t*) l6, l18.payload.obj);
        } else {
            l19 = vader_core_bytecode$size_of_bc_type(l10);
            if ((l19 > INT32_C(0))) {
                l20 = vader_emit_c_ast$number(((int64_t) (int32_t) l19));
                t1 = vader_emit_c_ast$designated(430u, l20);
                vader_array_t* _a6_arr = vader_array_new(254u, 1u, 13u, 1914u);
                ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t1.payload.obj;
                l21 = (void*) _a6_arr;
                l22 = vader_emit_c$info_row(l7, l21);
                vader_array_push_ref((vader_array_t*) l6, l22.payload.obj);
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    l15 = ((int32_t) (int64_t) l3);
    l9 = vader_emit_c_ast$initializer_list(l6);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a7_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a7_obj, 963u);
    _a7_obj->f_name = 2982u;
    _a7_obj->f_length = vader_box_i32(338u, l15);
    _a7_obj->f_value = l9;
    l2 = (void*) _a7_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a8_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a8_obj, 972u);
    _a8_obj->f_storage = (uint8_t) 1;
    _a8_obj->f_constant = true;
    _a8_obj->f_type = 2981u;
    _a8_obj->f_declarator = l2;
    l2 = (void*) _a8_obj;
    l9 = vader_emit_c_ast$number(l3);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a9_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a9_obj, 963u);
    _a9_obj->f_name = 2980u;
    _a9_obj->f_length = vader_box_obj(0u, NULL);
    _a9_obj->f_value = l9;
    l6 = (void*) _a9_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a10_obj, 972u);
    _a10_obj->f_storage = (uint8_t) 1;
    _a10_obj->f_constant = true;
    _a10_obj->f_type = 2567u;
    _a10_obj->f_declarator = l6;
    l6 = (void*) _a10_obj;
    vader_array_t* _a11_arr = vader_array_new(21u, 0u, 0u, 335u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(256u, 2u, 13u, 1922u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l6;
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l2;
    l2 = (void*) _a12_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a13_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a13_obj, 990u);
    _a13_obj->f_comment = l11;
    _a13_obj->f_items = l2;
    l2 = (void*) _a13_obj;
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
    void* l9 = NULL;
    void* l10 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
    int32_t l5, l6;
    uint8_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    uint8_t t5;
    vader_box_t* gc_roots[3] = { &l4, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l9, &l10 };
    vader_string_t* gc_atom_roots[3] = { &l3, &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
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
        l3 = concat_2(2402u, l3);
        vader_emit_c$unreachable(l0, l3);
        t0 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
        if (t0 == INT64_C(1)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 340u);
            l7 = ((uint8_t) t1.payload.i);
            l2 = vader_emit_c$new_temporary(l0, l7);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_results);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
            t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(0), 340u);
            l7 = ((uint8_t) t1.payload.i);
            vader_emit_c$push_temporary(l0, l2, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_emit_c$pop(l0);
    t1 = vader_emit_c$coerced_as(l0, l8, (uint8_t) 17);
    vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a2_arr;
    t2 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_parameter_count;
    l5 = vader_chk_sub(i32, t2, INT32_C(1));
    l9 = vader_emit_c$pop_args_boxed(l0, l5);
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l9);
    l9 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx;
    l10 = l4.payload.obj;
    l9 = vader_emit_c$vtable_sig_for_row(l9, l10);
    t3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) l1)->f_vtable_key;
    t4 = vader_emit_c$vtable_helper_name(t3);
    l4 = vader_emit_c_ast$call(t4, l2);
    t5 = vader_core_bytecode$bc_single_result(l9);
    if (!(t5 == INT32_C(14))) {
        l7 = vader_core_bytecode$bc_single_result(l9);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l3 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_entries)->length;
        if (t0 == INT64_C(0)) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l8 = vader_emit_c$vtable_sig_for_row(l0, l7);
        vader_array_t* _a2_arr = vader_array_new(96u, 0u, 13u, 956u);
        l9 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
        l10 = (void*) _a3_arr;
        l11 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_entries;
        l12 = ((vader_array_t*) l11)->length;
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l14 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l13);
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
            l19 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l18);
            l20 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l19)->f_signature;
            l21 = vader_emit_c_ast$verbatim(2502u);
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t2 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 340u);
            l22 = ((uint8_t) t2.payload.i);
            t2 = vader_emit_c$coerce_expr(l2, l21, (uint8_t) 17, l22);
            vader_array_t* _a7_arr = vader_array_new(254u, 1u, 13u, 1914u);
            ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t2.payload.obj;
            l23 = (void*) _a7_arr;
            t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params)->length;
            l24 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
            l25 = INT32_C(0);
            while ((l25 < l24)) {
                l26 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l27 = INT64_C(0);
                l27 = std_core$write_string_at(l26, l27, 1424u);
                l28 = ((int64_t) (int32_t) l25);
                l27 = std_core$write_int(l26, l27, l28);
                t3 = std_core$finish_buffer(l26, l27);
                l29 = vader_emit_c_ast$verbatim(t3);
                l30 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l20)->f_params;
                l31 = vader_chk_add(i32, l25, INT32_C(1));
                vader_array_t* _a8_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l31)
                t2 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l31, 340u);
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
                vader_obj_header_init(_a9_obj, 967u);
                _a9_obj->f_expression = l34;
                l36 = (void*) _a9_obj;
                vader_array_t* _a10_arr = vader_array_new(95u, 0u, 13u, 951u);
                t6 = (void*) _a10_arr;
                vader_struct_vader_emit_c_ast$CReturn_t* _a11_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
                vader_obj_header_init(_a11_obj, 988u);
                _a11_obj->f_stores = t6;
                _a11_obj->f_value = vader_box_obj(0u, NULL);
                _a11_obj->f_snapshot_type = 0u;
                _a11_obj->f_pops_frame = false;
                l37 = (void*) _a11_obj;
                vader_array_t* _a12_arr = vader_array_new(257u, 2u, 13u, 1924u);
                ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l37;
                ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l36;
                l35 = (void*) _a12_arr;
            } else {
                vader_array_t* _a13_arr = vader_array_new(95u, 0u, 13u, 951u);
                l38 = (void*) _a13_arr;
                l39 = vader_core_bytecode$bc_single_result(l20);
                l40 = vader_core_bytecode$bc_single_result(l8);
                l41 = vader_emit_c$dispatcher_result(l2, l34, l39, l40);
                vader_struct_vader_emit_c_ast$CReturn_t* _a14_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
                vader_obj_header_init(_a14_obj, 988u);
                _a14_obj->f_stores = l38;
                _a14_obj->f_value = l41;
                _a14_obj->f_snapshot_type = 0u;
                _a14_obj->f_pops_frame = false;
                t6 = (void*) _a14_obj;
                vader_array_t* _a15_arr = vader_array_new(257u, 1u, 13u, 1924u);
                ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t6;
                l35 = (void*) _a15_arr;
            }
            t7 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l14)->f_receiver_type_index;
            t2 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t7));
            vader_struct_vader_emit_c_ast$CCase_t* _a16_obj = (vader_struct_vader_emit_c_ast$CCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCase_t));
            vader_obj_header_init(_a16_obj, 956u);
            _a16_obj->f_value = t2;
            _a16_obj->f_body = l35;
            l42 = (void*) _a16_obj;
            vader_array_push_ref((vader_array_t*) l9, l42);
            l13 = (l13 + INT64_C(1));
        }
        l43 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_key;
        t3 = concat_2(3022u, l43);
        t4 = vader_emit_c$c_string_lit(t3);
        t2 = vader_emit_c_ast$verbatim(t4);
        vader_array_t* _a17_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t2.payload.obj;
        l44 = (void*) _a17_arr;
        t2 = vader_emit_c_ast$call(2983u, l44);
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a18_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a18_obj, 967u);
        _a18_obj->f_expression = t2;
        l45 = (void*) _a18_obj;
        t2 = vader_emit_c_ast$verbatim(2502u);
        vader_struct_vader_emit_c_ast$CMember_t* _a19_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a19_obj, 981u);
        _a19_obj->f_base = t2;
        _a19_obj->f_member = 2694u;
        _a19_obj->f_arrow = false;
        l46 = (void*) _a19_obj;
        vader_array_t* _a20_arr = vader_array_new(257u, 1u, 13u, 1924u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l45;
        l47 = (void*) _a20_arr;
        vader_struct_vader_emit_c_ast$CSwitch_t* _a21_obj = (vader_struct_vader_emit_c_ast$CSwitch_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSwitch_t));
        vader_obj_header_init(_a21_obj, 997u);
        _a21_obj->f_subject = vader_ref_box(l46);
        _a21_obj->f_cases = l9;
        _a21_obj->f_default_body = vader_ref_box(l47);
        t6 = (void*) _a21_obj;
        vader_array_t* _a22_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t6;
        l48 = (void*) _a22_arr;
        t5 = vader_core_bytecode$bc_single_result(l8);
        if (t5 != INT32_C(14)) {
            vader_array_push_ref((vader_array_t*) l48, l45);
        }
        l49 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l7)->f_key;
        l50 = vader_emit_c$dispatcher_signature(l0, l49, l8);
        vader_array_t* _a23_arr = vader_array_new(255u, 0u, 13u, 1918u);
        l51 = (void*) _a23_arr;
        vader_struct_vader_emit_c_ast$CBlock_t* _a24_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
        vader_obj_header_init(_a24_obj, 953u);
        _a24_obj->f_body = l48;
        l52 = (void*) _a24_obj;
        vader_struct_vader_emit_c_ast$CFunction_t* _a25_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
        vader_obj_header_init(_a25_obj, 970u);
        _a25_obj->f_signature = l50;
        _a25_obj->f_prologue = l51;
        _a25_obj->f_body = l52;
        l53 = (void*) _a25_obj;
        vader_array_push_ref((vader_array_t*) l3, l53);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a26_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a26_arr->buf)[_a26_arr->offset + 0u] = vader_box_string(335u, 3020u);
    t6 = (void*) _a26_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a27_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a27_obj, 990u);
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
    vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1922u);
    l2 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$VtableRow_t*) l6)->f_entries)->length;
        if (t0 == INT64_C(0)) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = vader_emit_c$vtable_sig_for_row(l0, l6);
        l8 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l6)->f_key;
        t1 = vader_emit_c$dispatcher_signature(l0, l8, l7);
        vader_struct_vader_emit_c_ast$CPrototype_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
        vader_obj_header_init(_a2_obj, 987u);
        _a2_obj->f_signature = t1;
        l9 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l9);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a3_arr->buf)[_a3_arr->offset + 0u] = vader_box_string(335u, 3021u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a4_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a4_obj, 990u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_emit_c$StructOffsets_t* _a3_obj = (vader_struct_vader_emit_c$StructOffsets_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StructOffsets_t));
    vader_obj_header_init(_a3_obj, 948u);
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
    if (l0.tag == 943u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
        l2 = t1 == l1;
    } else if (l0.tag == 947u) {
        l2 = false;
    } else {
        if (!(l0.tag == 944u)) {
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
    vader_obj_header_init(_a0_obj, 984u);
    _a0_obj->f_type = 3017u;
    _a0_obj->f_name = 1902u;
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
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l6.tag == 738u)) {
        t0 = vader_emit_c_ast$verbatim(450u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
    l7 = t0.payload.s;
    t1 = l6.payload.obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
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
    vader_obj_header_init(_a0_obj, 992u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline = false;
    _a0_obj->f_result = 2905u;
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
    vader_obj_header_init(_a0_obj, 967u);
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
    if (l0.tag == 947u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c$StackTemporary_t*) t0)->f_temporary;
        l1 = vader_ref_box(t1);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_expression;
    } else if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_slot;
        vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
        vader_obj_header_init(_a0_obj, 979u);
        _a0_obj->f_slot = t2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 943u)) {
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
    return 1799u;
}

static vader_box_t vader_emit_c$extern_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(101u, 0u, 13u, 984u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        t0 = vader_emit_c$extern_parameter_type(l0, l1, l3);
        vader_struct_vader_emit_c_ast$CParameter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a2_obj, 984u);
        _a2_obj->f_type = t0;
        _a2_obj->f_name = 0u;
        l5 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        l3 = (l3 + INT64_C(1));
    }
    l6 = vader_emit_c$extern_result_type(l0, l1);
    l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 992u);
    _a3_obj->f_storage = (uint8_t) 2;
    _a3_obj->f_inline = false;
    _a3_obj->f_result = l6;
    _a3_obj->f_name = l7;
    _a3_obj->f_parameters = l2;
    t1 = (void*) _a3_obj;
    vader_struct_vader_emit_c_ast$CPrototype_t* _a4_obj = (vader_struct_vader_emit_c_ast$CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrototype_t));
    vader_obj_header_init(_a4_obj, 987u);
    _a4_obj->f_signature = t1;
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$extern_parameter_type(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    bool l4;
    int32_t l5;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l6, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    l4 = vader_core_bytecode$param_is_c_out(l3, l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    t0 = vader_emit_c$is_abi_array(l1, l5);
    if (t0) {
        t1 = vader_emit_c$pointer_to(3016u, l4);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    l5 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2];
    l6 = vader_emit_c$mirrored_c_struct(l1, l5);
    if (l6 != 0u) {
        t0 = vader_core_bytecode$param_is_by_address(l3, l2);
        if (!(t0)) {
            { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_emit_c$pointer_to(l6, l4);
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
    l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
    t0 = vader_emit_c$is_abi_nullable_pointer(l1, l5);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return 3017u; }
    }
    l7 = vader_core_bytecode$param_c_type(l0, l2);
    if (l7.tag == 0u) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t3 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 340u);
        t1 = vader_emit_c$extern_c_type(((uint8_t) t3.payload.i));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l7.payload.s;
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
        { vader_gc_top = gc_frame.prev; return 3017u; }
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
    vader_obj_header_init(_a0_obj, 963u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    l4 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a1_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a1_obj, 972u);
    _a1_obj->f_storage = (uint8_t) 2;
    _a1_obj->f_constant = l3;
    _a1_obj->f_type = l0;
    _a1_obj->f_declarator = l4;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$field_c_name(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_2(1976u, l0);
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
    l3 = concat_2(l0, 349u);
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
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields)->length;
    if (l3 != l4) {
        return false;
    }
    l5 = false;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields)->length;
    for (;;) {
        if ((l3 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            l6 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            l7 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
            if (l7 == l6) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            l5 = true;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            if (t1.tag == 734u) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
            if (t1.tag == 734u) {
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (l3.tag == 738u) {
        t0 = l3.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
        l4 = std_string$string$std_core$Contains$contains(t1, 992u);
        l5 = INT64_C(0);
        l6 = ((vader_array_t*) l0)->length;
        while ((l5 < l6)) {
            if (((int32_t) (int64_t) l5) == l1) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            if (l7.tag == 738u) {
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
                        l12 = std_string$string$std_core$Contains$contains(t1, 992u);
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
        l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
        while ((l2 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
            if (t0 == l1) {
                t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body)->length;
                if ((t1 > INT64_C(0))) {
                    return ((int32_t) (int64_t) l2);
                }
            }
            l2 = (l2 + INT64_C(1));
        }
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
        if (t2) {
            t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body)->length;
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
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
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
    if (l1 == 2167u) {
        { vader_gc_top = gc_frame.prev; return 997u; }
    }
    if (l1 == 396u) {
        { vader_gc_top = gc_frame.prev; return 310u; }
    }
    if (l1 == 2372u) {
        { vader_gc_top = gc_frame.prev; return 998u; }
    }
    t0 = std_string$string$std_core$Contains$contains(l1, 397u);
    if (t0) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$string$std_core$Contains$contains(l1, 1858u);
    if (!(t0)) {
        t1 = concat_2(l1, 404u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        if (l5.tag == 735u) {
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
    t2 = ((vader_array_t*) l2)->length;
    if (!(t2 == INT64_C(0))) {
        t3 = vader_emit_c_ast$any_of(l2);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a2_obj, 985u);
        _a2_obj->f_inner = t3;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_emit_c_ast$verbatim(450u);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$fn_builds_stack_object(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
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
    vader_obj_header_init(_a0_obj, 367u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
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
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        t2 = vader_emit_c$sanitise(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (void*) vader_buffer_new((size_t) INT64_C(84));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l5, l3, 1702u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core$write_int(l5, l3, l4);
    l3 = std_core$write_string_at(l5, l3, 381u);
    t1 = std_core$finish_buffer(l5, l3);
    vader_host_std_abort$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void* vader_emit_c$foreign_libraries(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l5 = vader_core_bytecode$library_name(t0);
        if (l5 != 0u) {
            t1 = std_core$$array$Contains$contains__string(l1, l5);
            if (!(t1)) {
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(335u, l5));
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
        vader_obj_header_init(_a0_obj, 967u);
        _a0_obj->f_expression = l3;
        l5 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(95u, 0u, 13u, 951u);
        l6 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l7 = (void*) _a2_arr;
        l8 = vader_emit_c_ast$call(2902u, l7);
        vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a3_obj, 988u);
        _a3_obj->f_stores = l6;
        _a3_obj->f_value = l8;
        _a3_obj->f_snapshot_type = 0u;
        _a3_obj->f_pops_frame = false;
        l6 = (void*) _a3_obj;
        vader_array_t* _a4_arr = vader_array_new(255u, 2u, 13u, 1918u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l6;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l5;
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
    vader_array_t* _a5_arr = vader_array_new(95u, 0u, 13u, 951u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a6_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a6_obj, 988u);
    _a6_obj->f_stores = t0;
    _a6_obj->f_value = l8;
    _a6_obj->f_snapshot_type = 0u;
    _a6_obj->f_pops_frame = false;
    t0 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(255u, 1u, 13u, 1918u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
    t0 = (void*) _a7_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$forwarded_result(void* l0, void* l1, vader_box_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    int32_t l6, l9;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l14 = NULL;
    vader_string_t l13 = 0;
    uint8_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[7] = { &l2, &l4, &l5, &l10, &l11, &l12, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l7, &l8, &l14, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l13, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$verbatim(2487u);
    l5 = vader_emit_c_ast$verbatim(2446u);
    l6 = vader_core_bytecode$bc_single_result_type(l0);
    t0 = vader_core_bytecode$bc_single_result(l0);
    if (t0 == INT32_C(14)) {
        vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 967u);
        _a0_obj->f_expression = l2;
        l7 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(255u, 0u, 13u, 1918u);
        l8 = (void*) _a1_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a2_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a2_obj, 937u);
        _a2_obj->f_capture = vader_ref_box(l7);
        _a2_obj->f_returns = false;
        _a2_obj->f_settle = l8;
        _a2_obj->f_returned = vader_box_obj(0u, NULL);
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_emit_c$is_abi_nullable_pointer(l1, l6);
    if (t2) {
        l9 = vader_emit_c$present_tag(l1, (uint8_t) 15);
        l10 = vader_emit_c$box_expr(l4, (uint8_t) 15, l9);
        l11 = vader_emit_c_ast$declaration(3017u, 2487u, l2);
        vader_array_t* _a3_arr = vader_array_new(255u, 0u, 13u, 1918u);
        l7 = (void*) _a3_arr;
        l10 = vader_emit_c$null_or(l4, l10);
        vader_struct_vader_emit_c$ForwardedResult_t* _a4_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a4_obj, 937u);
        _a4_obj->f_capture = l11;
        _a4_obj->f_returns = false;
        _a4_obj->f_settle = l7;
        _a4_obj->f_returned = l10;
        t1 = (void*) _a4_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_emit_c$is_abi_nullable_string(l1, l6);
    if (t2) {
        l9 = vader_emit_c$present_tag(l1, (uint8_t) 12);
        l10 = vader_emit_c$interned(l4);
        l10 = vader_emit_c_ast$cast(2179u, l10);
        l10 = vader_emit_c$box_call(2107u, l9, l10);
        l11 = vader_emit_c_ast$declaration(1799u, 2487u, l2);
        l10 = vader_emit_c$null_or(l4, l10);
        t3 = vader_emit_c_ast$declaration(2905u, 2446u, l10);
        vader_array_t* _a5_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t3.payload.obj;
        l7 = (void*) _a5_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a6_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a6_obj, 937u);
        _a6_obj->f_capture = l11;
        _a6_obj->f_returns = false;
        _a6_obj->f_settle = l7;
        _a6_obj->f_returned = l5;
        t1 = (void*) _a6_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$bc_single_result(l0);
    if (t0 == INT32_C(12)) {
        l10 = vader_emit_c_ast$verbatim(250u);
        l11 = vader_emit_c_ast$number(INT64_C(0));
        vader_array_t* _a7_arr = vader_array_new(254u, 2u, 13u, 1914u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 1u] = l11.payload.obj;
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l10.payload.obj;
        l7 = (void*) _a7_arr;
        l10 = vader_emit_c_ast$call(2898u, l7);
        t1 = (void*) &vader_data_53;
        vader_array_t* _a8_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l7 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) INT64_C(0));
        l11 = vader_emit_c_ast$binary((uint8_t) 11, l4, vader_ref_box(l7));
        l12 = vader_emit_c$interned(l4);
        vader_struct_vader_emit_c_ast$CConditional_t* _a9_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
        vader_obj_header_init(_a9_obj, 960u);
        _a9_obj->f_condition = l11;
        _a9_obj->f_then_value = l10;
        _a9_obj->f_else_value = l12;
        l7 = (void*) _a9_obj;
        l10 = vader_emit_c_ast$declaration(1799u, 2487u, l2);
        t3 = vader_emit_c_ast$declaration(2975u, 2446u, vader_ref_box(l7));
        vader_array_t* _a10_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = t3.payload.obj;
        l7 = (void*) _a10_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a11_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a11_obj, 937u);
        _a11_obj->f_capture = l10;
        _a11_obj->f_returns = false;
        _a11_obj->f_settle = l7;
        _a11_obj->f_returned = l5;
        t1 = (void*) _a11_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l13 = vader_emit_c$mirrored_c_struct(l1, l6);
    if (l13 != 0u) {
        t1 = vader_emit_c$mirror_result(l1, l6, l13, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3)) {
        t0 = vader_core_bytecode$bc_single_result(l0);
        t4 = vader_emit_c$c_type_for_val_bare(t0);
        l5 = vader_emit_c_ast$declaration(t4, 2487u, l2);
        vader_array_t* _a12_arr = vader_array_new(255u, 0u, 13u, 1918u);
        l14 = (void*) _a12_arr;
        vader_struct_vader_emit_c$ForwardedResult_t* _a13_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
        vader_obj_header_init(_a13_obj, 937u);
        _a13_obj->f_capture = l5;
        _a13_obj->f_returns = false;
        _a13_obj->f_settle = l14;
        _a13_obj->f_returned = l4;
        t1 = (void*) _a13_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a14_arr = vader_array_new(95u, 0u, 13u, 951u);
    t1 = (void*) _a14_arr;
    vader_struct_vader_emit_c_ast$CReturn_t* _a15_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a15_obj, 988u);
    _a15_obj->f_stores = t1;
    _a15_obj->f_value = l2;
    _a15_obj->f_snapshot_type = 0u;
    _a15_obj->f_pops_frame = false;
    l7 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l8 = (void*) _a16_arr;
    vader_struct_vader_emit_c$ForwardedResult_t* _a17_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
    vader_obj_header_init(_a17_obj, 937u);
    _a17_obj->f_capture = vader_ref_box(l7);
    _a17_obj->f_returns = true;
    _a17_obj->f_settle = l8;
    _a17_obj->f_returned = vader_box_obj(0u, NULL);
    t1 = (void*) _a17_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$fresh_slot(vader_string_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l6, &t1 };
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 394u);
    l2 = vader_emit_c_ast$verbatim(t0);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l4 = INT64_C(0);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 2780u);
    t0 = std_core$finish_buffer(l3, l4);
    l6 = vader_emit_c_ast$verbatim(t0);
    t1 = vader_emit_c_ast$binary((uint8_t) 3, l2, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$function_definition(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    int32_t l6, l23;
    vader_string_t l7 = 0;
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    vader_string_t l29 = 0;
    vader_string_t l30 = 0;
    int64_t l8, l9, l14, l15, l16, l19, l20, l21;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l22 = vader_box_null(), l31 = vader_box_null(), l32 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null();
    bool l12, l18;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    int64_t t5;
    vader_box_t* gc_roots[8] = { &l10, &l11, &l22, &l31, &l32, &l33, &l34, &t4 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l5, &l24, &l25, &l26, &l27, &l28, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l7, &l13, &l17, &l29, &l30, &t3 };
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
    l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body)->length;
    while ((l8 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l10 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_drop_call_result;
        if (t0) {
            if (l10.tag == 771u) {
                ((vader_struct_vader_emit_c$FnState_t*) l3)->f_drop_call_result = false;
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_debug);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
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
                t3 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_file;
                l13 = vader_emit_c$c_string_lit(t3);
                l14 = vader_host_std_core$byte_len(l13);
                l4 = (void*) vader_buffer_new((size_t) (INT64_C(27) + l14));
                l15 = INT64_C(0);
                l15 = std_core$write_string_at(l4, l15, 257u);
                t1 = l11.payload.obj;
                t2 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_line;
                l16 = ((int64_t) (int32_t) t2);
                l15 = std_core$write_int(l4, l15, l16);
                l15 = std_core$write_string_at(l4, l15, 14u);
                l15 = std_core$write_string_at(l4, l15, l13);
                l17 = std_core$finish_buffer(l4, l15);
                vader_emit_c$directive(l3, l17);
                t1 = l11.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_line;
                t1 = l11.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$DebugPos_t*) t1)->f_file;
            }
        }
        if (l10.tag == 760u) {
            l18 = true;
        } else {
            l18 = l10.tag == 761u;
        }
        if (l18) {
            l19 = vader_chk_add(i64, l8, INT64_C(1));
            l20 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body)->length;
            if ((l19 < l20)) {
                l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body;
                l21 = vader_chk_add(i64, l8, INT64_C(1));
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l21)
                t4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l21);
                if (t4.tag == 771u) {
                    l22 = l10;
                    t5 = vader_emit_c$callee_result_arity(l0, l22);
                    if ((t5 <= INT64_C(1))) {
                        ((vader_struct_vader_emit_c$FnState_t*) l3)->f_drop_call_result = true;
                    }
                }
            }
        }
        l23 = ((int32_t) (int64_t) l8);
        vader_emit_c$emit_op(l3, l23, l10);
        l8 = (l8 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        t0 = vader_emit_c_ast$ends_with_return(((vader_struct_vader_emit_c$FnState_t*) l3)->f_root);
        if (!(t0)) {
            l4 = ((vader_struct_vader_emit_c_ast$CBlock_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root)->f_body;
            vader_struct_vader_emit_c_ast$CVerbatim_t* _a3_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
            vader_obj_header_init(_a3_obj, 1001u);
            _a3_obj->f_text = 2946u;
            l5 = (void*) _a3_obj;
            vader_struct_vader_emit_c_ast$CVerbatim_t* _a4_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
            vader_obj_header_init(_a4_obj, 1001u);
            _a4_obj->f_text = 2056u;
            l24 = (void*) _a4_obj;
            vader_struct_vader_emit_c_ast$CAssign_t* _a5_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
            vader_obj_header_init(_a5_obj, 951u);
            _a5_obj->f_target = vader_ref_box(l5);
            _a5_obj->f_value = vader_ref_box(l24);
            _a5_obj->f_operator = vader_box_obj(0u, NULL);
            l5 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l4, l5);
        }
    }
    l4 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root;
    l5 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_temporaries;
    l4 = vader_emit_c_ast$coalesce_temporaries(l4, l5);
    vader_emit_c_ast$structure_loops(((vader_struct_vader_emit_c$FnState_t*) l3)->f_root);
    vader_array_t* _a6_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l24 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l25 = (void*) _a8_arr;
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        l26 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params;
        l8 = INT64_C(0);
        l9 = ((vader_array_t*) l26)->length;
        while ((l8 < l9)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t4 = vader_array_read_u8(_a9_slotarr, _a9_slotarr->offset + (size_t) l8, 340u);
            if (((int32_t) t4.payload.i) == INT32_C(16)) {
                vader_struct_vader_emit_c_ast$CLocal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                vader_obj_header_init(_a10_obj, 979u);
                _a10_obj->f_slot = ((int32_t) (int64_t) l8);
                t1 = (void*) _a10_obj;
                l10 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                vader_array_push_ref((vader_array_t*) l24, l10.payload.obj);
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                t4 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l8, 340u);
                if (((int32_t) t4.payload.i) == INT32_C(12)) {
                    vader_struct_vader_emit_c_ast$CLocal_t* _a12_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                    vader_obj_header_init(_a12_obj, 979u);
                    _a12_obj->f_slot = ((int32_t) (int64_t) l8);
                    t1 = (void*) _a12_obj;
                    l11 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                    vader_array_push_ref((vader_array_t*) l25, l11.payload.obj);
                } else {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l26);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    t4 = vader_array_read_u8(_a13_slotarr, _a13_slotarr->offset + (size_t) l8, 340u);
                    t0 = vader_emit_c$is_ref_val(((uint8_t) t4.payload.i));
                    if (t0) {
                        vader_struct_vader_emit_c_ast$CLocal_t* _a14_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
                        vader_obj_header_init(_a14_obj, 979u);
                        _a14_obj->f_slot = ((int32_t) (int64_t) l8);
                        t1 = (void*) _a14_obj;
                        l22 = vader_emit_c_ast$address_of(vader_ref_box(t1));
                        vader_array_push_ref((vader_array_t*) l5, l22.payload.obj);
                    }
                }
            }
            l8 = (l8 + INT64_C(1));
        }
    }
    vader_array_t* _a15_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l26 = (void*) _a15_arr;
    l12 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    vader_emit_c$emit_local_decls(l2, l26, l5, l24, l25, l12);
    l12 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    vader_emit_c$emit_temporary_declarations(l4, l26, l5, l24, l25, l12);
    t0 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_needs_frame;
    if (t0) {
        t5 = ((vader_array_t*) l5)->length;
        if ((t5 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(2906u, 2058u, l5);
            vader_array_push_ref((vader_array_t*) l26, l10.payload.obj);
        }
        t5 = ((vader_array_t*) l24)->length;
        if ((t5 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3018u, 2057u, l24);
            vader_array_push_ref((vader_array_t*) l26, l10.payload.obj);
        }
        t5 = ((vader_array_t*) l5)->length;
        if ((t5 > INT64_C(0))) {
            l7 = 2058u;
        } else {
            l7 = 720u;
        }
        t5 = ((vader_array_t*) l24)->length;
        if ((t5 > INT64_C(0))) {
            l13 = 2057u;
        } else {
            l13 = 720u;
        }
        l8 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages)->length;
        if ((l8 > INT64_C(0))) {
            l17 = 2059u;
        } else {
            l17 = 720u;
        }
        vader_array_t* _a16_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l4 = (void*) _a16_arr;
        l9 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages)->length;
        vader_array_t* _a17_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l9);
        l4 = (void*) _a17_arr;
        l27 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_stack_storages;
        l9 = ((vader_array_t*) l27)->length;
        l14 = INT64_C(0);
        while ((l14 < l9)) {
            vader_array_t* _a18_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            l28 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l14);
            l29 = ((vader_struct_vader_emit_c$StackStorage_t*) l28)->f_cname;
            l30 = ((vader_struct_vader_emit_c$StackStorage_t*) l28)->f_storage;
            l10 = vader_emit_c_ast$verbatim(3064u);
            l11 = vader_emit_c_ast$declaration(l29, l30, l10);
            vader_array_push_ref((vader_array_t*) l26, l11.payload.obj);
            t3 = ((vader_struct_vader_emit_c$StackStorage_t*) l28)->f_storage;
            t4 = vader_emit_c_ast$verbatim(t3);
            l22 = vader_emit_c_ast$address_of(t4);
            l31 = vader_emit_c_ast$cast(3017u, l22);
            vader_array_push_ref((vader_array_t*) l4, l31.payload.obj);
            l14 = (l14 + INT64_C(1));
        }
        if ((l8 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(3017u, 2059u, l4);
            vader_array_push_ref((vader_array_t*) l26, l10.payload.obj);
        }
        l9 = ((vader_array_t*) l25)->length;
        if ((l9 > INT64_C(0))) {
            l10 = vader_emit_c_ast$array_declaration(2976u, 2054u, l25);
            vader_array_push_ref((vader_array_t*) l26, l10.payload.obj);
        }
        l10 = vader_emit_c_ast$verbatim(2946u);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l15 = ((vader_array_t*) l5)->length;
        l14 = std_core$write_int(l4, l14, l15);
        l14 = std_core$write_string_at(l4, l14, 2780u);
        t3 = std_core$finish_buffer(l4, l14);
        l11 = vader_emit_c_ast$verbatim(t3);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l15 = ((vader_array_t*) l24)->length;
        l14 = std_core$write_int(l4, l14, l15);
        l14 = std_core$write_string_at(l4, l14, 2780u);
        t3 = std_core$finish_buffer(l4, l14);
        l22 = vader_emit_c_ast$verbatim(t3);
        l31 = vader_emit_c_ast$verbatim(l7);
        l32 = vader_emit_c_ast$verbatim(l13);
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l14 = std_core$write_int(l4, l14, l8);
        l14 = std_core$write_string_at(l4, l14, 2780u);
        t3 = std_core$finish_buffer(l4, l14);
        l33 = vader_emit_c_ast$verbatim(t3);
        l34 = vader_emit_c_ast$verbatim(l17);
        vader_array_t* _a19_arr = vader_array_new(254u, 7u, 13u, 1914u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 6u] = l34.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 5u] = l33.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 4u] = l32.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 3u] = l31.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 2u] = l22.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 1u] = l11.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = l10.payload.obj;
        l4 = (void*) _a19_arr;
        if ((l9 > INT64_C(0))) {
            l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l8 = INT64_C(0);
            l8 = std_core$write_int(l5, l8, l9);
            l8 = std_core$write_string_at(l5, l8, 2780u);
            t3 = std_core$finish_buffer(l5, l8);
            l10 = vader_emit_c_ast$verbatim(t3);
            l11 = vader_emit_c_ast$verbatim(2054u);
            vader_array_t* _a20_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 1u] = l11.payload.obj;
            ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l10.payload.obj;
            l5 = (void*) _a20_arr;
            vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l5);
        }
        vader_struct_vader_emit_c_ast$CInitializerList_t* _a21_obj = (vader_struct_vader_emit_c_ast$CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInitializerList_t));
        vader_obj_header_init(_a21_obj, 977u);
        _a21_obj->f_elements = l4;
        l4 = (void*) _a21_obj;
        l10 = vader_emit_c_ast$declaration(2943u, 2055u, vader_ref_box(l4));
        vader_array_push_ref((vader_array_t*) l26, l10.payload.obj);
        l10 = vader_emit_c_ast$verbatim(2946u);
        t4 = vader_emit_c_ast$verbatim(2055u);
        l11 = vader_emit_c_ast$address_of(t4);
        vader_struct_vader_emit_c_ast$CAssign_t* _a22_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a22_obj, 951u);
        _a22_obj->f_target = l10;
        _a22_obj->f_value = l11;
        _a22_obj->f_operator = vader_box_obj(0u, NULL);
        l4 = (void*) _a22_obj;
        vader_array_push_ref((vader_array_t*) l26, l4);
    }
    l4 = vader_emit_c$signature_for(l0, l1);
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l3)->f_root;
    vader_struct_vader_emit_c_ast$CFunction_t* _a23_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a23_obj, 970u);
    _a23_obj->f_signature = l4;
    _a23_obj->f_prologue = l26;
    _a23_obj->f_body = l3;
    t1 = (void*) _a23_obj;
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
    l1 = concat_2(l0, 349u);
    t0 = concat_3(2569u, l0, 321u);
    t1 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(2941u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 951u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l2 = (void*) _a1_arr;
    t0 = vader_emit_c_ast$call(2944u, l2);
    vader_struct_vader_emit_c_ast$CMember_t* _a2_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a2_obj, 981u);
    _a2_obj->f_base = t0;
    _a2_obj->f_member = l0;
    _a2_obj->f_arrow = false;
    l2 = (void*) _a2_obj;
    l3 = vader_emit_c_ast$cast(2178u, vader_ref_box(l2));
    vader_struct_vader_emit_c_ast$CReturn_t* _a3_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a3_obj, 988u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals)->length;
    while ((l3 < l4)) {
        l5 = ((int32_t) (int64_t) l3);
        t0 = vader_emit_c$global_slot_val(l0, l5);
        if (t0 == l1) {
            l6 = (void*) vader_buffer_new((size_t) INT64_C(33));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l6, l7, 2947u);
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
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
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 737u) {
            return true;
        }
        if (l4.tag == 724u) {
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
    t0 = concat_2(2952u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_types;
    t0 = vader_emit_c$shim_body(l1, l4);
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 953u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CFunction_t* _a2_obj = (vader_struct_vader_emit_c_ast$CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFunction_t));
    vader_obj_header_init(_a2_obj, 970u);
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
    t0 = std_string$ends_with(l0, 432u);
    if (!(t0)) {
        t1 = concat_2(l0, 413u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = std_core$len(l0);
    l1 = vader_chk_sub(i64, t2, INT64_C(8));
    vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
    vader_obj_header_init(_a0_obj, 613u);
    _a0_obj->f_start = INT64_C(0);
    _a0_obj->f_end = l1;
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = INT64_C(0);
    l2 = (void*) _a0_obj;
    t1 = std_core$string$Index$at$1(l0, l2);
    t3 = concat_2(t1, 413u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$imports_may_collect(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    bool l5;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) l1)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = __lambda_vader_emit_c_6(t0);
        vader_array_push_bool((vader_array_t*) l2, l5);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$imports_of_library(void* l0, vader_string_t l1) {
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
    vader_obj_header_init(_a0_obj, 366u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(62u, 0u, 13u, 731u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
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
    t0 = std_core$len(l0);
    l1 = (t0 >= INT64_C(2));
    if (l1) {
        t0 = std_core$len(l0);
        l3 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
        vader_obj_header_init(_a0_obj, 613u);
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
        t1 = std_string$starts_with(l0, 502u);
        if (t1) {
            t1 = std_string$ends_with(l0, 526u);
            if (t1) {
                vader_struct_vader_emit_c_ast$CInclude_t* _a1_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
                vader_obj_header_init(_a1_obj, 975u);
                _a1_obj->f_path = l2;
                _a1_obj->f_system = true;
                t2 = (void*) _a1_obj;
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l1) {
        t1 = std_string$starts_with(l0, 248u);
        if (t1) {
            t1 = std_string$ends_with(l0, 248u);
            if (t1) {
                vader_struct_vader_emit_c_ast$CInclude_t* _a2_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
                vader_obj_header_init(_a2_obj, 975u);
                _a2_obj->f_path = l2;
                _a2_obj->f_system = false;
                t2 = (void*) _a2_obj;
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l1 = false;
            vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
            vader_obj_header_init(_a3_obj, 975u);
            _a3_obj->f_path = l0;
            _a3_obj->f_system = l1;
            t2 = (void*) _a3_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l1 = false;
        vader_struct_vader_emit_c_ast$CInclude_t* _a4_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
        vader_obj_header_init(_a4_obj, 975u);
        _a4_obj->f_path = l0;
        _a4_obj->f_system = l1;
        t2 = (void*) _a4_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = false;
    vader_struct_vader_emit_c_ast$CInclude_t* _a5_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a5_obj, 975u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 618u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CPrinter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CPrinter_t));
    vader_obj_header_init(_a2_obj, 986u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l1 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CInclude_t* _a3_obj = (vader_struct_vader_emit_c_ast$CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInclude_t));
    vader_obj_header_init(_a3_obj, 975u);
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
    l3 = std_core$write_string_at(l2, l3, 966u);
    l3 = std_core$write_int(l2, l3, l0);
    l3 = std_core$write_string_at(l2, l3, 969u);
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
    l5 = std_core$write_string_at(l4, l5, 2780u);
    t0 = std_core$finish_buffer(l4, l5);
    l7 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(2953u, l4);
    vader_emit_c$evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c$integer_as_address(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c_ast$cast(2194u, l0);
    t0 = vader_emit_c_ast$cast(3017u, l1);
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
    vader_obj_header_init(_a0_obj, 957u);
    _a0_obj->f_types = l0;
    _a0_obj->f_value = l1;
    l2 = (void*) _a0_obj;
    t0 = vader_emit_c_ast$designated(412u, vader_ref_box(l2));
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$internal_fn_flags(void* l0, void* l1, vader_string_t l2) {
    int64_t l3, l5, l7, l9, l10;
    void* l4 = NULL;
    void* l6 = NULL;
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
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l6, &l8, &l13, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a0_arr;
    if ((INT64_C(0) < l3)) {
        l5 = l3;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(19u, 0u, 12u, 333u);
    l6 = (void*) _a2_arr;
    if ((INT64_C(0) < l3)) {
        l5 = l3;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l5);
    l6 = (void*) _a3_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_push_i32((vader_array_t*) l4, INT32_C(-1));
        vader_array_push_bool((vader_array_t*) l6, false);
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    l7 = ((vader_array_t*) l1)->length;
    while ((l5 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l8 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10];
            l12 = ((int32_t) (int64_t) l5);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11] = (int32_t) l12;
            l10 = (l10 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_exports;
    l5 = ((vader_array_t*) l8)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
        l11 = ((vader_struct_vader_core_bytecode$BcExport_t*) t0)->f_fn_index;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
        ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11] = (uint8_t) true;
        l7 = (l7 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_vtables;
    l5 = ((vader_array_t*) l8)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l7);
        l13 = ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_entries;
        l9 = ((vader_array_t*) l13)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
            l11 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) t0)->f_fn_index;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l11)
            ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l11] = (uint8_t) true;
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l8 = vader_emit_c$scan_fn_value_usage(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l8)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
        t1 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l14 = true;
        } else {
            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnValueUsage_t*) l8)->f_is_closure);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
            t2 = ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5];
            l14 = t2;
        }
        if (l14) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
            ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5] = (uint8_t) true;
        }
        if (l2 != 0u) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l5);
            t3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
            if (t3 == l2) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l5)
                ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5] = (uint8_t) true;
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
        l11 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l5];
        vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l5);
        l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l8)->length;
        l9 = INT64_C(0);
        while ((l9 < l7)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t4 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l9);
            l12 = vader_emit_c$callee_index_of(t4);
            if ((l12 >= INT32_C(0))) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l12)
                t1 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l12];
                if (t1 != l11) {
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l12)
                    ((uint8_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l12] = (uint8_t) true;
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a22_arr;
    if ((INT64_C(0) < l3)) {
        l5 = l3;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a23_arr;
    l5 = INT64_C(0);
    vader_array_t* _pc314_hdr = (vader_array_t*) l4;
    size_t _pc314_len = _pc314_hdr->length;
    size_t _pc314_cap = (_pc314_hdr->offset == 0 && !vader_array_is_borrowed(_pc314_hdr) && _pc314_hdr->length >= _pc314_hdr->buf->length) ? _pc314_hdr->capacity : (size_t) 0;
    void* _pc314_slots = _pc314_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l5)
            t2 = ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l5];
            t5 = t2;
            l14 = !(t5);
            if (VADER_LIKELY(_pc314_len < _pc314_cap)) {
                ((uint8_t*) _pc314_slots)[_pc314_len] = (uint8_t) (l14);
                _pc314_len += 1;
            } else {
                _pc314_hdr->length = _pc314_len;
                if (_pc314_hdr->buf->length < _pc314_len) {
                    _pc314_hdr->buf->length = _pc314_len;
                }
                vader_array_push_bool((vader_array_t*) l4, l14);
                _pc314_hdr = (vader_array_t*) l4;
                _pc314_len = _pc314_hdr->length;
                _pc314_cap = (_pc314_hdr->offset == 0 && !vader_array_is_borrowed(_pc314_hdr) && _pc314_hdr->length >= _pc314_hdr->buf->length) ? _pc314_hdr->capacity : (size_t) 0;
                _pc314_slots = _pc314_hdr->buf->slots;
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        _pc314_hdr->length = _pc314_len;
        if (_pc314_hdr->buf->length < _pc314_len) {
            _pc314_hdr->buf->length = _pc314_len;
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_emit_c_ast$call(2657u, l1);
    vader_array_t* _a1_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a1_arr;
    t0 = vader_emit_c_ast$call(2898u, l1);
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
    if (l1.tag == 843u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        vader_emit_c$drop_bound_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 844u) {
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
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (int64_t) t0);
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return t1.tag == 725u;
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
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (int64_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 739u)) {
        return false;
    }
    t1 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants)->length;
    if (t0 != INT64_C(2)) {
        return false;
    }
    l4 = false;
    l5 = false;
    t1 = l3.payload.obj;
    l6 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        if (!((l2 < INT32_C(0)))) {
            t0 = ((vader_array_t*) l0)->length;
            l9 = ((int32_t) (int64_t) t0);
            if (!((l2 >= l9))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                if (l3.tag == 735u) {
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
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (int64_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 739u)) {
        return false;
    }
    t1 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants)->length;
    if (t0 != INT64_C(2)) {
        return false;
    }
    l4 = false;
    l5 = false;
    t1 = l3.payload.obj;
    l6 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        if (!((l2 < INT32_C(0)))) {
            t0 = ((vader_array_t*) l0)->length;
            l9 = ((int32_t) (int64_t) t0);
            if (!((l2 >= l9))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                if (l3.tag == 735u) {
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
    t0 = (void*) &vader_data_41;
    t1 = std_core$$array$Contains$contains__string(t0, l0);
    return t1;
}

static bool vader_emit_c$is_cache_safe(vader_box_t l0) {
    if ((l0.tag == 841u || l0.tag == 842u || l0.tag == 867u || l0.tag == 884u)) {
        return true;
    }
    if ((l0.tag == 837u || l0.tag == 838u || l0.tag == 839u)) {
        return true;
    }
    if ((l0.tag == 859u || l0.tag == 860u || l0.tag == 861u)) {
        return true;
    }
    if ((l0.tag == 715u || l0.tag == 716u || l0.tag == 722u)) {
        return true;
    }
    if ((l0.tag == 834u || l0.tag == 835u || l0.tag == 836u || l0.tag == 840u)) {
        return true;
    }
    if ((l0.tag == 856u || l0.tag == 857u || l0.tag == 858u || l0.tag == 862u)) {
        return true;
    }
    if ((l0.tag == 748u || l0.tag == 763u || l0.tag == 776u || l0.tag == 797u || l0.tag == 817u)) {
        return true;
    }
    if ((l0.tag == 767u || l0.tag == 789u || l0.tag == 848u || l0.tag == 855u || l0.tag == 864u || l0.tag == 871u)) {
        return true;
    }
    if ((l0.tag == 792u || l0.tag == 798u || l0.tag == 804u || l0.tag == 805u || l0.tag == 807u || l0.tag == 811u)) {
        return true;
    }
    if ((l0.tag == 812u || l0.tag == 818u || l0.tag == 824u || l0.tag == 825u || l0.tag == 827u || l0.tag == 831u)) {
        return true;
    }
    if ((l0.tag == 764u || l0.tag == 765u)) {
        return true;
    }
    if ((l0.tag == 775u || l0.tag == 777u || l0.tag == 783u || l0.tag == 785u || l0.tag == 786u)) {
        return true;
    }
    if ((l0.tag == 872u || l0.tag == 877u || l0.tag == 878u || l0.tag == 883u)) {
        return true;
    }
    if ((l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u || l0.tag == 808u || l0.tag == 809u || l0.tag == 810u)) {
        return true;
    }
    if ((l0.tag == 813u || l0.tag == 814u || l0.tag == 815u || l0.tag == 816u || l0.tag == 828u || l0.tag == 829u || l0.tag == 830u)) {
        return true;
    }
    if ((l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 803u || l0.tag == 806u)) {
        return true;
    }
    if ((l0.tag == 819u || l0.tag == 820u || l0.tag == 821u || l0.tag == 822u || l0.tag == 823u || l0.tag == 826u)) {
        return true;
    }
    if ((l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 784u)) {
        return true;
    }
    if ((l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 879u || l0.tag == 880u || l0.tag == 881u || l0.tag == 882u)) {
        return true;
    }
    if ((l0.tag == 749u || l0.tag == 750u)) {
        return true;
    }
    if ((l0.tag == 850u || l0.tag == 851u || l0.tag == 863u || l0.tag == 865u || l0.tag == 866u)) {
        return true;
    }
    if ((l0.tag == 747u || l0.tag == 751u || l0.tag == 752u)) {
        return true;
    }
    if ((l0.tag == 744u || l0.tag == 745u || l0.tag == 766u || l0.tag == 774u || l0.tag == 787u || l0.tag == 849u || l0.tag == 852u)) {
        return true;
    }
    if (!(l0.tag == 771u)) {
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
    if ((l0.tag == 841u || l0.tag == 842u)) {
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
    return (l0.tag == 746u || l0.tag == 832u || l0.tag == 845u);
}

static bool vader_emit_c$is_tail_forwarder(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4;
    vader_box_t t0;
    bool t1;
    l2 = vader_emit_c$leading_pure_reads(l1);
    l3 = ((vader_array_t*) l1)->length;
    if (l2 == l3) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = vader_emit_c$safepoint_result_arity(l0, l4, l2);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int64_t) l4.payload.i);
    l2 = vader_chk_add(i64, l2, INT64_C(1));
    if (l3 == INT64_C(1)) {
        l3 = ((vader_array_t*) l1)->length;
        if ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            if (t0.tag == 771u) {
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
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        t1 = vader_emit_c$is_pure_read(t0);
        if (!(t1)) {
            return l1;
        }
        l1 = (l1 + INT64_C(1));
    }
    t2 = ((vader_array_t*) l0)->length;
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(2977u, l2);
    l3 = vader_emit_c_ast$declaration(1799u, 1695u, l3);
    t0 = vader_emit_c_ast$verbatim(1695u);
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0.payload.obj;
    l2 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(l0, l2);
    l4 = vader_emit_c_ast$declaration(3017u, 2487u, l4);
    l5 = vader_emit_c_ast$verbatim(1695u);
    vader_array_t* _a2_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l5.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l1.payload.obj;
    l2 = (void*) _a2_arr;
    l5 = vader_emit_c_ast$perform(2922u, l2);
    vader_array_t* _a3_arr = vader_array_new(95u, 0u, 13u, 951u);
    l2 = (void*) _a3_arr;
    t0 = vader_emit_c_ast$verbatim(2487u);
    l6 = vader_emit_c$address_as_integer(t0);
    vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a4_obj, 988u);
    _a4_obj->f_stores = l2;
    _a4_obj->f_value = l6;
    _a4_obj->f_snapshot_type = 0u;
    _a4_obj->f_pops_frame = false;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(255u, 4u, 13u, 1918u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 3u] = l2;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l5.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l3.payload.obj;
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
    t0 = concat_2(1025u, l1);
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
    l3 = concat_2(2935u, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params)->length;
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
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l9, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    if ((INT64_C(1) < l2)) {
        t0 = ((vader_array_t*) l0)->length;
        l2 = (t0 - INT64_C(1));
    } else {
        l2 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(1);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1424u);
        l6 = vader_chk_sub(i64, l2, INT64_C(1));
        l5 = std_core$write_int(l4, l5, l6);
        t1 = std_core$finish_buffer(l4, l5);
        l7 = vader_emit_c_ast$verbatim(t1);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 340u);
        l8 = ((uint8_t) t2.payload.i);
        l9 = vader_emit_c$unbox_expr(l7, l8);
        vader_array_push_ref((vader_array_t*) l1, l9.payload.obj);
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$literal_within(vader_box_t l0, int64_t l1) {
    vader_box_t l2;
    bool l3;
    void* t0;
    int64_t t1;
    if (!(l0.tag == 944u)) {
        return false;
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_expression;
    if (l2.tag == 978u) {
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
    l2 = vader_emit_c_ast$verbatim(1557u);
    t0 = vader_emit_c_ast$cast(3016u, l2);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 967u);
    _a0_obj->f_expression = t0;
    l3 = (void*) _a0_obj;
    l2 = vader_emit_c_ast$verbatim(1560u);
    t0 = vader_emit_c_ast$cast(3016u, l2);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 967u);
    _a1_obj->f_expression = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(255u, 2u, 13u, 1918u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3;
    l3 = (void*) _a2_arr;
    l5 = vader_emit_c$find_main(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module, l1);
    if ((l5 < INT32_C(0))) {
        vader_array_t* _a3_arr = vader_array_new(95u, 0u, 13u, 951u);
        l4 = (void*) _a3_arr;
        l2 = vader_emit_c_ast$number(INT64_C(0));
        vader_struct_vader_emit_c_ast$CReturn_t* _a4_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a4_obj, 988u);
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
    l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature)->f_params)->length;
    l6 = t1 == INT64_C(1);
    l2 = vader_emit_c_ast$verbatim(2895u);
    l7 = vader_emit_c_ast$verbatim(932u);
    vader_array_t* _a6_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l7.payload.obj;
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l2.payload.obj;
    l8 = (void*) _a6_arr;
    t0 = vader_emit_c_ast$perform(2897u, l8);
    vader_array_t* _a7_arr = vader_array_new(255u, 1u, 13u, 1918u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0.payload.obj;
    l8 = (void*) _a7_arr;
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_globals)->length;
    if ((t1 > INT64_C(0))) {
        l2 = vader_emit_c_ast$verbatim(2946u);
        t0 = vader_emit_c_ast$verbatim(2950u);
        l7 = vader_emit_c_ast$address_of(t0);
        vader_struct_vader_emit_c_ast$CAssign_t* _a8_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a8_obj, 951u);
        _a8_obj->f_target = l2;
        _a8_obj->f_value = l7;
        _a8_obj->f_operator = vader_box_obj(0u, NULL);
        l9 = (void*) _a8_obj;
        vader_array_push_ref((vader_array_t*) l8, l9);
    }
    t0 = vader_emit_c_ast$verbatim(2899u);
    vader_array_t* _a9_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0.payload.obj;
    l9 = (void*) _a9_arr;
    l2 = vader_emit_c_ast$perform(1610u, l9);
    vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
    t0 = vader_emit_c_ast$verbatim(2945u);
    vader_array_t* _a10_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = t0.payload.obj;
    l9 = (void*) _a10_arr;
    l2 = vader_emit_c_ast$perform(1610u, l9);
    vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
    vader_array_t* _a11_arr = vader_array_new(254u, 0u, 13u, 1914u);
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
            l2 = vader_emit_c$trap(2310u);
            vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
            vader_array_t* _a12_arr = vader_array_new(95u, 0u, 13u, 951u);
            l11 = (void*) _a12_arr;
            l2 = vader_emit_c_ast$number(INT64_C(1));
            vader_struct_vader_emit_c_ast$CReturn_t* _a13_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a13_obj, 988u);
            _a13_obj->f_stores = l11;
            _a13_obj->f_value = l2;
            _a13_obj->f_snapshot_type = 0u;
            _a13_obj->f_pops_frame = false;
            l11 = (void*) _a13_obj;
            vader_array_push_ref((vader_array_t*) l8, l11);
            { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_emit_c_ast$verbatim(1557u);
        l7 = vader_emit_c_ast$verbatim(1560u);
        l12 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l10));
        l13 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l5));
        vader_array_t* _a14_arr = vader_array_new(254u, 4u, 13u, 1914u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 3u] = l13.payload.obj;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 2u] = l12.payload.obj;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 1u] = l7.payload.obj;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = l2.payload.obj;
        l11 = (void*) _a14_arr;
        l2 = vader_emit_c_ast$call(2962u, l11);
        vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a15_slotarr, _a15_slotarr->offset + (size_t) INT32_C(0), 340u);
        if (((int32_t) t0.payload.i) == INT32_C(16)) {
            l7 = vader_emit_c_ast$cast(3017u, l2);
            l7 = vader_emit_c_ast$declaration(3017u, 994u, l7);
            vader_array_push_ref((vader_array_t*) l8, l7.payload.obj);
        } else {
            t0 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l10));
            vader_array_t* _a16_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 1u] = l2.payload.obj;
            ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0.payload.obj;
            l11 = (void*) _a16_arr;
            l2 = vader_emit_c_ast$call(2903u, l11);
            l2 = vader_emit_c_ast$declaration(2905u, 994u, l2);
            vader_array_push_ref((vader_array_t*) l8, l2.payload.obj);
        }
        l2 = vader_emit_c_ast$verbatim(994u);
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
        vader_obj_header_init(_a17_obj, 967u);
        _a17_obj->f_expression = l2;
        l3 = (void*) _a17_obj;
        vader_array_push_ref((vader_array_t*) l8, l3);
        vader_array_t* _a18_arr = vader_array_new(95u, 0u, 13u, 951u);
        l3 = (void*) _a18_arr;
        l7 = vader_emit_c_ast$number(INT64_C(0));
        vader_struct_vader_emit_c_ast$CReturn_t* _a19_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a19_obj, 988u);
        _a19_obj->f_stores = l3;
        _a19_obj->f_value = l7;
        _a19_obj->f_snapshot_type = 0u;
        _a19_obj->f_pops_frame = false;
        l3 = (void*) _a19_obj;
        vader_array_push_ref((vader_array_t*) l8, l3);
        { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a20_arr = vader_array_new(95u, 0u, 13u, 951u);
    l3 = (void*) _a20_arr;
    l2 = vader_emit_c_ast$cast(2176u, l2);
    vader_struct_vader_emit_c_ast$CReturn_t* _a21_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a21_obj, 988u);
    _a21_obj->f_stores = l3;
    _a21_obj->f_value = l2;
    _a21_obj->f_snapshot_type = 0u;
    _a21_obj->f_pops_frame = false;
    l3 = (void*) _a21_obj;
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
    vader_obj_header_init(_a0_obj, 947u);
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
    l3 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t0 = vader_emit_c$entry_needs_materialise(l4, l1);
        if (t0) {
            l5 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
            l6 = vader_emit_c$materialise_entry(l0, l4);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2, l6.payload.obj);
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
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 728u) {
            t0 = l5.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params)->length;
            if ((t1 > l1)) {
                t0 = l5.payload.obj;
                l1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params)->length;
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a8_obj, 462u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a9_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a9_obj, 605u);
    _a9_obj->f_inner = t0;
    l3 = (void*) _a9_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l5 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_is_extern;
        if (t1) {
            l8 = INT64_C(0);
            l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature)->f_param_types)->length;
            while ((l8 < l9)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l5)->f_signature)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
                l10 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l8];
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
    vader_obj_header_init(_a12_obj, 938u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l6 = (void*) _a2_arr;
    l7 = vader_emit_c$push_mirror_allocation(l0, l1, l4, l5, l6, INT32_C(0));
    vader_array_t* _a3_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l8 = (void*) _a3_arr;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l5);
    t0 = ((vader_array_t*) l4)->length;
    if (t0 == INT64_C(1)) {
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
    } else {
        vader_array_t* _a4_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l5 = (void*) _a4_arr;
        l9 = ((vader_array_t*) l4)->length;
        vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l4, (int64_t) INT64_C(1), (int64_t) l9);
        l4 = (void*) _a5_arr;
        l9 = ((vader_array_t*) l4)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l10];
            t2 = t1.payload.s;
            t1 = vader_emit_c_ast$verbatim(t2);
            l11 = vader_emit_c_ast$address_of(t1);
            l12 = vader_emit_c_ast$cast(3018u, l11);
            vader_array_push_ref((vader_array_t*) l5, l12.payload.obj);
            l10 = (l10 + INT64_C(1));
        }
        l11 = vader_emit_c_ast$verbatim(1013u);
        l12 = vader_emit_c_ast$array_declaration(3018u, 1014u, l5);
        vader_array_push_ref((vader_array_t*) l8, l12.payload.obj);
        t0 = ((vader_array_t*) l5)->length;
        l12 = vader_emit_c_ast$number(t0);
        l13 = vader_emit_c_ast$verbatim(1014u);
        vader_array_t* _a7_arr = vader_array_new(254u, 3u, 13u, 1914u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 2u] = l12.payload.obj;
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 1u] = l13.payload.obj;
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l11.payload.obj;
        l4 = (void*) _a7_arr;
        l12 = vader_emit_c_ast$perform(934u, l4);
        vader_array_push_ref((vader_array_t*) l8, l12.payload.obj);
        vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l6);
        vader_array_t* _a8_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l11.payload.obj;
        l4 = (void*) _a8_arr;
        l11 = vader_emit_c_ast$perform(933u, l4);
        vader_array_push_ref((vader_array_t*) l8, l11.payload.obj);
    }
    l4 = vader_emit_c$bc_struct_fields(l0, l1);
    l11 = vader_emit_c_ast$verbatim(2487u);
    l12 = vader_emit_c_ast$verbatim(l7);
    vader_emit_c$push_member_copies(l0, l4, l11, l12, false, l8, INT32_C(0));
    l11 = vader_emit_c_ast$declaration(l2, 2487u, l3);
    l12 = vader_emit_c_ast$verbatim(l7);
    vader_struct_vader_emit_c$ForwardedResult_t* _a9_obj = (vader_struct_vader_emit_c$ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ForwardedResult_t));
    vader_obj_header_init(_a9_obj, 937u);
    _a9_obj->f_capture = l11;
    _a9_obj->f_returns = false;
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
        l4 = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_internal_fns)->length;
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_internal_fns);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
        t1 = t0;
        if (t1) {
            return (uint8_t) 0;
        }
        return (uint8_t) 1;
    }
    return (uint8_t) 1;
}

static vader_string_t vader_emit_c$module_stem_of(vader_string_t l0) {
    int64_t l1;
    vader_string_t t0;
    l1 = std_string$index_of(l0, 36u, INT64_C(0));
    if (!((l1 < INT64_C(0)))) {
        t0 = vader_host_std_core$byte_slice(l0, INT64_C(0), l1);
        return t0;
    }
    return 0u;
}

static bool vader_emit_c$needs_frame(void* l0, int32_t l1, void* l2) {
    void* l3;
    void* l4;
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_may_alloc);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
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
    l6 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types)->length;
    vader_struct___lambda_env_vader_emit_c_2_t* _a0_obj = (vader_struct___lambda_env_vader_emit_c_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_2_t));
    vader_obj_header_init(_a0_obj, 368u);
    _a0_obj->f_cap_0 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 309u);
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
    vader_obj_header_init(_a2_obj, 934u);
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
    vader_array_t* _a0_arr = vader_array_new(255u, 0u, 13u, 1918u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 953u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(253u, 0u, 13u, 1913u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(102u, 0u, 13u, 998u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(93u, 0u, 13u, 941u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a6_arr;
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_may_alloc);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l1)
    t1 = ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l1];
    t2 = t1;
    if (!(t2)) {
        l10 = !(l3);
    } else {
        l10 = false;
    }
    vader_array_t* _a8_arr = vader_array_new(92u, 0u, 13u, 940u);
    l11 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(91u, 0u, 13u, 930u);
    l12 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(94u, 0u, 13u, 946u);
    l13 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(258u, 0u, 13u, 1928u);
    l14 = (void*) _a11_arr;
    vader_struct_vader_emit_c$FnState_t* _a12_obj = (vader_struct_vader_emit_c$FnState_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$FnState_t));
    vader_obj_header_init(_a12_obj, 935u);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_temporaries)->length;
    vader_struct_vader_emit_c_ast$CTemporary_t* _a0_obj = (vader_struct_vader_emit_c_ast$CTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CTemporary_t));
    vader_obj_header_init(_a0_obj, 998u);
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
    l2 = concat_2(l0, 349u);
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
    t0 = (void*) &vader_data_53;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_emit_c_ast$binary((uint8_t) 11, l0, vader_ref_box(l2));
    vader_array_t* _a1_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l2 = (void*) _a1_arr;
    l4 = vader_emit_c_ast$call(2902u, l2);
    vader_struct_vader_emit_c_ast$CConditional_t* _a2_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
    vader_obj_header_init(_a2_obj, 960u);
    _a2_obj->f_condition = l3;
    _a2_obj->f_then_value = l4;
    _a2_obj->f_else_value = l1;
    t0 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$object_header(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_52;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_52;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_52;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_53;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l4 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(254u, 5u, 13u, 1914u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 4u] = l4;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 3u] = l3;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l2;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l1;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l0.payload.obj;
    t0 = (void*) _a4_arr;
    t1 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$object_pointer(vader_box_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(16)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_emit_c$payload(l0, 2418u);
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
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l3.tag == 734u) {
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
    if (l3.tag == 735u) {
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
    if (l0.tag == 868u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        l2 = !(t1);
        return l2;
    }
    if (l0.tag == 761u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        l2 = t1;
    } else if ((l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 721u || l0.tag == 723u || l0.tag == 755u || l0.tag == 756u || l0.tag == 762u || l0.tag == 788u || l0.tag == 846u || l0.tag == 887u)) {
        l2 = true;
    } else if ((l0.tag == 790u || l0.tag == 791u)) {
        l2 = false;
    } else {
        if (!((l0.tag == 713u || l0.tag == 714u || l0.tag == 715u || l0.tag == 716u || l0.tag == 720u || l0.tag == 722u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 750u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 754u || l0.tag == 757u || l0.tag == 760u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 766u || l0.tag == 767u || l0.tag == 769u || l0.tag == 770u || l0.tag == 771u || l0.tag == 772u || l0.tag == 773u || l0.tag == 774u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 783u || l0.tag == 784u || l0.tag == 785u || l0.tag == 786u || l0.tag == 787u || l0.tag == 789u || l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 803u || l0.tag == 804u || l0.tag == 805u || l0.tag == 806u || l0.tag == 807u || l0.tag == 808u || l0.tag == 809u || l0.tag == 810u || l0.tag == 811u || l0.tag == 812u || l0.tag == 813u || l0.tag == 814u || l0.tag == 815u || l0.tag == 816u || l0.tag == 817u || l0.tag == 818u || l0.tag == 819u || l0.tag == 820u || l0.tag == 821u || l0.tag == 822u || l0.tag == 823u || l0.tag == 824u || l0.tag == 825u || l0.tag == 826u || l0.tag == 827u || l0.tag == 828u || l0.tag == 829u || l0.tag == 830u || l0.tag == 831u || l0.tag == 832u || l0.tag == 834u || l0.tag == 835u || l0.tag == 836u || l0.tag == 837u || l0.tag == 838u || l0.tag == 839u || l0.tag == 840u || l0.tag == 841u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 845u || l0.tag == 847u || l0.tag == 848u || l0.tag == 849u || l0.tag == 850u || l0.tag == 851u || l0.tag == 852u || l0.tag == 853u || l0.tag == 854u || l0.tag == 855u || l0.tag == 856u || l0.tag == 857u || l0.tag == 858u || l0.tag == 859u || l0.tag == 860u || l0.tag == 861u || l0.tag == 862u || l0.tag == 863u || l0.tag == 864u || l0.tag == 865u || l0.tag == 866u || l0.tag == 867u || l0.tag == 869u || l0.tag == 870u || l0.tag == 871u || l0.tag == 872u || l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 877u || l0.tag == 878u || l0.tag == 879u || l0.tag == 880u || l0.tag == 881u || l0.tag == 882u || l0.tag == 883u || l0.tag == 884u || l0.tag == 885u || l0.tag == 886u))) {
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_open_nodes)->length;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l3.tag == 974u)) {
        vader_host_std_abort$panic(1698u);
        vader_unreachable("a no-return call returned");
    }
    l1 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(255u, 0u, 13u, 1918u);
    t1 = (void*) _a1_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a2_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a2_obj, 953u);
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
    vader_array_t* _a0_arr = vader_array_new(255u, 0u, 13u, 1918u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 953u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CIf_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIf_t));
    vader_obj_header_init(_a2_obj, 974u);
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
    vader_array_t* _a0_arr = vader_array_new(255u, 0u, 13u, 1918u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 953u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CScope_t* _a2_obj = (vader_struct_vader_emit_c_ast$CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CScope_t));
    vader_obj_header_init(_a2_obj, 989u);
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
    l2 = std_core$write_string_at(l1, l2, 1012u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 534u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = vader_emit_c$sorted_fn_indices(l0);
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l6 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l7 = vader_emit_c$module_stem_of(t1);
        l3 = (void*) &vader_fn_static___lambda_vader_emit_c_0;
        t0 = std_collections$get_or_put_with__string__i32__(l1, l7, l3);
        vader_array_push_i32((vader_array_t*) t0, l6);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    t0 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(3u, 1u, 13u, 22u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
    l2 = (void*) _a7_arr;
    l3 = vader_emit_c$sorted_module_stems(l1);
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t2 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l5];
        l7 = t2.payload.s;
        l8 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l7);
        if (l8.tag == 0u) {
            vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
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
    l2 = concat_2(2464u, l1);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 981u);
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
    vader_obj_header_init(_a0_obj, 985u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$pc_active_for(void* l0, int32_t l1) {
    int64_t l2;
    void* l3;
    int32_t t0;
    l2 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches)->length;
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t0 = ((vader_struct_vader_emit_c$PushCache_t*) l3)->f_slot;
    if (!(t0 != l1)) {
        return vader_ref_box(l3);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_c$pc_capacity(int32_t l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t0 };
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_emit_c$pc_header(l0, 2421u);
    l2 = vader_emit_c_ast$verbatim(450u);
    l1 = vader_emit_c_ast$binary((uint8_t) 11, l1, l2);
    l2 = vader_emit_c_ast$verbatim(244u);
    t0 = vader_emit_c$pc_local(l0, 2078u);
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l3 = (void*) _a0_arr;
    l4 = vader_emit_c_ast$call(2868u, l3);
    vader_array_t* _a1_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l2.payload.obj;
    t1 = (void*) _a1_arr;
    vader_struct_vader_emit_c_ast$CSequence_t* _a2_obj = (vader_struct_vader_emit_c_ast$CSequence_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSequence_t));
    vader_obj_header_init(_a2_obj, 991u);
    _a2_obj->f_parts = t1;
    l3 = (void*) _a2_obj;
    l2 = vader_emit_c$pc_header(l0, 2273u);
    l4 = vader_emit_c$pc_header(l0, 1655u);
    l2 = vader_emit_c_ast$binary((uint8_t) 10, l2, l4);
    l1 = vader_emit_c_ast$binary((uint8_t) 16, l1, vader_ref_box(l3));
    t0 = vader_emit_c_ast$binary((uint8_t) 16, l1, l2);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a3_obj, 985u);
    _a3_obj->f_inner = t0;
    l3 = (void*) _a3_obj;
    l1 = vader_emit_c$pc_header(l0, 1743u);
    l2 = vader_emit_c_ast$verbatim(450u);
    l2 = vader_emit_c_ast$cast(2567u, l2);
    vader_struct_vader_emit_c_ast$CConditional_t* _a4_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
    vader_obj_header_init(_a4_obj, 960u);
    _a4_obj->f_condition = vader_ref_box(l3);
    _a4_obj->f_then_value = l1;
    _a4_obj->f_else_value = l2;
    t1 = (void*) _a4_obj;
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
    l2 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches)->length;
    if (l2 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_push_caches;
    l2 = vader_chk_sub(i64, l2, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
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
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c$PushCache_t*) l1)->f_opener_pc;
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1030u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1027u);
    l6 = std_core$finish_buffer(l3, l4);
    t0 = ((vader_struct_vader_emit_c$PushCache_t*) l1)->f_slot;
    vader_struct_vader_emit_c_ast$CLocal_t* _a0_obj = (vader_struct_vader_emit_c_ast$CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CLocal_t));
    vader_obj_header_init(_a0_obj, 979u);
    _a0_obj->f_slot = t0;
    t1 = (void*) _a0_obj;
    l7 = vader_emit_c$array_pointer(vader_ref_box(t1));
    vader_emit_c$declare(l0, 2893u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1030u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1028u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_header(l2, 2273u);
    vader_emit_c$declare(l0, 2567u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(27));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1030u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1021u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_capacity(l2);
    vader_emit_c$declare(l0, 2567u, l6, l7);
    l3 = (void*) vader_buffer_new((size_t) INT64_C(29));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l3, l4, 1030u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 1032u);
    l6 = std_core$finish_buffer(l3, l4);
    l7 = vader_emit_c$pc_header(l2, 1656u);
    vader_emit_c$declare(l0, 3017u, l6, l7);
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
    l5 = vader_emit_c$pc_local(l4, 2272u);
    l6 = vader_emit_c$pc_local(l4, 1741u);
    t0 = vader_emit_c_ast$binary((uint8_t) 7, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l7 = (void*) _a0_arr;
    l5 = vader_emit_c_ast$call(936u, l7);
    vader_emit_c$open_if(l0, l5);
    t1 = vader_emit_c$pc_fill_of(((vader_struct_vader_emit_c$PushCache_t*) l1)->f_kind);
    l8 = ((vader_struct_vader_emit_c$SlotFill_t*) t1)->f_cty;
    l9 = concat_2(l8, 349u);
    l5 = vader_emit_c$pc_local(l4, 2576u);
    t0 = vader_emit_c_ast$cast(l9, l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a1_obj, 985u);
    _a1_obj->f_inner = t0;
    l7 = (void*) _a1_obj;
    l5 = vader_emit_c$pc_local(l4, 2272u);
    vader_struct_vader_emit_c_ast$CIndex_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a2_obj, 976u);
    _a2_obj->f_base = vader_ref_box(l7);
    _a2_obj->f_index = l5;
    l7 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a3_obj, 985u);
    _a3_obj->f_inner = l3;
    l10 = (void*) _a3_obj;
    l5 = vader_emit_c_ast$cast(l8, vader_ref_box(l10));
    vader_emit_c$assign(l0, vader_ref_box(l7), l5);
    l5 = vader_emit_c$pc_local(l4, 2272u);
    l6 = vader_emit_c_ast$verbatim(455u);
    vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
    vader_obj_header_init(_a4_obj, 951u);
    _a4_obj->f_target = l5;
    _a4_obj->f_value = l6;
    _a4_obj->f_operator = vader_box_i32(340u, INT32_C(3));
    l7 = (void*) _a4_obj;
    vader_emit_c$append_statement(l0, vader_ref_box(l7));
    vader_emit_c$open_else(l0);
    vader_emit_c$pc_emit_writeback(l0, l4);
    l8 = vader_emit_c$pc_helper_of(((vader_struct_vader_emit_c$PushCache_t*) l1)->f_kind);
    t0 = vader_emit_c$array_pointer(l2);
    vader_array_t* _a5_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0.payload.obj;
    l7 = (void*) _a5_arr;
    l5 = vader_emit_c_ast$call(l8, l7);
    vader_emit_c$evaluate(l0, l5);
    l5 = vader_emit_c$pc_local(l4, 2078u);
    l6 = vader_emit_c$array_pointer(l2);
    vader_emit_c$assign(l0, l5, l6);
    vader_emit_c$pc_reload(l0, l4);
    vader_emit_c$close_node(l0, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$pc_emit_writeback(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pc_header(l1, 2273u);
    l3 = vader_emit_c$pc_local(l1, 2272u);
    vader_emit_c$assign(l0, l2, l3);
    l2 = vader_emit_c$pc_header(l1, 1655u);
    l3 = vader_emit_c$pc_local(l1, 2272u);
    l2 = vader_emit_c_ast$binary((uint8_t) 7, l2, l3);
    vader_emit_c$open_if(l0, l2);
    l2 = vader_emit_c$pc_header(l1, 1655u);
    l3 = vader_emit_c$pc_local(l1, 2272u);
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
        vader_obj_header_init(_a0_obj, 942u);
        _a0_obj->f_cty = 2178u;
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
    t0 = vader_emit_c$pc_local(l0, 2078u);
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 981u);
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
        return 2877u;
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
    l3 = vader_host_std_core$byte_len(l2);
    l4 = (void*) vader_buffer_new((size_t) (INT64_C(24) + l3));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l4, l3, 1030u);
    l5 = ((int64_t) (int32_t) l0);
    l3 = std_core$write_int(l4, l3, l5);
    l3 = std_core$write_string_at(l4, l3, 977u);
    l3 = std_core$write_string_at(l4, l3, l2);
    t0 = std_core$finish_buffer(l4, l3);
    t1 = vader_emit_c_ast$verbatim(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$pc_operand_is_slot(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 945u)) {
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
            l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            if (l3.tag == 845u) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 718u) {
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
                l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
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
            if ((l3.tag == 853u || l3.tag == 854u)) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            {
                if ((l3.tag == 753u || l3.tag == 754u)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_function)->f_jump_table);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                    l15 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
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
            if (l3.tag == 760u) {
                l19 = ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_may_alloc;
                t0 = l3.payload.obj;
                l20 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l19);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l20)
                t2 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l20];
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
    l21 = ((vader_array_t*) l9)->length;
    l22 = INT64_C(0);
    while ((l22 < l21)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l22);
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
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$pc_local(l1, 2272u);
    l3 = vader_emit_c$pc_header(l1, 2273u);
    vader_emit_c$assign(l0, l2, l3);
    l2 = vader_emit_c$pc_local(l1, 1741u);
    l3 = vader_emit_c$pc_capacity(l1);
    vader_emit_c$assign(l0, l2, l3);
    l2 = vader_emit_c$pc_local(l1, 2576u);
    l3 = vader_emit_c$pc_header(l1, 1656u);
    vader_emit_c$assign(l0, l2, l3);
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
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 843u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            if (t1 == l3) {
                return true;
            }
        }
        if (l7.tag == 844u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            if (t1 == l3) {
                return true;
            }
        }
        if (l7.tag == 842u) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            if (t1 == l3) {
                l5 = vader_chk_add(i32, l5, INT32_C(1));
            }
        }
        if (l7.tag == 841u) {
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

static vader_string_t vader_emit_c$pointer_to(vader_string_t l0, bool l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1) {
        t0 = concat_2(l0, 349u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_3(1798u, l0, 349u);
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
    l1 = ((vader_array_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack)->length;
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
        l3 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l2 = ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack;
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(0), (int64_t) l1);
        l2 = (void*) _a1_arr;
        ((vader_struct_vader_emit_c$FnState_t*) l0)->f_stack = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_emit_c$FnState_t*) l0);
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_emit_c_ast$verbatim(450u);
    vader_struct_vader_emit_c$StackLit_t* _a2_obj = (vader_struct_vader_emit_c$StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$StackLit_t));
    vader_obj_header_init(_a2_obj, 944u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
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
        vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6, l7.payload.obj);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l4)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l8.tag == 753u) {
            l9 = true;
        } else {
            l9 = l8.tag == 754u;
        }
        if (l9) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
            l11 = vader_emit_c$branch_target(l1, l10);
            if (l11.tag == 941u) {
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
    vader_obj_header_init(_a4_obj, 931u);
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
    vader_array_t* _a0_arr = vader_array_new(93u, 0u, 13u, 941u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 1u, 340u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l4)->length;
    while ((l5 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if (l7.tag == 746u) {
            l8 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l8);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
        } else if (l7.tag == 845u) {
            l9 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l9);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(1));
        } else if (l7.tag == 832u) {
            l10 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(2));
        } else if (l7.tag == 773u) {
            l11 = ((vader_array_t*) l2)->length;
            if ((l11 > INT64_C(0))) {
                l12 = vader_chk_sub(i64, l11, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l13 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                l14 = vader_chk_sub(i64, l11, INT64_C(1));
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l14, 340u);
                l15 = ((uint8_t) t0.payload.i);
                l16 = ((int32_t) (int64_t) l5);
                vader_struct_vader_emit_c$ScopeInfo_t* _a6_obj = (vader_struct_vader_emit_c$ScopeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$ScopeInfo_t));
                vader_obj_header_init(_a6_obj, 941u);
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
            vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l6.payload.obj;
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
            l7 = (void*) _a0_arr;
            l5 = vader_emit_c_ast$call(2901u, l7);
            if (l1 == INT32_C(11)) {
                l6 = l5;
                vader_emit_c$push_expr(l0, l2, l6);
                { vader_gc_top = gc_frame.prev; return; }
            }
            vader_struct_vader_emit_c_ast$CUnary_t* _a1_obj = (vader_struct_vader_emit_c_ast$CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CUnary_t));
            vader_obj_header_init(_a1_obj, 999u);
            _a1_obj->f_operator = 244u;
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
    vader_string_t l5 = 0;
    void* l6 = NULL;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l7, &l8, &l9, &t1 };
    void** gc_raw_roots[3] = { &l2, &l3, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c$c_type_for_val_bare(l1);
    l5 = concat_3(l0, 14u, l4);
    t0 = std_core$$array$Contains$contains__string(l2, l5);
    if (!(t0)) {
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l5));
        t1 = vader_emit_c_ast$verbatim(l0);
        vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
        l6 = (void*) _a0_arr;
        l7 = vader_emit_c_ast$call(2568u, l6);
        t1 = vader_emit_c_ast$verbatim(l4);
        vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
        l6 = (void*) _a1_arr;
        l8 = vader_emit_c_ast$call(2568u, l6);
        l7 = vader_emit_c_ast$binary((uint8_t) 11, l7, l8);
        l8 = vader_emit_c_ast$verbatim(453u);
        l8 = vader_emit_c_ast$cast(l0, l8);
        l9 = vader_emit_c_ast$number(INT64_C(0));
        l8 = vader_emit_c_ast$binary((uint8_t) 11, l8, l9);
        l4 = concat_4(540u, l0, 333u, l4);
        t1 = vader_emit_c_ast$binary((uint8_t) 16, l7, l8);
        l7 = vader_emit_c$static_assert(t1, l4);
        vader_array_push_ref((vader_array_t*) l3, l7.payload.obj);
        { vader_gc_top = gc_frame.prev; return; }
    }
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
    vader_array_t* _a0_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
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
    vader_obj_header_init(_a0_obj, 943u);
    _a0_obj->f_expression = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
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
        l1 = vader_box_string(335u, 2877u);
        return l1;
    }
    if (l0 == INT32_C(8)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l1 = vader_box_string(335u, 2878u);
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_string(335u, 2875u);
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_string(335u, 2874u);
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_string(335u, 2883u);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_string(335u, 2879u);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_string(335u, 2882u);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_string(335u, 2876u);
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_string(335u, 2873u);
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
    if (l1.tag == 978u) {
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
    vader_obj_header_init(_a0_obj, 999u);
    _a0_obj->f_operator = 383u;
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
    l10 = ((vader_array_t*) l1)->length;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l12 = vader_emit_c$c_field_name(l11);
        l13 = concat_2(l3, l12);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$CLayout_t*) l8)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l14 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
        l15 = vader_chk_add(i64, l5, l14);
        l16 = vader_core_bytecode$nested_mirror(l11, l0);
        if (l16.tag == 0u) {
            t0 = vader_emit_c$null_member(l2, l13);
            vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0.payload.obj;
            l21 = (void*) _a2_arr;
            l22 = vader_emit_c_ast$call(2568u, l21);
            l23 = ((vader_struct_vader_core_bytecode$BcField_t*) l11)->f_name;
            l24 = concat_2(1976u, l23);
            t0 = vader_emit_c$null_member(l4, l24);
            vader_array_t* _a3_arr = vader_array_new(254u, 1u, 13u, 1914u);
            ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0.payload.obj;
            l25 = (void*) _a3_arr;
            l26 = vader_emit_c_ast$call(2568u, l25);
            l27 = vader_emit_c_ast$binary((uint8_t) 11, l22, l26);
            l28 = concat_3(l2, 397u, l13);
            l29 = vader_emit_c$static_assert(l27, l28);
            vader_array_push_ref((vader_array_t*) l6, l29.payload.obj);
            l30 = vader_emit_c_ast$verbatim(l2);
            l31 = vader_emit_c_ast$verbatim(l13);
            vader_array_t* _a4_arr = vader_array_new(254u, 2u, 13u, 1914u);
            ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l31.payload.obj;
            ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l30.payload.obj;
            l32 = (void*) _a4_arr;
            l33 = vader_emit_c_ast$call(999u, l32);
            l34 = vader_emit_c_ast$number(l15);
            l35 = vader_emit_c_ast$binary((uint8_t) 11, l33, l34);
            l36 = concat_4(l2, 397u, l13, 186u);
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
        l18 = concat_2(l13, 397u);
        t1 = l16.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_name;
        l19 = vader_emit_c$struct_c_name(t2);
        l20 = vader_chk_add(i32, l7, INT32_C(1));
        vader_emit_c$push_leaf_asserts(l0, l17, l2, l18, l19, l15, l6, l20);
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_library_units(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c$foreign_libraries(((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module);
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        l7 = vader_emit_c$library_unit_name(l6);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(335u, l7));
        l8 = vader_emit_c$emit_library_unit(l0, l6);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l8));
        l5 = (l5 + INT64_C(1));
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
    vader_obj_header_init(_a0_obj, 944u);
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
    vader_obj_header_init(_a0_obj, 945u);
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
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l11 = vader_emit_c$c_field_name(l10);
        vader_struct_vader_emit_c_ast$CMember_t* _a1_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a1_obj, 981u);
        _a1_obj->f_base = l2;
        _a1_obj->f_member = l11;
        _a1_obj->f_arrow = false;
        l12 = (void*) _a1_obj;
        l13 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
        l14 = concat_2(1976u, l13);
        vader_struct_vader_emit_c_ast$CMember_t* _a2_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
        vader_obj_header_init(_a2_obj, 981u);
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
            vader_obj_header_init(_a3_obj, 958u);
            _a3_obj->f_model = vader_ref_box(l20);
            _a3_obj->f_value = vader_ref_box(l21);
            l22 = (void*) _a3_obj;
            vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
            vader_obj_header_init(_a4_obj, 951u);
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
        t1 = concat_2(t2, 349u);
        t3 = vader_emit_c_ast$cast(t1, vader_ref_box(l15));
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a5_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a5_obj, 985u);
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
    l8 = std_core$write_string_at(l7, l8, 2418u);
    l9 = ((vader_array_t*) l2)->length;
    l8 = std_core$write_int(l7, l8, l9);
    l6 = std_core$finish_buffer(l7, l8);
    vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l6));
    t0 = vader_emit_c$bc_struct_name(l0, l1);
    l10 = vader_emit_c$struct_c_name(t0);
    l11 = concat_2(l10, 349u);
    t1 = (void*) &vader_data_53;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l12 = vader_emit_c_ast$declaration(l11, l6, vader_ref_box(l7));
    vader_array_push_ref((vader_array_t*) l3, l12.payload.obj);
    vader_array_t* _a1_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l7 = (void*) _a1_arr;
    l13 = vader_emit_c$bc_struct_fields(l0, l1);
    l8 = ((vader_array_t*) l13)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l14 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
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
                vader_obj_header_init(_a3_obj, 981u);
                _a3_obj->f_base = l12;
                _a3_obj->f_member = l17;
                _a3_obj->f_arrow = true;
                l18 = (void*) _a3_obj;
                l19 = vader_emit_c_ast$verbatim(l11);
                vader_struct_vader_emit_c_ast$CAssign_t* _a4_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
                vader_obj_header_init(_a4_obj, 951u);
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
    vader_obj_header_init(_a5_obj, 951u);
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
    l8 = std_core$write_string_at(l13, l8, 2780u);
    t0 = std_core$finish_buffer(l13, l8);
    l19 = vader_emit_c_ast$verbatim(t0);
    vader_array_t* _a6_arr = vader_array_new(254u, 2u, 13u, 1914u);
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l19.payload.obj;
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l12.payload.obj;
    l13 = (void*) _a6_arr;
    l12 = vader_emit_c_ast$perform(2953u, l13);
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
    l2 = vader_emit_c_ast$cast(3017u, l1);
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
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l2;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        t2 = t1.payload.s;
        l7 = __lambda_vader_emit_c_13(t2);
        vader_array_push_ref((vader_array_t*) l4, l7.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    l3 = l4;
    l8 = concat_3(397u, l1, 1029u);
    vader_struct_vader_emit_c_ast$CCompoundLiteral_t* _a3_obj = (vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCompoundLiteral_t));
    vader_obj_header_init(_a3_obj, 959u);
    _a3_obj->f_type = 1800u;
    _a3_obj->f_elements = l3;
    l3 = (void*) _a3_obj;
    l7 = vader_emit_c_ast$designated(l8, vader_ref_box(l3));
    vader_array_push_ref((vader_array_t*) l0, l7.payload.obj);
    l8 = concat_3(397u, l1, 1022u);
    t0 = ((vader_array_t*) l2)->length;
    l7 = vader_emit_c_ast$number(t0);
    l7 = vader_emit_c_ast$designated(l8, l7);
    vader_array_push_ref((vader_array_t*) l0, l7.payload.obj);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c$push_pool_array(void* l0, void* l1, vader_string_t l2, uint8_t l3, void* l4) {
    int64_t l5, l10, l11;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    uint8_t l7;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    vader_box_t l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[8] = { &l13, &l14, &l15, &l16, &l17, &l20, &l21, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l12, &l18, &l19, &t3 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l6, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_array_t*) l4)->length;
    t0 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_name;
    l6 = concat_2(t0, 1020u);
    l7 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_storage;
    l8 = 2955u;
    l9 = l2;
    l10 = vader_host_std_core$byte_len(l8);
    l11 = vader_host_std_core$byte_len(l9);
    l10 = (l10 + l11);
    l12 = (void*) vader_buffer_new((size_t) (INT64_C(41) + l10));
    l10 = INT64_C(0);
    l10 = std_core$write_string_at(l12, l10, 2668u);
    l10 = std_core$write_string_at(l12, l10, l8);
    l10 = std_core$write_string_at(l12, l10, 14u);
    l10 = std_core$write_string_at(l12, l10, l9);
    l10 = std_core$write_string_at(l12, l10, 213u);
    l10 = std_core$write_int(l12, l10, l5);
    l10 = std_core$write_string_at(l12, l10, 975u);
    l8 = std_core$finish_buffer(l12, l10);
    t1 = vader_emit_c_ast$verbatim(938u);
    l13 = vader_emit_c$object_header(t1);
    l14 = vader_emit_c_ast$unsigned(l5);
    l15 = vader_emit_c_ast$unsigned(l5);
    t2 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_element_tag;
    l16 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
    t2 = vader_core_bytecode$array_kind_index(l3);
    l17 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
    t3 = (void*) &vader_data_52;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l12 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t3 = (void*) &vader_data_52;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l18 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t3 = (void*) &vader_data_52;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l19 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a3_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 2u] = l19;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l18;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l12;
    t3 = (void*) _a3_arr;
    l20 = vader_emit_c_ast$initializer_list(t3);
    l21 = vader_emit_c_ast$initializer_list(l4);
    vader_array_t* _a4_arr = vader_array_new(254u, 7u, 13u, 1914u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 6u] = l21.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 5u] = l20.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 4u] = l17.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 3u] = l16.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l15.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l14.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l13.payload.obj;
    t3 = (void*) _a4_arr;
    l13 = vader_emit_c_ast$initializer_list(t3);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a5_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a5_obj, 963u);
    _a5_obj->f_name = l6;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l13;
    l12 = (void*) _a5_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a6_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a6_obj, 972u);
    _a6_obj->f_storage = l7;
    _a6_obj->f_constant = true;
    _a6_obj->f_type = l8;
    _a6_obj->f_declarator = l12;
    l12 = (void*) _a6_obj;
    vader_array_push_ref((vader_array_t*) l0, l12);
    l7 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_storage;
    l8 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_name;
    t2 = ((vader_struct_vader_emit_c$PoolArray_t*) l1)->f_type_id;
    t1 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) t2));
    l13 = vader_emit_c$object_header(t1);
    l14 = vader_emit_c_ast$unsigned(l5);
    l15 = vader_emit_c_ast$unsigned(l5);
    t3 = (void*) &vader_data_52;
    vader_array_t* _a7_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    l12 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_emit_c_ast$verbatim(l6);
    l16 = vader_emit_c_ast$address_of(t1);
    l16 = vader_emit_c_ast$cast(2864u, l16);
    vader_array_t* _a8_arr = vader_array_new(254u, 5u, 13u, 1914u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 4u] = l16.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 3u] = l12;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 2u] = l15.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l14.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l13.payload.obj;
    t3 = (void*) _a8_arr;
    l13 = vader_emit_c_ast$initializer_list(t3);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a9_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a9_obj, 963u);
    _a9_obj->f_name = l8;
    _a9_obj->f_length = vader_box_obj(0u, NULL);
    _a9_obj->f_value = l13;
    l12 = (void*) _a9_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a10_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a10_obj, 972u);
    _a10_obj->f_storage = l7;
    _a10_obj->f_constant = true;
    _a10_obj->f_type = 2892u;
    _a10_obj->f_declarator = l12;
    l12 = (void*) _a10_obj;
    vader_array_push_ref((vader_array_t*) l0, l12);
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
    vader_obj_header_init(_a0_obj, 985u);
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
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l6.tag == 738u)) {
        l8 = (void*) vader_buffer_new((size_t) INT64_C(59));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l8, l14, 2660u);
        l15 = ((int64_t) (int32_t) l1);
        l14 = std_core$write_int(l8, l14, l15);
        t0 = std_core$finish_buffer(l8, l14);
        std_abort$todo(t0);
        vader_unreachable("a no-return call returned");
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
    l7 = t1.payload.s;
    t2 = l6.payload.obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t2)->f_fields);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
    l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
    l10 = vader_emit_c$val_type_of_field(l5, l9);
    l6 = vader_emit_c$object_pointer(l3, l4);
    l11 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_name;
    l12 = vader_emit_c$field_of(l7, l6, l11);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_layout_siblings);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
    l5 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l1);
    t3 = ((vader_array_t*) l5)->length;
    if (t3 == INT64_C(0)) {
        vader_emit_c$push_expr(l0, l10, l12);
    } else {
        l13 = vader_emit_c$tag_expression(l3, l4);
        l14 = INT64_C(0);
        l15 = ((vader_array_t*) l5)->length;
        while ((l14 < l15)) {
            t3 = ((vader_array_t*) l5)->length;
            t4 = vader_chk_sub(i64, t3, INT64_C(1));
            l16 = vader_chk_sub(i64, t4, l14);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l16)
            l9 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l16];
            l17 = vader_emit_c$erased_sibling_field_read(l0, l9, l2, l10, l6);
            t1 = vader_emit_c$tag_equals(l13, l9);
            vader_struct_vader_emit_c_ast$CConditional_t* _a5_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
            vader_obj_header_init(_a5_obj, 960u);
            _a5_obj->f_condition = t1;
            _a5_obj->f_then_value = l17;
            _a5_obj->f_else_value = l12;
            t2 = (void*) _a5_obj;
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a6_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a6_obj, 985u);
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
    vader_obj_header_init(_a0_obj, 947u);
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
    vader_obj_header_init(_a0_obj, 999u);
    _a0_obj->f_operator = l1;
    _a0_obj->f_operand = l3;
    l4 = (void*) _a0_obj;
    vader_emit_c$push_expr(l0, l2, vader_ref_box(l4));
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_emit_c_ast$call(2961u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c$ref_carrying_element(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if ((l0.tag == 725u || l0.tag == 728u || l0.tag == 734u || l0.tag == 738u)) {
        return true;
    }
    if (!(l0.tag == 739u)) {
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
    vader_obj_header_init(_a0_obj, 988u);
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
    l2 = ((vader_array_t*) l0)->length;
    if (l1 == l2) {
        return true;
    }
    t0 = ((vader_array_t*) l0)->length;
    l2 = vader_chk_sub(i64, t0, INT64_C(1));
    if (l1 == l2) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return (t1.tag == 853u || t1.tag == 854u);
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
    t0 = ((vader_array_t*) l3)->length;
    if (!(t0 == INT64_C(0))) {
        t1 = (void*) &vader_data_51;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        l5 = vader_emit_c_ast$initializer_list(l3);
        vader_struct_vader_emit_c_ast$CDeclarator_t* _a1_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
        vader_obj_header_init(_a1_obj, 963u);
        _a1_obj->f_name = l2;
        _a1_obj->f_length = vader_ref_box(l4);
        _a1_obj->f_value = l5;
        l4 = (void*) _a1_obj;
        vader_struct_vader_emit_c_ast$CGlobal_t* _a2_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
        vader_obj_header_init(_a2_obj, 972u);
        _a2_obj->f_storage = (uint8_t) 0;
        _a2_obj->f_constant = false;
        _a2_obj->f_type = l1;
        _a2_obj->f_declarator = l4;
        l4 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l0, l4);
        t2 = vader_emit_c_ast$verbatim(l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_53;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$safepoint_result_arity(void* l0, vader_box_t l1, int64_t l2) {
    int32_t l3;
    void* l4;
    int64_t l5;
    void* t0;
    int64_t t1;
    if (l1.tag == 718u) {
        if (!(l2 != INT64_C(2))) {
            return vader_box_i64(339u, INT64_C(0));
        }
        return vader_box_obj(0u, NULL);
    }
    if (!(l1.tag == 760u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature;
    l5 = vader_core_bytecode$bc_result_arity(l4);
    t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l4)->f_params)->length;
    if (t1 != l2) {
        return vader_box_obj(0u, NULL);
    }
    if (!((l5 > INT64_C(1)))) {
        return vader_box_i64(339u, l5);
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
    l2 = vader_host_std_core$byte_len(l0);
    while ((l1 < l2)) {
        l3 = vader_host_std_core$byte_at(l0, l1);
        t0 = vader_support_text$is_ident_byte(l3);
        if (!(t0)) {
            if (l3 != INT32_C(36)) {
                t1 = concat_3(1705u, l0, 1124u);
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
    t1 = concat_2(l0, 258u);
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
    if (l0.tag == 978u) {
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
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 735u) {
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
    int64_t l1, l3, l8, l9;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    bool l5;
    vader_box_t l10 = vader_box_null();
    int32_t l11, l12, l13;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a2_arr;
    if ((INT64_C(0) < l1)) {
        l3 = l1;
    } else {
        l3 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l3);
    l4 = (void*) _a3_arr;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        vader_array_push_bool((vader_array_t*) l4, false);
        l3 = (l3 + INT64_C(1));
    }
    l5 = false;
    l6 = l0;
    l1 = ((vader_array_t*) l6)->length;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
        l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
            if (l10.tag == 789u) {
                t0 = l10.payload.obj;
                l11 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
                t0 = l10.payload.obj;
                l12 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11] = (int32_t) l12;
                l5 = true;
            } else if (l10.tag == 846u) {
                t0 = l10.payload.obj;
                l13 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l13)
                ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l13] = (uint8_t) true;
                l5 = true;
            }
            l9 = (l9 + INT64_C(1));
        }
        l3 = (l3 + INT64_C(1));
    }
    vader_struct_vader_emit_c$FnValueUsage_t* _a8_obj = (vader_struct_vader_emit_c$FnValueUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$FnValueUsage_t));
    vader_obj_header_init(_a8_obj, 936u);
    _a8_obj->f_fn_ref_type = l2;
    _a8_obj->f_is_closure = l4;
    _a8_obj->f_any = l5;
    t0 = (void*) _a8_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$scope_ending_at(void* l0, int32_t l1) {
    int64_t l2, l3;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_end_pc;
        if (t1 == l1) {
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
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
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_emit_c$ScopeInfo_t*) t0)->f_opener_pc;
        if (t1 == l1) {
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
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
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[7] = { &l2, &l3, &l6, &l9, &l10, &l11, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l13, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$argument(INT64_C(0));
    l3 = vader_emit_c$argument(INT64_C(1));
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l4 = vader_core_bytecode$intrinsic_id_for(t0);
    if (l4 == INT32_C(18)) {
        vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a0_arr;
        t1 = vader_emit_c_ast$perform(2957u, l5);
        vader_array_t* _a1_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a1_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a2_arr;
        t1 = vader_emit_c_ast$returning(2969u, l5);
        vader_array_t* _a3_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a3_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(2)) {
        vader_array_t* _a4_arr = vader_array_new(254u, 2u, 13u, 1914u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a4_arr;
        t1 = vader_emit_c_ast$returning(2968u, l5);
        vader_array_t* _a5_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a5_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(3)) {
        l6 = vader_emit_c$argument(INT64_C(2));
        vader_array_t* _a6_arr = vader_array_new(254u, 3u, 13u, 1914u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 2u] = l6.payload.obj;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a6_arr;
        t1 = vader_emit_c_ast$returning(2970u, l5);
        vader_array_t* _a7_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a7_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(4)) {
        vader_array_t* _a8_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a8_arr;
        t1 = vader_emit_c_ast$returning(2974u, l5);
        vader_array_t* _a9_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a9_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(5)) {
        l7 = vader_emit_c$class_index(l1, (uint8_t) 4);
        if ((l7 < INT32_C(0))) {
            t1 = vader_emit_c$trap(1689u);
            vader_array_t* _a10_arr = vader_array_new(255u, 1u, 13u, 1918u);
            ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = t1.payload.obj;
            t2 = (void*) _a10_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = vader_emit_c$array_tag(l1, l7);
        if (!((l8 < INT32_C(0)))) {
            l6 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l8));
            l9 = vader_emit_c_ast$unsigned(((int64_t) (int32_t) l7));
            vader_array_t* _a11_arr = vader_array_new(254u, 3u, 13u, 1914u);
            ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 2u] = l9.payload.obj;
            ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 1u] = l6.payload.obj;
            ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = l2.payload.obj;
            l5 = (void*) _a11_arr;
            l6 = vader_emit_c_ast$call(2971u, l5);
            vader_array_t* _a12_arr = vader_array_new(95u, 0u, 13u, 951u);
            l5 = (void*) _a12_arr;
            l6 = vader_emit_c_ast$cast(3017u, l6);
            vader_struct_vader_emit_c_ast$CReturn_t* _a13_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
            vader_obj_header_init(_a13_obj, 988u);
            _a13_obj->f_stores = l5;
            _a13_obj->f_value = l6;
            _a13_obj->f_snapshot_type = 0u;
            _a13_obj->f_pops_frame = false;
            t2 = (void*) _a13_obj;
            vader_array_t* _a14_arr = vader_array_new(255u, 1u, 13u, 1918u);
            ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t2;
            t2 = (void*) _a14_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_emit_c$trap(1690u);
        vader_array_t* _a15_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a15_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(6)) {
        t1 = vader_emit_c_ast$cast(2893u, l2);
        vader_array_t* _a16_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t1.payload.obj;
        l5 = (void*) _a16_arr;
        t1 = vader_emit_c_ast$returning(2967u, l5);
        vader_array_t* _a17_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a17_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(7)) {
        vader_array_t* _a18_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a18_arr;
        t1 = vader_emit_c_ast$returning(2973u, l5);
        vader_array_t* _a19_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a19_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(11)) {
        vader_array_t* _a20_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l5 = (void*) _a20_arr;
        t1 = vader_emit_c_ast$perform(2942u, l5);
        vader_array_t* _a21_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a21_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(12)) {
        t1 = vader_emit_c$gc_statistic(2737u);
        vader_array_t* _a22_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a22_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(13)) {
        t1 = vader_emit_c$gc_statistic(1693u);
        vader_array_t* _a23_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a23_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(14)) {
        t1 = vader_emit_c$gc_statistic(2738u);
        vader_array_t* _a24_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a24_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(15)) {
        vader_array_t* _a25_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l5 = (void*) _a25_arr;
        t1 = vader_emit_c_ast$returning(2964u, l5);
        vader_array_t* _a26_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a26_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(16)) {
        vader_array_t* _a27_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a27_arr;
        t1 = vader_emit_c_ast$perform(2963u, l5);
        vader_array_t* _a28_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a28_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(17)) {
        vader_array_t* _a29_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l5 = (void*) _a29_arr;
        t1 = vader_emit_c_ast$returning(2965u, l5);
        vader_array_t* _a30_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a30_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(21)) {
        t2 = vader_emit_c$library_open_shim(2931u, l2);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(22)) {
        t2 = vader_emit_c$library_open_shim(2932u, l2);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(23)) {
        l6 = vader_emit_c$integer_as_address(l2);
        l9 = vader_emit_c_ast$verbatim(1696u);
        vader_array_t* _a31_arr = vader_array_new(254u, 2u, 13u, 1914u);
        ((void**) _a31_arr->buf->slots)[_a31_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a31_arr->buf->slots)[_a31_arr->offset + 0u] = l6.payload.obj;
        l5 = (void*) _a31_arr;
        l6 = vader_emit_c_ast$call(2933u, l5);
        vader_array_t* _a32_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a32_arr->buf->slots)[_a32_arr->offset + 0u] = l3.payload.obj;
        l5 = (void*) _a32_arr;
        l9 = vader_emit_c_ast$call(2977u, l5);
        l9 = vader_emit_c_ast$declaration(1799u, 1696u, l9);
        l6 = vader_emit_c_ast$declaration(3017u, 2487u, l6);
        l10 = vader_emit_c_ast$verbatim(1696u);
        vader_array_t* _a33_arr = vader_array_new(254u, 2u, 13u, 1914u);
        ((void**) _a33_arr->buf->slots)[_a33_arr->offset + 1u] = l10.payload.obj;
        ((void**) _a33_arr->buf->slots)[_a33_arr->offset + 0u] = l3.payload.obj;
        l5 = (void*) _a33_arr;
        l10 = vader_emit_c_ast$perform(2922u, l5);
        vader_array_t* _a34_arr = vader_array_new(95u, 0u, 13u, 951u);
        l5 = (void*) _a34_arr;
        t1 = vader_emit_c_ast$verbatim(2487u);
        l11 = vader_emit_c$address_as_integer(t1);
        vader_struct_vader_emit_c_ast$CReturn_t* _a35_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a35_obj, 988u);
        _a35_obj->f_stores = l5;
        _a35_obj->f_value = l11;
        _a35_obj->f_snapshot_type = 0u;
        _a35_obj->f_pops_frame = false;
        l5 = (void*) _a35_obj;
        vader_array_t* _a36_arr = vader_array_new(255u, 4u, 13u, 1918u);
        ((void**) _a36_arr->buf->slots)[_a36_arr->offset + 3u] = l5;
        ((void**) _a36_arr->buf->slots)[_a36_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a36_arr->buf->slots)[_a36_arr->offset + 1u] = l6.payload.obj;
        ((void**) _a36_arr->buf->slots)[_a36_arr->offset + 0u] = l9.payload.obj;
        t2 = (void*) _a36_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(24)) {
        l6 = vader_emit_c$integer_as_address(l2);
        l9 = vader_emit_c_ast$cast(2893u, l3);
        l10 = vader_emit_c$argument(INT64_C(2));
        l10 = vader_emit_c_ast$cast(2893u, l10);
        l11 = vader_emit_c$argument(INT64_C(3));
        vader_array_t* _a37_arr = vader_array_new(254u, 4u, 13u, 1914u);
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 3u] = l11.payload.obj;
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 0u] = l6.payload.obj;
        l5 = (void*) _a37_arr;
        t1 = vader_emit_c_ast$returning(2929u, l5);
        vader_array_t* _a38_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a38_arr->buf->slots)[_a38_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a38_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(25)) {
        l2 = vader_emit_c$integer_as_address(l2);
        l3 = vader_emit_c_ast$cast(2893u, l3);
        l6 = vader_emit_c$argument(INT64_C(2));
        l6 = vader_emit_c_ast$cast(2893u, l6);
        vader_array_t* _a39_arr = vader_array_new(254u, 3u, 13u, 1914u);
        ((void**) _a39_arr->buf->slots)[_a39_arr->offset + 2u] = l6.payload.obj;
        ((void**) _a39_arr->buf->slots)[_a39_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a39_arr->buf->slots)[_a39_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a39_arr;
        t1 = vader_emit_c_ast$returning(2928u, l5);
        vader_array_t* _a40_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a40_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(19)) {
        vader_array_t* _a41_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l5 = (void*) _a41_arr;
        t1 = vader_emit_c_ast$returning(2924u, l5);
        vader_array_t* _a42_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a42_arr->buf->slots)[_a42_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a42_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(20)) {
        vader_array_t* _a43_arr = vader_array_new(254u, 0u, 13u, 1914u);
        l5 = (void*) _a43_arr;
        t1 = vader_emit_c_ast$returning(2923u, l5);
        vader_array_t* _a44_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a44_arr->buf->slots)[_a44_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a44_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(8)) {
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
        l12 = l4 == INT32_C(0);
    }
    if (!(l12)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t3 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_is_extern;
    if (!(t3)) {
        l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
        t0 = concat_2(2813u, l13);
        t1 = vader_emit_c$trap(t0);
        vader_array_t* _a45_arr = vader_array_new(255u, 1u, 13u, 1918u);
        ((void**) _a45_arr->buf->slots)[_a45_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a45_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_emit_c$user_extern_shim(l0, l1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    l5 = vader_emit_c$value_parameters(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l1)->f_signature)->f_params, 1424u);
    vader_struct_vader_emit_c_ast$CSignature_t* _a0_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a0_obj, 992u);
    _a0_obj->f_storage = (uint8_t) 0;
    _a0_obj->f_inline = l2;
    _a0_obj->f_result = l3;
    _a0_obj->f_name = l4;
    _a0_obj->f_parameters = l5;
    l5 = (void*) _a0_obj;
    t1 = ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_library_units;
    if (t1) {
        t2 = vader_core_bytecode$library_name(l1);
        if (t2 != 0u) {
            l6 = l5;
            l3 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l6)->f_result;
            l4 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l6)->f_name;
            l6 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l6)->f_parameters;
            vader_struct_vader_emit_c_ast$CSignature_t* _a1_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
            vader_obj_header_init(_a1_obj, 992u);
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
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l3 = vader_emit_c$value_parameters(((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_params, 2267u);
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature);
    l4 = (t0 > INT64_C(1));
    if (l4) {
        l5 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature)->f_results;
        l6 = INT64_C(0);
        l7 = ((vader_array_t*) l5)->length;
        while ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l6, 340u);
            t2 = vader_emit_c$c_type_for_val_bare(((uint8_t) t1.payload.i));
            l8 = concat_2(t2, 349u);
            l9 = vader_emit_c$out_param_name(l6);
            vader_struct_vader_emit_c_ast$CParameter_t* _a2_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
            vader_obj_header_init(_a2_obj, 984u);
            _a2_obj->f_type = l8;
            _a2_obj->f_name = l9;
            l10 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l10);
            l6 = (l6 + INT64_C(1));
        }
    }
    l11 = vader_emit_c$module_function_storage(l0, l1);
    if (l4) {
        l8 = 3016u;
    } else {
        t3 = vader_core_bytecode$bc_single_result(((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature);
        l8 = vader_emit_c$c_type_for_val_bare(t3);
    }
    t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_name;
    l9 = vader_emit_c$sanitise(t2);
    vader_struct_vader_emit_c_ast$CSignature_t* _a3_obj = (vader_struct_vader_emit_c_ast$CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSignature_t));
    vader_obj_header_init(_a3_obj, 992u);
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
    vader_obj_header_init(_a0_obj, 958u);
    _a0_obj->f_model = l5;
    _a0_obj->f_value = l6;
    l7 = (void*) _a0_obj;
    l5 = vader_emit_c_ast$number(INT64_C(0));
    t1 = vader_emit_c_ast$binary((uint8_t) 7, vader_ref_box(l7), l5);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a1_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a1_obj, 985u);
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
    l9 = concat_4(l2, 397u, l3, 210u);
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
    t0 = (void*) &vader_data_51;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_emit_c_ast$verbatim(l1);
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l3 = vader_emit_c_ast$initializer_list(t0);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a2_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a2_obj, 963u);
    _a2_obj->f_name = l0;
    _a2_obj->f_length = vader_ref_box(l2);
    _a2_obj->f_value = l3;
    l2 = (void*) _a2_obj;
    vader_struct_vader_emit_c_ast$CGlobal_t* _a3_obj = (vader_struct_vader_emit_c_ast$CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CGlobal_t));
    vader_obj_header_init(_a3_obj, 972u);
    _a3_obj->f_storage = (uint8_t) 0;
    _a3_obj->f_constant = true;
    _a3_obj->f_type = 2807u;
    _a3_obj->f_declarator = l2;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$single_reference_row(int64_t l0, vader_string_t l1, vader_string_t l2, int32_t l3, vader_string_t l4) {
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    void* l10 = NULL;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l5, &l6, &l7, &l8, &l9, &t1 };
    void** gc_raw_roots[1] = { &l10 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(939u, l1);
    l5 = vader_emit_c_ast$verbatim(t0);
    l5 = vader_emit_c_ast$designated(416u, l5);
    t0 = concat_3(2569u, l2, 321u);
    l6 = vader_emit_c_ast$verbatim(t0);
    l6 = vader_emit_c_ast$designated(429u, l6);
    l7 = vader_emit_c_ast$number(((int64_t) (int32_t) l3));
    l7 = vader_emit_c_ast$designated(430u, l7);
    l8 = vader_emit_c_ast$verbatim(l4);
    l8 = vader_emit_c_ast$designated(424u, l8);
    l9 = vader_emit_c_ast$number(INT64_C(1));
    l9 = vader_emit_c_ast$designated(423u, l9);
    vader_array_t* _a0_arr = vader_array_new(254u, 5u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l9.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l8.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l10 = (void*) _a0_arr;
    t1 = vader_emit_c$info_row(l0, l10);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_c$slot_index(vader_string_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 394u);
    l2 = vader_emit_c_ast$verbatim(t0);
    l3 = vader_emit_c$expression_of(l1);
    l3 = vader_emit_c_ast$cast(2567u, l3);
    t1 = vader_emit_c_ast$binary((uint8_t) 3, l2, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = ((vader_array_t*) l2)->length;
    l3 = ((int32_t) (int64_t) t0);
    if (!((l1 < l3))) {
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
        l5 = ((int64_t) (int32_t) l1);
        l6 = ((vader_array_t*) l2)->length;
        l5 = vader_chk_sub(i64, l5, l6);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        return ((vader_struct_vader_core_bytecode$BcLocal_t*) t1)->f_val;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l1, 340u);
    return ((uint8_t) t2.payload.i);
}

static void* vader_emit_c$sorted_fn_indices(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    int64_t l2, l3;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _pc14_hdr = (vader_array_t*) l1;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            l4 = ((int32_t) (int64_t) l2);
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int32_t*) _pc14_slots)[_pc14_len] = (int32_t) (l4);
                _pc14_len += 1;
            } else {
                _pc14_hdr->length = _pc14_len;
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i32((vader_array_t*) l1, l4);
                _pc14_hdr = (vader_array_t*) l1;
                _pc14_len = _pc14_hdr->length;
                _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc14_hdr->length = _pc14_len;
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    vader_struct___lambda_env_vader_emit_c_4_t* _a2_obj = (vader_struct___lambda_env_vader_emit_c_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_4_t));
    vader_obj_header_init(_a2_obj, 369u);
    _a2_obj->f_cap_0 = l0;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 307u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_emit_c_3;
    _a3_closure->env = t0;
    l5 = (void*) _a3_closure;
    t0 = std_sort$sort__i32(l1, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c$sorted_module_stems(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l2, l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections$MutableMap__string__i32___t*) l0)->f_size;
    if ((INT64_C(0) < l2)) {
        l2 = ((vader_struct_std_collections$MutableMap__string__i32___t*) l0)->f_size;
    } else {
        l2 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l4 = ((vader_struct_std_collections$MutableMap__string__i32___t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__i32___t*) l3)->f_evals;
    l2 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__i32___t*) l3)->f_size;
    while ((l2 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
        l7 = t0.payload.s;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l2);
        l8 = l7;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(335u, l8));
        l2 = (l2 + INT64_C(1));
    }
    l3 = (void*) &vader_fn_static___lambda_vader_emit_c_5;
    t1 = std_sort$sort__string(l1, l3);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 340u);
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
    vader_obj_header_init(_a0_obj, 955u);
    _a0_obj->f_callee = l1;
    _a0_obj->f_arguments = l2;
    t0 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CMacroStatement_t* _a1_obj = (vader_struct_vader_emit_c_ast$CMacroStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMacroStatement_t));
    vader_obj_header_init(_a1_obj, 980u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, t0);
    t1 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CStringLiterals_t* _a1_obj = (vader_struct_vader_emit_c_ast$CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStringLiterals_t));
    vader_obj_header_init(_a1_obj, 994u);
    _a1_obj->f_literals = t1;
    l2 = (void*) _a1_obj;
    vader_struct_vader_emit_c_ast$CStaticAssert_t* _a2_obj = (vader_struct_vader_emit_c_ast$CStaticAssert_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStaticAssert_t));
    vader_obj_header_init(_a2_obj, 993u);
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
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l3.tag == 735u) {
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
    t0 = concat_3(2978u, l1, 1033u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l5.tag == 738u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
            l6 = vader_emit_c$struct_c_name(t1);
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(335u, l6));
        } else {
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(335u, 0u));
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
    vader_obj_header_init(_a0_obj, 968u);
    _a0_obj->f_type = 2954u;
    _a0_obj->f_name = 2079u;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(98u, 1u, 13u, 968u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_type_index;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
        t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
        l10 = vader_emit_c$c_type_for(t1);
        t2 = ((vader_struct_vader_core_bytecode$BcField_t*) l8)->f_name;
        l11 = vader_emit_c$field_c_name(t2);
        vader_struct_vader_emit_c_ast$CField_t* _a4_obj = (vader_struct_vader_emit_c_ast$CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CField_t));
        vader_obj_header_init(_a4_obj, 968u);
        _a4_obj->f_type = l10;
        _a4_obj->f_name = l11;
        l12 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l4, l12);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
    t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l3];
    t2 = t1.payload.s;
    vader_struct_vader_emit_c_ast$CStructDefinition_t* _a6_obj = (vader_struct_vader_emit_c_ast$CStructDefinition_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CStructDefinition_t));
    vader_obj_header_init(_a6_obj, 995u);
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l6 = vader_emit_c$val_type_of_bc_type(t0);
    if (l6 == INT32_C(17)) {
        t0 = vader_emit_c$box_slot(l0, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 741u) {
        t1 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_kind;
        t1 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcValPrim_t*) t1)->f_bits;
        t0 = vader_emit_c$data_slot(l7, l8);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 742u) {
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
    t0 = vader_emit_c_ast$cast(3017u, l10);
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
    vader_box_t* gc_roots[4] = { &l4, &l6, &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &l9 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$verbatim(940u);
    l4 = vader_emit_c_ast$designated(416u, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
    l5 = t0.payload.s;
    t1 = concat_3(2569u, l5, 321u);
    l6 = vader_emit_c_ast$verbatim(t1);
    l6 = vader_emit_c_ast$designated(429u, l6);
    t2 = vader_core_bytecode$size_of_bc_type(vader_ref_box(l1));
    l7 = vader_emit_c_ast$number(((int64_t) (int32_t) t2));
    l7 = vader_emit_c_ast$designated(430u, l7);
    vader_array_t* _a1_arr = vader_array_new(254u, 3u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l7.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
    l8 = (void*) _a1_arr;
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_ptr_offsets;
    vader_emit_c$push_offset_list(l8, 2481u, l9);
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_str_offsets;
    vader_emit_c$push_offset_list(l8, 2646u, l9);
    l9 = ((vader_struct_vader_emit_c$StructOffsets_t*) l2)->f_ref_offsets;
    vader_emit_c$push_offset_list(l8, 2504u, l9);
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
        t1 = concat_2(l1, 349u);
        t2 = vader_emit_c_ast$cast(t1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
    l3 = std_core$write_string_at(l2, l3, 2780u);
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
        t0 = vader_emit_c_ast$pointer_member(2956u, l0, 2769u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_emit_c_ast$CMember_t* _a0_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a0_obj, 981u);
    _a0_obj->f_base = l0;
    _a0_obj->f_member = 2694u;
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
    vader_obj_header_init(_a0_obj, 985u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1;
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_impl_table;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        t2 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) l8)->f_trait_name;
        if (t2 == l2) {
            l9 = ((vader_struct_vader_core_bytecode$ImplEntry_t*) l8)->f_type_index;
            t0 = vader_emit_c$tag_equals(l1, l9);
            vader_struct_vader_emit_c_ast$CParenthesized_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
            vader_obj_header_init(_a3_obj, 985u);
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
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l8, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l5 = INT64_C(0);
        l5 = std_core$write_string_at(l4, l5, 1424u);
        l5 = std_core$write_int(l4, l5, l2);
        t0 = std_core$finish_buffer(l4, l5);
        l6 = vader_emit_c_ast$verbatim(t0);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 340u);
        l7 = ((uint8_t) t1.payload.i);
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
    l3 = concat_2(2940u, l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params)->length;
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    t1 = vader_emit_c_ast$perform(2979u, l1);
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
    l4 = std_core$write_string_at(l3, l4, 1701u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core$write_int(l3, l4, l5);
    l4 = std_core$write_string_at(l3, l4, 182u);
    t0 = std_core$finish_buffer(l3, l4);
    vader_host_std_abort$panic(t0);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_emit_c$type_index_for_name(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    vader_string_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 738u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(0);
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
        vader_obj_header_init(_a0_obj, 942u);
        _a0_obj->f_cty = 2178u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_emit_c$SlotFill_t* _a1_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a1_obj, 942u);
        _a1_obj->f_cty = 2178u;
        _a1_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_emit_c$SlotFill_t* _a2_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a2_obj, 942u);
        _a2_obj->f_cty = 2178u;
        _a2_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(8)) {
        vader_struct_vader_emit_c$SlotFill_t* _a3_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a3_obj, 942u);
        _a3_obj->f_cty = 2179u;
        _a3_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(4)) {
        vader_struct_vader_emit_c$SlotFill_t* _a4_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a4_obj, 942u);
        _a4_obj->f_cty = 2179u;
        _a4_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_emit_c$SlotFill_t* _a5_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a5_obj, 942u);
        _a5_obj->f_cty = 1850u;
        _a5_obj->f_val = (uint8_t) 9;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(1)) {
        vader_struct_vader_emit_c$SlotFill_t* _a6_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a6_obj, 942u);
        _a6_obj->f_cty = 2810u;
        _a6_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a6_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(5)) {
        vader_struct_vader_emit_c$SlotFill_t* _a7_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a7_obj, 942u);
        _a7_obj->f_cty = 2180u;
        _a7_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a7_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        vader_struct_vader_emit_c$SlotFill_t* _a8_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a8_obj, 942u);
        _a8_obj->f_cty = 2810u;
        _a8_obj->f_val = (uint8_t) 10;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(2)) {
        vader_struct_vader_emit_c$SlotFill_t* _a9_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a9_obj, 942u);
        _a9_obj->f_cty = 2807u;
        _a9_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(6)) {
        vader_struct_vader_emit_c$SlotFill_t* _a10_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a10_obj, 942u);
        _a10_obj->f_cty = 2177u;
        _a10_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a10_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(9)) {
        vader_struct_vader_emit_c$SlotFill_t* _a11_obj = (vader_struct_vader_emit_c$SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$SlotFill_t));
        vader_obj_header_init(_a11_obj, 942u);
        _a11_obj->f_cty = 2011u;
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
    l3 = concat_2(l0, 349u);
    t0 = concat_2(l1, 390u);
    l4 = vader_emit_c_ast$verbatim(t0);
    t1 = vader_emit_c_ast$cast(l3, l4);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 985u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CIndex_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIndex_t));
    vader_obj_header_init(_a1_obj, 976u);
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
        l2 = vader_emit_c$payload_cast(2180u, l0, 2083u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        l2 = vader_emit_c$payload_cast(2177u, l0, 2083u);
    } else if (l1 == INT32_C(2)) {
        l2 = vader_emit_c$payload_cast(2178u, l0, 2083u);
    } else if (l1 == INT32_C(3)) {
        l2 = vader_emit_c$payload_cast(2179u, l0, 2083u);
    } else if (l1 == INT32_C(4)) {
        l2 = vader_emit_c$payload_cast(2810u, l0, 2083u);
    } else if (l1 == INT32_C(5)) {
        l2 = vader_emit_c$payload_cast(2807u, l0, 2083u);
    } else if (l1 == INT32_C(6)) {
        l2 = vader_emit_c$payload_cast(2808u, l0, 2083u);
    } else if (l1 == INT32_C(7)) {
        l2 = vader_emit_c$payload_cast(2809u, l0, 2083u);
    } else if (l1 == INT32_C(11)) {
        l2 = vader_emit_c$payload_cast(2808u, l0, 2083u);
    } else if (l1 == INT32_C(8)) {
        l2 = vader_emit_c$payload_cast(2011u, l0, 1958u);
    } else if (l1 == INT32_C(9)) {
        l2 = vader_emit_c$payload_cast(1850u, l0, 1958u);
    } else if (l1 == INT32_C(10)) {
        l2 = vader_emit_c$payload(l0, 1617u);
    } else if (l1 == INT32_C(12)) {
        l2 = vader_emit_c$payload(l0, 2537u);
    } else if (l1 == INT32_C(13)) {
        l2 = l0;
    } else if (l1 == INT32_C(14)) {
        l2 = vader_emit_c_ast$verbatim(308u);
    } else if (l1 == INT32_C(15)) {
        l3 = vader_emit_c$payload(l0, 2083u);
        l3 = vader_emit_c_ast$cast(2194u, l3);
        t0 = vader_emit_c_ast$cast(3017u, l3);
        vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
        vader_obj_header_init(_a0_obj, 985u);
        _a0_obj->f_inner = t0;
        t1 = (void*) _a0_obj;
        l2 = vader_ref_box(t1);
    } else if (l1 == INT32_C(16)) {
        l2 = vader_emit_c$payload(l0, 2418u);
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
        l8 = std_core$write_string_at(l7, l8, 1700u);
        l9 = ((int64_t) (int32_t) l1);
        l8 = std_core$write_int(l7, l8, l9);
        l8 = std_core$write_string_at(l7, l8, 376u);
        t0 = std_core$finish_buffer(l7, l8);
        vader_host_std_abort$panic(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l5 = ((int32_t) l6.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (!(l6.tag == 738u)) {
            l7 = (void*) vader_buffer_new((size_t) INT64_C(61));
            l8 = INT64_C(0);
            l8 = std_core$write_string_at(l7, l8, 1704u);
            l9 = ((int64_t) (int32_t) l1);
            l8 = std_core$write_int(l7, l8, l9);
            l8 = std_core$write_string_at(l7, l8, 156u);
            t0 = std_core$finish_buffer(l7, l8);
            vader_host_std_abort$panic(t0);
            vader_unreachable("a no-return call returned");
        }
        t1 = l6.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        l10 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        t0 = vader_emit_c$c_type_for(t2);
        l6 = vader_emit_c_ast$verbatim(t0);
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) ((vader_struct_vader_emit_c$FnState_t*) l0)->f_ctx)->f_struct_c_names);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l5];
        t0 = t2.payload.s;
        l11 = vader_emit_c_ast$verbatim(t0);
        t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_name;
        t3 = vader_emit_c$field_c_name(t0);
        l12 = vader_emit_c_ast$verbatim(t3);
        vader_array_t* _a4_arr = vader_array_new(254u, 4u, 13u, 1914u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 3u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l11.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l6.payload.obj;
        l4 = (void*) _a4_arr;
        l6 = vader_emit_c_ast$call(941u, l4);
        l5 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
        vader_struct_vader_emit_c$UnionFieldPlace_t* _a5_obj = (vader_struct_vader_emit_c$UnionFieldPlace_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$UnionFieldPlace_t));
        vader_obj_header_init(_a5_obj, 949u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, 1026u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(1);
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
        l6 = vader_emit_c$module_stem_of(t1);
        l7 = INT64_C(0);
        l8 = vader_host_std_core$byte_len(l6);
        while ((l7 < l8)) {
            t2 = vader_host_std_core$byte_at(l6, l7);
            t3 = vader_support_text$is_ident_byte(t2);
            if (!(t3)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
                l9 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
                t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
                t1 = concat_3(2578u, l10, 1177u);
                std_abort$todo(t1);
                vader_unreachable("a no-return call returned");
            }
            l7 = (l7 + INT64_C(1));
        }
        if (l6 == 0u) {
            l11 = 1031u;
        } else {
            l11 = l6;
        }
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l11));
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 335u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(19u, 0u, 12u, 333u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a10_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a10_obj, 539u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_grow_at = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a10_obj;
    vader_struct_std_collections$MutableSet__string_t* _a11_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a11_obj, 607u);
    _a11_obj->f_inner = t0;
    l12 = (void*) _a11_obj;
    l13 = l2;
    l3 = ((vader_array_t*) l13)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        t4 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l4];
        l6 = t4.payload.s;
        t3 = std_collections$add__string(l12, l6);
        if (!(t3)) {
            t1 = concat_3(2577u, l6, 1268u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(2983u, l2);
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
    void* l45 = NULL;
    void* l50 = NULL;
    void* l53 = NULL;
    void* l54 = NULL;
    void* l57 = NULL;
    void* l58 = NULL;
    void* l62 = NULL;
    void* l65 = NULL;
    void* l68 = NULL;
    void* l71 = NULL;
    void* l74 = NULL;
    void* l76 = NULL;
    int64_t l8, l9, l15, l19, l30, l34, l42, l46, l59, l63, l66, l72, l77;
    vader_box_t l10 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null(), l21 = vader_box_null(), l31 = vader_box_null(), l36 = vader_box_null(), l37 = vader_box_null(), l38 = vader_box_null(), l39 = vader_box_null(), l44 = vader_box_null(), l47 = vader_box_null(), l48 = vader_box_null(), l51 = vader_box_null(), l52 = vader_box_null(), l55 = vader_box_null(), l56 = vader_box_null(), l61 = vader_box_null(), l64 = vader_box_null(), l69 = vader_box_null(), l70 = vader_box_null(), l73 = vader_box_null(), l75 = vader_box_null(), l78 = vader_box_null(), l79 = vader_box_null();
    int32_t l11, l22, l23, l25, l27, l49;
    vader_string_t l16 = 0;
    vader_string_t l24 = 0;
    vader_string_t l26 = 0;
    vader_string_t l35 = 0;
    vader_string_t l40 = 0;
    vader_string_t l43 = 0;
    vader_string_t l60 = 0;
    vader_string_t l67 = 0;
    bool l80;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[25] = {
        &l10, &l13, &l17, &l21, &l31, &l36, &l37, &l38, &l39, &l44, &l47, &l48, &l51, &l52, &l55,
        &l56, &l61, &l64, &l69, &l70, &l73, &l75, &l78, &l79, &t1,
    };
    void** gc_raw_roots[30] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l12, &l14, &l18, &l20, &l28, &l29, &l32, &l33,
        &l41, &l45, &l50, &l53, &l54, &l57, &l58, &l62, &l65, &l68, &l71, &l74, &l76, &t3,
    };
    vader_string_t* gc_atom_roots[9] = { &l16, &l24, &l26, &l35, &l40, &l43, &l60, &l67, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 25u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature;
    vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(254u, 0u, 13u, 1914u);
    l7 = (void*) _a4_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params)->length;
    while ((l8 < l9)) {
        l10 = vader_emit_c$argument(l8);
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8];
        t0 = vader_emit_c$is_abi_array(l1, l11);
        if (t0) {
            t1 = vader_emit_c_ast$cast(2893u, l10);
            vader_array_t* _a6_arr = vader_array_new(254u, 1u, 13u, 1914u);
            ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t1.payload.obj;
            l12 = (void*) _a6_arr;
            l13 = vader_emit_c_ast$call(2865u, l12);
            l14 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l15 = INT64_C(0);
            l15 = std_core$write_string_at(l14, l15, 2537u);
            l15 = std_core$write_int(l14, l15, l8);
            l16 = std_core$finish_buffer(l14, l15);
            l17 = vader_emit_c_ast$declaration(2966u, l16, l13);
            vader_array_push_ref((vader_array_t*) l4, l17.payload.obj);
            l18 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l19 = INT64_C(0);
            l19 = std_core$write_string_at(l18, l19, 2537u);
            l19 = std_core$write_int(l18, l19, l8);
            t2 = std_core$finish_buffer(l18, l19);
            t1 = vader_emit_c_ast$verbatim(t2);
            vader_struct_vader_emit_c_ast$CMember_t* _a7_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
            vader_obj_header_init(_a7_obj, 981u);
            _a7_obj->f_base = t1;
            _a7_obj->f_member = 2481u;
            _a7_obj->f_arrow = false;
            l20 = (void*) _a7_obj;
            t0 = vader_core_bytecode$param_is_c_out(l2, l8);
            if (t0) {
                l21 = vader_emit_c_ast$cast(3017u, vader_ref_box(l20));
            } else {
                l21 = vader_ref_box(l20);
            }
            vader_array_push_ref((vader_array_t*) l3, l21.payload.obj);
        } else {
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
            l22 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l8];
            t2 = vader_emit_c$mirrored_c_struct(l1, l22);
            if (t2 != 0u) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
                l23 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l8];
                l24 = vader_emit_c$mirrored_c_struct(l1, l23);
                vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
                l25 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8];
                t2 = vader_emit_c$bc_struct_name(l1, l25);
                l26 = vader_emit_c$struct_c_name(t2);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
                l27 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l8];
                l28 = vader_emit_c$bc_struct_fields(l1, l27);
                l29 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l30 = INT64_C(0);
                l30 = std_core$write_string_at(l29, l30, 2448u);
                l30 = std_core$write_int(l29, l30, l8);
                t2 = std_core$finish_buffer(l29, l30);
                l31 = vader_emit_c_ast$verbatim(t2);
                t2 = concat_2(l26, 349u);
                t1 = vader_emit_c_ast$cast(t2, l10);
                vader_struct_vader_emit_c_ast$CParenthesized_t* _a12_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
                vader_obj_header_init(_a12_obj, 985u);
                _a12_obj->f_inner = t1;
                l32 = (void*) _a12_obj;
                l33 = (void*) vader_buffer_new((size_t) INT64_C(21));
                l34 = INT64_C(0);
                l34 = std_core$write_string_at(l33, l34, 2448u);
                l34 = std_core$write_int(l33, l34, l8);
                l35 = std_core$finish_buffer(l33, l34);
                t1 = vader_emit_c_ast$number(INT64_C(0));
                vader_array_t* _a13_arr = vader_array_new(254u, 1u, 13u, 1914u);
                ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = t1.payload.obj;
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
                    l42 = std_core$write_string_at(l41, l42, 2448u);
                    l42 = std_core$write_int(l41, l42, l8);
                    l43 = std_core$finish_buffer(l41, l42);
                    l44 = vader_emit_c_ast$declaration(l40, l43, l10);
                    vader_array_push_ref((vader_array_t*) l4, l44.payload.obj);
                    l45 = (void*) vader_buffer_new((size_t) INT64_C(21));
                    l46 = INT64_C(0);
                    l46 = std_core$write_string_at(l45, l46, 2448u);
                    l46 = std_core$write_int(l45, l46, l8);
                    t2 = std_core$finish_buffer(l45, l46);
                    t1 = vader_emit_c_ast$verbatim(t2);
                    l47 = vader_emit_c_ast$address_of(t1);
                    l48 = vader_emit_c_ast$cast(3017u, l47);
                    vader_array_push_ref((vader_array_t*) l3, l48.payload.obj);
                } else {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
                    l49 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l8];
                    t0 = vader_emit_c$is_abi_nullable_pointer(l1, l49);
                    if (t0) {
                        vader_struct_vader_emit_c_ast$CMember_t* _a15_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a15_obj, 981u);
                        _a15_obj->f_base = l10;
                        _a15_obj->f_member = 2694u;
                        _a15_obj->f_arrow = false;
                        l50 = (void*) _a15_obj;
                        l51 = vader_emit_c_ast$verbatim(931u);
                        l52 = vader_emit_c_ast$binary((uint8_t) 11, vader_ref_box(l50), l51);
                        vader_struct_vader_emit_c_ast$CMember_t* _a16_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a16_obj, 981u);
                        _a16_obj->f_base = l10;
                        _a16_obj->f_member = 2463u;
                        _a16_obj->f_arrow = false;
                        t3 = (void*) _a16_obj;
                        vader_struct_vader_emit_c_ast$CMember_t* _a17_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
                        vader_obj_header_init(_a17_obj, 981u);
                        _a17_obj->f_base = vader_ref_box(t3);
                        _a17_obj->f_member = 2083u;
                        _a17_obj->f_arrow = false;
                        l53 = (void*) _a17_obj;
                        t3 = (void*) &vader_data_53;
                        vader_array_t* _a18_slotarr = ((vader_array_t*) t3);
                        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                        l54 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
                        l55 = vader_emit_c_ast$cast(2194u, vader_ref_box(l53));
                        l56 = vader_emit_c_ast$cast(3017u, l55);
                        vader_struct_vader_emit_c_ast$CConditional_t* _a19_obj = (vader_struct_vader_emit_c_ast$CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CConditional_t));
                        vader_obj_header_init(_a19_obj, 960u);
                        _a19_obj->f_condition = l52;
                        _a19_obj->f_then_value = vader_ref_box(l54);
                        _a19_obj->f_else_value = l56;
                        l57 = (void*) _a19_obj;
                        l58 = (void*) vader_buffer_new((size_t) INT64_C(21));
                        l59 = INT64_C(0);
                        l59 = std_core$write_string_at(l58, l59, 2448u);
                        l59 = std_core$write_int(l58, l59, l8);
                        l60 = std_core$finish_buffer(l58, l59);
                        l61 = vader_emit_c_ast$declaration(3017u, l60, vader_ref_box(l57));
                        vader_array_push_ref((vader_array_t*) l4, l61.payload.obj);
                        l62 = (void*) vader_buffer_new((size_t) INT64_C(21));
                        l63 = INT64_C(0);
                        l63 = std_core$write_string_at(l62, l63, 2448u);
                        l63 = std_core$write_int(l62, l63, l8);
                        t2 = std_core$finish_buffer(l62, l63);
                        l64 = vader_emit_c_ast$verbatim(t2);
                        vader_array_push_ref((vader_array_t*) l3, l64.payload.obj);
                    } else {
                        vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params);
                        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l8)
                        t1 = vader_array_read_u8(_a20_slotarr, _a20_slotarr->offset + (size_t) l8, 340u);
                        if (((int32_t) t1.payload.i) == INT32_C(12)) {
                            l65 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l66 = INT64_C(0);
                            l66 = std_core$write_string_at(l65, l66, 1694u);
                            l66 = std_core$write_int(l65, l66, l8);
                            l67 = std_core$finish_buffer(l65, l66);
                            vader_array_t* _a21_arr = vader_array_new(254u, 1u, 13u, 1914u);
                            ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = l10.payload.obj;
                            l68 = (void*) _a21_arr;
                            l69 = vader_emit_c_ast$call(2977u, l68);
                            l70 = vader_emit_c_ast$declaration(1799u, l67, l69);
                            vader_array_push_ref((vader_array_t*) l4, l70.payload.obj);
                            l71 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l72 = INT64_C(0);
                            l72 = std_core$write_string_at(l71, l72, 1694u);
                            l72 = std_core$write_int(l71, l72, l8);
                            t2 = std_core$finish_buffer(l71, l72);
                            l73 = vader_emit_c_ast$verbatim(t2);
                            vader_array_t* _a22_arr = vader_array_new(254u, 2u, 13u, 1914u);
                            ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 1u] = l73.payload.obj;
                            ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l10.payload.obj;
                            l74 = (void*) _a22_arr;
                            l75 = vader_emit_c_ast$perform(2922u, l74);
                            vader_array_push_ref((vader_array_t*) l5, l75.payload.obj);
                            l76 = (void*) vader_buffer_new((size_t) INT64_C(21));
                            l77 = INT64_C(0);
                            l77 = std_core$write_string_at(l76, l77, 1694u);
                            l77 = std_core$write_int(l76, l77, l8);
                            t2 = std_core$finish_buffer(l76, l77);
                            l78 = vader_emit_c_ast$verbatim(t2);
                            vader_array_push_ref((vader_array_t*) l3, l78.payload.obj);
                        } else {
                            l79 = vader_emit_c$renamed_argument(l0, l8, l10);
                            vader_array_push_ref((vader_array_t*) l3, l79.payload.obj);
                        }
                    }
                }
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a23_arr = vader_array_new(255u, 0u, 13u, 1918u);
    l12 = (void*) _a23_arr;
    t4 = ((vader_array_t*) l7)->length;
    if ((t4 > INT64_C(0))) {
        t4 = ((vader_array_t*) l7)->length;
        l10 = vader_emit_c_ast$number(t4);
        l13 = vader_emit_c_ast$array_declaration(3018u, 1017u, l7);
        vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
        l13 = vader_emit_c_ast$verbatim(1016u);
        l17 = vader_emit_c_ast$verbatim(1017u);
        vader_array_t* _a24_arr = vader_array_new(254u, 3u, 13u, 1914u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 1u] = l17.payload.obj;
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = l13.payload.obj;
        l7 = (void*) _a24_arr;
        l10 = vader_emit_c_ast$perform(934u, l7);
        vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
        vader_array_t* _a25_arr = vader_array_new(254u, 1u, 13u, 1914u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = l13.payload.obj;
        l7 = (void*) _a25_arr;
        l10 = vader_emit_c_ast$perform(933u, l7);
        vader_array_push_ref((vader_array_t*) l12, l10.payload.obj);
    }
    vader_array_push_all((vader_array_t*) l12, (vader_array_t*) l6);
    t4 = ((vader_array_t*) l12)->length;
    if (t4 == INT64_C(0)) {
        t4 = ((vader_array_t*) l5)->length;
        l80 = t4 == INT64_C(0);
    } else {
        l80 = false;
    }
    t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_extern_name;
    l10 = vader_emit_c_ast$call(t2, l3);
    l10 = vader_emit_c$read_back(l0, l10);
    l2 = vader_emit_c$forwarded_result(l2, l1, l10, l80);
    t0 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_returns;
    if (!(t0)) {
        l13 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_capture;
        vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
        vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l12);
        l3 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_settle;
        vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l3);
        vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l5);
        vader_array_t* _a26_arr = vader_array_new(95u, 0u, 13u, 951u);
        l3 = (void*) _a26_arr;
        l13 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_returned;
        vader_struct_vader_emit_c_ast$CReturn_t* _a27_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
        vader_obj_header_init(_a27_obj, 988u);
        _a27_obj->f_stores = l3;
        _a27_obj->f_value = l13;
        _a27_obj->f_snapshot_type = 0u;
        _a27_obj->f_pops_frame = false;
        l3 = (void*) _a27_obj;
        vader_array_push_ref((vader_array_t*) l4, l3);
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_emit_c$ForwardedResult_t*) l2)->f_capture;
    vader_array_push_ref((vader_array_t*) l4, l10.payload.obj);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_emit_c$val_of(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 947u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackTemporary_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLit_t*) t0)->f_val;
    } else if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_emit_c$StackLocalRef_t*) t0)->f_val;
    } else {
        if (!(l0.tag == 943u)) {
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
    if (l0.tag == 735u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 738u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 725u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 728u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 739u) {
        l1 = (uint8_t) 17;
    } else {
        if (!(l0.tag == 734u)) {
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
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
    vader_array_t* _a0_arr = vader_array_new(101u, 0u, 13u, 984u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l3, 340u);
        l5 = vader_emit_c$c_type_for_val_bare(((uint8_t) t0.payload.i));
        l6 = l1;
        l7 = vader_host_std_core$byte_len(l6);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(20) + l7));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l8, l9, l6);
        l9 = std_core$write_int(l8, l9, l3);
        l10 = std_core$finish_buffer(l8, l9);
        vader_struct_vader_emit_c_ast$CParameter_t* _a3_obj = (vader_struct_vader_emit_c_ast$CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParameter_t));
        vader_obj_header_init(_a3_obj, 984u);
        _a3_obj->f_type = l5;
        _a3_obj->f_name = l10;
        l11 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l2, l11);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c$vtable_helper_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$split(l0, 397u);
    t1 = std_string$join(t0, 258u);
    l1 = vader_emit_c$sanitise(t1);
    t1 = concat_2(2989u, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l3 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) t0)->f_fn_index;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature;
    l4 = vader_core_bytecode$bc_single_result(l2);
    l3 = vader_core_bytecode$bc_single_result_type(l2);
    l5 = true;
    l6 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l1)->f_entries;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l10 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_emit_c$EmitCtx_t*) l0)->f_module)->f_functions;
        l11 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) l9)->f_fn_index;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
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
        vader_array_t* _a4_arr = vader_array_new(24u, 1u, 1u, 340u);
        ((uint8_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (uint8_t) INT32_C(17);
        l9 = (void*) _a4_arr;
        l10 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_types;
        vader_array_t* _a5_arr = vader_array_new(22u, 1u, 7u, 338u);
        ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) l3;
        l12 = (void*) _a5_arr;
        l14 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_names;
        vader_array_t* _a6_arr = vader_array_new(19u, 0u, 12u, 333u);
        l15 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(19u, 0u, 12u, 333u);
        l16 = (void*) _a7_arr;
        vader_struct_vader_core_bytecode$BcSignature_t* _a8_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
        vader_obj_header_init(_a8_obj, 736u);
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
    vader_array_t* _a0_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(944u, l2);
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
        t0 = (void*) &vader_data_52;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_52;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(254u, 1u, 13u, 1914u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    t0 = (void*) _a2_arr;
    t1 = vader_emit_c_ast$initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
