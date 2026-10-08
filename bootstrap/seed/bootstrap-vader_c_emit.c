#include "bootstrap.split.h"

static vader_box_t vader_c_emit_address_as_size(vader_box_t l0);
static void vader_c_emit_append_statement(void* l0, vader_box_t l1);
static vader_box_t vader_c_emit_argument(size_t l0);
static int32_t vader_c_emit_array_element_tag(void* l0, int32_t l1);
static vader_box_t vader_c_emit_array_header_pointer(vader_box_t l0);
static vader_box_t vader_c_emit_array_pointer(vader_box_t l0);
static int32_t vader_c_emit_array_tag(void* l0, int32_t l1);
static int32_t vader_c_emit_array_type_index_for_element(void* l0, int32_t l1);
static vader_box_t vader_c_emit_as_size(vader_box_t l0);
static void vader_c_emit_assert_stack_empty(void* l0, vader_string_t l1);
static void vader_c_emit_assign(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_c_emit_atom_count_define(void* l0);
static int32_t vader_c_emit_atom_for(void* l0, vader_string_t l1);
static void* vader_c_emit_atom_table_of(void* l0, void* l1);
static vader_string_t vader_c_emit_aux(void* l0, vader_string_t l1);
static void* vader_c_emit_bc_struct_fields(void* l0, int32_t l1);
static vader_string_t vader_c_emit_bc_struct_name(void* l0, int32_t l1);
static vader_box_t vader_c_emit_binary_expression(void* l0, uint8_t l1, uint8_t l2);
static vader_string_t vader_c_emit_bind_array_local(void* l0, vader_box_t l1);
static vader_box_t vader_c_emit_box_call(vader_string_t l0, int32_t l1, vader_box_t l2);
static vader_box_t vader_c_emit_box_expr(vader_box_t l0, uint8_t l1, int32_t l2);
static vader_box_t vader_c_emit_box_expr_unknown(void* l0, vader_box_t l1, uint8_t l2);
static vader_box_t vader_c_emit_box_slot(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static vader_box_t vader_c_emit_box_slot_1(vader_string_t l0, vader_box_t l1);
static vader_box_t vader_c_emit_boxed_object(int32_t l0, vader_box_t l1);
static void* vader_c_emit_boxed_parameters(void* l0, size_t l1);
static vader_box_t vader_c_emit_boxed_scalar(int32_t l0, uint8_t l1, uint64_t l2);
static vader_box_t vader_c_emit_boxed_string(int32_t l0, int32_t l1);
static vader_box_t vader_c_emit_branch_target(void* l0, int32_t l1);
static vader_box_t vader_c_emit_buffer_pointer(vader_box_t l0);
static void* vader_c_emit_build_string_atom_map(void* l0);
static vader_string_t vader_c_emit_c_field_name(void* l0);
static vader_string_t vader_c_emit_c_string_lit(vader_string_t l0);
static void* vader_c_emit_c_struct_layout_asserts(void* l0, void* l1);
static vader_string_t vader_c_emit_c_type_for(vader_box_t l0);
static vader_string_t vader_c_emit_c_type_for_array_kind(uint8_t l0);
static vader_string_t vader_c_emit_c_type_for_val_bare(uint8_t l0);
static int32_t vader_c_emit_callee_index_of(vader_box_t l0);
static size_t vader_c_emit_callee_result_arity(void* l0, vader_box_t l1);
static void* vader_c_emit_classify_struct_fields(void* l0, void* l1, size_t l2);
static void vader_c_emit_close_node(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_coerce_expr(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static vader_box_t vader_c_emit_coerce_operand(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static vader_box_t vader_c_emit_coerced_as(void* l0, vader_box_t l1, uint8_t l2);
static void* vader_c_emit_compute_atom_ids(void* l0, void* l1);
static void* vader_c_emit_compute_may_alloc(void* l0, void* l1);
static vader_box_t vader_c_emit_const_lit_c(void* l0, vader_box_t l1);
static uint8_t vader_c_emit_const_val(vader_box_t l0);
static uint8_t vader_c_emit_convert_target_val(uint8_t l0);
static void* vader_c_emit_crossing_mirrors(void* l0);
static void* vader_c_emit_current_block(void* l0);
static vader_box_t vader_c_emit_data_slot(uint8_t l0, uint64_t l1);
static void vader_c_emit_declare(void* l0, vader_string_t l1, vader_string_t l2, vader_box_t l3);
static void vader_c_emit_directive(void* l0, vader_string_t l1);
static void* vader_c_emit_dispatcher_parameters(void* l0);
static vader_box_t vader_c_emit_dispatcher_result(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static void* vader_c_emit_dispatcher_signature(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_c_emit_div_mod_helper(uint8_t l0, uint8_t l1);
static void vader_c_emit_drop_bound_for_local(void* l0, int32_t l1);
static void vader_c_emit_drop_top(void* l0);
static uint8_t vader_c_emit_element_storage_kind(void* l0);
static void vader_c_emit_emit_agg_data_entry(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_c_emit_emit_array_clear(void* l0);
static void vader_c_emit_emit_array_copy(void* l0);
static void vader_c_emit_emit_array_get(void* l0, void* l1);
static void vader_c_emit_emit_array_len(void* l0);
static void vader_c_emit_emit_array_new(void* l0, void* l1);
static void vader_c_emit_emit_array_push(void* l0, void* l1);
static void vader_c_emit_emit_array_push_all(void* l0);
static void vader_c_emit_emit_array_remove_last(void* l0);
static void vader_c_emit_emit_array_repeat(void* l0);
static void vader_c_emit_emit_array_set(void* l0, void* l1);
static void vader_c_emit_emit_array_slice(void* l0, void* l1);
static void vader_c_emit_emit_atom_comptime_table(void* l0, void* l1);
static void vader_c_emit_emit_bits_to_f32(void* l0);
static void vader_c_emit_emit_bits_to_f64(void* l0);
static void vader_c_emit_emit_branch(void* l0, int32_t l1, bool l2);
static void vader_c_emit_emit_buffer_load(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_emit_buffer_new(void* l0);
static void vader_c_emit_emit_buffer_store(void* l0, vader_string_t l1, vader_string_t l2);
static void vader_c_emit_emit_buffer_to_string(void* l0);
static void vader_c_emit_emit_buffer_write_string(void* l0);
static void vader_c_emit_emit_call(void* l0, void* l1);
static void vader_c_emit_emit_call_import(void* l0, void* l1);
static void vader_c_emit_emit_call_indirect(void* l0, void* l1);
static void vader_c_emit_emit_call_result(void* l0, vader_box_t l1, uint8_t l2);
static void vader_c_emit_emit_call_to(void* l0, vader_string_t l1, void* l2);
static void vader_c_emit_emit_closure_forward_decls(void* l0, void* l1);
static void vader_c_emit_emit_closure_lift(void* l0, void* l1, int32_t l2);
static void vader_c_emit_emit_convert(void* l0, uint8_t l1, vader_string_t l2);
static void vader_c_emit_emit_data_const_op(void* l0, void* l1);
static void vader_c_emit_emit_data_global_externs(void* l0, void* l1);
static void vader_c_emit_emit_data_pool(void* l0, void* l1);
static vader_box_t vader_c_emit_emit_data_value(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4);
static void vader_c_emit_emit_defer_pop_exec(void* l0, void* l1);
static void vader_c_emit_emit_defer_push(void* l0);
static void vader_c_emit_emit_else(void* l0);
static void vader_c_emit_emit_end(void* l0, int32_t l1);
static void vader_c_emit_emit_f32_to_bits(void* l0);
static void vader_c_emit_emit_f64_to_bits(void* l0);
static void vader_c_emit_emit_fn_addr(void* l0, void* l1);
static void vader_c_emit_emit_fn_ref(void* l0, void* l1);
static void vader_c_emit_emit_fn_ref_tramp(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_c_emit_emit_fn_sig_typedefs(void* l0, void* l1);
static void vader_c_emit_emit_fn_trampolines(void* l0, void* l1);
static void vader_c_emit_emit_forward_decls(void* l0, void* l1);
static void vader_c_emit_emit_global_const_roots(void* l0, void* l1);
static void vader_c_emit_emit_if_open(void* l0);
static void vader_c_emit_emit_import_shims(void* l0, void* l1);
static void vader_c_emit_emit_internal_forward_decls(void* l0, void* l1, void* l2);
static void vader_c_emit_emit_local_decls(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5);
static void vader_c_emit_emit_local_field(void* l0, void* l1);
static void vader_c_emit_emit_local_get(void* l0, void* l1);
static void vader_c_emit_emit_local_set(void* l0, int32_t l1, bool l2);
static void vader_c_emit_emit_main(void* l0, void* l1, vader_string_t l2);
static void vader_c_emit_emit_make_closure(void* l0, void* l1);
static void vader_c_emit_emit_memory_copy(void* l0);
static void vader_c_emit_emit_mirrored_struct_typedefs(void* l0, void* l1);
static void vader_c_emit_emit_multi_call(void* l0, vader_string_t l1, void* l2, void* l3);
static void vader_c_emit_emit_multi_return(void* l0);
static vader_box_t vader_c_emit_emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4);
static void vader_c_emit_emit_op(void* l0, int32_t l1, vader_box_t l2);
static void vader_c_emit_emit_open_scope(void* l0, int32_t l1, uint8_t l2);
static void vader_c_emit_emit_preamble(void* l0, vader_string_t l1);
static void vader_c_emit_emit_prim_data_entry(void* l0, void* l1, void* l2);
static void vader_c_emit_emit_ref_cast(void* l0, void* l1);
static void vader_c_emit_emit_retag_op(void* l0, void* l1);
static void vader_c_emit_emit_return(void* l0);
static void vader_c_emit_emit_return_lit(void* l0, vader_box_t l1);
static void vader_c_emit_emit_size_of_type(void* l0);
static vader_string_t vader_c_emit_emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3);
static void vader_c_emit_emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6);
static void vader_c_emit_emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_c_emit_emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_c_emit_emit_str_data_entry(void* l0, void* l1, void* l2, void* l3);
static void vader_c_emit_emit_string_compare(void* l0);
static void vader_c_emit_emit_string_slice(void* l0);
static void vader_c_emit_emit_struct_get(void* l0, void* l1);
static void vader_c_emit_emit_struct_new(void* l0, void* l1);
static void vader_c_emit_emit_struct_set(void* l0, void* l1);
static void vader_c_emit_emit_struct_typedefs(void* l0, void* l1);
static void vader_c_emit_emit_temporary_declarations(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5);
static void vader_c_emit_emit_type_check(void* l0, void* l1);
static void vader_c_emit_emit_type_const(void* l0, void* l1);
static void vader_c_emit_emit_type_info_table(void* l0, void* l1);
static void vader_c_emit_emit_typed_slot_write(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3, vader_string_t l4, uint8_t l5);
static void vader_c_emit_emit_virtual_call(void* l0, void* l1);
static void vader_c_emit_emit_vtable_dispatchers(void* l0, void* l1);
static void vader_c_emit_emit_vtable_forward_decls(void* l0, void* l1);
static void* vader_c_emit_empty_struct_offsets(void);
static bool vader_c_emit_entry_needs_materialise(vader_box_t l0, int32_t l1);
static void* vader_c_emit_erased_parameters(size_t l0);
static vader_box_t vader_c_emit_erased_sibling_field_read(void* l0, int32_t l1, int32_t l2, uint8_t l3, vader_box_t l4);
static void* vader_c_emit_erased_wrapper_signature(void* l0, vader_string_t l1, size_t l2);
static void vader_c_emit_evaluate(void* l0, vader_box_t l1);
static vader_box_t vader_c_emit_expression_of(vader_box_t l0);
static vader_string_t vader_c_emit_extern_c_type(uint8_t l0);
static vader_box_t vader_c_emit_extern_decl(void* l0, void* l1);
static vader_string_t vader_c_emit_extern_parameter_type(void* l0, void* l1, size_t l2);
static vader_box_t vader_c_emit_external(vader_string_t l0, vader_string_t l1, vader_box_t l2, bool l3);
static bool vader_c_emit_field_may_hold_reference(void* l0, int32_t l1);
static vader_box_t vader_c_emit_field_of(vader_string_t l0, vader_box_t l1, vader_string_t l2);
static bool vader_c_emit_fields_are_layout_siblings(void* l0, void* l1, void* l2);
static void* vader_c_emit_find_layout_siblings(void* l0, int32_t l1);
static int32_t vader_c_emit_find_main(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_find_vtable_row(void* l0, vader_string_t l1);
static vader_string_t vader_c_emit_float_lit(double l0);
static vader_box_t vader_c_emit_float_tag_check_expr(void* l0, vader_box_t l1);
static bool vader_c_emit_fn_builds_stack_object(void* l0);
static bool vader_c_emit_fn_calls_may_alloc(void* l0, void* l1);
static bool vader_c_emit_fn_has_direct_alloc(void* l0, void* l1);
static vader_string_t vader_c_emit_fn_symbol_name(void* l0, int32_t l1);
static void* vader_c_emit_forward_boxed(vader_string_t l0, void* l1, void* l2);
static void* vader_c_emit_forwarded_result(void* l0, void* l1, vader_box_t l2, bool l3);
static vader_box_t vader_c_emit_fresh_slot(vader_string_t l0, int32_t l1);
static void* vader_c_emit_function_definition(void* l0, int32_t l1, void* l2);
static vader_box_t vader_c_emit_gc_allocation(vader_string_t l0);
static vader_box_t vader_c_emit_gc_statistic(vader_string_t l0);
static uint8_t vader_c_emit_global_storage(bool l0);
static bool vader_c_emit_has_str_data(void* l0);
static vader_string_t vader_c_emit_host_shim_name(void* l0);
static void* vader_c_emit_import_shim(void* l0, void* l1);
static vader_string_t vader_c_emit_imports_header_name(vader_string_t l0);
static void* vader_c_emit_imports_may_collect(void* l0);
static void* vader_c_emit_include_of(vader_string_t l0);
static void* vader_c_emit_including(vader_string_t l0);
static vader_box_t vader_c_emit_info_row(size_t l0, void* l1);
static void vader_c_emit_init_object_header(void* l0, vader_string_t l1, int32_t l2);
static vader_box_t vader_c_emit_integer_payload(void* l0, vader_box_t l1);
static void* vader_c_emit_internal_fn_flags(void* l0, void* l1, vader_string_t l2);
static vader_box_t vader_c_emit_interned(vader_box_t l0);
static void vader_c_emit_invalidate_header_cache(void* l0, vader_box_t l1);
static bool vader_c_emit_is_abi_array(void* l0, int32_t l1);
static bool vader_c_emit_is_abi_nullable_pointer(void* l0, int32_t l1);
static bool vader_c_emit_is_abi_nullable_string(void* l0, int32_t l1);
static bool vader_c_emit_is_c_reserved(vader_string_t l0);
static bool vader_c_emit_is_cache_safe(vader_box_t l0);
static bool vader_c_emit_is_continue_branch(void* l0, int32_t l1);
static bool vader_c_emit_is_param_by_address(void* l0, size_t l1);
static bool vader_c_emit_is_ref_val(uint8_t l0);
static bool vader_c_emit_is_scope_opening(vader_box_t l0);
static void* vader_c_emit_lift_signature(void* l0, vader_string_t l1, void* l2);
static void* vader_c_emit_lift_unbox_tail(void* l0);
static void* vader_c_emit_main_body(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_materialise_entry(void* l0, vader_box_t l1);
static void vader_c_emit_materialize_stack_for_slot(void* l0, int32_t l1);
static size_t vader_c_emit_max_fn_arity(void* l0);
static vader_string_t vader_c_emit_mirrored_c_struct(void* l0, int32_t l1);
static uint8_t vader_c_emit_module_function_storage(void* l0, int32_t l1);
static vader_string_t vader_c_emit_module_stem_of(vader_string_t l0);
static void* vader_c_emit_mutable_pool_indices(void* l0);
static void* vader_c_emit_nested_member_mirrors(void* l0);
static void* vader_c_emit_new_ctx(void* l0, bool l1, bool l2, void* l3, void* l4);
static void* vader_c_emit_new_fn_state(void* l0, void* l1);
static void* vader_c_emit_new_temporary(void* l0, uint8_t l1);
static vader_box_t vader_c_emit_null_member(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_c_emit_null_or(vader_box_t l0, vader_box_t l1);
static int32_t vader_c_emit_null_primitive_tag(void* l0);
static vader_box_t vader_c_emit_object_header(vader_box_t l0);
static vader_box_t vader_c_emit_object_pointer(vader_box_t l0, uint8_t l1);
static vader_box_t vader_c_emit_object_pointer_of(vader_box_t l0);
static vader_box_t vader_c_emit_one_variant_check(void* l0, vader_box_t l1, int32_t l2);
static bool vader_c_emit_op_may_collect(vader_box_t l0, void* l1);
static void vader_c_emit_open_else(void* l0);
static void vader_c_emit_open_if(void* l0, vader_box_t l1);
static void vader_c_emit_open_node(void* l0, vader_box_t l1);
static void vader_c_emit_open_scope(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_operand_as(void* l0, vader_box_t l1, uint8_t l2);
static vader_string_t vader_c_emit_out_param_name(size_t l0);
static bool vader_c_emit_param_is_mutable(void* l0, size_t l1);
static void* vader_c_emit_partition_functions(void* l0);
static vader_box_t vader_c_emit_payload(vader_box_t l0, vader_string_t l1);
static vader_box_t vader_c_emit_payload_cast(vader_string_t l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_c_emit_pc_active_for(void* l0, int32_t l1);
static vader_box_t vader_c_emit_pc_capacity(int32_t l0);
static void vader_c_emit_pc_close_cache(void* l0, int32_t l1);
static void vader_c_emit_pc_emit_preheader(void* l0, void* l1);
static void vader_c_emit_pc_emit_push(void* l0, void* l1, vader_box_t l2, vader_box_t l3);
static void vader_c_emit_pc_emit_writeback(void* l0, int32_t l1);
static void* vader_c_emit_pc_fill_of(uint8_t l0);
static vader_box_t vader_c_emit_pc_header(int32_t l0, vader_string_t l1);
static vader_string_t vader_c_emit_pc_helper_of(uint8_t l0);
static bool vader_c_emit_pc_liftable_kind(uint8_t l0);
static vader_box_t vader_c_emit_pc_local(int32_t l0, vader_string_t l1);
static bool vader_c_emit_pc_operand_is_slot(vader_box_t l0, int32_t l1);
static void vader_c_emit_pc_plan_for_loop(void* l0, int32_t l1, int32_t* __o0, int32_t* __o1, int32_t* __o2, uint8_t* __o3);
static void vader_c_emit_pc_reload(void* l0, int32_t l1);
static bool vader_c_emit_pc_slot_used_outside_push(void* l0, int32_t l1, int32_t l2, int32_t l3, int32_t l4);
static vader_string_t vader_c_emit_pointer_to(vader_string_t l0, bool l1);
static vader_box_t vader_c_emit_pop(void* l0);
static void* vader_c_emit_pop_args_boxed(void* l0, int32_t l1);
static void* vader_c_emit_precompute_branch_targets(void* l0, void* l1);
static void* vader_c_emit_precompute_scopes(void* l0);
static int32_t vader_c_emit_present_tag(void* l0, uint8_t l1);
static int32_t vader_c_emit_prim_tag(void* l0, uint8_t l1);
static bool vader_c_emit_primitive_matches_type(void* l0, uint8_t l1, int32_t l2);
static int32_t vader_c_emit_primitive_tag_of(void* l0, uint8_t l1);
static void vader_c_emit_push_binop(void* l0, uint8_t l1, uint8_t l2);
static void vader_c_emit_push_binop_any(void* l0, uint8_t l1, uint8_t l2);
static void vader_c_emit_push_cmp(void* l0, uint8_t l1, uint8_t l2);
static void vader_c_emit_push_const(void* l0, vader_box_t l1);
static void vader_c_emit_push_eager(void* l0, uint8_t l1, uint8_t l2);
static void vader_c_emit_push_expr(void* l0, uint8_t l1, vader_box_t l2);
static vader_box_t vader_c_emit_push_helper_for(uint8_t l0);
static void vader_c_emit_push_i64_neg(void* l0);
static void vader_c_emit_push_into_temporary(void* l0, vader_box_t l1, uint8_t l2);
static void vader_c_emit_push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7);
static void vader_c_emit_push_lit(void* l0, uint8_t l1, vader_box_t l2);
static void vader_c_emit_push_local_ref(void* l0, int32_t l1, uint8_t l2);
static void vader_c_emit_push_member_copies(void* l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4, void* l5, int32_t l6);
static void vader_c_emit_push_object(void* l0, vader_box_t l1);
static void vader_c_emit_push_offset_list(void* l0, vader_string_t l1, void* l2);
static void vader_c_emit_push_pool_array(void* l0, void* l1, vader_string_t l2, uint8_t l3, void* l4);
static void vader_c_emit_push_struct_field(void* l0, int32_t l1, int32_t l2, vader_box_t l3, uint8_t l4);
static void vader_c_emit_push_temporary(void* l0, void* l1, uint8_t l2);
static void vader_c_emit_push_unop(void* l0, vader_string_t l1, uint8_t l2);
static vader_box_t vader_c_emit_ref_box(vader_box_t l0);
static bool vader_c_emit_ref_carrying_element(vader_box_t l0, void* l1);
static void vader_c_emit_return_statement(void* l0, void* l1);
static vader_string_t vader_c_emit_sanitise(vader_string_t l0);
static vader_box_t vader_c_emit_scalar_cast(vader_box_t l0, uint8_t l1, uint8_t l2);
static int32_t vader_c_emit_scalar_tag(void* l0, uint8_t l1);
static void* vader_c_emit_scan_fn_value_usage(void* l0);
static vader_box_t vader_c_emit_scope_ending_at(void* l0, int32_t l1);
static vader_box_t vader_c_emit_scope_ending_for_opener(void* l0, int32_t l1);
static void* vader_c_emit_shim_body(void* l0, void* l1);
static void* vader_c_emit_signature_for(void* l0, int32_t l1);
static vader_box_t vader_c_emit_signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3);
static vader_box_t vader_c_emit_single_offset_list(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_c_emit_single_reference_row(size_t l0, vader_string_t l1, vader_string_t l2, int32_t l3, vader_string_t l4);
static vader_box_t vader_c_emit_size_as_address(vader_box_t l0);
static vader_box_t vader_c_emit_slot_index(vader_string_t l0, vader_box_t l1);
static uint8_t vader_c_emit_slot_val_type(void* l0, int32_t l1);
static void* vader_c_emit_sorted_fn_indices(void* l0);
static void* vader_c_emit_sorted_module_stems(void* l0);
static void vader_c_emit_statement_macro(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_c_emit_static_assert(vader_box_t l0, vader_string_t l1);
static int32_t vader_c_emit_string_array_tag(void* l0, int32_t l1);
static int32_t vader_c_emit_string_primitive_tag(void* l0);
static vader_string_t vader_c_emit_struct_c_name(vader_string_t l0);
static void* vader_c_emit_struct_definition(void* l0, void* l1, size_t l2);
static vader_box_t vader_c_emit_struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static vader_box_t vader_c_emit_struct_info_row(void* l0, void* l1, void* l2, size_t l3);
static vader_box_t vader_c_emit_tag_equals(vader_box_t l0, int32_t l1);
static vader_box_t vader_c_emit_tag_expression(vader_box_t l0, uint8_t l1);
static vader_box_t vader_c_emit_tag_of(vader_box_t l0);
static vader_box_t vader_c_emit_trait_check_expr(void* l0, vader_box_t l1, vader_string_t l2, int32_t l3);
static void* vader_c_emit_tramp_unbox_args(void* l0);
static void* vader_c_emit_trampoline_signature(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_c_emit_trap(vader_string_t l0);
static int32_t vader_c_emit_type_id_for_struct_symbol(void* l0, int32_t l1);
static int32_t vader_c_emit_type_index_for_name(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_typed_array_fill_for(uint8_t l0);
static vader_box_t vader_c_emit_typed_slot(vader_string_t l0, vader_string_t l1, vader_box_t l2);
static vader_box_t vader_c_emit_unbox_expr(vader_box_t l0, uint8_t l1);
static void* vader_c_emit_unit_names_of(void* l0, void* l1);
static void vader_c_emit_unreachable(void* l0, vader_string_t l1);
static void* vader_c_emit_user_extern_shim(void* l0, void* l1);
static uint8_t vader_c_emit_val_of(vader_box_t l0);
static uint8_t vader_c_emit_val_type_of_bc_type(vader_box_t l0);
static uint8_t vader_c_emit_val_type_of_field(void* l0, int32_t l1);
static void* vader_c_emit_value_parameters(void* l0, vader_string_t l1);
static vader_string_t vader_c_emit_vtable_helper_name(vader_string_t l0);
static void* vader_c_emit_vtable_sig_for_row(void* l0, void* l1);
static uint8_t vader_c_emit_wrapper_storage(bool l0);
static void vader_c_emit_write_barrier(void* l0, vader_box_t l1);

static vader_box_t vader_c_emit_address_as_size(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_c_ast_cast(2377u, l0);
    t0 = vader_c_emit_c_ast_cast(2141u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_append_statement(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_current_block(l0);
    vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) t0)->f_body, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_argument(size_t l0) {
    void* l1 = NULL;
    size_t l2;
    uint64_t l3;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 21);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1151u);
    t0 = ((int64_t) (size_t) l0);
    l3 = (uint64_t) (int64_t) t0;
    l2 = std_core_write_unsigned(l1, l2, l3);
    t1 = std_core_finish_buffer(l1, l2);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_array_element_tag(void* l0, int32_t l1) {
    size_t l2;
    vader_box_t l3;
    int64_t t0;
    void* t1;
    int32_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l3.tag == 523u)) {
        return l1;
    }
    t1 = l3.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
    return t2;
}

static vader_box_t vader_c_emit_array_header_pointer(vader_box_t l0) {
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &t0, &t1 };
    void** gc_raw_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_object_pointer_of(l0);
    t1 = vader_c_emit_array_pointer(t0);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 740u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_array_pointer(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_cast(2449u, l0);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_array_tag(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 523u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
}

static int32_t vader_c_emit_array_type_index_for_element(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t t0;
    void* t1;
    int32_t t2;
    int64_t t3;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (t0.tag == 523u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            t1 = t0.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
            if (t2 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t3 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t3;
    }
    return INT32_C(0);
}

static vader_box_t vader_c_emit_as_size(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_expression_of(l0);
    t0 = vader_c_emit_c_ast_cast(2141u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_assert_stack_empty(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    size_t l4, l5;
    void* l6 = NULL;
    uint64_t l7;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (!(t0 != INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l1;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
    l4 = vader_host_std_core_byte_len(l2);
    l5 = vader_host_std_core_byte_len(l3);
    t1 = (l4 + l5);
    l4 = (size_t) (int64_t) t1;
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(159) + l4));
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l6, l4, 1373u);
    l4 = std_core_write_string_at(l6, l4, l2);
    l4 = std_core_write_string_at(l6, l4, 83u);
    l4 = std_core_write_string_at(l6, l4, l3);
    l4 = std_core_write_string_at(l6, l4, 846u);
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    t1 = ((int64_t) (size_t) t0);
    l7 = (uint64_t) (int64_t) t1;
    l4 = std_core_write_unsigned(l6, l4, l7);
    l4 = std_core_write_string_at(l6, l4, 253u);
    t2 = std_core_finish_buffer(l6, l4);
    vader_host_std_abort_panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_assign(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CAssign_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
    vader_obj_header_init(_a0_obj, 706u);
    _a0_obj->f_target = l1;
    _a0_obj->f_value = l2;
    _a0_obj->f_operator = vader_box_obj(0u, NULL);
    l3 = (void*) _a0_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_atom_count_define(void* l0) {
    vader_box_t l1 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    l1 = vader_c_emit_c_ast_unsigned(((int64_t) (size_t) t0));
    vader_struct_vader_c_emit_c_ast_CDefine_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CDefine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDefine_t));
    vader_obj_header_init(_a0_obj, 719u);
    _a0_obj->f_name = 747u;
    _a0_obj->f_value = l1;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_atom_for(void* l0, vader_string_t l1) {
    vader_box_t l2;
    int32_t t0;
    l2 = std_collections_MutableMap_Index_at__string__i32(l0, l1);
    if (!(l2.tag == 233u)) {
        return INT32_C(0);
    }
    t0 = ((int32_t) l2.payload.i);
    return t0;
}

static void* vader_c_emit_atom_table_of(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_string_t l5 = 0;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3;
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
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        t2 = t1.payload.s;
        if (t2 != 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
            l5 = t1.payload.s;
            vader_array_push((vader_array_t*) l2, vader_box_string(230u, l5));
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_aux(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    size_t l3;
    void* l4 = NULL;
    int64_t l5;
    int32_t l6;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = vader_host_std_core_byte_len(l2);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l3));
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l4, l3, 823u);
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 786u);
    l3 = std_core_write_string_at(l4, l3, l2);
    l2 = std_core_finish_buffer(l4, l3);
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter;
    l6 = (t0 + INT32_C(1));
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter = l6;
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_bc_struct_fields(void* l0, int32_t l1) {
    bool l2;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((int64_t) (int32_t) l1);
        l3 = (size_t) (int64_t) t0;
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        vader_array_t* _a0_arr = vader_array_new(39u, 0u, 13u, 525u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (!(l5.tag == 536u)) {
        vader_array_t* _a2_arr = vader_array_new(39u, 0u, 13u, 525u);
        t1 = (void*) _a2_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l5.payload.obj;
    { void* __vret = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_bc_struct_name(void* l0, int32_t l1) {
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
    if (!(l5.tag == 536u)) {
        return 0u;
    }
    t1 = l5.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
    return t2;
}

static vader_box_t vader_c_emit_binary_expression(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_operand_as(l0, l4, l2);
    l3 = vader_c_emit_operand_as(l0, l3, l2);
    l3 = vader_c_emit_c_ast_binary(l1, l4, l3);
    if (l1 == INT32_C(11)) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == INT32_C(12))) {
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a0_obj, 740u);
        _a0_obj->f_inner = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_bind_array_local(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_bound_arrays;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = vader_c_emit_c_ast_same_expression(((vader_struct_vader_c_emit_BoundArray_t*) l5)->f_pointer, l1);
        if (t0) {
            t1 = ((vader_struct_vader_c_emit_BoundArray_t*) l5)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    l6 = vader_c_emit_aux(l0, 2149u);
    vader_c_emit_declare(l0, 2449u, l6, l1);
    t3 = vader_c_emit_c_ast_verbatim(l6);
    vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t3.payload.obj;
    l2 = (void*) _a1_arr;
    vader_c_emit_statement_macro(l0, 744u, l2);
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_bound_arrays;
    vader_struct_vader_c_emit_BoundArray_t* _a2_obj = (vader_struct_vader_c_emit_BoundArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_BoundArray_t));
    vader_obj_header_init(_a2_obj, 687u);
    _a2_obj->f_name = l6;
    _a2_obj->f_pointer = l1;
    l5 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_box_call(vader_string_t l0, int32_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    size_t l5;
    int64_t l6;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(2457u, l0);
    l4 = std_core_new_byte_buffer((size_t) 21);
    l5 = (size_t) 0;
    l6 = ((int64_t) (int32_t) l1);
    l5 = std_core_write_int(l4, l5, l6);
    l5 = std_core_write_string_at(l4, l5, 2346u);
    t0 = std_core_finish_buffer(l4, l5);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l4 = (void*) _a0_arr;
    t1 = vader_c_emit_c_ast_call(l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_box_expr(vader_box_t l0, uint8_t l1, int32_t l2) {
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
        l3 = vader_c_emit_box_call(1718u, l2, l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(5)) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(6);
    }
    if (l4) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(7);
    }
    if (l4) {
        vader_array_t* _a0_arr = vader_array_new(10u, 2u, 0u, 230u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(230u, 2374u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(230u, 1806u);
        t0 = (void*) _a0_arr;
        vader_struct_vader_c_emit_c_ast_CCast_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCast_t));
        vader_obj_header_init(_a1_obj, 712u);
        _a1_obj->f_types = t0;
        _a1_obj->f_value = l0;
        l5 = (void*) _a1_obj;
        l3 = vader_c_emit_box_call(1718u, l2, vader_ref_box(l5));
    } else if (l1 == INT32_C(3)) {
        l3 = vader_c_emit_box_call(1740u, l2, l0);
    } else if (l1 == INT32_C(4)) {
        l6 = vader_c_emit_c_ast_cast(1807u, l0);
        l3 = vader_c_emit_box_call(1740u, l2, l6);
    } else {
        if (l1 == INT32_C(8)) {
            l4 = true;
        } else {
            l4 = l1 == INT32_C(9);
        }
        if (l4) {
            vader_array_t* _a2_arr = vader_array_new(10u, 2u, 0u, 230u);
            vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 1u] = vader_box_string(230u, 2375u);
            vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(230u, 1807u);
            t0 = (void*) _a2_arr;
            vader_struct_vader_c_emit_c_ast_CCast_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCast_t));
            vader_obj_header_init(_a3_obj, 712u);
            _a3_obj->f_types = t0;
            _a3_obj->f_value = l0;
            l5 = (void*) _a3_obj;
            l3 = vader_c_emit_box_call(1740u, l2, vader_ref_box(l5));
        } else if (l1 == INT32_C(10)) {
            l6 = vader_c_emit_c_ast_cast(1505u, l0);
            l3 = vader_c_emit_box_call(1600u, l2, l6);
        } else if (l1 == INT32_C(11)) {
            l3 = vader_c_emit_box_call(1600u, l2, l0);
        } else if (l1 == INT32_C(12)) {
            l3 = vader_c_emit_box_call(1306u, l2, l0);
        } else if (l1 == INT32_C(13)) {
            l6 = vader_c_emit_c_ast_cast(1806u, l0);
            l3 = vader_c_emit_box_call(1718u, l2, l6);
        } else if (l1 == INT32_C(14)) {
            l3 = vader_c_emit_box_call(2214u, l2, l0);
        } else {
            if (l1 == INT32_C(15)) {
                l4 = true;
            } else {
                l4 = l1 == INT32_C(19);
            }
            if (l4) {
                l3 = l0;
            } else if (l1 == INT32_C(16)) {
                vader_array_t* _a4_arr = vader_array_new(181u, 0u, 13u, 1359u);
                l5 = (void*) _a4_arr;
                l3 = vader_c_emit_c_ast_call(2459u, l5);
            } else if (l1 == INT32_C(17)) {
                l6 = vader_c_emit_c_ast_cast(1822u, l0);
                l6 = vader_c_emit_c_ast_cast(1807u, l6);
                l3 = vader_c_emit_box_call(1740u, l2, l6);
            } else {
                if (!(l1 == INT32_C(18))) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l3 = vader_c_emit_ref_box(l0);
            }
        }
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_box_expr_unknown(void* l0, vader_box_t l1, uint8_t l2) {
    int32_t l3;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_primitive_tag_of(l0, l2);
    t0 = vader_c_emit_box_expr(l1, l2, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_box_slot(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
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
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    if (l2.tag == 540u) {
        l7 = vader_c_emit_primitive_tag_of(l6, (uint8_t) 14);
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        l9 = vader_c_emit_atom_for(l5, l8);
        t1 = vader_c_emit_boxed_string(l7, l9);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 539u) {
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        l7 = vader_c_emit_scalar_tag(l6, l10);
        t0 = l2.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_bits;
        t1 = vader_c_emit_boxed_scalar(l7, l10, l11);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 541u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_symbol_id;
        l7 = vader_c_emit_type_id_for_struct_symbol(l6, l9);
    } else {
        l7 = l4;
    }
    l12 = l2;
    l12 = vader_c_emit_emit_data_value(l0, l1, l12, l3, l5);
    t1 = vader_c_emit_boxed_object(l7, l12);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_box_slot_1(vader_string_t l0, vader_box_t l1) {
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
    t0 = concat_2(l0, 286u);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = vader_c_emit_c_ast_call(2421u, l2);
    vader_struct_vader_c_emit_c_ast_CIndex_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
    vader_obj_header_init(_a1_obj, 731u);
    _a1_obj->f_base = t1;
    _a1_obj->f_index = l1;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_boxed_object(int32_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t1 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_49;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l4 = vader_c_emit_c_ast_cast(2556u, l1);
    t1 = vader_c_emit_c_ast_designated(309u, l4);
    vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_c_emit_c_ast_initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
    t0 = (void*) _a2_arr;
    t1 = vader_c_emit_c_ast_initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_boxed_parameters(void* l0, size_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l3, l5;
    uint64_t l6;
    vader_string_t l7 = 0;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(60u, 1u, 13u, 739u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        l4 = std_core_new_byte_buffer((size_t) 21);
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l4, l5, 1151u);
        t0 = ((int64_t) (size_t) l3);
        l6 = (uint64_t) (int64_t) t0;
        l5 = std_core_write_unsigned(l4, l5, l6);
        l7 = std_core_finish_buffer(l4, l5);
        vader_struct_vader_c_emit_c_ast_CParameter_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
        vader_obj_header_init(_a1_obj, 739u);
        _a1_obj->f_type = 2462u;
        _a1_obj->f_name = l7;
        l8 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_boxed_scalar(int32_t l0, uint8_t l1, uint64_t l2) {
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
    l3 = vader_c_emit_data_slot(l1, l2);
    if (l1 == INT32_C(9)) {
        l5 = true;
    } else {
        l5 = l1 == INT32_C(10);
    }
    if (l5) {
        l4 = vader_c_emit_c_ast_cast(1505u, l3);
        l4 = vader_c_emit_c_ast_designated(305u, l4);
    } else if (l1 == INT32_C(12)) {
        l4 = vader_c_emit_c_ast_designated(303u, l3);
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
            vader_array_t* _a0_arr = vader_array_new(10u, 3u, 0u, 230u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(230u, 2374u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(230u, 1806u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(230u, 1807u);
            t0 = (void*) _a0_arr;
            l4 = vader_c_emit_integer_payload(t0, l3);
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
                vader_array_t* _a1_arr = vader_array_new(10u, 2u, 0u, 230u);
                vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 1u] = vader_box_string(230u, 1806u);
                vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = vader_box_string(230u, 1807u);
                t0 = (void*) _a1_arr;
                l4 = vader_c_emit_integer_payload(t0, l3);
            } else {
                if (l1 == INT32_C(8)) {
                    l5 = true;
                } else {
                    l5 = l1 == INT32_C(4);
                }
                if (l5) {
                    vader_array_t* _a2_arr = vader_array_new(10u, 1u, 0u, 230u);
                    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(230u, 1807u);
                    t0 = (void*) _a2_arr;
                    l4 = vader_c_emit_integer_payload(t0, l3);
                } else {
                    if (l1 == INT32_C(13)) {
                        l5 = true;
                    } else {
                        l5 = l1 == INT32_C(0);
                    }
                    if (!(l5)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l6 = vader_bytecode_array_kind_name(l1);
                    t1 = concat_3(1370u, l6, 843u);
                    vader_host_std_abort_panic(t1);
                    vader_unreachable("a no-return call returned");
                }
            }
        }
    }
    l3 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_49;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l4.payload.obj;
    t0 = (void*) _a4_arr;
    l4 = vader_c_emit_c_ast_initializer_list(t0);
    vader_array_t* _a5_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l7;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l3.payload.obj;
    t0 = (void*) _a5_arr;
    t2 = vader_c_emit_c_ast_initializer_list(t0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_boxed_string(int32_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l0));
    t0 = (void*) &vader_data_49;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l4 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l1));
    t1 = vader_c_emit_c_ast_designated(312u, l4);
    vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l4 = vader_c_emit_c_ast_initializer_list(t0);
    vader_array_t* _a2_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
    t0 = (void*) _a2_arr;
    t1 = vader_c_emit_c_ast_initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_branch_target(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    bool t1;
    int64_t t2;
    int32_t t3;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = vader_c_emit_is_continue_branch(t0, l1);
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            return vader_ref_box(t0);
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        t3 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_end_pc;
        if ((t3 + INT32_C(1)) == l1) {
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
            return vader_ref_box(t0);
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_c_emit_buffer_pointer(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_object_pointer_of(l0);
    t0 = vader_c_emit_c_ast_cast(2475u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_build_string_atom_map(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    int32_t l7;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 7u, 233u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 7u, 233u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 366u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_strings;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l2)->length;
    while ((l4 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
        l6 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_ids);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
        l7 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
        std_collections_MutableMap_IndexSet_set_at__string__i32(l1, l6, l7);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_c_field_name(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_name;
    return t0;
}

static vader_string_t vader_c_emit_c_string_lit(vader_string_t l0) {
    size_t l1, l3, l8;
    void* l2 = NULL;
    uint8_t l4, l6, l7;
    bool l5;
    uint32_t t0;
    int32_t t1;
    int64_t t2;
    uint8_t t3;
    bool t4;
    vader_string_t t5 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 1u, 236u);
    l2 = (void*) _a0_arr;
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        l4 = vader_host_std_core_byte_at(l0, l3);
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
                t0 = std_numbers_hex_digit((((int64_t) (uint8_t) l4) >> INT64_C(4)));
                t1 = (((int32_t) (uint32_t) t0) & INT32_C(255));
                l6 = (uint8_t) (int32_t) t1;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l6);
                t0 = std_numbers_hex_digit((uint64_t) (int64_t) (((int64_t) (uint8_t) l4) & INT64_C(15)));
                t1 = (((int32_t) (uint32_t) t0) & INT32_C(255));
                l7 = (uint8_t) (int32_t) t1;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l7);
                t2 = (l3 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                if ((l8 < l1)) {
                    t3 = vader_host_std_core_byte_at(l0, l8);
                    t4 = std_numbers_is_hex_digit(((uint32_t) (int32_t) ((int32_t) (uint8_t) t3)));
                    if (t4) {
                        vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
                        vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
                    }
                }
            } else {
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
            }
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    t5 = vader_host_std_core_bytes_to_string(l2);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_c_struct_layout_asserts(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l21 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l20 = vader_box_null();
    int32_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l15 = 0;
    vader_string_t l19 = 0;
    vader_string_t l22 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    size_t t3;
    bool t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[9] = { &l6, &l12, &l13, &l14, &l16, &l17, &l18, &l20, &t5 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l10, &l11, &l21, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l9, &l15, &l19, &l22, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 9u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_nested_member_mirrors(l0);
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l6.tag == 536u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
            if (t1 == 0u) {
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                continue;
            }
            t0 = l6.payload.obj;
            t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields)->length;
            if (t3 == INT64_C(0)) {
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                continue;
            }
            l7 = ((int32_t) (size_t) l4);
            t4 = std_collections_MutableSet_Contains_contains__i32(l3, l7);
            if (t4) {
                l8 = ((int32_t) (size_t) l4);
                t4 = std_collections_MutableSet_Contains_contains__i32(l1, l8);
                if (!(t4)) {
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    continue;
                }
            }
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            l9 = vader_c_emit_struct_c_name(t1);
            t0 = l6.payload.obj;
            l10 = vader_bytecode_c_struct_layout(((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields, l0);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
            t5 = vader_c_emit_c_ast_verbatim(t1);
            vader_array_t* _a2_arr = vader_array_new(181u, 1u, 13u, 1359u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t5.payload.obj;
            l11 = (void*) _a2_arr;
            l12 = vader_c_emit_c_ast_call(2142u, l11);
            t2 = ((vader_struct_vader_bytecode_CLayout_t*) l10)->f_size;
            l13 = vader_c_emit_c_ast_number(t2);
            l14 = vader_c_emit_c_ast_binary((uint8_t) 8, l13, l12);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
            l15 = concat_2(t1, 120u);
            l16 = vader_c_emit_static_assert(l14, l15);
            vader_array_push((vader_array_t*) l2, l16);
            l17 = vader_c_emit_c_ast_number(INT64_C(4096));
            l18 = vader_c_emit_c_ast_binary((uint8_t) 8, l12, l17);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
            l19 = concat_2(t1, 71u);
            l20 = vader_c_emit_static_assert(l18, l19);
            vader_array_push((vader_array_t*) l2, l20);
            t0 = l6.payload.obj;
            l21 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
            t0 = l6.payload.obj;
            l22 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
            vader_c_emit_push_leaf_asserts(l0, l21, l22, 0u, l9, INT64_C(0), l2, INT32_C(0));
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            continue;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_c_type_for(vader_box_t l0) {
    uint8_t t0;
    vader_string_t t1;
    t0 = vader_c_emit_val_type_of_bc_type(l0);
    t1 = vader_c_emit_c_type_for_val_bare(t0);
    return t1;
}

static vader_string_t vader_c_emit_c_type_for_array_kind(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(1)) {
        l1 = 2376u;
        return l1;
    }
    if (l0 == INT32_C(2)) {
        l1 = 2373u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2374u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2375u;
    } else if (l0 == INT32_C(5)) {
        l1 = 1808u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1805u;
    } else if (l0 == INT32_C(7)) {
        l1 = 1806u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1807u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1651u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1505u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2374u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2376u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2556u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2462u;
    }
    return l1;
}

static vader_string_t vader_c_emit_c_type_for_val_bare(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1808u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1805u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1806u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1807u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2376u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2373u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2374u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2375u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2141u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2061u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1651u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1505u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1306u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2374u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2526u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2462u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2555u;
    } else if (l0 == INT32_C(17)) {
        l1 = 2556u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2556u;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2462u;
    }
    return l1;
}

static int32_t vader_c_emit_callee_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 558u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 587u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        return t1;
    }
    if (!(l0.tag == 586u)) {
        return -(INT32_C(1));
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
    return t1;
}

static size_t vader_c_emit_callee_result_arity(void* l0, vader_box_t l1) {
    size_t l2, l3;
    void* l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    size_t t3;
    if (l1.tag == 558u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        t2 = ((int64_t) (int32_t) t1);
        l2 = (size_t) (int64_t) t2;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions)->length;
        if (!((l2 >= l3))) {
            l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
            t2 = ((int64_t) (int32_t) t1);
            l2 = (size_t) (int64_t) t2;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            t3 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_signature);
            return t3;
        }
        return (size_t) 1;
    }
    if (!(l1.tag == 559u)) {
        return (size_t) 1;
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
    t2 = ((int64_t) (int32_t) t1);
    l2 = (size_t) (int64_t) t2;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports)->length;
    if (!((l2 >= l3))) {
        l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t2 = ((int64_t) (int32_t) t1);
        l2 = (size_t) (int64_t) t2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t3 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcImport_t*) t0)->f_signature);
        return t3;
    }
    return (size_t) 1;
}

static void* vader_c_emit_classify_struct_fields(void* l0, void* l1, size_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l5, l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    bool t5;
    uint8_t t6;
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l7, &l8, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l11, &l12, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l3 = t0.payload.s;
    l4 = vader_c_emit_empty_struct_offsets();
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        t1 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
        t2 = ((int64_t) (int32_t) t1);
        l9 = (size_t) (int64_t) t2;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        t3 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
        l11 = vader_c_emit_sanitise(t3);
        l12 = concat_5(2012u, l3, 276u, l11, 241u);
        if (l10.tag == 532u) {
            t4 = l10.payload.obj;
            t5 = vader_bytecode_is_string_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t4)->f_val);
            if (t5) {
                vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_str_offsets, vader_box_string(230u, l12));
            }
        } else {
            t6 = vader_c_emit_val_type_of_bc_type(l10);
            if (t6 == INT32_C(18)) {
                vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_ref_offsets, vader_box_string(230u, l12));
            } else {
                vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_ptr_offsets, vader_box_string(230u, l12));
            }
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_close_node(void* l0, vader_string_t l1) {
    void* l2;
    size_t l3;
    vader_box_t l4;
    size_t t0;
    int64_t t1;
    void* t2;
    vader_box_t t3;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
    t1 = (t0 - INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 729u) {
        t2 = l4.payload.obj;
        ((vader_struct_vader_c_emit_c_ast_CIf_t*) t2)->f_end_label = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_c_ast_CIf_t*) t2);
        t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes);
        return;
    }
    t2 = l4.payload.obj;
    ((vader_struct_vader_c_emit_c_ast_CScope_t*) t2)->f_end_label = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_c_ast_CScope_t*) t2);
    t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes);
    return;
}

static vader_box_t vader_c_emit_coerce_expr(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
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
    if (l3 == INT32_C(18)) {
        if (l2 == INT32_C(19)) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(15);
        }
        if (!(l4)) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_c_emit_payload(l1, 2008u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(18)) {
        t1 = vader_c_emit_is_ref_val(l3);
        if (!(t1)) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_c_emit_ref_box(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l3);
    if (t1) {
        t1 = vader_c_emit_is_ref_val(l2);
        if (t1) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = vader_c_emit_is_ref_val(l3);
    if (t1) {
        t0 = vader_c_emit_box_expr_unknown(l0, l1, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l2);
    if (!(t1)) {
        t0 = vader_c_emit_scalar_cast(l1, l2, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_unbox_expr(l1, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_coerce_operand(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_is_ref_val(l2);
    if (!(t0)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_coerce_expr(l0, l1, l2, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_coerced_as(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    uint8_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l4 = vader_c_emit_expression_of(l1);
    l5 = vader_c_emit_val_of(l1);
    t0 = vader_c_emit_coerce_expr(l3, l4, l5, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_compute_atom_ids(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l3;
    size_t l4, l5;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t l10 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_iter_is_empty__string(l1);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
        l2 = (void*) _a0_arr;
        l3 = INT32_C(1);
        l4 = (size_t) 0;
        l5 = ((vader_array_t*) l0)->length;
        vader_array_t* _pc12_hdr = (vader_array_t*) l2;
        size_t _pc12_len = _pc12_hdr->length;
        size_t _pc12_cap = (_pc12_hdr->offset == 0 && !vader_array_is_borrowed(_pc12_hdr) && _pc12_hdr->length >= _pc12_hdr->buf->length) ? _pc12_hdr->capacity : (size_t) 0;
        void* _pc12_slots = _pc12_hdr->buf->slots;
        for (;;) {
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
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
                    l3 = (l3 + INT32_C(1));
                }
                t3 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t3;
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
    vader_array_t* _a2_arr = vader_array_new(10u, 0u, 0u, 230u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(11u, 0u, 7u, 233u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(11u, 0u, 7u, 233u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 366u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a5_obj;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l1)->length;
    while ((l4 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l4];
        l8 = t1.payload.s;
        t1 = std_collections_MutableMap_Index_at__string__i32(l2, l8);
        if (t1.tag == 0u) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l4];
            l9 = t1.payload.s;
            l3 = (((int32_t) (size_t) l4) + INT32_C(1));
            std_collections_MutableMap_IndexSet_set_at__string__i32(l2, l9, l3);
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a8_arr = vader_array_new(11u, 0u, 7u, 233u);
    l6 = (void*) _a8_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
        t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l4];
        t2 = t1.payload.s;
        if (t2 == 0u) {
            vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        } else {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l4)
            t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l4];
            l8 = t1.payload.s;
            l10 = std_collections_MutableMap_Index_at__string__i32(l2, l8);
            if (l10.tag == 0u) {
                l3 = INT32_C(0);
            } else {
                l3 = ((int32_t) l10.payload.i);
            }
            vader_array_push_i32((vader_array_t*) l6, l3);
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_compute_may_alloc(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5, l7;
    bool l6;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _pc7_hdr = (vader_array_t*) l2;
    size_t _pc7_len = _pc7_hdr->length;
    size_t _pc7_cap = (_pc7_hdr->offset == 0 && !vader_array_is_borrowed(_pc7_hdr) && _pc7_hdr->length >= _pc7_hdr->buf->length) ? _pc7_hdr->capacity : (size_t) 0;
    void* _pc7_slots = _pc7_hdr->buf->slots;
    for (;;) {
        if ((l3 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t1 = vader_c_emit_fn_has_direct_alloc(t0, l1);
            if (t1) {
                l5 = ((int32_t) (size_t) l3);
                if (VADER_LIKELY(_pc7_len < _pc7_cap)) {
                    ((int32_t*) _pc7_slots)[_pc7_len] = (int32_t) (l5);
                    _pc7_len += 1;
                } else {
                    _pc7_hdr->length = _pc7_len;
                    if (_pc7_hdr->buf->length < _pc7_len) {
                        _pc7_hdr->buf->length = _pc7_len;
                    }
                    vader_array_push_i32((vader_array_t*) l2, l5);
                    _pc7_hdr = (vader_array_t*) l2;
                    _pc7_len = _pc7_hdr->length;
                    _pc7_cap = (_pc7_hdr->offset == 0 && !vader_array_is_borrowed(_pc7_hdr) && _pc7_hdr->length >= _pc7_hdr->buf->length) ? _pc7_hdr->capacity : (size_t) 0;
                    _pc7_slots = _pc7_hdr->buf->slots;
                }
            }
            t2 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t2;
            continue;
        }
        _pc7_hdr->length = _pc7_len;
        if (_pc7_hdr->buf->length < _pc7_len) {
            _pc7_hdr->buf->length = _pc7_len;
        }
        break;
    }
    l6 = true;
    while (l6) {
        l6 = false;
        l3 = (size_t) 0;
        l4 = ((vader_array_t*) l0)->length;
        while ((l3 < l4)) {
            l5 = ((int32_t) (size_t) l3);
            t1 = std_core____Contains_contains__i32(l2, l5);
            if (t1) {
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t1 = vader_c_emit_fn_calls_may_alloc(t0, l2);
            if (t1) {
                l7 = ((int32_t) (size_t) l3);
                vader_array_push_i32((vader_array_t*) l2, l7);
                l6 = true;
            }
            t2 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t2;
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_const_lit_c(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6, l9;
    uint64_t l7;
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
    if (l1.tag == 593u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        l3 = ((int64_t) (int32_t) t1);
        vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t));
        vader_obj_header_init(_a0_obj, 733u);
        _a0_obj->f_class = (uint8_t) 2;
        _a0_obj->f_value = l3;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 613u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t));
        vader_obj_header_init(_a1_obj, 733u);
        _a1_obj->f_class = (uint8_t) 3;
        _a1_obj->f_value = l3;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l1.tag == 574u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        t3 = vader_c_emit_float_lit(t2);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else if (l1.tag == 546u) {
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        if (t4) {
            l4 = 2313u;
        } else {
            l4 = 1616u;
        }
        l2 = vader_c_emit_c_ast_verbatim(l4);
    } else if (l1.tag == 561u) {
        l5 = std_core_new_byte_buffer((size_t) 21);
        l6 = (size_t) 0;
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        t6 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        l7 = (uint64_t) (int64_t) t6;
        l6 = std_core_write_unsigned(l5, l6, l7);
        l6 = std_core_write_string_at(l5, l6, 2346u);
        t3 = std_core_finish_buffer(l5, l6);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else if (l1.tag == 644u) {
        l5 = std_core_new_byte_buffer((size_t) 42);
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l5, l6, 2461u);
        t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_null_tag;
        l3 = ((int64_t) (int32_t) t1);
        l6 = std_core_write_int(l5, l6, l3);
        l6 = std_core_write_string_at(l5, l6, 2349u);
        t3 = std_core_finish_buffer(l5, l6);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else {
        if (!(l1.tag == 662u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = std_core_new_byte_buffer((size_t) 21);
        l6 = (size_t) 0;
        l8 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_ids;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StringConst_t*) t0)->f_index;
        t6 = ((int64_t) (int32_t) t1);
        l9 = (size_t) (int64_t) t6;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9];
        l3 = ((int64_t) (int32_t) t1);
        l6 = std_core_write_int(l5, l6, l3);
        l6 = std_core_write_string_at(l5, l6, 2346u);
        t3 = std_core_finish_buffer(l5, l6);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_const_val(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 593u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 613u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 574u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 546u) {
        l1 = (uint8_t) 12;
    } else if (l0.tag == 561u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 644u) {
        l1 = (uint8_t) 19;
    } else {
        if (!(l0.tag == 662u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 14;
    }
    return l1;
}

static uint8_t vader_c_emit_convert_target_val(uint8_t l0) {
    uint8_t l1;
    if (l0 == INT32_C(0)) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = (uint8_t) 3;
    } else if (l0 == INT32_C(2)) {
        l1 = (uint8_t) 11;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 13;
    }
    return l1;
}

static void* vader_c_emit_crossing_mirrors(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5, l7, l8;
    int32_t l9;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    int64_t t3;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 12u, 228u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 7u, 233u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 312u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 400u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_is_extern;
        if (t1) {
            l6 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_signature)->f_param_types;
            l7 = ((vader_array_t*) l6)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
                t2 = vader_c_emit_mirrored_c_struct(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types, l9);
                if (t2 != 0u) {
                    std_collections_add__i32(l1, l9);
                }
                t3 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t3;
            }
            t3 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            continue;
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_current_block(void* l0) {
    void* l1;
    size_t l2;
    vader_box_t l3, l4;
    size_t t0;
    int64_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
    if (t0 == INT64_C(0)) {
        return ((vader_struct_vader_c_emit_FnState_t*) l0)->f_root;
    }
    l1 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
    t1 = (t0 - INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l3.tag == 729u)) {
        t2 = l3.payload.obj;
        return ((vader_struct_vader_c_emit_c_ast_CScope_t*) t2)->f_body;
    }
    t2 = l3.payload.obj;
    l4 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t2)->f_else_block;
    if (l4.tag == 0u) {
        t2 = l3.payload.obj;
        return ((vader_struct_vader_c_emit_c_ast_CIf_t*) t2)->f_then_block;
    }
    t2 = l4.payload.obj;
    return t2;
}

static vader_box_t vader_c_emit_data_slot(uint8_t l0, uint64_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    size_t l5;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l6, &t1 };
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_type_for_array_kind(l0);
    if (l0 == INT32_C(10)) {
        t0 = vader_c_emit_float_lit((((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l1) }).__vd));
        l3 = vader_c_emit_c_ast_verbatim(t0);
        t1 = vader_c_emit_c_ast_cast(l2, l3);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(9))) {
        l4 = std_core_new_byte_buffer((size_t) 20);
        l5 = (size_t) 0;
        l5 = std_core_write_unsigned(l4, l5, l1);
        t0 = std_core_finish_buffer(l4, l5);
        t1 = vader_c_emit_c_ast_verbatim(t0);
        vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
        l4 = (void*) _a0_arr;
        l6 = vader_c_emit_c_ast_call(738u, l4);
        t1 = vader_c_emit_c_ast_cast(l2, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_float_lit(((double) (float) (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(((int32_t) (uint64_t) l1)) }).__vf)));
    l3 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_cast(l2, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_declare(void* l0, vader_string_t l1, vader_string_t l2, vader_box_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_c_ast_declaration(l1, l2, l3);
    vader_c_emit_append_statement(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_directive(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CDirective_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CDirective_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDirective_t));
    vader_obj_header_init(_a0_obj, 721u);
    _a0_obj->f_text = l1;
    l2 = (void*) _a0_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_c_emit_dispatcher_parameters(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CParameter_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
    vader_obj_header_init(_a0_obj, 739u);
    _a0_obj->f_type = 2462u;
    _a0_obj->f_name = 2080u;
    l1 = (void*) _a0_obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_params)->length;
    t1 = (t0 - INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    t2 = vader_c_emit_boxed_parameters(l1, l2);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_dispatcher_result(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
    bool l4;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l3 == INT32_C(19)) {
        l4 = l2 != INT32_C(19);
    } else {
        l4 = false;
    }
    if (l4) {
        l4 = l2 != INT32_C(16);
    } else {
        l4 = false;
    }
    if (l4) {
        t0 = vader_c_emit_coerce_expr(l0, l1, l2, (uint8_t) 19);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_dispatcher_signature(void* l0, vader_string_t l1, void* l2) {
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
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l3 = vader_c_emit_wrapper_storage(t0);
    t1 = vader_bytecode_bc_single_result(l2);
    l4 = vader_c_emit_c_type_for_val_bare(t1);
    l5 = vader_c_emit_vtable_helper_name(l1);
    l6 = vader_c_emit_dispatcher_parameters(l2);
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a0_obj, 747u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline_v = false;
    _a0_obj->f_result = l4;
    _a0_obj->f_name = l5;
    _a0_obj->f_parameters = l6;
    t2 = (void*) _a0_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_div_mod_helper(uint8_t l0, uint8_t l1) {
    bool l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(2)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(3);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(8);
    }
    if (l2) {
        if (l0 == INT32_C(1)) {
            l3 = 1500u;
        } else {
            l3 = 1960u;
        }
        l4 = vader_bytecode_val_type_name(l1);
        t0 = concat_4(2420u, l3, 786u, l4);
        t1 = vader_box_string(230u, t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_c_emit_drop_bound_for_local(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(50u, 0u, 13u, 687u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_bound_arrays;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_BoundArray_t*) l6)->f_pointer, l1);
        if (!(t0)) {
            vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_bound_arrays = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_drop_top(void* l0) {
    size_t l1;
    void* l2 = NULL;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
        t0 = (l1 - INT64_C(1));
        l1 = (size_t) (int64_t) t0;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l1);
        l2 = (void*) _a0_arr;
        ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_c_emit_element_storage_kind(void* l0) {
    size_t t0;
    vader_box_t t1;
    void* t2;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        return (uint8_t) 0;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    if (!(t1.tag == 539u)) {
        return (uint8_t) 0;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    t2 = t1.payload.obj;
    return ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_kind;
}

static void vader_c_emit_emit_agg_data_entry(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l11 = NULL;
    size_t l6, l7, l10, l12;
    vader_box_t l8 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l14 = 0;
    uint64_t l13;
    int32_t l15;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l8, &l16 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l3)->f_elements)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l6);
    l5 = (void*) _a1_arr;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l3)->f_elements)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l3)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_vader_c_emit_PoolArray_t*) l2)->f_name;
        l10 = vader_host_std_core_byte_len(l9);
        l11 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l10));
        l12 = (size_t) 0;
        l12 = std_core_write_string_at(l11, l12, l9);
        l12 = std_core_write_string_at(l11, l12, 828u);
        t0 = ((int64_t) (size_t) l6);
        l13 = (uint64_t) (int64_t) t0;
        l12 = std_core_write_unsigned(l11, l12, l13);
        l14 = std_core_finish_buffer(l11, l12);
        l15 = ((vader_struct_vader_c_emit_PoolArray_t*) l2)->f_element_tag;
        l16 = vader_c_emit_box_slot(l0, l1, l8, l14, l15, l4);
        vader_array_push((vader_array_t*) l5, l16);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    vader_c_emit_push_pool_array(l1, l2, 2462u, (uint8_t) 0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_clear(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_object_pointer_of(t0);
    t0 = vader_c_emit_array_pointer(t1);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2424u, l1);
    vader_c_emit_evaluate(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_copy(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l1, &l2, &l3, &l4, &l5, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_object_pointer_of(t0);
    l5 = vader_c_emit_array_pointer(t1);
    l4 = vader_c_emit_as_size(l4);
    t0 = vader_c_emit_object_pointer_of(l3);
    l3 = vader_c_emit_array_pointer(t0);
    l2 = vader_c_emit_as_size(l2);
    l1 = vader_c_emit_as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(181u, 5u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2425u, l6);
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null(), l14 = vader_box_null(), l16 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    size_t l6;
    uint8_t l8, l12;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    int64_t l15;
    int64_t t0;
    bool t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l7, &l9, &l14, &l16 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l13, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = ((vader_struct_vader_bytecode_ArrayGet_t*) l1)->f_type_id;
    l5 = vader_c_emit_array_element_tag(l4, l5);
    t0 = ((int64_t) (int32_t) l5);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l8 = vader_bytecode_array_kind_of(l7, l4);
    l9 = vader_c_emit_typed_array_fill_for(l8);
    l10 = ((vader_struct_vader_bytecode_ArrayGet_t*) l1)->f_bounds_safe;
    l11 = vader_c_emit_emit_slot_array_local(l0, l3, l2, l10);
    if (l9.tag == 0u) {
        t1 = vader_c_emit_ref_carrying_element(l7, l4);
        if (t1) {
            l12 = vader_c_emit_val_type_of_bc_type(l7);
            if (l12 == INT32_C(18)) {
                l13 = 2442u;
            } else {
                l13 = 2441u;
            }
            t2 = concat_2(l11, 286u);
            l3 = vader_c_emit_c_ast_verbatim(t2);
            l7 = vader_c_emit_slot_index(l11, l2);
            vader_array_t* _a1_arr = vader_array_new(181u, 2u, 13u, 1359u);
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l7.payload.obj;
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
            l4 = (void*) _a1_arr;
            l3 = vader_c_emit_c_ast_call(l13, l4);
            vader_c_emit_push_into_temporary(l0, l3, l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l9.tag == 0u) {
        l7 = vader_c_emit_slot_index(l11, l2);
        l3 = vader_c_emit_box_slot_1(l11, l7);
        l12 = (uint8_t) 19;
        vader_c_emit_push_into_temporary(l0, l3, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l8 == INT32_C(1)) {
        l7 = vader_c_emit_c_ast_verbatim(l11);
        l14 = vader_c_emit_slot_index(l11, l2);
        l4 = std_core_new_byte_buffer((size_t) 21);
        l6 = (size_t) 0;
        l15 = ((int64_t) (int32_t) l5);
        l6 = std_core_write_int(l4, l6, l15);
        l6 = std_core_write_string_at(l4, l6, 2346u);
        t2 = std_core_finish_buffer(l4, l6);
        l16 = vader_c_emit_c_ast_verbatim(t2);
        vader_array_t* _a2_arr = vader_array_new(181u, 3u, 13u, 1359u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l16.payload.obj;
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l14.payload.obj;
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l7.payload.obj;
        l4 = (void*) _a2_arr;
        l3 = vader_c_emit_c_ast_call(2440u, l4);
    } else {
        t3 = l9.payload.obj;
        l13 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_cty;
        l2 = vader_c_emit_slot_index(l11, l2);
        l2 = vader_c_emit_typed_slot(l13, l11, l2);
        t3 = l9.payload.obj;
        l8 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_val;
        l3 = vader_c_emit_box_expr(l2, l8, l5);
    }
    l12 = (uint8_t) 19;
    vader_c_emit_push_into_temporary(l0, l3, l12);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_len(void* l0) {
    void* l1 = NULL;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_array_header_pointer(t0);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 736u);
    _a0_obj->f_base = t1;
    _a0_obj->f_member = 1886u;
    _a0_obj->f_arrow = true;
    l1 = (void*) _a0_obj;
    vader_c_emit_push_into_temporary(l0, vader_ref_box(l1), (uint8_t) 9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_new(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3, l6, l7;
    size_t l4;
    uint8_t l5, l16;
    vader_string_t l8 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    int64_t l9;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[13] = {
        &l10, &l11, &l12, &l13, &l17, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &t1,
    };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l14, &l15, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 13u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_type_id;
    l3 = vader_c_emit_array_element_tag(l2, l3);
    t0 = ((int64_t) (int32_t) l3);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = vader_bytecode_array_kind_of(t1, l2);
    l6 = vader_bytecode_array_kind_index(l5);
    l7 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_length;
    l8 = vader_c_emit_aux(l0, 1244u);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    t2 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_type_id;
    l9 = ((int64_t) (int32_t) t2);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2346u);
    t3 = std_core_finish_buffer(l2, l4);
    l10 = vader_c_emit_c_ast_verbatim(t3);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l9 = ((int64_t) (int32_t) l7);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2346u);
    t3 = std_core_finish_buffer(l2, l4);
    l11 = vader_c_emit_c_ast_verbatim(t3);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l9 = ((int64_t) (int32_t) l6);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2346u);
    t3 = std_core_finish_buffer(l2, l4);
    l12 = vader_c_emit_c_ast_verbatim(t3);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l9 = ((int64_t) (int32_t) l3);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2346u);
    t3 = std_core_finish_buffer(l2, l4);
    l13 = vader_c_emit_c_ast_verbatim(t3);
    vader_array_t* _a1_arr = vader_array_new(181u, 4u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 3u] = l13.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l11.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l10.payload.obj;
    l2 = (void*) _a1_arr;
    l10 = vader_c_emit_c_ast_call(2427u, l2);
    vader_c_emit_declare(l0, 2449u, l8, l10);
    l10 = vader_c_emit_typed_array_fill_for(l5);
    l3 = INT32_C(0);
    while ((l3 < l7)) {
        l11 = vader_c_emit_pop(l0);
        l6 = ((l7 - INT32_C(1)) - l3);
        if (l10.tag == 0u) {
            if (l5 == INT32_C(13)) {
                l19 = vader_c_emit_fresh_slot(l8, l6);
                l20 = vader_c_emit_typed_slot(2556u, l8, l19);
                l21 = vader_c_emit_coerced_as(l0, l11, (uint8_t) 18);
                vader_c_emit_assign(l0, l20, l21);
            } else {
                l22 = vader_c_emit_fresh_slot(l8, l6);
                l23 = vader_c_emit_box_slot_1(l8, l22);
                l24 = vader_c_emit_coerced_as(l0, l11, (uint8_t) 19);
                vader_c_emit_assign(l0, l23, l24);
            }
        } else {
            t4 = l10.payload.obj;
            l14 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_cty;
            l12 = vader_c_emit_fresh_slot(l8, l6);
            l13 = vader_c_emit_typed_slot(l14, l8, l12);
            t4 = l10.payload.obj;
            l15 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_cty;
            t4 = l10.payload.obj;
            l16 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_val;
            l17 = vader_c_emit_coerced_as(l0, l11, l16);
            l18 = vader_c_emit_c_ast_cast(l15, l17);
            vader_c_emit_assign(l0, l13, l18);
        }
        l3 = (l3 + INT32_C(1));
    }
    l10 = vader_c_emit_c_ast_verbatim(l8);
    vader_c_emit_push_object(l0, l10);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l9 = vader_box_null(), l13 = vader_box_null();
    void* l4 = NULL;
    void* l14 = NULL;
    size_t l6;
    uint8_t l7, l10;
    int32_t l8;
    bool l11;
    vader_string_t l12 = 0;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    void* t5 = NULL;
    bool t4;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l5, &l9, &l13, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l14, &t3, &t5 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_c_emit_object_pointer_of(l3);
    t0 = ((vader_struct_vader_bytecode_ArrayPush_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l6 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l7 = vader_bytecode_array_kind_of(t2, l4);
    l8 = ((vader_struct_vader_bytecode_ArrayPush_t*) l1)->f_cache_slot;
    l9 = vader_c_emit_pc_active_for(l0, l8);
    if (!(l9.tag == 0u)) {
        t3 = l9.payload.obj;
        l8 = ((vader_struct_vader_c_emit_PushCache_t*) t3)->f_slot;
        t4 = vader_c_emit_pc_operand_is_slot(l3, l8);
        if (t4) {
            t3 = l9.payload.obj;
            t5 = vader_c_emit_pc_fill_of(((vader_struct_vader_c_emit_PushCache_t*) t3)->f_kind);
            l10 = ((vader_struct_vader_c_emit_SlotFill_t*) t5)->f_val;
            l4 = l9.payload.obj;
            l3 = vader_c_emit_coerced_as(l0, l2, l10);
            vader_c_emit_pc_emit_push(l0, l4, l5, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l3 = vader_c_emit_push_helper_for(l7);
    l9 = vader_c_emit_typed_array_fill_for(l7);
    if (l3.tag == 0u) {
        l11 = true;
    } else {
        l11 = l9.tag == 0u;
    }
    if (!(l11)) {
        l12 = l3.payload.s;
        l13 = vader_c_emit_array_pointer(l5);
        t3 = l9.payload.obj;
        l7 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_val;
        l9 = vader_c_emit_coerced_as(l0, l2, l7);
        vader_array_t* _a1_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l13.payload.obj;
        l14 = (void*) _a1_arr;
        l9 = vader_c_emit_c_ast_call(l12, l14);
        vader_c_emit_evaluate(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_c_emit_array_pointer(l5);
    l2 = vader_c_emit_coerced_as(l0, l2, (uint8_t) 19);
    vader_array_t* _a2_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a2_arr;
    l2 = vader_c_emit_c_ast_call(2429u, l4);
    vader_c_emit_evaluate(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_push_all(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_object_pointer_of(t0);
    l2 = vader_c_emit_array_pointer(t1);
    t0 = vader_c_emit_object_pointer_of(l1);
    l1 = vader_c_emit_array_pointer(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2430u, l3);
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_remove_last(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_object_pointer_of(t0);
    t0 = vader_c_emit_array_pointer(t1);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2445u, l1);
    vader_c_emit_push_into_temporary(l0, l2, (uint8_t) 19);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_repeat(void* l0) {
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
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_aux(l0, 1244u);
    t0 = vader_c_emit_object_pointer_of(l2);
    l2 = vader_c_emit_array_pointer(t0);
    l1 = vader_c_emit_as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2446u, l4);
    vader_c_emit_declare(l0, 2449u, l3, l1);
    l1 = vader_c_emit_c_ast_verbatim(l3);
    vader_c_emit_push_object(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_set(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l12 = vader_box_null();
    void* l5 = NULL;
    int32_t l6;
    size_t l7;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    uint8_t l14;
    int32_t t0;
    int64_t t1;
    uint8_t t2;
    bool t3;
    vader_string_t t4 = 0;
    void* t5 = NULL;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l4, &l8, &l9, &l12 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t5 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l13, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = ((vader_struct_vader_bytecode_ArraySet_t*) l1)->f_type_id;
    t0 = vader_c_emit_array_element_tag(l5, l6);
    t1 = ((int64_t) (int32_t) t0);
    l7 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    t2 = vader_bytecode_array_kind_of(l8, l5);
    l9 = vader_c_emit_typed_array_fill_for(t2);
    l10 = ((vader_struct_vader_bytecode_ArraySet_t*) l1)->f_bounds_safe;
    l11 = vader_c_emit_emit_slot_array_local(l0, l4, l3, l10);
    if (l9.tag == 0u) {
        t3 = vader_c_emit_ref_carrying_element(l8, l5);
        if (t3) {
            if (l8.tag == 533u) {
                t4 = concat_2(l11, 286u);
                l4 = vader_c_emit_c_ast_verbatim(t4);
                l8 = vader_c_emit_slot_index(l11, l3);
                l12 = vader_c_emit_coerced_as(l0, l2, (uint8_t) 19);
                vader_array_t* _a1_arr = vader_array_new(181u, 3u, 13u, 1359u);
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l12.payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l8.payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
                l5 = (void*) _a1_arr;
                l4 = vader_c_emit_c_ast_call(2444u, l5);
                vader_c_emit_evaluate(l0, l4);
            } else {
                t4 = concat_2(l11, 286u);
                l4 = vader_c_emit_c_ast_verbatim(t4);
                l8 = vader_c_emit_slot_index(l11, l3);
                l12 = vader_c_emit_object_pointer_of(l2);
                vader_array_t* _a2_arr = vader_array_new(181u, 3u, 13u, 1359u);
                ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l12.payload.obj;
                ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l8.payload.obj;
                ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l4.payload.obj;
                l5 = (void*) _a2_arr;
                l4 = vader_c_emit_c_ast_call(2443u, l5);
                vader_c_emit_evaluate(l0, l4);
            }
            t4 = concat_2(l11, 286u);
            l4 = vader_c_emit_c_ast_verbatim(t4);
            vader_c_emit_write_barrier(l0, l4);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l9.tag == 0u) {
        l4 = vader_c_emit_slot_index(l11, l3);
        l4 = vader_c_emit_box_slot_1(l11, l4);
        l8 = vader_c_emit_coerced_as(l0, l2, (uint8_t) 19);
        vader_c_emit_assign(l0, l4, l8);
        t4 = concat_2(l11, 286u);
        l4 = vader_c_emit_c_ast_verbatim(t4);
        vader_c_emit_write_barrier(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t5 = l9.payload.obj;
    l13 = ((vader_struct_vader_c_emit_SlotFill_t*) t5)->f_cty;
    t5 = l9.payload.obj;
    l14 = ((vader_struct_vader_c_emit_SlotFill_t*) t5)->f_val;
    vader_c_emit_emit_typed_slot_write(l0, l11, l3, l2, l13, l14);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_slice(void* l0, void* l1) {
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
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_aux(l0, 1244u);
    t0 = vader_c_emit_object_pointer_of(l4);
    l4 = vader_c_emit_array_pointer(t0);
    l3 = vader_c_emit_as_size(l3);
    l2 = vader_c_emit_as_size(l2);
    vader_array_t* _a0_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l6 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2447u, l6);
    vader_c_emit_declare(l0, 2449u, l5, l2);
    l2 = vader_c_emit_c_ast_verbatim(l5);
    vader_c_emit_push_object(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_atom_comptime_table(void* l0, void* l1) {
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
    size_t l10, l12;
    int64_t l11, l14, l23;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    size_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    int64_t t5;
    vader_box_t* gc_roots[7] = { &l8, &l16, &l18, &l19, &l21, &l22, &t3 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l17, &l20, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l13, &l15, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(230u, 454u);
    l2 = (void*) _a0_arr;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    if (t0 == INT64_C(0)) {
        t1 = (void*) &vader_data_49;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_49;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_49;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l5 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_49;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_49;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
        l8 = vader_c_emit_c_ast_verbatim(179u);
        vader_array_t* _a6_arr = vader_array_new(181u, 6u, 13u, 1359u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 5u] = l8.payload.obj;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 4u] = l7;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 3u] = l6;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 2u] = l5;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l4;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l3;
        t1 = (void*) _a6_arr;
        l8 = vader_c_emit_c_ast_initializer_list(t1);
        t2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        l9 = vader_c_emit_global_storage(t2);
        vader_array_t* _a7_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l8.payload.obj;
        t1 = (void*) _a7_arr;
        l8 = vader_c_emit_c_ast_initializer_list(t1);
        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
        vader_obj_header_init(_a8_obj, 718u);
        _a8_obj->f_name = 2451u;
        _a8_obj->f_length = vader_box_i32(233u, INT32_C(1));
        _a8_obj->f_value = l8;
        l3 = (void*) _a8_obj;
        vader_struct_vader_c_emit_c_ast_CGlobal_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
        vader_obj_header_init(_a9_obj, 727u);
        _a9_obj->f_storage = l9;
        _a9_obj->f_constant = true;
        _a9_obj->f_type = 2452u;
        _a9_obj->f_declarator = l3;
        l3 = (void*) _a9_obj;
        l8 = vader_c_emit_atom_count_define(l0);
        vader_array_t* _a10_arr = vader_array_new(183u, 2u, 13u, 1367u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_struct_vader_c_emit_c_ast_CSection_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
        vader_obj_header_init(_a11_obj, 745u);
        _a11_obj->f_comment = l2;
        _a11_obj->f_items = l3;
        l3 = (void*) _a11_obj;
        vader_c_emit_c_ast_print_section(l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l9 = vader_c_emit_global_storage(t2);
    vader_array_t* _a12_arr = vader_array_new(10u, 0u, 0u, 230u);
    l3 = (void*) _a12_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l10);
    l3 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l4 = (void*) _a14_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l10);
    l4 = (void*) _a15_arr;
    l11 = INT64_C(0);
    l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table;
    l10 = ((vader_array_t*) l5)->length;
    l12 = (size_t) 0;
    while ((l12 < l10)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l12)
        t3 = vader_array_box_slots(_a16_slotarr->buf)[_a16_slotarr->offset + (size_t) l12];
        l13 = t3.payload.s;
        t0 = vader_host_std_core_byte_len(l13);
        l14 = ((int64_t) (size_t) t0);
        t4 = vader_c_emit_c_string_lit(l13);
        l15 = concat_2(t4, 22u);
        vader_array_push((vader_array_t*) l3, vader_box_string(230u, l15));
        l8 = vader_c_emit_c_ast_verbatim(2450u);
        l16 = vader_c_emit_c_ast_number(l11);
        vader_struct_vader_c_emit_c_ast_CIndex_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
        vader_obj_header_init(_a17_obj, 731u);
        _a17_obj->f_base = l8;
        _a17_obj->f_index = l16;
        l6 = (void*) _a17_obj;
        t1 = (void*) &vader_data_49;
        vader_array_t* _a18_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l7 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
        t1 = (void*) &vader_data_49;
        vader_array_t* _a19_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        l17 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
        l18 = vader_c_emit_c_ast_unsigned(l14);
        l19 = vader_c_emit_c_ast_verbatim(745u);
        t1 = (void*) &vader_data_49;
        vader_array_t* _a20_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l20 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
        l21 = vader_c_emit_c_ast_address_of(vader_ref_box(l6));
        vader_array_t* _a21_arr = vader_array_new(181u, 6u, 13u, 1359u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 5u] = l21.payload.obj;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 4u] = l20;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 3u] = l19.payload.obj;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 2u] = l18.payload.obj;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 1u] = l17;
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = l7;
        t1 = (void*) _a21_arr;
        l22 = vader_c_emit_c_ast_initializer_list(t1);
        vader_array_push((vader_array_t*) l4, l22);
        l23 = (l14 + INT64_C(1));
        l11 = (l11 + l23);
        t5 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t5;
    }
    t1 = (void*) &vader_data_48;
    vader_array_t* _a22_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
    l5 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_c_emit_c_ast_CStringLiterals_t* _a23_obj = (vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStringLiterals_t));
    vader_obj_header_init(_a23_obj, 749u);
    _a23_obj->f_literals = l3;
    l3 = (void*) _a23_obj;
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a24_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a24_obj, 718u);
    _a24_obj->f_name = 2450u;
    _a24_obj->f_length = vader_ref_box(l5);
    _a24_obj->f_value = vader_ref_box(l3);
    l3 = (void*) _a24_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a25_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a25_obj, 727u);
    _a25_obj->f_storage = l9;
    _a25_obj->f_constant = true;
    _a25_obj->f_type = 1413u;
    _a25_obj->f_declarator = l3;
    l3 = (void*) _a25_obj;
    t1 = (void*) &vader_data_48;
    vader_array_t* _a26_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
    l5 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) INT64_C(0));
    l8 = vader_c_emit_c_ast_initializer_list(l4);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a27_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a27_obj, 718u);
    _a27_obj->f_name = 2451u;
    _a27_obj->f_length = vader_ref_box(l5);
    _a27_obj->f_value = l8;
    l4 = (void*) _a27_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a28_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a28_obj, 727u);
    _a28_obj->f_storage = l9;
    _a28_obj->f_constant = true;
    _a28_obj->f_type = 2452u;
    _a28_obj->f_declarator = l4;
    l4 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(183u, 1u, 13u, 1367u);
    ((void**) _a29_arr->buf->slots)[_a29_arr->offset + 0u] = l3;
    l3 = (void*) _a29_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a30_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a30_obj, 745u);
    _a30_obj->f_comment = l2;
    _a30_obj->f_items = l3;
    l2 = (void*) _a30_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a31_arr = vader_array_new(10u, 0u, 0u, 230u);
    l2 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(183u, 1u, 13u, 1367u);
    ((void**) _a32_arr->buf->slots)[_a32_arr->offset + 0u] = l4;
    l3 = (void*) _a32_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a33_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a33_obj, 745u);
    _a33_obj->f_comment = l2;
    _a33_obj->f_items = l3;
    l2 = (void*) _a33_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a34_arr = vader_array_new(10u, 0u, 0u, 230u);
    l2 = (void*) _a34_arr;
    t3 = vader_c_emit_atom_count_define(l0);
    vader_array_t* _a35_arr = vader_array_new(183u, 1u, 13u, 1367u);
    ((void**) _a35_arr->buf->slots)[_a35_arr->offset + 0u] = t3.payload.obj;
    l3 = (void*) _a35_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a36_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a36_obj, 745u);
    _a36_obj->f_comment = l2;
    _a36_obj->f_items = l3;
    l2 = (void*) _a36_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_bits_to_f32(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 2);
    l1 = vader_c_emit_c_ast_around(228u, l1, 252u);
    vader_c_emit_push_expr(l0, (uint8_t) 10, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_bits_to_f64(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 3);
    l1 = vader_c_emit_c_ast_around(229u, l1, 251u);
    vader_c_emit_push_expr(l0, (uint8_t) 11, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_branch(void* l0, int32_t l1, bool l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l9 = 0;
    void* l6 = NULL;
    size_t l7;
    int64_t l8, l10;
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_jump_table);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l4 = vader_c_emit_branch_target(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l3);
    if (!(l4.tag == 697u)) {
        l6 = std_core_new_byte_buffer((size_t) 91);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 1518u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core_write_int(l6, l7, l8);
        l7 = std_core_write_string_at(l6, l7, 28u);
        l10 = ((int64_t) (int32_t) l3);
        l7 = std_core_write_int(l6, l7, l10);
        l7 = std_core_write_string_at(l6, l7, 241u);
        t0 = std_core_finish_buffer(l6, l7);
        std_abort_todo(t0);
        vader_unreachable("a no-return call returned");
    }
    t1 = l4.payload.obj;
    t2 = vader_c_emit_is_continue_branch(t1, l3);
    if (t2) {
        l6 = std_core_new_byte_buffer((size_t) 25);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 1910u);
        t1 = l4.payload.obj;
        t3 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t1)->f_opener_pc;
        l8 = ((int64_t) (int32_t) t3);
        l7 = std_core_write_int(l6, l7, l8);
        l5 = std_core_finish_buffer(l6, l7);
    } else {
        l6 = std_core_new_byte_buffer((size_t) 24);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 1525u);
        t1 = l4.payload.obj;
        t3 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t1)->f_opener_pc;
        l8 = ((int64_t) (int32_t) t3);
        l7 = std_core_write_int(l6, l7, l8);
        l5 = std_core_finish_buffer(l6, l7);
    }
    if (l2) {
        l4 = vader_c_emit_pop(l0);
        l6 = std_core_new_byte_buffer((size_t) 31);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 1319u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core_write_int(l6, l7, l8);
        l7 = std_core_write_string_at(l6, l7, 241u);
        l9 = std_core_finish_buffer(l6, l7);
        vader_c_emit_assert_stack_empty(l0, l9);
        l4 = vader_c_emit_expression_of(l4);
        vader_struct_vader_c_emit_c_ast_CGoto_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGoto_t));
        vader_obj_header_init(_a1_obj, 728u);
        _a1_obj->f_label = l5;
        _a1_obj->f_condition = l4;
        l6 = (void*) _a1_obj;
        vader_c_emit_append_statement(l0, vader_ref_box(l6));
    } else {
        l6 = std_core_new_byte_buffer((size_t) 28);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 1317u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core_write_int(l6, l7, l8);
        l7 = std_core_write_string_at(l6, l7, 241u);
        l9 = std_core_finish_buffer(l6, l7);
        vader_c_emit_assert_stack_empty(l0, l9);
        vader_struct_vader_c_emit_c_ast_CGoto_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGoto_t));
        vader_obj_header_init(_a2_obj, 728u);
        _a2_obj->f_label = l5;
        _a2_obj->f_condition = vader_box_obj(0u, NULL);
        l6 = (void*) _a2_obj;
        vader_c_emit_append_statement(l0, vader_ref_box(l6));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_buffer_load(void* l0, vader_string_t l1, uint8_t l2) {
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
    l3 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_buffer_pointer(t0);
    l3 = vader_c_emit_as_size(l3);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l5 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(l1, l5);
    vader_c_emit_push_into_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_buffer_new(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_as_size(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2470u, l1);
    l2 = vader_c_emit_c_ast_cast(2556u, l2);
    vader_c_emit_push_into_temporary(l0, l2, (uint8_t) 18);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_buffer_store(void* l0, vader_string_t l1, vader_string_t l2) {
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
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_buffer_pointer(t0);
    l4 = vader_c_emit_as_size(l4);
    l3 = vader_c_emit_expression_of(l3);
    l3 = vader_c_emit_c_ast_cast(l2, l3);
    vader_array_t* _a0_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(l1, l6);
    vader_c_emit_evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_buffer_to_string(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_buffer_pointer(t0);
    l1 = vader_c_emit_as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2464u, l3);
    vader_c_emit_push_into_temporary(l0, l1, (uint8_t) 14);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_buffer_write_string(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_buffer_pointer(t0);
    l2 = vader_c_emit_as_size(l2);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 14);
    vader_array_t* _a0_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2476u, l4);
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_c_emit_emit_c_split(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    bool l4;
    vader_string_t l6 = 0;
    vader_string_t l27 = 0;
    vader_string_t l28 = 0;
    vader_box_t l11 = vader_box_null();
    size_t l13, l14, l16, l18, l20, l21, l24;
    int32_t l22;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l3, &l5, &l7, &l8, &l9, &l10, &l12, &l15, &l17, &l19, &l23, &l25, &l26, &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l2, &l6, &l27, &l28, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_partition_functions(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l4 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_release;
    l5 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_atom_universe;
    l6 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_entry_mangled;
    l7 = vader_c_emit_internal_fn_flags(l0, l3, l6);
    l5 = vader_c_emit_new_ctx(l0, l4, true, l5, l7);
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 413u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CPrinter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t));
    vader_obj_header_init(_a2_obj, 741u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l7 = (void*) _a2_obj;
    vader_c_emit_emit_preamble(l7, 482u);
    vader_c_emit_emit_struct_typedefs(l5, l7);
    vader_c_emit_emit_fn_sig_typedefs(l5, l7);
    vader_c_emit_emit_forward_decls(l5, l7);
    vader_c_emit_emit_closure_forward_decls(l5, l7);
    vader_c_emit_emit_vtable_forward_decls(l5, l7);
    vader_array_t* _a3_arr = vader_array_new(10u, 0u, 0u, 230u);
    t0 = (void*) _a3_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a4_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a4_obj, 413u);
    _a4_obj->f_parts = t0;
    t0 = (void*) _a4_obj;
    vader_struct_vader_c_emit_c_ast_CPrinter_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t));
    vader_obj_header_init(_a5_obj, 741u);
    _a5_obj->f_out = t0;
    _a5_obj->f_started = false;
    l8 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a6_arr->buf)[_a6_arr->offset + 0u] = vader_box_string(230u, 481u);
    l9 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a7_obj, 730u);
    _a7_obj->f_path = 2415u;
    _a7_obj->f_system = false;
    t0 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(183u, 1u, 13u, 1367u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = t0;
    l10 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 745u);
    _a9_obj->f_comment = l9;
    _a9_obj->f_items = l10;
    l9 = (void*) _a9_obj;
    vader_c_emit_c_ast_print_section(l8, l9);
    vader_c_emit_emit_import_shims(l5, l8);
    t1 = vader_c_emit_imports_header_name(l2);
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a10_obj, 730u);
    _a10_obj->f_path = t1;
    _a10_obj->f_system = false;
    l9 = (void*) _a10_obj;
    vader_c_emit_c_ast_print_item(l7, vader_ref_box(l9));
    l11 = vader_c_emit_atom_count_define(l5);
    vader_c_emit_c_ast_print_item(l7, l11);
    vader_c_emit_emit_data_global_externs(l5, l7);
    l9 = vader_c_emit_including(l2);
    vader_c_emit_emit_atom_comptime_table(l5, l9);
    vader_c_emit_emit_data_pool(l5, l9);
    vader_c_emit_emit_type_info_table(l5, l9);
    l10 = vader_c_emit_unit_names_of(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions, l3);
    vader_array_t* _a11_arr = vader_array_new(10u, 0u, 0u, 230u);
    l12 = (void*) _a11_arr;
    l13 = ((vader_array_t*) l3)->length;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) l12, (size_t) l13);
    l12 = (void*) _a12_arr;
    l13 = (size_t) 0;
    l14 = ((vader_array_t*) l3)->length;
    while ((l13 < l14)) {
        l15 = vader_c_emit_including(l2);
        l16 = l13;
        vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l16)
        l17 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l16);
        vader_c_emit_emit_internal_forward_decls(l5, l17, l15);
        if (l13 == INT64_C(0)) {
            vader_c_emit_emit_fn_trampolines(l5, l15);
            vader_c_emit_emit_vtable_dispatchers(l5, l15);
        }
        l18 = l13;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l18)
        l19 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l18);
        l20 = ((vader_array_t*) l19)->length;
        l21 = (size_t) 0;
        while ((l21 < l20)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l21)
            l22 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l21];
            l23 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
            t2 = ((int64_t) (int32_t) l22);
            l24 = (size_t) (int64_t) t2;
            vader_array_t* _a16_slotarr = ((vader_array_t*) l23);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l24)
            l25 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l24);
            l26 = vader_c_emit_function_definition(l5, l22, l25);
            vader_c_emit_c_ast_print_item(l15, vader_ref_box(l26));
            t2 = (l21 + INT64_C(1));
            l21 = (size_t) (int64_t) t2;
        }
        if (l13 == INT64_C(0)) {
            l6 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_entry_mangled;
            vader_c_emit_emit_main(l5, l15, l6);
        }
        l27 = vader_c_emit_c_ast_printed_text(l15);
        vader_array_push((vader_array_t*) l12, vader_box_string(230u, l27));
        t2 = (l13 + INT64_C(1));
        l13 = (size_t) (int64_t) t2;
    }
    l6 = vader_c_emit_c_ast_printed_text(l7);
    l27 = vader_c_emit_c_ast_printed_text(l8);
    l28 = vader_c_emit_c_ast_printed_text(l9);
    vader_struct_vader_c_emit_CProgram_t* _a17_obj = (vader_struct_vader_c_emit_CProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CProgram_t));
    vader_obj_header_init(_a17_obj, 689u);
    _a17_obj->f_header = l6;
    _a17_obj->f_imports = l27;
    _a17_obj->f_globals = l28;
    _a17_obj->f_units = l12;
    _a17_obj->f_unit_names = l10;
    t0 = (void*) _a17_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_emit_call(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    vader_string_t l4 = 0;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    t0 = ((vader_struct_vader_bytecode_Call_t*) l1)->f_function_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t2 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_name;
    l4 = vader_c_emit_sanitise(t2);
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature;
    vader_c_emit_emit_call_to(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_call_import(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    vader_string_t l4 = 0;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_imports;
    t0 = ((vader_struct_vader_bytecode_CallImport_t*) l1)->f_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = vader_c_emit_host_shim_name(l2);
    l2 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_signature;
    vader_c_emit_emit_call_to(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_call_indirect(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t l3, l12;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    int64_t l10;
    uint8_t l11;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    size_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l7, &l9, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_CallIndirect_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 526u)) {
        l7 = std_core_new_byte_buffer((size_t) 49);
        l12 = (size_t) 0;
        l12 = std_core_write_string_at(l7, l12, 1383u);
        t0 = ((vader_struct_vader_bytecode_CallIndirect_t*) l1)->f_type_id;
        l10 = ((int64_t) (int32_t) t0);
        l12 = std_core_write_int(l7, l12, l10);
        t2 = std_core_finish_buffer(l7, l12);
        std_abort_todo(t2);
        vader_unreachable("a no-return call returned");
    }
    l5 = vader_c_emit_pop(l0);
    t3 = l4.payload.obj;
    t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t3)->f_params)->length;
    l6 = ((int32_t) (size_t) t4);
    l7 = vader_c_emit_pop_args_boxed(l0, l6);
    l8 = vader_c_emit_aux(l0, 1660u);
    l5 = vader_c_emit_object_pointer_of(l5);
    l5 = vader_c_emit_c_ast_cast(2492u, l5);
    vader_c_emit_declare(l0, 2492u, l8, l5);
    t2 = concat_2(l8, 290u);
    t5 = vader_c_emit_c_ast_verbatim(t2);
    vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t5.payload.obj;
    l9 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l7);
    l3 = vader_host_std_core_byte_len(l8);
    l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(53) + l3));
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l7, l3, 230u);
    l10 = ((int64_t) (int32_t) l6);
    l3 = std_core_write_int(l7, l3, l10);
    l3 = std_core_write_string_at(l7, l3, 838u);
    l3 = std_core_write_string_at(l7, l3, l8);
    l3 = std_core_write_string_at(l7, l3, 289u);
    t2 = std_core_finish_buffer(l7, l3);
    l5 = vader_c_emit_c_ast_call(t2, l9);
    t3 = l4.payload.obj;
    t0 = ((vader_struct_vader_bytecode_BcFn_t*) t3)->f_return_type;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
    l11 = vader_c_emit_val_type_of_bc_type(t5);
    if (l11 == INT32_C(16)) {
        vader_c_emit_evaluate(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = vader_c_emit_new_temporary(l0, (uint8_t) 19);
    vader_c_emit_assign(l0, vader_ref_box(l7), l5);
    if (l11 == INT32_C(19)) {
        vader_c_emit_push_temporary(l0, l7, (uint8_t) 19);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_c_emit_coerce_expr(l2, vader_ref_box(l7), (uint8_t) 19, l11);
    vader_c_emit_push_into_temporary(l0, l4, l11);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_call_result(void* l0, vader_box_t l1, uint8_t l2) {
    bool l3;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(16)) {
        l3 = true;
    } else {
        l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_drop_call_result;
    }
    if (!(l3)) {
        vader_c_emit_push_into_temporary(l0, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_call_to(void* l0, vader_string_t l1, void* l2) {
    int32_t l3, l6, l8;
    void* l4 = NULL;
    void* l9 = NULL;
    size_t l5, l10;
    vader_box_t l7 = vader_box_null(), l12 = vader_box_null();
    uint8_t l11;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l7, &l12, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    l3 = ((int32_t) (size_t) t0);
    t1 = vader_c_emit_c_ast_verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l4 = (void*) _a0_arr;
    t2 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l6 = INT32_C(0);
    while ((l6 < l3)) {
        l7 = vader_c_emit_pop(l0);
        l8 = ((l3 - INT32_C(1)) - l6);
        t2 = ((int64_t) (int32_t) l8);
        l5 = (size_t) (int64_t) t2;
        l9 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params;
        t2 = ((int64_t) (int32_t) l8);
        l10 = (size_t) (int64_t) t2;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l10, 236u);
        l11 = ((uint8_t) t1.payload.i);
        l12 = vader_c_emit_coerced_as(l0, l7, l11);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5, l12.payload.obj);
        VADER_WRITE_BARRIER(_a3_slotarr->buf);
        l6 = (l6 + INT32_C(1));
    }
    t0 = vader_bytecode_bc_result_arity(l2);
    if (!((t0 > INT64_C(1)))) {
        l7 = vader_c_emit_c_ast_call(l1, l4);
        l11 = vader_bytecode_bc_single_result(l2);
        vader_c_emit_emit_call_result(l0, l7, l11);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_emit_multi_call(l0, l1, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_closure_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l5, l6;
    int32_t l7;
    vader_string_t l8 = 0;
    vader_string_t l11 = 0;
    vader_box_t l12 = vader_box_null();
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    size_t t5;
    vader_box_t* gc_roots[2] = { &l12, &t4 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l9, &l10, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_c_emit_scan_fn_value_usage(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions);
    t0 = ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_any;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l7 = ((int32_t) (size_t) l5);
            l8 = vader_c_emit_fn_symbol_name(l3, l7);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature;
            t2 = vader_c_emit_trampoline_signature(l0, l8, l9);
            vader_struct_vader_c_emit_c_ast_CPrototype_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
            vader_obj_header_init(_a3_obj, 742u);
            _a3_obj->f_signature = t2;
            l10 = (void*) _a3_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
            l11 = concat_2(2490u, l8);
            l12 = vader_c_emit_external(2491u, l11, vader_box_obj(0u, NULL), false);
            vader_array_push((vader_array_t*) l4, l12);
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t4 = vader_box_bool(228u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
        t0 = t4.payload.b;
        if (t0) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
            t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
            t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature)->f_params)->length;
            if ((t5 > INT64_C(0))) {
                l7 = ((int32_t) (size_t) l5);
                l8 = vader_c_emit_fn_symbol_name(l3, l7);
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
                t2 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature;
                t2 = vader_c_emit_lift_signature(l0, l8, l9);
                vader_struct_vader_c_emit_c_ast_CPrototype_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
                vader_obj_header_init(_a7_obj, 742u);
                _a7_obj->f_signature = t2;
                l10 = (void*) _a7_obj;
                vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
            }
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a8_arr = vader_array_new(10u, 0u, 0u, 230u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 745u);
    _a9_obj->f_comment = t2;
    _a9_obj->f_items = l4;
    l2 = (void*) _a9_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_closure_lift(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l4;
    vader_string_t l5 = 0;
    vader_box_t l7 = vader_box_null();
    uint8_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l7, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l9, &l10, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_name;
    l5 = vader_c_emit_sanitise(t1);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature;
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params)->length;
    if (!(t2 == INT64_C(0))) {
        l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        l7 = vader_c_emit_c_ast_verbatim(1534u);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(0), 236u);
        l8 = ((uint8_t) t3.payload.i);
        t3 = vader_c_emit_coerce_expr(l6, l7, (uint8_t) 18, l8);
        vader_array_t* _a2_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t3.payload.obj;
        l6 = (void*) _a2_arr;
        l9 = vader_c_emit_lift_unbox_tail(((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
        vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l9);
        vader_array_t* _a3_arr = vader_array_new(182u, 0u, 13u, 1363u);
        t4 = (void*) _a3_arr;
        vader_struct_vader_c_emit_c_ast_CBlock_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
        vader_obj_header_init(_a4_obj, 708u);
        _a4_obj->f_body = t4;
        l9 = (void*) _a4_obj;
        l10 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l9)->f_body;
        l6 = vader_c_emit_forward_boxed(l5, l6, l3);
        vader_array_push_all((vader_array_t*) l10, (vader_array_t*) l6);
        l3 = vader_c_emit_lift_signature(l0, l5, l3);
        vader_array_t* _a5_arr = vader_array_new(182u, 0u, 13u, 1363u);
        l6 = (void*) _a5_arr;
        vader_struct_vader_c_emit_c_ast_CFunction_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
        vader_obj_header_init(_a6_obj, 725u);
        _a6_obj->f_signature = l3;
        _a6_obj->f_prologue = l6;
        _a6_obj->f_body = l9;
        l3 = (void*) _a6_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_convert(void* l0, uint8_t l1, vader_string_t l2) {
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
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_val_of(l3);
    if (l1 == INT32_C(3)) {
        l6 = true;
    } else {
        l6 = l1 == INT32_C(11);
    }
    if (l6) {
        l6 = l4 == INT32_C(2);
    } else {
        l6 = false;
    }
    if (l6) {
        l6 = std_string_starts_with(l2, 2346u);
    } else {
        l6 = false;
    }
    if (l6) {
        l5 = (uint8_t) 7;
    } else {
        l5 = l4;
    }
    t0 = vader_c_emit_is_ref_val(l4);
    if (t0) {
        t1 = vader_c_emit_expression_of(l3);
        l7 = vader_c_emit_unbox_expr(t1, l1);
        vader_c_emit_push_expr(l0, l1, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == l1) {
        l7 = vader_c_emit_expression_of(l3);
        vader_c_emit_push_expr(l0, l1, l7);
    } else {
        t1 = vader_c_emit_expression_of(l3);
        t2 = vader_c_emit_scalar_cast(t1, l5, l1);
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a0_obj, 740u);
        _a0_obj->f_inner = t2;
        l8 = (void*) _a0_obj;
        vader_c_emit_push_expr(l0, l1, vader_ref_box(l8));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_data_const_op(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
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
    l2 = std_core_new_byte_buffer((size_t) 31);
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l2, l3, 2480u);
    t0 = ((vader_struct_vader_bytecode_DataConst_t*) l1)->f_pool_index;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    t1 = std_core_finish_buffer(l2, l3);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    l5 = vader_c_emit_c_ast_address_of(t2);
    vader_c_emit_push_object(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_data_global_externs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    size_t l3, l4, l7;
    bool l5;
    uint64_t l8;
    vader_string_t l9 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    void* t3 = NULL;
    size_t t4;
    vader_box_t* gc_roots[4] = { &l10, &l11, &l12, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        t1 = vader_bytecode_data_entry_mutable(t0);
        l5 = !(t1);
        l6 = std_core_new_byte_buffer((size_t) 31);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 2480u);
        t2 = ((int64_t) (size_t) l3);
        l8 = (uint64_t) (int64_t) t2;
        l7 = std_core_write_unsigned(l6, l7, l8);
        l9 = std_core_finish_buffer(l6, l7);
        l10 = vader_c_emit_external(2448u, l9, vader_box_obj(0u, NULL), l5);
        vader_array_push((vader_array_t*) l2, l10);
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    t3 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    t4 = ((vader_array_t*) t3)->length;
    if ((t4 > INT64_C(0))) {
        t3 = (void*) &vader_data_48;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        l10 = vader_c_emit_external(2449u, 2500u, vader_ref_box(l6), false);
        t3 = (void*) &vader_data_48;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        l11 = vader_c_emit_external(2556u, 2502u, vader_ref_box(l6), false);
        l12 = vader_c_emit_external(2496u, 2501u, vader_box_obj(0u, NULL), false);
        vader_array_t* _a5_arr = vader_array_new(183u, 3u, 13u, 1367u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l12.payload.obj;
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l11.payload.obj;
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l10.payload.obj;
        l6 = (void*) _a5_arr;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l6);
    }
    t3 = (void*) &vader_data_48;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) INT64_C(0));
    l10 = vader_c_emit_external(2452u, 2451u, vader_ref_box(l6), true);
    vader_array_push((vader_array_t*) l2, l10);
    vader_array_t* _a7_arr = vader_array_new(10u, 0u, 0u, 230u);
    t3 = (void*) _a7_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a8_obj, 745u);
    _a8_obj->f_comment = t3;
    _a8_obj->f_items = l2;
    l2 = (void*) _a8_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_data_pool(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    size_t l8, l9, l11;
    vader_box_t l10 = vader_box_null();
    uint64_t l12;
    vader_string_t l13 = 0;
    uint8_t l14;
    bool l15;
    int32_t l16, l17, l18;
    size_t t0;
    bool t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l19, &l20, &l21, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    l3 = vader_bytecode_data_pool_type_ids(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module);
    t1 = vader_c_emit_has_str_data(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    if (t1) {
        l4 = vader_c_emit_build_string_atom_map(l0);
    } else {
        vader_array_t* _a1_arr = vader_array_new(10u, 0u, 0u, 230u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(11u, 0u, 7u, 233u);
        l6 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(11u, 0u, 7u, 233u);
        l7 = (void*) _a3_arr;
        vader_struct_std_collections_MutableMap__string__i32_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
        vader_obj_header_init(_a4_obj, 366u);
        _a4_obj->f_ekeys = l5;
        _a4_obj->f_evals = l6;
        _a4_obj->f_index = l7;
        _a4_obj->f_mask = (size_t) 0;
        _a4_obj->f_size = (size_t) 0;
        _a4_obj->f_tombs = (size_t) 0;
        l4 = (void*) _a4_obj;
    }
    l8 = (size_t) 0;
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    while ((l8 < l9)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        l5 = std_core_new_byte_buffer((size_t) 31);
        l11 = (size_t) 0;
        l11 = std_core_write_string_at(l5, l11, 2480u);
        t2 = ((int64_t) (size_t) l8);
        l12 = (uint64_t) (int64_t) t2;
        l11 = std_core_write_unsigned(l5, l11, l12);
        l13 = std_core_finish_buffer(l5, l11);
        t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        l14 = vader_c_emit_global_storage(t1);
        t1 = vader_bytecode_data_entry_mutable(l10);
        l15 = !(t1);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        l16 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
        l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        l17 = l16;
        l18 = vader_c_emit_array_element_tag(l6, l17);
        vader_struct_vader_c_emit_PoolArray_t* _a7_obj = (vader_struct_vader_c_emit_PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_PoolArray_t));
        vader_obj_header_init(_a7_obj, 695u);
        _a7_obj->f_name = l13;
        _a7_obj->f_storage = l14;
        _a7_obj->f_constant = l15;
        _a7_obj->f_type_id = l16;
        _a7_obj->f_element_tag = l18;
        l7 = (void*) _a7_obj;
        if (l10.tag == 535u) {
            l19 = l10.payload.obj;
            vader_c_emit_emit_str_data_entry(l2, l7, l19, l4);
        } else if (l10.tag == 531u) {
            l20 = l10.payload.obj;
            vader_c_emit_emit_prim_data_entry(l2, l7, l20);
        } else {
            if (!(l10.tag == 522u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l21 = l10.payload.obj;
            vader_c_emit_emit_agg_data_entry(l0, l2, l7, l21, l4);
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    vader_c_emit_emit_global_const_roots(l0, l2);
    vader_array_t* _a8_arr = vader_array_new(10u, 3u, 0u, 230u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 2u] = vader_box_string(230u, 2090u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 1u] = vader_box_string(230u, 549u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 0u] = vader_box_string(230u, 455u);
    t3 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 745u);
    _a9_obj->f_comment = t3;
    _a9_obj->f_items = l2;
    l2 = (void*) _a9_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_emit_data_value(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4) {
    uint8_t l5;
    uint64_t l6;
    vader_string_t l7 = 0;
    vader_string_t l15 = 0;
    vader_string_t l19 = 0;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l17 = NULL;
    int32_t l9;
    size_t l10, l12, l13, l16, l18;
    vader_box_t l14 = vader_box_null(), l20 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null(), t4 = vader_box_null();
    int32_t t2;
    int64_t t3;
    bool t5;
    vader_box_t* gc_roots[5] = { &l2, &l14, &l20, &t1, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l8, &l11, &l17, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l7, &l15, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 539u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_bits;
        t1 = vader_c_emit_data_slot(l5, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 540u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        t2 = vader_c_emit_atom_for(l4, l7);
        t1 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 541u) {
        l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_symbol_id;
        l9 = vader_c_emit_type_id_for_struct_symbol(l8, l9);
        l8 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names;
        t3 = ((int64_t) (int32_t) l9);
        l10 = (size_t) (int64_t) t3;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l10];
        l7 = t1.payload.s;
        l7 = concat_2(2235u, l7);
        t1 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l9));
        t4 = vader_c_emit_object_header(t1);
        vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t4.payload.obj;
        l8 = (void*) _a1_arr;
        l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        t3 = ((int64_t) (int32_t) l9);
        l10 = (size_t) (int64_t) t3;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        if (t1.tag == 536u) {
            l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
            t3 = ((int64_t) (int32_t) l9);
            l10 = (size_t) (int64_t) t3;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            l11 = t1.payload.obj;
            l10 = (size_t) 0;
            t0 = l2.payload.obj;
            l12 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields)->length;
            while ((l10 < l12)) {
                l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l11)->f_fields)->length;
                if ((l10 < l13)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l11)->f_fields);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
                    t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l10);
                    l9 = ((vader_struct_vader_bytecode_BcField_t*) t0)->f_type_index;
                } else {
                    l9 = INT32_C(0);
                }
                t0 = l2.payload.obj;
                vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
                l14 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l10);
                l15 = l3;
                l16 = vader_host_std_core_byte_len(l15);
                l17 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l16));
                l18 = (size_t) 0;
                l18 = std_core_write_string_at(l17, l18, l15);
                l18 = std_core_write_string_at(l17, l18, 829u);
                t3 = ((int64_t) (size_t) l10);
                l6 = (uint64_t) (int64_t) t3;
                l18 = std_core_write_unsigned(l17, l18, l6);
                l19 = std_core_finish_buffer(l17, l18);
                l20 = vader_c_emit_struct_field_init(l0, l1, l14, l19, l9, l4);
                vader_array_push((vader_array_t*) l8, l20);
                t3 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t3;
            }
        }
        t5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        l5 = vader_c_emit_global_storage(t5);
        l14 = vader_c_emit_c_ast_initializer_list(l8);
        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
        vader_obj_header_init(_a6_obj, 718u);
        _a6_obj->f_name = l3;
        _a6_obj->f_length = vader_box_obj(0u, NULL);
        _a6_obj->f_value = l14;
        l8 = (void*) _a6_obj;
        vader_struct_vader_c_emit_c_ast_CGlobal_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
        vader_obj_header_init(_a7_obj, 727u);
        _a7_obj->f_storage = l5;
        _a7_obj->f_constant = true;
        _a7_obj->f_type = l7;
        _a7_obj->f_declarator = l8;
        l8 = (void*) _a7_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
        l7 = concat_2(l7, 264u);
        t1 = vader_c_emit_c_ast_verbatim(l3);
        l14 = vader_c_emit_c_ast_address_of(t1);
        t1 = vader_c_emit_c_ast_cast(l7, l14);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 538u)) {
        t1 = vader_c_emit_c_ast_number(INT64_C(0));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l2.payload.obj;
    t1 = vader_c_emit_emit_nested_array(l0, l1, l8, l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_emit_defer_pop_exec(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
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
    l2 = std_core_new_byte_buffer((size_t) 21);
    l3 = (size_t) 0;
    t0 = ((vader_struct_vader_bytecode_DeferPopExec_t*) l1)->f_count;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2346u);
    t1 = std_core_finish_buffer(l2, l3);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t2.payload.obj;
    l2 = (void*) _a0_arr;
    l5 = vader_c_emit_c_ast_call(2481u, l2);
    vader_c_emit_evaluate(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_defer_push(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_coerced_as(l0, l1, (uint8_t) 19);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2482u, l2);
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_else(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_c_emit_assert_stack_empty(l0, 1517u);
    vader_c_emit_open_else(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_end(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    size_t l3;
    int64_t l4;
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
    l2 = std_core_new_byte_buffer((size_t) 35);
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l2, l3, 2120u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 241u);
    l5 = std_core_finish_buffer(l2, l3);
    vader_c_emit_assert_stack_empty(l0, l5);
    l6 = vader_c_emit_scope_ending_at(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l1);
    if (l6.tag == 0u) {
        l7 = std_core_new_byte_buffer((size_t) 50);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l7, l3, 1519u);
        l4 = ((int64_t) (int32_t) l1);
        l3 = std_core_write_int(l7, l3, l4);
        t0 = std_core_finish_buffer(l7, l3);
        std_abort_todo(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l6.payload.obj;
        l8 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
        vader_c_emit_pc_close_cache(l0, l8);
        l7 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_break_targets;
        l8 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
        t1 = std_core____Contains_contains__i32(l7, l8);
        if (t1) {
            l7 = std_core_new_byte_buffer((size_t) 24);
            l3 = (size_t) 0;
            l3 = std_core_write_string_at(l7, l3, 1525u);
            t2 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
            l4 = ((int64_t) (int32_t) t2);
            l3 = std_core_write_int(l7, l3, l4);
            l5 = std_core_finish_buffer(l7, l3);
            vader_c_emit_close_node(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l5 = 0u;
        vader_c_emit_close_node(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_f32_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 10);
    l1 = vader_c_emit_c_ast_around(236u, l1, 152u);
    vader_c_emit_push_expr(l0, (uint8_t) 2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_f64_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 11);
    l1 = vader_c_emit_c_ast_around(237u, l1, 153u);
    vader_c_emit_push_expr(l0, (uint8_t) 3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_fn_addr(void* l0, void* l1) {
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
    l2 = vader_c_emit_new_temporary(l0, (uint8_t) 17);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l4 = ((vader_struct_vader_bytecode_FnAddr_t*) l1)->f_function_index;
    t0 = vader_c_emit_fn_symbol_name(l3, l4);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    l5 = vader_c_emit_c_ast_address_of(t1);
    l5 = vader_c_emit_c_ast_cast(2556u, l5);
    vader_c_emit_assign(l0, vader_ref_box(l2), l5);
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l3 = (void*) _a0_arr;
    l5 = vader_c_emit_c_ast_call(2484u, l3);
    vader_c_emit_evaluate(l0, l5);
    vader_c_emit_push_temporary(l0, l2, (uint8_t) 17);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_fn_ref(void* l0, void* l1) {
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
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l3 = ((vader_struct_vader_bytecode_FnRef_t*) l1)->f_function_index;
    l4 = vader_c_emit_fn_symbol_name(l2, l3);
    t0 = concat_2(2490u, l4);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    l5 = vader_c_emit_c_ast_address_of(t1);
    vader_c_emit_push_object(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_fn_ref_tramp(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l5;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null(), l11 = vader_box_null();
    uint8_t l12;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[3] = { &l7, &l11, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l8, &l9, &l10, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t0 = ((int64_t) (int32_t) l2);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    l6 = vader_c_emit_sanitise(t1);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature;
    l7 = vader_c_emit_c_ast_verbatim(1534u);
    t2 = vader_c_emit_c_ast_cast(2555u, l7);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 722u);
    _a1_obj->f_expression = t2;
    t3 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(182u, 1u, 13u, 1363u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t3;
    t3 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a3_obj, 708u);
    _a3_obj->f_body = t3;
    l8 = (void*) _a3_obj;
    l9 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l8)->f_body;
    l10 = vader_c_emit_tramp_unbox_args(((vader_struct_vader_bytecode_BcSignature_t*) l4)->f_params);
    l10 = vader_c_emit_forward_boxed(l6, l10, l4);
    vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l10);
    l4 = vader_c_emit_trampoline_signature(l0, l6, l4);
    vader_array_t* _a4_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l9 = (void*) _a4_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a5_obj, 725u);
    _a5_obj->f_signature = l4;
    _a5_obj->f_prologue = l9;
    _a5_obj->f_body = l8;
    l4 = (void*) _a5_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
    t2 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l3));
    l7 = vader_c_emit_object_header(t2);
    t1 = concat_2(2493u, l6);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    l11 = vader_c_emit_c_ast_address_of(t2);
    l11 = vader_c_emit_c_ast_cast(2556u, l11);
    t3 = (void*) &vader_data_50;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l4 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 2u] = l4;
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 1u] = l11.payload.obj;
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l7.payload.obj;
    t3 = (void*) _a7_arr;
    l7 = vader_c_emit_c_ast_initializer_list(t3);
    t4 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l12 = vader_c_emit_global_storage(t4);
    t1 = concat_2(2490u, l6);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a8_obj, 718u);
    _a8_obj->f_name = t1;
    _a8_obj->f_length = vader_box_obj(0u, NULL);
    _a8_obj->f_value = l7;
    l4 = (void*) _a8_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a9_obj, 727u);
    _a9_obj->f_storage = l12;
    _a9_obj->f_constant = false;
    _a9_obj->f_type = 2491u;
    _a9_obj->f_declarator = l4;
    l4 = (void*) _a9_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_fn_sig_typedefs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l3, l4, l6;
    uint64_t l7;
    vader_string_t l8 = 0;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l9, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    l4 = vader_c_emit_max_fn_arity(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
    while ((l3 <= l4)) {
        l5 = std_core_new_byte_buffer((size_t) 42);
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l5, l6, 2487u);
        t0 = ((int64_t) (size_t) l3);
        l7 = (uint64_t) (int64_t) t0;
        l6 = std_core_write_unsigned(l5, l6, l7);
        l6 = std_core_write_string_at(l5, l6, 837u);
        l8 = std_core_finish_buffer(l5, l6);
        l9 = vader_c_emit_erased_parameters(l3);
        vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t));
        vader_obj_header_init(_a1_obj, 726u);
        _a1_obj->f_result = 2462u;
        _a1_obj->f_name = l8;
        _a1_obj->f_parameters = l9;
        l10 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a2_arr = vader_array_new(10u, 0u, 0u, 230u);
    t1 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a3_obj, 745u);
    _a3_obj->f_comment = t1;
    _a3_obj->f_items = l2;
    l2 = (void*) _a3_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_fn_trampolines(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3, l5;
    int32_t l6, l7;
    bool t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_scan_fn_value_usage(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions);
    t0 = ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_any;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        if ((t1 >= INT32_C(0))) {
            l6 = ((int32_t) (size_t) l5);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
            vader_c_emit_emit_fn_ref_tramp(l0, l4, l6, l7);
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t3 = vader_box_bool(228u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5]);
        t0 = t3.payload.b;
        if (t0) {
            l6 = ((int32_t) (size_t) l5);
            vader_c_emit_emit_closure_lift(l0, l4, l6);
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a4_arr = vader_array_new(10u, 0u, 0u, 230u);
    t4 = (void*) _a4_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a5_obj, 745u);
    _a5_obj->f_comment = t4;
    _a5_obj->f_items = l4;
    l2 = (void*) _a5_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    size_t l3, l4;
    int32_t l5, l7;
    bool l6;
    uint8_t t0;
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions)->length;
    while ((l3 < l4)) {
        l5 = ((int32_t) (size_t) l3);
        t0 = vader_c_emit_module_function_storage(l0, l5);
        if (t0 == INT32_C(1)) {
            l6 = true;
        } else {
            t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
            l6 = !(t1);
        }
        if (l6) {
            l7 = ((int32_t) (size_t) l3);
            t2 = vader_c_emit_signature_for(l0, l7);
            vader_struct_vader_c_emit_c_ast_CPrototype_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
            vader_obj_header_init(_a1_obj, 742u);
            _a1_obj->f_signature = t2;
            l8 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a2_arr = vader_array_new(10u, 0u, 0u, 230u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a3_obj, 745u);
    _a3_obj->f_comment = t2;
    _a3_obj->f_items = l2;
    l2 = (void*) _a3_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_global_const_roots(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    uint8_t l3;
    size_t l5, l7, l8, l10;
    uint64_t l11;
    vader_box_t l12 = vader_box_null(), l15 = vader_box_null();
    size_t t0;
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    void* t5 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l15, &t4 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l9, &l13, &l14, &t5 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l3 = vader_c_emit_global_storage(t1);
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l6 = l2;
    l5 = ((vader_array_t*) l6)->length;
    l7 = (size_t) 0;
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
        l8 = (size_t) (int64_t) t2;
        l9 = std_core_new_byte_buffer((size_t) 31);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l9, l10, 2480u);
        t2 = ((int64_t) (size_t) l8);
        l11 = (uint64_t) (int64_t) t2;
        l10 = std_core_write_unsigned(l9, l10, l11);
        t3 = std_core_finish_buffer(l9, l10);
        t4 = vader_c_emit_c_ast_verbatim(t3);
        l12 = vader_c_emit_c_ast_address_of(t4);
        vader_array_push((vader_array_t*) l4, l12);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    t5 = (void*) &vader_data_48;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    l12 = vader_c_emit_c_ast_initializer_list(l4);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a4_obj, 718u);
    _a4_obj->f_name = 2500u;
    _a4_obj->f_length = vader_ref_box(l6);
    _a4_obj->f_value = l12;
    l6 = (void*) _a4_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a5_obj, 727u);
    _a5_obj->f_storage = l3;
    _a5_obj->f_constant = false;
    _a5_obj->f_type = 2449u;
    _a5_obj->f_declarator = l6;
    l6 = (void*) _a5_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l6));
    l4 = std_iter_clone__CAddressOf___CBinary___CCall___CCast___CCastToTypeOf___CCompoundLiteral___CConditional___CDesignated___CIndex___CInitializerList___CIntegerLiteral___CLocal___CMember___CNumber___CParenthesized___CSequence___CStringLiterals___CTemporary___CUnary___CVerbatim(l4);
    l5 = ((vader_array_t*) l2)->length;
    l7 = (size_t) 0;
    while ((l7 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t2 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
        l8 = (size_t) (int64_t) t2;
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        t4 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        if (!(t4.tag == 531u)) {
            l6 = std_core_new_byte_buffer((size_t) 35);
            l10 = (size_t) 0;
            l10 = std_core_write_string_at(l6, l10, 2480u);
            t2 = ((int64_t) (size_t) l8);
            l11 = (uint64_t) (int64_t) t2;
            l10 = std_core_write_unsigned(l6, l10, l11);
            l10 = std_core_write_string_at(l6, l10, 825u);
            t3 = std_core_finish_buffer(l6, l10);
            t4 = vader_c_emit_c_ast_verbatim(t3);
            l12 = vader_c_emit_c_ast_address_of(t4);
            vader_array_push((vader_array_t*) l4, l12);
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    t5 = (void*) &vader_data_48;
    vader_array_t* _a8_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    l2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) INT64_C(0));
    l12 = vader_c_emit_c_ast_initializer_list(l4);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a9_obj, 718u);
    _a9_obj->f_name = 2502u;
    _a9_obj->f_length = vader_ref_box(l2);
    _a9_obj->f_value = l12;
    l2 = (void*) _a9_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a10_obj, 727u);
    _a10_obj->f_storage = l3;
    _a10_obj->f_constant = false;
    _a10_obj->f_type = 2556u;
    _a10_obj->f_declarator = l2;
    l2 = (void*) _a10_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    t5 = (void*) &vader_data_50;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    l2 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) INT64_C(0));
    t5 = (void*) &vader_data_49;
    vader_array_t* _a12_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
    l6 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) INT64_C(0));
    t5 = (void*) &vader_data_49;
    vader_array_t* _a13_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
    l9 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) INT64_C(0));
    t5 = (void*) &vader_data_50;
    vader_array_t* _a14_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
    l13 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) INT64_C(0));
    t5 = (void*) &vader_data_50;
    vader_array_t* _a15_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
    l14 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
    t0 = ((vader_array_t*) l4)->length;
    l12 = vader_c_emit_c_ast_unsigned(((int64_t) (size_t) t0));
    l15 = vader_c_emit_c_ast_verbatim(2502u);
    vader_array_t* _a16_arr = vader_array_new(181u, 7u, 13u, 1359u);
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 6u] = l15.payload.obj;
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 5u] = l12.payload.obj;
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 4u] = l14;
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 3u] = l13;
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 2u] = l9;
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 1u] = l6;
    ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = l2;
    t5 = (void*) _a16_arr;
    l12 = vader_c_emit_c_ast_initializer_list(t5);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a17_obj, 718u);
    _a17_obj->f_name = 2501u;
    _a17_obj->f_length = vader_box_obj(0u, NULL);
    _a17_obj->f_value = l12;
    l2 = (void*) _a17_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a18_obj, 727u);
    _a18_obj->f_storage = l3;
    _a18_obj->f_constant = false;
    _a18_obj->f_type = 2496u;
    _a18_obj->f_declarator = l2;
    l2 = (void*) _a18_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_if_open(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    vader_c_emit_assert_stack_empty(l0, 1770u);
    l1 = vader_c_emit_expression_of(l1);
    vader_c_emit_open_if(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_import_shims(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    size_t l6, l7;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_box_t l14 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l14, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l13, &l15, &t4 };
    vader_string_t* gc_atom_roots[5] = { &l9, &l10, &l11, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    if (t0) {
        vader_c_emit_emit_mirrored_struct_typedefs(l0, l1);
    }
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(10u, 0u, 0u, 230u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(10u, 0u, 0u, 230u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l5 = (void*) _a3_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l6);
    l5 = (void*) _a4_arr;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports)->length;
    while ((l6 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        t0 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_is_extern;
        if (t0) {
            l9 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_extern_name;
            t0 = std_core____Contains_contains__string(l3, l9);
            if (!(t0)) {
                l10 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_extern_name;
                vader_array_push((vader_array_t*) l3, vader_box_string(230u, l10));
                t1 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                if (t1 != 0u) {
                    l11 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                    t0 = std_core____Contains_contains__string(l4, l11);
                    if (!(t0)) {
                        l12 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                        vader_array_push((vader_array_t*) l4, vader_box_string(230u, l12));
                    }
                } else {
                    l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
                    l14 = vader_c_emit_extern_decl(l8, l13);
                    vader_array_push((vader_array_t*) l2, l14);
                }
            }
        }
        l15 = vader_c_emit_import_shim(l0, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l15));
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a6_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l3 = (void*) _a6_arr;
    l6 = ((vader_array_t*) l4)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l6);
    l3 = (void*) _a7_arr;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        t3 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l7];
        t1 = t3.payload.s;
        l8 = vader_c_emit_include_of(t1);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a9_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(230u, 487u);
    t4 = (void*) _a9_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a10_obj, 745u);
    _a10_obj->f_comment = t4;
    _a10_obj->f_items = l3;
    l3 = (void*) _a10_obj;
    vader_c_emit_c_ast_print_section(l1, l3);
    vader_array_t* _a11_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a11_arr->buf)[_a11_arr->offset + 0u] = vader_box_string(230u, 742u);
    t4 = (void*) _a11_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a12_obj, 745u);
    _a12_obj->f_comment = t4;
    _a12_obj->f_items = l2;
    l2 = (void*) _a12_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a13_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a13_arr->buf)[_a13_arr->offset + 0u] = vader_box_string(230u, 1083u);
    l2 = (void*) _a13_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l4 = vader_c_emit_crossing_mirrors(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module);
    l3 = vader_c_emit_c_struct_layout_asserts(l3, l4);
    vader_struct_vader_c_emit_c_ast_CSection_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a14_obj, 745u);
    _a14_obj->f_comment = l2;
    _a14_obj->f_items = l3;
    l2 = (void*) _a14_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a15_arr = vader_array_new(10u, 0u, 0u, 230u);
    t4 = (void*) _a15_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a16_obj, 745u);
    _a16_obj->f_comment = t4;
    _a16_obj->f_items = l5;
    l2 = (void*) _a16_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_internal_forward_decls(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l6;
    int32_t l7;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l3 = (void*) _a0_arr;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        t0 = vader_c_emit_module_function_storage(l0, l7);
        if (t0 == INT32_C(0)) {
            t1 = vader_c_emit_signature_for(l0, l7);
            vader_struct_vader_c_emit_c_ast_CPrototype_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
            vader_obj_header_init(_a2_obj, 742u);
            _a2_obj->f_signature = t1;
            l8 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a3_arr = vader_array_new(10u, 0u, 0u, 230u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a4_obj, 745u);
    _a4_obj->f_comment = t1;
    _a4_obj->f_items = l3;
    l3 = (void*) _a4_obj;
    vader_c_emit_c_ast_print_section(l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_local_decls(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    size_t l7, l10, l11, l14;
    uint8_t l12;
    uint64_t l15;
    vader_string_t l16 = 0;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &l9, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 1u, 236u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(10u, 0u, 0u, 230u);
    l9 = (void*) _a1_arr;
    l10 = (size_t) 0;
    l11 = ((vader_array_t*) l6)->length;
    while ((l10 < l11)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        if (((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val == INT32_C(16)) {
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
        l12 = ((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val;
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
        l13 = std_core_new_byte_buffer((size_t) 21);
        l14 = (size_t) 0;
        l14 = std_core_write_string_at(l13, l14, 1879u);
        t1 = (l7 + l10);
        l15 = (uint64_t) (int64_t) t1;
        l14 = std_core_write_unsigned(l13, l14, l15);
        l16 = std_core_finish_buffer(l13, l14);
        vader_array_push((vader_array_t*) l9, vader_box_string(230u, l16));
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
    }
    vader_c_emit_emit_slot_decls(l1, l8, l9, l2, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_local_field(void* l0, void* l1) {
    int32_t l2, l3, l6;
    void* l4 = NULL;
    void* l5 = NULL;
    uint8_t l7;
    int32_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_type_id;
    l3 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_field_index;
    t0 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_slot;
    vader_struct_vader_c_emit_c_ast_CLocal_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
    vader_obj_header_init(_a0_obj, 734u);
    _a0_obj->f_slot = t0;
    l4 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function;
    l6 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_slot;
    l7 = vader_c_emit_slot_val_type(l5, l6);
    vader_c_emit_push_struct_field(l0, l2, l3, vader_ref_box(l4), l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_local_get(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    uint8_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function;
    l3 = ((vader_struct_vader_bytecode_LocalGet_t*) l1)->f_slot;
    l4 = vader_c_emit_slot_val_type(l2, l3);
    if (!(l4 == INT32_C(16))) {
        l3 = ((vader_struct_vader_bytecode_LocalGet_t*) l1)->f_slot;
        vader_c_emit_push_local_ref(l0, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_local_set(void* l0, int32_t l1, bool l2) {
    uint8_t l3;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_slot_val_type(((vader_struct_vader_c_emit_FnState_t*) l0)->f_function, l1);
    if (l3 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_materialize_stack_for_slot(l0, l1);
    l4 = vader_c_emit_pop(l0);
    vader_struct_vader_c_emit_c_ast_CLocal_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
    vader_obj_header_init(_a0_obj, 734u);
    _a0_obj->f_slot = l1;
    l5 = (void*) _a0_obj;
    l4 = vader_c_emit_coerced_as(l0, l4, l3);
    vader_c_emit_assign(l0, vader_ref_box(l5), l4);
    if (l2) {
        vader_c_emit_push_local_ref(l0, l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_main(void* l0, void* l1, vader_string_t l2) {
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
    vader_struct_vader_c_emit_c_ast_CParameter_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
    vader_obj_header_init(_a0_obj, 739u);
    _a0_obj->f_type = 1804u;
    _a0_obj->f_name = 1239u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CParameter_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
    vader_obj_header_init(_a1_obj, 739u);
    _a1_obj->f_type = 1414u;
    _a1_obj->f_name = 1242u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(60u, 2u, 13u, 739u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3;
    l3 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a3_obj, 747u);
    _a3_obj->f_storage = (uint8_t) 1;
    _a3_obj->f_inline_v = false;
    _a3_obj->f_result = 1804u;
    _a3_obj->f_name = 1917u;
    _a3_obj->f_parameters = l3;
    l3 = (void*) _a3_obj;
    t0 = vader_c_emit_main_body(l0, l2);
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a4_obj, 708u);
    _a4_obj->f_body = t0;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l5 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a6_obj, 725u);
    _a6_obj->f_signature = l3;
    _a6_obj->f_prologue = l5;
    _a6_obj->f_body = l4;
    l3 = (void*) _a6_obj;
    vader_c_emit_c_ast_print_item(l1, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_make_closure(void* l0, void* l1) {
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
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_aux(l0, 1424u);
    l4 = vader_c_emit_gc_allocation(2491u);
    vader_c_emit_declare(l0, 2492u, l3, l4);
    l5 = ((vader_struct_vader_bytecode_MakeClosure_t*) l1)->f_env_type_id;
    vader_c_emit_init_object_header(l0, l3, l5);
    t0 = concat_2(l3, 288u);
    l4 = vader_c_emit_c_ast_verbatim(t0);
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l5 = ((vader_struct_vader_bytecode_MakeClosure_t*) l1)->f_function_index;
    l7 = vader_c_emit_fn_symbol_name(l6, l5);
    t0 = concat_2(2488u, l7);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    l8 = vader_c_emit_c_ast_address_of(t1);
    l8 = vader_c_emit_c_ast_cast(2556u, l8);
    vader_c_emit_assign(l0, l4, l8);
    t0 = concat_2(l3, 290u);
    l4 = vader_c_emit_c_ast_verbatim(t0);
    l2 = vader_c_emit_object_pointer_of(l2);
    vader_c_emit_assign(l0, l4, l2);
    l2 = vader_c_emit_c_ast_verbatim(l3);
    vader_c_emit_push_object(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_memory_copy(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_buffer_pointer(t0);
    l4 = vader_c_emit_as_size(l4);
    l3 = vader_c_emit_buffer_pointer(l3);
    l2 = vader_c_emit_as_size(l2);
    l1 = vader_c_emit_as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(181u, 5u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2469u, l6);
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_mirrored_struct_typedefs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l4, l5;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (t0.tag == 536u) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            l6 = t0.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_c_name;
            if (t1 != 0u) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                vader_struct_vader_c_emit_c_ast_CStructForward_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStructForward_t));
                vader_obj_header_init(_a5_obj, 751u);
                _a5_obj->f_name = t1;
                l7 = (void*) _a5_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l7));
                l8 = vader_c_emit_struct_definition(l0, l6, l4);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
            }
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a6_arr = vader_array_new(10u, 0u, 0u, 230u);
    t3 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a7_obj, 745u);
    _a7_obj->f_comment = t3;
    _a7_obj->f_items = l2;
    l2 = (void*) _a7_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a8_arr = vader_array_new(10u, 0u, 0u, 230u);
    t3 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 745u);
    _a9_obj->f_comment = t3;
    _a9_obj->f_items = l3;
    l2 = (void*) _a9_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_multi_call(void* l0, vader_string_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    size_t l6, l7;
    uint8_t l8;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_results;
    vader_array_t* _a0_arr = vader_array_new(61u, 0u, 13u, 753u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) l4)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l6);
    l5 = (void*) _a1_arr;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) l4)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 236u);
        l8 = ((uint8_t) t0.payload.i);
        l9 = vader_c_emit_new_temporary(l0, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l9));
        l10 = vader_c_emit_c_ast_address_of(vader_ref_box(l9));
        vader_array_push((vader_array_t*) l2, l10);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l10 = vader_c_emit_c_ast_call(l1, l2);
    vader_c_emit_evaluate(l0, l10);
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) l4)->length;
    while ((l6 < l7)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l9 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l6, 236u);
        l8 = ((uint8_t) t0.payload.i);
        vader_c_emit_push_temporary(l0, l9, l8);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_multi_return(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    size_t l2, l5, l6;
    vader_string_t l3 = 0;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    uint8_t l9;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l7, &l8, &l10, &t4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l11, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature)->f_results;
    l2 = ((vader_array_t*) l1)->length;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if ((t0 < l2)) {
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
        l3 = concat_2(2398u, l3);
        vader_c_emit_unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 706u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l4 = (void*) _a1_arr;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        t2 = ((l2 - INT64_C(1)) - l5);
        l6 = (size_t) (int64_t) t2;
        l7 = vader_c_emit_pop(l0);
        l3 = vader_c_emit_out_param_name(l6);
        t3 = concat_2(264u, l3);
        l8 = vader_c_emit_c_ast_verbatim(t3);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t4 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 236u);
        l9 = ((uint8_t) t4.payload.i);
        l10 = vader_c_emit_coerced_as(l0, l7, l9);
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a3_obj, 706u);
        _a3_obj->f_target = l8;
        _a3_obj->f_value = l10;
        _a3_obj->f_operator = vader_box_obj(0u, NULL);
        l11 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l11));
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a4_obj, 743u);
    _a4_obj->f_stores = l4;
    _a4_obj->f_value = vader_box_obj(0u, NULL);
    _a4_obj->f_snapshot_type = 0u;
    _a4_obj->f_pops_frame = false;
    l1 = (void*) _a4_obj;
    vader_c_emit_return_statement(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    uint8_t l5, l9;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l19 = 0;
    int32_t l8, l10;
    size_t l12, l13, l15, l17;
    vader_box_t l14 = vader_box_null(), l20 = vader_box_null(), l22 = vader_box_null();
    uint64_t l18, l21;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l14, &l20, &l22, &t3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l6, &l11, &l16, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l7, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_c_emit_element_storage_kind(((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements);
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l7 = ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_element_type_name;
    l8 = vader_c_emit_type_index_for_name(l6, l7);
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l9 = vader_c_emit_global_storage(t0);
    l10 = vader_c_emit_array_type_index_for_element(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types, l8);
    vader_struct_vader_c_emit_PoolArray_t* _a0_obj = (vader_struct_vader_c_emit_PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_PoolArray_t));
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_name = l3;
    _a0_obj->f_storage = l9;
    _a0_obj->f_constant = true;
    _a0_obj->f_type_id = l10;
    _a0_obj->f_element_tag = l8;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l11 = (void*) _a1_arr;
    l12 = (size_t) 0;
    l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements)->length;
    while ((l12 < l13)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
        l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
        if (l5 == INT32_C(0)) {
            l7 = l3;
            l15 = vader_host_std_core_byte_len(l7);
            l16 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l15));
            l17 = (size_t) 0;
            l17 = std_core_write_string_at(l16, l17, l7);
            l17 = std_core_write_string_at(l16, l17, 842u);
            t1 = ((int64_t) (size_t) l12);
            l18 = (uint64_t) (int64_t) t1;
            l17 = std_core_write_unsigned(l16, l17, l18);
            l19 = std_core_finish_buffer(l16, l17);
            l20 = vader_c_emit_box_slot(l0, l1, l14, l19, l8, l4);
            vader_array_push((vader_array_t*) l11, l20);
        } else if (l14.tag == 539u) {
            t2 = l14.payload.obj;
            l21 = ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_bits;
            l22 = vader_c_emit_data_slot(l5, l21);
            vader_array_push((vader_array_t*) l11, l22);
        }
        t1 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t1;
    }
    l7 = vader_c_emit_c_type_for_array_kind(l5);
    vader_c_emit_push_pool_array(l1, l6, l7, l5, l11);
    t3 = vader_c_emit_c_ast_verbatim(l3);
    l14 = vader_c_emit_c_ast_address_of(t3);
    t3 = vader_c_emit_c_ast_cast(2449u, l14);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_emit_op(void* l0, int32_t l1, vader_box_t l2) {
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
    vader_c_emit_invalidate_header_cache(l0, l2);
    if (l2.tag == 593u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 613u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 574u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 546u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 561u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 644u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 662u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 638u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_local_get(l0, l3);
    } else if (l2.tag == 639u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        vader_c_emit_emit_local_set(l0, l4, false);
    } else if (l2.tag == 640u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        vader_c_emit_emit_local_set(l0, l4, true);
    } else if (l2.tag == 637u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_local_field(l0, l3);
    } else if (l2.tag == 650u) {
        vader_c_emit_emit_return(l0);
    } else if (l2.tag == 651u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value;
        vader_c_emit_emit_return_lit(l0, l5);
    } else if (l2.tag == 567u) {
        vader_c_emit_drop_top(l0);
    } else if (l2.tag == 558u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call(l0, l3);
    } else if (l2.tag == 559u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call_import(l0, l3);
    } else if (l2.tag == 560u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call_indirect(l0, l3);
    } else if (l2.tag == 684u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_virtual_call(l0, l3);
    } else if (l2.tag == 587u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_fn_ref(l0, l3);
    } else if (l2.tag == 586u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_fn_addr(l0, l3);
    } else if (l2.tag == 642u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_make_closure(l0, l3);
    } else if (l2.tag == 628u) {
        vader_c_emit_emit_if_open(l0);
    } else if (l2.tag == 568u) {
        vader_c_emit_emit_else(l0);
    } else if (l2.tag == 571u) {
        vader_c_emit_emit_end(l0, l1);
    } else if (l2.tag == 544u) {
        vader_c_emit_emit_open_scope(l0, l1, (uint8_t) 0);
    } else if (l2.tag == 641u) {
        vader_c_emit_emit_open_scope(l0, l1, (uint8_t) 1);
    } else if (l2.tag == 551u) {
        vader_c_emit_emit_branch(l0, l1, false);
    } else if (l2.tag == 552u) {
        vader_c_emit_emit_branch(l0, l1, true);
    } else if (l2.tag == 549u) {
        vader_c_emit_push_unop(l0, 172u, (uint8_t) 12);
    } else if (l2.tag == 667u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_new(l0, l3);
    } else if (l2.tag == 666u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_get(l0, l3);
    } else if (l2.tag == 668u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_set(l0, l3);
    } else if (l2.tag == 515u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_new(l0, l3);
    } else if (l2.tag == 514u) {
        vader_c_emit_emit_array_len(l0);
    } else if (l2.tag == 516u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_push(l0, l3);
    } else if (l2.tag == 513u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_get(l0, l3);
    } else if (l2.tag == 520u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_set(l0, l3);
    } else if (l2.tag == 521u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_slice(l0, l3);
    } else if (l2.tag == 519u) {
        vader_c_emit_emit_array_repeat(l0);
    } else if (l2.tag == 517u) {
        vader_c_emit_emit_array_push_all(l0);
    } else if (l2.tag == 512u) {
        vader_c_emit_emit_array_copy(l0);
    } else if (l2.tag == 518u) {
        vader_c_emit_emit_array_remove_last(l0);
    } else if (l2.tag == 511u) {
        vader_c_emit_emit_array_clear(l0);
    } else if (l2.tag == 563u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_data_const_op(l0, l3);
    } else if (l2.tag == 670u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_type_const(l0, l3);
    } else if (l2.tag == 669u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_type_check(l0, l3);
    } else if (l2.tag == 646u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_ref_cast(l0, l3);
    } else if (l2.tag == 649u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_retag_op(l0, l3);
    } else if (l2.tag == 683u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Unreachable_t*) t0)->f_reason;
        vader_c_emit_unreachable(l0, l6);
    } else if (l2.tag == 562u) {
        t0 = l2.payload.obj;
        l7 = vader_c_emit_convert_target_val(((vader_struct_vader_bytecode_Convert_t*) t0)->f_target);
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        vader_c_emit_emit_convert(l0, l7, l6);
    } else if (l2.tag == 652u) {
        vader_c_emit_emit_size_of_type(l0);
    } else if (l2.tag == 588u) {
        vader_c_emit_push_binop(l0, (uint8_t) 3, (uint8_t) 2);
    } else if (l2.tag == 607u) {
        vader_c_emit_push_binop(l0, (uint8_t) 4, (uint8_t) 2);
    } else if (l2.tag == 601u) {
        vader_c_emit_push_binop(l0, (uint8_t) 0, (uint8_t) 2);
    } else if (l2.tag == 594u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 2);
    } else if (l2.tag == 600u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 2);
    } else if (l2.tag == 603u) {
        vader_c_emit_push_unop(l0, 282u, (uint8_t) 2);
    } else if (l2.tag == 590u) {
        vader_c_emit_push_unop(l0, 2607u, (uint8_t) 2);
    } else if (l2.tag == 589u) {
        vader_c_emit_push_binop(l0, (uint8_t) 13, (uint8_t) 2);
    } else if (l2.tag == 591u) {
        vader_c_emit_push_binop(l0, (uint8_t) 15, (uint8_t) 2);
    } else if (l2.tag == 592u) {
        vader_c_emit_push_binop(l0, (uint8_t) 14, (uint8_t) 2);
    } else if (l2.tag == 604u) {
        vader_c_emit_push_binop(l0, (uint8_t) 5, (uint8_t) 2);
    } else if (l2.tag == 605u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 2);
    } else if (l2.tag == 606u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 7);
    } else if (l2.tag == 595u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 2);
    } else if (l2.tag == 602u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 2);
    } else if (l2.tag == 599u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 2);
    } else if (l2.tag == 598u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 2);
    } else if (l2.tag == 597u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 2);
    } else if (l2.tag == 596u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 2);
    } else if (l2.tag == 608u) {
        vader_c_emit_push_binop(l0, (uint8_t) 3, (uint8_t) 3);
    } else if (l2.tag == 627u) {
        vader_c_emit_push_binop(l0, (uint8_t) 4, (uint8_t) 3);
    } else if (l2.tag == 621u) {
        vader_c_emit_push_binop(l0, (uint8_t) 0, (uint8_t) 3);
    } else if (l2.tag == 614u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 3);
    } else if (l2.tag == 620u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 3);
    } else if (l2.tag == 623u) {
        vader_c_emit_push_i64_neg(l0);
    } else if (l2.tag == 609u) {
        vader_c_emit_push_binop(l0, (uint8_t) 13, (uint8_t) 3);
    } else if (l2.tag == 611u) {
        vader_c_emit_push_binop(l0, (uint8_t) 15, (uint8_t) 3);
    } else if (l2.tag == 612u) {
        vader_c_emit_push_binop(l0, (uint8_t) 14, (uint8_t) 3);
    } else if (l2.tag == 610u) {
        vader_c_emit_push_unop(l0, 2607u, (uint8_t) 3);
    } else if (l2.tag == 624u) {
        vader_c_emit_push_binop(l0, (uint8_t) 5, (uint8_t) 3);
    } else if (l2.tag == 625u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 3);
    } else if (l2.tag == 626u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 8);
    } else if (l2.tag == 615u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 3);
    } else if (l2.tag == 622u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 3);
    } else if (l2.tag == 619u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 3);
    } else if (l2.tag == 618u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 3);
    } else if (l2.tag == 617u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 3);
    } else if (l2.tag == 616u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 3);
    } else if (l2.tag == 671u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 7);
    } else if (l2.tag == 676u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 7);
    } else if (l2.tag == 675u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 7);
    } else if (l2.tag == 674u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 7);
    } else if (l2.tag == 673u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 7);
    } else if (l2.tag == 672u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 7);
    } else if (l2.tag == 677u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 8);
    } else if (l2.tag == 682u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 8);
    } else if (l2.tag == 681u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 8);
    } else if (l2.tag == 680u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 8);
    } else if (l2.tag == 679u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 8);
    } else if (l2.tag == 678u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 8);
    } else if (l2.tag == 573u) {
        vader_c_emit_push_binop(l0, (uint8_t) 3, (uint8_t) 11);
    } else if (l2.tag == 584u) {
        vader_c_emit_push_binop(l0, (uint8_t) 4, (uint8_t) 11);
    } else if (l2.tag == 581u) {
        vader_c_emit_push_binop(l0, (uint8_t) 0, (uint8_t) 11);
    } else if (l2.tag == 575u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 11);
    } else if (l2.tag == 583u) {
        vader_c_emit_push_unop(l0, 282u, (uint8_t) 11);
    } else if (l2.tag == 576u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 11);
    } else if (l2.tag == 582u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 11);
    } else if (l2.tag == 580u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 11);
    } else if (l2.tag == 579u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 11);
    } else if (l2.tag == 578u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 11);
    } else if (l2.tag == 577u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 11);
    } else if (l2.tag == 547u) {
        vader_c_emit_push_binop(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 548u) {
        vader_c_emit_push_binop(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 545u) {
        vader_c_emit_push_binop(l0, (uint8_t) 16, (uint8_t) 12);
    } else if (l2.tag == 550u) {
        vader_c_emit_push_binop(l0, (uint8_t) 17, (uint8_t) 12);
    } else if (l2.tag == 663u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 14);
    } else if (l2.tag == 664u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 14);
    } else if (l2.tag == 661u) {
        vader_c_emit_emit_string_compare(l0);
    } else if (l2.tag == 665u) {
        vader_c_emit_emit_string_slice(l0);
    } else if (l2.tag == 647u) {
        vader_c_emit_push_binop_any(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 648u) {
        vader_c_emit_push_binop_any(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 566u) {
        vader_c_emit_emit_defer_push(l0);
    } else if (l2.tag == 565u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_defer_pop_exec(l0, l3);
    } else if (l2.tag == 553u) {
        vader_c_emit_emit_buffer_new(l0);
    } else if (l2.tag == 636u) {
        vader_c_emit_emit_buffer_load(l0, 2468u, (uint8_t) 2);
    } else if (l2.tag == 631u) {
        vader_c_emit_emit_buffer_load(l0, 2466u, (uint8_t) 2);
    } else if (l2.tag == 632u) {
        vader_c_emit_emit_buffer_load(l0, 2467u, (uint8_t) 3);
    } else if (l2.tag == 630u) {
        vader_c_emit_emit_buffer_load(l0, 2465u, (uint8_t) 11);
    } else if (l2.tag == 660u) {
        vader_c_emit_emit_buffer_store(l0, 2474u, 2376u);
    } else if (l2.tag == 655u) {
        vader_c_emit_emit_buffer_store(l0, 2472u, 1806u);
    } else if (l2.tag == 656u) {
        vader_c_emit_emit_buffer_store(l0, 2473u, 1807u);
    } else if (l2.tag == 654u) {
        vader_c_emit_emit_buffer_store(l0, 2471u, 1505u);
    } else if (l2.tag == 634u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LoadSlotI32_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1806u, (uint8_t) 2, l8);
    } else if (l2.tag == 635u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LoadSlotI64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1807u, (uint8_t) 3, l8);
    } else if (l2.tag == 633u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_LoadSlotF64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1505u, (uint8_t) 11, l8);
    } else if (l2.tag == 658u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_StoreSlotI32_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1806u, (uint8_t) 2, l8);
    } else if (l2.tag == 659u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_StoreSlotI64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1807u, (uint8_t) 3, l8);
    } else if (l2.tag == 657u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_StoreSlotF64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1505u, (uint8_t) 11, l8);
    } else if (l2.tag == 643u) {
        vader_c_emit_emit_memory_copy(l0);
    } else if (l2.tag == 554u) {
        vader_c_emit_emit_buffer_to_string(l0);
    } else if (l2.tag == 555u) {
        vader_c_emit_emit_buffer_write_string(l0);
    } else if (l2.tag == 585u) {
        vader_c_emit_emit_f64_to_bits(l0);
    } else if (l2.tag == 543u) {
        vader_c_emit_emit_bits_to_f64(l0);
    } else if (l2.tag == 572u) {
        vader_c_emit_emit_f32_to_bits(l0);
    } else {
        if (!(l2.tag == 542u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_c_emit_emit_bits_to_f32(l0);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_open_scope(void* l0, int32_t l1, uint8_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    size_t l4;
    int64_t l5;
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
    l3 = std_core_new_byte_buffer((size_t) 36);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 2121u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 241u);
    l6 = std_core_finish_buffer(l3, l4);
    vader_c_emit_assert_stack_empty(l0, l6);
    if (l2 == INT32_C(1)) {
        vader_c_emit_pc_plan_for_loop(l0, l1, &t0, &t1, &t2, &t3);
        l12 = t3;
        l11 = t2;
        l10 = t1;
        if (t0 == INT32_C(0)) {
            l7 = vader_box_obj(0u, NULL);
        } else {
            vader_struct_vader_c_emit_PushCache_t* _a0_obj = (vader_struct_vader_c_emit_PushCache_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_PushCache_t));
            vader_obj_header_init(_a0_obj, 696u);
            _a0_obj->f_opener_pc = l10;
            _a0_obj->f_slot = l11;
            _a0_obj->f_kind = l12;
            t4 = (void*) _a0_obj;
            l7 = vader_ref_box(t4);
        }
        if (!(l7.tag == 0u)) {
            l3 = l7.payload.obj;
            vader_c_emit_pc_emit_preheader(l0, l3);
            l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches;
            l8 = l7.payload.obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        }
    }
    if (l2 == INT32_C(1)) {
        l9 = std_core____Contains_contains__i32(((vader_struct_vader_c_emit_FnState_t*) l0)->f_continue_targets, l1);
    } else {
        l9 = false;
    }
    if (l9) {
        l3 = std_core_new_byte_buffer((size_t) 25);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1910u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        vader_c_emit_open_scope(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = 0u;
    vader_c_emit_open_scope(l0, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_preamble(void* l0, vader_string_t l1) {
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
    vader_array_t* _a0_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(230u, l1);
    l2 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a1_obj, 730u);
    _a1_obj->f_path = 2415u;
    _a1_obj->f_system = false;
    l3 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a2_obj, 730u);
    _a2_obj->f_path = 2198u;
    _a2_obj->f_system = true;
    l4 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a3_obj, 730u);
    _a3_obj->f_path = 2199u;
    _a3_obj->f_system = true;
    l5 = (void*) _a3_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a4_obj, 730u);
    _a4_obj->f_path = 2222u;
    _a4_obj->f_system = true;
    l6 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(183u, 4u, 13u, 1367u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 3u] = l6;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l5;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l4;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l3;
    l3 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a6_obj, 745u);
    _a6_obj->f_comment = l2;
    _a6_obj->f_items = l3;
    l2 = (void*) _a6_obj;
    vader_c_emit_c_ast_print_section(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_prim_data_entry(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l4, l6;
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
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_items)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_items;
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l7 = (uint64_t) (int64_t) t0;
        l8 = vader_c_emit_data_slot(((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_kind, l7);
        vader_array_push((vader_array_t*) l3, l8);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l9 = vader_c_emit_c_type_for_array_kind(((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_kind);
    l10 = ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_kind;
    vader_c_emit_push_pool_array(l0, l1, l9, l10, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_ref_cast(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    size_t l4;
    uint8_t l5;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_RefCast_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = vader_c_emit_val_type_of_bc_type(t2);
    l2 = vader_c_emit_coerced_as(l0, l2, l5);
    vader_c_emit_push_into_temporary(l0, l2, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_retag_op(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    uint8_t l4;
    int32_t l5;
    uint8_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_val_of(l2);
    if (t0 == INT32_C(19)) {
        l3 = vader_c_emit_expression_of(l2);
        vader_c_emit_push_into_temporary(l0, l3, (uint8_t) 19);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_c_emit_val_of(l2);
    if (t0 == INT32_C(18)) {
        t1 = vader_c_emit_expression_of(l2);
        l3 = vader_c_emit_ref_box(t1);
        vader_c_emit_push_into_temporary(l0, l3, (uint8_t) 19);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_c_emit_expression_of(l2);
    l4 = vader_c_emit_val_of(l2);
    l5 = ((vader_struct_vader_bytecode_Retag_t*) l1)->f_type_id;
    l3 = vader_c_emit_box_expr(l3, l4, l5);
    if (!(l2.tag == 700u)) {
        vader_c_emit_push_into_temporary(l0, l3, (uint8_t) 19);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_push_lit(l0, (uint8_t) 19, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_return(void* l0) {
    uint8_t l1;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature);
    if ((t0 > INT64_C(1))) {
        vader_c_emit_emit_multi_return(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature);
    if (l1 == INT32_C(16)) {
        vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 706u);
        t1 = (void*) _a0_arr;
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a1_obj, 743u);
        _a1_obj->f_stores = t1;
        _a1_obj->f_value = vader_box_obj(0u, NULL);
        _a1_obj->f_snapshot_type = 0u;
        _a1_obj->f_pops_frame = false;
        l2 = (void*) _a1_obj;
        vader_c_emit_return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (!(t0 == INT64_C(0))) {
        l4 = vader_c_emit_pop(l0);
        vader_array_t* _a2_arr = vader_array_new(54u, 0u, 13u, 706u);
        l2 = (void*) _a2_arr;
        l4 = vader_c_emit_coerced_as(l0, l4, l1);
        l3 = vader_c_emit_c_type_for_val_bare(l1);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a3_obj, 743u);
        _a3_obj->f_stores = l2;
        _a3_obj->f_value = l4;
        _a3_obj->f_snapshot_type = l3;
        _a3_obj->f_pops_frame = false;
        l2 = (void*) _a3_obj;
        vader_c_emit_return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
    l3 = concat_2(2398u, l3);
    vader_c_emit_unreachable(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_return_lit(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    uint8_t l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_const_lit_c(((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx, l1);
    l4 = vader_c_emit_const_val(l1);
    l5 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature);
    l3 = vader_c_emit_coerce_expr(l2, l3, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 706u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a1_obj, 743u);
    _a1_obj->f_stores = t0;
    _a1_obj->f_value = l3;
    _a1_obj->f_snapshot_type = 0u;
    _a1_obj->f_pops_frame = false;
    l2 = (void*) _a1_obj;
    vader_c_emit_return_statement(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_size_of_type(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &t0, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    t1 = vader_c_emit_expression_of(t0);
    l1 = vader_c_emit_payload(t1, 2008u);
    l1 = vader_c_emit_c_ast_around(239u, l1, 783u);
    vader_c_emit_push_into_temporary(l0, l1, (uint8_t) 9);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_c_emit_emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l5 = 0;
    void* l7 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l6 };
    void** gc_raw_roots[2] = { &l0, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_array_header_pointer(l1);
    l5 = vader_c_emit_bind_array_local(l0, l4);
    if (l3) {
        { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_c_emit_c_ast_verbatim(l5);
    l6 = vader_c_emit_expression_of(l2);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l7 = (void*) _a0_arr;
    vader_c_emit_statement_macro(l0, 743u, l7);
    { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6) {
    void* l7 = NULL;
    void* l27 = NULL;
    void* l31 = NULL;
    void* l33 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    size_t l8, l9, l13, l14, l19, l20, l28, l29;
    uint8_t l10;
    bool l11, l12;
    vader_string_t l15 = 0;
    vader_string_t l21 = 0;
    vader_string_t l25 = 0;
    vader_string_t l30 = 0;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l26 = vader_box_null(), l32 = vader_box_null(), l34 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[10] = { &l16, &l17, &l18, &l22, &l23, &l24, &l26, &l32, &l34, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l27, &l31, &l33, &l35, &l36 };
    vader_string_t* gc_atom_roots[5] = { &l15, &l21, &l25, &l30, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 10u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 1u, 236u);
    l7 = (void*) _a0_arr;
    l8 = (size_t) 0;
    l9 = ((vader_array_t*) l1)->length;
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l8, 236u);
        l10 = ((uint8_t) t0.payload.i);
        t1 = std_core____Contains_contains__ValType(l7, l10);
        if (t1) {
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
            continue;
        }
        vader_array_push_u8((vader_array_t*) l7, (int32_t) (uint8_t) l10);
        if (l10 == INT32_C(18)) {
            l11 = true;
        } else {
            l11 = l10 == INT32_C(17);
        }
        t1 = vader_c_emit_is_ref_val(l10);
        if (t1) {
            l12 = !(l6);
        } else {
            l12 = false;
        }
        if (l10 == INT32_C(14)) {
            if (!(l6)) {
                l13 = (size_t) 0;
                l14 = ((vader_array_t*) l1)->length;
                while ((l13 < l14)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
                    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l13, 236u);
                    if (((int32_t) t0.payload.i) == l10) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
                        t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l13];
                        l15 = t0.payload.s;
                        l16 = vader_c_emit_c_ast_verbatim(328u);
                        l17 = vader_c_emit_c_ast_declaration(2526u, l15, l16);
                        vader_array_push((vader_array_t*) l0, l17);
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
                        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l13];
                        t3 = t0.payload.s;
                        t0 = vader_c_emit_c_ast_verbatim(t3);
                        l18 = vader_c_emit_c_ast_address_of(t0);
                        vader_array_push((vader_array_t*) l5, l18);
                    }
                    t2 = (l13 + INT64_C(1));
                    l13 = (size_t) (int64_t) t2;
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                continue;
            }
        }
        if (l11) {
            l19 = (size_t) 0;
            l20 = ((vader_array_t*) l1)->length;
            while ((l19 < l20)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l19)
                t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l19, 236u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l19)
                        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l19];
                        l21 = t0.payload.s;
                        l22 = vader_c_emit_c_ast_verbatim(545u);
                        l23 = vader_c_emit_c_ast_declaration(2556u, l21, l22);
                        vader_array_push((vader_array_t*) l0, l23);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l19)
                        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l19];
                        t3 = t0.payload.s;
                        t0 = vader_c_emit_c_ast_verbatim(t3);
                        l24 = vader_c_emit_c_ast_address_of(t0);
                        vader_array_push((vader_array_t*) l4, l24);
                    } else {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l19)
                        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l19];
                        l25 = t0.payload.s;
                        l26 = vader_c_emit_c_ast_declaration(2556u, l25, vader_box_obj(0u, NULL));
                        vader_array_push((vader_array_t*) l0, l26);
                    }
                }
                t2 = (l19 + INT64_C(1));
                l19 = (size_t) (int64_t) t2;
            }
        } else {
            vader_array_t* _a9_arr = vader_array_new(56u, 0u, 13u, 718u);
            l27 = (void*) _a9_arr;
            l28 = (size_t) 0;
            l29 = ((vader_array_t*) l1)->length;
            while ((l28 < l29)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l28)
                t0 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l28, 236u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l28)
                        t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l28];
                        l30 = t0.payload.s;
                        vader_array_t* _a12_arr = vader_array_new(181u, 0u, 13u, 1359u);
                        l31 = (void*) _a12_arr;
                        l32 = vader_c_emit_c_ast_call(2459u, l31);
                        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a13_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
                        vader_obj_header_init(_a13_obj, 718u);
                        _a13_obj->f_name = l30;
                        _a13_obj->f_length = vader_box_obj(0u, NULL);
                        _a13_obj->f_value = l32;
                        l33 = (void*) _a13_obj;
                        vader_array_push((vader_array_t*) l27, vader_ref_box(l33));
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l28)
                        t0 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l28];
                        t3 = t0.payload.s;
                        t0 = vader_c_emit_c_ast_verbatim(t3);
                        l34 = vader_c_emit_c_ast_address_of(t0);
                        vader_array_push((vader_array_t*) l3, l34);
                    } else {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l28)
                        t0 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l28];
                        t3 = t0.payload.s;
                        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
                        vader_obj_header_init(_a16_obj, 718u);
                        _a16_obj->f_name = t3;
                        _a16_obj->f_length = vader_box_obj(0u, NULL);
                        _a16_obj->f_value = vader_box_obj(0u, NULL);
                        l35 = (void*) _a16_obj;
                        vader_array_push((vader_array_t*) l27, vader_ref_box(l35));
                    }
                }
                t2 = (l28 + INT64_C(1));
                l28 = (size_t) (int64_t) t2;
            }
            t3 = vader_c_emit_c_type_for_val_bare(l10);
            vader_struct_vader_c_emit_c_ast_CDeclaration_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclaration_t));
            vader_obj_header_init(_a17_obj, 717u);
            _a17_obj->f_type = t3;
            _a17_obj->f_declarators = l27;
            l36 = (void*) _a17_obj;
            vader_array_push((vader_array_t*) l0, vader_ref_box(l36));
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_pop(l0);
    l6 = vader_c_emit_emit_slot_array_local(l0, l5, l4, l3);
    l4 = vader_c_emit_slot_index(l6, l4);
    l4 = vader_c_emit_typed_slot(l1, l6, l4);
    vader_c_emit_push_into_temporary(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_pop(l0);
    l6 = vader_c_emit_pop(l0);
    l7 = vader_c_emit_emit_slot_array_local(l0, l6, l5, l3);
    vader_c_emit_emit_typed_slot_write(l0, l7, l5, l4, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_str_data_entry(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    size_t l5, l7;
    vader_string_t l8 = 0;
    int32_t l9, l10;
    vader_box_t l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStrData_t*) l2)->f_values)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l6 = ((vader_struct_vader_bytecode_BcStrData_t*) l2)->f_values;
    l5 = ((vader_array_t*) l6)->length;
    l7 = (size_t) 0;
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        l9 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_element_tag;
        l10 = vader_c_emit_atom_for(l3, l8);
        l11 = vader_c_emit_boxed_string(l9, l10);
        vader_array_push((vader_array_t*) l4, l11);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_c_emit_push_pool_array(l0, l1, 2462u, (uint8_t) 0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_string_compare(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_operand_as(l0, l2, (uint8_t) 14);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 14);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2523u, l3);
    vader_c_emit_push_expr(l0, (uint8_t) 2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_string_slice(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_expression_of(t0);
    l2 = vader_c_emit_expression_of(l2);
    l1 = vader_c_emit_expression_of(l1);
    vader_array_t* _a0_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2525u, l4);
    vader_c_emit_push_into_temporary(l0, l1, (uint8_t) 14);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_struct_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    int32_t l3, l4;
    uint8_t l6;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = ((vader_struct_vader_bytecode_StructGet_t*) l1)->f_type_id;
    l4 = ((vader_struct_vader_bytecode_StructGet_t*) l1)->f_field_index;
    l5 = vader_c_emit_expression_of(l2);
    l6 = vader_c_emit_val_of(l2);
    vader_c_emit_push_struct_field(l0, l3, l4, l5, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_struct_new(void* l0, void* l1) {
    void* l2 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    size_t l3, l12;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    int32_t l6, l7, l9, l14;
    uint8_t l15;
    uint64_t l20;
    int64_t l21;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    size_t t4;
    bool t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[4] = { &l4, &l8, &l16, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l10, &l11, &l13, &t3 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l17, &l18, &l19, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 536u) {
        l2 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        l5 = t2.payload.s;
        t3 = l4.payload.obj;
        t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields)->length;
        l6 = ((int32_t) (size_t) t4);
        t2 = vader_c_emit_c_ast_verbatim(0u);
        vader_array_t* _a2_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t2.payload.obj;
        l2 = (void*) _a2_arr;
        t1 = ((int64_t) (int32_t) l6);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
        l2 = (void*) _a3_arr;
        l7 = INT32_C(0);
        while ((l7 < l6)) {
            l8 = vader_c_emit_pop(l0);
            l9 = ((l6 - INT32_C(1)) - l7);
            t3 = l4.payload.obj;
            l10 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields;
            t1 = ((int64_t) (int32_t) l9);
            l3 = (size_t) (int64_t) t1;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
            l11 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
            t1 = ((int64_t) (int32_t) l9);
            l12 = (size_t) (int64_t) t1;
            l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l14 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_type_index;
            l15 = vader_c_emit_val_type_of_field(l13, l14);
            l16 = vader_c_emit_coerced_as(l0, l8, l15);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l12)
            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l12, l16.payload.obj);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
            l7 = (l7 + INT32_C(1));
        }
        t5 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_stack;
        if (t5) {
            l17 = vader_c_emit_aux(l0, 2202u);
            l18 = vader_c_emit_aux(l0, 2008u);
            l10 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack_storages;
            vader_struct_vader_c_emit_StackStorage_t* _a6_obj = (vader_struct_vader_c_emit_StackStorage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackStorage_t));
            vader_obj_header_init(_a6_obj, 702u);
            _a6_obj->f_cname = l5;
            _a6_obj->f_storage = l17;
            l11 = (void*) _a6_obj;
            vader_array_push((vader_array_t*) l10, vader_ref_box(l11));
            l19 = concat_2(l5, 264u);
            t2 = vader_c_emit_c_ast_verbatim(l17);
            l8 = vader_c_emit_c_ast_address_of(t2);
            vader_c_emit_declare(l0, l19, l18, l8);
            l17 = l18;
        } else {
            l18 = vader_c_emit_aux(l0, 2008u);
            l19 = concat_2(l5, 264u);
            l8 = vader_c_emit_gc_allocation(l5);
            vader_c_emit_declare(l0, l19, l18, l8);
            l17 = l18;
        }
        l7 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        vader_c_emit_init_object_header(l0, l17, l7);
        l7 = INT32_C(0);
        while ((l7 < l6)) {
            t3 = l4.payload.obj;
            l10 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields;
            t1 = ((int64_t) (int32_t) l7);
            l3 = (size_t) (int64_t) t1;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l3)
            l11 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l3);
            t6 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_name;
            l5 = vader_c_emit_sanitise(t6);
            t6 = concat_3(l17, 291u, l5);
            l8 = vader_c_emit_c_ast_verbatim(t6);
            t1 = ((int64_t) (int32_t) l7);
            l12 = (size_t) (int64_t) t1;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l12)
            l16 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l12);
            vader_c_emit_assign(l0, l8, l16);
            l7 = (l7 + INT32_C(1));
        }
        l4 = vader_c_emit_c_ast_verbatim(l17);
        vader_c_emit_push_object(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    l12 = ((vader_array_t*) l2)->length;
    if ((l3 >= l12)) {
        l10 = std_core_new_byte_buffer((size_t) 56);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l10, l3, 1793u);
        t4 = ((vader_array_t*) l2)->length;
        t1 = ((int64_t) (size_t) t4);
        l20 = (uint64_t) (int64_t) t1;
        l3 = std_core_write_unsigned(l10, l3, l20);
        l3 = std_core_write_string_at(l10, l3, 293u);
        l5 = std_core_finish_buffer(l10, l3);
    } else {
        l6 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        l17 = vader_bytecode_bc_type_key(l2, l6);
        l3 = vader_host_std_core_byte_len(l17);
        l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(53) + l3));
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l10, l3, 2278u);
        l3 = std_core_write_string_at(l10, l3, l17);
        l3 = std_core_write_string_at(l10, l3, 908u);
        t4 = ((vader_array_t*) l2)->length;
        t1 = ((int64_t) (size_t) t4);
        l20 = (uint64_t) (int64_t) t1;
        l3 = std_core_write_unsigned(l10, l3, l20);
        l3 = std_core_write_string_at(l10, l3, 293u);
        l5 = std_core_finish_buffer(l10, l3);
    }
    l3 = vader_host_std_core_byte_len(l5);
    l2 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(52) + l3));
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l2, l3, 2242u);
    t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
    l21 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l21);
    l3 = std_core_write_string_at(l2, l3, 336u);
    l3 = std_core_write_string_at(l2, l3, l5);
    t6 = std_core_finish_buffer(l2, l3);
    std_abort_todo(t6);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_set(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    size_t l3, l12;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l11 = 0;
    int32_t l9;
    uint8_t l10;
    int64_t l13;
    int32_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    bool t5;
    vader_box_t* gc_roots[4] = { &l4, &l6, &l7, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 536u)) {
        l8 = std_core_new_byte_buffer((size_t) 50);
        l12 = (size_t) 0;
        l12 = std_core_write_string_at(l8, l12, 2247u);
        t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
        l13 = ((int64_t) (int32_t) t0);
        l12 = std_core_write_int(l8, l12, l13);
        t2 = std_core_finish_buffer(l8, l12);
        std_abort_todo(t2);
        vader_unreachable("a no-return call returned");
    }
    l2 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
    t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
    l5 = t3.payload.s;
    l6 = vader_c_emit_pop(l0);
    l7 = vader_c_emit_pop(l0);
    t4 = l4.payload.obj;
    l2 = ((vader_struct_vader_bytecode_BcStruct_t*) t4)->f_fields;
    t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_field_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
    l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l9 = ((vader_struct_vader_bytecode_BcField_t*) l2)->f_type_index;
    l10 = vader_c_emit_val_type_of_field(l8, l9);
    l4 = vader_c_emit_coerced_as(l0, l6, l10);
    l6 = vader_c_emit_object_pointer_of(l7);
    l11 = ((vader_struct_vader_bytecode_BcField_t*) l2)->f_name;
    l7 = vader_c_emit_field_of(l5, l6, l11);
    vader_c_emit_assign(l0, l7, l4);
    t5 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_stack;
    if (!(t5)) {
        l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        l9 = ((vader_struct_vader_bytecode_BcField_t*) l2)->f_type_index;
        t5 = vader_c_emit_field_may_hold_reference(l8, l9);
        if (t5) {
            t2 = concat_2(l5, 264u);
            l4 = vader_c_emit_c_ast_cast(t2, l6);
            vader_c_emit_write_barrier(l0, l4);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_struct_typedefs(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l4, l5;
    bool l7;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    bool t2;
    int64_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l8, &l9, &t4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (t0.tag == 536u) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            l6 = t0.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_c_name;
            if (t1 == 0u) {
                l7 = true;
            } else {
                t2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                l7 = !(t2);
            }
            if (l7) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                vader_struct_vader_c_emit_c_ast_CStructForward_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStructForward_t));
                vader_obj_header_init(_a5_obj, 751u);
                _a5_obj->f_name = t1;
                l8 = (void*) _a5_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
                l9 = vader_c_emit_struct_definition(l0, l6, l4);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
            }
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a6_arr = vader_array_new(10u, 0u, 0u, 230u);
    t4 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a7_obj, 745u);
    _a7_obj->f_comment = t4;
    _a7_obj->f_items = l2;
    l2 = (void*) _a7_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a8_arr = vader_array_new(10u, 0u, 0u, 230u);
    t4 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 745u);
    _a9_obj->f_comment = t4;
    _a9_obj->f_items = l3;
    l2 = (void*) _a9_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_temporary_declarations(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    size_t l7, l8, l10;
    uint64_t l11;
    vader_string_t l12 = 0;
    int64_t t0;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l6, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l7);
    l6 = (void*) _a1_arr;
    l7 = (size_t) 0;
    l8 = ((vader_array_t*) l0)->length;
    while ((l7 < l8)) {
        l9 = std_core_new_byte_buffer((size_t) 21);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l9, l10, 2261u);
        t0 = ((int64_t) (size_t) l7);
        l11 = (uint64_t) (int64_t) t0;
        l10 = std_core_write_unsigned(l9, l10, l11);
        l12 = std_core_finish_buffer(l9, l10);
        vader_array_push((vader_array_t*) l6, vader_box_string(230u, l12));
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    vader_c_emit_emit_slot_decls(l1, l0, l6, l2, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_type_check(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l10 = vader_box_null();
    uint8_t l3;
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l8;
    int32_t l9;
    vader_string_t l11 = 0;
    bool t0;
    int32_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l6, &l10, &t4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l7, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_val_of(l2);
    t0 = vader_c_emit_is_ref_val(l3);
    if (t0) {
        l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        t1 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
        t2 = ((int64_t) (int32_t) t1);
        l5 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 537u) {
            vader_array_t* _a1_arr = vader_array_new(181u, 0u, 13u, 1359u);
            l4 = (void*) _a1_arr;
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_BcUnion_t*) t3)->f_variants;
            l5 = ((vader_array_t*) l7)->length;
            l8 = (size_t) 0;
            while ((l8 < l5)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
                l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
                l6 = vader_c_emit_tag_of(l2);
                l10 = vader_c_emit_one_variant_check(l0, l6, l9);
                vader_array_push((vader_array_t*) l4, l10);
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
            }
            t4 = vader_c_emit_c_ast_any_of(l4);
            vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
            vader_obj_header_init(_a3_obj, 740u);
            _a3_obj->f_inner = t4;
            l4 = (void*) _a3_obj;
            vader_c_emit_push_expr(l0, (uint8_t) 12, vader_ref_box(l4));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = vader_c_emit_tag_of(l2);
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
        l2 = vader_c_emit_one_variant_check(l0, l2, l9);
        vader_c_emit_push_expr(l0, (uint8_t) 12, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
    t0 = vader_c_emit_primitive_matches_type(l4, l3, l9);
    if (t0) {
        l11 = 2313u;
    } else {
        l11 = 1616u;
    }
    l2 = vader_c_emit_c_ast_verbatim(l11);
    vader_c_emit_push_lit(l0, (uint8_t) 12, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_type_const(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
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
    l2 = std_core_new_byte_buffer((size_t) 77);
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l2, l3, 2461u);
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_null_tag;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2348u);
    t0 = ((vader_struct_vader_bytecode_TypeConst_t*) l1)->f_type_id;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2347u);
    t1 = std_core_finish_buffer(l2, l3);
    l5 = vader_c_emit_c_ast_verbatim(t1);
    vader_c_emit_push_lit(l0, (uint8_t) 19, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_type_info_table(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l21 = NULL;
    size_t l3, l7, l8;
    bool l4, l5;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l14 = vader_box_null(), l16 = vader_box_null(), l18 = vader_box_null(), l20 = vader_box_null(), l22 = vader_box_null();
    int32_t l15, l17, l19;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[8] = { &l9, &l10, &l14, &l16, &l18, &l20, &l22, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l6, &l11, &l12, &l13, &l21, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 8u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l3 = ((vader_array_t*) l2)->length;
    l4 = false;
    l5 = false;
    l6 = l2;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        if (l9.tag == 526u) {
            l4 = true;
        }
        if (l9.tag == 523u) {
            l5 = true;
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a1_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l6 = (void*) _a1_arr;
    if (l4) {
        l9 = vader_c_emit_single_offset_list(2489u, 2014u);
        vader_array_push((vader_array_t*) l6, l9);
    }
    if (l5) {
        l9 = vader_c_emit_single_offset_list(2428u, 2013u);
        vader_array_push((vader_array_t*) l6, l9);
    }
    vader_array_t* _a2_arr = vader_array_new(10u, 0u, 0u, 230u);
    t1 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a3_obj, 745u);
    _a3_obj->f_comment = t1;
    _a3_obj->f_items = l6;
    l6 = (void*) _a3_obj;
    vader_c_emit_c_ast_print_section(l1, l6);
    vader_array_t* _a4_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l6 = (void*) _a4_arr;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l10 = l9;
        if (l9.tag == 536u) {
            l11 = l10.payload.obj;
            l12 = l10.payload.obj;
            l13 = vader_c_emit_classify_struct_fields(l0, l12, l7);
            l14 = vader_c_emit_struct_info_row(l0, l11, l13, l7);
            vader_array_push((vader_array_t*) l6, l14);
        } else if (l9.tag == 526u) {
            t1 = l10.payload.obj;
            l15 = vader_bytecode_size_of_bc_type(vader_ref_box(t1));
            l16 = vader_c_emit_single_reference_row(l7, 472u, 2491u, l15, 2489u);
            vader_array_push((vader_array_t*) l6, l16);
        } else if (l9.tag == 523u) {
            t1 = l10.payload.obj;
            l17 = vader_bytecode_size_of_bc_type(vader_ref_box(t1));
            l18 = vader_c_emit_single_reference_row(l7, 408u, 2448u, l17, 2428u);
            vader_array_push((vader_array_t*) l6, l18);
        } else {
            l19 = vader_bytecode_size_of_bc_type(l10);
            if ((l19 > INT32_C(0))) {
                l20 = vader_c_emit_c_ast_number(((int64_t) (int32_t) l19));
                t2 = vader_c_emit_c_ast_designated(314u, l20);
                vader_array_t* _a6_arr = vader_array_new(181u, 1u, 13u, 1359u);
                ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t2.payload.obj;
                l21 = (void*) _a6_arr;
                l22 = vader_c_emit_info_row(l7, l21);
                vader_array_push((vader_array_t*) l6, l22);
            }
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l15 = ((int32_t) (size_t) l3);
    l9 = vader_c_emit_c_ast_initializer_list(l6);
    t2 = vader_box_i32(233u, l15);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a7_obj, 718u);
    _a7_obj->f_name = 2533u;
    _a7_obj->f_length = t2;
    _a7_obj->f_value = l9;
    l2 = (void*) _a7_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a8_obj, 727u);
    _a8_obj->f_storage = (uint8_t) 1;
    _a8_obj->f_constant = true;
    _a8_obj->f_type = 2532u;
    _a8_obj->f_declarator = l2;
    l2 = (void*) _a8_obj;
    l9 = vader_c_emit_c_ast_number(((int64_t) (size_t) l3));
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a9_obj, 718u);
    _a9_obj->f_name = 2531u;
    _a9_obj->f_length = vader_box_obj(0u, NULL);
    _a9_obj->f_value = l9;
    l6 = (void*) _a9_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a10_obj, 727u);
    _a10_obj->f_storage = (uint8_t) 1;
    _a10_obj->f_constant = true;
    _a10_obj->f_type = 2141u;
    _a10_obj->f_declarator = l6;
    l6 = (void*) _a10_obj;
    vader_array_t* _a11_arr = vader_array_new(10u, 0u, 0u, 230u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(183u, 2u, 13u, 1367u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l6;
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l2;
    l2 = (void*) _a12_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a13_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a13_obj, 745u);
    _a13_obj->f_comment = l11;
    _a13_obj->f_items = l2;
    l2 = (void*) _a13_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_typed_slot_write(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3, vader_string_t l4, uint8_t l5) {
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l6, &l7 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_c_emit_slot_index(l1, l2);
    l6 = vader_c_emit_typed_slot(l4, l1, l6);
    l7 = vader_c_emit_coerced_as(l0, l3, l5);
    l7 = vader_c_emit_c_ast_cast(l4, l7);
    vader_c_emit_assign(l0, l6, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_virtual_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6;
    uint8_t l9;
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t* gc_roots[3] = { &l4, &l5, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l7, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l3, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx;
    l3 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_vtable_key;
    l4 = vader_c_emit_find_vtable_row(l2, l3);
    if (l4.tag == 0u) {
        l3 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_vtable_key;
        l3 = concat_2(1995u, l3);
        vader_c_emit_unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_coerced_as(l0, l5, (uint8_t) 19);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_parameter_count;
    l6 = (t1 - INT32_C(1));
    l7 = vader_c_emit_pop_args_boxed(l0, l6);
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
    l7 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx;
    l8 = l4.payload.obj;
    l7 = vader_c_emit_vtable_sig_for_row(l7, l8);
    t2 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_vtable_key;
    t3 = vader_c_emit_vtable_helper_name(t2);
    l4 = vader_c_emit_c_ast_call(t3, l2);
    t4 = vader_bytecode_bc_single_result(l7);
    if (!(t4 == INT32_C(16))) {
        l9 = vader_bytecode_bc_single_result(l7);
        vader_c_emit_push_into_temporary(l0, l4, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_evaluate(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_vtable_dispatchers(void* l0, void* l1) {
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
    size_t l5, l6, l12, l13, l18, l27, l31;
    int32_t l15, l16, l24, l25;
    vader_box_t l21 = vader_box_null(), l29 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null(), l41 = vader_box_null();
    uint8_t l22, l32, l39, l40;
    int64_t l28;
    vader_string_t l43 = 0;
    vader_string_t l49 = 0;
    size_t t0;
    int64_t t1;
    bool t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_string_t t6 = 0;
    uint8_t t7;
    void* t8 = NULL;
    vader_box_t* gc_roots[6] = { &l21, &l29, &l33, &l34, &l41, &t4 };
    void** gc_raw_roots[32] = {
        &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l10, &l11, &l14, &l17, &l19, &l20, &l23, &l26,
        &l30, &l35, &l36, &l37, &l38, &l42, &l44, &l45, &l46, &l47, &l48, &l50, &l51, &l52, &l53,
        &t8,
    };
    vader_string_t* gc_atom_roots[4] = { &l43, &l49, &t5, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 32u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_vtables;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l3 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l7)->f_entries)->length;
        if (t0 == INT64_C(0)) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        l8 = vader_c_emit_vtable_sig_for_row(l0, l7);
        vader_array_t* _a2_arr = vader_array_new(55u, 0u, 13u, 711u);
        l9 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(11u, 0u, 7u, 233u);
        l10 = (void*) _a3_arr;
        l11 = ((vader_struct_vader_bytecode_VtableRow_t*) l7)->f_entries;
        l12 = ((vader_array_t*) l11)->length;
        l13 = (size_t) 0;
        while ((l13 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l13)
            l14 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l13);
            l15 = ((vader_struct_vader_bytecode_VtableEntry_t*) l14)->f_receiver_type_index;
            t2 = std_core____Contains_contains__i32(l10, l15);
            if (t2) {
                t1 = (l13 + INT64_C(1));
                l13 = (size_t) (int64_t) t1;
                continue;
            }
            l16 = ((vader_struct_vader_bytecode_VtableEntry_t*) l14)->f_receiver_type_index;
            vader_array_push_i32((vader_array_t*) l10, l16);
            l17 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
            t3 = ((vader_struct_vader_bytecode_VtableEntry_t*) l14)->f_fn_index;
            t1 = ((int64_t) (int32_t) t3);
            l18 = (size_t) (int64_t) t1;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l18)
            l19 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l18);
            l20 = ((vader_struct_vader_bytecode_BcFunction_t*) l19)->f_signature;
            l21 = vader_c_emit_c_ast_verbatim(2080u);
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l20)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t4 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 236u);
            l22 = ((uint8_t) t4.payload.i);
            t4 = vader_c_emit_coerce_expr(l2, l21, (uint8_t) 19, l22);
            vader_array_t* _a7_arr = vader_array_new(181u, 1u, 13u, 1359u);
            ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t4.payload.obj;
            l23 = (void*) _a7_arr;
            t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l20)->f_params)->length;
            l24 = (((int32_t) (size_t) t0) - INT32_C(1));
            l25 = INT32_C(0);
            while ((l25 < l24)) {
                l26 = std_core_new_byte_buffer((size_t) 21);
                l27 = (size_t) 0;
                l27 = std_core_write_string_at(l26, l27, 1151u);
                l28 = ((int64_t) (int32_t) l25);
                l27 = std_core_write_int(l26, l27, l28);
                t5 = std_core_finish_buffer(l26, l27);
                l29 = vader_c_emit_c_ast_verbatim(t5);
                l30 = ((vader_struct_vader_bytecode_BcSignature_t*) l20)->f_params;
                t1 = ((int64_t) (int32_t) (l25 + INT32_C(1)));
                l31 = (size_t) (int64_t) t1;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l31)
                t4 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l31, 236u);
                l32 = ((uint8_t) t4.payload.i);
                l33 = vader_c_emit_coerce_expr(l2, l29, (uint8_t) 19, l32);
                vader_array_push((vader_array_t*) l23, l33);
                l25 = (l25 + INT32_C(1));
            }
            t5 = ((vader_struct_vader_bytecode_BcFunction_t*) l19)->f_name;
            t6 = vader_c_emit_sanitise(t5);
            l34 = vader_c_emit_c_ast_call(t6, l23);
            t7 = vader_bytecode_bc_single_result(l8);
            if (t7 == INT32_C(16)) {
                vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
                vader_obj_header_init(_a9_obj, 722u);
                _a9_obj->f_expression = l34;
                l36 = (void*) _a9_obj;
                vader_array_t* _a10_arr = vader_array_new(54u, 0u, 13u, 706u);
                t8 = (void*) _a10_arr;
                vader_struct_vader_c_emit_c_ast_CReturn_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
                vader_obj_header_init(_a11_obj, 743u);
                _a11_obj->f_stores = t8;
                _a11_obj->f_value = vader_box_obj(0u, NULL);
                _a11_obj->f_snapshot_type = 0u;
                _a11_obj->f_pops_frame = false;
                l37 = (void*) _a11_obj;
                vader_array_t* _a12_arr = vader_array_new(184u, 2u, 13u, 1369u);
                ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l37;
                ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l36;
                l35 = (void*) _a12_arr;
            } else {
                vader_array_t* _a13_arr = vader_array_new(54u, 0u, 13u, 706u);
                l38 = (void*) _a13_arr;
                l39 = vader_bytecode_bc_single_result(l20);
                l40 = vader_bytecode_bc_single_result(l8);
                l41 = vader_c_emit_dispatcher_result(l2, l34, l39, l40);
                vader_struct_vader_c_emit_c_ast_CReturn_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
                vader_obj_header_init(_a14_obj, 743u);
                _a14_obj->f_stores = l38;
                _a14_obj->f_value = l41;
                _a14_obj->f_snapshot_type = 0u;
                _a14_obj->f_pops_frame = false;
                t8 = (void*) _a14_obj;
                vader_array_t* _a15_arr = vader_array_new(184u, 1u, 13u, 1369u);
                ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t8;
                l35 = (void*) _a15_arr;
            }
            t3 = ((vader_struct_vader_bytecode_VtableEntry_t*) l14)->f_receiver_type_index;
            t4 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t3));
            vader_struct_vader_c_emit_c_ast_CCase_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCase_t));
            vader_obj_header_init(_a16_obj, 711u);
            _a16_obj->f_value = t4;
            _a16_obj->f_body = l35;
            l42 = (void*) _a16_obj;
            vader_array_push((vader_array_t*) l9, vader_ref_box(l42));
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
        }
        l43 = ((vader_struct_vader_bytecode_VtableRow_t*) l7)->f_key;
        t5 = concat_2(2561u, l43);
        t6 = vader_c_emit_c_string_lit(t5);
        t4 = vader_c_emit_c_ast_verbatim(t6);
        vader_array_t* _a17_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t4.payload.obj;
        l44 = (void*) _a17_arr;
        t4 = vader_c_emit_c_ast_call(2534u, l44);
        vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
        vader_obj_header_init(_a18_obj, 722u);
        _a18_obj->f_expression = t4;
        l45 = (void*) _a18_obj;
        t4 = vader_c_emit_c_ast_verbatim(2080u);
        vader_struct_vader_c_emit_c_ast_CMember_t* _a19_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a19_obj, 736u);
        _a19_obj->f_base = t4;
        _a19_obj->f_member = 2262u;
        _a19_obj->f_arrow = false;
        l46 = (void*) _a19_obj;
        vader_array_t* _a20_arr = vader_array_new(184u, 1u, 13u, 1369u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l45;
        l47 = (void*) _a20_arr;
        vader_struct_vader_c_emit_c_ast_CSwitch_t* _a21_obj = (vader_struct_vader_c_emit_c_ast_CSwitch_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSwitch_t));
        vader_obj_header_init(_a21_obj, 752u);
        _a21_obj->f_subject = vader_ref_box(l46);
        _a21_obj->f_cases = l9;
        _a21_obj->f_default_body = vader_ref_box(l47);
        t8 = (void*) _a21_obj;
        vader_array_t* _a22_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t8;
        l48 = (void*) _a22_arr;
        t7 = vader_bytecode_bc_single_result(l8);
        if (t7 != INT32_C(16)) {
            vader_array_push((vader_array_t*) l48, vader_ref_box(l45));
        }
        l49 = ((vader_struct_vader_bytecode_VtableRow_t*) l7)->f_key;
        l50 = vader_c_emit_dispatcher_signature(l0, l49, l8);
        vader_array_t* _a23_arr = vader_array_new(182u, 0u, 13u, 1363u);
        l51 = (void*) _a23_arr;
        vader_struct_vader_c_emit_c_ast_CBlock_t* _a24_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
        vader_obj_header_init(_a24_obj, 708u);
        _a24_obj->f_body = l48;
        l52 = (void*) _a24_obj;
        vader_struct_vader_c_emit_c_ast_CFunction_t* _a25_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
        vader_obj_header_init(_a25_obj, 725u);
        _a25_obj->f_signature = l50;
        _a25_obj->f_prologue = l51;
        _a25_obj->f_body = l52;
        l53 = (void*) _a25_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l53));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a26_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a26_arr->buf)[_a26_arr->offset + 0u] = vader_box_string(230u, 2559u);
    t8 = (void*) _a26_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a27_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a27_obj, 745u);
    _a27_obj->f_comment = t8;
    _a27_obj->f_items = l3;
    l2 = (void*) _a27_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_vtable_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t l4, l5;
    vader_string_t l8 = 0;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l9, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_vtables;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1367u);
    l2 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_entries)->length;
        if (t0 == INT64_C(0)) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        l7 = vader_c_emit_vtable_sig_for_row(l0, l6);
        l8 = ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_key;
        t2 = vader_c_emit_dispatcher_signature(l0, l8, l7);
        vader_struct_vader_c_emit_c_ast_CPrototype_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
        vader_obj_header_init(_a2_obj, 742u);
        _a2_obj->f_signature = t2;
        l9 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a3_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a3_arr->buf)[_a3_arr->offset + 0u] = vader_box_string(230u, 2560u);
    t2 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a4_obj, 745u);
    _a4_obj->f_comment = t2;
    _a4_obj->f_items = l2;
    l2 = (void*) _a4_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_c_emit_empty_struct_offsets(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(10u, 0u, 0u, 230u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(10u, 0u, 0u, 230u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_c_emit_StructOffsets_t* _a3_obj = (vader_struct_vader_c_emit_StructOffsets_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StructOffsets_t));
    vader_obj_header_init(_a3_obj, 704u);
    _a3_obj->f_ptr_offsets = l0;
    _a3_obj->f_str_offsets = l1;
    _a3_obj->f_ref_offsets = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_entry_needs_materialise(vader_box_t l0, int32_t l1) {
    bool l2;
    void* t0;
    int32_t t1;
    if (l0.tag == 699u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 701u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
        l2 = t1 == l1;
    } else if (l0.tag == 703u) {
        l2 = false;
    } else {
        if (!(l0.tag == 700u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    return l2;
}

static void* vader_c_emit_erased_parameters(size_t l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CParameter_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
    vader_obj_header_init(_a0_obj, 739u);
    _a0_obj->f_type = 2556u;
    _a0_obj->f_name = 1534u;
    t0 = (void*) _a0_obj;
    t1 = vader_c_emit_boxed_parameters(t0, l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_erased_sibling_field_read(void* l0, int32_t l1, int32_t l2, uint8_t l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l12 = 0;
    int32_t l10;
    uint8_t l11;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l7, &t1 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    if (!(l7.tag == 536u)) {
        t1 = vader_c_emit_c_ast_verbatim(328u);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
    l9 = t1.payload.s;
    t2 = l7.payload.obj;
    l8 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
    t0 = ((int64_t) (int32_t) l2);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
    l10 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_type_index;
    l11 = vader_c_emit_val_type_of_field(l5, l10);
    l12 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_name;
    l7 = vader_c_emit_field_of(l9, l4, l12);
    t1 = vader_c_emit_coerce_expr(l5, l7, l11, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_erased_wrapper_signature(void* l0, vader_string_t l1, size_t l2) {
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
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l3 = vader_c_emit_wrapper_storage(t0);
    l4 = vader_c_emit_erased_parameters(l2);
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a0_obj, 747u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline_v = false;
    _a0_obj->f_result = 2462u;
    _a0_obj->f_name = l1;
    _a0_obj->f_parameters = l4;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_evaluate(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 722u);
    _a0_obj->f_expression = l1;
    l2 = (void*) _a0_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_expression_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 703u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackTemporary_t*) t0)->f_temporary;
        l1 = vader_ref_box(t1);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 700u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackLit_t*) t0)->f_expression;
    } else if (l0.tag == 701u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
        vader_struct_vader_c_emit_c_ast_CLocal_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
        vader_obj_header_init(_a0_obj, 734u);
        _a0_obj->f_slot = t2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 699u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackExpr_t*) t0)->f_expression;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_extern_c_type(uint8_t l0) {
    vader_string_t t0;
    if (!(l0 == INT32_C(14))) {
        t0 = vader_c_emit_c_type_for_val_bare(l0);
        return t0;
    }
    return 1456u;
}

static vader_box_t vader_c_emit_extern_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    int32_t l7;
    vader_string_t t0 = 0;
    int64_t t1;
    bool t2;
    uint8_t t3;
    void* t4 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(60u, 0u, 13u, 739u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        t0 = vader_c_emit_extern_parameter_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l1, l3);
        vader_struct_vader_c_emit_c_ast_CParameter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
        vader_obj_header_init(_a2_obj, 739u);
        _a2_obj->f_type = t0;
        _a2_obj->f_name = 0u;
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    l7 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    t2 = vader_c_emit_is_abi_nullable_pointer(l1, l7);
    if (t2) {
        l6 = 2556u;
    } else {
        t3 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
        l6 = vader_c_emit_extern_c_type(t3);
    }
    l8 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a3_obj, 747u);
    _a3_obj->f_storage = (uint8_t) 2;
    _a3_obj->f_inline_v = false;
    _a3_obj->f_result = l6;
    _a3_obj->f_name = l8;
    _a3_obj->f_parameters = l2;
    t4 = (void*) _a3_obj;
    vader_struct_vader_c_emit_c_ast_CPrototype_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
    vader_obj_header_init(_a4_obj, 742u);
    _a4_obj->f_signature = t4;
    t4 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_extern_parameter_type(void* l0, void* l1, size_t l2) {
    bool l3;
    int32_t l4;
    vader_string_t l5 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l5, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_param_is_mutable(l0, l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    t0 = vader_c_emit_is_abi_array(l1, l4);
    if (t0) {
        t1 = vader_c_emit_pointer_to(2555u, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2];
    l5 = vader_c_emit_mirrored_c_struct(l1, l4);
    if (l5 != 0u) {
        t1 = vader_c_emit_pointer_to(l5, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_is_param_by_address(l0, l2);
    if (t0) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 236u);
        t1 = vader_c_emit_c_type_for_val_bare(((uint8_t) t2.payload.i));
        t3 = vader_c_emit_pointer_to(t1, l3);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
    l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l2];
    t0 = vader_c_emit_is_abi_nullable_pointer(l1, l4);
    if (!(t0)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
        t2 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l2, 236u);
        t1 = vader_c_emit_extern_c_type(((uint8_t) t2.payload.i));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 2556u; }
}

static vader_box_t vader_c_emit_external(vader_string_t l0, vader_string_t l1, vader_box_t l2, bool l3) {
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a0_obj, 718u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    l4 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a1_obj, 727u);
    _a1_obj->f_storage = (uint8_t) 2;
    _a1_obj->f_constant = l3;
    _a1_obj->f_type = l0;
    _a1_obj->f_declarator = l4;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_field_may_hold_reference(void* l0, int32_t l1) {
    uint8_t l2;
    bool l3;
    l2 = vader_c_emit_val_type_of_field(l0, l1);
    if (l2 == INT32_C(18)) {
        l3 = true;
    } else {
        l3 = l2 == INT32_C(19);
    }
    if (l3) {
        return true;
    }
    return l2 == INT32_C(14);
}

static vader_box_t vader_c_emit_field_of(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(l0, 264u);
    l4 = vader_c_emit_sanitise(l2);
    l4 = concat_2(1615u, l4);
    t0 = vader_c_emit_c_ast_pointer_member(l3, l1, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_fields_are_layout_siblings(void* l0, void* l1, void* l2) {
    size_t l3, l4, l8, l9;
    bool l5;
    int32_t l6, l7;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    uint8_t t3;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l2)->f_fields)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    if (l3 != l4) {
        return false;
    }
    l5 = false;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    for (;;) {
        if ((l3 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            l6 = ((vader_struct_vader_bytecode_BcField_t*) t0)->f_type_index;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l2)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            l7 = ((vader_struct_vader_bytecode_BcField_t*) t0)->f_type_index;
            if (l7 == l6) {
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                continue;
            }
            l5 = true;
            t1 = ((int64_t) (int32_t) l7);
            l8 = (size_t) (int64_t) t1;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            if (t2.tag == 533u) {
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                continue;
            }
            t1 = ((int64_t) (int32_t) l6);
            l9 = (size_t) (int64_t) t1;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            if (t2.tag == 533u) {
                t3 = vader_c_emit_val_type_of_field(l0, l7);
                if (t3 == INT32_C(18)) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
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

static void* vader_c_emit_find_layout_siblings(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    size_t l3, l6;
    vader_box_t l4 = vader_box_null();
    bool l5, l8, l9, l12;
    int32_t l10, l11, l14;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    bool t5;
    vader_box_t* gc_roots[2] = { &l4, &t3 };
    void** gc_raw_roots[5] = { &l0, &l2, &l7, &l13, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    l2 = (void*) _a0_arr;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (l4.tag == 536u) {
        t1 = l4.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        l5 = std_string_string_Contains_contains(t2, 801u);
        l3 = (size_t) 0;
        l6 = ((vader_array_t*) l0)->length;
        while ((l3 < l6)) {
            if (((int32_t) (size_t) l3) == l1) {
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            if (t3.tag == 536u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
                t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
                l7 = t3.payload.obj;
                t1 = l4.payload.obj;
                t4 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_symbol_id;
                if ((t4 >= INT32_C(0))) {
                    l10 = ((vader_struct_vader_bytecode_BcStruct_t*) l7)->f_symbol_id;
                    t1 = l4.payload.obj;
                    l11 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_symbol_id;
                    l9 = l10 == l11;
                } else {
                    l9 = false;
                }
                if (l9) {
                    l8 = true;
                } else {
                    if (l5) {
                        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) l7)->f_name;
                        l12 = std_string_string_Contains_contains(t2, 801u);
                    } else {
                        l12 = false;
                    }
                    l8 = l12;
                }
                if (l8) {
                    l13 = l4.payload.obj;
                    t5 = vader_c_emit_fields_are_layout_siblings(l0, l13, l7);
                    if (t5) {
                        l14 = ((int32_t) (size_t) l3);
                        vader_array_push_i32((vader_array_t*) l2, l14);
                    }
                }
            }
            t0 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t0;
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_find_main(void* l0, vader_string_t l1) {
    size_t l2, l3;
    void* l4;
    vader_string_t t0;
    size_t t1;
    int64_t t2;
    bool t3;
    if (l1 != 0u) {
        l2 = (size_t) 0;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        while ((l2 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
            if (t0 == l1) {
                t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
                if ((t1 > INT64_C(0))) {
                    return ((int32_t) (size_t) l2);
                }
            }
            t2 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t2;
        }
    }
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_is_main;
        if (t3) {
            t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
            if ((t1 > INT64_C(0))) {
                return ((int32_t) (size_t) l2);
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
}

static vader_box_t vader_c_emit_find_vtable_row(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    size_t l3, l4;
    vader_string_t t0;
    int64_t t1;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_vtables;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_key;
        if (t0 == l1) {
            return vader_ref_box(l5);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return vader_box_obj(0u, NULL);
}

static vader_string_t vader_c_emit_float_lit(double l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core_f64_Display_to_string(l0);
    if (l1 == 1794u) {
        { vader_gc_top = gc_frame.prev; return 806u; }
    }
    if (l1 == 294u) {
        { vader_gc_top = gc_frame.prev; return 233u; }
    }
    if (l1 == 1975u) {
        { vader_gc_top = gc_frame.prev; return 807u; }
    }
    t0 = std_string_string_Contains_contains(l1, 295u);
    if (t0) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string_string_Contains_contains(l1, 1514u);
    if (!(t0)) {
        t1 = concat_2(l1, 302u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_float_tag_check_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    int64_t t3;
    size_t t4;
    vader_box_t* gc_roots[3] = { &l1, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        if (t0.tag == 532u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t1 = t0.payload.obj;
            t2 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
            if (t2) {
                l5 = ((int32_t) (size_t) l3);
                l6 = vader_c_emit_tag_equals(l1, l5);
                vader_array_push((vader_array_t*) l2, l6);
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    t4 = ((vader_array_t*) l2)->length;
    if (!(t4 == INT64_C(0))) {
        t0 = vader_c_emit_c_ast_any_of(l2);
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a3_obj, 740u);
        _a3_obj->f_inner = t0;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_c_ast_verbatim(328u);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_fn_builds_stack_object(void* l0) {
    size_t l1, l2;
    vader_box_t l3;
    void* t0;
    bool t1;
    int64_t t2;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l3.tag == 667u) {
            t0 = l3.payload.obj;
            t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
            if (t1) {
                return true;
            }
        }
        t2 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t2;
    }
    return false;
}

static bool vader_c_emit_fn_calls_may_alloc(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4;
    int32_t l5;
    void* t0;
    bool t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 558u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
            t1 = std_core____Contains_contains__i32(l1, l5);
            if (t1) {
                return true;
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return false;
}

static bool vader_c_emit_fn_has_direct_alloc(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = vader_c_emit_op_may_collect(t0, l1);
        if (t1) {
            return true;
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return false;
}

static vader_string_t vader_c_emit_fn_symbol_name(void* l0, int32_t l1) {
    bool l2;
    size_t l3, l4;
    void* l5 = NULL;
    int64_t l6;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    void** gc_raw_roots[3] = { &l0, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((int64_t) (int32_t) l1);
        l3 = (size_t) (int64_t) t0;
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        t0 = ((int64_t) (int32_t) l1);
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
        t3 = vader_c_emit_sanitise(t2);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = std_core_new_byte_buffer((size_t) 84);
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l5, l3, 1372u);
    l6 = ((int64_t) (int32_t) l1);
    l3 = std_core_write_int(l5, l3, l6);
    l3 = std_core_write_string_at(l5, l3, 281u);
    t2 = std_core_finish_buffer(l5, l3);
    vader_host_std_abort_panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_forward_boxed(vader_string_t l0, void* l1, void* l2) {
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
    l3 = vader_c_emit_c_ast_call(l0, l1);
    l4 = vader_bytecode_bc_single_result(l2);
    if (l4 == INT32_C(16)) {
        vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 722u);
        _a0_obj->f_expression = l3;
        l5 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(54u, 0u, 13u, 706u);
        l6 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l7 = (void*) _a2_arr;
        l8 = vader_c_emit_c_ast_call(2459u, l7);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a3_obj, 743u);
        _a3_obj->f_stores = l6;
        _a3_obj->f_value = l8;
        _a3_obj->f_snapshot_type = 0u;
        _a3_obj->f_pops_frame = false;
        l6 = (void*) _a3_obj;
        vader_array_t* _a4_arr = vader_array_new(182u, 2u, 13u, 1363u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l6;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l5;
        t0 = (void*) _a4_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(19)) {
        l8 = l3;
    } else if (l4 == INT32_C(18)) {
        l8 = vader_c_emit_ref_box(l3);
    } else {
        l9 = vader_bytecode_bc_single_result_type(l2);
        l8 = vader_c_emit_box_expr(l3, l4, l9);
    }
    vader_array_t* _a5_arr = vader_array_new(54u, 0u, 13u, 706u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a6_obj, 743u);
    _a6_obj->f_stores = t0;
    _a6_obj->f_value = l8;
    _a6_obj->f_snapshot_type = 0u;
    _a6_obj->f_pops_frame = false;
    t0 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(182u, 1u, 13u, 1363u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
    t0 = (void*) _a7_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_forwarded_result(void* l0, void* l1, vader_box_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null();
    int32_t l6, l7;
    void* l10 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l2, &l4, &l5, &l8, &l9, &l11, &t4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_c_ast_verbatim(2066u);
    l5 = vader_c_emit_c_ast_verbatim(2034u);
    l6 = vader_bytecode_bc_single_result_type(l0);
    t0 = vader_bytecode_bc_single_result(l0);
    if (t0 == INT32_C(16)) {
        vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 722u);
        _a0_obj->f_expression = l2;
        t1 = (void*) _a0_obj;
        vader_struct_vader_c_emit_ForwardedResult_t* _a1_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a1_obj, 694u);
        _a1_obj->f_capture = vader_ref_box(t1);
        _a1_obj->f_returns = false;
        _a1_obj->f_settle = vader_box_obj(0u, NULL);
        _a1_obj->f_returned = vader_box_obj(0u, NULL);
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_c_emit_is_abi_nullable_pointer(l1, l6);
    if (t2) {
        l7 = vader_c_emit_present_tag(l1, (uint8_t) 17);
        l8 = vader_c_emit_box_expr(l4, (uint8_t) 17, l7);
        l9 = vader_c_emit_c_ast_declaration(2556u, 2066u, l2);
        l8 = vader_c_emit_null_or(l4, l8);
        vader_struct_vader_c_emit_ForwardedResult_t* _a2_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a2_obj, 694u);
        _a2_obj->f_capture = l9;
        _a2_obj->f_returns = false;
        _a2_obj->f_settle = vader_box_obj(0u, NULL);
        _a2_obj->f_returned = l8;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_c_emit_is_abi_nullable_string(l1, l6);
    if (t2) {
        l6 = vader_c_emit_present_tag(l1, (uint8_t) 14);
        l8 = vader_c_emit_interned(l4);
        l8 = vader_c_emit_c_ast_cast(1807u, l8);
        l8 = vader_c_emit_box_call(1740u, l6, l8);
        l9 = vader_c_emit_c_ast_declaration(1456u, 2066u, l2);
        l8 = vader_c_emit_null_or(l4, l8);
        l8 = vader_c_emit_c_ast_declaration(2462u, 2034u, l8);
        vader_struct_vader_c_emit_ForwardedResult_t* _a3_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a3_obj, 694u);
        _a3_obj->f_capture = l9;
        _a3_obj->f_returns = false;
        _a3_obj->f_settle = l8;
        _a3_obj->f_returned = l5;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_bc_single_result(l0);
    if (t0 == INT32_C(14)) {
        l8 = vader_c_emit_c_ast_verbatim(179u);
        l9 = vader_c_emit_c_ast_number(INT64_C(0));
        vader_array_t* _a4_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l8.payload.obj;
        l10 = (void*) _a4_arr;
        l8 = vader_c_emit_c_ast_call(2454u, l10);
        t1 = (void*) &vader_data_50;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l10 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
        l9 = vader_c_emit_c_ast_binary((uint8_t) 11, l4, vader_ref_box(l10));
        l11 = vader_c_emit_interned(l4);
        vader_struct_vader_c_emit_c_ast_CConditional_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
        vader_obj_header_init(_a6_obj, 715u);
        _a6_obj->f_condition = l9;
        _a6_obj->f_then_value = l8;
        _a6_obj->f_else_value = l11;
        l10 = (void*) _a6_obj;
        l8 = vader_c_emit_c_ast_declaration(1456u, 2066u, l2);
        l9 = vader_c_emit_c_ast_declaration(2526u, 2034u, vader_ref_box(l10));
        vader_struct_vader_c_emit_ForwardedResult_t* _a7_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a7_obj, 694u);
        _a7_obj->f_capture = l8;
        _a7_obj->f_returns = false;
        _a7_obj->f_settle = l9;
        _a7_obj->f_returned = l5;
        t1 = (void*) _a7_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3)) {
        t0 = vader_bytecode_bc_single_result(l0);
        t3 = vader_c_emit_c_type_for_val_bare(t0);
        t4 = vader_c_emit_c_ast_declaration(t3, 2066u, l2);
        vader_struct_vader_c_emit_ForwardedResult_t* _a8_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a8_obj, 694u);
        _a8_obj->f_capture = t4;
        _a8_obj->f_returns = false;
        _a8_obj->f_settle = vader_box_obj(0u, NULL);
        _a8_obj->f_returned = l4;
        t1 = (void*) _a8_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(54u, 0u, 13u, 706u);
    t1 = (void*) _a9_arr;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a10_obj, 743u);
    _a10_obj->f_stores = t1;
    _a10_obj->f_value = l2;
    _a10_obj->f_snapshot_type = 0u;
    _a10_obj->f_pops_frame = false;
    t1 = (void*) _a10_obj;
    vader_struct_vader_c_emit_ForwardedResult_t* _a11_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
    vader_obj_header_init(_a11_obj, 694u);
    _a11_obj->f_capture = vader_ref_box(t1);
    _a11_obj->f_returns = true;
    _a11_obj->f_settle = vader_box_obj(0u, NULL);
    _a11_obj->f_returned = vader_box_obj(0u, NULL);
    t1 = (void*) _a11_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_fresh_slot(vader_string_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    void* l3 = NULL;
    size_t l4;
    int64_t l5;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l6, &t1 };
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 292u);
    l2 = vader_c_emit_c_ast_verbatim(t0);
    l3 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 2346u);
    t0 = std_core_finish_buffer(l3, l4);
    l6 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_binary((uint8_t) 3, l2, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_function_definition(void* l0, int32_t l1, void* l2) {
    bool l3, l13, l19;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    int32_t l7, l24;
    vader_string_t l8 = 0;
    vader_string_t l14 = 0;
    vader_string_t l18 = 0;
    vader_string_t l30 = 0;
    vader_string_t l31 = 0;
    size_t l9, l10, l15, l16, l20, l21, l22;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l23 = vader_box_null(), l32 = vader_box_null(), l34 = vader_box_null(), l35 = vader_box_null(), l36 = vader_box_null();
    int64_t l17;
    uint64_t l33;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t t5 = vader_box_null();
    size_t t6;
    vader_box_t* gc_roots[8] = { &l11, &l12, &l23, &l32, &l34, &l35, &l36, &t5 };
    void** gc_raw_roots[11] = { &l0, &l2, &l4, &l5, &l6, &l25, &l26, &l27, &l28, &l29, &t2 };
    vader_string_t* gc_atom_roots[6] = { &l8, &l14, &l18, &l30, &l31, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core____Contains_contains__i32(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_may_alloc, l1);
    if (!(t0)) {
        t0 = vader_c_emit_fn_builds_stack_object(l2);
        l3 = !(t0);
    } else {
        l3 = false;
    }
    l4 = vader_c_emit_new_fn_state(l0, l2);
    ((vader_struct_vader_c_emit_FnState_t*) l4)->f_no_frame = l3;
    l5 = vader_c_emit_precompute_scopes(l2);
    ((vader_struct_vader_c_emit_FnState_t*) l4)->f_scopes = l5;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l4);
    l5 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_scopes;
    l5 = vader_c_emit_precompute_branch_targets(l2, l5);
    l6 = ((vader_struct_vader_c_emit_BranchTargets_t*) l5)->f_continue_targets;
    ((vader_struct_vader_c_emit_FnState_t*) l4)->f_continue_targets = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l4);
    l5 = ((vader_struct_vader_c_emit_BranchTargets_t*) l5)->f_break_targets;
    ((vader_struct_vader_c_emit_FnState_t*) l4)->f_break_targets = l5;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l4);
    l7 = -(INT32_C(1));
    l8 = 0u;
    l9 = (size_t) 0;
    l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l11 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        t0 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_drop_call_result;
        if (t0) {
            if (l11.tag == 567u) {
                ((vader_struct_vader_c_emit_FnState_t*) l4)->f_drop_call_result = false;
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                continue;
            }
        }
        t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_release;
        if (!(t0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            if (!(l12.tag == 0u)) {
                t2 = l12.payload.obj;
                t3 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_line;
                if (t3 != l7) {
                    l13 = true;
                } else {
                    t2 = l12.payload.obj;
                    t4 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_file;
                    l13 = t4 != l8;
                }
                if (l13) {
                    t2 = l12.payload.obj;
                    t4 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_file;
                    l14 = vader_c_emit_c_string_lit(t4);
                    l15 = vader_host_std_core_byte_len(l14);
                    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l15));
                    l16 = (size_t) 0;
                    l16 = std_core_write_string_at(l5, l16, 185u);
                    t2 = l12.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_line;
                    l17 = ((int64_t) (int32_t) t3);
                    l16 = std_core_write_int(l5, l16, l17);
                    l16 = std_core_write_string_at(l5, l16, 8u);
                    l16 = std_core_write_string_at(l5, l16, l14);
                    l18 = std_core_finish_buffer(l5, l16);
                    vader_c_emit_directive(l4, l18);
                    t2 = l12.payload.obj;
                    l7 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_line;
                    t2 = l12.payload.obj;
                    l8 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_file;
                }
            }
        }
        if (l11.tag == 558u) {
            l19 = true;
        } else {
            l19 = l11.tag == 559u;
        }
        if (l19) {
            t1 = (l9 + INT64_C(1));
            l20 = (size_t) (int64_t) t1;
            l21 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
            if ((l20 < l21)) {
                l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body;
                t1 = (l9 + INT64_C(1));
                l22 = (size_t) (int64_t) t1;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l22)
                t5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l22);
                if (t5.tag == 567u) {
                    l23 = l11;
                    t6 = vader_c_emit_callee_result_arity(l0, l23);
                    if ((t6 <= INT64_C(1))) {
                        ((vader_struct_vader_c_emit_FnState_t*) l4)->f_drop_call_result = true;
                    }
                }
            }
        }
        l24 = ((int32_t) (size_t) l9);
        vader_c_emit_emit_op(l4, l24, l11);
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_no_frame;
    if (!(t0)) {
        t0 = vader_c_emit_c_ast_ends_with_return(((vader_struct_vader_c_emit_FnState_t*) l4)->f_root);
        if (!(t0)) {
            l5 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) ((vader_struct_vader_c_emit_FnState_t*) l4)->f_root)->f_body;
            vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
            vader_obj_header_init(_a3_obj, 756u);
            _a3_obj->f_text = 2499u;
            l6 = (void*) _a3_obj;
            vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
            vader_obj_header_init(_a4_obj, 756u);
            _a4_obj->f_text = 1690u;
            l25 = (void*) _a4_obj;
            vader_struct_vader_c_emit_c_ast_CAssign_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
            vader_obj_header_init(_a5_obj, 706u);
            _a5_obj->f_target = vader_ref_box(l6);
            _a5_obj->f_value = vader_ref_box(l25);
            _a5_obj->f_operator = vader_box_obj(0u, NULL);
            l6 = (void*) _a5_obj;
            vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
        }
    }
    l5 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_root;
    l6 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_temporaries;
    l5 = vader_c_emit_c_ast_coalesce_temporaries(l5, l6);
    vader_c_emit_c_ast_structure_loops(((vader_struct_vader_c_emit_FnState_t*) l4)->f_root);
    vader_array_t* _a6_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l25 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l26 = (void*) _a8_arr;
    if (!(l3)) {
        l27 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params;
        l9 = (size_t) 0;
        l10 = ((vader_array_t*) l27)->length;
        while ((l9 < l10)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
            t5 = vader_array_read_u8(_a9_slotarr, _a9_slotarr->offset + (size_t) l9, 236u);
            if (((int32_t) t5.payload.i) == INT32_C(18)) {
                vader_struct_vader_c_emit_c_ast_CLocal_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
                vader_obj_header_init(_a10_obj, 734u);
                _a10_obj->f_slot = ((int32_t) (size_t) l9);
                t2 = (void*) _a10_obj;
                l11 = vader_c_emit_c_ast_address_of(vader_ref_box(t2));
                vader_array_push((vader_array_t*) l25, l11);
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l27);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                t5 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l9, 236u);
                if (((int32_t) t5.payload.i) == INT32_C(14)) {
                    vader_struct_vader_c_emit_c_ast_CLocal_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
                    vader_obj_header_init(_a12_obj, 734u);
                    _a12_obj->f_slot = ((int32_t) (size_t) l9);
                    t2 = (void*) _a12_obj;
                    l12 = vader_c_emit_c_ast_address_of(vader_ref_box(t2));
                    vader_array_push((vader_array_t*) l26, l12);
                } else {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l27);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l9)
                    t5 = vader_array_read_u8(_a13_slotarr, _a13_slotarr->offset + (size_t) l9, 236u);
                    t0 = vader_c_emit_is_ref_val(((uint8_t) t5.payload.i));
                    if (t0) {
                        vader_struct_vader_c_emit_c_ast_CLocal_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
                        vader_obj_header_init(_a14_obj, 734u);
                        _a14_obj->f_slot = ((int32_t) (size_t) l9);
                        t2 = (void*) _a14_obj;
                        l23 = vader_c_emit_c_ast_address_of(vader_ref_box(t2));
                        vader_array_push((vader_array_t*) l6, l23);
                    }
                }
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
    }
    vader_array_t* _a15_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l27 = (void*) _a15_arr;
    vader_c_emit_emit_local_decls(l2, l27, l6, l25, l26, l3);
    vader_c_emit_emit_temporary_declarations(l5, l27, l6, l25, l26, l3);
    if (!(l3)) {
        t6 = ((vader_array_t*) l6)->length;
        if ((t6 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2463u, 1692u, l6);
            vader_array_push((vader_array_t*) l27, l11);
        }
        t6 = ((vader_array_t*) l25)->length;
        if ((t6 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2557u, 1691u, l25);
            vader_array_push((vader_array_t*) l27, l11);
        }
        t6 = ((vader_array_t*) l6)->length;
        if ((t6 > INT64_C(0))) {
            l8 = 1692u;
        } else {
            l8 = 545u;
        }
        t6 = ((vader_array_t*) l25)->length;
        if ((t6 > INT64_C(0))) {
            l14 = 1691u;
        } else {
            l14 = 545u;
        }
        l9 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l4)->f_stack_storages)->length;
        if ((l9 > INT64_C(0))) {
            l18 = 1693u;
        } else {
            l18 = 545u;
        }
        vader_array_t* _a16_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l5 = (void*) _a16_arr;
        l10 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l4)->f_stack_storages)->length;
        vader_array_t* _a17_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l10);
        l5 = (void*) _a17_arr;
        l28 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_stack_storages;
        l10 = ((vader_array_t*) l28)->length;
        l15 = (size_t) 0;
        while ((l15 < l10)) {
            vader_array_t* _a18_slotarr = ((vader_array_t*) l28);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l15)
            l29 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l15);
            l30 = ((vader_struct_vader_c_emit_StackStorage_t*) l29)->f_cname;
            l31 = ((vader_struct_vader_c_emit_StackStorage_t*) l29)->f_storage;
            l11 = vader_c_emit_c_ast_verbatim(2596u);
            l12 = vader_c_emit_c_ast_declaration(l30, l31, l11);
            vader_array_push((vader_array_t*) l27, l12);
            t4 = ((vader_struct_vader_c_emit_StackStorage_t*) l29)->f_storage;
            t5 = vader_c_emit_c_ast_verbatim(t4);
            l23 = vader_c_emit_c_ast_address_of(t5);
            l32 = vader_c_emit_c_ast_cast(2556u, l23);
            vader_array_push((vader_array_t*) l5, l32);
            t1 = (l15 + INT64_C(1));
            l15 = (size_t) (int64_t) t1;
        }
        if ((l9 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2556u, 1693u, l5);
            vader_array_push((vader_array_t*) l27, l11);
        }
        l10 = ((vader_array_t*) l26)->length;
        if ((l10 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2527u, 1688u, l26);
            vader_array_push((vader_array_t*) l27, l11);
        }
        l11 = vader_c_emit_c_ast_verbatim(2499u);
        l5 = std_core_new_byte_buffer((size_t) 21);
        l15 = (size_t) 0;
        t6 = ((vader_array_t*) l6)->length;
        t1 = ((int64_t) (size_t) t6);
        l33 = (uint64_t) (int64_t) t1;
        l15 = std_core_write_unsigned(l5, l15, l33);
        l15 = std_core_write_string_at(l5, l15, 2346u);
        t4 = std_core_finish_buffer(l5, l15);
        l12 = vader_c_emit_c_ast_verbatim(t4);
        l5 = std_core_new_byte_buffer((size_t) 21);
        l15 = (size_t) 0;
        t6 = ((vader_array_t*) l25)->length;
        t1 = ((int64_t) (size_t) t6);
        l33 = (uint64_t) (int64_t) t1;
        l15 = std_core_write_unsigned(l5, l15, l33);
        l15 = std_core_write_string_at(l5, l15, 2346u);
        t4 = std_core_finish_buffer(l5, l15);
        l23 = vader_c_emit_c_ast_verbatim(t4);
        l32 = vader_c_emit_c_ast_verbatim(l8);
        l34 = vader_c_emit_c_ast_verbatim(l14);
        l5 = std_core_new_byte_buffer((size_t) 21);
        l15 = (size_t) 0;
        t1 = ((int64_t) (size_t) l9);
        l33 = (uint64_t) (int64_t) t1;
        l15 = std_core_write_unsigned(l5, l15, l33);
        l15 = std_core_write_string_at(l5, l15, 2346u);
        t4 = std_core_finish_buffer(l5, l15);
        l35 = vader_c_emit_c_ast_verbatim(t4);
        l36 = vader_c_emit_c_ast_verbatim(l18);
        vader_array_t* _a19_arr = vader_array_new(181u, 7u, 13u, 1359u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 6u] = l36.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 5u] = l35.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 4u] = l34.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 3u] = l32.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 2u] = l23.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 1u] = l12.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = l11.payload.obj;
        l5 = (void*) _a19_arr;
        if ((l10 > INT64_C(0))) {
            l6 = std_core_new_byte_buffer((size_t) 21);
            l9 = (size_t) 0;
            t1 = ((int64_t) (size_t) l10);
            l33 = (uint64_t) (int64_t) t1;
            l9 = std_core_write_unsigned(l6, l9, l33);
            l9 = std_core_write_string_at(l6, l9, 2346u);
            t4 = std_core_finish_buffer(l6, l9);
            l11 = vader_c_emit_c_ast_verbatim(t4);
            l12 = vader_c_emit_c_ast_verbatim(1688u);
            vader_array_t* _a20_arr = vader_array_new(181u, 2u, 13u, 1359u);
            ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 1u] = l12.payload.obj;
            ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l11.payload.obj;
            l6 = (void*) _a20_arr;
            vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
        }
        vader_struct_vader_c_emit_c_ast_CInitializerList_t* _a21_obj = (vader_struct_vader_c_emit_c_ast_CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInitializerList_t));
        vader_obj_header_init(_a21_obj, 732u);
        _a21_obj->f_elements = l5;
        l5 = (void*) _a21_obj;
        l11 = vader_c_emit_c_ast_declaration(2496u, 1689u, vader_ref_box(l5));
        vader_array_push((vader_array_t*) l27, l11);
        l11 = vader_c_emit_c_ast_verbatim(2499u);
        t5 = vader_c_emit_c_ast_verbatim(1689u);
        l12 = vader_c_emit_c_ast_address_of(t5);
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a22_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a22_obj, 706u);
        _a22_obj->f_target = l11;
        _a22_obj->f_value = l12;
        _a22_obj->f_operator = vader_box_obj(0u, NULL);
        l5 = (void*) _a22_obj;
        vader_array_push((vader_array_t*) l27, vader_ref_box(l5));
    }
    l5 = vader_c_emit_signature_for(l0, l1);
    l4 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_root;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a23_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a23_obj, 725u);
    _a23_obj->f_signature = l5;
    _a23_obj->f_prologue = l27;
    _a23_obj->f_body = l4;
    t2 = (void*) _a23_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_gc_allocation(vader_string_t l0) {
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
    l1 = concat_2(l0, 264u);
    t0 = concat_3(2143u, l0, 241u);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(2494u, l2);
    t1 = vader_c_emit_c_ast_cast(l1, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_gc_statistic(vader_string_t l0) {
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
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 706u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l2 = (void*) _a1_arr;
    t0 = vader_c_emit_c_ast_call(2497u, l2);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a2_obj, 736u);
    _a2_obj->f_base = t0;
    _a2_obj->f_member = l0;
    _a2_obj->f_arrow = false;
    l2 = (void*) _a2_obj;
    l3 = vader_c_emit_c_ast_cast(1806u, vader_ref_box(l2));
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a3_obj, 743u);
    _a3_obj->f_stores = l1;
    _a3_obj->f_value = l3;
    _a3_obj->f_snapshot_type = 0u;
    _a3_obj->f_pops_frame = false;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_global_storage(bool l0) {
    if (l0) {
        return (uint8_t) 1;
    }
    return (uint8_t) 0;
}

static bool vader_c_emit_has_str_data(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t l4;
    int64_t t0;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 535u) {
            return true;
        }
        if (l4.tag == 522u) {
            return true;
        }
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    return false;
}

static vader_string_t vader_c_emit_host_shim_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l1 = vader_c_emit_sanitise(t0);
    t0 = concat_2(2503u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_import_shim(void* l0, void* l1) {
    bool l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l5, &l6, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    t0 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l1)->f_signature);
    l3 = vader_c_emit_c_type_for_val_bare(t0);
    l4 = vader_c_emit_host_shim_name(l1);
    l5 = vader_c_emit_value_parameters(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l1)->f_signature)->f_params, 1151u);
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a0_obj, 747u);
    _a0_obj->f_storage = (uint8_t) 0;
    _a0_obj->f_inline_v = l2;
    _a0_obj->f_result = l3;
    _a0_obj->f_name = l4;
    _a0_obj->f_parameters = l5;
    l5 = (void*) _a0_obj;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    t1 = vader_c_emit_shim_body(l1, l6);
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 708u);
    _a1_obj->f_body = t1;
    l6 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l7 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a3_obj, 725u);
    _a3_obj->f_signature = l5;
    _a3_obj->f_prologue = l7;
    _a3_obj->f_body = l6;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_imports_header_name(vader_string_t l0) {
    size_t l1;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t4 = 0;
    size_t t2;
    int64_t t3;
    vader_string_t* gc_atom_roots[3] = { &l0, &t1, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_ends_with(l0, 316u);
    if (!(t0)) {
        t1 = concat_2(l0, 307u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = std_core_len(l0);
    t3 = (t2 - INT64_C(8));
    l1 = (size_t) (int64_t) t3;
    t1 = vader_string_slice_codepoints(l0, INT64_C(0), l1);
    t4 = concat_2(t1, 307u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_imports_may_collect(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4;
    bool l5;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 12u, 228u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) l1)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = __lambda_vader_c_emit_3(t0);
        vader_array_push_bool((vader_array_t*) l2, l5);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_include_of(vader_string_t l0) {
    bool l1;
    vader_string_t l2 = 0;
    size_t l3;
    size_t t0;
    int64_t t1;
    bool t2;
    void* t3 = NULL;
    void** gc_raw_roots[1] = { &t3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core_len(l0);
    l1 = (t0 >= INT64_C(2));
    if (l1) {
        t0 = std_core_len(l0);
        t1 = (t0 - INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        l2 = vader_string_slice_codepoints(l0, INT64_C(1), l3);
    } else {
        l2 = l0;
    }
    if (l1) {
        t2 = std_string_starts_with(l0, 368u);
        if (t2) {
            t2 = std_string_ends_with(l0, 390u);
            if (t2) {
                vader_struct_vader_c_emit_c_ast_CInclude_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
                vader_obj_header_init(_a0_obj, 730u);
                _a0_obj->f_path = l2;
                _a0_obj->f_system = true;
                t3 = (void*) _a0_obj;
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l1) {
        t2 = std_string_starts_with(l0, 177u);
        if (t2) {
            t2 = std_string_ends_with(l0, 177u);
            if (t2) {
                vader_struct_vader_c_emit_c_ast_CInclude_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
                vader_obj_header_init(_a1_obj, 730u);
                _a1_obj->f_path = l2;
                _a1_obj->f_system = false;
                t3 = (void*) _a1_obj;
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l1 = false;
            vader_struct_vader_c_emit_c_ast_CInclude_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
            vader_obj_header_init(_a2_obj, 730u);
            _a2_obj->f_path = l0;
            _a2_obj->f_system = l1;
            t3 = (void*) _a2_obj;
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l1 = false;
        vader_struct_vader_c_emit_c_ast_CInclude_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
        vader_obj_header_init(_a3_obj, 730u);
        _a3_obj->f_path = l0;
        _a3_obj->f_system = l1;
        t3 = (void*) _a3_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = false;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a4_obj, 730u);
    _a4_obj->f_path = l0;
    _a4_obj->f_system = l1;
    t3 = (void*) _a4_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_including(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 413u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CPrinter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t));
    vader_obj_header_init(_a2_obj, 741u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l1 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a3_obj, 730u);
    _a3_obj->f_path = l0;
    _a3_obj->f_system = false;
    l2 = (void*) _a3_obj;
    vader_c_emit_c_ast_print_item(l1, vader_ref_box(l2));
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_info_row(size_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    uint64_t l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t1 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_core_new_byte_buffer((size_t) 22);
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l2, l3, 777u);
    t0 = ((int64_t) (size_t) l0);
    l4 = (uint64_t) (int64_t) t0;
    l3 = std_core_write_unsigned(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 780u);
    l5 = std_core_finish_buffer(l2, l3);
    l6 = vader_c_emit_c_ast_initializer_list(l1);
    t1 = vader_c_emit_c_ast_designated(l5, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_init_object_header(void* l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    size_t l5;
    int64_t l6;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_c_ast_verbatim(l1);
    l4 = std_core_new_byte_buffer((size_t) 21);
    l5 = (size_t) 0;
    l6 = ((int64_t) (int32_t) l2);
    l5 = std_core_write_int(l4, l5, l6);
    l5 = std_core_write_string_at(l4, l5, 2346u);
    t0 = std_core_finish_buffer(l4, l5);
    l7 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(2504u, l4);
    vader_c_emit_evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_integer_payload(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CCast_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCast_t));
    vader_obj_header_init(_a0_obj, 712u);
    _a0_obj->f_types = l0;
    _a0_obj->f_value = l1;
    l2 = (void*) _a0_obj;
    t0 = vader_c_emit_c_ast_designated(306u, vader_ref_box(l2));
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_internal_fn_flags(void* l0, void* l1, vader_string_t l2) {
    size_t l3, l6, l8, l10, l11, l12;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    int32_t l7, l15;
    bool l14;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    bool t5;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l9, &l13, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 12u, 228u);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l5 = (void*) _a3_arr;
    l6 = (size_t) 0;
    while ((l6 < l3)) {
        l7 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l4, l7);
        vader_array_push_bool((vader_array_t*) l5, false);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l6 = (size_t) 0;
    l8 = ((vader_array_t*) l1)->length;
    while ((l6 < l8)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        l9 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l10 = ((vader_array_t*) l9)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t2 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l11];
            t1 = ((int64_t) (int32_t) t2);
            l12 = (size_t) (int64_t) t1;
            l7 = ((int32_t) (size_t) l6);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l12] = (int32_t) l7;
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_exports;
    l6 = ((vader_array_t*) l9)->length;
    l8 = (size_t) 0;
    while ((l8 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        t2 = ((vader_struct_vader_bytecode_BcExport_t*) t0)->f_fn_index;
        t1 = ((int64_t) (int32_t) t2);
        l10 = (size_t) (int64_t) t1;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
        ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l10] = (uint8_t) true;
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    l6 = ((vader_array_t*) l9)->length;
    l8 = (size_t) 0;
    while ((l8 < l6)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l8);
        l13 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries;
        l10 = ((vader_array_t*) l13)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l11);
            t2 = ((vader_struct_vader_bytecode_VtableEntry_t*) t0)->f_fn_index;
            t1 = ((int64_t) (int32_t) t2);
            l12 = (size_t) (int64_t) t1;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12] = (uint8_t) true;
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    l9 = vader_c_emit_scan_fn_value_usage(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l6 = (size_t) 0;
    while ((l6 < l3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l9)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
        t2 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6];
        if ((t2 >= INT32_C(0))) {
            l14 = true;
        } else {
            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l9)->f_is_closure);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
            t3 = vader_box_bool(228u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l6]);
            l14 = t3.payload.b;
        }
        if (l14) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
            ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (uint8_t) true;
        }
        if (l2 != 0u) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l6);
            t4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
            if (t4 == l2) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
                ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6] = (uint8_t) true;
            }
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l6 = (size_t) 0;
    while ((l6 < l3)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
        l7 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l6];
        vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l8 = ((vader_array_t*) l9)->length;
        l10 = (size_t) 0;
        while ((l10 < l8)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t3 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l10);
            l15 = vader_c_emit_callee_index_of(t3);
            if ((l15 >= INT32_C(0))) {
                t1 = ((int64_t) (int32_t) l15);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a20_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l11)
                t2 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l11];
                if (t2 != l7) {
                    t1 = ((int64_t) (int32_t) l15);
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l12)
                    ((uint8_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l12] = (uint8_t) true;
                }
            }
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a22_arr = vader_array_new(8u, 0u, 12u, 228u);
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l4 = (void*) _a23_arr;
    l6 = (size_t) 0;
    vader_array_t* _pc290_hdr = (vader_array_t*) l4;
    size_t _pc290_len = _pc290_hdr->length;
    size_t _pc290_cap = (_pc290_hdr->offset == 0 && !vader_array_is_borrowed(_pc290_hdr) && _pc290_hdr->length >= _pc290_hdr->buf->length) ? _pc290_hdr->capacity : (size_t) 0;
    void* _pc290_slots = _pc290_hdr->buf->slots;
    for (;;) {
        if ((l6 < l3)) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
            t3 = vader_box_bool(228u, ((uint8_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6]);
            t5 = t3.payload.b;
            l14 = !(t5);
            if (VADER_LIKELY(_pc290_len < _pc290_cap)) {
                ((uint8_t*) _pc290_slots)[_pc290_len] = (uint8_t) (l14);
                _pc290_len += 1;
            } else {
                _pc290_hdr->length = _pc290_len;
                if (_pc290_hdr->buf->length < _pc290_len) {
                    _pc290_hdr->buf->length = _pc290_len;
                }
                vader_array_push_bool((vader_array_t*) l4, l14);
                _pc290_hdr = (vader_array_t*) l4;
                _pc290_len = _pc290_hdr->length;
                _pc290_cap = (_pc290_hdr->offset == 0 && !vader_array_is_borrowed(_pc290_hdr) && _pc290_hdr->length >= _pc290_hdr->buf->length) ? _pc290_hdr->capacity : (size_t) 0;
                _pc290_slots = _pc290_hdr->buf->slots;
            }
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        _pc290_hdr->length = _pc290_len;
        if (_pc290_hdr->buf->length < _pc290_len) {
            _pc290_hdr->buf->length = _pc290_len;
        }
        break;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_interned(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l2, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2233u, l1);
    vader_array_t* _a1_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a1_arr;
    t0 = vader_c_emit_c_ast_call(2454u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_invalidate_header_cache(void* l0, vader_box_t l1) {
    int32_t l2;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 639u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        vader_c_emit_drop_bound_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 640u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        vader_c_emit_drop_bound_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_c_emit_is_cache_safe(l1);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_no_frame;
    if (t1) {
        t1 = vader_c_emit_is_scope_opening(l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_clear((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_bound_arrays);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_clear((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_bound_arrays);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_c_emit_is_abi_array(void* l0, int32_t l1) {
    int32_t l2;
    size_t t0;
    vader_box_t t1;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (size_t) t0);
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return t1.tag == 523u;
    }
    return false;
}

static bool vader_c_emit_is_abi_nullable_pointer(void* l0, int32_t l1) {
    int32_t l2, l9;
    vader_box_t l3;
    bool l4, l5;
    void* l6;
    size_t l7, l8;
    size_t t0;
    void* t1;
    int64_t t2;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (size_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 537u)) {
        return false;
    }
    t1 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants)->length;
    if (t0 != INT64_C(2)) {
        return false;
    }
    l4 = false;
    l5 = false;
    t1 = l3.payload.obj;
    l6 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        if (!((l2 < INT32_C(0)))) {
            t0 = ((vader_array_t*) l0)->length;
            l9 = ((int32_t) (size_t) t0);
            if (!((l2 >= l9))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                if (l3.tag == 532u) {
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(15)) {
                        l4 = true;
                    }
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(17)) {
                        l5 = true;
                    }
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                continue;
            }
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    if (l4) {
        return l5;
    }
    return false;
}

static bool vader_c_emit_is_abi_nullable_string(void* l0, int32_t l1) {
    int32_t l2, l9;
    vader_box_t l3;
    bool l4, l5;
    void* l6;
    size_t l7, l8;
    size_t t0;
    void* t1;
    int64_t t2;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (size_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l3.tag == 537u)) {
        return false;
    }
    t1 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants)->length;
    if (t0 != INT64_C(2)) {
        return false;
    }
    l4 = false;
    l5 = false;
    t1 = l3.payload.obj;
    l6 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        if (!((l2 < INT32_C(0)))) {
            t0 = ((vader_array_t*) l0)->length;
            l9 = ((int32_t) (size_t) t0);
            if (!((l2 >= l9))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                if (l3.tag == 532u) {
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(15)) {
                        l4 = true;
                    }
                    t1 = l3.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(14)) {
                        l5 = true;
                    }
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                continue;
            }
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    if (l4) {
        return l5;
    }
    return false;
}

static bool vader_c_emit_is_c_reserved(vader_string_t l0) {
    void* t0;
    bool t1;
    t0 = (void*) &vader_data_42;
    t1 = std_core____Contains_contains__string(t0, l0);
    return t1;
}

static bool vader_c_emit_is_cache_safe(vader_box_t l0) {
    if ((l0.tag == 637u || l0.tag == 638u || l0.tag == 666u)) {
        return true;
    }
    if ((l0.tag == 633u || l0.tag == 634u || l0.tag == 635u)) {
        return true;
    }
    if ((l0.tag == 657u || l0.tag == 658u || l0.tag == 659u)) {
        return true;
    }
    if ((l0.tag == 513u || l0.tag == 514u || l0.tag == 520u)) {
        return true;
    }
    if ((l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 636u)) {
        return true;
    }
    if ((l0.tag == 654u || l0.tag == 655u || l0.tag == 656u || l0.tag == 660u)) {
        return true;
    }
    if ((l0.tag == 546u || l0.tag == 561u || l0.tag == 574u || l0.tag == 593u || l0.tag == 613u)) {
        return true;
    }
    if ((l0.tag == 563u || l0.tag == 586u || l0.tag == 587u || l0.tag == 644u || l0.tag == 652u || l0.tag == 662u || l0.tag == 670u)) {
        return true;
    }
    if ((l0.tag == 588u || l0.tag == 594u || l0.tag == 600u || l0.tag == 601u || l0.tag == 603u || l0.tag == 607u)) {
        return true;
    }
    if ((l0.tag == 608u || l0.tag == 614u || l0.tag == 620u || l0.tag == 621u || l0.tag == 623u || l0.tag == 627u)) {
        return true;
    }
    if ((l0.tag == 573u || l0.tag == 575u || l0.tag == 581u || l0.tag == 583u || l0.tag == 584u)) {
        return true;
    }
    if ((l0.tag == 671u || l0.tag == 676u || l0.tag == 677u || l0.tag == 682u)) {
        return true;
    }
    if ((l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u)) {
        return true;
    }
    if ((l0.tag == 609u || l0.tag == 610u || l0.tag == 611u || l0.tag == 612u || l0.tag == 624u || l0.tag == 625u || l0.tag == 626u)) {
        return true;
    }
    if ((l0.tag == 595u || l0.tag == 596u || l0.tag == 597u || l0.tag == 598u || l0.tag == 599u || l0.tag == 602u)) {
        return true;
    }
    if ((l0.tag == 615u || l0.tag == 616u || l0.tag == 617u || l0.tag == 618u || l0.tag == 619u || l0.tag == 622u)) {
        return true;
    }
    if ((l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 582u)) {
        return true;
    }
    if ((l0.tag == 672u || l0.tag == 673u || l0.tag == 674u || l0.tag == 675u || l0.tag == 678u || l0.tag == 679u || l0.tag == 680u || l0.tag == 681u)) {
        return true;
    }
    if ((l0.tag == 547u || l0.tag == 548u)) {
        return true;
    }
    if ((l0.tag == 647u || l0.tag == 648u || l0.tag == 661u || l0.tag == 663u || l0.tag == 664u)) {
        return true;
    }
    if ((l0.tag == 545u || l0.tag == 549u || l0.tag == 550u)) {
        return true;
    }
    if ((l0.tag == 542u || l0.tag == 543u || l0.tag == 562u || l0.tag == 572u || l0.tag == 585u || l0.tag == 646u)) {
        return true;
    }
    if (!(l0.tag == 567u)) {
        return false;
    }
    return true;
}

static bool vader_c_emit_is_continue_branch(void* l0, int32_t l1) {
    int32_t t0;
    if (((vader_struct_vader_c_emit_ScopeInfo_t*) l0)->f_kind == INT32_C(1)) {
        t0 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l0)->f_opener_pc;
        return (t0 + INT32_C(1)) == l1;
    }
    return false;
}

static bool vader_c_emit_is_param_by_address(void* l0, size_t l1) {
    size_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address)->length;
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_bool(228u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = t0.payload.b;
        return t1;
    }
    return false;
}

static bool vader_c_emit_is_ref_val(uint8_t l0) {
    if (l0 == INT32_C(18)) {
        return true;
    }
    return l0 == INT32_C(19);
}

static bool vader_c_emit_is_scope_opening(vader_box_t l0) {
    return (l0.tag == 544u || l0.tag == 628u || l0.tag == 641u);
}

static void* vader_c_emit_lift_signature(void* l0, vader_string_t l1, void* l2) {
    vader_string_t l3 = 0;
    size_t l4;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(2488u, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    t1 = (t0 - INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    t2 = vader_c_emit_erased_wrapper_signature(l0, l3, l4);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_lift_unbox_tail(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3, l5;
    uint64_t l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    uint8_t l8;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l9, &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    if ((INT64_C(1) < l2)) {
        t0 = ((vader_array_t*) l0)->length;
        t1 = (t0 - INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    } else {
        l2 = (size_t) 0;
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 1;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        l4 = std_core_new_byte_buffer((size_t) 21);
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l4, l5, 1151u);
        t1 = (l2 - INT64_C(1));
        l6 = (uint64_t) (int64_t) t1;
        l5 = std_core_write_unsigned(l4, l5, l6);
        t2 = std_core_finish_buffer(l4, l5);
        l7 = vader_c_emit_c_ast_verbatim(t2);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t3 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 236u);
        l8 = ((uint8_t) t3.payload.i);
        l9 = vader_c_emit_unbox_expr(l7, l8);
        vader_array_push((vader_array_t*) l1, l9);
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_main_body(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    int32_t l5, l11;
    size_t l6;
    bool l7;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    size_t t2;
    void* t3 = NULL;
    vader_string_t t4 = 0;
    vader_string_t t5 = 0;
    uint8_t t6;
    vader_box_t* gc_roots[5] = { &l2, &l8, &l13, &l14, &t0 };
    void** gc_raw_roots[7] = { &l0, &l3, &l4, &l9, &l10, &l12, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t4, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_verbatim(1239u);
    t0 = vader_c_emit_c_ast_cast(2555u, l2);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 722u);
    _a0_obj->f_expression = t0;
    l3 = (void*) _a0_obj;
    l2 = vader_c_emit_c_ast_verbatim(1242u);
    t0 = vader_c_emit_c_ast_cast(2555u, l2);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 722u);
    _a1_obj->f_expression = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(182u, 2u, 13u, 1363u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3;
    l3 = (void*) _a2_arr;
    l5 = vader_c_emit_find_main(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module, l1);
    if ((l5 < INT32_C(0))) {
        vader_array_t* _a3_arr = vader_array_new(54u, 0u, 13u, 706u);
        l4 = (void*) _a3_arr;
        l2 = vader_c_emit_c_ast_number(INT64_C(0));
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a4_obj, 743u);
        _a4_obj->f_stores = l4;
        _a4_obj->f_value = l2;
        _a4_obj->f_snapshot_type = 0u;
        _a4_obj->f_pops_frame = false;
        l4 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t1 = ((int64_t) (int32_t) l5);
    l6 = (size_t) (int64_t) t1;
    vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
    l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params)->length;
    l7 = t2 == INT64_C(1);
    l2 = vader_c_emit_c_ast_verbatim(2451u);
    l8 = vader_c_emit_c_ast_verbatim(747u);
    vader_array_t* _a6_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l8.payload.obj;
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l2.payload.obj;
    l9 = (void*) _a6_arr;
    t0 = vader_c_emit_c_ast_perform(2453u, l9);
    vader_array_t* _a7_arr = vader_array_new(182u, 1u, 13u, 1363u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0.payload.obj;
    l9 = (void*) _a7_arr;
    t3 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    l6 = ((vader_array_t*) t3)->length;
    if ((l6 > INT64_C(0))) {
        l2 = vader_c_emit_c_ast_verbatim(2499u);
        t0 = vader_c_emit_c_ast_verbatim(2501u);
        l8 = vader_c_emit_c_ast_address_of(t0);
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a8_obj, 706u);
        _a8_obj->f_target = l2;
        _a8_obj->f_value = l8;
        _a8_obj->f_operator = vader_box_obj(0u, NULL);
        l10 = (void*) _a8_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l10));
        l2 = vader_c_emit_c_ast_verbatim(2500u);
        l8 = vader_c_emit_c_ast_unsigned(((int64_t) (size_t) l6));
        vader_array_t* _a9_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = l2.payload.obj;
        l10 = (void*) _a9_arr;
        l2 = vader_c_emit_c_ast_perform(2455u, l10);
        vader_array_push((vader_array_t*) l9, l2);
    }
    t0 = vader_c_emit_c_ast_verbatim(2456u);
    vader_array_t* _a10_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = t0.payload.obj;
    l10 = (void*) _a10_arr;
    l2 = vader_c_emit_c_ast_perform(1287u, l10);
    vader_array_push((vader_array_t*) l9, l2);
    t0 = vader_c_emit_c_ast_verbatim(2498u);
    vader_array_t* _a11_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0.payload.obj;
    l10 = (void*) _a11_arr;
    l2 = vader_c_emit_c_ast_perform(1287u, l10);
    vader_array_push((vader_array_t*) l9, l2);
    vader_array_t* _a12_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l10 = (void*) _a12_arr;
    if (l7) {
        l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_string_tag;
        l11 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_string_array_tag;
        if ((l5 < INT32_C(0))) {
            l7 = true;
        } else {
            l7 = (l11 < INT32_C(0));
        }
        if (l7) {
            vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l3);
            l2 = vader_c_emit_trap(1920u);
            vader_array_push((vader_array_t*) l9, l2);
            vader_array_t* _a13_arr = vader_array_new(54u, 0u, 13u, 706u);
            l12 = (void*) _a13_arr;
            l2 = vader_c_emit_c_ast_number(INT64_C(1));
            vader_struct_vader_c_emit_c_ast_CReturn_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
            vader_obj_header_init(_a14_obj, 743u);
            _a14_obj->f_stores = l12;
            _a14_obj->f_value = l2;
            _a14_obj->f_snapshot_type = 0u;
            _a14_obj->f_pops_frame = false;
            l12 = (void*) _a14_obj;
            vader_array_push((vader_array_t*) l9, vader_ref_box(l12));
            { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_c_emit_c_ast_verbatim(1239u);
        l8 = vader_c_emit_c_ast_verbatim(1242u);
        l13 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l11));
        l14 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l5));
        vader_array_t* _a15_arr = vader_array_new(181u, 4u, 13u, 1359u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 3u] = l14.payload.obj;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 2u] = l13.payload.obj;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l2.payload.obj;
        l12 = (void*) _a15_arr;
        l2 = vader_c_emit_c_ast_call(2513u, l12);
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) INT32_C(0), 236u);
        if (((int32_t) t0.payload.i) == INT32_C(18)) {
            l8 = vader_c_emit_c_ast_cast(2556u, l2);
            l8 = vader_c_emit_c_ast_declaration(2556u, 803u, l8);
            vader_array_push((vader_array_t*) l9, l8);
        } else {
            t0 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l11));
            vader_array_t* _a17_arr = vader_array_new(181u, 2u, 13u, 1359u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l2.payload.obj;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t0.payload.obj;
            l12 = (void*) _a17_arr;
            l2 = vader_c_emit_c_ast_call(2460u, l12);
            l2 = vader_c_emit_c_ast_declaration(2462u, 803u, l2);
            vader_array_push((vader_array_t*) l9, l2);
        }
        l2 = vader_c_emit_c_ast_verbatim(803u);
        vader_array_push((vader_array_t*) l10, l2);
    } else {
        vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l3);
    }
    t4 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    t5 = vader_c_emit_sanitise(t4);
    l2 = vader_c_emit_c_ast_call(t5, l10);
    t6 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature);
    if (t6 == INT32_C(16)) {
        vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
        vader_obj_header_init(_a18_obj, 722u);
        _a18_obj->f_expression = l2;
        l3 = (void*) _a18_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l3));
        vader_array_t* _a19_arr = vader_array_new(54u, 0u, 13u, 706u);
        l3 = (void*) _a19_arr;
        l8 = vader_c_emit_c_ast_number(INT64_C(0));
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a20_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a20_obj, 743u);
        _a20_obj->f_stores = l3;
        _a20_obj->f_value = l8;
        _a20_obj->f_snapshot_type = 0u;
        _a20_obj->f_pops_frame = false;
        l3 = (void*) _a20_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l3));
        { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a21_arr = vader_array_new(54u, 0u, 13u, 706u);
    l3 = (void*) _a21_arr;
    l2 = vader_c_emit_c_ast_cast(1804u, l2);
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a22_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a22_obj, 743u);
    _a22_obj->f_stores = l3;
    _a22_obj->f_value = l2;
    _a22_obj->f_snapshot_type = 0u;
    _a22_obj->f_pops_frame = false;
    l3 = (void*) _a22_obj;
    vader_array_push((vader_array_t*) l9, vader_ref_box(l3));
    { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_materialise_entry(void* l0, vader_box_t l1) {
    uint8_t l2;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_new_temporary(l0, l2);
    l4 = vader_c_emit_expression_of(l1);
    vader_c_emit_assign(l0, vader_ref_box(l3), l4);
    vader_struct_vader_c_emit_StackTemporary_t* _a0_obj = (vader_struct_vader_c_emit_StackTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackTemporary_t));
    vader_obj_header_init(_a0_obj, 703u);
    _a0_obj->f_temporary = l3;
    _a0_obj->f_val = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_materialize_stack_for_slot(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    void* l5 = NULL;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t0 = vader_c_emit_entry_needs_materialise(l4, l1);
        if (t0) {
            l5 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
            l6 = vader_c_emit_materialise_entry(l0, l4);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2, l6.payload.obj);
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static size_t vader_c_emit_max_fn_arity(void* l0) {
    size_t l1, l3, l4;
    void* l2;
    vader_box_t l5;
    void* t0;
    size_t t1;
    int64_t t2;
    l1 = (size_t) 0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 526u) {
            t0 = l5.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params)->length;
            if ((t1 > l1)) {
                t0 = l5.payload.obj;
                l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params)->length;
            }
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return l1;
}

static vader_string_t vader_c_emit_mirrored_c_struct(void* l0, int32_t l1) {
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
    if (!(l5.tag == 536u)) {
        return 0u;
    }
    t1 = l5.payload.obj;
    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
    return t2;
}

static uint8_t vader_c_emit_module_function_storage(void* l0, int32_t l1) {
    size_t l2, l3;
    void* l4;
    bool t0;
    int64_t t1;
    vader_box_t t2;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    if (!(t0)) {
        return (uint8_t) 0;
    }
    t1 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t1;
    l3 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_internal_fns)->length;
    if ((l2 < l3)) {
        l4 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_internal_fns;
        t1 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t2 = vader_box_bool(228u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2]);
        t0 = t2.payload.b;
        if (t0) {
            return (uint8_t) 0;
        }
        return (uint8_t) 1;
    }
    return (uint8_t) 1;
}

static vader_string_t vader_c_emit_module_stem_of(vader_string_t l0) {
    ptrdiff_t l1;
    void* l2 = NULL;
    size_t l3;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_string_index_of(l0, 36u, (size_t) 0);
    if (!((l1 < INT64_C(0)))) {
        l2 = vader_host_std_core_bytes(l0);
        t0 = ((int64_t) (ptrdiff_t) l1);
        l3 = (size_t) (int64_t) t0;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l3);
        t1 = (void*) _a0_arr;
        t2 = vader_host_std_core_bytes_to_string(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static void* vader_c_emit_mutable_pool_indices(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 4u, 240u);
    l1 = (void*) _a0_arr;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _pc7_hdr = (vader_array_t*) l1;
    size_t _pc7_len = _pc7_hdr->length;
    size_t _pc7_cap = (_pc7_hdr->offset == 0 && !vader_array_is_borrowed(_pc7_hdr) && _pc7_hdr->length >= _pc7_hdr->buf->length) ? _pc7_hdr->capacity : (size_t) 0;
    void* _pc7_slots = _pc7_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            t1 = vader_bytecode_data_entry_mutable(t0);
            if (t1) {
                if (VADER_LIKELY(_pc7_len < _pc7_cap)) {
                    ((int64_t*) _pc7_slots)[_pc7_len] = (int64_t) ((int64_t) (size_t) l2);
                    _pc7_len += 1;
                } else {
                    _pc7_hdr->length = _pc7_len;
                    if (_pc7_hdr->buf->length < _pc7_len) {
                        _pc7_hdr->buf->length = _pc7_len;
                    }
                    vader_array_push_i64((vader_array_t*) l1, (int64_t) (size_t) l2);
                    _pc7_hdr = (vader_array_t*) l1;
                    _pc7_len = _pc7_hdr->length;
                    _pc7_cap = (_pc7_hdr->offset == 0 && !vader_array_is_borrowed(_pc7_hdr) && _pc7_hdr->length >= _pc7_hdr->buf->length) ? _pc7_hdr->capacity : (size_t) 0;
                    _pc7_slots = _pc7_hdr->buf->slots;
                }
            }
            t2 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t2;
            continue;
        }
        _pc7_hdr->length = _pc7_len;
        if (_pc7_hdr->buf->length < _pc7_len) {
            _pc7_hdr->buf->length = _pc7_len;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_nested_member_mirrors(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l9 = NULL;
    size_t l4, l5, l7, l8;
    vader_box_t l6 = vader_box_null();
    int32_t l10;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 12u, 228u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 7u, 233u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 312u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 400u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l6 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        if (l6.tag == 536u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
            if (t1 == 0u) {
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                continue;
            }
            t0 = l6.payload.obj;
            l3 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
            l7 = ((vader_array_t*) l3)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                l9 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
                t3 = vader_bytecode_nested_mirror(l9, l0);
                if (!(t3.tag == 0u)) {
                    l10 = ((vader_struct_vader_bytecode_BcField_t*) l9)->f_type_index;
                    std_collections_add__i32(l1, l10);
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
            }
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            continue;
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_new_ctx(void* l0, bool l1, bool l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    int32_t l11, l15, l16;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l8, &l9 };
    void** gc_raw_roots[9] = { &l0, &l3, &l4, &l5, &l12, &l13, &l14, &l17, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l5 = (void*) _a0_arr;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = l8;
        if (l8.tag == 536u) {
            t0 = l9.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            l10 = vader_c_emit_struct_c_name(t1);
            vader_array_push((vader_array_t*) l5, vader_box_string(230u, l10));
        } else {
            vader_array_push((vader_array_t*) l5, vader_box_string(230u, 0u));
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    l11 = vader_c_emit_string_primitive_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l12 = vader_c_emit_imports_may_collect(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports);
    l13 = vader_c_emit_compute_atom_ids(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings, l3);
    l14 = vader_c_emit_atom_table_of(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings, l3);
    l15 = vader_c_emit_null_primitive_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l16 = vader_c_emit_string_array_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types, l11);
    l17 = vader_c_emit_compute_may_alloc(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions, l12);
    vader_struct_vader_c_emit_EmitCtx_t* _a2_obj = (vader_struct_vader_c_emit_EmitCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_EmitCtx_t));
    vader_obj_header_init(_a2_obj, 690u);
    _a2_obj->f_module = l0;
    _a2_obj->f_struct_c_names = l5;
    _a2_obj->f_atom_ids = l13;
    _a2_obj->f_atom_table = l14;
    _a2_obj->f_null_tag = l15;
    _a2_obj->f_string_tag = l11;
    _a2_obj->f_string_array_tag = l16;
    _a2_obj->f_may_alloc = l17;
    _a2_obj->f_import_may_collect = l12;
    _a2_obj->f_release = l1;
    _a2_obj->f_split = l2;
    _a2_obj->f_internal_fns = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_new_fn_state(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(182u, 0u, 13u, 1363u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 708u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(180u, 0u, 13u, 1358u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(61u, 0u, 13u, 753u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(52u, 0u, 13u, 697u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(11u, 0u, 7u, 233u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(11u, 0u, 7u, 233u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(51u, 0u, 13u, 696u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(50u, 0u, 13u, 687u);
    l9 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(53u, 0u, 13u, 702u);
    l10 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(185u, 0u, 13u, 1373u);
    l11 = (void*) _a10_arr;
    vader_struct_vader_c_emit_FnState_t* _a11_obj = (vader_struct_vader_c_emit_FnState_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_FnState_t));
    vader_obj_header_init(_a11_obj, 692u);
    _a11_obj->f_ctx = l0;
    _a11_obj->f_function = l1;
    _a11_obj->f_root = l2;
    _a11_obj->f_stack = l3;
    _a11_obj->f_temporaries = l4;
    _a11_obj->f_aux_counter = INT32_C(0);
    _a11_obj->f_scopes = l5;
    _a11_obj->f_continue_targets = l6;
    _a11_obj->f_break_targets = l7;
    _a11_obj->f_no_frame = true;
    _a11_obj->f_push_caches = l8;
    _a11_obj->f_bound_arrays = l9;
    _a11_obj->f_drop_call_result = false;
    _a11_obj->f_stack_storages = l10;
    _a11_obj->f_open_nodes = l11;
    t0 = (void*) _a11_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_new_temporary(void* l0, uint8_t l1) {
    int32_t l2, l3;
    void* l4 = NULL;
    size_t t0;
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_temporaries)->length;
    l2 = ((int32_t) (size_t) t0);
    l3 = -(INT32_C(1));
    vader_struct_vader_c_emit_c_ast_CTemporary_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CTemporary_t));
    vader_obj_header_init(_a0_obj, 753u);
    _a0_obj->f_id = l2;
    _a0_obj->f_val = l1;
    _a0_obj->f_slot = l3;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_temporaries, vader_ref_box(l4));
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_null_member(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_2(l0, 264u);
    l3 = vader_c_emit_c_ast_number(INT64_C(0));
    t0 = vader_c_emit_c_ast_pointer_member(l2, l3, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_null_or(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l3, &l4 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_50;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_c_emit_c_ast_binary((uint8_t) 11, l0, vader_ref_box(l2));
    vader_array_t* _a1_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l2 = (void*) _a1_arr;
    l4 = vader_c_emit_c_ast_call(2459u, l2);
    vader_struct_vader_c_emit_c_ast_CConditional_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
    vader_obj_header_init(_a2_obj, 715u);
    _a2_obj->f_condition = l3;
    _a2_obj->f_then_value = l4;
    _a2_obj->f_else_value = l1;
    t0 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_null_primitive_tag(void* l0) {
    size_t l1, l2;
    vader_box_t l3;
    void* t0;
    int64_t t1;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l3.tag == 532u) {
            t0 = l3.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15)) {
                return ((int32_t) (size_t) l1);
            }
        }
        t1 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t1;
    }
    return INT32_C(0);
}

static vader_box_t vader_c_emit_object_header(vader_box_t l0) {
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
    t0 = (void*) &vader_data_49;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_49;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_49;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_50;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l4 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(181u, 5u, 13u, 1359u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 4u] = l4;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 3u] = l3;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l2;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l1;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l0.payload.obj;
    t0 = (void*) _a4_arr;
    t1 = vader_c_emit_c_ast_initializer_list(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_object_pointer(vader_box_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(18)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_payload(l0, 2008u);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_object_pointer_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    uint8_t l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_expression_of(l0);
    l2 = vader_c_emit_val_of(l0);
    t0 = vader_c_emit_object_pointer(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_one_variant_check(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    size_t l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[3] = { &l1, &l5, &t3 };
    void** gc_raw_roots[3] = { &l0, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 533u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcRef_t*) t1)->f_trait_name;
        if (t2 != 0u) {
            l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx;
            t1 = l5.payload.obj;
            l6 = ((vader_struct_vader_bytecode_BcRef_t*) t1)->f_trait_name;
            t3 = vader_c_emit_trait_check_expr(l3, l1, l6, l2);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l5.tag == 532u) {
        t1 = l5.payload.obj;
        t4 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
        if (t4) {
            t3 = vader_c_emit_float_tag_check_expr(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types, l1);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = vader_c_emit_tag_equals(l1, l2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_c_emit_tag_equals(l1, l2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_op_may_collect(vader_box_t l0, void* l1) {
    bool l2;
    size_t l3;
    void* t0;
    bool t1;
    int32_t t2;
    int64_t t3;
    vader_box_t t4;
    if (l0.tag == 667u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        l2 = !(t1);
        return l2;
    }
    if (l0.tag == 559u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t3 = ((int64_t) (int32_t) t2);
        l3 = (size_t) (int64_t) t3;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t4 = vader_box_bool(228u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3]);
        l2 = t4.payload.b;
    } else if ((l0.tag == 515u || l0.tag == 516u || l0.tag == 517u || l0.tag == 519u || l0.tag == 521u || l0.tag == 553u || l0.tag == 554u || l0.tag == 560u || l0.tag == 586u || l0.tag == 642u || l0.tag == 665u || l0.tag == 684u)) {
        l2 = true;
    } else {
        if (!((l0.tag == 511u || l0.tag == 512u || l0.tag == 513u || l0.tag == 514u || l0.tag == 518u || l0.tag == 520u || l0.tag == 542u || l0.tag == 543u || l0.tag == 544u || l0.tag == 545u || l0.tag == 546u || l0.tag == 547u || l0.tag == 548u || l0.tag == 549u || l0.tag == 550u || l0.tag == 551u || l0.tag == 552u || l0.tag == 555u || l0.tag == 558u || l0.tag == 561u || l0.tag == 562u || l0.tag == 563u || l0.tag == 565u || l0.tag == 566u || l0.tag == 567u || l0.tag == 568u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 581u || l0.tag == 582u || l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 587u || l0.tag == 588u || l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 593u || l0.tag == 594u || l0.tag == 595u || l0.tag == 596u || l0.tag == 597u || l0.tag == 598u || l0.tag == 599u || l0.tag == 600u || l0.tag == 601u || l0.tag == 602u || l0.tag == 603u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 608u || l0.tag == 609u || l0.tag == 610u || l0.tag == 611u || l0.tag == 612u || l0.tag == 613u || l0.tag == 614u || l0.tag == 615u || l0.tag == 616u || l0.tag == 617u || l0.tag == 618u || l0.tag == 619u || l0.tag == 620u || l0.tag == 621u || l0.tag == 622u || l0.tag == 623u || l0.tag == 624u || l0.tag == 625u || l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 638u || l0.tag == 639u || l0.tag == 640u || l0.tag == 641u || l0.tag == 643u || l0.tag == 644u || l0.tag == 646u || l0.tag == 647u || l0.tag == 648u || l0.tag == 649u || l0.tag == 650u || l0.tag == 651u || l0.tag == 652u || l0.tag == 654u || l0.tag == 655u || l0.tag == 656u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 666u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 672u || l0.tag == 673u || l0.tag == 674u || l0.tag == 675u || l0.tag == 676u || l0.tag == 677u || l0.tag == 678u || l0.tag == 679u || l0.tag == 680u || l0.tag == 681u || l0.tag == 682u || l0.tag == 683u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    return l2;
}

static void vader_c_emit_open_else(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2;
    vader_box_t l3 = vader_box_null();
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
    t1 = (t0 - INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l3.tag == 729u)) {
        vader_host_std_abort_panic(1369u);
        vader_unreachable("a no-return call returned");
    }
    l1 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(182u, 0u, 13u, 1363u);
    t2 = (void*) _a1_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a2_obj, 708u);
    _a2_obj->f_body = t2;
    l4 = (void*) _a2_obj;
    ((vader_struct_vader_c_emit_c_ast_CIf_t*) l1)->f_else_block = vader_ref_box(l4);
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_c_ast_CIf_t*) l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_open_if(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(182u, 0u, 13u, 1363u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 708u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CIf_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIf_t));
    vader_obj_header_init(_a2_obj, 729u);
    _a2_obj->f_condition = l1;
    _a2_obj->f_then_block = l2;
    _a2_obj->f_else_block = vader_box_obj(0u, NULL);
    _a2_obj->f_end_label = 0u;
    l2 = (void*) _a2_obj;
    vader_c_emit_open_node(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_open_node(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_c_emit_append_statement(l0, l1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_open_scope(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(182u, 0u, 13u, 1363u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 708u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CScope_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CScope_t));
    vader_obj_header_init(_a2_obj, 744u);
    _a2_obj->f_label = l1;
    _a2_obj->f_body = l2;
    _a2_obj->f_end_label = 0u;
    l2 = (void*) _a2_obj;
    vader_c_emit_open_node(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_operand_as(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    uint8_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l4 = vader_c_emit_expression_of(l1);
    l5 = vader_c_emit_val_of(l1);
    t0 = vader_c_emit_coerce_operand(l3, l4, l5, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_out_param_name(size_t l0) {
    void* l1 = NULL;
    size_t l2;
    uint64_t l3;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 23);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 819u);
    t0 = ((int64_t) (size_t) l0);
    l3 = (uint64_t) (int64_t) t0;
    l2 = std_core_write_unsigned(l1, l2, l3);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_param_is_mutable(void* l0, size_t l1) {
    size_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_mutable)->length;
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_mutable);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_bool(228u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = t0.payload.b;
        return t1;
    }
    return false;
}

static void* vader_c_emit_partition_functions(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l10 = NULL;
    size_t l4, l5, l7;
    int32_t l6;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(18u, 0u, 0u, 241u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 7u, 233u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = vader_c_emit_sorted_fn_indices(l0);
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l6 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
        t0 = ((int64_t) (int32_t) l6);
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        t2 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
        l8 = vader_c_emit_module_stem_of(t2);
        l9 = std_collections_MutableMap_Index_at__string__Any(l1, l8);
        if (l9.tag == 0u) {
            vader_array_t* _a6_arr = vader_array_new(11u, 1u, 7u, 233u);
            ((int32_t*) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = (int32_t) l6;
            l3 = (void*) _a6_arr;
            std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l8, vader_ref_box(l3));
        } else {
            t1 = l9.payload.obj;
            vader_array_push_i32((vader_array_t*) t1, l6);
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a7_arr = vader_array_new(11u, 0u, 7u, 233u);
    t1 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(2u, 1u, 13u, 11u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = t1;
    l2 = (void*) _a8_arr;
    l3 = vader_c_emit_sorted_module_stems(l1);
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
        t3 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
        l8 = t3.payload.s;
        l9 = std_collections_MutableMap_Index_at__string__Any(l1, l8);
        if (l9.tag == 0u) {
            vader_array_t* _a10_arr = vader_array_new(11u, 0u, 7u, 233u);
            l10 = (void*) _a10_arr;
        } else {
            l10 = l9.payload.obj;
        }
        vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_payload(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_2(2047u, l1);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 736u);
    _a0_obj->f_base = l0;
    _a0_obj->f_member = l2;
    _a0_obj->f_arrow = false;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_payload_cast(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
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
    l3 = vader_c_emit_payload(l1, l2);
    t0 = vader_c_emit_c_ast_cast(l0, l3);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 740u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_pc_active_for(void* l0, int32_t l1) {
    size_t l2;
    void* l3;
    int64_t t0;
    int32_t t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches)->length;
    if (l2 == INT64_C(0)) {
        return vader_box_obj(0u, NULL);
    }
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches;
    t0 = (l2 - INT64_C(1));
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t1 = ((vader_struct_vader_c_emit_PushCache_t*) l3)->f_slot;
    if (!(t1 != l1)) {
        return vader_ref_box(l3);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_c_emit_pc_capacity(int32_t l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t0 };
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pc_header(l0, 2011u);
    l2 = vader_c_emit_c_ast_verbatim(328u);
    l1 = vader_c_emit_c_ast_binary((uint8_t) 11, l1, l2);
    l2 = vader_c_emit_c_ast_verbatim(172u);
    t0 = vader_c_emit_pc_local(l0, 1711u);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l3 = (void*) _a0_arr;
    l4 = vader_c_emit_c_ast_call(2426u, l3);
    vader_array_t* _a1_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l2.payload.obj;
    t1 = (void*) _a1_arr;
    vader_struct_vader_c_emit_c_ast_CSequence_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CSequence_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSequence_t));
    vader_obj_header_init(_a2_obj, 746u);
    _a2_obj->f_parts = t1;
    l3 = (void*) _a2_obj;
    l2 = vader_c_emit_pc_header(l0, 1886u);
    l4 = vader_c_emit_pc_header(l0, 1326u);
    l2 = vader_c_emit_c_ast_binary((uint8_t) 10, l2, l4);
    l1 = vader_c_emit_c_ast_binary((uint8_t) 16, l1, vader_ref_box(l3));
    t0 = vader_c_emit_c_ast_binary((uint8_t) 16, l1, l2);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a3_obj, 740u);
    _a3_obj->f_inner = t0;
    l3 = (void*) _a3_obj;
    l1 = vader_c_emit_pc_header(l0, 1403u);
    l2 = vader_c_emit_c_ast_verbatim(328u);
    l2 = vader_c_emit_c_ast_cast(2141u, l2);
    vader_struct_vader_c_emit_c_ast_CConditional_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
    vader_obj_header_init(_a4_obj, 715u);
    _a4_obj->f_condition = vader_ref_box(l3);
    _a4_obj->f_then_value = l1;
    _a4_obj->f_else_value = l2;
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_pc_close_cache(void* l0, int32_t l1) {
    size_t l2;
    void* l3 = NULL;
    int32_t l4;
    int64_t t0;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches)->length;
    if (l2 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches;
    t0 = (l2 - INT64_C(1));
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t1 = ((vader_struct_vader_c_emit_PushCache_t*) l3)->f_opener_pc;
    if (!(t1 != l1)) {
        l4 = ((vader_struct_vader_c_emit_PushCache_t*) l3)->f_opener_pc;
        vader_c_emit_pc_emit_writeback(l0, l4);
        t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_pc_emit_preheader(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    size_t l4;
    int64_t l5;
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
    l2 = ((vader_struct_vader_c_emit_PushCache_t*) l1)->f_opener_pc;
    l3 = std_core_new_byte_buffer((size_t) 27);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 834u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 831u);
    l6 = std_core_finish_buffer(l3, l4);
    t0 = ((vader_struct_vader_c_emit_PushCache_t*) l1)->f_slot;
    vader_struct_vader_c_emit_c_ast_CLocal_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
    vader_obj_header_init(_a0_obj, 734u);
    _a0_obj->f_slot = t0;
    t1 = (void*) _a0_obj;
    l7 = vader_c_emit_array_pointer(vader_ref_box(t1));
    vader_c_emit_declare(l0, 2449u, l6, l7);
    l3 = std_core_new_byte_buffer((size_t) 27);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 834u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 832u);
    l6 = std_core_finish_buffer(l3, l4);
    l7 = vader_c_emit_pc_header(l2, 1886u);
    vader_c_emit_declare(l0, 2141u, l6, l7);
    l3 = std_core_new_byte_buffer((size_t) 27);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 834u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 826u);
    l6 = std_core_finish_buffer(l3, l4);
    l7 = vader_c_emit_pc_capacity(l2);
    vader_c_emit_declare(l0, 2141u, l6, l7);
    l3 = std_core_new_byte_buffer((size_t) 29);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 834u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 836u);
    l6 = std_core_finish_buffer(l3, l4);
    l7 = vader_c_emit_pc_header(l2, 1327u);
    vader_c_emit_declare(l0, 2556u, l6, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_pc_emit_push(void* l0, void* l1, vader_box_t l2, vader_box_t l3) {
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
    l4 = ((vader_struct_vader_c_emit_PushCache_t*) l1)->f_opener_pc;
    l5 = vader_c_emit_pc_local(l4, 1885u);
    l6 = vader_c_emit_pc_local(l4, 1401u);
    t0 = vader_c_emit_c_ast_binary((uint8_t) 7, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l7 = (void*) _a0_arr;
    l5 = vader_c_emit_c_ast_call(751u, l7);
    vader_c_emit_open_if(l0, l5);
    t1 = vader_c_emit_pc_fill_of(((vader_struct_vader_c_emit_PushCache_t*) l1)->f_kind);
    l8 = ((vader_struct_vader_c_emit_SlotFill_t*) t1)->f_cty;
    l9 = concat_2(l8, 264u);
    l5 = vader_c_emit_pc_local(l4, 2150u);
    t0 = vader_c_emit_c_ast_cast(l9, l5);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a1_obj, 740u);
    _a1_obj->f_inner = t0;
    l7 = (void*) _a1_obj;
    l5 = vader_c_emit_pc_local(l4, 1885u);
    vader_struct_vader_c_emit_c_ast_CIndex_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
    vader_obj_header_init(_a2_obj, 731u);
    _a2_obj->f_base = vader_ref_box(l7);
    _a2_obj->f_index = l5;
    l7 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a3_obj, 740u);
    _a3_obj->f_inner = l3;
    l10 = (void*) _a3_obj;
    l5 = vader_c_emit_c_ast_cast(l8, vader_ref_box(l10));
    vader_c_emit_assign(l0, vader_ref_box(l7), l5);
    l5 = vader_c_emit_pc_local(l4, 1885u);
    l6 = vader_c_emit_c_ast_verbatim(331u);
    vader_struct_vader_c_emit_c_ast_CAssign_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
    vader_obj_header_init(_a4_obj, 706u);
    _a4_obj->f_target = l5;
    _a4_obj->f_value = l6;
    _a4_obj->f_operator = vader_box_i32(236u, INT32_C(3));
    l7 = (void*) _a4_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l7));
    vader_c_emit_open_else(l0);
    vader_c_emit_pc_emit_writeback(l0, l4);
    l8 = vader_c_emit_pc_helper_of(((vader_struct_vader_c_emit_PushCache_t*) l1)->f_kind);
    t0 = vader_c_emit_array_pointer(l2);
    vader_array_t* _a5_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0.payload.obj;
    l7 = (void*) _a5_arr;
    l5 = vader_c_emit_c_ast_call(l8, l7);
    vader_c_emit_evaluate(l0, l5);
    l5 = vader_c_emit_pc_local(l4, 1711u);
    l6 = vader_c_emit_array_pointer(l2);
    vader_c_emit_assign(l0, l5, l6);
    vader_c_emit_pc_reload(l0, l4);
    vader_c_emit_close_node(l0, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_pc_emit_writeback(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pc_header(l1, 1886u);
    l3 = vader_c_emit_pc_local(l1, 1885u);
    vader_c_emit_assign(l0, l2, l3);
    l2 = vader_c_emit_pc_header(l1, 1326u);
    l3 = vader_c_emit_pc_local(l1, 1885u);
    l2 = vader_c_emit_c_ast_binary((uint8_t) 7, l2, l3);
    vader_c_emit_open_if(l0, l2);
    l2 = vader_c_emit_pc_header(l1, 1326u);
    l3 = vader_c_emit_pc_local(l1, 1885u);
    vader_c_emit_assign(l0, l2, l3);
    vader_c_emit_close_node(l0, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_c_emit_pc_fill_of(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_typed_array_fill_for(l0);
    if (l1.tag == 0u) {
        vader_struct_vader_c_emit_SlotFill_t* _a0_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a0_obj, 698u);
        _a0_obj->f_cty = 1806u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_pc_header(int32_t l0, vader_string_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pc_local(l0, 1711u);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 736u);
    _a0_obj->f_base = t0;
    _a0_obj->f_member = l1;
    _a0_obj->f_arrow = true;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_pc_helper_of(uint8_t l0) {
    vader_box_t l1;
    vader_string_t t0;
    l1 = vader_c_emit_push_helper_for(l0);
    if (l1.tag == 0u) {
        return 2435u;
    }
    t0 = l1.payload.s;
    return t0;
}

static bool vader_c_emit_pc_liftable_kind(uint8_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_push_helper_for(l0);
    if (!(t0.tag == 0u)) {
        t0 = vader_c_emit_typed_array_fill_for(l0);
        { bool __vret = !(t0.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_c_emit_pc_local(int32_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    size_t l3;
    void* l4 = NULL;
    int64_t l5;
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
    l3 = vader_host_std_core_byte_len(l2);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
    l3 = (size_t) 0;
    l3 = std_core_write_string_at(l4, l3, 834u);
    l5 = ((int64_t) (int32_t) l0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 786u);
    l3 = std_core_write_string_at(l4, l3, l2);
    t0 = std_core_finish_buffer(l4, l3);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_pc_operand_is_slot(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 701u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
    return t1 == l1;
}

static void vader_c_emit_pc_plan_for_loop(void* l0, int32_t l1, int32_t* __o0, int32_t* __o1, int32_t* __o2, uint8_t* __o3) {
    void* l2 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l20 = NULL;
    vader_box_t l3 = vader_box_null(), l13 = vader_box_null(), l19 = vader_box_null();
    int32_t l4, l6, l7, l8, l16, l17, l18, l21;
    uint8_t l5, l15;
    size_t l10, l12;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[3] = { &l3, &l13, &l19 };
    void** gc_raw_roots[7] = { &l0, &l2, &l9, &l11, &l14, &l20, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_scope_ending_for_opener(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l1);
    if (l3.tag == 0u) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    l4 = -(INT32_C(1));
    l5 = (uint8_t) 7;
    l6 = INT32_C(0);
    l7 = (l1 + INT32_C(1));
    for (;;) {
        l8 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_end_pc;
        if ((l7 < l8)) {
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_body;
            t0 = ((int64_t) (int32_t) l7);
            l10 = (size_t) (int64_t) t0;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
            l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l10);
            if (l3.tag == 641u) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 516u) {
                t1 = l3.payload.obj;
                t2 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_cache_slot;
                if ((t2 < INT32_C(0))) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                t1 = l3.payload.obj;
                t2 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_type_id;
                t0 = ((int64_t) (int32_t) t2);
                l12 = (size_t) (int64_t) t0;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
                l13 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
                l14 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                l15 = vader_bytecode_array_kind_of(l13, l14);
                t3 = vader_c_emit_pc_liftable_kind(l15);
                if (!(t3)) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                if ((l4 >= INT32_C(0))) {
                    t1 = l3.payload.obj;
                    l16 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_cache_slot;
                    if (l4 != l16) {
                        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                    }
                }
                t1 = l3.payload.obj;
                l4 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_cache_slot;
                l5 = l15;
                l6 = (l6 + INT32_C(1));
                l7 = (l7 + INT32_C(1));
                continue;
            }
            if ((l3.tag == 650u || l3.tag == 651u)) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            {
                if ((l3.tag == 551u || l3.tag == 552u)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_jump_table);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                    l17 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
                    if (!((l17 < l1))) {
                        l18 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_end_pc;
                        if (!((l17 > l18))) {
                            goto end_145;
                        }
                    }
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
            } end_145: ;
            l19 = l3;
            l20 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_import_may_collect;
            t3 = vader_c_emit_op_may_collect(l19, l20);
            if (t3) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 558u) {
                t1 = l3.payload.obj;
                l21 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
                t3 = std_core____Contains_contains__i32(((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_may_alloc, l21);
                if (t3) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
            }
            l7 = (l7 + INT32_C(1));
            continue;
        }
        break;
    }
    if ((l4 < INT32_C(0))) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches;
    l10 = ((vader_array_t*) l9)->length;
    l12 = (size_t) 0;
    while ((l12 < l10)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l12);
        t2 = ((vader_struct_vader_c_emit_PushCache_t*) t1)->f_slot;
        if (t2 == l4) {
            { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
        }
        t0 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t0;
    }
    l7 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_end_pc;
    t3 = vader_c_emit_pc_slot_used_outside_push(l0, l1, l7, l4, l6);
    if (!(t3)) {
        { *__o3 = l5; *__o2 = l4; *__o1 = l1; *__o0 = INT32_C(1); vader_gc_top = gc_frame.prev; return; }
    }
    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_pc_reload(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pc_local(l1, 1885u);
    l3 = vader_c_emit_pc_header(l1, 1886u);
    vader_c_emit_assign(l0, l2, l3);
    l2 = vader_c_emit_pc_local(l1, 1401u);
    l3 = vader_c_emit_pc_capacity(l1);
    vader_c_emit_assign(l0, l2, l3);
    l2 = vader_c_emit_pc_local(l1, 2150u);
    l3 = vader_c_emit_pc_header(l1, 1327u);
    vader_c_emit_assign(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_c_emit_pc_slot_used_outside_push(void* l0, int32_t l1, int32_t l2, int32_t l3, int32_t l4) {
    int32_t l5, l6;
    void* l7;
    size_t l8;
    vader_box_t l9;
    int64_t t0;
    void* t1;
    int32_t t2;
    l5 = INT32_C(0);
    l6 = l1;
    while ((l6 < l2)) {
        l7 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_body;
        t0 = ((int64_t) (int32_t) l6);
        l8 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        if (l9.tag == 639u) {
            t1 = l9.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            if (t2 == l3) {
                return true;
            }
        }
        if (l9.tag == 640u) {
            t1 = l9.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            if (t2 == l3) {
                return true;
            }
        }
        if (l9.tag == 638u) {
            t1 = l9.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            if (t2 == l3) {
                l5 = (l5 + INT32_C(1));
            }
        }
        if (l9.tag == 637u) {
            t1 = l9.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
            if (t2 == l3) {
                l5 = (l5 + INT32_C(1));
            }
        }
        l6 = (l6 + INT32_C(1));
    }
    return l5 != l4;
}

static vader_string_t vader_c_emit_pointer_to(vader_string_t l0, bool l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1) {
        t0 = concat_2(l0, 264u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_3(1455u, l0, 264u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_pop(void* l0) {
    size_t l1, l3;
    void* l2 = NULL;
    vader_box_t l4 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
        t0 = (l1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
        t0 = (l1 - INT64_C(1));
        l1 = (size_t) (int64_t) t0;
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l1);
        l2 = (void*) _a1_arr;
        ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_c_ast_verbatim(328u);
    vader_struct_vader_c_emit_StackLit_t* _a2_obj = (vader_struct_vader_c_emit_StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLit_t));
    vader_obj_header_init(_a2_obj, 700u);
    _a2_obj->f_expression = t1;
    _a2_obj->f_val = (uint8_t) 2;
    t2 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_pop_args_boxed(void* l0, int32_t l1) {
    void* l2 = NULL;
    size_t l3;
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l5, &l6, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_verbatim(0u);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = INT32_C(0);
    while ((l4 < l1)) {
        l5 = vader_c_emit_pop(l0);
        t1 = ((int64_t) (int32_t) ((l1 - INT32_C(1)) - l4));
        l3 = (size_t) (int64_t) t1;
        l6 = vader_c_emit_coerced_as(l0, l5, (uint8_t) 19);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3, l6.payload.obj);
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        l4 = (l4 + INT32_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_precompute_branch_targets(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    bool l9;
    int32_t l10, l12, l13, l14, l15;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l8, &l11 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 7u, 233u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) l4)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l8.tag == 551u) {
            l9 = true;
        } else {
            l9 = l8.tag == 552u;
        }
        if (l9) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
            l11 = vader_c_emit_branch_target(l1, l10);
            if (l11.tag == 697u) {
                t0 = l11.payload.obj;
                t1 = vader_c_emit_is_continue_branch(t0, l10);
                if (t1) {
                    t0 = l11.payload.obj;
                    l12 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
                    t1 = std_core____Contains_contains__i32(l2, l12);
                    if (!(t1)) {
                        t0 = l11.payload.obj;
                        l13 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
                        vader_array_push_i32((vader_array_t*) l2, l13);
                    }
                } else {
                    t0 = l11.payload.obj;
                    l14 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
                    t1 = std_core____Contains_contains__i32(l3, l14);
                    if (!(t1)) {
                        t0 = l11.payload.obj;
                        l15 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
                        vader_array_push_i32((vader_array_t*) l3, l15);
                    }
                }
            }
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_struct_vader_c_emit_BranchTargets_t* _a4_obj = (vader_struct_vader_c_emit_BranchTargets_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_BranchTargets_t));
    vader_obj_header_init(_a4_obj, 688u);
    _a4_obj->f_continue_targets = l2;
    _a4_obj->f_break_targets = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_precompute_scopes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l17 = NULL;
    size_t l5, l6, l11, l12, l14, l18, l19;
    vader_box_t l7 = vader_box_null();
    int32_t l8, l9, l10, l13, l16;
    uint8_t l15;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l17 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(52u, 0u, 13u, 697u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 7u, 233u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 1u, 236u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l4)->length;
    while ((l5 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if (l7.tag == 544u) {
            l8 = ((int32_t) (size_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l8);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
        } else if (l7.tag == 641u) {
            l9 = ((int32_t) (size_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l9);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(1));
        } else if (l7.tag == 628u) {
            l10 = ((int32_t) (size_t) l5);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(2));
        } else if (l7.tag == 571u) {
            l11 = ((vader_array_t*) l2)->length;
            if ((l11 > INT64_C(0))) {
                t0 = (l11 - INT64_C(1));
                l12 = (size_t) (int64_t) t0;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                l13 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                t0 = (l11 - INT64_C(1));
                l14 = (size_t) (int64_t) t0;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                t1 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l14, 236u);
                l15 = ((uint8_t) t1.payload.i);
                l16 = ((int32_t) (size_t) l5);
                vader_struct_vader_c_emit_ScopeInfo_t* _a6_obj = (vader_struct_vader_c_emit_ScopeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ScopeInfo_t));
                vader_obj_header_init(_a6_obj, 697u);
                _a6_obj->f_opener_pc = l13;
                _a6_obj->f_kind = l15;
                _a6_obj->f_end_pc = l16;
                l17 = (void*) _a6_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l17));
                t0 = (l11 - INT64_C(1));
                l18 = (size_t) (int64_t) t0;
                vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l18);
                l2 = (void*) _a7_arr;
                t0 = (l11 - INT64_C(1));
                l19 = (size_t) (int64_t) t0;
                vader_array_t* _a8_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l19);
                l3 = (void*) _a8_arr;
            }
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_present_tag(void* l0, uint8_t l1) {
    int32_t l2;
    l2 = vader_c_emit_prim_tag(l0, l1);
    if ((l2 < INT32_C(0))) {
        return INT32_C(0);
    }
    return l2;
}

static int32_t vader_c_emit_prim_tag(void* l0, uint8_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 532u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    return -(INT32_C(1));
}

static bool vader_c_emit_primitive_matches_type(void* l0, uint8_t l1, int32_t l2) {
    size_t l3;
    vader_box_t l4;
    int64_t t0;
    void* t1;
    t0 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 532u)) {
        return false;
    }
    t1 = l4.payload.obj;
    return ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == l1;
}

static int32_t vader_c_emit_primitive_tag_of(void* l0, uint8_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    bool t2;
    vader_box_t t3;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 532u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    t2 = vader_bytecode_is_float_val(l1);
    if (t2) {
        l2 = (size_t) 0;
        l3 = ((vader_array_t*) l0)->length;
        while ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            if (t3.tag == 532u) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
                t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                t0 = t3.payload.obj;
                t2 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
                if (t2) {
                    return ((int32_t) (size_t) l2);
                }
            }
            t1 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t1;
        }
    }
    return INT32_C(0);
}

static void vader_c_emit_push_binop(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_binary_expression(l0, l1, l2);
    vader_c_emit_push_expr(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_binop_any(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l3, &l4, &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_val_of(l4);
    if (t0 == INT32_C(19)) {
        t0 = vader_c_emit_val_of(l3);
        if (t0 == INT32_C(19)) {
            l5 = vader_c_emit_expression_of(l4);
            l6 = vader_c_emit_expression_of(l3);
            vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l6.payload.obj;
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
            l7 = (void*) _a0_arr;
            l5 = vader_c_emit_c_ast_call(2458u, l7);
            if (l1 == INT32_C(11)) {
                l6 = l5;
                vader_c_emit_push_expr(l0, l2, l6);
                { vader_gc_top = gc_frame.prev; return; }
            }
            vader_struct_vader_c_emit_c_ast_CUnary_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnary_t));
            vader_obj_header_init(_a1_obj, 754u);
            _a1_obj->f_operator = 172u;
            _a1_obj->f_operand = l5;
            t1 = (void*) _a1_obj;
            l6 = vader_ref_box(t1);
            vader_c_emit_push_expr(l0, l2, l6);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = vader_c_emit_object_pointer_of(l4);
    l3 = vader_c_emit_object_pointer_of(l3);
    l3 = vader_c_emit_c_ast_binary(l1, l4, l3);
    vader_c_emit_push_expr(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_cmp(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_binary_expression(l0, l1, l2);
    vader_c_emit_push_expr(l0, (uint8_t) 12, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_const(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_const_val(l1);
    l3 = vader_c_emit_const_lit_c(((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx, l1);
    vader_c_emit_push_lit(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_eager(void* l0, uint8_t l1, uint8_t l2) {
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
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_operand_as(l0, l4, l2);
    l3 = vader_c_emit_operand_as(l0, l3, l2);
    l5 = vader_c_emit_div_mod_helper(l1, l2);
    if (l5.tag == 0u) {
        l6 = vader_c_emit_c_ast_binary(l1, l4, l3);
        vader_c_emit_push_into_temporary(l0, l6, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l5.payload.s;
    vader_array_t* _a0_arr = vader_array_new(181u, 2u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l8 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(l7, l8);
    vader_c_emit_push_into_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_expr(void* l0, uint8_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackExpr_t* _a0_obj = (vader_struct_vader_c_emit_StackExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackExpr_t));
    vader_obj_header_init(_a0_obj, 699u);
    _a0_obj->f_expression = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_push_helper_for(uint8_t l0) {
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
        l1 = vader_box_string(230u, 2435u);
        return l1;
    }
    if (l0 == INT32_C(8)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l1 = vader_box_string(230u, 2436u);
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_string(230u, 2433u);
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_string(230u, 2432u);
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_string(230u, 2439u);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_string(230u, 2437u);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_string(230u, 2438u);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_string(230u, 2434u);
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_string(230u, 2431u);
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

static void vader_c_emit_push_i64_neg(void* l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 3);
    if (l1.tag == 733u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_class == INT32_C(3);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.obj;
        l2 = vader_c_emit_c_ast_is_most_negative(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        l3 = l1.payload.obj;
        vader_c_emit_push_lit(l0, (uint8_t) 3, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_struct_vader_c_emit_c_ast_CUnary_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnary_t));
    vader_obj_header_init(_a0_obj, 754u);
    _a0_obj->f_operator = 282u;
    _a0_obj->f_operand = l1;
    l3 = (void*) _a0_obj;
    vader_c_emit_push_expr(l0, (uint8_t) 3, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_into_temporary(void* l0, vader_box_t l1, uint8_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_new_temporary(l0, l2);
    vader_c_emit_assign(l0, vader_ref_box(l3), l1);
    vader_c_emit_push_temporary(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7) {
    void* l8 = NULL;
    void* l11 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l32 = NULL;
    size_t l9, l10;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l28 = 0;
    vader_string_t l36 = 0;
    int64_t l14, l15;
    vader_box_t l16 = vader_box_null(), l22 = vader_box_null(), l26 = vader_box_null(), l27 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null(), l31 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null(), l35 = vader_box_null(), l37 = vader_box_null(), l38 = vader_box_null(), l39 = vader_box_null();
    int32_t l20;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[14] = {
        &l16, &l22, &l26, &l27, &l29, &l30, &l31, &l33, &l34, &l35, &l37, &l38, &l39, &t0,
    };
    void** gc_raw_roots[10] = { &l0, &l1, &l6, &l8, &l11, &l17, &l21, &l25, &l32, &t2 };
    vader_string_t* gc_atom_roots[12] = {
        &l2, &l3, &l4, &l12, &l13, &l18, &l19, &l23, &l24, &l28, &l36, &t3,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 14u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 12u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_bytecode_c_struct_layout(l1, l0);
    l9 = (size_t) 0;
    l10 = ((vader_array_t*) l1)->length;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l12 = vader_c_emit_c_field_name(l11);
        l13 = concat_2(l3, l12);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l8)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l14 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
        l15 = (l5 + l14);
        l16 = vader_bytecode_nested_mirror(l11, l0);
        if (l16.tag == 0u) {
            t0 = vader_c_emit_null_member(l2, l13);
            vader_array_t* _a2_arr = vader_array_new(181u, 1u, 13u, 1359u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0.payload.obj;
            l21 = (void*) _a2_arr;
            l22 = vader_c_emit_c_ast_call(2142u, l21);
            l23 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_name;
            l24 = concat_2(1615u, l23);
            t0 = vader_c_emit_null_member(l4, l24);
            vader_array_t* _a3_arr = vader_array_new(181u, 1u, 13u, 1359u);
            ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0.payload.obj;
            l25 = (void*) _a3_arr;
            l26 = vader_c_emit_c_ast_call(2142u, l25);
            l27 = vader_c_emit_c_ast_binary((uint8_t) 11, l22, l26);
            l28 = concat_3(l2, 295u, l13);
            l29 = vader_c_emit_static_assert(l27, l28);
            vader_array_push((vader_array_t*) l6, l29);
            l30 = vader_c_emit_c_ast_verbatim(l2);
            l31 = vader_c_emit_c_ast_verbatim(l13);
            vader_array_t* _a4_arr = vader_array_new(181u, 2u, 13u, 1359u);
            ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l31.payload.obj;
            ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l30.payload.obj;
            l32 = (void*) _a4_arr;
            l33 = vader_c_emit_c_ast_call(808u, l32);
            l34 = vader_c_emit_c_ast_number(l15);
            l35 = vader_c_emit_c_ast_binary((uint8_t) 11, l33, l34);
            l36 = concat_4(l2, 295u, l13, 108u);
            l37 = vader_c_emit_static_assert(l35, l36);
            vader_array_push((vader_array_t*) l6, l37);
            l38 = vader_c_emit_signedness_assert(l0, l11, l2, l13);
            if (!(l38.tag == 0u)) {
                l39 = l38;
                vader_array_push((vader_array_t*) l6, l39);
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            continue;
        }
        t2 = l16.payload.obj;
        l17 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
        l18 = concat_2(l13, 295u);
        t2 = l16.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_name;
        l19 = vader_c_emit_struct_c_name(t3);
        l20 = (l7 + INT32_C(1));
        vader_c_emit_push_leaf_asserts(l0, l17, l2, l18, l19, l15, l6, l20);
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_lit(void* l0, uint8_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackLit_t* _a0_obj = (vader_struct_vader_c_emit_StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLit_t));
    vader_obj_header_init(_a0_obj, 700u);
    _a0_obj->f_expression = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_local_ref(void* l0, int32_t l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackLocalRef_t* _a0_obj = (vader_struct_vader_c_emit_StackLocalRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLocalRef_t));
    vader_obj_header_init(_a0_obj, 701u);
    _a0_obj->f_slot = l1;
    _a0_obj->f_val = l2;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_member_copies(void* l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4, void* l5, int32_t l6) {
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
    size_t l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_box_t l16 = vader_box_null();
    int32_t l19;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l16, &t4 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l5, &l7, &l10, &l12, &l15, &l17, &l18, &l20, &l21, &l22, &l23, &t1,
    };
    vader_string_t* gc_atom_roots[5] = { &l11, &l13, &l14, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l6 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l1;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l11 = vader_c_emit_c_field_name(l10);
        vader_struct_vader_c_emit_c_ast_CMember_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a1_obj, 736u);
        _a1_obj->f_base = l2;
        _a1_obj->f_member = l11;
        _a1_obj->f_arrow = false;
        l12 = (void*) _a1_obj;
        l13 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
        l14 = concat_2(1615u, l13);
        vader_struct_vader_c_emit_c_ast_CMember_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a2_obj, 736u);
        _a2_obj->f_base = l3;
        _a2_obj->f_member = l14;
        _a2_obj->f_arrow = true;
        l15 = (void*) _a2_obj;
        l16 = vader_bytecode_nested_mirror(l10, l0);
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
            vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t));
            vader_obj_header_init(_a3_obj, 713u);
            _a3_obj->f_model = vader_ref_box(l20);
            _a3_obj->f_value = vader_ref_box(l21);
            l22 = (void*) _a3_obj;
            vader_struct_vader_c_emit_c_ast_CAssign_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
            vader_obj_header_init(_a4_obj, 706u);
            _a4_obj->f_target = vader_ref_box(l20);
            _a4_obj->f_value = vader_ref_box(l22);
            _a4_obj->f_operator = vader_box_obj(0u, NULL);
            l23 = (void*) _a4_obj;
            vader_array_push((vader_array_t*) l5, vader_ref_box(l23));
            t0 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t0;
            continue;
        }
        t1 = l16.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        t3 = vader_c_emit_struct_c_name(t2);
        t2 = concat_2(t3, 264u);
        t4 = vader_c_emit_c_ast_cast(t2, vader_ref_box(l15));
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a5_obj, 740u);
        _a5_obj->f_inner = t4;
        l17 = (void*) _a5_obj;
        t1 = l16.payload.obj;
        l18 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
        l19 = (l6 + INT32_C(1));
        vader_c_emit_push_member_copies(l0, l18, vader_ref_box(l12), vader_ref_box(l17), l4, l5, l19);
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_object(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_cast(2556u, l1);
    vader_c_emit_push_into_temporary(l0, l2, (uint8_t) 18);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_offset_list(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3;
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
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        t2 = t1.payload.s;
        l7 = __lambda_vader_c_emit_4(t2);
        vader_array_push((vader_array_t*) l4, l7);
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    l3 = l4;
    l8 = concat_3(295u, l1, 833u);
    vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t));
    vader_obj_header_init(_a3_obj, 714u);
    _a3_obj->f_type = 1457u;
    _a3_obj->f_elements = l3;
    l3 = (void*) _a3_obj;
    l7 = vader_c_emit_c_ast_designated(l8, vader_ref_box(l3));
    vader_array_push((vader_array_t*) l0, l7);
    l8 = concat_3(295u, l1, 827u);
    t0 = ((vader_array_t*) l2)->length;
    l7 = vader_c_emit_c_ast_number(((int64_t) (size_t) t0));
    l7 = vader_c_emit_c_ast_designated(l8, l7);
    vader_array_push((vader_array_t*) l0, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_pool_array(void* l0, void* l1, vader_string_t l2, uint8_t l3, void* l4) {
    int64_t l5;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    uint8_t l7;
    bool l8;
    size_t l11, l12;
    void* l13 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    vader_box_t l14 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null();
    size_t t0;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[8] = { &l14, &l15, &l16, &l17, &l18, &l21, &l22, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l13, &l19, &l20, &t5 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l6, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l4)->length;
    l5 = ((int64_t) (size_t) t0);
    t1 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_name;
    l6 = concat_2(t1, 825u);
    l7 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_storage;
    l8 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_constant;
    l9 = 2506u;
    l10 = l2;
    l11 = vader_host_std_core_byte_len(l9);
    l12 = vader_host_std_core_byte_len(l10);
    t2 = (l11 + l12);
    l11 = (size_t) (int64_t) t2;
    l13 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(41) + l11));
    l11 = (size_t) 0;
    l11 = std_core_write_string_at(l13, l11, 2239u);
    l11 = std_core_write_string_at(l13, l11, l9);
    l11 = std_core_write_string_at(l13, l11, 8u);
    l11 = std_core_write_string_at(l13, l11, l10);
    l11 = std_core_write_string_at(l13, l11, 129u);
    l11 = std_core_write_int(l13, l11, l5);
    l11 = std_core_write_string_at(l13, l11, 784u);
    l9 = std_core_finish_buffer(l13, l11);
    t3 = vader_c_emit_c_ast_verbatim(753u);
    l14 = vader_c_emit_object_header(t3);
    l15 = vader_c_emit_c_ast_unsigned(l5);
    l16 = vader_c_emit_c_ast_unsigned(l5);
    t4 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_element_tag;
    l17 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t4));
    t4 = vader_bytecode_array_kind_index(l3);
    l18 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t4));
    t5 = (void*) &vader_data_49;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l13 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t5 = (void*) &vader_data_49;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l19 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t5 = (void*) &vader_data_49;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l20 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a3_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 2u] = l20;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l19;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l13;
    t5 = (void*) _a3_arr;
    l21 = vader_c_emit_c_ast_initializer_list(t5);
    l22 = vader_c_emit_c_ast_initializer_list(l4);
    vader_array_t* _a4_arr = vader_array_new(181u, 7u, 13u, 1359u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 6u] = l22.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 5u] = l21.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 4u] = l18.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 3u] = l17.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l16.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l15.payload.obj;
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l14.payload.obj;
    t5 = (void*) _a4_arr;
    l14 = vader_c_emit_c_ast_initializer_list(t5);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a5_obj, 718u);
    _a5_obj->f_name = l6;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l14;
    l13 = (void*) _a5_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a6_obj, 727u);
    _a6_obj->f_storage = l7;
    _a6_obj->f_constant = l8;
    _a6_obj->f_type = l9;
    _a6_obj->f_declarator = l13;
    l13 = (void*) _a6_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l13));
    l7 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_storage;
    l8 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_constant;
    l9 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_name;
    t4 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_type_id;
    t3 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t4));
    l14 = vader_c_emit_object_header(t3);
    l15 = vader_c_emit_c_ast_unsigned(l5);
    l16 = vader_c_emit_c_ast_unsigned(l5);
    t5 = (void*) &vader_data_49;
    vader_array_t* _a7_slotarr = ((vader_array_t*) t5);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    l13 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
    t3 = vader_c_emit_c_ast_verbatim(l6);
    l17 = vader_c_emit_c_ast_address_of(t3);
    l17 = vader_c_emit_c_ast_cast(2422u, l17);
    vader_array_t* _a8_arr = vader_array_new(181u, 5u, 13u, 1359u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 4u] = l17.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 3u] = l13;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 2u] = l16.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l15.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l14.payload.obj;
    t5 = (void*) _a8_arr;
    l14 = vader_c_emit_c_ast_initializer_list(t5);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a9_obj, 718u);
    _a9_obj->f_name = l9;
    _a9_obj->f_length = vader_box_obj(0u, NULL);
    _a9_obj->f_value = l14;
    l13 = (void*) _a9_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a10_obj, 727u);
    _a10_obj->f_storage = l7;
    _a10_obj->f_constant = l8;
    _a10_obj->f_type = 2448u;
    _a10_obj->f_declarator = l13;
    l13 = (void*) _a10_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l13));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_struct_field(void* l0, int32_t l1, int32_t l2, vader_box_t l3, uint8_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6, l15, l16;
    vader_box_t l7 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l12 = 0;
    int32_t l10;
    uint8_t l11;
    int64_t l18;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    size_t t4;
    vader_box_t* gc_roots[6] = { &l3, &l7, &l13, &l14, &l17, &t2 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    if (!(l7.tag == 536u)) {
        l8 = std_core_new_byte_buffer((size_t) 59);
        l15 = (size_t) 0;
        l15 = std_core_write_string_at(l8, l15, 2236u);
        l18 = ((int64_t) (int32_t) l1);
        l15 = std_core_write_int(l8, l15, l18);
        t1 = std_core_finish_buffer(l8, l15);
        std_abort_todo(t1);
        vader_unreachable("a no-return call returned");
    }
    l8 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
    l9 = t2.payload.s;
    t3 = l7.payload.obj;
    l8 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields;
    t0 = ((int64_t) (int32_t) l2);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
    l10 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_type_index;
    l11 = vader_c_emit_val_type_of_field(l5, l10);
    l7 = vader_c_emit_object_pointer(l3, l4);
    l12 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_name;
    l13 = vader_c_emit_field_of(l9, l7, l12);
    l5 = vader_c_emit_find_layout_siblings(l5, l1);
    t4 = ((vader_array_t*) l5)->length;
    if (t4 == INT64_C(0)) {
        vader_c_emit_push_expr(l0, l11, l13);
    } else {
        l14 = vader_c_emit_tag_expression(l3, l4);
        l6 = (size_t) 0;
        l15 = ((vader_array_t*) l5)->length;
        while ((l6 < l15)) {
            t4 = ((vader_array_t*) l5)->length;
            t0 = ((t4 - INT64_C(1)) - l6);
            l16 = (size_t) (int64_t) t0;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l16)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l16];
            l17 = vader_c_emit_erased_sibling_field_read(l0, l10, l2, l11, l7);
            t2 = vader_c_emit_tag_equals(l14, l10);
            vader_struct_vader_c_emit_c_ast_CConditional_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
            vader_obj_header_init(_a4_obj, 715u);
            _a4_obj->f_condition = t2;
            _a4_obj->f_then_value = l17;
            _a4_obj->f_else_value = l13;
            t3 = (void*) _a4_obj;
            vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
            vader_obj_header_init(_a5_obj, 740u);
            _a5_obj->f_inner = vader_ref_box(t3);
            t3 = (void*) _a5_obj;
            l13 = vader_ref_box(t3);
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
        }
        vader_c_emit_push_expr(l0, l11, l13);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_temporary(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackTemporary_t* _a0_obj = (vader_struct_vader_c_emit_StackTemporary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackTemporary_t));
    vader_obj_header_init(_a0_obj, 703u);
    _a0_obj->f_temporary = l1;
    _a0_obj->f_val = l2;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_unop(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_operand_as(l0, l3, l2);
    vader_struct_vader_c_emit_c_ast_CUnary_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnary_t));
    vader_obj_header_init(_a0_obj, 754u);
    _a0_obj->f_operator = l1;
    _a0_obj->f_operand = l3;
    l4 = (void*) _a0_obj;
    vader_c_emit_push_expr(l0, l2, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_ref_box(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_c_emit_c_ast_call(2512u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_ref_carrying_element(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if ((l0.tag == 523u || l0.tag == 526u || l0.tag == 533u || l0.tag == 536u)) {
        return true;
    }
    if (!(l0.tag == 537u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
    return t1;
}

static void vader_c_emit_return_statement(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    bool l6;
    bool t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l2)->f_stores;
    l4 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l2)->f_value;
    l5 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l2)->f_snapshot_type;
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_no_frame;
    l6 = !(t0);
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a0_obj, 743u);
    _a0_obj->f_stores = l3;
    _a0_obj->f_value = l4;
    _a0_obj->f_snapshot_type = l5;
    _a0_obj->f_pops_frame = l6;
    l2 = (void*) _a0_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_c_emit_sanitise(vader_string_t l0) {
    size_t l1, l3;
    void* l2 = NULL;
    uint8_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 1u, 236u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        l4 = vader_host_std_core_byte_at(l0, l3);
        t1 = vader_text_is_ident_byte(l4);
        if (t1) {
            l5 = l4;
        } else {
            l5 = (uint8_t) 95;
        }
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l5);
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    l6 = vader_host_std_core_bytes_to_string(l2);
    t1 = vader_c_emit_is_c_reserved(l6);
    if (!(t1)) {
        { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = concat_2(l6, 839u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_scalar_cast(vader_box_t l0, uint8_t l1, uint8_t l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    size_t l5;
    int64_t l6;
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
    if (l0.tag == 733u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_class == l1) {
            t0 = l0.payload.obj;
            t1 = vader_c_emit_c_ast_is_most_negative(t0);
            if (!(t1)) {
                l3 = vader_c_emit_c_type_for_val_bare(l2);
                l4 = std_core_new_byte_buffer((size_t) 20);
                l5 = (size_t) 0;
                t0 = l0.payload.obj;
                l6 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_value;
                l5 = std_core_write_int(l4, l5, l6);
                t2 = std_core_finish_buffer(l4, l5);
                l7 = vader_c_emit_c_ast_verbatim(t2);
                t3 = vader_c_emit_c_ast_cast(l3, l7);
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l3 = vader_c_emit_c_type_for_val_bare(l2);
    t2 = vader_c_emit_c_type_for_val_bare(l1);
    l7 = vader_c_emit_c_ast_cast(t2, l0);
    t3 = vader_c_emit_c_ast_cast(l3, l7);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_scalar_tag(void* l0, uint8_t l1) {
    size_t l2, l3;
    void* l4;
    vader_box_t t0;
    uint8_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (t0.tag == 532u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            l4 = t0.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) l4)->f_val != INT32_C(17)) {
                t1 = vader_bytecode_array_kind_of_val(((vader_struct_vader_bytecode_BcPrimitive_t*) l4)->f_val);
                if (t1 == l1) {
                    return ((int32_t) (size_t) l2);
                }
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return INT32_C(0);
}

static void* vader_c_emit_scan_fn_value_usage(void* l0) {
    size_t l1, l4, l9, l10, l12, l13;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int32_t l5;
    bool l6;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 12u, 228u);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a3_arr;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        l5 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l2, l5);
        vader_array_push_bool((vader_array_t*) l3, false);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    l6 = false;
    l7 = l0;
    l1 = ((vader_array_t*) l7)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        l8 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l11 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l10);
            if (l11.tag == 587u) {
                t0 = l11.payload.obj;
                t2 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
                t1 = ((int64_t) (int32_t) t2);
                l12 = (size_t) (int64_t) t1;
                t0 = l11.payload.obj;
                l5 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
                ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l12] = (int32_t) l5;
                l6 = true;
            } else if (l11.tag == 642u) {
                t0 = l11.payload.obj;
                t2 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
                t1 = ((int64_t) (int32_t) t2);
                l13 = (size_t) (int64_t) t1;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l13)
                ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l13] = (uint8_t) true;
                l6 = true;
            }
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    vader_struct_vader_c_emit_FnValueUsage_t* _a8_obj = (vader_struct_vader_c_emit_FnValueUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_FnValueUsage_t));
    vader_obj_header_init(_a8_obj, 693u);
    _a8_obj->f_fn_ref_type = l2;
    _a8_obj->f_is_closure = l3;
    _a8_obj->f_any = l6;
    t0 = (void*) _a8_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_scope_ending_at(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    int32_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_end_pc;
        if (t1 == l1) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            return vader_ref_box(t0);
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_c_emit_scope_ending_for_opener(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    int32_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
        if (t1 == l1) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            return vader_ref_box(t0);
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_c_emit_shim_body(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    uint8_t l4;
    void* l5 = NULL;
    int32_t l6, l7;
    bool l12;
    vader_string_t l13 = 0;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[7] = { &l2, &l3, &l8, &l9, &l10, &l11, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l13, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_argument((size_t) 0);
    l3 = vader_c_emit_argument((size_t) 1);
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l4 = vader_bytecode_intrinsic_id_for(t0);
    if (l4 == INT32_C(17)) {
        vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a0_arr;
        t1 = vader_c_emit_c_ast_perform(2508u, l5);
        vader_array_t* _a1_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a1_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        vader_array_t* _a2_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a2_arr;
        t1 = vader_c_emit_c_ast_returning(2520u, l5);
        vader_array_t* _a3_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a3_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(2)) {
        vader_array_t* _a4_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a4_arr;
        t1 = vader_c_emit_c_ast_returning(2519u, l5);
        vader_array_t* _a5_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a5_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(5)) {
        vader_array_t* _a6_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a6_arr;
        t1 = vader_c_emit_c_ast_returning(2522u, l5);
        vader_array_t* _a7_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a7_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(3)) {
        l6 = vader_c_emit_prim_tag(l1, (uint8_t) 5);
        if ((l6 < INT32_C(0))) {
            t1 = vader_c_emit_trap(1360u);
            vader_array_t* _a8_arr = vader_array_new(182u, 1u, 13u, 1363u);
            ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = t1.payload.obj;
            t2 = (void*) _a8_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = vader_c_emit_array_tag(l1, l6);
        if (!((l7 < INT32_C(0)))) {
            l8 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l7));
            l9 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l6));
            vader_array_t* _a9_arr = vader_array_new(181u, 3u, 13u, 1359u);
            ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 2u] = l9.payload.obj;
            ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 1u] = l8.payload.obj;
            ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = l2.payload.obj;
            l5 = (void*) _a9_arr;
            l8 = vader_c_emit_c_ast_call(2521u, l5);
            vader_array_t* _a10_arr = vader_array_new(54u, 0u, 13u, 706u);
            l5 = (void*) _a10_arr;
            l8 = vader_c_emit_c_ast_cast(2556u, l8);
            vader_struct_vader_c_emit_c_ast_CReturn_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
            vader_obj_header_init(_a11_obj, 743u);
            _a11_obj->f_stores = l5;
            _a11_obj->f_value = l8;
            _a11_obj->f_snapshot_type = 0u;
            _a11_obj->f_pops_frame = false;
            t2 = (void*) _a11_obj;
            vader_array_t* _a12_arr = vader_array_new(182u, 1u, 13u, 1363u);
            ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t2;
            t2 = (void*) _a12_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_c_emit_trap(1361u);
        vader_array_t* _a13_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a13_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(4)) {
        t1 = vader_c_emit_c_ast_cast(2449u, l2);
        vader_array_t* _a14_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t1.payload.obj;
        l5 = (void*) _a14_arr;
        t1 = vader_c_emit_c_ast_returning(2518u, l5);
        vader_array_t* _a15_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a15_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(6)) {
        vader_array_t* _a16_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a16_arr;
        t1 = vader_c_emit_c_ast_returning(2524u, l5);
        vader_array_t* _a17_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a17_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(10)) {
        vader_array_t* _a18_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l5 = (void*) _a18_arr;
        t1 = vader_c_emit_c_ast_perform(2495u, l5);
        vader_array_t* _a19_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a19_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(11)) {
        t1 = vader_c_emit_gc_statistic(2303u);
        vader_array_t* _a20_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a20_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(12)) {
        t1 = vader_c_emit_gc_statistic(1364u);
        vader_array_t* _a21_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a21_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(13)) {
        t1 = vader_c_emit_gc_statistic(2304u);
        vader_array_t* _a22_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a22_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(14)) {
        vader_array_t* _a23_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l5 = (void*) _a23_arr;
        t1 = vader_c_emit_c_ast_returning(2515u, l5);
        vader_array_t* _a24_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a24_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(15)) {
        vader_array_t* _a25_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a25_arr;
        t1 = vader_c_emit_c_ast_perform(2514u, l5);
        vader_array_t* _a26_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a26_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(16)) {
        vader_array_t* _a27_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l5 = (void*) _a27_arr;
        t1 = vader_c_emit_c_ast_returning(2516u, l5);
        vader_array_t* _a28_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a28_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(20)) {
        vader_array_t* _a29_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a29_arr->buf->slots)[_a29_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a29_arr;
        l8 = vader_c_emit_c_ast_call(2528u, l5);
        l8 = vader_c_emit_c_ast_declaration(1456u, 1366u, l8);
        t1 = vader_c_emit_c_ast_verbatim(1366u);
        vader_array_t* _a30_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = t1.payload.obj;
        l5 = (void*) _a30_arr;
        l9 = vader_c_emit_c_ast_call(2485u, l5);
        l9 = vader_c_emit_c_ast_declaration(2556u, 2066u, l9);
        l10 = vader_c_emit_c_ast_verbatim(1366u);
        vader_array_t* _a31_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a31_arr->buf->slots)[_a31_arr->offset + 1u] = l10.payload.obj;
        ((void**) _a31_arr->buf->slots)[_a31_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a31_arr;
        l10 = vader_c_emit_c_ast_perform(2477u, l5);
        vader_array_t* _a32_arr = vader_array_new(54u, 0u, 13u, 706u);
        l5 = (void*) _a32_arr;
        t1 = vader_c_emit_c_ast_verbatim(2066u);
        l11 = vader_c_emit_address_as_size(t1);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a33_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a33_obj, 743u);
        _a33_obj->f_stores = l5;
        _a33_obj->f_value = l11;
        _a33_obj->f_snapshot_type = 0u;
        _a33_obj->f_pops_frame = false;
        l5 = (void*) _a33_obj;
        vader_array_t* _a34_arr = vader_array_new(182u, 4u, 13u, 1363u);
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 3u] = l5;
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 0u] = l8.payload.obj;
        t2 = (void*) _a34_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(21)) {
        l8 = vader_c_emit_size_as_address(l2);
        l9 = vader_c_emit_c_ast_verbatim(1367u);
        vader_array_t* _a35_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a35_arr->buf->slots)[_a35_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a35_arr->buf->slots)[_a35_arr->offset + 0u] = l8.payload.obj;
        l5 = (void*) _a35_arr;
        l8 = vader_c_emit_c_ast_call(2486u, l5);
        vader_array_t* _a36_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a36_arr->buf->slots)[_a36_arr->offset + 0u] = l3.payload.obj;
        l5 = (void*) _a36_arr;
        l9 = vader_c_emit_c_ast_call(2528u, l5);
        l9 = vader_c_emit_c_ast_declaration(1456u, 1367u, l9);
        l8 = vader_c_emit_c_ast_declaration(2556u, 2066u, l8);
        l10 = vader_c_emit_c_ast_verbatim(1367u);
        vader_array_t* _a37_arr = vader_array_new(181u, 2u, 13u, 1359u);
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 1u] = l10.payload.obj;
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 0u] = l3.payload.obj;
        l5 = (void*) _a37_arr;
        l10 = vader_c_emit_c_ast_perform(2477u, l5);
        vader_array_t* _a38_arr = vader_array_new(54u, 0u, 13u, 706u);
        l5 = (void*) _a38_arr;
        t1 = vader_c_emit_c_ast_verbatim(2066u);
        l11 = vader_c_emit_address_as_size(t1);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a39_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a39_obj, 743u);
        _a39_obj->f_stores = l5;
        _a39_obj->f_value = l11;
        _a39_obj->f_snapshot_type = 0u;
        _a39_obj->f_pops_frame = false;
        l5 = (void*) _a39_obj;
        vader_array_t* _a40_arr = vader_array_new(182u, 4u, 13u, 1363u);
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 3u] = l5;
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 0u] = l9.payload.obj;
        t2 = (void*) _a40_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(22)) {
        l2 = vader_c_emit_size_as_address(l2);
        l3 = vader_c_emit_c_ast_cast(2449u, l3);
        l8 = vader_c_emit_argument((size_t) 2);
        l8 = vader_c_emit_c_ast_cast(2449u, l8);
        l9 = vader_c_emit_argument((size_t) 3);
        vader_array_t* _a41_arr = vader_array_new(181u, 4u, 13u, 1359u);
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 3u] = l9.payload.obj;
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 2u] = l8.payload.obj;
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a41_arr;
        t1 = vader_c_emit_c_ast_returning(2483u, l5);
        vader_array_t* _a42_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a42_arr->buf->slots)[_a42_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a42_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(18)) {
        vader_array_t* _a43_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l5 = (void*) _a43_arr;
        t1 = vader_c_emit_c_ast_returning(2479u, l5);
        vader_array_t* _a44_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a44_arr->buf->slots)[_a44_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a44_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(19)) {
        vader_array_t* _a45_arr = vader_array_new(181u, 0u, 13u, 1359u);
        l5 = (void*) _a45_arr;
        t1 = vader_c_emit_c_ast_returning(2478u, l5);
        vader_array_t* _a46_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a46_arr->buf->slots)[_a46_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a46_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(7)) {
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
        l12 = l4 == INT32_C(0);
    }
    if (!(l12)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t3 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_is_extern;
    if (!(t3)) {
        l13 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
        t0 = concat_2(2380u, l13);
        t1 = vader_c_emit_trap(t0);
        vader_array_t* _a47_arr = vader_array_new(182u, 1u, 13u, 1363u);
        ((void**) _a47_arr->buf->slots)[_a47_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a47_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_c_emit_user_extern_shim(l0, l1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_signature_for(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    size_t l3, l7;
    bool l5;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    uint8_t l11;
    int64_t t0;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    uint8_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l6, &l10, &t5 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = vader_c_emit_value_parameters(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params, 1879u);
    t1 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature);
    l5 = (t1 > INT64_C(1));
    if (l5) {
        l6 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_results;
        l3 = (size_t) 0;
        l7 = ((vader_array_t*) l6)->length;
        while ((l3 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 236u);
            t3 = vader_c_emit_c_type_for_val_bare(((uint8_t) t2.payload.i));
            l8 = concat_2(t3, 264u);
            l9 = vader_c_emit_out_param_name(l3);
            vader_struct_vader_c_emit_c_ast_CParameter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
            vader_obj_header_init(_a2_obj, 739u);
            _a2_obj->f_type = l8;
            _a2_obj->f_name = l9;
            l10 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
            t0 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t0;
        }
    }
    l11 = vader_c_emit_module_function_storage(l0, l1);
    if (l5) {
        l8 = 2555u;
    } else {
        t4 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature);
        l8 = vader_c_emit_c_type_for_val_bare(t4);
    }
    t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_name;
    l9 = vader_c_emit_sanitise(t3);
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a3_obj, 747u);
    _a3_obj->f_storage = l11;
    _a3_obj->f_inline_v = false;
    _a3_obj->f_result = l8;
    _a3_obj->f_name = l9;
    _a3_obj->f_parameters = l4;
    t5 = (void*) _a3_obj;
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3) {
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
    l5 = vader_bytecode_c_field_val_type(l1, l0);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((uint8_t) l5.payload.i);
    t0 = vader_bytecode_is_integer_val(l4);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = vader_c_emit_null_member(l2, l3);
    l6 = vader_c_emit_c_ast_number(-(INT64_C(1)));
    vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t));
    vader_obj_header_init(_a0_obj, 713u);
    _a0_obj->f_model = l5;
    _a0_obj->f_value = l6;
    l7 = (void*) _a0_obj;
    l5 = vader_c_emit_c_ast_number(INT64_C(0));
    t1 = vader_c_emit_c_ast_binary((uint8_t) 7, vader_ref_box(l7), l5);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a1_obj, 740u);
    _a1_obj->f_inner = t1;
    l7 = (void*) _a1_obj;
    t0 = vader_bytecode_is_unsigned_val(l4);
    if (t0) {
        l8 = INT64_C(0);
    } else {
        l8 = INT64_C(1);
    }
    l5 = vader_c_emit_c_ast_number(l8);
    l5 = vader_c_emit_c_ast_binary((uint8_t) 11, vader_ref_box(l7), l5);
    l9 = concat_4(l2, 295u, l3, 127u);
    t1 = vader_c_emit_static_assert(l5, l9);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_single_offset_list(vader_string_t l0, vader_string_t l1) {
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
    t0 = (void*) &vader_data_48;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_c_emit_c_ast_verbatim(l1);
    vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
    t0 = (void*) _a1_arr;
    l3 = vader_c_emit_c_ast_initializer_list(t0);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a2_obj, 718u);
    _a2_obj->f_name = l0;
    _a2_obj->f_length = vader_ref_box(l2);
    _a2_obj->f_value = l3;
    l2 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a3_obj, 727u);
    _a3_obj->f_storage = (uint8_t) 0;
    _a3_obj->f_constant = true;
    _a3_obj->f_type = 2373u;
    _a3_obj->f_declarator = l2;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_single_reference_row(size_t l0, vader_string_t l1, vader_string_t l2, int32_t l3, vader_string_t l4) {
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
    t0 = concat_2(754u, l1);
    l5 = vader_c_emit_c_ast_verbatim(t0);
    l5 = vader_c_emit_c_ast_designated(308u, l5);
    t0 = concat_3(2143u, l2, 241u);
    l6 = vader_c_emit_c_ast_verbatim(t0);
    l6 = vader_c_emit_c_ast_designated(313u, l6);
    l7 = vader_c_emit_c_ast_number(((int64_t) (int32_t) l3));
    l7 = vader_c_emit_c_ast_designated(314u, l7);
    l8 = vader_c_emit_c_ast_verbatim(l4);
    l8 = vader_c_emit_c_ast_designated(311u, l8);
    l9 = vader_c_emit_c_ast_number(INT64_C(1));
    l9 = vader_c_emit_c_ast_designated(310u, l9);
    vader_array_t* _a0_arr = vader_array_new(181u, 5u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l9.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l8.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l10 = (void*) _a0_arr;
    t1 = vader_c_emit_info_row(l0, l10);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_size_as_address(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_c_ast_cast(2377u, l0);
    t0 = vader_c_emit_c_ast_cast(2556u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_slot_index(vader_string_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 292u);
    l2 = vader_c_emit_c_ast_verbatim(t0);
    l3 = vader_c_emit_expression_of(l1);
    l3 = vader_c_emit_c_ast_cast(2141u, l3);
    t1 = vader_c_emit_c_ast_binary((uint8_t) 3, l2, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_slot_val_type(void* l0, int32_t l1) {
    void* l2;
    void* l5;
    int32_t l3;
    size_t l4, l6;
    size_t t0;
    int64_t t1;
    void* t2;
    vader_box_t t3;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params;
    t0 = ((vader_array_t*) l2)->length;
    l3 = ((int32_t) (size_t) t0);
    if (!((l1 < l3))) {
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
        t1 = ((int64_t) (int32_t) l1);
        l4 = (size_t) (int64_t) t1;
        l6 = ((vader_array_t*) l2)->length;
        t1 = (l4 - l6);
        l6 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        return ((vader_struct_vader_bytecode_BcLocal_t*) t2)->f_val;
    }
    t1 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 236u);
    return ((uint8_t) t3.payload.i);
}

static void* vader_c_emit_sorted_fn_indices(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    size_t l2, l3;
    int32_t l4;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 7u, 233u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _pc14_hdr = (vader_array_t*) l1;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            l4 = ((int32_t) (size_t) l2);
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
            t0 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t0;
            continue;
        }
        _pc14_hdr->length = _pc14_len;
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    vader_struct___lambda_env_vader_c_emit_1_t* _a2_obj = (vader_struct___lambda_env_vader_c_emit_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_1_t));
    vader_obj_header_init(_a2_obj, 248u);
    _a2_obj->f_cap_0 = l0;
    t1 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 205u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_0;
    _a3_closure->env = t1;
    l5 = (void*) _a3_closure;
    t1 = std_sort_sort__i32(l1, l5);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_sorted_module_stems(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 0u, 230u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32___t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32___t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__i32___t*) l2)->f_size;
    l6 = (size_t) 0;
    while (!((l6 >= l5))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        l7 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = l7;
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
        vader_array_push((vader_array_t*) l1, vader_box_string(230u, l8));
    }
    l2 = (void*) &vader_fn_static___lambda_vader_c_emit_2;
    t1 = std_sort_sort__string(l1, l2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_statement_macro(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CCall_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCall_t));
    vader_obj_header_init(_a0_obj, 710u);
    _a0_obj->f_callee = l1;
    _a0_obj->f_arguments = l2;
    t0 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CMacroStatement_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CMacroStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMacroStatement_t));
    vader_obj_header_init(_a1_obj, 735u);
    _a1_obj->f_call = t0;
    l3 = (void*) _a1_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_static_assert(vader_box_t l0, vader_string_t l1) {
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
    t0 = vader_c_emit_c_string_lit(l1);
    vader_array_t* _a0_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(230u, t0);
    t1 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CStringLiterals_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStringLiterals_t));
    vader_obj_header_init(_a1_obj, 749u);
    _a1_obj->f_literals = t1;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CStaticAssert_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CStaticAssert_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStaticAssert_t));
    vader_obj_header_init(_a2_obj, 748u);
    _a2_obj->f_condition = l0;
    _a2_obj->f_message = l2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_string_array_tag(void* l0, int32_t l1) {
    int32_t t0;
    if (!((l1 < INT32_C(0)))) {
        t0 = vader_c_emit_array_tag(l0, l1);
        return t0;
    }
    return -(INT32_C(1));
}

static int32_t vader_c_emit_string_primitive_tag(void* l0) {
    size_t l1, l2;
    vader_box_t l3;
    void* t0;
    bool t1;
    int64_t t2;
    l1 = (size_t) 0;
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        if (l3.tag == 532u) {
            t0 = l3.payload.obj;
            t1 = vader_bytecode_is_string_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
            if (t1) {
                return ((int32_t) (size_t) l1);
            }
        }
        t2 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
}

static vader_string_t vader_c_emit_struct_c_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_sanitise(l0);
    t0 = concat_3(2529u, l1, 837u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_struct_definition(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    size_t l5, l6, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l7, &l8, &l13, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l11, &l12, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CField_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CField_t));
    vader_obj_header_init(_a0_obj, 723u);
    _a0_obj->f_type = 2505u;
    _a0_obj->f_name = 1712u;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(57u, 1u, 13u, 723u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        t1 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
        t2 = ((int64_t) (int32_t) t1);
        l9 = (size_t) (int64_t) t2;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
        t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
        l10 = vader_c_emit_c_type_for(t3);
        t4 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
        l11 = vader_c_emit_sanitise(t4);
        l12 = concat_2(1615u, l11);
        vader_struct_vader_c_emit_c_ast_CField_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CField_t));
        vader_obj_header_init(_a4_obj, 723u);
        _a4_obj->f_type = l10;
        _a4_obj->f_name = l12;
        l13 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l13));
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
    t3 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l2];
    t4 = t3.payload.s;
    vader_struct_vader_c_emit_c_ast_CStructDefinition_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CStructDefinition_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStructDefinition_t));
    vader_obj_header_init(_a6_obj, 750u);
    _a6_obj->f_name = t4;
    _a6_obj->f_fields = l3;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
    void* l6 = NULL;
    size_t l7;
    uint8_t l8, l9;
    uint64_t l10;
    vader_string_t l11 = 0;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[4] = { &l2, &l12, &l13, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l4);
    l7 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    l8 = vader_c_emit_val_type_of_bc_type(t1);
    if (l8 == INT32_C(19)) {
        t1 = vader_c_emit_box_slot(l0, l1, l2, l3, l4, l5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 539u) {
        t2 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_kind;
        t2 = l2.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_bits;
        t1 = vader_c_emit_data_slot(l9, l10);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 540u) {
        t2 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcValStr_t*) t2)->f_value;
        t3 = vader_c_emit_atom_for(l5, l11);
        t1 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t3));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l8 == INT32_C(18))) {
        l12 = l2;
        l13 = vader_c_emit_emit_data_value(l0, l1, l12, l3, l5);
        t1 = vader_c_emit_boxed_object(l4, l13);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = l2;
    l12 = vader_c_emit_emit_data_value(l0, l1, l12, l3, l5);
    t1 = vader_c_emit_c_ast_cast(2556u, l12);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_struct_info_row(void* l0, void* l1, void* l2, size_t l3) {
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
    l4 = vader_c_emit_c_ast_verbatim(755u);
    l4 = vader_c_emit_c_ast_designated(308u, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
    l5 = t0.payload.s;
    t1 = concat_3(2143u, l5, 241u);
    l6 = vader_c_emit_c_ast_verbatim(t1);
    l6 = vader_c_emit_c_ast_designated(313u, l6);
    t2 = vader_bytecode_size_of_bc_type(vader_ref_box(l1));
    l7 = vader_c_emit_c_ast_number(((int64_t) (int32_t) t2));
    l7 = vader_c_emit_c_ast_designated(314u, l7);
    vader_array_t* _a1_arr = vader_array_new(181u, 3u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l7.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
    l8 = (void*) _a1_arr;
    l9 = ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_ptr_offsets;
    vader_c_emit_push_offset_list(l8, 2060u, l9);
    l9 = ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_str_offsets;
    vader_c_emit_push_offset_list(l8, 2214u, l9);
    l9 = ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_ref_offsets;
    vader_c_emit_push_offset_list(l8, 2082u, l9);
    t0 = vader_c_emit_info_row(l3, l8);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_tag_equals(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
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
    l2 = std_core_new_byte_buffer((size_t) 21);
    l3 = (size_t) 0;
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2346u);
    t0 = std_core_finish_buffer(l2, l3);
    l5 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_binary((uint8_t) 11, l0, l5);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_tag_expression(vader_box_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(18)) {
        t0 = vader_c_emit_c_ast_pointer_member(2507u, l0, 2336u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 736u);
    _a0_obj->f_base = l0;
    _a0_obj->f_member = 2262u;
    _a0_obj->f_arrow = false;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_tag_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    uint8_t l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_expression_of(l0);
    l2 = vader_c_emit_val_of(l0);
    t0 = vader_c_emit_tag_expression(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_trait_check_expr(void* l0, vader_box_t l1, vader_string_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    size_t l6, l7;
    int32_t l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[6] = { &l0, &l4, &l5, &l8, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_tag_equals(l1, l3);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 740u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1;
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_impl_table;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        t2 = ((vader_struct_vader_bytecode_ImplEntry_t*) l8)->f_trait_name;
        if (t2 == l2) {
            l9 = ((vader_struct_vader_bytecode_ImplEntry_t*) l8)->f_struct_type_index;
            t0 = vader_c_emit_tag_equals(l1, l9);
            vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
            vader_obj_header_init(_a3_obj, 740u);
            _a3_obj->f_inner = t0;
            l10 = (void*) _a3_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
        }
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    t0 = vader_c_emit_c_ast_any_of(l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_tramp_unbox_args(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3, l5;
    uint64_t l6;
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
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        l4 = std_core_new_byte_buffer((size_t) 21);
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l4, l5, 1151u);
        t0 = ((int64_t) (size_t) l2);
        l6 = (uint64_t) (int64_t) t0;
        l5 = std_core_write_unsigned(l4, l5, l6);
        t1 = std_core_finish_buffer(l4, l5);
        l7 = vader_c_emit_c_ast_verbatim(t1);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 236u);
        l8 = ((uint8_t) t2.payload.i);
        l9 = vader_c_emit_unbox_expr(l7, l8);
        vader_array_push((vader_array_t*) l1, l9);
        t0 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_trampoline_signature(void* l0, vader_string_t l1, void* l2) {
    vader_string_t l3 = 0;
    size_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_2(2493u, l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    t0 = vader_c_emit_erased_wrapper_signature(l0, l3, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_trap(vader_string_t l0) {
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
    t0 = vader_c_emit_c_string_lit(l0);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    t1 = vader_c_emit_c_ast_perform(2530u, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_type_id_for_struct_symbol(void* l0, int32_t l1) {
    size_t l2, l3;
    void* l4 = NULL;
    int64_t l5;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    int64_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (t0.tag == 536u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            t1 = t0.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_symbol_id;
            if (t2 == l1) {
                { int32_t __vret = ((int32_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        t3 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t3;
    }
    l4 = std_core_new_byte_buffer((size_t) 80);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l4, l2, 1371u);
    l5 = ((int64_t) (int32_t) l1);
    l2 = std_core_write_int(l4, l2, l5);
    l2 = std_core_write_string_at(l4, l2, 105u);
    t4 = std_core_finish_buffer(l4, l2);
    vader_host_std_abort_panic(t4);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_type_index_for_name(void* l0, vader_string_t l1) {
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (t0.tag == 536u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            t1 = t0.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
            l4 = vader_c_emit_struct_c_name(t2);
            l5 = vader_c_emit_struct_c_name(l1);
            if (l4 == l5) {
                { int32_t __vret = ((int32_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        t3 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t3;
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
}

static vader_box_t vader_c_emit_typed_array_fill_for(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(7)) {
        vader_struct_vader_c_emit_SlotFill_t* _a0_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a0_obj, 698u);
        _a0_obj->f_cty = 1806u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_c_emit_SlotFill_t* _a1_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a1_obj, 698u);
        _a1_obj->f_cty = 1806u;
        _a1_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_c_emit_SlotFill_t* _a2_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a2_obj, 698u);
        _a2_obj->f_cty = 1806u;
        _a2_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(8)) {
        vader_struct_vader_c_emit_SlotFill_t* _a3_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a3_obj, 698u);
        _a3_obj->f_cty = 1807u;
        _a3_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(4)) {
        vader_struct_vader_c_emit_SlotFill_t* _a4_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a4_obj, 698u);
        _a4_obj->f_cty = 1807u;
        _a4_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_c_emit_SlotFill_t* _a5_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a5_obj, 698u);
        _a5_obj->f_cty = 1505u;
        _a5_obj->f_val = (uint8_t) 11;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(1)) {
        vader_struct_vader_c_emit_SlotFill_t* _a6_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a6_obj, 698u);
        _a6_obj->f_cty = 2376u;
        _a6_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a6_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(5)) {
        vader_struct_vader_c_emit_SlotFill_t* _a7_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a7_obj, 698u);
        _a7_obj->f_cty = 1808u;
        _a7_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a7_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        vader_struct_vader_c_emit_SlotFill_t* _a8_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a8_obj, 698u);
        _a8_obj->f_cty = 2376u;
        _a8_obj->f_val = (uint8_t) 12;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(2)) {
        vader_struct_vader_c_emit_SlotFill_t* _a9_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a9_obj, 698u);
        _a9_obj->f_cty = 2373u;
        _a9_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(6)) {
        vader_struct_vader_c_emit_SlotFill_t* _a10_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a10_obj, 698u);
        _a10_obj->f_cty = 1805u;
        _a10_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a10_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(9)) {
        vader_struct_vader_c_emit_SlotFill_t* _a11_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a11_obj, 698u);
        _a11_obj->f_cty = 1651u;
        _a11_obj->f_val = (uint8_t) 10;
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

static vader_box_t vader_c_emit_typed_slot(vader_string_t l0, vader_string_t l1, vader_box_t l2) {
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
    l3 = concat_2(l0, 264u);
    t0 = concat_2(l1, 287u);
    l4 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_cast(l3, l4);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 740u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CIndex_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
    vader_obj_header_init(_a1_obj, 731u);
    _a1_obj->f_base = vader_ref_box(t2);
    _a1_obj->f_index = l2;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_unbox_expr(vader_box_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l3, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(0)) {
        l2 = vader_c_emit_payload_cast(1808u, l0, 1716u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        l2 = vader_c_emit_payload_cast(1805u, l0, 1716u);
    } else if (l1 == INT32_C(2)) {
        l2 = vader_c_emit_payload_cast(1806u, l0, 1716u);
    } else if (l1 == INT32_C(3)) {
        l2 = vader_c_emit_payload_cast(1807u, l0, 1716u);
    } else if (l1 == INT32_C(5)) {
        l2 = vader_c_emit_payload_cast(2376u, l0, 1716u);
    } else if (l1 == INT32_C(6)) {
        l2 = vader_c_emit_payload_cast(2373u, l0, 1716u);
    } else if (l1 == INT32_C(7)) {
        l2 = vader_c_emit_payload_cast(2374u, l0, 1716u);
    } else if (l1 == INT32_C(8)) {
        l2 = vader_c_emit_payload_cast(2375u, l0, 1716u);
    } else if (l1 == INT32_C(9)) {
        l2 = vader_c_emit_payload_cast(2141u, l0, 1716u);
    } else if (l1 == INT32_C(4)) {
        l2 = vader_c_emit_payload_cast(2061u, l0, 1716u);
    } else if (l1 == INT32_C(13)) {
        l2 = vader_c_emit_payload_cast(2374u, l0, 1716u);
    } else if (l1 == INT32_C(10)) {
        l2 = vader_c_emit_payload_cast(1651u, l0, 1597u);
    } else if (l1 == INT32_C(11)) {
        l2 = vader_c_emit_payload_cast(1505u, l0, 1597u);
    } else if (l1 == INT32_C(12)) {
        l2 = vader_c_emit_payload(l0, 1292u);
    } else if (l1 == INT32_C(14)) {
        l2 = vader_c_emit_payload(l0, 2115u);
    } else if (l1 == INT32_C(15)) {
        l2 = l0;
    } else if (l1 == INT32_C(16)) {
        l2 = vader_c_emit_c_ast_verbatim(231u);
    } else if (l1 == INT32_C(17)) {
        l3 = vader_c_emit_payload(l0, 1716u);
        l3 = vader_c_emit_c_ast_cast(1822u, l3);
        t0 = vader_c_emit_c_ast_cast(2556u, l3);
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a0_obj, 740u);
        _a0_obj->f_inner = t0;
        t1 = (void*) _a0_obj;
        l2 = vader_ref_box(t1);
    } else if (l1 == INT32_C(18)) {
        l2 = vader_c_emit_payload(l0, 2008u);
    } else {
        if (!(l1 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_unit_names_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    size_t l3, l4, l5, l7, l8, l9;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    uint8_t t4;
    bool t5;
    vader_box_t t6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t6 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l12, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l10, &l11, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 1u, 0u, 230u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(230u, 830u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 1;
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        t2 = ((int64_t) (int32_t) t1);
        l5 = (size_t) (int64_t) t2;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
        l6 = vader_c_emit_module_stem_of(t3);
        l7 = vader_host_std_core_byte_len(l6);
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            t4 = vader_host_std_core_byte_at(l6, l8);
            t5 = vader_text_is_ident_byte(t4);
            if (!(t5)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
                t1 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
                t2 = ((int64_t) (int32_t) t1);
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
                t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                l10 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
                t3 = concat_3(2152u, l10, 944u);
                std_abort_todo(t3);
                vader_unreachable("a no-return call returned");
            }
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
        if (l6 == 0u) {
            l11 = 835u;
        } else {
            l11 = l6;
        }
        vader_array_push((vader_array_t*) l2, vader_box_string(230u, l11));
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a7_arr = vader_array_new(10u, 0u, 0u, 230u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 12u, 228u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(11u, 0u, 7u, 233u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a10_obj, 365u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = (size_t) 0;
    _a10_obj->f_size = (size_t) 0;
    _a10_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__string_t* _a11_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a11_obj, 402u);
    _a11_obj->f_inner = t0;
    l12 = (void*) _a11_obj;
    l13 = l2;
    l3 = ((vader_array_t*) l13)->length;
    l4 = (size_t) 0;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            t6 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l4];
            l6 = t6.payload.s;
            t5 = std_collections_MutableSet_Contains_contains__string(l12, l6);
            if (t5) {
                t3 = concat_3(2151u, l6, 1003u);
                std_abort_todo(t3);
                vader_unreachable("a no-return call returned");
            } else {
                std_collections_add__string(l12, l6);
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                continue;
            }
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_unreachable(void* l0, vader_string_t l1) {
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
    t0 = vader_c_emit_c_string_lit(l1);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(2534u, l2);
    vader_c_emit_evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_c_emit_user_extern_shim(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l45 = NULL;
    void* l50 = NULL;
    void* l56 = NULL;
    void* l59 = NULL;
    void* l60 = NULL;
    void* l63 = NULL;
    void* l64 = NULL;
    void* l69 = NULL;
    void* l73 = NULL;
    void* l77 = NULL;
    void* l80 = NULL;
    void* l84 = NULL;
    void* l86 = NULL;
    size_t l8, l9, l15, l20, l32, l37, l46, l51, l65, l70, l74, l81, l87;
    vader_box_t l10 = vader_box_null(), l13 = vader_box_null(), l18 = vader_box_null(), l23 = vader_box_null(), l34 = vader_box_null(), l40 = vader_box_null(), l41 = vader_box_null(), l42 = vader_box_null(), l43 = vader_box_null(), l49 = vader_box_null(), l53 = vader_box_null(), l54 = vader_box_null(), l57 = vader_box_null(), l58 = vader_box_null(), l61 = vader_box_null(), l62 = vader_box_null(), l68 = vader_box_null(), l72 = vader_box_null(), l78 = vader_box_null(), l79 = vader_box_null(), l83 = vader_box_null(), l85 = vader_box_null(), l89 = vader_box_null();
    int32_t l11, l24, l25, l27, l29, l55;
    uint64_t l16, l21, l33, l38, l47, l52, l66, l71, l75, l82, l88;
    vader_string_t l17 = 0;
    vader_string_t l26 = 0;
    vader_string_t l28 = 0;
    vader_string_t l39 = 0;
    vader_string_t l44 = 0;
    vader_string_t l48 = 0;
    vader_string_t l67 = 0;
    vader_string_t l76 = 0;
    bool l90;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    size_t t5;
    vader_box_t* gc_roots[24] = {
        &l10, &l13, &l18, &l23, &l34, &l40, &l41, &l42, &l43, &l49, &l53, &l54, &l57, &l58, &l61,
        &l62, &l68, &l72, &l78, &l79, &l83, &l85, &l89, &t1,
    };
    void** gc_raw_roots[30] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l12, &l14, &l19, &l22, &l30, &l31, &l35, &l36,
        &l45, &l50, &l56, &l59, &l60, &l63, &l64, &l69, &l73, &l77, &l80, &l84, &l86, &t4,
    };
    vader_string_t* gc_atom_roots[9] = { &l17, &l26, &l28, &l39, &l44, &l48, &l67, &l76, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 24u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature;
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(181u, 0u, 13u, 1359u);
    l7 = (void*) _a4_arr;
    l8 = (size_t) 0;
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    while ((l8 < l9)) {
        l10 = vader_c_emit_argument(l8);
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8];
        t0 = vader_c_emit_is_abi_array(l1, l11);
        if (t0) {
            t1 = vader_c_emit_c_ast_cast(2449u, l10);
            vader_array_t* _a6_arr = vader_array_new(181u, 1u, 13u, 1359u);
            ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t1.payload.obj;
            l12 = (void*) _a6_arr;
            l13 = vader_c_emit_c_ast_call(2423u, l12);
            l14 = std_core_new_byte_buffer((size_t) 21);
            l15 = (size_t) 0;
            l15 = std_core_write_string_at(l14, l15, 2115u);
            t2 = ((int64_t) (size_t) l8);
            l16 = (uint64_t) (int64_t) t2;
            l15 = std_core_write_unsigned(l14, l15, l16);
            l17 = std_core_finish_buffer(l14, l15);
            l18 = vader_c_emit_c_ast_declaration(2517u, l17, l13);
            vader_array_push((vader_array_t*) l4, l18);
            l19 = std_core_new_byte_buffer((size_t) 21);
            l20 = (size_t) 0;
            l20 = std_core_write_string_at(l19, l20, 2115u);
            t2 = ((int64_t) (size_t) l8);
            l21 = (uint64_t) (int64_t) t2;
            l20 = std_core_write_unsigned(l19, l20, l21);
            t3 = std_core_finish_buffer(l19, l20);
            t1 = vader_c_emit_c_ast_verbatim(t3);
            vader_struct_vader_c_emit_c_ast_CMember_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
            vader_obj_header_init(_a7_obj, 736u);
            _a7_obj->f_base = t1;
            _a7_obj->f_member = 2060u;
            _a7_obj->f_arrow = false;
            l22 = (void*) _a7_obj;
            t0 = vader_c_emit_param_is_mutable(l2, l8);
            if (t0) {
                l23 = vader_c_emit_c_ast_cast(2556u, vader_ref_box(l22));
            } else {
                l23 = vader_ref_box(l22);
            }
            vader_array_push((vader_array_t*) l3, l23);
        } else {
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
            l24 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l8];
            t3 = vader_c_emit_mirrored_c_struct(l1, l24);
            if (t3 != 0u) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
                l25 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l8];
                l26 = vader_c_emit_mirrored_c_struct(l1, l25);
                vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
                l27 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8];
                t3 = vader_c_emit_bc_struct_name(l1, l27);
                l28 = vader_c_emit_struct_c_name(t3);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
                l29 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l8];
                l30 = vader_c_emit_bc_struct_fields(l1, l29);
                l31 = std_core_new_byte_buffer((size_t) 21);
                l32 = (size_t) 0;
                l32 = std_core_write_string_at(l31, l32, 2036u);
                t2 = ((int64_t) (size_t) l8);
                l33 = (uint64_t) (int64_t) t2;
                l32 = std_core_write_unsigned(l31, l32, l33);
                t3 = std_core_finish_buffer(l31, l32);
                l34 = vader_c_emit_c_ast_verbatim(t3);
                t3 = concat_2(l28, 264u);
                t1 = vader_c_emit_c_ast_cast(t3, l10);
                vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
                vader_obj_header_init(_a12_obj, 740u);
                _a12_obj->f_inner = t1;
                l35 = (void*) _a12_obj;
                l36 = std_core_new_byte_buffer((size_t) 21);
                l37 = (size_t) 0;
                l37 = std_core_write_string_at(l36, l37, 2036u);
                t2 = ((int64_t) (size_t) l8);
                l38 = (uint64_t) (int64_t) t2;
                l37 = std_core_write_unsigned(l36, l37, l38);
                l39 = std_core_finish_buffer(l36, l37);
                t1 = vader_c_emit_c_ast_number(INT64_C(0));
                vader_array_t* _a13_arr = vader_array_new(181u, 1u, 13u, 1359u);
                ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = t1.payload.obj;
                t4 = (void*) _a13_arr;
                l40 = vader_c_emit_c_ast_initializer_list(t4);
                l41 = vader_c_emit_c_ast_declaration(l26, l39, l40);
                vader_array_push((vader_array_t*) l4, l41);
                vader_c_emit_push_member_copies(l1, l30, l34, vader_ref_box(l35), true, l4, INT32_C(0));
                t0 = vader_c_emit_param_is_mutable(l2, l8);
                if (t0) {
                    l42 = vader_c_emit_c_ast_address_of(l10);
                    vader_array_push((vader_array_t*) l7, l42);
                    vader_c_emit_push_member_copies(l1, l30, l34, vader_ref_box(l35), false, l6, INT32_C(0));
                }
                l43 = vader_c_emit_c_ast_address_of(l34);
                vader_array_push((vader_array_t*) l3, l43);
            } else {
                t0 = vader_c_emit_is_param_by_address(l2, l8);
                if (t0) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
                    t1 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l8, 236u);
                    l44 = vader_c_emit_c_type_for_val_bare(((uint8_t) t1.payload.i));
                    l45 = std_core_new_byte_buffer((size_t) 21);
                    l46 = (size_t) 0;
                    l46 = std_core_write_string_at(l45, l46, 2036u);
                    t2 = ((int64_t) (size_t) l8);
                    l47 = (uint64_t) (int64_t) t2;
                    l46 = std_core_write_unsigned(l45, l46, l47);
                    l48 = std_core_finish_buffer(l45, l46);
                    l49 = vader_c_emit_c_ast_declaration(l44, l48, l10);
                    vader_array_push((vader_array_t*) l4, l49);
                    l50 = std_core_new_byte_buffer((size_t) 21);
                    l51 = (size_t) 0;
                    l51 = std_core_write_string_at(l50, l51, 2036u);
                    t2 = ((int64_t) (size_t) l8);
                    l52 = (uint64_t) (int64_t) t2;
                    l51 = std_core_write_unsigned(l50, l51, l52);
                    t3 = std_core_finish_buffer(l50, l51);
                    t1 = vader_c_emit_c_ast_verbatim(t3);
                    l53 = vader_c_emit_c_ast_address_of(t1);
                    l54 = vader_c_emit_c_ast_cast(2556u, l53);
                    vader_array_push((vader_array_t*) l3, l54);
                } else {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l8)
                    l55 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l8];
                    t0 = vader_c_emit_is_abi_nullable_pointer(l1, l55);
                    if (t0) {
                        vader_struct_vader_c_emit_c_ast_CMember_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
                        vader_obj_header_init(_a16_obj, 736u);
                        _a16_obj->f_base = l10;
                        _a16_obj->f_member = 2262u;
                        _a16_obj->f_arrow = false;
                        l56 = (void*) _a16_obj;
                        l57 = vader_c_emit_c_ast_verbatim(746u);
                        l58 = vader_c_emit_c_ast_binary((uint8_t) 11, vader_ref_box(l56), l57);
                        vader_struct_vader_c_emit_c_ast_CMember_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
                        vader_obj_header_init(_a17_obj, 736u);
                        _a17_obj->f_base = l10;
                        _a17_obj->f_member = 2046u;
                        _a17_obj->f_arrow = false;
                        t4 = (void*) _a17_obj;
                        vader_struct_vader_c_emit_c_ast_CMember_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
                        vader_obj_header_init(_a18_obj, 736u);
                        _a18_obj->f_base = vader_ref_box(t4);
                        _a18_obj->f_member = 1716u;
                        _a18_obj->f_arrow = false;
                        l59 = (void*) _a18_obj;
                        t4 = (void*) &vader_data_50;
                        vader_array_t* _a19_slotarr = ((vader_array_t*) t4);
                        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                        l60 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
                        l61 = vader_c_emit_c_ast_cast(1822u, vader_ref_box(l59));
                        l62 = vader_c_emit_c_ast_cast(2556u, l61);
                        vader_struct_vader_c_emit_c_ast_CConditional_t* _a20_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
                        vader_obj_header_init(_a20_obj, 715u);
                        _a20_obj->f_condition = l58;
                        _a20_obj->f_then_value = vader_ref_box(l60);
                        _a20_obj->f_else_value = l62;
                        l63 = (void*) _a20_obj;
                        l64 = std_core_new_byte_buffer((size_t) 21);
                        l65 = (size_t) 0;
                        l65 = std_core_write_string_at(l64, l65, 2036u);
                        t2 = ((int64_t) (size_t) l8);
                        l66 = (uint64_t) (int64_t) t2;
                        l65 = std_core_write_unsigned(l64, l65, l66);
                        l67 = std_core_finish_buffer(l64, l65);
                        l68 = vader_c_emit_c_ast_declaration(2556u, l67, vader_ref_box(l63));
                        vader_array_push((vader_array_t*) l4, l68);
                        l69 = std_core_new_byte_buffer((size_t) 21);
                        l70 = (size_t) 0;
                        l70 = std_core_write_string_at(l69, l70, 2036u);
                        t2 = ((int64_t) (size_t) l8);
                        l71 = (uint64_t) (int64_t) t2;
                        l70 = std_core_write_unsigned(l69, l70, l71);
                        t3 = std_core_finish_buffer(l69, l70);
                        l72 = vader_c_emit_c_ast_verbatim(t3);
                        vader_array_push((vader_array_t*) l3, l72);
                    } else {
                        vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params);
                        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l8)
                        t1 = vader_array_read_u8(_a21_slotarr, _a21_slotarr->offset + (size_t) l8, 236u);
                        if (((int32_t) t1.payload.i) == INT32_C(14)) {
                            l73 = std_core_new_byte_buffer((size_t) 21);
                            l74 = (size_t) 0;
                            l74 = std_core_write_string_at(l73, l74, 1365u);
                            t2 = ((int64_t) (size_t) l8);
                            l75 = (uint64_t) (int64_t) t2;
                            l74 = std_core_write_unsigned(l73, l74, l75);
                            l76 = std_core_finish_buffer(l73, l74);
                            vader_array_t* _a22_arr = vader_array_new(181u, 1u, 13u, 1359u);
                            ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l10.payload.obj;
                            l77 = (void*) _a22_arr;
                            l78 = vader_c_emit_c_ast_call(2528u, l77);
                            l79 = vader_c_emit_c_ast_declaration(1456u, l76, l78);
                            vader_array_push((vader_array_t*) l4, l79);
                            l80 = std_core_new_byte_buffer((size_t) 21);
                            l81 = (size_t) 0;
                            l81 = std_core_write_string_at(l80, l81, 1365u);
                            t2 = ((int64_t) (size_t) l8);
                            l82 = (uint64_t) (int64_t) t2;
                            l81 = std_core_write_unsigned(l80, l81, l82);
                            t3 = std_core_finish_buffer(l80, l81);
                            l83 = vader_c_emit_c_ast_verbatim(t3);
                            vader_array_t* _a23_arr = vader_array_new(181u, 2u, 13u, 1359u);
                            ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 1u] = l83.payload.obj;
                            ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = l10.payload.obj;
                            l84 = (void*) _a23_arr;
                            l85 = vader_c_emit_c_ast_perform(2477u, l84);
                            vader_array_push((vader_array_t*) l5, l85);
                            l86 = std_core_new_byte_buffer((size_t) 21);
                            l87 = (size_t) 0;
                            l87 = std_core_write_string_at(l86, l87, 1365u);
                            t2 = ((int64_t) (size_t) l8);
                            l88 = (uint64_t) (int64_t) t2;
                            l87 = std_core_write_unsigned(l86, l87, l88);
                            t3 = std_core_finish_buffer(l86, l87);
                            l89 = vader_c_emit_c_ast_verbatim(t3);
                            vader_array_push((vader_array_t*) l3, l89);
                        } else {
                            vader_array_push((vader_array_t*) l3, l10);
                        }
                    }
                }
            }
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a24_arr = vader_array_new(182u, 0u, 13u, 1363u);
    l12 = (void*) _a24_arr;
    t5 = ((vader_array_t*) l7)->length;
    if ((t5 > INT64_C(0))) {
        t5 = ((vader_array_t*) l7)->length;
        l10 = vader_c_emit_c_ast_number(((int64_t) (size_t) t5));
        l13 = vader_c_emit_c_ast_array_declaration(2557u, 822u, l7);
        vader_array_push((vader_array_t*) l4, l13);
        l13 = vader_c_emit_c_ast_verbatim(821u);
        l18 = vader_c_emit_c_ast_verbatim(822u);
        vader_array_t* _a25_arr = vader_array_new(181u, 3u, 13u, 1359u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 1u] = l18.payload.obj;
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = l13.payload.obj;
        l7 = (void*) _a25_arr;
        l10 = vader_c_emit_c_ast_perform(749u, l7);
        vader_array_push((vader_array_t*) l4, l10);
        vader_array_t* _a26_arr = vader_array_new(181u, 1u, 13u, 1359u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = l13.payload.obj;
        l7 = (void*) _a26_arr;
        l10 = vader_c_emit_c_ast_perform(748u, l7);
        vader_array_push((vader_array_t*) l12, l10);
    }
    vader_array_push_all((vader_array_t*) l12, (vader_array_t*) l6);
    t5 = ((vader_array_t*) l12)->length;
    if (t5 == INT64_C(0)) {
        t5 = ((vader_array_t*) l5)->length;
        l90 = t5 == INT64_C(0);
    } else {
        l90 = false;
    }
    t3 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    l10 = vader_c_emit_c_ast_call(t3, l3);
    l2 = vader_c_emit_forwarded_result(l2, l1, l10, l90);
    t0 = ((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_returns;
    if (t0) {
        l10 = ((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_capture;
        vader_array_push((vader_array_t*) l4, l10);
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_capture;
    vader_array_push((vader_array_t*) l4, l10);
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l12);
    if (!(((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_settle.tag == 0u)) {
        l10 = ((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_settle;
        vader_array_push((vader_array_t*) l4, l10);
    }
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l5);
    vader_array_t* _a27_arr = vader_array_new(54u, 0u, 13u, 706u);
    l3 = (void*) _a27_arr;
    l10 = ((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_returned;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a28_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a28_obj, 743u);
    _a28_obj->f_stores = l3;
    _a28_obj->f_value = l10;
    _a28_obj->f_snapshot_type = 0u;
    _a28_obj->f_pops_frame = false;
    l2 = (void*) _a28_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l2));
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_val_of(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 703u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackTemporary_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 700u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackLit_t*) t0)->f_val;
    } else if (l0.tag == 701u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_val;
    } else {
        if (!(l0.tag == 699u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackExpr_t*) t0)->f_val;
    }
    return l1;
}

static uint8_t vader_c_emit_val_type_of_bc_type(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 532u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val;
        return l1;
    }
    if (l0.tag == 536u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 523u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 526u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 537u) {
        l1 = (uint8_t) 19;
    } else {
        if (!(l0.tag == 533u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 19;
    }
    return l1;
}

static uint8_t vader_c_emit_val_type_of_field(void* l0, int32_t l1) {
    size_t l2;
    int64_t t0;
    vader_box_t t1;
    uint8_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t2 = vader_c_emit_val_type_of_bc_type(t1);
    return t2;
}

static void* vader_c_emit_value_parameters(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    size_t l3, l4, l7, l9;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    uint64_t l10;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &l12 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l6, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(60u, 0u, 13u, 739u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l3, 236u);
        l5 = vader_c_emit_c_type_for_val_bare(((uint8_t) t0.payload.i));
        l6 = l1;
        l7 = vader_host_std_core_byte_len(l6);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(20) + l7));
        l9 = (size_t) 0;
        l9 = std_core_write_string_at(l8, l9, l6);
        t1 = ((int64_t) (size_t) l3);
        l10 = (uint64_t) (int64_t) t1;
        l9 = std_core_write_unsigned(l8, l9, l10);
        l11 = std_core_finish_buffer(l8, l9);
        vader_struct_vader_c_emit_c_ast_CParameter_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
        vader_obj_header_init(_a3_obj, 739u);
        _a3_obj->f_type = l5;
        _a3_obj->f_name = l11;
        l12 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l12));
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_vtable_helper_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_split(l0, 295u);
    t1 = std_string_join(t0, 800u);
    l1 = vader_c_emit_sanitise(t1);
    t1 = concat_2(2538u, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_vtable_sig_for_row(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    size_t l3, l8, l11;
    uint8_t l4;
    int32_t l5;
    bool l6, l13;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    uint8_t t3;
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l7, &l9, &l10, &l12, &l14, &l15, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l1)->f_entries);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t0)->f_fn_index;
    t2 = ((int64_t) (int32_t) t1);
    l3 = (size_t) (int64_t) t2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_signature;
    l4 = vader_bytecode_bc_single_result(l2);
    l5 = vader_bytecode_bc_single_result_type(l2);
    l6 = true;
    l7 = ((vader_struct_vader_bytecode_VtableRow_t*) l1)->f_entries;
    l3 = ((vader_array_t*) l7)->length;
    l8 = (size_t) 0;
    while ((l8 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l10 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
        t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) l9)->f_fn_index;
        t2 = ((int64_t) (int32_t) t1);
        l11 = (size_t) (int64_t) t2;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
        t3 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_signature);
        if (t3 != l4) {
            l13 = true;
        } else {
            t1 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_signature);
            l13 = t1 != l5;
        }
        if (l13) {
            l6 = false;
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    if (!(l6)) {
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params;
        vader_array_t* _a4_arr = vader_array_new(13u, 1u, 1u, 236u);
        ((uint8_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (uint8_t) INT32_C(19);
        l9 = (void*) _a4_arr;
        l10 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types;
        vader_array_t* _a5_arr = vader_array_new(11u, 1u, 7u, 233u);
        ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) l5;
        l12 = (void*) _a5_arr;
        l14 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_names;
        vader_array_t* _a6_arr = vader_array_new(8u, 0u, 12u, 228u);
        l15 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(8u, 0u, 12u, 228u);
        l16 = (void*) _a7_arr;
        vader_struct_vader_bytecode_BcSignature_t* _a8_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
        vader_obj_header_init(_a8_obj, 534u);
        _a8_obj->f_params = l7;
        _a8_obj->f_results = l9;
        _a8_obj->f_param_types = l10;
        _a8_obj->f_result_types = l12;
        _a8_obj->f_param_names = l14;
        _a8_obj->f_param_mutable = l15;
        _a8_obj->f_param_by_address = l16;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_wrapper_storage(bool l0) {
    if (l0) {
        return (uint8_t) 1;
    }
    return (uint8_t) 0;
}

static void vader_c_emit_write_barrier(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 1u, 13u, 1359u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(756u, l2);
    vader_c_emit_evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}
