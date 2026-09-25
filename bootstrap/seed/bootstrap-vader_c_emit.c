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
static vader_box_t vader_c_emit_box_call(vader_string_t l0, int32_t l1, vader_box_t l2);
static vader_box_t vader_c_emit_box_expr(vader_box_t l0, uint8_t l1, int32_t l2);
static vader_box_t vader_c_emit_box_expr_unknown(void* l0, vader_box_t l1, uint8_t l2);
static vader_box_t vader_c_emit_box_slot(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static vader_box_t vader_c_emit_box_slot_1(vader_string_t l0, vader_box_t l1);
static vader_box_t vader_c_emit_boxed_object(int32_t l0, vader_box_t l1);
static void* vader_c_emit_boxed_parameters(void* l0, size_t l1);
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
static void* vader_c_emit_compute_may_alloc(void* l0);
static vader_box_t vader_c_emit_const_lit_c(void* l0, vader_box_t l1);
static uint8_t vader_c_emit_const_val(vader_box_t l0);
static uint8_t vader_c_emit_convert_target_val(uint8_t l0);
static void* vader_c_emit_crossing_mirrors(void* l0);
static void* vader_c_emit_current_block(void* l0);
static bool vader_c_emit_data_entry_mutable(vader_box_t l0);
static void* vader_c_emit_data_pool_type_ids(void* l0);
static vader_box_t vader_c_emit_data_slot(uint8_t l0, uint64_t l1);
static void vader_c_emit_declare(void* l0, vader_string_t l1, vader_string_t l2, vader_box_t l3);
static void vader_c_emit_directive(void* l0, vader_string_t l1);
static void* vader_c_emit_dispatcher_parameters(void* l0);
static vader_box_t vader_c_emit_dispatcher_result(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3);
static void* vader_c_emit_dispatcher_signature(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_c_emit_div_mod_helper(uint8_t l0, uint8_t l1);
static void vader_c_emit_drop_resolved_for_local(void* l0, int32_t l1);
static void vader_c_emit_drop_top(void* l0);
static uint8_t vader_c_emit_element_storage_kind(void* l0);
static void vader_c_emit_emit_agg_data_entry(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_c_emit_emit_array_clear(void* l0);
static void vader_c_emit_emit_array_copy(void* l0);
static void vader_c_emit_emit_array_get(void* l0, void* l1);
static void vader_c_emit_emit_array_len(void* l0, bool l1);
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
static void vader_c_emit_emit_box_op(void* l0, void* l1);
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
static void vader_c_emit_emit_return(void* l0);
static void vader_c_emit_emit_return_lit(void* l0, vader_box_t l1);
static void vader_c_emit_emit_size_of_type(void* l0);
static vader_string_t vader_c_emit_emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3);
static void vader_c_emit_emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6);
static void vader_c_emit_emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_c_emit_emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_c_emit_emit_str_data_entry(void* l0, void* l1, void* l2, void* l3);
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
static void* vader_c_emit_find_erased_siblings(void* l0, int32_t l1);
static int32_t vader_c_emit_find_main(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_find_vtable_row(void* l0, vader_string_t l1);
static vader_string_t vader_c_emit_float_lit(double l0);
static vader_box_t vader_c_emit_float_tag_check_expr(void* l0, vader_box_t l1);
static bool vader_c_emit_fn_builds_stack_object(void* l0);
static bool vader_c_emit_fn_calls_may_alloc(void* l0, void* l1);
static bool vader_c_emit_fn_has_direct_alloc(void* l0);
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
static void* vader_c_emit_include_of(vader_string_t l0);
static void* vader_c_emit_including(vader_string_t l0);
static vader_box_t vader_c_emit_info_row(size_t l0, void* l1);
static void vader_c_emit_init_object_header(void* l0, vader_string_t l1, int32_t l2);
static void* vader_c_emit_internal_fn_flags(void* l0, void* l1, vader_string_t l2);
static vader_box_t vader_c_emit_interned(vader_box_t l0);
static void vader_c_emit_invalidate_resolve_cache(void* l0, vader_box_t l1);
static bool vader_c_emit_is_abi_array(void* l0, int32_t l1);
static bool vader_c_emit_is_abi_nullable_pointer(void* l0, int32_t l1);
static bool vader_c_emit_is_abi_nullable_string(void* l0, int32_t l1);
static bool vader_c_emit_is_c_reserved(vader_string_t l0);
static bool vader_c_emit_is_cache_safe(vader_box_t l0);
static bool vader_c_emit_is_continue_branch(void* l0, int32_t l1);
static bool vader_c_emit_is_param_by_address(void* l0, size_t l1);
static bool vader_c_emit_is_pure_control_flow(vader_box_t l0);
static bool vader_c_emit_is_ref_val(uint8_t l0);
static bool vader_c_emit_is_scope_opening(vader_box_t l0);
static void vader_c_emit_keep_pinned_resolves(void* l0, vader_box_t l1);
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
static bool vader_c_emit_op_allocates(vader_box_t l0);
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
static bool vader_c_emit_pc_slot_written_in(void* l0, int32_t l1, int32_t l2, int32_t l3);
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
static vader_string_t vader_c_emit_resolve_array_local(void* l0, vader_box_t l1, bool l2);
static void vader_c_emit_return_statement(void* l0, void* l1);
static vader_string_t vader_c_emit_sanitise(vader_string_t l0);
static vader_box_t vader_c_emit_scalar_cast(vader_box_t l0, uint8_t l1, uint8_t l2);
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
static bool vader_c_emit_struct_all_ref(void* l0, void* l1);
static vader_string_t vader_c_emit_struct_c_name(vader_string_t l0);
static vader_box_t vader_c_emit_struct_check_expr(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3);
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
    l1 = vader_c_emit_c_ast_cast(2163u, l0);
    t0 = vader_c_emit_c_ast_cast(1930u, l1);
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
    l2 = std_core_write_string_at(l1, l2, 1012u);
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
    if (l3.tag == 480u) {
        t1 = l3.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
        return t2;
    }
    return l1;
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
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_array_pointer(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_cast(2235u, l0);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_array_tag(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 480u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
            if (t1 == l1) {
                return ((int32_t) (size_t) l3);
            }
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
}

static int32_t vader_c_emit_array_type_index_for_element(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t t0;
    void* t1;
    int32_t t2;
    int64_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (t0.tag == 480u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t1 = t0.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
            if (t2 == l1) {
                return ((int32_t) (size_t) l3);
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
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
    t0 = vader_c_emit_c_ast_cast(1930u, l1);
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
    if (t0 != INT64_C(0)) {
        l2 = l1;
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
        l4 = vader_host_std_core_byte_len(l2);
        l5 = vader_host_std_core_byte_len(l3);
        t1 = (l4 + l5);
        l4 = (size_t) (int64_t) t1;
        l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(159) + l4));
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l6, l4, 1210u);
        l4 = std_core_write_string_at(l6, l4, l2);
        l4 = std_core_write_string_at(l6, l4, 70u);
        l4 = std_core_write_string_at(l6, l4, l3);
        l4 = std_core_write_string_at(l6, l4, 776u);
        t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
        t1 = ((int64_t) (size_t) t0);
        l7 = (uint64_t) (int64_t) t1;
        l4 = std_core_write_unsigned(l6, l4, l7);
        l4 = std_core_write_string_at(l6, l4, 218u);
        t2 = std_core_finish_buffer(l6, l4);
        vader_host_std_abort_panic(t2);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_assign(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CAssign_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
    vader_obj_header_init(_a0_obj, 661u);
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
    vader_obj_header_init(_a0_obj, 674u);
    _a0_obj->f_name = 676u;
    _a0_obj->f_value = l1;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_atom_for(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(l0, l1);
    if (l2.tag == 193u) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
        t2 = t1.payload.s;
        if (t2 != 0u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
            l5 = t1.payload.s;
            vader_array_push((vader_array_t*) l2, vader_box_string(190u, l5));
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
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
    l3 = std_core_write_string_at(l4, l3, 753u);
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 716u);
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
        vader_array_t* _a0_arr = vader_array_new(37u, 0u, 13u, 482u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (l5.tag == 493u) {
        t1 = l5.payload.obj;
        { void* __vret = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(37u, 0u, 13u, 482u);
    t1 = (void*) _a2_arr;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l5.tag == 493u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        return t2;
    }
    return 0u;
}

static vader_box_t vader_c_emit_binary_expression(void* l0, uint8_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool l5;
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
        l5 = true;
    } else {
        l5 = l1 == INT32_C(12);
    }
    if (l5) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_inner = l3;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = concat_2(2243u, l0);
    l4 = std_core_new_byte_buffer((size_t) 21);
    l5 = (size_t) 0;
    l6 = ((int64_t) (int32_t) l1);
    l5 = std_core_write_int(l4, l5, l6);
    l5 = std_core_write_string_at(l4, l5, 2134u);
    t0 = std_core_finish_buffer(l4, l5);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l4 = (void*) _a0_arr;
    t1 = vader_c_emit_c_ast_call(l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_box_expr(vader_box_t l0, uint8_t l1, int32_t l2) {
    bool l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l6 };
    void** gc_raw_roots[2] = { &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(0)) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(1);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(2);
    }
    if (l3) {
        l4 = vader_c_emit_box_call(1537u, l2, l0);
    } else {
        if (l1 == INT32_C(5)) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(6);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(7);
        }
        if (l3) {
            vader_array_t* _a0_arr = vader_array_new(8u, 2u, 0u, 190u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(190u, 2160u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(190u, 1619u);
            t0 = (void*) _a0_arr;
            vader_struct_vader_c_emit_c_ast_CCast_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCast_t));
            vader_obj_header_init(_a1_obj, 667u);
            _a1_obj->f_types = t0;
            _a1_obj->f_value = l0;
            l5 = (void*) _a1_obj;
            l4 = vader_c_emit_box_call(1537u, l2, vader_ref_box(l5));
        } else if (l1 == INT32_C(3)) {
            l4 = vader_c_emit_box_call(1559u, l2, l0);
        } else if (l1 == INT32_C(4)) {
            l6 = vader_c_emit_c_ast_cast(1620u, l0);
            l4 = vader_c_emit_box_call(1559u, l2, l6);
        } else {
            if (l1 == INT32_C(8)) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(9);
            }
            if (l3) {
                vader_array_t* _a2_arr = vader_array_new(8u, 2u, 0u, 190u);
                vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 1u] = vader_box_string(190u, 2161u);
                vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(190u, 1620u);
                t0 = (void*) _a2_arr;
                vader_struct_vader_c_emit_c_ast_CCast_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCast_t));
                vader_obj_header_init(_a3_obj, 667u);
                _a3_obj->f_types = t0;
                _a3_obj->f_value = l0;
                l5 = (void*) _a3_obj;
                l4 = vader_c_emit_box_call(1559u, l2, vader_ref_box(l5));
            } else if (l1 == INT32_C(10)) {
                l6 = vader_c_emit_c_ast_cast(1340u, l0);
                l4 = vader_c_emit_box_call(1429u, l2, l6);
            } else if (l1 == INT32_C(11)) {
                l4 = vader_c_emit_box_call(1429u, l2, l0);
            } else if (l1 == INT32_C(12)) {
                l4 = vader_c_emit_box_call(1143u, l2, l0);
            } else if (l1 == INT32_C(13)) {
                l6 = vader_c_emit_c_ast_cast(1619u, l0);
                l4 = vader_c_emit_box_call(1537u, l2, l6);
            } else if (l1 == INT32_C(14)) {
                l4 = vader_c_emit_box_call(2010u, l2, l0);
            } else {
                if (l1 == INT32_C(15)) {
                    l3 = true;
                } else {
                    l3 = l1 == INT32_C(19);
                }
                if (l3) {
                    l4 = l0;
                } else if (l1 == INT32_C(16)) {
                    vader_array_t* _a4_arr = vader_array_new(145u, 0u, 13u, 1205u);
                    l5 = (void*) _a4_arr;
                    l4 = vader_c_emit_c_ast_call(2244u, l5);
                } else if (l1 == INT32_C(17)) {
                    l6 = vader_c_emit_c_ast_cast(1635u, l0);
                    l6 = vader_c_emit_c_ast_cast(1620u, l6);
                    l4 = vader_c_emit_box_call(1559u, l2, l6);
                } else if (l1 == INT32_C(18)) {
                    l4 = vader_c_emit_ref_box(l0);
                } else {
                    vader_unreachable("unreachable return in vader_c_emit$box_expr");
                }
            }
        }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_string_t l6 = 0;
    int32_t l7;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l8, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 497u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        l7 = vader_c_emit_atom_for(l5, l6);
        t1 = vader_c_emit_boxed_string(l4, l7);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l2;
    l8 = vader_c_emit_emit_data_value(l0, l1, l8, l3, l5);
    t1 = vader_c_emit_boxed_object(l4, l8);
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
    t0 = concat_2(l0, 249u);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    t1 = vader_c_emit_c_ast_call(2207u, l2);
    vader_struct_vader_c_emit_c_ast_CIndex_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
    vader_obj_header_init(_a1_obj, 686u);
    _a1_obj->f_base = t1;
    _a1_obj->f_index = l1;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_boxed_object(int32_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t0 };
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l0));
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_value = INT64_C(0);
    _a0_obj->f_unsigned_v = true;
    l3 = (void*) _a0_obj;
    l4 = vader_c_emit_c_ast_cast(2337u, l1);
    t0 = vader_c_emit_c_ast_designated(269u, l4);
    vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0.payload.obj;
    t1 = (void*) _a1_arr;
    l4 = vader_c_emit_c_ast_initializer_list(t1);
    vader_array_t* _a2_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
    t1 = (void*) _a2_arr;
    t0 = vader_c_emit_c_ast_initializer_list(t1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(54u, 1u, 13u, 694u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        l4 = std_core_new_byte_buffer((size_t) 21);
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l4, l5, 1012u);
        t0 = ((int64_t) (size_t) l3);
        l6 = (uint64_t) (int64_t) t0;
        l5 = std_core_write_unsigned(l4, l5, l6);
        l7 = std_core_finish_buffer(l4, l5);
        vader_struct_vader_c_emit_c_ast_CParameter_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
        vader_obj_header_init(_a1_obj, 694u);
        _a1_obj->f_type = 2247u;
        _a1_obj->f_name = l7;
        l8 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_boxed_string(int32_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l4, &t0 };
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l0));
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_value = INT64_C(0);
    _a0_obj->f_unsigned_v = true;
    l3 = (void*) _a0_obj;
    l4 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l1));
    t0 = vader_c_emit_c_ast_designated(272u, l4);
    vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0.payload.obj;
    t1 = (void*) _a1_arr;
    l4 = vader_c_emit_c_ast_initializer_list(t1);
    vader_array_t* _a2_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l3;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
    t1 = (void*) _a2_arr;
    t0 = vader_c_emit_c_ast_initializer_list(t1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_branch_target(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    bool t1;
    int64_t t2;
    int32_t t3;
    vader_box_t t4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_c_emit_is_continue_branch(t0, l1);
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            return vader_ref_box(t0);
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        t3 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_end_pc;
        if ((t3 + INT32_C(1)) == l1) {
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            return vader_ref_box(t0);
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    t4 = vader_box_obj(0u, NULL);
    return t4;
}

static vader_box_t vader_c_emit_buffer_pointer(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_object_pointer_of(l0);
    t0 = vader_c_emit_c_ast_cast(2260u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 343u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_strings;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_ids);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l7 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
        std_collections_MutableMap_IndexSet_set_at__string__i32(l1, l6, l7);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
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
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 196u);
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
                t1 = ((int32_t) (uint32_t) t0);
                l6 = (uint8_t) (int32_t) t1;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l6);
                t0 = std_numbers_hex_digit((uint64_t) (int64_t) (((int64_t) (uint8_t) l4) & INT64_C(15)));
                t1 = ((int32_t) (uint32_t) t0);
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
    void* l11 = NULL;
    void* l12 = NULL;
    void* l22 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null();
    int32_t l7, l9;
    bool l8;
    vader_string_t l10 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    vader_string_t l23 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    size_t t3;
    bool t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[9] = { &l6, &l13, &l14, &l15, &l17, &l18, &l19, &l21, &t5 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l11, &l12, &l22, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l16, &l20, &l23, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 9u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_nested_member_mirrors(l0);
    l4 = ((vader_array_t*) l0)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (!(l6.tag == 493u)) {
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        t1 = l6.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        if (t2 == 0u) {
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        t1 = l6.payload.obj;
        t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields)->length;
        if (t3 == INT64_C(0)) {
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        l7 = ((int32_t) (size_t) l5);
        t4 = std_collections_MutableSet_Contains_contains__i32(l3, l7);
        if (t4) {
            l9 = ((int32_t) (size_t) l5);
            t4 = std_collections_MutableSet_Contains_contains__i32(l1, l9);
            l8 = !(t4);
        } else {
            l8 = false;
        }
        if (l8) {
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        t1 = l6.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        l10 = vader_c_emit_struct_c_name(t2);
        t1 = l6.payload.obj;
        l11 = vader_bytecode_c_struct_layout(((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields, l0);
        t1 = l6.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        t5 = vader_c_emit_c_ast_verbatim(t2);
        vader_array_t* _a2_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t5.payload.obj;
        l12 = (void*) _a2_arr;
        l13 = vader_c_emit_c_ast_call(1931u, l12);
        t0 = ((vader_struct_vader_bytecode_CLayout_t*) l11)->f_size;
        l14 = vader_c_emit_c_ast_number(t0);
        l15 = vader_c_emit_c_ast_binary((uint8_t) 8, l14, l13);
        t1 = l6.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        l16 = concat_2(t2, 108u);
        l17 = vader_c_emit_static_assert(l15, l16);
        vader_array_push((vader_array_t*) l2, l17);
        l18 = vader_c_emit_c_ast_number(INT64_C(4096));
        l19 = vader_c_emit_c_ast_binary((uint8_t) 8, l13, l18);
        t1 = l6.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        l20 = concat_2(t2, 63u);
        l21 = vader_c_emit_static_assert(l19, l20);
        vader_array_push((vader_array_t*) l2, l21);
        t1 = l6.payload.obj;
        l22 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
        t1 = l6.payload.obj;
        l23 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        vader_c_emit_push_leaf_asserts(l0, l22, l23, 0u, l10, INT64_C(0), l2, INT32_C(0));
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
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
        l1 = 2162u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2159u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2160u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2161u;
    } else if (l0 == INT32_C(5)) {
        l1 = 1621u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1618u;
    } else if (l0 == INT32_C(7)) {
        l1 = 1619u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1620u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1479u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1340u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2160u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2162u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2337u;
    } else if (l0 == INT32_C(0)) {
        l1 = 2247u;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$c_type_for_array_kind");
    }
    return l1;
}

static vader_string_t vader_c_emit_c_type_for_val_bare(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1621u;
    } else if (l0 == INT32_C(1)) {
        l1 = 1618u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1619u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1620u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2162u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2159u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2160u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2161u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1930u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1863u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1479u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1340u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1143u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2160u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2310u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2247u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2336u;
    } else if (l0 == INT32_C(17)) {
        l1 = 2337u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2337u;
    } else if (l0 == INT32_C(19)) {
        l1 = 2247u;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$c_type_for_val_bare");
    }
    return l1;
}

static int32_t vader_c_emit_callee_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 516u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 545u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 544u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
        return t1;
    }
    return -(INT32_C(1));
}

static size_t vader_c_emit_callee_result_arity(void* l0, vader_box_t l1) {
    size_t l2, l3;
    void* l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    size_t t3;
    if (l1.tag == 516u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        t2 = ((int64_t) (int32_t) t1);
        l2 = (size_t) (int64_t) t2;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions)->length;
        if ((l2 >= l3)) {
            return (size_t) 1;
        }
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
    if (l1.tag == 517u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t2 = ((int64_t) (int32_t) t1);
        l2 = (size_t) (int64_t) t2;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports)->length;
        if ((l2 >= l3)) {
            return (size_t) 1;
        }
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
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
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
        l12 = concat_5(1822u, l3, 239u, l11, 206u);
        if (l10.tag == 489u) {
            t4 = l10.payload.obj;
            t5 = vader_bytecode_is_string_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t4)->f_val);
            if (t5) {
                vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_str_offsets, vader_box_string(190u, l12));
            }
        } else {
            t6 = vader_c_emit_val_type_of_bc_type(l10);
            if (t6 == INT32_C(18)) {
                vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_ref_offsets, vader_box_string(190u, l12));
            } else {
                vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_ptr_offsets, vader_box_string(190u, l12));
            }
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
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
    if (l4.tag == 684u) {
        t2 = l4.payload.obj;
        ((vader_struct_vader_c_emit_c_ast_CIf_t*) t2)->f_end_label = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_c_ast_CIf_t*) t2);
    } else {
        t2 = l4.payload.obj;
        ((vader_struct_vader_c_emit_c_ast_CScope_t*) t2)->f_end_label = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_c_ast_CScope_t*) t2);
    }
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
        if (l4) {
            t0 = vader_c_emit_payload(l1, 1818u);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(18)) {
        t1 = vader_c_emit_is_ref_val(l3);
        if (t1) {
            t0 = vader_c_emit_ref_box(l1);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l3);
    if (t1) {
        l4 = vader_c_emit_is_ref_val(l2);
    } else {
        l4 = false;
    }
    if (l4) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l3);
    if (t1) {
        t0 = vader_c_emit_box_expr_unknown(l0, l1, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l2);
    if (t1) {
        t0 = vader_c_emit_unbox_expr(l1, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_scalar_cast(l1, l2, l3);
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
    if (t0) {
        t1 = vader_c_emit_coerce_expr(l0, l1, l2, l3);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
        vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
        l2 = (void*) _a0_arr;
        l3 = INT32_C(1);
        l4 = ((vader_array_t*) l0)->length;
        l5 = (size_t) 0;
        {
            vader_array_t* _pc13_hdr = (vader_array_t*) l2;
            size_t _pc13_len = _pc13_hdr->length;
            size_t _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
            void* _pc13_slots = _pc13_hdr->buf->slots;
            for (;;) {
                if ((l5 < l4)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                    t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
                    t2 = t1.payload.s;
                    if (t2 == 0u) {
                        if (VADER_LIKELY(_pc13_len < _pc13_cap)) {
                            ((int32_t*) _pc13_slots)[_pc13_len] = (int32_t) (INT32_C(0));
                            _pc13_len += 1;
                        } else {
                            _pc13_hdr->length = _pc13_len;
                            if (_pc13_hdr->buf->length < _pc13_len) {
                                _pc13_hdr->buf->length = _pc13_len;
                            }
                            vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                            _pc13_hdr = (vader_array_t*) l2;
                            _pc13_len = _pc13_hdr->length;
                            _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
                            _pc13_slots = _pc13_hdr->buf->slots;
                        }
                    } else {
                        if (VADER_LIKELY(_pc13_len < _pc13_cap)) {
                            ((int32_t*) _pc13_slots)[_pc13_len] = (int32_t) (l3);
                            _pc13_len += 1;
                        } else {
                            _pc13_hdr->length = _pc13_len;
                            if (_pc13_hdr->buf->length < _pc13_len) {
                                _pc13_hdr->buf->length = _pc13_len;
                            }
                            vader_array_push_i32((vader_array_t*) l2, l3);
                            _pc13_hdr = (vader_array_t*) l2;
                            _pc13_len = _pc13_hdr->length;
                            _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
                            _pc13_slots = _pc13_hdr->buf->slots;
                        }
                        l3 = (l3 + INT32_C(1));
                    }
                    t3 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t3;
                    continue;
                }
                _pc13_hdr->length = _pc13_len;
                if (_pc13_hdr->buf->length < _pc13_len) {
                    _pc13_hdr->buf->length = _pc13_len;
                }
                break;
            }
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 193u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 343u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a5_obj;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l5];
        l8 = t1.payload.s;
        t1 = std_collections_MutableMap_Index_at__string__i32(l2, l8);
        if (t1.tag == 0u) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l5];
            l9 = t1.payload.s;
            l3 = (((int32_t) (size_t) l5) + INT32_C(1));
            std_collections_MutableMap_IndexSet_set_at__string__i32(l2, l9, l3);
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a8_arr;
    l4 = ((vader_array_t*) l0)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
        t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
        t2 = t1.payload.s;
        if (t2 == 0u) {
            vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        } else {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
            t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l5];
            l8 = t1.payload.s;
            l10 = std_collections_MutableMap_Index_at__string__i32(l2, l8);
            if (l10.tag == 0u) {
                l3 = INT32_C(0);
            } else {
                l3 = ((int32_t) l10.payload.i);
            }
            vader_array_push_i32((vader_array_t*) l6, l3);
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_compute_may_alloc(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    int32_t l4, l6;
    bool l5;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    {
        vader_array_t* _pc8_hdr = (vader_array_t*) l1;
        size_t _pc8_len = _pc8_hdr->length;
        size_t _pc8_cap = (_pc8_hdr->offset == 0 && !vader_array_is_borrowed(_pc8_hdr) && _pc8_hdr->length >= _pc8_hdr->buf->length) ? _pc8_hdr->capacity : (size_t) 0;
        void* _pc8_slots = _pc8_hdr->buf->slots;
        for (;;) {
            if ((l3 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                t1 = vader_c_emit_fn_has_direct_alloc(t0);
                if (t1) {
                    l4 = ((int32_t) (size_t) l3);
                    if (VADER_LIKELY(_pc8_len < _pc8_cap)) {
                        ((int32_t*) _pc8_slots)[_pc8_len] = (int32_t) (l4);
                        _pc8_len += 1;
                    } else {
                        _pc8_hdr->length = _pc8_len;
                        if (_pc8_hdr->buf->length < _pc8_len) {
                            _pc8_hdr->buf->length = _pc8_len;
                        }
                        vader_array_push_i32((vader_array_t*) l1, l4);
                        _pc8_hdr = (vader_array_t*) l1;
                        _pc8_len = _pc8_hdr->length;
                        _pc8_cap = (_pc8_hdr->offset == 0 && !vader_array_is_borrowed(_pc8_hdr) && _pc8_hdr->length >= _pc8_hdr->buf->length) ? _pc8_hdr->capacity : (size_t) 0;
                        _pc8_slots = _pc8_hdr->buf->slots;
                    }
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                continue;
            }
            _pc8_hdr->length = _pc8_len;
            if (_pc8_hdr->buf->length < _pc8_len) {
                _pc8_hdr->buf->length = _pc8_len;
            }
            break;
        }
    }
    l5 = true;
    while (l5) {
        l5 = false;
        l2 = ((vader_array_t*) l0)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            l4 = ((int32_t) (size_t) l3);
            t1 = std_core____Contains_contains__i32(l1, l4);
            if (t1) {
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t1 = vader_c_emit_fn_calls_may_alloc(t0, l1);
            if (t1) {
                l6 = ((int32_t) (size_t) l3);
                vader_array_push_i32((vader_array_t*) l1, l6);
                l5 = true;
            }
            t2 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t2;
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l1.tag == 551u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        l3 = ((int64_t) (int32_t) t1);
        vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t));
        vader_obj_header_init(_a0_obj, 688u);
        _a0_obj->f_class = (uint8_t) 2;
        _a0_obj->f_value = l3;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l1.tag == 571u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t));
        vader_obj_header_init(_a1_obj, 688u);
        _a1_obj->f_class = (uint8_t) 3;
        _a1_obj->f_value = l3;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l1.tag == 532u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        t3 = vader_c_emit_float_lit(t2);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else if (l1.tag == 503u) {
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        if (t4) {
            l4 = 2098u;
        } else {
            l4 = 1445u;
        }
        l2 = vader_c_emit_c_ast_verbatim(l4);
    } else if (l1.tag == 519u) {
        l5 = std_core_new_byte_buffer((size_t) 21);
        l6 = (size_t) 0;
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        t6 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        l7 = (uint64_t) (int64_t) t6;
        l6 = std_core_write_unsigned(l5, l6, l7);
        l6 = std_core_write_string_at(l5, l6, 2134u);
        t3 = std_core_finish_buffer(l5, l6);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else if (l1.tag == 602u) {
        l5 = std_core_new_byte_buffer((size_t) 42);
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l5, l6, 2246u);
        t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_null_tag;
        l3 = ((int64_t) (int32_t) t1);
        l6 = std_core_write_int(l5, l6, l3);
        l6 = std_core_write_string_at(l5, l6, 2137u);
        t3 = std_core_finish_buffer(l5, l6);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else if (l1.tag == 617u) {
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
        l6 = std_core_write_string_at(l5, l6, 2134u);
        t3 = std_core_finish_buffer(l5, l6);
        l2 = vader_c_emit_c_ast_verbatim(t3);
    } else {
        vader_unreachable("unreachable return in vader_c_emit$const_lit_c");
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_const_val(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 551u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 571u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 532u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 503u) {
        l1 = (uint8_t) 12;
    } else if (l0.tag == 519u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 602u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 617u) {
        l1 = (uint8_t) 14;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$const_val");
    }
    return l1;
}

static uint8_t vader_c_emit_convert_target_val(uint8_t l0) {
    uint8_t l1;
    if (l0 == INT32_C(0)) {
        l1 = (uint8_t) 2;
    } else if (l0 == INT32_C(1)) {
        l1 = (uint8_t) 3;
    } else if (l0 == INT32_C(2)) {
        l1 = (uint8_t) 11;
    } else if (l0 == INT32_C(3)) {
        l1 = (uint8_t) 13;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$convert_target_val");
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
    int64_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 362u);
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
        if (!(t1)) {
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            continue;
        }
        l6 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_signature)->f_param_types;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
            l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
            t3 = vader_c_emit_mirrored_c_struct(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types, l9);
            if (t3 != 0u) {
                std_collections_add__i32(l1, l9);
            }
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
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
    if (l3.tag == 684u) {
        t2 = l3.payload.obj;
        l4 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t2)->f_else_block;
        if (l4.tag == 0u) {
            t2 = l3.payload.obj;
            l1 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t2)->f_then_block;
        } else {
            l1 = l4.payload.obj;
        }
        return l1;
    }
    t2 = l3.payload.obj;
    return ((vader_struct_vader_c_emit_c_ast_CScope_t*) t2)->f_body;
}

static bool vader_c_emit_data_entry_mutable(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 488u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_mutable;
    } else if (l0.tag == 492u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcStrData_t*) t0)->f_mutable;
    } else if (l0.tag == 479u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_mutable;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$data_entry_mutable");
    }
    return l1;
}

static void* vader_c_emit_data_pool_type_ids(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l2, l4, l6, l7, l10, l11, l12;
    vader_box_t l8 = vader_box_null();
    bool l9;
    int32_t l13;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 193u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (l8.tag == 521u) {
                t0 = l8.payload.obj;
                t1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                if ((t1 >= INT32_C(0))) {
                    t0 = l8.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                    t2 = ((int64_t) (int32_t) t1);
                    l10 = (size_t) (int64_t) t2;
                    l11 = ((vader_array_t*) l1)->length;
                    l9 = (l10 < l11);
                } else {
                    l9 = false;
                }
                if (l9) {
                    t0 = l8.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                    t2 = ((int64_t) (int32_t) t1);
                    l12 = (size_t) (int64_t) t2;
                    t0 = l8.payload.obj;
                    l13 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12] = (int32_t) l13;
                }
            }
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_data_slot(uint8_t l0, uint64_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    size_t l5;
    double t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    float t3;
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_type_for_array_kind(l0);
    if (l0 == INT32_C(10)) {
        t0 = std_core_u64_BitsFloat_from_bits_vt(l1);
        t1 = vader_c_emit_float_lit(t0);
        l3 = vader_c_emit_c_ast_verbatim(t1);
        t2 = vader_c_emit_c_ast_cast(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        t3 = std_core_u32_Bits32Float_from_bits_vt((uint32_t) (int32_t) ((int32_t) (uint64_t) l1));
        t1 = vader_c_emit_float_lit(((double) (float) t3));
        l3 = vader_c_emit_c_ast_verbatim(t1);
        t2 = vader_c_emit_c_ast_cast(l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_core_new_byte_buffer((size_t) 20);
    l5 = (size_t) 0;
    l5 = std_core_write_unsigned(l4, l5, l1);
    t1 = std_core_finish_buffer(l4, l5);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t2.payload.obj;
    l4 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(667u, l4);
    t2 = vader_c_emit_c_ast_cast(l2, l3);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 676u);
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
    vader_obj_header_init(_a0_obj, 694u);
    _a0_obj->f_type = 2247u;
    _a0_obj->f_name = 1878u;
    l1 = (void*) _a0_obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_params)->length;
    t1 = (t0 - INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    t2 = vader_c_emit_boxed_parameters(l1, l2);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_dispatcher_result(void* l0, vader_box_t l1, uint8_t l2, uint8_t l3) {
    bool l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l5 };
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
        l5 = vader_c_emit_coerce_expr(l0, l1, l2, (uint8_t) 19);
    } else {
        l5 = l1;
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 702u);
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
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t0 };
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
            l4 = 1335u;
        } else {
            l4 = 1775u;
        }
        l5 = vader_bytecode_val_type_name(l1);
        t0 = concat_4(2206u, l4, 716u, l5);
        l3 = vader_box_string(190u, t0);
    } else {
        l3 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_drop_resolved_for_local(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(46u, 0u, 13u, 651u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_ResolvedArray_t*) l6)->f_pointer, l1);
        if (!(t0)) {
            vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays = l2;
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
    if (l1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    t0 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l1);
    l2 = (void*) _a0_arr;
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
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
    if (t1.tag == 496u) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        t2 = t1.payload.obj;
        return ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_kind;
    }
    return (uint8_t) 0;
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l3)->f_elements)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l3)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_c_emit_PoolArray_t*) l2)->f_name;
        l10 = vader_host_std_core_byte_len(l9);
        l11 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l10));
        l12 = (size_t) 0;
        l12 = std_core_write_string_at(l11, l12, l9);
        l12 = std_core_write_string_at(l11, l12, 758u);
        t0 = ((int64_t) (size_t) l7);
        l13 = (uint64_t) (int64_t) t0;
        l12 = std_core_write_unsigned(l11, l12, l13);
        l14 = std_core_finish_buffer(l11, l12);
        l15 = ((vader_struct_vader_c_emit_PoolArray_t*) l2)->f_element_tag;
        l16 = vader_c_emit_box_slot(l0, l1, l8, l14, l15, l4);
        vader_array_push((vader_array_t*) l5, l16);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    vader_c_emit_push_pool_array(l1, l2, 2247u, (uint8_t) 0, l5);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2210u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 5u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2211u, l6);
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
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l7, &l9, &l14, &l16 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l13, &t1 };
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
        l10 = vader_c_emit_ref_carrying_element(l7, l4);
    } else {
        l10 = false;
    }
    if (l10) {
        l12 = vader_c_emit_val_type_of_bc_type(l7);
        if (l12 == INT32_C(18)) {
            l13 = 2228u;
        } else {
            l13 = 2227u;
        }
        t1 = concat_2(l11, 249u);
        l3 = vader_c_emit_c_ast_verbatim(t1);
        l7 = vader_c_emit_slot_index(l11, l2);
        vader_array_t* _a1_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l7.payload.obj;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
        l4 = (void*) _a1_arr;
        l3 = vader_c_emit_c_ast_call(l13, l4);
        vader_c_emit_push_into_temporary(l0, l3, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l9.tag == 0u) {
        l7 = vader_c_emit_slot_index(l11, l2);
        l3 = vader_c_emit_box_slot_1(l11, l7);
    } else if (l8 == INT32_C(1)) {
        l7 = vader_c_emit_c_ast_verbatim(l11);
        l14 = vader_c_emit_slot_index(l11, l2);
        l4 = std_core_new_byte_buffer((size_t) 21);
        l6 = (size_t) 0;
        l15 = ((int64_t) (int32_t) l5);
        l6 = std_core_write_int(l4, l6, l15);
        l6 = std_core_write_string_at(l4, l6, 2134u);
        t1 = std_core_finish_buffer(l4, l6);
        l16 = vader_c_emit_c_ast_verbatim(t1);
        vader_array_t* _a2_arr = vader_array_new(145u, 3u, 13u, 1205u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l16.payload.obj;
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l14.payload.obj;
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l7.payload.obj;
        l4 = (void*) _a2_arr;
        l3 = vader_c_emit_c_ast_call(2226u, l4);
    } else {
        t2 = l9.payload.obj;
        l13 = ((vader_struct_vader_c_emit_SlotFill_t*) t2)->f_cty;
        l2 = vader_c_emit_slot_index(l11, l2);
        l2 = vader_c_emit_typed_slot(l13, l11, l2);
        t2 = l9.payload.obj;
        l8 = ((vader_struct_vader_c_emit_SlotFill_t*) t2)->f_val;
        l3 = vader_c_emit_box_expr(l2, l8, l5);
    }
    vader_c_emit_push_into_temporary(l0, l3, (uint8_t) 19);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_len(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    if (l1) {
        l3 = vader_c_emit_array_header_pointer(l2);
        vader_c_emit_resolve_array_local(l0, l3, true);
    }
    t0 = vader_c_emit_array_header_pointer(l2);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 691u);
    _a0_obj->f_base = t0;
    _a0_obj->f_member = 1698u;
    _a0_obj->f_arrow = true;
    l4 = (void*) _a0_obj;
    vader_c_emit_push_into_temporary(l0, vader_ref_box(l4), (uint8_t) 9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_new(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3, l6, l7, l14;
    size_t l4;
    uint8_t l5, l17, l26;
    vader_string_t l8 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    int64_t l9;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[14] = {
        &l10, &l11, &l12, &l13, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &l25, &l27, &t1,
    };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l15, &l16, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 14u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
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
    l8 = vader_c_emit_aux(l0, 1067u);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    t2 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_type_id;
    l9 = ((int64_t) (int32_t) t2);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2134u);
    t3 = std_core_finish_buffer(l2, l4);
    l10 = vader_c_emit_c_ast_verbatim(t3);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l9 = ((int64_t) (int32_t) l7);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2134u);
    t3 = std_core_finish_buffer(l2, l4);
    l11 = vader_c_emit_c_ast_verbatim(t3);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l9 = ((int64_t) (int32_t) l6);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2134u);
    t3 = std_core_finish_buffer(l2, l4);
    l12 = vader_c_emit_c_ast_verbatim(t3);
    l2 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l9 = ((int64_t) (int32_t) l3);
    l4 = std_core_write_int(l2, l4, l9);
    l4 = std_core_write_string_at(l2, l4, 2134u);
    t3 = std_core_finish_buffer(l2, l4);
    l13 = vader_c_emit_c_ast_verbatim(t3);
    vader_array_t* _a1_arr = vader_array_new(145u, 4u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 3u] = l13.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l12.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l11.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l10.payload.obj;
    l2 = (void*) _a1_arr;
    l10 = vader_c_emit_c_ast_call(2213u, l2);
    vader_c_emit_declare(l0, 2235u, l8, l10);
    l10 = vader_c_emit_typed_array_fill_for(l5);
    l6 = INT32_C(0);
    while ((l6 < l7)) {
        l11 = vader_c_emit_pop(l0);
        l14 = ((l7 - INT32_C(1)) - l6);
        if (!(l10.tag == 0u)) {
            t4 = l10.payload.obj;
            l15 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_cty;
            l12 = vader_c_emit_fresh_slot(l8, l14);
            l13 = vader_c_emit_typed_slot(l15, l8, l12);
            t4 = l10.payload.obj;
            l16 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_cty;
            t4 = l10.payload.obj;
            l17 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_val;
            l18 = vader_c_emit_coerced_as(l0, l11, l17);
            l19 = vader_c_emit_c_ast_cast(l16, l18);
            vader_c_emit_assign(l0, l13, l19);
        } else if (l5 == INT32_C(13)) {
            l20 = vader_c_emit_fresh_slot(l8, l14);
            l21 = vader_c_emit_typed_slot(2337u, l8, l20);
            l22 = vader_c_emit_coerced_as(l0, l11, (uint8_t) 18);
            vader_c_emit_assign(l0, l21, l22);
        } else {
            l23 = vader_c_emit_fresh_slot(l8, l14);
            l24 = vader_c_emit_box_slot_1(l8, l23);
            l25 = vader_c_emit_expression_of(l11);
            l26 = vader_c_emit_val_of(l11);
            l27 = vader_c_emit_box_expr(l25, l26, l3);
            vader_c_emit_assign(l0, l24, l27);
        }
        l6 = (l6 + INT32_C(1));
    }
    l10 = vader_c_emit_c_ast_verbatim(l8);
    vader_c_emit_push_object(l0, l10);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l9 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    void* l4 = NULL;
    size_t l6;
    uint8_t l7, l11;
    int32_t l8;
    bool l10;
    vader_string_t l14 = 0;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    void* t4 = NULL;
    vader_box_t* gc_roots[7] = { &l2, &l3, &l5, &l9, &l12, &l13, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &t3, &t4 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
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
        l10 = vader_c_emit_pc_operand_is_slot(l3, l8);
    } else {
        l10 = false;
    }
    if (l10) {
        t3 = l9.payload.obj;
        t4 = vader_c_emit_pc_fill_of(((vader_struct_vader_c_emit_PushCache_t*) t3)->f_kind);
        l11 = ((vader_struct_vader_c_emit_SlotFill_t*) t4)->f_val;
        l4 = l9.payload.obj;
        l3 = vader_c_emit_coerced_as(l0, l2, l11);
        vader_c_emit_pc_emit_push(l0, l4, l5, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_c_emit_push_helper_for(l7);
    l9 = vader_c_emit_typed_array_fill_for(l7);
    if (l3.tag == 0u) {
        l10 = true;
    } else {
        l10 = l9.tag == 0u;
    }
    if (l10) {
        l12 = vader_c_emit_array_pointer(l5);
        l13 = vader_c_emit_expression_of(l2);
        l7 = vader_c_emit_val_of(l2);
        l8 = ((vader_struct_vader_bytecode_ArrayPush_t*) l1)->f_type_id;
        l13 = vader_c_emit_box_expr(l13, l7, l8);
        vader_array_t* _a1_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l13.payload.obj;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l12.payload.obj;
        l4 = (void*) _a1_arr;
        l12 = vader_c_emit_c_ast_call(2215u, l4);
        vader_c_emit_evaluate(l0, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l14 = l3.payload.s;
    l3 = vader_c_emit_array_pointer(l5);
    t3 = l9.payload.obj;
    l7 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_val;
    l2 = vader_c_emit_coerced_as(l0, l2, l7);
    vader_array_t* _a2_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a2_arr;
    l2 = vader_c_emit_c_ast_call(l14, l4);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2216u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2231u, l1);
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
    l3 = vader_c_emit_aux(l0, 1067u);
    t0 = vader_c_emit_object_pointer_of(l2);
    l2 = vader_c_emit_array_pointer(t0);
    l1 = vader_c_emit_as_size(l1);
    vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2232u, l4);
    vader_c_emit_declare(l0, 2235u, l3, l1);
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
    vader_string_t l14 = 0;
    uint8_t l13;
    int64_t t0;
    uint8_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l4, &l8, &l9, &l12 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l14, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = ((vader_struct_vader_bytecode_ArraySet_t*) l1)->f_type_id;
    l6 = vader_c_emit_array_element_tag(l5, l6);
    t0 = ((int64_t) (int32_t) l6);
    l7 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    t1 = vader_bytecode_array_kind_of(l8, l5);
    l9 = vader_c_emit_typed_array_fill_for(t1);
    l10 = ((vader_struct_vader_bytecode_ArraySet_t*) l1)->f_bounds_safe;
    l11 = vader_c_emit_emit_slot_array_local(l0, l4, l3, l10);
    if (l9.tag == 0u) {
        l10 = vader_c_emit_ref_carrying_element(l8, l5);
    } else {
        l10 = false;
    }
    if (l10) {
        if (l8.tag == 490u) {
            t2 = concat_2(l11, 249u);
            l4 = vader_c_emit_c_ast_verbatim(t2);
            l8 = vader_c_emit_slot_index(l11, l3);
            l12 = vader_c_emit_coerced_as(l0, l2, (uint8_t) 19);
            vader_array_t* _a1_arr = vader_array_new(145u, 3u, 13u, 1205u);
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l12.payload.obj;
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l8.payload.obj;
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
            l5 = (void*) _a1_arr;
            l4 = vader_c_emit_c_ast_call(2230u, l5);
            vader_c_emit_evaluate(l0, l4);
        } else {
            t2 = concat_2(l11, 249u);
            l4 = vader_c_emit_c_ast_verbatim(t2);
            l8 = vader_c_emit_slot_index(l11, l3);
            l12 = vader_c_emit_object_pointer_of(l2);
            vader_array_t* _a2_arr = vader_array_new(145u, 3u, 13u, 1205u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 2u] = l12.payload.obj;
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l8.payload.obj;
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l4.payload.obj;
            l5 = (void*) _a2_arr;
            l4 = vader_c_emit_c_ast_call(2229u, l5);
            vader_c_emit_evaluate(l0, l4);
        }
        t2 = concat_2(l11, 249u);
        l4 = vader_c_emit_c_ast_verbatim(t2);
        vader_c_emit_write_barrier(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l9.tag == 0u) {
        l4 = vader_c_emit_slot_index(l11, l3);
        l4 = vader_c_emit_box_slot_1(l11, l4);
        l8 = vader_c_emit_expression_of(l2);
        l13 = vader_c_emit_val_of(l2);
        l8 = vader_c_emit_box_expr(l8, l13, l6);
        vader_c_emit_assign(l0, l4, l8);
        t2 = concat_2(l11, 249u);
        l4 = vader_c_emit_c_ast_verbatim(t2);
        vader_c_emit_write_barrier(l0, l4);
    } else {
        t3 = l9.payload.obj;
        l14 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_cty;
        t3 = l9.payload.obj;
        l13 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_val;
        vader_c_emit_emit_typed_slot_write(l0, l11, l3, l2, l14, l13);
    }
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
    l5 = vader_c_emit_aux(l0, 1067u);
    t0 = vader_c_emit_object_pointer_of(l4);
    l4 = vader_c_emit_array_pointer(t0);
    l3 = vader_c_emit_as_size(l3);
    l2 = vader_c_emit_as_size(l2);
    vader_array_t* _a0_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l6 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2233u, l6);
    vader_c_emit_declare(l0, 2235u, l5, l2);
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
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null();
    uint8_t l9;
    int64_t l11, l15, l23;
    size_t l12, l13;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    size_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    int64_t t5;
    vader_box_t* gc_roots[7] = { &l8, &l10, &l18, &l19, &l21, &l22, &t3 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l17, &l20, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l14, &l16, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(190u, 409u);
    l2 = (void*) _a0_arr;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    if (t0 == INT64_C(0)) {
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a1_obj, 692u);
        _a1_obj->f_value = INT64_C(0);
        _a1_obj->f_unsigned_v = true;
        l3 = (void*) _a1_obj;
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a2_obj, 692u);
        _a2_obj->f_value = INT64_C(0);
        _a2_obj->f_unsigned_v = true;
        l4 = (void*) _a2_obj;
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a3_obj, 692u);
        _a3_obj->f_value = INT64_C(0);
        _a3_obj->f_unsigned_v = true;
        l5 = (void*) _a3_obj;
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a4_obj, 692u);
        _a4_obj->f_value = INT64_C(0);
        _a4_obj->f_unsigned_v = true;
        l6 = (void*) _a4_obj;
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a5_obj, 692u);
        _a5_obj->f_value = INT64_C(0);
        _a5_obj->f_unsigned_v = true;
        l7 = (void*) _a5_obj;
        l8 = vader_c_emit_c_ast_verbatim(148u);
        vader_array_t* _a6_arr = vader_array_new(145u, 6u, 13u, 1205u);
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
        l10 = vader_box_i32(193u, INT32_C(1));
        vader_array_t* _a7_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l8.payload.obj;
        t1 = (void*) _a7_arr;
        l8 = vader_c_emit_c_ast_initializer_list(t1);
        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
        vader_obj_header_init(_a8_obj, 673u);
        _a8_obj->f_name = 2237u;
        _a8_obj->f_length = l10;
        _a8_obj->f_value = l8;
        l3 = (void*) _a8_obj;
        vader_struct_vader_c_emit_c_ast_CGlobal_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
        vader_obj_header_init(_a9_obj, 682u);
        _a9_obj->f_storage = l9;
        _a9_obj->f_constant = true;
        _a9_obj->f_type = 2238u;
        _a9_obj->f_declarator = l3;
        l3 = (void*) _a9_obj;
        l8 = vader_c_emit_atom_count_define(l0);
        vader_array_t* _a10_arr = vader_array_new(147u, 2u, 13u, 1214u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_struct_vader_c_emit_c_ast_CSection_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
        vader_obj_header_init(_a11_obj, 700u);
        _a11_obj->f_comment = l2;
        _a11_obj->f_items = l3;
        l3 = (void*) _a11_obj;
        vader_c_emit_c_ast_print_section(l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l9 = vader_c_emit_global_storage(t2);
    vader_array_t* _a12_arr = vader_array_new(8u, 0u, 0u, 190u);
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l4 = (void*) _a13_arr;
    l11 = INT64_C(0);
    l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table;
    l12 = ((vader_array_t*) l5)->length;
    l13 = (size_t) 0;
    while ((l13 < l12)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l13)
        t3 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l13];
        l14 = t3.payload.s;
        t0 = vader_host_std_core_byte_len(l14);
        l15 = ((int64_t) (size_t) t0);
        t4 = vader_c_emit_c_string_lit(l14);
        l16 = concat_2(t4, 19u);
        vader_array_push((vader_array_t*) l3, vader_box_string(190u, l16));
        l8 = vader_c_emit_c_ast_verbatim(2236u);
        l10 = vader_c_emit_c_ast_number(l11);
        vader_struct_vader_c_emit_c_ast_CIndex_t* _a15_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
        vader_obj_header_init(_a15_obj, 686u);
        _a15_obj->f_base = l8;
        _a15_obj->f_index = l10;
        l6 = (void*) _a15_obj;
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a16_obj, 692u);
        _a16_obj->f_value = INT64_C(0);
        _a16_obj->f_unsigned_v = true;
        l7 = (void*) _a16_obj;
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a17_obj, 692u);
        _a17_obj->f_value = INT64_C(0);
        _a17_obj->f_unsigned_v = true;
        l17 = (void*) _a17_obj;
        l18 = vader_c_emit_c_ast_unsigned(l15);
        l19 = vader_c_emit_c_ast_verbatim(674u);
        vader_struct_vader_c_emit_c_ast_CNumber_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
        vader_obj_header_init(_a18_obj, 692u);
        _a18_obj->f_value = INT64_C(0);
        _a18_obj->f_unsigned_v = true;
        l20 = (void*) _a18_obj;
        l21 = vader_c_emit_c_ast_address_of(vader_ref_box(l6));
        vader_array_t* _a19_arr = vader_array_new(145u, 6u, 13u, 1205u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 5u] = l21.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 4u] = l20;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 3u] = l19.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 2u] = l18.payload.obj;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 1u] = l17;
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = l7;
        t1 = (void*) _a19_arr;
        l22 = vader_c_emit_c_ast_initializer_list(t1);
        vader_array_push((vader_array_t*) l4, l22);
        l23 = (l15 + INT64_C(1));
        l11 = (l11 + l23);
        t5 = (l13 + INT64_C(1));
        l13 = (size_t) (int64_t) t5;
    }
    vader_struct_vader_c_emit_c_ast_CUnsized_t* _a20_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
    vader_obj_header_init(_a20_obj, 710u);
    l5 = (void*) _a20_obj;
    vader_struct_vader_c_emit_c_ast_CStringLiterals_t* _a21_obj = (vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStringLiterals_t));
    vader_obj_header_init(_a21_obj, 704u);
    _a21_obj->f_literals = l3;
    l3 = (void*) _a21_obj;
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a22_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a22_obj, 673u);
    _a22_obj->f_name = 2236u;
    _a22_obj->f_length = vader_ref_box(l5);
    _a22_obj->f_value = vader_ref_box(l3);
    l3 = (void*) _a22_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a23_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a23_obj, 682u);
    _a23_obj->f_storage = l9;
    _a23_obj->f_constant = true;
    _a23_obj->f_type = 1254u;
    _a23_obj->f_declarator = l3;
    l3 = (void*) _a23_obj;
    vader_struct_vader_c_emit_c_ast_CUnsized_t* _a24_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
    vader_obj_header_init(_a24_obj, 710u);
    l5 = (void*) _a24_obj;
    l8 = vader_c_emit_c_ast_initializer_list(l4);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a25_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a25_obj, 673u);
    _a25_obj->f_name = 2237u;
    _a25_obj->f_length = vader_ref_box(l5);
    _a25_obj->f_value = l8;
    l4 = (void*) _a25_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a26_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a26_obj, 682u);
    _a26_obj->f_storage = l9;
    _a26_obj->f_constant = true;
    _a26_obj->f_type = 2238u;
    _a26_obj->f_declarator = l4;
    l4 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(147u, 1u, 13u, 1214u);
    ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = l3;
    l3 = (void*) _a27_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a28_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a28_obj, 700u);
    _a28_obj->f_comment = l2;
    _a28_obj->f_items = l3;
    l2 = (void*) _a28_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a29_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(147u, 1u, 13u, 1214u);
    ((void**) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = l4;
    l3 = (void*) _a30_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a31_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a31_obj, 700u);
    _a31_obj->f_comment = l2;
    _a31_obj->f_items = l3;
    l2 = (void*) _a31_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a32_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a32_arr;
    t3 = vader_c_emit_atom_count_define(l0);
    vader_array_t* _a33_arr = vader_array_new(147u, 1u, 13u, 1214u);
    ((void**) _a33_arr->buf->slots)[_a33_arr->offset + 0u] = t3.payload.obj;
    l3 = (void*) _a33_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a34_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a34_obj, 700u);
    _a34_obj->f_comment = l2;
    _a34_obj->f_items = l3;
    l2 = (void*) _a34_obj;
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
    l1 = vader_c_emit_c_ast_around(193u, l1, 217u);
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
    l1 = vader_c_emit_c_ast_around(194u, l1, 216u);
    vader_c_emit_push_expr(l0, (uint8_t) 11, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_box_op(void* l0, void* l1) {
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
    l5 = ((vader_struct_vader_bytecode_Box_t*) l1)->f_type_id;
    l2 = vader_c_emit_box_expr(l3, l4, l5);
    vader_c_emit_push_into_temporary(l0, l2, (uint8_t) 19);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_branch(void* l0, int32_t l1, bool l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l9 = 0;
    void* l6 = NULL;
    size_t l7;
    int64_t l8;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l9, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_jump_table);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l4 = vader_c_emit_branch_target(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l3);
    if (l4.tag == 652u) {
        t0 = l4.payload.obj;
        t1 = vader_c_emit_is_continue_branch(t0, l3);
        if (t1) {
            l6 = std_core_new_byte_buffer((size_t) 25);
            l7 = (size_t) 0;
            l7 = std_core_write_string_at(l6, l7, 1726u);
            t0 = l4.payload.obj;
            t2 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
            l8 = ((int64_t) (int32_t) t2);
            l7 = std_core_write_int(l6, l7, l8);
            l5 = std_core_finish_buffer(l6, l7);
        } else {
            l6 = std_core_new_byte_buffer((size_t) 24);
            l7 = (size_t) 0;
            l7 = std_core_write_string_at(l6, l7, 1362u);
            t0 = l4.payload.obj;
            t2 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
            l8 = ((int64_t) (int32_t) t2);
            l7 = std_core_write_int(l6, l7, l8);
            l5 = std_core_finish_buffer(l6, l7);
        }
        if (l2) {
            l4 = vader_c_emit_pop(l0);
            l6 = std_core_new_byte_buffer((size_t) 31);
            l7 = (size_t) 0;
            l7 = std_core_write_string_at(l6, l7, 1154u);
            l8 = ((int64_t) (int32_t) l1);
            l7 = std_core_write_int(l6, l7, l8);
            l7 = std_core_write_string_at(l6, l7, 206u);
            l9 = std_core_finish_buffer(l6, l7);
            vader_c_emit_assert_stack_empty(l0, l9);
            l4 = vader_c_emit_expression_of(l4);
            vader_struct_vader_c_emit_c_ast_CGoto_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGoto_t));
            vader_obj_header_init(_a1_obj, 683u);
            _a1_obj->f_label = l5;
            _a1_obj->f_condition = l4;
            l6 = (void*) _a1_obj;
            vader_c_emit_append_statement(l0, vader_ref_box(l6));
        } else {
            l6 = std_core_new_byte_buffer((size_t) 28);
            l7 = (size_t) 0;
            l7 = std_core_write_string_at(l6, l7, 1152u);
            l8 = ((int64_t) (int32_t) l1);
            l7 = std_core_write_int(l6, l7, l8);
            l7 = std_core_write_string_at(l6, l7, 206u);
            l9 = std_core_finish_buffer(l6, l7);
            vader_c_emit_assert_stack_empty(l0, l9);
            vader_struct_vader_c_emit_c_ast_CGoto_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CGoto_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGoto_t));
            vader_obj_header_init(_a2_obj, 683u);
            _a2_obj->f_label = l5;
            _a2_obj->f_condition = vader_box_obj(0u, NULL);
            l6 = (void*) _a2_obj;
            vader_c_emit_append_statement(l0, vader_ref_box(l6));
        }
    } else {
        l6 = std_core_new_byte_buffer((size_t) 91);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 1355u);
        l8 = ((int64_t) (int32_t) l1);
        l7 = std_core_write_int(l6, l7, l8);
        l7 = std_core_write_string_at(l6, l7, 26u);
        l8 = ((int64_t) (int32_t) l3);
        l7 = std_core_write_int(l6, l7, l8);
        l7 = std_core_write_string_at(l6, l7, 206u);
        t3 = std_core_finish_buffer(l6, l7);
        std_abort_todo(t3);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2255u, l1);
    l2 = vader_c_emit_c_ast_cast(2337u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 3u, 13u, 1205u);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
    l3 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2249u, l3);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2261u, l4);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 374u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CPrinter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t));
    vader_obj_header_init(_a2_obj, 696u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l7 = (void*) _a2_obj;
    vader_c_emit_emit_preamble(l7, 437u);
    vader_c_emit_emit_struct_typedefs(l5, l7);
    vader_c_emit_emit_fn_sig_typedefs(l5, l7);
    vader_c_emit_emit_forward_decls(l5, l7);
    vader_c_emit_emit_closure_forward_decls(l5, l7);
    vader_c_emit_emit_vtable_forward_decls(l5, l7);
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 190u);
    t0 = (void*) _a3_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a4_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a4_obj, 374u);
    _a4_obj->f_parts = t0;
    t0 = (void*) _a4_obj;
    vader_struct_vader_c_emit_c_ast_CPrinter_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t));
    vader_obj_header_init(_a5_obj, 696u);
    _a5_obj->f_out = t0;
    _a5_obj->f_started = false;
    l8 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a6_arr->buf)[_a6_arr->offset + 0u] = vader_box_string(190u, 436u);
    l9 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a7_obj, 685u);
    _a7_obj->f_path = 2201u;
    _a7_obj->f_system = false;
    t0 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(147u, 1u, 13u, 1214u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = t0;
    l10 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 700u);
    _a9_obj->f_comment = l9;
    _a9_obj->f_items = l10;
    l9 = (void*) _a9_obj;
    vader_c_emit_c_ast_print_section(l8, l9);
    vader_c_emit_emit_import_shims(l5, l8);
    t1 = vader_c_emit_imports_header_name(l2);
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a10_obj, 685u);
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
    vader_array_t* _a11_arr = vader_array_new(8u, 0u, 0u, 190u);
    l12 = (void*) _a11_arr;
    l13 = ((vader_array_t*) l3)->length;
    l14 = (size_t) 0;
    while ((l14 < l13)) {
        l15 = vader_c_emit_including(l2);
        l16 = l14;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l16)
        l17 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l16);
        vader_c_emit_emit_internal_forward_decls(l5, l17, l15);
        if (l14 == INT64_C(0)) {
            vader_c_emit_emit_fn_trampolines(l5, l15);
            vader_c_emit_emit_vtable_dispatchers(l5, l15);
        }
        l18 = l14;
        vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l18)
        l19 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l18);
        l20 = ((vader_array_t*) l19)->length;
        l21 = (size_t) 0;
        while ((l21 < l20)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l21)
            l22 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l21];
            l23 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
            t2 = ((int64_t) (int32_t) l22);
            l24 = (size_t) (int64_t) t2;
            vader_array_t* _a15_slotarr = ((vader_array_t*) l23);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l24)
            l25 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l24);
            l26 = vader_c_emit_function_definition(l5, l22, l25);
            vader_c_emit_c_ast_print_item(l15, vader_ref_box(l26));
            t2 = (l21 + INT64_C(1));
            l21 = (size_t) (int64_t) t2;
        }
        if (l14 == INT64_C(0)) {
            l6 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_entry_mangled;
            vader_c_emit_emit_main(l5, l15, l6);
        }
        l27 = vader_c_emit_c_ast_printed_text(l15);
        vader_array_push((vader_array_t*) l12, vader_box_string(190u, l27));
        t2 = (l14 + INT64_C(1));
        l14 = (size_t) (int64_t) t2;
    }
    l6 = vader_c_emit_c_ast_printed_text(l7);
    l27 = vader_c_emit_c_ast_printed_text(l8);
    l28 = vader_c_emit_c_ast_printed_text(l9);
    vader_struct_vader_c_emit_CProgram_t* _a16_obj = (vader_struct_vader_c_emit_CProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CProgram_t));
    vader_obj_header_init(_a16_obj, 643u);
    _a16_obj->f_header = l6;
    _a16_obj->f_imports = l27;
    _a16_obj->f_globals = l28;
    _a16_obj->f_units = l12;
    _a16_obj->f_unit_names = l10;
    t0 = (void*) _a16_obj;
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
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    int64_t l10;
    uint8_t l11;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    size_t t3;
    vader_string_t t4 = 0;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l7, &l9, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t4 };
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
    if (l4.tag == 483u) {
        l5 = vader_c_emit_pop(l0);
        t2 = l4.payload.obj;
        t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_params)->length;
        l6 = ((int32_t) (size_t) t3);
        l7 = vader_c_emit_pop_args_boxed(l0, l6);
        l8 = vader_c_emit_aux(l0, 1487u);
        l5 = vader_c_emit_object_pointer_of(l5);
        l5 = vader_c_emit_c_ast_cast(2277u, l5);
        vader_c_emit_declare(l0, 2277u, l8, l5);
        t4 = concat_2(l8, 253u);
        t5 = vader_c_emit_c_ast_verbatim(t4);
        vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t5.payload.obj;
        l9 = (void*) _a1_arr;
        vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l7);
        l3 = vader_host_std_core_byte_len(l8);
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(53) + l3));
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l7, l3, 195u);
        l10 = ((int64_t) (int32_t) l6);
        l3 = std_core_write_int(l7, l3, l10);
        l3 = std_core_write_string_at(l7, l3, 768u);
        l3 = std_core_write_string_at(l7, l3, l8);
        l3 = std_core_write_string_at(l7, l3, 252u);
        t4 = std_core_finish_buffer(l7, l3);
        l5 = vader_c_emit_c_ast_call(t4, l9);
        t2 = l4.payload.obj;
        t0 = ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_return_type;
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
    } else {
        l2 = std_core_new_byte_buffer((size_t) 49);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l2, l3, 1223u);
        t0 = ((vader_struct_vader_bytecode_CallIndirect_t*) l1)->f_type_id;
        l10 = ((int64_t) (int32_t) t0);
        l3 = std_core_write_int(l2, l3, l10);
        t4 = std_core_finish_buffer(l2, l3);
        std_abort_todo(t4);
    }
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
    if (l3) {
        vader_c_emit_evaluate(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_push_into_temporary(l0, l1, l2);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
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
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l10, 196u);
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
    if ((t0 > INT64_C(1))) {
        vader_c_emit_emit_multi_call(l0, l1, l4, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = vader_c_emit_c_ast_call(l1, l4);
    l11 = vader_bytecode_bc_single_result(l2);
    vader_c_emit_emit_call_result(l0, l7, l11);
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
    bool l13;
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        if ((t1 >= INT32_C(0))) {
            l7 = ((int32_t) (size_t) l6);
            l8 = vader_c_emit_fn_symbol_name(l3, l7);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature;
            t2 = vader_c_emit_trampoline_signature(l0, l8, l9);
            vader_struct_vader_c_emit_c_ast_CPrototype_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
            vader_obj_header_init(_a3_obj, 697u);
            _a3_obj->f_signature = t2;
            l10 = (void*) _a3_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
            l11 = concat_2(2275u, l8);
            l12 = vader_c_emit_external(2276u, l11, vader_box_obj(0u, NULL), false);
            vader_array_push((vader_array_t*) l4, l12);
        }
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_is_closure);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t4 = vader_box_bool(188u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6]);
        t0 = t4.payload.b;
        if (t0) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
            t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature)->f_params)->length;
            l13 = (t5 > INT64_C(0));
        } else {
            l13 = false;
        }
        if (l13) {
            l7 = ((int32_t) (size_t) l6);
            l8 = vader_c_emit_fn_symbol_name(l3, l7);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
            t2 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature;
            t2 = vader_c_emit_lift_signature(l0, l8, l9);
            vader_struct_vader_c_emit_c_ast_CPrototype_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
            vader_obj_header_init(_a7_obj, 697u);
            _a7_obj->f_signature = t2;
            l10 = (void*) _a7_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
        }
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 190u);
    t2 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 700u);
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
    if (t2 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l7 = vader_c_emit_c_ast_verbatim(1369u);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(0), 196u);
    l8 = ((uint8_t) t3.payload.i);
    t3 = vader_c_emit_coerce_expr(l6, l7, (uint8_t) 18, l8);
    vader_array_t* _a2_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t3.payload.obj;
    l6 = (void*) _a2_arr;
    l9 = vader_c_emit_lift_unbox_tail(((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
    vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l9);
    vader_array_t* _a3_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t4 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a4_obj, 663u);
    _a4_obj->f_body = t4;
    l9 = (void*) _a4_obj;
    l10 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l9)->f_body;
    l6 = vader_c_emit_forward_boxed(l5, l6, l3);
    vader_array_push_all((vader_array_t*) l10, (vader_array_t*) l6);
    l3 = vader_c_emit_lift_signature(l0, l5, l3);
    vader_array_t* _a5_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l6 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a6_obj, 680u);
    _a6_obj->f_signature = l3;
    _a6_obj->f_prologue = l6;
    _a6_obj->f_body = l9;
    l3 = (void*) _a6_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l3));
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
        l6 = std_string_starts_with(l2, 2134u);
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
    } else if (l5 == l1) {
        l7 = vader_c_emit_expression_of(l3);
        vader_c_emit_push_expr(l0, l1, l7);
    } else {
        t1 = vader_c_emit_expression_of(l3);
        t2 = vader_c_emit_scalar_cast(t1, l5, l1);
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a0_obj, 695u);
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
    l3 = std_core_write_string_at(l2, l3, 2265u);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        t1 = vader_c_emit_data_entry_mutable(t0);
        l5 = !(t1);
        l6 = std_core_new_byte_buffer((size_t) 31);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 2265u);
        t2 = ((int64_t) (size_t) l4);
        l8 = (uint64_t) (int64_t) t2;
        l7 = std_core_write_unsigned(l6, l7, l8);
        l9 = std_core_finish_buffer(l6, l7);
        l10 = vader_c_emit_external(2234u, l9, vader_box_obj(0u, NULL), l5);
        vader_array_push((vader_array_t*) l2, l10);
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    t3 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    t4 = ((vader_array_t*) t3)->length;
    if ((t4 > INT64_C(0))) {
        vader_struct_vader_c_emit_c_ast_CUnsized_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
        vader_obj_header_init(_a2_obj, 710u);
        l6 = (void*) _a2_obj;
        l10 = vader_c_emit_external(2235u, 2285u, vader_ref_box(l6), false);
        vader_struct_vader_c_emit_c_ast_CUnsized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
        vader_obj_header_init(_a3_obj, 710u);
        l6 = (void*) _a3_obj;
        l11 = vader_c_emit_external(2337u, 2287u, vader_ref_box(l6), false);
        l12 = vader_c_emit_external(2281u, 2286u, vader_box_obj(0u, NULL), false);
        vader_array_t* _a4_arr = vader_array_new(147u, 3u, 13u, 1214u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l11.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l10.payload.obj;
        l6 = (void*) _a4_arr;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l6);
    }
    vader_struct_vader_c_emit_c_ast_CUnsized_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
    vader_obj_header_init(_a5_obj, 710u);
    l6 = (void*) _a5_obj;
    l10 = vader_c_emit_external(2238u, 2237u, vader_ref_box(l6), true);
    vader_array_push((vader_array_t*) l2, l10);
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 190u);
    t3 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a7_obj, 700u);
    _a7_obj->f_comment = t3;
    _a7_obj->f_items = l2;
    l2 = (void*) _a7_obj;
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_data_pool_type_ids(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module);
    t1 = vader_c_emit_has_str_data(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    if (t1) {
        l4 = vader_c_emit_build_string_atom_map(l0);
    } else {
        vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
        l6 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 193u);
        l7 = (void*) _a3_arr;
        vader_struct_std_collections_MutableMap__string__i32_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
        vader_obj_header_init(_a4_obj, 343u);
        _a4_obj->f_ekeys = l5;
        _a4_obj->f_evals = l6;
        _a4_obj->f_index = l7;
        _a4_obj->f_mask = (size_t) 0;
        _a4_obj->f_size = (size_t) 0;
        _a4_obj->f_tombs = (size_t) 0;
        l4 = (void*) _a4_obj;
    }
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        l5 = std_core_new_byte_buffer((size_t) 31);
        l11 = (size_t) 0;
        l11 = std_core_write_string_at(l5, l11, 2265u);
        t2 = ((int64_t) (size_t) l9);
        l12 = (uint64_t) (int64_t) t2;
        l11 = std_core_write_unsigned(l5, l11, l12);
        l13 = std_core_finish_buffer(l5, l11);
        t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        l14 = vader_c_emit_global_storage(t1);
        t1 = vader_c_emit_data_entry_mutable(l10);
        l15 = !(t1);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        l16 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l9];
        l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        l17 = l16;
        l18 = vader_c_emit_array_element_tag(l6, l17);
        vader_struct_vader_c_emit_PoolArray_t* _a7_obj = (vader_struct_vader_c_emit_PoolArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_PoolArray_t));
        vader_obj_header_init(_a7_obj, 649u);
        _a7_obj->f_name = l13;
        _a7_obj->f_storage = l14;
        _a7_obj->f_constant = l15;
        _a7_obj->f_type_id = l16;
        _a7_obj->f_element_tag = l18;
        l7 = (void*) _a7_obj;
        if (l10.tag == 492u) {
            l19 = l10.payload.obj;
            vader_c_emit_emit_str_data_entry(l2, l7, l19, l4);
        } else if (l10.tag == 488u) {
            l20 = l10.payload.obj;
            vader_c_emit_emit_prim_data_entry(l2, l7, l20);
        } else if (l10.tag == 479u) {
            l21 = l10.payload.obj;
            vader_c_emit_emit_agg_data_entry(l0, l2, l7, l21, l4);
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    vader_c_emit_emit_global_const_roots(l0, l2);
    vader_array_t* _a8_arr = vader_array_new(8u, 3u, 0u, 190u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 2u] = vader_box_string(190u, 1887u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 1u] = vader_box_string(190u, 493u);
    vader_array_box_slots(_a8_arr->buf)[_a8_arr->offset + 0u] = vader_box_string(190u, 410u);
    t3 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 700u);
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
    if (l2.tag == 496u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_bits;
        t1 = vader_c_emit_data_slot(l5, l6);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 497u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        t2 = vader_c_emit_atom_for(l4, l7);
        t1 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 498u) {
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
        l7 = concat_2(2030u, l7);
        t1 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l9));
        t4 = vader_c_emit_object_header(t1);
        vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t4.payload.obj;
        l8 = (void*) _a1_arr;
        l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        t3 = ((int64_t) (int32_t) l9);
        l10 = (size_t) (int64_t) t3;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        if (t1.tag == 493u) {
            l11 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
            t3 = ((int64_t) (int32_t) l9);
            l10 = (size_t) (int64_t) t3;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            l11 = t1.payload.obj;
            t0 = l2.payload.obj;
            l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields)->length;
            l12 = (size_t) 0;
            while ((l12 < l10)) {
                l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l11)->f_fields)->length;
                if ((l12 < l13)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l11)->f_fields);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                    t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
                    l9 = ((vader_struct_vader_bytecode_BcField_t*) t0)->f_type_index;
                } else {
                    l9 = INT32_C(0);
                }
                t0 = l2.payload.obj;
                vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l12)
                l14 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l12);
                l15 = l3;
                l16 = vader_host_std_core_byte_len(l15);
                l17 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l16));
                l18 = (size_t) 0;
                l18 = std_core_write_string_at(l17, l18, l15);
                l18 = std_core_write_string_at(l17, l18, 759u);
                t3 = ((int64_t) (size_t) l12);
                l6 = (uint64_t) (int64_t) t3;
                l18 = std_core_write_unsigned(l17, l18, l6);
                l19 = std_core_finish_buffer(l17, l18);
                l20 = vader_c_emit_struct_field_init(l0, l1, l14, l19, l9, l4);
                vader_array_push((vader_array_t*) l8, l20);
                t3 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t3;
            }
        }
        t5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        l5 = vader_c_emit_global_storage(t5);
        l14 = vader_c_emit_c_ast_initializer_list(l8);
        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
        vader_obj_header_init(_a6_obj, 673u);
        _a6_obj->f_name = l3;
        _a6_obj->f_length = vader_box_obj(0u, NULL);
        _a6_obj->f_value = l14;
        l8 = (void*) _a6_obj;
        vader_struct_vader_c_emit_c_ast_CGlobal_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
        vader_obj_header_init(_a7_obj, 682u);
        _a7_obj->f_storage = l5;
        _a7_obj->f_constant = true;
        _a7_obj->f_type = l7;
        _a7_obj->f_declarator = l8;
        l8 = (void*) _a7_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
        l7 = concat_2(l7, 229u);
        t1 = vader_c_emit_c_ast_verbatim(l3);
        l14 = vader_c_emit_c_ast_address_of(t1);
        t1 = vader_c_emit_c_ast_cast(l7, l14);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 495u) {
        l8 = l2.payload.obj;
        t1 = vader_c_emit_emit_nested_array(l0, l1, l8, l3, l4);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_c_ast_number(INT64_C(0));
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
    l3 = std_core_write_string_at(l2, l3, 2134u);
    t1 = std_core_finish_buffer(l2, l3);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t2.payload.obj;
    l2 = (void*) _a0_arr;
    l5 = vader_c_emit_c_ast_call(2266u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l2 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2267u, l2);
    vader_c_emit_evaluate(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_else(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_c_emit_assert_stack_empty(l0, 1353u);
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
    l3 = std_core_write_string_at(l2, l3, 1912u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 206u);
    l5 = std_core_finish_buffer(l2, l3);
    vader_c_emit_assert_stack_empty(l0, l5);
    l6 = vader_c_emit_scope_ending_at(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l1);
    if (l6.tag == 0u) {
        l7 = std_core_new_byte_buffer((size_t) 50);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l7, l3, 1356u);
        l4 = ((int64_t) (int32_t) l1);
        l3 = std_core_write_int(l7, l3, l4);
        t0 = std_core_finish_buffer(l7, l3);
        std_abort_todo(t0);
        l2 = 0;
    } else {
        l2 = l6.payload.obj;
    }
    l8 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
    vader_c_emit_pc_close_cache(l0, l8);
    l7 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_break_targets;
    l8 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
    t1 = std_core____Contains_contains__i32(l7, l8);
    if (t1) {
        l7 = std_core_new_byte_buffer((size_t) 24);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l7, l3, 1362u);
        t2 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
        l4 = ((int64_t) (int32_t) t2);
        l3 = std_core_write_int(l7, l3, l4);
        l5 = std_core_finish_buffer(l7, l3);
    } else {
        l5 = 0u;
    }
    vader_c_emit_close_node(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_f32_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_operand_as(l0, l1, (uint8_t) 10);
    l1 = vader_c_emit_c_ast_around(201u, l1, 128u);
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
    l1 = vader_c_emit_c_ast_around(202u, l1, 129u);
    vader_c_emit_push_expr(l0, (uint8_t) 3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_fn_addr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l6, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_new_temporary(l0, (uint8_t) 17);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l4 = ((vader_struct_vader_bytecode_FnAddr_t*) l1)->f_function_index;
    t0 = vader_c_emit_fn_symbol_name(l3, l4);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    l5 = vader_c_emit_c_ast_address_of(t1);
    l5 = vader_c_emit_c_ast_cast(2337u, l5);
    vader_c_emit_assign(l0, vader_ref_box(l2), l5);
    l5 = vader_c_emit_c_ast_verbatim(2269u);
    l6 = vader_c_emit_c_ast_verbatim(290u);
    vader_c_emit_assign(l0, l5, l6);
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
    t0 = concat_2(2275u, l4);
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
    l7 = vader_c_emit_c_ast_verbatim(1369u);
    t2 = vader_c_emit_c_ast_cast(2336u, l7);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 677u);
    _a1_obj->f_expression = t2;
    t3 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(146u, 1u, 13u, 1209u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t3;
    t3 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a3_obj, 663u);
    _a3_obj->f_body = t3;
    l8 = (void*) _a3_obj;
    l9 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l8)->f_body;
    l10 = vader_c_emit_tramp_unbox_args(((vader_struct_vader_bytecode_BcSignature_t*) l4)->f_params);
    l10 = vader_c_emit_forward_boxed(l6, l10, l4);
    vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l10);
    l4 = vader_c_emit_trampoline_signature(l0, l6, l4);
    vader_array_t* _a4_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l9 = (void*) _a4_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a5_obj, 680u);
    _a5_obj->f_signature = l4;
    _a5_obj->f_prologue = l9;
    _a5_obj->f_body = l8;
    l4 = (void*) _a5_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
    t2 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l3));
    l7 = vader_c_emit_object_header(t2);
    t1 = concat_2(2278u, l6);
    t2 = vader_c_emit_c_ast_verbatim(t1);
    l11 = vader_c_emit_c_ast_address_of(t2);
    l11 = vader_c_emit_c_ast_cast(2337u, l11);
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a6_obj, 711u);
    _a6_obj->f_text = 489u;
    l4 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 2u] = l4;
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 1u] = l11.payload.obj;
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = l7.payload.obj;
    t3 = (void*) _a7_arr;
    l7 = vader_c_emit_c_ast_initializer_list(t3);
    t4 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l12 = vader_c_emit_global_storage(t4);
    t1 = concat_2(2275u, l6);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a8_obj, 673u);
    _a8_obj->f_name = t1;
    _a8_obj->f_length = vader_box_obj(0u, NULL);
    _a8_obj->f_value = l7;
    l4 = (void*) _a8_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a9_obj, 682u);
    _a9_obj->f_storage = l12;
    _a9_obj->f_constant = false;
    _a9_obj->f_type = 2276u;
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_max_fn_arity(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
    l4 = (size_t) 0;
    while ((l4 <= l3)) {
        l5 = std_core_new_byte_buffer((size_t) 42);
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l5, l6, 2272u);
        t0 = ((int64_t) (size_t) l4);
        l7 = (uint64_t) (int64_t) t0;
        l6 = std_core_write_unsigned(l5, l6, l7);
        l6 = std_core_write_string_at(l5, l6, 767u);
        l8 = std_core_finish_buffer(l5, l6);
        l9 = vader_c_emit_erased_parameters(l4);
        vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t));
        vader_obj_header_init(_a1_obj, 681u);
        _a1_obj->f_result = 2247u;
        _a1_obj->f_name = l8;
        _a1_obj->f_parameters = l9;
        l10 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 190u);
    t1 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a3_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
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
        t3 = vader_box_bool(188u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5]);
        t0 = t3.payload.b;
        if (t0) {
            l6 = ((int32_t) (size_t) l5);
            vader_c_emit_emit_closure_lift(l0, l4, l6);
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 190u);
    t4 = (void*) _a4_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a5_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        l5 = ((int32_t) (size_t) l4);
        t0 = vader_c_emit_module_function_storage(l0, l5);
        if (t0 == INT32_C(1)) {
            l6 = true;
        } else {
            t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
            l6 = !(t1);
        }
        if (l6) {
            l7 = ((int32_t) (size_t) l4);
            t2 = vader_c_emit_signature_for(l0, l7);
            vader_struct_vader_c_emit_c_ast_CPrototype_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
            vader_obj_header_init(_a1_obj, 697u);
            _a1_obj->f_signature = t2;
            l8 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 190u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a3_obj, 700u);
    _a3_obj->f_comment = t2;
    _a3_obj->f_items = l2;
    l2 = (void*) _a3_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_global_const_roots(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    uint8_t l3;
    size_t l6, l7, l8, l10;
    uint64_t l11;
    vader_box_t l12 = vader_box_null(), l15 = vader_box_null();
    size_t t0;
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    void* t5 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l15, &t4 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l5, &l9, &l13, &l14, &t5 };
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l4 = (void*) _a0_arr;
    l5 = l2;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
        l8 = (size_t) (int64_t) t2;
        l9 = std_core_new_byte_buffer((size_t) 31);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l9, l10, 2265u);
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
    vader_struct_vader_c_emit_c_ast_CUnsized_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
    vader_obj_header_init(_a2_obj, 710u);
    l5 = (void*) _a2_obj;
    l12 = vader_c_emit_c_ast_initializer_list(l4);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a3_obj, 673u);
    _a3_obj->f_name = 2285u;
    _a3_obj->f_length = vader_ref_box(l5);
    _a3_obj->f_value = l12;
    l5 = (void*) _a3_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a4_obj, 682u);
    _a4_obj->f_storage = l3;
    _a4_obj->f_constant = false;
    _a4_obj->f_type = 2235u;
    _a4_obj->f_declarator = l5;
    l5 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
    l4 = std_iter_clone__CAddressOf___CBinary___CCall___CCast___CCastToTypeOf___CCompoundLiteral___CConditional___CDesignated___CIndex___CInitializerList___CIntegerLiteral___CLocal___CMember___CNumber___CParenthesized___CSequence___CStringLiterals___CTemporary___CUnary___CVerbatim(l4);
    l6 = ((vader_array_t*) l2)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        t2 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l7];
        l8 = (size_t) (int64_t) t2;
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t4 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
        if (!(t4.tag == 488u)) {
            l5 = std_core_new_byte_buffer((size_t) 35);
            l10 = (size_t) 0;
            l10 = std_core_write_string_at(l5, l10, 2265u);
            t2 = ((int64_t) (size_t) l8);
            l11 = (uint64_t) (int64_t) t2;
            l10 = std_core_write_unsigned(l5, l10, l11);
            l10 = std_core_write_string_at(l5, l10, 755u);
            t3 = std_core_finish_buffer(l5, l10);
            t4 = vader_c_emit_c_ast_verbatim(t3);
            l12 = vader_c_emit_c_ast_address_of(t4);
            vader_array_push((vader_array_t*) l4, l12);
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    vader_struct_vader_c_emit_c_ast_CUnsized_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
    vader_obj_header_init(_a7_obj, 710u);
    l2 = (void*) _a7_obj;
    l12 = vader_c_emit_c_ast_initializer_list(l4);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a8_obj, 673u);
    _a8_obj->f_name = 2287u;
    _a8_obj->f_length = vader_ref_box(l2);
    _a8_obj->f_value = l12;
    l2 = (void*) _a8_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a9_obj, 682u);
    _a9_obj->f_storage = l3;
    _a9_obj->f_constant = false;
    _a9_obj->f_type = 2337u;
    _a9_obj->f_declarator = l2;
    l2 = (void*) _a9_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a10_obj, 711u);
    _a10_obj->f_text = 489u;
    l2 = (void*) _a10_obj;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a11_obj, 692u);
    _a11_obj->f_value = INT64_C(0);
    _a11_obj->f_unsigned_v = true;
    l5 = (void*) _a11_obj;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a12_obj, 692u);
    _a12_obj->f_value = INT64_C(0);
    _a12_obj->f_unsigned_v = true;
    l9 = (void*) _a12_obj;
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a13_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a13_obj, 711u);
    _a13_obj->f_text = 489u;
    l13 = (void*) _a13_obj;
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a14_obj, 711u);
    _a14_obj->f_text = 489u;
    l14 = (void*) _a14_obj;
    t0 = ((vader_array_t*) l4)->length;
    l12 = vader_c_emit_c_ast_unsigned(((int64_t) (size_t) t0));
    l15 = vader_c_emit_c_ast_verbatim(2287u);
    vader_array_t* _a15_arr = vader_array_new(145u, 7u, 13u, 1205u);
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 6u] = l15.payload.obj;
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 5u] = l12.payload.obj;
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 4u] = l14;
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 3u] = l13;
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 2u] = l9;
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l5;
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l2;
    t5 = (void*) _a15_arr;
    l12 = vader_c_emit_c_ast_initializer_list(t5);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a16_obj, 673u);
    _a16_obj->f_name = 2286u;
    _a16_obj->f_length = vader_box_obj(0u, NULL);
    _a16_obj->f_value = l12;
    l2 = (void*) _a16_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a17_obj, 682u);
    _a17_obj->f_storage = l3;
    _a17_obj->f_constant = false;
    _a17_obj->f_type = 2281u;
    _a17_obj->f_declarator = l2;
    l2 = (void*) _a17_obj;
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
    vader_c_emit_assert_stack_empty(l0, 1591u);
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
    void* l14 = NULL;
    void* l16 = NULL;
    size_t l6, l7;
    bool l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_box_t l15 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l15, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l14, &l16, &t4 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l11, &l12, &l13, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    if (t0) {
        vader_c_emit_emit_mirrored_struct_typedefs(l0, l1);
    }
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 190u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l5 = (void*) _a3_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_is_extern;
        if (t0) {
            l10 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_extern_name;
            t0 = std_core____Contains_contains__string(l3, l10);
            l9 = !(t0);
        } else {
            l9 = false;
        }
        if (l9) {
            l11 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_extern_name;
            vader_array_push((vader_array_t*) l3, vader_box_string(190u, l11));
            t1 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
            if (t1 != 0u) {
                l12 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                t0 = std_core____Contains_contains__string(l4, l12);
                if (!(t0)) {
                    l13 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                    vader_array_push((vader_array_t*) l4, vader_box_string(190u, l13));
                }
            } else {
                l14 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
                l15 = vader_c_emit_extern_decl(l8, l14);
                vader_array_push((vader_array_t*) l2, l15);
            }
        }
        l16 = vader_c_emit_import_shim(l0, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l16));
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a5_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l3 = (void*) _a5_arr;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t3 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l7];
        t1 = t3.payload.s;
        l8 = vader_c_emit_include_of(t1);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a7_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a7_arr->buf)[_a7_arr->offset + 0u] = vader_box_string(190u, 442u);
    t4 = (void*) _a7_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a8_obj, 700u);
    _a8_obj->f_comment = t4;
    _a8_obj->f_items = l3;
    l3 = (void*) _a8_obj;
    vader_c_emit_c_ast_print_section(l1, l3);
    vader_array_t* _a9_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(190u, 671u);
    t4 = (void*) _a9_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a10_obj, 700u);
    _a10_obj->f_comment = t4;
    _a10_obj->f_items = l2;
    l2 = (void*) _a10_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a11_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a11_arr->buf)[_a11_arr->offset + 0u] = vader_box_string(190u, 952u);
    l2 = (void*) _a11_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l4 = vader_c_emit_crossing_mirrors(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module);
    l3 = vader_c_emit_c_struct_layout_asserts(l3, l4);
    vader_struct_vader_c_emit_c_ast_CSection_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a12_obj, 700u);
    _a12_obj->f_comment = l2;
    _a12_obj->f_items = l3;
    l2 = (void*) _a12_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a13_arr = vader_array_new(8u, 0u, 0u, 190u);
    t4 = (void*) _a13_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a14_obj, 700u);
    _a14_obj->f_comment = t4;
    _a14_obj->f_items = l5;
    l2 = (void*) _a14_obj;
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
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
            vader_obj_header_init(_a2_obj, 697u);
            _a2_obj->f_signature = t1;
            l8 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 190u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a4_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 196u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
    l9 = (void*) _a1_arr;
    l10 = ((vader_array_t*) l6)->length;
    l11 = (size_t) 0;
    while ((l11 < l10)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
        if (((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val == INT32_C(16)) {
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
        l12 = ((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val;
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
        l13 = std_core_new_byte_buffer((size_t) 21);
        l14 = (size_t) 0;
        l14 = std_core_write_string_at(l13, l14, 1691u);
        t1 = (l7 + l11);
        l15 = (uint64_t) (int64_t) t1;
        l14 = std_core_write_unsigned(l13, l14, l15);
        l16 = std_core_finish_buffer(l13, l14);
        vader_array_push((vader_array_t*) l9, vader_box_string(190u, l16));
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
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
    vader_obj_header_init(_a0_obj, 689u);
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
    if (l4 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_bytecode_LocalGet_t*) l1)->f_slot;
    vader_c_emit_push_local_ref(l0, l3, l4);
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
    vader_obj_header_init(_a0_obj, 689u);
    _a0_obj->f_slot = l1;
    l5 = (void*) _a0_obj;
    l4 = vader_c_emit_coerced_as(l0, l4, l3);
    vader_c_emit_assign(l0, vader_ref_box(l5), l4);
    if (l2) {
        vader_c_emit_push_local_ref(l0, l1, l3);
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
    vader_obj_header_init(_a0_obj, 694u);
    _a0_obj->f_type = 1617u;
    _a0_obj->f_name = 1062u;
    l3 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CParameter_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
    vader_obj_header_init(_a1_obj, 694u);
    _a1_obj->f_type = 1255u;
    _a1_obj->f_name = 1065u;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(54u, 2u, 13u, 694u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3;
    l3 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a3_obj, 702u);
    _a3_obj->f_storage = (uint8_t) 1;
    _a3_obj->f_inline_v = false;
    _a3_obj->f_result = 1617u;
    _a3_obj->f_name = 1732u;
    _a3_obj->f_parameters = l3;
    l3 = (void*) _a3_obj;
    t0 = vader_c_emit_main_body(l0, l2);
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a4_obj, 663u);
    _a4_obj->f_body = t0;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l5 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a6_obj, 680u);
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
    l3 = vader_c_emit_aux(l0, 1264u);
    l4 = vader_c_emit_gc_allocation(2276u);
    vader_c_emit_declare(l0, 2277u, l3, l4);
    l5 = ((vader_struct_vader_bytecode_MakeClosure_t*) l1)->f_env_type_id;
    vader_c_emit_init_object_header(l0, l3, l5);
    t0 = concat_2(l3, 251u);
    l4 = vader_c_emit_c_ast_verbatim(t0);
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l5 = ((vader_struct_vader_bytecode_MakeClosure_t*) l1)->f_function_index;
    l7 = vader_c_emit_fn_symbol_name(l6, l5);
    t0 = concat_2(2273u, l7);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    l8 = vader_c_emit_c_ast_address_of(t1);
    l8 = vader_c_emit_c_ast_cast(2337u, l8);
    vader_c_emit_assign(l0, l4, l8);
    t0 = concat_2(l3, 253u);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 5u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l5.payload.obj;
    l6 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2254u, l6);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (t0.tag == 493u) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
            l6 = t0.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_c_name;
            if (t1 != 0u) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
                t1 = t0.payload.s;
                vader_struct_vader_c_emit_c_ast_CStructForward_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStructForward_t));
                vader_obj_header_init(_a5_obj, 706u);
                _a5_obj->f_name = t1;
                l7 = (void*) _a5_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l7));
                l8 = vader_c_emit_struct_definition(l0, l6, l5);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
            }
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 190u);
    t3 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a7_obj, 700u);
    _a7_obj->f_comment = t3;
    _a7_obj->f_items = l2;
    l2 = (void*) _a7_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 190u);
    t3 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(55u, 0u, 13u, 708u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l7, 196u);
        l8 = ((uint8_t) t0.payload.i);
        l9 = vader_c_emit_new_temporary(l0, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l9));
        l10 = vader_c_emit_c_ast_address_of(vader_ref_box(l9));
        vader_array_push((vader_array_t*) l2, l10);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    l10 = vader_c_emit_c_ast_call(l1, l2);
    vader_c_emit_evaluate(l0, l10);
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 196u);
        l8 = ((uint8_t) t0.payload.i);
        vader_c_emit_push_temporary(l0, l9, l8);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
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
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l7, &l8, &l10, &t3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature)->f_results;
    l2 = ((vader_array_t*) l1)->length;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if ((t0 < l2)) {
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
        l3 = concat_2(2184u, l3);
        vader_c_emit_unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(49u, 0u, 13u, 661u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        t1 = ((l2 - INT64_C(1)) - l5);
        l6 = (size_t) (int64_t) t1;
        l7 = vader_c_emit_pop(l0);
        l3 = vader_c_emit_out_param_name(l6);
        t2 = concat_2(229u, l3);
        l8 = vader_c_emit_c_ast_verbatim(t2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l6, 196u);
        l9 = ((uint8_t) t3.payload.i);
        l10 = vader_c_emit_coerced_as(l0, l7, l9);
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a2_obj, 661u);
        _a2_obj->f_target = l8;
        _a2_obj->f_value = l10;
        _a2_obj->f_operator = vader_box_obj(0u, NULL);
        l11 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l11));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a3_obj, 698u);
    _a3_obj->f_stores = l4;
    _a3_obj->f_value = vader_box_obj(0u, NULL);
    _a3_obj->f_snapshot_type = 0u;
    _a3_obj->f_pops_frame = false;
    l1 = (void*) _a3_obj;
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
    vader_obj_header_init(_a0_obj, 649u);
    _a0_obj->f_name = l3;
    _a0_obj->f_storage = l9;
    _a0_obj->f_constant = true;
    _a0_obj->f_type_id = l10;
    _a0_obj->f_element_tag = l8;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l11 = (void*) _a1_arr;
    l12 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements)->length;
    l13 = (size_t) 0;
    while ((l13 < l12)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
        l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
        if (l5 == INT32_C(0)) {
            l7 = l3;
            l15 = vader_host_std_core_byte_len(l7);
            l16 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l15));
            l17 = (size_t) 0;
            l17 = std_core_write_string_at(l16, l17, l7);
            l17 = std_core_write_string_at(l16, l17, 772u);
            t1 = ((int64_t) (size_t) l13);
            l18 = (uint64_t) (int64_t) t1;
            l17 = std_core_write_unsigned(l16, l17, l18);
            l19 = std_core_finish_buffer(l16, l17);
            l20 = vader_c_emit_box_slot(l0, l1, l14, l19, l8, l4);
            vader_array_push((vader_array_t*) l11, l20);
        } else if (l14.tag == 496u) {
            t2 = l14.payload.obj;
            l21 = ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_bits;
            l22 = vader_c_emit_data_slot(l5, l21);
            vader_array_push((vader_array_t*) l11, l22);
        }
        t1 = (l13 + INT64_C(1));
        l13 = (size_t) (int64_t) t1;
    }
    l7 = vader_c_emit_c_type_for_array_kind(l5);
    vader_c_emit_push_pool_array(l1, l6, l7, l5, l11);
    t3 = vader_c_emit_c_ast_verbatim(l3);
    l14 = vader_c_emit_c_ast_address_of(t3);
    t3 = vader_c_emit_c_ast_cast(2235u, l14);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_emit_op(void* l0, int32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    bool l6;
    vader_string_t l7 = 0;
    uint8_t l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_c_emit_invalidate_resolve_cache(l0, l2);
    if (l2.tag == 551u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 571u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 532u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 503u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 519u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 602u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 617u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
    } else if (l2.tag == 596u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_local_get(l0, l3);
    } else if (l2.tag == 597u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        vader_c_emit_emit_local_set(l0, l4, false);
    } else if (l2.tag == 598u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        vader_c_emit_emit_local_set(l0, l4, true);
    } else if (l2.tag == 595u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_local_field(l0, l3);
    } else if (l2.tag == 606u) {
        vader_c_emit_emit_return(l0);
    } else if (l2.tag == 607u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value;
        vader_c_emit_emit_return_lit(l0, l5);
    } else if (l2.tag == 525u) {
        vader_c_emit_drop_top(l0);
    } else if (l2.tag == 516u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call(l0, l3);
    } else if (l2.tag == 517u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call_import(l0, l3);
    } else if (l2.tag == 518u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call_indirect(l0, l3);
    } else if (l2.tag == 639u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_virtual_call(l0, l3);
    } else if (l2.tag == 545u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_fn_ref(l0, l3);
    } else if (l2.tag == 544u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_fn_addr(l0, l3);
    } else if (l2.tag == 600u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_make_closure(l0, l3);
    } else if (l2.tag == 586u) {
        vader_c_emit_emit_if_open(l0);
    } else if (l2.tag == 526u) {
        vader_c_emit_emit_else(l0);
    } else if (l2.tag == 529u) {
        vader_c_emit_emit_end(l0, l1);
    } else if (l2.tag == 501u) {
        vader_c_emit_emit_open_scope(l0, l1, (uint8_t) 0);
    } else if (l2.tag == 599u) {
        vader_c_emit_emit_open_scope(l0, l1, (uint8_t) 1);
    } else if (l2.tag == 509u) {
        vader_c_emit_emit_branch(l0, l1, false);
    } else if (l2.tag == 510u) {
        vader_c_emit_emit_branch(l0, l1, true);
    } else if (l2.tag == 506u) {
        vader_c_emit_push_unop(l0, 143u, (uint8_t) 12);
    } else if (l2.tag == 622u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_new(l0, l3);
    } else if (l2.tag == 621u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_get(l0, l3);
    } else if (l2.tag == 623u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_set(l0, l3);
    } else if (l2.tag == 472u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_new(l0, l3);
    } else if (l2.tag == 471u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_ArrayLen_t*) t0)->f_resolve_buf;
        vader_c_emit_emit_array_len(l0, l6);
    } else if (l2.tag == 473u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_push(l0, l3);
    } else if (l2.tag == 470u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_get(l0, l3);
    } else if (l2.tag == 477u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_set(l0, l3);
    } else if (l2.tag == 478u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_slice(l0, l3);
    } else if (l2.tag == 476u) {
        vader_c_emit_emit_array_repeat(l0);
    } else if (l2.tag == 474u) {
        vader_c_emit_emit_array_push_all(l0);
    } else if (l2.tag == 469u) {
        vader_c_emit_emit_array_copy(l0);
    } else if (l2.tag == 475u) {
        vader_c_emit_emit_array_remove_last(l0);
    } else if (l2.tag == 468u) {
        vader_c_emit_emit_array_clear(l0);
    } else if (l2.tag == 521u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_data_const_op(l0, l3);
    } else if (l2.tag == 625u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_type_const(l0, l3);
    } else if (l2.tag == 624u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_type_check(l0, l3);
    } else if (l2.tag == 603u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_ref_cast(l0, l3);
    } else if (l2.tag == 508u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_box_op(l0, l3);
    } else if (l2.tag == 638u) {
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_Unreachable_t*) t0)->f_reason;
        vader_c_emit_unreachable(l0, l7);
    } else if (l2.tag == 520u) {
        t0 = l2.payload.obj;
        l8 = vader_c_emit_convert_target_val(((vader_struct_vader_bytecode_Convert_t*) t0)->f_target);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        vader_c_emit_emit_convert(l0, l8, l7);
    } else if (l2.tag == 608u) {
        vader_c_emit_emit_size_of_type(l0);
    } else if (l2.tag == 546u) {
        vader_c_emit_push_binop(l0, (uint8_t) 3, (uint8_t) 2);
    } else if (l2.tag == 565u) {
        vader_c_emit_push_binop(l0, (uint8_t) 4, (uint8_t) 2);
    } else if (l2.tag == 559u) {
        vader_c_emit_push_binop(l0, (uint8_t) 0, (uint8_t) 2);
    } else if (l2.tag == 552u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 2);
    } else if (l2.tag == 558u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 2);
    } else if (l2.tag == 561u) {
        vader_c_emit_push_unop(l0, 245u, (uint8_t) 2);
    } else if (l2.tag == 548u) {
        vader_c_emit_push_unop(l0, 2385u, (uint8_t) 2);
    } else if (l2.tag == 547u) {
        vader_c_emit_push_binop(l0, (uint8_t) 13, (uint8_t) 2);
    } else if (l2.tag == 549u) {
        vader_c_emit_push_binop(l0, (uint8_t) 15, (uint8_t) 2);
    } else if (l2.tag == 550u) {
        vader_c_emit_push_binop(l0, (uint8_t) 14, (uint8_t) 2);
    } else if (l2.tag == 562u) {
        vader_c_emit_push_binop(l0, (uint8_t) 5, (uint8_t) 2);
    } else if (l2.tag == 563u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 2);
    } else if (l2.tag == 564u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 7);
    } else if (l2.tag == 553u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 2);
    } else if (l2.tag == 560u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 2);
    } else if (l2.tag == 557u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 2);
    } else if (l2.tag == 556u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 2);
    } else if (l2.tag == 555u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 2);
    } else if (l2.tag == 554u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 2);
    } else if (l2.tag == 566u) {
        vader_c_emit_push_binop(l0, (uint8_t) 3, (uint8_t) 3);
    } else if (l2.tag == 585u) {
        vader_c_emit_push_binop(l0, (uint8_t) 4, (uint8_t) 3);
    } else if (l2.tag == 579u) {
        vader_c_emit_push_binop(l0, (uint8_t) 0, (uint8_t) 3);
    } else if (l2.tag == 572u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 3);
    } else if (l2.tag == 578u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 3);
    } else if (l2.tag == 581u) {
        vader_c_emit_push_i64_neg(l0);
    } else if (l2.tag == 567u) {
        vader_c_emit_push_binop(l0, (uint8_t) 13, (uint8_t) 3);
    } else if (l2.tag == 569u) {
        vader_c_emit_push_binop(l0, (uint8_t) 15, (uint8_t) 3);
    } else if (l2.tag == 570u) {
        vader_c_emit_push_binop(l0, (uint8_t) 14, (uint8_t) 3);
    } else if (l2.tag == 568u) {
        vader_c_emit_push_unop(l0, 2385u, (uint8_t) 3);
    } else if (l2.tag == 582u) {
        vader_c_emit_push_binop(l0, (uint8_t) 5, (uint8_t) 3);
    } else if (l2.tag == 583u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 3);
    } else if (l2.tag == 584u) {
        vader_c_emit_push_binop(l0, (uint8_t) 6, (uint8_t) 8);
    } else if (l2.tag == 573u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 3);
    } else if (l2.tag == 580u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 3);
    } else if (l2.tag == 577u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 3);
    } else if (l2.tag == 576u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 3);
    } else if (l2.tag == 575u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 3);
    } else if (l2.tag == 574u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 3);
    } else if (l2.tag == 626u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 7);
    } else if (l2.tag == 631u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 7);
    } else if (l2.tag == 630u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 7);
    } else if (l2.tag == 629u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 7);
    } else if (l2.tag == 628u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 7);
    } else if (l2.tag == 627u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 7);
    } else if (l2.tag == 632u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 8);
    } else if (l2.tag == 637u) {
        vader_c_emit_push_eager(l0, (uint8_t) 2, (uint8_t) 8);
    } else if (l2.tag == 636u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 8);
    } else if (l2.tag == 635u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 8);
    } else if (l2.tag == 634u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 8);
    } else if (l2.tag == 633u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 8);
    } else if (l2.tag == 531u) {
        vader_c_emit_push_binop(l0, (uint8_t) 3, (uint8_t) 11);
    } else if (l2.tag == 542u) {
        vader_c_emit_push_binop(l0, (uint8_t) 4, (uint8_t) 11);
    } else if (l2.tag == 539u) {
        vader_c_emit_push_binop(l0, (uint8_t) 0, (uint8_t) 11);
    } else if (l2.tag == 533u) {
        vader_c_emit_push_eager(l0, (uint8_t) 1, (uint8_t) 11);
    } else if (l2.tag == 541u) {
        vader_c_emit_push_unop(l0, 245u, (uint8_t) 11);
    } else if (l2.tag == 534u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 11);
    } else if (l2.tag == 540u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 11);
    } else if (l2.tag == 538u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 7, (uint8_t) 11);
    } else if (l2.tag == 537u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 8, (uint8_t) 11);
    } else if (l2.tag == 536u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 9, (uint8_t) 11);
    } else if (l2.tag == 535u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 10, (uint8_t) 11);
    } else if (l2.tag == 504u) {
        vader_c_emit_push_binop(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 505u) {
        vader_c_emit_push_binop(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 502u) {
        vader_c_emit_push_binop(l0, (uint8_t) 16, (uint8_t) 12);
    } else if (l2.tag == 507u) {
        vader_c_emit_push_binop(l0, (uint8_t) 17, (uint8_t) 12);
    } else if (l2.tag == 618u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 11, (uint8_t) 14);
    } else if (l2.tag == 619u) {
        vader_c_emit_push_cmp(l0, (uint8_t) 12, (uint8_t) 14);
    } else if (l2.tag == 620u) {
        vader_c_emit_emit_string_slice(l0);
    } else if (l2.tag == 604u) {
        vader_c_emit_push_binop_any(l0, (uint8_t) 11, (uint8_t) 12);
    } else if (l2.tag == 605u) {
        vader_c_emit_push_binop_any(l0, (uint8_t) 12, (uint8_t) 12);
    } else if (l2.tag == 524u) {
        vader_c_emit_emit_defer_push(l0);
    } else if (l2.tag == 523u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_defer_pop_exec(l0, l3);
    } else if (l2.tag == 511u) {
        vader_c_emit_emit_buffer_new(l0);
    } else if (l2.tag == 594u) {
        vader_c_emit_emit_buffer_load(l0, 2253u, (uint8_t) 2);
    } else if (l2.tag == 589u) {
        vader_c_emit_emit_buffer_load(l0, 2251u, (uint8_t) 2);
    } else if (l2.tag == 590u) {
        vader_c_emit_emit_buffer_load(l0, 2252u, (uint8_t) 3);
    } else if (l2.tag == 588u) {
        vader_c_emit_emit_buffer_load(l0, 2250u, (uint8_t) 11);
    } else if (l2.tag == 616u) {
        vader_c_emit_emit_buffer_store(l0, 2259u, 2162u);
    } else if (l2.tag == 611u) {
        vader_c_emit_emit_buffer_store(l0, 2257u, 1619u);
    } else if (l2.tag == 612u) {
        vader_c_emit_emit_buffer_store(l0, 2258u, 1620u);
    } else if (l2.tag == 610u) {
        vader_c_emit_emit_buffer_store(l0, 2256u, 1340u);
    } else if (l2.tag == 592u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LoadSlotI32_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1619u, (uint8_t) 2, l6);
    } else if (l2.tag == 593u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LoadSlotI64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1620u, (uint8_t) 3, l6);
    } else if (l2.tag == 591u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LoadSlotF64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1340u, (uint8_t) 11, l6);
    } else if (l2.tag == 614u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StoreSlotI32_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1619u, (uint8_t) 2, l6);
    } else if (l2.tag == 615u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StoreSlotI64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1620u, (uint8_t) 3, l6);
    } else if (l2.tag == 613u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StoreSlotF64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1340u, (uint8_t) 11, l6);
    } else if (l2.tag == 601u) {
        vader_c_emit_emit_memory_copy(l0);
    } else if (l2.tag == 512u) {
        vader_c_emit_emit_buffer_to_string(l0);
    } else if (l2.tag == 513u) {
        vader_c_emit_emit_buffer_write_string(l0);
    } else if (l2.tag == 543u) {
        vader_c_emit_emit_f64_to_bits(l0);
    } else if (l2.tag == 500u) {
        vader_c_emit_emit_bits_to_f64(l0);
    } else if (l2.tag == 530u) {
        vader_c_emit_emit_f32_to_bits(l0);
    } else if (l2.tag == 499u) {
        vader_c_emit_emit_bits_to_f32(l0);
    } else {
        { vader_gc_top = gc_frame.prev; return; }
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
    l4 = std_core_write_string_at(l3, l4, 1913u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 206u);
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
            vader_obj_header_init(_a0_obj, 650u);
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
        l4 = std_core_write_string_at(l3, l4, 1726u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
    } else {
        l6 = 0u;
    }
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
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(190u, l1);
    l2 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a1_obj, 685u);
    _a1_obj->f_path = 2201u;
    _a1_obj->f_system = false;
    l3 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a2_obj, 685u);
    _a2_obj->f_path = 1988u;
    _a2_obj->f_system = true;
    l4 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a3_obj, 685u);
    _a3_obj->f_path = 1989u;
    _a3_obj->f_system = true;
    l5 = (void*) _a3_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a4_obj, 685u);
    _a4_obj->f_path = 2017u;
    _a4_obj->f_system = true;
    l6 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(147u, 4u, 13u, 1214u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 3u] = l6;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 2u] = l5;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l4;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l3;
    l3 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a6_obj, 700u);
    _a6_obj->f_comment = l2;
    _a6_obj->f_items = l3;
    l2 = (void*) _a6_obj;
    vader_c_emit_c_ast_print_section(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_prim_data_entry(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_items;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
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
        vader_array_t* _a0_arr = vader_array_new(49u, 0u, 13u, 661u);
        t1 = (void*) _a0_arr;
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a1_obj, 698u);
        _a1_obj->f_stores = t1;
        _a1_obj->f_value = vader_box_obj(0u, NULL);
        _a1_obj->f_snapshot_type = 0u;
        _a1_obj->f_pops_frame = false;
        l2 = (void*) _a1_obj;
        vader_c_emit_return_statement(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (t0 == INT64_C(0)) {
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
        l3 = concat_2(2184u, l3);
        vader_c_emit_unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_c_emit_pop(l0);
    vader_array_t* _a2_arr = vader_array_new(49u, 0u, 13u, 661u);
    l2 = (void*) _a2_arr;
    l4 = vader_c_emit_coerced_as(l0, l4, l1);
    l3 = vader_c_emit_c_type_for_val_bare(l1);
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a3_obj, 698u);
    _a3_obj->f_stores = l2;
    _a3_obj->f_value = l4;
    _a3_obj->f_snapshot_type = l3;
    _a3_obj->f_pops_frame = false;
    l2 = (void*) _a3_obj;
    vader_c_emit_return_statement(l0, l2);
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
    vader_array_t* _a0_arr = vader_array_new(49u, 0u, 13u, 661u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a1_obj, 698u);
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
    l1 = vader_c_emit_payload(t1, 1818u);
    l1 = vader_c_emit_c_ast_around(205u, l1, 713u);
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
    l5 = vader_c_emit_resolve_array_local(l0, l4, false);
    if (!(l3)) {
        l4 = vader_c_emit_c_ast_verbatim(l5);
        l6 = vader_c_emit_expression_of(l2);
        vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l6.payload.obj;
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
        l7 = (void*) _a0_arr;
        vader_c_emit_statement_macro(l0, 672u, l7);
    }
    { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6) {
    void* l7 = NULL;
    void* l28 = NULL;
    void* l32 = NULL;
    void* l34 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    size_t l8, l9, l14, l15, l20, l21, l29, l30;
    uint8_t l10;
    bool l11, l12, l13;
    vader_string_t l16 = 0;
    vader_string_t l22 = 0;
    vader_string_t l26 = 0;
    vader_string_t l31 = 0;
    vader_box_t l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null(), l33 = vader_box_null(), l35 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[10] = { &l17, &l18, &l19, &l23, &l24, &l25, &l27, &l33, &l35, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l28, &l32, &l34, &l36, &l37 };
    vader_string_t* gc_atom_roots[5] = { &l16, &l22, &l26, &l31, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 10u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 196u);
    l7 = (void*) _a0_arr;
    l8 = ((vader_array_t*) l1)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 196u);
        l10 = ((uint8_t) t0.payload.i);
        t1 = std_core____Contains_contains__ValType(l7, l10);
        if (t1) {
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
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
            l13 = !(l6);
        } else {
            l13 = false;
        }
        if (l13) {
            l14 = ((vader_array_t*) l1)->length;
            l15 = (size_t) 0;
            while ((l15 < l14)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l15)
                t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l15, 196u);
                if (((int32_t) t0.payload.i) == l10) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l15)
                    t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l15];
                    l16 = t0.payload.s;
                    l17 = vader_c_emit_c_ast_verbatim(287u);
                    l18 = vader_c_emit_c_ast_declaration(2310u, l16, l17);
                    vader_array_push((vader_array_t*) l0, l18);
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
                    t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l15];
                    t3 = t0.payload.s;
                    t0 = vader_c_emit_c_ast_verbatim(t3);
                    l19 = vader_c_emit_c_ast_address_of(t0);
                    vader_array_push((vader_array_t*) l5, l19);
                }
                t2 = (l15 + INT64_C(1));
                l15 = (size_t) (int64_t) t2;
            }
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
            continue;
        }
        if (l11) {
            l20 = ((vader_array_t*) l1)->length;
            l21 = (size_t) 0;
            while ((l21 < l20)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l21)
                t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l21, 196u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l21)
                        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l21];
                        l22 = t0.payload.s;
                        l23 = vader_c_emit_c_ast_verbatim(489u);
                        l24 = vader_c_emit_c_ast_declaration(2337u, l22, l23);
                        vader_array_push((vader_array_t*) l0, l24);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l21)
                        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l21];
                        t3 = t0.payload.s;
                        t0 = vader_c_emit_c_ast_verbatim(t3);
                        l25 = vader_c_emit_c_ast_address_of(t0);
                        vader_array_push((vader_array_t*) l4, l25);
                    } else {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l21)
                        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l21];
                        l26 = t0.payload.s;
                        l27 = vader_c_emit_c_ast_declaration(2337u, l26, vader_box_obj(0u, NULL));
                        vader_array_push((vader_array_t*) l0, l27);
                    }
                }
                t2 = (l21 + INT64_C(1));
                l21 = (size_t) (int64_t) t2;
            }
        } else {
            vader_array_t* _a9_arr = vader_array_new(51u, 0u, 13u, 673u);
            l28 = (void*) _a9_arr;
            l29 = ((vader_array_t*) l1)->length;
            l30 = (size_t) 0;
            while ((l30 < l29)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l30)
                t0 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l30, 196u);
                if (((int32_t) t0.payload.i) == l10) {
                    if (l12) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l30)
                        t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l30];
                        l31 = t0.payload.s;
                        vader_array_t* _a12_arr = vader_array_new(145u, 0u, 13u, 1205u);
                        l32 = (void*) _a12_arr;
                        l33 = vader_c_emit_c_ast_call(2244u, l32);
                        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a13_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
                        vader_obj_header_init(_a13_obj, 673u);
                        _a13_obj->f_name = l31;
                        _a13_obj->f_length = vader_box_obj(0u, NULL);
                        _a13_obj->f_value = l33;
                        l34 = (void*) _a13_obj;
                        vader_array_push((vader_array_t*) l28, vader_ref_box(l34));
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l30)
                        t0 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l30];
                        t3 = t0.payload.s;
                        t0 = vader_c_emit_c_ast_verbatim(t3);
                        l35 = vader_c_emit_c_ast_address_of(t0);
                        vader_array_push((vader_array_t*) l3, l35);
                    } else {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l30)
                        t0 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l30];
                        t3 = t0.payload.s;
                        vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
                        vader_obj_header_init(_a16_obj, 673u);
                        _a16_obj->f_name = t3;
                        _a16_obj->f_length = vader_box_obj(0u, NULL);
                        _a16_obj->f_value = vader_box_obj(0u, NULL);
                        l36 = (void*) _a16_obj;
                        vader_array_push((vader_array_t*) l28, vader_ref_box(l36));
                    }
                }
                t2 = (l30 + INT64_C(1));
                l30 = (size_t) (int64_t) t2;
            }
            t3 = vader_c_emit_c_type_for_val_bare(l10);
            vader_struct_vader_c_emit_c_ast_CDeclaration_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclaration_t));
            vader_obj_header_init(_a17_obj, 672u);
            _a17_obj->f_type = t3;
            _a17_obj->f_declarators = l28;
            l37 = (void*) _a17_obj;
            vader_array_push((vader_array_t*) l0, vader_ref_box(l37));
        }
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
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
    void* l5 = NULL;
    size_t l6, l7;
    vader_string_t l8 = 0;
    int32_t l9, l10;
    vader_box_t l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_bytecode_BcStrData_t*) l2)->f_values;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        l9 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_element_tag;
        l10 = vader_c_emit_atom_for(l3, l8);
        l11 = vader_c_emit_boxed_string(l9, l10);
        vader_array_push((vader_array_t*) l4, l11);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_c_emit_push_pool_array(l0, l1, 2247u, (uint8_t) 0, l4);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l1 = vader_c_emit_c_ast_call(2309u, l4);
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
    if (l4.tag == 493u) {
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
        vader_array_t* _a2_arr = vader_array_new(145u, 1u, 13u, 1205u);
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
            l17 = vader_c_emit_aux(l0, 1992u);
            l18 = vader_c_emit_aux(l0, 1818u);
            l10 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack_storages;
            vader_struct_vader_c_emit_StackStorage_t* _a6_obj = (vader_struct_vader_c_emit_StackStorage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackStorage_t));
            vader_obj_header_init(_a6_obj, 657u);
            _a6_obj->f_cname = l5;
            _a6_obj->f_storage = l17;
            l11 = (void*) _a6_obj;
            vader_array_push((vader_array_t*) l10, vader_ref_box(l11));
            l19 = concat_2(l5, 229u);
            t2 = vader_c_emit_c_ast_verbatim(l17);
            l8 = vader_c_emit_c_ast_address_of(t2);
            vader_c_emit_declare(l0, l19, l18, l8);
            l17 = l18;
        } else {
            l18 = vader_c_emit_aux(l0, 1818u);
            l19 = concat_2(l5, 229u);
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
            t6 = concat_3(l17, 254u, l5);
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
    } else {
        l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        l12 = ((vader_array_t*) l2)->length;
        if ((l3 >= l12)) {
            l10 = std_core_new_byte_buffer((size_t) 56);
            l3 = (size_t) 0;
            l3 = std_core_write_string_at(l10, l3, 1610u);
            t4 = ((vader_array_t*) l2)->length;
            t1 = ((int64_t) (size_t) t4);
            l20 = (uint64_t) (int64_t) t1;
            l3 = std_core_write_unsigned(l10, l3, l20);
            l3 = std_core_write_string_at(l10, l3, 256u);
            l5 = std_core_finish_buffer(l10, l3);
        } else {
            l6 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
            l17 = vader_bytecode_bc_type_key(l2, l6);
            l3 = vader_host_std_core_byte_len(l17);
            l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(53) + l3));
            l3 = (size_t) 0;
            l3 = std_core_write_string_at(l10, l3, 2067u);
            l3 = std_core_write_string_at(l10, l3, l17);
            l3 = std_core_write_string_at(l10, l3, 819u);
            t4 = ((vader_array_t*) l2)->length;
            t1 = ((int64_t) (size_t) t4);
            l20 = (uint64_t) (int64_t) t1;
            l3 = std_core_write_unsigned(l10, l3, l20);
            l3 = std_core_write_string_at(l10, l3, 256u);
            l5 = std_core_finish_buffer(l10, l3);
        }
        l3 = vader_host_std_core_byte_len(l5);
        l2 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(52) + l3));
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l2, l3, 2037u);
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        l21 = ((int64_t) (int32_t) t0);
        l3 = std_core_write_int(l2, l3, l21);
        l3 = std_core_write_string_at(l2, l3, 295u);
        l3 = std_core_write_string_at(l2, l3, l5);
        t6 = std_core_finish_buffer(l2, l3);
        std_abort_todo(t6);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_emit_struct_set(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    size_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l11 = 0;
    int32_t l9;
    uint8_t l10;
    bool l12;
    int64_t l13;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    bool t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[4] = { &l4, &l6, &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l11, &t5 };
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
    if (l4.tag == 493u) {
        l2 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
        t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        l5 = t2.payload.s;
        l6 = vader_c_emit_pop(l0);
        l7 = vader_c_emit_pop(l0);
        t3 = l4.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields;
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
        t4 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_stack;
        if (!(t4)) {
            l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l9 = ((vader_struct_vader_bytecode_BcField_t*) l2)->f_type_index;
            l12 = vader_c_emit_field_may_hold_reference(l8, l9);
        } else {
            l12 = false;
        }
        if (l12) {
            t5 = concat_2(l5, 229u);
            l4 = vader_c_emit_c_ast_cast(t5, l6);
            vader_c_emit_write_barrier(l0, l4);
        }
    } else {
        l2 = std_core_new_byte_buffer((size_t) 50);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l2, l3, 2041u);
        t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
        l13 = ((int64_t) (int32_t) t0);
        l3 = std_core_write_int(l2, l3, l13);
        t5 = std_core_finish_buffer(l2, l3);
        std_abort_todo(t5);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (t0.tag == 493u) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
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
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
                t1 = t0.payload.s;
                vader_struct_vader_c_emit_c_ast_CStructForward_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CStructForward_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStructForward_t));
                vader_obj_header_init(_a5_obj, 706u);
                _a5_obj->f_name = t1;
                l8 = (void*) _a5_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
                l9 = vader_c_emit_struct_definition(l0, l6, l5);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
            }
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 190u);
    t4 = (void*) _a6_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a7_obj, 700u);
    _a7_obj->f_comment = t4;
    _a7_obj->f_items = l2;
    l2 = (void*) _a7_obj;
    vader_c_emit_c_ast_print_section(l1, l2);
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 190u);
    t4 = (void*) _a8_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a9_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_array_t*) l0)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        l9 = std_core_new_byte_buffer((size_t) 21);
        l10 = (size_t) 0;
        l10 = std_core_write_string_at(l9, l10, 2054u);
        t0 = ((int64_t) (size_t) l8);
        l11 = (uint64_t) (int64_t) t0;
        l10 = std_core_write_unsigned(l9, l10, l11);
        l12 = std_core_finish_buffer(l9, l10);
        vader_array_push((vader_array_t*) l6, vader_box_string(190u, l12));
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
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
        if (l6.tag == 494u) {
            vader_array_t* _a1_arr = vader_array_new(145u, 0u, 13u, 1205u);
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
            vader_obj_header_init(_a3_obj, 695u);
            _a3_obj->f_inner = t4;
            l4 = (void*) _a3_obj;
            vader_c_emit_push_expr(l0, (uint8_t) 12, vader_ref_box(l4));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = vader_c_emit_tag_of(l2);
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
        l2 = vader_c_emit_one_variant_check(l0, l2, l9);
        vader_c_emit_push_expr(l0, (uint8_t) 12, l2);
    } else {
        l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
        t0 = vader_c_emit_primitive_matches_type(l4, l3, l9);
        if (t0) {
            l11 = 2098u;
        } else {
            l11 = 1445u;
        }
        l2 = vader_c_emit_c_ast_verbatim(l11);
        vader_c_emit_push_lit(l0, (uint8_t) 12, l2);
    }
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
    l3 = std_core_write_string_at(l2, l3, 2246u);
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_null_tag;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2136u);
    t0 = ((vader_struct_vader_bytecode_TypeConst_t*) l1)->f_type_id;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2135u);
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = ((vader_array_t*) l2)->length;
    l4 = false;
    l5 = false;
    l6 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l9 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        if (l9.tag == 483u) {
            l4 = true;
        }
        if (l9.tag == 480u) {
            l5 = true;
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a2_arr = vader_array_new(147u, 0u, 13u, 1214u);
    l6 = (void*) _a2_arr;
    if (l4) {
        l9 = vader_c_emit_single_offset_list(2274u, 1824u);
        vader_array_push((vader_array_t*) l6, l9);
    }
    if (l5) {
        l9 = vader_c_emit_single_offset_list(2214u, 1823u);
        vader_array_push((vader_array_t*) l6, l9);
    }
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 190u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a4_obj, 700u);
    _a4_obj->f_comment = t1;
    _a4_obj->f_items = l6;
    l6 = (void*) _a4_obj;
    vader_c_emit_c_ast_print_section(l1, l6);
    vader_array_t* _a5_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l6 = (void*) _a5_arr;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l9 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
        l10 = l9;
        if (l9.tag == 493u) {
            l11 = l10.payload.obj;
            l12 = l10.payload.obj;
            l13 = vader_c_emit_classify_struct_fields(l0, l12, l7);
            l14 = vader_c_emit_struct_info_row(l0, l11, l13, l7);
            vader_array_push((vader_array_t*) l6, l14);
        } else if (l9.tag == 483u) {
            t1 = l10.payload.obj;
            l15 = vader_bytecode_size_of_bc_type(vader_ref_box(t1));
            l16 = vader_c_emit_single_reference_row(l7, 427u, 2276u, l15, 2274u);
            vader_array_push((vader_array_t*) l6, l16);
        } else if (l9.tag == 480u) {
            t1 = l10.payload.obj;
            l17 = vader_bytecode_size_of_bc_type(vader_ref_box(t1));
            l18 = vader_c_emit_single_reference_row(l7, 365u, 2234u, l17, 2214u);
            vader_array_push((vader_array_t*) l6, l18);
        } else {
            l19 = vader_bytecode_size_of_bc_type(l10);
            if ((l19 > INT32_C(0))) {
                l20 = vader_c_emit_c_ast_number(((int64_t) (int32_t) l19));
                t2 = vader_c_emit_c_ast_designated(274u, l20);
                vader_array_t* _a7_arr = vader_array_new(145u, 1u, 13u, 1205u);
                ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t2.payload.obj;
                l21 = (void*) _a7_arr;
                l22 = vader_c_emit_info_row(l7, l21);
                vader_array_push((vader_array_t*) l6, l22);
            }
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l15 = ((int32_t) (size_t) l3);
    l9 = vader_c_emit_c_ast_initializer_list(l6);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a8_obj, 673u);
    _a8_obj->f_name = 2317u;
    _a8_obj->f_length = vader_box_i32(193u, l15);
    _a8_obj->f_value = l9;
    l2 = (void*) _a8_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a9_obj, 682u);
    _a9_obj->f_storage = (uint8_t) 1;
    _a9_obj->f_constant = true;
    _a9_obj->f_type = 2316u;
    _a9_obj->f_declarator = l2;
    l2 = (void*) _a9_obj;
    l9 = vader_c_emit_c_ast_number(((int64_t) (size_t) l3));
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a10_obj, 673u);
    _a10_obj->f_name = 2315u;
    _a10_obj->f_length = vader_box_obj(0u, NULL);
    _a10_obj->f_value = l9;
    l6 = (void*) _a10_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a11_obj, 682u);
    _a11_obj->f_storage = (uint8_t) 1;
    _a11_obj->f_constant = true;
    _a11_obj->f_type = 1930u;
    _a11_obj->f_declarator = l6;
    l6 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(8u, 0u, 0u, 190u);
    l11 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(147u, 2u, 13u, 1214u);
    ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l6;
    ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l2;
    l2 = (void*) _a13_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a14_obj, 700u);
    _a14_obj->f_comment = l11;
    _a14_obj->f_items = l2;
    l2 = (void*) _a14_obj;
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
        l3 = concat_2(1807u, l3);
        vader_c_emit_unreachable(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_coerced_as(l0, l5, (uint8_t) 19);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
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
    if (t4 == INT32_C(16)) {
        vader_c_emit_evaluate(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = vader_bytecode_bc_single_result(l7);
    vader_c_emit_push_into_temporary(l0, l4, l9);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
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
        vader_array_t* _a2_arr = vader_array_new(50u, 0u, 13u, 666u);
        l9 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 193u);
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
            l21 = vader_c_emit_c_ast_verbatim(1878u);
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l20)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t4 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) INT32_C(0), 196u);
            l22 = ((uint8_t) t4.payload.i);
            t4 = vader_c_emit_coerce_expr(l2, l21, (uint8_t) 19, l22);
            vader_array_t* _a7_arr = vader_array_new(145u, 1u, 13u, 1205u);
            ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t4.payload.obj;
            l23 = (void*) _a7_arr;
            t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l20)->f_params)->length;
            l24 = (((int32_t) (size_t) t0) - INT32_C(1));
            l25 = INT32_C(0);
            while ((l25 < l24)) {
                l26 = std_core_new_byte_buffer((size_t) 21);
                l27 = (size_t) 0;
                l27 = std_core_write_string_at(l26, l27, 1012u);
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
                t4 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l31, 196u);
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
                vader_obj_header_init(_a9_obj, 677u);
                _a9_obj->f_expression = l34;
                l36 = (void*) _a9_obj;
                vader_array_t* _a10_arr = vader_array_new(49u, 0u, 13u, 661u);
                t8 = (void*) _a10_arr;
                vader_struct_vader_c_emit_c_ast_CReturn_t* _a11_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
                vader_obj_header_init(_a11_obj, 698u);
                _a11_obj->f_stores = t8;
                _a11_obj->f_value = vader_box_obj(0u, NULL);
                _a11_obj->f_snapshot_type = 0u;
                _a11_obj->f_pops_frame = false;
                l37 = (void*) _a11_obj;
                vader_array_t* _a12_arr = vader_array_new(148u, 2u, 13u, 1216u);
                ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l37;
                ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l36;
                l35 = (void*) _a12_arr;
            } else {
                vader_array_t* _a13_arr = vader_array_new(49u, 0u, 13u, 661u);
                l38 = (void*) _a13_arr;
                l39 = vader_bytecode_bc_single_result(l20);
                l40 = vader_bytecode_bc_single_result(l8);
                l41 = vader_c_emit_dispatcher_result(l2, l34, l39, l40);
                vader_struct_vader_c_emit_c_ast_CReturn_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
                vader_obj_header_init(_a14_obj, 698u);
                _a14_obj->f_stores = l38;
                _a14_obj->f_value = l41;
                _a14_obj->f_snapshot_type = 0u;
                _a14_obj->f_pops_frame = false;
                t8 = (void*) _a14_obj;
                vader_array_t* _a15_arr = vader_array_new(148u, 1u, 13u, 1216u);
                ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t8;
                l35 = (void*) _a15_arr;
            }
            t3 = ((vader_struct_vader_bytecode_VtableEntry_t*) l14)->f_receiver_type_index;
            t4 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t3));
            vader_struct_vader_c_emit_c_ast_CCase_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCase_t));
            vader_obj_header_init(_a16_obj, 666u);
            _a16_obj->f_value = t4;
            _a16_obj->f_body = l35;
            l42 = (void*) _a16_obj;
            vader_array_push((vader_array_t*) l9, vader_ref_box(l42));
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
        }
        l43 = ((vader_struct_vader_bytecode_VtableRow_t*) l7)->f_key;
        t5 = concat_2(2342u, l43);
        t6 = vader_c_emit_c_string_lit(t5);
        t4 = vader_c_emit_c_ast_verbatim(t6);
        vader_array_t* _a17_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t4.payload.obj;
        l44 = (void*) _a17_arr;
        t4 = vader_c_emit_c_ast_call(2318u, l44);
        vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
        vader_obj_header_init(_a18_obj, 677u);
        _a18_obj->f_expression = t4;
        l45 = (void*) _a18_obj;
        t4 = vader_c_emit_c_ast_verbatim(1878u);
        vader_struct_vader_c_emit_c_ast_CMember_t* _a19_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a19_obj, 691u);
        _a19_obj->f_base = t4;
        _a19_obj->f_member = 2055u;
        _a19_obj->f_arrow = false;
        l46 = (void*) _a19_obj;
        vader_array_t* _a20_arr = vader_array_new(148u, 1u, 13u, 1216u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l45;
        l47 = (void*) _a20_arr;
        vader_struct_vader_c_emit_c_ast_CSwitch_t* _a21_obj = (vader_struct_vader_c_emit_c_ast_CSwitch_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSwitch_t));
        vader_obj_header_init(_a21_obj, 707u);
        _a21_obj->f_subject = vader_ref_box(l46);
        _a21_obj->f_cases = l9;
        _a21_obj->f_default_body = vader_ref_box(l47);
        t8 = (void*) _a21_obj;
        vader_array_t* _a22_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t8;
        l48 = (void*) _a22_arr;
        t7 = vader_bytecode_bc_single_result(l8);
        if (t7 != INT32_C(16)) {
            vader_array_push((vader_array_t*) l48, vader_ref_box(l45));
        }
        l49 = ((vader_struct_vader_bytecode_VtableRow_t*) l7)->f_key;
        l50 = vader_c_emit_dispatcher_signature(l0, l49, l8);
        vader_array_t* _a23_arr = vader_array_new(146u, 0u, 13u, 1209u);
        l51 = (void*) _a23_arr;
        vader_struct_vader_c_emit_c_ast_CBlock_t* _a24_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
        vader_obj_header_init(_a24_obj, 663u);
        _a24_obj->f_body = l48;
        l52 = (void*) _a24_obj;
        vader_struct_vader_c_emit_c_ast_CFunction_t* _a25_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
        vader_obj_header_init(_a25_obj, 680u);
        _a25_obj->f_signature = l50;
        _a25_obj->f_prologue = l51;
        _a25_obj->f_body = l52;
        l53 = (void*) _a25_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l53));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a26_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a26_arr->buf)[_a26_arr->offset + 0u] = vader_box_string(190u, 2340u);
    t8 = (void*) _a26_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a27_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a27_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(147u, 0u, 13u, 1214u);
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
        vader_obj_header_init(_a2_obj, 697u);
        _a2_obj->f_signature = t2;
        l9 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a3_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a3_arr->buf)[_a3_arr->offset + 0u] = vader_box_string(190u, 2341u);
    t2 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a4_obj, 700u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_c_emit_StructOffsets_t* _a3_obj = (vader_struct_vader_c_emit_StructOffsets_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StructOffsets_t));
    vader_obj_header_init(_a3_obj, 659u);
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
    if (l0.tag == 654u) {
        l2 = true;
    } else if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
        l2 = t1 == l1;
    } else if (l0.tag == 658u) {
        l2 = false;
    } else if (l0.tag == 655u) {
        l2 = false;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$entry_needs_materialise");
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
    vader_obj_header_init(_a0_obj, 694u);
    _a0_obj->f_type = 2337u;
    _a0_obj->f_name = 1369u;
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
    if (l7.tag == 493u) {
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
    t1 = vader_c_emit_c_ast_verbatim(287u);
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
    vader_obj_header_init(_a0_obj, 702u);
    _a0_obj->f_storage = l3;
    _a0_obj->f_inline_v = false;
    _a0_obj->f_result = 2247u;
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
    vader_obj_header_init(_a0_obj, 677u);
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
    if (l0.tag == 658u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackTemporary_t*) t0)->f_temporary;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackLit_t*) t0)->f_expression;
    } else if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
        vader_struct_vader_c_emit_c_ast_CLocal_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
        vader_obj_header_init(_a0_obj, 689u);
        _a0_obj->f_slot = t2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackExpr_t*) t0)->f_expression;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$expression_of");
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_extern_c_type(uint8_t l0) {
    vader_string_t t0;
    if (l0 == INT32_C(14)) {
        return 1296u;
    }
    t0 = vader_c_emit_c_type_for_val_bare(l0);
    return t0;
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
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 694u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        t0 = vader_c_emit_extern_parameter_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l1, l4);
        vader_struct_vader_c_emit_c_ast_CParameter_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
        vader_obj_header_init(_a1_obj, 694u);
        _a1_obj->f_type = t0;
        _a1_obj->f_name = 0u;
        l5 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    l7 = vader_bytecode_bc_single_result_type(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
    t2 = vader_c_emit_is_abi_nullable_pointer(l1, l7);
    if (t2) {
        l6 = 2337u;
    } else {
        t3 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature);
        l6 = vader_c_emit_extern_c_type(t3);
    }
    l8 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a2_obj, 702u);
    _a2_obj->f_storage = (uint8_t) 2;
    _a2_obj->f_inline_v = false;
    _a2_obj->f_result = l6;
    _a2_obj->f_name = l8;
    _a2_obj->f_parameters = l2;
    t4 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CPrototype_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CPrototype_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrototype_t));
    vader_obj_header_init(_a3_obj, 697u);
    _a3_obj->f_signature = t4;
    t4 = (void*) _a3_obj;
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
        t1 = vader_c_emit_pointer_to(2336u, l3);
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
        t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l2, 196u);
        t1 = vader_c_emit_c_type_for_val_bare(((uint8_t) t2.payload.i));
        t3 = vader_c_emit_pointer_to(t1, l3);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_types);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
    l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l2];
    t0 = vader_c_emit_is_abi_nullable_pointer(l1, l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return 2337u; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_params);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
    t2 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l2, 196u);
    t1 = vader_c_emit_extern_c_type(((uint8_t) t2.payload.i));
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 673u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    l4 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a1_obj, 682u);
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
        l3 = true;
    } else {
        l3 = l2 == INT32_C(14);
    }
    return l3;
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
    l3 = concat_2(l0, 229u);
    l4 = vader_c_emit_sanitise(l2);
    l4 = concat_2(1444u, l4);
    t0 = vader_c_emit_c_ast_pointer_member(l3, l1, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_find_erased_siblings(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    size_t l3, l7, l8, l16, l19, l24;
    vader_box_t l4 = vader_box_null();
    bool l6, l9, l10, l13, l14, l15, l22;
    int32_t l11, l12, l20, l21, l23;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    size_t t5;
    int32_t t6;
    vader_box_t* gc_roots[2] = { &l4, &t4 };
    void** gc_raw_roots[6] = { &l0, &l2, &l5, &l17, &l18, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a0_arr;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (l4.tag == 493u) {
        l5 = l4.payload.obj;
        t1 = vader_c_emit_struct_all_ref(l0, l5);
        if (t1) {
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l4.payload.obj;
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields)->length;
        t2 = l4.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_name;
        l6 = std_string_string_Contains_contains(t3, 731u);
        l7 = ((vader_array_t*) l0)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            if (((int32_t) (size_t) l8) == l1) {
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            t4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            if (t4.tag == 493u) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
                t4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                l5 = t4.payload.obj;
                t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_fields)->length;
                if (t5 != l3) {
                    t0 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t0;
                    continue;
                }
                t2 = l4.payload.obj;
                t6 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_symbol_id;
                if ((t6 >= INT32_C(0))) {
                    l11 = ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_symbol_id;
                    t2 = l4.payload.obj;
                    l12 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_symbol_id;
                    l10 = l11 == l12;
                } else {
                    l10 = false;
                }
                if (l10) {
                    l9 = true;
                } else {
                    if (l6) {
                        t3 = ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_name;
                        l13 = std_string_string_Contains_contains(t3, 731u);
                    } else {
                        l13 = false;
                    }
                    l9 = l13;
                }
                if (l9) {
                    l14 = true;
                    l15 = false;
                    l16 = (size_t) 0;
                    while ((l16 < l3)) {
                        t2 = l4.payload.obj;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l16)
                        l17 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l16);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_fields);
                        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
                        l18 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l16);
                        t6 = ((vader_struct_vader_bytecode_BcField_t*) l18)->f_type_index;
                        t0 = ((int64_t) (int32_t) t6);
                        l19 = (size_t) (int64_t) t0;
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l19)
                        t4 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l19);
                        if (t4.tag == 490u) {
                            l15 = true;
                        } else {
                            l20 = ((vader_struct_vader_bytecode_BcField_t*) l18)->f_type_index;
                            l21 = ((vader_struct_vader_bytecode_BcField_t*) l17)->f_type_index;
                            if (l20 != l21) {
                                l14 = false;
                            }
                        }
                        t0 = (l16 + INT64_C(1));
                        l16 = (size_t) (int64_t) t0;
                    }
                    if (l14) {
                        l22 = l15;
                    } else {
                        l22 = false;
                    }
                    if (l22) {
                        l23 = ((int32_t) (size_t) l8);
                        vader_array_push_i32((vader_array_t*) l2, l23);
                    }
                }
                l24 = (size_t) 1;
                t0 = (l8 + l24);
                l8 = (size_t) (int64_t) t0;
                continue;
            }
            l24 = (size_t) 1;
            t0 = (l8 + l24);
            l8 = (size_t) (int64_t) t0;
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_find_main(void* l0, vader_string_t l1) {
    size_t l2, l3;
    void* l4;
    bool l5;
    vader_string_t t0;
    size_t t1;
    int64_t t2;
    bool t3;
    if (l1 != 0u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
            if (t0 == l1) {
                t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
                l5 = (t1 > INT64_C(0));
            } else {
                l5 = false;
            }
            if (l5) {
                return ((int32_t) (size_t) l3);
            }
            t2 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t2;
        }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_is_main;
        if (t3) {
            t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
            l5 = (t1 > INT64_C(0));
        } else {
            l5 = false;
        }
        if (l5) {
            return ((int32_t) (size_t) l3);
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
}

static vader_box_t vader_c_emit_find_vtable_row(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    size_t l3, l4;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_vtables;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_key;
        if (t0 == l1) {
            return vader_ref_box(l5);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
}

static vader_string_t vader_c_emit_float_lit(double l0) {
    vader_string_t l1 = 0;
    bool l2;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core_f64_Display_to_string(l0);
    if (l1 == 1611u) {
        { vader_gc_top = gc_frame.prev; return 736u; }
    }
    if (l1 == 257u) {
        { vader_gc_top = gc_frame.prev; return 198u; }
    }
    if (l1 == 1790u) {
        { vader_gc_top = gc_frame.prev; return 737u; }
    }
    t0 = std_string_string_Contains_contains(l1, 258u);
    if (t0) {
        l2 = true;
    } else {
        l2 = std_string_string_Contains_contains(l1, 1349u);
    }
    if (l2) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_2(l1, 265u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (t0.tag == 489u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            t1 = t0.payload.obj;
            t2 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
            if (t2) {
                l5 = ((int32_t) (size_t) l4);
                l6 = vader_c_emit_tag_equals(l1, l5);
                vader_array_push((vader_array_t*) l2, l6);
            }
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    t4 = ((vader_array_t*) l2)->length;
    if (t4 == INT64_C(0)) {
        t0 = vader_c_emit_c_ast_verbatim(287u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_c_emit_c_ast_any_of(l2);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a3_obj, 695u);
    _a3_obj->f_inner = t0;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_fn_builds_stack_object(void* l0) {
    size_t l1, l2;
    vader_box_t l3;
    void* t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    l2 = (size_t) 0;
    while ((l2 < l1)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l3.tag == 622u) {
            t0 = l3.payload.obj;
            t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
            if (t1) {
                return true;
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 516u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
            t1 = std_core____Contains_contains__i32(l1, l5);
            if (t1) {
                return true;
            }
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return false;
}

static bool vader_c_emit_fn_has_direct_alloc(void* l0) {
    size_t l1, l2;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    l2 = (size_t) 0;
    while ((l2 < l1)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = vader_c_emit_op_allocates(t0);
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
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l5, &t2 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t3 };
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
    if (l2) {
        l5 = std_core_new_byte_buffer((size_t) 84);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l5, l3, 1209u);
        l6 = ((int64_t) (int32_t) l1);
        l3 = std_core_write_int(l5, l3, l6);
        l3 = std_core_write_string_at(l5, l3, 244u);
        t1 = std_core_finish_buffer(l5, l3);
        vader_host_std_abort_panic(t1);
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
    t3 = vader_c_emit_sanitise(t1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
        vader_obj_header_init(_a0_obj, 677u);
        _a0_obj->f_expression = l3;
        l5 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(49u, 0u, 13u, 661u);
        l6 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l7 = (void*) _a2_arr;
        l8 = vader_c_emit_c_ast_call(2244u, l7);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a3_obj, 698u);
        _a3_obj->f_stores = l6;
        _a3_obj->f_value = l8;
        _a3_obj->f_snapshot_type = 0u;
        _a3_obj->f_pops_frame = false;
        l6 = (void*) _a3_obj;
        vader_array_t* _a4_arr = vader_array_new(146u, 2u, 13u, 1209u);
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
    vader_array_t* _a5_arr = vader_array_new(49u, 0u, 13u, 661u);
    t0 = (void*) _a5_arr;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a6_obj, 698u);
    _a6_obj->f_stores = t0;
    _a6_obj->f_value = l8;
    _a6_obj->f_snapshot_type = 0u;
    _a6_obj->f_pops_frame = false;
    t0 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(146u, 1u, 13u, 1209u);
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
    l4 = vader_c_emit_c_ast_verbatim(1867u);
    l5 = vader_c_emit_c_ast_verbatim(1839u);
    l6 = vader_bytecode_bc_single_result_type(l0);
    t0 = vader_bytecode_bc_single_result(l0);
    if (t0 == INT32_C(16)) {
        vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
        vader_obj_header_init(_a0_obj, 677u);
        _a0_obj->f_expression = l2;
        t1 = (void*) _a0_obj;
        vader_struct_vader_c_emit_ForwardedResult_t* _a1_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a1_obj, 648u);
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
        l9 = vader_c_emit_c_ast_declaration(2337u, 1867u, l2);
        l8 = vader_c_emit_null_or(l4, l8);
        vader_struct_vader_c_emit_ForwardedResult_t* _a2_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a2_obj, 648u);
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
        l8 = vader_c_emit_c_ast_cast(1620u, l8);
        l8 = vader_c_emit_box_call(1559u, l6, l8);
        l9 = vader_c_emit_c_ast_declaration(1296u, 1867u, l2);
        l8 = vader_c_emit_null_or(l4, l8);
        l8 = vader_c_emit_c_ast_declaration(2247u, 1839u, l8);
        vader_struct_vader_c_emit_ForwardedResult_t* _a3_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a3_obj, 648u);
        _a3_obj->f_capture = l9;
        _a3_obj->f_returns = false;
        _a3_obj->f_settle = l8;
        _a3_obj->f_returned = l5;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_bc_single_result(l0);
    if (t0 == INT32_C(14)) {
        l8 = vader_c_emit_c_ast_verbatim(148u);
        l9 = vader_c_emit_c_ast_number(INT64_C(0));
        vader_array_t* _a4_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l8.payload.obj;
        l10 = (void*) _a4_arr;
        l8 = vader_c_emit_c_ast_call(2240u, l10);
        vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
        vader_obj_header_init(_a5_obj, 711u);
        _a5_obj->f_text = 489u;
        l10 = (void*) _a5_obj;
        l9 = vader_c_emit_c_ast_binary((uint8_t) 11, l4, vader_ref_box(l10));
        l11 = vader_c_emit_interned(l4);
        vader_struct_vader_c_emit_c_ast_CConditional_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
        vader_obj_header_init(_a6_obj, 670u);
        _a6_obj->f_condition = l9;
        _a6_obj->f_then_value = l8;
        _a6_obj->f_else_value = l11;
        l10 = (void*) _a6_obj;
        l8 = vader_c_emit_c_ast_declaration(1296u, 1867u, l2);
        l9 = vader_c_emit_c_ast_declaration(2310u, 1839u, vader_ref_box(l10));
        vader_struct_vader_c_emit_ForwardedResult_t* _a7_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a7_obj, 648u);
        _a7_obj->f_capture = l8;
        _a7_obj->f_returns = false;
        _a7_obj->f_settle = l9;
        _a7_obj->f_returned = l5;
        t1 = (void*) _a7_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3) {
        vader_array_t* _a8_arr = vader_array_new(49u, 0u, 13u, 661u);
        t1 = (void*) _a8_arr;
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a9_obj, 698u);
        _a9_obj->f_stores = t1;
        _a9_obj->f_value = l2;
        _a9_obj->f_snapshot_type = 0u;
        _a9_obj->f_pops_frame = false;
        t1 = (void*) _a9_obj;
        vader_struct_vader_c_emit_ForwardedResult_t* _a10_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
        vader_obj_header_init(_a10_obj, 648u);
        _a10_obj->f_capture = vader_ref_box(t1);
        _a10_obj->f_returns = true;
        _a10_obj->f_settle = vader_box_obj(0u, NULL);
        _a10_obj->f_returned = vader_box_obj(0u, NULL);
        t1 = (void*) _a10_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_bc_single_result(l0);
    t3 = vader_c_emit_c_type_for_val_bare(t0);
    t4 = vader_c_emit_c_ast_declaration(t3, 1867u, l2);
    vader_struct_vader_c_emit_ForwardedResult_t* _a11_obj = (vader_struct_vader_c_emit_ForwardedResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ForwardedResult_t));
    vader_obj_header_init(_a11_obj, 648u);
    _a11_obj->f_capture = t4;
    _a11_obj->f_returns = false;
    _a11_obj->f_settle = vader_box_obj(0u, NULL);
    _a11_obj->f_returned = l4;
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
    t0 = concat_2(l0, 255u);
    l2 = vader_c_emit_c_ast_verbatim(t0);
    l3 = std_core_new_byte_buffer((size_t) 21);
    l4 = (size_t) 0;
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 2134u);
    t0 = std_core_finish_buffer(l3, l4);
    l6 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_binary((uint8_t) 3, l2, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_function_definition(void* l0, int32_t l1, void* l2) {
    bool l3, l12, l14, l20, l23;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    int32_t l7, l26;
    vader_string_t l8 = 0;
    vader_string_t l15 = 0;
    vader_string_t l19 = 0;
    vader_string_t l32 = 0;
    vader_string_t l33 = 0;
    size_t l9, l10, l16, l17, l21, l22, l24;
    vader_box_t l11 = vader_box_null(), l13 = vader_box_null(), l25 = vader_box_null(), l34 = vader_box_null(), l36 = vader_box_null(), l37 = vader_box_null(), l38 = vader_box_null();
    int64_t l18;
    uint64_t l35;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t t5 = vader_box_null();
    size_t t6;
    vader_box_t* gc_roots[8] = { &l11, &l13, &l25, &l34, &l36, &l37, &l38, &t5 };
    void** gc_raw_roots[11] = { &l0, &l2, &l4, &l5, &l6, &l27, &l28, &l29, &l30, &l31, &t2 };
    vader_string_t* gc_atom_roots[6] = { &l8, &l15, &l19, &l32, &l33, &t4 };
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
    l9 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
    l10 = (size_t) 0;
    while ((l10 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
        l11 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l10);
        t0 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_drop_call_result;
        if (t0) {
            l12 = l11.tag == 525u;
        } else {
            l12 = false;
        }
        if (l12) {
            ((vader_struct_vader_c_emit_FnState_t*) l4)->f_drop_call_result = false;
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
            continue;
        }
        t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_release;
        if (!(t0)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
            l13 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
            if (!(l13.tag == 0u)) {
                t2 = l13.payload.obj;
                t3 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_line;
                if (t3 != l7) {
                    l14 = true;
                } else {
                    t2 = l13.payload.obj;
                    t4 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_file;
                    l14 = t4 != l8;
                }
                if (l14) {
                    t2 = l13.payload.obj;
                    t4 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_file;
                    l15 = vader_c_emit_c_string_lit(t4);
                    l16 = vader_host_std_core_byte_len(l15);
                    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l16));
                    l17 = (size_t) 0;
                    l17 = std_core_write_string_at(l5, l17, 154u);
                    t2 = l13.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_line;
                    l18 = ((int64_t) (int32_t) t3);
                    l17 = std_core_write_int(l5, l17, l18);
                    l17 = std_core_write_string_at(l5, l17, 8u);
                    l17 = std_core_write_string_at(l5, l17, l15);
                    l19 = std_core_finish_buffer(l5, l17);
                    vader_c_emit_directive(l4, l19);
                    t2 = l13.payload.obj;
                    l7 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_line;
                    t2 = l13.payload.obj;
                    l8 = ((vader_struct_vader_bytecode_DebugPos_t*) t2)->f_file;
                }
            }
        }
        if (l11.tag == 516u) {
            l20 = true;
        } else {
            l20 = l11.tag == 517u;
        }
        if (l20) {
            t1 = (l10 + INT64_C(1));
            l21 = (size_t) (int64_t) t1;
            l22 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
            if ((l21 < l22)) {
                l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body;
                t1 = (l10 + INT64_C(1));
                l24 = (size_t) (int64_t) t1;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l24)
                t5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l24);
                l23 = t5.tag == 525u;
            } else {
                l23 = false;
            }
            if (l23) {
                l25 = l11;
                t6 = vader_c_emit_callee_result_arity(l0, l25);
                if ((t6 <= INT64_C(1))) {
                    ((vader_struct_vader_c_emit_FnState_t*) l4)->f_drop_call_result = true;
                }
            }
        }
        l26 = ((int32_t) (size_t) l10);
        vader_c_emit_emit_op(l4, l26, l11);
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_no_frame;
    if (!(t0)) {
        t0 = vader_c_emit_c_ast_ends_with_return(((vader_struct_vader_c_emit_FnState_t*) l4)->f_root);
        l12 = !(t0);
    } else {
        l12 = false;
    }
    if (l12) {
        l5 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) ((vader_struct_vader_c_emit_FnState_t*) l4)->f_root)->f_body;
        vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
        vader_obj_header_init(_a3_obj, 711u);
        _a3_obj->f_text = 2284u;
        l6 = (void*) _a3_obj;
        vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
        vader_obj_header_init(_a4_obj, 711u);
        _a4_obj->f_text = 1512u;
        l27 = (void*) _a4_obj;
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a5_obj, 661u);
        _a5_obj->f_target = vader_ref_box(l6);
        _a5_obj->f_value = vader_ref_box(l27);
        _a5_obj->f_operator = vader_box_obj(0u, NULL);
        l6 = (void*) _a5_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    }
    l5 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_root;
    l6 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_temporaries;
    l5 = vader_c_emit_c_ast_coalesce_temporaries(l5, l6);
    vader_c_emit_c_ast_structure_loops(((vader_struct_vader_c_emit_FnState_t*) l4)->f_root);
    vader_array_t* _a6_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l27 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l28 = (void*) _a8_arr;
    if (!(l3)) {
        l29 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params;
        l9 = ((vader_array_t*) l29)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l29);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
            t5 = vader_array_read_u8(_a9_slotarr, _a9_slotarr->offset + (size_t) l10, 196u);
            if (((int32_t) t5.payload.i) == INT32_C(18)) {
                vader_struct_vader_c_emit_c_ast_CLocal_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
                vader_obj_header_init(_a10_obj, 689u);
                _a10_obj->f_slot = ((int32_t) (size_t) l10);
                t2 = (void*) _a10_obj;
                l11 = vader_c_emit_c_ast_address_of(vader_ref_box(t2));
                vader_array_push((vader_array_t*) l27, l11);
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l29);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
                t5 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l10, 196u);
                if (((int32_t) t5.payload.i) == INT32_C(14)) {
                    vader_struct_vader_c_emit_c_ast_CLocal_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
                    vader_obj_header_init(_a12_obj, 689u);
                    _a12_obj->f_slot = ((int32_t) (size_t) l10);
                    t2 = (void*) _a12_obj;
                    l13 = vader_c_emit_c_ast_address_of(vader_ref_box(t2));
                    vader_array_push((vader_array_t*) l28, l13);
                } else {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l29);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l10)
                    t5 = vader_array_read_u8(_a13_slotarr, _a13_slotarr->offset + (size_t) l10, 196u);
                    t0 = vader_c_emit_is_ref_val(((uint8_t) t5.payload.i));
                    if (t0) {
                        vader_struct_vader_c_emit_c_ast_CLocal_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
                        vader_obj_header_init(_a14_obj, 689u);
                        _a14_obj->f_slot = ((int32_t) (size_t) l10);
                        t2 = (void*) _a14_obj;
                        l25 = vader_c_emit_c_ast_address_of(vader_ref_box(t2));
                        vader_array_push((vader_array_t*) l6, l25);
                    }
                }
            }
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
    }
    vader_array_t* _a15_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l29 = (void*) _a15_arr;
    vader_c_emit_emit_local_decls(l2, l29, l6, l27, l28, l3);
    vader_c_emit_emit_temporary_declarations(l5, l29, l6, l27, l28, l3);
    if (!(l3)) {
        t6 = ((vader_array_t*) l6)->length;
        if ((t6 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2248u, 1514u, l6);
            vader_array_push((vader_array_t*) l29, l11);
        }
        t6 = ((vader_array_t*) l27)->length;
        if ((t6 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2338u, 1513u, l27);
            vader_array_push((vader_array_t*) l29, l11);
        }
        t6 = ((vader_array_t*) l6)->length;
        if ((t6 > INT64_C(0))) {
            l8 = 1514u;
        } else {
            l8 = 489u;
        }
        t6 = ((vader_array_t*) l27)->length;
        if ((t6 > INT64_C(0))) {
            l15 = 1513u;
        } else {
            l15 = 489u;
        }
        l9 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l4)->f_stack_storages)->length;
        if ((l9 > INT64_C(0))) {
            l19 = 1515u;
        } else {
            l19 = 489u;
        }
        vader_array_t* _a16_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l5 = (void*) _a16_arr;
        l30 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_stack_storages;
        l10 = ((vader_array_t*) l30)->length;
        l16 = (size_t) 0;
        while ((l16 < l10)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l30);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l16)
            l31 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l16);
            l32 = ((vader_struct_vader_c_emit_StackStorage_t*) l31)->f_cname;
            l33 = ((vader_struct_vader_c_emit_StackStorage_t*) l31)->f_storage;
            l11 = vader_c_emit_c_ast_verbatim(2374u);
            l13 = vader_c_emit_c_ast_declaration(l32, l33, l11);
            vader_array_push((vader_array_t*) l29, l13);
            t4 = ((vader_struct_vader_c_emit_StackStorage_t*) l31)->f_storage;
            t5 = vader_c_emit_c_ast_verbatim(t4);
            l25 = vader_c_emit_c_ast_address_of(t5);
            l34 = vader_c_emit_c_ast_cast(2337u, l25);
            vader_array_push((vader_array_t*) l5, l34);
            t1 = (l16 + INT64_C(1));
            l16 = (size_t) (int64_t) t1;
        }
        if ((l9 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2337u, 1515u, l5);
            vader_array_push((vader_array_t*) l29, l11);
        }
        l10 = ((vader_array_t*) l28)->length;
        if ((l10 > INT64_C(0))) {
            l11 = vader_c_emit_c_ast_array_declaration(2311u, 1510u, l28);
            vader_array_push((vader_array_t*) l29, l11);
        }
        l11 = vader_c_emit_c_ast_verbatim(2284u);
        l5 = std_core_new_byte_buffer((size_t) 21);
        l16 = (size_t) 0;
        t6 = ((vader_array_t*) l6)->length;
        t1 = ((int64_t) (size_t) t6);
        l35 = (uint64_t) (int64_t) t1;
        l16 = std_core_write_unsigned(l5, l16, l35);
        l16 = std_core_write_string_at(l5, l16, 2134u);
        t4 = std_core_finish_buffer(l5, l16);
        l13 = vader_c_emit_c_ast_verbatim(t4);
        l5 = std_core_new_byte_buffer((size_t) 21);
        l16 = (size_t) 0;
        t6 = ((vader_array_t*) l27)->length;
        t1 = ((int64_t) (size_t) t6);
        l35 = (uint64_t) (int64_t) t1;
        l16 = std_core_write_unsigned(l5, l16, l35);
        l16 = std_core_write_string_at(l5, l16, 2134u);
        t4 = std_core_finish_buffer(l5, l16);
        l25 = vader_c_emit_c_ast_verbatim(t4);
        l34 = vader_c_emit_c_ast_verbatim(l8);
        l36 = vader_c_emit_c_ast_verbatim(l15);
        l5 = std_core_new_byte_buffer((size_t) 21);
        l16 = (size_t) 0;
        t1 = ((int64_t) (size_t) l9);
        l35 = (uint64_t) (int64_t) t1;
        l16 = std_core_write_unsigned(l5, l16, l35);
        l16 = std_core_write_string_at(l5, l16, 2134u);
        t4 = std_core_finish_buffer(l5, l16);
        l37 = vader_c_emit_c_ast_verbatim(t4);
        l38 = vader_c_emit_c_ast_verbatim(l19);
        vader_array_t* _a18_arr = vader_array_new(145u, 7u, 13u, 1205u);
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 6u] = l38.payload.obj;
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 5u] = l37.payload.obj;
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 4u] = l36.payload.obj;
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 3u] = l34.payload.obj;
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 2u] = l25.payload.obj;
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 1u] = l13.payload.obj;
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = l11.payload.obj;
        l5 = (void*) _a18_arr;
        if ((l10 > INT64_C(0))) {
            l6 = std_core_new_byte_buffer((size_t) 21);
            l9 = (size_t) 0;
            t1 = ((int64_t) (size_t) l10);
            l35 = (uint64_t) (int64_t) t1;
            l9 = std_core_write_unsigned(l6, l9, l35);
            l9 = std_core_write_string_at(l6, l9, 2134u);
            t4 = std_core_finish_buffer(l6, l9);
            l11 = vader_c_emit_c_ast_verbatim(t4);
            l13 = vader_c_emit_c_ast_verbatim(1510u);
            vader_array_t* _a19_arr = vader_array_new(145u, 2u, 13u, 1205u);
            ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 1u] = l13.payload.obj;
            ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = l11.payload.obj;
            l6 = (void*) _a19_arr;
            vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
        }
        vader_struct_vader_c_emit_c_ast_CInitializerList_t* _a20_obj = (vader_struct_vader_c_emit_c_ast_CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInitializerList_t));
        vader_obj_header_init(_a20_obj, 687u);
        _a20_obj->f_elements = l5;
        l5 = (void*) _a20_obj;
        l11 = vader_c_emit_c_ast_declaration(2281u, 1511u, vader_ref_box(l5));
        vader_array_push((vader_array_t*) l29, l11);
        l11 = vader_c_emit_c_ast_verbatim(2284u);
        t5 = vader_c_emit_c_ast_verbatim(1511u);
        l13 = vader_c_emit_c_ast_address_of(t5);
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a21_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a21_obj, 661u);
        _a21_obj->f_target = l11;
        _a21_obj->f_value = l13;
        _a21_obj->f_operator = vader_box_obj(0u, NULL);
        l5 = (void*) _a21_obj;
        vader_array_push((vader_array_t*) l29, vader_ref_box(l5));
    }
    l5 = vader_c_emit_signature_for(l0, l1);
    l4 = ((vader_struct_vader_c_emit_FnState_t*) l4)->f_root;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a22_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a22_obj, 680u);
    _a22_obj->f_signature = l5;
    _a22_obj->f_prologue = l29;
    _a22_obj->f_body = l4;
    t2 = (void*) _a22_obj;
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
    l1 = concat_2(l0, 229u);
    t0 = concat_3(1932u, l0, 206u);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(2279u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(49u, 0u, 13u, 661u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l2 = (void*) _a1_arr;
    t0 = vader_c_emit_c_ast_call(2282u, l2);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a2_obj, 691u);
    _a2_obj->f_base = t0;
    _a2_obj->f_member = l0;
    _a2_obj->f_arrow = false;
    l2 = (void*) _a2_obj;
    l3 = vader_c_emit_c_ast_cast(1619u, vader_ref_box(l2));
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a3_obj, 698u);
    _a3_obj->f_stores = l1;
    _a3_obj->f_value = l3;
    _a3_obj->f_snapshot_type = 0u;
    _a3_obj->f_pops_frame = false;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_global_storage(bool l0) {
    uint8_t l1;
    if (l0) {
        l1 = (uint8_t) 1;
    } else {
        l1 = (uint8_t) 0;
    }
    return l1;
}

static bool vader_c_emit_has_str_data(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t l4;
    int64_t t0;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 492u) {
            return true;
        }
        if (l4.tag == 479u) {
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
    t0 = concat_2(2288u, l1);
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
    l5 = vader_c_emit_value_parameters(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l1)->f_signature)->f_params, 1012u);
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a0_obj, 702u);
    _a0_obj->f_storage = (uint8_t) 0;
    _a0_obj->f_inline_v = l2;
    _a0_obj->f_result = l3;
    _a0_obj->f_name = l4;
    _a0_obj->f_parameters = l5;
    l5 = (void*) _a0_obj;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    t1 = vader_c_emit_shim_body(l1, l6);
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 663u);
    _a1_obj->f_body = t1;
    l6 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l7 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CFunction_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFunction_t));
    vader_obj_header_init(_a3_obj, 680u);
    _a3_obj->f_signature = l5;
    _a3_obj->f_prologue = l7;
    _a3_obj->f_body = l6;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_imports_header_name(vader_string_t l0) {
    size_t l1;
    bool t0;
    size_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t3, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_ends_with(l0, 276u);
    if (t0) {
        t1 = std_core_len(l0);
        t2 = (t1 - INT64_C(8));
        l1 = (size_t) (int64_t) t2;
        t3 = vader_string_slice_codepoints(l0, INT64_C(0), l1);
        t4 = concat_2(t3, 267u);
        { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = concat_2(l0, 267u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_include_of(vader_string_t l0) {
    bool l1, l4;
    vader_string_t l2 = 0;
    size_t l3;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[1] = { &t2 };
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
        l4 = std_string_starts_with(l0, 328u);
    } else {
        l4 = false;
    }
    if (l4) {
        l4 = std_string_ends_with(l0, 348u);
    } else {
        l4 = false;
    }
    if (l4) {
        vader_struct_vader_c_emit_c_ast_CInclude_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
        vader_obj_header_init(_a0_obj, 685u);
        _a0_obj->f_path = l2;
        _a0_obj->f_system = true;
        t2 = (void*) _a0_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        l1 = std_string_starts_with(l0, 147u);
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = std_string_ends_with(l0, 147u);
    } else {
        l1 = false;
    }
    if (l1) {
        vader_struct_vader_c_emit_c_ast_CInclude_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
        vader_obj_header_init(_a1_obj, 685u);
        _a1_obj->f_path = l2;
        _a1_obj->f_system = false;
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a2_obj, 685u);
    _a2_obj->f_path = l0;
    _a2_obj->f_system = false;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 374u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CPrinter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CPrinter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CPrinter_t));
    vader_obj_header_init(_a2_obj, 696u);
    _a2_obj->f_out = t0;
    _a2_obj->f_started = false;
    l1 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CInclude_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CInclude_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInclude_t));
    vader_obj_header_init(_a3_obj, 685u);
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
    l3 = std_core_write_string_at(l2, l3, 706u);
    t0 = ((int64_t) (size_t) l0);
    l4 = (uint64_t) (int64_t) t0;
    l3 = std_core_write_unsigned(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 710u);
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
    l5 = std_core_write_string_at(l4, l5, 2134u);
    t0 = std_core_finish_buffer(l4, l5);
    l7 = vader_c_emit_c_ast_verbatim(t0);
    vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l7.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(2289u, l4);
    vader_c_emit_evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_c_emit_internal_fn_flags(void* l0, void* l1, vader_string_t l2) {
    size_t l3, l6, l8, l10, l11, l12;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    int32_t l7, l16;
    bool l14, l15;
    int64_t t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    bool t5;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l9, &l13, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) 0;
    while ((l6 < l3)) {
        l7 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l4, l7);
        vader_array_push_bool((vader_array_t*) l5, false);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l6 = ((vader_array_t*) l1)->length;
    l8 = (size_t) 0;
    while ((l8 < l6)) {
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l10 = ((vader_array_t*) l9)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l11];
            t0 = ((int64_t) (int32_t) t1);
            l12 = (size_t) (int64_t) t0;
            l7 = ((int32_t) (size_t) l8);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12] = (int32_t) l7;
            t0 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t0;
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_exports;
    vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l6 = ((vader_array_t*) l9)->length;
    l8 = (size_t) 0;
    while ((l8 < l6)) {
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        t1 = ((vader_struct_vader_bytecode_BcExport_t*) t2)->f_fn_index;
        t0 = ((int64_t) (int32_t) t1);
        l10 = (size_t) (int64_t) t0;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10] = (uint8_t) true;
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    l6 = ((vader_array_t*) l9)->length;
    l8 = (size_t) 0;
    while ((l8 < l6)) {
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        t2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
        l13 = ((vader_struct_vader_bytecode_VtableRow_t*) t2)->f_entries;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l10 = ((vader_array_t*) l13)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
            t2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
            t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t2)->f_fn_index;
            t0 = ((int64_t) (int32_t) t1);
            l12 = (size_t) (int64_t) t0;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l12)
            ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l12] = (uint8_t) true;
            t0 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t0;
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l9 = vader_c_emit_scan_fn_value_usage(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l6 = (size_t) 0;
    while ((l6 < l3)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l9)->f_fn_ref_type);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
        t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l6];
        if ((t1 >= INT32_C(0))) {
            l14 = true;
        } else {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l9)->f_is_closure);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
            t3 = vader_box_bool(188u, ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l6]);
            l14 = t3.payload.b;
        }
        if (l14) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6] = (uint8_t) true;
        }
        if (l2 != 0u) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
            t2 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6);
            t4 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
            l15 = t4 == l2;
        } else {
            l15 = false;
        }
        if (l15) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
            ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (uint8_t) true;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l6 = (size_t) 0;
    while ((l6 < l3)) {
        vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
        l7 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l6];
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body;
        vader_array_t* _a17_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        l8 = ((vader_array_t*) l9)->length;
        l10 = (size_t) 0;
        while ((l10 < l8)) {
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l10)
            t3 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l10);
            l16 = vader_c_emit_callee_index_of(t3);
            if ((l16 >= INT32_C(0))) {
                t0 = ((int64_t) (int32_t) l16);
                l11 = (size_t) (int64_t) t0;
                vader_array_t* _a18_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l11)
                t1 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l11];
                l14 = t1 != l7;
            } else {
                l14 = false;
            }
            if (l14) {
                t0 = ((int64_t) (int32_t) l16);
                l12 = (size_t) (int64_t) t0;
                vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l12)
                ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l12] = (uint8_t) true;
            }
            t0 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t0;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a20_arr = vader_array_new(6u, 0u, 12u, 188u);
    l4 = (void*) _a20_arr;
    l6 = (size_t) 0;
    {
        vader_array_t* _pc313_hdr = (vader_array_t*) l4;
        size_t _pc313_len = _pc313_hdr->length;
        size_t _pc313_cap = (_pc313_hdr->offset == 0 && !vader_array_is_borrowed(_pc313_hdr) && _pc313_hdr->length >= _pc313_hdr->buf->length) ? _pc313_hdr->capacity : (size_t) 0;
        void* _pc313_slots = _pc313_hdr->buf->slots;
        for (;;) {
            if ((l6 < l3)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
                t3 = vader_box_bool(188u, ((uint8_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6]);
                t5 = t3.payload.b;
                l14 = !(t5);
                if (VADER_LIKELY(_pc313_len < _pc313_cap)) {
                    ((uint8_t*) _pc313_slots)[_pc313_len] = (uint8_t) (l14);
                    _pc313_len += 1;
                } else {
                    _pc313_hdr->length = _pc313_len;
                    if (_pc313_hdr->buf->length < _pc313_len) {
                        _pc313_hdr->buf->length = _pc313_len;
                    }
                    vader_array_push_bool((vader_array_t*) l4, l14);
                    _pc313_hdr = (vader_array_t*) l4;
                    _pc313_len = _pc313_hdr->length;
                    _pc313_cap = (_pc313_hdr->offset == 0 && !vader_array_is_borrowed(_pc313_hdr) && _pc313_hdr->length >= _pc313_hdr->buf->length) ? _pc313_hdr->capacity : (size_t) 0;
                    _pc313_slots = _pc313_hdr->buf->slots;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                continue;
            }
            _pc313_hdr->length = _pc313_len;
            if (_pc313_hdr->buf->length < _pc313_len) {
                _pc313_hdr->buf->length = _pc313_len;
            }
            break;
        }
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    l2 = vader_c_emit_c_ast_call(2028u, l1);
    vader_array_t* _a1_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l2.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a1_arr;
    t0 = vader_c_emit_c_ast_call(2240u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_invalidate_resolve_cache(void* l0, vader_box_t l1) {
    int32_t l2;
    bool l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 597u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        vader_c_emit_drop_resolved_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 598u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        vader_c_emit_drop_resolved_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_c_emit_is_cache_safe(l1);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_no_frame;
    if (t1) {
        l3 = vader_c_emit_is_scope_opening(l1);
    } else {
        l3 = false;
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_c_emit_is_pure_control_flow(l1);
    if (t1) {
        l4 = l1;
        vader_c_emit_keep_pinned_resolves(l0, l4);
    } else {
        vader_array_clear((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays);
    }
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
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return t1.tag == 480u;
}

static bool vader_c_emit_is_abi_nullable_pointer(void* l0, int32_t l1) {
    int32_t l2, l10;
    vader_box_t l3;
    bool l4, l5, l9;
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
    if (l3.tag == 494u) {
        t1 = l3.payload.obj;
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants)->length;
        if (t0 != INT64_C(2)) {
            return false;
        }
        l4 = false;
        l5 = false;
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
            if ((l2 < INT32_C(0))) {
                l9 = true;
            } else {
                t0 = ((vader_array_t*) l0)->length;
                l10 = ((int32_t) (size_t) t0);
                l9 = (l2 >= l10);
            }
            if (l9) {
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                continue;
            }
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
            l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
            if (l3.tag == 489u) {
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
        }
        if (l4) {
            l4 = l5;
        } else {
            l4 = false;
        }
        return l4;
    }
    return false;
}

static bool vader_c_emit_is_abi_nullable_string(void* l0, int32_t l1) {
    bool l2, l5, l9;
    int32_t l3, l10;
    vader_box_t l4;
    void* l6;
    size_t l7, l8;
    size_t t0;
    void* t1;
    int64_t t2;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((vader_array_t*) l0)->length;
        l3 = ((int32_t) (size_t) t0);
        l2 = (l1 >= l3);
    }
    if (l2) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l4.tag == 494u)) {
        return false;
    }
    t1 = l4.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants)->length;
    if (t0 != INT64_C(2)) {
        return false;
    }
    l2 = false;
    l5 = false;
    t1 = l4.payload.obj;
    l6 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        l3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        if ((l3 < INT32_C(0))) {
            l9 = true;
        } else {
            t0 = ((vader_array_t*) l0)->length;
            l10 = ((int32_t) (size_t) t0);
            l9 = (l3 >= l10);
        }
        if (l9) {
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
            continue;
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        if (l4.tag == 489u) {
            t1 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(15)) {
                l2 = true;
            }
            t1 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == INT32_C(14)) {
                l5 = true;
            }
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    if (l2) {
        l2 = l5;
    } else {
        l2 = false;
    }
    return l2;
}

static bool vader_c_emit_is_c_reserved(vader_string_t l0) {
    void* t0;
    bool t1;
    t0 = (void*) &vader_data_13;
    t1 = std_core____Contains_contains__string(t0, l0);
    return t1;
}

static bool vader_c_emit_is_cache_safe(vader_box_t l0) {
    if ((l0.tag == 595u || l0.tag == 596u || l0.tag == 621u)) {
        return true;
    }
    if ((l0.tag == 591u || l0.tag == 592u || l0.tag == 593u)) {
        return true;
    }
    if ((l0.tag == 613u || l0.tag == 614u || l0.tag == 615u)) {
        return true;
    }
    if ((l0.tag == 470u || l0.tag == 471u || l0.tag == 477u)) {
        return true;
    }
    if ((l0.tag == 588u || l0.tag == 589u || l0.tag == 590u || l0.tag == 594u)) {
        return true;
    }
    if ((l0.tag == 610u || l0.tag == 611u || l0.tag == 612u || l0.tag == 616u)) {
        return true;
    }
    if ((l0.tag == 503u || l0.tag == 519u || l0.tag == 532u || l0.tag == 551u || l0.tag == 571u)) {
        return true;
    }
    if ((l0.tag == 521u || l0.tag == 544u || l0.tag == 545u || l0.tag == 602u || l0.tag == 608u || l0.tag == 617u || l0.tag == 625u)) {
        return true;
    }
    if ((l0.tag == 546u || l0.tag == 552u || l0.tag == 558u || l0.tag == 559u || l0.tag == 561u || l0.tag == 565u)) {
        return true;
    }
    if ((l0.tag == 566u || l0.tag == 572u || l0.tag == 578u || l0.tag == 579u || l0.tag == 581u || l0.tag == 585u)) {
        return true;
    }
    if ((l0.tag == 531u || l0.tag == 533u || l0.tag == 539u || l0.tag == 541u || l0.tag == 542u)) {
        return true;
    }
    if ((l0.tag == 626u || l0.tag == 631u || l0.tag == 632u || l0.tag == 637u)) {
        return true;
    }
    if ((l0.tag == 547u || l0.tag == 548u || l0.tag == 549u || l0.tag == 550u || l0.tag == 562u || l0.tag == 563u || l0.tag == 564u)) {
        return true;
    }
    if ((l0.tag == 567u || l0.tag == 568u || l0.tag == 569u || l0.tag == 570u || l0.tag == 582u || l0.tag == 583u || l0.tag == 584u)) {
        return true;
    }
    if ((l0.tag == 553u || l0.tag == 554u || l0.tag == 555u || l0.tag == 556u || l0.tag == 557u || l0.tag == 560u)) {
        return true;
    }
    if ((l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 580u)) {
        return true;
    }
    if ((l0.tag == 534u || l0.tag == 535u || l0.tag == 536u || l0.tag == 537u || l0.tag == 538u || l0.tag == 540u)) {
        return true;
    }
    if ((l0.tag == 627u || l0.tag == 628u || l0.tag == 629u || l0.tag == 630u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 636u)) {
        return true;
    }
    if ((l0.tag == 504u || l0.tag == 505u)) {
        return true;
    }
    if ((l0.tag == 604u || l0.tag == 605u || l0.tag == 618u || l0.tag == 619u)) {
        return true;
    }
    if ((l0.tag == 502u || l0.tag == 506u || l0.tag == 507u)) {
        return true;
    }
    if ((l0.tag == 499u || l0.tag == 500u || l0.tag == 520u || l0.tag == 530u || l0.tag == 543u || l0.tag == 603u)) {
        return true;
    }
    if (l0.tag == 525u) {
        return true;
    }
    return false;
}

static bool vader_c_emit_is_continue_branch(void* l0, int32_t l1) {
    bool l2;
    int32_t t0;
    if (((vader_struct_vader_c_emit_ScopeInfo_t*) l0)->f_kind == INT32_C(1)) {
        t0 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l0)->f_opener_pc;
        l2 = (t0 + INT32_C(1)) == l1;
    } else {
        l2 = false;
    }
    return l2;
}

static bool vader_c_emit_is_param_by_address(void* l0, size_t l1) {
    size_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address)->length;
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_box_bool(188u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    return t1;
}

static bool vader_c_emit_is_pure_control_flow(vader_box_t l0) {
    return (l0.tag == 501u || l0.tag == 509u || l0.tag == 510u || l0.tag == 529u || l0.tag == 586u || l0.tag == 599u || l0.tag == 606u);
}

static bool vader_c_emit_is_ref_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(18)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(19);
    }
    return l1;
}

static bool vader_c_emit_is_scope_opening(vader_box_t l0) {
    return (l0.tag == 501u || l0.tag == 586u || l0.tag == 599u);
}

static void vader_c_emit_keep_pinned_resolves(void* l0, vader_box_t l1) {
    size_t l2, l5, l6;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    bool l8;
    size_t t0;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 529u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
        t1 = (t0 - INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    } else {
        l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
    }
    vader_array_t* _a0_arr = vader_array_new(46u, 0u, 13u, 651u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        t2 = ((vader_struct_vader_c_emit_ResolvedArray_t*) l7)->f_pinned;
        if (t2) {
            t0 = ((vader_struct_vader_c_emit_ResolvedArray_t*) l7)->f_depth;
            l8 = (t0 <= l2);
        } else {
            l8 = false;
        }
        if (l8) {
            vader_array_push((vader_array_t*) l3, vader_ref_box(l7));
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
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
    l3 = concat_2(2273u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 1;
    while ((l3 < l2)) {
        l4 = std_core_new_byte_buffer((size_t) 21);
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l4, l5, 1012u);
        t0 = (l3 - INT64_C(1));
        l6 = (uint64_t) (int64_t) t0;
        l5 = std_core_write_unsigned(l4, l5, l6);
        t1 = std_core_finish_buffer(l4, l5);
        l7 = vader_c_emit_c_ast_verbatim(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 196u);
        l8 = ((uint8_t) t2.payload.i);
        l9 = vader_c_emit_unbox_expr(l7, l8);
        vader_array_push((vader_array_t*) l1, l9);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
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
    l2 = vader_c_emit_c_ast_verbatim(1062u);
    t0 = vader_c_emit_c_ast_cast(2336u, l2);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 677u);
    _a0_obj->f_expression = t0;
    l3 = (void*) _a0_obj;
    l2 = vader_c_emit_c_ast_verbatim(1065u);
    t0 = vader_c_emit_c_ast_cast(2336u, l2);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a1_obj, 677u);
    _a1_obj->f_expression = t0;
    l4 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(146u, 2u, 13u, 1209u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l4;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3;
    l3 = (void*) _a2_arr;
    l5 = vader_c_emit_find_main(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module, l1);
    if ((l5 < INT32_C(0))) {
        vader_array_t* _a3_arr = vader_array_new(49u, 0u, 13u, 661u);
        l4 = (void*) _a3_arr;
        l2 = vader_c_emit_c_ast_number(INT64_C(0));
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a4_obj, 698u);
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
    l2 = vader_c_emit_c_ast_verbatim(2237u);
    l8 = vader_c_emit_c_ast_verbatim(676u);
    vader_array_t* _a6_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l8.payload.obj;
    ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l2.payload.obj;
    l9 = (void*) _a6_arr;
    t0 = vader_c_emit_c_ast_perform(2239u, l9);
    vader_array_t* _a7_arr = vader_array_new(146u, 1u, 13u, 1209u);
    ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0.payload.obj;
    l9 = (void*) _a7_arr;
    t3 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    l6 = ((vader_array_t*) t3)->length;
    if ((l6 > INT64_C(0))) {
        l2 = vader_c_emit_c_ast_verbatim(2284u);
        t0 = vader_c_emit_c_ast_verbatim(2286u);
        l8 = vader_c_emit_c_ast_address_of(t0);
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a8_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a8_obj, 661u);
        _a8_obj->f_target = l2;
        _a8_obj->f_value = l8;
        _a8_obj->f_operator = vader_box_obj(0u, NULL);
        l10 = (void*) _a8_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l10));
        l2 = vader_c_emit_c_ast_verbatim(2285u);
        l8 = vader_c_emit_c_ast_unsigned(((int64_t) (size_t) l6));
        vader_array_t* _a9_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = l2.payload.obj;
        l10 = (void*) _a9_arr;
        l2 = vader_c_emit_c_ast_perform(2241u, l10);
        vader_array_push((vader_array_t*) l9, l2);
    }
    t0 = vader_c_emit_c_ast_verbatim(2242u);
    vader_array_t* _a10_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = t0.payload.obj;
    l10 = (void*) _a10_arr;
    l2 = vader_c_emit_c_ast_perform(1123u, l10);
    vader_array_push((vader_array_t*) l9, l2);
    t0 = vader_c_emit_c_ast_verbatim(2283u);
    vader_array_t* _a11_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0.payload.obj;
    l10 = (void*) _a11_arr;
    l2 = vader_c_emit_c_ast_perform(1123u, l10);
    vader_array_push((vader_array_t*) l9, l2);
    vader_array_t* _a12_arr = vader_array_new(145u, 0u, 13u, 1205u);
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
            l2 = vader_c_emit_trap(1735u);
            vader_array_push((vader_array_t*) l9, l2);
            vader_array_t* _a13_arr = vader_array_new(49u, 0u, 13u, 661u);
            l12 = (void*) _a13_arr;
            l2 = vader_c_emit_c_ast_number(INT64_C(1));
            vader_struct_vader_c_emit_c_ast_CReturn_t* _a14_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
            vader_obj_header_init(_a14_obj, 698u);
            _a14_obj->f_stores = l12;
            _a14_obj->f_value = l2;
            _a14_obj->f_snapshot_type = 0u;
            _a14_obj->f_pops_frame = false;
            l12 = (void*) _a14_obj;
            vader_array_push((vader_array_t*) l9, vader_ref_box(l12));
            { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_c_emit_c_ast_verbatim(1062u);
        l8 = vader_c_emit_c_ast_verbatim(1065u);
        l13 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l11));
        l14 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l5));
        vader_array_t* _a15_arr = vader_array_new(145u, 4u, 13u, 1205u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 3u] = l14.payload.obj;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 2u] = l13.payload.obj;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l2.payload.obj;
        l12 = (void*) _a15_arr;
        l2 = vader_c_emit_c_ast_call(2298u, l12);
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) INT32_C(0), 196u);
        if (((int32_t) t0.payload.i) == INT32_C(18)) {
            l8 = vader_c_emit_c_ast_cast(2337u, l2);
            l8 = vader_c_emit_c_ast_declaration(2337u, 733u, l8);
            vader_array_push((vader_array_t*) l9, l8);
        } else {
            t0 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l11));
            vader_array_t* _a17_arr = vader_array_new(145u, 2u, 13u, 1205u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l2.payload.obj;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t0.payload.obj;
            l12 = (void*) _a17_arr;
            l2 = vader_c_emit_c_ast_call(2245u, l12);
            l2 = vader_c_emit_c_ast_declaration(2247u, 733u, l2);
            vader_array_push((vader_array_t*) l9, l2);
        }
        l2 = vader_c_emit_c_ast_verbatim(733u);
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
        vader_obj_header_init(_a18_obj, 677u);
        _a18_obj->f_expression = l2;
        l3 = (void*) _a18_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l3));
        vader_array_t* _a19_arr = vader_array_new(49u, 0u, 13u, 661u);
        l3 = (void*) _a19_arr;
        l8 = vader_c_emit_c_ast_number(INT64_C(0));
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a20_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a20_obj, 698u);
        _a20_obj->f_stores = l3;
        _a20_obj->f_value = l8;
        _a20_obj->f_snapshot_type = 0u;
        _a20_obj->f_pops_frame = false;
        l3 = (void*) _a20_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l3));
    } else {
        vader_array_t* _a21_arr = vader_array_new(49u, 0u, 13u, 661u);
        l3 = (void*) _a21_arr;
        l2 = vader_c_emit_c_ast_cast(1617u, l2);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a22_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a22_obj, 698u);
        _a22_obj->f_stores = l3;
        _a22_obj->f_value = l2;
        _a22_obj->f_snapshot_type = 0u;
        _a22_obj->f_pops_frame = false;
        l3 = (void*) _a22_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l3));
    }
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
    vader_obj_header_init(_a0_obj, 658u);
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
    l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = vader_c_emit_entry_needs_materialise(l4, l1);
        if (t0) {
            l5 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
            l6 = vader_c_emit_materialise_entry(l0, l4);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l6.payload.obj);
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static size_t vader_c_emit_max_fn_arity(void* l0) {
    size_t l1, l3, l4;
    void* l2;
    vader_box_t l5;
    bool l6;
    void* t0;
    size_t t1;
    int64_t t2;
    l1 = (size_t) 0;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 483u) {
            t0 = l5.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params)->length;
            l6 = (t1 > l1);
        } else {
            l6 = false;
        }
        if (l6) {
            t0 = l5.payload.obj;
            l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params)->length;
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
    if (l5.tag == 493u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        return t2;
    }
    return 0u;
}

static uint8_t vader_c_emit_module_function_storage(void* l0, int32_t l1) {
    size_t l2, l3;
    bool l4;
    void* l5;
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
        l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_internal_fns;
        t1 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t2 = vader_box_bool(188u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2]);
        l4 = t2.payload.b;
    } else {
        l4 = false;
    }
    if (l4) {
        return (uint8_t) 0;
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
    if ((l1 < INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l2 = vader_host_std_core_bytes(l0);
    t0 = ((int64_t) (ptrdiff_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l3);
    t1 = (void*) _a0_arr;
    t2 = vader_host_std_core_bytes_to_string(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 4u, 200u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    {
        vader_array_t* _pc8_hdr = (vader_array_t*) l1;
        size_t _pc8_len = _pc8_hdr->length;
        size_t _pc8_cap = (_pc8_hdr->offset == 0 && !vader_array_is_borrowed(_pc8_hdr) && _pc8_hdr->length >= _pc8_hdr->buf->length) ? _pc8_hdr->capacity : (size_t) 0;
        void* _pc8_slots = _pc8_hdr->buf->slots;
        for (;;) {
            if ((l3 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                t1 = vader_c_emit_data_entry_mutable(t0);
                if (t1) {
                    if (VADER_LIKELY(_pc8_len < _pc8_cap)) {
                        ((int64_t*) _pc8_slots)[_pc8_len] = (int64_t) ((int64_t) (size_t) l3);
                        _pc8_len += 1;
                    } else {
                        _pc8_hdr->length = _pc8_len;
                        if (_pc8_hdr->buf->length < _pc8_len) {
                            _pc8_hdr->buf->length = _pc8_len;
                        }
                        vader_array_push_i64((vader_array_t*) l1, (int64_t) (size_t) l3);
                        _pc8_hdr = (vader_array_t*) l1;
                        _pc8_len = _pc8_hdr->length;
                        _pc8_cap = (_pc8_hdr->offset == 0 && !vader_array_is_borrowed(_pc8_hdr) && _pc8_hdr->length >= _pc8_hdr->buf->length) ? _pc8_hdr->capacity : (size_t) 0;
                        _pc8_slots = _pc8_hdr->buf->slots;
                    }
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                continue;
            }
            _pc8_hdr->length = _pc8_len;
            if (_pc8_hdr->buf->length < _pc8_len) {
                _pc8_hdr->buf->length = _pc8_len;
            }
            break;
        }
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
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 362u);
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
        if (!(l6.tag == 493u)) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        t0 = l6.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
        if (t2 == 0u) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
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
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_new_ctx(void* l0, bool l1, bool l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    int32_t l11, l14, l15;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l8, &l9 };
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l12, &l13, &l16, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = l8;
        if (l8.tag == 493u) {
            t0 = l9.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            l10 = vader_c_emit_struct_c_name(t1);
            vader_array_push((vader_array_t*) l5, vader_box_string(190u, l10));
        } else {
            vader_array_push((vader_array_t*) l5, vader_box_string(190u, 0u));
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    l11 = vader_c_emit_string_primitive_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l12 = vader_c_emit_compute_atom_ids(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings, l3);
    l13 = vader_c_emit_atom_table_of(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings, l3);
    l14 = vader_c_emit_null_primitive_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l15 = vader_c_emit_string_array_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types, l11);
    l16 = vader_c_emit_compute_may_alloc(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    vader_struct_vader_c_emit_EmitCtx_t* _a2_obj = (vader_struct_vader_c_emit_EmitCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_EmitCtx_t));
    vader_obj_header_init(_a2_obj, 644u);
    _a2_obj->f_module = l0;
    _a2_obj->f_struct_c_names = l5;
    _a2_obj->f_atom_ids = l12;
    _a2_obj->f_atom_table = l13;
    _a2_obj->f_null_tag = l14;
    _a2_obj->f_string_tag = l11;
    _a2_obj->f_string_array_tag = l15;
    _a2_obj->f_may_alloc = l16;
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
    vader_array_t* _a0_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 663u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(144u, 0u, 13u, 1204u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(55u, 0u, 13u, 708u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(47u, 0u, 13u, 652u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 193u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(45u, 0u, 13u, 650u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(46u, 0u, 13u, 651u);
    l9 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(48u, 0u, 13u, 657u);
    l10 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(149u, 0u, 13u, 1219u);
    l11 = (void*) _a10_arr;
    vader_struct_vader_c_emit_FnState_t* _a11_obj = (vader_struct_vader_c_emit_FnState_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_FnState_t));
    vader_obj_header_init(_a11_obj, 646u);
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
    _a11_obj->f_resolved_arrays = l9;
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
    vader_obj_header_init(_a0_obj, 708u);
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
    l2 = concat_2(l0, 229u);
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
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a0_obj, 711u);
    _a0_obj->f_text = 489u;
    l2 = (void*) _a0_obj;
    l3 = vader_c_emit_c_ast_binary((uint8_t) 11, l0, vader_ref_box(l2));
    vader_array_t* _a1_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l2 = (void*) _a1_arr;
    l4 = vader_c_emit_c_ast_call(2244u, l2);
    vader_struct_vader_c_emit_c_ast_CConditional_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
    vader_obj_header_init(_a2_obj, 670u);
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = ((vader_array_t*) l0)->length;
    l2 = (size_t) 0;
    while ((l2 < l1)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l3.tag == 489u) {
            t0 = l3.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15)) {
                return ((int32_t) (size_t) l2);
            }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
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
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_value = INT64_C(0);
    _a0_obj->f_unsigned_v = true;
    l1 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a1_obj, 692u);
    _a1_obj->f_value = INT64_C(0);
    _a1_obj->f_unsigned_v = true;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a2_obj, 692u);
    _a2_obj->f_value = INT64_C(0);
    _a2_obj->f_unsigned_v = true;
    l3 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a3_obj, 711u);
    _a3_obj->f_text = 489u;
    l4 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(145u, 5u, 13u, 1205u);
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
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(18)) {
        l2 = l0;
    } else {
        l2 = vader_c_emit_payload(l0, 1818u);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l5.tag == 490u) {
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
    if (l5.tag == 493u) {
        l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        t3 = vader_c_emit_struct_check_expr(l3, l1, l2, l6);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 489u) {
        t1 = l5.payload.obj;
        t4 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
        if (t4) {
            t3 = vader_c_emit_float_tag_check_expr(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types, l1);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t3 = vader_c_emit_tag_equals(l1, l2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_op_allocates(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 622u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        l1 = !(t1);
    } else if ((l0.tag == 472u || l0.tag == 473u || l0.tag == 474u || l0.tag == 476u || l0.tag == 478u || l0.tag == 511u || l0.tag == 512u || l0.tag == 517u || l0.tag == 518u || l0.tag == 600u || l0.tag == 620u || l0.tag == 639u)) {
        l1 = true;
    } else if ((l0.tag == 468u || l0.tag == 469u || l0.tag == 470u || l0.tag == 471u || l0.tag == 475u || l0.tag == 477u || l0.tag == 499u || l0.tag == 500u || l0.tag == 501u || l0.tag == 502u || l0.tag == 503u || l0.tag == 504u || l0.tag == 505u || l0.tag == 506u || l0.tag == 507u || l0.tag == 508u || l0.tag == 509u || l0.tag == 510u || l0.tag == 513u || l0.tag == 516u || l0.tag == 519u || l0.tag == 520u || l0.tag == 521u || l0.tag == 523u || l0.tag == 524u || l0.tag == 525u || l0.tag == 526u || l0.tag == 529u || l0.tag == 530u || l0.tag == 531u || l0.tag == 532u || l0.tag == 533u || l0.tag == 534u || l0.tag == 535u || l0.tag == 536u || l0.tag == 537u || l0.tag == 538u || l0.tag == 539u || l0.tag == 540u || l0.tag == 541u || l0.tag == 542u || l0.tag == 543u || l0.tag == 544u || l0.tag == 545u || l0.tag == 546u || l0.tag == 547u || l0.tag == 548u || l0.tag == 549u || l0.tag == 550u || l0.tag == 551u || l0.tag == 552u || l0.tag == 553u || l0.tag == 554u || l0.tag == 555u || l0.tag == 556u || l0.tag == 557u || l0.tag == 558u || l0.tag == 559u || l0.tag == 560u || l0.tag == 561u || l0.tag == 562u || l0.tag == 563u || l0.tag == 564u || l0.tag == 565u || l0.tag == 566u || l0.tag == 567u || l0.tag == 568u || l0.tag == 569u || l0.tag == 570u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 581u || l0.tag == 582u || l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 586u || l0.tag == 588u || l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 593u || l0.tag == 594u || l0.tag == 595u || l0.tag == 596u || l0.tag == 597u || l0.tag == 598u || l0.tag == 599u || l0.tag == 601u || l0.tag == 602u || l0.tag == 603u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 608u || l0.tag == 610u || l0.tag == 611u || l0.tag == 612u || l0.tag == 613u || l0.tag == 614u || l0.tag == 615u || l0.tag == 616u || l0.tag == 617u || l0.tag == 618u || l0.tag == 619u || l0.tag == 621u || l0.tag == 623u || l0.tag == 624u || l0.tag == 625u || l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 629u || l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 638u)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$op_allocates");
    }
    return l1;
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
    if (!(l3.tag == 684u)) {
        vader_host_std_abort_panic(1207u);
    }
    l1 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t2 = (void*) _a1_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a2_obj, 663u);
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
    vader_array_t* _a0_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 663u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CIf_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIf_t));
    vader_obj_header_init(_a2_obj, 684u);
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
    vader_array_t* _a0_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 663u);
    _a1_obj->f_body = t0;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CScope_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CScope_t));
    vader_obj_header_init(_a2_obj, 699u);
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
    l2 = std_core_write_string_at(l1, l2, 749u);
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
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_mutable);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_box_bool(188u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    return t1;
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 201u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 306u);
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
            vader_array_t* _a6_arr = vader_array_new(9u, 1u, 7u, 193u);
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
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 193u);
    t1 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(2u, 1u, 13u, 9u);
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
            vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 193u);
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
    l2 = concat_2(1851u, l1);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 691u);
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
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_pc_active_for(void* l0, int32_t l1) {
    size_t l2;
    bool l3;
    void* l4;
    vader_box_t t0;
    int64_t t1;
    int32_t t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches)->length;
    if (l2 == INT64_C(0)) {
        l3 = true;
    } else {
        l3 = (l1 < INT32_C(0));
    }
    if (l3) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    l4 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches;
    t1 = (l2 - INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t2 = ((vader_struct_vader_c_emit_PushCache_t*) l4)->f_slot;
    if (t2 != l1) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    return vader_ref_box(l4);
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
    l1 = vader_c_emit_pc_header(l0, 1821u);
    l2 = vader_c_emit_c_ast_verbatim(287u);
    l1 = vader_c_emit_c_ast_binary((uint8_t) 11, l1, l2);
    l2 = vader_c_emit_c_ast_verbatim(143u);
    t0 = vader_c_emit_pc_local(l0, 1530u);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l3 = (void*) _a0_arr;
    l4 = vader_c_emit_c_ast_call(2212u, l3);
    vader_array_t* _a1_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l4.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l2.payload.obj;
    t1 = (void*) _a1_arr;
    vader_struct_vader_c_emit_c_ast_CSequence_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CSequence_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSequence_t));
    vader_obj_header_init(_a2_obj, 701u);
    _a2_obj->f_parts = t1;
    l3 = (void*) _a2_obj;
    l2 = vader_c_emit_pc_header(l0, 1698u);
    l4 = vader_c_emit_pc_header(l0, 1163u);
    l2 = vader_c_emit_c_ast_binary((uint8_t) 10, l2, l4);
    l1 = vader_c_emit_c_ast_binary((uint8_t) 16, l1, vader_ref_box(l3));
    t0 = vader_c_emit_c_ast_binary((uint8_t) 16, l1, l2);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a3_obj, 695u);
    _a3_obj->f_inner = t0;
    l3 = (void*) _a3_obj;
    l1 = vader_c_emit_pc_header(l0, 1244u);
    l2 = vader_c_emit_c_ast_verbatim(287u);
    l2 = vader_c_emit_c_ast_cast(1930u, l2);
    vader_struct_vader_c_emit_c_ast_CConditional_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
    vader_obj_header_init(_a4_obj, 670u);
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
    if (t1 != l1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_c_emit_PushCache_t*) l3)->f_opener_pc;
    vader_c_emit_pc_emit_writeback(l0, l4);
    t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches);
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
    l4 = std_core_write_string_at(l3, l4, 764u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 761u);
    l6 = std_core_finish_buffer(l3, l4);
    t0 = ((vader_struct_vader_c_emit_PushCache_t*) l1)->f_slot;
    vader_struct_vader_c_emit_c_ast_CLocal_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CLocal_t));
    vader_obj_header_init(_a0_obj, 689u);
    _a0_obj->f_slot = t0;
    t1 = (void*) _a0_obj;
    l7 = vader_c_emit_array_pointer(vader_ref_box(t1));
    vader_c_emit_declare(l0, 2235u, l6, l7);
    l3 = std_core_new_byte_buffer((size_t) 27);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 764u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 762u);
    l6 = std_core_finish_buffer(l3, l4);
    l7 = vader_c_emit_pc_header(l2, 1698u);
    vader_c_emit_declare(l0, 1930u, l6, l7);
    l3 = std_core_new_byte_buffer((size_t) 27);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 764u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 756u);
    l6 = std_core_finish_buffer(l3, l4);
    l7 = vader_c_emit_pc_capacity(l2);
    vader_c_emit_declare(l0, 1930u, l6, l7);
    l3 = std_core_new_byte_buffer((size_t) 29);
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l3, l4, 764u);
    l5 = ((int64_t) (int32_t) l2);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 766u);
    l6 = std_core_finish_buffer(l3, l4);
    l7 = vader_c_emit_pc_header(l2, 1164u);
    vader_c_emit_declare(l0, 2337u, l6, l7);
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
    l5 = vader_c_emit_pc_local(l4, 1697u);
    l6 = vader_c_emit_pc_local(l4, 1242u);
    t0 = vader_c_emit_c_ast_binary((uint8_t) 7, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0.payload.obj;
    l7 = (void*) _a0_arr;
    l5 = vader_c_emit_c_ast_call(680u, l7);
    vader_c_emit_open_if(l0, l5);
    t1 = vader_c_emit_pc_fill_of(((vader_struct_vader_c_emit_PushCache_t*) l1)->f_kind);
    l8 = ((vader_struct_vader_c_emit_SlotFill_t*) t1)->f_cty;
    l9 = concat_2(l8, 229u);
    l5 = vader_c_emit_pc_local(l4, 1938u);
    t0 = vader_c_emit_c_ast_cast(l9, l5);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a1_obj, 695u);
    _a1_obj->f_inner = t0;
    l7 = (void*) _a1_obj;
    l5 = vader_c_emit_pc_local(l4, 1697u);
    vader_struct_vader_c_emit_c_ast_CIndex_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
    vader_obj_header_init(_a2_obj, 686u);
    _a2_obj->f_base = vader_ref_box(l7);
    _a2_obj->f_index = l5;
    l7 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a3_obj, 695u);
    _a3_obj->f_inner = l3;
    l10 = (void*) _a3_obj;
    l5 = vader_c_emit_c_ast_cast(l8, vader_ref_box(l10));
    vader_c_emit_assign(l0, vader_ref_box(l7), l5);
    l5 = vader_c_emit_pc_local(l4, 1697u);
    l6 = vader_c_emit_c_ast_verbatim(290u);
    vader_struct_vader_c_emit_c_ast_CAssign_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
    vader_obj_header_init(_a4_obj, 661u);
    _a4_obj->f_target = l5;
    _a4_obj->f_value = l6;
    _a4_obj->f_operator = vader_box_i32(193u, INT32_C(3));
    l7 = (void*) _a4_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l7));
    vader_c_emit_open_else(l0);
    vader_c_emit_pc_emit_writeback(l0, l4);
    l8 = vader_c_emit_pc_helper_of(((vader_struct_vader_c_emit_PushCache_t*) l1)->f_kind);
    t0 = vader_c_emit_array_pointer(l2);
    vader_array_t* _a5_arr = vader_array_new(145u, 2u, 13u, 1205u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0.payload.obj;
    l7 = (void*) _a5_arr;
    l5 = vader_c_emit_c_ast_call(l8, l7);
    vader_c_emit_evaluate(l0, l5);
    l5 = vader_c_emit_pc_local(l4, 1530u);
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
    l2 = vader_c_emit_pc_header(l1, 1698u);
    l3 = vader_c_emit_pc_local(l1, 1697u);
    vader_c_emit_assign(l0, l2, l3);
    l2 = vader_c_emit_pc_header(l1, 1163u);
    l3 = vader_c_emit_pc_local(l1, 1697u);
    l2 = vader_c_emit_c_ast_binary((uint8_t) 7, l2, l3);
    vader_c_emit_open_if(l0, l2);
    l2 = vader_c_emit_pc_header(l1, 1163u);
    l3 = vader_c_emit_pc_local(l1, 1697u);
    vader_c_emit_assign(l0, l2, l3);
    vader_c_emit_close_node(l0, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_c_emit_pc_fill_of(uint8_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_typed_array_fill_for(l0);
    if (l1.tag == 0u) {
        vader_struct_vader_c_emit_SlotFill_t* _a0_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a0_obj, 653u);
        _a0_obj->f_cty = 1619u;
        _a0_obj->f_val = (uint8_t) 2;
        l2 = (void*) _a0_obj;
    } else {
        l2 = l1.payload.obj;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_c_emit_pc_local(l0, 1530u);
    vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a0_obj, 691u);
    _a0_obj->f_base = t0;
    _a0_obj->f_member = l1;
    _a0_obj->f_arrow = true;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_pc_helper_of(uint8_t l0) {
    vader_box_t l1;
    vader_string_t l2;
    l1 = vader_c_emit_push_helper_for(l0);
    if (l1.tag == 0u) {
        l2 = 2221u;
    } else {
        l2 = l1.payload.s;
    }
    return l2;
}

static bool vader_c_emit_pc_liftable_kind(uint8_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_push_helper_for(l0);
    if (t0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = vader_c_emit_typed_array_fill_for(l0);
    { bool __vret = !(t0.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = std_core_write_string_at(l4, l3, 764u);
    l5 = ((int64_t) (int32_t) l0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 716u);
    l3 = std_core_write_string_at(l4, l3, l2);
    t0 = std_core_finish_buffer(l4, l3);
    t1 = vader_c_emit_c_ast_verbatim(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_pc_operand_is_slot(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
        return t1 == l1;
    }
    return false;
}

static void vader_c_emit_pc_plan_for_loop(void* l0, int32_t l1, int32_t* __o0, int32_t* __o1, int32_t* __o2, uint8_t* __o3) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l20 = NULL;
    vader_box_t l3 = vader_box_null(), l12 = vader_box_null();
    int32_t l4, l6, l7, l16, l17, l19, l21;
    uint8_t l5, l14;
    size_t l9, l11;
    bool l15, l18;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l3, &l12 };
    void** gc_raw_roots[7] = { &l0, &l2, &l8, &l10, &l13, &l20, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_scope_ending_for_opener(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l1);
    if (l3.tag == 0u) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    l4 = -(INT32_C(1));
    l5 = (uint8_t) 7;
    l6 = (l1 + INT32_C(1));
    for (;;) {
        l7 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_end_pc;
        if ((l6 < l7)) {
            l8 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_body;
            t0 = ((int64_t) (int32_t) l6);
            l9 = (size_t) (int64_t) t0;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
            if (l3.tag == 599u) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 473u) {
                t1 = l3.payload.obj;
                t2 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_cache_slot;
                if ((t2 < INT32_C(0))) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                l10 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                t1 = l3.payload.obj;
                t2 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_type_id;
                t0 = ((int64_t) (int32_t) t2);
                l11 = (size_t) (int64_t) t0;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
                l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                l14 = vader_bytecode_array_kind_of(l12, l13);
                t3 = vader_c_emit_pc_liftable_kind(l14);
                if (!(t3)) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                if ((l4 >= INT32_C(0))) {
                    t1 = l3.payload.obj;
                    l16 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_cache_slot;
                    l15 = l4 != l16;
                } else {
                    l15 = false;
                }
                if (l15) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
                t1 = l3.payload.obj;
                l4 = ((vader_struct_vader_bytecode_ArrayPush_t*) t1)->f_cache_slot;
                l5 = l14;
                l6 = (l6 + INT32_C(1));
                continue;
            }
            if ((l3.tag == 606u || l3.tag == 607u)) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if ((l3.tag == 509u || l3.tag == 510u)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_jump_table);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
                l17 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                if ((l17 < l1)) {
                    l18 = true;
                } else {
                    l19 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_end_pc;
                    l18 = (l17 > l19);
                }
                if (l18) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
            }
            t3 = vader_c_emit_op_allocates(l3);
            if (t3) {
                { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
            }
            if (l3.tag == 516u) {
                l20 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_may_alloc;
                t1 = l3.payload.obj;
                l21 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
                t3 = std_core____Contains_contains__i32(l20, l21);
                if (t3) {
                    { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
                }
            }
            l6 = (l6 + INT32_C(1));
            continue;
        }
        break;
    }
    if ((l4 < INT32_C(0))) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    l8 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_push_caches;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l9 = ((vader_array_t*) l8)->length;
    l11 = (size_t) 0;
    while ((l11 < l9)) {
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
        t2 = ((vader_struct_vader_c_emit_PushCache_t*) t1)->f_slot;
        if (t2 == l4) {
            { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
        }
        t0 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_end_pc;
    t3 = vader_c_emit_pc_slot_written_in(l0, l1, l6, l4);
    if (t3) {
        { *__o3 = (uint8_t) 0; *__o2 = INT32_C(0); *__o1 = INT32_C(0); *__o0 = INT32_C(0); vader_gc_top = gc_frame.prev; return; }
    }
    { *__o3 = l5; *__o2 = l4; *__o1 = l1; *__o0 = INT32_C(1); vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_pc_reload(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pc_local(l1, 1697u);
    l3 = vader_c_emit_pc_header(l1, 1698u);
    vader_c_emit_assign(l0, l2, l3);
    l2 = vader_c_emit_pc_local(l1, 1242u);
    l3 = vader_c_emit_pc_capacity(l1);
    vader_c_emit_assign(l0, l2, l3);
    l2 = vader_c_emit_pc_local(l1, 1938u);
    l3 = vader_c_emit_pc_header(l1, 1164u);
    vader_c_emit_assign(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_c_emit_pc_slot_written_in(void* l0, int32_t l1, int32_t l2, int32_t l3) {
    int32_t l4;
    void* l5;
    size_t l6;
    vader_box_t l7;
    int64_t t0;
    void* t1;
    int32_t t2;
    l4 = l1;
    while ((l4 < l2)) {
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_body;
        t0 = ((int64_t) (int32_t) l4);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 597u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            if (t2 == l3) {
                return true;
            }
        }
        if (l7.tag == 598u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            if (t2 == l3) {
                return true;
            }
        }
        l4 = (l4 + INT32_C(1));
    }
    return false;
}

static vader_string_t vader_c_emit_pointer_to(vader_string_t l0, bool l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1) {
        l2 = concat_2(l0, 229u);
    } else {
        l2 = concat_3(1295u, l0, 229u);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_pop(void* l0) {
    size_t l1, l3;
    void* l2 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (l1 == INT64_C(0)) {
        t0 = vader_c_emit_c_ast_verbatim(287u);
        vader_struct_vader_c_emit_StackLit_t* _a0_obj = (vader_struct_vader_c_emit_StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLit_t));
        vader_obj_header_init(_a0_obj, 655u);
        _a0_obj->f_expression = t0;
        _a0_obj->f_val = (uint8_t) 2;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    t2 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    t2 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t2;
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l1);
    l2 = (void*) _a2_arr;
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        if (l8.tag == 509u) {
            l9 = true;
        } else {
            l9 = l8.tag == 510u;
        }
        if (l9) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            l11 = vader_c_emit_branch_target(l1, l10);
            if (l11.tag == 652u) {
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
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    vader_struct_vader_c_emit_BranchTargets_t* _a4_obj = (vader_struct_vader_c_emit_BranchTargets_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_BranchTargets_t));
    vader_obj_header_init(_a4_obj, 642u);
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
    vader_array_t* _a0_arr = vader_array_new(47u, 0u, 13u, 652u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 1u, 196u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 501u) {
            l8 = ((int32_t) (size_t) l6);
            vader_array_push_i32((vader_array_t*) l2, l8);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
        } else if (l7.tag == 599u) {
            l9 = ((int32_t) (size_t) l6);
            vader_array_push_i32((vader_array_t*) l2, l9);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(1));
        } else if (l7.tag == 586u) {
            l10 = ((int32_t) (size_t) l6);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_push_u8((vader_array_t*) l3, INT32_C(2));
        } else if (l7.tag == 529u) {
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
                t1 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l14, 196u);
                l15 = ((uint8_t) t1.payload.i);
                l16 = ((int32_t) (size_t) l6);
                vader_struct_vader_c_emit_ScopeInfo_t* _a6_obj = (vader_struct_vader_c_emit_ScopeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ScopeInfo_t));
                vader_obj_header_init(_a6_obj, 652u);
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
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_present_tag(void* l0, uint8_t l1) {
    int32_t l2, l3;
    l2 = vader_c_emit_prim_tag(l0, l1);
    if ((l2 < INT32_C(0))) {
        l3 = INT32_C(0);
    } else {
        l3 = l2;
    }
    return l3;
}

static int32_t vader_c_emit_prim_tag(void* l0, uint8_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 489u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == l1) {
                return ((int32_t) (size_t) l3);
            }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
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
    if (l4.tag == 489u) {
        t1 = l4.payload.obj;
        return ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == l1;
    }
    return false;
}

static int32_t vader_c_emit_primitive_tag_of(void* l0, uint8_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    bool t2;
    vader_box_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 489u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == l1) {
                return ((int32_t) (size_t) l3);
            }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    t2 = vader_bytecode_is_float_val(l1);
    if (t2) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = ((vader_array_t*) l0)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            if (t3.tag == 489u) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                t0 = t3.payload.obj;
                t2 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
                if (t2) {
                    return ((int32_t) (size_t) l3);
                }
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
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
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_object_pointer_of(t0);
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
    } else {
        l7 = l5.payload.s;
        vader_array_t* _a0_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
        l8 = (void*) _a0_arr;
        l3 = vader_c_emit_c_ast_call(l7, l8);
        vader_c_emit_push_into_temporary(l0, l3, l2);
    }
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
    vader_obj_header_init(_a0_obj, 654u);
    _a0_obj->f_expression = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_push_helper_for(uint8_t l0) {
    bool l1;
    vader_box_t l2;
    if (l0 == INT32_C(7)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l2 = vader_box_string(190u, 2221u);
    } else {
        if (l0 == INT32_C(8)) {
            l1 = true;
        } else {
            l1 = l0 == INT32_C(4);
        }
        if (l1) {
            l2 = vader_box_string(190u, 2222u);
        } else if (l0 == INT32_C(10)) {
            l2 = vader_box_string(190u, 2219u);
        } else if (l0 == INT32_C(9)) {
            l2 = vader_box_string(190u, 2218u);
        } else if (l0 == INT32_C(1)) {
            l2 = vader_box_string(190u, 2225u);
        } else if (l0 == INT32_C(5)) {
            l2 = vader_box_string(190u, 2223u);
        } else if (l0 == INT32_C(2)) {
            l2 = vader_box_string(190u, 2224u);
        } else if (l0 == INT32_C(6)) {
            l2 = vader_box_string(190u, 2220u);
        } else if (l0 == INT32_C(12)) {
            l2 = vader_box_string(190u, 2217u);
        } else {
            if (l0 == INT32_C(13)) {
                l1 = true;
            } else {
                l1 = l0 == INT32_C(0);
            }
            if (l1) {
                l2 = vader_box_obj(0u, NULL);
            } else {
                vader_unreachable("unreachable return in vader_c_emit$push_helper_for");
            }
        }
    }
    return l2;
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
    if (l1.tag == 688u) {
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
    } else {
        vader_struct_vader_c_emit_c_ast_CUnary_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnary_t));
        vader_obj_header_init(_a0_obj, 709u);
        _a0_obj->f_operator = 245u;
        _a0_obj->f_operand = l1;
        l3 = (void*) _a0_obj;
        vader_c_emit_push_expr(l0, (uint8_t) 3, vader_ref_box(l3));
    }
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
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[14] = {
        &l16, &l22, &l26, &l27, &l29, &l30, &l31, &l33, &l34, &l35, &l37, &l38, &l39, &t3,
    };
    void** gc_raw_roots[10] = { &l0, &l1, &l6, &l8, &l11, &l17, &l21, &l25, &l32, &t0 };
    vader_string_t* gc_atom_roots[12] = {
        &l2, &l3, &l4, &l12, &l13, &l18, &l19, &l23, &l24, &l28, &l36, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 14u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 12u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_bytecode_c_struct_layout(l1, l0);
    l9 = ((vader_array_t*) l1)->length;
    l10 = (size_t) 0;
    while ((l10 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
        l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l10);
        l12 = vader_c_emit_c_field_name(l11);
        l13 = concat_2(l3, l12);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l8)->f_offsets);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
        l14 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l10];
        l15 = (l5 + l14);
        l16 = vader_bytecode_nested_mirror(l11, l0);
        if (!(l16.tag == 0u)) {
            t0 = l16.payload.obj;
            l17 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
            l18 = concat_2(l13, 258u);
            t0 = l16.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            l19 = vader_c_emit_struct_c_name(t1);
            l20 = (l7 + INT32_C(1));
            vader_c_emit_push_leaf_asserts(l0, l17, l2, l18, l19, l15, l6, l20);
            t2 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t2;
            continue;
        }
        t3 = vader_c_emit_null_member(l2, l13);
        vader_array_t* _a2_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t3.payload.obj;
        l21 = (void*) _a2_arr;
        l22 = vader_c_emit_c_ast_call(1931u, l21);
        l23 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_name;
        l24 = concat_2(1444u, l23);
        t3 = vader_c_emit_null_member(l4, l24);
        vader_array_t* _a3_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t3.payload.obj;
        l25 = (void*) _a3_arr;
        l26 = vader_c_emit_c_ast_call(1931u, l25);
        l27 = vader_c_emit_c_ast_binary((uint8_t) 11, l22, l26);
        l28 = concat_3(l2, 258u, l13);
        l29 = vader_c_emit_static_assert(l27, l28);
        vader_array_push((vader_array_t*) l6, l29);
        l30 = vader_c_emit_c_ast_verbatim(l2);
        l31 = vader_c_emit_c_ast_verbatim(l13);
        vader_array_t* _a4_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l31.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l30.payload.obj;
        l32 = (void*) _a4_arr;
        l33 = vader_c_emit_c_ast_call(738u, l32);
        l34 = vader_c_emit_c_ast_number(l15);
        l35 = vader_c_emit_c_ast_binary((uint8_t) 11, l33, l34);
        l36 = concat_4(l2, 258u, l13, 98u);
        l37 = vader_c_emit_static_assert(l35, l36);
        vader_array_push((vader_array_t*) l6, l37);
        l38 = vader_c_emit_signedness_assert(l0, l11, l2, l13);
        if (!(l38.tag == 0u)) {
            l39 = l38;
            vader_array_push((vader_array_t*) l6, l39);
        }
        t2 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t2;
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
    vader_obj_header_init(_a0_obj, 655u);
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
    vader_obj_header_init(_a0_obj, 656u);
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
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
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
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l11 = vader_c_emit_c_field_name(l10);
        vader_struct_vader_c_emit_c_ast_CMember_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_base = l2;
        _a1_obj->f_member = l11;
        _a1_obj->f_arrow = false;
        l12 = (void*) _a1_obj;
        l13 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
        l14 = concat_2(1444u, l13);
        vader_struct_vader_c_emit_c_ast_CMember_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_base = l3;
        _a2_obj->f_member = l14;
        _a2_obj->f_arrow = true;
        l15 = (void*) _a2_obj;
        l16 = vader_bytecode_nested_mirror(l10, l0);
        if (!(l16.tag == 0u)) {
            t0 = l16.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            t2 = vader_c_emit_struct_c_name(t1);
            t1 = concat_2(t2, 229u);
            t3 = vader_c_emit_c_ast_cast(t1, vader_ref_box(l15));
            vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
            vader_obj_header_init(_a3_obj, 695u);
            _a3_obj->f_inner = t3;
            l17 = (void*) _a3_obj;
            t0 = l16.payload.obj;
            l18 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
            l19 = (l6 + INT32_C(1));
            vader_c_emit_push_member_copies(l0, l18, vader_ref_box(l12), vader_ref_box(l17), l4, l5, l19);
            t4 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t4;
            continue;
        }
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
        vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t));
        vader_obj_header_init(_a4_obj, 668u);
        _a4_obj->f_model = vader_ref_box(l20);
        _a4_obj->f_value = vader_ref_box(l21);
        l22 = (void*) _a4_obj;
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a5_obj, 661u);
        _a5_obj->f_target = vader_ref_box(l20);
        _a5_obj->f_value = vader_ref_box(l22);
        _a5_obj->f_operator = vader_box_obj(0u, NULL);
        l23 = (void*) _a5_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l23));
        t4 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t4;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_object(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_cast(2337u, l1);
    vader_c_emit_push_into_temporary(l0, l2, (uint8_t) 18);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_push_offset_list(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l3 = (void*) _a0_arr;
    vader_struct___lambda_env_vader_c_emit_5_t* _a1_obj = (vader_struct___lambda_env_vader_c_emit_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_5_t));
    vader_obj_header_init(_a1_obj, 229u);
    l4 = (void*) _a1_obj;
    l5 = l2;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l8 = t1.payload.s;
        l9 = __lambda_vader_c_emit_4(l4, l8);
        vader_array_push((vader_array_t*) l3, l9);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    l8 = concat_3(258u, l1, 763u);
    vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t));
    vader_obj_header_init(_a3_obj, 669u);
    _a3_obj->f_type = 1297u;
    _a3_obj->f_elements = l3;
    l3 = (void*) _a3_obj;
    l9 = vader_c_emit_c_ast_designated(l8, vader_ref_box(l3));
    vader_array_push((vader_array_t*) l0, l9);
    l8 = concat_3(258u, l1, 757u);
    t0 = ((vader_array_t*) l2)->length;
    l9 = vader_c_emit_c_ast_number(((int64_t) (size_t) t0));
    l9 = vader_c_emit_c_ast_designated(l8, l9);
    vader_array_push((vader_array_t*) l0, l9);
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
    l6 = concat_2(t1, 755u);
    l7 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_storage;
    l8 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_constant;
    l9 = 2291u;
    l10 = l2;
    l11 = vader_host_std_core_byte_len(l9);
    l12 = vader_host_std_core_byte_len(l10);
    t2 = (l11 + l12);
    l11 = (size_t) (int64_t) t2;
    l13 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(41) + l11));
    l11 = (size_t) 0;
    l11 = std_core_write_string_at(l13, l11, 2034u);
    l11 = std_core_write_string_at(l13, l11, l9);
    l11 = std_core_write_string_at(l13, l11, 8u);
    l11 = std_core_write_string_at(l13, l11, l10);
    l11 = std_core_write_string_at(l13, l11, 116u);
    l11 = std_core_write_int(l13, l11, l5);
    l11 = std_core_write_string_at(l13, l11, 714u);
    l9 = std_core_finish_buffer(l13, l11);
    t3 = vader_c_emit_c_ast_verbatim(682u);
    l14 = vader_c_emit_object_header(t3);
    l15 = vader_c_emit_c_ast_unsigned(l5);
    l16 = vader_c_emit_c_ast_unsigned(l5);
    t4 = ((vader_struct_vader_c_emit_PoolArray_t*) l1)->f_element_tag;
    l17 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t4));
    t4 = vader_bytecode_array_kind_index(l3);
    l18 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t4));
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_value = INT64_C(0);
    _a0_obj->f_unsigned_v = true;
    l13 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a1_obj, 692u);
    _a1_obj->f_value = INT64_C(0);
    _a1_obj->f_unsigned_v = true;
    l19 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a2_obj, 692u);
    _a2_obj->f_value = INT64_C(0);
    _a2_obj->f_unsigned_v = true;
    l20 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 2u] = l20;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l19;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l13;
    t5 = (void*) _a3_arr;
    l21 = vader_c_emit_c_ast_initializer_list(t5);
    l22 = vader_c_emit_c_ast_initializer_list(l4);
    vader_array_t* _a4_arr = vader_array_new(145u, 7u, 13u, 1205u);
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
    vader_obj_header_init(_a5_obj, 673u);
    _a5_obj->f_name = l6;
    _a5_obj->f_length = vader_box_obj(0u, NULL);
    _a5_obj->f_value = l14;
    l13 = (void*) _a5_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a6_obj, 682u);
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
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a7_obj, 692u);
    _a7_obj->f_value = INT64_C(0);
    _a7_obj->f_unsigned_v = true;
    l13 = (void*) _a7_obj;
    t3 = vader_c_emit_c_ast_verbatim(l6);
    l17 = vader_c_emit_c_ast_address_of(t3);
    l17 = vader_c_emit_c_ast_cast(2208u, l17);
    vader_array_t* _a8_arr = vader_array_new(145u, 5u, 13u, 1205u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 4u] = l17.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 3u] = l13;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 2u] = l16.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l15.payload.obj;
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l14.payload.obj;
    t5 = (void*) _a8_arr;
    l14 = vader_c_emit_c_ast_initializer_list(t5);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a9_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a9_obj, 673u);
    _a9_obj->f_name = l9;
    _a9_obj->f_length = vader_box_obj(0u, NULL);
    _a9_obj->f_value = l14;
    l13 = (void*) _a9_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a10_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a10_obj, 682u);
    _a10_obj->f_storage = l7;
    _a10_obj->f_constant = l8;
    _a10_obj->f_type = 2234u;
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
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    size_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[6] = { &l3, &l7, &l13, &l14, &l17, &t1 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l12, &t4 };
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
    if (l7.tag == 493u) {
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
        l7 = vader_c_emit_object_pointer(l3, l4);
        l12 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_name;
        l13 = vader_c_emit_field_of(l9, l7, l12);
        l5 = vader_c_emit_find_erased_siblings(l5, l1);
        t3 = ((vader_array_t*) l5)->length;
        if (t3 == INT64_C(0)) {
            vader_c_emit_push_expr(l0, l11, l13);
        } else {
            l14 = vader_c_emit_tag_expression(l3, l4);
            l6 = ((vader_array_t*) l5)->length;
            l15 = (size_t) 0;
            while ((l15 < l6)) {
                t3 = ((vader_array_t*) l5)->length;
                t0 = ((t3 - INT64_C(1)) - l15);
                l16 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l16)
                l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l16];
                l17 = vader_c_emit_erased_sibling_field_read(l0, l10, l2, l11, l7);
                t1 = vader_c_emit_tag_equals(l14, l10);
                vader_struct_vader_c_emit_c_ast_CConditional_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
                vader_obj_header_init(_a4_obj, 670u);
                _a4_obj->f_condition = t1;
                _a4_obj->f_then_value = l17;
                _a4_obj->f_else_value = l13;
                t2 = (void*) _a4_obj;
                vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
                vader_obj_header_init(_a5_obj, 695u);
                _a5_obj->f_inner = vader_ref_box(t2);
                t2 = (void*) _a5_obj;
                l13 = vader_ref_box(t2);
                t0 = (l15 + INT64_C(1));
                l15 = (size_t) (int64_t) t0;
            }
            vader_c_emit_push_expr(l0, l11, l13);
        }
    } else {
        l5 = std_core_new_byte_buffer((size_t) 59);
        l6 = (size_t) 0;
        l6 = std_core_write_string_at(l5, l6, 2031u);
        l18 = ((int64_t) (int32_t) l1);
        l6 = std_core_write_int(l5, l6, l18);
        t4 = std_core_finish_buffer(l5, l6);
        std_abort_todo(t4);
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
    vader_obj_header_init(_a0_obj, 658u);
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
    vader_obj_header_init(_a0_obj, 709u);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l1 = (void*) _a0_arr;
    t0 = vader_c_emit_c_ast_call(2297u, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_ref_carrying_element(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if ((l0.tag == 480u || l0.tag == 483u || l0.tag == 490u || l0.tag == 493u)) {
        return true;
    }
    if (l0.tag == 494u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        return t1;
    }
    return false;
}

static vader_string_t vader_c_emit_resolve_array_local(void* l0, vader_box_t l1, bool l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    vader_string_t l7 = 0;
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t3 };
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = vader_c_emit_c_ast_same_expression(((vader_struct_vader_c_emit_ResolvedArray_t*) l6)->f_pointer, l1);
        if (t0) {
            if (l2) {
                ((vader_struct_vader_c_emit_ResolvedArray_t*) l6)->f_pinned = true;
            }
            t1 = ((vader_struct_vader_c_emit_ResolvedArray_t*) l6)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    l7 = vader_c_emit_aux(l0, 1937u);
    vader_c_emit_declare(l0, 2235u, l7, l1);
    t3 = vader_c_emit_c_ast_verbatim(l7);
    vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t3.payload.obj;
    l3 = (void*) _a1_arr;
    vader_c_emit_statement_macro(l0, 673u, l3);
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays;
    l4 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_open_nodes)->length;
    vader_struct_vader_c_emit_ResolvedArray_t* _a2_obj = (vader_struct_vader_c_emit_ResolvedArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ResolvedArray_t));
    vader_obj_header_init(_a2_obj, 651u);
    _a2_obj->f_name = l7;
    _a2_obj->f_pointer = l1;
    _a2_obj->f_pinned = l2;
    _a2_obj->f_depth = l4;
    l6 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
    { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_return_statement(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    bool l5;
    bool t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_stores;
    l3 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_value;
    l4 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_snapshot_type;
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_no_frame;
    l5 = !(t0);
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a0_obj, 698u);
    _a0_obj->f_stores = l2;
    _a0_obj->f_value = l3;
    _a0_obj->f_snapshot_type = l4;
    _a0_obj->f_pops_frame = l5;
    l2 = (void*) _a0_obj;
    vader_c_emit_append_statement(l0, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_c_emit_sanitise(vader_string_t l0) {
    size_t l1, l3;
    void* l2 = NULL;
    uint8_t l4, l5;
    vader_string_t l6 = 0;
    bool t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 196u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        l4 = vader_host_std_core_byte_at(l0, l3);
        t0 = vader_text_is_ident_byte(l4);
        if (t0) {
            l5 = l4;
        } else {
            l5 = (uint8_t) 95;
        }
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l5);
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    l6 = vader_host_std_core_bytes_to_string(l2);
    t0 = vader_c_emit_is_c_reserved(l6);
    if (t0) {
        t2 = concat_2(l6, 769u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_scalar_cast(vader_box_t l0, uint8_t l1, uint8_t l2) {
    bool l3;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    size_t l6;
    int64_t l7;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l8, &t3 };
    void** gc_raw_roots[2] = { &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 688u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_class == l1;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = l0.payload.obj;
        t1 = vader_c_emit_c_ast_is_most_negative(t0);
        l3 = !(t1);
    } else {
        l3 = false;
    }
    if (l3) {
        l4 = vader_c_emit_c_type_for_val_bare(l2);
        l5 = std_core_new_byte_buffer((size_t) 20);
        l6 = (size_t) 0;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_value;
        l6 = std_core_write_int(l5, l6, l7);
        t2 = std_core_finish_buffer(l5, l6);
        l8 = vader_c_emit_c_ast_verbatim(t2);
        t3 = vader_c_emit_c_ast_cast(l4, l8);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_c_emit_c_type_for_val_bare(l2);
    t2 = vader_c_emit_c_type_for_val_bare(l1);
    l8 = vader_c_emit_c_ast_cast(t2, l0);
    t3 = vader_c_emit_c_ast_cast(l4, l8);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        l5 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l2, l5);
        vader_array_push_bool((vader_array_t*) l3, false);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l6 = false;
    l7 = l0;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l1 = ((vader_array_t*) l7)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l8 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            if (l11.tag == 545u) {
                t1 = l11.payload.obj;
                t2 = ((vader_struct_vader_bytecode_FnRef_t*) t1)->f_function_index;
                t0 = ((int64_t) (int32_t) t2);
                l12 = (size_t) (int64_t) t0;
                t1 = l11.payload.obj;
                l5 = ((vader_struct_vader_bytecode_FnRef_t*) t1)->f_type_id;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12] = (int32_t) l5;
                l6 = true;
            } else if (l11.tag == 600u) {
                t1 = l11.payload.obj;
                t2 = ((vader_struct_vader_bytecode_MakeClosure_t*) t1)->f_function_index;
                t0 = ((int64_t) (int32_t) t2);
                l13 = (size_t) (int64_t) t0;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
                ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l13] = (uint8_t) true;
                l6 = true;
            }
            t0 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t0;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_struct_vader_c_emit_FnValueUsage_t* _a6_obj = (vader_struct_vader_c_emit_FnValueUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_FnValueUsage_t));
    vader_obj_header_init(_a6_obj, 647u);
    _a6_obj->f_fn_ref_type = l2;
    _a6_obj->f_is_closure = l3;
    _a6_obj->f_any = l6;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_scope_ending_at(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_end_pc;
        if (t1 == l1) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            return vader_ref_box(t0);
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    t3 = vader_box_obj(0u, NULL);
    return t3;
}

static vader_box_t vader_c_emit_scope_ending_for_opener(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_opener_pc;
        if (t1 == l1) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            return vader_ref_box(t0);
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    t3 = vader_box_obj(0u, NULL);
    return t3;
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
    if (l4 == INT32_C(19)) {
        vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a0_arr;
        t1 = vader_c_emit_c_ast_perform(2293u, l5);
        vader_array_t* _a1_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a1_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        vader_array_t* _a2_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a2_arr;
        t1 = vader_c_emit_c_ast_returning(2305u, l5);
        vader_array_t* _a3_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a3_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(2)) {
        vader_array_t* _a4_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a4_arr;
        t1 = vader_c_emit_c_ast_returning(2304u, l5);
        vader_array_t* _a5_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a5_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(5)) {
        vader_array_t* _a6_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a6_arr;
        t1 = vader_c_emit_c_ast_returning(2307u, l5);
        vader_array_t* _a7_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a7_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(3)) {
        l6 = vader_c_emit_prim_tag(l1, (uint8_t) 5);
        if ((l6 < INT32_C(0))) {
            t1 = vader_c_emit_trap(1198u);
            vader_array_t* _a8_arr = vader_array_new(146u, 1u, 13u, 1209u);
            ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = t1.payload.obj;
            t2 = (void*) _a8_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = vader_c_emit_array_tag(l1, l6);
        if ((l7 < INT32_C(0))) {
            t1 = vader_c_emit_trap(1199u);
            vader_array_t* _a9_arr = vader_array_new(146u, 1u, 13u, 1209u);
            ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t1.payload.obj;
            t2 = (void*) _a9_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l7));
        l9 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) l6));
        vader_array_t* _a10_arr = vader_array_new(145u, 3u, 13u, 1205u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 2u] = l9.payload.obj;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a10_arr;
        l8 = vader_c_emit_c_ast_call(2306u, l5);
        vader_array_t* _a11_arr = vader_array_new(49u, 0u, 13u, 661u);
        l5 = (void*) _a11_arr;
        l8 = vader_c_emit_c_ast_cast(2337u, l8);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a12_obj, 698u);
        _a12_obj->f_stores = l5;
        _a12_obj->f_value = l8;
        _a12_obj->f_snapshot_type = 0u;
        _a12_obj->f_pops_frame = false;
        t2 = (void*) _a12_obj;
        vader_array_t* _a13_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = t2;
        t2 = (void*) _a13_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(4)) {
        t1 = vader_c_emit_c_ast_cast(2235u, l2);
        vader_array_t* _a14_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t1.payload.obj;
        l5 = (void*) _a14_arr;
        t1 = vader_c_emit_c_ast_returning(2303u, l5);
        vader_array_t* _a15_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a15_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(6)) {
        vader_array_t* _a16_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a16_arr;
        t1 = vader_c_emit_c_ast_returning(2308u, l5);
        vader_array_t* _a17_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a17_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(12)) {
        vader_array_t* _a18_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l5 = (void*) _a18_arr;
        t1 = vader_c_emit_c_ast_perform(2280u, l5);
        vader_array_t* _a19_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a19_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(13)) {
        t1 = vader_c_emit_gc_statistic(2088u);
        vader_array_t* _a20_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a20_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(14)) {
        t1 = vader_c_emit_gc_statistic(1202u);
        vader_array_t* _a21_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a21_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(15)) {
        t1 = vader_c_emit_gc_statistic(2089u);
        vader_array_t* _a22_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a22_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(16)) {
        vader_array_t* _a23_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l5 = (void*) _a23_arr;
        t1 = vader_c_emit_c_ast_returning(2300u, l5);
        vader_array_t* _a24_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a24_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(17)) {
        vader_array_t* _a25_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a25_arr;
        t1 = vader_c_emit_c_ast_perform(2299u, l5);
        vader_array_t* _a26_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a26_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(18)) {
        vader_array_t* _a27_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l5 = (void*) _a27_arr;
        t1 = vader_c_emit_c_ast_returning(2301u, l5);
        vader_array_t* _a28_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a28_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(22)) {
        vader_array_t* _a29_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a29_arr->buf->slots)[_a29_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a29_arr;
        l8 = vader_c_emit_c_ast_call(2312u, l5);
        l8 = vader_c_emit_c_ast_declaration(1296u, 1204u, l8);
        t1 = vader_c_emit_c_ast_verbatim(1204u);
        vader_array_t* _a30_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = t1.payload.obj;
        l5 = (void*) _a30_arr;
        l9 = vader_c_emit_c_ast_call(2270u, l5);
        l9 = vader_c_emit_c_ast_declaration(2337u, 1867u, l9);
        l10 = vader_c_emit_c_ast_verbatim(1204u);
        vader_array_t* _a31_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a31_arr->buf->slots)[_a31_arr->offset + 1u] = l10.payload.obj;
        ((void**) _a31_arr->buf->slots)[_a31_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a31_arr;
        l10 = vader_c_emit_c_ast_perform(2262u, l5);
        vader_array_t* _a32_arr = vader_array_new(49u, 0u, 13u, 661u);
        l5 = (void*) _a32_arr;
        t1 = vader_c_emit_c_ast_verbatim(1867u);
        l11 = vader_c_emit_address_as_size(t1);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a33_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a33_obj, 698u);
        _a33_obj->f_stores = l5;
        _a33_obj->f_value = l11;
        _a33_obj->f_snapshot_type = 0u;
        _a33_obj->f_pops_frame = false;
        l5 = (void*) _a33_obj;
        vader_array_t* _a34_arr = vader_array_new(146u, 4u, 13u, 1209u);
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 3u] = l5;
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a34_arr->buf->slots)[_a34_arr->offset + 0u] = l8.payload.obj;
        t2 = (void*) _a34_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(23)) {
        l8 = vader_c_emit_size_as_address(l2);
        l9 = vader_c_emit_c_ast_verbatim(1205u);
        vader_array_t* _a35_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a35_arr->buf->slots)[_a35_arr->offset + 1u] = l9.payload.obj;
        ((void**) _a35_arr->buf->slots)[_a35_arr->offset + 0u] = l8.payload.obj;
        l5 = (void*) _a35_arr;
        l8 = vader_c_emit_c_ast_call(2271u, l5);
        vader_array_t* _a36_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a36_arr->buf->slots)[_a36_arr->offset + 0u] = l3.payload.obj;
        l5 = (void*) _a36_arr;
        l9 = vader_c_emit_c_ast_call(2312u, l5);
        l9 = vader_c_emit_c_ast_declaration(1296u, 1205u, l9);
        l8 = vader_c_emit_c_ast_declaration(2337u, 1867u, l8);
        l10 = vader_c_emit_c_ast_verbatim(1205u);
        vader_array_t* _a37_arr = vader_array_new(145u, 2u, 13u, 1205u);
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 1u] = l10.payload.obj;
        ((void**) _a37_arr->buf->slots)[_a37_arr->offset + 0u] = l3.payload.obj;
        l5 = (void*) _a37_arr;
        l10 = vader_c_emit_c_ast_perform(2262u, l5);
        vader_array_t* _a38_arr = vader_array_new(49u, 0u, 13u, 661u);
        l5 = (void*) _a38_arr;
        t1 = vader_c_emit_c_ast_verbatim(1867u);
        l11 = vader_c_emit_address_as_size(t1);
        vader_struct_vader_c_emit_c_ast_CReturn_t* _a39_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
        vader_obj_header_init(_a39_obj, 698u);
        _a39_obj->f_stores = l5;
        _a39_obj->f_value = l11;
        _a39_obj->f_snapshot_type = 0u;
        _a39_obj->f_pops_frame = false;
        l5 = (void*) _a39_obj;
        vader_array_t* _a40_arr = vader_array_new(146u, 4u, 13u, 1209u);
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 3u] = l5;
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 1u] = l8.payload.obj;
        ((void**) _a40_arr->buf->slots)[_a40_arr->offset + 0u] = l9.payload.obj;
        t2 = (void*) _a40_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(24)) {
        l2 = vader_c_emit_size_as_address(l2);
        l3 = vader_c_emit_c_ast_cast(2235u, l3);
        l8 = vader_c_emit_argument((size_t) 2);
        l8 = vader_c_emit_c_ast_cast(2235u, l8);
        l9 = vader_c_emit_argument((size_t) 3);
        vader_array_t* _a41_arr = vader_array_new(145u, 4u, 13u, 1205u);
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 3u] = l9.payload.obj;
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 2u] = l8.payload.obj;
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a41_arr->buf->slots)[_a41_arr->offset + 0u] = l2.payload.obj;
        l5 = (void*) _a41_arr;
        t1 = vader_c_emit_c_ast_returning(2268u, l5);
        vader_array_t* _a42_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a42_arr->buf->slots)[_a42_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a42_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(20)) {
        vader_array_t* _a43_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l5 = (void*) _a43_arr;
        t1 = vader_c_emit_c_ast_returning(2264u, l5);
        vader_array_t* _a44_arr = vader_array_new(146u, 1u, 13u, 1209u);
        ((void**) _a44_arr->buf->slots)[_a44_arr->offset + 0u] = t1.payload.obj;
        t2 = (void*) _a44_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(21)) {
        vader_array_t* _a45_arr = vader_array_new(145u, 0u, 13u, 1205u);
        l5 = (void*) _a45_arr;
        t1 = vader_c_emit_c_ast_returning(2263u, l5);
        vader_array_t* _a46_arr = vader_array_new(146u, 1u, 13u, 1209u);
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
        l12 = l4 == INT32_C(0);
    }
    if (l12) {
    } else {
        vader_unreachable("unreachable return in vader_c_emit$shim_body");
    }
    t3 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_is_extern;
    if (t3) {
        t2 = vader_c_emit_user_extern_shim(l0, l1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l13 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    t0 = concat_2(2166u, l13);
    t1 = vader_c_emit_trap(t0);
    vader_array_t* _a47_arr = vader_array_new(146u, 1u, 13u, 1209u);
    ((void**) _a47_arr->buf->slots)[_a47_arr->offset + 0u] = t1.payload.obj;
    t2 = (void*) _a47_arr;
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
    l4 = vader_c_emit_value_parameters(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params, 1691u);
    t1 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature);
    l5 = (t1 > INT64_C(1));
    if (l5) {
        l6 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_results;
        l3 = ((vader_array_t*) l6)->length;
        l7 = (size_t) 0;
        while ((l7 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l7, 196u);
            t3 = vader_c_emit_c_type_for_val_bare(((uint8_t) t2.payload.i));
            l8 = concat_2(t3, 229u);
            l9 = vader_c_emit_out_param_name(l7);
            vader_struct_vader_c_emit_c_ast_CParameter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
            vader_obj_header_init(_a2_obj, 694u);
            _a2_obj->f_type = l8;
            _a2_obj->f_name = l9;
            l10 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
        }
    }
    l11 = vader_c_emit_module_function_storage(l0, l1);
    if (l5) {
        l8 = 2336u;
    } else {
        t4 = vader_bytecode_bc_single_result(((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature);
        l8 = vader_c_emit_c_type_for_val_bare(t4);
    }
    t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_name;
    l9 = vader_c_emit_sanitise(t3);
    vader_struct_vader_c_emit_c_ast_CSignature_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSignature_t));
    vader_obj_header_init(_a3_obj, 702u);
    _a3_obj->f_storage = l11;
    _a3_obj->f_inline_v = false;
    _a3_obj->f_result = l8;
    _a3_obj->f_name = l9;
    _a3_obj->f_parameters = l4;
    t5 = (void*) _a3_obj;
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    int64_t l8;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    bool t2;
    vader_box_t* gc_roots[4] = { &l4, &l5, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_bytecode_c_field_val_type(l1, l0);
    if (l4.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((uint8_t) l4.payload.i);
    t2 = vader_bytecode_is_integer_val(t1);
    if (!(t2)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_c_emit_null_member(l2, l3);
    l6 = vader_c_emit_c_ast_number(-(INT64_C(1)));
    vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t));
    vader_obj_header_init(_a0_obj, 668u);
    _a0_obj->f_model = l5;
    _a0_obj->f_value = l6;
    l7 = (void*) _a0_obj;
    l5 = vader_c_emit_c_ast_number(INT64_C(0));
    t0 = vader_c_emit_c_ast_binary((uint8_t) 7, vader_ref_box(l7), l5);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a1_obj, 695u);
    _a1_obj->f_inner = t0;
    l7 = (void*) _a1_obj;
    t1 = ((uint8_t) l4.payload.i);
    t2 = vader_bytecode_is_unsigned_val(t1);
    if (t2) {
        l8 = INT64_C(0);
    } else {
        l8 = INT64_C(1);
    }
    l4 = vader_c_emit_c_ast_number(l8);
    l4 = vader_c_emit_c_ast_binary((uint8_t) 11, vader_ref_box(l7), l4);
    l9 = concat_4(l2, 258u, l3, 114u);
    t0 = vader_c_emit_static_assert(l4, l9);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_single_offset_list(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CUnsized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CUnsized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnsized_t));
    vader_obj_header_init(_a0_obj, 710u);
    l2 = (void*) _a0_obj;
    t0 = vader_c_emit_c_ast_verbatim(l1);
    vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0.payload.obj;
    t1 = (void*) _a1_arr;
    l3 = vader_c_emit_c_ast_initializer_list(t1);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a2_obj, 673u);
    _a2_obj->f_name = l0;
    _a2_obj->f_length = vader_ref_box(l2);
    _a2_obj->f_value = l3;
    l2 = (void*) _a2_obj;
    vader_struct_vader_c_emit_c_ast_CGlobal_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CGlobal_t));
    vader_obj_header_init(_a3_obj, 682u);
    _a3_obj->f_storage = (uint8_t) 0;
    _a3_obj->f_constant = true;
    _a3_obj->f_type = 2159u;
    _a3_obj->f_declarator = l2;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = concat_2(683u, l1);
    l5 = vader_c_emit_c_ast_verbatim(t0);
    l5 = vader_c_emit_c_ast_designated(268u, l5);
    t0 = concat_3(1932u, l2, 206u);
    l6 = vader_c_emit_c_ast_verbatim(t0);
    l6 = vader_c_emit_c_ast_designated(273u, l6);
    l7 = vader_c_emit_c_ast_number(((int64_t) (int32_t) l3));
    l7 = vader_c_emit_c_ast_designated(274u, l7);
    l8 = vader_c_emit_c_ast_verbatim(l4);
    l8 = vader_c_emit_c_ast_designated(271u, l8);
    l9 = vader_c_emit_c_ast_number(INT64_C(1));
    l9 = vader_c_emit_c_ast_designated(270u, l9);
    vader_array_t* _a0_arr = vader_array_new(145u, 5u, 13u, 1205u);
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
    l1 = vader_c_emit_c_ast_cast(2163u, l0);
    t0 = vader_c_emit_c_ast_cast(2337u, l1);
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
    t0 = concat_2(l0, 255u);
    l2 = vader_c_emit_c_ast_verbatim(t0);
    l3 = vader_c_emit_expression_of(l1);
    l3 = vader_c_emit_c_ast_cast(1930u, l3);
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
    vader_box_t t2;
    void* t3;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params;
    t0 = ((vader_array_t*) l2)->length;
    l3 = ((int32_t) (size_t) t0);
    if ((l1 < l3)) {
        t1 = ((int64_t) (int32_t) l1);
        l4 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 196u);
        return ((uint8_t) t2.payload.i);
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    t1 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t1;
    l6 = ((vader_array_t*) l2)->length;
    t1 = (l4 - l6);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    return ((vader_struct_vader_bytecode_BcLocal_t*) t3)->f_val;
}

static void* vader_c_emit_sorted_fn_indices(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l6 = NULL;
    size_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t* _a0_obj = (vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t));
    vader_obj_header_init(_a0_obj, 202u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    l1 = vader_ref_box(t0);
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) l1.payload.obj)->f_value)->length;
    l4 = (size_t) 0;
    {
        vader_array_t* _pc11_hdr = (vader_array_t*) l2;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l4 < l3)) {
                l5 = ((int32_t) (size_t) l4);
                if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                    ((int32_t*) _pc11_slots)[_pc11_len] = (int32_t) (l5);
                    _pc11_len += 1;
                } else {
                    _pc11_hdr->length = _pc11_len;
                    if (_pc11_hdr->buf->length < _pc11_len) {
                        _pc11_hdr->buf->length = _pc11_len;
                    }
                    vader_array_push_i32((vader_array_t*) l2, l5);
                    _pc11_hdr = (vader_array_t*) l2;
                    _pc11_len = _pc11_hdr->length;
                    _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                    _pc11_slots = _pc11_hdr->buf->slots;
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
    }
    vader_struct___lambda_env_vader_c_emit_1_t* _a2_obj = (vader_struct___lambda_env_vader_c_emit_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_1_t));
    vader_obj_header_init(_a2_obj, 227u);
    _a2_obj->f_cap_0 = l1;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 167u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_0;
    _a3_closure->env = t0;
    l6 = (void*) _a3_closure;
    t0 = std_sort_sort__i32(l2, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
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
        vader_array_push((vader_array_t*) l1, vader_box_string(190u, l8));
    }
    vader_struct___lambda_env_vader_c_emit_3_t* _a3_obj = (vader_struct___lambda_env_vader_c_emit_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_3_t));
    vader_obj_header_init(_a3_obj, 228u);
    t1 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 163u);
    _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_2;
    _a4_closure->env = t1;
    l2 = (void*) _a4_closure;
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
    vader_obj_header_init(_a0_obj, 665u);
    _a0_obj->f_callee = l1;
    _a0_obj->f_arguments = l2;
    t0 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CMacroStatement_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CMacroStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMacroStatement_t));
    vader_obj_header_init(_a1_obj, 690u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(190u, t0);
    t1 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CStringLiterals_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStringLiterals_t));
    vader_obj_header_init(_a1_obj, 704u);
    _a1_obj->f_literals = t1;
    l2 = (void*) _a1_obj;
    vader_struct_vader_c_emit_c_ast_CStaticAssert_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CStaticAssert_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CStaticAssert_t));
    vader_obj_header_init(_a2_obj, 703u);
    _a2_obj->f_condition = l0;
    _a2_obj->f_message = l2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_c_emit_string_array_tag(void* l0, int32_t l1) {
    int32_t t0;
    if ((l1 < INT32_C(0))) {
        return -(INT32_C(1));
    }
    t0 = vader_c_emit_array_tag(l0, l1);
    return t0;
}

static int32_t vader_c_emit_string_primitive_tag(void* l0) {
    size_t l1, l2;
    vader_box_t l3;
    void* t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = ((vader_array_t*) l0)->length;
    l2 = (size_t) 0;
    while ((l2 < l1)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l3.tag == 489u) {
            t0 = l3.payload.obj;
            t1 = vader_bytecode_is_string_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
            if (t1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
}

static bool vader_c_emit_struct_all_ref(void* l0, void* l1) {
    void* l2;
    void* l5;
    size_t l3, l4, l6, l7, l8;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l2 = ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_vader_bytecode_BcField_t*) l5)->f_type_index;
        t2 = ((int64_t) (int32_t) t1);
        l6 = (size_t) (int64_t) t2;
        l7 = ((vader_array_t*) l0)->length;
        if ((l6 >= l7)) {
            return false;
        }
        t1 = ((vader_struct_vader_bytecode_BcField_t*) l5)->f_type_index;
        t2 = ((int64_t) (int32_t) t1);
        l8 = (size_t) (int64_t) t2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        if (!(t3.tag == 490u)) {
            return false;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return true;
}

static vader_string_t vader_c_emit_struct_c_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_sanitise(l0);
    t0 = concat_3(2313u, l1, 767u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_struct_check_expr(void* l0, vader_box_t l1, int32_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    size_t l7, l8;
    int32_t l9;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    size_t t5;
    vader_box_t* gc_roots[4] = { &l1, &l4, &l10, &t1 };
    void** gc_raw_roots[3] = { &l0, &l6, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l5, &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_tag_equals(l1, l2);
    l5 = vader_text_prefix_before_double_underscore(l3);
    if (l5 == 0u) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l4.payload.obj;
    l6 = (void*) _a0_arr;
    l7 = ((vader_array_t*) l0)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        if (((int32_t) (size_t) l8) == l2) {
            t0 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t0;
            continue;
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        if (t1.tag == 493u) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            t2 = t1.payload.obj;
            t3 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_name;
            t4 = vader_text_prefix_before_double_underscore(t3);
            if (t4 == l5) {
                l9 = ((int32_t) (size_t) l8);
                l10 = vader_c_emit_tag_equals(l1, l9);
                vader_array_push((vader_array_t*) l6, l10);
            }
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    t5 = ((vader_array_t*) l6)->length;
    if (t5 == INT64_C(1)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_c_ast_any_of(l6);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a3_obj, 695u);
    _a3_obj->f_inner = t1;
    t2 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 678u);
    _a0_obj->f_type = 2290u;
    _a0_obj->f_name = 1531u;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(52u, 1u, 13u, 678u);
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
        l12 = concat_2(1444u, l11);
        vader_struct_vader_c_emit_c_ast_CField_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CField_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CField_t));
        vader_obj_header_init(_a4_obj, 678u);
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
    vader_obj_header_init(_a6_obj, 705u);
    _a6_obj->f_name = t4;
    _a6_obj->f_fields = l3;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
    uint8_t l6;
    uint64_t l7;
    vader_string_t l8 = 0;
    void* l9 = NULL;
    size_t l10;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    uint8_t t4;
    vader_box_t* gc_roots[3] = { &l2, &l11, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 496u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_kind;
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcValPrim_t*) t0)->f_bits;
        t1 = vader_c_emit_data_slot(l6, l7);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 497u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        t2 = vader_c_emit_atom_for(l5, l8);
        t1 = vader_c_emit_c_ast_unsigned(((int64_t) (int32_t) t2));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    t3 = ((int64_t) (int32_t) l4);
    l10 = (size_t) (int64_t) t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l10);
    t4 = vader_c_emit_val_type_of_bc_type(t1);
    if (t4 == INT32_C(18)) {
        l11 = l2;
        l11 = vader_c_emit_emit_data_value(l0, l1, l11, l3, l5);
        t1 = vader_c_emit_c_ast_cast(2337u, l11);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l2;
    l11 = vader_c_emit_emit_data_value(l0, l1, l11, l3, l5);
    t1 = vader_c_emit_boxed_object(l4, l11);
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
    l4 = vader_c_emit_c_ast_verbatim(684u);
    l4 = vader_c_emit_c_ast_designated(268u, l4);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
    l5 = t0.payload.s;
    t1 = concat_3(1932u, l5, 206u);
    l6 = vader_c_emit_c_ast_verbatim(t1);
    l6 = vader_c_emit_c_ast_designated(273u, l6);
    t2 = vader_bytecode_size_of_bc_type(vader_ref_box(l1));
    l7 = vader_c_emit_c_ast_number(((int64_t) (int32_t) t2));
    l7 = vader_c_emit_c_ast_designated(274u, l7);
    vader_array_t* _a1_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = l7.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l6.payload.obj;
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l4.payload.obj;
    l8 = (void*) _a1_arr;
    l9 = ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_ptr_offsets;
    vader_c_emit_push_offset_list(l8, 1862u, l9);
    l9 = ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_str_offsets;
    vader_c_emit_push_offset_list(l8, 2010u, l9);
    l9 = ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_ref_offsets;
    vader_c_emit_push_offset_list(l8, 1880u, l9);
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
    l3 = std_core_write_string_at(l2, l3, 2134u);
    t0 = std_core_finish_buffer(l2, l3);
    l5 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_binary((uint8_t) 11, l0, l5);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_c_emit_tag_expression(vader_box_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(18)) {
        l2 = vader_c_emit_c_ast_pointer_member(2292u, l0, 2124u);
    } else {
        vader_struct_vader_c_emit_c_ast_CMember_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_base = l0;
        _a0_obj->f_member = 2055u;
        _a0_obj->f_arrow = false;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(145u, 1u, 13u, 1205u);
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
            vader_obj_header_init(_a3_obj, 695u);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        l4 = std_core_new_byte_buffer((size_t) 21);
        l5 = (size_t) 0;
        l5 = std_core_write_string_at(l4, l5, 1012u);
        t0 = ((int64_t) (size_t) l3);
        l6 = (uint64_t) (int64_t) t0;
        l5 = std_core_write_unsigned(l4, l5, l6);
        t1 = std_core_finish_buffer(l4, l5);
        l7 = vader_c_emit_c_ast_verbatim(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 196u);
        l8 = ((uint8_t) t2.payload.i);
        l9 = vader_c_emit_unbox_expr(l7, l8);
        vader_array_push((vader_array_t*) l1, l9);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
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
    l3 = concat_2(2278u, l1);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l1 = (void*) _a0_arr;
    t1 = vader_c_emit_c_ast_perform(2314u, l1);
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (t0.tag == 493u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t1 = t0.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_symbol_id;
            if (t2 == l1) {
                { int32_t __vret = ((int32_t) (size_t) l3); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    l4 = std_core_new_byte_buffer((size_t) 80);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l4, l2, 1208u);
    l5 = ((int64_t) (int32_t) l1);
    l2 = std_core_write_int(l4, l2, l5);
    l2 = std_core_write_string_at(l4, l2, 94u);
    t4 = std_core_finish_buffer(l4, l2);
    vader_host_std_abort_panic(t4);
    vader_unreachable("unreachable return in vader_c_emit$type_id_for_struct_symbol");
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
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (t0.tag == 493u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t1 = t0.payload.obj;
            t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
            l4 = vader_c_emit_struct_c_name(t2);
            l5 = vader_c_emit_struct_c_name(l1);
            if (l4 == l5) {
                { int32_t __vret = ((int32_t) (size_t) l3); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
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
        vader_obj_header_init(_a0_obj, 653u);
        _a0_obj->f_cty = 1619u;
        _a0_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(3)) {
        vader_struct_vader_c_emit_SlotFill_t* _a1_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a1_obj, 653u);
        _a1_obj->f_cty = 1619u;
        _a1_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_c_emit_SlotFill_t* _a2_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a2_obj, 653u);
        _a2_obj->f_cty = 1619u;
        _a2_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(8)) {
        vader_struct_vader_c_emit_SlotFill_t* _a3_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a3_obj, 653u);
        _a3_obj->f_cty = 1620u;
        _a3_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a3_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(4)) {
        vader_struct_vader_c_emit_SlotFill_t* _a4_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a4_obj, 653u);
        _a4_obj->f_cty = 1620u;
        _a4_obj->f_val = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_c_emit_SlotFill_t* _a5_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a5_obj, 653u);
        _a5_obj->f_cty = 1340u;
        _a5_obj->f_val = (uint8_t) 11;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(1)) {
        vader_struct_vader_c_emit_SlotFill_t* _a6_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a6_obj, 653u);
        _a6_obj->f_cty = 2162u;
        _a6_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a6_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(5)) {
        vader_struct_vader_c_emit_SlotFill_t* _a7_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a7_obj, 653u);
        _a7_obj->f_cty = 1621u;
        _a7_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a7_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        vader_struct_vader_c_emit_SlotFill_t* _a8_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a8_obj, 653u);
        _a8_obj->f_cty = 2162u;
        _a8_obj->f_val = (uint8_t) 12;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(2)) {
        vader_struct_vader_c_emit_SlotFill_t* _a9_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a9_obj, 653u);
        _a9_obj->f_cty = 2159u;
        _a9_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(6)) {
        vader_struct_vader_c_emit_SlotFill_t* _a10_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a10_obj, 653u);
        _a10_obj->f_cty = 1618u;
        _a10_obj->f_val = (uint8_t) 2;
        t0 = (void*) _a10_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(9)) {
        vader_struct_vader_c_emit_SlotFill_t* _a11_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a11_obj, 653u);
        _a11_obj->f_cty = 1479u;
        _a11_obj->f_val = (uint8_t) 10;
        t0 = (void*) _a11_obj;
        l1 = vader_ref_box(t0);
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(0)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        vader_unreachable("unreachable return in vader_c_emit$typed_array_fill_for");
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
    l3 = concat_2(l0, 229u);
    t0 = concat_2(l1, 250u);
    l4 = vader_c_emit_c_ast_verbatim(t0);
    t1 = vader_c_emit_c_ast_cast(l3, l4);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_inner = t1;
    t2 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CIndex_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIndex_t));
    vader_obj_header_init(_a1_obj, 686u);
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
        l2 = vader_c_emit_payload_cast(1621u, l0, 1535u);
    } else if (l1 == INT32_C(1)) {
        l2 = vader_c_emit_payload_cast(1618u, l0, 1535u);
    } else if (l1 == INT32_C(2)) {
        l2 = vader_c_emit_payload_cast(1619u, l0, 1535u);
    } else if (l1 == INT32_C(3)) {
        l2 = vader_c_emit_payload_cast(1620u, l0, 1535u);
    } else if (l1 == INT32_C(5)) {
        l2 = vader_c_emit_payload_cast(2162u, l0, 1535u);
    } else if (l1 == INT32_C(6)) {
        l2 = vader_c_emit_payload_cast(2159u, l0, 1535u);
    } else if (l1 == INT32_C(7)) {
        l2 = vader_c_emit_payload_cast(2160u, l0, 1535u);
    } else if (l1 == INT32_C(8)) {
        l2 = vader_c_emit_payload_cast(2161u, l0, 1535u);
    } else if (l1 == INT32_C(9)) {
        l2 = vader_c_emit_payload_cast(1930u, l0, 1535u);
    } else if (l1 == INT32_C(4)) {
        l2 = vader_c_emit_payload_cast(1863u, l0, 1535u);
    } else if (l1 == INT32_C(13)) {
        l2 = vader_c_emit_payload_cast(2160u, l0, 1535u);
    } else if (l1 == INT32_C(10)) {
        l2 = vader_c_emit_payload_cast(1479u, l0, 1425u);
    } else if (l1 == INT32_C(11)) {
        l2 = vader_c_emit_payload_cast(1340u, l0, 1425u);
    } else if (l1 == INT32_C(12)) {
        l2 = vader_c_emit_payload(l0, 1128u);
    } else if (l1 == INT32_C(14)) {
        l2 = vader_c_emit_payload(l0, 1908u);
    } else if (l1 == INT32_C(15)) {
        l2 = l0;
    } else if (l1 == INT32_C(16)) {
        l2 = vader_c_emit_c_ast_verbatim(196u);
    } else if (l1 == INT32_C(17)) {
        l3 = vader_c_emit_payload(l0, 1535u);
        l3 = vader_c_emit_c_ast_cast(1635u, l3);
        t0 = vader_c_emit_c_ast_cast(2337u, l3);
        vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
        vader_obj_header_init(_a0_obj, 695u);
        _a0_obj->f_inner = t0;
        t1 = (void*) _a0_obj;
        l2 = vader_ref_box(t1);
    } else if (l1 == INT32_C(18)) {
        l2 = vader_c_emit_payload(l0, 1818u);
    } else if (l1 == INT32_C(19)) {
        l2 = l0;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$unbox_expr");
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
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(190u, 760u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    l4 = (size_t) 1;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
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
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
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
                t3 = concat_3(1940u, l10, 849u);
                std_abort_todo(t3);
            }
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
        if (l6 == 0u) {
            l11 = 765u;
        } else {
            l11 = l6;
        }
        vader_array_push((vader_array_t*) l2, vader_box_string(190u, l11));
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a7_arr = vader_array_new(8u, 0u, 0u, 190u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 188u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 193u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a10_obj, 342u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = (size_t) 0;
    _a10_obj->f_size = (size_t) 0;
    _a10_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__string_t* _a11_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a11_obj, 364u);
    _a11_obj->f_inner = t0;
    l12 = (void*) _a11_obj;
    l13 = l2;
    l3 = ((vader_array_t*) l13)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
        t6 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l4];
        l6 = t6.payload.s;
        t5 = std_collections_MutableSet_Contains_contains__string(l12, l6);
        if (t5) {
            t3 = concat_3(1939u, l6, 887u);
            std_abort_todo(t3);
        }
        std_collections_add__string(l12, l6);
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
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
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(2318u, l2);
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
    vader_array_t* _a0_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(145u, 0u, 13u, 1205u);
    l7 = (void*) _a4_arr;
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        l10 = vader_c_emit_argument(l9);
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9];
        t0 = vader_c_emit_is_abi_array(l1, l11);
        if (t0) {
            t1 = vader_c_emit_c_ast_cast(2235u, l10);
            vader_array_t* _a6_arr = vader_array_new(145u, 1u, 13u, 1205u);
            ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t1.payload.obj;
            l12 = (void*) _a6_arr;
            l13 = vader_c_emit_c_ast_call(2209u, l12);
            l14 = std_core_new_byte_buffer((size_t) 21);
            l15 = (size_t) 0;
            l15 = std_core_write_string_at(l14, l15, 1908u);
            t2 = ((int64_t) (size_t) l9);
            l16 = (uint64_t) (int64_t) t2;
            l15 = std_core_write_unsigned(l14, l15, l16);
            l17 = std_core_finish_buffer(l14, l15);
            l18 = vader_c_emit_c_ast_declaration(2302u, l17, l13);
            vader_array_push((vader_array_t*) l4, l18);
            l19 = std_core_new_byte_buffer((size_t) 21);
            l20 = (size_t) 0;
            l20 = std_core_write_string_at(l19, l20, 1908u);
            t2 = ((int64_t) (size_t) l9);
            l21 = (uint64_t) (int64_t) t2;
            l20 = std_core_write_unsigned(l19, l20, l21);
            t3 = std_core_finish_buffer(l19, l20);
            t1 = vader_c_emit_c_ast_verbatim(t3);
            vader_struct_vader_c_emit_c_ast_CMember_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
            vader_obj_header_init(_a7_obj, 691u);
            _a7_obj->f_base = t1;
            _a7_obj->f_member = 1862u;
            _a7_obj->f_arrow = false;
            l22 = (void*) _a7_obj;
            t0 = vader_c_emit_param_is_mutable(l2, l9);
            if (t0) {
                l23 = vader_c_emit_c_ast_cast(2337u, vader_ref_box(l22));
            } else {
                l23 = vader_ref_box(l22);
            }
            vader_array_push((vader_array_t*) l3, l23);
        } else {
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
            l24 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l9];
            t3 = vader_c_emit_mirrored_c_struct(l1, l24);
            if (t3 != 0u) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
                l25 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9];
                l26 = vader_c_emit_mirrored_c_struct(l1, l25);
                vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
                l27 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9];
                t3 = vader_c_emit_bc_struct_name(l1, l27);
                l28 = vader_c_emit_struct_c_name(t3);
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                l29 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                l30 = vader_c_emit_bc_struct_fields(l1, l29);
                l31 = std_core_new_byte_buffer((size_t) 21);
                l32 = (size_t) 0;
                l32 = std_core_write_string_at(l31, l32, 1841u);
                t2 = ((int64_t) (size_t) l9);
                l33 = (uint64_t) (int64_t) t2;
                l32 = std_core_write_unsigned(l31, l32, l33);
                t3 = std_core_finish_buffer(l31, l32);
                l34 = vader_c_emit_c_ast_verbatim(t3);
                t3 = concat_2(l28, 229u);
                t1 = vader_c_emit_c_ast_cast(t3, l10);
                vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a12_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
                vader_obj_header_init(_a12_obj, 695u);
                _a12_obj->f_inner = t1;
                l35 = (void*) _a12_obj;
                l36 = std_core_new_byte_buffer((size_t) 21);
                l37 = (size_t) 0;
                l37 = std_core_write_string_at(l36, l37, 1841u);
                t2 = ((int64_t) (size_t) l9);
                l38 = (uint64_t) (int64_t) t2;
                l37 = std_core_write_unsigned(l36, l37, l38);
                l39 = std_core_finish_buffer(l36, l37);
                t1 = vader_c_emit_c_ast_number(INT64_C(0));
                vader_array_t* _a13_arr = vader_array_new(145u, 1u, 13u, 1205u);
                ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = t1.payload.obj;
                t4 = (void*) _a13_arr;
                l40 = vader_c_emit_c_ast_initializer_list(t4);
                l41 = vader_c_emit_c_ast_declaration(l26, l39, l40);
                vader_array_push((vader_array_t*) l4, l41);
                vader_c_emit_push_member_copies(l1, l30, l34, vader_ref_box(l35), true, l4, INT32_C(0));
                t0 = vader_c_emit_param_is_mutable(l2, l9);
                if (t0) {
                    l42 = vader_c_emit_c_ast_address_of(l10);
                    vader_array_push((vader_array_t*) l7, l42);
                    vader_c_emit_push_member_copies(l1, l30, l34, vader_ref_box(l35), false, l6, INT32_C(0));
                }
                l43 = vader_c_emit_c_ast_address_of(l34);
                vader_array_push((vader_array_t*) l3, l43);
            } else {
                t0 = vader_c_emit_is_param_by_address(l2, l9);
                if (t0) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l9)
                    t1 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l9, 196u);
                    l44 = vader_c_emit_c_type_for_val_bare(((uint8_t) t1.payload.i));
                    l45 = std_core_new_byte_buffer((size_t) 21);
                    l46 = (size_t) 0;
                    l46 = std_core_write_string_at(l45, l46, 1841u);
                    t2 = ((int64_t) (size_t) l9);
                    l47 = (uint64_t) (int64_t) t2;
                    l46 = std_core_write_unsigned(l45, l46, l47);
                    l48 = std_core_finish_buffer(l45, l46);
                    l49 = vader_c_emit_c_ast_declaration(l44, l48, l10);
                    vader_array_push((vader_array_t*) l4, l49);
                    l50 = std_core_new_byte_buffer((size_t) 21);
                    l51 = (size_t) 0;
                    l51 = std_core_write_string_at(l50, l51, 1841u);
                    t2 = ((int64_t) (size_t) l9);
                    l52 = (uint64_t) (int64_t) t2;
                    l51 = std_core_write_unsigned(l50, l51, l52);
                    t3 = std_core_finish_buffer(l50, l51);
                    t1 = vader_c_emit_c_ast_verbatim(t3);
                    l53 = vader_c_emit_c_ast_address_of(t1);
                    l54 = vader_c_emit_c_ast_cast(2337u, l53);
                    vader_array_push((vader_array_t*) l3, l54);
                } else {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l9)
                    l55 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l9];
                    t0 = vader_c_emit_is_abi_nullable_pointer(l1, l55);
                    if (t0) {
                        vader_struct_vader_c_emit_c_ast_CMember_t* _a16_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
                        vader_obj_header_init(_a16_obj, 691u);
                        _a16_obj->f_base = l10;
                        _a16_obj->f_member = 2055u;
                        _a16_obj->f_arrow = false;
                        l56 = (void*) _a16_obj;
                        l57 = vader_c_emit_c_ast_verbatim(675u);
                        l58 = vader_c_emit_c_ast_binary((uint8_t) 11, vader_ref_box(l56), l57);
                        vader_struct_vader_c_emit_c_ast_CMember_t* _a17_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
                        vader_obj_header_init(_a17_obj, 691u);
                        _a17_obj->f_base = l10;
                        _a17_obj->f_member = 1850u;
                        _a17_obj->f_arrow = false;
                        t4 = (void*) _a17_obj;
                        vader_struct_vader_c_emit_c_ast_CMember_t* _a18_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
                        vader_obj_header_init(_a18_obj, 691u);
                        _a18_obj->f_base = vader_ref_box(t4);
                        _a18_obj->f_member = 1535u;
                        _a18_obj->f_arrow = false;
                        l59 = (void*) _a18_obj;
                        vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a19_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
                        vader_obj_header_init(_a19_obj, 711u);
                        _a19_obj->f_text = 489u;
                        l60 = (void*) _a19_obj;
                        l61 = vader_c_emit_c_ast_cast(1635u, vader_ref_box(l59));
                        l62 = vader_c_emit_c_ast_cast(2337u, l61);
                        vader_struct_vader_c_emit_c_ast_CConditional_t* _a20_obj = (vader_struct_vader_c_emit_c_ast_CConditional_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CConditional_t));
                        vader_obj_header_init(_a20_obj, 670u);
                        _a20_obj->f_condition = l58;
                        _a20_obj->f_then_value = vader_ref_box(l60);
                        _a20_obj->f_else_value = l62;
                        l63 = (void*) _a20_obj;
                        l64 = std_core_new_byte_buffer((size_t) 21);
                        l65 = (size_t) 0;
                        l65 = std_core_write_string_at(l64, l65, 1841u);
                        t2 = ((int64_t) (size_t) l9);
                        l66 = (uint64_t) (int64_t) t2;
                        l65 = std_core_write_unsigned(l64, l65, l66);
                        l67 = std_core_finish_buffer(l64, l65);
                        l68 = vader_c_emit_c_ast_declaration(2337u, l67, vader_ref_box(l63));
                        vader_array_push((vader_array_t*) l4, l68);
                        l69 = std_core_new_byte_buffer((size_t) 21);
                        l70 = (size_t) 0;
                        l70 = std_core_write_string_at(l69, l70, 1841u);
                        t2 = ((int64_t) (size_t) l9);
                        l71 = (uint64_t) (int64_t) t2;
                        l70 = std_core_write_unsigned(l69, l70, l71);
                        t3 = std_core_finish_buffer(l69, l70);
                        l72 = vader_c_emit_c_ast_verbatim(t3);
                        vader_array_push((vader_array_t*) l3, l72);
                    } else {
                        vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params);
                        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l9)
                        t1 = vader_array_read_u8(_a21_slotarr, _a21_slotarr->offset + (size_t) l9, 196u);
                        if (((int32_t) t1.payload.i) == INT32_C(14)) {
                            l73 = std_core_new_byte_buffer((size_t) 21);
                            l74 = (size_t) 0;
                            l74 = std_core_write_string_at(l73, l74, 1203u);
                            t2 = ((int64_t) (size_t) l9);
                            l75 = (uint64_t) (int64_t) t2;
                            l74 = std_core_write_unsigned(l73, l74, l75);
                            l76 = std_core_finish_buffer(l73, l74);
                            vader_array_t* _a22_arr = vader_array_new(145u, 1u, 13u, 1205u);
                            ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l10.payload.obj;
                            l77 = (void*) _a22_arr;
                            l78 = vader_c_emit_c_ast_call(2312u, l77);
                            l79 = vader_c_emit_c_ast_declaration(1296u, l76, l78);
                            vader_array_push((vader_array_t*) l4, l79);
                            l80 = std_core_new_byte_buffer((size_t) 21);
                            l81 = (size_t) 0;
                            l81 = std_core_write_string_at(l80, l81, 1203u);
                            t2 = ((int64_t) (size_t) l9);
                            l82 = (uint64_t) (int64_t) t2;
                            l81 = std_core_write_unsigned(l80, l81, l82);
                            t3 = std_core_finish_buffer(l80, l81);
                            l83 = vader_c_emit_c_ast_verbatim(t3);
                            vader_array_t* _a23_arr = vader_array_new(145u, 2u, 13u, 1205u);
                            ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 1u] = l83.payload.obj;
                            ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = l10.payload.obj;
                            l84 = (void*) _a23_arr;
                            l85 = vader_c_emit_c_ast_perform(2262u, l84);
                            vader_array_push((vader_array_t*) l5, l85);
                            l86 = std_core_new_byte_buffer((size_t) 21);
                            l87 = (size_t) 0;
                            l87 = std_core_write_string_at(l86, l87, 1203u);
                            t2 = ((int64_t) (size_t) l9);
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
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a24_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l12 = (void*) _a24_arr;
    t5 = ((vader_array_t*) l7)->length;
    if ((t5 > INT64_C(0))) {
        t5 = ((vader_array_t*) l7)->length;
        l10 = vader_c_emit_c_ast_number(((int64_t) (size_t) t5));
        l13 = vader_c_emit_c_ast_array_declaration(2338u, 752u, l7);
        vader_array_push((vader_array_t*) l4, l13);
        l13 = vader_c_emit_c_ast_verbatim(751u);
        l18 = vader_c_emit_c_ast_verbatim(752u);
        vader_array_t* _a25_arr = vader_array_new(145u, 3u, 13u, 1205u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 2u] = l10.payload.obj;
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 1u] = l18.payload.obj;
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = l13.payload.obj;
        l7 = (void*) _a25_arr;
        l10 = vader_c_emit_c_ast_perform(678u, l7);
        vader_array_push((vader_array_t*) l4, l10);
        vader_array_t* _a26_arr = vader_array_new(145u, 1u, 13u, 1205u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = l13.payload.obj;
        l7 = (void*) _a26_arr;
        l10 = vader_c_emit_c_ast_perform(677u, l7);
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
    vader_array_t* _a27_arr = vader_array_new(49u, 0u, 13u, 661u);
    l3 = (void*) _a27_arr;
    l10 = ((vader_struct_vader_c_emit_ForwardedResult_t*) l2)->f_returned;
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a28_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a28_obj, 698u);
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
    if (l0.tag == 658u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackTemporary_t*) t0)->f_val;
    } else if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackLit_t*) t0)->f_val;
    } else if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_val;
    } else if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_c_emit_StackExpr_t*) t0)->f_val;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$val_of");
    }
    return l1;
}

static uint8_t vader_c_emit_val_type_of_bc_type(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    if (l0.tag == 489u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val;
    } else if (l0.tag == 493u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 480u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 483u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 494u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 490u) {
        l1 = (uint8_t) 19;
    } else {
        vader_unreachable("unreachable return in vader_c_emit$val_type_of_bc_type");
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
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 694u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 196u);
        l5 = vader_c_emit_c_type_for_val_bare(((uint8_t) t0.payload.i));
        l6 = l1;
        l7 = vader_host_std_core_byte_len(l6);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(20) + l7));
        l9 = (size_t) 0;
        l9 = std_core_write_string_at(l8, l9, l6);
        t1 = ((int64_t) (size_t) l4);
        l10 = (uint64_t) (int64_t) t1;
        l9 = std_core_write_unsigned(l8, l9, l10);
        l11 = std_core_finish_buffer(l8, l9);
        vader_struct_vader_c_emit_c_ast_CParameter_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CParameter_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParameter_t));
        vader_obj_header_init(_a2_obj, 694u);
        _a2_obj->f_type = l5;
        _a2_obj->f_name = l11;
        l12 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l12));
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
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
    t0 = std_string_split(l0, 258u);
    t1 = std_string_join(t0, 730u);
    l1 = vader_c_emit_sanitise(t1);
    t1 = concat_2(2322u, l1);
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
    size_t l3, l8, l11;
    uint8_t l4;
    int32_t l5;
    bool l6, l13;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    uint8_t t3;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l7, &l9, &l10, &l12, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
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
    if (l6) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params;
    vader_array_t* _a4_arr = vader_array_new(11u, 1u, 1u, 196u);
    ((uint8_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (uint8_t) INT32_C(19);
    l9 = (void*) _a4_arr;
    l10 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types;
    vader_array_t* _a5_arr = vader_array_new(9u, 1u, 7u, 193u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) l5;
    l12 = (void*) _a5_arr;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_names;
    vader_array_t* _a6_arr = vader_array_new(6u, 0u, 12u, 188u);
    l14 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(6u, 0u, 12u, 188u);
    l15 = (void*) _a7_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a8_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a8_obj, 491u);
    _a8_obj->f_params = l7;
    _a8_obj->f_results = l9;
    _a8_obj->f_param_types = l10;
    _a8_obj->f_result_types = l12;
    _a8_obj->f_param_names = l2;
    _a8_obj->f_param_mutable = l14;
    _a8_obj->f_param_by_address = l15;
    t0 = (void*) _a8_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_c_emit_wrapper_storage(bool l0) {
    uint8_t l1;
    if (l0) {
        l1 = (uint8_t) 1;
    } else {
        l1 = (uint8_t) 0;
    }
    return l1;
}

static void vader_c_emit_write_barrier(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(145u, 1u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1.payload.obj;
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(685u, l2);
    vader_c_emit_evaluate(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}
